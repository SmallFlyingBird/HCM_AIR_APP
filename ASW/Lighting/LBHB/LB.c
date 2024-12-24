
#include "HcmPlatform.h"
#include "LB.h"
#include "Channel_Interface.h"
#include "Parameter_Interface.h"
#include "BD18397_Interface.h"

static S_LowBeamConfigInfo gs_lowbeamConfigInfo;
static S_LowBeamRunInfo gs_LowBeamRunInfo;

void LowBeam_GetParameterIntoInfo(void)
{
    gs_lowbeamConfigInfo.LBChannelMask = GetChannelMaskByLightFunction(E_LowBeamKink) & 0xFFF;
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
            gs_lowbeamConfigInfo.SelfOnRampTime  = Get_pLedOnRampTi(E_LowBeamKink);
            gs_lowbeamConfigInfo.SelfOffRampTime = Get_pLedOffRampTi(E_LowBeamKink);
            break;
    }
    gs_lowbeamConfigInfo.SelfOnDelayTime  = Get_pLedONDelay(E_LowBeamKink);
    gs_lowbeamConfigInfo.SelfOffDelayTime = Get_pLedOFFDelay(E_LowBeamKink);
}

/* 近光启动初始化 */
void LowBeam_Init(void)
{
    LowBeam_GetParameterIntoInfo();
}
