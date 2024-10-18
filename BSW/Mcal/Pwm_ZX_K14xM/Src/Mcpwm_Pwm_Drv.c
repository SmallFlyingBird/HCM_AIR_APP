/*************************************************************************************/
/**
 * @file      : Mcpwm_Pwm_Drv.c
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
#include "Mcpwm_Pwm_Drv.h"
#include "Device_Regs.h"
#include "SchM_Pwm.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define MCPWM_PWM_DRV_C_VENDOR_ID                   0x00B3U
#define MCPWM_PWM_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define MCPWM_PWM_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define MCPWM_PWM_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define MCPWM_PWM_DRV_C_SW_MAJOR_VERSION            1U
#define MCPWM_PWM_DRV_C_SW_MINOR_VERSION            2U
#define MCPWM_PWM_DRV_C_SW_PATCH_VERSION            1U

/* Check if source file and Mcpwm_Pwm_Drv.h header file are of the same vendor */
#if (MCPWM_PWM_DRV_C_VENDOR_ID != MCPWM_PWM_DRV_H_VENDOR_ID)
    #error "Vendor ID of Mcpwm_Pwm_Drv.c and Mcpwm_Pwm_Drv.h are different"
#endif
/* Check if source file and Mcpwm_Pwm_Drv.h header file are of the same AUTOSAR version */
#if ((MCPWM_PWM_DRV_C_AR_RELEASE_MAJOR_VERSION    != MCPWM_PWM_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (MCPWM_PWM_DRV_C_AR_RELEASE_MINOR_VERSION    != MCPWM_PWM_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (MCPWM_PWM_DRV_C_AR_RELEASE_REVISION_VERSION != MCPWM_PWM_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Mcpwm_Pwm_Drv.c and Mcpwm_Pwm_Drv.h are different"
#endif
/* Check if header file and Mcpwm_Pwm_Drv.h header file are of the same software version */
#if ((MCPWM_PWM_DRV_C_SW_MAJOR_VERSION != MCPWM_PWM_DRV_H_SW_MAJOR_VERSION) || \
     (MCPWM_PWM_DRV_C_SW_MINOR_VERSION != MCPWM_PWM_DRV_H_SW_MINOR_VERSION) || \
     (MCPWM_PWM_DRV_C_SW_PATCH_VERSION != MCPWM_PWM_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Mcpwm_Pwm_Drv.c and Mcpwm_Pwm_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Device_Regs.h are the same Autosar version */
    #if ((MCPWM_PWM_DRV_C_AR_RELEASE_MAJOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) || \
         (MCPWM_PWM_DRV_C_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Mcpwm_Pwm_Drv.c and Device_Regs.h are different"
    #endif
    
    /* Check if current file and SchM_Pwm.h are the same Autosar version */
    #if ((MCPWM_PWM_DRV_C_AR_RELEASE_MAJOR_VERSION != SCHM_PWM_H_AR_RELEASE_MAJOR_VERSION) || \
         (MCPWM_PWM_DRV_C_AR_RELEASE_MINOR_VERSION != SCHM_PWM_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar version of Mcpwm_Pwm_Drv.c and SchM_Pwm.h are different"
    #endif
#endif


/**
 * @brief GLBCR Register counting mode shift.
 */
#define MCPWM_GLBCR_CNTM_SHIFT          (8UL)

/**
 * @brief GLBCR Register counter enable shift.
 */
#define MCPWM_GLBCR_CNTEN_SHIFT         (12UL)

/**
 * @brief GLBCR Register overflow interrupt enable shift.
 */
#define MCPWM_GLBCR_TOIE_SHIFT          (20UL)

/**
 * @brief GLBCR Register counters enable mask.
 */
#define MCPWM_GLBCR_CNTEN_MASK          (0xF000UL)

/**
 * @brief GLBSR Register overflow interrupt flag shift.
 */
#define MCPWM_GLBSR_TOF_SHIFT           (12UL)

/**
 * @brief Reload Register
 */
#define MCPWM_RELOAD_LOADEN_MASK          (0xF00UL)

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
static uint16 Mcpwm_Pwm_Drv_Period[MCPWM_PWM_DRV_INSTANCE_NUM][MCPWM_PWM_DRV_COUNTER_NUM];
static uint16 Mcpwm_Pwm_Drv_DutyCycle[MCPWM_PWM_DRV_INSTANCE_NUM][MCPWM_PWM_DRV_CHANNEL_NUM];
static uint16 Mcpwm_Pwm_Drv_PhaseShift[MCPWM_PWM_DRV_INSTANCE_NUM][MCPWM_PWM_DRV_PAIR_CHANNEL_NUM];
static uint16 Mcpwm_Pwm_Drv_ChannelDither[MCPWM_PWM_DRV_INSTANCE_NUM][MCPWM_PWM_DRV_CHANNEL_NUM];
static uint16 Mcpwm_Pwm_Drv_PeriodDither[MCPWM_PWM_DRV_INSTANCE_NUM][MCPWM_PWM_DRV_COUNTER_NUM];
#define PWM_STOP_SEC_VAR_CLEARED_16
#include "Pwm_MemMap.h"

#define PWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Pwm_MemMap.h"

static Mcpwm_Pwm_Drv_EdgeInterruptType Mcpwm_Pwm_Drv_NotifIrq[MCPWM_PWM_DRV_INSTANCE_NUM] \
                                                      [MCPWM_PWM_DRV_CHANNEL_NUM];
static Mcpwm_Pwm_Drv_ChannelModeType Mcpwm_Pwm_Drv_ChannelMode[MCPWM_PWM_DRV_INSTANCE_NUM] \
                                                              [MCPWM_PWM_DRV_CHANNEL_NUM];
static Mcpwm_Pwm_Drv_CountingModeType Mcpwm_Pwm_Drv_CounterMode[MCPWM_PWM_DRV_INSTANCE_NUM] \
                                                               [MCPWM_PWM_DRV_CHANNEL_NUM];
static Mcpwm_Pwm_Drv_ChannelStateType Mcpwm_Pwm_Drv_ChannelState[MCPWM_PWM_DRV_INSTANCE_NUM] \
                                                                [MCPWM_PWM_DRV_CHANNEL_NUM];
static Mcpwm_Pwm_Drv_ChannelStateType \
       Mcpwm_Pwm_Drv_PreviousChannelState[MCPWM_PWM_DRV_INSTANCE_NUM][MCPWM_PWM_DRV_CHANNEL_NUM];
static Mcpwm_Pwm_Drv_OutputStateType Mcpwm_Pwm_Drv_IdleState[MCPWM_PWM_DRV_INSTANCE_NUM] \
                                                            [MCPWM_PWM_DRV_CHANNEL_NUM];
static Mcpwm_Pwm_Drv_OutputStateType Mcpwm_Pwm_Drv_OffValue[MCPWM_PWM_DRV_INSTANCE_NUM] \
                                                           [MCPWM_PWM_DRV_CHANNEL_NUM];
static Mcpwm_Pwm_Drv_PolarityType Mcpwm_Pwm_Drv_PolarityState[MCPWM_PWM_DRV_INSTANCE_NUM] \
                                                             [MCPWM_PWM_DRV_CHANNEL_NUM];
static Mcpwm_Pwm_Drv_ClkSourceType Mcpwm_Pwm_Drv_ClockSource[MCPWM_PWM_DRV_INSTANCE_NUM];
static Mcpwm_Pwm_Drv_ClkDivideType Mcpwm_Pwm_Drv_ClockDivide[MCPWM_PWM_DRV_INSTANCE_NUM];

static Mcpwm_Pwm_Drv_CallbackType Mcpwm_Pwm_Drv_ChIrqCallbacks[MCPWM_PWM_DRV_INSTANCE_NUM] \
                                                        [MCPWM_PWM_DRV_CHANNEL_NUM];
#if (MCPWM_PWM_DRV_NOTIFICATION_SUPPORTED == STD_ON)
static Mcpwm_Pwm_Drv_CallbackType Mcpwm_Pwm_Drv_OverflowIrqCallbacks[MCPWM_PWM_DRV_INSTANCE_NUM] \
                                                             [MCPWM_PWM_DRV_CHANNEL_NUM];
#else
static Mcpwm_Pwm_Drv_CallbackType Mcpwm_Pwm_Drv_OverflowIrqCallbacks[MCPWM_PWM_DRV_INSTANCE_NUM] \
                                                             [MCPWM_PWM_DRV_COUNTER_NUM];
#endif

#define PWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Pwm_MemMap.h"


#define PWM_START_SEC_CONST_PTR
#include "Pwm_MemMap.h"
/* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer object,
   no side effects forseen by violating this rule.
The following two lines of code also violate this rule with the same reason. */
static Reg_Mcpwm_BfType * const Mcpwm_Pwm_Drv_PwmRegBfPtr[MCPWM_PWM_DRV_INSTANCE_NUM] = 
{
    (Reg_Mcpwm_BfType *) MCPWM0_BASE_ADDR,
    (Reg_Mcpwm_BfType *) MCPWM1_BASE_ADDR
};

/* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer object,
   no side effects forseen by violating this rule.
The following two lines of code also violate this rule with the same reason. */
static Reg_Mcpwm_WType * const Mcpwm_Pwm_Drv_PwmRegWPtr[MCPWM_PWM_DRV_INSTANCE_NUM] = 
{
    (Reg_Mcpwm_WType *) MCPWM0_BASE_ADDR,
    (Reg_Mcpwm_WType *) MCPWM1_BASE_ADDR
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
 * @brief     Set the modulation value for the counter.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] CounterId: The id of the counter. 
 * @param[in] ModVal: The modulation value to be set. 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Mcpwm_Pwm_Drv_SetCounterModVal(uint8 McpwmId, uint8 CounterId, uint16 ModVal);

/**
 * @brief     Get the running state of the counter.
 *
 * @param[in] BaseBf: The hardware registers struct pointer of MCPWM module.
 * @param[in] CounterId: The id of counter.
 *
 * @return    boolean: Status of the counter.
 * @retval    TRUE: The counter is running.
 * @retval    FALSE: The counter stopped.
 *
 */
LOCAL_INLINE boolean Mcpwm_Pwm_Drv_GetCounterState(const Reg_Mcpwm_BfType * BaseBf, uint8 CounterId);

/**
 * @brief     Set the reload enable or not of the pair channels.
 *
 * @param[in] BaseBf: The hardware register struct pointer of MCPWM module.
 * @param[in] PairId: The Id of pair channels.
 * @param[in] Enable: Enable or disable the reload registers of pair channels.
 *
 * @return   None
 *
 */
LOCAL_INLINE void Mcpwm_Pwm_Drv_SetReloadEnable(Reg_Mcpwm_BfType * BaseBf, uint8 PairId,
                                                                        boolean Enable);

/**
 * @brief      Get the output polarity of Pwm channel.
 *
 * @param[in] BaseBf: The hardware registers struct pointer of MCPWM module.
 * @param[in] ChannelId: The id of the channel.
 *
 * @return    Mcpwm_Pwm_Drv_PolarityType: The output polarity of the channel.
 * @retval   MCPWM_PWM_DRV_POL_HIGH: the channel output polarity is High.
 * @retval   MCPWM_PWM_DRV_POL_LOW: the channel output polarity is Low.
 *
 */
LOCAL_INLINE Mcpwm_Pwm_Drv_PolarityType Mcpwm_Pwm_Drv_GetChannelPolVal(
                                             const Reg_Mcpwm_BfType * BaseBf, uint8 ChannelId);

/**
 * @brief      Get the output value of Pwm channel when counter stopped.
 *
 * @param[in] BaseBf: The hardware registers struct pointer of MCPWM module.
 * @param[in] ChannelId: The id of the channel.
 *
 * @return    Mcpwm_Pwm_Drv_OutputStateType: The channel output value when counter stopped.
 * @retval   MCPWM_PWM_DRV_OUTPUT_STATE_LOW: The channel output low when counter stopped.
 * @retval   MCPWM_PWM_DRV_OUTPUT_STATE_HIGH: The channel output high when counter stopped.
 *
 */
LOCAL_INLINE Mcpwm_Pwm_Drv_OutputStateType Mcpwm_Pwm_Drv_GetChannelOffVal(
                                               const Reg_Mcpwm_BfType * BaseBf, uint8 ChannelId);

/**
 * @brief     Set the output polarity of the channel.
 *
 * @param[in] BaseBf: The hardware registers struct pointer for the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Pol: The polairty to be set. 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Mcpwm_Pwm_Drv_SetChannelPolarity(Reg_Mcpwm_BfType * BaseBf, uint8 ChannelId, 
                                                Mcpwm_Pwm_Drv_PolarityType Pol);

#if ((MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON) && (MCPWM_PWM_DRV_SET_CHANNEL_DEAD_TIME_TICKS_API == STD_ON))
/**
 * @brief     If the pair channels deadtime insert is enabled.
 *
 * @param[in] BaseBf: The hardware register struct pointer of MCPWM module.
 * @param[in] PairId: The id of the pair channels.
 *
 * @return   boolean: If the deadtime insert is enabled.
 * @retval   TRUE: The deadtime insert is enabled.
 * @retval   FALSE: The deadtime insert is disabled.
 *
 */
LOCAL_INLINE boolean Mcpwm_Pwm_Drv_GetDualChDeadTimeCmd(const Reg_Mcpwm_BfType * BaseBf, 
                                                                           uint8 PairId);
#endif /* MCPWM_PWM_DRV_DEV_ERROR_DETECT */

/**
 * @brief     Set the deadtime of the pair channels inserted Enable/disable.
 *
 * @param[in] BaseBf: The hardware registers struct pointer for the MCPWM module. 
 * @param[in] PairId: The id of the pair channels. 
 * @param[in] Enable: Enable/Disable the deadtime inserted. 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Mcpwm_Pwm_Drv_ControlPairDeadtime(Reg_Mcpwm_BfType * BaseBf, uint8 PairId, 
                                            boolean Enable);

/**
 * @brief     Get the combine state of pair channels.
 *
 * @param[in] BaseBf: The hardware registers struct pointer of MCPWM module.
 * @param[in] PairId: The id of the pair channels.
 *
 * @return    boolean: If the pair channels output in independ mode or combine mode.
 * @retval    TRUE:  The channels output in combine mode.
 * @retval    FALSE: The channels output in indepedent mode.
 *
 */
LOCAL_INLINE boolean Mcpwm_Pwm_Drv_GetDualCombineCmd(const Reg_Mcpwm_BfType * BaseBf, uint8 PairId);

/**
 * @brief     Get the software control output Enable/disable status of Pwm channel.
 *
 * @param[in] BaseBf: The hardware registers struct pointer of MCPWM module.
 * @param[in] ChannelId:The id of the channel.
 *
 * @return    boolean: If the Pwm channel output Enable.
 * @retval    TRUE: The Pwm channel is software control output Enable.
 * @retval    FALSE: The Pwm channel is software control output disable.
 *
 */
LOCAL_INLINE boolean Mcpwm_Pwm_Drv_GetOutSwCtrState(const Reg_Mcpwm_BfType * BaseBf, uint8 ChannelId);

/**
 * @brief      Get the software control output value of Pwm channel.
 *
 * @param[in] BaseBf: The hardware registers struct pointer of MCPWM module.
 * @param[in] ChannelId: The id of the channel.
 *
 * @return    boolean: If the software control output value of Pwm channel is High.
 * @retval    TRUE: The software control output value of Pwm channel is High.
 * @retval    FALSE: The software control output value of Pwm channel is Low.
 *
 */
LOCAL_INLINE boolean Mcpwm_Pwm_Drv_GetOutSwCtrVal(const Reg_Mcpwm_BfType * BaseBf, uint8 ChannelId);

/**
 * @brief     Get the counting mode of the counter.
 *
 * @param[in] BaseBf: The hardware register struct pointer of MCPWM module.
 * @param[in] CounterId: The id of the counter.
 *
 * @return   boolean: If the counting mode of the counter is "COUNTING_UP" or "COUNTING_UP_AND_DOWN"
 * @retval   TRUE: The counting mode is up_down counting mode.
 * @retval   FALSE: The counting mode is up counting mode.
 *
 */
LOCAL_INLINE boolean Mcpwm_Pwm_Drv_GetCountingMode(const Reg_Mcpwm_BfType * BaseBf, uint8 CounterId);

/**
 * @brief     Set the match trigger of the channel.
 *
 * @param[in] BaseBf: The hardware registers struct pointer for the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Trigger: Enable/Disable the match trigger of the channel. 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Mcpwm_Pwm_Drv_ControlChannelMatchTrigger(Reg_Mcpwm_BfType * BaseBf, uint8 ChannelId, 
                                                    boolean Trigger);

/**
 * @brief     Set the software control output value of the channel.
 *
 * @param[in] BaseBf: The hardware registers struct pointer for the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] State: The output value to be set. 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Mcpwm_Pwm_Drv_SetChannelOCV(Reg_Mcpwm_BfType * BaseBf, uint8 ChannelId, 
                                            Mcpwm_Pwm_Drv_OutputStateType State);

/**
 * @brief     Set the software control output of the channel Enable/disable.
 *
 * @param[in] BaseBf: The hardware registers struct pointer for the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Cmd: Enable/Disable the software control output of the channel. 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Mcpwm_Pwm_Drv_ControlChannelOC(Reg_Mcpwm_BfType * BaseBf, uint8 ChannelId, 
                                            boolean Cmd);

/**
 * @brief     Set the symmetric/asymmetric output mode of the pair channels.
 *
 * @param[in] BaseBf: The hardware registers struct pointer for the MCPWM module. 
 * @param[in] PairId: The id of the pair channels. 
 * @param[in] Asym: The symmertric/asymmertic output mode to be set. 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Mcpwm_Pwm_Drv_ControlPairAsymmetric(Reg_Mcpwm_BfType * BaseBf, uint8 PairId, 
                                                Mcpwm_Pwm_Drv_AsymType Asym);

/**
 * @brief     Set the pulse edge control mode of the pair channels.
 *
 * @param[in] BaseBf: The hardware registers struct pointer for the MCPWM module. 
 * @param[in] PairId: The id of the pair channels. 
 * @param[in] Cmd: The pulse edge control mode to be set. 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Mcpwm_Pwm_Drv_SetPairPec(Reg_Mcpwm_BfType * BaseBf, uint8 PairId, boolean Cmd);

/**
 * @brief     Set the complentary/independent output mode of the pair channels.
 *
 * @param[in] BaseBf: The hardware registers struct pointer for the MCPWM module. 
 * @param[in] PairId: The id of the pair channels. 
 * @param[in] Cmd: The complentary/independent output mode to be set. 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Mcpwm_Pwm_Drv_SetPairCombineCmd(Reg_Mcpwm_BfType * BaseBf, uint8 PairId, 
                                                boolean Cmd);

/**
 * @brief     Set the synchronization Enable/disable of the pair channels.
 *
 * @param[in] BaseBf: The hardware registers struct pointer for the MCPWM module. 
 * @param[in] PairId: The id of the pair channels. 
 * @param[in] Enable: Enable/Disable the synchronization of CV(n) and CV(n+1). 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Mcpwm_Pwm_Drv_ControlPairSynchronization(Reg_Mcpwm_BfType * BaseBf, uint8 PairId, 
                                                    boolean Enable);

/**
 * @brief     Get current complementary config of the channel.
 *
 * @param[in] BaseBf: The hardware registers struct pointer for the MCPWM module. 
 * @param[in] ChannelId: The id of the channel.
 *
 * @return   boolean : The complementary is enable or disable.
 * @retval   TRUE: The complementary is enable.
 * @retval   FALSE: The complementary is disable.
 *
 */
LOCAL_INLINE boolean Mcpwm_Pwm_Drv_GetCombineConfig(const Reg_Mcpwm_BfType * BaseBf, uint8 ChannelId);

/**
 * @brief     Enable the normal notification case for the channel, contain the overflow interrupt 
 *            and the match interrupt.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * 
 * @return   None
 *
 */
static void Mcpwm_Pwm_Drv_SetNormalNotificationCase(uint8 McpwmId, uint8 ChannelId);

/**
 * @brief     Update the notification edge type of the pair channel in complementary output mode.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Notification: The edge type for notification to be updated. 
 * 
 * @return   None
 *
 */
static void Mcpwm_Pwm_Drv_UpdateNotificationStateCombine(uint8 McpwmId, uint8 ChannelId,
                                                Mcpwm_Pwm_Drv_EdgeNotifType Notification);

/**
 * @brief     Update the notification edge type of the channel in independent edge output mode.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Notification: The edge type for notification to be updated. 
 * 
 * @return   None
 *
 */
static void Mcpwm_Pwm_Drv_UpdateNotificationStateEdge(uint8 McpwmId, uint8 ChannelId,
                                            Mcpwm_Pwm_Drv_EdgeNotifType Notification);   

/**
 * @brief     Update the notification edge type of the channel in complementary edge output mode.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Notification: The edge type for notification to be updated. 
 * 
 * @return   None
 *
 */
static void Mcpwm_Pwm_Drv_UpdateNotificationStateEdgeCombine(uint8 McpwmId, uint8 ChannelId,
                                               Mcpwm_Pwm_Drv_EdgeNotifType Notification);
/**
 * @brief     Update the notification edge type of the channel in up_down counting mode.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Notification: The edge type for notification to be updated. 
 * 
 * @return   None
 *
 */
static void Mcpwm_Pwm_Drv_UpdateNotificationStateCenter(uint8 McpwmId, uint8 ChannelId,
                                               Mcpwm_Pwm_Drv_EdgeNotifType Notification);                                                                                 

#if (MCPWM_PWM_DRV_NOTIFICATION_SUPPORTED == STD_ON)
/**
 * @brief     Check if notifications have been enabled in special circumstances.
 *
 * @param[in] McpwmId: The id of the MCPWM module.
 * @param[in] ChannelId: The id of the channel.
 *
 * @return    None
 *
 */
static void Mcpwm_Pwm_Drv_SpecialCheckNotification(uint8 McpwmId, uint8 ChannelId);

/**
 * @brief     Check if notifications are enabled under normal circumstances.
 *
 * @param[in] McpwmId: The id of the MCPWM module.
 * @param[in] ChannelId: The id of the channel.
 *
 * @return    None
 *
 */
static void Mcpwm_Pwm_Drv_NormalCheckNotification(uint8 McpwmId, uint8 ChannelId);

/**
 * @brief     Check if notification is enabled.
 *
 * @param[in] McpwmId: The id of the MCPWM module.
 * @param[in] ChannelId: The id of the channel.
 *
 * @return    None
 *
 */
static void Mcpwm_Pwm_Drv_CheckNotification(uint8 McpwmId, uint8 ChannelId);
#endif

/**
 * @brief     Set the counters config of the MCPWM module.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] CntCfg: The counters configurations pointer to be configured. 
 * 
 * @return   None
 *
 */
static void Mcpwm_Pwm_Drv_ConfigCounter(uint8 McpwmId, const Mcpwm_Pwm_Drv_CounterType * CntCfg);

/**
 * @brief     Configure the MCPWM module.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] InstanceCfg: The instance configuration pointer of MCPWM to be configured. 
 * 
 * @return   None
 *
 */
static void Mcpwm_Pwm_Drv_ConfigInstance(uint8 McpwmId, const Mcpwm_Pwm_Drv_ConfigType * InstanceCfg);

/**
 * @brief     Initialize the configured channels of MCPWM module.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChCfg: The channels configuration pointer. 
 * 
 * @return   None
 *
 */
static void Mcpwm_Pwm_Drv_InitChannel(uint8 McpwmId, const Mcpwm_Pwm_Drv_ChannelConfigType * ChCfg);

/**
 * @brief     Initialize the MCPWM module.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] InstanceCfg: The configuration pointer of the MCPWM. 
 * 
 * @return   None
 *
 */
static void Mcpwm_Pwm_Drv_InitInstance(uint8 McpwmId, const Mcpwm_Pwm_Drv_ConfigType * InstanceCfg);

#if (defined(MCPWM_PWM_DRV_NOTIFICATION_SUPPORTED) && \
                                             (MCPWM_PWM_DRV_NOTIFICATION_SUPPORTED == STD_ON))
/**
 * @brief     Set the output of the channel to sepcific state.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] ActiveState: The specific state to be output. 
 * 
 * @return   None
 *
 */
static void Mcpwm_Pwm_Drv_SetOutputForForcedChannel(uint8 McpwmId, uint8 ChannelId,
                                            boolean ActiveState);
#endif

/**
 * @brief     Update the period for the pair channnels.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] PairId: The id of the pair channels. 
 * @param[in] Period: The period to be updated. 
 * @param[in] SwTrigger: Enable/Disable update period immediatly. 
 * 
 * @return   None
 *
 */
static void Mcpwm_Pwm_Drv_UpdatePwmPeriod(uint8 McpwmId, uint8 PairId, uint32 Period,
                                        boolean SwTrigger);

/**
 * @brief     Get the output state of the channel output.
 *
 * @param[in] McpwmId: The id of MCPWM module.
 * @param[in] ChannelId: The id of output channel.
 *
 * @return   boolean: If the channel output is high.
 * @retval   TRUE: The channel output is high.
 * @retval   FALSE: The channel output is low.
 *
 */
static boolean Mcpwm_Pwm_Drv_IsChannelOutputActive(uint8 McpwmId,uint8 ChannelId);

/**
 * @brief     Set current output mode of the channel.
 *
 * @param[in] McpwmId: The id of MCPWM module.
 * @param[in] ChannelId: The id of the channel.
 * @param[in] Mode: The output mode of the channel.
 *
 * @return   None
 *
 */
static void Mcpwm_Pwm_Drv_SetChannelMode(uint8 McpwmId, uint8 ChannelId, 
                              Mcpwm_Pwm_Drv_ChannelModeType Mode);

/**
 * @brief     Update the duty cycle when channel output in variable edge placement mode.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] FirstEdge: The first edge to start of the active state of PWM. 
 * @param[in] SecondEdge: The second edge to end of the active state of PWM. 
 * @param[in] SwTrigger: Enable/Disable update the dutycycle immediatly. 
 * 
 * @return   None
 *
 */
static Mcpwm_Pwm_Drv_StatusType Mcpwm_Pwm_Drv_UpdatePwmChannel(uint8 McpwmId, uint8 ChannelId, 
                                      uint16 FirstEdge, uint16 SecondEdge, boolean SwTrigger);

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
/**
 * @brief     Set the modulation value for the counter.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] CounterId: The id of the counter. 
 * @param[in] ModVal: The modulation value to be set. 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Mcpwm_Pwm_Drv_SetCounterModVal(uint8 McpwmId, uint8 CounterId, uint16 ModVal)
{
    Reg_Mcpwm_BfType *BaseBf = (Reg_Mcpwm_BfType *)Mcpwm_Pwm_Drv_PwmRegBfPtr[McpwmId];

    SchM_Enter_Pwm_SetMcpwmModuloValueRegister();
    if(TRUE == (boolean)BaseBf->MCPWM_GLBCR.GLBCNTEN)
    {
        BaseBf->MCPWM_MODn[0].MOD = ModVal;
        BaseBf->MCPWM_MODn_DITHER[0].MOD_DITHER = Mcpwm_Pwm_Drv_PeriodDither[McpwmId][0];
    }
    else
    {
        BaseBf->MCPWM_MODn[CounterId].MOD = ModVal;
        BaseBf->MCPWM_MODn_DITHER[CounterId].MOD_DITHER = 
                                            Mcpwm_Pwm_Drv_PeriodDither[McpwmId][CounterId];
    }
    SchM_Exit_Pwm_SetMcpwmModuloValueRegister();
}

/**
 * @brief     Get the running state of the counter.
 *
 * @param[in] BaseBf: The hardware registers struct pointer of MCPWM module.
 * @param[in] CounterId: The id of counter.
 *
 * @return    boolean: Status of the counter.
 * @retval    TRUE: The counter is running.
 * @retval    FALSE: The counter stopped.
 *
 */
LOCAL_INLINE boolean Mcpwm_Pwm_Drv_GetCounterState(const Reg_Mcpwm_BfType * BaseBf, uint8 CounterId)
{
    boolean State = FALSE;
    switch(CounterId)
    {
        case 0U:
            State = BaseBf->MCPWM_GLBCR.CNTEN0;
            break;
        case 1U:
            State = BaseBf->MCPWM_GLBCR.CNTEN1;
            break;
        case 2U:
            State = BaseBf->MCPWM_GLBCR.CNTEN2;
            break;
        case 3U:
            State = BaseBf->MCPWM_GLBCR.CNTEN3;
            break;
        default:
            /* Nothing to do */
            break;
    }
    return State;
}

/**
 * @brief     Set the reload enable or not of the pair channels.
 *
 * @param[in] BaseBf: The hardware register struct pointer of MCPWM module.
 * @param[in] PairId: The Id of pair channels.
 * @param[in] Enable: Enable or disable the reload registers of pair channels.
 *
 * @return   None
 *
 */
LOCAL_INLINE void Mcpwm_Pwm_Drv_SetReloadEnable(Reg_Mcpwm_BfType * BaseBf, uint8 PairId,
                                            boolean Enable)
{
    SchM_Enter_Pwm_SetMcpwmReloadRegister();
    switch(PairId)
    {
        case 0U:
            BaseBf->MCPWM_RELOAD.LOADEN0 = (uint32)Enable;
            break;
        case 1U:
            BaseBf->MCPWM_RELOAD.LOADEN1 = (uint32)Enable;
            break;
        case 2U:
            BaseBf->MCPWM_RELOAD.LOADEN2 = (uint32)Enable;
            break;
        case 3U:
            BaseBf->MCPWM_RELOAD.LOADEN3 = (uint32)Enable;
            break;
        default:
            /* Nothing to do */
            break;
    }
    SchM_Exit_Pwm_SetMcpwmReloadRegister();
}

/**
 * @brief     Get the output state of the channel output.
 *
 * @param[in] McpwmId: The id of MCPWM module.
 * @param[in] ChannelId: The id of output channel.
 *
 * @return   boolean: If the channel output is high.
 * @retval   TRUE: The channel output is high.
 * @retval   FALSE: The channel output is low.
 *
 */
static boolean Mcpwm_Pwm_Drv_IsChannelOutputActive(uint8 McpwmId, uint8 ChannelId)
{
    Reg_Mcpwm_BfType const * BaseBf = (Reg_Mcpwm_BfType *)Mcpwm_Pwm_Drv_PwmRegBfPtr[McpwmId];
    Mcpwm_Pwm_Drv_ChannelModeType ChMode;
    uint8 PairId = ChannelId >> 1U;
    uint16 CounterVal = 0;
    uint16 ChannelCmpVal = 0;
    uint16 SecondChCmpVal = 0;
    boolean ActiveState = FALSE;

    ChMode = Mcpwm_Pwm_Drv_ChannelMode[McpwmId][ChannelId];

    if(TRUE == (boolean)BaseBf->MCPWM_GLBCR.GLBCNTEN)
    {
        CounterVal = (uint16)(BaseBf->MCPWM_CNTn[0U].CNT);
    }
    else
    {
        CounterVal = (uint16)(BaseBf->MCPWM_CNTn[ChannelId >> 1U].CNT);
    }


    switch(ChMode)
    {
        case MCPWM_PWM_DRV_MODE_EDGE_ALIGNED:
            ChannelCmpVal = (uint16)BaseBf->MCPWM_CVn[ChannelId].CV;
            ActiveState = (boolean)(CounterVal < ChannelCmpVal);
            break;
        case MCPWM_PWM_DRV_MODE_CENTER_ALIGNED:
            ChannelCmpVal = (uint16)BaseBf->MCPWM_CVn[ChannelId].CV;
            ActiveState = (boolean)(CounterVal < ChannelCmpVal);
            break;
        case MCPWM_PWM_DRV_MODE_COMBINE_EDGE_ALIGNED:
            ChannelCmpVal = (uint16)BaseBf->MCPWM_CVn[PairId << 1U].CV;
            if(0UL == ((uint32)ChannelId % 2UL))
            {
                /* main channel of combine channels */
                ActiveState = (boolean)(CounterVal < ChannelCmpVal);
            }
            else
            {
                ActiveState = (boolean)(CounterVal > ChannelCmpVal);
            }
            break;
        case MCPWM_PWM_DRV_MODE_COMBINE_SYM_CENTER_ALIGNED:
            ChannelCmpVal = (uint16)BaseBf->MCPWM_CVn[PairId << 1U].CV;
            if(0UL == ((uint32)ChannelId % 2UL))
            {
                /* main channel of combine channels */
                ActiveState = (boolean)(CounterVal < ChannelCmpVal);
            }
            else
            {
                ActiveState = (boolean)(CounterVal > ChannelCmpVal);
            }
            break;
        case MCPWM_PWM_DRV_MODE_COMBINE_VARIABLE_EDGE_PLACEMENT:
            ChannelCmpVal = (uint16)BaseBf->MCPWM_CVn[PairId << 1U].CV;
            SecondChCmpVal = (uint16)BaseBf->MCPWM_CVn[(PairId << 1U) + 1U].CV;
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
 * @param[in] BaseBf: The hardware registers struct pointer of MCPWM module.
 * @param[in] ChannelId: The id of the channel.
 *
 * @return    Mcpwm_Pwm_Drv_PolarityType: The output polarity of the channel.
 * @retval   MCPWM_PWM_DRV_POL_HIGH: the channel output polarity is High.
 * @retval   MCPWM_PWM_DRV_POL_LOW: the channel output polarity is Low.
 *
 */
LOCAL_INLINE Mcpwm_Pwm_Drv_PolarityType Mcpwm_Pwm_Drv_GetChannelPolVal(
                                               const Reg_Mcpwm_BfType * BaseBf, uint8 ChannelId)
{
    Mcpwm_Pwm_Drv_PolarityType PolVal =MCPWM_PWM_DRV_POL_HIGH;
    switch(ChannelId)
    {
        case 0U:
            PolVal = (Mcpwm_Pwm_Drv_PolarityType)BaseBf->MCPWM_OUTCR.POL0;
            break;
        case 1U:
            PolVal = (Mcpwm_Pwm_Drv_PolarityType)BaseBf->MCPWM_OUTCR.POL1;
            break;
        case 2U:
            PolVal = (Mcpwm_Pwm_Drv_PolarityType)BaseBf->MCPWM_OUTCR.POL2;
            break;
        case 3U:
            PolVal = (Mcpwm_Pwm_Drv_PolarityType)BaseBf->MCPWM_OUTCR.POL3;
            break;
        case 4U:
            PolVal = (Mcpwm_Pwm_Drv_PolarityType)BaseBf->MCPWM_OUTCR.POL4;
            break;
        case 5U:
            PolVal = (Mcpwm_Pwm_Drv_PolarityType)BaseBf->MCPWM_OUTCR.POL5;
            break;
        case 6U:
            PolVal = (Mcpwm_Pwm_Drv_PolarityType)BaseBf->MCPWM_OUTCR.POL6;
            break;
        case 7U:
            PolVal = (Mcpwm_Pwm_Drv_PolarityType)BaseBf->MCPWM_OUTCR.POL7;
            break;
        default:
            /* Nothing to do */
            break;
    }
    return PolVal;
}

/**
 * @brief      Get the output value of Pwm channel when counter stopped.
 *
 * @param[in] BaseBf: The hardware registers struct pointer of MCPWM module.
 * @param[in] ChannelId: The id of the channel.
 *
 * @return    Mcpwm_Pwm_Drv_OutputStateType: The channel output value when counter stopped.
 * @retval   MCPWM_PWM_DRV_OUTPUT_STATE_LOW: The channel output low when counter stopped.
 * @retval   MCPWM_PWM_DRV_OUTPUT_STATE_HIGH: The channel output high when counter stopped.
 *
 */
LOCAL_INLINE Mcpwm_Pwm_Drv_OutputStateType Mcpwm_Pwm_Drv_GetChannelOffVal(
                                              const Reg_Mcpwm_BfType * BaseBf, uint8 ChannelId)
{
    Mcpwm_Pwm_Drv_OutputStateType OffVal =MCPWM_PWM_DRV_OUTPUT_STATE_LOW; 
    switch(ChannelId)
    {
        case 0U:
            OffVal = (Mcpwm_Pwm_Drv_OutputStateType) BaseBf->MCPWM_OUTCR.OFFVAL0;
            break;
        case 1U:
            OffVal = (Mcpwm_Pwm_Drv_OutputStateType) BaseBf->MCPWM_OUTCR.OFFVAL1;
            break;
        case 2U:
            OffVal = (Mcpwm_Pwm_Drv_OutputStateType) BaseBf->MCPWM_OUTCR.OFFVAL2;
            break;
        case 3U:
            OffVal = (Mcpwm_Pwm_Drv_OutputStateType) BaseBf->MCPWM_OUTCR.OFFVAL3;
            break;
        case 4U:
            OffVal = (Mcpwm_Pwm_Drv_OutputStateType) BaseBf->MCPWM_OUTCR.OFFVAL4;
            break;
        case 5U:
            OffVal = (Mcpwm_Pwm_Drv_OutputStateType) BaseBf->MCPWM_OUTCR.OFFVAL5;
            break;
        case 6U:
            OffVal = (Mcpwm_Pwm_Drv_OutputStateType) BaseBf->MCPWM_OUTCR.OFFVAL6;
            break;
        case 7U:
            OffVal = (Mcpwm_Pwm_Drv_OutputStateType) BaseBf->MCPWM_OUTCR.OFFVAL7;
            break;
        default:
            /* Nothing to do */
            break;
    }
    return OffVal;
}

/**
 * @brief     Set the output value of the channel when counter stopped.
 *
 * @param[in] BaseBf: The hardware registers struct pointer for the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Val: The output value to be set. 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Mcpwm_Pwm_Drv_SetChannelOffValue(Reg_Mcpwm_BfType * BaseBf, uint8 ChannelId, 
                                                Mcpwm_Pwm_Drv_OutputStateType Val)
{
    switch(ChannelId)
    {
        case 0U:
            BaseBf->MCPWM_OUTCR.OFFVAL0 = (uint32)Val;
            break;
        case 1U:
            BaseBf->MCPWM_OUTCR.OFFVAL1 = (uint32)Val;
            break;
        case 2U:
            BaseBf->MCPWM_OUTCR.OFFVAL2 = (uint32)Val;
            break;
        case 3U:
            BaseBf->MCPWM_OUTCR.OFFVAL3 = (uint32)Val;
            break;
        case 4U:
            BaseBf->MCPWM_OUTCR.OFFVAL4 = (uint32)Val;
            break;
        case 5U:
            BaseBf->MCPWM_OUTCR.OFFVAL5 = (uint32)Val;
            break;
        case 6U:
            BaseBf->MCPWM_OUTCR.OFFVAL6 = (uint32)Val;
            break;
        case 7U:
            BaseBf->MCPWM_OUTCR.OFFVAL7 = (uint32)Val;
            break;
        default:
            /* Nothing to do */
            break;
    }
}

/**
 * @brief     Set the output polarity of the channel.
 *
 * @param[in] BaseBf: The hardware registers struct pointer for the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Pol: The polairty to be set. 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Mcpwm_Pwm_Drv_SetChannelPolarity(Reg_Mcpwm_BfType * BaseBf, uint8 ChannelId, 
                                                Mcpwm_Pwm_Drv_PolarityType Pol)
{
       switch(ChannelId)
    {
        case 0U:
            BaseBf->MCPWM_OUTCR.POL0 = (uint32)Pol;
            break;
        case 1U:
            BaseBf->MCPWM_OUTCR.POL1 = (uint32)Pol;
            break;
        case 2U:
            BaseBf->MCPWM_OUTCR.POL2 = (uint32)Pol;
            break;
        case 3U:
            BaseBf->MCPWM_OUTCR.POL3 = (uint32)Pol;
            break;
        case 4U:
            BaseBf->MCPWM_OUTCR.POL4 = (uint32)Pol;
            break;
        case 5U:
            BaseBf->MCPWM_OUTCR.POL5 = (uint32)Pol;
            break;
        case 6U:
            BaseBf->MCPWM_OUTCR.POL6 = (uint32)Pol;
            break;
        case 7U:
            BaseBf->MCPWM_OUTCR.POL7 = (uint32)Pol;
            break;
        default:
            /* Nothing to do */
            break;
    }
}

#if ((MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON) && (MCPWM_PWM_DRV_SET_CHANNEL_DEAD_TIME_TICKS_API == STD_ON))
/**
 * @brief     If the pair channels deadtime insert is enabled.
 *
 * @param[in] BaseBf: The hardware register struct pointer of MCPWM module.
 * @param[in] PairId: The id of the pair channels.
 *
 * @return   boolean: If the deadtime insert is enabled.
 * @retval   TRUE: The deadtime insert is enabled.
 * @retval   FALSE: The deadtime insert is disabled.
 *
 */
LOCAL_INLINE boolean Mcpwm_Pwm_Drv_GetDualChDeadTimeCmd(const Reg_Mcpwm_BfType * BaseBf, 
                                                                           uint8 PairId)
{
    boolean State = FALSE;
    switch(PairId)
    {
        case 0U:
            State = (boolean)BaseBf->MCPWM_PCR.DTEN0;
            break;
        case 1U:
            State = (boolean)BaseBf->MCPWM_PCR.DTEN1;
            break;
        case 2U:
            State = (boolean)BaseBf->MCPWM_PCR.DTEN2;
            break;
        case 3U:
            State = (boolean)BaseBf->MCPWM_PCR.DTEN3;
            break;
        default:
            /* Nothing to do */
            break;
    }
    return State;
}
#endif /* MCPWM_PWM_DRV_DEV_ERROR_DETECT */

/**
 * @brief     Set the deadtime of the pair channels inserted Enable/disable.
 *
 * @param[in] BaseBf: The hardware registers struct pointer for the MCPWM module. 
 * @param[in] PairId: The id of the pair channels. 
 * @param[in] Enable: Enable/Disable the deadtime inserted. 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Mcpwm_Pwm_Drv_ControlPairDeadtime(Reg_Mcpwm_BfType * BaseBf, uint8 PairId,
                                            boolean Enable) 
{ 
    switch(PairId)
    {
        case 0U:
            BaseBf->MCPWM_PCR.DTEN0 = Enable;
            break;
        case 1U:
            BaseBf->MCPWM_PCR.DTEN1 = Enable;
            break;
        case 2U:
            BaseBf->MCPWM_PCR.DTEN2 = Enable;
            break;
        case 3U:
            BaseBf->MCPWM_PCR.DTEN3 = Enable;
            break;
        default:
            /* Nothing to do */
            break;
    }
}

/**
 * @brief     Get the combine state of pair channels.
 *
 * @param[in] BaseBf: The hardware registers struct pointer of MCPWM module.
 * @param[in] PairId: The id of the pair channels.
 *
 * @return    boolean: If the pair channels output in independ mode or combine mode.
 * @retval    TRUE:  The channels output in combine mode.
 * @retval    FALSE: The channels output in indepedent mode.
 *
 */
LOCAL_INLINE boolean Mcpwm_Pwm_Drv_GetDualCombineCmd(const Reg_Mcpwm_BfType * BaseBf, uint8 PairId)
{
    boolean CombineStatus = FALSE;
    switch(PairId)
    {
        case 0U:
            CombineStatus = (boolean)BaseBf->MCPWM_PCR.COMB0;
            break;
        case 1U:
            CombineStatus = (boolean)BaseBf->MCPWM_PCR.COMB1;
            break;
        case 2U:
            CombineStatus = (boolean)BaseBf->MCPWM_PCR.COMB2;
            break;
        case 3U:
            CombineStatus = (boolean)BaseBf->MCPWM_PCR.COMB3;
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
 * @param[in] BaseBf: The hardware registers struct pointer of MCPWM module.
 * @param[in] ChannelId:The id of the channel.
 *
 * @return    boolean: If the Pwm channel output Enable.
 * @retval    TRUE: The Pwm channel is software control output Enable.
 * @retval    FALSE: The Pwm channel is software control output disable.
 *
 */
LOCAL_INLINE boolean Mcpwm_Pwm_Drv_GetOutSwCtrState(const Reg_Mcpwm_BfType * BaseBf, uint8 ChannelId)
{
    boolean State = FALSE;
    switch(ChannelId)
    {
        case 0U:
            State = BaseBf->MCPWM_OUTSWCR.CH0OC;
            break;
        case 1U:
            State = BaseBf->MCPWM_OUTSWCR.CH1OC;
            break;
        case 2U:
            State = BaseBf->MCPWM_OUTSWCR.CH2OC;
            break;
        case 3U:
            State = BaseBf->MCPWM_OUTSWCR.CH3OC;
            break;
        case 4U:
            State = BaseBf->MCPWM_OUTSWCR.CH4OC;
            break;
        case 5U:
            State = BaseBf->MCPWM_OUTSWCR.CH5OC;
            break;
        case 6U:
            State = BaseBf->MCPWM_OUTSWCR.CH6OC;
            break;
        case 7U:
            State = BaseBf->MCPWM_OUTSWCR.CH7OC;
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
 * @param[in] BaseBf: The hardware registers struct pointer of MCPWM module.
 * @param[in] ChannelId: The id of the channel.
 *
 * @return    boolean: If the software control output value of Pwm channel is High.
 * @retval    TRUE: The software control output value of Pwm channel is High.
 * @retval    FALSE: The software control output value of Pwm channel is Low.
 *
 */
LOCAL_INLINE boolean Mcpwm_Pwm_Drv_GetOutSwCtrVal(const Reg_Mcpwm_BfType * BaseBf, uint8 ChannelId)
{
    boolean State = FALSE;
    switch(ChannelId)
    {
        case 0U:
            State = BaseBf->MCPWM_OUTSWCR.CH0OCV;
            break;
        case 1U:
            State = BaseBf->MCPWM_OUTSWCR.CH1OCV;
            break;
        case 2U:
            State = BaseBf->MCPWM_OUTSWCR.CH2OCV;
            break;
        case 3U:
            State = BaseBf->MCPWM_OUTSWCR.CH3OCV;
            break;
        case 4U:
            State = BaseBf->MCPWM_OUTSWCR.CH4OCV;
            break;
        case 5U:
            State = BaseBf->MCPWM_OUTSWCR.CH5OCV;
            break;
        case 6U:
            State = BaseBf->MCPWM_OUTSWCR.CH6OCV;
            break;
        case 7U:
            State = BaseBf->MCPWM_OUTSWCR.CH7OCV;
            break;
        default:
            /* Nothing to do */
            break;
    }
    return State;
}

/**
 * @brief     Get the counting mode of the counter.
 *
 * @param[in] BaseBf: The hardware register struct pointer of MCPWM module.
 * @param[in] CounterId: The id of the counter.
 *
 * @return   boolean: If the counting mode of the counter is "COUNTING_UP" or "COUNTING_UP_AND_DOWN"
 * @retval   TRUE: The counting mode is up_down counting mode.
 * @retval   FALSE: The counting mode is up counting mode.
 *
 */
LOCAL_INLINE boolean Mcpwm_Pwm_Drv_GetCountingMode(const Reg_Mcpwm_BfType * BaseBf, uint8 CounterId)
{
    boolean State = FALSE;

    if(TRUE == (boolean)BaseBf->MCPWM_GLBCR.GLBCNTEN)
    {
        CounterId = 0U;
    }

    switch(CounterId)
    {
        case 0U:
            State = (boolean) BaseBf->MCPWM_GLBCR.CNTM0;
            break;
        case 1U:
            State = (boolean) BaseBf->MCPWM_GLBCR.CNTM1;
            break;
        case 2U:
            State = (boolean) BaseBf->MCPWM_GLBCR.CNTM2;
            break;
        case 3U:
            State = (boolean) BaseBf->MCPWM_GLBCR.CNTM3;
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
 * @param[in] BaseBf: The hardware registers struct pointer for the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Trigger: Enable/Disable the match trigger of the channel. 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Mcpwm_Pwm_Drv_ControlChannelMatchTrigger(Reg_Mcpwm_BfType * BaseBf, uint8 ChannelId, 
                                                    boolean Trigger)
{
    switch(ChannelId)
    {
        case 0U:
            BaseBf->MCPWM_OUTTRIG.TRIGE0 = (uint32)Trigger;
            break;
        case 1U:
            BaseBf->MCPWM_OUTTRIG.TRIGE1 = (uint32)Trigger;
            break;
        case 2U:
            BaseBf->MCPWM_OUTTRIG.TRIGE2 = (uint32)Trigger;
            break;
        case 3U:
            BaseBf->MCPWM_OUTTRIG.TRIGE3 = (uint32)Trigger;
            break;
        case 4U:
            BaseBf->MCPWM_OUTTRIG.TRIGE4 = (uint32)Trigger;
            break;
        case 5U:
            BaseBf->MCPWM_OUTTRIG.TRIGE5 = (uint32)Trigger;
            break;
        case 6U:
            BaseBf->MCPWM_OUTTRIG.TRIGE6 = (uint32)Trigger;
            break;
        case 7U:
            BaseBf->MCPWM_OUTTRIG.TRIGE7 = (uint32)Trigger;
            break;
        default:
            /* Nothing to do */
            break;
    }
}

/**
 * @brief     Set the software control output value of the channel.
 *
 * @param[in] BaseBf: The hardware registers struct pointer for the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] State: The output value to be set. 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Mcpwm_Pwm_Drv_SetChannelOCV(Reg_Mcpwm_BfType * BaseBf, uint8 ChannelId,
                                            Mcpwm_Pwm_Drv_OutputStateType State)
{
    SchM_Enter_Pwm_SetMcpwmSoftwareControlRegister();
    switch(ChannelId)
    {
        case 0U:
            BaseBf->MCPWM_OUTSWCR.CH0OCV = (uint32)State;
            break;
        case 1U:
            BaseBf->MCPWM_OUTSWCR.CH1OCV = (uint32)State;
            break;
        case 2U:
            BaseBf->MCPWM_OUTSWCR.CH2OCV = (uint32)State;
            break;
        case 3U:
            BaseBf->MCPWM_OUTSWCR.CH3OCV = (uint32)State;
            break;
        case 4U:
            BaseBf->MCPWM_OUTSWCR.CH4OCV = (uint32)State;
            break;
        case 5U:
            BaseBf->MCPWM_OUTSWCR.CH5OCV = (uint32)State;
            break;
        case 6U:
            BaseBf->MCPWM_OUTSWCR.CH6OCV = (uint32)State;
            break;
        case 7U:
            BaseBf->MCPWM_OUTSWCR.CH7OCV = (uint32)State;
            break;
        default:
            /* Nothing to do */
            break;
    }
    SchM_Exit_Pwm_SetMcpwmSoftwareControlRegister();
}

/**
 * @brief     Set the software control output of the channel Enable/disable.
 *
 * @param[in] BaseBf: The hardware registers struct pointer for the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Cmd: Enable/Disable the software control output of the channel. 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Mcpwm_Pwm_Drv_ControlChannelOC(Reg_Mcpwm_BfType * BaseBf, uint8 ChannelId, 
                                            boolean Cmd)
{
    SchM_Enter_Pwm_SetMcpwmSoftwareControlRegister();   
    switch(ChannelId)
    {
        case 0U:
            BaseBf->MCPWM_OUTSWCR.CH0OC = Cmd;
            break;
        case 1U:
            BaseBf->MCPWM_OUTSWCR.CH1OC = Cmd;
            break;
        case 2U:
            BaseBf->MCPWM_OUTSWCR.CH2OC = Cmd;
            break;
        case 3U:
            BaseBf->MCPWM_OUTSWCR.CH3OC = Cmd;
            break;
        case 4U:
            BaseBf->MCPWM_OUTSWCR.CH4OC = Cmd;
            break;
        case 5U:
            BaseBf->MCPWM_OUTSWCR.CH5OC = Cmd;
            break;
        case 6U:
            BaseBf->MCPWM_OUTSWCR.CH6OC = Cmd;
            break;
        case 7U:
            BaseBf->MCPWM_OUTSWCR.CH7OC = Cmd;
            break;
        default:
            /* Nothing to do */
            break;
    }
    SchM_Exit_Pwm_SetMcpwmSoftwareControlRegister();
}

/**
 * @brief     Set the symmetric/asymmetric output mode of the pair channels.
 *
 * @param[in] BaseBf: The hardware registers struct pointer for the MCPWM module. 
 * @param[in] PairId: The id of the pair channels. 
 * @param[in] Asym: The symmertric/asymmertic output mode to be set. 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Mcpwm_Pwm_Drv_ControlPairAsymmetric(Reg_Mcpwm_BfType * BaseBf, uint8 PairId, 
                                                Mcpwm_Pwm_Drv_AsymType Asym)
{
    switch(PairId)
    {
        case 0U:
            BaseBf->MCPWM_PCR.ASYMEN0 = (uint32)Asym;
            break;
        case 1U:
            BaseBf->MCPWM_PCR.ASYMEN1 = (uint32)Asym;
            break;
        case 2U:
            BaseBf->MCPWM_PCR.ASYMEN2 = (uint32)Asym;
            break;
        case 3U:
            BaseBf->MCPWM_PCR.ASYMEN3 = (uint32)Asym;
            break;
        default:
            /* Nothing to do */
            break;
    }
}

/**
 * @brief     Set the pulse edge control mode of the pair channels.
 *
 * @param[in] BaseBf: The hardware registers struct pointer for the MCPWM module. 
 * @param[in] PairId: The id of the pair channels. 
 * @param[in] Cmd: The pulse edge control mode to be set. 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Mcpwm_Pwm_Drv_SetPairPec(Reg_Mcpwm_BfType * BaseBf, uint8 PairId, boolean Cmd)
{
    switch(PairId)
    {
        case 0U:            
            BaseBf->MCPWM_PCR.PEC0 = (uint32)Cmd;
            break;
        case 1U:
            BaseBf->MCPWM_PCR.PEC1 = (uint32)Cmd;
            break;
        case 2U:
            BaseBf->MCPWM_PCR.PEC2 = (uint32)Cmd;
            break;
        case 3U:
            BaseBf->MCPWM_PCR.PEC3 = (uint32)Cmd;
            break;
        default:
            /* Nothing to do */
            break;
    }
}

/**
 * @brief     Set the complentary/independent output mode of the pair channels.
 *
 * @param[in] BaseBf: The hardware registers struct pointer for the MCPWM module. 
 * @param[in] PairId: The id of the pair channels. 
 * @param[in] Cmd: The complentary/independent output mode to be set. 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Mcpwm_Pwm_Drv_SetPairCombineCmd(Reg_Mcpwm_BfType * BaseBf, uint8 PairId, 
                                                boolean Cmd)
{
    switch(PairId)
    {
        case 0U:
            BaseBf->MCPWM_PCR.COMB0 = Cmd;
            break;
        case 1U:
            BaseBf->MCPWM_PCR.COMB1 = Cmd;
            break;
        case 2U:
            BaseBf->MCPWM_PCR.COMB2 = Cmd;
            break;
        case 3U:
            BaseBf->MCPWM_PCR.COMB3 = Cmd;
            break;
        default:
            /* Nothing to do */
            break;
    }
}

/**
 * @brief     Set the synchronization Enable/disable of the pair channels.
 *
 * @param[in] BaseBf: The hardware registers struct pointer for the MCPWM module. 
 * @param[in] PairId: The id of the pair channels. 
 * @param[in] Enable: Enable/Disable the synchronization of CV(n) and CV(n+1). 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Mcpwm_Pwm_Drv_ControlPairSynchronization(Reg_Mcpwm_BfType * BaseBf, uint8 PairId,
                                                    boolean Enable)
{
    switch(PairId)
    {
        case 0U:
            BaseBf->MCPWM_PCR.SYNCEN0 = Enable;
            break;
        case 1U:
            BaseBf->MCPWM_PCR.SYNCEN1 = Enable;
            break;
        case 2U:
            BaseBf->MCPWM_PCR.SYNCEN2 = Enable;
            break;
        case 3U:
            BaseBf->MCPWM_PCR.SYNCEN3 = Enable;
            break;
        default:
            /* Nothing to do */
            break;
    }
}

/**
 * @brief     Clear overflow interrupt of the counter .
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] CounterId: The Counter Id which Overflow interrput to be cleared. 
 * 
 * @return   None
 *
 */
LOCAL_INLINE void Mcpwm_Pwm_Drv_ClearCounterOverflow(uint8 McpwmId, uint8 CounterId)
{
    Reg_Mcpwm_BfType *BaseBf = (Reg_Mcpwm_BfType *) Mcpwm_Pwm_Drv_PwmRegBfPtr[McpwmId];

    if(TRUE == (boolean)BaseBf->MCPWM_GLBCR.GLBCNTEN)
    {
        CounterId = 0;
    }

    SchM_Enter_Pwm_SetMcpwmGlobalStatusRegister();
    switch(CounterId)
    {
        
        case 0:
            BaseBf->MCPWM_GLBSR.TOF0 = 0U;
            break;
        case 1:
            BaseBf->MCPWM_GLBSR.TOF1 = 0U;
            break;
        case 2:
            BaseBf->MCPWM_GLBSR.TOF2 = 0U;
            break;
        case 3:
            BaseBf->MCPWM_GLBSR.TOF3 = 0U;
            break;
        default:
            /* Nothing to do */
            break;
    }
    SchM_Exit_Pwm_SetMcpwmGlobalStatusRegister();
}

/**
 * @brief     Update the notification edge type of the pair channel in complementary output mode.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Notification: The edge type for notification to be updated. 
 * 
 * @return   None
 *
 */
static void Mcpwm_Pwm_Drv_UpdateNotificationStateCombine(uint8 McpwmId, uint8 ChannelId,
                                                    Mcpwm_Pwm_Drv_EdgeNotifType Notification)
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

    SchM_Enter_Pwm_SetMcpwmNotifIrq();
    switch(Notification)
    {
        case MCPWM_PWM_DRV_BOTH_EDGES:
            Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] |= MCPWM_PWM_DRV_CHF_IRQ_EDGE;
            Mcpwm_Pwm_Drv_NotifIrq[McpwmId][CombineChannelId] |= \
                                                      MCPWM_PWM_DRV_CHF_COMBINE_IRQ_EDGE;
            break;

        case MCPWM_PWM_DRV_RISING_EDGE:
            if(MCPWM_PWM_DRV_POL_LOW == \
                                   Mcpwm_Pwm_Drv_PolarityState[McpwmId][ChannelId])
            {
                Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] |= MCPWM_PWM_DRV_CHF_IRQ_EDGE;
            }
            else
            {
                Mcpwm_Pwm_Drv_NotifIrq[McpwmId][CombineChannelId] |= \
                                                      MCPWM_PWM_DRV_CHF_COMBINE_IRQ_EDGE;
            }         
            break;

        case MCPWM_PWM_DRV_FALLING_EDGE:
            if(MCPWM_PWM_DRV_POL_HIGH == \
                                Mcpwm_Pwm_Drv_PolarityState[McpwmId][ChannelId])
            {
                Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] |= MCPWM_PWM_DRV_CHF_IRQ_EDGE;
            }
            else
            {
                Mcpwm_Pwm_Drv_NotifIrq[McpwmId][CombineChannelId] |= \
                                                      MCPWM_PWM_DRV_CHF_COMBINE_IRQ_EDGE;
            }
            break;
            
        default:        
            /* Nothing to do */
            break;
    }
    SchM_Exit_Pwm_SetMcpwmNotifIrq();
}

/**
 * @brief     Update the notification edge type of the channel in independent edge output mode.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Notification: The edge type for notification to be updated. 
 * 
 * @return   None
 *
 */
static void Mcpwm_Pwm_Drv_UpdateNotificationStateEdge(uint8 McpwmId, uint8 ChannelId,
                                            Mcpwm_Pwm_Drv_EdgeNotifType Notification)
{
    SchM_Enter_Pwm_SetMcpwmNotifIrq();
    switch(Notification)
    {
        case MCPWM_PWM_DRV_BOTH_EDGES:
            Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] |= (Mcpwm_Pwm_Drv_EdgeInterruptType) \
                                   (MCPWM_PWM_DRV_TOF_IRQ_EDGE |MCPWM_PWM_DRV_CHF_IRQ_EDGE);
            break;
        case MCPWM_PWM_DRV_RISING_EDGE:
            if(MCPWM_PWM_DRV_POL_HIGH == Mcpwm_Pwm_Drv_PolarityState[McpwmId][ChannelId])
            {
                Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] |= MCPWM_PWM_DRV_TOF_IRQ_EDGE;
            }
            else
            {
                Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] |= MCPWM_PWM_DRV_CHF_IRQ_EDGE;
            }          
            break;
        case MCPWM_PWM_DRV_FALLING_EDGE:
            if(MCPWM_PWM_DRV_POL_LOW == Mcpwm_Pwm_Drv_PolarityState[McpwmId][ChannelId])
            {
                Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] |= MCPWM_PWM_DRV_TOF_IRQ_EDGE;
            }
            else
            {
                Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] |= MCPWM_PWM_DRV_CHF_IRQ_EDGE;
            }      
            break;
        default:
            /* Nothing to do */
            break;
    }
    SchM_Exit_Pwm_SetMcpwmNotifIrq();
}

/**
 * @brief     Update the notification edge type of the channel in complementary edge output mode.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Notification: The edge type for notification to be updated. 
 * 
 * @return   None
 *
 */
static void Mcpwm_Pwm_Drv_UpdateNotificationStateEdgeCombine(uint8 McpwmId, uint8 ChannelId,
                                            Mcpwm_Pwm_Drv_EdgeNotifType Notification)
{
    boolean EvenChannel = (boolean)((ChannelId % 2U) == 0U);

    SchM_Enter_Pwm_SetMcpwmNotifIrq();
    switch(Notification)
    {
        case MCPWM_PWM_DRV_BOTH_EDGES:
            Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] |= (Mcpwm_Pwm_Drv_EdgeInterruptType) \
                                   (MCPWM_PWM_DRV_TOF_IRQ_EDGE |MCPWM_PWM_DRV_CHF_IRQ_EDGE);
            break;

        case MCPWM_PWM_DRV_RISING_EDGE:
            if(TRUE == EvenChannel)
            {
                if(MCPWM_PWM_DRV_POL_HIGH == Mcpwm_Pwm_Drv_PolarityState[McpwmId][ChannelId])
                {
                    Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] |= MCPWM_PWM_DRV_TOF_IRQ_EDGE;
                }
                else
                {
                    Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] |= MCPWM_PWM_DRV_CHF_IRQ_EDGE;
                }    
            }
            else
            {
                if(MCPWM_PWM_DRV_POL_LOW == Mcpwm_Pwm_Drv_PolarityState[McpwmId][ChannelId])
                {
                    Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] |= MCPWM_PWM_DRV_TOF_IRQ_EDGE;
                }
                else
                {
                    Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] |= MCPWM_PWM_DRV_CHF_IRQ_EDGE;
                } 
            }     
            break;

        case MCPWM_PWM_DRV_FALLING_EDGE:
            if(TRUE == EvenChannel)
            {
                if(MCPWM_PWM_DRV_POL_LOW == Mcpwm_Pwm_Drv_PolarityState[McpwmId][ChannelId])
                {
                    Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] |= MCPWM_PWM_DRV_TOF_IRQ_EDGE;
                }
                else
                {
                    Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] |= MCPWM_PWM_DRV_CHF_IRQ_EDGE;
                }   
            }
            else
            {
                if(MCPWM_PWM_DRV_POL_HIGH == Mcpwm_Pwm_Drv_PolarityState[McpwmId][ChannelId])
                {
                    Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] |= MCPWM_PWM_DRV_TOF_IRQ_EDGE;
                }
                else
                {
                    Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] |= MCPWM_PWM_DRV_CHF_IRQ_EDGE;
                }   
            }            
            break;
            
        default:
            /* Nothing to do */
            break;
    }
    SchM_Exit_Pwm_SetMcpwmNotifIrq();
}

/**
 * @brief     Update the notification edge type of the channel in up_down counting mode.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Notification: The edge type for notification to be updated. 
 * 
 * @return   None
 *
 */
static void Mcpwm_Pwm_Drv_UpdateNotificationStateCenter(uint8 McpwmId, uint8 ChannelId,
                                            Mcpwm_Pwm_Drv_EdgeNotifType Notification)
{
    SchM_Enter_Pwm_SetMcpwmNotifIrq();
    switch(Notification)
    {
        case MCPWM_PWM_DRV_BOTH_EDGES:
            Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] |= \
                             (Mcpwm_Pwm_Drv_EdgeInterruptType)MCPWM_PWM_DRV_CHF_IRQ_EDGE;
            break;
        default:
            /* Nothing to do */
            break;
    }
    SchM_Exit_Pwm_SetMcpwmNotifIrq();
}

/**
 * @brief     Enable/Disable the over flow interrupt of the channel.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] Enable: Enable/Disable Counter Overflow Interrupt. 
 * 
 * @return   None
 *
 */
static void Mcpwm_Pwm_Drv_SetCounterOverflowInt(uint8 McpwmId, uint8 ChannelId, boolean Enable)
{ 
    Reg_Mcpwm_BfType *BaseBf = (Reg_Mcpwm_BfType *)Mcpwm_Pwm_Drv_PwmRegBfPtr[McpwmId];
    uint8 PairId = ChannelId >> 1U;

    SchM_Enter_Pwm_SetMcpwmGlobalControlRegister();
    if(FALSE == (boolean)BaseBf->MCPWM_GLBCR.GLBCNTEN)
    {
        switch(PairId)
        {
            case 0U:
                BaseBf->MCPWM_GLBCR.TOIE0 = (uint32)Enable;
                break;
            case 1U:
                BaseBf->MCPWM_GLBCR.TOIE1 = (uint32)Enable;    
                break;
            case 2U:
                BaseBf->MCPWM_GLBCR.TOIE2 = (uint32)Enable;
                break;
            case 3U:
                BaseBf->MCPWM_GLBCR.TOIE3 = (uint32)Enable;
                break;
            default:
                /* Nothing to do */
                break;
        }
    }
    else
    {
        BaseBf->MCPWM_GLBCR.TOIE0 = (uint32)Enable;
    }
    SchM_Exit_Pwm_SetMcpwmGlobalControlRegister();
}

/**
 * @brief     Disable the interrupts relate to  the channel.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * 
 * @return   None
 *
 */
static void Mcpwm_Pwm_Drv_DisableInterrupt(uint8 McpwmId, uint8 ChannelId)
{
    Reg_Mcpwm_BfType *BaseBf = (Reg_Mcpwm_BfType *) Mcpwm_Pwm_Drv_PwmRegBfPtr[McpwmId];
    Mcpwm_Pwm_Drv_EdgeInterruptType NotifyState;
    boolean OverFlowFlag = FALSE;
    uint8 Index;
    uint8 PairId = ChannelId >> 1U;

    SchM_Enter_Pwm_SetMcpwmChannelConfigurationRegister();

    /* Channel Int*/
    NotifyState = Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] & (MCPWM_PWM_DRV_CHF_IRQ_EDGE | \
                                                     MCPWM_PWM_DRV_CHF_COMBINE_IRQ_EDGE);
    if(MCPWM_PWM_DRV_NO_EDGE == NotifyState)  
    {
        /* Disable Channel Int*/
        BaseBf->MCPWM_CFGn[ChannelId].CHIE = FALSE;
    }

    /* Clear Channel Int */
    BaseBf->MCPWM_CFGn[ChannelId].CHF = 0U;
    SchM_Exit_Pwm_SetMcpwmChannelConfigurationRegister();


    /* Counter Overflow Int */
    if(TRUE == (boolean)BaseBf->MCPWM_GLBCR.GLBCNTEN)
    {
        for(Index = 0U; Index < (uint8)MCPWM_PWM_DRV_CHANNEL_NUM; Index++)
        {
            NotifyState = (Mcpwm_Pwm_Drv_NotifIrq[McpwmId][Index] & MCPWM_PWM_DRV_TOF_IRQ_EDGE);
            if(MCPWM_PWM_DRV_NO_EDGE != NotifyState)
            {
                OverFlowFlag = TRUE;
                break;
            }
        }
    }
    else
    {
        NotifyState = (Mcpwm_Pwm_Drv_NotifIrq[McpwmId][(uint32)PairId << 1UL] & \
                                                                MCPWM_PWM_DRV_TOF_IRQ_EDGE);
        NotifyState |= (Mcpwm_Pwm_Drv_NotifIrq[McpwmId][((uint32)PairId << 1UL) + 1UL] & \
                                                                MCPWM_PWM_DRV_TOF_IRQ_EDGE);
        if(MCPWM_PWM_DRV_NO_EDGE != NotifyState)
        {
            OverFlowFlag = TRUE;
        }
    }

    if(FALSE == OverFlowFlag)
    {
        /* Disable Counter Overflow Int */
        Mcpwm_Pwm_Drv_SetCounterOverflowInt(McpwmId, ChannelId, FALSE);
    }

    /* Clear Counter Overflow Int */
    Mcpwm_Pwm_Drv_ClearCounterOverflow(McpwmId, PairId);
}

/**
 * @brief     Enable the normal notification case for the channel, contain the overflow interrupt 
 *            and the match interrupt.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * 
 * @return   None
 *
 */
static void Mcpwm_Pwm_Drv_SetNormalNotificationCase(uint8 McpwmId, uint8 ChannelId)
{
    Reg_Mcpwm_BfType * BaseBf = (Reg_Mcpwm_BfType *) Mcpwm_Pwm_Drv_PwmRegBfPtr[McpwmId];
    Mcpwm_Pwm_Drv_ChannelModeType Mode = Mcpwm_Pwm_Drv_ChannelMode[McpwmId][ChannelId];
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
    if(MCPWM_PWM_DRV_TOF_IRQ_EDGE == (Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] & \
                                                                 MCPWM_PWM_DRV_TOF_IRQ_EDGE))
    {
        Mcpwm_Pwm_Drv_SetCounterOverflowInt(McpwmId, ChannelId, TRUE);
    }

    SchM_Enter_Pwm_SetMcpwmChannelConfigurationRegister();

    /* Channel Int*/
    if(MCPWM_PWM_DRV_CHF_IRQ_EDGE == (Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] & \
                                                                 MCPWM_PWM_DRV_CHF_IRQ_EDGE))
    {        
        BaseBf->MCPWM_CFGn[ChannelId].CHIE = TRUE;
    }

    if(MCPWM_PWM_DRV_MODE_COMBINE_VARIABLE_EDGE_PLACEMENT == Mode)
    {
        /* Clear Combine Channel Int */
        BaseBf->MCPWM_CFGn[CombineChannelId].CHF = 0U;

        if(MCPWM_PWM_DRV_CHF_COMBINE_IRQ_EDGE  == (Mcpwm_Pwm_Drv_NotifIrq[McpwmId][CombineChannelId] \
                                                   & MCPWM_PWM_DRV_CHF_COMBINE_IRQ_EDGE))
        {
            BaseBf->MCPWM_CFGn[CombineChannelId].CHIE = TRUE;
        }
    }
    SchM_Exit_Pwm_SetMcpwmChannelConfigurationRegister();
}

#if (MCPWM_PWM_DRV_NOTIFICATION_SUPPORTED == STD_ON)
/**
 * @brief     Check if notifications have been enabled in special circumstances.
 *
 * @param[in] McpwmId: The id of the MCPWM module.
 * @param[in] ChannelId: The id of the channel.
 *
 * @return    None
 *
 */
static void Mcpwm_Pwm_Drv_SpecialCheckNotification(uint8 McpwmId, uint8 ChannelId)
{
    SchM_Enter_Pwm_SetMcpwmNotifIrq();
    /* Overflow Int*/
    if (MCPWM_PWM_DRV_NO_EDGE != (Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] & MCPWM_PWM_DRV_TOF_IRQ_EDGE))
    {
        /* Close overflow interrupt notification edge */
        Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] |= MCPWM_PWM_DRV_IRQ_NO_EDGE_NOTIF;
    }
    SchM_Exit_Pwm_SetMcpwmNotifIrq();

    Mcpwm_Pwm_Drv_DisableInterrupt(McpwmId, ChannelId);
}

/**
 * @brief     Check if notifications are enabled under normal circumstances.
 *
 * @param[in] McpwmId: The id of the MCPWM module.
 * @param[in] ChannelId: The id of the channel.
 *
 * @return    None
 *
 */
static void Mcpwm_Pwm_Drv_NormalCheckNotification(uint8 McpwmId, uint8 ChannelId)
{
    Reg_Mcpwm_BfType * BaseBf = (Reg_Mcpwm_BfType *)Mcpwm_Pwm_Drv_PwmRegBfPtr[McpwmId];
    Mcpwm_Pwm_Drv_ChannelModeType Mode = Mcpwm_Pwm_Drv_ChannelMode[McpwmId][ChannelId];
    uint8 CombineChannelId;
    if((ChannelId % 2U) == 0U)
    {
        CombineChannelId = ChannelId + 1U;
    }
    else
    {
        CombineChannelId = ChannelId - 1U;
    }

    SchM_Enter_Pwm_SetMcpwmNotifIrq();
    /* Overflow Int */
    if (MCPWM_PWM_DRV_NO_EDGE != (Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] & MCPWM_PWM_DRV_TOF_IRQ_EDGE))
    {
        /* Open overflow interrupt notification edge */
        Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] &= (uint8)(~(MCPWM_PWM_DRV_IRQ_NO_EDGE_NOTIF));
        SchM_Exit_Pwm_SetMcpwmNotifIrq();

        Mcpwm_Pwm_Drv_SetCounterOverflowInt(McpwmId, ChannelId, TRUE);
    }
    else
    {
        SchM_Exit_Pwm_SetMcpwmNotifIrq();
    }

    SchM_Enter_Pwm_SetMcpwmChannelConfigurationRegister();
    /* Channel Int */
    if(MCPWM_PWM_DRV_CHF_IRQ_EDGE == (Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] & \
                                                               MCPWM_PWM_DRV_CHF_IRQ_EDGE))
    {
        BaseBf->MCPWM_CFGn[ChannelId].CHIE = TRUE;
    }

    if(MCPWM_PWM_DRV_MODE_COMBINE_VARIABLE_EDGE_PLACEMENT == Mode)
    {
        /* Clear Combine Channel Int */
        BaseBf->MCPWM_CFGn[CombineChannelId].CHF = 0U;

        if(MCPWM_PWM_DRV_CHF_COMBINE_IRQ_EDGE == (Mcpwm_Pwm_Drv_NotifIrq[McpwmId][CombineChannelId] \
                                                    & MCPWM_PWM_DRV_CHF_COMBINE_IRQ_EDGE))
        {
            BaseBf->MCPWM_CFGn[CombineChannelId].CHIE = TRUE;
        }
    }
    SchM_Exit_Pwm_SetMcpwmChannelConfigurationRegister();
}

/**
 * @brief     Check if notification is enabled.
 *
 * @param[in] McpwmId: The id of the MCPWM module.
 * @param[in] ChannelId: The id of the channel.
 *
 * @return    None
 *
 */
static void Mcpwm_Pwm_Drv_CheckNotification(uint8 McpwmId, uint8 ChannelId)
{
    /* If duty cycle is 0% or 100% */
    if((0U == Mcpwm_Pwm_Drv_DutyCycle[McpwmId][ChannelId]) ||
       (Mcpwm_Pwm_Drv_Period[McpwmId][ChannelId >> 1U] == Mcpwm_Pwm_Drv_DutyCycle[McpwmId][ChannelId]))
    {
        Mcpwm_Pwm_Drv_SpecialCheckNotification(McpwmId, ChannelId);
    }
    /* If duty cycle is not 0% and 100% */
    else
    {
        Mcpwm_Pwm_Drv_NormalCheckNotification(McpwmId, ChannelId);
    }
}
#endif

/**
 * @brief     Set the counters config of the MCPWM module.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] CntCfg: The counters configurations pointer to be configured. 
 * 
 * @return   None
 *
 */
static void Mcpwm_Pwm_Drv_ConfigCounter(uint8 McpwmId, const Mcpwm_Pwm_Drv_CounterType * CntCfg)
{
    Reg_Mcpwm_BfType *BaseBf = (Reg_Mcpwm_BfType *)Mcpwm_Pwm_Drv_PwmRegBfPtr[McpwmId];

    Mcpwm_Pwm_Drv_PeriodDither[McpwmId][CntCfg->CntId] = CntCfg->PwmPeriodDither;

    if(MCPWM_PWM_DRV_COUNTING_UP_AND_DOWN == Mcpwm_Pwm_Drv_CounterMode[McpwmId][CntCfg->CntId << 1])
    {
        Mcpwm_Pwm_Drv_SetCounterModVal(McpwmId, CntCfg->CntId, CntCfg->PwmPeriod >> 1U);
    }
    else 
    {
        Mcpwm_Pwm_Drv_SetCounterModVal(McpwmId, CntCfg->CntId, CntCfg->PwmPeriod - 1U);
    }

    BaseBf->MCPWM_DTVALn[CntCfg->CntId].DTVAL = CntCfg->DeadTimeVal;

#if (MCPWM_PWM_DRV_NOTIFICATION_SUPPORTED == STD_ON)
    Mcpwm_Pwm_Drv_SetCounterOverflowInt(McpwmId, CntCfg->CntId << 1, FALSE);
#else
    if(TRUE == CntCfg->OverflowIrqEn)
    {
        Mcpwm_Pwm_Drv_SetCounterOverflowInt(McpwmId, CntCfg->CntId << 1, TRUE);
        Mcpwm_Pwm_Drv_OverflowIrqCallbacks[McpwmId][CntCfg->CntId] = CntCfg->OverflowCb;
    }
#endif
}

/**
 * @brief     Configure the MCPWM module.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] InstanceCfg: The instance configuration pointer of MCPWM to be configured. 
 * 
 * @return   None
 *
 */
static void Mcpwm_Pwm_Drv_ConfigInstance(uint8 McpwmId, const Mcpwm_Pwm_Drv_ConfigType * InstanceCfg)
{
    uint8 CounterIndex;
    Reg_Mcpwm_BfType *BaseBf = (Reg_Mcpwm_BfType *)Mcpwm_Pwm_Drv_PwmRegBfPtr[McpwmId];

    BaseBf->MCPWM_TIMEBASE.PSDIV = (uint32)InstanceCfg->ClkDiv;
    BaseBf->MCPWM_TIMEBASE.CKSRC = (uint32)InstanceCfg->ClkSrc;
    if(FALSE == InstanceCfg->GlobalCntEn)
    {
        for(CounterIndex = 0; CounterIndex < InstanceCfg->CounterNum; CounterIndex++)
        {
            Mcpwm_Pwm_Drv_ConfigCounter(McpwmId, InstanceCfg->CounterConfig[CounterIndex]);
        }
    }
    else
    {
        Mcpwm_Pwm_Drv_ConfigCounter(McpwmId, InstanceCfg->CounterConfig[0]);
        BaseBf->MCPWM_GLBCR.GLBCNTEN = 1U;
    }
    BaseBf->MCPWM_OUTTRIG.INITRIGE = (uint32)InstanceCfg->InitTrigEn;
}

/**
 * @brief     Initialize the configured channels of MCPWM module.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChCfg: The channels configuration pointer. 
 * 
 * @return   None
 *
 */
static void Mcpwm_Pwm_Drv_InitChannel(uint8 McpwmId, const Mcpwm_Pwm_Drv_ChannelConfigType * ChCfg)
{
    uint8 ChannelId;
    uint8 CounterId;
    uint8  PairId; 
    Reg_Mcpwm_WType * BaseW;
    Reg_Mcpwm_BfType * BaseBf;

#if(MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(MCPWM_PWM_DRV_INSTANCE_NUM > McpwmId);
    MCALLIB_DEV_ASSERT(NULL_PTR != ChCfg);
#endif

    BaseW = (Reg_Mcpwm_WType *)Mcpwm_Pwm_Drv_PwmRegWPtr[McpwmId];
    BaseBf = (Reg_Mcpwm_BfType *)Mcpwm_Pwm_Drv_PwmRegBfPtr[McpwmId];

    ChannelId = ChCfg->ChannelId;
    CounterId = ChannelId >> 1UL;
    PairId = CounterId;


    Mcpwm_Pwm_Drv_DutyCycle[McpwmId][ChannelId] = 0;
    Mcpwm_Pwm_Drv_PolarityState[McpwmId][ChannelId] = ChCfg->Polarity;

    Mcpwm_Pwm_Drv_SetChannelPolarity(BaseBf, ChannelId, ChCfg->Polarity);
    Mcpwm_Pwm_Drv_ChannelDither[McpwmId][ChannelId] = ChCfg->ChannelDither;
    Mcpwm_Pwm_Drv_SetChannelOffValue(BaseBf, ChannelId, Mcpwm_Pwm_Drv_OffValue[McpwmId][ChannelId]);
    /* Set Channel Pulse Polarity */
    BaseBf->MCPWM_CFGn[ChannelId].CPP = (uint32)MCPWM_PWM_DRV_LOW_PULSE_POL;
    Mcpwm_Pwm_Drv_ControlChannelMatchTrigger(BaseBf, ChannelId, ChCfg->ChannelMatchTrigEnable);
    Mcpwm_Pwm_Drv_SetChannelMode(McpwmId, ChannelId, ChCfg->ChannelMode);
    BaseBf->MCPWM_CVn[ChannelId].CV = 0xFFFFU;
    BaseBf->MCPWM_CVn_DITHER[ChannelId].CV_DITHER = Mcpwm_Pwm_Drv_ChannelDither[McpwmId][ChannelId];

    if(0U == (ChannelId % 2U))
    {
        if(NULL_PTR != ChCfg->PairCfg)
        {
            Mcpwm_Pwm_Drv_ControlPairDeadtime(BaseBf, PairId, ChCfg->PairCfg->DeadTimeEnable);
            if(TRUE == Mcpwm_Pwm_Drv_GetCombineConfig(BaseBf, ChannelId))
            {
                Mcpwm_Pwm_Drv_PhaseShift[McpwmId][PairId] = ChCfg->PairCfg->PhaseShiftValue;
            }
        }
    }

    BaseBf->MCPWM_CFGn[ChannelId].DMA = (uint32)ChCfg->DmaEn;

    Mcpwm_Pwm_Drv_SetChannelOCV(BaseBf, ChannelId, Mcpwm_Pwm_Drv_IdleState[McpwmId][ChannelId]);
    Mcpwm_Pwm_Drv_ChannelState[McpwmId][ChannelId] = MCPWM_PWM_DRV_CHANNEL_RUNNING;


#if (MCPWM_PWM_DRV_NOTIFICATION_SUPPORTED == STD_ON)
    BaseBf->MCPWM_CFGn[ChannelId].CHIE = FALSE;
    Mcpwm_Pwm_Drv_ChIrqCallbacks[McpwmId][ChannelId] = ChCfg->ChannelCb;
    Mcpwm_Pwm_Drv_OverflowIrqCallbacks[McpwmId][ChannelId] = ChCfg->ChannelCb;
#else
    if(TRUE == ChCfg->ChIrqEn)
    {
        Mcpwm_Pwm_Drv_ChIrqCallbacks[McpwmId][ChannelId] = ChCfg->ChannelCb;
        BaseBf->MCPWM_CFGn[ChannelId].CHIE = TRUE;
    }
#endif

    if(TRUE == ChCfg->ChannelOutputEnable)
    {
        /* Enable Channel Output */
        BaseW->MCPWM_GLBCR |= (0x01UL << (uint32)ChannelId);
    }
    else
    {
        /* Disable Channel Output */
        BaseW->MCPWM_GLBCR &= ~(0x01UL << (uint32)ChannelId);
    }

    /* Clear Channel Int */
    BaseBf->MCPWM_CFGn[ChannelId].CHF = 0U;
        
#if(MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     Initialize the MCPWM module.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] InstanceCfg: The configuration pointer of the MCPWM. 
 * 
 * @return   None
 *
 */
static void Mcpwm_Pwm_Drv_InitInstance(uint8 McpwmId, const Mcpwm_Pwm_Drv_ConfigType * InstanceCfg)
{
    uint16 Index;
#if (MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(MCPWM_PWM_DRV_INSTANCE_NUM > McpwmId);
    MCALLIB_DEV_ASSERT(NULL_PTR != InstanceCfg);
#endif

    Mcpwm_Pwm_Drv_ConfigInstance(McpwmId, InstanceCfg);

    if(FALSE == InstanceCfg->GlobalCntEn)
    {
        for(Index = 0; Index < InstanceCfg->CounterNum; Index++)
        {
            Mcpwm_Pwm_Drv_Period[McpwmId][InstanceCfg->CounterConfig[Index]->CntId] = \
                                                InstanceCfg->CounterConfig[Index]->PwmPeriod;
        }
    }
    else
    {
        for(Index = 0U; Index < 4U; Index++)
        {
            Mcpwm_Pwm_Drv_Period[McpwmId][InstanceCfg->CounterConfig[Index]->CntId] = \
                                                InstanceCfg->CounterConfig[0]->PwmPeriod;
        }
    }

    Mcpwm_Pwm_Drv_ClockSource[McpwmId] = InstanceCfg->ClkSrc;
    Mcpwm_Pwm_Drv_ClockDivide[McpwmId] = InstanceCfg->ClkDiv;
        
#if(MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     Start to run the MCPWM module after initialization.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] InstanceCfg: The configuration pointer of the MCPWM. 
 * 
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_InitInstanceStart(uint8 McpwmId, 
                                      const Mcpwm_Pwm_Drv_ConfigType * InstanceCfg)
{
    Reg_Mcpwm_BfType * BaseBf;
    Reg_Mcpwm_WType * BaseW;
    uint8 Index;
    uint32 CountersMask = 0;
#if (MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(MCPWM_PWM_DRV_INSTANCE_NUM > McpwmId);
    MCALLIB_DEV_ASSERT(NULL_PTR != InstanceCfg);
#endif

    BaseW = (Reg_Mcpwm_WType *)Mcpwm_Pwm_Drv_PwmRegWPtr[McpwmId];
    BaseBf = (Reg_Mcpwm_BfType *)Mcpwm_Pwm_Drv_PwmRegBfPtr[McpwmId];

    if(FALSE == InstanceCfg->GlobalCntEn)
    {
        for(Index = 0; Index < InstanceCfg->CounterNum; Index++)
        {
            /* Clear Timer Overflow Flag */
            BaseW->MCPWM_GLBSR &= ~(0x01UL << (MCPWM_GLBSR_TOF_SHIFT + \
                                  (uint32)InstanceCfg->CounterConfig[Index]->CntId));
            /* Start Counter */
            CountersMask |= (0x01UL << (MCPWM_GLBCR_CNTEN_SHIFT + \
                                          (uint32)InstanceCfg->CounterConfig[Index]->CntId));
        }
        BaseW->MCPWM_GLBCR |= CountersMask;
    }
    else
    {
        /* Clear Timer Overflow Flag */
        BaseW->MCPWM_GLBSR &= ~(0x01UL << MCPWM_GLBSR_TOF_SHIFT);
        /* Start Global Counter */
        BaseBf->MCPWM_GLBCR.GLBCNTEN = 0x1U;
    }
        
#if(MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

#if (defined(MCPWM_PWM_DRV_NOTIFICATION_SUPPORTED) && \
                                             (MCPWM_PWM_DRV_NOTIFICATION_SUPPORTED == STD_ON))
/**
 * @brief     Set the output of the channel to sepcific state.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] ActiveState: The specific state to be output. 
 * 
 * @return   None
 *
 */
static void Mcpwm_Pwm_Drv_SetOutputForForcedChannel(uint8 McpwmId, uint8 ChannelId,
                                                boolean ActiveState)
{
    Reg_Mcpwm_BfType *BaseBf = (Reg_Mcpwm_BfType *)Mcpwm_Pwm_Drv_PwmRegBfPtr[McpwmId];
    
    if(TRUE == ActiveState)
    {
        Mcpwm_Pwm_Drv_DisableInterrupt(McpwmId, ChannelId);
    }
    else
    {
        if(MCPWM_PWM_DRV_NO_EDGE != (Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] & \
                                                                MCPWM_PWM_DRV_TOF_IRQ_EDGE))
        {
            Mcpwm_Pwm_Drv_SetCounterOverflowInt(McpwmId, ChannelId, TRUE);
        }
        
        if(MCPWM_PWM_DRV_NO_EDGE != (Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] & \
                         (MCPWM_PWM_DRV_CHF_IRQ_EDGE | MCPWM_PWM_DRV_CHF_COMBINE_IRQ_EDGE)))
        {
            SchM_Enter_Pwm_SetMcpwmChannelConfigurationRegister();

            BaseBf->MCPWM_CFGn[ChannelId].CHIE = TRUE;

            SchM_Exit_Pwm_SetMcpwmChannelConfigurationRegister();
        }
    }
}
#endif

/**
 * @brief     Update the period for the pair channnels.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] PairId: The id of the pair channels. 
 * @param[in] Period: The period to be updated. 
 * @param[in] SwTrigger: Enable/Disable update period immediatly. 
 * 
 * @return   None
 *
 */
static void Mcpwm_Pwm_Drv_UpdatePwmPeriod(uint8 McpwmId, uint8 PairId, uint32 Period,
                                    boolean SwTrigger)
{
    Reg_Mcpwm_BfType * BaseBf;
    uint8 pwmPairId;
#if(MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(McpwmId <MCPWM_PWM_DRV_INSTANCE_NUM);
#endif

    BaseBf = (Reg_Mcpwm_BfType *)Mcpwm_Pwm_Drv_PwmRegBfPtr[McpwmId];
    
    if(TRUE == (boolean)BaseBf->MCPWM_GLBCR.GLBCNTEN)
    {
        pwmPairId = 0U;
        Mcpwm_Pwm_Drv_Period[McpwmId][0] = (uint16)Period;
        Mcpwm_Pwm_Drv_Period[McpwmId][1] = (uint16)Period;
        Mcpwm_Pwm_Drv_Period[McpwmId][2] = (uint16)Period;
        Mcpwm_Pwm_Drv_Period[McpwmId][3] = (uint16)Period;
    }
    else
    {
        pwmPairId = PairId;
        Mcpwm_Pwm_Drv_Period[McpwmId][PairId] = (uint16)Period;
    }

    if(TRUE == Mcpwm_Pwm_Drv_GetCountingMode(BaseBf, pwmPairId))
    {
        Mcpwm_Pwm_Drv_SetCounterModVal(McpwmId, pwmPairId, (uint16)(Period >> 1U));
    }
    else
    {
        Mcpwm_Pwm_Drv_SetCounterModVal(McpwmId, pwmPairId, (uint16)(Period - 1U));
    }
   
    Mcpwm_Pwm_Drv_SetReloadEnable(BaseBf, pwmPairId, SwTrigger);

#if(MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

/**
 * @brief     Initialize the driver of MCPWM module with user configuration generated from AUTOSAR 
 *            code template.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] userCfg: The configuration pointer of user definition. 
 * 
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_Init(uint8 McpwmId, const Mcpwm_Pwm_Drv_UserCfgType * userCfg)
{
    uint8 Index;
    const Mcpwm_Pwm_Drv_ChannelConfigType *ChannelConfig;
#if (MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(MCPWM_PWM_DRV_INSTANCE_NUM > McpwmId);
    MCALLIB_DEV_ASSERT(NULL_PTR != userCfg);
#endif
    if(FALSE == userCfg->InstanceCfg->GlobalCntEn)
    {
        for(Index = 0; Index < userCfg->NoOfConfiguredCh; Index++)
        {
            ChannelConfig = userCfg->ConfiguredChArray[Index];
            if((ChannelConfig->ChannelMode == MCPWM_PWM_DRV_MODE_EDGE_ALIGNED) || 
                (ChannelConfig->ChannelMode == MCPWM_PWM_DRV_MODE_COMBINE_EDGE_ALIGNED) ||
                (ChannelConfig->ChannelMode == MCPWM_PWM_DRV_MODE_COMBINE_VARIABLE_EDGE_PLACEMENT))
            {
                Mcpwm_Pwm_Drv_CounterMode[McpwmId][ChannelConfig->ChannelId] =MCPWM_PWM_DRV_COUNTING_UP;
            }
            else
            {
                Mcpwm_Pwm_Drv_CounterMode[McpwmId][ChannelConfig->ChannelId] = \
                                                           MCPWM_PWM_DRV_COUNTING_UP_AND_DOWN;
            }
        }
    }
    else
    {
        for(Index = 0; Index < userCfg->NoOfConfiguredCh; Index++)
        {
            ChannelConfig = userCfg->ConfiguredChArray[Index];
            if((ChannelConfig->ChannelMode == MCPWM_PWM_DRV_MODE_EDGE_ALIGNED) || 
                (ChannelConfig->ChannelMode == MCPWM_PWM_DRV_MODE_COMBINE_EDGE_ALIGNED) ||
                (ChannelConfig->ChannelMode == MCPWM_PWM_DRV_MODE_COMBINE_VARIABLE_EDGE_PLACEMENT))
            {
                Mcpwm_Pwm_Drv_CounterMode[McpwmId][0] = MCPWM_PWM_DRV_COUNTING_UP;
            }
            else
            {
                Mcpwm_Pwm_Drv_CounterMode[McpwmId][0] = MCPWM_PWM_DRV_COUNTING_UP_AND_DOWN;
            }
        }        
    }
    Mcpwm_Pwm_Drv_InitInstance(McpwmId, userCfg->InstanceCfg);

    for(Index = 0; Index < userCfg->NoOfConfiguredCh; Index++)
    {
        Mcpwm_Pwm_Drv_InitChannel(McpwmId, userCfg->ConfiguredChArray[Index]);
    }
        
#if(MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     De-initialze the MCPWM module and reset all registers of MCPWM.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * 
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_DeInit(uint8 McpwmId)
{
    Reg_Mcpwm_WType *BaseW = (Reg_Mcpwm_WType *) Mcpwm_Pwm_Drv_PwmRegWPtr[McpwmId];

    /* Stop Counters */
    BaseW->MCPWM_GLBCR &= ~(MCPWM_GLBCR_CNTEN_MASK);

    BaseW->MCPWM_TIMEBASE = 0x0U;
    BaseW->MCPWM_GLBCR &= 0x0FFU;
    (void)BaseW->MCPWM_GLBSR;
    BaseW->MCPWM_GLBSR = 0x0U;
    BaseW->MCPWM_OUTCR &= 0x0FF00U;
    (void)BaseW->MCPWM_OUTTRIG;
    BaseW->MCPWM_OUTTRIG = 0x0U;
    BaseW->MCPWM_OUTSWCR = 0x0U;
    BaseW->MCPWM_PCR = 0x0U;
    BaseW->MCPWM_FLTCR = 0x0U;
    BaseW->MCPWM_FLTSR = 0x0U;
    BaseW->MCPWM_FLTASS = 0x0U;
    BaseW->MCPWM_FLTBSS = 0x0U;
    BaseW->MCPWM_SYNC = 0x0U;
    BaseW->MCPWM_RELOAD = 0x0U;
    BaseW->MCPWM_LDFREQ = 0x0U;
    
    for(uint8 Index = 0; Index <MCPWM_PWM_DRV_COUNTER_NUM; Index++)
    {
       BaseW->MCPWM_CNTn[Index] = 0x0U;
       BaseW->MCPWM_MODn[Index] = 0x0U;
       BaseW->MCPWM_DTVALn[Index] = 0x0U;
       (void)BaseW->MCPWM_CFGn[2U * Index];
       BaseW->MCPWM_CFGn[2U * Index] = 0x0U;
       (void)BaseW->MCPWM_CFGn[(2U * Index) + 1U];
       BaseW->MCPWM_CFGn[(2U * Index) + 1U] = 0x0U;
       BaseW->MCPWM_CVn[2U*Index] = 0x0U;
       BaseW->MCPWM_CVn[(2U * Index) + 1U] = 0x0U;
       BaseW->MCPWM_MODn_DITHER[Index] = 0x0U;
       BaseW->MCPWM_CVn_DITHER[2U*Index] = 0x0U;
       BaseW->MCPWM_CVn_DITHER[(2U*Index) + 1U] = 0x0U;

       Mcpwm_Pwm_Drv_NotifIrq[McpwmId][2U * Index] = 0x0U;
       Mcpwm_Pwm_Drv_NotifIrq[McpwmId][(2U * Index) + 1U] = 0x0U;
    }
}

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
void Mcpwm_Pwm_Drv_SetDutyCycle(uint8 McpwmId, uint8 ChannelId, uint16 DutyCycle, boolean SwTrigger)
{
    Reg_Mcpwm_BfType *BaseBf = (Reg_Mcpwm_BfType *) Mcpwm_Pwm_Drv_PwmRegBfPtr[McpwmId];
    uint16 FirstEdge = 0;
    uint8 PairId;
    Mcpwm_Pwm_Drv_ChannelModeType Mode;

    PairId = ChannelId >> 1U;
    Mcpwm_Pwm_Drv_DutyCycle[McpwmId][ChannelId] = DutyCycle;

    Mode = Mcpwm_Pwm_Drv_ChannelMode[McpwmId][ChannelId];

#if (MCPWM_PWM_DRV_NOTIFICATION_SUPPORTED == STD_ON)
    Mcpwm_Pwm_Drv_CheckNotification(McpwmId, ChannelId);
#endif

    SchM_Enter_Pwm_SetMcpwmChannelState();
    if(MCPWM_PWM_DRV_CHANNEL_IDLE == Mcpwm_Pwm_Drv_ChannelState[McpwmId][ChannelId])
    {
        Mcpwm_Pwm_Drv_ChannelState[McpwmId][ChannelId] = MCPWM_PWM_DRV_CHANNEL_RUNNING;
        SchM_Exit_Pwm_SetMcpwmChannelState();

        Mcpwm_Pwm_Drv_SetChannelOCV(BaseBf, ChannelId, Mcpwm_Pwm_Drv_IdleState[McpwmId][ChannelId]);
        Mcpwm_Pwm_Drv_ControlChannelOC(BaseBf, ChannelId, FALSE);                                  
    }
    else
    {
        SchM_Exit_Pwm_SetMcpwmChannelState();
    }

    if((Mode == MCPWM_PWM_DRV_MODE_EDGE_ALIGNED) || (Mode == MCPWM_PWM_DRV_MODE_COMBINE_EDGE_ALIGNED))
    {
        (void)Mcpwm_Pwm_Drv_UpdatePwmChannel(McpwmId, ChannelId, DutyCycle, DutyCycle, SwTrigger); 
    }
    else if((Mode == MCPWM_PWM_DRV_MODE_CENTER_ALIGNED) || (Mode == \
                                               MCPWM_PWM_DRV_MODE_COMBINE_SYM_CENTER_ALIGNED))
    {
        (void)Mcpwm_Pwm_Drv_UpdatePwmChannel(McpwmId, ChannelId, DutyCycle >> 1U, \
                                                                  DutyCycle >> 1U, SwTrigger); 
    }
    else if(Mode ==MCPWM_PWM_DRV_MODE_COMBINE_VARIABLE_EDGE_PLACEMENT)
    {
        if(0U == DutyCycle )
        {
            (void)Mcpwm_Pwm_Drv_UpdatePwmChannel(McpwmId, ChannelId, 0, \
                                       Mcpwm_Pwm_Drv_Period[McpwmId][PairId] + 1U, SwTrigger);
        }
        else if(DutyCycle == Mcpwm_Pwm_Drv_Period[McpwmId][PairId])
        {
            (void)Mcpwm_Pwm_Drv_UpdatePwmChannel(McpwmId, ChannelId, DutyCycle, 0, SwTrigger);
        }
        else 
        {
            FirstEdge = Mcpwm_Pwm_Drv_Period[McpwmId][PairId] 
                            + Mcpwm_Pwm_Drv_PhaseShift[McpwmId][PairId] - DutyCycle;
            (void)Mcpwm_Pwm_Drv_UpdatePwmChannel(McpwmId, ChannelId, \
                                Mcpwm_Pwm_Drv_PhaseShift[McpwmId][PairId], FirstEdge, SwTrigger);    
        }
    }
    else
    {
        /* Do Nothing */
    }
  
}

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
                                boolean SwTrigger)
{
    Reg_Mcpwm_BfType * BaseBf;
    uint16 TempDutyCycle = 0U;
    uint8 PairId = ChannelId >> 1U;

#if (MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(McpwmId <MCPWM_PWM_DRV_INSTANCE_NUM);
    MCALLIB_DEV_ASSERT(ChannelId <MCPWM_PWM_DRV_CHANNEL_NUM);
#endif

    BaseBf = (Reg_Mcpwm_BfType *) Mcpwm_Pwm_Drv_PwmRegBfPtr[McpwmId];

    SchM_Enter_Pwm_SetMcpwmChannelState();
    if(MCPWM_PWM_DRV_CHANNEL_IDLE == Mcpwm_Pwm_Drv_ChannelState[McpwmId][ChannelId])
    {
        Mcpwm_Pwm_Drv_ChannelState[McpwmId][ChannelId] =MCPWM_PWM_DRV_CHANNEL_RUNNING;
        SchM_Exit_Pwm_SetMcpwmChannelState();
        
        Mcpwm_Pwm_Drv_SetChannelOCV(BaseBf, ChannelId, Mcpwm_Pwm_Drv_IdleState[McpwmId][ChannelId]);
        Mcpwm_Pwm_Drv_ControlChannelOC(BaseBf, ChannelId, FALSE);                                  
    }
    else
    {
        SchM_Exit_Pwm_SetMcpwmChannelState();
    }

    if(0U == Period)
    {
        TempDutyCycle = 0;
    }
    else
    {
        TempDutyCycle = DutyCycle;

        if(TRUE == (boolean)BaseBf->MCPWM_GLBCR.GLBCNTEN)
        {
            Mcpwm_Pwm_Drv_UpdatePwmPeriod(McpwmId, 0U, Period, SwTrigger);
        }
        else
        {
            Mcpwm_Pwm_Drv_UpdatePwmPeriod(McpwmId, PairId, Period, SwTrigger);
        }
    }

    Mcpwm_Pwm_Drv_SetDutyCycle(McpwmId, ChannelId, TempDutyCycle, SwTrigger);
        
#if(MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

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
                                Mcpwm_Pwm_Drv_OutputStateType State, boolean ActiveState)
{
    Reg_Mcpwm_BfType * BaseBf;
#if(MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(McpwmId <MCPWM_PWM_DRV_INSTANCE_NUM);
    MCALLIB_DEV_ASSERT(ChannelId <MCPWM_PWM_DRV_CHANNEL_NUM);
#endif
    BaseBf = (Reg_Mcpwm_BfType *) Mcpwm_Pwm_Drv_PwmRegBfPtr[McpwmId];

    if((Mcpwm_Pwm_Drv_ChannelStateType)MCPWM_PWM_DRV_CHANNEL_IDLE == \
                                               Mcpwm_Pwm_Drv_ChannelState[McpwmId][ChannelId])
    {
        Mcpwm_Pwm_Drv_DutyCycle[McpwmId][ChannelId] = (uint16) 0U;
#if (defined(MCPWM_PWM_DRV_NOTIFICATION_SUPPORTED) && \
                                             (MCPWM_PWM_DRV_NOTIFICATION_SUPPORTED == STD_ON))
        SchM_Enter_Pwm_SetMcpwmNotifIrq();                        
        if(MCPWM_PWM_DRV_NO_EDGE != (Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] & \
                                                                MCPWM_PWM_DRV_TOF_IRQ_EDGE))
        {
            Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] |=MCPWM_PWM_DRV_IRQ_NO_EDGE_NOTIF;
        }
        SchM_Exit_Pwm_SetMcpwmNotifIrq();

        Mcpwm_Pwm_Drv_DisableInterrupt(McpwmId, ChannelId);        
    }
    else if((Mcpwm_Pwm_Drv_ChannelStateType)MCPWM_PWM_DRV_CHANNEL_OUTPUT_FORCED 
                    == Mcpwm_Pwm_Drv_ChannelState[McpwmId][ChannelId])
    {
        Mcpwm_Pwm_Drv_SetOutputForForcedChannel(McpwmId, ChannelId, ActiveState);
    }
#else 
    }
#endif
    else
    {
        /* Do Nothing */
    }

    Mcpwm_Pwm_Drv_SetChannelOCV(BaseBf, ChannelId, State);
    Mcpwm_Pwm_Drv_ControlChannelOC(BaseBf, ChannelId, ActiveState);
    
#if(MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

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
Mcpwm_Pwm_Drv_OutputStateType Mcpwm_Pwm_Drv_GetOutputState(uint8 McpwmId, uint8 ChannelId)
{
    Reg_Mcpwm_BfType const * BaseBf;
    boolean CounterEnable;
    boolean OutSwCtrState;
    Mcpwm_Pwm_Drv_PolarityType PolVal;
    boolean ChActive = TRUE;
    

#if(MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(MCPWM_PWM_DRV_INSTANCE_NUM > McpwmId);
    MCALLIB_DEV_ASSERT(MCPWM_PWM_DRV_CHANNEL_NUM > ChannelId);
#endif
    BaseBf = (Reg_Mcpwm_BfType *)Mcpwm_Pwm_Drv_PwmRegBfPtr[McpwmId];

    if(TRUE == (boolean)BaseBf->MCPWM_GLBCR.GLBCNTEN)
    {
        /* Using the global counter as channel counter */
        CounterEnable = TRUE;
    }
    else
    {
        CounterEnable = Mcpwm_Pwm_Drv_GetCounterState(BaseBf, ChannelId >> 1U);
    }
    if(TRUE == CounterEnable)
    {
        /* counter is running */
        OutSwCtrState = Mcpwm_Pwm_Drv_GetOutSwCtrState(BaseBf, ChannelId);
        if(TRUE == OutSwCtrState)
        { 
            /* channel output software control Enable */
            ChActive = Mcpwm_Pwm_Drv_GetOutSwCtrVal(BaseBf, ChannelId);          
        }
        else
        { 
            /* channel output software control disable */
            ChActive = Mcpwm_Pwm_Drv_IsChannelOutputActive(McpwmId, ChannelId);
        }

        PolVal = Mcpwm_Pwm_Drv_GetChannelPolVal(BaseBf, ChannelId);
        if(MCPWM_PWM_DRV_POL_LOW == PolVal)
        {
            ChActive = (~ChActive) & 0x1U;
        }
    }
    else
    {
        ChActive = (boolean)Mcpwm_Pwm_Drv_GetChannelOffVal(BaseBf, ChannelId);
    }
    
#if(MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
    return ((Mcpwm_Pwm_Drv_OutputStateType) ChActive);
}

/**
 * @brief     Disable the match notification of the channel.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * 
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_DisableNotification(uint8 McpwmId, uint8 ChannelId)
{
    uint8 CombineChannelId;
    Mcpwm_Pwm_Drv_ChannelModeType Mode;
#if(MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(MCPWM_PWM_DRV_INSTANCE_NUM > McpwmId);
    MCALLIB_DEV_ASSERT(MCPWM_PWM_DRV_CHANNEL_NUM > ChannelId);
#endif
    if((ChannelId % 2U) == 0U)
    {
        CombineChannelId = ChannelId + 1U;
    }
    else
    {
        CombineChannelId = ChannelId - 1U;
    }

    Mode = Mcpwm_Pwm_Drv_ChannelMode[McpwmId][ChannelId];
    if(MCPWM_PWM_DRV_MODE_COMBINE_VARIABLE_EDGE_PLACEMENT == Mode)
    {
        SchM_Enter_Pwm_SetMcpwmNotifIrq();
        Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] &= MCPWM_PWM_DRV_CHF_COMBINE_IRQ_EDGE;
        Mcpwm_Pwm_Drv_NotifIrq[McpwmId][CombineChannelId] &= (~MCPWM_PWM_DRV_CHF_COMBINE_IRQ_EDGE);
        SchM_Exit_Pwm_SetMcpwmNotifIrq();

        Mcpwm_Pwm_Drv_DisableInterrupt(McpwmId, ChannelId);
        Mcpwm_Pwm_Drv_DisableInterrupt(McpwmId, CombineChannelId);
    }
    else
    {
        Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] = MCPWM_PWM_DRV_NO_EDGE;

        Mcpwm_Pwm_Drv_DisableInterrupt(McpwmId, ChannelId);
    }
        
#if(MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

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
                                Mcpwm_Pwm_Drv_EdgeNotifType Notification)
{
    Reg_Mcpwm_BfType * BaseBf;
    Mcpwm_Pwm_Drv_ChannelModeType Mode;

#if(MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(MCPWM_PWM_DRV_INSTANCE_NUM > McpwmId);
    MCALLIB_DEV_ASSERT(MCPWM_PWM_DRV_CHANNEL_NUM > ChannelId);
#endif
    
    BaseBf = (Reg_Mcpwm_BfType *) Mcpwm_Pwm_Drv_PwmRegBfPtr[McpwmId];

    SchM_Enter_Pwm_SetMcpwmNotifIrq();
    Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] &= (uint8)(~(MCPWM_PWM_DRV_CHF_IRQ_EDGE | \
                                                                   MCPWM_PWM_DRV_TOF_IRQ_EDGE));
    SchM_Exit_Pwm_SetMcpwmNotifIrq();

    SchM_Enter_Pwm_SetMcpwmChannelConfigurationRegister();
    /* Clear Channel Int */
    BaseBf->MCPWM_CFGn[ChannelId].CHF = 0U;
    SchM_Exit_Pwm_SetMcpwmChannelConfigurationRegister();
   
    /* Clear Counter Overflow Int */
    Mcpwm_Pwm_Drv_ClearCounterOverflow(McpwmId, ChannelId);


    Mode = Mcpwm_Pwm_Drv_ChannelMode[McpwmId][ChannelId];
    if(MCPWM_PWM_DRV_MODE_EDGE_ALIGNED == Mode)
    {
        Mcpwm_Pwm_Drv_UpdateNotificationStateEdge(McpwmId, ChannelId, Notification);
    }
    else if (MCPWM_PWM_DRV_MODE_COMBINE_EDGE_ALIGNED == Mode)
    {
        Mcpwm_Pwm_Drv_UpdateNotificationStateEdgeCombine(McpwmId, ChannelId, Notification);
    }
    
    else if((MCPWM_PWM_DRV_MODE_CENTER_ALIGNED == Mode) || \
                                 (MCPWM_PWM_DRV_MODE_COMBINE_SYM_CENTER_ALIGNED == Mode))
    {
        Mcpwm_Pwm_Drv_UpdateNotificationStateCenter(McpwmId, ChannelId, Notification);
    }
    else
    {
        /* MCPWM_PWM_DRV_MODE_COMBINE_VARIABLE_EDGE_PLACEMENT == Mode */
        Mcpwm_Pwm_Drv_UpdateNotificationStateCombine(McpwmId, ChannelId, Notification);
    }

    if((0U != Mcpwm_Pwm_Drv_DutyCycle[McpwmId][ChannelId]) &&
        (Mcpwm_Pwm_Drv_Period[McpwmId][ChannelId >> 1U] != \
                                                   Mcpwm_Pwm_Drv_DutyCycle[McpwmId][ChannelId]))
    {
        Mcpwm_Pwm_Drv_SetNormalNotificationCase(McpwmId, ChannelId);
    }
    else
    {
        SchM_Enter_Pwm_SetMcpwmNotifIrq();
        Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] |= MCPWM_PWM_DRV_IRQ_NO_EDGE_NOTIF;
        SchM_Exit_Pwm_SetMcpwmNotifIrq();

        Mcpwm_Pwm_Drv_DisableInterrupt(McpwmId, ChannelId);
    }
        
#if(MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     Update the duty cycle when channel output in variable edge placement mode.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] FirstEdge: The first edge to start of the active state of PWM. 
 * @param[in] SecondEdge: The second edge to end of the active state of PWM. 
 * @param[in] SwTrigger: Enable/Disable update the dutycycle immediatly. 
 * 
 * @return   None
 *
 */
static Mcpwm_Pwm_Drv_StatusType Mcpwm_Pwm_Drv_UpdatePwmChannel(uint8 McpwmId, uint8 ChannelId, 
                                            uint16 FirstEdge, uint16 SecondEdge, boolean SwTrigger)
{
    Reg_Mcpwm_BfType * BaseBf;
    Mcpwm_Pwm_Drv_StatusType RetStatus =MCPWM_PWM_DRV_STATUS_SUCCESS;
    uint8 PairId = ChannelId >> 1UL;

#if(MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(McpwmId <MCPWM_PWM_DRV_INSTANCE_NUM);
    MCALLIB_DEV_ASSERT(ChannelId <MCPWM_PWM_DRV_CHANNEL_NUM);
#endif
    BaseBf = (Reg_Mcpwm_BfType *)Mcpwm_Pwm_Drv_PwmRegBfPtr[McpwmId];

    if(TRUE == Mcpwm_Pwm_Drv_GetDualCombineCmd(BaseBf, PairId))
    {
        SchM_Enter_Pwm_SetMcpwmChannelValueRegister();
        BaseBf->MCPWM_CVn[PairId << 1U].CV = (uint32)FirstEdge;
        BaseBf->MCPWM_CVn[(PairId << 1U) + 1U].CV = (uint32)SecondEdge;

        BaseBf->MCPWM_CVn_DITHER[PairId << 1U].CV_DITHER = \
                                        Mcpwm_Pwm_Drv_ChannelDither[McpwmId][PairId << 1U];
        BaseBf->MCPWM_CVn_DITHER[(PairId << 1U) + 1U].CV_DITHER = \
                                        Mcpwm_Pwm_Drv_ChannelDither[McpwmId][(PairId << 1U) + 1U];
        SchM_Exit_Pwm_SetMcpwmChannelValueRegister();

        Mcpwm_Pwm_Drv_ControlChannelOC(BaseBf, PairId << 1U, FALSE);
        Mcpwm_Pwm_Drv_ControlChannelOC(BaseBf, (PairId << 1U) + 1U, FALSE);       
    }
    else /* if(FALSE == Mcpwm_Pwm_Drv_GetDualCombineCmd(BaseBf, PairId)) */
    {
        SchM_Enter_Pwm_SetMcpwmChannelValueRegister();
        BaseBf->MCPWM_CVn[ChannelId].CV = (uint32)FirstEdge;
        BaseBf->MCPWM_CVn_DITHER[ChannelId].CV_DITHER = \
                                                Mcpwm_Pwm_Drv_ChannelDither[McpwmId][ChannelId];
        SchM_Exit_Pwm_SetMcpwmChannelValueRegister();
        
        Mcpwm_Pwm_Drv_ControlChannelOC(BaseBf, ChannelId, FALSE);
    }

    Mcpwm_Pwm_Drv_SetReloadEnable(BaseBf, PairId, SwTrigger);
    
#if(MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
    return RetStatus;
}

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
                            boolean SoftwareShift)
{
    uint8 PairId;
    uint16 DutyCycleVal;
    Reg_Mcpwm_BfType * BaseBf;

#if(MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    Mcpwm_Pwm_Drv_ChannelModeType Mode;
    uint16 ChCV = 0U;
    boolean CheckChMode = TRUE;
    boolean RetVal = TRUE;

    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(MCPWM_PWM_DRV_INSTANCE_NUM > McpwmId);
    MCALLIB_DEV_ASSERT(MCPWM_PWM_DRV_CHANNEL_NUM > ChannelId);

    Mode = Mcpwm_Pwm_Drv_ChannelMode[McpwmId][ChannelId];

    if(MCPWM_PWM_DRV_MODE_COMBINE_VARIABLE_EDGE_PLACEMENT != Mode)
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

    BaseBf = (Reg_Mcpwm_BfType *)Mcpwm_Pwm_Drv_PwmRegBfPtr[McpwmId];
    Mcpwm_Pwm_Drv_Period[McpwmId][PairId] = Period;

    if(TRUE == Mcpwm_Pwm_Drv_GetCountingMode(BaseBf, PairId))
    {
        Mcpwm_Pwm_Drv_SetCounterModVal(McpwmId, PairId, (uint16)(Period >> 1U));
    }
    else
    {
        Mcpwm_Pwm_Drv_SetCounterModVal(McpwmId, PairId, (uint16)(Period - 1U));
    }


    DutyCycleVal = (uint16)(Period >> 1U);
    Mcpwm_Pwm_Drv_DutyCycle[McpwmId][ChannelId] = DutyCycleVal;

    SchM_Enter_Pwm_SetMcpwmChannelValueRegister();
    BaseBf->MCPWM_CVn[PairId << 1U].CV = (uint32)PhaseShift;
    BaseBf->MCPWM_CVn[(PairId << 1U) + 1U].CV = (uint32)PhaseShift + (uint32)DutyCycleVal;

    BaseBf->MCPWM_CVn_DITHER[PairId << 1U].CV_DITHER = \
                                        Mcpwm_Pwm_Drv_ChannelDither[McpwmId][PairId << 1U];
    BaseBf->MCPWM_CVn_DITHER[(PairId << 1U) + 1U].CV_DITHER = \
                                        Mcpwm_Pwm_Drv_ChannelDither[McpwmId][(PairId << 1U) + 1U];
    SchM_Exit_Pwm_SetMcpwmChannelValueRegister();

    Mcpwm_Pwm_Drv_SetReloadEnable(BaseBf, PairId, SoftwareShift);
    
#if(MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     Set the duty cycle of PWM output while channel worked in variable edge placement 
 *            output mode.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 * @param[in] DutyCycle: The dutycycle to be set. 
 * @param[in] PhaseShift: The start of the active state of PWM output to be set. 
 * @param[in] SotfwareTrigger: Enable/Disable the configuration updated immediately. 
 * 
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_SetDutyPhaseShift(uint8 McpwmId, uint8 ChannelId, uint16 DutyCycle,
                               uint16 PhaseShift, boolean SotfwareTrigger)
{
    uint16 FirstEdge = 0U;
    uint16 SecondEdge = 0U;
    uint8 PairId = ChannelId >> 1U;
#if(MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    Mcpwm_Pwm_Drv_ChannelModeType Mode;
    uint16 ChCV = 0U;
    boolean CheckChMode = TRUE;
    boolean RetVal = TRUE;

    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(MCPWM_PWM_DRV_INSTANCE_NUM > McpwmId);
    MCALLIB_DEV_ASSERT(MCPWM_PWM_DRV_CHANNEL_NUM > ChannelId);

    Mode = Mcpwm_Pwm_Drv_ChannelMode[McpwmId][ChannelId];

    if(MCPWM_PWM_DRV_MODE_COMBINE_VARIABLE_EDGE_PLACEMENT != Mode)
    {
        CheckChMode = FALSE;
    }

    MCALLIB_DEV_ASSERT(CheckChMode != FALSE);

    if((Mcpwm_Pwm_Drv_Period[McpwmId][PairId] != DutyCycle) && (DutyCycle != 0U))
    {
        ChCV = PhaseShift + Mcpwm_Pwm_Drv_Period[McpwmId][PairId] -  DutyCycle;
        if((ChCV <= PhaseShift) || (Mcpwm_Pwm_Drv_Period[McpwmId][PairId] <= ChCV))
        {
            RetVal = FALSE;
        }
    }
    MCALLIB_DEV_ASSERT(RetVal != FALSE);
    (void)CheckChMode;
    (void)RetVal;
#endif

    Mcpwm_Pwm_Drv_PhaseShift[McpwmId][PairId] = PhaseShift;
    Mcpwm_Pwm_Drv_DutyCycle[McpwmId][ChannelId] = DutyCycle;

    if(0U == PhaseShift)
    {
        FirstEdge = 1U;
    }
    else
    {
        FirstEdge = PhaseShift;
    }

    if(Mcpwm_Pwm_Drv_Period[McpwmId][PairId] == DutyCycle)
    {
        SecondEdge = Mcpwm_Pwm_Drv_PhaseShift[McpwmId][PairId];
    }
    else if (0U == DutyCycle)
    {
        SecondEdge = Mcpwm_Pwm_Drv_Period[McpwmId][PairId];
    }
    else
    {
        SecondEdge = Mcpwm_Pwm_Drv_PhaseShift[McpwmId][PairId] + \
                                            Mcpwm_Pwm_Drv_Period[McpwmId][PairId] - DutyCycle;
    }

    (void)Mcpwm_Pwm_Drv_UpdatePwmChannel(McpwmId,ChannelId,FirstEdge,SecondEdge,SotfwareTrigger);
        
#if(MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     This function is used to get current duty cycle of the channel 
 *
 * @param[in] McpwmId:   The id of the MCPWM module. 
 * @param[in] ChannelId: The id of the channel. 
 *
 * @return    uint16     DutyCyclePu of the specified logic channel
 */
uint16 Mcpwm_Pwm_Drv_GetChannelDutyCycle(uint8 McpwmId, uint8 ChannelId)
{
    uint32 DutyCyclePu = (uint16)0U;
#if(MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(MCPWM_PWM_DRV_INSTANCE_NUM > McpwmId);
    MCALLIB_DEV_ASSERT(MCPWM_PWM_DRV_CHANNEL_NUM > ChannelId);
#endif
    Reg_Mcpwm_BfType const * BaseBf = (Reg_Mcpwm_BfType *)Mcpwm_Pwm_Drv_PwmRegBfPtr[McpwmId];
    Mcpwm_Pwm_Drv_ChannelModeType Mode = Mcpwm_Pwm_Drv_ChannelMode[McpwmId][ChannelId];
    uint8 PairlId = ChannelId >> 1U;
    uint8 CounterId;
    uint32 PeriodValue;
    uint32 CompValue;

    if(FALSE == Mcpwm_Pwm_Drv_GetOutSwCtrState(BaseBf, ChannelId))
    {       
        if(TRUE == (boolean)BaseBf->MCPWM_GLBCR.GLBCNTEN)
        {
            CounterId = 0U;
        }
        else
        {
            CounterId = PairlId;
        }

        if(TRUE == Mcpwm_Pwm_Drv_GetCountingMode(BaseBf, PairlId))
        {
            PeriodValue = BaseBf->MCPWM_MODn[CounterId].MOD;
        }
        else
        {
            PeriodValue = BaseBf->MCPWM_MODn[CounterId].MOD + 1UL;
        }

        if(MCPWM_PWM_DRV_MODE_COMBINE_VARIABLE_EDGE_PLACEMENT == Mode)
        {
            CompValue = BaseBf->MCPWM_CVn[(PairlId << 1U) + 1U].CV;
            if(CompValue > BaseBf->MCPWM_CVn[PairlId << 1U].CV)
            {
                CompValue = CompValue - BaseBf->MCPWM_CVn[PairlId << 1U].CV;
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
        else
        {
            CompValue = BaseBf->MCPWM_CVn[ChannelId].CV;
            if(TRUE == Mcpwm_Pwm_Drv_GetDualCombineCmd(BaseBf, CounterId))
            {
                if((ChannelId % 2U) != 0U)
                {
                    CompValue = PeriodValue - CompValue;
                }  
            }
        }

        DutyCyclePu = CompValue * 0x8000U / PeriodValue;
    }
      
#if(MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif

    return (uint16)DutyCyclePu;
}

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
void Mcpwm_Pwm_Drv_SetChannelDeadTime(uint8 McpwmId, uint8 ChannelId, uint16 DeadTimeVal)
{
    Reg_Mcpwm_WType * BaseW;
#if(MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(MCPWM_PWM_DRV_INSTANCE_NUM > McpwmId);
    MCALLIB_DEV_ASSERT(MCPWM_PWM_DRV_CHANNEL_NUM > ChannelId);
    Reg_Mcpwm_BfType const * BaseBf = (Reg_Mcpwm_BfType *)Mcpwm_Pwm_Drv_PwmRegBfPtr[McpwmId];
    MCALLIB_DEV_ASSERT(TRUE == Mcpwm_Pwm_Drv_GetDualCombineCmd(BaseBf, ChannelId >> 1U));
    MCALLIB_DEV_ASSERT(TRUE == Mcpwm_Pwm_Drv_GetDualChDeadTimeCmd(BaseBf, ChannelId >> 1U));
    MCALLIB_DEV_ASSERT(((DeadTimeVal < 4096U) && (DeadTimeVal > 0U)));
    (void)BaseBf;
#endif
    BaseW = (Reg_Mcpwm_WType *)Mcpwm_Pwm_Drv_PwmRegWPtr[McpwmId];

    BaseW->MCPWM_DTVALn[ChannelId >> 1U] = DeadTimeVal;
        
#if(MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     Enable the triggers that triggerMask activated.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] TriggerMask: The triggers activated mask. 
 * 
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_EnableTrigger(uint8 McpwmId, uint32 TriggerMask)
{
    Reg_Mcpwm_WType * BaseW;
    uint32 Reg;
#if(MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(MCPWM_PWM_DRV_INSTANCE_NUM > McpwmId);
#endif
    BaseW = (Reg_Mcpwm_WType*) Mcpwm_Pwm_Drv_PwmRegWPtr[McpwmId];

    SchM_Enter_Pwm_SetMcpwmOutputTriggerRegister();
    
    Reg = BaseW->MCPWM_OUTTRIG;
    Reg |= TriggerMask;
    BaseW->MCPWM_OUTTRIG = Reg;

    SchM_Exit_Pwm_SetMcpwmOutputTriggerRegister();
        
#if(MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     Disable the triggers that triggerMask activated.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] TriggerMask: The triggers activated mask. 
 * 
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_DisableTrigger(uint8 McpwmId, uint32 TriggerMask)
{
    Reg_Mcpwm_WType * BaseW;
    uint32 Reg;
#if(MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(MCPWM_PWM_DRV_INSTANCE_NUM > McpwmId);
#endif
    BaseW = (Reg_Mcpwm_WType *)Mcpwm_Pwm_Drv_PwmRegWPtr[McpwmId];

    SchM_Enter_Pwm_SetMcpwmOutputTriggerRegister();

    Reg = BaseW->MCPWM_OUTTRIG;
    Reg &= ~TriggerMask;
    BaseW->MCPWM_OUTTRIG = Reg;

    SchM_Exit_Pwm_SetMcpwmOutputTriggerRegister();
        
#if(MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief     Enable the reload mechanism of MCPWM module.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * 
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_SyncUpdate(uint8 McpwmId)
{
    Reg_Mcpwm_WType * BaseW = (Reg_Mcpwm_WType *) Mcpwm_Pwm_Drv_PwmRegWPtr[McpwmId];

    SchM_Enter_Pwm_SetMcpwmReloadRegister();
    BaseW->MCPWM_RELOAD |= MCPWM_RELOAD_LOADEN_MASK;
    SchM_Exit_Pwm_SetMcpwmReloadRegister();
}

/**
 * @brief     Disable the channel output as mask activate.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChannelMask: The channel to be masked. 
 * 
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_MaskOutputChannels(uint8 McpwmId, uint32 ChannelMask)
{
    Reg_Mcpwm_WType *BaseW = (Reg_Mcpwm_WType *) Mcpwm_Pwm_Drv_PwmRegWPtr[McpwmId];

    SchM_Enter_Pwm_SetMcpwmGlobalControlRegister();

    ChannelMask &= (uint32) 0xff;
    BaseW->MCPWM_GLBCR &= ~ChannelMask;

    SchM_Exit_Pwm_SetMcpwmGlobalControlRegister();
}

/**
 * @brief     Unmask the output of the channel.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] ChannelMask: The channel to be unmasked. 
 * 
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_UnMaskOutputChannels(uint8 McpwmId, uint32 ChannelMask)
{
    Reg_Mcpwm_WType *BaseW = (Reg_Mcpwm_WType *) Mcpwm_Pwm_Drv_PwmRegWPtr[McpwmId];

    SchM_Enter_Pwm_SetMcpwmGlobalControlRegister();

    ChannelMask &= (uint32) 0xff;
    BaseW->MCPWM_GLBCR |= ChannelMask;

    SchM_Exit_Pwm_SetMcpwmGlobalControlRegister();
}

/**
 * @brief     Set the power state of the MCPWM module.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * @param[in] PowerState: The power state to be set. 
 * 
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_SetPowerState(uint8 McpwmId, Mcpwm_Pwm_Drv_PowerStateType PowerState)
{
#if(MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_START();
    MCALLIB_DEV_ASSERT(MCPWM_PWM_DRV_INSTANCE_NUM > McpwmId);
#endif
    Reg_Mcpwm_BfType *BaseBf = (Reg_Mcpwm_BfType *) Mcpwm_Pwm_Drv_PwmRegBfPtr[McpwmId];
    
    if(MCPWM_PWM_DRV_LOW_POWER == PowerState)
    {
        SchM_Enter_Pwm_SetMcpwmTimeRegister();
        BaseBf->MCPWM_TIMEBASE.CKSRC = (uint32)MCPWM_PWM_DRV_CLK_DISABLE;
        SchM_Exit_Pwm_SetMcpwmTimeRegister();

        SchM_Enter_Pwm_SetMCPWMCounterRegister();
        /* Clear counter */
        BaseBf->MCPWM_CNTn[0].CNT = 0U;
        BaseBf->MCPWM_CNTn[1].CNT = 0U;
        BaseBf->MCPWM_CNTn[2].CNT = 0U;
        BaseBf->MCPWM_CNTn[3].CNT = 0U;
        SchM_Exit_Pwm_SetMCPWMCounterRegister();
    }
    else
    {
        SchM_Enter_Pwm_SetMcpwmTimeRegister();
        BaseBf->MCPWM_TIMEBASE.CKSRC = (uint32)Mcpwm_Pwm_Drv_ClockSource[McpwmId];
        BaseBf->MCPWM_TIMEBASE.PSDIV = (uint32)Mcpwm_Pwm_Drv_ClockDivide[McpwmId];
        SchM_Exit_Pwm_SetMcpwmTimeRegister();
    }
        
#if(MCPWM_PWM_DRV_DEV_ERROR_DETECT == STD_ON)
    MCALLIB_DEV_ASSERT_END();
#endif
}

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
Mcpwm_Pwm_Drv_ChannelModeType Mcpwm_Pwm_Drv_GetChannelMode(uint8 McpwmId, uint8 ChannelId)
{
    return Mcpwm_Pwm_Drv_ChannelMode[McpwmId][ChannelId];
}

/**
 * @brief     Get current state of the channel.
 *
 * @param[in] McpwmId: The id of MCPWM module.
 * @param[in] ChannelId: The id of the channel.
 *
 * @return   Current State of the channel.
 * @retval  MCPWM_PWM_DRV_CHANNEL_UNINIT: The Channel is uniniatialized.
 * @retval  MCPWM_PWM_DRV_CHANNEL_RUNNING: The Channel is running.
 * @retval  MCPWM_PWM_DRV_CHANNEL_IDLE: The Channel is in idle state.
 * @retval  MCPWM_PWM_DRV_CHANNEL_OUTPUT_FORCED: The Channel is in forced output state.
 *
 */
Mcpwm_Pwm_Drv_ChannelStateType Mcpwm_Pwm_Drv_GetCurrentChannelState(uint8 McpwmId, uint8 ChannelId)
{
    return Mcpwm_Pwm_Drv_ChannelState[McpwmId][ChannelId];
}

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
                                    Mcpwm_Pwm_Drv_ChannelStateType State)
{
    SchM_Enter_Pwm_SetMcpwmChannelState();
    Mcpwm_Pwm_Drv_PreviousChannelState[McpwmId][ChannelId] = \
                                              Mcpwm_Pwm_Drv_ChannelState[McpwmId][ChannelId];
    Mcpwm_Pwm_Drv_ChannelState[McpwmId][ChannelId] = State;
    SchM_Exit_Pwm_SetMcpwmChannelState();
}

/**
 * @brief     Revert current state of the channel.
 *
 * @param[in] McpwmId: The id of MCPWM module.
 * @param[in] ChannelId: The id of the channel.
 *
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_RevertCurrentChannelState(uint8 McpwmId, uint8 ChannelId)
{
    Mcpwm_Pwm_Drv_ChannelState[McpwmId][ChannelId] = \
                                      Mcpwm_Pwm_Drv_PreviousChannelState[McpwmId][ChannelId];
}

/**
 * @brief     Get current notif type of the channel.
 *
 * @param[in] McpwmId: The id of MCPWM module.
 * @param[in] ChannelId: The id of the channel.
 *
 * @return   None
 *
 */
Mcpwm_Pwm_Drv_EdgeInterruptType Mcpwm_Pwm_Drv_GetNotifFlag(uint8 McpwmId, uint8 ChannelId)
{
    return Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId];
}

/**
 * @brief     Get current period of the channel.
 *
 * @param[in] McpwmId: The id of MCPWM module.
 * @param[in] ChannelId: The id of the channel.
 *
 * @return   uint16 : Current period of the channel. 
 *
 */
uint16 Mcpwm_Pwm_Drv_GetPeriod(uint8 McpwmId, uint8 ChannelId)
{
    return Mcpwm_Pwm_Drv_Period[McpwmId][ChannelId >> 1U];
}


/**
 * @brief     Set current output mode of the channel.
 *
 * @param[in] McpwmId: The id of MCPWM module.
 * @param[in] ChannelId: The id of the channel.
 * @param[in] Mode: The output mode of the channel.
 *
 * @return   None
 *
 */
static void Mcpwm_Pwm_Drv_SetChannelMode(uint8 McpwmId, uint8 ChannelId, 
                            Mcpwm_Pwm_Drv_ChannelModeType Mode)
{
    Reg_Mcpwm_BfType *BaseBf = (Reg_Mcpwm_BfType *)Mcpwm_Pwm_Drv_PwmRegBfPtr[McpwmId];
    Reg_Mcpwm_WType *BaseW = (Reg_Mcpwm_WType *)Mcpwm_Pwm_Drv_PwmRegWPtr[McpwmId];
    uint8 PairId = ChannelId >> 1;

    if(TRUE == (boolean)BaseBf->MCPWM_GLBCR.GLBCNTEN)
    {
        PairId = 0;
    }
    else
    {
        /* Do Nothing */
    }

    switch(Mode)
    {
        case MCPWM_PWM_DRV_MODE_EDGE_ALIGNED:
            /* Set Counter Mode */
            BaseW->MCPWM_GLBCR &= ~(0x01UL << (MCPWM_GLBCR_CNTM_SHIFT + (uint32)PairId));
            Mcpwm_Pwm_Drv_SetPairCombineCmd(BaseBf, (ChannelId >> 1), FALSE);
            break;
        case MCPWM_PWM_DRV_MODE_CENTER_ALIGNED:
            /* Set Counter Mode */
            BaseW->MCPWM_GLBCR |= 0x01UL << (MCPWM_GLBCR_CNTM_SHIFT + (uint32)PairId);
            /* Full cycle reload */
            BaseW->MCPWM_RELOAD |= (0x01UL << (uint32)PairId);
            Mcpwm_Pwm_Drv_SetPairCombineCmd(BaseBf, (ChannelId >> 1), FALSE);
            break;
        case MCPWM_PWM_DRV_MODE_COMBINE_EDGE_ALIGNED:
            /* Set Counter Mode */
            BaseW->MCPWM_GLBCR &= ~(0x01UL << (MCPWM_GLBCR_CNTM_SHIFT + (uint32)PairId));
            Mcpwm_Pwm_Drv_SetPairCombineCmd(BaseBf, (ChannelId >> 1), TRUE);
            Mcpwm_Pwm_Drv_SetPairPec(BaseBf, (ChannelId >> 1), FALSE);
            break;
        case MCPWM_PWM_DRV_MODE_COMBINE_SYM_CENTER_ALIGNED:
            /* Set Counter Mode */
            BaseW->MCPWM_GLBCR |= 0x01UL << (MCPWM_GLBCR_CNTM_SHIFT + (uint32)PairId);
            /* Full cycle reload */
            BaseW->MCPWM_RELOAD |= (0x01UL << (uint32)PairId);
            Mcpwm_Pwm_Drv_SetPairCombineCmd(BaseBf, (ChannelId >> 1), TRUE);
            Mcpwm_Pwm_Drv_SetPairPec(BaseBf, (ChannelId >> 1), FALSE);
            Mcpwm_Pwm_Drv_ControlPairAsymmetric(BaseBf, (ChannelId >> 1),MCPWM_PWM_DRV_SYMMETRIC);
            break;
        case MCPWM_PWM_DRV_MODE_COMBINE_VARIABLE_EDGE_PLACEMENT:
            /* Set Counter Mode */
            BaseW->MCPWM_GLBCR &= ~(0x01UL << (MCPWM_GLBCR_CNTM_SHIFT + (uint32)PairId));
            Mcpwm_Pwm_Drv_SetPairCombineCmd(BaseBf, (ChannelId >> 1), TRUE);
            Mcpwm_Pwm_Drv_SetPairPec(BaseBf, (ChannelId >> 1), TRUE);
            break;
        default:
            /* Nothing to do */
            break;
    }
    Mcpwm_Pwm_Drv_ChannelMode[McpwmId][ChannelId] = Mode;
}

/**
 * @brief     Get current complementary config of the channel.
 *
 * @param[in] BaseBf: The hardware registers struct pointer for the MCPWM module. 
 * @param[in] ChannelId: The id of the channel.
 *
 * @return   boolean : The complementary is enable or disable.
 * @retval   TRUE: The complementary is enable.
 * @retval   FALSE: The complementary is disable.
 *
 */
LOCAL_INLINE boolean Mcpwm_Pwm_Drv_GetCombineConfig(const Reg_Mcpwm_BfType * BaseBf, uint8 ChannelId)
{
    uint8 PairId = ChannelId >> 1U;
    uint32 CombineConfig = 0;

    switch(PairId)
    {
        case 0:
            CombineConfig = BaseBf->MCPWM_PCR.COMB0;
            break;
        case 1:
            CombineConfig = BaseBf->MCPWM_PCR.COMB1;
            break;
        case 2:
            CombineConfig = BaseBf->MCPWM_PCR.COMB2;
            break;
        case 3:
            CombineConfig = BaseBf->MCPWM_PCR.COMB3;
            break;
        default:
            /* Nothing to do */
            break;
    }

    return (CombineConfig == 0U) ? FALSE: TRUE;

}

/**
 * @brief     Software trig the sync of registers for MOD and CCV.
 *
 * @param[in] McpwmId: The id of MCPWM module.
 *
 * @return    None 
 *
 */
void Mcpwm_Pwm_Drv_SoftwareUpdate(uint8 McpwmId)
{
   Reg_Mcpwm_BfType *BaseBf = (Reg_Mcpwm_BfType *)Mcpwm_Pwm_Drv_PwmRegBfPtr[McpwmId];

   BaseBf->MCPWM_SYNC.SWWRBUF = TRUE;
   BaseBf->MCPWM_SYNC.SWRSTCNT = TRUE;

   Mcpwm_Pwm_Drv_ControlPairSynchronization(BaseBf, 0U, TRUE);
   Mcpwm_Pwm_Drv_ControlPairSynchronization(BaseBf, 1U, TRUE);
   Mcpwm_Pwm_Drv_ControlPairSynchronization(BaseBf, 2U, TRUE);
   Mcpwm_Pwm_Drv_ControlPairSynchronization(BaseBf, 3U, TRUE);

   BaseBf->MCPWM_SYNC.SWTRIG = (uint32)TRUE;
}

/**
 * @brief     Software triggered, updated immediately after service call.
 *
 * @param[in] McpwmId: The id of MCPWM module.
 *
 * @return    None 
 *
 */
void Mcpwm_Pwm_Drv_UpdateNow(uint8 McpwmId)
{
    Reg_Mcpwm_BfType *BaseBf = (Reg_Mcpwm_BfType *)Mcpwm_Pwm_Drv_PwmRegBfPtr[McpwmId];

    SchM_Enter_Pwm_SetMcpwmSyncRegister();
    BaseBf->MCPWM_SYNC.SWTRIG = (uint32)TRUE;
    SchM_Exit_Pwm_SetMcpwmSyncRegister();
}

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
void Mcpwm_Pwm_Drv_InitIdleState(uint8 ModuleId,uint8 ChannelId, 
                                Mcpwm_Pwm_Drv_OutputStateType State)
{
    Mcpwm_Pwm_Drv_IdleState[ModuleId][ChannelId] = State;
}

/**
 * @brief     Init the offvalue of the channel.
 *
 * @param[in] ModuleId: The id of MCPWM module.
 * @param[in] ChannelId: The id of channel.
 * @param[in] State: The offvalue to be set.
 *
 * @return    None 
 *
 */
void Mcpwm_Pwm_Drv_InitOffValue(uint8 ModuleId, uint8 ChannelId, 
                                Mcpwm_Pwm_Drv_OutputStateType State)
{
    Mcpwm_Pwm_Drv_OffValue[ModuleId][ChannelId] = State;
}

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
Mcpwm_Pwm_Drv_OutputStateType Mcpwm_Pwm_Drv_GetIdleState(uint8 McpwmId, uint8 ChannelId)
{
    return Mcpwm_Pwm_Drv_IdleState[McpwmId][ChannelId];
}

/**
 * @brief     Processing overflow interrupt.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * 
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_ProcessTofInterrupt(uint8 McpwmId)
{
    Reg_Mcpwm_BfType const * BaseBf = (Reg_Mcpwm_BfType *)Mcpwm_Pwm_Drv_PwmRegBfPtr[McpwmId];
    Reg_Mcpwm_WType * BaseW = (Reg_Mcpwm_WType *)Mcpwm_Pwm_Drv_PwmRegWPtr[McpwmId];
    boolean TofIntEn;
    boolean TofFlag;
    uint8 CountId;
#if (MCPWM_PWM_DRV_NOTIFICATION_SUPPORTED == STD_ON)
    uint8 ChannelId;
    Mcpwm_Pwm_Drv_EdgeInterruptType ChnIrqNotif;
#endif

    if(TRUE == (boolean)BaseBf->MCPWM_GLBCR.GLBCNTEN)
    {
        TofIntEn =  (boolean)(0UL != (BaseW->MCPWM_GLBCR & (0x01UL << MCPWM_GLBCR_TOIE_SHIFT)));
        TofFlag = (boolean)(0UL != (BaseW->MCPWM_GLBSR & (0x01UL << MCPWM_GLBSR_TOF_SHIFT)));
        
        if((FALSE != TofIntEn) && (FALSE != TofFlag))
        {
            /* Clear Timer Overflow Flag */
            BaseW->MCPWM_GLBSR &= ~(0x01UL << MCPWM_GLBSR_TOF_SHIFT);

#if (MCPWM_PWM_DRV_NOTIFICATION_SUPPORTED == STD_ON)
            for(ChannelId = 0; ChannelId < MCPWM_PWM_DRV_CHANNEL_NUM; ChannelId++)
            {
                ChnIrqNotif = Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId];
                if((MCPWM_PWM_DRV_NO_EDGE != (ChnIrqNotif & MCPWM_PWM_DRV_TOF_IRQ_EDGE)) && 
                   (MCPWM_PWM_DRV_NO_EDGE == (ChnIrqNotif & MCPWM_PWM_DRV_IRQ_NO_EDGE_NOTIF)))
                {
                    if(NULL_PTR != Mcpwm_Pwm_Drv_OverflowIrqCallbacks[McpwmId][ChannelId])
                    {
                        Mcpwm_Pwm_Drv_OverflowIrqCallbacks[McpwmId][ChannelId]();
                    }
#else
                    if(NULL_PTR != Mcpwm_Pwm_Drv_OverflowIrqCallbacks[McpwmId][0U])
                    {
                        Mcpwm_Pwm_Drv_OverflowIrqCallbacks[McpwmId][0U]();
                    }
#endif
#if (MCPWM_PWM_DRV_NOTIFICATION_SUPPORTED == STD_ON)
                }
            }
#endif
        }
    }
    else
    {
        for(CountId = 0U; CountId < MCPWM_PWM_DRV_COUNTER_NUM; CountId++)
        {
            TofIntEn = (boolean)(0UL != (BaseW->MCPWM_GLBCR & \
                                  (0x01UL << (MCPWM_GLBCR_TOIE_SHIFT + (uint32)CountId))));
            TofFlag = (boolean)(0UL != (BaseW->MCPWM_GLBSR & \
                                   (0x01UL << (MCPWM_GLBSR_TOF_SHIFT + (uint32)CountId))));
            
            if((FALSE != TofIntEn) && ((uint8)FALSE != TofFlag))
            {
                /* Clear Timer Overflow Flag */
                BaseW->MCPWM_GLBSR &= ~(0x01UL << (MCPWM_GLBSR_TOF_SHIFT + (uint32)CountId));
                
#if (MCPWM_PWM_DRV_NOTIFICATION_SUPPORTED == STD_ON)
                /* for even channel */
                ChannelId = CountId << 1U;
                ChnIrqNotif = Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId];
                if((MCPWM_PWM_DRV_NO_EDGE != (ChnIrqNotif & MCPWM_PWM_DRV_TOF_IRQ_EDGE)) && 
                   (MCPWM_PWM_DRV_NO_EDGE == (ChnIrqNotif & MCPWM_PWM_DRV_IRQ_NO_EDGE_NOTIF)))
                {
                    if(NULL_PTR != Mcpwm_Pwm_Drv_OverflowIrqCallbacks[McpwmId][ChannelId])
                    {
                        Mcpwm_Pwm_Drv_OverflowIrqCallbacks[McpwmId][ChannelId]();
                    }
#else
                    if(NULL_PTR != Mcpwm_Pwm_Drv_OverflowIrqCallbacks[McpwmId][CountId])
                    {
                        Mcpwm_Pwm_Drv_OverflowIrqCallbacks[McpwmId][CountId]();
                    }
#endif
#if (MCPWM_PWM_DRV_NOTIFICATION_SUPPORTED == STD_ON)
                }
                /* for odd channel */
                ChannelId = (CountId << 1U) + 1U;
                ChnIrqNotif = Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId];
                if((MCPWM_PWM_DRV_NO_EDGE != (ChnIrqNotif & MCPWM_PWM_DRV_TOF_IRQ_EDGE)) && 
                   (MCPWM_PWM_DRV_NO_EDGE == (ChnIrqNotif & MCPWM_PWM_DRV_IRQ_NO_EDGE_NOTIF)))
                {
                    if(NULL_PTR != Mcpwm_Pwm_Drv_OverflowIrqCallbacks[McpwmId][ChannelId])
                    {
                        Mcpwm_Pwm_Drv_OverflowIrqCallbacks[McpwmId][ChannelId]();
                    }
                }
#endif
            }
        }
    }
}  


/**
 * @brief     Processing channel matching interrupt.
 *
 * @param[in] McpwmId: The id of the MCPWM module. 
 * 
 * @return   None
 *
 */
void Mcpwm_Pwm_Drv_ProcessCommonInterrupt(uint8 McpwmId)
{
    Reg_Mcpwm_BfType *BaseBf = (Reg_Mcpwm_BfType *) Mcpwm_Pwm_Drv_PwmRegBfPtr[McpwmId];
    boolean ChnIntEn;
    boolean ChnIntFlag;

    for(uint8 ChannelId = 0U; ChannelId < MCPWM_PWM_DRV_CHANNEL_NUM; ChannelId++)
    {
        ChnIntEn = (boolean)BaseBf->MCPWM_CFGn[ChannelId].CHIE;
        ChnIntFlag = (boolean)BaseBf->MCPWM_CFGn[ChannelId].CHF;
    
        if((FALSE != ChnIntEn) && (FALSE != ChnIntFlag))
        {
            /* Clear Channel Int */
            BaseBf->MCPWM_CFGn[ChannelId].CHF = 0U;

    #if (MCPWM_PWM_DRV_NOTIFICATION_SUPPORTED == STD_ON)
            Mcpwm_Pwm_Drv_EdgeInterruptType ChnIrqNotif = \
                 Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] & MCPWM_PWM_DRV_CHF_IRQ_EDGE;      
            if(MCPWM_PWM_DRV_NO_EDGE != ChnIrqNotif)
            {
    #endif
                if(NULL_PTR != Mcpwm_Pwm_Drv_ChIrqCallbacks[McpwmId][ChannelId])
                {
                    Mcpwm_Pwm_Drv_ChIrqCallbacks[McpwmId][ChannelId]();
                }
    #if (MCPWM_PWM_DRV_NOTIFICATION_SUPPORTED == STD_ON)
            }

            if(MCPWM_PWM_DRV_MODE_COMBINE_VARIABLE_EDGE_PLACEMENT == \
                                           Mcpwm_Pwm_Drv_ChannelMode[McpwmId][ChannelId])
            {
                uint8 CombineChannelId = ((ChannelId % 2U) == 0U) ? (ChannelId + 1U) : (ChannelId - 1U);
                ChnIrqNotif = Mcpwm_Pwm_Drv_NotifIrq[McpwmId][ChannelId] & \
                                                     MCPWM_PWM_DRV_CHF_COMBINE_IRQ_EDGE; 
                if(MCPWM_PWM_DRV_NO_EDGE != ChnIrqNotif)
                {
                    if(NULL_PTR != Mcpwm_Pwm_Drv_ChIrqCallbacks[McpwmId][CombineChannelId])
                    {
                        Mcpwm_Pwm_Drv_ChIrqCallbacks[McpwmId][CombineChannelId]();
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
