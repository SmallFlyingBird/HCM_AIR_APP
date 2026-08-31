/**
 * @file    Gpt_Lld_Rtc.c
 * @version V2.3.0
 *
 * @brief   MCU Gpt module interface
 * @details API implementation for GPT driver
 *
 * @addtogroup GPT_LLD_RTC_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : rtc
 *   Dependencies         : none
 *
 *   Autosar Version      : V4.4.0
 *   Autosar Revision     : ASR_REL_4_4_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           : V2.3.0
 *
 *   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
 *   All Rights Reserved.
==================================================================================================*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Gpt_Lld_Rtc.h"
#include "Std_Types.h"
#include "Gpt_Lld_Rtc_Types.h"
#include "Gpt_Lld_Rtc_Reg.h"
#include "SchM_Gpt.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_LLD_RTC_VENDOR_ID_C                      (180)
#define GPT_LLD_RTC_AR_RELEASE_MAJOR_VERSION_C       (4)
#define GPT_LLD_RTC_AR_RELEASE_MINOR_VERSION_C       (4)
#define GPT_LLD_RTC_AR_RELEASE_REVISION_VERSION_C    (0)
#define GPT_LLD_RTC_SW_MAJOR_VERSION_C               (2)
#define GPT_LLD_RTC_SW_MINOR_VERSION_C               (3)
#define GPT_LLD_RTC_SW_PATCH_VERSION_C               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and GPT_LLD_RTC header file are of the same vendor */
#if (GPT_LLD_RTC_VENDOR_ID_C != GPT_LLD_RTC_VENDOR_ID)
#error "Gpt_Lld_Rtc.c and Gpt_Lld_Rtc.h have different vendor ids"
#endif

/* Check if source file and GPT_LLD_RTC header file are of the same Autosar version */
#if ((GPT_LLD_RTC_AR_RELEASE_MAJOR_VERSION_C != GPT_LLD_RTC_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_LLD_RTC_AR_RELEASE_MINOR_VERSION_C != GPT_LLD_RTC_AR_RELEASE_MINOR_VERSION) || \
     (GPT_LLD_RTC_AR_RELEASE_REVISION_VERSION_C != GPT_LLD_RTC_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Gpt_Lld_Rtc.c and Gpt_Lld_Rtc.h are different"
#endif

/* Check if source file and GPT_LLD_RTC header file are of the same Software version */
#if ((GPT_LLD_RTC_SW_MAJOR_VERSION_C != GPT_LLD_RTC_SW_MAJOR_VERSION) || \
     (GPT_LLD_RTC_SW_MINOR_VERSION_C != GPT_LLD_RTC_SW_MINOR_VERSION) || \
     (GPT_LLD_RTC_SW_PATCH_VERSION_C != GPT_LLD_RTC_SW_PATCH_VERSION))
#error "Software Version Numbers of Gpt_Lld_Rtc.c and Gpt_Lld_Rtc.h are different"
#endif

/* Check if GPT_LLD_RTC_REG_H file and GPT_LLD_RTC header file are of the same vendor */
#if (GPT_LLD_RTC_REG_VENDOR_ID != GPT_LLD_RTC_VENDOR_ID)
#error "Gpt_Lld_Rtc_Reg.h and Gpt_Lld_Rtc.h have different vendor ids"
#endif

/* Check if GPT_LLD_RTC_REG_H file and GPT_LLD_RTC header file are of the same Autosar version */
#if ((GPT_LLD_RTC_REG_AR_RELEASE_MAJOR_VERSION != GPT_LLD_RTC_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_LLD_RTC_REG_AR_RELEASE_MINOR_VERSION != GPT_LLD_RTC_AR_RELEASE_MINOR_VERSION) || \
     (GPT_LLD_RTC_REG_AR_RELEASE_REVISION_VERSION != GPT_LLD_RTC_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Gpt_Lld_Rtc_Reg.h and Gpt_Lld_Rtc.h are different"
#endif

/* Check if GPT_LLD_RTC_REG_H file and GPT_LLD_RTC header file are of the same Software version */
#if ((GPT_LLD_RTC_REG_SW_MAJOR_VERSION != GPT_LLD_RTC_SW_MAJOR_VERSION) || \
     (GPT_LLD_RTC_REG_SW_MINOR_VERSION != GPT_LLD_RTC_SW_MINOR_VERSION) || \
     (GPT_LLD_RTC_REG_SW_PATCH_VERSION != GPT_LLD_RTC_SW_PATCH_VERSION))
#error "Software Version Numbers of Gpt_Lld_Rtc_Reg.h and Gpt_Lld_Rtc.h are different"
#endif

/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
#define RTC_REG_ADDR32_READ(address) (*(volatile uint32 *)(address))
#define RTC_REG_ADDR32_WRITE(address, value) ((*(volatile uint32 *)(address)) = (value))
#define RTC_REG_ADDR32_AEARWRITE(address, mask, value) \
    (RTC_REG_ADDR32_WRITE((address),                   \
                           ((RTC_REG_ADDR32_READ(address) & ((uint32) ~(mask))) | (value))))

#define RTC_REG_ADDR32_SET_BITS(address, mask) ((*(volatile uint32 *)(address)) |= (mask))
#define RTC_REG_ADDR32_CLEAR_BITS(address, mask) ((*(volatile uint32 *)(address)) &= (~(mask)))
#define RTC_REG_ADDR32_GET_BITS(address, mask) ((*(volatile uint32 *)(address)) & (mask))
#define RTC_REG_ADDR32_INDEX_SET_BIT(address, bitindex) ((*(volatile uint32 *)(address)) |= ((uint32)1 << (bitindex)))
#define RTC_REG_ADDR32_INDEX_CLEAR_BIT(address, bitindex) ((*(volatile uint32 *)(address)) &= (~((uint32)1 << (bitindex))))

/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/
#define GPT_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Gpt_MemMap.h"

GPT_VAR static Rtc_InfoType Rtc_Info;

extern GPT_VAR Gpt_ModeType Gpt_Mode;

#define GPT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Gpt_MemMap.h"


/*==================================================================================================
 *                                         LOCAL CONSTANTS
==================================================================================================*/
#define GPT_START_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"

/** @brief Table of base addresses for RTC instances. */
GPT_CONST static volatile RTC_Type * const Rtc_Lld_Base[RTC_INSTANCE_COUNT] = RTC_BASE_PTRS;

#define GPT_STOP_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

/**
 * @brief       This function initializes the RTC module.
 * @param[in]   ConfigPtr Pointer to the RTC instance configuration structure.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_RtcInitInstance(const Rtc_InstanceConfigType * ConfigPtr)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_20();

    /* Disable interrupt */
    RTC_REG_ADDR32_CLEAR_BITS(RTC0_BASE_ADDR32 + RTC_INTE_OFFSET32, RTC_INTE_ALMIE_MASK);
    RTC_REG_ADDR32_CLEAR_BITS(RTC0_BASE_ADDR32 + RTC_INTE_OFFSET32, RTC_INTE_SECIE_MASK);
    RTC_REG_ADDR32_CLEAR_BITS(RTC0_BASE_ADDR32 + RTC_INTE_OFFSET32, RTC_INTE_OVFIE_MASK);

    /* Disable RTC module */
    RTC_REG_ADDR32_SET_BITS(RTC0_BASE_ADDR32 + RTC_CTRL_OFFSET32, RTC_CTRL_UNLOCK_MASK);
    RTC_REG_ADDR32_CLEAR_BITS(RTC0_BASE_ADDR32 + RTC_EN_OFFSET32, RTC_EN_EN_MASK);
    RTC_REG_ADDR32_CLEAR_BITS(RTC0_BASE_ADDR32 + RTC_CTRL_OFFSET32, RTC_CTRL_UNLOCK_MASK);

    /* Set second value to 0 */
    RTC_REG_ADDR32_WRITE(RTC0_BASE_ADDR32 + RTC_SEC_OFFSET32, 0U);

    /* Write ALM register to clear alarm interrupt flag */
    RTC_REG_ADDR32_WRITE(RTC0_BASE_ADDR32 + RTC_ALM_OFFSET32, 0U);

    /* Clear second and overflow interrupt flag. */
    RTC_REG_ADDR32_WRITE(RTC0_BASE_ADDR32 + RTC_INTF_OFFSET32, RTC_INTF_SECIF_MASK | RTC_INTF_OVFIF_MASK);
    RTC_REG_ADDR32_WRITE(RTC0_BASE_ADDR32 + RTC_INTF_OFFSET32, 0U);

    /* Config run or stop in debug mode */
    if (TRUE == ConfigPtr->StopInDebugMode)
    {
        RTC_REG_ADDR32_SET_BITS(RTC0_BASE_ADDR32 + RTC_CTRL_OFFSET32, RTC_CTRL_DBGDIS_MASK);
    }
    else
    {
        RTC_REG_ADDR32_CLEAR_BITS(RTC0_BASE_ADDR32 + RTC_CTRL_OFFSET32, RTC_CTRL_DBGDIS_MASK);
    }

    /* Set clock source */
    RTC_REG_ADDR32_AEARWRITE(RTC0_BASE_ADDR32 + RTC_CTRL_OFFSET32, RTC_CTRL_CLKSEL_MASK, RTC_CTRL_CLKSEL(ConfigPtr->ClockSource));
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_20();
}

/**
 * @brief       This function initializes the RTC module.
 * @param[in]   ConfigPtr Pointer to the RTC configuration structure.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Rtc_Init(const Rtc_ConfigType * ConfigPtr)
{
    Rtc_Info.IsNotificationEnabled = FALSE;
    Rtc_Info.NotificationPtr = ConfigPtr->NotificationPtr;
    Rtc_Info.CountMode = ConfigPtr->CountMode;
    Rtc_Info.IsWakeupEnabled = FALSE;
    Rtc_Info.IsWakeupGenerated = FALSE;
    Rtc_Info.State = RTC_STATE_INITIALIZED;
    Rtc_Info.StopValue = 0U;
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    Rtc_Info.WakeupSource = ConfigPtr->WakeupSource;
#endif

}

/**
 * @brief       De-Initializes the Rtc instance.
 * @param[in]   Instance The Rtc instance id
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Rtc_DeInit(uint8 Instance)
{
    volatile RTC_Type * const Base = Rtc_Lld_Base[Instance];

    RTC_REG_ADDR32_SET_BITS(RTC0_BASE_ADDR32 + RTC_CTRL_OFFSET32, RTC_CTRL_UNLOCK_MASK);
    Base->EN = 0U;
    RTC_REG_ADDR32_CLEAR_BITS(RTC0_BASE_ADDR32 + RTC_CTRL_OFFSET32, RTC_CTRL_UNLOCK_MASK);
    Base->SEC = 0U;
    Base->CMP = 0U;
    Base->ALM = 0U;
    Base->CTRL = 0U;
    Base->INTE = 0U;
    /* Write 1 and then write 0 to clear Interrupt flag. */
    Base->INTF = RTC_INTF_SECIF_MASK | RTC_INTF_OVFIF_MASK;
    Base->INTF = 0U;

    Rtc_Info.State = RTC_STATE_UNINIT;
    Rtc_Info.IsNotificationEnabled = FALSE;
    Rtc_Info.NotificationPtr = NULL_PTR;
    Rtc_Info.CountMode = RTC_MODE_CONTINUOUS;
    Rtc_Info.PeriodTickValue = 0U;
    Rtc_Info.TargetCompareValue = 0U;
    Rtc_Info.StopValue = 0U;
}

/**
 * @brief       This function starts the Rtc module.
 * @param[in]   Value Period value.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Rtc_StartTimer(Rtc_ValueType Value)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_21();
    /* Set alarm value */
    Rtc_Info.PeriodTickValue = Value;
    Rtc_ValueType CurrentSecondValue = RTC_REG_ADDR32_READ(RTC0_BASE_ADDR32 + RTC_SEC_OFFSET32);
    Rtc_Info.TargetCompareValue = CurrentSecondValue + Rtc_Info.PeriodTickValue;
    RTC_REG_ADDR32_WRITE(RTC0_BASE_ADDR32 + RTC_ALM_OFFSET32, Rtc_Info.TargetCompareValue);

    /* Enable interrupt */
    if (RTC_MODE_ONESHOT == Rtc_Info.CountMode)
    {
        RTC_REG_ADDR32_SET_BITS(RTC0_BASE_ADDR32 + RTC_INTE_OFFSET32, RTC_INTE_ALMIE_MASK);
    }
    /* Start RTC */
    RTC_REG_ADDR32_SET_BITS(RTC0_BASE_ADDR32 + RTC_CTRL_OFFSET32, RTC_CTRL_UNLOCK_MASK);
    RTC_REG_ADDR32_SET_BITS(RTC0_BASE_ADDR32 + RTC_EN_OFFSET32, RTC_EN_EN_MASK);
    RTC_REG_ADDR32_CLEAR_BITS(RTC0_BASE_ADDR32 + RTC_CTRL_OFFSET32, RTC_CTRL_UNLOCK_MASK);
    /* Update timer state to "running" */
    Rtc_Info.State = RTC_STATE_RUNNING;
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_21();
}

/**
 * @brief       This function stops the RTC module.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Rtc_StopTimer(void)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_22();
    Rtc_Info.StopValue = RTC_REG_ADDR32_READ(RTC0_BASE_ADDR32 + RTC_SEC_OFFSET32);
    /* Disable interrupt */
    RTC_REG_ADDR32_CLEAR_BITS(RTC0_BASE_ADDR32 + RTC_INTE_OFFSET32, RTC_INTE_ALMIE_MASK);
    /* Disable RTC module */
    RTC_REG_ADDR32_SET_BITS(RTC0_BASE_ADDR32 + RTC_CTRL_OFFSET32, RTC_CTRL_UNLOCK_MASK);
    RTC_REG_ADDR32_CLEAR_BITS(RTC0_BASE_ADDR32 + RTC_EN_OFFSET32, RTC_EN_EN_MASK);
    RTC_REG_ADDR32_CLEAR_BITS(RTC0_BASE_ADDR32 + RTC_CTRL_OFFSET32, RTC_CTRL_UNLOCK_MASK);
    /* Update timer state to "stoped" */
    if (RTC_MODE_CONTINUOUS == Rtc_Info.CountMode)
    {
        Rtc_Info.State = RTC_STATE_STOPPED;
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_22();
}

/**
 * @brief       This function is the RTC interrupt handler.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Rtc_IrqProcess(void)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_23();
    uint32 IntFlag = RTC_REG_ADDR32_GET_BITS(RTC0_BASE_ADDR32 + RTC_INTF_OFFSET32, RTC_INTF_ALMIF_MASK) >> RTC_INTF_ALMIF_SHIFT;
    uint32 IntEnable = RTC_REG_ADDR32_GET_BITS(RTC0_BASE_ADDR32 + RTC_INTE_OFFSET32, RTC_INTE_ALMIE_MASK) >> RTC_INTE_ALMIE_SHIFT;
    if ((1U == IntFlag) && (1U == IntEnable))
    {
        if(GPT_MODE_SLEEP == Gpt_Mode) {
            Rtc_Info.IsWakeupGenerated = TRUE;
            Gpt_Mode = GPT_MODE_NORMAL;
        }
        if (RTC_MODE_ONESHOT == Rtc_Info.CountMode)
        {
            /* Disable interrupt */
            RTC_REG_ADDR32_CLEAR_BITS(RTC0_BASE_ADDR32 + RTC_INTE_OFFSET32, RTC_INTE_ALMIE_MASK);
            /* Disable RTC module */
            RTC_REG_ADDR32_SET_BITS(RTC0_BASE_ADDR32 + RTC_CTRL_OFFSET32, RTC_CTRL_UNLOCK_MASK);
            RTC_REG_ADDR32_CLEAR_BITS(RTC0_BASE_ADDR32 + RTC_EN_OFFSET32, RTC_EN_EN_MASK);
            RTC_REG_ADDR32_CLEAR_BITS(RTC0_BASE_ADDR32 + RTC_CTRL_OFFSET32, RTC_CTRL_UNLOCK_MASK);
            /* Clear Alarm Interrupt flag */
            RTC_REG_ADDR32_WRITE(RTC0_BASE_ADDR32 + RTC_ALM_OFFSET32, 0U);
            /* Update channel state to expired */
            Rtc_Info.State = RTC_STATE_EXPIRED;
        }
        /* when continuous mode, */
        else
        {
            /* Update Stop time stamp */
            Rtc_Info.TargetCompareValue += Rtc_Info.PeriodTickValue;
            /* Update ALM register value */
            RTC_REG_ADDR32_WRITE(RTC0_BASE_ADDR32 + RTC_ALM_OFFSET32, Rtc_Info.TargetCompareValue);
        }
        /* Update flag bit */
        RTC_REG_ADDR32_WRITE(RTC0_BASE_ADDR32 + RTC_INTF_OFFSET32, 0U);
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_23();
        /* Call Notifacation function */
        if (TRUE == Rtc_Info.IsNotificationEnabled)
        {
            if (NULL_PTR != Rtc_Info.NotificationPtr)
            {
                Rtc_Info.NotificationPtr();
            }
        }
    }
    else
    {
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_23();
    }
}

/**
 * @brief       This function returns the elapsed time.
 * @return      Rtc_ValueType Elapsed time.
 */
GPT_FUNC Rtc_ValueType Gpt_Lld_Rtc_GetTimeElapsed(void)
{
    Rtc_ValueType ElapsedValue = 0U;
    Rtc_ValueType CurrentTimeStamp=0U;
    switch (Rtc_Info.State)
    {
    case RTC_STATE_RUNNING:
        /* Get current time stamp */
        CurrentTimeStamp = RTC_REG_ADDR32_READ(RTC0_BASE_ADDR32 + RTC_SEC_OFFSET32);
        ElapsedValue = Rtc_Info.PeriodTickValue - (Rtc_Info.TargetCompareValue - CurrentTimeStamp);
        break;
    case RTC_STATE_STOPPED:
        ElapsedValue = Rtc_Info.StopValue - (Rtc_Info.TargetCompareValue - Rtc_Info.PeriodTickValue);
        break;
    case RTC_STATE_EXPIRED:
        ElapsedValue = Rtc_Info.PeriodTickValue;
        break;
    default:
        /* Nothing to do */
        break;
    }
    return ElapsedValue;
}

/**
 * @brief       This function returns the remaining time.
 * @return      Rtc_ValueType Remaining time.
 */
GPT_FUNC Rtc_ValueType Gpt_Lld_Rtc_GetTimeRemaining(void)
{
    Rtc_ValueType RemainingValue = 0U;
    Rtc_ValueType CurrentTimeStamp = 0U;
    switch (Rtc_Info.State)
    {
    case RTC_STATE_RUNNING:
        /* Get current time stamp */
        CurrentTimeStamp = RTC_REG_ADDR32_READ(RTC0_BASE_ADDR32 + RTC_SEC_OFFSET32);
        RemainingValue = Rtc_Info.TargetCompareValue - CurrentTimeStamp;
        break;
    case RTC_STATE_STOPPED:
        RemainingValue = Rtc_Info.TargetCompareValue - Rtc_Info.StopValue;
        break;
    case RTC_STATE_EXPIRED:
        RemainingValue = 0U;
        break;
    default:
        /* Nothing to do */
        break;
    }
    return RemainingValue;
}

/**
 * @brief       This function returns the RTC state.
 * @return      Rtc_StatesType
 */
GPT_FUNC Rtc_StatesType Gpt_Lld_Rtc_GetTimerState(void)
{
    return Rtc_Info.State;
}

/**
 * @brief       This function enables the RTC notification.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Rtc_EnableNotification(void)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_24();
    Rtc_Info.IsNotificationEnabled = TRUE;
    /* Enable Alarm interrupt */
    RTC_REG_ADDR32_SET_BITS(RTC0_BASE_ADDR32 + RTC_INTE_OFFSET32, RTC_INTE_ALMIE_MASK);
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_24();
}

/**
 * @brief       This function disables the RTC notification.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Rtc_DisableNotification(void)
{
    if((GPT_MODE_NORMAL == Gpt_Mode)||((GPT_MODE_SLEEP == Gpt_Mode)&&(FALSE == Rtc_Info.IsWakeupEnabled)))
    {
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_25();
        /* Save notification disable attribute */
        Rtc_Info.IsNotificationEnabled = FALSE;
        /* Disable interrupt
        Condition:
                1. Continuous mode
                2. OneShot mode: timer state is not running */
        if ((RTC_MODE_CONTINUOUS == Rtc_Info.CountMode) ||
                (RTC_STATE_RUNNING != Rtc_Info.State))
        {
            RTC_REG_ADDR32_CLEAR_BITS(RTC0_BASE_ADDR32 + RTC_INTE_OFFSET32, RTC_INTE_ALMIE_MASK);
        }
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_25();
    }
}

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
 * @brief       This function enables the RTC wakeup.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Rtc_EnableWakeup(void)
{
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_26();
    RTC_REG_ADDR32_INDEX_SET_BIT(WKU_BASE_ADDR32 + WKU_MER_OFFSET32, 0U);
    Rtc_Info.IsWakeupEnabled = TRUE;
    Gpt_Lld_Rtc_EnableNotification();
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_26();
#endif /* GPT_REPORT_WAKEUP_SOURCE */
}

/**
 * @brief       This function disables the RTC wakeup.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Rtc_DisableWakeup(void)
{
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_27();
    RTC_REG_ADDR32_INDEX_CLEAR_BIT(WKU_BASE_ADDR32 + WKU_MER_OFFSET32, 0U);
    Rtc_Info.IsWakeupEnabled = FALSE;
    if(GPT_MODE_SLEEP == Gpt_Mode)
    {
        Gpt_Lld_Rtc_DisableNotification();
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_27();
#endif /* GPT_REPORT_WAKEUP_SOURCE */
}

/**
 * @brief       This function sets the operation mode of the RTC.
 * @param[in]   Mode GPT_MODE_NORMAL: Normal operation mode of the GPT driver.
 *                   GPT_MODE_SLEEP: Sleep mode of the GPT driver (wakeup capable).
 *                   See also Gpt_ModeType.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Rtc_SetMode(Gpt_ModeType Mode)
{
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    if(GPT_MODE_SLEEP == Mode)
    {
        if((Rtc_Info.State == RTC_STATE_RUNNING)&&(FALSE == Rtc_Info.IsWakeupEnabled))
        {
            Gpt_Lld_Rtc_StopTimer();
            /* Clear Alarm Interrupt flag */
            RTC_REG_ADDR32_WRITE(RTC0_BASE_ADDR32 + RTC_ALM_OFFSET32, 0U);
        }
    }
#endif /* GPT_REPORT_WAKEUP_SOURCE */
}

/**
 * @brief       This function checks whether RTC is the source for a wakeup event.
 * @param[in]   EcuM_WakeupSourceType WakeupSource
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Rtc_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
{
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_28();
    if((WakeupSource == Rtc_Info.WakeupSource)&&(TRUE == Rtc_Info.IsWakeupGenerated))
    {
        /*GCOVR_EXCL_START: Testing the wake up function requires the MCU to be set to a non-general mode,
        but in the integration test, it is necessary to ensure that the chip can run normally.
        Therefore, the wake up function has been excluded from coverage testing.*/
        /* Reset the wakeup flag */
        Rtc_Info.IsWakeupGenerated = FALSE;
        /* Calling EcuM_SetWakeupEvent*/
        EcuM_SetWakeupEvent(WakeupSource);
        /*GCOVR_EXCL_STOP*/
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_28();
#endif /* GPT_REPORT_WAKEUP_SOURCE */
}
#endif /* GPT_WAKEUP_FUNCTIONALITY_API */

/**
 * @brief       This function gets the RTC hardware instance configuration.
 * @param[in]   Instance The RTC instance id
 * @param[in]   Cfg The pointer to the configuration structure.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Rtc_GetCfg(uint8 Instance, Rtc_ConfigType * const Cfg)
{
    uint8 Tmp = 0U;
    volatile uint32 Reg = 0U;
    RTC_Type const volatile * Base = Rtc_Lld_Base[Instance];

    Reg = Base->CTRL;
    Tmp = (uint8)((Reg & RTC_CTRL_CLKSEL_MASK) >> RTC_CTRL_CLKSEL_SHIFT);
    Cfg->ClockSource = (Rtc_ClockSourceType)Tmp;
    Cfg->CountMode = Rtc_Info.CountMode;
    Cfg->EnableNotification = Rtc_Info.IsNotificationEnabled;
    Cfg->NotificationPtr = Rtc_Info.NotificationPtr;
    Tmp = (uint8)((Reg & RTC_CTRL_DBGDIS_MASK) >> RTC_CTRL_DBGDIS_SHIFT);
    Cfg->StopInDebugMode = (boolean)Tmp;
}

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

