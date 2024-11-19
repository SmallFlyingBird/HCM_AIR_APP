/**************************************************************************************************/
/**
 * @file      : Adc_Drv_Cfg.h  
 * @brief     : Adc low level driver - Pre-Compile(PC) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef ADC_DRV_CFG_H
#define ADC_DRV_CFG_H

/** @addtogroup Adc_Module
 *  @{
 */

/** @addtogroup Adc_Configuration
 *  @brief Adc low level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif
#include "Adc_Drv_PBcfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define ADC_DRV_CFG_H_VENDOR_ID                   0x00B3U
#define ADC_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define ADC_DRV_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define ADC_DRV_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define ADC_DRV_CFG_H_SW_MAJOR_VERSION            1U
#define ADC_DRV_CFG_H_SW_MINOR_VERSION            2U
#define ADC_DRV_CFG_H_SW_PATCH_VERSION            2U

/* Check if current file and Adc_Drv_PBcfg.h are the same vendor */
#if (ADC_DRV_CFG_H_VENDOR_ID != ADC_DRV_PBCFG_H_VENDOR_ID)
    #error "Vendor ID of Adc_Drv_Cfg.h and Adc_Drv_PBcfg.h are different"
#endif
/* Check if current file and Adc_Drv_PBcfg.h are the same Autosar version */
#if ((ADC_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION != ADC_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_DRV_CFG_H_AR_RELEASE_MINOR_VERSION != ADC_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
     (ADC_DRV_CFG_H_AR_RELEASE_REVISION_VERSION != ADC_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version of Adc_Drv_Cfg.h and Adc_Drv_PBcfg.h are different"
#endif
/* Check if current file and Adc_Drv_PBcfg.h are the same software version */
#if ((ADC_DRV_CFG_H_SW_MAJOR_VERSION != ADC_DRV_PBCFG_H_SW_MAJOR_VERSION) || \
     (ADC_DRV_CFG_H_SW_MINOR_VERSION != ADC_DRV_PBCFG_H_SW_MINOR_VERSION) || \
     (ADC_DRV_CFG_H_SW_PATCH_VERSION != ADC_DRV_PBCFG_H_SW_PATCH_VERSION) \
    )
    #error "Software Version of Adc_Drv_Cfg.h and Adc_Drv_PBcfg.h are different"
#endif

/**
 * @brief Defines Adc Driver configuration.
 */
#define ADC_DRV_CONFIG_EXT \
    ADC_DRV_CONFIG_PB

/**
 * @brief Defines ADC interrupt process functions declaration.
 */
#define ADC_DRV_FUNC_DECL_EXT \
    ADC_DRV_FUNC_DECL_PB

/** 
 * @brief Defines number of Adc hw units.
 */
#define ADC_DRV_INSTANCE_NUM    (2U)

/**
 * @brief max number of groups configured across all configset.
 */
#define ADC_DRV_MAX_GROUPS    (3U)

/**
 * @brief Switches Development error detect ON or OFF.
 */
#define ADC_DRV_DEV_ERROR_DETECT    (STD_ON)

/**
 * @brief Defines timeout methond from McalLib.
 */
#define ADC_DRV_TIMEOUT_METHOD    (MCALLIB_COUNTER_SOFTWARE)

/**
 * @brief Defines timeout value.
 */
#define ADC_DRV_TIMEOUT_VAL    (1000U)

/**
 * @brief Defines FIFO size.
 */
#define ADC_DRV_FIFO_SIZE    (16U)

/**
 * @brief Defines if DMA or Interrupt is used.
 * @details As long as Dma is used by one Adc HWUnit, ADC_DRV_DMA_USED will be STD_ON.
 */
#define ADC_DRV_DMA_USED    (STD_OFF)

/** 
 * @brief Defines invalid ID of DMA channel.
 */
#define ADC_DRV_INVALID_DMA_CHANNEL_ID      (0xFFU)

/**
 * @brief Maximum number of channels across all hardware units.
 */
#define ADC_DRV_MAX_CHANNELS_PER_HWUNIT    (12U)

/**
 * @brief Maximum number of channels per group.
 */
#define ADC_DRV_MAX_CHANNELS_PER_GROUP    (6U)

/**
 * @brief Defines HW Units enable or not.
 */
#define ADC_DRV_0_ENABLE    (STD_ON)
#define ADC_DRV_1_ENABLE    (STD_ON)

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Adc_Drv_Configuration */

/** @} end of group Adc_Module */

#endif /* ADC_DRV_CFG_H */
