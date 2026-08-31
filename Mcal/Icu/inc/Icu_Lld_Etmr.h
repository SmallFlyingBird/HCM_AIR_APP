/*
* @file    Icu_Lld_Etmr.h
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Icu_Lld
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

#ifndef ICU_LLD_ETMR_H
#define ICU_LLD_ETMR_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
#include "Icu_Base.h"
#include "Icu.h"
/*==================================================================================================
                                      HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_LLD_ETMR_VENDOR_ID                      (180)
#define ICU_LLD_ETMR_AR_RELEASE_MAJOR_VERSION       (4)
#define ICU_LLD_ETMR_AR_RELEASE_MINOR_VERSION       (4)
#define ICU_LLD_ETMR_AR_RELEASE_REVISION_VERSION    (0)
#define ICU_LLD_ETMR_SW_MAJOR_VERSION               (2)
#define ICU_LLD_ETMR_SW_MINOR_VERSION               (3)
#define ICU_LLD_ETMR_SW_PATCH_VERSION               (0)
/*==================================================================================================
                                                DEFINES AND MACROS
==================================================================================================*/
#define SETACTIVATION_SERVICE_ID (0x11U)
#define NORMAL_SERVICE_ID (0x00U)
typedef uint32 Icu_Etmr_Mc_ValueType;

typedef void (*Icu_Etmr_Mc_NotificationType)(void);

#define ICU_ETMR_REG_ADDR32_READ(address) (*(volatile uint32 *)(address))

#define ICU_ETMR_REG_ADDR32_WRITE(address, value) ((*(volatile uint32 *)(address)) = (value))
#define ICU_ETMR_REG_ADDR32_AEARWRITE(address, mask, value) \
    (ICU_ETMR_REG_ADDR32_WRITE((address),                   \
                               ((ICU_ETMR_REG_ADDR32_READ(address) & ((uint32) ~(mask))) | (value))))

#define ICU_ETMR_REG_ADDR32_SET_BITS(address, mask) ((*(volatile uint32 *)(address)) |= (mask))
#define ICU_ETMR_REG_ADDR32_CLEAR_BITS(address, mask) ((*(volatile uint32 *)(address)) &= (~(mask)))

#define ICU_ETMR_REG_ADDR32_GET_BITS(address, mask) ((*(volatile uint32 *)(address)) & (mask))
#define ICU_ETMR_REG_ADDR32_INDEX_GET_BIT(address, bitindex) (((*(volatile uint32 *)(address)) >> (bitindex)) & ((uint32)1U))

#define MOD_FULL_MASK (0xFFFFFFFFU)
#define FULL_MASK (0xFFFFFFFFU)
#define INSTANCE_OFFSET (8U)
/*==================================================================================================
                                                EXTERNAL CONSTANTS
==================================================================================================*/
typedef enum
{
    ETMR_ICU_CHANNEL_UNINIT,
    ETMR_ICU_CHANNEL_INIT_OK,
} Etmr_Icu_ChannelInitStateType;

typedef enum
{
    ETMR_ICU_TIMESTAMP_STATE_STOPPED,
    ETMR_ICU_TIMESTAMP_STATE_RUNNING,
}Etmr_Icu_TimeStampModeStateType;


typedef enum
{
    ICU_MC_CLOCK_SOURCE_FASTBUSCLK = 0x00U,  /*!< Fast bus clock */
    ICU_MC_CLOCK_SOURCE_EXTERNALCLK = 0x01U, /*!< External clock */
} Icu_Etmr_Mc_ClockSourceType;

typedef enum
{
    ICU_MC_CLOCK_OTHERS_EXTERNAL_IN0 = 0x00U, /*!< External input 0 */
    ICU_MC_CLOCK_OTHERS_EXTERNAL_IN1 = 0x01U, /*!< External input 1 */
    ICU_MC_CLOCK_OTHERS_EXTERNAL_IN2 = 0x02U, /*!< External input 2 */
    ICU_MC_CLOCK_OTHERS_EXTERNAL_INPUT_IPC = 0x03U, /*!< External Input from input 3 */
} Icu_Etmr_Mc_ClockOthersType;


typedef enum
{
    ETMR_MC_CH_MODE_CONTINUOUS = 0U, /**<    */
    ETMR_MC_CH_MODE_ONESHOT = 1U,    /**<    */
} Icu_Etmr_Mc_ChannelModeType;

typedef enum
{
    ETMR_MC_CHANNEL_STATE_UNINIT = 0U,
    ETMR_MC_CHANNEL_STATE_INITIALIZED = 1U,
    ETMR_MC_CHANNEL_STATE_RUNNING = 2U,
    ETMR_MC_CHANNEL_STATE_STOPPED = 3U,
    ETMR_MC_CHANNEL_STATE_EXPIRED = 4U,
} Icu_Etmr_Mc_ChannelStatesType;

typedef enum
{
    ETMR_FUNCTION_MODE_DISABLE=0x00U,
    ETMR_FUNCTION_MODE_PWM=0x01U,
    ETMR_FUNCTION_MODE_OCU=0x02U,
    ETMR_FUNCTION_MODE_ICU=0x03U,
}Icu_Etmr_ChannelFunctionModeType;

typedef enum
{
    ETMR_MC_TIMER_BASE_NONE = 0U,
    ETMR_MC_TIMER_BASE_GPT = 1U,
    ETMR_MC_TIMER_BASE_PWM = 2U,
    ETMR_MC_TIMER_BASE_ICU = 3U,
    ETMR_MC_TIMER_BASE_OCU = 4U,
}Icu_Etmr_Mc_TimerBaseType;

/*==================================================================================================
                                                ENUMS
==================================================================================================*/
typedef enum
{
    ICU_ETMR0,
    ICU_ETMR1,
    ICU_ETMR2,
    ICU_ETMR3,
    ICU_ETMR4,
    ICU_ETMR5,
}IcuEtmrInstanceType;

typedef struct
{
    Icu_EdgeNotificationType EdgeNotificationPtr;   /*!< Pointer to notification function */
    boolean IsNotificationEnable;                   /*!< Notification Enable status */
}Etmr_Icu_EdgeDetectType;



typedef struct
{
    Etmr_Icu_TimeStampModeStateType TimeStampModeState; /*!< Time stamp mode state */
    Icu_ValueType *BufferPtr;                        /*!< Pointer to the buffer */
    uint16 BufferSize;                             /*!< Buffer size */
    Icu_IndexType TimestampIndex;               /*!< Index of the next element in the buffer */
    Icu_TimestampBufferType BufferType;        /*!< Type of the buffer */
    boolean IsNotificationEnable;           /*!< Notification status */
    Icu_TimestampNotificationType TimestampNotificationPtr; /*!< Pointer to notification function */
    uint16 NotifyInterval;                            /*!< Notification interval */
} Etmr_Icu_TimeStampInfoType;

typedef struct
{
    Icu_Etmr_Mc_TimerBaseType TimerBaseFunction;    /*!< Timer base function */
    Icu_Etmr_Mc_ChannelStatesType State;            /*!< Channel state */
    boolean IsNotificationEnabled;            /*!< Notification status */
    Icu_Etmr_Mc_NotificationType NotificationPtr;   /*!< Pointer to notification function */
    Icu_Etmr_Mc_ChannelModeType CountMode;    /*!< Count mode */
    Icu_Etmr_Mc_ValueType PeriodTickValue;      /*!< Period tick value */
    uint32 OverflowTimes;                    /*!< Overflow times */
} Icu_Etmr_Mc_ChannelInfoType;

typedef struct
{
    uint8 HwChannelId; /*!< Hardware channel ID */
    Icu_Etmr_Mc_ClockSourceType ClockSource;    /*!< Clock source */
    Icu_Etmr_Mc_ClockOthersType ClockOthers;    /*!< Clock others config (CIM) */
    uint8 Prescale; /*!< Prescale value */
    Icu_Etmr_Mc_ChannelModeType CountMode;  /*!< Count mode */
    boolean EnableNotification; /*!< Notification status */
    Icu_Etmr_Mc_NotificationType NotificationPtr;   /*!< Pointer to notification function */
} Icu_Etmr_Mc_ChannelConfigType;

extern Icu_Etmr_Mc_ChannelInfoType Etmr_Mc_gChannelInfo[ICU_ETMR_MC_CHANNEL_COUNT];
extern Icu_Etmr_Mc_ChannelInfoType Icu_Etmr_Mc_gChannelInfo[ICU_ETMR_MC_CHANNEL_COUNT];
extern Icu_ChannelType Etmr_Icu_gHwToUserChannelMap[ICU_ETMR_MC_CHANNEL_COUNT][ETMR_ICU_CHANNEL_COUNT];
extern Etmr_Icu_TimeStampInfoType Etmr_Icu_TimeStampInfo[ICU_MAX_CHANNEL];
extern Etmr_Icu_EdgeDetectType Etmr_Icu_gEdgeNotification[ICU_MAX_CHANNEL];
/*==================================================================================================
                                                FUNCTION PROTOTYPES
==================================================================================================*/
/**
 * @brief            This function initializes the driver.
 * @details
 *
 *
 */
void Icu_Lld_Etmr_Init(void);

#if (ICU_DE_INIT_API == STD_ON)
/**
 * @brief            This function de-initializes the ICU module.
 *
 *
 */
void Icu_Lld_Etmr_DeInit(void);
#endif
/**
 * @brief            This function sets the activation-edge for the given channel.
 * @details
 * @param[in]        Channel Numeric identifier of the ICU channel
 * @param[in]        Activation Type of activation (if supported by hardware)
                    - ICU_RISING_EDGE
                    - ICU_FALLING_EDGE
                    - ICU_BOTH_EDGES
 *
 *
 */
void Icu_Lld_Etmr_SetActivationCondition(Icu_ChannelType Channel, Icu_ActivationType Activation);

#if (ICU_EDGE_DETECT_API == STD_ON)
/**
 * @brief            This function enables the counting of edges of the given channel.
 * @details
 * @param[in]        Channel Numeric identifier of the ICU channel
 *
 *
 */
void Icu_Lld_Etmr_EnableEdgeCount(Icu_ChannelType Channel);
/**
 * @brief            This function disables the counting of edges of the given channel.
 * @details
 * @param[in]        Channel Numeric identifier of the ICU channel
 *
 *
 */
void Icu_Lld_Etmr_DisableEdgeCount(Icu_ChannelType Channel);
#endif

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/**
 * @brief            This function starts the signal measurement on the given channel.
 * @details
 * @param[in]        Channel Numeric identifier of the ICU channel
 *
 *
 */
void Icu_Lld_Etmr_StartSignalMeasurement(Icu_ChannelType Channel);
/**
 * @brief            This function stops the signal measurement on the given channel.
 * @details
 * @param[in]        Channel Numeric identifier of the ICU channel
 *
 *
 */
void Icu_Lld_Etmr_StopSignalMeasurement(Icu_ChannelType Channel);
#endif

#if (ICU_GET_INPUT_STATE_API == STD_ON)
/**
 * @brief            This function returns the input state of the given channel.
 * @details
 * @param[in]        InChannel Numeric identifier of the ICU channel
 * @return           Icu_InputStateType
 *                   - ICU_ACTIVE
 *                   - ICU_IDLE
 *
 *
 */
Icu_InputStateType Icu_Lld_Etmr_GetInputState(Icu_ChannelType Channel);
#endif

#if (ICU_GET_TIME_ELAPSED_API == STD_ON)
/**
 * @brief            This function returns the elapsed time of the given channel.
 * @details
 * @param[in]        Channel Numeric identifier of the ICU channel
 * @return           Icu_ValueType
 *                   - Elapsed time measured by the given channel
 *
 *
 */
Icu_ValueType Icu_Lld_Etmr_GetTimeElapsed(Icu_ChannelType Channel);
#endif

#if (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON)
/**
 * @brief            This function returns the duty cycle values of the given channel.
 * @details
 * @param[in]        Channel Numeric identifier of the ICU channel
 * @param[out]       DutyCycleValues Pointer to the structure which will store the high and low times
 *
 *
 */
void Icu_Lld_Etmr_GetDutyCycleValues(Icu_ChannelType Channel, Icu_DutyCycleType *DutyCycleValues);
#endif

#if (ICU_TIMESTAMP_API == STD_ON)
/**
 * @brief            This function starts the time stamping on the given channel.
 * @details
 * @param[in]        Channel Numeric identifier of the ICU channel
 * @param[in]        BufferPtr Pointer to the buffer which will store the time stamps
 * @param[in]        BufferSize Size of the buffer
 * @param[in]        NotifyInterval Notification interval
 *
 *
 */
void Icu_Lld_Etmr_StartTimestamp(Icu_ChannelType Channel, Icu_ValueType *BufferPtr, uint16 BufferSize, uint16 NotifyInterval);
/**
 * @brief            This function stops the time stamping on the given channel.
 * @details
 * @param[in]        Channel Numeric identifier of the ICU channel
 *
 *
 */
void Icu_Lld_Etmr_StopTimestamp(Icu_ChannelType Channel);
/**
 * @brief            This function resets the time stamp buffer index.
 * @details
 * @param[in]        Channel Numeric identifier of the ICU channel
 *
 *
 */
#if 0
Icu_IndexType Icu_Lld_Etmr_GetTimestampIndex(Icu_ChannelType Channel);
#endif
#endif

#if (ICU_EDGE_DETECT_API == STD_ON)
/**
 * @brief            This function enables the edge detection for the given channel.
 * @details
 * @param[in]        Channel Numeric identifier of the ICU channel
 *
 *
 */
void Icu_Lld_Etmr_EnableEdgeDetectionNotification(Icu_ChannelType Channel);
#endif
void Icu_Lld_Etmr_EnableEdgeDetection(Icu_ChannelType ChannelIndex); /*PRQA S 0777,0779*/
void Icu_Lld_Etmr_DisableEdgeDetection(Icu_ChannelType ChannelIndex);

#ifdef __cplusplus
}
#endif

#endif /* End of file Icu_Lld_Etmr.h */

