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

#define MAX_LVL_ACC 	20
#define MAX_LVL_BRAKE 	20

#define MAX_SVL_ACC 	32
#define MAX_SVL_BRAKE   32

/*版本号 0.0.0*/
#define PARAMETER_INTERFACE_VERSION_HIGH_BYTE 				0
#define PARAMETER_INTERFACE_VERSION_MIDDLE_BYTE 			0
#define PARAMETER_INTERFACE_VERSION_LOW_BYTE 				0

/****************************************************************************************************/
/****************************************************************************************************/
/*******************************Title Page related Parameter*****************************************/
/****************************************************************************************************/
/****************************************************************************************************/
uint8 Get_Variant(void);
uint8 *Get_LeftPartNumber_Address(void);
uint8 *Get_RightPartNumber_Address(void);
/****************************************************************************************************/
/****************************************************************************************************/
/********************************Mapping related Parameter*******************************************/
/****************************************************************************************************/
/****************************************************************************************************/
uint16_t GetChannelMaskByLightFunction(Light_Functions lf);
uint16_t Get_LightN_1(void);

uint16_t Get_MatrixRealisation(void);
const uint8_t *Get_PixelNoforchannel(void);
uint16_t Get_DRL_TI_surfaces_Near(void);
uint16_t Get_DRL_TI_surfaces_apparent(void);
uint16_t Get_POS_TI_surfaces_apparent(void);


/****************************************************************************************************/
/****************************************************************************************************/
/********************************TPSSetting related Parameter****************************************/
/****************************************************************************************************/
/****************************************************************************************************/
uint8_t Get_pLMMADCID(void);
uint8_t Get_pLMMPWMTick(void);
uint8_t Get_pLMMCMWEN(void);
uint8_t Get_pLMMCMWTAP(void);
const uint16_t *Get_LB_HB_PhsSft(uint8_t id);
const uint16_t *Get_TI_PhsSft(uint8_t id);
const uint16_t *Get_DRL_POS_PhsSft(uint8_t id);
const uint16_t *Get_Grille_PhsSft(uint8_t id);
const uint16_t *Get_Logo_PhsSft(uint8_t id);
const uint16_t *Get_Assistant_PhsSft(uint8_t id);
const uint16_t *Get_FrontCross_PhsSft(uint8_t id);
const uint8_t *Get_LB_HB_MatrixInfo(uint8_t id);
const uint8_t *Get_TI_MatrixInfo(uint8_t id);
const uint8_t *Get_DRL_POS_MatrixInfo(uint8_t id);
const uint8_t *Get_Grille_MatrixInfo(uint8_t id);
const uint8_t *Get_Logo_MatrixInfo(uint8_t id);
const uint8_t *Get_Assistant_MatrixInfo(uint8_t id);
const uint8_t *Get_FrontCross_MatrixInfo(uint8_t id);

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

uint8_t Get_pHSDxOLEnable(uint8_t HsdID);
uint8_t Get_pLedDerMinCurrLoBeamFlat(void);
uint8_t Get_pLedDerMinCurrDirIndcr(void);
uint8_t Get_pLedDerTempHys(void);

/****************************************************************************************************/
/****************************************************************************************************/
/***********************************NTC related Parameter*******************************************/
/****************************************************************************************************/
/****************************************************************************************************/
uint8_t Get_pNtcSCAdc(uint8_t ntcindex);
uint8_t Get_pNtcOCAdc(uint8_t ntcindex);
uint8_t GetNtcTempByMatrixADCVal(uint8_t adcval, uint8 MtxNtcIndex);
uint8_t GetNtcTempByRegisterVal(uint32 register_val,uint8_t ntctype);
uint8_t Get_pNtcFaultTemp(uint8_t ntcid);
uint8_t Get_pNtcType(uint8_t ntcid);
uint8_t Get_pLedChToNtc(E_ChannelID index);
uint8_t Get_pLMMAddNTC_Mx1(void);
uint8_t Get_pLMMAddNTC_Mx2(void); 
uint8_t Get_pLMMAdcPort_Mx1(void);
uint8_t Get_pLMMAdcPort_Mx2(void);


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
uint8_t Get_pLMMAddRcod1(void);
uint8_t Get_pLMMAdcPortRcod1(void);
uint8_t Get_pLMMAddRcod2(void);
uint8_t Get_pLMMAdcPortRcod2(void);

/****************************************************************************************************/
/****************************************************************************************************/
/**********************************AFS related Parameter*********************************************/
/****************************************************************************************************/
/****************************************************************************************************/
const uint8_t * Get_pLowBeamPWMPixel_P(void);
const uint8_t * Get_pTownLightPWMPixel_P(void);
const uint8_t * Get_pMotorWayPWMPixel_P(void);
const uint8_t * Get_pCountryLightPWMPixel_P(void);
const uint8_t * Get_pWeatherLightPWMPixel_P(void);
const uint8_t * Get_pLHTPWMPixel_P(void);

const uint8_t * Get_pLowBeamPWMPixel_R_P(void);
const uint8_t * Get_pTownLightPWMPixel_R_P(void);
const uint8_t * Get_pMotorWayPWMPixel_R_P(void);
const uint8_t * Get_pCountryLightPWMPixel_R_P(void);
const uint8_t * Get_pWeatherLightPWMPixel_R_P(void);
const uint8_t * Get_pLHTPWMPixel_R_P(void);

uint8_t Get_pLowBeamPWMPixel(uint8_t pixelNum);
uint8_t Get_pHighBeamPWMPixel(uint8_t pixelNum);
uint8_t Get_pTownLightPWMPixel(uint8_t pixelNum);
uint8_t Get_pMotorWayPWMPixel(uint8_t pixelNum);
uint8_t Get_pCountryLightPWMPixel(uint8_t pixelNum);
uint8_t Get_pWeatherLightPWMPixel(uint8_t pixelNum);
uint8_t Get_pLHTPWMPixel(uint8_t pixelNum);

uint8_t Get_pLowBeamPWMPixel_R(uint8_t pixelNum);
uint8_t Get_pHighBeamPWMPixel_R(uint8_t pixelNum);
uint8_t Get_pTownLightPWMPixel_R(uint8_t pixelNum);
uint8_t Get_pMotorWayPWMPixel_R(uint8_t pixelNum);
uint8_t Get_pCountryLightPWMPixel_R(uint8_t pixelNum);
uint8_t Get_pWeatherLightPWMPixel_R(uint8_t pixelNum);
uint8_t Get_pLHTPWMPixel_R(uint8_t pixelNum);

uint16  Get_ParaMgr_pSpdThd1OfAfs(void);
uint16  Get_ParaMgr_pSpdThd2OfAfs(void);
uint16  Get_ParaMgr_pSpdThd3OfAfs(void);
uint8  Get_ParaMgr_pSpdzoneOfAfsHys(void);
uint8  Get_ParaMgr_pTownLightEn(void);
uint8  Get_ParaMgr_pCountryLightEn(void);
uint8  Get_ParaMgr_pAWLightEn(void);
uint8  Get_ParaMgr_pMotorwayLightEn(void);
uint8  Get_ParaMgr_pTouristMod(void);
uint8  Get_ParaMgr_pTownLightLoBeamFlatInt(void);
uint8  Get_ParaMgr_pTownLightLoBeamKinkInt(void);
uint8  Get_ParaMgr_pAWLLoBeamFlatInt(void);
uint8  Get_ParaMgr_pAWLLoBeamKinkInt(void);
uint8  Get_ParaMgr_pMotorwayLoBeamFlatInt(void);
uint8  Get_ParaMgr_pMotorwayLoBeamKinkInt(void);
uint8  Get_ParaMgr_pCountryLoBeamFlatInt(void);
uint8  Get_ParaMgr_pCountryLoBeamKinkInt(void);

uint8   Get_ParaMgr_pTownCornerLightPWM(void);
uint16  Get_ParaMgr_pMotorwayChngOvrTime(void);
uint16  Get_ParaMgr_pCountryChngOvrTime(void);
uint16  Get_ParaMgr_pTownChngOvrTime(void);
uint16  Get_ParaMgr_pAWLChngOvrTime(void);
uint16  Get_ParaMgr_pTourMdChngOvrTime(void);
uint16  Get_ParaMgr_pLoBeamChngOvrTime(void);
uint8   Get_ParaMgr_pTownLightCornerLight(void);
uint8   Get_ParaMgr_pAWLLightFogLight(void);
uint16  Get_ParaMgr_pAWLOffsetLeftLvl_deg(void);
uint16  Get_ParaMgr_pAWLOffsetRightLvl_deg(void);
uint16  Get_ParaMgr_pCountryOffsetLeftLvl_deg(void);
uint16  Get_ParaMgr_pCountryOffsetRightLvl_deg(void);
uint16  Get_ParaMgr_pMotorwayOffsetLeftLvl_deg(void);
uint16  Get_ParaMgr_pMotorwayOffsetRightLvl_deg(void);
uint16  Get_ParaMgr_pTownOffsetLeftLvl_deg(void);
uint16  Get_ParaMgr_pTownOffsetRightLvl_deg(void);
uint16  Get_ParaMgr_pTownOffsetLeftDBL_deg(void);
uint16  Get_ParaMgr_pTownOffsetRightDBL_deg(void);
uint16  Get_ParaMgr_pCountryOffsetLeftDBL_deg(void);
uint16  Get_ParaMgr_pCountryOffsetRightDBL_deg(void);
uint16  Get_ParaMgr_pMotorwayOffsetLeftDBL_deg(void);
uint16  Get_ParaMgr_pMotorwayOffsetRightDBL_deg(void);
uint16  Get_ParaMgr_pAWLOffsetLeftDBL_deg(void);
uint16  Get_ParaMgr_pAWLOffsetRightDBL_deg(void);

const uint8  Get_ParaMgr_pAFSLightDRL(void);
const uint16 Get_ParaMgr_pAFSDRLPWM(void);

const uint8 *Get_pLowBeamPWMPixel_head(void);
const uint8 *Get_pHighBeamPWMPixel_B_head(void);
const uint8 *Get_pTownLightPWMPixel_head(void);
const uint8 *Get_pMotorWayPWMPixel_head(void);
const uint8 *Get_pCountryLightPWMPixel_head(void);
const uint8 *Get_pWeatherLightPWMPixel_head(void);
const uint8 *Get_pLHTPWMPixel_head(void);

const uint8 *Get_pLowBeamPWMPixel_R_head(void);
const uint8 *Get_pHighBeamPWMPixel_R_B_head(void);
const uint8 *Get_pTownLightPWMPixel_R_head(void);
const uint8 *Get_pMotorWayPWMPixel_R_head(void);
const uint8 *Get_pCountryLightPWMPixel_R_head(void);
const uint8 *Get_pWeatherLightPWMPixel_R_head(void);
const uint8 *Get_pLHTPWMPixel_R_head(void);


/****************************************************************************************************/
/****************************************************************************************************/
/**********************************DBLLvlAHB related Parameter***************************************/
/****************************************************************************************************/
/****************************************************************************************************/
/*
 * vehicle LVL type, 0=LVL not available, 1=manual LVL, 2=automatic LVL, 3=reserved
 */
uint8_t Get_pVehLvLType(void);
/*
 * Type of Realisation of DBL function:
 *  0: DBL not avaiable, 1: DBL in Stepper motor w/o Hall sensor , 2: DBL in Stepper motor with Hall sensor  , 3: DBL in matrix
 *  pVehDBLType==4 :DBL with cornering light (static bending light)
 *pVehDBLType==5 :DBL in swiveling motor (without hall sensor) with cornering lamp
 *pVehDBLType==6 :DBL in swiveling motor with hallsensor with cornering lamp
 *pVehDBLType==7 :DBL in matrix with cornering lamp.
 *
 */
uint8_t Get_pVehDBLType(void);
/*
*Swiveling: sensor availability and type [1 = not used; 2 = hall@5V; 4 = hall@12V; 8 = inductive@5V; 16 = inductive@12V; other = Invalid]
*/
uint8_t Get_pSensorType(void);
/*Automatic driving beam configuration paramter. One of: 0=No Glare Free HB; 1=AHB; 2=AHB2; 3=ADB*/
uint8_t Get_pAHBCType(void);
/*******************************************************************Light Function: Leveling*************************************************************/
uint8_t Get_pLVLPlsbltyChckEna(void);
uint8_t Get_pLvlPlsbltyErrChckTime(void);
uint8_t Get_pLvlPlsbltyOkChckTime(void);
/* range:(-10) - (+10)  HS*/
sint8_t Get_pLVLOffset(void);
/* range:(-10.00) - (+10.00)  HS*/
double Get_pLVLSafetyposdeg(void);
/* range:(-1000) - (+1000)  HS*/
int16_t Get_pLVLSafetyposHS(void);
/* range:0.0 - 25.5 v*/
double Get_pLvlHoldMinVolt(void);
/* range:0.0 - 25.5 v*/
double Get_pLvlRunMinVolt(void);
/* range:0.0 - 25.5 v*/
double Get_pLvlRunMaxVolt(void);
/* range:0.0 - 25.5 v*/
double Get_pLvlHoldMaxVolt(void);
uint8_t Get_LeLamp_pLvlPolSeq(void);
uint8_t Get_RiLamp_pLvlPolSeq(void);
/* range:-1000 - 0 HS*/
sint16_t Get_LeLamp_pLvlLimBotPos(void);
/* range:-1000 - 0 HS*/
sint16_t Get_RiLamp_pLvlLimBotPos(void);
/* range:-1000 - 0 HS*/
sint16_t Get_LeLamp_pLvlBotPos(void);
/* range:-1000 - 0 HS*/
sint16_t Get_RiLamp_pLvlBotPos(void);
/* range:0 - 1000 HS*/
sint16_t Get_LeLamp_pLvlTopPos(void);
/* range:0 - 1000 HS*/
sint16_t Get_RiLamp_pLvlTopPos(void);
/* range:0 - 1000 HS*/
sint16_t Get_LeLamp_pLvlLimTopPos(void);
/* range:0 - 1000 HS*/
sint16_t Get_RiLamp_pLvlLimTopPos(void);
/* range:-1000 - 1000 HS*/
sint16_t Get_LeLamp_pLvlDfltPosLe(void);
/* range:-1000 - 1000 HS*/
sint16_t Get_RiLamp_pLvlDfltPosRi(void);
/* range:0 - 30 HS*/
uint8_t Get_pLvlCorStepsNum(void);
/* range:0 - 65535 HS/rad*/
uint16_t Get_pLvlHsPerRad(void);
/* range:-10.00 - 10.00 deg*/
double Get_LeLamp_pLvlDfltPosLe_deg(void);
/* range:-10.00 - 10.00 deg*/
double Get_RiLamp_pLvlDfltPosRi_deg(void);
/* range:-45.00 - 45.00 deg*/
double Get_LeLamp_pLvlBotPosdeg(void);
/* range:-45.00 - 45.00 deg*/
double Get_RiLamp_pLvlBotPosdeg(void);
/* range:-45.00 - 45.00 deg*/
double Get_LeLamp_pLvlTopPosdeg(void);
/* range:-45.00 - 45.00 deg*/
double Get_RiLamp_pLvlTopPosdeg(void);
uint8_t Get_pLvlVmaxLowTemp(void);
uint8_t Get_pLvlVmaxNorm(void);
uint8_t Get_pLvlVmaxRef(void);
uint16_t Get_pLvlIrunLowTemp(void);
uint16_t Get_pLvlIrunNorm(void);
uint16_t Get_pLvlIrunRef(void);
uint16_t Get_pLvlIholdLowTemp(void);
uint16_t Get_pLvlIholdNorm(void);
/*return range: 0- 1275 s*/
uint16_t Get_pLvlLowTempHeatupTime(void);
/*return range: -50- 200 °C*/
sint16_t Get_pLvlLowTempThreshold(void);
uint16_t Get_pLvlPreTime(void);
uint16_t Get_pLvlPostTime(void);
uint16_t Get_pLvlUsageInterval(void);
uint8_t Get_pLvlNormUsage(void);
uint8_t Get_pLvlOverUsage(void);
uint8_t Get_pLvlMinDistStart(void);
uint8_t Get_pLvlMinDistTime(void);
uint8_t Get_pLvlFilterTime(void);
uint8_t Get_pLvlStepMode(void);
uint16_t *Get_pLvlAccArray(void);
uint16_t *Get_pLvlBrakeArray(void);
uint8_t Get_pLvlstalldetethreshold(void);
/*retrun rang:-1000 - 1000 hs*/
sint16_t Get_pManLvlAgPos1(void);
/*retrun rang:-1000 - 1000 hs*/
sint16_t Get_pManLvlAgPos2(void);
/*retrun rang:-1000 - 1000 hs*/
sint16_t Get_pManLvlAgPos3(void);
/*retrun rang:-1000 - 1000 hs*/
sint16_t Get_pManLvlAgPos4(void);
/*retrun rang:-1000 - 1000 hs*/
sint16_t Get_pManLvlAgPos5(void);


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

/*******************************************************************Light Function: DBL*************************************************************/
/*
 * Attention: The return value is typeof uint16,the actual degree is  (ParaMgr_pSvlDfltPosdeg_W * 0.01 -50)
 */

uint8_t  Get_pDBCntrPxlBttmRow(void);
uint8_t  Get_pDBCntrPxlMddlRow(void);
uint8_t  Get_pDBCntrPxlTopRow(void);
uint8_t  Get_pDBLeEdgePxlHLBttmRow(void);
uint8_t  Get_pDBRiEdgePxlHLBttmRow(void);
uint8_t  Get_pDBLeEdgePxlHLMddlRow(void);
uint8_t  Get_pDBRiEdgePxlHLMddlRow(void);
uint8_t  Get_pDBLeEdgePxlHLTopRow(void);
uint8_t  Get_pDBRiEdgePxlHLTopRow(void);
uint8_t  Get_pDBLeLimBttmRow(void);
uint8_t  Get_pDBRiLimBttmRow(void);
uint8_t  Get_pDBLeLimMddlRow(void);
uint8_t  Get_pDBRiLimMddlRow(void);
uint8_t  Get_pDBLeLimTopRow(void);
uint8_t  Get_pDBRiLimTopRow(void);
uint16_t Get_pDBTrnsntime(void);
uint16_t Get_pDBPxlShiftDlyTime(void);

uint16_t Get_SvlDfltPosdeg(void);
/*return range :-50.00 - 50.00 deg*/
double Get_LeLamp_SvlLePosdeg(void);
/*return range :-50.00 - 50.00 deg*/
double Get_RiLamp_SvlLePosdeg(void);
/*return range :-50.00 - 50.00 deg*/
double Get_LeLamp_SvlRiPosdeg(void);
/*return range :-50.00 - 50.00 deg*/
double Get_RiLamp_SvlRiPosdeg(void);
/*return range :0 - 25.5 v*/
double Get_pSvlHoldMinVolt(void);
/*return range :0 - 25.5 v*/
double Get_pSvlRunMinVolt(void);
/*return range :0 - 25.5 v*/
double Get_pSvlRunMaxVolt(void);
/*return range :0 - 25.5 v*/
double Get_pSvlHoldMaxVolt(void);
uint8_t Get_LeLamp_pSvlPolSeq(void);
uint8_t Get_RiLamp_pSvlPolSeq(void);
uint8_t Get_LeLamp_pSvlRefDirection(void);
uint8_t Get_RiLamp_pSvlRefDirection(void);
/*return range : -1500 - 0 HS*/
sint16_t Get_LeLamp_SvlLeftBlockPos(void);
/*return range : -1500 - 0 HS*/
sint16_t Get_RiLamp_SvlLeftBlockPos(void);
/*return range : -1500 - 0 HS*/
sint16_t Get_LeLamp_SvlLeftLogicPos(void);
/*return range : -1500 - 0 HS*/
sint16_t Get_RiLamp_SvlLeftLogicPos(void);
/*return range : 0 - 1500 HS*/
sint16_t Get_LeLamp_SvlRightLogicPos(void);
/*return range : 0 - 1500 HS*/
sint16_t Get_RiLamp_SvlRightLogicPos(void);
/*return range : 0 - 1500 HS*/
sint16_t Get_LeLamp_SvlRightBlockPos(void);
/*return range : 0 - 1500 HS*/
sint16_t Get_RiLamp_SvlRightBlockPos(void);
/*return range : -1500 - 1500 HS*/
sint16_t Get_pSvlDfltPos(void);
uint8_t Get_pSvlCorStepsNum(void);
/*return range : -1500 - 1500 HS*/
sint16_t Get_LeLamp_pSvlSensorPos(void);
/*return range : -1500 - 1500 HS*/
sint16_t Get_RiLamp_pSvlSensorPos(void);
uint8_t Get_LeLamp_pSvlSensorEdge(void);
uint8_t Get_RiLamp_pSvlSensorEdge(void);
/*
* return 1:sensor input no inversion
* return 2:sensor input inversion
*/
uint8_t Get_LeLamp_pSvlSensorInv(void) ;
/*
* return 1:sensor input no inversion
* return 2:sensor input inversion
*/
uint8_t Get_RiLamp_pSvlSensorInv(void);
uint8_t Get_pSvlSensorTol(void);
uint8_t Get_pSvlSensorRange(void);
uint8_t Get_pSvlMaxCorNum(void);
uint8_t Get_pSvlVmaxLowTemp(void);
uint8_t Get_pSvlVmaxNorm(void);
uint8_t Get_pSvlVmaxRef(void);
uint16_t Get_pSvlIrunLowTemp(void);
uint16_t Get_pSvlIrunNorm(void);
uint16_t Get_pSvlIrunRef(void);
uint16_t Get_pSvlIholdLowTemp(void);
uint16_t Get_pSvlIholdNorm(void);
uint16_t Get_pSvlLowTempHeatupTime(void);
/*return range: -50 - 200 °C*/
sint16_t Get_pSvlLowTempThreshold(void);
uint16_t Get_pSvlPreTime(void);
uint16_t Get_pSvlPostTime(void);
uint16_t Get_pSvlUsageInterval(void);
uint8_t Get_pSvlOverUsage(void);
uint8_t Get_pSvlNormUsage(void);

uint8_t Get_pSvlMinDistStart(void);
uint8_t Get_pSvlMinDistTime(void);

uint8_t Get_pSvlStepMode(void);
uint16_t Get_pSvlHsPerRad(void);
uint16_t *Get_pSvlAccArray(void);
uint16_t *Get_pSvlBrakeArray(void);
uint8_t Get_pSvlstalldetethreshold(void);

/*******************************************************************Light Function: AHB&AHB2*************************************************************/
/*
 */

uint16_t Get_pAHBCDistOfHiBeam(void);

uint16_t Get_pAHB2OncmngDist1(void);
uint16_t Get_pAHB2OncmngDist2(void);
uint16_t Get_pAHB2OncmngDist3(void);
uint16_t Get_pAHB2OncmngDist4(void);
uint16_t Get_pAHB2OncmngDist5(void);
uint16_t Get_pAHB2OncmngDist6(void);
uint16_t Get_pAHB2OncmngDist7(void);
uint16_t Get_pAHB2OncmngDist8(void);
uint16_t Get_pAHB2OncmngDist9(void);

uint8_t Get_LeLamp_pLVLOffsetLeAHB2OncmngDist1(void) ;
uint8_t Get_LeLamp_pLVLOffsetLeAHB2OncmngDist2(void) ;
uint8_t Get_LeLamp_pLVLOffsetLeAHB2OncmngDist3(void) ;
uint8_t Get_LeLamp_pLVLOffsetLeAHB2OncmngDist4(void) ;
uint8_t Get_LeLamp_pLVLOffsetLeAHB2OncmngDist5(void) ;
uint8_t Get_LeLamp_pLVLOffsetLeAHB2OncmngDist6(void) ;
uint8_t Get_LeLamp_pLVLOffsetLeAHB2OncmngDist7(void) ;
uint8_t Get_LeLamp_pLVLOffsetLeAHB2OncmngDist8(void) ;
uint8_t Get_LeLamp_pLVLOffsetLeAHB2OncmngDist9(void) ;
uint8_t Get_LeLamp_pLVLOffsetLeAHB2OncmngDist10(void);

uint8_t Get_RiLamp_pLVLOffsetRiAHB2OncmngDist1(void) ;
uint8_t Get_RiLamp_pLVLOffsetRiAHB2OncmngDist2(void) ;
uint8_t Get_RiLamp_pLVLOffsetRiAHB2OncmngDist3(void) ;
uint8_t Get_RiLamp_pLVLOffsetRiAHB2OncmngDist4(void) ;
uint8_t Get_RiLamp_pLVLOffsetRiAHB2OncmngDist5(void) ;
uint8_t Get_RiLamp_pLVLOffsetRiAHB2OncmngDist6(void) ;
uint8_t Get_RiLamp_pLVLOffsetRiAHB2OncmngDist7(void) ;
uint8_t Get_RiLamp_pLVLOffsetRiAHB2OncmngDist8(void) ;
uint8_t Get_RiLamp_pLVLOffsetRiAHB2OncmngDist9(void) ;
uint8_t Get_RiLamp_pLVLOffsetRiAHB2OncmngDist10(void);

uint16_t Get_pAHB2PrecdngDist1(void);
uint16_t Get_pAHB2PrecdngDist2(void);
uint16_t Get_pAHB2PrecdngDist3(void);
uint16_t Get_pAHB2PrecdngDist4(void);
uint16_t Get_pAHB2PrecdngDist5(void);
uint16_t Get_pAHB2PrecdngDist6(void);
uint16_t Get_pAHB2PrecdngDist7(void);
uint16_t Get_pAHB2PrecdngDist8(void);
uint16_t Get_pAHB2PrecdngDist9(void);

uint8_t Get_LeLamp_pLVLOffsetLeAHB2PrecdngDist1(void) ;
uint8_t Get_LeLamp_pLVLOffsetLeAHB2PrecdngDist2(void) ;
uint8_t Get_LeLamp_pLVLOffsetLeAHB2PrecdngDist3(void) ;
uint8_t Get_LeLamp_pLVLOffsetLeAHB2PrecdngDist4(void) ;
uint8_t Get_LeLamp_pLVLOffsetLeAHB2PrecdngDist5(void) ;
uint8_t Get_LeLamp_pLVLOffsetLeAHB2PrecdngDist6(void) ;
uint8_t Get_LeLamp_pLVLOffsetLeAHB2PrecdngDist7(void) ;
uint8_t Get_LeLamp_pLVLOffsetLeAHB2PrecdngDist8(void) ;
uint8_t Get_LeLamp_pLVLOffsetLeAHB2PrecdngDist9(void) ;
uint8_t Get_LeLamp_pLVLOffsetLeAHB2PrecdngDist10(void);

uint8_t Get_RiLamp_pLVLOffsetRiAHB2PrecdngDist1(void) ;
uint8_t Get_RiLamp_pLVLOffsetRiAHB2PrecdngDist2(void) ;
uint8_t Get_RiLamp_pLVLOffsetRiAHB2PrecdngDist3(void) ;
uint8_t Get_RiLamp_pLVLOffsetRiAHB2PrecdngDist4(void) ;
uint8_t Get_RiLamp_pLVLOffsetRiAHB2PrecdngDist5(void) ;
uint8_t Get_RiLamp_pLVLOffsetRiAHB2PrecdngDist6(void) ;
uint8_t Get_RiLamp_pLVLOffsetRiAHB2PrecdngDist7(void) ;
uint8_t Get_RiLamp_pLVLOffsetRiAHB2PrecdngDist8(void) ;
uint8_t Get_RiLamp_pLVLOffsetRiAHB2PrecdngDist9(void) ;
uint8_t Get_RiLamp_pLVLOffsetRiAHB2PrecdngDist10(void);

uint16_t Get_pAHB2FrznTi(void);

uint8_t Get_pAHB2SftyMrgnOncmngVrtcl  (void);
uint8_t Get_pAHB2SftyMrgnPrecedngVrtcl(void);

uint8_t Get_pAHB2LightLoBeamFlatInt(void);
uint8_t Get_pAHB2LightLoBeamKinkInt(void);
uint8_t Get_pAHB2LightHiBeamSpotInt(void);
uint8_t Get_pAHB2LightHiBeamSailInt(void);

uint16_t Get_pAHB2ChngOvrTime(void);









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
uint16_t Get_pSTITime(void);
uint8_t Get_pVariantTyp(void);
uint8_t Get_pLedSeqTiHwl(void);
uint8_t Get_pLegalRequirement(void);
uint8_t Get_pLMMBaudRateSet(void);

uint8_t Get_pLedIntensPosLDuty(void);
uint8_t Get_pLedIntensGrillLDuty(void);
uint8_t Get_pLedIntensConerLDuty(void);
uint8_t Get_pLedIntensFogLDuty(void);
uint8_t Get_pLedIntensCrossLDuty(void);

uint8_t Get_pLedGamma(void);
uint8_t Get_pLedONDelay(Light_Functions lf);
uint8_t Get_pLedOFFDelay(Light_Functions lf);
uint16_t Get_pLedOnRampTi(Light_Functions lf);
uint16_t Get_pLedOffRampTi(Light_Functions lf);

uint8_t Get_pFrntCrossAvl(void);
uint8_t Get_pGrilleAvl(void);

uint8_t Get_pFssRelFailSvlDflt(void);

uint16_t Get_pVehHeadlampOverhang(void);
uint16_t Get_pVehHeadlampHeight(void);
uint16_t Get_pVehWheelBase(void);

uint8_t Get_pLogoLowbeamPOS(void);
uint8_t Get_pFrontCrossPositionlamp(void);
uint8_t Get_pSBLCornerLightPWM(void);

uint8_t Get_pPincodeEnable(void);

/****************************************************************************************************/
/****************************************************************************************************/
/**********************************LED Groups related Parameter***********************************/
/****************************************************************************************************/
/****************************************************************************************************/

const uint8* Get_pTIPixelToLedUnitAddress(void); 

/****************************************************************************************************/
/****************************************************************************************************/
/**********************************Fan Parameter*****************************************************/
/****************************************************************************************************/
/****************************************************************************************************/

uint16_t Get_pFanToChannel(void);
uint16_t Get_pFanOnLedCh(void);
uint8_t  Get_pFanAmbTempHys(void);
uint8_t  Get_pFanLedTempHys(void);
uint16_t Get_pFanSupInrushTime(void);
uint16_t Get_pFanNomCurrent(void);
uint8_t  Get_pFanNomCurTol(void);
uint16_t Get_pFanLockDebTime(void);
uint8_t  Get_pFanMaxVolt(void);
uint8_t  Get_pFanMinVolt(void);
uint8_t  Get_pFanLockProtOnTime0(void);
uint8_t  Get_pFanLockProtOnTime1(void);
uint8_t  Get_pFanLockProtTimeTol0(void);
uint8_t  Get_pFanLockProtTimeTol1(void);
uint8_t  Get_pFanLockRetryOffTime(void);
uint8_t  Get_pFanFaultSignal(void);
uint8_t  Get_pFanCoolLedTempLo(void);
uint8_t  Get_pFanCoolLedTempHi(void);
uint8_t  Get_pFanCoolPowerLo(void);
uint8_t  Get_pFanCoolPowerHi(void);
uint8_t  Get_pFanDefAmbTempLo(void);
uint8_t  Get_pFanDefAmbTempHi(void);
uint8_t  Get_pFanDefPowerLo(void);
uint8_t  Get_pFanDefPowerHi(void);
uint8_t  Get_pFanDeiAmbTempLo(void);
uint8_t  Get_pFanDeiAmbTempHi(void);
uint8_t  Get_pFanDeiPowerLo(void);
uint8_t  Get_pFanDeiPowerHi(void);
uint8_t  Get_pFan2CoolLedTempLo(void);

/****************************************************************************************************/
/****************************************************************************************************/
/******************************************ADB Parameter*********************************************/
/****************************************************************************************************/
/****************************************************************************************************/

const uint16_t * Get_pPixelLeft_LeftBdr(void);
const uint16_t * Get_pPixelLeft_RightBdr(void);
const uint16_t * Get_pPixelRight_LeftBdr(void);
const uint16_t * Get_pPixelRight_RightBdr(void);

void  Get_ParaMgr_pFanADBleEna_B( uint8* ADBangletemp );
void  Get_ParaMgr_pFanADBriEna_B( uint8* ADBangletemp );
void  Get_ParaMgr_pFanADBlepPixel_LeftBdrl( uint16* ADBangletemp );
void  Get_ParaMgr_pFanADBlepPixel_RightBdr( uint16* ADBangletemp );
void  Get_ParaMgr_pFanADBripPixel_LeftBdrl( uint16* ADBangletemp );
void  Get_ParaMgr_pFanADBripPixel_RightBdr( uint16* ADBangletemp );

/****************************************************************************************************/
/****************************************************************************************************/
/**********************************Dynamic Light Pattern Parameter***********************************/
/****************************************************************************************************/
/****************************************************************************************************/
/*LED Groups*/
uint8 Get_Dynamic_Light_Function_GroupFunc_ByGroup(E_LED_Group_ID Group_NO);
const uint8 *Get_Dynamic_Light_Function_GroupPixel_Info_ByGroup(E_LED_Group_ID Group_NO);
const uint8 *Get_Dynamic_Light_Function_GroupChannel_Info_ByGroup(E_LED_Group_ID Group_NO);
uint8 Get_Dynamic_Light_Function_p_WelGbyPatten(void);
uint8 Get_Dynamic_Light_Function_p_ParaMgr_pWaitmode(void);
/*WelGby Pattern*/
uint8 Get_Dynamic_Light_Function_pWelMotorEN_B(void);
uint16 Get_Dynamic_Light_Function_pWelLevMotorTime_W(void);
uint16 Get_Dynamic_Light_Function_pWelSwivMotorTime_W(void);
uint32 Get_Dynamic_Light_Function_pELCWelcomeTimeout_DW(void);
/*Welcome 1*/
const uint8 *Get_Dynamic_Light_Function_pWelcomP1ModeLowBri_By_Group(E_LED_Group_ID Group_NO);
const uint16 *Get_Dynamic_Light_Function_pWelcomP1OffTiConTiUpBri_By_Group(E_LED_Group_ID Group_NO);
const uint8 *Get_Dynamic_Light_Function_pWelcomP1ModeLowBri_By_Group_Right(E_LED_Group_ID Group_NO);
const uint16 *Get_Dynamic_Light_Function_pWelcomP1OffTiConTiUpBri_By_Group_Right(E_LED_Group_ID Group_NO);
/*Welcome 2*/
const uint8 *Get_Dynamic_Light_Function_pWelcomP2ModeLowBri_By_Group(E_LED_Group_ID Group_NO);
const uint16 *Get_Dynamic_Light_Function_pWelcomP2OffTiConTiUpBri_By_Group(E_LED_Group_ID Group_NO);
const uint8 *Get_Dynamic_Light_Function_pWelcomP2ModeLowBri_By_Group_Right(E_LED_Group_ID Group_NO);
const uint16 *Get_Dynamic_Light_Function_pWelcomP2OffTiConTiUpBri_By_Group_Right(E_LED_Group_ID Group_NO);
/*Welcome 3*/
const uint8 *Get_Dynamic_Light_Function_pWelcomP3ModeLowBri_By_Group(E_LED_Group_ID Group_NO);
const uint16 *Get_Dynamic_Light_Function_pWelcomP3OffTiConTiUpBri_By_Group(E_LED_Group_ID Group_NO);
/*const uint8 *Get_Dynamic_Light_Function_pWelcomP3ModeLowBri_By_Group_Right(E_LED_Group_ID Group_NO);*/
/*const uint16 *Get_Dynamic_Light_Function_pWelcomP3OffTiConTiUpBri_By_Group_Right(E_LED_Group_ID Group_NO);*/
/*Goodbye 1*/
const uint8 *Get_Dynamic_Light_Function_pGoodbyeP1ModeLowBri_By_Group(E_LED_Group_ID Group_NO);
const uint16 *Get_Dynamic_Light_Function_pGoodbyeP1OffTiConTiUpBri_By_Group(E_LED_Group_ID Group_NO);
const uint8 *Get_Dynamic_Light_Function_pGoodbyeP1ModeLowBri_By_Group_Right(E_LED_Group_ID Group_NO);
const uint16 *Get_Dynamic_Light_Function_pGoodbyeP1OffTiConTiUpBri_By_Group_Right(E_LED_Group_ID Group_NO);
/*Goodbye 2*/
const uint8 *Get_Dynamic_Light_Function_pGoodbyeP2ModeLowBri_By_Group(E_LED_Group_ID Group_NO);
const uint16 *Get_Dynamic_Light_Function_pGoodbyeP2OffTiConTiUpBri_By_Group(E_LED_Group_ID Group_NO);
const uint8 *Get_Dynamic_Light_Function_pGoodbyeP2ModeLowBri_By_Group_Right(E_LED_Group_ID Group_NO);
const uint16 *Get_Dynamic_Light_Function_pGoodbyeP2OffTiConTiUpBri_By_Group_Right(E_LED_Group_ID Group_NO);
/*Goodbye 3*/
const uint8 *Get_Dynamic_Light_Function_pGoodbyeP3ModeLowBri_By_Group(E_LED_Group_ID Group_NO);
const uint16 *Get_Dynamic_Light_Function_pGoodbyeP3OffTiConTiUpBri_By_Group(E_LED_Group_ID Group_NO);
/*const uint8 *Get_Dynamic_Light_Function_pGoodbyeP3ModeLowBri_By_Group_Right(E_LED_Group_ID Group_NO);*/
/*const uint16 *Get_Dynamic_Light_Function_pGoodbyeP3OffTiConTiUpBri_By_Group_Right(E_LED_Group_ID Group_NO);*/
/*Waitemode*/
const uint8 *Get_Dynamic_Light_Function_pWaitModeModeLowBri_By_Group(E_LED_Group_ID Group_NO);
const uint16 *Get_Dynamic_Light_Function_pWaitModeOffTiConTiUpBri_By_Group(E_LED_Group_ID Group_NO);
/*Car Approach Pattern*/
uint8 Get_Dynamic_Light_Function_pCarAppMotorEN_B(void);
uint16 Get_Dynamic_Light_Function_pCarAppLevMotorTime_W(void);
uint16 Get_Dynamic_Light_Function_pCarAppSwivMotorTime_W(void);
uint16 Get_Dynamic_Light_Function_pLedApprLightDimOnTi_W(void);
/*Car Approach*/
const uint8 *Get_Dynamic_Light_Function_pApproachModeLowBri_By_Group(E_LED_Group_ID Group_NO);
const uint16 *Get_Dynamic_Light_Function_pApproachOffTiConTiUpBri_By_Group(E_LED_Group_ID Group_NO);
/*HomeSafety*/
const uint8 *Get_Dynamic_Light_Function_pHomeSafetyModeLowBri_By_Group(E_LED_Group_ID Group_NO);
const uint16 *Get_Dynamic_Light_Function_pHomeSafetyOffTiConTiUpBri_By_Group(E_LED_Group_ID Group_NO);
/*Car Locator*/
const uint8 *Get_Dynamic_Light_Function_pLocatorModeLowBri_By_Group(E_LED_Group_ID Group_NO);
const uint16 *Get_Dynamic_Light_Function_pLocatorOffTiConTiUpBri_By_Group(E_LED_Group_ID Group_NO);
/*Light Show*/
const uint32 Get_Dynamic_Light_Function_ParaMgr_pELCTimeout_DW(void);


#endif /* ASW_INTERFACE_PARAMETER_INTERFACE_PARAMETER_INTERFACE_H_ */
