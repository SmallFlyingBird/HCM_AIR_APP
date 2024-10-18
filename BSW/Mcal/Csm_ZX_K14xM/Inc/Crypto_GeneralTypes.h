/**************************************************************************************************/
/**
 * @file      : Crypto_GeneralTypes.h
 * @brief     : Crypto service manager type definition file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef CRYPTO_GENERALTYPES_H
#define CRYPTO_GENERALTYPES_H

/** @addtogroup Crypto_Module
 *  @{
 */

/** @addtogroup Crypto_GeneralTypes
 *  @brief Crypto general types
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "Rte_Csm_Type.h"
 
/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define CRYPTO_GENERALTYPES_H_VENDOR_ID                   0x00B3U
#define CRYPTO_GENERALTYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define CRYPTO_GENERALTYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define CRYPTO_GENERALTYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define CRYPTO_GENERALTYPES_H_SW_MAJOR_VERSION            1U
#define CRYPTO_GENERALTYPES_H_SW_MINOR_VERSION            2U
#define CRYPTO_GENERALTYPES_H_SW_PATCH_VERSION            1U

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
	/* Check if current file and Std_Types.h are the same Autosar version */
    #if((CRYPTO_GENERALTYPES_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
        (CRYPTO_GENERALTYPES_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
		#error "AutoSar Version of Crypto_GeneralTypes.h and Std_Types.h are different"
    #endif
	/* Check if current file and Rte_Csm_Type.h are the same Autosar version */
    #if((CRYPTO_GENERALTYPES_H_AR_RELEASE_MAJOR_VERSION != RTE_CSM_TYPE_H_AR_RELEASE_MAJOR_VERSION) || \
        (CRYPTO_GENERALTYPES_H_AR_RELEASE_MINOR_VERSION != RTE_CSM_TYPE_H_AR_RELEASE_MINOR_VERSION))
		#error "AutoSar Version of Crypto_GeneralTypes.h and Rte_Csm_Type.h are different"
    #endif
#endif
/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */
/**
 * @brief  Enumeration of the algorithm family.
 */
typedef enum 
{
    CRYPTO_ALGOFAM_NOT_SET                      = 0x00U,
    CRYPTO_ALGOFAM_SHA1                         = 0x01U,
    CRYPTO_ALGOFAM_SHA2_224                     = 0x02U,
    CRYPTO_ALGOFAM_SHA2_256                     = 0x03U,
    CRYPTO_ALGOFAM_SHA2_384                     = 0x04U,
    CRYPTO_ALGOFAM_SHA2_512                     = 0x05U,
    CRYPTO_ALGOFAM_SHA2_512_224                 = 0x06U,
    CRYPTO_ALGOFAM_SHA2_512_256                 = 0x07U,
    CRYPTO_ALGOFAM_SHA3_224                     = 0x08U,
    CRYPTO_ALGOFAM_SHA3_256                     = 0x09U,
    CRYPTO_ALGOFAM_SHA3_384                     = 0x0AU,
    CRYPTO_ALGOFAM_SHA3_512                     = 0x0BU,
    CRYPTO_ALGOFAM_SHAKE128                     = 0x0CU,
    CRYPTO_ALGOFAM_SHAKE256                     = 0x0DU,
    CRYPTO_ALGOFAM_RIPEMD160                    = 0x0EU,
    CRYPTO_ALGOFAM_BLAKE_1_256                  = 0x0FU,
    CRYPTO_ALGOFAM_BLAKE_1_512                  = 0x10U,
    CRYPTO_ALGOFAM_BLAKE_2s_256                 = 0x11U,
    CRYPTO_ALGOFAM_BLAKE_2s_512                 = 0x12U,
    CRYPTO_ALGOFAM_3DES                         = 0x13U,
    CRYPTO_ALGOFAM_AES                          = 0x14U,
    CRYPTO_ALGOFAM_CHACHA                       = 0x15U,
    CRYPTO_ALGOFAM_RSA                          = 0x16U,
    CRYPTO_ALGOFAM_ED25519                      = 0x17U,
    CRYPTO_ALGOFAM_BRAINPOOL                    = 0x18U,
    CRYPTO_ALGOFAM_ECCNIST                      = 0x19U,
    CRYPTO_ALGOFAM_RNG                          = 0x1BU,
    CRYPTO_ALGOFAM_SIPHASH                      = 0x1CU,
    CRYPTO_ALGOFAM_ECCANSI                      = 0x1EU,
    CRYPTO_ALGOFAM_ECCSEC                       = 0x1FU,
    CRYPTO_ALGOFAM_DRBG                         = 0x20U,
    CRYPTO_ALGOFAM_FIPS186                      = 0x21U,
    CRYPTO_ALGOFAM_PADDING_PKCS7                = 0x22U,
    CRYPTO_ALGOFAM_PADDING_ONEWITHZEROS         = 0x23U,
    CRYPTO_ALGOFAM_PBKDF2                       = 0x24U,
    CRYPTO_ALGOFAM_KDFX963                      = 0x25U,
    CRYPTO_ALGOFAM_DH                           = 0x26U,
    CRYPTO_ALGOFAM_SM2                          = 0x27U,
    CRYPTO_ALGOFAM_EEA3                         = 0x28U,
    CRYPTO_ALGOFAM_SM3                          = 0x29U,
    CRYPTO_ALGOFAM_EIA3                         = 0x2AU,
    CRYPTO_ALGOFAM_HKDF                         = 0x2BU,
    CRYPTO_ALGOFAM_ECDSA                        = 0x2CU,
    CRYPTO_ALGOFAM_POLY1305                     = 0x2DU,
    CRYPTO_ALGOFAM_X25519                       = 0x2EU,
    CRYPTO_ALGOFAM_ECDH                         = 0x2FU,
    CRYPTO_ALGOFAM_CUSTOM                       = 0xffU
} Crypto_AlgorithmFamilyType;

/**
 * @brief  Enumeration of the algorithm mode.
 */
typedef enum
{
    CRYPTO_ALGOMODE_NOT_SET           = 0x00U, /* Algorithm key is not set */
    CRYPTO_ALGOMODE_ECB               = 0x01U, /* Blockmode: Electronic Code Book */
    CRYPTO_ALGOMODE_CBC               = 0x02U, /* Blockmode: Cipher Block Chaining */
    CRYPTO_ALGOMODE_CFB               = 0x03U, /* Blockmode: Cipher Feedback Mode */
    CRYPTO_ALGOMODE_OFB               = 0x04U, /* Blockmode: Output Feedback Mode */
    CRYPTO_ALGOMODE_CTR               = 0x05U, /* Blockmode: Counter Modex */
    CRYPTO_ALGOMODE_GCM               = 0x06U, /* Blockmode: Galois/Counter Mode */
    CRYPTO_ALGOMODE_XTS               = 0x07U, /* XOR-encryption-based tweaked-codebook mode with 
                                                  ciphertext stealing */
    CRYPTO_ALGOMODE_RSAES_OAEP        = 0x08U, /* RSA Optimal Asymmetric Encryption Padding */
    CRYPTO_ALGOMODE_RSAES_PKCS1_v1_5  = 0x09U, /* RSA encryption/decryption with PKCS#1 v1.5 
                                                  padding */
    CRYPTO_ALGOMODE_RSASSA_PSS        = 0x0AU, /* RSA Probabilistic Signature Scheme */
    CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5 = 0x0BU, /* RSA signature with PKCS#1 v1.5 */
    CRYPTO_ALGOMODE_8ROUNDS           = 0x0CU, /* 8 rounds (e.g. ChaCha8) */
    CRYPTO_ALGOMODE_12ROUNDS          = 0x0DU, /* 12 rounds (e.g. ChaCha12) */
    CRYPTO_ALGOMODE_20ROUNDS          = 0x0EU, /* 20 rounds (e.g. ChaCha20) */
    CRYPTO_ALGOMODE_HMAC              = 0x0FU, /* Hashed-based MAC */
    CRYPTO_ALGOMODE_CMAC              = 0x10U, /* Cipher-based MAC */
    CRYPTO_ALGOMODE_GMAC              = 0x11U, /* Galois MAC */
    CRYPTO_ALGOMODE_CTRDRBG           = 0x12U, /* Counter-based Deterministic Random Bit Generator*/
    CRYPTO_ALGOMODE_SIPHASH_2_4       = 0x13U, /* Siphash-2-4 */
    CRYPTO_ALGOMODE_SIPHASH_4_8       = 0x14U, /* Siphash-4-8 */
    CRYPTO_ALGOMODE_PXXXR1            = 0x15U, /* ANSI R1 Curve */
    CRYPTO_ALGOMODE_CUSTOM            = 0xffU  /* Custom algorithm mode */
} Crypto_AlgorithmModeType;

/**
 * @brief  Defines which of the input/output parameters are re-directed to a key element. The values
 *         can be combined to define a bit field.
 */
typedef enum
{
    CRYPTO_REDIRECT_CONFIG_PRIMARY_INPUT    = 0x01U,
    CRYPTO_REDIRECT_CONFIG_SECONDARY_INPUT  = 0x02U,
    CRYPTO_REDIRECT_CONFIG_TERTIARY_INPUT   = 0x04U,
    CRYPTO_REDIRECT_CONFIG_PRIMARY_OUTPUT   = 0x10U,
    CRYPTO_REDIRECT_CONFIG_SECONDARY_OUTPUT = 0x20U
} Crypto_InputOutputRedirectionConfigType;

/**
 * @brief  Enumeration of the current job state.
 */
typedef enum
{
    CRYPTO_JOBSTATE_IDLE   = 0x00U,
    CRYPTO_JOBSTATE_ACTIVE = 0x01U
} Crypto_JobStateType;

/**
 * @brief  Structure which contains input and output information depending on the job and 
 *         the crypto primitive.
 */
typedef struct 
{
    const uint8 *inputPtr;
    uint32 inputLength;
    const uint8 *secondaryInputPtr;
    uint32 secondaryInputLength;
    const uint8 *tertiaryInputPtr;
    uint32 tertiaryInputLength;
    uint8 *outputPtr;
    uint32 *outputLengthPtr;
    uint8 *secondaryOutputPtr;
    uint32 *secondaryOutputLengthPtr;
    Crypto_VerifyResultType *verifyPtr;
    Crypto_OperationModeType mode;
    uint32 cryIfKeyId;
    uint32 targetCryIfKeyId;
} Crypto_JobPrimitiveInputOutputType;

/**
 * @brief  Enumeration of the kind of the service.
 */
typedef enum
{
    CRYPTO_HASH                  = 0x00U,  /* Hash Service */
    CRYPTO_MACGENERATE           = 0x01U,  /* MacGenerate Service */
    CRYPTO_MACVERIFY             = 0x02U,  /* MacVerify Service */
    CRYPTO_ENCRYPT               = 0x03U,  /* Encrypt Service */
    CRYPTO_DECRYPT               = 0x04U,  /* Decrypt Service */
    CRYPTO_AEADENCRYPT           = 0x05U,  /* AEADEncrypt Service */
    CRYPTO_AEADDECRYPT           = 0x06U,  /* AEADDecrypt Service */
    CRYPTO_SIGNATUREGENERATE     = 0x07U,  /* SignatureGenerate Service */
    CRYPTO_SIGNATUREVERIFY       = 0x08U,  /* SignatureVerify Service */
    CRYPTO_RANDOMGENERATE        = 0x0BU,  /* RandomGenerate Service */
    CRYPTO_RANDOMSEED            = 0x0CU,  /* RandomSeed Service */
    CRYPTO_KEYGENERATE           = 0x0DU,  /* KeyGenerate Service */
    CRYPTO_KEYDERIVE             = 0x0EU,  /* KeyDerive Service */
    CRYPTO_KEYEXCHANGECALCPUBVAL = 0x0FU,  /* KeyExchangeCalcpubVal Service */
    CRYPTO_KEYEXCHANGECALCSECRET = 0x10U,  /* KeyExchangeCalcSecret Service */
    CRYPTO_KEYSETVALID           = 0x13U,  /* KeySetValid Service */
    CRYPTO_KEYSETINVALID         = 0x14U   /* KeySetInValid Service */
} Crypto_ServiceInfoType;

/**
 * @brief  Structure which holds the identifiers of the keys and key elements which shall be used
 *         as input and output for a job and a bit structure which indicates which buffers shall be
 *         redirected to those key elements.
 */
typedef struct
{
    uint8 redirectionConfig;
    uint32 inputKeyId;
    uint32 inputKeyElementId;
    uint32 secondaryInputKeyId;
    uint32 secondaryInputKeyElementId;
    uint32 tertiaryInputKeyId;
    uint32 tertiaryInputKeyElementId;
    uint32 outputKeyId;
    uint32 outputKeyElementId;
    uint32 secondaryOutputKeyId;
    uint32 secondaryOutputKeyElementId;
} Crypto_JobRedirectionInfoType;

/**
 * @brief  Structure which determines the exact algorithm. Note, not every algorithm needs to 
 *         specify all fields. AUTOSAR shall only allow valid combinations.
 */
typedef struct
{
    Crypto_AlgorithmFamilyType family;
    Crypto_AlgorithmFamilyType secondaryFamily;
    uint32 keyLength;
    Crypto_AlgorithmModeType mode;
} Crypto_AlgorithmInfoType;

/**
 * @brief  Enumeration of the processing type.
 */
typedef enum
{
    CRYPTO_PROCESSING_ASYNC = 0x0U,    /* Asynchronous job processing */
    CRYPTO_PROCESSING_SYNC  = 0x1U     /* Synchronous job processing */
} Crypto_ProcessingType;

/**
 * @brief  Structure which contains basic information about the crypto primitive.
 */
typedef struct
{
    const Crypto_ServiceInfoType service;
    const Crypto_AlgorithmInfoType algorithm;
} Crypto_PrimitiveInfoType;

/**
 * @brief  Structure which contains further information, which depends on the job and the crypto 
 *         primitive.
 */
typedef struct
{
    uint32 callbackId;
    const Crypto_PrimitiveInfoType *primitiveInfo;
    uint32 cryIfKeyId;
    Crypto_ProcessingType processingType;
} Crypto_JobPrimitiveInfoType;


/**
 * @brief  Structure which contains further information, which depends on the job and the crypto 
 *         primitive.
 */
typedef struct
{
    uint32 jobId;
    Crypto_JobStateType jobState;
    Crypto_JobPrimitiveInputOutputType jobPrimitiveInputOutput;
    const Crypto_JobPrimitiveInfoType* jobPrimitiveInfo;
    uint32 cryptoKeyId;
    Crypto_JobRedirectionInfoType* jobRedirectionInfoRef;
    uint32 targetCryptoKeyId;
    const uint32 jobPriority;
} Crypto_JobType;

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

/** @} end of group Crypto_GeneralTypes */

/** @} end of group Crypto_Module */

#endif /* CRYPTO_GENERALTYPES_H */
