#include "LinManager.h"


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
	Rte_Com_Lin_HcmlZcud_Lin2Fr01(pt);
}
#endif

#ifdef RightAir
void LIN_SetDTC_Fun(void)
{
	HcmrZcud_Lin2Fr01_Msg_Type pt;
    lightsts.Light_Status=Lighting_Rek_Fun();

    pt.sig.StsOfLedCornrgLampwithLINRi = lightsts.Bits.StsCORN;
    pt.sig.StsOfLedDaytiRunngLampWithLINRi = lightsts.Bits.StsDRL;
    pt.sig.StsOfLedFrntFogLampWithLINRi = 0;
    pt.sig.StsOfLedFrntPosnLampWithLINRi = lightsts.Bits.StsPOS;

    pt.sig.StsOfLedFrntTurnIndcrWithLINRi = lightsts.Bits.StsTI;
    pt.sig.StsOfLedHiBeamWithLINRi = lightsts.Bits.StsHB;
    pt.sig.StsOfLedLoBeamWithLINRi = lightsts.Bits.StsLB;
    pt.sig.StsOfWelGbyFrntWithLINRi = lightsts.Bits.StsWELC;
    
    pt.sig.ErrRespHCMR =0;

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
        uint8 sts=0,act=0;
        sts=Rte_Com_Lin_ZcudZcud_Lin2Fr01().sig.IndcrSts;
        act=Rte_Com_Lin_ZcudZcud_Lin2Fr01().sig.ActvnOfIndcrIndcrOut;

        if(((sts==act)&&(sts!=0))||((act==0)&&(sts!=0)))
        {
        #ifdef LeftAir
            sts&=0x01;  
            act&=0x01;  
        #endif
        #ifdef RightAir
            sts&=0x02; 
            act&=0x02; 
        #endif
            rtval=sts<<2 | act;
        }
        else
        {
            rtval=0;
        }
		break;
	case E_FrontCrossLamp:
		rtval = Rte_Com_Lin_ZcudZcud_Lin2Fr01().sig.ActnOfLedFrntCrossLamp;
		break;
    default :
    break;
	}
	return rtval;
}


Std_ReturnType Interface_GetSignal_PosnLampDyn(void)
{
    return Rte_Com_Lin_ZcudZcud_Lin2Fr01().sig.ActnOfLedPosnLampDyn;
}





