/**
 *   @file    Std_Types.h
 *   @version
 *
 *   @brief   Stander type define
 *
 *   @addtogroup GENERAL
 *   @{
 */
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : V2.3.0
*
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/
#ifndef STD_TYPES_H
#define STD_TYPES_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/
#include "Compiler.h"
#include "Platform_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define STD_VENDOR_ID                     (180)
#define STD_AR_RELEASE_MAJOR_VERSION      (4)
#define STD_AR_RELEASE_MINOR_VERSION      (4)
#define STD_AR_RELEASE_REVISION_VERSION   (0)
#define STD_SW_MAJOR_VERSION              (2)
#define STD_SW_MINOR_VERSION              (3)
#define STD_SW_PATCH_VERSION              (0)

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/**
 * @brief OK and not OK define
 * @note range:
 *         - E_OK     : 0
 *         - E_NOT_OK : 1
 *         - 0x02-0x3F: 2 (Available to user specific errors)
 */
#ifndef STATUSTYPEDEFINED
#define STATUSTYPEDEFINED
typedef unsigned char StatusType;
#define E_OK (0U)
#endif
#define E_NOT_OK (1U)

/**
 * @brief High and low define
 */
#define STD_HIGH (1U) /**< Physical state 5V or 3.3V             */
#define STD_LOW (0U)  /**< Physical state 0V                     */

/**
 * @brief Acticve and idle define
 */
#define STD_ACTIVE (1U) /**< Logical state active                  */
#define STD_IDLE (0U)   /**< Logical state idle                    */

/**
 * @brief On and off define
 */
#define STD_ON (0x01u)
#define STD_OFF (0x00u)

typedef uint8 Std_ReturnType;

typedef struct
{
    uint16 vendorID;          /**< Vendor ID of the module */
    uint16 moduleID;          /**< Module ID of the module */
    uint8 sw_major_version;   /**< Software major version */
    uint8 sw_minor_version;   /**< Software minor version */
    uint8 sw_patch_version;   /**< Software patch version */
} Std_VersionInfoType;

#endif /* STD_TYPES_H */
/** @} */

