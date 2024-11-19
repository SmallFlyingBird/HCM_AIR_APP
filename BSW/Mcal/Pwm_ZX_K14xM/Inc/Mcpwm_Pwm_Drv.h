/*************************************************************************************/
/**
 * @file      : Mcpwm_Pwm_Drv.h
 * @brief     : AUTOSAR Pwm low level driver header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 *************************************************************************************/

#ifndef MCPWM_PWM_DRV_H
#define MCPWM_PWM_DRV_H

/** @addtogroup  Pwm_Module
 *  @{
 */

/** @addtogroup Mcpwm_Pwm_Drv
 *  @brief Pwm low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Mcpwm_Pwm_Drv_Types.h"
/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define MCPWM_PWM_DRV_H_VENDOR_ID                   0x00B3U
#define MCPWM_PWM_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define MCPWM_PWM_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define MCPWM_PWM_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define MCPWM_PWM_DRV_H_SW_MAJOR_VERSION            1U
#define MCPWM_PWM_DRV_H_SW_MINOR_VERSION            2U
#define MCPWM_PWM_DRV_H_SW_PATCH_VERSION            2U

/* Check if header file and Mcpwm_Pwm_Drv_Types.h header file are the same vendor */
#if (MCPWM_PWM_DRV_H_VENDOR_ID != MCPWM_PWM_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Mcpwm_Pwm_Drv.h and Mcpwm_Pwm_Drv_Types.h are different"
#endif

/* Check if header file and Mcpwm_Pwm_Drv_Types.h header file are the same AUTOSAR version */
#if ((MCPWM_PWM_DRV_H_AR_RELEASE_MAJOR_VERSION    != MCPWM_PWM_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
     (MCPWM_PWM_DRV_H_AR_RELEASE_MINOR_VERSION    != MCPWM_PWM_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) || \
     (MCPWM_PWM_DRV_H_AR_RELEASE_REVISION_VERSION != MCPWM_PWM_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Mcpwm_Pwm_Drv.h and Mcpwm_Pwm_Drv_Types.h are different"
#endif

/* Check if header file and Mcpwm_Pwm_Drv_Types.h header file are the same software version */
#if ((MCPWM_PWM_DRV_H_SW_MAJOR_VERSION != MCPWM_PWM_DRV_TYPES_H_SW_MAJOR_VERSION) || \
     (MCPWM_PWM_DRV_H_SW_MINOR_VERSION != MCPWM_PWM_DRV_TYPES_H_SW_MINOR_VERSION) || \
     (MCPWM_PWM_DRV_H_SW_PATCH_VERSION != MCPWM_PWM_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Mcpwm_Pwm_Drv.h and Mcpwm_Pwm_Drv_Types.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"
/**
 * @brief   Export Post-Build configurations.
 */
MCPWM_PWM_DRV_CONFIG_EXT

#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

/** @} end of group Global_VariableDeclaration */

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/**
 * @brief     Initialize the driver of MCPWM module with user configuration generated from AUTOSAR 
 *            code template.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] UserCfg: The configuration pointer of user definition. 
 * 
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_Init(uint8 McpwmId, const Mcpwm_Pwm_Drv_UserCfgType * UserCfg);

/**
 * @brief     De-initialize the MCPWM module and reset all registers of MCPWM.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * 
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_DeInit(uint8 McpwmId);

/**
 * @brief     Update the Pwm dutycycle for the channel of MCPWM module.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] DutyCycle: The duty cycle to be updated. 
 * @param[in] SwTrigger: If the duty cycle update immediately or not. 
 * 
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_SetDutyCycle(uint8 McpwmId, uint8 ChannelId, uint16 DutyCycle, 
                                                                           boolean SwTrigger);

/**
 * @brief     Update the Pwm period and duty cycle for the channel of MCPWM module.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Period: The period to be updated. 
 * @param[in] DutyCycle: The duty cycle to be updated. 
 * @param[in] SwTrigger: If the period and duty cycle updated immediately or not. 
 * 
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_SetPeriodAndDuty(uint8 McpwmId, uint8 ChannelId, uint16 Period, uint16 DutyCycle, 
                                                                           boolean SwTrigger);

/**
 * @brief     Set the software output control configuration for the channel.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] State: The software output state of channel when software output control activate. 
 * @param[in] ActiveState: Enable/Disable the software control output. 
 * 
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_SwOutputControl(uint8 McpwmId, uint8 ChannelId, 
                                    Mcpwm_Pwm_Drv_OutputStateType State, boolean ActiveState);

/**
 * @brief     Get current output state of the channel.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * 
 * @return   Mcpwm_Pwm_Drv_OutputStateType: Current output pwm state of the channel.
 * @retval  MCPWM_PWM_DRV_OUTPUT_STATE_LOW: Current output pwm is low.
 * @retval  MCPWM_PWM_DRV_OUTPUT_STATE_HIGH: Current output pwm is high.
 *
 */
Mcpwm_Pwm_Drv_OutputStateType Mcpwm_Pwm_Drv_GetOutputState(uint8 McpwmId, uint8 ChannelId);

/**
 * @brief     Disable the match notification of the channel.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * 
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_DisableNotification(uint8 McpwmId, uint8 ChannelId);

/**
 * @brief     Enable the notification for  the channel.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Notification: The notification to be enabled. 
 * 
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_EnableNotification(uint8 McpwmId, uint8 ChannelId, 
                                                    Mcpwm_Pwm_Drv_EdgeNotifType Notification);

/**
 * @brief     Set the period and start of the active state of PWM output while channel worked in 
 *            variable edge placement output mode.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Period: The period to be set. 
 * @param[in] PhaseShift: The start of the active state of PWM output to be set. 
 * @param[in] SoftwareShift: Enable/Disable the configuration updated immediately. 
 * 
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_SetPhaseShift(uint8 McpwmId, uint8 ChannelId, uint16 Period, uint16 PhaseShift, 
                                                                       boolean SoftwareShift);

/**
 * @brief     Set the duty cycle of PWM output while channel worked in variable edge placement 
 *            output mode.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] DutyCycle: The dutycycle to be set. 
 * @param[in] PhaseShift: The start of the active state of PWM output to be set. 
 * @param[in] SoftwareTrigger: Enable/Disable the configuration updated immediately. 
 * 
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_SetDutyPhaseShift(uint8 McpwmId, uint8 ChannelId, uint16 DutyCycle, 
                                                  uint16 PhaseShift, boolean SoftwareTrigger);

/**
 * @brief     This function is used to get current duty cycle of the channel 
 *
 * @param[in] McpwmId:   The id of the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 *
 * @return    uint16     DutyCyclePu of the specified logic channel
 */
uint16 Mcpwm_Pwm_Drv_GetChannelDutyCycle(uint8 McpwmId, uint8 ChannelId);

/**
 * @brief     Set the dead time value for the channel.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] DeadTimeVal: The dead time value be set. 
 * 
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_SetChannelDeadTime(uint8 McpwmId, uint8 ChannelId, uint16 DeadTimeVal);

/**
 * @brief     Enable the triggers that triggerMask activated.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] TriggerMask: The triggers activated mask. 
 * 
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_EnableTrigger(uint8 McpwmId, uint32 TriggerMask);

/**
 * @brief     Disable the triggers that triggerMask activated.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] TriggerMask: The triggers activated mask. 
 * 
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_DisableTrigger(uint8 McpwmId, uint32 TriggerMask);


/**
 * @brief     Enable the reload mechanism of MCPWM module.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * 
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_SyncUpdate(uint8 McpwmId);

/**
 * @brief     Disable the channel output as mask activate.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChannelMask: The channel to be masked. 
 * 
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_MaskOutputChannels(uint8 McpwmId, uint32 ChannelMask);

/**
 * @brief     Unmask the output of the channel.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChannelMask: The channel to be unmasked. 
 * 
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_UnMaskOutputChannels(uint8 McpwmId, uint32 ChannelMask);

/**
 * @brief     Set the power state of the MCPWM module.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] PowerState: The power state to be set. 
 * 
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_SetPowerState(uint8 McpwmId, Mcpwm_Pwm_Drv_PowerStateType PowerState);

/**
 * @brief     Get current output pwm mode of the channel.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * 
 * @return  Mcpwm_Pwm_Drv_ChannelModeType: Current output pwm mode of the channel.
 * @retval  MCPWM_PWM_DRV_MODE_EDGE_ALIGNED: Current output mode is independent edge aligned.
 * @retval  MCPWM_PWM_DRV_MODE_CENTER_ALIGNED: Current output mode is independent center aligned.
 * @retval  MCPWM_PWM_DRV_MODE_COMBINE_EDGE_ALIGNED: Current output pwm mode is complementary edge 
 *                                                 aligned mode.
 * @retval  MCPWM_PWM_DRV_MODE_COMBINE_SYM_CENTER_ALIGNED: Current output pwm mode is complementary 
 *                                                 symmetric center aligned mode.
 * @retval  MCPWM_PWM_DRV_MODE_COMBINE_VARIABLE_EDGE_PLACEMENT: Current output pwm mode is 
 *                                                 complementary variable edge placement mode.
 *
 */
Mcpwm_Pwm_Drv_ChannelModeType Mcpwm_Pwm_Drv_GetChannelMode(uint8 McpwmId, uint8 ChannelId);

/**
 * @brief     Get current state of the channel.
 *
 * @param[in] McpwmId: The id of MCPWM module.
 * @param[in] ChannelId: The id of the channel.
 *
 * @return   Current State of the channel.
 * @retval  MCPWM_PWM_DRV_CHANNEL_UNINIT: The Channel is uninitialized.
 * @retval  MCPWM_PWM_DRV_CHANNEL_RUNNING: The Channel is running.
 * @retval  MCPWM_PWM_DRV_CHANNEL_IDLE: The Channel is in idle state.
 * @retval  MCPWM_PWM_DRV_CHANNEL_OUTPUT_FORCED: The Channel is in forced output state.
 *
 */
Mcpwm_Pwm_Drv_ChannelStateType Mcpwm_Pwm_Drv_GetCurrentChannelState(uint8 McpwmId, uint8 ChannelId);

/**
 * @brief     Set current state of the channel.
 *
 * @param[in] McpwmId: The id of MCPWM module.
 * @param[in] ChannelId: The id of the channel.
 * @param[in] State: The target state of the channel.
 *
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_SetCurrentChannelState(uint8 McpwmId, uint8 ChannelId,
                                                        Mcpwm_Pwm_Drv_ChannelStateType State);

/**
 * @brief     Revert current state of the channel.
 *
 * @param[in] McpwmId: The id of MCPWM module.
 * @param[in] ChannelId: The id of the channel.
 *
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_RevertCurrentChannelState(uint8 McpwmId, uint8 ChannelId);

/**
 * @brief     Get current notif type of the channel.
 *
 * @param[in] McpwmId: The id of MCPWM module.
 * @param[in] ChannelId: The id of the channel.
 *
 * @return   Mcpwm_Pwm_Drv_EdgeInterruptType: Edge Interrupt Type.
 *
 */
Mcpwm_Pwm_Drv_EdgeInterruptType Mcpwm_Pwm_Drv_GetNotifFlag(uint8 McpwmId, uint8 ChannelId);

/**
 * @brief     Get current period of the channel.
 *
 * @param[in] McpwmId: The id of MCPWM module.
 * @param[in] ChannelId: The id of the channel.
 *
 * @return   uint16 : Current period of the channel. 
 *
 */
uint16 Mcpwm_Pwm_Drv_GetPeriod(uint8 McpwmId, uint8 ChannelId);

/**
 * @brief     Software trig the sync of registers for MOD and CCV.
 *
 * @param[in] McpwmId: The id of MCPWM module.
 *
 * @return    None 
 *
 */
void Mcpwm_Pwm_Drv_SoftwareUpdate(uint8 McpwmId);

/**
 * @brief     Software triggered, updated immediately after service call.
 *
 * @param[in] McpwmId: The id of MCPWM module.
 *
 * @return    None 
 *
 */
void Mcpwm_Pwm_Drv_UpdateNow(uint8 McpwmId);

/**
 * @brief     Init the idle output state of the channel.
 *
 * @param[in] ModuleId: The id of MCPWM module.
 * @param[in] ChannelId: The id of channel.
 * @param[in] State: The idle output state to be set.
 *
 * @return    None 
 *
 */
void Mcpwm_Pwm_Drv_InitIdleState(uint8 ModuleId, uint8 ChannelId, 
                                                         Mcpwm_Pwm_Drv_OutputStateType State);

/**
 * @brief     Get the idle output state of the channel.
 *
 * @param[in] McpwmId: The id of MCPWM module.
 * @param[in] ChannelId: The id of channel.
 *
 * @return    Mcpwm_Pwm_Drv_OutputStateType  current idle output state of the channel
 * @retval    - MCPWM_PWM_DRV_OUTPUT_STATE_LOW   Current idle output state is low
 * @retval    - MCPWM_PWM_DRV_OUTPUT_STATE_HIGH  Current idle output state is high
 *
 */
Mcpwm_Pwm_Drv_OutputStateType Mcpwm_Pwm_Drv_GetIdleState(uint8 McpwmId, uint8 ChannelId);

/**
 * @brief     Init the off value of the channel.
 *
 * @param[in] ModuleId: The id of MCPWM module.
 * @param[in] ChannelId: The id of channel.
 * @param[in] State: The off value to be set.
 *
 * @return    None 
 *
 */
void Mcpwm_Pwm_Drv_InitOffValue(uint8 ModuleId, uint8 ChannelId, 
                                                         Mcpwm_Pwm_Drv_OutputStateType State);

/**
 * @brief     Start to run the MCPWM module after initialization.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] InstanceCfg: The configuration pointer of the MCPWM. 
 * 
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_InitInstanceStart(uint8 McpwmId, const Mcpwm_Pwm_Drv_ConfigType * InstanceCfg);

/**
 * @brief     Processing overflow interrupt.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * 
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_ProcessTofInterrupt(uint8 McpwmId);


/**
 * @brief     Processing channel matching interrupt.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * 
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_ProcessCommonInterrupt(uint8 McpwmId);


/** @} end of group Public_FunctionDeclaration */

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} end of group Mcpwm_Pwm_Drv */

/** @} end of group Pwm_Module */

#endif
