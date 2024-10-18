/**************************************************************************************************/
/**
 * @file      : Tdg_Adc_Drv_PBcfg.h
 * @brief     : Tdg Adc low level driver - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef TDG_ADC_DRV_PBCFG_H
#define TDG_ADC_DRV_PBCFG_H

/** @addtogroup Adc_Module
 *  @{
 */

/** @addtogroup Tdg_Adc_Drv_Configuration
 *  @brief Tdg Adc low level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define TDG_ADC_DRV_PBCFG_H_VENDOR_ID                   0x00B3U
#define TDG_ADC_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define TDG_ADC_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION    6U
#define TDG_ADC_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION 0U
#define TDG_ADC_DRV_PBCFG_H_SW_MAJOR_VERSION            1U
#define TDG_ADC_DRV_PBCFG_H_SW_MINOR_VERSION            2U
#define TDG_ADC_DRV_PBCFG_H_SW_PATCH_VERSION            1U

/**
 * @brief Defines Adc Driver Configuration
*/
#define TDG_ADC_DRV_CONFIG_PB \
    extern const Tdg_Adc_Drv_ConfigType Tdg_Adc_Drv_Config_0;    \
    extern const Tdg_Adc_Drv_ConfigType Tdg_Adc_Drv_Config_1;    \
    extern const Tdg_Adc_Drv_GroupConfigType Tdg_Adc_Drv_GroupConfig_0; \
    extern const Tdg_Adc_Drv_GroupConfigType Tdg_Adc_Drv_GroupConfig_1; \
    extern const Tdg_Adc_Drv_GroupConfigType Tdg_Adc_Drv_GroupConfig_2; \

/**
 * @brief Defines declaration of TDG callback functions.
 */
#define TDG_ADC_DRV_FUNC_DECL_PB \

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

#endif

