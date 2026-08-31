/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Lin_PBcfg.c
 * @brief 
 * 
 */


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Lin.h"
#if (LIN_IP_UART == STD_ON)
#include "Lin_Lld_Uart.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LIN_VENDOR_ID_PBCFG_C                      (180)
#define LIN_AR_RELEASE_MAJOR_VERSION_PBCFG_C       (4)
#define LIN_AR_RELEASE_MINOR_VERSION_PBCFG_C       (4)
#define LIN_AR_RELEASE_REVISION_VERSION_PBCFG_C    (0)
#define LIN_SW_MAJOR_VERSION_PBCFG_C               (2)
#define LIN_SW_MINOR_VERSION_PBCFG_C               (3)
#define LIN_SW_PATCH_VERSION_PBCFG_C               (0)

/*==================================================================================================
*                                       CONSTANTS
==================================================================================================*/

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"


#define LIN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_MemMap.h"



LIN_CONST const uint8 LinInstMap[LIN_CONST_THEORETICAL_MAX_CHANNEL_NUM] = { 255U, 0U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,  };

LIN_CONST const Lin_ChConfigType LinChConfig[1] =
{
    {
        .LinChannelId = 0U,
        .LinHwChannel = LINFLEXD_IP_1,
        .LinNodeMode = LIN_SLAVE_MODE,
        .LinChWakeSupport = FALSE,
        .LinChEcuMWakeupSource = (EcuM_WakeupSourceType)0,
        .LinChBreakLength = MASTER_13_BIT_BREAK_LENGTH,
        .LinDetectBreakLength = SLAVE_11_BIT_BREAK_LENGTH,
        .LinClockRef = 120000000U,
        .ResponseTimeoutValue = 14U,
        .HeaderTimeoutValue = 44U,
        .LinBaudrateRegValue = 19200U,
        .LinFilterEnable = FALSE,
        .LinFilterNum = 0U,
        .LinFilterIdPtr = NULL_PTR
    },
};

#if (LIN_DEM_DISABLE == STD_OFF)
#endif /* (LIN_DEM_DISABLE == STD_OFF) */

LIN_CONST const Lin_ConfigType Lin_Config =
{
    .LinChCount = 1,
    .LinChConfigPtrs = &LinChConfig[0],
    .LinInstMapPtr = &LinInstMap[0],
#if (LIN_DEM_DISABLE == STD_OFF)
    .LinDemConfigPtr = NULL_PTR,
#endif /* (LIN_DEM_DISABLE == STD_OFF) */
};

#define LIN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Lin_MemMap.h"/*memory map finish*/

#ifdef __cplusplus
}
#endif

/** @} */

