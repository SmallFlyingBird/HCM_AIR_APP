/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Platform_Mld_Cfg.c
 * @brief 
 * 
 */


#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/

#include "Platform_Mld_Cfg.h"
#include "IntCtrl_Lld.h"
#include "System_Lld.h"
#include "Mpu_Lld_M33_Types.h"

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

#define PLATFORM_PLATFORM_MLD_CFG_VENDOR_ID_C                     (180)
#define PLATFORM_PLATFORM_MLD_CFG_AR_RELEASE_MAJOR_VERSION_C      (4)
#define PLATFORM_PLATFORM_MLD_CFG_AR_RELEASE_MINOR_VERSION_C      (4)
#define PLATFORM_PLATFORM_MLD_CFG_AR_RELEASE_REVISION_VERSION_C   (0)
#define PLATFORM_PLATFORM_MLD_CFG_SW_MAJOR_VERSION_C              (2)
#define PLATFORM_PLATFORM_MLD_CFG_SW_MINOR_VERSION_C              (3)
#define PLATFORM_PLATFORM_MLD_CFG_SW_PATCH_VERSION_C              (0)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Platform_Mld_TypesDef header file are of the same vendor */
#if (PLATFORM_PLATFORM_MLD_CFG_VENDOR_ID_C != PLATFORM_MLD_CFG_VENDOR_ID)
    #error "Platform_Mld_Cfg.c and Platform_Mld_TypesDef.h have different vendor ids"
#endif
/* Check if current file and Platform_Mld_TypesDef header file are of the same Autosar version */
#if ((PLATFORM_PLATFORM_MLD_CFG_AR_RELEASE_MAJOR_VERSION_C    != PLATFORM_MLD_TYPESDEF_AR_RELEASE_MAJOR_VERSION) || \
     (PLATFORM_PLATFORM_MLD_CFG_AR_RELEASE_MINOR_VERSION_C    != PLATFORM_MLD_TYPESDEF_AR_RELEASE_MINOR_VERSION) || \
     (PLATFORM_PLATFORM_MLD_CFG_AR_RELEASE_REVISION_VERSION_C != PLATFORM_MLD_TYPESDEF_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Mld_Cfg.c and Platform_Mld_TypesDef.h are different"
#endif
/* Check if current file and Platform_Mld_TypesDef header file are of the same Software version */
#if ((PLATFORM_PLATFORM_MLD_CFG_SW_MAJOR_VERSION_C != PLATFORM_MLD_TYPESDEF_SW_MAJOR_VERSION) || \
     (PLATFORM_PLATFORM_MLD_CFG_SW_MINOR_VERSION_C != PLATFORM_MLD_TYPESDEF_SW_MINOR_VERSION) || \
     (PLATFORM_PLATFORM_MLD_CFG_SW_PATCH_VERSION_C != PLATFORM_MLD_TYPESDEF_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Mld_Cfg.c and Platform_Mld_TypesDef.h are different"
#endif


/* Check if current file and IntCtrl_Lld header file are of the same vendor */
#if (PLATFORM_MLD_CFG_VENDOR_ID != PLATFORM_INTCTRL_LLD_VENDOR_ID)
    #error "Platform_Mld_Cfg.c and IntCtrl_Lld.h have different vendor ids"
#endif
/* Check if current file and IntCtrl_Lld header file are of the same Autosar version */
#if ((PLATFORM_MLD_CFG_AR_MAJOR_VERSION    != PLATFORM_MLD_TYPESDEF_AR_RELEASE_MAJOR_VERSION) || \
     (PLATFORM_MLD_CFG_AR_MINOR_VERSION    != PLATFORM_MLD_TYPESDEF_AR_RELEASE_MINOR_VERSION) || \
     (PLATFORM_MLD_CFG_AR_REVISION_VERSION != PLATFORM_MLD_TYPESDEF_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Mld_Cfg.c and IntCtrl_Lld.h are different"
#endif
/* Check if current file and IntCtrl_Lld header file are of the same Software version */
#if ((PLATFORM_MLD_CFG_SW_MAJOR_VERSION != PLATFORM_MLD_TYPESDEF_SW_MAJOR_VERSION) || \
     (PLATFORM_MLD_CFG_SW_MINOR_VERSION != PLATFORM_MLD_TYPESDEF_SW_MINOR_VERSION) || \
     (PLATFORM_MLD_CFG_SW_PATCH_VERSION != PLATFORM_MLD_TYPESDEF_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Mld_Cfg.c and IntCtrl_Lld.h are different"
#endif


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

#if (INT_CTRL_LLD_CORTEXM == STD_ON)          
#if (PLATFORM_SYS_CFG == STD_ON)

/* The configuration of system FPU */
PLATFORM_CONST const Platform_SystemIrqConfigType SysIrqCfg[1] = {
    {
        .Irq = FPU_DIVIDE_BY_ZERO_IRQ,
        .Enable = (boolean)(STD_ON),
    },
};
PLATFORM_CONST const Platform_SystemConfigType SystemConfig = 
{ 
    .SystemIrqs = SysIrqCfg,
    .SysIrqsCount = 1U,
    .AhbSlavePriority = STD_OFF,
};

#endif
#endif

#if (PLATFORM_INT_MONITOR == STD_ON)

/* The configuration of INTM */

#endif

/* Definition of the configuration structure for Platform MLD */
PLATFORM_CONST const Platform_Mld_ConfigType MldConfig = {
    .IntCtrlConfig = &IntCtrlConfig,
#if (SYSTEM_FPU_CFG == STD_ON)     
    .SystemConfig = &SystemConfig,
#endif
#if (PLATFORM_INT_MONITOR == STD_ON)
    .IntMonitorConfig = NULL_PTR
#endif
};



/* Definition of the configuration structure for non core Platform LLD */
PLATFORM_CONST const Platform_Mld_NonCoreConfigType MldNonCoreConfig;

#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

#ifdef __cplusplus
}
#endif

