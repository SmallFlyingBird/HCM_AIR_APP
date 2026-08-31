/**
 * @file    Lin.h
 * @version V2.3.0
 *
 * @brief   AUTOSAR Lin module interface
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

#ifndef LIN_H
#define LIN_H

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section Lin_PBCfg_C_REF_1
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers.
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 *
 * @section Lin_PBCfg_C_REF_2
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers.
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 */


/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Lin_Types.h"

/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LIN_VENDOR_ID                      (180)
#define LIN_AR_RELEASE_MAJOR_VERSION       (4)
#define LIN_AR_RELEASE_MINOR_VERSION       (4)
#define LIN_AR_RELEASE_REVISION_VERSION    (0)
#define LIN_SW_MAJOR_VERSION               (2)
#define LIN_SW_MINOR_VERSION               (3)
#define LIN_SW_PATCH_VERSION               (0)
/* update, notion: the version 4.2.2 Change to 4.4.0 for build ,without check */

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and LIN configuration header file are of the same vendor */
#if (LIN_VENDOR_ID != LIN_VENDOR_ID_CFG)
#error "Lin.h and Lin_Cfg.h have different vendor ids"
#endif

/* Check if source file and LIN configuration header file are of the same Autosar version */
#if ((LIN_AR_RELEASE_MAJOR_VERSION != LIN_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (LIN_AR_RELEASE_MINOR_VERSION != LIN_AR_RELEASE_MINOR_VERSION_CFG) || \
     (LIN_AR_RELEASE_REVISION_VERSION != LIN_AR_RELEASE_REVISION_VERSION_CFG) \
    )
#error "AutoSar Version Numbers of Lin.h and Lin_Cfg.h are different"
#endif

/* Check if source file and LIN configuration header file are of the same software version */
#if ((LIN_SW_MAJOR_VERSION != LIN_SW_MAJOR_VERSION_CFG) || \
     (LIN_SW_MINOR_VERSION != LIN_SW_MINOR_VERSION_CFG) || \
     (LIN_SW_PATCH_VERSION != LIN_SW_PATCH_VERSION_CFG) \
    )
#error "Software Version Numbers of Lin.h and Lin_Cfg.h are different"
#endif

/*==================================================================================================
 *                                             APIS
==================================================================================================*/
/**
 * @brief            This function checks if a wakeup has occurred on the addressed LIN channel.
 * @details          This function identifies if the addressed LIN channel
 *                   has been woken up by the LIN bus transceiver. It checks
 *                   the wake up flag from the addressed LIN channel which
 *                   must be in sleep mode and have the wake up signal.
 * @param[in]        Channel LIN channel to be addressed
 * @return           Std_ReturnType
 * @retval E_NOT_OK  If the LIN Channel is not valid or
 *                   LIN driver is not initialized or
 *                   the addressed LIN Channel is not
 *                   in sleep state.
 * @retval E_OK      LIN Channel is in sleep mode
 */
Std_ReturnType Lin_CheckWakeup (uint8 Channel);

#if (LIN_MASTER_API_SUPPORT == STD_ON)
/**
 * @brief            Sends a LIN header and a LIN response, if necessary.
 * @details          The direction of the frame response (master response, slave response,
 *                   slave-to-slave communication) is provided by the PduInfoPtr.
 * @param[in]        Channel LIN channel to be addressed
 * @param[in]        PduInfoPtr Pointer to PDU containing the PID, checksum model,
 *                               response type, Dl and SDU data pointer
 * @return           Std_ReturnType
 * @retval           E_OK LIN header and response were sent successfully
 * @retval           E_NOT_OK LIN header and response were not sent successfully
 */
Std_ReturnType Lin_SendFrame (uint8 Channel, const Lin_PduType * PduInfoPtr);

/**
 * @brief            Gets the status of the LIN driver.
 * @param[in]        Channel LIN channel to be checked
 * @param[out]       Lin_SduPtr Pointer to pointer to a shadow buffer or memory mapped LIN Hardware
 *                          receive buffer where the current SDU is stored.
 *
 * @return           Lin_StatusType
 *
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
Lin_StatusType Lin_GetStatus (uint8 Channel, uint8 ** Lin_SduPtr);

/**
 * @brief            The service instructs the driver to transmit a go-to-sleep-command on the addressed LIN channel.
 * @param[in]        Channel LIN channel to be addressed
 * @return           Std_ReturnType
 * @retval E_OK      Sleep command has been accepted
 * @retval E_NOT_OK: Sleep command has not been accepted, development or production error occurred
 */
Std_ReturnType Lin_GoToSleep (uint8 Channel);
#endif /* LIN_MASTER_API_SUPPORT == STD_ON */

/**
 * @brief            Sets the channel state to LIN_CH_SLEEP, enables the wake-up detection
 *                   and optionally sets the LIN hardware unit to reduced power operation
 *                   mode (if supported by HW).
 * @param[in]        Channel LIN channel to be addressed
 * @return           Std_ReturnType
 * @retval           E_OK      Command has been accepted
 * @retval           E_NOT_OK  Command has not been accepted, development or production error occurred
 */
Std_ReturnType Lin_GoToSleepInternal (uint8 Channel);

/**
 * @brief            Initializes the LIN module.
 * @param[in]        Config Pointer to LIN driver configuration set.
 * @return           void
 */
void Lin_Init (const Lin_ConfigType * Config);

#if (LIN_DEINIT_API_SUPPORT == STD_ON)
/**
 * @brief            DeInitializes the LIN module.
 * @return           void
 */
void Lin_DeInit (void);
#endif /* LIN_DEINIT_API_SUPPORT == STD_ON */

/**
 * @brief            Generates a wake up pulse and sets the channel state to LIN_DRV_CH_OPERATIONAL.
 * @param[in]        Channel LIN channel to be addressed
 * @return           Std_ReturnType
 * @retval           E_OK      Command has been accepted
 * @retval           E_NOT_OK  Command has not been accepted, development or production error occurred
 */
Std_ReturnType Lin_Wakeup (uint8 Channel);

/**
 * @brief            Sets the channel state to LIN_DRV_CH_OPERATIONAL without generating a wake up pulse.
 * @param[in]        Channel LIN channel to be addressed
 * @return           Std_ReturnType
 * @retval E_OK      Wake-up request has been accepted
 * @retval E_NOT_OK  Wake-up request has not been accepted
 */
Std_ReturnType Lin_WakeupInternal (uint8 Channel);

#if (((LIN_VERSION_INFO_API == STD_ON) && (LIN_DEV_ERROR_DETECT == STD_ON)))
/**
 * @brief            Returns the version information of this module.
 * @param[out]       versioninfo Pointer to where is stored the version information of this module.
 * @return           void
 */
#define Lin_GetVersionInfo(versioninfo)                                    \
    {                                                                         \
        /* Check for DET: LIN_E_PARAM_POINTER */                              \
        if ((versioninfo) == NULL_PTR)                                        \
        {                                                                     \
            /* Report LIN_E_PARAM_POINTER DET if service called with          \
               NULL_PTR                                                       \
            */                                                                \
            Det_ReportError(                                                  \
                (uint16)LIN_MODULE_ID,                                        \
                LIN_INSTANCE_ID,                                              \
                LIN_SID_GET_VERSION_INFO,                                     \
                LIN_E_PARAM_POINTER);                                         \
        }                                                                     \
        else                                                                  \
        {                                                                     \
            /* Vendor ID information */                                       \
            ((Std_VersionInfoType *)(versioninfo))->vendorID = LIN_VENDOR_ID; \
            /* Lin module ID information */                                   \
            ((Std_VersionInfoType *)(versioninfo))->moduleID = LIN_MODULE_ID; \
            /* Lin module Software major version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_major_version =        \
                (uint8)LIN_SW_MAJOR_VERSION;                                      \
            /* Lin module Software minor version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_minor_version =        \
                (uint8)LIN_SW_MINOR_VERSION;                                      \
            /* Lin module Software patch version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_patch_version =        \
                (uint8)LIN_SW_PATCH_VERSION;                                      \
        }                                                                     \
    }
#elif (((LIN_VERSION_INFO_API == STD_ON) && (LIN_DEV_ERROR_DETECT == STD_OFF)))
#define Lin_GetVersionInfo(versioninfo)                                       \
    {                                                                         \
        /* Vendor ID information */                                           \
        ((Std_VersionInfoType *)(versioninfo))->vendorID = LIN_VENDOR_ID;     \
        /* Lin module ID information */                                       \
        ((Std_VersionInfoType *)(versioninfo))->moduleID = LIN_MODULE_ID;     \
        /* Lin module Software major version information */                   \
        ((Std_VersionInfoType *)(versioninfo))->sw_major_version =            \
            (uint8)LIN_SW_MAJOR_VERSION;                                          \
        /* Lin module Software minor version information */                   \
        ((Std_VersionInfoType *)(versioninfo))->sw_minor_version =            \
            (uint8)LIN_SW_MINOR_VERSION;                                          \
        /* Lin module Software patch version information */                   \
        ((Std_VersionInfoType *)(versioninfo))->sw_patch_version =            \
            (uint8)LIN_SW_PATCH_VERSION;                                          \
    }
#endif /* LIN_VERSION_INFO_API == STD_ON && LIN_DEV_ERROR_DETECT == STD_ON */

#ifdef __cplusplus
}
#endif

#endif /* LIN_H */

/** @} */

