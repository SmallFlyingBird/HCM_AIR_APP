/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Mpu_Lld_Cfg.c
 * @brief 
 * 
 */


#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "Mpu_Lld_Cfg.h"

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

#define MPU_LLD_CFG_VENDOR_ID_C                     (180)
#define MPU_LLD_CFG_AR_RELEASE_MAJOR_VERSION_C      (4)
#define MPU_LLD_CFG_AR_RELEASE_MINOR_VERSION_C      (4)
#define MPU_LLD_CFG_AR_RELEASE_REVISION_VERSION_C   (0)
#define MPU_LLD_CFG_SW_MAJOR_VERSION_C              (2)
#define MPU_LLD_CFG_SW_MINOR_VERSION_C              (3)
#define MPU_LLD_CFG_SW_PATCH_VERSION_C              (0)

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"


/* The configuration of M33 MPU attribute MpuM33Config_Core0 */
PLATFORM_CONST const Mpu_Lld_M33_AttrCfgType MpuM33AttributeConfig_MpuM33Config_Core0[2U] = 
{
    {
        /* AttributeConfig_Normal */
        .AttributeIndex = 0U,
        .Attribute = (uint8)(MPU_LLD_M33_OUTER(MPU_M33_CACHE_POLICY_NORMAL_NO_CACHE) | MPU_LLD_M33_INNER(MPU_M33_CACHE_POLICY_NORMAL_NO_CACHE)),
    },
    {
        /* AttributeConfig_Device */
        .AttributeIndex = 1U,
        .Attribute = (uint8)(MPU_LLD_M33_OUTER(MPU_M33_CACHE_POLICY_DEVICE) | MPU_LLD_M33_INNER(MPU_M33_CACHE_POLICY_DEVICE_NGNRNE)),
    },
};

/* The configuration of M33 MPU region MpuM33Config_Core0 */
PLATFORM_CONST const Mpu_Lld_M33_RegionCfgType MpuM33RegionConfig_MpuM33Config_Core0[3U] = 
{
    {
        /* RegionConfig_NVR */
        .RegionIndex = 1U,
        {
            .RBAR = ARM_MPU_RBAR
            (
                0x10000000U,
                MPU_M33_MEM_NORMAL_NOSHARE,
                MPU_LLD_M33_RO(MPU_M33_PRIV_RW_UNPRIV_NONE),
                MPU_LLD_M33_NP(MPU_M33_PRIV_RW_UNPRIV_NONE),
                MPU_LLD_M33_XN(MPU_M33_PRIV_RW_UNPRIV_NONE)
            ),
            .RLAR = ARM_MPU_RLAR
            (
                0x100007ffU,
                0U
            )
        }
    },
    {
        /* RegionConfig_APB0 */
        .RegionIndex = 3U,
        {
            .RBAR = ARM_MPU_RBAR
            (
                0x40000000U,
                MPU_M33_MEM_NORMAL_NOSHARE,
                MPU_LLD_M33_RO(MPU_M33_PRIV_RW_UNPRIV_NONE),
                MPU_LLD_M33_NP(MPU_M33_PRIV_RW_UNPRIV_NONE),
                MPU_LLD_M33_XN(MPU_M33_PRIV_RW_UNPRIV_NONE)
            ),
            .RLAR = ARM_MPU_RLAR
            (
                0x4007ffffU,
                1U
            )
        }
    },
    {
        /* RegionConfig_PPB */
        .RegionIndex = 4U,
        {
            .RBAR = ARM_MPU_RBAR
            (
                0xe0000000U,
                MPU_M33_MEM_NORMAL_NOSHARE,
                MPU_LLD_M33_RO(MPU_M33_PRIV_RW_UNPRIV_NONE),
                MPU_LLD_M33_NP(MPU_M33_PRIV_RW_UNPRIV_NONE),
                MPU_LLD_M33_XN(MPU_M33_PRIV_RW_UNPRIV_NONE)
            ),
            .RLAR = ARM_MPU_RLAR
            (
                0xe00fffffU,
                1U
            )
        }
    },
};

/* The configuration of MPU MpuM33Config_Core0 */
PLATFORM_CONST const Mpu_Lld_M33_ConfigType MpuConfig = 
{
    .DefaultMapEn = TRUE,
    .RunHFNMIEn = FALSE,
    .MemManageIrqEn = TRUE,
    .AttributeCount = 2U,
    .AttributeConfig = MpuM33AttributeConfig_MpuM33Config_Core0,
    .RegionCount = 3U,
    .RegionConfig = MpuM33RegionConfig_MpuM33Config_Core0
};

#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

#ifdef __cplusplus
}
#endif

