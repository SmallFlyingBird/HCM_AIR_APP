/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Icu_Mld_Cfg.h
 * @brief 
 * 
 */


#ifndef ICU_MLD_CFG_H
#define ICU_MLD_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_MLD_CFG_VENDOR_ID                      (180)
#define ICU_MLD_CFG_AR_RELEASE_MAJOR_VERSION       (4)
#define ICU_MLD_CFG_AR_RELEASE_MINOR_VERSION       (4)
#define ICU_MLD_CFG_AR_RELEASE_REVISION_VERSION    (0)
#define ICU_MLD_CFG_SW_MAJOR_VERSION               (2)
#define ICU_MLD_CFG_SW_MINOR_VERSION               (3)
#define ICU_MLD_CFG_SW_PATCH_VERSION               (0)

/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
/**
 * @brief   ETMR is used as ICU or not
 */
#define ICU_ETMR_USED    (STD_ON)

/**
 * @brief   MPWM is used as ICU or not
 */
#define ICU_MPWM_USED    (STD_OFF)

/**
 * @brief   Port is used as ICU or not
 */
#define ICU_PORT_USED    (STD_OFF)

/**
 * @brief   ACMP is used as ICU or not
 */
#define ICU_ACMP_USED    (STD_OFF)

#ifdef __cplusplus
}
#endif

#endif /* ICU_MLD_CFG_H */

/** @} */

