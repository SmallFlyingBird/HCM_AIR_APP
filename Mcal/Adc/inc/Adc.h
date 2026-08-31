/**
 * @file    Adc.h
 * @version
 *
 * @brief   AUTOSAR Adc module interface
 * @details API implementation for ADC driver
 *
 * @addtogroup ADC_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Adc
 *   Dependencies         : none
 *
 *   Autosar Version      : V4.4.0
 *   Autosar Revision     : ASR_REL_4_4_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           : V2.3.0
 *
 *
 *   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
 *   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef ADC_H
#define ADC_H

#include "Platform_Types.h"
#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section Adc_PBCfg_C_REF_1
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers.
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 *
 * @section Adc_PBCfg_C_REF_2
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers.
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 */

/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include "Std_Types.h"
#include "Adc_Cfg.h"
/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_VENDOR_ID                      (180)
#define ADC_AR_RELEASE_MAJOR_VERSION       (4)
#define ADC_AR_RELEASE_MINOR_VERSION       (4)
#define ADC_AR_RELEASE_REVISION_VERSION    (0)
#define ADC_SW_MAJOR_VERSION               (2)
#define ADC_SW_MINOR_VERSION               (3)
#define ADC_SW_PATCH_VERSION               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ADC configuration header file are of the same vendor */
#if (ADC_VENDOR_ID != ADC_VENDOR_ID_CFG)
#error "Adc.h and Adc_Cfg.h have different vendor ids"
#endif

/* Check if source file and ADC configuration header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION != ADC_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (ADC_AR_RELEASE_MINOR_VERSION != ADC_AR_RELEASE_MINOR_VERSION_CFG) || \
     (ADC_AR_RELEASE_REVISION_VERSION != ADC_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Adc.h and Adc_Cfg.h are different"
#endif

/* Check if source file and ADC configuration header file are of the same software version */
#if ((ADC_SW_MAJOR_VERSION != ADC_SW_MAJOR_VERSION_CFG) || \
     (ADC_SW_MINOR_VERSION != ADC_SW_MINOR_VERSION_CFG) || \
     (ADC_SW_PATCH_VERSION != ADC_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Adc.h and Adc_Cfg.h are different"
#endif

/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief ADC MODULE INSTANCE ID */
#define ADC_INSTANCE_ID ((uint8)0U)

/** @brief ADC MODULE ID */
#define ADC_MODULE_ID ((uint8)123)


/**
 * @defgroup        Adc_DEV_ERROR
 * @brief           ADC development errors
 * @{
 */
/** @brief API called when module is not initialized */
#define ADC_E_UNINIT                         (0x0AU)
/** @brief API called while module is busy processing a user request. */
#define ADC_E_BUSY                           (0x0BU)
/** @brief API called while module is is idle. */
#define ADC_E_IDLE                           (0x0CU)
/** @brief API service for initialization called when already initialized. */
#define ADC_E_ALREADY_INITIALIZED            (0x0DU)
/** @brief API service called with wrong configuration. */
#define ADC_E_PARAM_CONFIG                   (0x0EU)
/** @brief API service called with wrong parameter. */
#define ADC_E_PARAM_POINTER                  (0x14U)
/** @brief API service called with invalid group id. */
#define ADC_E_PARAM_GROUP                    (0x15U)
/** @brief API service called with wrong conversion mode. */
#define ADC_E_WRONG_CONV_MODE                (0x16U)
/** @brief API service called with wrong trigger source. */
#define ADC_E_WRONG_TRIGG_SRC                (0x17U)
/** @brief Enable/disable notification function for a group whose configuration set has no notification available. */
#define ADC_E_NOTIF_CAPABILITY               (0x18U)
/** @brief Conversion started and result buffer pointer is not initialized. */
#define ADC_E_BUFFER_UNINIT                  (0x19U)
/** @brief One or more ADC group/channel not in IDLE state */
#define ADC_E_NOT_DISENGAGED                 (0x1AU)
/** @brief Unsupported power state request */
#define ADC_E_POWER_STATE_NOT_SUPPORTED      (0x1BU)
/** @brief Requested power state can not be reached directly */
#define ADC_E_TRANSITION_NOT_POSSIBLE        (0x1CU)
/** @brief ADC not prepared for target power state */
#define ADC_E_PERIPHERAL_NOT_PREPARED        (0x1DU)

/** @} */


/**
 * @defgroup        Adc_SID
 * @brief           Service ID number for all ADC driver services
 */
/** @{ */
/** @brief API Service ID for Adc_Init */
#define ADC_SID_INIT                                (0x00U)
/** @brief API Service ID for Adc_DeInit */
#define ADC_SID_DE_INIT                             (0x01U)
/** @brief API Service ID for Adc_StartGroupConversion */
#define ADC_SID_START_GROUP_CONVERSION              (0x02U)
/** @brief API Service ID for Adc_StopGroupConversion */
#define ADC_SID_STOP_GROUP_CONVERSION               (0x03U)
/** @brief API Service ID for Adc_ReadGroup */
#define ADC_SID_READ_GROUP                          (0x04U)
/** @brief API Service ID for Adc_EnableHardwareTrigger */
#define ADC_SID_ENABLE_HARDWARE_TRIGGER             (0x05U)
/** @brief API Service ID for Adc_DisableHardwareTrigger */
#define ADC_SID_DISABLE_HARDWARE_TRIGGER            (0x06U)
/** @brief API Service ID for Adc_EnableGroupNotification */
#define ADC_SID_ENABLE_GROUP_NOTIFICATION           (0x07U)
/** @brief API Service ID for Adc_DisableGroupNotification */
#define ADC_SID_DISABLE_GROUP_NOTIFICATION          (0x08U)
/** @brief API Service ID for Adc_GetGroupStatus */
#define ADC_SID_GET_GROUP_STATUS                    (0x09U)
/** @brief API Service ID for Adc_GetVersionInfo */
#define ADC_SID_GET_VERSION_INFO                    (0x0AU)
/** @brief API Service ID for Adc_GetStreamLastPointer */
#define ADC_SID_GET_STREAM_LAST_POINTER             (0x0BU)
/** @brief API Service ID for Adc_SetupResultBuffer */
#define ADC_SID_SETUP_RESULT_BUFFER                 (0x0CU)
#if (ADC_LOW_POWER_STATES_SUPPORT == STD_ON)
/** @brief API service ID for Adc_SetPowerState function */
#define ADC_SID_SET_POWER_STATE                     (0x10U)
/** @brief API service ID for Adc_GetCurrentPowerState function */
#define ADC_SID_GET_CURRENT_POWER_STATE             (0x11U)
/** @brief API service ID for Adc_GetTargetPowerState function */
#define ADC_SID_GET_TARGET_POWER_STATE              (0x12U)
/**  @brief API service ID for Adc_PreparePowerState function */
#define ADC_SID_PREPARE_POWER_STATE                 (0x13U)
#endif /* (ADC_POWER_STATE_SUPPORTED == STD_ON) */
/** @} */

/**
 * @brief Total number of hardware
 * @note Strong relationship to the hardware
 */
#define ADC_UNIT_TOTAL_NUMBER (uint8)(1U)

/*==================================================================================================
*                                         EXTERNAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/**
 * @brief           Ranges slecet value
 * @details         Indicates which range select is used.
 * @note            trace: SWS_Adc_00524
 * @implements      Adc_ChannelRangeSelectType_enum
 */
typedef enum
{
    ADC_RANGE_UNDER_LOW     = 0U,    /*!< Range below low limit - low limit value included*/
    ADC_RANGE_BETWEEN       = 1U,    /*!< Range between low limit and high limit - high limit value included*/
    ADC_RANGE_OVER_HIGH     = 2U,    /*!< Range above high limit*/
    ADC_RANGE_ALWAYS        = 3U,    /*!< Complete range - independent from channel limit settings*/
    ADC_RANGE_NOT_UNDER_LOW = 4U,    /*!< Range above low limit*/
    ADC_RANGE_NOT_BETWEEN   = 5U,    /*!< Range above high limit or below low limit - low limit value included*/
    ADC_RANGE_NOT_OVER_HIGH = 6U,    /*!< Range below high limit - high limit value included   */
} Adc_ChannelRangeSelectType;

/**
 * @brief           Adc group access mode.
 * @details         Used for configuring the group conversion result fifo access mode.
 * @note            trace: SWS_Adc_00528
 * @implements      Adc_GroupAccessModeType_enum
 */
typedef enum
{
    ADC_ACCESS_MODE_SINGLE    = 0U,    /*! Single access mode */
    ADC_ACCESS_MODE_STREAMING = 1U,    /*! Streaming access mode */
} Adc_GroupAccessModeType;

/**
 * @brief           Adc group conversion mode.
 * @details         Used for configuring the group conversion mode.
 * @note            trace: SWS_Adc_00515
 * @implements      Adc_GroupConvModeType_enum
 */
typedef enum
{
    ADC_CONV_MODE_ONESHOT    = 0U,    /*!< One-shot conversion mode*/
    ADC_CONV_MODE_CONTINUOUS = 1U,    /*!< Continuous conversion mode*/
} Adc_GroupConvModeType;


/**
 * @brief           Adc group replacement
 * @details         Used for configuring the replacemet for group.
 * @note            trace: SWS_Adc_00523
 * @implements      Adc_GroupReplacementType_enum
 */
typedef enum
{
    ADC_GROUP_REPL_ABORT_RESTART  = 0U,  /*!< Abort and restart of group*/
    ADC_GROUP_REPL_SUSPEND_RESUME = 1U,  /*!< Suspend and resume of group*/
} Adc_GroupReplacementType;


/**
 * @brief           Adc hardware trigger edge.
 * @details         Used for configuring trigger edge when a group configured hardware trigger.
 * @note            trace: SWS_Adc_00520
 * @implements      Adc_GroupTriggSrcType_enum
 */
typedef enum
{
    ADC_HW_TRIG_RISING_EDGE  = 0U,   /*!< Rising edge  */
    ADC_HW_TRIG_FALLING_EDGE = 1U,   /*!< Falling edge */
    ADC_HW_TRIG_BOTH_EDGES   = 2U,   /*!< Both edges   */
} Adc_HwTriggerSignalType;

/**
 * @brief           Adc group status.
 * @details         Used for return the status of group.
 * @note            trace: SWS_Adc_00513
 * @implements      Adc_StatusType_enum
 */
typedef enum
{
    ADC_IDLE             = 0U,     /*!< Group is in IDLE state*/
    ADC_BUSY             = 1U,     /*!< Group is in BUSY state*/
    ADC_COMPLETED        = 2U,     /*!< Group is in COMPLETED state*/
    ADC_STREAM_COMPLETED = 3U,     /*!< Group is in STREAM_COMPLETED state*/
} Adc_StatusType;

/**
 * @brief           Adc group streaming buffer mode.
 * @details         Used for configuring the group streaming buffer mode.
 * @note            trace: SWS_Adc_00519
 * @implements      Adc_StreamBufferModeType_enum
 */
typedef enum
{
    ADC_STREAM_BUFFER_LINEAR   = 0U,   /*!< Linear streaming buffer mode*/
    ADC_STREAM_BUFFER_CIRCULAR = 1U,   /*!< Circular streaming buffer mode*/
} Adc_StreamBufferModeType;

/**
 * @brief           Adc group trigger source.
 * @details         Used for configuring the group trigger source.
 * @note            trace: SWS_Adc_00514
 * @implements      Adc_TriggerSourceType_enum
 */
typedef enum
{
    ADC_TRIGG_SRC_SW = 0U,  /*!< Software trigger*/
    ADC_TRIGG_SRC_HW = 1U,  /*!< Hardware trigger*/
} Adc_TriggerSourceType;

/**
* @brief          ADC group notification.
* @details        Indicates if notification is enabled for the group.
* @implements     Adc_NotificationCfgType_enum
*/
typedef enum
{
    ADC_NOTIFICATION_DISABLED = 0U, /*!< @brief Notification is disabled */
    ADC_NOTIFICATION_ENABLED  = 1U, /*!< @brief Notification is enabled */
} Adc_NotificationCfgType;

/**
* @brief          ADC interrupt and DMA configure.
* @details        Indicates if group conversion end interrput and DMA is enabled for the group.
*
*/
typedef enum
{
    ADC_INTCANDDMA_DISABLED = 0U, /*!< @brief interrput and DMA is disabled */
    ADC_INTC_ENABLED   = 1U, /*!< @brief only the interrput is enabled */
    ADC_DMA_ENABLED    = 2U, /*!< @brief only the DMA is enabled*/
} Adc_IntcAdnDmaCfgType;

/**
 * @brief           Type for ADC result of one channel.
 * @note            trace: SWS_Adc_00508
 */
typedef uint16 Adc_ValueGroupType;

/**
 * @brief            Numeric ID of an ADC channel.
 * @note            trace: SWS_Adc_00506
 */
typedef uint8 Adc_ChannelType;

/**
 * @brief           Type for ADC channel configuring of one group.
 */
typedef struct
{
    const Adc_ChannelType   *GroupChannels;   /*!< @brief Pointer to the array of channels in the group. */
    Adc_ChannelType         GroupChannelsNum; /*!< @brief Number of channels in the group. */
    uint8                   GroupInHwUnitId;  /*!< @brief The hw unit id of the group. */
} Adc_GroupDefType;

/**
 * @brief           Type for ADC conversion time.
 * @note            trace: SWS_Adc_00510
 */
typedef uint16 Adc_ConversionTimeType;

/**
 * @brief           Numeric ID of an ADC group.
 * @note            trace: SWS_Adc_00507
 */
typedef uint16 Adc_GroupType;

/**
 * @brief Index for the queue of groups .
 */
typedef uint16 Adc_QueueIndexType;

/**
 * @brief           ADC Channel group priority.
 * @note            trace: SWS_Adc_00516
 */
typedef uint8 Adc_GroupPriorityType;

/**
 * @brief           Type for the reload value of the ADC embedded timer
 * @note            trace: SWS_Adc_00521
 */
typedef uint64 Adc_HwTriggerTimerType;

/**
 * @brief           ADC prescale value for the ADC clock.
 * @note            trace: SWS_Adc_00509
 */
typedef uint8 Adc_PrescaleType;

/**
 * @brief           Type for ADC resolution.
 * @details         Used for configuring the ADC resolution.
 * @note            trace: SWS_Adc_00512
 * @implements      Adc_ResolutionType_enum
 */
typedef enum
{
    ADC_RESOLUTION_12BIT   = 0U,    /*!< 12 bit resolution */
    ADC_RESOLUTION_10BIT   = 1U,    /*!< 10 bit resolution */
    ADC_RESOLUTION_8BIT    = 2U,    /*!< 8 bit resolution */
    ADC_RESOLUTION_6BIT    = 3U,    /*!< 6 bit resolution */
} Adc_ResolutionType;

/**
 * @brief   ADC Clock choose
 * @details Used for configuring the ADC function clock source.
 * @implements Adc_ClockSourceType_enum
 */
typedef enum
{
    ADC_BUSCLK = 0U,   /*!< Bus clock */
    ADC_FIRC   = 1U,   /*!< FIRC clock */
    ADC_EOSC   = 2U,   /*!< FXOSC clock */
    ADC_SIRC   = 3U,   /*!< SIRC clock */
} Adc_ClockSourceType;

#if (ADC_LOW_POWER_STATES_SUPPORT == STD_ON)
/**
* @brief      Power state type
* @details    Power state currently active or set as target power state.
* @implements     Adc_PowerStateType_enum
*/
typedef enum
{
    ADC_FULL_POWER = 0U,    /*!< Adc full power mode. */
    ADC_LOW_POWER,          /*!< Adc low power mode. */
    ADC_NODEFINE_POWER      /*!< Adc no define power mode. */
} Adc_PowerStateType;

/**
* @brief      Result of power state type
* @details    Result of the requests related to power state transitions.
* @implements     Adc_PowerStateRequestResultType_enum
*/
typedef enum
{
    ADC_SERVICE_ACCEPTED = 0U,  /*!< Power state change executed. */
    ADC_NOT_INIT,               /*!< Module not initialized. */
    ADC_SEQUENCE_ERROR,         /*!< Wrong API call sequence. */
    ADC_HW_FAILURE,             /*!< The HW module has a failure which prevents it to enter the required power state. */
    ADC_POWER_STATE_NOT_SUPP,   /*!< Module does not support the requested power state. */
    ADC_TRANS_NOT_POSSIBLE      /*!< Module cannot transition directly from the current power state to the requested power state. */
} Adc_PowerStateRequestResultType;
#endif /*(ADC_LOW_POWER_STATES_SUPPORT == STD_ON)*/

/**
* @brief            Type for ADC sampling time.
* @note            trace: SWS_Adc_00511
*/
typedef uint8 Adc_SamplingTimeType;

/**
* @brief           Number of samples of a streaming conversion buffer.
* @note            trace: SWS_Adc_00518
*/
typedef uint8 Adc_StreamNumSampleType;

/**
 * @brief           Notification function pointer definition
 * @note            trace: ECUC_Adc_00402
 */
typedef void(*Adc_NotificationType)(void);

/**
 * @brief       The channel configuration (parameters) depending on the hardware capability
 * @note        trace:ECUC_Adc_00268
 */
typedef struct
{
    /*ECUC_Adc_00011*/
    Adc_ConversionTimeType ChannelConvTime; /*!< Conversion time in ADC clock cycles */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    /*ECUC_Adc_00455*/
    uint64 ChannelHighLimit;  /*!< High limit value for limit check */
    /*ECUC_Adc_00453*/
    boolean ChannelLimitCheck; /*!< Enable/disable limit check */
    /*ECUC_Adc_00454*/
    uint64 ChannelLowLimit; /*!< Low limit value for limit check */
    /*ECUC_Adc_00456*/
    Adc_ChannelRangeSelectType ChannelRangeSelect; /*!< Select the range for limit check */
#endif
    /*ECUC_Adc_00089*/
    uint16 ChannelRefVoltsrcHigh; /*!< Reference voltage source high value */
    /*ECUC_Adc_00023*/
    uint16 ChannelRefVoltsrcLow; /*!< Reference voltage source low value */
    /*ECUC_Adc_00019*/
    Adc_ResolutionType ChannelResolution; /*!< Resolution of the channel */
    /*ECUC_Adc_00290*/
    Adc_SamplingTimeType ChannelSampTime; /*!< Sampling time in ADC clock cycles */
} Adc_ChannelSampleType;

/**
 * @brief       The Group configuration parameters.
 * @note        trace:ECUC_Adc_00028
 */
typedef struct
{
    /*ECUC_Adc_00317*/
    Adc_GroupAccessModeType GroupAccessMode;    /*!< Access mode of the group */
    /*ECUC_Adc_00397*/
    Adc_GroupConvModeType GroupConversionMode;  /*!< Conversion mode of the group */
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /*ECUC_Adc_00287*/
    Adc_GroupPriorityType GroupPriority;        /*!< Priority of the group */
#endif/* (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) */
    /*ECUC_Adc_00435*/
    Adc_GroupReplacementType GroupReplacement;  /*!< Replacement mode of the group */
    /*ECUC_Adc_00399*/
    Adc_TriggerSourceType GroupTriggSrc;        /*!< Trigger source of the group */

#if (ADC_HW_TRIGGER_API == STD_ON)
    Adc_HwTriggerSourceType HwTrigSrc;          /*!< Hardware trigger source select*/
    /*ECUC_Adc_00400*/
    Adc_HwTriggerSignalType HwTrigSignal;       /*!< Hardware trigger edge */
    /*ECUC_Adc_00401*/
    Adc_HwTriggerTimerType HwTrigTimer;         /*!< Hardware trigger delay timer value */
#endif

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    /*ECUC_Adc_00402*/
    Adc_NotificationType  NotificationFunc;        /*!< Notification function pointer for the group*/
#endif

    /*ECUC_Adc_00316*/
    Adc_StreamBufferModeType StreamingBufferMode;  /*!< Buffer mode of the group */
    /*ECUC_Adc_00292*/
    Adc_StreamNumSampleType StreamingNumSamples;   /*!< Number of samples of the group */
    /*ECUC_Adc_00014*/
    const Adc_GroupDefType *GroupDefinition;      /*!< Pointer to the group definition */

    Adc_IntcAdnDmaCfgType IntcAndDmaCfg;         /*!< Interrupt and DMA configuration */
} Adc_GroupSampleType;

/**
 * @brief       The ADC HW specific parameters.
 * @note        trace:ECUC_Adc_00242
 */
typedef struct
{
    /*ECUC_Adc_00389*/
    uint8 HwUnitId;          /*!< ADC HW unit ID */
    /*ECUC_Adc_00087*/
    Adc_ClockSourceType ClockSource;  /*!< ADC clock source */
    /*ECUC_Adc_00088*/
    uint8 Prescale;         /*!< ADC prescale value */
    /*Adc startup time config*/
    uint8 StartupTime;    /*!< ADC startup time */
    /*Internal tempreture sensor enable*/
    boolean InternalTempSensor; /*!< Internal tempreture sensor enable */
#ifdef ADC_DMA_SUPPORTED
    uint8 DmaChannel;                            /*!< DMA channel configuration for ADC */
#endif
} Adc_HwUnitType;

/**
 * @brief       The Group configuration parameters,include GroupID and channel configuration.
 * @note        trace:ECUC_Adc_00028
 */
typedef struct
{
    /*ECUC_Adc_00398*/
    Adc_GroupType                 GroupId;  /*!< Group ID */

    const Adc_ChannelSampleType   *ChannelSample;  /*!< Pointer to the channel configuration */

    const Adc_GroupSampleType     *GroupSample;    /*!< Pointer to the group configuration */
} Adc_GroupConfigType;

/**
 * @brief       The configuration parameters and sub containers of the AUTOSAR Adc module.
 * @note        trace:ECUC_Adc_00390
 */
typedef struct
{
    const uint8       HwUnitCfgNum;    /*!< The number of hw unit will be configured. */

    const uint8       GroupCfgNum;      /*!< The number of group will be configured*/

    const Adc_HwUnitType       *HwUnitUserCfg;  /*!< ADC HW module configuration*/

    const Adc_GroupConfigType  *GroupUserCfg;  /*!< ADC groups configuration*/
} Adc_ConfigType;

/**
* @brief          Structure for hardware unit status.
* @details        This structure contains the HW unit status information.
*
*/
typedef struct
{
    volatile Adc_QueueIndexType SwNormalQueueIndex; /*!< Queue index for all groups in the hw unit */

#if ((ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)|| (ADC_ENABLE_QUEUING == STD_ON))
    volatile Adc_GroupType SwNormalQueue[ADC_QUEUE_MAX_DEPTH_MAX]; /*!< the queue for group ID,the Queue[0] is conversion group*/

    volatile Adc_GroupPriorityType SwNormalQueuePriority[ADC_QUEUE_MAX_DEPTH_MAX]; /*!< Queue index for all groups in the hw unit */
#else
    volatile Adc_GroupType SwNormalQueue[1]; /*!< the queue for group ID,the Queue[0] is conversion group*/
#endif/* ((ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)|| (ADC_ENABLE_QUEUING == STD_ON)) */
#if (ADC_HW_TRIGGER_API == STD_ON)
    volatile Adc_GroupType HwOngoingHwGroup;       /*!< Ongoing hardware group ID */
#endif /* ADC_HW_TRIGGER_API == STD_ON */
} Adc_UnitStatusType;


/**
 * @brief          Structure for group status.
 * @details        This structure contains the group status information and result fifo ptr.
*/
typedef struct
{
    Adc_StatusType             GroupStatus;            /*!< Group status */
    Adc_ValueGroupType        *GroupValueBuf;          /*!< Pointer to the result buffer */
    boolean                    ResultBufInitSt;   /*!< Result buffer init status */
    boolean                    SampleFinished;    /*!< Sample finished status */
    Adc_StreamNumSampleType    GroupSampleCount;  /*!< Sample count of the group */
    Adc_ChannelType            GroupCompChnNum;   /*!< Channel count of conversion completed in the group */
    Adc_ChannelType            GroupLoadChnNum;   /*!< Channel count of loading to Adc hardware sequence */
#if (ADC_GRP_NOTIF_CAPABILITY==STD_ON)
    Adc_NotificationCfgType       NotificationEnFlag;   /*!< Notification status */
#endif
} Adc_GroupResultType;

/********************************************************************/
/* Global data extern*/
/* Variable Adc_ConfigPtr point to configuration data of ADC units */
extern const Adc_ConfigType *Adc_ConfigPtr;

/*ADC conversion result buffer*/
#if(ADC_FIXED_PB_CONFIG == STD_ON)
extern Adc_GroupResultType     Adc_GroupResult[ADC_GROUP_NUMBER];
#else
extern Adc_GroupResultType     Adc_GroupResult[ADC_MAX_GROUPS];
#endif

/*ADC hw status data*/
extern Adc_UnitStatusType Adc_HwStatus[ADC_MAX_HW_UNITS];




/*-----------------------------------------------------*/


/**
 * @brief            Initializes the ADC hardware units and driver.
 * @details          This function will initialize both the ADC HW unit and the driver structures.
 * @param[in]        ConfigPtr Pointer to configuration set in Variant PB
                    (Variant PC  requires a NULL_PTR).
 * @return           void
 */
void Adc_Init(const Adc_ConfigType *ConfigPtr);

/**
 * @brief            Initializes the result buffer for specific group.
 * @details          Initializes ADC driver with the group specific result buffer start address where
 *                   the conversion results will be stored. The application has to ensure that the
 *                   application  buffer, where DataBufferPtr points to, can hold all the conversion
 *                   results of the specified group. The initialization with Adc_SetupResultBuffer is
 *                   required after reset, before a group conversion can be started.
 * @param[in]        Group Numeric ID of requested ADC channel group.
 * @param[in]        DataBufferPtr pointer to result data buffer
 * @return           Std_ReturnType
 */
Std_ReturnType Adc_SetupResultBuffer(Adc_GroupType Group, Adc_ValueGroupType *DataBufferPtr);


#if (ADC_DE_INIT_API == STD_ON)
/**
 * @brief            De-initializes all ADC HW Units.
 * @details          Returns all ADC HW Units to a state comparable to their power on reset state.
 * @return           void
 */
void Adc_DeInit(void);
#endif/*ADC_DE_INIT_API == STD_ON*/

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
/**
 * @brief            Disables the notification for specific group.
 * @details          This function will disable the notification mechanism only for
 *                   the requested ADC channel group.
 * @param[in]        Group Numeric ID of requested ADC Channel group.
 * @return           void
 */
void Adc_DisableGroupNotification(Adc_GroupType Group);

/**
 * @brief            Enable the notification for specific group.
 * @details          This function will enable the notification mechanism only for
 *                    the requested ADC channel group.
 * @param[in]        Group Numeric ID of requested ADC Channel group.
 * @return           void
 */
void Adc_EnableGroupNotification(Adc_GroupType Group);
#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */

#if (ADC_HW_TRIGGER_API == STD_ON)
/**
 * @brief            Disables the hardware trigger for the requested group.
 * @details          This function will disable the HW trigger source for the requested
 *                   ADC channel group.
 * @param[in]        Group Numeric ID of requested ADC Channel group.
 * @return           void
 */
void Adc_DisableHardwareTrigger(Adc_GroupType Group);

/**
 * @brief            Enables the hardware trigger for the requested group.
 * @details          This function will enable the notification mechanism only for
 *                   the requested ADC channel group.
 * @param[in]        Group Numeric ID of requested ADC Channel group.
 * @return           void
 */
void Adc_EnableHardwareTrigger(Adc_GroupType Group);
#endif /* ADC_HW_TRIGGER_API == STD_ON */

#if (ADC_LOW_POWER_STATES_SUPPORT == STD_ON)
/**
 * @brief            Get the current power state of the ADC HW unit.
 * @details          This API returns the current power state of the ADC HW unit.
 * @param[out]       CurrentPowerState The current power mode of the ADC HW Unit is returned in this
 *                    parameter
 * @param[out]       Result If the API returns E_OK:
                                               ADC_SERVICE_ACCEPTED: Current power mode was returned.
                            If the API returns E_NOT_OK:
                                               ADC_NOT_INIT: ADC Module not initialized.
 * @return           Std_ReturnType
 */
Std_ReturnType Adc_GetCurrentPowerState(Adc_PowerStateType *CurrentPowerState, Adc_PowerStateRequestResultType *Result);

/**
 * @brief            Get the target power state of the ADC HW unit.
 * @details          This API returns the Target power state of the ADC HW unit.
 * @param[out]       TargetPowerState The Target power mode of the ADC HW Unit is returned in this
 *                   parameter
 * @param[out]       Result If the API returns E_OK:
 *                                   ADC_SERVICE_ACCEPTED:Target power mode was returned.
 *                          If the API returns E_NOT_OK:
 *                                   ADC_NOT_INIT: ADC Module not initialized.
 * @return           Std_ReturnType
 */
Std_ReturnType Adc_GetTargetPowerState(Adc_PowerStateType *TargetPowerState, Adc_PowerStateRequestResultType *Result);

/**
 * @brief            Starts the needed process to allow the ADC HW module to enter the requested power state.
 * @details          This API starts the needed process to allow the ADC HW module to enter the requested
 *                   power state.
 * @param[in]        PowerState The target power state intended to be attained
 * @param[out]       Result If the API returns E_OK:
 *                   ADC_SERVICE_ACCEPTED: ADC Module power state preparation was started.
 *                   If the API returns E_NOT_OK:
 *                   ADC_NOT_INIT: ADC Module not initialized.
 *                   ADC_SEQUENCE_ERROR: wrong API call sequence (Current Power State = Target Power State).
 *                   ADC_POWER_STATE_NOT_SUPP: ADC Module does not support the requested power state.
 *                   ADC_TRANS_NOT_POSSIBLE: ADC Module cannot transition directly from the current power state to the
 *                   requested power state or the HW peripheral is still busy.
 * @return           Std_ReturnType
 */
Std_ReturnType Adc_PreparePowerState(Adc_PowerStateType PowerState, Adc_PowerStateRequestResultType *Result);

/**
 * @brief            Enters the already prepared power state.
 * @details          This API configures the Adc module so that it enters the already prepared power
 *                   state, chosen between a predefined set of configured ones.
 * @param[out]       Result If the API returns E_OK:
 *                               ADC_SERVICE_ACCEPTED: Power state change executed.
 *                           If the API returns E_NOT_OK:
 *                                ADC_NOT_INIT: ADC Module not initialized.
 *                                ADC_SEQUENCE_ERROR: wrong API call sequence.
 *                                ADC_HW_FAILURE: the HW module has a failure which
 *                                prevents it to enter the required power state.
 * @return           Std_ReturnType
 */
Std_ReturnType Adc_SetPowerState(Adc_PowerStateRequestResultType *Result);

#if (ADC_POWER_STATE_ASYNCH_TRANSITION_MODE == STD_ON)
/**
 * @brief            Cyclically called and supervises the power state transitions.
 * @details          This API is cyclically called and supervises the power state transitions,
 *                   checking for the readiness of the module and issuing the callbacks IoHwAb_
 *                   Adc_NotifyReadyForPowerState<Mode> (see AdcPowerStateReadyCbkRef configuration
 *                   parameter).
 * @return           void
 */
void Adc_Main_PowerTransitionManager(void);
#endif /*ADC_POWER_STATE_ASYNCH_TRANSITION_MODE == STD_ON*/
#endif /* ADC_LOW_POWER_STATES_SUPPORT == STD_ON */

/**
 * @brief            Returns the conversion status of the requested ADC Channel group.
 * @details          This function will return the conversion status of the requested
 *                    group.
 * @param[in]        Group Numeric ID of requested ADC Channel group.
 * @return           Adc_StatusType
 */
Adc_StatusType Adc_GetGroupStatus(Adc_GroupType Group);

/**
 * @brief            Returns the number of valid samples per channel.
 * @details          Returns the number of valid samples per channel, stored in the result buffer.
 *                   Reads a pointer, pointing to a position in the group result buffer. With the
 *                   pointer position, the  results of all group channels of the last completed
 *                   conversion round can be accessed. With the pointer and the return value, all
 *                   valid group conversion results can be accessed (the user has to take the
 *                   layout of the result buffer into account).
 * @param[in]        Group Numeric ID of requested ADC Channel group.
 * @param[out]       PtrToSamplePtr Pointer to result buffer pointer.
 * @return           Adc_StreamNumSampleType
 */
Adc_StreamNumSampleType Adc_GetStreamLastPointer(Adc_GroupType Group, Adc_ValueGroupType **PtrToSamplePtr);

#if (ADC_READ_GROUP_API == STD_ON)
/**
 * @brief            Reads the group conversion results.
 * @details          Reads the group conversion result of the  last completed conversion round of the
 *                   requested group and stores the channel values starting at the DataBufferPtr address.
 *                   The group channel values are stored in ascending channel number order ( in contrast
 *                   to the storage layout of the result buffer if streaming access is configured).
 * @param[in]        Group Numeric ID of requested ADC channel group.
 * @param[out]       DataBufferPtr ADC results of all channels of the selected group are stored in
 *                                 the data buffer addressed with the pointer.
 * @return           Std_ReturnType
 */
Std_ReturnType Adc_ReadGroup(Adc_GroupType Group, Adc_ValueGroupType *DataBufferPtr);
#endif /* ADC_READ_GROUP_API == STD_ON */

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
/**
 * @brief            Starts the conversion of a specific group.
 * @details          This function will start the SW conversion of the requested ADC group.
 * @param[in]        Group Numeric ID of requested ADC Channel group.
 * @return           void
 */
void Adc_StartGroupConversion(Adc_GroupType Group);

/**
 * @brief            Stops the conversion of a specific group.
 * @details          This function will stop the SW conversion of the requested ADC group.
 * @param[in]        Group Numeric ID of requested ADC Channel group.
 * @return           void
 */
void Adc_StopGroupConversion(Adc_GroupType Group);
#endif /* ADC_ENABLE_START_STOP_GROUP_API == STD_ON */

#if (((ADC_VERSION_INFO_API == STD_ON) && (ADC_DEV_ERROR_DETECT == STD_ON)))
/**
 * @brief            Returns the version information of this module.
 * @details
 * @param[out]       versioninfo Pointer to where to store version information of this module
 * @return           void
 */
#define Adc_GetVersionInfo(versioninfo)                                       \
    {                                                                         \
        /* Check for DET: ADC_E_PARAM_POINTER */                              \
        if ((versioninfo) == NULL_PTR)                                        \
        {                                                                     \
            /* Report ADC_E_PARAM_POINTER DET if service called with          \
               NULL_PTR                                                       \
            */                                                                \
            Det_ReportError(                                                  \
                (uint16)ADC_MODULE_ID,                                        \
                ADC_INSTANCE_ID,                                              \
                ADC_SID_GET_VERSION_INFO,                                     \
                ADC_E_PARAM_POINTER);                                         \
        }                                                                     \
        else                                                                  \
        {                                                                     \
            /* Vendor ID information */                                       \
            ((Std_VersionInfoType *)(versioninfo))->vendorID = ADC_VENDOR_ID; \
            /* Adc module ID information */                                   \
            ((Std_VersionInfoType *)(versioninfo))->moduleID = ADC_MODULE_ID; \
            /* Adc module Software major version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_major_version =        \
                (uint8)ADC_SW_MAJOR_VERSION;                                      \
            /* Adc module Software minor version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_minor_version =        \
                (uint8)ADC_SW_MINOR_VERSION;                                      \
            /* Adc module Software patch version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_patch_version =        \
                (uint8)ADC_SW_PATCH_VERSION;                                      \
        }                                                                     \
    }
#elif (((ADC_VERSION_INFO_API == STD_ON) && (ADC_DEV_ERROR_DETECT == STD_OFF)))
#define Adc_GetVersionInfo(versioninfo)                                   \
    {                                                                     \
        /* Vendor ID information */                                       \
        ((Std_VersionInfoType *)(versioninfo))->vendorID = ADC_VENDOR_ID; \
        /* Adc module ID information */                                   \
        ((Std_VersionInfoType *)(versioninfo))->moduleID = ADC_MODULE_ID; \
        /* Adc module Software major version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_major_version =        \
            (uint8)ADC_SW_MAJOR_VERSION;                                      \
        /* Adc module Software minor version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_minor_version =        \
            (uint8)ADC_SW_MINOR_VERSION;                                      \
        /* Adc module Software patch version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_patch_version =        \
            (uint8)ADC_SW_PATCH_VERSION;                                      \
    }
#endif /* ADC_VERSION_INFO_API == STD_ON && ADC_DEV_ERROR_DETECT == STD_ON */

#ifdef __cplusplus
}
#endif

#endif /* ADC_H */

/** @} */

