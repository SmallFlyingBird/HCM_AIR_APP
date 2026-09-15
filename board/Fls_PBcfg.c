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

#include "Fls_Types.h"
#include "Platform_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_VENDOR_ID_PBCFG_C                      (180)
#define FLS_AR_RELEASE_MAJOR_VERSION_PBCFG_C       (4)
#define FLS_AR_RELEASE_MINOR_VERSION_PBCFG_C       (4)
#define FLS_AR_RELEASE_REVISION_VERSION_PBCFG_C    (0)
#define FLS_SW_MAJOR_VERSION_PBCFG_C               (2)
#define FLS_SW_MINOR_VERSION_PBCFG_C               (3)
#define FLS_SW_PATCH_VERSION_PBCFG_C               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/*==================================================================================================
 *                                       Function Prototypes
==================================================================================================*/

#define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"
/*================================================================================================== */
/* One configuration entry per 1 KB physical sector. Fee keeps its 4 KB banks. */
FLS_CONST const Fls_SectorType Fls_SectorConfig[8] ={
    {
        .SectorId = FlsConf_FlsConfigSet_FlsSector_0,
        .SectorStartAddress = 0x0000U,
        .SectorSize = 0x400U,
        .PageSize = 0x8U,
        .SectorHwStartAddress = 0x7c000U,
        .PhySectorSize = 0x400U,
        .AsyncAccess = FALSE,
        .SectorHwCh = FLS_CH_INTERN,
    },
    {
        .SectorId = FlsConf_FlsConfigSet_FlsSector_1,
        .SectorStartAddress = 0x0400U,
        .SectorSize = 0x400U,
        .PageSize = 0x8U,
        .SectorHwStartAddress = 0x7c400U,
        .PhySectorSize = 0x400U,
        .AsyncAccess = FALSE,
        .SectorHwCh = FLS_CH_INTERN,
    },
    {
        .SectorId = FlsConf_FlsConfigSet_FlsSector_2,
        .SectorStartAddress = 0x0800U,
        .SectorSize = 0x400U,
        .PageSize = 0x8U,
        .SectorHwStartAddress = 0x7c800U,
        .PhySectorSize = 0x400U,
        .AsyncAccess = FALSE,
        .SectorHwCh = FLS_CH_INTERN,
    },
    {
        .SectorId = FlsConf_FlsConfigSet_FlsSector_3,
        .SectorStartAddress = 0x0c00U,
        .SectorSize = 0x400U,
        .PageSize = 0x8U,
        .SectorHwStartAddress = 0x7cc00U,
        .PhySectorSize = 0x400U,
        .AsyncAccess = FALSE,
        .SectorHwCh = FLS_CH_INTERN,
    },
    {
        .SectorId = FlsConf_FlsConfigSet_FlsSector_4,
        .SectorStartAddress = 0x1000U,
        .SectorSize = 0x400U,
        .PageSize = 0x8U,
        .SectorHwStartAddress = 0x7d000U,
        .PhySectorSize = 0x400U,
        .AsyncAccess = FALSE,
        .SectorHwCh = FLS_CH_INTERN,
    },
    {
        .SectorId = FlsConf_FlsConfigSet_FlsSector_5,
        .SectorStartAddress = 0x1400U,
        .SectorSize = 0x400U,
        .PageSize = 0x8U,
        .SectorHwStartAddress = 0x7d400U,
        .PhySectorSize = 0x400U,
        .AsyncAccess = FALSE,
        .SectorHwCh = FLS_CH_INTERN,
    },
    {
        .SectorId = FlsConf_FlsConfigSet_FlsSector_6,
        .SectorStartAddress = 0x1800U,
        .SectorSize = 0x400U,
        .PageSize = 0x8U,
        .SectorHwStartAddress = 0x7d800U,
        .PhySectorSize = 0x400U,
        .AsyncAccess = FALSE,
        .SectorHwCh = FLS_CH_INTERN,
    },
    {
        .SectorId = FlsConf_FlsConfigSet_FlsSector_7,
        .SectorStartAddress = 0x1c00U,
        .SectorSize = 0x400U,
        .PageSize = 0x8U,
        .SectorHwStartAddress = 0x7dc00U,
        .PhySectorSize = 0x400U,
        .AsyncAccess = FALSE,
        .SectorHwCh = FLS_CH_INTERN,
    },
};

FLS_CONST const Fls_SectorProtectType Fls_SectorProtectConfig[FLS_INTERNAL_BLOCK_NUM] ={

    0x0U,
    0x0U,
};


FLS_CONST const Fls_ConfigType Fls_Config = {
    .AcEraseFunPtr = NULL_PTR,
    .AcWriteFunPtr = NULL_PTR,
    .JobEndNotificationFunPtr = NULL_PTR,
    .JobErrorNotificationFunPtr = NULL_PTR,
    .DefaultMode = MEMIF_MODE_SLOW,
    .MaxReadFastMode = 10240U,
    .MaxReadNormalMode = 1024U,
    .MaxWriteFastMode = 256U,
    .MaxWriteNormalMode = 128U, /* 1 KB payload: 8 calls at the 5 ms task period. */
    .ConfiguredSectorNumber = 8U,
    .SectorList = Fls_SectorConfig,
    .SectorProtection = Fls_SectorProtectConfig,
};

#define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"

