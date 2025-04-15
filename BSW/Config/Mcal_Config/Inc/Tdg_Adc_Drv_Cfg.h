/**************************************************************************************************/
/**
 * @file      : Tdg_Adc_Drv_Cfg.h  
 * @brief     : Tdg Adc low level driver - Pre-Compile(PC) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef TDG_ADC_DRV_CFG_H
#define TDG_ADC_DRV_CFG_H

/** @addtogroup Adc_Module
 *  @{
 */

/** @addtogroup Tdg_Adc_Configuration
 *  @brief Tdg Adc low level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif
#include "Tdg_Adc_Drv_PBcfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define TDG_ADC_DRV_CFG_H_VENDOR_ID                   0x00B3U
#define TDG_ADC_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define TDG_ADC_DRV_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define TDG_ADC_DRV_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define TDG_ADC_DRV_CFG_H_SW_MAJOR_VERSION            1U
#define TDG_ADC_DRV_CFG_H_SW_MINOR_VERSION            2U
#define TDG_ADC_DRV_CFG_H_SW_PATCH_VERSION            2U

/* Check if current file and Tdg_Adc_Drv_PBcfg.h are the same vendor */
#if (TDG_ADC_DRV_CFG_H_VENDOR_ID != TDG_ADC_DRV_PBCFG_H_VENDOR_ID)
    #error "Vendor ID of Tdg_Adc_Drv_Cfg.h and Tdg_Adc_Drv_PBcfg.h are different"
#endif
/* Check if current file and Tdg_Adc_Drv_PBcfg.h are the same Autosar version */
#if ((TDG_ADC_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION != TDG_ADC_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (TDG_ADC_DRV_CFG_H_AR_RELEASE_MINOR_VERSION != TDG_ADC_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
     (TDG_ADC_DRV_CFG_H_AR_RELEASE_REVISION_VERSION != TDG_ADC_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version of Tdg_Adc_Drv_Cfg.h and Tdg_Adc_Drv_PBcfg.h are different"
#endif
/* Check if current file and Tdg_Adc_Drv_PBcfg.h are the same software version */
#if ((TDG_ADC_DRV_CFG_H_SW_MAJOR_VERSION != TDG_ADC_DRV_PBCFG_H_SW_MAJOR_VERSION) || \
     (TDG_ADC_DRV_CFG_H_SW_MINOR_VERSION != TDG_ADC_DRV_PBCFG_H_SW_MINOR_VERSION) || \
     (TDG_ADC_DRV_CFG_H_SW_PATCH_VERSION != TDG_ADC_DRV_PBCFG_H_SW_PATCH_VERSION) \
    )
    #error "Software Version of Tdg_Adc_Drv_Cfg.h and Tdg_Adc_Drv_PBcfg.h are different"
#endif
/** 
 * @brief Defines Tdg Driver configuration.
 */
#define TDG_ADC_DRV_CONFIG_EXT \
    TDG_ADC_DRV_CONFIG_PB

/** 
 * @brief Defines Tdg callback functions declaration.
 */
#define TDG_ADC_DRV_FUNC_DECL_EXT \
    TDG_ADC_DRV_FUNC_DECL_PB

/** 
 * @brief Defines number of Tdg hw units.
 */
#define TDG_ADC_DRV_INSTANCE_NUM   (2U)

/** 
 * @brief Switches Development error detect ON or OFF.
 */
#define TDG_ADC_DRV_DEV_ERROR_DETECT    (STD_ON)

/** 
 * @brief Defines timeout methond from McalLib.
 */
#define TDG_ADC_DRV_TIMEOUT_METHOD    (MCALLIB_COUNTER_SOFTWARE)

/** 
 * @brief Defines timeout value.
 */
#define TDG_ADC_DRV_TIMEOUT_VAL    (1000U)

/** 
 * @brief Defines the chanel number of each Tdg hardware unit.
 */
#define TDG_ADC_DRV_CHANNEL_NUM    (6U)

/**
 * @brief max number of groups configured across all configset.
 */
#define TDG_ADC_DRV_MAX_GROUPS    (4U)

/** 
 * @brief Defines the delay output number of each Tdg channel.
 */
#define TDG_ADC_DRV_CHANNEL_DELAY_OUTPUT_NUM    (8U)

/**
 * @brief Defines HW Units enanble or not.
 */
#define TDG_ADC_DRV_0_ENABLE    (STD_ON)
#define TDG_ADC_DRV_1_ENABLE    (STD_ON)

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

/** @} end of group Tdg_Adc_Drv_Configuration */

/** @} end of group Adc_Module */

#endif /* TDG_ADC_DRV_CFG_H */
