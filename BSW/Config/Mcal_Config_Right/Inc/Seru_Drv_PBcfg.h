/**************************************************************************************************/
/**
 * @file      : Seru_Drv_PBcfg.h
 * @brief     : Seru low level driver - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef SERU_DRV_PBCFG_H
#define SERU_DRV_PBCFG_H

/** @addtogroup Seru_Module
 *  @{
 */

/** @addtogroup Seru_Drv_Configuration
 *  @brief Seru low level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define SERU_DRV_PBCFG_H_VENDOR_ID                   0x00B3U
#define SERU_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define SERU_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION    6U
#define SERU_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION 0U
#define SERU_DRV_PBCFG_H_SW_MAJOR_VERSION            1U
#define SERU_DRV_PBCFG_H_SW_MINOR_VERSION            1U
#define SERU_DRV_PBCFG_H_SW_PATCH_VERSION            0U

/**
 * @brief Defines SERU Driver Configuration
 */
#define SERU_DRV_CONFIG_PB \
    extern const Seru_Drv_ConfigType  Seru_Drv_Config; \

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

/** @} end of group Seru_Drv_Configuration */

/** @} end of group Seru_Module */

#endif
