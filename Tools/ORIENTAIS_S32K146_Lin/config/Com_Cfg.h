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
**  Created on  :2024/12/16 14:21:13                                                           
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
#define COM_IPDUGROUP_NUMBER 				         2	
#define ComIPduGroup_HCML_Tx    0
#define ComIPduGroup_HCML_Rx    1	

#define COM_RXIPDU_NUMBER	2	
#define COM_RXPDU_Com_ZcudZcud_Lin2Fr01        0
#define COM_RXPDU_Com_ZcudZcud_Lin2Fr02        1
#define COM_TXIPDU_NUMBER	1	
#define COM_TXPDU_Com_HcmlZcud_Lin2Fr01        2
#define COM_RXIPDUBUFF_SIZE  14	
#define COM_TXIPDUBUFF_SIZE  7

#define COM_SIGNAL_BOOLBUFF_SIZE			28	
#define COM_RXGROUPSIGNAL_BOOLBUFF_SIZE		0	
#define COM_SIGNAL_BOOL_INVALID_SIZE		0	
#define COM_SIGNAL_BOOL_TIMEOUTID_SIZE      0

#define COM_SIGNAL_8BITBUFF_SIZE	    	21
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

#define COM_TXSIGNAL_NUMBER 				13	
#define HCML2DTCGroup1_HcmlZcud_Lin2Fr01               0
#define HCML2DTCGroup2_HcmlZcud_Lin2Fr01               1
#define HCML2DTCGroup3_HcmlZcud_Lin2Fr01               2
#define HCML2DTCGroup4_HcmlZcud_Lin2Fr01               3
#define StsOfLedCornrgLampwithLINLe_HcmlZcud_Lin2Fr01               4
#define StsOfLedDaytiRunngLampWithLINLe_HcmlZcud_Lin2Fr01               5
#define StsOfLedFrntFogLampWithLINLe_HcmlZcud_Lin2Fr01               6
#define StsOfLedFrntPosnLampWithLINLe_HcmlZcud_Lin2Fr01               7
#define StsOfLedFrntTurnIndcrWithLINLe_HcmlZcud_Lin2Fr01               8
#define StsOfLedHiBeamWithLINLe_HcmlZcud_Lin2Fr01               9
#define StsOfLedLoBeamWithLINLe_HcmlZcud_Lin2Fr01               10
#define StsOfWelGbyFrntWithLINLe_HcmlZcud_Lin2Fr01               11
#define ErrRespHCML_HcmlZcud_Lin2Fr01               12

#define COM_RXSIGNAL_NUMBER 				36
#define ActnOfAssistantLi_ZcudZcud_Lin2Fr01             0
#define ActnOfLedCornrgLampLe_ZcudZcud_Lin2Fr01             1
#define ActnOfLedCornrgLampRi_ZcudZcud_Lin2Fr01             2
#define ActnOfLedDaytiRunngLamp_ZcudZcud_Lin2Fr01             3
#define ActnOfLedFrntCrossLamp_ZcudZcud_Lin2Fr01             4
#define ActnOfLedFrntCrossLampDyn_ZcudZcud_Lin2Fr01             5
#define ActnOfLedFrntFogLamp_ZcudZcud_Lin2Fr01             6
#define ActnOfLedGrilleLamp_ZcudZcud_Lin2Fr01             7
#define ActnOfLedGrilleLampDyn_ZcudZcud_Lin2Fr01             8
#define ActnOfLedHiBeam_ZcudZcud_Lin2Fr01             9
#define ActnOfLedLeLogoLamp_ZcudZcud_Lin2Fr01             10
#define ActnOfLedLeLogoLampDyn_ZcudZcud_Lin2Fr01             11
#define ActnOfLedLoBeamActnOfLedLoBeam_ZcudZcud_Lin2Fr01             12
#define ActnOfLedLoBeamChks_ZcudZcud_Lin2Fr01             13
#define ActnOfLedLoBeamCntr_ZcudZcud_Lin2Fr01             14
#define ActnOfLedPosnLamp_ZcudZcud_Lin2Fr01             15
#define ActnOfLedPosnLampDyn_ZcudZcud_Lin2Fr01             16
#define ActnOfLedRiLogoLamp_ZcudZcud_Lin2Fr01             17
#define ActnOfLedRiLogoLampDyn_ZcudZcud_Lin2Fr01             18
#define ActvnOfApproach_ZcudZcud_Lin2Fr01             19
#define ActvnOfCarLoctr_ZcudZcud_Lin2Fr01             20
#define ActvnOfGoodByeLi_ZcudZcud_Lin2Fr01             21
#define ActvnOfIndcrIndcrOut_ZcudZcud_Lin2Fr01             22
#define ActvnOfIndcrIndcrOutChks_ZcudZcud_Lin2Fr01             23
#define ActvnOfIndcrIndcrOutCntr_ZcudZcud_Lin2Fr01             24
#define ActvnOfShowModLi_ZcudZcud_Lin2Fr01             25
#define ActvnOfWaitMode_ZcudZcud_Lin2Fr01             26
#define ActvnOfWelcomeLi_ZcudZcud_Lin2Fr01             27
#define IndcrNoSeq_ZcudZcud_Lin2Fr01             28
#define IndcrSts_ZcudZcud_Lin2Fr01             29
#define WelcomeGoodbyeModeReq_ZcudZcud_Lin2Fr01             30
#define ClrDTCOfLINHCML2_ZcudZcud_Lin2Fr02             31
#define ClrDTCOfLINHCMR2_ZcudZcud_Lin2Fr02             32
#define LvlgSwtSetReqChks_ZcudZcud_Lin2Fr02             33
#define LvlgSwtSetReqCntr_ZcudZcud_Lin2Fr02             34
#define LvlgSwtSetReqLvlgSwtSetReq_ZcudZcud_Lin2Fr02             35	

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

