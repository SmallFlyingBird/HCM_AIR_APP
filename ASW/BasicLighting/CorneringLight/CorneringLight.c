/********************************
 * CorneringLight.c
 *
 *  Created on: 2024/4/15
 *      Author: tujiongjiong
 ********************************/


/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "CorneringLight.h"

/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Global Variable Define                     *
 *                                                              *
 ****************************************************************/
static S_CorneringLightConfigInfo gs_CorneringLightConfigInfo;

static S_CorneringLightRunInfo gs_CorneringLightRunInfo =
{
    .Pwm_Fog        = 0,
    .Pwm_DBL        = 0,
    .Pwm_AFS        = 0,
    .Pwm_Self       = 0,
    .Pwm_Target     = 0,
    .Pwm_LastTarget = 0,
    .ChannelMask    = 0,
    .Ownership      = E_CorneringLightOwnership_Self,
    .RunState       = E_CorneringLightState_Run,
    .TacticN_1      = 0,
    .OnRampTime     = 0,
    .OffRampTime    = 0,
    .OnDelayTime    = 0,
    .OffDelayTime   = 0
};

static S_CorneringLightDidInfo gs_CorneringLightDidInfo = { .CorneringLightStatus = CorneringLightStatus_Res };

/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/

/* 读取角灯参数配置并存放 */
static Std_ReturnType CorneringLight_GetParameterIntoInfo(void)
{
    Std_ReturnType rtval = E_OK;

    gs_CorneringLightConfigInfo.CLChannelMask = GetChannelMaskByLightFunction(E_CorneringLight) & 0xFFF;
    gs_CorneringLightConfigInfo.FLChannelMask = GetChannelMaskByLightFunction(E_FogLamp) & 0xFFF;
    gs_CorneringLightConfigInfo.LedGamma = (E_LedGamma)Get_pLedGamma();

    gs_CorneringLightConfigInfo.SelfIntensityDuty = Get_pLedIntensConerLDuty();
    switch( gs_CorneringLightConfigInfo.LedGamma )
    {
        case E_LedGamma_Step:
            gs_CorneringLightConfigInfo.SelfOnRampTime  = 0;
            gs_CorneringLightConfigInfo.SelfOffRampTime = 0;
            gs_CorneringLightConfigInfo.FogOnRampTime   = 0;
            gs_CorneringLightConfigInfo.FogOffRampTime  = 0;
            break;

        case E_LedGamma_Linear:
        case E_LedGamma_Exponent:
            gs_CorneringLightConfigInfo.SelfOnRampTime  = Get_pLedOnRampTi(E_CorneringLight);
            gs_CorneringLightConfigInfo.SelfOffRampTime = Get_pLedOffRampTi(E_CorneringLight);
            gs_CorneringLightConfigInfo.FogOnRampTime   = Get_pLedOnRampTi(E_FogLamp);
            gs_CorneringLightConfigInfo.FogOffRampTime  = Get_pLedOffRampTi(E_FogLamp);
    }
    
    gs_CorneringLightConfigInfo.SelfOnDelayTime  = Get_pLedONDelay(E_CorneringLight);
    gs_CorneringLightConfigInfo.SelfOffDelayTime = Get_pLedOFFDelay(E_CorneringLight);
    gs_CorneringLightConfigInfo.FogOnDelayTime   = Get_pLedONDelay(E_FogLamp);
    gs_CorneringLightConfigInfo.FogOffDelayTime  = Get_pLedOFFDelay(E_FogLamp);

    return rtval;
}

/* 角灯硬件归属权仲裁 */
static Std_ReturnType CorneringLight_Ownership(void)
{
    Std_ReturnType rtval = E_OK;

    if(gs_CorneringLightConfigInfo.CLChannelMask == gs_CorneringLightConfigInfo.FLChannelMask) /* 角灯雾灯完全共用通道 */
    {
        static uint8_t CorneringLight_ActStaCurr = 0;
        static uint8_t CorneringLight_ActStaLast = 0;
        static uint8_t FogLamp_ActStaCurr = 0;
        static uint8_t FogLamp_ActStaLast = 0;

        CorneringLight_ActStaLast = CorneringLight_ActStaCurr;
        FogLamp_ActStaLast = FogLamp_ActStaCurr;

        if( gs_CorneringLightRunInfo.Pwm_DBL > 0 ||
            gs_CorneringLightRunInfo.Pwm_AFS > 0 ||
            gs_CorneringLightRunInfo.Pwm_Self > 0)
        {
            CorneringLight_ActStaCurr = 1;
        }
        else
        {
            CorneringLight_ActStaCurr = 0;
        }
        if(gs_CorneringLightRunInfo.Pwm_Fog > 0)
        {
            FogLamp_ActStaCurr = 1;
        }
        else
        {
            FogLamp_ActStaCurr = 0;
        }

        if(CorneringLight_ActStaCurr == 1 && FogLamp_ActStaCurr == 1)
        {
            gs_CorneringLightRunInfo.Ownership = E_CorneringLightOwnership_Fog;
        }
        else if(CorneringLight_ActStaCurr == 1 && FogLamp_ActStaCurr == 0)
        {
            gs_CorneringLightRunInfo.Ownership = E_CorneringLightOwnership_Self;
        }
        else if(CorneringLight_ActStaCurr == 0 && FogLamp_ActStaCurr == 1)
        {
            gs_CorneringLightRunInfo.Ownership = E_CorneringLightOwnership_Fog;
        }
        else if(CorneringLight_ActStaCurr == 0 && FogLamp_ActStaCurr == 0)
        {
            if(CorneringLight_ActStaLast == 1 && FogLamp_ActStaLast == 1)
            {
                gs_CorneringLightRunInfo.Ownership = E_CorneringLightOwnership_Fog;
            }
            else if(CorneringLight_ActStaLast == 1 && FogLamp_ActStaLast == 0)
            {
                gs_CorneringLightRunInfo.Ownership = E_CorneringLightOwnership_Self;
            }
            else if(CorneringLight_ActStaLast == 0 && FogLamp_ActStaLast == 1)
            {
                gs_CorneringLightRunInfo.Ownership = E_CorneringLightOwnership_Fog;
            }
        }
    }
    else /* 角灯雾灯不共用通道 */
    {
        gs_CorneringLightRunInfo.Ownership = E_CorneringLightOwnership_Self;
    }

    if(gs_CorneringLightRunInfo.Ownership == E_CorneringLightOwnership_Self)
    {
        gs_CorneringLightRunInfo.TacticN_1    = Get_LightN_1() & 0x0080;
        gs_CorneringLightRunInfo.OnRampTime   = gs_CorneringLightConfigInfo.SelfOnRampTime;
        gs_CorneringLightRunInfo.OffRampTime  = gs_CorneringLightConfigInfo.SelfOffRampTime;
        gs_CorneringLightRunInfo.OnDelayTime  = gs_CorneringLightConfigInfo.SelfOnDelayTime;
        gs_CorneringLightRunInfo.OffDelayTime = gs_CorneringLightConfigInfo.SelfOffDelayTime;
    }
    else if(gs_CorneringLightRunInfo.Ownership == E_CorneringLightOwnership_Fog)
    {
        gs_CorneringLightRunInfo.TacticN_1    = Get_LightN_1() & 0x0100;
        gs_CorneringLightRunInfo.OnRampTime   = gs_CorneringLightConfigInfo.FogOnRampTime;
        gs_CorneringLightRunInfo.OffRampTime  = gs_CorneringLightConfigInfo.FogOffRampTime;
        gs_CorneringLightRunInfo.OnDelayTime  = gs_CorneringLightConfigInfo.FogOnDelayTime;
        gs_CorneringLightRunInfo.OffDelayTime = gs_CorneringLightConfigInfo.FogOffDelayTime;
    }
    return rtval;
}

/* 角灯运行 */
static Std_ReturnType CorneringLight_Run(uint8_t timebase)
{
    Std_ReturnType rtval = E_OK;

    CorneringLight_Ownership();

    /* 开灯仲裁 */
    gs_CorneringLightRunInfo.Pwm_LastTarget = gs_CorneringLightRunInfo.Pwm_Target;
    if(gs_CorneringLightRunInfo.Pwm_Fog > 0)
    {
        gs_CorneringLightRunInfo.Pwm_Target = gs_CorneringLightRunInfo.Pwm_Fog;
    }
    else if(gs_CorneringLightRunInfo.Pwm_DBL > 0)
    {
        gs_CorneringLightRunInfo.Pwm_Target = gs_CorneringLightRunInfo.Pwm_DBL;
    }
    else if(gs_CorneringLightRunInfo.Pwm_AFS > 0)
    {
        gs_CorneringLightRunInfo.Pwm_Target = gs_CorneringLightRunInfo.Pwm_AFS;
    }
    else if(gs_CorneringLightRunInfo.Pwm_Self > 0)
    {
        gs_CorneringLightRunInfo.Pwm_Target = gs_CorneringLightRunInfo.Pwm_Self;
    }
    else
    {
        gs_CorneringLightRunInfo.Pwm_Target = 0;
    }

    /* 判断是否是开关灯前 */
    if(gs_CorneringLightRunInfo.Pwm_LastTarget != gs_CorneringLightRunInfo.Pwm_Target)
    {
        if(gs_CorneringLightRunInfo.Pwm_LastTarget == 0 && gs_CorneringLightRunInfo.Pwm_Target > 0)
        {
            gs_CorneringLightRunInfo.ChannelMask = gs_CorneringLightConfigInfo.CLChannelMask;
            gs_CorneringLightRunInfo.RunState = E_CorneringLightState_OnDelay;
        }
        else if(gs_CorneringLightRunInfo.Pwm_LastTarget > 0 && gs_CorneringLightRunInfo.Pwm_Target == 0)
        {
            gs_CorneringLightRunInfo.RunState = E_CorneringLightState_OffDelay;
        }
    }

    /* 排除故障的LED通道 */
    if(gs_CorneringLightRunInfo.Pwm_Target)
    {
        U_DisSrc_t CorneringLightDerateSta;

        GetLgtFuncDisSrc_CORN(& CorneringLightDerateSta); /* 降额状态 */
        if( CorneringLightDerateSta.bits.sp_los == 1u ||
            CorneringLightDerateSta.bits.sp_ouv == 1u ||
            CorneringLightDerateSta.bits.ot_chn == 1u ||
            CorneringLightDerateSta.bits.ot_led == 1u ||
            CorneringLightDerateSta.bits.ot_amb == 1u ) /* 角灯开启降额 */
        {
            LampM_SetLampChn(E_CorneringLight, gs_CorneringLightRunInfo.ChannelMask, 0, 0, 0); /* 立即关闭所有LED通道并返回 */
            return rtval;
        }
        else /* 角灯没有降额 */
        {
            uint16_t ErrorChannelMask = 0u;
            S_LF_Err_T DTCErrMask;

            LampM_GetLampBaseErr_DTC(& DTCErrMask); /* LED通道DTC故障 */
            ErrorChannelMask = gs_CorneringLightRunInfo.ChannelMask & DTCErrMask.chnErr; /* 剩余LED通道出现了新故障 */
            if(gs_CorneringLightRunInfo.TacticN_1) /* 有N-1策略 */
            {
                if(ErrorChannelMask)
                {
                    ErrorChannelMask = gs_CorneringLightRunInfo.ChannelMask;
                }
            }
            gs_CorneringLightRunInfo.ChannelMask ^= ErrorChannelMask; /* 逐步屏蔽故障的LED通道 */
            LampM_SetLampChn(E_CorneringLight, ErrorChannelMask, 0, 0, 0); /* 立即关闭无矩阵故障LED通道，关闭后下一次就读不到该故障 */
        }
    }

    static uint8_t CorneringLight_OnDelayTime = 0;
    static uint8_t CorneringLight_OffDelayTime = 0;

    switch( gs_CorneringLightRunInfo.RunState )
    {
        case E_CorneringLightState_OnDelay:
            CorneringLight_OnDelayTime += timebase;
            if(CorneringLight_OnDelayTime >= gs_CorneringLightRunInfo.OnDelayTime)
            {
                CorneringLight_OnDelayTime = 0;
                gs_CorneringLightRunInfo.RunState = E_CorneringLightState_Run;
            }
            break;

        case E_CorneringLightState_OffDelay:
            CorneringLight_OffDelayTime += timebase;
            if(CorneringLight_OffDelayTime >= gs_CorneringLightRunInfo.OffDelayTime)
            {
                CorneringLight_OffDelayTime = 0;
                gs_CorneringLightRunInfo.RunState = E_CorneringLightState_Run;
            }
            break;

        case E_CorneringLightState_Run:
            LampM_SetLampChn(E_CorneringLight, gs_CorneringLightRunInfo.ChannelMask, gs_CorneringLightRunInfo.Pwm_Target, gs_CorneringLightRunInfo.OnRampTime, gs_CorneringLightRunInfo.OffRampTime);
    }
    return rtval;
}

/* 打开角灯 */
static Std_ReturnType CorneringLight_SwitchON(void)
{
    Std_ReturnType rtval = E_OK;

    gs_CorneringLightRunInfo.Pwm_Self = 100 * gs_CorneringLightConfigInfo.SelfIntensityDuty / 100;
    return rtval;
}

/* 关闭角灯 */
static Std_ReturnType CorneringLight_SwitchOFF(void)
{
    Std_ReturnType rtval = E_OK;

    gs_CorneringLightRunInfo.Pwm_Self = 0;
    return rtval;
}


/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
/* 设置角灯的DID数据，4368 */
Std_ReturnType CorneringLight_SetDID_4368_CorneringLightStatus(void)
{
    Std_ReturnType rtval = E_OK;

    rtval |= Interface_SetDidSignalData(DIDSIGNALNAME_ID_StsOfCorner, (uint32_t)gs_CorneringLightDidInfo.CorneringLightStatus);

    return rtval;
}

/* 角灯AFS设置PWM */
void CorneringLight_SetPwmOfAFS(uint8_t PwmValue)
{
    gs_CorneringLightRunInfo.Pwm_AFS = PwmValue * gs_CorneringLightConfigInfo.SelfIntensityDuty / 100;
}

/* 角灯DBL设置PWM */
void CorneringLight_SetPwmOfDBL(uint8_t PwmValue)
{
    gs_CorneringLightRunInfo.Pwm_DBL = PwmValue * gs_CorneringLightConfigInfo.SelfIntensityDuty / 100;
}

/* 角灯Fog设置PWM */
void CorneringLight_SetPwmOfFog(uint8_t PwmValue)
{
    gs_CorneringLightRunInfo.Pwm_Fog = PwmValue;
}

/* 获取角灯实时故障状态 */
/* 返回值： 0：无故障； 1：有故障 */
uint8_t CorneringLight_GetCLRealTimeErrSta(void)
{
    if(gs_CorneringLightDidInfo.CorneringLightStatus == CorneringLightStatus_Error)
    {
        return 1u;
    }
    else
    {
        return 0u;
    }
}

/* 角灯启动初始化 */
void CorneringLight_Init(void)
{
    CorneringLight_GetParameterIntoInfo();
}

/* 角灯主函数 */
void CorneringLight_MainFunction(uint8_t timebase)
{
    if(gs_CorneringLightConfigInfo.CLChannelMask == 0) /* 没有该灯光配置，直接退出 */
    {
        return;
    }

    static uint8_t ActnOfLedCornrgLamp_Curr = 0;
    static uint8_t ActnOfLedCornrgLamp_Last = 0;

    S_LgtActIns_t LgtActIns;
    GetLgtActIns(& LgtActIns);

    ActnOfLedCornrgLamp_Last = ActnOfLedCornrgLamp_Curr;
    ActnOfLedCornrgLamp_Curr = LgtActIns.ActCORN;

    if(ActnOfLedCornrgLamp_Curr)
    {
        CorneringLight_SwitchON();
    }
    else
    {
        CorneringLight_SwitchOFF();
    }

    CorneringLight_Run(timebase);

    if(gs_CorneringLightRunInfo.Ownership == E_CorneringLightOwnership_Self) /* 角灯本身获得硬件归属权 */
    {
        static uint16 CorneringLightInfo_OnRampTime = 0;
        static uint16 CorneringLightInfo_OffRampTime = 0;

        if(ActnOfLedCornrgLamp_Curr != ActnOfLedCornrgLamp_Last) /* 开关激活信号转换时间节点 */
        {
            CorneringLightInfo_OnRampTime = 0;
            CorneringLightInfo_OffRampTime = 0;
        }
        else if(ActnOfLedCornrgLamp_Curr == 1 && ActnOfLedCornrgLamp_Last == 1) /* 开灯信号保持阶段 */
        {
            if(CorneringLightInfo_OnRampTime < gs_CorneringLightConfigInfo.SelfOnRampTime)
            {
                CorneringLightInfo_OnRampTime += timebase;
            }
            else
            {
                S_LF_Err_T RealTimeErrMask;
                U_DisSrc_t CorneringLightDerateSta;

                LampM_GetLampBaseErr(& RealTimeErrMask);
                GetLgtFuncDisSrc_CORN(& CorneringLightDerateSta); /* 降额状态 */

                if( CorneringLightDerateSta.bits.ot_chn == 1u ||
                    CorneringLightDerateSta.bits.ot_led == 1u ||
                    CorneringLightDerateSta.bits.ot_amb == 1u ||
                    gs_CorneringLightConfigInfo.CLChannelMask & RealTimeErrMask.chnErr ||
                    gs_CorneringLightConfigInfo.CLChannelMask & RealTimeErrMask.ntcErr ||
                    gs_CorneringLightRunInfo.ChannelMask != gs_CorneringLightConfigInfo.CLChannelMask )  /* 读取实时故障和DTC故障，DTC记录并关闭通道后实时故障清除 */
                {
                    SetLgtStsFb_CORN(STS_ERR);
                    gs_CorneringLightDidInfo.CorneringLightStatus = CorneringLightStatus_Error;
                }
                else
                {
                    SetLgtStsFb_CORN(STS_ON);
                    gs_CorneringLightDidInfo.CorneringLightStatus = CorneringLightStatus_On;
                }
            }
        }
        else if(ActnOfLedCornrgLamp_Curr == 0 && ActnOfLedCornrgLamp_Last == 0) /* 关灯信号保持阶段 */
        {
            if(CorneringLightInfo_OffRampTime < gs_CorneringLightConfigInfo.SelfOffRampTime)
            {
                CorneringLightInfo_OffRampTime += timebase;
            }
            else
            {
                SetLgtStsFb_CORN(STS_OFF);
                gs_CorneringLightDidInfo.CorneringLightStatus = CorneringLightStatus_Off;
            }
        }
    }
    else if(gs_CorneringLightRunInfo.Ownership == E_CorneringLightOwnership_Fog)/* 雾灯获得硬件归属权，直接反馈关闭 */
    {
        SetLgtStsFb_CORN(STS_OFF);
        gs_CorneringLightDidInfo.CorneringLightStatus = CorneringLightStatus_Off;
    }
}





