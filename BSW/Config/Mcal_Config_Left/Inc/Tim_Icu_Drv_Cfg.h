/**************************************************************************************************/
/**
 * @file      : Tim_Icu_Drv_Cfg.h
 * @brief     : AUTOSAR Tim Icu Drv pre-compile configure head file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef TIM_ICU_DRV_CFG_H
#define TIM_ICU_DRV_CFG_H

/** @addtogroup  Icu_Module
 *  @{
 */

/** @addtogroup  Icu_Drv
 *  @{
 */

#ifdef __cplusplus
extern "C"
{
#endif

#include "Tim_Icu_Drv_PBcfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
#define TIM_ICU_DRV_CFG_H_VENDOR_ID                   0x00B3U
#define TIM_ICU_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define TIM_ICU_DRV_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define TIM_ICU_DRV_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define TIM_ICU_DRV_CFG_H_SW_MAJOR_VERSION            1U
#define TIM_ICU_DRV_CFG_H_SW_MINOR_VERSION            2U
#define TIM_ICU_DRV_CFG_H_SW_PATCH_VERSION            1U


#if (TIM_ICU_DRV_CFG_H_VENDOR_ID != TIM_ICU_DRV_PBCFG_H_VENDOR_ID)
    #error "Vendor ID Tim_Icu_Drv_Cfg.h and Tim_Icu_Drv_PBcfg.h have different"
#endif

#if ((TIM_ICU_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION != TIM_ICU_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
        (TIM_ICU_DRV_CFG_H_AR_RELEASE_MINOR_VERSION != TIM_ICU_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Tim_Icu_Drv_Cfg.h and Tim_Icu_Drv_PBcfg.h are different"
#endif

#if ((TIM_ICU_DRV_CFG_H_AR_RELEASE_REVISION_VERSION != TIM_ICU_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION) || \
        (TIM_ICU_DRV_CFG_H_SW_PATCH_VERSION != TIM_ICU_DRV_PBCFG_H_SW_PATCH_VERSION))
    #error "AutoSar Version Numbers of Tim_Icu_Drv_Cfg.h and Tim_Icu_Drv_PBcfg.h are different"
#endif

#if ((TIM_ICU_DRV_CFG_H_SW_MAJOR_VERSION != TIM_ICU_DRV_PBCFG_H_SW_MAJOR_VERSION) || \
        (TIM_ICU_DRV_CFG_H_SW_MINOR_VERSION != TIM_ICU_DRV_PBCFG_H_SW_MINOR_VERSION))
    #error "Software Version Numbers of Tim_Icu_Drv_Cfg.h and Tim_Icu_Drv_PBcfg.h are different"
#endif

#define TIM_ICU_DRV_CONFIG_EXT \
    TIM_ICU_DRV_CONFIG_PB

#define TIM_ICU_DRV_INSTANCE_SUMCNT                 (4U)

#define TIM_ICU_DRV_CHANNEL_SUMCNT                  (8U)

#define TIM_ICU_DRV_FILTER_MAXCH                    (4U)

#define TIM_ICU_DRV_DEV_ERROR_DETECT                (STD_OFF)

#define TIM_ICU_DRV_DEM_EVENT_REPORT                (STD_OFF)

#define TIM_ICU_DRV_WAKEUP_SOURCE_REPORT             (STD_OFF)

#define TIM_ICU_DRV_GET_VERSIONINFO_API              (STD_ON)

#define TIM_ICU_DRV_DEINIT_API                      (STD_ON)

#define TIM_ICU_DRV_SET_MODE_API                     (STD_ON)

#define TIM_ICU_DRV_DISABLE_WAKEUP_API               (STD_ON)

#define TIM_ICU_DRV_ENABLE_WAKEUP_API                (STD_ON)

#define TIM_ICU_DRV_TIMESTAMP_API                   (STD_ON)

#define TIM_ICU_DRV_EDGE_COUNT_API                   (STD_ON)

#define TIM_ICU_DRV_GET_TIMEELAPSED_API              (STD_ON)

#define TIM_ICU_DRV_GET_DUTYCYCLE_VALUES_API          (STD_ON)

#define TIM_ICU_DRV_GET_INPUT_STATE_API               (STD_ON)

#define TIM_ICU_DRV_SIGNAL_MEASUREMENT_API           (STD_ON)

#define TIM_ICU_DRV_WAKEUP_FUNCTIONALITY_API         (STD_ON)

#define TIM_ICU_DRV_EDGE_DETECT_API                  (STD_ON)

#define TIM_ICU_DRV_OVERFLOW_NOTIFICATION_API        (STD_OFF)


#define TIM_ICU_DRV_SIGNAL_MEASUREMENT_DMA_USE      (STD_OFF)

#define TIM_ICU_DRV_TIMESTAMP_DMA_USE              (STD_OFF)

#define TIM_ICU_DRV_CAPTURE_REG_MAX                (0xFFFFU)

#ifndef TIM_0_USED
    #define TIM_0_USED
    #define TIM_ICU_DRV_0_ENABLE  (STD_ON)
#else
    #error "TIM 0 instance is locked by another MCAL module!"
#endif

#define TIM_0_ICU_DRV_CH_ISR_USED           (STD_ON)

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
        
/** @} end of group Tim_Icu_Drv  */
/** @} end of group Icu_Module */

#endif    /* TIM_ICU_DRV_CFG_H */

