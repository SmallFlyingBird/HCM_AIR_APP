/**************************************************************************************************/
/**
 * @file      : Wdg_Drvw_PBcfg.h
 * @brief     : Wdg driver wrapper - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef WDG_DRVW_PBCFG_H
#define WDG_DRVW_PBCFG_H

/** @addtogroup Wdg_Module
 *  @{
 */

/** @addtogroup Wdg_Drvw_Configuration
 *  @brief Wdg driver wrapper configuration
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define WDG_DRVW_PBCFG_H_VENDOR_ID                   0x00B3U
#define WDG_DRVW_PBCFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define WDG_DRVW_PBCFG_H_AR_RELEASE_MINOR_VERSION    6U
#define WDG_DRVW_PBCFG_H_AR_RELEASE_REVISION_VERSION 0U
#define WDG_DRVW_PBCFG_H_SW_MAJOR_VERSION            1U
#define WDG_DRVW_PBCFG_H_SW_MINOR_VERSION            2U
#define WDG_DRVW_PBCFG_H_SW_PATCH_VERSION            1U

/**
 * @brief Defines WDG Driver Wrapper Configuration
*/
#define WDG_DRVW_CONFIG_PB \
    extern const Wdg_Drvw_ConfigType Wdg_Drvw_Config; \

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

/** @} end of group Wdg_Drvw_Configuration */

/** @} end of group Wdg_Module */

#endif
