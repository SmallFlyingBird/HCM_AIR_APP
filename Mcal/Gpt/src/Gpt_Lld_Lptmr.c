/**
 * @file    Gpt_Lld_Lptmr.c
 * @version V2.3.0
 *
 * @brief   MCU Gpt module interface
 * @details API implementation for GPT driver
 *
 * @addtogroup GPT_LLD_LPTMR_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Lptmr
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

/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include "Gpt_Lld_Lptmr.h"
#include "Std_Types.h"
#include "Gpt_Lld_Lptmr_Types.h"
#include "Gpt_Lld_Lptmr_Reg.h"
#include "SchM_Gpt.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_LLD_LPTMR_VENDOR_ID_C                      (180)
#define GPT_LLD_LPTMR_AR_RELEASE_MAJOR_VERSION_C       (4)
#define GPT_LLD_LPTMR_AR_RELEASE_MINOR_VERSION_C       (4)
#define GPT_LLD_LPTMR_AR_RELEASE_REVISION_VERSION_C    (0)
#define GPT_LLD_LPTMR_SW_MAJOR_VERSION_C               (2)
#define GPT_LLD_LPTMR_SW_MINOR_VERSION_C               (3)
#define GPT_LLD_LPTMR_SW_PATCH_VERSION_C               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and GPT_LLD_LPTMR header file are of the same vendor */
#if (GPT_LLD_LPTMR_VENDOR_ID_C != GPT_LLD_LPTMR_VENDOR_ID)
#error "Gpt_Lld_Lptmr.c and Gpt_Lld_Lptmr.h have different vendor ids"
#endif

/* Check if source file and GPT_LLD_LPTMR header file are of the same Autosar version */
#if ((GPT_LLD_LPTMR_AR_RELEASE_MAJOR_VERSION_C != GPT_LLD_LPTMR_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_LLD_LPTMR_AR_RELEASE_MINOR_VERSION_C != GPT_LLD_LPTMR_AR_RELEASE_MINOR_VERSION) || \
     (GPT_LLD_LPTMR_AR_RELEASE_REVISION_VERSION_C != GPT_LLD_LPTMR_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Gpt_Lld_Lptmr.c and Gpt_Lld_Lptmr.h are different"
#endif

/* Check if source file and GPT_LLD_LPTMR header file are of the same Software version */
#if ((GPT_LLD_LPTMR_SW_MAJOR_VERSION_C != GPT_LLD_LPTMR_SW_MAJOR_VERSION) || \
     (GPT_LLD_LPTMR_SW_MINOR_VERSION_C != GPT_LLD_LPTMR_SW_MINOR_VERSION) || \
     (GPT_LLD_LPTMR_SW_PATCH_VERSION_C != GPT_LLD_LPTMR_SW_PATCH_VERSION))
#error "Software Version Numbers of Gpt_Lld_Lptmr.c and Gpt_Lld_Lptmr.h are different"
#endif

/* Check if GPT_LLD_LPTMR_REG_H file and GPT_LLD_LPTMR header file are of the same vendor */
#if (GPT_LLD_LPTMR_REG_VENDOR_ID != GPT_LLD_LPTMR_VENDOR_ID)
#error "Gpt_Lld_Lptmr_Reg.h and Gpt_Lld_Lptmr.h have different vendor ids"
#endif

/* Check if GPT_LLD_LPTMR_REG_H file and GPT_LLD_LPTMR header file are of the same Autosar version */
#if ((GPT_LLD_LPTMR_REG_AR_RELEASE_MAJOR_VERSION != GPT_LLD_LPTMR_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_LLD_LPTMR_REG_AR_RELEASE_MINOR_VERSION != GPT_LLD_LPTMR_AR_RELEASE_MINOR_VERSION) || \
     (GPT_LLD_LPTMR_REG_AR_RELEASE_REVISION_VERSION != GPT_LLD_LPTMR_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Gpt_Lld_Lptmr_Reg.h and Gpt_Lld_Lptmr.h are different"
#endif

/* Check if GPT_LLD_LPTMR_REG_H file and GPT_LLD_LPTMR header file are of the same Software version */
#if ((GPT_LLD_LPTMR_REG_SW_MAJOR_VERSION != GPT_LLD_LPTMR_SW_MAJOR_VERSION) || \
     (GPT_LLD_LPTMR_REG_SW_MINOR_VERSION != GPT_LLD_LPTMR_SW_MINOR_VERSION) || \
     (GPT_LLD_LPTMR_REG_SW_PATCH_VERSION != GPT_LLD_LPTMR_SW_PATCH_VERSION))
#error "Software Version Numbers of Gpt_Lld_Lptmr_Reg.h and Gpt_Lld_Lptmr.h are different"
#endif

/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
#define LPTMR_REG_ADDR32_READ(address) (*(volatile uint32 *)(address))
#define LPTMR_REG_ADDR32_WRITE(address, value) ((*(volatile uint32 *)(address)) = (value))
#define LPTMR_REG_ADDR32_AEARWRITE(address, mask, value) \
    (LPTMR_REG_ADDR32_WRITE((address),                   \
                            ((LPTMR_REG_ADDR32_READ(address) & ((uint32) ~(mask))) | (value))))

#define LPTMR_REG_ADDR32_SET_BITS(address, mask) ((*(volatile uint32 *)(address)) |= (mask))
#define LPTMR_REG_ADDR32_CLEAR_BITS(address, mask) ((*(volatile uint32 *)(address)) &= (~(mask)))
#define LPTMR_REG_ADDR32_GET_BITS(address, mask) ((*(volatile uint32 *)(address)) & (mask))
#define LPTMR_REG_ADDR32_INDEX_SET_BIT(address, bitindex) ((*(volatile uint32 *)(address)) |= ((uint32)1 << (bitindex)))          /* PRQA S 1534 */
#define LPTMR_REG_ADDR32_INDEX_CLEAR_BIT(address, bitindex) ((*(volatile uint32 *)(address)) &= (~((uint32)1 << (bitindex))))     /* PRQA S 1534 */

/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/
#define GPT_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Gpt_MemMap.h"

GPT_VAR static Lptmr_InfoType Lptmr_Info;

#define GPT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Gpt_MemMap.h"   /*NOSONAR, The #include need to be here to be able to use the Gpt_MemMap.h */

#define GPT_START_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"

extern GPT_VAR Gpt_ModeType Gpt_Mode;

#define GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"

/*==================================================================================================
 *                                         LOCAL CONSTANTS
==================================================================================================*/
#define GPT_START_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"

/** @brief Table of base addresses for lpTMR instances. */
GPT_CONST static volatile lpTMR_Type * const Lptmr_Lld_Base[lpTMR_INSTANCE_COUNT] = lpTMR_BASE_PTRS;

#define GPT_STOP_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
GPT_FUNC static void Gpt_Lld_Lptmr_LatchTimer(void);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
 * @brief       This function latches the current value of the lpTMR counter.
 * @return      void
 */
GPT_FUNC static void Gpt_Lld_Lptmr_LatchTimer(void)
{
    /* Write register LCVAL to latch timer counter to CNT */
    LPTMR_REG_ADDR32_WRITE(lpTMR0_BASE_ADDR32 + lpTMR_LCNT_OFFSET32, 0U);
}

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
 * @brief       This function initializes the lpTMR module.
 * @param[in]   ConfigPtr Pointer to the lpTMR instance configuration structure.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_LptmrInitInstance(const Lptmr_InstanceConfigType * ConfigPtr)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_00();
    /* Disable interrupt */
    LPTMR_REG_ADDR32_CLEAR_BITS(lpTMR0_BASE_ADDR32 + lpTMR_DIE_OFFSET32, lpTMR_DIE_IE_MASK);
    /* Disable lpTMR module */
    LPTMR_REG_ADDR32_CLEAR_BITS(lpTMR0_BASE_ADDR32 + lpTMR_CTRL_OFFSET32, lpTMR_CTRL_EN_MASK);
    /* Clock set */
    /* Set clock source */
    LPTMR_REG_ADDR32_AEARWRITE(lpTMR0_BASE_ADDR32 + lpTMR_PRS_OFFSET32,
                               lpTMR_PRS_CLKSEL_MASK,
                               (uint8)ConfigPtr->ClockSource);
    /* Set prescale */
    if (LPTMR_CLOCK_PRESCALER_1 == ConfigPtr->PrescaleCode)
    {
        LPTMR_REG_ADDR32_SET_BITS(lpTMR0_BASE_ADDR32 + lpTMR_PRS_OFFSET32, lpTMR_PRS_BYPASS_MASK);
    }
    else
    {
        LPTMR_REG_ADDR32_CLEAR_BITS(lpTMR0_BASE_ADDR32 + lpTMR_PRS_OFFSET32, lpTMR_PRS_BYPASS_MASK);
        LPTMR_REG_ADDR32_AEARWRITE(lpTMR0_BASE_ADDR32 + lpTMR_PRS_OFFSET32,
                                   lpTMR_PRS_PRES_MASK,
                                   lpTMR_PRS_PRES(ConfigPtr->PrescaleCode));
    }

    /* Set lpTMR mode : set as time counter mode */
    LPTMR_REG_ADDR32_CLEAR_BITS(lpTMR0_BASE_ADDR32 + lpTMR_CTRL_OFFSET32, lpTMR_CTRL_MODE_MASK);

    /* Set free running timer mode : set as CNT is reset whenever CCF is set */
    LPTMR_REG_ADDR32_CLEAR_BITS(lpTMR0_BASE_ADDR32 + lpTMR_CTRL_OFFSET32, lpTMR_CTRL_TMODE_MASK);
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_00();
}


/**
 * @brief       This function initializes the lpTMR module.
 * @param[in]   ConfigPtr Pointer to the lpTMR configuration structure.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Lptmr_Init(const Lptmr_ConfigType * ConfigPtr)
{
    Lptmr_Info.IsNotificationEnabled = FALSE;
    Lptmr_Info.NotificationPtr = ConfigPtr->NotificationPtr;
    Lptmr_Info.CountMode = ConfigPtr->CountMode;
    Lptmr_Info.IsWakeupEnabled = FALSE;
    Lptmr_Info.IsWakeupGenerated = FALSE;
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    Lptmr_Info.WakeupSource = ConfigPtr->WakeupSource;
#endif
    Lptmr_Info.State = LPTMR_STATE_INITIALIZED;
}

/**
 * @brief       De-Initializes the lpTMR instance.
 * @param[in]   Instance The lpTMR instance id
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Lptmr_DeInit(uint8 Instance)
{
    volatile lpTMR_Type * const Base = Lptmr_Lld_Base[Instance];

    Base->CTRL = 0U;
    Base->PRS = 0U;
    Base->DIE = 0U;
    /* Write 1 to clear counter compare flag. */
    Base->STS = 1U;
    Base->CMP = 0U;
    Base->LCNT = 0U;
    Base->CNT = 0U;

    Lptmr_Info.State = LPTMR_STATE_UNINIT;
    Lptmr_Info.IsNotificationEnabled = FALSE;
    Lptmr_Info.NotificationPtr = NULL_PTR;
    Lptmr_Info.CountMode = LPTMR_MODE_CONTINUOUS;
    Lptmr_Info.PeriodTickValue = 0U;
    Lptmr_Info.StopValue = 0U;
}

/**
 * @brief       This function starts the lpTMR module.
 * @param[in]   Value Period value.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Lptmr_StartTimer(Lptmr_ValueType Value)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_01();
    /* Disable lpTMR module */
    LPTMR_REG_ADDR32_CLEAR_BITS(lpTMR0_BASE_ADDR32 + lpTMR_CTRL_OFFSET32, lpTMR_CTRL_EN_MASK);
    /* Set period value */
    LPTMR_REG_ADDR32_WRITE(lpTMR0_BASE_ADDR32 + lpTMR_CMP_OFFSET32, Value);
    Lptmr_Info.PeriodTickValue = Value;

    LPTMR_REG_ADDR32_WRITE(lpTMR0_BASE_ADDR32 + lpTMR_CNT_OFFSET32, 0);

    /* Enable interrupt */
    if (LPTMR_MODE_ONESHOT == Lptmr_Info.CountMode)
    {
        LPTMR_REG_ADDR32_SET_BITS(lpTMR0_BASE_ADDR32 + lpTMR_DIE_OFFSET32, lpTMR_DIE_IE_MASK);
    }

    /* Start lpTMR */
    LPTMR_REG_ADDR32_SET_BITS(lpTMR0_BASE_ADDR32 + lpTMR_CTRL_OFFSET32, lpTMR_CTRL_EN_MASK);
    /* Update timer state to "running" */
    Lptmr_Info.State = LPTMR_STATE_RUNNING;
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_01();
}

/**
 * @brief       This function stops the lpTMR module.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Lptmr_StopTimer(void)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_02();
    Gpt_Lld_Lptmr_LatchTimer();
    Lptmr_Info.StopValue = (uint16)LPTMR_REG_ADDR32_READ(lpTMR0_BASE_ADDR32 + lpTMR_CNT_OFFSET32);
    /* Disable interrupt */
    LPTMR_REG_ADDR32_CLEAR_BITS(lpTMR0_BASE_ADDR32 + lpTMR_DIE_OFFSET32, lpTMR_DIE_IE_MASK);
    /* Disable lpTMR module */
    LPTMR_REG_ADDR32_CLEAR_BITS(lpTMR0_BASE_ADDR32 + lpTMR_CTRL_OFFSET32, lpTMR_CTRL_EN_MASK);

    /* Update timer state to "stoped" */
    if (LPTMR_MODE_CONTINUOUS == Lptmr_Info.CountMode)
    {
        Lptmr_Info.State = LPTMR_STATE_STOPPED;
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_02();
}

/**
 * @brief       This function is the lpTMR interrupt handler.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Lptmr_IrqProcess(void)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_03();
    uint32 IntFlag = LPTMR_REG_ADDR32_GET_BITS(lpTMR0_BASE_ADDR32 + lpTMR_STS_OFFSET32, lpTMR_STS_CCF_MASK) >> lpTMR_STS_CCF_SHIFT;
    uint32 IntEnable = LPTMR_REG_ADDR32_GET_BITS(lpTMR0_BASE_ADDR32 + lpTMR_DIE_OFFSET32, lpTMR_DIE_IE_MASK) >> lpTMR_DIE_IE_SHIFT;
    if ((1U == IntFlag) && (1U == IntEnable))
    {
        if(GPT_MODE_SLEEP == Gpt_Mode) {
            Lptmr_Info.IsWakeupGenerated = TRUE;
            Gpt_Mode = GPT_MODE_NORMAL;
        }
        /* Clear flag */
        LPTMR_REG_ADDR32_SET_BITS(lpTMR0_BASE_ADDR32 + lpTMR_STS_OFFSET32, lpTMR_STS_CCF_MASK);

        if (LPTMR_MODE_ONESHOT == Lptmr_Info.CountMode)
        {
            /* Disable interrupt */
            LPTMR_REG_ADDR32_CLEAR_BITS(lpTMR0_BASE_ADDR32 + lpTMR_DIE_OFFSET32, lpTMR_DIE_IE_MASK);
            /* Disable lpTMR module */
            LPTMR_REG_ADDR32_CLEAR_BITS(lpTMR0_BASE_ADDR32 + lpTMR_CTRL_OFFSET32, lpTMR_CTRL_EN_MASK);
            /* Update channel state to expired */
            Lptmr_Info.State = LPTMR_STATE_EXPIRED;
        }
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_03();

        /* Call Notifacation function */
        if (TRUE == Lptmr_Info.IsNotificationEnabled)
        {
            if (NULL_PTR != Lptmr_Info.NotificationPtr)
            {
                Lptmr_Info.NotificationPtr();
            }
        }
    }
    else
    {
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_03();
    }
}

/**
 * @brief       This function returns the elapsed time.
 * @return      Lptmr_ValueType Elapsed time.
 */
GPT_FUNC Lptmr_ValueType Gpt_Lld_Lptmr_GetTimeElapsed(void)
{
    Lptmr_ValueType ElapsedValue = 0U;

    switch (Lptmr_Info.State)
    {
    case LPTMR_STATE_RUNNING:
        Gpt_Lld_Lptmr_LatchTimer();
        /* Get current time stamp */
        ElapsedValue = (uint16)LPTMR_REG_ADDR32_READ(lpTMR0_BASE_ADDR32 + lpTMR_CNT_OFFSET32);
        break;
    case LPTMR_STATE_STOPPED:
        ElapsedValue = Lptmr_Info.StopValue;
        break;
    case LPTMR_STATE_EXPIRED:
        ElapsedValue = Lptmr_Info.PeriodTickValue;
        break;
    default:
        /* Nothing to do */
        break;
    }

    return ElapsedValue;
}

/**
 * @brief       This function returns the remaining time.
 * @return      Lptmr_ValueType Remaining time.
 */
GPT_FUNC Lptmr_ValueType Gpt_Lld_Lptmr_GetTimeRemaining(void)
{
    Lptmr_ValueType ElapsedValue = 0U;
    Lptmr_ValueType RemainingValue = 0U;

    switch (Lptmr_Info.State)
    {
    case LPTMR_STATE_RUNNING:
        Gpt_Lld_Lptmr_LatchTimer();
        /* Get current time stamp */
        ElapsedValue = (uint16)LPTMR_REG_ADDR32_READ(lpTMR0_BASE_ADDR32 + lpTMR_CNT_OFFSET32);
        break;
    case LPTMR_STATE_STOPPED:
        ElapsedValue = Lptmr_Info.StopValue;
        break;
    case LPTMR_STATE_EXPIRED:
        ElapsedValue = Lptmr_Info.PeriodTickValue;
        break;
    default:
        /* Nothing to do */
        break;
    }
    RemainingValue = Lptmr_Info.PeriodTickValue - ElapsedValue;

    return RemainingValue;
}

/**
 * @brief       This function returns the lpTMR state.
 * @return      Lptmr_StatesType
 */
GPT_FUNC Lptmr_StatesType Gpt_Lld_Lptmr_GetTimerState(void)
{
    return Lptmr_Info.State;
}

/**
 * @brief       This function enables the lpTMR notification.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Lptmr_EnNotification(void)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_04();
    Lptmr_Info.IsNotificationEnabled = TRUE;
    /* Enable interrupt */
    LPTMR_REG_ADDR32_SET_BITS(lpTMR0_BASE_ADDR32 + lpTMR_DIE_OFFSET32, lpTMR_DIE_IE_MASK);
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_04();
}

/**
 * @brief       This function disables the lpTMR notification.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Lptmr_DisNotification(void)
{
    if((GPT_MODE_NORMAL == Gpt_Mode)||((GPT_MODE_SLEEP == Gpt_Mode)&&(FALSE == Lptmr_Info.IsWakeupEnabled)))
    {
        SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_05();
        /* Save notification disable attribute */
        Lptmr_Info.IsNotificationEnabled = FALSE;
        /* Disable interrupt
        Condition:
                1. Continuous mode
                2. OneShot mode: timer state is not running */
        if ((LPTMR_MODE_CONTINUOUS == Lptmr_Info.CountMode) ||
                (LPTMR_STATE_RUNNING != Lptmr_Info.State))
        {
            LPTMR_REG_ADDR32_CLEAR_BITS(lpTMR0_BASE_ADDR32 + lpTMR_DIE_OFFSET32, lpTMR_DIE_IE_MASK);
        }
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_05();
    }
}

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
 * @brief       This function enables the lpTMR wakeup.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Lptmr_EnableWakeup(void)
{
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_29();
#if (GPT_SUPPORT_POWERDOWN_WAKEUP == STD_ON)
    LPTMR_REG_ADDR32_INDEX_SET_BIT(WKU_BASE_ADDR32 + WKU_MER_OFFSET32, 2U);
#endif
    Lptmr_Info.IsWakeupEnabled = TRUE;
    Gpt_Lld_Lptmr_EnNotification();
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_29();
#endif /* GPT_REPORT_WAKEUP_SOURCE */
}

/**
 * @brief       This function disables the lpTMR wakeup.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Lptmr_DisableWakeup(void)
{
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_30();
#if (GPT_SUPPORT_POWERDOWN_WAKEUP == STD_ON)
    LPTMR_REG_ADDR32_INDEX_CLEAR_BIT(WKU_BASE_ADDR32 + WKU_MER_OFFSET32, 2U);
#endif
    Lptmr_Info.IsWakeupEnabled = FALSE;
    if(GPT_MODE_SLEEP == Gpt_Mode)
    {
        Gpt_Lld_Lptmr_DisNotification();
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_30();
#endif /* GPT_REPORT_WAKEUP_SOURCE */
}

/**
 * @brief       This function sets the operation mode of the lpTMR.
 * @param[in]   Mode GPT_MODE_NORMAL: Normal operation mode of the GPT driver.
 *                   GPT_MODE_SLEEP: Sleep mode of the GPT driver (wakeup capable).
 *                   See also Gpt_ModeType.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Lptmr_SetMode(Gpt_ModeType Mode)
{
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    if(GPT_MODE_SLEEP == Mode)
    {
        if((Lptmr_Info.State == LPTMR_STATE_RUNNING)&&(FALSE == Lptmr_Info.IsWakeupEnabled))
        {
            Gpt_Lld_Lptmr_StopTimer();
            /* Clear flag */
            LPTMR_REG_ADDR32_SET_BITS(lpTMR0_BASE_ADDR32 + lpTMR_STS_OFFSET32, lpTMR_STS_CCF_MASK);
        }
    }
#endif /* GPT_REPORT_WAKEUP_SOURCE */
}

/**
 * @brief       This function checks whether lpTMR is the source for a wakeup event.
 * @param[in]   EcuM_WakeupSourceType WakeupSource
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Lptmr_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
{
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_31();
    if((WakeupSource == Lptmr_Info.WakeupSource)&&(TRUE == Lptmr_Info.IsWakeupGenerated))
    {
        /*GCOVR_EXCL_START: Testing the wake up function requires the MCU to be set to a non-general mode,
        but in the integration test, it is necessary to ensure that the chip can run normally.
        Therefore, the wake up function has been excluded from coverage testing.*/
        /* Reset the wakeup flag */
        Lptmr_Info.IsWakeupGenerated = FALSE;
        /* Calling EcuM_SetWakeupEvent*/
        EcuM_SetWakeupEvent(WakeupSource);
        /*GCOVR_EXCL_STOP*/
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_31();
#endif /* GPT_REPORT_WAKEUP_SOURCE */
}
#endif /* GPT_WAKEUP_FUNCTIONALITY_API */

/**
 * @brief       This function gets the lpTMR hardware instance configuration.
 * @param[in]   Instance The lpTMR instance id
 * @param[in]   Cfg The pointer to the configuration structure.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Lptmr_GetCfg(uint8 Instance, Lptmr_ConfigType * const Cfg)
{
    uint8 Tmp = 0U;
    volatile uint32 Reg = 0U;
    lpTMR_Type const volatile * Base = Lptmr_Lld_Base[Instance];

    Reg = Base->PRS;
    Tmp = (uint8)((Reg & lpTMR_PRS_CLKSEL_MASK) >> lpTMR_PRS_CLKSEL_SHIFT);
    Cfg->ClockSource = (Lptmr_ClockSourceType)Tmp;
    Tmp = (uint8)((Reg & lpTMR_PRS_PRES_MASK) >> lpTMR_PRS_PRES_SHIFT);
    Cfg->PrescaleCode = (Lptmr_PrescalerType)Tmp;
    Cfg->CountMode = Lptmr_Info.CountMode;
    Cfg->EnableNotification = Lptmr_Info.IsNotificationEnabled;
    Cfg->NotificationPtr = Lptmr_Info.NotificationPtr;
}

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

