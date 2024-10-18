/**************************************************************************************************/
/**
 * @file      : Srmc_Drv_Cfg.h
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

/** @addtogroup Srmc_Drv_Configuration
 *  @brief Mcu driver configuration
 *  @{
 */

#ifndef SRMC_DRV_CFG_H
#define SRMC_DRV_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Srmc_Drv_PBcfg.h"


/** @defgroup Public_MacroDefinition
 *  @{
 */

#define SRMC_DRV_CFG_H_VENDOR_ID                   0x00B3U
#define SRMC_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define SRMC_DRV_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define SRMC_DRV_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define SRMC_DRV_CFG_H_SW_MAJOR_VERSION            1U
#define SRMC_DRV_CFG_H_SW_MINOR_VERSION            2U
#define SRMC_DRV_CFG_H_SW_PATCH_VERSION            1U

/* Check if current file and Srmc_Drv_PBcfg.h are of the same vendor */
#if (SRMC_DRV_CFG_H_VENDOR_ID != SRMC_DRV_PBCFG_H_VENDOR_ID)
    #error "Vendor ID of Srmc_Drv_Cfg.h and Srmc_Drv_PBcfg.h are different"
#endif
    /* Check if current file and Srmc_Drv_PBcfg.h are of the same Autosar version */
#if ((SRMC_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION != SRMC_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (SRMC_DRV_CFG_H_AR_RELEASE_MINOR_VERSION != SRMC_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
     (SRMC_DRV_CFG_H_AR_RELEASE_REVISION_VERSION != SRMC_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Srmc_Drv_Cfg.h and Srmc_Drv_PBcfg.h are different"
#endif
/* Check if current file and Srmc_Drv_PBcfg.h are of the same software version */
#if ((SRMC_DRV_CFG_H_SW_MAJOR_VERSION != SRMC_DRV_PBCFG_H_SW_MAJOR_VERSION) || \
     (SRMC_DRV_CFG_H_SW_MINOR_VERSION != SRMC_DRV_PBCFG_H_SW_MINOR_VERSION) || \
     (SRMC_DRV_CFG_H_SW_PATCH_VERSION != SRMC_DRV_PBCFG_H_SW_PATCH_VERSION))
#error "Software Version of Srmc_Drv_Cfg.h and Srmc_Drv_PBcfg.h are different"
#endif

#define SRMC_DRV_CONFIG_EXT \
    SRMC_DRV_CONFIG_PB

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

#endif /* #ifndef SRMC_DRV_CFG_H */

/** @} end of group Srmc_Drv_Configuration */

/** @} end of group Mcu_Module */
