/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2016)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Com_Cfg.h                                                   **
**                                                                            **
**  Created on  :2024/12/12 15:33:33                                                           
**  Author      : zhiqiang.huang                                              **
**  Vendor      :                                                             **
**  DESCRIPTION : cfg parameter declaration of Com                            **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define COM_CFG_H_AR_MAJOR_VERSION    4
#define COM_CFG_H_AR_MINOR_VERSION    2
#define COM_CFG_H_AR_PATCH_VERSION    2
#define COM_CFG_H_SW_MAJOR_VERSION    1
#define COM_CFG_H_SW_MINOR_VERSION    0
#define COM_CFG_H_SW_PATCH_VERSION    0

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#ifndef  COM_CFG_H
#define  COM_CFG_H

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/


#define COM_CANCELLATION_SUPPORT 			         STD_OFF	
#define COM_DEV_ERROR_DETECT 				         STD_OFF
#define COM_ENABLE_SIGNAL_GROUP_ARRAY_API	         STD_OFF
#define COM_VERSION_INFO_API				         STD_OFF	
#define COM_ENABLE_MDT_FOR_CYCLIC_TRANSMISSION       STD_ON 
#define COM_METADATA_SUPPORT                        STD_OFF
#define COM_RETRY_FAILED_TRANSMIT_REQUESTS	         STD_OFF	
#define COM_IPDUGROUP_NUMBER 				         4	
#define ComIPduGroup_RLM_RS_Tx    0
#define ComIPduGroup_RLM_RS_Rx    1
#define ComIPduGroup_HCML_Tx    2
#define ComIPduGroup_HCML_Rx    3	

#define COM_RXIPDU_NUMBER	4	
#define COM_RXPDU_Com_BCM_RLM_01        0
#define COM_RXPDU_Com_BCM_RLM_02        1
#define COM_RXPDU_Com_ZcudZcud_Lin2Fr01        2
#define COM_RXPDU_Com_ZcudZcud_Lin2Fr02        3
#define COM_TXIPDU_NUMBER	2	
#define COM_TXPDU_Com_RLM_RS_BCM_01        4
#define COM_TXPDU_Com_HcmlZcud_Lin2Fr01        5
#define COM_RXIPDUBUFF_SIZE  30	
#define COM_TXIPDUBUFF_SIZE  15

#define COM_SIGNAL_BOOLBUFF_SIZE			58	
#define COM_RXGROUPSIGNAL_BOOLBUFF_SIZE		0	
#define COM_SIGNAL_BOOL_INVALID_SIZE		0	
#define COM_SIGNAL_BOOL_TIMEOUTID_SIZE      0

#define COM_SIGNAL_8BITBUFF_SIZE	    	44
#define COM_RXGROUPSIGNAL_8BITBUFF_SIZE 	0 
#define COM_SIGNAL_8BIT_INVALID_SIZE		0
#define COM_SIGNAL_8BIT_TIMEOUTID_SIZE      0

#define COM_SIGNAL_16BITBUFF_SIZE 			0
#define COM_RXGROUPSIGNAL_16BITBUFF_SIZE 	0
#define COM_SIGNAL_16BIT_INVALID_SIZE		0
#define COM_SIGNAL_16BIT_TIMEOUTID_SIZE     0

#define COM_SIGNAL_32BITBUFF_SIZE 			0
#define COM_RXGROUPSIGNAL_32BITBUFF_SIZE 	0
#define COM_SIGNAL_32BIT_INVALID_SIZE		0
#define COM_SIGNAL_32BIT_TIMEOUTID_SIZE     0


#define COM_SIGNAL_64BITBUFF_SIZE 			0
#define COM_RXGROUPSIGNAL_64BITBUFF_SIZE 	0
#define COM_SIGNAL_64BIT_INVALID_SIZE		0
#define COM_SIGNAL_64BIT_TIMEOUTID_SIZE     0


#define COM_TMCTXSIGNAL_NUMBER 				0	
#define COM_TMCTXGROUPSIGNAL_NUMBER 		0	

#define COM_TXSIGNALGROUP_NUMBER 			0	

#define COM_RXSIGNALGROUP_NUMBER 			0	

#define COM_TXSIGNAL_NUMBER 				33	
#define RLM_RSResponseErr_RLM_RS_BCM_01               0
#define RLM_RS_ErrEcu_RLM_RS_BCM_01               1
#define RLM_RS_StVolt_RLM_RS_BCM_01               2
#define PosnLiStsReRiSide_RLM_RS_BCM_01               3
#define PosnLiErrIndcnReRiSide_RLM_RS_BCM_01               4
#define PosnLiErrStsReRiSide_RLM_RS_BCM_01               5
#define RvsLiStsReRiSide_RLM_RS_BCM_01               6
#define RvsLiErrIndcnReRiSide_RLM_RS_BCM_01               7
#define RvsLiErrStsReRiSide_RLM_RS_BCM_01               8
#define BrkLiStsReRiSide_RLM_RS_BCM_01               9
#define BrkLiErrIndcnReRiSide_RLM_RS_BCM_01               10
#define BrkLiErrStsReRiSide_RLM_RS_BCM_01               11
#define FogLiStsReRiSide_RLM_RS_BCM_01               12
#define FogLiErrIndcnReRiSide_RLM_RS_BCM_01               13
#define FogLiErrStsReRiSide_RLM_RS_BCM_01               14
#define LilanguageSts_RLM_R_RLM_RS_BCM_01               15
#define TurnLiStsReRiSide_RLM_RS_BCM_01               16
#define TurnLiErrIndcnReRiSide_RLM_RS_BCM_01               17
#define TurnLiErrStsReRiSide_RLM_RS_BCM_01               18
#define RLM_R_ChrgSyncIndcn_RLM_RS_BCM_01               19
#define HCML2DTCGroup1_HcmlZcud_Lin2Fr01               20
#define HCML2DTCGroup2_HcmlZcud_Lin2Fr01               21
#define HCML2DTCGroup3_HcmlZcud_Lin2Fr01               22
#define HCML2DTCGroup4_HcmlZcud_Lin2Fr01               23
#define StsOfLedCornrgLampwithLINLe_HcmlZcud_Lin2Fr01               24
#define StsOfLedDaytiRunngLampWithLINLe_HcmlZcud_Lin2Fr01               25
#define StsOfLedFrntFogLampWithLINLe_HcmlZcud_Lin2Fr01               26
#define StsOfLedFrntPosnLampWithLINLe_HcmlZcud_Lin2Fr01               27
#define StsOfLedFrntTurnIndcrWithLINLe_HcmlZcud_Lin2Fr01               28
#define StsOfLedHiBeamWithLINLe_HcmlZcud_Lin2Fr01               29
#define StsOfLedLoBeamWithLINLe_HcmlZcud_Lin2Fr01               30
#define StsOfWelGbyFrntWithLINLe_HcmlZcud_Lin2Fr01               31
#define ErrRespHCML_HcmlZcud_Lin2Fr01               32

#define COM_RXSIGNAL_NUMBER 				69
#define PosnLiOnOffReLeMid_BCM_RLM_01             0
#define PosnLiOnOffReRiMid_BCM_RLM_01             1
#define PosnLiOnOffBrilvl_BCM_RLM_01             2
#define FogLiOnOffReLeMid_BCM_RLM_01             3
#define FogLiOnOffReRiMid_BCM_RLM_01             4
#define RvsLiOnOffLeMid_BCM_RLM_01             5
#define RvsLiOnOffRiMid_BCM_RLM_01             6
#define BrkLampOnOffLeMid_BCM_RLM_01             7
#define BrkLampOnOffRiMid_BCM_RLM_01             8
#define TurnSweepingEna_BCM_RLM_01             9
#define LiLanguageMod_BCM_RLM_01             10
#define ChrgSyncIndcnSts_BCM_RLM_01             11
#define PosnLiOnOffReLeSide_BCM_RLM_01             12
#define PosnLiOnOffReRiSide_BCM_RLM_01             13
#define FogLiOnOffFrntLe_BCM_RLM_01             14
#define FogLiOnOffFrntRi_BCM_RLM_01             15
#define FogLiOnOffReLeSide_BCM_RLM_01             16
#define FogLiOnOffReRiSide_BCM_RLM_01             17
#define RvsLiOnOffLeSide_BCM_RLM_01             18
#define RvsLiOnOffRiSide_BCM_RLM_01             19
#define BrkLampOnOffLeSide_BCM_RLM_01             20
#define BrkLampOnOffRiSide_BCM_RLM_01             21
#define TurnLiOnOffLe_BCM_RLM_01             22
#define TurnLiOnOffRi_BCM_RLM_01             23
#define BCMResponseErr_BCM_RLM_01             24
#define LiLanguageCtrl_1_BCM_RLM_02             25
#define LiLanguageCtrl_2_BCM_RLM_02             26
#define LiLanguageCtrl_3_BCM_RLM_02             27
#define LiLanguageCtrl_4_BCM_RLM_02             28
#define LiLanguageCtrl_5_BCM_RLM_02             29
#define LiLanguageCtrl_6_BCM_RLM_02             30
#define LiLanguageCtrl_7_BCM_RLM_02             31
#define LiLanguageCtrl_8_BCM_RLM_02             32
#define ActnOfAssistantLi_ZcudZcud_Lin2Fr01             33
#define ActnOfLedCornrgLampLe_ZcudZcud_Lin2Fr01             34
#define ActnOfLedCornrgLampRi_ZcudZcud_Lin2Fr01             35
#define ActnOfLedDaytiRunngLamp_ZcudZcud_Lin2Fr01             36
#define ActnOfLedFrntCrossLamp_ZcudZcud_Lin2Fr01             37
#define ActnOfLedFrntCrossLampDyn_ZcudZcud_Lin2Fr01             38
#define ActnOfLedFrntFogLamp_ZcudZcud_Lin2Fr01             39
#define ActnOfLedGrilleLamp_ZcudZcud_Lin2Fr01             40
#define ActnOfLedGrilleLampDyn_ZcudZcud_Lin2Fr01             41
#define ActnOfLedHiBeam_ZcudZcud_Lin2Fr01             42
#define ActnOfLedLeLogoLamp_ZcudZcud_Lin2Fr01             43
#define ActnOfLedLeLogoLampDyn_ZcudZcud_Lin2Fr01             44
#define ActnOfLedLoBeamActnOfLedLoBeam_ZcudZcud_Lin2Fr01             45
#define ActnOfLedLoBeamChks_ZcudZcud_Lin2Fr01             46
#define ActnOfLedLoBeamCntr_ZcudZcud_Lin2Fr01             47
#define ActnOfLedPosnLamp_ZcudZcud_Lin2Fr01             48
#define ActnOfLedPosnLampDyn_ZcudZcud_Lin2Fr01             49
#define ActnOfLedRiLogoLamp_ZcudZcud_Lin2Fr01             50
#define ActnOfLedRiLogoLampDyn_ZcudZcud_Lin2Fr01             51
#define ActvnOfApproach_ZcudZcud_Lin2Fr01             52
#define ActvnOfCarLoctr_ZcudZcud_Lin2Fr01             53
#define ActvnOfGoodByeLi_ZcudZcud_Lin2Fr01             54
#define ActvnOfIndcrIndcrOut_ZcudZcud_Lin2Fr01             55
#define ActvnOfIndcrIndcrOutChks_ZcudZcud_Lin2Fr01             56
#define ActvnOfIndcrIndcrOutCntr_ZcudZcud_Lin2Fr01             57
#define ActvnOfShowModLi_ZcudZcud_Lin2Fr01             58
#define ActvnOfWaitMode_ZcudZcud_Lin2Fr01             59
#define ActvnOfWelcomeLi_ZcudZcud_Lin2Fr01             60
#define IndcrNoSeq_ZcudZcud_Lin2Fr01             61
#define IndcrSts_ZcudZcud_Lin2Fr01             62
#define WelcomeGoodbyeModeReq_ZcudZcud_Lin2Fr01             63
#define ClrDTCOfLINHCML2_ZcudZcud_Lin2Fr02             64
#define ClrDTCOfLINHCMR2_ZcudZcud_Lin2Fr02             65
#define LvlgSwtSetReqChks_ZcudZcud_Lin2Fr02             66
#define LvlgSwtSetReqCntr_ZcudZcud_Lin2Fr02             67
#define LvlgSwtSetReqLvlgSwtSetReq_ZcudZcud_Lin2Fr02             68	

#define COM_GWSOURCESIGNAL_UPDATE_NUMBER 	0	
#define COM_ONEEVERYNFILTERSIGNAL_NUMBER 	0
#define COM_RXSIGNALMASKNEWDIFFERMASKOLD_NUMBER   0

#define COM_GWSIGNAL_BOOLBUFF_SIZE	0	
#define COM_GWSIGNAL_8BITBUFF_SIZE	0  
#define COM_GWSIGNAL_16BITBUFF_SIZE	0
#define COM_GWSIGNAL_32BITBUFF_SIZE	0
#define COM_GWSIGNAL_64BITBUFF_SIZE	0

#define COM_TXGROUPSIGNAL_NUMBER	0	

#define COM_RXGROUPSIGNAL_NUMBER 	0	

#define COM_GWMAPPING_NUMBER 		0	
#define COM_SOURCE_SIGNAL_NUMBER	0	
#define COM_DST_SIGNAL_NUMBER	0	
/*runtime state*/


#endif

