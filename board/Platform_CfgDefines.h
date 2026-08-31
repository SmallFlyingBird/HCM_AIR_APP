/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Platform_CfgDefines.h
 * @brief 
 * 
 */


#ifndef PLATFORM_CFG_DEFINES_H_
#define PLATFORM_CFG_DEFINES_H_

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PLATFORM_CFGDEFINES_VENDOR_ID                     (180)
#define PLATFORM_CFGDEFINES_AR_RELEASE_MAJOR_VERSION      (4)
#define PLATFORM_CFGDEFINES_AR_RELEASE_MINOR_VERSION      (4)
#define PLATFORM_CFGDEFINES_AR_RELEASE_REVISION_VERSION   (0)
#define PLATFORM_CFGDEFINES_SW_MAJOR_VERSION              (2)
#define PLATFORM_CFGDEFINES_SW_MINOR_VERSION              (3)
#define PLATFORM_CFGDEFINES_SW_PATCH_VERSION              (0)

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and StandardTypes header file are of the same Autosar version */
#if ((PLATFORM_CFGDEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (PLATFORM_CFGDEFINES_AR_RELEASE_MINOR_VERSION  != STD_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_CfgDefines.h and Std_Types.h are different"
#endif
#endif

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/* Development error checking */
#define PLATFORM_DEV_ERROR_DETECT   (STD_ON)

/* Interrupt monitoring feature enablement */
#define PLATFORM_INT_MONITOR        (STD_OFF)

/* System settings configurable */
#define PLATFORM_SYS_CFG            (STD_ON)

/* System MSCM configurable */
#define PLATFORM_MSCM_CFG           (STD_OFF)

/* System MPU configurable */
#define PLATFORM_MPU_CFG            (STD_ON)

#define PLATFORM_MPU_M33            (0U)
#define PLATFORM_MPU_M7             (1U)

#define PLATFORM_MPU_TYPE           (PLATFORM_MPU_M33)

#define PLATFORM_ENABLE_CACHE       (STD_OFF)

#if (STD_ON == PLATFORM_INT_MONITOR)
/* Number of available interrupt monitors */
#define PLATFORM_INT_MONITOR_CNT         (0x0U) 

/* Number of available interrupt monitors */
#define PLATFORM_INT_MONITOR_MAX_LATENCY (0x0U) 

#endif /* (STD_ON == PLATFORM_INT_MONITOR) */

#define PLATFORM_MULTICORE_SUPPORT       (STD_OFF)             

#if (STD_ON == PLATFORM_MULTICORE_SUPPORT)
    #define Platform_GetCoreID()     OsIf_GetCoreID()
#else
    #define Platform_GetCoreID()     ((uint8)0UL)
#endif

/* TODO: update if multiple partition support */
#define PLATFORM_MAX_PARTITIONS                   (1U)

/**
* @brief Support for User mode.
*        If this parameter has been configured to 'STD_ON', the PLATFORM driver code can be executed from both supervisor and user mode.
*/
#define PLATFORM_ENABLE_USER_MODE_SUPPORT   (STD_OFF)

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
 #ifdef PLATFORM_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == PLATFORM_ENABLE_USER_MODE_SUPPORT)
   #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Platform in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
  #endif /* (STD_ON == PLATFORM_ENABLE_USER_MODE_SUPPORT) */
 #endif /* ifdef PLATFORM_ENABLE_USER_MODE_SUPPORT*/
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

#define PLATFORM_PC_OFFSET_OF_MSP   (6U)

#endif /* PLATFORM_CFG_DEFINES_H_ */

