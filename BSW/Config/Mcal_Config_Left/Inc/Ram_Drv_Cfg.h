/**************************************************************************************************/
/**
 * @file      : Ram_Drv_Cfg.h
 * @brief     : AUTOSAR Mcu - Pre-Compile(PC) configuration file code template
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

/** @addtogroup Ram_Drv_Configuration
 *  @brief RAM driver configuration
 *  @{
 */

#ifndef RAM_DRV_CFG_H
#define RAM_DRV_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Ram_Drv_PBcfg.h"


/** @defgroup Public_MacroDefinition
 *  @{
 */

#define RAM_DRV_CFG_H_VENDOR_ID                   0x00B3U
#define RAM_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define RAM_DRV_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define RAM_DRV_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define RAM_DRV_CFG_H_SW_MAJOR_VERSION            1U
#define RAM_DRV_CFG_H_SW_MINOR_VERSION            2U
#define RAM_DRV_CFG_H_SW_PATCH_VERSION            1U

/* Check if current file and Ram_Drv_PBcfg.h are of the same vendor */
#if (RAM_DRV_CFG_H_VENDOR_ID != RAM_DRV_PBCFG_H_VENDOR_ID)
    #error "Vendor ID of Ram_Drv_Cfg.h and Ram_Drv_PBcfg.h are different"
#endif
    /* Check if current file and Ram_Drv_PBcfg.h are of the same Autosar version */
#if ((RAM_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION != RAM_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (RAM_DRV_CFG_H_AR_RELEASE_MINOR_VERSION != RAM_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
     (RAM_DRV_CFG_H_AR_RELEASE_REVISION_VERSION != RAM_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Ram_Drv_Cfg.h and Ram_Drv_PBcfg.h are different"
#endif
/* Check if current file and Ram_Drv_PBcfg.h are of the same software version */
#if ((RAM_DRV_CFG_H_SW_MAJOR_VERSION != RAM_DRV_PBCFG_H_SW_MAJOR_VERSION) || \
     (RAM_DRV_CFG_H_SW_MINOR_VERSION != RAM_DRV_PBCFG_H_SW_MINOR_VERSION) || \
     (RAM_DRV_CFG_H_SW_PATCH_VERSION != RAM_DRV_PBCFG_H_SW_PATCH_VERSION))
#error "Software Version of Ram_Drv_Cfg.h and Ram_Drv_PBcfg.h are different"
#endif

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

#endif /* #ifndef RAM_DRV_CFG_H */

/** @} end of group Ram_Drv_Configuration */

/** @} end of group Mcu_Module */
