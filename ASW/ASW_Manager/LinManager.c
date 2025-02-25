#include "LinManager.h"
#include "TurnIndicator.h"

/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/

extern uint8 *ExLin_ControlBuffPtr;
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
#ifdef LeftAir
void LIN_SetDTC_Fun(void)
{
    HcmlZcud_Lin2Fr01_Msg_Type pt;
    S_LgtStsFb_t lightsts;
    lightsts.Light_Status=Lighting_Rek_Fun();

    pt.sig.StsOfLedCornrgLampwithLINLe = lightsts.Bits.StsCORN; 
    pt.sig.StsOfLedDaytiRunngLampWithLINLe = lightsts.Bits.StsDRL; 
    pt.sig.StsOfLedFrntFogLampWithLINLe = lightsts.Bits.StsFOG; 
    pt.sig.StsOfLedFrntPosnLampWithLINLe = lightsts.Bits.StsPOS; 

    pt.sig.StsOfLedFrntTurnIndcrWithLINLe = lightsts.Bits.StsTI;
    pt.sig.StsOfLedHiBeamWithLINLe = lightsts.Bits.StsHB;
    pt.sig.StsOfLedLoBeamWithLINLe = lightsts.Bits.StsLB;
    pt.sig.StsOfWelGbyFrntWithLINLe = lightsts.Bits.StsWELC;
    
    pt.sig.ErrRespHCML = TransmErrorFlag;

    pt.sig.HCML2DTCGroup1 = 0; 
    pt.sig.HCML2DTCGroup2 = 0; 
    pt.sig.HCML2DTCGroup3 = 0;
    pt.sig.HCML2DTCGroup4 = 0; 
	Rte_Com_Lin_HcmlZcud_Lin2Fr01(pt);
}
#endif

#ifdef RightAir
void LIN_SetDTC_Fun(void)
{
	HcmrZcud_Lin2Fr01_Msg_Type pt;
    S_LgtStsFb_t lightsts;
    lightsts.Light_Status=Lighting_Rek_Fun();

    pt.sig.StsOfLedCornrgLampwithLINRi = lightsts.Bits.StsCORN;
    pt.sig.StsOfLedDaytiRunngLampWithLINRi = lightsts.Bits.StsDRL;
    pt.sig.StsOfLedFrntFogLampWithLINRi =  lightsts.Bits.StsFOG;
    pt.sig.StsOfLedFrntPosnLampWithLINRi = lightsts.Bits.StsPOS;

    pt.sig.StsOfLedFrntTurnIndcrWithLINRi = lightsts.Bits.StsTI;
    pt.sig.StsOfLedHiBeamWithLINRi = lightsts.Bits.StsHB;
    pt.sig.StsOfLedLoBeamWithLINRi = lightsts.Bits.StsLB;
    pt.sig.StsOfWelGbyFrntWithLINRi = lightsts.Bits.StsWELC;
    
    pt.sig.ErrRespHCMR = TransmErrorFlag;

    pt.sig.HCMR2DTCGroup1 = 0;
    pt.sig.HCMR2DTCGroup2 = 0;
    pt.sig.HCMR2DTCGroup3 = 0;
    pt.sig.HCMR2DTCGroup4 = 0;
	Rte_Com_Lin_HcmrZcud_Lin2Fr01(pt);
}
#endif


/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
void Lin_Mainfunction(uint8 timebase)
{
    LIN_SetDTC_Fun();
}


uint8 Lighting_GetLinCtrl(Light_Functions lf)
{
	uint16_t rtval = 0;
    uint8 sts=0,act=0;
	switch (lf)
	{
	case E_LowBeamKink:
		rtval = Rte_Com_Lin_ZcudZcud_Lin2Fr01().sig.ActnOfLedLoBeamActnOfLedLoBeam;
		break;
	case E_HighBeamSpot:
		rtval = Rte_Com_Lin_ZcudZcud_Lin2Fr01().sig.ActnOfLedHiBeam; 
		break;
	case E_DaytimeRunningLight:
		rtval = Rte_Com_Lin_ZcudZcud_Lin2Fr01().sig.ActnOfLedDaytiRunngLamp; 
		break;
	case E_PositionLight:
		rtval = Rte_Com_Lin_ZcudZcud_Lin2Fr01().sig.ActnOfLedPosnLamp; 
		break;
	case E_TurnIndicator:     
        sts=Rte_Com_Lin_ZcudZcud_Lin2Fr01().sig.IndcrSts;
        act=Rte_Com_Lin_ZcudZcud_Lin2Fr01().sig.ActvnOfIndcrIndcrOut;
        rtval=TI_LinStsActAnalysis(sts,act);
		break;
    case E_TurnIndicator_Act:
        act=Rte_Com_Lin_ZcudZcud_Lin2Fr01().sig.ActvnOfIndcrIndcrOut;
        if(act==0) rtval=0;
        else rtval=1;
    break;
	case E_FrontCrossLamp:
		rtval = Rte_Com_Lin_ZcudZcud_Lin2Fr01().sig.ActnOfLedFrntCrossLamp;
		break;
    default :
    break;
	}
	return rtval;
}


uint8 Interface_GetSignal_PosnLampDyn(void)
{
    return Rte_Com_Lin_ZcudZcud_Lin2Fr01().sig.ActnOfLedPosnLampDyn;
}

uint8 Interface_GetSignal_ClrDTCOfLINHCM(void)
{
    uint8 ctrl_dcmotor=0;
    #ifdef LeftAir
	ctrl_dcmotor = Rte_Com_Lin_ZcudZcud_Lin2Fr02().sig.ClrDTCOfLINHCML2;
	#endif
	
	#ifdef RightAir
	ctrl_dcmotor = Rte_Com_Lin_ZcudZcud_Lin2Fr02().sig.ClrDTCOfLINHCMR2;
	#endif
    return ctrl_dcmotor;
}

uint8 Interface_GetSignal_LvlgSwtSetReqLvlgSwtSetReq(void)
{
    uint8 ctrl_dcmotor=0;
	ctrl_dcmotor = Rte_Com_Lin_ZcudZcud_Lin2Fr02().sig.LvlgSwtSetReqLvlgSwtSetReq;
    return ctrl_dcmotor;
}


