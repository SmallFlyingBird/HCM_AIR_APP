/*
* @file    Dio_Lld.h
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Dio_Lld
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

#ifndef DIO_LLD_H
#define DIO_LLD_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/

#include "Dio_Lld_Reg.h"

/*==================================================================================================
                                      HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define DIO_LLD_VENDOR_ID                      (180)
#define DIO_LLD_AR_RELEASE_MAJOR_VERSION       (4)
#define DIO_LLD_AR_RELEASE_MINOR_VERSION       (4)
#define DIO_LLD_AR_RELEASE_REVISION_VERSION    (0)
#define DIO_LLD_SW_MAJOR_VERSION               (2)
#define DIO_LLD_SW_MINOR_VERSION               (3)
#define DIO_LLD_SW_PATCH_VERSION               (0)
/*==================================================================================================
                                                DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
                                                EXTERNAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
                                                ENUMS
==================================================================================================*/
/*==================================================================================================
                                                FUNCTION PROTOTYPES
==================================================================================================*/

/**
 * @brief Write to set output a value to a GPIO port.
 * @details This function set ouput pins to the GPIO port via PSOR register.
 * @param[in] PortHwId The hardware ID of the port.
 * @param[in] Level    The value to be written to the port, set output HIGH if the corresponding bit is set(1'b1)
 *                     else have no effect if the corresponding bit is clear(1'b0).
 * @return void
*/
void Dio_Lld_WriteSetOutGPIOPort(Dio_PortType PortHwId, Dio_PortLevelType Level);

/**
 * @brief Write to clear output a value to a GPIO port.
 * @details This function clear ouput pins to the GPIO port via PCOR register.
 * @param[in] PortHwId The hardware ID of the port.
 * @param[in] Level    The value to be written to the port, clear output HIGH if the corresponding bit is set(1'b1)
 *                     else have no effect if the corresponding bit is clear(1'b0).
 * @return void
*/
void Dio_Lld_WriteClrOutGPIOPort(Dio_PortType PortHwId, Dio_PortLevelType Level);

/**
 * @brief Write a value to a GPIO pin.
 * @details This function writes a value to a OUTPUT GPIO pin via PCOR(clean output for Level = STD_LOW)
 * or PSOR(set output for level = STD_HIGH) register.
 * @param[in] PortHwId The hardware ID of the port.
 * @param[in] PinHwId  The hardware ID of the pin.
 * @param[in] Level    The value to be written to the pin.
 * @return void
*/
void Dio_Lld_WriteGPIOPin(Dio_PortType PortHwId, Dio_PinType PinHwId, Dio_LevelType Level);

/**
 * @brief Read a value from a GPIO pin.
 * @details This function reads a value from a INPUT GPIO pin via PDIR register.
 * @param[in] PortHwId   The hardware ID of the port.
 * @param[in] PinHwId    The hardware ID of the pin.
 * @return Dio_LevelType The value read from the pin.
*/
Dio_LevelType Dio_Lld_ReadGPIOPin(Dio_PortType PortHwId, Dio_PinType PinHwId);

/**
 * @brief Write a value to a GPIO port.
 * @details This function writes a value to a OUTPUT GPIO port via PDOR register.
 * @param[in] PortHwId  The hardware ID of the port.
 * @param[in] Level     The value to be written to the port.
 * @return void
*/
void Dio_Lld_WriteGPIOPort(Dio_PortType PortHwId, Dio_PortLevelType Level);

/**
 * @brief Read a value from a GPIO port.
 * @details This function reads a value from a INPUT GPIO port via PDIR register.
 * @param[in] PortHwId   The hardware ID of the port.
 * @return Dio_PortLevelType The value read from the port.
*/
Dio_PortLevelType Dio_Lld_ReadGPIOPort(Dio_PortType PortHwId);

/**
 * @brief Toggle a value of a GPIO pin.
 * @details This function toggles a value of a GPIO pin via set bit of PTOR register.
 * @param[in] PortHwId  The hardware ID of the port.
 * @param[in] PinHwId   The hardware ID of the pin.
 * @return Dio_LevelType  The value read from the pin after toggle.
*/
Dio_LevelType Dio_Lld_ToggleGPIOPin(Dio_PortType PortHwId, Dio_PinType PinHwId);

#ifdef __cplusplus
}
#endif

#endif /* End of file Dio_Lld.h */

