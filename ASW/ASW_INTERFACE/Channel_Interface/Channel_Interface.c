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
#include "NtcRcod_Interface.h"
#include "DidConfig.h"
#include "DID_Interface.h"
#include "OUVDerate_Interface.h"
#define CHANNELOFFMINTIME  200
/****************************************************************
 *                                                              *
 *                  Global Private Variable Define              *
 *                                                              *
 ****************************************************************/
static S_ChannelControl g_S_ChannelControl[MAX_CHANNLE_NUM] = {
    {
        .channel_ParaNormalcurrent = INVALIED_CURRENT,
        .channel_bincurrent = INVALIED_CURRENT,
        .channel_DidConfigcurrent = INVALIED_CURRENT,
        // .channel_DidconfigcurrentRef = DIDSIGNALNAME_ID_Ch1MaxCur,
    },
    {
        .channel_ParaNormalcurrent = INVALIED_CURRENT,
        .channel_bincurrent = INVALIED_CURRENT,
        .channel_DidConfigcurrent = INVALIED_CURRENT,
        // .channel_DidconfigcurrentRef = DIDSIGNALNAME_ID_Ch2MaxCur,
    },
    {
        .channel_ParaNormalcurrent = INVALIED_CURRENT,
        .channel_bincurrent = INVALIED_CURRENT,
        .channel_DidConfigcurrent = INVALIED_CURRENT,
        // .channel_DidconfigcurrentRef = DIDSIGNALNAME_ID_Ch3MaxCur,
    },
    {
        .channel_ParaNormalcurrent = INVALIED_CURRENT,
        .channel_bincurrent = INVALIED_CURRENT,
        .channel_DidConfigcurrent = INVALIED_CURRENT,
        // .channel_DidconfigcurrentRef = DIDSIGNALNAME_ID_Ch4MaxCur,
    },
    {
        .channel_ParaNormalcurrent = INVALIED_CURRENT,
        .channel_bincurrent = INVALIED_CURRENT,
        .channel_DidConfigcurrent = INVALIED_CURRENT,
        // .channel_DidconfigcurrentRef = DIDSIGNALNAME_ID_Ch5MaxCur,
    },
    {
        .channel_ParaNormalcurrent = INVALIED_CURRENT,
        .channel_bincurrent = INVALIED_CURRENT,
        .channel_DidConfigcurrent = INVALIED_CURRENT,
        // .channel_DidconfigcurrentRef = DIDSIGNALNAME_ID_Ch6MaxCur,
    },
};
static uint8 gu_channelmask = 0;
/*通道电压有效标记位*/
static uint16_t gu_ChannelVoltageValiedFlag = 0;

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
uint16_t Interface_GetChannelMask(void)
{
    return gu_channelmask;
}

static Std_ReturnType UpdateChannelVoltageFromBuckDriver(E_ChannelID id)
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
        /*电压获取成功*/
        g_S_ChannelControl[id].Channel_CurVoltage = ChannelVoltageDataSrc.ChannelVoltageValue;
        gu_ChannelVoltageValiedFlag |= (1 << id);
    }

    return rtval;
}

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
/* 
data=0 disable
data=1 enable
 */
void ChannelDiagEnable(E_ChannelID id,uint8 data)
{
    g_S_ChannelControl[id].channelDiagEn=data;
}
static Std_ReturnType ChannelDiagFunction(E_ChannelID id)
{
    Std_ReturnType rtval = E_OK;
    U_ChannelDiagState ChannelDiagState;
    uint8_t channel_pwm = 0;
    double voltage;
    E_ChannelID id0=0;
    if(Interface_GetDerateRatioOfOUV()==0)
    {       
        return E_NOT_OK; /* when the supply is low ,don't diag . */
    }
    if ((g_S_ChannelControl[id].channel_state == CHANNEL_STATE_ON)&&(g_S_ChannelControl[id].channelDiagEn==1))
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

            channel_pwm = g_S_ChannelControl[id].channel_current_pwm;

            /*Full pwm*/
            /*从buck里面获取电压，并更新到g_S_ChannelControl中*/
            UpdateChannelVoltageFromBuckDriver(id);

            if ((gu_ChannelVoltageValiedFlag & (1 << id)) == 0)
                return E_NOT_OK; /*the first val no use*/

            voltage = g_S_ChannelControl[id].Channel_CurVoltage;

            if (Get_pLedUminVoltage(id) > ((uint16_t)(voltage * 10)))
            {
                g_S_ChannelControl[id].channel_lowvoltage_errorcnt = CNT_INC(g_S_ChannelControl[id].channel_lowvoltage_errorcnt, STEP_1, CNT_LIMIT_5);
                g_S_ChannelControl[id].channel_overvoltage_errorcnt = CNT_DEC(g_S_ChannelControl[id].channel_overvoltage_errorcnt, STEP_1, DEC_LIMIT_0);
            }
            else if (Get_pLedUminVoltage(id) < ((uint16_t)(voltage * 10) - 10)) /*HCM_SRS_2_0004*/
            {
                g_S_ChannelControl[id].channel_lowvoltage_errorcnt = CNT_DEC(g_S_ChannelControl[id].channel_lowvoltage_errorcnt, STEP_1, DEC_LIMIT_0);

                if ((Get_pLedUmaxVoltage(id)) < ((uint16_t)(voltage * 10)))
                {
                    g_S_ChannelControl[id].channel_overvoltage_errorcnt = CNT_INC(g_S_ChannelControl[id].channel_overvoltage_errorcnt, STEP_1, CNT_LIMIT_5);
                }
                else
                {
                    g_S_ChannelControl[id].channel_overvoltage_errorcnt = CNT_DEC(g_S_ChannelControl[id].channel_overvoltage_errorcnt, STEP_1, DEC_LIMIT_0);
                }
            }
        }
    }
    else
    {
        /*channel is close */
        if(g_S_ChannelControl[id].channeloff_diag_delaytimer<CHANNELOFFMINTIME)
        {
            g_S_ChannelControl[id].channeloff_diag_delaytimer=CHANNELOFFMINTIME;
        }
        if (g_S_ChannelControl[id].channelOfftimer < g_S_ChannelControl[id].channeloff_diag_delaytimer)
            return E_OK;

        /*从buck里面获取电压，并更新到g_S_ChannelControl中*/
        UpdateChannelVoltageFromBuckDriver(id);

        if ((gu_ChannelVoltageValiedFlag & (1 << id)) == 0)
            return E_NOT_OK; /*首次电压数据暂未获取到*/

        voltage = g_S_ChannelControl[id].Channel_CurVoltage;

        if (voltage > CHANNEL_SHORT2VCC_VOLTAGE_LIMIT)
        {
            g_S_ChannelControl[id].channel_short2VCC_errorcnt = CNT_INC(g_S_ChannelControl[id].channel_short2VCC_errorcnt, STEP_1, CNT_LIMIT_5);
        }
        else if (voltage < (CHANNEL_SHORT2VCC_VOLTAGE_LIMIT - SHORT2BATTARY_VOLATGE_HYSTERESIS)) /*HCM_SRS_2_0006*/
        {
            g_S_ChannelControl[id].channel_short2VCC_errorcnt = CNT_DEC(g_S_ChannelControl[id].channel_short2VCC_errorcnt, STEP_1, DEC_LIMIT_0);
        }
    }
    for(id0=0;id0<CHANNEL_NUM;id0++)
    {
    /*****Notify Dtc Layer***/
        if (g_S_ChannelControl[id0].channel_open_errorcnt >= CNT_LIMIT_5 || g_S_ChannelControl[id0].channel_overvoltage_errorcnt >= CNT_LIMIT_5)
        {
            Interface_SetDtcChannelError(id0, E_CAHNNEL_OPEN, 1);
        }
        else if (g_S_ChannelControl[id0].channel_open_errorcnt == 0 && g_S_ChannelControl[id0].channel_overvoltage_errorcnt == 0)
        {
            Interface_SetDtcChannelError(id0, E_CAHNNEL_OPEN, 0);
        }

        if (g_S_ChannelControl[id0].channel_short2GND_errorcnt >= CNT_LIMIT_5)
        {
            Interface_SetDtcChannelError(id0, E_CAHNNEL_SHORT2GND, 1);
        }
        else if (g_S_ChannelControl[id0].channel_short2GND_errorcnt == 0)
        {
            Interface_SetDtcChannelError(id0, E_CAHNNEL_SHORT2GND, 0);
        }

        if (g_S_ChannelControl[id0].channel_lowvoltage_errorcnt >= CNT_LIMIT_5)
        {
            Interface_SetDtcChannelError(id0, E_CAHNNEL_UNVOL, 1);
        }
        else if (g_S_ChannelControl[id0].channel_lowvoltage_errorcnt == 0)
        {
            Interface_SetDtcChannelError(id0, E_CAHNNEL_UNVOL, 0);
        }

        if (g_S_ChannelControl[id0].channel_short2VCC_errorcnt >= CNT_LIMIT_5)
        {
            Interface_SetDtcChannelError(id0, E_CAHNNEL_SHORT2VCC, 1);
        }
        else if (g_S_ChannelControl[id0].channel_short2VCC_errorcnt == 0)
        {
            Interface_SetDtcChannelError(id0, E_CAHNNEL_SHORT2VCC, 0);
        }
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

    if ((gu_ChannelVoltageValiedFlag & (1 << id)) == 0)
    {
        rtval = E_NOT_OK;
    }
    else
    {
        *voltage = g_S_ChannelControl[id].Channel_CurVoltage;
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
            g_S_ChannelControl[chid].channelOfftimer = 0;
        }
        else
        {
            g_S_ChannelControl[chid].channelontimer = 0;
            g_S_ChannelControl[chid].channelOfftimer += timebase;
        }
    }
    return E_OK;
}

/*
 * suggest put this function into 10ms task
 *
 */
Std_ReturnType Channel_Interface_MainFunction(uint8_t timebase)
{
    E_ChannelID chid = ChannelID1;
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

void Interface_ChannelInit(void)
{
    Light_Functions lf = E_LowBeam;
    E_ChannelID chid = ChannelID1;
    for (lf = E_LowBeam; lf <= E_AssistantLight; lf++)
    {
        if (GetChannelMaskByLightFunction(lf) != 0)
        {
            gu_channelmask |= GetChannelMaskByLightFunction(lf);
        }
    }
    /*高2位清0 ，低6位保持不变*/
    gu_channelmask &= 0x3F;

    for (chid = ChannelID1; chid < MAX_CHANNLE_NUM; chid++)
    {
        if (((1 << chid) & gu_channelmask) != 0)
        {
            g_S_ChannelControl[chid].channelinfo.bits.IsChannelConfiged = 1;
            g_S_ChannelControl[chid].channelinfo.bits.IsChannelDiagEnable = 1;
            g_S_ChannelControl[chid].channel_DidConfigcurrent = 0xFFFF;
            g_S_ChannelControl[chid].channel_ParaNormalcurrent = Get_pLedNormalCurrent(chid);
            g_S_ChannelControl[chid].channelon_diag_delaytimer = 100;
            g_S_ChannelControl[chid].channeloff_diag_delaytimer = 100;
        }
        else
        {
            g_S_ChannelControl[chid].channelinfo.bits.IsChannelConfiged = 0;
            g_S_ChannelControl[chid].channelinfo.bits.IsChannelDiagEnable = 0;
        }
    }
}


void Interface_ChannelClose(E_ChannelID id)
{
    Interface_SetChannelCurrent(id, 0);
    Interface_SetChannelPWM(id, 0);
    Interface_SetChannelSwitchState(id, CHANNEL_STATE_OFF); 
}

void Interface_ChannelOpen(E_ChannelID id,uint16 cur,uint8 pwm)
{
    Interface_SetChannelCurrent(id,cur); /* set the channel current */
    Interface_SetChannelPWM(id, pwm);
    Interface_SetChannelSwitchState(id, CHANNEL_STATE_ON); 
}

void Reset_ChannelAllError(E_ChannelID id)
{
    g_S_ChannelControl[id].channel_lowvoltage_errorcnt=0;
    g_S_ChannelControl[id].channel_overvoltage_errorcnt=0;
    g_S_ChannelControl[id].channel_open_errorcnt=0;
    g_S_ChannelControl[id].channel_short2GND_errorcnt=0;
    g_S_ChannelControl[id].channel_short2VCC_errorcnt=0;
}

void Reset_ChannelLowVolError(E_ChannelID id)
{
    g_S_ChannelControl[id].channel_lowvoltage_errorcnt=0;
}

#endif /* ASW_INTERFACE_CHANNEL_INTERFACE_CHANNEL_INTERFACE_C_ */













