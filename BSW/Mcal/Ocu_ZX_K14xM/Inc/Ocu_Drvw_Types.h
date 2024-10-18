/**************************************************************************************************/
/**
 * @file      : Ocu_Drvw_Types.h
 * @brief     : Ocu driver wrapper type definition file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Ocu_Module
 *  @{
 */

/** @addtogroup Ocu_Drvw_Types
 *  @brief Ocu driver
 *  @{
 */

#ifndef OCU_DRVW_TYPES_H
#define OCU_DRVW_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Ocu_Drvw_Cfg.h"
#include "Tim_Ocu_Drv_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define OCU_DRVW_TYPES_H_VENDOR_ID                   0x00B3U
#define OCU_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define OCU_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define OCU_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define OCU_DRVW_TYPES_H_SW_MAJOR_VERSION            1U
#define OCU_DRVW_TYPES_H_SW_MINOR_VERSION            2U
#define OCU_DRVW_TYPES_H_SW_PATCH_VERSION            1U

/* Check if current file and Tim_Ocu_Drv_Types.h are the same vendor */
#if (OCU_DRVW_TYPES_H_VENDOR_ID != TIM_OCU_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Ocu_Drvw_Types.h and Tim_Ocu_Drv_Types.h are different"
#endif
/* Check if current file and Tim_Ocu_Drv_Types.h are the same Autosar version */
#if ((OCU_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION != TIM_OCU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||    \
     (OCU_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION != TIM_OCU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||    \
     (OCU_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION !=                                              \
      TIM_OCU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Ocu_Drvw_Types.h and Tim_Ocu_Drv_Types.h are different"
#endif
/* Check if current file and Tim_Ocu_Drv_Types.h are the same Software version */
#if ((OCU_DRVW_TYPES_H_SW_MAJOR_VERSION != TIM_OCU_DRV_TYPES_H_SW_MAJOR_VERSION) ||                    \
     (OCU_DRVW_TYPES_H_SW_MINOR_VERSION != TIM_OCU_DRV_TYPES_H_SW_MINOR_VERSION) ||                    \
     (OCU_DRVW_TYPES_H_SW_PATCH_VERSION != TIM_OCU_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Ocu_Drvw_Types.h and Tim_Ocu_Drv_Types.h are different"
#endif

/* Check if current file and Ocu_Drvw_Cfg.h are the same vendor */
#if (OCU_DRVW_TYPES_H_VENDOR_ID != OCU_DRVW_CFG_H_VENDOR_ID)
    #error "Vendor ID of Ocu_Drvw_Types.h and Ocu_Drvw_Cfg.h are different"
#endif
/* Check if current file and Ocu_Drvw_Cfg.h are the same Autosar version */
#if ((OCU_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION != OCU_DRVW_CFG_H_AR_RELEASE_MAJOR_VERSION) ||     \
     (OCU_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION != OCU_DRVW_CFG_H_AR_RELEASE_MINOR_VERSION) ||     \
     (OCU_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION != OCU_DRVW_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Ocu_Drvw_Types.h and Ocu_Drvw_Cfg.h are different"
#endif
/* Check if current file and Ocu_Drvw_Cfg.h are the same Software version */
#if ((OCU_DRVW_TYPES_H_SW_MAJOR_VERSION != OCU_DRVW_CFG_H_SW_MAJOR_VERSION) ||                     \
     (OCU_DRVW_TYPES_H_SW_MINOR_VERSION != OCU_DRVW_CFG_H_SW_MINOR_VERSION) ||                     \
     (OCU_DRVW_TYPES_H_SW_PATCH_VERSION != OCU_DRVW_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Ocu_Drvw_Types.h and Ocu_Drvw_Cfg.h are different"
#endif

/**
 * @brief Ocu Tim_Ocu_Drv_PinActionType typedef
 */
typedef uint8 Ocu_Drvw_PinActionType;

/**
 * @brief Ocu Tim_Ocu_Drv_PinStateType typedef
 */
typedef uint8 Ocu_Drvw_PinStateType;

/**
 * @brief Ocu Tim_Ocu_Drv_ReturnType typedef
 */
typedef uint8 Ocu_Drvw_ReturnType;

/**
 * @brief Ocu TIM channel type
 */
#define OCU_DRVW_TIM_CHANNEL     (0U)

#ifndef OCU_DRVW_PIN_STATE_TYPE
#define OCU_DRVW_PIN_STATE_TYPE              Ocu_Drvw_PinStateType
#endif

#ifndef OCU_DRVW_PIN_ACTION_TYPE
#define OCU_DRVW_PIN_ACTION_TYPE             Ocu_Drvw_PinActionType
#endif

#ifndef OCU_DRVW_RETURN_TYPE
#define OCU_DRVW_RETURN_TYPE                 Ocu_Drvw_ReturnType
#endif

/**
 * @brief Ocu compare match will occur in the Interval.
 */
#define OCU_DRVW_CM_IN_REF_INTERVAL  0U

/**
 * @brief Ocu compare match will occur out the Interval.
 */
#define OCU_DRVW_CM_OUT_REF_INTERVAL 1U

/**
 * @brief Ocu TIM channel config type typedef
 */
typedef struct 
{
    const uint8 ChannelHwType; /*!< TIM used for the OCU channel */
    const uint16 ChannelIndex; /*!< TIM configuration in wrapper level */
} Ocu_Drvw_ChannelConfigType;

/**
 * @brief TIM configuration structure in wrapper level
 */
typedef struct
{  
    const Tim_Ocu_Drv_ModuleConfigType * const ModuleConfigPtr; /*!< TIM configuration structure in driver level */    
    const Ocu_Drvw_ChannelConfigType (*ChannelsConfigPtr)[]; /*!< TIM channels configuration structure in wrapper level */
} Ocu_Drvw_ConfigType;

#ifdef __cplusplus
}
#endif

/** @} end of group Ocu_Drvw_Types */

/** @} end of group Ocu_Module */

#endif    /* OCU_DRVW_TYPES_H */
