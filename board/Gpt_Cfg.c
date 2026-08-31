/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Gpt_Cfg.c
 * @brief 
 * 
 */


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Gpt_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_VENDOR_ID_CFG_C                      (180)
#define GPT_AR_RELEASE_MAJOR_VERSION_CFG_C       (4)
#define GPT_AR_RELEASE_MINOR_VERSION_CFG_C       (4)
#define GPT_AR_RELEASE_REVISION_VERSION_CFG_C    (0)
#define GPT_SW_MAJOR_VERSION_CFG_C               (2)
#define GPT_SW_MINOR_VERSION_CFG_C               (3)
#define GPT_SW_PATCH_VERSION_CFG_C               (0)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Gpt_Cfg.c and Gpt_Cfg.h are of the same vendor */
#if (GPT_VENDOR_ID_CFG_C != GPT_VENDOR_ID_CFG)
#error "Gpt_Cfg.c and Gpt_Cfg.h have different vendor IDs"
#endif
    /* Check if Gpt_Cfg.c and Gpt_Cfg.h are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION_CFG_C != GPT_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (GPT_AR_RELEASE_MINOR_VERSION_CFG_C != GPT_AR_RELEASE_MINOR_VERSION_CFG) || \
     (GPT_AR_RELEASE_REVISION_VERSION_CFG_C != GPT_AR_RELEASE_REVISION_VERSION_CFG) \
    )
#error "AutoSar Version Numbers of Gpt_Cfg.c and Gpt_Cfg.h are different"
#endif
/* Check if Gpt_Cfg.c and Gpt_Cfg.h are of the same software version */
#if ((GPT_SW_MAJOR_VERSION_CFG_C != GPT_SW_MAJOR_VERSION_CFG) || \
     (GPT_SW_MINOR_VERSION_CFG_C != GPT_SW_MINOR_VERSION_CFG) || \
     (GPT_SW_PATCH_VERSION_CFG_C != GPT_SW_PATCH_VERSION_CFG) \
    )
#error "Software Version Numbers of Gpt_Cfg.c and Gpt_Cfg.h are different"
#endif

#ifdef __cplusplus
}
#endif

/** @} */

