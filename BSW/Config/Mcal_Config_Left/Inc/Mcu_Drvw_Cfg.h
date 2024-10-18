/**************************************************************************************************/
/**
 * @file      : Mcu_Drvw_Cfg.h
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

/** @addtogroup Mcu_Drvw_Configuration
 *  @brief Mcu driver wrapper configuration
 *  @{
 */

#ifndef MCU_DRVW_CFG_H
#define MCU_DRVW_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Mcu_Drvw_PBcfg.h"


/** @defgroup Public_MacroDefinition
 *  @{
 */

#define MCU_DRVW_CFG_H_VENDOR_ID                   0x00B3U
#define MCU_DRVW_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define MCU_DRVW_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define MCU_DRVW_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define MCU_DRVW_CFG_H_SW_MAJOR_VERSION            1U
#define MCU_DRVW_CFG_H_SW_MINOR_VERSION            2U
#define MCU_DRVW_CFG_H_SW_PATCH_VERSION            1U

/* Check if current file and Mcu_Drvw_PBcfg.h are of the same vendor */
#if (MCU_DRVW_CFG_H_VENDOR_ID != MCU_DRVW_PBCFG_H_VENDOR_ID)
    #error "Vendor ID of Mcu_Drvw_Cfg.h and Mcu_Drvw_PBcfg.h are different"
#endif
    /* Check if current file and Mcu_Drvw_PBcfg.h are of the same Autosar version */
#if ((MCU_DRVW_CFG_H_AR_RELEASE_MAJOR_VERSION != MCU_DRVW_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_DRVW_CFG_H_AR_RELEASE_MINOR_VERSION != MCU_DRVW_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
     (MCU_DRVW_CFG_H_AR_RELEASE_REVISION_VERSION != MCU_DRVW_PBCFG_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Mcu_Drvw_Cfg.h and Mcu_Drvw_PBcfg.h are different"
#endif
/* Check if current file and Mcu_Drvw_PBcfg.h are of the same software version */
#if ((MCU_DRVW_CFG_H_SW_MAJOR_VERSION != MCU_DRVW_PBCFG_H_SW_MAJOR_VERSION) || \
     (MCU_DRVW_CFG_H_SW_MINOR_VERSION != MCU_DRVW_PBCFG_H_SW_MINOR_VERSION) || \
     (MCU_DRVW_CFG_H_SW_PATCH_VERSION != MCU_DRVW_PBCFG_H_SW_PATCH_VERSION))
#error "Software Version of Mcu_Drvw_Cfg.h and Mcu_Drvw_PBcfg.h are different"
#endif

/**
* @brief If this parameter is set to FALSE, the clock initialization has to be disabled from the MCU driver wrapper.
*/
#define MCU_DRVW_INIT_CLOCK    (STD_ON)

/**
* @brief If this parameter is set to TRUE, the System Reset and Mode Control Module (SRMC) initialization has to be disabled from the MCU driver wrapper.
*/
#define MCU_DRVW_DISABLE_SRMC_INIT    (STD_OFF)

/**
* @brief If this parameter is set to TRUE, the System Control Module (SCM) initialization has to be disabled from the MCU driver wrapper.
*/
#define MCU_DRVW_DISABLE_SCM_INIT    (STD_OFF)

/**
* @brief Pre-processor switch to enable/disable the initialization of Power Management Unit(PMU) module in the MCU driver.
*/
#define MCU_DRVW_DISABLE_PMU_INIT    (STD_OFF)

/**
* @brief This parameter shall be set True, if the H/W does not have a PLL or the PLL circuitry is enabled after the power on without S/W intervention.
*/
#define MCU_DRVW_NO_PLL    (STD_OFF)

/**
* @brief API Mcu_PerformReset is/isn't available (STD_ON/STD_OFF).
*/
#define MCU_DRVW_PERFORM_RESET_API    (STD_ON)

/**
* @brief Enable/Disable the API to get the current power mode state.
*/
#define MCU_DRVW_POWERMODE_STATE_API    (STD_ON)

/**
* @brief Switch to enable PLL monitor API.
*/
#define MCU_DRVW_ENABLE_PLL_MONITOR_API (SCC_DRV_ENABLE_PLL_MONITOR_API)

/**
* @brief            Maximum number of MCU Ram configurations.
*/

#define MCU_DRVW_MAX_NORAMCONFIGS
#define MCU_DRVW_CLOCK_CONFIG_EXT \
    MCU_DRVW_CLOCK_CONFIG_PB

#define MCU_DRVW_CONFIG_EXT \
    MCU_DRVW_CONFIG_PB

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

#endif /* #ifndef MCU_DRVW_CFG_H */

/** @} end of group Mcu_Drvw_Configuration */

/** @} end of group Mcu_Module */
