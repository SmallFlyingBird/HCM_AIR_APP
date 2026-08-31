/**
 * @file    Gpt_Lld_Tmr.c
 * @version V2.3.0
 *
 * @brief   MCU Gpt module interface
 * @details API implementation for GPT driver
 *
 * @addtogroup GPT_LLD_TMR_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Tmr
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

/**
 * @page misra_violations MISRA-C:2012 violations list
 * PRQA S 2985 Rule 2.2:  The operation here is redundant as the result's value is always that of the left-hand operand.
 * PRQA S 2877 Dir 4.1:  This loop will never be executed more than once.
 */

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Gpt_Lld_Tmr.h"
#include "Std_Types.h"
#include "Gpt_Lld_Tmr_Types.h"
#include "Gpt_Lld_Tmr_Reg.h"
#include "SchM_Gpt.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_LLD_TMR_VENDOR_ID_C                      (180)
#define GPT_LLD_TMR_AR_RELEASE_MAJOR_VERSION_C       (4)
#define GPT_LLD_TMR_AR_RELEASE_MINOR_VERSION_C       (4)
#define GPT_LLD_TMR_AR_RELEASE_REVISION_VERSION_C    (0)
#define GPT_LLD_TMR_SW_MAJOR_VERSION_C               (2)
#define GPT_LLD_TMR_SW_MINOR_VERSION_C               (3)
#define GPT_LLD_TMR_SW_PATCH_VERSION_C               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and GPT_LLD_TMR header file are of the same vendor */
#if (GPT_LLD_TMR_VENDOR_ID_C != GPT_LLD_TMR_VENDOR_ID)
#error "Gpt_Lld_Tmr.c and Gpt_Lld_Tmr.h have different vendor ids"
#endif

/* Check if source file and GPT_MLD header file are of the same Autosar version */
#if ((GPT_LLD_TMR_AR_RELEASE_MAJOR_VERSION_C != GPT_LLD_TMR_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_LLD_TMR_AR_RELEASE_MINOR_VERSION_C != GPT_LLD_TMR_AR_RELEASE_MINOR_VERSION) || \
     (GPT_LLD_TMR_AR_RELEASE_REVISION_VERSION_C != GPT_LLD_TMR_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Gpt_Lld_Tmr.c and Gpt_Lld_Tmr.h are different"
#endif

/* Check if source file and GPT_MLD header file are of the same Software version */
#if ((GPT_LLD_TMR_SW_MAJOR_VERSION_C != GPT_LLD_TMR_SW_MAJOR_VERSION) || \
     (GPT_LLD_TMR_SW_MINOR_VERSION_C != GPT_LLD_TMR_SW_MINOR_VERSION) || \
     (GPT_LLD_TMR_SW_PATCH_VERSION_C != GPT_LLD_TMR_SW_PATCH_VERSION))
#error "Software Version Numbers of Gpt_Lld_Tmr.c and Gpt_Lld_Tmr.h are different"
#endif

/* Check if GPT_LLD_TMR_REG_H file and GPT_LLD_TMR header file are of the same vendor */
#if (GPT_LLD_TMR_REG_VENDOR_ID != GPT_LLD_TMR_VENDOR_ID)
#error "Gpt_Lld_Tmr_Reg.h and Gpt_Lld_Tmr.h have different vendor ids"
#endif

/* Check if GPT_LLD_TMR_REG_H file and GPT_MLD header file are of the same Autosar version */
#if ((GPT_LLD_TMR_REG_AR_RELEASE_MAJOR_VERSION != GPT_LLD_TMR_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_LLD_TMR_REG_AR_RELEASE_MINOR_VERSION != GPT_LLD_TMR_AR_RELEASE_MINOR_VERSION) || \
     (GPT_LLD_TMR_REG_AR_RELEASE_REVISION_VERSION != GPT_LLD_TMR_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Gpt_Lld_Tmr_Reg.h and Gpt_Lld_Tmr.h are different"
#endif

/* Check if GPT_LLD_TMR_REG_H file and GPT_MLD header file are of the same Software version */
#if ((GPT_LLD_TMR_REG_SW_MAJOR_VERSION != GPT_LLD_TMR_SW_MAJOR_VERSION) || \
     (GPT_LLD_TMR_REG_SW_MINOR_VERSION != GPT_LLD_TMR_SW_MINOR_VERSION) || \
     (GPT_LLD_TMR_REG_SW_PATCH_VERSION != GPT_LLD_TMR_SW_PATCH_VERSION))
#error "Software Version Numbers of Gpt_Lld_Tmr_Reg.h and Gpt_Lld_Tmr.h are different"
#endif

/*==================================================================================================
 *                                       LOCAL MACROS
==================================================================================================*/
#define TMR_REG_ADDR32_READ(address) (*(volatile uint32 *)(address))
#define TMR_REG_ADDR32_WRITE(address, value) ((*(volatile uint32 *)(address)) = (value))
#define TMR_REG_ADDR32_AEARWRITE(address, mask, value) \
    (TMR_REG_ADDR32_WRITE((address),                   \
                          ((TMR_REG_ADDR32_READ(address) & ((uint32) ~(mask))) | (value))))

#define TMR_REG_ADDR32_SET_BITS(address, mask) ((*(volatile uint32 *)(address)) |= (mask))
#define TMR_REG_ADDR32_CLEAR_BITS(address, mask) ((*(volatile uint32 *)(address)) &= (~(mask)))
#define TMR_REG_ADDR32_GET_BITS(address, mask) ((*(volatile uint32 *)(address)) & (mask))

/*==================================================================================================
 *                                         LOCAL CONSTANTS
==================================================================================================*/
#define GPT_START_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"

/** @brief Table of base addresses for TMR instances. */
GPT_CONST static volatile TMR_Type * const Tmr_Lld_Base[TMR_INSTANCE_COUNT] = TMR_BASE_PTRS;

#define GPT_STOP_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CONST_32
#include "Gpt_MemMap.h"

#if (TMR_INSTANCE_COUNT == 1)
GPT_CONST static const uint32 TMR_BASE_ADDR32[TMR_INSTANCE_COUNT] = {TMR0_BASE_ADDR32};
#endif

#if (TMR_INSTANCE_COUNT == 2)
GPT_CONST static const uint32 TMR_BASE_ADDR32[TMR_INSTANCE_COUNT] = {TMR0_BASE_ADDR32, TMR1_BASE_ADDR32};
#endif

#define GPT_STOP_SEC_CONST_32
#include "Gpt_MemMap.h"

/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/
#define GPT_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Gpt_MemMap.h"

GPT_VAR static Tmr_ChannelInfoType Tmr_ChannelInfo[TMR_INSTANCE_COUNT][TMR_CHANNEL_COUNT];

#define GPT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Gpt_MemMap.h"

#define GPT_START_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"

extern GPT_VAR Gpt_ModeType Gpt_Mode;

#define GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
GPT_FUNC static void Gpt_Lld_Tmr_CalcTimeElapsed(uint8 Instance, uint8 Channel, Tmr_ValueType * ElapsedValuePtr, Tmr_ValueType * RemainingValuePtr);
GPT_FUNC static void Gpt_Lld_Tmr_IrqCmpUpdate(uint8 Instance, uint8 Channel);
/*==================================================================================================
 *                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
 * @brief       Calculate elapsed time and remaining time
 * @param[in]   Instance Instance ID
 * @param[in]   Channel Channel ID
 * @param[out]  ElapsedValuePtr Pointer to elapsed time value
 * @param[out]  RemainingValuePtr Pointer to remaining time value
 * @return      void
 */
GPT_FUNC static void Gpt_Lld_Tmr_CalcTimeElapsed(uint8 Instance, uint8 Channel, Tmr_ValueType * ElapsedValuePtr, Tmr_ValueType * RemainingValuePtr)
{
    /* Get current time stamp */
    Tmr_ValueType CurrentTimeStamp = TMR_REG_ADDR32_READ(TMR_BASE_ADDR32[Instance] + TMR_CNT_OFFSET32);
    /* Calculate remaining time value */
    *RemainingValuePtr = Tmr_ChannelInfo[Instance][Channel].TargetCompareValue - CurrentTimeStamp;
    /* If remaining time value greater than period value, it means cureet time stamp get currently has overrun */
    if (*RemainingValuePtr > Tmr_ChannelInfo[Instance][Channel].PeriodTickValue)
    {
        *RemainingValuePtr = 0U;
    }
    *ElapsedValuePtr = Tmr_ChannelInfo[Instance][Channel].PeriodTickValue - *RemainingValuePtr;
}

GPT_FUNC static void Gpt_Lld_Tmr_IrqCmpUpdate(uint8 Instance, uint8 Channel)
{
#if (GPT_TMR_IRQ_CMP_MODIFY == STD_ON)
    Tmr_ValueType CounterValue = TMR_REG_ADDR32_READ(TMR_BASE_ADDR32[Instance] + TMR_CNT_OFFSET32);
    /* current counter value has exceeded the original next cmp value */
    if((CounterValue >= ((Tmr_ChannelInfo[Instance][Channel].PeriodTickValue + Tmr_ChannelInfo[Instance][Channel].TargetCompareValue) - 10)) ||
            (((Tmr_ChannelInfo[Instance][Channel].PeriodTickValue + Tmr_ChannelInfo[Instance][Channel].TargetCompareValue) - CounterValue) >
             Tmr_ChannelInfo[Instance][Channel].PeriodTickValue)) /*counter rolled from end to beginning, original next cmp value still at the end*/
    {
        Tmr_ChannelInfo[Instance][Channel].TargetCompareValue = Tmr_ChannelInfo[Instance][Channel].PeriodTickValue + CounterValue;
        TMR_REG_ADDR32_WRITE(TMR_BASE_ADDR32[Instance] + TMR_CH_CMP_OFFSET32((uint32)Channel),
                             Tmr_ChannelInfo[Instance][Channel].TargetCompareValue);
    }
    else
    {
#endif
        /* Update Stop time stamp */
        Tmr_ChannelInfo[Instance][Channel].TargetCompareValue += Tmr_ChannelInfo[Instance][Channel].PeriodTickValue;
        /* Update CMP register value */
        TMR_REG_ADDR32_WRITE(TMR_BASE_ADDR32[Instance] + TMR_CH_CMP_OFFSET32(Channel),
                             Tmr_ChannelInfo[Instance][Channel].TargetCompareValue);
#if (GPT_TMR_IRQ_CMP_MODIFY == STD_ON)
    }
#endif
}

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
 * @brief       Initializes the TMR instance.
 * @param[in]   ConfigPtr Pointer to a selected configuration structure
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Tmr_InitInstance(const Tmr_InstanceConfigType *ConfigPtr)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_15();
    /*
     *  MR12 RULE 2.2 VIOLATION: The value of TMR_CTRL_OFFSET32 is 0, remain the code to
     *  maintain stylistic consistency of register manipulation functions.
     */
    /* Disable TMR instance */
    TMR_REG_ADDR32_CLEAR_BITS(TMR_BASE_ADDR32[ConfigPtr->InstanceId] + TMR_CTRL_OFFSET32, TMR_CTRL_TEN_MASK);  /* PRQA S 2985 */
    /* Config run or stop in debug mode */
    if (TRUE == ConfigPtr->StopInDebugMode)
    {
        TMR_REG_ADDR32_SET_BITS(TMR_BASE_ADDR32[ConfigPtr->InstanceId] + TMR_CTRL_OFFSET32, TMR_CTRL_DBGDIS_MASK);   /* PRQA S 2985 */
    }
    else
    {
        TMR_REG_ADDR32_CLEAR_BITS(TMR_BASE_ADDR32[ConfigPtr->InstanceId] + TMR_CTRL_OFFSET32, TMR_CTRL_DBGDIS_MASK);   /* PRQA S 2985 */
    }
    /* Set prescale value */
    TMR_REG_ADDR32_AEARWRITE(TMR_BASE_ADDR32[ConfigPtr->InstanceId] + TMR_PRS_OFFSET32,
                             TMR_PRS_PRS_MASK,
                             (uint32)ConfigPtr->Prescaler);
    /* Set start value to 0 */
    TMR_REG_ADDR32_WRITE(TMR_BASE_ADDR32[ConfigPtr->InstanceId] + TMR_CNT_OFFSET32, 0U);
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_15();
}

/**
 * @brief       Initializes the TMR channel.
 * @param[in]   ConfigPtr Pointer to a selected configuration structure
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Tmr_InitChannel(const Tmr_ChannelConfigType *ConfigPtr)
{
    /* Set channel info value */
    Tmr_ChannelInfo[ConfigPtr->HwInstanceId][ConfigPtr->HwChannelId].IsEnabled = FALSE;
    Tmr_ChannelInfo[ConfigPtr->HwInstanceId][ConfigPtr->HwChannelId].CountMode = ConfigPtr->CountMode;
    Tmr_ChannelInfo[ConfigPtr->HwInstanceId][ConfigPtr->HwChannelId].IsNotificationEnabled = FALSE;
    Tmr_ChannelInfo[ConfigPtr->HwInstanceId][ConfigPtr->HwChannelId].NotificationPtr = ConfigPtr->NotificationPtr;
    Tmr_ChannelInfo[ConfigPtr->HwInstanceId][ConfigPtr->HwChannelId].State = TMR_CHANNEL_STATE_INITIALIZED;
}

/**
 * @brief       De-Initializes the TMR instance.
 * @param[in]   Instance The TMR instance id
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Tmr_DeInitInstance(uint8 Instance)
{
    volatile TMR_Type * const Base = Tmr_Lld_Base[Instance];

    Base->CTRL = 0U;
    Base->PRS = 0U;
    Base->CNT = 0U;
}

/**
 * @brief       De-Initializes the TMR channel.
 * @param[in]   Instance The TMR instance id
 * @param[in]   Channel The TMR channel id
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Tmr_DeInitChannel(uint8 Instance, uint8 Channel)
{
    volatile TMR_Type * const Base = Tmr_Lld_Base[Instance];

    Base->CH[Channel].CTRL = 0U;
    /* Write 1 to clear the channel interrupt flag. */
    Base->CH[Channel].INT = 1U;
    Base->CH[Channel].CMP = 0U;

    Tmr_ChannelInfo[Instance][Channel].IsEnabled = FALSE;
    Tmr_ChannelInfo[Instance][Channel].State = TMR_CHANNEL_STATE_UNINIT;
    Tmr_ChannelInfo[Instance][Channel].IsNotificationEnabled = FALSE;
    Tmr_ChannelInfo[Instance][Channel].NotificationPtr = NULL_PTR;
    Tmr_ChannelInfo[Instance][Channel].CountMode = TMR_CH_MODE_CONTINUOUS;
    Tmr_ChannelInfo[Instance][Channel].PeriodTickValue = 0U;
    Tmr_ChannelInfo[Instance][Channel].TargetCompareValue = 0U;
}

/**
 * @brief       Starts the TMR.
 * @param[in]   Instance The TMR instance id
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Tmr_Start(uint8 Instance)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_16();
    /* Enable TMR module */
    /*
     *  MR12 RULE 2.2 VIOLATION: The value of TMR_CTRL_OFFSET32 is 0, remain the code to
     *  maintain stylistic consistency of register manipulation functions.
     */
    TMR_REG_ADDR32_SET_BITS(TMR_BASE_ADDR32[Instance] + TMR_CTRL_OFFSET32, TMR_CTRL_TEN_MASK);   /* PRQA S 2985 */
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_16();
}

/**
 * @brief       Stops the TMR.
 * @param[in]   Instance The TMR instance id
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Tmr_Stop(uint8 Instance)  /* PRQA S 1505 */
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_17();
    /* Disable TMR module */
    /*
     *  MR12 RULE 2.2 VIOLATION: The value of TMR_CTRL_OFFSET32 is 0, remain the code to
     *  maintain stylistic consistency of register manipulation functions.
     */
    TMR_REG_ADDR32_CLEAR_BITS(TMR_BASE_ADDR32[Instance] + TMR_CTRL_OFFSET32, TMR_CTRL_TEN_MASK);   /* PRQA S 2985 */
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_17();
}

/**
 * @brief       Starts the TMR channel.
 * @param[in]   Instance The TMR instance id
 * @param[in]   Channel The TMR channel id
 * @param[in]   Value The TMR channel value, the minimum value is TMR_CH_CMP_VALUE_MIN
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Tmr_StartChannel(uint8 Instance, uint8 Channel, Tmr_ValueType Value)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_18();
    /* When the channel compare value is less than TMR_CH_CMP_VALUE_MIN, the channel interrupt
     * can not be guaranteed. */
    if (Value < TMR_CH_CMP_VALUE_MIN)
    {
        Tmr_ChannelInfo[Instance][Channel].PeriodTickValue = TMR_CH_CMP_VALUE_MIN;
    }
    else
    {
        Tmr_ChannelInfo[Instance][Channel].PeriodTickValue = Value;
    }
    Tmr_ChannelInfo[Instance][Channel].State = TMR_CHANNEL_STATE_RUNNING;
    Tmr_ValueType FreeRunCounterValue = TMR_REG_ADDR32_READ(TMR_BASE_ADDR32[Instance] + TMR_CNT_OFFSET32);

    Tmr_ChannelInfo[Instance][Channel].TargetCompareValue = FreeRunCounterValue + Tmr_ChannelInfo[Instance][Channel].PeriodTickValue;
    /* Update CMP register value */
    TMR_REG_ADDR32_WRITE(TMR_BASE_ADDR32[Instance] + TMR_CH_CMP_OFFSET32((uint32)Channel),
                         Tmr_ChannelInfo[Instance][Channel].TargetCompareValue);
    /* Enable TMR channel */
    TMR_REG_ADDR32_SET_BITS(TMR_BASE_ADDR32[Instance] + TMR_CH_CTRL_OFFSET32((uint32)Channel),
                            TMR_CH_CTRL_CHEN_MASK);
#if defined(CPU_YTM32B1HA0)
    /* Enable interrupt */
    if (TMR_CH_MODE_ONESHOT == Tmr_ChannelInfo[Instance][Channel].CountMode)
    {
        TMR_REG_ADDR32_SET_BITS(TMR_BASE_ADDR32[Instance] + TMR_CH_CTRL_OFFSET32((uint32)Channel), TMR_CH_CTRL_CHIE_MASK);
    }
#endif
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_18();
}

/**
 * @brief       Stops the TMR channel.
 * @param[in]   Instance The TMR instance id
 * @param[in]   Channel The TMR channel id
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Tmr_StopChannel(uint8 Instance, uint8 Channel)
{
    /* Disable TMR channel */
    TMR_REG_ADDR32_CLEAR_BITS(TMR_BASE_ADDR32[Instance] + TMR_CH_CTRL_OFFSET32((uint32)Channel), TMR_CH_CTRL_CHEN_MASK);
    Tmr_ChannelInfo[Instance][Channel].StopValue = TMR_REG_ADDR32_READ(TMR_BASE_ADDR32[Instance] + TMR_CNT_OFFSET32);
    if (TMR_CH_MODE_CONTINUOUS == Tmr_ChannelInfo[Instance][Channel].CountMode)
    {
        Tmr_ChannelInfo[Instance][Channel].State = TMR_CHANNEL_STATE_STOPPED;
    }
}

/**
 * @brief       Gets the TMR channel time elapsed.
 * @param[in]   Instance The TMR instance id
 * @param[in]   Channel The TMR channel id
 * @return      Tmr_ValueType
 */
GPT_FUNC Tmr_ValueType Gpt_Lld_Tmr_GetChTimeElapsed(uint8 Instance, uint8 Channel)
{
    Tmr_ValueType ElapsedValue = 0U;
    Tmr_ValueType RemainingValue = 0U;

    switch (Tmr_ChannelInfo[Instance][Channel].State)
    {
    case TMR_CHANNEL_STATE_STOPPED:
        ElapsedValue = Tmr_ChannelInfo[Instance][Channel].StopValue -
                       (Tmr_ChannelInfo[Instance][Channel].TargetCompareValue - Tmr_ChannelInfo[Instance][Channel].PeriodTickValue);
        break;
    case TMR_CHANNEL_STATE_EXPIRED:
        ElapsedValue = Tmr_ChannelInfo[Instance][Channel].PeriodTickValue;
        break;
    case TMR_CHANNEL_STATE_RUNNING:
        Gpt_Lld_Tmr_CalcTimeElapsed(Instance, Channel, &ElapsedValue, &RemainingValue);
        break;
    default:
        /* Nothing to do. */
        break;
    }

    return ElapsedValue;
}

/**
 * @brief       Gets the TMR channel time remaining.
 * @param[in]   Instance The TMR instance id
 * @param[in]   Channel The TMR channel id
 * @return      Tmr_ValueType
 */
GPT_FUNC Tmr_ValueType Gpt_Lld_Tmr_GetChTimeRemaining(uint8 Instance, uint8 Channel)
{
    Tmr_ValueType ElapsedValue = 0U;
    Tmr_ValueType RemainingValue = 0U;

    switch (Tmr_ChannelInfo[Instance][Channel].State)
    {
    case TMR_CHANNEL_STATE_STOPPED:
        RemainingValue = Tmr_ChannelInfo[Instance][Channel].TargetCompareValue - Tmr_ChannelInfo[Instance][Channel].StopValue;
        break;
    case TMR_CHANNEL_STATE_EXPIRED:
        RemainingValue = 0U;
        break;
    case TMR_CHANNEL_STATE_RUNNING:
        Gpt_Lld_Tmr_CalcTimeElapsed(Instance, Channel, &ElapsedValue, &RemainingValue);
        break;
    default:
        /* Nothing to do. */
        break;
    }

    return RemainingValue;
}

#if defined(CPU_YTM32B1MD1) || defined(CPU_YTM32B1ME0)
/**
 * @brief       TMR channel interrupt process.
 * @param[in]   Instance The TMR instance id
 * @param[in]   Channel The TMR channel id
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Tmr_ChannelIrqProcess(uint8 Instance, uint8 Channel)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_19();
    uint32 IntFlag = TMR_REG_ADDR32_READ(TMR_BASE_ADDR32[Instance] + TMR_CH_INT_OFFSET32(Channel));
    uint32 ChannelEnable = TMR_REG_ADDR32_READ(TMR_BASE_ADDR32[Instance] + TMR_CH_CTRL_OFFSET32(Channel));
    if ((1U == IntFlag) && (1U == ChannelEnable))
    {
        /* when one-shot mode, stop timer and transter channel state to expired */
        if (TMR_CH_MODE_ONESHOT == Tmr_ChannelInfo[Instance][Channel].CountMode)
        {
            /* stop timer */
            TMR_REG_ADDR32_CLEAR_BITS(TMR_BASE_ADDR32[Instance] + TMR_CH_CTRL_OFFSET32((uint32)Channel), TMR_CH_CTRL_CHEN_MASK);
            Tmr_ChannelInfo[Instance][Channel].State = TMR_CHANNEL_STATE_EXPIRED;
        }
        /* when continuous mode, update Stop time stamp and CMP register value */
        else
        {
            Gpt_Lld_Tmr_IrqCmpUpdate(Instance, Channel);
        }
        /* Clear flag */
        TMR_REG_ADDR32_SET_BITS(TMR_BASE_ADDR32[Instance] + TMR_CH_INT_OFFSET32((uint32)Channel), TMR_CH_INT_CHIF_MASK);
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_19();
        /* Call Notifacation function */
        if (TRUE == Tmr_ChannelInfo[Instance][Channel].IsNotificationEnabled)
        {
            if (NULL_PTR != Tmr_ChannelInfo[Instance][Channel].NotificationPtr)
            {
                Tmr_ChannelInfo[Instance][Channel].NotificationPtr();
            }
        }
    }
    else
    {
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_19();
    }
}
#endif

#if defined(CPU_YTM32B1HA0)
/**
 * @brief       TMR channel interrupt process.
 * @param[in]   Instance The TMR instance id
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Tmr_ChannelIrqProcess(uint8 Instance)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_19();
    /* Check which channel triggered the interrupt */
    uint32 IntFlag;
    uint32 Channel = TMR_CHANNEL_COUNT;
    for(uint32 ChannelId = 0; ChannelId < TMR_CHANNEL_COUNT; ++ChannelId)
    {
        IntFlag = TMR_REG_ADDR32_READ(TMR_BASE_ADDR32[Instance] + TMR_CH_INT_OFFSET32(ChannelId));
        uint32 IntEnable = TMR_REG_ADDR32_GET_BITS(TMR_BASE_ADDR32[Instance] + TMR_CH_CTRL_OFFSET32(ChannelId), TMR_CH_CTRL_CHIE_MASK) >> TMR_CH_CTRL_CHIE_SHIFT;

        if ((1U == IntFlag) && (1U == IntEnable)) {
            Channel = ChannelId;
            break;
        }
    }

    if(Channel != TMR_CHANNEL_COUNT)
    {
        /* when one-shot mode, stop timer and transter channel state to expired */
        if (TMR_CH_MODE_ONESHOT == Tmr_ChannelInfo[Instance][Channel].CountMode)
        {
            /* stop timer */
            TMR_REG_ADDR32_CLEAR_BITS(TMR_BASE_ADDR32[Instance] + TMR_CH_CTRL_OFFSET32(Channel), TMR_CH_CTRL_CHEN_MASK);
            Tmr_ChannelInfo[Instance][Channel].State = TMR_CHANNEL_STATE_EXPIRED;
        }
        /* when continuous mode, update Stop time stamp and CMP register value */
        else
        {
            Gpt_Lld_Tmr_IrqCmpUpdate(Instance, Channel);
        }
        /* Clear flag */
        TMR_REG_ADDR32_SET_BITS(TMR_BASE_ADDR32[Instance] + TMR_CH_INT_OFFSET32(Channel), TMR_CH_INT_CHIF_MASK);
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_19();
        /* Call Notifacation function */
        if (TRUE == Tmr_ChannelInfo[Instance][Channel].IsNotificationEnabled)
        {
            if (NULL_PTR != Tmr_ChannelInfo[Instance][Channel].NotificationPtr)
            {
                Tmr_ChannelInfo[Instance][Channel].NotificationPtr();
            }
        }
    }
    else
    {
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_19();
    }
}
#endif

/**
 * @brief       Gets the TMR channel state.
 * @param[in]   Instance The TMR instance id
 * @param[in]   Channel The TMR channel id
 * @return      Tmr_ChannelStatesType
 */
GPT_FUNC Tmr_ChannelStatesType Gpt_Lld_Tmr_GetTimerState(uint8 Instance, uint8 Channel)
{
    return Tmr_ChannelInfo[Instance][Channel].State;
}

/**
 * @brief       Enables the TMR channel notification.
 * @param[in]   Instance The TMR instance id
 * @param[in]   Channel The TMR channel id
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Tmr_EnableNotification(uint8 Instance, uint8 Channel)
{
    Tmr_ChannelInfo[Instance][Channel].IsNotificationEnabled = TRUE;
#if defined(CPU_YTM32B1HA0)
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_06();
    TMR_REG_ADDR32_SET_BITS(TMR_BASE_ADDR32[Instance] + TMR_CH_CTRL_OFFSET32((uint32)Channel), TMR_CH_CTRL_CHIE_MASK);
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_06();
#endif
}

/**
 * @brief       Disables the TMR channel notification.
 * @param[in]   Instance The TMR instance id
 * @param[in]   Channel The TMR channel id
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Tmr_DisableNotification(uint8 Instance, uint8 Channel)
{
    Tmr_ChannelInfo[Instance][Channel].IsNotificationEnabled = FALSE;
#if defined(CPU_YTM32B1HA0)
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_14();
    /* Disable interrupt
       Condition:
            1. Continuous mode
            2. OneShot mode: timer state is not running */
    if ((TMR_CH_MODE_CONTINUOUS == Tmr_ChannelInfo[Instance][Channel].CountMode) ||
            (TMR_CHANNEL_STATE_RUNNING != Tmr_ChannelInfo[Instance][Channel].State))
    {
        TMR_REG_ADDR32_CLEAR_BITS(TMR_BASE_ADDR32[Instance] + TMR_CH_CTRL_OFFSET32((uint32)Channel), TMR_CH_CTRL_CHIE_MASK);
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_14();
#endif
}

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
 * @brief       This function sets the operation mode of the TMR.
 * @param[in]   Mode GPT_MODE_NORMAL: Normal operation mode of the GPT driver.
 *                   GPT_MODE_SLEEP: Sleep mode of the GPT driver (wakeup capable).
 *                   See also Gpt_ModeType.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Tmr_SetMode(Gpt_ModeType Mode)
{
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    if(GPT_MODE_SLEEP == Mode)
    {
        /*
         *  MR12 RULE 2.2 VIOLATION: When the chip is YTM32BIMD1 or ME0 or MC0, the value of TMR_INSTANCE_COUNT is 1.
         *  When the chip is YTM32BIHA0, the value of TMR_INSTANCE_COUNT is 2.
         *  Use the loop to make the code applicable to each chip.
         */
        for(uint8 Instance = 0; Instance < TMR_INSTANCE_COUNT; ++Instance)    /* PRQA S 2877 */
        {
            Gpt_Lld_Tmr_Stop(Instance);
            for(uint8 Channel = 0; Channel < TMR_CHANNEL_COUNT; ++Channel)
            {
                if(TMR_CHANNEL_STATE_RUNNING == Tmr_ChannelInfo[Instance][Channel].State)
                {
                    Gpt_Lld_Tmr_StopChannel(Instance, Channel);
                    /* Clear flag */
                    TMR_REG_ADDR32_SET_BITS(TMR_BASE_ADDR32[Instance] + TMR_CH_INT_OFFSET32((uint32)Channel), TMR_CH_INT_CHIF_MASK);
                }
            }
        }
    }
#endif /* GPT_REPORT_WAKEUP_SOURCE */
}
#endif

/**
 * @brief       This function gets the TMR hardware instance configuration.
 * @param[in]   Instance The TMR instance id
 * @param[in]   InstCfg The pointer to the configuration structure.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Tmr_GetInstanceCfg(uint8 Instance, Tmr_InstanceConfigType * const InstCfg)
{
    volatile uint32 Reg = 0U;
    TMR_Type const volatile * Base = Tmr_Lld_Base[Instance];
    InstCfg->InstanceId = Instance;
    Reg = Base->CTRL;
    InstCfg->StopInDebugMode = (boolean)((Reg & TMR_CTRL_DBGDIS_MASK) >> TMR_CTRL_DBGDIS_SHIFT);
    Reg = Base->PRS;
    InstCfg->Prescaler = (uint8)((Reg & TMR_PRS_PRS_MASK) >> TMR_PRS_PRS_SHIFT);
}

/**
 * @brief       This function gets the TMR channel configuration.
 * @param[in]   Instance The TMR instance id
 * @param[in]   Channel The TMR channel id
 * @param[in]   ChCfg The pointer to the configuration structure.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Tmr_GetChannelCfg(uint8 Instance, uint8 Channel, Tmr_ChannelConfigType * const ChCfg)
{
    ChCfg->HwInstanceId = Instance;
    ChCfg->HwChannelId = Channel;
    ChCfg->CountMode = Tmr_ChannelInfo[Instance][Channel].CountMode;
    ChCfg->EnableNotification = Tmr_ChannelInfo[Instance][Channel].IsNotificationEnabled;
    ChCfg->NotificationPtr = Tmr_ChannelInfo[Instance][Channel].NotificationPtr;
}

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /** @} */

