/*
 * DrvTps2HB35.c
 *
 *  Created on: 2024��2��21��
 *      Author: mihuiliang
 */

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "DrvTps2HB35.h"
#include "HighSide_Interface.h"
#include "GeneralFunction.h"
#include "Dio_Cfg.h"
#include "Dio.h"
#include "Parameter_Interface.h"
/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/

static HSD_Diag_Step g_HSD1_Diag_Step = HSD_Diag_Step_SetDiagMUX;
static S_ChannelInfo gS_ChannelInfo[HSD_CHANNEL_SIZE] = {
    {.ChannelState = HS_OFF, .OverCurrentThreshold = HSCHANNEL_OVERCURRENT_VAL_1A_12ADBIT, .HsdFD_ADCVAL = 0xFFFFFFFF, .DiagPreCurrentIndex = 0xFFFFFFFF},
    {.ChannelState = HS_OFF, .OverCurrentThreshold = HSCHANNEL_OVERCURRENT_VAL_2_5A_12ADBIT, .HsdFD_ADCVAL = 0xFFFFFFFF, .DiagPreCurrentIndex = 0xFFFFFFFF},
};
static uint32_t Hsd1ADCBuffer[ADC_BUFFER_SIZE];

static Std_ReturnType DrvTps2HB35_DeviceInit(void *ptr);
static Std_ReturnType DrvTps2HB35_DeviceDeInit(void *ptr);
static Std_ReturnType DrvTps2HB35_Read(void *ptr);
static Std_ReturnType DrvTps2HB35_Write(void *ptr);
Std_ReturnType DrvTps2HB35_MainFunction(void *ptr);

static S_HighSideDrv_Dev gs_HighSideDrv_Dev[MAX_HSDDRV_NUM] = {
    {
        .Device_id = 0,
        .HsdChMappingMask = 0x03,
        .DeviceInit = DrvTps2HB35_DeviceInit,
        .DeviceDeInit = DrvTps2HB35_DeviceDeInit,
        .Read = DrvTps2HB35_Read,
        .Write = DrvTps2HB35_Write,
        .MainFunction = DrvTps2HB35_MainFunction,
        .ptNext = NULL,
    },
};

static uint16_t SNS_MUX[4][3] =
{
    {0, 0, 0},
    {1, 0, 0},
    {1, 0, 1},
    {1, 1, 1},
};

/****************************************************************
 *                                                              *
 *                   Global Variable Define                     *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/

static void HS1_SEL2(uint8_t pin_state)
{
    if (pin_state == STD_HIGH)
    {
        Dio_WriteChannel(DioConf_DioChannel_HSD1_SEL2, STD_HIGH);
    }
    else
    {
        Dio_WriteChannel(DioConf_DioChannel_HSD1_SEL2, STD_LOW);
    }
}
static void HS1_SEL1(uint8_t pin_state)
{
    if (pin_state == STD_HIGH)
    {
        Dio_WriteChannel(DioConf_DioChannel_HSD1_SEL1, STD_HIGH);
    }
    else
    {
        Dio_WriteChannel(DioConf_DioChannel_HSD1_SEL1, STD_LOW);
    }
}

// static uint16_t SNS_MUX[4][3] =
// {
//     {0, 0, 0},
//     {1, 0, 0},
//     {1, 0, 1},
//     {1, 1, 1},
// };
// static void SetDiagMUX(uint8_t DiagNum)
// {
//     HS1_SEL1(SNS_MUX[DiagNum][1]);
//     HS1_SEL2(SNS_MUX[DiagNum][2]);
// }

static S_HighSideDrv_Dev *GetHighSideDrvDevByDeviceid(uint8_t devid)
{
    uint8_t i = 0;

    for (i = 0; i < MAX_HSDDRV_NUM; i++)
    {
        if (gs_HighSideDrv_Dev[i].Device_id == devid)
            return &gs_HighSideDrv_Dev[i];
    }

    return NULL;
}

static S_HighSideDrv_Dev *GetHighSideDrvDevByHSChannel(E_HSChannel HSChannel)
{
    uint8_t i = 0;
    for (i = 0; i < MAX_HSDDRV_NUM; i++)
    {
        if ((gs_HighSideDrv_Dev[i].HsdChMappingMask & (1 << HSChannel)) != 0)
            return &(gs_HighSideDrv_Dev[i]);
    }

    return NULL;
}

static Std_ReturnType SetDrvTps2HB35Output(E_HSChannel HSChannel, E_HSDChannelSwitchState HsdState)
{
    Std_ReturnType rtval = E_OK;
    switch (HSChannel)
    {
    case E_HSChannel_HS0:
        if (HsdState == E_HSDChannelSwitchState_OFF)
        {
            Dio_WriteChannel(DioConf_DioChannel_HSD_EN1, STD_LOW);
        }
        else
        {
            Dio_WriteChannel(DioConf_DioChannel_HSD_EN1, STD_HIGH);
        }
        break;
    case E_HSChannel_HS1:
        if (HsdState == E_HSDChannelSwitchState_OFF)
        {
            Dio_WriteChannel(DioConf_DioChannel_HSD_EN2, STD_LOW);
        }
        else
        {
            Dio_WriteChannel(DioConf_DioChannel_HSD_EN2, STD_HIGH);
        }
        break;
    }
    if (HsdState == E_HSDChannelSwitchState_OFF)
        gS_ChannelInfo[HSChannel].ChannelState = HS_OFF;
    else if (HsdState == E_HSDChannelSwitchState_ON)
        gS_ChannelInfo[HSChannel].ChannelState = HS_ON;

    return rtval;
}
static Std_ReturnType DrvTps2HB35_DeviceInit(void *ptr)
{
    Std_ReturnType rtval = E_OK;
    S_HighSidekDataPackets *HighSidekDataPackets;
    S_HighSideDevInitDataSrc *HighSideDevInitDataSrc;
    S_HighSideDrv_Dev *tmp = NULL;

    HighSidekDataPackets = (S_HighSidekDataPackets *)ptr;
    HighSideDevInitDataSrc = (S_HighSideDevInitDataSrc *)HighSidekDataPackets->datasrc;

    tmp = GetHighSideDrvDevByDeviceid(HighSideDevInitDataSrc->Device_id);

    if (tmp == NULL)
        return E_NOT_OK;

    if (tmp->Device_id == 0)
    {
        // SetDiagMUX(0);
        HS1_SEL1(0);
        HS1_SEL2(0);
        SetDrvTps2HB35Output(E_HSChannel_HS0, E_HSDChannelSwitchState_OFF);
        SetDrvTps2HB35Output(E_HSChannel_HS1, E_HSDChannelSwitchState_OFF);
    }

    return rtval;
}

static Std_ReturnType DrvTps2HB35_DeviceDeInit(void *ptr)
{
    Std_ReturnType rtval = E_OK;

    return rtval;
}

static Std_ReturnType DrvTps2HB35_Read(void *ptr)
{
    Std_ReturnType rtval = E_OK;

    S_HighSidekDataPackets *HighSidekDataPackets;
    S_HighSideCurrentDataSrc *HighSideCurrentDataSrc;
    S_HighSideDiagDataSrc *HighSideDiagDataSrc;

    HighSidekDataPackets = (S_HighSidekDataPackets *)ptr;
    uint32_t OpenCurrentThr = 0;
    switch (HighSidekDataPackets->HighSideDataType)
    {
    case E_HighSideDataType_ChannelCurrent: //通道电流处理
        HighSideCurrentDataSrc = (S_HighSideCurrentDataSrc *)(HighSidekDataPackets->datasrc);
        if (GetHighSideDrvDevByHSChannel(HighSideCurrentDataSrc->HSChannel) == NULL)
            return E_NOT_OK;
        if (gS_ChannelInfo[HighSideCurrentDataSrc->HSChannel].HsdFD_ADCVAL == 0xFFFFFFFF)
            return E_NOT_OK;

        HighSideCurrentDataSrc->current = gS_ChannelInfo[HighSideCurrentDataSrc->HSChannel].HsdFD_ADCVAL * 10000 / ADCWIDTH;
        break;
    case E_HighSideDataType_ChannelDiagInfo:
        HighSideDiagDataSrc = (S_HighSideDiagDataSrc *)(HighSidekDataPackets->datasrc);
        if (GetHighSideDrvDevByHSChannel(HighSideCurrentDataSrc->HSChannel) == NULL)
            return E_NOT_OK;

        if (gS_ChannelInfo[HighSideCurrentDataSrc->HSChannel].DiagPreCurrentIndex == gS_ChannelInfo[HighSideCurrentDataSrc->HSChannel].CurrentUpdateIndex)
        {
            /*表明电流还没更新*/
            HighSideDiagDataSrc->HSChannelDiagInfo.bits.Short2GND = 0;
            HighSideDiagDataSrc->HSChannelDiagInfo.bits.OverCurrent = 0;
            HighSideDiagDataSrc->HSChannelDiagInfo.bits.OpenOrShort2Vcc = 0;
            return E_OK;
        }

        gS_ChannelInfo[HighSideCurrentDataSrc->HSChannel].DiagPreCurrentIndex = gS_ChannelInfo[HighSideCurrentDataSrc->HSChannel].CurrentUpdateIndex;

        if (gS_ChannelInfo[HighSideCurrentDataSrc->HSChannel].HsdFD_ADCVAL == 0xFFFFFFFF)
        {
            HighSideDiagDataSrc->HSChannelDiagInfo.bits.Short2GND = 0;
            HighSideDiagDataSrc->HSChannelDiagInfo.bits.OverCurrent = 0;
            HighSideDiagDataSrc->HSChannelDiagInfo.bits.OpenOrShort2Vcc = 0;
        }
        else 
        {
            if (gS_ChannelInfo[HighSideCurrentDataSrc->HSChannel].HsdFD_ADCVAL > HSCHANNEL_SHORT2GND_VAL_12ADBIT)
            {
                HighSideDiagDataSrc->HSChannelDiagInfo.bits.Short2GND = 1;
                HighSideDiagDataSrc->HSChannelDiagInfo.bits.OverCurrent = 0;
                HighSideDiagDataSrc->HSChannelDiagInfo.bits.OpenOrShort2Vcc = 0;
            }
            else if (gS_ChannelInfo[HighSideCurrentDataSrc->HSChannel].HsdFD_ADCVAL > gS_ChannelInfo[HighSideCurrentDataSrc->HSChannel].OverCurrentThreshold)
            {
                HighSideDiagDataSrc->HSChannelDiagInfo.bits.Short2GND = 0;
                HighSideDiagDataSrc->HSChannelDiagInfo.bits.OverCurrent = 1;
                HighSideDiagDataSrc->HSChannelDiagInfo.bits.OpenOrShort2Vcc = 0;
            }
            else
            {
                HighSideDiagDataSrc->HSChannelDiagInfo.bits.Short2GND = 0;
                HighSideDiagDataSrc->HSChannelDiagInfo.bits.OverCurrent = 0;
                if (HighSideCurrentDataSrc->HSChannel == E_HSChannel_HS0)
                {
                    OpenCurrentThr = 1; /*风扇高边开路阈值30mA*/
                    if (OpenCurrentThr > (gS_ChannelInfo[HighSideCurrentDataSrc->HSChannel].HsdFD_ADCVAL * 10000 /ADCWIDTH))
                    {
                        HighSideDiagDataSrc->HSChannelDiagInfo.bits.OpenOrShort2Vcc = 1;
                    }
                    else
                    {
                        HighSideDiagDataSrc->HSChannelDiagInfo.bits.OpenOrShort2Vcc = 0;
                    }
                }
                else
                {
                    if (Get_pHSDxOLEnable(HighSideCurrentDataSrc->HSChannel) == 1)
                    {
                        HighSideDiagDataSrc->HSChannelDiagInfo.bits.OpenOrShort2Vcc = 0;
                    }
                    else
                    {
                        OpenCurrentThr = Get_pHSDIOutOC(HighSideCurrentDataSrc->HSChannel);
                        if (OpenCurrentThr > (gS_ChannelInfo[HighSideCurrentDataSrc->HSChannel].HsdFD_ADCVAL * 10000 / ADCWIDTH))
                        {
                            HighSideDiagDataSrc->HSChannelDiagInfo.bits.OpenOrShort2Vcc = 1;
                        }
                        else
                        {
                            HighSideDiagDataSrc->HSChannelDiagInfo.bits.OpenOrShort2Vcc = 0;
                        }
                    }
                }
            }
        }
        break;
    }

    return rtval;
}
static Std_ReturnType DrvTps2HB35_Write(void *ptr)
{
    Std_ReturnType rtval = E_OK;
    S_HighSidekDataPackets *HighSidekDataPackets;

    HighSidekDataPackets = (S_HighSidekDataPackets *)ptr;

    switch (HighSidekDataPackets->HighSideDataType)
    {
    case E_HighSideDataType_ChannelSwitch:
        rtval |= SetDrvTps2HB35Output(((S_HighSideSwitchStateDataSrc *)HighSidekDataPackets->datasrc)->HSChannel,
                                      ((S_HighSideSwitchStateDataSrc *)HighSidekDataPackets->datasrc)->HsdState);
        break;
    }
    return rtval;
}

static uint8_t HSD1_Diag(E_HSChannel HSChannel, uint32_t ad_val)
{
    static uint8_t index = 0;

    Hsd1ADCBuffer[index] = ad_val;
    index++;
    if (index >= ADC_BUFFER_SIZE)
    {
        gS_ChannelInfo[HSChannel].HsdFD_ADCVAL = CalArrayAverageValue_Uint32(Hsd1ADCBuffer, ADC_BUFFER_SIZE);
        index = 0;
        return 1;
    }

    return 0;
}

Std_ReturnType DrvTps2HB35_MainFunction(void *ptr)
{
    Std_ReturnType rtval = E_OK;
    S_HighSidekDataPackets *HighSidekDataPackets = (S_HighSidekDataPackets *)ptr;
    S_HighSideDevMainFuncDataSrc *HighSideDevMainFuncDataSrc;
    HSD_Diag_Step *p_HSD_Diag_Step_tmp;
    E_HSChannel *p_HSD_HSChannel_tmp;
    static E_HSChannel HSD1_HSChannel = E_HSChannel_HS0;
    uint32 adval;
    E_HSChannel HSChanneltmp;

    if (HighSidekDataPackets->HighSideDataType != E_HighSideDataType_DeviceMainFunction)
        return E_NOT_OK;

    HighSideDevMainFuncDataSrc = (S_HighSideDevMainFuncDataSrc *)HighSidekDataPackets->datasrc;

    if (HighSideDevMainFuncDataSrc->Device_id == 0)
    {
        p_HSD_HSChannel_tmp = &HSD1_HSChannel;
        p_HSD_Diag_Step_tmp = &g_HSD1_Diag_Step;
    }

    switch ((*p_HSD_Diag_Step_tmp))
    {
    case HSD_Diag_Step_SetDiagMUX:
        if (gS_ChannelInfo[(*p_HSD_HSChannel_tmp)].ChannelState == HS_ON)
        {
            if (*p_HSD_HSChannel_tmp == E_HSChannel_HS0)//诊断通道1 SEL2=0
            {
                // SetDiagMUX(1);
                HS1_SEL1(0);
                HS1_SEL2(0);
            }
            else if (*p_HSD_HSChannel_tmp == E_HSChannel_HS1)//诊断通道2 SEL2=1
            {
                // SetDiagMUX(2);
                HS1_SEL1(0);
                HS1_SEL2(1);
            }
            *p_HSD_Diag_Step_tmp = HSD_Diag_Step_GetADVal;
        }
        else
        {
            if (*p_HSD_HSChannel_tmp == E_HSChannel_HS0)
                *p_HSD_HSChannel_tmp = E_HSChannel_HS1;
            else if (*p_HSD_HSChannel_tmp == E_HSChannel_HS1)
                *p_HSD_HSChannel_tmp = E_HSChannel_HS0;
        }
        break;
    case HSD_Diag_Step_GetADVal:
        if ((*p_HSD_HSChannel_tmp == E_HSChannel_HS0) || (*p_HSD_HSChannel_tmp == E_HSChannel_HS1))
        {
            if (Interface_GetAdcDigitalValue(E_AdcFunction_HSD1FB, &adval) == E_OK)
            {
                HSChanneltmp = *p_HSD_HSChannel_tmp;
                if (HSD1_Diag(HSChanneltmp, adval) == 1)
                {
                    if (*p_HSD_HSChannel_tmp == E_HSChannel_HS0)
                        *p_HSD_HSChannel_tmp = E_HSChannel_HS1;
                    else if (*p_HSD_HSChannel_tmp == E_HSChannel_HS1)
                        *p_HSD_HSChannel_tmp = E_HSChannel_HS0;

                    *p_HSD_Diag_Step_tmp = HSD_Diag_Step_SetDiagMUX;
                }
            }
        }
        break;
    }

    return rtval;
}

/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
Std_ReturnType CddDriver_DrvTps2HB35Init(void)
{
    Std_ReturnType rtval = E_OK;
    uint8_t i = 0;

    for (i = 0; i < MAX_HSDDRV_NUM; i++)
    {
        rtval |= HighSideDrvDev_Register(&gs_HighSideDrv_Dev[i]);
    }

    return rtval;
}

void FAN_Open(void)
{
    Dio_WriteChannel(DioConf_DioChannel_HSD_EN1, STD_HIGH);//HSE_EN=1 打开风扇
}

void FAN_Close(void)
{
    Dio_WriteChannel(DioConf_DioChannel_HSD_EN1, STD_LOW);//HSE_EN=1 打开风扇
}

void DC_Motor_Open(void)
{
    Dio_WriteChannel(DioConf_DioChannel_HSD_EN1, STD_HIGH);//HSE_EN=1 打开风扇
}

void DC_Motor_Close(void)
{
    Dio_WriteChannel(DioConf_DioChannel_HSD_EN1, STD_LOW);//HSE_EN=1 打开风扇
}
