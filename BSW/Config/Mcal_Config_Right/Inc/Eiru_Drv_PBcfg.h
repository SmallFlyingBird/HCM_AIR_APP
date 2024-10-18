/**************************************************************************************************/
/**
 * @file      : Eiru_Drv_PBcfg.h
 * @brief     : Eiru low level driver - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef EIRU_DRV_PBCFG_H
#define EIRU_DRV_PBCFG_H

/** @addtogroup Eiru_Module
 *  @{
 */

/** @addtogroup Eiru_Drv_Configuration
 *  @brief Eiru low level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define EIRU_DRV_PBCFG_H_VENDOR_ID                   0x00B3U
#define EIRU_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define EIRU_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION    6U
#define EIRU_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION 0U
#define EIRU_DRV_PBCFG_H_SW_MAJOR_VERSION            1U
#define EIRU_DRV_PBCFG_H_SW_MINOR_VERSION            1U
#define EIRU_DRV_PBCFG_H_SW_PATCH_VERSION            0U

/**
 * @brief Defines EIRU Driver Configuration
 */
#define EIRU_DRV_CONFIG_PB \
    extern const Eiru_Drv_SramEccConfigType      Eiru_Drv_Config; \

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

/** @} end of group Eiru_Drv_Configuration */

/** @} end of group Eiru_Module */

#endif
