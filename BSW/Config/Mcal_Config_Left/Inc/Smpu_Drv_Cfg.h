/**************************************************************************************************/
/**
 * @file      : Smpu_Drv_Cfg.h
 * @brief     : System memory protect unit configration header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef SMPU_DRV_CFG_H
#define SMPU_DRV_CFG_H

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

/** @defgroup Public_MacroDefinition
 *  @{
 */

/**
 *  @brief Published information
 */
#define SMPU_DRV_CFG_H_VENDOR_ID                   0x00B3U
#define SMPU_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define SMPU_DRV_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define SMPU_DRV_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define SMPU_DRV_CFG_H_SW_MAJOR_VERSION            1U
#define SMPU_DRV_CFG_H_SW_MINOR_VERSION            1U
#define SMPU_DRV_CFG_H_SW_PATCH_VERSION            0U

/**
 * @brief Development error detection enabled/disabled ((STD_ON)/(STD_OFF)).
 */
#define SMPU_DRV_DEV_ERROR_DETECT    (STD_ON)

/** @} end of group Public_MacroDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Smpu */

/** @} end of group Smpu_Module */
#endif /* SMPU_DRV_CFG_H */
