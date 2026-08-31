/**
 * @file    Det.c
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

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @page misra_violations MISRA-C:2004 violations
 *
 */

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Det.h"


/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DET_VENDOR_ID_C                      (0xB4)
#define DET_AR_RELEASE_MAJOR_VERSION_C       (4)
#define DET_AR_RELEASE_MINOR_VERSION_C       (4)
#define DET_AR_RELEASE_REVISION_VERSION_C    (0)
#define DET_SW_MAJOR_VERSION_C               (2)
#define DET_SW_MINOR_VERSION_C               (3)
#define DET_SW_PATCH_VERSION_C               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and DET header file are of the same vendor */
#if (DET_VENDOR_ID_C != DET_VENDOR_ID)
#error "Det.c and Det.h have different vendor ids"
#endif

/* Check if source file and DET header file are of the same Autosar version */
#if ((DET_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
     (DET_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) || \
     (DET_AR_RELEASE_REVISION_VERSION_C != DET_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Det.c and Det.h are different"
#endif

/* Check if source file and DET header file are of the same Software version */
#if ((DET_SW_MAJOR_VERSION_C != DET_SW_MAJOR_VERSION) || \
     (DET_SW_MINOR_VERSION_C != DET_SW_MINOR_VERSION) || \
     (DET_SW_PATCH_VERSION_C != DET_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Det.c and Det.h are different"
#endif

/*==================================================================================================
 *                                       LOCAL MACROS
==================================================================================================*/
#define DET_UNUSED_PARAM(parma) ((void)parma)
/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/
uint16 Det_ModuleId;
uint8 Det_ApiId;
uint8 Det_InstanceId;
uint8 Det_ErrorId;
uint16 Det_TotalError;
/*==================================================================================================
 *                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
 * @brief            Service to initialize the Default Error Tracer.
 * @details          
 * @param[in]        Det_ConfigType Pointer to the selected configuration set.
 * @return           void
 * @note             service_id:       0x00 \n
 *                   is_reentrant:     false \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
void Det_Init (const Det_ConfigType * ConfigPtr)
{
    DET_UNUSED_PARAM(ConfigPtr);
}

/**
 * @brief            Service to report development errors.
 * @details          
 * @param[in]        ModuleId Module ID of calling module.
 * @param[in]        InstanceId The identifier of the index based instance of a module, starting from 0, If the module is a single instance module it shall pass 0 as the InstanceId.
 * @param[in]        ApiId ID of API service in which error is detected
                    (defined in SWS of calling module)
 * @param[in]        ErrorId ID of detected development error
                    (defined in SWS of calling module).
 * @return           Std_ReturnType
 * @note             service_id:       0x01 \n
 *                   is_reentrant:     true \n
 *                   is_synchronous:   false \n
 *                   autosar_api:      true \n
 */
Std_ReturnType Det_ReportError (uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId)
{
    Det_ModuleId = ModuleId;
    Det_ApiId = ApiId;
    Det_InstanceId = InstanceId;
    Det_ErrorId = ErrorId;
    Det_TotalError++;
    return (Std_ReturnType)0;
}

/**
 * @brief            Service to report runtime errors. If a callout has been configured then this callout shall be called.
 * @details          
 * @param[in]        ModuleId Module ID of calling module.
 * @param[in]        InstanceId The identifier of the index based instance of a module, starting from 0, If the module is a single instance module it shall pass 0 as the InstanceId.
 * @param[in]        ApiId ID of API service in which error is detected (defined in SWS of calling module)
 * @param[in]        ErrorId ID of detected runtime error (defined in SWS of calling module).
 * @return           Std_ReturnType
 * @note             service_id:       0x04 \n
 *                   is_reentrant:     true \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
Std_ReturnType Det_ReportRuntimeError (uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId)
{
    Det_ModuleId = ModuleId;
    Det_ApiId = ApiId;
    Det_InstanceId = InstanceId;
    Det_ErrorId = ErrorId;
    Det_TotalError++;
    return (Std_ReturnType)0;
}

/**
 * @brief            Service to report transient faults. If a callout has been configured than this callout shall be called and the returned value of the callout shall be returned. Otherwise it returns immediately with E_OK.
 * @details          
 * @param[in]        ModuleId Module ID of calling module.
 * @param[in]        InstanceId The identifier of the index based instance of a module, starting from 0, If the module is a single instance module it shall pass 0 as the InstanceId.
 * @param[in]        ApiId ID of API service in which transient fault is detected (defined in SWS of calling module)
 * @param[in]        FaultId ID of detected transient fault (defined in SWS of calling module).
 * @return           Std_ReturnType
 * @note             service_id:       0x05 \n
 *                   is_reentrant:     true \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
Std_ReturnType Det_ReportTransientFault (uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 FaultId)
{
    Det_ModuleId = ModuleId;
    Det_ApiId = ApiId;
    Det_InstanceId = InstanceId;
    Det_ErrorId = FaultId;
    Det_TotalError++;
    return (Std_ReturnType)0;
}

/**
 * @brief            Service to start the Default Error Tracer.
 * @details          
 * @return           void
 * @note             service_id:       0x02 \n
 *                   is_reentrant:     false \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
void Det_Start (void)
{

}

/*==================================================================================================
 *                                       LOCAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

