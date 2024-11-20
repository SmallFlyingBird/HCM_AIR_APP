/**************************************************************************************************/
/**
 * @file      : Trng_Drv.h
 * @brief     : Trng low level driver header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef TRNG_DRV_H
#define TRNG_DRV_H

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

#include "Trng_Drv_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define TRNG_DRV_H_VENDOR_ID                   0x00B3U
#define TRNG_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define TRNG_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define TRNG_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define TRNG_DRV_H_SW_MAJOR_VERSION            1U
#define TRNG_DRV_H_SW_MINOR_VERSION            2U
#define TRNG_DRV_H_SW_PATCH_VERSION            2U

/* Check if current file and Trng_Drv_Types.h are the same vendor */
#if (TRNG_DRV_H_VENDOR_ID != TRNG_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Trng_Drv.h and Trng_Drv_Types.h are different"
#endif
/* Check if current file and Trng_Drv_Types.h are the same Autosar version */
#if ((TRNG_DRV_H_AR_RELEASE_MAJOR_VERSION != TRNG_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
     (TRNG_DRV_H_AR_RELEASE_MINOR_VERSION != TRNG_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) || \
     (TRNG_DRV_H_AR_RELEASE_REVISION_VERSION != TRNG_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Trng_Drv.h and Trng_Drv_Types.h are different"
#endif
/* Check if current file and Trng_Drv_Types.h are the same Software version */
#if ((TRNG_DRV_H_SW_MAJOR_VERSION != TRNG_DRV_TYPES_H_SW_MAJOR_VERSION) || \
     (TRNG_DRV_H_SW_MINOR_VERSION != TRNG_DRV_TYPES_H_SW_MINOR_VERSION) || \
     (TRNG_DRV_H_SW_PATCH_VERSION != TRNG_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Trng_Drv.h and Trng_Drv_Types.h are different"
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
 * @brief     Initialize the TRNG module.
 *
 * @param[in] None
 *
 * @return    Trng_Drv_StatusType: Error code of TRNG operation
 * 
 */
void Trng_Drv_Init(void);

/**
 * @brief      Get the random data of CTR-DRBG.
 *
 * @param[out] DataOutPtr: Random Pointer to store the random data
 * @param[in]  DataLength: Length of requested random data in bytes
 *
 * @return     Trng_Drv_StatusType: Error code of TRNG operation.
 * 
 */
Trng_Drv_StatusType Trng_Drv_GetCtrDrbgRandomData(uint8 *DataOutPtr, uint32 DataLength);

#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Trng_Drv */

/** @} end of group Crypto_Module */

#endif /* TRNG_DRV_H */
