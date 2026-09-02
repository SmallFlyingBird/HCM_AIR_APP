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
**  FILENAME    : LinIf_Slave.h                                               **
**                                                                            **
**  Created on  :                                                             **
**  Author      : HuRongbo                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
#ifndef LINIF_SLAVE_H
#define LINIF_SLAVE_H

#include "LinIf.h"
#include "LinIf_Internal.h"

#if (STD_ON == LINIF_SLAVE_SUPPORT)
/*******************************************************************************
**                      Macros Definitions                                    **
*******************************************************************************/

/*******************************************************************************
**                      Runtime Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
#define LINIF_START_SEC_CODE
#include "LinIf_MemMap.h"
/******************************************************************************/
/*
 * Brief               Initializes the LinIf slave channel.
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void,LINIF_CODE) LinIf_SlaveInit( void );

/******************************************************************************/
/*
 * Brief               Wakeup process in slave channel.
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ch: LinIf Channel
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(Std_ReturnType,LINIF_CODE) LinIf_SlaveWakeUp(
    NetworkHandleType ch
);

/******************************************************************************/
/*
 * Brief: Wakeup confirmation process in slave node
 * Param-Name[in]: ch
 * Param-Name[out]: None
 * Param-Name[in/out]: None
 * Return: None
 * PreCondition: None
 * CallByAPI: This is a internal function
 */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_SlaveWakeupConfirmation(
    EcuM_WakeupSourceType WakeupSource
);

/******************************************************************************/
/*
 * Brief               Header receive process in slave node.
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ch: LinIf Channel
 * Param-Name[out]     Nad: Configured NAD of slave.
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(Std_ReturnType,LINIF_CODE) LinIf_SlaveHeaderIndication(
    NetworkHandleType ch,
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) PduPtr
);

/******************************************************************************/
/*
 * Brief               Receive indication process in slave node.
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ch: LinIf Channel
 *                     Lin_SduPtr: pointer to a buffer where the current SDU is
 *                                 stored.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void,LINIF_CODE) LinIf_SlaveRxIndication(
    NetworkHandleType ch,
    P2VAR(uint8, AUTOMATIC, LINIF_APPL_DATA) Lin_SduPtr
);

/******************************************************************************/
/*
 * Brief               Tx confirmation process in slave node.
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ch: LinIf Channel
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void,LINIF_CODE) LinIf_SlaveTxConfirmation(
    NetworkHandleType ch
);

/******************************************************************************/
/*
 * Brief               Lin error indication process in slave node.
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ch: LinIf Channel.
 *                     ErrorStatus: Type of detected error.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void,LINIF_CODE) LinIf_SlaveLinErrorIndication(
    NetworkHandleType ch,
    Lin_SlaveErrorType ErrorStatus
);

/******************************************************************************/
/*
 * Brief               Go-to-sleep process in slave node.
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ch: LinIf Channel
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_SlaveGotoSleep(
    NetworkHandleType ch
);

/******************************************************************************/
/*
 * Brief               Main function of slave node.
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ch: LinIf channel
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_SlaveMainFunction(
    NetworkHandleType ch
);

#define LINIF_STOP_SEC_CODE
#include "LinIf_MemMap.h"

#endif /* #if (STD_ON == LINIF_SLAVE_SUPPORT) */

#endif /* LINIF_SLAVE_H */
