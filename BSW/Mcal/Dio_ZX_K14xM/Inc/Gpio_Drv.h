/**************************************************************************************************/
/**
 * @file      : Gpio_Drv.h
 * @brief     : Internal gpio low level driver header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef GPIO_DRV_H
#define GPIO_DRV_H

/** @addtogroup  Gpio_Module
 *  @{
 */

/** @defgroup Gpio_Drv
 *  @brief Internal Gpio low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Gpio_Drv_Types.h"
/** @defgroup Public_MacroDefinition
 *  @{
 */

/**
 *  @brief Published information
 */
#define GPIO_DRV_H_VENDOR_ID                   0x00B3U
#define GPIO_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define GPIO_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define GPIO_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define GPIO_DRV_H_SW_MAJOR_VERSION            1U
#define GPIO_DRV_H_SW_MINOR_VERSION            2U
#define GPIO_DRV_H_SW_PATCH_VERSION            1U

/**
 *  @brief Check if current file and Gpio_Drv_Types header file are of the same vendor
 */
#if ((GPIO_DRV_H_VENDOR_ID != GPIO_DRV_TYPES_H_VENDOR_ID))
    #error "VENDOR ID of Gpio_Drv.h and Gpio_Drv_Types.h are different"
#endif

/**
 *  @brief Check if current file and Gpio_Drv_Types header file are of the same Autosar version
 */
#if (((GPIO_DRV_H_AR_RELEASE_MAJOR_VERSION != GPIO_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||        \
      (GPIO_DRV_H_AR_RELEASE_MINOR_VERSION != GPIO_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION)) ||       \
     (GPIO_DRV_H_AR_RELEASE_REVISION_VERSION != GPIO_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Gpio_Drv.h and Gpio_Drv_Types.h are different"
#endif
#if ((GPIO_DRV_H_SW_MAJOR_VERSION != GPIO_DRV_TYPES_H_SW_MAJOR_VERSION) ||                         \
     (GPIO_DRV_H_SW_MINOR_VERSION != GPIO_DRV_TYPES_H_SW_MINOR_VERSION) ||                         \
     (GPIO_DRV_H_SW_PATCH_VERSION != GPIO_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Gpio_Drv.h and Gpio_Drv_Types.h are different"
#endif

/** @} end of group Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"

/** @defgroup Public_FunctionDeclaration
 *  @brief functions declaration
 *  @{
 */
/**
 * @brief          Returns the value of the specified DIO channel.
 *
 * @param[in]      Base: ID of DIO port.
 * @param[in]      Pin: The specified DIO channel.
 *
 * @return         Gpio_Drv_PinsLevelType: Returns the level of the corresponding pin
 * @retval         1: The physical level of the corresponding pin is STD_HIGH.
 * @retval         0: The physical level of the corresponding Pin is STD_LOW.
 *
 */
Gpio_Drv_PinsLevelType Gpio_Drv_ReadPin(const uint32 Base, Gpio_Drv_PinsChannelType Pin);

/**
 * @brief          Set the level of a channel.
 *
 * @param[in]      Base: ID of DIO port.
 * @param[in]      Pin: The specified DIO channel.
 * @param[in]      Value: Value to be written.
 *
 * @return         None.
 */
void Gpio_Drv_WritePin(const uint32 Base, Gpio_Drv_PinsChannelType Pin,
                       Gpio_Drv_PinsLevelType Value);

/**
 * @brief          Toggle (change from 1 to 0 or from 0 to 1) the level of a
 *                 channel
 *
 * @param[in]      Base: ID of DIO channel.
 * @param[in]      Pins: The specified DIO channel.
 *
 * @return         None.
 *
 */
void Gpio_Drv_TogglePins(const uint32 Base, Gpio_Drv_PinsChannelType Pins);

/**
 * @brief          Get the level of a port.
 *
 * @param[in]      Base: ID of DIO port.
 *
 * @return         Gpio_Drv_PinsChannelType: Returns the level of the corresponding port
 *
 */
Gpio_Drv_PinsChannelType Gpio_Drv_GetPinsOutput(const uint32 Base);

/**
 * @brief          Returns the value of the specified DIO port.
 *
 * @param[in]      Base: ID of DIO port.
 *
 * @return         Gpio_Drv_PinsChannelType: Returns the level of the corresponding port
 *
 */
Gpio_Drv_PinsChannelType Gpio_Drv_ReadPins(const uint32 Base);

/**
 * @brief          Set the level of a port.
 *
 * @param[in]      Base: ID of DIO port.
 * @param[in]      Pins: Value to be written for the specified port.
 *
 * @return         None.
 */
void Gpio_Drv_WritePort(const uint32 Base, Gpio_Drv_PinsChannelType Pins);

/**
 * @brief          Set the level of a port.
 *
 * @param[in]      Base: ID of DIO port.
 * @param[in]      Pins: The specified DIO channel.
 *
 * @return         None.
 */
void Gpio_Drv_SetPins(const uint32 Base, Gpio_Drv_PinsChannelType Pins);

/**
 * @brief          Clear the level of a port.
 *
 * @param[in]      Base: ID of DIO port.
 * @param[in]      Pin: The specified DIO channel.
 *
 * @return         None.
 */
void Gpio_Drv_ClearPins(const uint32 Base, Gpio_Drv_PinsChannelType Pins);
/** @} end of group Public_FunctionDeclaration */
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} end of group Gpio_Drv */

/** @} end of group Gpio_Module */

#endif /* GPIO_DRV_H */
