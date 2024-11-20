/**************************************************************************************************/
/**
 * @file      : Can_PBcfg.h
 * @brief     : Can AUTOSAR level - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef CAN_PBCFG_H
#define CAN_PBCFG_H

/** @addtogroup Can_Module
 *  @{
 */

/** @addtogroup Can_Configuration
 *  @brief Can AUTOSAR level configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */

#define CAN_PBCFG_H_VENDOR_ID                   0x00B3U
#define CAN_PBCFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define CAN_PBCFG_H_AR_RELEASE_MINOR_VERSION    6U
#define CAN_PBCFG_H_AR_RELEASE_REVISION_VERSION 0U
#define CAN_PBCFG_H_SW_MAJOR_VERSION            1U
#define CAN_PBCFG_H_SW_MINOR_VERSION            2U
#define CAN_PBCFG_H_SW_PATCH_VERSION            2U

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
/* Declaration */
#define CAN_CONFIG_PB \
    extern const Can_ConfigType Can_Config;

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Can_Configuration */

/** @} end of group Can_Module */

#endif 
