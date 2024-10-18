/**************************************************************************************************/
/**
 * @file      : Port_Drv_Types.h
 * @brief     : AUTOSAR Port driver types headfile
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef PORT_DRV_TYPES_H
#define PORT_DRV_TYPES_H

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

#include "Std_Types.h"
#include "Port_Drv_Cfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define PORT_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define PORT_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define PORT_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define PORT_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define PORT_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define PORT_DRV_TYPES_H_SW_MINOR_VERSION            2U
#define PORT_DRV_TYPES_H_SW_PATCH_VERSION            1U

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if ((PORT_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) ||            \
         (PORT_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar version of Port_Drv_Types.h and Std_Types.h are different"
    #endif
#endif

#if (PORT_DRV_TYPES_H_VENDOR_ID != PORT_DRV_CFG_H_VENDOR_ID)
    #error "Vendor id of Port_Drv_Types.h and Port_Drv_Cfg.h are different"
#endif

#if ((PORT_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != PORT_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) ||     \
     (PORT_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != PORT_DRV_CFG_H_AR_RELEASE_MINOR_VERSION) ||     \
     (PORT_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION != PORT_DRV_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar version of Port_Drv_Types.h and Port_Drv_Cfg.h are different"
#endif

#if ((PORT_DRV_TYPES_H_SW_MAJOR_VERSION != PORT_DRV_CFG_H_SW_MAJOR_VERSION) ||                     \
     (PORT_DRV_TYPES_H_SW_MINOR_VERSION != PORT_DRV_CFG_H_SW_MINOR_VERSION) ||                     \
     (PORT_DRV_TYPES_H_SW_PATCH_VERSION != PORT_DRV_CFG_H_SW_PATCH_VERSION))
    #error "Software version of Port_Drv_Types.h and Port_Drv_Cfg.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 * @brief Pull type definition
 */
typedef enum
{
    PORT_DRV_PULL_DISABLED = 0U, /*!< Pull disable*/
    PORT_DRV_PULL_DOWN = 2U,     /*!< Pull down*/
    PORT_DRV_PULL_UP = 3U,       /*!< Pull up*/
} Port_Drv_PullConfigType;

/**
 * @brief Pinmux function definition
 */
typedef enum
{
    PORT_DRV_PIN_MODE_ALT0 = 0U,
    PORT_DRV_PIN_MODE_GPIO = 1U,
    PORT_DRV_PIN_MODE_ALT2 = 2U,
    PORT_DRV_PIN_MODE_ALT3 = 3U,
    PORT_DRV_PIN_MODE_ALT4 = 4U,
    PORT_DRV_PIN_MODE_ALT5 = 5U,
    PORT_DRV_PIN_MODE_ALT6 = 6U,
    PORT_DRV_PIN_MODE_ALT7 = 7U
} Port_Drv_PortMuxType;

/**
 * @brief Port direction definition
 */
typedef enum
{
    PORT_DRV_PIN_IN = 0U,  /*!< Input*/
    PORT_DRV_PIN_OUT = 1U, /*!< Output. */
} Port_Drv_DirectionType;

/**
 * @brief Port id definition
 */
typedef enum
{
    PORT_DRV_PORT_A = 0U, /*!< PORT A*/
    PORT_DRV_PORT_B,      /*!< PORT B*/
    PORT_DRV_PORT_C,      /*!< PORT C*/
    PORT_DRV_PORT_D,      /*!< PORT D*/
    PORT_DRV_PORT_E       /*!< PORT E*/
} Port_Drv_PortIdType;

/**
 *  @brief Slew rate definition
 */
typedef enum
{
    PORT_DRV_FAST_RATE = 0U, /*!< PORT fast rate */
    PORT_DRV_SLOW_RATE       /*!< PORT slow rate */
} Port_Drv_SlewRateType;

/**
 *  @brief Pin output level definition
 */
typedef enum
{
    PORT_DRV_LEVEL_LOW = 0U, /*!< Low voltage*/
    PORT_DRV_LEVEL_HIGH      /*!< High voltage*/
} Port_Drv_GpioLvlType;

/**
 *  @brief Gpio number definition
 */
typedef enum
{
    PORT_DRV_GPIO_0 = 0U, /*!< GPIO0 pin definition*/
    PORT_DRV_GPIO_1,      /*!< GPIO1 pin definition*/
    PORT_DRV_GPIO_2,      /*!< GPIO2 pin definition*/
    PORT_DRV_GPIO_3,      /*!< GPIO3 pin definition*/
    PORT_DRV_GPIO_4,      /*!< GPIO4 pin definition*/
    PORT_DRV_GPIO_5,      /*!< GPIO5 pin definition*/
    PORT_DRV_GPIO_6,      /*!< GPIO6 pin definition*/
    PORT_DRV_GPIO_7,      /*!< GPIO7 pin definition*/
    PORT_DRV_GPIO_8,      /*!< GPIO8 pin definition*/
    PORT_DRV_GPIO_9,      /*!< GPIO9 pin definition*/
    PORT_DRV_GPIO_10,     /*!< GPIO10 pin definition*/
    PORT_DRV_GPIO_11,     /*!< GPIO11 pin definition*/
    PORT_DRV_GPIO_12,     /*!< GPIO12 pin definition*/
    PORT_DRV_GPIO_13,     /*!< GPIO13 pin definition*/
    PORT_DRV_GPIO_14,     /*!< GPIO14 pin definition*/
    PORT_DRV_GPIO_15,     /*!< GPIO15 pin definition*/
    PORT_DRV_GPIO_16,     /*!< GPIO16 pin definition*/
    PORT_DRV_GPIO_17,     /*!< GPIO17 pin definition*/
    PORT_DRV_GPIO_18,     /*!< GPIO18 pin definition*/
    PORT_DRV_GPIO_19,     /*!< GPIO19 pin definition*/
    PORT_DRV_GPIO_20,     /*!< GPIO20 pin definition*/
    PORT_DRV_GPIO_21,     /*!< GPIO21 pin definition*/
    PORT_DRV_GPIO_22,     /*!< GPIO22 pin definition*/
    PORT_DRV_GPIO_23,     /*!< GPIO23 pin definition*/
    PORT_DRV_GPIO_24,     /*!< GPIO24 pin definition*/
    PORT_DRV_GPIO_25,     /*!< GPIO25 pin definition*/
    PORT_DRV_GPIO_26,     /*!< GPIO26 pin definition*/
    PORT_DRV_GPIO_27,     /*!< GPIO27 pin definition*/
    PORT_DRV_GPIO_28,     /*!< GPIO28 pin definition*/
    PORT_DRV_GPIO_29,     /*!< GPIO29 pin definition*/
    PORT_DRV_GPIO_30,     /*!< GPIO30 pin definition*/
    PORT_DRV_GPIO_31      /*!< GPIO31 pin definition*/
} Port_Drv_GpioNoType;

/**
 * @brief Port and pin configuration
 */
typedef struct
{
    Port_Drv_PortIdType         PortId;          /*!< The PORT ID.                  */
    Port_Drv_GpioNoType         GpioNo;          /*!< Gpio number in a port.        */
    Port_Drv_PullConfigType     PullConfig;      /*!< Pull selection.               */
    Port_Drv_PortMuxType        PinMode;         /*!< Port pinmux.                  */
    Port_Drv_DirectionType      Direction;       /*!< Pin direction selection.      */
    Port_Drv_SlewRateType       SlewRate;        /*!< Slew rate.                    */
    boolean                     PassiveFilter;   /*!< Passive filter                */
    boolean                     FilterEnable;    /*!< Filter enablement.            */
    uint8                       FilterConfig;    /*!< Filter value.                 */
    boolean                     OpenDrainConfig; /*!< Configures open drain.        */
    Port_Drv_GpioLvlType        InitValue;       /*!< GPIO initial value.           */
} Port_Drv_ConfigType;

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
 
/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/** @} end of group Public_FunctionDeclaration */

#if defined(__cplusplus)
}
#endif

/** @} end of group Port_Drv */

/** @} end of group Port_Module */

#endif /* PORT_DRV_TYPES_H */
