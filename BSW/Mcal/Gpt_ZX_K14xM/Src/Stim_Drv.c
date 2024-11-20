/**************************************************************************************************/
/**
 * @file      : Stim_Drv.c
 * @brief     : Rtc module source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup Gpt_Module
 *  @{
 */

/** @addtogroup Stim_Drv
 *  @brief Gpt low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Device_Regs.h"
#include "Stim_Drv.h"
#include "SchM_Gpt.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
/* Published information */
#define STIM_DRV_C_VENDOR_ID                   0x00B3U
#define STIM_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define STIM_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define STIM_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define STIM_DRV_C_SW_MAJOR_VERSION            1U
#define STIM_DRV_C_SW_MINOR_VERSION            2U
#define STIM_DRV_C_SW_PATCH_VERSION            2U

/* Check if current file and Stim_Drv header file are of the same vendor */
#if (STIM_DRV_C_VENDOR_ID != STIM_DRV_H_VENDOR_ID)
    #error "Vendor ID of Stim_Drv.c and Stim_Drv.h are different"
#endif
/* Check if current file and Stim_Drv header file are of the same Autosar version */
#if ((STIM_DRV_C_AR_RELEASE_MAJOR_VERSION != STIM_DRV_H_AR_RELEASE_MAJOR_VERSION) ||               \
     (STIM_DRV_C_AR_RELEASE_MINOR_VERSION != STIM_DRV_H_AR_RELEASE_MINOR_VERSION) ||               \
     (STIM_DRV_C_AR_RELEASE_REVISION_VERSION != STIM_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Stim_Drv.c and Stim_Drv.h are different"
#endif
/* Check if current file and Stim_Drv header file are of the same Software version */
#if ((STIM_DRV_C_SW_MAJOR_VERSION != STIM_DRV_H_SW_MAJOR_VERSION) ||                               \
     (STIM_DRV_C_SW_MINOR_VERSION != STIM_DRV_H_SW_MINOR_VERSION) ||                               \
     (STIM_DRV_C_SW_PATCH_VERSION != STIM_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Stim_Drv.c and Stim_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Device_Regs.h are the same Autosar version */
    #if ((STIM_DRV_C_AR_RELEASE_MAJOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) ||        \
         (STIM_DRV_C_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Stim_Drv.c and Device_Regs.h are different"
    #endif

    /* Check if current file and SchM_Gpt.h are the same Autosar version */
    #if ((STIM_DRV_C_AR_RELEASE_MAJOR_VERSION != SCHM_GPT_H_AR_RELEASE_MAJOR_VERSION) ||           \
         (STIM_DRV_C_AR_RELEASE_MINOR_VERSION != SCHM_GPT_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Stim_Drv.c and SchM_Gpt.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/** @} end of Private_MacroDefinition */
#if (STIM_DRV_ENABLE == STD_ON)

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
#define GPT_START_SEC_CONST_PTR
#include "Gpt_MemMap.h"
/**
 *  @brief Stim instance address array
 */
static Reg_Stim_BfType *const Stim_Drv_StimRegBfPtr[STIM_DRV_INSTANCE_COUNT] = 
{
    (Reg_Stim_BfType *)STIM_BASE_ADDR
};

static Reg_Stim_WType *const Stim_Drv_StimRegWPtr[STIM_DRV_INSTANCE_COUNT] = 
{
    (Reg_Stim_WType *)STIM_BASE_ADDR
};
#define GPT_STOP_SEC_CONST_PTR
#include "Gpt_MemMap.h"

#define GPT_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Gpt_MemMap.h"
/**
 *  @brief Set the interrupt channel status.
 */
#if (STIM_DRV_ISR_ENABLE == STD_ON)
static Stim_Drv_StateType Stim_Drv_ChannelState[STIM_DRV_INSTANCE_COUNT][STIM_DRV_CHANNEL_COUNT];
#endif

#if (STIM_DRV_SET_DUAL_CLOCK_MODE == STD_ON)
/**
 *  @brief Set the clock status.
 */
static Stim_Drv_ClockStateType Stim_Drv_ClockState[STIM_DRV_INSTANCE_COUNT][STIM_DRV_CHANNEL_COUNT];
#endif
/** @} end of group Global_VariableDefinition */

#define GPT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#if (STIM_DRV_ISR_ENABLE == STD_ON)
ISR(Stim_Drv_IrqHandler);
#endif
/** @} end of group Public_FunctionDeclaration */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

LOCAL_INLINE void Stim_Drv_Configure(uint8 Instance, uint8 Channel,
                                     Stim_Drv_ClockSourceType ClockSource,
                                     Stim_Drv_PrescalerType   PrescalerValue);
LOCAL_INLINE void Stim_Drv_EnableTimer(uint8 Instance, uint8 Channel, boolean Enable);
LOCAL_INLINE void Stim_Drv_EnableInt(uint8 Instance, uint8 Channel, boolean Enable);
LOCAL_INLINE void Stim_Drv_ClearCompareFlag(uint8 Instance, uint8 Channel);
LOCAL_INLINE void Stim_Drv_SelectTimerMode(uint8 Instance, uint8 Channel, uint32 Mode);
#if (STIM_DRV_SET_DUAL_CLOCK_MODE == STD_ON)
LOCAL_INLINE void Stim_Drv_SetPrescalerValue(uint8 Instance, uint8 Channel,
                                             Stim_Drv_PrescalerType PrescalerValue);
#endif
LOCAL_INLINE void    Stim_Drv_WriteCompareValue(uint8 Instance, uint8 Channel, uint32 Value);
LOCAL_INLINE boolean Stim_Drv_GetInterruptBit(uint8 Instance, uint8 Channel);
#if (STIM_DRV_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
LOCAL_INLINE boolean Stim_Drv_GetEnableState(uint8 Instance, uint8 Channel);
#endif
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#if (STIM_DRV_ISR_ENABLE == STD_ON)
/**
 * @brief       Stim interrupt handler.
 *
 * @param[in]   Instance: STIM peripheral instance number
 * @param[in]   Channel: Stim channel
 *
 * @return      None
 */
static void Stim_Drv_IntHandler(uint8 Instance, uint8 Channel)
{
    Reg_Stim_BfType *STIMx = Stim_Drv_StimRegBfPtr[Instance];
    boolean Flag = (boolean)FALSE;
    boolean InterruptEnabled = (boolean)FALSE;
    Flag = Stim_Drv_GetStatus(Instance, Channel);

    if(TRUE == Flag)
    {
        STIMx->STIM_SCn[Channel].FLAG = 1U;
        InterruptEnabled = Stim_Drv_GetInterruptBit(Instance, Channel);
        if (TRUE == InterruptEnabled)
        {
            if ((TRUE == Stim_Drv_ChannelState[Instance][Channel].ChannelInit) &&
                (NULL_PTR != Stim_Drv_ChannelState[Instance][Channel].Callback))
            {
                Stim_Drv_ChannelState[Instance][Channel].Callback(
                Stim_Drv_ChannelState[Instance][Channel].CallbackParam);
            }
        }
    }
}
#endif

/**
 * @brief       This function enable stim.
 *
 * @param[in]   Instance: STIM peripheral instance number
 * @param[in]   Channel: Stim channel
 * @param[in]   Enable: Enable/Disable Stim
 *
 * @return      None
 */
LOCAL_INLINE void Stim_Drv_EnableTimer(uint8 Instance, uint8 Channel, boolean Enable)
{
    Reg_Stim_BfType *STIMx = Stim_Drv_StimRegBfPtr[Instance];

    SchM_Enter_Gpt_StimControlAndStatusReg();
    if (TRUE == Enable)
    {
        STIMx->STIM_SCn[Channel].EN = 1U;
    }
    else
    {
        STIMx->STIM_SCn[Channel].EN = 0U;
    }
    SchM_Exit_Gpt_StimControlAndStatusReg();
}

/**
 * @brief       This function enable or disable stim interrupt.
 *
 * @param[in]   Instance: STIM peripheral instance number
 * @param[in]   Channel: Stim channel
 * @param[in]   Enable: Enable/Disable Stim interrupt
 *
 * @return      None
 */
LOCAL_INLINE void Stim_Drv_EnableInt(uint8 Instance, uint8 Channel, boolean Enable)
{
    Reg_Stim_BfType *STIMx = Stim_Drv_StimRegBfPtr[Instance];

    SchM_Enter_Gpt_StimControlAndStatusReg();
    if (TRUE == Enable)
    {
        STIMx->STIM_SCn[Channel].IE = 1U;
    }
    else
    {
        STIMx->STIM_SCn[Channel].IE = 0U;
    }
    SchM_Exit_Gpt_StimControlAndStatusReg();
}

/**
 * @brief       This function clears compare flag.
 *
 * @param[in]   Instance: STIM peripheral instance number
 * @param[in]   Channel: Stim channel
 *
 * @return      None
 */
LOCAL_INLINE void Stim_Drv_ClearCompareFlag(uint8 Instance, uint8 Channel)
{
    Reg_Stim_BfType *STIMx = Stim_Drv_StimRegBfPtr[Instance];

    SchM_Enter_Gpt_StimControlAndStatusReg();
    if(1U == STIMx->STIM_SCn[Channel].FLAG)
    {
        STIMx->STIM_SCn[Channel].FLAG = 1U;
    }
    SchM_Exit_Gpt_StimControlAndStatusReg();
}

/**
 * @brief       This function select stim counter mode.
 *
 * @param[in]   Instance: STIM peripheral instance number
 * @param[in]   Channel: Stim channel
 * @param[in]   Mode: Stim work mode
 *
 * @return      None
 */
LOCAL_INLINE void Stim_Drv_SelectTimerMode(uint8 Instance, uint8 Channel, uint32 Mode)
{
    Reg_Stim_BfType *STIMx = Stim_Drv_StimRegBfPtr[Instance];

    SchM_Enter_Gpt_StimControlAndStatusReg();
    STIMx->STIM_SCn[Channel].MODE = Mode;
    SchM_Exit_Gpt_StimControlAndStatusReg();
}

#if (STIM_DRV_SET_DUAL_CLOCK_MODE == STD_ON)
/**
 * @brief       This function set prescaler value.
 *
 * @param[in]   Instance: STIM peripheral instance number
 * @param[in]   Channel: Stim channel
 * @param[in]   PrescalerValue: stim prescaler divider factor type
 *
 * @return      None
 */
LOCAL_INLINE void Stim_Drv_SetPrescalerValue(uint8 Instance, uint8 Channel,
                                             Stim_Drv_PrescalerType PrescalerValue)
{
    Reg_Stim_BfType *STIMx = Stim_Drv_StimRegBfPtr[Instance];

    SchM_Enter_Gpt_StimControlAndStatusReg();
    STIMx->STIM_SCn[Channel].PSDIV = (uint32)PrescalerValue;
    SchM_Exit_Gpt_StimControlAndStatusReg();
}
#endif

/**
 * @brief       This function configure the clock source and prescaler value.
 *
 * @param[in]   Instance: STIM peripheral instance number
 * @param[in]   Channel: Stim Channel
 * @param[in]   Channel: Stim clock source type
 *              - STIM_DRV_FUNCTION_CLOCK
 *              - STIM_DRV_BUS_CLOCK
 *              - STIM_DRV_OSC40M
 *              - STIM_DRV_LPO32K
 * @param[in]   PrescalerValue: stim prescaler divider factor type
 *
 * @return      None
 */
LOCAL_INLINE void Stim_Drv_Configure(uint8 Instance, uint8 Channel,
                                     Stim_Drv_ClockSourceType ClockSource,
                                     Stim_Drv_PrescalerType   PrescalerValue)
{
    Reg_Stim_BfType *STIMx = Stim_Drv_StimRegBfPtr[Instance];

    SchM_Enter_Gpt_StimControlAndStatusReg();
    STIMx->STIM_SCn[Channel].CLKS = (uint32)ClockSource;
    STIMx->STIM_SCn[Channel].PSDIV = (uint32)PrescalerValue;
    SchM_Exit_Gpt_StimControlAndStatusReg();
}

/**
 * @brief       This function writes compare value.
 *
 * @param[in]   Instance: STIM peripheral instance number
 * @param[in]   Channel: Stim channel
 * @param[in]   Value: Stim compare vaule
 *
 * @return      None
 */
LOCAL_INLINE void Stim_Drv_WriteCompareValue(uint8 Instance, uint8 Channel, uint32 Value)
{
    Reg_Stim_WType *STIMxw = Stim_Drv_StimRegWPtr[Instance];

    STIMxw->STIM_CVn[Channel] = Value;
}

/**
 * @brief       This function get the interrupt bit status.
 *
 * @param[in]   Instance: STIM peripheral instance number
 * @param[in]   Channel: Stim channel
 *
 * @return      boolean
 * @retval      TRUE: Interrupt enables.
 * @retval      FALSE: Interrupt disables.
 */
LOCAL_INLINE boolean Stim_Drv_GetInterruptBit(uint8 Instance, uint8 Channel)
{
    const Reg_Stim_BfType *STIMx = Stim_Drv_StimRegBfPtr[Instance];

    boolean Status;

    Status = ((STIMx->STIM_SCn[Channel].IE != 0U) ? TRUE : FALSE);

    return Status;
}

#if (STIM_DRV_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/**
 * @brief       This function get stim enable/disable status.
 *
 * @param[in]   Instance: STIM peripheral instance number
 * @param[in]   Channel: Stim channel
 *
 * @return      boolean
 * @retval      TRUE: Stim has enabled.
 * @retval      FALSE: Stim has not enabled.
 */
LOCAL_INLINE boolean Stim_Drv_GetEnableState(uint8 Instance, uint8 Channel)
{
    const Reg_Stim_BfType *STIMx = Stim_Drv_StimRegBfPtr[Instance];

    boolean EnableState;

    EnableState = ((STIMx->STIM_SCn[Channel].EN != 0U) ? TRUE : FALSE);

    return EnableState;
}


/**
 * @brief       Get status of setting compare value.
 *
 * @param[in]   Instance: STIM peripheral instance number
 * @param[in]   Channel: Select the stim channel number.
 * @param[in]   CompareValue: Stim compare value.
 *
 * @return     Stim_Drv_StatusType
 * @retval     STIM_DRV_SUCCESS:  set compare value has been completed.
 * @retval     STIM_DRV_ERROR:    set compare value has not been completed.
 */
static Stim_Drv_StatusType Stim_Drv_SetCompareValue(uint8 Instance, uint8 Channel, uint32 CompareValue)
{
    Stim_Drv_StatusType Status = STIM_DRV_SUCCESS;
    boolean             EnableStatus;
    boolean             CompareFlagStatus;
    uint32              CounterVal;

#if STD_ON == STIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_START();
#endif

#if STD_ON == STIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT(STIM_DRV_INSTANCE_COUNT > Instance);
    MCALLIB_DEV_ASSERT(STIM_DRV_CHANNEL_COUNT > Channel);
#endif
    EnableStatus = Stim_Drv_GetEnableState(Instance, Channel);
    CompareFlagStatus = Stim_Drv_GetStatus(Instance, Channel);

    if ((TRUE == EnableStatus) && (FALSE == CompareFlagStatus))
    {
        Status = STIM_DRV_ERROR;
    }
    else
    {
        Stim_Drv_WriteCompareValue(Instance, Channel, CompareValue);
        CounterVal = (uint32)Stim_Drv_GetCurrentCounterValue(Instance, Channel);
        if (CounterVal >= CompareValue)
        {
            Status = STIM_DRV_TIMEOUT;
        }
    }
#if STD_ON == STIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_END();
#endif
    return Status;
}
#endif

/**
 * @brief       This function checks if the status flag is set when the counter matches the
 *              compare value.
 *
 * @param[in]   Instance: STIM peripheral instance number
 * @param[in]   Channel: Stim channel
 *
 * @return      boolean
 * @retval      TRUE: Stim flag is set.
 * @retval      FALSE: Stim flag is not set.
 */
boolean Stim_Drv_GetStatus(uint8 Instance, uint8 Channel)
{
    const Reg_Stim_BfType *STIMx;
    boolean IntBitStatus = FALSE;

#if STD_ON == STIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_START();
#endif

#if STD_ON == STIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT(STIM_DRV_INSTANCE_COUNT > Instance);
    MCALLIB_DEV_ASSERT(STIM_DRV_CHANNEL_COUNT > Channel);
#endif
    STIMx = Stim_Drv_StimRegBfPtr[Instance];

    IntBitStatus = (STIMx->STIM_SCn[Channel].FLAG != 0U) ? TRUE : FALSE;
#if STD_ON == STIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_END();
#endif
    return IntBitStatus;
}

/**
 * @brief       Get current counter value of stim.
 *
 * @param[in]   Instance: STIM peripheral instance number
 * @param[in]   Channel: Stim channel
 *
 * @return      CurrentCntValue
 */
uint32 Stim_Drv_GetCurrentCounterValue(uint8 Instance, uint8 Channel)
{
    const Reg_Stim_WType *STIMxw = Stim_Drv_StimRegWPtr[Instance];

    uint32 CurrentCntValue;
    CurrentCntValue = ((uint32)STIMxw->STIM_CNTn[Channel]);
    return CurrentCntValue;
}

/**
 * @brief       Get current compare value.
 *
 * @param[in]   Instance: STIM peripheral instance number
 * @param[in]   Channel: Stim channel
 *
 * @return      uint32
 * @retval      Stim compare value.
 */
uint32 Stim_Drv_GetCompareValue(uint8 Instance, uint8 Channel)
{
    const Reg_Stim_WType *STIMxw = Stim_Drv_StimRegWPtr[Instance];

    uint32 CurrentCompareValue;
    CurrentCompareValue = STIMxw->STIM_CVn[Channel];
    return CurrentCompareValue;
}

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

/**
 * @brief       This function initialize the STIM
 *
 * @param[in]   Instance: STIM peripheral instance number
 * @param[in]   ConfigChannelPtr: Pointer to the specified STIM channel configuration
 *
 * @return      None
 */
void Stim_Drv_InitChannel(uint8 Instance, const Stim_Drv_ChannelConfigType *ConfigChannelPtr)
{
#if (STIM_DRV_STANDBY_WAKEUP_SUPPORT == STD_ON)
    boolean Status;
    boolean InterruptBitStatus;
#endif
    Reg_Stim_BfType *STIMx;

#if STD_ON == STIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_START();
#endif

#if STD_ON == STIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT(STIM_DRV_INSTANCE_COUNT > Instance);
    MCALLIB_DEV_ASSERT(NULL_PTR != ConfigChannelPtr);
    MCALLIB_DEV_ASSERT(STIM_DRV_CHANNEL_COUNT > ConfigChannelPtr->HwChannel);
#endif
    STIMx = Stim_Drv_StimRegBfPtr[Instance];

#if (STIM_DRV_STANDBY_WAKEUP_SUPPORT == STD_ON)
    Status = Stim_Drv_GetStatus(Instance, ConfigChannelPtr->HwChannel);
    InterruptBitStatus = Stim_Drv_GetInterruptBit(Instance, ConfigChannelPtr->HwChannel);
    if ((TRUE == Status) && (TRUE == InterruptBitStatus))
    {
#endif
        Stim_Drv_EnableTimer(Instance, ConfigChannelPtr->HwChannel, FALSE);

        Stim_Drv_EnableInt(Instance, ConfigChannelPtr->HwChannel, FALSE);

        Stim_Drv_ClearCompareFlag(Instance, ConfigChannelPtr->HwChannel);

        Stim_Drv_SelectTimerMode(Instance, ConfigChannelPtr->HwChannel, STIM_DRV_TIMER_MODE);

#if (STIM_DRV_STANDBY_WAKEUP_SUPPORT == STD_ON)
    }
#endif
    SchM_Enter_Gpt_StimControlAndStatusReg();
    if (TRUE == ConfigChannelPtr->PrescalerEnable)
    {
        STIMx->STIM_SCn[ConfigChannelPtr->HwChannel].PSEN = 1U;
    }
    else
    {
        STIMx->STIM_SCn[ConfigChannelPtr->HwChannel].PSEN = 0U;
    }
    SchM_Exit_Gpt_StimControlAndStatusReg();
    Stim_Drv_Configure(Instance, ConfigChannelPtr->HwChannel, ConfigChannelPtr->ClockSource,
                       ConfigChannelPtr->ClockPrescaler);

    Stim_Drv_WriteCompareValue(Instance, ConfigChannelPtr->HwChannel, 0xFFFFFFFFU);

#if (STIM_DRV_ISR_ENABLE == STD_ON)
    Stim_Drv_ChannelState[Instance][ConfigChannelPtr->HwChannel].ChannelInit = TRUE;
    Stim_Drv_ChannelState[Instance][ConfigChannelPtr->HwChannel].Callback = ConfigChannelPtr->Callback;
    Stim_Drv_ChannelState[Instance][ConfigChannelPtr->HwChannel].CallbackParam =
        ConfigChannelPtr->CallbackParam;
#endif

#if (STIM_DRV_SET_DUAL_CLOCK_MODE == STD_ON)
    Stim_Drv_ClockState[Instance][ConfigChannelPtr->HwChannel].ClockPrescaler =
        ConfigChannelPtr->ClockPrescaler;
    Stim_Drv_ClockState[Instance][ConfigChannelPtr->HwChannel].ClockAlternatePrescaler =
        ConfigChannelPtr->ClockAlternatePrescaler;
#endif
#if STD_ON == STIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief       This function de-initialize the STIM
 *
 * @param[in]   Instance: STIM peripheral instance number
 *
 * @return      None
 */
void Stim_Drv_DeInit(uint8 Instance)
{
    Reg_Stim_BfType *STIMx;

    uint8 ChannelIndex;
#if STD_ON == STIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_START();
#endif

#if STD_ON == STIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT(STIM_DRV_INSTANCE_COUNT > Instance);
#endif
    STIMx = Stim_Drv_StimRegBfPtr[Instance];

    for (ChannelIndex = 0; ChannelIndex < STIM_DRV_CHANNEL_COUNT; ChannelIndex++)
    {
        Stim_Drv_EnableTimer(Instance, ChannelIndex, FALSE);

        Stim_Drv_EnableInt(Instance, ChannelIndex, FALSE);

        Stim_Drv_ClearCompareFlag(Instance, ChannelIndex);
        /* Disable stim prescaler */
        STIMx->STIM_SCn[ChannelIndex].PSEN = 0U;
        STIMx->STIM_SCn[ChannelIndex].CLKS = 0U;
        STIMx->STIM_SCn[ChannelIndex].PSDIV = 0U;
    }
#if STD_ON == STIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief       Start the stim counter.
 *
 * @param[in]   Instance: STIM peripheral instance number
 * @param[in]   Channel: Select the stim channel number.
 * @param[in]   Value: Channel timeout value.
 *
 * @return      None
 */
void Stim_Drv_StartTimer(uint8 Instance, uint8 Channel, uint32 Value)
{
#if STD_ON == STIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_START();
#endif

#if STD_ON == STIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT(STIM_DRV_INSTANCE_COUNT > Instance);
    MCALLIB_DEV_ASSERT(STIM_DRV_CHANNEL_COUNT > Channel);
#endif

    Stim_Drv_EnableTimer(Instance, Channel, FALSE);

    Stim_Drv_WriteCompareValue(Instance, Channel, Value);

    Stim_Drv_EnableTimer(Instance, Channel, TRUE);
#if STD_ON == STIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief       Stop the stim counter.
 *
 * @param[in]   Instance: STIM peripheral instance number
 * @param[in]   Channel: Select the stim channel number.
 *
 * @return      None
 */
void Stim_Drv_StopTimer(uint8 Instance, uint8 Channel)
{
#if STD_ON == STIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_START();
#endif

#if STD_ON == STIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT(STIM_DRV_INSTANCE_COUNT > Instance);
    MCALLIB_DEV_ASSERT(STIM_DRV_CHANNEL_COUNT > Channel);
#endif

    Stim_Drv_EnableTimer(Instance, Channel, FALSE);

    Stim_Drv_ClearCompareFlag(Instance, Channel);
#if STD_ON == STIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief       Enable interrupt for stim channel.
 *
 * @param[in]   Instance: STIM peripheral instance number
 * @param[in]   Channel: Select the stim channel number.
 *
 * @return      None
 */
void Stim_Drv_EnableInterrupt(uint8 Instance, uint8 Channel)
{
#if STD_ON == STIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_START();
#endif

#if STD_ON == STIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT(STIM_DRV_INSTANCE_COUNT > Instance);
    MCALLIB_DEV_ASSERT(STIM_DRV_CHANNEL_COUNT > Channel);
#endif

    if (FALSE == Stim_Drv_GetInterruptBit(Instance, Channel))
    {
        Stim_Drv_ClearCompareFlag(Instance, Channel);

        Stim_Drv_EnableInt(Instance, Channel, TRUE);
    }
#if STD_ON == STIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief       Disable interrupt for stim channel.
 *
 * @param[in]   Instance: STIM peripheral instance number
 * @param[in]   Channel: Select the stim channel number.
 *
 * @return      None
 */
void Stim_Drv_DisableInterrupt(uint8 Instance, uint8 Channel)
{
#if STD_ON == STIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_START();
#endif

#if STD_ON == STIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT(STIM_DRV_INSTANCE_COUNT > Instance);
    MCALLIB_DEV_ASSERT(STIM_DRV_CHANNEL_COUNT > Channel);
#endif
    Stim_Drv_EnableInt(Instance, Channel, FALSE);
    Stim_Drv_ClearCompareFlag(Instance, Channel);
#if STD_ON == STIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_END();
#endif
}

#if (STIM_DRV_SET_DUAL_CLOCK_MODE == STD_ON)
/**
 * @brief       Change the Stim prescaler value.
 *
 * @param[in]   Instance: STIM peripheral instance number
 * @param[in]   Channel: Select the stim channel number.
 * @param[in]   ClockMode: Stim prescaler type.
 *                        - STIM_DRV_CLOCKMODE_NORMAL
 *                        - STIM_DRV_CLOCKMODE_ALTERNATE
 *
 * @return      None
 */
void Stim_Drv_SetDualClockMode(uint8 Instance, uint8 Channel, Stim_Drv_DualClockModeType ClockMode)
{
#if STD_ON == STIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_START();
#endif

#if STD_ON == STIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT(STIM_DRV_INSTANCE_COUNT > Instance);
    MCALLIB_DEV_ASSERT(STIM_DRV_CHANNEL_COUNT > Channel);
#endif

    if (STIM_DRV_CLOCKMODE_NORMAL == ClockMode)
    {
        Stim_Drv_SetPrescalerValue(Instance, Channel,
                                   Stim_Drv_ClockState[Instance][Channel].ClockPrescaler);
    }
    else
    {
        Stim_Drv_SetPrescalerValue(Instance, Channel,
                                   Stim_Drv_ClockState[Instance][Channel].ClockAlternatePrescaler);
    }
#if STD_ON == STIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_END();
#endif
}
#endif /*STIM_DRV_SET_DUAL_CLOCK_MODE*/

#if (STIM_DRV_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/**
 * @brief       Start the predefTimer.
 *
 * @param[in]   Instance: STIM peripheral instance number
 * @param[in]   Channel: Select the stim channel number.
 * @param[in]   CompareValue: Stim compare value.
 * @param[in]   Prescaler: Select stim prescaler value.
 * @param[in]   ClockSource: Select stim clock source.
 *
 * @return      None
 */
void Stim_Drv_StartPredefTimer(uint8 Instance, uint8 Channel, uint32 CompareValue, uint8 Prescaler,
                               uint8 ClockSource)
{
    Reg_Stim_BfType *STIMx;

#if STD_ON == STIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_START();
#endif

#if STD_ON == STIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT(STIM_DRV_INSTANCE_COUNT > Instance);
    MCALLIB_DEV_ASSERT(STIM_DRV_CHANNEL_COUNT > Channel);
#endif
    STIMx = Stim_Drv_StimRegBfPtr[Instance];

    Stim_Drv_EnableTimer(Instance, Channel, FALSE);

    Stim_Drv_EnableInt(Instance, Channel, FALSE);

    Stim_Drv_ClearCompareFlag(Instance, Channel);

    Stim_Drv_SelectTimerMode(Instance, Channel, STIM_DRV_TIMER_MODE);

    (void)Stim_Drv_SetCompareValue(Instance, Channel, CompareValue);

    SchM_Enter_Gpt_StimControlAndStatusReg();
    STIMx->STIM_SCn[Channel].CLKS = ClockSource;
    STIMx->STIM_SCn[Channel].PSDIV = Prescaler;
    /* Enable stim prescaler */
    STIMx->STIM_SCn[Channel].PSEN = 1U;
    SchM_Exit_Gpt_StimControlAndStatusReg();
    Stim_Drv_EnableTimer(Instance, Channel, TRUE);

#if STD_ON == STIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief       Stop the predefTimer.
 *
 * @param[in]   Instance: STIM peripheral instance number
 * @param[in]   Channel: Select the stim channel number.
 *
 * @return      None
 */
void Stim_Drv_StopPredefTimer(uint8 Instance, uint8 Channel)
{
#if STD_ON == STIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_START();
#endif

#if STD_ON == STIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT(STIM_DRV_INSTANCE_COUNT > Instance);
    MCALLIB_DEV_ASSERT(STIM_DRV_CHANNEL_COUNT > Channel);
#endif
    Stim_Drv_EnableTimer(Instance, Channel, FALSE);

    Stim_Drv_EnableInt(Instance, Channel, FALSE);

    Stim_Drv_ClearCompareFlag(Instance, Channel);

    (void)Stim_Drv_SetCompareValue(Instance, Channel, 0U);
#if STD_ON == STIM_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_END();
#endif
}
#endif /* STIM_DRV_PREDEFTIMER_FUNCTIONALITY_API */

#if (STIM_DRV_ISR_ENABLE == STD_ON)
/**
 * @brief   Interrupt handler for STIM channel.
 *
 * @return  None
 */
ISR(Stim_Drv_IrqHandler)
{
    uint8 Channel = 0U;

    for (Channel = 0U; Channel < STIM_DRV_CHANNEL_COUNT; Channel++)
    {
        Stim_Drv_IntHandler(0U, Channel);
    }
    EXIT_INTERRUPT();
}
#endif

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#endif /* STIM_DRV_ENABLE == STD_ON */

#ifdef __cplusplus
}
#endif

/** @} end of group Stim_Drv */

/** @} end of group Stim_Module */
