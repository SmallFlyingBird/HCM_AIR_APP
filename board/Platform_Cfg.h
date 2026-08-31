/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Platform_Cfg.h
 * @brief 
 * 
 */



#ifndef PLATFORM_CFG_H_
#define PLATFORM_CFG_H_

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "Platform_TypesDef.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PLATFORM_MAIN_CFG_VENDOR_ID                     (180)
#define PLATFORM_MAIN_CFG_AR_RELEASE_MAJOR_VERSION      (4)
#define PLATFORM_MAIN_CFG_AR_RELEASE_MINOR_VERSION      (4)
#define PLATFORM_MAIN_CFG_AR_RELEASE_REVISION_VERSION   (0)
#define PLATFORM_MAIN_CFG_SW_MAJOR_VERSION              (2)
#define PLATFORM_MAIN_CFG_SW_MINOR_VERSION              (3)
#define PLATFORM_MAIN_CFG_SW_PATCH_VERSION              (0)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Platform_TypesDef header file are of the same vendor */
#if (PLATFORM_MAIN_CFG_VENDOR_ID != PLATFORM_TYPESDEF_VENDOR_ID)
    #error "Platform_Cfg.h and Platform_TypesDef.h have different vendor ids"
#endif
/* Check if current file and Platform_TypesDef header file are of the same Autosar version */
#if ((PLATFORM_MAIN_CFG_AR_RELEASE_MAJOR_VERSION    != PLATFORM_TYPESDEF_AR_RELEASE_MAJOR_VERSION) || \
     (PLATFORM_MAIN_CFG_AR_RELEASE_MINOR_VERSION    != PLATFORM_TYPESDEF_AR_RELEASE_MINOR_VERSION) || \
     (PLATFORM_MAIN_CFG_AR_RELEASE_REVISION_VERSION != PLATFORM_TYPESDEF_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Cfg.h and Platform_TypesDef.h are different"
#endif
/* Check if current file and Platform_TypesDef header file are of the same Software version */
#if ((PLATFORM_MAIN_CFG_SW_MAJOR_VERSION != PLATFORM_TYPESDEF_SW_MAJOR_VERSION) || \
     (PLATFORM_MAIN_CFG_SW_MINOR_VERSION != PLATFORM_TYPESDEF_SW_MINOR_VERSION) || \
     (PLATFORM_MAIN_CFG_SW_PATCH_VERSION != PLATFORM_TYPESDEF_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Cfg.h and Platform_TypesDef.h are different"
#endif

/* Check if current file and Platform_CfgDefines header file are of the same vendor */
#if (PLATFORM_MAIN_CFG_VENDOR_ID != PLATFORM_CFGDEFINES_VENDOR_ID)
    #error "Platform_Cfg.h and Platform_CfgDefines.h have diPlatform_CfgDefinesfferent vendor ids"
#endif
/* Check if current file and Platform_CfgDefines header file are of the same Autosar version */
#if ((PLATFORM_MAIN_CFG_AR_RELEASE_MAJOR_VERSION    != PLATFORM_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (PLATFORM_MAIN_CFG_AR_RELEASE_MINOR_VERSION    != PLATFORM_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     (PLATFORM_MAIN_CFG_AR_RELEASE_REVISION_VERSION != PLATFORM_CFGDEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Cfg.h and Platform_CfgDefines.h are different"
#endif
/* Check if current file and Platform_CfgDefines header file are of the same Software version */
#if ((PLATFORM_MAIN_CFG_SW_MAJOR_VERSION != PLATFORM_CFGDEFINES_SW_MAJOR_VERSION) || \
     (PLATFORM_MAIN_CFG_SW_MINOR_VERSION != PLATFORM_CFGDEFINES_SW_MINOR_VERSION) || \
     (PLATFORM_MAIN_CFG_SW_PATCH_VERSION != PLATFORM_CFGDEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Cfg.h and Platform_CfgDefines.h are different"
#endif



/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/* TBD */


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/



/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/* @brief ARM Cortex-A 64-bit CPU core platform */
#define MCAL_ARM_AARCH64                 (0u)

/* @brief ARM Cortex-A 32-bit CPU core platform */
#define MCAL_ARM_AARCH32                 (1u)

/* @brief ARM Cortex-R CPU core platform */
#define MCAL_ARM_RARCH                   (3u)

/* @brief ARM Cortex-M CPU core platform */
#define MCAL_ARM_MARCH                   (4u)

/* @brief ARM CPU core platform */
#define MCAL_PLATFORM_ARM                (MCAL_ARM_MARCH)

/**
* @brief Support for SchM: sync/atomic operations, global interrupt disable/enable.
*        If this parameter has been configured to 'STD_ON', the MCAL driver code supports sync/atomic operations for key resource protection.
*        If it is enabled, all the SchM codes in MCAL Platform driver codes will work and support sync/atomic operation with CPU global interrupt enable/disable for key resource protection. 
*        Disable it can reduce code size, but may cause potential risks when access to some critical resource!
*/
#define PLATFORM_SCHM_SUPPORT  (STD_ON) 

/**
 * @brief Pre-processor switch to use or not use the post-build config
 * @note range: STD_ON, STD_OFF      
 */
#define PLATFORM_FIXED_PB_CONFIG (STD_ON)


#endif /* PLATFORM_CFG_H_ */

