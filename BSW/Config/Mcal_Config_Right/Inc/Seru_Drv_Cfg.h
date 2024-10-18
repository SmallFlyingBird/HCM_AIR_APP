/**************************************************************************************************/
/**
 * @file      : Seru_Drv_Cfg.h
 * @brief     : Meh Extended MicroController Error Handle configuration header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef SERU_DRV_CFG_H
#define SERU_DRV_CFG_H

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
#include "Seru_Drv_PBcfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/**
 *  @brief Published information
 */
#define SERU_DRV_CFG_H_VENDOR_ID                   0x00B3U
#define SERU_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define SERU_DRV_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define SERU_DRV_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define SERU_DRV_CFG_H_SW_MAJOR_VERSION            1U
#define SERU_DRV_CFG_H_SW_MINOR_VERSION            1U
#define SERU_DRV_CFG_H_SW_PATCH_VERSION            0U

/* Check if current file and Seru_Drv_PBcfg.h are the same vendor */
#if (SERU_DRV_CFG_H_VENDOR_ID != SERU_DRV_PBCFG_H_VENDOR_ID)
    #error "Vendor ID of Seru_Drv_Cfg.h and Seru_Drv_PBcfg.h are different"
#endif
/* Check if current file and Seru_Drv_PBcfg.h are the same Autosar version */
#if ((SERU_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION != SERU_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (SERU_DRV_CFG_H_AR_RELEASE_MINOR_VERSION != SERU_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
     (SERU_DRV_CFG_H_AR_RELEASE_REVISION_VERSION != SERU_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version of Seru_Drv_Cfg.h and Seru_Drv_PBcfg.h are different"
#endif
/* Check if current file and Seru_Drv_PBcfg.h are the same software version */
#if ((SERU_DRV_CFG_H_SW_MAJOR_VERSION != SERU_DRV_PBCFG_H_SW_MAJOR_VERSION) || \
     (SERU_DRV_CFG_H_SW_MINOR_VERSION != SERU_DRV_PBCFG_H_SW_MINOR_VERSION) || \
     (SERU_DRV_CFG_H_SW_PATCH_VERSION != SERU_DRV_PBCFG_H_SW_PATCH_VERSION) \
    )
    #error "Software Version of Seru_Drv_Cfg.h and Seru_Drv_PBcfg.h are different"
#endif

/**
 * @brief Development error detection enabled/disabled ((STD_ON)/(STD_OFF)).
 */
#define SERU_DRV_DEV_ERROR_DETECT                                                                       \
    (STD_OFF)

/**
 * @brief Defines Seru Driver configuration.
 */
#define SERU_DRV_CONFIG_EXT \
        SERU_DRV_CONFIG_PB

/** 
* @brief  Defines the seru parity error ISR switch in Drv level
*/
#define SERU_DRV_PARITY_ERROR_ISR_ENABLED    (STD_ON)

/** 
* @brief  Defines the seru channel error ISR switch in Drv level
*/
#define SERU_DRV_CHANNEL_ERROR_ISR_ENABLED   (STD_ON)
/** @} end of Public_MacroDefinition */


#ifdef __cplusplus
}
#endif

/** @} end of group Meh_cfg */

/** @} end of group Meh_Module */
#endif /* SERU_DRV_CFG_H */
