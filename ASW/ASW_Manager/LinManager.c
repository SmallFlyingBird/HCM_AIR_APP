#include "LinManager.h"
#include "HcmPlatform.h"
#include "Lighting.h"
#include "Com.h"

/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
typedef union
{
    uint16 Light_Status;
    struct
    {
        uint8    StsLB       :2;
        uint8    StsTI       :2;
        uint8    StsPOS      :2;
        uint8    StsHB       :2;
        uint8    StsDRL      :2;
        uint8    StsCORN     :2;
        uint8    StsCROS     :2;
        uint8    StsWELC     :2;
    }Bits;
}S_Lin_LgtFb_t;
S_Lin_LgtFb_t lightsts;

extern uint8 *ExLin_ControlBuffPtr;
S_Lin_LControl gs_lin_ctrl;
S_Lin_HSDControl gs_lin_hsdctrl;
/****************************************************************
 *                                                              *
 *                   Global Variable Define                     *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/

void LIN_Analysis_Fun(void)
{    
//Basic light signal
    gs_lin_ctrl.Bits.LB_Ena = Rte_Com_Lin_ZcudZcud_Lin2Fr01().sig.ActnOfLedLoBeamActnOfLedLoBeam;
    gs_lin_ctrl.Bits.HB_Ena = Rte_Com_Lin_ZcudZcud_Lin2Fr01().sig.ActnOfLedHiBeam; 
    gs_lin_ctrl.Bits.CROS_Ena = Rte_Com_Lin_ZcudZcud_Lin2Fr01().sig.ActnOfLedFrntCrossLamp;
    gs_lin_ctrl.Bits.Pos_Ena = Rte_Com_Lin_ZcudZcud_Lin2Fr01().sig.ActnOfLedPosnLamp; 
    gs_lin_ctrl.Bits.Drl_Ena = Rte_Com_Lin_ZcudZcud_Lin2Fr01().sig.ActnOfLedDaytiRunngLamp; 
    gs_lin_ctrl.Bits.Turn_Act = Rte_Com_Lin_ZcudZcud_Lin2Fr01().sig.ActvnOfIndcrIndcrOut; 
    gs_lin_ctrl.Bits.Turn_Sts = Rte_Com_Lin_ZcudZcud_Lin2Fr01().sig.IndcrSts;

    /* 测试 */
    // static uint16_t s_CycleTime = 0u;

    // if (s_CycleTime >= 0 && s_CycleTime <= 20000)
    // {
    //     gs_lin_ctrl.Bits.LB_Ena = 1;
    //     gs_lin_ctrl.Bits.HB_Ena = 1;
    //     gs_lin_ctrl.Bits.CROS_Ena = 1;
    //     gs_lin_ctrl.Bits.Pos_Ena = 1;
    //     gs_lin_ctrl.Bits.Drl_Ena = 1;
    // }
    // else if (s_CycleTime >= 20001 && s_CycleTime <= 25000)
    // {
    //     gs_lin_ctrl.Bits.LB_Ena = 0;
    //     gs_lin_ctrl.Bits.HB_Ena = 0;
    //     gs_lin_ctrl.Bits.CROS_Ena = 0;
    //     gs_lin_ctrl.Bits.Pos_Ena = 0;
    //     gs_lin_ctrl.Bits.Drl_Ena = 0;
    // }
    // if (s_CycleTime < 25000)
    // {
    //     s_CycleTime += 10;
    // }
    // else
    // {
    //     s_CycleTime = 0;
    // }

    if( gs_lin_ctrl.Bits.Turn_Act==gs_lin_ctrl.Bits.Turn_Sts)
    {
    #ifdef LeftAir
        gs_lin_ctrl.Bits.Turn_Act=gs_lin_ctrl.Bits.Turn_Act&0x01;  
        gs_lin_ctrl.Bits.Turn_Sts=gs_lin_ctrl.Bits.Turn_Sts&0x01;  
    #endif
	#ifdef RightAir
        gs_lin_ctrl.Bits.Turn_Act=gs_lin_ctrl.Bits.Turn_Act&0x02; 
        gs_lin_ctrl.Bits.Turn_Sts=gs_lin_ctrl.Bits.Turn_Sts&0x02; 
    #endif
    }
    else if((gs_lin_ctrl.Bits.Turn_Act==0)&&(gs_lin_ctrl.Bits.Turn_Sts!=0))//系统需求：两个信号一致，信号有效
    {
	#ifdef LeftAir
        gs_lin_ctrl.Bits.Turn_Sts=gs_lin_ctrl.Bits.Turn_Sts&0x01;  
	#endif
    #ifdef RightAir
        gs_lin_ctrl.Bits.Turn_Sts=gs_lin_ctrl.Bits.Turn_Sts&0x02; 
    #endif
    }
    else
    {
        gs_lin_ctrl.Bits.Turn_Act=0;
        gs_lin_ctrl.Bits.Turn_Sts=0;
    }
}

S_Lin_LControl Interface_Get_LinSignal(void)
{
    return gs_lin_ctrl;
}

/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
//read back FAN LIN signal
uint8 LIN_SetFANSignal(void)
{
    return gs_lin_hsdctrl.HSD1_Ena;
}

void LIN_SetDTC_Fun(void)
{
#ifdef LeftAir
    HcmlZcud_Lin2Fr01_Msg_Type pt;
#endif
#ifdef RightAir
	HcmrZcud_Lin2Fr01_Msg_Type pt;
#endif
    lightsts.Light_Status=Lighting_Rek_Fun();

    pt.sig.StsOfLedCornrgLampwithLINLe = lightsts.Bits.StsCORN;
    pt.sig.StsOfLedDaytiRunngLampWithLINLe = lightsts.Bits.StsDRL;
    pt.sig.StsOfLedFrntFogLampWithLINLe = 0;
    pt.sig.StsOfLedFrntPosnLampWithLINLe = lightsts.Bits.StsPOS;

    pt.sig.StsOfLedFrntTurnIndcrWithLINLe = lightsts.Bits.StsTI;
    pt.sig.StsOfLedHiBeamWithLINLe = lightsts.Bits.StsHB;
    pt.sig.StsOfLedLoBeamWithLINLe = lightsts.Bits.StsLB;
    pt.sig.StsOfWelGbyFrntWithLINLe = lightsts.Bits.StsWELC;
    
    pt.sig.ErrRespHCML =0;

    pt.sig.HCML2DTCGroup1 = 0;
    pt.sig.HCML2DTCGroup2 = 0;
    pt.sig.HCML2DTCGroup3 = 0;
    pt.sig.HCML2DTCGroup4 = 0;
#ifdef LeftAir
	Rte_Com_Lin_HcmlZcud_Lin2Fr01(pt);
#endif
#ifdef RightAir
	Rte_Com_Lin_HcmrZcud_Lin2Fr01(pt);
#endif
}

void Lin_Mainfunction(uint8 timebase)
{
    LIN_Analysis_Fun();
    LIN_SetDTC_Fun();
}


