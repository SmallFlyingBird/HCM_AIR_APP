/**************************************************************************************************/
/**
 * @file      : Dio.h
 * @brief     : AUTOSAR Dio driver header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef DIO_H
#define DIO_H

/** @addtogroup  Dio_Module
 *  @{
 */

/** @addtogroup Dio
 *  @brief Dio high level driver
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Dio_Types.h"
/** @defgroup Public_MacroDefinition
 *  @{
 */

/**
 *  @brief Published information
 */
#define DIO_MODULE_ID                   120U
#define DIO_VENDOR_ID                   0x00B3U
#define DIO_AR_RELEASE_MAJOR_VERSION    4U
#define DIO_AR_RELEASE_MINOR_VERSION    6U
#define DIO_AR_RELEASE_REVISION_VERSION 0U
#define DIO_SW_MAJOR_VERSION            1U
#define DIO_SW_MINOR_VERSION            2U
#define DIO_SW_PATCH_VERSION            1U

/**
 *  @brief Check if current file and Dio_Types header file are of the same vendor
 */
#if (DIO_TYPES_H_VENDOR_ID != DIO_VENDOR_ID)
    #error "Vendor ID of Dio.h and Dio_Types.h are different "
#endif
/**
 *  @brief Check if header file and Dio_Types header file are of the same Autosar version
 */
#if ((DIO_TYPES_H_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION) ||                     \
     (DIO_TYPES_H_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION) ||                     \
     (DIO_TYPES_H_AR_RELEASE_REVISION_VERSION != DIO_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Dio_Types.h and Dio.h are different"
#endif

#if ((DIO_TYPES_H_SW_MAJOR_VERSION != DIO_SW_MAJOR_VERSION) ||                                     \
     (DIO_TYPES_H_SW_MINOR_VERSION != DIO_SW_MINOR_VERSION) ||                                     \
     (DIO_TYPES_H_SW_PATCH_VERSION != DIO_SW_PATCH_VERSION))
    #error "Software Version of Dio_Types.h and Dio.h are different"
#endif

/**
 *  @brief Development errors
 */
#define DIO_E_PARAM_INVALID_CHANNEL_ID ((uint8)0x0AU)
#define DIO_E_PARAM_INVALID_PORT_ID    ((uint8)0x14U)
#define DIO_E_PARAM_INVALID_GROUP_ID   ((uint8)0x1FU)
#define DIO_E_PARAM_POINTER            ((uint8)0x20U)

/**
 *  @brief Dio function ID
 */
#define DIO_SID_READ_CHANNEL        ((uint8)0x00U)
#define DIO_SID_WRITE_CHANNEL       ((uint8)0x01U)
#define DIO_SID_READ_PORT           ((uint8)0x02U)
#define DIO_SID_WRITE_PORT          ((uint8)0x03U)
#define DIO_SID_READ_CHANNEL_GROUP  ((uint8)0x04U)
#define DIO_SID_WRITE_CHANNEL_GROUP ((uint8)0x05U)
#define DIO_SID_GET_VERSION_INFO    ((uint8)0x12U)
#define DIO_SID_FLIP_CHANNEL        ((uint8)0x11U)
#define DIO_SID_MASKED_WRITE_PORT   ((uint8)0x13U)

/**
 *  @brief Instance ID of the Dio driver
 */
#define DIO_INSTANCE_ID ((uint8)0x00U)

/**
 *  @brief Export Pre-Compiler configurations
 */
#define DIO_START_SEC_CONFIG_DATA_PTR
    #include "Dio_MemMap.h"
extern const Dio_ConfigType *const Dio_PreDefinedConfigPtr;
    #define DIO_STOP_SEC_CONFIG_DATA_PTR
    #include "Dio_MemMap.h"
DIO_CONFIG_AVAILABLE_PIN
DIO_CONFIG_GROUP_LIST
DIO_CONFIG_GROUP_PARTITION

/** @} end of group Public_MacroDefinition */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/* Start of Dio section CODE */
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"

#if (STD_ON == DIO_VERSION_INFO_API)
/**
 * @brief          Get the version information of DIO module.
 *
 * @param[in,out]  VersionInfo: Pointer to where to store the version information of this module.
 *
 * Definition from AUTOSAR
 */
void Dio_GetVersionInfo(Std_VersionInfoType *VersionInfo);
#endif /* (STD_ON == DIO_VERSION_INFO_API) */

#if (STD_ON == DIO_FLIP_CHANNEL_API)
/**
 * @brief          Flip (change from 1 to 0 or from 0 to 1) the level of a
 *                 channel and return the level of the channel after flip.
 *                 If the specified channel is configured as an input channel,
 *                 user can use Dio_ReadChannel() to check physical level of 
 *                 the channel
 *
 * @param[in]      ChannelId: ID of DIO channel.
 *
 * @return         Dio_LevelType: Returns the level of the corresponding pin
 * @retval         1: The physical level of the corresponding pin is STD_HIGH.
 * @retval         0: he physical level of the corresponding Pin is STD_LOW.
 *
 * Definition from AUTOSAR
 */
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);
#endif /* (STD_ON == DIO_FLIP_CHANNEL_API) */

#if (STD_ON == DIO_MASKED_WRITE_PORT_API)
/**
 * @brief          Set the value of a given port with required mask.
 *
 * @param[in]      PortId: ID of DIO Port.
 * @param[in]      Level: Value to be written.
 * @param[in]      Mask: Channels to be masked in the port.
 *
 * @return         None.
 *
 * Definition from AUTOSAR
 */
void Dio_MaskedWritePort(Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask);
#endif /* (STD_ON == DIO_MASKED_WRITE_PORT_API) */

/**
 * @brief          Return the value of the specified DIO channel.
 *
 * @param[in]      ChannelId: ID of DIO channel.
 *
 * @return         Dio_LevelType: Returns the level of the corresponding pin
 * @retval         1: The physical level of the corresponding pin is STD_HIGH.
 * @retval         0: he physical level of the corresponding Pin is STD_LOW.
 *
 * Definition from AUTOSAR
 */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/**
 * @brief        Returns the level of all channels of the port.
 *
 * @param[in]    PortId: ID of DIO Port.
 *
 * @return       Dio_PortLevelType:Levels of all channels of specified port.
 *
 * Definition from AUTOSAR
 */

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

/**
 * @brief          Read a subset of the adjoining bits of a port.
 *
 * @param[in]      ChannelGroupIdPtr: Pointer to the channel group.
 *
 * @return         Dio_PortLevelType:Level of a subset of the adjoining bits of a port.
 *
 * Definition from AUTOSAR
 */
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType *ChannelGroupIdPtr);

/**
 * @brief          Set the level of a channel.
 *
 * @param[in]      ChannelId: ID of DIO channel.
 * @param[in]      Level: Value to be written.
 *
 * Definition from AUTOSAR
 */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

/**
 * @brief          Set a value of the port. 
 *
 * @param[in]      PortId: ID of DIO Port.
 * @param[in]      Level: Value to be written.
 *
 * @return         None.
 *
 * Definition from AUTOSAR
 */
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);

/**
 * @brief          Set a subset of the adjoining bits of a port to a specified
 *                 levels.
 *
 * @param[in]      ChannelGroupIdPtr: Pointer to the channel group.
 * @param[in]      Level:Value to be written.
 *
 * @return         None.
 *
 * Definition from AUTOSAR
 */
void Dio_WriteChannelGroup(const Dio_ChannelGroupType *ChannelGroupIdPtr, Dio_PortLevelType Level);

/**
 * @brief   Stop of Dio section CODE
 */
#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"
/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif
/** @} end of group Dio */

/** @} end of group Dio_Module */

#endif /* DIO_H */
