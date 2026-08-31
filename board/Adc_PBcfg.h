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


#ifndef ADC_PB_CFG_H
#define ADC_PB_CFG_H


/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_VENDOR_ID_PBCFG                      (180)
#define ADC_AR_RELEASE_MAJOR_VERSION_PBCFG       (4)
#define ADC_AR_RELEASE_MINOR_VERSION_PBCFG       (4)
#define ADC_AR_RELEASE_REVISION_VERSION_PBCFG    (0)
#define ADC_SW_MAJOR_VERSION_PBCFG               (2)
#define ADC_SW_MINOR_VERSION_PBCFG               (3)
#define ADC_SW_PATCH_VERSION_PBCFG               (0)


/**
*@brief AdcGroup_0 Group index ，channel number and channel index
*/
#define AdcConf_AdcConfigSet_AdcGroup_0                (0U)

#define AdcGroup_0_CHANNEL_NUMBER             (7U)

/**
*@brief AdcGroup_1 Group index ，channel number and channel index
*/
#define AdcConf_AdcConfigSet_AdcGroup_1                (1U)

#define AdcGroup_1_CHANNEL_NUMBER             (3U)



#define ADC_CONFIG_PB \
    extern const Adc_ConfigType Adc_Config;

#endif

