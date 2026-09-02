/**
 * @file    Fls.h
 * @version
 *
 * @brief   AUTOSAR Fls module interface
 * @details API implementation for FLS driver
 *
 * @addtogroup FLS_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Fls
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

#ifndef FLS_H
#define FLS_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * @page misra_violations MISRA-C:2012 violations list
 * PRQA S 1534 Rule 2.5:  A project should not contain unused macro definitions.
 *
 */

/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include "Std_Types.h"
#include "Fls_Cfg.h"
#include "MemIf_Types.h"
#include "Fls_Types.h"
#include "Det.h"


/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_VENDOR_ID                      (180)
#define FLS_AR_RELEASE_MAJOR_VERSION       (4)
#define FLS_AR_RELEASE_MINOR_VERSION       (4)
#define FLS_AR_RELEASE_REVISION_VERSION    (0)
#define FLS_SW_MAJOR_VERSION               (2)
#define FLS_SW_MINOR_VERSION               (3)
#define FLS_SW_PATCH_VERSION               (0)


/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and FLS configuration header file are of the same vendor */
#if (FLS_VENDOR_ID != FLS_VENDOR_ID_CFG)
#error "Fls.h and Fls_Cfg.h have different vendor ids"
#endif

/* Check if source file and FLS configuration header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION != FLS_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FLS_AR_RELEASE_MINOR_VERSION != FLS_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FLS_AR_RELEASE_REVISION_VERSION != FLS_AR_RELEASE_REVISION_VERSION_CFG) \
    )
#error "AutoSar Version Numbers of Fls.h and Fls_Cfg.h are different"
#endif

/* Check if source file and FLS configuration header file are of the same software version */
#if ((FLS_SW_MAJOR_VERSION != FLS_SW_MAJOR_VERSION_CFG) || \
     (FLS_SW_MINOR_VERSION != FLS_SW_MINOR_VERSION_CFG) || \
     (FLS_SW_PATCH_VERSION != FLS_SW_PATCH_VERSION_CFG) \
    )
#error "Software Version Numbers of Fls.h and Fls_Cfg.h are different"
#endif

/* Check if source file and FLS type header file are of the same vendor */
#if (FLS_VENDOR_ID != FLS_TYPES_VENDOR_ID)
#error "Fls.h and Fls_Types.h have different vendor ids"
#endif

/* Check if source file and FLS type header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION != FLS_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_AR_RELEASE_MINOR_VERSION != FLS_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FLS_AR_RELEASE_REVISION_VERSION != FLS_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Fls.h and Fls_Types.h are different"
#endif

/* Check if source file and FLS type header file are of the same software version */
#if ((FLS_SW_MAJOR_VERSION != FLS_TYPES_SW_MAJOR_VERSION) || \
     (FLS_SW_MINOR_VERSION != FLS_TYPES_SW_MINOR_VERSION) || \
     (FLS_SW_PATCH_VERSION != FLS_TYPES_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Fls.h and Fls_Types.h are different"
#endif


/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief FLS MODULE INSTANCE ID */
#define FLS_INSTANCE_ID         ((uint8)0U)

/** @brief FLS MODULE ID */
#define FLS_MODULE_ID           ((uint16)92)

#if (FLS_DEV_ERROR_DETECT == STD_ON)
/**
 * @defgroup        Fls_DEV_ERROR
 * @brief           FLS development errors
 * @{
 */
/** @brief FLS API service is called using an invalid configuration.  */
#define FLS_E_PARAM_CONFIG              ((uint8)0x01U)
/** @brief FLS API service is called using an invalid address.  */
#define FLS_E_PARAM_ADDRESS             ((uint8)0x02U)
/** @brief FLS API service is called using an invalid data length.  */
#define FLS_E_PARAM_LENGTH              ((uint8)0x03U)
/** @brief FLS API service is called using an invalid data align.  */
#define FLS_E_PARAM_DATA                ((uint8)0x04U)
/** @brief FLS API service called without module initialization.  */
#define FLS_E_UNINIT                    ((uint8)0x05U)
/** @brief FLS API service called while driver still busy.  */
#define FLS_E_BUSY                      ((uint8)0x06U)
/** @brief FLS API service called with NULL pointer.  */
/* MR12 Rule 2.5 VIOLATION: The macro has been used in Fls_GetVersionInfo.
*/
#define FLS_E_PARAM_POINTER             ((uint8)0x0AU)  /*PRQA S 1534*/
/** @} */
#endif
/** @brief FLS Erase verification (blank check) failed.  */
#define FLS_E_VERIFY_ERASE_FAILED       ((uint8)0x07U)
/** @brief FLS Write verification (compare) failed.  */
#define FLS_E_VERIFY_WRITE_FAILED       ((uint8)0x08U)
/** @brief FLS timeout.  */
#define FLS_E_TIMEOUT                   ((uint8)0x09U)

/**
* @defgroup        Fls_HW_ERROR
* @brief          Transient Faults codes (passed to DET).
*/
/**
* @brief           Flash erase failed (HW)
*/
#define FLS_E_ERASE_FAILED           0x01U
/**
* @brief           Flash write failed (HW)
*/
#define FLS_E_WRITE_FAILED           0x02U
/**
* @brief           Flash read failed (HW)
*/
#define FLS_E_READ_FAILED            0x03U
/**
* @brief           Flash compare failed (HW)
*/
#define FLS_E_COMPARE_FAILED         0x04U

#if (FLS_QSPI_SECTORS_CONFIGURED == STD_ON)
#define FLS_E_UNEXPECTED_FLASH_ID    0x05U /* Expected hardware ID not matched */
#endif

/**
 * @defgroup        Fls_SID
 * @brief           Service ID number for all FLS driver services
 * @{
 */
/** @brief API Service ID for Fls_Init */
#define FLS_SID_INIT                                         (0x00U)
/** @brief API Service ID for Fls_Erase */
#define FLS_SID_ERASE                                        (0x01U)
/** @brief API Service ID for Fls_Write */
#define FLS_SID_WRITE                                        (0x02U)
/** @brief API Service ID for Fls_Cancel */
#define FLS_SID_CANCEL                                       (0x03U)
/** @brief API Service ID for Fls_GetStatus */
/* MR12 Rule 2.5 VIOLATION: This macro is the service id for Fls_GetStatus
*                           defined in AUTOSAR SWS,it can't be deleted.
*/
#define FLS_SID_GET_STATUS                                   (0x04U) /*PRQA S 1534*/
/** @brief API Service ID for Fls_GetJobResult */
#define FLS_SID_GET_JOB_RESULT                               (0x05U)
/** @brief API Service ID for Fls_MainFunction */
#define FLS_SID_MAIN_FUNCTION                                (0x06U)
/** @brief API Service ID for Fls_Read */
#define FLS_SID_READ                                         (0x07U)
/** @brief API Service ID for Fls_Compare */
#define FLS_SID_COMPARE                                      (0x08U)
/** @brief API Service ID for Fls_SetMode */
#define FLS_SID_SET_MODE                                     (0x09U)
/** @brief API Service ID for Fls_BlankCheck */
#define FLS_SID_BLANK_CHECK                                  (0x0aU)
/** @brief API Service ID for Fls_GetVersionInfo */
/* MR12 Rule 2.5 VIOLATION: The macro has been used in Fls_GetVersionInfo.
*/
#define FLS_SID_GET_VERSION_INFO                             (0x10U) /*PRQA S 1534*/
/** @} */

/*! Invalid device instance */
#define FLS_DEVICE_INSTANCE_INVALID       (0xFFU)

/*==================================================================================================
 *                                         EXTERNAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                         EXTERNAL VARIABLE
==================================================================================================*/

/*==================================================================================================
 *                                             ENUMS
==================================================================================================*/

/**
 * @brief            Initializes the Flash Driver.
 * @details          The function sets the internal module variables according to given
 *                   configuration set.
 * @param[in]        ConfigPtr Pointer to flash driver configuration set.
 * @return           void
 */
void Fls_Init(const Fls_ConfigType *ConfigPtr);

/**
 * @brief            Erases flash sector(s).
 * @details          Starts an erase job asynchronously. The actual job is performed
 *                   by the @p Fls_MainFunction.
 * @param[in]        TargetAddress Target address in flash memory. This address offset will be added to
 *                   the flash memory base address.
 *                    Min.:  0
 *                    Max.: FLS_SIZE - 1
 * @param[in]        Length Number of bytes to erase
 *                    Min.:  1
 *                    Max.: FLS_SIZE - TargetAddress
 * @return           Std_ReturnType
 */
Std_ReturnType Fls_Erase(Fls_AddressType TargetAddress, Fls_LengthType Length);

/**
 * @brief            Writes one or more complete flash pages.
 * @details          Starts a write job asynchronously. The actual job is performed by @p Fls_MainFunction.
 * @param[in]        TargetAddress Target address in flash memory. This address offset will be added to the flash memory base address.
 *                    Min.:  0
 *                    Max.: FLS_SIZE - 1
 * @param[in]        SourceAddressPtr Pointer to source data buffer
 * @param[in]        Length Number of bytes to write
 *                    Min.:  1
 *                    Max.: FLS_SIZE - TargetAddress
 * @return           Std_ReturnType
 */
Std_ReturnType Fls_Write(Fls_AddressType TargetAddress, const uint8 *SourceAddressPtr, Fls_LengthType Length);

#if (STD_ON == FLS_CANCEL_API)
/**
 * @brief            Cancels an ongoing job.
 * @details          Abort a running job synchronously so that directly after returning
 *                   from this function a new job can be started.
 * @return           void
 */
void Fls_Cancel(void);
#endif

#if (STD_ON == FLS_GET_STATUS_API)
/**
 * @brief            Returns the driver state.
 * @details          Returns the FLS module status synchronously.
 * @return           MemIf_StatusType
 */
MemIf_StatusType Fls_GetStatus(void);
#endif

#if (STD_ON == FLS_GET_JOB_RESULT_API)
/**
 * @brief            Returns the result of the last job.
 * @details          Returns the result of the last job synchronously.
 * @return           MemIf_JobResultType
 */
MemIf_JobResultType Fls_GetJobResult(void);
#endif

/**
 * @brief            Performs the processing of jobs.
 * @details          Bytes number processed per cycle depends by job type (erase, write, read, compare)
 *                   current FLS module's operating mode (normal, fast) and write, erase Mode of Execution (sync, async).
 * @return           void
 */
void Fls_MainFunction(void);

/**
 * @brief            Reads from flash memory.
 * @details          Starts a read job asynchronously. The actual job is performed by
 *                   @p Fls_MainFunction.
 * @param[in]        SourceAddress Source address in flash memory. This address offset will be added to the flash memory base address.
 *                    Min.:  0
 *                    Max.: FLS_SIZE - 1
 * @param[out]       TargetAddressPtr Pointer to target data buffer
 * @param[in]        Length Number of bytes to read
 *                    Min.:  1
 *                    Max.: FLS_SIZE - SourceAddress
 * @return           Std_ReturnType
 */
Std_ReturnType Fls_Read(Fls_AddressType SourceAddress, uint8 *TargetAddressPtr, Fls_LengthType Length);

#if (STD_ON == FLS_COMPARE_API)
/**
 * @brief            Compares the contents of an area of flash memory with that of an application data buffer.
 * @details          Starts a compare job asynchronously. The actual job is performed by
 *                   @p Fls_MainFunction.
 * @param[in]        SourceAddress Source address in flash memory. This address offset will be added to the flash memory base address.
 *                    Min.:  0
 *                    Max.: FLS_SIZE - 1
 * @param[in]        TargetAddressPtr Pointer to target data buffer
 * @param[in]        Length Number of bytes to compare
 *                    Min.:  1
 *                    Max.: FLS_SIZE - SourceAddress
 * @return           Std_ReturnType
 */
Std_ReturnType Fls_Compare(Fls_AddressType SourceAddress, const uint8 *TargetAddressPtr, Fls_LengthType Length);
#endif

#if (STD_ON == FLS_SET_MODE_API)
/**
 * @brief            Sets the flash driver's operation mode.
 * @details          Every given mode determinates maximum bytes for read-write
 *                   operations. Every mode has a set of pre-configured values.
 * @param[in]        Mode MEMIF_MODE_SLOW: Slow read access / normal SPI access.
 *                        MEMIF_MODE_FAST: Fast read access / SPI burst access.
 * @return           void
 */
void Fls_SetMode(MemIf_ModeType Mode);
#endif

#if (STD_ON == FLS_BLANK_CHECK_API)
/**
 * @brief            The function Fls_BlankCheck shall verify, whether a given memory area has been erased but not (yet) programmed.
 *                   The function shall limit the maximum number of checked flash cells per main function cycle to the configured value
 *                   FlsMaxReadNormalMode or FlsMaxReadFastMode respectively.
 * @details          Starts a compare job asynchronously. The actual job is performed by
 *                   @p Fls_MainFunction.
 * @param[in]        TargetAddress Address in flash memory from which the blank check should be started.
 *                    Min.: 0
 *                    Max.: FLS_SIZE - 1
 * @param[in]        Length Number of bytes to be checked for erase pattern.
 *                    Min.: 1
 *                    Max.: FLS_SIZE - TargetAddress
 * @return           Std_ReturnType
 */
Std_ReturnType Fls_BlankCheck(Fls_AddressType TargetAddress, Fls_LengthType Length);
#endif

#if (((FLS_VERSION_INFO_API == STD_ON) && (FLS_DEV_ERROR_DETECT == STD_ON)))
/**
 * @brief            Read Fls Version.
 * @details          Returns version information about FLS module.
 * @param[out]       versioninfo Pointer to where to store version information of this module
 * @return           void
 */
/* MR12 Rule 2.5 VIOLATION: This macro is code for the API Fls_GetVersionInfo
*                           defined in AUTOSAR SWS,it can't be deleted.
*/
#define Fls_GetVersionInfo(versioninfo)                                       \
    {                                                                         \
        /* Check for DET: FLS_E_PARAM_POINTER */                              \
        if ((versioninfo) == NULL_PTR)                                        \
        {                                                                     \
            /* Report FLS_E_PARAM_POINTER DET if service called with          \
               NULL_PTR                                                       \
            */                                                                \
            Det_ReportError(                                                  \
                (uint16)FLS_MODULE_ID,                                        \
                FLS_INSTANCE_ID,                                              \
                FLS_SID_GET_VERSION_INFO,                                     \
                FLS_E_PARAM_POINTER);                                         \
        }                                                                     \
        else                                                                  \
        {                                                                     \
            /* Vendor ID information */                                       \
            ((Std_VersionInfoType *)(versioninfo))->vendorID = FLS_VENDOR_ID; \
            /* Fls module ID information */                                   \
            ((Std_VersionInfoType *)(versioninfo))->moduleID = FLS_MODULE_ID; \
            /* Fls module Software major version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_major_version =        \
                (uint8)FLS_SW_MAJOR_VERSION;                                      \
            /* Fls module Software minor version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_minor_version =        \
                (uint8)FLS_SW_MINOR_VERSION;                                      \
            /* Fls module Software patch version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_patch_version =        \
                (uint8)FLS_SW_PATCH_VERSION;                                      \
        }                                                                     \
    }/*PRQA S 1534*/
#elif (((FLS_VERSION_INFO_API == STD_ON) && (FLS_DEV_ERROR_DETECT == STD_OFF)))
#define Fls_GetVersionInfo(versioninfo)                                       \
    {                                                                         \
        /* Vendor ID information */                                           \
        ((Std_VersionInfoType *)(versioninfo))->vendorID = FLS_VENDOR_ID;     \
        /* Fls module ID information */                                       \
        ((Std_VersionInfoType *)(versioninfo))->moduleID = FLS_MODULE_ID;     \
        /* Fls module Software major version information */                   \
        ((Std_VersionInfoType *)(versioninfo))->sw_major_version =            \
            (uint8)FLS_SW_MAJOR_VERSION;                                          \
        /* Fls module Software minor version information */                   \
        ((Std_VersionInfoType *)(versioninfo))->sw_minor_version =            \
            (uint8)FLS_SW_MINOR_VERSION;                                          \
        /* Fls module Software patch version information */                   \
        ((Std_VersionInfoType *)(versioninfo))->sw_patch_version =            \
            (uint8)FLS_SW_PATCH_VERSION;                                          \
    }/*PRQA S 1534*/
#endif   /* FLS_VERSION_INFO_API == STD_ON && FLS_DEV_ERROR_DETECT == STD_ON */



#ifdef __cplusplus
}
#endif

#endif /* FLS_H */

/** @} */

