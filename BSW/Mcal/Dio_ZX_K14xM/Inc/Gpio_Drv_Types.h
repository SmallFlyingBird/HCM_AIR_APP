/**************************************************************************************************/
/**
 * @file      : Gpio_Drv_Types.h
 * @brief     : Gpio low level driver type definition file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef GPIO_DRV_TYPES_H
#define GPIO_DRV_TYPES_H

/** @addtogroup  Gpio_Module
 *  @{
 */

/** @addtogroup Gpio_Drv
 *  @brief Gpio low level driver
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "McalLib.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define GPIO_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define GPIO_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define GPIO_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define GPIO_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define GPIO_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define GPIO_DRV_TYPES_H_SW_MINOR_VERSION            2U
#define GPIO_DRV_TYPES_H_SW_PATCH_VERSION            1U

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Std_Types.h are the same Autosar version */
    #if ((GPIO_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) ||            \
         (GPIO_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Gpio_Drv_Types.h and Std_Types.h are different"
    #endif

    /* Check if current file and McalLib.h are the same Autosar version */
    #if ((GPIO_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) ||        \
         (GPIO_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Gpio_Drv_Types.h and McalLib.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */
#define GPIO_DRV_CHANNEL_MASK     ((uint32)0x1FU)
#define GPIO_DRV_PORTID_SHIFT     ((uint8)5U)
#define GPIO_DRV_PORT(channel)    ((uint32)((uint32)(channel) >> GPIO_DRV_PORTID_SHIFT))
#define GPIO_DRV_CHANNEL(channel) ((uint32)((uint32)(channel)&GPIO_DRV_CHANNEL_MASK))
/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/*!
 * @brief Type of a GPIO channel representation
 */
typedef uint32 Gpio_Drv_PinsChannelType;

/*!
 * @brief Type of a port levels representation.
 */
typedef uint8 Gpio_Drv_PinsLevelType;

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Gpio_Drv */

/** @} end of group Gpio_Module */

#endif /*GPIO_DRV_TYPES*/
