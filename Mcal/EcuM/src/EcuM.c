/**
 * @file    EcuM.c
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
#include "EcuM.h"
#include "EcuM_Cfg.h"

#if (ECUM_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif /* ECUM_DEV_ERROR_DETECT == STD_ON */

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ECUM_VENDOR_ID_C                      (0xB4)
#define ECUM_AR_RELEASE_MAJOR_VERSION_C       (4)
#define ECUM_AR_RELEASE_MINOR_VERSION_C       (4)
#define ECUM_AR_RELEASE_REVISION_VERSION_C    (0)
#define ECUM_SW_MAJOR_VERSION_C               (2)
#define ECUM_SW_MINOR_VERSION_C               (3)
#define ECUM_SW_PATCH_VERSION_C               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ECUM header file are of the same vendor */
#if (ECUM_VENDOR_ID_C != ECUM_VENDOR_ID)
#error "EcuM.c and EcuM.h have different vendor ids"
#endif

/* Check if source file and ECUM header file are of the same Autosar version */
#if ((ECUM_AR_RELEASE_MAJOR_VERSION_C != ECUM_AR_RELEASE_MAJOR_VERSION) || \
     (ECUM_AR_RELEASE_MINOR_VERSION_C != ECUM_AR_RELEASE_MINOR_VERSION) || \
     (ECUM_AR_RELEASE_REVISION_VERSION_C != ECUM_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of EcuM.c and EcuM.h are different"
#endif

/* Check if source file and ECUM header file are of the same Software version */
#if ((ECUM_SW_MAJOR_VERSION_C != ECUM_SW_MAJOR_VERSION) || \
     (ECUM_SW_MINOR_VERSION_C != ECUM_SW_MINOR_VERSION) || \
     (ECUM_SW_PATCH_VERSION_C != ECUM_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of EcuM.c and EcuM.h are different"
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


/* weak EcuM callback */
__attribute__((weak)) void WkuInterruptCallback(EcuM_WakeupSourceType sources){
    (void)sources;
}
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
void EcuM_CheckWakeup (EcuM_WakeupSourceType sources)
{
    WkuInterruptCallback(sources);
}


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
void EcuM_SetWakeupEvent (EcuM_WakeupSourceType sources)
{
    (void)sources;
}

/*==================================================================================================
 *                                       LOCAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

