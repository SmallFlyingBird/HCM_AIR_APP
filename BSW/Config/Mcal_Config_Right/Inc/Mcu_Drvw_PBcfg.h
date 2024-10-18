/**************************************************************************************************/
/**
 * @file      : Mcu_Drvw_PBcfg.h
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

/** @addtogroup Mcu_Drvw_Configuration
 *  @brief Mcu driver wrapper configuration
 *  @{
 */
#ifndef MCU_DRVW_PBCFG_H
#define MCU_DRVW_PBCFG_H

#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */

#define MCU_DRVW_PBCFG_H_VENDOR_ID                   0x00B3U
#define MCU_DRVW_PBCFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define MCU_DRVW_PBCFG_H_AR_RELEASE_MINOR_VERSION    6U
#define MCU_DRVW_PBCFG_H_AR_RELEASE_REVISION_VERSION 0U
#define MCU_DRVW_PBCFG_H_SW_MAJOR_VERSION            1U
#define MCU_DRVW_PBCFG_H_SW_MINOR_VERSION            2U
#define MCU_DRVW_PBCFG_H_SW_PATCH_VERSION            1U


/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

#define MCU_DRVW_CLOCK_CONFIG_PB \
    extern const Mcu_Drvw_ClockConfigType Mcu_Drvw_ClockConfig[1U];

#define MCU_DRVW_CONFIG_PB \
    extern const Mcu_Drvw_HwConfigType Mcu_Drvw_HwConfig;

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

#endif /* MCU_DRVW_PBCFG_H  */

/** @} end of group MCU_DRVW_Configuration */

/** @} end of group Mcu_Module */


