/**************************************************************************************************/
/**
 * @file      : Crypto_Cfg.h  
 * @brief     : Crypto configuration header file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef CRYPTO_CFG_H
#define CRYPTO_CFG_H

#ifdef __cplusplus
extern "C"{
#endif


/* Published information */
#define CRYPTO_CFG_H_VENDOR_ID                   0x00B3U
#define CRYPTO_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define CRYPTO_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define CRYPTO_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define CRYPTO_CFG_H_SW_MAJOR_VERSION            1U
#define CRYPTO_CFG_H_SW_MINOR_VERSION            2U
#define CRYPTO_CFG_H_SW_PATCH_VERSION            2U

/* Pre-processor switch to enable/disable development error detection for Crypto API */
#define CRYPTO_DEV_ERROR_DETECT                         (STD_ON)

/* Pre-processor switch to enable/disable the API to read out the modules version information */
#define CRYPTO_VERSION_INFO_API                         (STD_ON)

/* Crypto instance ID value */
#define CRYPTO_INSTANCE_ID                              ((uint8)0)

/* Number of configured Crypto driver objects */
#define CRYPTO_NUMBER_OF_DRIVER_OBJECTS                 ((uint32)3U)
      
/* Symbolic names macro definition */
#define CryptoConf_CryptoDriverObject_CryptoDriverObject_AES    ((uint32)1U)
#define CryptoConf_CryptoDriverObject_CryptoDriverObject_TRNG    ((uint32)0U)
#define CryptoConf_CryptoDriverObject_CryptoDriverObject_KEY    ((uint32)2U)
#define CryptoConf_CryptoKey_Encrypt    ((uint32)0U)
#define CryptoConf_CryptoKey_Decrypt    ((uint32)1U)
#define CryptoConf_CryptoKey_AEADEncrypt    ((uint32)2U)
#define CryptoConf_CryptoKey_AEADDecrypt    ((uint32)3U)
#define CryptoConf_CryptoKey_CMAC    ((uint32)4U)
#define CryptoConf_CryptoKey_GMAC    ((uint32)5U)
#define CryptoConf_CryptoKeyElement_EncryptKey    ((uint32)1U)
#define CryptoConf_CryptoKeyElement_EncryptIv    ((uint32)5U)
#define CryptoConf_CryptoKeyElement_DecryptKey    ((uint32)1U)
#define CryptoConf_CryptoKeyElement_DecryptIv    ((uint32)5U)
#define CryptoConf_CryptoKeyElement_AEADEncryptKey    ((uint32)1U)
#define CryptoConf_CryptoKeyElement_AEADEncryptIv    ((uint32)5U)
#define CryptoConf_CryptoKeyElement_AEADDecryptKey    ((uint32)1U)
#define CryptoConf_CryptoKeyElement_AEADDecryptIv    ((uint32)5U)
#define CryptoConf_CryptoKeyElement_CMACKey    ((uint32)1U)
#define CryptoConf_CryptoKeyElement_GMACKey    ((uint32)1U)
#define CryptoConf_CryptoKeyElement_GMACIv    ((uint32)5U)
#define CryptoConf_CryptoPrimitiveAlgorithmModeCustom_CryptoPrimitiveAlgorithmModeCustom_0    ((uint8)128U)

/* Crypto custom primitive algorithm mode definition */
#define CRYPTO_ALGOMODE_CCM    CryptoConf_CryptoPrimitiveAlgorithmModeCustom_CryptoPrimitiveAlgorithmModeCustom_0

#define CRYPTO_ALGOMODE_CUSTOM_SWITCH    (STD_ON)

#define CRYPTO_CONFIG_EXT \
        extern const Crypto_ObjectPrimitiveType Crypto_ObjectPrimitiveList[CRYPTO_NUMBER_OF_DRIVER_OBJECTS];
    
#define CRYPTO_CONFIG1_EXT \
        extern const Crypto_QueueInfoType Crypto_QueueInfoList[CRYPTO_NUMBER_OF_DRIVER_OBJECTS];
        
#define CRYPTO_CONFIG2_EXT \
        extern Crypto_ObjectQueueType Crypto_ObjectQueueList[CRYPTO_NUMBER_OF_DRIVER_OBJECTS];

/* At least one key exists */
#define CRYPTO_EXIST_KEYS                           (STD_ON)

/* Number of Crypto keys */
#define CRYPTO_NUMBER_OF_KEYS                       ((uint32)6U)

#define CRYPTO_CONFIG3_EXT \
        extern const Crypto_KeyType Crypto_KeyList[CRYPTO_NUMBER_OF_KEYS];

#define CRYPTO_CALLBACK_FUNSET_EXT \

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CRYPTO_CFG_H */

