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


#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Pwm_PBcfg.h"
#include "Pwm_Lld_Etmr_PBcfg.h"

/*==================================================================================================
 *                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_VENDOR_ID_PBCFG_C                      (180)
#define PWM_AR_RELEASE_MAJOR_VERSION_PBCFG_C       (4)
#define PWM_AR_RELEASE_MINOR_VERSION_PBCFG_C       (4)
#define PWM_AR_RELEASE_REVISION_VERSION_PBCFG_C    (0)
#define PWM_SW_MAJOR_VERSION_PBCFG_C               (2)
#define PWM_SW_MINOR_VERSION_PBCFG_C               (3)
#define PWM_SW_PATCH_VERSION_PBCFG_C               (0)

/*==================================================================================================
 *                                        GLOBAL CONSTANTS                                        
==================================================================================================*/
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

/**
 * @brief   PWM channels configuration array
 */
PWM_CONST static const Pwm_ChannelConfigType Pwm_ChannelConfigs[PWM_PBCFG_CHANNELS_COUNT] = 
{
/* TRK_CC_BOOST */
    {
        .ChannelId = 0U,
        .ChannelClass = PWM_VARIABLE_PERIOD,
        .MldChCfg = 
        {
            .ChInstId = PWM_LLD_ETMR_INST_ID_ETMR_0_CH_6,
            .ChType = PWM_MLD_CHN_ETMR,
            .ChDutyCycle = 0U,
            .EtmrChCfg = &Pwm_Lld_Etmr_ChCfg_Inst0_Ch6
        },
        .ChannelIdleState = PWM_LOW,
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        .ChannelNotification = NULL_PTR
#endif
    },
/* DC_Ctr */
    {
        .ChannelId = 1U,
        .ChannelClass = PWM_VARIABLE_PERIOD,
        .MldChCfg = 
        {
            .ChInstId = PWM_LLD_ETMR_INST_ID_ETMR_1_CH_7,
            .ChType = PWM_MLD_CHN_ETMR,
            .ChDutyCycle = 0U,
            .EtmrChCfg = &Pwm_Lld_Etmr_ChCfg_Inst1_Ch7
        },
        .ChannelIdleState = PWM_LOW,
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        .ChannelNotification = NULL_PTR
#endif
    },
/* HL_Ctrl */
    {
        .ChannelId = 2U,
        .ChannelClass = PWM_VARIABLE_PERIOD,
        .MldChCfg = 
        {
            .ChInstId = PWM_LLD_ETMR_INST_ID_ETMR_1_CH_6,
            .ChType = PWM_MLD_CHN_ETMR,
            .ChDutyCycle = 0U,
            .EtmrChCfg = &Pwm_Lld_Etmr_ChCfg_Inst1_Ch6
        },
        .ChannelIdleState = PWM_LOW,
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        .ChannelNotification = NULL_PTR
#endif
    },
/* Trigger_Ctrl2 */
    {
        .ChannelId = 3U,
        .ChannelClass = PWM_VARIABLE_PERIOD,
        .MldChCfg = 
        {
            .ChInstId = PWM_LLD_ETMR_INST_ID_ETMR_3_CH_0,
            .ChType = PWM_MLD_CHN_ETMR,
            .ChDutyCycle = 0U,
            .EtmrChCfg = &Pwm_Lld_Etmr_ChCfg_Inst3_Ch0
        },
        .ChannelIdleState = PWM_LOW,
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        .ChannelNotification = NULL_PTR
#endif
    },
/* TL_Ctrl */
    {
        .ChannelId = 4U,
        .ChannelClass = PWM_VARIABLE_PERIOD,
        .MldChCfg = 
        {
            .ChInstId = PWM_LLD_ETMR_INST_ID_ETMR_3_CH_3,
            .ChType = PWM_MLD_CHN_ETMR,
            .ChDutyCycle = 0U,
            .EtmrChCfg = &Pwm_Lld_Etmr_ChCfg_Inst3_Ch3
        },
        .ChannelIdleState = PWM_LOW,
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        .ChannelNotification = NULL_PTR
#endif
    },
};

/**
 * @brief   PWM instances configuration array
 */
PWM_CONST static const Pwm_Mld_InstCfgType Pwm_InstanceConfigs[PWM_PBCFG_INSTANCES_COUNT] =
{
/* PwmEtmr_0 */
    {
        .InstId = 0U,
        .InstType = PWM_MLD_INST_ETMR,
        .EtmrInstCfg = &Pwm_Lld_Etmr_InstCfg_Inst0
    },
/* PwmEtmr_1 */
    {
        .InstId = 1U,
        .InstType = PWM_MLD_INST_ETMR,
        .EtmrInstCfg = &Pwm_Lld_Etmr_InstCfg_Inst1
    },
/* PwmEtmr_3 */
    {
        .InstId = 3U,
        .InstType = PWM_MLD_INST_ETMR,
        .EtmrInstCfg = &Pwm_Lld_Etmr_InstCfg_Inst3
    },
};

/**
 * @brief   PWM configuration
 */
PWM_CONST const Pwm_ConfigType Pwm_Config = 
{
    .ChannelCount = PWM_PBCFG_CHANNELS_COUNT,
    .PwmChannelsConfig = &Pwm_ChannelConfigs,
    .InstanceCount = PWM_PBCFG_INSTANCES_COUNT,   
    .PwmInstancesConfig = &Pwm_InstanceConfigs
};

#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

