/**
 * @file    LinIf.h
 * @version 
 *
 * @brief   AUTOSAR LinIf module interface
 * @details API implementation for LINIF driver
 *
 * @addtogroup LINIF_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : LinIf
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

#ifndef LINIF_H
#define LINIF_H

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section LinIf_PBCfg_C_REF_1
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers. 
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 *
 * @section LinIf_PBCfg_C_REF_2
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers. 
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 */


/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include "Std_Types.h"
#include "ComStack_Types.h"
#include "Lin_GeneralTypes.h"
#include "EcuM.h"
#include "LinIf_Types.h"
#include "LinIf_Cfg.h"

/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LINIF_VENDOR_ID                      (0xB4)
#define LINIF_AR_RELEASE_MAJOR_VERSION       (4)
#define LINIF_AR_RELEASE_MINOR_VERSION       (4)
#define LINIF_AR_RELEASE_REVISION_VERSION    (0)
#define LINIF_SW_MAJOR_VERSION               (2)
#define LINIF_SW_MINOR_VERSION               (3)
#define LINIF_SW_PATCH_VERSION               (0)
/* update, notion: the version 4.2.2 Change to 4.4.0 for build ,without check */

/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief LINIF MODULE INSTANCE ID */
#define LINIF_INSTANCE_ID ((uint8)0U)

/** @brief LINIF MODULE ID */
#define LINIF_MODULE_ID ((uint8)Lookup from Doc U)

#if (LINIF_DEV_ERROR_DETECT == STD_ON)
/**
 * @defgroup        LinIf_DEV_ERROR
 * @brief           LINIF development errors
 * @{
 */

/** @brief LINIF API service is called using an invalid pointer (e.g. the pointer should not be NULL).  */
#define LINIF_E_PARAM_POINTER ((uint8)Lookup from Doc U)

Error list ....
/** @} */
#endif

/**
 * @defgroup        LinIf_SID
 * @brief           Service ID number for all LINIF driver services
 */
/** @{ */
/** @brief API Service ID for LinIf_CheckWakeup */
#define LIN_IF_CHECK_WAKEUP                              (0x60U)
/** @brief API Service ID for LinIf_EnableBusMirroring */
#define LIN_IF_ENABLE_BUS_MIRRORING                      (0x7fU)
/** @brief API Service ID for LinIf_GetConfiguredNAD */
#define LIN_IF_GET_CONFIGURED_NA_D                       (0x70U)
/** @brief API Service ID for LinIf_GetPIDTable */
#define LIN_IF_GET_PI_DTABLE                             (0x72U)
/** @brief API Service ID for LinIf_GetTrcvMode */
#define LIN_IF_GET_TRCV_MODE                             (0x09U)
/** @brief API Service ID for LinIf_GetTrcvWakeupReason */
#define LIN_IF_GET_TRCV_WAKEUP_REASON                    (0x0aU)
/** @brief API Service ID for LinIf_GetVersionInfo */
#define LIN_IF_GET_VERSION_INFO                          (0x03U)
/** @brief API Service ID for LinIf_GotoSleep */
#define LIN_IF_GOTO_SLEEP                                (0x06U)
/** @brief API Service ID for LinIf_HeaderIndication */
#define LIN_IF_HEADER_INDICATION                         (0x78U)
/** @brief API Service ID for LinIf_Init */
#define LIN_IF_INIT                                      (0x01U)
/** @brief API Service ID for LinIf_LinErrorIndication */
#define LIN_IF_LIN_ERROR_INDICATION                      (0x7bU)
/** @brief API Service ID for LinIf_RxIndication */
#define LIN_IF_RX_INDICATION                             (0x79U)
/** @brief API Service ID for LinIf_ScheduleRequest */
#define LIN_IF_SCHEDULE_REQUEST                          (0x05U)
/** @brief API Service ID for LinIf_SetConfiguredNAD */
#define LIN_IF_SET_CONFIGURED_NA_D                       (0x71U)
/** @brief API Service ID for LinIf_SetPIDTable */
#define LIN_IF_SET_PI_DTABLE                             (0x73U)
/** @brief API Service ID for LinIf_SetTrcvMode */
#define LIN_IF_SET_TRCV_MODE                             (0x08U)
/** @brief API Service ID for LinIf_SetTrcvWakeupMode */
#define LIN_IF_SET_TRCV_WAKEUP_MODE                      (0x0bU)
/** @brief API Service ID for LinIf_Transmit */
#define LIN_IF_TRANSMIT                                  (0x49U)
/** @brief API Service ID for LinIf_TxConfirmation */
#define LIN_IF_TX_CONFIRMATION                           (0x7aU)
/** @brief API Service ID for LinIf_Wakeup */
#define LIN_IF_WAKEUP                                    (0x07U)
/** @brief API Service ID for LinIf_WakeupConfirmation */
#define LIN_IF_WAKEUP_CONFIRMATION                       (0x61U)
/** @brief API Service ID for LinTp_ChangeParameter */
#define LIN_TP_CHANGE_PARAMETER                          (0x4bU)
/** @brief API Service ID for LinTp_GetVersionInfo */
#define LIN_TP_GET_VERSION_INFO                          (0x42U)
/** @brief API Service ID for LinTp_Init */
#define LIN_TP_INIT                                      (0x40U)
/** @brief API Service ID for LinTp_Shutdown */
#define LIN_TP_SHUTDOWN                                  (0x43U)
/** @brief API Service ID for LinTp_Transmit */
#define LIN_TP_TRANSMIT                                  (0x49U)
/** @brief API Service ID for PduR_LinIfRxIndication */
#define PDU_R_LIN_IF_RX_INDICATION                       (0x42U)
/** @brief API Service ID for PduR_LinIfTriggerTransmit */
#define PDU_R_LIN_IF_TRIGGER_TRANSMIT                    (0x41U)
/** @brief API Service ID for PduR_LinIfTxConfirmation */
#define PDU_R_LIN_IF_TX_CONFIRMATION                     (0x40U)
/** @brief API Service ID for PduR_LinTpCopyRxData */
#define PDU_R_LIN_TP_COPY_RX_DATA                        (0x44U)
/** @brief API Service ID for PduR_LinTpCopyTxData */
#define PDU_R_LIN_TP_COPY_TX_DATA                        (0x43U)
/** @brief API Service ID for PduR_LinTpRxIndication */
#define PDU_R_LIN_TP_RX_INDICATION                       (0x45U)
/** @brief API Service ID for PduR_LinTpStartOfReception */
#define PDU_R_LIN_TP_START_OF_RECEPTION                  (0x46U)
/** @brief API Service ID for PduR_LinTpTxConfirmation */
#define PDU_R_LIN_TP_TX_CONFIRMATION                     (0x48U)
/** @} */

/*==================================================================================================
 *                                         EXTERNAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
 *                                             ENUMS
==================================================================================================*/

/**
 * @brief            Will be called when the EcuM has been notified about a wakeup on a specific LIN channel.    
 * @param[in]        EcuM_WakeupSourceType Source device, which initiated the wakeup event: LIN controller or LIN transceiver
 * @return           Std_ReturnType
 */
Std_ReturnType LinIf_CheckWakeup (EcuM_WakeupSourceType WakeupSource);

/**
 * @brief            The LIN Driver or LIN Transceiver Driver will call this function to report the wake up source after the successful wakeup detection during CheckWakeup or after power on by bus.
 * @param[in]        EcuM_WakeupSourceType Source device which initiated the wakeup event: LIN controller or LIN transceiver
 * @return           void
 */
void LinIf_WakeupConfirmation (EcuM_WakeupSourceType WakeupSource);

/**
 * @brief           The LIN Driver will call this function to report a received LIN header. This 
 *                  function is only applicable for LIN slave nodes (available only if the ECU has 
 *                  any LIN slave channel).     
 * @param[in]       NetworkHandleType LIN transceiver channel ID.
 * @param[in]       Lin_PduType LIN Frame information.
 * @return          Std_ReturnType
 */
Std_ReturnType LinIf_HeaderIndication(NetworkHandleType Channel, Lin_PduType* PduPtr);

/**
 * @brief           The LIN Driver will call this function to report a successfully received 
 *                  response and provides the reception data to the LIN Interface. This function 
 *                  is only applicable for LIN slave nodes (available only if the ECU has any LIN 
 *                  slave channel).     
 * @param[in]       NetworkHandleType LIN transceiver channel ID.
 * @param[in]       uint8* Pointer to pointer to a shadow buffer or memory mapped LIN Hardware 
 *                  receive buffer where the current SDU is stored. This pointer is only valid if 
 *                  the response is received.
 * @return          void
 */
void LinIf_RxIndication(NetworkHandleType Channel, uint8* Lin_SduPtr );

/**
 * @brief           The LIN Driver will call this function to report a successfully transmitted 
 *                  response. This function is only applicable for LIN slave nodes (available only 
 *                  if the ECU has any LIN slave channel).    
 * @param[in]       NetworkHandleType LIN transceiver channel ID.
 * @return          void
 */
void LinIf_TxConfirmation(NetworkHandleType Channel);

/**
 * @brief           The LIN Driver will call this function to report a detected error event during
 *                  header or response processing. This function is only applicable for LIN slave 
 *                  nodes (available only if the ECU has any LIN slave channel). 
 * @param[in]       NetworkHandleType LIN transceiver channel ID.
 * @param[in]       Lin_SlaveErrorType Type of detected error.
 * @return          void
 */
void LinIf_LinErrorIndication(NetworkHandleType Channel, Lin_SlaveErrorType ErrorStatus);

#if (((LINIF_VERSION_INFO_API == STD_ON) && (LINIF_DEV_ERROR_DETECT == STD_ON)))
/**
 * @brief            Returns the version information of this module.
 * @details          
 *
 * @param[in]        none
 * @param[out]       versioninfo Pointer to where to store version information of this module
 *
 * @return           none
 */
#define LinIf_GetVersionInfo(versioninfo)                                       \
    {                                                                          \
        /* Check for DET: LINIF_E_PARAM_POINTER */                              \
        if ((versioninfo) == NULL_PTR)                                         \
        {                                                                      \
            /* Report LINIF_E_PARAM_POINTER DET if service called with          \
               NULL_PTR                                                        \
            */                                                                 \
            Det_ReportError(                                                   \
                (uint16)LINIF_MODULE_ID,                                        \
                LINIF_INSTANCE_ID,                                              \
                LINIF_GET_VERSION_INFO_SID,                                       \
                LINIF_E_PARAM_POINTER);                                         \
        }                                                                      \
        else                                                                   \
        {                                                                      \
            /* Vendor ID information */                                        \
            ((Std_VersionInfoType *)(versioninfo))->vendorID = LINIF_VENDOR_ID; \
            /* LinIf module ID information */                                   \
            ((Std_VersionInfoType *)(versioninfo))->moduleID = LINIF_MODULE_ID; \
            /* LinIf module Software major version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_major_version =         \
                (uint8)LINIF_SW_MAJOR_VERSION;                                  \
            /* LinIf module Software minor version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_minor_version =         \
                (uint8)LINIF_SW_MINOR_VERSION;                                  \
            /* LinIf module Software patch version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_patch_version =         \
                (uint8)LINIF_SW_PATCH_VERSION;                                  \
        }                                                                      \
    }
#elif (((LINIF_VERSION_INFO_API == STD_ON) && (LINIF_DEV_ERROR_DETECT == STD_OFF)))
#define LinIf_GetVersionInfo(versioninfo)                                   \
    {                                                                      \
        /* Vendor ID information */                                        \
        ((Std_VersionInfoType *)(versioninfo))->vendorID = LINIF_VENDOR_ID; \
        /* LinIf module ID information */                                   \
        ((Std_VersionInfoType *)(versioninfo))->moduleID = LINIF_MODULE_ID; \
        /* LinIf module Software major version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_major_version =         \
            (uint8)LINIF_SW_MAJOR_VERSION;                                  \
        /* LinIf module Software minor version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_minor_version =         \
            (uint8)LINIF_SW_MINOR_VERSION;                                  \
        /* LinIf module Software patch version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_patch_version =         \
            (uint8)LINIF_SW_PATCH_VERSION;                                  \
    }
#endif   /* LINIF_VERSION_INFO_API == STD_ON && LINIF_DEV_ERROR_DETECT == STD_ON */

extern CONST(Lin_DriverApiType, LINIF_CONST) Lin_DriverApi[];
extern LinIf_ConfigType LinIf_PCConfig;

FUNC(void, LINIF_CODE)LinIf_Init(LinIf_ConfigType* ConfigPtr);
FUNC(void, LINIF_CODE)LinIf_Side_Init(void);
FUNC(Std_ReturnType, LINIF_CODE)LinIf_GotoSleep(NetworkHandleType Channel);
Std_ReturnType LinIf_CheckWakeup(EcuM_WakeupSourceType WakeupSource);
FUNC(Std_ReturnType, LINIF_CODE) LinIf_Wakeup(NetworkHandleType Channel);
static FUNC(NetworkHandleType, LINIF_CODE) LinIf_GetLinIfChannel(NetworkHandleType channel);
static FUNC(NetworkHandleType, LINIF_CODE) LinIf_GetLinIfChannelByDriverChId(NetworkHandleType channel);
static FUNC(void, LINIF_CODE) LinIf_SlaveMainHandle(void);

#ifdef __cplusplus
}
#endif

#endif /* LINIF_H */

/** @} */

