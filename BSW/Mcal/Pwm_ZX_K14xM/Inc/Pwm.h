/*************************************************************************************/
/**
 * @file      : Pwm.h
 * @brief     : Pwm AUTOSAR level header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 *************************************************************************************/
#ifndef PWM_H
#define PWM_H

/** @addtogroup  Pwm_Module
 *  @{
 */

/** @addtogroup Pwm 
 *  @brief Pwm AUTOSAR level
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Pwm_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
#define PWM_INSTANCE_ID                 121U
#define PWM_VENDOR_ID                   0x00B3U
#define PWM_AR_RELEASE_MAJOR_VERSION    4U
#define PWM_AR_RELEASE_MINOR_VERSION    6U
#define PWM_AR_RELEASE_REVISION_VERSION 0U
#define PWM_SW_MAJOR_VERSION            1U
#define PWM_SW_MINOR_VERSION            2U
#define PWM_SW_PATCH_VERSION            1U

/* Check if current file and Pwm_Types.h are the same vendor */
#if (PWM_VENDOR_ID != PWM_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Pwm.h and Pwm_Types.h are different"
#endif

/* Check if current file and Pwm_Types.h are the same Autosar version */
#if ((PWM_AR_RELEASE_MAJOR_VERSION    != PWM_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_AR_RELEASE_MINOR_VERSION    != PWM_TYPES_H_AR_RELEASE_MINOR_VERSION) || \
     (PWM_AR_RELEASE_REVISION_VERSION != PWM_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Pwm.h and Pwm_Types.h are different"
#endif

/* Check if current file and Pwm_Types.h are the same Software version */
#if ((PWM_SW_MAJOR_VERSION != PWM_TYPES_H_SW_MAJOR_VERSION) || \
     (PWM_SW_MINOR_VERSION != PWM_TYPES_H_SW_MINOR_VERSION) || \
     (PWM_SW_PATCH_VERSION != PWM_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Pwm.h and Pwm_Types.h are different"
#endif



/**
* @brief            100% duty cycle
*/
#define PWM_DUTY_CYCLE_100                          ((uint16)0x8000U)

/**
* @brief            API Pwm_Init service called with wrong parameter
*/
#define PWM_E_INIT_FAILED                           (0x10U)

/**
* @brief            API service used without module initialization
*/
#define PWM_E_UNINIT                                (0x11U)

/**
* @brief            API service used with an invalid channel Identifier
*/
#define PWM_E_PARAM_CHANNEL                         (0x12U)

/**
* @brief            Usage of unauthorized PWM service on PWM channel configured a fixed period
*/
#define PWM_E_PERIOD_UNCHANGEABLE                   (0x13U)

/**
* @brief            API Pwm_Init service called while the PWM driver has already been initialized
*/
#define PWM_E_ALREADY_INITIALIZED                   (0x14U)

/**
* @brief            API Pwm_GetVersionInfo is called with a NULL parameter
*/
#define PWM_E_PARAM_POINTER                         (0x15U)

/**
* @brief            API Pwm_SetPowerState is called while the PWM module is still in use
*/
#define PWM_E_NOT_DISENGAGED                        (0x16U)

/**
* @brief            The requested power state is not supported by the PWM module
*/
#define PWM_E_POWER_STATE_NOT_SUPPORTED             (0x17U)

/**
* @brief            The requested power state is not reachable from the current one
*/
#define PWM_E_TRANSITION_NOT_POSSIBLE               (0x18U)

/**
* @brief            API Pwm_SetPowerState has been called without having called the API 
*                   Pwm_PreparePowerState before.
*/
#define PWM_E_PERIPHERAL_NOT_PREPARED               (0x19U)

/**
* @brief            Pwm_SetPeriodAndDuty called with invalid period range
*/
#define PWM_E_PERIODVALUE                           (0x1AU)

/**
* @brief            Invalid polarity selected for edge notification
*/
#define PWM_E_PARAM_NOTIFICATION                    (0x30U)

/**
* @brief            NULL_PTR function is configured as notification callback
*/
#define PWM_E_PARAM_NOTIFICATION_NULL               (0x31U)

/**
* @brief            Pwm_SetDutyCycle or Pwm_SetPeriodAndDuty called with invalid duty cycle range
*/
#define PWM_E_DUTYCYCLE_RANGE                       (0x32U)

/**
* @brief            EB generated Pwm channel configuration structure error 
*/
#define PWM_E_CHANNEL_CONFIGURATION_STRUCTURE       (0x34U)

/**
* @brief            EB generated Pwm module configuration structure error
*/
#define PWM_E_MODULE_CONFIGURATION_STRUCTURE        (0x35U)

/**
* @brief            Generated when the module id is more than the number of module that supported by
*                   this platform
*/
#define PWM_E_PARAM_INSTANCE                        (0x36U)

/**
* @brief            Generated when requested phase shift value greater than 0x4000(50%) or equals 0
*/
#define PWM_E_PARAM_PHASESHIFT_RANGE                (0x3AU)

/**
* @brief            Generated when bit mask is not compatible with hardware register
* @details
*/
#define PWM_E_TRIGGER_MASK                          (0x3DU)

/**
* @brief            Generated when the logical channel ID setting is invalid
*/
#define PWM_E_PARAM_CONFIG                          (0x40U)

/**
* @brief            Generated when the configured dead time ticks value is not valid
*/
#define PWM_E_DEADTIME_RANGE                        (0x41U)

/**
* @brief            API service ID of Pwm_Init function
*/
#define PWM_SID_INIT                                (0x00U)

/**
* @brief            API service ID of Pwm_DeInit function
*/
#define PWM_SID_DEINIT                              (0x01U)

/**
* @brief            API service ID of Pwm_SetDutyCycle function
*/
#define PWM_SID_SET_DUTYCYCLE                       (0x02U)

/**
* @brief            API service ID of Pwm_SetPeriodAndDuty function
*/
#define PWM_SID_SET_PERIODANDDUTY                   (0x03U)

/**
* @brief            API service ID of Pwm_SetOutputToIdle function
*/
#define PWM_SID_SET_OUTPUTTOIDLE                    (0x04U)

/**
* @brief            API service ID of Pwm_GetOutputState function
*/
#define PWM_SID_GET_OUTPUTSTATE                     (0x05U)

/**
* @brief            API service ID of Pwm_DisableNotification function
*/
#define PWM_SID_DISABLE_NOTIFICATION                (0x06U)

/**
* @brief            API service ID of Pwm_EnableNotification function
*/
#define PWM_SID_ENABLE_NOTIFICATION                 (0x07U)

/**
* @brief            API service ID of Pwm_GetVersionInfo function
*/
#define PWM_SID_GET_VERSIONINFO                     (0x08U)

/**
* @brief            API service ID of Pwm_SetPowerState function
*/
#define PWM_SID_SET_POWERSTATE                      (0x09U)

/**
* @brief            API service ID of Pwm_GetCurrentPowerState function
*/
#define PWM_SID_GET_CURRENTPOWERSTATE               (0x0AU)

/**
* @brief            API service ID of Pwm_GetTargetPowerState function
*/
#define PWM_SID_GET_TARGETPOWERSTATE                (0x0BU)

/**
* @brief            API service ID of Pwm_PreparePowerState function
*/
#define PWM_SID_PREPARE_POWERSTATE                  (0x0CU)

/**
* @brief            API service ID of Pwm_GetChannelDutyCycle function
*/
#define PWM_SID_GET_CHANNEL_DUTYCYCLE               (0x20U)

/**
* @brief            API service ID of Pwm_ForceOutputToLowLevel function
*/
#define PWM_SID_FORCE_OUTPUT_TOLOWLEVEL             (0x21U)

/**
* @brief            API service ID of Pwm_SyncUpdate function
*/
#define PWM_SID_SYNCUPDATE                          (0x28U)

/**
* @brief            API service ID of Pwm_WritePeriodAndDutyToBuffer function
*/
#define PWM_SID_WRITER_PERIODANDDUTY_TOBUFFER       (0x29U)

/**
* @brief            API service ID of Pwm_WriteDutyCycleToBuffer function
*/
#define PWM_SID_WRITER_DUTYCYCLE_TOBUFFER           (0x2AU)

/**
* @brief            API service ID of Pwm_SetChannelDeadTimeTicks function
*/
#define PWM_SID_SET_CHANNELDEADTIME                 (0x2BU)

/**
* @brief            API service ID of Pwm_SetPhaseShiftTicks function
*/
#define PWM_SID_SET_PHASESHIFT                      (0x2CU)

/**
* @brief            API service ID of Pwm_WritePhaseShiftTicksToBuffer function
*/
#define PWM_SID_WRITER_PHASESHIFT_TOBUFFER          (0x2DU)

/**
* @brief            API service ID of Pwm_EnableTriggerOutput function
*/
#define PWM_SID_ENABLE_TRIGGER                      (0x2EU)

/**
* @brief            API service ID of Pwm_DisableTriggerOutput function
*/
#define PWM_SID_DISABLE_TRIGGER                     (0x2FU)

/**
* @brief            API service ID of Pwm_MaskOutputs function
*/
#define PWM_SID_MASKOUTPUT                          (0x32U)

/**
* @brief            API service ID of Pwm_UnMaskOutputs function
*/
#define PWM_SID_UNMASKOUTPUT                        (0x33U)

/**
* @brief            API service ID of Pwm_SetDutyPhaseShiftTicks function
*/
#define PWM_SID_SET_DUTYPHASESHIFT                  (0x37U)

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#if (PWM_PRECOMPILE_SUPPORT == STD_ON)
    #define PWM_START_SEC_CONFIG_DATA_PTR
    #include "Pwm_MemMap.h"
extern const Pwm_ConfigType * const Pwm_PreDefinedConfigPtr[PWM_MAX_PARTITIONS];
    #define PWM_STOP_SEC_CONFIG_DATA_PTR
    #include "Pwm_MemMap.h"
#else
    #define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Pwm_MemMap.h"

PWM_CONFIG_EXT

    #define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Pwm_MemMap.h"
#endif /* (PWM_PRECOMPILE_SUPPORT == STD_ON) */

/** @} end of group Global_VariableDeclaration */

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/**
* @brief        Service for PWM initialization.
*
* @param[in]    ConfigPtr       Pointer to configuration set 
*
* @return       void
*/
void Pwm_Init(const Pwm_ConfigType * ConfigPtr);

#if (PWM_DE_INIT_API == STD_ON)
/**
* @brief        Service for PWM De-Initialization.
*
* @param[in]    None
*
* @return       void
*/
void Pwm_DeInit(void);
#endif /* PWM_DE_INIT_API */

#if (PWM_SET_DUTY_CYCLE_API == STD_ON)
/**
* @brief        Service sets the duty cycle of the PWM channel.
*
* @param[in]    ChannelNumber   Numeric identifier of the PWM
* @param[in]    DutyCycle       Min=0x0000 Max=0x8000
*
* @return       void
*/
void Pwm_SetDutyCycle(Pwm_ChannelType ChannelNumber, uint16 DutyCycle);
#endif /* PWM_SET_DUTY_CYCLE_API */

#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
/**
* @brief        Service sets the period and the duty cycle of a PWM channel
*
* @param[in]    ChannelNumber   Numeric identifier of the PWM
* @param[in]    Period          Period of the PWM signal
* @param[in]    DutyCycle       Min=0x0000 Max=0x8000
*
* @return       void
*/
void Pwm_SetPeriodAndDuty(Pwm_ChannelType ChannelNumber, Pwm_PeriodType Period,
                        uint16 DutyCycle);
#endif /* PWM_SET_PERIOD_AND_DUTY_API */

#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
/**
* @brief        Service sets the PWM output to the configured Idle state.
*
* @param[in]    ChannelNumber   Numeric identifier of the PWM
*
* @return       void
*
*/
void Pwm_SetOutputToIdle(Pwm_ChannelType ChannelNumber);
#endif /* PWM_SET_OUTPUT_TO_IDLE_API */

#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
/**
* @brief        Service to read the internal state of the PWM output signal.
*
* @param[in]    ChannelNumber   Numeric identifier of the PWM
*
* @return       Pwm_OutputStateType
*                 - PWM_LOW              The PWM output state is low
*                 - PWM_HIGH             The PWM output state is high
*/
Pwm_OutputStateType Pwm_GetOutputState(Pwm_ChannelType ChannelNumber);
#endif /* PWM_GET_OUTPUT_STATE_API */

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief        Service to disable the PWM signal edge notification.
*
* @param[in]    ChannelNumber   Numeric identifier of the PWM
*
* @return       void
*/
void Pwm_DisableNotification(Pwm_ChannelType ChannelNumber);
/**
* @brief        Service to enable the PWM signal edge notification according to notification 
*               parameter.
*
* @param[in]    ChannelNumber   Numeric identifier of the PWM
* @param[in]    Notification    Type of notification
*                 - PWM_RISING_EDGE
*                 - PWM_FALLING_EDGE
*                 - PWM_BOTH_EDGES
*
* @return       void
*/
void Pwm_EnableNotification(Pwm_ChannelType ChannelNumber, Pwm_EdgeNotificationType Notification);
#endif /* PWM_NOTIFICATION_SUPPORTED */

#if (PWM_VERSION_INFO_API == STD_ON)
/**
* @brief        Service returns the version information of this module.
*
* @param[out]   versioninfo     Pointer to where to store the version information of this module.
*
* @return       void
*/
void Pwm_GetVersionInfo(Std_VersionInfoType * versioninfo);
#endif /* PWM_VERSION_INFO_API */

#if (PWM_GET_CHANNEL_DUTYCYCLE_API == STD_ON)
/**
* @brief        This function is used to get current duty cycle of the channel, When the channel
*               status is running.
* @details      The current duty cycle is obtained, and the previous setting value must take effect.
*               The high and low levels of the duty cycle are determined by the PWM polarity of the 
*               channel.
*
* @param[in]    ChannelNumber   Pwm logic channel id
*
* @return       uint16          DutyCycle of the specified logic channel
*/
uint16 Pwm_GetChannelDutyCycle(Pwm_ChannelType ChannelNumber);
#endif /* PWM_GET_CHANNEL_DUTYCYCLE_API */

#if (PWM_FORCE_OUTPUT_TO_LOW_LEVEL_API == STD_ON)
/**
* @brief        This function is used to enable or disable the forcing of the output of a given
*               channel to logic 0.
*
* @param[in]    ChannelNumber   Pwm logic channel id
* @param[in]    ForceEnable     If the output of the channel will be forced to zero logic or not
* @return       void
*/
void Pwm_ForceOutputToLowLevel(Pwm_ChannelType ChannelNumber, boolean ForceEnable);
#endif /* PWM_FORCE_OUTPUT_TO_LOW_LEVEL_API */

#if (PWM_SET_CHANNEL_DEAD_TIME_TICKS_API == STD_ON)
/**
* @brief        This function is used to set the deadtime ticks for Pwm logic channel specified
*
* @param[in]    ChannelNumber       Pwm logic channel id
* @param[in]    DeadTimeTicks       Dead Time ticks
*
* @return       void
*/
void Pwm_SetChannelDeadTimeTicks(Pwm_ChannelType ChannelNumber, uint16 DeadTimeTicks);
#endif /* PWM_SET_CHANNEL_DEAD_TIME_TICKS_API */

#if (PWM_SYNC_UPDATE_API == STD_ON)
    #if (PWM_WRITE_DUTY_CYCLE_TO_BUFFER_API == STD_ON)
/**
* @brief        This function set the duty cycle value to the shadow registers of Pwm physical module,
*               and they will not active right now but trigged by a sync signal.
* @details      Generating synchronization signals by using Pwm_SyncUpdate function.
*               This function should not be mixed Pwm_SetDutyCycle and Pwm_SetPeriodAndDuty.
*
* @param[in]    ChannelNumber       Pwm logic channel id
* @param[in]    DutyCycle           Pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
*
* @return       void
*/
void Pwm_WriteDutyCycleToBuffer(Pwm_ChannelType ChannelNumber, uint16 DutyCycle);
    #endif /* PWM_WRITE_DUTY_CYCLE_TO_BUFFER_API */

    #if (PWM_WRITE_PERIOD_AND_DUTY_TO_BUFFER_API == STD_ON)
/**
* @brief        This function set the period and duty cycle value to the shadow registers of Pwm 
*               physical module, and they will not active right now but trigged by a sync signal
* @details      Generating synchronization signals by using Pwm_SyncUpdate function.
*               This function should not be mixed Pwm_SetDutyCycle and Pwm_SetPeriodAndDuty.
*
* @param[in]    ChannelNumber    Pwm logic channel id
* @param[in]    Period           Pwm Period value
* @param[in]    DutyCycle        Pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
*
* @return       void
*/
void Pwm_WritePeriodAndDutyToBuffer(Pwm_ChannelType ChannelNumber, Pwm_PeriodType Period,
                                    uint16 DutyCycle);
    #endif /* PWM_WRITE_PERIOD_AND_DUTY_TO_BUFFER_API */

    #if (PWM_WRITE_PHASE_SHIFT_TICKS_TO_BUFFER_API == STD_ON)
/**
* @brief        This function is used to set the phase shift scale and force the duty cycle to 50%. 
*               Set the values to the shadow registers of the Pwm physical module, and they will now 
*               be inactive and triggered by a synchronization signal.
* @details      Generating synchronization signals by using Pwm_SyncUpdate function.
*               This function should not be mixed Pwm_SetDutyCycle and Pwm_SetPeriodAndDuty.
*
* @param[in]    ChannelNumber        Pwm logic channel Id specified
* @param[in]    Period               Pwm period value
* @param[in]    PhaseShiftTicks      Phase shift ticks
*
* @return       void
*
*/
void Pwm_WritePhaseShiftTicksToBuffer(Pwm_ChannelType ChannelNumber, Pwm_PeriodType Period,
                                        uint16 PhaseShiftTicks);
    #endif /* PWM_WRITE_PHASE_SHIFT_TICKS_TO_BUFFER_API */
/**
* @brief        This function can generate a synchronization signal to update the shadow register 
*               synchronized by the physical pwm module.
* @details      The update is not immediate, but at the end of the period
*
* @param[in]    ModuleId      PWM HW module ID.
*
* @return       void
*/
void Pwm_SyncUpdate(uint8 ModuleId);

#endif /* PWM_SYNC_UPDATE_API */

#if (PWM_SET_PHASE_SHIFT_TICKS_API == STD_ON)
/**
* @brief        This function is used to set phase shift ticks and also force duty cycle to 50%
*
* @param[in]    ChannelNumber           Pwm logic channel Id in the configuration
* @param[in]    Period                  Pwm period value
* @param[in]    PhaseShiftTicks         Phase shift ticks 
*
* @return       void
*/
void Pwm_SetPhaseShiftTicks(Pwm_ChannelType ChannelNumber, Pwm_PeriodType Period,
                            uint16 PhaseShiftTicks);
#endif /* PWM_SET_PHASE_SHIFT_TICKS_API */

#if (PWM_SET_DUTY_AND_PHASE_SHIFT_TICKS_API == STD_ON)
/**
* @brief        This function is used to set phase shift and duty cycle value, and specify update or not.
*
* @param[in]    ChannelNumber           Pwm logic channel Id in the configuration
* @param[in]    DutyCycle               Pwm duty cycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    PhaseShiftTicks         Phase shift ticks
* @param[in]    boolean                 SyncUpdate
*                                        - TRUE    Update settings at the end of the period
*                                        - FALSE   Update is triggered by a synchronization signal 
*                                                  by using the function Pwm_SyncUpdate
*
* @return       void
*/
void Pwm_SetDutyPhaseShiftTicks(Pwm_ChannelType ChannelNumber, uint16 DutyCycle,
                                uint16 PhaseShiftTicks, boolean SyncUpdate);
#endif /* PWM_SET_DUTY_AND_PHASE_SHIFT_TICKS_API */

#if (PWM_ENABLE_TRIGGER_OUTPUT_API == STD_ON)
/**
* @brief        This function is used to enable trigger generation for source specified
*
* @param[in]    ModuleId      PWM HW module ID.
* @param[in]    TriggerMask   Bit mask will be set to enable trigger with corresponding sources.
*
* @return       void
*
*/
void Pwm_EnableTriggerOutput(uint8 ModuleId, uint16 TriggerMask);
#endif /* PWM_ENABLE_TRIGGER_OUTPUT_API */

#if (PWM_DISABLE_TRIGGER_OUTPUT_API == STD_ON)
/**
* @brief        This function is used to disable trigger generation for specific source
*
* @param[in]    ModuleId      PWM HW module ID.
* @param[in]    TriggerMask   Bit mask will be cleared to disable trigger with corresponding sources.
*
* @return       void
*/
void Pwm_DisableTriggerOutput(uint8 ModuleId, uint16 TriggerMask);
#endif /* PWM_DISABLE_TRIGGER_OUTPUT_API */

#if (PWM_ENABLE_MASKING_OPERATIONS == STD_ON)
/**
* @brief        This function is used to force channels output to their inactive state
*
* @param[in]    ModuleId      PWM HW module ID.
* @param[in]    ChannelMask   Bit mask will be set to inactive corresponding channels.
*
* @return       void
*/
void Pwm_MaskOutputs(uint8 ModuleId, uint8 ChannelMask);

/**
* @brief        This function is to active channels output to normal operation state
*
* @param[in]    ModuleId      PWM HW module ID.
* @param[in]    ChannelMask   Bit mask will be cleared to active the output of corresponding channel.
*
* @return       void
*/
void Pwm_UnMaskOutputs(uint8 ModuleId, uint8 ChannelMask);
#endif /* PWM_ENABLE_MASKING_OPERATIONS */

#if (PWM_LOW_POWER_STATE_SUPPORTED == STD_ON)
/**
* @brief        This API configures the Pwm module so that it enters the already prepared power 
*               state, chosen between a predefined set of configured ones.
*
* @param[out]   Result
*                 - PWM_SERVICE_ACCEPTED   Power state change executed.
*                 - PWM_NOT_INIT           PWM Module not initialized.
*                 - PWM_SEQUENCE_ERROR     wrong API call sequence.
*                 - PWM_HW_FAILURE         the HW module has a failure which prevents it to enter
*                                          the required power state.
*
* @return       Std_ReturnType
*                 - E_OK                   Mode changed
*                 - E_NOT_OK               request rejected
*
*/
Std_ReturnType Pwm_SetPowerState(Pwm_PowerStateRequestResultType * Result);
/**
* @brief        This API returns the current power state of the PWM HW unit.
*
* @param[out]   CurrentPowerState    The current power mode of the PWM HW Unit is returned in 
*                                    this parameter
* @param[out]   Result
*                 - PWM_SERVICE_ACCEPTED   Current power mode was returned.
*                 - PWM_NOT_INIT           PWM Module not initialized.
*
* @return       Std_ReturnType
*                 - E_OK                   Mode could be read
*                 - E_NOT_OK               Service is rejected
*
*/
Std_ReturnType Pwm_GetCurrentPowerState(Pwm_PowerStateType * CurrentPowerState,
                                        Pwm_PowerStateRequestResultType * Result);
/**
* @brief        This API returns the Target power state of the PWM HW unit.
*
* @param[out]   TargetPowerState     The Target power mode of the PWM HW Unit is returned in this 
*                                    parameter
* @param[out]   Result
*                 - PWM_SERVICE_ACCEPTED   Target power mode was returned.
*                 - PWM_NOT_INIT           PWM Module not initialized.
*
* @return       Std_ReturnType
*                 - E_OK                   Mode could be read
*                 - E_NOT_OK               Service is rejected
*
*/
Std_ReturnType Pwm_GetTargetPowerState(Pwm_PowerStateType * TargetPowerState,
                                       Pwm_PowerStateRequestResultType * Result);
/**
* @brief        This API starts the needed process to allow the PWM HW module to enter the 
*               requested power state.
*
* @param[in]    PowerState      The target power state intended to be attained
* @param[out]   Result
*                 - PWM_SERVICE_ACCEPTED      PWM Module power state preparation was started.
*                 - PWM_NOT_INIT              PWM Module not initialized.
*                 - PWM_SEQUENCE_ERROR        wrong API call sequence (Current Power State = Target 
*                                             Power State).
*                 - PWM_POWER_STATE_NOT_SUPP  PWM Module does not support the requested power state.
*                 - PWM_TRANS_NOT_POSSIBLE    PWM Module cannot transition directly from the current
*                                             power state to the requested power state or the HW 
*                                             peripheral is still busy.
*
* @return       Std_ReturnType
*                 - E_OK                      Preparation process started
*                 - E_NOT_OK                  Service is rejected
*
*/
Std_ReturnType Pwm_PreparePowerState(Pwm_PowerStateType PowerState,
                                     Pwm_PowerStateRequestResultType * Result);
#endif /* PWM_LOW_POWER_STATE_SUPPORTED */

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
/** @} end of group Public_FunctionDeclaration */
#ifdef __cplusplus
}
#endif
/** @} end of group Pwm */

/** @} end of group Pwm_Module */

#endif   /* PWM_H */
