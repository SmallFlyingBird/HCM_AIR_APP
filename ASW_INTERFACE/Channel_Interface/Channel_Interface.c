/*
 * Channel_Interface.c
 *
 *  Created on: 2024��1��9��
 *      Author: mihuiliang
 */

#ifndef ASW_INTERFACE_CHANNEL_INTERFACE_CHANNEL_INTERFACE_C_
#define ASW_INTERFACE_CHANNEL_INTERFACE_CHANNEL_INTERFACE_C_

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "Channel_Interface.h"
#include "GeneralFunction.h"
#include "Parameter_Interface.h"
#include "DTC_Interface.h"
#include "ComSignal_Interface.h"
#include "NtcRcod_Interface.h"
#include "DidConfig.h"
#include "DID_Interface.h"
/****************************************************************
 *                                                              *
 *                  Global Private Variable Define              *
 *                                                              *
 ****************************************************************/
static S_ChannelControl g_S_ChannelControl[MAX_CHANNLE_NUM] = {
    {.channel_ParaNormalcurrent = INVALIED_CURRENT, .channel_bincurrent = INVALIED_CURRENT, .channel_DidConfigcurrent = INVALIED_CURRENT, .channel_DidconfigcurrentRef = DIDSIGNALNAME_ID_Ch1MaxCur},
    {.channel_ParaNormalcurrent = INVALIED_CURRENT, .channel_bincurrent = INVALIED_CURRENT, .channel_DidConfigcurrent = INVALIED_CURRENT, .channel_DidconfigcurrentRef = DIDSIGNALNAME_ID_Ch2MaxCur},
    {.channel_ParaNormalcurrent = INVALIED_CURRENT, .channel_bincurrent = INVALIED_CURRENT, .channel_DidConfigcurrent = INVALIED_CURRENT, .channel_DidconfigcurrentRef = DIDSIGNALNAME_ID_Ch3MaxCur},
    {.channel_ParaNormalcurrent = INVALIED_CURRENT, .channel_bincurrent = INVALIED_CURRENT, .channel_DidConfigcurrent = INVALIED_CURRENT, .channel_DidconfigcurrentRef = DIDSIGNALNAME_ID_Ch4MaxCur},
    {.channel_ParaNormalcurrent = INVALIED_CURRENT, .channel_bincurrent = INVALIED_CURRENT, .channel_DidConfigcurrent = INVALIED_CURRENT, .channel_DidconfigcurrentRef = DIDSIGNALNAME_ID_Ch5MaxCur},
    {.channel_ParaNormalcurrent = INVALIED_CURRENT, .channel_bincurrent = INVALIED_CURRENT, .channel_DidConfigcurrent = INVALIED_CURRENT, .channel_DidconfigcurrentRef = DIDSIGNALNAME_ID_Ch6MaxCur},
    {.channel_ParaNormalcurrent = INVALIED_CURRENT, .channel_bincurrent = INVALIED_CURRENT, .channel_DidConfigcurrent = INVALIED_CURRENT, .channel_DidconfigcurrentRef = DIDSIGNALNAME_ID_Ch7MaxCur},
    {.channel_ParaNormalcurrent = INVALIED_CURRENT, .channel_bincurrent = INVALIED_CURRENT, .channel_DidConfigcurrent = INVALIED_CURRENT, .channel_DidconfigcurrentRef = DIDSIGNALNAME_ID_Ch8MaxCur},
    {.channel_ParaNormalcurrent = INVALIED_CURRENT, .channel_bincurrent = INVALIED_CURRENT, .channel_DidConfigcurrent = INVALIED_CURRENT, .channel_DidconfigcurrentRef = DIDSIGNALNAME_ID_Ch9MaxCur},
    {.channel_ParaNormalcurrent = INVALIED_CURRENT, .channel_bincurrent = INVALIED_CURRENT, .channel_DidConfigcurrent = INVALIED_CURRENT, .channel_DidconfigcurrentRef = DIDSIGNALNAME_ID_Ch10MaxCur},
    {.channel_ParaNormalcurrent = INVALIED_CURRENT, .channel_bincurrent = INVALIED_CURRENT, .channel_DidConfigcurrent = INVALIED_CURRENT, .channel_DidconfigcurrentRef = DIDSIGNALNAME_ID_Ch11MaxCur},
    {.channel_ParaNormalcurrent = INVALIED_CURRENT, .channel_bincurrent = INVALIED_CURRENT, .channel_DidConfigcurrent = INVALIED_CURRENT, .channel_DidconfigcurrentRef = DIDSIGNALNAME_ID_Ch12MaxCur},
};
static uint16_t gu_channelmask = 0;

/****************************************************************
 *                                                              *
 *                   Global Variable Define                     *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Global Private Functions Define            *
 *                                                              *
 ****************************************************************/
static Std_ReturnType Interface_GetChannelDiagState(E_ChannelID id, U_ChannelDiagState *ChannelDiagState)
{
    Std_ReturnType rtval = E_OK;
    S_BuckDrv_Dev *BuckDrvDev = NULL;
    S_BuckDataPackets BuckDataPackets;
    S_ChannelDiagStateDataSrc ChannelDiagStateDataSrc;

    BuckDrvDev = GetBuckDrvDevByChId(id);

    if (BuckDrvDev == NULL)
        return E_NOT_OK;

    ChannelDiagStateDataSrc.ChannelID = id;

    BuckDataPackets.BuckDataType = E_BuckDataType_ChannelDiagState;
    BuckDataPackets.datasrc = (void *)(&ChannelDiagStateDataSrc);

    rtval |= BuckDrvDev->Read((void *)(&BuckDataPackets));

    if (rtval == E_OK)
    {
        *ChannelDiagState = ChannelDiagStateDataSrc.ChannelDiagState;
    }

    return rtval;
}

static Std_ReturnType ChannelDiagFunction(E_ChannelID id)
{
    Std_ReturnType rtval = E_OK;
    U_ChannelDiagState ChannelDiagState;
    uint8_t channel_pwm = 0;
    // uint8_t MatrixChipDevAddress;
    double voltage;

    if (g_S_ChannelControl[id].channel_state == CHANNEL_STATE_ON)
    {
        /*channel is open */
        if (g_S_ChannelControl[id].channelontimer < g_S_ChannelControl[id].channelon_diag_delaytimer)
            return E_OK;

        rtval |= Interface_GetChannelDiagState(id, &ChannelDiagState);

        if (rtval != E_OK)
            return rtval;

        if (ChannelDiagState.Bits.OpenError == 1)
        {
            /*open error*/
            g_S_ChannelControl[id].channel_open_errorcnt = CNT_INC(g_S_ChannelControl[id].channel_open_errorcnt, STEP_1, CNT_LIMIT_5);
            g_S_ChannelControl[id].channel_short2GND_errorcnt = CNT_DEC(g_S_ChannelControl[id].channel_short2GND_errorcnt, STEP_1, DEC_LIMIT_0);
            g_S_ChannelControl[id].channel_lowvoltage_errorcnt = CNT_DEC(g_S_ChannelControl[id].channel_lowvoltage_errorcnt, STEP_1, DEC_LIMIT_0);
        }
        else if (ChannelDiagState.Bits.Short2Gnd == 1)
        {
            /*open error*/
            g_S_ChannelControl[id].channel_open_errorcnt = CNT_DEC(g_S_ChannelControl[id].channel_open_errorcnt, STEP_1, DEC_LIMIT_0);
            g_S_ChannelControl[id].channel_short2GND_errorcnt = CNT_INC(g_S_ChannelControl[id].channel_short2GND_errorcnt, STEP_1, CNT_LIMIT_5);
            g_S_ChannelControl[id].channel_lowvoltage_errorcnt = CNT_DEC(g_S_ChannelControl[id].channel_lowvoltage_errorcnt, STEP_1, DEC_LIMIT_0);
        }
        else if (ChannelDiagState.Bits.Pending == 1)
        {
            /*do nothing */
        }
        else /*no error */
        {
            g_S_ChannelControl[id].channel_open_errorcnt = CNT_DEC(g_S_ChannelControl[id].channel_open_errorcnt, STEP_1, DEC_LIMIT_0);
            g_S_ChannelControl[id].channel_short2GND_errorcnt = CNT_DEC(g_S_ChannelControl[id].channel_short2GND_errorcnt, STEP_1, DEC_LIMIT_0);    
        }
    }
    else
    {
        /*channel is close */
        if (g_S_ChannelControl[id].channelOfftimer < g_S_ChannelControl[id].channeloff_diag_delaytimer)
            return E_OK;

        rtval |= Interface_GetChannelVoltage(id, &voltage);

        if (rtval != E_OK)
            return rtval;

        if (voltage > CHANNEL_SHORT2VCC_VOLTAGE_LIMIT)
        {
            g_S_ChannelControl[id].channel_short2VCC_errorcnt = CNT_INC(g_S_ChannelControl[id].channel_short2VCC_errorcnt, STEP_1, CNT_LIMIT_5);
        }
        else if (voltage < (CHANNEL_SHORT2VCC_VOLTAGE_LIMIT - SHORT2BATTARY_VOLATGE_HYSTERESIS)) /*HCM_SRS_2_0006*/
        {
            g_S_ChannelControl[id].channel_short2VCC_errorcnt = CNT_DEC(g_S_ChannelControl[id].channel_short2VCC_errorcnt, STEP_1, DEC_LIMIT_0);
        }
    }

    /*****Notify Dtc Layer***/
    if (g_S_ChannelControl[id].channel_open_errorcnt >= CNT_LIMIT_5 || g_S_ChannelControl[id].channel_overvoltage_errorcnt >= CNT_LIMIT_5)
    {
        Interface_SetDtcChannelError(id, E_CAHNNEL_OPEN, 1);
    }
    else if (g_S_ChannelControl[id].channel_open_errorcnt == 0 && g_S_ChannelControl[id].channel_overvoltage_errorcnt == 0)
    {
        Interface_SetDtcChannelError(id, E_CAHNNEL_OPEN, 0);
    }

    if (g_S_ChannelControl[id].channel_short2GND_errorcnt >= CNT_LIMIT_5)
    {
        Interface_SetDtcChannelError(id, E_CAHNNEL_SHORT2GND, 1);
    }
    else if (g_S_ChannelControl[id].channel_short2GND_errorcnt == 0)
    {
        Interface_SetDtcChannelError(id, E_CAHNNEL_SHORT2GND, 0);
    }

    if (g_S_ChannelControl[id].channel_lowvoltage_errorcnt >= CNT_LIMIT_5)
    {
        Interface_SetDtcChannelError(id, E_CAHNNEL_UNVOL, 1);
    }
    else if (g_S_ChannelControl[id].channel_lowvoltage_errorcnt == 0)
    {
        Interface_SetDtcChannelError(id, E_CAHNNEL_UNVOL, 0);
    }

    if (g_S_ChannelControl[id].channel_short2VCC_errorcnt >= CNT_LIMIT_5)
    {
        Interface_SetDtcChannelError(id, E_CAHNNEL_SHORT2VCC, 1);
    }
    else if (g_S_ChannelControl[id].channel_short2VCC_errorcnt == 0)
    {
        Interface_SetDtcChannelError(id, E_CAHNNEL_SHORT2VCC, 0);
    }

    return rtval;
}

/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
Std_ReturnType Interface_SetChannelDiagSwitch(E_ChannelID id, uint8_t DiagEn)
{
    if (DiagEn != 0)
    {
        g_S_ChannelControl[id].channelinfo.bits.IsChannelDiagEnable = 1;
    }
    else
    {
        g_S_ChannelControl[id].channelinfo.bits.IsChannelDiagEnable = 0;
    }
    return E_OK;
}

Std_ReturnType Interface_SetChannelOnDiagDelaytimer(E_ChannelID id, uint16_t timer)
{
    g_S_ChannelControl[id].channelon_diag_delaytimer = timer;
    return E_OK;
}

Std_ReturnType Interface_SetChannelOffDiagDelaytimer(E_ChannelID id, uint16_t timer)
{
    g_S_ChannelControl[id].channeloff_diag_delaytimer = timer;
    return E_OK;
}
Std_ReturnType Interface_SetChannelBinCurrent(E_ChannelID id, uint16_t current)
{
    Std_ReturnType rtval = E_OK;
    g_S_ChannelControl[id].channel_bincurrent = current;
    return rtval;
}
Std_ReturnType Interface_SetChannelCurrent(E_ChannelID id, uint16_t current)
{
    Std_ReturnType rtval = E_OK;
    S_BuckDrv_Dev *BuckDrvDev = NULL;
    S_BuckDataPackets BuckDataPackets;
    S_ChannelCurrentDataSrc ChannelCurrentDataSrc;

    if (g_S_ChannelControl[id].channel_current_cur == current)
    {
        return E_OK;
    }
    BuckDrvDev = GetBuckDrvDevByChId(id);

    if (BuckDrvDev == NULL)
        return E_NOT_OK;

    ChannelCurrentDataSrc.ChannelID = id;
    ChannelCurrentDataSrc.CurrentValue = current;

    BuckDataPackets.BuckDataType = E_BuckDataType_ChannelCurrent;
    BuckDataPackets.datasrc = (void *)(&ChannelCurrentDataSrc);

    rtval |= BuckDrvDev->Write((void *)(&BuckDataPackets));

    if (rtval == E_OK)
    {
        g_S_ChannelControl[id].channel_current_cur = current;
    }

    return rtval;
}
Std_ReturnType Interface_SetChannelPWM(E_ChannelID id, uint8_t pwm)
{
    Std_ReturnType rtval = E_OK;
    S_BuckDrv_Dev *BuckDrvDev = NULL;
    S_BuckDataPackets BuckDataPackets;
    S_ChannelPwmDataSrc ChannelPwmDataSrc;

    if (g_S_ChannelControl[id].channel_current_pwm == pwm)
    {
        return E_OK;
    }
    BuckDrvDev = GetBuckDrvDevByChId(id);

    if (BuckDrvDev == NULL)
        return E_NOT_OK;

    ChannelPwmDataSrc.ChannelID = id;
    if (pwm > 100)
        pwm = 100;
    ChannelPwmDataSrc.PwmValue = pwm;

    BuckDataPackets.BuckDataType = E_BuckDataType_ChannelPWM;
    BuckDataPackets.datasrc = (void *)(&ChannelPwmDataSrc);

    rtval |= BuckDrvDev->Write((void *)(&BuckDataPackets));

    if (rtval == E_OK)
    {
        g_S_ChannelControl[id].channel_current_pwm = pwm;
    }

    return rtval;
}
Std_ReturnType Interface_SetChannelSwitchState(E_ChannelID id, E_ChannelState channelstate)
{

    Std_ReturnType rtval = E_OK;
    S_BuckDrv_Dev *BuckDrvDev = NULL;
    S_BuckDataPackets BuckDataPackets;
    S_ChannelSwitchStateDataSrc ChannelSwitchStateDataSrc;

    if (g_S_ChannelControl[id].channel_state == channelstate)
    {
        return E_OK;
    }
    BuckDrvDev = GetBuckDrvDevByChId(id);

    if (BuckDrvDev == NULL)
        return E_NOT_OK;

    ChannelSwitchStateDataSrc.ChannelID = id;
    ChannelSwitchStateDataSrc.SwitchStateValue = channelstate;

    BuckDataPackets.BuckDataType = E_BuckDataType_ChannelSwitchState;
    BuckDataPackets.datasrc = (void *)(&ChannelSwitchStateDataSrc);

    rtval |= BuckDrvDev->Write((void *)(&BuckDataPackets));

    if (rtval == E_OK)
    {
        g_S_ChannelControl[id].channel_state = channelstate;
    }

    return rtval;
}
uint16_t Interface_GetChannelMask(void)
{
    return gu_channelmask;
}

Std_ReturnType Interface_GetChannelTemperature(E_ChannelID id, sint16 *tmp)
{
    uint16_t ChannelMask = 0;
    E_NtcRcodFunction NtcRcodFunction = E_NtcRcodFunction_Ntc1;

    for (NtcRcodFunction = E_NtcRcodFunction_Ntc1; NtcRcodFunction <= E_NtcRcodFunction_MatrixNtc2; NtcRcodFunction++)
    {
        if (Interface_GetNtcTemperature(NtcRcodFunction, tmp) == E_OK)
        {
            if (Interface_GetNtcRcodMap2ChannelMask(NtcRcodFunction, &ChannelMask) == E_OK)
            {
                if ((ChannelMask & (1 << id)) != 0)
                    return E_OK;
            }
        }
    }
    return E_NOT_OK;
}

Std_ReturnType Interface_GetChannelFrequency(E_ChannelID id, uint16_t *Freq)
{
    Std_ReturnType rtval = E_OK;
    S_BuckDrv_Dev *BuckDrvDev = NULL;
    S_BuckDataPackets BuckDataPackets;
    S_ChannelFrequencyDataSrc ChannelFrequencyDataSrc;

    BuckDrvDev = GetBuckDrvDevByChId(id);

    if (BuckDrvDev == NULL)
        return E_NOT_OK;

    ChannelFrequencyDataSrc.ChannelID = id;

    BuckDataPackets.BuckDataType = E_BuckDataType_ChannelFrequency;
    BuckDataPackets.datasrc = (void *)(&ChannelFrequencyDataSrc);

    rtval |= BuckDrvDev->Read((void *)(&BuckDataPackets));

    if (rtval == E_OK)
    {
        *Freq = ChannelFrequencyDataSrc.ChannelFrequency;
    }

    return rtval;
}

Std_ReturnType Interface_GetChannelVoltage(E_ChannelID id, double *voltage)
{
    Std_ReturnType rtval = E_OK;
    S_BuckDrv_Dev *BuckDrvDev = NULL;
    S_BuckDataPackets BuckDataPackets;
    S_ChannelVoltageDataSrc ChannelVoltageDataSrc;

    BuckDrvDev = GetBuckDrvDevByChId(id);

    if (BuckDrvDev == NULL)
        return E_NOT_OK;

    ChannelVoltageDataSrc.ChannelID = id;
    BuckDataPackets.BuckDataType = E_BuckDataType_ChannelVoltage;
    BuckDataPackets.datasrc = (void *)(&ChannelVoltageDataSrc);

    rtval |= BuckDrvDev->Read((void *)(&BuckDataPackets));

    if (rtval == E_OK)
    {
        *voltage = ChannelVoltageDataSrc.ChannelVoltageValue;
    }

    return rtval;
}

Std_ReturnType Interface_GetChannelSwitchState(E_ChannelID id, E_ChannelState *channelstate)
{
    *channelstate = g_S_ChannelControl[id].channel_state;
    return E_OK;
}

uint16_t Interface_GetChannelDidConfigCurrent(E_ChannelID id)
{
    return g_S_ChannelControl[id].channel_DidConfigcurrent;
}

uint16_t Interface_GetChannelBinCurrent(E_ChannelID id)
{
    return g_S_ChannelControl[id].channel_bincurrent;
}

uint16_t Interface_GetChannelParamTableNormalCurrent(E_ChannelID id)
{
    return g_S_ChannelControl[id].channel_ParaNormalcurrent;
}
/*获得通道当前电流*/
uint16_t Interface_GetChannelCurCurrent(E_ChannelID id)
{
    return g_S_ChannelControl[id].channel_current_cur;
}
/*
 *获得通道的当前占空比
 *返回值0-100 表示0%-100%
 */
uint8_t Interface_GetChannelCurPWM(E_ChannelID id)
{
    return g_S_ChannelControl[id].channel_current_pwm;
}

/*
 * suggest put this function into 1ms task
 *
 */
Std_ReturnType Channel_Interface_TimerMainFunction(uint8_t timebase)
{
    E_ChannelID chid = ChannelID1;
    for (chid = ChannelID1; chid < MAX_CHANNLE_NUM; chid++)
    {
        if (g_S_ChannelControl[chid].channelinfo.bits.IsChannelConfiged == 0)
            continue;

        if (g_S_ChannelControl[chid].channel_state == CHANNEL_STATE_ON)
        {
            g_S_ChannelControl[chid].channelontimer += timebase;
            g_S_ChannelControl[chid].channeltotalontimer += timebase;
            g_S_ChannelControl[chid].channelOfftimer = 0;
        }
        else
        {
            g_S_ChannelControl[chid].channelontimer = 0;
            g_S_ChannelControl[chid].channelOfftimer += timebase;
        }
    }
}

/*
 * suggest put this function into 10ms task
 *
 */
Std_ReturnType Channel_Interface_MainFunction(uint8_t timebase)
{
    E_ChannelID chid = ChannelID1;
//测试代码
    g_S_ChannelControl[0].channelinfo.bits.IsChannelConfiged =1;
    g_S_ChannelControl[1].channelinfo.bits.IsChannelConfiged =1;
    g_S_ChannelControl[0].channelinfo.bits.IsChannelDiagEnable=1;
    g_S_ChannelControl[1].channelinfo.bits.IsChannelDiagEnable=1;

    for (chid = ChannelID1; chid < MAX_CHANNLE_NUM; chid++)
    {
        if (g_S_ChannelControl[chid].channelinfo.bits.IsChannelConfiged == 0)
            continue;

        if (g_S_ChannelControl[chid].channelinfo.bits.IsChannelDiagEnable == 0)
            continue;

        ChannelDiagFunction(chid);
    }

    return E_OK;
}

Std_ReturnType Interface_ChannelInit(void)
{
    Std_ReturnType rtval = E_OK;
    Light_Functions lf = E_LowBeamFlat;
    E_ChannelID chid = ChannelID1;
    uint16_t didsignalid = 0;
    uint32_t didconfigcurrent = 0;
    uint8_t DidCfgErr = 0;

    for (lf = E_LowBeamFlat; lf <= E_AssistantLight; lf++)
    {
        if (GetChannelMaskByLightFunction(lf) != 0)
        {
            gu_channelmask |= GetChannelMaskByLightFunction(lf);
        }
    }
    /*高4位清0 ，低12位保持不变*/
    gu_channelmask &= 0x0FFF;

    for (chid = ChannelID1; chid < MAX_CHANNLE_NUM; chid++)
    {
        if (((1 << chid) & gu_channelmask) != 0)
        {
            /*��ͨ��ʹ��*/
            g_S_ChannelControl[chid].channelinfo.bits.IsChannelConfiged = 1;
            g_S_ChannelControl[chid].channelinfo.bits.IsChannelDiagEnable = 1;
            /*�ж��Ƿ��о���оƬ*/
            // if ((Get_MatrixRealisation() & (1 << chid)) != 0)
            // {
            //     g_S_ChannelControl[chid].channelinfo.bits.IsChannelConfigedMatrixChip = 1;
            // }
            // else
            // {
            //     g_S_ChannelControl[chid].channelinfo.bits.IsChannelConfigedMatrixChip = 0;
            // }

            /*Set channel_DidConfigcurrent */
            didsignalid = g_S_ChannelControl[chid].channel_DidconfigcurrentRef;
            if (Interface_GetDidSignalData(didsignalid, &didconfigcurrent) == E_OK)
            {
                if (didconfigcurrent == 0xFFF)
                {
                    g_S_ChannelControl[chid].channel_DidConfigcurrent = 0xFFFF;
                    // g_S_ChannelControl[chid].channel_ParaNormalcurrent = Get_pLedNormalCurrent(chid);
                }
                else
                {
                    g_S_ChannelControl[chid].channel_DidConfigcurrent = (uint16_t)didconfigcurrent;
                }
            }
            else
            {
                g_S_ChannelControl[chid].channel_DidConfigcurrent = 0xFFFF;
                // g_S_ChannelControl[chid].channel_ParaNormalcurrent = Get_pLedNormalCurrent(chid);
            }

            g_S_ChannelControl[chid].channelon_diag_delaytimer = 100;
            g_S_ChannelControl[chid].channeloff_diag_delaytimer = 100;
        }
        else
        {
            g_S_ChannelControl[chid].channelinfo.bits.IsChannelConfiged = 0;
            g_S_ChannelControl[chid].channelinfo.bits.IsChannelDiagEnable = 0;
            // g_S_ChannelControl[chid].channelinfo.bits.IsChannelConfigedMatrixChip = 0;
        }
    }

    if (DidCfgErr == 0)
    {
        Interface_SetSystemError(E_SystemErrorType_ChannelCurrentConfigError, 0);
    }
    else
    {
        Interface_SetSystemError(E_SystemErrorType_ChannelCurrentConfigError, 1);
    }

    return rtval;
}

#endif /* ASW_INTERFACE_CHANNEL_INTERFACE_CHANNEL_INTERFACE_C_ */
