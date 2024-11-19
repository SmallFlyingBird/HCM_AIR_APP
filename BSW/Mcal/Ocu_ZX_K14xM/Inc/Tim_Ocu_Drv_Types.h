/**************************************************************************************************/
/**
 * @file      : Tim_Ocu_Drv_Types.h
 * @brief     : Ocu low level driver type definition file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Ocu_Module
 *  @{
 */

/** @addtogroup Tim_Ocu_Drv_Types
 *  @brief Ocu driver
 *  @{
 */

#ifndef TIM_OCU_DRV_TYPES_H
#define TIM_OCU_DRV_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#include "McalLib.h"
#include "Tim_Ocu_Drv_Cfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define TIM_OCU_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define TIM_OCU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define TIM_OCU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define TIM_OCU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define TIM_OCU_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define TIM_OCU_DRV_TYPES_H_SW_MINOR_VERSION            2U
#define TIM_OCU_DRV_TYPES_H_SW_PATCH_VERSION            2U

/* Check if current file and Tim_Ocu_Drv_Cfg.h are the same vendor */
#if (TIM_OCU_DRV_TYPES_H_VENDOR_ID != TIM_OCU_DRV_CFG_H_VENDOR_ID)
    #error "Vendor ID of Tim_Ocu_Drv_Types.h and Tim_Ocu_Drv_Cfg.h are different"
#endif
/* Check if current file and Tim_Ocu_Drv_Cfg.h are the same Autosar version */
#if ((TIM_OCU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != TIM_OCU_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) ||       \
     (TIM_OCU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != TIM_OCU_DRV_CFG_H_AR_RELEASE_MINOR_VERSION) ||       \
     (TIM_OCU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION != TIM_OCU_DRV_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Tim_Ocu_Drv_Types.h and Tim_Ocu_Drv_Cfg.h are different"
#endif
/* Check if current file and Tim_Ocu_Drv_Cfg.h are the same software version */
#if ((TIM_OCU_DRV_TYPES_H_SW_MAJOR_VERSION != TIM_OCU_DRV_CFG_H_SW_MAJOR_VERSION) ||                       \
     (TIM_OCU_DRV_TYPES_H_SW_MINOR_VERSION != TIM_OCU_DRV_CFG_H_SW_MINOR_VERSION) ||                       \
     (TIM_OCU_DRV_TYPES_H_SW_PATCH_VERSION != TIM_OCU_DRV_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Tim_Ocu_Drv_Types.h and Tim_Ocu_Drv_Cfg.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and McalLib.h are the same Autosar version */
    #if ((TIM_OCU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) ||         \
         (TIM_OCU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Tim_Ocu_Drv_Types.h and McalLib.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/** @} end of Public_MacroDefinition */

/**
 *@brief Enum the possible states of TIM
 */
typedef enum
{
    TIM_OCU_DRV_STATE_UNINIT = 0, /*!< @brief Ocu driver state - uninitialized */
    TIM_OCU_DRV_STATE_IDLE        /*!< @brief Ocu driver state - Idle */
} Tim_Ocu_Drv_GlobalDrvStateType;

/**
 * @brief Enum the possible states of TIM channels
 */
typedef enum
{
    TIM_OCU_DRV_CH_STATE_UNINITIALIZED = 0, /*!< Ocu channel state - uninitialized */
    TIM_OCU_DRV_CH_STATE_INITIALIZED,       /*!< Ocu channel state - initialized */
    TIM_OCU_DRV_CH_STATE_STOPPED,           /*!< Ocu channel state - stopped */
    TIM_OCU_DRV_CH_STATE_RUNNING            /*!< Ocu channel state - running */
} Tim_Ocu_Drv_ChannelStateType;

/**
 * @brief Enum whether the pin of OCU channel is used.
 */
typedef enum
{
    TIM_OCU_DRV_CH_PIN_UNUSED = 0, /*!< Ocu channel pin - unused */
    TIM_OCU_DRV_CH_PIN_USED        /*!< Ocu channel pin - used */
} Tim_Ocu_Drv_ChannelPinUseType;

/**
 *  @brief TIM ID type definition
 */
typedef enum
{
    TIM_OCU_DRV_ID_0 = 0U,                            /*!< TIM0  */
    TIM_OCU_DRV_ID_1,                                 /*!< TIM1  */
    TIM_OCU_DRV_ID_2,                                 /*!< TIM2  */
    TIM_OCU_DRV_ID_3                                  /*!< TIM3  */
}Tim_Ocu_Drv_IdType;

/**
 *  @brief TIM_Interrupt_Mask_Table
 */
#define TIM_OCU_DRV_INTMASK   (0xFFU)

/**
 *  @brief TIM_Interrupt_Mask_Defines
 */
#define TIM_OCU_DRV_CHINTMASK    (0x00000020U)

/** @brief invalid TIM channel number */
#define TIM_OCU_DRV_INVALID_CHANNEL_NUM     255U

/**
 * @brief TIM channel mask defines
 */
#define TIM_OCU_DRV_CH_MASK_U8      (0x07U)

/**
 * @brief TIM mod mask defines
 */
#define TIM_OCU_DRV_MOD_MASK_U8     (0xF8U)

/**
 * @brief TIM channel shift defines
 */
#define TIM_OCU_DRV_CH_SHIFT        (0U)
/** @} */

/**
 * @brief TIM 0 channel 0
 */
#define TIM_0_CH_0    (0x00U)

/**
 * @brief TIM 0 channel 1 
 */
#define TIM_0_CH_1    (0x01U)

/**
 * @brief TIM 0 channel 2 
 */
#define TIM_0_CH_2    (0x02U)

/**
 * @brief TIM 0 channel 3 
 */
#define TIM_0_CH_3    (0x03U)

/**
 * @brief TIM 0 channel 4 
 */
#define TIM_0_CH_4    (0x04U)

/**
 * @brief TIM 0 channel 5 
 */
#define TIM_0_CH_5    (0x05U)

/**
 * @brief TIM 0 channel 6 
 */
#define TIM_0_CH_6    (0x06U)

/**
 * @brief TIM 0 channel 7 
 */
#define TIM_0_CH_7    (0x07U)

/**
 * @brief TIM 1 channel 0
 */
#define TIM_1_CH_0    ((uint8)((1U << (3U)) + 0x00U))

/**
 * @brief TIM 1 channel 1
 */
#define TIM_1_CH_1    ((uint8)((1U << (3U)) + 0x01U))

/**
 * @brief TIM 1 channel 2
 */
#define TIM_1_CH_2    ((uint8)((1U << (3U)) + 0x02U))

/**
 * @brief TIM 1 channel 3
 */
#define TIM_1_CH_3    ((uint8)((1U << (3U)) + 0x03U))

/**
 * @brief TIM 1 channel 4
 */
#define TIM_1_CH_4    ((uint8)((1U << (3U)) + 0x04U))

/**
 * @brief TIM 1 channel 5
 */
#define TIM_1_CH_5    ((uint8)((1U << (3U)) + 0x05U))
 
 /**
 * @brief TIM 1 channel 6
 */
#define TIM_1_CH_6    ((uint8)((1U << (3U)) + 0x06U))

/**
 * @brief TIM 1 channel 7
 */
#define TIM_1_CH_7    ((uint8)((1U << (3U)) + 0x07U))

/**
 * @brief TIM 2 channel 0
 */
#define TIM_2_CH_0    ((uint8)((2U << (3U)) + 0x00U))

/**
 * @brief TIM 2 channel 1
 */
#define TIM_2_CH_1    ((uint8)((2U << (3U)) + 0x01U))

/**
 * @brief TIM 2 channel 2
 */
#define TIM_2_CH_2    ((uint8)((2U << (3U)) + 0x02U))

/**
 * @brief TIM 2 channel 3
 */
#define TIM_2_CH_3    ((uint8)((2U << (3U)) + 0x03U))

/**
 * @brief TIM 2 channel 4
 */
#define TIM_2_CH_4    ((uint8)((2U << (3U)) + 0x04U))

/**
 * @brief TIM 2 channel 5
 */
#define TIM_2_CH_5    ((uint8)((2U << (3U)) + 0x05U))

/**
 * @brief TIM 2 channel 6
 */
#define TIM_2_CH_6    ((uint8)((2U << (3U)) + 0x06U))

/**
 * @brief TIM 2 channel 7
 */
#define TIM_2_CH_7    ((uint8)((2U << (3U)) + 0x07U))

/**
 * @brief TIM 3 channel 0
 */
#define TIM_3_CH_0    ((uint8)((3U << (3U)) + 0x00U))

/**
 * @brief TIM 3 channel 1
 */
#define TIM_3_CH_1    ((uint8)((3U << (3U)) + 0x01U))

/**
 * @brief TIM 3 channel 2
 */
#define TIM_3_CH_2    ((uint8)((3U << (3U)) + 0x02U))

/**
 * @brief TIM 3 channel 3
 */
#define TIM_3_CH_3    ((uint8)((3U << (3U)) + 0x03U))

/**
 * @brief TIM 3 channel 4
 */
#define TIM_3_CH_4    ((uint8)((3U << (3U)) + 0x04U))

/**
 * @brief TIM 3 channel 5
 */
#define TIM_3_CH_5    ((uint8)((3U << (3U)) + 0x05U))

/**
 * @brief TIM 3 channel 6
 */
#define TIM_3_CH_6    ((uint8)((3U << (3U)) + 0x06U))

/**
 * @brief TIM 3 channel 7
 */
#define TIM_3_CH_7    ((uint8)((3U << (3U)) + 0x07U))

/**
 * @brief OCU TIM out control shift
 */
#ifndef TIM_OCU_DRV_OUTCTRL_POL_SHIFT_U8
#define TIM_OCU_DRV_OUTCTRL_POL_SHIFT_U8          (8U)
#endif

/**
 * @brief OCU TIM debug mode define
 */
#define TIM_OCU_DRV_BDM_MODE_00 0x00U
#define TIM_OCU_DRV_BDM_MODE_01 0x01U  
#define TIM_OCU_DRV_BDM_MODE_10 0x02U
#define TIM_OCU_DRV_BDM_MODE_11 0x03U

/**
 * @brief OCU clock source divide shift
 */
#define TIM_OCU_DRV_CS_DIV1_U32      (0UL)
#define TIM_OCU_DRV_CS_DIV2_U32      (1UL)
#define TIM_OCU_DRV_CS_DIV4_U32      (2UL)
#define TIM_OCU_DRV_CS_DIV8_U32      (3UL)
#define TIM_OCU_DRV_CS_DIV16_U32     (4UL)
#define TIM_OCU_DRV_CS_DIV32_U32     (5UL)
#define TIM_OCU_DRV_CS_DIV64_U32     (6UL)
#define TIM_OCU_DRV_CS_DIV128_U32    (7UL)

/**
 * @brief OCU TIM output control offset
 */
#define TIM_OCU_DRV_OUTSWCR_FORCED_VALUE_OFFSET  (8U)

/**
 * @brief TIM module Clock source select
 */
/* no clock source valid for TIM  */
#define TIM_OCU_DRV_CLOCK_SOURCE_NONE           0x00U
/* system clock selected for TIM  */
#define TIM_OCU_DRV_CLOCK_SOURCE_SYSTEMCLK      0x01U
/* function clock selected for TIM  */
#define TIM_OCU_DRV_CLOCK_SOURCE_FUNCTIONCLK    0x02U
/* external clock selected for TIM  */
#define TIM_OCU_DRV_CLOCK_SOURCE_EXTERNALCLK    0x03U

/**
 * @brief Ocu pin status typedef
 */
/* Ocu pin is used */
#define TIM_OCU_DRV_PIN_USED     1U
/* Ocu pin is not used */
#define TIM_OCU_DRV_PIN_UNUSED   0U

/**
 * @brief Ocu pin DMA trigger typedef
 */
/* Ocu pin DMA trigger is enabled */
#define TIM_OCU_DRV_PIN_DMA_ENABLE     1U
/* Ocu pin DMA trigger is disabled */
#define TIM_OCU_DRV_PIN_DMA_DISABLE   0U

/**
 * @brief Ocu pin state type typedef
 */
/* Ocu pin level is logic low */
#define TIM_OCU_DRV_LOW     0U
/* Ocu pin level is logic high */
#define TIM_OCU_DRV_HIGH    1U

/**
 * @brief TIM pin Action types define
 */
/* The channel pin will be set HIGH upon compare match. */
#define TIM_OCU_DRV_SET_LOW     0U
/* The channel pin will be set LOW upon compare match. */
#define TIM_OCU_DRV_SET_HIGH    1U
/* The channel pin will be set to the opposite of its current level upon compare match. */
#define TIM_OCU_DRV_SET_TOGGLE  2U
/* The channel pin will remain at its current level upon compare match. */
#define TIM_OCU_DRV_SET_DISABLE 3U

/**
 * @brief Ocu return type typedef
 */
/* The compare match will occur in this interval. */
#define TIM_OCU_DRV_IN_INTERVAL  0U
/* The compare match will occur out this interval. */
#define TIM_OCU_DRV_OUT_INTERVAL 1U

/**
 * @brief Ocu pin set type typedef
 */
/* Ocu pin set start */
#define TIM_OCU_DRV_START   1U
/* Ocu pin set stop */
#define TIM_OCU_DRV_STOP    0U

/**
 * @brief Ocu Tim_Ocu_Drv_ValueType typedef
 */
typedef uint32 Tim_Ocu_Drv_ValueType ;

/**
 * @brief Ocu Tim_Ocu_Drv_PinActionType typedef
 */
typedef uint8 Tim_Ocu_Drv_PinActionType;

/**
 * @brief Ocu Tim_Ocu_Drv_PinStateType typedef
 */
typedef uint8 Tim_Ocu_Drv_PinStateType;

/**
 * @brief Ocu Tim_Ocu_Drv_ReturnType typedef
 */
typedef uint8 Tim_Ocu_Drv_ReturnType;

/**
 * @brief Ocu Tim_Ocu_Drv_CallbackType typedef
 */
typedef void (*Tim_Ocu_Drv_CallbackType)(void);

#if (TIM_OCU_DRV_NOTIFICATION_SUPPORTED == STD_ON)
/**
 * @brief Ocu driver level channel state type typedef
 */
typedef struct
{
    boolean                 ChannelIsInit;  /*!< whether channel is init */
    Tim_Ocu_Drv_CallbackType CallBackFunc;  /*!< callback function */
} Tim_Ocu_Drv_ChStateType;
#endif

/**
 *  @brief Ocu driver level TIM clock information type typedef
 */
typedef struct
{
    uint8 InstanceClockSource; /*!< Clock source */
    uint8 InstanceClockDivide; /*!< Clock divide */
} Tim_Ocu_Drv_InstanceClockType;

/**
 * @brief Ocu driver level TIM config type typedef
 */
typedef struct
{
    const uint8 ModuleId;  /*!< TIM module id */
    const uint16 MaxCounterValue;  /*!< TIM max counter value */ 
    const uint8 ClockSource; /*!< Clock source */
    const uint8 ClockPrescale; /*!< Clock pre-scale */
    const uint8 DebugMode; /*!< Debug mode config */ 
} Tim_Ocu_Drv_TimConfigType;

/**
 * @brief Ocu driver level channel config type typedef
 */
typedef struct
{
    const uint16 OcuHwChannel;  /*!< TIM channel id */
    const uint16 DefaultThreshold;  /*!< Default compare match threshold */  
    const uint8 PinUsedState;  /*!< output pin used state 0: not used, 1: used */  
    const uint8 DefaultPinState;  /*!< default pin State: 0: low, 1: high */  
    const uint8 PinAction;  /*!< pin action on compare match. 0: low, 1: high, 2: toggle, 3: disable */
    const uint8 PinDMATrigger;  /*!< pin DMA trigger state. 0: disable, 1: enable */   
#if (TIM_OCU_DRV_NOTIFICATION_SUPPORTED == STD_ON)
    Tim_Ocu_Drv_CallbackType CallBackFunc;  /*!< Channel notification callback function */
#endif
} Tim_Ocu_Drv_ChannelConfigType;

/**
 * @brief Ocu driver level TIM module config type typedef
 */
typedef struct
{
    const uint8 NumChannels;  /*!< Number of TIM channels configured */
    const uint8 NumModules;  /*!< Number of TIM modules configured */
    const Tim_Ocu_Drv_ChannelConfigType (*ChannelsConfig)[];  /*!< Pointer to the configured channels for TIM */
    const Tim_Ocu_Drv_TimConfigType (*ModulesConfig)[];  /*!< Pointer to the configured modules for TIM */    
} Tim_Ocu_Drv_ModuleConfigType;

#ifdef __cplusplus
}
#endif

/** @} end of group Tim_Ocu_Drv_Types */

/** @} end of group Ocu_Module */

#endif  /* TIM_OCU_DRV_TYPES_H */
