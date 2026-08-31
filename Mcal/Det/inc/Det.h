/**
 * @file    Det.h
 * @version
 *
 * @brief   AUTOSAR Det module interface
 * @details API implementation for DET driver
 *
 * @addtogroup DET_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Det
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

#ifndef DET_H
#define DET_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section Det_PBCfg_C_REF_1
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers.
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 *
 * @section Det_PBCfg_C_REF_2
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers.
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 */

/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include "Std_Types.h"
#include "Det_Cfg.h"

/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DET_VENDOR_ID                      (180)
#define DET_AR_RELEASE_MAJOR_VERSION       (4)
#define DET_AR_RELEASE_MINOR_VERSION       (4)
#define DET_AR_RELEASE_REVISION_VERSION    (0)
#define DET_SW_MAJOR_VERSION               (2)
#define DET_SW_MINOR_VERSION               (3)
#define DET_SW_PATCH_VERSION               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and DET configuration header file are of the same vendor */
#if (DET_VENDOR_ID != DET_VENDOR_ID_CFG)
#error "Det.h and Det_Cfg.h have different vendor ids"
#endif

/* Check if source file and DET configuration header file are of the same Autosar version */
#if ((DET_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (DET_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION_CFG) || \
     (DET_AR_RELEASE_REVISION_VERSION != DET_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Det.h and Det_Cfg.h are different"
#endif

/* Check if source file and DET configuration header file are of the same software version */
#if ((DET_SW_MAJOR_VERSION != DET_SW_MAJOR_VERSION_CFG) || \
     (DET_SW_MINOR_VERSION != DET_SW_MINOR_VERSION_CFG) || \
     (DET_SW_PATCH_VERSION != DET_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Det.h and Det_Cfg.h are different"
#endif

/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief DET MODULE INSTANCE ID */
#define DET_INSTANCE_ID ((uint8)0U)

/** @brief DET MODULE ID */
#define DET_MODULE_ID (15U)

/**
 * @defgroup        Det_SID
 * @brief           Service ID number for all DET driver services
 */
/** @{ */
/** @brief API Service ID for Det_GetVersionInfo */
#define DET_SID_GET_VERSION_INFO (0x03U)
/** @brief API Service ID for Det_Init */
#define DET_SID_INIT (0x00U)
/** @brief API Service ID for Det_ReportError */
#define DET_SID_REPORT_ERROR (0x01U)
/** @brief API Service ID for Det_ReportRuntimeError */
#define DET_SID_REPORT_RUNTIME_ERROR (0x04U)
/** @brief API Service ID for Det_ReportTransientFault */
#define DET_SID_REPORT_TRANSIENT_FAULT (0x05U)
/** @brief API Service ID for Det_Start */
#define DET_SID_START (0x02U)
/** @} */

/*==================================================================================================
*                                         EXTERNAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/**
* @brief
* @todo
*/
typedef struct
{
    uint8 tbd;
} Det_ConfigType;

/**
* @brief            Service to initialize the Default Error Tracer.
* @details
* @param[in]        Det_ConfigType Pointer to the selected configuration set.
* @return           void
* @note             service_id:       0x00
*                   is_reentrant:     false
*                   is_synchronous:   true
*                   autosar_api:      true
*/
void Det_Init(const Det_ConfigType *ConfigPtr);

/**
* @brief            Service to report development errors.
* @details
* @param[in]        uint16 Module ID of calling module.
* @param[in]        uint8 The identifier of the index based instance of a module, starting from 0, If the module is a single instance module it shall pass 0 as the InstanceId.
* @param[in]        uint8 ID of API service in which error is detected
                (defined in SWS of calling module)
* @param[in]        uint8 ID of detected development error
                (defined in SWS of calling module).
* @return           Std_ReturnType
* @note             service_id:       0x01
*                   is_reentrant:     true
*                   is_synchronous:   false
*                   autosar_api:      true
*/
Std_ReturnType Det_ReportError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);

/**
* @brief            Service to report runtime errors. If a callout has been configured then this callout shall be called.
* @details
*
* @param[in]        uint16 Module ID of calling module.
* @param[in]        uint8 The identifier of the index based instance of a module, starting from 0, If the module is a single instance module it shall pass 0 as the InstanceId.
* @param[in]        uint8 ID of API service in which error is detected (defined in SWS of calling module)
* @param[in]        uint8 ID of detected runtime error (defined in SWS of calling module).
* @return           Std_ReturnType
* @note             service_id:       0x04
*                   is_reentrant:     true
*                   is_synchronous:   true
*                   bsw_entry_kind:   CONCRETE
*                   autosar_api:      true
*/
Std_ReturnType Det_ReportRuntimeError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);

/**
* @brief            Service to report transient faults. If a callout has been configured than this callout shall be called and the returned value of the callout shall be returned. Otherwise it returns immediately with E_OK.
* @details
* @param[in]        uint16 Module ID of calling module.
* @param[in]        uint8 The identifier of the index based instance of a module, starting from 0, If the module is a single instance module it shall pass 0 as the InstanceId.
* @param[in]        uint8 ID of API service in which transient fault is detected (defined in SWS of calling module)
* @param[in]        uint8 ID of detected transient fault (defined in SWS of calling module).
* @return           Std_ReturnType
* @note             service_id:       0x05
*                   is_reentrant:     true
*                   is_synchronous:   true
*                   autosar_api:      true
*/
Std_ReturnType Det_ReportTransientFault(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 FaultId);

/**
* @brief            Service to start the Default Error Tracer.
* @details
* @return           void
* @note             service_id:       0x02
*                   is_reentrant:     false
*                   is_synchronous:   true
*                   autosar_api:      true
*/
void Det_Start(void);

/**
 * @brief            Returns the version information of this module.
 * @details
 *
 * @param[in]        none
 * @param[out]       versioninfo Pointer to where to store version information of this module
 *
 * @return           none
 */
#define Det_GetVersionInfo(versioninfo)                                       \
    {                                                                         \
        /* Check for DET: DET_E_PARAM_POINTER */                              \
        if ((versioninfo) == NULL_PTR)                                        \
        {                                                                     \
            /* Report DET_E_PARAM_POINTER DET if service called with          \
               NULL_PTR                                                       \
            */                                                                \
            Det_ReportError(                                                  \
                (uint16)DET_MODULE_ID,                                        \
                DET_INSTANCE_ID,                                              \
                DET_GET_VERSION_INFO_SID,                                     \
                DET_E_PARAM_POINTER);                                         \
        }                                                                     \
        else                                                                  \
        {                                                                     \
            /* Vendor ID information */                                       \
            ((Std_VersionInfoType *)(versioninfo))->vendorID = DET_VENDOR_ID; \
            /* Det module ID information */                                   \
            ((Std_VersionInfoType *)(versioninfo))->moduleID = DET_MODULE_ID; \
            /* Det module Software major version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_major_version =        \
                (uint8)DET_SW_MAJOR_VERSION;                                      \
            /* Det module Software minor version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_minor_version =        \
                (uint8)DET_SW_MINOR_VERSION;                                      \
            /* Det module Software patch version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_patch_version =        \
                (uint8)DET_SW_PATCH_VERSION;                                      \
        }                                                                     \
    }

#ifdef __cplusplus
}
#endif

#endif /* DET_H */

/** @} */

