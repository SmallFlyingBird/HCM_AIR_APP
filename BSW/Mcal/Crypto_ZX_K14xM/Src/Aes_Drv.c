/**************************************************************************************************/
/**
 * @file      : Aes_Drv.c
 * @brief     : Aes low level driver source file
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

/** @addtogroup Aes_Drv
 *  @brief Aes low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Aes_Drv.h"
#include "Device_Regs.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
/* Published information */
#define AES_DRV_C_VENDOR_ID                   0x00B3U
#define AES_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define AES_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define AES_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define AES_DRV_C_SW_MAJOR_VERSION            1U
#define AES_DRV_C_SW_MINOR_VERSION            2U
#define AES_DRV_C_SW_PATCH_VERSION            2U

/* Check if current file and Aes_Drv.h are the same vendor */
#if (AES_DRV_C_VENDOR_ID != AES_DRV_H_VENDOR_ID)
    #error "Vendor ID of Aes_Drv.c and Aes_Drv.h are different"
#endif
/* Check if current file and Aes_Drv.h are the same Autosar version */
#if ((AES_DRV_C_AR_RELEASE_MAJOR_VERSION != AES_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (AES_DRV_C_AR_RELEASE_MINOR_VERSION != AES_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (AES_DRV_C_AR_RELEASE_REVISION_VERSION != AES_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Aes_Drv.c and Aes_Drv.h are different"
#endif
/* Check if current file and Aes_Drv.h are the same Software version */
#if ((AES_DRV_C_SW_MAJOR_VERSION != AES_DRV_H_SW_MAJOR_VERSION) || \
     (AES_DRV_C_SW_MINOR_VERSION != AES_DRV_H_SW_MINOR_VERSION) || \
     (AES_DRV_C_SW_PATCH_VERSION != AES_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Aes_Drv.c and Aes_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Device_Regs.h are the same Autosar version */
    #if ((AES_DRV_C_AR_RELEASE_MAJOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) || \
         (AES_DRV_C_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Aes_Drv.c and Device_Regs.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

#define AES_DRV_CMAC_PADDING_BYTE_MASK (0x80U)

#define AES_UTIL_REV(in, out)       __asm volatile("REV %0, %1" :"=r"((out)) :"r"((in)))
/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */
/**
 * @brief  AES operation mode configuration type
 *
 */
typedef enum
{
    AES_DRV_ECB_INIT       = 0x00U,          /*!< ECB init */
    AES_DRV_GCM_INIT       = 0x50U,          /*!< GCM init */
    AES_DRV_GCM_GHASH      = 0x51U,          /*!< GCM ghash */
    AES_DRV_GCM_UPDATE     = 0x52U,          /*!< GCM update */
    AES_DRV_GCM_FINISH_IV  = 0x53U,          /*!< GCM finish with iv */
    AES_DRV_GCM_FINISH     = 0x54U,          /*!< GCM finish */
    AES_DRV_CCM_INIT       = 0x60U,          /*!< CCM init */
    AES_DRV_CCM_MAC        = 0x61U,          /*!< CCM mac */
    AES_DRV_CCM_UPDATE     = 0x62U,          /*!< CCM update */
    AES_DRV_CCM_FINISH     = 0x63U,          /*!< CCM finish */
    AES_DRV_XTS_TWEAK_ENC  = 0x70U,          /*!< XTS tweak enc */
    AES_DRV_XTS_INIT       = 0x71U,          /*!< XTS init */
    AES_DRV_CMAC_INIT      = 0x80U,          /*!< CMAC init */
    AES_DRV_CMAC_UPDATE    = 0x81U,          /*!< CMAC update */
    AES_DRV_CMAC_FINISH_K1 = 0x82U,          /*!< CMAC finish K1 */
    AES_DRV_CMAC_FINISH_K2 = 0x83U           /*!< CMAC finish K2 */
} Aes_Drv_OptModeType;
/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */
#define CRYPTO_START_SEC_CONST_PTR
#include "Crypto_MemMap.h"
/**
 *  @brief AES peripheral base address array
 */
static const Reg_Aes_BfType * const Aes_Drv_AesRegBfPtr = (Reg_Aes_BfType *) AES_BASE_ADDR;
static Reg_Aes_WType *const Aes_Drv_AesRegWPtr = (Reg_Aes_WType *) AES_BASE_ADDR;

#define CRYPTO_STOP_SEC_CONST_PTR
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_VAR_INIT_8
#include "Crypto_MemMap.h"
static boolean Aes_Drv_CmacAlignedFlag = FALSE;
static boolean Aes_Drv_GcmAadEndFlag = TRUE;
static boolean Aes_Drv_GcmDataAlignedFlag = FALSE;
static boolean Aes_Drv_CcmDataAlignedFlag = FALSE;
#define CRYPTO_STOP_SEC_VAR_INIT_8
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_VAR_CLEARED_32
#include "Crypto_MemMap.h"
static uint32 Aes_Drv_GcmAadLen;
static uint32 Aes_Drv_GcmDataLen;
#define CRYPTO_STOP_SEC_VAR_CLEARED_32
#include "Crypto_MemMap.h"
/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
static void Aes_Drv_CopyDataBlock(const uint8 *DataInPtr, uint8 *DataOutPtr, uint8 DataLen);
static void Aes_Drv_WriteKey(const uint8 *KeyPtr);
static void Aes_Drv_WriteInitVector(const uint8 *IvPtr);
static void Aes_Drv_WriteGcmInitVector(const uint8 *IvPtr);
static void Aes_Drv_WriteData(const uint8 *InputDataPtr);
static void Aes_Drv_ReadData(uint8 *OutputDataPtr, uint32 DataLen);
static void Aes_Drv_Configure(Aes_Drv_OptModeType OptMode, 
                              Aes_Drv_CryptFunctionType FunctionType, uint32 BlockSize);
static Aes_Drv_StatusType Aes_Drv_StartOperation(void);
static Aes_Drv_StatusType Aes_Drv_ProcessGcmCcmData(const uint8 *InputDataPtr, 
                                                    Aes_Drv_OptModeType OptMode, 
                                                    Aes_Drv_CryptFunctionType FunctionType,
                                                    uint32 BlockSize);
static Aes_Drv_StatusType Aes_Drv_GetStatus(void);
static Aes_Drv_StatusType Aes_Drv_Start96BitsIvGcm(const uint8 *KeyPtr, const uint8 *IvPtr, 
                                                   Aes_Drv_CryptFunctionType FunctionType);
static Aes_Drv_StatusType Aes_Drv_StartNon96BitsIvGcm(const uint8 *KeyPtr, const uint8 *IvPtr, 
                                              uint32 IvLen, Aes_Drv_CryptFunctionType FunctionType);
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
static boolean AES_Drv_CheckCcmLengthPara(uint32 IvLen, uint32 InputLen, uint32 TagLen);
#endif
static void Aes_Drv_GenerateInitBlock(const uint8 *IvPtr, uint32 IvLen, uint32 InputLen, 
                                      uint32 AadLen, uint32 TagLen, uint8 *CtrB0Ptr, uint8 *B0Ptr);
static Aes_Drv_StatusType Aes_Drv_StartCcm(const uint8 *KeyPtr, const uint8 *IvPtr, uint32 IvLen,
             uint32 InputLen, uint32 AadLen, uint32 TagLen, Aes_Drv_CryptFunctionType FunctionType);
static Aes_Drv_StatusType Aes_Drv_UpdateCcmAad(const uint8 *AadPtr, uint32 AadLength, 
                                               Aes_Drv_CryptFunctionType FunctionType);
static Aes_Drv_StatusType Aes_Drv_UpdateCcmData(const uint8 *InputDataPtr, uint32 InputLength, 
                                      uint8 *OutputDataPtr, Aes_Drv_CryptFunctionType FunctionType);
static Aes_Drv_StatusType Aes_Drv_FinishCcm(const uint8 *InputDataPtr, uint32 InputLength, 
                                            const uint8 *AadDataPtr, uint32 AadLength,
                                            uint8 *OutputDataPtr, uint8 *TagPtr, uint32 TagLength, 
                                            Aes_Drv_CryptFunctionType FunctionType);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
/**
 * @brief      Copy the data block.
 *
 * @param[in]  DataInPtr: The pointer to the input data
 * @param[out] DataOutPtr: The pointer to the output data
 * @param[in]  DataLen: Length in bytes to be copied
 *
 * @return     None
 * 
 */
static void Aes_Drv_CopyDataBlock(const uint8 *DataInPtr, uint8 *DataOutPtr, uint8 DataLen)
{
    uint8 Count;
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT((NULL_PTR != DataInPtr) || (0U == DataLen));
    MCALLIB_DEV_ASSERT((NULL_PTR != DataOutPtr) || (0U == DataLen));
#endif
    for (Count = 0U; Count < DataLen; Count++)
    {
        DataOutPtr[Count] = DataInPtr[Count];
    }

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif    
}

/**
 * @brief     Write the key for AES operation.
 *
 * @param[in] KeyPtr: Pointer to the value of the key to be written into AES module
 *
 * @return    None
 * 
 */
static void Aes_Drv_WriteKey(const uint8 *KeyPtr)
{
    volatile uint8 *DataReg = (volatile uint8 *)&(Aes_Drv_AesRegWPtr->AES_KEY0);
    uint8 Loop;
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != KeyPtr);
#endif

    for(Loop = 0U; Loop < 16U; Loop++)
    {
        DataReg[Loop] = KeyPtr[15U - Loop];
    }

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif    
}

/**
 * @brief     Write the initial vector for AES operation
 *
 * @param[in] IvPtr: Pointer to the value of the initial vector to be written into AES module
 *
 * @return    None
 * 
 */
static void Aes_Drv_WriteInitVector(const uint8 *IvPtr)
{
    volatile uint8 *DataReg = (volatile uint8 *)&(Aes_Drv_AesRegWPtr->AES_IV0);
    uint8 Loop;
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != IvPtr);
#endif

    for(Loop = 0U; Loop < 16U; Loop++)
    {
        DataReg[Loop] = IvPtr[15U - Loop];
    }

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif    
}

/**
 * @brief     Write the GCM initial vector for AES operation
 *
 * @param[in] IvPtr: Pointer to the value of the GCM initial vector to be written into AES module
 *
 * @return    None
 * 
 */
static void Aes_Drv_WriteGcmInitVector(const uint8 *IvPtr)
{
    volatile uint8 *DataReg = (volatile uint8 *)&(Aes_Drv_AesRegWPtr->AES_IV0);
    uint8 Loop;
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != IvPtr);
#endif

    for(Loop = 0U; Loop < 16U; Loop++)
    {
        if (Loop < 4U)
        {
            DataReg[Loop] = 0U;
        }
        else
        {
            DataReg[Loop] = IvPtr[15U - Loop];
        }
    }

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif    
}

/**
 * @brief     Write the input data for AES operation
 *
 * @param[in] InputDataPtr: Pointer to the value of the input data to be written into AES module
 *
 * @return    None
 */
static void Aes_Drv_WriteData(const uint8 *InputDataPtr)
{
    volatile uint8 *DataReg = (volatile uint8 *)&(Aes_Drv_AesRegWPtr->AES_DATA_I0);
    uint8 Loop;
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != InputDataPtr);
#endif

    /* Write the input data value into the AES data input registers */
    for(Loop = 0U; Loop < 16U; Loop++)
    {
        DataReg[Loop] = InputDataPtr[15U - Loop];
    }

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif    
}

/**
 * @brief      Read the output data of AES operation
 *
 * @param[out] OutputDataPtr: Pointer to the value of the output data
 * @param[in]  DataLen: Data length in bytes
 *
 * @return     None
 * 
 */
static void Aes_Drv_ReadData(uint8 *OutputDataPtr, uint32 DataLen)
{
    uint8 Loop;
    uint32 TempData[4U] = {0};
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != OutputDataPtr);
#endif
    AES_UTIL_REV(Aes_Drv_AesRegWPtr->AES_DATA_O3, TempData[0]);
    AES_UTIL_REV(Aes_Drv_AesRegWPtr->AES_DATA_O2, TempData[1]);
    AES_UTIL_REV(Aes_Drv_AesRegWPtr->AES_DATA_O1, TempData[2]);
    AES_UTIL_REV(Aes_Drv_AesRegWPtr->AES_DATA_O0, TempData[3]);
 
    /* Read the output data value from the AES data output registers */
    for(Loop = 0U; Loop < DataLen; Loop++)
    {
        OutputDataPtr[Loop] = ((uint8*)TempData)[Loop];
    }

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif    
}

/**
 * @brief     Configure the AES operation
 *
 * @param[in] OptMode: AES operation mode
 * @param[in] FunctionType: AES encryption or decryption
 * @param[in] BlockSize: Block size in bits
 *
 * @return    None
 * 
 */
static void Aes_Drv_Configure(Aes_Drv_OptModeType OptMode, 
                              Aes_Drv_CryptFunctionType FunctionType, uint32 BlockSize)
{
    uint32 ConfigData = 0U;

    ConfigData = ((uint32)FunctionType & 1U) | ((uint32)OptMode << 8U) | ((BlockSize & 0xFFU) << 16U);
    Aes_Drv_AesRegWPtr->AES_CONFIG = ConfigData;
}

/**
 * @brief     Start an AES operation
 *
 * @param[in] None
 *
 * @return    Aes_Drv_StatusType
 * 
 */
static Aes_Drv_StatusType Aes_Drv_StartOperation(void)
{
    Aes_Drv_StatusType Ret = AES_DRV_STATUS_NO_ERR;

    if (1U != Aes_Drv_AesRegBfPtr->AES_STATUS.R)
    {
        Ret = AES_DRV_STATUS_BUSY_ERROR;
    }
    else
    {
        /* Start the AES operation */
        Aes_Drv_AesRegWPtr->AES_CONTROL = 1U;

        /* Get AES module status */
        Ret = Aes_Drv_GetStatus();
    }

    return Ret;
}

/**
 * @brief     Process GCM or CCM data
 *
 * @param[in] InputDataPtr: Pointer to the data to be processed
 * @param[in] OptMode: AES operation mode
 * @param[in] FunctionType: AES encryption or decryption
 * @param[in] BlockSize: Block size in bits
 * 
 * @return    Aes_Drv_StatusType
 * 
 */
static Aes_Drv_StatusType Aes_Drv_ProcessGcmCcmData(const uint8 *InputDataPtr, 
                                                    Aes_Drv_OptModeType OptMode, 
                                                    Aes_Drv_CryptFunctionType FunctionType,
                                                    uint32 BlockSize)
{
    Aes_Drv_StatusType Ret = AES_DRV_STATUS_NO_ERR;
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != InputDataPtr);
#endif

    /* Write the input data for the operation */
    Aes_Drv_WriteData(InputDataPtr);

    /* Setup the configuration for the operation */
    Aes_Drv_Configure(OptMode, FunctionType, BlockSize);

    /* Trigger the start of the operation */
    Ret = Aes_Drv_StartOperation();

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif    

    return Ret;
}

/**
 * @brief     Get the execution status of an AES operation
 *
 * @param[in] None
 *
 * @return    Aes_Drv_StatusType
 * 
 */
static Aes_Drv_StatusType Aes_Drv_GetStatus(void)
{
    Aes_Drv_StatusType Ret = AES_DRV_STATUS_NO_ERR;    
#if (STD_ON == AES_DRV_TIMEOUT_SUPERVISION_ENABLED)
    uint32 AesCurrentTicks = 0U;
    uint32 AesElapsedTicks = 0U;
    uint32 AesTimeoutTicks = 0U;
    uint32 ElapsedTicks = 0U;

    (void)McalLib_GetCounterValue(AES_DRV_TIMEOUT_TYPE, &AesCurrentTicks);
    AesElapsedTicks = 0U;
    AesTimeoutTicks = McalLib_MicroSecToTicks(AES_DRV_TIMEOUT_TYPE, AES_DRV_TIMEOUT_VALUE);
    while((FALSE == Aes_Drv_AesRegBfPtr->AES_STATUS.R) && (AesElapsedTicks < AesTimeoutTicks))
    {
        (void)McalLib_GetElapsedValue(AES_DRV_TIMEOUT_TYPE, &AesCurrentTicks, &ElapsedTicks);
        AesElapsedTicks += ElapsedTicks;
    }
    
    if(TRUE == Aes_Drv_AesRegBfPtr->AES_STATUS.R)
    {
        Ret = (Aes_Drv_StatusType)Aes_Drv_AesRegBfPtr->AES_STATUS.ERR;
    }
    else
    {
        Ret = AES_DRV_STATUS_TIMEOUT;
    }
#else
    while(FALSE == Aes_Drv_AesRegBfPtr->AES_STATUS.R)
    {
        /* do nothing */
    }
#endif

    return Ret;
}

/**
 * @brief     Initialize an GCM operation with 96-bits initial vector
 *
 * @param[in] KeyPtr: Pointer to the key
 * @param[in] IvPtr: Pointer to the initial vector
 * @param[in] FunctionType: AES encryption or decryption
 *
 * @return    Aes_Drv_StatusType
 * 
 */
static Aes_Drv_StatusType Aes_Drv_Start96BitsIvGcm(const uint8 *KeyPtr, const uint8 *IvPtr, 
                                                   Aes_Drv_CryptFunctionType FunctionType)
{
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != KeyPtr);
    MCALLIB_DEV_ASSERT(NULL_PTR != IvPtr);
#endif
    /* Write the key for the operation */
    Aes_Drv_WriteKey(KeyPtr);

    /* Write the GCM initial vector for the operation */
    Aes_Drv_WriteGcmInitVector(IvPtr);

    /* Setup the configuration for the operation */
    Aes_Drv_Configure(AES_DRV_GCM_INIT, FunctionType, 0x80U);

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return Aes_Drv_StartOperation();
}

/**
 * @brief     Initialize an GCM operation with non-96-bits initial vector
 *
 * @param[in] KeyPtr: Pointer to the key
 * @param[in] IvPtr: Pointer to the initial vector
 * @param[in] IvLen: Length of initial vector in bits
 * @param[in] FunctionType: AES encryption or decryption
 *
 * @return    Aes_Drv_StatusType
 * 
 */
static Aes_Drv_StatusType Aes_Drv_StartNon96BitsIvGcm(const uint8 *KeyPtr, const uint8 *IvPtr, 
                                               uint32 IvLen, Aes_Drv_CryptFunctionType FunctionType)
{
    Aes_Drv_StatusType Ret = AES_DRV_STATUS_NO_ERR;
    uint32 CountBlock;
    uint8 Loop;
    uint32 BlockNum = IvLen / 128U;
    uint8 LastBlockLength = (uint8)(IvLen % 128U);
    uint8 BytesNum = (LastBlockLength / 8U);
    uint8 LastByteLength = (LastBlockLength % 8U);
    uint8 LastDataCopy[16U] = {0};
    uint8 LenAsInput[16U] = {0};
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != KeyPtr);
    MCALLIB_DEV_ASSERT(NULL_PTR != IvPtr);
    MCALLIB_DEV_ASSERT((96U != IvLen) && (0U != IvLen));
#endif
    /* Write the key for the operation */
    Aes_Drv_WriteKey(KeyPtr);
    /* Setup the configuration for the operation */
    Aes_Drv_Configure(AES_DRV_GCM_INIT, FunctionType, 0x80U);
    Ret =  Aes_Drv_StartOperation();
    
    if (AES_DRV_STATUS_NO_ERR == Ret)
    {
        for(CountBlock = 0U; CountBlock < BlockNum; CountBlock++)
        {
            Ret = Aes_Drv_ProcessGcmCcmData(&IvPtr[16U * CountBlock], AES_DRV_GCM_GHASH, FunctionType, 0x80U);
            if(AES_DRV_STATUS_NO_ERR != Ret)
            {
                break;
            }
        }

        if((AES_DRV_STATUS_NO_ERR == Ret) && (0U != LastBlockLength))
        {
            /* Copy the last data block */
            Aes_Drv_CopyDataBlock(&IvPtr[16U * CountBlock], LastDataCopy, BytesNum);
            LastDataCopy[BytesNum] = IvPtr[(16U * CountBlock) + BytesNum] & ((1U << LastByteLength) - 1U);
            Ret = Aes_Drv_ProcessGcmCcmData(LastDataCopy, AES_DRV_GCM_GHASH, FunctionType, 0x80U);
        }

        if(AES_DRV_STATUS_NO_ERR == Ret)
        {
            /* Process length data via GHASH */
            for (Loop = 12U; Loop < 16U; Loop++)
            {
                LenAsInput[Loop] = ((uint8*)(&IvLen))[15U - Loop];
            }
            Ret = Aes_Drv_ProcessGcmCcmData(LenAsInput, AES_DRV_GCM_GHASH, FunctionType, 0x80U);
        }

        if(AES_DRV_STATUS_NO_ERR == Ret)
        {
            /* Setup the configuration for the operation */
            Aes_Drv_Configure(AES_DRV_GCM_FINISH_IV, FunctionType, 0x80U);

            /* Trigger the start of the operation */
            Ret = Aes_Drv_StartOperation();
        }
    }

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif

    return Ret;
}

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
/**
 * @brief     Check length parameters for CCM to generate B0 and CtrB0 
 *
 * @param[in] IvLen: The length of the IV in bytes
 * @param[in] InputLen: The length of the input data in bytes
 * @param[in] TagLen: The length of the tag in bytes
 *
 * @return    boolean   
 *
 */
static boolean AES_Drv_CheckCcmLengthPara(uint32 IvLen, uint32 InputLen, uint32 TagLen)
{
    boolean Ret = TRUE;
    uint32 TempLen = 15U - IvLen;

    /* IvLen is an element of   {7, 8, 9, 10, 11, 12, 13}
     * TagLen is an element of  {4, 6, 8, 10, 12, 14, 16}
     */
    if ((IvLen < 7U) || (IvLen > 13U))
    {
        Ret = FALSE;
    }

    if (((TempLen == 2U) && (InputLen > 0xFFFFU)) || ((TempLen == 3U) && (InputLen > 0xFFFFFFU)))
    {
        Ret = FALSE;
    }

    if ((TagLen < 4U) || (TagLen > 16U))
    {
        Ret = FALSE;
    }

    return Ret;
}
#endif

/**
 * @brief      Generate initial CtrB0 and B0 block for CCM
 *
 * @param[in]  IvPtr: Pointer to the initial vector
 * @param[in]  IvLen: Length of the initial vector in bytes
 * @param[in]  InputLen: Total length of the input data in bytes
 * @param[in]  AadLen: Total length of the AAD data in bytes
 * @param[in]  TagLen: Tag length in bytes
 * @param[out] CtrB0Ptr: Pointer to the CtrB0 Block
 * @param[out] B0Ptr: Pointer to the B0 Block
 *
 * @return     Aes_Drv_StatusType
 * 
 */
static void Aes_Drv_GenerateInitBlock(const uint8 *IvPtr, uint32 IvLen, uint32 InputLen, 
                                      uint32 AadLen, uint32 TagLen, uint8 *CtrB0Ptr, uint8 *B0Ptr)
{
    uint8 Loop;
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    boolean Ret = AES_Drv_CheckCcmLengthPara(IvLen, InputLen, TagLen);

    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(TRUE == Ret);
#endif

    B0Ptr[0U] = (14U - (uint8)IvLen) | ((((uint8)TagLen - 2U) / 2U) << 3U) | ((uint8)(AadLen > 0U) << 6U);
    CtrB0Ptr[0U] = (14U - (uint8)IvLen);

    for (Loop = 0U; Loop < IvLen; Loop++)
    {
        B0Ptr[Loop + 1U] = IvPtr[Loop];
        CtrB0Ptr[Loop + 1U] = IvPtr[Loop];
    }

    for (Loop = 15U; Loop > IvLen; Loop--)
    {
        B0Ptr[Loop] = (uint8)(((uint64)InputLen >> (8U * (15U - Loop))) & 0xFFU);
    }

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif    
}

/**
 * @brief      Initialize a CCM operation
 *
 * @param[in]  KeyPtr: Pointer to the key
 * @param[in]  IvPtr: Pointer to the initial vector
 * @param[in]  IvLen: Length of the initial vector in bytes
 * @param[in]  InputLen: Total length of the input data in bytes
 * @param[in]  AadLen: Total length of the AAD data in bytes
 * @param[in]  TagLen: Tag length in bytes
 * @param[in]  FunctionType: AES encryption or decryption
 *
 * @return     Aes_Drv_StatusType
 * 
 */
static Aes_Drv_StatusType Aes_Drv_StartCcm(const uint8 *KeyPtr, const uint8 *IvPtr, uint32 IvLen,
              uint32 InputLen, uint32 AadLen, uint32 TagLen, Aes_Drv_CryptFunctionType FunctionType)
{
    Aes_Drv_StatusType Ret = AES_DRV_STATUS_NO_ERR;
    uint8 CtrB0[16U] = {0};
    uint8 B0[16U] = {0};
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != KeyPtr);
    MCALLIB_DEV_ASSERT(NULL_PTR != IvPtr);
    MCALLIB_DEV_ASSERT(0U != IvLen);
#endif

    Aes_Drv_CcmDataAlignedFlag = TRUE;

    /* Write the key for the operation */
    Aes_Drv_WriteKey(KeyPtr);

    /* Generate initial CtrB0 and B0 block */
    Aes_Drv_GenerateInitBlock(IvPtr, IvLen, InputLen, AadLen, TagLen, CtrB0, B0);

    /* Write CtrB0 to IV reg */
    Aes_Drv_WriteInitVector(CtrB0);

    /* Process B0 for CCM init */
    Ret = Aes_Drv_ProcessGcmCcmData(B0, AES_DRV_CCM_INIT, FunctionType, 0x80U);

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif    

    return Ret;
}

/**
 * @brief     Update CCM AAD data
 *
 * @param[in] AadPtr: Pointer to the AAD data block
 * @param[in] AadLength: AAD data length in bytes
 * @param[in] FunctionType: AES encryption or decryption
 *
 * @return    Aes_Drv_StatusType
 * 
 */
static Aes_Drv_StatusType Aes_Drv_UpdateCcmAad(const uint8 *AadPtr, uint32 AadLength, 
                                               Aes_Drv_CryptFunctionType FunctionType)
{
    Aes_Drv_StatusType Ret = AES_DRV_STATUS_NO_ERR;
    uint32 BlockNum;
    uint32 CountBlock, Count;
    uint8 LastDataLength;
    uint8 FirstDataBlock[16U] = {0};
    uint8 LastDataCopy[16U] = {0};
    uint32 PadLen = 0U;
    uint32 TempLen;
    const uint8 *DataPtr;
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != AadPtr);
    MCALLIB_DEV_ASSERT(0U != AadLength);
#endif

    if (0xFF00U > AadLength)
    {
        FirstDataBlock[0] = (uint8)(AadLength >> 8U);
        FirstDataBlock[1] = (uint8)(AadLength & 0xFFU);
        PadLen = 2U;
    }
    else
    {
        FirstDataBlock[0] = 0xFFU;
        FirstDataBlock[1] = 0xFEU;
        FirstDataBlock[2] = (uint8)(AadLength >> 24U);
        FirstDataBlock[3] = (uint8)((AadLength >> 16U) & 0xFFU);
        FirstDataBlock[4] = (uint8)((AadLength >> 8U) & 0xFFU);
        FirstDataBlock[5] = (uint8)(AadLength & 0xFFU);
        PadLen = 6U;
    }

    if (AadLength < (16U - PadLen))
    {
        TempLen = AadLength;
        BlockNum = 0U;
        LastDataLength = 0U;
    }
    else
    {
        TempLen = (16U - PadLen);
        BlockNum = ((AadLength + PadLen) / 16U) - 1U;
        LastDataLength = (uint8)((AadLength + PadLen)  % 16U);
    }

    for(Count = 0U; Count < TempLen; Count++)
    {
        FirstDataBlock[PadLen + Count] = AadPtr[Count];
    }

    /* Process first data block */
    Ret = Aes_Drv_ProcessGcmCcmData(FirstDataBlock, AES_DRV_CCM_MAC, FunctionType, 0x80U);
    
    if(AES_DRV_STATUS_NO_ERR == Ret)
    {
        DataPtr = &AadPtr[Count];
        for(CountBlock = 0U; CountBlock < BlockNum; CountBlock++)
        {
            Ret = Aes_Drv_ProcessGcmCcmData(&DataPtr[16U * CountBlock], AES_DRV_CCM_MAC, 
                                            FunctionType, 0x80U);
            if(AES_DRV_STATUS_NO_ERR != Ret)
            {
                break;
            }
        }
    }

    if((AES_DRV_STATUS_NO_ERR == Ret) && (0U != LastDataLength))
    {
        /* Copy the last data block */
        Aes_Drv_CopyDataBlock(&DataPtr[16U * CountBlock], LastDataCopy, LastDataLength);
        /* Process last data block */
        Ret = Aes_Drv_ProcessGcmCcmData(LastDataCopy, AES_DRV_CCM_MAC, FunctionType, 0x80U);
    }

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif    

    return Ret;
}

/**
 * @brief      Update CCM message data
 *
 * @param[in]  InputDataPtr: Pointer to the input data block
 * @param[in]  InputLength: Data length in bytes
 * @param[out] OutputDataPtr: Pointer to the output data block
 * @param[in]  FunctionType: AES encryption or decryption
 *
 * @return     Aes_Drv_StatusType
 * 
 */
static Aes_Drv_StatusType Aes_Drv_UpdateCcmData(const uint8 *InputDataPtr, uint32 InputLength, 
                                       uint8 *OutputDataPtr, Aes_Drv_CryptFunctionType FunctionType)
{
    Aes_Drv_StatusType Ret = AES_DRV_STATUS_NO_ERR;
    uint32 BlockNum = (InputLength / 16U);
    uint32 CountBlock;
    uint8 LastDataLength = (uint8)(InputLength % 16U);
    uint8 LastDataCopy[16U] = {0};
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(0U != InputLength);
    MCALLIB_DEV_ASSERT(NULL_PTR != InputDataPtr);
    MCALLIB_DEV_ASSERT(NULL_PTR != OutputDataPtr);
#endif

    if (FALSE == Aes_Drv_CcmDataAlignedFlag)
    {
        Ret = AES_DRV_STATUS_INPUT_ERROR;
    }
    else
    {
        /* Process the input data */
        for(CountBlock = 0U; CountBlock < BlockNum; CountBlock++)
        {
            Ret = Aes_Drv_ProcessGcmCcmData(&InputDataPtr[16U * CountBlock], AES_DRV_CCM_UPDATE, 
                                            FunctionType, 0x80U);
            if(AES_DRV_STATUS_NO_ERR == Ret)
            {
                /* Read out the output value */
                Aes_Drv_ReadData(&OutputDataPtr[16U * CountBlock], 16U);
            }
            else
            {
                break;
            }
        }

        if((AES_DRV_STATUS_NO_ERR == Ret) && (0U != LastDataLength))
        {
            /* Set data aligned flag to FALSE, indicating that no CCM data can be fed any more */
            Aes_Drv_CcmDataAlignedFlag = FALSE;
            
            /*Copy the last data block*/
            Aes_Drv_CopyDataBlock(&InputDataPtr[16U * CountBlock], LastDataCopy, LastDataLength);
            Ret = Aes_Drv_ProcessGcmCcmData(LastDataCopy, AES_DRV_CCM_UPDATE, 
                                            FunctionType, 8U * (uint32)LastDataLength);
            if(AES_DRV_STATUS_NO_ERR == Ret)
            {
                /* Read out the output value */
                Aes_Drv_ReadData(&OutputDataPtr[16U * CountBlock], LastDataLength);
            }
        }
    }

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif    

    return Ret;
}

/**
 * @brief     Finish a CCM operation and read out the text data and tag
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
static Aes_Drv_StatusType Aes_Drv_FinishCcm(const uint8 *InputDataPtr, uint32 InputLength, 
                                            const uint8 *AadDataPtr, uint32 AadLength,
                                            uint8 *OutputDataPtr, uint8 *TagPtr, uint32 TagLength, 
                                            Aes_Drv_CryptFunctionType FunctionType)
{
    Aes_Drv_StatusType Ret = AES_DRV_STATUS_NO_ERR;
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT((NULL_PTR != InputDataPtr) || (0U == InputLength));
    MCALLIB_DEV_ASSERT((NULL_PTR != AadDataPtr) || (0U == AadLength));
    MCALLIB_DEV_ASSERT((NULL_PTR != OutputDataPtr) || (0U == InputLength));
    MCALLIB_DEV_ASSERT((NULL_PTR != TagPtr) || (0U == TagLength));
    MCALLIB_DEV_ASSERT(TagLength <= 16U);
#endif

    /* process AAD data */
    if (0U != AadLength)
    {
        Ret = Aes_Drv_UpdateCcmAad(AadDataPtr, AadLength, FunctionType);
    }

    /* process input text data */
    if((0U != InputLength) && (AES_DRV_STATUS_NO_ERR == Ret))
    {
        Ret = Aes_Drv_UpdateCcmData(InputDataPtr, InputLength, OutputDataPtr, FunctionType);
    }

    if(AES_DRV_STATUS_NO_ERR == Ret)
    {
        Aes_Drv_Configure(AES_DRV_CCM_FINISH, FunctionType, 0x80U);

        Ret = Aes_Drv_StartOperation();
        if(AES_DRV_STATUS_NO_ERR == Ret)
        {
            /* Read out the tag output value */
            Aes_Drv_ReadData(TagPtr, TagLength);
        }
    }

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif    

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
 * @brief     Compare generated data by AES with expected data
 *
 * @param[in] ExpectedDataPtr: Pointer to the expected data
 * @param[in] GeneratedDataPtr: Pointer to the generated data
 * @param[in] DataLen: Compare length in bits
 *
 * @return    boolean
 * @retval    TRUE or FALSE
 */
boolean Aes_Drv_CompareData(const uint8 *ExpectedDataPtr, const uint8 *GeneratedDataPtr, uint32 DataLen)
{
    uint8 Count;
    uint32 LenInBytes = (DataLen / 8U); 
    uint32 LastLenInBits = (DataLen % 8U); 
    uint8 TempValue;
    boolean CompareFail = FALSE;
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != ExpectedDataPtr);
    MCALLIB_DEV_ASSERT(NULL_PTR != GeneratedDataPtr);
    MCALLIB_DEV_ASSERT(0U != DataLen);
#endif

    for(Count = 0U; Count < LenInBytes ; Count++)
    {
        /*8-bitwise compare*/
        if (0U != (GeneratedDataPtr[Count] ^ ExpectedDataPtr[Count]))
        {
            CompareFail = TRUE;
            break;
        }
    }

    if ((FALSE == CompareFail) && (0U != LastLenInBits))
    {
        TempValue = GeneratedDataPtr[Count] ^ ExpectedDataPtr[Count];
        TempValue &= ((1U << LastLenInBits) - 1U);

        if (0U != TempValue)
        {
            CompareFail = TRUE;
        }
    }

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif    

    return CompareFail;
}

/**
 * @brief     Initialize a CMAC operation
 *
 * @param[in] KeyPtr: Pointer to the key
 *
 * @return    None
 * 
 */
void Aes_Drv_StartCmac(const uint8 *KeyPtr)
{
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != KeyPtr);
#endif

    Aes_Drv_CmacAlignedFlag = TRUE;

    /* Write the key for the operation */
    Aes_Drv_WriteKey(KeyPtr);

    /* Setup the configuration for the operation */
    Aes_Drv_Configure(AES_DRV_CMAC_INIT, AES_DRV_ENCRYPTION, 0x80U);

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif    
}

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
Aes_Drv_StatusType Aes_Drv_UpdateCmac(const uint8 *InputDataPtr, uint32 InputLen)
{
    Aes_Drv_StatusType Ret = AES_DRV_STATUS_NO_ERR;
    uint32 BlockNum = (InputLen / 16U);
    uint32 CountBlock;
    uint8 LastDataLength = (uint8)(InputLen % 16U);
    uint8 LastDataCopy[16U] = {0};
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != InputDataPtr);
    MCALLIB_DEV_ASSERT(0U != InputLen);
#endif

    if (FALSE == Aes_Drv_CmacAlignedFlag)
    {
         Ret = AES_DRV_STATUS_INPUT_ERROR;
    }
    else
    {
        for(CountBlock = 0U; CountBlock < BlockNum; CountBlock++)
        {
            Ret = Aes_Drv_StartOperation();
            if(AES_DRV_STATUS_NO_ERR != Ret)
            {
                break;
            }
            Aes_Drv_WriteData(&InputDataPtr[16U * CountBlock]);
            Aes_Drv_Configure(AES_DRV_CMAC_UPDATE, AES_DRV_ENCRYPTION, 0x80U);
        }

        if((AES_DRV_STATUS_NO_ERR == Ret) && (0U != LastDataLength))
        {
            /* Set CMAC aligned flag to FALSE, indicating that no CMAC data can be fed any more */
            Aes_Drv_CmacAlignedFlag = FALSE;

            Ret = Aes_Drv_StartOperation();
            if(AES_DRV_STATUS_NO_ERR == Ret)
            {
                Aes_Drv_CopyDataBlock(&InputDataPtr[16U * CountBlock], LastDataCopy,LastDataLength);
                LastDataCopy[LastDataLength] = AES_DRV_CMAC_PADDING_BYTE_MASK;
                Aes_Drv_WriteData(LastDataCopy);
            }
            Aes_Drv_Configure(AES_DRV_CMAC_UPDATE, AES_DRV_ENCRYPTION, 0x80U);
        }
    }

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif    

    return Ret;
}

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
                                      uint32 InputLen, uint8 *MacPtr, uint32 MacLength)
{
    Aes_Drv_StatusType Ret = AES_DRV_STATUS_NO_ERR;
    Aes_Drv_OptModeType OptMode;
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT((NULL_PTR != InputDataPtr) || (0U == InputLen));
    MCALLIB_DEV_ASSERT(NULL_PTR != MacPtr);
    MCALLIB_DEV_ASSERT(0U != MacLength);
    MCALLIB_DEV_ASSERT(MacLength <= 16U);
#endif

    if (0U != InputLen)
    {
        Ret = Aes_Drv_UpdateCmac(InputDataPtr, InputLen);
    }

    if (AES_DRV_STATUS_NO_ERR == Ret)
    {
        if (TRUE == Aes_Drv_CmacAlignedFlag)
        {
            OptMode = AES_DRV_CMAC_FINISH_K1;
        }
        else
        {
            OptMode = AES_DRV_CMAC_FINISH_K2;
        }

        Aes_Drv_Configure(OptMode, AES_DRV_ENCRYPTION, 0x80U);
        Ret = Aes_Drv_StartOperation();
        if(AES_DRV_STATUS_NO_ERR == Ret)
        {
            /* Read out the MAC output value */
            Aes_Drv_ReadData(MacPtr, MacLength);
        }
    }
    
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif    

    return Ret;
}

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
                                        uint32 MessageLength, uint8 *MacPtr, uint32 MacLength)
{
    Aes_Drv_StatusType Ret = AES_DRV_STATUS_NO_ERR;
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != KeyPtr);
    MCALLIB_DEV_ASSERT((NULL_PTR != Message) || (0U == MessageLength));
    MCALLIB_DEV_ASSERT(NULL_PTR != MacPtr);
    MCALLIB_DEV_ASSERT(0U != MacLength);
    MCALLIB_DEV_ASSERT(MacLength <= 16U);
#endif

    /* Init the CMAC operation */
    Aes_Drv_StartCmac(KeyPtr);
    
    /* Update data for CMAC operation */
    Ret = Aes_Drv_UpdateCmac(Message, MessageLength);

    if(AES_DRV_STATUS_NO_ERR == Ret)
    {
        /* Finish the CMAC operation */
        Ret = Aes_Drv_FinishCmac(NULL_PTR, 0U, MacPtr, MacLength);
    }    
   
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif    

    return Ret;
}

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
                  uint32 MessageLength, const uint8 *MacPtr, uint32 MacLength, boolean *VerifyResult)
{
    Aes_Drv_StatusType Ret = AES_DRV_STATUS_NO_ERR;
    uint8 GeneratedMac[16U] = {0};
    uint32 ReadLen = ((MacLength + 7U) / 8U);
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != KeyPtr);
    MCALLIB_DEV_ASSERT((NULL_PTR != Message) || (0U == MessageLength));
    MCALLIB_DEV_ASSERT(NULL_PTR != MacPtr);
    MCALLIB_DEV_ASSERT(0U != MacLength);
    MCALLIB_DEV_ASSERT(MacLength <= 128U);
    MCALLIB_DEV_ASSERT(NULL_PTR != VerifyResult);
#endif

    /*Generate the MAC data*/
    Ret = Aes_Drv_GenerateCmac(KeyPtr, Message, MessageLength, GeneratedMac, ReadLen);

    if(AES_DRV_STATUS_NO_ERR == Ret)
    {
        /*Verify the MAC data*/
        *VerifyResult = Aes_Drv_CompareData(MacPtr, GeneratedMac, MacLength);
    }
    
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif    

    return Ret;
}

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
              const Aes_Drv_AlgorithmModeType AlgorithmMode, Aes_Drv_CryptFunctionType FunctionType)
{
    Aes_Drv_StatusType Ret = AES_DRV_STATUS_NO_ERR;
    uint8 OptMode;
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != KeyPtr);
    if (AES_DRV_ECB != AlgorithmMode)
    {
        MCALLIB_DEV_ASSERT(NULL_PTR != IvPtr);
    }
#endif

    OptMode = ((uint8)AlgorithmMode << 4U);

    /* Write the key for the operation */
    Aes_Drv_WriteKey(KeyPtr);
    /* Write the initial vector for the operation(not needed for ECB mode) */
    if(AES_DRV_ECB_INIT != (Aes_Drv_OptModeType)OptMode)
    {
        Aes_Drv_WriteInitVector(IvPtr);
    }
    /* Setup the configuration for the operation */
    Aes_Drv_Configure((Aes_Drv_OptModeType)OptMode, FunctionType, 0x80U);

    if(AES_DRV_XTS_TWEAK_ENC == (Aes_Drv_OptModeType)OptMode)
    {
        Ret = Aes_Drv_StartOperation();
        if (AES_DRV_STATUS_NO_ERR == Ret)
        {
            /* Write XTS data key for the operation */
            Aes_Drv_WriteKey(&KeyPtr[16U]);
            /* Setup the configuration for XTS operation */
            Aes_Drv_Configure(AES_DRV_XTS_INIT, FunctionType, 0x80U);
        }
    }

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif    

    return Ret;
}

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
                                       Aes_Drv_CryptFunctionType FunctionType)
{
    Aes_Drv_StatusType Ret = AES_DRV_STATUS_NO_ERR;
    uint8 OptMode;
    uint32 BlockNum;
    uint32 CountBlock;
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(0U != InputLength);
    MCALLIB_DEV_ASSERT(NULL_PTR != InputDataPtr);
    MCALLIB_DEV_ASSERT(NULL_PTR != OutputDataPtr);
#endif

    OptMode = (((uint8)AlgorithmMode << 4U) + 1U);
    if (AES_DRV_XTS == AlgorithmMode)
    {
        /* Set operation mode to XTS_UPDATE */
        OptMode = (((uint8)AlgorithmMode << 4U) + 2U);
    }

    if(0U == (InputLength % 16U))
    {
        BlockNum = InputLength / 16U;
        /* Process the input data */
        for(CountBlock = 0U; CountBlock < BlockNum; CountBlock++)
        {
            /* Write the input data for the operation */
            Aes_Drv_WriteData(&InputDataPtr[16U * CountBlock]);
            /* Trigger the start of the operation */
            Ret = Aes_Drv_StartOperation();
            if(AES_DRV_STATUS_NO_ERR == Ret)
            {
                /* Read out the output value */
                Aes_Drv_ReadData(&OutputDataPtr[16U * CountBlock], 16U);
                /* Setup the configuration for the next operation */
                Aes_Drv_Configure((Aes_Drv_OptModeType)OptMode, FunctionType, 0x80U);
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        Ret = AES_DRV_STATUS_INPUT_ERROR;
    }

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif    

    return Ret;
}

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
                                 Aes_Drv_CryptFunctionType FunctionType)
{
    Aes_Drv_StatusType Ret = AES_DRV_STATUS_NO_ERR;
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != KeyPtr);
    if (AES_DRV_ECB != AlgorithmMode)
    {
        MCALLIB_DEV_ASSERT(NULL_PTR != IvPtr);
    }
    MCALLIB_DEV_ASSERT(0U != InputLength);
    MCALLIB_DEV_ASSERT(NULL_PTR != InputDataPtr);
    MCALLIB_DEV_ASSERT(NULL_PTR != OutputDataPtr);
#endif

    Ret = Aes_Drv_StartCrypt(KeyPtr, IvPtr, AlgorithmMode, FunctionType);

    if (AES_DRV_STATUS_NO_ERR == Ret)
    {
        Ret = Aes_Drv_UpdateCrypt(InputDataPtr, InputLength, OutputDataPtr, 
                                  AlgorithmMode, FunctionType);
    }

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif    

    return Ret;
}

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
                                    uint32 IvLen, Aes_Drv_CryptFunctionType FunctionType)
{
    Aes_Drv_StatusType Ret = AES_DRV_STATUS_NO_ERR;
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != KeyPtr);
    MCALLIB_DEV_ASSERT(NULL_PTR != IvPtr);
    MCALLIB_DEV_ASSERT(0U != IvLen);
#endif

    Aes_Drv_GcmAadEndFlag = FALSE;
    Aes_Drv_GcmDataAlignedFlag = TRUE;

    Aes_Drv_GcmAadLen = 0U;
    Aes_Drv_GcmDataLen = 0U;

    if (96U == IvLen)
    {
        Ret = Aes_Drv_Start96BitsIvGcm(KeyPtr, IvPtr, FunctionType);
    }
    else
    {
        Ret = Aes_Drv_StartNon96BitsIvGcm(KeyPtr, IvPtr, IvLen, FunctionType);
    }

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif    

    return Ret;
}

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
                                        Aes_Drv_CryptFunctionType FunctionType)
{
    Aes_Drv_StatusType Ret = AES_DRV_STATUS_NO_ERR;
    uint32 BlockNum = AadLength / 16U;
    uint32 CountBlock;
    uint8 LastDataLength = (uint8)(AadLength % 16U);
    uint8 LastDataCopy[16U] = {0};
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != AadPtr);
    MCALLIB_DEV_ASSERT(0U != AadLength);
#endif

    if (TRUE == Aes_Drv_GcmAadEndFlag)
    {
        Ret = AES_DRV_STATUS_INPUT_ERROR;
    }
    else
    {
        /* Process the AAD data */
        for(CountBlock = 0U; CountBlock < BlockNum; CountBlock++)
        {
            Aes_Drv_GcmAadLen += 16U;

            Ret = Aes_Drv_ProcessGcmCcmData(&AadPtr[16U * CountBlock], AES_DRV_GCM_GHASH, 
                                            FunctionType, 0x80U);
            if(AES_DRV_STATUS_NO_ERR != Ret)
            {
                break;
            }
        }
        
        if((AES_DRV_STATUS_NO_ERR == Ret) && (0U != LastDataLength))
        {
            /* Set AAD end flag to TRUE, indicating that no AAD data can be fed any more */
            Aes_Drv_GcmAadEndFlag = TRUE;

            Aes_Drv_GcmAadLen += LastDataLength;

            /* Copy the last data block */
            Aes_Drv_CopyDataBlock(&AadPtr[16U * CountBlock], LastDataCopy, LastDataLength);

            Ret = Aes_Drv_ProcessGcmCcmData(LastDataCopy, AES_DRV_GCM_GHASH, FunctionType, 0x80U);
        }
    }
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif    

    return Ret;
}
                                                   
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
                                       uint8 *OutputDataPtr, Aes_Drv_CryptFunctionType FunctionType)
{
    Aes_Drv_StatusType Ret = AES_DRV_STATUS_NO_ERR;
    uint32 BlockNum = (InputLength / 16U);
    uint32 CountBlock;
    uint8 LastDataLength = (uint8)(InputLength % 16U);
    uint8 LastDataCopy[16U] = {0};
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(0U != InputLength);
    MCALLIB_DEV_ASSERT(NULL_PTR != InputDataPtr);
    MCALLIB_DEV_ASSERT(NULL_PTR != OutputDataPtr);
#endif

    /* Set AAD end flag to TRUE, indicating that no AAD data can be fed any more */
    Aes_Drv_GcmAadEndFlag = TRUE;
    
    if (FALSE == Aes_Drv_GcmDataAlignedFlag)
    {
        Ret = AES_DRV_STATUS_INPUT_ERROR;
    }
    else
    {
        /* Process the input data */
        for(CountBlock = 0U; CountBlock < BlockNum; CountBlock++)
        {
            Aes_Drv_GcmDataLen += 16U;
            
            Ret = Aes_Drv_ProcessGcmCcmData(&InputDataPtr[16U * CountBlock], AES_DRV_GCM_UPDATE, 
                                            FunctionType, 0x80U);
            if(AES_DRV_STATUS_NO_ERR == Ret)
            {
                /* Read out the output value */
                Aes_Drv_ReadData(&OutputDataPtr[16U * CountBlock], 16U);
            }
            else
            {
                break;
            }
        }

        if((AES_DRV_STATUS_NO_ERR == Ret) && (0U != LastDataLength))
        {
            /* Set data aligned flag to FALSE, indicating that no GCM data can be fed any more */
            Aes_Drv_GcmDataAlignedFlag = FALSE;

            Aes_Drv_GcmDataLen += LastDataLength;

            /*Copy the last data block*/
            Aes_Drv_CopyDataBlock(&InputDataPtr[16U * CountBlock], LastDataCopy, LastDataLength);

            Ret = Aes_Drv_ProcessGcmCcmData(LastDataCopy, AES_DRV_GCM_UPDATE, 
                                            FunctionType, 8U * (uint32)LastDataLength);
            if(AES_DRV_STATUS_NO_ERR == Ret)
            {
                /* Read out the output value */
                Aes_Drv_ReadData(&OutputDataPtr[16U * CountBlock], LastDataLength);
            }
        }
    }

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif    

    return Ret;
}

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
                                     Aes_Drv_CryptFunctionType FunctionType)
{
    Aes_Drv_StatusType Ret = AES_DRV_STATUS_NO_ERR;
    uint8 LenAsInput[16U] = {0};
    uint8 Loop;
    uint64 AadLength_bits;
    uint64 MsgLength_bits;
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT((NULL_PTR != InputDataPtr) || (0U == InputLength));
    MCALLIB_DEV_ASSERT((NULL_PTR != AadDataPtr) || (0U == AadLength));
    MCALLIB_DEV_ASSERT((NULL_PTR != OutputDataPtr) || (0U == InputLength));
    MCALLIB_DEV_ASSERT((NULL_PTR != TagPtr) || (0U == TagLength));
    MCALLIB_DEV_ASSERT(TagLength <= 16U);
#endif

    /* process AAD data */
    if (0U != AadLength)
    {
        Ret = Aes_Drv_UpdateGcmAad(AadDataPtr, AadLength, FunctionType);
    }

    /* process input text data */
    if((0U != InputLength) && (AES_DRV_STATUS_NO_ERR == Ret))
    {
        Ret = Aes_Drv_UpdateGcmData(InputDataPtr, InputLength, OutputDataPtr, FunctionType);
    }

    if(AES_DRV_STATUS_NO_ERR == Ret)
    {
        AadLength_bits = ((uint64)Aes_Drv_GcmAadLen * 8U);
        MsgLength_bits = ((uint64)Aes_Drv_GcmDataLen * 8U);

        /* Process length data via GHASH */
        for (Loop = 0U; Loop < 8U; Loop++)
        {
            LenAsInput[Loop] = ((uint8*)(&AadLength_bits))[7U - Loop];
            LenAsInput[Loop + 8U] = ((uint8*)(&MsgLength_bits))[7U - Loop];
        }

        Ret = Aes_Drv_ProcessGcmCcmData(LenAsInput, AES_DRV_GCM_GHASH, FunctionType, 0x80U);

        if(AES_DRV_STATUS_NO_ERR == Ret)
        {
            Aes_Drv_Configure(AES_DRV_GCM_FINISH, FunctionType, 0x80U);

            Ret = Aes_Drv_StartOperation();
            if(AES_DRV_STATUS_NO_ERR == Ret)
            {
                /* Read out the tag output value */
                Aes_Drv_ReadData(TagPtr, TagLength);
            }
        }
    }

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif    

    return Ret;
}

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
                               uint8 *TagPtr, uint32 TagLen, Aes_Drv_CryptFunctionType FunctionType)
{
    Aes_Drv_StatusType Ret = AES_DRV_STATUS_NO_ERR;
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != KeyPtr);
    MCALLIB_DEV_ASSERT(NULL_PTR != IvPtr);
    MCALLIB_DEV_ASSERT(0U != IvLength);
    MCALLIB_DEV_ASSERT((NULL_PTR != InputDataPtr) || (0U == InputLength));
    MCALLIB_DEV_ASSERT((NULL_PTR != AadDataPtr) || (0U == AadLength));
    MCALLIB_DEV_ASSERT((NULL_PTR != OutputDataPtr) || (0U == InputLength));
    MCALLIB_DEV_ASSERT((NULL_PTR != TagPtr) || (0U == TagLen));
    MCALLIB_DEV_ASSERT(TagLen <= 16U);
#endif

    /* Init the AES operation */
    Ret = Aes_Drv_StartGcm(KeyPtr, IvPtr, IvLength, FunctionType);

    /* process AAD data */
    if((0U != AadLength) && (AES_DRV_STATUS_NO_ERR == Ret))
    {
        Ret = Aes_Drv_UpdateGcmAad(AadDataPtr, AadLength, FunctionType);
    }

    /* process input text data */
    if((0U != InputLength) && (AES_DRV_STATUS_NO_ERR == Ret))
    {
        Ret = Aes_Drv_UpdateGcmData(InputDataPtr, InputLength, OutputDataPtr, FunctionType);
    }  

    if(AES_DRV_STATUS_NO_ERR == Ret)
    {
        /* finish gcm operation and read out the output data and tag */
        Ret = Aes_Drv_FinishGcm(NULL_PTR, 0U, NULL_PTR, 0U, 
                                OutputDataPtr, TagPtr, TagLen, FunctionType);
    }

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif    

    return Ret;
}

/**
 * @brief      CCM operation, only single call mode is supported for CCM
 *
 * @param[in]  KeyPtr: Pointer to the key
 * @param[in]  IvPtr: Pointer to the initial vector
 * @param[in]  IvLength: Length of the initial vector in bytes
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
                               uint8 *TagPtr, uint32 TagLen, Aes_Drv_CryptFunctionType FunctionType)
{
    Aes_Drv_StatusType Ret = AES_DRV_STATUS_NO_ERR;
#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_START();
#endif

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT(NULL_PTR != KeyPtr);
    MCALLIB_DEV_ASSERT(NULL_PTR != IvPtr);
    MCALLIB_DEV_ASSERT(0U != IvLength);
    MCALLIB_DEV_ASSERT((NULL_PTR != InputDataPtr) || (0U == InputLength));
    MCALLIB_DEV_ASSERT((NULL_PTR != AadDataPtr) || (0U == AadLength));
    MCALLIB_DEV_ASSERT((NULL_PTR != OutputDataPtr) || (0U == InputLength));
    MCALLIB_DEV_ASSERT((NULL_PTR != TagPtr) || (0U == TagLen));
    MCALLIB_DEV_ASSERT(TagLen <= 16U);
#endif

    /* Init the AES operation */
    Ret = Aes_Drv_StartCcm(KeyPtr, IvPtr, IvLength, InputLength, AadLength, TagLen, FunctionType);

    /* process AAD data */
    if((0U != AadLength) && (AES_DRV_STATUS_NO_ERR == Ret))
    {
        Ret = Aes_Drv_UpdateCcmAad(AadDataPtr, AadLength, FunctionType);
    }

    /* process input text data */
    if((0U != InputLength) && (AES_DRV_STATUS_NO_ERR == Ret))
    {
        Ret = Aes_Drv_UpdateCcmData(InputDataPtr, InputLength, OutputDataPtr, FunctionType);
    }  

    if(AES_DRV_STATUS_NO_ERR == Ret)
    {
        /* finish ccm operation and read out the output data and tag */
        Ret = Aes_Drv_FinishCcm(NULL_PTR, 0U, NULL_PTR, 0U, 
                                OutputDataPtr, TagPtr, TagLen, FunctionType);
    }

#if (STD_ON == AES_DRV_DEV_ERROR_DETECT)
    MCALLIB_DEV_ASSERT_END();
#endif    

    return Ret;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Aes_Drv */

/** @} end of group Crypto_Module */
