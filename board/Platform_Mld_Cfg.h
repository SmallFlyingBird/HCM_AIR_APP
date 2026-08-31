/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Platform_Mld_Cfg.h
 * @brief 
 * 
 */


#ifndef PLATFORM_MLD_CFG_H_
#define PLATFORM_MLD_CFG_H_

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "Platform_Mld_TypesDef.h"
#define PLATFORM_MLD_CFG_VENDOR_ID                     (180)
#define PLATFORM_MLD_CFG_AR_MAJOR_VERSION              (4)
#define PLATFORM_MLD_CFG_AR_MINOR_VERSION              (4)
#define PLATFORM_MLD_CFG_AR_REVISION_VERSION           (0)
#define PLATFORM_MLD_CFG_SW_MAJOR_VERSION              (2)
#define PLATFORM_MLD_CFG_SW_MINOR_VERSION              (3)
#define PLATFORM_MLD_CFG_SW_PATCH_VERSION              (0)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Platform_Mld_TypesDef header file are of the same vendor */
#if (PLATFORM_MLD_CFG_VENDOR_ID != PLATFORM_MLD_TYPESDEF_VENDOR_ID)
    #error "Platform_Mld_Cfg.h and Platform_Mld_TypesDef.h have different vendor ids"
#endif
/* Check if current file and Platform_Mld_TypesDef header file are of the same Autosar version */
#if ((PLATFORM_MLD_CFG_AR_MAJOR_VERSION    != PLATFORM_MLD_TYPESDEF_AR_RELEASE_MAJOR_VERSION) || \
     (PLATFORM_MLD_CFG_AR_MINOR_VERSION    != PLATFORM_MLD_TYPESDEF_AR_RELEASE_MINOR_VERSION) || \
     (PLATFORM_MLD_CFG_AR_REVISION_VERSION != PLATFORM_MLD_TYPESDEF_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Mld_Cfg.h and Platform_Mld_TypesDef.h are different"
#endif
/* Check if current file and Platform_Mld_TypesDef header file are of the same Software version */
#if ((PLATFORM_MLD_CFG_SW_MAJOR_VERSION != PLATFORM_MLD_TYPESDEF_SW_MAJOR_VERSION) || \
     (PLATFORM_MLD_CFG_SW_MINOR_VERSION != PLATFORM_MLD_TYPESDEF_SW_MINOR_VERSION) || \
     (PLATFORM_MLD_CFG_SW_PATCH_VERSION != PLATFORM_MLD_TYPESDEF_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Mld_Cfg.h and Platform_Mld_TypesDef.h are different"
#endif

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/* TBD */


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/* Definition of the configuration structure for Platform MLD */
extern const Platform_Mld_ConfigType MldConfig;



#endif /* PLATFORM_MLD_CFG_H_ */

