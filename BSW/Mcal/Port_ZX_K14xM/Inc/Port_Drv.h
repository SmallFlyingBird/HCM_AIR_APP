/**************************************************************************************************/
/**
 * @file      : Port_Drv.h
 * @brief     : AUTOSAR Port driver headfile
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef PORT_DRV_H
#define PORT_DRV_H

/** @addtogroup Port_Module
 *  @{
 */

/** @addtogroup Port_Drv
 *  @brief Port low level driver
 *  @{
 */

#if defined(__cplusplus)
extern "C" {
#endif

#include "Port_Drv_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define PORT_DRV_H_VENDOR_ID                   0x00B3U
#define PORT_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define PORT_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define PORT_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define PORT_DRV_H_SW_MAJOR_VERSION            1U
#define PORT_DRV_H_SW_MINOR_VERSION            2U
#define PORT_DRV_H_SW_PATCH_VERSION            1U

#if (PORT_DRV_H_VENDOR_ID != PORT_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor id of Port_Drv.h and Port_Drv_Types.h are different"
#endif

#if ((PORT_DRV_H_AR_RELEASE_MAJOR_VERSION != PORT_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||         \
     (PORT_DRV_H_AR_RELEASE_MINOR_VERSION != PORT_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||         \
     (PORT_DRV_H_AR_RELEASE_REVISION_VERSION != PORT_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar version of Port_Drv.h and Port_Drv_Types.h are different"
#endif

#if ((PORT_DRV_H_SW_MAJOR_VERSION != PORT_DRV_TYPES_H_SW_MAJOR_VERSION) ||                         \
     (PORT_DRV_H_SW_MINOR_VERSION != PORT_DRV_TYPES_H_SW_MINOR_VERSION) ||                         \
     (PORT_DRV_H_SW_PATCH_VERSION != PORT_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software version of Port_Drv.h and Port_Drv_Types.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"
/**
 * @brief   Export Post-Build configurations.
 */
PORT_DRV_CONFIG_EXT

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"
 
/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
/* @brief Allocate defined section for PORT code. */
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"

/**
 * @brief       This function writes a pin with 'Set' value.
 *
 * @param[in]   PortId: Select pin PORT ID: PORT_A, PORT_B, PORT_C,
 *                      PORT_D, PORT_E.
 * @param[in]   GpioNo: Select the GPIO pin,such as GPIO_0~GPIO_31.
 *
 * @return      None.
 */
void Port_Drv_SetPinOutput(Port_Drv_PortIdType PortId, Port_Drv_GpioNoType GpioNo);

/**
 * @brief       This function writes a pin to 'Clear' value.
 *
 * @param[in]   PortId: Select pin PORT ID: PORT_A, PORT_B, PORT_C,
 *                      PORT_D, PORT_E.
 * @param[in]   GpioNo: Select the GPIO pin,such as GPIO_0~GPIO_31.
 *
 * @return      None.
 */
void Port_Drv_ClearPinOutput(Port_Drv_PortIdType PortId, Port_Drv_GpioNoType GpioNo);

/**
 * @brief       This function sets the pin Direction.
 *
 * @param[in]   PortId: Select pin PORT ID: PORT_A, PORT_B, PORT_C,
 *                      PORT_D, PORT_E.
 * @param[in]   GpioNo: Select the GPIO pin,such as GPIO_0~GPIO_31.
 * @param[in]   Direction: Select  I/O Direction of a pin.
 *
 * @return      None.
 */
void Port_Drv_SetPinDirection(Port_Drv_PortIdType PortId, Port_Drv_GpioNoType GpioNo,
                    Port_Drv_DirectionType Direction);

/**
 * @brief       This function initializes port pin.
 *
 * @param[in]   PinCount: total number of the pins to be initialized.
 * @param[in]   Config: Pointer to the pin setting structure.
 *
 * @return      None.
 */
void Port_Drv_Init(uint32 PinCount, const Port_Drv_ConfigType Config[]);

/**
 * @brief       This function configures the pin muxing.
 *
 * @param[in]   PortId:      Select the PORT id,such as PORT_A,PORT_B,PORT_C
 *                          PORT_D,PORT_E.
 * @param[in]   GpioNo:      Select the GPIO pin,such as GPIO_0~GPIO_31.
 * @param[in]   PinMode:  Pin mux function.
 *
 * @return      None.
 */
void Port_Drv_SetPinMode(Port_Drv_PortIdType PortId, Port_Drv_GpioNoType GpioNo,
                         Port_Drv_PortMuxType PinMode);

/**
 * @brief       This function configures the slew rate.
 *
 * @param[in]   PortId:   Select the PORT id,such as PORT_A,PORT_B,PORT_C
 *                          PORT_D,PORT_E.
 * @param[in]   GpioNo:   Select the GPIO pin,such as GPIO_0~GPIO_31.
 * @param[in]   SlewRateConfig:  Slew Rate.
 *
 * @return      None.
 */
void Port_Drv_SetSlewRate(Port_Drv_PortIdType PortId, Port_Drv_GpioNoType GpioNo,
                          Port_Drv_SlewRateType SlewRateConfig);

/**
 * @brief       This function configures the pin pull configure.
 *
 * @param[in]   PortId:   Select the PORT id,such as PORT_A,PORT_B,PORT_C
 *                          PORT_D,PORT_E.
 * @param[in]   GpioNo:   Select the GPIO pin,such as GPIO_0~GPIO_31.
 * @param[in]   PullConfig:  Pull Configure value.
 *
 * @return      None.
 */
void Port_Drv_SetPullConfig(Port_Drv_PortIdType PortId, Port_Drv_GpioNoType GpioNo,
                            Port_Drv_PullConfigType PullConfig);

#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#if defined(__cplusplus)
}
#endif

/** @} end of group Port_Drv */

/** @} end of group Port_Module */

#endif /* PORT_DRV_H */
