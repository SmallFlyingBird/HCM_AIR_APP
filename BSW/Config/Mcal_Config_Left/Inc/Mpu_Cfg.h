/**************************************************************************************************/
/**
 * @file      : Mpu_Cfg.h
 * @brief     : System memory protect unit configration header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef MPU_CFG_H
#define MPU_CFG_H

/** @addtogroup  Smpu_Module
 *  @{
 */

/** @defgroup Smpu
 *  @brief Smpu configuration value defined
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Mpu_PBCfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/**
 *  @brief Published information
 */
#define MPU_CFG_H_VENDOR_ID                   0x00B3U
#define MPU_CFG_H_MODULE_ID                   2053U
#define MPU_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define MPU_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define MPU_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define MPU_CFG_H_SW_MAJOR_VERSION            1U
#define MPU_CFG_H_SW_MINOR_VERSION            1U
#define MPU_CFG_H_SW_PATCH_VERSION            0U

/**
 *  @brief Check if current file and Mpu_PBCfg.h are of the same vendor
 */
#if (MPU_CFG_H_VENDOR_ID != MPU_PBCFG_H_VENDOR_ID)
    #error "Vendor ID of Mpu_Cfg.h and Mpu_PBCfg.h are different"
#endif

/**
 *  @brief Check if current file and Mpu_PBCfg.h are of the same Autosar version
 */
#if ((MPU_CFG_H_AR_RELEASE_MAJOR_VERSION != MPU_PBCFG_H_AR_RELEASE_MAJOR_VERSION) ||                 \
     (MPU_CFG_H_AR_RELEASE_MINOR_VERSION != MPU_PBCFG_H_AR_RELEASE_MINOR_VERSION) ||                 \
     (MPU_CFG_H_AR_RELEASE_REVISION_VERSION != MPU_PBCFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Mpu_Cfg.h and Mpu_PBCfg.h are different"
#endif

/**
 *  @brief Check if current file and Mpu_PBCfg.h are of the same SW version
 */
#if ((MPU_CFG_H_SW_MAJOR_VERSION != MPU_PBCFG_H_SW_MAJOR_VERSION) ||                                 \
     (MPU_CFG_H_SW_MINOR_VERSION != MPU_PBCFG_H_SW_MINOR_VERSION) ||                                 \
     (MPU_CFG_H_SW_PATCH_VERSION != MPU_PBCFG_H_SW_PATCH_VERSION))
    #error "Software Version of Mpu_Cfg.h and Mpu_PBCfg.h are different"
#endif
/**
 * @brief Development error detection enabled/disabled ((STD_ON)/(STD_OFF)).
 */
#define MPU_DEV_ERROR_DETECT       (STD_ON)

/**
 * @brief Add/remove ((STD_ON)/(STD_OFF)) the service Mpu_GetVersionInfo() from the code.
 */
#define MPU_VERSION_INFO_API      (STD_ON)

/**
* @brief Pre-compile Support.
*/
#define MPU_PRECOMPILE_SUPPORT    (STD_ON)

/** @} end of group Public_MacroDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */



/** @} end of group Global_VariableDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Smpu */

/** @} end of group Smpu_Module */
#endif /* MPU_CFG_H */
