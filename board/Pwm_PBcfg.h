/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Pwm_PBcfg.h
 * @brief 
 * 
 */


#ifndef PWM_PB_CFG_H
#define PWM_PB_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Pwm_Types.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_VENDOR_ID_PBCFG                      (180)
#define PWM_AR_RELEASE_MAJOR_VERSION_PBCFG       (4)
#define PWM_AR_RELEASE_MINOR_VERSION_PBCFG       (4)
#define PWM_AR_RELEASE_REVISION_VERSION_PBCFG    (0)
#define PWM_SW_MAJOR_VERSION_PBCFG               (2)
#define PWM_SW_MINOR_VERSION_PBCFG               (3)
#define PWM_SW_PATCH_VERSION_PBCFG               (0)

/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
/**
 * @brief    Total number of configured PWM channels
 */
#define PWM_PBCFG_CHANNELS_COUNT    (2U)

/**
 * @brief    Total number of configured PWM instances
 */
#define PWM_PBCFG_INSTANCES_COUNT   (2U)

/*==================================================================================================
 *                                  GLOBAL CONSTANT DECLARATIONS
==================================================================================================*/
#define PWM_CONFIG_PB \
    extern const Pwm_ConfigType Pwm_Config;

/*==================================================================================================
 *                                   FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* PWM_PB_CFG_H */

/** @} */

