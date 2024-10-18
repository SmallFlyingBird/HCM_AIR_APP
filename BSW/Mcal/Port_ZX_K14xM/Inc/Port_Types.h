/**************************************************************************************************/
/**
 * @file      : Port_Types.h
 * @brief     : AUTOSAR Port types headfile
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef PORT_TYPES_H
#define PORT_TYPES_H

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

#include "Port_Drvw_Types.h"
#include "Port_Cfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define PORT_TYPES_H_VENDOR_ID                   0x00B3U
#define PORT_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define PORT_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define PORT_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define PORT_TYPES_H_SW_MAJOR_VERSION            1U
#define PORT_TYPES_H_SW_MINOR_VERSION            2U
#define PORT_TYPES_H_SW_PATCH_VERSION            1U

#if (PORT_TYPES_H_VENDOR_ID != PORT_DRVW_TYPES_H_VENDOR_ID)
    #error "Vendor id of Port_Types.h and Port_Drvw_Types.h are different"
#endif

#if ((PORT_TYPES_H_AR_RELEASE_MAJOR_VERSION != PORT_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||    \
     (PORT_TYPES_H_AR_RELEASE_MINOR_VERSION != PORT_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION) ||    \
     (PORT_TYPES_H_AR_RELEASE_REVISION_VERSION != PORT_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar version of Port_Types.h and Port_Drvw_Types.h are different"
#endif

#if ((PORT_TYPES_H_SW_MAJOR_VERSION != PORT_DRVW_TYPES_H_SW_MAJOR_VERSION) ||                    \
     (PORT_TYPES_H_SW_MINOR_VERSION != PORT_DRVW_TYPES_H_SW_MINOR_VERSION) ||                    \
     (PORT_TYPES_H_SW_PATCH_VERSION != PORT_DRVW_TYPES_H_SW_PATCH_VERSION))
    #error "Software version of Port_Types.h and Port_Drvw_Types.h are different"
#endif

#if (PORT_TYPES_H_VENDOR_ID != PORT_CFG_H_VENDOR_ID)
    #error "Vendor id of Port_Types.h and Port_Cfg.h are different"
#endif

#if ((PORT_TYPES_H_AR_RELEASE_MAJOR_VERSION != PORT_CFG_H_AR_RELEASE_MAJOR_VERSION) ||           \
     (PORT_TYPES_H_AR_RELEASE_MINOR_VERSION != PORT_CFG_H_AR_RELEASE_MINOR_VERSION) ||           \
     (PORT_TYPES_H_AR_RELEASE_REVISION_VERSION != PORT_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar version of Port_Types.h and Port_Cfg.h are different"
#endif

#if ((PORT_TYPES_H_SW_MAJOR_VERSION != PORT_CFG_H_SW_MAJOR_VERSION) ||                           \
     (PORT_TYPES_H_SW_MINOR_VERSION != PORT_CFG_H_SW_MINOR_VERSION) ||                           \
     (PORT_TYPES_H_SW_PATCH_VERSION != PORT_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Port_Types.h and Port_Cfg.h are different"
#endif

/* SWS_Port_00013,SWS_Port_00219*/
typedef uint32 Port_PinType;

/**
* @brief port pinmux modes.
*/
/* SWS_Port_00212,SWS_Port_00221*/
typedef uint8 Port_PinModeType;

#define PORT_PIN_MODE_ALT0             ((Port_PinModeType)0)   /*!< Pinmux ALT0*/
#define PORT_PIN_MODE_GPIO             ((Port_PinModeType)1)   /*!< Pinmux ALT1*/
#define PORT_PIN_MODE_ALT2             ((Port_PinModeType)2)   /*!< Pinmux ALT2*/
#define PORT_PIN_MODE_ALT3             ((Port_PinModeType)3)   /*!< Pinmux ALT3*/
#define PORT_PIN_MODE_ALT4             ((Port_PinModeType)4)   /*!< Pinmux ALT4*/
#define PORT_PIN_MODE_ALT5             ((Port_PinModeType)5)   /*!< Pinmux ALT5*/
#define PORT_PIN_MODE_ALT6             ((Port_PinModeType)6)   /*!< Pinmux ALT6*/
#define PORT_PIN_MODE_ALT7             ((Port_PinModeType)7)   /*!< Pinmux ALT7*/

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */
/**
 * @brief Port direction definition
 */
/* SWS_Port_00230,SWS_Port_00046,SWS_Port_00220*/
typedef enum
{
    PORT_PIN_IN = 0U,              /*!< Input*/
    PORT_PIN_OUT,                  /*!< Output*/
} Port_PinDirectionType;

/**
 * @brief Configured pin attributes
 */
typedef struct
{
    uint16 Pin;                             /*!< Autosar pin configuration id*/
    uint8 PinOutputLevel;                   /*!< Pin output level */
    Port_PinDirectionType PinDirection;     /*!< Pin direction */
    boolean GPIO;                           /*!< If pin configured as GPIO*/
    boolean DirectionChangebility;          /*!< If pin direction is changeable*/
    boolean ModeChangebility;               /*!< If pin mode is changeable*/
} Port_PinConfigType;

/**
 * @brief Overal pin configuration structure
 */
/* SWS_Port_00228*/
typedef struct
{
    uint16 NumConfigPins;                               /*!< Number of configured pins */
    const uint32 *Port_PinsPartitionTable;           /*!< Partition mapping table pointer */
    const uint8 *Port_PartitionTable;                   /*!< Partition table pointer */
    const Port_Drvw_ConfigType *DrvwConfigPtr;         /*!< Port/GPIO register configuration */
} Port_ConfigType;

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

/** @} end of group Port */

/** @} end of group Port_Module */

#endif /* PORT_TYPES_H */
