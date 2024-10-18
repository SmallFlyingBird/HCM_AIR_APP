/**************************************************************************************************/
/**
 * @file      : Adc_Types.h
 * @brief     : Adc AUTOSAR level type definition file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef ADC_TYPES_H
#define ADC_TYPES_H

/** @addtogroup Adc_Module
 *  @{
 */

/** @addtogroup Adc
 *  @brief Adc AUTOSAR level
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Adc_Cfg.h"
#include "Adc_Drv_Types.h"
#include "Tdg_Adc_Drv_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define ADC_TYPES_H_VENDOR_ID                   0x00B3U
#define ADC_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define ADC_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define ADC_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define ADC_TYPES_H_SW_MAJOR_VERSION            1U
#define ADC_TYPES_H_SW_MINOR_VERSION            2U
#define ADC_TYPES_H_SW_PATCH_VERSION            1U

/* Check if current file and Adc_Cfg.h are the same vendor */
#if (ADC_TYPES_H_VENDOR_ID != ADC_CFG_H_VENDOR_ID)
    #error "Vendor ID of Adc_Types.h and Adc_Cfg.h are different"
#endif

/* Check if current file and Adc_Cfg.h are the same Autosar version */
#if ((ADC_TYPES_H_AR_RELEASE_MAJOR_VERSION != ADC_CFG_H_AR_RELEASE_MAJOR_VERSION) ||               \
     (ADC_TYPES_H_AR_RELEASE_MINOR_VERSION != ADC_CFG_H_AR_RELEASE_MINOR_VERSION) ||               \
     (ADC_TYPES_H_AR_RELEASE_REVISION_VERSION != ADC_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Adc_Types.h and Adc_Cfg.h are different"
#endif

/* Check if current file and Adc_Cfg.h are the same Software version */
#if ((ADC_TYPES_H_SW_MAJOR_VERSION != ADC_CFG_H_SW_MAJOR_VERSION) ||                               \
     (ADC_TYPES_H_SW_MINOR_VERSION != ADC_CFG_H_SW_MINOR_VERSION) ||                               \
     (ADC_TYPES_H_SW_PATCH_VERSION != ADC_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Adc_Types.h and Adc_Cfg.h are different"
#endif

/* Check if current file and Adc_Drv_Types.h are the same vendor */
#if (ADC_TYPES_H_VENDOR_ID != ADC_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Adc_Types.h and Adc_Drv_Types.h are different"
#endif

/* Check if current file and Adc_Drv_Types.h are the same Autosar version */
#if ((ADC_TYPES_H_AR_RELEASE_MAJOR_VERSION != ADC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||         \
     (ADC_TYPES_H_AR_RELEASE_MINOR_VERSION != ADC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||         \
     (ADC_TYPES_H_AR_RELEASE_REVISION_VERSION != ADC_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Adc_Types.h and Adc_Drv_Types.h are different"
#endif

/* Check if current file and Adc_Drv_Types.h are the same Software version */
#if ((ADC_TYPES_H_SW_MAJOR_VERSION != ADC_DRV_TYPES_H_SW_MAJOR_VERSION) ||                         \
     (ADC_TYPES_H_SW_MINOR_VERSION != ADC_DRV_TYPES_H_SW_MINOR_VERSION) ||                         \
     (ADC_TYPES_H_SW_PATCH_VERSION != ADC_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Adc_Types.h and Adc_Drv_Types.h are different"
#endif

/* Check if current file and Tdg_Adc_Drv_Types.h are the same vendor */
#if (ADC_TYPES_H_VENDOR_ID != TDG_ADC_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Adc_Types.h and Tdg_Adc_Drv_Types.h are different"
#endif

/* Check if current file and Tdg_Adc_Drv_Types.h are the same Autosar version */
#if ((ADC_TYPES_H_AR_RELEASE_MAJOR_VERSION != TDG_ADC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||     \
     (ADC_TYPES_H_AR_RELEASE_MINOR_VERSION != TDG_ADC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||     \
     (ADC_TYPES_H_AR_RELEASE_REVISION_VERSION != TDG_ADC_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Adc_Types.h and Tdg_Adc_Drv_Types.h are different"
#endif

/* Check if current file and Tdg_Adc_Drv_Types.h are the same Software version */
#if ((ADC_TYPES_H_SW_MAJOR_VERSION != TDG_ADC_DRV_TYPES_H_SW_MAJOR_VERSION) ||                     \
     (ADC_TYPES_H_SW_MINOR_VERSION != TDG_ADC_DRV_TYPES_H_SW_MINOR_VERSION) ||                     \
     (ADC_TYPES_H_SW_PATCH_VERSION != TDG_ADC_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Adc_Types.h and Tdg_Adc_Drv_Types.h are different"
#endif
/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */
/**
 * @brief   ADC driver status
 * @details Used to differentiate if ADC driver is already uninit, during init or already
 *          initialized or not.
 *
 */
typedef enum
{
    ADC_STATE_UNINIT = 0U, /*!< Adc driver uninitialized */
    ADC_STATE_BUSY,        /*!< Adc driver busy */
    ADC_STATE_IDLE         /*!< Adc driver idle */
} Adc_GlobalStateType;

/**
 * @brief   ADC group already converted type.
 * @details Used to differentiate if group is already converted or not.
 *
 */
typedef enum
{
    ADC_NOT_YET_CONVERTED = 0U, /*!< Group not yet converted */
    ADC_ALREADY_CONVERTED       /*!< Group is already converted */
} Adc_GroupConversionStateType;

/**
 * @brief   Adc group access Mode.
 * @details Type for configuring the access mode to group conversion results.
 *
 * SWS_Adc_00528
 */
typedef enum
{
    ADC_ACCESS_MODE_SINGLE = 0U, /*!< Single value access mode. */
    ADC_ACCESS_MODE_STREAMING    /*!< Streaming access mode. */
} Adc_GroupAccessModeType;

/**
 * @brief   Adc Group conversion mode.
 * @details Type for configuring the conversion mode of an ADC Channel group.
 *
 */
/* SWS_Adc_00515 */
typedef enum
{
    ADC_CONV_MODE_ONESHOT = 0U,
    /*!< Exactly one conversion of each channel in an ADC channel group is performed after
    the configured trigger event. In case of 'group trigger source software', a started
    One-Shot conversion can be stopped by a software API call. In case of 'group trigger
    source hardware', a started One-Shot conversion can be stopped by disabling the
    trigger event (if supported by hardware). */
    ADC_CONV_MODE_CONTINUOUS
    /*!< Repeated conversions of each ADC channel in an ADC channel group
    are performed. 'Continuous conversion mode' is only available for
    'group trigger source software'. A started 'Continuous conversion'
    can be stopped by a software API call. */
} Adc_GroupConvModeType;

/**
 * @brief   Adc group replacement.
 * @details Replacement mechanism, which is used on ADC group level, if a group conversion is
 * interrupted by a group which has a higher priority.
 *
 * SWS_Adc_00523
 */
typedef enum
{
    ADC_GROUP_REPL_ABORT_RESTART = 0U,
    /*!< Abort/Restart mechanism is used on group level, if a group is interrupted by a
    higher priority group. The complete conversion round of the interrupted group (all
    group channels)is restarted after the higher priority group conversion is finished.
    If the group is configured in streaming access mode, only the results of the
    interrupted conversion round are discarded. Results of previous conversion rounds
    which are already written to the result buffer are not affected. */
    ADC_GROUP_REPL_SUSPEND_RESUME
    /*!< Suspend/Resume mechanism is used on group level, if a group
    is interrupted by a higher priority group. The conversion round
    of the interrupted group is completed after the higher priority
    group conversion is finished. Results of previous conversion
    rounds which are already written to the result buffer are not
    affected. Description: Replacement mechanism, which is used on
    ADC group level, if a group conversion is interrupted by a
    group which has a higher priority. */
} Adc_GroupReplacementType;

/**
 * @brief   Adc group streaming buffer mode.
 * @details Type for configuring the streaming access mode buffer type.
 *
 */
/* SWS_Adc_00519 */
typedef enum
{
    ADC_STREAM_BUFFER_LINEAR = 0U, /*!< The ADC Driver stops the conversion as soon as the stream
                                      buffer is full (number of samples reached). */
    ADC_STREAM_BUFFER_CIRCULAR     /*!< The ADC Driver continues the conversion even if the stream
                                      buffer is full (number of samples reached) by wrapping around
                                      the stream buffer itself. */
} Adc_StreamBufferModeType;

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/**
 * @brief   Range select values.
 * @details In case of active limit checking: defines which conversion values are taken into account
 * related to the boarders defined with AdcChannelLowLimit and AdcChannel HighLimit.
 *
 */
/* SWS_Adc_00524 */
typedef enum
{
    ADC_RANGE_UNDER_LOW = 0U, /*!< Range below low limit - low limit value included. */
    ADC_RANGE_BETWEEN,   /*!< Range between low limit and high limit - high limit value included. */
    ADC_RANGE_OVER_HIGH, /*!< Range above high limit */
    ADC_RANGE_ALWAYS,    /*!< Complete range - independent from channel limit settings */
    ADC_RANGE_NOT_UNDER_LOW, /*!< Range above low limit. */
    ADC_RANGE_NOT_BETWEEN,   /*!< Range above high limit or below low limit - low limit value
                              included */
    ADC_RANGE_NOT_OVER_HIGH  /*!< Range below high limit - high limit value included. */
} Adc_ChannelRangeSelectType;
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

/**
 * @brief   ADC group status.
 * @details Current status of the conversion of the requested ADC Channel group.
 *
 */
/* SWS_Adc_00513 */
typedef enum
{
    ADC_IDLE = 0U, /*!< The conversion of the specified group has not been started. No result is
                      available. */
    ADC_BUSY, /*!< The conversion of the specified group has been started and is still going on. So
                 far no result is available. */
    ADC_COMPLETED, /*!< A conversion round (which is not the final one) of the specified group has
                      been finished. A result is available for all channels of the group. */
    ADC_STREAM_COMPLETED /*!< The result buffer is completely filled. For each channel of the
                            selected group the number of samples to be acquired is available. */
} Adc_StatusType;

/**
 * @brief   ADC group notification.
 * @details Indicates if notification is enabled for the group.
 *
 */
typedef enum
{
    ADC_NOTIFICATION_DISABLED = 0U, /*!< Notification is disabled */
    ADC_NOTIFICATION_ENABLED        /*!< Notification is enabled */
} Adc_NotificationType;

/**
 * @brief   Adc hardware trigger edge.
 * @details Type for configuring on which edge of the hardware trigger signal the driver should
 * react, i.e. start the conversion (only if supported by the ADC hardware).
 *
 */
/* SWS_Adc_00520 */
typedef enum
{
    ADC_HW_TRIG_RISING_EDGE = 0U, /*!< React on the rising edge of the hardware trigger signal (only
                                     if supported by the ADC hardware). */
    ADC_HW_TRIG_FALLING_EDGE, /*!< React on the falling edge of the hardware trigger signal (only if
                                 supported by the ADC hardware). */
    ADC_HW_TRIG_BOTH_EDGES    /*!< React on both edges of the hardware trigger signal (only if
                                 supported by the ADC hardware). */
} Adc_HwTriggerSignalType;

/**
 * @brief   Adc hardware trigger source.
 * @details Type for configuring the trigger source for an ADC Channel group..
 *
 */
/* SWS_Adc_00514 */
typedef enum
{
    ADC_TRIGG_SRC_SW = 0U, /*!< Group is triggered by a software API call. */
    ADC_TRIGG_SRC_HW       /*!< Group is triggered by a hardware event. */
} Adc_TriggerSourceType;

#if (STD_ON == ADC_HW_TRIGGER_API)
/**
 * @brief   Adc Hardware trigger.
 * @details Indicates if hardware trigger is enabled for group.
 *
 */
typedef enum
{
    ADC_HWTRIGGER_DISABLED = 0U, /*!< Hardware trigger is disabled */
    ADC_HWTRIGGER_ENABLED        /*!< Hardware trigger is enabled */
} Adc_HwTriggeringType;

#endif /* (STD_ON==ADC_HW_TRIGGER_API) */

#if (ADC_POWER_STATE_SUPPORTED == STD_ON)
/**
 * @brief Result of the requests related to power state transitions.
 *
 */
/* SWS_Adc_00527 */
typedef enum
{
    ADC_SERVICE_ACCEPTED = 0U, /*!< Power state change executed. */
    ADC_NOT_INIT,              /*!< ADC Module not initialized. */
    ADC_SEQUENCE_ERROR,        /*!< Wrong API call sequence. */
    ADC_HW_FAILURE, /* The HW module has a failure which prevents it to enter the required power
                       state. */
    ADC_POWER_STATE_NOT_SUPP, /* ADC Module does not support the requested power state. */
    ADC_TRANS_NOT_POSSIBLE /* ADC Module cannot transition directly from the current power state to
                              the requested power state or the HW peripheral is still busy. */
} Adc_PowerStateRequestResultType;
#endif /* (ADC_POWER_STATE_SUPPORTED == STD_ON) */
/**
 * @brief Notification function pointer definition
 */
typedef void (*Adc_NotifyType)(void);

/**
 * @brief type for ADC result of one channel
 */
/* SWS_Adc_00508 */
typedef uint16 Adc_ValueGroupType;

/**
 * @brief Type of channel resolution in number of bits.
 */
/* SWS_Adc_00512 */
typedef uint8 Adc_ResolutionType;

#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
/**
 * @brief Priority level of the channel. Lowest priority is 0.
 */
/* SWS_Adc_00516 */
typedef uint8 Adc_GroupPriorityType;
#endif /* (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) */

/**
 * @brief Numeric ID of an ADC channel
 */
/* SWS_Adc_00506 */
typedef uint16 Adc_ChannelType;

/**
 * @brief Numeric ID of an ADC channel group. No uC dependent
 */
/* SWS_Adc_00507 */
typedef uint16 Adc_GroupType;

/**
 * @brief Type for assignment of channels to a channel group.
 */
/* SWS_Adc_00517 */
typedef Adc_ChannelType Adc_GroupDefType;

/**
 * @brief Type of clock prescaler factor.
 */
/* SWS_Adc_00509 */
typedef uint8 Adc_PrescaleType;

/**
 * @brief Type of sampling time, i.e. the time during which the value is sampled.
 */
/* SWS_Adc_00511 */
typedef uint8 Adc_SamplingTimeType;

/**
 * @brief Type for configuring the number of group conversions in streaming access mode (in single
 * access mode, parameter is 1).
 */
/* SWS_Adc_00518 */
typedef uint16 Adc_StreamNumSampleType;

/**
 * @brief Type for the reload value of the ADC module embedded timer (only if supported by the ADC
 * hardware).
 */
/* SWS_Adc_00521 */
typedef uint16 Adc_HwTriggerTimerType;

/**
 * @brief Type of conversion time, i.e. the time during which the sampled analogue value is
 * converted into digital representation.
 */
/* SWS_Adc_00510 */
typedef uint16 Adc_ConversionTimeType;

/**
 * @brief Index for the queue of groups
 */
typedef uint16 Adc_QueueIndexType;

/**
 * @brief Numeric ID of an ADC Hw Unit
 */
typedef uint8 Adc_HwUnitType;

/**
 * @brief Number of channels
 */
typedef uint8 Adc_ChannelIndexType;

#if (ADC_POWER_STATE_SUPPORTED == STD_ON)
/**
 * @brief Power state currently active or set as target power state. ADC_FULL_POWER 0: Full Power.
 */
/* SWS_Adc_00526 */
typedef uint8 Adc_PowerStateType;

/**
 * @brief Result of the requests related to power state transitions.
 */
typedef struct
{
    boolean        EndValidations; /*!< Signal if validation ended */
    Std_ReturnType ValidParams;    /*!< Return status */
} Adc_PowerStateRequestResultType;
#endif /* (ADC_POWER_STATE_SUPPORTED == STD_ON) */

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/**
 * @brief Structure for limit check of ADC channel.
 * @details This structure contains the channel limit check information.
 */
typedef struct
{
    const boolean ChannelLimitCheckEnabled;            /*!< Channel limit checking enabled */
    const Adc_ChannelRangeSelectType ChannelRange;     /*!< Range conversion */
    const uint16                     ChannelHighLimit; /*!< High limit channel conversion value */
    const uint16                     ChannelLowLimit;  /*!< Low limit channel conversion value */
} Adc_ChannelLimitCheckType;
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

/**
 * @brief   Structure for group status.
 * @details This structure contains the group status information.
 *
 */
typedef struct
{
    volatile Adc_StatusType ConvStatus; /*!< Group status */
    volatile Adc_GroupConversionStateType
        AlreadyConverted; /*!< Group was previously converted or not */
#if (ADC_HW_TRIGGER_API == STD_ON)
    Adc_HwTriggeringType HwTriggering; /*!< hw trigger enabled/disabled */
#endif                                 /* ADC_HW_TRIGGER_API == STD_ON */
#if (ADC_GROUP_NOTIF_CAPABILITY == STD_ON)
    Adc_NotificationType Notification; /*!< notification enabled/disabled */
#endif                                 /* ADC_GROUP_NOTIF_CAPABILITY == STD_ON */
    volatile Adc_StreamNumSampleType
        ResultIndex; /*!< index into streaming buffer that is currently being filled */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    volatile boolean LimitCheckFailed; /*!< check limit check fail */
#endif                                 /* ADC_ENABLE_LIMIT_CHECK == STD_ON */
} Adc_GroupStatusType;

/**
 * @brief   Structure for HW unit status.
 * @details This structure contains the HW unit status information.
 *
 */
typedef struct
{
    volatile Adc_QueueIndexType SwNormalQueueIndex; /*!< Filled slots in the queue */
    volatile Adc_GroupType SwNormalQueue[ADC_QUEUE_MAX_QUEUE_DEPTH]; /*!< Queued groups indexes,
                                                                        always executing Queue[0] */
#if (ADC_HW_TRIGGER_API == STD_ON)
    volatile Adc_GroupType OngoingHwGroup; /*!< Ongoing hardware group ID */
#endif                                     /* ADC_HW_TRIGGER_API == STD_ON */
} Adc_UnitStatusType;

/**
 * @brief Structure for HW Unit configuration.
 * @details This structure contains the configuration information of HW unit.
 */
typedef struct
{
    const Adc_GroupType    GroupNum;         /*!< Number of groups configured */
    const Adc_ChannelType  ChannelNum;       /*!< Number of channels of configured */
    const uint8            TransferMode;     /*!< DMA or Interrupt mode */
    const uint8            DmaChannel;       /*!< Dma channel number for HWUnit */
    Adc_Drv_ResolutionType Resolution;       /*!< ADC resolution (8,10,12 bit) */
    const boolean          WithoutInterrupt; /*!< Enables or Disables the ADC and DMA interrupts */
    const Adc_Drv_ConfigType     *AdcDrvConfigPtr; /*< Pointer to ADC driver configuration */
    const Tdg_Adc_Drv_ConfigType *TdgDrvConfigPtr; /*< Pointer to TDG driver configuration */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    const Adc_ChannelLimitCheckType *ChannelLimitCheckingConfig;
#endif
} Adc_HWUnitConfigType;

/**
 * @brief   Structure for List of HW Unit configuration.
 * @details This structure contains the set of configuration parameters required for HW unit.
 *
 */
typedef struct
{
    const Adc_HWUnitConfigType *HWUnitConfigPtr;
} Adc_HWUnitConfigListType;

/**
 * @brief   Structure for Group configuration.
 * @details This structure contains the set of configuration parameters required for group.
 *
 */
typedef struct
{
    const Adc_GroupType           GroupId;    /*!< Index of group */
    const Adc_HwUnitType          HwUnitId;   /*!< The ADC HW Unit Id that the group belongs to */
    const Adc_GroupAccessModeType AccessMode; /*!< Access Mode */
    const Adc_GroupConvModeType   ConvMode;   /*!< Conversion Mode (OneShot/Continuous) */
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    const Adc_GroupPriorityType Priority; /*!< Priority of group */
#endif                                    /* (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) */
    const Adc_GroupReplacementType ReplacementMode; /*!< Replacement Mode */
    const Adc_TriggerSourceType    TriggerSource;   /*!< Hw/Sw trigger */
#if (STD_ON == ADC_HW_TRIGGER_API)
    const Adc_TriggerSourceType   HwTriggerSource; /*!< Hardware trigger source for the group */
    const Adc_HwTriggerSignalType TriggerEdge;     /*!< Hardware trigger edge */
#endif                                             /* (STD_ON == ADC_HW_TRIGGER_API) */
#if (STD_ON == ADC_GROUP_NOTIF_CAPABILITY)
    const Adc_NotifyType Notification;               /*!< Pointer to notification function */
#endif                                               /* (STD_ON==ADC_GROUP_NOTIF_CAPABILITY) */
    Adc_ValueGroupType           **ResultsBufferPtr; /*!< pointer to user result buffer array */
    const Adc_StreamBufferModeType BufferMode;       /*!< Buffer Mode */
    const Adc_StreamNumSampleType  NumSamples;       /*!< Number of samples */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    const boolean GroupLimitcheck; /*!< enable or disable limit check for group. */
#endif                             /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
    const Adc_ChannelIndexType         AssignedChannelCount; /*!< Number of Assigned channels */
    const ADC_Drv_PositiveChannelType *AssignedChannelList;  /*!< Assigned channels to group */
    const Adc_Drv_GroupConfigType
        *AdcGroupConfigPtr; /*!< Pointer to ADC driver group configuration */
    const Tdg_Adc_Drv_GroupConfigType
        *TdgGroupConfigPtr; /*!< Pointer to ADC driver group configuration */
} Adc_GroupConfigType;

/**
 * @brief          Structure for ADC configuration.
 * @details        Data structure containing the set of configuration parameters required for
 * initializing the ADC Driver and ADC HW Unit(s).
 *
 */
/* SWS_Adc_00505 */
typedef struct
{
    const Adc_HWUnitConfigListType
                              *HWUnitConfigList; /*!< Pointer to list of HWUnit configuration */
    const Adc_GroupConfigType *GroupConfigList;  /*!< Group configurations */
    Adc_GroupType              GroupCount;       /*!< Total number of groups */
    uint32                     CoreId;           /*!< Configuration CoreID */
} Adc_ConfigType;
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

/** @} end of group Adc_Drv */

/** @} end of group Adc_Module */

#endif /* ADC_TYPES_H */
