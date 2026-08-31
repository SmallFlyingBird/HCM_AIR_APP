/*
* @file    Icu_Lld_Port.h
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

#ifndef ICU_LLD_PORT_H
#define ICU_LLD_PORT_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
#include "Icu.h"
/*==================================================================================================
                                      HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_LLD_PORT_VENDOR_ID                      (180)
#define ICU_LLD_PORT_AR_RELEASE_MAJOR_VERSION       (4)
#define ICU_LLD_PORT_AR_RELEASE_MINOR_VERSION       (4)
#define ICU_LLD_PORT_AR_RELEASE_REVISION_VERSION    (0)
#define ICU_LLD_PORT_SW_MAJOR_VERSION               (2)
#define ICU_LLD_PORT_SW_MINOR_VERSION               (3)
#define ICU_LLD_PORT_SW_PATCH_VERSION               (0)
/*==================================================================================================
                                                DEFINES AND MACROS
==================================================================================================*/
typedef void (*Icu_Port_NotificationType)(void);    /*!< Pointer to notification function */
typedef enum 
{
    ICU_PIN_WAKEUP_DISABLE,
    ICU_PIN_WAKEUP_RASING,
    ICU_PIN_WAKEUP_FALLING,
    ICU_PIN_WAKEUP_BOTH,
}IcuPortWkuModeType;

typedef struct
{
    Icu_Port_NotificationType EdgeNotificationPtr;  /*!< ICU_Port notification function */
    boolean IsNotificationEnable;               /*!< ICU_Port notification enable flag */
} IcuPortEdgeDetectType;

#define ICU_GPIO_REG_ADDR32_READ(address) (*(volatile uint32 *)(address))   /*!< Read 32bit register */
#define ICU_GPIO_REG_ADDR32_WRITE(address, value) ((*(volatile uint32 *)(address)) = (value))   /*!< Write 32bit register */

#define ICU_GPIO_REG_ADDR32_AEARWRITE(address, mask, value) \
                        (ICU_GPIO_REG_ADDR32_WRITE((address),                   \
                        ((ICU_GPIO_REG_ADDR32_READ(address) & ((uint32) ~(mask))) | (value))))  /*!< Write 32bit register with mask */

#define ICU_GPIO_REG_ADDR32_INDEX_W1C_BIT(address, bitindex) ((*(volatile uint32 *)(address))  = ((uint32)1 << (bitindex))) /*!<Write 1 to clear bit*/
#define ICU_GPIO_REG_ADDR32_INDEX_GET_BIT(address, bitindex) (((*(volatile uint32 *)(address)) >> (bitindex)) & ((uint32)1U))   /*!< Get bit value */

#define ICU_PORTA (uint16)(0U)  /*!< Port A */
#define ICU_PORTB (uint16)(1U)  /*!< Port B */
#define ICU_PORTC (uint16)(2U)  /*!< Port C */
#define ICU_PORTD (uint16)(3U)  /*!< Port D */
#define ICU_PORTE (uint16)(4U)  /*!< Port E */

#define PORT_SHIFT 8U
/*==================================================================================================
                                                EXTERNAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
                                                ENUMS
==================================================================================================*/
typedef enum
{
    ICU_PORT_NOTIFICATION_INT_DISABLE = 0x0U,        /*!< ICU_Port notification disable */
    ICU_PORT_NOTIFICATION_INT_ON_RASING_EDGE = 0x9U,  /*!< ICU_Port notification trigger IRQ request on rasing edge */
    ICU_PORT_NOTIFICATION_INT_ON_FALLING_EDGE = 0xAU, /*!< ICU_Port notification trigger IRQ request on falling edge */
    ICU_PORT_NOTIFICATION_INT_ON_BOTH_EDGE = 0xBU,    /*!< ICU_Port notification trigger IRQ request on both edge */
} Icu_Port_NotificationModeType;
/*==================================================================================================
                                                FUNCTION PROTOTYPES
==================================================================================================*/
extern IcuPortEdgeDetectType Icu_Port_Notification[ICU_MAX_CHANNEL];

/**
 * @brief            This function initializes the driver.
 * @details
 * @return           void
 *
 */
void Icu_Lld_Port_Init(void);

/**
 * @brief            This function deinitialize the driver.
 * @details
 * @return           void
 *
 */
void Icu_Lld_Port_DeInit(void);

/**
 * @brief            This function initializes the channel.
 * @details
 * @param[in]        Channel - The channel
 * @return           void
 *
 */
void Icu_Lld_Port_EnableNotification(uint8 Channel);

/**
 * @brief            This function deinitialize the channel.
 * @details
 * @param[in]        Channel - The channel
 * @return           void
 *
 */
void Icu_Lld_Port_DisableNotification(uint8 Channel);

/**
 * @brief            This function sets the activation condition.
 * @details
 * @param[in]        ChannelIndex - The channel index.
 * @param[in]        Activation - The activation condition.
 * @return           void
 *
 */
void Icu_Lld_Port_SetActivationCondition(uint8 ChannelIndex, Icu_ActivationType Activation);

/**
 * @brief            This function sets the sleep mode.
 * @details
 * @param[in]        ConfigPtr - The channel configuration.
 * @return           void
 *
 */
void Icu_Lld_Port_SetSleepMode(const Icu_ChannelConfigType *ConfigPtr);

/**
 * @brief            This function sets the normal mode.
 * @details
 * @param[in]        ConfigPtr - The channel configuration.
 * @return           void
 *
 */
void Icu_Lld_Port_SetNormalMode(const Icu_ChannelConfigType *ConfigPtr);

/**
 * @brief            This function gets the PIN init flag.
 * @details
 * @param[in]        PortHwId - The port hardware ID.
 * @param[in]        PinHwId - The pin hardware ID.
 * @return           The PIN init flag.
 *
 */
uint32 Icu_Lld_GetGPIOPinIntFlag(uint8 PortHwId, uint8 PinHwId);

/**
 * @brief            This function clear the PIN init flag.
 * @details
 * @param[in]        PortHwId - The port hardware ID.
 * @param[in]        PinHwId - The pin hardware ID.
 * @return           void
 *
 */
void Icu_Lld_CleanGPIOPinIntFlag(uint8 PortHwId, uint8 PinHwId);

/**
 * @brief            This function Clear the wakeup flag.
 * @details
 * @return           void
 *
 */
void Icu_Lld_ClearWakeupFlag(void);

/**
 * @brief Get Pin Wakeup Flag
 * @param[in] Region used only in HA0, 0:0-31, 1: 32-63
 * @return uint32 
 */
uint32 Icu_Lld_GetWakeUpFlag(uint8 Region);


/**
 * @brief            This function enable Edge Detection.
 * @details
 * @param[in]        ChannelIndex - The channel index.
 * @return           void
 *
 */
void Icu_Lld_Port_EnableEdgeDetection(uint16 ChannelIndex);

/**
 * @brief            This function disable Edge Detection.
 * @details
 * @param[in]        ChannelIndex - The channel index.
 * @return           void
 *
 */
void Icu_Lld_Port_DisableEdgeDetection(uint16 ChannelIndex);

#ifdef __cplusplus
}
#endif

#endif /* End of file Icu_Lld_Port.h */

