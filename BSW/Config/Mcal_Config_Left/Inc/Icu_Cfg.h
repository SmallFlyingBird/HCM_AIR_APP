/**************************************************************************************************/
/**
 * @file      : Icu_Cfg.h
 * @brief     : AUTOSAR Icu pre-compile configure head file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef ICU_CFG_H
#define ICU_CFG_H

/** @addtogroup  Icu_Module
 *  @{
 */

/** @addtogroup  Icu
 *  @{
 */

#ifdef __cplusplus
extern "C"
{
#endif

#include "Icu_PBcfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
#define ICU_CFG_H_VENDOR_ID                   0x00B3U
#define ICU_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define ICU_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define ICU_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define ICU_CFG_H_SW_MAJOR_VERSION            1U
#define ICU_CFG_H_SW_MINOR_VERSION            2U
#define ICU_CFG_H_SW_PATCH_VERSION            1U

#if (ICU_CFG_H_VENDOR_ID != ICU_PBCFG_H_VENDOR_ID)
    #error "Vendor ID Icu_Cfg.h and Icu_PBcfg.h have different"
#endif

#if ((ICU_CFG_H_AR_RELEASE_MAJOR_VERSION != ICU_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
        (ICU_CFG_H_AR_RELEASE_MINOR_VERSION != ICU_PBCFG_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Icu_Cfg.h and Icu_PBcfg.h are different"
#endif

#if ((ICU_CFG_H_AR_RELEASE_REVISION_VERSION != ICU_PBCFG_H_AR_RELEASE_REVISION_VERSION) || \
        (ICU_CFG_H_SW_PATCH_VERSION != ICU_PBCFG_H_SW_PATCH_VERSION))
    #error "AutoSar Version Numbers of Icu_Cfg.h and Icu_PBcfg.h are different"
#endif

#if ((ICU_CFG_H_SW_MAJOR_VERSION != ICU_PBCFG_H_SW_MAJOR_VERSION) || \
        (ICU_CFG_H_SW_MINOR_VERSION != ICU_PBCFG_H_SW_MINOR_VERSION))
    #error "Software Version Numbers of Icu_Cfg.h and Icu_PBcfg.h are different"
#endif


#define ICU_CHANNEL_MAXNUM                  ((Icu_ChannelType)1U)

#define ICU_DEV_ERROR_DETECT                (STD_OFF)

#define ICU_DEM_EVENT_REPORT                (STD_OFF)

#define ICU_WAKEUP_SOURCE_REPORT             (STD_OFF)

#define ICU_GET_VERSION_INFO_API              (STD_ON)

#define ICU_DEINIT_API                      (STD_ON)

#define ICU_SET_MODE_API                     (STD_ON)

#define ICU_DISABLE_WAKEUP_API               (STD_ON)

#define ICU_ENABLE_WAKEUP_API                (STD_ON)

#define ICU_TIMESTAMP_API                   (STD_ON)

#define ICU_EDGE_COUNT_API                   (STD_ON)

#define ICU_GET_TIMEELAPSED_API              (STD_ON)

#define ICU_GET_DUTY_CYCLE_VALUES_API          (STD_ON)

#define ICU_GET_INPUT_STATE_API               (STD_ON)

#define ICU_SIGNAL_MEASUREMENT_API           (STD_ON)

#define ICU_WAKEUP_FUNCTIONALITY_API         (STD_ON)

#define ICU_EDGE_DETECT_API                  (STD_ON)

#define ICU_OVERFLOW_NOTIFICATION_API        (STD_OFF)


#define IcuConf_IcuChannel_FAN_CTR_DIAG  ((Icu_ChannelType)0U) 

#define IcuConf_IcuInstanceId_0  ((Icu_InstanceType)0U) 


/**
* @brief Defines ICU configuration
*/
#define ICU_CONFIG_EXT \
    ICU_CONFIG_PB


#define ICU_SIGNAL_MEASUREMENT_DMA_USE      (STD_OFF)

#define ICU_TIMESTAMP_DMA_USE              (STD_OFF)

#if ((STD_ON == ICU_SIGNAL_MEASUREMENT_DMA_USE) || (STD_ON == ICU_TIMESTAMP_DMA_USE))
#define ICU_CAPTURE_REG_MAX                ((Icu_Drvw_ValueType)0xFFFFU)

#define ICU_INVALID_DMACHANNEL             (0xFFFFFFFFU)

#define ICU_DMA_TRANSFER_SIZE              (DMA_TRANSFER_SIZE_2BYTE)

#define ICU_DMA_MINORLOOP_OFFSET           (2U)

#define ICU_DMA_TRANSFER_NUM               (2U)
#endif

#define ICU_PARTITIONS_MAXNUM              (1U)

/** @} end of group Public_MacroDefinition */

/** @defgroup Public_TypeDefinition 
 *  @{
 */

typedef uint16 Icu_TimCounterWidthType;

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
    
/** @} end of group Icu  */
/** @} end of group Icu_Module */

#endif /* ICU_CFG_H */

