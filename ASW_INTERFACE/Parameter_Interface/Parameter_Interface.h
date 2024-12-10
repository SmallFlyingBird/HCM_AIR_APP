/*
 * Parameter_Interface.h
 *
 *  Created on: 2024骞�1鏈�10鏃�
 *      Author: mihuiliang
 */

#ifndef ASW_INTERFACE_PARAMETER_INTERFACE_PARAMETER_INTERFACE_H_
#define ASW_INTERFACE_PARAMETER_INTERFACE_PARAMETER_INTERFACE_H_

#include "HcmPlatform.h"
#include "HighSide_Interface.h"

/****************************************************************************************************/
/****************************************************************************************************/
/********************************Mapping related Parameter*******************************************/
/****************************************************************************************************/
/****************************************************************************************************/
uint16_t GetChannelMaskByLightFunction(Light_Functions lf);
uint16_t Get_LightN_1(void);
const uint8_t *Get_PixelNoforchannel(void);
uint16_t Get_DRL_TI_surfaces_Near(void);
uint16_t Get_DRL_TI_surfaces_apparent(void);
uint16_t Get_POS_TI_surfaces_apparent(void);

/****************************************************************************************************/
/****************************************************************************************************/
/*****************************ChnConfig_Derating related Parameter***********************************/
/****************************************************************************************************/
/****************************************************************************************************/
uint8_t Get_pChannelEnable(E_ChannelID index);
uint16_t Get_pLedUminVoltage(E_ChannelID index);
uint16_t Get_pLedUmaxVoltage(E_ChannelID index);
uint16_t Get_pLedNormalCurrent(E_ChannelID index);
uint16_t Get_pLedMinCurrent(E_ChannelID index);
uint16_t Get_pLedMaxCurrent(E_ChannelID index);
uint16_t Get_pLedPmaxPower(E_ChannelID index);
uint8_t Get_pLedDerTemp1(E_ChannelID index);
uint8_t Get_pLedDerTemp2(E_ChannelID index);
uint8_t Get_pLedDerTemp3(E_ChannelID index);
uint8_t Get_pLedDerTemp4(E_ChannelID index);
uint8_t Get_pLedDerTemp5(E_ChannelID index);
uint8_t Get_pLedDerPwrA(E_ChannelID channelno);
uint8_t Get_pLedDerPwrB(E_ChannelID channelno);
uint8_t Get_pLedDerPwrC(E_ChannelID channelno);

uint8_t Get_pLedDerMinCurrLoBeamFlat(void);
uint8_t Get_pLedDerMinCurrDirIndcr(void);
uint8_t Get_pLedDerTempHys(void);

//HSD
uint8_t Get_pHSDxOLEnable(uint8_t HsdID);
uint8_t Get_pHSDIOutOC(E_HSChannel HSDChannel);
uint16_t Get_pIOutSCGHSD(E_HSChannel HSDChannel);
uint8_t Get_pHSDMaxVolt(E_HSChannel HSDChannel);
uint8_t Get_pHSDMinVolt(E_HSChannel HSDChannel);
/****************************************************************************************************/
/****************************************************************************************************/
/***********************************NTC related Parameter*******************************************/
/****************************************************************************************************/
/****************************************************************************************************/
uint8_t GetNtcTempByMatrixADCVal(uint8_t adcval, uint8 MtxNtcIndex);
uint8_t GetNtcTempByRegisterVal(uint32 register_val,uint8_t ntctype);
uint8_t Get_pNtcFaultTemp(uint8_t ntcid);
uint8_t Get_pNtcType(uint8_t ntcid);
uint8_t Get_pLedChToNtc(E_ChannelID index);


/****************************************************************************************************/
/****************************************************************************************************/
/***********************************Rcod related Parameter*******************************************/
/****************************************************************************************************/
/****************************************************************************************************/
uint8_t Get_pRcodEnable(void);
uint16_t GetRcodCurrentByRcodIndex(uint8_t index,uint8_t pBinSrcCh,uint8_t IsMatrixIndex);
uint16_t GetRcodCurrentByMatrixADCVal(uint16_t adcval, uint8 MtxRcodIndex);
uint16_t GetRcodCurrentByRegisterVal(uint32 register_val,uint8_t pBinSrcCh);
uint8_t Get_pDefaultRcodIndexChByChannelID(E_ChannelID index);
uint8_t Get_pBinRcodToNTC(uint8 Rcod);
uint8_t Get_pBinSrcChByChannelID(E_ChannelID index);


/****************************************************************************************************/
/****************************************************************************************************/
/**********************************DBLLvlAHB related Parameter***************************************/
/****************************************************************************************************/
/****************************************************************************************************/
/*
 * vehicle LVL type, 0=LVL not available, 1=manual LVL, 2=automatic LVL, 3=reserved
 */
uint8_t Get_pVehLvLType(void);


/*Automatic driving beam configuration paramter. One of: 0=No Glare Free HB; 1=AHB; 2=AHB2; 3=ADB*/
uint8_t Get_pAHBCType(void);

uint8_t  Get_pDCMotrCntrlSCG(void);
uint8_t  Get_pDCMotrCntrlSCB(void);
uint16_t Get_pIOutStallDCMotrHSD(void);
uint8_t  Get_pManLvlDCPos1(void);
uint8_t  Get_pManLvlDCPos2(void);
uint8_t  Get_pManLvlDCPos3(void);
uint8_t  Get_pManLvlDCPos4(void);
uint8_t  Get_pManLvlDCPos5(void);
uint8_t  Get_pLVLSafetyPosDC(void);
uint8_t  Get_pDCMotrCntrlLowrThd(void);
uint8_t  Get_pDCMotrCntrlUpprThd(void);
uint16_t Get_pDCMotrDeactDlyTi(void);

/****************************************************************************************************/
/****************************************************************************************************/
/**********************************Light Control related Parameter***********************************/
/****************************************************************************************************/
/****************************************************************************************************/
uint16_t Get_pLedTimeUpPosTi(void);
uint8_t Get_pLedIntensityPos(void);
uint8_t Get_pLedIntensityPosTi(void);
uint16_t Get_pLedTimeUpDrlTi(void);
uint8_t Get_pLedIntensityDrlTi(void);
uint8_t Get_pLedIntensityDrlTi40mm(void);
uint8_t Get_pLedSeqTiHwl(void);

uint8_t Get_pLedIntensFogLDuty(void);

uint8_t Get_pLedONDelay(Light_Functions lf);
uint8_t Get_pLedOFFDelay(Light_Functions lf);
uint16_t Get_pLedOnRampTi(Light_Functions lf);
uint16_t Get_pLedOffRampTi(Light_Functions lf);
uint8_t Get_pLogoLowbeamPOS(void);

/****************************************************************************************************/
/****************************************************************************************************/
/**********************************Fan Parameter*****************************************************/
/****************************************************************************************************/
/****************************************************************************************************/

uint16_t Get_pFanToChannel(void);
uint16_t Get_pFanOnLedCh(void);
uint8_t  Get_pFanLedTempHys(void);
uint16_t Get_pFanSupInrushTime(void);
uint16_t Get_pFanNomCurrent(void);
uint8_t  Get_pFanNomCurTol(void);
uint16_t Get_pFanLockDebTime(void);
uint8_t  Get_pFanLockProtOnTime0(void);
uint8_t  Get_pFanLockProtOnTime1(void);
uint8_t  Get_pFanLockProtTimeTol0(void);
uint8_t  Get_pFanLockRetryOffTime(void);
uint8_t  Get_pFanFaultSignal(void);
uint8_t  Get_pFanCoolLedTempLo(void);
uint8_t  Get_pFanCoolLedTempHi(void);
uint8_t  Get_pFanCoolPowerLo(void);
uint8_t  Get_pFanCoolPowerHi(void);

/****************************************************************************************************/
/****************************************************************************************************/
/******************************************ADB Parameter*********************************************/
/****************************************************************************************************/
/****************************************************************************************************/

const uint16_t * Get_pPixelLeft_LeftBdr(void);
const uint16_t * Get_pPixelLeft_RightBdr(void);
const uint16_t * Get_pPixelRight_LeftBdr(void);
const uint16_t * Get_pPixelRight_RightBdr(void);

/****************************************************************************************************/
/****************************************************************************************************/
/**********************************Dynamic Light Pattern Parameter***********************************/
/****************************************************************************************************/
/****************************************************************************************************/
/*Welcome 1*/
const uint8 *Get_Dynamic_Light_Function_pWelcomP1ModeLowBri_By_Group(E_LED_Group_ID Group_NO);
const uint16 *Get_Dynamic_Light_Function_pWelcomP1OffTiConTiUpBri_By_Group(E_LED_Group_ID Group_NO);
/*Welcome 2*/
const uint8 *Get_Dynamic_Light_Function_pWelcomP2ModeLowBri_By_Group(E_LED_Group_ID Group_NO);
const uint16 *Get_Dynamic_Light_Function_pWelcomP2OffTiConTiUpBri_By_Group(E_LED_Group_ID Group_NO);
/*Welcome 3*/
const uint8 *Get_Dynamic_Light_Function_pWelcomP3ModeLowBri_By_Group(E_LED_Group_ID Group_NO);
const uint16 *Get_Dynamic_Light_Function_pWelcomP3OffTiConTiUpBri_By_Group(E_LED_Group_ID Group_NO);

#endif /* ASW_INTERFACE_PARAMETER_INTERFACE_PARAMETER_INTERFACE_H_ */
