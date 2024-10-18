/*************************************************************************************/
/**
 * @file      : Pwm_Drvw.h
 * @brief     : AUTOSAR Pwm middle level driver header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 *************************************************************************************/
#ifndef PWM_DRVW_H
#define PWM_DRVW_H

/** @addtogroup  Pwm_Module
 *  @{
 */

/** @addtogroup Pwm_Drvw
 *  @brief Pwm middle level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Pwm_Drvw_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
#define PWM_DRVW_H_VENDOR_ID                   0x00B3U
#define PWM_DRVW_H_AR_RELEASE_MAJOR_VERSION    4U
#define PWM_DRVW_H_AR_RELEASE_MINOR_VERSION    6U
#define PWM_DRVW_H_AR_RELEASE_REVISION_VERSION 0U
#define PWM_DRVW_H_SW_MAJOR_VERSION            1U
#define PWM_DRVW_H_SW_MINOR_VERSION            2U
#define PWM_DRVW_H_SW_PATCH_VERSION            1U

/* Check if header file and Pwm_Drvw_Types header file are of the same vendor */
#if (PWM_DRVW_H_VENDOR_ID != PWM_DRVW_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Pwm_Drvw.h and Pwm_Drvw_Types.h are different"
#endif

/* Check if header file and Pwm_Drvw_Types header file are of the same AUTOSAR version */
#if ((PWM_DRVW_H_AR_RELEASE_MAJOR_VERSION    != PWM_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_DRVW_H_AR_RELEASE_MINOR_VERSION    != PWM_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION) || \
     (PWM_DRVW_H_AR_RELEASE_REVISION_VERSION != PWM_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Pwm_Drvw.h and Pwm_Drvw_Types.h are different"
#endif

/* Check if header file and Pwm_Drvw_Types header file are of the same software version */
#if ((PWM_DRVW_H_SW_MAJOR_VERSION != PWM_DRVW_TYPES_H_SW_MAJOR_VERSION) || \
     (PWM_DRVW_H_SW_MINOR_VERSION != PWM_DRVW_TYPES_H_SW_MINOR_VERSION) || \
     (PWM_DRVW_H_SW_PATCH_VERSION != PWM_DRVW_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Pwm_Drvw.h and Pwm_Drvw_Types.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"
/**
 * @brief   Export Post-Build configurations.
 */
PWM_DRVW_CONFIG_EXT

#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"
/** @} end of group Global_VariableDeclaration */

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/**
* @brief        This function is used to Init the corresponding physical pwm module.
*
* @param[in]    HwCfgPtr       Pointer to Pwm module configuration structure
*
* @return       void
*/
void Pwm_Drvw_Init(const Pwm_Drvw_HwConfigType * const HwCfgPtr);

/**
* @brief        This function is used to set default duty cycle to corresponding physical channel.
*
* @param[in]    DutyCyclePu    Duty cycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    ChnConfigPtr   Pointer to Pwm channel configuration structure
*
* @return       void
*/
void Pwm_Drvw_SetDefaultDutyCycle(uint16 DutyCyclePu,
                                    const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr);

/**
* @brief        This function is used to update the default dutycycle to physical reigster.
*
* @param[in]    ModuleId       Id to Pwm module to be synchronized 
* @param[in]    HwType         HW module type
*
* @return       void
*/
void Pwm_Drvw_SyncDefaultDutyCycle(uint8 ModuleId, Pwm_Drvw_HwType HwType);

/**
* @brief        This function is used to start the counters of the corresponding physical pwm module
*
* @param[in]    HwCfgPtr       Pointer to Pwm module configuration structure
*
* @return       void
*/
void Pwm_Drvw_StartInstance(const Pwm_Drvw_HwConfigType * const HwCfgPtr);

/**
* @brief        This function is used to init the idle output state of Hardware.
*
* @param[in]    State The output idle state of the hardware channel 
* @param[in]    ChnConfigPtr Pointer to Pwm channel configuration structure
*
* @return       void
*/
void Pwm_Drvw_InitIdleState(Pwm_Drvw_OutputStateType State,
                                    const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr);

#if (PWM_DRVW_DE_INIT_API == STD_ON)
/**
* @brief        This function is used to deinitialize the corresponding pwm physical module.
*
* @param[in]    HwCfgPtr       Pointer to PWM module configuration structure
*
* @return       void
*/
void Pwm_Drvw_DeInit(const Pwm_Drvw_HwConfigType * const HwCfgPtr);
#endif /* PWM_DRVW_DE_INIT_API */

#if (PWM_DRVW_SET_DUTY_CYCLE_API == STD_ON)
/**
* @brief        This function is used to set the duty cycle to corresponding pwm channel 
*
* @param[in]    DutyCyclePu      Duty cycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    ChnConfigPtr      Pointer to Pwm channel configuration structure
*
* @return       Std_ReturnType
* @retval       E_OK: Set duty cycle successfully.
* @retval       E_NOT_OK: Set duty cycle failed. 
*
*/
Std_ReturnType Pwm_Drvw_SetDutyCycle(uint16 DutyCyclePu,
                                    const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr);
#endif /* PWM_DRVW_SET_DUTY_CYCLE_API */

#if (PWM_DRVW_SET_PERIOD_AND_DUTY_API == STD_ON)
/**
* @brief      This function is used to set Period and Duty  for the corresponding PwmChannel
*
* @param[in]    Period         Period ticks value for this channel
* @param[in]    DutyCyclePu    Duty cycle pu value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    ChnConfigPtr   Pointer to PWM channel configuration structure
*
* @return       Std_ReturnType
* @retval       E_OK: Set duty cycle successfully.
* @retval       E_NOT_OK: Set duty cycle failed.
*
*/
Std_ReturnType Pwm_Drvw_SetPeriodAndDuty(Pwm_Drvw_PeriodType Period, uint16 DutyCyclePu,
                                    const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr);
#endif /* PWM_DRVW_SET_PERIOD_AND_DUTY_API */

#if (PWM_DRVW_SET_OUTPUT_TO_IDLE_API == STD_ON)
/**
* @brief        This function is used to set Output To Idle function for the corresponding PwmChannel
*
* @param[in]    ChnConfigPtr       Pointer to PWM channel configuration structure
*
* @return       void
*
*/
void Pwm_Drvw_SetOutputToIdle(const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr);
#endif /* PWM_DRVW_SET_OUTPUT_TO_IDLE_API */

#if (PWM_DRVW_GET_OUTPUT_STATE_API == STD_ON)
/**
* @brief        This function is used to Get Output State for the corresponding PwmChannel
*
* @param[in]    ChnConfigPtr        Pointer to PWM channel configuration structure
*
* @return       Pwm_Drvw_OutputStateType
* @retval       HIGH: Current output state is high
* @retval       LOW: Current output state is low
*
*/
Pwm_Drvw_OutputStateType Pwm_Drvw_GetOutputState(
                                    const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr);
#endif /* PWM_DRVW_GET_OUTPUT_STATE_API */

#if (PWM_DRVW_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief      This function is used to DisableNotification for the corresponding PwmChannel
*
* @param[in]    ChnConfigPtr       Pointer to PWM channel configuration structure
*
* @return       void
*
*/
void Pwm_Drvw_DisableNotification(const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr);

/**
* @brief      This function is used to EnableNotification for the corresponding  PwmChannel
*
* @param[in]    Notification       Notification edge type to be enabled
* @param[in]    ChnConfigPtr       Pointer to PWM channel configuration structure
*
* @return       void
*
*/
void Pwm_Drvw_EnableNotification(Pwm_Drvw_EdgeNotificationType Notification,
                                    const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr);

/**
* @brief        This feature will check whether the current channel supports the selected 
*               notification edge type.
*
* @param[in]    Notification       Notification edge type to be enabled
* @param[in]    ChnConfigPtr       Pointer to PWM channel configuration structure
*
* @return       Std_ReturnType  
* @retval       E_NOT_OK            The selected notification edge type is not supported.
* @retval       E_OK                The selected notification edge type is supported.
*
*/
Std_ReturnType Pwm_Drvw_CheckEdgeNotificationType(Pwm_Drvw_EdgeNotificationType Notification,
                                    const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr);

#endif /* PWM_DRVW_NOTIFICATION_SUPPORTED */

#if (PWM_DRVW_GET_CHANNEL_DUTYCYCLE_API == STD_ON)
/**
* @brief        This function is used to get current duty cycle of the channel 
*
* @param[in]    ChnConfigPtr    Pointer to PWM channel configuration structure
*
* @return       uint16          DutyCyclePu of the specified logic channel
*/
uint16 Pwm_Drvw_GetChannelDutyCycle(const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr);
#endif /* PWM_DRVW_GET_CHANNEL_DUTYCYCLE_API */

#if (PWM_DRVW_FORCE_OUTPUT_TO_LOW_LEVEL_API == STD_ON)
/**
* @brief        This function is used to ForceOutputToLowLevel function.
*
* @param[in]    Force              Flag to state if force to zero should be applied or not
* @param[in]    ChnConfigPtr       Pointer to PWM channel configuration structure
*
* @return       void
*
*/
void Pwm_Drvw_ForceOutputToLowLevel(boolean Force,
                                    const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr);
#endif /* PWM_DRVW_FORCE_OUTPUT_TO_LOW_LEVEL_API */

#if (PWM_DRVW_SET_CHANNEL_DEAD_TIME_TICKS_API == STD_ON)
/**
* @brief        This function is used to update the deadtime ticks at runtime for Pwm channels.     
*
* @param[in]    DeadTimeTicks       dead Time value
* @param[in]    ChnConfigPtr        Pointer to PWM channel configuration structure
*
* @return       Std_ReturnType
* @retval       E_NOT_OK            Deadtime ticks is invalid
* @retval       E_OK                Deadtime ticks is valid
*
*/
Std_ReturnType Pwm_Drvw_SetChannelDeadTimeTicks(uint16 DeadTimeTicks,
                                    const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr);

#endif /* PWM_DRVW_SET_CHANNEL_DEAD_TIME_TICKS_API */

#if (PWM_DRVW_SYNC_UPDATE_API == STD_ON)
    #if (PWM_DRVW_WRITE_DUTY_CYCLE_TO_BUFFER_API == STD_ON)
/**
* @brief        This function is used to write dutycycle to buffer register.
*
* @param[in]    DutyCyclePu      Duty cycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    ChnConfigPtr     Pointer to PWM channel configuration structure
*
* @return       Std_ReturnType
* @retval       E_NOT_OK            The Idle state is not ready
* @retval       E_OK                The Idle state is ready
*
*/
Std_ReturnType Pwm_Drvw_WriteDutyCycleToBuffer(uint16 DutyCyclePu,
                                    const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr);
    #endif /* PWM_DRVW_WRITE_DUTY_CYCLE_TO_BUFFER_API */

    #if (PWM_DRVW_WRITE_PERIOD_AND_DUTY_TO_BUFFER_API == STD_ON)
/**
* @brief        This function is used to write period and dutycycle to buffer register
*
* @param[in]    Period           Period value for this channel
* @param[in]    DutyCyclePu      Duty cycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    ChnConfigPtr     Pointer to PWM channel configuration structure
*
* @return       Std_ReturnType
* @retval       E_OK: Set duty cycle successfully.
* @retval       E_NOT_OK: Set duty cycle failed.
*
*/
Std_ReturnType Pwm_Drvw_WritePeriodAndDutyToBuffer(Pwm_Drvw_PeriodType Period, uint16 DutyCyclePu,
                                    const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr);
    #endif /* PWM_DRVW_WRITE_PERIOD_AND_DUTY_TO_BUFFER_API */

    #if (PWM_DRVW_WRITE_PHASE_SHIFT_TICKS_TO_BUFFER_API == STD_ON)
/**
* @brief        This function set phase shift value and also force duty cycle to 50%. The output 
*               will take effect after Pwm_SyncUpdate be called.
*
* @param[in]    Period             Period value for this channel
* @param[in]    PhaseShiftTicks    Phase shift ticks value
* @param[in]    ChnConfigPtr       Pointer to PWM channel configuration structure
*
* @return       void
*
*/
void Pwm_Drvw_WritePhaseShiftTicksToBuffer(uint16 Period, uint16 PhaseShiftTicks,
                                    const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr);
    #endif /* PWM_DRVW_WRITE_PHASE_SHIFT_TICKS_TO_BUFFER_API */

/**
* @brief        This function will allow synchronized loading of the duty registers for all the 
*               channels of a given MCPWM module
*
* @param[in]    HwCfgPtr       Pointer to PWM module configuration structure

*
* @return       void
*
*/
void Pwm_Drvw_SyncUpdate(const Pwm_Drvw_HwConfigType * HwCfgPtr);
#endif /* PWM_DRVW_SYNC_UPDATE_API */

#if (PWM_DRVW_SET_PHASE_SHIFT_TICKS_API == STD_ON)
/**
* @brief        This function set phase shift value and also force duty cycle to 50%. The output will
*               effect immediately after calling this function.
*
* @param[in]    Period              Period value for this channel
* @param[in]    PhaseShiftTicks     Phase shift value
* @param[in]    ChnConfigPtr        Pointer to PWM channel configuration structure
*
* @return       void
*
*/
void Pwm_Drvw_SetPhaseShiftTicks(uint16 Period, uint16 PhaseShiftTicks,
                                    const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr);
#endif /* PWM_DRVW_SET_PHASE_SHIFT_TICKS_API */

#if (PWM_DRVW_SET_DUTY_AND_PHASE_SHIFT_TICKS_API == STD_ON)
/**
* @brief        This function set phase shift and duty cycle value (as immediate or synchronized base on API parameter SyncUpdate)
*
* @param[in]    DutyCyclePu               Pwm duty cycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    PhaseShiftTicks           Phase shift value 
* @param[in]    ChnConfigPtr              Pointer to PWM channel configuration structure
* @param[in]    SyncUpdate                
*                      TRUE               calling Pwm_SyncUpdate Effective.
                       FALSE              Effective immediately
*
* @return       void
*
*/
void Pwm_Drvw_SetDutyPhaseShiftTicks(uint16 DutyCyclePu, uint16 PhaseShiftTicks,
                const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr, boolean SyncUpdate);
#endif /* PWM_DRVW_SET_DUTY_AND_PHASE_SHIFT_TICKS_API */

#if (PWM_DRVW_ENABLE_TRIGGER_OUTPUT_API == STD_ON)
/**
* @brief        This function enables trigger generation for specific source
*
* @param[in]    TrigMask       bit mask will be clear for MCPWM_EXTTRIG.
*                                - Bit 0~7   Channel 0~7 Trigger Enable
*                                - Bit 8     Initialization Trigger Enable
* @param[in]    HwCfgPtr       Pointer to PWM module configuration structure
*
* @return       void
*
*/
void Pwm_Drvw_EnableTriggerOutput(uint16 TrigMask, const Pwm_Drvw_HwConfigType * const HwCfgPtr);
#endif /* PWM_DRVW_ENABLE_TRIGGER_OUTPUT_API */

#if (PWM_DRVW_DISABLE_TRIGGER_OUTPUT_API == STD_ON)
/**
* @brief        This function disables trigger generation for specific source
*               
* @param[in]    TrigMask       bit mask will be clear for MCPWM_EXTTRIG.
*                                - Bit 0~7   Channel 0~7 Trigger Enable
*                                - Bit 8     Initialization Trigger Enable
* @param[in]    HwCfgPtr       Pointer to PWM module configuration structure
*
* @return       void
*
*/
void Pwm_Drvw_DisableTriggerOutput(uint16 TrigMask, const Pwm_Drvw_HwConfigType * const HwCfgPtr);
#endif /* PWM_DRVW_DISABLE_TRIGGER_OUTPUT_API */

#if (PWM_DRVW_ENABLE_MASKING_OPERATIONS == STD_ON)
/**
* @brief        This function force channels output to their inactive state
*
* @param[in]    ChannelMask    bit mask will be set for MCPWM_OUTMASK.
*                                - Bit 0~7   Channel 0~7 Output Mask
* @param[in]    HwCfgPtr       Pointer to PWM module configuration structure
*
* @return       void
*
*/
void Pwm_Drvw_MaskOutputs(uint8 ChannelMask, const Pwm_Drvw_HwConfigType * const HwCfgPtr);

/**
* @brief        This function puts channels output to normal operation state
*
* @param[in]    ChannelMask    bit mask will be set for MCPWM_OUTMASK.
*                                - Bit 0~7   Channel 0~7 Output Mask
* @param[in]    HwCfgPtr       Pointer to PWM module configuration structure
*
* @return       void
*
*/
void Pwm_Drvw_UnMaskOutputs(uint8 ChannelMask, const Pwm_Drvw_HwConfigType * const HwCfgPtr);
#endif /* PWM_DRVW_ENABLE_MASKING_OPERATIONS */

/**
* @brief        This function will call CheckIdleState function of all configured hardware channels
*
* @param[in]    ChnConfigPtr        Pointer to PWM channel configuration structure
*
* @return       Std_ReturnType
* @retval       E_NOT_OK            The Idle state is not ready
* @retval       E_OK                The Idle state is ready
*
*/
Std_ReturnType Pwm_Drvw_CheckIdleState(const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr);

#if (PWM_DRVW_LOW_POWER_STATE_SUPPORTED == STD_ON)
/**
* @brief        This function will call SetPowerState function of all configured hardware modules
*
* @param[in]    HwCfgPtr        Pointer to PWM module configuration structure
* @param[in]    PowerState      Target power mode
*
* @return       void
*
*/
void Pwm_Drvw_SetPowerState(const Pwm_Drvw_HwConfigType * const HwCfgPtr,
                                                       Pwm_Drvw_PowerStateType PowerState);
#endif /* PWM_DRVW_LOW_POWER_STATE_SUPPORTED */

#if (PWM_DRVW_MAX_PERIOD_PLAUSABILITY == STD_ON)
    #if ((PWM_DRVW_SET_PERIOD_AND_DUTY_API               == STD_ON) || \
         (PWM_DRVW_WRITE_PERIOD_AND_DUTY_TO_BUFFER_API   == STD_ON) || \
         (PWM_DRVW_SET_PHASE_SHIFT_TICKS_API             == STD_ON) || \
         (PWM_DRVW_WRITE_PHASE_SHIFT_TICKS_TO_BUFFER_API == STD_ON))
/**
* @brief        Get the maximum period in physical hardware channels.
*
* @param[in]    ChnConfigPtr        Pointer to PWM channel configuration structure
*
* @return       uint32              Max period value
*
*/  
uint32 Pwm_Drvw_GetMaxPeriodValue(const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr);
    #endif
#endif /* PWM_DRVW_MAX_PERIOD_PLAUSABILITY */

#if (PWM_DRVW_DEV_ERROR_DETECT == STD_ON)
    #if (PWM_DRVW_SET_CHANNEL_DEAD_TIME_TICKS_API == STD_ON)
/**
* @brief        This function will check operation mode of current channel to use deadtime feature.
*
* @param[in]    ChnConfigPtr        Pointer to PWM channel configuration structure
*
* @return       Std_ReturnType
* @retval       E_NOT_OK        Current channel DeadTime mode is invalid
* @retval       E_OK            Current channel DeadTime mode is valid
*
*/
Std_ReturnType Pwm_Drvw_CheckDeadTimeMode(const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr);

    #endif /* PWM_DRVW_SET_CHANNEL_DEAD_TIME_TICKS_API */

    #if (PWM_DRVW_SET_DUTY_AND_PHASE_SHIFT_TICKS_API == STD_ON)
/**
* @brief        This function will check phase shift ticks and duty cycle per unit value
*
* @param[in]    PhaseShiftTicks     Phase shift ticks value
* @param[in]    DutyCyclePu         Duty Cycle value
* @param[in]    ChnConfigPtr        Pointer to PWM channel configuration structure
*
* @return       Std_ReturnType  
* @retval       E_NOT_OK            Params is invalid
* @retval       E_OK                Params is valid
*
*/
Std_ReturnType Pwm_Drvw_CheckSetDutyPhaseShiftParams(uint16 PhaseShiftTicks, uint16 DutyCyclePu,
                                    const Pwm_Drvw_ChannelConfigType * const ChnConfigPtr);

    #endif /* PWM_DRVW_SET_DUTY_AND_PHASE_SHIFT_TICKS_API */

#endif /* PWM_DRVW_DEV_ERROR_DETECT */

/** @} end of group Public_FunctionDeclaration */

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} end of group Pwm_Drvw */

/** @} end of group Pwm_Module */

#endif
