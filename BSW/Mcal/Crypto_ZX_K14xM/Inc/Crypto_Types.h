/**************************************************************************************************/
/**
 * @file      : Crypto_Types.h
 * @brief     : Crypto AUTOSAR level type definition file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef CRYPTO_TYPES_H
#define CRYPTO_TYPES_H

/** @addtogroup Crypto_Module
 *  @{
 */

/** @addtogroup Crypto
 *  @brief Crypto AUTOSAR level
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Crypto_Cfg.h"
#include "Aes_Drv_Types.h"
#include "Trng_Drv_Types.h"
#include "Crypto_GeneralTypes.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define CRYPTO_TYPES_H_VENDOR_ID                   0x00B3U
#define CRYPTO_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define CRYPTO_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define CRYPTO_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define CRYPTO_TYPES_H_SW_MAJOR_VERSION            1U
#define CRYPTO_TYPES_H_SW_MINOR_VERSION            2U
#define CRYPTO_TYPES_H_SW_PATCH_VERSION            2U

/* Check if current file and Crypto_Cfg.h are the same vendor */
#if (CRYPTO_TYPES_H_VENDOR_ID != CRYPTO_CFG_H_VENDOR_ID)
    #error "Vendor ID of Crypto_Types.h and Crypto_Cfg.h are different"
#endif
/* Check if current file and Crypto_Cfg.h are the same Autosar version */
#if ((CRYPTO_TYPES_H_AR_RELEASE_MAJOR_VERSION != CRYPTO_CFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (CRYPTO_TYPES_H_AR_RELEASE_MINOR_VERSION != CRYPTO_CFG_H_AR_RELEASE_MINOR_VERSION) || \
     (CRYPTO_TYPES_H_AR_RELEASE_REVISION_VERSION != CRYPTO_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Crypto_Types.h and Crypto_Cfg.h are different"
#endif
/* Check if current file and Crypto_Cfg.h are the same Software version */
#if ((CRYPTO_TYPES_H_SW_MAJOR_VERSION != CRYPTO_CFG_H_SW_MAJOR_VERSION) || \
     (CRYPTO_TYPES_H_SW_MINOR_VERSION != CRYPTO_CFG_H_SW_MINOR_VERSION) || \
     (CRYPTO_TYPES_H_SW_PATCH_VERSION != CRYPTO_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Crypto_Types.h and Crypto_Cfg.h are different"
#endif

/* Check if current file and Aes_Drv_Types.h are the same vendor */
#if (CRYPTO_TYPES_H_VENDOR_ID != AES_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Crypto_Types.h and Aes_Drv_Types.h are different"
#endif
/* Check if current file and Aes_Drv_Types.h are the same Autosar version */
#if ((CRYPTO_TYPES_H_AR_RELEASE_MAJOR_VERSION != AES_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
     (CRYPTO_TYPES_H_AR_RELEASE_MINOR_VERSION != AES_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) || \
     (CRYPTO_TYPES_H_AR_RELEASE_REVISION_VERSION != AES_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Crypto_Types.h and Aes_Drv_Types.h are different"
#endif
/* Check if current file and Aes_Drv_Types.h are the same Software version */
#if ((CRYPTO_TYPES_H_SW_MAJOR_VERSION != AES_DRV_TYPES_H_SW_MAJOR_VERSION) || \
     (CRYPTO_TYPES_H_SW_MINOR_VERSION != AES_DRV_TYPES_H_SW_MINOR_VERSION) || \
     (CRYPTO_TYPES_H_SW_PATCH_VERSION != AES_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Crypto_Types.h and Aes_Drv_Types.h are different"
#endif

/* Check if current file and Trng_Drv_Types.h are the same vendor */
#if (CRYPTO_TYPES_H_VENDOR_ID != TRNG_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Crypto_Types.h and Trng_Drv_Types.h are different"
#endif
/* Check if current file and Trng_Drv_Types.h are the same Autosar version */
#if ((CRYPTO_TYPES_H_AR_RELEASE_MAJOR_VERSION != TRNG_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
     (CRYPTO_TYPES_H_AR_RELEASE_MINOR_VERSION != TRNG_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) || \
     (CRYPTO_TYPES_H_AR_RELEASE_REVISION_VERSION != TRNG_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Crypto_Types.h and Trng_Drv_Types.h are different"
#endif
/* Check if current file and Trng_Drv_Types.h are the same Software version */
#if ((CRYPTO_TYPES_H_SW_MAJOR_VERSION != TRNG_DRV_TYPES_H_SW_MAJOR_VERSION) || \
     (CRYPTO_TYPES_H_SW_MINOR_VERSION != TRNG_DRV_TYPES_H_SW_MINOR_VERSION) || \
     (CRYPTO_TYPES_H_SW_PATCH_VERSION != TRNG_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Crypto_Types.h and Trng_Drv_Types.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Crypto_GeneralTypes.h are the same Autosar version */
    #if ((CRYPTO_TYPES_H_AR_RELEASE_MAJOR_VERSION != CRYPTO_GENERALTYPES_H_AR_RELEASE_MAJOR_VERSION) || \
        (CRYPTO_TYPES_H_AR_RELEASE_MINOR_VERSION != CRYPTO_GENERALTYPES_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Crypto_Types.h and Crypto_GeneralTypes.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */
/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

#if(STD_ON == CRYPTO_DEV_ERROR_DETECT)
/**
 * @brief   CRYPTO driver initialization status
 *
 */
typedef enum
{
    CRYPTO_DRIVER_UNINIT       = 0U, /*!< Crypto driver is uninitialized */
    CRYPTO_DRIVER_INITIALIZED  = 1U  /*!< Crypto driver is initialized */
} Crypto_InitStateType;
#endif

/**
 * @brief   CRYPTO Driver Object state
 *
 */
typedef enum
{
    CRYPTO_DRIVER_OBJECT_IDLE       = 0U, /*!< Crypto Driver Object is idle */
    CRYPTO_DRIVER_OBJECT_ACTIVE     = 1U  /*!< Crypto Driver Object is active */
} Crypto_DriverObjectStateType;

/**
 * @brief   CRYPTO primitive information type
 * 
 */
typedef struct
{
    const Crypto_ServiceInfoType Service;
    const uint8 AlgoFamily;
    const uint8 AlgoMode;
    const uint8 SecondaryAlgoFamily;
} Crypto_PrimitiveType;

/**
 * @brief   CRYPTO driver object primitive type
 * 
 */
typedef struct
{
    const Crypto_PrimitiveType* const CryptoPrimitives;
    const uint32 CryptoPrimitivesNum;
} Crypto_ObjectPrimitiveType;

/**
 * @brief   CRYPTO Key format type
 * 
 */
typedef enum
{
    CRYPTO_KE_FORMAT_BIN_OCTET                  = 0x01U,
    CRYPTO_KE_FORMAT_BIN_SHEKEYS                = 0x02U,
    CRYPTO_KE_FORMAT_BIN_IDENT_PRIVATEKEY_PKCS8 = 0x03U,
    CRYPTO_KE_FORMAT_BIN_IDENT_PUBLICKEY        = 0x04U,
    CRYPTO_KE_FORMAT_BIN_RSA_PRIVATEKEY         = 0x05U,
    CRYPTO_KE_FORMAT_BIN_RSA_PUBLICKEY          = 0x06U
} Crypto_KeyElementFormatType;

/**
 * @brief   CRYPTO read access right type
 * 
 */
typedef enum
{
    CRYPTO_RA_ALLOWED       = 0x00U,
    CRYPTO_RA_ENCRYPTED     = 0x01U,
    CRYPTO_RA_INTERNAL_COPY = 0x02U,
    CRYPTO_RA_DENIED        = 0x03U
} Crypto_KeyElementReadAccessType;

/**
 * @brief   CRYPTO write access right type
 * 
 */
typedef enum
{
    CRYPTO_WA_ALLOWED       = 0x00U,
    CRYPTO_WA_ENCRYPTED     = 0x01U,
    CRYPTO_WA_INTERNAL_COPY = 0x02U,
    CRYPTO_WA_DENIED        = 0x03U
} Crypto_KeyElementWriteAccessType;

/**
 * @brief   Crypto Nvm Block processing type.
 *
 */
typedef enum
{
    CRYPTO_NV_BLOCK_DEFERRED = 0x01U,
    CRYPTO_NV_BLOCK_IMMEDIATE = 0x02U
} Crypto_NvBlockProcessingType;

/**
 * @brief   Crypto key element type definition
 *
 */
typedef struct
{
    const boolean ElementPartialAccess;
    const Crypto_KeyElementFormatType ElementFormat;
    const uint32 ElementId;
    const uint8 *const ElementInitValue;
    const boolean ElementPersist;
    const Crypto_KeyElementReadAccessType ElementReadAccess;
    const uint32 ElementMaxSize;
    const Crypto_KeyElementWriteAccessType ElementWriteAccess;
    uint32* const ElementActSize;
    uint8* const KeyElementPtr;
} Crypto_KeyElementType;

/**
 * @brief   Crypto key type definition
 *
 */
typedef struct
{
    const uint32 KeyId;
    Crypto_KeyStatusType *const KeyStatus;
    const uint32 KeyElementNum;
    const uint16 RefNvBlockId;
    const uint32 RefNvBlockSize;
    const Crypto_NvBlockProcessingType BlockProType;
    const uint32 RetryTimes;
    const Crypto_KeyElementType* const *KeyElementListPtr;
    uint8 *const PersistKeyElementsPtr;
} Crypto_KeyType;

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

/** @} end of group Crypto_Drv */

/** @} end of group Crypto_Module */

#endif /* CRYPTO_TYPES_H */
