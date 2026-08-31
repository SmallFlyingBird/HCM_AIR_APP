/**
 * @file    Lin_Mld.h
 * @version V2.3.0
 *
 * @brief   AUTOSAR Lin driver interface
 * @details API implementation for LIN driver
 *
 * @addtogroup LIN_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Lin
 *   Dependencies         : none
 *
 *   Autosar Version      : V4.4.0
 *   Autosar Revision     : ASR_REL_4_4_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           : V2.3.0
 *
 *
 *   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
 *   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef LIN_MLD_H
#define LIN_MLD_H

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section Lin_MLD_H_REF_1
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers.
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 *
 * @section Lin_MLD_H_REF_2
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers.
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 */


/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include "Lin_Types.h"

/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LIN_MLD_VENDOR_ID                      (180)
#define LIN_MLD_AR_RELEASE_MAJOR_VERSION       (4)
#define LIN_MLD_AR_RELEASE_MINOR_VERSION       (4)
#define LIN_MLD_AR_RELEASE_REVISION_VERSION    (0)
#define LIN_MLD_SW_MAJOR_VERSION               (2)
#define LIN_MLD_SW_MINOR_VERSION               (3)
#define LIN_MLD_SW_PATCH_VERSION               (0)
/* update, notion: the version 4.2.2 Change to 4.4.0 for build ,without check */

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and LIN configuration header file are of the same vendor */
#if (LIN_MLD_VENDOR_ID != LIN_VENDOR_ID_CFG)
#error "Lin_Mld.h and Lin_Cfg.h have different vendor ids"
#endif

/* Check if source file and LIN configuration header file are of the same Autosar version */
#if ((LIN_MLD_AR_RELEASE_MAJOR_VERSION != LIN_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (LIN_MLD_AR_RELEASE_MINOR_VERSION != LIN_AR_RELEASE_MINOR_VERSION_CFG) || \
     (LIN_MLD_AR_RELEASE_REVISION_VERSION != LIN_AR_RELEASE_REVISION_VERSION_CFG) \
    )
#error "AutoSar Version Numbers of Lin_Mld.h and Lin_Cfg.h are different"
#endif

/* Check if source file and LIN configuration header file are of the same software version */
#if ((LIN_MLD_SW_MAJOR_VERSION != LIN_SW_MAJOR_VERSION_CFG) || \
     (LIN_MLD_SW_MINOR_VERSION != LIN_SW_MINOR_VERSION_CFG) || \
     (LIN_MLD_SW_PATCH_VERSION != LIN_SW_PATCH_VERSION_CFG) \
    )
#error "Software Version Numbers of Lin_Mld.h and Lin_Cfg.h are different"
#endif


/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
 *                                       EXTERNAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                             ENUMS
==================================================================================================*/

/*==================================================================================================
 *                                      PUBLIC API FUNCTIONS
==================================================================================================*/

/**
 * @brief            Set the LIN Instance map pointer
 * @details          This function will set the LIN Instance map
 * @param[in]        LinInstMapPtr pointer to LIN Instance map
 * @return           void
 */
void Lin_Mld_SetInstMap(const uint8 * LinInstMapPtr);

/**
 * @brief            LIN channel hardware initialization
 * @details          This function will initialize the LIN hardware channel
 * @param[in]        Channel LIN channel to be initialized.
 * @param[in]        LinCfgPtr pointer to LIN channel configuration structure
 * @return           void
 */
void Lin_Mld_InitChannel(const uint8 Channel, const Lin_ConfigType * LinCfgPtr);

#if (LIN_DEINIT_API_SUPPORT == STD_ON)
/**
 * @brief            LIN channel hardware de-initialization
 * @details          This function will de-initialize the LIN hardware channel
 * @param[in]        Channel LIN channel to be de-initialized.
 * @return           void
 */
void Lin_Mld_DeInitChannel(const uint8 Channel);
#endif /* LIN_DEINIT_API_SUPPORT == STD_ON */

/**
 * @brief            Prepares and send wakeup command
 * @details          This function will send a wake up signal to LIN bus and put
 *                   LIN channel into LIN_DRV_CH_OPERATIONAL state.
 * @param[in]        Channel LIN channel.
 * @return           void.
 */
void Lin_Mld_Wakeup(const uint8 Channel);

/**
 * @brief            Wakeup LIN Channel
 * @details          This  and put LIN channel into LIN_DRV_CH_OPERATIONAL state.
 * @param[in]        Channel LIN channel.
 * @return           void.
 */
void Lin_Mld_WakeupInternal(const uint8 Channel);

/**
 * @brief            Check out wakeup status
 * @details          This function will check if LIN channel is wakeup
 * @param[in]        Channel LIN channel.
 * @return           boolean.
 * @retval TRUE      LIN channel is wake up
 * @retval FALSE     LIN channel is not wake up
 */
boolean Lin_Mld_CheckWakeup(const uint8 Channel);

/**
 * @brief            Prepares and send go to sleep command
 * @details          This function will stop any ongoing transmission and put channel in sleep mode.
 * @param[in]        Channel LIN channel.
 * @return           Std_ReturnType.
 * @retval E_OK      gotosleep OK
 * @retval E_NOT_OK  gotosleep not OK
 */
Std_ReturnType Lin_Mld_GoToSleepInternal(const uint8 Channel);

#if (LIN_MASTER_API_SUPPORT == STD_ON)
/**
 * @brief            Prepares and send go to sleep command
 * @details          This function will stop any ongoing transmission and start to send go to sleep
 *                   command with frame ID = 0x3C, data = (0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF).
 * @param[in]        Channel LIN channel.
 * @return           Std_ReturnType.
 * @retval E_OK      gotosleep frame transmission OK
 * @retval E_NOT_OK  gotosleep frame transmission not OK
 */
Std_ReturnType Lin_Mld_GoToSleep(const uint8 Channel);

/**
 * @brief            LIN channel hardware send header
 * @details          This function will start a header transmission.
 *                   LIN frame data stored in PduInfoPtr pointer.
 *                   Header will only transmitted in master mode, if reponse type is LIN_FRAMERESPONSE_TX,
 *                   LIN frame data will be transmitted with Lin_Mld_SendResponse.
 * @param[in]        Channel LIN channel to be initialized.
 * @param[in]        PduInfoPtr point to PDU structure containing PID, checksum, response type,
 *                              data length and SDU data pointer.
 * @return           Std_ReturnType.
 * @retval E_OK      transmission OK
 * @retval E_NOT_OK  transmission timeout
 */
Std_ReturnType Lin_Mld_SendHeader(const uint8 Channel, const Lin_PduType* PduInfoPtr);

/**
 * @brief            LIN channel hardware send response
 * @details          This function will transmission the data part of LIN frame
 * @param[in]        Channel LIN channel.
 * @param[in]        PduInfoPtr point to PDU structure containing PID, checksum, response type,
 *                              data length and SDU data pointer.
 * @return           void.
 */
void Lin_Mld_SendResponse(const uint8 Channel, const Lin_PduType* PduInfoPtr);

/**
 * @brief            Gets the status of the LIN driver when Channel is operating.
 * @details          This function returns the state of the current transmission, reception or
 *                   operation status.
 *                   If the reception of a Slave response was successful then this service provides
 *                   a pointer to the buffer where the data is stored.
 * @param[in]        Channel LIN channel to be addressed
 * @param[out]       LinSduPtr Pointer to point a shadow SDU stored buffer or memory mapped LIN
 *                      hardware receive buffer
 * @return           Lin_StatusType
 * @retval LIN_NOT_OK           Development or production error occurred.
 * @retval LIN_TX_OK            Successful transmission.
 * @retval LIN_TX_BUSY          Ongoing transmission (Header or Response).
 * @retval LIN_TX_HEADER_ERROR  Error happens on header transmission.
 * @retval LIN_TX_ERROR         Error happens on transmission.
 * @retval LIN_RX_OK            Reception of correct response.
 * @retval LIN_RX_BUSY          Ongoing reception.
 * @retval LIN_RX_ERROR         Error happens on reception.
 * @retval LIN_RX_NO_RESPONSE   No response byte has been received so far.
 * @retval LIN_OPERATIONAL      Normal operation.
 * @retval LIN_CH_SLEEP         Sleep mode operation.
 */
Lin_StatusType Lin_Mld_HardwareGetStatus(const uint8 Channel, uint8 * LinSduPtr);
#endif /* LIN_MASTER_API_SUPPORT == STD_ON */

#ifdef __cplusplus
}
#endif

#endif /* LIN_MLD_H */

/** @} */

