/**************************************************************************************************/
/**
 * @file      : Crypto_KeyManagement.h
 * @brief     : Crypto Key Management header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef CRYPTO_KEYMANAGEMENT_H
#define CRYPTO_KEYMANAGEMENT_H

/** @addtogroup Crypto_Module
 *  @{
 */

/** @addtogroup Crypto_KeyManagement
 *  @brief Crypto Key Management
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define CRYPTO_KEYMANAGEMENT_H_VENDOR_ID                   0x00B3U
#define CRYPTO_KEYMANAGEMENT_H_AR_RELEASE_MAJOR_VERSION    4U
#define CRYPTO_KEYMANAGEMENT_H_AR_RELEASE_MINOR_VERSION    6U
#define CRYPTO_KEYMANAGEMENT_H_AR_RELEASE_REVISION_VERSION 0U
#define CRYPTO_KEYMANAGEMENT_H_SW_MAJOR_VERSION            1U
#define CRYPTO_KEYMANAGEMENT_H_SW_MINOR_VERSION            2U
#define CRYPTO_KEYMANAGEMENT_H_SW_PATCH_VERSION            1U

#define CRYPTO_GETKEYSTATUS(KeyId)         ((boolean)(*Crypto_KeyList[(KeyId)].KeyStatus) & 0x03U)
#define CRYPTO_SETKEYSTATUS(KeyId, Status) (*Crypto_KeyList[(KeyId)].KeyStatus = (Status))
#define CRYPTO_CLEARKEYSTATUS(KeyId)       (*Crypto_KeyList[(KeyId)].KeyStatus = CRYPTO_KEYSTATUS_INVALID)
/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
/**
 * @brief      Sets the given key element bytes to the key identified by cryptoKeyId.
 *
 * @param[in]  cryptoKeyId: Holds the identifier of the key whose key element shall be set.
 * @param[in]  keyElementId: Holds the identifier of the key element which shall be set.
 * @param[in]  keyPtr: Holds the pointer to the key data which shall be set as key element.
 * @param[in]  keyLength: Contains the length of the key element in bytes.
 *
 * @return     Std_ReturnType
 * @retval     E_OK
 * @retval     E_NOT_OK
 * @retval     CRYPTO_E_BUSY
 * @retval     CRYPTO_E_KEY_WRITE_FAIL
 * @retval     CRYPTO_E_KEY_NOT_AVAILABLE
 * @retval     CRYPTO_E_KEY_SIZE_MISMATCH
 * 
 */
Std_ReturnType Crypto_KeyElementSet(uint32 cryptoKeyId, uint32 keyElementId, const uint8* keyPtr,
                                    uint32 keyLength);

/**
 * @brief      Sets the key state of the key identified by cryptoKeyId to valid.
 *
 * @param[in]  cryptoKeyId: Holds the identifier of the key which shall be set to valid.
 *
 * @return     Std_ReturnType
 * @retval     E_OK
 * @retval     E_NOT_OK
 * @retval     CRYPTO_E_BUSY
 * 
 */
Std_ReturnType Crypto_KeySetValid(uint32 cryptoKeyId);

/**
 * @brief      Sets invalid for the status of the key identified by cryptoKeyId.
 *
 * @param[in]  cryptoKeyId: Holds the identifier of the key for which the status shall be set to 
 *             invalid.
 *
 * @return     Std_ReturnType
 * @retval     E_OK
 * @retval     E_NOT_OK
 * @retval     CRYPTO_E_BUSY
 * 
 */
Std_ReturnType Crypto_KeySetInvalid(uint32 cryptoKeyId);

/**
 * @brief      This interface shall be used to get a key element of the key identified by the crypto
 *             KeyId and store the key element in the memory location pointed by the result pointer. 
 *             Note: If the actual key element is directly mapped to flash memory, there could be a 
 *             bigger delay when calling this function (synchronous operation).
 *
 * @param[in]  cryptoKeyId: Holds the identifier of the key whose key element shall be returned.
 * @param[in]  keyElementId: Holds the identifier of the key element which shall be returned.
 * @param[out] resultPtr: Holds the pointer of the buffer for the returned key element.
 * @param[in]  resultLengthPtr: Holds a pointer to a memory location in which the length information 
 *             is stored. 
 *
 * @return     Std_ReturnType
 * @retval     E_OK
 * @retval     E_NOT_OK
 * @retval     CRYPTO_E_BUSY
 * @retval     CRYPTO_E_KEY_READ_FAIL
 * @retval     CRYPTO_E_KEY_NOT_AVAILABLE
 * @retval     CRYPTO_E_KEY_EMPTY
 * 
 */
Std_ReturnType Crypto_KeyElementGet(uint32 cryptoKeyId, uint32 keyElementId, uint8* resultPtr,
                                    uint32* resultLengthPtr);

/**
 * @brief      Returns the key state of the key identified by cryptoKeyId.
 *
 * @param[in]  cryptoKeyId: Holds the identifier of the key for which the key state shall be 
 *             returned.
 * @param[out] keyStatusPtr: Contains the pointer to the data where the status of the key shall be 
 *             stored.
 *
 * @return     Std_ReturnType
 * @retval     E_OK
 * @retval     E_NOT_OK
 * 
 */
Std_ReturnType Crypto_KeyGetStatus(uint32 cryptoKeyId, Crypto_KeyStatusType* keyStatusPtr);

/**
 * @brief      Copies a key element to another key element in the same crypto driver. Note: If the 
 *             actual key element is directly mapped to flash memory, there could be a bigger delay
 *             when calling this function (synchronous operation)
 *
 * @param[in]  cryptoKeyId: Holds the identifier of the key whose key element shall be the source
 *             element.
 * @param[out] keyElementId: Holds the identifier of the key element which shall be the source for
 *             the copy operation.
 * @param[in]  targetCryptoKeyId: Holds the identifier of the key whose key element shall be the 
 *             destination element.
 * @param[out] targetKeyElementId: Holds the identifier of the key element which shall be the 
 *             destination for the copy operation.
 *
 * @return     Std_ReturnType
 * @retval     E_OK
 * @retval     E_NOT_OK
 * @retval     CRYPTO_E_BUSY
 * @retval     CRYPTO_E_KEY_NOT_AVAILABLE
 * @retval     CRYPTO_E_KEY_READ_FAIL
 * @retval     CRYPTO_E_KEY_WRITE_FAIL
 * @retval     CRYPTO_E_KEY_SIZE_MISMATCH
 * @retval     CRYPTO_E_KEY_EMPTY
 * 
 */
Std_ReturnType Crypto_KeyElementCopy(uint32 cryptoKeyId, uint32 keyElementId,
                                     uint32 targetCryptoKeyId, uint32 targetKeyElementId);

/**
 * @brief      Copies a key element to another key element in the same crypto driver. The key
 *             ElementSourceOffset and keyElementCopyLength allows to copy just a part of the source
 *             key element into the destination. The offset of the target key is also specified with
 *             this function.
 *
 * @param[in]  cryptoKeyId: Holds the identifier of the key whose key element shall be the source
 *             element.
 * @param[out] keyElementId: Holds the identifier of the key element which shall be the source for
 *             the copy operation.
 * @param[in]  keyElementSourceOffset: This is the offset of the of the source key element
 *             indicating the start index of the copy operation.
 * @param[out] keyElementTargetOffset: This is the offset of the of the target key element 
 *             indicating the  start index of the copy operation.
 * @param[out] keyElementCopyLength: Specifies the number of bytes that shall be copied.
 * @param[in]  targetCryptoKeyId: Holds the identifier of the key whose key element shall be the 
 *             destination element.
 * @param[out] targetKeyElementId: Holds the identifier of the key element which shall be the 
 *             destination for the copy operation.
 * 
 * @return     Std_ReturnType
 * @retval     E_OK
 * @retval     E_NOT_OK
 * @retval     CRYPTO_E_BUSY
 * @retval     CRYPTO_E_KEY_NOT_AVAILABLE
 * @retval     CRYPTO_E_KEY_READ_FAIL
 * @retval     CRYPTO_E_KEY_WRITE_FAIL
 * @retval     CRYPTO_E_KEY_SIZE_MISMATCH
 * @retval     CRYPTO_E_KEY_EMPTY
 * 
 */
Std_ReturnType Crypto_KeyElementCopyPartial(uint32 cryptoKeyId, uint32 keyElementId,
                                            uint32 keyElementSourceOffset,
                                            uint32 keyElementTargetOffset,
                                            uint32 keyElementCopyLength, uint32 targetCryptoKeyId,
                                            uint32 targetKeyElementId);

/**
 * @brief      Copies a key with all its elements to another key in the same crypto driver.
 *
 * @param[in]  cryptoKeyId: Holds the identifier of the key whose key element shall be the source
 *             element.
 * @param[out] targetCryptoKeyId: Holds the identifier of the key whose key element shall be the 
 *             destination element.
 *
 * @return     Std_ReturnType
 * @retval     E_OK
 * @retval     E_NOT_OK
 * @retval     CRYPTO_E_BUSY
 * @retval     CRYPTO_E_KEY_NOT_AVAILABLE
 * @retval     CRYPTO_E_KEY_READ_FAIL
 * @retval     CRYPTO_E_KEY_WRITE_FAIL
 * @retval     CRYPTO_E_KEY_SIZE_MISMATCH
 * @retval     CRYPTO_E_KEY_EMPTY
 * 
 */
Std_ReturnType Crypto_KeyCopy(uint32 cryptoKeyId, uint32 targetCryptoKeyId);

/**
 * @brief        Used to retrieve information which key elements are available in a given key.
 *
 * @param[in]    cryptoKeyId: Holds the identifier of the key whose available element ids shall be
 *               exported.
 * @param[in]    keyElementIdsPtr: Contains the pointer to the array where the ids of the key 
 *               elements shall be stored.
 * @param[inout] keyElementIdsLengthPtr: Holds a pointer to the memory location in which the number
 *               of key elements in the given key is stored. On calling this function, this 
 *               parameter shall contain the size of the buffer provided by keyElement IdsPtr. When
 *               the request has finished, the actual number of key elements shall be stored.
 * 
 * @return       Std_ReturnType
 * @retval       E_OK
 * @retval       E_NOT_OK
 * @retval       CRYPTO_E_BUSY
 * 
 */
Std_ReturnType Crypto_KeyElementIdsGet(uint32 cryptoKeyId, uint32* keyElementIdsPtr,
                                       uint32* keyElementIdsLengthPtr);

/**
 * @brief      This function generates the internal seed state using the provided entropy source. 
 *             Furthermore, this function can be used to update the seed state with new entropy.
 *
 * @param[in]  cryptoKeyId: Holds the identifier of the key for which a new seed shall be generated.
 * @param[in]  seedPtr: Holds a pointer to the memory location which contains the data to feed the 
 *             seed.
 * @param[in]  seedLength: Contains the length of the seed in bytes.
 * 
 * @return     Std_ReturnType
 * @retval     E_OK
 * @retval     E_NOT_OK
 * @retval     CRYPTO_E_KEY_NOT_VALID
 * 
 */
Std_ReturnType Crypto_RandomSeed(uint32 cryptoKeyId, const uint8* seedPtr, uint32 seedLength);

/**
 * @brief      Generates new key material store it in the key identified by cryptoKeyId.
 *
 * @param[in]  cryptoKeyId: Holds the identifier of the key which is to be updated with the 
 *             generated value.
 * 
 * @return     Std_ReturnType
 * @retval     E_OK
 * @retval     E_NOT_OK
 * @retval     CRYPTO_E_BUSY
 * @retval     CRYPTO_E_KEY_EMPTY
 * @retval     CRYPTO_E_KEY_NOT_VALID
 * 
 */
Std_ReturnType Crypto_KeyGenerate(uint32 cryptoKeyId);

/**
 * @brief      Derives a new key by using the key elements in the given key identified by the crypto
 *             KeyId.
 *
 * @param[in]  cryptoKeyId: Holds the identifier of the key which is used for key derivation.
 * @param[in]  targetCryptoKeyId: Holds the identifier of the key which is used to store the derived 
 *             key.
 * 
 * @return     Std_ReturnType
 * @retval     E_OK
 * @retval     E_NOT_OK
 * @retval     CRYPTO_E_BUSY
 * @retval     CRYPTO_E_KEY_EMPTY
 * @retval     CRYPTO_E_KEY_NOT_VALID
 * 
 */
Std_ReturnType Crypto_KeyDerive(uint32 cryptoKeyId, uint32 targetCryptoKeyId);

/**
 * @brief         Calculates the public value for the key exchange and stores the public key in the 
 *                memory location pointed by the public value pointer.
 *
 * @param[in]     cryptoKeyId: Holds the identifier of the key which shall be used for the key 
 *                exchange protocol.
 * @param[inout]  publicValueLengthPtr: Holds a pointer to the memory location in which the public
 *                value length information is stored. On calling this function, this parameter shall 
 *                contain the size of the buffer provided by publicValuePtr. When the request has
 *                finished, the actual length of the returned value shall be stored.
 * @param[out]    publicValuePtr: Contains the pointer to the data where the public value shall be 
 *                stored.
 * 
 * @return        Std_ReturnType
 * @retval        E_OK
 * @retval        E_NOT_OK
 * @retval        CRYPTO_E_BUSY
 * @retval        CRYPTO_E_KEY_EMPTY
 * @retval        CRYPTO_E_KEY_NOT_VALID
 * 
 */
Std_ReturnType Crypto_KeyExchangeCalcPubVal(uint32 cryptoKeyId, uint8* publicValuePtr,
                                            uint32* publicValueLengthPtr);

/**
 * @brief      Calculates the shared secret key for the key exchange with the key material of the 
 *             key identified by the cryptoKeyId and the partner public key. The shared secret key 
 *             is stored as a key element in the same key.
 *
 * @param[in]  cryptoKeyId: Holds the identifier of the key which shall be used for the key 
 *             exchange protocol.
 * @param[in]  partnerPublicValuePtr: Holds the pointer to the memory location which contains the 
 *             partner's public value.
 * @param[in]  partnerPublicValueLength: Contains the length of the partner's public value in bytes.
 * 
 * @return     Std_ReturnType
 * @retval     E_OK
 * @retval     E_NOT_OK
 * @retval     CRYPTO_E_BUSY
 * @retval     CRYPTO_E_KEY_EMPTY
 * @retval     CRYPTO_E_KEY_NOT_VALID
 * 
 */
Std_ReturnType Crypto_KeyExchangeCalcSecret(uint32 cryptoKeyId, const uint8* partnerPublicValuePtr,
                                            uint32 partnerPublicValueLength);
                                              
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Crypto_KeyManagement */

/** @} end of group Crypto_Module */

#endif /* CRYPTO_KEYMANAGEMENT_H */
