/**
 * @file    Fls_Lld.h
 * @version
 *
 * @brief   AUTOSAR Fls driver interface
 * @details API implementation for FLS driver
 *
 * @addtogroup FLS_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Fls
 *   Dependencies         : none
 *
 *   Autosar Version      : V4.4.0
 *   Autosar Revision     : ASR_REL_4_4_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           : V2.3.0
 *
 *
 *   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
 *   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef FLS_DRV_H
#define FLS_DRV_H

#ifdef __cplusplus
extern "C" {
#endif


/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include "Std_Types.h"
#include "Fls_Cfg.h"
#include "MemIf_Types.h"
#include "Fls_Types.h"

/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_DRV_VENDOR_ID                      (180)
#define FLS_DRV_AR_RELEASE_MAJOR_VERSION       (4)
#define FLS_DRV_AR_RELEASE_MINOR_VERSION       (4)
#define FLS_DRV_AR_RELEASE_REVISION_VERSION    (0)
#define FLS_DRV_SW_MAJOR_VERSION               (2)
#define FLS_DRV_SW_MINOR_VERSION               (3)
#define FLS_DRV_SW_PATCH_VERSION               (0)


/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and FLS configuration header file are of the same vendor */
#if (FLS_DRV_VENDOR_ID != FLS_VENDOR_ID_CFG)
#error "Fls_Drv.h and Fls_Cfg.h have different vendor ids"
#endif

/* Check if source file and FLS configuration header file are of the same Autosar version */
#if ((FLS_DRV_AR_RELEASE_MAJOR_VERSION != FLS_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FLS_DRV_AR_RELEASE_MINOR_VERSION != FLS_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FLS_DRV_AR_RELEASE_REVISION_VERSION != FLS_AR_RELEASE_REVISION_VERSION_CFG) \
    )
#error "AutoSar Version Numbers of Fls_Drv.h and Fls_Cfg.h are different"
#endif

/* Check if source file and FLS configuration header file are of the same software version */
#if ((FLS_DRV_SW_MAJOR_VERSION != FLS_SW_MAJOR_VERSION_CFG) || \
     (FLS_DRV_SW_MINOR_VERSION != FLS_SW_MINOR_VERSION_CFG) || \
     (FLS_DRV_SW_PATCH_VERSION != FLS_SW_PATCH_VERSION_CFG) \
    )
#error "Software Version Numbers of Fls_Drv.h and Fls_Cfg.h are different"
#endif


/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
#define FLS_SECTOR_ERASE_COMMAND_CODE     (0x10u)
#if defined (CPU_YTM32B1HA0)
#define FLS_PAGE_PROGRAM64_COMMAND_CODE   (0x01u)
#define FLS_PAGE_PROGRAM256_COMMAND_CODE  (0x02u)
#define FLS_ERASE_RETRY_COMMAND_CODE      (0x14u)
#elif defined (CPU_YTM32B1MC0)
#define FLS_PAGE_PROGRAM_COMMAND_CODE     (0x01u)
#define FLS_ERASE_RETRY_COMMAND_CODE      (0x10u)
#define FEATURE_EFM_SECTOR_ERASE_RETRY_TIMING 400u
#else
#define FLS_PAGE_PROGRAM_COMMAND_CODE     (0x02u)
#define FLS_ERASE_RETRY_COMMAND_CODE      (0x17u)
#endif
#define FLS_LOAD_AES_KEY_CMD_CODE         (0x20u)
#define FLS_EFM_CMDUNLOCK_KEY             (0xFD9573F5U)
#if defined (CPU_YTM32B1MC0)
#define FLS_ERR_FLAGS_MASK                (EFM_STS_CMD_FAIL_MASK|\
                                        EFM_STS_ACCERR_MASK|\
                                        EFM_STS_UNRECOVERR_MASK|\
                                        EFM_STS_RECOVERR_MASK)
#elif defined (CPU_YTM32B1HA0)
#define FLS_ERR_FLAGS_MASK                (EFM_STS_FAIL_MASK|\
                                        EFM_STS_ACCERR_MASK|\
                                        EFM_STS_UNRECOVERR_MASK|\
                                        EFM_STS_RECOVERR_MASK|\
                                        EFM_STS_CI_UNRECOVERR_MASK|\
                                        EFM_STS_CI_RECOVERR_MASK)
#else
#define FLS_ERR_FLAGS_MASK                (EFM_STS_FAIL_MASK|\
                                        EFM_STS_ACCERR_MASK|\
                                        EFM_STS_UNRECOVERR_MASK|\
                                        EFM_STS_RECOVERR_MASK)
#endif
#if (FLS_WEBIT_AVAILABLE==STD_ON)
#if defined (CPU_YTM32B1HA0)
#define FLS_ADDR_SELECTED_FLAG_MASK           (EFM_STS_SET_ADDR_MASK)   /* addr selected flag */
#elif defined (CPU_YTM32B1MC0)
#define FLS_ADDR_SELECTED_FLAG_MASK           (EFM_STS_ARRAY_SELECTED_MASK)   /* addr selected flag */
#else
#endif
#endif
/**
* @brief the number of bytes uses to compare (1 byte).
*
*/
#define FLS_SIZE_1BYTE      1U

/**
* @brief the number of bytes uses to compare (2 bytes).
*
*/
#define FLS_SIZE_2BYTE      2U

/**
* @brief the number of bytes uses to compare (4 bytes).
*
*/
#define FLS_SIZE_4BYTE      4U
/*==================================================================================================
 *                                         EXTERNAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                             ENUMS
==================================================================================================*/
/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
 *                                 PUBLIC API FUNCTIONS
==================================================================================================*/

/**
 * @brief            FLS hardware initialization
 * @details          This function will initialize the FLS hardware
 * @param[in]        SectorProtCfg - pointer to fls protection configuration structure
 * @return           Fls_Lld_StatusType
 */
Fls_Lld_StatusType Fls_Lld_Init(Fls_SectorProtectType const *SectorProtCfg);

/**
 * @brief            Get flash erase job process
 * @details          This function will process the flash erase job
 * @param[in]        StartAddress - Start address of the flash memory to be erased
 * @param[in]        Async - Asynchronous or synchronous job
 * @return           Fls_Lld_StatusType
 */
Fls_Lld_StatusType Fls_Lld_SectorErase(Fls_AddressType StartAddress, boolean Async);

/**
 * @brief            flash read data flash job process
 * @details          This function will process the data flash read job
 * @param[in]        StartAddress - Start address of the flash memory to be read
 * @param[in]        Length - Data length to be read
 * @param[out]       TargetAddressPtr - Data address to be written
 * @return           Fls_Lld_StatusType
 */
Fls_Lld_StatusType Fls_Lld_ReadFlash(Fls_AddressType StartAddress, Fls_LengthType Length, uint8 *TargetAddressPtr);

/**
 * @brief            flash data compare job process
 * @details          This function will process the data flash data compare job
 * @param[in]        StartAddress - Start address of the flash memory to be read
 * @param[in]        Length - Data length to be compared
 * @param[in]        SourceAddressPtr - Data pointer to be compared
 * @return           Fls_Lld_StatusType
 */
Fls_Lld_StatusType Fls_Lld_CompareFlash(Fls_AddressType StartAddress, Fls_LengthType Length, const uint8 *SourceAddressPtr);

/**
* @brief          Process ongoing erase or write hardware job.
* @details        In case Async Operation is ongoing this function will complete the following job:
*                 - Erase
*                 - Erase on Interleaved sectors
*                 - Write
*                 - Erase blank Check
* @return         void
*/
void Fls_Lld_MainFunction(void);
/**
* @brief          IP wrapper sector write function.
* @details        Route the write job to appropriate low level IP function.
* @param[in]      DestAddr - Destination address
* @param[in]      Length - Length of data to be written
* @param[in]      JobDataSrcPtr - Pointer to data source
* @param[in]      AsynchFlag - Asynchronous or synchronous job
* @return         Fls_Lld_ReturnType
*/
Fls_Lld_ReturnType Fls_Lld_SectorWrite(const Fls_AddressType DestAddr, const Fls_LengthType Length, \
                                        const uint8 *JobDataSrcPtr, const boolean AsynchFlag);
/**
 * @brief           Abort a program or erase operation
 * @details         This function will abort a program or erase operation
 * @return          Fls_Lld_StatusType
 */
Fls_Lld_StatusType Fls_Lld_Cancel(void);
/**
 * @brief            Translate the return code from drv.
 * @details          This function will Translate the return code from drv to Fls_Lld_ReturnType.
 * @param[in]        ReturnCode the return code from fls drv
 * @return           Fls_Lld_ReturnType
 */
Fls_Lld_ReturnType Fls_Lld_TranslateReturnCode(Fls_Lld_StatusType ReturnCode);
/**
 * @brief           Get the physical sector size.
 * @details         This function will get the physical sector size.
 * @param[in]       DestAddr the destination address
 * @return          uint16
*/
uint16 Fls_Lld_GetPhycSectorSize(Fls_AddressType DestAddr);
/**
 * @brief           Get One bit Ecc error flag.
 * @details         This function will get One bit Ecc error flag.
 * @return          boolean
*/
boolean Fls_Lld_GetOneBitEccErrFlag(void);

/**
 * @brief           Get Two bit Ecc error flag.
 * @details         This function will get Two bit Ecc error flag.
 * @return          boolean
*/
boolean Fls_Lld_GetTwoBitEccErrFlag(void);

/**
 * @brief           Get the flash ecc error address.
 * @details         This function will get the flash ecc error address.
 * @return          Fls_AddressType
*/
Fls_AddressType Fls_Lld_GetEccErrAddr(void);

#ifdef __cplusplus
}
#endif

#endif /* FLS_DRV_H */

/** @} */

