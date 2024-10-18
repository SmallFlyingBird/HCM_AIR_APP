/**************************************************************************************************/
/**
 * @file      : Tim_Icu_Drv_Types.h
 * @brief     : AUTOSAR Tim Icu hardware types definition head file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef TIM_ICU_DRV_TYPES_H
#define TIM_ICU_DRV_TYPES_H

/** @addtogroup  Icu_Module
 *  @{
 */

/** @addtogroup  Tim_Icu_Drv
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Std_Types.h"
#include "McalLib.h"
#include "Tim_Icu_Drv_Cfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
#define TIM_ICU_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define TIM_ICU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define TIM_ICU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define TIM_ICU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define TIM_ICU_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define TIM_ICU_DRV_TYPES_H_SW_MINOR_VERSION            2U
#define TIM_ICU_DRV_TYPES_H_SW_PATCH_VERSION            1U

#if ((TIM_ICU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != TIM_ICU_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) || \
        (TIM_ICU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != TIM_ICU_DRV_CFG_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Tim_Icu_Drv_Types.h and Tim_Icu_Drv_Cfg.h are different"
#endif

#if ((TIM_ICU_DRV_TYPES_H_SW_MAJOR_VERSION != TIM_ICU_DRV_CFG_H_SW_MAJOR_VERSION) || \
        (TIM_ICU_DRV_TYPES_H_SW_MINOR_VERSION != TIM_ICU_DRV_CFG_H_SW_MINOR_VERSION))
    #error "Software version of Tim_Icu_Drv_Types.h and Tim_Icu_Drv_Cfg.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if (TIM_ICU_DRV_TYPES_H_VENDOR_ID != MCALLIB_VENDOR_ID)
        #error "Vendor ID Tim_Icu_Drv_Types.h and McalLib.h have different"
    #endif

    #if ((TIM_ICU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) || \
            (TIM_ICU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar version of Tim_Icu_Drv_Types.h and McalLib.h are different"
    #endif

    #if ((TIM_ICU_DRV_TYPES_H_SW_MAJOR_VERSION != MCALLIB_SW_MAJOR_VERSION) || \
            (TIM_ICU_DRV_TYPES_H_SW_MINOR_VERSION != MCALLIB_SW_MINOR_VERSION))
        #error "Software version of Tim_Icu_Drv_Types.h and McalLib.h are different"
    #endif

    #if ((TIM_ICU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
            (TIM_ICU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar version of Tim_Icu_Drv_Types.h and Std_Types.h are different"
    #endif

    #if ((TIM_ICU_DRV_TYPES_H_SW_MAJOR_VERSION != STD_SW_MAJOR_VERSION) || \
            (TIM_ICU_DRV_TYPES_H_SW_MINOR_VERSION != STD_SW_MINOR_VERSION))
        #error "Software version of Tim_Icu_Drv_Types.h and Std_Types.h are different"
    #endif

#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/** @} end of group Public_MacroDefinition */

/** @defgroup Public_TypeDefinition 
 *  @{
 */

/**
 * @brief Icu Tim_Icu_Drv_ActivationType typedef
 */
typedef uint8 Tim_Icu_Drv_ActivationType;

/**
 *  @brief The notification functions shall have no parameters and no return value
 */
typedef void (* Tim_Icu_Drv_NotificationType)(void);

/**
 *  @brief The callback type for each channel
 */
typedef void (* Tim_Icu_Drv_CallbackType)(uint16 param1, boolean param2);

/**
 *  @brief The callback type for setting channel state
 */
typedef void (* Tim_Icu_Drv_SetupChStateType)(uint16 channel, uint8 mask, boolean optType);

/**
 *  @brief TIM ID type definition
 */
typedef enum
{
    TIM_ICU_DRV_ID_0                                = 0U,                            /*!< TIM0  */
    TIM_ICU_DRV_ID_1,                                                                /*!< TIM1  */
    TIM_ICU_DRV_ID_2,                                                                /*!< TIM2  */
    TIM_ICU_DRV_ID_3                                                                 /*!< TIM3  */
} Tim_Icu_Drv_IdType;

/**
 *  @brief TIM Channel ID type definition
 */
typedef enum
{
    TIM_ICU_DRV_CHANNEL_0  = 0U, /*!< TIM Channel 0 */
    TIM_ICU_DRV_CHANNEL_1,       /*!< TIM Channel 1 */
    TIM_ICU_DRV_CHANNEL_2,       /*!< TIM Channel 2 */
    TIM_ICU_DRV_CHANNEL_3,       /*!< TIM Channel 3 */
    TIM_ICU_DRV_CHANNEL_4,       /*!< TIM Channel 4 */
    TIM_ICU_DRV_CHANNEL_5,       /*!< TIM Channel 5 */
    TIM_ICU_DRV_CHANNEL_6,       /*!< TIM Channel 6 */
    TIM_ICU_DRV_CHANNEL_7        /*!< TIM Channel 7 */
} Tim_Icu_Drv_ChannelIdType;

/**
 *  @brief TIM Clock Source type definition
 */
typedef enum
{
    TIM_ICU_DRV_DISABLE_CLOCK  = 0U, /*!<  disable tim clock */
    TIM_ICU_DRV_SYSTEM_CLOCK   = 1U, /*!< System Clock as TIM Counter Clock */
    TIM_ICU_DRV_FUNCTION_CLOCK = 2U, /*!< Function Clock as TIM Counter Clock */
    TIM_ICU_DRV_EXTERNAL_CLOCK = 3U  /*!< External Clock as TIM Counter Clock */
} Tim_Icu_Drv_ClkSourceType;

/**
 *  @brief TIM Clock Divide type definition
 */
typedef enum
{
    TIM_ICU_DRV_CLK_DIVIDE_1     = 0U, /*!< TIM Clock Divide by 1*/
    TIM_ICU_DRV_CLK_DIVIDE_2,          /*!< TIM Clock Divide by 2*/
    TIM_ICU_DRV_CLK_DIVIDE_4,          /*!< TIM Clock Divide by 4*/
    TIM_ICU_DRV_CLK_DIVIDE_8,          /*!< TIM Clock Divide by 8*/
    TIM_ICU_DRV_CLK_DIVIDE_16,         /*!< TIM Clock Divide by 16*/
    TIM_ICU_DRV_CLK_DIVIDE_32,         /*!< TIM Clock Divide by 32*/
    TIM_ICU_DRV_CLK_DIVIDE_64,         /*!< TIM Clock Divide by 64*/
    TIM_ICU_DRV_CLK_DIVIDE_128         /*!< TIM Clock Divide by 128*/
} Tim_Icu_Drv_ClkDivideType;

/**
 *  @brief TIM Edge-Alignment Mode type definition
 */
typedef enum
{
    TIM_ICU_DRV_INPUT_DISABLED     = 0U, /*!< TIM input capture disabled*/
    TIM_ICU_DRV_INPUT_RISING_EDGE,       /*!< TIM input capture only on rising edge*/
    TIM_ICU_DRV_INPUT_FALLING_EDGE,      /*!< TIM input capture only on falling edge*/
    TIM_ICU_DRV_INPUT_BOTH_EDGES         /*!< TIM input capture both on rising and falling edge*/
} Tim_Icu_Drv_EdgeAlignmentModeType;

/**
 *  @brief TIM behavior in debug Mode type definition
 */
typedef enum
{
    TIM_ICU_DRV_DEBUG_MODE_0  = 0U, /*!< counter stopped, CHF can be set */
    TIM_ICU_DRV_DEBUG_MODE_1,       /*!< counter stopped, CHF is not set */
    TIM_ICU_DRV_DEBUG_MODE_2,       /*!< counter stopped, CHF is not set */
    TIM_ICU_DRV_DEBUG_MODE_3        /*!< counter running, CHF can be set */
} Tim_Icu_Drv_DebugModeType;

/**
 *  @brief TIM Type of operation for signal measurement
 */
typedef enum
{
    TIM_ICU_DRV_NO_MEAS     = 0U, /*!< No measurement */                           
    TIM_ICU_DRV_LOW_TIME    = 1U, /*!< The time measurement for OFF period */
    TIM_ICU_DRV_HIGH_TIME   = 2U, /*!< The time measurement for ON period */
    TIM_ICU_DRV_PERIOD_TIME = 4U, /*!< Period measurement between two consecutive 
                                        falling/raising edges */
    TIM_ICU_DRV_DUTY_CYCLE  = 8U  /*!< The fraction of active period */
} Tim_Icu_Drv_MeasPropertyType;

/**
 *  @brief TIM channel input filter type definition, only available for channel 0/1/2/3
 */
typedef enum
{
    TIM_ICU_DRV_INPUT_FILTER_DISABLE  = 0U, /*!< the channel input filter: disabled*/
    TIM_ICU_DRV_INPUT_FILTER_1,             /*!< the channel input filter: 1*/
    TIM_ICU_DRV_INPUT_FILTER_2,             /*!< the channel input filter: 2*/
    TIM_ICU_DRV_INPUT_FILTER_3,             /*!< the channel input filter: 3*/
    TIM_ICU_DRV_INPUT_FILTER_4,             /*!< the channel input filter: 4*/
    TIM_ICU_DRV_INPUT_FILTER_5,             /*!< the channel input filter: 5*/
    TIM_ICU_DRV_INPUT_FILTER_6,             /*!< the channel input filter: 6*/
    TIM_ICU_DRV_INPUT_FILTER_7,             /*!< the channel input filter: 7*/
    TIM_ICU_DRV_INPUT_FILTER_8,             /*!< the channel input filter: 8*/
    TIM_ICU_DRV_INPUT_FILTER_9,             /*!< the channel input filter: 9*/
    TIM_ICU_DRV_INPUT_FILTER_10,            /*!< the channel input filter: 10*/
    TIM_ICU_DRV_INPUT_FILTER_11,            /*!< the channel input filter: 11*/
    TIM_ICU_DRV_INPUT_FILTER_12,            /*!< the channel input filter: 12*/
    TIM_ICU_DRV_INPUT_FILTER_13,            /*!< the channel input filter: 13*/
    TIM_ICU_DRV_INPUT_FILTER_14,            /*!< the channel input filter: 14*/
    TIM_ICU_DRV_INPUT_FILTER_15             /*!< the channel input filter: 15*/
} Tim_Icu_Drv_FilterType;

/**
 *  @brief TIM Dual Edge Capture Mode type definition
 */
typedef enum
{
    TIM_ICU_DRV_ONE_PULSE_CAPTURE = 0U,  /*!< one pulse capture in dual edge capture mode*/
    TIM_ICU_DRV_CONTINUOUS_PULSE_CAPTURE /*!< continuous pulse capture in dual edge capture mode*/
} Tim_Icu_Drv_DualEdgeCaptureModeType;
 
/**
 *  @brief TIM dma configure type definition
 */
typedef enum
{
    TIM_ICU_DRV_DMA_DISABLE                    = 0U, /*!< use dma */
    TIM_ICU_DRV_DMA_ENABLE                           /*!< not use dma */
} Tim_Icu_Drv_DmaConfigType;

typedef enum
{
    TIM_ICU_DRV_STATUS_SUCCESS                 = 0U, /*!< Generic operation success status */
    TIM_ICU_DRV_STATUS_ERROR                         /*!< Generic operation failure status */
} Tim_Icu_Drv_StatusType;

/**
 *  @brief TIM Signal Measurement type definition
 */
typedef enum
{
    TIM_ICU_DRV_MODE_MEASUREMENT_DISABLE        = 0U, /*!< No measurement mode */
    TIM_ICU_DRV_MODE_SIGNAL_EDGE_DETECT         = 1U, /*!< edge detect measurement mode */
    TIM_ICU_DRV_MODE_SIGNAL_MEASUREMENT         = 2U, /*!< Signal measurement mode */
    TIM_ICU_DRV_MODE_TIMESTAMP                  = 4U, /*!< Timestamp measurement mode */
    TIM_ICU_DRV_MODE_EDGE_COUNTER               = 8U  /*!< Edge counter measurement mode */
} Tim_Icu_Drv_MeasurementModeType; 

#if (STD_ON == TIM_ICU_DRV_TIMESTAMP_API)
typedef enum
{
    TIM_ICU_DRV_NO_TIMESTAMP                   = 0U, /*!< No timestamp */
    TIM_ICU_DRV_CIRCULAR_BUFFER,                     /*!< The timestamp with circular buffer */
    TIM_ICU_DRV_LINEAR_BUFFER                        /*!< The timestamp with linear buffer */
} Tim_Icu_Drv_TimestampBufferType; 
#endif

/**
 * @brief Structure that contains ICU Duty cycle parameters
 *          i.e Period time value and active time value  
 */
typedef struct
{
    uint16 ActiveTime; /*!< @brief Low or High time value */
    uint16 PeriodTime; /*!< @brief Period time value */
} Tim_Icu_Drv_DutyCycleType;

/**
 * @brief Structure that driver configuration
 */
typedef struct
{
    uint16 MaxCntVal; /*!< Maximum counter value */
    Tim_Icu_Drv_ClkDivideType ClockDiv; /*!< Prescaler value */
    Tim_Icu_Drv_ClkSourceType ClockSrc; /*!< Type of clock source used */
    Tim_Icu_Drv_DebugModeType DebugMode; /*!< Debug mode */
} Tim_Icu_Drv_GlobalConfigType;

/**
 * @brief Structure that store Input capture parameters for each channel
 */
typedef struct
{
    uint32 PhsyChId; /*!< Physical hardware channel ID */              
    Tim_Icu_Drv_MeasPropertyType MeasProperty; /*!< Measurement Mode for signal measurement */       
    Tim_Icu_Drv_EdgeAlignmentModeType ActiveEdge; /*!< Edge alignment Mode for signal measurement */      
    Tim_Icu_Drv_DualEdgeCaptureModeType DecapMode; /*!< Continuous measurement state */
    Tim_Icu_Drv_MeasurementModeType OptMode; /*!< mode of operation */                 
    Tim_Icu_Drv_DmaConfigType DmaUse; /*!< dma use selection */
    Tim_Icu_Drv_FilterType FilterWidth; /*!< Filter Value */
    uint16 CallbackParam; /*!< The parameters of callback functions for channels events */
    Tim_Icu_Drv_CallbackType CallbackFun; /*!< The callback function for 
                                                        channels edge detect events */        
    Tim_Icu_Drv_SetupChStateType SetupChStateFun; /*!< function used to change the logic 
                                                                    state of the channel */
    Tim_Icu_Drv_NotificationType ChNotificationFun; /*!< The notification functions shall have no
                                                                 parameters and no return value */
    Tim_Icu_Drv_NotificationType ChOvfNotificationFun; /*!< The overflow notification functions 
                                                    shall have no parameters and no return value */
#if (STD_ON == TIM_ICU_DRV_TIMESTAMP_API)
    Tim_Icu_Drv_TimestampBufferType TsBufferType; /*!< Timestamp buffer type for timestamp mode */      
#endif
} Tim_Icu_Drv_ChannelConfigType;

/**
 * @brief Structure that store channel operation state
 */
typedef struct
{
    Tim_Icu_Drv_NotificationType ChNotificationFun; /*!< The notification functions for TIME_STAMP 
                                                                    or SIGNAL_EDGE_DETECT mode */
    Tim_Icu_Drv_NotificationType ChOvfNotificationFun; /*!< The overflow notification functions */
    Tim_Icu_Drv_MeasurementModeType OptMode; /*!< channel mode */
    Tim_Icu_Drv_EdgeAlignmentModeType ActiveEdge; /*!< Type of edge used for activation */
    Tim_Icu_Drv_DmaConfigType DmaUse; /*!< Support DMA or not */
    uint8 Pad1; /*!< pad */        
#if (STD_ON == TIM_ICU_DRV_SIGNAL_MEASUREMENT_API)
    boolean FirstCapture;   /*!< Store the status of the first measurement
                             - TRUE: the first capture 
                             - FALSE: not the first capture */
    boolean DutyFirstCapture;   /*!< Store the status of the Duty cycle first measurement
                             - TRUE: the Duty cycle first capture 
                             - FALSE: not the Duty cycle first capture */
    boolean FirstCapturePolarity;   /*!< Store the first edge come to measurement in BOTH_EDGE mode
                                         - TRUE: the rising capture 
                                         - FALSE: the falling capture */
    uint16 PeriodValue;         /*!< saving the period value */
    uint16 PulseValue;          /*!< saving the pulse value */
    uint16 FirstCapValue;       /*!< temp capture value */
    Tim_Icu_Drv_MeasPropertyType MeasProperty; /*!< Signal measurement mode */
    uint8 Pad2[3U];                          /*!< pad */
#endif
#if (STD_ON == TIM_ICU_DRV_TIMESTAMP_API)
    uint16 * BufferHeadPtr; /*!< Pointer to the buffer-array where the timestamp 
                                                            values shall be placed */
    uint16 BufferSize;      /*!< saving the size of the external buffer */
    uint16 NotifyInterval;  /*!< saving Notification interval */
    uint16 NotifyCount;     /*!< saving the number of notify counts */
    uint16 BufferIndex;     /*!< saving the time stamp index */
    Tim_Icu_Drv_TimestampBufferType TsBufferType; /*!< Timestamp buffer type */
    uint8 Pad3[3U];                             /*!< pad */
#endif
    Tim_Icu_Drv_SetupChStateType SetupChStateFun; /*!< Store address of function used to change the
                                                     logic state of the channel */
    Tim_Icu_Drv_CallbackType CallbackFun; /*!< Calback for other types of measurement */
    uint16 CallbackParam; /*!< Logic channel for which callback is executed */
#if (STD_ON == TIM_ICU_DRV_EDGE_COUNT_API)
    uint16 EdgeSumNum; /*!< Logic variable to count edges */
#endif
    boolean NotifyEnable;   /*!< determines whether Notifications are enabled or not
                                 - TRUE: enable notification 
                                 - FALSE: disable notification */
} Tim_Icu_Drv_ChannelStateType;

/**
 * @brief Structure that driver configuration
 */
typedef struct
{
    uint32 ChSumNum; /*!< Number of input capture channel used */
    const Tim_Icu_Drv_GlobalConfigType * GlobalCfgPtr; /*!< Input capture instance configuration */
    const Tim_Icu_Drv_ChannelConfigType (*ChCfgPtr)[]; /*!< Input capture channels configuration */
} Tim_Icu_Drv_InstanceConfigType;

/**
 * @brief used by the drv driver for internal logic
 */
typedef struct
{
    boolean InstInitFlag;   /*!< Module initialization state
                             - TRUE: initialization 
                             - FALSE: de-initialization */
    Tim_Icu_Drv_ClkDivideType ClockDiv; /*!< Module prescaler value */
    uint16 ChfClrMask; /*!< Mask with channels not verified for spurious interrupt */
    uint16 TimCounterModulValue; /*!< TIM Counter Max Value (0 -> 65535) */
} Tim_Icu_Drv_InstanceStateType;


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

#endif  /* TIM_ICU_DRV_TYPES_H */

