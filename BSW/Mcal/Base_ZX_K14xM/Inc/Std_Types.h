/**************************************************************************************************/
/**
 * @file      : Std_Types.h
 * @brief     : AUTOSAR standard types definition
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H

/** @addtogroup  Base_Module
 *  @{
 */

/** @defgroup Std_Types
 *  @brief AUTOSAR standard types definition
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Platform_Types.h"
#include "Compiler.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define STD_AR_RELEASE_MAJOR_VERSION    4U
#define STD_AR_RELEASE_MINOR_VERSION    6U
#define STD_AR_RELEASE_REVISION_VERSION 0U
#define STD_SW_MAJOR_VERSION            1U
#define STD_SW_MINOR_VERSION            2U
#define STD_SW_PATCH_VERSION            2U

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Platform_Types.h are the same AUTOSAR version */
    #if ((STD_AR_RELEASE_MAJOR_VERSION != PLATFORM_TYPES_AR_RELEASE_MAJOR_VERSION) ||                    \
         (STD_AR_RELEASE_MINOR_VERSION != PLATFORM_TYPES_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of Std_Types.h and Platform_Types.h are different"
    #endif

    /* Check if current file and Compiler.h files are the same AUTOSAR version */
    #if ((STD_AR_RELEASE_MAJOR_VERSION != COMPILER_AR_RELEASE_MAJOR_VERSION) ||                    \
         (STD_AR_RELEASE_MINOR_VERSION != COMPILER_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of Std_Types.h and Compiler.h are different"
    #endif
#endif

#ifndef STATUSTYPEDEFINED
    #define STATUSTYPEDEFINED
    #define E_OK 0x00U

typedef unsigned char StatusType; /* OSEK compliance */
#endif

#define E_NOT_OK 0x01U

#define STD_HIGH 0x01U /* Physical state 5V or 3.3V */
#define STD_LOW  0x00U /* Physical state 0V */

#define STD_ACTIVE 0x01U /* Logical state active */
#define STD_IDLE   0x00U /* Logical state idle */

#define STD_ON  0x01U /* Standard ON */
#define STD_OFF 0x00U /* Standard OFF */

#define STD_TRANSFORMER_UNSPECIFIED 0x00U /* Transformer of a unspecified transformer class */
#define STD_TRANSFORMER_SERIALIZER  0x01U /*  Transformer of a serializer class  */
#define STD_TRANSFORMER_SAFETY      0x02U /* Transformer of a safety class */
#define STD_TRANSFORMER_SECURITY    0x03U /* Transformer of a security class */
/* Transformer of a custom class not standardized by AUTOSAR */
#define STD_TRANSFORMER_CUSTOM 0xFFU

#define E_SAFETY_INVALID_REP 0x01U /* Repeat the last used sequence number */
#define E_SAFETY_INVALID_SEQ 0x02U /* Use a wrong sequence number */
#define E_SAFETY_INVALID_CRC 0x03U /* Generate a deliberately wrong CRC */

#define STD_MESSAGETYPE_REQUEST  0x00U /* Message type for a request message */
#define STD_MESSAGETYPE_RESPONSE 0x01U /* Message type for a response message */

#define STD_MESSAGERESULT_OK    0x00U /* Message result OK */
#define STD_MESSAGERESULT_ERROR 0x01U /* Message result for an ERROR response */

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 *  @brief This type can be used as standard API return type which is shared between the RTE and the
 *         BSW modules.
 */
typedef uint8 Std_ReturnType;

/**
 *  @brief Transformer class definition
 */
typedef uint8 Std_TransformerClass;

/**
 *  @brief Transformer forward code definition
 */
typedef uint8 Std_TransformerForwardCode;

/**
 *  @brief This type is used to encode the different type of messages. Currently this encoding is
 *         limited to the distinction between requests and responses in C/S communication
 */
typedef uint8 Std_MessageTypeType;

/**
 *  @brief This type is used to encode different types of results for response messages. Currently
 *         this encoding is limited to the distinction between OK and ERROR responses.
 */
typedef uint8 Std_MessageResultType;

/**
 * @brief This type shall be used to request the version of a BSW module using the
 *       <ModuleName>_GetVersionInfo() function.
 */
typedef struct
{
    uint16 vendorID;         /*!<  vendor ID */
    uint16 moduleID;         /*!<  BSW module ID */
    uint8  sw_major_version; /*!<  BSW module software major version */
    uint8  sw_minor_version; /*!<  BSW module software minor version */
    uint8  sw_patch_version; /*!<  BSW module software patch version */
} Std_VersionInfoType;

/**
 * @brief This type represents a transformer error in the context of a certain transformer chain.
 */
typedef struct
{
    uint8                errorCode;        /*!< error code */
    Std_TransformerClass transformerClass; /*!< Transformer class */
} Std_TransformerError;

/**
 * @brief This type represents a forwarded transformer status in the context of a certain
 *        transformer chain.
 */
typedef struct
{
    Std_TransformerForwardCode errorCode;        /*!< error code */
    Std_TransformerClass       transformerClass; /*!< Transformer class */
} Std_TransformerForward;

/**
 * @brief Type for the function pointer to extract the relevant protocol header fields of the
 *        message and the type of the message result of a transformer. - At the time being, this is
 *        limited to the types used for C/S communication (i.e., REQUEST and RESPONSE and OK and
 *        ERROR).
 */
typedef Std_ReturnType (*Std_ExtractProtocolHeaderFieldsType)(const uint8           *buffer,
                                                              uint32                 bufferLength,
                                                              Std_MessageTypeType   *messageType,
                                                              Std_MessageResultType *messageResult);

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

/** @} end of group Std_Types */
/** @} end of group Base_Module */

#endif /* STD_TYPES_H */
