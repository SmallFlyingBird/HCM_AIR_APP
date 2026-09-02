/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2017)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : LinIf_Cbk.h                                                 **
**                                                                            **
**  Created on  :                                                             **
**  Author      : HuRongbo                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Callback declaration supplied by LinSM                      **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/


#ifndef LINIF_CBK_H
#define LINIF_CBK_H

#include "LinIf_Cfg.h"
#include "Lin_GeneralTypes.h"
#include "ComStack_Types.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
#if (LINIF_WAKEUP_SUPPORT == STD_ON)
#define LINIF_START_SEC_LINIFWAKEUPCONFIRMATION_CALLBACK_CODE
#include "LinIf_MemMap.h"
/******************************************************************************/
/*
 * Brief               The LIN Driver or LIN Transceiver Driver will call this
 *                     function to report the wake up source after the
 *                     successful wakeup detection during CheckWakeup or after
 *                     power on by bus.
 * ServiceId           0x61
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      WakeupSource: Source device, which initiated the wakeup
 *                                   event: LIN controller or LIN transceiver.
 * Param-Name[in/out]  None
 * Param-Name[out]     None
 * Return              None
 */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_WakeupConfirmation
(
    EcuM_WakeupSourceType WakeupSource
);
#define LINIF_STOP_SEC_LINIFWAKEUPCONFIRMATION_CALLBACK_CODE
#include "LinIf_MemMap.h"
#endif /* #if (LINIF_WAKEUP_SUPPORT == STD_ON) */

#define LINIF_START_SEC_LINIFHEADERINDICATION_CALLBACK_CODE
#include "LinIf_MemMap.h"
/******************************************************************************/
/*
 * Brief               The LIN Driver will call this function to report a
 *                     received LIN header. This function is only applicable for
 *                     LIN slave nodes
 * ServiceId           0x78
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different Channels.
 * Param-Name[in]      Channel: Identification of the LIN channel.
 *                     Nad: Configured NAD to set as new slave NAD.
 * Param-Name[in/out]  PduPtr: Pointer to PDU providing the received PID and
 *                     pointer to the SDU data buffer as in parameter. Upon
 *                     return, the length, checksum type and frame response type
 *                     are received as out parameter. If the frame response type
 *                     is LIN_FRAMERESPONSE_TX, then the SDU data buffer
 *                     contains the transmission data.
 * Param-Name[out]     None
 * Return              E_OK: Request has been accepted.
 *                     E_NOT_OK: Request has not been accepted, development or
 *                               production error occurred.
 */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE) LinIf_HeaderIndication(
    NetworkHandleType Channel,
    P2VAR(Lin_PduType, AUTOMATIC, LINIF_APPL_DATA) PduPtr
);
#define LINIF_STOP_SEC_LINIFHEADERINDICATION_CALLBACK_CODE
#include "LinIf_MemMap.h"

#define LINIF_START_SEC_LINIFRXINDICATION_CALLBACK_CODE
#include "LinIf_MemMap.h"
/******************************************************************************/
/*
 * Brief               The LIN Driver will call this function to report a
 *                     successfully received response and provides the reception
 *                     data to the LIN Interface. This function is only
 *                     applicable for LIN slave nodes.
 * ServiceId           0x79
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different Channels.
 * Param-Name[in]      Channel: Identification of the LIN channel.
 *                     Lin_SduPtr: pointer to a shadow buffer or memory mapped
 *                     LIN Hardware receive buffer where the current SDU is
 *                     stored. This pointer is only valid if the response is
 *                     received.
 * Param-Name[in/out]  None
 * Param-Name[out]     None
 * Return              None
 */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_RxIndication(
    NetworkHandleType Channel,
    P2VAR(uint8, AUTOMATIC, LINIF_APPL_DATA) Lin_SduPtr
);
#define LINIF_STOP_SEC_LINIFRXINDICATION_CALLBACK_CODE
#include "LinIf_MemMap.h"

#define LINIF_START_SEC_LINIFTXCONFIRMATION_CALLBACK_CODE
#include "LinIf_MemMap.h"
/******************************************************************************/
/*
 * Brief               The LIN Driver will call this function to report a
 *                     successfully transmitted response.
 *                     This function is only applicable for LIN slave nodes.
 * ServiceId           0x7a
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different Channels.
 * Param-Name[in]      Channel: Identification of the LIN channel.
 * Param-Name[in/out]  None
 * Param-Name[out]     None
 * Return              None
 */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_TxConfirmation(
    NetworkHandleType Channel
);
#define LINIF_STOP_SEC_LINIFTXCONFIRMATION_CALLBACK_CODE
#include "LinIf_MemMap.h"

#define LINIF_START_SEC_LINIFLINERRORINDICATION_CALLBACK_CODE
#include "LinIf_MemMap.h"
/******************************************************************************/
/*
 * Brief               The LIN Driver will call this function to report a
 *                     detected error event during header or response processing
 *                     This function is only applicable for LIN slave nodes
 * ServiceId           0x7b
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different Channels.
 * Param-Name[in]      Channel: Identification of the LIN channel.
 *                     ErrorStatus: Type of detected error.
 * Param-Name[in/out]  None
 * Param-Name[out]     None
 * Return              None
 */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_LinErrorIndication(
    NetworkHandleType Channel,
    Lin_SlaveErrorType ErrorStatus
);
#define LINIF_STOP_SEC_LINIFLINERRORINDICATION_CALLBACK_CODE
#include "LinIf_MemMap.h"

#endif /* LINIF_CBK_H */
