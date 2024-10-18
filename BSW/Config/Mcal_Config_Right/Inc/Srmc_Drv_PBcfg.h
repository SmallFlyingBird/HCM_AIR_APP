/**************************************************************************************************/
/**
 * @file      : Srmc_Drv_PBcfg.h
 * @brief     : AUTOSAR Mcu - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Mcu_Module
 *  @{
 */

/** @addtogroup Srmc_Drv_Configuration
 *  @brief SRMC driver configuration
 *  @{
 */
#ifndef SRMC_DRV_PBCFG_H
#define SRMC_DRV_PBCFG_H

#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */

#define SRMC_DRV_PBCFG_H_VENDOR_ID                   0x00B3U
#define SRMC_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define SRMC_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION    6U
#define SRMC_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION 0U
#define SRMC_DRV_PBCFG_H_SW_MAJOR_VERSION            1U
#define SRMC_DRV_PBCFG_H_SW_MINOR_VERSION            2U
#define SRMC_DRV_PBCFG_H_SW_PATCH_VERSION            1U


/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

#define SRMC_DRV_CONFIG_PB \
    extern const Srmc_Drv_ResetConfigType Srmc_Drv_ResetConfig; \
    extern const Srmc_Drv_PowerModeConfigType Srmc_Drv_PowerModeConfig;

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

#endif /* SRMC_DRV_PBCFG_H  */

/** @} end of group Srmc_Drv_Configuration */

/** @} end of group Mcu_Module */


