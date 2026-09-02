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
#include "ParaMgr.h"
#include "Rte_Dcm_Callout.h"
#include "Lighting.h"
#include "Pwm_Service.h"
#include "Dio_Service.h"
#include "WelGdy.h"
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
        .channel_DidConfigcurrent = 0xFFF,
        // .channel_DidconfigcurrentRef = DIDSIGNALNAME_ID_Ch1MaxCur,
    },
    {
        .channel_ParaNormalcurrent = INVALIED_CURRENT,
        .channel_bincurrent = INVALIED_CURRENT,
        .channel_DidConfigcurrent = 0xFFF,
        // .channel_DidconfigcurrentRef = DIDSIGNALNAME_ID_Ch2MaxCur,
    },
    {
        .channel_ParaNormalcurrent = INVALIED_CURRENT,
        .channel_bincurrent = INVALIED_CURRENT,
        .channel_DidConfigcurrent = 0xFFF,
        // .channel_DidconfigcurrentRef = DIDSIGNALNAME_ID_Ch3MaxCur,
    },
    {
        .channel_ParaNormalcurrent = INVALIED_CURRENT,
        .channel_bincurrent = INVALIED_CURRENT,
        .channel_DidConfigcurrent = 0xFFF,
        // .channel_DidconfigcurrentRef = DIDSIGNALNAME_ID_Ch4MaxCur,
    },
    {
        .channel_ParaNormalcurrent = INVALIED_CURRENT,
        .channel_bincurrent = INVALIED_CURRENT,
        .channel_DidConfigcurrent = 0xFFF,
        // .channel_DidconfigcurrentRef = DIDSIGNALNAME_ID_Ch5MaxCur,
    },
    {
        .channel_ParaNormalcurrent = INVALIED_CURRENT,
        .channel_bincurrent = INVALIED_CURRENT,
        .channel_DidConfigcurrent = 0xFFF,
        // .channel_DidconfigcurrentRef = DIDSIGNALNAME_ID_Ch6MaxCur,
    },
};
static uint8 gu_channelmask = 0;
/*通道电压有效标记位*/
static uint16_t gu_ChannelVoltageValiedFlag = 0;
U_BuckErrorState BuckErrorState[CHANNEL_NUM];
U_BuckErrorState BuckErrorState_Light[CHANNEL_NUM];
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
    ChannelVoltageDataSrc.ChannelVoltageValue = 0;
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
    ChannelDiagStateDataSrc.ChannelDiagState = (U_ChannelDiagState){0};
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
    double voltage;
    uint16 max=0,min=0xffff;

/*从buck里面获取电压，并更新到g_S_ChannelControl中*/
    UpdateChannelVoltageFromBuckDriver(id);
    if((ParaMgr_pBypassFunctionDefinition_B==1)&&(id==ChannelID1_Tap))
    {
        return E_NOT_OK; /* 如果bypass作为开关，非CH1', */
    }
    if((ParaMgr_CfgPrm_Usage_B==HWTEST_CODE)||(TRUE == Rte_Dcm_GetEolSessionStatus()))
    {       
        return E_NOT_OK; /* EOL and HardWare TEST */
    }
    if(Interface_GetDerateRatioOfOUV()==0)
    {       
        return E_NOT_OK; /* when the supply is low ,don't diag . */
    }
    if((GetLgtStsEna_WELC()!=0)||(GetLgtStsEna_GDY()!=0)||(GetLgtStsEna_Charge()!=0))
    {
        return E_NOT_OK;
    }
    if ((g_S_ChannelControl[id].channel_state == CHANNEL_STATE_ON)&&(g_S_ChannelControl[id].channel_state_set == CHANNEL_STATE_ON))
    {
        /*channel is close */
        if(g_S_ChannelControl[id].channelon_diag_delaytimer<100)
        {
            g_S_ChannelControl[id].channelon_diag_delaytimer=100;
        }
        /*channel is open */
        if (g_S_ChannelControl[id].channelontimer < g_S_ChannelControl[id].channelon_diag_delaytimer)
        {
            return E_OK;
        }
        
        /* Get 18397 register Diag data */
        rtval |= Interface_GetChannelDiagState(id, &ChannelDiagState);

        if (rtval != E_OK)
        {
            return rtval;
        }
            
        if (ChannelDiagState.Bits.OpenError == 1)
        {
            /*open error*/
            g_S_ChannelControl[id].channel_open_errorcnt = CNT_INC(g_S_ChannelControl[id].channel_open_errorcnt, STEP_1, CNT_LIMIT_50);
            g_S_ChannelControl[id].channel_short2GND_errorcnt = 0;
            g_S_ChannelControl[id].channel_lowvoltage_errorcnt = 0;
        }
        else if (ChannelDiagState.Bits.Short2Gnd == 1)
        {
            /*short error*/
            g_S_ChannelControl[id].channel_open_errorcnt = 0;
            g_S_ChannelControl[id].channel_short2GND_errorcnt = CNT_INC(g_S_ChannelControl[id].channel_short2GND_errorcnt, STEP_1, CNT_LIMIT_50);
            g_S_ChannelControl[id].channel_lowvoltage_errorcnt = 0;
        }
        else if (ChannelDiagState.Bits.Pending == 1)
        {
            /*do nothing */
        }
        else /*no error */
        {
            g_S_ChannelControl[id].channel_open_errorcnt = 0;
            g_S_ChannelControl[id].channel_short2GND_errorcnt = 0;

            channel_pwm = g_S_ChannelControl[id].channel_current_pwm;
            if(channel_pwm == 100)
            {
                /*Full pwm*/

                if ((gu_ChannelVoltageValiedFlag & (1 << id)) == 0)
                    return E_NOT_OK; /*the first val no use*/

                voltage = g_S_ChannelControl[id].Channel_CurVoltage;

                if((g_S_ChannelControl[ChannelID1_Tap].channel_state == CHANNEL_STATE_ON)&&((ParaMgr_High_Beam_Sail_W&0x02)!=0)&&( id==ChannelID1 ))
                {/* 如果CH1_Tap配位远光，且处于开的状态，通道1过欠压阈值用CH1_Tap */
                    max=Get_pLedUmaxVoltage(ChannelID1_Tap);
                    min=Get_pLedUminVoltage(ChannelID1);
                }
                else if((g_S_ChannelControl[ChannelID1_Tap].channel_state == CHANNEL_STATE_ON)&&((ParaMgr_High_Beam_Sail_W&0x02)!=0)&&( id==ChannelID1_Tap))
                {/* 如果CH1_Tap配位远光，且处于开的状态，通道1过欠压阈值用CH1_Tap */
                    max=Get_pLedUmaxVoltage(ChannelID1_Tap);
                    min=Get_pLedUminVoltage(ChannelID1_Tap);
                }
                else
                {
                    max=Get_pLedUmaxVoltage(id);
                    min=Get_pLedUminVoltage(id);
                }
                if (min > ((uint16_t)(voltage * 10)))
                {
                    g_S_ChannelControl[id].channel_lowvoltage_errorcnt = CNT_INC(g_S_ChannelControl[id].channel_lowvoltage_errorcnt, STEP_1, CNT_LIMIT_50);
                    g_S_ChannelControl[id].channel_overvoltage_errorcnt = 0;
                }
                else if (min < ((uint16_t)(voltage * 10) - 10)) /*HCM_SRS_2_0004*/
                {
                    g_S_ChannelControl[id].channel_lowvoltage_errorcnt = 0;
                    if (max < ((uint16_t)(voltage * 10)))
                    {
                        g_S_ChannelControl[id].channel_overvoltage_errorcnt = CNT_INC(g_S_ChannelControl[id].channel_overvoltage_errorcnt, STEP_1, CNT_LIMIT_50);
                    }
                    else
                    {
                        g_S_ChannelControl[id].channel_overvoltage_errorcnt = 0;
                    }
                }
            }
        }
        if (g_S_ChannelControl[id].channel_open_errorcnt >= CNT_LIMIT_50)
        {
            BuckErrorState[id].bits.OpenError=1;
            BuckErrorState_Light[id].bits.OpenError=BuckErrorState[id].bits.OpenError;
            Interface_SetD900Data( Channel1_OL+id*4 , STATE_ERROR);
        }
        else 
        {
            BuckErrorState_Light[id].bits.OpenError=0;
            if (g_S_ChannelControl[id].channel_open_errorcnt == 0 )
            {
                BuckErrorState[id].bits.OpenError=0;
                Interface_SetD900Data( Channel1_OL+id*4 , STATE_OK);
            }
        }

        if (g_S_ChannelControl[id].channel_short2GND_errorcnt >= CNT_LIMIT_50)
        {
            BuckErrorState[id].bits.Short2GndError=1;
            BuckErrorState_Light[id].bits.Short2GndError=BuckErrorState[id].bits.Short2GndError;
            Interface_SetD900Data( Channel1_SCG+id*4 , STATE_ERROR);
        }
        else 
        {
            BuckErrorState_Light[id].bits.Short2GndError=0;
            if (g_S_ChannelControl[id].channel_short2GND_errorcnt == 0)
            {
                BuckErrorState[id].bits.Short2GndError=0;
                Interface_SetD900Data( Channel1_SCG+id*4 , STATE_OK);
            }
        }

        if (g_S_ChannelControl[id].channel_lowvoltage_errorcnt >= CNT_LIMIT_50) 
        {
            BuckErrorState_Light[id].bits.UnderVoltage=BuckErrorState[id].bits.UnderVoltage;
            BuckErrorState[id].bits.UnderVoltage=1;
            Interface_SetD900Data(Channel1_UV+id*4 , STATE_ERROR);
        }
        else 
        {
            BuckErrorState_Light[id].bits.UnderVoltage=0;
            if (g_S_ChannelControl[id].channel_lowvoltage_errorcnt == 0)
            {
                BuckErrorState[id].bits.UnderVoltage=0;
                Interface_SetD900Data(Channel1_UV+id*4 , STATE_OK);
            }
        }

        if (g_S_ChannelControl[id].channel_overvoltage_errorcnt >= CNT_LIMIT_50)
        {
            BuckErrorState_Light[id].bits.OverVol=BuckErrorState[id].bits.OverVol;
            BuckErrorState[id].bits.OverVol=1;
        }
        else 
        {
            BuckErrorState_Light[id].bits.OverVol=0;
            if (g_S_ChannelControl[id].channel_overvoltage_errorcnt == 0)
            {
                BuckErrorState[id].bits.OverVol=0;
            }
        }
    }
    else if((g_S_ChannelControl[id].channel_state == CHANNEL_STATE_OFF)&&((g_S_ChannelControl[id].channel_state_set == CHANNEL_STATE_OFF)))
    {
        /*channel is close */
        if(g_S_ChannelControl[id].channeloff_diag_delaytimer<CHANNELOFFMINTIME)
        {
            g_S_ChannelControl[id].channeloff_diag_delaytimer=CHANNELOFFMINTIME;
        }
        if (g_S_ChannelControl[id].channelOfftimer < g_S_ChannelControl[id].channeloff_diag_delaytimer)
        {
            return E_OK;
        }
/*if channelid2 on,don't check channelid2_alt short to vcc*/
        if((id==ChannelID2)&&(g_S_ChannelControl[ChannelID2_Alt].channelontimer>0))
        {
            g_S_ChannelControl[ChannelID2].channel_short2VCC_errorcnt=0;
        }
        else if((id==ChannelID2_Alt)&&(g_S_ChannelControl[ChannelID2].channelontimer>0))
        {
            g_S_ChannelControl[ChannelID2_Alt].channel_short2VCC_errorcnt=0;
        }

        if ((gu_ChannelVoltageValiedFlag & (1 << id)) == 0)
            return E_NOT_OK; /*首次电压数据暂未获取到*/

        voltage = g_S_ChannelControl[id].Channel_CurVoltage;

        if (voltage > CHANNEL_SHORT2VCC_VOLTAGE_LIMIT)
        {
            if((id==ChannelID1_Tap)&&(g_S_ChannelControl[ChannelID1].channel_state==CHANNEL_STATE_ON))
            {
                g_S_ChannelControl[id].channel_short2VCC_errorcnt = 0;
            }
            else
            {
                g_S_ChannelControl[id].channel_short2VCC_errorcnt = CNT_INC(g_S_ChannelControl[id].channel_short2VCC_errorcnt, STEP_1, CNT_LIMIT_50);
            }
        }
        else if (voltage < (CHANNEL_SHORT2VCC_VOLTAGE_LIMIT - SHORT2BATTARY_VOLATGE_HYSTERESIS)) /*HCM_SRS_2_0006*/
        {
            g_S_ChannelControl[id].channel_short2VCC_errorcnt = CNT_DEC(g_S_ChannelControl[id].channel_short2VCC_errorcnt, STEP_1, DEC_LIMIT_0);
        }
        if (g_S_ChannelControl[id].channel_short2VCC_errorcnt >= CNT_LIMIT_50)
        {
            BuckErrorState_Light[id].bits.Short2VCC=BuckErrorState[id].bits.Short2VCC;
            BuckErrorState[id].bits.Short2VCC=1;
            Interface_SetD900Data( Channel1_SCB+id*4 , STATE_ERROR);
        }
        else 
        {
            BuckErrorState_Light[id].bits.Short2VCC=0;
            if (g_S_ChannelControl[id].channel_short2VCC_errorcnt == 0)
            {
                BuckErrorState[id].bits.Short2VCC=0;
                Interface_SetD900Data( Channel1_SCB+id*4 , STATE_OK);
            }
        }
    }
    return rtval;
}

uint8 Interface_GetChannelState(E_ChannelID id)
{
    return BuckErrorState[id].Error;
}
/* 灯光获取BUCK cc状态 */
uint8 Interface_GetChannelState_Light(E_ChannelID id)
{
    return BuckErrorState_Light[id].Error;
}

/* 灯光清除BUCK cc状态 */
void Interface_ClearChannelState_Light(E_ChannelID id)
{
    BuckErrorState_Light[id].Error=0;
}


void Interface_ClearChannelState(void)
{
    for (uint8 i = 0; i < CHANNEL_NUM; i++)
    {
        BuckErrorState[i].Error = 0;
    }      
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
    
    if(id==ChannelID1_Tap)/* CH1'只通过IO口控制 ；CH1 控制BUCK打开 */
    {
        g_S_ChannelControl[id].channel_current_cur = current;
        return E_NOT_OK;
    }
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

    if(id==ChannelID1_Tap)/* CH1'只通过IO口控制 ；CH1 控制BUCK打开 */
    {
        g_S_ChannelControl[id].channel_current_pwm = pwm;
        return E_NOT_OK;
    }

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
    /*复位标记置起来以后，通道不能打开*/
    if (ASWInterface_GetEcuResetFlag() == 1)
    {
        if (g_S_ChannelControl[id].channel_state == CHANNEL_STATE_ON)
        {
            return E_NOT_OK;
        }
    }
    if(id==ChannelID1_Tap)/* CH1'只通过IO口控制 ；CH1 控制BUCK打开 */
    {
        g_S_ChannelControl[id].channel_state = channelstate;
        return E_NOT_OK;
    }
    if ((g_S_ChannelControl[id].channel_state != channelstate)||( g_S_ChannelControl[id].channel_current_prepwm!=g_S_ChannelControl[id].channel_current_pwm))
    {
        if (channelstate == CHANNEL_STATE_ON)
        {
            g_S_ChannelControl[id].channelOfftimer = 0;
        }
        else
        {
            g_S_ChannelControl[id].channelontimer = 0;
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
    }
    g_S_ChannelControl[id].channel_current_prepwm=g_S_ChannelControl[id].channel_current_pwm;
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
    ChannelFrequencyDataSrc.ChannelFrequency = 0;
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
    uint16 current=0;
    if(g_S_ChannelControl[id].channel_state == CHANNEL_STATE_ON)
    {
        current=g_S_ChannelControl[id].channel_current_cur;
    }
    return current;
}
/*
 *获得通道的当前占空比
 *返回值0-100 表示0%-100%
 */
uint8_t Interface_GetChannelCurPWM(E_ChannelID id)
{
    uint8 pwm=0;
    if(g_S_ChannelControl[id].channel_state == CHANNEL_STATE_ON)
    {
        pwm=g_S_ChannelControl[id].channel_current_pwm;
    }
    return pwm;
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
        {
            continue;
        }

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
    uint8 DID_Circuit_OutOfRange=0;/* 437C电流值超范围 100~1500mA */
    for (lf = E_LowBeam; lf <= E_ADSLight; lf++)
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
            g_S_ChannelControl[chid].channel_current_cur=1666;/* ISET[0-9]=901 : (901/1024*2.5-0.2)*1000/(12*R)*/
            g_S_ChannelControl[chid].channel_current_pwm=100; 
            g_S_ChannelControl[chid].channel_state =CHANNEL_STATE_OFF;
            g_S_ChannelControl[chid].channelinfo.bits.IsChannelConfiged = 1;
            g_S_ChannelControl[chid].channelinfo.bits.IsChannelDiagEnable = 1;
            g_S_ChannelControl[chid].channel_DidConfigcurrent = Get_DidConfigCurrent(chid) &0xfff;
            if((g_S_ChannelControl[chid].channel_DidConfigcurrent<100)||((g_S_ChannelControl[chid].channel_DidConfigcurrent>1500)&&(g_S_ChannelControl[chid].channel_DidConfigcurrent!=0xFFF)))
            {
                g_S_ChannelControl[chid].channel_DidConfigcurrent=0xFFF;
                DID_Circuit_OutOfRange=1;
            }
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
/* high beam current > low beam current */
    if((g_S_ChannelControl[ChannelID1_Tap].channel_DidConfigcurrent!=0xfff)&&(g_S_ChannelControl[ChannelID1].channel_DidConfigcurrent!=0xfff))
    {
        if(g_S_ChannelControl[ChannelID1_Tap].channel_DidConfigcurrent>g_S_ChannelControl[ChannelID1].channel_DidConfigcurrent) 
        {
            DID_Circuit_OutOfRange=1;
            g_S_ChannelControl[ChannelID1_Tap].channel_DidConfigcurrent=0xfff;
            g_S_ChannelControl[ChannelID1].channel_DidConfigcurrent=0xfff;
        }
    }
    if(DID_Circuit_OutOfRange==1)
    {
        Interface_SetD900Data(CC_OverRange , STATE_ERROR);
    }
    else
    {
        Interface_SetD900Data(CC_OverRange , STATE_OK);
    }
}

void Interface_ChannelClose(E_ChannelID id)
{
    g_S_ChannelControl[id].channel_state_set=CHANNEL_STATE_OFF;
    g_S_ChannelControl[id].channel_current_pwm_set=0;
    Interface_SetLightChannelStateSwitch(id,STS_OFF);
    if((id==ChannelID1)&&(g_S_ChannelControl[id].channel_current_cur==0))
    {
        g_S_ChannelControl[id].channel_current_cur_set=Interface_GetSignal_ChannelCurrent(id); 
    }
}

void Interface_ChannelOpen(E_ChannelID id,uint16 cur,uint8 pwm)
{
    if((cur==0)||(pwm==0))
    {
        g_S_ChannelControl[id].channel_state_set=CHANNEL_STATE_OFF;
        g_S_ChannelControl[id].channel_current_pwm_set=0;
        Interface_SetLightChannelStateSwitch(id,STS_OFF);
    }
    else
    {
        g_S_ChannelControl[id].channel_state_set=CHANNEL_STATE_ON;
        g_S_ChannelControl[id].channel_current_cur_set=cur;
        g_S_ChannelControl[id].channel_current_pwm_set=pwm;
        if(Interface_GetLightChannelStateSwitch(id)!=STS_ERR)
        {
            Interface_SetLightChannelStateSwitch(id,STS_ON);
        }
    }
}
void Interface_SetAllChannelOutPut(void)
{
    E_ChannelID id=0;
    E_ChannelState state_set;
    uint16_t current_set;
    uint8_t pwm_set;
    uint8 ChannelSettingFlag=0;
    uint8 CH1ByPwm=0;
    for(id=0;id<6;id++)
    {
        ChannelSettingFlag=1;/* 对通道进行写 */
        if((ParaMgr_pBypassFunctionDefinition_B==1)&&(id==ChannelID1_Tap))/* 作为开关打开bypass */
        {
            if((GetLgtStsEna_WELC()!=0)||(GetLgtStsEna_GDY()!=0))/* 开欢迎欢送，按动态的灯光输出 */
            {
                pwm_set=Interface_GetChannelID1_Tap_Pwm();
            }
            else if(GetLgtStsEna_Charge()==1)/* 开动态位置灯；100%输出 */
            {
                pwm_set=100;
            }
            else
            {
                if((g_S_ChannelControl[ChannelID1_Tap].channel_state_set==CHANNEL_STATE_OFF))
                {
                    pwm_set=0;
                }
                else
                {
                    pwm_set=100;
                }
            }
            ByPass_PwmSetting(pwm_set);
        }
        else
        {
            if((ParaMgr_pBypassFunctionDefinition_B==0)&&((ParaMgr_High_Beam_Sail_W&0x02)!=0)&&((id==ChannelID1)||(id==ChannelID1_Tap)))/* bypass作为远光通道需要打开CH1 */
            {
                /* CH1开 CH1'关的时候HLCtrl 关闭远光输出，其他情况把IO口设置为打开模式（硬件 2025.4.16）*/
                if(((g_S_ChannelControl[ChannelID1_Tap].channel_state_set==CHANNEL_STATE_OFF))&&((g_S_ChannelControl[ChannelID1].channel_state_set==CHANNEL_STATE_ON)))
                {
                    ByPass_PwmSetting(0);
                }
                else if(((g_S_ChannelControl[ChannelID1_Tap].channel_state_set==CHANNEL_STATE_ON))&&((g_S_ChannelControl[ChannelID1].channel_state_set==CHANNEL_STATE_ON)))
                {
                    if((GetLgtStsEna_WELC()!=0)||(GetLgtStsEna_GDY()!=0))/* 开欢迎欢送，按动态的灯光输出 */
                    {
                        if(g_S_ChannelControl[ChannelID1_Tap].channel_current_cur_set>0)
                        {
                            CH1ByPwm=g_S_ChannelControl[ChannelID1_Tap].channel_current_cur_set*100/g_S_ChannelControl[ChannelID1].channel_current_cur_set;/*from actruc : CH1' current÷CH1 current */
                            ByPass_PwmSetting(CH1ByPwm);
                        }
                    }
                    else
                    {
                        CH1ByPwm=Get_pLedNormalCurrent(ChannelID1_Tap)*100/Get_pLedNormalCurrent(ChannelID1);/*from paramgr.c : CH1' current÷CH1 current */
                        ByPass_PwmSetting(CH1ByPwm);
                    }
                }
                else
                {
                    ByPass_PwmSetting(100);/* hardware request */
                }
                current_set=g_S_ChannelControl[id].channel_current_cur_set;
                pwm_set=g_S_ChannelControl[id].channel_current_pwm_set;
                state_set=g_S_ChannelControl[id].channel_state_set;/* 有一通道开则BUCK CH1打开 */
            }
            else if((id==ChannelID2)||(id==ChannelID2_Alt))
            {
                if(g_S_ChannelControl[ChannelID2_Alt].channel_state_set==CHANNEL_STATE_ON)
                {
                    if((id==ChannelID2_Alt)&&(g_S_ChannelControl[ChannelID2].channel_state==CHANNEL_STATE_OFF))
                    {
                        current_set=g_S_ChannelControl[ChannelID2_Alt].channel_current_cur_set;
                        pwm_set=g_S_ChannelControl[ChannelID2_Alt].channel_current_pwm_set;
                        state_set=g_S_ChannelControl[ChannelID2_Alt].channel_state_set;
                    }
                    else if(id==ChannelID2)
                    {
                        if(g_S_ChannelControl[ChannelID2].channel_state==CHANNEL_STATE_ON)
                        {
                            current_set=0;
                            pwm_set=0;
                            state_set=0;
                        }
                        else
                        {
                            ChannelSettingFlag=0;
                        }
                    }
                }
                else if(g_S_ChannelControl[ChannelID2].channel_state_set!=0)
                {
                    if((id==ChannelID2)&&(g_S_ChannelControl[ChannelID2_Alt].channel_state==CHANNEL_STATE_OFF))
                    {
                        current_set=g_S_ChannelControl[ChannelID2].channel_current_cur_set;
                        pwm_set=g_S_ChannelControl[ChannelID2].channel_current_pwm_set;
                        state_set=g_S_ChannelControl[ChannelID2].channel_state_set;
                    }
                    else if(id==ChannelID2_Alt)
                    {
                        if(g_S_ChannelControl[ChannelID2_Alt].channel_state==CHANNEL_STATE_ON)
                        {
                            current_set=0;
                            pwm_set=0;
                            state_set=0;
                        }
                        else
                        {
                            ChannelSettingFlag=0;
                        }
                    }
                }
                else
                {
                    current_set=0;
                    pwm_set=0;
                    state_set=0;
                }
            }
            else
            {
                current_set=g_S_ChannelControl[id].channel_current_cur_set;
                pwm_set=g_S_ChannelControl[id].channel_current_pwm_set;
                state_set=g_S_ChannelControl[id].channel_state_set;
            }
            if(ChannelSettingFlag==1)
            {
                Interface_SetChannelCurrent(id,current_set); /* set the channel current */
                Interface_SetChannelPWM(id, pwm_set);
                Interface_SetChannelSwitchState(id, state_set); 
            }
            if((state_set == CHANNEL_STATE_OFF)&&(g_S_ChannelControl[id].channelOfftimer >1000))
            {
                Interface_ClearChannelState_Light(id);
            }
/* 设置日行位置转向IO口 */
            if(g_S_ChannelControl[ChannelID2_Alt].channel_state ==CHANNEL_STATE_ON)
            {
                Port_CH2_Disable();
                Port_CH2Alt_Enable();
            }
            else if(g_S_ChannelControl[ChannelID2].channel_state ==CHANNEL_STATE_ON)
            {
                Port_CH2_Enable();
                Port_CH2Alt_Disable();
            }
            else 
            {
                Port_CH2_Disable();
                Port_CH2Alt_Disable();
            }
        }
    }
}

uint32_t Interface_GetChannelOnTime(E_ChannelID id)
{
    return g_S_ChannelControl[id].channelontimer;
}

void Reset_ChannelAllError(E_ChannelID id)
{
    g_S_ChannelControl[id].channel_lowvoltage_errorcnt=0;
    g_S_ChannelControl[id].channel_overvoltage_errorcnt=0;
    g_S_ChannelControl[id].channel_open_errorcnt=0;
    g_S_ChannelControl[id].channel_short2GND_errorcnt=0;
    // g_S_ChannelControl[id].channel_short2VCC_errorcnt=0;
}

void Reset_ChannelLowVolError(E_ChannelID id)
{
    g_S_ChannelControl[id].channel_lowvoltage_errorcnt=0;
}

void Interface_SetAllChannelClose(void)
{
    E_ChannelID id=ChannelID1;
    for (id = 0; id < MAX_CHANNLE_NUM; id++)
    {
        Interface_SetChannelSwitchState((E_ChannelID)id, CHANNEL_STATE_OFF);
        Interface_SetChannelPWM((E_ChannelID)id, 0);
        Interface_SetChannelCurrent((E_ChannelID)id, 0);
    }
}
#endif /* ASW_INTERFACE_CHANNEL_INTERFACE_CHANNEL_INTERFACE_C_ */













