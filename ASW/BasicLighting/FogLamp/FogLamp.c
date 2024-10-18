/********************************
 * FogLamp.c
 *
 *  Created on: 2024/4/15
 *      Author: tujiongjiong
 ********************************/


/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "FogLamp.h"

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
static S_FogLampConfigInfo gs_FogLampConfigInfo;

static S_FogLampRunInfo gs_FogLampRunInfo =
{
    .Pwm_AFS        = 0,
    .Pwm_Basic      = 0,
    .Pwm_Target     = 0,
    .Pwm_LastTarget = 0,
    .ChannelMask    = 0,
    .RunState       = E_FogLampState_Run
};

static S_FogLampDidInfo gs_FogLampDidInfo = { .FogLampStatus = FogLampStatus_Res };

/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/

/* 读取雾灯参数配置并存放 */
static Std_ReturnType FogLamp_GetParameterIntoInfo(void)
{
    Std_ReturnType rtval = E_OK;

    gs_FogLampConfigInfo.CLChannelMask = GetChannelMaskByLightFunction(E_CorneringLight) & 0xFFF;
    gs_FogLampConfigInfo.FLChannelMask = GetChannelMaskByLightFunction(E_FogLamp) & 0xFFF;
    gs_FogLampConfigInfo.IntensityDuty = Get_pLedIntensFogLDuty();
    gs_FogLampConfigInfo.LedGamma      = (E_LedGamma)Get_pLedGamma();

    switch( gs_FogLampConfigInfo.LedGamma )
    {
        case E_LedGamma_Step:
            gs_FogLampConfigInfo.OnRampTime  = 0;
            gs_FogLampConfigInfo.OffRampTime = 0;
            break;

        case E_LedGamma_Linear:
        case E_LedGamma_Exponent:
            gs_FogLampConfigInfo.OnRampTime  = Get_pLedOnRampTi(E_FogLamp);
            gs_FogLampConfigInfo.OffRampTime = Get_pLedOffRampTi(E_FogLamp);
    }

    gs_FogLampConfigInfo.OnDelayTime  = Get_pLedONDelay(E_FogLamp);
    gs_FogLampConfigInfo.OffDelayTime = Get_pLedOFFDelay(E_FogLamp);

    return rtval;
}


/* 雾灯运行 */
static Std_ReturnType FogLamp_Run(uint8_t timebase)
{
    Std_ReturnType rtval = E_OK;

    /* 开灯仲裁 */
    gs_FogLampRunInfo.Pwm_LastTarget = gs_FogLampRunInfo.Pwm_Target;
    if(gs_FogLampRunInfo.Pwm_AFS > 0)
    {
        gs_FogLampRunInfo.Pwm_Target = gs_FogLampRunInfo.Pwm_AFS;
    }
    else if(gs_FogLampRunInfo.Pwm_Basic > 0)
    {
        gs_FogLampRunInfo.Pwm_Target = gs_FogLampRunInfo.Pwm_Basic;
    }
    else
    {
        gs_FogLampRunInfo.Pwm_Target = 0;
    }

    if(gs_FogLampConfigInfo.CLChannelMask == gs_FogLampConfigInfo.FLChannelMask) /* 角灯雾灯完全共用通道，不再单独控制雾灯 */
    {
        CorneringLight_SetPwmOfFog(gs_FogLampRunInfo.Pwm_Target * gs_FogLampConfigInfo.IntensityDuty / 100);
        return rtval;
    }

    /* 判断是否是开关灯前 */
    if(gs_FogLampRunInfo.Pwm_LastTarget != gs_FogLampRunInfo.Pwm_Target)
    {
        if(gs_FogLampRunInfo.Pwm_LastTarget == 0 && gs_FogLampRunInfo.Pwm_Target > 0)
        {
            gs_FogLampRunInfo.ChannelMask = gs_FogLampConfigInfo.FLChannelMask;
            gs_FogLampRunInfo.RunState = E_FogLampState_OnDelay;
        }
        else if(gs_FogLampRunInfo.Pwm_LastTarget > 0 && gs_FogLampRunInfo.Pwm_Target == 0)
        {
            gs_FogLampRunInfo.RunState = E_FogLampState_OffDelay;
        }
    }

    /* 排除故障的LED通道 */
    if(gs_FogLampRunInfo.Pwm_Target)
    {
        U_DisSrc_t FogLampDerateSta;

        GetLgtFuncDisSrc_FOG(& FogLampDerateSta); /* 降额状态 */
        if( FogLampDerateSta.bits.sp_los == 1u ||
            FogLampDerateSta.bits.sp_ouv == 1u ||
            FogLampDerateSta.bits.ot_chn == 1u ||
            FogLampDerateSta.bits.ot_led == 1u ||
            FogLampDerateSta.bits.ot_amb == 1u ) /* 雾灯开启降额 */
        {
            LampM_SetLampChn(E_FogLamp, gs_FogLampRunInfo.ChannelMask, 0, 0, 0); /* 立即关闭所有LED通道并返回 */
            return rtval;
        }
        else /* 雾灯没有降额 */
        {
            uint16_t ErrorChannelMask = 0;
            S_LF_Err_T DTCErrMask;

            LampM_GetLampBaseErr_DTC(& DTCErrMask);
            ErrorChannelMask = gs_FogLampRunInfo.ChannelMask & DTCErrMask.chnErr; /* 剩余LED通道出现了新故障 */
            if(Get_LightN_1() & 0x0100) /* 有N-1策略 */
            {
                if(ErrorChannelMask)
                {
                    ErrorChannelMask = gs_FogLampRunInfo.ChannelMask;
                }
            }
            gs_FogLampRunInfo.ChannelMask ^= ErrorChannelMask; /* 逐步屏蔽故障的LED通道 */
            LampM_SetLampChn(E_FogLamp, ErrorChannelMask, 0, 0, 0); /* 立即关闭无矩阵故障LED通道，关闭后下一次就读不到该故障 */
        }
    }

    static uint8_t FogLamp_OnDelayTime = 0;
    static uint8_t FogLamp_OffDelayTime = 0;

    switch( gs_FogLampRunInfo.RunState )
    {
        case E_FogLampState_OnDelay:
            FogLamp_OnDelayTime += timebase;
            if(FogLamp_OnDelayTime >= gs_FogLampConfigInfo.OnDelayTime)
            {
                FogLamp_OnDelayTime = 0;
                gs_FogLampRunInfo.RunState = E_FogLampState_Run;
            }
            break;

        case E_FogLampState_OffDelay:
            FogLamp_OffDelayTime += timebase;
            if(FogLamp_OffDelayTime >= gs_FogLampConfigInfo.OffDelayTime)
            {
                FogLamp_OffDelayTime = 0;
                gs_FogLampRunInfo.RunState = E_FogLampState_Run;
            }
            break;

        case E_FogLampState_Run:
            LampM_SetLampChn(E_FogLamp, gs_FogLampRunInfo.ChannelMask, gs_FogLampRunInfo.Pwm_Target, gs_FogLampConfigInfo.OnRampTime, gs_FogLampConfigInfo.OffRampTime);
    }
    return rtval;
}

/* 打开雾灯 */
static Std_ReturnType FogLamp_SwitchON(void)
{
    Std_ReturnType rtval = E_OK;

    gs_FogLampRunInfo.Pwm_Basic = 100 * gs_FogLampConfigInfo.IntensityDuty / 100;
    return rtval;
}

/* 关闭雾灯 */
static Std_ReturnType FogLamp_SwitchOFF(void)
{
    Std_ReturnType rtval = E_OK;

    gs_FogLampRunInfo.Pwm_Basic = 0;
    return rtval;
}


/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
/* 设置雾灯的DID数据，4368 */
Std_ReturnType FogLamp_SetDID_4368_FogLampStatus(void)
{
    Std_ReturnType rtval = E_OK;

    rtval |= Interface_SetDidSignalData(DIDSIGNALNAME_ID_StsOfFog, (uint32_t)gs_FogLampDidInfo.FogLampStatus);

    return rtval;
}

/* 雾灯AFS设置PWM */
void FogLamp_SetPwmOfAFS(uint8_t PwmValue)
{
    gs_FogLampRunInfo.Pwm_AFS = PwmValue * gs_FogLampConfigInfo.IntensityDuty / 100;
}


/* 雾灯启动初始化 */
void FogLamp_Init(void)
{
    FogLamp_GetParameterIntoInfo();
}

/* 雾灯主函数 */
void FogLamp_MainFunction(uint8_t timebase)
{
    if(gs_FogLampConfigInfo.FLChannelMask == 0) /* 没有该灯光配置，直接退出 */
    {
        return;
    }

    static uint8_t ActnOfLedFrntFogLamp_Curr = 0;
    static uint8_t ActnOfLedFrntFogLamp_Last = 0;

    S_LgtActIns_t LgtActIns;
    GetLgtActIns(& LgtActIns);

    ActnOfLedFrntFogLamp_Last = ActnOfLedFrntFogLamp_Curr;
    ActnOfLedFrntFogLamp_Curr = LgtActIns.ActFOG;

    if(ActnOfLedFrntFogLamp_Curr)
    {
        FogLamp_SwitchON();
    }
    else
    {
        FogLamp_SwitchOFF();
    }

    FogLamp_Run(timebase);

    static uint16 FogLampInfo_OnRampTime = 0;
    static uint16 FogLampInfo_OffRampTime = 0;

    if(ActnOfLedFrntFogLamp_Curr != ActnOfLedFrntFogLamp_Last) /* 开关激活信号转换时间节点 */
    {
        FogLampInfo_OnRampTime = 0;
        FogLampInfo_OffRampTime = 0;
    }
    else if(ActnOfLedFrntFogLamp_Curr == 1 && ActnOfLedFrntFogLamp_Last == 1) /* 开灯信号保持阶段 */
    {
        if(FogLampInfo_OnRampTime < gs_FogLampConfigInfo.OnRampTime)
        {
            FogLampInfo_OnRampTime += timebase;
        }
        else
        {
            if(gs_FogLampConfigInfo.CLChannelMask == gs_FogLampConfigInfo.FLChannelMask) /* 角灯雾灯完全共用通道，实时故障需要从角灯读取*/
            {
                if(CorneringLight_GetCLRealTimeErrSta() == 1u)
                {
                    SetLgtStsFb_FOG(STS_ERR);
                    gs_FogLampDidInfo.FogLampStatus = FogLampStatus_Error;
                }
                else
                {
                    SetLgtStsFb_FOG(STS_ON);
                    gs_FogLampDidInfo.FogLampStatus = FogLampStatus_On;
                }
            }
            else
            {
                S_LF_Err_T RealTimeErrMask;
                U_DisSrc_t FogLampDerateSta;

                LampM_GetLampBaseErr(& RealTimeErrMask);
                GetLgtFuncDisSrc_FOG(& FogLampDerateSta); /* 降额状态 */
                if( FogLampDerateSta.bits.ot_chn == 1u ||
                    FogLampDerateSta.bits.ot_led == 1u ||
                    FogLampDerateSta.bits.ot_amb == 1u ||
                    gs_FogLampConfigInfo.FLChannelMask & RealTimeErrMask.chnErr ||
                    gs_FogLampConfigInfo.FLChannelMask & RealTimeErrMask.ntcErr ||
                    gs_FogLampRunInfo.ChannelMask != gs_FogLampConfigInfo.FLChannelMask ) /* 读取实时故障和DTC故障，DTC记录并关闭通道后实时故障清除 */
                {
                    SetLgtStsFb_FOG(STS_ERR);
                    gs_FogLampDidInfo.FogLampStatus = FogLampStatus_Error;
                }
                else
                {
                    SetLgtStsFb_FOG(STS_ON);
                    gs_FogLampDidInfo.FogLampStatus = FogLampStatus_On;
                }
            }
        }
    }
    else if(ActnOfLedFrntFogLamp_Curr == 0 && ActnOfLedFrntFogLamp_Last == 0) /* 关灯信号保持阶段 */
    {
        if(FogLampInfo_OffRampTime < gs_FogLampConfigInfo.OffRampTime)
        {
            FogLampInfo_OffRampTime += timebase;
        }
        else
        {
            SetLgtStsFb_FOG(STS_OFF);
            gs_FogLampDidInfo.FogLampStatus = FogLampStatus_Off;
        }
    }
}


