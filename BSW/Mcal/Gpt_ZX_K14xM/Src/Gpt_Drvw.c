/**************************************************************************************************/
/**
 * @file      : Gpt_Drvw.c
 * @brief     : AUTOSAR Gpt drvw driver source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup  Gpt_Module
 *  @{
 */

/** @addtogroup Gpt_Drvw
 *  @brief Gpt driver wrapper
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Gpt_Drvw.h"
#include "Rtc_Drv.h"
#include "Stim_Drv.h"
#include "Tim_Drv.h"
#include "SchM_Gpt.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
/* Published information */
#define GPT_DRVW_C_VENDOR_ID                   0x00B3U
#define GPT_DRVW_C_AR_RELEASE_MAJOR_VERSION    4U
#define GPT_DRVW_C_AR_RELEASE_MINOR_VERSION    6U
#define GPT_DRVW_C_AR_RELEASE_REVISION_VERSION 0U
#define GPT_DRVW_C_SW_MAJOR_VERSION            1U
#define GPT_DRVW_C_SW_MINOR_VERSION            2U
#define GPT_DRVW_C_SW_PATCH_VERSION            2U

/* Check if current file and Gpt_Drvw header file are of the same vendor */
#if (GPT_DRVW_C_VENDOR_ID != GPT_DRVW_H_VENDOR_ID)
    #error "Vendor ID of Gpt_Drvw.c and Gpt_Drvw.h are different"
#endif
/* Check if current file and Gpt_Drvw header file are of the same Autosar version */
#if ((GPT_DRVW_C_AR_RELEASE_MAJOR_VERSION != GPT_DRVW_H_AR_RELEASE_MAJOR_VERSION) ||               \
     (GPT_DRVW_C_AR_RELEASE_MINOR_VERSION != GPT_DRVW_H_AR_RELEASE_MINOR_VERSION) ||               \
     (GPT_DRVW_C_AR_RELEASE_REVISION_VERSION != GPT_DRVW_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Gpt_Drvw.c and Gpt_Drvw.h are different"
#endif
/* Check if current file and Gpt_Drvw header file are of the same Software version */
#if ((GPT_DRVW_C_SW_MAJOR_VERSION != GPT_DRVW_H_SW_MAJOR_VERSION) ||                               \
     (GPT_DRVW_C_SW_MINOR_VERSION != GPT_DRVW_H_SW_MINOR_VERSION) ||                               \
     (GPT_DRVW_C_SW_PATCH_VERSION != GPT_DRVW_H_SW_PATCH_VERSION))
    #error "Software Version of Gpt_Drvw.c and Gpt_Drvw.h are different"
#endif

/* Check if current file and Rtc_Drv header file are of the same vendor */
#if (GPT_DRVW_C_VENDOR_ID != RTC_DRV_H_VENDOR_ID)
    #error "Vendor ID of Gpt_Drvw.c and Rtc_Drv.h are different"
#endif
/* Check if current file and Rtc_Drv header file are of the same Autosar version */
#if ((GPT_DRVW_C_AR_RELEASE_MAJOR_VERSION != RTC_DRV_H_AR_RELEASE_MAJOR_VERSION) ||                \
     (GPT_DRVW_C_AR_RELEASE_MINOR_VERSION != RTC_DRV_H_AR_RELEASE_MINOR_VERSION) ||                \
     (GPT_DRVW_C_AR_RELEASE_REVISION_VERSION != RTC_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Gpt_Drvw.c and Rtc_Drv.h are different"
#endif
/* Check if current file and Rtc_Drv header file are of the same Software version */
#if ((GPT_DRVW_C_SW_MAJOR_VERSION != RTC_DRV_H_SW_MAJOR_VERSION) ||                                \
     (GPT_DRVW_C_SW_MINOR_VERSION != RTC_DRV_H_SW_MINOR_VERSION) ||                                \
     (GPT_DRVW_C_SW_PATCH_VERSION != RTC_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Gpt_Drvw.c and Rtc_Drv.h are different"
#endif

/* Check if current file and Stim_Drv header file are of the same vendor */
#if (GPT_DRVW_C_VENDOR_ID != STIM_DRV_H_VENDOR_ID)
    #error "Vendor ID of Gpt_Drvw.c and Stim_Drv.h are different"
#endif
/* Check if current file and Stim_Drv header file are of the same Autosar version */
#if ((GPT_DRVW_C_AR_RELEASE_MAJOR_VERSION != STIM_DRV_H_AR_RELEASE_MAJOR_VERSION) ||               \
     (GPT_DRVW_C_AR_RELEASE_MINOR_VERSION != STIM_DRV_H_AR_RELEASE_MINOR_VERSION) ||               \
     (GPT_DRVW_C_AR_RELEASE_REVISION_VERSION != STIM_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Gpt_Drvw.c and Stim_Drv.h are different"
#endif
/* Check if current file and Stim_Drv header file are of the same Software version */
#if ((GPT_DRVW_C_SW_MAJOR_VERSION != STIM_DRV_H_SW_MAJOR_VERSION) ||                               \
     (GPT_DRVW_C_SW_MINOR_VERSION != STIM_DRV_H_SW_MINOR_VERSION) ||                               \
     (GPT_DRVW_C_SW_PATCH_VERSION != STIM_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Gpt_Drvw.c and Stim_Drv.h are different"
#endif
/** @} end of Private_MacroDefinition */

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#if (RTC_DRV_ENABLE == STD_ON)
LOCAL_INLINE uint32
Gpt_Drvw_RtcGetTimeRemaing(const Gpt_Drvw_HwChannelConfigType *HwChannelConfigPtr);
LOCAL_INLINE uint32
Gpt_Drvw_RtcGetTimeElapsed(const Gpt_Drvw_HwChannelConfigType *HwChannelConfigPtr,
                           Gpt_Drvw_HwChannelInfoType         *ReturnHwChannelInfoPtr);
#endif
#if (STIM_DRV_ENABLE == STD_ON)
LOCAL_INLINE uint32
Gpt_Drvw_StimGetTimeElapsed(const Gpt_Drvw_HwChannelConfigType *HwChannelConfigPtr,
                            Gpt_Drvw_HwChannelInfoType         *ReturnHwChannelInfoPtr);
#endif
#if (TIM_DRV_ENABLE == STD_ON)
LOCAL_INLINE uint32
Gpt_Drvw_TimGetTimeElapsed(const Gpt_Drvw_HwChannelConfigType *HwChannelConfigPtr,
                           Gpt_Drvw_HwChannelInfoType         *ReturnHwChannelInfoPtr);
#endif
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#if (STIM_DRV_ENABLE == STD_ON)
/**
 * @brief        This function get stim elapsed time.
 * 
 * @param[in]    HwChannelConfigPtr  A pointer to the channel configuration structure.
 * @param[in]    ReturnHwChannelInfoPtr  The rollover status of the hardware timer channel.
 *
 * @return       uint32
 */
LOCAL_INLINE uint32
Gpt_Drvw_StimGetTimeElapsed(const Gpt_Drvw_HwChannelConfigType *HwChannelConfigPtr,
                            Gpt_Drvw_HwChannelInfoType         *ReturnHwChannelInfoPtr)
{
    uint32 ReturnValue = 0U;

    ReturnHwChannelInfoPtr->TargetTime =
        Stim_Drv_GetCompareValue(HwChannelConfigPtr->Instance, HwChannelConfigPtr->Channel);

    ReturnValue =
        Stim_Drv_GetCurrentCounterValue(HwChannelConfigPtr->Instance, HwChannelConfigPtr->Channel);

    if (TRUE == Stim_Drv_GetStatus(HwChannelConfigPtr->Instance, HwChannelConfigPtr->Channel))
    {
        ReturnHwChannelInfoPtr->ChannelRollover = TRUE;
    }
    else
    {
        ReturnHwChannelInfoPtr->ChannelRollover = FALSE;
    }

    return ((uint32)ReturnValue);
}
#endif

#if (RTC_DRV_ENABLE == STD_ON)
/**
 * @brief        This function get rtc remaining time.
 * 
 * @param[in]    HwChannelConfigPtr  A pointer to the channel configuration structure.
 *
 * @return       uint32
 */
LOCAL_INLINE uint32
Gpt_Drvw_RtcGetTimeRemaing(const Gpt_Drvw_HwChannelConfigType *HwChannelConfigPtr)
{
    uint32 Value = 0U;
    uint32 CompareValue = 0U;
    uint32 AlarmCounterValue = 0U;

    AlarmCounterValue = Rtc_Drv_GetAlarmCounter(HwChannelConfigPtr->Instance);
    CompareValue = Rtc_Drv_GetAlarmMatchCounter(HwChannelConfigPtr->Instance);
    if (AlarmCounterValue > CompareValue)
    {
        Value = (MAX_VALUE - AlarmCounterValue) + CompareValue + 1U;
    }
    else
    {
        Value = CompareValue - AlarmCounterValue;
    }
    return ((uint32)Value);
}
/**
 * @brief        This function get rtc elapsed time.
 * 
 * @param[in]    HwChannelConfigPtr  A pointer to the channel configuration structure.
 * @param[in]    ReturnHwChannelInfoPtr  The rollover status of the hardware timer channel.
 *
 * @return       uint32
 */
LOCAL_INLINE uint32
Gpt_Drvw_RtcGetTimeElapsed(const Gpt_Drvw_HwChannelConfigType *HwChannelConfigPtr,
                           Gpt_Drvw_HwChannelInfoType         *ReturnHwChannelInfoPtr)
{
    uint32 ReturnValue = 0U;
    uint32 IntStatus = 0U;
    uint32 RemainingValue = 0U;
    Rtc_Drv_InterruptType InterruptMode;

    InterruptMode = HwChannelConfigPtr->ChannelConfig.RtcChannelConfig->ModeSelect;

    ReturnHwChannelInfoPtr->TargetTime = Rtc_Drv_TargetValue;

    RemainingValue = Gpt_Drvw_RtcGetTimeRemaing(HwChannelConfigPtr);

    if (RemainingValue > Rtc_Drv_TargetValue)
    {
        ReturnValue = Rtc_Drv_TargetValue;
    }
    else
    {
        ReturnValue = Rtc_Drv_TargetValue - RemainingValue;
    }
    IntStatus = Rtc_Drv_GetIntStatus(HwChannelConfigPtr->Instance, InterruptMode);
    if (0U != IntStatus)
    {
        ReturnHwChannelInfoPtr->ChannelRollover = TRUE;
    }
    else
    {
        ReturnHwChannelInfoPtr->ChannelRollover = FALSE;
    }

    return ((uint32)ReturnValue);
}
#endif

#if (TIM_DRV_ENABLE == STD_ON)
/**
 * @brief        This function get timer elapsed time.
 * 
 * @param[in]    HwChannelConfigPtr  A pointer to the channel configuration structure.
 * @param[in]    ReturnHwChannelInfoPtr  The rollover status of the hardware timer channel.
 *
 * @return       uint32
 */
LOCAL_INLINE uint32
Gpt_Drvw_TimGetTimeElapsed(const Gpt_Drvw_HwChannelConfigType *HwChannelConfigPtr,
                           Gpt_Drvw_HwChannelInfoType         *ReturnHwChannelInfoPtr)
{
    uint32 ReturnValue = 0U;
    uint32 IntStatus = 0U;
    uint32 CompareValue = 0U;
    uint32 CounterValue = 0U;

    ReturnHwChannelInfoPtr->TargetTime =
        Tim_Drv_TargetValue[HwChannelConfigPtr->Instance][HwChannelConfigPtr->Channel];

    SchM_Enter_Gpt_TimGetValue();
    CounterValue = Tim_Drv_GetCounterValue(HwChannelConfigPtr->Instance);
    CompareValue =
        Tim_Drv_GetCompareValue(HwChannelConfigPtr->Instance, HwChannelConfigPtr->Channel);
    SchM_Exit_Gpt_TimGetValue();
    /* Calculate the elapsed time */
    if (CounterValue > CompareValue)
    {
        /* There will be roll-over during this timer period */
        if (((TIM_DRV_MAX_VALUE - CounterValue) + CompareValue + 1U) <=
            ReturnHwChannelInfoPtr->TargetTime)
        {
            ReturnValue = (ReturnHwChannelInfoPtr->TargetTime - \
                           ((TIM_DRV_MAX_VALUE - CounterValue) + CompareValue + 1U));
        }
        else
        {
            /* There is an delay in interrupt Handler, compare value has not been updated, 
            so counter value passed compare value. */
            ReturnValue = ReturnHwChannelInfoPtr->TargetTime;
        }
    }
    else
    {
        ReturnValue = ReturnHwChannelInfoPtr->TargetTime - (CompareValue - CounterValue);
    }

    IntStatus = Tim_Drv_GetInterruptFlag(HwChannelConfigPtr->Instance, HwChannelConfigPtr->Channel);

    /*Check interrupt status flag*/
    if (0U != IntStatus)
    {
        /* Channel counter was roll-over */
        ReturnHwChannelInfoPtr->ChannelRollover = TRUE;
    }
    else
    {
        /* Channel counter was not rollover */
        ReturnHwChannelInfoPtr->ChannelRollover = FALSE;
    }

    return ReturnValue;
}
#endif
/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
/**
 * @brief        This function initializes the Gpt driver instance.
 * 
 * @param[in]    HwInstanceConfigPtr  A pointer to the instance configuration structure.
 *
 * @return       void
 * @pre          The driver needs to be initialized.
 */
void Gpt_Drvw_InitInstances(const Gpt_Drvw_HwInstanceConfigType *HwInstanceConfigPtr)
{

    if (GPT_DRVW_TIM_MODULE == HwInstanceConfigPtr->InstanceType)
    {
#if (TIM_DRV_ENABLE == STD_ON)
        Tim_Drv_InitInstance(HwInstanceConfigPtr->Instance,
                             HwInstanceConfigPtr->InstanceConfig.Tim_Drv_InstanceConfig);
#endif
    }
    else
    {
        /* Nothing to do */
    }
    return;
}

/**
 * @brief      This function initializes the Gpt driver.
 *
 * @param[in]  HwChannelConfigPtr  A pointer to the channel configuration structure.
 *
 * @return     None
 */
void Gpt_Drvw_Init(const Gpt_Drvw_HwChannelConfigType *HwChannelConfigPtr)
{

    if (GPT_DRVW_TIM_MODULE == HwChannelConfigPtr->InstanceType)
    {
#if (TIM_DRV_ENABLE == STD_ON)
        Tim_Drv_InitChannel(HwChannelConfigPtr->Instance,
                            HwChannelConfigPtr->ChannelConfig.TimChannelConfig);
#endif
    }
    else if (GPT_DRVW_RTC_MODULE == HwChannelConfigPtr->InstanceType)
    {
#if (RTC_DRV_ENABLE == STD_ON)
        Rtc_Drv_Init(HwChannelConfigPtr->Instance,
                     HwChannelConfigPtr->ChannelConfig.RtcChannelConfig);
#endif
    }
    else if (GPT_DRVW_STIM_MODULE == HwChannelConfigPtr->InstanceType)
    {
#if (STIM_DRV_ENABLE == STD_ON)
        Stim_Drv_InitChannel(HwChannelConfigPtr->Instance,
                             HwChannelConfigPtr->ChannelConfig.StimChannelConfig);
#endif
    }
    else
    {
        /* Nothing to do */
    }
}

#if (GPT_DRVW_DEINIT_API == STD_ON)
/**
 * @brief      This function de-initializes the Gpt driver.
 *
 * @param[in]  HwChannelConfigPtr A pointer to the channel configuration structure.
 *
 * @return     None
 */
void Gpt_Drvw_DeInit(const Gpt_Drvw_HwChannelConfigType *HwChannelConfigPtr)
{
    if (GPT_DRVW_TIM_MODULE == HwChannelConfigPtr->InstanceType)
    {
#if (TIM_DRV_ENABLE == STD_ON)
        Tim_Drv_Deinit(HwChannelConfigPtr->Instance);
#endif
    }
    else if (GPT_DRVW_RTC_MODULE == HwChannelConfigPtr->InstanceType)
    {
#if (RTC_DRV_ENABLE == STD_ON)
        Rtc_Drv_DeInit(HwChannelConfigPtr->Instance);
#endif
    }
    else if (GPT_DRVW_STIM_MODULE == HwChannelConfigPtr->InstanceType)
    {
#if (STIM_DRV_ENABLE == STD_ON)
        Stim_Drv_DeInit(HwChannelConfigPtr->Instance);
#endif
    }
    else
    {
        /* Nothing to do */
    }
    return;
}
#endif

/**
 * @brief      This function returns the time already elapsed.
 *
 * @param[in]  HwChannelConfigPtr  A pointer to the channel configuration structure.
 * @param[out] ReturnHwChannelInfoPtr  The rollover status of the hardware timer channel.
 *
 * @return     uint32
 * @retval     The elapsed time
 */
uint32 Gpt_Drvw_GetTimeElapsed(const Gpt_Drvw_HwChannelConfigType *HwChannelConfigPtr,
                               Gpt_Drvw_HwChannelInfoType         *ReturnHwChannelInfoPtr)
{
    uint32 ReturnValue = 0U;

    if (GPT_DRVW_TIM_MODULE == HwChannelConfigPtr->InstanceType)
    {
#if (TIM_DRV_ENABLE == STD_ON)
        ReturnValue = Gpt_Drvw_TimGetTimeElapsed(HwChannelConfigPtr, ReturnHwChannelInfoPtr);
#endif
    }
    else if (GPT_DRVW_RTC_MODULE == HwChannelConfigPtr->InstanceType)
    {
#if (RTC_DRV_ENABLE == STD_ON)
        ReturnValue = Gpt_Drvw_RtcGetTimeElapsed(HwChannelConfigPtr, ReturnHwChannelInfoPtr);
#endif
    }
    else if (GPT_DRVW_STIM_MODULE == HwChannelConfigPtr->InstanceType)
    {
#if (STIM_DRV_ENABLE == STD_ON)
        ReturnValue = Gpt_Drvw_StimGetTimeElapsed(HwChannelConfigPtr, ReturnHwChannelInfoPtr);
#endif
    }
    else
    {
        /* Nothing to do */
    }
    return ReturnValue;
}

/**
 * @brief      This function starts the timer.
 *
 * @param[in]  HwChannelConfigPtr A pointer to the channel configuration structure.
 * @param[in]  Value   A notification is generated when the value is reached(if enabled).
 *
 * @return     Std_ReturnType
 * @retval     E_OK
 * @retval     E_NOT_OK
 */
Std_ReturnType Gpt_Drvw_StartTimer(const Gpt_Drvw_HwChannelConfigType  *HwChannelConfigPtr,
                                   uint32                               Value)
{

    Std_ReturnType ReturnValue = (Std_ReturnType)E_NOT_OK;

    if (GPT_DRVW_TIM_MODULE == HwChannelConfigPtr->InstanceType)
    {
#if (TIM_DRV_ENABLE == STD_ON)
        Tim_Drv_StartTimer(HwChannelConfigPtr->Instance, HwChannelConfigPtr->Channel, (uint16)Value,
                           HwChannelConfigPtr->ChannelConfig.TimChannelConfig->ClockSource);
        ReturnValue = (Std_ReturnType)E_OK;
#endif
    }
    else if (GPT_DRVW_RTC_MODULE == HwChannelConfigPtr->InstanceType)
    {
#if (RTC_DRV_ENABLE == STD_ON)
        Rtc_Drv_StartTimer(HwChannelConfigPtr->Instance, Value);
        ReturnValue = (Std_ReturnType)E_OK;
#endif
    }
    else if (GPT_DRVW_STIM_MODULE == HwChannelConfigPtr->InstanceType)
    {
#if (STIM_DRV_ENABLE == STD_ON)
        Stim_Drv_StartTimer(HwChannelConfigPtr->Instance, HwChannelConfigPtr->Channel, Value);
        ReturnValue = (Std_ReturnType)E_OK;
#endif
    }
    else
    {
        /* Nothing to do */
    }

    return ReturnValue;
}

/**
 * @brief      This function stops the timer.
 *
 * @param[in]  HwChannelConfigPtr A pointer to the channel configuration structure.
 *
 * @return     None
 */
void Gpt_Drvw_StopTimer(const Gpt_Drvw_HwChannelConfigType *HwChannelConfigPtr)
{
    if (GPT_DRVW_TIM_MODULE == HwChannelConfigPtr->InstanceType)
    {
#if (TIM_DRV_ENABLE == STD_ON)
        Tim_Drv_StopTimer(HwChannelConfigPtr->Instance, HwChannelConfigPtr->Channel);
#endif
    }
    else if (GPT_DRVW_RTC_MODULE == HwChannelConfigPtr->InstanceType)
    {
#if (RTC_DRV_ENABLE == STD_ON)
        /* Stop counter */
        (void)Rtc_Drv_StopTimer(HwChannelConfigPtr->Instance);
#endif
    }
    else if (GPT_DRVW_STIM_MODULE == HwChannelConfigPtr->InstanceType)
    {
#if (STIM_DRV_ENABLE == STD_ON)
        Stim_Drv_StopTimer(HwChannelConfigPtr->Instance, HwChannelConfigPtr->Channel);
#endif
    }
    else
    {
        /* Nothing to do */
    }
}

/**
 * @brief      This function enables hardware timer interrupts.
 *
 * @param[in]  HwChannelConfigPtr A pointer to the channel configuration structure.
 *
 * @return     None
 */
void Gpt_Drvw_EnableInterrupt(const Gpt_Drvw_HwChannelConfigType *HwChannelConfigPtr)
{
    if (GPT_DRVW_TIM_MODULE == HwChannelConfigPtr->InstanceType)
    {
#if (TIM_DRV_ENABLE == STD_ON)
        Tim_Drv_EnableChannelInterrupt(HwChannelConfigPtr->Instance, HwChannelConfigPtr->Channel);
#endif
    }
    else if (GPT_DRVW_RTC_MODULE == HwChannelConfigPtr->InstanceType)
    {
#if (RTC_DRV_ENABLE == STD_ON)
        Rtc_Drv_EnableInterrupt(HwChannelConfigPtr->Instance, RTC_DRV_INT_ALARM);
#endif
    }
    else if (GPT_DRVW_STIM_MODULE == HwChannelConfigPtr->InstanceType)
    {
#if (STIM_DRV_ENABLE == STD_ON)
        Stim_Drv_EnableInterrupt(HwChannelConfigPtr->Instance, HwChannelConfigPtr->Channel);
#endif
    }
    else
    {
        /* Nothing to do */
    }
    return;
}

#if ((GPT_DRVW_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) ||                                       \
     (GPT_DRVW_WAKEUP_FUNCTIONALITY_API == STD_ON))
/**
 * @brief      This function disable hardware timer interrupts.
 *
 * @param[in]  HwChannelConfigPtr A pointer to the channel configuration structure.
 *
 * @return     None
 */
void Gpt_Drvw_DisableInterrupt(const Gpt_Drvw_HwChannelConfigType *HwChannelConfigPtr)
{
    if (GPT_DRVW_TIM_MODULE == HwChannelConfigPtr->InstanceType)
    {
#if (TIM_DRV_ENABLE == STD_ON)
        Tim_Drv_DisableChannelInterrupt(HwChannelConfigPtr->Instance, HwChannelConfigPtr->Channel);
#endif
    }
else if (GPT_DRVW_RTC_MODULE == HwChannelConfigPtr->InstanceType)
    {
#if (RTC_DRV_ENABLE == STD_ON)
        Rtc_Drv_DisableInterrupt(HwChannelConfigPtr->Instance, RTC_DRV_INT_ALARM);
#endif
    }
else if (GPT_DRVW_STIM_MODULE == HwChannelConfigPtr->InstanceType)
    {
#if (STIM_DRV_ENABLE == STD_ON)
        Stim_Drv_DisableInterrupt(HwChannelConfigPtr->Instance, HwChannelConfigPtr->Channel);
#endif
    }
    else
    {
        /* Nothing to do */
    }
}
#endif

#if (GPT_DRVW_SET_DUAL_CLOCK_MODE == STD_ON)
/**
 * @brief      This function sets instance dual clock mode.
 *
 * @param[in]  InstanceConfigPtr A pointer to the channel configuration structure.
 * @param[in]  ClockMode  Prescaler type.
 *
 * @return     None
 */
void Gpt_Drvw_SetInstanceDualClockMode(const Gpt_Drvw_HwInstanceConfigType *InstanceConfigPtr,
                                       Gpt_Drvw_DualClockModeType           ClockMode)
{
    switch (InstanceConfigPtr->InstanceType)
    {
        case (GPT_DRVW_TIM_MODULE):
#if (TIM_DRV_ENABLE == STD_ON)
            if (GPT_DRVW_CLOCKMODE_NORMAL == ClockMode)
            {
                Tim_Drv_SetDualClockMode(InstanceConfigPtr->Instance, TIM_DRV_CLOCKMODE_NORMAL);
            }
            else
            {
                Tim_Drv_SetDualClockMode(InstanceConfigPtr->Instance, TIM_DRV_CLOCKMODE_ALTERNATE);
            }
#endif
            break;
        default:
            /* Do nothing */
            break;
    }
}
/**
 * @brief      This function sets channel dual clock mode.
 *
 * @param[in]  HwChannelConfigPtr A pointer to the channel configuration structure.
 * @param[in]  ClockMode  Prescaler type.
 *
 * @return     None
 */
void Gpt_Drvw_SetChannelDualClockMode(const Gpt_Drvw_HwChannelConfigType  *HwChannelConfigPtr,
                               Gpt_Drvw_DualClockModeType           ClockMode)
{
    switch (HwChannelConfigPtr->InstanceType)
    {
        case (GPT_DRVW_STIM_MODULE):
#if (STIM_DRV_ENABLE == STD_ON)
            if (GPT_DRVW_CLOCKMODE_NORMAL == ClockMode)
            {
                Stim_Drv_SetDualClockMode(HwChannelConfigPtr->Instance, HwChannelConfigPtr->Channel,
                                          STIM_DRV_CLOCKMODE_NORMAL);
            }
            else
            {
                Stim_Drv_SetDualClockMode(HwChannelConfigPtr->Instance, HwChannelConfigPtr->Channel,
                                          STIM_DRV_CLOCKMODE_ALTERNATE);
            }
#endif
            break;
        default:
            /* Do nothing */
            break;
    }
}
#endif /* GPT_DRVW_SET_DUAL_CLOCK_MODE == STD_ON */

#if (GPT_DRVW_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/**
 * @brief      This function start predeftimer.
 *
 * @param[in]  HwPredefChannelConfigPtr A pointer to the channel configuration structure.
 * @param[in]  PrdefTimerType  The type of predef timer.
 *
 * @return     None
 */
void Gpt_Drvw_StartPredefTimer(const Gpt_Drvw_HwPredefChannelConfigType *HwPredefChannelConfigPtr,
                               Gpt_Drvw_PredefTimerType                  PrdefTimerType)
{
    if (NULL_PTR != HwPredefChannelConfigPtr)
    {
        switch (HwPredefChannelConfigPtr->InstanceType)
        {
            case GPT_DRVW_STIM_MODULE:
#if (STIM_DRV_ENABLE == STD_ON)
                switch (PrdefTimerType)
                {
                    case GPT_DRVW_PREDEF_TIMER_1US_16BIT:
                        Stim_Drv_StartPredefTimer(HwPredefChannelConfigPtr->Instance,
                                                  HwPredefChannelConfigPtr->Channel, 0xFFFFU,
                                                  HwPredefChannelConfigPtr->Prescaler,
                                                  HwPredefChannelConfigPtr->ClockSource);
                        break;
                    case GPT_DRVW_PREDEF_TIMER_1US_24BIT:
                        Stim_Drv_StartPredefTimer(HwPredefChannelConfigPtr->Instance,
                                                  HwPredefChannelConfigPtr->Channel, 0xFFFFFFU,
                                                  HwPredefChannelConfigPtr->Prescaler,
                                                  HwPredefChannelConfigPtr->ClockSource);
                        break;
                    case GPT_DRVW_PREDEF_TIMER_1US_32BIT:
                        Stim_Drv_StartPredefTimer(HwPredefChannelConfigPtr->Instance,
                                                  HwPredefChannelConfigPtr->Channel, 0xFFFFFFFFU,
                                                  HwPredefChannelConfigPtr->Prescaler,
                                                  HwPredefChannelConfigPtr->ClockSource);
                        break;
                    case GPT_DRVW_PREDEF_TIMER_100US_32BIT:
                        /* Nothing to do */
                        break;
                    default:
                        /* Do nothing */
                        break;
                }
#endif
                break;
            default:
                /* Do nothing */
                break;
        }
    }
}

/**
 * @brief      This function get value of predeftimer.
 *
 * @param[in]  HwPredefChannelConfigPtr A pointer to the channel configuration structure.
 * @param[in]  TimeValuePtr    A pointer that saves the current value of the channel.
 *
 * @return     None
 */
void Gpt_Drvw_GetPredefTimerValue
(
    const Gpt_Drvw_HwPredefChannelConfigType *HwPredefChannelConfigPtr,
    Gpt_Drvw_PredefTimerType PredefTimer, uint32 *TimeValuePtr
)
{
    uint32 ReturnValue = 0U;
    switch (HwPredefChannelConfigPtr->InstanceType)
    {
        case GPT_DRVW_STIM_MODULE:
#if (STIM_DRV_ENABLE == STD_ON)
            ReturnValue = Stim_Drv_GetCurrentCounterValue(HwPredefChannelConfigPtr->Instance,
                                                          HwPredefChannelConfigPtr->Channel);
#endif
            break;
        default:
            /* Do nothing */
            break;
    }
    switch (PredefTimer)
    {
        case GPT_DRVW_PREDEF_TIMER_1US_16BIT:
            *TimeValuePtr = (0x0000FFFFU & ReturnValue);
            break;
        case GPT_DRVW_PREDEF_TIMER_1US_24BIT:
            *TimeValuePtr = (0x00FFFFFFU & ReturnValue);
            break;
        case GPT_DRVW_PREDEF_TIMER_1US_32BIT:
            *TimeValuePtr = ReturnValue;
            break;
        case GPT_DRVW_PREDEF_TIMER_100US_32BIT:
            *TimeValuePtr = ReturnValue;
            break;
        default:
            /* Do nothing */
            break;
    }
}

/**
 * @brief      This function stops predeftimer.
 *
 * @param[in]  HwPredefChannelConfigPtr  A pointer to the channel configuration structure.
 *
 * @return     None
 */
void Gpt_Drvw_StopPredefTimer(const Gpt_Drvw_HwPredefChannelConfigType *HwPredefChannelConfigPtr)
{
    if (NULL_PTR != HwPredefChannelConfigPtr)
    {
        switch (HwPredefChannelConfigPtr->InstanceType)
        {
            case GPT_DRVW_STIM_MODULE:
#if (STIM_DRV_ENABLE == STD_ON)
                Stim_Drv_StopPredefTimer(HwPredefChannelConfigPtr->Instance,
                                         HwPredefChannelConfigPtr->Channel);
#endif
                break;
            default:
                /* Do nothing */
                break;
        }
    }
    return;
}
#endif

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Gpt_Drvw */

/** @} end of group Gpt_Module */
