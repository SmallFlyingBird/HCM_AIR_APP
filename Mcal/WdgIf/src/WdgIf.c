/**
 * @file    WdgIf.c
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

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section Dio_PBCfg_C_REF_1
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers. 
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 *
 * @section Dio_PBCfg_C_REF_2
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers. 
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 */



/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "WdgIf.h"


#if 0
    #include "Det.h"
#endif /* WDGIF_DEV_ERROR_DETECT == STD_ON */

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WDGIF_VENDOR_ID_C                      (0xB4)
#define WDGIF_AR_RELEASE_MAJOR_VERSION_C       (4)
#define WDGIF_AR_RELEASE_MINOR_VERSION_C       (4)
#define WDGIF_AR_RELEASE_REVISION_VERSION_C    (0)
#define WDGIF_SW_MAJOR_VERSION_C               (2)
#define WDGIF_SW_MINOR_VERSION_C               (3)
#define WDGIF_SW_PATCH_VERSION_C               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and WDGIF header file are of the same vendor */
#if (WDGIF_VENDOR_ID_C != WDGIF_VENDOR_ID)
#error "WdgIf.c and WdgIf.h have different vendor ids"
#endif

/* Check if source file and WDGIF header file are of the same Autosar version */
#if ((WDGIF_AR_RELEASE_MAJOR_VERSION_C != WDGIF_AR_RELEASE_MAJOR_VERSION) || \
     (WDGIF_AR_RELEASE_MINOR_VERSION_C != WDGIF_AR_RELEASE_MINOR_VERSION) || \
     (WDGIF_AR_RELEASE_REVISION_VERSION_C != WDGIF_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of WdgIf.c and WdgIf.h are different"
#endif

/* Check if source file and WDGIF header file are of the same Software version */
#if ((WDGIF_SW_MAJOR_VERSION_C != WDGIF_SW_MAJOR_VERSION) || \
     (WDGIF_SW_MINOR_VERSION_C != WDGIF_SW_MINOR_VERSION) || \
     (WDGIF_SW_PATCH_VERSION_C != WDGIF_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of WdgIf.c and WdgIf.h are different"
#endif

/*==================================================================================================
 *                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/

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
void WdgIf_GetVersionInfo (Std_VersionInfoType * VersionInfoPtr)   /* PRQA S 3673 */
{
    (void)VersionInfoPtr;
}

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
Std_ReturnType WdgIf_SetMode (uint8 DeviceIndex, WdgIf_ModeType WdgMode)
{
    (void)DeviceIndex;
    (void)WdgMode;
    return E_NOT_OK;
}

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
void WdgIf_SetTriggerCondition (uint8 DeviceIndex, uint16 Timeout)
{
    (void)DeviceIndex;
    (void)Timeout;
}

/*==================================================================================================
 *                                       LOCAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

