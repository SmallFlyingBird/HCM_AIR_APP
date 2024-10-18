/**************************************************************************************************/
/**
 * @file      : Wdog_Drv_PBcfg.h
 * @brief     : Wdog low level driver - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef WDOG_DRV_PBCFG_H
#define WDOG_DRV_PBCFG_H

/** @addtogroup Wdg_Module
 *  @{
 */

/** @addtogroup Wdog_Drv_Configuration
 *  @brief Wdog low level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define WDOG_DRV_PBCFG_H_VENDOR_ID                   0x00B3U
#define WDOG_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define WDOG_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION    6U
#define WDOG_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION 0U
#define WDOG_DRV_PBCFG_H_SW_MAJOR_VERSION            1U
#define WDOG_DRV_PBCFG_H_SW_MINOR_VERSION            2U
#define WDOG_DRV_PBCFG_H_SW_PATCH_VERSION            1U

/**
 * @brief Defines Wdog Driver Configuration
 */
#define WDOG_DRV_CONFIG_PB \
    extern const Wdog_Drv_ConfigType Wdog_Drv_FastModeConfig; \
    extern const Wdog_Drv_ConfigType Wdog_Drv_SlowModeConfig; \

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

/** @} end of group Wdog_Drv_Configuration */

/** @} end of group Wdg_Module */

#endif
