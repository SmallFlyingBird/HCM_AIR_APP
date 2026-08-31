/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file undefined
 * @brief 
 * 
 */


#ifndef PWM_LLD_ETMR_CFG_H
#define PWM_LLD_ETMR_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                          INCLUDE FILES                                        
==================================================================================================*/
#include "Std_Types.h"

/*==================================================================================================
 *                                SOURCE FILE VERSION INFORMATION                                
==================================================================================================*/
#define PWM_LLD_ETMR_VENDOR_ID_CFG                      (180)
#define PWM_LLD_ETMR_AR_RELEASE_MAJOR_VERSION_CFG       (4)
#define PWM_LLD_ETMR_AR_RELEASE_MINOR_VERSION_CFG       (4)
#define PWM_LLD_ETMR_AR_RELEASE_REVISION_VERSION_CFG    (0)
#define PWM_LLD_ETMR_SW_MAJOR_VERSION_CFG               (2)
#define PWM_LLD_ETMR_SW_MINOR_VERSION_CFG               (3)
#define PWM_LLD_ETMR_SW_PATCH_VERSION_CFG               (0)

/*==================================================================================================
 *                                       DEFINES AND MACROS                                       
==================================================================================================*/
/**
 * @brief   Switch to enable the development error detection.
 */
#define PWM_LLD_ETMR_DEV_ERROR_DETECT   STD_OFF

/**
 * @brief   eTMR timeout count
 */
#define PWM_LLD_ETMR_TIMEOUT_COUNT      (65535U)

/**
 * @brief   eTMR has deadtime prescaler or not.
 */
#define PWM_LLD_ETMR_HAS_DEADTIME_PRESCALER     STD_OFF

/**
 * @brief   eTMR has output trigger width or not.
 */
#define PWM_LLD_ETMR_HAS_OUTPUT_TRIGGER_WIDTH   STD_ON

/**
 * @brief   eTMR has MID match trigger or not.
 */
#define PWM_LLD_ETMR_HAS_MID_MATCH_TRIGGER      STD_ON

/**
 * @brief   eTMR has INIT match trigger or not.
 */
#define PWM_LLD_ETMR_HAS_INIT_MATCH_TRIGGER     STD_ON

#ifdef __cplusplus
}
#endif

#endif /* PWM_LLD_ETMR_CFG_H */

