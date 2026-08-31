/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Gpt_PBcfg.h
 * @brief 
 * 
 */


#ifndef GPT_PB_CFG_H
#define GPT_PB_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Gpt_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_VENDOR_ID_PBCFG                      (180)
#define GPT_AR_RELEASE_MAJOR_VERSION_PBCFG       (4)
#define GPT_AR_RELEASE_MINOR_VERSION_PBCFG       (4)
#define GPT_AR_RELEASE_REVISION_VERSION_PBCFG    (0)
#define GPT_SW_MAJOR_VERSION_PBCFG               (2)
#define GPT_SW_MINOR_VERSION_PBCFG               (3)
#define GPT_SW_PATCH_VERSION_PBCFG               (0)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Gpt_PBcfg.h and Gpt_Cfg.h are of the same vendor */
#if (GPT_VENDOR_ID_PBCFG != GPT_VENDOR_ID_CFG)
#error "Gpt_PBcfg.h and Gpt_Cfg.h have different vendor IDs"
#endif
    /* Check if Gpt_PBcfg.h and Gpt_Cfg.h are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION_PBCFG != GPT_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (GPT_AR_RELEASE_MINOR_VERSION_PBCFG != GPT_AR_RELEASE_MINOR_VERSION_CFG) || \
     (GPT_AR_RELEASE_REVISION_VERSION_PBCFG != GPT_AR_RELEASE_REVISION_VERSION_CFG) \
    )
#error "AutoSar Version Numbers of Gpt_PBcfg.h and Gpt_Cfg.h are different"
#endif
/* Check if Gpt_PBcfg.h and Gpt_Cfg.h are of the same software version */
#if ((GPT_SW_MAJOR_VERSION_PBCFG != GPT_SW_MAJOR_VERSION_CFG) || \
     (GPT_SW_MINOR_VERSION_PBCFG != GPT_SW_MINOR_VERSION_CFG) || \
     (GPT_SW_PATCH_VERSION_PBCFG != GPT_SW_PATCH_VERSION_CFG) \
    )
#error "Software Version Numbers of Gpt_PBcfg.h and Gpt_Cfg.h are different"
#endif

/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
#define GPT_CONFIG_PB \
    extern const Gpt_ConfigType Gpt_Config;

/**
 * @brief    Total number of configured GPT channels
 */
#define GPT_PBCFG_CHANNELS_COUNT    (1U)

/**
 * @brief    Total number of configured GPT instances
 */
#define GPT_PBCFG_INSTANCES_COUNT (1)

/*==================================================================================================
 *                                   FUNCTION PROTOTYPES
==================================================================================================*/

/**
 * @brief Gpt Notification for the GptChannelConfiguration_0 channel.
 */
void Gpt_Notification_GptChannelConfiguration_0(void);

#ifdef __cplusplus
}
#endif

#endif /* GPT_PB_CFG_H */

/** @} */

