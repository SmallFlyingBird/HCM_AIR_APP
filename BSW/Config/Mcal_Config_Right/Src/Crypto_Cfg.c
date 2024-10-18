/**************************************************************************************************/
/**
 * @file      : Crypto_Cfg.c  
 * @brief     : AUTOSAR Crypto driver source file
 *              - Platform: Z20K14xM
 *              - Autosar Version : 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (C) 2021-2022 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

#include "NvM.h"
#include "Crypto.h"

/* Published information */
#define CRYPTO_CFG_C_VENDOR_ID                   0x00B3U
#define CRYPTO_CFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define CRYPTO_CFG_C_AR_RELEASE_MINOR_VERSION    6U
#define CRYPTO_CFG_C_AR_RELEASE_REVISION_VERSION 0U
#define CRYPTO_CFG_C_SW_MAJOR_VERSION            1U
#define CRYPTO_CFG_C_SW_MINOR_VERSION            2U
#define CRYPTO_CFG_C_SW_PATCH_VERSION            1U

/* Check if current file and Crypto.h are the same vendor */
#if (CRYPTO_CFG_C_VENDOR_ID != CRYPTO_VENDOR_ID)
    #error "Vendor ID of Crypto_Cfg.c and Crypto.h are different"
#endif
/* Check if current file and Crypto.h are the same Autosar version */
#if ((CRYPTO_CFG_C_AR_RELEASE_MAJOR_VERSION != CRYPTO_AR_RELEASE_MAJOR_VERSION) || \
     (CRYPTO_CFG_C_AR_RELEASE_MINOR_VERSION != CRYPTO_AR_RELEASE_MINOR_VERSION) || \
     (CRYPTO_CFG_C_AR_RELEASE_REVISION_VERSION != CRYPTO_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Crypto_Cfg.c and Crypto.h are different"
#endif
/* Check if current file and Crypto.h are the same Software version */
#if ((CRYPTO_CFG_C_SW_MAJOR_VERSION != CRYPTO_SW_MAJOR_VERSION) || \
     (CRYPTO_CFG_C_SW_MINOR_VERSION != CRYPTO_SW_MINOR_VERSION) || \
     (CRYPTO_CFG_C_SW_PATCH_VERSION != CRYPTO_SW_PATCH_VERSION))
    #error "Software Version of Crypto_Cfg.c and Crypto.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and NvM.h are the same Autosar version */
    #if ((CRYPTO_CFG_C_AR_RELEASE_MAJOR_VERSION != NVM_AR_RELEASE_MAJOR_VERSION) || \
         (CRYPTO_CFG_C_AR_RELEASE_MINOR_VERSION != NVM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Crypto_Cfg.c and NvM.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

#define CRYPTO_START_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"
/* Crypto primitives of Crypto Driver Object CryptoDriverObject_TRNG */
static const Crypto_PrimitiveType Crypto_Primitives_CryptoDriverObject_TRNG[1U] =
{
    {
        CRYPTO_RANDOMGENERATE,
        (uint8)CRYPTO_ALGOFAM_RNG,
        (uint8)CRYPTO_ALGOMODE_NOT_SET,
        (uint8)CRYPTO_ALGOFAM_NOT_SET
    }
};
/* Crypto primitives of Crypto Driver Object CryptoDriverObject_AES */
static const Crypto_PrimitiveType Crypto_Primitives_CryptoDriverObject_AES[20U] =
{
    {
        CRYPTO_ENCRYPT,
        (uint8)CRYPTO_ALGOFAM_AES,
        (uint8)CRYPTO_ALGOMODE_ECB,
        (uint8)CRYPTO_ALGOFAM_NOT_SET
    },
    {
        CRYPTO_MACVERIFY,
        (uint8)CRYPTO_ALGOFAM_AES,
        (uint8)CRYPTO_ALGOMODE_GMAC,
        (uint8)CRYPTO_ALGOFAM_NOT_SET
    },
    {
        CRYPTO_DECRYPT,
        (uint8)CRYPTO_ALGOFAM_AES,
        (uint8)CRYPTO_ALGOMODE_CFB,
        (uint8)CRYPTO_ALGOFAM_NOT_SET
    },
    {
        CRYPTO_ENCRYPT,
        (uint8)CRYPTO_ALGOFAM_AES,
        (uint8)CRYPTO_ALGOMODE_CFB,
        (uint8)CRYPTO_ALGOFAM_NOT_SET
    },
    {
        CRYPTO_DECRYPT,
        (uint8)CRYPTO_ALGOFAM_AES,
        (uint8)CRYPTO_ALGOMODE_CTR,
        (uint8)CRYPTO_ALGOFAM_NOT_SET
    },
    {
        CRYPTO_ENCRYPT,
        (uint8)CRYPTO_ALGOFAM_AES,
        (uint8)CRYPTO_ALGOMODE_CTR,
        (uint8)CRYPTO_ALGOFAM_NOT_SET
    },
    {
        CRYPTO_DECRYPT,
        (uint8)CRYPTO_ALGOFAM_AES,
        (uint8)CRYPTO_ALGOMODE_OFB,
        (uint8)CRYPTO_ALGOFAM_NOT_SET
    },
    {
        CRYPTO_ENCRYPT,
        (uint8)CRYPTO_ALGOFAM_AES,
        (uint8)CRYPTO_ALGOMODE_OFB,
        (uint8)CRYPTO_ALGOFAM_NOT_SET
    },
    {
        CRYPTO_DECRYPT,
        (uint8)CRYPTO_ALGOFAM_AES,
        (uint8)CRYPTO_ALGOMODE_XTS,
        (uint8)CRYPTO_ALGOFAM_NOT_SET
    },
    {
        CRYPTO_ENCRYPT,
        (uint8)CRYPTO_ALGOFAM_AES,
        (uint8)CRYPTO_ALGOMODE_XTS,
        (uint8)CRYPTO_ALGOFAM_NOT_SET
    },
    {
        CRYPTO_AEADDECRYPT,
        (uint8)CRYPTO_ALGOFAM_AES,
        (uint8)CryptoConf_CryptoPrimitiveAlgorithmModeCustom_CryptoPrimitiveAlgorithmModeCustom_0,
        (uint8)CRYPTO_ALGOFAM_NOT_SET
    },
    {
        CRYPTO_DECRYPT,
        (uint8)CRYPTO_ALGOFAM_AES,
        (uint8)CRYPTO_ALGOMODE_ECB,
        (uint8)CRYPTO_ALGOFAM_NOT_SET
    },
    {
        CRYPTO_AEADENCRYPT,
        (uint8)CRYPTO_ALGOFAM_AES,
        (uint8)CryptoConf_CryptoPrimitiveAlgorithmModeCustom_CryptoPrimitiveAlgorithmModeCustom_0,
        (uint8)CRYPTO_ALGOFAM_NOT_SET
    },
    {
        CRYPTO_ENCRYPT,
        (uint8)CRYPTO_ALGOFAM_AES,
        (uint8)CRYPTO_ALGOMODE_CBC,
        (uint8)CRYPTO_ALGOFAM_NOT_SET
    },
    {
        CRYPTO_DECRYPT,
        (uint8)CRYPTO_ALGOFAM_AES,
        (uint8)CRYPTO_ALGOMODE_CBC,
        (uint8)CRYPTO_ALGOFAM_NOT_SET
    },
    {
        CRYPTO_MACGENERATE,
        (uint8)CRYPTO_ALGOFAM_AES,
        (uint8)CRYPTO_ALGOMODE_CMAC,
        (uint8)CRYPTO_ALGOFAM_NOT_SET
    },
    {
        CRYPTO_MACVERIFY,
        (uint8)CRYPTO_ALGOFAM_AES,
        (uint8)CRYPTO_ALGOMODE_CMAC,
        (uint8)CRYPTO_ALGOFAM_NOT_SET
    },
    {
        CRYPTO_AEADENCRYPT,
        (uint8)CRYPTO_ALGOFAM_AES,
        (uint8)CRYPTO_ALGOMODE_GCM,
        (uint8)CRYPTO_ALGOFAM_NOT_SET
    },
    {
        CRYPTO_MACGENERATE,
        (uint8)CRYPTO_ALGOFAM_AES,
        (uint8)CRYPTO_ALGOMODE_GMAC,
        (uint8)CRYPTO_ALGOFAM_NOT_SET
    },
    {
        CRYPTO_AEADDECRYPT,
        (uint8)CRYPTO_ALGOFAM_AES,
        (uint8)CRYPTO_ALGOMODE_GCM,
        (uint8)CRYPTO_ALGOFAM_NOT_SET
    }
};
/* Crypto primitives of Crypto Driver Object CryptoDriverObject_KEY */
static const Crypto_PrimitiveType Crypto_Primitives_CryptoDriverObject_KEY[1U] =
{
    {
        CRYPTO_KEYSETVALID,
        (uint8)CRYPTO_ALGOFAM_NOT_SET,
        (uint8)CRYPTO_ALGOMODE_NOT_SET,
        (uint8)CRYPTO_ALGOFAM_NOT_SET
    }
};
#define CRYPTO_STOP_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"
/* Crypto Driver Objects primitive list */
const Crypto_ObjectPrimitiveType Crypto_ObjectPrimitiveList[CRYPTO_NUMBER_OF_DRIVER_OBJECTS] =
{
    {
        Crypto_Primitives_CryptoDriverObject_TRNG,
        1U
    },
    {
        Crypto_Primitives_CryptoDriverObject_AES,
        20U
    },
    {
        Crypto_Primitives_CryptoDriverObject_KEY,
        1U
    }
};
#define CRYPTO_STOP_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_MemMap.h"
/* Crypto Driver Objects queued jobs array */
static Crypto_QueueElementType Crypto_QueuedJobs_CryptoDriverObject_TRNG[6U];
/* Crypto Driver Objects queued jobs array */
static Crypto_QueueElementType Crypto_QueuedJobs_CryptoDriverObject_AES[6U];
/* Crypto Driver Objects queued jobs array */
static Crypto_QueueElementType Crypto_QueuedJobs_CryptoDriverObject_KEY[6U];
#define CRYPTO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"
/* Crypto Driver Objects queue information list */
const Crypto_QueueInfoType Crypto_QueueInfoList[CRYPTO_NUMBER_OF_DRIVER_OBJECTS] =
{
    {
        Crypto_QueuedJobs_CryptoDriverObject_TRNG,
        6U
    },
    {
        Crypto_QueuedJobs_CryptoDriverObject_AES,
        6U
    },
    {
        Crypto_QueuedJobs_CryptoDriverObject_KEY,
        6U
    }
};
#define CRYPTO_STOP_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_MemMap.h"
/* Crypto Driver Object queue list */
Crypto_ObjectQueueType Crypto_ObjectQueueList[CRYPTO_NUMBER_OF_DRIVER_OBJECTS];
#define CRYPTO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_VAR_INIT_32
#include "Crypto_MemMap.h"
static uint32 Crypto_KeyElementActSize[11U] = 
{
    0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U
};
#define CRYPTO_STOP_SEC_VAR_INIT_32
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_VAR_CLEARED_8
#include "Crypto_MemMap.h"
#define CRYPTO_STOP_SEC_VAR_CLEARED_8
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CONFIG_DATA_8
#include "Crypto_MemMap.h"
#define CRYPTO_STOP_SEC_CONFIG_DATA_8
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_VAR_CLEARED_8
#include "Crypto_MemMap.h"
static uint8 Crypto_KeyElement_EncryptKeyPtr[32U];
static uint8 Crypto_KeyElement_EncryptIvPtr[16U];
static uint8 Crypto_KeyElement_DecryptKeyPtr[16U];
static uint8 Crypto_KeyElement_DecryptIvPtr[16U];
static uint8 Crypto_KeyElement_AEADEncryptKeyPtr[16U];
static uint8 Crypto_KeyElement_AEADEncryptIvPtr[12U];
static uint8 Crypto_KeyElement_AEADDecryptKeyPtr[16U];
static uint8 Crypto_KeyElement_AEADDecryptIvPtr[12U];
static uint8 Crypto_KeyElement_CMACKeyPtr[16U];
static uint8 Crypto_KeyElement_GMACKeyPtr[16U];
static uint8 Crypto_KeyElement_GMACIvPtr[12U];
#define CRYPTO_STOP_SEC_VAR_CLEARED_8
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Crypto_MemMap.h"
static const Crypto_KeyElementType Crypto_KeyElement_EncryptKey =
{
    (boolean)TRUE,
    CRYPTO_KE_FORMAT_BIN_OCTET,
    1U,
    NULL_PTR,
    (boolean)FALSE,
    CRYPTO_RA_ALLOWED,
    32U,
    CRYPTO_WA_ALLOWED,
    &Crypto_KeyElementActSize[0U],
    Crypto_KeyElement_EncryptKeyPtr
};
static const Crypto_KeyElementType Crypto_KeyElement_EncryptIv =
{
    (boolean)TRUE,
    CRYPTO_KE_FORMAT_BIN_OCTET,
    5U,
    NULL_PTR,
    (boolean)FALSE,
    CRYPTO_RA_ALLOWED,
    16U,
    CRYPTO_WA_ALLOWED,
    &Crypto_KeyElementActSize[1U],
    Crypto_KeyElement_EncryptIvPtr
};
static const Crypto_KeyElementType Crypto_KeyElement_DecryptKey =
{
    (boolean)TRUE,
    CRYPTO_KE_FORMAT_BIN_OCTET,
    1U,
    NULL_PTR,
    (boolean)FALSE,
    CRYPTO_RA_ALLOWED,
    16U,
    CRYPTO_WA_ALLOWED,
    &Crypto_KeyElementActSize[2U],
    Crypto_KeyElement_DecryptKeyPtr
};
static const Crypto_KeyElementType Crypto_KeyElement_DecryptIv =
{
    (boolean)TRUE,
    CRYPTO_KE_FORMAT_BIN_OCTET,
    5U,
    NULL_PTR,
    (boolean)FALSE,
    CRYPTO_RA_ALLOWED,
    16U,
    CRYPTO_WA_ALLOWED,
    &Crypto_KeyElementActSize[3U],
    Crypto_KeyElement_DecryptIvPtr
};
static const Crypto_KeyElementType Crypto_KeyElement_AEADEncryptKey =
{
    (boolean)TRUE,
    CRYPTO_KE_FORMAT_BIN_OCTET,
    1U,
    NULL_PTR,
    (boolean)FALSE,
    CRYPTO_RA_ALLOWED,
    16U,
    CRYPTO_WA_ALLOWED,
    &Crypto_KeyElementActSize[4U],
    Crypto_KeyElement_AEADEncryptKeyPtr
};
static const Crypto_KeyElementType Crypto_KeyElement_AEADEncryptIv =
{
    (boolean)TRUE,
    CRYPTO_KE_FORMAT_BIN_OCTET,
    5U,
    NULL_PTR,
    (boolean)FALSE,
    CRYPTO_RA_ALLOWED,
    12U,
    CRYPTO_WA_ALLOWED,
    &Crypto_KeyElementActSize[5U],
    Crypto_KeyElement_AEADEncryptIvPtr
};
static const Crypto_KeyElementType Crypto_KeyElement_AEADDecryptKey =
{
    (boolean)TRUE,
    CRYPTO_KE_FORMAT_BIN_OCTET,
    1U,
    NULL_PTR,
    (boolean)FALSE,
    CRYPTO_RA_ALLOWED,
    16U,
    CRYPTO_WA_ALLOWED,
    &Crypto_KeyElementActSize[6U],
    Crypto_KeyElement_AEADDecryptKeyPtr
};
static const Crypto_KeyElementType Crypto_KeyElement_AEADDecryptIv =
{
    (boolean)TRUE,
    CRYPTO_KE_FORMAT_BIN_OCTET,
    5U,
    NULL_PTR,
    (boolean)FALSE,
    CRYPTO_RA_ALLOWED,
    12U,
    CRYPTO_WA_ALLOWED,
    &Crypto_KeyElementActSize[7U],
    Crypto_KeyElement_AEADDecryptIvPtr
};
static const Crypto_KeyElementType Crypto_KeyElement_CMACKey =
{
    (boolean)TRUE,
    CRYPTO_KE_FORMAT_BIN_OCTET,
    1U,
    NULL_PTR,
    (boolean)FALSE,
    CRYPTO_RA_ALLOWED,
    16U,
    CRYPTO_WA_ALLOWED,
    &Crypto_KeyElementActSize[8U],
    Crypto_KeyElement_CMACKeyPtr
};
static const Crypto_KeyElementType Crypto_KeyElement_GMACKey =
{
    (boolean)TRUE,
    CRYPTO_KE_FORMAT_BIN_OCTET,
    1U,
    NULL_PTR,
    (boolean)FALSE,
    CRYPTO_RA_ALLOWED,
    16U,
    CRYPTO_WA_ALLOWED,
    &Crypto_KeyElementActSize[9U],
    Crypto_KeyElement_GMACKeyPtr
};
static const Crypto_KeyElementType Crypto_KeyElement_GMACIv =
{
    (boolean)TRUE,
    CRYPTO_KE_FORMAT_BIN_OCTET,
    5U,
    NULL_PTR,
    (boolean)FALSE,
    CRYPTO_RA_ALLOWED,
    12U,
    CRYPTO_WA_ALLOWED,
    &Crypto_KeyElementActSize[10U],
    Crypto_KeyElement_GMACIvPtr
};
#define CRYPTO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CONFIG_DATA_PTR
#include "Crypto_MemMap.h"
static const Crypto_KeyElementType* const Crypto_EncryptKeyElementListPtr[2U] =
{
    &Crypto_KeyElement_EncryptKey,
    &Crypto_KeyElement_EncryptIv,
};
static const Crypto_KeyElementType* const Crypto_DecryptKeyElementListPtr[2U] =
{
    &Crypto_KeyElement_DecryptKey,
    &Crypto_KeyElement_DecryptIv,
};
static const Crypto_KeyElementType* const Crypto_AEADEncryptKeyElementListPtr[2U] =
{
    &Crypto_KeyElement_AEADEncryptKey,
    &Crypto_KeyElement_AEADEncryptIv,
};
static const Crypto_KeyElementType* const Crypto_AEADDecryptKeyElementListPtr[2U] =
{
    &Crypto_KeyElement_AEADDecryptKey,
    &Crypto_KeyElement_AEADDecryptIv,
};
static const Crypto_KeyElementType* const Crypto_CMACKeyElementListPtr[1U] =
{
    &Crypto_KeyElement_CMACKey,
};
static const Crypto_KeyElementType* const Crypto_GMACKeyElementListPtr[2U] =
{
    &Crypto_KeyElement_GMACKey,
    &Crypto_KeyElement_GMACIv,
};
#define CRYPTO_STOP_SEC_CONFIG_DATA_PTR
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_MemMap.h"
static Crypto_KeyStatusType Crypto_KeyStatus[6U];
#define CRYPTO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"
const Crypto_KeyType Crypto_KeyList[6U] =
{
    {
        0U,
        &Crypto_KeyStatus[0U],
        2U,
        0U,
        0U,
        CRYPTO_NV_BLOCK_DEFERRED,
        0U,
        Crypto_EncryptKeyElementListPtr,
        NULL_PTR
    },
    {
        1U,
        &Crypto_KeyStatus[1U],
        2U,
        0U,
        0U,
        CRYPTO_NV_BLOCK_DEFERRED,
        0U,
        Crypto_DecryptKeyElementListPtr,
        NULL_PTR
    },
    {
        2U,
        &Crypto_KeyStatus[2U],
        2U,
        0U,
        0U,
        CRYPTO_NV_BLOCK_DEFERRED,
        0U,
        Crypto_AEADEncryptKeyElementListPtr,
        NULL_PTR
    },
    {
        3U,
        &Crypto_KeyStatus[3U],
        2U,
        0U,
        0U,
        CRYPTO_NV_BLOCK_DEFERRED,
        0U,
        Crypto_AEADDecryptKeyElementListPtr,
        NULL_PTR
    },
    {
        4U,
        &Crypto_KeyStatus[4U],
        1U,
        0U,
        0U,
        CRYPTO_NV_BLOCK_DEFERRED,
        0U,
        Crypto_CMACKeyElementListPtr,
        NULL_PTR
    },
    {
        5U,
        &Crypto_KeyStatus[5U],
        2U,
        0U,
        0U,
        CRYPTO_NV_BLOCK_DEFERRED,
        0U,
        Crypto_GMACKeyElementListPtr,
        NULL_PTR
    }
};
#define CRYPTO_STOP_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#ifdef __cplusplus
}
#endif

