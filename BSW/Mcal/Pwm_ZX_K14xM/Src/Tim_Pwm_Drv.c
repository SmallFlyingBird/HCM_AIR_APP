/*************************************************************************************/
/**
 * @file      : Tim_Pwm_Drv.c
 * @brief     : AUTOSAR Pwm low level driver source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 *************************************************************************************/
/** @addtogroup  Pwm_Module
 *  @{
 */

/** @addtogroup Pwm_Drv 
 *  @brief Pwm low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif
#include "Tim_Pwm_Drv.h"
#include "Device_Regs.h"
#include "SchM_Pwm.h"
/** @defgroup Private_MacroDefinition
 *  @{
 */
#define TIM_PWM_DRV_C_VENDOR_ID                   0x00B3U
#define TIM_PWM_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define TIM_PWM_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define TIM_PWM_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define TIM_PWM_DRV_C_SW_MAJOR_VERSION            1U
#define TIM_PWM_DRV_C_SW_MINOR_VERSION            2U
#define TIM_PWM_DRV_C_SW_PATCH_VERSION            1U

/* Check if source file and Tim_Pwm_Drv.h header file are of the same vendor */
#if (TIM_PWM_DRV_C_VENDOR_ID != TIM_PWM_DRV_H_VENDOR_ID)
    #error "Vendor ID of Tim_Pwm_Drv.c and Tim_Pwm_Drv.h are different"
#endif
/* Check if source file and Tim_Pwm_Drv.h header file are of the same AUTOSAR version */
#if ((TIM_PWM_DRV_C_AR_RELEASE_MAJOR_VERSION    != TIM_PWM_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (TIM_PWM_DRV_C_AR_RELEASE_MINOR_VERSION    != TIM_PWM_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (TIM_PWM_DRV_C_AR_RELEASE_REVISION_VERSION != TIM_PWM_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Tim_Pwm_Drv.c and Tim_Pwm_Drv.h are different"
#endif
/* Check if header file and Tim_Pwm_Drv.h header file are of the same software version */
#if ((TIM_PWM_DRV_C_SW_MAJOR_VERSION != TIM_PWM_DRV_H_SW_MAJOR_VERSION) || \
     (TIM_PWM_DRV_C_SW_MINOR_VERSION != TIM_PWM_DRV_H_SW_MINOR_VERSION) || \
     (TIM_PWM_DRV_C_SW_PATCH_VERSION != TIM_PWM_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Tim_Pwm_Drv.c and Tim_Pwm_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Device_Regs.h are the same Autosar version */
    #if ((TIM_PWM_DRV_C_AR_RELEASE_MAJOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) || \
         (TIM_PWM_DRV_C_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Tim_Pwm_Drv.c and Device_Regs.h are different"
    #endif
        
    /* Check if current file and SchM_Pwm.h are the same Autosar version */
    #if ((TIM_PWM_DRV_C_AR_RELEASE_MAJOR_VERSION != SCHM_PWM_H_AR_RELEASE_MAJOR_VERSION) || \
         (TIM_PWM_DRV_C_AR_RELEASE_MINOR_VERSION != SCHM_PWM_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar version of Tim_Pwm_Drv.c and SchM_Pwm.h are different"
    #endif
#endif

/******************************************************************/
/** @brief OUTCR Register Definition   */
#define TIM_OUTCR_TRIGE_SHIFT         (16UL)

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */
/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

#define PWM_START_SEC_VAR_CLEARED_16
#include "Pwm_MemMap.h"
static uint16 Tim_Pwm_Drv_Period[TIM_PWM_DRV_INSTANCE_NUM];
static uint16 Tim_Pwm_Drv_DutyCycle[TIM_PWM_DRV_INSTANCE_NUM][TIM_PWM_DRV_CHANNEL_NUM];
static uint16 Tim_Pwm_Drv_PhaseShift[TIM_PWM_DRV_INSTANCE_NUM][TIM_PWM_DRV_PAIR_CHANNEL_NUM];
#define PWM_STOP_SEC_VAR_CLEARED_16
#include "Pwm_MemMap.h"

#define PWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Pwm_MemMap.h"

static Tim_Pwm_Drv_EdgeInterruptType Tim_Pwm_Drv_NotifIrq[TIM_PWM_DRV_INSTANCE_NUM] \
                                                  [TIM_PWM_DRV_CHANNEL_NUM];
static Tim_Pwm_Drv_ChannelModeType Tim_Pwm_Drv_ChannelMode[TIM_PWM_DRV_INSTANCE_NUM] \
                                                          [TIM_PWM_DRV_CHANNEL_NUM];
static Tim_Pwm_Drv_ChannelStateType Tim_Pwm_Drv_ChannelState[TIM_PWM_DRV_INSTANCE_NUM] \
                                                            [TIM_PWM_DRV_CHANNEL_NUM];
static Tim_Pwm_Drv_ChannelStateType Tim_Pwm_Drv_PreviousChannelState[TIM_PWM_DRV_INSTANCE_NUM] \
                                                                    [TIM_PWM_DRV_CHANNEL_NUM];
static Tim_Pwm_Drv_OutputStateType Tim_Pwm_Drv_IdleState[TIM_PWM_DRV_INSTANCE_NUM] \
                                                        [TIM_PWM_DRV_CHANNEL_NUM];
static Tim_Pwm_Drv_PolarityType Tim_Pwm_Drv_PolarityState[TIM_PWM_DRV_INSTANCE_NUM] \
                                                         [TIM_PWM_DRV_CHANNEL_NUM];
static Tim_Pwm_Drv_ClkSourceType Tim_Pwm_Drv_ClockSource[TIM_PWM_DRV_INSTANCE_NUM];
static Tim_Pwm_Drv_ClkDivideType Tim_Pwm_Drv_ClockDivide[TIM_PWM_DRV_INSTANCE_NUM];

static Tim_Pwm_Drv_CallbackType Tim_Pwm_Drv_ChIrqCallbacks[TIM_PWM_DRV_INSTANCE_NUM] \
                                                   [TIM_PWM_DRV_CHANNEL_NUM];
#if (TIM_PWM_DRV_NOTIFICATION_SUPPORTED == STD_ON)
static Tim_Pwm_Drv_CallbackType Tim_Pwm_Drv_OverflowIrqCallbacks[TIM_PWM_DRV_INSTANCE_NUM] \
                                                         [TIM_PWM_DRV_CHANNEL_NUM];
#else
static Tim_Pwm_Drv_CallbackType Tim_Pwm_Drv_OverflowIrqCallbacks[TIM_PWM_DRV_INSTANCE_NUM];
#endif

#define PWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CONST_PTR
#include "Pwm_MemMap.h"
/* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer object,
   no side effects forseen by violating this rule.
The following four lines of code also violate this rule with the same reason. */
static Reg_Tim_BfType * const Tim_Pwm_Drv_PwmRegBfPtr[TIM_PWM_DRV_INSTANCE_NUM] = 
{
    (Reg_Tim_BfType *) TIM0_BASE_ADDR,
    (Reg_Tim_BfType *) TIM1_BASE_ADDR,
    (Reg_Tim_BfType *) TIM2_BASE_ADDR,
    (Reg_Tim_BfType *) TIM3_BASE_ADDR
};

/* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer object,
   no side effects forseen by violating this rule.
The following four lines of code also violate this rule with the same reason. */
static Reg_Tim_WType * const Tim_Pwm_Drv_PwmRegWPtr[TIM_PWM_DRV_INSTANCE_NUM] = 
{
    (Reg_Tim_WType *) TIM0_BASE_ADDR,
    (Reg_Tim_WType *) TIM1_BASE_ADDR,
    (Reg_Tim_WType *) TIM2_BASE_ADDR,
    (Reg_Tim_WType *) TIM3_BASE_ADDR
};
#define PWM_STOP_SEC_CONST_PTR
#include "Pwm_MemMap.h"

/** @} end of group Private_VariableDefinition */

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
/**
 * @brief      Get the output polarity of Pwm channel.
 *
 * @param[in] BaseBf: The hardware registers struct pointer of TIM module.
 * @param[in] ChannelId: The id of the channel.
 *
 * @return    Tim_Pwm_Drv_PolarityType: The output polarity of the channel.
 * @retval   TIM_PWM_DRV_POL_HIGH: the channel output polarity is High.
 * @retval   TIM_PWM_DRV_POL_LOW: the channel output polarity is Low.
 *
 */
LOCAL_INLINE Tim_Pwm_Drv_PolarityType Tim_Pwm_Drv_GetChannelPolVal(const Reg_Tim_BfType * BaseBf, 
                                                                                uint8 ChannelId);

/**
 * @brief     Set the output polarity of the channel.
 *
 * @param[in] BaseBf: The hardware registers struct pointer for the TIM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Pol: The polairty to be set. 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Tim_Pwm_Drv_SetChannelPolarity(Reg_Tim_BfType * BaseBf, uint8 ChannelId, 
                                              Tim_Pwm_Drv_PolarityType Pol);

/**
 * @brief     Set the deadtime of the pair channels inserted Enable/disable.
 *
 * @param[in] BaseBf: The hardware registers struct pointer for the TIM module. 
 * @param[in] PairId: The id of the pair channels. 
 * @param[in] Cmd: Enable/Disable the deadtime inserted. 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Tim_Pwm_Drv_PairDeadtimeCmd(Reg_Tim_BfType * BaseBf, uint8 PairId, boolean Cmd);

/**
 * @brief     Get the combine state of pair channels.
 *
 * @param[in] BaseBf: The hardware registers struct pointer of TIM module.
 * @param[in] PairId: The id of the pair channels.
 *
 * @return    boolean: If the pair channels output in independ mode or combine mode.
 * @retval    TRUE:  The channels output in combine mode.
 * @retval    FALSE: The channels output in indepedent mode.
 *
 */
LOCAL_INLINE boolean Tim_Pwm_Drv_GetDualCombineCmd(const Reg_Tim_BfType * BaseBf, uint8 PairId);

/**
 * @brief     Get the software control output Enable/disable status of Pwm channel.
 *
 * @param[in] BaseBf: The hardware registers struct pointer of TIM module.
 * @param[in] ChannelId:The id of the channel.
 *
 * @return    boolean: If the Pwm channel output Enable.
 * @retval    TRUE: The Pwm channel is software control output Enable.
 * @retval    FALSE: The Pwm channel is software control output disable.
 *
 */
LOCAL_INLINE boolean Tim_Pwm_Drv_GetOutSwCtrState(const Reg_Tim_BfType * BaseBf, uint8 ChannelId);

/**
 * @brief      Get the software control output value of Pwm channel.
 *
 * @param[in] BaseBf: The hardware registers struct pointer of TIM module.
 * @param[in] ChannelId: The id of the channel.
 *
 * @return    boolean: If the software control output value of Pwm channel is High.
 * @retval    TRUE: The software control output value of Pwm channel is High.
 * @retval    FALSE: The software control output value of Pwm channel is Low.
 *
 */
LOCAL_INLINE boolean Tim_Pwm_Drv_GetOutSwCtrVal(const Reg_Tim_BfType * BaseBf, uint8 ChannelId);

/**
 * @brief     Set the match trigger of the channel.
 *
 * @param[in] BaseBf: The hardware registers struct pointer for the TIM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Trigger: Enable/Disable the match trigger of the channel. 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Tim_Pwm_Drv_ControlChannelMatchTrigger(Reg_Tim_BfType * BaseBf, uint8 ChannelId, 
                                                  boolean Trigger);

/**
 * @brief     Set the software control output value of the channel.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] State: The output value to be set. 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Tim_Pwm_Drv_SetChannelOCV(uint8 TimId, uint8 ChannelId, 
                                         Tim_Pwm_Drv_OutputStateType State);

/**
 * @brief     Set the software control output of the channel Enable/disable.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Cmd: Enable/Disable the software control output of the channel. 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Tim_Pwm_Drv_ControlChannelOC(uint8 TimId, uint8 ChannelId, boolean Cmd);

/**
 * @brief     Set the complentary/independent output mode of the pair channels.
 *
 * @param[in] BaseBf: The hardware registers struct pointer for the TIM module. 
 * @param[in] PairId: The id of the pair channels. 
 * @param[in] Cmd: The complentary/independent output mode to be set. 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Tim_Pwm_Drv_SetPairCombineCmd(Reg_Tim_BfType * BaseBf, uint8 PairId, boolean Cmd);

/**
 * @brief     Set the synchronization Enable/disable of the pair channels.
 *
 * @param[in] BaseBf: The hardware registers struct pointer for the TIM module. 
 * @param[in] PairId: The id of the pair channels. 
 * @param[in] Enable: Enable/Disable the synchronization of CV(n) and CV(n+1). 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Tim_Pwm_Drv_ControlPairSynchronization(Reg_Tim_BfType * BaseBf, uint8 PairId, 
                                                    boolean Enable);

/**
 * @brief     Get current complementary config of the channel.
 *
 * @param[in] BaseBf: The hardware registers struct pointer for the TIM module. 
 * @param[in] ChannelId: The id of the channel.
 *
 * @return   boolean : The complementary is enable or disable.
 * @retval   TRUE: The complementary is enable.
 * @retval   FALSE: The complementary is disable.
 *
 */
LOCAL_INLINE boolean Tim_Pwm_Drv_GetCombineConfig(const Reg_Tim_BfType * BaseBf, uint8 ChannelId);

/**
 * @brief     Enable the normal notification case for the channel, contain the overflow interrupt 
 *            and the match interrupt.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] ChannelId: The id of the channel. 
 * 
 * @return   None
 *
 */
static void Tim_Pwm_Drv_SetNormalNotificationCase(uint8 TimId, uint8 ChannelId);

/**
 * @brief     Update the notification edge type of the pair channel in complementary output mode.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Notification: The edge type for notification to be updated. 
 * 
 * @return   None
 *
 */
static void Tim_Pwm_Drv_UpdateNotificationStateCombine(uint8 TimId, uint8 ChannelId,
                                                   Tim_Pwm_Drv_EdgeNotifType Notification);

/**
 * @brief     Update the notification edge type of the channel in independent edge output mode.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Notification: The edge type for notification to be updated. 
 * 
 * @return   None
 *
 */
static void Tim_Pwm_Drv_UpdateNotificationStateEdge(uint8 TimId, uint8 ChannelId,
                                            Tim_Pwm_Drv_EdgeNotifType Notification);

/**
 * @brief     Update the notification edge type of the channel in independent center output mode.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Notification: The edge type for notification to be updated. 
 * 
 * @return   None
 *
 */                                            
static void Tim_Pwm_Drv_UpdateNotificationStateCenter(uint8 TimId, uint8 ChannelId,
                                            Tim_Pwm_Drv_EdgeNotifType Notification);                                       

/**
 * @brief     Set the counters config of the TIM module.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] CntCfg: The counters configurations pointer to be configured. 
 * 
 * @return   None
 *
 */
static void Tim_Pwm_Drv_ConfigCounter(uint8 TimId, const Tim_Pwm_Drv_ConfigType * CntCfg);

#if (TIM_PWM_DRV_NOTIFICATION_SUPPORTED == STD_ON)
/**
 * @brief     Check if notifications have been enabled in special circumstances.
 *
 * @param[in] TimId: The id of the TIM module.
 * @param[in] ChannelId: The id of the channel.
 *
 * @return    None
 *
 */
static void Tim_Pwm_Drv_SpecialCheckNotification(uint8 TimId, uint8 ChannelId);

/**
 * @brief     Check if notifications are enabled under normal circumstances.
 *
 * @param[in] TimId: The id of the TIM module.
 * @param[in] ChannelId: The id of the channel.
 *
 * @return    None
 *
 */
static void Tim_Pwm_Drv_NormalCheckNotification(uint8 TimId, uint8 ChannelId);

/**
 * @brief     Check if notification is enabled.
 *
 * @param[in] TimId: The id of the TIM module.
 * @param[in] ChannelId: The id of the channel.
 *
 * @return    None
 *
 */
static void Tim_Pwm_Drv_CheckNotification(uint8 TimId, uint8 ChannelId);
#endif

/**
 * @brief     Set the counters config of the TIM module.
 *
 * @param[in] ChannelMode: The output pwm mode of the TIM channel. 
 * 
 * @return    Tim_Pwm_Drv_PulsePolarityType
 *              - TIM_PWM_DRV_LOW_PULSE_POL      Tim Channel Pulse Polarity Low
 *              - TIM_PWM_DRV_HIGH_PULSE_POL     Tim Channel Pulse Polarity High
 *
 */
static Tim_Pwm_Drv_PulsePolarityType Tim_Pwm_Drv_SelectChannelPulsePol(
                                            Tim_Pwm_Drv_ChannelModeType ChannelMode);

/**
 * @brief     Initialize the configured channels of TIM module.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] ChCfg: The channels configuration pointer. 
 * 
 * @return   None
 *
 */
static void Tim_Pwm_Drv_InitChannel(uint8 TimId, const Tim_Pwm_Drv_ChannelConfigType * ChCfg);

/**
 * @brief     Set current output mode of the channel.
 *
 * @param[in] TimId: The id of TIM module.
 * @param[in] ChannelId: The id of the channel.
 * @param[in] Mode: The output mode of the channel.
 *
 * @return   None
 *
 */
static void Tim_Pwm_Drv_SetChannelMode(uint8 TimId, uint8 ChannelId, Tim_Pwm_Drv_ChannelModeType Mode);

/**
 * @brief     Initialize the TIM module.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] InstanceCfg: The configuration pointer of the TIM. 
 * 
 * @return   None
 *
 */
static void Tim_Pwm_Drv_InitInstance(uint8 TimId, const Tim_Pwm_Drv_ConfigType * InstanceCfg);

#if (defined(TIM_PWM_DRV_NOTIFICATION_SUPPORTED) && (TIM_PWM_DRV_NOTIFICATION_SUPPORTED == STD_ON))
/**
 * @brief     Set the output of the channel to sepcific state.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] ActiveState: The specific state to be output. 
 * 
 * @return   None
 *
 */
static void Tim_Pwm_Drv_SetOutputForForcedChannel(uint8 TimId, uint8 ChannelId,
                                              boolean ActiveState);
#endif

/**
 * @brief     Update the cycle of the counter.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] Period: The period to be updated. 
 * @param[in] SwTrigger: Enable/Disable update period immediatly. 
 * 
 * @return   None
 *
 */
static void Tim_Pwm_Drv_UpdatePwmPeriod(uint8 TimId, uint32  Period, boolean SwTrigger);

/**
 * @brief     Get whether the output state of the channel output is active(Low true pulse).
 *
 * @param[in] TimId: The id of TIM module.
 * @param[in] ChannelId: The id of output channel.
 *
 * @return   boolean: If the channel output is high.
 * @retval   TRUE: The channel output is active.
 * @retval   FALSE: The channel output is inactive.
 *
 */
static boolean Tim_Pwm_Drv_IsChannelOutputActive(uint8 TimId, uint8 ChannelId);

/**
 * @brief     Disable the interrupts relate to the channel.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] ChannelId: The id of the channel. 
 * 
 * @return   None
 *
 */
static void Tim_Pwm_Drv_DisableInterrupt(uint8 TimId, uint8 ChannelId);

/**
 * @brief     Update the duty cycle when channel output in variable edge placement mode.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] FirstEdge: The first edge to start of the active state of PWM. 
 * @param[in] SecondEdge: The second edge to end of the active state of PWM. 
 * @param[in] SwTrigger: Enable/Disable update the dutycycle immediatly. 
 * 
 * @return   None
 *
 */
static Tim_Pwm_Drv_StatusType Tim_Pwm_Drv_UpdatePwmChannel(uint8 TimId, uint8 ChannelId, uint16 FirstEdge, 
                                                   uint16 SecondEdge, boolean SwTrigger);

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

/**
 * @brief     Get whether the output state of the channel output is active(Low true pulse).
 *
 * @param[in] TimId: The id of TIM module.
 * @param[in] ChannelId: The id of output channel.
 *
 * @return   boolean: If the channel output is high.
 * @retval   TRUE: The channel output is active.
 * @retval   FALSE: The channel output is inactive.
 *
 */
static boolean Tim_Pwm_Drv_IsChannelOutputActive(uint8 TimId, uint8 ChannelId)
{
    Reg_Tim_BfType const * BaseBf = (Reg_Tim_BfType *)Tim_Pwm_Drv_PwmRegBfPtr[TimId];
    Tim_Pwm_Drv_ChannelModeType ChMode;
    uint16 CounterVal = 0;
    uint16 ChannelCmpVal = 0;
    uint8 PairId = ChannelId >> 1U;
    uint16 SecondChCmpVal = 0;
    boolean ActiveState = FALSE;

    ChMode = Tim_Pwm_Drv_ChannelMode[TimId][ChannelId];
    CounterVal = BaseBf->TIM_CNT.CNT;

    switch(ChMode)
    {
        case TIM_PWM_DRV_MODE_EDGE_ALIGNED:
            ChannelCmpVal = (uint16)BaseBf->TIM_CCVn[ChannelId].CCV;
            ActiveState = (boolean)(CounterVal < ChannelCmpVal);
            break;
        case TIM_PWM_DRV_MODE_CENTER_ALIGNED:
            ChannelCmpVal = (uint16)BaseBf->TIM_CCVn[ChannelId].CCV;
            ActiveState = (boolean)(CounterVal < ChannelCmpVal);
            break;
        case TIM_PWM_DRV_MODE_COMBINE_VARIABLE_EDGE_PLACEMENT:
            ChannelCmpVal = (uint16)BaseBf->TIM_CCVn[PairId << 1U].CCV;
            SecondChCmpVal = (uint16)BaseBf->TIM_CCVn[(PairId << 1U) + 1U].CCV;
            if(0UL == ((uint32)ChannelId % 2UL))
            {
                ActiveState = (boolean)((CounterVal < ChannelCmpVal) || \
                                                           (CounterVal > SecondChCmpVal));
            }
            else
            {
                ActiveState = (boolean)((CounterVal >= ChannelCmpVal) && \
                                                          (CounterVal <= SecondChCmpVal));
            }
            break;
        default:
            /* Nothing to do */
            break;
    }

    return ActiveState;
}

/**
 * @brief      Get the output polarity of Pwm channel.
 *
 * @param[in] BaseBf: The hardware registers struct pointer of TIM module.
 * @param[in] ChannelId: The id of the channel.
 *
 * @return    Tim_Pwm_Drv_PolarityType: The output polarity of the channel.
 * @retval   TIM_PWM_DRV_POL_HIGH: the channel output polarity is High.
 * @retval   TIM_PWM_DRV_POL_LOW: the channel output polarity is Low.
 *
 */
LOCAL_INLINE Tim_Pwm_Drv_PolarityType Tim_Pwm_Drv_GetChannelPolVal(const Reg_Tim_BfType * BaseBf, 
                                                            uint8 ChannelId)
{
    Tim_Pwm_Drv_PolarityType PolVal =TIM_PWM_DRV_POL_HIGH;
    switch(ChannelId)
    {
        case 0U:
            PolVal = (Tim_Pwm_Drv_PolarityType)BaseBf->TIM_OUTCR.POL0;
            break;
        case 1U:
            PolVal = (Tim_Pwm_Drv_PolarityType)BaseBf->TIM_OUTCR.POL1;
            break;
        case 2U:
            PolVal = (Tim_Pwm_Drv_PolarityType)BaseBf->TIM_OUTCR.POL2;
            break;
        case 3U:
            PolVal = (Tim_Pwm_Drv_PolarityType)BaseBf->TIM_OUTCR.POL3;
            break;
        case 4U:
            PolVal = (Tim_Pwm_Drv_PolarityType)BaseBf->TIM_OUTCR.POL4;
            break;
        case 5U:
            PolVal = (Tim_Pwm_Drv_PolarityType)BaseBf->TIM_OUTCR.POL5;
            break;
        case 6U:
            PolVal = (Tim_Pwm_Drv_PolarityType)BaseBf->TIM_OUTCR.POL6;
            break;
        case 7U:
            PolVal = (Tim_Pwm_Drv_PolarityType)BaseBf->TIM_OUTCR.POL7;
            break;
        default:
            /* Nothing to do */
            break;
    }
    return PolVal;
}

/**
 * @brief     Set the output polarity of the channel.
 *
 * @param[in] BaseBf: The hardware registers struct pointer for the TIM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Pol: The polairty to be set. 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Tim_Pwm_Drv_SetChannelPolarity(Reg_Tim_BfType * BaseBf, uint8 ChannelId, 
                                              Tim_Pwm_Drv_PolarityType Pol)
{
       switch(ChannelId)
    {
        case 0U:
            BaseBf->TIM_OUTCR.POL0 = (uint32)Pol;
            break;
        case 1U:
            BaseBf->TIM_OUTCR.POL1 = (uint32)Pol;
            break;
        case 2U:
            BaseBf->TIM_OUTCR.POL2 = (uint32)Pol;
            break;
        case 3U:
            BaseBf->TIM_OUTCR.POL3 = (uint32)Pol;
            break;
        case 4U:
            BaseBf->TIM_OUTCR.POL4 = (uint32)Pol;
            break;
        case 5U:
            BaseBf->TIM_OUTCR.POL5 = (uint32)Pol;
            break;
        case 6U:
            BaseBf->TIM_OUTCR.POL6 = (uint32)Pol;
            break;
        case 7U:
            BaseBf->TIM_OUTCR.POL7 = (uint32)Pol;
            break;
        default:
            /* Nothing to do */
            break;
    }
}

/**
 * @brief     Set the deadtime of the pair channels inserted Enable/disable.
 *
 * @param[in] BaseBf: The hardware registers struct pointer for the TIM module. 
 * @param[in] PairId: The id of the pair channels. 
 * @param[in] Cmd: Enable/Disable the deadtime inserted. 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Tim_Pwm_Drv_PairDeadtimeCmd(Reg_Tim_BfType * BaseBf, uint8 PairId, boolean Cmd) 
{
    switch(PairId)
    {
        case 0U:
            BaseBf->TIM_PCR.DTEN0 = Cmd;
            break;
        case 1U:
            BaseBf->TIM_PCR.DTEN1 = Cmd;
            break;
        case 2U:
            BaseBf->TIM_PCR.DTEN2 = Cmd;
            break;
        case 3U:
            BaseBf->TIM_PCR.DTEN3 = Cmd;
            break;
        default:
            /* Nothing to do */
            break;
    }
}

/**
 * @brief     Get the combine state of pair channels.
 *
 * @param[in] BaseBf: The hardware registers struct pointer of TIM module.
 * @param[in] PairId: The id of the pair channels.
 *
 * @return    boolean: If the pair channels output in independ mode or combine mode.
 * @retval    TRUE:  The channels output in combine mode.
 * @retval    FALSE: The channels output in indepedent mode.
 *
 */
LOCAL_INLINE boolean Tim_Pwm_Drv_GetDualCombineCmd(const Reg_Tim_BfType * BaseBf, uint8 PairId)
{
    boolean CombineStatus = FALSE;
    switch(PairId)
    {
        case 0U:
            CombineStatus = (boolean)BaseBf->TIM_PCR.COMB0;
            break;
        case 1U:
            CombineStatus = (boolean)BaseBf->TIM_PCR.COMB1;
            break;
        case 2U:
            CombineStatus = (boolean)BaseBf->TIM_PCR.COMB2;
            break;
        case 3U:
            CombineStatus = (boolean)BaseBf->TIM_PCR.COMB3;
            break;
        default:
            /* Nothing to do */
            break;
    }
    return CombineStatus;
}

/**
 * @brief     Get the software control output Enable/disable status of Pwm channel.
 *
 * @param[in] BaseBf: The hardware registers struct pointer of TIM module.
 * @param[in] ChannelId:The id of the channel.
 *
 * @return    boolean: If the Pwm channel output Enable.
 * @retval    TRUE: The Pwm channel is software control output Enable.
 * @retval    FALSE: The Pwm channel is software control output disable.
 *
 */
LOCAL_INLINE boolean Tim_Pwm_Drv_GetOutSwCtrState(const Reg_Tim_BfType * BaseBf, uint8 ChannelId)
{
    boolean State = FALSE;
    switch(ChannelId)
    {
        case 0U:
            State = BaseBf->TIM_OUTSWCR.CH0OC;
            break;
        case 1U:
            State = BaseBf->TIM_OUTSWCR.CH1OC;
            break;
        case 2U:
            State = BaseBf->TIM_OUTSWCR.CH2OC;
            break;
        case 3U:
            State = BaseBf->TIM_OUTSWCR.CH3OC;
            break;
        case 4U:
            State = BaseBf->TIM_OUTSWCR.CH4OC;
            break;
        case 5U:
            State = BaseBf->TIM_OUTSWCR.CH5OC;
            break;
        case 6U:
            State = BaseBf->TIM_OUTSWCR.CH6OC;
            break;
        case 7U:
            State = BaseBf->TIM_OUTSWCR.CH7OC;
            break;
        default:
            /* Nothing to do */
            break;
    }

    return State;
}

/**
 * @brief      Get the software control output value of Pwm channel.
 *
 * @param[in] BaseBf: The hardware registers struct pointer of TIM module.
 * @param[in] ChannelId: The id of the channel.
 *
 * @return    boolean: If the software control output value of Pwm channel is High.
 * @retval    TRUE: The software control output value of Pwm channel is High.
 * @retval    FALSE: The software control output value of Pwm channel is Low.
 *
 */
LOCAL_INLINE boolean Tim_Pwm_Drv_GetOutSwCtrVal(const Reg_Tim_BfType * BaseBf, uint8 ChannelId)
{
    boolean State = FALSE;
    switch(ChannelId)
    {
        case 0U:
            State = BaseBf->TIM_OUTSWCR.CH0OCV;
            break;
        case 1U:
            State = BaseBf->TIM_OUTSWCR.CH1OCV;
            break;
        case 2U:
            State = BaseBf->TIM_OUTSWCR.CH2OCV;
            break;
        case 3U:
            State = BaseBf->TIM_OUTSWCR.CH3OCV;
            break;
        case 4U:
            State = BaseBf->TIM_OUTSWCR.CH4OCV;
            break;
        case 5U:
            State = BaseBf->TIM_OUTSWCR.CH5OCV;
            break;
        case 6U:
            State = BaseBf->TIM_OUTSWCR.CH6OCV;
            break;
        case 7U:
            State = BaseBf->TIM_OUTSWCR.CH7OCV;
            break;
        default:
            /* Nothing to do */
            break;
    }
    return State;
}

/**
 * @brief     Set the match trigger of the channel.
 *
 * @param[in] BaseBf: The hardware registers struct pointer for the TIM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Trigger: Enable/Disable the match trigger of the channel. 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Tim_Pwm_Drv_ControlChannelMatchTrigger(Reg_Tim_BfType * BaseBf, uint8 ChannelId, 
                                                    boolean Trigger)
{
    switch(ChannelId)
    {
        case 0U:
            BaseBf->TIM_OUTCR.TRIGE0 = (uint32)Trigger;
            break;
        case 1U:
            BaseBf->TIM_OUTCR.TRIGE1 = (uint32)Trigger;
            break;
        case 2U:
            BaseBf->TIM_OUTCR.TRIGE2 = (uint32)Trigger;
            break;
        case 3U:
            BaseBf->TIM_OUTCR.TRIGE3 = (uint32)Trigger;
            break;
        case 4U:
            BaseBf->TIM_OUTCR.TRIGE4 = (uint32)Trigger;
            break;
        case 5U:
            BaseBf->TIM_OUTCR.TRIGE5 = (uint32)Trigger;
            break;
        case 6U:
            BaseBf->TIM_OUTCR.TRIGE6 = (uint32)Trigger;
            break;
        case 7U:
            BaseBf->TIM_OUTCR.TRIGE7 = (uint32)Trigger;
            break;
        default:
            /* Nothing to do */
            break;
    }
}

/**
 * @brief     Set the software control output value of the channel.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] State: The output value to be set. 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Tim_Pwm_Drv_SetChannelOCV(uint8 TimId, uint8 ChannelId,
                                         Tim_Pwm_Drv_OutputStateType State)
{
    Reg_Tim_BfType *BaseBf = (Reg_Tim_BfType *) Tim_Pwm_Drv_PwmRegBfPtr[TimId];

    SchM_Enter_Pwm_SetTimSoftwareControlRegister();
    switch(ChannelId)
    {
        case 0U:
            BaseBf->TIM_OUTSWCR.CH0OCV = (uint32)State;
            break;
        case 1U:
            BaseBf->TIM_OUTSWCR.CH1OCV = (uint32)State;
            break;
        case 2U:
            BaseBf->TIM_OUTSWCR.CH2OCV = (uint32)State;
            break;
        case 3U:
            BaseBf->TIM_OUTSWCR.CH3OCV = (uint32)State;
            break;
        case 4U:
            BaseBf->TIM_OUTSWCR.CH4OCV = (uint32)State;
            break;
        case 5U:
            BaseBf->TIM_OUTSWCR.CH5OCV = (uint32)State;
            break;
        case 6U:
            BaseBf->TIM_OUTSWCR.CH6OCV = (uint32)State;
            break;
        case 7U:
            BaseBf->TIM_OUTSWCR.CH7OCV = (uint32)State;
            break;
        default:
            /* Nothing to do */
            break;
    }
    SchM_Exit_Pwm_SetTimSoftwareControlRegister();
}

/**
 * @brief     Set the software control output of the channel Enable/disable.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Cmd: Enable/Disable the software control output of the channel. 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Tim_Pwm_Drv_ControlChannelOC(uint8 TimId, uint8 ChannelId, boolean Cmd)
{
    Reg_Tim_BfType *BaseBf = (Reg_Tim_BfType *) Tim_Pwm_Drv_PwmRegBfPtr[TimId];
    
    SchM_Enter_Pwm_SetTimSoftwareControlRegister();
    switch(ChannelId)
    {
        case 0U:
            BaseBf->TIM_OUTSWCR.CH0OC = Cmd;
            break;
        case 1U:
            BaseBf->TIM_OUTSWCR.CH1OC = Cmd;
            break;
        case 2U:
            BaseBf->TIM_OUTSWCR.CH2OC = Cmd;
            break;
        case 3U:
            BaseBf->TIM_OUTSWCR.CH3OC = Cmd;
            break;
        case 4U:
            BaseBf->TIM_OUTSWCR.CH4OC = Cmd;
            break;
        case 5U:
            BaseBf->TIM_OUTSWCR.CH5OC = Cmd;
            break;
        case 6U:
            BaseBf->TIM_OUTSWCR.CH6OC = Cmd;
            break;
        case 7U:
            BaseBf->TIM_OUTSWCR.CH7OC = Cmd;
            break;
        default:
            /* Nothing to do */
            break;
    }
    SchM_Exit_Pwm_SetTimSoftwareControlRegister();
}

/**
 * @brief     Set the complentary/independent output mode of the pair channels.
 *
 * @param[in] BaseBf: The hardware registers struct pointer for the TIM module. 
 * @param[in] PairId: The id of the pair channels. 
 * @param[in] Cmd: The complentary/independent output mode to be set. 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Tim_Pwm_Drv_SetPairCombineCmd(Reg_Tim_BfType * BaseBf, uint8 PairId, boolean Cmd)
{
    switch(PairId)
    {
        case 0U:
            BaseBf->TIM_PCR.COMB0 = Cmd;
            break;
        case 1U:
            BaseBf->TIM_PCR.COMB1 = Cmd;
            break;
        case 2U:
            BaseBf->TIM_PCR.COMB2 = Cmd;
            break;
        case 3U:
            BaseBf->TIM_PCR.COMB3 = Cmd;
            break;
        default:
            /* Nothing to do */
            break;
    }
}

/**
 * @brief     Set the synchronization Enable/disable of the pair channels.
 *
 * @param[in] BaseBf: The hardware registers struct pointer for the TIM module. 
 * @param[in] PairId: The id of the pair channels. 
 * @param[in] Enable: Enable/Disable the synchronization of CV(n) and CV(n+1). 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Tim_Pwm_Drv_ControlPairSynchronization(Reg_Tim_BfType * BaseBf, uint8 PairId,
                                                  boolean Enable)
{
    switch(PairId)
    {
        case 0U:
            BaseBf->TIM_PCR.SYNCEN0 = Enable;
            break;
        case 1U:
            BaseBf->TIM_PCR.SYNCEN1 = Enable;
            break;
        case 2U:
            BaseBf->TIM_PCR.SYNCEN2 = Enable;
            break;
        case 3U:
            BaseBf->TIM_PCR.SYNCEN3 = Enable;
            break;
        default:
            /* Nothing to do */
            break;
    }
}

/**
 * @brief     Update the notification edge type of the pair channel in complementary output mode.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Notification: The edge type for notification to be updated. 
 * 
 * @return   None
 *
 */
static void Tim_Pwm_Drv_UpdateNotificationStateCombine(uint8 TimId, uint8 ChannelId,
                                                    Tim_Pwm_Drv_EdgeNotifType Notification)
{
    uint8 CombineChannelId;
    if((ChannelId % 2U) == 0U)
    {
        CombineChannelId = ChannelId + 1U;
    }
    else
    {
        CombineChannelId = ChannelId - 1U;
    }

    SchM_Enter_Pwm_SetTimNotifIrq();
    switch(Notification)
    {
        case TIM_PWM_DRV_BOTH_EDGES:
            Tim_Pwm_Drv_NotifIrq[TimId][ChannelId] |= TIM_PWM_DRV_CHF_IRQ_EDGE;
            Tim_Pwm_Drv_NotifIrq[TimId][CombineChannelId] |= TIM_PWM_DRV_CHF_COMBINE_IRQ_EDGE;
            break;
        case TIM_PWM_DRV_RISING_EDGE:
            if(TIM_PWM_DRV_POL_LOW == Tim_Pwm_Drv_PolarityState[TimId][ChannelId])
            {
                Tim_Pwm_Drv_NotifIrq[TimId][ChannelId] |= TIM_PWM_DRV_CHF_IRQ_EDGE;
            }
            else
            {
                Tim_Pwm_Drv_NotifIrq[TimId][CombineChannelId] |= TIM_PWM_DRV_CHF_COMBINE_IRQ_EDGE;
            }
            break;
        case TIM_PWM_DRV_FALLING_EDGE:
            if(TIM_PWM_DRV_POL_HIGH == Tim_Pwm_Drv_PolarityState[TimId][ChannelId])
            {
                Tim_Pwm_Drv_NotifIrq[TimId][ChannelId] |= TIM_PWM_DRV_CHF_IRQ_EDGE;
            }
            else
            {
                Tim_Pwm_Drv_NotifIrq[TimId][CombineChannelId] |= TIM_PWM_DRV_CHF_COMBINE_IRQ_EDGE;
            }
            break;
        default:        
            /* Nothing to do */
            break;
    }
    SchM_Exit_Pwm_SetTimNotifIrq();
}

/**
 * @brief     Update the notification edge type of the channel in independent edge output mode.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Notification: The edge type for notification to be updated. 
 * 
 * @return   None
 *
 */
static void Tim_Pwm_Drv_UpdateNotificationStateEdge(uint8 TimId, uint8 ChannelId,
                                            Tim_Pwm_Drv_EdgeNotifType Notification)
{
    SchM_Enter_Pwm_SetTimNotifIrq();
    switch(Notification)
    {
        case TIM_PWM_DRV_BOTH_EDGES:
            Tim_Pwm_Drv_NotifIrq[TimId][ChannelId] |= (Tim_Pwm_Drv_EdgeInterruptType) \
                                        (TIM_PWM_DRV_TOF_IRQ_EDGE | TIM_PWM_DRV_CHF_IRQ_EDGE);
            break;
        case TIM_PWM_DRV_RISING_EDGE:
            if(TIM_PWM_DRV_POL_HIGH == Tim_Pwm_Drv_PolarityState[TimId][ChannelId])
            {
                Tim_Pwm_Drv_NotifIrq[TimId][ChannelId] |= TIM_PWM_DRV_TOF_IRQ_EDGE;
            }
            else
            {
                Tim_Pwm_Drv_NotifIrq[TimId][ChannelId] |= TIM_PWM_DRV_CHF_IRQ_EDGE;
            }
            break;
        case TIM_PWM_DRV_FALLING_EDGE:
            if(TIM_PWM_DRV_POL_LOW == Tim_Pwm_Drv_PolarityState[TimId][ChannelId])
            {
                Tim_Pwm_Drv_NotifIrq[TimId][ChannelId] |= TIM_PWM_DRV_TOF_IRQ_EDGE;
            }
            else
            {
                Tim_Pwm_Drv_NotifIrq[TimId][ChannelId] |= TIM_PWM_DRV_CHF_IRQ_EDGE;
            }
            break;
        default:
            /* Nothing to do */
            break;
    }
    SchM_Exit_Pwm_SetTimNotifIrq();
}

/**
 * @brief     Update the notification edge type of the channel in independent center output mode.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Notification: The edge type for notification to be updated. 
 * 
 * @return   None
 *
 */
static void Tim_Pwm_Drv_UpdateNotificationStateCenter(uint8 TimId, uint8 ChannelId,
                                            Tim_Pwm_Drv_EdgeNotifType Notification)
{
    SchM_Enter_Pwm_SetTimNotifIrq();
    switch(Notification)
    {
        case TIM_PWM_DRV_BOTH_EDGES:
            Tim_Pwm_Drv_NotifIrq[TimId][ChannelId] |= \
                                    (Tim_Pwm_Drv_EdgeInterruptType)TIM_PWM_DRV_CHF_IRQ_EDGE;
            break;
        default:
            /* Nothing to do */
            break;
    }
    SchM_Exit_Pwm_SetTimNotifIrq();
}

/**
 * @brief     Disable the interrupts relate to the channel.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] ChannelId: The id of the channel. 
 * 
 * @return   None
 *
 */
static void Tim_Pwm_Drv_DisableInterrupt(uint8 TimId, uint8 ChannelId)
{
    Reg_Tim_BfType *BaseBf = (Reg_Tim_BfType *) Tim_Pwm_Drv_PwmRegBfPtr[TimId];
    Tim_Pwm_Drv_EdgeInterruptType NotifyState;
    boolean OverFlowFlag = FALSE;
    uint8 Index;

    SchM_Enter_Pwm_SetTimChannelConfigurationRegister();

    /* Channel Int*/
    NotifyState = Tim_Pwm_Drv_NotifIrq[TimId][ChannelId] & \
                            (TIM_PWM_DRV_CHF_IRQ_EDGE |TIM_PWM_DRV_CHF_COMBINE_IRQ_EDGE);
    if(TIM_PWM_DRV_NO_EDGE == NotifyState)
    {
        /* Disable Channel Int*/
        BaseBf->TIM_CMCn[ChannelId].CHIE = FALSE;

    }
    
    /* Clear Channel Int*/
    BaseBf->TIM_CMCn[ChannelId].CHF = 0U;

    SchM_Exit_Pwm_SetTimChannelConfigurationRegister();
    
  

    /* Counter Overflow Int */
    for(Index = 0U; Index < (uint8)TIM_PWM_DRV_CHANNEL_NUM; Index++)
    {
        NotifyState = (Tim_Pwm_Drv_NotifIrq[TimId][Index] & TIM_PWM_DRV_TOF_IRQ_EDGE);
        if(TIM_PWM_DRV_NO_EDGE != NotifyState)
        {
            OverFlowFlag =TRUE;
            break;
        }
    }

    if(FALSE == OverFlowFlag)
    {
        SchM_Enter_Pwm_SetTimGlobalControlRegister();

        /* Disable Counter Overflow Int */
        BaseBf->TIM_GLBCR.TOIE = FALSE;

        SchM_Exit_Pwm_SetTimGlobalControlRegister();
    }

    SchM_Enter_Pwm_SetTimGlobalStatusRegister();

    /* Clear Counter Overflow Int */
    BaseBf->TIM_GLBSR.TOF = 0U;

    SchM_Exit_Pwm_SetTimGlobalStatusRegister();
}

/**
 * @brief     Enable the normal notification case for the channel, contain the overflow interrupt 
 *            and the match interrupt.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] ChannelId: The id of the channel. 
 * 
 * @return   None
 *
 */
static void Tim_Pwm_Drv_SetNormalNotificationCase(uint8 TimId, uint8 ChannelId)
{
    Reg_Tim_BfType * BaseBf = (Reg_Tim_BfType *)Tim_Pwm_Drv_PwmRegBfPtr[TimId];
    Tim_Pwm_Drv_ChannelModeType Mode = Tim_Pwm_Drv_ChannelMode[TimId][ChannelId];
    uint8 CombineChannelId;
    if((ChannelId % 2U) == 0U)
    {
        CombineChannelId = ChannelId + 1U;
    }
    else
    {
        CombineChannelId = ChannelId - 1U;
    }

    /* Overflow Int*/
    if(TIM_PWM_DRV_TOF_IRQ_EDGE == (Tim_Pwm_Drv_NotifIrq[TimId][ChannelId] & \
                                                               TIM_PWM_DRV_TOF_IRQ_EDGE))
    {
        SchM_Enter_Pwm_SetTimGlobalControlRegister();
        BaseBf->TIM_GLBCR.TOIE = TRUE;
        SchM_Exit_Pwm_SetTimGlobalControlRegister();
    }

    SchM_Enter_Pwm_SetTimChannelConfigurationRegister();

    /* Channel Int*/
    if(TIM_PWM_DRV_CHF_IRQ_EDGE == (Tim_Pwm_Drv_NotifIrq[TimId][ChannelId] & \
                                                               TIM_PWM_DRV_CHF_IRQ_EDGE))
    {
        BaseBf->TIM_CMCn[ChannelId].CHIE = TRUE; 
    }

    if(TIM_PWM_DRV_MODE_COMBINE_VARIABLE_EDGE_PLACEMENT == Mode)
    {
        /* Clear Combine Channel Int*/
        BaseBf->TIM_CMCn[CombineChannelId].CHF = 0U;

        if(TIM_PWM_DRV_CHF_COMBINE_IRQ_EDGE == (Tim_Pwm_Drv_NotifIrq[TimId][CombineChannelId] \
                                                     & TIM_PWM_DRV_CHF_COMBINE_IRQ_EDGE))
        {
            BaseBf->TIM_CMCn[CombineChannelId].CHIE = TRUE;
        }
    }
    SchM_Exit_Pwm_SetTimChannelConfigurationRegister();
}

/**
 * @brief     Set the counters config of the TIM module.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] CntCfg: The counters configurations pointer to be configured. 
 * 
 * @return   None
 *
 */
static void Tim_Pwm_Drv_ConfigCounter(uint8 TimId, const Tim_Pwm_Drv_ConfigType * CntCfg)
{
    Reg_Tim_BfType * BaseBf = (Reg_Tim_BfType *)Tim_Pwm_Drv_PwmRegBfPtr[TimId];

    /* Set counter mode */
    BaseBf->TIM_GLBCR.CNTMODE = (uint32)CntCfg->PwmCounterMode;

    /* Set the period of the counter */
    if(TIM_PWM_DRV_COUNTING_UP_AND_DOWN == CntCfg->PwmCounterMode)
    {
        Tim_Pwm_Drv_Period[TimId] = (uint16)CntCfg->PwmPeriod;
        BaseBf->TIM_MOD.MOD = CntCfg->PwmPeriod >> 1U;
    }
    else 
    {
        Tim_Pwm_Drv_Period[TimId] = (uint16)CntCfg->PwmPeriod;
        BaseBf->TIM_MOD.MOD = CntCfg->PwmPeriod - 1U;
    }

    /* Set dead time value */
    BaseBf->TIM_FILTER.DTPS = (uint32)CntCfg->DeadTimeDiv;
    BaseBf->TIM_FILTER.DTVAL = (uint32)CntCfg->DeadTimeVal;
    BaseBf->TIM_OUTCR.INITRIGE = (uint32)CntCfg->InitTrigEn;

#if (TIM_PWM_DRV_NOTIFICATION_SUPPORTED == STD_ON)
    BaseBf->TIM_GLBCR.TOIE = FALSE;
#else
    if(TRUE == CntCfg->OverflowIrqEn)
    {
        BaseBf->TIM_GLBCR.TOIE = TRUE;
        Tim_Pwm_Drv_OverflowIrqCallbacks[TimId] = CntCfg->OverflowCb;
    }
#endif
}

#if (TIM_PWM_DRV_NOTIFICATION_SUPPORTED == STD_ON)
/**
 * @brief     Check if notifications have been enabled in special circumstances.
 *
 * @param[in] TimId: The id of the TIM module.
 * @param[in] ChannelId: The id of the channel.
 *
 * @return    None
 *
 */
static void Tim_Pwm_Drv_SpecialCheckNotification(uint8 TimId, uint8 ChannelId)
{
    SchM_Enter_Pwm_SetTimNotifIrq();
    /* Overflow Int*/
    if (TIM_PWM_DRV_NO_EDGE != (Tim_Pwm_Drv_NotifIrq[TimId][ChannelId] & TIM_PWM_DRV_TOF_IRQ_EDGE))
    {
        /* Close overflow interrupt notification edge */
        Tim_Pwm_Drv_NotifIrq[TimId][ChannelId] |= TIM_PWM_DRV_IRQ_NO_EDGE_NOTIF;
    }
    SchM_Exit_Pwm_SetTimNotifIrq();

    Tim_Pwm_Drv_DisableInterrupt(TimId, ChannelId);
}

/**
 * @brief     Check if notifications are enabled under normal circumstances.
 *
 * @param[in] TimId: The id of the TIM module.
 * @param[in] ChannelId: The id of the channel.
 *
 * @return    None
 *
 */
static void Tim_Pwm_Drv_NormalCheckNotification(uint8 TimId, uint8 ChannelId)
{
    Reg_Tim_BfType * BaseBf = (Reg_Tim_BfType *)Tim_Pwm_Drv_PwmRegBfPtr[TimId];
    Tim_Pwm_Drv_ChannelModeType Mode = Tim_Pwm_Drv_ChannelMode[TimId][ChannelId];
    uint8 CombineChannelId;
    if((ChannelId % 2U) == 0U)
    {
        CombineChannelId = ChannelId + 1U;
    }
    else
    {
        CombineChannelId = ChannelId - 1U;
    }

    SchM_Enter_Pwm_SetTimNotifIrq();
    /* Overflow Int */
    if (TIM_PWM_DRV_NO_EDGE != (Tim_Pwm_Drv_NotifIrq[TimId][ChannelId] & TIM_PWM_DRV_TOF_IRQ_EDGE))
    {
        /* Open overflow interrupt notification edge */
        Tim_Pwm_Drv_NotifIrq[TimId][ChannelId] &= (uint8)(~(TIM_PWM_DRV_IRQ_NO_EDGE_NOTIF));
        SchM_Exit_Pwm_SetTimNotifIrq();

        SchM_Enter_Pwm_SetTimGlobalControlRegister();
        BaseBf->TIM_GLBCR.TOIE = TRUE;
        SchM_Exit_Pwm_SetTimGlobalControlRegister();
    }
    else
    {
        SchM_Exit_Pwm_SetTimNotifIrq();
    }

    SchM_Enter_Pwm_SetTimChannelConfigurationRegister();

    /* Channel Int */
    if(TIM_PWM_DRV_CHF_IRQ_EDGE == (Tim_Pwm_Drv_NotifIrq[TimId][ChannelId] & \
                                                               TIM_PWM_DRV_CHF_IRQ_EDGE))
    {
        BaseBf->TIM_CMCn[ChannelId].CHIE = TRUE;
    }

    if(TIM_PWM_DRV_MODE_COMBINE_VARIABLE_EDGE_PLACEMENT == Mode)
    {
        /* Clear Combine Channel Int */
        BaseBf->TIM_CMCn[CombineChannelId].CHF = 0U;

        if(TIM_PWM_DRV_CHF_COMBINE_IRQ_EDGE == (Tim_Pwm_Drv_NotifIrq[TimId][CombineChannelId] \
                                                     & TIM_PWM_DRV_CHF_COMBINE_IRQ_EDGE))
        {
            BaseBf->TIM_CMCn[CombineChannelId].CHIE = TRUE;
        }
    }
    SchM_Exit_Pwm_SetTimChannelConfigurationRegister();
}

/**
 * @brief     Check if notification is enabled.
 *
 * @param[in] TimId: The id of the TIM module.
 * @param[in] ChannelId: The id of the channel.
 *
 * @return    None
 *
 */
static void Tim_Pwm_Drv_CheckNotification(uint8 TimId, uint8 ChannelId)
{
    /* If duty cycle is 0% or 100% */
    if((0U == Tim_Pwm_Drv_DutyCycle[TimId][ChannelId]) ||
        (Tim_Pwm_Drv_Period[TimId] == Tim_Pwm_Drv_DutyCycle[TimId][ChannelId]))
    {
        Tim_Pwm_Drv_SpecialCheckNotification(TimId, ChannelId);
    }
    /* If duty cycle is not 0% and 100% */
    else
    {
        Tim_Pwm_Drv_NormalCheckNotification(TimId, ChannelId);
    }
}
#endif

/**
 * @brief     Set the counters config of the TIM module.
 *
 * @param[in] ChannelMode: The output pwm mode of the TIM channel. 
 * 
 * @return    Tim_Pwm_Drv_PulsePolarityType
 *              - TIM_PWM_DRV_LOW_PULSE_POL      Tim Channel Pulse Polarity Low
 *              - TIM_PWM_DRV_HIGH_PULSE_POL     Tim Channel Pulse Polarity High
 *
 */
static Tim_Pwm_Drv_PulsePolarityType Tim_Pwm_Drv_SelectChannelPulsePol(
                                            Tim_Pwm_Drv_ChannelModeType ChannelMode)
{
    Tim_Pwm_Drv_PulsePolarityType ChannelPulsePol;
    if((TIM_PWM_DRV_MODE_EDGE_ALIGNED == ChannelMode) || \
                                           (TIM_PWM_DRV_MODE_CENTER_ALIGNED == ChannelMode))
    {
        ChannelPulsePol = TIM_PWM_DRV_HIGH_PULSE_POL;
    }
    else
    {
        ChannelPulsePol = TIM_PWM_DRV_LOW_PULSE_POL;
    }

    return ChannelPulsePol;
}

/**
 * @brief     Initialize the configured channels of TIM module.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] ChCfg: The channels configuration pointer. 
 * 
 * @return   None
 *
 */
static void Tim_Pwm_Drv_InitChannel(uint8 TimId, const Tim_Pwm_Drv_ChannelConfigType * ChCfg)
{
    uint8 ChannelId;
    uint8 PairId; 
    Reg_Tim_WType * BaseW;
    Reg_Tim_BfType * BaseBf;
    Tim_Pwm_Drv_PulsePolarityType ChannelPulsePol;

#if(TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(TIM_PWM_DRV_INSTANCE_NUM > TimId);
    MCALLIB_DEV_ASSERT(NULL_PTR != ChCfg);
#endif

    BaseW = (Reg_Tim_WType *)Tim_Pwm_Drv_PwmRegWPtr[TimId];
    BaseBf = (Reg_Tim_BfType *)Tim_Pwm_Drv_PwmRegBfPtr[TimId];

    ChannelId = ChCfg->ChannelId;
    PairId = ChannelId >> 1UL;
    ChannelPulsePol = Tim_Pwm_Drv_SelectChannelPulsePol(ChCfg->ChannelMode);

    Tim_Pwm_Drv_DutyCycle[TimId][ChannelId] = 0;
    Tim_Pwm_Drv_PolarityState[TimId][ChannelId] = ChCfg->Polarity;

    Tim_Pwm_Drv_SetChannelPolarity(BaseBf, ChannelId, ChCfg->Polarity);
    BaseBf->TIM_CMCn[ChannelId].ELS = (uint32)ChannelPulsePol;
    BaseBf->TIM_CMCn[ChannelId].CMS = (uint32)0x2U;

    Tim_Pwm_Drv_ControlChannelMatchTrigger(BaseBf, ChannelId, ChCfg->ChannelMatchTrigEnable);
    Tim_Pwm_Drv_SetChannelMode(TimId, ChannelId, ChCfg->ChannelMode);
    BaseBf->TIM_CCVn[ChannelId].CCV = 0xFFFFU;

    if(0U == (ChannelId % 2U))
    {
        if(NULL_PTR != ChCfg->PairCfg)
        {
            Tim_Pwm_Drv_PairDeadtimeCmd(BaseBf, PairId, ChCfg->PairCfg->DeadTimeEnable);
            if(TRUE == Tim_Pwm_Drv_GetCombineConfig(BaseBf, ChannelId))
            {
                Tim_Pwm_Drv_PhaseShift[TimId][PairId] = ChCfg->PairCfg->PhaseShiftValue;
            }
        }
    }

    BaseBf->TIM_CMCn[ChannelId].DMAEN = (uint32)ChCfg->DmaEn;

    Tim_Pwm_Drv_SetChannelOCV(TimId, ChannelId, Tim_Pwm_Drv_IdleState[TimId][ChannelId]);
    Tim_Pwm_Drv_ChannelState[TimId][ChannelId] = TIM_PWM_DRV_CHANNEL_RUNNING;

#if (TIM_PWM_DRV_NOTIFICATION_SUPPORTED == STD_ON)
    BaseBf->TIM_CMCn[ChannelId].CHIE = FALSE;
    Tim_Pwm_Drv_ChIrqCallbacks[TimId][ChannelId] = ChCfg->ChannelCb;
    Tim_Pwm_Drv_OverflowIrqCallbacks[TimId][ChannelId] = ChCfg->ChannelCb;
#else
    if(TRUE == ChCfg->ChIrqEn)
    {
        Tim_Pwm_Drv_ChIrqCallbacks[TimId][ChannelId] = ChCfg->ChannelCb;
        BaseBf->TIM_CMCn[ChannelId].CHIE = TRUE;
    }
#endif

    if(TRUE == ChCfg->ChannelOutputEnable)
    {
        /* Enable Channel Output */
        BaseW->TIM_GLBCR |= (0x01UL << (uint32)ChannelId);
    }
    else
    {
        /* Disable Channel Output */
        BaseW->TIM_GLBCR &= ~(0x01UL << (uint32)ChannelId);
    }

    /* Clear Channel Int*/
    BaseBf->TIM_CMCn[ChannelId].CHF = 0U;
        
#if(TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     Initialize the TIM module.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] InstanceCfg: The configuration pointer of the TIM. 
 * 
 * @return   None
 *
 */
static void Tim_Pwm_Drv_InitInstance(uint8 TimId, const Tim_Pwm_Drv_ConfigType * InstanceCfg)
{
#if (TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(TIM_PWM_DRV_INSTANCE_NUM > TimId);
    MCALLIB_DEV_ASSERT(NULL_PTR != InstanceCfg);
#endif

    Tim_Pwm_Drv_ConfigCounter(TimId, InstanceCfg);

    Tim_Pwm_Drv_ClockSource[TimId] = InstanceCfg->ClkSrc;
    Tim_Pwm_Drv_ClockDivide[TimId] = InstanceCfg->ClkDiv;
        
#if(TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     Start to run the TIM module after initialization.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] InstanceCfg: The configuration pointer of the TIM. 
 * 
 * @return   None
 *
 */
void Tim_Pwm_Drv_InitInstanceStart(uint8 TimId, const Tim_Pwm_Drv_ConfigType * InstanceCfg)
{
#if (TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(TIM_PWM_DRV_INSTANCE_NUM > TimId);
    MCALLIB_DEV_ASSERT(NULL_PTR != InstanceCfg);
#endif
    Reg_Tim_BfType * BaseBf = (Reg_Tim_BfType *)Tim_Pwm_Drv_PwmRegBfPtr[TimId];

    /* Clear Timer Overflow Flag */
    BaseBf->TIM_GLBSR.TOF = 0;

    BaseBf->TIM_TIMEBASE.PSDIV = (uint32)InstanceCfg->ClkDiv;
    /* Start Counter */ 
    BaseBf->TIM_TIMEBASE.CKSRC = (uint32)InstanceCfg->ClkSrc;
        
#if(TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

#if (defined(TIM_PWM_DRV_NOTIFICATION_SUPPORTED) && (TIM_PWM_DRV_NOTIFICATION_SUPPORTED == STD_ON))
/**
 * @brief     Set the output of the channel to sepcific state.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] ActiveState: The specific state to be output. 
 * 
 * @return   None
 *
 */
static void Tim_Pwm_Drv_SetOutputForForcedChannel(uint8 TimId, uint8 ChannelId, boolean ActiveState)
{
    Reg_Tim_BfType *BaseBf = (Reg_Tim_BfType *) Tim_Pwm_Drv_PwmRegBfPtr[TimId];
    
    if(TRUE == ActiveState)
    {
        Tim_Pwm_Drv_DisableInterrupt(TimId, ChannelId);
    }
    else
    {
        if(TIM_PWM_DRV_NO_EDGE != (Tim_Pwm_Drv_NotifIrq[TimId][ChannelId] & \
                                                               TIM_PWM_DRV_TOF_IRQ_EDGE))
        {
            SchM_Enter_Pwm_SetTimGlobalControlRegister();
            BaseBf->TIM_GLBCR.TOIE = TRUE;
            SchM_Exit_Pwm_SetTimGlobalControlRegister();
        }
        
        if(TIM_PWM_DRV_NO_EDGE != (Tim_Pwm_Drv_NotifIrq[TimId][ChannelId] & \
                          (TIM_PWM_DRV_CHF_IRQ_EDGE | TIM_PWM_DRV_CHF_COMBINE_IRQ_EDGE)))
        {
            SchM_Enter_Pwm_SetTimChannelConfigurationRegister();
            BaseBf->TIM_CMCn[ChannelId].CHIE = TRUE;
            SchM_Exit_Pwm_SetTimChannelConfigurationRegister();
        }
    }
}
#endif

/**
 * @brief     Update the cycle of the counter.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] Period: The period to be updated. 
 * @param[in] SwTrigger: Enable/Disable update period immediatly. 
 * 
 * @return   None
 *
 */
static void Tim_Pwm_Drv_UpdatePwmPeriod(uint8 TimId, uint32 Period, boolean SwTrigger)
{
    Reg_Tim_BfType * BaseBf;
#if(TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(TimId <TIM_PWM_DRV_INSTANCE_NUM);
#endif

    BaseBf = (Reg_Tim_BfType *)Tim_Pwm_Drv_PwmRegBfPtr[TimId]; 
    Tim_Pwm_Drv_Period[TimId] = (uint16)Period;

    SchM_Enter_Pwm_SetTimModuloValueRegister();
    if(TRUE == BaseBf->TIM_GLBCR.CNTMODE)
    {
        BaseBf->TIM_MOD.MOD = (uint16)(Period >> 1U);
    }
    else
    {
        BaseBf->TIM_MOD.MOD = (uint16)(Period - 1U);
    }

    BaseBf->TIM_RELOAD.LOADEN = (uint32)SwTrigger;

    SchM_Exit_Pwm_SetTimModuloValueRegister();
        
#if(TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

/**
 * @brief     Initialize the driver of TIM module with user configuration generated from AUTOSAR 
 *            code template.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] userCfg: The configuration pointer of user definition. 
 * 
 * @return   None
 *
 */
void Tim_Pwm_Drv_Init(uint8 TimId, const Tim_Pwm_Drv_UserCfgType * userCfg)
{
    uint8 Index;
#if (TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(TIM_PWM_DRV_INSTANCE_NUM > TimId);
    MCALLIB_DEV_ASSERT(NULL_PTR != userCfg);
#endif

    Tim_Pwm_Drv_InitInstance(TimId, userCfg->InstanceCfg);

    for(Index = 0; Index < userCfg->NoOfConfiguredCh; Index++)
    {
        Tim_Pwm_Drv_InitChannel(TimId, userCfg->ConfiguredChArray[Index]);
    }
        
#if(TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     De-initialze the TIM module and reset all registers of TIM.
 *
 * @param[in] TimId: The id of the TIM module. 
 * 
 * @return   None
 *
 */
void Tim_Pwm_Drv_DeInit(uint8 TimId)
{
    Reg_Tim_BfType * BaseBf = (Reg_Tim_BfType *)Tim_Pwm_Drv_PwmRegBfPtr[TimId];
    Reg_Tim_WType * BaseW = (Reg_Tim_WType *)Tim_Pwm_Drv_PwmRegWPtr[TimId];

    /*Stop counter */
    BaseBf->TIM_TIMEBASE.CKSRC = (uint32)TIM_PWM_DRV_CLK_DISABLE;
    
    BaseW->TIM_TIMEBASE = 0x0U;
    BaseW->TIM_CNT = 0x0U;
    BaseW->TIM_CNTINIT = 0x0U;
    BaseW->TIM_MOD = 0x0U;
    (void)BaseW->TIM_GLBCR;
    BaseW->TIM_GLBCR &= 0x0FFU;
    (void)BaseW->TIM_GLBSR;
    BaseW->TIM_GLBSR = 0x0U;
    (void)BaseW->TIM_OUTCR;
    BaseW->TIM_OUTCR = 0x0U;
    BaseW->TIM_PCR = 0x0U;
    BaseW->TIM_FILTER = 0x0U;
    BaseW->TIM_FLTCR = 0x0U;
    (void)BaseW->TIM_FLTSR;
    BaseW->TIM_FLTSR = 0x0U;
    BaseW->TIM_SYNC = 0x0U;
    BaseW->TIM_RELOAD = 0x0U;
    BaseW->TIM_HCV = 0x0U;
    
    for(uint8 Index = 0; Index <TIM_PWM_DRV_CHANNEL_NUM; Index++)
    {
        (void)BaseW->TIM_CMCn[Index];
        BaseW->TIM_CMCn[Index] = 0x0U;
        BaseW->TIM_CCVn[Index] = 0x0U;

        Tim_Pwm_Drv_NotifIrq[TimId][Index] = 0x0U;
    }
}

/**
 * @brief     Update the Pwm dutycycle for the channel of TIM module.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] DutyCycle: The duty cycle to be updated. 
 * @param[in] SwTrigger: If the duty cycle update immediately or not. 
 * 
 * @return   None
 *
 */
void Tim_Pwm_Drv_SetDutyCycle(uint8 TimId, uint8 ChannelId, uint16 DutyCycle, boolean SwTrigger)
{
    uint16 FirstEdge = 0;
    uint8 PairId;
    Tim_Pwm_Drv_ChannelModeType Mode;

    PairId = ChannelId >> 1U;

    Tim_Pwm_Drv_DutyCycle[TimId][ChannelId] = DutyCycle;

    Mode = Tim_Pwm_Drv_ChannelMode[TimId][ChannelId];

#if (TIM_PWM_DRV_NOTIFICATION_SUPPORTED == STD_ON)
    Tim_Pwm_Drv_CheckNotification(TimId, ChannelId);
#endif

    SchM_Enter_Pwm_SetTimChannelState();
    if(TIM_PWM_DRV_CHANNEL_IDLE == Tim_Pwm_Drv_ChannelState[TimId][ChannelId])
    {      
        Tim_Pwm_Drv_ChannelState[TimId][ChannelId] =TIM_PWM_DRV_CHANNEL_RUNNING;
        SchM_Exit_Pwm_SetTimChannelState();

        Tim_Pwm_Drv_SetChannelOCV(TimId, ChannelId, Tim_Pwm_Drv_IdleState[TimId][ChannelId]);
        Tim_Pwm_Drv_ControlChannelOC(TimId, ChannelId, FALSE);
    }
    else
    {
        SchM_Exit_Pwm_SetTimChannelState();
    }

    if(Mode ==TIM_PWM_DRV_MODE_EDGE_ALIGNED)
    {
        (void)Tim_Pwm_Drv_UpdatePwmChannel(TimId, ChannelId, DutyCycle, DutyCycle, SwTrigger); 
    }
    else if(Mode ==TIM_PWM_DRV_MODE_CENTER_ALIGNED)
    {
        (void)Tim_Pwm_Drv_UpdatePwmChannel(TimId, ChannelId, DutyCycle >> 1U, DutyCycle >> 1U, \
                                                                             SwTrigger); 
    }
    else if(Mode ==TIM_PWM_DRV_MODE_COMBINE_VARIABLE_EDGE_PLACEMENT)
    {
        if(0U == DutyCycle)
        {
            (void)Tim_Pwm_Drv_UpdatePwmChannel(TimId, ChannelId, 0, Tim_Pwm_Drv_Period[TimId] + 1U, 
                                                                              SwTrigger);
        }
        else if(DutyCycle == Tim_Pwm_Drv_Period[TimId])
        {
            (void)Tim_Pwm_Drv_UpdatePwmChannel(TimId, ChannelId, DutyCycle, 0, SwTrigger);
        }
        else 
        {
            FirstEdge = Tim_Pwm_Drv_Period[TimId] 
                            + Tim_Pwm_Drv_PhaseShift[TimId][PairId] - DutyCycle;
            (void)Tim_Pwm_Drv_UpdatePwmChannel(TimId, ChannelId, \
                             Tim_Pwm_Drv_PhaseShift[TimId][PairId], FirstEdge, SwTrigger);         
        }
    }
    else
    {
        /* Do Nothing */
    }
}

/**
 * @brief     Update the Pwm period and duty cycle for the channel of TIM module.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Period: The period to be updated. 
 * @param[in] DutyCycle: The duty cycle to be updated. 
 * @param[in] SwTrigger: If the period and duty cycle updated immediately or not. 
 * 
 * @return   None
 *
 */
void Tim_Pwm_Drv_SetPeriodAndDuty(uint8 TimId, uint8 ChannelId, uint16 Period, uint16 DutyCycle,
                                    boolean SwTrigger)
{
    uint16 TempDutyCycle = 0U;
#if (TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(TimId <TIM_PWM_DRV_INSTANCE_NUM);
    MCALLIB_DEV_ASSERT(ChannelId <TIM_PWM_DRV_CHANNEL_NUM);
#endif

    SchM_Enter_Pwm_SetTimChannelState();
    if(TIM_PWM_DRV_CHANNEL_IDLE == Tim_Pwm_Drv_ChannelState[TimId][ChannelId])
    {
        Tim_Pwm_Drv_ChannelState[TimId][ChannelId] =TIM_PWM_DRV_CHANNEL_RUNNING;
        SchM_Exit_Pwm_SetTimChannelState();

        Tim_Pwm_Drv_SetChannelOCV(TimId, ChannelId, Tim_Pwm_Drv_IdleState[TimId][ChannelId]);
        Tim_Pwm_Drv_ControlChannelOC(TimId, ChannelId, FALSE);
    }
    else
    {
        SchM_Exit_Pwm_SetTimChannelState();
    }

    if(0U == Period)
    {
        TempDutyCycle = 0U;
    }
    else
    {
        TempDutyCycle = DutyCycle;
        Tim_Pwm_Drv_UpdatePwmPeriod(TimId, Period, SwTrigger);
    }

    Tim_Pwm_Drv_SetDutyCycle(TimId, ChannelId, TempDutyCycle, SwTrigger);

#if(TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     Set the software output control configuration for the channel.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] State: The software output state of channel when software output control activate. 
 * @param[in] ActiveState: Enable/Disable the software control output. 
 * 
 * @return   None
 *
 */
void Tim_Pwm_Drv_SwOutputControl(uint8 TimId, uint8 ChannelId, Tim_Pwm_Drv_OutputStateType State,
                             boolean ActiveState)
{
#if(TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(TimId <TIM_PWM_DRV_INSTANCE_NUM);
    MCALLIB_DEV_ASSERT(ChannelId <TIM_PWM_DRV_CHANNEL_NUM);
#endif

    if((Tim_Pwm_Drv_ChannelStateType)TIM_PWM_DRV_CHANNEL_IDLE == \
                                              Tim_Pwm_Drv_ChannelState[TimId][ChannelId])
    {
        Tim_Pwm_Drv_DutyCycle[TimId][ChannelId] = (uint16)0U;
#if (defined(TIM_PWM_DRV_NOTIFICATION_SUPPORTED) && (TIM_PWM_DRV_NOTIFICATION_SUPPORTED == STD_ON))
        SchM_Enter_Pwm_SetTimNotifIrq();
        if(TIM_PWM_DRV_NO_EDGE != (Tim_Pwm_Drv_NotifIrq[TimId][ChannelId] & \
                                                               TIM_PWM_DRV_TOF_IRQ_EDGE))
        {
            Tim_Pwm_Drv_NotifIrq[TimId][ChannelId] |= TIM_PWM_DRV_IRQ_NO_EDGE_NOTIF;
        }
        SchM_Exit_Pwm_SetTimNotifIrq();

        Tim_Pwm_Drv_DisableInterrupt(TimId, ChannelId);
    }
    else if((Tim_Pwm_Drv_ChannelStateType)TIM_PWM_DRV_CHANNEL_OUTPUT_FORCED 
                    == Tim_Pwm_Drv_ChannelState[TimId][ChannelId])
    {
        Tim_Pwm_Drv_SetOutputForForcedChannel(TimId, ChannelId, ActiveState);
    }
#else 
    }
#endif
    else
    {
        /* Do Nothing */
    }
    
    Tim_Pwm_Drv_SetChannelOCV(TimId, ChannelId, State);
    Tim_Pwm_Drv_ControlChannelOC(TimId, ChannelId, ActiveState);
    
#if(TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     Get current output state of the channel.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] ChannelId: The id of the channel. 
 * 
 * @return   Tim_Pwm_Drv_OutputStateType: Current output pwm state of the channel.
 * @retval  TIM_PWM_DRV_OUTPUT_STATE_LOW: Current output pwm is low.
 * @retval  TIM_PWM_DRV_OUTPUT_STATE_HIGH: Current output pwm is high.
 *
 */
Tim_Pwm_Drv_OutputStateType Tim_Pwm_Drv_GetOutputState(uint8 TimId, uint8 ChannelId)
{
    Reg_Tim_BfType const * BaseBf;
    boolean OutSwCtrState;
    Tim_Pwm_Drv_PolarityType PolVal;
    boolean ChActive = TRUE;
#if(TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(TIM_PWM_DRV_INSTANCE_NUM > TimId);
    MCALLIB_DEV_ASSERT(TIM_PWM_DRV_CHANNEL_NUM > ChannelId);
#endif
    BaseBf = (Reg_Tim_BfType *)Tim_Pwm_Drv_PwmRegBfPtr[TimId];
   
    if(BaseBf->TIM_TIMEBASE.CKSRC != (uint32)TIM_PWM_DRV_CLK_DISABLE)
    {
        /* counter is running */
        OutSwCtrState = Tim_Pwm_Drv_GetOutSwCtrState(BaseBf, ChannelId);
        if(TRUE == OutSwCtrState)
        { 
            /* channel output software control Enable */              
            ChActive = Tim_Pwm_Drv_GetOutSwCtrVal(BaseBf, ChannelId);
        }            
        else
        { 
            /* channel output software control disable */
            ChActive = Tim_Pwm_Drv_IsChannelOutputActive(TimId, ChannelId);
        }
    }
    else
    {
        /* channel output software control Enable */
        ChActive = Tim_Pwm_Drv_GetOutSwCtrVal(BaseBf, ChannelId); 
    }

    PolVal = Tim_Pwm_Drv_GetChannelPolVal(BaseBf, ChannelId);
    if(TIM_PWM_DRV_POL_LOW == PolVal)
    {
        ChActive = (~ChActive) & 0x1U;
    }
    
#if(TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
    return ((Tim_Pwm_Drv_OutputStateType) ChActive);
}

/**
 * @brief     Disable the match notification of the channel.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] ChannelId: The id of the channel. 
 * 
 * @return   None
 *
 */
void Tim_Pwm_Drv_DisableNotification(uint8 TimId, uint8 ChannelId)
{
    uint8 CombineChannelId;
    Tim_Pwm_Drv_ChannelModeType Mode;
#if(TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(TIM_PWM_DRV_INSTANCE_NUM > TimId);
    MCALLIB_DEV_ASSERT(TIM_PWM_DRV_CHANNEL_NUM > ChannelId);
#endif
    if((ChannelId % 2U) == 0U)
    {
        CombineChannelId = ChannelId + 1U;
    }
    else
    {
        CombineChannelId = ChannelId - 1U;
    }

    Mode = Tim_Pwm_Drv_ChannelMode[TimId][ChannelId];

    if(TIM_PWM_DRV_MODE_COMBINE_VARIABLE_EDGE_PLACEMENT == Mode)
    {
        SchM_Enter_Pwm_SetTimNotifIrq();
        Tim_Pwm_Drv_NotifIrq[TimId][ChannelId] &= TIM_PWM_DRV_CHF_COMBINE_IRQ_EDGE;
        Tim_Pwm_Drv_NotifIrq[TimId][CombineChannelId] &= (~TIM_PWM_DRV_CHF_COMBINE_IRQ_EDGE);
        SchM_Exit_Pwm_SetTimNotifIrq();

        Tim_Pwm_Drv_DisableInterrupt(TimId, ChannelId);
        Tim_Pwm_Drv_DisableInterrupt(TimId, CombineChannelId);
    }
    else
    {
        Tim_Pwm_Drv_NotifIrq[TimId][ChannelId] = TIM_PWM_DRV_NO_EDGE;
        Tim_Pwm_Drv_DisableInterrupt(TimId, ChannelId);
    }
        
#if(TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     Enable the notification for  the channel.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Notification: The notification to be enabled. 
 * 
 * @return   None
 *
 */
void Tim_Pwm_Drv_EnableNotification(uint8 TimId, uint8 ChannelId,
                                Tim_Pwm_Drv_EdgeNotifType Notification)
{
    Tim_Pwm_Drv_ChannelModeType Mode;
#if(TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(TIM_PWM_DRV_INSTANCE_NUM > TimId);
    MCALLIB_DEV_ASSERT(TIM_PWM_DRV_CHANNEL_NUM > ChannelId);
#endif
    
    Reg_Tim_BfType *BaseBf = (Reg_Tim_BfType *) Tim_Pwm_Drv_PwmRegBfPtr[TimId];
    
    SchM_Enter_Pwm_SetTimNotifIrq();
    Tim_Pwm_Drv_NotifIrq[TimId][ChannelId] &= (uint8)(~(TIM_PWM_DRV_CHF_IRQ_EDGE | 
                                                              TIM_PWM_DRV_TOF_IRQ_EDGE));
    SchM_Exit_Pwm_SetTimNotifIrq();

    SchM_Enter_Pwm_SetTimChannelConfigurationRegister();
    /* Clear Channel Int */
    BaseBf->TIM_CMCn[ChannelId].CHF = 0U;
    SchM_Exit_Pwm_SetTimChannelConfigurationRegister();

    SchM_Enter_Pwm_SetTimGlobalStatusRegister();
    /* Clear Counter Overflow Int */
    BaseBf->TIM_GLBSR.TOF = 0U;
    SchM_Exit_Pwm_SetTimGlobalStatusRegister();

    Mode = Tim_Pwm_Drv_ChannelMode[TimId][ChannelId];
    if(TIM_PWM_DRV_MODE_EDGE_ALIGNED == Mode)
    {
        Tim_Pwm_Drv_UpdateNotificationStateEdge(TimId, ChannelId, Notification);
    }
    else if(TIM_PWM_DRV_MODE_CENTER_ALIGNED == Mode)
    {
        Tim_Pwm_Drv_UpdateNotificationStateCenter(TimId, ChannelId, Notification);
    }
    else
    {
        /* TIM_PWM_DRV_MODE_COMBINE_VARIABLE_EDGE_PLACEMENT == Mode */
        Tim_Pwm_Drv_UpdateNotificationStateCombine(TimId, ChannelId, Notification);
    }

    if((0U != Tim_Pwm_Drv_DutyCycle[TimId][ChannelId]) &&
        (Tim_Pwm_Drv_Period[TimId] != Tim_Pwm_Drv_DutyCycle[TimId][ChannelId]))
    {
        Tim_Pwm_Drv_SetNormalNotificationCase(TimId, ChannelId);
    }
    else
    {
        SchM_Enter_Pwm_SetTimNotifIrq();
        Tim_Pwm_Drv_NotifIrq[TimId][ChannelId] |= TIM_PWM_DRV_IRQ_NO_EDGE_NOTIF;
        SchM_Exit_Pwm_SetTimNotifIrq();

        Tim_Pwm_Drv_DisableInterrupt(TimId, ChannelId);
    }
        
#if(TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     Update the duty cycle when channel output in variable edge placement mode.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] FirstEdge: The first edge to start of the active state of PWM. 
 * @param[in] SecondEdge: The second edge to end of the active state of PWM. 
 * @param[in] SwTrigger: Enable/Disable update the dutycycle immediatly. 
 * 
 * @return   None
 *
 */
static Tim_Pwm_Drv_StatusType Tim_Pwm_Drv_UpdatePwmChannel(uint8 TimId, uint8 ChannelId, uint16 FirstEdge, 
                                            uint16 SecondEdge, boolean SwTrigger)
{
    Reg_Tim_BfType * BaseBf;
    Tim_Pwm_Drv_StatusType RetStatus =TIM_PWM_DRV_STATUS_SUCCESS;
    uint8 PairId = ChannelId >> 1UL;

#if(TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(TimId <TIM_PWM_DRV_INSTANCE_NUM);
    MCALLIB_DEV_ASSERT(ChannelId <TIM_PWM_DRV_CHANNEL_NUM);
#endif

    BaseBf = (Reg_Tim_BfType *)Tim_Pwm_Drv_PwmRegBfPtr[TimId];

    if(TRUE == Tim_Pwm_Drv_GetDualCombineCmd(BaseBf, PairId))
    {     
        SchM_Enter_Pwm_SetTimCompValueRegister();
        BaseBf->TIM_CCVn[PairId << 1U].CCV = (uint32)FirstEdge;
        BaseBf->TIM_CCVn[(PairId << 1U) + 1U].CCV = (uint32)SecondEdge;
        SchM_Exit_Pwm_SetTimCompValueRegister();

        Tim_Pwm_Drv_ControlChannelOC(TimId, PairId << 1U, FALSE);
        Tim_Pwm_Drv_ControlChannelOC(TimId, (PairId << 1U) + 1U, FALSE);       
    }
    else /* if(FALSE == Tim_Pwm_Drv_GetDualCombineCmd(BaseBf, PairId)) */
    {
        SchM_Enter_Pwm_SetTimCompValueRegister();
        BaseBf->TIM_CCVn[ChannelId].CCV = (uint32)FirstEdge;
        SchM_Exit_Pwm_SetTimCompValueRegister();

        Tim_Pwm_Drv_ControlChannelOC(TimId, ChannelId, FALSE);
    }

    SchM_Enter_Pwm_SetTimReloadRegister();
    BaseBf->TIM_RELOAD.LOADEN = (uint32)SwTrigger;
    SchM_Exit_Pwm_SetTimReloadRegister();

#if(TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
    return RetStatus;
}

/**
 * @brief     Set the period and start of the active state of PWM output while channel worked in 
 *            variable edge placement output mode.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Period: The period to be set. 
 * @param[in] PhaseShift: The start of the active state of PWM output to be set. 
 * @param[in] SoftwareShift: Enable/Disable the configuration updated immediately. 
 * 
 * @return   None
 *
 */
void Tim_Pwm_Drv_SetPhaseShift(uint8 TimId, uint8 ChannelId, uint16 Period, uint16 PhaseShift,
                           boolean SoftwareShift)
{
    uint8 PairId;
    uint16 DutyCycleVal;
    Reg_Tim_BfType * BaseBf;
#if(TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    Tim_Pwm_Drv_ChannelModeType Mode;
    uint16 ChCV = 0U;
    boolean CheckChMode = TRUE;
    boolean RetVal = TRUE;

    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(TIM_PWM_DRV_INSTANCE_NUM > TimId);
    MCALLIB_DEV_ASSERT(TIM_PWM_DRV_CHANNEL_NUM > ChannelId);

    Mode = Tim_Pwm_Drv_ChannelMode[TimId][ChannelId];

    if(TIM_PWM_DRV_MODE_COMBINE_VARIABLE_EDGE_PLACEMENT != Mode)
    {
        CheckChMode = FALSE;
    }

    MCALLIB_DEV_ASSERT(FALSE != CheckChMode);

    ChCV = PhaseShift + (uint16)(Period >> 1U);

    if((ChCV <= PhaseShift) || (Period <= ChCV))
    {
        RetVal = FALSE;
    }
    MCALLIB_DEV_ASSERT(RetVal != FALSE);
    (void)CheckChMode;
    (void)RetVal;
#endif
    PairId = ChannelId >> 1U;

    BaseBf = (Reg_Tim_BfType *)Tim_Pwm_Drv_PwmRegBfPtr[TimId];
    Tim_Pwm_Drv_Period[TimId] = Period;

    SchM_Enter_Pwm_SetTimModuloValueRegister();
    if(TRUE == BaseBf->TIM_GLBCR.CNTMODE)
    {
        BaseBf->TIM_MOD.MOD = (Period >> 1U);
    }
    else
    {
        BaseBf->TIM_MOD.MOD = Period - 1U;
    }
    SchM_Exit_Pwm_SetTimModuloValueRegister();

    DutyCycleVal = (uint16)(Period >> 1U);
    Tim_Pwm_Drv_DutyCycle[TimId][ChannelId] = DutyCycleVal;

    SchM_Enter_Pwm_SetTimCompValueRegister();
    BaseBf->TIM_CCVn[PairId << 1U].CCV = (uint32)PhaseShift;
    BaseBf->TIM_CCVn[(PairId << 1U) + 1U].CCV = (uint32)PhaseShift + (uint32)DutyCycleVal;
    SchM_Exit_Pwm_SetTimCompValueRegister();

    SchM_Enter_Pwm_SetTimReloadRegister();
    BaseBf->TIM_RELOAD.LOADEN = (uint32)SoftwareShift;
    SchM_Exit_Pwm_SetTimReloadRegister();

#if(TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     Set the duty cycle of PWM output while channel worked in variable edge placement 
 *            output mode.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] DutyCycle: The dutycycle to be set. 
 * @param[in] PhaseShift: The start of the active state of PWM output to be set. 
 * @param[in] SotfwareTrigger: Enable/Disable the configuration updated immediately. 
 * 
 * @return   None
 *
 */
void Tim_Pwm_Drv_SetDutyPhaseShift(uint8 TimId, uint8 ChannelId, uint16 DutyCycle,
                               uint16 PhaseShift, boolean SotfwareTrigger)
{
    uint16 FirstEdge = 0U;
    uint16 SecondEdge = 0U;
    uint8 PairId = ChannelId >> 1U;
#if(TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    Tim_Pwm_Drv_ChannelModeType Mode;
    uint16 ChCV = 0U;
    boolean CheckChMode = TRUE;
    boolean RetVal = TRUE;

    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(TIM_PWM_DRV_INSTANCE_NUM > TimId);
    MCALLIB_DEV_ASSERT(TIM_PWM_DRV_CHANNEL_NUM > ChannelId);

    Mode = Tim_Pwm_Drv_ChannelMode[TimId][ChannelId];

    if(TIM_PWM_DRV_MODE_COMBINE_VARIABLE_EDGE_PLACEMENT != Mode)
    {
        CheckChMode = FALSE;
    }

    MCALLIB_DEV_ASSERT(CheckChMode != FALSE);

    if((Tim_Pwm_Drv_Period[TimId] != DutyCycle) && (DutyCycle != 0U))
    {
        ChCV = PhaseShift + Tim_Pwm_Drv_Period[TimId] - DutyCycle;
        if((ChCV <= PhaseShift) || (Tim_Pwm_Drv_Period[TimId] <= ChCV))
        {
            RetVal = FALSE;
        }
    }
    MCALLIB_DEV_ASSERT(RetVal != FALSE);
    (void)CheckChMode;
    (void)RetVal;
#endif

    Tim_Pwm_Drv_PhaseShift[TimId][PairId] = PhaseShift;
    Tim_Pwm_Drv_DutyCycle[TimId][ChannelId] = DutyCycle;

    if(0U == PhaseShift)
    {
        FirstEdge = 1U;
    }
    else
    {
        FirstEdge = PhaseShift;
    }

    if(Tim_Pwm_Drv_Period[TimId] == DutyCycle)
    {
        SecondEdge = Tim_Pwm_Drv_PhaseShift[TimId][PairId];
    }
    else if (0U == DutyCycle)
    {
        SecondEdge = Tim_Pwm_Drv_Period[TimId];
    }
    else
    {
        SecondEdge = Tim_Pwm_Drv_PhaseShift[TimId][PairId] + Tim_Pwm_Drv_Period[TimId] - DutyCycle;
    }

    (void)Tim_Pwm_Drv_UpdatePwmChannel(TimId, ChannelId, FirstEdge, SecondEdge, SotfwareTrigger);
        
#if(TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     This function is used to get current duty cycle of the channel 
 *
 * @param[in] TimId:     The id of the TIM module. 
 * @param[in] ChannelId: The id of the channel. 
 *
 * @return    uint16     DutyCyclePu of the specified logic channel
 */
uint16 Tim_Pwm_Drv_GetChannelDutyCycle(uint8 TimId, uint8 ChannelId)
{
    uint32 DutyCyclePu = (uint16)0U;
#if(TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(TIM_PWM_DRV_INSTANCE_NUM > TimId);
    MCALLIB_DEV_ASSERT(TIM_PWM_DRV_CHANNEL_NUM > ChannelId);
#endif
    Reg_Tim_BfType const * BaseBf = (Reg_Tim_BfType *)Tim_Pwm_Drv_PwmRegBfPtr[TimId];
    Tim_Pwm_Drv_ChannelModeType Mode = Tim_Pwm_Drv_ChannelMode[TimId][ChannelId];
    uint8 PairlId = ChannelId >> 1U;
    uint32 PeriodValue;
    uint32 CompValue;

    if(FALSE == Tim_Pwm_Drv_GetOutSwCtrState(BaseBf, ChannelId))
    {
        if(TIM_PWM_DRV_MODE_COMBINE_VARIABLE_EDGE_PLACEMENT == Mode)
        {
            PeriodValue = BaseBf->TIM_MOD.MOD + 1UL;
            CompValue = BaseBf->TIM_CCVn[(PairlId << 1U) + 1U].CCV;
            if(CompValue > BaseBf->TIM_CCVn[PairlId << 1U].CCV)
            {
                CompValue = CompValue - BaseBf->TIM_CCVn[PairlId << 1U].CCV;
            }
            else
            {
                CompValue = 0U;
            }

            if(CompValue > PeriodValue)
            {
                CompValue = PeriodValue;
            }

            if((ChannelId % 2U) == 0U)
            {
                CompValue = PeriodValue - CompValue;
            }
        }
        else if(TIM_PWM_DRV_MODE_EDGE_ALIGNED == Mode)
        {
            PeriodValue = BaseBf->TIM_MOD.MOD + 1UL;
            CompValue = BaseBf->TIM_CCVn[ChannelId].CCV;
        }
        else
        {
            PeriodValue = BaseBf->TIM_MOD.MOD;
            CompValue = BaseBf->TIM_CCVn[ChannelId].CCV;
        }

        DutyCyclePu = CompValue * 0x8000U / PeriodValue;
    }
        
#if(TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif    

    return (uint16)DutyCyclePu;
}

/**
 * @brief     Set the dead time value for the counter
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] DeadTimeVal: The dead time value be set. 
 * 
 * @return   None
 *
 */
void Tim_Pwm_Drv_SetCounterDeadTime(uint8 TimId,uint16 DeadTimeVal)
{
    Reg_Tim_BfType * BaseBf;
#if(TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(TIM_PWM_DRV_INSTANCE_NUM > TimId);
    MCALLIB_DEV_ASSERT(((DeadTimeVal < 64U) && (DeadTimeVal > 0U)))
#endif
    BaseBf = (Reg_Tim_BfType *)Tim_Pwm_Drv_PwmRegBfPtr[TimId];

    SchM_Enter_Pwm_SetTimFilterRegister();
    BaseBf->TIM_FILTER.DTVAL = (uint32)DeadTimeVal;
    SchM_Exit_Pwm_SetTimFilterRegister();
        
#if(TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     Enable the triggers that triggerMask activated.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] TriggerMask: The triggers activated mask. 
 * 
 * @return   None
 *
 */
void Tim_Pwm_Drv_EnableTrigger(uint8 TimId, uint32 TriggerMask)
{
    Reg_Tim_WType * BaseW;
    uint32 Reg;
    uint32 Mask;
#if(TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(TIM_PWM_DRV_INSTANCE_NUM > TimId);
#endif
    BaseW = (Reg_Tim_WType*) Tim_Pwm_Drv_PwmRegWPtr[TimId];

    SchM_Enter_Pwm_SetTimOutputControlRegister();
    
    Mask = TriggerMask & 0x1FFU;
    Reg = BaseW->TIM_OUTCR;
    Reg |= (Mask << TIM_OUTCR_TRIGE_SHIFT);
    BaseW->TIM_OUTCR = Reg;

    SchM_Exit_Pwm_SetTimOutputControlRegister();
        
#if(TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     Disable the triggers that triggerMask activated.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] TriggerMask: The triggers activated mask. 
 * 
 * @return   None
 *
 */
void Tim_Pwm_Drv_DisableTrigger(uint8 TimId, uint32 TriggerMask)
{
    Reg_Tim_WType * BaseW;
    uint32 Reg;
    uint32 Mask;
#if(TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(TIM_PWM_DRV_INSTANCE_NUM > TimId);
#endif
    BaseW = (Reg_Tim_WType *)Tim_Pwm_Drv_PwmRegWPtr[TimId];

    SchM_Enter_Pwm_SetTimOutputControlRegister();

    Mask = TriggerMask & 0x1FFU;
    Reg = BaseW->TIM_OUTCR;
    Reg &= ~(Mask << TIM_OUTCR_TRIGE_SHIFT);
    BaseW->TIM_OUTCR = Reg;

    SchM_Exit_Pwm_SetTimOutputControlRegister();
        
#if(TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     Enable the reload mechanism of TIM module.
 *
 * @param[in] TimId: The id of the TIM module. 
 * 
 * @return   None
 *
 */
void Tim_Pwm_Drv_SyncUpdate(uint8 TimId)
{
    Reg_Tim_BfType *BaseBf = (Reg_Tim_BfType *) Tim_Pwm_Drv_PwmRegBfPtr[TimId];

    SchM_Enter_Pwm_SetTimReloadRegister();
    BaseBf->TIM_RELOAD.LOADEN = TRUE;
    SchM_Exit_Pwm_SetTimReloadRegister();
}

/**
 * @brief     Disable the channel output as mask activate.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] ChannelMask: The channel to be masked. 
 * 
 * @return   None
 *
 */
void Tim_Pwm_Drv_MaskOutputChannels(uint8 TimId, uint32 ChannelMask)
{
    Reg_Tim_WType *BaseW = (Reg_Tim_WType *) Tim_Pwm_Drv_PwmRegWPtr[TimId];

    SchM_Enter_Pwm_SetTimGlobalControlRegister();

    ChannelMask &= (uint32) 0xff;
    BaseW->TIM_GLBCR &= ~ChannelMask;

    SchM_Exit_Pwm_SetTimGlobalControlRegister();
}

/**
 * @brief     Unmask the output of the channel.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] ChannelMask: The channel to be unmasked. 
 * 
 * @return   None
 *
 */
void Tim_Pwm_Drv_UnMaskOutputChannels(uint8 TimId, uint32 ChannelMask)
{
    Reg_Tim_WType *BaseW = (Reg_Tim_WType *) Tim_Pwm_Drv_PwmRegWPtr[TimId];

    SchM_Enter_Pwm_SetTimGlobalControlRegister();

    ChannelMask &= (uint32) 0xff;
    BaseW->TIM_GLBCR |= ChannelMask;

    SchM_Exit_Pwm_SetTimGlobalControlRegister();
}

/**
 * @brief     Set the power state of the TIM module.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] PowerState: The power state to be set. 
 * 
 * @return   None
 *
 */
void Tim_Pwm_Drv_SetPowerState(uint8 TimId, Tim_Pwm_Drv_PowerStateType PowerState)
{
#if(TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(TIM_PWM_DRV_INSTANCE_NUM > TimId);
#endif 

    Reg_Tim_BfType * BaseBf = (Reg_Tim_BfType *)Tim_Pwm_Drv_PwmRegBfPtr[TimId];
   
    if(TIM_PWM_DRV_LOW_POWER == PowerState)
    {
        for(uint8 ChannelId = 0U;ChannelId < 8U;ChannelId++)
        {
            Tim_Pwm_Drv_OutputStateType SwCtrlValue = Tim_Pwm_Drv_IdleState[TimId][ChannelId];
            Tim_Pwm_Drv_SetCurrentChannelState(TimId,ChannelId,TIM_PWM_DRV_CHANNEL_IDLE);
            Tim_Pwm_Drv_SwOutputControl(TimId,ChannelId,SwCtrlValue,TRUE);
        }            
        
        SchM_Enter_Pwm_SetTimTimeRegister();
        /* Stop counter */
        BaseBf->TIM_TIMEBASE.CKSRC = (uint32)TIM_PWM_DRV_CLK_DISABLE;
        SchM_Exit_Pwm_SetTimTimeRegister();
        
        SchM_Enter_Pwm_SetTimCounterRegister();
        /* Clear counter */
        BaseBf->TIM_CNT.CNT = 0U;
        SchM_Exit_Pwm_SetTimCounterRegister();
    }
    else
    {
        SchM_Enter_Pwm_SetTimTimeRegister();
        /* Start Counter */
        BaseBf->TIM_TIMEBASE.PSDIV = (uint32)Tim_Pwm_Drv_ClockDivide[TimId];
        BaseBf->TIM_TIMEBASE.CKSRC = (uint32)Tim_Pwm_Drv_ClockSource[TimId];
        SchM_Exit_Pwm_SetTimTimeRegister();
    }
        
#if(TIM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     Get current output pwm mode of the channel.
 *
 * @param[in] TimId: The id of the TIM module. 
 * @param[in] ChannelId: The id of the channel. 
 * 
 * @return  Tim_Pwm_Drv_ChannelModeType: Current output pwm mode of the channel.
 * @retval  TIM_PWM_DRV_MODE_EDGE_ALIGNED: Current output mode is independent edge aligned.
 * @retval  TIM_PWM_DRV_MODE_CENTER_ALIGNED: Current output mode is independent center aligned.
 * @retval  TIM_PWM_DRV_MODE_COMBINE_VARIABLE_EDGE_PLACEMENT: Current output pwm mode is 
 *                                           complementary variable edge placement mode.
 *
 */
Tim_Pwm_Drv_ChannelModeType Tim_Pwm_Drv_GetChannelMode(uint8 TimId, uint8 ChannelId)
{
    return Tim_Pwm_Drv_ChannelMode[TimId][ChannelId];
}

/**
 * @brief     Get current state of the channel.
 *
 * @param[in] TimId: The id of TIM module.
 * @param[in] ChannelId: The id of the channel.
 *
 * @return   Current State of the channel.
 * @retval  TIM_PWM_DRV_CHANNEL_UNINIT: The Channel is uniniatialized.
 * @retval  TIM_PWM_DRV_CHANNEL_RUNNING: The Channel is running.
 * @retval  TIM_PWM_DRV_CHANNEL_IDLE: The Channel is in idle state.
 * @retval  TIM_PWM_DRV_CHANNEL_OUTPUT_FORCED: The Channel is in forced output state.
 *
 */
Tim_Pwm_Drv_ChannelStateType Tim_Pwm_Drv_GetCurrentChannelState(uint8 TimId, uint8 ChannelId)
{
    return Tim_Pwm_Drv_ChannelState[TimId][ChannelId];
}

/**
 * @brief     Set current state of the channel.
 *
 * @param[in] TimId: The id of TIM module.
 * @param[in] ChannelId: The id of the channel.
 * @param[in] State: The target state of the channel.
 *
 * @return   None
 *
 */
void Tim_Pwm_Drv_SetCurrentChannelState(uint8 TimId, uint8 ChannelId, 
                                    Tim_Pwm_Drv_ChannelStateType State)
{
    SchM_Enter_Pwm_SetTimChannelState();
    Tim_Pwm_Drv_PreviousChannelState[TimId][ChannelId] = Tim_Pwm_Drv_ChannelState[TimId][ChannelId];
    Tim_Pwm_Drv_ChannelState[TimId][ChannelId] = State;
    SchM_Exit_Pwm_SetTimChannelState();
}

/**
 * @brief     Revert current state of the channel.
 *
 * @param[in] TimId: The id of TIM module.
 * @param[in] ChannelId: The id of the channel.
 *
 * @return   None
 *
 */
void Tim_Pwm_Drv_RevertCurrentChannelState(uint8 TimId, uint8 ChannelId)
{
    Tim_Pwm_Drv_ChannelState[TimId][ChannelId] = Tim_Pwm_Drv_PreviousChannelState[TimId][ChannelId];
}

/**
 * @brief     Get current notif type of the channel.
 *
 * @param[in] TimId: The id of TIM module.
 * @param[in] ChannelId: The id of the channel.
 *
 * @return   None
 *
 */
Tim_Pwm_Drv_EdgeInterruptType Tim_Pwm_Drv_GetNotifFlag(uint8 TimId, uint8 ChannelId)
{
    return Tim_Pwm_Drv_NotifIrq[TimId][ChannelId];
}

/**
 * @brief     Get current period of the counter.
 *
 * @param[in] TimId: The id of TIM module.
 *
 * @return    uint16 : Current period of the counter. 
 *
 */
uint16 Tim_Pwm_Drv_GetPeriod(uint8 TimId)
{
    return Tim_Pwm_Drv_Period[TimId];
}

/**
 * @brief     Set current output mode of the channel.
 *
 * @param[in] TimId: The id of TIM module.
 * @param[in] ChannelId: The id of the channel.
 * @param[in] Mode: The output mode of the channel.
 *
 * @return   None
 *
 */
static void Tim_Pwm_Drv_SetChannelMode(uint8 TimId, uint8 ChannelId, Tim_Pwm_Drv_ChannelModeType Mode)
{
    Reg_Tim_BfType *BaseBf = (Reg_Tim_BfType *)Tim_Pwm_Drv_PwmRegBfPtr[TimId];

    switch(Mode)
    {
        case TIM_PWM_DRV_MODE_EDGE_ALIGNED:
            Tim_Pwm_Drv_SetPairCombineCmd(BaseBf, (ChannelId >> 1), FALSE);
            break;
        case TIM_PWM_DRV_MODE_CENTER_ALIGNED:
            Tim_Pwm_Drv_SetPairCombineCmd(BaseBf, (ChannelId >> 1), FALSE);
            break;
        case TIM_PWM_DRV_MODE_COMBINE_VARIABLE_EDGE_PLACEMENT:
            Tim_Pwm_Drv_SetPairCombineCmd(BaseBf, (ChannelId >> 1), TRUE);
            break;
        default:
            /* Nothing to do */
            break;
    }

    Tim_Pwm_Drv_ChannelMode[TimId][ChannelId] = Mode; 
}

/**
 * @brief     Get current complementary config of the channel.
 *
 * @param[in] BaseBf: The hardware registers struct pointer for the TIM module. 
 * @param[in] ChannelId: The id of the channel.
 *
 * @return   boolean : The complementary is enable or disable.
 * @retval   TRUE: The complementary is enable.
 * @retval   FALSE: The complementary is disable.
 *
 */
LOCAL_INLINE boolean Tim_Pwm_Drv_GetCombineConfig(const Reg_Tim_BfType * BaseBf, uint8 ChannelId)
{
    uint8 PairId = ChannelId >> 1U;
    uint32 CombineConfig = 0;

    switch(PairId)
    {
        case 0:
            CombineConfig = BaseBf->TIM_PCR.COMB0;
            break;
        case 1:
            CombineConfig = BaseBf->TIM_PCR.COMB1;
            break;
        case 2:
            CombineConfig = BaseBf->TIM_PCR.COMB2;
            break;
        case 3:
            CombineConfig = BaseBf->TIM_PCR.COMB3;
            break;
        default:
            /* Nothing to do */
            break;
    }

    return (boolean)CombineConfig;

}

/**
 * @brief     Software trig the sync of registers for MOD and CCV.
 *
 * @param[in] TimId: The id of TIM module.
 *
 * @return    None 
 *
 */
void Tim_Pwm_Drv_SoftwareUpdate(uint8 TimId)
{
    Reg_Tim_BfType *BaseBf = (Reg_Tim_BfType *)Tim_Pwm_Drv_PwmRegBfPtr[TimId];

    BaseBf->TIM_SYNC.SWWRBUF = TRUE;
    BaseBf->TIM_SYNC.SWRSTCNT = TRUE;

    Tim_Pwm_Drv_ControlPairSynchronization(BaseBf, 0U, TRUE);
    Tim_Pwm_Drv_ControlPairSynchronization(BaseBf, 1U, TRUE);
    Tim_Pwm_Drv_ControlPairSynchronization(BaseBf, 2U, TRUE);
    Tim_Pwm_Drv_ControlPairSynchronization(BaseBf, 3U, TRUE);

    BaseBf->TIM_SYNC.SWTRIG = (uint32)TRUE;
}

/**
 * @brief     Software triggered, updated immediately after service call.
 *
 * @param[in] TimId: The id of Tim module.
 *
 * @return    None 
 *
 */
void Tim_Pwm_Drv_UpdateNow(uint8 TimId)
{
    Reg_Tim_BfType *BaseBf = (Reg_Tim_BfType *)Tim_Pwm_Drv_PwmRegBfPtr[TimId];
    
    SchM_Enter_Pwm_SetTimSyncRegister();
    
    BaseBf->TIM_SYNC.SWTRIG = (uint32)TRUE;
    
    SchM_Exit_Pwm_SetTimSyncRegister();
}

/**
 * @brief     Init the idle output state of the channel.
 *
 * @param[in] ModuleId: The id of TIM module.
 * @param[in] ChannelId: The id of channel.
 * @param[in] State: The idle output state to be set.
 *
 * @return    None 
 *
 */
void Tim_Pwm_Drv_InitIdleState(uint8 ModuleId, uint8 ChannelId, Tim_Pwm_Drv_OutputStateType State)
{
    Tim_Pwm_Drv_IdleState[ModuleId][ChannelId] = State;
}

/**
 * @brief     Get the idle output state of the channel.
 *
 * @param[in] TimId: The id of TIM module.
 * @param[in] ChannelId: The id of channel.
 *
 * @return    Tim_Pwm_Drv_OutputStateType  current idle output state of the channel
 * @retval    - TIM_PWM_DRV_OUTPUT_STATE_LOW   Current idle output state is low
 * @retval    - TIM_PWM_DRV_OUTPUT_STATE_HIGH  Current idle output state is high
 *
 */
Tim_Pwm_Drv_OutputStateType Tim_Pwm_Drv_GetIdleState(uint8 TimId, uint8 ChannelId)
{
    return Tim_Pwm_Drv_IdleState[TimId][ChannelId];
}

/**
 * @brief     Processing overflow interrupt.
 *
 * @param[in] TimId: The id of the TIM module. 
 * 
 * @return    None
 *
 */
void Tim_Pwm_Drv_ProcessTofInterrupt(uint8 TimId)
{
    Reg_Tim_BfType * BaseBf = (Reg_Tim_BfType *)Tim_Pwm_Drv_PwmRegBfPtr[TimId];
    boolean TofIntEn = (boolean)BaseBf->TIM_GLBCR.TOIE;
    boolean TofFlag = (boolean)BaseBf->TIM_GLBSR.TOF;
    
    if((FALSE != TofIntEn) && (FALSE != TofFlag))
    {
        /* Clear Timer Overflow Flag */
        BaseBf->TIM_GLBSR.TOF = 0;

#if (TIM_PWM_DRV_NOTIFICATION_SUPPORTED == STD_ON)
        for(uint8 ChannelId = 0; ChannelId < TIM_PWM_DRV_CHANNEL_NUM; ChannelId++)
        {
            Tim_Pwm_Drv_EdgeInterruptType ChnIrqNotif = Tim_Pwm_Drv_NotifIrq[TimId][ChannelId];
            if((TIM_PWM_DRV_NO_EDGE != (ChnIrqNotif & TIM_PWM_DRV_TOF_IRQ_EDGE)) && 
                (TIM_PWM_DRV_NO_EDGE == (ChnIrqNotif & TIM_PWM_DRV_IRQ_NO_EDGE_NOTIF)))
            {
                if(NULL_PTR != Tim_Pwm_Drv_OverflowIrqCallbacks[TimId][ChannelId])
                {
                    Tim_Pwm_Drv_OverflowIrqCallbacks[TimId][ChannelId]();
                }
#else
                if(NULL_PTR != Tim_Pwm_Drv_OverflowIrqCallbacks[TimId])
                {
                    Tim_Pwm_Drv_OverflowIrqCallbacks[TimId]();
                }
#endif
#if (TIM_PWM_DRV_NOTIFICATION_SUPPORTED == STD_ON)
            }
        }
#endif
    }
}  


/**
 * @brief     Processing channel matching interrupt.
 *
 * @param[in] TimId: The id of the TIM module. 
 * 
 * @return    None
 *
 */
void Tim_Pwm_Drv_ProcessCommonInterrupt(uint8 TimId)
{
    Reg_Tim_BfType * BaseBf = (Reg_Tim_BfType *) Tim_Pwm_Drv_PwmRegBfPtr[TimId];
    boolean ChnIntEn;
    boolean ChnIntFlag;

    for(uint8 ChannelId = 0U; ChannelId < TIM_PWM_DRV_CHANNEL_NUM; ChannelId++)
    {
        ChnIntEn = (boolean)BaseBf->TIM_CMCn[ChannelId].CHIE;
        ChnIntFlag = (boolean)BaseBf->TIM_CMCn[ChannelId].CHF;

        if((FALSE != ChnIntEn) && (FALSE != ChnIntFlag))
        {
            /* Clear Channel Int*/
            BaseBf->TIM_CMCn[ChannelId].CHF = 0U;

    #if (TIM_PWM_DRV_NOTIFICATION_SUPPORTED == STD_ON)     
            Tim_Pwm_Drv_EdgeInterruptType ChnIrqNotif = \
                       Tim_Pwm_Drv_NotifIrq[TimId][ChannelId] & TIM_PWM_DRV_CHF_IRQ_EDGE;
            if(TIM_PWM_DRV_NO_EDGE != ChnIrqNotif)
            {
    #endif
                if(NULL_PTR != Tim_Pwm_Drv_ChIrqCallbacks[TimId][ChannelId])
                {
                    Tim_Pwm_Drv_ChIrqCallbacks[TimId][ChannelId]();
                }
    #if (TIM_PWM_DRV_NOTIFICATION_SUPPORTED == STD_ON)
            }

            if(TIM_PWM_DRV_MODE_COMBINE_VARIABLE_EDGE_PLACEMENT == \
                                               Tim_Pwm_Drv_ChannelMode[TimId][ChannelId])
            {
                uint8 CombineChannelId = ((ChannelId % 2U) == 0U) ? (ChannelId + 1U) : (ChannelId - 1U);
                ChnIrqNotif = Tim_Pwm_Drv_NotifIrq[TimId][ChannelId] & \
                                                        TIM_PWM_DRV_CHF_COMBINE_IRQ_EDGE;
                if(TIM_PWM_DRV_NO_EDGE != ChnIrqNotif)
                {
                    if(NULL_PTR != Tim_Pwm_Drv_ChIrqCallbacks[TimId][CombineChannelId])
                    {
                        Tim_Pwm_Drv_ChIrqCallbacks[TimId][CombineChannelId]();
                    }
                }
            }          
    #endif
        }
    }
}


/** @} end of group Public_FunctionDefinition */

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} end of group Pwm_Drv */

/** @} end of group Pwm_Module */
