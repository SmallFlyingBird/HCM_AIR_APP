
/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2022)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : CanNm_Cfg.h                                                 **
**                                                                            **
**  Created on  : 2024/10/09 16:58:59                                         **
**  Author      : Wanglili                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
#ifndef CANNM_CFG_H_
#define CANNM_CFG_H_

/******************************************************************************
**                      Includes                                             **
******************************************************************************/
#include "Std_Types.h"
/******************************************************************************
**                      Global Symbols                                       **
******************************************************************************/

/* Pre-processor switch for enabling support of the Passive Mode. */
/* dependency: calculationFormula = Equal(NM_PASSIVE_MODE_ENABLED) */
#define CANNM_PASSIVE_MODE_ENABLED                       STD_OFF

/* Enables or disables support of partial networking.*/
#define CANNM_GLOBAL_PN_SUPPORT                                     STD_ON

/* Enables or disables support of CarWakeUp bit evaluation in received NM
PDUs. */
#define CANNM_CAR_WAKEUP_RX_ENABLED                          STD_OFF

/* If CWU filtering is supported, only the CWU bit within the NM PDU with
source node identifier CanNmCarWakeUpFilterNodeId is considered as
CWU request */
/* dependency: only available if CANNM_CAR_WAKEUP_RX_ENABLED == TRUE */

#define CANNM_CAR_WAKEUP_FILTER_ENABLED                        STD_OFF

/* normal config */

/* Pre-processor switch for enabling the asynchronous transmission of a NM
PDU upon bus-communication request in Prepare-Bus-Sleep mode. */
/* dependency: Must not be defined if CANNM_PASSIVE_MODE_ENABLED is defined. */
#define CANNM_IMMEDIATE_RESTART_ENABLED                         STD_OFF

/* this macro will be check every channel,if least one channel need,
this is been config */
#define CANNM_IMMEDIATE_TRANSMIT_ENABLED                        STD_ON

/* normal config */

/* Pre-processor switch for enabling busload reduction support. */
/* dependency: CANNM_BUSLOAD_REDUCTION_ENABLED = false if
CANNM_PASSIVE_MODE_ENABLED ==
true or CANNM_GLOBAL_PN_SUPPORT == true for at least one CanNm Channel. */
#define CANNM_BUSLOAD_REDUCTION_ENABLED                         STD_OFF

/* Pre-processor switch for enabling bus synchronization support. This
feature is required for gateway nodes only. */
/* dependency: calculationFormula = If (CANNM_PASSIVE_MODE_ENABLED ==
False) then Equal(NM_BUS_SYNCHRONIZATION_ENABLED) else Equal(False) */
#define CANNM_BUS_SYNCHRONIZATION_ENABLED                         STD_OFF

/* Pre-processor switch for enabling the Communication Control support */
/* dependency: calculationformula = Equal(NM_COM_CONTROL_ENABLED) */
#define CANNM_COM_CONTROL_ENABLED                                 STD_ON

/* Preprocessor switch for enabling Com User Data. */
/* dependency: If CANNM_PASSIVE_MODE_ENABLED == True then
CANNM_COM_USERDATA_SUPPORT = False */
#define CANNM_COM_USERDATA_SUPPORT                                STD_ON

/* Enables/disables the coordinator synchronisation support. */
/* dependency: CANNM_COORDINATOR_SYNC_SUPPORT has to be set to FALSE if
CANNM_PASSIVE_MODE_ENABLED is set to TRUE. */
#define CANNM_COORDINATOR_SYNC_SUPPORT                            STD_OFF

/* Switches the Default Error Tracer (Det) detection and notification ON or
OFF. */
#define CANNM_DEV_ERROR_DETECT                                    STD_ON

/* Enable/disable the immediate tx confirmation. */
/* dependency: CANNM_IMMEDIATE_TXCONF_ENABLED shall not be enabled if
CanNmPasiveModeEnabled is enabled */
#define CANNM_IMMEDIATE_TXCONF_ENABLED                             STD_OFF

/* Pre-processor switch for enabling the source node identifier. */
/* calculationFormula = Equal(NM_NODE_ID_ENABLED) */                                          

#define CANNM_NODE_ID_ENABLED                                      STD_ON

/* Precompile time switch to enable the node detection feature. */
/* dependency: Only valid if CANNM_NODE_ID_ENABLED is set to TRUE
If CANNM_PASSIVE_MODE_ENABLED == True then CanNmNodeDetection = False */
#define CANNM_NODE_DETECTION_ENABLED                               STD_ON

/* Pre-processor switch for enabling the PDU Rx Indication. */
/* calculationFormula = Equal(NM_PDU_RX_INDICATION_ENABLED) */
#define CANNM_PDU_RX_INDICATION_ENABLED                             STD_ON

/* Specifies if CanNm calculates the PN request information for internal an
external requests. (EIRA)
true: PN request are calculated false: PN request are not calculated */
/* dependency: only available if CANNM_GLOBAL_PN_SUPPORT == true for at least one
CanNm Channel */
#define CANNM_PN_EIRA_CALC_ENABLED                                  STD_ON

/* Specifies if CanNm calculates the PN request information for external
    requests. (ERA) */
/* dependency: only available if CANNM_GLOBAL_PN_SUPPORT == true */
#define CANNM_PN_ERA_CALC_ENABLED                                   STD_ON

/* Pre-processor switch for enabling remote sleep indication support. This
feature is required for gateway nodes only. */
/* dependency: calculationFormula = If (CANNM_PASSIVE_MODE_ENABLED ==
False) then Equal(NM_REMOTE_SLEEP_IND_ENABLED) else Equal(False) */
#define CANNM_REMOTE_SLEEP_IND_ENABLED                               STD_OFF

/* Enable/disable the notification that a RepeatMessageRequest bit has been
received */
/* dependency: calculationformula = Equal(NM_REPEAT_MSG_IND_ENABLED) */
#define CANNM_REPEAT_MSG_IND_ENABLED                                  STD_OFF

/* Pre-processor switch for enabling the CAN NM state change notification. */
/* dependency: calculationFormula = Equal(NmStateChangeIdEnabled) */
#define CANNM_STATE_CHANGE_IND_ENABLED                                STD_ON

/* Pre-processor switch for enabling user data support. */
/* dependency: calculationFormula = Equal(NM_USER_DATA_ENABLED) */
#define CANNM_USER_DATA_ENABLED                                        STD_ON

/* Pre-processor switch for enabling version info API support. */
#define CANNM_VERSION_INFO_API                                         STD_OFF

/* add other configer */
/* support Channel number */
#define CANNM_NUMBER_OF_CHANNEL                                         0x1u
#define CANNM_CHANNEL_0                                                 0x0u

/* max CanNmPnInfoLength */
#define CANNM_PN_INFO_LENGTH                                            0x6u

#define CANNM_PNEIRARXNSDU       0u

#define BODYEXPOSEDCANNMCLUSTER_CANNMERARXPDU_BODYEXPOSEDCAN_HCML            0u

/*symbols generated for RXPDU*/
#define CANNM_RX_PDU_NUMBER_MAX                                         1u
#define CANNM_RX_PDU_0                                                  0u

/*symbols generated for TXPDU*/
#define CANNM_TX_PDU_NUMBER_MAX                                        1u
#define CANNM_TX_PDU_0                                                  0u

#define CANNM_USER_DATA_TX_PDU_MAX                                      1u
#define CANNM_USER_TX_PDU_0                    0u

/*PN number,equal number of PnFilterMaskByteValue bit is 1*/
#define CANNM_PN_NUM                              8u

#endif /* CANNM_CFG_H_ */

