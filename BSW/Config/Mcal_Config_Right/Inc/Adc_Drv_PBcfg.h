/**************************************************************************************************/
/**
 * @file      : Adc_Drv_PBcfg.h
 * @brief     : Adc low level driver - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef ADC_DRV_PBCFG_H
#define ADC_DRV_PBCFG_H

/** @addtogroup Adc_Module
 *  @{
 */

/** @addtogroup Adc_Drv_Configuration
 *  @brief Adc low level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define ADC_DRV_PBCFG_H_VENDOR_ID                   0x00B3U
#define ADC_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define ADC_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION    6U
#define ADC_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION 0U
#define ADC_DRV_PBCFG_H_SW_MAJOR_VERSION            1U
#define ADC_DRV_PBCFG_H_SW_MINOR_VERSION            2U
#define ADC_DRV_PBCFG_H_SW_PATCH_VERSION            2U

/**
 * @brief Defines Adc Driver Configuration
*/
#define ADC_DRV_CONFIG_PB \
    extern const Adc_Drv_ConfigType Adc_Drv_Config_0;   \
    extern const Adc_Drv_ConfigType Adc_Drv_Config_1;   \
    extern const Adc_Drv_GroupConfigType Adc_Drv_GroupConfig_0; \
    extern const Adc_Drv_GroupConfigType Adc_Drv_GroupConfig_1; \
    extern const Adc_Drv_GroupConfigType Adc_Drv_GroupConfig_2; \

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
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"


/**
 * @brief Defines declaration of ADC interrupt process functions.
 */
#define ADC_DRV_FUNC_DECL_PB \
    void Adc_ProcessConversionEndInterrupt(const uint8 HWUnit);   \


#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Adc_Drv_Configuration */

/** @} end of group Adc_Module */

#endif

