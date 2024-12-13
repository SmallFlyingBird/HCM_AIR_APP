/**************************************************************************************************/
/**
 * @file      : Mcu_Cfg.h
 * @brief     : AUTOSAR Mcu - Pre-Compile(PC) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup Mcu_Module
 *  @{
 */

/** @addtogroup Mcu_Configuration
 *  @brief Mcu driver configuration
 *  @{
 */

#ifndef MCU_CFG_H
#define MCU_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Mcu_PBcfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

#define MCU_CFG_H_VENDOR_ID                   0x00B3U
#define MCU_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define MCU_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define MCU_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define MCU_CFG_H_SW_MAJOR_VERSION            1U
#define MCU_CFG_H_SW_MINOR_VERSION            2U
#define MCU_CFG_H_SW_PATCH_VERSION            2U

/* Check if current file and Mcu_PBcfg header file are of the same vendor */
#if (MCU_CFG_H_VENDOR_ID != MCU_PBCFG_H_VENDOR_ID)
    #error "Vendor ID of Mcu_Cfg.h and Mcu_PBcfg.h are different"
#endif
    /* Check if current file and Mcu_PBcfg header file are of the same Autosar version */
#if ((MCU_CFG_H_AR_RELEASE_MAJOR_VERSION != MCU_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_CFG_H_AR_RELEASE_MINOR_VERSION != MCU_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
     (MCU_CFG_H_AR_RELEASE_REVISION_VERSION != MCU_PBCFG_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Mcu_Cfg.h and Mcu_PBcfg.h are different"
#endif
/* Check if current file and Mcu_PBcfg header file are of the same software version */
#if ((MCU_CFG_H_SW_MAJOR_VERSION != MCU_PBCFG_H_SW_MAJOR_VERSION) || \
     (MCU_CFG_H_SW_MINOR_VERSION != MCU_PBCFG_H_SW_MINOR_VERSION) || \
     (MCU_CFG_H_SW_PATCH_VERSION != MCU_PBCFG_H_SW_PATCH_VERSION))
#error "Software Version of Mcu_Cfg.h and Mcu_PBcfg.h are different"
#endif

/**
* @brief Pre-processor switch to enable/disable the use of the function Mcu_PerformReset().
*/
#define MCU_PERFORM_RESET_API    (STD_OFF)

#if (MCU_PERFORM_RESET_API == STD_ON)
/**
* @brief Pre-processor switch to enable/disable to call user defined function before performing reset.
*/
#define MCU_PRIOR_RESET_CALLOUT_USED    (STD_OFF)
#endif

/**
* @brief Switches the development error detection and notification on or off.
*/
#define MCU_DEV_ERROR_DETECT    (STD_OFF)

#if (MCU_DEV_ERROR_DETECT == STD_ON)
/**
* @brief  Default MCU reset raw value.
*/
#define MCU_RAW_RESET_DEFAULT      ((uint32)0xFFFFFFFFUL)

#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */


/**
* @brief Pre-processor switch to enable/disable the API Mcu_GetRamState.
*/
#define MCU_GET_RAM_STATE_API    (STD_OFF)

/**
* @brief If this parameter is set to FALSE, the clock initialization has to be disabled from the MCU driver.
*/
#define MCU_INIT_CLOCK    (STD_ON)

/**
* @brief This parameter shall be set True, if the H/W does not have a PLL or the PLL circuitry is enabled after the power on without S/W intervention.
*/
#define MCU_NO_PLL    (STD_OFF)


/**
* @brief Pre-processor switch to enable/disable the API to read out the modules version information.
*/
#define MCU_VERSION_INFO_API    (STD_OFF)

/**
* @brief Pre-processor switch to enable/disable the API Mcu_GetPowerModeState.
*/
#define MCU_POWERMODE_STATE_API    (STD_OFF)

/**
* @brief Pre-compile Support.
*/
#define MCU_PRECOMPILE_SUPPORT    (STD_ON)

/**
* @brief Switch to enable/disable the API Mcu_EnablePllClockMonitor.
*/
#define MCU_ENABLE_PLL_MONITOR_API (MCU_DRVW_ENABLE_PLL_MONITOR_API)

/**
* @brief Maximum number of MCU Ram configurations.
*/
#define MCU_MAX_RAMCONFIGS   ((uint32)0U)

#define MCU_MAX_NORAMCONFIGS
/**
* @brief Pre-processor switch to enable/disable Hardware test.
*/
#define MCU_HW_TEST_ENABLED    (STD_OFF)

#if (MCU_HW_TEST_ENABLED == STD_ON)
/**
* @brief API to get current hardware test state.
*/
#define MCU_GET_HARDWARE_TEST_STATE_FUNC    (NULL_PTR)
#endif

/**
* @brief Maximum number of MCU mode configurations.
*/
#define MCU_MAX_MODECONFIGS    ((uint32)1U)

/**
* @brief Maximum number of MCU clock configurations.
*/
#define MCU_MAX_CLKCONFIGS    ((uint32)1U)

/**
* @brief Defines MCU_E_CLOCK_FAILURE enable or not
*/
#define MCU_E_CLOCK_FAILURE_ENABLE    (STD_OFF)


/**
 * @brief   Symbolic names of MCU clock setting ID.
 */
#define McuConf_McuClockSettingConfig_McuClockSettingConfig_0    (0U)

/**
 * @brief   Symbolic names of MCU mode.
 */
#define McuConf_McuModeSettingConf_McuModeSettingConf_0    (0U)

/**
 * @brief   Symbolic names of MCU reset reason.
 */
#define McuConf_McuResetReasonConf_McuResetReasonConf_0    (5U)

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

#endif /* #ifndef MCU_CFG_H */

/** @} end of group Mcu_Configuration */

/** @} end of group Mcu_Module */
