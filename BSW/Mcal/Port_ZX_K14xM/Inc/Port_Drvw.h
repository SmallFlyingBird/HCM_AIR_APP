/**************************************************************************************************/
/**
 * @file      : Port_Drvw.h
 * @brief     : AUTOSAR Port Drvw driver headfile
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef PORT_DRVW_H
#define PORT_DRVW_H

/** @addtogroup Port_Module
 *  @{
 */

/** @addtogroup Port_Drvw
 *  @brief Port driver wrapper
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Port_Drvw_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define PORT_DRVW_H_VENDOR_ID                   0x00B3U
#define PORT_DRVW_H_AR_RELEASE_MAJOR_VERSION    4U
#define PORT_DRVW_H_AR_RELEASE_MINOR_VERSION    6U
#define PORT_DRVW_H_AR_RELEASE_REVISION_VERSION 0U
#define PORT_DRVW_H_SW_MAJOR_VERSION            1U
#define PORT_DRVW_H_SW_MINOR_VERSION            2U
#define PORT_DRVW_H_SW_PATCH_VERSION            1U

#if (PORT_DRVW_H_VENDOR_ID != PORT_DRVW_TYPES_H_VENDOR_ID)
    #error "Vendor id of Port_Drvw.h and Port_Drvw_types.h are different"
#endif

#if ((PORT_DRVW_H_AR_RELEASE_MAJOR_VERSION != PORT_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||       \
    (PORT_DRVW_H_AR_RELEASE_MINOR_VERSION != PORT_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION) ||        \
    (PORT_DRVW_H_AR_RELEASE_REVISION_VERSION != PORT_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar version of Port_Drvw.h and Port_Drvw_types.h are different"
#endif

#if ((PORT_DRVW_H_SW_MAJOR_VERSION != PORT_DRVW_TYPES_H_SW_MAJOR_VERSION ||                        \
    (PORT_DRVW_H_SW_MINOR_VERSION != PORT_DRVW_TYPES_H_SW_MINOR_VERSION) ||                        \
    (PORT_DRVW_H_SW_PATCH_VERSION != PORT_DRVW_TYPES_H_SW_PATCH_VERSION)))
    #error "Software version of Port_Drvw.h and Port_Drvw_types.h are different"
#endif

#define PORT_DRVW_E_DIRECTION_UNCHANGEABLE   (0x0BU)   /*!< Port direction unchangeable error */
#define PORT_DRVW_E_PARAM_INVALID_MODE       (0x0DU)   /*!< Port invalid parameter error */
#define PORT_DRVW_E_MODE_UNCHANGEABLE        (0x0EU)   /*!< Port mode unchangeable error */

#define PORT_DRVW_PIN_LEVEL_LOW  ((uint8)0) 
#define PORT_DRVW_PIN_LEVEL_HIGH ((uint8)1)

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
PORT_DRVW_CONFIG_EXT

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"
 
/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"

/**
 * @brief     This function initializes both the configured and un-configured pins
 *
 * @param[in] DrvwConfigPtr: Pointer to configuration set
 * 
 * @return    None
 */
void Port_Drvw_Init(const Port_Drvw_ConfigType *DrvwConfigPtr);

#if (STD_ON == PORT_DRVW_DEV_ERROR_DETECT)

#if (STD_ON == PORT_DRVW_SET_PIN_DIRECTION_API)
/**
 * @brief     This function checks if the port pin direction is changeable.
 *
 * @param[in] PinIndex:     Port pin index
 * @param[in] DrvwConfigPtr:    Pointer to configuration set
 * 
 * @return    Pin direction setting status
 * @retval    E_OK: Pin direction changeable
 * @retval    PORT_DRVW_E_DIRECTION_UNCHANGEABLE: Pin direction is not changeable
 */
Std_ReturnType Port_Drvw_CheckPinDirectionChangeable(Port_Drvw_PinType PinIndex, 
                                    const Port_Drvw_ConfigType *DrvwConfigPtr);
#endif /*(STD_ON == PORT_DRVW_SET_PIN_DIRECTION_API)*/

#if (STD_ON == PORT_DRVW_SET_PIN_MODE_API)
/**
 * @brief     This function checks if the port pin mode is changeable.
 *
 * @param[in] PinIndex:     Port pin index
 * @param[in] DrvwConfigPtr:    Pointer to configuration set
 * 
 * @return    Pin mode check status
 * @retval    E_OK: Pin mode is changeable
 * @retval    PORT_DRVW_E_MODE_UNCHANGEABLE: Pin mode is not changeable
 */
Std_ReturnType Port_Drvw_CheckPinModeChangeable(Port_Drvw_PinType PinIndex,
                                                const Port_Drvw_ConfigType *DrvwConfigPtr);
#endif /*(STD_ON == PORT_DRVW_SET_PIN_MODE_API)*/

#endif /*(STD_ON == PORT_DRVW_DEV_ERROR_DETECT)*/

#if (STD_ON == PORT_DRVW_SET_PIN_DIRECTION_API)
/**
 * @brief     This function sets the port pin direction.
 *
 * @param[in] PinIndex:     Port pin index
 * @param[in] Direction:    Port pin direction
 * @param[in] DrvwConfigPtr:    Pointer to configuration set
 * 
 * @return    None
 */
void Port_Drvw_SetPinDirection(Port_Drvw_PinType PinIndex, Port_Drvw_DirectionType Direction,
                                         const Port_Drvw_ConfigType *DrvwConfigPtr);
#endif /* (STD_ON == PORT_DRVW_SET_PIN_DIRECTION_API) */


#if (STD_ON == PORT_DRVW_SET_PIN_MODE_API)
/**
 * @brief     This function sets the port pin pinmux mode.
 *
 * @param[in] PinIndex:     Port pin index
 * @param[in] PinMode:      Port pin pinmux mode
 * @param[in] DrvwConfigPtr:    Pointer to configuration set
 * 
 * @return    None
 */
void Port_Drvw_SetPinMode(Port_Drvw_PinType PinIndex, Port_Drvw_PinModeType PinMode,
                                    const Port_Drvw_ConfigType *DrvwConfigPtr);
#endif /*(STD_ON == PORT_DRVW_SET_PIN_MODE_API)*/

/**
 * @brief     This function refresh the port direction for used pins.
 *
 * @param[in] DrvwConfigPtr: Pointer to configuration set
 * 
 * @return    None
 */
void Port_Drvw_RefreshPortDirection(const Port_Drvw_ConfigType *DrvwConfigPtr);

#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Port_Drvw */

/** @} end of group Port_Module */

#endif /*PORT_DRVW_H*/
