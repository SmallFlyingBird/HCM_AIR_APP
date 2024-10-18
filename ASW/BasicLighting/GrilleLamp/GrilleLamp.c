/********************************
 * GrilleLamp.c
 *
 *  Created on: 2024/4/17
 *      Author: tujiongjiong
 ********************************/


/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "GrilleLamp.h"

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
/****************************************************************
 *                                                              *
 *                   Global Variable Define                     *
 *                                                              *
 ****************************************************************/
static S_GrilleLampConfigInfo gs_GrilleLampConfigInfo;
static S_GrilleLampRunInfo gs_GrilleLampRunInfo =
{
    .Pwm_Basic        = 0,
    .Pwm_Target       = 0,
    .Pwm_LastTarget   = 0,
    .ChannelMaskWoMtx = 0,
    .ChannelMaskWiMtx = 0,
    .GrilleLampRunState = E_GrilleLampRunState_Run
};

static S_LF_Info_T gs_LF_Info_GrilleLamp;

/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/

/* 读取格栅灯参数配置并存放 */
static Std_ReturnType GrilleLamp_GetParameterIntoInfo(void)
{
    Std_ReturnType rtval = E_OK;

    switch( Get_pGrilleAvl() )
    {
        case 0:
            gs_GrilleLampConfigInfo.LampAvl = E_GrilleLampAvl_NotAvl;
            break;
        case 1:
            gs_GrilleLampConfigInfo.LampAvl = E_GrilleLampAvl_Left;
            break;
        case 2:
            gs_GrilleLampConfigInfo.LampAvl = E_GrilleLampAvl_Right;
            break;
        case 3:
            gs_GrilleLampConfigInfo.LampAvl = E_GrilleLampAvl_Both;
    }
    gs_GrilleLampConfigInfo.IntensityDuty = Get_pLedIntensCrossLDuty();
    gs_GrilleLampConfigInfo.LedGamma      = (E_LedGamma)Get_pLedGamma();
    switch( gs_GrilleLampConfigInfo.LedGamma )
    {
        case E_LedGamma_Step:
            gs_GrilleLampConfigInfo.OnRampTime  = 0;
            gs_GrilleLampConfigInfo.OffRampTime = 0;
            break;

        case E_LedGamma_Linear:
        case E_LedGamma_Exponent:
            gs_GrilleLampConfigInfo.OnRampTime  = Get_pLedOnRampTi(E_GrilleLamp);
            gs_GrilleLampConfigInfo.OffRampTime = Get_pLedOffRampTi(E_GrilleLamp);
    }
    gs_GrilleLampConfigInfo.OnDelayTime   = Get_pLedONDelay(E_GrilleLamp);
    gs_GrilleLampConfigInfo.OffDelayTime  = Get_pLedOFFDelay(E_GrilleLamp);

    return rtval;
}

/* 格栅灯运行 */
static Std_ReturnType GrilleLamp_Run(uint8_t timebase)
{
    Std_ReturnType rtval = E_OK;

    gs_GrilleLampRunInfo.Pwm_LastTarget = gs_GrilleLampRunInfo.Pwm_Target;
    gs_GrilleLampRunInfo.Pwm_Target = gs_GrilleLampRunInfo.Pwm_Basic;

    /* 判断是否是开关灯前 */
    if(gs_GrilleLampRunInfo.Pwm_LastTarget != gs_GrilleLampRunInfo.Pwm_Target)
    {
        if(gs_GrilleLampRunInfo.Pwm_LastTarget == 0 && gs_GrilleLampRunInfo.Pwm_Target > 0)
        {
            gs_GrilleLampRunInfo.ChannelMaskWoMtx = gs_LF_Info_GrilleLamp.chnMask ^ gs_LF_Info_GrilleLamp.mtxMask; /* 开灯前读取一次通道掩码 */
            gs_GrilleLampRunInfo.ChannelMaskWiMtx = gs_LF_Info_GrilleLamp.mtxMask;

            gs_GrilleLampRunInfo.GrilleLampRunState = E_GrilleLampRunState_OnDelay;
        }
        else if(gs_GrilleLampRunInfo.Pwm_LastTarget > 0 && gs_GrilleLampRunInfo.Pwm_Target == 0)
        {
            gs_GrilleLampRunInfo.GrilleLampRunState = E_GrilleLampRunState_OffDelay;
        }
    }

    /* 排除故障的LED通道 */
    if(gs_GrilleLampRunInfo.Pwm_Target)
    {
        U_DisSrc_t GrilleLampDerateSta;

        GetLgtFuncDisSrc_GRIL(& GrilleLampDerateSta); /* 降额状态 */
        if( GrilleLampDerateSta.bits.sp_los == 1u ||
            GrilleLampDerateSta.bits.sp_ouv == 1u ||
            GrilleLampDerateSta.bits.ot_chn == 1u ||
            GrilleLampDerateSta.bits.ot_led == 1u ||
            GrilleLampDerateSta.bits.ot_amb == 1u ) /* 格栅灯开启降额 */
        {
            LampM_SetLampChn(E_GrilleLamp, gs_GrilleLampRunInfo.ChannelMaskWoMtx, 0, 0, 0); /* 立即关闭所有LED通道并返回 */
            LampM_SetLampChn(E_GrilleLamp, gs_GrilleLampRunInfo.ChannelMaskWiMtx, 0, 0, 0);
            return rtval;
        }
        else /* 格栅灯没有降额 */
        {
            uint16_t ErrorChannelWoMtxMask = 0;
            uint16_t ErrorChannelWiMtxMask = 0;
            S_LF_Err_T DTCErrMask;

            LampM_GetLampBaseErr_DTC(& DTCErrMask); /* LED通道DTC故障 */
            ErrorChannelWoMtxMask = gs_GrilleLampRunInfo.ChannelMaskWoMtx & DTCErrMask.chnErr; /* 剩余LED通道出现了新故障 */
            ErrorChannelWiMtxMask = gs_GrilleLampRunInfo.ChannelMaskWiMtx & DTCErrMask.chnErr;
            if(Get_LightN_1() & 0x0800) /* 有N-1策略 */
            {
                if(ErrorChannelWoMtxMask || ErrorChannelWiMtxMask)
                {
                    ErrorChannelWoMtxMask = gs_GrilleLampRunInfo.ChannelMaskWoMtx;
                    ErrorChannelWiMtxMask = gs_GrilleLampRunInfo.ChannelMaskWiMtx;
                }
            }
            gs_GrilleLampRunInfo.ChannelMaskWoMtx ^= ErrorChannelWoMtxMask; /* 逐步屏蔽故障的LED通道 */
            gs_GrilleLampRunInfo.ChannelMaskWiMtx ^= ErrorChannelWiMtxMask; /* 逐步屏蔽故障的LED通道 */
            LampM_SetLampChn(E_GrilleLamp, ErrorChannelWoMtxMask, 0, 0, 0); /* 立即关闭无矩阵故障LED通道，关闭后下一次就读不到该故障 */
            LampM_SetLampChn(E_GrilleLamp, ErrorChannelWiMtxMask, 0, 0, 0); /* 立即关闭有矩阵故障LED通道，关闭后下一次就读不到该故障 */
        }
    }

    uint8_t PixelNum;
    static uint8_t GrilleLamp_OnDelayTime = 0;
    static uint8_t GrilleLamp_OffDelayTime = 0;

    switch( gs_GrilleLampRunInfo.GrilleLampRunState )
    {
        case E_GrilleLampRunState_OnDelay:
            GrilleLamp_OnDelayTime += timebase;
            if(GrilleLamp_OnDelayTime >= gs_GrilleLampConfigInfo.OnDelayTime)
            {
                GrilleLamp_OnDelayTime = 0;
                gs_GrilleLampRunInfo.GrilleLampRunState = E_GrilleLampRunState_Run;
            }
            break;

        case E_GrilleLampRunState_OffDelay:
            GrilleLamp_OffDelayTime += timebase;
            if(GrilleLamp_OffDelayTime >= gs_GrilleLampConfigInfo.OffDelayTime)
            {
                GrilleLamp_OffDelayTime = 0;
                gs_GrilleLampRunInfo.GrilleLampRunState = E_GrilleLampRunState_Run;
            }
            break;

        case E_GrilleLampRunState_Run:
            LampM_SetLampChn(E_GrilleLamp, gs_GrilleLampRunInfo.ChannelMaskWoMtx, gs_GrilleLampRunInfo.Pwm_Target, gs_GrilleLampConfigInfo.OnRampTime, gs_GrilleLampConfigInfo.OffRampTime);
            LampM_SetLampChn(E_GrilleLamp, gs_GrilleLampRunInfo.ChannelMaskWiMtx, 100, 0, 0);
            for(PixelNum = 1; PixelNum <= gs_LF_Info_GrilleLamp.lednum; PixelNum++)
            {
                LampM_SetLampPix(E_GrilleLamp, PixelNum, gs_GrilleLampRunInfo.Pwm_Target, gs_GrilleLampConfigInfo.OnRampTime, gs_GrilleLampConfigInfo.OffRampTime);
            }
    }
    return rtval;
}

/* 打开格栅灯 */
static Std_ReturnType GrilleLamp_SwitchON(void)
{
    Std_ReturnType rtval = E_OK;

    gs_GrilleLampRunInfo.Pwm_Basic = 100 * gs_GrilleLampConfigInfo.IntensityDuty / 100;
    return rtval;
}

/* 关闭格栅灯 */
static Std_ReturnType GrilleLamp_SwitchOFF(void)
{
    Std_ReturnType rtval = E_OK;

    gs_GrilleLampRunInfo.Pwm_Basic = 0;
    return rtval;
}


/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/

/* 格栅灯启动初始化 */
void GrilleLamp_Init(void)
{
    GrilleLamp_GetParameterIntoInfo();
    lampM_GetLampInfo(E_GrilleLamp, &gs_LF_Info_GrilleLamp);
}

/* 格栅灯主函数 */
void GrilleLamp_MainFunction(uint8_t timebase)
{
    if(gs_LF_Info_GrilleLamp.chnMask == 0) /* 没有该灯光配置，直接退出 */
    {
        return;
    }

#if HCM_LEFT_SIDE

    if(gs_GrilleLampConfigInfo.LampAvl == E_GrilleLampAvl_Left || gs_GrilleLampConfigInfo.LampAvl == E_GrilleLampAvl_Both)
    {
        S_LgtActIns_t LgtActIns;
        GetLgtActIns(& LgtActIns);

        if(LgtActIns.ActGRIL)
        {
            GrilleLamp_SwitchON();
        }
        else
        {
            GrilleLamp_SwitchOFF();
        }
        GrilleLamp_Run(timebase);
    }

#elif HCM_RIGHT_SIDE

    if(gs_GrilleLampConfigInfo.LampAvl == E_GrilleLampAvl_Right || gs_GrilleLampConfigInfo.LampAvl == E_GrilleLampAvl_Both)
    {
        S_LgtActIns_t LgtActIns;
        GetLgtActIns(& LgtActIns);
        
        if(LgtActIns.ActGRIL)
        {
            GrilleLamp_SwitchON();
        }
        else
        {
            GrilleLamp_SwitchOFF();
        }
        GrilleLamp_Run(timebase);
    }

#endif
}



