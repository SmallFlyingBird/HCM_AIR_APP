/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Mpu_Lld_Cfg.h
 * @brief 
 * 
 */


#ifndef MPU_LLD_CFG_H_
#define MPU_LLD_CFG_H_

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "Mpu_Lld_M33_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MPU_LLD_CFG_VENDOR_ID           (180)
#define MPU_LLD_CFG_SW_MAJOR_VERSION    (2)
#define MPU_LLD_CFG_SW_MINOR_VERSION    (3)
#define MPU_LLD_CFG_SW_PATCH_VERSION    (0)

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
extern const Mpu_Lld_M33_ConfigType MpuConfig;

#endif /* MPU_LLD_CFG_H_ */

