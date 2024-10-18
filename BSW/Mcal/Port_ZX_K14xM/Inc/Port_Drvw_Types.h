/**************************************************************************************************/
/**
 * @file      : Port_Drvw_Types.h
 * @brief     : AUTOSAR Port Drvw types headfile
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef PORT_DRVW_TYPES_H
#define PORT_DRVW_TYPES_H

/** @addtogroup Port_Module
 *  @{
 */

/** @addtogroup Port
 *  @brief Port AUTOSAR level
 *  @{
 */

#if defined(__cplusplus)
extern "C" {
#endif

#include "Port_Drv_Types.h"
#include "Port_Drvw_Cfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define PORT_DRVW_TYPES_H_VENDOR_ID                   0x00B3U
#define PORT_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define PORT_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define PORT_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define PORT_DRVW_TYPES_H_SW_MAJOR_VERSION            1U
#define PORT_DRVW_TYPES_H_SW_MINOR_VERSION            2U
#define PORT_DRVW_TYPES_H_SW_PATCH_VERSION            1U

#if (PORT_DRVW_TYPES_H_VENDOR_ID != PORT_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor id of Port_Drvw_Types.h and Port_Drv_Types.h are different"
#endif

#if ((PORT_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION != PORT_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||        \
     (PORT_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION != PORT_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||        \
     (PORT_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION != PORT_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar version of Port_Drvw_Types.h and Port_Drv_Types.h are different"
#endif

#if ((PORT_DRVW_TYPES_H_SW_MAJOR_VERSION != PORT_DRV_TYPES_H_SW_MAJOR_VERSION) ||                        \
     (PORT_DRVW_TYPES_H_SW_MINOR_VERSION != PORT_DRV_TYPES_H_SW_MINOR_VERSION) ||                        \
     (PORT_DRVW_TYPES_H_SW_PATCH_VERSION != PORT_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software version of Port_Drvw_Types.h and Port_Drv_Types.h are different"
#endif

#if (PORT_DRVW_TYPES_H_VENDOR_ID != PORT_DRVW_CFG_H_VENDOR_ID)
    #error "Vendor id of Port_Drvw_Types.h and Port_Drvw_Cfg.h are different"
#endif

#if ((PORT_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION != PORT_DRVW_CFG_H_AR_RELEASE_MAJOR_VERSION) ||          \
     (PORT_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION != PORT_DRVW_CFG_H_AR_RELEASE_MINOR_VERSION) ||          \
     (PORT_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION != PORT_DRVW_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar version of Port_Drvw_Types.h and Port_Drvw_Cfg.h are different"
#endif

#if ((PORT_DRVW_TYPES_H_SW_MAJOR_VERSION != PORT_DRVW_CFG_H_SW_MAJOR_VERSION) ||                          \
     (PORT_DRVW_TYPES_H_SW_MINOR_VERSION != PORT_DRVW_CFG_H_SW_MINOR_VERSION) ||                          \
     (PORT_DRVW_TYPES_H_SW_PATCH_VERSION != PORT_DRVW_CFG_H_SW_PATCH_VERSION))
    #error "Software version of Port_Drvw_Types.h and Port_Drvw_Cfg.h are different"
#endif

typedef uint32 Port_Drvw_PinType;

/**
* @brief port pinmux modes.
*/
typedef uint8 Port_Drvw_PinModeType;

#define PORT_DRVW_PIN_MODE_GPIO         ((Port_Drvw_PinModeType)1)   /*!< Pinmux ALT1*/

#define PORT_DRVW_GET_PORT_ID(PinNumber)    ((uint32)((uint32)(PinNumber) >> 5))
#define PORT_DRVW_GET_GPIO_ID(PinNumber)    ((uint32)((uint32)(PinNumber) & (uint32)31))
/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 * @brief Port id definition
 */
typedef enum
{
    PORT_DRVW_PORT_A = 0U, /*!< PORT A*/
    PORT_DRVW_PORT_B,      /*!< PORT B*/
    PORT_DRVW_PORT_C,      /*!< PORT C*/
    PORT_DRVW_PORT_D,      /*!< PORT D*/
    PORT_DRVW_PORT_E       /*!< PORT E*/
} Port_Drvw_PortIdType;

/**
 *  @brief Gpio number definition
 */
typedef enum
{
    PORT_DRVW_GPIO_0 = 0U, /*!< GPIO0 pin definition*/
    PORT_DRVW_GPIO_1,      /*!< GPIO1 pin definition*/
    PORT_DRVW_GPIO_2,      /*!< GPIO2 pin definition*/
    PORT_DRVW_GPIO_3,      /*!< GPIO3 pin definition*/
    PORT_DRVW_GPIO_4,      /*!< GPIO4 pin definition*/
    PORT_DRVW_GPIO_5,      /*!< GPIO5 pin definition*/
    PORT_DRVW_GPIO_6,      /*!< GPIO6 pin definition*/
    PORT_DRVW_GPIO_7,      /*!< GPIO7 pin definition*/
    PORT_DRVW_GPIO_8,      /*!< GPIO8 pin definition*/
    PORT_DRVW_GPIO_9,      /*!< GPIO9 pin definition*/
    PORT_DRVW_GPIO_10,     /*!< GPIO10 pin definition*/
    PORT_DRVW_GPIO_11,     /*!< GPIO11 pin definition*/
    PORT_DRVW_GPIO_12,     /*!< GPIO12 pin definition*/
    PORT_DRVW_GPIO_13,     /*!< GPIO13 pin definition*/
    PORT_DRVW_GPIO_14,     /*!< GPIO14 pin definition*/
    PORT_DRVW_GPIO_15,     /*!< GPIO15 pin definition*/
    PORT_DRVW_GPIO_16,     /*!< GPIO16 pin definition*/
    PORT_DRVW_GPIO_17,     /*!< GPIO17 pin definition*/
    PORT_DRVW_GPIO_18,     /*!< GPIO18 pin definition*/
    PORT_DRVW_GPIO_19,     /*!< GPIO19 pin definition*/
    PORT_DRVW_GPIO_20,     /*!< GPIO20 pin definition*/
    PORT_DRVW_GPIO_21,     /*!< GPIO21 pin definition*/
    PORT_DRVW_GPIO_22,     /*!< GPIO22 pin definition*/
    PORT_DRVW_GPIO_23,     /*!< GPIO23 pin definition*/
    PORT_DRVW_GPIO_24,     /*!< GPIO24 pin definition*/
    PORT_DRVW_GPIO_25,     /*!< GPIO25 pin definition*/
    PORT_DRVW_GPIO_26,     /*!< GPIO26 pin definition*/
    PORT_DRVW_GPIO_27,     /*!< GPIO27 pin definition*/
    PORT_DRVW_GPIO_28,     /*!< GPIO28 pin definition*/
    PORT_DRVW_GPIO_29,     /*!< GPIO29 pin definition*/
    PORT_DRVW_GPIO_30,     /*!< GPIO30 pin definition*/
    PORT_DRVW_GPIO_31      /*!< GPIO31 pin definition*/
} Port_Drvw_GpioNoType;

/**
 * @brief Port direction definition
 */
typedef enum
{
    PORT_DRVW_PIN_IN = 0U,              /*!< Input*/
    PORT_DRVW_PIN_OUT,                  /*!< Output*/
} Port_Drvw_DirectionType;

/**
 *  @brief Pin output level definition
 */
typedef enum
{
    PORT_DRVW_LEVEL_LOW = 0U, /*!< Low voltage*/
    PORT_DRVW_LEVEL_HIGH      /*!< High voltage*/
} Port_Drvw_GpioLvlType;

/**
 *  @brief Slew rate definition
 */
typedef enum
{
    PORT_DRVW_FAST_RATE = 0U, /*!< PORT fast rate */
    PORT_DRVW_SLOW_RATE       /*!< PORT slow rate */
} Port_Drvw_SlewRateType;

/**
 * @brief Pull type definition
 */
typedef enum
{
    PORT_DRVW_PULL_DISABLED = 0U, /*!< Pull disable*/
    PORT_DRVW_PULL_DOWN = 2U,     /*!< Pull down*/
    PORT_DRVW_PULL_UP = 3U,       /*!< Pull up*/
} Port_Drvw_PullConfigType;

/**
 * @brief Un-configured Pin attributes
 */
typedef struct
{
    Port_Drvw_DirectionType PinDirection;     /*!< Pin direction*/
    uint8    PinOutputLevel;                  /*!< Pin output level*/
    Port_Drvw_SlewRateType PinSlewRate;       /*!< Pin slew rate*/
    Port_Drvw_PullConfigType PinPullConfig;   /*!< Pin pull config*/
} Port_Drvw_UnconfigPinAttrType;

/**
 * @brief Configured pin attributes
 */
typedef struct
{
    uint16 Pin;                             /*!< Autosar pin configuration id*/
    uint8 PinOutputLevel;                   /*!< Pin output level */
    Port_Drvw_DirectionType PinDirection;     /*!< Pin direction */
    boolean GPIO;                           /*!< If pin configured as GPIO*/
    boolean DirectionChangebility;          /*!< If pin direction is changeable*/
    boolean ModeChangebility;               /*!< If pin mode is changeable*/
} Port_Drvw_ConfigPinAttrType;

/**
 * Port config type
 */
typedef struct
{
    uint16 NumConfigPins;                                           /*!< Number of configured pins */
    uint16 NumUnconfigPins;                                         /*!< Number of un-configured pins */
    const uint16 *UnconfigPinList;                                  /*!< Un-configured pin id list */
    const Port_Drvw_UnconfigPinAttrType *UnconfigPinConfigAttr;     /*!< Un-configured pin attributes*/
    const Port_Drvw_ConfigPinAttrType *ConfigPinAttr;               /*!< Configured pin attributes */
    const Port_Drv_ConfigType *DrvConfigPtr;
} Port_Drvw_ConfigType;
/** @} end of group Public_TypeDefinition */

#if defined(__cplusplus)
}
#endif

/** @} end of group Port */

/** @} end of group Port_Module */

#endif /* PORT_DRVW_TYPES_H */
