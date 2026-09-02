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


#ifndef FLS_PB_CFG_H
#define FLS_PB_CFG_H


/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_VENDOR_ID_PBCFG                      (180)
#define FLS_AR_RELEASE_MAJOR_VERSION_PBCFG       (4)
#define FLS_AR_RELEASE_MINOR_VERSION_PBCFG       (4)
#define FLS_AR_RELEASE_REVISION_VERSION_PBCFG    (0)
#define FLS_SW_MAJOR_VERSION_PBCFG               (2)
#define FLS_SW_MINOR_VERSION_PBCFG               (3)
#define FLS_SW_PATCH_VERSION_PBCFG               (0)
/**
 * @brief        Index of the driver.
*/
#define FlsConf_FlsGeneral_FlsDriverIndex    (0U)
/**
 * @brief        The index num of fls sector which difined in Fls_PBcfg.c.
 * @details
 * @ref          
 */
#define FlsConf_FlsConfigSet_FlsSector_0    (0U)
#define FlsConf_FlsConfigSet_FlsSector_1    (1U)
#define FlsConf_FlsConfigSet_FlsSector_2    (2U)
#define FlsConf_FlsConfigSet_FlsSector_3    (3U)
#define FlsConf_FlsConfigSet_FlsSector_4    (4U)


#define FLS_CONFIG_PB \
    extern const Fls_ConfigType Fls_Config;

#endif

