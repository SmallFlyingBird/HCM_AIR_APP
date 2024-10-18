/**************************************************************************************************/
/**
 * @file      : Mpu_PBcfg.h
 * @brief     : System memory protect unit configuration header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef MPU_PBCFG_H
#define MPU_PBCFG_H

/** @addtogroup  Smpu_Module
 *  @{
 */

/** @defgroup Smpu configuration
 *  @brief Smpu configuration header file
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */

/**
 *  @brief Published information
 */
#define MPU_PBCFG_H_VENDOR_ID                   0x00B3U
#define MPU_PBCFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define MPU_PBCFG_H_AR_RELEASE_MINOR_VERSION    6U
#define MPU_PBCFG_H_AR_RELEASE_REVISION_VERSION 0U
#define MPU_PBCFG_H_SW_MAJOR_VERSION            1U
#define MPU_PBCFG_H_SW_MINOR_VERSION            1U
#define MPU_PBCFG_H_SW_PATCH_VERSION            0U

#define MPU_CONFIG_REGION_NUM     (6U)

/** @} end of group Public_MacroDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */



/** @} end of group Global_VariableDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Smpu configuration */

/** @} end of group Smpu_Module */
#endif /* MPU_PBCFG_H */
