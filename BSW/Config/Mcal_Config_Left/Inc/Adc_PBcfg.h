/**************************************************************************************************/
/**
 * @file      : Adc_PBcfg.h
 * @brief     : Adc AUTOSAR level - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef ADC_PBCFG_H
#define ADC_PBCFG_H

/** @addtogroup Adc_Module
 *  @{
 */

/** @addtogroup Adc_Configuration
 *  @brief Adc AUTOSAR level configuration
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define ADC_PBCFG_H_VENDOR_ID                   0x00B3U
#define ADC_PBCFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define ADC_PBCFG_H_AR_RELEASE_MINOR_VERSION    6U
#define ADC_PBCFG_H_AR_RELEASE_REVISION_VERSION 0U
#define ADC_PBCFG_H_SW_MAJOR_VERSION            1U
#define ADC_PBCFG_H_SW_MINOR_VERSION            2U
#define ADC_PBCFG_H_SW_PATCH_VERSION            1U

/**
 * @brief Defines ADC configuration
 */
#define ADC_CONFIG_PB \
    extern const Adc_ConfigType Adc_Config;

/**
 * @brief Total number of groups across all ConfigSet.
 *
 */
#define ADC_CFG_GROUP_NUM    (3U)

/**
* @brief Number of channels configured for each group.
*
*/
#define ADC_CFG_GROUP_0_CHANNEL_NUM    (6U)
#define ADC_CFG_GROUP_1_CHANNEL_NUM    (6U)
#define ADC_CFG_GROUP_2_CHANNEL_NUM    (5U)

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

/**
 * @brief Defines declaration of ADC notification functions.
 */
#define ADC_FUNC_DECL_PB \
    extern void ADC0_GroupNotification_0(void);  \
    extern void ADC0_GroupNotification_1(void);  \
    extern void ADC1_GroupNotification_0(void);  \

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Adc_Configuration */

/** @} end of group Adc_Module */

#endif /* ADC_PBCFG_H */

