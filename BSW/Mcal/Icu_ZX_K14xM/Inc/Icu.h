/**************************************************************************************************/
/**
 * @file      : Icu.h
 * @brief     : AUTOSAR Icu driver head file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef ICU_H
#define ICU_H

/** @addtogroup  Icu_Module
 *  @{
 */

/** @addtogroup  Icu
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Icu_Types.h"

#if (STD_ON == ICU_WAKEUP_FUNCTIONALITY_API)
#include "EcuM.h"
#endif


/** @defgroup Public_MacroDefinition
 *  @{
 */
#define ICU_MODULE_ID                   122U
#define ICU_VENDOR_ID                   0x00B3U
#define ICU_AR_RELEASE_MAJOR_VERSION    4U
#define ICU_AR_RELEASE_MINOR_VERSION    6U
#define ICU_AR_RELEASE_REVISION_VERSION 0U
#define ICU_SW_MAJOR_VERSION            1U
#define ICU_SW_MINOR_VERSION            2U
#define ICU_SW_PATCH_VERSION            2U

#if (ICU_VENDOR_ID != ICU_TYPES_H_VENDOR_ID)
    #error "Vendor ID Icu.h and Icu_Types.h have different"
#endif
    
#if (ICU_AR_RELEASE_REVISION_VERSION != ICU_TYPES_H_AR_RELEASE_REVISION_VERSION)
    #error "Vendor ID Icu.h and Icu_Types.h have different"
#endif

#if ((ICU_AR_RELEASE_MAJOR_VERSION != ICU_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
        (ICU_AR_RELEASE_MINOR_VERSION != ICU_TYPES_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Icu.h and Icu_Types.h are different"
#endif
    
#if ((ICU_SW_MAJOR_VERSION != ICU_TYPES_H_SW_MAJOR_VERSION) || \
        (ICU_SW_MINOR_VERSION != ICU_TYPES_H_SW_MINOR_VERSION))
    #error "Software version of Icu.h and Icu_Types.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if (STD_ON == ICU_WAKEUP_FUNCTIONALITY_API)
        #if ((ICU_AR_RELEASE_MAJOR_VERSION != ECUM_AR_RELEASE_MAJOR_VERSION) ||                    \
             (ICU_AR_RELEASE_MINOR_VERSION != ECUM_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar version of Icu.h and EcuM.h are different"
        #endif

        #if ((ICU_SW_MAJOR_VERSION != ECUM_SW_MAJOR_VERSION) ||                                    \
             (ICU_SW_MINOR_VERSION != ECUM_SW_MINOR_VERSION))
            #error "Software version of Icu.h and EcuM.h are different"
        #endif
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

#if (STD_ON == ICU_DEV_ERROR_DETECT)
/**
* @brief API service ID for Icu_Init function
* */
#define ICU_SID_INIT                                            ((uint8)0x00U)

#if (STD_ON == ICU_DEINIT_API)
/**
* @brief API service ID for Icu_DeInit function
* */
#define ICU_SID_DEINIT                                          ((uint8)0x01U)
#endif

#if (STD_ON == ICU_SET_MODE_API)
/**
* @brief API service ID for Icu_SetMode function
* */
#define ICU_SID_SET_MODE                                         ((uint8)0x02U)
#endif

#if (STD_ON == ICU_DISABLE_WAKEUP_API)
/**
* @brief API service ID for Icu_DisableWakeup function
* */
#define ICU_SID_DISABLE_WAKEUP                                   ((uint8)0x03U)
#endif

#if (STD_ON == ICU_ENABLE_WAKEUP_API)
/**
* @brief API service ID for Icu_EnableWakeup function
* */
#define ICU_SID_ENABLE_WAKEUP                                    ((uint8)0x04U)
#endif

#if (STD_ON == ICU_WAKEUP_FUNCTIONALITY_API)
/**
* @brief API service ID for Icu_CheckWakeup function
* */
#define ICU_SID_CHECK_WAKEUP                                     ((uint8)0x15U)
#endif

/**
* @brief API service ID for Icu_SetActivationCondition function
* */
#define ICU_SID_SET_ACTIVATION_CONDITION                          ((uint8)0x05U)

/**
* @brief API service ID for Icu_DisableNotification function
* */
#define ICU_SID_DISABLE_NOTIFICATION                             ((uint8)0x06U)

/**
* @brief API service ID for Icu_EnableNotification function
* */
#define ICU_SID_ENABLE_NOTIFICATION                              ((uint8)0x07U)

#if (STD_ON == ICU_GET_INPUT_STATE_API)
/**
* @brief API service ID for Icu_GetInputState function
* */
#define ICU_SID_GET_INPUT_STATE                                 ((uint8)0x08U)
#endif

#if (STD_ON == ICU_TIMESTAMP_API)
/**
* @brief API service ID for Icu_StartTimestamp function
* */
#define ICU_SID_START_TIMESTAMP                                  ((uint8)0x09U)

/**
* @brief API service ID for Icu_StopTimestamp function
* */
#define ICU_SID_STOP_TIMESTAMP                                   ((uint8)0x0AU)

/**
* @brief API service ID for Icu_GetTimestampIndex function
* */
#define ICU_SID_GET_TIMESTAMP_INDEX                               ((uint8)0x0BU)
#endif

#if (STD_ON == ICU_EDGE_COUNT_API)
/**
* @brief API service ID for Icu_ResetEdgeCount function
* */
#define ICU_SID_RESET_EDGE_COUNT                                  ((uint8)0x0CU)

/**
* @brief API service ID for Icu_EnableEdgeCount function
* */
#define ICU_SID_ENABLE_EDGE_COUNT                                 ((uint8)0x0DU)

/**
* @brief API service ID for Icu_DisableEdgeCount function
* */
#define ICU_SID_DISABLE_EDGE_COUNT                                ((uint8)0x0EU)

/**
* @brief API service ID for Icu_GetEdgeNumbers function
* */
#define ICU_SID_GET_EDGE_NUMBERS                                  ((uint8)0x0FU)
#endif

#if (STD_ON == ICU_EDGE_DETECT_API)
/**
* @brief API service ID for Icu_EnableEdgeDetection function
* */
#define ICU_SID_ENABLE_EDGE_DETECTION                             ((uint8)0x16U)

/**
* @brief API service ID for Icu_DisableEdgeDetection function
* */
#define ICU_SID_DISABLE_EDGE_DETECTION                            ((uint8)0x17U)
#endif

#if (STD_ON == ICU_SIGNAL_MEASUREMENT_API)
/**
* @brief API service ID for Icu_StartSignalMeasurement function
* */
#define ICU_SID_START_SIGNAL_MEASUREMENT                          ((uint8)0x13U)

/**
* @brief API service ID for Icu_StopSignalMeasurement function
* */
#define ICU_SID_STOP_SIGNAL_MEASUREMENT                           ((uint8)0x14U)
#endif

#if (STD_ON == ICU_GET_TIMEELAPSED_API)
/**
* @brief API service ID for Icu_GetTimeElapsed function
* */
#define ICU_SID_GET_TIME_ELAPSED                                  ((uint8)0x10U)
#endif

#if (STD_ON == ICU_GET_DUTY_CYCLE_VALUES_API)
/**
* @brief API service ID for Icu_GetDutyCycleValues function
* */
#define ICU_SID_GET_DUTY_CYCLE_VALUES                              ((uint8)0x11U)
#endif

/**
* @brief API service ID for Icu_GetVersionInfo function
* */
#define ICU_SID_GET_VERSION_INFO                                  ((uint8)0x12U)


/**
* @brief   API is called with invalid pointer
* */
/* SWS_Icu_00382 */
#define ICU_E_PARAM_POINTER                                     ((uint8)0x0AU)

/**
* @brief   API service used with an invalid channel identifier or channel
*          was not configured for the functionality of the calling API
* */
/* SWS_Icu_00382 */
#define ICU_E_PARAM_CHANNEL                                     ((uint8)0x0BU)

/**
* @brief   API service used with an invalid or not feasible activation
* */
/* SWS_Icu_00382 */
#define ICU_E_PARAM_ACTIVATION                                  ((uint8)0x0CU)

/**
* @brief   Init function failed
* */
/* SWS_Icu_00382 */
#define ICU_E_INIT_FAILED                                       ((uint8)0x0DU)

#if (STD_ON == ICU_TIMESTAMP_API)
/**
* @brief   API service used with an invalid buffer size
* */
/* SWS_Icu_00382 */
#define ICU_E_PARAM_BUFFER_SIZE                                 ((uint8)0x0EU)
#endif

#if (STD_ON == ICU_SET_MODE_API)
/**
* @brief   API service Icu_SetMode used with an invalid mode
* */
/* SWS_Icu_00382 */
#define ICU_E_PARAM_MODE                                        ((uint8)0x0FU)

/**
* @brief   API service Icu_SetMode is called while a running operation
* */
/* SWS_Icu_00382 */
#define ICU_E_BUSY_OPERATION                                    ((uint8)0x16U)
#endif

/**
* @brief   API service used without module initialization
* */
/* SWS_Icu_00382 */
#define ICU_E_UNINIT                                            ((uint8)0x14U)

/**
* @brief   API Icu_Init service is called and when the ICU driver and the
*          Hardware are already initialized
* */
/* SWS_Icu_00382 */
#define ICU_E_ALREADY_INITIALIZED                               ((uint8)0x17U)

#if (STD_ON == ICU_TIMESTAMP_API)
/**
* @brief   API Icu_StartTimeStamp is called and the parameter Notify
*          Interval is invalid (e.g."0", NotifyInterval < 1)
* */
/* SWS_Icu_00382 */
#define ICU_E_PARAM_NOTIFY_INTERVAL                             ((uint8)0x18U)
#endif

/**
* @brief   API Icu_GetVersionInfo is called and the parameter
*          versioninfo is is invalid ( e.g. NULL )
* */
/* SWS_Icu_00382 */
#define ICU_E_PARAM_VINFO                                       ((uint8)0x19U)

/**
* @brief   API service used with invalid configure parameter
* */
#define ICU_E_PARAM_INVALID                                     ((uint8)0x1AU)

#if (STD_OFF == ICU_OVERFLOW_NOTIFICATION_API)
#if (STD_ON == ICU_EDGE_COUNT_API)
/**
* @brief   API Icu_GetEdgeNumbers service called when the counter rollback
* */
#define ICU_E_EDGECOUNT_OVERFLOW                                ((uint8)0x1BU)
#endif

#if (STD_ON == ICU_TIMESTAMP_API)
/**
* @brief   API Icu_GetTimestampIndex service called when the counter overflow
* */
#define ICU_E_TIMESTAMP_OVERFLOW                                ((uint8)0x1CU)
#endif

#if ((STD_ON == ICU_GET_TIMEELAPSED_API) || (STD_ON == ICU_GET_DUTY_CYCLE_VALUES_API))
/**
* @brief   API Icu_GetTimeElapsed service called when the counter overflow
* */
#define ICU_E_MEASUREMENT_OVERFLOW                              ((uint8)0x1DU)
#endif
#endif

/**
* @brief   API Check mode before start operation
* */
#define ICU_E_MODE_INVALID                                      ((uint8)0x1EU)

#if (STD_ON == ICU_TIMESTAMP_API)
/**
* @brief   API service Icu_StopTimestamp called on a channel which was
*          not started or already stopped
* */
/* SWS_Icu_91004 */
#define ICU_E_NOT_STARTED                                       ((uint8)0x15U)

#endif
#endif

/** @} end of group Public_MacroDefinition */

/** @defgroup Public_TypeDefinition 
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/**
 * @brief   Export Post-Build configurations.
 */
#if (ICU_PRECOMPILE_SUPPORT == STD_ON)
    #define ICU_START_SEC_CONFIG_DATA_PTR
    #include "Icu_MemMap.h"
extern const Icu_ConfigType *const Icu_PredefinedConfigPtr[ICU_PARTITIONS_MAXNUM];
    #define ICU_STOP_SEC_CONFIG_DATA_PTR
    #include "Icu_MemMap.h"
#else
    #define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Icu_MemMap.h"
/**
 * @brief   Export Post-Build configurations.
 */
ICU_CONFIG_EXT

    #define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Icu_MemMap.h"
#endif /* (ICU_PRECOMPILE_SUPPORT == STD_ON) */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @brief Icu functions declaration
 *  @{
 */
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

/**
 * @brief      This function initializes the driver.
 *
 * @param[in]  ConfigPtr: Pointer to a Icu initial configuration structure
 *
 * @return none
 *
 */
/* SWS_Icu_00191 */
void Icu_Init(const Icu_ConfigType * ConfigPtr);

#if (STD_ON == ICU_DEINIT_API)
/**
 * @brief      This function de-initializes the ICU module. 
 *
 * @param[in]  none
 *
 * @return     none
 *
 */
/* SWS_Icu_00193 SWS_Icu_00092*/
void Icu_DeInit(void);
#endif

/**
 * @brief      This function sets the activation-edge for the given Channel
 *
 * @param[in]  Channel: Numeric identifier of the ICU channel
 * @param[in]  Activation: Type of activation (if supported by hardware)
 *                         - ICU_RISING_EDGE
 *                         - ICU_FALLING_EDGE
 *                         - ICU_BOTH_EDGES
 *
 * @return none
 *
 */
/* SWS_Icu_00197 */
void Icu_SetActivationCondition(Icu_ChannelType Channel, Icu_ActivationType Activation);

/**
 * @brief      This function enables the notification on the given Channel
 *
 * @param[in]  Channel: Numeric identifier of the ICU channel
 *
 * @return none
 *
 */
/* SWS_Icu_00199 */
void Icu_EnableNotification(Icu_ChannelType Channel);

/**
 * @brief      This function disables the notification of a Channel
 *
 * @param[in]  Channel: Numeric identifier of the ICU channel
 *
 * @return none
 *
 */
/* SWS_Icu_00198 */
void Icu_DisableNotification(Icu_ChannelType Channel);

#if (STD_ON == ICU_GET_INPUT_STATE_API)
/**
 * @brief      This function returns the status of the ICU input
 *
 * @param[in]  Channel: Numeric identifier of the ICU channel
 *
 * @return     Icu_InputStateType
 *             - ICU_ACTIVE: An activation edge has been detected
 *             - ICU_IDLE: No activation edge has been detected since the last
 *                         call of Icu_GetInputState() or Icu_Init().
 *
 */
/* SWS_Icu_00200 SWS_Icu_00122*/
Icu_InputStateType Icu_GetInputState(Icu_ChannelType Channel);
#endif

#if (STD_ON == ICU_SET_MODE_API)
/**
 * @brief      This function sets the ICU Mode
 *
 * @param[in]  Mode: ICU_MODE_NORMAL: Normal operation, all used interrupts are enabled
 *                                    according to the notification requests. 
 *                   ICU_MODE_SLEEP: Reduced power mode. In sleep mode only those notifications are
 *                                  available which are configured as wakeup capable.
 *
 * @return none
 *
 */
/* SWS_Icu_00194 SWS_Icu_00095*/
void Icu_SetMode(Icu_ModeType Mode);
#endif

#if (STD_ON == ICU_TIMESTAMP_API)
/**
 * @brief      This function starts the capturing of timer values on the edges
 *
 * @param[in]  Channel:        Numeric identifier of the ICU channel
 * @param[in]  BufferPtr:      Pointer to the buffer-array where the timestamp 
 *                             values shall be placed
 * @param[in]  BufferSize:     Size of the external buffer (number of entries)It should be the same 
 *                             size as the array pointed to by BufferPtr.
 * @param[in]  NotifyInterval: Notification interval (number of events). This parameter can not be
 *                             checked in a reasonable way,It should not be greater than BufferSize.
 *
 * @return none
 *
 */
/* SWS_Icu_00201 SWS_Icu_00098*/
void Icu_StartTimestamp(Icu_ChannelType Channel, Icu_ValueType * BufferPtr, uint16 BufferSize, 
                               uint16 NotifyInterval);

/**
 * @brief      This function read the timestamp index of the given Channel
 *
 * @param[in]  Channel: Numeric identifier of the ICU channel
 *
 * @return     Icu_IndexType Abstract return type to cover different microcontrollers.
 *
 */
/* SWS_Icu_00203 SWS_Icu_00100*/
Icu_IndexType Icu_GetTimestampIndex(Icu_ChannelType Channel);

/**
 * @brief      This function stops the timestamp measurement of the given Channel
 *
 * @param[in]  Channel: Numeric identifier of the ICU channel
 *
 * @return none
 *
 */
/* SWS_Icu_00202 SWS_Icu_00099*/
void Icu_StopTimestamp(Icu_ChannelType Channel);

#endif

#if (STD_ON == ICU_ENABLE_WAKEUP_API)
/**
 * @brief      This function (re-)enables the wakeup capability of the given ICU channel.
 *
 * @param[in]  Channel: Numeric identifier of the ICU channel
 *
 * @return none
 *
 */
/* SWS_Icu_00196 SWS_Icu_00097*/
void Icu_EnableWakeup(Icu_ChannelType Channel);
#endif

#if (STD_ON == ICU_WAKEUP_FUNCTIONALITY_API)
/**
 * @brief      Checks if a wakeup capable ICU channel is the source for a wakeup event and calls
 *             the ECU state manager service EcuM_SetWakeupEvent in case of a valid ICU channel
 *             wakeup event.
 *
 * @param[in]  WakeupSource: Informatin on wakeup source to be checked. The associated ICU
 *                           channel can be determined from configuration data.
 *
 * @return none
 *
 */
/* SWS_Icu_00358 SWS_Icu_00362*/
void Icu_CheckWakeup(EcuM_WakeupSourceType WakeupSource);
#endif


#if (STD_ON == ICU_DISABLE_WAKEUP_API)
/**
 * @brief      This function disables the wakeup capability of a single ICU Channel
 *
 * @param[in]  Channel: Logical number of the ICU Channel
 *
 * @return none
 *
 */
/* SWS_Icu_00195 SWS_Icu_00096*/
void Icu_DisableWakeup(Icu_ChannelType Channel);
#endif

#if (STD_ON == ICU_EDGE_COUNT_API)
/**
 * @brief      This function enables the counting of edges of the given Channel
 *
 * @param[in]  Channel: Numeric identifier of the ICU channel
 *
 * @return none
 *
 */
/* SWS_Icu_00205 SWS_Icu_00102*/
void Icu_EnableEdgeCount(Icu_ChannelType Channel);

/**
 * @brief      This function reads the number of counted edges
 *
 * @param[in]  Channel: Numeric identifier of the ICU channel
 *
 * @return Icu_EdgeNumberType Abstract return type to cover different microcontrollers.
 *
 */
/* SWS_Icu_00207 SWS_Icu_00104*/
Icu_EdgeNumberType Icu_GetEdgeNumbers(Icu_ChannelType Channel);

/**
 * @brief      This function resets the value of the counted edges to zero.
 *
 * @param[in]  Channel: Numeric identifier of the ICU channel
 *
 * @return none
 *
 */
/* SWS_Icu_00204 SWS_Icu_00101*/
void Icu_ResetEdgeCount(Icu_ChannelType Channel);

/**
 * @brief      This function disables the counting of edges of the given channel.
 *
 * @param[in]  Channel: Numeric identifier of the ICU channel
 *
 * @return none
 *
 */
/* SWS_Icu_00206 */
void Icu_DisableEdgeCount(Icu_ChannelType Channel);
#endif

#if (STD_ON == ICU_EDGE_DETECT_API)
/**
 * @brief      This function enables / re-enables the detection of edges of the given channel.
 *
 * @param[in]  Channel: Numeric identifier of the ICU channel
 *
 * @return none
 *
 */
/* SWS_Icu_00364 SWS_Icu_00369*/
void Icu_EnableEdgeDetection(Icu_ChannelType Channel);

/**
 * @brief      This function disables the detection of edges of the given channel.
 *
 * @param[in]  Channel: Numeric identifier of the ICU channel
 *
 * @return none
 *
 */
/* SWS_Icu_00377 SWS_Icu_00374*/
void Icu_DisableEdgeDetection(Icu_ChannelType Channel);
#endif

#if (STD_ON == ICU_SIGNAL_MEASUREMENT_API)
/**
 * @brief      This function starts the measurement of signals.
 *
 * @param[in]  Channel: Numeric identifier of the ICU channel
 *
 * @return none
 *
 */
/* SWS_Icu_00208 SWS_Icu_00142*/
void Icu_StartSignalMeasurement(Icu_ChannelType Channel);

/**
 * @brief      This function stops the measurement of signals of the given channel.
 *
 * @param[in]  Channel: Numeric identifier of the ICU channel
 *
 * @return none
 *
 */
/* SWS_Icu_00209 SWS_Icu_00145*/
void Icu_StopSignalMeasurement(Icu_ChannelType Channel);
#endif

#if (STD_ON == ICU_GET_TIMEELAPSED_API)
/**
 * @brief      This function reads the elapsed Signal Low Time for the given channel.
 *
 * @param[in]  Channel: Numeric identifier of the ICU channel
 *
 * @return elapsed time
 *
 */
/* SWS_Icu_00210 SWS_Icu_00105*/
Icu_ValueType Icu_GetTimeElapsed(Icu_ChannelType Channel);
#endif

#if (STD_ON == ICU_GET_DUTY_CYCLE_VALUES_API)
/**
 * @brief      This function reads the coherent active time and period time for the given 
 *             ICU Channel.
 *
 * @param[in]  Channel:          Numeric identifier of the ICU channel
 * @param[out] DutyCycleValues : Pointer to a buffer where the results (high time 
 *                               and period time) shall be placed
 *
 * @return none
 *
 */
/* SWS_Icu_00211 SWS_Icu_00106*/
void Icu_GetDutyCycleValues(Icu_ChannelType Channel, Icu_DutyCycleType* DutyCycleValues);
#endif

#if (STD_ON == ICU_GET_VERSION_INFO_API)
/**
 * @brief      This function returns the version information of this module.
 *
 * @param[out] versioninfo : Pointer to where to store the version information of this module.
 *
 * @return none
 *
 */
/* SWS_Icu_00212 SWS_Icu_00218*/
void Icu_GetVersionInfo(Std_VersionInfoType * const versioninfo);
#endif

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Icu  */
/** @} end of group Icu_Module */

#endif  /* ICU_H */

