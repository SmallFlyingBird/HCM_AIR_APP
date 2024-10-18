/**************************************************************************************************/
/**
 * @file      : Stim_Drv_Types.h
 * @brief     : Stim module type definition header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef STIM_DRV_TYPES_H
#define STIM_DRV_TYPES_H

/** @addtogroup  Gpt_Module
 *  @{
 */

/** @addtogroup Stim_Drv
 *  @brief Gpt low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "McalLib.h"
#include "Stim_Drv_Cfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define STIM_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define STIM_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define STIM_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define STIM_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define STIM_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define STIM_DRV_TYPES_H_SW_MINOR_VERSION            2U
#define STIM_DRV_TYPES_H_SW_PATCH_VERSION            1U

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if ((STIM_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) ||            \
         (STIM_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Stim_Drv_Types.h and Std_Types.h are different"
    #endif
    /* Check if current file and McalLib header file are of the same software version */
    #if ((STIM_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) ||        \
         (STIM_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Stim_Drv_Types.h and McalLib.h are different"
    #endif
#endif

/* Check if current file and Stim_Drv_Cfg header file are of the same vendor */
#if (STIM_DRV_TYPES_H_VENDOR_ID != STIM_DRV_CFG_H_VENDOR_ID)
    #error "Vendor ID of Stim_Drv_Types.h and Stim_Drv_Cfg.h are different"
#endif
/* Check if current file and Stim_Drv_Cfg header file are of the same software version */
#if ((STIM_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != STIM_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) ||     \
     (STIM_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != STIM_DRV_CFG_H_AR_RELEASE_MINOR_VERSION) ||     \
     (STIM_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION != STIM_DRV_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "Software Version of Stim_Drv_Types.h and Stim_Drv_Cfg.h are different"
#endif
/* Check if current file and Stim_Drv_Cfg header file are of the same software version */
#if ((STIM_DRV_TYPES_H_SW_MAJOR_VERSION != STIM_DRV_CFG_H_SW_MAJOR_VERSION) ||                     \
     (STIM_DRV_TYPES_H_SW_MINOR_VERSION != STIM_DRV_CFG_H_SW_MINOR_VERSION) ||                     \
     (STIM_DRV_TYPES_H_SW_PATCH_VERSION != STIM_DRV_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Stim_Drv_Types.h and Stim_Drv_Cfg.h are different"
#endif
/** @} end of Public_MacroDefinition */

/**
 * @brief STIM timeout
 */
#define E_TIMEOUT 0x03
/**
 * @brief     Define Mode
 * @details   Mode type (MODE)
 */
#define STIM_DRV_TIMER_MODE ((uint32)(0x00))

/**
 * @brief     Stim module's instance number
 */
#define STIM_DRV_INSTANCE_COUNT (1u)

/**
 * @brief     Stim channel number
 */
#define STIM_DRV_CHANNEL_COUNT  (4u)

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */
/**
 *  @brief Enum defining the stim clock source type
 */
typedef enum
{
    STIM_DRV_FUNCTION_CLOCK = 0U, /*!< Select stim function clock as counter clock source. */
    STIM_DRV_BUS_CLOCK,           /*!< Select bus clock as counter clock source. */
    STIM_DRV_OSC40M,              /*!< Select OSC40M as counter clock source. */
    STIM_DRV_LPO32K               /*!< Select LPO32K as counter clock source. */
} Stim_Drv_ClockSourceType;

/**
 * @brief Enum defining the stim status error type
 */
typedef enum
{
    STIM_DRV_SUCCESS = E_OK,     /*!< Status value is SUCCESS */
    STIM_DRV_ERROR = E_NOT_OK,   /*!< Status value is ERROR */
    STIM_DRV_TIMEOUT = E_TIMEOUT /*!< Status value is TIMEOUT */
} Stim_Drv_StatusType;

/**
 *  @brief Enum defining the stim prescaler divider factor type
 */
typedef enum
{
    STIM_DRV_DIV_2 = 0U, /*!< divide the system clock by 2 as counter clock. */
    STIM_DRV_DIV_4,      /*!< divide the system clock by 4 as counter clock. */
    STIM_DRV_DIV_8,      /*!< divide the system clock by 8 as counter clock. */
    STIM_DRV_DIV_16,     /*!< divide the system clock by 16 as counter clock. */
    STIM_DRV_DIV_32,     /*!< divide the system clock by 32 as counter clock */
    STIM_DRV_DIV_64,     /*!< divide the system clock by 64 as counter clock. */
    STIM_DRV_DIV_128,    /*!< divide the system clock by 128 as counter clock. */
    STIM_DRV_DIV_256,    /*!< divide the system clock by 256 as counter clock. */
    STIM_DRV_DIV_512,    /*!< divide the system clock by 512 as counter clock. */
    STIM_DRV_DIV_1024,   /*!< divide the system clock by 1024 as counter clock. */
    STIM_DRV_DIV_2048,   /*!< divide the system clock by 2048 as counter clock. */
    STIM_DRV_DIV_4096,   /*!< divide the system clock by 4096 as counter clock. */
    STIM_DRV_DIV_8192,   /*!< divide the system clock by 8192 as counter clock. */
    STIM_DRV_DIV_16384,  /*!< divide the system clock by 16384 as counter clock. */
    STIM_DRV_DIV_32768,  /*!< divide the system clock by 32768 as counter clock. */
    STIM_DRV_DIV_65536   /*!< divide the system clock by 65536 as counter clock. */
} Stim_Drv_PrescalerType;

/**
 * @brief    Enum defining the stim dual mode.
 */
#if (STIM_DRV_SET_DUAL_CLOCK_MODE == STD_ON)
typedef enum
{
    STIM_DRV_CLOCKMODE_NORMAL = 0x0U, /*!< Configure prescaler by noraml */
    STIM_DRV_CLOCKMODE_ALTERNATE      /*!< Configure prescaler by alternate */
} Stim_Drv_DualClockModeType;
#endif /* STIM_DRV_SET_DUAL_CLOCK_MODE */

/**
 * @brief  Callback type for each channel
 */
typedef void (*Stim_Drv_CallbackType)(uint8 CallbackParam);

/**
 * @brief  Structure defining the configuration for stim
 *
 */
typedef struct
{
    uint8   HwChannel;       /*!< stim channel number */
    boolean PrescalerEnable; /*!< - TURE: prescaler Enable
                                  - FALSE: prescaler Disable */
#if (STIM_DRV_SET_DUAL_CLOCK_MODE == STD_ON)
    Stim_Drv_PrescalerType ClockAlternatePrescaler; /*!< The clock alternate prescaler value*/
#endif
    Stim_Drv_PrescalerType   ClockPrescaler; /*!< Clock prescaler value */
    Stim_Drv_ClockSourceType ClockSource;    /*!< STIM clock source type */
    Stim_Drv_CallbackType    Callback;       /*!< Stim interrupt Callback */
    uint8                    CallbackParam;  /*!< Pointer to callback parameters */
} Stim_Drv_ChannelConfigType;

/**
 * @brief  Structure defining the state for stim
 */
typedef struct
{
    boolean               ChannelInit;   /*!< Channel init */
    Stim_Drv_CallbackType Callback;      /*!< Callback  */
    uint8                 CallbackParam; /*!< CallbackParam */
} Stim_Drv_StateType;

/**
 * @brief  Structure defining the clock state for stim
 */
typedef struct
{
    Stim_Drv_PrescalerType ClockPrescaler;          /*!< Clock prescaler value  */
    Stim_Drv_PrescalerType ClockAlternatePrescaler; /*!< The clock alternate prescaler value */
} Stim_Drv_ClockStateType;

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

/** @} end of group Stim_Drv */

/** @} end of group Stim_Module */

#endif /* STIM_DRV_H */
