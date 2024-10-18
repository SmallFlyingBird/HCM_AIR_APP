/**************************************************************************************************/
/**
 * @file      : Dio.c
 * @brief     : AUTOSAR Dio driver source file
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

/** @addtogroup Dio
 *  @brief Dio high level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Dio.h"
#include "Dio_Drvw.h"
/*SWS_Dio_00194*/
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    #include "Det.h"
#endif

/** @defgroup Private_MacroDefinition
 *  @{
 */
/**
 *  @brief Published information
 */
#define DIO_C_VENDOR_ID                   0x00B3U
#define DIO_C_AR_RELEASE_MAJOR_VERSION    4U
#define DIO_C_AR_RELEASE_MINOR_VERSION    6U
#define DIO_C_AR_RELEASE_REVISION_VERSION 0U
#define DIO_C_SW_MAJOR_VERSION            1U
#define DIO_C_SW_MINOR_VERSION            2U
#define DIO_C_SW_PATCH_VERSION            1U

/**
 *  @brief Macro to get core ID.
 */
#define Dio_GetCoreID() McalLib_GetCoreID()

/**
 *  @brief Check if current file and Dio header file are of the same vendor
 */
#if (DIO_C_VENDOR_ID != DIO_VENDOR_ID)
    #error "Vendor ID of Dio.c and Dio.h are different"
#endif
/**
 *  @brief Check if current file and Dio header file are of the same Autosar version
 */
#if ((DIO_AR_RELEASE_MAJOR_VERSION != DIO_C_AR_RELEASE_MAJOR_VERSION) ||                           \
     (DIO_AR_RELEASE_MINOR_VERSION != DIO_C_AR_RELEASE_MINOR_VERSION) ||                           \
     (DIO_AR_RELEASE_REVISION_VERSION != DIO_C_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Dio.c and Dio.h are different"
#endif

#if ((DIO_SW_MAJOR_VERSION != DIO_C_SW_MAJOR_VERSION) ||                                           \
     (DIO_SW_MINOR_VERSION != DIO_C_SW_MINOR_VERSION) ||                                           \
     (DIO_SW_PATCH_VERSION != DIO_C_SW_PATCH_VERSION))
    #error "Software Version of Dio.c and Dio.h are different"
#endif

/**
 *  @brief Check if current file and Dio_Drvw header file are of the same vendor
 */
#if (DIO_C_VENDOR_ID != DIO_DRVW_H_VENDOR_ID)
    #error "Vendor ID of Dio.c and Dio_Drvw.h are different"
#endif
/**
 *  @brief Check if current file and Dio_Drvw header file are of the same Autosar version
 */
#if ((DIO_DRVW_H_AR_RELEASE_MAJOR_VERSION != DIO_C_AR_RELEASE_MAJOR_VERSION) ||                    \
     (DIO_DRVW_H_AR_RELEASE_MINOR_VERSION != DIO_C_AR_RELEASE_MINOR_VERSION) ||                    \
     (DIO_DRVW_H_AR_RELEASE_REVISION_VERSION != DIO_C_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Dio.c and Dio_Drvw.h are different"
#endif

#if ((DIO_DRVW_H_SW_MAJOR_VERSION != DIO_C_SW_MAJOR_VERSION) ||                                    \
     (DIO_DRVW_H_SW_MINOR_VERSION != DIO_C_SW_MINOR_VERSION) ||                                    \
     (DIO_DRVW_H_SW_PATCH_VERSION != DIO_C_SW_PATCH_VERSION))
    #error "Software Version of Dio.c and Dio_Drvw.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if (STD_ON == DIO_DEV_ERROR_DETECT)
        /* Check if current file and Det header file are of the same Autosar version */
        #if ((DIO_C_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) ||                   \
             (DIO_C_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
            #error "AUTOSAR Version of Dio.c and Det.h are different"
        #endif
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

#if (STD_ON == DIO_DEV_ERROR_DETECT)
    #define DIO_BIT1_LEFT_SHIFT ((uint32)1U)
    #define DIO_CHECK_CHANNEL_AVAILABLE(ChannelId)                                                 \
        (DIO_BIT1_LEFT_SHIFT << ((ChannelId)&GPIO_DRV_CHANNEL_MASK))
#endif

#define DIO_PORT_ID_SHIFT            (5U)
#define DIO_PORT_ID_COUNT(ChannelId) ((ChannelId) >> DIO_PORT_ID_SHIFT)
/** @} end of group Private_MacroDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

/** @} end of group Private_VariableDefinition*/

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
/**
 *  @brief Dio error detection ON/OFF
 */
#if (STD_ON == DIO_DEV_ERROR_DETECT)

#define DET_REPORT_ERROR( ApiId,  ErrorId) \
(void)Det_ReportError((uint16)DIO_MODULE_ID, DIO_INSTANCE_ID, (uint8) (ApiId), (uint8)( ErrorId));

LOCAL_INLINE Std_ReturnType Dio_CheckWriteChannel(Dio_ChannelType ChannelId, uint8 ServiceId);

LOCAL_INLINE Std_ReturnType Dio_CheckReadChannel(Dio_ChannelType ChannelId, uint8 ServiceId);

LOCAL_INLINE Std_ReturnType Dio_CheckWritePort(Dio_PortType PortId, uint8 ServiceId);
LOCAL_INLINE Std_ReturnType Dio_CheckReadPort(Dio_PortType PortId, uint8 ServiceId);

LOCAL_INLINE Std_ReturnType Dio_CheckWriteChannelGroup(const Dio_ChannelGroupType *ChannelGroupPtr,
                                                       uint8                       ServiceId);
LOCAL_INLINE Std_ReturnType Dio_CheckReadChannelGroup(const Dio_ChannelGroupType *ChannelGroupPtr,
                                                      uint8                       ServiceId);

#endif /* (STD_ON == DIO_DEV_ERROR_DETECT) */

/**
 *  @brief Dio channel group partition 
 */
#ifdef DIO_CHANNEL_GROUPS_AVAILABLE
LOCAL_INLINE boolean Dio_ChannelGroupForEachPartition(const Dio_ChannelGroupType *ChannelGroupIdPtr);
#endif /* (STD_ON == DIO_CHANNEL_GROUPS_AVAILABLE) */


/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

#if (STD_ON == DIO_DEV_ERROR_DETECT)
/**
 * @brief       Check DIO channel in Dio_ReadChannel function.
 *
 * @param[in]   ChannelId: The channel to be checked.
 * @param[in]   ServiceId: The service id of the caller function
 *
 * @return      Std_ReturnType: Status of validation
 * @retval      E_OK:      specified channel is implemented.
 * @retval      E_NOT_OK:  specified channel is not implemented.
 *
 */
LOCAL_INLINE Std_ReturnType Dio_CheckReadChannel(Dio_ChannelType ChannelId, uint8 ServiceId)
{
    Std_ReturnType Valid = (Std_ReturnType)E_NOT_OK;
    uint8          CoreId = (uint8)Dio_GetCoreID();

    /* Check if that channel ID is available for read */
    if (((((Dio_ChannelType)(ChannelId) <= DIO_CHANNEL_NUM)) &&
         ((Dio_PortLevelType)0U != (Dio_AvailablePinsForRead[DIO_PORT_ID_COUNT(ChannelId)] &
                                    (DIO_CHECK_CHANNEL_AVAILABLE((uint16)ChannelId))))) &&
    /* MISRA2012 Rule-2.2 violation: The CoreId value depends on the hardware, 
       and the 14xM series chip CoreId is equal to 0 */
        ((uint32)1U ==
         ((Dio_PreDefinedConfigPtr->ChannelPartitionMapPtr[ChannelId] & ((uint32)1U << CoreId)) >>
          CoreId)))
    {
        Valid = (Std_ReturnType)E_OK;
    }
    else
    {
        /* Raise Det error when invalid channel ID */
        DET_REPORT_ERROR(ServiceId, DIO_E_PARAM_INVALID_CHANNEL_ID);
    }

    return Valid;
}
#endif

#if (STD_ON == DIO_DEV_ERROR_DETECT)
/**
 * @brief       Check DIO channel in Dio_WriteChannel function.
 *
 * @param[in]   ChannelId: The channel to be checked.
 * @param[in]   ServiceId: The service id of the caller function
 *
 * @return      Std_ReturnType: Status of validation
 * @retval      E_OK:      specified channel is implemented.
 * @retval      E_NOT_OK:  specified channel is not implemented.
 *
 */
LOCAL_INLINE Std_ReturnType Dio_CheckWriteChannel(Dio_ChannelType ChannelId, uint8 ServiceId)
{
    Std_ReturnType Valid = (Std_ReturnType)E_NOT_OK;
    uint8          CoreId = (uint8)Dio_GetCoreID();

    /* Check if that channel ID is available for write */
    if (((((Dio_ChannelType)(ChannelId) <= DIO_CHANNEL_NUM)) &&
         ((Dio_PortLevelType)0U != (Dio_AvailablePinsForWrite[DIO_PORT_ID_COUNT(ChannelId)] &
                                    (DIO_CHECK_CHANNEL_AVAILABLE((uint16)ChannelId))))) &&
    /* MISRA2012 Rule-2.2 violation: The CoreId value depends on the hardware, 
       and the 14xM series chip CoreId is equal to 0 */
        (((uint32)1U ==
          ((Dio_PreDefinedConfigPtr->ChannelPartitionMapPtr[ChannelId] & ((uint32)1U << CoreId)) >>
           CoreId))))
    {
        Valid = (Std_ReturnType)E_OK;
    }
    else
    {
        /* Raise Det error when invalid channel ID */
        DET_REPORT_ERROR(ServiceId,DIO_E_PARAM_INVALID_CHANNEL_ID);
    }
    return Valid;
}

#endif

#if (STD_ON == DIO_DEV_ERROR_DETECT)
/**
 * @brief       Check DIO port in Dio_ReadPort function.
 *
 * @param[in]   PortId:    The port to be checked.
 * @param[in]   ServiceId: The service id of the caller function
 *
 * @return      Std_ReturnType: Status of validation
 * @retval      E_OK:      specified port is implemented.
 * @retval      E_NOT_OK:  specified port is not implemented.
 *
 */
LOCAL_INLINE Std_ReturnType Dio_CheckReadPort(Dio_PortType PortId, uint8 ServiceId)
{
    Std_ReturnType Valid = (Std_ReturnType)E_NOT_OK;
    uint8          CoreId = (uint8)Dio_GetCoreID();

    /* Check input parameters are available for read */
    if ((((uint8)(PortId) < DIO_PORT_NUM) &&
         (Dio_AvailablePinsForRead[(uint8)(PortId)] != DIO_NO_AVAILABLE_CHANNEL_NUM)) &&
    /* MISRA2012 Rule-2.2 violation: The CoreId value depends on the hardware, 
       and the 14xM series chip CoreId is equal to 0 */
        ((uint32)1U ==
         ((Dio_PreDefinedConfigPtr->PortPartitionMapPtr[PortId] & ((uint32)1U << CoreId)) >>
          CoreId)))
    {
        Valid = (Std_ReturnType)E_OK;
    }
    else
    {
        /* Raise Det error when invalid port ID */
        DET_REPORT_ERROR(ServiceId, DIO_E_PARAM_INVALID_PORT_ID);
    }

    return Valid;
}
#endif

#if (STD_ON == DIO_DEV_ERROR_DETECT)
/**
 * @brief       Check DIO port in Dio_WritePort function.
 *
 * @param[in]   PortId:  The port to be checked.
 * @param[in]   ServiceId: The service id of the caller function
 *
 * @return      Std_ReturnType: Status of validation
 * @retval      E_OK:      specified port is implemented.
 * @retval      E_NOT_OK:  specified port is not implemented.
 *
 */
LOCAL_INLINE Std_ReturnType Dio_CheckWritePort(Dio_PortType PortId, uint8 ServiceId)
{
    Std_ReturnType Valid = (Std_ReturnType)E_NOT_OK;
    uint8          CoreId = (uint8)Dio_GetCoreID();

    /* Check input parameters are available for write */
    if ((((uint8)(PortId) < DIO_PORT_NUM) &&
         (Dio_AvailablePinsForWrite[(uint8)(PortId)] != DIO_NO_AVAILABLE_CHANNEL_NUM)) &&
        ((uint32)1U ==
    /* MISRA2012 Rule-2.2 violation: The CoreId value depends on the hardware, 
       and the 14xM series chip CoreId is equal to 0 */
         ((Dio_PreDefinedConfigPtr->PortPartitionMapPtr[PortId] & ((uint32)1U << CoreId)) >>
          CoreId)))
    {
        Valid = (Std_ReturnType)E_OK;
    }
    else
    {
        /* Raise Det error when invalid port ID */
        DET_REPORT_ERROR(ServiceId, DIO_E_PARAM_INVALID_PORT_ID);
    }

    return Valid;
}
#endif

#if (STD_ON == DIO_DEV_ERROR_DETECT)
/**
 * @brief       Check DIO channel group in Dio_WriteChannelGroup function.
 *
 * @param[in]   ChannelGroupPtr:  The channel group to be validated.
 * @param[in]   ServiceId:    The service id of the caller function
 *
 * @return      Std_ReturnType: Status of validation
 * @retval      E_OK:      The parameter matches one of the channel group pointers in
 *              the configuration.
 * @retval      E_NOT_OK:  The parameter doesn't match one of the channel group pointers in
 *              the configuration.
 *
 */
LOCAL_INLINE Std_ReturnType Dio_CheckWriteChannelGroup(const Dio_ChannelGroupType *ChannelGroupPtr,
                                                       uint8                       ServiceId)
{
    Std_ReturnType Valid = (Std_ReturnType)E_NOT_OK;

    if (NULL_PTR == ChannelGroupPtr)
    {
        /* Raise Det error when a void pointer to zero */
        DET_REPORT_ERROR(ServiceId, DIO_E_PARAM_POINTER);
    }
    else
    {
        /* Check input pointer are available for write */
        /* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer object, 
         no side effects forseen by violating this rule.
         The following four lines of code also violate this rule with the same reason. */
        if ((((Dio_PointerSizeType)(ChannelGroupPtr)) >=
             ((Dio_PointerSizeType)Dio_PreDefinedConfigPtr->ChannelGroupListPtr)) &&
            (((Dio_PointerSizeType)(ChannelGroupPtr)) <=
             (Dio_PointerSizeType)(&Dio_PreDefinedConfigPtr
                                    ->ChannelGroupListPtr[Dio_PreDefinedConfigPtr->ChannelGroupNum -
                                                          1U])) &&
            ((uint8)(ChannelGroupPtr->PortId) < DIO_PORT_NUM) &&
            ((uint8)(ChannelGroupPtr->BitOffset) <= DIO_VALID_OFFSET_MAX) &&
            (Dio_AvailablePinsForWrite[(uint8)(ChannelGroupPtr->PortId)] != DIO_NO_AVAILABLE_CHANNEL_NUM))
        {
            Valid = (Std_ReturnType)E_OK;
        }
        else
        {
            /* Raise Det error when invalid channel group */
            DET_REPORT_ERROR(ServiceId,DIO_E_PARAM_INVALID_GROUP_ID);
        }
    }
    return Valid;
}

/**
 * @brief       Check DIO channel group in Dio_ReadChannelGroup function.
 *
 * @param[in]   ChannelGroupPtr:  The channel group to be validated.
 * @param[in]   ServiceId:    The service id of the caller function
 *
 * @return      Std_ReturnType: Status of validation
 * @retval      E_OK:The parameter matches one of the channel group pointers in
 *              the configuration.
 * @retval      E_NOT_OK:The parameter doesn't match one of the channel group pointers in
 *              the configuration.
 *
 */
LOCAL_INLINE Std_ReturnType Dio_CheckReadChannelGroup(const Dio_ChannelGroupType *ChannelGroupPtr,
                                                      uint8                       ServiceId)
{
    Std_ReturnType Valid = (Std_ReturnType)E_NOT_OK;

    if (NULL_PTR == ChannelGroupPtr)
    {
        /* Raise Det error when a void pointer to zero */
        DET_REPORT_ERROR(ServiceId, DIO_E_PARAM_POINTER);
    }
    else
    {
        /* Check input pointer are available for read */
        /* MISRA2012 Rule-11.4 violation: Convert a value of register address to a pointer object, 
         no side effects forseen by violating this rule.
         The following four lines of code also violate this rule with the same reason. */
        if ((((Dio_PointerSizeType)(ChannelGroupPtr)) >=
             ((Dio_PointerSizeType)Dio_PreDefinedConfigPtr->ChannelGroupListPtr)) &&
            (((Dio_PointerSizeType)(ChannelGroupPtr)) <=
             (Dio_PointerSizeType)(&Dio_PreDefinedConfigPtr
                                    ->ChannelGroupListPtr[Dio_PreDefinedConfigPtr->ChannelGroupNum -
                                                          1U])) &&
            ((uint8)(ChannelGroupPtr->PortId) < DIO_PORT_NUM) &&
            ((uint8)(ChannelGroupPtr->BitOffset) <= DIO_VALID_OFFSET_MAX) &&
            (Dio_AvailablePinsForRead[(uint8)(ChannelGroupPtr->PortId)] != DIO_NO_AVAILABLE_CHANNEL_NUM))
        {
            Valid = (Std_ReturnType)E_OK;
        }
        else
        {
            /* Raise Det error when invalid channel group */
            DET_REPORT_ERROR(ServiceId,DIO_E_PARAM_INVALID_GROUP_ID);
        }
    }
    return Valid;
}
#endif


#ifdef DIO_CHANNEL_GROUPS_AVAILABLE
/**
 * @brief       DIO channel group partition.
 *
 * @param[in]   ChannelGroupIdPtr:  The channel group to be validated.
 *
 * @return      boolean. 
 *
 * @retval      TRUE:Channel Group is alocated partition.
 * @retval      FALSE:Channel Group is not alocated partition .
 *
 */
LOCAL_INLINE boolean Dio_ChannelGroupForEachPartition(const Dio_ChannelGroupType *ChannelGroupIdPtr)
{
    boolean GroupAlocated = FALSE;
    uint8 GroupIndex = 0U;
    uint8 GroupNum = 0U;
    uint8 CoreId = 0U;
  
    GroupNum = Dio_PreDefinedConfigPtr->ChannelGroupNum;
    CoreId = (uint8)Dio_GetCoreID();
    for (GroupIndex = 0U; GroupIndex < GroupNum; GroupIndex++)
    {
        if (Dio_ChannelGroupsListForEachPartitionPtr[CoreId][GroupIndex] == ChannelGroupIdPtr)
        {
            GroupAlocated = TRUE;
            break;
        }
    }
    return GroupAlocated;
}
#endif
/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#if (STD_ON == DIO_VERSION_INFO_API)
/**
 * @brief          Get the version information of DIO module.
 *
 *
 * @param[in,out]  VersionInfo: Pointer to where to store the version information of this module.
 *
 */
void Dio_GetVersionInfo(Std_VersionInfoType *VersionInfo)
{
    #if (STD_ON == DIO_DEV_ERROR_DETECT)
    if (NULL_PTR == VersionInfo)
    {
        /* Raise Det error when a void pointer to zero */
        (void)Det_ReportError((uint16)DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_SID_GET_VERSION_INFO,
                              DIO_E_PARAM_POINTER);
    }
    else
    #endif /* (STD_ON == DIO_DEV_ERROR_DETECT) */
    {
        VersionInfo->vendorID = (uint16)DIO_VENDOR_ID;
        VersionInfo->moduleID = (uint16)DIO_MODULE_ID;
        VersionInfo->sw_major_version = (uint8)DIO_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = (uint8)DIO_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = (uint8)DIO_SW_PATCH_VERSION;
    }
}
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
 * @retval         0: The physical level of the corresponding Pin is STD_LOW.
 *
 */
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
    Dio_LevelType ChannelLevel = (Dio_LevelType)STD_LOW;

    #if (STD_ON == DIO_DEV_ERROR_DETECT)
    /* Check ChannelId are available for write */
    if ((Std_ReturnType)E_OK == Dio_CheckWriteChannel(ChannelId, DIO_SID_FLIP_CHANNEL))
    {
    #endif
        ChannelLevel = Dio_Drvw_FlipChannel(ChannelId);
    #if (STD_ON == DIO_DEV_ERROR_DETECT)
    }
    #endif

    return ChannelLevel;
}

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
 */
void Dio_MaskedWritePort(Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask)
{
    #if (STD_ON == DIO_DEV_ERROR_DETECT)

    /* Check PortId are available for write */
    if ((Std_ReturnType)E_OK == Dio_CheckWritePort(PortId, DIO_SID_MASKED_WRITE_PORT))
    {
    #endif
        Dio_Drvw_MaskedWritePort(PortId, Level, Mask);
    #if (STD_ON == DIO_DEV_ERROR_DETECT)
    }
    #endif
}
#endif /* (STD_ON == DIO_MASKED_WRITE_PORT_API) */

/**
 * @brief          Return the value of the specified DIO channel.
 *
 * @param[in]      ChannelId: ID of DIO channel.
 *
 * @return         Dio_LevelType: Returns the level of the corresponding pin
 * @retval         1: The physical level of the corresponding pin is STD_HIGH.
 * @retval         0: The physical level of the corresponding Pin is STD_LOW.
 *
 */
/*SWS_Dio_00023*/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    Dio_LevelType ChannelLevel = (Dio_LevelType)STD_LOW;
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    /* Check ChannelId are available for read */
    if ((Std_ReturnType)E_OK == Dio_CheckReadChannel(ChannelId, DIO_SID_READ_CHANNEL))
    {
#endif
        ChannelLevel = Dio_Drvw_ReadChannel(ChannelId);
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    }
#endif
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
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    /* Check ChannelId are available for write */
    if ((Std_ReturnType)E_OK == Dio_CheckWriteChannel(ChannelId, DIO_SID_WRITE_CHANNEL))
    {
#endif
        Dio_Drvw_WriteChannel(ChannelId, Level);
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    }
#endif
}

/**
 * @brief        Returns the level of all channels of the port.
 *
 * @param[in]    PortId: ID of DIO Port.
 *
 * @return       Dio_PortLevelType:Levels of all channels of specified port.
 *
 */

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
    Dio_PortLevelType PortLevel = (Dio_PortLevelType)STD_LOW;

#if (STD_ON == DIO_DEV_ERROR_DETECT)
    /* Check PortId are available for read */
    if ((Std_ReturnType)E_OK == Dio_CheckReadPort(PortId, DIO_SID_READ_PORT))
    {
#endif
        /* Returns the level of the port */
        PortLevel = Dio_Drvw_ReadPort(PortId);
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    }
#endif
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
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    /* Check PortId are available for write */
    if ((Std_ReturnType)E_OK == Dio_CheckWritePort(PortId, DIO_SID_WRITE_PORT))
    {
#endif
        Dio_Drvw_WritePort(PortId, Level);
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    }
#endif
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
void Dio_WriteChannelGroup(const Dio_ChannelGroupType *ChannelGroupIdPtr, Dio_PortLevelType Level)
{
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    /*Check DIO channel group for write*/
    if ((Std_ReturnType)E_OK == Dio_CheckWriteChannelGroup(ChannelGroupIdPtr, DIO_SID_WRITE_CHANNEL_GROUP))
    {
    #ifdef DIO_CHANNEL_GROUPS_AVAILABLE
        if (TRUE == Dio_ChannelGroupForEachPartition(ChannelGroupIdPtr))
        {
    #endif /* DIO_CHANNEL_GROUPS_AVAILABLE */
#endif     /* DIO_DEV_ERROR_DETECT */
            Dio_Drvw_WriteChannelGroup(ChannelGroupIdPtr, Level);
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    #ifdef DIO_CHANNEL_GROUPS_AVAILABLE
        }
        else
        {
            DET_REPORT_ERROR( DIO_SID_WRITE_CHANNEL_GROUP,
                                  DIO_E_PARAM_INVALID_GROUP_ID);
        }
    #endif /* DIO_CHANNEL_GROUPS_AVAILABLE */
    }
#endif /* DIO_DEV_ERROR_DETECT */
}

/**
 * @brief          Read a subset of the adjoining bits of a port.
 *
 * @param[in]      ChannelGroupIdPtr: Pointer to the channel group.
 *
 * @return         Dio_PortLevelType:Level of a subset of the adjoining bits of a port.
 *
 * @return         None.
 * 
 */
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType *ChannelGroupIdPtr)
{
    Dio_PortLevelType PortLevel = (Dio_PortLevelType)STD_LOW;

#if (STD_ON == DIO_DEV_ERROR_DETECT)
    /*Check DIO channel group for read*/
    if ((Std_ReturnType)E_OK == Dio_CheckReadChannelGroup(ChannelGroupIdPtr, DIO_SID_READ_CHANNEL_GROUP))
    {
    #ifdef DIO_CHANNEL_GROUPS_AVAILABLE
        if ( TRUE == Dio_ChannelGroupForEachPartition(ChannelGroupIdPtr))
        {
    #endif /* DIO_CHANNEL_GROUPS_AVAILABLE */

#endif /* DIO_DEV_ERROR_DETECT */
            PortLevel = Dio_Drvw_ReadChannelGroup(ChannelGroupIdPtr);

#if (STD_ON == DIO_DEV_ERROR_DETECT)
    #ifdef DIO_CHANNEL_GROUPS_AVAILABLE
        }
        else
        {
            /* Report error of read channel group */
            DET_REPORT_ERROR( DIO_SID_READ_CHANNEL_GROUP, DIO_E_PARAM_INVALID_GROUP_ID);
        }
    #endif /* DIO_CHANNEL_GROUPS_AVAILABLE */
    }
#endif /* DIO_DEV_ERROR_DETECT */

    return PortLevel;
}

/** @} end of group Public_FunctionDefinition */

#define DIO_STOP_SEC_CODE

#include "Dio_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} end of group Dio */
/** @} end of group Dio_Module */
