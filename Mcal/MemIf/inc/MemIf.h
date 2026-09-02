/**
 * @file    MemIf.h
 * @version 
 *
 * @brief   AUTOSAR MemIf module interface
 * @details API implementation for MEMIF driver
 *
 * @addtogroup MEMIF_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : MemIf
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

#ifndef MEMIF_H
#define MEMIF_H

#ifdef __cplusplus
extern "C"{
#endif


/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include "Std_Types.h"
#include "MemIf_Cfg.h"

/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEMIF_VENDOR_ID                      (180)
#define MEMIF_AR_RELEASE_MAJOR_VERSION       (4)
#define MEMIF_AR_RELEASE_MINOR_VERSION       (4)
#define MEMIF_AR_RELEASE_REVISION_VERSION    (0)
#define MEMIF_SW_MAJOR_VERSION               (2)
#define MEMIF_SW_MINOR_VERSION               (3)
#define MEMIF_SW_PATCH_VERSION               (0)


/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and MEMIF configuration header file are of the same vendor */
#if (MEMIF_VENDOR_ID != MEMIF_VENDOR_ID_CFG)
#error "MemIf.h and MemIf_Cfg.h have different vendor ids"
#endif

/* Check if source file and MEMIF configuration header file are of the same Autosar version */
#if ((MEMIF_AR_RELEASE_MAJOR_VERSION != MEMIF_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (MEMIF_AR_RELEASE_MINOR_VERSION != MEMIF_AR_RELEASE_MINOR_VERSION_CFG) || \
     (MEMIF_AR_RELEASE_REVISION_VERSION != MEMIF_AR_RELEASE_REVISION_VERSION_CFG) \
    )
#error "AutoSar Version Numbers of MemIf.h and MemIf_Cfg.h are different"
#endif

/* Check if source file and MEMIF configuration header file are of the same software version */
#if ((MEMIF_SW_MAJOR_VERSION != MEMIF_SW_MAJOR_VERSION_CFG) || \
     (MEMIF_SW_MINOR_VERSION != MEMIF_SW_MINOR_VERSION_CFG) || \
     (MEMIF_SW_PATCH_VERSION != MEMIF_SW_PATCH_VERSION_CFG) \
    )
#error "Software Version Numbers of MemIf.h and MemIf_Cfg.h are different"
#endif


/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief MEMIF MODULE INSTANCE ID */
#define MEMIF_INSTANCE_ID       ((uint8)0U)

/** @brief MEMIF MODULE ID */
#define MEMIF_MODULE_ID         ((uint16)22)

#if (MEMIF_DEV_ERROR_DETECT == STD_ON)
/**
 * @defgroup        MemIf_DEV_ERROR
 * @brief           MEMIF development errors
 * @{
 */
/** @brief MEMIF API service is called using an invalid pointer (e.g. the pointer should not be NULL).  */
#define MEMIF_E_PARAM_POINTER ((uint8)0x1U)
/** @brief MEMIF API service is called using an invalid device index.  */
#define MEMIF_E_PARAM_DEVICE ((uint8)0x2U)

/** @} */
#endif

/**
 * @defgroup        MemIf_SID
 * @brief           Service ID number for all MEMIF driver services
 * @{
 */
/** @brief API Service ID for MemIf_Cancel */
#define MEM_IF_CANCEL                                    (0x04U)
/** @brief API Service ID for MemIf_EraseImmediateBlock */
#define MEM_IF_ERASE_IMMEDIATE_BLOCK                     (0x09U)
/** @brief API Service ID for MemIf_GetJobResult */
#define MEM_IF_GET_JOB_RESULT                            (0x06U)
/** @brief API Service ID for MemIf_GetStatus */
#define MEM_IF_GET_STATUS                                (0x05U)
/** @brief API Service ID for MemIf_GetVersionInfo */
#define MEM_IF_GET_VERSION_INFO                          (0x08U)
/** @brief API Service ID for MemIf_InvalidateBlock */
#define MEM_IF_INVALIDATE_BLOCK                          (0x07U)
/** @brief API Service ID for MemIf_Read */
#define MEM_IF_READ                                      (0x02U)
/** @brief API Service ID for MemIf_SetMode */
#define MEM_IF_SET_MODE                                  (0x01U)
/** @brief API Service ID for MemIf_Write */
#define MEM_IF_WRITE                                     (0x03U)
/** @} */

/*==================================================================================================
 *                                         EXTERNAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
 *                                             ENUMS
==================================================================================================*/

/**
 * @brief           
 * @note            trace: 
 */
typedef enum {
    MEMIF_JOB_OK                             = 0, /**<    */
    MEMIF_JOB_FAILED                         = 1, /**<    */
    MEMIF_JOB_PENDING                        = 2, /**<    */
    MEMIF_JOB_CANCELED                       = 3, /**<    */
    MEMIF_BLOCK_INCONSISTENT                 = 4, /**<    */
    MEMIF_BLOCK_INVALID                      = 5, /**<    */
} MemIf_JobResultType;


/**
 * @brief           
 * @note            trace: 
 */
typedef enum {
    MEMIF_MODE_SLOW                          = 0, /**<    */
    MEMIF_MODE_FAST                          = 1, /**<    */
} MemIf_ModeType;


/**
 * @brief           
 * @note            trace: 
 */
typedef enum {
    MEMIF_UNINIT                             = 0, /**<    */
    MEMIF_IDLE                               = 1, /**<    */
    MEMIF_BUSY                               = 2, /**<    */
    MEMIF_BUSY_INTERNAL                      = 3, /**<    */
} MemIf_StatusType;



/**
 * @brief            Invokes the "Cancel" function of the underlying memory abstraction module selected by the parameter DeviceIndex.
 * @details          
 * @param[in]        uint8 
 * @return           void
 * @retval           <return_value> {return_value description}
 * @note             service_id:       0x04 \n
 *                   is_reentrant:     false \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
void MemIf_Cancel (uint8 DeviceIndex);

/**
 * @brief            Invokes the "EraseImmediateBlock" function of the underlying memory abstraction module selected by the parameter DeviceIndex.
 * @details          
 * @param[in]        uint8 
 * @param[in]        uint16 
 * @return           Std_ReturnType
 * @retval           <return_value> {return_value description}
 * @note             service_id:       0x09 \n
 *                   is_reentrant:     false \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
Std_ReturnType MemIf_EraseImmediateBlock (uint8 DeviceIndex, uint16 BlockNumber);

/**
 * @brief            Invokes the "GetJobResult" function of the underlying memory abstraction module selected by the parameter DeviceIndex.
 * @details          
 * @param[in]        uint8 
 * @return           MemIf_JobResultType
 * @retval           <return_value> {return_value description}
 * @note             service_id:       0x06 \n
 *                   is_reentrant:     false \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
MemIf_JobResultType MemIf_GetJobResult (uint8 DeviceIndex);

/**
 * @brief            Invokes the "GetStatus" function of the underlying memory abstraction module selected by the parameter DeviceIndex.
 * @details          
 * @param[in]        uint8 
 * @return           MemIf_StatusType
 * @retval           <return_value> {return_value description}
 * @note             service_id:       0x05 \n
 *                   is_reentrant:     false \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
MemIf_StatusType MemIf_GetStatus (uint8 DeviceIndex);

/**
 * @brief            Returns version information.
 * @details          
 * @param[out]       Std_VersionInfoType Pointer to standard version information structure.
 * @return           void
 * @retval           <return_value> {return_value description}
 * @note             service_id:       0x08 \n
 *                   is_reentrant:     true \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
void MemIf_GetVersionInfo (Std_VersionInfoType * VersionInfoPtr);

/**
 * @brief            Invokes the "InvalidateBlock" function of the underlying memory abstraction module selected by the parameter DeviceIndex.
 * @details          
 * @param[in]        uint8 
 * @param[in]        uint16 
 * @return           Std_ReturnType
 * @retval           <return_value> {return_value description}
 * @note             service_id:       0x07 \n
 *                   is_reentrant:     false \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
Std_ReturnType MemIf_InvalidateBlock (uint8 DeviceIndex, uint16 BlockNumber);

/**
 * @brief            Invokes the "Read" function of the underlying memory abstraction module selected by the parameter DeviceIndex.
 * @details          
 * @param[in]        uint8 
 * @param[in]        uint16 
 * @param[in]        uint16 
 * @param[out]       uint8 
 * @param[in]        uint16 
 * @return           Std_ReturnType
 * @retval           <return_value> {return_value description}
 * @note             service_id:       0x02 \n
 *                   is_reentrant:     false \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
Std_ReturnType MemIf_Read (uint8 DeviceIndex, uint16 BlockNumber, uint16 BlockOffset, uint8 * DataBufferPtr, uint16 Length);

/**
 * @brief            Invokes the "SetMode" functions of all underlying memory abstraction modules.
 * @details          
 * @param[in]        MemIf_ModeType 
 * @return           void
 * @retval           <return_value> {return_value description}
 * @note             service_id:       0x01 \n
 *                   is_reentrant:     false \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
void MemIf_SetMode (MemIf_ModeType Mode);

/**
 * @brief            Invokes the "Write" function of the underlying memory abstraction module selected by the parameter DeviceIndex.
 * @details          
 * @param[in]        uint8 
 * @param[in]        uint16 
 * @param[in]        uint8 
 * @return           Std_ReturnType
 * @retval           <return_value> {return_value description}
 * @note             service_id:       0x03 \n
 *                   is_reentrant:     false \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
Std_ReturnType MemIf_Write (uint8 DeviceIndex, uint16 BlockNumber, const uint8 * DataBufferPtr);

#if (((MEMIF_VERSION_INFO_API == STD_ON) && (MEMIF_DEV_ERROR_DETECT == STD_ON)))
/**
 * @brief            Returns the version information of this module.
 * @details          
 *
 * @param[in]        none
 * @param[out]       versioninfo Pointer to where to store version information of this module
 *
 * @return           none
 */
#define MemIf_GetVersionInfo(versioninfo)                                       \
    {                                                                          \
        /* Check for DET: MEMIF_E_PARAM_POINTER */                              \
        if ((versioninfo) == NULL_PTR)                                         \
        {                                                                      \
            /* Report MEMIF_E_PARAM_POINTER DET if service called with          \
               NULL_PTR                                                        \
            */                                                                 \
            Det_ReportError(                                                   \
                (uint16)MEMIF_MODULE_ID,                                        \
                MEMIF_INSTANCE_ID,                                              \
                MEMIF_SID_GET_VERSION_INFO,                                       \
                MEMIF_E_PARAM_POINTER);                                         \
        }                                                                      \
        else                                                                   \
        {                                                                      \
            /* Vendor ID information */                                        \
            ((Std_VersionInfoType *)(versioninfo))->vendorID = MEMIF_VENDOR_ID; \
            /* MemIf module ID information */                                   \
            ((Std_VersionInfoType *)(versioninfo))->moduleID = MEMIF_MODULE_ID; \
            /* MemIf module Software major version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_major_version =         \
                (uint8)MEMIF_SW_MAJOR_VERSION;                                  \
            /* MemIf module Software minor version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_minor_version =         \
                (uint8)MEMIF_SW_MINOR_VERSION;                                  \
            /* MemIf module Software patch version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_patch_version =         \
                (uint8)MEMIF_SW_PATCH_VERSION;                                  \
        }                                                                      \
    }
#elif (((MEMIF_VERSION_INFO_API == STD_ON) && (MEMIF_DEV_ERROR_DETECT == STD_OFF)))
#define MemIf_GetVersionInfo(versioninfo)                                   \
    {                                                                      \
        /* Vendor ID information */                                        \
        ((Std_VersionInfoType *)(versioninfo))->vendorID = MEMIF_VENDOR_ID; \
        /* MemIf module ID information */                                   \
        ((Std_VersionInfoType *)(versioninfo))->moduleID = MEMIF_MODULE_ID; \
        /* MemIf module Software major version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_major_version =         \
            (uint8)MEMIF_SW_MAJOR_VERSION;                                  \
        /* MemIf module Software minor version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_minor_version =         \
            (uint8)MEMIF_SW_MINOR_VERSION;                                  \
        /* MemIf module Software patch version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_patch_version =         \
            (uint8)MEMIF_SW_PATCH_VERSION;                                  \
    }
#endif   /* MEMIF_VERSION_INFO_API == STD_ON && MEMIF_DEV_ERROR_DETECT == STD_ON */



#ifdef __cplusplus
}
#endif

#endif /* MEMIF_H */

/** @} */

