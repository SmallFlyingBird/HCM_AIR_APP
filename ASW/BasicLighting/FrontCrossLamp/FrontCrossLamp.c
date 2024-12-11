/********************************
 * FrontCrossLamp.c
 *
 *  Created on: 2024/4/17
 *      Author: tujiongjiong
 ********************************/


/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "FrontCrossLamp.h"

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
static S_FrontCrossLampConfigInfo gs_FrontCrossLampConfigInfo;
static S_FrontCrossLampRunInfo gs_FrontCrossLampRunInfo =
{
    .Pwm_Posn         = 0,
    .Pwm_Self         = 0,
    .Pwm_Target       = 0,
    .Pwm_LastTarget   = 0,
    .ChannelMaskWoMtx = 0,
    .ChannelMaskWiMtx = 0,
    .Ownership = E_FrontCrossLampOwnership_Self,
    .RunState  = E_FrontCrossLampRunState_Run,
    .TacticN_1    = 0,
    .OnRampTime   = 0,
    .OffRampTime  = 0,
    .OnDelayTime  = 0,
    .OffDelayTime = 0
};

// static S_LF_Info_T gs_LF_Info_FrontCrossLamp;

/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/

/* 读取前贯穿灯参数配置并存放 */
static Std_ReturnType FrontCrossLamp_GetParameterIntoInfo(void)
{
    Std_ReturnType rtval = E_OK;

    switch( Get_pFrntCrossAvl() )
    {
        case 0:
            gs_FrontCrossLampConfigInfo.LampAvl = E_FrontCrossLampAvl_NotAvl;
            break;
        case 1:
            gs_FrontCrossLampConfigInfo.LampAvl = E_FrontCrossLampAvl_Left;
            break;
        case 2:
            gs_FrontCrossLampConfigInfo.LampAvl = E_FrontCrossLampAvl_Right;
            break;
        case 3:
            gs_FrontCrossLampConfigInfo.LampAvl = E_FrontCrossLampAvl_Both;
    }
    gs_FrontCrossLampConfigInfo.SelfIntensityDuty = Get_pLedIntensCrossLDuty();
    gs_FrontCrossLampConfigInfo.LedGamma      = (E_LedGamma)Get_pLedGamma();
    switch( gs_FrontCrossLampConfigInfo.LedGamma )
    {
        case E_LedGamma_Step:
            gs_FrontCrossLampConfigInfo.SelfOnRampTime  = 0;
            gs_FrontCrossLampConfigInfo.SelfOffRampTime = 0;
            gs_FrontCrossLampConfigInfo.PosnOnRampTime  = 0;
            gs_FrontCrossLampConfigInfo.PosnOffRampTime = 0;
            break;

        case E_LedGamma_Linear:
        case E_LedGamma_Exponent:
            gs_FrontCrossLampConfigInfo.SelfOnRampTime  = Get_pLedOnRampTi(E_FrontCrossLamp);
            gs_FrontCrossLampConfigInfo.SelfOffRampTime = Get_pLedOffRampTi(E_FrontCrossLamp);
            gs_FrontCrossLampConfigInfo.PosnOnRampTime  = Get_pLedOnRampTi(E_PositionLight);
            gs_FrontCrossLampConfigInfo.PosnOffRampTime = Get_pLedOffRampTi(E_PositionLight);
    }
    gs_FrontCrossLampConfigInfo.SelfOnDelayTime  = Get_pLedONDelay(E_FrontCrossLamp);
    gs_FrontCrossLampConfigInfo.SelfOffDelayTime = Get_pLedOFFDelay(E_FrontCrossLamp);
    gs_FrontCrossLampConfigInfo.PosnOnDelayTime  = Get_pLedONDelay(E_PositionLight);
    gs_FrontCrossLampConfigInfo.PosnOffDelayTime = Get_pLedOFFDelay(E_PositionLight);

    gs_FrontCrossLampConfigInfo.PosnIntensityDuty = Get_pLedIntensPosLDuty();
    gs_FrontCrossLampConfigInfo.PartOfPosn        = Get_pFrontCrossPositionlamp();

    return rtval;
}


/* 贯穿灯硬件归属权仲裁 */
static Std_ReturnType FrontCrossLamp_Ownership(void)
{
    Std_ReturnType rtval = E_OK;

    if(gs_FrontCrossLampConfigInfo.PartOfPosn == 1u)
    {
        static uint8_t FrontCrossLamp_ActStaCurr = 0;
        static uint8_t FrontCrossLamp_ActStaLast = 0;
        static uint8_t PositionLight_ActStaCurr = 0;
        static uint8_t PositionLight_ActStaLast = 0;

        FrontCrossLamp_ActStaLast = FrontCrossLamp_ActStaCurr;
        PositionLight_ActStaLast = PositionLight_ActStaCurr;

        if(gs_FrontCrossLampRunInfo.Pwm_Self > 0)
        {
            FrontCrossLamp_ActStaCurr = 1;
        }
        else
        {
            FrontCrossLamp_ActStaCurr = 0;
        }
        if(gs_FrontCrossLampRunInfo.Pwm_Posn > 0)
        {
            PositionLight_ActStaCurr = 1;
        }
        else
        {
            PositionLight_ActStaCurr = 0;
        }

        if(FrontCrossLamp_ActStaCurr == 1 && PositionLight_ActStaCurr == 1)
        {
            gs_FrontCrossLampRunInfo.Ownership = E_FrontCrossLampOwnership_Posn;
        }
        else if(FrontCrossLamp_ActStaCurr == 1 && PositionLight_ActStaCurr == 0)
        {
            gs_FrontCrossLampRunInfo.Ownership = E_FrontCrossLampOwnership_Self;
        }
        else if(FrontCrossLamp_ActStaCurr == 0 && PositionLight_ActStaCurr == 1)
        {
            gs_FrontCrossLampRunInfo.Ownership = E_FrontCrossLampOwnership_Posn;
        }
        else if(FrontCrossLamp_ActStaCurr == 0 && PositionLight_ActStaCurr == 0)
        {
            if(FrontCrossLamp_ActStaLast == 1 && PositionLight_ActStaLast == 1)
            {
                gs_FrontCrossLampRunInfo.Ownership = E_FrontCrossLampOwnership_Posn;
            }
            else if(FrontCrossLamp_ActStaLast == 1 && PositionLight_ActStaLast == 0)
            {
                gs_FrontCrossLampRunInfo.Ownership = E_FrontCrossLampOwnership_Self;
            }
            else if(FrontCrossLamp_ActStaLast == 0 && PositionLight_ActStaLast == 1)
            {
                gs_FrontCrossLampRunInfo.Ownership = E_FrontCrossLampOwnership_Posn;
            }
        }
    }
    else
    {
        gs_FrontCrossLampRunInfo.Ownership = E_FrontCrossLampOwnership_Self;
    }

    if(gs_FrontCrossLampRunInfo.Ownership == E_FrontCrossLampOwnership_Self)
    {
        gs_FrontCrossLampRunInfo.TacticN_1    = Get_LightN_1() & 0x0400;
        gs_FrontCrossLampRunInfo.OnRampTime   = gs_FrontCrossLampConfigInfo.SelfOnRampTime;
        gs_FrontCrossLampRunInfo.OffRampTime  = gs_FrontCrossLampConfigInfo.SelfOffRampTime;
        gs_FrontCrossLampRunInfo.OnDelayTime  = gs_FrontCrossLampConfigInfo.SelfOnDelayTime;
        gs_FrontCrossLampRunInfo.OffDelayTime = gs_FrontCrossLampConfigInfo.SelfOffDelayTime;
    }
    else if(gs_FrontCrossLampRunInfo.Ownership == E_FrontCrossLampOwnership_Posn)
    {
        gs_FrontCrossLampRunInfo.TacticN_1    = Get_LightN_1() & 0x0020;
        gs_FrontCrossLampRunInfo.OnRampTime   = gs_FrontCrossLampConfigInfo.PosnOnRampTime;
        gs_FrontCrossLampRunInfo.OffRampTime  = gs_FrontCrossLampConfigInfo.PosnOffRampTime;
        gs_FrontCrossLampRunInfo.OnDelayTime  = gs_FrontCrossLampConfigInfo.PosnOnDelayTime;
        gs_FrontCrossLampRunInfo.OffDelayTime = gs_FrontCrossLampConfigInfo.PosnOffDelayTime;
    }
    return rtval;
}

/* 贯穿灯运行 */
static Std_ReturnType FrontCrossLamp_Run(uint8_t timebase)
{
    Std_ReturnType rtval = E_OK;

  
    return rtval;
}

/* 打开贯穿灯 */
static Std_ReturnType FrontCrossLamp_SwitchON(void)
{
    Std_ReturnType rtval = E_OK;

    gs_FrontCrossLampRunInfo.Pwm_Self = 100 * gs_FrontCrossLampConfigInfo.SelfIntensityDuty / 100;
    return rtval;
}

/* 关闭贯穿灯 */
static Std_ReturnType FrontCrossLamp_SwitchOFF(void)
{
    Std_ReturnType rtval = E_OK;

    gs_FrontCrossLampRunInfo.Pwm_Self = 0;
    return rtval;
}


/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/

/* 前贯穿灯启动初始化 */
void FrontCrossLamp_Init(void)
{
    FrontCrossLamp_GetParameterIntoInfo();
    // lampM_GetLampInfo(E_FrontCrossLamp, &gs_LF_Info_FrontCrossLamp);
}

/* 前贯穿灯主函数 */
void FrontCrossLamp_MainFunction(uint8_t timebase)
{
    // if(gs_LF_Info_FrontCrossLamp.chnMask == 0) /* 没有该灯光配置，直接退出 */
    // {
    //     return;
    // }
    
#if HCM_LEFT_SIDE

    if(gs_FrontCrossLampConfigInfo.LampAvl == E_FrontCrossLampAvl_Left || gs_FrontCrossLampConfigInfo.LampAvl == E_FrontCrossLampAvl_Both)
    {
        S_LgtActIns_t LgtActIns;
        GetLgtActIns(& LgtActIns);

        if(LgtActIns.ActCROS)
        {
            FrontCrossLamp_SwitchON();
        }
        else
        {
            FrontCrossLamp_SwitchOFF();
        }
        if(gs_FrontCrossLampConfigInfo.PartOfPosn == 1u)
        {
            if(LgtActIns.ActPOS)
            {
                gs_FrontCrossLampRunInfo.Pwm_Posn = 100 * gs_FrontCrossLampConfigInfo.PosnIntensityDuty / 100;
            }
            else
            {
                gs_FrontCrossLampRunInfo.Pwm_Posn = 0;
            }
        }
        FrontCrossLamp_Run(timebase);
    }

#elif HCM_RIGHT_SIDE

    if(gs_FrontCrossLampConfigInfo.LampAvl == E_FrontCrossLampAvl_Right || gs_FrontCrossLampConfigInfo.LampAvl == E_FrontCrossLampAvl_Both)
    {
        S_LgtActIns_t LgtActIns;
        GetLgtActIns(& LgtActIns);

        if(LgtActIns.ActCROS)
        {
            FrontCrossLamp_SwitchON();
        }
        else
        {
            FrontCrossLamp_SwitchOFF();
        }
        if(gs_FrontCrossLampConfigInfo.PartOfPosn == 1u)
        {
            if(LgtActIns.ActPOS)
            {
                gs_FrontCrossLampRunInfo.Pwm_Posn = 100 * gs_FrontCrossLampConfigInfo.PosnIntensityDuty / 100;
            }
            else
            {
                gs_FrontCrossLampRunInfo.Pwm_Posn = 0;
            }
        }
        FrontCrossLamp_Run(timebase);
    }

#endif
}


