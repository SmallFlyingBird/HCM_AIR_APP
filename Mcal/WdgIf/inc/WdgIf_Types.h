/**
 * @file    WdgIf_Types.h
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

#ifndef WDGIF_TYPES_H
#define WDGIF_TYPES_H

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

/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WDGIF_TYPES_VENDOR_ID                      (0xB4)
#define WDGIF_TYPES_AR_RELEASE_MAJOR_VERSION       (4)
#define WDGIF_TYPES_AR_RELEASE_MINOR_VERSION       (2)
#define WDGIF_TYPES_AR_RELEASE_REVISION_VERSION    (2)
#define WDGIF_TYPES_SW_MAJOR_VERSION               (2)
#define WDGIF_TYPES_SW_MINOR_VERSION               (3)
#define WDGIF_TYPES_SW_PATCH_VERSION               (0)


/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
/*==================================================================================================
 *                                         EXTERNAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
 *                                             ENUMS
==================================================================================================*/
/**
*   @brief  This enumerated type will contain the watchdog driver's possible states
*/
typedef enum
{
    WDGIF_UNINIT    = 0x01U,    /**< @brief = 0x01 The watchdog driver is not uninitialized.  This shall be the default value after reset */
    WDGIF_IDLE      = 0x02U,    /**< @brief = 0x02 The watchdog driver is currently idle, i.e not beeing triggered or mode changed */
    WDGIF_BUSY      = 0x03U     /**< @brief = 0x03 The watchdog driver is currently busy, i.e triggered or switchd between modes */
} WdgIf_StatusType;

/**
*   @brief  This enumerated type will contain the watchdog driver's possible modes
*/
typedef enum {
    WDGIF_OFF_MODE  = 0x00U,    /**< @brief  = 0x00 In this mode, the watchdog driver is disabled (switched off). */
    WDGIF_SLOW_MODE = 0x01U,    /**< @brief  = 0x01 In this mode, the watchdog driver is set up for a long timeout period (slow triggering).*/
    WDGIF_FAST_MODE = 0x02U     /**< @brief  = 0x02 In this mode, the watchdog driver is set up for a short timeout period (fast triggering).*/
} WdgIf_ModeType;

#ifdef __cplusplus
}
#endif

#endif /* WDGIF_H */

/** @} */

