/**
* @file    Icu_Lld_Port.c
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Icu_Lld_Port
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
/**
 * @page misra_violations MISRA-C:2012 violations list
 * PRQA S 0488 Rule 18.4: The +, -, += and -= operators sho uld not be applied to anexpression of pointer type
 * PRQA S 2985 Rule 2.2: There shall be no dead code.
 *
 * PRQA S 2986 Rule 2.2: There shall be no dead code.
 */
/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "Icu.h"
#include "Icu_Lld_Port.h"
#include "Icu_Cfg.h"
#include "Icu_Lld_Reg.h"
#include "SchM_Icu.h"
/*==================================================================================================
                                      SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_LLD_PORT_VENDOR_ID_C                      (180)
#define ICU_LLD_PORT_AR_RELEASE_MAJOR_VERSION_C       (4)
#define ICU_LLD_PORT_AR_RELEASE_MINOR_VERSION_C       (4)
#define ICU_LLD_PORT_AR_RELEASE_REVISION_VERSION_C    (0)
#define ICU_LLD_PORT_SW_MAJOR_VERSION_C               (2)
#define ICU_LLD_PORT_SW_MINOR_VERSION_C               (3)
#define ICU_LLD_PORT_SW_PATCH_VERSION_C               (0)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ICU_LLD_PORT header file are of the same vendor */
#if (ICU_LLD_PORT_VENDOR_ID_C != ICU_LLD_PORT_VENDOR_ID)
#error "Icu_Lld_Port.c and Icu_Lld_Port.h have different vendor ids"
#endif

/* Check if source file and ICU_LLD_PORT header file are of the same Autosar version */
#if ((ICU_LLD_PORT_AR_RELEASE_MAJOR_VERSION_C != ICU_LLD_PORT_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_LLD_PORT_AR_RELEASE_MINOR_VERSION_C != ICU_LLD_PORT_AR_RELEASE_MINOR_VERSION) || \
     (ICU_LLD_PORT_AR_RELEASE_REVISION_VERSION_C != ICU_LLD_PORT_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu_Lld_Port.c and Icu_Lld_Port.h are different"
#endif

/* Check if source file and ICU_LLD_PORT header file are of the same Software version */
#if ((ICU_LLD_PORT_SW_MAJOR_VERSION_C != ICU_LLD_PORT_SW_MAJOR_VERSION) || \
     (ICU_LLD_PORT_SW_MINOR_VERSION_C != ICU_LLD_PORT_SW_MINOR_VERSION) || \
     (ICU_LLD_PORT_SW_PATCH_VERSION_C != ICU_LLD_PORT_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Lld_Port.c and Icu_Lld_Port.h are different"
#endif

/*================================================================================*/
/* Check if source file and ICU_LLD_REG header file are of the same vendor */
#if (ICU_LLD_PORT_VENDOR_ID_C != ICU_LLD_REG_VENDOR_ID)
#error "Icu_Lld_Port.c and Icu_Lld_Reg.h have different vendor ids"
#endif

/* Check if source file and ICU_LLD_REG header file are of the same Autosar version */
#if ((ICU_LLD_PORT_AR_RELEASE_MAJOR_VERSION_C != ICU_LLD_REG_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_LLD_PORT_AR_RELEASE_MINOR_VERSION_C != ICU_LLD_REG_AR_RELEASE_MINOR_VERSION) || \
     (ICU_LLD_PORT_AR_RELEASE_REVISION_VERSION_C != ICU_LLD_REG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu_Lld_Port.c and Icu_Lld_Reg.h are different"
#endif

/* Check if source file and ICU_LLD_REG header file are of the same Software version */
#if ((ICU_LLD_PORT_SW_MAJOR_VERSION_C != ICU_LLD_REG_SW_MAJOR_VERSION) || \
     (ICU_LLD_PORT_SW_MINOR_VERSION_C != ICU_LLD_REG_SW_MINOR_VERSION) || \
     (ICU_LLD_PORT_SW_PATCH_VERSION_C != ICU_LLD_REG_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Lld_Port.c and Icu_Lld_Reg.h are different"
#endif

/*==================================================================================================
                                                GLOBAL VARIABLES
==================================================================================================*/
#define ICU_START_SEC_VAR_CLEARED_32
#include "Icu_MemMap.h"
ICU_VAR IcuPortEdgeDetectType Icu_Port_Notification[ICU_MAX_CHANNEL];
ICU_VAR static Icu_ActivationType IcuPortCurrentEdgeStatus[ICU_MAX_CHANNEL];
#define ICU_STOP_SEC_VAR_CLEARED_32
#include "Icu_MemMap.h"

extern Icu_ChannelInfoType Icu_gChannelInfo[ICU_MAX_CHANNEL];
/*==================================================================================================
                                                LOCAL VARIABLES
==================================================================================================*/
#define ICU_START_SEC_CONST_16
#include "Icu_MemMap.h"
ICU_CONST const uint16 IcuWkupPortBuff[ICU_WKUP_PORT_MAX] =
{
#if defined (YTM32B1MC_LQFP48)
    ((uint16)(ICU_PORTA << 8U) | 0U), ((uint16)(ICU_PORTA << 8U) | 1U), ((uint16)(ICU_PORTA << 8U) | 2U), ((uint16)(ICU_PORTA << 8U) | 3U),
    ((uint16)(ICU_PORTA << 8U) | 4U), ((uint16)(ICU_PORTA << 8U) | 5U), ((uint16)(ICU_PORTA << 8U) | 7U), ((uint16)(ICU_PORTA << 8U) | 10U),
    ((uint16)(ICU_PORTA << 8U) | 11U), ((uint16)(ICU_PORTA << 8U) | 12U), ((uint16)(ICU_PORTA << 8U) | 13U), ((uint16)(ICU_PORTB << 8U) | 0),
    ((uint16)(ICU_PORTB << 8U) | 1U), ((uint16)(ICU_PORTB << 8U) | 2U), ((uint16)(ICU_PORTB << 8U) | 3U), ((uint16)(ICU_PORTB << 8U) | 4U),
    ((uint16)(ICU_PORTB << 8U) | 5U), ((uint16)(ICU_PORTB << 8U) | 6U), ((uint16)(ICU_PORTB << 8U) | 7U), ((uint16)(ICU_PORTB << 8U) | 13U),
    ((uint16)(ICU_PORTC << 8U) | 1U), ((uint16)(ICU_PORTC << 8U) | 2U), ((uint16)(ICU_PORTC << 8U) | 3U), ((uint16)(ICU_PORTC << 8U) | 4U),
    ((uint16)(ICU_PORTC << 8U) | 5U), ((uint16)(ICU_PORTC << 8U) | 6U), ((uint16)(ICU_PORTC << 8U) | 7U), ((uint16)(ICU_PORTC << 8U) | 8U),
    ((uint16)(ICU_PORTC << 8U) | 9U), ((uint16)(ICU_PORTC << 8U) | 14U), ((uint16)(ICU_PORTC << 8U) | 15U), ((uint16)(ICU_PORTC << 8U) | 16U),
    ((uint16)(ICU_PORTD << 8U) | 0U), ((uint16)(ICU_PORTD << 8U) | 1U), ((uint16)(ICU_PORTD << 8U) | 2U), ((uint16)(ICU_PORTD << 8U) | 3U),
    ((uint16)(ICU_PORTD << 8U) | 5U), ((uint16)(ICU_PORTD << 8U) | 15U), ((uint16)(ICU_PORTD << 8U) | 16U), ((uint16)(ICU_PORTE << 8U) | 4U),
    ((uint16)(ICU_PORTE << 8U) | 5U), ((uint16)(ICU_PORTE << 8U) | 8U), ((uint16)(ICU_PORTE << 8U) | 9U), (uint16)0x0f00U /*0x0f00 is ACMP*/
#elif defined (YTM32B1MC_LQFP64)
    ((uint16)(ICU_PORTA << 8U) | 0U), ((uint16)(ICU_PORTA << 8U) | 1U), ((uint16)(ICU_PORTA << 8U) | 2U), ((uint16)(ICU_PORTA << 8U) | 3U),
    ((uint16)(ICU_PORTA << 8U) | 4U), ((uint16)(ICU_PORTA << 8U) | 5U), ((uint16)(ICU_PORTA << 8U) | 6U), ((uint16)(ICU_PORTA << 8U) | 7U),
    ((uint16)(ICU_PORTA << 8U) | 10U), ((uint16)(ICU_PORTA << 8U) | 11U), ((uint16)(ICU_PORTA << 8U) | 12U), ((uint16)(ICU_PORTA << 8U) | 13U),
    ((uint16)(ICU_PORTB << 8U) | 0), ((uint16)(ICU_PORTB << 8U) | 1U), ((uint16)(ICU_PORTB << 8U) | 2U), ((uint16)(ICU_PORTB << 8U) | 3U),
    ((uint16)(ICU_PORTB << 8U) | 4U), ((uint16)(ICU_PORTB << 8U) | 5U), ((uint16)(ICU_PORTB << 8U) | 6U), ((uint16)(ICU_PORTB << 8U) | 7U),
    ((uint16)(ICU_PORTB << 8U) | 12U), ((uint16)(ICU_PORTB << 8U) | 13U), ((uint16)(ICU_PORTC << 8U) | 0), ((uint16)(ICU_PORTC << 8U) | 1U),
    ((uint16)(ICU_PORTC << 8U) | 2U), ((uint16)(ICU_PORTC << 8U) | 3U), ((uint16)(ICU_PORTC << 8U) | 4U), ((uint16)(ICU_PORTC << 8U) | 5U),
    ((uint16)(ICU_PORTC << 8U) | 6U), ((uint16)(ICU_PORTC << 8U) | 7U), ((uint16)(ICU_PORTC << 8U) | 8U), ((uint16)(ICU_PORTC << 8U) | 9U),
    ((uint16)(ICU_PORTC << 8U) | 14U), ((uint16)(ICU_PORTC << 8U) | 15U), ((uint16)(ICU_PORTC << 8U) | 16U), ((uint16)(ICU_PORTC << 8U) | 17U),
    ((uint16)(ICU_PORTD << 8U) | 0U), ((uint16)(ICU_PORTD << 8U) | 1U), ((uint16)(ICU_PORTD << 8U) | 2U), ((uint16)(ICU_PORTD << 8U) | 3U),
    ((uint16)(ICU_PORTD << 8U) | 4U), ((uint16)(ICU_PORTD << 8U) | 5U), ((uint16)(ICU_PORTD << 8U) | 6U), ((uint16)(ICU_PORTD << 8U) | 7U),
    ((uint16)(ICU_PORTD << 8U) | 15U), ((uint16)(ICU_PORTD << 8U) | 16U), ((uint16)(ICU_PORTE << 8U) | 0U), ((uint16)(ICU_PORTE << 8U) | 1U),
    ((uint16)(ICU_PORTE << 8U) | 2U), ((uint16)(ICU_PORTE << 8U) | 3U), ((uint16)(ICU_PORTE << 8U) | 4U), ((uint16)(ICU_PORTE << 8U) | 5U),
    ((uint16)(ICU_PORTE << 8U) | 6U), ((uint16)(ICU_PORTE << 8U) | 7U), ((uint16)(ICU_PORTE << 8U) | 8U), ((uint16)(ICU_PORTE << 8U) | 9U),
    ((uint16)(ICU_PORTE << 8U) | 10U), ((uint16)(ICU_PORTE << 8U) | 11U), (uint16)0x0f00U /*0x0f00 is ACMP*/
#elif defined(CPU_YTM32B1ME0)
    ((uint16)(ICU_PORTE << 8U) | 11U), ((uint16)(ICU_PORTE << 8U) | 10U),
    ((uint16)(ICU_PORTE << 8U) | 5U), ((uint16)(ICU_PORTE << 8U) | 4U), ((uint16)(ICU_PORTE << 8U) | 3U), ((uint16)(ICU_PORTE << 8U) | 1U),
    ((uint16)(ICU_PORTE << 8U) | 0U), ((uint16)(ICU_PORTE << 8U) | 9U), ((uint16)(ICU_PORTE << 8U) | 8U), ((uint16)(ICU_PORTC << 8U) | 3U),
    ((uint16)(ICU_PORTC << 8U) | 2U), ((uint16)(ICU_PORTD << 8U) | 5U), ((uint16)(ICU_PORTC << 8U) | 1U), ((uint16)(ICU_PORTC << 8U) | 0U),
    ((uint16)(ICU_PORTC << 8U) | 15U), ((uint16)(ICU_PORTC << 8U) | 14U), ((uint16)(ICU_PORTB << 8U) | 1U), ((uint16)(ICU_PORTB << 8U) | 0U),
    ((uint16)(ICU_PORTA << 8U) | 7U), ((uint16)(ICU_PORTA << 8U) | 6U), ((uint16)(ICU_PORTB << 8U) | 13U), ((uint16)(ICU_PORTB << 8U) | 12U),
    ((uint16)(ICU_PORTD << 8U) | 3U), ((uint16)(ICU_PORTD << 8U) | 2U), ((uint16)(ICU_PORTA << 8U) | 3U), ((uint16)(ICU_PORTA << 8U) | 2U),
    ((uint16)(ICU_PORTC << 8U) | 7U), ((uint16)(ICU_PORTC << 8U) | 6U), ((uint16)(ICU_PORTE << 8U) | 6U), ((uint16)(ICU_PORTE << 8U) | 2U),
    ((uint16)(ICU_PORTA << 8U) | 13U), ((uint16)(ICU_PORTA << 8U) | 12U), (uint16)0x0f00U /*0x0f00 is ACMP*/
#elif defined(CPU_YTM32B1MD1)
    ((uint16)(ICU_PORTE << 8U) | 11U), ((uint16)(ICU_PORTE << 8U) | 4U),
    ((uint16)(ICU_PORTE << 8U) | 3U), ((uint16)(ICU_PORTE << 8U) | 0U), ((uint16)(ICU_PORTE << 8U) | 8U), ((uint16)(ICU_PORTC << 8U) | 2U),
    ((uint16)(ICU_PORTC << 8U) | 1U), ((uint16)(ICU_PORTC << 8U) | 15U), ((uint16)(ICU_PORTB << 8U) | 1U), ((uint16)(ICU_PORTA << 8U) | 7U),
    ((uint16)(ICU_PORTB << 8U) | 12U), ((uint16)(ICU_PORTD << 8U) | 3U), ((uint16)(ICU_PORTA << 8U) | 2U), ((uint16)(ICU_PORTC << 8U) | 6U),
    ((uint16)(ICU_PORTE << 8U) | 6U), ((uint16)(ICU_PORTA << 8U) | 12U), (uint16)0x0f00U
#elif defined (CPU_YTM32B1HA0)
    ((uint16)(ICU_PORTE << 8U) | 11U), ((uint16)(ICU_PORTE << 8U) | 10U),
    ((uint16)(ICU_PORTE << 8U) | 5U), ((uint16)(ICU_PORTE << 8U) | 4U), ((uint16)(ICU_PORTE << 8U) | 3U), ((uint16)(ICU_PORTE << 8U) | 1U),
    ((uint16)(ICU_PORTE << 8U) | 0U), ((uint16)(ICU_PORTE << 8U) | 9U), ((uint16)(ICU_PORTE << 8U) | 8U), ((uint16)(ICU_PORTC << 8U) | 3U),
    ((uint16)(ICU_PORTB << 8U) | 26U), ((uint16)(ICU_PORTD << 8U) | 5U), ((uint16)(ICU_PORTC << 8U) | 1U), ((uint16)(ICU_PORTC << 8U) | 0U),
    ((uint16)(ICU_PORTC << 8U) | 15U), ((uint16)(ICU_PORTC << 8U) | 14U), ((uint16)(ICU_PORTB << 8U) | 1U), ((uint16)(ICU_PORTB << 8U) | 0U),
    ((uint16)(ICU_PORTA << 8U) | 7U), ((uint16)(ICU_PORTA << 8U) | 6U), ((uint16)(ICU_PORTB << 8U) | 13U), ((uint16)(ICU_PORTB << 8U) | 12U),
    ((uint16)(ICU_PORTD << 8U) | 3U), ((uint16)(ICU_PORTD << 8U) | 2U), ((uint16)(ICU_PORTA << 8U) | 3U), ((uint16)(ICU_PORTA << 8U) | 2U),
    ((uint16)(ICU_PORTC << 8U) | 7U), ((uint16)(ICU_PORTC << 8U) | 6U), ((uint16)(ICU_PORTE << 8U) | 6U), ((uint16)(ICU_PORTE << 8U) | 2U),
    ((uint16)(ICU_PORTA << 8U) | 13U), ((uint16)(ICU_PORTA << 8U) | 12U), ((uint16)(ICU_PORTE << 8U) | 16U), ((uint16)(ICU_PORTE << 8U) | 15),
    ((uint16)(ICU_PORTA << 8U) | 22U), ((uint16)(ICU_PORTE << 8U) | 14U), ((uint16)(ICU_PORTD << 8U) | 15U), ((uint16)(ICU_PORTD << 8U) | 13U),
    ((uint16)(ICU_PORTB << 8U) | 21U), ((uint16)(ICU_PORTB << 8U) | 23U), ((uint16)(ICU_PORTB << 8U) | 2U), ((uint16)(ICU_PORTC << 8U) | 25U),
    ((uint16)(ICU_PORTC << 8U) | 11U), ((uint16)(ICU_PORTC << 8U) | 9U), ((uint16)(ICU_PORTB << 8U) | 17U), ((uint16)(ICU_PORTD << 8U) | 4U),
    ((uint16)(ICU_PORTB << 8U) | 9U), ((uint16)(ICU_PORTB << 8U) | 8U), ((uint16)(ICU_PORTA << 8U) | 15U), ((uint16)(ICU_PORTE << 8U) | 23U),
    ((uint16)(ICU_PORTE << 8U) | 25U), ((uint16)(ICU_PORTA << 8U) | 9U), ((uint16)(ICU_PORTA << 8U) | 8U), ((uint16)(ICU_PORTB << 8U) | 16U),
    ((uint16)(ICU_PORTB << 8U) | 15U), ((uint16)(ICU_PORTA << 8U) | 1U), ((uint16)(ICU_PORTA << 8U) | 16U), ((uint16)(ICU_PORTA << 8U) | 25U),
    ((uint16)(ICU_PORTA << 8U) | 30U), ((uint16)(ICU_PORTB << 8U) | 28U), ((uint16)(ICU_PORTC << 8U) | 18U), ((uint16)(ICU_PORTA << 8U) | 26U),
    ((uint16)(ICU_PORTC << 8U) | 23U), ((uint16)(ICU_PORTB << 8U) | 11U), (uint16)0x0f00U /*0x0f00 is ACMP*/
#endif
};
#define ICU_STOP_SEC_CONST_16
#include "Icu_MemMap.h"

#define ICU_START_SEC_VAR_INIT_BOOLEAN
#include "Icu_MemMap.h"
ICU_VAR static boolean PortWakeupEnable = FALSE;
#define ICU_STOP_SEC_VAR_INIT_BOOLEAN
#include "Icu_MemMap.h"

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
ICU_FUNC static uint8 IcuChannelToWkuChannel(uint16 Channel)
{
    uint8 Index;
    for (Index = 0; Index < ICU_WKUP_PORT_MAX; ++Index)
    {
        if (IcuWkupPortBuff[Index] == Channel)
        {
            break;
        }
    }
    return Index;
}

/*==================================================================================================
                                                GLOBAL FUNCTIONS
==================================================================================================*/

ICU_FUNC void Icu_Lld_Port_SetActivationCondition(uint8 ChannelIndex, Icu_ActivationType Activation)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_03();
    switch (Activation)
    {
        case ICU_RISING_EDGE:
            IcuPortCurrentEdgeStatus[ChannelIndex] = ICU_RISING_EDGE;
            break;
        case ICU_FALLING_EDGE:
            IcuPortCurrentEdgeStatus[ChannelIndex] = ICU_FALLING_EDGE;
            break;
        case ICU_BOTH_EDGES:
            IcuPortCurrentEdgeStatus[ChannelIndex] = ICU_BOTH_EDGES;
            break;
        default:
        {
            /*nothing to do*/
        }
        break;
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_03();
}
ICU_FUNC void Icu_Lld_Port_Init(void)
{
    Icu_ChannelConfigType const *ConfigPtr = Icu_gConfigPtr->ChannelConfigPtr;
    uint8 ChannelCount = (uint8)Icu_gConfigPtr->IcuChannelCount;
    uint8 PortInstance = 0;
    uint8 PortChannel = 0;
#if(WKU_SUPPORT == STD_ON)
    uint8 WkuChannelIndex = 0;
    uint32 WkuPinAddress = WKU_BASE_ADDR32;
#endif
    for (uint8 ChannelIndex = 0; ChannelIndex < ChannelCount; ++ChannelIndex)
    {
        if (ConfigPtr->IcuHwIp == ICU_PORT)
        {
            PortInstance = (uint8)ConfigPtr->IcuHwIpInstance;
            PortChannel = (uint8)ConfigPtr->IcuHwChannel;
            SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_04();
            /*Clear pin interrupt flag*/
            ICU_GPIO_REG_ADDR32_INDEX_W1C_BIT(GPIO_PIFR_ADDR32(PortInstance), PortChannel);
            Icu_gChannelInfo[ChannelIndex].InputState = ICU_IDLE;
            SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_04();
            /*Enable pin interrupt and Set Pin Interrupt Mode*/
            IcuPortCurrentEdgeStatus[ChannelIndex] = ConfigPtr->IcuDefaultStartEdge;
            if (TRUE == ConfigPtr->IcuWakeupCapability)
            {
#if(WKU_SUPPORT == STD_ON)
                WkuChannelIndex = IcuChannelToWkuChannel((uint16)((uint16)PortInstance << PORT_SHIFT) | PortChannel);
                WkuPinAddress = WKU_BASE_ADDR32 + WkuChannelIndex;
                /*Enable Wakeup*/
                SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_04();
                ICU_WKU_REG_ADDR8_AEARWRITE(WkuPinAddress, (uint8)0x0f, (uint8)(WKU_PCR_WUPIE_MASK));
                SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_04();
#endif
                PortWakeupEnable = TRUE;
            }
        }
        ++ConfigPtr;
    }
}
ICU_FUNC void Icu_Lld_Port_DeInit(void)
{
    Icu_ChannelConfigType const *ConfigPtr = Icu_gConfigPtr->ChannelConfigPtr;
    uint8 ChannelCount = (uint8)Icu_gConfigPtr->IcuChannelCount;
    uint8 PortInstance = 0;
    uint8 PortChannel = 0;
    for (uint8 ChannelIndex = 0; ChannelIndex < ChannelCount; ++ChannelIndex)
    {
        if (ConfigPtr->IcuHwIp == ICU_PORT)
        {
            PortInstance = (uint8)ConfigPtr->IcuHwIpInstance;
            PortChannel = (uint8)ConfigPtr->IcuHwChannel;
            SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_05();
            /*Clear pin interrupt flag*/
            ICU_GPIO_REG_ADDR32_INDEX_W1C_BIT(GPIO_PIFR_ADDR32(PortInstance), PortChannel);
            /*Disable pin interrupt*/
            ICU_GPIO_REG_ADDR32_AEARWRITE(GPIO_PCR_ADDR32((uint32)PortInstance, (uint32)PortChannel),
                                          GPIO_PCR_IRQC_MASK,
                                          (uint32)(ICU_PORT_NOTIFICATION_INT_DISABLE) << GPIO_PCR_IRQC_SHIFT);
            Icu_gChannelInfo[ChannelIndex].InputState = ICU_IDLE;
            SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_05();
        }
        ++ConfigPtr;
    }
    if (TRUE == PortWakeupEnable)
    {
        SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_05();
        /*Disable Wakeup*/
#if (WKU_SUPPORT == STD_ON)
        ICU_GPIO_REG_ADDR32_WRITE(WKU_BASE_ADDR32, 0);
#endif
        PortWakeupEnable = FALSE;
        SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_05();
    }
}
ICU_FUNC void Icu_Lld_Port_EnableNotification(uint8 Channel)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_06();
    Icu_Port_Notification[Channel].IsNotificationEnable = TRUE;
    Icu_Port_Notification[Channel].EdgeNotificationPtr = Icu_gConfigPtr->ChannelConfigPtr[Channel].SignalNotificationPtr;
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_06();
}
ICU_FUNC void Icu_Lld_Port_DisableNotification(uint8 Channel)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_07();
    Icu_Port_Notification[Channel].IsNotificationEnable = FALSE;
    Icu_Port_Notification[Channel].EdgeNotificationPtr = NULL_PTR;
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_07();
}

ICU_FUNC uint32 Icu_Lld_GetGPIOPinIntFlag(uint8 PortHwId, uint8 PinHwId)
{
    return ICU_GPIO_REG_ADDR32_INDEX_GET_BIT(GPIO_PIFR_ADDR32(PortHwId), PinHwId);
}
ICU_FUNC void Icu_Lld_CleanGPIOPinIntFlag(uint8 PortHwId, uint8 PinHwId)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_08();
    ICU_GPIO_REG_ADDR32_INDEX_W1C_BIT(GPIO_PIFR_ADDR32(PortHwId), PinHwId);
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_08();
}
ICU_FUNC void Icu_Lld_Port_SetNormalMode(const Icu_ChannelConfigType *ConfigPtr)
{
    /* Disable IRQ Interrupt */
    uint8 PortInstance = (uint8)ConfigPtr->IcuHwIpInstance;
    uint8 PortChannel = (uint8)ConfigPtr->IcuHwChannel;
#if(WKU_SUPPORT == STD_ON)
    uint8 WkuChannelIndex = IcuChannelToWkuChannel((uint16)((uint16)PortInstance << PORT_SHIFT) | PortChannel);
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_09();
    ICU_WKU_REG_ADDR8_WRITE(WKU_BASE_ADDR32 + WKU_PCR_OFFSET8((uint32)WkuChannelIndex), (uint8)0U); /*PRQA S 2985,2986*/
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_09();
#else
    (void)PortInstance;
    (void)PortChannel;
#endif
}
ICU_FUNC void Icu_Lld_Port_SetSleepMode(const Icu_ChannelConfigType *ConfigPtr)
{
    /* Enable IRQ Interrupt */
    uint8 PortInstance = (uint8)ConfigPtr->IcuHwIpInstance;
    uint8 PortChannel = (uint8)ConfigPtr->IcuHwChannel;
    uint8 WkuChannelIndex = IcuChannelToWkuChannel((uint16)((uint16)PortInstance << PORT_SHIFT) | PortChannel);
    IcuPortWkuModeType WkuEdge = ICU_PIN_WAKEUP_DISABLE;
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_10();
    switch (ConfigPtr->IcuDefaultStartEdge)
    {
        case ICU_RISING_EDGE:
            WkuEdge = ICU_PIN_WAKEUP_RASING;
            break;
        case ICU_FALLING_EDGE:
            WkuEdge = ICU_PIN_WAKEUP_FALLING;
            break;
        case ICU_BOTH_EDGES:
            WkuEdge = ICU_PIN_WAKEUP_BOTH;
            break;
        default:
        {
            /*nothing to do*/
        }
        break;
    }
#if (WKU_SUPPORT == STD_ON)
    ICU_WKU_REG_ADDR8_AEARWRITE(WKU_BASE_ADDR32 + WKU_PCR_OFFSET8((uint32)WkuChannelIndex), (uint8)0x0fU,/*PRQA S 2985,2986*/
                                (uint8)((uint8)WKU_PCR_WUPIE_MASK | (uint8)WkuEdge));
    ICU_WKU_REG_ADDR32_AEARWRITE(WKU_BASE_ADDR32 + WKU_RPCR_OFFSET32, 0x0dU, WKU_RPCR_WURPE(1));
#if defined(CPU_YTM32B1ME0) || defined(CPU_YTM32B1MD1)
    ICU_WKU_REG_ADDR32_AEARWRITE(WKU_BASE_ADDR32 + WKU_PFR_OFFSET32(0), WKU_PFR_WUF_MASK, WKU_PFR_WUF_MASK); /* write 1 to clear*/
#elif defined(CPU_YTM32B1HA0)
    ICU_WKU_REG_ADDR32_AEARWRITE(WKU_BASE_ADDR32 + WKU_PFR_OFFSET32(WkuChannelIndex / 32), WKU_PFR_WUF_MASK, WKU_PFR_WUF_MASK); /* write 1 to clear*/
#endif
#else
    (void)WkuEdge;
    (void)WkuChannelIndex;
#endif
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_10();
}

ICU_FUNC void Icu_Lld_ClearWakeupFlag(void)
{
#if (WKU_SUPPORT == STD_ON)
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_11();
#if defined(CPU_YTM32B1ME0) || defined(CPU_YTM32B1MD1)
    ICU_WKU_REG_ADDR32_AEARWRITE(WKU_BASE_ADDR32 + WKU_PFR_OFFSET32(0), WKU_PFR_WUF_MASK, WKU_PFR_WUF_MASK); /* write 1 to clear*/
#elif defined(CPU_YTM32B1HA0)
    ICU_WKU_REG_ADDR32_AEARWRITE(WKU_BASE_ADDR32 + WKU_PFR_OFFSET32(0), WKU_PFR_WUF_MASK, WKU_PFR_WUF_MASK); /* write 1 to clear*/
    ICU_WKU_REG_ADDR32_AEARWRITE(WKU_BASE_ADDR32 + WKU_PFR_OFFSET32(1), WKU_PFR_WUF_MASK, WKU_PFR_WUF_MASK); /* write 1 to clear*/
#endif
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_11();
#endif
}


ICU_FUNC uint32 Icu_Lld_GetWakeUpFlag(uint8 Region)
{
    uint32 WkuFlag = 0;
#if (WKU_SUPPORT == STD_ON)
#if defined(CPU_YTM32B1ME0) || defined(CPU_YTM32B1MD1)
    (void)Region;
    WkuFlag = ICU_WKU_REG_ADDR32_READ(WKU_BASE_ADDR32 + WKU_PFR_OFFSET32(0));
#elif defined(CPU_YTM32B1HA0)
    WkuFlag = ICU_WKU_REG_ADDR32_READ(WKU_BASE_ADDR32 + WKU_PFR_OFFSET32(Region));
#endif
#endif
    return WkuFlag;
}


ICU_FUNC void Icu_Lld_Port_EnableEdgeDetection(uint16 ChannelIndex)
{
    /* MR12 RULE 18.4 VIOLATION: The integer value 1 is being added or subtracted from a pointer.
     * Pointer operation is more concise for data processing, thus, couldn't adhere to M3CM Rule-8.13
       */
    Icu_ChannelConfigType const *ConfigPtr = Icu_gConfigPtr->ChannelConfigPtr + ChannelIndex;/*PRQA S 0488*/
    uint8 PortID = (uint8)ConfigPtr->IcuHwIpInstance;
    uint8 PinID = (uint8)ConfigPtr->IcuHwChannel;
    Icu_ActivationType Activation = IcuPortCurrentEdgeStatus[ChannelIndex];
    Icu_Port_NotificationModeType PortNotificationMode = ICU_PORT_NOTIFICATION_INT_DISABLE;
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_03();
    switch (Activation)
    {
        case ICU_RISING_EDGE:
            PortNotificationMode = ICU_PORT_NOTIFICATION_INT_ON_RASING_EDGE;
            break;
        case ICU_FALLING_EDGE:
            PortNotificationMode = ICU_PORT_NOTIFICATION_INT_ON_FALLING_EDGE;
            break;
        case ICU_BOTH_EDGES:
            PortNotificationMode = ICU_PORT_NOTIFICATION_INT_ON_BOTH_EDGE;
            break;
        default:
        {
            /*nothing to do*/
        }
        break;
    }
    ICU_GPIO_REG_ADDR32_AEARWRITE(GPIO_PCR_ADDR32((uint32)PortID, (uint32)PinID),/*PRQA S 2985*/
                                  GPIO_PCR_IRQC_MASK,
                                  (uint32)(PortNotificationMode) << GPIO_PCR_IRQC_SHIFT);
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_03();
}
ICU_FUNC void Icu_Lld_Port_DisableEdgeDetection(uint16 ChannelIndex)
{
    /* MR12 RULE 18.4 VIOLATION: The integer value 1 is being added or subtracted from a pointer.
     * Pointer operation is more concise for data processing, thus, couldn't adhere to M3CM Rule-8.13
       */
    Icu_ChannelConfigType const *ConfigPtr = Icu_gConfigPtr->ChannelConfigPtr + ChannelIndex;/*PRQA S 0488*/
    uint8 PortID = (uint8)ConfigPtr->IcuHwIpInstance;
    uint8 PinID = (uint8)ConfigPtr->IcuHwChannel;
    ICU_GPIO_REG_ADDR32_AEARWRITE(GPIO_PCR_ADDR32((uint32)PortID, (uint32)PinID),
                                  GPIO_PCR_IRQC_MASK,
                                  (uint32)(ICU_PORT_NOTIFICATION_INT_DISABLE) << GPIO_PCR_IRQC_SHIFT);
}
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#ifdef __cplusplus
}
#endif

/* End of file Icu_Lld_Port.c */

