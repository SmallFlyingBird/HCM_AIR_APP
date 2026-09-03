/**
 * @file    WdgIf.h
 * @version 
 *
 * @brief   AUTOSAR WdgIf module interface
 * @details API implementation for WDGIF driver
 *
 * @addtogroup WDGIF_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : WdgIf
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

#ifndef WDGIF_H
#define WDGIF_H

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section WdgIf_PBCfg_C_REF_1
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers. 
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 *
 * @section WdgIf_PBCfg_C_REF_2
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers. 
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 */


/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include "Std_Types.h"
#include "WdgIf_Types.h"
#if 0
#include "WdgIf_Cfg.h"
#endif
/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WDGIF_VENDOR_ID                      (0xB4)
#define WDGIF_AR_RELEASE_MAJOR_VERSION       (4)
#define WDGIF_AR_RELEASE_MINOR_VERSION       (4)
#define WDGIF_AR_RELEASE_REVISION_VERSION    (0)
#define WDGIF_SW_MAJOR_VERSION               (2)
#define WDGIF_SW_MINOR_VERSION               (3)
#define WDGIF_SW_PATCH_VERSION               (0)


/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief WDGIF MODULE INSTANCE ID */
#define WDGIF_INSTANCE_ID ((uint8)0U)

/** @brief WDGIF MODULE ID */
#define WDGIF_MODULE_ID ((uint8)Lookup from Doc U)

#if (WDGIF_DEV_ERROR_DETECT == STD_ON)   /* PRQA S 3332 */
/**
 * @defgroup        WdgIf_DEV_ERROR
 * @brief           WDGIF development errors
 * @{
 */
/** @brief WDGIF API service is called using an invalid pointer (e.g. the pointer should not be NULL).  */
#define WDGIF_E_PARAM_DEVICE  ((uint8)1U)   /** @brief API service called with wrong device index parameter*/
#define WDGIF_E_INV_POINTER   ((uint8)2U)   /** @brief Invalid pointer in parameter list*/
#define WDGIF_E_PARAM_POINTER ((uint8)3U)   /** @brief NULL pointer checking*/

/** @} */
#endif

/**
 * @defgroup        WdgIf_SID
 * @brief           Service ID number for all WDGIF driver services
 * @{
 */
/** @brief API Service ID for WdgIf_GetVersionInfo */
#define WDG_IF_GET_VERSION_INFO                          (0x03U)
/** @brief API Service ID for WdgIf_SetMode */
#define WDG_IF_SET_MODE                                  (0x01U)
/** @brief API Service ID for WdgIf_SetTriggerCondition */
#define WDG_IF_SET_TRIGGER_CONDITION                     (0x02U)
/** @} */

/*==================================================================================================
 *                                         EXTERNAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
 *                                             ENUMS
==================================================================================================*/

/**
 * @brief            Returns the version information.
 * @details          
 * @param[out]       Std_VersionInfoType Pointer to where to store the version information of this module.
 * @return           void
 * @retval           <return_value> {return_value description}
 * @note             service_id:       0x03 \n
 *                   is_reentrant:     true \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
void WdgIf_GetVersionInfo (Std_VersionInfoType * VersionInfoPtr);

/**
 * @brief            Map the service WdgIf_SetMode to the service Wdg_180_Inst0_SetMode of the corresponding Watchdog Driver.
 * @details          
 * @param[in]        uint8 Identifies the Watchdog Driver instance.
 * @param[in]        WdgIf_ModeType The watchdog driver mode (see Watchdog Driver).
 * @return           Std_ReturnType
 * @retval           <return_value> {return_value description}
 * @note             service_id:       0x01 \n
 *                   is_reentrant:     false \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
Std_ReturnType WdgIf_SetMode (uint8 DeviceIndex, WdgIf_ModeType WdgMode);

/**
 * @brief            Map the service WdgIf_SetTriggerCondition to the service Wdg_SetTriggerCondition of the corresponding Watchdog Driver.
 * @details          
 * @param[in]        uint8 Identifies the Watchdog Driver instance.
 * @param[in]        uint16 Timeout value (milliseconds) for setting the trigger counter.
 * @return           void
 * @retval           <return_value> {return_value description}
 * @note             service_id:       0x02 \n
 *                   is_reentrant:     false \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
void WdgIf_SetTriggerCondition (uint8 DeviceIndex, uint16 Timeout);

#if (((WDGIF_VERSION_INFO_API == STD_ON) && (WDGIF_DEV_ERROR_DETECT == STD_ON)))   /* PRQA S 3332 */
/**
 * @brief            Returns the version information of this module.
 * @details          
 *
 * @param[in]        none
 * @param[out]       versioninfo Pointer to where to store version information of this module
 *
 * @return           none
 */
#define WdgIf_GetVersionInfo(versioninfo)                                       \
    {                                                                          \
        /* Check for DET: WDGIF_E_PARAM_POINTER */                              \
        if ((versioninfo) == NULL_PTR)                                         \
        {                                                                      \
            /* Report WDGIF_E_PARAM_POINTER DET if service called with          \
               NULL_PTR                                                        \
            */                                                                 \
            Det_ReportError(                                                   \
                (uint16)WDGIF_MODULE_ID,                                        \
                WDGIF_INSTANCE_ID,                                              \
                WDGIF_SID_GET_VERSION_INFO,                                       \
                WDGIF_E_PARAM_POINTER);                                         \
        }                                                                      \
        else                                                                   \
        {                                                                      \
            /* Vendor ID information */                                        \
            ((Std_VersionInfoType *)(versioninfo))->vendorID = WDGIF_VENDOR_ID; \
            /* WdgIf module ID information */                                   \
            ((Std_VersionInfoType *)(versioninfo))->moduleID = WDGIF_MODULE_ID; \
            /* WdgIf module Software major version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_major_version =         \
                (uint8)WDGIF_SW_MAJOR_VERSION;                                  \
            /* WdgIf module Software minor version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_minor_version =         \
                (uint8)WDGIF_SW_MINOR_VERSION;                                  \
            /* WdgIf module Software patch version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_patch_version =         \
                (uint8)WDGIF_SW_PATCH_VERSION;                                  \
        }                                                                      \
    }
#elif (((WDGIF_VERSION_INFO_API == STD_ON) && (WDGIF_DEV_ERROR_DETECT == STD_OFF)))   /* PRQA S 3332 */
#define WdgIf_GetVersionInfo(versioninfo)                                   \
    {                                                                      \
        /* Vendor ID information */                                        \
        ((Std_VersionInfoType *)(versioninfo))->vendorID = WDGIF_VENDOR_ID; \
        /* WdgIf module ID information */                                   \
        ((Std_VersionInfoType *)(versioninfo))->moduleID = WDGIF_MODULE_ID; \
        /* WdgIf module Software major version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_major_version =         \
            (uint8)WDGIF_SW_MAJOR_VERSION;                                  \
        /* WdgIf module Software minor version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_minor_version =         \
            (uint8)WDGIF_SW_MINOR_VERSION;                                  \
        /* WdgIf module Software patch version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_patch_version =         \
            (uint8)WDGIF_SW_PATCH_VERSION;                                  \
    }
#endif   /* WDGIF_VERSION_INFO_API == STD_ON && WDGIF_DEV_ERROR_DETECT == STD_ON */



#ifdef __cplusplus
}
#endif

#endif /* WDGIF_H */

/** @} */

