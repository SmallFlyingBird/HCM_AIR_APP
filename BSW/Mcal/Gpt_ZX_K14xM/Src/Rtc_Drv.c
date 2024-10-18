/**************************************************************************************************/
/**
 * @file      : Rtc_Drv.c
 * @brief     : Rtc module source file
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

/** @addtogroup Rtc_Drv
 *  @brief Gpt low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Device_Regs.h"
#include "Rtc_Drv.h"
#include "SchM_Gpt.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
/* Published information */
#define RTC_DRV_C_VENDOR_ID                   0x00B3U
#define RTC_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define RTC_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define RTC_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define RTC_DRV_C_SW_MAJOR_VERSION            1U
#define RTC_DRV_C_SW_MINOR_VERSION            2U
#define RTC_DRV_C_SW_PATCH_VERSION            1U

/* Check if current file and Rtc_Drv header file are of the same vendor */
#if (RTC_DRV_C_VENDOR_ID != RTC_DRV_H_VENDOR_ID)
    #error "Vendor ID of Rtc_Drv.c and Rtc_Drv.h are different"
#endif
/* Check if current file and Rtc_Drv header file are of the same Autosar version */
#if ((RTC_DRV_C_AR_RELEASE_MAJOR_VERSION != RTC_DRV_H_AR_RELEASE_MAJOR_VERSION) ||                 \
     (RTC_DRV_C_AR_RELEASE_MINOR_VERSION != RTC_DRV_H_AR_RELEASE_MINOR_VERSION) ||                 \
     (RTC_DRV_C_AR_RELEASE_REVISION_VERSION != RTC_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Rtc_Drv.c and Rtc_Drv.h are different"
#endif
/* Check if current file and Rtc_Drv header file are of the same Software version */
#if ((RTC_DRV_C_SW_MAJOR_VERSION != RTC_DRV_H_SW_MAJOR_VERSION) ||                                 \
     (RTC_DRV_C_SW_MINOR_VERSION != RTC_DRV_H_SW_MINOR_VERSION) ||                                 \
     (RTC_DRV_C_SW_PATCH_VERSION != RTC_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Rtc_Drv.c and Rtc_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Device_Regs.h are the same Autosar version */
    #if ((RTC_DRV_C_AR_RELEASE_MAJOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) ||         \
         (RTC_DRV_C_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Rtc_Drv.c and Device_Regs.h are different"
    #endif

    /* Check if current file and SchM_Gpt.h are the same Autosar version */
    #if ((RTC_DRV_C_AR_RELEASE_MAJOR_VERSION != SCHM_GPT_H_AR_RELEASE_MAJOR_VERSION) ||            \
         (RTC_DRV_C_AR_RELEASE_MINOR_VERSION != SCHM_GPT_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Rtc_Drv.c and SchM_Gpt.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/** @} end of Private_MacroDefinition */
#if (RTC_DRV_ENABLE == STD_ON)

/** @defgroup Private_TypeDefinition
 *  @{
 */
/** @} end of group Private_TypeDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */
#define GPT_START_SEC_CONST_8
#include "Gpt_MemMap.h"
/**
 *  @brief Table of monthly day lengths in the Leap-year
 */
static const uint8 LeapYear[] = {0U, 31U, 29U, 31U, 30U, 31U, 30U, 31U, 31U, 30U, 31U, 30U, 31U};
/**
 *  @brief Table of monthly day lengths in leap years
 */
static const uint8 UnLeapYear[] = {0U, 31U, 28U, 31U, 30U, 31U, 30U, 31U, 31U, 30U, 31U, 30U, 31U};

#define GPT_STOP_SEC_CONST_8
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CONST_16
#include "Gpt_MemMap.h"
/**
 *  @brief Table of month length (in days) for the non Leap-year
 */
static const uint16 MonthDays[] = {0U, 0U, 31U, 59U, 90U, 120U, 151U,
                                   181U, 212U, 243U, 273U, 304U, 334U};

#define GPT_STOP_SEC_CONST_16
#include "Gpt_MemMap.h"

/** @} end of group Private_VariableDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */
#define GPT_START_SEC_VAR_INIT_32
#include "Gpt_MemMap.h"
/**
 * @brief  Rtc target time value.
 */
uint32 Rtc_Drv_TargetValue = 0U;

#define GPT_STOP_SEC_VAR_INIT_32
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CONST_PTR
#include "Gpt_MemMap.h"
/**
 *  @brief Rtc instance address array
 */
/* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer object, 
no side effects forseen by violating this rule.*/
static Reg_Rtc_BfType *const Rtc_Drv_RtcRegBfPtr[RTC_DRV_INSTANCE_COUNT] = 
{
    (Reg_Rtc_BfType *)RTC_BASE_ADDR
};

/* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer object, 
no side effects forseen by violating this rule.*/
static Reg_Rtc_WType *const Rtc_Drv_RtcRegWPtr[RTC_DRV_INSTANCE_COUNT] = 
{
    (Reg_Rtc_WType *)RTC_BASE_ADDR
};
/**
 *  @brief Power Management Unit Register
 */
/* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer object, 
no side effects forseen by violating this rule.*/
static Reg_Pmu_BfType *const Rtc_Drv_PmuRegBfPtr = (Reg_Pmu_BfType *)PMU_BASE_ADDR;

#define GPT_STOP_SEC_CONST_PTR
#include "Gpt_MemMap.h"

#define GPT_START_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"
/**
 *  @brief Set the interrupt channel status.
 */
static Rtc_Drv_StateType Rtc_Drv_ChannelState[RTC_DRV_INSTANCE_COUNT] = {
    {RTC_DRV_INT_ALARM,(boolean)FALSE, 0U, 0U, (boolean)FALSE, (boolean)FALSE, NULL_PTR, 0U,
    (boolean)FALSE,(boolean)FALSE, NULL_PTR, 0U}
};
#define GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CONST_32
#include "Gpt_MemMap.h"
/**
 *  @brief Rtc interrupt mask table
 */
static const uint32 Rtc_Drv_InterruptMaskTable[] = {
    0x00000008U, /*!< RTC overflow interrupt */
    0x00000010U, /*!< RTC alarm interrupt  */
    0x00000020U, /*!< RTC second interrupt */
    0x00000040U, /*!< RTC period interrupt */
    0x00000078U  /*!< RTC_DRV_INT_ALL */
};

/**
 *  @brief Rtc instatus table
 */
static const uint32 Rtc_Drv_IntStatusTable[] = {
    0x00000080U, /*!< RTC overflow interrupt */
    0x00000100U, /*!< RTC alarm interrupt  */
    0x00000800U, /*!< RTC second interrupt */
    0x00002000U, /*!< RTC period interrupt */
    0x00002980U  /*!< RTC_DRV_INT_ALL */
};

#define GPT_STOP_SEC_CONST_32
#include "Gpt_MemMap.h"

/** @} end of group Global_VariableDefinition */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

#if (RTC_DRV_ISR_ENABLE == STD_ON)
ISR(Rtc_Drv_AlarmIrqHandler);
ISR(Rtc_Drv_SecondIrqHandler);
#endif

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"
/** @} end of group Public_FunctionDeclaration */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

#if (RTC_DRV_ISR_ENABLE == STD_ON)
static void Rtc_Drv_AlarmIntHandler(uint8 Instance);
#endif
LOCAL_INLINE void Rtc_Drv_SetAlarmTime(uint8 Instance, uint32 Value);
LOCAL_INLINE void Rtc_Drv_SetAlarmMatchTime(uint8 Instance, uint32 MatchValue);
LOCAL_INLINE void Rtc_Drv_EnableInt(uint8 Instance, Rtc_Drv_InterruptType IntType, boolean Enable);
LOCAL_INLINE void Rtc_Drv_ClearIntStatus(uint8 Instance, Rtc_Drv_InterruptType InterruptType);
LOCAL_INLINE void Rtc_Drv_SWReset(uint8 Instance);
LOCAL_INLINE void Rtc_Drv_EnableCounter(uint8 Instance, boolean Enable);
LOCAL_INLINE boolean Rtc_Drv_CheckCounterEnable(uint8 Instance);
LOCAL_INLINE Std_ReturnType Rtc_Drv_WaitOSC32KReady(uint8 Instance);
LOCAL_INLINE Std_ReturnType Rtc_Drv_ConfigClock(uint8 Instance,
                                                Rtc_Drv_ClockSourceType ClockSource);
LOCAL_INLINE void Rtc_Drv_SelectClockOut(uint8 Instance, Rtc_Drv_ClockOutType ClockOut);
#if (defined(RTC_DRV_ENABLE_COMPENSATION_SUPPORT) &&                                 \
         (RTC_DRV_ENABLE_COMPENSATION_SUPPORT == STD_ON))
LOCAL_INLINE void Rtc_Drv_SetCompensationDelayValue(uint8 Instance, uint8 DelayVal);
LOCAL_INLINE void Rtc_Drv_SetCompensationValue(uint8 Instance, uint8 Value);
LOCAL_INLINE void Rtc_Drv_SetCompDirection(uint8 Instance, Rtc_Drv_CompDirectionType FreqComp);
#endif
static boolean Rtc_Drv_CheckYearLeap(uint16 Year);
static boolean Rtc_Drv_CheckTimeDataRange(const Rtc_Drv_TimedateType *TimeDatePtr);
static boolean Rtc_Drv_CheckTimeDateFormat(const Rtc_Drv_TimedateType *TimeDatePtr);
#if (STD_ON == RTC_DRV_ENABLE_USER_MODE_SUPPORT)
LOCAL_INLINE void Rtc_Drv_EnableNonSupervisorAccess(uint8 Instance);
#endif
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
/**
 * @brief       Set rtc counter then counter will count from this value.
 *              Note: This value can be written when rtc is disable only and at the same time,
 *              written this register can clear overflow flag
 *
 * @param[in]   Instance: RTC peripheral instance number
 * @param[in]   Value: Set start value
 *
 * @return      None
 */
LOCAL_INLINE void Rtc_Drv_SetAlarmTime(uint8 Instance, uint32 Value)
{
    Reg_Rtc_BfType *RTCx = Rtc_Drv_RtcRegBfPtr[Instance];
    Reg_Rtc_WType  *RTCxw = Rtc_Drv_RtcRegWPtr[Instance];

    if (RTCx->RTC_LOCKR.LOCK != (uint32)0U)
    {
        RTCxw->RTC_LOCKR = 0x98670000U;
    }

    if(RTC_DRV_INT_ALARM == Rtc_Drv_ChannelState[Instance].ModeSelect)
    {
        RTCxw->RTC_ALARM_CNTR = Value;
    }
    else
    {
        RTCxw->RTC_PERIODIC_TMR_CNT = Value;
    }

    RTCx->RTC_LOCKR.LOCK = 0x1U;
}

/**
 * @brief       This function sets rtc march counter and also can clear counter interrupt, it can be
 *              written when rtc is enable.
 *
 * @param[in]   Instance:  RTC peripheral instance number
 * @param[in]   MatchValue:Set the match value
 *
 * @return      None
 */
LOCAL_INLINE void Rtc_Drv_SetAlarmMatchTime(uint8 Instance, uint32 MatchValue)
{
    Reg_Rtc_BfType *RTCx = Rtc_Drv_RtcRegBfPtr[Instance];
    Reg_Rtc_WType  *RTCxw = Rtc_Drv_RtcRegWPtr[Instance];

    if (RTCx->RTC_LOCKR.LOCK != (uint32)0U)
    {
        RTCxw->RTC_LOCKR = 0x98670000U;
    }

    if(RTC_DRV_INT_ALARM == Rtc_Drv_ChannelState[Instance].ModeSelect)
    {
        RTCxw->RTC_MATCH_CNTR = MatchValue;
    }
    else
    {
        RTCxw->RTC_PERIODIC_TMR_MATCH_CNT = MatchValue;
    }

    RTCx->RTC_LOCKR.LOCK = 0x1U;
}

/**
 * @brief       Mask/Unmask the RTC interrupt.
 *
 * @param[in]   Instance:  RTC peripheral instance number
 * @param[in]   IntType: Select interrupt
 *              - RTC_DRV_INT_OVERFLOW
 *              - RTC_DRV_INT_ALARM
 *              - RTC_DRV_INT_SECOND
 *              - RTC_DRV_INT_PERIODIC
 *              - RTC_DRV_INT_ALL
 * @param[in]   Enable: Enable/Disable interrupt
 *
 * @return      None
 */
LOCAL_INLINE void Rtc_Drv_EnableInt(uint8 Instance, Rtc_Drv_InterruptType IntType, boolean Enable)
{
    Reg_Rtc_BfType *RTCx = Rtc_Drv_RtcRegBfPtr[Instance];
    Reg_Rtc_WType  *RTCxw = Rtc_Drv_RtcRegWPtr[Instance];

    SchM_Enter_Gpt_RtcEnableInt();
    if (RTCx->RTC_LOCKR.LOCK != (uint32)0U)
    {
        RTCxw->RTC_LOCKR = 0x98670000U;
    }

    if (TRUE == Enable)
    {
        RTCxw->RTC_IER |= Rtc_Drv_InterruptMaskTable[IntType];
    }
    else
    {
        RTCxw->RTC_IER &= (~(Rtc_Drv_InterruptMaskTable[IntType]));
    }

    RTCx->RTC_LOCKR.LOCK = 0x1U;
    SchM_Exit_Gpt_RtcEnableInt();
}

/**
 * @brief       Clear RTC interrupt status.
 *              Note:Clear RTC overflow flag via writting 0 to one second counter, it can be written
 *              only when rtc counter is disable,reset match counter to clear alarm int status.
 *
 * @param[in]   Instance:  RTC peripheral instance number
 * @param[in]   InterruptType: Select interrupt
 *              - RTC_DRV_INT_OVERFLOW
 *              - RTC_DRV_INT_ALARM
 *              - RTC_DRV_INT_SECOND
 *              - RTC_DRV_INT_PERIODIC
 *              - RTC_DRV_INT_ALL
 *
 * @return      None
 */
LOCAL_INLINE void Rtc_Drv_ClearIntStatus(uint8 Instance, Rtc_Drv_InterruptType InterruptType)
{
    Reg_Rtc_BfType *RTCx = Rtc_Drv_RtcRegBfPtr[Instance];
    Reg_Rtc_WType  *RTCxw = Rtc_Drv_RtcRegWPtr[Instance];

    SchM_Enter_Gpt_RtcClearIntStatus();
    if (RTCx->RTC_LOCKR.LOCK != (uint32)0U)
    {
        RTCxw->RTC_LOCKR = 0x98670000U;
    }

    switch (InterruptType)
    {
        case RTC_DRV_INT_OVERFLOW:
            RTCx->RTC_ONE_SECOND_CNTR.ONE_SECOND_CNT = 0U;
            break;

        case RTC_DRV_INT_ALARM:
            RTCxw->RTC_MATCH_CNTR = 0xFFFFFFFFU;
            break;

        case RTC_DRV_INT_SECOND:
            RTCx->RTC_CSR.SECONDS_INT_FLAG = 0x1U;
            break;

        case RTC_DRV_INT_PERIODIC:
            RTCx->RTC_CSR.PERIODIC_MATCH_FLG = 0x1U;
            break;

        case RTC_DRV_INT_ALL:
            RTCx->RTC_ONE_SECOND_CNTR.ONE_SECOND_CNT = 0U;
            RTCxw->RTC_MATCH_CNTR = 0xFFFFFFFFU;
            RTCx->RTC_CSR.SECONDS_INT_FLAG = 0x1U;
            RTCx->RTC_CSR.PERIODIC_MATCH_FLG = 0x1U;
            break;

        default:
            /* Do nothing */
            break;
    }

    RTCx->RTC_LOCKR.LOCK = 0x1U;
    SchM_Exit_Gpt_RtcClearIntStatus();
}

/**
 * @brief       Software reset all rtc registers except sw_rst bit.
 *
 * @param[in]   Instance:  RTC peripheral Instance number
 *
 * @return      None
 */
LOCAL_INLINE void Rtc_Drv_SWReset(uint8 Instance)
{
    Reg_Rtc_BfType *RTCx = Rtc_Drv_RtcRegBfPtr[Instance];
    Reg_Rtc_WType  *RTCxw = Rtc_Drv_RtcRegWPtr[Instance];

    if (RTCx->RTC_LOCKR.LOCK != (uint32)0U)
    {
        RTCxw->RTC_LOCKR = 0x98670000U;
    }
    RTCx->RTC_CSR.SW_RST = 1U;
    RTCx->RTC_CSR.SW_RST = 0U;
    RTCx->RTC_LOCKR.LOCK = 0x1U;
}

/**
 * @brief       Enable/Disable RTC functioin
 *
 * @param[in]   Instance:  RTC peripheral instance number
 * @param[in]   Enable:  Enable/Disable RTC
 *
 * @return      None
 */
LOCAL_INLINE void Rtc_Drv_EnableCounter(uint8 Instance, boolean Enable)
{
    Reg_Rtc_BfType *RTCx = Rtc_Drv_RtcRegBfPtr[Instance];
    Reg_Rtc_WType  *RTCxw = Rtc_Drv_RtcRegWPtr[Instance];

    SchM_Enter_Gpt_RtcEnableCounter();
    if (RTCx->RTC_LOCKR.LOCK != (uint32)0U)
    {
        RTCxw->RTC_LOCKR = 0x98670000U;
    }

    if (FALSE == Enable)
    {
        /* Disable counter */
        RTCx->RTC_CSR.COUNT_EN = 0U;
        if(RTC_DRV_INT_PERIODIC == Rtc_Drv_ChannelState[Instance].ModeSelect)
        {
            RTCx->RTC_CSR.PERIODIC_CNT_EN = 0U;
        }
    }
    else
    {
        /* Enable counter */
        RTCx->RTC_CSR.COUNT_EN = 1U;
        if(RTC_DRV_INT_PERIODIC == Rtc_Drv_ChannelState[Instance].ModeSelect)
        {
            RTCx->RTC_CSR.PERIODIC_CNT_EN = 1U;
        }
    }
    RTCx->RTC_LOCKR.LOCK = 0x1U;
    SchM_Exit_Gpt_RtcEnableCounter();
}

/**
 * @brief       Check if rtc counter is enabled
 *
 * @param[in]   Instance:  RTC peripheral instance number
 *
 * @return      boolean
 * @retval      TRUE: Rtc counter has enabled.
 * @retval      FALSE: Rtc counter has not enabled.
 */
LOCAL_INLINE boolean Rtc_Drv_CheckCounterEnable(uint8 Instance)
{
    Reg_Rtc_BfType *RTCx = Rtc_Drv_RtcRegBfPtr[Instance];
    Reg_Rtc_WType  *RTCxw = Rtc_Drv_RtcRegWPtr[Instance];

    if (RTCx->RTC_LOCKR.LOCK != (uint32)0U)
    {
        RTCxw->RTC_LOCKR = 0x98670000U;
    }

    boolean EnableStatus;

    if(RTC_DRV_INT_ALARM == Rtc_Drv_ChannelState[Instance].ModeSelect)
    {
        /* check if counter is enabled */
        EnableStatus = ((RTCx->RTC_CSR.COUNT_EN != 0U) ? TRUE : FALSE);
    }
    else
    {
        /* check if counter is enabled */
        EnableStatus = ((RTCx->RTC_CSR.COUNT_EN != 0U) ? TRUE : FALSE);
        EnableStatus = (((EnableStatus & RTCx->RTC_CSR.PERIODIC_CNT_EN) != 0U) ? TRUE : FALSE);

    }

    RTCx->RTC_LOCKR.LOCK = 0x1U;

    return EnableStatus;
}

/**
 * @brief       Wait the clock source status until it is ready
 *
 * @param[in]   Instance:  RTC peripheral instance number
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      OSC32K is ready
 * @retval     E_NOT_OK:  OSC32K is not ready
 */
LOCAL_INLINE Std_ReturnType Rtc_Drv_WaitOSC32KReady(uint8 Instance)
{
    const Reg_Rtc_BfType *RTCx = Rtc_Drv_RtcRegBfPtr[Instance];

    Std_ReturnType  Ret = E_NOT_OK;
    uint32 CurrentTicks = 0U;      /* initialize current counter */
    uint32 ElapsedTicks = 0U;      /* elapse elapsed time */
    uint32 TotalElapsedTicks = 0U; /* total elapsed time*/
    
    (void)McalLib_GetCounterValue(RTC_DRV_TIMEOUT_TYPE, &CurrentTicks);
    uint32 TimeoutTicks = McalLib_MicroSecToTicks(RTC_DRV_TIMEOUT_TYPE, RTC_DRV_TIMEOUT_VALUE);
    
    while (TotalElapsedTicks <= TimeoutTicks)
    {
        if (RTCx->RTC_CSR.OSC_RDY != (uint32)0U)
        {
            Ret = E_OK;
            break;
        }
        (void)McalLib_GetElapsedValue(RTC_DRV_TIMEOUT_TYPE, &CurrentTicks, &ElapsedTicks);
        TotalElapsedTicks += ElapsedTicks;
    }
    return Ret;
}

/**
 * @brief       Enable RTC output clock
 *
 * @param[in]   Instance:  RTC peripheral instance number
 * @param[in]   ClockOut:  RTC output clock type
 *                          - RTC_DRV_SECONDS
 *                          - RTC_DRV_32K_CLK
 *
 * @return     None
 */
LOCAL_INLINE void Rtc_Drv_SelectClockOut(uint8 Instance, Rtc_Drv_ClockOutType ClockOut)
{
    Reg_Rtc_BfType *RTCx = Rtc_Drv_RtcRegBfPtr[Instance];
    Reg_Rtc_WType  *RTCxw = Rtc_Drv_RtcRegWPtr[Instance];

    SchM_Enter_Gpt_RtcSelectClockOut();
    if (RTCx->RTC_LOCKR.LOCK != (uint32)0U)
    {
        RTCxw->RTC_LOCKR = 0x98670000U;
    }
    RTCx->RTC_CSR.CLKOUT_SEL = (uint32)ClockOut;
    RTCx->RTC_CSR.CLKOUT_PIN_EN = 0x1U;
    RTCx->RTC_LOCKR.LOCK = 0x1U;
    SchM_Exit_Gpt_RtcSelectClockOut();
}

/**
 * @brief       Select clock source
 *
 * @param[in]   Instance:  RTC peripheral instance number
 * @param[in]   ClockSource:  RTC source type
 *                          - RTC_DRV_CLK_OSC32K_INT
 *                          - RTC_DRV_CLK_OSC32K_EXT
 *                          - RTC_DRV_CLK_LPO32K
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      Clock source is selected
 * @retval     E_NOT_OK:  Clock source is not selected
 */
LOCAL_INLINE Std_ReturnType Rtc_Drv_ConfigClock(uint8 Instance, Rtc_Drv_ClockSourceType ClockSource)
{
    Reg_Rtc_BfType *RTCx = Rtc_Drv_RtcRegBfPtr[Instance];
    Reg_Rtc_WType  *RTCxw = Rtc_Drv_RtcRegWPtr[Instance];

    Std_ReturnType Ret = E_NOT_OK;

    if (RTCx->RTC_LOCKR.LOCK != (uint32)0U)
    {
        RTCxw->RTC_LOCKR = 0x98670000U;
    }

    if(ClockSource == RTC_DRV_CLK_OSC32K_INT)
    {
        RTCx->RTC_CSR.CNT_CLK_SEL = 0U;
        RTCx->RTC_CSR.CRYSTAL_EN = 1;
        if (E_OK == Rtc_Drv_WaitOSC32KReady(Instance))
        {
            Ret = E_OK;
        }
        else
        {
            Ret = E_NOT_OK;
        }
    }
    else if(ClockSource == RTC_DRV_CLK_OSC32K_EXT)
    {
        RTCx->RTC_CSR.CNT_CLK_SEL = 0U;
        RTCx->RTC_CSR.EXTAL_32K_EN = 1;
        if (E_OK == Rtc_Drv_WaitOSC32KReady(Instance))
        {
            Ret = E_OK;
        }
        else
        {
            Ret = E_NOT_OK;
        }
    }
    else if(ClockSource == RTC_DRV_CLK_LPO32K)
    {
        Rtc_Drv_PmuRegBfPtr->PMU_LPO_32K_CFG.LPO_CLK_DIS = 0U;
        RTCx->RTC_CSR.CNT_CLK_SEL = 1U;
        if (TRUE == Rtc_Drv_PmuRegBfPtr->PMU_LPO_32K_CFG.LPO_CLK_READY)
        {
            Ret = (uint8)RTC_DRV_SUCCESS;
        }
        else
        {
            Ret = (uint8)RTC_DRV_ERROR;
        }
    }
    else
    {
        /* Nothing to do */
    }

    RTCx->RTC_LOCKR.LOCK = 0x1U;
    return Ret;
}

#if (defined(RTC_DRV_ENABLE_COMPENSATION_SUPPORT) &&                                           \
         (RTC_DRV_ENABLE_COMPENSATION_SUPPORT == STD_ON))
/**
 * @brief       Set Compensation delay value
 *
 * @param[in]   Instance:  RTC peripheral instance number
 * @param[in]   DelayVal:  RTC Compensation delay value
 *
 * @return     None
 */
LOCAL_INLINE void Rtc_Drv_SetCompensationDelayValue(uint8 Instance, uint8 DelayVal)
{
    Reg_Rtc_BfType *RTCx = Rtc_Drv_RtcRegBfPtr[Instance];
    Reg_Rtc_WType  *RTCxw = Rtc_Drv_RtcRegWPtr[Instance];

    SchM_Enter_Gpt_RtcSetCompDelayValue();
    if (RTCx->RTC_LOCKR.LOCK != (uint32)0U)
    {
        RTCxw->RTC_LOCKR = 0x98670000U;
    }
    /* Set Compensation Interval */
    RTCx->RTC_COMPENSATIONR.DLY = DelayVal;

    RTCx->RTC_LOCKR.LOCK = 0x1U;
    SchM_Exit_Gpt_RtcSetCompDelayValue();
}

/**
 * @brief       Set Compensation counter value
 *
 * @param[in]   Instance:  RTC peripheral Instance number
 * @param[in]   Value:  RTC Compensation counter value
 *
 * @return     None
 */
LOCAL_INLINE void Rtc_Drv_SetCompensationValue(uint8 Instance, uint8 Value)
{
    Reg_Rtc_BfType *RTCx = Rtc_Drv_RtcRegBfPtr[Instance];
    Reg_Rtc_WType  *RTCxw = Rtc_Drv_RtcRegWPtr[Instance];

    SchM_Enter_Gpt_RtcSetCompensationValue();
    if (RTCx->RTC_LOCKR.LOCK != (uint32)0U)
    {
        RTCxw->RTC_LOCKR = 0x98670000U;
    }

    /* Set Compensation value */
    RTCx->RTC_COMPENSATIONR.COMP_CNT = Value;

    RTCx->RTC_LOCKR.LOCK = 0x1U;
    SchM_Exit_Gpt_RtcSetCompensationValue();
}

/**
 * @brief       Set frequency Compensation direction
 *
 * @param[in]   Instance:  RTC peripheral instance number
 * @param[in]   FreqComp:  RTC frequency Compensation direction type
 *                        - RTC_DRV_COMP_UP
 *                        - RTC_DRV_COMP_DOWN
 *
 * @return     None
 */
LOCAL_INLINE void Rtc_Drv_SetCompDirection(uint8 Instance, Rtc_Drv_CompDirectionType FreqComp)
{
    Reg_Rtc_BfType *RTCx = Rtc_Drv_RtcRegBfPtr[Instance];
    Reg_Rtc_WType  *RTCxw = Rtc_Drv_RtcRegWPtr[Instance];

    SchM_Enter_Gpt_RtcSetCompDirection();
    if (RTCx->RTC_LOCKR.LOCK != (uint32)0U)
    {
        RTCxw->RTC_LOCKR = 0x98670000U;
    }
    /* Set frequency Compensation direction */
    RTCx->RTC_COMPENSATIONR.COMP_DIRECTION = (uint32)FreqComp;

    RTCx->RTC_LOCKR.LOCK = 0x1U;
    SchM_Exit_Gpt_RtcSetCompDirection();
}
#endif

#if (STD_ON == RTC_DRV_ENABLE_USER_MODE_SUPPORT)
/**
 * @brief      This function configures write access to RTC in non-supervisor.
 *
 * @param[in]  Instance: RTC peripheral instance number
 *
 * @return     None
 */
LOCAL_INLINE void Rtc_Drv_EnableNonSupervisorAccess(uint8 Instance)
{
    Reg_Rtc_BfType *RTCx = Rtc_Drv_RtcRegBfPtr[Instance];
    Reg_Rtc_WType  *RTCxw = Rtc_Drv_RtcRegWPtr[Instance];

    if (RTCx->RTC_LOCKR.LOCK != 0U)
    {
        RTCxw->RTC_LOCKR = 0x98670000U;
    }
    /*Check Software Reset*/
    if (0U != RTCx->RTC_CSR.SW_RST)
    {
        /* Clear Software Reset*/
        RTCx->RTC_CSR.SW_RST = 0U;
    }
    /*Non-supervisor mode write accesses are supported.*/
    RTCx->RTC_CSR.SUP_EN = 0x1U;
    RTCx->RTC_LOCKR.LOCK = 0x1U;
}
#endif

#if (RTC_DRV_ISR_ENABLE == STD_ON)
/**
 * @brief      Rtc alarm interrupt handler.
 *
 * @param[in]  Instance: RTC peripheral instance number
 *
 * @return     None
 */
static void Rtc_Drv_AlarmIntHandler(uint8 Instance)
{
    uint32 CounterValue = 0U;
    uint32 NewAlarmMatchTime = 0U;

    NewAlarmMatchTime = Rtc_Drv_GetAlarmMatchCounter(Instance) + Rtc_Drv_TargetValue;
    Rtc_Drv_SetAlarmMatchTime(Instance, NewAlarmMatchTime);

    if ((TRUE == Rtc_Drv_ChannelState[Instance].ChannelInit) &&
        (NULL_PTR != Rtc_Drv_ChannelState[Instance].Callback))
    {
        Rtc_Drv_ChannelState[Instance].Callback(Rtc_Drv_ChannelState[Instance].CallbackParam);
    }
    else if ((FALSE != Rtc_Drv_ChannelState[Instance].AlarmInit) &&
             (TRUE == Rtc_Drv_ChannelState[Instance].AlarmIntEnable))
    {
        if ((0UL < Rtc_Drv_ChannelState[Instance].AlarmRepeatsNumber) ||
            (TRUE == Rtc_Drv_ChannelState[Instance].RepeatForever))
        {
            CounterValue = Rtc_Drv_GetAlarmCounter(Instance);
            NewAlarmMatchTime =
                CounterValue + (Rtc_Drv_ChannelState[Instance].AlarmRepetitionInterval - 1U);
            Rtc_Drv_SetAlarmMatchTime(Instance, NewAlarmMatchTime);
            Rtc_Drv_ChannelState[Instance].AlarmRepeatsNumber =
                (Rtc_Drv_ChannelState[Instance].RepeatForever == FALSE)
                    ? (Rtc_Drv_ChannelState[Instance].AlarmRepeatsNumber - 1UL)
                    : 0UL;
        }
        else
        {
            Rtc_Drv_ChannelState[Instance].IsAlarmMatchTimeNew = FALSE;
        }
        if (NULL_PTR != Rtc_Drv_ChannelState[Instance].AlarmCallback)
        {
            Rtc_Drv_ChannelState[Instance].AlarmCallback(
                Rtc_Drv_ChannelState[Instance].AlarmCallbackParams);
        }
        else
        {
            /* Nothing to do */
        }
    }
    else
    {
        /* Nothing to do */
    }
}

/**
 * @brief      Rtc interrupt handler.
 *
 * @param[in]  Instance: RTC peripheral instance number
 *
 * @return     None
 */
static void Rtc_Drv_IntHandler(uint8 Instance)
{
    Reg_Rtc_BfType *RTCx = Rtc_Drv_RtcRegBfPtr[Instance];
    Reg_Rtc_WType  *RTCxw = Rtc_Drv_RtcRegWPtr[Instance];

    uint32 AlarmInterruptEnable = 0U;
    uint32 OverflowInterruptEnable = 0U;
    uint32 SecondsInterruptEnable = 0U;
    uint32 PeriodicInterruptEnable = 0U;
    uint32 AlarmInterruptFlag = 0U;
    uint32 SecondInterruptFlag = 0U;
    uint32 PeriodInterruptFlag = 0U;
    uint32 OverflowInterruptFlag = 0U;

    AlarmInterruptFlag = Rtc_Drv_GetIntStatus(Instance, RTC_DRV_INT_ALARM);
    SecondInterruptFlag = Rtc_Drv_GetIntStatus(Instance, RTC_DRV_INT_SECOND);
    PeriodInterruptFlag = Rtc_Drv_GetIntStatus(Instance, RTC_DRV_INT_PERIODIC);
    OverflowInterruptFlag = Rtc_Drv_GetIntStatus(Instance, RTC_DRV_INT_OVERFLOW);
    AlarmInterruptEnable = RTCx->RTC_IER.ALARM_IE;
    SecondsInterruptEnable = RTCx->RTC_IER.SECONDS_IE;
    PeriodicInterruptEnable = RTCx->RTC_IER.PERIODIC_IE;
    OverflowInterruptEnable = RTCx->RTC_IER.OVFLOW_IE;

    if (RTCx->RTC_LOCKR.LOCK != (uint32)0U)
    {
        RTCxw->RTC_LOCKR = 0x98670000U;
    }
    /* Clear interrupt flags. */
    if(1U == AlarmInterruptFlag)
    {
        RTCxw->RTC_MATCH_CNTR = 0xFFFFFFFFU;
    }
    if(1U == SecondInterruptFlag)
    {
        RTCx->RTC_CSR.SECONDS_INT_FLAG = 0x1U;
    }
    if(1U == PeriodInterruptFlag)
    {
        RTCx->RTC_CSR.PERIODIC_MATCH_FLG = 0x1U;
    }
    RTCx->RTC_LOCKR.LOCK = 1U;
    /* Check if ALARM_MATCHF and ALARM_IE */
    if ((1U == AlarmInterruptFlag) && (1U == AlarmInterruptEnable))
    {
        Rtc_Drv_AlarmIntHandler(Instance);
    }
    else if (((1U == OverflowInterruptFlag) && (1U == OverflowInterruptEnable)) ||
             ((1U == SecondInterruptFlag) && (1U == SecondsInterruptEnable)))
    {
        /* Call Callback notification */
        if ((TRUE == Rtc_Drv_ChannelState[Instance].ChannelInit) &&
            (NULL_PTR != Rtc_Drv_ChannelState[Instance].Callback))
        {
            Rtc_Drv_ChannelState[Instance].Callback(Rtc_Drv_ChannelState[Instance].CallbackParam);
        }
        else
        {
            /* Nothing to do */
        }
    }
    else if((1U == PeriodInterruptFlag) && (1U == PeriodicInterruptEnable))
    {
        /* Call Callback notification */
        if ((TRUE == Rtc_Drv_ChannelState[Instance].ChannelInit) &&
            (NULL_PTR != Rtc_Drv_ChannelState[Instance].Callback))
        {
            Rtc_Drv_ChannelState[Instance].Callback(Rtc_Drv_ChannelState[Instance].CallbackParam);
        }
        else
        {
            /* Nothing to do */
        }
    }
    else
    {
        /* Nothing to do */
    }
}
#endif
/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

/**
 * @brief      This function reads the current rtc counter.
 *
 * @param[in]  Instance: RTC peripheral instance number
 *
 * @return     uint32
 */
uint32 Rtc_Drv_GetAlarmCounter(uint8 Instance)
{
    const Reg_Rtc_WType *RTCxw = Rtc_Drv_RtcRegWPtr[Instance];

    uint32 RtcCounter = 0U;

    if(RTC_DRV_INT_ALARM == Rtc_Drv_ChannelState[Instance].ModeSelect)
    {
        RtcCounter = RTCxw->RTC_ALARM_CNTR;
    }
    else
    {
        RtcCounter = RTCxw->RTC_PERIODIC_TMR_CNT;
    }

    return RtcCounter;
}

/**
 * @brief      This function gets rtc match counter
 *
 * @param[in]  Instance: RTC peripheral instance number
 *
 * @return     uint32
 */
uint32 Rtc_Drv_GetAlarmMatchCounter(uint8 Instance)
{
    const Reg_Rtc_WType *RTCxw = Rtc_Drv_RtcRegWPtr[Instance];

    uint32 RtcMatchCounter = 0U;
    if(RTC_DRV_INT_ALARM == Rtc_Drv_ChannelState[Instance].ModeSelect)
    {
        RtcMatchCounter = RTCxw->RTC_MATCH_CNTR;
    }
    else
    {
        RtcMatchCounter = RTCxw->RTC_PERIODIC_TMR_MATCH_CNT;
    }

    return RtcMatchCounter;
}

/**
 * @brief       Config second interrupt mux and need to configure this before
 *              enable second interrupt.
 *
 * @param[in]   Instance:  RTC peripheral instance number
 * @param[in]   MuxSel:  RTC second interrupt mux type
 *                        - RTC_DRV_SECOND_1
 *                        - RTC_DRV_SECOND_64
 *                        - RTC_DRV_SECOND_32
 *                        - RTC_DRV_SECOND_16
 *                        - RTC_DRV_SECOND_8
 *                        - RTC_DRV_SECOND_4
 *                        - RTC_DRV_SECOND_2
 *                        - RTC_DRV_SECOND_128
 *
 * @return     Rtc_Drv_StatusType
 * @retval     RTC_DRV_SUCCESS: Second interrupt mux configuration is SUCCESS
 * @retval     RTC_DRV_ERROR: Second interrupt mux configuration is ERROR
 */
Rtc_Drv_StatusType Rtc_Drv_ConfigSecondIntMux(uint8 Instance, Rtc_Drv_SecondIntMuxSelType MuxSel)
{
    Reg_Rtc_BfType *RTCx = Rtc_Drv_RtcRegBfPtr[Instance];
    Reg_Rtc_WType  *RTCxw = Rtc_Drv_RtcRegWPtr[Instance];

    Rtc_Drv_StatusType Status = RTC_DRV_ERROR;
    uint32             IntEnableStatus = 0U;
    SchM_Enter_Gpt_RtcConfigSecondIntMux();
    if (RTCx->RTC_LOCKR.LOCK != (uint32)0U)
    {
        RTCxw->RTC_LOCKR = 0x98670000U;
    }
    /* Check if rtc seconds interrupt enables */
    IntEnableStatus = ((uint32)RTCx->RTC_IER.SECONDS_IE);
    if (0U != IntEnableStatus)
    {
        Status = RTC_DRV_ERROR;
    }
    else
    {
        RTCx->RTC_IER.SECOND_INT_MUX_SEL = (uint32)MuxSel;
        Status = RTC_DRV_SUCCESS;
    }
    RTCx->RTC_LOCKR.LOCK = 1U;
    SchM_Exit_Gpt_RtcConfigSecondIntMux();
    return Status;
}

/**
 * @brief      This function gets RTC interrupt status.
 *
 * @param[in]  Instance: RTC peripheral instance number
 * @param[in]  InterruptType:  Rtc instance interrupt type
 *                             - RTC_DRV_INT_OVERFLOW
 *                             - RTC_DRV_INT_ALARM
 *                             - RTC_DRV_INT_SECOND
 *                             - RTC_DRV_INT_PERIODIC
 * @return     uint32
 * @retval     RTC interrupt status
 */
uint32 Rtc_Drv_GetIntStatus(uint8 Instance, Rtc_Drv_InterruptType InterruptType)
{
    const Reg_Rtc_WType *RTCxw = Rtc_Drv_RtcRegWPtr[Instance];

    uint32 BitStatus = 0U;
    if (InterruptType < RTC_DRV_INT_ALL)
    {
        BitStatus = (((RTCxw->RTC_CSR & Rtc_Drv_IntStatusTable[InterruptType]) != 0U) 
                                                                                   ? TRUE : FALSE);
    }
    else
    {
        /* nothing */
    }
    return BitStatus;
}

/**
 * @brief      This function initialize the RTC.
 *
 * @param[in]  Instance: RTC peripheral instance number
 * @param[in]  RtcConfigPtr:   Pointer to the specified RTC Unit configuration
 *
 * @return     None
 */
void Rtc_Drv_Init(uint8 Instance, const Rtc_Drv_ConfigType *RtcConfigPtr)
{
    Reg_Rtc_BfType *RTCx;
    Reg_Rtc_WType *RTCxw;
    Rtc_Drv_InterruptType InterruptMode;

#if (STD_ON == RTC_DRV_ENABLE_USER_MODE_SUPPORT)
    uint32 ModeSwiched;
#endif

#if STD_ON == RTC_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_START();
#endif

#if STD_ON == RTC_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT(RTC_DRV_INSTANCE_COUNT > Instance);
    MCALLIB_DEV_ASSERT(NULL_PTR != RtcConfigPtr);
#endif
     RTCx = Rtc_Drv_RtcRegBfPtr[Instance];
     RTCxw = Rtc_Drv_RtcRegWPtr[Instance];
     InterruptMode = RtcConfigPtr->ModeSelect;

#if (STD_ON == RTC_DRV_ENABLE_USER_MODE_SUPPORT)
    ModeSwiched = Sys_EnterPrivilegedMode();
    /* Enables RTC registers writing in User Mode */
    Rtc_Drv_EnableNonSupervisorAccess(Instance);
    if (1U == ModeSwiched)
    {
        (void)Sys_EnterNonPrivilegedMode();
    }
#endif

    if (RTCx->RTC_LOCKR.LOCK != (uint32)0U)
    {
        RTCxw->RTC_LOCKR = 0x98670000U;
    }

    switch(InterruptMode)
    {
        case RTC_DRV_INT_ALARM:
        {
        #if (defined(RTC_DRV_STANDBY_WAKEUP_SUPPORT) && (RTC_DRV_STANDBY_WAKEUP_SUPPORT == STD_ON))
            if (0U == RTCx->RTC_IER.ALARM_IE)
            {
        #endif
                Rtc_Drv_EnableCounter(Instance, FALSE);
                Rtc_Drv_EnableInt(Instance, RTC_DRV_INT_ALL, FALSE);

        #if (defined(RTC_DRV_STANDBY_WAKEUP_SUPPORT) && (RTC_DRV_STANDBY_WAKEUP_SUPPORT == STD_ON))
            }
        #endif
        }
        
            break;

        case RTC_DRV_INT_PERIODIC:
        {
        #if (defined(RTC_DRV_STANDBY_WAKEUP_SUPPORT) && (RTC_DRV_STANDBY_WAKEUP_SUPPORT == STD_ON))
            if (0U == RTCx->RTC_IER.PERIODIC_IE)
            {
        #endif
                Rtc_Drv_EnableCounter(Instance, FALSE);
                Rtc_Drv_EnableInt(Instance, RTC_DRV_INT_ALL, FALSE);

        #if (defined(RTC_DRV_STANDBY_WAKEUP_SUPPORT) && (RTC_DRV_STANDBY_WAKEUP_SUPPORT == STD_ON))
            }
        #endif
        }
            break;
        default:
            /* Do nothing */
            break;
    }

    RTCx->RTC_LOCKR.LOCK = 1U;

    (void)Rtc_Drv_ConfigClock(Instance, RtcConfigPtr->ClockSource);
    Rtc_Drv_SelectClockOut(Instance, RtcConfigPtr->ClockOutSelect);
#if (defined(RTC_DRV_ENABLE_COMPENSATION_SUPPORT) &&                                           \
         (RTC_DRV_ENABLE_COMPENSATION_SUPPORT == STD_ON))
    Rtc_Drv_SetCompensationDelayValue(Instance, RtcConfigPtr->CompensationInterval);
    Rtc_Drv_SetCompensationValue(Instance, RtcConfigPtr->Compensation);
    Rtc_Drv_SetCompDirection(Instance, RtcConfigPtr->CompensationDirection);
#endif
    Rtc_Drv_ChannelState[Instance].ModeSelect = InterruptMode;
    Rtc_Drv_ChannelState[Instance].ChannelInit = TRUE;
    Rtc_Drv_ChannelState[Instance].Callback = RtcConfigPtr->Callback;
    Rtc_Drv_ChannelState[Instance].CallbackParam = RtcConfigPtr->CallbackParam;
    Rtc_Drv_TargetValue = 0U;
#if STD_ON == RTC_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      This function de-initialize the RTC.
 *
 * @param[in]  Instance: RTC peripheral instance number
 *
 * @return     None
 */
void Rtc_Drv_DeInit(uint8 Instance)
{
#if STD_ON == RTC_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_START();
#endif

#if STD_ON == RTC_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT(RTC_DRV_INSTANCE_COUNT > Instance);
#endif
    Rtc_Drv_SWReset(Instance);
    Rtc_Drv_TargetValue = 0U;
#if STD_ON == RTC_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Stop the Rtc timer.
 *
 * @param[in]  Instance: RTC peripheral instance number
 *
 * @return     Rtc_Drv_StatusType
 * @retval     RTC_DRV_SUCCESS:  stop command has been accepted.
 * @retval     RTC_DRV_ERROR:    stop command has not been accepted.
 */
Rtc_Drv_StatusType Rtc_Drv_StopTimer(uint8 Instance)
{
    Rtc_Drv_StatusType Status = RTC_DRV_ERROR;
#if STD_ON == RTC_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_START();
#endif

#if STD_ON == RTC_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT(RTC_DRV_INSTANCE_COUNT > Instance);
#endif

    Rtc_Drv_EnableInt(Instance, RTC_DRV_INT_ALARM, FALSE);

    if (1U == Rtc_Drv_GetIntStatus(Instance, RTC_DRV_INT_ALARM))
    {
        Rtc_Drv_ClearIntStatus(Instance, RTC_DRV_INT_ALARM);
    }
    if (FALSE == Rtc_Drv_CheckCounterEnable(Instance))
    {
        Status = RTC_DRV_SUCCESS;
    }
    else
    {
        Rtc_Drv_EnableCounter(Instance, FALSE);
        Status = RTC_DRV_SUCCESS;
    }
#if STD_ON == RTC_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_END();
#endif
    return Status;
}

/**
 * @brief      Start the Rtc timer channel with a timeout value.
 *
 * @param[in]  Instance: RTC peripheral instance number
 * @param[in]  Value: RTC channel timeout value
 *
 * @return     None
 */
void Rtc_Drv_StartTimer(uint8 Instance, uint32 Value)
{
    uint32 CounterValue = 0U;
    Rtc_Drv_TargetValue = Value;
#if STD_ON == RTC_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_START();
#endif

#if STD_ON == RTC_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT(RTC_DRV_INSTANCE_COUNT > Instance);
#endif

    Rtc_Drv_EnableCounter(Instance, FALSE);
    Rtc_Drv_EnableInt(Instance, Rtc_Drv_ChannelState[Instance].ModeSelect, FALSE);
    
    if(RTC_DRV_INT_ALARM == Rtc_Drv_ChannelState[Instance].ModeSelect)
    {
        CounterValue = Rtc_Drv_GetAlarmCounter(Instance);
        CounterValue = CounterValue + Value;
    }
    else
    {
        Rtc_Drv_SetAlarmTime(Instance, 0U);
        CounterValue = Value;
    }

    Rtc_Drv_SetAlarmMatchTime(Instance, CounterValue);
    Rtc_Drv_EnableInt(Instance, Rtc_Drv_ChannelState[Instance].ModeSelect, TRUE);
    Rtc_Drv_EnableCounter(Instance, TRUE);

#if STD_ON == RTC_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Enable interrupt for RTC channel.
 *
 * @param[in]  Instance: RTC peripheral instance number
 * @param[in]  InterruptType: Rtc interrupt type
 *                           - RTC_DRV_INT_OVERFLOW
 *                           - RTC_DRV_INT_ALARM
 *                           - RTC_DRV_INT_SECOND
 *                           - RTC_DRV_INT_PERIODIC
 *                           - RTC_DRV_INT_ALL
 * @return     None
 */
void Rtc_Drv_EnableInterrupt(uint8 Instance, Rtc_Drv_InterruptType InterruptType)
{
#if STD_ON == RTC_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_START();
#endif

#if STD_ON == RTC_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT(RTC_DRV_INSTANCE_COUNT > Instance);
#endif

    if (InterruptType == RTC_DRV_INT_OVERFLOW)
    {
        Rtc_Drv_EnableInt(Instance, RTC_DRV_INT_OVERFLOW, TRUE);
    }
    else if (InterruptType == RTC_DRV_INT_ALARM)
    {
        if (0U != Rtc_Drv_GetIntStatus(Instance, RTC_DRV_INT_ALARM))
        {
            Rtc_Drv_ClearIntStatus(Instance, RTC_DRV_INT_ALARM);
        }
        Rtc_Drv_EnableInt(Instance, RTC_DRV_INT_ALARM, TRUE);
    }
    else if (InterruptType == RTC_DRV_INT_SECOND)
    {
        Rtc_Drv_EnableInt(Instance, RTC_DRV_INT_SECOND, TRUE);
    }
    else if(InterruptType == RTC_DRV_INT_PERIODIC)
    {
        Rtc_Drv_EnableInt(Instance, RTC_DRV_INT_PERIODIC, TRUE);
    }
    else if(InterruptType == RTC_DRV_INT_ALL)
    {
        Rtc_Drv_EnableInt(Instance, RTC_DRV_INT_ALL, TRUE);
    }
    else
    {
        /* Nothing to do */
    }
#if STD_ON == RTC_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Disable interrupt for RTC channel.
 *
 * @param[in]  Instance: RTC peripheral instance number
 * @param[in]  InterruptType: Rtc interrupt type
 *                           - RTC_DRV_INT_OVERFLOW
 *                           - RTC_DRV_INT_ALARM
 *                           - RTC_DRV_INT_SECOND
 *                           - RTC_DRV_INT_PERIODIC
 *                           - RTC_DRV_INT_ALL
 * @return     None
 */
void Rtc_Drv_DisableInterrupt(uint8 Instance, Rtc_Drv_InterruptType InterruptType)
{
#if STD_ON == RTC_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_START();
#endif

#if STD_ON == RTC_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT(RTC_DRV_INSTANCE_COUNT > Instance);
#endif

    if (InterruptType == RTC_DRV_INT_OVERFLOW)
    {
        Rtc_Drv_EnableInt(Instance, RTC_DRV_INT_OVERFLOW, FALSE);
    }
    else if (InterruptType == RTC_DRV_INT_ALARM)
    {
        Rtc_Drv_EnableInt(Instance, RTC_DRV_INT_ALARM, FALSE);
        Rtc_Drv_ClearIntStatus(Instance, RTC_DRV_INT_ALARM);
    }
    else if (InterruptType == RTC_DRV_INT_SECOND)
    {
        Rtc_Drv_EnableInt(Instance, RTC_DRV_INT_SECOND, FALSE);
    }
    else if(InterruptType == RTC_DRV_INT_PERIODIC)
    {
        Rtc_Drv_EnableInt(Instance, RTC_DRV_INT_PERIODIC, FALSE);
    }
    else if(InterruptType == RTC_DRV_INT_ALL)
    {
        Rtc_Drv_EnableInt(Instance, RTC_DRV_INT_ALL, FALSE);
    }
    else
    {
        /* Nothing to do */
    }
#if STD_ON == RTC_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      Check whether the time and data within the range.
 *
 * @param[in]  TimeDatePtr: Time date for rtc
 *
 * @return     boolean
 * @retval     TRUE: The configuration data within the range.
 * @retval     FALSE: The configuration data out of range.
 */
static boolean Rtc_Drv_CheckTimeDataRange(const Rtc_Drv_TimedateType *TimeDatePtr)
{
    boolean ReturnValue = FALSE;

    if ((TimeDatePtr->Year >= YEAR_RANGE_START) && (TimeDatePtr->Year <= YEAR_RANGE_END) &&
        (TimeDatePtr->Month >= 1U) && (TimeDatePtr->Month <= 12U) && (TimeDatePtr->Day >= 1U) &&
        (TimeDatePtr->Day <= 31U) && (TimeDatePtr->Hour < HOURS_IN_A_DAY) &&
        (TimeDatePtr->Minutes < MINS_IN_A_HOUR) && (TimeDatePtr->Seconds < SECONDS_IN_A_MIN))
    {
        ReturnValue = TRUE;
    }
    return ReturnValue;
}

/**
 * @brief      Check whether the time and data is correct.
 *
 * @param[in]  TimeDatePtr: Time date for rtc
 *
 * @return     boolean
 * @retval     TRUE: The configuration data in the structure is correct.
 * @retval     FALSE: The configuration data in the structure is not correct.
 */
static boolean Rtc_Drv_CheckTimeDateFormat(const Rtc_Drv_TimedateType *TimeDatePtr)
{
    boolean      ReturnValue;
    boolean      YearLeap;
    const uint8 *Days;

    YearLeap = Rtc_Drv_CheckYearLeap(TimeDatePtr->Year);
    Days = (TRUE == YearLeap)? (LeapYear) : (UnLeapYear);

    ReturnValue = Rtc_Drv_CheckTimeDataRange(TimeDatePtr);
    if (TimeDatePtr->Day > Days[TimeDatePtr->Month])
    {
        ReturnValue = FALSE;
    }
    else if (FALSE == ReturnValue)
    {
        ReturnValue = FALSE;
    }
    else
    {
        ReturnValue = TRUE;
    }
    return ReturnValue;
}

/**
 * @brief      Check if it is a leap year.
 *
 * @param[in]  Year:  year
 *
 * @return     boolean
 * @retval     TRUE: It is a leap year.
 * @retval     FALSE: It is not a leap year.
 */
static boolean Rtc_Drv_CheckYearLeap(uint16 Year)
{
    boolean ReturnValue;

    if (0U == (Year % 4U))
    {
        if (0U == (Year % 100U))
        {
            if (0U == (Year % 400U))
            {
                ReturnValue = TRUE;
            }
            else
            {
                ReturnValue = FALSE;
            }
        }
        else
        {
            ReturnValue = TRUE;
        }
    }
    else
    {
        ReturnValue = FALSE;
    }
    return ReturnValue;
}

/**
 * @brief      This function convert seconds into time-date format.
 *
 * @param[in]  Seconds:  Seconds
 * @param[in]  TimeDatePtr: Pointer to time-data configuration
 *
 * @return     None
 */
static void Rtc_Drv_SecondsToTimeDate(const uint32 *Seconds, Rtc_Drv_TimedateType *const TimeDatePtr)
{
    uint8   Index = 1U;
    boolean YearLeap;
    uint32  DaysNumber;
    uint32  RemainingSeconds;
    uint16  DaysInYear;
#if STD_ON == RTC_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_START();
#endif

#if STD_ON == RTC_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT(NULL_PTR != Seconds);
    MCALLIB_DEV_ASSERT(NULL_PTR != TimeDatePtr);
#endif

    DaysInYear = DAYS_IN_A_YEAR;
    TimeDatePtr->Year = YEAR_RANGE_START;
    DaysNumber = (*Seconds) / SECONDS_IN_A_DAY;
    RemainingSeconds = (*Seconds) % SECONDS_IN_A_DAY;
    TimeDatePtr->Hour = (uint16)(RemainingSeconds / SECONDS_IN_A_HOUR);
    RemainingSeconds = RemainingSeconds % SECONDS_IN_A_HOUR;
    TimeDatePtr->Minutes = (uint16)(RemainingSeconds / SECONDS_IN_A_MIN);
    TimeDatePtr->Seconds = (uint8)(RemainingSeconds % SECONDS_IN_A_MIN);

    while (DaysNumber >= DaysInYear)
    {
        TimeDatePtr->Year++;
        DaysNumber -= DaysInYear;

        if (TRUE == Rtc_Drv_CheckYearLeap(TimeDatePtr->Year))
        {
            DaysInYear = DAYS_IN_A_LEAP_YEAR;
        }
        else
        {
            DaysInYear = DAYS_IN_A_YEAR;
        }
    }

    DaysNumber += 1U;

    YearLeap = Rtc_Drv_CheckYearLeap(TimeDatePtr->Year);

    if (YearLeap == TRUE)
    {
        for (Index = 1U; Index <= 12U; Index++)
        {
            uint32 DaysInCurrentMonth = (uint32)LeapYear[Index];
            if (DaysNumber > DaysInCurrentMonth)
            {
                DaysNumber -= DaysInCurrentMonth;
            }
            else
            {
                TimeDatePtr->Month = (uint16)Index;
                break;
            }
        }
    }
    else
    {
        for (Index = 1U; Index <= 12U; Index++)
        {
            uint32 DaysInCurrentMonth = (uint32)UnLeapYear[Index];
            if (DaysNumber > DaysInCurrentMonth)
            {
                DaysNumber -= DaysInCurrentMonth;
            }
            else
            {
                TimeDatePtr->Month = (uint16)Index;
                break;
            }
        }
    }
    TimeDatePtr->Day = (uint16)DaysNumber;
#if STD_ON == RTC_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      This function convert time-date into seconds.
 *
 * @param[in]  TimeDatePtr: Pointer to time-data configuration
 * @param[in]  Seconds:  Seconds
 *
 * @return     None
 */
static void Rtc_Drv_TimeDateToSeconds(const Rtc_Drv_TimedateType *TimeDatePtr, uint32 *const Seconds)
{
    uint16 Year = YEAR_RANGE_START;

#if STD_ON == RTC_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_START();
#endif

#if STD_ON == RTC_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT(NULL_PTR != Seconds);
    MCALLIB_DEV_ASSERT(NULL_PTR != TimeDatePtr);
#endif
    (*Seconds) = (uint32)(DAYS_IN_A_YEAR * (uint32)(SECONDS_IN_A_DAY));
    (*Seconds) *= ((uint32)TimeDatePtr->Year - YEAR_RANGE_START);

    while (Year < TimeDatePtr->Year)
    {
        if (TRUE == Rtc_Drv_CheckYearLeap(Year))
        {
            (*Seconds) += SECONDS_IN_A_DAY;
        }
        Year++;
    }
    /* If the current year is a leap year and February 29 has already passed, add another day to
       the number of seconds that have passed. */
    if ((TRUE == Rtc_Drv_CheckYearLeap(Year)) && (TimeDatePtr->Month > 2U))
    {
        (*Seconds) += SECONDS_IN_A_DAY;
    }
    else
    {
        /* Nothing to do */
    }
    (*Seconds) += MonthDays[TimeDatePtr->Month] * SECONDS_IN_A_DAY;
    (*Seconds) += (uint32)(((uint32)TimeDatePtr->Day - 1U) * (uint32)SECONDS_IN_A_DAY);
    (*Seconds) +=
        (uint32)(((uint32)TimeDatePtr->Hour * SECONDS_IN_A_HOUR) +
                 ((uint32)TimeDatePtr->Minutes * SECONDS_IN_A_MIN) + (uint32)TimeDatePtr->Seconds);
#if STD_ON == RTC_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_END();
#endif
}

/**
 * @brief      This function gets the current time and date stored in the state structure.
 *
 * @param[in]  Instance: RTC peripheral instance number
 * @param[in]  TimeDatePtr: pointer to time date configuration
 *
 * @return     Rtc_Drv_StatusType
 * @retval     RTC_DRV_SUCCESS:  status success.
 * @retval     RTC_DRV_ERROR:    status error.
 */
Rtc_Drv_StatusType Rtc_Drv_GetCurrentTimeDate(uint8                       Instance,
                                              Rtc_Drv_TimedateType *const TimeDatePtr)
{
    Rtc_Drv_StatusType Status = RTC_DRV_ERROR;
    uint32             FirstRead = 0U;
    uint32             SecondRead = 0U;

#if STD_ON == RTC_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_START();
#endif

#if STD_ON == RTC_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT(NULL_PTR != TimeDatePtr);
    MCALLIB_DEV_ASSERT(RTC_DRV_INSTANCE_COUNT > Instance);
#endif
    FirstRead = Rtc_Drv_GetAlarmCounter(Instance);
    SecondRead = Rtc_Drv_GetAlarmCounter(Instance);

    if (FirstRead == SecondRead)
    {
        Rtc_Drv_SecondsToTimeDate(&FirstRead, TimeDatePtr);
        Status = RTC_DRV_SUCCESS;
    }
    else
    {
        FirstRead = Rtc_Drv_GetAlarmCounter(Instance);
        if (FirstRead == SecondRead)
        {
            Rtc_Drv_SecondsToTimeDate(&FirstRead, TimeDatePtr);
            Status = RTC_DRV_SUCCESS;
        }
        else
        {
            Status = RTC_DRV_ERROR;
        }
    }
#if STD_ON == RTC_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_END();
#endif
    return Status;
}

/**
 * @brief      This function sets the date passed by the user
 *
 * @param[in]  Instance: RTC peripheral instance number
 * @param[in]  TimeDatePtr: pointer to time date configuration
 *
 * @return     Rtc_Drv_StatusType
 * @retval     RTC_DRV_SUCCESS:  status success.
 * @retval     RTC_DRV_ERROR:    status error.
 */
Rtc_Drv_StatusType Rtc_Drv_SetTimeDate(uint8 Instance, const Rtc_Drv_TimedateType *TimeDatePtr)
{
    Rtc_Drv_StatusType Status = RTC_DRV_ERROR;
    uint32             Seconds = 0U;

#if STD_ON == RTC_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_START();
#endif

#if STD_ON == RTC_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT(NULL_PTR != TimeDatePtr);
    MCALLIB_DEV_ASSERT(RTC_DRV_INSTANCE_COUNT > Instance);
#endif
    if (TRUE == Rtc_Drv_CheckTimeDateFormat(TimeDatePtr))
    {
        Rtc_Drv_TimeDateToSeconds(TimeDatePtr, &Seconds);
        Rtc_Drv_SetAlarmTime(Instance, Seconds);
        Status = RTC_DRV_SUCCESS;
    }
    else
    {
        Status = RTC_DRV_ERROR;
    }
#if STD_ON == RTC_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_END();
#endif
    return Status;
}

/**
 * @brief      This function configures the alarm based on the configuration structure.
 *
 * @param[in]  Instance: RTC peripheral instance number
 * @param[in]  AlarmConfigPtr: pointer to alarm configuration
 *
 * @return     Rtc_Drv_StatusType
 * @retval     RTC_DRV_SUCCESS:  status success.
 * @retval     RTC_DRV_ERROR:    status error.
 */
Rtc_Drv_StatusType Rtc_Drv_ConfigAlarm(uint8                          Instance,
                                       const Rtc_Drv_AlarmConfigType *AlarmConfigPtr)
{
    Rtc_Drv_StatusType Status = RTC_DRV_ERROR;
    uint32 ConvertedAlarmMatchTime;
    uint32 CurrentTime;

#if STD_ON == RTC_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_START();
#endif

#if STD_ON == RTC_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT(NULL_PTR != AlarmConfigPtr);
    MCALLIB_DEV_ASSERT(RTC_DRV_INSTANCE_COUNT > Instance);
#endif
    if (TRUE == Rtc_Drv_CheckTimeDateFormat(&(AlarmConfigPtr->AlarmTime)))
    {
        Rtc_Drv_ChannelState[Instance].AlarmInit = TRUE;
        Rtc_Drv_ChannelState[Instance].AlarmRepetitionInterval =
            AlarmConfigPtr->AlarmRepetitionInterval;
        Rtc_Drv_ChannelState[Instance].AlarmRepeatsNumber = AlarmConfigPtr->AlarmRepeatsNumber;
        Rtc_Drv_ChannelState[Instance].RepeatForever = AlarmConfigPtr->RepeatForever;
        Rtc_Drv_ChannelState[Instance].AlarmIntEnable = AlarmConfigPtr->AlarmIntEnable;
        Rtc_Drv_ChannelState[Instance].AlarmCallback = AlarmConfigPtr->AlarmCallback;
        Rtc_Drv_ChannelState[Instance].AlarmCallbackParams = AlarmConfigPtr->AlarmCallbackParams;
        Rtc_Drv_TimeDateToSeconds(&(AlarmConfigPtr->AlarmTime), &ConvertedAlarmMatchTime);
        CurrentTime = Rtc_Drv_GetAlarmCounter(Instance);

        if (ConvertedAlarmMatchTime <= CurrentTime)
        {
            Status = RTC_DRV_ERROR;
        }
        else
        {
            /* Set alarm match time */
            Rtc_Drv_SetAlarmMatchTime(Instance, ConvertedAlarmMatchTime);
            Rtc_Drv_EnableInt(Instance, RTC_DRV_INT_ALARM,
                              Rtc_Drv_ChannelState[Instance].AlarmIntEnable);
            Status = RTC_DRV_SUCCESS;
        }
    }
    else
    {
        Status = RTC_DRV_ERROR;
    }
#if STD_ON == RTC_DRV_DEV_ERROR_DETECT
    MCALLIB_DEV_ASSERT_END();
#endif
    return Status;
}

#if (RTC_DRV_ISR_ENABLE == STD_ON)
/**
 * @brief      Interrupt handler for RTC channel.
 *
 * @return     None
 */
ISR(Rtc_Drv_AlarmIrqHandler)
{
    Rtc_Drv_IntHandler(0U);
    EXIT_INTERRUPT();
}

/**
 * @brief      Interrupt handler for RTC channel.
 *
 * @return     None
 */
ISR(Rtc_Drv_SecondIrqHandler)
{
    Rtc_Drv_IntHandler(0U);
    EXIT_INTERRUPT();
}
#endif

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#endif /* RTC_DRV_ENABLE == STD_ON */

#ifdef __cplusplus
}
#endif

/** @} end of group Rtc_Drv */

/** @} end of group Rtc_Module */
