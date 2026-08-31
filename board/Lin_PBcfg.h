/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Lin_PBcfg.h
 * @brief 
 * 
 */


#ifndef LIN_PB_CFG_H
#define LIN_PB_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Lin_GeneralTypes.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LIN_VENDOR_ID_PBCFG                      (180)
#define LIN_AR_RELEASE_MAJOR_VERSION_PBCFG       (4)
#define LIN_AR_RELEASE_MINOR_VERSION_PBCFG       (4)
#define LIN_AR_RELEASE_REVISION_VERSION_PBCFG    (0)
#define LIN_SW_MAJOR_VERSION_PBCFG               (2)
#define LIN_SW_MINOR_VERSION_PBCFG               (3)
#define LIN_SW_PATCH_VERSION_PBCFG               (0)

/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
#define LIN_CONFIG_PB \
    extern const Lin_ConfigType Lin_Config;
#define LIN_FIXED_PB_CONFIG             (STD_OFF)

#ifdef __cplusplus
}
#endif

#endif /* LIN_PB_CFG_H */

/** @} */

