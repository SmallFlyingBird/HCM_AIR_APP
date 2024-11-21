// /****************************************************************
//  *                                                              *
//  *                     Include Files                            *
//  *                                                              *
//  ****************************************************************/
// #include "ComSignal_Interface.h"
// #include "Com_Cfg.h"
// #include "Com.h"
// #include "HcmPlatform.h"
// /****************************************************************
//  *                                                              *
//  *                  Private Variable Define                     *
//  *                                                              *
//  ****************************************************************/

// /*********************************/
// /* Global Variable Define (Left) */
// /*********************************/
// /***********************************************************Flag**********************************************************************/
// static uint8_t UsageModeRcvd_Flag = 0;
// static uint8_t VehSpeedRcvd_Flag = 0;
// /*********************************************************TxSignal********************************************************************/
// static uint32_t StsOfLedHiBeamLe;
// static uint32_t StsOfLedLoBeamLe;
// static uint32_t ExtrLiShowStoreStsFrntLe;
// static uint32_t StsOfLedLeLogoLamp;
// static uint32_t StsOfLedFrntTurnIndcrLe;
// static uint32_t StsOfTouristModLe;
// static uint32_t StsOfLedDaytiRunngLampLe;
// static uint32_t StsOfLedFrntFogLampLe;
// static uint32_t StsOfAfsLe;
// static uint32_t StsOfAhbcLe;
// static uint32_t StsOfSwvlgLe;
// static uint32_t StsOfFrntSideMkrLampLe2;
// static uint32_t StsOfLedCornrgLampLe;
// static uint32_t StsOfLedFrntPosnLampLe;
// static uint32_t HdlampLeInpSts1;
// static uint32_t HdlampLeInpSts2;
// static uint32_t ExtrLiShowActvnFrntLeFb;
// static uint32_t DwnLoadStsFbOfHdlampLe;
// static uint32_t ExtrLiShowActvnLeLogoFb;
// static uint32_t DwnLoadStsFbOfLogoLampLe;
// static uint32_t StsOfWelGbyFrntLe;
// static uint32_t StsOfLvlg;
// static uint32_t LvlgMtrAgle;
// #if HCM_LEFT_SIDE
// /*********************************************************RxSignal********************************************************************/
// static uint8_t  Signal_ActnOfLedCornrgLampLe          = 0;
// static uint8_t  Signal_ActnOfLedDaytiRunngLamp        = 0;
// static uint8_t  Signal_ActnOfLedFrntFogLamp           = 0;
// static uint8_t  Signal_ActnOfLedHiBeam                = 0;
// static uint8_t  Signal_ActnOfLedPosnLamp              = 0;
// static uint8_t  Signal_ActvnOfAfs                     = 0;
// static uint8_t  Signal_ActvnOfAhbc                    = 0;
// static uint8_t  Signal_ActvnOfAhl                     = 0;
// static uint8_t  Signal_ActvnOfDbl                     = 0;
// static uint8_t  Signal_ActvnOfGoodByeLi               = 0;
// static uint8_t  Signal_ActvnOfTouristMod              = 0;
// static uint8_t  Signal_ActvnOfWelcomeLi               = 0;
// static uint8_t  Signal_ActnOfLedLoBeamActnOfLedLoBeam = 0;
// static uint8_t  Signal_ActvnOfIndcrIndcrOut           = 0;
// static uint8_t  Signal_WipgAutFrntMod                 = 0;
// static uint8_t  Signal_RainLi                         = 0;
// static uint8_t  Signal_CameraStsforAHBC               = 0;
// static uint8_t  Signal_ActnOfLedPosnLampDyn           = 0;
// static uint8_t  Signal_ActnOfLedFrntCrossLampDyn      = 0;
// static uint8_t  Signal_ActnOfLedGrilleLampDyn         = 0;
// static uint8_t  Signal_ActnOfLedLeLogoLampDyn         = 0;
// static uint8_t  Signal_ActvnOfHomeSafe                = 0;
// static uint16_t Signal_YawRateReqdByDrvr              = 0;
// static uint32_t Signal_CarTiGlb                       = 0;
// static uint8_t  Signal_Body2CntrForMissCom            = 0;
// static uint8_t  Signal_ActnOfLedFrntCrossLamp         = 0;
// static uint8_t  Signal_ActnOfLedGrilleLamp            = 0;
// static uint8_t  Signal_ActnOfLedLeLogoLamp            = 0;
// static uint8_t  Signal_ExtrLiRlyPwrDwn                = 0;
// static uint32_t Signal_BkpOfDstTrvld                  = 0;
// static uint8_t  Signal_LiOprnMod                      = 0;
// static uint8_t  Signal_AutWinWipgCmd                  = 0;
// static uint8_t  Signal_IndcrSts                       = 0;
// static uint8_t  Signal_LitArea                        = 0;
// static uint8_t  Signal_ActvnOfApproach                = 0;
// static uint8_t  Signal_ActvnOfCarLoctr                = 0;
// static uint8_t  Signal_ActvnOfWaitMode                = 0;
// static uint8_t  Signal_IndcrNoSeq                     = 0;
// static uint8_t  Signal_ExtrLiShowFileTxReq            = 0;
// static uint8_t  Signal_ExtrLiShowActvnReq             = 0;
// static uint8_t  Signal_WelcomeGoodbyeModeReq          = 0xFF;
// static uint8_t  Signal_WelLiFileTxReq                 = 0;
// static uint8_t  Signal_ActvnOfLiForComity             = 0;
// static uint8_t  Signal_ActvnOfLiForSpkr               = 0;
// static uint8_t  Signal_ActvnOfLiForWait               = 0;
// static uint8_t  Signal_ActvnOfADB                     = 0;

// static uint8_t  Signal_VehCfgPrmExtCCPBytePosn5   = 0;
// static uint8_t  Signal_VehCfgPrmExtCCPBytePosn6   = 0;
// static uint8_t  Signal_VehCfgPrmExtCCPBytePosn2   = 0;
// static uint8_t  Signal_VehCfgPrmExtCCPBytePosn3   = 0;
// static uint8_t  Signal_VehCfgPrmExtCCPBytePosn8   = 0;
// static uint8_t  Signal_VehCfgPrmExtCCPBytePosn4   = 0;
// static uint8_t  Signal_VehCfgPrmExtCCPBytePosn7   = 0;
// static uint8_t  Signal_VehCfgPrmExtBlkIDBytePosn1 = 0;

// static uint16_t Signal_TrafficSignForADB1AdbAbsDist   = 0;
// static uint8_t  Signal_TrafficSignForADB1AdbTrkInfo   = 0;
// static uint8_t  Signal_TrafficSignForADB1AdbDetdQly   = 0;
// static uint16_t Signal_TrafficSignForADB1AdbHozlAgRi  = 0;
// static uint16_t Signal_TrafficSignForADB1AdbVertAgTop = 0; 
// static uint16_t Signal_TrafficSignForADB1AdbHozlAgLe  = 0;
// static uint16_t Signal_TrafficSignForADB1AdbVertAgBot = 0;

// static uint16_t Signal_VehObjforADB7AdbAbsDist        = 0;         
// static uint8_t  Signal_VehObjforADB7AdbClassn         = 0;          
// static uint8_t  Signal_VehObjforADB7AdbTrkInfo        = 0;         
// static uint8_t  Signal_VehObjforADB7AdbObjDir         = 0;         
// static uint8_t  Signal_VehObjforADB7AdbVertAg         = 0;        
// static uint16_t Signal_VehObjforADB7AdbObjHozlAgSpdRi = 0; 
// static uint16_t Signal_VehObjforADB7AdbHozlAgLe       = 0;      
// static uint16_t Signal_VehObjforADB7AdbHozlAgRi       = 0;   
// static uint16_t Signal_VehObjforADB7AdbObjHozlAgSpdLe = 0;

// static uint8_t  Signal_VehObjforADB5AdbClassn         = 0;
// static uint8_t  Signal_VehObjforADB5AdbObjDir         = 0;
// static uint8_t  Signal_VehObjforADB5AdbTrkInfo        = 0;
// static uint16_t Signal_VehObjforADB5AdbAbsDist        = 0;
// static uint8_t  Signal_VehObjforADB5AdbVertAg         = 0;
// static uint16_t Signal_VehObjforADB5AdbObjHozlAgSpdRi = 0;
// static uint16_t Signal_VehObjforADB5AdbHozlAgLe       = 0;
// static uint16_t Signal_VehObjforADB5AdbHozlAgRi       = 0;
// static uint16_t Signal_VehObjforADB5AdbObjHozlAgSpdLe = 0;

// static uint8_t  Signal_VehCfgPrmCCPBytePosn6   = 0;
// static uint8_t  Signal_VehCfgPrmBlkIDBytePosn1 = 0;
// static uint8_t  Signal_VehCfgPrmCCPBytePosn4   = 0;
// static uint8_t  Signal_VehCfgPrmCCPBytePosn3   = 0;
// static uint8_t  Signal_VehCfgPrmCCPBytePosn2   = 0;
// static uint8_t  Signal_VehCfgPrmCCPBytePosn8   = 0;
// static uint8_t  Signal_VehCfgPrmCCPBytePosn7   = 0;
// static uint8_t  Signal_VehCfgPrmCCPBytePosn5   = 0;

// static uint8_t  Signal_VehModMngtGlbSafe1Chks              = 0;
// static uint8_t  Signal_VehModMngtGlbSafe1CarModSts1        = 0;
// static uint8_t  Signal_VehModMngtGlbSafe1Cntr              = 0;
// static uint8_t  Signal_VehModMngtGlbSafe1EgyLvlElecSubtyp  = 0;
// static uint8_t  Signal_VehModMngtGlbSafe1PwrLvlElecSubtyp  = 0;
// static uint8_t  Signal_VehModMngtGlbSafe1CarModSubtypWdCar = 0;
// static uint8_t  Signal_VehModMngtGlbSafe1UsgModSts         = (uint8_t)E_UsageModeSts_InActv;
// static uint8_t  Signal_VehModMngtGlbSafe1PwrLvlElecMai     = 0;
// static uint8_t  Signal_VehModMngtGlbSafe1EgyLvlElecMai     = 0;
// static uint8_t  Signal_VehModMngtGlbSafe1FltEgyCnsWdSts    = 0;

// static uint8_t  Signal_VehObjforADB8AdbTrkInfo        = 0;
// static uint8_t  Signal_VehObjforADB8AdbClassn         = 0;
// static uint8_t  Signal_VehObjforADB8AdbObjDir         = 0;
// static uint16_t Signal_VehObjforADB8AdbAbsDist        = 0;
// static uint8_t  Signal_VehObjforADB8AdbVertAg         = 0;
// static uint16_t Signal_VehObjforADB8AdbHozlAgLe       = 0;
// static uint16_t Signal_VehObjforADB8AdbObjHozlAgSpdLe = 0;
// static uint16_t Signal_VehObjforADB8AdbHozlAgRi       = 0;
// static uint16_t Signal_VehObjforADB8AdbObjHozlAgSpdR  = 0;

// static uint16_t Signal_DwnLoadDynLtgPrmForLedCornrgLampLeUpprBriPrm   = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedCornrgLampLeContTiPrm    = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedCornrgLampLeLowBriPrm    = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedCornrgLampLeOffsTiPrm    = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedCornrgLampLeModePrm      = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedCornrgLampLeTistamp      = 0;

// static uint16_t Signal_DwnLoadDynLtgPrmForLedFrntPosnLampLeLowBriPrm  = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedFrntPosnLampLeUpprBriPrm = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedFrntPosnLampLeContTiPrm  = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedFrntPosnLampLeOffsTiPrm  = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedFrntPosnLampLeModePrm    = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedFrntPosnLampLeTistamp    = 0;

// static uint16_t Signal_VehObjforADB3AdbAbsDist        = 0;
// static uint8_t  Signal_VehObjforADB3AdbTrkInfo        = 0;
// static uint8_t  Signal_VehObjforADB3AdbClassn         = 0;
// static uint8_t  Signal_VehObjforADB3AdbObjDir         = 0;
// static uint8_t  Signal_VehObjforADB3AdbVertAg         = 0;
// static uint16_t Signal_VehObjforADB3AdbObjHozlAgSpdLe = 0;
// static uint16_t Signal_VehObjforADB3AdbObjHozlAgSpdRi = 0;
// static uint16_t Signal_VehObjforADB3AdbHozlAgLe       = 0;
// static uint16_t Signal_VehObjforADB3AdbHozlAgRi       = 0;

// static uint16_t Signal_BrkPedlrRatQf                  = 3;
// static uint16_t Signal_BrkPedlrRatPerc                = 0;

// static uint8_t  Signal_VehObjforADB2AdbObjDir         = 0;
// static uint8_t  Signal_VehObjforADB2AdbTrkInfo        = 0;
// static uint16_t Signal_VehObjforADB2AdbAbsDist        = 0;
// static uint8_t  Signal_VehObjforADB2AdbClassn         = 0;
// static uint8_t  Signal_VehObjforADB2AdbVertAg         = 0;
// static uint16_t Signal_VehObjforADB2AdbObjHozlAgSpdRi = 0;
// static uint16_t Signal_VehObjforADB2AdbObjHozlAgSpdLe = 0;
// static uint16_t Signal_VehObjforADB2AdbHozlAgLe       = 0;
// static uint16_t Signal_VehObjforADB2AdbHozlAgRi       = 0;

// static uint8_t  Signal_VehObjforADB6AdbClassn         = 0;
// static uint8_t  Signal_VehObjforADB6AdbObjDir         = 0;
// static uint8_t  Signal_VehObjforADB6AdbTrkInfo        = 0;
// static uint16_t Signal_VehObjforADB6AdbAbsDist        = 0;
// static uint8_t  Signal_VehObjforADB6AdbVertAg         = 0;
// static uint16_t Signal_VehObjforADB6AdbObjHozlAgSpdRi = 0;
// static uint16_t Signal_VehObjforADB6AdbHozlAgLe       = 0;
// static uint16_t Signal_VehObjforADB6AdbHozlAgRi       = 0;
// static uint16_t Signal_VehObjforADB6AdbObjHozlAgSpdLe = 0;

// static uint8_t  Signal_AccrPedlRatCntr                = 0;
// static uint8_t  Signal_AccrPedlRatChks                = 0;
// static uint16_t Signal_AccrPedlRatAccrPedlRat         = 0;

// static uint8_t  Signal_BrkPedlSnsrSt                  = 0;
// static uint8_t  Signal_BrkPedlSnsrChks                = 0;
// static uint8_t  Signal_BrkPedlSnsrCntr                = 0;
// static uint8_t  Signal_BrkPedlSnsrQf                  = 3;

// static uint8_t  Signal_AmbTRawQly                     = 0;
// static uint16_t Signal_AmbTRawAmbTVal                 = 0;

// static uint8_t  Signal_VehBattUSysU                   = 0;
// static uint8_t  Signal_VehBattUSysUQf                 = 3;

// static uint8_t  Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampLeModePrm    = 0;                                         
// static uint16_t Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampLeOffsTiPrm  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampLeLowBriPrm  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampLeUpprBriPrm = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampLeContTiPrm  = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampLeTistamp    = 0;
// static uint8_t  Signal_LvlgSwtSetReqADModCtrlInhbn                      = 0;

// static uint8_t  Signal_OutdBriSts                     = 0;

// static uint8_t  Signal_VehObjforADB1AdbObjDir         = 0;
// static uint8_t  Signal_VehObjforADB1AdbTrkInfo        = 0;
// static uint16_t Signal_VehObjforADB1AdbAbsDist        = 0;
// static uint8_t  Signal_VehObjforADB1AdbClassn         = 0;
// static uint8_t  Signal_VehObjforADB1AdbVertAg         = 0;
// static uint16_t Signal_VehObjforADB1AdbObjHozlAgSpdRi = 0;
// static uint16_t Signal_VehObjforADB1AdbObjHozlAgSpdLe = 0;
// static uint16_t Signal_VehObjforADB1AdbHozlAgLe       = 0;
// static uint16_t Signal_VehObjforADB1AdbHozlAgRi       = 0;

// static uint8_t  Signal_VehObjforADB4AdbObjDir         = 0;
// static uint8_t  Signal_VehObjforADB4AdbTrkInfo        = 0;
// static uint16_t Signal_VehObjforADB4AdbAbsDist        = 0;
// static uint8_t  Signal_VehObjforADB4AdbClassn         = 0;
// static uint8_t  Signal_VehObjforADB4AdbVertAg         = 0;
// static uint16_t Signal_VehObjforADB4AdbObjHozlAgSpdRi = 0;
// static uint16_t Signal_VehObjforADB4AdbObjHozlAgSpdLe = 0;
// static uint16_t Signal_VehObjforADB4AdbHozlAgLe       = 0;
// static uint16_t Signal_VehObjforADB4AdbHozlAgRi       = 0;

// static uint16_t Signal_DwnLoadDynLtgPrmForLedAllWthrLampLeOffsTiPrm  = 0;          
// static uint16_t Signal_DwnLoadDynLtgPrmForLedAllWthrLampLeContTiPrm  = 0;  
// static uint8_t  Signal_DwnLoadDynLtgPrmForLedAllWthrLampLeModePrm    = 0;      
// static uint8_t  Signal_DwnLoadDynLtgPrmForLedAllWthrLampLeLowBriPrm  = 0;  
// static uint8_t  Signal_DwnLoadDynLtgPrmForLedAllWthrLampLeUpprBriPrm = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedAllWthrLampLeTistamp    = 0;     

// static uint16_t Signal_DwnLoadDynLitPrmForLedLoBeamLeContTiPrm  = 0;
// static uint8_t  Signal_DwnLoadDynLitPrmForLedLoBeamLeModePrm    = 0;
// static uint8_t  Signal_DwnLoadDynLitPrmForLedLoBeamLeLowBriPrm  = 0;
// static uint16_t Signal_DwnLoadDynLitPrmForLedLoBeamLeOffsTiPrm  = 0;
// static uint8_t  Signal_DwnLoadDynLitPrmForLedLoBeamLeUpprBriPrm = 0;
// static uint16_t Signal_DwnLoadDynLitPrmForLedLoBeamLeTistamp    = 0;

// static uint8_t  Signal_SteerWhlSnsrQf    = 3;
// static uint16_t Signal_SteerWhlSnsrAg    = 0;
// static uint16_t Signal_SteerWhlSnsrAgSpd = 0;

// static uint8_t  Signal_DwnLoadDynLitPrmForLedHiBeamLeLowBriPrm  = 0;         
// static uint8_t  Signal_DwnLoadDynLitPrmForLedHiBeamLeModePrm    = 0;         
// static uint8_t  Signal_DwnLoadDynLitPrmForLedHiBeamLeUpprBriPrm = 0;         
// static uint16_t Signal_DwnLoadDynLitPrmForLedHiBeamLeOffsTiPrm  = 0;        
// static uint16_t Signal_DwnLoadDynLitPrmForLedHiBeamLeContTiPrm  = 0;        
// static uint16_t Signal_DwnLoadDynLitPrmForLedHiBeamLeTistamp    = 0;        
                                                                         
// static uint8_t  Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeUpprBriPrm = 0;  
// static uint8_t  Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeModePrm    = 0;  
// static uint16_t Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeContTiPrm  = 0; 
// static uint16_t Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeOffsTiPrm  = 0; 
// static uint8_t  Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeLowBriPrm  = 0;  
// static uint16_t Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeTistamp    = 0; 

// static uint8_t  Signal_VehSpdLgtQf                    = 3;  
// static uint16_t Signal_VehSpdLgtA                     = 0; 

// static uint16_t Signal_IndcrPatCmd1WdTiOff            = 0; 
// static uint16_t Signal_IndcrPatCmd1WdTiOn             = 0; 

// static uint16_t Signal_TrafficSignForADB2AdbAbsDist   = 0;
// static uint8_t  Signal_TrafficSignForADB2AdbTrkInfo   = 0;
// static uint8_t  Signal_TrafficSignForADB2AdbDetdQly   = 0;
// static uint16_t Signal_TrafficSignForADB2AdbHozlAgRi  = 0;
// static uint16_t Signal_TrafficSignForADB2AdbVertAgTop = 0; 
// static uint16_t Signal_TrafficSignForADB2AdbHozlAgLe  = 0;
// static uint16_t Signal_TrafficSignForADB2AdbVertAgBot = 0;

// static uint8_t  Signal_VehObjforAHBAdbObjDir        = 0;
// static uint8_t  Signal_VehObjforAHBAdbDetdQly       = 0;
// static uint8_t  Signal_VehObjforAHBAdbClassn        = 0;
// static uint8_t  Signal_VehObjforAHBAdbClassnQly     = 0;
// static uint16_t Signal_VehObjforAHBAdbAbsDist       = 0;
// static uint8_t  Signal_VehObjforAHBAdbTrkInfo       = 0;
// static uint16_t Signal_VehObjforAHBAdbObjVertAgSpd  = 0;
// static uint16_t Signal_VehObjforAHBAdbObjHozlAgSpd  = 0;
// static uint8_t  Signal_VehObjforAHBAdbVertAg        = 0;

// static uint16_t Signal_BrkPedlValBrkPedlVal         = 0;
// static uint16_t Signal_BrkPedlValQf                 = 3;

// static uint8_t  Signal_WipgInfoWiprActv             = 0;
// static uint8_t  Signal_WipgInfoWiprInWipgAr         = 0;
// static uint8_t  Signal_WipgInfoWipgSpdInfo          = 0;
// static uint8_t  Signal_TooManyCars                  = 0;

// static uint16_t Signal_SuspPosnVertAgSuspPosnVertAg = 0;
// static uint8_t  Signal_SuspPosnVertAgGenQf          = 3; 

// static uint8_t  Signal_SuspPosnVertLvlReQf          = 3;
// static uint16_t Signal_SuspPosnVertLvlRe            = 0;
// static uint16_t Signal_SuspPosnVertLvlFrnt          = 0;
// static uint8_t  Signal_SuspPosnVertLvlFrntQf        = 3;

// static uint16_t Signal_DwnLoadDynLitPrmLedLeGrilleLampOffsTiPrm     = 0; 
// static uint16_t Signal_DwnLoadDynLitPrmLedLeGrilleLampTistamp       = 0; 
// static uint8_t  Signal_DwnLoadDynLitPrmLedLeGrilleLampLowBriPrm     = 0; 
// static uint8_t  Signal_DwnLoadDynLitPrmLedLeGrilleLampModePrm       = 0; 
// static uint8_t  Signal_DwnLoadDynLitPrmLedLeGrilleLampUpprBriPrm    = 0; 
// static uint16_t Signal_DwnLoadDynLitPrmLedLeGrilleLampContTiPrm     = 0; 
                                    	                          
// static uint16_t Signal_DwnLoadDynLitPrmLedLeSideLogoLiModePrm       = 0; 
// static uint16_t Signal_DwnLoadDynLitPrmLedLeSideLogoLiLowBriPrm     = 0; 
// static uint8_t  Signal_DwnLoadDynLitPrmLedLeSideLogoLiUpprBriPrm    = 0; 
// static uint8_t  Signal_DwnLoadDynLitPrmLedLeSideLogoLiTistamp       = 0; 
// static uint8_t  Signal_DwnLoadDynLitPrmLedLeSideLogoLiContTiPrm     = 0; 
// static uint16_t Signal_DwnLoadDynLitPrmLedLeSideLogoLiOffsTiPrm     = 0; 

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp1LowBrightness   = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp1OffsetTime      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp1HighBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp1Mode1           = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp1Timestamp       = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp1ContinueTime    = 0; 

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp2LowBrightness   = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp2OffsetTime      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp2HighBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp2Mode1           = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp2Timestamp       = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp2ContinueTime    = 0; 

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp3LowBrightness   = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp3OffsetTime      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp3HighBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp3Mode1           = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp3Timestamp       = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp3ContinueTime    = 0; 

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp4LowBrightness   = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp4OffsetTime      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp4HighBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp4Mode1           = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp4Timestamp       = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp4ContinueTime    = 0; 

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp5LowBrightness   = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp5OffsetTime      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp5HighBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp5Mode1           = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp5Timestamp       = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp5ContinueTime    = 0; 

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp6LowBrightness   = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp6OffsetTime      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp6HighBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp6Mode1           = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp6Timestamp       = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp6ContinueTime    = 0; 

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp7LowBrightness   = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp7OffsetTime      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp7HighBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp7Mode1           = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp7Timestamp       = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp7ContinueTime    = 0; 

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp8LowBrightness   = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp8OffsetTime      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp8HighBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp8Mode1           = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp8Timestamp       = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp8ContinueTime    = 0; 

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp9LowBrightness   = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp9OffsetTime      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp9HighBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp9Mode1           = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp9Timestamp       = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp9ContinueTime    = 0; 

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp10LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp10OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp10HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp10Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp10Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp10ContinueTime   = 0; 

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp11LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp11OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp11HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp11Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp11Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp11ContinueTime   = 0; 

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp12LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp12OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp12HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp12Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp12Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp12ContinueTime   = 0; 

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp13LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp13OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp13HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp13Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp13Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp13ContinueTime   = 0; 

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp14LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp14OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp14HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp14Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp14Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp14ContinueTime   = 0; 

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp15LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp15OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp15HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp15Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp15Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp15ContinueTime   = 0; 

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp16LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp16OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp16HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp16Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp16Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp16ContinueTime   = 0; 

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp17LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp17OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp17HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp17Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp17Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp17ContinueTime   = 0; 

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp18LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp18OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp18HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp18Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp18Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp18ContinueTime   = 0; 

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp19LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp19OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp19HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp19Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp19Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp19ContinueTime   = 0; 

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp20LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp20OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp20HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp20Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp20Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp20ContinueTime   = 0; 

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp21LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp21OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp21HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp21Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp21Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp21ContinueTime   = 0; 

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp22LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp22OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp22HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp22Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp22Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp22ContinueTime   = 0; 

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp23LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp23OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp23HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp23Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp23Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp23ContinueTime   = 0; 


// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp24LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp24OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp24HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp24Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp24Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntLeGrp24ContinueTime   = 0; 

// static uint8_t  Signal_TiAndDateIndcnDay       = 0;
// static uint8_t  Signal_TiAndDateIndcnYr1       = 0;
// static uint8_t  Signal_TiAndDateIndcnMins1     = 0;
// static uint8_t  Signal_TiAndDateIndcnMth1      = 0;
// static uint8_t  Signal_TiAndDateIndcnHr1       = 0;
// static uint8_t  Signal_TiAndDateIndcnSec1      = 0; 
// static uint8_t  Signal_TiAndDateIndcnDataValid = 0;

// static uint8_t  Signal_DHUcontrolleftcorneringlamp      = 0;
// static uint8_t  Signal_DHUcontrolleftdaytimerunninglamp = 0;
// static uint8_t  Signal_DHUcontrolleftfroglight          = 0;
// static uint8_t  Signal_DHUcontrollefthighbeamlamp       = 0;
// static uint8_t  Signal_DHUcontrolleftlowbeamlamp        = 0;
// static uint8_t  Signal_DHUcontrolleftpositionlamp       = 0;

// static uint16_t Signal_VehObjforAHBAdbHozlAg            = 0;

// #elif HCM_RIGHT_SIDE
// /**********************************/
// /* Global Variable Define (Right) */
// /**********************************/

// static uint8_t  Signal_ExtrLiShowFileTxReq = 0;
// static uint8_t  Signal_ExtrLiShowActvnReq  = 0;

// static uint8_t  Signal_WipgAutFrntMod   = 0;
// static uint8_t  Signal_RainLi           = 0;
// static uint8_t  Signal_CameraStsforAHBC = 0;

// static uint8_t  Signal_ActnOfLedPosnLampDyn      = 0;
// static uint8_t  Signal_ActnOfLedFrntCrossLampDyn = 0;
// static uint8_t  Signal_ActnOfLedGrilleLampDyn    = 0;
// static uint8_t  Signal_ActnOfLedRiLogoLampDyn    = 0;
// static uint8_t  Signal_ActvnOfHomeSafe           = 0;

// static uint16_t Signal_YawRateReqdByDrvr      = 0;

// static uint32_t Signal_CarTiGlb               = 0;
// static uint8_t  Signal_Body2CntrForMissCom    = 0;
// static uint8_t  Signal_ActnOfLedFrntCrossLamp = 0;
// static uint8_t  Signal_ActnOfLedGrilleLamp    = 0;
// static uint8_t  Signal_ActnOfLedRiLogoLamp    = 0;

// static uint8_t  Signal_TooManyCars            = 0;

// static uint8_t  Signal_ExtrLiRlyPwrDwn = 0;
// static uint32_t Signal_BkpOfDstTrvld   = 0;

// static uint8_t  Signal_IndcrSts        = 0;

// static uint8_t  Signal_LitArea         = 0;
// static uint8_t  Signal_ActvnOfApproach = 0;
// static uint8_t  Signal_ActvnOfCarLoctr = 0;
// static uint8_t  Signal_ActvnOfWaitMode = 0;
// static uint8_t  Signal_IndcrNoSeq      = 0;

// static uint8_t  Signal_LiOprnMod       = 0;
// static uint8_t  Signal_AutWinWipgCmd   = 0;

// static uint8_t  Signal_ActnOfLedCornrgLampRi   = 0;
// static uint8_t  Signal_ActnOfLedDaytiRunngLamp = 0;
// static uint8_t  Signal_ActnOfLedFrntFogLamp    = 0;
// static uint8_t  Signal_ActnOfLedHiBeam         = 0;
// static uint8_t  Signal_ActnOfLedPosnLamp       = 0;
// static uint8_t  Signal_ActvnOfAfs              = 0;
// static uint8_t  Signal_ActvnOfAhbc             = 0;
// static uint8_t  Signal_ActvnOfAhl              = 0;
// static uint8_t  Signal_ActvnOfDbl              = 0;
// static uint8_t  Signal_ActvnOfGoodByeLi        = 0;
// static uint8_t  Signal_ActvnOfTouristMod       = 0;
// static uint8_t  Signal_ActvnOfWelcomeLi        = 0;

// static uint8_t  Signal_WelcomeGoodbyeModeReq = 0xFF;
// static uint8_t  Signal_WelLiFileTxReq        = 0;
// static uint8_t  Signal_ActvnOfLiForComity    = 0;
// static uint8_t  Signal_ActvnOfLiForSpkr      = 0;
// static uint8_t  Signal_ActvnOfLiForWait      = 0;
// static uint8_t  Signal_ActvnOfADB            = 0;

// static uint8_t  Signal_DHUcontrolrightcorneringlamp      = 0;
// static uint8_t  Signal_DHUcontrolrightdaytimerunninglamp = 0;
// static uint8_t  Signal_DHUcontrolrightfroglight          = 0;
// static uint8_t  Signal_DHUcontrolrighthighbeamlamp       = 0;
// static uint8_t  Signal_DHUcontrolrightlowbeamlamp        = 0;
// static uint8_t  Signal_DHUcontrolrightpositionlamp       = 0;

// static uint16_t Signal_DwnLoadDynLtgPrmForLedCornrgLampRiUpprBriPrm = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedCornrgLampRiContTiPrm  = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedCornrgLampRiLowBriPrm  = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedCornrgLampRiOffsTiPrm  = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedCornrgLampRiModePrm    = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedCornrgLampRiTistamp    = 0;

// static uint8_t  Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiUpprBriPrm = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiModePrm    = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiContTiPrm  = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiOffsTiPrm  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiLowBriPrm  = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiTistamp    = 0;

// static uint8_t  Signal_VehModMngtGlbSafe1Chks              = 0;
// static uint8_t  Signal_VehModMngtGlbSafe1CarModSts1        = 0;
// static uint8_t  Signal_VehModMngtGlbSafe1Cntr              = 0;
// static uint8_t  Signal_VehModMngtGlbSafe1EgyLvlElecSubtyp  = 0;
// static uint8_t  Signal_VehModMngtGlbSafe1PwrLvlElecSubtyp  = 0;
// static uint8_t  Signal_VehModMngtGlbSafe1CarModSubtypWdCar = 0;
// static uint8_t  Signal_VehModMngtGlbSafe1UsgModSts         = (uint8_t)E_UsageModeSts_InActv;
// static uint8_t  Signal_VehModMngtGlbSafe1PwrLvlElecMai     = 0;
// static uint8_t  Signal_VehModMngtGlbSafe1EgyLvlElecMai     = 0;
// static uint8_t  Signal_VehModMngtGlbSafe1FltEgyCnsWdSts    = 0;

// static uint16_t Signal_VehObjforAHBAdbHozlAg       = 0;
// static uint8_t  Signal_VehObjforAHBAdbObjDir       = 0;
// static uint8_t  Signal_VehObjforAHBAdbDetdQly      = 0;
// static uint8_t  Signal_VehObjforAHBAdbClassn       = 0;
// static uint8_t  Signal_VehObjforAHBAdbClassnQly    = 0;
// static uint16_t Signal_VehObjforAHBAdbAbsDist      = 0;
// static uint8_t  Signal_VehObjforAHBAdbTrkInfo      = 0;
// static uint16_t Signal_VehObjforAHBAdbObjVertAgSpd = 0;
// static uint16_t Signal_VehObjforAHBAdbObjHozlAgSpd = 0;
// static uint8_t  Signal_VehObjforAHBAdbVertAg       = 0;

// static uint16_t Signal_DwnLoadDynLtgPrmForLedAllWthrLampRiOffsTiPrm  = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedAllWthrLampRiContTiPrm  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForLedAllWthrLampRiModePrm    = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForLedAllWthrLampRiLowBriPrm  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForLedAllWthrLampRiUpprBriPrm = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedAllWthrLampRiTistamp    = 0;

// static uint8_t  Signal_VehCfgPrmExtCCPBytePosn5   =0;
// static uint8_t  Signal_VehCfgPrmExtCCPBytePosn6   =0;
// static uint8_t  Signal_VehCfgPrmExtCCPBytePosn2   =0;
// static uint8_t  Signal_VehCfgPrmExtCCPBytePosn3   =0;
// static uint8_t  Signal_VehCfgPrmExtCCPBytePosn8   =0;
// static uint8_t  Signal_VehCfgPrmExtCCPBytePosn4   =0;
// static uint8_t  Signal_VehCfgPrmExtCCPBytePosn7   =0;
// static uint8_t  Signal_VehCfgPrmExtBlkIDBytePosn1 =0;

// static uint16_t Signal_VehObjforADB7AdbAbsDist        = 0;
// static uint8_t  Signal_VehObjforADB7AdbClassn         = 0;
// static uint8_t  Signal_VehObjforADB7AdbTrkInfo        = 0;
// static uint8_t  Signal_VehObjforADB7AdbObjDir         = 0;
// static uint8_t  Signal_VehObjforADB7AdbVertAg         = 0;
// static uint16_t Signal_VehObjforADB7AdbObjHozlAgSpdRi = 0;
// static uint16_t Signal_VehObjforADB7AdbHozlAgLe       = 0;
// static uint16_t Signal_VehObjforADB7AdbHozlAgRi       = 0;
// static uint16_t Signal_VehObjforADB7AdbObjHozlAgSpdLe = 0;


// static uint8_t  Signal_VehCfgPrmCCPBytePosn6   = 0;
// static uint8_t  Signal_VehCfgPrmBlkIDBytePosn1 = 0;
// static uint8_t  Signal_VehCfgPrmCCPBytePosn4   = 0;
// static uint8_t  Signal_VehCfgPrmCCPBytePosn3   = 0;
// static uint8_t  Signal_VehCfgPrmCCPBytePosn2   = 0;
// static uint8_t  Signal_VehCfgPrmCCPBytePosn8   = 0;
// static uint8_t  Signal_VehCfgPrmCCPBytePosn7   = 0;
// static uint8_t  Signal_VehCfgPrmCCPBytePosn5   = 0;

// static uint16_t Signal_VehObjforADB3AdbAbsDist        = 0;
// static uint8_t  Signal_VehObjforADB3AdbTrkInfo        = 0;
// static uint8_t  Signal_VehObjforADB3AdbClassn         = 0;
// static uint8_t  Signal_VehObjforADB3AdbObjDir         = 0;
// static uint8_t  Signal_VehObjforADB3AdbVertAg         = 0;
// static uint16_t Signal_VehObjforADB3AdbObjHozlAgSpdLe = 0;
// static uint16_t Signal_VehObjforADB3AdbObjHozlAgSpdRi = 0;
// static uint16_t Signal_VehObjforADB3AdbHozlAgLe       = 0;
// static uint16_t Signal_VehObjforADB3AdbHozlAgRi       = 0;

// static uint16_t Signal_BrkPedlrRatQf   = 0;
// static uint16_t Signal_BrkPedlrRatPerc = 0;

// static uint16_t Signal_DwnLoadDynLtgPrmForLedFrntPosnLampRiLowBriPrm  = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedFrntPosnLampRiUpprBriPrm = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedFrntPosnLampRiContTiPrm  = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedFrntPosnLampRiOffsTiPrm  = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedFrntPosnLampRiModePrm    = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedFrntPosnLampRiTistamp    = 0;

// static uint8_t  Signal_VehObjforADB4AdbObjDir         = 0;
// static uint8_t  Signal_VehObjforADB4AdbTrkInfo        = 0;
// static uint16_t Signal_VehObjforADB4AdbAbsDist        = 0;
// static uint8_t  Signal_VehObjforADB4AdbClassn         = 0;
// static uint8_t  Signal_VehObjforADB4AdbVertAg         = 0;
// static uint16_t Signal_VehObjforADB4AdbObjHozlAgSpdRi = 0;
// static uint16_t Signal_VehObjforADB4AdbObjHozlAgSpdLe = 0;
// static uint16_t Signal_VehObjforADB4AdbHozlAgLe       = 0;
// static uint16_t Signal_VehObjforADB4AdbHozlAgRi       = 0;

// static uint8_t  Signal_AccrPedlRatCntr        = 0;
// static uint8_t  Signal_AccrPedlRatChks        = 0;
// static uint16_t Signal_AccrPedlRatAccrPedlRat = 0;

// static uint8_t  Signal_BrkPedlSnsrSt          = 0;
// static uint8_t  Signal_BrkPedlSnsrChks        = 0;
// static uint8_t  Signal_BrkPedlSnsrCntr        = 0;
// static uint8_t  Signal_BrkPedlSnsrQf          = 0;

// static uint8_t  Signal_AmbTRawQly             = 0;
// static uint16_t Signal_AmbTRawAmbTVal         = 0;

// static uint8_t  Signal_VehBattUSysU           = 0;
// static uint8_t  Signal_VehBattUSysUQf         = 0;

// static uint8_t  Signal_VehObjforADB8AdbTrkInfo        = 0;
// static uint8_t  Signal_VehObjforADB8AdbClassn         = 0;
// static uint8_t  Signal_VehObjforADB8AdbObjDir         = 0;
// static uint16_t Signal_VehObjforADB8AdbAbsDist        = 0;
// static uint8_t  Signal_VehObjforADB8AdbVertAg         = 0;
// static uint16_t Signal_VehObjforADB8AdbHozlAgLe       = 0;
// static uint16_t Signal_VehObjforADB8AdbObjHozlAgSpdLe = 0;
// static uint16_t Signal_VehObjforADB8AdbHozlAgRi       = 0;
// static uint16_t Signal_VehObjforADB8AdbObjHozlAgSpdR  = 0;

// static uint8_t  Signal_DwnLoadDynLtgPrmForLedHiBeamRiLowBriPrm  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForLedHiBeamRiModePrm    = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForLedHiBeamRiUpprBriPrm = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedHiBeamRiOffsTiPrm  = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedHiBeamRiContTiPrm  = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedHiBeamRiTistamp    = 0;

// static uint8_t  Signal_VehObjforADB1AdbObjDir         = 0;
// static uint8_t  Signal_VehObjforADB1AdbTrkInfo        = 0;
// static uint16_t Signal_VehObjforADB1AdbAbsDist        = 0;
// static uint8_t  Signal_VehObjforADB1AdbClassn         = 0;
// static uint8_t  Signal_VehObjforADB1AdbVertAg         = 0;
// static uint16_t Signal_VehObjforADB1AdbObjHozlAgSpdRi = 0;
// static uint16_t Signal_VehObjforADB1AdbObjHozlAgSpdLe = 0;
// static uint16_t Signal_VehObjforADB1AdbHozlAgLe       = 0;
// static uint16_t Signal_VehObjforADB1AdbHozlAgRi       = 0;

// static uint8_t  Signal_LvlgSwtSetReqADModCtrlInhbn    = 0;

// static uint8_t  Signal_OutdBriSts           = 0;

// static uint8_t  Signal_ActvnOfIndcrIndcrOut = 0;

// static uint16_t Signal_IndcrPatCmd1WdTiOff  = 0;
// static uint16_t Signal_IndcrPatCmd1WdTiOn   = 0;

// static uint8_t  Signal_VehSpdLgtQf          = 2;
// static uint16_t Signal_VehSpdLgtA           = 0;

// static uint16_t Signal_TrafficSignForADB1AdbAbsDist   = 0;
// static uint8_t  Signal_TrafficSignForADB1AdbTrkInfo   = 0;
// static uint8_t  Signal_TrafficSignForADB1AdbDetdQly   = 0;
// static uint16_t Signal_TrafficSignForADB1AdbHozlAgRi  = 0;
// static uint16_t Signal_TrafficSignForADB1AdbVertAgTop = 0;
// static uint16_t Signal_TrafficSignForADB1AdbHozlAgLe  = 0;
// static uint16_t Signal_TrafficSignForADB1AdbVertAgBot = 0;

// static uint16_t Signal_BrkPedlValBrkPedlVal = 0;
// static uint16_t Signal_BrkPedlValQf         = 0;

// static uint8_t  Signal_WipgInfoWiprActv     = 0;
// static uint8_t  Signal_WipgInfoWiprInWipgAr = 0;
// static uint8_t  Signal_WipgInfoWipgSpdInfo  = 0;

// static uint8_t  Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampRiModePrm    = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampRiOffsTiPrm  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampRiLowBriPrm  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampRiUpprBriPrm = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampRiContTiPrm  = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampRiTistamp    = 0;

// static uint16_t Signal_TrafficSignForADB2AdbAbsDist   = 0;
// static uint8_t  Signal_TrafficSignForADB2AdbTrkInfo   = 0;
// static uint8_t  Signal_TrafficSignForADB2AdbDetdQly   = 0;
// static uint16_t Signal_TrafficSignForADB2AdbHozlAgRi  = 0;
// static uint16_t Signal_TrafficSignForADB2AdbVertAgTop = 0;
// static uint16_t Signal_TrafficSignForADB2AdbHozlAgLe  = 0;
// static uint16_t Signal_TrafficSignForADB2AdbVertAgBot = 0;

// static uint8_t  Signal_VehObjforADB5AdbClassn         = 0;
// static uint8_t  Signal_VehObjforADB5AdbObjDir         = 0;
// static uint8_t  Signal_VehObjforADB5AdbTrkInfo        = 0;
// static uint16_t Signal_VehObjforADB5AdbAbsDist        = 0;
// static uint8_t  Signal_VehObjforADB5AdbVertAg         = 0;
// static uint16_t Signal_VehObjforADB5AdbObjHozlAgSpdRi = 0;
// static uint16_t Signal_VehObjforADB5AdbHozlAgLe       = 0;
// static uint16_t Signal_VehObjforADB5AdbHozlAgRi       = 0;
// static uint16_t Signal_VehObjforADB5AdbObjHozlAgSpdLe = 0;

// static uint8_t  Signal_VehObjforADB2AdbObjDir         = 0;
// static uint8_t  Signal_VehObjforADB2AdbTrkInfo        = 0;
// static uint16_t Signal_VehObjforADB2AdbAbsDist        = 0;
// static uint8_t  Signal_VehObjforADB2AdbClassn         = 0;
// static uint8_t  Signal_VehObjforADB2AdbVertAg         = 0;
// static uint16_t Signal_VehObjforADB2AdbObjHozlAgSpdRi = 0;
// static uint16_t Signal_VehObjforADB2AdbObjHozlAgSpdLe = 0;
// static uint16_t Signal_VehObjforADB2AdbHozlAgLe       = 0;
// static uint16_t Signal_VehObjforADB2AdbHozlAgRi       = 0;

// static uint8_t  Signal_SteerWhlSnsrQf    = 1;
// static uint16_t Signal_SteerWhlSnsrAg    = 0;
// static uint16_t Signal_SteerWhlSnsrAgSpd = 0;

// static uint8_t  Signal_VehObjforADB6AdbClassn         = 0;
// static uint8_t  Signal_VehObjforADB6AdbObjDir         = 0;
// static uint8_t  Signal_VehObjforADB6AdbTrkInfo        = 0;
// static uint16_t Signal_VehObjforADB6AdbAbsDist        = 0;
// static uint8_t  Signal_VehObjforADB6AdbVertAg         = 0;
// static uint16_t Signal_VehObjforADB6AdbObjHozlAgSpdRi = 0;
// static uint16_t Signal_VehObjforADB6AdbHozlAgLe       = 0;
// static uint16_t Signal_VehObjforADB6AdbHozlAgRi       = 0;
// static uint16_t Signal_VehObjforADB6AdbObjHozlAgSpdLe = 0;

// static uint8_t  Signal_ActnOfLedLoBeamActnOfLedLoBeam = 0;

// static uint8_t  Signal_DwnLoadDynLtgPrmForLedLoBeamRiUpprBriPrm = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedLoBeamRiContTiPrm  = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedLoBeamRiOffsTiPrm  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForLedLoBeamRiModePrm    = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForLedLoBeamRiLowBriPrm  = 0;
// static uint16_t Signal_DwnLoadDynLtgPrmForLedLoBeamRiTistamp    = 0;

// static uint16_t Signal_SuspPosnVertAgSuspPosnVertAg = 0;
// static uint8_t  Signal_SuspPosnVertAgGenQf          = 0;

// static uint8_t  Signal_SuspPosnVertLvlReQf   = 1;
// static uint16_t Signal_SuspPosnVertLvlRe     = 0;
// static uint16_t Signal_SuspPosnVertLvlFrnt   = 0;
// static uint8_t  Signal_SuspPosnVertLvlFrntQf = 1;

// static uint16_t Signal_DwnLoadDynLitPrmLedRiGrilleLampOffsTiPrm  = 0;
// static uint16_t Signal_DwnLoadDynLitPrmLedRiGrilleLampTistamp    = 0;
// static uint8_t  Signal_DwnLoadDynLitPrmLedRiGrilleLampLowBriPrm  = 0;
// static uint8_t  Signal_DwnLoadDynLitPrmLedRiGrilleLampModePrm    = 0;
// static uint8_t  Signal_DwnLoadDynLitPrmLedRiGrilleLampUpprBriPrm = 0;
// static uint16_t Signal_DwnLoadDynLitPrmLedRiGrilleLampContTiPrm  = 0;

// static uint16_t Signal_DwnLoadDynLitPrmLedRiSideLogoLiModePrm    = 0;
// static uint16_t Signal_DwnLoadDynLitPrmLedRISideLogoLiLowBriPrm  = 0;
// static uint8_t  Signal_DwnLoadDynLitPrmLedRiSideLogoLiUpprBriPrm = 0;
// static uint8_t  Signal_DwnLoadDynLitPrmLedRiSideLogoLiTistamp    = 0;
// static uint8_t  Signal_DwnLoadDynLitPrmLedRiSideLogoLiContTiPrm  = 0;
// static uint16_t Signal_DwnLoadDynLitPrmLedRiSideLogoLiOffsTiPrm  = 0;

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp1LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp1OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp1HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp1Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp1Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp1ContinueTime   = 0;

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp2LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp2OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp2HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp2Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp2Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp2ContinueTime   = 0;

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp3LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp3OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp3HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp3Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp3Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp3ContinueTime   = 0;

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp4LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp4OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp4HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp4Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp4Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp4ContinueTime   = 0;

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp5LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp5OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp5HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp5Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp5Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp5ContinueTime   = 0;

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp6LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp6OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp6HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp6Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp6Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp6ContinueTime   = 0;

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp7LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp7OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp7HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp7Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp7Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp7ContinueTime   = 0;

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp8LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp8OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp8HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp8Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp8Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp8ContinueTime   = 0;

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp9LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp9OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp9HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp9Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp9Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp9ContinueTime   = 0;

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp10LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp10OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp10HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp10Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp10Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp10ContinueTime   = 0;

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp11LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp11OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp11HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp11Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp11Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp11ContinueTime   = 0;

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp12LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp12OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp12HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp12Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp12Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp12ContinueTime   = 0;

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp13LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp13OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp13HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp13Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp13Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp13ContinueTime   = 0;

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp14LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp14OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp14HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp14Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp14Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp14ContinueTime   = 0;

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp15LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp15OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp15HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp15Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp15Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp15ContinueTime   = 0;

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp16LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp16OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp16HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp16Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp16Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp16ContinueTime   = 0;

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp17LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp17OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp17HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp17Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp17Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp17ContinueTime   = 0;

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp18LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp18OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp18HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp18Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp18Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp18ContinueTime   = 0;

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp19LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp19OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp19HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp19Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp19Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp19ContinueTime   = 0;

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp20LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp20OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp20HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp20Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp20Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp20ContinueTime   = 0;

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp21LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp21OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp21HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp21Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp21Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp21ContinueTime   = 0;

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp22LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp22OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp22HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp22Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp22Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp22ContinueTime   = 0;

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp23LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp23OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp23HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp23Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp23Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp23ContinueTime   = 0;

// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp24LowBrightness  = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp24OffsetTime     = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp24HighBrightness = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp24Mode1          = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp24Timestamp      = 0;
// static uint8_t  Signal_DwnLoadDynLtgPrmForFrntRIGrp24ContinueTime   = 0;

// static uint8_t  Signal_TiAndDateIndcnDay       = 0;
// static uint8_t  Signal_TiAndDateIndcnYr1       = 0;
// static uint8_t  Signal_TiAndDateIndcnMins1     = 0;
// static uint8_t  Signal_TiAndDateIndcnMth1      = 0;
// static uint8_t  Signal_TiAndDateIndcnHr1       = 0;
// static uint8_t  Signal_TiAndDateIndcnSec1      = 0;
// static uint8_t  Signal_TiAndDateIndcnDataValid = 0;


// static uint8_t  Signal_DwnLoadDynLitPrmForLedHiBeamLeLowBriPrm  = 0;
// static uint8_t  Signal_DwnLoadDynLitPrmForLedHiBeamLeModePrm    = 0;
// static uint8_t  Signal_DwnLoadDynLitPrmForLedHiBeamLeUpprBriPrm = 0;
// static uint16_t Signal_DwnLoadDynLitPrmForLedHiBeamLeOffsTiPrm  = 0;
// static uint16_t Signal_DwnLoadDynLitPrmForLedHiBeamLeContTiPrm  = 0;
// static uint16_t Signal_DwnLoadDynLitPrmForLedHiBeamLeTistamp    = 0;


// static uint16_t Signal_DwnLoadDynLitPrmForLedLoBeamLeContTiPrm  = 0;
// static uint8_t  Signal_DwnLoadDynLitPrmForLedLoBeamLeModePrm    = 0;
// static uint8_t  Signal_DwnLoadDynLitPrmForLedLoBeamLeLowBriPrm  = 0;
// static uint16_t Signal_DwnLoadDynLitPrmForLedLoBeamLeOffsTiPrm  = 0;
// static uint8_t  Signal_DwnLoadDynLitPrmForLedLoBeamLeUpprBriPrm = 0;
// static uint16_t Signal_DwnLoadDynLitPrmForLedLoBeamLeTistamp    = 0;

// #endif

// /****************************************************************
//  *                                                              *
//  *                   Global Variable Define                     *
//  *                                                              *
//  ****************************************************************/

// /****************************************************************
//  *                                                              *
//  *                   Private Functions Define                   *
//  *                                                              *
//  ****************************************************************/

// /****************************************************************
//  *                                                              *
//  *                   Global Functions Define                    *
//  *                                                              *
//  ****************************************************************/
// /*****************************************************************FLAG***********************************************************************/
// Std_ReturnType Interface_SetSignalFlag_UsageModeRcvd(void)
// {
//     UsageModeRcvd_Flag = 1; 
//     return E_OK;
// }

// uint8_t Interface_GetSignalFlag_UsageModeRcvd(void)
// {
//     return UsageModeRcvd_Flag ; 
// }

// Std_ReturnType Interface_SetSignalFlag_VehSpeedRcvd(void)
// {
//     VehSpeedRcvd_Flag = 1; 
//     return E_OK;
// }

// uint8_t Interface_GetSignalFlag_VehSpeedRcvd(void)
// {
//     return VehSpeedRcvd_Flag ; 
// }


// /************************************************************Tx Signal***************************************************************************/
// Std_ReturnType Interface_SetSignal_StsOfLedHiBeam(uint32_t SignalValue)
// {
//     StsOfLedHiBeamLe = SignalValue;
//     return E_OK;
// }

// Std_ReturnType Interface_GetSignal_StsOfLedHiBeam(uint32_t *SignalValue)
// {
//     *SignalValue = StsOfLedHiBeamLe;
//     return E_OK;
// }

// Std_ReturnType Interface_SetSignal_StsOfLedLoBeam(uint32_t SignalValue)
// {
//     StsOfLedLoBeamLe = SignalValue;
//     return E_OK;
// }

// Std_ReturnType Interface_GetSignal_StsOfLedLoBeam(uint32_t *SignalValue)
// {
//     *SignalValue = StsOfLedLoBeamLe;
//     return E_OK;
// }

// Std_ReturnType Interface_SetSignal_ExtrLiShowStoreStsFrnt(uint32_t SignalValue)
// {
//     ExtrLiShowStoreStsFrntLe = SignalValue;
//     return E_OK;
// }

// Std_ReturnType Interface_GetSignal_ExtrLiShowStoreStsFrnt(uint32_t *SignalValue)
// {
//     *SignalValue = ExtrLiShowStoreStsFrntLe;
//     return E_OK;
// }

// Std_ReturnType Interface_SetSignal_StsOfLedLeLogoLamp(uint32_t SignalValue)
// {
//     StsOfLedLeLogoLamp = SignalValue;
//     return E_OK;
// }

// Std_ReturnType Interface_GetSignal_StsOfLedLeLogoLamp(uint32_t *SignalValue)
// {
//     *SignalValue = StsOfLedLeLogoLamp;
//     return E_OK;
// }

// Std_ReturnType Interface_SetSignal_StsOfLedFrntTurnIndcr(uint32_t SignalValue)
// {
//     StsOfLedFrntTurnIndcrLe = SignalValue;
//     return E_OK;
// }

// Std_ReturnType Interface_GetSignal_StsOfLedFrntTurnIndcr(uint32_t *SignalValue)
// {
//     *SignalValue = StsOfLedFrntTurnIndcrLe;
//     return E_OK;
// }

// Std_ReturnType Interface_SetSignal_StsOfTouristMod(uint32_t SignalValue)
// {
//     StsOfTouristModLe = SignalValue;
//     return E_OK;
// }

// Std_ReturnType Interface_GetSignal_StsOfTouristMod(uint32_t *SignalValue)
// {
//     *SignalValue = StsOfTouristModLe;
//     return E_OK;
// }

// Std_ReturnType Interface_SetSignal_StsOfLedDaytiRunngLamp(uint32_t SignalValue)
// {
//     StsOfLedDaytiRunngLampLe = SignalValue;
//     return E_OK;
// }

// Std_ReturnType Interface_GetSignal_StsOfLedDaytiRunngLamp(uint32_t *SignalValue)
// {
//     *SignalValue = StsOfLedDaytiRunngLampLe;
//     return E_OK;
// }

// Std_ReturnType Interface_SetSignal_StsOfLedFrntFogLamp(uint32_t SignalValue)
// {
//     StsOfLedFrntFogLampLe = SignalValue;
//     return E_OK;
// }

// Std_ReturnType Interface_GetSignal_StsOfLedFrntFogLamp(uint32_t *SignalValue)
// {
//     *SignalValue = StsOfLedFrntFogLampLe;
//     return E_OK;
// }

// Std_ReturnType Interface_SetSignal_StsOfAfs(uint32_t SignalValue)
// {
//     StsOfAfsLe = SignalValue;
//     return E_OK;
// }

// Std_ReturnType Interface_GetSignal_StsOfAfs(uint32_t *SignalValue)
// {
//     *SignalValue = StsOfAfsLe;
//     return E_OK;
// }

// Std_ReturnType Interface_SetSignal_StsOfAhbc(uint32_t SignalValue)
// {
//     StsOfAhbcLe = SignalValue;
//     return E_OK;
// }

// Std_ReturnType Interface_GetSignal_StsOfAhbc(uint32_t *SignalValue)
// {
//     *SignalValue = StsOfAhbcLe;
//     return E_OK;
// }

// Std_ReturnType Interface_SetSignal_StsOfSwvlg(uint32_t SignalValue)
// {
//     StsOfSwvlgLe = SignalValue;
//     return E_OK;
// }

// Std_ReturnType Interface_GetSignal_StsOfSwvlg(uint32_t *SignalValue)
// {
//     *SignalValue = StsOfSwvlgLe;
//     return E_OK;
// }

// Std_ReturnType Interface_SetSignal_StsOfFrntSideMkrLamp2(uint32_t SignalValue)
// {
//     StsOfFrntSideMkrLampLe2 = SignalValue;
//     return E_OK;
// }

// Std_ReturnType Interface_GetSignal_StsOfFrntSideMkrLamp2(uint32_t *SignalValue)
// {
//     *SignalValue = StsOfFrntSideMkrLampLe2;
//     return E_OK;
// }

// Std_ReturnType Interface_SetSignal_StsOfLedCornrgLamp(uint32_t SignalValue)
// {
//     StsOfLedCornrgLampLe = SignalValue;
//     return E_OK;
// }

// Std_ReturnType Interface_GetSignal_StsOfLedCornrgLamp(uint32_t *SignalValue)
// {
//     *SignalValue = StsOfLedCornrgLampLe;
//     return E_OK;
// }

// Std_ReturnType Interface_SetSignal_StsOfLedFrntPosnLamp(uint32_t SignalValue)
// {
//     StsOfLedFrntPosnLampLe = SignalValue;
//     return E_OK;
// }

// Std_ReturnType Interface_GetSignal_StsOfLedFrntPosnLamp(uint32_t *SignalValue)
// {
//     *SignalValue = StsOfLedFrntPosnLampLe;
//     return E_OK;
// }

// Std_ReturnType Interface_SetSignal_HdlampLeInpSts1(uint32_t SignalValue)
// {
//     HdlampLeInpSts1 = SignalValue;
//     return E_OK;
// }

// Std_ReturnType Interface_GetSignal_HdlampLeInpSts1(uint32_t *SignalValue)
// {
//     *SignalValue = HdlampLeInpSts1;
//     return E_OK;
// }

// Std_ReturnType Interface_SetSignal_HdlampLeInpSts2(uint32_t SignalValue)
// {
//     HdlampLeInpSts2 = SignalValue;
//     return E_OK;
// }

// Std_ReturnType Interface_GetSignal_HdlampLeInpSts2(uint32_t *SignalValue)
// {
//     *SignalValue = HdlampLeInpSts2;
//     return E_OK;
// }

// Std_ReturnType Interface_SetSignal_ExtrLiShowActvnFrntLeFb(uint32_t SignalValue)
// {
//     ExtrLiShowActvnFrntLeFb = SignalValue;
//     return E_OK;
// }

// Std_ReturnType Interface_GetSignal_ExtrLiShowActvnFrntLeFb(uint32_t *SignalValue)
// {
//     *SignalValue = ExtrLiShowActvnFrntLeFb;
//     return E_OK;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadStsFbOfHdlamp(uint32_t SignalValue)
// {
//     DwnLoadStsFbOfHdlampLe = SignalValue;
//     return E_OK;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadStsFbOfHdlamp(uint32_t *SignalValue)
// {
//     *SignalValue = DwnLoadStsFbOfHdlampLe;
//     return E_OK;
// }

// Std_ReturnType Interface_SetSignal_ExtrLiShowActvnLeLogoFb(uint32_t SignalValue)
// {
//     ExtrLiShowActvnLeLogoFb = SignalValue;
//     return E_OK;
// }

// Std_ReturnType Interface_GetSignal_ExtrLiShowActvnLeLogoFb(uint32_t *SignalValue)
// {
//     *SignalValue = ExtrLiShowActvnLeLogoFb;
//     return E_OK;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadStsFbOfLogoLamp(uint32_t SignalValue)
// {
//     DwnLoadStsFbOfLogoLampLe = SignalValue;
//     return E_OK;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadStsFbOfLogoLamp(uint32_t *SignalValue)
// {
//     *SignalValue = DwnLoadStsFbOfLogoLampLe;
//     return E_OK;
// }

// Std_ReturnType Interface_SetSignal_StsOfWelGbyFrnt(uint32_t SignalValue)
// {
//     StsOfWelGbyFrntLe = SignalValue;
//     return E_OK;
// }

// Std_ReturnType Interface_GetSignal_StsOfWelGbyFrnt(uint32_t *SignalValue)
// {
//     *SignalValue = StsOfWelGbyFrntLe;
//     return E_OK;
// }

// Std_ReturnType Interface_SetSignal_StsOfLvlg(uint32_t SignalValue)
// {
//     StsOfLvlg = SignalValue;
//     return E_OK;
// }

// Std_ReturnType Interface_GetSignal_StsOfLvlg(uint32_t *SignalValue)
// {
//     *SignalValue = StsOfLvlg;
//     return E_OK;
// }

// Std_ReturnType Interface_SetSignal_LvlgMtrAgle(uint32_t SignalValue)
// {
//     LvlgMtrAgle = SignalValue;
//     return E_OK;
// }

// Std_ReturnType Interface_GetSignal_LvlgMtrAgle(uint32_t *SignalValue)
// {
//     *SignalValue = LvlgMtrAgle;
//     return E_OK;
// }



// /************************************************************Rx Signal***************************************************************************/
// #if HCM_LEFT_SIDE
// /******************************/
// /* Set Signal Function (Left) */
// /******************************/

// Std_ReturnType Interface_SetSignal_ActnOfLedCornrgLampLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActnOfLedCornrgLampLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActnOfLedDaytiRunngLamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActnOfLedDaytiRunngLamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActnOfLedFrntFogLamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActnOfLedFrntFogLamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActnOfLedHiBeam(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActnOfLedHiBeam = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActnOfLedPosnLamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActnOfLedPosnLamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActvnOfAfs(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActvnOfAfs = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActvnOfAhbc(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActvnOfAhbc = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActvnOfAhl(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActvnOfAhl = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActvnOfDbl(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActvnOfDbl = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActvnOfGoodByeLi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActvnOfGoodByeLi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActvnOfTouristMod(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActvnOfTouristMod = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActvnOfWelcomeLi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActvnOfWelcomeLi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActnOfLedLoBeamActnOfLedLoBeam(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActnOfLedLoBeamActnOfLedLoBeam = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActvnOfIndcrIndcrOut(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActvnOfIndcrIndcrOut = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_WipgAutFrntMod(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_WipgAutFrntMod = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_RainLi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_RainLi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_CameraStsforAHBC(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_CameraStsforAHBC = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActnOfLedPosnLampDyn(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActnOfLedPosnLampDyn = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActnOfLedFrntCrossLampDyn(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActnOfLedFrntCrossLampDyn = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActnOfLedGrilleLampDyn(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActnOfLedGrilleLampDyn = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActnOfLedLeLogoLampDyn(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActnOfLedLeLogoLampDyn = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActvnOfHomeSafe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActvnOfHomeSafe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_YawRateReqdByDrvr(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_YawRateReqdByDrvr = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_CarTiGlb(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_CarTiGlb = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_Body2CntrForMissCom(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_Body2CntrForMissCom = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActnOfLedFrntCrossLamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActnOfLedFrntCrossLamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActnOfLedGrilleLamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActnOfLedGrilleLamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActnOfLedLeLogoLamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActnOfLedLeLogoLamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ExtrLiRlyPwrDwn(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ExtrLiRlyPwrDwn = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_BkpOfDstTrvld(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_BkpOfDstTrvld = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_LiOprnMod(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_LiOprnMod = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_AutWinWipgCmd(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_AutWinWipgCmd = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_IndcrSts(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_IndcrSts = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_LitArea(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_LitArea = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActvnOfApproach(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActvnOfApproach = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActvnOfCarLoctr(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActvnOfCarLoctr = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActvnOfWaitMode(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActvnOfWaitMode = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_IndcrNoSeq(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_IndcrNoSeq = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ExtrLiShowFileTxReq(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ExtrLiShowFileTxReq = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ExtrLiShowActvnReq(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ExtrLiShowActvnReq = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_WelcomeGoodbyeModeReq(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_WelcomeGoodbyeModeReq = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_WelLiFileTxReq(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_WelLiFileTxReq = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActvnOfLiForComity(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActvnOfLiForComity = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActvnOfLiForSpkr(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActvnOfLiForSpkr = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActvnOfLiForWait(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActvnOfLiForWait = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActvnOfADB(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActvnOfADB = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehCfgPrmExtCCPBytePosn5(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehCfgPrmExtCCPBytePosn5 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehCfgPrmExtCCPBytePosn6(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehCfgPrmExtCCPBytePosn6 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehCfgPrmExtCCPBytePosn2(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehCfgPrmExtCCPBytePosn2 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehCfgPrmExtCCPBytePosn3(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehCfgPrmExtCCPBytePosn3 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehCfgPrmExtCCPBytePosn8(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehCfgPrmExtCCPBytePosn8 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehCfgPrmExtCCPBytePosn4(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehCfgPrmExtCCPBytePosn4 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehCfgPrmExtCCPBytePosn7(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehCfgPrmExtCCPBytePosn7 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehCfgPrmExtBlkIDBytePosn1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehCfgPrmExtBlkIDBytePosn1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TrafficSignForADB1AdbAbsDist(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TrafficSignForADB1AdbAbsDist = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TrafficSignForADB1AdbTrkInfo(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TrafficSignForADB1AdbTrkInfo = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TrafficSignForADB1AdbDetdQly(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TrafficSignForADB1AdbDetdQly = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TrafficSignForADB1AdbHozlAgRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TrafficSignForADB1AdbHozlAgRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TrafficSignForADB1AdbVertAgTop(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TrafficSignForADB1AdbVertAgTop = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TrafficSignForADB1AdbHozlAgLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TrafficSignForADB1AdbHozlAgLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TrafficSignForADB1AdbVertAgBot(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TrafficSignForADB1AdbVertAgBot = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB7AdbAbsDist(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB7AdbAbsDist = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB7AdbClassn(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB7AdbClassn = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB7AdbTrkInfo(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB7AdbTrkInfo = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB7AdbObjDir(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB7AdbObjDir = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB7AdbVertAg(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB7AdbVertAg = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB7AdbObjHozlAgSpdRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB7AdbObjHozlAgSpdRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB7AdbHozlAgLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB7AdbHozlAgLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB7AdbHozlAgRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB7AdbHozlAgRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB7AdbObjHozlAgSpdLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB7AdbObjHozlAgSpdLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB5AdbClassn(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB5AdbClassn = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB5AdbObjDir(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB5AdbObjDir = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB5AdbTrkInfo(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB5AdbTrkInfo = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB5AdbAbsDist(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB5AdbAbsDist = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB5AdbVertAg(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB5AdbVertAg = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB5AdbObjHozlAgSpdRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB5AdbObjHozlAgSpdRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB5AdbHozlAgLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB5AdbHozlAgLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB5AdbHozlAgRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB5AdbHozlAgRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB5AdbObjHozlAgSpdLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB5AdbObjHozlAgSpdLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehCfgPrmCCPBytePosn6(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehCfgPrmCCPBytePosn6 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehCfgPrmBlkIDBytePosn1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehCfgPrmBlkIDBytePosn1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehCfgPrmCCPBytePosn4(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehCfgPrmCCPBytePosn4 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehCfgPrmCCPBytePosn3(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehCfgPrmCCPBytePosn3 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehCfgPrmCCPBytePosn2(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehCfgPrmCCPBytePosn2 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehCfgPrmCCPBytePosn8(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehCfgPrmCCPBytePosn8 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehCfgPrmCCPBytePosn7(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehCfgPrmCCPBytePosn7 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehCfgPrmCCPBytePosn5(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehCfgPrmCCPBytePosn5 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehModMngtGlbSafe1Chks(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehModMngtGlbSafe1Chks = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehModMngtGlbSafe1CarModSts1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehModMngtGlbSafe1CarModSts1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehModMngtGlbSafe1Cntr(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehModMngtGlbSafe1Cntr = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehModMngtGlbSafe1EgyLvlElecSubtyp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehModMngtGlbSafe1EgyLvlElecSubtyp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehModMngtGlbSafe1PwrLvlElecSubtyp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehModMngtGlbSafe1PwrLvlElecSubtyp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehModMngtGlbSafe1CarModSubtypWdCar(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehModMngtGlbSafe1CarModSubtypWdCar = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehModMngtGlbSafe1UsgModSts(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehModMngtGlbSafe1UsgModSts = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehModMngtGlbSafe1PwrLvlElecMai(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehModMngtGlbSafe1PwrLvlElecMai = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehModMngtGlbSafe1EgyLvlElecMai(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehModMngtGlbSafe1EgyLvlElecMai = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehModMngtGlbSafe1FltEgyCnsWdSts(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehModMngtGlbSafe1FltEgyCnsWdSts = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB8AdbTrkInfo(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB8AdbTrkInfo = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB8AdbClassn(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB8AdbClassn = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB8AdbObjDir(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB8AdbObjDir = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB8AdbAbsDist(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB8AdbAbsDist = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB8AdbVertAg(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB8AdbVertAg = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB8AdbHozlAgLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB8AdbHozlAgLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB8AdbObjHozlAgSpdLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB8AdbObjHozlAgSpdLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB8AdbHozlAgRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB8AdbHozlAgRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB8AdbObjHozlAgSpdR(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB8AdbObjHozlAgSpdR = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedCornrgLampLeUpprBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedCornrgLampLeUpprBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedCornrgLampLeContTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedCornrgLampLeContTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedCornrgLampLeLowBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedCornrgLampLeLowBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedCornrgLampLeOffsTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedCornrgLampLeOffsTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedCornrgLampLeModePrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedCornrgLampLeModePrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedCornrgLampLeTistamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedCornrgLampLeTistamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedFrntPosnLampLeLowBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedFrntPosnLampLeLowBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedFrntPosnLampLeUpprBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedFrntPosnLampLeUpprBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedFrntPosnLampLeContTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedFrntPosnLampLeContTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedFrntPosnLampLeOffsTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedFrntPosnLampLeOffsTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedFrntPosnLampLeModePrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedFrntPosnLampLeModePrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedFrntPosnLampLeTistamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedFrntPosnLampLeTistamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB3AdbAbsDist(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB3AdbAbsDist = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB3AdbTrkInfo(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB3AdbTrkInfo = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB3AdbClassn(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB3AdbClassn = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB3AdbObjDir(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB3AdbObjDir = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB3AdbVertAg(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB3AdbVertAg = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB3AdbObjHozlAgSpdLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB3AdbObjHozlAgSpdLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB3AdbObjHozlAgSpdRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB3AdbObjHozlAgSpdRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB3AdbHozlAgLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB3AdbHozlAgLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB3AdbHozlAgRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB3AdbHozlAgRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_BrkPedlrRatQf(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_BrkPedlrRatQf = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_BrkPedlrRatPerc(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_BrkPedlrRatPerc = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB2AdbObjDir(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB2AdbObjDir = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB2AdbTrkInfo(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB2AdbTrkInfo = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB2AdbAbsDist(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB2AdbAbsDist = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB2AdbClassn(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB2AdbClassn = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB2AdbVertAg(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB2AdbVertAg = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB2AdbObjHozlAgSpdRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB2AdbObjHozlAgSpdRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB2AdbObjHozlAgSpdLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB2AdbObjHozlAgSpdLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB2AdbHozlAgLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB2AdbHozlAgLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB2AdbHozlAgRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB2AdbHozlAgRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB6AdbClassn(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB6AdbClassn = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB6AdbObjDir(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB6AdbObjDir = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB6AdbTrkInfo(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB6AdbTrkInfo = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB6AdbAbsDist(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB6AdbAbsDist = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB6AdbVertAg(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB6AdbVertAg = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB6AdbObjHozlAgSpdRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB6AdbObjHozlAgSpdRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB6AdbHozlAgLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB6AdbHozlAgLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB6AdbHozlAgRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB6AdbHozlAgRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB6AdbObjHozlAgSpdLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB6AdbObjHozlAgSpdLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_AccrPedlRatCntr(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_AccrPedlRatCntr = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_AccrPedlRatChks(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_AccrPedlRatChks = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_AccrPedlRatAccrPedlRat(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_AccrPedlRatAccrPedlRat = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_BrkPedlSnsrSt(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_BrkPedlSnsrSt = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_BrkPedlSnsrChks(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_BrkPedlSnsrChks = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_BrkPedlSnsrCntr(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_BrkPedlSnsrCntr = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_BrkPedlSnsrQf(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_BrkPedlSnsrQf = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_AmbTRawQly(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_AmbTRawQly = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_AmbTRawAmbTVal(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_AmbTRawAmbTVal = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehBattUSysU(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehBattUSysU = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehBattUSysUQf(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehBattUSysUQf = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedDaytiRunngLampLeModePrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampLeModePrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedDaytiRunngLampLeOffsTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampLeOffsTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedDaytiRunngLampLeLowBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampLeLowBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedDaytiRunngLampLeUpprBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampLeUpprBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedDaytiRunngLampLeContTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampLeContTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedDaytiRunngLampLeTistamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampLeTistamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_LvlgSwtSetReqADModCtrlInhbn(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_LvlgSwtSetReqADModCtrlInhbn = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_OutdBriSts(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_OutdBriSts = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB1AdbObjDir(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB1AdbObjDir = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB1AdbTrkInfo(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB1AdbTrkInfo = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB1AdbAbsDist(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB1AdbAbsDist = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB1AdbClassn(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB1AdbClassn = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB1AdbVertAg(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB1AdbVertAg = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB1AdbObjHozlAgSpdRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB1AdbObjHozlAgSpdRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB1AdbObjHozlAgSpdLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB1AdbObjHozlAgSpdLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB1AdbHozlAgLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB1AdbHozlAgLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB1AdbHozlAgRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB1AdbHozlAgRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB4AdbObjDir(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB4AdbObjDir = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB4AdbTrkInfo(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB4AdbTrkInfo = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB4AdbAbsDist(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB4AdbAbsDist = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB4AdbClassn(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB4AdbClassn = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB4AdbVertAg(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB4AdbVertAg = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB4AdbObjHozlAgSpdRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB4AdbObjHozlAgSpdRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB4AdbObjHozlAgSpdLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB4AdbObjHozlAgSpdLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB4AdbHozlAgLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB4AdbHozlAgLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB4AdbHozlAgRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB4AdbHozlAgRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedAllWthrLampLeOffsTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedAllWthrLampLeOffsTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedAllWthrLampLeContTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedAllWthrLampLeContTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedAllWthrLampLeModePrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedAllWthrLampLeModePrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedAllWthrLampLeLowBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedAllWthrLampLeLowBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedAllWthrLampLeUpprBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedAllWthrLampLeUpprBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedAllWthrLampLeTistamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedAllWthrLampLeTistamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmForLedLoBeamLeContTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmForLedLoBeamLeContTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmForLedLoBeamLeModePrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmForLedLoBeamLeModePrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmForLedLoBeamLeLowBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmForLedLoBeamLeLowBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmForLedLoBeamLeOffsTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmForLedLoBeamLeOffsTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmForLedLoBeamLeUpprBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmForLedLoBeamLeUpprBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmForLedLoBeamLeTistamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmForLedLoBeamLeTistamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_SteerWhlSnsrQf(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_SteerWhlSnsrQf = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_SteerWhlSnsrAg(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_SteerWhlSnsrAg = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_SteerWhlSnsrAgSpd(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_SteerWhlSnsrAgSpd = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmForLedHiBeamLeLowBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmForLedHiBeamLeLowBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmForLedHiBeamLeModePrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmForLedHiBeamLeModePrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmForLedHiBeamLeUpprBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmForLedHiBeamLeUpprBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmForLedHiBeamLeOffsTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmForLedHiBeamLeOffsTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmForLedHiBeamLeContTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmForLedHiBeamLeContTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmForLedHiBeamLeTistamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmForLedHiBeamLeTistamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeUpprBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeUpprBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeModePrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeModePrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeContTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeContTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeOffsTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeOffsTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeLowBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeLowBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeTistamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeTistamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehSpdLgtQf(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehSpdLgtQf = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehSpdLgtA(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehSpdLgtA = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_IndcrPatCmd1WdTiOff(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_IndcrPatCmd1WdTiOff = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_IndcrPatCmd1WdTiOn(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_IndcrPatCmd1WdTiOn = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TrafficSignForADB2AdbAbsDist(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TrafficSignForADB2AdbAbsDist = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TrafficSignForADB2AdbTrkInfo(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TrafficSignForADB2AdbTrkInfo = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TrafficSignForADB2AdbDetdQly(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TrafficSignForADB2AdbDetdQly = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TrafficSignForADB2AdbHozlAgRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TrafficSignForADB2AdbHozlAgRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TrafficSignForADB2AdbVertAgTop(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TrafficSignForADB2AdbVertAgTop = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TrafficSignForADB2AdbHozlAgLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TrafficSignForADB2AdbHozlAgLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TrafficSignForADB2AdbVertAgBot(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TrafficSignForADB2AdbVertAgBot = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforAHBAdbObjDir(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforAHBAdbObjDir = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforAHBAdbDetdQly(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforAHBAdbDetdQly = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforAHBAdbClassn(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforAHBAdbClassn = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforAHBAdbClassnQly(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforAHBAdbClassnQly = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforAHBAdbAbsDist(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforAHBAdbAbsDist = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforAHBAdbTrkInfo(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforAHBAdbTrkInfo = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforAHBAdbObjVertAgSpd(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforAHBAdbObjVertAgSpd = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforAHBAdbObjHozlAgSpd(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforAHBAdbObjHozlAgSpd = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforAHBAdbVertAg(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforAHBAdbVertAg = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_BrkPedlValBrkPedlVal(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_BrkPedlValBrkPedlVal = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_BrkPedlValQf(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_BrkPedlValQf = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_WipgInfoWiprActv(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_WipgInfoWiprActv = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_WipgInfoWiprInWipgAr(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_WipgInfoWiprInWipgAr = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_WipgInfoWipgSpdInfo(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_WipgInfoWipgSpdInfo = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TooManyCars(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TooManyCars = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_SuspPosnVertAgSuspPosnVertAg(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_SuspPosnVertAgSuspPosnVertAg = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_SuspPosnVertAgGenQf(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_SuspPosnVertAgGenQf = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_SuspPosnVertLvlReQf(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_SuspPosnVertLvlReQf = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_SuspPosnVertLvlRe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_SuspPosnVertLvlRe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_SuspPosnVertLvlFrnt(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_SuspPosnVertLvlFrnt = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_SuspPosnVertLvlFrntQf(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_SuspPosnVertLvlFrntQf = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmLedLeGrilleLampOffsTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmLedLeGrilleLampOffsTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmLedLeGrilleLampTistamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmLedLeGrilleLampTistamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmLedLeGrilleLampLowBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmLedLeGrilleLampLowBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmLedLeGrilleLampModePrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmLedLeGrilleLampModePrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmLedLeGrilleLampUpprBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmLedLeGrilleLampUpprBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmLedLeGrilleLampContTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmLedLeGrilleLampContTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmLedLeSideLogoLiModePrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmLedLeSideLogoLiModePrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmLedLeSideLogoLiLowBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmLedLeSideLogoLiLowBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmLedLeSideLogoLiUpprBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmLedLeSideLogoLiUpprBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmLedLeSideLogoLiTistamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmLedLeSideLogoLiTistamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmLedLeSideLogoLiContTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmLedLeSideLogoLiContTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmLedLeSideLogoLiOffsTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmLedLeSideLogoLiOffsTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp1LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp1LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp1OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp1OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp1HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp1HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp1Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp1Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp1Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp1Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp1ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp1ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp2LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp2LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp2OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp2OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp2HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp2HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp2Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp2Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp2Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp2Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp2ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp2ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp3LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp3LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp3OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp3OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp3HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp3HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp3Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp3Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp3Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp3Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp3ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp3ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp4LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp4LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp4OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp4OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp4HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp4HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp4Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp4Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp4Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp4Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp4ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp4ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp5LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp5LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp5OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp5OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp5HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp5HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp5Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp5Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp5Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp5Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp5ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp5ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp6LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp6LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp6OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp6OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp6HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp6HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp6Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp6Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp6Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp6Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp6ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp6ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp7LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp7LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp7OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp7OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp7HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp7HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp7Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp7Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp7Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp7Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp7ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp7ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp8LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp8LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp8OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp8OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp8HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp8HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp8Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp8Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp8Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp8Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp8ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp8ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp9LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp9LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp9OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp9OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp9HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp9HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp9Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp9Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp9Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp9Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp9ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp9ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp10LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp10LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp10OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp10OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp10HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp10HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp10Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp10Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp10Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp10Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp10ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp10ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp11LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp11LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp11OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp11OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp11HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp11HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp11Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp11Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp11Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp11Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp11ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp11ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp12LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp12LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp12OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp12OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp12HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp12HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp12Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp12Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp12Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp12Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp12ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp12ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp13LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp13LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp13OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp13OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp13HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp13HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp13Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp13Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp13Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp13Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp13ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp13ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp14LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp14LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp14OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp14OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp14HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp14HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp14Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp14Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp14Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp14Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp14ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp14ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp15LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp15LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp15OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp15OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp15HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp15HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp15Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp15Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp15Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp15Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp15ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp15ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp16LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp16LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp16OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp16OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp16HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp16HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp16Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp16Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp16Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp16Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp16ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp16ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp17LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp17LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp17OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp17OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp17HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp17HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp17Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp17Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp17Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp17Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp17ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp17ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp18LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp18LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp18OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp18OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp18HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp18HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp18Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp18Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp18Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp18Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp18ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp18ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp19LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp19LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp19OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp19OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp19HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp19HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp19Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp19Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp19Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp19Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp19ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp19ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp20LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp20LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp20OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp20OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp20HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp20HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp20Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp20Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp20Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp20Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp20ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp20ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp21LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp21LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp21OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp21OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp21HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp21HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp21Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp21Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp21Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp21Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp21ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp21ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp22LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp22LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp22OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp22OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp22HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp22HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp22Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp22Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp22Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp22Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp22ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp22ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp23LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp23LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp23OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp23OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp23HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp23HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp23Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp23Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp23Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp23Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp23ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp23ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp24LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp24LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp24OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp24OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp24HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp24HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp24Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp24Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp24Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp24Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntLeGrp24ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntLeGrp24ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TiAndDateIndcnDay(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TiAndDateIndcnDay = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TiAndDateIndcnYr1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TiAndDateIndcnYr1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TiAndDateIndcnMins1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TiAndDateIndcnMins1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TiAndDateIndcnMth1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TiAndDateIndcnMth1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TiAndDateIndcnHr1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TiAndDateIndcnHr1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TiAndDateIndcnSec1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TiAndDateIndcnSec1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TiAndDateIndcnDataValid(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TiAndDateIndcnDataValid = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DHUcontrolleftcorneringlamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DHUcontrolleftcorneringlamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DHUcontrolleftdaytimerunninglamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DHUcontrolleftdaytimerunninglamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DHUcontrolleftfroglight(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DHUcontrolleftfroglight = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DHUcontrollefthighbeamlamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DHUcontrollefthighbeamlamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DHUcontrolleftlowbeamlamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DHUcontrolleftlowbeamlamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DHUcontrolleftpositionlamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DHUcontrolleftpositionlamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforAHBAdbHozlAg(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforAHBAdbHozlAg = SignalValue;
//     return rtval;
// }

// /******************************/
// /* Get Signal Function (Left) */
// /******************************/

// Std_ReturnType Interface_GetSignal_ActnOfLedCornrgLampLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActnOfLedCornrgLampLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActnOfLedDaytiRunngLamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActnOfLedDaytiRunngLamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActnOfLedFrntFogLamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActnOfLedFrntFogLamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActnOfLedHiBeam(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActnOfLedHiBeam;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActnOfLedPosnLamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActnOfLedPosnLamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActvnOfAfs(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActvnOfAfs;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActvnOfAhbc(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActvnOfAhbc;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActvnOfAhl(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActvnOfAhl;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActvnOfDbl(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActvnOfDbl;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActvnOfGoodByeLi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActvnOfGoodByeLi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActvnOfTouristMod(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActvnOfTouristMod;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActvnOfWelcomeLi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActvnOfWelcomeLi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActnOfLedLoBeamActnOfLedLoBeam(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActnOfLedLoBeamActnOfLedLoBeam;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActvnOfIndcrIndcrOut(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActvnOfIndcrIndcrOut;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_WipgAutFrntMod(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_WipgAutFrntMod;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_RainLi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_RainLi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_CameraStsforAHBC(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_CameraStsforAHBC;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActnOfLedPosnLampDyn(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActnOfLedPosnLampDyn;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActnOfLedFrntCrossLampDyn(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActnOfLedFrntCrossLampDyn;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActnOfLedGrilleLampDyn(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActnOfLedGrilleLampDyn;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActnOfLedLeLogoLampDyn(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActnOfLedLeLogoLampDyn;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActvnOfHomeSafe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActvnOfHomeSafe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_YawRateReqdByDrvr(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_YawRateReqdByDrvr;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_CarTiGlb(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_CarTiGlb;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_Body2CntrForMissCom(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_Body2CntrForMissCom;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActnOfLedFrntCrossLamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActnOfLedFrntCrossLamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActnOfLedGrilleLamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActnOfLedGrilleLamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActnOfLedLeLogoLamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActnOfLedLeLogoLamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ExtrLiRlyPwrDwn(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ExtrLiRlyPwrDwn;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_BkpOfDstTrvld(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_BkpOfDstTrvld;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_LiOprnMod(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_LiOprnMod;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_AutWinWipgCmd(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_AutWinWipgCmd;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_IndcrSts(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_IndcrSts;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_LitArea(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_LitArea;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActvnOfApproach(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActvnOfApproach;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActvnOfCarLoctr(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActvnOfCarLoctr;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActvnOfWaitMode(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActvnOfWaitMode;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_IndcrNoSeq(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_IndcrNoSeq;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ExtrLiShowFileTxReq(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ExtrLiShowFileTxReq;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ExtrLiShowActvnReq(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ExtrLiShowActvnReq;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_WelcomeGoodbyeModeReq(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_WelcomeGoodbyeModeReq;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_WelLiFileTxReq(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_WelLiFileTxReq;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActvnOfLiForComity(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActvnOfLiForComity;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActvnOfLiForSpkr(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActvnOfLiForSpkr;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActvnOfLiForWait(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActvnOfLiForWait;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActvnOfADB(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActvnOfADB;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehCfgPrmExtCCPBytePosn5(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehCfgPrmExtCCPBytePosn5;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehCfgPrmExtCCPBytePosn6(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehCfgPrmExtCCPBytePosn6;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehCfgPrmExtCCPBytePosn2(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehCfgPrmExtCCPBytePosn2;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehCfgPrmExtCCPBytePosn3(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehCfgPrmExtCCPBytePosn3;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehCfgPrmExtCCPBytePosn8(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehCfgPrmExtCCPBytePosn8;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehCfgPrmExtCCPBytePosn4(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehCfgPrmExtCCPBytePosn4;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehCfgPrmExtCCPBytePosn7(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehCfgPrmExtCCPBytePosn7;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehCfgPrmExtBlkIDBytePosn1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehCfgPrmExtBlkIDBytePosn1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TrafficSignForADB1AdbAbsDist(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TrafficSignForADB1AdbAbsDist;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TrafficSignForADB1AdbTrkInfo(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TrafficSignForADB1AdbTrkInfo;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TrafficSignForADB1AdbDetdQly(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TrafficSignForADB1AdbDetdQly;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TrafficSignForADB1AdbHozlAgRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TrafficSignForADB1AdbHozlAgRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TrafficSignForADB1AdbVertAgTop(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TrafficSignForADB1AdbVertAgTop;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TrafficSignForADB1AdbHozlAgLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TrafficSignForADB1AdbHozlAgLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TrafficSignForADB1AdbVertAgBot(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TrafficSignForADB1AdbVertAgBot;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB7AdbAbsDist(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB7AdbAbsDist;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB7AdbClassn(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB7AdbClassn;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB7AdbTrkInfo(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB7AdbTrkInfo;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB7AdbObjDir(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB7AdbObjDir;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB7AdbVertAg(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB7AdbVertAg;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB7AdbObjHozlAgSpdRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB7AdbObjHozlAgSpdRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB7AdbHozlAgLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB7AdbHozlAgLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB7AdbHozlAgRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB7AdbHozlAgRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB7AdbObjHozlAgSpdLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB7AdbObjHozlAgSpdLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB5AdbClassn(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB5AdbClassn;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB5AdbObjDir(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB5AdbObjDir;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB5AdbTrkInfo(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB5AdbTrkInfo;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB5AdbAbsDist(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB5AdbAbsDist;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB5AdbVertAg(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB5AdbVertAg;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB5AdbObjHozlAgSpdRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB5AdbObjHozlAgSpdRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB5AdbHozlAgLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB5AdbHozlAgLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB5AdbHozlAgRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB5AdbHozlAgRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB5AdbObjHozlAgSpdLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB5AdbObjHozlAgSpdLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehCfgPrmCCPBytePosn6(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehCfgPrmCCPBytePosn6;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehCfgPrmBlkIDBytePosn1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehCfgPrmBlkIDBytePosn1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehCfgPrmCCPBytePosn4(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehCfgPrmCCPBytePosn4;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehCfgPrmCCPBytePosn3(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehCfgPrmCCPBytePosn3;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehCfgPrmCCPBytePosn2(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehCfgPrmCCPBytePosn2;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehCfgPrmCCPBytePosn8(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehCfgPrmCCPBytePosn8;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehCfgPrmCCPBytePosn7(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehCfgPrmCCPBytePosn7;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehCfgPrmCCPBytePosn5(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehCfgPrmCCPBytePosn5;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehModMngtGlbSafe1Chks(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehModMngtGlbSafe1Chks;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehModMngtGlbSafe1CarModSts1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehModMngtGlbSafe1CarModSts1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehModMngtGlbSafe1Cntr(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehModMngtGlbSafe1Cntr;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehModMngtGlbSafe1EgyLvlElecSubtyp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehModMngtGlbSafe1EgyLvlElecSubtyp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehModMngtGlbSafe1PwrLvlElecSubtyp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehModMngtGlbSafe1PwrLvlElecSubtyp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehModMngtGlbSafe1CarModSubtypWdCar(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehModMngtGlbSafe1CarModSubtypWdCar;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehModMngtGlbSafe1UsgModSts(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehModMngtGlbSafe1UsgModSts;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehModMngtGlbSafe1PwrLvlElecMai(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehModMngtGlbSafe1PwrLvlElecMai;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehModMngtGlbSafe1EgyLvlElecMai(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehModMngtGlbSafe1EgyLvlElecMai;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehModMngtGlbSafe1FltEgyCnsWdSts(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehModMngtGlbSafe1FltEgyCnsWdSts;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB8AdbTrkInfo(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB8AdbTrkInfo;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB8AdbClassn(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB8AdbClassn;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB8AdbObjDir(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB8AdbObjDir;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB8AdbAbsDist(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB8AdbAbsDist;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB8AdbVertAg(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB8AdbVertAg;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB8AdbHozlAgLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB8AdbHozlAgLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB8AdbObjHozlAgSpdLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB8AdbObjHozlAgSpdLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB8AdbHozlAgRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB8AdbHozlAgRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB8AdbObjHozlAgSpdRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB8AdbObjHozlAgSpdR;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedCornrgLampLeUpprBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedCornrgLampLeUpprBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedCornrgLampLeContTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedCornrgLampLeContTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedCornrgLampLeLowBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedCornrgLampLeLowBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedCornrgLampLeOffsTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedCornrgLampLeOffsTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedCornrgLampLeModePrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedCornrgLampLeModePrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedCornrgLampLeTistamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedCornrgLampLeTistamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedFrntPosnLampLeLowBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedFrntPosnLampLeLowBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedFrntPosnLampLeUpprBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedFrntPosnLampLeUpprBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedFrntPosnLampLeContTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedFrntPosnLampLeContTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedFrntPosnLampLeOffsTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedFrntPosnLampLeOffsTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedFrntPosnLampLeModePrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedFrntPosnLampLeModePrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedFrntPosnLampLeTistamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedFrntPosnLampLeTistamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB3AdbAbsDist(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB3AdbAbsDist;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB3AdbTrkInfo(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB3AdbTrkInfo;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB3AdbClassn(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB3AdbClassn;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB3AdbObjDir(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB3AdbObjDir;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB3AdbVertAg(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB3AdbVertAg;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB3AdbObjHozlAgSpdLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB3AdbObjHozlAgSpdLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB3AdbObjHozlAgSpdRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB3AdbObjHozlAgSpdRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB3AdbHozlAgLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB3AdbHozlAgLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB3AdbHozlAgRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB3AdbHozlAgRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_BrkPedlrRatQf(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_BrkPedlrRatQf;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_BrkPedlrRatPerc(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_BrkPedlrRatPerc;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB2AdbObjDir(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB2AdbObjDir;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB2AdbTrkInfo(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB2AdbTrkInfo;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB2AdbAbsDist(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB2AdbAbsDist;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB2AdbClassn(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB2AdbClassn;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB2AdbVertAg(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB2AdbVertAg;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB2AdbObjHozlAgSpdRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB2AdbObjHozlAgSpdRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB2AdbObjHozlAgSpdLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB2AdbObjHozlAgSpdLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB2AdbHozlAgLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB2AdbHozlAgLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB2AdbHozlAgRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB2AdbHozlAgRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB6AdbClassn(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB6AdbClassn;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB6AdbObjDir(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB6AdbObjDir;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB6AdbTrkInfo(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB6AdbTrkInfo;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB6AdbAbsDist(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB6AdbAbsDist;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB6AdbVertAg(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB6AdbVertAg;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB6AdbObjHozlAgSpdRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB6AdbObjHozlAgSpdRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB6AdbHozlAgLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB6AdbHozlAgLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB6AdbHozlAgRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB6AdbHozlAgRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB6AdbObjHozlAgSpdLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB6AdbObjHozlAgSpdLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_AccrPedlRatCntr(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_AccrPedlRatCntr;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_AccrPedlRatChks(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_AccrPedlRatChks;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_AccrPedlRatAccrPedlRat(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_AccrPedlRatAccrPedlRat;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_BrkPedlSnsrSt(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_BrkPedlSnsrSt;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_BrkPedlSnsrChks(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_BrkPedlSnsrChks;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_BrkPedlSnsrCntr(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_BrkPedlSnsrCntr;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_BrkPedlSnsrQf(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_BrkPedlSnsrQf;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_AmbTRawQly(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_AmbTRawQly;
//     return rtval;
// }


// Std_ReturnType Interface_GetSignal_AmbTRawAmbTVal(sint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = (((sint32_t)Signal_AmbTRawAmbTVal) *0.1 -70);
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehBattUSysU(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehBattUSysU;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehBattUSysUQf(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehBattUSysUQf;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedDaytiRunngLampLeModePrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampLeModePrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedDaytiRunngLampLeOffsTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampLeOffsTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedDaytiRunngLampLeLowBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampLeLowBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedDaytiRunngLampLeUpprBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampLeUpprBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedDaytiRunngLampLeContTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampLeContTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedDaytiRunngLampLeTistamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampLeTistamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_LvlgSwtSetReqADModCtrlInhbn(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_LvlgSwtSetReqADModCtrlInhbn;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_OutdBriSts(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_OutdBriSts;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB1AdbObjDir(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB1AdbObjDir;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB1AdbTrkInfo(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB1AdbTrkInfo;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB1AdbAbsDist(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB1AdbAbsDist;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB1AdbClassn(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB1AdbClassn;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB1AdbVertAg(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB1AdbVertAg;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB1AdbObjHozlAgSpdRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB1AdbObjHozlAgSpdRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB1AdbObjHozlAgSpdLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB1AdbObjHozlAgSpdLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB1AdbHozlAgLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB1AdbHozlAgLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB1AdbHozlAgRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB1AdbHozlAgRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB4AdbObjDir(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB4AdbObjDir;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB4AdbTrkInfo(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB4AdbTrkInfo;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB4AdbAbsDist(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB4AdbAbsDist;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB4AdbClassn(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB4AdbClassn;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB4AdbVertAg(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB4AdbVertAg;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB4AdbObjHozlAgSpdRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB4AdbObjHozlAgSpdRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB4AdbObjHozlAgSpdLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB4AdbObjHozlAgSpdLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB4AdbHozlAgLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB4AdbHozlAgLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB4AdbHozlAgRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB4AdbHozlAgRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedAllWthrLampLeOffsTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedAllWthrLampLeOffsTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedAllWthrLampLeContTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedAllWthrLampLeContTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedAllWthrLampLeModePrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedAllWthrLampLeModePrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedAllWthrLampLeLowBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedAllWthrLampLeLowBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedAllWthrLampLeUpprBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedAllWthrLampLeUpprBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedAllWthrLampLeTistamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedAllWthrLampLeTistamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmForLedLoBeamLeContTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmForLedLoBeamLeContTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmForLedLoBeamLeModePrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmForLedLoBeamLeModePrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmForLedLoBeamLeLowBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmForLedLoBeamLeLowBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmForLedLoBeamLeOffsTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmForLedLoBeamLeOffsTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmForLedLoBeamLeUpprBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmForLedLoBeamLeUpprBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmForLedLoBeamLeTistamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmForLedLoBeamLeTistamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_SteerWhlSnsrQf(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_SteerWhlSnsrQf;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_SteerWhlSnsrAg(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_SteerWhlSnsrAg;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_SteerWhlSnsrAgSpd(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_SteerWhlSnsrAgSpd;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmForLedHiBeamLeLowBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmForLedHiBeamLeLowBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmForLedHiBeamLeModePrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmForLedHiBeamLeModePrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmForLedHiBeamLeUpprBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmForLedHiBeamLeUpprBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmForLedHiBeamLeOffsTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmForLedHiBeamLeOffsTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmForLedHiBeamLeContTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmForLedHiBeamLeContTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmForLedHiBeamLeTistamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmForLedHiBeamLeTistamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeUpprBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeUpprBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeModePrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeModePrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeContTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeContTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeOffsTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeOffsTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeLowBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeLowBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeTistamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrLeTistamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehSpdLgtQf(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehSpdLgtQf;
//     return rtval;
// }
// /* 
//  *SignalValue 单位 m/s
//  */
// Std_ReturnType Interface_GetSignal_VehSpdLgtA(double * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = (double)Signal_VehSpdLgtA * 0.00391;
//     return rtval;
// }


// Std_ReturnType Interface_GetSignal_VehSpdLgtA_CanBusVal(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehSpdLgtA;
//     return rtval;
// }


// Std_ReturnType Interface_GetSignal_IndcrPatCmd1WdTiOff(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_IndcrPatCmd1WdTiOff;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_IndcrPatCmd1WdTiOn(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_IndcrPatCmd1WdTiOn;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TrafficSignForADB2AdbAbsDist(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TrafficSignForADB2AdbAbsDist;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TrafficSignForADB2AdbTrkInfo(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TrafficSignForADB2AdbTrkInfo;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TrafficSignForADB2AdbDetdQly(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TrafficSignForADB2AdbDetdQly;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TrafficSignForADB2AdbHozlAgRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TrafficSignForADB2AdbHozlAgRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TrafficSignForADB2AdbVertAgTop(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TrafficSignForADB2AdbVertAgTop;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TrafficSignForADB2AdbHozlAgLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TrafficSignForADB2AdbHozlAgLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TrafficSignForADB2AdbVertAgBot(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TrafficSignForADB2AdbVertAgBot;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforAHBAdbObjDir(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforAHBAdbObjDir;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforAHBAdbDetdQly(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforAHBAdbDetdQly;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforAHBAdbClassn(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforAHBAdbClassn;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforAHBAdbClassnQly(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforAHBAdbClassnQly;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforAHBAdbAbsDist(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforAHBAdbAbsDist;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforAHBAdbTrkInfo(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforAHBAdbTrkInfo;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforAHBAdbObjVertAgSpd(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforAHBAdbObjVertAgSpd;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforAHBAdbObjHozlAgSpd(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforAHBAdbObjHozlAgSpd;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforAHBAdbVertAg(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforAHBAdbVertAg;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_BrkPedlValBrkPedlVal(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_BrkPedlValBrkPedlVal;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_BrkPedlValQf(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_BrkPedlValQf;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_WipgInfoWiprActv(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_WipgInfoWiprActv;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_WipgInfoWiprInWipgAr(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_WipgInfoWiprInWipgAr;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_WipgInfoWipgSpdInfo(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_WipgInfoWipgSpdInfo;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TooManyCars(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TooManyCars;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_SuspPosnVertAgSuspPosnVertAg(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_SuspPosnVertAgSuspPosnVertAg;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_SuspPosnVertAgGenQf(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_SuspPosnVertAgGenQf;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_SuspPosnVertLvlReQf(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_SuspPosnVertLvlReQf;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_SuspPosnVertLvlRe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_SuspPosnVertLvlRe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_SuspPosnVertLvlFrnt(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_SuspPosnVertLvlFrnt;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_SuspPosnVertLvlFrntQf(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_SuspPosnVertLvlFrntQf;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmLedLeGrilleLampOffsTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmLedLeGrilleLampOffsTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmLedLeGrilleLampTistamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmLedLeGrilleLampTistamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmLedLeGrilleLampLowBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmLedLeGrilleLampLowBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmLedLeGrilleLampModePrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmLedLeGrilleLampModePrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmLedLeGrilleLampUpprBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmLedLeGrilleLampUpprBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmLedLeGrilleLampContTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmLedLeGrilleLampContTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmLedLeSideLogoLiModePrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmLedLeSideLogoLiModePrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmLedLeSideLogoLiLowBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmLedLeSideLogoLiLowBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmLedLeSideLogoLiUpprBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmLedLeSideLogoLiUpprBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmLedLeSideLogoLiTistamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmLedLeSideLogoLiTistamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmLedLeSideLogoLiContTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmLedLeSideLogoLiContTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmLedLeSideLogoLiOffsTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmLedLeSideLogoLiOffsTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp1LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp1LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp1OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp1OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp1HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp1HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp1Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp1Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp1Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp1Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp1ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp1ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp2LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp2LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp2OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp2OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp2HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp2HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp2Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp2Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp2Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp2Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp2ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp2ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp3LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp3LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp3OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp3OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp3HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp3HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp3Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp3Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp3Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp3Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp3ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp3ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp4LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp4LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp4OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp4OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp4HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp4HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp4Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp4Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp4Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp4Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp4ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp4ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp5LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp5LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp5OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp5OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp5HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp5HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp5Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp5Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp5Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp5Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp5ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp5ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp6LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp6LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp6OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp6OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp6HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp6HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp6Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp6Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp6Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp6Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp6ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp6ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp7LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp7LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp7OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp7OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp7HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp7HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp7Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp7Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp7Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp7Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp7ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp7ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp8LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp8LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp8OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp8OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp8HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp8HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp8Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp8Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp8Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp8Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp8ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp8ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp9LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp9LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp9OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp9OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp9HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp9HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp9Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp9Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp9Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp9Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp9ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp9ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp10LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp10LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp10OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp10OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp10HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp10HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp10Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp10Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp10Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp10Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp10ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp10ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp11LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp11LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp11OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp11OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp11HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp11HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp11Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp11Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp11Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp11Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp11ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp11ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp12LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp12LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp12OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp12OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp12HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp12HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp12Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp12Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp12Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp12Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp12ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp12ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp13LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp13LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp13OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp13OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp13HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp13HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp13Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp13Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp13Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp13Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp13ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp13ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp14LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp14LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp14OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp14OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp14HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp14HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp14Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp14Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp14Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp14Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp14ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp14ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp15LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp15LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp15OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp15OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp15HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp15HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp15Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp15Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp15Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp15Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp15ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp15ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp16LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp16LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp16OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp16OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp16HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp16HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp16Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp16Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp16Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp16Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp16ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp16ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp17LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp17LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp17OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp17OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp17HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp17HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp17Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp17Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp17Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp17Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp17ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp17ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp18LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp18LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp18OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp18OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp18HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp18HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp18Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp18Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp18Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp18Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp18ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp18ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp19LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp19LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp19OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp19OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp19HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp19HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp19Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp19Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp19Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp19Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp19ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp19ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp20LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp20LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp20OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp20OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp20HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp20HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp20Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp20Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp20Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp20Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp20ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp20ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp21LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp21LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp21OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp21OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp21HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp21HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp21Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp21Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp21Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp21Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp21ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp21ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp22LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp22LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp22OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp22OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp22HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp22HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp22Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp22Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp22Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp22Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp22ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp22ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp23LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp23LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp23OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp23OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp23HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp23HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp23Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp23Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp23Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp23Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp23ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp23ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp24LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp24LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp24OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp24OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp24HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp24HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp24Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp24Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp24Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp24Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntLeGrp24ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntLeGrp24ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TiAndDateIndcnDay(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TiAndDateIndcnDay;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TiAndDateIndcnYr1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TiAndDateIndcnYr1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TiAndDateIndcnMins1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TiAndDateIndcnMins1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TiAndDateIndcnMth1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TiAndDateIndcnMth1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TiAndDateIndcnHr1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TiAndDateIndcnHr1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TiAndDateIndcnSec1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TiAndDateIndcnSec1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TiAndDateIndcnDataValid(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TiAndDateIndcnDataValid;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DHUcontrolleftcorneringlamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DHUcontrolleftcorneringlamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DHUcontrolleftdaytimerunninglamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DHUcontrolleftdaytimerunninglamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DHUcontrolleftfroglight(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DHUcontrolleftfroglight;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DHUcontrollefthighbeamlamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DHUcontrollefthighbeamlamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DHUcontrolleftlowbeamlamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DHUcontrolleftlowbeamlamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DHUcontrolleftpositionlamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DHUcontrolleftpositionlamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforAHBAdbHozlAg(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforAHBAdbHozlAg;
//     return rtval;
// }



// /*******************************************************************************************/
// /*******************************************************************************************/

// #elif HCM_RIGHT_SIDE

// /*******************************/
// /* Set Signal Function (Right) */
// /*******************************/

// Std_ReturnType Interface_SetSignal_ExtrLiShowFileTxReq(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ExtrLiShowFileTxReq = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ExtrLiShowActvnReq(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ExtrLiShowActvnReq = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_WipgAutFrntMod(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_WipgAutFrntMod = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_RainLi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_RainLi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_CameraStsforAHBC(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_CameraStsforAHBC = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActnOfLedPosnLampDyn(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActnOfLedPosnLampDyn = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActnOfLedFrntCrossLampDyn(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActnOfLedFrntCrossLampDyn = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActnOfLedGrilleLampDyn(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActnOfLedGrilleLampDyn = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActnOfLedRiLogoLampDyn(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActnOfLedRiLogoLampDyn = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActvnOfHomeSafe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActvnOfHomeSafe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_YawRateReqdByDrvr(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_YawRateReqdByDrvr = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_CarTiGlb(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_CarTiGlb = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_Body2CntrForMissCom(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_Body2CntrForMissCom = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActnOfLedFrntCrossLamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActnOfLedFrntCrossLamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActnOfLedGrilleLamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActnOfLedGrilleLamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActnOfLedRiLogoLamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActnOfLedRiLogoLamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TooManyCars(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TooManyCars = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ExtrLiRlyPwrDwn(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ExtrLiRlyPwrDwn = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_BkpOfDstTrvld(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_BkpOfDstTrvld = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_IndcrSts(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_IndcrSts = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_LitArea(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_LitArea = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActvnOfApproach(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActvnOfApproach = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActvnOfCarLoctr(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActvnOfCarLoctr = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActvnOfWaitMode(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActvnOfWaitMode = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_IndcrNoSeq(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_IndcrNoSeq = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_LiOprnMod(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_LiOprnMod = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_AutWinWipgCmd(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_AutWinWipgCmd = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActnOfLedCornrgLampRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActnOfLedCornrgLampRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActnOfLedDaytiRunngLamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActnOfLedDaytiRunngLamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActnOfLedFrntFogLamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActnOfLedFrntFogLamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActnOfLedHiBeam(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActnOfLedHiBeam = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActnOfLedPosnLamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActnOfLedPosnLamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActvnOfAfs(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActvnOfAfs = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActvnOfAhbc(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActvnOfAhbc = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActvnOfAhl(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActvnOfAhl = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActvnOfDbl(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActvnOfDbl = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActvnOfGoodByeLi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActvnOfGoodByeLi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActvnOfTouristMod(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActvnOfTouristMod = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActvnOfWelcomeLi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActvnOfWelcomeLi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_WelcomeGoodbyeModeReq(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_WelcomeGoodbyeModeReq = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_WelLiFileTxReq(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_WelLiFileTxReq = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActvnOfLiForComity(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActvnOfLiForComity = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActvnOfLiForSpkr(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActvnOfLiForSpkr = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActvnOfLiForWait(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActvnOfLiForWait = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActvnOfADB(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActvnOfADB = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DHUcontrolrightcorneringlamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DHUcontrolrightcorneringlamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DHUcontrolrightdaytimerunninglamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DHUcontrolrightdaytimerunninglamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DHUcontrolrightfroglight(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DHUcontrolrightfroglight = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DHUcontrolrighthighbeamlamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DHUcontrolrighthighbeamlamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DHUcontrolrightlowbeamlamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DHUcontrolrightlowbeamlamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DHUcontrolrightpositionlamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DHUcontrolrightpositionlamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedCornrgLampRiUpprBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedCornrgLampRiUpprBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedCornrgLampRiContTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedCornrgLampRiContTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedCornrgLampRiLowBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedCornrgLampRiLowBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedCornrgLampRiOffsTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedCornrgLampRiOffsTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedCornrgLampRiModePrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedCornrgLampRiModePrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedCornrgLampRiTistamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedCornrgLampRiTistamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiUpprBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiUpprBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiModePrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiModePrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiContTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiContTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiOffsTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiOffsTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiLowBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiLowBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiTistamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiTistamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehModMngtGlbSafe1Chks(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehModMngtGlbSafe1Chks = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehModMngtGlbSafe1CarModSts1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehModMngtGlbSafe1CarModSts1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehModMngtGlbSafe1Cntr(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehModMngtGlbSafe1Cntr = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehModMngtGlbSafe1EgyLvlElecSubtyp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehModMngtGlbSafe1EgyLvlElecSubtyp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehModMngtGlbSafe1PwrLvlElecSubtyp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehModMngtGlbSafe1PwrLvlElecSubtyp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehModMngtGlbSafe1CarModSubtypWdCar(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehModMngtGlbSafe1CarModSubtypWdCar = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehModMngtGlbSafe1UsgModSts(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehModMngtGlbSafe1UsgModSts = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehModMngtGlbSafe1PwrLvlElecMai(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehModMngtGlbSafe1PwrLvlElecMai = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehModMngtGlbSafe1EgyLvlElecMai(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehModMngtGlbSafe1EgyLvlElecMai = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehModMngtGlbSafe1FltEgyCnsWdSts(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehModMngtGlbSafe1FltEgyCnsWdSts = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforAHBAdbHozlAg(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforAHBAdbHozlAg = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforAHBAdbObjDir(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforAHBAdbObjDir = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforAHBAdbDetdQly(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforAHBAdbDetdQly = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforAHBAdbClassn(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforAHBAdbClassn = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforAHBAdbClassnQly(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforAHBAdbClassnQly = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforAHBAdbAbsDist(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforAHBAdbAbsDist = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforAHBAdbTrkInfo(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforAHBAdbTrkInfo = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforAHBAdbObjVertAgSpd(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforAHBAdbObjVertAgSpd = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforAHBAdbObjHozlAgSpd(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforAHBAdbObjHozlAgSpd = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforAHBAdbVertAg(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforAHBAdbVertAg = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedAllWthrLampRiOffsTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedAllWthrLampRiOffsTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedAllWthrLampRiContTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedAllWthrLampRiContTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedAllWthrLampRiModePrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedAllWthrLampRiModePrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedAllWthrLampRiLowBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedAllWthrLampRiLowBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedAllWthrLampRiUpprBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedAllWthrLampRiUpprBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedAllWthrLampRiTistamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedAllWthrLampRiTistamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehCfgPrmExtCCPBytePosn5(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehCfgPrmExtCCPBytePosn5 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehCfgPrmExtCCPBytePosn6(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehCfgPrmExtCCPBytePosn6 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehCfgPrmExtCCPBytePosn2(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehCfgPrmExtCCPBytePosn2 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehCfgPrmExtCCPBytePosn3(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehCfgPrmExtCCPBytePosn3 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehCfgPrmExtCCPBytePosn8(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehCfgPrmExtCCPBytePosn8 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehCfgPrmExtCCPBytePosn4(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehCfgPrmExtCCPBytePosn4 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehCfgPrmExtCCPBytePosn7(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehCfgPrmExtCCPBytePosn7 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehCfgPrmExtBlkIDBytePosn1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehCfgPrmExtBlkIDBytePosn1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB7AdbAbsDist(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB7AdbAbsDist = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB7AdbClassn(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB7AdbClassn = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB7AdbTrkInfo(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB7AdbTrkInfo = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB7AdbObjDir(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB7AdbObjDir = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB7AdbVertAg(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB7AdbVertAg = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB7AdbObjHozlAgSpdRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB7AdbObjHozlAgSpdRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB7AdbHozlAgLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB7AdbHozlAgLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB7AdbHozlAgRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB7AdbHozlAgRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB7AdbObjHozlAgSpdLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB7AdbObjHozlAgSpdLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehCfgPrmCCPBytePosn6(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehCfgPrmCCPBytePosn6 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehCfgPrmBlkIDBytePosn1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehCfgPrmBlkIDBytePosn1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehCfgPrmCCPBytePosn4(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehCfgPrmCCPBytePosn4 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehCfgPrmCCPBytePosn3(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehCfgPrmCCPBytePosn3 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehCfgPrmCCPBytePosn2(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehCfgPrmCCPBytePosn2 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehCfgPrmCCPBytePosn8(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehCfgPrmCCPBytePosn8 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehCfgPrmCCPBytePosn7(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehCfgPrmCCPBytePosn7 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehCfgPrmCCPBytePosn5(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehCfgPrmCCPBytePosn5 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB3AdbAbsDist(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB3AdbAbsDist = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB3AdbTrkInfo(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB3AdbTrkInfo = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB3AdbClassn(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB3AdbClassn = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB3AdbObjDir(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB3AdbObjDir = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB3AdbVertAg(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB3AdbVertAg = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB3AdbObjHozlAgSpdLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB3AdbObjHozlAgSpdLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB3AdbObjHozlAgSpdRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB3AdbObjHozlAgSpdRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB3AdbHozlAgLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB3AdbHozlAgLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB3AdbHozlAgRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB3AdbHozlAgRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_BrkPedlrRatQf(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_BrkPedlrRatQf = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_BrkPedlrRatPerc(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_BrkPedlrRatPerc = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedFrntPosnLampRiLowBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedFrntPosnLampRiLowBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedFrntPosnLampRiUpprBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedFrntPosnLampRiUpprBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedFrntPosnLampRiContTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedFrntPosnLampRiContTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedFrntPosnLampRiOffsTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedFrntPosnLampRiOffsTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedFrntPosnLampRiModePrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedFrntPosnLampRiModePrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedFrntPosnLampRiTistamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedFrntPosnLampRiTistamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB4AdbObjDir(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB4AdbObjDir = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB4AdbTrkInfo(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB4AdbTrkInfo = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB4AdbAbsDist(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB4AdbAbsDist = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB4AdbClassn(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB4AdbClassn = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB4AdbVertAg(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB4AdbVertAg = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB4AdbObjHozlAgSpdRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB4AdbObjHozlAgSpdRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB4AdbObjHozlAgSpdLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB4AdbObjHozlAgSpdLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB4AdbHozlAgLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB4AdbHozlAgLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB4AdbHozlAgRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB4AdbHozlAgRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_AccrPedlRatCntr(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_AccrPedlRatCntr = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_AccrPedlRatChks(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_AccrPedlRatChks = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_AccrPedlRatAccrPedlRat(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_AccrPedlRatAccrPedlRat = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_BrkPedlSnsrSt(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_BrkPedlSnsrSt = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_BrkPedlSnsrChks(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_BrkPedlSnsrChks = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_BrkPedlSnsrCntr(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_BrkPedlSnsrCntr = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_BrkPedlSnsrQf(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_BrkPedlSnsrQf = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_AmbTRawQly(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_AmbTRawQly = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_AmbTRawAmbTVal(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_AmbTRawAmbTVal = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehBattUSysU(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehBattUSysU = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehBattUSysUQf(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehBattUSysUQf = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB8AdbTrkInfo(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB8AdbTrkInfo = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB8AdbClassn(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB8AdbClassn = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB8AdbObjDir(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB8AdbObjDir = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB8AdbAbsDist(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB8AdbAbsDist = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB8AdbVertAg(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB8AdbVertAg = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB8AdbHozlAgLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB8AdbHozlAgLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB8AdbObjHozlAgSpdLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB8AdbObjHozlAgSpdLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB8AdbHozlAgRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB8AdbHozlAgRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB8AdbObjHozlAgSpdR(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB8AdbObjHozlAgSpdR = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedHiBeamRiLowBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedHiBeamRiLowBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedHiBeamRiModePrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedHiBeamRiModePrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedHiBeamRiUpprBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedHiBeamRiUpprBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedHiBeamRiOffsTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedHiBeamRiOffsTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedHiBeamRiContTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedHiBeamRiContTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedHiBeamRiTistamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedHiBeamRiTistamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB1AdbObjDir(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB1AdbObjDir = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB1AdbTrkInfo(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB1AdbTrkInfo = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB1AdbAbsDist(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB1AdbAbsDist = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB1AdbClassn(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB1AdbClassn = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB1AdbVertAg(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB1AdbVertAg = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB1AdbObjHozlAgSpdRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB1AdbObjHozlAgSpdRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB1AdbObjHozlAgSpdLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB1AdbObjHozlAgSpdLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB1AdbHozlAgLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB1AdbHozlAgLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB1AdbHozlAgRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB1AdbHozlAgRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_LvlgSwtSetReqADModCtrlInhbn(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_LvlgSwtSetReqADModCtrlInhbn = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_OutdBriSts(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_OutdBriSts = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActvnOfIndcrIndcrOut(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActvnOfIndcrIndcrOut = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_IndcrPatCmd1WdTiOff(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_IndcrPatCmd1WdTiOff = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_IndcrPatCmd1WdTiOn(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_IndcrPatCmd1WdTiOn = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehSpdLgtQf(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehSpdLgtQf = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehSpdLgtA(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehSpdLgtA = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TrafficSignForADB1AdbAbsDist(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TrafficSignForADB1AdbAbsDist = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TrafficSignForADB1AdbTrkInfo(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TrafficSignForADB1AdbTrkInfo = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TrafficSignForADB1AdbDetdQly(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TrafficSignForADB1AdbDetdQly = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TrafficSignForADB1AdbHozlAgRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TrafficSignForADB1AdbHozlAgRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TrafficSignForADB1AdbVertAgTop(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TrafficSignForADB1AdbVertAgTop = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TrafficSignForADB1AdbHozlAgLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TrafficSignForADB1AdbHozlAgLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TrafficSignForADB1AdbVertAgBot(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TrafficSignForADB1AdbVertAgBot = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_BrkPedlValBrkPedlVal(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_BrkPedlValBrkPedlVal = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_BrkPedlValQf(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_BrkPedlValQf = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_WipgInfoWiprActv(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_WipgInfoWiprActv = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_WipgInfoWiprInWipgAr(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_WipgInfoWiprInWipgAr = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_WipgInfoWipgSpdInfo(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_WipgInfoWipgSpdInfo = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedDaytiRunngLampRiModePrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampRiModePrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedDaytiRunngLampRiOffsTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampRiOffsTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedDaytiRunngLampRiLowBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampRiLowBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedDaytiRunngLampRiUpprBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampRiUpprBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedDaytiRunngLampRiContTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampRiContTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedDaytiRunngLampRiTistamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampRiTistamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TrafficSignForADB2AdbAbsDist(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TrafficSignForADB2AdbAbsDist = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TrafficSignForADB2AdbTrkInfo(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TrafficSignForADB2AdbTrkInfo = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TrafficSignForADB2AdbDetdQly(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TrafficSignForADB2AdbDetdQly = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TrafficSignForADB2AdbHozlAgRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TrafficSignForADB2AdbHozlAgRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TrafficSignForADB2AdbVertAgTop(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TrafficSignForADB2AdbVertAgTop = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TrafficSignForADB2AdbHozlAgLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TrafficSignForADB2AdbHozlAgLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TrafficSignForADB2AdbVertAgBot(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TrafficSignForADB2AdbVertAgBot = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB5AdbClassn(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB5AdbClassn = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB5AdbObjDir(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB5AdbObjDir = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB5AdbTrkInfo(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB5AdbTrkInfo = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB5AdbAbsDist(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB5AdbAbsDist = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB5AdbVertAg(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB5AdbVertAg = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB5AdbObjHozlAgSpdRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB5AdbObjHozlAgSpdRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB5AdbHozlAgLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB5AdbHozlAgLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB5AdbHozlAgRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB5AdbHozlAgRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB5AdbObjHozlAgSpdLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB5AdbObjHozlAgSpdLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB2AdbObjDir(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB2AdbObjDir = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB2AdbTrkInfo(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB2AdbTrkInfo = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB2AdbAbsDist(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB2AdbAbsDist = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB2AdbClassn(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB2AdbClassn = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB2AdbVertAg(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB2AdbVertAg = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB2AdbObjHozlAgSpdRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB2AdbObjHozlAgSpdRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB2AdbObjHozlAgSpdLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB2AdbObjHozlAgSpdLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB2AdbHozlAgLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB2AdbHozlAgLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB2AdbHozlAgRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB2AdbHozlAgRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_SteerWhlSnsrQf(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_SteerWhlSnsrQf = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_SteerWhlSnsrAg(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_SteerWhlSnsrAg = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_SteerWhlSnsrAgSpd(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_SteerWhlSnsrAgSpd = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB6AdbClassn(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB6AdbClassn = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB6AdbObjDir(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB6AdbObjDir = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB6AdbTrkInfo(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB6AdbTrkInfo = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB6AdbAbsDist(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB6AdbAbsDist = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB6AdbVertAg(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB6AdbVertAg = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB6AdbObjHozlAgSpdRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB6AdbObjHozlAgSpdRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB6AdbHozlAgLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB6AdbHozlAgLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB6AdbHozlAgRi(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB6AdbHozlAgRi = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_VehObjforADB6AdbObjHozlAgSpdLe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_VehObjforADB6AdbObjHozlAgSpdLe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_ActnOfLedLoBeamActnOfLedLoBeam(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_ActnOfLedLoBeamActnOfLedLoBeam = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedLoBeamRiUpprBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedLoBeamRiUpprBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedLoBeamRiContTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedLoBeamRiContTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedLoBeamRiOffsTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedLoBeamRiOffsTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedLoBeamRiModePrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedLoBeamRiModePrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedLoBeamRiLowBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedLoBeamRiLowBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForLedLoBeamRiTistamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForLedLoBeamRiTistamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_SuspPosnVertAgSuspPosnVertAg(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_SuspPosnVertAgSuspPosnVertAg = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_SuspPosnVertAgGenQf(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_SuspPosnVertAgGenQf = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_SuspPosnVertLvlReQf(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_SuspPosnVertLvlReQf = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_SuspPosnVertLvlRe(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_SuspPosnVertLvlRe = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_SuspPosnVertLvlFrnt(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_SuspPosnVertLvlFrnt = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_SuspPosnVertLvlFrntQf(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_SuspPosnVertLvlFrntQf = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmLedRiGrilleLampOffsTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmLedRiGrilleLampOffsTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmLedRiGrilleLampTistamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmLedRiGrilleLampTistamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmLedRiGrilleLampLowBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmLedRiGrilleLampLowBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmLedRiGrilleLampModePrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmLedRiGrilleLampModePrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmLedRiGrilleLampUpprBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmLedRiGrilleLampUpprBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmLedRiGrilleLampContTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmLedRiGrilleLampContTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmLedRiSideLogoLiModePrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmLedRiSideLogoLiModePrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmLedRISideLogoLiLowBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmLedRISideLogoLiLowBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmLedRiSideLogoLiUpprBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmLedRiSideLogoLiUpprBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmLedRiSideLogoLiTistamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmLedRiSideLogoLiTistamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmLedRiSideLogoLiContTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmLedRiSideLogoLiContTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmLedRiSideLogoLiOffsTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmLedRiSideLogoLiOffsTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp1LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp1LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp1OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp1OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp1HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp1HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp1Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp1Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp1Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp1Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp1ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp1ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp2LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp2LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp2OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp2OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp2HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp2HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp2Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp2Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp2Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp2Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp2ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp2ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp3LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp3LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp3OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp3OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp3HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp3HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp3Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp3Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp3Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp3Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp3ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp3ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp4LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp4LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp4OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp4OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp4HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp4HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp4Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp4Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp4Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp4Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp4ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp4ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp5LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp5LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp5OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp5OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp5HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp5HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp5Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp5Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp5Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp5Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp5ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp5ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp6LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp6LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp6OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp6OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp6HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp6HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp6Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp6Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp6Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp6Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp6ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp6ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp7LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp7LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp7OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp7OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp7HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp7HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp7Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp7Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp7Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp7Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp7ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp7ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp8LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp8LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp8OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp8OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp8HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp8HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp8Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp8Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp8Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp8Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp8ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp8ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp9LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp9LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp9OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp9OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp9HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp9HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp9Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp9Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp9Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp9Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp9ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp9ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp10LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp10LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp10OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp10OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp10HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp10HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp10Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp10Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp10Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp10Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp10ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp10ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp11LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp11LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp11OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp11OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp11HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp11HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp11Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp11Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp11Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp11Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp11ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp11ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp12LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp12LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp12OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp12OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp12HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp12HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp12Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp12Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp12Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp12Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp12ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp12ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp13LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp13LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp13OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp13OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp13HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp13HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp13Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp13Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp13Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp13Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp13ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp13ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp14LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp14LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp14OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp14OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp14HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp14HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp14Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp14Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp14Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp14Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp14ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp14ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp15LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp15LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp15OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp15OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp15HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp15HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp15Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp15Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp15Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp15Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp15ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp15ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp16LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp16LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp16OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp16OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp16HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp16HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp16Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp16Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp16Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp16Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp16ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp16ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp17LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp17LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp17OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp17OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp17HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp17HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp17Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp17Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp17Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp17Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp17ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp17ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp18LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp18LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp18OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp18OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp18HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp18HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp18Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp18Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp18Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp18Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp18ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp18ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp19LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp19LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp19OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp19OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp19HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp19HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp19Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp19Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp19Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp19Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp19ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp19ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp20LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp20LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp20OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp20OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp20HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp20HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp20Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp20Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp20Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp20Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp20ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp20ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp21LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp21LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp21OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp21OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp21HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp21HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp21Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp21Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp21Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp21Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp21ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp21ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp22LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp22LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp22OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp22OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp22HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp22HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp22Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp22Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp22Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp22Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp22ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp22ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp23LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp23LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp23OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp23OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp23HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp23HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp23Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp23Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp23Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp23Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp23ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp23ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp24LowBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp24LowBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp24OffsetTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp24OffsetTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp24HighBrightness(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp24HighBrightness = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp24Mode1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp24Mode1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp24Timestamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp24Timestamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLtgPrmForFrntRIGrp24ContinueTime(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLtgPrmForFrntRIGrp24ContinueTime = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TiAndDateIndcnDay(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TiAndDateIndcnDay = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TiAndDateIndcnYr1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TiAndDateIndcnYr1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TiAndDateIndcnMins1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TiAndDateIndcnMins1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TiAndDateIndcnMth1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TiAndDateIndcnMth1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TiAndDateIndcnHr1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TiAndDateIndcnHr1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TiAndDateIndcnSec1(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TiAndDateIndcnSec1 = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_TiAndDateIndcnDataValid(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_TiAndDateIndcnDataValid = SignalValue;
//     return rtval;
// }


// /*******************************/
// /* Get Signal Function (Right) */
// /*******************************/

// Std_ReturnType Interface_GetSignal_ExtrLiShowFileTxReq(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ExtrLiShowFileTxReq;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ExtrLiShowActvnReq(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ExtrLiShowActvnReq;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_WipgAutFrntMod(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_WipgAutFrntMod;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_RainLi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_RainLi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_CameraStsforAHBC(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_CameraStsforAHBC;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActnOfLedPosnLampDyn(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActnOfLedPosnLampDyn;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActnOfLedFrntCrossLampDyn(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActnOfLedFrntCrossLampDyn;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActnOfLedGrilleLampDyn(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActnOfLedGrilleLampDyn;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActnOfLedRiLogoLampDyn(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActnOfLedRiLogoLampDyn;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActvnOfHomeSafe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActvnOfHomeSafe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_YawRateReqdByDrvr(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_YawRateReqdByDrvr;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_CarTiGlb(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_CarTiGlb;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_Body2CntrForMissCom(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_Body2CntrForMissCom;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActnOfLedFrntCrossLamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActnOfLedFrntCrossLamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActnOfLedGrilleLamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActnOfLedGrilleLamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActnOfLedRiLogoLamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActnOfLedRiLogoLamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TooManyCars(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TooManyCars;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ExtrLiRlyPwrDwn(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ExtrLiRlyPwrDwn;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_BkpOfDstTrvld(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_BkpOfDstTrvld;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_IndcrSts(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_IndcrSts;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_LitArea(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_LitArea;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActvnOfApproach(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActvnOfApproach;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActvnOfCarLoctr(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActvnOfCarLoctr;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActvnOfWaitMode(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActvnOfWaitMode;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_IndcrNoSeq(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_IndcrNoSeq;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_LiOprnMod(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_LiOprnMod;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_AutWinWipgCmd(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_AutWinWipgCmd;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActnOfLedCornrgLampRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActnOfLedCornrgLampRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActnOfLedDaytiRunngLamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActnOfLedDaytiRunngLamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActnOfLedFrntFogLamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActnOfLedFrntFogLamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActnOfLedHiBeam(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActnOfLedHiBeam;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActnOfLedPosnLamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActnOfLedPosnLamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActvnOfAfs(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActvnOfAfs;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActvnOfAhbc(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActvnOfAhbc;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActvnOfAhl(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActvnOfAhl;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActvnOfDbl(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActvnOfDbl;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActvnOfGoodByeLi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActvnOfGoodByeLi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActvnOfTouristMod(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActvnOfTouristMod;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActvnOfWelcomeLi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActvnOfWelcomeLi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_WelcomeGoodbyeModeReq(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_WelcomeGoodbyeModeReq;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_WelLiFileTxReq(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_WelLiFileTxReq;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActvnOfLiForComity(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActvnOfLiForComity;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActvnOfLiForSpkr(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActvnOfLiForSpkr;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActvnOfLiForWait(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActvnOfLiForWait;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActvnOfADB(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActvnOfADB;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DHUcontrolrightcorneringlamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DHUcontrolrightcorneringlamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DHUcontrolrightdaytimerunninglamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DHUcontrolrightdaytimerunninglamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DHUcontrolrightfroglight(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DHUcontrolrightfroglight;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DHUcontrolrighthighbeamlamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DHUcontrolrighthighbeamlamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DHUcontrolrightlowbeamlamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DHUcontrolrightlowbeamlamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DHUcontrolrightpositionlamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DHUcontrolrightpositionlamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedCornrgLampRiUpprBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedCornrgLampRiUpprBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedCornrgLampRiContTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedCornrgLampRiContTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedCornrgLampRiLowBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedCornrgLampRiLowBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedCornrgLampRiOffsTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedCornrgLampRiOffsTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedCornrgLampRiModePrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedCornrgLampRiModePrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedCornrgLampRiTistamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedCornrgLampRiTistamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiUpprBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiUpprBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiModePrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiModePrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiContTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiContTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiOffsTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiOffsTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiLowBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiLowBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiTistamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedFrntTurnIndcrRiTistamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehModMngtGlbSafe1Chks(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehModMngtGlbSafe1Chks;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehModMngtGlbSafe1CarModSts1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehModMngtGlbSafe1CarModSts1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehModMngtGlbSafe1Cntr(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehModMngtGlbSafe1Cntr;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehModMngtGlbSafe1EgyLvlElecSubtyp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehModMngtGlbSafe1EgyLvlElecSubtyp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehModMngtGlbSafe1PwrLvlElecSubtyp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehModMngtGlbSafe1PwrLvlElecSubtyp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehModMngtGlbSafe1CarModSubtypWdCar(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehModMngtGlbSafe1CarModSubtypWdCar;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehModMngtGlbSafe1UsgModSts(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehModMngtGlbSafe1UsgModSts;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehModMngtGlbSafe1PwrLvlElecMai(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehModMngtGlbSafe1PwrLvlElecMai;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehModMngtGlbSafe1EgyLvlElecMai(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehModMngtGlbSafe1EgyLvlElecMai;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehModMngtGlbSafe1FltEgyCnsWdSts(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehModMngtGlbSafe1FltEgyCnsWdSts;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforAHBAdbHozlAg(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforAHBAdbHozlAg;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforAHBAdbObjDir(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforAHBAdbObjDir;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforAHBAdbDetdQly(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforAHBAdbDetdQly;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforAHBAdbClassn(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforAHBAdbClassn;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforAHBAdbClassnQly(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforAHBAdbClassnQly;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforAHBAdbAbsDist(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforAHBAdbAbsDist;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforAHBAdbTrkInfo(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforAHBAdbTrkInfo;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforAHBAdbObjVertAgSpd(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforAHBAdbObjVertAgSpd;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforAHBAdbObjHozlAgSpd(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforAHBAdbObjHozlAgSpd;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforAHBAdbVertAg(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforAHBAdbVertAg;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedAllWthrLampRiOffsTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedAllWthrLampRiOffsTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedAllWthrLampRiContTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedAllWthrLampRiContTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedAllWthrLampRiModePrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedAllWthrLampRiModePrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedAllWthrLampRiLowBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedAllWthrLampRiLowBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedAllWthrLampRiUpprBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedAllWthrLampRiUpprBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedAllWthrLampRiTistamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedAllWthrLampRiTistamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehCfgPrmExtCCPBytePosn5(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehCfgPrmExtCCPBytePosn5;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehCfgPrmExtCCPBytePosn6(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehCfgPrmExtCCPBytePosn6;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehCfgPrmExtCCPBytePosn2(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehCfgPrmExtCCPBytePosn2;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehCfgPrmExtCCPBytePosn3(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehCfgPrmExtCCPBytePosn3;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehCfgPrmExtCCPBytePosn8(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehCfgPrmExtCCPBytePosn8;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehCfgPrmExtCCPBytePosn4(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehCfgPrmExtCCPBytePosn4;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehCfgPrmExtCCPBytePosn7(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehCfgPrmExtCCPBytePosn7;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehCfgPrmExtBlkIDBytePosn1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehCfgPrmExtBlkIDBytePosn1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB7AdbAbsDist(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB7AdbAbsDist;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB7AdbClassn(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB7AdbClassn;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB7AdbTrkInfo(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB7AdbTrkInfo;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB7AdbObjDir(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB7AdbObjDir;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB7AdbVertAg(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB7AdbVertAg;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB7AdbObjHozlAgSpdRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB7AdbObjHozlAgSpdRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB7AdbHozlAgLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB7AdbHozlAgLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB7AdbHozlAgRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB7AdbHozlAgRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB7AdbObjHozlAgSpdLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB7AdbObjHozlAgSpdLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehCfgPrmCCPBytePosn6(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehCfgPrmCCPBytePosn6;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehCfgPrmBlkIDBytePosn1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehCfgPrmBlkIDBytePosn1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehCfgPrmCCPBytePosn4(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehCfgPrmCCPBytePosn4;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehCfgPrmCCPBytePosn3(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehCfgPrmCCPBytePosn3;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehCfgPrmCCPBytePosn2(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehCfgPrmCCPBytePosn2;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehCfgPrmCCPBytePosn8(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehCfgPrmCCPBytePosn8;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehCfgPrmCCPBytePosn7(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehCfgPrmCCPBytePosn7;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehCfgPrmCCPBytePosn5(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehCfgPrmCCPBytePosn5;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB3AdbAbsDist(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB3AdbAbsDist;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB3AdbTrkInfo(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB3AdbTrkInfo;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB3AdbClassn(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB3AdbClassn;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB3AdbObjDir(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB3AdbObjDir;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB3AdbVertAg(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB3AdbVertAg;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB3AdbObjHozlAgSpdLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB3AdbObjHozlAgSpdLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB3AdbObjHozlAgSpdRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB3AdbObjHozlAgSpdRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB3AdbHozlAgLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB3AdbHozlAgLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB3AdbHozlAgRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB3AdbHozlAgRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_BrkPedlrRatQf(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_BrkPedlrRatQf;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_BrkPedlrRatPerc(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_BrkPedlrRatPerc;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedFrntPosnLampRiLowBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedFrntPosnLampRiLowBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedFrntPosnLampRiUpprBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedFrntPosnLampRiUpprBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedFrntPosnLampRiContTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedFrntPosnLampRiContTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedFrntPosnLampRiOffsTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedFrntPosnLampRiOffsTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedFrntPosnLampRiModePrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedFrntPosnLampRiModePrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedFrntPosnLampRiTistamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedFrntPosnLampRiTistamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB4AdbObjDir(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB4AdbObjDir;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB4AdbTrkInfo(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB4AdbTrkInfo;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB4AdbAbsDist(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB4AdbAbsDist;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB4AdbClassn(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB4AdbClassn;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB4AdbVertAg(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB4AdbVertAg;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB4AdbObjHozlAgSpdRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB4AdbObjHozlAgSpdRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB4AdbObjHozlAgSpdLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB4AdbObjHozlAgSpdLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB4AdbHozlAgLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB4AdbHozlAgLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB4AdbHozlAgRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB4AdbHozlAgRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_AccrPedlRatCntr(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_AccrPedlRatCntr;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_AccrPedlRatChks(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_AccrPedlRatChks;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_AccrPedlRatAccrPedlRat(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_AccrPedlRatAccrPedlRat;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_BrkPedlSnsrSt(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_BrkPedlSnsrSt;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_BrkPedlSnsrChks(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_BrkPedlSnsrChks;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_BrkPedlSnsrCntr(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_BrkPedlSnsrCntr;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_BrkPedlSnsrQf(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_BrkPedlSnsrQf;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_AmbTRawQly(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_AmbTRawQly;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_AmbTRawAmbTVal(sint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = ((sint32_t)Signal_AmbTRawAmbTVal) * 0.1 -70;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehBattUSysU(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehBattUSysU;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehBattUSysUQf(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehBattUSysUQf;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB8AdbTrkInfo(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB8AdbTrkInfo;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB8AdbClassn(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB8AdbClassn;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB8AdbObjDir(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB8AdbObjDir;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB8AdbAbsDist(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB8AdbAbsDist;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB8AdbVertAg(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB8AdbVertAg;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB8AdbHozlAgLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB8AdbHozlAgLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB8AdbObjHozlAgSpdLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB8AdbObjHozlAgSpdLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB8AdbHozlAgRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB8AdbHozlAgRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB8AdbObjHozlAgSpdRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB8AdbObjHozlAgSpdR;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedHiBeamRiLowBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedHiBeamRiLowBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedHiBeamRiModePrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedHiBeamRiModePrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedHiBeamRiUpprBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedHiBeamRiUpprBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedHiBeamRiOffsTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedHiBeamRiOffsTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedHiBeamRiContTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedHiBeamRiContTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedHiBeamRiTistamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedHiBeamRiTistamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB1AdbObjDir(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB1AdbObjDir;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB1AdbTrkInfo(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB1AdbTrkInfo;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB1AdbAbsDist(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB1AdbAbsDist;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB1AdbClassn(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB1AdbClassn;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB1AdbVertAg(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB1AdbVertAg;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB1AdbObjHozlAgSpdRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB1AdbObjHozlAgSpdRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB1AdbObjHozlAgSpdLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB1AdbObjHozlAgSpdLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB1AdbHozlAgLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB1AdbHozlAgLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB1AdbHozlAgRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB1AdbHozlAgRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_LvlgSwtSetReqADModCtrlInhbn(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_LvlgSwtSetReqADModCtrlInhbn;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_OutdBriSts(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_OutdBriSts;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActvnOfIndcrIndcrOut(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActvnOfIndcrIndcrOut;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_IndcrPatCmd1WdTiOff(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_IndcrPatCmd1WdTiOff;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_IndcrPatCmd1WdTiOn(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_IndcrPatCmd1WdTiOn;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehSpdLgtQf(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehSpdLgtQf;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehSpdLgtA(double * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = (double)Signal_VehSpdLgtA * 0.00391;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehSpdLgtA_CanBusVal(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehSpdLgtA;
//     return rtval;
// }


// Std_ReturnType Interface_GetSignal_TrafficSignForADB1AdbAbsDist(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TrafficSignForADB1AdbAbsDist;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TrafficSignForADB1AdbTrkInfo(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TrafficSignForADB1AdbTrkInfo;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TrafficSignForADB1AdbDetdQly(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TrafficSignForADB1AdbDetdQly;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TrafficSignForADB1AdbHozlAgRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TrafficSignForADB1AdbHozlAgRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TrafficSignForADB1AdbVertAgTop(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TrafficSignForADB1AdbVertAgTop;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TrafficSignForADB1AdbHozlAgLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TrafficSignForADB1AdbHozlAgLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TrafficSignForADB1AdbVertAgBot(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TrafficSignForADB1AdbVertAgBot;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_BrkPedlValBrkPedlVal(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_BrkPedlValBrkPedlVal;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_BrkPedlValQf(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_BrkPedlValQf;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_WipgInfoWiprActv(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_WipgInfoWiprActv;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_WipgInfoWiprInWipgAr(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_WipgInfoWiprInWipgAr;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_WipgInfoWipgSpdInfo(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_WipgInfoWipgSpdInfo;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedDaytiRunngLampRiModePrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampRiModePrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedDaytiRunngLampRiOffsTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampRiOffsTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedDaytiRunngLampRiLowBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampRiLowBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedDaytiRunngLampRiUpprBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampRiUpprBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedDaytiRunngLampRiContTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampRiContTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedDaytiRunngLampRiTistamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedDaytiRunngLampRiTistamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TrafficSignForADB2AdbAbsDist(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TrafficSignForADB2AdbAbsDist;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TrafficSignForADB2AdbTrkInfo(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TrafficSignForADB2AdbTrkInfo;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TrafficSignForADB2AdbDetdQly(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TrafficSignForADB2AdbDetdQly;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TrafficSignForADB2AdbHozlAgRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TrafficSignForADB2AdbHozlAgRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TrafficSignForADB2AdbVertAgTop(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TrafficSignForADB2AdbVertAgTop;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TrafficSignForADB2AdbHozlAgLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TrafficSignForADB2AdbHozlAgLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TrafficSignForADB2AdbVertAgBot(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TrafficSignForADB2AdbVertAgBot;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB5AdbClassn(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB5AdbClassn;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB5AdbObjDir(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB5AdbObjDir;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB5AdbTrkInfo(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB5AdbTrkInfo;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB5AdbAbsDist(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB5AdbAbsDist;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB5AdbVertAg(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB5AdbVertAg;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB5AdbObjHozlAgSpdRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB5AdbObjHozlAgSpdRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB5AdbHozlAgLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB5AdbHozlAgLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB5AdbHozlAgRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB5AdbHozlAgRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB5AdbObjHozlAgSpdLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB5AdbObjHozlAgSpdLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB2AdbObjDir(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB2AdbObjDir;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB2AdbTrkInfo(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB2AdbTrkInfo;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB2AdbAbsDist(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB2AdbAbsDist;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB2AdbClassn(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB2AdbClassn;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB2AdbVertAg(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB2AdbVertAg;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB2AdbObjHozlAgSpdRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB2AdbObjHozlAgSpdRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB2AdbObjHozlAgSpdLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB2AdbObjHozlAgSpdLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB2AdbHozlAgLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB2AdbHozlAgLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB2AdbHozlAgRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB2AdbHozlAgRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_SteerWhlSnsrQf(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_SteerWhlSnsrQf;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_SteerWhlSnsrAg(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_SteerWhlSnsrAg;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_SteerWhlSnsrAgSpd(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_SteerWhlSnsrAgSpd;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB6AdbClassn(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB6AdbClassn;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB6AdbObjDir(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB6AdbObjDir;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB6AdbTrkInfo(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB6AdbTrkInfo;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB6AdbAbsDist(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB6AdbAbsDist;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB6AdbVertAg(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB6AdbVertAg;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB6AdbObjHozlAgSpdRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB6AdbObjHozlAgSpdRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB6AdbHozlAgLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB6AdbHozlAgLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB6AdbHozlAgRi(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB6AdbHozlAgRi;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_VehObjforADB6AdbObjHozlAgSpdLe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_VehObjforADB6AdbObjHozlAgSpdLe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_ActnOfLedLoBeamActnOfLedLoBeam(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_ActnOfLedLoBeamActnOfLedLoBeam;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedLoBeamRiUpprBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedLoBeamRiUpprBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedLoBeamRiContTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedLoBeamRiContTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedLoBeamRiOffsTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedLoBeamRiOffsTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedLoBeamRiModePrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedLoBeamRiModePrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedLoBeamRiLowBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedLoBeamRiLowBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForLedLoBeamRiTistamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForLedLoBeamRiTistamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_SuspPosnVertAgSuspPosnVertAg(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_SuspPosnVertAgSuspPosnVertAg;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_SuspPosnVertAgGenQf(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_SuspPosnVertAgGenQf;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_SuspPosnVertLvlReQf(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_SuspPosnVertLvlReQf;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_SuspPosnVertLvlRe(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_SuspPosnVertLvlRe;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_SuspPosnVertLvlFrnt(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_SuspPosnVertLvlFrnt;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_SuspPosnVertLvlFrntQf(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_SuspPosnVertLvlFrntQf;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmLedRiGrilleLampOffsTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmLedRiGrilleLampOffsTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmLedRiGrilleLampTistamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmLedRiGrilleLampTistamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmLedRiGrilleLampLowBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmLedRiGrilleLampLowBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmLedRiGrilleLampModePrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmLedRiGrilleLampModePrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmLedRiGrilleLampUpprBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmLedRiGrilleLampUpprBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmLedRiGrilleLampContTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmLedRiGrilleLampContTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmLedRiSideLogoLiModePrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmLedRiSideLogoLiModePrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmLedRISideLogoLiLowBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmLedRISideLogoLiLowBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmLedRiSideLogoLiUpprBriPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmLedRiSideLogoLiUpprBriPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmLedRiSideLogoLiTistamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmLedRiSideLogoLiTistamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmLedRiSideLogoLiContTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmLedRiSideLogoLiContTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLitPrmLedRiSideLogoLiOffsTiPrm(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLitPrmLedRiSideLogoLiOffsTiPrm;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp1LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp1LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp1OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp1OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp1HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp1HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp1Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp1Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp1Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp1Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp1ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp1ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp2LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp2LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp2OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp2OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp2HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp2HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp2Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp2Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp2Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp2Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp2ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp2ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp3LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp3LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp3OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp3OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp3HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp3HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp3Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp3Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp3Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp3Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp3ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp3ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp4LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp4LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp4OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp4OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp4HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp4HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp4Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp4Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp4Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp4Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp4ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp4ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp5LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp5LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp5OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp5OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp5HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp5HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp5Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp5Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp5Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp5Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp5ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp5ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp6LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp6LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp6OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp6OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp6HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp6HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp6Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp6Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp6Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp6Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp6ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp6ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp7LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp7LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp7OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp7OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp7HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp7HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp7Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp7Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp7Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp7Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp7ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp7ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp8LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp8LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp8OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp8OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp8HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp8HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp8Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp8Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp8Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp8Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp8ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp8ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp9LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp9LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp9OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp9OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp9HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp9HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp9Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp9Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp9Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp9Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp9ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp9ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp10LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp10LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp10OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp10OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp10HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp10HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp10Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp10Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp10Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp10Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp10ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp10ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp11LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp11LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp11OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp11OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp11HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp11HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp11Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp11Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp11Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp11Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp11ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp11ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp12LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp12LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp12OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp12OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp12HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp12HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp12Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp12Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp12Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp12Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp12ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp12ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp13LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp13LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp13OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp13OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp13HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp13HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp13Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp13Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp13Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp13Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp13ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp13ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp14LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp14LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp14OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp14OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp14HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp14HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp14Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp14Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp14Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp14Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp14ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp14ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp15LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp15LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp15OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp15OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp15HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp15HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp15Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp15Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp15Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp15Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp15ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp15ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp16LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp16LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp16OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp16OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp16HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp16HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp16Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp16Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp16Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp16Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp16ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp16ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp17LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp17LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp17OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp17OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp17HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp17HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp17Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp17Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp17Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp17Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp17ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp17ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp18LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp18LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp18OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp18OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp18HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp18HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp18Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp18Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp18Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp18Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp18ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp18ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp19LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp19LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp19OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp19OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp19HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp19HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp19Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp19Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp19Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp19Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp19ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp19ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp20LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp20LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp20OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp20OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp20HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp20HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp20Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp20Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp20Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp20Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp20ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp20ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp21LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp21LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp21OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp21OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp21HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp21HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp21Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp21Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp21Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp21Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp21ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp21ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp22LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp22LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp22OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp22OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp22HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp22HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp22Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp22Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp22Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp22Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp22ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp22ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp23LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp23LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp23OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp23OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp23HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp23HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp23Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp23Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp23Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp23Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp23ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp23ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp24LowBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp24LowBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp24OffsetTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp24OffsetTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp24HighBrightness(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp24HighBrightness;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp24Mode1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp24Mode1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp24Timestamp(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp24Timestamp;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_DwnLoadDynLtgPrmForFrntRIGrp24ContinueTime(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_DwnLoadDynLtgPrmForFrntRIGrp24ContinueTime;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TiAndDateIndcnDay(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TiAndDateIndcnDay;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TiAndDateIndcnYr1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TiAndDateIndcnYr1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TiAndDateIndcnMins1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TiAndDateIndcnMins1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TiAndDateIndcnMth1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TiAndDateIndcnMth1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TiAndDateIndcnHr1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TiAndDateIndcnHr1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TiAndDateIndcnSec1(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TiAndDateIndcnSec1;
//     return rtval;
// }

// Std_ReturnType Interface_GetSignal_TiAndDateIndcnDataValid(uint32_t * SignalValue)
// {
//     Std_ReturnType rtval = E_OK;

//     *SignalValue = Signal_TiAndDateIndcnDataValid;
//     return rtval;
// }


// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmForLedHiBeamRiLowBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmForLedHiBeamLeLowBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmForLedHiBeamRiModePrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmForLedHiBeamLeModePrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmForLedHiBeamRiUpprBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmForLedHiBeamLeUpprBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmForLedHiBeamRiOffsTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmForLedHiBeamLeOffsTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmForLedHiBeamRiContTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmForLedHiBeamLeContTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmForLedHiBeamRiTistamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmForLedHiBeamLeTistamp = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmForLedLoBeamRiContTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmForLedLoBeamLeContTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmForLedLoBeamRiModePrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmForLedLoBeamLeModePrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmForLedLoBeamRiLowBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmForLedLoBeamLeLowBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmForLedLoBeamRiOffsTiPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmForLedLoBeamLeOffsTiPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmForLedLoBeamRiUpprBriPrm(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmForLedLoBeamLeUpprBriPrm = SignalValue;
//     return rtval;
// }

// Std_ReturnType Interface_SetSignal_DwnLoadDynLitPrmForLedLoBeamRiTistamp(uint32_t SignalValue)
// {
//     Std_ReturnType rtval = E_OK;
   
//     Signal_DwnLoadDynLitPrmForLedLoBeamLeTistamp = SignalValue;
//     return rtval;
// }




// #endif



// void ComSignalInterfaceMainFunction(uint8_t timebase)
// {
// #if (BASE_TECH_PLATFORM == BASE_TECH_3_0)
//     static uint8_t CanNmUserData[6] = {0x00, 0x00, 0x00, 0x00, 0x01, 0x05};
//     Com_SendSignal(isCanNmUserData_BodyExposedCAN_HCML, CanNmUserData);
// #endif
// #if HCM_LEFT_SIDE 	
//     Com_SendSignal(StsOfLedHiBeamLe_IPDU_COM_HcmlBodyExpoSignalIPDU02,&StsOfLedHiBeamLe);
//     Com_SendSignal(StsOfLedLoBeamLe_IPDU_COM_HcmlBodyExpoSignalIPDU02,&StsOfLedLoBeamLe);
//     Com_SendSignal(ExtrLiShowStoreStsFrntLe_IPDU_COM_HcmlBodyExpoSignalIPDU02,&ExtrLiShowStoreStsFrntLe);
//     Com_SendSignal(StsOfLedLeLogoLamp_IPDU_COM_HcmlBodyExpoSignalIPDU02,&StsOfLedLeLogoLamp);
//     Com_SendSignal(StsOfLedFrntTurnIndcrLe_IPDU_COM_HcmlBodyExpoSignalIPDU04,&StsOfLedFrntTurnIndcrLe);
//     Com_SendSignal(StsOfTouristModLe_IPDU_COM_HcmlBodyExpoSignalIPDU04,&StsOfTouristModLe);
//     Com_SendSignal(StsOfLedDaytiRunngLampLe_IPDU_COM_HcmlBodyExpoSignalIPDU04,&StsOfLedDaytiRunngLampLe);
//     Com_SendSignal(StsOfLedFrntFogLampLe_IPDU_COM_HcmlBodyExpoSignalIPDU04,&StsOfLedFrntFogLampLe);
//     Com_SendSignal(StsOfAfsLe_IPDU_COM_HcmlBodyExpoSignalIPDU04,&StsOfAfsLe);
//     Com_SendSignal(StsOfAhbcLe_IPDU_COM_HcmlBodyExpoSignalIPDU04,&StsOfAhbcLe);
//     Com_SendSignal(StsOfSwvlgLe_IPDU_COM_HcmlBodyExpoSignalIPDU04,&StsOfSwvlgLe);
//     Com_SendSignal(StsOfFrntSideMkrLampLe2_IPDU_COM_HcmlBodyExpoSignalIPDU04,&StsOfFrntSideMkrLampLe2);
//     Com_SendSignal(StsOfLedCornrgLampLe_IPDU_COM_HcmlBodyExpoSignalIPDU04,&StsOfLedCornrgLampLe);
//     Com_SendSignal(StsOfLedFrntPosnLampLe_IPDU_COM_HcmlBodyExpoSignalIPDU04,&StsOfLedFrntPosnLampLe);
//     Com_SendSignal(HdlampLeInpSts1_IPDU_COM_HcmlBodyExpoSignalIPDU04,&HdlampLeInpSts1);
//     Com_SendSignal(HdlampLeInpSts2_IPDU_COM_HcmlBodyExpoSignalIPDU04,&HdlampLeInpSts2);
//     Com_SendSignal(ExtrLiShowActvnFrntLeFb_IPDU_COM_HcmlBodyExpoSignalIPDU04,&ExtrLiShowActvnFrntLeFb);
//     Com_SendSignal(DwnLoadStsFbOfHdlampLe_IPDU_COM_HcmlBodyExpoSignalIPDU04,&DwnLoadStsFbOfHdlampLe);
//     Com_SendSignal(ExtrLiShowActvnLeLogoFb_IPDU_COM_HcmlBodyExpoSignalIPDU04,&ExtrLiShowActvnLeLogoFb);
//     Com_SendSignal(DwnLoadStsFbOfLogoLampLe_IPDU_COM_HcmlBodyExpoSignalIPDU04,&DwnLoadStsFbOfLogoLampLe);
//     Com_SendSignal(StsOfWelGbyFrntLe_IPDU_COM_HcmlBodyExpoSignalIPDU04,&StsOfWelGbyFrntLe);
//     Com_SendSignal(igStsOfLvlgLe_StsOfLvlgLeStsOfLvlgLe_IPDU_COM_HcmlBodyExpoSignalIPDU04,&StsOfLvlg);
//     Com_SendSignal(LvlgMtrAgle_IPDU_COM_HcmlBodyExpoSignalIPDU02,&LvlgMtrAgle);
    
//     Com_SendSignalGroup(igStsOfLvlgLe);
// #elif HCM_RIGHT_SIDE 
//     Com_SendSignal(StsOfLedHiBeamLe_IPDU_COM_HcmlBodyExpoSignalIPDU02,&StsOfLedHiBeamLe);
//     Com_SendSignal(StsOfLedLoBeamLe_IPDU_COM_HcmlBodyExpoSignalIPDU02,&StsOfLedLoBeamLe);
//     Com_SendSignal(ExtrLiShowStoreStsFrntLe_IPDU_COM_HcmlBodyExpoSignalIPDU02,&ExtrLiShowStoreStsFrntLe);
//     Com_SendSignal(StsOfLedLeLogoLamp_IPDU_COM_HcmlBodyExpoSignalIPDU02,&StsOfLedLeLogoLamp);
//     Com_SendSignal(StsOfLedFrntTurnIndcrLe_IPDU_COM_HcmlBodyExpoSignalIPDU04,&StsOfLedFrntTurnIndcrLe);
//     Com_SendSignal(StsOfTouristModLe_IPDU_COM_HcmlBodyExpoSignalIPDU04,&StsOfTouristModLe);
//     Com_SendSignal(StsOfLedDaytiRunngLampLe_IPDU_COM_HcmlBodyExpoSignalIPDU04,&StsOfLedDaytiRunngLampLe);
//     Com_SendSignal(StsOfLedFrntFogLampLe_IPDU_COM_HcmlBodyExpoSignalIPDU04,&StsOfLedFrntFogLampLe);
//     Com_SendSignal(StsOfAfsLe_IPDU_COM_HcmlBodyExpoSignalIPDU04,&StsOfAfsLe);
//     Com_SendSignal(StsOfAhbcLe_IPDU_COM_HcmlBodyExpoSignalIPDU04,&StsOfAhbcLe);
//     Com_SendSignal(StsOfSwvlgLe_IPDU_COM_HcmlBodyExpoSignalIPDU04,&StsOfSwvlgLe);
//     Com_SendSignal(StsOfFrntSideMkrLampLe2_IPDU_COM_HcmlBodyExpoSignalIPDU04,&StsOfFrntSideMkrLampLe2);
//     Com_SendSignal(StsOfLedCornrgLampLe_IPDU_COM_HcmlBodyExpoSignalIPDU04,&StsOfLedCornrgLampLe);
//     Com_SendSignal(StsOfLedFrntPosnLampLe_IPDU_COM_HcmlBodyExpoSignalIPDU04,&StsOfLedFrntPosnLampLe);
//     Com_SendSignal(HdlampLeInpSts1_IPDU_COM_HcmlBodyExpoSignalIPDU04,&HdlampLeInpSts1);
//     Com_SendSignal(HdlampLeInpSts2_IPDU_COM_HcmlBodyExpoSignalIPDU04,&HdlampLeInpSts2);
//     Com_SendSignal(ExtrLiShowActvnFrntLeFb_IPDU_COM_HcmlBodyExpoSignalIPDU04,&ExtrLiShowActvnFrntLeFb);
//     Com_SendSignal(DwnLoadStsFbOfHdlampLe_IPDU_COM_HcmlBodyExpoSignalIPDU04,&DwnLoadStsFbOfHdlampLe);
//     Com_SendSignal(ExtrLiShowActvnLeLogoFb_IPDU_COM_HcmlBodyExpoSignalIPDU04,&ExtrLiShowActvnLeLogoFb);
//     Com_SendSignal(DwnLoadStsFbOfLogoLampLe_IPDU_COM_HcmlBodyExpoSignalIPDU04,&DwnLoadStsFbOfLogoLampLe);
//     Com_SendSignal(StsOfWelGbyFrntLe_IPDU_COM_HcmlBodyExpoSignalIPDU04,&StsOfWelGbyFrntLe);
//     Com_SendSignal(igStsOfLvlgLe_StsOfLvlgLeStsOfLvlgLe_IPDU_COM_HcmlBodyExpoSignalIPDU04,&StsOfLvlg);
//     Com_SendSignal(LvlgMtrAgle_IPDU_COM_HcmlBodyExpoSignalIPDU02,&LvlgMtrAgle);
    
//     Com_SendSignalGroup(igStsOfLvlgLe);
// #endif
// }