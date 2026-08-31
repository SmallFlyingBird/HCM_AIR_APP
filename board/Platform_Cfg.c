/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Platform_Cfg.c
 * @brief 
 * 
 */


#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "Platform_Cfg.h"
#include "Platform_Mld_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PLATFORM_MAIN_CFG_VENDOR_ID_C                     (180)
#define PLATFORM_MAIN_CFG_AR_RELEASE_MAJOR_VERSION_C      (4)
#define PLATFORM_MAIN_CFG_AR_RELEASE_MINOR_VERSION_C      (4)
#define PLATFORM_MAIN_CFG_AR_RELEASE_REVISION_VERSION_C   (0)
#define PLATFORM_MAIN_CFG_SW_MAJOR_VERSION_C              (2)
#define PLATFORM_MAIN_CFG_SW_MINOR_VERSION_C              (3)
#define PLATFORM_MAIN_CFG_SW_PATCH_VERSION_C              (0)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Platform_Cfg header file are of the same vendor */
#if (PLATFORM_MAIN_CFG_VENDOR_ID_C != PLATFORM_MAIN_CFG_VENDOR_ID)
    #error "Platform_Cfg.c and Platform_TypesDef.h have different vendor ids"
#endif
/* Check if current file and Platform_Cfg header file are of the same Autosar version */
#if ((PLATFORM_MAIN_CFG_AR_RELEASE_MAJOR_VERSION_C    != PLATFORM_MAIN_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PLATFORM_MAIN_CFG_AR_RELEASE_MINOR_VERSION_C    != PLATFORM_MAIN_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PLATFORM_MAIN_CFG_AR_RELEASE_REVISION_VERSION_C != PLATFORM_MAIN_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Cfg.c and Platform_Cfg.h are different"
#endif
/* Check if current file and Platform_Cfg header file are of the same Software version */
#if ((PLATFORM_MAIN_CFG_SW_MAJOR_VERSION_C != PLATFORM_MAIN_CFG_SW_MAJOR_VERSION) || \
     (PLATFORM_MAIN_CFG_SW_MINOR_VERSION_C != PLATFORM_MAIN_CFG_SW_MINOR_VERSION) || \
     (PLATFORM_MAIN_CFG_SW_PATCH_VERSION_C != PLATFORM_MAIN_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Cfg.c and Platform_Cfg.h are different"
#endif


/* Check if current file and Platform_Mld_Cfg header file are of the same vendor */
#if (PLATFORM_MAIN_CFG_VENDOR_ID_C != PLATFORM_MLD_CFG_VENDOR_ID)
    #error "Platform_Cfg.c and Platform_Mld_Cfg.h have different vendor ids"
#endif
/* Check if current file and Platform_Mld_Cfg header file are of the same Autosar version */
#if ((PLATFORM_MAIN_CFG_AR_RELEASE_MAJOR_VERSION_C    != PLATFORM_MLD_CFG_AR_MAJOR_VERSION) || \
     (PLATFORM_MAIN_CFG_AR_RELEASE_MINOR_VERSION_C    != PLATFORM_MLD_CFG_AR_MINOR_VERSION) || \
     (PLATFORM_MAIN_CFG_AR_RELEASE_REVISION_VERSION_C != PLATFORM_MLD_CFG_AR_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Cfg.c and Platform_Mld_Cfg.h are different"
#endif
/* Check if current file and Platform_Cfg header file are of the same Software version */
#if ((PLATFORM_MAIN_CFG_SW_MAJOR_VERSION_C != PLATFORM_MLD_CFG_SW_MAJOR_VERSION) || \
     (PLATFORM_MAIN_CFG_SW_MINOR_VERSION_C != PLATFORM_MLD_CFG_SW_MINOR_VERSION) || \
     (PLATFORM_MAIN_CFG_SW_PATCH_VERSION_C != PLATFORM_MLD_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Cfg.c and Platform_Mld_Cfg.h are different"
#endif

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

PLATFORM_CONST static const Platform_ConfigType Platform_uConfiguration = {
    &MldConfig,
    NULL_PTR
};
PLATFORM_CONST const Platform_ConfigType *const Platform_Config[1U]=
{
    &Platform_uConfiguration
};

#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

#ifdef __cplusplus
}
#endif

