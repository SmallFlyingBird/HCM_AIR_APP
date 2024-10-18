/**************************************************************************************************/
/**
 * @file      : Tim_Drv.c
 * @brief     : Timer module source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup Gpt_Module
 *  @{
 */

/** @addtogroup Tim_Drv
 *  @brief Gpt low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Device_Regs.h"
#include "Tim_Drv.h"
#include "SchM_Gpt.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
/* Published information */
#define TIM_DRV_C_VENDOR_ID                   0x00B3U
#define TIM_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define TIM_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define TIM_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define TIM_DRV_C_SW_MAJOR_VERSION            1U
#define TIM_DRV_C_SW_MINOR_VERSION            2U
#define TIM_DRV_C_SW_PATCH_VERSION            1U

/* Check if current file and Tim_Drv header file are of the same vendor */
#if (TIM_DRV_C_VENDOR_ID != TIM_DRV_H_VENDOR_ID)
    #error "Vendor ID of Tim_Drv.c and Tim_Drv.h are different"
#endif
/* Check if current file and Tim_Drv header file are of the same Autosar version */
#if ((TIM_DRV_C_AR_RELEASE_MAJOR_VERSION != TIM_DRV_H_AR_RELEASE_MAJOR_VERSION) ||                 \
     (TIM_DRV_C_AR_RELEASE_MINOR_VERSION != TIM_DRV_H_AR_RELEASE_MINOR_VERSION) ||                 \
     (TIM_DRV_C_AR_RELEASE_REVISION_VERSION != TIM_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Tim_Drv.c and Tim_Drv.h are different"
#endif
/* Check if current file and Tim_Drv header file are of the same Software version */
#if ((TIM_DRV_C_SW_MAJOR_VERSION != TIM_DRV_H_SW_MAJOR_VERSION) ||                                 \
     (TIM_DRV_C_SW_MINOR_VERSION != TIM_DRV_H_SW_MINOR_VERSION) ||                                 \
     (TIM_DRV_C_SW_PATCH_VERSION != TIM_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Tim_Drv.c and Tim_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
/* Check if current file and Device_Regs.h are the same Autosar version */
#if ((TIM_DRV_C_AR_RELEASE_MAJOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) ||         \
      (TIM_DRV_C_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version of Tim_Drv.c and Device_Regs.h are different"
#endif

/* Check if current file and SchM_Gpt.h are the same Autosar version */
#if ((TIM_DRV_C_AR_RELEASE_MAJOR_VERSION != SCHM_GPT_H_AR_RELEASE_MAJOR_VERSION) ||            \
      (TIM_DRV_C_AR_RELEASE_MINOR_VERSION != SCHM_GPT_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version of Tim_Drv.c and SchM_Gpt.h are different"
#endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/** @} end of Private_MacroDefinition */

#if (TIM_DRV_ENABLE == STD_ON)

/** @defgroup Private_TypeDefinition
 *  @{
 */
/** @} end of group Private_TypeDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

/** @} end of group Private_VariableDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */
#define GPT_START_SEC_VAR_CLEARED_32
#include "Gpt_MemMap.h"
/**
 * @brief  Timer target time value.
 */
uint32 Tim_Drv_TargetValue[TIM_DRV_INSTANCE_COUNT][TIM_DRV_CHANNEL_COUNT];

#define GPT_STOP_SEC_VAR_CLEARED_32
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CONST_PTR
#include "Gpt_MemMap.h"
/**
 *  @brief Timer instance address array
 */
/* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer object, 
no side effects forseen by violating this rule.
The following four lines of code also violate this rule with the same reason.*/
static Reg_Tim_BfType *const Tim_Drv_TimRegBfPtr[TIM_DRV_INSTANCE_COUNT] = 
{
    (Reg_Tim_BfType *)TIM0_BASE_ADDR, 
    (Reg_Tim_BfType *)TIM1_BASE_ADDR,
    (Reg_Tim_BfType *)TIM2_BASE_ADDR,
    (Reg_Tim_BfType *)TIM3_BASE_ADDR
};

#define GPT_STOP_SEC_CONST_PTR
#include "Gpt_MemMap.h"

#define GPT_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Gpt_MemMap.h"
/**
 *  @brief Set the interrupt channel status.
 */
#if (TIM_DRV_0_ISR_ENABLE == STD_ON) || (TIM_DRV_1_ISR_ENABLE == STD_ON) ||                    \
    (TIM_DRV_2_ISR_ENABLE == STD_ON) || (TIM_DRV_3_ISR_ENABLE == STD_ON)
static Tim_Drv_ChannelStateType Tim_Drv_ChannelState[TIM_DRV_INSTANCE_COUNT][TIM_DRV_CHANNEL_COUNT];
#endif

#if (TIM_DRV_SET_DUAL_CLOCK_MODE == STD_ON)
/**
 *  @brief Set the clock status.
 */
static Tim_Drv_InstanceStateType Tim_Drv_ClockState[TIM_DRV_INSTANCE_COUNT];
#endif
/** @} end of group Global_VariableDefinition */

#define GPT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#if (TIM_DRV_0_ISR_ENABLE == STD_ON)
/**
 * @brief   Interrupt handler for Timer.
 *
 * @return  None
 */
ISR(Tim_Drv_0_ChIrqHandler);
#endif

#if (TIM_DRV_1_ISR_ENABLE == STD_ON)
/**
 * @brief   Interrupt handler for Timer.
 *
 * @return  None
 */
ISR(Tim_Drv_1_ChIrqHandler);
#endif

#if (TIM_DRV_2_ISR_ENABLE == STD_ON)
/**
 * @brief   Interrupt handler for Timer.
 *
 * @return  None
 */
ISR(Tim_Drv_2_ChIrqHandler);
#endif

#if (TIM_DRV_3_ISR_ENABLE == STD_ON)
/**
 * @brief   Interrupt handler for Timer.
 *
 * @return  None
 */
ISR(Tim_Drv_3_ChIrqHandler);
#endif
/** @} end of group Public_FunctionDeclaration */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
LOCAL_INLINE void   Tim_Drv_SetFreezebit(uint8 Instance, boolean FreezeBit);
LOCAL_INLINE void   Tim_Drv_SetInitValue(uint8 Instance, uint16 InitValue);
LOCAL_INLINE void   Tim_Drv_LoadCounterInitValue(uint8 Instance, uint16 Value);
LOCAL_INLINE void   Tim_Drv_ClearInterruptFlag(uint8 Instance, uint8 Channel);
LOCAL_INLINE void   Tim_Drv_EnableInterrupt(uint8 Instance, uint8 Channel, boolean Enable);
LOCAL_INLINE void   Tim_Drv_SelectClockSource(uint8 Instance, Tim_Drv_ClockSourceType ClockSource);
LOCAL_INLINE void   Tim_Drv_SetCompareValue(uint8 Instance, uint8 Channel, uint16 CompareValue);
LOCAL_INLINE void   Tim_Drv_SetModValue(uint8 Instance, uint16 ModValue);
LOCAL_INLINE void   Tim_Drv_SelectOutputCompareMode(uint8 Instance, uint8 Channel, boolean Enable);
LOCAL_INLINE void   Tim_Drv_SetPrescaler(uint8 Instance, Tim_Drv_PrescalerType PrescalerValue);
static       uint32 Tim_Drv_GetInterruptBitStatus(uint8 Instance, uint8 Channel);
#if (TIM_DRV_0_ISR_ENABLE == STD_ON) || (TIM_DRV_1_ISR_ENABLE == STD_ON) ||                    \
    (TIM_DRV_2_ISR_ENABLE == STD_ON) || (TIM_DRV_3_ISR_ENABLE == STD_ON)
LOCAL_INLINE void   Tim_Drv_EnableSyncCCV(uint8 Instance, uint8 Channel, boolean Enable);
LOCAL_INLINE void   Tim_Drv_EnableSyncSoftWareTrigger(uint8 Instance);
#endif
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#if (TIM_DRV_0_ISR_ENABLE == STD_ON) || (TIM_DRV_1_ISR_ENABLE == STD_ON) ||                    \
    (TIM_DRV_2_ISR_ENABLE == STD_ON) || (TIM_DRV_3_ISR_ENABLE == STD_ON)
/**
 * @brief       Timer interrupt handler
 *
 * @param[in]   Instance: TIMER peripheral instance number
 * @param[in]   Channel: Timer channel
 *
 * @return      None
 */
static void Tim_Drv_IntHandler(uint8 Instance, uint8 Channel)
{
    Reg_Tim_BfType *TimBfPtr = Tim_Drv_TimRegBfPtr[Instance];
    uint32 InterruptFlag;
    uint32 InterruptEnabled;
    uint32 OldCompareValue = 0U;
    uint32 TargetValue = 0U;

    /*Checks for spurious interrupts*/
    InterruptFlag = Tim_Drv_GetInterruptFlag(Instance, Channel);
    InterruptEnabled = Tim_Drv_GetInterruptBitStatus(Instance, Channel);

    if (TRUE == InterruptFlag)
    {
        /* Clear interrupt flag */
        TimBfPtr->TIM_CMCn[Channel].CHF = 0U;
        if (TRUE == InterruptEnabled)
        {
            OldCompareValue = Tim_Drv_GetCompareValue(Instance, Channel);
            TargetValue = Tim_Drv_TargetValue[Instance][Channel];

            if ((uint32)(OldCompareValue + TargetValue) > TIM_DRV_MAX_VALUE)
            {
                Tim_Drv_SetCompareValue(Instance, Channel,
                                     (uint16)(TargetValue - (TIM_DRV_MAX_VALUE - OldCompareValue + 1U)));
                Tim_Drv_EnableSyncCCV(Instance, Channel, TRUE);
                Tim_Drv_EnableSyncSoftWareTrigger(Instance);
                Tim_Drv_EnableSyncCCV(Instance, Channel, FALSE);
            }
            else
            {
                /*Set new compare value*/
                Tim_Drv_SetCompareValue(Instance, Channel, (uint16)(OldCompareValue + TargetValue));
                Tim_Drv_EnableSyncCCV(Instance, Channel, TRUE);
                Tim_Drv_EnableSyncSoftWareTrigger(Instance);
                Tim_Drv_EnableSyncCCV(Instance, Channel, FALSE);
            }
            /* Call upper layer handler */
            if ((TIM_DRV_BUSY == Tim_Drv_ChannelState[Instance][Channel].ChannelStatus) &&
                (NULL_PTR != Tim_Drv_ChannelState[Instance][Channel].Callback))
            {
                Tim_Drv_ChannelState[Instance][Channel].Callback(
                Tim_Drv_ChannelState[Instance][Channel].CallbackParam);
            }
        }
    }
}
#endif

/**
 * @brief       This function enable/Disable timer freeze bit.
 *
 * @param[in]   Instance: Timer hardware instance number
 * @param[in]   FreezeBit: Enable/Disable freeze bit
 *
 * @return      None
 */
LOCAL_INLINE void Tim_Drv_SetFreezebit(uint8 Instance, boolean FreezeBit)
{
    Reg_Tim_BfType *TimBfPtr = Tim_Drv_TimRegBfPtr[Instance];

    if (TRUE == FreezeBit)
    {
        TimBfPtr->TIM_TIMEBASE.DBGM = 0U;
    }
    else
    {
        TimBfPtr->TIM_TIMEBASE.DBGM = 3U;
    }
}

/**
 * @brief      This function sets timer counter initial value
 *
 * @param[in]  Instance:   Timer hardware instance number
 * @param[in]  InitValue:  Counter init value.
 *
 * @return     None
 *
 */
LOCAL_INLINE void Tim_Drv_SetInitValue(uint8 Instance, uint16 InitValue)
{
    Reg_Tim_BfType *TimBfPtr = Tim_Drv_TimRegBfPtr[Instance];

    TimBfPtr->TIM_CNTINIT.CNTINIT = InitValue;
}

/**
 * @brief       This function loads init Value to counter.
 *
 * @param[in]   Instance: Timer hardware instance number
 * @param[in]   Value: Timer counter
 *
 * @return      None
 *
 */
LOCAL_INLINE void Tim_Drv_LoadCounterInitValue(uint8 Instance, uint16 Value)
{
    Reg_Tim_BfType *TimBfPtr = Tim_Drv_TimRegBfPtr[Instance];

    TimBfPtr->TIM_CNT.CNT = Value;
}

/**
 * @brief      This function clears timer channel interrupt flag.
 *
 * @param[in]  Instance: Timer hardware instance number
 * @param[in]  Channel: Channel of timer
 *
 * @return     None
 *
 */
LOCAL_INLINE void Tim_Drv_ClearInterruptFlag(uint8 Instance, uint8 Channel)
{
    Reg_Tim_BfType *TimBfPtr = Tim_Drv_TimRegBfPtr[Instance];

    SchM_Enter_Gpt_TimChannelConfigurationReg();
    if (1U == TimBfPtr->TIM_CMCn[Channel].CHF)
    {
        TimBfPtr->TIM_CMCn[Channel].CHF = 0U;
    }
    SchM_Exit_Gpt_TimChannelConfigurationReg();
}

/**
 * @brief      This function enable or disable timer channel interrupt.
 *
 * @param[in]  Instance: Timer hardware instance number
 * @param[in]  Channel: Channel of timer.
 * @param[in]  Enable: Enable/Disable timer interrupt.
 *
 * @return     None
 *
 */
LOCAL_INLINE void Tim_Drv_EnableInterrupt(uint8 Instance, uint8 Channel, boolean Enable)
{
    Reg_Tim_BfType *TimBfPtr = Tim_Drv_TimRegBfPtr[Instance];

    SchM_Enter_Gpt_TimChannelConfigurationReg();
    TimBfPtr->TIM_CMCn[Channel].CHIE = (uint32)Enable;
    SchM_Exit_Gpt_TimChannelConfigurationReg();
}

/**
* @brief         This function configure the clock source.
*
* @param[in]     Instance: Timer hardware instance number
* @param[in]     ClockSource: Tim clock source type
                            - TIM_DRV_CLK_SOURCE_DISABLED
                            - TIM_DRV_CLK_SOURCE_SYSTEM
                            - TIM_DRV_CLK_SOURCE_FUNCTION
                            - TIM_DRV_CLK_SOURCE_EXTERNAL
*
* @return        None
*/
LOCAL_INLINE void Tim_Drv_SelectClockSource(uint8 Instance, Tim_Drv_ClockSourceType ClockSource)
{
    Reg_Tim_BfType *TimBfPtr = Tim_Drv_TimRegBfPtr[Instance];

    volatile uint32 Flag = TimBfPtr->TIM_FLTSR.WPEN;
    if (1U == Flag)
    {
        TimBfPtr->TIM_GLBSR.WPDIS = 1U;
    }
    SchM_Enter_Gpt_TimBaseReg();
    TimBfPtr->TIM_TIMEBASE.CKSRC = (uint32)ClockSource;
    SchM_Exit_Gpt_TimBaseReg();
    TimBfPtr->TIM_FLTSR.WPEN = 1U;
}

/**
 * @brief      This function sets timer compare value
 *
 * @param[in]  Instance: Timer hardware instance number
 * @param[in]  Channel: Channel of timer.
 * @param[in]  CompareValue:  Compare Value.
 *
 * @return     None
 *
 */
LOCAL_INLINE void Tim_Drv_SetCompareValue(uint8 Instance, uint8 Channel, uint16 CompareValue)
{
    Reg_Tim_BfType *TimBfPtr = Tim_Drv_TimRegBfPtr[Instance];

    TimBfPtr->TIM_CCVn[Channel].CCV = CompareValue;
}

/**
 * @brief      This function sets timer mod value
 *
 * @param[in]  Instance: Timer hardware instance number
 * @param[in]  ModValue: Counter MOD value.
 *
 * @return     None
 */
LOCAL_INLINE void Tim_Drv_SetModValue(uint8 Instance, uint16 ModValue)
{
    Reg_Tim_BfType *TimBfPtr = Tim_Drv_TimRegBfPtr[Instance];

    TimBfPtr->TIM_MOD.MOD = ModValue;
}

/**
 * @brief      This function selects timer output compare mode
 *
 * @param[in]  Instance: Timer hardware instance number
 * @param[in]  Channel: Channel of timer.
 * @param[in]  Enable: Enable/Disable output compare mode
 *
 * @return     None
 *
 */
LOCAL_INLINE void Tim_Drv_SelectOutputCompareMode(uint8 Instance, uint8 Channel, boolean Enable)
{
    Reg_Tim_BfType *TimBfPtr = Tim_Drv_TimRegBfPtr[Instance];

    volatile uint32 Flag = TimBfPtr->TIM_FLTSR.WPEN;
    if (1U == Flag)
    {
        TimBfPtr->TIM_GLBSR.WPDIS = 1U;
    }
    SchM_Enter_Gpt_TimEnableOutputCompare();
    TimBfPtr->TIM_GLBCR.CNTMODE = 0U;
    TimBfPtr->TIM_CMCn[Channel].CMS = (uint32)Enable;
    TimBfPtr->TIM_CMCn[Channel].ELS = 0U;
    SchM_Exit_Gpt_TimEnableOutputCompare();
    TimBfPtr->TIM_FLTSR.WPEN = 1U;
}

/**
 * @brief      This function configure timer prescaler value.
 *
 * @param[in]  Instance: Timer hardware instance number
 * @param[in]  PrescalerValue: Timer prescaler divider factor type
 *
 * @return     None
 */
LOCAL_INLINE void Tim_Drv_SetPrescaler(uint8 Instance, Tim_Drv_PrescalerType PrescalerValue)
{
    Reg_Tim_BfType *TimBfPtr = Tim_Drv_TimRegBfPtr[Instance];

    volatile uint32 Flag = TimBfPtr->TIM_FLTSR.WPEN;
    if (1U == Flag)
    {
        TimBfPtr->TIM_GLBSR.WPDIS = 1U;
    }
    SchM_Enter_Gpt_TimBaseReg();
    TimBfPtr->TIM_TIMEBASE.PSDIV = (uint32)PrescalerValue;
    SchM_Exit_Gpt_TimBaseReg();
    TimBfPtr->TIM_FLTSR.WPEN = 1U;
}

/**
 * @brief      This function gets timer interrupt bit status
 *
 * @param[in]  Instance: Timer hardware instance number
 * @param[in]  Channel: Channel of timer.
 *
 * @return     uint32
 * @retval     timer interrupt bit status.
 */
static uint32 Tim_Drv_GetInterruptBitStatus(uint8 Instance, uint8 Channel)
{
    const Reg_Tim_BfType *TimBfPtr = Tim_Drv_TimRegBfPtr[Instance];

    uint32 BitStatus = TimBfPtr->TIM_CMCn[Channel].CHIE;
    return BitStatus;
}

#if (TIM_DRV_0_ISR_ENABLE == STD_ON) || (TIM_DRV_1_ISR_ENABLE == STD_ON) ||                    \
    (TIM_DRV_2_ISR_ENABLE == STD_ON) || (TIM_DRV_3_ISR_ENABLE == STD_ON)
/**
 * @brief      This function enables counter synchronization comparison.
 *
 * @param[in]  Instance: Timer hardware instance number
 * @param[in]  Channel: Channel of timer.
 * @param[in]  Enable: Enable/Disable synchronization comparison
 *
 * @return     None
 */
LOCAL_INLINE void Tim_Drv_EnableSyncCCV(uint8 Instance, uint8 Channel, boolean Enable)
{
    Reg_Tim_BfType *TimBfPtr = Tim_Drv_TimRegBfPtr[Instance];
    uint8 ChannelIndex = Channel/2U;

    if (TRUE == Enable)
    {
        if (0U == ChannelIndex)
        {
            TimBfPtr->TIM_PCR.SYNCEN0 = 1U;
        }
        else if (1U == ChannelIndex)
        {
            TimBfPtr->TIM_PCR.SYNCEN1 = 1U;
        }
        else if (2U == ChannelIndex)
        {
            TimBfPtr->TIM_PCR.SYNCEN2 = 1U;
        }
        else
        {
            TimBfPtr->TIM_PCR.SYNCEN3 = 1U;
        }
        TimBfPtr->TIM_SYNC.SWWRBUF = 1U;
        TimBfPtr->TIM_SYNC.SWRSTCNT = 0U;
    }
    else
    {
        if (0U == ChannelIndex)
        {
            TimBfPtr->TIM_PCR.SYNCEN0 = 0U;
        }
        else if (1U == ChannelIndex)
        {
            TimBfPtr->TIM_PCR.SYNCEN1 = 0U;
        }
        else if (2U == ChannelIndex)
        {
            TimBfPtr->TIM_PCR.SYNCEN2 = 0U;
        }
        else
        {
            TimBfPtr->TIM_PCR.SYNCEN3 = 0U;
        }
        TimBfPtr->TIM_SYNC.SWWRBUF = 0U;
        TimBfPtr->TIM_SYNC.SWRSTCNT = 0U;
    }
}

/**
 * @brief      This function enable software trigger synchronization.
 *
 * @param[in]  Instance: Timer hardware instance number
 *
 * @return     None
 */
LOCAL_INLINE void Tim_Drv_EnableSyncSoftWareTrigger(uint8 Instance)
{
    Reg_Tim_BfType *TimBfPtr = Tim_Drv_TimRegBfPtr[Instance];

    TimBfPtr->TIM_SYNC.SWTRIG = 1U;
}
#endif
/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
/**
 * @brief       This function gets timer current value
 *
 * @param[in]   Instance: Timer hardware instance number
 *
 * @return      CurrentCntValue
 */
uint16 Tim_Drv_GetCounterValue(uint8 Instance)
{
    const Reg_Tim_BfType *TimBfPtr = Tim_Drv_TimRegBfPtr[Instance];

    uint16 CurrentValue;
    CurrentValue = TimBfPtr->TIM_CNT.CNT;
    return CurrentValue;
}

/**
 * @brief      This function gets timer compare value
 *
 * @param[in]  Instance: Timer hardware instance number
 * @param[in]  Channel: Channel of timer.
 *
 * @return     uint16
 * @retval     Timer compare value
 */
uint16 Tim_Drv_GetCompareValue(uint8 Instance, uint8 Channel)
{
    const Reg_Tim_BfType *TimBfPtr = Tim_Drv_TimRegBfPtr[Instance];
    
    uint16 CompareValue;
    CompareValue = TimBfPtr->TIM_CCVn[Channel].CCV;
    return CompareValue;
}

/**
 * @brief      This function gets timer channel interrupt flag
 *
 * @param[in]  Instance: Timer hardware instance number
 * @param[in]  Channel: Channel of timer.
 *
 * @return     uint32
 * @retval     Timer interrupt flag
 */
uint32 Tim_Drv_GetInterruptFlag(uint8 Instance, uint8 Channel)
{
    const Reg_Tim_BfType *TimBfPtr = Tim_Drv_TimRegBfPtr[Instance];

    uint32 IntStatus;
    IntStatus = TimBfPtr->TIM_CMCn[Channel].CHF;
    return IntStatus;
}

/**
 * @brief      This function initializes the Timer instance.
 *
 * @param[in]  Instance: Timer hardware instance number
 * @param[in]  ConfigInstancePtr: Pointer to the specified TIMER instance configuration
 * 
 * @return     None 
 */
void Tim_Drv_InitInstance(uint8 Instance, const Tim_Drv_InstanceConfigType *ConfigInstancePtr)
{
#if STD_ON == TIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_START();
#endif

#if STD_ON == TIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT(TIM_DRV_INSTANCE_COUNT > Instance);
    MCALLIB_DEV_ASSERT(NULL_PTR != ConfigInstancePtr);
#endif

    if (TIM_DRV_COUNTING_UP == ConfigInstancePtr->Mode)
    {
        /* Set timer prescaler*/
        Tim_Drv_SetPrescaler(Instance, ConfigInstancePtr->ClockPrescaler);

        /*Set freeze bit*/
        Tim_Drv_SetFreezebit(Instance, ConfigInstancePtr->FreezeBit);

        /*Set initial value*/
        Tim_Drv_SetInitValue(Instance, 0U);
        
        Tim_Drv_LoadCounterInitValue(Instance, 0U);

        /* Set mod value to 0xFFFF */
        Tim_Drv_SetModValue(Instance, 0xFFFFU);
    }
    else
    {
        /* Do nothing */
    }
#if (STD_ON == TIM_DRV_SET_DUAL_CLOCK_MODE)
    Tim_Drv_ClockState[Instance].ClockPrescaler = ConfigInstancePtr->ClockPrescaler;
    Tim_Drv_ClockState[Instance].ClockAlternatePrescaler = 
                                                        ConfigInstancePtr->ClockAlternatePrescaler;
#endif
#if STD_ON == TIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      This function initializes the Timer channel.
 *
 * @param[in]  Instance: Timer hardware instance number
 * @param[in]  ConfigChannelPtr: Pointer to the specified TIMER channel configuration
 * 
 * @return     None 
 */
void Tim_Drv_InitChannel(uint8 Instance, const Tim_Drv_ChannelConfigType *ConfigChannelPtr)
{
#if STD_ON == TIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_START();
#endif

#if STD_ON == TIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT(TIM_DRV_INSTANCE_COUNT > Instance);
    MCALLIB_DEV_ASSERT(NULL_PTR != ConfigChannelPtr);
    MCALLIB_DEV_ASSERT(TIM_DRV_CHANNEL_COUNT > ConfigChannelPtr->HwChannel);
#endif
    /* Disable channels interrupt */
    Tim_Drv_EnableInterrupt(Instance, ConfigChannelPtr->HwChannel, FALSE);
    /* Clear channel interrupt flag */
    Tim_Drv_ClearInterruptFlag(Instance, ConfigChannelPtr->HwChannel);
    /* Select output compare mode */
    Tim_Drv_SelectOutputCompareMode(Instance, ConfigChannelPtr->HwChannel, TRUE);
    /* Set compare value to 0xFFFF */
    Tim_Drv_SetCompareValue(Instance, ConfigChannelPtr->HwChannel, 0xFFFFU);
    
#if (TIM_DRV_0_ISR_ENABLE == STD_ON) || (TIM_DRV_1_ISR_ENABLE == STD_ON) ||                    \
    (TIM_DRV_2_ISR_ENABLE == STD_ON) || (TIM_DRV_3_ISR_ENABLE == STD_ON)
    Tim_Drv_ChannelState[Instance][ConfigChannelPtr->HwChannel].ChannelStatus = TIM_DRV_IDLE;
    Tim_Drv_ChannelState[Instance][ConfigChannelPtr->HwChannel].Callback =
        ConfigChannelPtr->Callback;
    Tim_Drv_ChannelState[Instance][ConfigChannelPtr->HwChannel].CallbackParam =
        ConfigChannelPtr->CallbackParam;
#endif
#if STD_ON == TIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      This function de-initialize the TIMER.
 *
 * @param[in]  Instance: Timer hardware instance numberr
 * 
 * @return     None
 */
void Tim_Drv_Deinit(uint8 Instance)
{
    uint8 ChannelIndex;

#if STD_ON == TIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_START();
#endif

#if STD_ON == TIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT(TIM_DRV_INSTANCE_COUNT > Instance);
#endif
    for (ChannelIndex = 0; ChannelIndex < TIM_DRV_CHANNEL_COUNT; ChannelIndex++)
    {
        /* Disable channel interrupt */
        Tim_Drv_EnableInterrupt(Instance, ChannelIndex, FALSE);
        /*Clear interrupt flag*/
        Tim_Drv_ClearInterruptFlag(Instance, ChannelIndex);

#if (TIM_DRV_0_ISR_ENABLE == STD_ON) || (TIM_DRV_1_ISR_ENABLE == STD_ON) ||                    \
    (TIM_DRV_2_ISR_ENABLE == STD_ON) || (TIM_DRV_3_ISR_ENABLE == STD_ON)
        Tim_Drv_ChannelState[Instance][ChannelIndex].ChannelStatus = TIM_DRV_IDLE;
#endif
    }
    /* Disable clockSoure */
    Tim_Drv_SelectClockSource(Instance, TIM_DRV_CLK_SOURCE_DISABLED);
    /* Disable freeze */
    Tim_Drv_SetFreezebit(Instance, FALSE);
    /* Set initial counter Value to 0 and load init value to counter */
    Tim_Drv_SetInitValue(Instance, 0U);
    Tim_Drv_LoadCounterInitValue(Instance, 0U);
#if STD_ON == TIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Start the timer counter.
 *
 * @param[in]  Instance: Timer hardware instance number
 * @param[in]  Channel: Channel of timer.
 * @param[in]  CompareValue: Channel timeout value.
 * 
 * @return     None
 */
void Tim_Drv_StartTimer(uint8 Instance, uint8 Channel, uint16 CompareValue,
                        Tim_Drv_ClockSourceType ClockSource)
{
    uint32 CounterValue;
    uint32 CurrentCountValue = 0U;
#if STD_ON == TIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_START();
#endif

#if STD_ON == TIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT(TIM_DRV_INSTANCE_COUNT > Instance);
    MCALLIB_DEV_ASSERT(TIM_DRV_CHANNEL_COUNT > Channel);
#endif

    CurrentCountValue = Tim_Drv_GetCounterValue(Instance);
    if ((uint32)(CurrentCountValue + CompareValue) > TIM_DRV_MAX_VALUE)
    {
        CounterValue = (uint32)(CompareValue - (TIM_DRV_MAX_VALUE - CurrentCountValue + 1U));
    }
    else
    {
        CounterValue = (uint32)(CurrentCountValue + CompareValue);
    }
    /* Set new compare value */
    Tim_Drv_SetCompareValue(Instance, Channel, (uint16)CounterValue);
    /* Save compare value */
    Tim_Drv_TargetValue[Instance][Channel] = CompareValue;
    /* Clear channel interrupt flag */
    Tim_Drv_ClearInterruptFlag(Instance, Channel);
    /* Enable channels interrupt */
    Tim_Drv_EnableInterrupt(Instance, Channel, TRUE);
    /* Select timer clock source*/
    Tim_Drv_SelectClockSource(Instance, ClockSource);

#if (TIM_DRV_0_ISR_ENABLE == STD_ON) || (TIM_DRV_1_ISR_ENABLE == STD_ON) ||                    \
    (TIM_DRV_2_ISR_ENABLE == STD_ON) || (TIM_DRV_3_ISR_ENABLE == STD_ON)
    Tim_Drv_ChannelState[Instance][Channel].ChannelStatus = TIM_DRV_BUSY;
#endif

#if STD_ON == TIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Stop the timer counter.
 *
 * @param[in]  Instance: Timer hardware instance number
 * 
 * @return     None
 */
void Tim_Drv_StopTimer(uint8 Instance, uint8 Channel)
{
    uint8 TempChannel;
    uint32 InterruptEnabled;
    boolean ChannelEnabled = FALSE;

#if STD_ON == TIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_START();
#endif

#if STD_ON == TIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT(TIM_DRV_INSTANCE_COUNT > Instance);
#endif
    /* Disable channel interrupt */
    Tim_Drv_EnableInterrupt(Instance, Channel, FALSE);

    for (TempChannel = 0U; TempChannel < TIM_DRV_CHANNEL_SUMCNT; TempChannel++)
    {
        InterruptEnabled = Tim_Drv_GetInterruptBitStatus(Instance, TempChannel);
        if (TRUE == InterruptEnabled)
        {
            ChannelEnabled = TRUE;
            break;
        }
    }

    if(TRUE == ChannelEnabled)
    {
        /* Disable Timer counter */
        Tim_Drv_SelectClockSource(Instance, TIM_DRV_CLK_SOURCE_DISABLED);
    }

#if (TIM_DRV_0_ISR_ENABLE == STD_ON) || (TIM_DRV_1_ISR_ENABLE == STD_ON) ||                    \
    (TIM_DRV_2_ISR_ENABLE == STD_ON) || (TIM_DRV_3_ISR_ENABLE == STD_ON)
    Tim_Drv_ChannelState[Instance][Channel].ChannelStatus = TIM_DRV_IDLE;
#endif

#if STD_ON == TIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Enable interrupt for timer channel.
 *
 * @param[in]  Instance: Timer hardware instance number
 * @param[in]  Channel: Channel of timer.
 * 
 * @return     None
 */
void Tim_Drv_EnableChannelInterrupt(uint8 Instance, uint8 Channel)
{
#if STD_ON == TIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_START();
#endif

#if STD_ON == TIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT(TIM_DRV_INSTANCE_COUNT > Instance);
    MCALLIB_DEV_ASSERT(TIM_DRV_CHANNEL_COUNT > Channel);
#endif

    /* Clear interrupt flag */
    Tim_Drv_ClearInterruptFlag(Instance, Channel);
    /* Enable channel interrupt */
    Tim_Drv_EnableInterrupt(Instance, Channel, TRUE);

#if STD_ON == TIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Disable interrupt for timer channel.
 *
 * @param[in]  Instance: Timer hardware instance number
 * @param[in]  Channel: Channel of timer.
 * 
 * @return     None
 */
void Tim_Drv_DisableChannelInterrupt(uint8 Instance, uint8 Channel)
{
#if STD_ON == TIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_START();
#endif

#if STD_ON == TIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT(TIM_DRV_INSTANCE_COUNT > Instance);
    MCALLIB_DEV_ASSERT(TIM_DRV_CHANNEL_COUNT > Channel);
#endif

    /* Disable interrupt */
    Tim_Drv_EnableInterrupt(Instance, Channel, FALSE);
    /* Clear interrupt flag */
    Tim_Drv_ClearInterruptFlag(Instance, Channel);

#if STD_ON == TIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_END();
#endif
}

#if (STD_ON == TIM_DRV_SET_DUAL_CLOCK_MODE)
/**
 * @brief       Change the Timer prescaler value.
 *
 * @param[in]   Instance: Timer peripheral instance number
 * @param[in]   ClockMode: Timer prescaler type.
 *                        - TIM_DRV_CLOCKMODE_NORMAL
 *                        - TIM_DRV_CLOCKMODE_ALTERNATE
 * 
 * @return      None
 */
void Tim_Drv_SetDualClockMode(uint8 Instance, Tim_Drv_DualClockModeType ClockMode)
{
#if STD_ON == TIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_START();
#endif

#if STD_ON == TIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT(TIM_DRV_INSTANCE_COUNT > Instance);
#endif

    /* Set Prescaler */
    if (TIM_DRV_CLOCKMODE_NORMAL == ClockMode)
    {
        Tim_Drv_SetPrescaler(Instance, Tim_Drv_ClockState[Instance].ClockPrescaler);
    }
    else
    {
        Tim_Drv_SetPrescaler(Instance, Tim_Drv_ClockState[Instance].ClockAlternatePrescaler);
    }

#if STD_ON == TIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_END();
#endif
}
#endif /*TIM_DRV_SET_DUAL_CLOCK_MODE*/

#if (TIM_DRV_0_ISR_ENABLE == STD_ON)
/**
 * @brief   Interrupt handler for Timer.
 *
 * @return  None
 */
ISR(Tim_Drv_0_ChIrqHandler)
{
    uint8 Channel = 0U;

    for (Channel = 0U; Channel < TIM_DRV_CHANNEL_COUNT; Channel++)
    {
        Tim_Drv_IntHandler(0U, Channel);
    }
    EXIT_INTERRUPT();
}
#endif

#if (TIM_DRV_1_ISR_ENABLE == STD_ON)
/**
 * @brief   Interrupt handler for Timer.
 *
 * @return  None
 */
ISR(Tim_Drv_1_ChIrqHandler)
{
    uint8 Channel = 0U;

    for (Channel = 0U; Channel < TIM_DRV_CHANNEL_COUNT; Channel++)
    {
        Tim_Drv_IntHandler(1U, Channel);
    }
    EXIT_INTERRUPT();
}
#endif

#if (TIM_DRV_2_ISR_ENABLE == STD_ON)
/**
 * @brief   Interrupt handler for Timer.
 *
 * @return  None
 */
ISR(Tim_Drv_2_ChIrqHandler)
{
    uint8 Channel = 0U;

    for (Channel = 0U; Channel < TIM_DRV_CHANNEL_COUNT; Channel++)
    {
        Tim_Drv_IntHandler(2U, Channel);
    }
    EXIT_INTERRUPT();
}
#endif

#if (TIM_DRV_3_ISR_ENABLE == STD_ON)
/**
 * @brief   Interrupt handler for Timer.
 *
 * @return  None
 */
ISR(Tim_Drv_3_ChIrqHandler)
{
    uint8 Channel = 0U;

    for (Channel = 0U; Channel < TIM_DRV_CHANNEL_COUNT; Channel++)
    {
        Tim_Drv_IntHandler(3U, Channel);
    }
    EXIT_INTERRUPT();
}
#endif

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#endif /* TIM_DRV_ENABLE == STD_ON */

#ifdef __cplusplus
}
#endif

/** @} end of group Tim_Drv */

/** @} end of group Tim_Module */
