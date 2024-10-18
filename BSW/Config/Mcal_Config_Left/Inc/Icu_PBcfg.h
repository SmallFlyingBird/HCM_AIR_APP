/**************************************************************************************************/
/**
 * @file      : Icu_PBcfg.h
 * @brief     : AUTOSAR Icu post-build configure head file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef ICU_PBCFG_H
#define ICU_PBCFG_H

/** @addtogroup  Icu_Module
 *  @{
 */

/** @addtogroup  Icu
 *  @{
 */

#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */

#define ICU_PBCFG_H_VENDOR_ID                   0x00B3U 
#define ICU_PBCFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define ICU_PBCFG_H_AR_RELEASE_MINOR_VERSION    6U
#define ICU_PBCFG_H_AR_RELEASE_REVISION_VERSION 0U
#define ICU_PBCFG_H_SW_MAJOR_VERSION            1U
#define ICU_PBCFG_H_SW_MINOR_VERSION            2U
#define ICU_PBCFG_H_SW_PATCH_VERSION            1U

/** @} end of group Public_MacroDefinition */

/** @defgroup Public_TypeDefinition 
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/**
 * @brief Defines ICU configuration
 */
#define ICU_CONFIG_PB \
    extern const Icu_ConfigType Icu_Config;

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Icu  */
/** @} end of group Icu_Module */

#endif /* ICU_PBCFG_H */

