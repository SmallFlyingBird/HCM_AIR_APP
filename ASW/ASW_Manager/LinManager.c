#include "LinManager.h"
#include "TurnIndicator.h"
#include "Com_Cfg.h"
#include "DTC_Interface.h"
#include "Rte_E2EXf.h"
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
    U_Ntc_Error ntcErr;
    U_Bin_Error BinErr;
    uint8 id=0;
    U_ChannelErrorState BuckErr[CHANNEL_NUM];
    U_ChannelErrorState BuckErrTotal;
    U_E2EErrorFlag LB_E2EFlag;
    U_E2EErrorFlag TI_E2EFlag;

/* get light status */
    lightsts.Light_Status=Lighting_Rek_Fun();
/* get ntc bin err */
    ntcErr = Interface_GetNtcErrorState();          //get all ntc error
    BinErr = Interface_GetBinErrorState();
    BuckErrTotal.bits.OpenError =0;
    BuckErrTotal.bits.Short2GndError =0;
    BuckErrTotal.bits.Short2VCC =0;
    BuckErrTotal.bits.UnderVoltage =0;
/* get buck err */
    for(id=0;id<CHANNEL_NUM;id++)
    {
        BuckErr[id]=Interface_GetChannelState(id);
        BuckErrTotal.bits.OpenError |= BuckErr[id].bits.OpenError;
        BuckErrTotal.bits.Short2GndError |= BuckErr[id].bits.Short2GndError;
        BuckErrTotal.bits.Short2VCC |= BuckErr[id].bits.Short2VCC;
        BuckErrTotal.bits.UnderVoltage |= BuckErr[id].bits.UnderVoltage;
    }
    
/* get functional safety */
    LB_E2EFlag=Rbk_U_E2EErrorFlag();
    TI_E2EFlag=Rbk_U_E2EErrorFlag();

    pt.sig.StsOfLedCornrgLampwithLINLe = lightsts.Bits.StsCORN; 
    pt.sig.StsOfLedDaytiRunngLampWithLINLe = lightsts.Bits.StsDRL; 
    pt.sig.StsOfLedFrntFogLampWithLINLe = lightsts.Bits.StsFOG; 
    pt.sig.StsOfLedFrntPosnLampWithLINLe = lightsts.Bits.StsPOS; 

    pt.sig.StsOfLedFrntTurnIndcrWithLINLe = lightsts.Bits.StsTI;
    pt.sig.StsOfLedHiBeamWithLINLe = lightsts.Bits.StsHB;
    pt.sig.StsOfLedLoBeamWithLINLe = lightsts.Bits.StsLB;
    pt.sig.StsOfWelGbyFrntWithLINLe = lightsts.Bits.StsWELC;
    
    pt.sig.ErrRespHCML = TransmErrorFlag;
/* DTC GROUP */
    pt.sig.HCML2DTCGroup1Bit0_WDGSafetySPI        = 0;
    pt.sig.HCML2DTCGroup1Bit1_Ntc1Bin1            = ntcErr.bits.Ntc1_OpenOrShort2Vcc_ErrorConfirmed | ntcErr.bits.Ntc1_Short2Gnd_ErrorConfirmed | BinErr.bits.Bin1ErrorConfirm; 
    pt.sig.HCML2DTCGroup1Bit2_Ntc2Bin2            = ntcErr.bits.Ntc2_OpenOrShort2Vcc_ErrorConfirmed | ntcErr.bits.Ntc2_Short2Gnd_ErrorConfirmed | BinErr.bits.Bin2ErrorConfirm; 
    pt.sig.HCML2DTCGroup1Bit3_Ntc3Bin3            = ntcErr.bits.Ntc3_OpenOrShort2Vcc_ErrorConfirmed | ntcErr.bits.Ntc3_Short2Gnd_ErrorConfirmed | BinErr.bits.Bin3ErrorConfirm; 
    pt.sig.HCML2DTCGroup1Bit4_Ntc4Bin4            = ntcErr.bits.Ntc4_OpenOrShort2Vcc_ErrorConfirmed | ntcErr.bits.Ntc4_Short2Gnd_ErrorConfirmed ; 
    pt.sig.HCML2DTCGroup1Bit5_Ntc5Bin5            = ntcErr.bits.Ntc5_OpenOrShort2Vcc_ErrorConfirmed | ntcErr.bits.Ntc5_Short2Gnd_ErrorConfirmed ; 
    pt.sig.HCML2DTCGroup1Bit6_CtrlModuleFailure   = 0; 
    pt.sig.HCML2DTCGroup1Bit7_LBError             = (GetLgtStsFb_LB() &0x02)>>1; 
    pt.sig.HCML2DTCGroup2Bit0_HBError             = (GetLgtStsFb_HB() &0x02)>>1;
    pt.sig.HCML2DTCGroup2Bit1_PosError            = (GetLgtStsFb_POS()&0x02)>>1; 
    pt.sig.HCML2DTCGroup2Bit2_DrlError            = (GetLgtStsFb_DRL()&0x02)>>1; 
    pt.sig.HCML2DTCGroup2Bit3_TIError             = (GetLgtStsFb_TI() &0x02)>>1;
    pt.sig.HCML2DTCGroup2Bit4_FogError            = (GetLgtStsFb_Fog()&0x02)>>1; 
    pt.sig.HCML2DTCGroup2Bit5_LogoError           = 0;  //not exist
    pt.sig.HCML2DTCGroup2Bit6_CrosError           = GetLgtStsFb_CROS(); 
    pt.sig.HCML2DTCGroup2Bit7_CornError           = GetLgtStsFb_CORN(); 
    pt.sig.HCML2DTCGroup3Bit0_GrillError          = 0;  //not exist
    pt.sig.HCML2DTCGroup3Bit1_HSDCH1SCGOL         = 0; 
    pt.sig.HCML2DTCGroup3Bit2_HSDCH3SCGOL         = 0; 
    pt.sig.HCML2DTCGroup3Bit3_BUCKDiagError       = BuckErrTotal.bits.OpenError|BuckErrTotal.bits.Short2GndError; 
    pt.sig.HCML2DTCGroup3Bit4_LRFailure           = 0; 
    pt.sig.HCML2DTCGroup3Bit5_TISignalFailure     = (TI_E2EFlag.bits.ActvnOfIndcrCntErr | TI_E2EFlag.bits.ActvnOfIndcrCrcErr | TI_E2EFlag.bits.ActvnOfIndcrTimeout); 
    pt.sig.HCML2DTCGroup3Bit5_LBSignalFailure     = (LB_E2EFlag.bits.ActnOfLedLoBeamCntErr | LB_E2EFlag.bits.ActnOfLedLoBeamCrcErr | LB_E2EFlag.bits.ActnOfLedLoBeamTimeout); 
    pt.sig.HCML2DTCGroup3Bit7_BUCKVolOut          = (BuckErrTotal.bits.Short2VCC | BuckErrTotal.bits.UnderVoltage); 
    pt.sig.HCML2DTCGroup4Bit0_DCMotor             = 0; 
    pt.sig.HCML2DTCGroup4Bit1Bit6_Rsv             = 0;

	Rte_Com_Lin_HcmlZcud_Lin2Fr01(pt);
}
#endif

#ifdef RightAir
void LIN_SetDTC_Fun(void)
{
	HcmrZcud_Lin2Fr01_Msg_Type pt;
    S_LgtStsFb_t lightsts;
    U_Ntc_Error ntcErr;
    U_Bin_Error BinErr;
    uint8 id=0;
    U_ChannelErrorState BuckErr[CHANNEL_NUM];
    U_ChannelErrorState BuckErrTotal;
    U_E2EErrorFlag LB_E2EFlag;
    U_E2EErrorFlag TI_E2EFlag;
/* get light status */
    lightsts.Light_Status=Lighting_Rek_Fun();
/* get ntc bin err */
    ntcErr = Interface_GetNtcErrorState();          //get all ntc error
    BinErr = Interface_GetBinErrorState();
/* get buck err */
    for(id=0;id<CHANNEL_NUM;id++)
    {
        BuckErr[id]=Interface_GetChannelState(id);
        BuckErrTotal.bits.OpenError |= BuckErr[id].bits.OpenError;
        BuckErrTotal.bits.Short2GndError |= BuckErr[id].bits.Short2GndError;
        BuckErrTotal.bits.Short2VCC |= BuckErr[id].bits.Short2VCC;
        BuckErrTotal.bits.UnderVoltage |= BuckErr[id].bits.UnderVoltage;
    }
/* get functional safety */
    LB_E2EFlag=Rbk_U_E2EErrorFlag();
    TI_E2EFlag=Rbk_U_E2EErrorFlag();

    pt.sig.StsOfLedCornrgLampwithLINRi = lightsts.Bits.StsCORN;
    pt.sig.StsOfLedDaytiRunngLampWithLINRi = lightsts.Bits.StsDRL;
    pt.sig.StsOfLedFrntFogLampWithLINRi =  lightsts.Bits.StsFOG;
    pt.sig.StsOfLedFrntPosnLampWithLINRi = lightsts.Bits.StsPOS;

    pt.sig.StsOfLedFrntTurnIndcrWithLINRi = lightsts.Bits.StsTI;
    pt.sig.StsOfLedHiBeamWithLINRi = lightsts.Bits.StsHB;
    pt.sig.StsOfLedLoBeamWithLINRi = lightsts.Bits.StsLB;
    pt.sig.StsOfWelGbyFrntWithLINRi = lightsts.Bits.StsWELC;
    
    pt.sig.ErrRespHCMR = TransmErrorFlag;

/* DTC GROUP */
    pt.sig.HCMR2DTCGroup1Bit0_WDGSafetySPI        = 0;
    pt.sig.HCMR2DTCGroup1Bit1_Ntc1Bin1            = ntcErr.bits.Ntc1_OpenOrShort2Vcc_ErrorConfirmed | ntcErr.bits.Ntc1_Short2Gnd_ErrorConfirmed | BinErr.bits.Bin1ErrorConfirm; 
    pt.sig.HCMR2DTCGroup1Bit2_Ntc2Bin2            = ntcErr.bits.Ntc2_OpenOrShort2Vcc_ErrorConfirmed | ntcErr.bits.Ntc2_Short2Gnd_ErrorConfirmed | BinErr.bits.Bin2ErrorConfirm; 
    pt.sig.HCMR2DTCGroup1Bit3_Ntc3Bin3            = ntcErr.bits.Ntc3_OpenOrShort2Vcc_ErrorConfirmed | ntcErr.bits.Ntc3_Short2Gnd_ErrorConfirmed | BinErr.bits.Bin3ErrorConfirm; 
    pt.sig.HCMR2DTCGroup1Bit4_Ntc4Bin4            = ntcErr.bits.Ntc4_OpenOrShort2Vcc_ErrorConfirmed | ntcErr.bits.Ntc4_Short2Gnd_ErrorConfirmed ; 
    pt.sig.HCMR2DTCGroup1Bit5_Ntc5Bin5            = ntcErr.bits.Ntc5_OpenOrShort2Vcc_ErrorConfirmed | ntcErr.bits.Ntc5_Short2Gnd_ErrorConfirmed ; 
    pt.sig.HCMR2DTCGroup1Bit6_CtrlModuleFailure   = 0; 
    pt.sig.HCMR2DTCGroup1Bit7_LBError             = (GetLgtStsFb_LB() &0x02)>>1; 
    pt.sig.HCMR2DTCGroup2Bit0_HBError             = (GetLgtStsFb_HB() &0x02)>>1;
    pt.sig.HCMR2DTCGroup2Bit1_PosError            = (GetLgtStsFb_POS()&0x02)>>1; 
    pt.sig.HCMR2DTCGroup2Bit2_DrlError            = (GetLgtStsFb_DRL()&0x02)>>1; 
    pt.sig.HCMR2DTCGroup2Bit3_TIError             = (GetLgtStsFb_TI() &0x02)>>1;
    pt.sig.HCMR2DTCGroup2Bit4_FogError            = (GetLgtStsFb_Fog()&0x02)>>1; 
    pt.sig.HCMR2DTCGroup2Bit5_LogoError           = 0;  //not exist
    pt.sig.HCMR2DTCGroup2Bit6_CrosError           = GetLgtStsFb_CROS(); 
    pt.sig.HCMR2DTCGroup2Bit7_CornError           = GetLgtStsFb_CORN(); 
    pt.sig.HCMR2DTCGroup3Bit0_GrillError          = 0;  //not exist
    pt.sig.HCMR2DTCGroup3Bit1_HSDCH1SCGOL         = 0; 
    pt.sig.HCMR2DTCGroup3Bit2_HSDCH3SCGOL         = 0; 
    pt.sig.HCMR2DTCGroup3Bit3_BUCKDiagError       = BuckErrTotal.bits.OpenError|BuckErrTotal.bits.Short2GndError; 
    pt.sig.HCMR2DTCGroup3Bit4_LRFailure           = 0; 
    pt.sig.HCMR2DTCGroup3Bit5_TISignalFailure     = TI_E2EFlag.bits.ActvnOfIndcrCntErr | TI_E2EFlag.bits.ActvnOfIndcrCrcErr | TI_E2EFlag.bits.ActvnOfIndcrTimeout; 
    pt.sig.HCMR2DTCGroup3Bit5_LBSignalFailure     = LB_E2EFlag.bits.ActnOfLedLoBeamCntErr | LB_E2EFlag.bits.ActnOfLedLoBeamCrcErr==1 | LB_E2EFlag.bits.ActnOfLedLoBeamTimeout; 
    pt.sig.HCMR2DTCGroup3Bit7_BUCKVolOut          = BuckErrTotal.bits.Short2VCC | BuckErrTotal.bits.UnderVoltage;  
    pt.sig.HCMR2DTCGroup4Bit0_DCMotor             = 0; 
    pt.sig.HCMR2DTCGroup4Bit1Bit6_Rsv             = 0;
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
        rtval=Rte_Com_Lin_ZcudZcud_Lin2Fr01().sig.IndcrSts;
		break;
    case E_TurnIndicator_Act:
        rtval=Rte_Com_Lin_ZcudZcud_Lin2Fr01().sig.ActvnOfIndcrIndcrOut;
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






