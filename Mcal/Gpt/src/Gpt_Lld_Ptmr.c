/**
 * @file    Gpt_Lld_Ptmr.c
 * @version V2.3.0
 *
 * @brief   MCU Gpt module interface
 * @details API implementation for GPT driver
 *
 * @addtogroup GPT_LLD_PTMR_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Ptmr
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
#include "Gpt_Lld_Ptmr.h"
#include "Std_Types.h"
#include "Gpt_Lld_Ptmr_Types.h"
#include "Gpt_Lld_Ptmr_Reg.h"
#include "SchM_Gpt.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_LLD_PTMR_VENDOR_ID_C                      (180)
#define GPT_LLD_PTMR_AR_RELEASE_MAJOR_VERSION_C       (4)
#define GPT_LLD_PTMR_AR_RELEASE_MINOR_VERSION_C       (4)
#define GPT_LLD_PTMR_AR_RELEASE_REVISION_VERSION_C    (0)
#define GPT_LLD_PTMR_SW_MAJOR_VERSION_C               (2)
#define GPT_LLD_PTMR_SW_MINOR_VERSION_C               (3)
#define GPT_LLD_PTMR_SW_PATCH_VERSION_C               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and GPT_LLD_PTMR header file are of the same vendor */
#if (GPT_LLD_PTMR_VENDOR_ID_C != GPT_LLD_PTMR_VENDOR_ID)
#error "Gpt_Lld_Ptmr.c and Gpt_Lld_Ptmr.h have different vendor ids"
#endif

/* Check if source file and GPT_LLD_PTMR header file are of the same Autosar version */
#if ((GPT_LLD_PTMR_AR_RELEASE_MAJOR_VERSION_C != GPT_LLD_PTMR_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_LLD_PTMR_AR_RELEASE_MINOR_VERSION_C != GPT_LLD_PTMR_AR_RELEASE_MINOR_VERSION) || \
     (GPT_LLD_PTMR_AR_RELEASE_REVISION_VERSION_C != GPT_LLD_PTMR_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Gpt_Lld_Ptmr.c and Gpt_Lld_Ptmr.h are different"
#endif

/* Check if source file and GPT_LLD_PTMR header file are of the same Software version */
#if ((GPT_LLD_PTMR_SW_MAJOR_VERSION_C != GPT_LLD_PTMR_SW_MAJOR_VERSION) || \
     (GPT_LLD_PTMR_SW_MINOR_VERSION_C != GPT_LLD_PTMR_SW_MINOR_VERSION) || \
     (GPT_LLD_PTMR_SW_PATCH_VERSION_C != GPT_LLD_PTMR_SW_PATCH_VERSION))
#error "Software Version Numbers of Gpt_Lld_Ptmr.c and Gpt_Lld_Ptmr.h are different"
#endif

/* Check if GPT_LLD_PTMR_REG_H file and GPT_LLD_PTMR header file are of the same vendor */
#if (GPT_LLD_PTMR_REG_VENDOR_ID != GPT_LLD_PTMR_VENDOR_ID)
#error "Gpt_Lld_Ptmr_Reg.h and Gpt_Lld_Ptmr.h have different vendor ids"
#endif

/* Check if GPT_LLD_PTMR_REG_H file and GPT_LLD_PTMR header file are of the same Autosar version */
#if ((GPT_LLD_PTMR_REG_AR_RELEASE_MAJOR_VERSION != GPT_LLD_PTMR_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_LLD_PTMR_REG_AR_RELEASE_MINOR_VERSION != GPT_LLD_PTMR_AR_RELEASE_MINOR_VERSION) || \
     (GPT_LLD_PTMR_REG_AR_RELEASE_REVISION_VERSION != GPT_LLD_PTMR_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Gpt_Lld_Ptmr_Reg.h and Gpt_Lld_Ptmr.h are different"
#endif

/* Check if GPT_LLD_PTMR_REG_H file and GPT_LLD_PTMR header file are of the same Software version */
#if ((GPT_LLD_PTMR_REG_SW_MAJOR_VERSION != GPT_LLD_PTMR_SW_MAJOR_VERSION) || \
     (GPT_LLD_PTMR_REG_SW_MINOR_VERSION != GPT_LLD_PTMR_SW_MINOR_VERSION) || \
     (GPT_LLD_PTMR_REG_SW_PATCH_VERSION != GPT_LLD_PTMR_SW_PATCH_VERSION))
#error "Software Version Numbers of Gpt_Lld_Ptmr_Reg.h and Gpt_Lld_Ptmr.h are different"
#endif

/*==================================================================================================
 *                                       LOCAL MACROS
==================================================================================================*/
#define PTMR_REG_ADDR32_READ(address) (*(volatile uint32 *)(address))
#define PTMR_REG_ADDR32_WRITE(address, value) ((*(volatile uint32 *)(address)) = (value))
#define PTMR_REG_ADDR32_SET_BITS(address, mask) ((*(volatile uint32 *)(address)) |= (mask))
#define PTMR_REG_ADDR32_CLEAR_BITS(address, mask) ((*(volatile uint32 *)(address)) &= (~(mask)))
#define PTMR_REG_ADDR32_GET_BITS(address, mask) ((*(volatile uint32 *)(address)) & (mask))

/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/
#define GPT_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Gpt_MemMap.h" /* NOSONAR, memory map */

GPT_VAR static Ptmr_ChannelInfoType Ptmr_ChannelInfo[pTMR_INSTANCE_COUNT][PTMR_CHANNEL_COUNT];

#define GPT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Gpt_MemMap.h" /* NOSONAR, memory map */

#define GPT_START_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_MemMap.h" /* NOSONAR, memory map */

extern GPT_VAR Gpt_ModeType Gpt_Mode;

#define GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_MemMap.h" /* NOSONAR, memory map */

/*==================================================================================================
 *                                         LOCAL CONSTANTS
==================================================================================================*/
#define GPT_START_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"

/** @brief Table of base addresses for pTMR instances. */
GPT_CONST static volatile pTMR_Type * const Ptmr_Lld_Base[pTMR_INSTANCE_COUNT] = pTMR_BASE_PTRS;

#define GPT_STOP_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CONST_32
#include "Gpt_MemMap.h"

#if (pTMR_INSTANCE_COUNT == 1)
GPT_CONST static const uint32 pTMR_BASE_ADDR32[pTMR_INSTANCE_COUNT] = {pTMR0_BASE_ADDR32};
#endif

#if (pTMR_INSTANCE_COUNT == 3)
GPT_CONST static const uint32 pTMR_BASE_ADDR32[pTMR_INSTANCE_COUNT] = {pTMR0_BASE_ADDR32, pTMR1_BASE_ADDR32, pTMR2_BASE_ADDR32};
#endif

#define GPT_STOP_SEC_CONST_32
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
GPT_FUNC static void Gpt_Lld_Ptmr_CalcTimeElapsed(uint8 Instance, uint8 Channel,
    Ptmr_ValueType * ElapsedValuePtr, Ptmr_ValueType * RemainingValuePtr);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
 * @brief        Calculate time elapsed and remaining value
 * @param[in]    Instance Instance ID
 * @param[in]    Channel Channel ID
 * @param[out]   ElapsedValuePtr pointer to elapsed value
 * @param[out]   RemainingValuePtr pointer to remaining value
 * @return       void
 */
GPT_FUNC static void Gpt_Lld_Ptmr_CalcTimeElapsed(uint8 Instance, uint8 Channel, Ptmr_ValueType * ElapsedValuePtr, Ptmr_ValueType * RemainingValuePtr)
{
    /* Get current time stamp */
    Ptmr_ValueType CurrentTimeStamp = PTMR_REG_ADDR32_READ(pTMR_BASE_ADDR32[Instance] + pTMR_CH_TCV_OFFSET32((uint32)Channel));
    *ElapsedValuePtr = Ptmr_ChannelInfo[Instance][Channel].PeriodTickValue - CurrentTimeStamp;
    *RemainingValuePtr = CurrentTimeStamp;
}

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
 * @brief        Initialize pTMR instance
 * @param[in]    ConfigPtr pointer to configuration
 * @return       void
 */
GPT_FUNC void Gpt_Lld_Ptmr_InitInstance(const Ptmr_InstanceConfigType *ConfigPtr)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_07();
    /*
     *  MR12 RULE 2.2 VIOLATION: The value of pTMR_MCR_OFFSET32 is 0, remain the code to
     *  maintain stylistic consistency of register manipulation functions.
     */
    /* Disable pTMR module */
    PTMR_REG_ADDR32_CLEAR_BITS(pTMR_BASE_ADDR32[ConfigPtr->InstanceId] + pTMR_MCR_OFFSET32, pTMR_MCR_EN_MASK);   /* PRQA S 2985 */
    /* Config run or stop in debug mode */
    if (TRUE == ConfigPtr->StopInDebugMode)
    {
        PTMR_REG_ADDR32_SET_BITS(pTMR_BASE_ADDR32[ConfigPtr->InstanceId] + pTMR_MCR_OFFSET32, pTMR_MCR_FRZ_MASK);   /* PRQA S 2985 */
    }
    else
    {
        PTMR_REG_ADDR32_CLEAR_BITS(pTMR_BASE_ADDR32[ConfigPtr->InstanceId] + pTMR_MCR_OFFSET32, pTMR_MCR_FRZ_MASK);   /* PRQA S 2985 */
    }
    /* Enable pTMR module */
    PTMR_REG_ADDR32_SET_BITS(pTMR_BASE_ADDR32[ConfigPtr->InstanceId] + pTMR_MCR_OFFSET32, pTMR_MCR_EN_MASK);   /* PRQA S 2985 */
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_07();
}

/**
 * @brief        Initialize pTMR channel
 * @param[in]    ConfigPtr pointer to configuration
 * @return       void
 */
GPT_FUNC void Gpt_Lld_Ptmr_InitChannel(const Ptmr_ChannelConfigType *ConfigPtr)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_08();
    /* Disable channel and disable interrupt */
    PTMR_REG_ADDR32_CLEAR_BITS(pTMR_BASE_ADDR32[ConfigPtr->HwInstanceId] + pTMR_CH_TCR_OFFSET32((uint32)ConfigPtr->HwChannelId),
                               pTMR_CH_TCR_TEN_MASK |
                               pTMR_CH_TCR_TIE_MASK |
                               pTMR_CH_TCR_CHAIN_MASK);
    /* Clear interrupt flag */
    PTMR_REG_ADDR32_SET_BITS(pTMR_BASE_ADDR32[ConfigPtr->HwInstanceId] + pTMR_CH_TFR_OFFSET32((uint32)ConfigPtr->HwChannelId), pTMR_CH_TFR_TIF_MASK);
    Ptmr_ChannelInfo[ConfigPtr->HwInstanceId][ConfigPtr->HwChannelId].IsNotificationEnabled = FALSE;
    Ptmr_ChannelInfo[ConfigPtr->HwInstanceId][ConfigPtr->HwChannelId].NotificationPtr = ConfigPtr->NotificationPtr;
    Ptmr_ChannelInfo[ConfigPtr->HwInstanceId][ConfigPtr->HwChannelId].CountMode = ConfigPtr->CountMode;
    Ptmr_ChannelInfo[ConfigPtr->HwInstanceId][ConfigPtr->HwChannelId].State = PTMR_CHANNEL_STATE_INITIALIZED;
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_08();
}

/**
 * @brief       De-Initializes the pTMR instance.
 * @param[in]   Instance The pTMR instance id
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Ptmr_DeInitInstance(uint8 Instance)
{
    volatile pTMR_Type * const Base = Ptmr_Lld_Base[Instance];

    Base->MCR = 0U;
}

/**
 * @brief       De-Initializes the pTMR channel.
 * @param[in]   Instance The pTMR instance id
 * @param[in]   Channel The pTMR channel id
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Ptmr_DeInitChannel(uint8 Instance, uint8 Channel)
{
    volatile pTMR_Type * const Base = Ptmr_Lld_Base[Instance];

    Base->CH[Channel].TSV = 0U;
    Base->CH[Channel].TCV = 0U;
    Base->CH[Channel].TCR = 0U;
    /* Write 1 to clear the timer interrupt flag. */
    Base->CH[Channel].TFR = 1U;

    Ptmr_ChannelInfo[Instance][Channel].State = PTMR_CHANNEL_STATE_UNINIT;
    Ptmr_ChannelInfo[Instance][Channel].IsNotificationEnabled = FALSE;
    Ptmr_ChannelInfo[Instance][Channel].NotificationPtr = NULL_PTR;
    Ptmr_ChannelInfo[Instance][Channel].CountMode = PTMR_CH_MODE_CONTINUOUS;
    Ptmr_ChannelInfo[Instance][Channel].PeriodTickValue = 0U;
    Ptmr_ChannelInfo[Instance][Channel].StopValue = 0U;
}

/**
 * @brief        Start pTMR channel
 * @param[in]    Instance The pTMR instance id
 * @param[in]    Channel The pTMR channel ID
 * @param[in]    Value period value
 * @return       void
 */
GPT_FUNC void Gpt_Lld_Ptmr_StartChannel(uint8 Instance, uint8 Channel, Ptmr_ValueType Value)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_09();
    /* Disable channel */
    PTMR_REG_ADDR32_CLEAR_BITS
    (
        pTMR_BASE_ADDR32[Instance] + pTMR_CH_TCR_OFFSET32((uint32)Channel),
        pTMR_CH_TCR_TEN_MASK |
        pTMR_CH_TCR_CHAIN_MASK
    );
    /* Set period value */
    PTMR_REG_ADDR32_WRITE(pTMR_BASE_ADDR32[Instance] + pTMR_CH_TSV_OFFSET32((uint32)Channel), Value);
    Ptmr_ChannelInfo[Instance][Channel].PeriodTickValue = Value;
    /* Enable or disable interrupt */
    if (PTMR_CH_MODE_ONESHOT == Ptmr_ChannelInfo[Instance][Channel].CountMode)
    {
        PTMR_REG_ADDR32_SET_BITS(pTMR_BASE_ADDR32[Instance] + pTMR_CH_TCR_OFFSET32((uint32)Channel), pTMR_CH_TCR_TIE_MASK);
    }
    /* Enable timer channel */
    PTMR_REG_ADDR32_SET_BITS(pTMR_BASE_ADDR32[Instance] + pTMR_CH_TCR_OFFSET32((uint32)Channel), pTMR_CH_TCR_TEN_MASK);
    /* Update channel state to "runing" */
    Ptmr_ChannelInfo[Instance][Channel].State = PTMR_CHANNEL_STATE_RUNNING;
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_09();
}

/**
 * @brief        Stop pTMR channel
 * @param[in]    Instance The pTMR instance id
 * @param[in]    Channel The pTMR channel ID
 * @return       void
 */
GPT_FUNC void Gpt_Lld_Ptmr_StopChannel(uint8 Instance, uint8 Channel)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_10();
    Ptmr_ChannelInfo[Instance][Channel].StopValue = PTMR_REG_ADDR32_READ(pTMR_BASE_ADDR32[Instance] + pTMR_CH_TCV_OFFSET32((uint32)Channel));
    /* Disable timer channnel */
    PTMR_REG_ADDR32_CLEAR_BITS
    (
        pTMR_BASE_ADDR32[Instance] + pTMR_CH_TCR_OFFSET32((uint32)Channel),
        pTMR_CH_TCR_TIE_MASK |
        pTMR_CH_TCR_TEN_MASK
    );
    /* Update channel state to "stoped" */
    if (PTMR_CH_MODE_CONTINUOUS == Ptmr_ChannelInfo[Instance][Channel].CountMode)
    {
        Ptmr_ChannelInfo[Instance][Channel].State = PTMR_CHANNEL_STATE_STOPPED;
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_10();
}

/**
 * @brief        pTMR channel interrupt process
 * @param[in]    Instance The pTMR instance id
 * @param[in]    Channel The pTMR channel ID
 * @return       void
 */
GPT_FUNC void Gpt_Lld_Ptmr_ChannelIrqProcess(uint8 Instance, uint8 Channel)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_11();
    uint32 IntFlag = PTMR_REG_ADDR32_READ(pTMR_BASE_ADDR32[Instance] + pTMR_CH_TFR_OFFSET32(Channel));
    uint32 IntEnable = PTMR_REG_ADDR32_GET_BITS(pTMR_BASE_ADDR32[Instance] + pTMR_CH_TCR_OFFSET32(Channel), pTMR_CH_TCR_TIE_MASK) >> pTMR_CH_TCR_TIE_SHIFT;
    if ((1U == IntFlag) && (1U == IntEnable))
    {
        /* Clear interrupt flag */
        PTMR_REG_ADDR32_SET_BITS(pTMR_BASE_ADDR32[Instance] + pTMR_CH_TFR_OFFSET32((uint32)Channel), pTMR_CH_TFR_TIF_MASK);

        if (PTMR_CH_MODE_ONESHOT == Ptmr_ChannelInfo[Instance][Channel].CountMode)
        {
            /* Disable channel and disable interrupt */
            PTMR_REG_ADDR32_CLEAR_BITS(pTMR_BASE_ADDR32[Instance] + pTMR_CH_TCR_OFFSET32((uint32)Channel),
                                       pTMR_CH_TCR_TEN_MASK |
                                       pTMR_CH_TCR_TIE_MASK |
                                       pTMR_CH_TCR_CHAIN_MASK);
            /* Update channel state to expired */
            Ptmr_ChannelInfo[Instance][Channel].State = PTMR_CHANNEL_STATE_EXPIRED;
        }
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_11();
        /* Call Notifacation function */
        if (TRUE == Ptmr_ChannelInfo[Instance][Channel].IsNotificationEnabled)
        {
            if (NULL_PTR != Ptmr_ChannelInfo[Instance][Channel].NotificationPtr)
            {
                Ptmr_ChannelInfo[Instance][Channel].NotificationPtr();
            }
        }
    }
    else
    {
        SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_11();
    }
}

/**
 * @brief        Get pTMR channel time elapsed
 * @param[in]    Instance The pTMR instance id
 * @param[in]    Channel The pTMR channel ID
 * @return       Ptmr_ValueType time elapsed
 */
GPT_FUNC Ptmr_ValueType Gpt_Lld_Ptmr_GetChTimeElapsed(uint8 Instance, uint8 Channel)
{
    Ptmr_ValueType ElapsedValue = 0;
    Ptmr_ValueType RemainingValue = 0;

    switch (Ptmr_ChannelInfo[Instance][Channel].State)
    {
    case PTMR_CHANNEL_STATE_STOPPED:
        ElapsedValue = Ptmr_ChannelInfo[Instance][Channel].PeriodTickValue - Ptmr_ChannelInfo[Instance][Channel].StopValue;
        break;
    case PTMR_CHANNEL_STATE_EXPIRED:
        ElapsedValue = Ptmr_ChannelInfo[Instance][Channel].PeriodTickValue;
        break;
    case PTMR_CHANNEL_STATE_RUNNING:
        Gpt_Lld_Ptmr_CalcTimeElapsed(Instance, Channel, &ElapsedValue, &RemainingValue);
        break;
    default:
        /* Nothing to do */
        break;
    }

    return ElapsedValue;
}

/**
 * @brief        Get pTMR channel time remaining
 * @param[in]    Instance The pTMR instance id
 * @param[in]    Channel The pTMR channel ID
 * @return       Ptmr_ValueType time remaining
 */
GPT_FUNC Ptmr_ValueType Gpt_Lld_Ptmr_GetChTimeRemaining(uint8 Instance, uint8 Channel)
{
    Ptmr_ValueType ElapsedValue = 0U;
    Ptmr_ValueType RemainingValue = 0U;

    switch (Ptmr_ChannelInfo[Instance][Channel].State)
    {
    case PTMR_CHANNEL_STATE_STOPPED:
        RemainingValue = Ptmr_ChannelInfo[Instance][Channel].StopValue;
        break;
    case PTMR_CHANNEL_STATE_EXPIRED:
        RemainingValue = 0U;
        break;
    case PTMR_CHANNEL_STATE_RUNNING:
        Gpt_Lld_Ptmr_CalcTimeElapsed(Instance, Channel, &ElapsedValue, &RemainingValue);
        break;
    default:
        /* Nothing to do. */
        break;
    }

    return RemainingValue;
}

/**
 * @brief        Get pTMR channel state
 * @param[in]    Instance The pTMR instance id
 * @param[in]    Channel The pTMR channel ID
 * @return       Ptmr_ChannelStatesType channel state
 */
GPT_FUNC Ptmr_ChannelStatesType Gpt_Lld_Ptmr_GetTimerState(uint8 Instance, uint8 Channel)
{
    return Ptmr_ChannelInfo[Instance][Channel].State;
}

/**
 * @brief        Enable pTMR channel notification
 * @param[in]    Instance The pTMR instance id
 * @param[in]    Channel The pTMR channel ID
 * @return       void
 */
GPT_FUNC void Gpt_Lld_Ptmr_EnableNotification(uint8 Instance, uint8 Channel)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_12();
    /* Save notification enabled attribute */
    Ptmr_ChannelInfo[Instance][Channel].IsNotificationEnabled = TRUE;
    /* Enable interrupt */
    PTMR_REG_ADDR32_SET_BITS(pTMR_BASE_ADDR32[Instance] + pTMR_CH_TCR_OFFSET32((uint32)Channel), pTMR_CH_TCR_TIE_MASK);
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_12();
}

/**
 * @brief        Disable pTMR channel notification
 * @param[in]    Instance The pTMR instance id
 * @param[in]    Channel The pTMR channel ID
 * @return       void
 */
GPT_FUNC void Gpt_Lld_Ptmr_DisNotification(uint8 Instance, uint8 Channel)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_13();
    /* Save notification disable attribute */
    Ptmr_ChannelInfo[Instance][Channel].IsNotificationEnabled = FALSE;
    /* Disable interrupt
       Condition:
            1. Continuous mode
            2. OneShot mode: timer state is not running */
    if ((PTMR_CH_MODE_CONTINUOUS == Ptmr_ChannelInfo[Instance][Channel].CountMode) ||
            (PTMR_CHANNEL_STATE_RUNNING != Ptmr_ChannelInfo[Instance][Channel].State))
    {
        PTMR_REG_ADDR32_CLEAR_BITS(pTMR_BASE_ADDR32[Instance] + pTMR_CH_TCR_OFFSET32((uint32)Channel), pTMR_CH_TCR_TIE_MASK);
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_13();
}

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
 * @brief       This function sets the operation mode of the pTMR.
 * @param[in]   Mode GPT_MODE_NORMAL: Normal operation mode of the GPT driver.
 *                   GPT_MODE_SLEEP: Sleep mode of the GPT driver (wakeup capable).
 *                   See also Gpt_ModeType.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Ptmr_SetMode(Gpt_ModeType Mode)
{
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    if(GPT_MODE_SLEEP == Mode)
    {
        /*
         *  MR12 RULE 2.2 VIOLATION: When the chip is YTM32BIMD1 or ME0 or MC0, the value of pTMR_INSTANCE_COUNT is 1.
         *  When the chip is YTM32BIHA0, the value of pTMR_INSTANCE_COUNT is 3.
         *  Use the loop to make the code applicable to each chip.
         */
        for(uint8 Instance = 0; Instance < pTMR_INSTANCE_COUNT; ++Instance)    /* PRQA S 2877 */
        {
            for(uint8 Channel = 0; Channel < PTMR_CHANNEL_COUNT; ++Channel)
            {
                if(PTMR_CHANNEL_STATE_RUNNING == Ptmr_ChannelInfo[Instance][Channel].State )
                {
                    Gpt_Lld_Ptmr_StopChannel(Instance, Channel);
                    /* Clear interrupt flag */
                    PTMR_REG_ADDR32_SET_BITS(pTMR_BASE_ADDR32[Instance] + pTMR_CH_TFR_OFFSET32((uint32)Channel), pTMR_CH_TFR_TIF_MASK);
                }
            }
        }
    }
#endif /* GPT_REPORT_WAKEUP_SOURCE */
}
#endif

/**
 * @brief       This function gets the pTMR hardware instance configuration.
 * @param[in]   Instance The pTMR instance id
 * @param[in]   InstCfg The pointer to the configuration structure.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Ptmr_GetInstanceCfg(uint8 Instance, Ptmr_InstanceConfigType * const InstCfg)
{
    InstCfg->InstanceId = Instance;
    volatile uint32 Reg = 0U;
    pTMR_Type const volatile * Base = Ptmr_Lld_Base[Instance];

    Reg = Base->MCR;
    InstCfg->StopInDebugMode = (boolean)((Reg & pTMR_MCR_FRZ_MASK) >> pTMR_MCR_FRZ_SHIFT);
}

/**
 * @brief       This function gets the pTMR channel configuration.
 * @param[in]   Instance The pTMR instance id
 * @param[in]   Channel The pTMR channel id
 * @param[in]   ChCfg The pointer to the configuration structure.
 * @return      void
 */
GPT_FUNC void Gpt_Lld_Ptmr_GetChannelCfg(uint8 Instance, uint8 Channel, Ptmr_ChannelConfigType * const ChCfg)
{
    ChCfg->HwInstanceId = Instance;
    ChCfg->HwChannelId = Channel;
    ChCfg->CountMode = Ptmr_ChannelInfo[Instance][Channel].CountMode;
    ChCfg->EnableNotification = Ptmr_ChannelInfo[Instance][Channel].IsNotificationEnabled;
    ChCfg->NotificationPtr = Ptmr_ChannelInfo[Instance][Channel].NotificationPtr;
}

#ifdef __cplusplus
}
#endif

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

/** @} */

