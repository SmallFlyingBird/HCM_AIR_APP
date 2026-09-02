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
FLS_CONST const Fls_SectorType Fls_SectorConfig[5] ={
    {
        .SectorId = FlsConf_FlsConfigSet_FlsSector_0,
        .SectorStartAddress = 0x0U,
        .SectorSize = 0x400U,
        .PageSize = 0x8U,
        .SectorHwStartAddress = 0x78000U,
        .PhySectorSize = 0x400U,
        .AsyncAccess = TRUE,
        .SectorHwCh = FLS_CH_INTERN,
    },
    {
        .SectorId = FlsConf_FlsConfigSet_FlsSector_1,
        .SectorStartAddress = 0x400U,
        .SectorSize = 0x400U,
        .PageSize = 0x8U,
        .SectorHwStartAddress = 0x7f000U,
        .PhySectorSize = 0x400U,
        .AsyncAccess = TRUE,
        .SectorHwCh = FLS_CH_INTERN,
    },
    {
        .SectorId = FlsConf_FlsConfigSet_FlsSector_2,
        .SectorStartAddress = 0x800U,
        .SectorSize = 0x400U,
        .PageSize = 0x8U,
        .SectorHwStartAddress = 0x7f400U,
        .PhySectorSize = 0x400U,
        .AsyncAccess = TRUE,
        .SectorHwCh = FLS_CH_INTERN,
    },
    {
        .SectorId = FlsConf_FlsConfigSet_FlsSector_3,
        .SectorStartAddress = 0xc00U,
        .SectorSize = 0x400U,
        .PageSize = 0x8U,
        .SectorHwStartAddress = 0x7f800U,
        .PhySectorSize = 0x400U,
        .AsyncAccess = TRUE,
        .SectorHwCh = FLS_CH_INTERN,
    },
    {
        .SectorId = FlsConf_FlsConfigSet_FlsSector_4,
        .SectorStartAddress = 0x1000U,
        .SectorSize = 0x400U,
        .PageSize = 0x8U,
        .SectorHwStartAddress = 0x7fc00U,
        .PhySectorSize = 0x400U,
        .AsyncAccess = TRUE,
        .SectorHwCh = FLS_CH_INTERN,
    },
};

FLS_CONST const Fls_SectorProtectType Fls_SectorProtectConfig[FLS_INTERNAL_BLOCK_NUM] ={
                                
    0x1U,
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
    .MaxWriteNormalMode = 8U,
    .ConfiguredSectorNumber = 5U,
    .SectorList = Fls_SectorConfig,
    .SectorProtection = Fls_SectorProtectConfig,
};

#define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"

