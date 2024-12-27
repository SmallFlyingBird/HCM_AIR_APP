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
**  FILENAME    : WdgM_Cfg.h                                                  **
**                                                                            **
**  Created on  : 2024/12/12 15:24:14                                         **
**  Author      : <>                                                          **
**  Vendor      :                                                             **
**  DESCRIPTION : Post-build configuration parameter of WdgM                  **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#ifndef WDGM_CFG_H_
#define WDGM_CFG_H_

#include "WdgM_Type.h"
#include "WdgIf_Cfg.h"		
	
#ifdef __cplusplus
extern "C" {
#endif 

#define  WDGM_SLEEP_MODE_ID 					0UL

#define	 WDGM_WATCHDOG_0							WdgIfExternalDevice_0

#define WDGM_FIRST_EXPIRED_SEID  				0x1ffffff8U
#define WDGM_FIRST_EXPIRED_INVERSE_SEID  		0x1ffffffcU

#define  WDGM_OFF_MODE_EABLED                   STD_ON
#define  WDGM_DEV_ERROR_DETECT                  STD_OFF
#define  WDGM_VERSION_INFO_API                  STD_OFF

/*WdgMImmediateReset may only be set to TRUE if the McuPerformResetApi (defined in SWS_Mcu_Driver) is set to TRUE*/
#define  WDGM_IMMEDIATE_RESET                   STD_OFF

#define  WDGM_E_SET_MODE_ENABLE      			STD_OFF
#define  WDGM_E_SUPERVISION_ENABLE       		STD_OFF


/*Supervision Mechanism quantity*/
#define WDGM_SE_NUM          					1U
#define WDGM_ALIVE_NUM       					1U
#define WDGM_DEADLINE_SUP_NUM   				1U
#define WDGM_INTLOG_SUP_NUM     				1U
#define WDGM_EXTLOG_SUP_NUM   					0U

extern const WdgM_SupervisedEntityIdType WdgM_SupervisedEntityToTabIndex[WDGM_SE_NUM];
extern const uint16 WdgM_CheckpointQuantityInSE[WDGM_SE_NUM];


#ifdef __cplusplus
}
#endif 

#endif 
