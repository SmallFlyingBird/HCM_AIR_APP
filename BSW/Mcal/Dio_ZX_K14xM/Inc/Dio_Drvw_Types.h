/**************************************************************************************************/
/**
 * @file      : Dio_Drvw_Types.h
 * @brief     : Dio driver wrapper type definition file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef DIO_DRVW_TYPES_H
#define DIO_DRVW_TYPES_H

/** @addtogroup Dio_Module
 *  @{
 */

/** @addtogroup Dio_Drvw
 *  @brief Dio driver wrapper
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Gpio_Drv_Types.h"
#include "Dio_Drvw_Cfg.h"
/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define DIO_DRVW_TYPES_H_VENDOR_ID                   0x00B3U
#define DIO_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define DIO_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define DIO_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define DIO_DRVW_TYPES_H_SW_MAJOR_VERSION            1U
#define DIO_DRVW_TYPES_H_SW_MINOR_VERSION            2U
#define DIO_DRVW_TYPES_H_SW_PATCH_VERSION            1U

/* Check if current file and GPIO_DRV_TYPES.h are the same vendor */
#if (DIO_DRVW_TYPES_H_VENDOR_ID != GPIO_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Dio_Drvw_Types.h and GPIO_DRV_TYPES.h are different"
#endif
/* Check if current file and GPIO_DRV_TYPES.h are the same Autosar version */
#if ((DIO_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION != GPIO_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||   \
     (DIO_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION != GPIO_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||   \
     (DIO_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION !=                                              \
      GPIO_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Dio_Drvw_Types.h and GPIO_DRV_TYPES.h are different"
#endif
/* Check if current file and GPIO_DRV_TYPES.h are the same Software version */
#if ((DIO_DRVW_TYPES_H_SW_MAJOR_VERSION != GPIO_DRV_TYPES_H_SW_MAJOR_VERSION) ||                   \
     (DIO_DRVW_TYPES_H_SW_MINOR_VERSION != GPIO_DRV_TYPES_H_SW_MINOR_VERSION) ||                   \
     (DIO_DRVW_TYPES_H_SW_PATCH_VERSION != GPIO_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Dio_Drvw_Types.h and GPIO_DRV_TYPES.h are different"
#endif

/* Check if current file and Dio_Drvw_Cfg.h are the same vendor */
#if (DIO_DRVW_TYPES_H_VENDOR_ID != DIO_DRVW_CFG_H_VENDOR_ID)
    #error "Vendor ID of Dio_Drvw_Types.h and Dio_Drvw_Cfg.h are different"
#endif
/* Check if current file and Dio_Drvw_Cfg.h are the same Autosar version */
#if ((DIO_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION != DIO_DRVW_CFG_H_AR_RELEASE_MAJOR_VERSION) ||     \
     (DIO_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION != DIO_DRVW_CFG_H_AR_RELEASE_MINOR_VERSION) ||     \
     (DIO_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION != DIO_DRVW_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Dio_Drvw_Types.h and Dio_Drvw_Cfg.h are different"
#endif

/* Check if current file and Dio_Drvw_Cfg.h are the same Software version */
#if ((DIO_DRVW_TYPES_H_SW_MAJOR_VERSION != DIO_DRVW_CFG_H_SW_MAJOR_VERSION) ||                     \
     (DIO_DRVW_TYPES_H_SW_MINOR_VERSION != DIO_DRVW_CFG_H_SW_MINOR_VERSION) ||                     \
     (DIO_DRVW_TYPES_H_SW_PATCH_VERSION != DIO_DRVW_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Dio_Drvw_Types.h and Dio_Drvw_Cfg.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */
/**
 * @brief          Numeric ID of a DIO port.
 */
/*SWS_Dio_00183,SWS_Dio_00018*/
typedef uint8 Dio_Drvw_PortType;

/**
 * @brief          Numeric ID of a DIO channel.
 */
/*SWS_Dio_00182,SWS_Dio_00015*/
typedef uint16 Dio_Drvw_ChannelType;

/**
 * @brief          Type for the value of a DIO port.
 */
/*SWS_Dio_00186*/
typedef uint32 Dio_Drvw_PortLevelType;

/**
 * @brief          Type for the possible levels that a DIO channel can
 *                  have (input or output).
 */
/*SWS_Dio_00185*/
typedef uint8 Dio_Drvw_LevelType;

/**
 * @brief          Type for the definition of a channel group, which consists
 *                 of several adjoining channels within a port.
 */
/*SWS_Dio_00184,SWS_Dio_00021*/
typedef struct
{
    Dio_Drvw_PortType      PortId;    /*!< Port id. */
    uint8                  BitOffset; /*!< Bit offset within the port. */
    Dio_Drvw_PortLevelType GroupMask; /*!< Mask for Dio channel group. */
} Dio_Drvw_ChannelGroupType;

/**
 * @brief          Type of a DIO configuration data structure.
 */

typedef struct
{
    uint8 ChannelGroupNum; /*!< Number of channel group in configuration */
    const Dio_Drvw_ChannelGroupType
        *ChannelGroupListPtr;             /*!< Pointer to list of channel groups in configuration
                                       - PortId:Port id
                                       - BitOffset:Bit offset within the port
                                       - GroupMask:Mask for Dio channel group
                                  */
    const uint32 *ChannelPartitionMapPtr; /*!< Channel partition mapping */
    const uint32 *PortPartitionMapPtr;    /*!< Port partition mapping */
} Dio_Drvw_ConfigType;
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

/** @} end of group Dio_Drvw */

/** @} end of group Dio_Module */

#endif /*DIO_DRVW_TYPES_H*/
