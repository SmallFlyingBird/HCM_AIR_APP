/**
* @file    Icu_Port_Irq.c
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Icu_Port_Irq
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
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
                                              INCLUDE FILES
==================================================================================================*/
#include "Icu_Port_Irq.h"
#include "Icu_Lld_Port.h"
#include "Icu.h"
#include "Std_Types.h"
#include "OsIf.h"
/*==================================================================================================
                                      SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_PORT_IRQ_VENDOR_ID_C                      (180)
#define ICU_PORT_IRQ_AR_RELEASE_MAJOR_VERSION_C       (4)
#define ICU_PORT_IRQ_AR_RELEASE_MINOR_VERSION_C       (4)
#define ICU_PORT_IRQ_AR_RELEASE_REVISION_VERSION_C    (0)
#define ICU_PORT_IRQ_SW_MAJOR_VERSION_C               (2)
#define ICU_PORT_IRQ_SW_MINOR_VERSION_C               (3)
#define ICU_PORT_IRQ_SW_PATCH_VERSION_C               (0)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ICU_PORT_IRQ header file are of the same vendor */
#if (ICU_PORT_IRQ_VENDOR_ID_C != ICU_PORT_IRQ_VENDOR_ID)
#error "Icu_Port_Irq.c and Icu_Port_Irq.h have different vendor ids"
#endif

/* Check if source file and ICU_PORT_IRQ header file are of the same Autosar version */
#if ((ICU_PORT_IRQ_AR_RELEASE_MAJOR_VERSION_C != ICU_PORT_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_PORT_IRQ_AR_RELEASE_MINOR_VERSION_C != ICU_PORT_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (ICU_PORT_IRQ_AR_RELEASE_REVISION_VERSION_C != ICU_PORT_IRQ_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu_Port_Irq.c and Icu_Port_Irq.h are different"
#endif

/* Check if source file and ICU_PORT_IRQ header file are of the same Software version */
#if ((ICU_PORT_IRQ_SW_MAJOR_VERSION_C != ICU_PORT_IRQ_SW_MAJOR_VERSION) || \
     (ICU_PORT_IRQ_SW_MINOR_VERSION_C != ICU_PORT_IRQ_SW_MINOR_VERSION) || \
     (ICU_PORT_IRQ_SW_PATCH_VERSION_C != ICU_PORT_IRQ_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Port_Irq.c and Icu_Port_Irq.h are different"
#endif

/*==================================================================================================
                                                GLOBAL VARIABLES
==================================================================================================*/
#if (defined(ICU_PORT_0_IRQ_ENABLE) || defined(ICU_PORT_1_IRQ_ENABLE) || defined(ICU_PORT_2_IRQ_ENABLE) || defined(ICU_PORT_3_IRQ_ENABLE) || defined(ICU_PORT_4_IRQ_ENABLE))
static void IcuPortIrqProcess(uint8 PortId);
#endif
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
#if (defined(ICU_PORT_0_IRQ_ENABLE) || defined(ICU_PORT_1_IRQ_ENABLE) || defined(ICU_PORT_2_IRQ_ENABLE) || defined(ICU_PORT_3_IRQ_ENABLE) || defined(ICU_PORT_4_IRQ_ENABLE))
ICU_FUNC static inline void Icu_PinIrqProcess(uint8 PortId, uint8 PortHwId, uint8 PinHwId, uint32 ChannelIndex)
{
    if (PortId == PortHwId)
    {
        /* Get pinHwId interrupt flag */
        if ((uint32)STD_OFF != Icu_Lld_GetGPIOPinIntFlag(PortHwId, PinHwId))
        {
            Icu_ReportWakeup(ChannelIndex);
            /* Call notification function */
            if ((NULL_PTR != Icu_Port_Notification[ChannelIndex].EdgeNotificationPtr) && \
                    (TRUE == Icu_Port_Notification[ChannelIndex].IsNotificationEnable))
            {
                (void)Icu_Port_Notification[ChannelIndex].EdgeNotificationPtr();
            }
        }
        else
        {
            /* nothing to do */
        }
        /* Clear interrupt flag */
        Icu_Lld_CleanGPIOPinIntFlag(PortHwId, PinHwId);
    }
}
#endif
/*==================================================================================================
                                                GLOBAL FUNCTIONS
==================================================================================================*/
#if defined(ICU_PORT_0_IRQ_ENABLE)
ICU_FUNC ISR(GPIOA_IRQHandler)
{
    IcuPortIrqProcess((uint8)ICU_PORTA);
}
#endif

#if defined(ICU_PORT_1_IRQ_ENABLE)
ICU_FUNC ISR(GPIOB_IRQHandler)
{
    IcuPortIrqProcess((uint8)ICU_PORTB);
}
#endif

#if defined(ICU_PORT_2_IRQ_ENABLE)
ICU_FUNC ISR(GPIOC_IRQHandler)
{
    IcuPortIrqProcess((uint8)ICU_PORTC);
}
#endif

#if defined(ICU_PORT_3_IRQ_ENABLE)
ICU_FUNC ISR(GPIOD_IRQHandler)
{
    IcuPortIrqProcess((uint8)ICU_PORTD);
}
#endif

#if defined(ICU_PORT_4_IRQ_ENABLE)
ICU_FUNC ISR(GPIOE_IRQHandler)
{
    IcuPortIrqProcess((uint8)ICU_PORTE);
}
#endif
#if (defined(ICU_PORT_0_IRQ_ENABLE) || defined(ICU_PORT_1_IRQ_ENABLE) || defined(ICU_PORT_2_IRQ_ENABLE) || defined(ICU_PORT_3_IRQ_ENABLE) || defined(ICU_PORT_4_IRQ_ENABLE))
ICU_FUNC static void IcuPortIrqProcess(uint8 PortId)
{
    uint8 PortHwId;
    uint8 PinHwId;
    Icu_ChannelConfigType const *ChannelConfigPtr = Icu_gConfigPtr->ChannelConfigPtr;
    uint32 ChannelCount = Icu_gConfigPtr->IcuChannelCount;

    for (uint32 ChannelIndex = 0; ChannelIndex < ChannelCount; ++ChannelIndex)
    {
        if (ICU_PORT == ChannelConfigPtr->IcuHwIp)
        {
            PortHwId = (uint8)ChannelConfigPtr->IcuHwIpInstance;
            PinHwId = (uint8)ChannelConfigPtr->IcuHwChannel;

            Icu_PinIrqProcess(PortId, PortHwId, PinHwId, ChannelIndex);
        }
        ++ChannelConfigPtr;
    }
}
#endif

#if WKU_SUPPORT == STD_ON
ICU_FUNC ISR(WKU_IRQHandler)
{
#if defined(CPU_YTM32B1ME0) || defined(CPU_YTM32B1MD1)
    uint8 RegionNum = 1;
    uint32 WKUFlag[1] = {0};
#elif defined(CPU_YTM32B1HA0)
    uint8 RegionNum = 2;
    uint32 WKUFlag[2] = {0};
#endif

    if (Icu_gConfigPtr->IcuWakeUpNotificationPtr != NULL_PTR)
    {
        for (uint8 Index = 0; Index < RegionNum; ++Index)
        {
            WKUFlag[Index] = Icu_Lld_GetWakeUpFlag(Index);
        }
        Icu_gConfigPtr->IcuWakeUpNotificationPtr(WKUFlag, RegionNum, 0);
    }
    else
    {
        /* nothing to do */
    }
    Icu_Lld_ClearWakeupFlag();
}
#endif

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif

/* End of file Icu_Port_Irq.c */

