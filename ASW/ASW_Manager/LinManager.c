#include "LinManager.h"
#include "TurnIndicator.h"
#include "Com_Cfg.h"
#include "DTC_Interface.h"
#include "Rte_E2EXf.h"
#include "DCMotor.h"
#include "OUVDerate_Interface.h"
#include "NtcDerate_Interface.h"
#include "BuckDerate_Interface.h"
#include "ParaMgr.h"
#include "Channel_Interface.h"
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
uint8 Interface_GetDeratePwm(void);

void LIN_SetDTC_Fun(void)
{
    HcmZcud_Lin2Fr01_Msg_Type pt;
    S_LgtStsFb_t lightsts;
    U_Ntc_Error ntcErr;
    U_Bin_Error BinErr;
    uint8 id=0;
    U_BuckErrorState BuckErr[CHANNEL_NUM];
    U_BuckErrorState BuckErrTotal = {0};
    U_E2EErrorFlag LB_E2EFlag;
    U_E2EErrorFlag TI_E2EFlag;

/* get light status */
    lightsts.Light_Status=Lighting_Rek_Fun();
/* get ntc bin err */
    ntcErr = Interface_GetNtcErrorState();          //get all ntc error
    BinErr = Interface_GetBinErrorState();
    // BuckErrTotal.bits.OpenError =0;
    // BuckErrTotal.bits.Short2GndError =0;
    // BuckErrTotal.bits.Short2VCC =0;
    // BuckErrTotal.bits.UnderVoltage =0;
/* get buck err */
    for(id=0;id<CHANNEL_NUM;id++)
    {
        BuckErr[id].Error=Interface_GetChannelState(id);
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
    if(ParaMgr_CfgPrm_Usage_B==HWTEST_CODE)
    {
        /* V_KL56+Temp_NTC7+Temp_BUCK1+Temp_BUCK2*/
        pt.bytes[2]= Interface_GetDeratePwm(); //derate
        pt.bytes[3]= Interface_GetEnviroment();
        pt.bytes[4]= Interface_GetKL56Value();//(uint8)Interface_GetTemp(0);
        pt.bytes[5]= (uint8)Interface_GetTemp(1);
    }
    else if(ParaMgr_CfgPrm_Usage_B==NORMAL_CODE)
    {
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
        pt.sig.HCML2DTCGroup3Bit1_HSDCH1SCGOL         = Interface_GetHsdError(E_HSChannel_HS0); 
        pt.sig.HCML2DTCGroup3Bit2_HSDCH3SCGOL         = Interface_GetHsdError(E_HSChannel_HS1);    //dc_motor
        pt.sig.HCML2DTCGroup3Bit3_BUCKDiagError       = BuckErrTotal.bits.OpenError|BuckErrTotal.bits.Short2GndError; 
        pt.sig.HCML2DTCGroup3Bit4_LRFailure           = 0; 
        pt.sig.HCML2DTCGroup3Bit5_TISignalFailure     = (TI_E2EFlag.bits.ActvnOfIndcrCntErr | TI_E2EFlag.bits.ActvnOfIndcrCrcErr | TI_E2EFlag.bits.ActvnOfIndcrTimeout); 
        pt.sig.HCML2DTCGroup3Bit6_LBSignalFailure     = (LB_E2EFlag.bits.ActnOfLedLoBeamCntErr | LB_E2EFlag.bits.ActnOfLedLoBeamCrcErr | LB_E2EFlag.bits.ActnOfLedLoBeamTimeout); 
        pt.sig.HCML2DTCGroup3Bit7_BUCKVolOut          = (BuckErrTotal.bits.Short2VCC | BuckErrTotal.bits.UnderVoltage); 
        pt.sig.HCML2DTCGroup4Bit0_DCMotor             = DCMotor_GetSIGErrStatus(); 
        pt.sig.HCML2DTCGroup4Bit1Bit6_Rsv             = 0;
    }
	Rte_Com_Lin_HcmZcud_Lin2Fr01(pt);
}

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
#if (HARDWARE_HEAT_TEST==1)
    return 1;
#elif LDF_LIGHT
	switch (lf)
	{
	case E_LowBeam:
		rtval = Rte_Com_Lin_ZcudZcud_Lin2Fr01().sig.ActnOfLedLoBeamActnOfLedLoBeam;
		break;
	case E_HighBeam:
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
    case E_ADSLight:
        rtval = Rte_Com_Lin_ZcudZcud_Lin2Fr02().sig.ActvnOfLedFrntAutDrvgLi;
        break;
    default :
    break;
	}
#endif
	return rtval;
}

/* get the signal of posnlampdyn */
uint8 Interface_GetSignal_PosnLampDyn(void)
{
    return Rte_Com_Lin_ZcudZcud_Lin2Fr01().sig.ActnOfLedPosnLampDyn;
}
/* get the signal of goodbye */
uint8 Interface_GetSignal_ActvnOfGoodByeLi(void)
{
    return Rte_Com_Lin_ZcudZcud_Lin2Fr01().sig.ActvnOfGoodByeLi;
}
/* get the signal of welcome */
uint8 Interface_GetSignal_ActvnOfWelcomeLi(void)
{
    return Rte_Com_Lin_ZcudZcud_Lin2Fr01().sig.ActvnOfWelcomeLi;
}

uint8 Interface_GetSignal_LvlgSwtSetReqLvlgSwtSetReq(void)
{
    uint8 ctrl_dcmotor=0;
	ctrl_dcmotor = Rte_Com_Lin_ZcudZcud_Lin2Fr02().sig.LvlgSwtSetReqLvlgSwtSetReq;
    return ctrl_dcmotor;
}






