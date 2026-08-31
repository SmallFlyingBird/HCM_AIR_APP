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

#include "Adc.h"
#include "Adc_Cfg.h"
#ifdef ADC_DMA_SUPPORTED
#include "CddDma_Cfg.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_VENDOR_ID_PBCFG_C                      (180)
#define ADC_AR_RELEASE_MAJOR_VERSION_PBCFG_C       (4)
#define ADC_AR_RELEASE_MINOR_VERSION_PBCFG_C       (4)
#define ADC_AR_RELEASE_REVISION_VERSION_PBCFG_C    (0)
#define ADC_SW_MAJOR_VERSION_PBCFG_C               (2)
#define ADC_SW_MINOR_VERSION_PBCFG_C               (3)
#define ADC_SW_PATCH_VERSION_PBCFG_C               (0)

/*================================================================================================== */
/**
 * @brief          Config number of ADC Hw units.
 */
#define ADC_UNIT_NUMBER                         (1U)

/**
 * @brief          Max number of ADC Hw units.
 */
#define ADC_GROUP_NUMBER                        (2U)

/*****************************************************************************************************/
extern void CallBack_AdcGroup0(void); 
extern void CallBack_AdcGroup1(void); 

#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/*Group channels definetion*/
ADC_CONST static const Adc_ChannelType AdcGroup_0_Channel[7] = 
{
    ADC0_SE11_ADCH11,
    ADC0_SE10_ADCH10,
    ADC0_SE15_ADCH15,
    ADC0_SE14_ADCH14,
    ADC0_SE13_ADCH13,
    ADC0_SE12_ADCH12,
    ADC0_SE7_ADCH7,
};
ADC_CONST static const Adc_ChannelType AdcGroup_1_Channel[3] = 
{
    ADC0_SE3_ADCH3,
    ADC0_SE23_ADCH23,
    ADC0_SE0_ADCH0,
};

/**/

ADC_CONST static const Adc_GroupDefType AdcGroup_0_ChannelsInf = 
{
    .GroupChannels       = &AdcGroup_0_Channel[0],
    .GroupChannelsNum    = 7,
    .GroupInHwUnitId     = ADC_0,
};
ADC_CONST static const Adc_GroupDefType AdcGroup_1_ChannelsInf = 
{
    .GroupChannels       = &AdcGroup_1_Channel[0],
    .GroupChannelsNum    = 3,
    .GroupInHwUnitId     = ADC_0,
};


#if (ADC_UNIT_NUMBER != 0)
#if (ADC_UNIT_NUMBER > ADC_MAX_HW_UNITS)
    #error "Config too many ADC Hw Unit !"
#else
ADC_CONST const Adc_HwUnitType Adc_HwUnitConfiguration[ADC_UNIT_NUMBER] = {
{ 
    .HwUnitId = ADC_0,
    .ClockSource = ADC_BUSCLK,
    .Prescale = 0,
        .StartupTime = 25,
    .InternalTempSensor = FALSE,
},
};
#endif /* ADC_UNIT_NUMBER > ADC_MAX_HW_UNITS */
#endif /* ADC_UNIT_NUMBER != 0 */

ADC_CONST const Adc_ChannelSampleType AdcGroup_0_ChannelSample = {
    .ChannelSampTime = 35,
    .ChannelConvTime = 0,
    .ChannelRefVoltsrcHigh = 0,
    .ChannelRefVoltsrcLow = 0,
    .ChannelResolution = ADC_RESOLUTION_12BIT,
};
ADC_CONST const Adc_ChannelSampleType AdcGroup_1_ChannelSample = {
    .ChannelSampTime = 2,
    .ChannelConvTime = 0,
    .ChannelRefVoltsrcHigh = 0,
    .ChannelRefVoltsrcLow = 0,
    .ChannelResolution = ADC_RESOLUTION_12BIT,
};

ADC_CONST const Adc_GroupSampleType AdcGroup_0_Configuration = 
{
    .GroupAccessMode = ADC_ACCESS_MODE_SINGLE,
    .GroupConversionMode = ADC_CONV_MODE_ONESHOT,
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    .GroupPriority = 0,
#endif /* (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) */
    .GroupReplacement = ADC_GROUP_REPL_ABORT_RESTART,
    .GroupTriggSrc = ADC_TRIGG_SRC_SW,
#if (ADC_HW_TRIGGER_API == STD_ON)
    .HwTrigSrc = (Adc_HwTriggerSourceType)0U,
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
    .StreamingBufferMode = ADC_STREAM_BUFFER_LINEAR,
    .StreamingNumSamples = 1,
    .GroupDefinition = &AdcGroup_0_ChannelsInf,
    .NotificationFunc = CallBack_AdcGroup0,
    .IntcAndDmaCfg = ADC_INTC_ENABLED,
};
ADC_CONST const Adc_GroupSampleType AdcGroup_1_Configuration = 
{
    .GroupAccessMode = ADC_ACCESS_MODE_SINGLE,
    .GroupConversionMode = ADC_CONV_MODE_ONESHOT,
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    .GroupPriority = 0,
#endif /* (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) */
    .GroupReplacement = ADC_GROUP_REPL_ABORT_RESTART,
    .GroupTriggSrc = ADC_TRIGG_SRC_SW,
#if (ADC_HW_TRIGGER_API == STD_ON)
    .HwTrigSrc = (Adc_HwTriggerSourceType)0U,
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
    .StreamingBufferMode = ADC_STREAM_BUFFER_LINEAR,
    .StreamingNumSamples = 1,
    .GroupDefinition = &AdcGroup_1_ChannelsInf,
    .NotificationFunc = CallBack_AdcGroup1,
    .IntcAndDmaCfg = ADC_INTC_ENABLED,
};

ADC_CONST const Adc_GroupConfigType Adc_GourpsConfiguration[2] = 
{
    {
        .GroupId = AdcConf_AdcConfigSet_AdcGroup_0,
        .GroupSample = &AdcGroup_0_Configuration,
        .ChannelSample = &AdcGroup_0_ChannelSample,
    },
    {
        .GroupId = AdcConf_AdcConfigSet_AdcGroup_1,
        .GroupSample = &AdcGroup_1_Configuration,
        .ChannelSample = &AdcGroup_1_ChannelSample,
    },
};
ADC_CONST const Adc_ConfigType Adc_Config =
{
    .GroupCfgNum    = ADC_GROUP_NUMBER,
    .HwUnitCfgNum   = ADC_UNIT_NUMBER,
    .HwUnitUserCfg = &Adc_HwUnitConfiguration[0],
    .GroupUserCfg  = &Adc_GourpsConfiguration[0],
};

#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

