/**************************************************************************************************/
/**
 * @file      : Crypto_KeyManagement.c
 * @brief     : Crypto AUTOSAR level source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Crypto_Module
 *  @{
 */

/** @addtogroup Crypto_KeyManagement
 *  @brief Crypto AUTOSAR level
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Trng_Drv.h"
#include "Det.h"
#include "Crypto.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
/* Published information */
#define CRYPTO_KEYMANAGEMENT_C_VENDOR_ID                   0x00B3U
#define CRYPTO_KEYMANAGEMENT_C_AR_RELEASE_MAJOR_VERSION    4U
#define CRYPTO_KEYMANAGEMENT_C_AR_RELEASE_MINOR_VERSION    6U
#define CRYPTO_KEYMANAGEMENT_C_AR_RELEASE_REVISION_VERSION 0U
#define CRYPTO_KEYMANAGEMENT_C_SW_MAJOR_VERSION            1U
#define CRYPTO_KEYMANAGEMENT_C_SW_MINOR_VERSION            2U
#define CRYPTO_KEYMANAGEMENT_C_SW_PATCH_VERSION            2U

/* Check if current file and Crypto.h are the same vendor */
#if (CRYPTO_KEYMANAGEMENT_C_VENDOR_ID != CRYPTO_VENDOR_ID)
    #error "Vendor ID of Crypto_KeyManagement.c and Crypto.h are different"
#endif
/* Check if current file and Crypto.h are the same Autosar version */
#if ((CRYPTO_KEYMANAGEMENT_C_AR_RELEASE_MAJOR_VERSION != CRYPTO_AR_RELEASE_MAJOR_VERSION) || \
     (CRYPTO_KEYMANAGEMENT_C_AR_RELEASE_MINOR_VERSION != CRYPTO_AR_RELEASE_MINOR_VERSION) || \
     (CRYPTO_KEYMANAGEMENT_C_AR_RELEASE_REVISION_VERSION != CRYPTO_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Crypto_KeyManagement.c and Crypto.h are different"
#endif
/* Check if current file and Crypto.h are the same Software version */
#if ((CRYPTO_KEYMANAGEMENT_C_SW_MAJOR_VERSION != CRYPTO_SW_MAJOR_VERSION) || \
     (CRYPTO_KEYMANAGEMENT_C_SW_MINOR_VERSION != CRYPTO_SW_MINOR_VERSION) || \
     (CRYPTO_KEYMANAGEMENT_C_SW_PATCH_VERSION != CRYPTO_SW_PATCH_VERSION))
    #error "Software Version of Crypto_KeyManagement.c and Crypto.h are different"
#endif

/* Check if current file and Trng_Drv.h are the same vendor */
#if (CRYPTO_KEYMANAGEMENT_C_VENDOR_ID != TRNG_DRV_H_VENDOR_ID)
    #error "Vendor ID of Crypto_KeyManagement.c and Trng_Drv.h are different"
#endif
/* Check if current file and Trng_Drv.h are the same Autosar version */
#if ((CRYPTO_KEYMANAGEMENT_C_AR_RELEASE_MAJOR_VERSION != TRNG_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (CRYPTO_KEYMANAGEMENT_C_AR_RELEASE_MINOR_VERSION != TRNG_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (CRYPTO_KEYMANAGEMENT_C_AR_RELEASE_REVISION_VERSION != TRNG_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Crypto_KeyManagement.c and Trng_Drv.h are different"
#endif
/* Check if current file and Trng_Drv.h are the same Software version */
#if ((CRYPTO_KEYMANAGEMENT_C_SW_MAJOR_VERSION != TRNG_DRV_H_SW_MAJOR_VERSION) || \
     (CRYPTO_KEYMANAGEMENT_C_SW_MINOR_VERSION != TRNG_DRV_H_SW_MINOR_VERSION) || \
     (CRYPTO_KEYMANAGEMENT_C_SW_PATCH_VERSION != TRNG_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Crypto_KeyManagement.c and Trng_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and NvM.h are the same Autosar version */
    #if ((CRYPTO_KEYMANAGEMENT_C_AR_RELEASE_MAJOR_VERSION != NVM_AR_RELEASE_MAJOR_VERSION) || \
         (CRYPTO_KEYMANAGEMENT_C_AR_RELEASE_MINOR_VERSION != NVM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Crypto_KeyManagement.c and NvM.h are different"
    #endif
    /* Check if current file and Det.h are the same Autosar version */
    #if ((CRYPTO_KEYMANAGEMENT_C_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) || \
         (CRYPTO_KEYMANAGEMENT_C_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Crypto_KeyManagement.c and Det.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/* invalid Key Element id definition */
#define CRYPTO_INVALID_KEY_ELEMENT_INDEX    (0xFFFFFFFFU)
/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
#if(STD_ON == CRYPTO_DEV_ERROR_DETECT)
LOCAL_INLINE Std_ReturnType Crypto_CheckModuleState(uint8 ServiceId);
LOCAL_INLINE Std_ReturnType Crypto_CheckKeyId(uint32 KeyId, uint8 ServiceId);
LOCAL_INLINE Std_ReturnType Crypto_CheckKeyElementId(uint32 KeyId, uint32 KeyElementId, uint8 ServiceId);
LOCAL_INLINE Std_ReturnType Crypto_CheckDataPtr(const uint8* DataPtr, uint8 ServiceId);
LOCAL_INLINE Std_ReturnType Crypto_CheckDataLength(uint32 DataLength, uint8 ServiceId);
#endif
static void Crypto_MemCopy(uint8* DesPtr, const uint8* SrcPtr, uint32 Length);
static void Crypto_GetIndex(uint32 CryptoKeyId, uint32 KeyElementId, uint32 *KeyElementIndex);
static Std_ReturnType Crypto_CheckKeyElementCopy(uint32 SrcKeyIndex, uint32 SrcElementIndex,
                                                 uint32 DesKeyIndex, uint32 DesElementIndex);
static Std_ReturnType Crypto_CheckKeyElementCopyPartial(uint32 SrcKeyIndex, uint32 SrcElementIndex,
                                             uint32 SrcOffset, uint32 DesOffset, uint32 CopyLength, 
                                             uint32 DesKeyIndex, uint32 DesElementIndex);
static Std_ReturnType Crypto_CopyKeyElements(uint32 SrcKeyIndex, uint32 DesKeyIndex);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
#if(STD_ON == CRYPTO_DEV_ERROR_DETECT)
/**
 * @brief     Check the Crypto module state
 *
 * @param[in] ServiceId: ApiId
 *
 * @return    Std_ReturnType
 * @retval    E_OK
 * @retval    E_NOT_OK
 *
 */
LOCAL_INLINE Std_ReturnType Crypto_CheckModuleState(uint8 ServiceId)
{
	Std_ReturnType RetVal = (Std_ReturnType)E_OK;

    if(CRYPTO_DRIVER_UNINIT == Crypto_InitState)
    {
        (void)Det_ReportError((uint16)CRYPTO_MODULE_ID, CRYPTO_INSTANCE_ID, ServiceId, CRYPTO_E_UNINIT);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

	return RetVal;
}

/**
 * @brief     Check if the KeyId is out of range
 *
 * @param[in] KeyId: KeyId
 * @param[in] ServiceId: ApiId
 *
 * @return    Std_ReturnType
 * @retval    E_OK
 * @retval    E_NOT_OK
 *
 */
LOCAL_INLINE Std_ReturnType Crypto_CheckKeyId(uint32 KeyId, uint8 ServiceId)
{
	Std_ReturnType RetVal = (Std_ReturnType)E_OK;

    if(KeyId >= CRYPTO_NUMBER_OF_KEYS)
    {
        (void)Det_ReportError((uint16)CRYPTO_MODULE_ID, CRYPTO_INSTANCE_ID, ServiceId, CRYPTO_E_PARAM_HANDLE);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

	return RetVal;
}

/**
 * @brief     Check if the KeyElementId is out of range
 *
 * @param[in] KeyId: KeyId
 * @param[in] KeyElementId: Key element Id
 * @param[in] ServiceId: ApiId
 *
 * @return    Std_ReturnType
 * @retval    E_OK
 * @retval    E_NOT_OK
 *
 */
LOCAL_INLINE Std_ReturnType Crypto_CheckKeyElementId(uint32 KeyId, uint32 KeyElementId, uint8 ServiceId)
{
	Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    uint32 Loop;

    if (KeyId < CRYPTO_NUMBER_OF_KEYS)
    {
        for (Loop = 0U; Loop < Crypto_KeyList[KeyId].KeyElementNum; Loop++)
        {
            if (KeyElementId == Crypto_KeyList[KeyId].KeyElementListPtr[Loop]->ElementId)
            {
                RetVal = (Std_ReturnType)E_OK;
                break;
            }
        }
    }

    if((Std_ReturnType)E_NOT_OK == RetVal)
    {
        (void)Det_ReportError((uint16)CRYPTO_MODULE_ID, CRYPTO_INSTANCE_ID, ServiceId, CRYPTO_E_PARAM_HANDLE);
    }

	return RetVal;
}

/**
 * @brief     Check if the data pointer is NULL
 *
 * @param[in] DataPtr: Data pointer
 * @param[in] ServiceId: ApiId
 *
 * @return    Std_ReturnType
 * @retval    E_OK
 * @retval    E_NOT_OK
 *
 */
LOCAL_INLINE Std_ReturnType Crypto_CheckDataPtr(const uint8* DataPtr, uint8 ServiceId)
{
	Std_ReturnType RetVal = (Std_ReturnType)E_OK;

	if(NULL_PTR == DataPtr)
    {
        (void)Det_ReportError((uint16)CRYPTO_MODULE_ID, CRYPTO_INSTANCE_ID, ServiceId, CRYPTO_E_PARAM_POINTER);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

	return RetVal;
}

/**
 * @brief     Check if the data length is zero
 *
 * @param[in] DataLength: Data length
 * @param[in] ServiceId: ApiId
 *
 * @return    Std_ReturnType
 * @retval    E_OK
 * @retval    E_NOT_OK
 *
 */
LOCAL_INLINE Std_ReturnType Crypto_CheckDataLength(uint32 DataLength, uint8 ServiceId)
{
	Std_ReturnType RetVal = (Std_ReturnType)E_OK;

	if(0U == DataLength)
    {
        (void)Det_ReportError((uint16)CRYPTO_MODULE_ID, CRYPTO_INSTANCE_ID, ServiceId, CRYPTO_E_PARAM_VALUE);
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

	return RetVal;
}
#endif

/**
 * @brief      Copy data from SrcPtr to DesPtr.
 *
 * @param[out] DesPtr: Pointer to the destination data buffer.
 * @param[in]  SrcPtr: Pointer to the source data buffer.
 * @param[in]  Length: Length of data to be copied in bytes.
 *
 * @return     None
 *
 */
static void Crypto_MemCopy(uint8* DesPtr, const uint8* SrcPtr, uint32 Length)
{
    uint32 Loop;

    for (Loop = 0U; Loop < Length; Loop++)
    {
        *DesPtr = *SrcPtr;
        SrcPtr++;
        DesPtr++;
    }
}      

/**
 * @brief      Get key element index.
 *
 * @param[in]  CryptoKeyId: Key identification.
 * @param[in]  KeyElementId: Key element identification.
 * @param[out] KeyElementIndex: Key element index.
 *
 * @return     None
 * 
 */ 
static void Crypto_GetIndex(uint32 CryptoKeyId, uint32 KeyElementId, uint32 *KeyElementIndex)
{
    uint32 Loop;

    for (Loop = 0U; Loop < Crypto_KeyList[CryptoKeyId].KeyElementNum; Loop++)
    {
        if (KeyElementId == Crypto_KeyList[CryptoKeyId].KeyElementListPtr[Loop]->ElementId)
        {
            *KeyElementIndex = Loop;
            break;
        }
    }
}

/**
 * @brief      Check parameters for Key Element Copy operation.
 *
 * @param[in]  SrcKeyIndex: Source key index.
 * @param[in]  SrcElementIndex: Source key element index.
 * @param[in]  DesKeyIndex: Destination key index.
 * @param[in]  DesElementIndex: Destination key element index.
 *
 * @return     Std_ReturnType
 * @retval     E_OK
 * @retval     E_NOT_OK
 * @retval     CRYPTO_E_KEY_READ_FAIL
 * @retval     CRYPTO_E_KEY_WRITE_FAIL
 * @retval     CRYPTO_E_KEY_SIZE_MISMATCH
 * @retval     CRYPTO_E_KEY_EMPTY
 * 
 */
static Std_ReturnType Crypto_CheckKeyElementCopy(uint32 SrcKeyIndex, uint32 SrcElementIndex,
                                                 uint32 DesKeyIndex, uint32 DesElementIndex)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;

    if (*Crypto_KeyList[SrcKeyIndex].KeyElementListPtr[SrcElementIndex]->ElementActSize > 
        Crypto_KeyList[DesKeyIndex].KeyElementListPtr[DesElementIndex]->ElementMaxSize)
    {
        Ret = CRYPTO_E_KEY_SIZE_MISMATCH;
    }
    else if((*Crypto_KeyList[SrcKeyIndex].KeyElementListPtr[SrcElementIndex]->ElementActSize < 
             Crypto_KeyList[DesKeyIndex].KeyElementListPtr[DesElementIndex]->ElementMaxSize) &&
            (FALSE == Crypto_KeyList[DesKeyIndex].KeyElementListPtr[DesElementIndex]->ElementPartialAccess))
    {
        Ret = CRYPTO_E_KEY_SIZE_MISMATCH;
    }
    else if(CRYPTO_RA_DENIED == Crypto_KeyList[SrcKeyIndex].KeyElementListPtr[SrcElementIndex]->ElementReadAccess)
    {
        Ret = CRYPTO_E_KEY_READ_FAIL;
    }
    else if(CRYPTO_WA_DENIED == Crypto_KeyList[DesKeyIndex].KeyElementListPtr[DesElementIndex]->ElementWriteAccess)
    {
        Ret = CRYPTO_E_KEY_WRITE_FAIL;
    }
    else if(Crypto_KeyList[SrcKeyIndex].KeyElementListPtr[SrcElementIndex]->ElementReadAccess > 
            Crypto_KeyList[DesKeyIndex].KeyElementListPtr[DesElementIndex]->ElementReadAccess)
    {
        Ret = (Std_ReturnType)E_NOT_OK;
    }
    else if(0U == *Crypto_KeyList[SrcKeyIndex].KeyElementListPtr[SrcElementIndex]->ElementActSize)
    {
        Ret = CRYPTO_E_KEY_EMPTY;
    }
    else if((NULL_PTR == Crypto_KeyList[SrcKeyIndex].KeyElementListPtr[SrcElementIndex]->KeyElementPtr) ||
            (NULL_PTR == Crypto_KeyList[DesKeyIndex].KeyElementListPtr[DesElementIndex]->KeyElementPtr))
    {
        Ret = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        Ret = (Std_ReturnType)E_OK;
    }

    return Ret;
}

/**
 * @brief      Check parameters for Key Element Copy Partial operation.
 *
 * @param[in]  SrcKeyIndex: Source key index.
 * @param[in]  SrcElementIndex: Source key element index.
 * @param[in]  SrcOffset: This is the offset of the of the source key element indicating the start
 *             index of the copy operation.
 * @param[in]  DesOffset: This is the offset of the of the target key element indicating the start
 *             index of the copy operation.
 * @param[in]  CopyLength: Specifies the number of bytes that shall be copied.
 * @param[in]  DesKeyIndex: Destination key index.
 * @param[in]  DesElementIndex: Destination key element index.
 *
 * @return     Std_ReturnType
 * @retval     E_OK
 * @retval     E_NOT_OK
 * @retval     CRYPTO_E_KEY_READ_FAIL
 * @retval     CRYPTO_E_KEY_WRITE_FAIL
 * @retval     CRYPTO_E_KEY_SIZE_MISMATCH
 * @retval     CRYPTO_E_KEY_EMPTY
 * 
 */
static Std_ReturnType Crypto_CheckKeyElementCopyPartial(uint32 SrcKeyIndex, uint32 SrcElementIndex,
                                             uint32 SrcOffset, uint32 DesOffset, uint32 CopyLength, 
                                             uint32 DesKeyIndex, uint32 DesElementIndex)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;

    if(*Crypto_KeyList[SrcKeyIndex].KeyElementListPtr[SrcElementIndex]->ElementActSize < (SrcOffset + CopyLength))
    {
        Ret = CRYPTO_E_KEY_SIZE_MISMATCH;
    }
    else if(Crypto_KeyList[DesKeyIndex].KeyElementListPtr[DesElementIndex]->ElementMaxSize < (DesOffset + CopyLength))
    {
        Ret = CRYPTO_E_KEY_SIZE_MISMATCH;
    }
    else if(CRYPTO_RA_DENIED == Crypto_KeyList[SrcKeyIndex].KeyElementListPtr[SrcElementIndex]->ElementReadAccess)
    {
        Ret = CRYPTO_E_KEY_READ_FAIL;
    }
    else if(CRYPTO_WA_DENIED == Crypto_KeyList[DesKeyIndex].KeyElementListPtr[DesElementIndex]->ElementWriteAccess)
    {
        Ret = CRYPTO_E_KEY_WRITE_FAIL;
    }
    else if(Crypto_KeyList[SrcKeyIndex].KeyElementListPtr[SrcElementIndex]->ElementReadAccess > 
            Crypto_KeyList[DesKeyIndex].KeyElementListPtr[DesElementIndex]->ElementReadAccess)
    {
        Ret = (Std_ReturnType)E_NOT_OK;
    }
    else if(0U == *Crypto_KeyList[SrcKeyIndex].KeyElementListPtr[SrcElementIndex]->ElementActSize)
    {
        Ret = CRYPTO_E_KEY_EMPTY;
    }
    else if((NULL_PTR == Crypto_KeyList[SrcKeyIndex].KeyElementListPtr[SrcElementIndex]->KeyElementPtr) ||
            (NULL_PTR == Crypto_KeyList[DesKeyIndex].KeyElementListPtr[DesElementIndex]->KeyElementPtr))
    {
        Ret = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        Ret = (Std_ReturnType)E_OK;
    }

    return Ret;
}

/**
 * @brief      Check parameters and perform copy operation for Key Copy operation.
 *
 * @param[in]  SrcKeyIndex: Source key index.
 * @param[in]  DesKeyIndex: Destination key index.
 *
 * @return     Std_ReturnType
 * @retval     E_OK
 * @retval     E_NOT_OK
 * @retval     CRYPTO_E_KEY_READ_FAIL
 * @retval     CRYPTO_E_KEY_WRITE_FAIL
 * @retval     CRYPTO_E_KEY_SIZE_MISMATCH
 * @retval     CRYPTO_E_KEY_EMPTY
 * 
 */
static Std_ReturnType Crypto_CopyKeyElements(uint32 SrcKeyIndex, uint32 DesKeyIndex)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;
    uint32 SrcLoop;
    uint32 DesLoop;
    uint32 SrcElementNum;
    uint32 DesElementNum;

    SrcElementNum = Crypto_KeyList[SrcKeyIndex].KeyElementNum;
    DesElementNum = Crypto_KeyList[DesKeyIndex].KeyElementNum;

    if(SrcElementNum > DesElementNum)
    {
        Ret = (Std_ReturnType)E_NOT_OK; 
    }
    else
    {
        for(SrcLoop = 0U; SrcLoop < SrcElementNum; SrcLoop++)
        {
            for(DesLoop = 0U; DesLoop < DesElementNum; DesLoop++)
            {
                if(Crypto_KeyList[SrcKeyIndex].KeyElementListPtr[SrcLoop]->ElementId == 
                   Crypto_KeyList[DesKeyIndex].KeyElementListPtr[DesLoop]->ElementId)
                {
                    Ret = Crypto_CheckKeyElementCopy(SrcKeyIndex,SrcLoop, DesKeyIndex, DesLoop);
                    if ((Std_ReturnType)E_OK == Ret)
                    {
                        /* Clear key valid flag since it is changed */
                        CRYPTO_CLEARKEYSTATUS(DesKeyIndex);
                        
                        Crypto_MemCopy(Crypto_KeyList[DesKeyIndex].KeyElementListPtr[DesLoop]->KeyElementPtr, 
                        Crypto_KeyList[SrcKeyIndex].KeyElementListPtr[SrcLoop]->KeyElementPtr, 
                        *Crypto_KeyList[SrcKeyIndex].KeyElementListPtr[SrcLoop]->ElementActSize);
                        *Crypto_KeyList[DesKeyIndex].KeyElementListPtr[DesLoop]->ElementActSize = 
                        *Crypto_KeyList[SrcKeyIndex].KeyElementListPtr[SrcLoop]->ElementActSize;
                    }
                    break;
                }
            }

            if(DesElementNum == DesLoop)
            {
                Ret = (Std_ReturnType)E_NOT_OK;
                break;
            }
            else if ((Std_ReturnType)E_OK != Ret)
            {
                break;
            }
            else
            {
                /* do nothing */
            }
        }
    }

    return Ret;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
/**
 * @brief      Sets the given key element bytes to the key identified by cryptoKeyId.
 *
 * @param[in]  cryptoKeyId: Holds the identifier of the key whose key element shall be set. Range: 0..CRYPTO_NUMBER_OF_KEYS - 1.
 * @param[in]  keyElementId: Holds the identifier of the key element which shall be set. Range: Among the IDs of the elements referred by the key.
 * @param[in]  keyPtr: Holds the pointer to the key data which shall be set as key element.
 * @param[in]  keyLength: Contains the length of the key element in bytes. Range: 1..Maximum key element size by configuration.
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
                                    uint32 keyLength)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == CRYPTO_EXIST_KEYS)
    uint32 KeyElementIndex = CRYPTO_INVALID_KEY_ELEMENT_INDEX;
#if(STD_ON == CRYPTO_DEV_ERROR_DETECT)
	Ret = Crypto_CheckModuleState(CRYPTO_SID_KEYELEMENTSET);
	Ret |= Crypto_CheckKeyId(cryptoKeyId, CRYPTO_SID_KEYELEMENTSET);
	Ret |= Crypto_CheckKeyElementId(cryptoKeyId, keyElementId, CRYPTO_SID_KEYELEMENTSET);
	Ret |= Crypto_CheckDataPtr(keyPtr, CRYPTO_SID_KEYELEMENTSET);
    Ret |= Crypto_CheckDataLength(keyLength, CRYPTO_SID_KEYELEMENTSET);
	if (E_OK == Ret)
#endif  /* CRYPTO_DEV_ERROR_DETECT == STD_ON */
    {
        Crypto_GetIndex(cryptoKeyId, keyElementId, &KeyElementIndex);
 
        if(((keyLength < Crypto_KeyList[cryptoKeyId].KeyElementListPtr[KeyElementIndex]->ElementMaxSize) && 
            (FALSE == Crypto_KeyList[cryptoKeyId].KeyElementListPtr[KeyElementIndex]->ElementPartialAccess)) ||
            (keyLength > Crypto_KeyList[cryptoKeyId].KeyElementListPtr[KeyElementIndex]->ElementMaxSize))
        {
            Ret = CRYPTO_E_KEY_SIZE_MISMATCH;
        }
        else if((CRYPTO_WA_ALLOWED != Crypto_KeyList[cryptoKeyId].KeyElementListPtr[KeyElementIndex]->ElementWriteAccess) &&
                (CRYPTO_WA_ENCRYPTED != Crypto_KeyList[cryptoKeyId].KeyElementListPtr[KeyElementIndex]->ElementWriteAccess))
        {
            Ret = CRYPTO_E_KEY_WRITE_FAIL;
        }
        else if (NULL_PTR != Crypto_KeyList[cryptoKeyId].KeyElementListPtr[KeyElementIndex]->KeyElementPtr)
        {            
            /* Clear key valid flag since the key has been modified */
            CRYPTO_CLEARKEYSTATUS(cryptoKeyId);
        
            Crypto_MemCopy(Crypto_KeyList[cryptoKeyId].KeyElementListPtr[KeyElementIndex]->KeyElementPtr, keyPtr, keyLength);
            *Crypto_KeyList[cryptoKeyId].KeyElementListPtr[KeyElementIndex]->ElementActSize = keyLength;

            Ret = (Std_ReturnType)E_OK;
        }
        else
        {
            Ret = (Std_ReturnType)E_NOT_OK;
        }
    }
#else
    (void)cryptoKeyId;
    (void)keyElementId;
    (void)keyPtr;
    (void)keyLength;
#endif /* (STD_ON == CRYPTO_EXIST_KEYS)*/
    
    return Ret;
}

/**
 * @brief      Sets the key state of the key identified by cryptoKeyId to valid.
 *
 * @param[in]  cryptoKeyId: Holds the identifier of the key which shall be set to valid. Range: 0..CRYPTO_NUMBER_OF_KEYS - 1.
 *
 * @return     Std_ReturnType
 * @retval     E_OK
 * @retval     E_NOT_OK
 * @retval     CRYPTO_E_BUSY
 * 
 */
Std_ReturnType Crypto_KeySetValid(uint32 cryptoKeyId)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == CRYPTO_EXIST_KEYS)
    boolean BlockChanged = TRUE;
#if(CRYPTO_DEV_ERROR_DETECT == STD_ON)
	Ret = Crypto_CheckModuleState(CRYPTO_SID_KEYSETVALID);
	Ret |= Crypto_CheckKeyId(cryptoKeyId, CRYPTO_SID_KEYSETVALID);
	if (E_OK == Ret)
#endif  /* CRYPTO_DEV_ERROR_DETECT == STD_ON */
    {
        if(TRUE == Crypto_KeyJobInfo.ProcessingFlag)
        {
            Ret = CRYPTO_E_BUSY;
        }
        else if(0U != Crypto_KeyList[cryptoKeyId].RefNvBlockSize)
        {
            Crypto_KeyJobInfo.ProcessingFlag = TRUE;
            Crypto_KeyJobInfo.CurrentJobPtr = NULL_PTR;
            Crypto_KeyJobInfo.ProcessingKeyId = cryptoKeyId;
            Crypto_KeyJobInfo.RetryTimes = Crypto_KeyList[cryptoKeyId].RetryTimes;
            
            Ret = NvM_SetRamBlockStatus(Crypto_KeyList[cryptoKeyId].RefNvBlockId, BlockChanged);

            if(((Std_ReturnType)E_OK == Ret) && 
               (CRYPTO_NV_BLOCK_IMMEDIATE == Crypto_KeyList[cryptoKeyId].BlockProType))
            {
                Ret = NvM_WriteBlock(Crypto_KeyList[cryptoKeyId].RefNvBlockId, Crypto_KeyList[cryptoKeyId].PersistKeyElementsPtr);
            }  

            if((Std_ReturnType)E_OK != Ret)
            {
                Crypto_KeyJobInfo.WriteNvmFailFlag = TRUE;
            }
            else
            {
                /* Write request is successful and wait for the result from nvm */
                Crypto_KeyJobInfo.WriteNvmFailFlag = FALSE;
                Crypto_KeyJobInfo.NvmResultValidFlag = FALSE;
                
                /* Set crypto key status */
                CRYPTO_SETKEYSTATUS(cryptoKeyId, CRYPTO_KEYSTATUS_UPDATE_IN_PROGRESS);
            }
        }
        else
        {
            /* Set crypto key status */
            CRYPTO_SETKEYSTATUS(cryptoKeyId, CRYPTO_KEYSTATUS_VALID);
            Ret = (Std_ReturnType)E_OK;
        }
    }
#else
    (void)cryptoKeyId;
#endif /* (STD_ON == CRYPTO_EXIST_KEYS)*/

    return Ret;
}

/**
 * @brief      Sets invalid for the status of the key identified by cryptoKeyId.
 *
 * @param[in]  cryptoKeyId: Holds the identifier of the key for which the status shall be set to 
 *             invalid. Range: 0..CRYPTO_NUMBER_OF_KEYS - 1.
 *
 * @return     Std_ReturnType
 * @retval     E_OK
 * @retval     E_NOT_OK
 * @retval     CRYPTO_E_BUSY
 * 
 */
Std_ReturnType Crypto_KeySetInvalid(uint32 cryptoKeyId)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == CRYPTO_EXIST_KEYS)
#if(CRYPTO_DEV_ERROR_DETECT == STD_ON)
	Ret = Crypto_CheckModuleState(CRYPTO_SID_KEYSETINVALID);
	Ret |= Crypto_CheckKeyId(cryptoKeyId, CRYPTO_SID_KEYSETINVALID);
	if (E_OK == Ret)
#endif  /* CRYPTO_DEV_ERROR_DETECT == STD_ON */
    {
        /* Clear crypto key valid flag */
        CRYPTO_CLEARKEYSTATUS(cryptoKeyId);
        Ret = (Std_ReturnType)E_OK;
    }
#else
    (void)cryptoKeyId;
#endif /* (STD_ON == CRYPTO_EXIST_KEYS)*/

    return Ret;
}

/**
 * @brief      This interface shall be used to get a key element of the key identified by the crypto
 *             KeyId and store the key element in the memory location pointed by the result pointer. 
 *             Note: If the actual key element is directly mapped to flash memory, there could be a 
 *             bigger delay when calling this function (synchronous operation).
 *
 * @param[in]  cryptoKeyId: Holds the identifier of the key whose key element shall be returned. Range: 0..CRYPTO_NUMBER_OF_KEYS - 1.
 * @param[in]  keyElementId: Holds the identifier of the key element which shall be returned. Range: Among the IDs of the elements referred by the key.
 * @param[out] resultPtr: Holds the pointer of the buffer for the returned key element.
 * @param[inout] resultLengthPtr: Holds a pointer to a memory location in which the length information 
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
                                    uint32* resultLengthPtr)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == CRYPTO_EXIST_KEYS)
    uint32 KeyElementIndex = CRYPTO_INVALID_KEY_ELEMENT_INDEX;
#if(STD_ON == CRYPTO_DEV_ERROR_DETECT)
	Ret = Crypto_CheckModuleState(CRYPTO_SID_KEYELEMENTGET);
	Ret |= Crypto_CheckKeyId(cryptoKeyId, CRYPTO_SID_KEYELEMENTGET);
	Ret |= Crypto_CheckKeyElementId(cryptoKeyId, keyElementId, CRYPTO_SID_KEYELEMENTGET);
	Ret |= Crypto_CheckDataPtr(resultPtr, CRYPTO_SID_KEYELEMENTGET);
    Ret |= Crypto_CheckDataPtr((uint8*)resultLengthPtr, CRYPTO_SID_KEYELEMENTGET);
    Ret |= Crypto_CheckDataLength(*resultLengthPtr, CRYPTO_SID_KEYELEMENTGET);
	if (E_OK == Ret)
#endif /* STD_ON == CRYPTO_DEV_ERROR_DETECT*/
    {
        Crypto_GetIndex(cryptoKeyId, keyElementId, &KeyElementIndex);

        if(Crypto_KeyList[cryptoKeyId].KeyElementListPtr[KeyElementIndex]->ElementReadAccess > CRYPTO_RA_ENCRYPTED)
        {
            Ret = CRYPTO_E_KEY_READ_FAIL;
        }
        else if(*resultLengthPtr < *Crypto_KeyList[cryptoKeyId].KeyElementListPtr[KeyElementIndex]->ElementActSize)
        {
#if(STD_ON == CRYPTO_DEV_ERROR_DETECT)
            (void)Det_ReportError((uint16)CRYPTO_MODULE_ID, CRYPTO_INSTANCE_ID, CRYPTO_SID_KEYELEMENTGET, CRYPTO_E_SMALL_BUFFER);
#endif /* STD_ON == CRYPTO_DEV_ERROR_DETECT*/
            Ret = (Std_ReturnType)CRYPTO_E_SMALL_BUFFER;
        }
        else if (NULL_PTR != Crypto_KeyList[cryptoKeyId].KeyElementListPtr[KeyElementIndex]->KeyElementPtr)
        {
            Crypto_MemCopy(resultPtr, Crypto_KeyList[cryptoKeyId].KeyElementListPtr[KeyElementIndex]->KeyElementPtr, 
                                *Crypto_KeyList[cryptoKeyId].KeyElementListPtr[KeyElementIndex]->ElementActSize);
            *resultLengthPtr = *Crypto_KeyList[cryptoKeyId].KeyElementListPtr[KeyElementIndex]->ElementActSize;
            Ret = (Std_ReturnType)E_OK;
        }
        else
        {
            Ret = (Std_ReturnType)E_NOT_OK;
        }
    }
#else
    (void)cryptoKeyId;
    (void)keyElementId;
    (void)resultPtr;
    (void)resultLengthPtr;
#endif /* (STD_ON == CRYPTO_EXIST_KEYS)*/
    
    return Ret;
}

/**
 * @brief      Returns the key state of the key identified by cryptoKeyId.
 *
 * @param[in]  cryptoKeyId: Holds the identifier of the key for which the key state shall be 
 *             returned. Range: 0..CRYPTO_NUMBER_OF_KEYS - 1.
 * @param[out] keyStatusPtr: Contains the pointer to the data where the status of the key shall be 
 *             stored.
 *
 * @return     Std_ReturnType
 * @retval     E_OK
 * @retval     E_NOT_OK
 * 
 */
Std_ReturnType Crypto_KeyGetStatus(uint32 cryptoKeyId, Crypto_KeyStatusType* keyStatusPtr)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == CRYPTO_EXIST_KEYS)
#if(CRYPTO_DEV_ERROR_DETECT == STD_ON)
	Ret = Crypto_CheckModuleState(CRYPTO_SID_KEYGETSTATUS);
	Ret |= Crypto_CheckKeyId(cryptoKeyId, CRYPTO_SID_KEYGETSTATUS);
    Ret |= Crypto_CheckDataPtr((uint8*)keyStatusPtr, CRYPTO_SID_KEYGETSTATUS);
	if (E_OK == Ret)
#endif  /* CRYPTO_DEV_ERROR_DETECT == STD_ON */
    {
        /* Get crypto key status */
        *keyStatusPtr = *Crypto_KeyList[cryptoKeyId].KeyStatus;
        Ret = (Std_ReturnType)E_OK;
    }
#else
    (void)cryptoKeyId;
    (void)keyStatusPtr;
#endif /* (STD_ON == CRYPTO_EXIST_KEYS)*/

    return Ret;
}

/**
 * @brief      Copies a key element to another key element in the same crypto driver. Note: If the 
 *             actual key element is directly mapped to flash memory, there could be a bigger delay
 *             when calling this function (synchronous operation)
 *
 * @param[in]  cryptoKeyId: Holds the identifier of the key whose key element shall be the source
 *             element. Range: 0..CRYPTO_NUMBER_OF_KEYS - 1.
 * @param[in]  keyElementId: Holds the identifier of the key element which shall be the source for
 *             the copy operation. Range: Among the IDs of the elements referred by the key.
 * @param[in]  targetCryptoKeyId: Holds the identifier of the key whose key element shall be the 
 *             destination element. Range: 0..CRYPTO_NUMBER_OF_KEYS - 1.
 * @param[in]  targetKeyElementId: Holds the identifier of the key element which shall be the 
 *             destination for the copy operation. Range: Among the IDs of the elements referred by the target key.
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
                                     uint32 targetCryptoKeyId, uint32 targetKeyElementId)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == CRYPTO_EXIST_KEYS)
    uint32 SrcElementIndex = CRYPTO_INVALID_KEY_ELEMENT_INDEX;
    uint32 DesElementIndex = CRYPTO_INVALID_KEY_ELEMENT_INDEX;
#if(STD_ON == CRYPTO_DEV_ERROR_DETECT)
	Ret = Crypto_CheckModuleState(CRYPTO_SID_KEYELEMENTCOPY);
	Ret |= Crypto_CheckKeyId(cryptoKeyId, CRYPTO_SID_KEYELEMENTCOPY);
    Ret |= Crypto_CheckKeyId(targetCryptoKeyId, CRYPTO_SID_KEYELEMENTCOPY);
	Ret |= Crypto_CheckKeyElementId(cryptoKeyId, keyElementId, CRYPTO_SID_KEYELEMENTCOPY);
    Ret |= Crypto_CheckKeyElementId(targetCryptoKeyId,targetKeyElementId,CRYPTO_SID_KEYELEMENTCOPY);
	if (E_OK == Ret)
#endif  /* CRYPTO_DEV_ERROR_DETECT == STD_ON */
    {
        Crypto_GetIndex(cryptoKeyId, keyElementId, &SrcElementIndex);
        Crypto_GetIndex(targetCryptoKeyId, targetKeyElementId, &DesElementIndex);

        Ret = Crypto_CheckKeyElementCopy(cryptoKeyId,SrcElementIndex,targetCryptoKeyId, DesElementIndex);

        if((Std_ReturnType)E_OK == Ret)
        {
            /* Clear key valid flag since it is changed */
            CRYPTO_CLEARKEYSTATUS(targetCryptoKeyId);
            
            Crypto_MemCopy(Crypto_KeyList[targetCryptoKeyId].KeyElementListPtr[DesElementIndex]->KeyElementPtr, 
                           Crypto_KeyList[cryptoKeyId].KeyElementListPtr[SrcElementIndex]->KeyElementPtr, 
                           *Crypto_KeyList[cryptoKeyId].KeyElementListPtr[SrcElementIndex]->ElementActSize);
            *Crypto_KeyList[targetCryptoKeyId].KeyElementListPtr[DesElementIndex]->ElementActSize = 
            *Crypto_KeyList[cryptoKeyId].KeyElementListPtr[SrcElementIndex]->ElementActSize;
        }
    }
#else
    (void)cryptoKeyId;
    (void)keyElementId;
    (void)targetCryptoKeyId;
    (void)targetKeyElementId;
#endif /* (STD_ON == CRYPTO_EXIST_KEYS)*/

    return Ret;
}

/**
 * @brief      Copies a key element to another key element in the same crypto driver. The key
 *             ElementSourceOffset and keyElementCopyLength allows to copy just a part of the source
 *             key element into the destination. The offset of the target key is also specified with
 *             this function.
 *
 * @param[in]  cryptoKeyId: Holds the identifier of the key whose key element shall be the source
 *             element. Range: 0..CRYPTO_NUMBER_OF_KEYS - 1.
 * @param[in]  keyElementId: Holds the identifier of the key element which shall be the source for
 *             the copy operation. Range: Among the IDs of the elements referred by the key.
 * @param[in]  keyElementSourceOffset: This is the offset of the of the source key element
 *             indicating the start index of the copy operation. Range: 0..Actual key element size (set by user) - 1.
 * @param[in]  keyElementTargetOffset: This is the offset of the of the target key element 
 *             indicating the start index of the copy operation. Range: 0..Maximum key element size (by configuration) - 1.
 * @param[in]  keyElementCopyLength: Specifies the number of bytes that shall be copied. 
 *             Range: 1..Minor value between source element actual size and target element maximum size.
 * @param[in]  targetCryptoKeyId: Holds the identifier of the key whose key element shall be the 
 *             destination element. Range: 0..CRYPTO_NUMBER_OF_KEYS - 1.
 * @param[in]  targetKeyElementId: Holds the identifier of the key element which shall be the 
 *             destination for the copy operation. Range: Among the IDs of the elements referred by the target key.
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
                                            uint32 targetKeyElementId)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == CRYPTO_EXIST_KEYS)
    uint32 SrcElementIndex = CRYPTO_INVALID_KEY_ELEMENT_INDEX;
    uint32 DesElementIndex = CRYPTO_INVALID_KEY_ELEMENT_INDEX;
#if(STD_ON == CRYPTO_DEV_ERROR_DETECT)
	Ret = Crypto_CheckModuleState(CRYPTO_SID_KEYELEMENTCOPYPARTIAL);
	Ret |= Crypto_CheckKeyId(cryptoKeyId, CRYPTO_SID_KEYELEMENTCOPYPARTIAL);
    Ret |= Crypto_CheckKeyId(targetCryptoKeyId, CRYPTO_SID_KEYELEMENTCOPYPARTIAL);
	Ret |= Crypto_CheckKeyElementId(cryptoKeyId, keyElementId, CRYPTO_SID_KEYELEMENTCOPYPARTIAL);
    Ret |= Crypto_CheckKeyElementId(targetCryptoKeyId,targetKeyElementId,CRYPTO_SID_KEYELEMENTCOPYPARTIAL);
	if (E_OK == Ret)
#endif  /* CRYPTO_DEV_ERROR_DETECT == STD_ON */
    {
        Crypto_GetIndex(cryptoKeyId, keyElementId, &SrcElementIndex);
        Crypto_GetIndex(targetCryptoKeyId, targetKeyElementId, &DesElementIndex);

        Ret = Crypto_CheckKeyElementCopyPartial(cryptoKeyId, SrcElementIndex,keyElementSourceOffset,
                        keyElementTargetOffset, keyElementCopyLength, targetCryptoKeyId, DesElementIndex);
        if((Std_ReturnType)E_OK == Ret)
        {           
            /* Clear key valid flag since it is changed */
            CRYPTO_CLEARKEYSTATUS(targetCryptoKeyId);
        
            Crypto_MemCopy(&Crypto_KeyList[targetCryptoKeyId].KeyElementListPtr[DesElementIndex]->KeyElementPtr[keyElementTargetOffset], 
                           &Crypto_KeyList[cryptoKeyId].KeyElementListPtr[SrcElementIndex]->KeyElementPtr[keyElementSourceOffset], 
                           keyElementCopyLength);
            if(*Crypto_KeyList[targetCryptoKeyId].KeyElementListPtr[DesElementIndex]->ElementActSize <
               (keyElementTargetOffset + keyElementCopyLength))
            {
                *Crypto_KeyList[targetCryptoKeyId].KeyElementListPtr[DesElementIndex]->ElementActSize = 
                (keyElementTargetOffset + keyElementCopyLength);  
            }
        }
    }
#else
    (void)cryptoKeyId;
    (void)keyElementId;
    (void)keyElementSourceOffset;
    (void)keyElementTargetOffset;
    (void)keyElementCopyLength;
    (void)targetCryptoKeyId;
    (void)targetKeyElementId;
#endif /* (STD_ON == CRYPTO_EXIST_KEYS)*/

    return Ret;
}

/**
 * @brief      Copies a key with all its elements to another key in the same crypto driver.
 *
 * @param[in]  cryptoKeyId: Holds the identifier of the key whose key element shall be the source
 *             element. Range: 0..CRYPTO_NUMBER_OF_KEYS - 1.
 * @param[in]  targetCryptoKeyId: Holds the identifier of the key whose key element shall be the 
 *             destination element. Range: 0..CRYPTO_NUMBER_OF_KEYS - 1.
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
Std_ReturnType Crypto_KeyCopy(uint32 cryptoKeyId, uint32 targetCryptoKeyId)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == CRYPTO_EXIST_KEYS)
#if(STD_ON == CRYPTO_DEV_ERROR_DETECT)
	Ret = Crypto_CheckModuleState(CRYPTO_SID_KEYCOPY);
	Ret |= Crypto_CheckKeyId(cryptoKeyId, CRYPTO_SID_KEYCOPY);
    Ret |= Crypto_CheckKeyId(targetCryptoKeyId, CRYPTO_SID_KEYCOPY);
	if (E_OK == Ret)
#endif  /* CRYPTO_DEV_ERROR_DETECT == STD_ON */
    {
        Ret = Crypto_CopyKeyElements(cryptoKeyId, targetCryptoKeyId);
    }
#else
    (void)cryptoKeyId;
    (void)targetCryptoKeyId;
#endif /* (STD_ON == CRYPTO_EXIST_KEYS)*/

    return Ret;
}

/**
 * @brief        Used to retrieve information which key elements are available in a given key.
 *
 * @param[in]    cryptoKeyId: Holds the identifier of the key whose available element ids shall be
 *               exported. Range: 0..CRYPTO_NUMBER_OF_KEYS - 1.
 * @param[out]   keyElementIdsPtr: Contains the pointer to the array where the ids of the key 
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
                                       uint32* keyElementIdsLengthPtr)
{    
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == CRYPTO_EXIST_KEYS)
    uint32 Loop;
#if(STD_ON == CRYPTO_DEV_ERROR_DETECT)
	Ret = Crypto_CheckModuleState(CRYPTO_SID_KEYELEMENTIDSGET);
	Ret |= Crypto_CheckKeyId(cryptoKeyId, CRYPTO_SID_KEYELEMENTIDSGET);
    Ret |= Crypto_CheckDataPtr((uint8*)keyElementIdsPtr, CRYPTO_SID_KEYELEMENTIDSGET);
    Ret |= Crypto_CheckDataPtr((uint8*)keyElementIdsLengthPtr, CRYPTO_SID_KEYELEMENTIDSGET);
	if (E_OK == Ret)
#endif  /* CRYPTO_DEV_ERROR_DETECT == STD_ON */
    {
        if(*keyElementIdsLengthPtr < Crypto_KeyList[cryptoKeyId].KeyElementNum)
        {
#if(STD_ON == CRYPTO_DEV_ERROR_DETECT)
            (void)Det_ReportError((uint16)CRYPTO_MODULE_ID, CRYPTO_INSTANCE_ID, CRYPTO_SID_KEYELEMENTIDSGET, CRYPTO_E_SMALL_BUFFER);
#endif /* STD_ON == CRYPTO_DEV_ERROR_DETECT*/
            Ret = (Std_ReturnType)CRYPTO_E_SMALL_BUFFER;
        }
        else
        {
            for(Loop = 0U; Loop < Crypto_KeyList[cryptoKeyId].KeyElementNum; Loop++)
            {
                *keyElementIdsPtr = Crypto_KeyList[cryptoKeyId].KeyElementListPtr[Loop]->ElementId;
                keyElementIdsPtr++;
            }
            *keyElementIdsLengthPtr = Crypto_KeyList[cryptoKeyId].KeyElementNum;
            Ret = (Std_ReturnType)E_OK;
        }
    
    }
#else
    (void)cryptoKeyId;
    (void)keyElementIdsPtr;
    (void)keyElementIdsLengthPtr;
#endif /* (STD_ON == CRYPTO_EXIST_KEYS)*/

    return Ret;
}

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
Std_ReturnType Crypto_RandomSeed(uint32 cryptoKeyId, const uint8* seedPtr, uint32 seedLength)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;

    (void)cryptoKeyId;
    (void)seedPtr;
    (void)seedLength;
    
    return Ret;
}

/**
 * @brief      Generates new key material store it in the key identified by cryptoKeyId.
 *
 * @param[in]  cryptoKeyId: Holds the identifier of the key which is to be updated with the 
 *             generated value. Range: 0..CRYPTO_NUMBER_OF_KEYS - 1.
 * 
 * @return     Std_ReturnType
 * @retval     E_OK
 * @retval     E_NOT_OK
 * @retval     CRYPTO_E_BUSY
 * @retval     CRYPTO_E_KEY_EMPTY
 * @retval     CRYPTO_E_KEY_NOT_VALID
 * 
 */
Std_ReturnType Crypto_KeyGenerate(uint32 cryptoKeyId)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == CRYPTO_EXIST_KEYS)
    Trng_Drv_StatusType ResultStatus;
    uint32 KeyElementIndex = CRYPTO_INVALID_KEY_ELEMENT_INDEX;
#if(STD_ON == CRYPTO_DEV_ERROR_DETECT)
	Ret = Crypto_CheckModuleState(CRYPTO_SID_KEYGENERATE);
	Ret |= Crypto_CheckKeyId(cryptoKeyId, CRYPTO_SID_KEYGENERATE);
    Ret |= Crypto_CheckKeyElementId(cryptoKeyId, 1U, CRYPTO_SID_KEYGENERATE);
	if (E_OK == Ret)
#endif  /* CRYPTO_DEV_ERROR_DETECT == STD_ON */
    {
        Crypto_GetIndex(cryptoKeyId, 1U, &KeyElementIndex);
        ResultStatus = Trng_Drv_GetCtrDrbgRandomData(Crypto_KeyList[cryptoKeyId].KeyElementListPtr[KeyElementIndex]->KeyElementPtr,
                                                     Crypto_KeyList[cryptoKeyId].KeyElementListPtr[KeyElementIndex]->ElementMaxSize);
        if (TRNG_DRV_STATUS_NO_ERR == ResultStatus)
        {
            Ret = (Std_ReturnType)E_OK;
            *Crypto_KeyList[cryptoKeyId].KeyElementListPtr[KeyElementIndex]->ElementActSize = 
            Crypto_KeyList[cryptoKeyId].KeyElementListPtr[KeyElementIndex]->ElementMaxSize;
        }
        else
        {
            Ret = (Std_ReturnType)E_NOT_OK;
        }
    }
#else
    (void)cryptoKeyId;
#endif /* (STD_ON == CRYPTO_EXIST_KEYS)*/

    return Ret;
}

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
Std_ReturnType Crypto_KeyDerive(uint32 cryptoKeyId, uint32 targetCryptoKeyId)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;

    (void)cryptoKeyId;
    (void)targetCryptoKeyId;

    return Ret;
}

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
                                            uint32* publicValueLengthPtr)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;

    (void)cryptoKeyId;
    (void)publicValuePtr;
    (void)publicValueLengthPtr;

    return Ret;
}

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
                                            uint32 partnerPublicValueLength)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;

    (void)cryptoKeyId;
    (void)partnerPublicValuePtr;
    (void)partnerPublicValueLength;

    return Ret;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Crypto_KeyManagement */

/** @} end of group Crypto_Module */
