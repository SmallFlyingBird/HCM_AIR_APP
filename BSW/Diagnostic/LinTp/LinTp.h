/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2020)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : LinTp.h                                                     **
**                                                                            **
**  Created on  :                                                             **
**  Author      : HuRongbo                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*  <VERSION>    <DATE>       <AUTHOR>   <REVISION LOG>
 *  V1.0.0       2020-08-04   HuRongbo   R19_11 LinTp initial version.
 */

#ifndef LINTP_H
#define LINTP_H

#include "LinIf_Cfg.h"
#include "LinTp_Types.h"
#include "Lin_GeneralTypes.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/
#define LINTP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "LinIf_MemMap.h"

extern CONST(LinTp_ConfigType, LINIF_CONST) LinTp_PCConfig_L;
extern CONST(LinTp_ConfigType, LINIF_CONST) LinTp_PCConfig_R;
#define LINTP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "LinIf_MemMap.h"

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
#define LINTP_START_SEC_CODE
#include "LinIf_MemMap.h"
/******************************************************************************/
/*
 * Brief               Initializes the LIN Transport Layer.
 * ServiceId           0x40
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      ConfigPtr: Pointer to the LIN Transport Protocol
 *                                configuration
 * Param-Name[in/out]  None
 * Param-Name[out]     None
 * Return              None
 */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinTp_Init (
    P2CONST(LinTp_ConfigType, AUTOMATIC, LINIF_APPL_CONST) ConfigPtr
);

/******************************************************************************/
/*
 * Brief               Initializes the LIN Transport Layer after choose left or right
 * ServiceId           0x40
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      ConfigPtr: Pointer to the LIN Transport Protocol
 *                                configuration
 * Param-Name[in/out]  None
 * Param-Name[out]     None
 * Return              None
 */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinTp_Side_Init (void);


/******************************************************************************/
/*
 * Brief               Requests the transfer of segmented data.
 * ServiceId           0x41
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      LinTpTxSduId: This parameter contains the unique
 *                                   identifier of the N-SDU to be transmitted
 *                     LinTpTxInfoPtr: A pointer to a structure with N-SDU
 *                                     related data
 * Param-Name[in/out]  None
 * Param-Name[out]     None
 * Return              E_OK: The request can be started successfully
 *                     E_NOT_OK: The request can not be started
 */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE) LinTp_Transmit (
    PduIdType LinTpTxSduId,
    P2CONST(PduInfoType, AUTOMATIC, LINIF_APPL_CONST) LinTpTxInfoPtr
);

/******************************************************************************/
/*
 * Brief               Shutdowns the LIN TP
 * ServiceId           0x43
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[in/out]  None
 * Param-Name[out]     None
 * Return              None
 */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinTp_Shutdown(void);

#define LINTP_STOP_SEC_CODE
#include "LinIf_MemMap.h"

#endif /* LINTP_H */
