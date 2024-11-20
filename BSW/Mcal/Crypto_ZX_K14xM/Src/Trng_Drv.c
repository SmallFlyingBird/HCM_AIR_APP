/**************************************************************************************************/
/**
 * @file      : Trng_Drv.c
 * @brief     : Trng low level driver source file
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

/** @addtogroup Trng_Drv
 *  @brief Trng low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Trng_Drv.h"
#include "Device_Regs.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define TRNG_DRV_C_VENDOR_ID                   0x00B3U
#define TRNG_DRV_C_AR_RELEASE_MAJOR_VERSION    4U
#define TRNG_DRV_C_AR_RELEASE_MINOR_VERSION    6U
#define TRNG_DRV_C_AR_RELEASE_REVISION_VERSION 0U
#define TRNG_DRV_C_SW_MAJOR_VERSION            1U
#define TRNG_DRV_C_SW_MINOR_VERSION            2U
#define TRNG_DRV_C_SW_PATCH_VERSION            2U

/* Check if current file and Trng_Drv.h are the same vendor */
#if (TRNG_DRV_C_VENDOR_ID != TRNG_DRV_H_VENDOR_ID)
    #error "Vendor ID of Trng_Drv.c and Trng_Drv.h are different"
#endif
/* Check if current file and Trng_Drv.h are the same Autosar version */
#if ((TRNG_DRV_C_AR_RELEASE_MAJOR_VERSION != TRNG_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (TRNG_DRV_C_AR_RELEASE_MINOR_VERSION != TRNG_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (TRNG_DRV_C_AR_RELEASE_REVISION_VERSION != TRNG_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Trng_Drv.c and Trng_Drv.h are different"
#endif
/* Check if current file and Trng_Drv.h are the same Software version */
#if ((TRNG_DRV_C_SW_MAJOR_VERSION != TRNG_DRV_H_SW_MAJOR_VERSION) || \
     (TRNG_DRV_C_SW_MINOR_VERSION != TRNG_DRV_H_SW_MINOR_VERSION) || \
     (TRNG_DRV_C_SW_PATCH_VERSION != TRNG_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Trng_Drv.c and Trng_Drv.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Device_Regs.h are the same Autosar version */
    #if ((TRNG_DRV_C_AR_RELEASE_MAJOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) || \
         (TRNG_DRV_C_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Trng_Drv.c and Device_Regs.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */


#define TRNG_DRV_REG_CTR_DRBG_RANDOM_DATA_VA_MASK        (0x1UL << 16U)
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
#define CRYPTO_START_SEC_CONST_PTR
#include "Crypto_MemMap.h"
/**
 *  @brief TRNG peripheral base address array
 */
static Reg_Trng_WType *const Trng_Drv_TrngRegWPtr = (Reg_Trng_WType *) TRNG_BASE_ADDR;

#define CRYPTO_STOP_SEC_CONST_PTR
#include "Crypto_MemMap.h"

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */
 
/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
 #define CRYPTO_START_SEC_CODE
 #include "Crypto_MemMap.h"

/**
 * @brief     Initialize the TRNG module.
 *
 * @param[in] None
 *
 * @return    Trng_Drv_StatusType: Error code of TRNG operation
 * 
 */
void Trng_Drv_Init(void)
{
    /* set number of generate requests between two reseeds */
    Trng_Drv_TrngRegWPtr->CTR_DRBG_CONFIG_1 = 0xFFFFU;

    /* set additional config */
    Trng_Drv_TrngRegWPtr->ADDITIONAL_CONFIG_0 = 0x3C0U;
    Trng_Drv_TrngRegWPtr->ADDITIONAL_CONFIG_1 = 0x400U;
    Trng_Drv_TrngRegWPtr->ADDITIONAL_CONFIG_2 = 0xFFFFFFFFU;

    /* set number of random generations between two periodic health tests */
    Trng_Drv_TrngRegWPtr->CTR_DRBG_CONFIG_2 = 0xFFFFU;

    /* set number of 128-bit words that are requested */
    Trng_Drv_TrngRegWPtr->CTR_DRBG_REQUEST_SIZE = 0xFFU;

    /* configure and enable TRNG */
    Trng_Drv_TrngRegWPtr->TRNG_CONFIG = 0x50143U;
}

/**
 * @brief      Get the random data of CTR-DRBG.
 *
 * @param[out] DataOutPtr: Random Pointer to store the random data
 * @param[in]  DataLength: Length of requested random data in bytes
 *
 * @return     Trng_Drv_StatusType: Error code of TRNG operation.
 * 
 */
Trng_Drv_StatusType Trng_Drv_GetCtrDrbgRandomData(uint8 *DataOutPtr, uint32 DataLength)
{
    uint32 Count = 0U;
    Trng_Drv_StatusType Ret = TRNG_DRV_STATUS_INVALID_RANDOM_ERR;
    uint32 TempValue = 0U; 
    uint32 RegValue = 0U;
#if (STD_ON == TRNG_DRV_TIMEOUT_SUPERVISION_ENABLED)     
    uint32 ElapsedTicks = 0U;
    uint32 TrngCurrentTicks, TrngElapsedTicks, TrngTimeoutTicks;
 
    (void)McalLib_GetCounterValue(TRNG_DRV_TIMEOUT_TYPE, &TrngCurrentTicks);
    TrngElapsedTicks = 0U;
    TrngTimeoutTicks = McalLib_MicroSecToTicks(TRNG_DRV_TIMEOUT_TYPE, TRNG_DRV_TIMEOUT_VALUE);
    while((TrngElapsedTicks < TrngTimeoutTicks) && (Count < DataLength))
    {
        if(0U == (Count % 2U))
        {
            RegValue = Trng_Drv_TrngRegWPtr->CTR_DRBG_RANDOM_DATA;
            TempValue = RegValue;
        }
        
        if(0U != (RegValue & TRNG_DRV_REG_CTR_DRBG_RANDOM_DATA_VA_MASK))
        {
            DataOutPtr[Count] = (uint8)(TempValue & 0xFFU);
            TempValue = (TempValue >> 8U);
            Count++;
            Ret = TRNG_DRV_STATUS_NO_ERR;
        }
        else
        {
            (void)McalLib_GetElapsedValue(TRNG_DRV_TIMEOUT_TYPE, &TrngCurrentTicks, &ElapsedTicks);
            TrngElapsedTicks += ElapsedTicks;            
        }
    }
    
    if(TrngElapsedTicks >= TrngTimeoutTicks)
    {
        Ret = TRNG_DRV_STATUS_INVALID_RANDOM_ERR;
    }
#else
    while(Count < DataLength)
    {
        if(0U == (Count % 2U))
        {
            RegValue = Trng_Drv_TrngRegWPtr->CTR_DRBG_RANDOM_DATA;
            TempValue = RegValue;
        }
        
        if(0U != (RegValue & TRNG_DRV_REG_CTR_DRBG_RANDOM_DATA_VA_MASK))
        {
            DataOutPtr[Count] = (uint8)(TempValue & 0xFFU);
            TempValue = (TempValue >> 8U);
            Count++;
            Ret = TRNG_DRV_STATUS_NO_ERR;
        }
    }
#endif
    return Ret;
}

#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Trng_Drv */

/** @} end of group Crypto_Module */
