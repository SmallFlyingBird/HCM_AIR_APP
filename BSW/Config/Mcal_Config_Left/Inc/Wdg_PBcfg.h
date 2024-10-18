/**************************************************************************************************/
/**
 * @file      : Wdg_PBcfg.h
 * @brief     : Wdg AUTOSAR level - Post-Build(PB) configuration file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef WDG_PBCFG_H
#define WDG_PBCFG_H

/** @addtogroup Wdg_Module
 *  @{
 */

/** @addtogroup Wdg_Configuration
 *  @brief Wdg AUTOSAR level configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */
#define WDG_PBCFG_H_VENDOR_ID                   0x00B3U
#define WDG_PBCFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define WDG_PBCFG_H_AR_RELEASE_MINOR_VERSION    6U
#define WDG_PBCFG_H_AR_RELEASE_REVISION_VERSION 0U
#define WDG_PBCFG_H_SW_MAJOR_VERSION            1U
#define WDG_PBCFG_H_SW_MINOR_VERSION            2U
#define WDG_PBCFG_H_SW_PATCH_VERSION            1U

/**
* @brief Defines the watchdog configuration in post-build.
*/
#define WDG_CONFIG_PB extern const Wdg_ConfigType Wdg_Config;
/** @} end of Public_MacroDefinition */

#ifdef __cplusplus
}
#endif
#endif

/** @} end of group Wdg_Configuration */

/** @} end of group Wdg_Module */
