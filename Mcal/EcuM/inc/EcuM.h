/**
 * @file    EcuM.h
 * @version 
 *
 * @brief   AUTOSAR EcuM module interface
 * @details API implementation for ECUM driver
 *
 * @addtogroup ECUM_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : EcuM
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

#ifndef ECUM_H
#define ECUM_H

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section EcuM_PBCfg_C_REF_1
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers. 
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 *
 * @section EcuM_PBCfg_C_REF_2
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers. 
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 */


/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include "Std_Types.h"
#include "EcuM_Cfg.h"

/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ECUM_VENDOR_ID                      (0xB4)
#define ECUM_AR_RELEASE_MAJOR_VERSION       (4)
#define ECUM_AR_RELEASE_MINOR_VERSION       (4)
#define ECUM_AR_RELEASE_REVISION_VERSION    (0)
#define ECUM_SW_MAJOR_VERSION               (2)
#define ECUM_SW_MINOR_VERSION               (3)
#define ECUM_SW_PATCH_VERSION               (0)


/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ECUM configuration header file are of the same vendor */
#if (ECUM_VENDOR_ID != ECUM_VENDOR_ID_CFG)
#error "EcuM.h and EcuM_Cfg.h have different vendor ids"
#endif

/* Check if source file and ECUM configuration header file are of the same Autosar version */
#if ((ECUM_AR_RELEASE_MAJOR_VERSION != ECUM_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (ECUM_AR_RELEASE_MINOR_VERSION != ECUM_AR_RELEASE_MINOR_VERSION_CFG) || \
     (ECUM_AR_RELEASE_REVISION_VERSION != ECUM_AR_RELEASE_REVISION_VERSION_CFG) \
    )
#error "AutoSar Version Numbers of EcuM.h and EcuM_Cfg.h are different"
#endif

/* Check if source file and ECUM configuration header file are of the same software version */
#if ((ECUM_SW_MAJOR_VERSION != ECUM_SW_MAJOR_VERSION_CFG) || \
     (ECUM_SW_MINOR_VERSION != ECUM_SW_MINOR_VERSION_CFG) || \
     (ECUM_SW_PATCH_VERSION != ECUM_SW_PATCH_VERSION_CFG) \
    )
#error "Software Version Numbers of EcuM.h and EcuM_Cfg.h are different"
#endif


/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief ECUM MODULE INSTANCE ID */
#define ECUM_INSTANCE_ID ((uint8)0U)

/** @brief ECUM MODULE ID */
#define ECUM_MODULE_ID ((uint8)Lookup from Doc U)

#if (ECUM_DEV_ERROR_DETECT == STD_ON)
/**
 * @defgroup        EcuM_DEV_ERROR
 * @brief           ECUM development errors
 * @{
 */

/** @brief ECUM API service is called using an invalid pointer (e.g. the pointer should not be NULL).  */
#define ECUM_E_PARAM_POINTER ((uint8)Lookup from Doc U)

Error list ....
/** @} */
#endif

/**
 * @defgroup        EcuM_SID
 * @brief           Service ID number for all ECUM driver services
 */
/** @{ */
/** @brief API Service ID for EcuM_ClearWakeupEvent */
#define ECU_M_CLEAR_WAKEUP_EVENT                         (0x16U)
/** @brief API Service ID for EcuM_GetBootTarget */
#define ECU_M_GET_BOOT_TARGET                            (0x13U)
/** @brief API Service ID for EcuM_GetExpiredWakeupEvents */
#define ECU_M_GET_EXPIRED_WAKEUP_EVENTS                  (0x19U)
/** @brief API Service ID for EcuM_GetLastShutdownTarget */
#define ECU_M_GET_LAST_SHUTDOWN_TARGET                   (0x08U)
/** @brief API Service ID for EcuM_GetPendingWakeupEvents */
#define ECU_M_GET_PENDING_WAKEUP_EVENTS                  (0x0dU)
/** @brief API Service ID for EcuM_GetShutdownTarget */
#define ECU_M_GET_SHUTDOWN_TARGET                        (0x09U)
/** @brief API Service ID for EcuM_GetValidatedWakeupEvents */
#define ECU_M_GET_VALIDATED_WAKEUP_EVENTS                (0x15U)
/** @brief API Service ID for EcuM_GetVersionInfo */
#define ECU_M_GET_VERSION_INFO                           (0x00U)
/** @brief API Service ID for EcuM_Init */
#define ECU_M_INIT                                       (0x01U)
/** @brief API Service ID for EcuM_MainFunction */
#define ECU_M_MAIN_FUNCTION                              (0x18U)
/** @brief API Service ID for EcuM_ReleasePOST_RUN */
#define ECU_M_RELEASE_PO_ST_RU_N                         (0x0bU)
/** @brief API Service ID for EcuM_ReleaseRUN */
#define ECU_M_RELEASE_RU_N                               (0x04U)
/** @brief API Service ID for EcuM_RequestPOST_RUN */
#define ECU_M_REQUEST_PO_ST_RU_N                         (0x0aU)
/** @brief API Service ID for EcuM_RequestRUN */
#define ECU_M_REQUEST_RU_N                               (0x03U)
/** @brief API Service ID for EcuM_SelectBootTarget */
#define ECU_M_SELECT_BOOT_TARGET                         (0x12U)
/** @brief API Service ID for EcuM_SelectShutdownTarget */
#define ECU_M_SELECT_SHUTDOWN_TARGET                     (0x06U)
/** @brief API Service ID for EcuM_SetWakeupEvent */
#define ECU_M_SET_WAKEUP_EVENT                           (0x0cU)
/** @brief API Service ID for EcuM_Shutdown */
#define ECU_M_SHUTDOWN                                   (0x02U)
/** @brief API Service ID for EcuM_StartupTwo */
#define ECU_M_STARTUP_TWO                                (0x1aU)
/** @brief API Service ID for EcuM_AL_DriverInitOne */
#define ECU_M_AL_DRIVER_INIT_ONE                         (0x33U)
/** @brief API Service ID for EcuM_AL_DriverInitZero */
#define ECU_M_AL_DRIVER_INIT_ZERO                        (0x31U)
/** @brief API Service ID for EcuM_AL_DriverRestart */
#define ECU_M_AL_DRIVER_RESTART                          (0x45U)
/** @brief API Service ID for EcuM_AL_SwitchOff */
#define ECU_M_AL_SWITCH_OFF                              (0x3eU)
/** @brief API Service ID for EcuM_CheckRamHash */
#define ECU_M_CHECK_RAM_HASH                             (0x43U)
/** @brief API Service ID for EcuM_CheckValidation */
#define ECU_M_CHECK_VALIDATION                           (0x47U)
/** @brief API Service ID for EcuM_DeterminePbConfiguration */
#define ECU_M_DETERMINE_PB_CONFIGURATION                 (0x32U)
/** @brief API Service ID for EcuM_DisableWakeupSources */
#define ECU_M_DISABLE_WAKEUP_SOURCES                     (0x44U)
/** @brief API Service ID for EcuM_EnableWakeupSources */
#define ECU_M_ENABLE_WAKEUP_SOURCES                      (0x3fU)
/** @brief API Service ID for EcuM_EndCheckWakeup */
#define ECU_M_END_CHECK_WAKEUP                           (0x00U)
/** @brief API Service ID for EcuM_ErrorHook */
#define ECU_M_ERROR_HOOK                                 (0x30U)
/** @brief API Service ID for EcuM_GenerateRamHash */
#define ECU_M_GENERATE_RAM_HASH                          (0x40U)
/** @brief API Service ID for EcuM_OnGoOffOne */
#define ECU_M_ON_GO_OFF_ONE                              (0x3cU)
/** @brief API Service ID for EcuM_OnGoOffTwo */
#define ECU_M_ON_GO_OFF_TWO                              (0x3dU)
/** @brief API Service ID for EcuM_SleepActivity */
#define ECU_M_SLEEP_ACTIVITY                             (0x41U)
/** @brief API Service ID for EcuM_StartCheckWakeup */
#define ECU_M_START_CHECK_WAKEUP                         (0x00U)
/** @brief API Service ID for EcuM_StartWakeupSources */
#define ECU_M_START_WAKEUP_SOURCES                       (0x46U)
/** @brief API Service ID for EcuM_StopWakeupSources */
#define ECU_M_STOP_WAKEUP_SOURCES                        (0x48U)
/** @} */

/*==================================================================================================
 *                                         EXTERNAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
 *                                             ENUMS
==================================================================================================*/

/**
 * @brief           
 * @note            trace: 
 */
typedef enum {
    ECUM_WKSTATUS_NONE                       = 0, /**<    */
    ECUM_WKSTATUS_PENDING                    = 1, /**<    */
    ECUM_WKSTATUS_VALIDATED                  = 2, /**<    */
    ECUM_WKSTATUS_EXPIRED                    = 3, /**<    */
    ECUM_WKSTATUS_ENABLED                    = 6, /**<    */
} EcuM_WakeupStatusType;



/**
 * @brief            
 * @note            trace: 
 */
typedef uint32 EcuM_WakeupSourceType;



/**
 * @brief            Check wakeup events.
 * @details          
 * @param[in]        EcuM_WakeupSourceType Events to be cleared
 * @return           void
 * @note             service_id:       0x16 \n
 *                   is_reentrant:     false \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
void EcuM_CheckWakeup (EcuM_WakeupSourceType sources);

/**
 * @brief            Sets the wakeup event.
 * @details          
 * @param[in]        EcuM_WakeupSourceType Value to be set
 * @return           void
 * @note             service_id:       0x0c \n
 *                   is_reentrant:     false \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
void EcuM_SetWakeupEvent (EcuM_WakeupSourceType sources);

#if (((ECUM_VERSION_INFO_API == STD_ON) && (ECUM_DEV_ERROR_DETECT == STD_ON)))
/**
 * @brief            Returns the version information of this module.
 * @details          
 *
 * @param[in]        none
 * @param[out]       versioninfo Pointer to where to store version information of this module
 *
 * @return           none
 */
#define EcuM_GetVersionInfo(versioninfo)                                       \
    {                                                                          \
        /* Check for DET: ECUM_E_PARAM_POINTER */                              \
        if ((versioninfo) == NULL_PTR)                                         \
        {                                                                      \
            /* Report ECUM_E_PARAM_POINTER DET if service called with          \
               NULL_PTR                                                        \
            */                                                                 \
            Det_ReportError(                                                   \
                (uint16)ECUM_MODULE_ID,                                        \
                ECUM_INSTANCE_ID,                                              \
                ECUM_GET_VERSION_INFO_SID,                                       \
                ECUM_E_PARAM_POINTER);                                         \
        }                                                                      \
        else                                                                   \
        {                                                                      \
            /* Vendor ID information */                                        \
            ((Std_VersionInfoType *)(versioninfo))->vendorID = ECUM_VENDOR_ID; \
            /* EcuM module ID information */                                   \
            ((Std_VersionInfoType *)(versioninfo))->moduleID = ECUM_MODULE_ID; \
            /* EcuM module Software major version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_major_version =         \
                (uint8)ECUM_SW_MAJOR_VERSION;                                  \
            /* EcuM module Software minor version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_minor_version =         \
                (uint8)ECUM_SW_MINOR_VERSION;                                  \
            /* EcuM module Software patch version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_patch_version =         \
                (uint8)ECUM_SW_PATCH_VERSION;                                  \
        }                                                                      \
    }
#elif (((ECUM_VERSION_INFO_API == STD_ON) && (ECUM_DEV_ERROR_DETECT == STD_OFF)))
#define EcuM_GetVersionInfo(versioninfo)                                   \
    {                                                                      \
        /* Vendor ID information */                                        \
        ((Std_VersionInfoType *)(versioninfo))->vendorID = ECUM_VENDOR_ID; \
        /* EcuM module ID information */                                   \
        ((Std_VersionInfoType *)(versioninfo))->moduleID = ECUM_MODULE_ID; \
        /* EcuM module Software major version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_major_version =         \
            (uint8)ECUM_SW_MAJOR_VERSION;                                  \
        /* EcuM module Software minor version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_minor_version =         \
            (uint8)ECUM_SW_MINOR_VERSION;                                  \
        /* EcuM module Software patch version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_patch_version =         \
            (uint8)ECUM_SW_PATCH_VERSION;                                  \
    }
#endif   /* ECUM_VERSION_INFO_API == STD_ON && ECUM_DEV_ERROR_DETECT == STD_ON */



#ifdef __cplusplus
}
#endif

#endif /* ECUM_H */

/** @} */

