/**************************************************************************************************/
/**
 * @file      : Eiru_Drv_Cfg.h
 * @brief     : Meh Extended MicroController Error Handle configration header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef EIRU_DRV_CFG_H
#define EIRU_DRV_CFG_H

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
#include "Eiru_Drv_PBcfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/**
 *  @brief Published information
 */
#define EIRU_DRV_CFG_H_VENDOR_ID                   0x00B3U
#define EIRU_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define EIRU_DRV_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define EIRU_DRV_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define EIRU_DRV_CFG_H_SW_MAJOR_VERSION            1U
#define EIRU_DRV_CFG_H_SW_MINOR_VERSION            1U
#define EIRU_DRV_CFG_H_SW_PATCH_VERSION            0U

/* Check if current file and Eiru_Drv_PBcfg.h are the same vendor */
#if (EIRU_DRV_CFG_H_VENDOR_ID != EIRU_DRV_PBCFG_H_VENDOR_ID)
    #error "Vendor ID of Eiru_Drv_Cfg.h and Eiru_Drv_PBcfg.h are different"
#endif
/* Check if current file and Eiru_Drv_PBcfg.h are the same Autosar version */
#if ((EIRU_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION != EIRU_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (EIRU_DRV_CFG_H_AR_RELEASE_MINOR_VERSION != EIRU_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
     (EIRU_DRV_CFG_H_AR_RELEASE_REVISION_VERSION != EIRU_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version of Eiru_Drv_Cfg.h and Eiru_Drv_PBcfg.h are different"
#endif
/* Check if current file and Eiru_Drv_PBcfg.h are the same software version */
#if ((EIRU_DRV_CFG_H_SW_MAJOR_VERSION != EIRU_DRV_PBCFG_H_SW_MAJOR_VERSION) || \
     (EIRU_DRV_CFG_H_SW_MINOR_VERSION != EIRU_DRV_PBCFG_H_SW_MINOR_VERSION) || \
     (EIRU_DRV_CFG_H_SW_PATCH_VERSION != EIRU_DRV_PBCFG_H_SW_PATCH_VERSION) \
    )
    #error "Software Version of Eiru_Drv_Cfg.h and Eiru_Drv_PBcfg.h are different"
#endif

/**
 * @brief Development error detection enabled/disabled ((STD_ON)/(STD_OFF)).
 */
#define EIRU_DRV_DEV_ERROR_DETECT          (STD_OFF)

/**
 * @brief Defines Eiru Driver configuration.
 */
#define EIRU_DRV_CONFIG_EXT \
        EIRU_DRV_CONFIG_PB
/** @} end of Public_MacroDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Meh */

/** @} end of group Meh_Module */
#endif /* EIRU_DRV_CFG_H */
