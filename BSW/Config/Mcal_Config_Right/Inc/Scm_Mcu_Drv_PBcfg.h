/**************************************************************************************************/
/**
 * @file      : Scm_Mcu_Drv_PBcfg.h
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

/** @addtogroup Scm_Mcu_Drv_Configuration
 *  @brief SCM driver configuration
 *  @{
 */
#ifndef SCM_MCU_DRV_PBCFG_H
#define SCM_MCU_DRV_PBCFG_H

#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */

#define SCM_MCU_DRV_PBCFG_H_VENDOR_ID                   0x00B3U
#define SCM_MCU_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define SCM_MCU_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION    6U
#define SCM_MCU_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION 0U
#define SCM_MCU_DRV_PBCFG_H_SW_MAJOR_VERSION            1U
#define SCM_MCU_DRV_PBCFG_H_SW_MINOR_VERSION            2U
#define SCM_MCU_DRV_PBCFG_H_SW_PATCH_VERSION            1U


/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

#define SCM_MCU_DRV_CONFIG_PB \
    extern const Scm_Mcu_Drv_ConfigType Scm_Mcu_Drv_Config; \
    extern const Scm_Mcu_Drv_ClockConfigType Scm_Mcu_Drv_ClockConfig[1U];
    
/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

#endif /* SCM_MCU_DRV_PBCFG_H  */

/** @} end of group Scm_Mcu_Drv_Configuration */

/** @} end of group Mcu_Module */


