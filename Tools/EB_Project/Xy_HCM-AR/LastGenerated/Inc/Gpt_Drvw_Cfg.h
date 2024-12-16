/**************************************************************************************************/
/**
 * @file      : Gpt_Drvw_Cfg.h  
 * @brief     : AUTOSAR Gpt Drvw - Pre-Compile(PC) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef GPT_DRVW_CFG_H
#define GPT_DRVW_CFG_H

/** @addtogroup Gpt_Module
 *  @{
 */

/** @addtogroup Gpt_Drvw_Configuration
 *  @brief Gpt driver wrapper configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif
#include "Gpt_Drvw_PBcfg.h"
/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define GPT_DRVW_CFG_H_VENDOR_ID                   0x00B3U
#define GPT_DRVW_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define GPT_DRVW_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define GPT_DRVW_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define GPT_DRVW_CFG_H_SW_MAJOR_VERSION            1U
#define GPT_DRVW_CFG_H_SW_MINOR_VERSION            2U
#define GPT_DRVW_CFG_H_SW_PATCH_VERSION            2U

/* Check if current file and Gpt_Drvw_PBcfg.h are the same vendor */
#if (GPT_DRVW_CFG_H_VENDOR_ID != GPT_DRVW_PBCFG_H_VENDOR_ID)
    #error "Vendor ID of Gpt_Drvw_Cfg.h and Gpt_Drvw_PBcfg.h are different"
#endif
    /* Check if current file and Gpt_Drvw_PBcfg.h are the same Autosar version */
#if ((GPT_DRVW_CFG_H_AR_RELEASE_MAJOR_VERSION != GPT_DRVW_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_DRVW_CFG_H_AR_RELEASE_MINOR_VERSION != GPT_DRVW_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
     (GPT_DRVW_CFG_H_AR_RELEASE_REVISION_VERSION != GPT_DRVW_PBCFG_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Gpt_Drvw_Cfg.h and Gpt_Drvw_PBcfg.h are different"
#endif
/* Check if current file and Gpt_Drvw_PBcfg.h are the same software version */
#if ((GPT_DRVW_CFG_H_SW_MAJOR_VERSION != GPT_DRVW_PBCFG_H_SW_MAJOR_VERSION) || \
     (GPT_DRVW_CFG_H_SW_MINOR_VERSION != GPT_DRVW_PBCFG_H_SW_MINOR_VERSION) || \
     (GPT_DRVW_CFG_H_SW_PATCH_VERSION != GPT_DRVW_PBCFG_H_SW_PATCH_VERSION))
#error "Software Version of Gpt_Drvw_Cfg.h and Gpt_Drvw_PBcfg.h are different"
#endif

#define GPT_DRVW_CONFIG_EXT \
    GPT_DRVW_CONFIG_PB

/**
 * @brief  Switches the Gpt wakeup functionality ON or OFF.
 */ 
#define GPT_DRVW_WAKEUP_FUNCTIONALITY_API      (STD_ON)

/**
 * @brief  Switches the predefined timer functionality ON or OFF.
 */
#define GPT_DRVW_PREDEFTIMER_FUNCTIONALITY_API   (STD_ON)

/**
 * @brief  Switches the Gpt deinit functionality ON or OFF.
 */
#define GPT_DRVW_DEINIT_API               (STD_ON)

/**
* @brief   Switches the Gpt enable/disable notification functionality ON or OFF.
*/
#define GPT_DRVW_ENABLE_DISABLE_NOTIFICATION_API    (STD_ON)

/**
 * @brief  Switches the dual mode functionality ON or OFF.
 */
#define GPT_DRVW_SET_DUAL_CLOCK_MODE           (STD_OFF)
/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Gpt_Drvw_Configuration */

/** @} end of group Gpt_Module */

#endif 
