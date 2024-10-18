/**************************************************************************************************/
/**
 * @file      : Dio_Drvw.c
 * @brief     : Dio driver wrapper layer source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup  Dio_Module
 *  @{
 */

/** @addtogroup Dio_Drvw
 *  @brief Dio driver wrapper layer
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Dio_Drvw.h"
#include "Gpio_Drv.h"
/** @defgroup Private_MacroDefinition
 *  @{
 */

/**
 *  @brief Published information
 */
#define DIO_DRVW_C_VENDOR_ID                   0x00B3U
#define DIO_DRVW_C_AR_RELEASE_MAJOR_VERSION    4U
#define DIO_DRVW_C_AR_RELEASE_MINOR_VERSION    6U
#define DIO_DRVW_C_AR_RELEASE_REVISION_VERSION 0U
#define DIO_DRVW_C_SW_MAJOR_VERSION            1U
#define DIO_DRVW_C_SW_MINOR_VERSION            2U
#define DIO_DRVW_C_SW_PATCH_VERSION            1U

/**
 *  @brief Check if current file and Dio_Drvw header file are of the same vendor
 */
#if (DIO_DRVW_C_VENDOR_ID != DIO_DRVW_H_VENDOR_ID)
    #error "Vendor ID of Dio_Drvw.c and Dio_Drvw.h are different vendor"
#endif
/**
 *  @brief Check if current file and Dio_Drvw header file are of the same Autosar version
 */
#if ((DIO_DRVW_H_AR_RELEASE_MAJOR_VERSION != DIO_DRVW_C_AR_RELEASE_MAJOR_VERSION) ||               \
     (DIO_DRVW_H_AR_RELEASE_MINOR_VERSION != DIO_DRVW_C_AR_RELEASE_MINOR_VERSION) ||               \
     (DIO_DRVW_H_AR_RELEASE_REVISION_VERSION != DIO_DRVW_C_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of DIO_Drvw.c and DIO_Drvw.h are different"
#endif

#if ((DIO_DRVW_H_SW_MAJOR_VERSION != DIO_DRVW_C_SW_MAJOR_VERSION) ||                               \
     (DIO_DRVW_H_SW_MINOR_VERSION != DIO_DRVW_C_SW_MINOR_VERSION) ||                               \
     (DIO_DRVW_H_SW_PATCH_VERSION != DIO_DRVW_C_SW_PATCH_VERSION))
    #error "Software Version of DIO_Drvw.c and DIO_Drvw.h are different"
#endif

/**
 *  @brief Check if current file and Dio_Drv header file are of the same vendor
 */
#if (DIO_DRVW_C_VENDOR_ID != GPIO_DRV_H_VENDOR_ID)
    #error "Vendor ID of Dio_Drvw.c and Dio_Drv.h are different"
#endif
/**
 *  @brief Check if current file and Dio_Drv header file are of the same Autosar version
 */
#if ((GPIO_DRV_H_AR_RELEASE_MAJOR_VERSION != DIO_DRVW_C_AR_RELEASE_MAJOR_VERSION) ||               \
     (GPIO_DRV_H_AR_RELEASE_MINOR_VERSION != DIO_DRVW_C_AR_RELEASE_MINOR_VERSION) ||               \
     (GPIO_DRV_H_AR_RELEASE_REVISION_VERSION != DIO_DRVW_C_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of DIO_Drv.h and DIO_Drvw.c are different"
#endif

#if ((GPIO_DRV_H_SW_MAJOR_VERSION != DIO_DRVW_C_SW_MAJOR_VERSION) ||                               \
     (GPIO_DRV_H_SW_MINOR_VERSION != DIO_DRVW_C_SW_MINOR_VERSION) ||                               \
     (GPIO_DRV_H_SW_PATCH_VERSION != DIO_DRVW_C_SW_PATCH_VERSION))
    #error "Software Version of DIO_Drv.h and DIO_Drvw.c are different"
#endif

/** @} end of group Private_MacroDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define DIO_START_SEC_VAR_INIT_32
#include "Dio_MemMap.h"

#define DIO_STOP_SEC_VAR_INIT_32
#include "Dio_MemMap.h"
/** @} end of group Global_VariableDeclaration*/

#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
/** @defgroup Public_FunctionDefinition
 *  @{
 */
/**
 * @brief          Returns the value of the specified DIO channel.
 *
 * @param[in]      ChannelId:   ID of DIO channel.
 *
 * @return         Dio_Drvw_LevelType: Returns the level of the corresponding pin
 * @retval         1: The physical level of the corresponding pin is STD_HIGH.
 * @retval         0: The physical level of the corresponding Pin is STD_LOW.
 */
Dio_Drvw_LevelType Dio_Drvw_ReadChannel(Dio_Drvw_ChannelType ChannelId)
{
    Dio_Drvw_LevelType ChannelLevel = (Dio_Drvw_LevelType)STD_LOW;
    uint32             Instance; /*portId*/
    uint32             PinIndex; /*portChannelID*/

    Instance = GPIO_DRV_PORT(ChannelId);
    PinIndex = GPIO_DRV_CHANNEL(ChannelId);

    ChannelLevel = Gpio_Drv_ReadPin(Instance, PinIndex);
    return ChannelLevel;
}

/**
 * @brief          Set the level of a channel.
 *
 * @param[in]      ChannelId: ID of DIO channel.
 * @param[in]      Level: Value to be written.
 *
 * @return         None.
 */
void Dio_Drvw_WriteChannel(Dio_Drvw_ChannelType ChannelId, Dio_Drvw_LevelType Level)
{
    uint32 Instance;
    uint32 PinIndex;

    Instance = GPIO_DRV_PORT(ChannelId);
    PinIndex = GPIO_DRV_CHANNEL(ChannelId);

    Gpio_Drv_WritePin(Instance, PinIndex, Level);
}

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
Dio_Drvw_LevelType Dio_Drvw_FlipChannel(Dio_Drvw_ChannelType ChannelId)
{
    Dio_Drvw_LevelType ChannelLevel = (Dio_Drvw_LevelType)STD_LOW;
    uint32             Instance;
    uint32             PinIndex;
    uint32             PinId;
    uint32             PortOutPutLevel;
    Instance = GPIO_DRV_PORT(ChannelId);
    PinIndex = GPIO_DRV_CHANNEL(ChannelId);

    PinId = (uint32)1U << PinIndex;
    /* Flip channel level */
    Gpio_Drv_TogglePins(Instance, PinId);
    /* Return channel level */
    PortOutPutLevel = Gpio_Drv_GetPinsOutput(Instance);

    PortOutPutLevel &= PinId;
    ChannelLevel = (Dio_Drvw_LevelType)(PortOutPutLevel >> PinIndex);

    return ChannelLevel;
}
#endif /* (STD_ON == DIO_DRVW_FLIP_CHANNEL_API) */

/**
 * @brief        Returns the level of all channels of the port.
 *
 * @param[in]    PortId: ID of DIO Port.
 *
 * @return       Dio_Drvw_PortLevelType:Levels of all channels of specified port.
 *
 */
Dio_Drvw_PortLevelType Dio_Drvw_ReadPort(Dio_Drvw_PortType PortId)
{
    Dio_Drvw_PortLevelType PortLevel = (Dio_Drvw_PortLevelType)STD_LOW;

    PortLevel = (Dio_Drvw_PortLevelType)(Gpio_Drv_ReadPins(PortId));
    return PortLevel;
}

/**
 * @brief          Set a value of the port.
 *
 * @param[in]      PortId: ID of DIO Port.
 * @param[in]      Level: Value to be written.
 *
 * @return         None.
 */
void Dio_Drvw_WritePort(Dio_Drvw_PortType PortId, Dio_Drvw_PortLevelType Level)
{
    Gpio_Drv_WritePort(PortId, Level);
}

/**
 * @brief          Read a subset of the adjoining bits of a port.
 *
 * @param[in]      ChannelGroupIdPtr: Pointer to the channel group.
 *
 * @return         Dio_Drvw_PortLevelType:Level of a subset of the adjoining bits of a port.
 *
 */
Dio_Drvw_PortLevelType Dio_Drvw_ReadChannelGroup(const Dio_Drvw_ChannelGroupType *ChannelGroupIdPtr)
{
    Dio_Drvw_PortLevelType PortLevel = (Dio_Drvw_PortLevelType)STD_LOW;
    Dio_Drvw_PortLevelType PinsValue;
    Dio_Drvw_PortType      Port;
    Port = ChannelGroupIdPtr->PortId;
    PinsValue = (Dio_Drvw_PortLevelType)(Gpio_Drv_ReadPins(Port));
    PinsValue &= (ChannelGroupIdPtr->GroupMask);
    PortLevel = (Dio_Drvw_PortLevelType)(PinsValue >> (ChannelGroupIdPtr->BitOffset));

    return PortLevel;
}

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
                                Dio_Drvw_PortLevelType           Level)
{
    Dio_Drvw_PortLevelType ValueSet;
    Dio_Drvw_PortLevelType ValueClear;
    Dio_Drvw_PortType      Port;
    Port = ChannelGroupIdPtr->PortId;

    ValueSet = ((Dio_Drvw_PortLevelType)(Level) << (ChannelGroupIdPtr->BitOffset));
    ValueSet &= ((Dio_Drvw_PortLevelType)(ChannelGroupIdPtr->GroupMask));

    Gpio_Drv_SetPins(Port, ValueSet);
    ValueClear = (~ValueSet) & ChannelGroupIdPtr->GroupMask;
    Gpio_Drv_ClearPins(Port, ValueClear);
}

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
                              Dio_Drvw_PortLevelType Mask)
{
    Dio_Drvw_PortLevelType Value;

    Value = ((uint32)Mask) & ((uint32)(Level));
    Gpio_Drv_SetPins(PortId, Value);
    Value = (~Level) & Mask;
    Gpio_Drv_ClearPins(PortId, Value);
}
/** @} end of group Public_FunctionDefinition */
#endif /* (STD_ON == DIO_DRVW_MASKEDWRITEPORT_API) */

#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} end of group Dio_Drvw */

/** @} end of group Dio_Module */
