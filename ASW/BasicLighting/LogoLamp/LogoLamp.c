/********************************
 * LogoLamp.c
 *
 *  Created on: 2024/4/15
 *      Author: tujiongjiong
 ********************************/


/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "LogoLamp.h"

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
static S_LogoLampConfigInfo gs_LogoLampConfigInfo;
static S_LogoLampRunInfo gs_LogoLampRunInfo =
{
    .Pwm_Posn         = 0,
    .Pwm_LB           = 0,
    .Pwm_Self         = 0,
    .Pwm_Target       = 0,
    .Pwm_LastTarget   = 0,
    .ChannelMaskWoMtx = 0,
    .ChannelMaskWiMtx = 0,
    .Ownership = E_LogoLampOwnership_Self,
    .RunState  = E_LogoLampRunState_Run,
    .TacticN_1    = 0,
    .OnRampTime   = 0,
    .OffRampTime  = 0,
    .OnDelayTime  = 0,
    .OffDelayTime = 0
};

static S_LF_Info_T gs_LF_Info_LogoLamp;

/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/

/* 读取LOGO灯参数配置并存放 */
static Std_ReturnType LogoLamp_GetParameterIntoInfo(void)
{
    Std_ReturnType rtval = E_OK;

    gs_LogoLampConfigInfo.LedGamma = (E_LedGamma)Get_pLedGamma();

    switch( gs_LogoLampConfigInfo.LedGamma )
    {
        case E_LedGamma_Step:
            gs_LogoLampConfigInfo.SelfOnRampTime  = 0;
            gs_LogoLampConfigInfo.SelfOffRampTime = 0;
            gs_LogoLampConfigInfo.LBOnRampTime    = 0;
            gs_LogoLampConfigInfo.LBOffRampTime   = 0;
            gs_LogoLampConfigInfo.PosnOnRampTime  = 0;
            gs_LogoLampConfigInfo.PosnOffRampTime = 0;
            break;

        case E_LedGamma_Linear:
        case E_LedGamma_Exponent:
            gs_LogoLampConfigInfo.SelfOnRampTime  = Get_pLedOnRampTi(E_LogoLamp);
            gs_LogoLampConfigInfo.SelfOffRampTime = Get_pLedOffRampTi(E_LogoLamp);
            gs_LogoLampConfigInfo.LBOnRampTime    = Get_pLedOnRampTi(E_LowBeamKink);
            gs_LogoLampConfigInfo.LBOffRampTime   = Get_pLedOffRampTi(E_LowBeamKink);
            gs_LogoLampConfigInfo.PosnOnRampTime  = Get_pLedOnRampTi(E_PositionLight);
            gs_LogoLampConfigInfo.PosnOffRampTime = Get_pLedOffRampTi(E_PositionLight);
    }
    gs_LogoLampConfigInfo.SelfOnDelayTime  = Get_pLedONDelay(E_LogoLamp);
    gs_LogoLampConfigInfo.SelfOffDelayTime = Get_pLedOFFDelay(E_LogoLamp);
    gs_LogoLampConfigInfo.LBOnDelayTime    = Get_pLedONDelay(E_LowBeamKink);
    gs_LogoLampConfigInfo.LBOffDelayTime   = Get_pLedOFFDelay(E_LowBeamKink);
    gs_LogoLampConfigInfo.PosnOnDelayTime  = Get_pLedONDelay(E_PositionLight);
    gs_LogoLampConfigInfo.PosnOffDelayTime = Get_pLedOFFDelay(E_PositionLight);

    gs_LogoLampConfigInfo.PosnIntensityDuty = Get_pLedIntensPosLDuty();
    gs_LogoLampConfigInfo.PartOfLBOrPosn    = Get_pLogoLowbeamPOS();

    switch( GetChannelMaskByLightFunction(E_LogoLamp) & 0x07000 )
    {
        case 0x0000:
            gs_LogoLampConfigInfo.HSDChannel = E_HSChannel_HS0; /* 表示没有高边配置 */
            break;
        case 0x1000:
            gs_LogoLampConfigInfo.HSDChannel = E_HSChannel_HS1;
            break;
        case 0x2000:
            gs_LogoLampConfigInfo.HSDChannel = E_HSChannel_HS2;
            break;
        case 0x4000:
            gs_LogoLampConfigInfo.HSDChannel = E_HSChannel_HS3;
    }
    return rtval;
}

/* LOGO灯硬件归属权仲裁 */
static Std_ReturnType LogoLamp_Ownership(void)
{
    Std_ReturnType rtval = E_OK;

    if(gs_LogoLampConfigInfo.PartOfLBOrPosn == 1 || gs_LogoLampConfigInfo.PartOfLBOrPosn == 2)
    {
        static uint8_t LogoLamp_ActStaCurr = 0;
        static uint8_t LogoLamp_ActStaLast = 0;

        LogoLamp_ActStaLast = LogoLamp_ActStaCurr;

        if(gs_LogoLampRunInfo.Pwm_Self > 0)
        {
            LogoLamp_ActStaCurr = 1;
        }
        else
        {
            LogoLamp_ActStaCurr = 0;
        }

        if(gs_LogoLampConfigInfo.PartOfLBOrPosn == 1)
        {
            static uint8_t LowBeamLight_ActStaCurr = 0;
            static uint8_t LowBeamLight_ActStaLast = 0;

            LowBeamLight_ActStaLast = LowBeamLight_ActStaCurr;
            if(gs_LogoLampRunInfo.Pwm_LB > 0)
            {
                LowBeamLight_ActStaCurr = 1;
            }
            else
            {
                LowBeamLight_ActStaCurr = 0;
            }
            if(LogoLamp_ActStaCurr == 1 && LowBeamLight_ActStaCurr == 1)
            {
                gs_LogoLampRunInfo.Ownership = E_LogoLampOwnership_LB;
            }
            else if(LogoLamp_ActStaCurr == 1 && LowBeamLight_ActStaCurr == 0)
            {
                gs_LogoLampRunInfo.Ownership = E_LogoLampOwnership_Self;
            }
            else if(LogoLamp_ActStaCurr == 0 && LowBeamLight_ActStaCurr == 1)
            {
                gs_LogoLampRunInfo.Ownership = E_LogoLampOwnership_LB;
            }
            else if(LogoLamp_ActStaCurr == 0 && LowBeamLight_ActStaCurr == 0)
            {
                if(LogoLamp_ActStaLast == 1 && LowBeamLight_ActStaLast == 1)
                {
                    gs_LogoLampRunInfo.Ownership = E_LogoLampOwnership_LB;
                }
                else if(LogoLamp_ActStaLast == 1 && LowBeamLight_ActStaLast == 0)
                {
                    gs_LogoLampRunInfo.Ownership = E_LogoLampOwnership_Self;
                }
                else if(LogoLamp_ActStaLast == 0 && LowBeamLight_ActStaLast == 1)
                {
                    gs_LogoLampRunInfo.Ownership = E_LogoLampOwnership_LB;
                }
            }
        }
        else if(gs_LogoLampConfigInfo.PartOfLBOrPosn == 2)
        {
            static uint8_t PositionLight_ActStaCurr = 0;
            static uint8_t PositionLight_ActStaLast = 0;

            PositionLight_ActStaLast = PositionLight_ActStaCurr;
            if(gs_LogoLampRunInfo.Pwm_Posn > 0)
            {
                PositionLight_ActStaCurr = 1;
            }
            else
            {
                PositionLight_ActStaCurr = 0;
            }
            if(LogoLamp_ActStaCurr == 1 && PositionLight_ActStaCurr == 1)
            {
                gs_LogoLampRunInfo.Ownership = E_LogoLampOwnership_Posn;
            }
            else if(LogoLamp_ActStaCurr == 1 && PositionLight_ActStaCurr == 0)
            {
                gs_LogoLampRunInfo.Ownership = E_LogoLampOwnership_Self;
            }
            else if(LogoLamp_ActStaCurr == 0 && PositionLight_ActStaCurr == 1)
            {
                gs_LogoLampRunInfo.Ownership = E_LogoLampOwnership_Posn;
            }
            else if(LogoLamp_ActStaCurr == 0 && PositionLight_ActStaCurr == 0)
            {
                if(LogoLamp_ActStaLast == 1 && PositionLight_ActStaLast == 1)
                {
                    gs_LogoLampRunInfo.Ownership = E_LogoLampOwnership_Posn;
                }
                else if(LogoLamp_ActStaLast == 1 && PositionLight_ActStaLast == 0)
                {
                    gs_LogoLampRunInfo.Ownership = E_LogoLampOwnership_Self;
                }
                else if(LogoLamp_ActStaLast == 0 && PositionLight_ActStaLast == 1)
                {
                    gs_LogoLampRunInfo.Ownership = E_LogoLampOwnership_Posn;
                }
            }
        }
    }
    else
    {
        gs_LogoLampRunInfo.Ownership = E_LogoLampOwnership_Self;
    }

    if(gs_LogoLampRunInfo.Ownership == E_LogoLampOwnership_Self)
    {
        gs_LogoLampRunInfo.TacticN_1    = Get_LightN_1() & 0x0200;
        gs_LogoLampRunInfo.OnRampTime   = gs_LogoLampConfigInfo.SelfOnRampTime;
        gs_LogoLampRunInfo.OffRampTime  = gs_LogoLampConfigInfo.SelfOffRampTime;
        gs_LogoLampRunInfo.OnDelayTime  = gs_LogoLampConfigInfo.SelfOnDelayTime;
        gs_LogoLampRunInfo.OffDelayTime = gs_LogoLampConfigInfo.SelfOffDelayTime;
    }
    else if(gs_LogoLampRunInfo.Ownership == E_LogoLampOwnership_LB)
    {
        gs_LogoLampRunInfo.TacticN_1    = Get_LightN_1() & 0x0000;
        gs_LogoLampRunInfo.OnRampTime   = gs_LogoLampConfigInfo.LBOnRampTime;
        gs_LogoLampRunInfo.OffRampTime  = gs_LogoLampConfigInfo.LBOffRampTime;
        gs_LogoLampRunInfo.OnDelayTime  = gs_LogoLampConfigInfo.LBOnDelayTime;
        gs_LogoLampRunInfo.OffDelayTime = gs_LogoLampConfigInfo.LBOffDelayTime;
    }
    else if(gs_LogoLampRunInfo.Ownership == E_LogoLampOwnership_Posn)
    {
        gs_LogoLampRunInfo.TacticN_1    = Get_LightN_1() & 0x0020;
        gs_LogoLampRunInfo.OnRampTime   = gs_LogoLampConfigInfo.PosnOnRampTime;
        gs_LogoLampRunInfo.OffRampTime  = gs_LogoLampConfigInfo.PosnOffRampTime;
        gs_LogoLampRunInfo.OnDelayTime  = gs_LogoLampConfigInfo.PosnOnDelayTime;
        gs_LogoLampRunInfo.OffDelayTime = gs_LogoLampConfigInfo.PosnOffDelayTime;
    }
    return rtval;
}

/* LOGO灯运行 */
static Std_ReturnType LogoLamp_Run(uint8_t timebase)
{
    Std_ReturnType rtval = E_OK;
    
    LogoLamp_Ownership();

    /* 开灯仲裁 */
    gs_LogoLampRunInfo.Pwm_LastTarget = gs_LogoLampRunInfo.Pwm_Target;
    if(gs_LogoLampRunInfo.Pwm_Posn > 0)
    {
        gs_LogoLampRunInfo.Pwm_Target = gs_LogoLampRunInfo.Pwm_Posn;
    }
    else if(gs_LogoLampRunInfo.Pwm_LB > 0)
    {
        gs_LogoLampRunInfo.Pwm_Target = gs_LogoLampRunInfo.Pwm_LB;
    }
    else if(gs_LogoLampRunInfo.Pwm_Self > 0)
    {
        gs_LogoLampRunInfo.Pwm_Target = gs_LogoLampRunInfo.Pwm_Self;
    }
    else
    {
        gs_LogoLampRunInfo.Pwm_Target = 0;
    }

    /* 判断是否是开关灯前 */
    if(gs_LogoLampRunInfo.Pwm_LastTarget != gs_LogoLampRunInfo.Pwm_Target)
    {
        if(gs_LogoLampRunInfo.Pwm_LastTarget == 0 && gs_LogoLampRunInfo.Pwm_Target > 0) /* 开灯前时间点 */
        {
            gs_LogoLampRunInfo.ChannelMaskWoMtx = gs_LF_Info_LogoLamp.chnMask ^ gs_LF_Info_LogoLamp.mtxMask; /* 开灯前读取一次通道掩码 */
            gs_LogoLampRunInfo.ChannelMaskWiMtx = gs_LF_Info_LogoLamp.mtxMask;

            gs_LogoLampRunInfo.RunState = E_LogoLampRunState_OnDelay;
        }
        else if(gs_LogoLampRunInfo.Pwm_LastTarget > 0 && gs_LogoLampRunInfo.Pwm_Target == 0) /* 关灯前时间点 */
        {
            gs_LogoLampRunInfo.RunState = E_LogoLampRunState_OffDelay;
        }
    }

    /* 排除故障的LED通道 */
    if(gs_LogoLampRunInfo.Pwm_Target)
    {
        if(gs_LogoLampConfigInfo.HSDChannel == E_HSChannel_HS0) /* LOGO配置为LED通道 */
        {
            U_DisSrc_t LogoLampDerateSta;

            GetLgtFuncDisSrc_LOGO(& LogoLampDerateSta); /* 降额状态 */
            if( LogoLampDerateSta.bits.sp_los == 1u ||
                LogoLampDerateSta.bits.sp_ouv == 1u ||
                LogoLampDerateSta.bits.ot_chn == 1u ||
                LogoLampDerateSta.bits.ot_led == 1u ||
                LogoLampDerateSta.bits.ot_amb == 1u ) /* LOGO灯开启降额 */
            {
                LampM_SetLampChn(E_LogoLamp, gs_LogoLampRunInfo.ChannelMaskWoMtx, 0, 0, 0); /* 立即关闭所有LED通道并返回 */
                LampM_SetLampChn(E_LogoLamp, gs_LogoLampRunInfo.ChannelMaskWiMtx, 0, 0, 0);
                return rtval;
            }
            else /* LOGO灯没有降额 */
            {
                uint16_t ErrorChannelWoMtxMask = 0;
                uint16_t ErrorChannelWiMtxMask = 0;
                S_LF_Err_T DTCErrMask;

                LampM_GetLampBaseErr_DTC(& DTCErrMask); /* LED通道DTC故障 */
                ErrorChannelWoMtxMask = gs_LogoLampRunInfo.ChannelMaskWoMtx & DTCErrMask.chnErr; /* 剩余LED通道出现了新故障 */
                ErrorChannelWiMtxMask = gs_LogoLampRunInfo.ChannelMaskWiMtx & DTCErrMask.chnErr;
                if(gs_LogoLampRunInfo.TacticN_1) /* 有N-1策略 */
                {
                    if(ErrorChannelWoMtxMask || ErrorChannelWiMtxMask)
                    {
                        ErrorChannelWoMtxMask = gs_LogoLampRunInfo.ChannelMaskWoMtx;
                        ErrorChannelWiMtxMask = gs_LogoLampRunInfo.ChannelMaskWiMtx;
                    }
                }
                gs_LogoLampRunInfo.ChannelMaskWoMtx ^= ErrorChannelWoMtxMask; /* 逐步屏蔽故障的LED通道 */
                gs_LogoLampRunInfo.ChannelMaskWiMtx ^= ErrorChannelWiMtxMask; /* 逐步屏蔽故障的LED通道 */
                LampM_SetLampChn(E_LogoLamp, ErrorChannelWoMtxMask, 0, 0, 0); /* 立即关闭无矩阵故障LED通道，关闭后下一次就读不到该故障 */
                LampM_SetLampChn(E_LogoLamp, ErrorChannelWiMtxMask, 0, 0, 0); /* 立即关闭有矩阵故障LED通道，关闭后下一次就读不到该故障  */
            }
        }
    }

    uint8_t PixelNum;
    static uint8_t LogoLamp_OnDelayTime = 0;
    static uint8_t LogoLamp_OffDelayTime = 0;

    switch( gs_LogoLampRunInfo.RunState )
    {
        case E_LogoLampRunState_OnDelay:
            LogoLamp_OnDelayTime += timebase;
            if(LogoLamp_OnDelayTime >= gs_LogoLampRunInfo.OnDelayTime)
            {
                LogoLamp_OnDelayTime = 0;
                gs_LogoLampRunInfo.RunState = E_LogoLampRunState_Run;
            }
            break;

        case E_LogoLampRunState_OffDelay:
            LogoLamp_OffDelayTime += timebase;
            if(LogoLamp_OffDelayTime >= gs_LogoLampRunInfo.OffDelayTime)
            {
                LogoLamp_OffDelayTime = 0;
                gs_LogoLampRunInfo.RunState = E_LogoLampRunState_Run;
            }
            break;

        case E_LogoLampRunState_Run:
            if(gs_LogoLampConfigInfo.HSDChannel != E_HSChannel_HS0) /* LOGO配置为高边 */
            {
                if(gs_LogoLampRunInfo.Pwm_Target) /* 开灯 */
                {
                    HSDManage_SetHSDActState(gs_LogoLampConfigInfo.HSDChannel, E_HSDActSta_Act);
                }
                else /* 关灯 */
                {
                    HSDManage_SetHSDActState(gs_LogoLampConfigInfo.HSDChannel, E_HSDActSta_NoAct);
                }
            }
            else /* LOGO配置为LED通道 */
            {
                LampM_SetLampChn(E_LogoLamp, gs_LogoLampRunInfo.ChannelMaskWoMtx, gs_LogoLampRunInfo.Pwm_Target, gs_LogoLampRunInfo.OnRampTime, gs_LogoLampRunInfo.OffRampTime);
                LampM_SetLampChn(E_LogoLamp, gs_LogoLampRunInfo.ChannelMaskWiMtx, 100, 0, 0);
                for(PixelNum = 1; PixelNum <= gs_LF_Info_LogoLamp.lednum; PixelNum++)
                {
                    LampM_SetLampPix(E_LogoLamp, PixelNum, gs_LogoLampRunInfo.Pwm_Target, gs_LogoLampRunInfo.OnRampTime, gs_LogoLampRunInfo.OffRampTime);
                }
            }
    }
    return rtval;
}


/* 打开LOGO灯 */
static Std_ReturnType LogoLamp_SwitchON(void)
{
    Std_ReturnType rtval = E_OK;

    gs_LogoLampRunInfo.Pwm_Self = 100;
    return rtval;
}

/* 关闭LOGO灯 */
static Std_ReturnType LogoLamp_SwitchOFF(void)
{
    Std_ReturnType rtval = E_OK;

    gs_LogoLampRunInfo.Pwm_Self = 0;
    return rtval;
}



/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
/* 获取LOGO灯作为近光灯或位置灯一部分时的故障状态 */
/* 返回值： 0：无故障； 1：有故障 */
uint8_t LogoLamp_GetLogoLampErrorState(void)
{
    if(gs_LogoLampRunInfo.Ownership != E_LogoLampOwnership_Self) /* LOGO灯归属于近光灯或位置灯 */
    {
        if(gs_LogoLampConfigInfo.HSDChannel != E_HSChannel_HS0)
        {
            E_HSDErrSta LogoLampHSDErrSta;
            LogoLampHSDErrSta = HSDManage_GetHSDErrState(gs_LogoLampConfigInfo.HSDChannel);

            if(LogoLampHSDErrSta == E_HSDErrSta_HWRTErr || LogoLampHSDErrSta == E_HSDErrSta_HWDtcErr)
            {
                return 1;
            }
            else if(LogoLampHSDErrSta == E_HSDErrSta_Normal)
            {
                return 0;
            }
        }
        else
        {
            S_LF_Err_T RealTimeErrMask;
            LampM_GetLampBaseErr(& RealTimeErrMask);
            if( (gs_LF_Info_LogoLamp.chnMask & RealTimeErrMask.chnErr) || 
                (gs_LF_Info_LogoLamp.chnMask & RealTimeErrMask.ntcErr) ||
                (gs_LogoLampRunInfo.ChannelMaskWoMtx | gs_LogoLampRunInfo.ChannelMaskWiMtx) != gs_LF_Info_LogoLamp.chnMask ) /* 有故障LED通道 */
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
}


/* LOGO灯启动初始化 */
void LogoLamp_Init(void)
{
    LogoLamp_GetParameterIntoInfo();
    lampM_GetLampInfo(E_LogoLamp, &gs_LF_Info_LogoLamp);
}

/* LOGO灯主函数 */
void LogoLamp_MainFunction(uint8_t timebase)
{
    if(gs_LF_Info_LogoLamp.chnMask == 0) /* 没有该灯光配置，直接退出 */
    {
        return;
    }

    static uint8_t ActnOfLedLogoLamp_Curr = 0;
    static uint8_t ActnOfLedLogoLamp_Last = 0;

    S_LgtActIns_t LgtActIns;
    GetLgtActIns(& LgtActIns);
    
    ActnOfLedLogoLamp_Last = ActnOfLedLogoLamp_Curr;
    ActnOfLedLogoLamp_Curr = LgtActIns.ActLOGO;

    if(ActnOfLedLogoLamp_Curr) /* 开关LOGO灯 */
    {
        LogoLamp_SwitchON();
    }
    else
    {
        LogoLamp_SwitchOFF();
    }
    if(gs_LogoLampConfigInfo.PartOfLBOrPosn == 1u) /* 开关近光灯 */
    {
        if(LgtActIns.ActLB)
        {
            gs_LogoLampRunInfo.Pwm_LB = 100;
        }
        else
        {
            gs_LogoLampRunInfo.Pwm_LB = 0;
        }
    }
    if(gs_LogoLampConfigInfo.PartOfLBOrPosn == 2u) /* 开关位置灯 */
    {
        if(LgtActIns.ActPOS)
        {
            gs_LogoLampRunInfo.Pwm_Posn = 100 * gs_LogoLampConfigInfo.PosnIntensityDuty / 100;
        }
        else
        {
            gs_LogoLampRunInfo.Pwm_Posn = 0;
        }
    }

    LogoLamp_Run(timebase);

    if(gs_LogoLampRunInfo.Ownership == E_LogoLampOwnership_Self) /* LOGO灯本身获得硬件归属权 */
    {
        static uint16 LogoLampInfo_OnRampTime = 0;
        static uint16 LogoLampInfo_OffRampTime = 0;

        if(ActnOfLedLogoLamp_Curr != ActnOfLedLogoLamp_Last) /* 开关激活信号转换时间节点 */
        {
            LogoLampInfo_OnRampTime = 0;
            LogoLampInfo_OffRampTime = 0;
        }
        else if(ActnOfLedLogoLamp_Curr == 1 && ActnOfLedLogoLamp_Last == 1) /* 开灯信号保持阶段 */
        {
            if(LogoLampInfo_OnRampTime < gs_LogoLampConfigInfo.SelfOnRampTime)
            {
                LogoLampInfo_OnRampTime += timebase;
            }
            else
            {
                if(gs_LogoLampConfigInfo.HSDChannel != E_HSChannel_HS0)
                {
                    E_HSDErrSta LogoLampHSDErrSta;
                    LogoLampHSDErrSta = HSDManage_GetHSDErrState(gs_LogoLampConfigInfo.HSDChannel);

                    if(LogoLampHSDErrSta == E_HSDErrSta_HWRTErr || LogoLampHSDErrSta == E_HSDErrSta_HWDtcErr)
                    {
                        SetLgtStsFb_LOGO(STS_ERR); /* 上报LOGO灯故障状态 */
                    }
                    else if(LogoLampHSDErrSta == E_HSDErrSta_Normal)
                    {
                        SetLgtStsFb_LOGO(STS_ON);
                    }
                }
                else
                {
                    S_LF_Err_T RealTimeErrMask;
                    U_DisSrc_t LogoLampDerateSta;

                    LampM_GetLampBaseErr(& RealTimeErrMask);
                    GetLgtFuncDisSrc_LOGO(& LogoLampDerateSta); /* 降额状态 */
                    if( LogoLampDerateSta.bits.ot_chn == 1u ||
                        LogoLampDerateSta.bits.ot_led == 1u ||
                        LogoLampDerateSta.bits.ot_amb == 1u ||
                        (gs_LF_Info_LogoLamp.chnMask & RealTimeErrMask.chnErr) ||
                        (gs_LF_Info_LogoLamp.chnMask & RealTimeErrMask.ntcErr) ||
                        (gs_LogoLampRunInfo.ChannelMaskWoMtx | gs_LogoLampRunInfo.ChannelMaskWiMtx) != gs_LF_Info_LogoLamp.chnMask ) /* 有故障LED通道 */
                    {
                        SetLgtStsFb_LOGO(STS_ERR); /* 上报LOGO灯故障状态 */
                    }
                    else
                    {
                        SetLgtStsFb_LOGO(STS_ON);
                    }
                }
            }
        }
        else if(ActnOfLedLogoLamp_Curr == 0 && ActnOfLedLogoLamp_Last == 0) /* 关灯信号保持阶段 */
        {
            if(LogoLampInfo_OffRampTime < gs_LogoLampConfigInfo.SelfOffRampTime)
            {
                LogoLampInfo_OffRampTime += timebase;
            }
            else
            {
                SetLgtStsFb_LOGO(STS_OFF);
            }
        }
    }
    else /* LOGO灯本身没有获得硬件归属权，直接反馈关闭 */
    {
        SetLgtStsFb_LOGO(STS_OFF);
    }
}



