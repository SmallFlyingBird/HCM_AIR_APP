/**************************************************************************************************/
/**
 * @file      : Meh_Cfg.h
 * @brief     : Meh Extended MicroController Error Handle configuration header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef MEH_CFG_H
#define MEH_CFG_H

/** @addtogroup  Meh_Module
 *  @{
 */

/** @defgroup Meh
 *  @brief Meh configuration header file
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Meh_PBcfg.h"
/** @defgroup Public_MacroDefinition
 *  @{
 */

/**
 *  @brief Published information
 */
#define MEH_CFG_H_VENDOR_ID                   0x00B3U
#define MEH_CFG_H_MODULE_ID                   2052U
#define MEH_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define MEH_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define MEH_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define MEH_CFG_H_SW_MAJOR_VERSION            1U
#define MEH_CFG_H_SW_MINOR_VERSION            1U
#define MEH_CFG_H_SW_PATCH_VERSION            0U

/* Check if current file and Meh_PBcfg header file are of the same vendor */
#if (MEH_CFG_H_VENDOR_ID != MEH_PBCFG_H_VENDOR_ID)
    #error "Vendor ID of Meh_Cfg.h and Meh_PBcfg.h are different"
#endif
    /* Check if current file and Meh_PBcfg header file are of the same Autosar version */
#if ((MEH_CFG_H_AR_RELEASE_MAJOR_VERSION != MEH_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (MEH_CFG_H_AR_RELEASE_MINOR_VERSION != MEH_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
     (MEH_CFG_H_AR_RELEASE_REVISION_VERSION != MEH_PBCFG_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Meh_Cfg.h and Meh_PBcfg.h are different"
#endif
/* Check if current file and Meh_PBcfg header file are of the same software version */
#if ((MEH_CFG_H_SW_MAJOR_VERSION != MEH_PBCFG_H_SW_MAJOR_VERSION) || \
     (MEH_CFG_H_SW_MINOR_VERSION != MEH_PBCFG_H_SW_MINOR_VERSION) || \
     (MEH_CFG_H_SW_PATCH_VERSION != MEH_PBCFG_H_SW_PATCH_VERSION))
#error "Software Version of Meh_Cfg.h and Meh_PBcfg.h are different"
#endif

/**
 * @brief Development error detection enabled/disabled ((STD_ON)/(STD_OFF)).
 */
#define MEH_DEV_ERROR_DETECT      (STD_OFF)

/**
 * @brief Add/remove ((STD_ON)/(STD_OFF)) the service Meh_GetVersionInfo() from the code.
 */
#define MEH_VERSION_INFO_API      (STD_OFF)

/**
* @brief Pre-compile Support.
*/
#define MEH_PRECOMPILE_SUPPORT    (STD_ON)

/** @} end of group Private_MacroDefinition */

/** @defgroup Public_MacroDefinition
 *  @{
 */

/** @} end of Public_MacroDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */



/** @} end of group Global_VariableDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Meh_cfg */

/** @} end of group Meh_Module */
#endif /* MEH_CFG_H */
