/**
 * @file    Lin_GeneralTypes.h
 * @version V2.3.0
 *
 * @brief   AUTOSAR Lin_GeneralTypes module interface
 * @details API implementation for LIN_GENERALTYPES driver
 *
 * @addtogroup LIN_GENERALTYPES_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Lin_GeneralTypes
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

#ifndef LIN_GENERALTYPES_H
#define LIN_GENERALTYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section Lin_GeneralTypes_PBCfg_C_REF_1
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers.
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 *
 * @section Lin_GeneralTypes_PBCfg_C_REF_2
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers.
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 */


/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include "Std_Types.h"
#include "ComStack_Types.h"
#include "Lin_Cfg.h"
/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LIN_GENERALTYPES_VENDOR_ID                      (180)
#define LIN_GENERALTYPES_AR_RELEASE_MAJOR_VERSION       (4)
#define LIN_GENERALTYPES_AR_RELEASE_MINOR_VERSION       (4)
#define LIN_GENERALTYPES_AR_RELEASE_REVISION_VERSION    (0)
#define LIN_GENERALTYPES_SW_MAJOR_VERSION               (2)
#define LIN_GENERALTYPES_SW_MINOR_VERSION               (3)
#define LIN_GENERALTYPES_SW_PATCH_VERSION               (0)

/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
#define LIN_UNUSED_PARAM(parma) ((void)parma)

#define LIN_UNINIT                             (0x00U)
#define LIN_INIT                               (0x01U)

/*==================================================================================================
 *                                         EXTERNAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
 *                                             ENUMS
==================================================================================================*/
/**
 * @brief
 */
typedef enum {
    LINTRCV_WUMODE_ENABLE                    = 0, /**<    */
    LINTRCV_WUMODE_DISABLE                   = 1, /**<    */
    LINTRCV_WUMODE_CLEAR                     = 2, /**<    */
} LinTrcv_TrcvWakeupModeType;


/**
 * @brief
 */
typedef enum {
    LINTRCV_WU_ERROR                         = 0, /**<    */
    LINTRCV_WU_NOT_SUPPORTED                 = 1, /**<    */
    LINTRCV_WU_BY_BUS                        = 2, /**<    */
    LINTRCV_WU_BY_PIN                        = 3, /**<    */
    LINTRCV_WU_INTERNALLY                    = 4, /**<    */
    LINTRCV_WU_RESET                         = 5, /**<    */
    LINTRCV_WU_POWER_ON                      = 6, /**<    */
} LinTrcv_TrcvWakeupReasonType;

/**
 * @brief This type represents the slave error types that are detected during header reception
          and response transmission / reception.
 */
typedef enum {
    LIN_ERR_NO_ERROR                         = 0, /**<  No error  */
    LIN_ERR_HEADER                           = 1, /**<  Error in header  */
    LIN_ERR_RESP_STOPBIT                     = 2, /**<  Framing error in response  */
    LIN_ERR_RESP_CHKSUM                      = 3, /**<  Checksum error  */
    LIN_ERR_RESP_DATABIT                     = 4, /**<  Monitoring error of transmitted data bit in response  */
    LIN_ERR_NO_RESP                          = 5, /**<  No response  */
    LIN_ERR_INC_RESP                         = 6, /**<  Incomplete response  */
} Lin_SlaveErrorType;

/**
 * @brief
 */
typedef enum {
    LIN_NOT_OK                               = 0, /**< @brief Development or production error occurred. */
    LIN_TX_OK                                = 1, /**< @brief Successful transmission. */
    LIN_TX_BUSY                              = 2, /**< @brief Ongoing transmission (Header or Response). */
    LIN_TX_HEADER_ERROR                      = 3, /**< @brief Error happens on header transmission
                                                        - Mismatch between sent and read back data
                                                        - Identifier parity error
                                                        - Physical bus error. */
    LIN_TX_ERROR                             = 4, /**< @brief Error happens on transmission
                                                        - Mismatch between sent and read back data
                                                        - Physical bus error. */
    LIN_RX_OK                                = 5, /**< @brief Reception of correct response. */
    LIN_RX_BUSY                              = 6, /**< @brief Ongoing reception  */
    LIN_RX_ERROR                             = 7, /**< @brief Error happens on reception
                                                        - Framing error
                                                        - Overrun error
                                                        - Checksum error
                                                        - Short response. */
    LIN_RX_NO_RESPONSE                       = 8, /**< @brief No response byte has been received so far */
    LIN_OPERATIONAL                          = 9, /**< @brief Normal operation
                                                        - the related LIN channel is ready to transmit next header
                                                        - No data from previous frame available. */
    LIN_CH_SLEEP                             = 10, /**< @brief Sleep mode operation   */
} Lin_StatusType;

/**
 * @brief       Data length of a LIN Frame.
 * @details     This type is used to specify the number of SDU data bytes to copy.
 * @implements  Lin_FrameDlType_typedef
 */
typedef uint8 Lin_FrameDlType;

/**
 * @brief       The LIN identifier (0..0x3F) with its parity bits.
 * @details     Represents all valid protected Identifier used by Lin_SendHeader().
 * @implements  Lin_FramePidType_typedef
 */
typedef uint8 Lin_FramePidType;

typedef enum {
    LIN_ENHANCED_CS                          = 0, /**< Enhanced checksum model */
    LIN_CLASSIC_CS                           = 1, /**< Classic checksum model */
} Lin_FrameCsModelType;

typedef enum {
    LIN_FRAMERESPONSE_TX,     /**< @brief Response is generated from this node.*/
    LIN_FRAMERESPONSE_RX,     /**< @brief Response is generated from another node and is relevant for this node.*/
    LIN_FRAMERESPONSE_IGNORE  /**< @brief Response is generated from another node and is irrelevant for this node.*/
} Lin_FrameResponseType;

/**
 * @brief       The LIN identifier (0..0x3F) with its parity bits.
 * @details     This Type is used to provide PID, checksum model, data length and SDU
 *              pointer from the LIN Interface to the LIN driver.
 * @implements  Lin_PduType_struct
 */
typedef struct
{
    Lin_FramePidType      Pid;     /*!< LIN frame identifier.*/
    Lin_FrameCsModelType  Cs;      /*!< Checksum model type.*/
    Lin_FrameResponseType Drc;     /*!< Response type.*/
    Lin_FrameDlType       Dl;      /*!< Data length.*/
    uint8*                SduPtr;  /*!< Pointer to Sdu.*/
} Lin_PduType;

#if (((LIN_VERSION_INFO_API == STD_ON) && (LIN_DEV_ERROR_DETECT == STD_ON)))
/**
 * @brief            Returns the version information of this module.
 *
 * @param[in]        none
 * @param[out]       versioninfo Pointer to where to store version information of this module
 *
 * @return           none
 */
#define Lin_GeneralTypes_GetVersionInfo(versioninfo)                                       \
    {                                                                          \
        /* Check for DET: LIN_GENERALTYPES_E_PARAM_POINTER */                              \
        if ((versioninfo) == NULL_PTR)                                         \
        {                                                                      \
            /* Report LIN_GENERALTYPES_E_PARAM_POINTER DET if service called with          \
               NULL_PTR                                                        \
            */                                                                 \
            Det_ReportError(                                                   \
                (uint16)LIN_GENERALTYPES_MODULE_ID,                                        \
                LIN_GENERALTYPES_INSTANCE_ID,                                              \
                LIN_GENERALTYPES_GET_VERSION_INFO_SID,                                       \
                LIN_GENERALTYPES_E_PARAM_POINTER);                                         \
        }                                                                      \
        else                                                                   \
        {                                                                      \
            /* Vendor ID information */                                        \
            ((Std_VersionInfoType *)(versioninfo))->vendorID = LIN_GENERALTYPES_VENDOR_ID; \
            /* Lin_GeneralTypes module ID information */                                   \
            ((Std_VersionInfoType *)(versioninfo))->moduleID = LIN_GENERALTYPES_MODULE_ID; \
            /* Lin_GeneralTypes module Software major version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_major_version =         \
                (uint8)LIN_GENERALTYPES_SW_MAJOR_VERSION;                                  \
            /* Lin_GeneralTypes module Software minor version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_minor_version =         \
                (uint8)LIN_GENERALTYPES_SW_MINOR_VERSION;                                  \
            /* Lin_GeneralTypes module Software patch version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_patch_version =         \
                (uint8)LIN_GENERALTYPES_SW_PATCH_VERSION;                                  \
        }                                                                      \
    }
#elif (((LIN_VERSION_INFO_API == STD_ON) && (LIN_DEV_ERROR_DETECT == STD_OFF)))
#define Lin_GeneralTypes_GetVersionInfo(versioninfo)                                   \
    {                                                                      \
        /* Vendor ID information */                                        \
        ((Std_VersionInfoType *)(versioninfo))->vendorID = LIN_GENERALTYPES_VENDOR_ID; \
        /* Lin_GeneralTypes module ID information */                                   \
        ((Std_VersionInfoType *)(versioninfo))->moduleID = LIN_GENERALTYPES_MODULE_ID; \
        /* Lin_GeneralTypes module Software major version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_major_version =         \
            (uint8)LIN_GENERALTYPES_SW_MAJOR_VERSION;                                  \
        /* Lin_GeneralTypes module Software minor version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_minor_version =         \
            (uint8)LIN_GENERALTYPES_SW_MINOR_VERSION;                                  \
        /* Lin_GeneralTypes module Software patch version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_patch_version =         \
            (uint8)LIN_GENERALTYPES_SW_PATCH_VERSION;                                  \
    }
#endif   /* LIN_VERSION_INFO_API == STD_ON && LIN_DEV_ERROR_DETECT == STD_ON */



#ifdef __cplusplus
}
#endif

#endif /* LIN_GENERALTYPES_H */

/** @} */

