/**************************************************************************************************/
/**
 * @file      : Dio_Drvw.h
 * @brief     : Dio driver wrapper layer header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef DIO_DRVW_H
#define DIO_DRVW_H

/** @addtogroup  Dio_Module
 *  @{
 */

/** @defgroup Dio_Drvw
 *  @brief Dio driver wrapper layer
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Dio_Drvw_Types.h"
/** @defgroup Public_MacroDefinition
 *  @{
 */

/**
 *  @brief Published information
 */
#define DIO_DRVW_H_VENDOR_ID                   0x00B3U
#define DIO_DRVW_H_AR_RELEASE_MAJOR_VERSION    4U
#define DIO_DRVW_H_AR_RELEASE_MINOR_VERSION    6U
#define DIO_DRVW_H_AR_RELEASE_REVISION_VERSION 0U
#define DIO_DRVW_H_SW_MAJOR_VERSION            1U
#define DIO_DRVW_H_SW_MINOR_VERSION            2U
#define DIO_DRVW_H_SW_PATCH_VERSION            1U

/**
 *  @brief Check if current file and Dio_Drvw_Types header file are of the same vendor
 */
#if (DIO_DRVW_H_VENDOR_ID != DIO_DRVW_TYPES_H_VENDOR_ID)
    #error "VENDOR ID of Dio_Drvw.h and Dio_Drvw_Types.h are different"
#endif
/**
 *  @brief Check if current file and Dio_Drvw_Types header file are of the same Autosar version
 */
#if ((DIO_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION != DIO_DRVW_H_AR_RELEASE_MAJOR_VERSION) ||         \
     (DIO_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION != DIO_DRVW_H_AR_RELEASE_MINOR_VERSION) ||         \
     (DIO_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION != DIO_DRVW_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Dio_Drvw_Types.h and DIO_Drvw.h are different"
#endif

#if ((DIO_DRVW_TYPES_H_SW_MAJOR_VERSION != DIO_DRVW_H_SW_MAJOR_VERSION) ||                         \
     (DIO_DRVW_TYPES_H_SW_MINOR_VERSION != DIO_DRVW_H_SW_MINOR_VERSION) ||                         \
     (DIO_DRVW_TYPES_H_SW_PATCH_VERSION != DIO_DRVW_H_SW_PATCH_VERSION))
    #error "Software Version of Dio_Drvw_Types.h and DIO_Drvw.h are different"
#endif

/** @} end of group Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Public_FunctionDeclaration
 *  @brief functions declaration
 *  @{
 */
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"

#if (STD_ON == DIO_DRVW_FLIP_CHANNEL_API)
/**
 * @brief          Flip (change from 1 to 0 or from 0 to 1) the level of a
 *                 channel and return the level of the channel after flip.
 *
 * @param[in]      ChannelId: ID of DIO channel.
 *
 * @return         Dio_Drvw_LevelType: Returns the level of the corresponding pin
 * @retval         1: The physical level of the corresponding pin is STD_HIGH.
 * @retval         0: The physical level of the corresponding Pin is STD_LOW.
 *
 */
Dio_Drvw_LevelType Dio_Drvw_FlipChannel(Dio_Drvw_ChannelType ChannelId);
#endif

#if (STD_ON == DIO_DRVW_MASKEDWRITEPORT_API)
/**
 * @brief          Set the value of a given port with required mask.
 *
 * @param[in]      PortId: ID of DIO Port.
 * @param[in]      Level: Value to be written.
 * @param[in]      Mask: Channels to be masked in the port.
 *
 * @return         None.
 */

void Dio_Drvw_MaskedWritePort(Dio_Drvw_PortType PortId, Dio_Drvw_PortLevelType Level,
                              Dio_Drvw_PortLevelType Mask);
#endif /* (STD_ON == DIO_DRVW_MASKEDWRITEPORT_API)  */

/**
 * @brief          Returns the value of the specified DIO channel.
 *
 * @param[in]      ChannelId:ID of DIO channel.
 *
 * @return         Dio_Drvw_LevelType:Returns the level of the corresponding pin.
 * @retval         1: The physical level of the corresponding pin is STD_HIGH.
 * @retval         0: The physical level of the corresponding Pin is STD_LOW.
 */
Dio_Drvw_LevelType Dio_Drvw_ReadChannel(Dio_Drvw_ChannelType ChannelId);

/**
 * @brief        Returns the level of all channels of the port.
 *
 * @param[in]    PortId: ID of DIO Port.
 *
 * @return       Dio_Drvw_PortLevelType:Levels of all channels of specified port.
 *
 */
Dio_Drvw_PortLevelType Dio_Drvw_ReadPort(Dio_Drvw_PortType PortId);

/**
 * @brief          Read a subset of the adjoining bits of a port.
 *
 * @param[in]      ChannelGroupIdPtr: Pointer to the channel group.
 *
 * @return         Dio_Drvw_PortLevelType:Level of a subset of the adjoining bits of a port.
 *
 */
Dio_Drvw_PortLevelType
Dio_Drvw_ReadChannelGroup(const Dio_Drvw_ChannelGroupType *ChannelGroupIdPtr);

/**
 * @brief          Set the level of a channel.
 *
 * @param[in]      ChannelId: ID of DIO channel.
 * @param[in]      Level: Value to be written.
 *
 * @return         None.
 */
void Dio_Drvw_WriteChannel(Dio_Drvw_ChannelType ChannelId, Dio_Drvw_LevelType Level);
/**
 * @brief          Set a value of the port.
 *
 * @param[in]      PortId: ID of DIO Port.
 * @param[in]      Level: Value to be written.
 *
 * @return         None.
 */
void Dio_Drvw_WritePort(Dio_Drvw_PortType PortId, Dio_Drvw_PortLevelType Level);

/**
 * @brief          Set a subset of the adjoining bits of a port to a specified
 *                 levels.
 *
 * @param[in]      ChannelGroupIdPtr: Pointer to the channel group.
 * @param[in]      Level:Value to be written.
 *
 * @return         None.
 */
void Dio_Drvw_WriteChannelGroup(const Dio_Drvw_ChannelGroupType *ChannelGroupIdPtr,
                                Dio_Drvw_PortLevelType           Level);


#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} end of group DIO_DRVW */

/** @} end of group Dio_Module */

#endif /* DIO_DRVW_H */
