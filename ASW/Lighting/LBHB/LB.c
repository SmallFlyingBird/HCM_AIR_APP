
#include "HcmPlatform.h"
#include "LB.h"
#include "Channel_Interface.h"
#include "Parameter_Interface.h"

static S_LowBeamConfigInfo gs_lowbeamConfigInfo;
static S_LowBeamRunInfo gs_LowBeamRunInfo;

void LowBeam_GetParameterIntoInfo(void)
{
    gs_lowbeamConfigInfo.LBChannelMask = GetChannelMaskByLightFunction(E_LowBeamFlat) & 0xFFF;
    // gs_lowbeamConfigInfo.LedGamma = (E_LedGamma)Get_pLedGamma();//待参数配置表更新
    gs_lowbeamConfigInfo.LedGamma=E_LedGamma_Linear;
    switch( gs_lowbeamConfigInfo.LedGamma )
    {
        case E_LedGamma_Step:
            gs_lowbeamConfigInfo.SelfOnRampTime  = 0;
            gs_lowbeamConfigInfo.SelfOffRampTime = 0;
            break;
        case E_LedGamma_Linear:
        case E_LedGamma_Exponent:
            gs_lowbeamConfigInfo.SelfOnRampTime  = Get_pLedOnRampTi(E_LowBeamFlat);
            gs_lowbeamConfigInfo.SelfOffRampTime = Get_pLedOffRampTi(E_LowBeamFlat);
            break;
    }
    gs_lowbeamConfigInfo.SelfOnDelayTime  = Get_pLedONDelay(E_LowBeamFlat);
    gs_lowbeamConfigInfo.SelfOffDelayTime = Get_pLedOFFDelay(E_LowBeamFlat);
}

/* 近光启动初始化 */
void LowBeam_Init(void)
{
    LowBeam_GetParameterIntoInfo();
}

/* 近光灯运行 */
static Std_ReturnType LowBeam_Run(uint8_t timebase)
{
    // Std_ReturnType rtval = E_OK;

    // /* 开灯 */
    // gs_LowBeamRunInfo.Pwm_LastTarget = gs_LowBeamRunInfo.Pwm_Target;
    // if(gs_LowBeamRunInfo.Pwm_Self > 0)
    // {
    //     gs_LowBeamRunInfo.Pwm_Target = gs_LowBeamRunInfo.Pwm_Self;
    // }
    // else
    // {
    //     gs_LowBeamRunInfo.Pwm_Target = 0;
    // }

    // /* 判断是否是开关灯前 */
    // if(gs_LowBeamRunInfo.Pwm_LastTarget == 0 && gs_LowBeamRunInfo.Pwm_Target > 0)
    // {
    //     gs_LowBeamRunInfo.RunState = E_LowBeamState_OnDelay;
    // }
    // else if(gs_LowBeamRunInfo.Pwm_LastTarget > 0 && gs_LowBeamRunInfo.Pwm_Target == 0)
    // {
    //     gs_LowBeamRunInfo.RunState = E_LowBeamState_OffDelay;
    // }

    // /* 排除故障的LED通道 */
    // if(gs_LowBeamRunInfo.Pwm_Target > 0u) /* 开灯 */
    // {
    //     // U_DisSrc_t LowBeamDerateSta;

    //     // GetLgtFuncDisSrc_CORN(& LowBeamDerateSta); /* 降额状态 */
    //     // if( LowBeamDerateSta.bits.sp_los == 1u ||
    //     //     LowBeamDerateSta.bits.sp_ouv == 1u ||
    //     //     LowBeamDerateSta.bits.ot_chn == 1u ||
    //     //     LowBeamDerateSta.bits.ot_led == 1u ||
    //     //     LowBeamDerateSta.bits.ot_amb == 1u ) /* 开启降额 */
    //     // {
    //     //     LampM_SetLampChn(E_LowBeam, gs_LowBeamConfigInfo.CLChannelMask, 0, 0, 0); /* 立即关闭所有LED通道并返回 */
    //     //     return rtval;
    //     // }
    //     // else /* 没有降额 */
    //     // {
    //     //     S_LF_Err_T DTCErrMask;

    //     //     LampM_GetLampBaseErr_DTC(& DTCErrMask); /* LED通道DTC故障 */
    //     //     if(gs_LowBeamRunInfo.TacticN_1) /* 有N-1策略 */
    //     //     {
    //     //         if(gs_LowBeamConfigInfo.CLChannelMask & DTCErrMask.chnErr)
    //     //         {
    //     //             gs_LowBeamRunInfo.ErrChnlMask = gs_LowBeamConfigInfo.CLChannelMask;
    //     //         }
    //     //     }
    //     //     else
    //     //     {
    //     //         gs_LowBeamRunInfo.ErrChnlMask |= gs_LowBeamConfigInfo.CLChannelMask & DTCErrMask.chnErr;
    //     //     }
    //     //     gs_LowBeamRunInfo.NmlChnlMask = gs_LowBeamConfigInfo.CLChannelMask ^ gs_LowBeamRunInfo.ErrChnlMask;
    //     // }
    // }
    // else /* 关灯 */
    // {
    //     // gs_LowBeamRunInfo.ErrChnlMask = 0u;
    //     // gs_LowBeamRunInfo.NmlChnlMask = gs_LowBeamConfigInfo.CLChannelMask;
    // }

    // static uint8_t LowBeam_OnDelayTime = 0;
    // static uint8_t LowBeam_OffDelayTime = 0;
    // gs_LowBeamRunInfo.RunState=E_LowBeamState_Run;
    // switch( gs_LowBeamRunInfo.RunState )
    // {
    //     case E_LowBeamState_OnDelay:
    //         LowBeam_OnDelayTime += timebase;
    //         if(LowBeam_OnDelayTime >= gs_LowBeamRunInfo.OnDelayTime)
    //         {
    //             LowBeam_OnDelayTime = 0;
    //             gs_LowBeamRunInfo.RunState = E_LowBeamState_Run;
    //         }
    //         break;

    //     case E_LowBeamState_OffDelay:
    //         LowBeam_OffDelayTime += timebase;
    //         if(LowBeam_OffDelayTime >= gs_LowBeamRunInfo.OffDelayTime)
    //         {
    //             LowBeam_OffDelayTime = 0;
    //             gs_LowBeamRunInfo.RunState = E_LowBeamState_Run;
    //         }
    //         break;

    //     case E_LowBeamState_Run:
    //     {
    //         // for (i=0; i<MAX_CHANNLE_NUM; i++)
    //         // {
    //         //     if ((lampctl.chnMask & (0x0001 << i)) != 0)
    //         //     {
    //         //     }
    //         // }
    //         Interface_SetChannelSwitchState((E_ChannelID)ChannelID1, 0); 
    //         /* 设置通道电流 */
    //         Interface_SetChannelCurrent((E_ChannelID)ChannelID1, 250);
    //     }break;
    // }
    // return rtval;
}
#include "BD18397_Interface.h"

/* 近光主函数 */
void LowBeam_MainFunction(uint8_t timebase)
{
    // static uint8_t ActnOfLedLowBeam_Curr = 0; //当前近光灯的开关状态
    // static uint8_t ActnOfLedLowBeam_Last = 0; //上一次近光灯的开关状态

    // static uint16 LowBeamInfo_OnRampTime = 0;
    // static uint16 LowBeamInfo_OffRampTime = 0;

    // if(gs_lowbeamConfigInfo.LBChannelMask == 0) /* 没有该灯光配置，直接退出 */
    // {
    //     return;
    // }
    
    // LowBeam_Run(timebase);


}