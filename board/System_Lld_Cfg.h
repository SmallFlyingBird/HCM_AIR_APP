/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file System_Lld_Cfg.h
 * @brief 
 * 
 */


#ifndef SYSTEM_LLD_CFG_H_
#define SYSTEM_LLD_CFG_H_

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "System_Lld_CfgDefines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PLATFORM_SYSTEM_LLD_CFG_TYPES_VENDOR_ID                    (180)
#define PLATFORM_SYSTEM_LLD_CFG_SW_MAJOR_VERSION                   (2)
#define PLATFORM_SYSTEM_LLD_CFG_SW_MINOR_VERSION                   (3)
#define PLATFORM_SYSTEM_LLD_CFG_SW_PATCH_VERSION                   (0)

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and System_Lld_CfgDefines header file are of the same vendor */
#if (PLATFORM_SYSTEM_LLD_CFG_TYPES_VENDOR_ID != PLATFORM_SYSTEM_LLD_CFG_DEFINES_TYPES_VENDOR_ID)
    #error "System_Lld_Cfg.h and System_Lld_CfgDefines.h have different vendor ids"
#endif

/* Check if current file and System_Lld_CfgDefines header file are of the same Software version */
#if ((PLATFORM_SYSTEM_LLD_CFG_SW_MAJOR_VERSION != PLATFORM_SYSTEM_LLD_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (PLATFORM_SYSTEM_LLD_CFG_SW_MINOR_VERSION != PLATFORM_SYSTEM_LLD_CFG_DEFINES_SW_MINOR_VERSION) || \
     (PLATFORM_SYSTEM_LLD_CFG_SW_PATCH_VERSION != PLATFORM_SYSTEM_LLD_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of System_Lld_Cfg.h and System_Lld_CfgDefines.h are different"
#endif
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/* Development error detection */
#define SYSTEM_LLD_DEV_ERROR_DETECT         (STD_ON)

/* User mode support */
#define SYSTEM_LLD_ENABLE_USER_MODE_SUPPORT (STD_OFF)

#endif /* SYSTEM_LLD_CFG_H_ */

