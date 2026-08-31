/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Gpt_PBcfg.c
 * @brief 
 * 
 */


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Gpt_PBcfg.h"
#include "Gpt_Types.h"
#include "Gpt_Lld_Lptmr_Types.h"
#include "Gpt_Lld_Ptmr_Types.h"
#if (GPT_TMR_MODULE_USED == STD_ON)
#include "Gpt_Lld_Tmr_Types.h"
#endif
#if (GPT_RTC_MODULE_USED == STD_ON)
#include "Gpt_Lld_Rtc_Types.h"
#endif
#if(GPT_REPORT_WAKEUP_SOURCE == STD_ON)
#include "EcuM.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_VENDOR_ID_PBCFG_C                      (180)
#define GPT_AR_RELEASE_MAJOR_VERSION_PBCFG_C       (4)
#define GPT_AR_RELEASE_MINOR_VERSION_PBCFG_C       (4)
#define GPT_AR_RELEASE_REVISION_VERSION_PBCFG_C    (0)
#define GPT_SW_MAJOR_VERSION_PBCFG_C               (2)
#define GPT_SW_MINOR_VERSION_PBCFG_C               (3)
#define GPT_SW_PATCH_VERSION_PBCFG_C               (0)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Gpt_PBcfg.c and Gpt_PBcfg.h are of the same vendor */
#if (GPT_VENDOR_ID_PBCFG_C != GPT_VENDOR_ID_PBCFG)
#error "Gpt_PBcfg.c and Gpt_PBcfg.h have different vendor IDs"
#endif
    /* Check if Gpt_PBcfg.c and Gpt_PBcfg.h are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION_PBCFG_C != GPT_AR_RELEASE_MAJOR_VERSION_PBCFG) || \
     (GPT_AR_RELEASE_MINOR_VERSION_PBCFG_C != GPT_AR_RELEASE_MINOR_VERSION_PBCFG) || \
     (GPT_AR_RELEASE_REVISION_VERSION_PBCFG_C != GPT_AR_RELEASE_REVISION_VERSION_PBCFG) \
    )
#error "AutoSar Version Numbers of Gpt_PBcfg.c and Gpt_PBcfg.h are different"
#endif
/* Check if Gpt_PBcfg.c and Gpt_PBcfg.h are of the same software version */
#if ((GPT_SW_MAJOR_VERSION_PBCFG_C != GPT_SW_MAJOR_VERSION_PBCFG) || \
     (GPT_SW_MINOR_VERSION_PBCFG_C != GPT_SW_MINOR_VERSION_PBCFG) || \
     (GPT_SW_PATCH_VERSION_PBCFG_C != GPT_SW_PATCH_VERSION_PBCFG) \
    )
#error "Software Version Numbers of Gpt_PBcfg.c and Gpt_PBcfg.h are different"
#endif

/*==================================================================================================
*                                       GPT CHANNEL CONFIGURATIONS
==================================================================================================*/

#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"

/**
 * @brief   Convert configuration channelId to channelIndex
 */
GPT_CONST const uint8 GptChannelIdToIndexMap[GPT_PBCFG_CHANNELS_COUNT] = {0,};

/**
 * @brief   Gpt channels configuration hw Id
 */
GPT_CONST static const Gpt_HwChannelConfigType GptHwChannelConfig0 =
{
    .InstanceType = GPT_HW_MODULE_PTMR,
    .HwInstanceId = 0,
    .HwChannelId = 0,
};

/**
 * @brief   Gpt channels configuration array
 */
GPT_CONST static const Gpt_ChannelConfigType Gpt_ChannelConfigs[GPT_PBCFG_CHANNELS_COUNT] =
{    /* GptChannelConfiguration_0 */
    {
        .ChannelId = 0U,
        .TickFrequency = 40000000,
        .TickValueMax = 4294967295,
        .CountMode = GPT_CH_MODE_CONTINUOUS,
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
        .EnableWakeup = STD_OFF,
#endif
        .GptHwChannelConfig = &GptHwChannelConfig0,
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
        .NotificationPtr = Gpt_Notification_GptChannelConfiguration_0,
#endif
#if(GPT_REPORT_WAKEUP_SOURCE == STD_ON)
        .WakeupSource = (EcuM_WakeupSourceType)0,
#endif
    },
};


/**
 * @brief   Lptmr instance configuration
 */

/**
 * @brief   Ptmr instance configuration
 */
GPT_CONST const Ptmr_InstanceConfigType Gpt_Lld_Ptmr_InstCfg_Inst0 =
{
    .InstanceId = 0,
    .StopInDebugMode = TRUE,
};

/**
 * @brief   Tmr instance configuration
 */

/**
 * @brief   Rtc instance configuration
 */


/**
 * @brief   Gpt instances configuration array
 */
GPT_CONST static const Gpt_InstanceConfigType Gpt_InstanceConfigs[GPT_PBCFG_INSTANCES_COUNT] =
{
/* GptPtmr_0 */
    {
        .InstanceType = GPT_HW_MODULE_PTMR,
        .HwInstanceId = 0U,
        .PtmrInstCfg = &Gpt_Lld_Ptmr_InstCfg_Inst0
    },
};

/**
 * @brief   Gpt Config
 */
GPT_CONST const Gpt_ConfigType Gpt_Config =
{
    .UsedInstanceCount = GPT_PBCFG_INSTANCES_COUNT,
    .UsedChannelCount = GPT_PBCFG_CHANNELS_COUNT,
    .InstanceConfig = &Gpt_InstanceConfigs,
    .ChannelConfig = &Gpt_ChannelConfigs,
    .ChannelIdToIndexMap = &GptChannelIdToIndexMap,
};

#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"

/*==================================================================================================
*                                       CONSTANTS
==================================================================================================*/


/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

