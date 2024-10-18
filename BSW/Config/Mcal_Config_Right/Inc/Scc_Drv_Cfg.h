/**************************************************************************************************/
/**
 * @file      : Scc_Drv_Cfg.h
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

/** @addtogroup Scc_Drv_Configuration
 *  @brief SCC clock driver configuration
 *  @{
 */

#ifndef SCC_DRV_CFG_H
#define SCC_DRV_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Scc_Drv_PBcfg.h"


/** @defgroup Public_MacroDefinition
 *  @{
 */

#define SCC_DRV_CFG_H_VENDOR_ID                   0x00B3U
#define SCC_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define SCC_DRV_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define SCC_DRV_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define SCC_DRV_CFG_H_SW_MAJOR_VERSION            1U
#define SCC_DRV_CFG_H_SW_MINOR_VERSION            2U
#define SCC_DRV_CFG_H_SW_PATCH_VERSION            1U

/* Check if current file and Scc_Drv_PBcfg.h are of the same vendor */
#if (SCC_DRV_CFG_H_VENDOR_ID != SCC_DRV_PBCFG_H_VENDOR_ID)
    #error "Vendor ID of Scc_Drv_Cfg.h and Scc_Drv_PBcfg.h are different"
#endif
    /* Check if current file and Scc_Drv_PBcfg.h are of the same Autosar version */
#if ((SCC_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION != SCC_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (SCC_DRV_CFG_H_AR_RELEASE_MINOR_VERSION != SCC_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
     (SCC_DRV_CFG_H_AR_RELEASE_REVISION_VERSION != SCC_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Scc_Drv_Cfg.h and Scc_Drv_PBcfg.h are different"
#endif
/* Check if current file and Scc_Drv_PBcfg.h are of the same software version */
#if ((SCC_DRV_CFG_H_SW_MAJOR_VERSION != SCC_DRV_PBCFG_H_SW_MAJOR_VERSION) || \
     (SCC_DRV_CFG_H_SW_MINOR_VERSION != SCC_DRV_PBCFG_H_SW_MINOR_VERSION) || \
     (SCC_DRV_CFG_H_SW_PATCH_VERSION != SCC_DRV_PBCFG_H_SW_PATCH_VERSION))
#error "Software Version of Scc_Drv_Cfg.h and Scc_Drv_PBcfg.h are different"
#endif


#define SCC_DRV_CONFIG_EXT \
    SCC_DRV_CONFIG_PB

/**
* @brief Switch to enable PLL monitor API.
* @note  This API should be set to STD_OFF in Z20K14xM.
*/
#define SCC_DRV_ENABLE_PLL_MONITOR_API (STD_OFF)

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

#endif /* #ifndef SCC_DRV_CFG_H */

/** @} end of group Scc_Drv_Configuration */

/** @} end of group Mcu_Module */
