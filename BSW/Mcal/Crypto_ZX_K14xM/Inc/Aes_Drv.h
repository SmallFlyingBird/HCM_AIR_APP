/**************************************************************************************************/
/**
 * @file      : Aes_Drv.h
 * @brief     : Aes low level driver header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef AES_DRV_H
#define AES_DRV_H

/** @addtogroup Crypto_Module
 *  @{
 */

/** @addtogroup Aes_Drv
 *  @brief Aes low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Aes_Drv_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define AES_DRV_H_VENDOR_ID                   0x00B3U
#define AES_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define AES_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define AES_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define AES_DRV_H_SW_MAJOR_VERSION            1U
#define AES_DRV_H_SW_MINOR_VERSION            2U
#define AES_DRV_H_SW_PATCH_VERSION            2U

/* Check if current file and Aes_Drv_Types.h are the same vendor */
#if (AES_DRV_H_VENDOR_ID != AES_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Aes_Drv.h and Aes_Drv_Types.h are different"
#endif
/* Check if current file and Aes_Drv_Types.h are the same Autosar version */
#if ((AES_DRV_H_AR_RELEASE_MAJOR_VERSION != AES_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
     (AES_DRV_H_AR_RELEASE_MINOR_VERSION != AES_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) || \
     (AES_DRV_H_AR_RELEASE_REVISION_VERSION != AES_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Aes_Drv.h and Aes_Drv_Types.h are different"
#endif
/* Check if current file and Aes_Drv_Types.h are the same Software version */
#if ((AES_DRV_H_SW_MAJOR_VERSION != AES_DRV_TYPES_H_SW_MAJOR_VERSION) || \
     (AES_DRV_H_SW_MINOR_VERSION != AES_DRV_TYPES_H_SW_MINOR_VERSION) || \
     (AES_DRV_H_SW_PATCH_VERSION != AES_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Aes_Drv.h and Aes_Drv_Types.h are different"
#endif
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
 * @brief     Compare generated data by AES with expected data
 *
 * @param[in] ExpectedDataPtr: Pointer to the expected data
 * @param[in] GeneratedDataPtr: Pointer to the generated data
 * @param[in] DataLen: Compare length in bits
 *
 * @return    boolean
 * @retval    TRUE or FALSE
 */
boolean Aes_Drv_CompareData(const uint8 *ExpectedDataPtr, const uint8 *GeneratedDataPtr, uint32 DataLen);

/**
 * @brief     Initialize a CMAC operation
 *
 * @param[in] KeyPtr: Pointer to the key
 *
 * @return    None
 * 
 */
void Aes_Drv_StartCmac(const uint8 *KeyPtr);

/**
 * @brief     Update data for CMAC operation
 *
 * @param[in] InputDataPtr: Pointer to the input data block
 * @param[in] InputLen: Data length in bytes. 
 *            Note: Data that are not 16-bytes aligned is supported only for the last update 
 *            operation, and there shall not be new input data in finish operation in that case
 * 
 * @return    Aes_Drv_StatusType
 * 
 */
Aes_Drv_StatusType Aes_Drv_UpdateCmac(const uint8 *InputDataPtr, uint32 InputLen);

/**
 * @brief      Finish a CMAC operation
 *
 * @param[in]  InputDataPtr: Pointer to the input data block
 * @param[in]  InputLen: Data length in bytes
 * @param[out] MacPtr: Pointer to the generated MAC
 * @param[in]  MacLength: Length of the required MAC in bytes
 *
 * @return     Aes_Drv_StatusType
 * 
 */
Aes_Drv_StatusType Aes_Drv_FinishCmac(const uint8 *InputDataPtr, 
                                      uint32 InputLen, uint8 *MacPtr, uint32 MacLength);

/**
 * @brief      CMAC generation operation
 *
 * @param[in]  KeyPtr: Pointer to the key
 * @param[in]  Message: Pointer to the given message
 * @param[in]  MessageLength: Length of the whole given message for CMAC operation in bytes
 * @param[out] MacPtr: Pointer to the generated MAC
 * @param[in]  MacLength: Length of the required MAC in bytes
 *
 * @return     Aes_Drv_StatusType
 * 
 */ 
Aes_Drv_StatusType Aes_Drv_GenerateCmac(const uint8 *KeyPtr, const uint8 *Message, 
                                        uint32 MessageLength, uint8 *MacPtr, uint32 MacLength);

/**
 * @brief      CMAC verification operation
 * 
 * @param[in]  KeyPtr: Pointer to the key
 * @param[in]  Message: Pointer to the given message
 * @param[in]  MessageLength: Length of the whole given message for CMAC operation in bytes
 * @param[in]  MacPtr: Pointer to the MAC for verification
 * @param[in]  MacLength: Length of the MAC to be verified in bits
 * @param[out] VerifyResult: Pointer to space storing the result of the MAC verify operation
 *
 * @return     Aes_Drv_StatusType
 * 
 */
Aes_Drv_StatusType Aes_Drv_VerifyCmac(const uint8 *KeyPtr, const uint8 *Message,
                 uint32 MessageLength, const uint8 *MacPtr, uint32 MacLength, boolean *VerifyResult);

/**
 * @brief     Initialize an encrypt or decrypt operation
 *
 * @param[in] KeyPtr: Pointer to the key
 * @param[in] IvPtr: Pointer to the initial vector
 * @param[in] AlgorithmMode: Algorithm mode
 * @param[in] FunctionType: AES encryption or decryption
 *
 * @return    Aes_Drv_StatusType
 * 
 */
Aes_Drv_StatusType Aes_Drv_StartCrypt(const uint8 *KeyPtr,const uint8 *IvPtr, 
             const Aes_Drv_AlgorithmModeType AlgorithmMode, Aes_Drv_CryptFunctionType FunctionType);

/**
 * @brief      Update data for an encrypt or decrypt operation
 *
 * @param[in]  InputDataPtr: Pointer to the input data block
 * @param[in]  InputLength: Data length in bytes, it should be 16 bytes aligned
 * @param[out] OutputDataPtr: Pointer to the output data block
 * @param[in]  AlgorithmMode: Algorithm mode
 * @param[in]  FunctionType: AES encryption or decryption
 *
 * @return     Aes_Drv_StatusType
 * 
 */
Aes_Drv_StatusType Aes_Drv_UpdateCrypt(const uint8 *InputDataPtr, 
                                       uint32 InputLength, uint8 *OutputDataPtr, 
                                       const Aes_Drv_AlgorithmModeType AlgorithmMode, 
                                       Aes_Drv_CryptFunctionType FunctionType);

/**
 * @brief      AES encrypt or decrypt operation
 *
 * @param[in]  KeyPtr: Pointer to the key
 * @param[in]  IvPtr: Pointer to the initial vector
 * @param[in]  InputDataPtr: Pointer to the input data block
 * @param[in]  InputLength: Data length in bytes, it should be 16 bytes aligned
 * @param[out] OutputDataPtr: Pointer to the output data block
 * @param[in]  AlgorithmMode: Algorithm mode
 * @param[in]  FunctionType: AES encryption or decryption
 *
 * @return     Aes_Drv_StatusType
 * 
 */
Aes_Drv_StatusType Aes_Drv_Crypt(const uint8 *KeyPtr, const uint8 *IvPtr, const uint8 *InputDataPtr, 
                                 uint32 InputLength, uint8 *OutputDataPtr,
                                 const Aes_Drv_AlgorithmModeType AlgorithmMode, 
                                 Aes_Drv_CryptFunctionType FunctionType);

/**
 * @brief     Initialize an GCM operation
 *
 * @param[in] KeyPtr: Pointer to the key
 * @param[in] IvPtr: Pointer to the initial vector
 * @param[in] IvLen: Length of initial vector in bits
 * @param[in] FunctionType: AES encryption or decryption
 *
 * @return    Aes_Drv_StatusType
 * 
 */
Aes_Drv_StatusType Aes_Drv_StartGcm(const uint8 *KeyPtr, const uint8 *IvPtr, 
                                    uint32 IvLen, Aes_Drv_CryptFunctionType FunctionType);

/**
 * @brief     Update GCM AAD data
 *
 * @param[in] AadPtr: Pointer to the AAD data block
 * @param[in] AadLength: AAD data length in bytes
 *            Note: AAD data that are not 16-bytes aligned is supported only for the last update 
 *            AAD operation, and there shall not be new AAD data in finish operation in that case
 * @param[in] FunctionType: AES encryption or decryption
 *
 * @return    Aes_Drv_StatusType
 * 
 */
Aes_Drv_StatusType Aes_Drv_UpdateGcmAad(const uint8 *AadPtr, uint32 AadLength, 
                                        Aes_Drv_CryptFunctionType FunctionType);

/**
 * @brief      Update GCM message data
 *
 * @param[in]  InputDataPtr: Pointer to the input data block
 * @param[in]  InputLength: Data length in bytes
 *             Note: GCM data that are not 16-bytes aligned is supported only for the last update 
 *             operation, and there shall not be new input data in finish operation in that case
 * @param[out] OutputDataPtr: Pointer to the output data block
 * @param[in]  FunctionType: AES encryption or decryption
 *
 * @return     Aes_Drv_StatusType
 * 
 */
Aes_Drv_StatusType Aes_Drv_UpdateGcmData(const uint8 *InputDataPtr, uint32 InputLength, 
                                      uint8 *OutputDataPtr, Aes_Drv_CryptFunctionType FunctionType);

/**
 * @brief     Finish a GCM operation and read out the text data and tag
 *
 * @param[in]  InputDataPtr: Pointer to the input data
 * @param[in]  InputLength: Length of the input data in bytes
 * @param[in]  AadDataPtr: Pointer to the AAD data
 * @param[in]  AadLength: Length of the AAD data in bytes
 * @param[out] OutputDataPtr: Pointer to the output data
 * @param[out] TagPtr: Pointer to the calculated tag
 * @param[in]  TagLength: Tag length in bytes
 * @param[in]  FunctionType: AES encryption or decryption
 *
 * @return    Aes_Drv_StatusType
 * 
 */
Aes_Drv_StatusType Aes_Drv_FinishGcm(const uint8 *InputDataPtr, uint32 InputLength, 
                                     const uint8 *AadDataPtr, uint32 AadLength,
                                     uint8 *OutputDataPtr, uint8 *TagPtr, uint32 TagLength, 
                                     Aes_Drv_CryptFunctionType FunctionType);

/**
 * @brief      GCM operation
 *
 * @param[in]  KeyPtr: Pointer to the key
 * @param[in]  IvPtr: Pointer to the initial vector
 * @param[in]  IvLength: Length of the initial vector in bits
 * @param[in]  InputDataPtr: Pointer to the input data
 * @param[in]  InputLength: Length of the input data in bytes
 * @param[in]  AadDataPtr: Pointer to the AAD data
 * @param[in]  AadLength: Length of the AAD data in bytes
 * @param[out] OutputDataPtr: Pointer to the output data
 * @param[out] TagPtr: Pointer to the calculated tag
 * @param[in]  TagLen: Tag length in bytes
 * @param[in]  FunctionType: AES encryption or decryption
 *
 * @return     Aes_Drv_StatusType
 * 
 */
Aes_Drv_StatusType Aes_Drv_Gcm(const uint8 *KeyPtr, const uint8 *IvPtr, uint32 IvLength,
                               const uint8 *InputDataPtr, uint32 InputLength,
                               const uint8 *AadDataPtr, uint32 AadLength, uint8 *OutputDataPtr, 
                               uint8 *TagPtr, uint32 TagLen,Aes_Drv_CryptFunctionType FunctionType);

/**
 * @brief      CCM operation, only single call mode is supported for CCM
 *
 * @param[in]  KeyPtr: Pointer to the key
 * @param[in]  IvPtr: Pointer to the initial vector
 * @param[in]  IvLength: Length of the initial vector in bits
 * @param[in]  InputDataPtr: Pointer to the input data
 * @param[in]  InputLength: Length of the input data in bytes
 * @param[in]  AadDataPtr: Pointer to the AAD data
 * @param[in]  AadLength: Length of the AAD data in bytes
 * @param[out] OutputDataPtr: Pointer to the output data
 * @param[out] TagPtr: Pointer to the calculated tag
 * @param[in]  TagLen: Tag length in bytes
 * @param[in]  FunctionType: AES encryption or decryption
 *
 * @return     Aes_Drv_StatusType
 * 
 */
Aes_Drv_StatusType Aes_Drv_Ccm(const uint8 *KeyPtr, const uint8 *IvPtr, uint32 IvLength,
                               const uint8 *InputDataPtr, uint32 InputLength,
                               const uint8 *AadDataPtr, uint32 AadLength, uint8 *OutputDataPtr, 
                               uint8 *TagPtr,uint32 TagLen, Aes_Drv_CryptFunctionType FunctionType);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Aes_Drv */

/** @} end of group Crypto_Module */

#endif /* AES_DRV_H */
