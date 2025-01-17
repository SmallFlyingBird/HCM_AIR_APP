/**************************************************************************************************/
/**
 * @file      : Adc_Drv_PBcfg.c  
 * @brief     : Adc low level driver - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Adc_Module
 *  @{
 */

/** @addtogroup Adc_Drv_Configuration
 *  @brief Adc low level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Adc_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define ADC_DRV_PBCFG_C_VENDOR_ID                   0x00B3U
#define ADC_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define ADC_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define ADC_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define ADC_DRV_PBCFG_C_SW_MAJOR_VERSION            1U
#define ADC_DRV_PBCFG_C_SW_MINOR_VERSION            2U
#define ADC_DRV_PBCFG_C_SW_PATCH_VERSION            2U

/* Check if current file and Adc_Drv.h are the same vendor */
#if (ADC_DRV_PBCFG_C_VENDOR_ID != ADC_DRV_H_VENDOR_ID)
    #error "Adc_Drv_PBcfg.c and Adc_Drv.h have different vendor ids"
#endif

/* Check if current file and Adc_Drv.h are the same Autosar version */
#if ((ADC_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION != ADC_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION != ADC_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (ADC_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION != ADC_DRV_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Adc_Drv_PBcfg.c and Adc_Drv.h are different"
#endif

/* Check if current file and Adc_Drv.h are the same Software version */
#if ((ADC_DRV_PBCFG_C_SW_MAJOR_VERSION != ADC_DRV_H_SW_MAJOR_VERSION) || \
     (ADC_DRV_PBCFG_C_SW_MINOR_VERSION != ADC_DRV_H_SW_MINOR_VERSION) || \
     (ADC_DRV_PBCFG_C_SW_PATCH_VERSION != ADC_DRV_H_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Adc_Drv_PBcfg.c and Adc_Drv.h are different"
#endif

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */
#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/**
 * @brief ADC Driver List of Channels Configuration for HW Unit0
 */
static const Adc_Drv_ChannelConfigType Adc_Drv_ChannelConfigList_0[8U] =
{
    {
        0U, /*!< Channel Index */
        ADC_DRV_P_CH0, /*!< Channel */
        (boolean)FALSE /*!< InterruptEnable */
    },
    {
        1U, /*!< Channel Index */
        ADC_DRV_P_CH3, /*!< Channel */
        (boolean)FALSE /*!< InterruptEnable */
    },
    {
        2U, /*!< Channel Index */
        ADC_DRV_P_CH13, /*!< Channel */
        (boolean)FALSE /*!< InterruptEnable */
    },
    {
        3U, /*!< Channel Index */
        ADC_DRV_P_CH14, /*!< Channel */
        (boolean)FALSE /*!< InterruptEnable */
    },
    {
        4U, /*!< Channel Index */
        ADC_DRV_P_CH8, /*!< Channel */
        (boolean)FALSE /*!< InterruptEnable */
    },
    {
        5U, /*!< Channel Index */
        ADC_DRV_P_CH9, /*!< Channel */
        (boolean)FALSE /*!< InterruptEnable */
    },
    {
        6U, /*!< Channel Index */
        ADC_DRV_P_CH10, /*!< Channel */
        (boolean)FALSE /*!< InterruptEnable */
    },
    {
        7U, /*!< Channel Index */
        ADC_DRV_P_CH11, /*!< Channel */
        (boolean)FALSE /*!< InterruptEnable */
    }
};

/**
 * @brief ADC Driver List of Channels Configuration for HW Unit1
 */
static const Adc_Drv_ChannelConfigType Adc_Drv_ChannelConfigList_1[1U] =
{
    {
        0U, /*!< Channel Index */
        ADC_DRV_P_CH7, /*!< Channel */
        (boolean)FALSE /*!< InterruptEnable */
    }
};

#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"
/** @} end of group Private_VariableDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */
#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/**
 * @brief ADC Driver Configuration: Adc_Drv_Config_0
 */
const Adc_Drv_ConfigType Adc_Drv_Config_0 =
{
    ADC_DRV_AVG_DISABLE, /*!< AvgSel */
    ADC_DRV_RESOLUTION_12BIT, /*!< Resolution */
    ADC_DRV_TRIGGER_TDG, /*!< TriggerMode */
    ADC_DRV_VREF_EXTERNAL, /*!< VoltageRef */
    ADC_DRV_CONVERSION_SINGLE, /*!< ConvMode */
    ADC_DRV_COMPARE_MODE_DISABLED, /*!< CompareEnable */
    (boolean)FALSE, /*!< CompareGreaterThanEnable */
    (boolean)FALSE, /*!< CompareRangeFuncEnable */
    0U, /*!< CompVal1 */
    255U, /*!< CompVal2 */
    (boolean)FALSE, /*!< CalibrationEnable */
    0U, /*!< UsrGain */
    0U, /*!< UsrOffset */
    Adc_Drv_ChannelConfigList_0, /*!< ChannelConfigList */
    8, /*!< ConfiguredChannelCount */
    &Adc_ProcessConversionEndInterrupt, /*!< ConversionCompleteNotification */
    NULL_PTR, /*!< TriggerErrorNotification */
    ADC_DRV_INTERRUPT, /*!< TransferMode */
    ADC_DRV_INVALID_DMA_CHANNEL_ID, /*!< DmaChannel */
    (boolean)FALSE /*!< WithoutInterrupt */
};
/**
 * @brief ADC Driver Configuration: Adc_Drv_Config_1
 */
const Adc_Drv_ConfigType Adc_Drv_Config_1 =
{
    ADC_DRV_AVG_DISABLE, /*!< AvgSel */
    ADC_DRV_RESOLUTION_12BIT, /*!< Resolution */
    ADC_DRV_TRIGGER_TDG, /*!< TriggerMode */
    ADC_DRV_VREF_EXTERNAL, /*!< VoltageRef */
    ADC_DRV_CONVERSION_SINGLE, /*!< ConvMode */
    ADC_DRV_COMPARE_MODE_DISABLED, /*!< CompareEnable */
    (boolean)FALSE, /*!< CompareGreaterThanEnable */
    (boolean)FALSE, /*!< CompareRangeFuncEnable */
    0U, /*!< CompVal1 */
    255U, /*!< CompVal2 */
    (boolean)FALSE, /*!< CalibrationEnable */
    0U, /*!< UsrGain */
    0U, /*!< UsrOffset */
    Adc_Drv_ChannelConfigList_1, /*!< ChannelConfigList */
    1, /*!< ConfiguredChannelCount */
    &Adc_ProcessConversionEndInterrupt, /*!< ConversionCompleteNotification */
    NULL_PTR, /*!< TriggerErrorNotification */
    ADC_DRV_INTERRUPT, /*!< TransferMode */
    ADC_DRV_INVALID_DMA_CHANNEL_ID, /*!< DmaChannel */
    (boolean)FALSE /*!< WithoutInterrupt */
};

/**
 * @brief ADC Driver Group0 Config: Adc_Drv_GroupConfig_0.
 */
const Adc_Drv_GroupConfigType Adc_Drv_GroupConfig_0 =
{
    ADC_DRV_AVG_4_CONV, /*!< AverageSelect */
    256U, /*!< StableTime */
    256U, /*!< SampleTime */
    ADC_DRV_LOOP_MODE, /*!< TdgTriggerMode */
};
/**
 * @brief ADC Driver Group1 Config: Adc_Drv_GroupConfig_1.
 */
const Adc_Drv_GroupConfigType Adc_Drv_GroupConfig_1 =
{
    ADC_DRV_AVG_4_CONV, /*!< AverageSelect */
    256U, /*!< StableTime */
    256U, /*!< SampleTime */
    ADC_DRV_LOOP_MODE, /*!< TdgTriggerMode */
};
/**
 * @brief ADC Driver Group2 Config: Adc_Drv_GroupConfig_2.
 */
const Adc_Drv_GroupConfigType Adc_Drv_GroupConfig_2 =
{
    ADC_DRV_AVG_4_CONV, /*!< AverageSelect */
    256U, /*!< StableTime */
    256U, /*!< SampleTime */
    ADC_DRV_LOOP_MODE, /*!< TdgTriggerMode */
};

#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"
/** @} end of group Global_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Adc_Drv_Configuration */

/** @} end of group Adc_Module */
