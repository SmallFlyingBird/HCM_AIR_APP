/**
 *   @file    Dio.h
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

#ifndef DIO_H
#define DIO_H

/**
*   @file Dio.h
*   @implements Dio.h_Artifact
*
*   @defgroup DIO
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @page misra_violations MISRA-C:2004 violations
 *
 */

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/
#include "Std_Types.h"
#include "Dio_Cfg.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
 * @file     Dio.h
 */
#define DIO_VENDOR_ID                      (180)
#define DIO_AR_RELEASE_MAJOR_VERSION       (4)
#define DIO_AR_RELEASE_MINOR_VERSION       (4)
#define DIO_AR_RELEASE_REVISION_VERSION    (0)
#define DIO_SW_MAJOR_VERSION               (2)
#define DIO_SW_MINOR_VERSION               (3)
#define DIO_SW_PATCH_VERSION               (0)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/**
 * @file     Dio.h
 */
/* Check if source file and DIO configuration header file are of the same vendor */
#if (DIO_VENDOR_ID != DIO_VENDOR_ID_CFG)
#error "Dio.h and Dio_Cfg.h have different vendor ids"
#endif

/* Check if source file and DIO configuration header file are of the same Autosar version */
#if ((DIO_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (DIO_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION_CFG) || \
     (DIO_AR_RELEASE_REVISION_VERSION != DIO_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Dio.h and Dio_Cfg.h are different"
#endif

/* Check if source file and DIO configuration header file are of the same software version */
#if ((DIO_SW_MAJOR_VERSION != DIO_SW_MAJOR_VERSION_CFG) || \
     (DIO_SW_MINOR_VERSION != DIO_SW_MINOR_VERSION_CFG) || \
     (DIO_SW_PATCH_VERSION != DIO_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Dio.h and Dio_Cfg.h are different"
#endif

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/** @brief DIO MODULE INSTANCE ID */
#define DIO_INSTANCE_ID ((uint8)0U)

/** @brief DIO MODULE ID */
#define DIO_MODULE_ID (120U)

#if (DIO_DEV_ERROR_DETECT == STD_ON)
/**
 * @defgroup Dio_DEV_ERROR
 * @brief DIO development errors
 */
/** @{ */
/** @brief Invalid channel name requested */
#define DIO_E_PARAM_INVALID_CHANNEL_ID (0x0AU)
/** @brief Invalid port name requested */
#define DIO_E_PARAM_INVALID_PORT_ID (0x14U)
/** @brief Invalid ChannelGroup passed */
#define DIO_E_PARAM_INVALID_GROUP (0x1FU)
/** @brief API service called with a NULL pointer */
#define DIO_E_PARAM_POINTER (0x20U)
/** @brief Invalid channel level */
/*#define DIO_E_PARAM_INVALID_CHANNEL_LEVEL (0x0BU)*/
/** @} */
#endif

/**
 * @defgroup Dio_SID
 * @brief Service ID number for all DIO driver services
 */
/** @{ */
/** @brief API Service ID for Dio_ReadChannel */
#define DIO_SID_READ_CHANNEL ((uint8)0x00)
/** @brief API Service ID for Dio_WriteChannel */
#define DIO_SID_WRITE_CHANNEL ((uint8)0x01)
/** @brief API Service ID for Dio_ReadPort */
#define DIO_SID_READ_PORT ((uint8)0x02)
/** @brief API Service ID for Dio_WritePort */
#define DIO_SID_WRITE_PORT ((uint8)0x03)
/** @brief API Service ID for Dio_ReadChannelGroup */
#define DIO_SID_READ_CHANNEL_GROUP ((uint8)0x04)
/** @brief API Service ID for Dio_WriteChannelGroup */
#define DIO_SID_WRITE_CHANNEL_GROUP ((uint8)0x05)
/** @brief API Service ID for Dio_MaskedWritePort */
#define DIO_SID_MASKED_WRITE_PORT ((uint8)0x03)
/** @brief API Service ID for Dio_GetVersionInfo */
#define DIO_SID_GET_VERSION_INFO  ((uint8)0x12)/*PRQA S 1534*/
/** @brief API Service ID for Dio_FlipChannel */
#define DIO_SID_FLIP_CHANNEL ((uint8)0x11)
/** @} */

/** @brief DIO channel unmasked/unavailable */
#define DIO_PIN_NOT_MASKED ((uint32)0U)

/** @brief DIO channel masked/available */
/*#define DIO_PIN_MASKED ((uint32)1U)*/

/** @brief Total number of ports in the MCU */
#define DIO_PORT_TOTAL_NUMBER (5U)

/** @brief Total number of pins in a port */
#define DIO_PORT_PIN_TOTAL_NUMBER (32U)

#if (DIO_CHANNELID_CONTINUITY == STD_ON)

/** @brief Get the pin number of a DIO channel */
#define DIO_CHANNEL_PIN_NUM(x)   ((Dio_ChannelType)(x)%DIO_PORT_PIN_TOTAL_NUMBER)
/** @brief Get the port number of a DIO channel */
#define DIO_CHANNEL_PORT_NUM(x)  ((Dio_ChannelType)(x)/DIO_PORT_PIN_TOTAL_NUMBER)

#else   /* DIO_CHANNELID_CONTINUITY == STD_OFF */

/** @brief Get the pin number of a DIO channel */
#define DIO_CHANNEL_PIN_NUM(x)   ((Dio_ChannelType)((x)&0x00FFU))
/** @brief Get the port number of a DIO channel */
#define DIO_CHANNEL_PORT_NUM(x)  ((Dio_ChannelType)((x)&0xFF00U)>>8U)

#endif /* DIO_CHANNELID_CONTINUITY == STD_ON */


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                             TYPEDEF
==================================================================================================*/
/**
 * @brief These are the possible levels a DIO channel can have
 * @details STD_HIGH, STD_LOW
 * @note Trace: SWS_Dio_00185
 */
typedef uint8 Dio_LevelType;

/**
 * @brief Numeric ID of a DIO channel
 * @note Trace: SWS_Dio_00182
 */
typedef uint16 Dio_ChannelType;

/**
 * @brief  If the MCU owns ports of different port widths (e.g. 4, 8,16...Bit)
 *      Dio_PortLevelType inherits the size of the largest port
 * @note Trace: SWS_Dio_00186
 */
typedef uint32 Dio_PortLevelType;

/**
 * @brief Numeric ID of a DIO port
 * @note Trace: SWS_Dio_00183
 */
typedef uint8 Dio_PortType;

/**
 * @brief Numeric ID of a DIO pin
 */
typedef uint8 Dio_PinType;

#if (DIO_CHANNEL_GROUP_NUMBER != 0)
/**
 * @brief  Type for the definition of a channel group, which consists of
 *      several adjoining channels within a port
 * @note Trace: SWS_Dio_00184
 */
typedef struct
{
    uint32 mask;       /*!< This element mask which defines the positions of the channel group */
    uint8 offset;      /*!< This element shall be the position of the Channel Group on the port, counted from the LSB */
    Dio_PortType port; /*!< This shall be the port on which the Channel group is defined */
} Dio_ChannelGroupType;
#endif /* (DIO_CHANNEL_GROUP_NUMBER != 0) */

/*==================================================================================================
*                                         EXTERNAL CONSTANTS
==================================================================================================*/
#if (DIO_CHANNEL_GROUP_NUMBER != 0)
extern  const Dio_ChannelGroupType Dio_ChannelGroupConfig[DIO_CHANNEL_GROUP_NUMBER];
#endif

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
 * @brief            Service to flip (change from 1 to 0 or from 0 to 1) the level of
 *                   a channel and return the level of the channel after flip.
 * @details          The API is used to flip the level of a Dio channel and return the level of the channel
 * @param[in]        ChannelId ID of DIO channel
 * @return           Dio_LevelType
 */
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);

/**
 * @brief            Returns the value of the specified DIO channel.
 * @details          The API is used to read the level of a Dio channel.
 * @param[in]        ChannelId ID of DIO channel
 * @return           Dio_LevelType
 * @note             service_id       0x00
 */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

#if (DIO_CHANNEL_GROUP_NUMBER != 0)
/**
 * @brief            This Service reads a subset of the adjoining bits of a port.
 * @details          The API is used to read a subset of the adjoining Dio bits of a port.
 * @param[in]        ChannelGroupIdPtr  Pointer to ChannelGroup
 * @return           Dio_PortLevelType
 */
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType *ChannelGroupIdPtr);
#endif /* (DIO_CHANNEL_GROUP_NUMBER != 0) */

/**
 * @brief            Returns the level of all channels of that port.
 * @details          The API is used to read the level of all channels of a input port.
 * @param[in]        PortId ID of DIO Port
 * @return           Dio_PortLevelType
 */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

/**
 * @brief            Service to set a level of a channel.
 * @details          The API is used to set the level of a Dio channel.
 *
 * @param[in]        ChannelId ID of DIO channel
 * @param[in]        Level Value to be written
 *
 * @return           void
 */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

#if (DIO_CHANNEL_GROUP_NUMBER != 0)
/**
 * @brief            Service to set a subset of the adjoining bits of a port to a specified level.
 * @details          The API is used to set a subset of the adjoining Dio bits of a port to a specified level.
 *
 * @param[in]        ChannelGroupIdPtr Pointer to ChannelGroup
 * @param[in]        Level Value to be written
 *
 * @return           void
 */
void Dio_WriteChannelGroup(const Dio_ChannelGroupType *ChannelGroupIdPtr, Dio_PortLevelType Level);
#endif /* (DIO_CHANNEL_GROUP_NUMBER != 0) */

/**
 * @brief            Service to set a value of the port.
 * @details          The API is used to set the level of all Dio channels of a port.
 *
 * @param[in]        PortId ID of DIO Port
 * @param[in]        Level Value to be written
 *
 * @return           void
 */
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);

#if (DIO_MASKED_WRITE_PORT_API == STD_ON)
/**
 * @brief            Service to set the value of a given port with required mask.
 * @details          The API set the specified value for the channels in the specified port if
 *                   the corresponding bit in Mask is '1'.
 *
 * @param[in]        PortId ID of DIO Port
 * @param[in]        Level Value to be written
 * @param[in]        Mask Channels to be masked in the port
 *
 * @return           void
 */
void Dio_MaskedWritePort(Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask);
#endif /* (DIO_MASKED_WRITE_PORT_API == STD_ON) */

#if (((DIO_VERSION_INFO_API == STD_ON) && (DIO_DEV_ERROR_DETECT == STD_ON)))
/**
 * @brief            Returns the version information of this module.
 * @details
 * @param[out]       versioninfo Pointer to where to store version information of this module
 * @return           none
 *
 */
#define Dio_GetVersionInfo(versioninfo) /*PRQA S 1534*/                      \
    {                                                                         \
        /* Check for DET: DIO_E_PARAM_POINTER */                              \
        if ((versioninfo) == NULL_PTR)                                        \
        {                                                                     \
            /* Report DIO_E_PARAM_POINTER DET if service called with          \
               NULL_PTR                                                       \
            */                                                                \
            Det_ReportError(                                                  \
                (uint16)DIO_MODULE_ID,                                        \
                DIO_INSTANCE_ID,                                              \
                DIO_SID_GET_VERSION_INFO,                                     \
                DIO_E_PARAM_POINTER);                                         \
        }                                                                     \
        else                                                                  \
        {                                                                     \
            /* Vendor ID information */                                       \
            ((Std_VersionInfoType *)(versioninfo))->vendorID = DIO_VENDOR_ID; \
            /* Dio module ID information */                                   \
            ((Std_VersionInfoType *)(versioninfo))->moduleID = DIO_MODULE_ID; \
            /* Dio module Software major version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_major_version =        \
                (uint8)DIO_SW_MAJOR_VERSION;                                      \
            /* Dio module Software minor version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_minor_version =        \
                (uint8)DIO_SW_MINOR_VERSION;                                      \
            /* Dio module Software patch version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_patch_version =        \
                (uint8)DIO_SW_PATCH_VERSION;                                      \
        }                                                                     \
    }
#elif (((DIO_VERSION_INFO_API == STD_ON) && (DIO_DEV_ERROR_DETECT == STD_OFF)))
#define Dio_GetVersionInfo(versioninfo)                                   \
    {                                                                     \
        /* Vendor ID information */                                       \
        ((Std_VersionInfoType *)(versioninfo))->vendorID = DIO_VENDOR_ID; \
        /* Dio module ID information */                                   \
        ((Std_VersionInfoType *)(versioninfo))->moduleID = DIO_MODULE_ID; \
        /* Dio module Software major version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_major_version =        \
            (uint8)DIO_SW_MAJOR_VERSION;                                      \
        /* Dio module Software minor version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_minor_version =        \
            (uint8)DIO_SW_MINOR_VERSION;                                      \
        /* Dio module Software patch version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_patch_version =        \
            (uint8)DIO_SW_PATCH_VERSION;                                      \
    }
#endif /* (((DIO_VERSION_INFO_API == STD_ON) && (DIO_DEV_ERROR_DETECT == STD_ON))) */

#ifdef __cplusplus
}
#endif

#endif /* DIO_H */

/** @} */

