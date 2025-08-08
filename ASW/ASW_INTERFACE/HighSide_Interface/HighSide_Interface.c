/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "Dio.h"
#include "HighSide_Interface.h"
#include "DTC_Interface.h"
#include "GeneralFunction.h"
#include "Parameter_Interface.h"
#include "DrvTps2HB35.h"
/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
static S_HighSideDrv_Dev *gs_HighSideDrv_Dev_Header = NULL;
static E_HSDChannelSwitchState gE_HSDChannelSwitchState[CHANNEL_SIZE] = {E_HSDChannelSwitchState_OFF, E_HSDChannelSwitchState_OFF};
static S_HSDErrCnt gs_HSDErrCnt[CHANNEL_SIZE];
/****************************************************************
 *                                                              *
 *                   Global Variable Define                     *
 *                                                              *
 ****************************************************************/
static uint8 HSDErrorCheckFlag = 0;
/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/
static S_HighSideDrv_Dev *GetHighSideDrvDev(E_HSChannel HSChannel)
{
    S_HighSideDrv_Dev *tmp = gs_HighSideDrv_Dev_Header;

    while (tmp)
    {
        if ((tmp->HsdChMappingMask & (1 << HSChannel)) != 0)
            return tmp;

        tmp = tmp->ptNext;
    }

    return NULL;
}
/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
/* get the HSD current */
Std_ReturnType Interface_GetHighSideChannelCurrent(E_HSChannel HSChannel, uint16_t *current)
{
    Std_ReturnType rtval = E_OK;
    S_HighSideDrv_Dev *tmp = NULL;
    S_HighSideCurrentDataSrc HighSideCurrentDataSrc;
    S_HighSidekDataPackets HighSidekDataPackets;
    tmp = GetHighSideDrvDev(HSChannel);

    if (tmp == NULL)
        return E_NOT_OK;

    HighSideCurrentDataSrc.HSChannel = HSChannel;
    HighSideCurrentDataSrc.current = 0;
    HighSidekDataPackets.HighSideDataType = E_HighSideDataType_ChannelCurrent;
    HighSidekDataPackets.datasrc = (void *)&HighSideCurrentDataSrc;

    rtval |= tmp->Read((void *)(&HighSidekDataPackets));

    if (rtval == E_OK)
    {
        *current = HighSideCurrentDataSrc.current;
    }

    return rtval;
}
/* get the HSD diag */
Std_ReturnType Interface_GetHighSideChannelDiagInfo(E_HSChannel HSChannel, U_HSChannelDiagInfo *HSChannelDiagInfo)
{
    Std_ReturnType rtval = E_OK;
    S_HighSideDrv_Dev *tmp = NULL;
    S_HighSideDiagDataSrc HighSideDiagDataSrc = {HSChannel,0};
    S_HighSidekDataPackets HighSidekDataPackets;
    tmp = GetHighSideDrvDev(HSChannel);

    if (tmp == NULL)
    {
        return E_NOT_OK;
    }
    
    HighSidekDataPackets.HighSideDataType = E_HighSideDataType_ChannelDiagInfo;
    HighSidekDataPackets.datasrc = (void *)&HighSideDiagDataSrc;

    rtval |= tmp->Read((void *)(&HighSidekDataPackets));

    if (rtval == E_OK)
    {
        *HSChannelDiagInfo = HighSideDiagDataSrc.HSChannelDiagInfo;
    }

    return rtval;
}

/* get the HSD Status */
Std_ReturnType Interface_GetHighSideState(E_HSChannel HSChannel, E_HSDChannelSwitchState *Sts)
{
    S_HighSideDrv_Dev *tmp = NULL;

    tmp = GetHighSideDrvDev(HSChannel);
    if (tmp == NULL)
        return E_NOT_OK;

    *Sts = gE_HSDChannelSwitchState[HSChannel];

    return E_OK;
}

/* set  the HSD Status */
Std_ReturnType Interface_SetHighSideState(E_HSChannel HSChannel, E_HSDChannelSwitchState Sts)
{
    Std_ReturnType rtval = E_OK;
    S_HighSideDrv_Dev *tmp = NULL;
    S_HighSideSwitchStateDataSrc HighSideSwitchStateDataSrc;
    S_HighSidekDataPackets HighSidekDataPackets;

    tmp = GetHighSideDrvDev(HSChannel);

    if (tmp == NULL)
        return E_NOT_OK;

    if (gE_HSDChannelSwitchState[HSChannel] == Sts)
        return E_OK;

    HighSideSwitchStateDataSrc.HSChannel = HSChannel;
    HighSideSwitchStateDataSrc.HsdState = Sts;

    HighSidekDataPackets.HighSideDataType = E_HighSideDataType_ChannelSwitch;
    HighSidekDataPackets.datasrc = (void *)&HighSideSwitchStateDataSrc;

    rtval |= tmp->Write((void *)(&HighSidekDataPackets));

    if (rtval == E_OK)
    {
        gE_HSDChannelSwitchState[HSChannel] = Sts;
    }

    return rtval;
}

Std_ReturnType HighSide_Interface_Mainfunction(uint8_t timebase)
{
    Std_ReturnType rtval = E_OK;
    S_HighSideDrv_Dev *tmp = gs_HighSideDrv_Dev_Header;
    S_HighSideDevMainFuncDataSrc HighSideDevMainFuncDataSrc;
    S_HighSidekDataPackets HighSidekDataPackets;
    U_HSChannelDiagInfo HSChannelDiagInfo;
    uint8_t i = 0;

    while (tmp)
    {
        if (tmp->MainFunction != NULL)
        {
            HighSideDevMainFuncDataSrc.Device_id = tmp->Device_id;
            HighSidekDataPackets.HighSideDataType = E_HighSideDataType_DeviceMainFunction;
            HighSidekDataPackets.datasrc = (void *)(&HighSideDevMainFuncDataSrc);

            rtval |= tmp->MainFunction((void *)(&HighSidekDataPackets));
        }

        tmp = tmp->ptNext;
    }

    if(STD_OFF == Interface_GetHsdErrorCheck())
    {
        rtval = E_NOT_OK;
    }
    else
    {
        for (i = 0; i < CHANNEL_SIZE; i++)
        {
            if (gE_HSDChannelSwitchState[i] == E_HSDChannelSwitchState_OFF)
                continue;

            if (Interface_GetHighSideChannelDiagInfo((E_HSChannel)i, &HSChannelDiagInfo) != E_OK)
                continue;

            switch (i)
            {
            case E_HSChannel_HS0:
                if (HSChannelDiagInfo.bits.OverCurrent == 1)
                {
                    gs_HSDErrCnt[E_HSChannel_HS0].OverCurrentErrCnt = CNT_INC(gs_HSDErrCnt[E_HSChannel_HS0].OverCurrentErrCnt, STEP_1, CNT_LIMIT_10);
                    if (gs_HSDErrCnt[E_HSChannel_HS0].OverCurrentErrCnt >= CNT_LIMIT_10)
                    {
                        Interface_SetDtcHSDAndFanError(E_HSDAndFanErrorType_HSD0_OverCur, 1);
                    }
                }
                else
                {
                    gs_HSDErrCnt[E_HSChannel_HS0].OverCurrentErrCnt = CNT_DEC(gs_HSDErrCnt[E_HSChannel_HS0].OverCurrentErrCnt, STEP_10, DEC_LIMIT_0);
                    if (gs_HSDErrCnt[E_HSChannel_HS0].OverCurrentErrCnt <= DEC_LIMIT_0)
                    {
                        Interface_SetDtcHSDAndFanError(E_HSDAndFanErrorType_HSD0_OverCur, 0);
                    }
                }

                if (HSChannelDiagInfo.bits.Short2GND == 1)
                {
                    gs_HSDErrCnt[E_HSChannel_HS0].Short2GndErrCnt = CNT_INC(gs_HSDErrCnt[E_HSChannel_HS0].Short2GndErrCnt, STEP_1, CNT_LIMIT_10);
                    if (gs_HSDErrCnt[E_HSChannel_HS0].Short2GndErrCnt >= CNT_LIMIT_10)
                    {
                        Interface_SetDtcHSDAndFanError(E_HSDAndFanErrorType_HSD0_Shor2Gnd, 1);
                    }
                }
                else
                {
                    gs_HSDErrCnt[E_HSChannel_HS0].Short2GndErrCnt = CNT_DEC(gs_HSDErrCnt[E_HSChannel_HS0].Short2GndErrCnt, STEP_10, DEC_LIMIT_0);
                    if (gs_HSDErrCnt[E_HSChannel_HS0].Short2GndErrCnt <= DEC_LIMIT_0)
                    {
                        Interface_SetDtcHSDAndFanError(E_HSDAndFanErrorType_HSD0_Shor2Gnd, 0);
                    }
                }

                if (HSChannelDiagInfo.bits.OpenOrShort2Vcc == 1)
                {
                    gs_HSDErrCnt[E_HSChannel_HS0].OpenOrShort2VccErrCnt = CNT_INC(gs_HSDErrCnt[E_HSChannel_HS0].OpenOrShort2VccErrCnt, STEP_1, CNT_LIMIT_10);
                    if (gs_HSDErrCnt[E_HSChannel_HS0].OpenOrShort2VccErrCnt >= CNT_LIMIT_10)
                    {
                        Interface_SetDtcHSDAndFanError(E_HSDAndFanErrorType_HSD0_OpenOrShort2Vcc, 1);
                    }
                }
                else
                {
                    gs_HSDErrCnt[E_HSChannel_HS0].OpenOrShort2VccErrCnt = CNT_DEC(gs_HSDErrCnt[E_HSChannel_HS0].OpenOrShort2VccErrCnt, STEP_20, DEC_LIMIT_0);
                    if (gs_HSDErrCnt[E_HSChannel_HS0].OpenOrShort2VccErrCnt <= DEC_LIMIT_0)
                    {
                        Interface_SetDtcHSDAndFanError(E_HSDAndFanErrorType_HSD0_OpenOrShort2Vcc, 0);
                    }
                }
                break;
            case E_HSChannel_HS1:
                if (Interface_GetHSChannelDiagInfo(E_HSChannel_HS1) == 2)
                {
                    gs_HSDErrCnt[i].OverCurrentErrCnt = CNT_INC(gs_HSDErrCnt[i].OverCurrentErrCnt, STEP_1, CNT_LIMIT_10);
                    if (gs_HSDErrCnt[i].OverCurrentErrCnt >= CNT_LIMIT_10)
                    {
                        Interface_SetDtcHSDAndFanError((E_HSDAndFanErrorType_HSD1_OverCur + (i - E_HSChannel_HS1) * 3), 1);
                    }
                }
                else
                {
                    gs_HSDErrCnt[i].OverCurrentErrCnt = CNT_DEC(gs_HSDErrCnt[i].OverCurrentErrCnt, STEP_10, DEC_LIMIT_0);
                    if (gs_HSDErrCnt[i].OverCurrentErrCnt <= DEC_LIMIT_0)
                    {
                        Interface_SetDtcHSDAndFanError((E_HSDAndFanErrorType_HSD1_OverCur + (i - E_HSChannel_HS1) * 3), 0);
                    }
                }

                if (Interface_GetHSChannelDiagInfo(E_HSChannel_HS1) == 1)
                {
                    gs_HSDErrCnt[i].Short2GndErrCnt = CNT_INC(gs_HSDErrCnt[i].Short2GndErrCnt, STEP_1, CNT_LIMIT_10);
                    if (gs_HSDErrCnt[i].Short2GndErrCnt >= CNT_LIMIT_10)
                    {
                        Interface_SetDtcHSDAndFanError((E_HSDAndFanErrorType_HSD1_Shor2Gnd + (i - E_HSChannel_HS1) * 3), 1);
                    }
                }
                else
                {
                    gs_HSDErrCnt[i].Short2GndErrCnt = CNT_DEC(gs_HSDErrCnt[i].Short2GndErrCnt, STEP_10, DEC_LIMIT_0);
                    if (gs_HSDErrCnt[i].Short2GndErrCnt <= DEC_LIMIT_0)
                    {
                        Interface_SetDtcHSDAndFanError((E_HSDAndFanErrorType_HSD1_Shor2Gnd + (i - E_HSChannel_HS1) * 3), 0);
                    }
                }

                if (Interface_GetHSChannelDiagInfo(E_HSChannel_HS1) == 4)
                {
                    gs_HSDErrCnt[i].OpenOrShort2VccErrCnt = CNT_INC(gs_HSDErrCnt[i].OpenOrShort2VccErrCnt, STEP_1, CNT_LIMIT_10);
                    if (gs_HSDErrCnt[i].OpenOrShort2VccErrCnt >= CNT_LIMIT_10)
                    {
                        Interface_SetDtcHSDAndFanError((E_HSDAndFanErrorType_HSD1_OpenOrShort2Vcc + (i - E_HSChannel_HS1) * 3), 1);
                    }
                }
                else
                {
                    gs_HSDErrCnt[i].OpenOrShort2VccErrCnt = CNT_DEC(gs_HSDErrCnt[i].OpenOrShort2VccErrCnt, STEP_10, DEC_LIMIT_0);
                    if (gs_HSDErrCnt[i].OpenOrShort2VccErrCnt <= DEC_LIMIT_0)
                    {
                        Interface_SetDtcHSDAndFanError((E_HSDAndFanErrorType_HSD1_OpenOrShort2Vcc + (i - E_HSChannel_HS1) * 3), 0);
                    }
                }
                break;
            }
        }
    }

    return rtval;
}

Std_ReturnType Interface_GetHsdError(E_HSChannel hsdid)
{
    static Std_ReturnType rtval = E_OK;
    switch (hsdid)
    {
    case E_HSChannel_HS0:
        if((gs_HSDErrCnt[E_HSChannel_HS0].OverCurrentErrCnt >= CNT_LIMIT_10)||(gs_HSDErrCnt[E_HSChannel_HS0].Short2GndErrCnt >= CNT_LIMIT_10)||(gs_HSDErrCnt[E_HSChannel_HS0].OpenOrShort2VccErrCnt >= CNT_LIMIT_10))
        {
            rtval=E_NOT_OK;
        }
        else  if((gs_HSDErrCnt[E_HSChannel_HS0].OverCurrentErrCnt == DEC_LIMIT_0)&&(gs_HSDErrCnt[E_HSChannel_HS0].Short2GndErrCnt == DEC_LIMIT_0)&&(gs_HSDErrCnt[E_HSChannel_HS0].OpenOrShort2VccErrCnt == DEC_LIMIT_0))
        {
            rtval = E_OK;
        }
    break;
    case E_HSChannel_HS1:
        if((gs_HSDErrCnt[E_HSChannel_HS1].OverCurrentErrCnt >= CNT_LIMIT_10)||(gs_HSDErrCnt[E_HSChannel_HS1].Short2GndErrCnt >= CNT_LIMIT_10)||(gs_HSDErrCnt[E_HSChannel_HS1].OpenOrShort2VccErrCnt >= CNT_LIMIT_10))
        {
            rtval=E_NOT_OK;
        }
        else if((gs_HSDErrCnt[E_HSChannel_HS1].OverCurrentErrCnt == DEC_LIMIT_0)&&(gs_HSDErrCnt[E_HSChannel_HS1].Short2GndErrCnt == DEC_LIMIT_0)&&(gs_HSDErrCnt[E_HSChannel_HS1].OpenOrShort2VccErrCnt == DEC_LIMIT_0))
        {
            rtval = E_OK;
        }
    break;
    default:
        break;
    }
    return rtval;
}
Std_ReturnType Interface_HighSideInit(void)
{
    Std_ReturnType rtval = E_OK;
    S_HighSideDrv_Dev *tmp = gs_HighSideDrv_Dev_Header;
    S_HighSideDevInitDataSrc HighSideDevInitDataSrc;
    S_HighSidekDataPackets HighSidekDataPackets;

    while (tmp)
    {
        HighSidekDataPackets.HighSideDataType = E_HighSideDataType_DeviceInit;
        HighSidekDataPackets.datasrc = (void *)(&HighSideDevInitDataSrc);

        rtval |= tmp->DeviceInit((void *)(&HighSidekDataPackets));

        tmp = tmp->ptNext;
    }

    return rtval;
}

Std_ReturnType HighSideDrvDev_Register(S_HighSideDrv_Dev *Drv_Dev)
{
    S_HighSideDrv_Dev *tmp = gs_HighSideDrv_Dev_Header;

    if (gs_HighSideDrv_Dev_Header == NULL)
    {
        gs_HighSideDrv_Dev_Header = Drv_Dev;
        gs_HighSideDrv_Dev_Header->ptNext = NULL;
    }
    else
    {
        while (tmp->ptNext != NULL)
            tmp = tmp->ptNext;
        tmp->ptNext = Drv_Dev;
        Drv_Dev->ptNext = NULL;
    }
    return E_OK;
}


void Interface_SetHsdErrorCheck(uint8 status)
{
    HSDErrorCheckFlag = status;
}

Std_ReturnType Interface_GetHsdErrorCheck(void)
{
    return HSDErrorCheckFlag;
}