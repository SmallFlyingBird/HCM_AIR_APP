/**************************************************************************************************/
/**
 * @file      : Port_Drv_PBcfg.c
 * @brief     : AUTOSAR Port low level driver config file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup Port_Module
 *  @{
 */

/** @addtogroup Port_Drv_Configuration
 *  @brief Port low level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Port_Drv.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define PORT_DRV_PBCFG_C_VENDOR_ID                   0x00B3U
#define PORT_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define PORT_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define PORT_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define PORT_DRV_PBCFG_C_SW_MAJOR_VERSION            1U
#define PORT_DRV_PBCFG_C_SW_MINOR_VERSION            2U
#define PORT_DRV_PBCFG_C_SW_PATCH_VERSION            2U

/* Check if the vendor id of current file and Port_Drv.h are the same*/
#if (PORT_DRV_PBCFG_C_VENDOR_ID != PORT_DRV_H_VENDOR_ID)
    #error "Vendor id of Port_Drv_PBcfg.c and Port_Drv.h are diffrent"
#endif
/* Check if Autosar version of Port_Drv_PBcfg.c and Port_Drv.h are the same */
#if ((PORT_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != PORT_DRV_H_AR_RELEASE_MAJOR_VERSION)  || \
     (PORT_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    != PORT_DRV_H_AR_RELEASE_MINOR_VERSION)  || \
     (PORT_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION != PORT_DRV_H_AR_RELEASE_REVISION_VERSION)  \
    )
    #error "AutoSar version of Port_Drv_PBcfg.c and Port_Drv.h are different"
#endif
/* Check if software version of Port_Drv_PBcfg.c and Port_Drv.h are the same */
#if ((PORT_DRV_PBCFG_C_SW_MAJOR_VERSION != PORT_DRV_H_SW_MAJOR_VERSION) || \
     (PORT_DRV_PBCFG_C_SW_MINOR_VERSION != PORT_DRV_H_SW_MINOR_VERSION) || \
     (PORT_DRV_PBCFG_C_SW_PATCH_VERSION != PORT_DRV_H_SW_PATCH_VERSION)    \
    )
    #error "Software version of Port_Drv_PBcfg.c and Port_Drv.h are different"
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
 * @brief  PreDefined Port Configuration
 */
/*SWS_Port_00228*/
const Port_Drv_ConfigType Port_DrvConfig[NUMBER_OF_CONFIG_PINS] =
{
    {
        .PortId                      = PORT_DRV_PORT_A,
        .GpioNo                      = PORT_DRV_GPIO_7,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_ALT0,
        .Direction                   = PORT_DRV_PIN_IN,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE
    },
    {
        .PortId                      = PORT_DRV_PORT_A,
        .GpioNo                      = PORT_DRV_GPIO_6,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_GPIO,
        .Direction                   = PORT_DRV_PIN_IN,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE,
        .InitValue                   = PORT_DRV_LEVEL_LOW
    },
    {
        .PortId                      = PORT_DRV_PORT_A,
        .GpioNo                      = PORT_DRV_GPIO_2,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_ALT2,
        .Direction                   = PORT_DRV_PIN_OUT,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE
    },
    {
        .PortId                      = PORT_DRV_PORT_A,
        .GpioNo                      = PORT_DRV_GPIO_0,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_ALT0,
        .Direction                   = PORT_DRV_PIN_IN,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE
    },
    {
        .PortId                      = PORT_DRV_PORT_A,
        .GpioNo                      = PORT_DRV_GPIO_13,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_ALT2,
        .Direction                   = PORT_DRV_PIN_OUT,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE
    },
    {
        .PortId                      = PORT_DRV_PORT_A,
        .GpioNo                      = PORT_DRV_GPIO_12,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_ALT2,
        .Direction                   = PORT_DRV_PIN_OUT,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE
    },
    {
        .PortId                      = PORT_DRV_PORT_A,
        .GpioNo                      = PORT_DRV_GPIO_11,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_ALT5,
        .Direction                   = PORT_DRV_PIN_OUT,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE
    },
    {
        .PortId                      = PORT_DRV_PORT_A,
        .GpioNo                      = PORT_DRV_GPIO_10,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_ALT5,
        .Direction                   = PORT_DRV_PIN_IN,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE
    },
    {
        .PortId                      = PORT_DRV_PORT_B,
        .GpioNo                      = PORT_DRV_GPIO_4,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_GPIO,
        .Direction                   = PORT_DRV_PIN_OUT,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE,
        .InitValue                   = PORT_DRV_LEVEL_HIGH
    },
    {
        .PortId                      = PORT_DRV_PORT_B,
        .GpioNo                      = PORT_DRV_GPIO_2,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_GPIO,
        .Direction                   = PORT_DRV_PIN_OUT,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE,
        .InitValue                   = PORT_DRV_LEVEL_LOW
    },
    {
        .PortId                      = PORT_DRV_PORT_B,
        .GpioNo                      = PORT_DRV_GPIO_0,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_GPIO,
        .Direction                   = PORT_DRV_PIN_IN,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE,
        .InitValue                   = PORT_DRV_LEVEL_LOW
    },
    {
        .PortId                      = PORT_DRV_PORT_B,
        .GpioNo                      = PORT_DRV_GPIO_17,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_GPIO,
        .Direction                   = PORT_DRV_PIN_IN,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE,
        .InitValue                   = PORT_DRV_LEVEL_LOW
    },
    {
        .PortId                      = PORT_DRV_PORT_B,
        .GpioNo                      = PORT_DRV_GPIO_12,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_ALT0,
        .Direction                   = PORT_DRV_PIN_IN,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE
    },
    {
        .PortId                      = PORT_DRV_PORT_B,
        .GpioNo                      = PORT_DRV_GPIO_11,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_GPIO,
        .Direction                   = PORT_DRV_PIN_OUT,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE,
        .InitValue                   = PORT_DRV_LEVEL_LOW
    },
    {
        .PortId                      = PORT_DRV_PORT_B,
        .GpioNo                      = PORT_DRV_GPIO_9,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_ALT2,
        .Direction                   = PORT_DRV_PIN_OUT,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE
    },
    {
        .PortId                      = PORT_DRV_PORT_B,
        .GpioNo                      = PORT_DRV_GPIO_8,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_GPIO,
        .Direction                   = PORT_DRV_PIN_OUT,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE,
        .InitValue                   = PORT_DRV_LEVEL_LOW
    },
    {
        .PortId                      = PORT_DRV_PORT_C,
        .GpioNo                      = PORT_DRV_GPIO_3,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_ALT0,
        .Direction                   = PORT_DRV_PIN_IN,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE
    },
    {
        .PortId                      = PORT_DRV_PORT_C,
        .GpioNo                      = PORT_DRV_GPIO_2,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_ALT0,
        .Direction                   = PORT_DRV_PIN_IN,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE
    },
    {
        .PortId                      = PORT_DRV_PORT_C,
        .GpioNo                      = PORT_DRV_GPIO_1,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_ALT0,
        .Direction                   = PORT_DRV_PIN_IN,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE
    },
    {
        .PortId                      = PORT_DRV_PORT_C,
        .GpioNo                      = PORT_DRV_GPIO_0,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_ALT0,
        .Direction                   = PORT_DRV_PIN_IN,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE
    },
    {
        .PortId                      = PORT_DRV_PORT_C,
        .GpioNo                      = PORT_DRV_GPIO_16,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_ALT0,
        .Direction                   = PORT_DRV_PIN_IN,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE
    },
    {
        .PortId                      = PORT_DRV_PORT_C,
        .GpioNo                      = PORT_DRV_GPIO_15,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_ALT0,
        .Direction                   = PORT_DRV_PIN_IN,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE
    },
    {
        .PortId                      = PORT_DRV_PORT_C,
        .GpioNo                      = PORT_DRV_GPIO_8,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_GPIO,
        .Direction                   = PORT_DRV_PIN_IN,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE,
        .InitValue                   = PORT_DRV_LEVEL_LOW
    },
    {
        .PortId                      = PORT_DRV_PORT_C,
        .GpioNo                      = PORT_DRV_GPIO_7,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_ALT2,
        .Direction                   = PORT_DRV_PIN_OUT,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE
    },
    {
        .PortId                      = PORT_DRV_PORT_C,
        .GpioNo                      = PORT_DRV_GPIO_6,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_ALT2,
        .Direction                   = PORT_DRV_PIN_IN,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE
    },
    {
        .PortId                      = PORT_DRV_PORT_C,
        .GpioNo                      = PORT_DRV_GPIO_17,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_ALT0,
        .Direction                   = PORT_DRV_PIN_IN,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE
    },
    {
        .PortId                      = PORT_DRV_PORT_D,
        .GpioNo                      = PORT_DRV_GPIO_16,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_ALT6,
        .Direction                   = PORT_DRV_PIN_IN,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE
    },
    {
        .PortId                      = PORT_DRV_PORT_D,
        .GpioNo                      = PORT_DRV_GPIO_15,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_GPIO,
        .Direction                   = PORT_DRV_PIN_OUT,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE,
        .InitValue                   = PORT_DRV_LEVEL_HIGH
    },
    {
        .PortId                      = PORT_DRV_PORT_D,
        .GpioNo                      = PORT_DRV_GPIO_13,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_ALT5,
        .Direction                   = PORT_DRV_PIN_OUT,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE
    },
    {
        .PortId                      = PORT_DRV_PORT_D,
        .GpioNo                      = PORT_DRV_GPIO_11,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_ALT5,
        .Direction                   = PORT_DRV_PIN_OUT,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE
    },
    {
        .PortId                      = PORT_DRV_PORT_D,
        .GpioNo                      = PORT_DRV_GPIO_10,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_ALT5,
        .Direction                   = PORT_DRV_PIN_IN,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE
    },
    {
        .PortId                      = PORT_DRV_PORT_D,
        .GpioNo                      = PORT_DRV_GPIO_2,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_GPIO,
        .Direction                   = PORT_DRV_PIN_OUT,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE,
        .InitValue                   = PORT_DRV_LEVEL_HIGH
    },
    {
        .PortId                      = PORT_DRV_PORT_D,
        .GpioNo                      = PORT_DRV_GPIO_14,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_ALT7,
        .Direction                   = PORT_DRV_PIN_IN,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE
    },
    {
        .PortId                      = PORT_DRV_PORT_E,
        .GpioNo                      = PORT_DRV_GPIO_16,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_GPIO,
        .Direction                   = PORT_DRV_PIN_OUT,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE,
        .InitValue                   = PORT_DRV_LEVEL_HIGH
    },
    {
        .PortId                      = PORT_DRV_PORT_E,
        .GpioNo                      = PORT_DRV_GPIO_15,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_GPIO,
        .Direction                   = PORT_DRV_PIN_OUT,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE,
        .InitValue                   = PORT_DRV_LEVEL_LOW
    },
    {
        .PortId                      = PORT_DRV_PORT_E,
        .GpioNo                      = PORT_DRV_GPIO_3,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_GPIO,
        .Direction                   = PORT_DRV_PIN_OUT,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE,
        .InitValue                   = PORT_DRV_LEVEL_HIGH
    },
    {
        .PortId                      = PORT_DRV_PORT_E,
        .GpioNo                      = PORT_DRV_GPIO_12,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_GPIO,
        .Direction                   = PORT_DRV_PIN_OUT,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE,
        .InitValue                   = PORT_DRV_LEVEL_LOW
    },
    {
        .PortId                      = PORT_DRV_PORT_E,
        .GpioNo                      = PORT_DRV_GPIO_8,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_ALT2,
        .Direction                   = PORT_DRV_PIN_OUT,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE
    },
    {
        .PortId                      = PORT_DRV_PORT_E,
        .GpioNo                      = PORT_DRV_GPIO_7,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_GPIO,
        .Direction                   = PORT_DRV_PIN_OUT,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE,
        .InitValue                   = PORT_DRV_LEVEL_LOW
    },
    {
        .PortId                      = PORT_DRV_PORT_E,
        .GpioNo                      = PORT_DRV_GPIO_1,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_ALT4,
        .Direction                   = PORT_DRV_PIN_OUT,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE
    },

    {
        .PortId                      = PORT_DRV_PORT_E,
        .GpioNo                      = PORT_DRV_GPIO_0,
        .PullConfig                  = PORT_DRV_PULL_DISABLED,
        .PinMode                     = PORT_DRV_PIN_MODE_ALT4,
        .Direction                   = PORT_DRV_PIN_IN,
        .SlewRate                    = PORT_DRV_SLOW_RATE,
        .FilterEnable                = (boolean)FALSE,
        .FilterConfig                = 0,
        .OpenDrainConfig             = (boolean)FALSE
    }

};

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Port_Drv_Configuration */

/** @} end of group Port_Module */
