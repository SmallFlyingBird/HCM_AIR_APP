/**************************************************************************************************/
/**
 * @file      : Tim_Drv_Types.h
 * @brief     : Tim module type definition header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef TIM_DRV_TYPES_H
#define TIM_DRV_TYPES_H

/** @addtogroup  Gpt_Module
 *  @{
 */

/** @addtogroup Tim_Drv
 *  @brief Gpt low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "McalLib.h"
#include "Tim_Drv_Cfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define TIM_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define TIM_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define TIM_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define TIM_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define TIM_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define TIM_DRV_TYPES_H_SW_MINOR_VERSION            2U
#define TIM_DRV_TYPES_H_SW_PATCH_VERSION            2U

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if ((TIM_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) ||             \
         (TIM_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Tim_Drv_Types.h and Std_Types.h are different"
    #endif
    /* Check if current file and McalLib header file are of the same software version */
    #if ((TIM_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) ||         \
         (TIM_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Tim_Drv_Types.h and McalLib.h are different"
    #endif
#endif

/* Check if current file and Tim_Drv_Cfg header file are of the same vendor */
#if (TIM_DRV_TYPES_H_VENDOR_ID != TIM_DRV_CFG_H_VENDOR_ID)
    #error "Vendor ID of Tim_Drv_Types.h and Tim_Drv_Cfg.h are different"
#endif
/* Check if current file and Tim_Drv_Cfg header file are of the same software version */
#if ((TIM_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != TIM_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) ||       \
     (TIM_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != TIM_DRV_CFG_H_AR_RELEASE_MINOR_VERSION) ||       \
     (TIM_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION != TIM_DRV_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "Software Version of Tim_Drv_Types.h and Tim_Drv_Cfg.h are different"
#endif
/* Check if current file and Tim_Drv_Cfg header file are of the same software version */
#if ((TIM_DRV_TYPES_H_SW_MAJOR_VERSION != TIM_DRV_CFG_H_SW_MAJOR_VERSION) ||                       \
     (TIM_DRV_TYPES_H_SW_MINOR_VERSION != TIM_DRV_CFG_H_SW_MINOR_VERSION) ||                       \
     (TIM_DRV_TYPES_H_SW_PATCH_VERSION != TIM_DRV_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Tim_Drv_Types.h and Tim_Drv_Cfg.h are different"
#endif
/** @} end of Public_MacroDefinition */

/**
 * @brief  Tim module's instance number
 */
#define TIM_DRV_INSTANCE_COUNT (4U)

/**
 * @brief  Tim channel number
 */
#define TIM_DRV_CHANNEL_COUNT (8U)

/**
 * @brief  Tim max value
 */
#define TIM_DRV_MAX_VALUE (0x0000FFFFU)

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 *  @brief Enum defining the timer clock source type
 */
typedef enum
{
    TIM_DRV_CLK_SOURCE_DISABLED = 0U, /*!< Timer counter clock is disabled. */
    TIM_DRV_CLK_SOURCE_SYSTEM,        /*!< System Clock as timer Counter Clock. */
    TIM_DRV_CLK_SOURCE_FUNCTION,      /*!< Function Clock as timer Counter Clock. */
    TIM_DRV_CLK_SOURCE_EXTERNAL       /*!< External Clock as timer Counter Clock. */
} Tim_Drv_ClockSourceType;

/**
 *  @brief Enum defining the timer prescaler divider factor type
 */
typedef enum
{
    TIM_DRV_CLK_DIV_1 = 0U, /*!< Timer clock divide by 1 */
    TIM_DRV_CLK_DIV_2,      /*!< Timer clock divide by 2 */
    TIM_DRV_CLK_DIV_4,      /*!< Timer clock divide by 4 */
    TIM_DRV_CLK_DIV_8,      /*!< Timer clock divide by 8 */
    TIM_DRV_CLK_DIV_16,     /*!< Timer clock divide by 16 */
    TIM_DRV_CLK_DIV_32,     /*!< Timer clock divide by 32 */
    TIM_DRV_CLK_DIV_64,     /*!< Timer clock divide by 64 */
    TIM_DRV_CLK_DIV_128     /*!< Timer clock divide by 128 */
} Tim_Drv_PrescalerType;

/**
 *  @brief Enum defining the timer conuting mode type
 */
typedef enum
{
    TIM_DRV_COUNTING_UP = 0U, /*!< Timer Up counting mode */
    TIM_DRV_COUNTING_UP_DOWN  /*!< Timer Up-Down counting mode */
} Tim_Drv_CountingModeType;

/**
 * @brief Enum defining the timer dual mode.
 */
#if (TIM_DRV_SET_DUAL_CLOCK_MODE == STD_ON)
typedef enum
{
    TIM_DRV_CLOCKMODE_NORMAL = 0x0U, /*!< Configure prescaler by noraml */
    TIM_DRV_CLOCKMODE_ALTERNATE      /*!< Configure prescaler by alternate */
} Tim_Drv_DualClockModeType;
#endif /* TIM_DRV_SET_DUAL_CLOCK_MODE */

/**
 * @brief Enum defining the timer channel status type
 */
typedef enum
{
    TIM_DRV_IDLE = 0U,          /*!< Timer channel status is IDEL */
    TIM_DRV_BUSY                /*!< Timer channel is running */
} Tim_Drv_StatusType;

/**
 * @brief  Callback type for each channel
 */
typedef void (*Tim_Drv_CallbackType)(uint8 CallbackParam);

/**
 * @brief  Structure defining the configuration for timer instance
 *
 */
typedef struct
{
    boolean                  FreezeBit;   /*!< Enable/Disable Freeze bit */
    Tim_Drv_ClockSourceType  ClockSource; /*!< Timer clock source type */
#if (TIM_DRV_SET_DUAL_CLOCK_MODE == STD_ON)
    Tim_Drv_PrescalerType    ClockAlternatePrescaler; /*!< The clock alternate prescaler value*/
#endif
    Tim_Drv_PrescalerType    ClockPrescaler; /*!< Clock prescaler value */
    Tim_Drv_CountingModeType Mode;           /*!< Timer conuting mode type */
} Tim_Drv_InstanceConfigType;

/**
 * @brief  Structure defining the configuration for timer channel
 *
 */
typedef struct
{
    uint8 HwChannel;                      /*!< Timer channel number */
    Tim_Drv_ClockSourceType  ClockSource; /*!< Timer instance clock source type */
    Tim_Drv_CallbackType Callback;        /*!< Timer interrupt Callback */
    uint8 CallbackParam;                  /*!< Pointer to callback parameters */
} Tim_Drv_ChannelConfigType;

/**
 * @brief  Structure defining the channel state for timer
 */
typedef struct
{
    Tim_Drv_StatusType   ChannelStatus;   /*!< Channel status */
    Tim_Drv_CallbackType Callback;        /*!< Callback  */
    uint8                CallbackParam;   /*!< CallbackParam */
} Tim_Drv_ChannelStateType;

/**
 * @brief  Structure defining the instance state for timer
 */
typedef struct
{
    Tim_Drv_PrescalerType ClockPrescaler;          /*!< Clock prescaler value  */
    Tim_Drv_PrescalerType ClockAlternatePrescaler; /*!< The clock alternate prescaler value */
} Tim_Drv_InstanceStateType;

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

/** @} end of group Tim_Drv */

/** @} end of group Tim_Module */

#endif /* TIM_DRV_H */
