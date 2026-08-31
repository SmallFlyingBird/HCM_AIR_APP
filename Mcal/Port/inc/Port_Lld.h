/**
* @file    Port_Lld.h
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Port_Lld
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

#ifndef PORT_LLD_H
#define PORT_LLD_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                          INCLUDE FILES
==================================================================================================*/
#include "Port.h"
/*==================================================================================================
 *                                  HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define PORT_LLD_VENDOR_ID                      (180)
#define PORT_LLD_AR_RELEASE_MAJOR_VERSION       (4)
#define PORT_LLD_AR_RELEASE_MINOR_VERSION       (4)
#define PORT_LLD_AR_RELEASE_REVISION_VERSION    (0)
#define PORT_LLD_SW_MAJOR_VERSION               (2)
#define PORT_LLD_SW_MINOR_VERSION               (3)
#define PORT_LLD_SW_PATCH_VERSION               (0)

/*==================================================================================================
 *                                        FUNCTION PROTOTYPES
==================================================================================================*/
/**
 * @brief This function sets the specified pin's mode to the specified mode.
 *
 * @param[in] Port Hardware port ID
 * @param[in] Pin Hardware pin ID
 * @param[in] Mode Pin mode type
 */
void Port_Lld_SetPinMode(Port_HwPortType Port, Port_HwPinType Pin, Port_PinModeType Mode);

/**
 * @brief This function sets the specified pin's direction to the specified value.
 *
 * @param[in] Port Hardware port ID
 * @param[in] Pin Hardware pin ID
 * @param[in] Direction Pin direction
 * @note If an incorrect port and pin combination is used, the function will have no effect.
 *       Please ensure that the correct port and pin are used.
 */
void Port_Lld_SetPinDirection(Port_HwPortType Port, Port_HwPinType Pin, Port_PinDirectionType Direction);

/**
 * @brief This function determines if the specified pin's mode is changeable.
 *
 * @param[in] ConfigPtr Pointer to the port configuration, containing all port and pin config information
 * @param[in] Port Hardware port ID
 * @param[in] Pin Hardware pin ID
 * @return boolean Whether the pin mode is changeable
 */
boolean Port_Lld_IsPinModeChangeable(const Port_ConfigType *ConfigPtr, Port_HwPortType Port, Port_HwPinType Pin);

/**
 * @brief This function determines if the specified pin's direction is changeable.
 *
 * @param[in] ConfigPtr Pointer to the port configuration, containing all port and pin config information
 * @param[in] Port Hardware port ID
 * @param[in] Pin Hardware pin ID
 * @return boolean Whether the pin direction is changeable
 */
boolean Port_Lld_IsPinDireChangeable(const Port_ConfigType *ConfigPtr, Port_HwPortType Port, Port_HwPinType Pin);

/**
 * @brief This function refreshes the pins specified in ConfigPtr, where the pin direction is unchangeable.
 *
 * @param[in] ConfigPtr Pointer to the port configuration, containing all port and pin config information
 */
void Port_Lld_RefreshPortDirection(const Port_ConfigType *ConfigPtr);

/**
 * @brief This function sets the pins' relative register using the configuration specified in ConfigPtr.
 *
 * @param[in] ConfigPtr Pointer to the port configuration, containing all port and pin config information
 */
void Port_Lld_Init(const Port_ConfigType *ConfigPtr);



#ifdef __cplusplus
}
#endif

#endif /* End of file Port_Lld.h */

