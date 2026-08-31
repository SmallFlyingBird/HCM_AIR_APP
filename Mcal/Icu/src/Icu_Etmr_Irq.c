/**
* @file    Icu_Etmr_Irq.c
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Icu_Etmr_Irq
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/
#include "Platform_Types.h"
#ifdef __cplusplus
extern "C"
{
#endif
/**
 * @page misra_violations MISRA-C:2012 violations list
 * PRQA S 3415 Rule 13.5:Right hand operand of '&&' or '||' is an expression with persistent side effects.
 * PRQA S 2985 Rule 2.2: There shall be no dead code.
 */
/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "Icu_Lld_Etmr.h"
#include "Icu_Mld.h"
#include "Icu_Etmr_Irq.h"
#include "Icu_Cfg.h"
#include "Std_Types.h"
#include "OsIf.h"
/*==================================================================================================
                                      SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_ETMR_IRQ_VENDOR_ID_C                      (180)
#define ICU_ETMR_IRQ_AR_RELEASE_MAJOR_VERSION_C       (4)
#define ICU_ETMR_IRQ_AR_RELEASE_MINOR_VERSION_C       (4)
#define ICU_ETMR_IRQ_AR_RELEASE_REVISION_VERSION_C    (0)
#define ICU_ETMR_IRQ_SW_MAJOR_VERSION_C               (2)
#define ICU_ETMR_IRQ_SW_MINOR_VERSION_C               (3)
#define ICU_ETMR_IRQ_SW_PATCH_VERSION_C               (0)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ICU_IRQ header file are of the same vendor */
#if (ICU_ETMR_IRQ_VENDOR_ID_C != ICU_ETMR_IRQ_VENDOR_ID)
#error "Icu_Etmr_Irq.c and Icu_Etmr_Irq.h have different vendor ids"
#endif

/* Check if source file and ICU_IRQ header file are of the same Autosar version */
#if ((ICU_ETMR_IRQ_AR_RELEASE_MAJOR_VERSION_C != ICU_ETMR_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_ETMR_IRQ_AR_RELEASE_MINOR_VERSION_C != ICU_ETMR_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (ICU_ETMR_IRQ_AR_RELEASE_REVISION_VERSION_C != ICU_ETMR_IRQ_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu_Etmr_Irq.c and Icu_Etmr_Irq.h are different"
#endif

/* Check if source file and ICU_IRQ header file are of the same Software version */
#if ((ICU_ETMR_IRQ_SW_MAJOR_VERSION_C != ICU_EMR_IRQ_SW_MAJOR_VERSION) ||  \
     (ICU_ETMR_IRQ_SW_MINOR_VERSION_C != ICU_ETMR_IRQ_SW_MINOR_VERSION) || \
     (ICU_ETMR_IRQ_SW_PATCH_VERSION_C != ICU_ETMR_IRQ_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Etmr_Irq.c and Icu_Etmr_Irq.h are different"
#endif

/*==================================================================================================
                                                GLOBAL VARIABLES
==================================================================================================*/
#define ICU_START_SEC_CONST_UNSPECIFIED
#include "Icu_MemMap.h"
ICU_CONST volatile eTMR_Type *const Icu_Etmr_Common_gBaseAddress32[eTMR_INSTANCE_COUNT] = eTMR_BASE_PTRS;
#define ICU_STOP_SEC_CONST_UNSPECIFIED
#include "Icu_MemMap.h"
/*==================================================================================================
                                                LOCAL VARIABLES
==================================================================================================*/
/*==================================================================================================
                                                LOCAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
                                                LOCAL MACROS
==================================================================================================*/
/*==================================================================================================
                                                LOCAL FUNCTIONS
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
#if defined(CPU_YTM32B1MC0)
ICU_FUNC uint32 HwChannelToIcuChannel(uint16 InstanceId, uint16 EtmrChannelId)
{
    Icu_ConfigType const *ConfigPtr = Icu_gConfigPtr;

    uint16 ChannelIndex = (uint16)ConfigPtr->IcuChannelCount;
    uint16 HwChannelMap = (uint16)(((uint32)InstanceId << 8U) | EtmrChannelId);
    uint16 ChannelCount = 0;
    uint16 EtmrInstance = 0;
    uint16 EtmrChannel = 0;
    for (ChannelCount = 0; ChannelCount < ChannelIndex; ++ChannelCount)
    {
        if (ICU_ETMR == ConfigPtr->ChannelConfigPtr[ChannelCount].IcuHwIp)
        {
            EtmrInstance = ConfigPtr->ChannelConfigPtr[ChannelCount].IcuHwIpInstance;
            EtmrChannel = ConfigPtr->ChannelConfigPtr[ChannelCount].IcuHwChannel;
            if (HwChannelMap == (uint16)((uint16)(EtmrInstance << 8U) | EtmrChannel))
            {
                break;
            }
        }
    }
    return ChannelCount;
}
#endif
#if defined(CPU_YTM32B1ME0)
#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
ICU_FUNC static inline boolean CheckIoState(uint32 EtmrBaseAddress, uint8 EtmrChannelId)
{
    boolean IcuChannelIoPositiveFlag = FALSE;
    boolean IcuChannelIoNegativeFlag = FALSE;
    boolean IcuChannelIoState = FALSE;
    IcuChannelIoPositiveFlag = (boolean)ICU_ETMR_REG_ADDR32_INDEX_GET_BIT(EtmrBaseAddress + eTMR_STS_OFFSET32, /*PRQA S 2985*/
                               EtmrChannelId + eTMR_STS_CH0PPF_SHIFT);
    IcuChannelIoNegativeFlag = (boolean)ICU_ETMR_REG_ADDR32_INDEX_GET_BIT(EtmrBaseAddress + eTMR_STS_OFFSET32, /*PRQA S 2985*/
                               EtmrChannelId + eTMR_STS_CH0NPF_SHIFT);
    if (IcuChannelIoPositiveFlag != IcuChannelIoNegativeFlag)
    {
        if (TRUE == IcuChannelIoPositiveFlag)
        {
            IcuChannelIoState = 0;
        }
        else
        {
            IcuChannelIoState = 1;
        }
    }
    return IcuChannelIoState;
}
#endif
#endif
ICU_FUNC void EdgeCounterHandle(Icu_ChannelType UserDefineChannel)
{
    Icu_ChannelType EdgeCounterMaxValue = 0xffffU - 1U;
    if (Icu_gChannelInfo[UserDefineChannel].EdgeNumber <= EdgeCounterMaxValue)
    {
        ++Icu_gChannelInfo[UserDefineChannel].EdgeNumber;
    }
    else
    {
        Icu_gChannelInfo[UserDefineChannel].EdgeNumber = 0;
    }
}
#if (ICU_TIMESTAMP_API == STD_ON)
ICU_FUNC void TimeStampHandle(Icu_ChannelType UserDefineChannel, uint32 EtmrBaseAddress, uint8 McChannel)
{
    Icu_IndexType CurrentTimeStampIndex;
    uint32 TimeStampMod = 0;
    /* Get current timestamp index */
    CurrentTimeStampIndex = Etmr_Icu_TimeStampInfo[UserDefineChannel].TimestampIndex;
    /* Store the timestamp value */
    TimeStampMod = ICU_ETMR_REG_ADDR32_READ(EtmrBaseAddress + (uint32)eTMR_MOD_OFFSET32);

    Etmr_Icu_TimeStampInfo[UserDefineChannel].BufferPtr[CurrentTimeStampIndex] = Icu_gChannelInfo[UserDefineChannel].ActiveTime +
            (Icu_Etmr_Mc_gChannelInfo[McChannel].OverflowTimes * TimeStampMod);
    /* Timestamp index increase 1 */
    ++Etmr_Icu_TimeStampInfo[UserDefineChannel].TimestampIndex;
    /* Update input state to "ACTIVE" */
    Icu_gChannelInfo[UserDefineChannel].InputState = ICU_ACTIVE;
    /* Call notification */
    /* The Icu module shall only call a notification function if the
       notification has been configured enabled by the call of Icu_EnableNotification
       The Icu module shall only call a notification function if
       NotifyInterval is greater than [0]
       Trace : SWS_Icu_00134, SWS_Icu_00318, SWS_Icu_00319 */
    if ((TRUE == Etmr_Icu_TimeStampInfo[UserDefineChannel].IsNotificationEnable) &&
            (NULL_PTR != Etmr_Icu_TimeStampInfo[UserDefineChannel].TimestampNotificationPtr))
    {
        /* The Icu module shall only call a notification function if the
           number of events specified by NotifyInterval has been captured
           Trace : SWS_Icu_00320 */
        if (Etmr_Icu_TimeStampInfo[UserDefineChannel].NotifyInterval == Etmr_Icu_TimeStampInfo[UserDefineChannel].TimestampIndex)
        {
            (void)Etmr_Icu_TimeStampInfo[UserDefineChannel].TimestampNotificationPtr();
        }
        else
        {
            /* Do nothing */
        }
    }
    /* Estimate Timestamp index beyond the buffer size or not */
    if (Etmr_Icu_TimeStampInfo[UserDefineChannel].TimestampIndex >= Etmr_Icu_TimeStampInfo[UserDefineChannel].BufferSize)
    {
        /* If Timestamp index beyond the buffer size, assign the Timestamp index to 0 */
        Etmr_Icu_TimeStampInfo[UserDefineChannel].TimestampIndex = 0U;
        /* If linear buffer handling is configured, when the capture
           functionality reaches the end of the buffer, the Icu module shall stop capturing timer
           values
           Trace : SWS_Icu_00065*/
        if (ICU_LINEAR_BUFFER == Etmr_Icu_TimeStampInfo[UserDefineChannel].BufferType)
        {
            Icu_Mld_StopTimestamp(UserDefineChannel);
        }
    }
}
#endif

#if (ICU_EDGE_DETECT_API == STD_ON)
ICU_FUNC void SignalEdgeHandle(Icu_ChannelType UserDefineChannel)
{
    Icu_gChannelInfo[UserDefineChannel].InputState = ICU_ACTIVE;
    if ((TRUE == Etmr_Icu_gEdgeNotification[UserDefineChannel].IsNotificationEnable)
            && (NULL_PTR != Etmr_Icu_gEdgeNotification[UserDefineChannel].EdgeNotificationPtr))
    {
        (void)Etmr_Icu_gEdgeNotification[UserDefineChannel].EdgeNotificationPtr();
    }
}
#endif
#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
ICU_FUNC void SignalMeasurementHandle(Icu_ChannelType UserDefineChannel, uint32 EtmrBaseAddress, uint8 EtmrChannelId)
{
    boolean IcuChannelIoState = FALSE;
    uint32 ChannelMeasurementProperty;
#if defined (CPU_YTM32B1MC0)
    uint32 ChannelPeriodTime = 0;
#endif
#if defined(CPU_YTM32B1ME0)
    IcuChannelIoState = CheckIoState(EtmrBaseAddress, EtmrChannelId);
#else
    IcuChannelIoState = (boolean)ICU_ETMR_REG_ADDR32_INDEX_GET_BIT(EtmrBaseAddress + eTMR_IOSTS_OFFSET32, EtmrChannelId);
#endif
    ChannelMeasurementProperty = ICU_ETMR_REG_ADDR32_READ(EtmrBaseAddress + (uint32)eTMR_CH_CTRL_OFFSET32((uint32)EtmrChannelId));
    ChannelMeasurementProperty &= eTMR_CH_CTRL_CAPEDGE_MASK;
    ChannelMeasurementProperty >>= eTMR_CH_CTRL_CAPEDGE_SHIFT;

    Icu_gChannelInfo[UserDefineChannel].InputLevel = IcuChannelIoState;

    if (1U == Icu_gChannelInfo[UserDefineChannel].EdgeNumber)
    {
        if ((Icu_gChannelInfo[UserDefineChannel].InputLevel != STD_ON) && (ICU_RISING_EDGE == Icu_gChannelInfo[UserDefineChannel].StartEdge))
        {
            /* check set start edge is rising edge */
            Icu_gChannelInfo[UserDefineChannel].EdgeNumber = 0;
        }
        else if ((Icu_gChannelInfo[UserDefineChannel].InputLevel != STD_OFF) && (ICU_FALLING_EDGE == Icu_gChannelInfo[UserDefineChannel].StartEdge))
        {
            Icu_gChannelInfo[UserDefineChannel].EdgeNumber = 0;
        }
        else
        {
#if defined(CPU_YTM32B1MC0)
            Icu_gChannelInfo[UserDefineChannel].HighLevelMcOverflowTimes = 0U;
            Icu_gChannelInfo[UserDefineChannel].LowLevelMcOverflowTimes = 0U;
#endif
        }
    }
    if (((uint32)ICU_RISING_EDGE == ChannelMeasurementProperty) || ((uint32)ICU_FALLING_EDGE == ChannelMeasurementProperty))
    {
        /* Measurement Low time or High time */
        if (2U == (Icu_gChannelInfo[UserDefineChannel].EdgeNumber))
        {
            Icu_gChannelInfo[UserDefineChannel].InputState = ICU_ACTIVE;
        }
    }
    /* Measurement period time */
#if defined (CPU_YTM32B1MC0)
    else if ((uint32)ICU_BOTH_EDGES == ChannelMeasurementProperty)
    {
        /*MC0 Not support PPCNTV_PPCNTN,change to read CVAL*/
        Icu_ValueType CurrentChannelCval = ICU_ETMR_REG_ADDR32_READ(EtmrBaseAddress
                                           + (uint32)eTMR_CH_CVAL_OFFSET32((uint32)EtmrChannelId));
        Icu_ValueType IntervalTimes = 0;
       
        ChannelPeriodTime = ICU_ETMR_REG_ADDR32_READ(EtmrBaseAddress + eTMR_MOD_OFFSET32);
        if((ICU_ETMR_REG_ADDR32_INDEX_GET_BIT(EtmrBaseAddress + eTMR_STS_OFFSET32, eTMR_STS_TOF_SHIFT))||\
            (CurrentChannelCval<2000)||((ChannelPeriodTime-CurrentChannelCval))<2000)
        {
            /* Give up this measure, unstable */
            Icu_gChannelInfo[UserDefineChannel].InputState = ICU_IDLE;
            Icu_gChannelInfo[UserDefineChannel].EdgeNumber = 0;
        }
        IntervalTimes = CurrentChannelCval+ChannelPeriodTime*Icu_gChannelInfo[UserDefineChannel].HighLevelMcOverflowTimes-Icu_gChannelInfo[UserDefineChannel].EtmrChannelValue;

        if (2U == (Icu_gChannelInfo[UserDefineChannel].EdgeNumber))
        {
            Icu_gChannelInfo[UserDefineChannel].HighLevelMcOverflowTimes=0;
            if (TRUE == IcuChannelIoState)
            {
                Icu_gChannelInfo[UserDefineChannel].LowLevelTimes = IntervalTimes;
            }
            else
            {
                Icu_gChannelInfo[UserDefineChannel].HighLevelTimes = IntervalTimes;
            }
        }
        else if (3U == Icu_gChannelInfo[UserDefineChannel].EdgeNumber)
        {
            Icu_gChannelInfo[UserDefineChannel].InputState = ICU_ACTIVE;
            Icu_gChannelInfo[UserDefineChannel].HighLevelMcOverflowTimes=0;
            Icu_gChannelInfo[UserDefineChannel].LowLevelMcOverflowTimes=0;
            if (TRUE == IcuChannelIoState)
            {
                Icu_gChannelInfo[UserDefineChannel].LowLevelTimes = IntervalTimes;
            }
            else
            {
                Icu_gChannelInfo[UserDefineChannel].HighLevelTimes = IntervalTimes;
            }
        }
        Icu_gChannelInfo[UserDefineChannel].EtmrChannelValue = CurrentChannelCval;
    }
#else
    else if (((uint32)ICU_BOTH_EDGES == ChannelMeasurementProperty) && (3U == Icu_gChannelInfo[UserDefineChannel].EdgeNumber))
    {
        Icu_gChannelInfo[UserDefineChannel].InputState = ICU_ACTIVE;
        Icu_gChannelInfo[UserDefineChannel].HighLevelTimes = ICU_ETMR_REG_ADDR32_READ(EtmrBaseAddress +
                (uint32)eTMR_CH_PPCNTV_OFFSET32((uint32)EtmrChannelId));
        Icu_gChannelInfo[UserDefineChannel].LowLevelTimes = ICU_ETMR_REG_ADDR32_READ(EtmrBaseAddress +
                (uint32)eTMR_CH_NPCNTV_OFFSET32((uint32)EtmrChannelId));
        Icu_gChannelInfo[UserDefineChannel].HighLevelMcOverflowTimes = ICU_ETMR_REG_ADDR32_READ(EtmrBaseAddress +
                (uint32)eTMR_CH_PPCNTN_OFFSET32((uint32)EtmrChannelId));
        Icu_gChannelInfo[UserDefineChannel].LowLevelMcOverflowTimes = ICU_ETMR_REG_ADDR32_READ(EtmrBaseAddress +
                (uint32)eTMR_CH_NPCNTN_OFFSET32((uint32)EtmrChannelId));
    }
#endif
    else
    {
        /* Do nothing */
    }
}
#endif

#if(defined(ICU_ETMR_0_CH_0_IRQ_ENABLE) || defined(ICU_ETMR_0_CH_1_IRQ_ENABLE) || \
    defined(ICU_ETMR_0_CH_2_IRQ_ENABLE) || defined(ICU_ETMR_0_CH_3_IRQ_ENABLE) || \
    defined(ICU_ETMR_0_CH_4_IRQ_ENABLE) || defined(ICU_ETMR_0_CH_5_IRQ_ENABLE) || \
    defined(ICU_ETMR_0_CH_6_IRQ_ENABLE) || defined(ICU_ETMR_0_CH_7_IRQ_ENABLE) || \
    \
    defined(ICU_ETMR_1_CH_0_IRQ_ENABLE) || defined(ICU_ETMR_1_CH_1_IRQ_ENABLE) || \
    defined(ICU_ETMR_1_CH_2_IRQ_ENABLE) || defined(ICU_ETMR_1_CH_3_IRQ_ENABLE) || \
    defined(ICU_ETMR_1_CH_4_IRQ_ENABLE) || defined(ICU_ETMR_1_CH_5_IRQ_ENABLE) || \
    defined(ICU_ETMR_1_CH_6_IRQ_ENABLE) || defined(ICU_ETMR_1_CH_7_IRQ_ENABLE) || \
    \
    defined(ICU_ETMR_2_CH_0_IRQ_ENABLE) || defined(ICU_ETMR_2_CH_1_IRQ_ENABLE) || \
    defined(ICU_ETMR_2_CH_2_IRQ_ENABLE) || defined(ICU_ETMR_2_CH_3_IRQ_ENABLE) || \
    defined(ICU_ETMR_2_CH_4_IRQ_ENABLE) || defined(ICU_ETMR_2_CH_5_IRQ_ENABLE) || \
    defined(ICU_ETMR_2_CH_6_IRQ_ENABLE) || defined(ICU_ETMR_2_CH_7_IRQ_ENABLE) || \
    \
    defined(ICU_ETMR_3_CH_0_IRQ_ENABLE) || defined(ICU_ETMR_3_CH_1_IRQ_ENABLE) || \
    defined(ICU_ETMR_3_CH_2_IRQ_ENABLE) || defined(ICU_ETMR_3_CH_3_IRQ_ENABLE) || \
    defined(ICU_ETMR_3_CH_4_IRQ_ENABLE) || defined(ICU_ETMR_3_CH_5_IRQ_ENABLE) || \
    defined(ICU_ETMR_3_CH_6_IRQ_ENABLE) || defined(ICU_ETMR_3_CH_7_IRQ_ENABLE) || \
    \
    defined(ICU_ETMR_4_CH_0_IRQ_ENABLE) || defined(ICU_ETMR_4_CH_1_IRQ_ENABLE) || \
    defined(ICU_ETMR_4_CH_2_IRQ_ENABLE) || defined(ICU_ETMR_4_CH_3_IRQ_ENABLE) || \
    defined(ICU_ETMR_4_CH_4_IRQ_ENABLE) || defined(ICU_ETMR_4_CH_5_IRQ_ENABLE) || \
    defined(ICU_ETMR_4_CH_6_IRQ_ENABLE) || defined(ICU_ETMR_4_CH_7_IRQ_ENABLE) || \
    \
    defined(ICU_ETMR_5_CH_0_IRQ_ENABLE) || defined(ICU_ETMR_5_CH_1_IRQ_ENABLE) || \
    defined(ICU_ETMR_5_CH_2_IRQ_ENABLE) || defined(ICU_ETMR_5_CH_3_IRQ_ENABLE) || \
    defined(ICU_ETMR_5_CH_4_IRQ_ENABLE) || defined(ICU_ETMR_5_CH_5_IRQ_ENABLE) || \
    defined(ICU_ETMR_5_CH_6_IRQ_ENABLE) || defined(ICU_ETMR_5_CH_7_IRQ_ENABLE))
ICU_FUNC static void EtmrIcullChannelIrqProcess(uint8 McChannel, uint8 CCChannelGroup)
{
    uint32 EtmrBaseAddress = (uint32)Icu_Etmr_Common_gBaseAddress32[McChannel];
    uint8 EtmrChannelId = (uint8)(CCChannelGroup << 1U);
    Icu_ChannelType UserDefineChannel;
    uint32 ChannelFunctionMode;
    Icu_MeasurementModeType ChannelMeasurementMode = ICU_MODE_EDGE_COUNTER;

    /* Check odd channel and oven channel */
    for (uint8 ChannelIndex = 0; ChannelIndex < 2U; ++ChannelIndex)
    {
        EtmrChannelId += ChannelIndex;
        if (0U != ICU_ETMR_REG_ADDR32_INDEX_GET_BIT(EtmrBaseAddress + eTMR_STS_OFFSET32, EtmrChannelId)) /*PRQA S 2985*/
        {
            ChannelFunctionMode = ICU_ETMR_REG_ADDR32_GET_BITS(EtmrBaseAddress + (uint32)eTMR_CH_CTRL_OFFSET32((uint32)EtmrChannelId),
                                  eTMR_CH_CTRL_CHMODE_MASK >> (uint32)eTMR_CH_CTRL_CHMODE_SHIFT);
            /* Channel set as Icu mode */
            if (ETMR_FUNCTION_MODE_ICU == (Icu_Etmr_ChannelFunctionModeType)ChannelFunctionMode)
            {

                /* Map hardware channel to user define channel */
                UserDefineChannel = Etmr_Icu_gHwToUserChannelMap[McChannel][EtmrChannelId];

                /* update active timestamp */
                Icu_gChannelInfo[UserDefineChannel].ActiveTime = \
                        ICU_ETMR_REG_ADDR32_READ(EtmrBaseAddress + (uint32)eTMR_CH_CVAL_OFFSET32((uint32)EtmrChannelId));
                /* Increase edge counter */
                ++Icu_gChannelInfo[UserDefineChannel].EdgeNumber;

                ChannelMeasurementMode = Icu_gConfigPtr->ChannelConfigPtr[UserDefineChannel].IcuMeasurementMode;

                switch (ChannelMeasurementMode)
                {
#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
                    /* Do something in Signal Measurement Mode */
                    case ICU_MODE_SIGNAL_MEASUREMENT:
                        /* Get current channel IO state */
                        SignalMeasurementHandle(UserDefineChannel, EtmrBaseAddress, EtmrChannelId);
                        break;
#endif /* (ICU_TIMESTAMP_API == STD_ON) */
#if (ICU_TIMESTAMP_API == STD_ON)
                    case ICU_MODE_TIMESTAMP:
                        TimeStampHandle(UserDefineChannel, EtmrBaseAddress, McChannel);
                        break;
#endif /* (ICU_TIMESTAMP_API == STD_ON) */
#if (ICU_EDGE_DETECT_API == STD_ON)
                    case ICU_MODE_SIGNAL_EDGE_DETECT:
                        SignalEdgeHandle(UserDefineChannel);
                        break;
#endif                       /* (ICU_EDGE_DETECT_API == STD_ON) */
                    default: /* ICU_MODE_EDGE_COUNTER */
                        EdgeCounterHandle(UserDefineChannel);
                        break;
                }
            }
            /* Map hardware channel to user define channel */
            UserDefineChannel = Etmr_Icu_gHwToUserChannelMap[McChannel][EtmrChannelId];
            (void)UserDefineChannel;
            (void)ChannelMeasurementMode;
            /* Clear interrupt flag */
            ICU_ETMR_REG_ADDR32_WRITE(EtmrBaseAddress + (uint32)eTMR_STS_OFFSET32,    /*PRQA S 2985*/
                                      ((uint32)eTMR_STS_CH0F_MASK << EtmrChannelId)
#if defined(CPU_YTM32B1ME0)
                                      | ((uint32)eTMR_STS_CH0PPF_MASK << EtmrChannelId)
                                      | ((uint32)eTMR_STS_CH0NPF_MASK << EtmrChannelId)
#endif
                                     );
        }
    }
}
ICU_FUNC static void EtmrMc_ChannelIrqProcess(uint16 InstanceId)
{
    uint32 EtmrBaseAddress = (uint32)Icu_Etmr_Common_gBaseAddress32[InstanceId];
    if(ICU_ETMR_REG_ADDR32_INDEX_GET_BIT(EtmrBaseAddress + eTMR_STS_OFFSET32, eTMR_STS_TOF_SHIFT))
    {
        ++Icu_Etmr_Mc_gChannelInfo[InstanceId].OverflowTimes;
#if defined(CPU_YTM32B1MC0)
        for (uint16 ChannelCount = 0; ChannelCount < ETMR_ICU_CHANNEL_COUNT; ++ChannelCount)
        {
            if (0U != ICU_ETMR_REG_ADDR32_INDEX_GET_BIT(EtmrBaseAddress + eTMR_INTE_OFFSET32, ChannelCount))
            {
                uint32 ChannelIndex = HwChannelToIcuChannel(InstanceId, ChannelCount);
                ++Icu_gChannelInfo[ChannelIndex].HighLevelMcOverflowTimes;
            }
        }
#endif
        if (ETMR_MC_CH_MODE_ONESHOT == Icu_Etmr_Mc_gChannelInfo[InstanceId].CountMode)
        {
            /* Disable channel and disable interrupt */
            /* Disable timer channel */
            ICU_ETMR_REG_ADDR32_CLEAR_BITS(EtmrBaseAddress + eTMR_CTRL_OFFSET32, eTMR_CTRL_EN_MASK);
            /* Update channel state to expired */
            Icu_Etmr_Mc_gChannelInfo[InstanceId].State = ETMR_MC_CHANNEL_STATE_EXPIRED;
        }

        /* Clear overflow interrupt flag */
        ICU_ETMR_REG_ADDR32_WRITE(EtmrBaseAddress + eTMR_STS_OFFSET32, eTMR_STS_TOF_MASK); /*PRQA S 2985*/
    }
}
#endif
/*==================================================================================================
                                                GLOBAL FUNCTIONS
==================================================================================================*/

/* eTMR0 Interrupt ISRs */
#if (defined(ICU_ETMR_0_CH_0_IRQ_ENABLE) || defined(ICU_ETMR_0_CH_1_IRQ_ENABLE) || \
     defined(ICU_ETMR_0_CH_2_IRQ_ENABLE) || defined(ICU_ETMR_0_CH_3_IRQ_ENABLE) || \
     defined(ICU_ETMR_0_CH_4_IRQ_ENABLE) || defined(ICU_ETMR_0_CH_5_IRQ_ENABLE) || \
     defined(ICU_ETMR_0_CH_6_IRQ_ENABLE) || defined(ICU_ETMR_0_CH_7_IRQ_ENABLE))

ICU_FUNC ISR(eTMR0_Ovf_IRQHandler)
{
    EtmrMc_ChannelIrqProcess(0);
}
#endif

#if (defined(ICU_ETMR_0_CH_0_IRQ_ENABLE) || defined(ICU_ETMR_0_CH_1_IRQ_ENABLE))
ICU_FUNC ISR(eTMR0_Ch0_Ch1_IRQHandler)
{
    EtmrIcullChannelIrqProcess(0, 0);
}
#endif

#if (defined(ICU_ETMR_0_CH_2_IRQ_ENABLE) || defined(ICU_ETMR_0_CH_3_IRQ_ENABLE))
ICU_FUNC ISR(eTMR0_Ch2_Ch3_IRQHandler)
{
    EtmrIcullChannelIrqProcess(0, 1);
}
#endif

#if (defined(ICU_ETMR_0_CH_4_IRQ_ENABLE) || defined(ICU_ETMR_0_CH_5_IRQ_ENABLE))
ICU_FUNC ISR(eTMR0_Ch4_Ch5_IRQHandler)
{
    EtmrIcullChannelIrqProcess(0, 2);
}
#endif

#if (defined(ICU_ETMR_0_CH_6_IRQ_ENABLE) || defined(ICU_ETMR_0_CH_7_IRQ_ENABLE))
ICU_FUNC ISR(eTMR0_Ch6_Ch7_IRQHandler)
{
    EtmrIcullChannelIrqProcess(0, 3);
}
#endif

/* eTMR1 Interrupt ISRs */
#if (defined(ICU_ETMR_1_CH_0_IRQ_ENABLE) || defined(ICU_ETMR_1_CH_1_IRQ_ENABLE) || \
     defined(ICU_ETMR_1_CH_2_IRQ_ENABLE) || defined(ICU_ETMR_1_CH_3_IRQ_ENABLE) || \
     defined(ICU_ETMR_1_CH_4_IRQ_ENABLE) || defined(ICU_ETMR_1_CH_5_IRQ_ENABLE) || \
     defined(ICU_ETMR_1_CH_6_IRQ_ENABLE) || defined(ICU_ETMR_1_CH_7_IRQ_ENABLE))
ICU_FUNC ISR(eTMR1_Ovf_IRQHandler)
{
    EtmrMc_ChannelIrqProcess(1);
}
#endif

#if (defined(ICU_ETMR_1_CH_0_IRQ_ENABLE) || defined(ICU_ETMR_1_CH_1_IRQ_ENABLE))
ICU_FUNC ISR(eTMR1_Ch0_Ch1_IRQHandler)
{
    EtmrIcullChannelIrqProcess(1, 0);
}
#endif

#if (defined(ICU_ETMR_1_CH_2_IRQ_ENABLE) || defined(ICU_ETMR_1_CH_3_IRQ_ENABLE))
ICU_FUNC ISR(eTMR1_Ch2_Ch3_IRQHandler)
{
    EtmrIcullChannelIrqProcess(1, 1);
}
#endif
#if (defined(ICU_ETMR_1_CH_4_IRQ_ENABLE) || defined(ICU_ETMR_1_CH_5_IRQ_ENABLE))
ICU_FUNC ISR(eTMR1_Ch4_Ch5_IRQHandler)
{
    EtmrIcullChannelIrqProcess(1, 2);
}

#endif

#if (defined(ICU_ETMR_1_CH_6_IRQ_ENABLE) || defined(ICU_ETMR_1_CH_7_IRQ_ENABLE))
ICU_FUNC ISR(eTMR1_Ch6_Ch7_IRQHandler)
{
    EtmrIcullChannelIrqProcess(1, 3);
}
#endif

/* eTMR2 Interrupt ISRs */
#if (defined(ICU_ETMR_2_CH_0_IRQ_ENABLE) || defined(ICU_ETMR_2_CH_1_IRQ_ENABLE) || \
     defined(ICU_ETMR_2_CH_2_IRQ_ENABLE) || defined(ICU_ETMR_2_CH_3_IRQ_ENABLE) || \
     defined(ICU_ETMR_2_CH_4_IRQ_ENABLE) || defined(ICU_ETMR_2_CH_5_IRQ_ENABLE) || \
     defined(ICU_ETMR_2_CH_6_IRQ_ENABLE) || defined(ICU_ETMR_2_CH_7_IRQ_ENABLE))
ICU_FUNC ISR(eTMR2_Ovf_IRQHandler)
{
    EtmrMc_ChannelIrqProcess(2);
}
#endif

#if (defined(ICU_ETMR_2_CH_0_IRQ_ENABLE) || defined(ICU_ETMR_2_CH_1_IRQ_ENABLE))
ICU_FUNC ISR(eTMR2_Ch0_Ch1_IRQHandler)
{
    EtmrIcullChannelIrqProcess(2, 0);
}
#endif

#if (defined(ICU_ETMR_2_CH_2_IRQ_ENABLE) || defined(ICU_ETMR_2_CH_3_IRQ_ENABLE))
ICU_FUNC ISR(eTMR2_Ch2_Ch3_IRQHandler)
{
    EtmrIcullChannelIrqProcess(2, 1);
}
#endif
#if (defined(ICU_ETMR_2_CH_4_IRQ_ENABLE) || defined(ICU_ETMR_2_CH_5_IRQ_ENABLE))
ICU_FUNC ISR(eTMR2_Ch4_Ch5_IRQHandler)
{
    EtmrIcullChannelIrqProcess(2, 2);
}
#endif

#if (defined(ICU_ETMR_2_CH_6_IRQ_ENABLE) || defined(ICU_ETMR_2_CH_7_IRQ_ENABLE))
ICU_FUNC ISR(eTMR2_Ch6_Ch7_IRQHandler)
{
    EtmrIcullChannelIrqProcess(2, 3);
}
#endif

/* eTMR3 Interrupt ISRs */
#if (defined(ICU_ETMR_3_CH_0_IRQ_ENABLE) || defined(ICU_ETMR_3_CH_1_IRQ_ENABLE) || \
     defined(ICU_ETMR_3_CH_2_IRQ_ENABLE) || defined(ICU_ETMR_3_CH_3_IRQ_ENABLE) || \
     defined(ICU_ETMR_3_CH_4_IRQ_ENABLE) || defined(ICU_ETMR_3_CH_5_IRQ_ENABLE) || \
     defined(ICU_ETMR_3_CH_6_IRQ_ENABLE) || defined(ICU_ETMR_3_CH_7_IRQ_ENABLE))
ICU_FUNC ISR(eTMR3_Ovf_IRQHandler)
{
    EtmrMc_ChannelIrqProcess(3);
}
#endif

#if (defined(ICU_ETMR_3_CH_0_IRQ_ENABLE) || defined(ICU_ETMR_3_CH_1_IRQ_ENABLE))
ICU_FUNC ISR(eTMR3_Ch0_Ch1_IRQHandler)
{
    EtmrIcullChannelIrqProcess(3, 0);
}
#endif

#if (defined(ICU_ETMR_3_CH_2_IRQ_ENABLE) || defined(ICU_ETMR_3_CH_3_IRQ_ENABLE))
ICU_FUNC ISR(eTMR3_Ch2_Ch3_IRQHandler)
{
    EtmrIcullChannelIrqProcess(3, 1);
}
#endif

#if (defined(ICU_ETMR_3_CH_4_IRQ_ENABLE) || defined(ICU_ETMR_3_CH_5_IRQ_ENABLE))
ICU_FUNC ISR(eTMR3_Ch4_Ch5_IRQHandler)
{
    EtmrIcullChannelIrqProcess(3, 2);
}
#endif

#if (defined(ICU_ETMR_3_CH_6_IRQ_ENABLE) || defined(ICU_ETMR_3_CH_7_IRQ_ENABLE))
ICU_FUNC ISR(eTMR3_Ch6_Ch7_IRQHandler)
{
    EtmrIcullChannelIrqProcess(3, 3);
}
#endif
#if defined(CPU_YTM32B1ME0) || defined(CPU_YTM32B1HA0)
/* eTMR4 Interrupt ISRs */
#if (defined(ICU_ETMR_4_CH_0_IRQ_ENABLE) || defined(ICU_ETMR_4_CH_1_IRQ_ENABLE) || \
     defined(ICU_ETMR_4_CH_2_IRQ_ENABLE) || defined(ICU_ETMR_4_CH_3_IRQ_ENABLE) || \
     defined(ICU_ETMR_4_CH_4_IRQ_ENABLE) || defined(ICU_ETMR_4_CH_5_IRQ_ENABLE) || \
     defined(ICU_ETMR_4_CH_6_IRQ_ENABLE) || defined(ICU_ETMR_4_CH_7_IRQ_ENABLE))
ISR(eTMR4_Ovf_IRQHandler)
{
    EtmrMc_ChannelIrqProcess(4);
}
#endif
#if (defined(ICU_ETMR_4_CH_0_IRQ_ENABLE) || defined(ICU_ETMR_4_CH_1_IRQ_ENABLE))
ICU_FUNC ISR(eTMR4_Ch0_Ch1_IRQHandler)
{
    EtmrIcullChannelIrqProcess(4, 0);
}
#endif

#if (defined(ICU_ETMR_4_CH_2_IRQ_ENABLE) || defined(ICU_ETMR_4_CH_3_IRQ_ENABLE))
ICU_FUNC ISR(eTMR4_Ch2_Ch3_IRQHandler)
{
    EtmrIcullChannelIrqProcess(4, 1);
}
#endif

#if (defined(ICU_ETMR_4_CH_4_IRQ_ENABLE) || defined(ICU_ETMR_4_CH_5_IRQ_ENABLE))
ICU_FUNC ISR(eTMR4_Ch4_Ch5_IRQHandler)
{
    EtmrIcullChannelIrqProcess(4, 2);
}
#endif

#if (defined(ICU_ETMR_4_CH_6_IRQ_ENABLE) || defined(ICU_ETMR_4_CH_7_IRQ_ENABLE))
ICU_FUNC ISR(eTMR4_Ch6_Ch7_IRQHandler)
{
    EtmrIcullChannelIrqProcess(4, 3);
}
#endif
/* eTMR5 Interrupt ISRs */
#if (defined(ICU_ETMR_5_CH_0_IRQ_ENABLE) || defined(ICU_ETMR_5_CH_1_IRQ_ENABLE) || \
     defined(ICU_ETMR_5_CH_2_IRQ_ENABLE) || defined(ICU_ETMR_5_CH_3_IRQ_ENABLE) || \
     defined(ICU_ETMR_5_CH_4_IRQ_ENABLE) || defined(ICU_ETMR_5_CH_5_IRQ_ENABLE) || \
     defined(ICU_ETMR_5_CH_6_IRQ_ENABLE) || defined(ICU_ETMR_5_CH_7_IRQ_ENABLE))
ICU_FUNC ISR(eTMR5_Ovf_IRQHandler)
{
    EtmrMc_ChannelIrqProcess(5);
}
#endif
#if (defined(ICU_ETMR_5_CH_0_IRQ_ENABLE) || defined(ICU_ETMR_5_CH_1_IRQ_ENABLE))
ICU_FUNC ISR(eTMR5_Ch0_Ch1_IRQHandler)
{
    EtmrIcullChannelIrqProcess(5, 0);
}
#endif

#if (defined(ICU_ETMR_5_CH_2_IRQ_ENABLE) || defined(ICU_ETMR_5_CH_3_IRQ_ENABLE))
ICU_FUNC ISR(eTMR5_Ch2_Ch3_IRQHandler)
{
    EtmrIcullChannelIrqProcess(5, 1);
}
#endif

#if (defined(ICU_ETMR_5_CH_4_IRQ_ENABLE) || defined(ICU_ETMR_5_CH_5_IRQ_ENABLE))
ICU_FUNC ISR(eTMR5_Ch4_Ch5_IRQHandler)
{
    EtmrIcullChannelIrqProcess(5, 2);
}
#endif

#if (defined(ICU_ETMR_5_CH_6_IRQ_ENABLE) || defined(ICU_ETMR_5_CH_7_IRQ_ENABLE))
ICU_FUNC ISR(eTMR5_Ch6_Ch7_IRQHandler)
{
    EtmrIcullChannelIrqProcess(5, 3);
}
#endif
#endif

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif

/* End of file Icu_Etmr_Irq.c */

