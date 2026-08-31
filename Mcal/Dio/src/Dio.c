/**
 *   @file    Dio.c
 *   @version
 *
 *   @brief   AUTOSAR Dio module interface
 *   @details API implementation for DIO driver
 *
 *   @addtogroup DIO_MODULE
 *   @{
 */
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Dio
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

#ifdef __cplusplus
extern "C"
{
#endif

/*
 * @page misra_violations MISRA-C:2012 violations list
 * PRQA S 4461 Rule 10.3: The value of an expression shall not be assigned to an object with a narrower
 *                        essential type or of a different essential type category.
 */

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Dio.h"
#include "Dio_Lld.h"
#include "SchM_Dio.h"

#include "OsIf.h"

#if (DIO_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* DIO_DEV_ERROR_DETECT == STD_ON */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DIO_VENDOR_ID_C                      (0xB4)
#define DIO_AR_RELEASE_MAJOR_VERSION_C       (4)
#define DIO_AR_RELEASE_MINOR_VERSION_C       (4)
#define DIO_AR_RELEASE_REVISION_VERSION_C    (0)
#define DIO_SW_MAJOR_VERSION_C               (2)
#define DIO_SW_MINOR_VERSION_C               (3)
#define DIO_SW_PATCH_VERSION_C               (0)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and DIO header file are of the same vendor */
#if (DIO_VENDOR_ID_C != DIO_VENDOR_ID)
#error "Dio.c and Dio.h have different vendor ids"
#endif

/* Check if source file and DIO header file are of the same Autosar version */
#if ((DIO_AR_RELEASE_MAJOR_VERSION_C != DIO_AR_RELEASE_MAJOR_VERSION) || \
     (DIO_AR_RELEASE_MINOR_VERSION_C != DIO_AR_RELEASE_MINOR_VERSION) || \
     (DIO_AR_RELEASE_REVISION_VERSION_C != DIO_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Dio.c and Dio.h are different"
#endif

/* Check if source file and DIO header file are of the same Software version */
#if ((DIO_SW_MAJOR_VERSION_C != DIO_SW_MAJOR_VERSION) || \
     (DIO_SW_MINOR_VERSION_C != DIO_SW_MINOR_VERSION) || \
     (DIO_SW_PATCH_VERSION_C != DIO_SW_PATCH_VERSION))
#error "Software Version Numbers of Dio.c and Dio.h are different"
#endif

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

#if (GPIO_DEV_ERROR_DETECT == STD_ON)
#define DIO_LLD_VALID_PORT_PIN(port, pin) ((Dio_gPortPinsMask[port] & ((uint32)1 << (pin))) == DIO_PIN_NOT_MASKED)

#define DIO_LLD_VALID_CHANNEL(pin) ((pin) >= DIO_PORT_PIN_TOTAL_NUMBER)

#define DIO_LLD_VALID_PORT(port) ((port) >= DIO_PORT_TOTAL_NUMBER)
#endif /* (GPIO_DEV_ERROR_DETECT == STD_ON) */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

#if (GPIO_DEV_ERROR_DETECT == STD_ON)
#define DIO_START_SEC_CONST_32
#include "Dio_MemMap.h"
DIO_CONST static const uint32 Dio_gPortPinsMask[DIO_PORT_TOTAL_NUMBER] =
{
    DIO_PORTA_PINS_MASK,   /*!< available pins mask for port A */
    DIO_PORTB_PINS_MASK,   /*!< available pins mask for port B */
    DIO_PORTC_PINS_MASK,   /*!< available pins mask for port C */
    DIO_PORTD_PINS_MASK,   /*!< available pins mask for port D */
    DIO_PORTE_PINS_MASK,   /*!< available pins mask for port E */
};

#define DIO_STOP_SEC_CONST_32
#include "Dio_MemMap.h"

#endif /* (GPIO_DEV_ERROR_DETECT == STD_ON) */

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#if (DIO_CHANNEL_GROUP_NUMBER != 0)
#if (GPIO_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief            Check the channel group config parameters and address
 * @details
 * @param[in]        ChannelGroupIdPtr Pointer to Dio channel group config
 * @return           Std_ReturnType
 */
LOCAL_INLINE Std_ReturnType Dio_llCheckChannelGroup(const Dio_ChannelGroupType *ChannelGroupIdPtr);

/**
 * @brief            Check the channel group config address
 * @details
 * @param[in]        ChannelGroupIdPtr Pointer to Dio channel group config
 * @return           Std_ReturnType
 */
LOCAL_INLINE Std_ReturnType Dio_llCheckChannelGroupPtr(const Dio_ChannelGroupType *ChannelGroupIdPtr);
#endif /* (GPIO_DEV_ERROR_DETECT == STD_ON) */
#endif

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"

#if (DIO_FLIP_CHANNEL_API == STD_ON)
DIO_FUNC Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
    Dio_LevelType ChannelLevel = STD_LOW;
    /*
    *  MR12 RULE 10.3 VIOLATION: The PortHwId is ensured to be a uint8 via limiting the ChannelId in the MCAL config tool(YCT)
    */
    Dio_PortType PortHwId = DIO_CHANNEL_PORT_NUM(ChannelId); /* PRQA S 4461 */
    /*
    *  MR12 RULE 10.3 VIOLATION: The PinHwId is ensured to be a uint8 via limiting the ChannelId in the MCAL config tool(YCT)
    */
    Dio_PinType PinHwId = (Dio_PinType)DIO_CHANNEL_PIN_NUM(ChannelId); /* PRQA S 4461 */

#if (GPIO_DEV_ERROR_DETECT == STD_ON)
    /* Check the function parameter
       Traceability : SWS_Dio_00074 */
    /* Check the channel id */

    /* check the port availability, ensure it's within PORTA~E(0~4)/less than 5 */
    if (DIO_LLD_VALID_PORT(PortHwId))
    {
        (void)Det_ReportError((uint16)DIO_MODULE_ID, DIO_INSTANCE_ID,
                              DIO_SID_FLIP_CHANNEL, DIO_E_PARAM_INVALID_PORT_ID);
    }
    /* check the pin rang, ensure it's within pin0~31/less than 32 */
    else if (DIO_LLD_VALID_CHANNEL(PinHwId))
    {
        (void)Det_ReportError((uint16)DIO_MODULE_ID, DIO_INSTANCE_ID,
                              DIO_SID_FLIP_CHANNEL, DIO_E_PARAM_INVALID_CHANNEL_ID);
    }
    else if (DIO_LLD_VALID_PORT_PIN(PortHwId, PinHwId)) /* check the pin availability */
    {
        (void)Det_ReportError((uint16)DIO_MODULE_ID, DIO_INSTANCE_ID,
                              DIO_SID_FLIP_CHANNEL, DIO_E_PARAM_INVALID_CHANNEL_ID);
    }
    else
#endif /* (GPIO_DEV_ERROR_DETECT == STD_ON) */
    {
        /* trace: SWS_Dio_00191,SWS_Dio_00192,SWS_Dio_00193 */
#ifdef DIO_ENABLE_USER_MODE_SUPPORT
        ChannelLevel = OsIf_Trusted_Call_Return2param(Dio_Lld_ToggleGPIOPin, PortHwId, PinHwId);
#else
        ChannelLevel = Dio_Lld_ToggleGPIOPin(PortHwId, PinHwId);
#endif /* DIO_ENABLE_USER_MODE_SUPPORT */
    }
    return ChannelLevel;
}
#endif /* (DIO_FLIP_CHANNEL_API == STD_ON) */

DIO_FUNC Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    Dio_LevelType ChannelLevel = STD_LOW;
    /*
    *  MR12 RULE 10.3 VIOLATION: The PortHwId is ensured to be a uint8 via limiting the ChannelId in the MCAL config tool(YCT)
    */
    Dio_PortType PortHwId = DIO_CHANNEL_PORT_NUM(ChannelId); /* PRQA S 4461 */
    /*
    *  MR12 RULE 10.3 VIOLATION: The PinHwId is ensured to be a uint8 via limiting the ChannelId in the MCAL config tool(YCT)
    */
    Dio_PinType PinHwId = (Dio_PinType)DIO_CHANNEL_PIN_NUM(ChannelId); /* PRQA S 4461 */

#if (GPIO_DEV_ERROR_DETECT == STD_ON)
    /* Check the function parameter
       Traceability : SWS_Dio_00074 */
    /* Check the channel id */

    /* check the port availability, ensure it's within PORTA~E(0~4)/less than 5 */
    if (DIO_LLD_VALID_PORT(PortHwId))
    {
        (void)Det_ReportError((uint16)DIO_MODULE_ID, DIO_INSTANCE_ID,
                              DIO_SID_READ_CHANNEL, DIO_E_PARAM_INVALID_PORT_ID);
    }
    /* check the pin rang, ensure it's within pin0~31/less than 32 */
    else if (DIO_LLD_VALID_CHANNEL(PinHwId))
    {
        (void)Det_ReportError((uint16)DIO_MODULE_ID, DIO_INSTANCE_ID,
                              DIO_SID_READ_CHANNEL, DIO_E_PARAM_INVALID_CHANNEL_ID);
    }
    else if (DIO_LLD_VALID_PORT_PIN(PortHwId, PinHwId)) /* check the pin availability */
    {
        (void)Det_ReportError((uint16)DIO_MODULE_ID, DIO_INSTANCE_ID,
                              DIO_SID_READ_CHANNEL, DIO_E_PARAM_INVALID_CHANNEL_ID);
    }
    else
#endif /* (GPIO_DEV_ERROR_DETECT == STD_ON) */
    {
        /* Traceability : SWS_Dio_00011, read the level of a single DIO channel. */
#ifdef DIO_ENABLE_USER_MODE_SUPPORT
        ChannelLevel = OsIf_Trusted_Call_Return2param(Dio_Lld_ReadGPIOPin, PortHwId, PinHwId);
#else
        ChannelLevel = Dio_Lld_ReadGPIOPin(PortHwId, PinHwId);
#endif /* DIO_ENABLE_USER_MODE_SUPPORT */
    }
    return ChannelLevel;
}

#if (DIO_CHANNEL_GROUP_NUMBER != 0)
DIO_FUNC Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType *ChannelGroupIdPtr)
{
    Dio_PortLevelType ChannelGroupValue = (Dio_PortLevelType)0U;
#if (DIO_DEV_ERROR_DETECT == STD_ON)
    /* Check the function parameter
        Traceability : SWS_Dio_00074 */
    /* Check the paramater <ChannelGroupIdPtr> */
    /* Check if NULL pointer */
    if (NULL_PTR == ChannelGroupIdPtr)
    {
        (void)Det_ReportError((uint16)DIO_MODULE_ID, DIO_INSTANCE_ID,
                              DIO_SID_READ_CHANNEL_GROUP, DIO_E_PARAM_POINTER);
    }
#if (GPIO_DEV_ERROR_DETECT == STD_ON)
    /* Check if input paramater */
    else if ((Std_ReturnType)E_NOT_OK == Dio_llCheckChannelGroup(ChannelGroupIdPtr))
    {
        (void)Det_ReportError((uint16)DIO_MODULE_ID, DIO_INSTANCE_ID,
                              DIO_SID_READ_CHANNEL_GROUP, DIO_E_PARAM_INVALID_GROUP);
    }
#endif /* (GPIO_DEV_ERROR_DETECT == STD_ON) */
    else
#endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */
    {
        /* trace: SWS_Dio_00037, SWS_Dio_00092, SWS_Dio_00093*/
#ifdef DIO_ENABLE_USER_MODE_SUPPORT
        ChannelGroupValue = ((OsIf_Trusted_Call_Return1param(Dio_Lld_ReadGPIOPort, ChannelGroupIdPtr->port)\
                                                & ChannelGroupIdPtr->mask) >> ChannelGroupIdPtr->offset);
#else
        ChannelGroupValue = ((Dio_Lld_ReadGPIOPort(ChannelGroupIdPtr->port) \
                                                & ChannelGroupIdPtr->mask) >> ChannelGroupIdPtr->offset);
#endif /* DIO_ENABLE_USER_MODE_SUPPORT */

    }
    return ChannelGroupValue;
}
#endif /* (DIO_CHANNEL_GROUP_NUMBER != 0) */

DIO_FUNC Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
    Dio_PortLevelType PortLevel = 0U;
#if (GPIO_DEV_ERROR_DETECT == STD_ON)
    /* Check the function parameter
       Traceability : SWS_Dio_00074 */
    /* Check the port id */
    if (DIO_LLD_VALID_PORT(PortId))
    {
        (void)Det_ReportError((uint16)DIO_MODULE_ID, DIO_INSTANCE_ID,
                              DIO_SID_READ_PORT, DIO_E_PARAM_INVALID_PORT_ID);
        PortLevel = (Dio_PortLevelType)0U;
    }
    else
#endif /* (GPIO_DEV_ERROR_DETECT == STD_ON) */
    {

#ifdef DIO_ENABLE_USER_MODE_SUPPORT
        PortLevel = OsIf_Trusted_Call_Return1param(Dio_Lld_ReadGPIOPort, PortId);
#else
        PortLevel = Dio_Lld_ReadGPIOPort(PortId);
#endif /* DIO_ENABLE_USER_MODE_SUPPORT */

    }
    return PortLevel;
}

DIO_FUNC void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    /*
    *  MR12 RULE 10.3 VIOLATION: The PortHwId is ensured to be a uint8 via limiting the ChannelId in the MCAL config tool(YCT)
    */
    Dio_PortType PortHwId = DIO_CHANNEL_PORT_NUM(ChannelId); /* PRQA S 4461 */
    /*
    *  MR12 RULE 10.3 VIOLATION: The PinHwId is ensured to be a uint8 via limiting the ChannelId in the MCAL config tool(YCT)
    */
    Dio_PinType PinHwId = (Dio_PinType)DIO_CHANNEL_PIN_NUM(ChannelId); /* PRQA S 4461 */

#if (GPIO_DEV_ERROR_DETECT == STD_ON)
    /* Check the function parameter
       Traceability : SWS_Dio_00074 */
    /* Check the channel id */

    /* check the port availability, ensure it's within PORTA~E(0~4)/less than 5 */
    if (DIO_LLD_VALID_PORT(PortHwId))
    {
        (void)Det_ReportError((uint16)DIO_MODULE_ID, DIO_INSTANCE_ID,
                              DIO_SID_WRITE_CHANNEL, DIO_E_PARAM_INVALID_PORT_ID);
    }
    /* check the pin rang, ensure it's within pin0~31/less than 32 */
    else if (DIO_LLD_VALID_CHANNEL(PinHwId))
    {
        (void)Det_ReportError((uint16)DIO_MODULE_ID, DIO_INSTANCE_ID,
                              DIO_SID_WRITE_CHANNEL, DIO_E_PARAM_INVALID_CHANNEL_ID);
    }
    else if (DIO_LLD_VALID_PORT_PIN(PortHwId, PinHwId)) /* check the pin availability */
    {
        (void)Det_ReportError((uint16)DIO_MODULE_ID, DIO_INSTANCE_ID,
                              DIO_SID_WRITE_CHANNEL, DIO_E_PARAM_INVALID_CHANNEL_ID);
    }
    else
#endif /* (GPIO_DEV_ERROR_DETECT == STD_ON) */
    {

#ifdef DIO_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call3params(Dio_Lld_WriteGPIOPin, PortHwId, PinHwId, Level);
#else
        Dio_Lld_WriteGPIOPin(PortHwId, PinHwId, Level);
#endif /* DIO_ENABLE_USER_MODE_SUPPORT */

    }
}

#if (DIO_CHANNEL_GROUP_NUMBER != 0)
DIO_FUNC void Dio_WriteChannelGroup(const Dio_ChannelGroupType *ChannelGroupIdPtr, Dio_PortLevelType Level)
{
    Dio_PortLevelType ChannelGroupWriteValue;
#if (DIO_DEV_ERROR_DETECT == STD_ON)
    /* Check the function parameter
        Traceability : SWS_Dio_00074 */
    /* Check the paramater <ChannelGroupIdPtr> */
    /* Check if NULL pointer */
    if (NULL_PTR == ChannelGroupIdPtr)
    {
        (void)Det_ReportError((uint16)DIO_MODULE_ID, DIO_INSTANCE_ID,
                              DIO_SID_WRITE_CHANNEL_GROUP, DIO_E_PARAM_POINTER);
    }
#if (GPIO_DEV_ERROR_DETECT == STD_ON)
    /* Check if input paramater */
    else if ((Std_ReturnType)E_NOT_OK == Dio_llCheckChannelGroup(ChannelGroupIdPtr))
    {
        (void)Det_ReportError((uint16)DIO_MODULE_ID, DIO_INSTANCE_ID,
                              DIO_SID_WRITE_CHANNEL_GROUP, DIO_E_PARAM_INVALID_GROUP);
    }
#endif /* (GPIO_DEV_ERROR_DETECT == STD_ON) */
    else
#endif /* (DIO_DEV_ERROR_DETECT == STD_ON) */
    {
        /* Traceability : SWS_Dio_00008
            simultaneously set an adjoining subset of DIO channels (channel group). */
        /* trace: SWS_Dio_00039, SWS_Dio_00040, SWS_Dio_00090, SWS_Dio_00091 */
        ChannelGroupWriteValue = (Level << (ChannelGroupIdPtr->offset)) & (ChannelGroupIdPtr->mask);

#ifdef DIO_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call2params(Dio_Lld_WriteGPIOPort, ChannelGroupIdPtr->port, ChannelGroupWriteValue);
#else
        Dio_Lld_WriteGPIOPort(ChannelGroupIdPtr->port, ChannelGroupWriteValue);
#endif /* DIO_ENABLE_USER_MODE_SUPPORT */

    }
}
#endif /* (DIO_CHANNEL_GROUP_NUMBER != 0) */

DIO_FUNC void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
#if (GPIO_DEV_ERROR_DETECT == STD_ON)
    /* Check the function parameter
       Traceability : SWS_Dio_00074 */
    /* Check the port id */
    if (DIO_LLD_VALID_PORT(PortId))
    {
        (void)Det_ReportError((uint16)DIO_MODULE_ID, DIO_INSTANCE_ID,
                              DIO_SID_WRITE_PORT, DIO_E_PARAM_INVALID_PORT_ID);
    }
    else
#endif /* (GPIO_DEV_ERROR_DETECT == STD_ON) */
    {
        /* Traceability : SWS_Dio_00007:
          The Dio_WritePort function shall simultaneously
          set the levels of all output channels.  */

#ifdef DIO_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call2params(Dio_Lld_WriteGPIOPort, PortId, Level);
#else
        Dio_Lld_WriteGPIOPort(PortId, Level);
#endif /* DIO_ENABLE_USER_MODE_SUPPORT */

        /* The Dio_WritePort function shall ensure that the functionality
           of the input channels of that port is not affected.
           Traceability : SWS_Dio_00004 */
    }
}

#if (DIO_MASKED_WRITE_PORT_API == STD_ON)
DIO_FUNC void Dio_MaskedWritePort(Dio_PortType PortId, Dio_PortLevelType Level, \
                                  Dio_PortLevelType Mask)
{
    Dio_PortLevelType PortValue = 0U;
#if (GPIO_DEV_ERROR_DETECT == STD_ON)
    /* Check the function parameter
       Traceability : SWS_Dio_00074 */
    /* Check the port id */
    if (DIO_LLD_VALID_PORT(PortId))
    {
        (void)Det_ReportError((uint16)DIO_MODULE_ID, DIO_INSTANCE_ID,
                              DIO_SID_MASKED_WRITE_PORT, DIO_E_PARAM_INVALID_PORT_ID);
    }
    else
#endif /* (GPIO_DEV_ERROR_DETECT == STD_ON) */
    {
        /* [SWS_Dio_00005] The Dio module's read and write services shall ensure for all
           services, that the data is consistent (Interruptable read-modify-write sequences are
           not allowed).(SRS_Dio_12424) */

        /* Traceability : SWS_Dio_00005:
          The Dio_WritePort function shall simultaneously
          set the levels of all output channels.  */
        SchM_Enter_Dio_DIO_EXCLUSIVE_AREA_00();

        /* Set the bits that are set in the mask */
        PortValue = Mask & Level;

#ifdef DIO_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call2params(Dio_Lld_WriteSetOutGPIOPort, PortId, PortValue);
#else
        Dio_Lld_WriteSetOutGPIOPort(PortId, PortValue);
#endif /* DIO_ENABLE_USER_MODE_SUPPORT */

        /* Clear the bits that are set in the mask */
        PortValue = (~Level) & Mask;

#ifdef DIO_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call2params(Dio_Lld_WriteClrOutGPIOPort, PortId, PortValue);
#else
        Dio_Lld_WriteClrOutGPIOPort(PortId, PortValue);
#endif /* DIO_ENABLE_USER_MODE_SUPPORT */

        /* The Dio_WritePort function shall ensure that the functionality
           of the input channels of that port is not affected.
           Traceability : SWS_Dio_00005 */
        SchM_Exit_Dio_DIO_EXCLUSIVE_AREA_00();

    }
}
#endif /* (DIO_MASKED_WRITE_PORT_API == STD_ON) */

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#if (DIO_CHANNEL_GROUP_NUMBER != 0)
#if (GPIO_DEV_ERROR_DETECT == STD_ON)
DIO_FUNC LOCAL_INLINE Std_ReturnType Dio_llCheckChannelGroup(const Dio_ChannelGroupType *ChannelGroupIdPtr)
{
    Std_ReturnType CheckResult = (Std_ReturnType)E_OK;
    /* Check pointer address */
    if ((Std_ReturnType)E_OK == Dio_llCheckChannelGroupPtr(ChannelGroupIdPtr))
    {
        /* Check element <port> */
        if (DIO_LLD_VALID_PORT(ChannelGroupIdPtr->port))
        {
            CheckResult = (Std_ReturnType)E_NOT_OK;
        }
        /* Check element <mask> */
        else if ((Dio_PortType)0U == ChannelGroupIdPtr->mask)
        {
            CheckResult = (Std_ReturnType)E_NOT_OK;
        }
        else if ((ChannelGroupIdPtr->mask & Dio_gPortPinsMask[ChannelGroupIdPtr->port]) != ChannelGroupIdPtr->mask)
        {
            CheckResult = (Std_ReturnType)E_NOT_OK;
        }
        /* Check element <offset> */
        else if (DIO_PORT_PIN_TOTAL_NUMBER <= ChannelGroupIdPtr->offset)
        {
            CheckResult = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            CheckResult = (Std_ReturnType)E_OK;
        }
    }
    else
    {
        CheckResult = (Std_ReturnType)E_NOT_OK;
    }
    return CheckResult;
}

DIO_FUNC LOCAL_INLINE Std_ReturnType Dio_llCheckChannelGroupPtr(const Dio_ChannelGroupType *ChannelGroupIdPtr)
{
    Std_ReturnType CheckResult = (Std_ReturnType)E_NOT_OK;
    for (uint32 PtrIndex = 0U; PtrIndex < (uint32)DIO_CHANNEL_GROUP_NUMBER; PtrIndex++)
    {
        if (&Dio_ChannelGroupConfig[PtrIndex] == ChannelGroupIdPtr)
        {
            CheckResult = (Std_ReturnType)E_OK;
            break;
        }
        else
        {
            /* Do nothing */
        }
    }
    return CheckResult;
}

#endif /* (GPIO_DEV_ERROR_DETECT == STD_ON) */
#endif

#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

