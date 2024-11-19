/**************************************************************************************************/
/**
 * @file      : Icu_Drvw_Cfg.h
 * @brief     : AUTOSAR Icu Drvw pre-compile configure head file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef ICU_DRVW_CFG_H
#define ICU_DRVW_CFG_H

/** @addtogroup  Icu_Module
 *  @{
 */

/** @addtogroup  Icu_Drvw
 *  @{
 */

#ifdef __cplusplus
extern "C"
{
#endif

#include "Icu_Drvw_PBcfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
#define ICU_DRVW_CFG_H_VENDOR_ID                   0x00B3U
#define ICU_DRVW_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define ICU_DRVW_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define ICU_DRVW_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define ICU_DRVW_CFG_H_SW_MAJOR_VERSION            1U
#define ICU_DRVW_CFG_H_SW_MINOR_VERSION            2U
#define ICU_DRVW_CFG_H_SW_PATCH_VERSION            2U

#if (ICU_DRVW_CFG_H_VENDOR_ID != ICU_DRVW_PBCFG_H_VENDOR_ID)
    #error "Vendor ID Icu_Drvw_Cfg.h and Icu_Drvw_PBcfg.h have different"
#endif

#if ((ICU_DRVW_CFG_H_AR_RELEASE_MAJOR_VERSION != ICU_DRVW_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
        (ICU_DRVW_CFG_H_AR_RELEASE_MINOR_VERSION != ICU_DRVW_PBCFG_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Icu_Drvw_Cfg.h and Icu_Drvw_PBcfg.h are different"
#endif

#if ((ICU_DRVW_CFG_H_AR_RELEASE_REVISION_VERSION != ICU_DRVW_PBCFG_H_AR_RELEASE_REVISION_VERSION) || \
        (ICU_DRVW_CFG_H_SW_PATCH_VERSION != ICU_DRVW_PBCFG_H_SW_PATCH_VERSION))
    #error "AutoSar Version Numbers of Icu_Drvw_Cfg.h and Icu_Drvw_PBcfg.h are different"
#endif


#if ((ICU_DRVW_CFG_H_SW_MAJOR_VERSION != ICU_DRVW_PBCFG_H_SW_MAJOR_VERSION) || \
        (ICU_DRVW_CFG_H_SW_MINOR_VERSION != ICU_DRVW_PBCFG_H_SW_MINOR_VERSION))
    #error "Software Version Numbers of Icu_Drvw_Cfg.h and Icu_Drvw_PBcfg.h are different"
#endif

#define ICU_PRECOMPILE_SUPPORT              (STD_OFF)

#define ICU_DRVW_DEINIT_API                      (STD_ON)

#define ICU_DRVW_SET_MODE_API                     (STD_ON)

#define ICU_DRVW_TIMESTAMP_API                   (STD_ON)

#define ICU_DRVW_EDGE_COUNT_API                   (STD_ON)

#define ICU_DRVW_GET_TIMEELAPSED_API              (STD_ON)

#define ICU_DRVW_GET_DUTYCYCLE_VALUES_API          (STD_ON)

#define ICU_DRVW_GET_INPUT_STATE_API               (STD_ON)

#define ICU_DRVW_SIGNAL_MEASUREMENT_API           (STD_ON)

#define ICU_DRVW_EDGE_DETECT_API                  (STD_ON)

#define ICU_DRVW_OVERFLOW_NOTIFICATION_API        (STD_OFF)


#define ICU_DRVW_SIGNAL_MEASUREMENT_DMA_USE      (STD_OFF)

#define ICU_DRVW_TIMESTAMP_DMA_USE              (STD_OFF)


#if ((STD_ON == ICU_DRVW_SIGNAL_MEASUREMENT_DMA_USE) && (STD_ON == ICU_DRVW_TIMESTAMP_DMA_USE))

#define ICU_DRVW_INVALID_DMACHANNEL             (0xFFFFFFFFU)

#endif

#define ICU_DRVW_CONFIG_EXT \
    ICU_DRVW_CONFIG_PB

/** @} end of group Public_MacroDefinition */

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
        
/** @} end of group Icu_Drvw  */
/** @} end of group Icu_Module */

#endif    /* ICU_DRVW_CFG_H */

