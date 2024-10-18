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
static HSD_Diag_Step g_HSD2_Diag_Step = HSD_Diag_Step_SetDiagMUX;
static S_ChannelInfo gS_ChannelInfo[HSD_CHANNEL_SIZE] = {
    {.ChannelState = HS_OFF, .OverCurrentThreshold = HSCHANNEL_OVERCURRENT_VAL_1A_12ADBIT, .HsdFD_ADCVAL = 0xFFFFFFFF},
    {.ChannelState = HS_OFF, .OverCurrentThreshold = HSCHANNEL_OVERCURRENT_VAL_2_5A_12ADBIT, .HsdFD_ADCVAL = 0xFFFFFFFF},
    {.ChannelState = HS_OFF, .OverCurrentThreshold = HSCHANNEL_OVERCURRENT_VAL_2_5A_12ADBIT, .HsdFD_ADCVAL = 0xFFFFFFFF},
    {.ChannelState = HS_OFF, .OverCurrentThreshold = HSCHANNEL_OVERCURRENT_VAL_2_5A_12ADBIT, .HsdFD_ADCVAL = 0xFFFFFFFF},
};
static uint32_t Hsd1ADCBuffer[ADC_BUFFER_SIZE];
static uint32_t Hsd2ADCBuffer[ADC_BUFFER_SIZE];

static Std_ReturnType DrvTps2HB35_DeviceInit(void *ptr);
static Std_ReturnType DrvTps2HB35_DeviceDeInit(void *ptr);
static Std_ReturnType DrvTps2HB35_Read(void *ptr);
static Std_ReturnType DrvTps2HB35_Write(void *ptr);
static Std_ReturnType DrvTps2HB35_MainFunction(void *ptr);

static S_HighSideDrv_Dev gs_HighSideDrv_Dev[MAX_HSDDRV_NUM] = {
    {
        .HighSideDrvDevType = E_HighSideDrvDevType_Tps2HB35,
        .Device_id = 0,
        .HsdChMappingMask = 0x03,
        .DeviceInit = DrvTps2HB35_DeviceInit,
        .DeviceDeInit = DrvTps2HB35_DeviceDeInit,
        .Read = DrvTps2HB35_Read,
        .Write = DrvTps2HB35_Write,
        .MainFunction = DrvTps2HB35_MainFunction,
        .ptNext = NULL,
    },
    {
        .HighSideDrvDevType = E_HighSideDrvDevType_Tps2HB35,
        .Device_id = 1,
        .HsdChMappingMask = 0x0C,
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

static void HS2_SEL2(uint8_t pin_state)
{
    if (pin_state == STD_HIGH)
    {
        Dio_WriteChannel(DioConf_DioChannel_HSD2_SEL2, STD_HIGH);
    }
    else
    {
        Dio_WriteChannel(DioConf_DioChannel_HSD2_SEL2, STD_LOW);
    }
}
static void HS2_SEL1(uint8_t pin_state)
{
    if (pin_state == STD_HIGH)
    {
        Dio_WriteChannel(DioConf_DioChannel_HSD2_SEL1, STD_HIGH);
    }
    else
    {
        Dio_WriteChannel(DioConf_DioChannel_HSD2_SEL1, STD_LOW);
    }
}

static void SetDiagMUX(uint8_t HighSideNum, uint8_t DiagNum)
{
    if (HighSideNum == 1)
    {
        HS1_SEL1(SNS_MUX[DiagNum][1]);
        HS1_SEL2(SNS_MUX[DiagNum][2]);
    }
    else
    {
        HS2_SEL1(SNS_MUX[DiagNum][1]);
        HS2_SEL2(SNS_MUX[DiagNum][2]);
    }
}

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
    case E_HSChannel_HS2:
        if (HsdState == E_HSDChannelSwitchState_OFF)
        {
            Dio_WriteChannel(DioConf_DioChannel_HSD_EN3, STD_LOW);
        }
        else
        {
            Dio_WriteChannel(DioConf_DioChannel_HSD_EN3, STD_HIGH);
        }
        break;
    case E_HSChannel_HS3:
        if (HsdState == E_HSDChannelSwitchState_OFF)
        {
            Dio_WriteChannel(DioConf_DioChannel_HSD_EN4, STD_LOW);
        }
        else
        {
            Dio_WriteChannel(DioConf_DioChannel_HSD_EN4, STD_HIGH);
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
        SetDiagMUX(1, 0);
        SetDrvTps2HB35Output(E_HSChannel_HS0, E_HSDChannelSwitchState_OFF);
        SetDrvTps2HB35Output(E_HSChannel_HS1, E_HSDChannelSwitchState_OFF);
    }
    else
    {
        SetDiagMUX(2, 0);
        SetDrvTps2HB35Output(E_HSChannel_HS2, E_HSDChannelSwitchState_OFF);
        SetDrvTps2HB35Output(E_HSChannel_HS3, E_HSDChannelSwitchState_OFF);
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
    case E_HighSideDataType_ChannelCurrent:
        HighSideCurrentDataSrc = (S_HighSideCurrentDataSrc *)(HighSidekDataPackets->datasrc);
        if (GetHighSideDrvDevByHSChannel(HighSideCurrentDataSrc->HSChannel) == NULL)
            return E_NOT_OK;
        if (gS_ChannelInfo[HighSideCurrentDataSrc->HSChannel].HsdFD_ADCVAL == 0xFFFFFFFF)
            return E_NOT_OK;

        HighSideCurrentDataSrc->current = gS_ChannelInfo[HighSideCurrentDataSrc->HSChannel].HsdFD_ADCVAL * 10000 / gS_ChannelInfo[HighSideCurrentDataSrc->HSChannel].Adc_width;
        break;
    case E_HighSideDataType_ChannelDiagInfo:
        HighSideDiagDataSrc = (S_HighSideDiagDataSrc *)(HighSidekDataPackets->datasrc);
        if (GetHighSideDrvDevByHSChannel(HighSideCurrentDataSrc->HSChannel) == NULL)
            return E_NOT_OK;
        if (gS_ChannelInfo[HighSideCurrentDataSrc->HSChannel].HsdFD_ADCVAL == 0xFFFFFFFF)
        {
            HighSideDiagDataSrc->HSChannelDiagInfo.bits.Short2GND = 0;
            HighSideDiagDataSrc->HSChannelDiagInfo.bits.OverCurrent = 0;
            HighSideDiagDataSrc->HSChannelDiagInfo.bits.OpenOrShort2Vcc = 0;
        }
        else if (gS_ChannelInfo[HighSideCurrentDataSrc->HSChannel].AdcAccuracy == E_AdcAccuracy_Bit12)
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
                    if (OpenCurrentThr > (gS_ChannelInfo[HighSideCurrentDataSrc->HSChannel].HsdFD_ADCVAL * 10000 / gS_ChannelInfo[HighSideCurrentDataSrc->HSChannel].Adc_width))
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
                        if (OpenCurrentThr > (gS_ChannelInfo[HighSideCurrentDataSrc->HSChannel].HsdFD_ADCVAL * 10000 / gS_ChannelInfo[HighSideCurrentDataSrc->HSChannel].Adc_width))
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

static uint8_t HSD1_Diag(E_HSChannel HSChannel, uint32_t ad_val, E_AdcAccuracy AdcAccuracy)
{
    static uint8_t index = 0;

    Hsd1ADCBuffer[index] = ad_val;
    index++;
    if (index >= ADC_BUFFER_SIZE)
    {
        gS_ChannelInfo[HSChannel].HsdFD_ADCVAL = CalArrayAverageValue_Uint32(Hsd1ADCBuffer, ADC_BUFFER_SIZE);
        gS_ChannelInfo[HSChannel].AdcAccuracy = AdcAccuracy;
        gS_ChannelInfo[HSChannel].Adc_width = GetAdcWidth(AdcAccuracy);
        index = 0;
        return 1;
    }

    return 0;
}

static uint8_t HSD2_Diag(E_HSChannel HSChannel, uint32_t ad_val, E_AdcAccuracy AdcAccuracy)
{
    static uint8_t index = 0;

    Hsd2ADCBuffer[index] = ad_val;
    index++;
    if (index >= ADC_BUFFER_SIZE)
    {
        gS_ChannelInfo[HSChannel].HsdFD_ADCVAL = CalArrayAverageValue_Uint32(Hsd2ADCBuffer, ADC_BUFFER_SIZE);
        gS_ChannelInfo[HSChannel].Adc_width = GetAdcWidth(AdcAccuracy);
        gS_ChannelInfo[HSChannel].AdcAccuracy = AdcAccuracy;
        index = 0;
        return 1;
    }

    return 0;
}

static Std_ReturnType DrvTps2HB35_MainFunction(void *ptr)
{
    Std_ReturnType rtval = E_OK;
    S_HighSidekDataPackets *HighSidekDataPackets = (S_HighSidekDataPackets *)ptr;
    S_HighSideDevMainFuncDataSrc *HighSideDevMainFuncDataSrc;
    HSD_Diag_Step *p_HSD_Diag_Step_tmp;
    E_HSChannel *p_HSD_HSChannel_tmp;
    static E_HSChannel HSD1_HSChannel = E_HSChannel_HS0;
    static E_HSChannel HSD2_HSChannel = E_HSChannel_HS2;
    uint32 adval;
    E_AdcAccuracy AdcAccuracy;
    E_HSChannel HSChanneltmp;

    if (HighSidekDataPackets->HighSideDataType != E_HighSideDataType_DeviceMainFunction)
        return E_NOT_OK;

    HighSideDevMainFuncDataSrc = (S_HighSideDevMainFuncDataSrc *)HighSidekDataPackets->datasrc;

    if (HighSideDevMainFuncDataSrc->Device_id == 0)
    {
        p_HSD_HSChannel_tmp = &HSD1_HSChannel;
        p_HSD_Diag_Step_tmp = &g_HSD1_Diag_Step;
    }
    else if (HighSideDevMainFuncDataSrc->Device_id == 1)
    {
        p_HSD_HSChannel_tmp = &HSD2_HSChannel;
        p_HSD_Diag_Step_tmp = &g_HSD2_Diag_Step;
    }

    switch ((*p_HSD_Diag_Step_tmp))
    {
    case HSD_Diag_Step_SetDiagMUX:
        if (gS_ChannelInfo[(*p_HSD_HSChannel_tmp)].ChannelState == HS_ON)
        {
            if (*p_HSD_HSChannel_tmp == E_HSChannel_HS0)
                SetDiagMUX(1, 1);
            else if (*p_HSD_HSChannel_tmp == E_HSChannel_HS1)
                SetDiagMUX(1, 2);
            else if (*p_HSD_HSChannel_tmp == E_HSChannel_HS2)
                SetDiagMUX(2, 1);
            else if (*p_HSD_HSChannel_tmp == E_HSChannel_HS3)
                SetDiagMUX(2, 2);

            *p_HSD_Diag_Step_tmp = HSD_Diag_Step_GetADVal;
        }
        else
        {
            if (*p_HSD_HSChannel_tmp == E_HSChannel_HS0)
                *p_HSD_HSChannel_tmp = E_HSChannel_HS1;
            else if (*p_HSD_HSChannel_tmp == E_HSChannel_HS1)
                *p_HSD_HSChannel_tmp = E_HSChannel_HS0;
            else if (*p_HSD_HSChannel_tmp == E_HSChannel_HS2)
                *p_HSD_HSChannel_tmp = E_HSChannel_HS3;
            else if (*p_HSD_HSChannel_tmp == E_HSChannel_HS3)
                *p_HSD_HSChannel_tmp = E_HSChannel_HS2;
        }
        break;
    case HSD_Diag_Step_GetADVal:
        if ((*p_HSD_HSChannel_tmp == E_HSChannel_HS0) || (*p_HSD_HSChannel_tmp == E_HSChannel_HS1))
        {
            if (Interface_GetAdcDigitalValue(E_AdcFunction_HSD1FB, &adval) == E_OK)
            {
                Interface_GetAdcAccuracy(E_AdcFunction_HSD1FB, &AdcAccuracy);
                HSChanneltmp = *p_HSD_HSChannel_tmp;
                if (HSD1_Diag(HSChanneltmp, adval, AdcAccuracy) == 1)
                {
                    if (*p_HSD_HSChannel_tmp == E_HSChannel_HS0)
                        *p_HSD_HSChannel_tmp = E_HSChannel_HS1;
                    else if (*p_HSD_HSChannel_tmp == E_HSChannel_HS1)
                        *p_HSD_HSChannel_tmp = E_HSChannel_HS0;

                    *p_HSD_Diag_Step_tmp = HSD_Diag_Step_SetDiagMUX;
                }
            }
        }
        else
        {
            if (Interface_GetAdcDigitalValue(E_AdcFunction_HSD2FB, &adval) == E_OK)
            {
                Interface_GetAdcAccuracy(E_AdcFunction_HSD2FB, &AdcAccuracy);
                HSChanneltmp = *p_HSD_HSChannel_tmp;
                if (HSD2_Diag(HSChanneltmp, adval, AdcAccuracy) == 1)
                {
                    if (*p_HSD_HSChannel_tmp == E_HSChannel_HS2)
                        *p_HSD_HSChannel_tmp = E_HSChannel_HS3;
                    else if (*p_HSD_HSChannel_tmp == E_HSChannel_HS3)
                        *p_HSD_HSChannel_tmp = E_HSChannel_HS2;

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
