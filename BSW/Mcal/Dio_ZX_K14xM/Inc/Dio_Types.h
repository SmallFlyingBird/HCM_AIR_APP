/**************************************************************************************************/
/**
 * @file      : Dio_Types.h
 * @brief     : Dio AUTOSAR level type definition file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef DIO_TYPES_H
#define DIO_TYPES_H

/** @addtogroup Dio_Module
 *  @{
 */

/** @addtogroup Dio
 *  @brief Dio driver wrapper
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Dio_Drvw_Types.h"
#include "Dio_Cfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define DIO_TYPES_H_VENDOR_ID                   0x00B3U
#define DIO_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define DIO_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define DIO_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define DIO_TYPES_H_SW_MAJOR_VERSION            1U
#define DIO_TYPES_H_SW_MINOR_VERSION            2U
#define DIO_TYPES_H_SW_PATCH_VERSION            1U

/* Check if current file and Dio_Drvw_Types.h are the same vendor */
#if (DIO_TYPES_H_VENDOR_ID != DIO_DRVW_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Dio_Types.h and Dio_Drvw_Types.h are different"
#endif
/* Check if current file and Dio_Drvw_Types.h are the same Autosar version */
#if ((DIO_TYPES_H_AR_RELEASE_MAJOR_VERSION != DIO_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||        \
     (DIO_TYPES_H_AR_RELEASE_MINOR_VERSION != DIO_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION) ||        \
     (DIO_TYPES_H_AR_RELEASE_REVISION_VERSION != DIO_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Dio_Types.h and Dio_Drvw_Types.h are different"
#endif
/* Check if current file and Dio_Drvw_Types.h are the same Software version */
#if ((DIO_TYPES_H_SW_MAJOR_VERSION != DIO_DRVW_TYPES_H_SW_MAJOR_VERSION) ||                        \
     (DIO_TYPES_H_SW_MINOR_VERSION != DIO_DRVW_TYPES_H_SW_MINOR_VERSION) ||                        \
     (DIO_TYPES_H_SW_PATCH_VERSION != DIO_DRVW_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Dio_Types.h and Dio_Drvw_Types.h are different"
#endif

/* Check if current file and Dio_Cfg.h are the same vendor */
#if (DIO_TYPES_H_VENDOR_ID != DIO_CFG_H_VENDOR_ID)
    #error "Vendor ID of Dio_Types.h Dio_Cfg.h and are different"
#endif
/* Check if current file and Dio_Cfg.h are the same Autosar version */
#if ((DIO_TYPES_H_AR_RELEASE_MAJOR_VERSION != DIO_CFG_H_AR_RELEASE_MAJOR_VERSION) ||               \
     (DIO_TYPES_H_AR_RELEASE_MINOR_VERSION != DIO_CFG_H_AR_RELEASE_MINOR_VERSION) ||               \
     (DIO_TYPES_H_AR_RELEASE_REVISION_VERSION != DIO_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Dio_Types.h and Dio_Cfg.h are different"
#endif
/* Check if current file and Dio_Cfg header file are the same Software version */
#if ((DIO_TYPES_H_SW_MAJOR_VERSION != DIO_CFG_H_SW_MAJOR_VERSION) ||                               \
     (DIO_TYPES_H_SW_MINOR_VERSION != DIO_CFG_H_SW_MINOR_VERSION) ||                               \
     (DIO_TYPES_H_SW_PATCH_VERSION != DIO_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Dio_Types.h and Dio_Cfg.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */
/**
 * @brief          Numeric ID of a DIO port.
 */
typedef Dio_Drvw_PortType Dio_PortType;

/**
 * @brief          Numeric ID of a DIO channel.
 */
typedef Dio_Drvw_ChannelType Dio_ChannelType;

/**
 * @brief          Type for the value of a DIO port.
 */
typedef Dio_Drvw_PortLevelType Dio_PortLevelType;

/**
 * @brief           Type for the possible levels that a DIO channel can
 *                  have (input or output).
 */
typedef Dio_Drvw_LevelType Dio_LevelType;

/**
 * @brief           Type for the definition of a channel group, which consists
 *                  of several adjoining channels within a port.
 */
typedef Dio_Drvw_ChannelGroupType Dio_ChannelGroupType;

/**
 * @brief          Type of a DIO configuration data structure.
 */

typedef Dio_Drvw_ConfigType Dio_ConfigType;

#if (STD_ON == DIO_DEV_ERROR_DETECT)
    #ifdef CPU_TYPE
        #if (CPU_TYPE == CPU_TYPE_64)
/**
 * @brief size of pointer type. on CPU_TYPE_64, the size is 64bits.
 */
typedef uint64 Dio_PointerSizeType;
        #elif (CPU_TYPE == CPU_TYPE_32)
/**
 * @brief size of pointer type. on CPU_TYPE_32, the size is 32bits.
 */
typedef uint32 Dio_PointerSizeType;
        #elif (CPU_TYPE == CPU_TYPE_16)
/**
 * @brief size of pointer type. on CPU_TYPE_16, the size is 16bits.
 */
typedef uint16 Dio_PointerSizeType;
        #endif
    #endif
#endif
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

/** @} end of group Dio */

/** @} end of group Dio_Module */

#endif /*DIO_TYPES_H*/
