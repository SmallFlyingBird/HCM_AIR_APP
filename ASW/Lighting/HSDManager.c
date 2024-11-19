

#include "HcmPlatform.h"
#include "GeneralFunction.h"
#include "Parameter_Interface.h"

#include "HighSide_Interface.h"

typedef struct _HsdM_
{
    /* 是否可自由控制? */
    uint8_t     pr_bCtlHS0  :1;
    uint8_t     pr_bCtlHS1  :1;
    uint8_t     pr_bCtlHS2  :1;
    uint8_t     pr_bCtlHS3  :1;
    /* 自由控制开关 */
    uint8_t     st_bHS0_Fan     :1; /* control HS out */
    uint8_t     st_bHS1_        :1; /* control HS out */
    uint8_t     st_bHS2_        :1; /* control HS out */
    uint8_t     st_bHS3_        :1; /* control HS out */
}S_HsdM_t;

static S_HsdM_t hsdm, *_ctl = 0;


void HsdM_Init(void)
{
    uint16_t HSFuncFlag[6] = 0; /* 高边选配功能 */

    HSFuncFlag[0] = GetChannelMaskByLightFunction(E_LogoLamp);
    HSFuncFlag[1] = GetChannelMaskByLightFunction(E_Fan2);
    HSFuncFlag[2] = GetChannelMaskByLightFunction(E_SideMarkerLamp);
    HSFuncFlag[3] = GetChannelMaskByLightFunction(E_DynamicLightCircuit);
    HSFuncFlag[4] = GetChannelMaskByLightFunction(E_DC_Motor);
    HSFuncFlag[5] = GetChannelMaskByLightFunction(E_LMM_Supply);

    hsdm.pr_bCtlHS0 = 0;
    hsdm.pr_bCtlHS1 = 0;
    hsdm.pr_bCtlHS2 = 0;
    hsdm.pr_bCtlHS3 = 0;

    /* 根据功能配置 判断是否可自由控制 */
    if (Get_pFanNumber() == 1)
    { hsdm.pr_bCtlHS0 = 1; }

    if (((HSFuncFlag[0] & 0x1000) == 0) &&
        ((HSFuncFlag[1] & 0x1000) == 0) &&
        ((HSFuncFlag[2] & 0x1000) == 0) &&
        ((HSFuncFlag[3] & 0x1000) == 0) &&
        ((HSFuncFlag[4] & 0x1000) == 0) &&
        ((HSFuncFlag[5] & 0x1000) == 0))
    { hsdm.pr_bCtlHS1 = 1; }

    if (((HSFuncFlag[0] & 0x2000) == 0) &&
        ((HSFuncFlag[1] & 0x2000) == 0) &&
        ((HSFuncFlag[2] & 0x2000) == 0) &&
        ((HSFuncFlag[3] & 0x2000) == 0) &&
        ((HSFuncFlag[4] & 0x2000) == 0) &&
        ((HSFuncFlag[5] & 0x2000) == 0))
    { hsdm.pr_bCtlHS2 = 1; }

    if (((HSFuncFlag[0] & 0x4000) == 0) &&
        ((HSFuncFlag[1] & 0x4000) == 0) &&
        ((HSFuncFlag[2] & 0x4000) == 0) &&
        ((HSFuncFlag[3] & 0x4000) == 0) &&
        ((HSFuncFlag[4] & 0x4000) == 0) &&
        ((HSFuncFlag[5] & 0x4000) == 0))
    { hsdm.pr_bCtlHS3 = 1; }

    hsdm.st_bHS0_Fan = 0;
    hsdm.st_bHS1_ = 0;
    hsdm.st_bHS2_ = 0;
    hsdm.st_bHS3_ = 0;

    _ctl = &hsdm;
}

void HsdM_Exit(void)
{

    
    _ctl = 0;
}

void HsdM_Run10ms(void)
{
    if (_ctl == 0) { return; }

#if (QINGHAIGANG) && (QHG_DMONI_orXCP)
    if (((dmoni_rx[D_EPTEST][0] & 0x7e) >> 1) == D_EPTEST)
    {
        if ((dmoni_rx[D_EPTEST][3] & 0x01) != 0) { _ctl->st_bHS0_Fan = 1; }
        else                                     { _ctl->st_bHS0_Fan = 0; }
        if ((dmoni_rx[D_EPTEST][3] & 0x02) != 0) { _ctl->st_bHS1_    = 1; }
        else                                     { _ctl->st_bHS1_    = 0; }
        if ((dmoni_rx[D_EPTEST][3] & 0x04) != 0) { _ctl->st_bHS2_    = 1; }
        else                                     { _ctl->st_bHS2_    = 0; }
        if ((dmoni_rx[D_EPTEST][3] & 0x08) != 0) { _ctl->st_bHS3_    = 1; }
        else                                     { _ctl->st_bHS3_    = 0; }
    }

    if (_ctl->pr_bCtlHS0) { Interface_SetHighSideState(E_HSChannel_HS0, (E_HSDChannelSwitchState)(_ctl->st_bHS0_Fan)); }
    if (_ctl->pr_bCtlHS1) { Interface_SetHighSideState(E_HSChannel_HS1, (E_HSDChannelSwitchState)(_ctl->st_bHS1_)); }
    if (_ctl->pr_bCtlHS2) { Interface_SetHighSideState(E_HSChannel_HS2, (E_HSDChannelSwitchState)(_ctl->st_bHS2_)); }
    if (_ctl->pr_bCtlHS3) { Interface_SetHighSideState(E_HSChannel_HS3, (E_HSDChannelSwitchState)(_ctl->st_bHS3_)); }
#endif  /* (QINGHAIGANG) && (QHG_DMONI_orXCP) */

}



