/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file undefined
 * @brief 
 * 
 */
#ifndef FLS_CFG_H
#define FLS_CFG_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
#include "Fls_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_VENDOR_ID_CFG                      (180)
#define FLS_AR_RELEASE_MAJOR_VERSION_CFG       (4)
#define FLS_AR_RELEASE_MINOR_VERSION_CFG       (4)
#define FLS_AR_RELEASE_REVISION_VERSION_CFG    (0)
#define FLS_SW_MAJOR_VERSION_CFG               (2)
#define FLS_SW_MINOR_VERSION_CFG               (3)
#define FLS_SW_PATCH_VERSION_CFG               (0)



/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/**
 * @brief        The flash driver shall load the flash access code to RAM whenever an erase or write job is started and unload (overwrite) it after that job has been finished or canceled.
 * @details      true:	Flash access code loaded on job start / unloaded on job end  
              	or error.
              false:	Flash access code not loaded to / unloaded from RAM at all. 
 * @ref          ECUC_Fls_00284
 */
#define FLS_AC_LOAD_ON_JOB_START                   (STD_OFF)

/**
 * @brief        Compile switch to enable/disable the Fls_BlankCheck function.
 * @details      true:	API supported / function provided.
              false:	API not supported / function not provided 
 * @ref          ECUC_Fls_00319
 */
#define FLS_BLANK_CHECK_API                        (STD_ON)

/**
 * @brief        Compile switch to enable and disable the Fls_Cancel function.
 * @details      true:	API supported / function provided.
              false:	API not supported / function not provided 
 * @ref          ECUC_Fls_00285
 */
#define FLS_CANCEL_API                             (STD_ON)

/**
 * @brief        Compile switch to enable and disable the Fls_Compare function.
 * @details      true:	API supported / function provided.
              false:	API not supported / function not provided 
 * @ref          ECUC_Fls_00286
 */
#define FLS_COMPARE_API                            (STD_ON)

/**
 * @brief        Switches the development error detection and notification on or off.
 * @details      * true: detection and notification is enabled.
              * false: detection and notification is disabled. 
 * @ref          ECUC_Fls_00287
 */
#define FLS_DEV_ERROR_DETECT                       (STD_ON)

/**
 * @brief        Switches the development error detection and notification on or off on IP level.
*/
#define FLS_DEV_ERROR_DETECT_IN_IPLEVEL            (STD_ON)

/**
 * @brief        Compile switch to enable erase verification.
 * @details      true: memory region is checked to be erased.
              false: memory region is not checked to be erased. 
 * @ref          ECUC_Fls_00321
 */
#define FLS_ERASE_VERIFICATION_ENABLED             (STD_OFF)

/**
 * @brief        Compile switch to enable and disable the Fls_GetJobResult function.
 * @details      true:	API supported / function provided.
              false:	API not supported / function not provided 
 * @ref          ECUC_Fls_00289
 */
#define FLS_GET_JOB_RESULT_API                      (STD_ON)

/**
 * @brief        Compile switch to enable and disable the Fls_GetStatus function.
 * @details      true:	API supported / function provided.
              false:	API not supported / function not provided 
 * @ref          ECUC_Fls_00290
 */
#define FLS_GET_STATUS_API                          (STD_ON)
/**
 * @brief        Compile switch to enable and disable the Fls_SetMode function.
 * @details      true:	API supported / function provided.
              false:	API not supported / function not provided 
 * @ref          ECUC_Fls_00291
 */
#define FLS_SET_MODE_API                            (STD_ON)

/**
 * @brief        Compile switch to enable timeout supervision.
 * @details      true: timeout supervision for read/erase/write/compare jobs enabled.
              false: timeout supervision for read/erase/write/compare jobs disabled. 
 * @ref          ECUC_Fls_00322
 */
#define FLS_TIMEOUT_SUPERVISION_ENABLED             (STD_OFF)

/**
 * @brief        Job processing triggered by hardware interrupt.
 * @details      true: Job processing triggered by interrupt (hardware controlled). 
              false: Job processing not triggered by interrupt (software controlled) or the underlying hardware does not support interrupt mode for flash operations. 
 * @ref          ECUC_Fls_00292
 */
#define FLS_USE_INTERRUPTS                          (STD_OFF)

/**
 * @brief        Pre-processor switch to enable / disable the API to read out the modules version information.
 * @details      true:	Version info API enabled.
              false:	Version info API disabled. 
 * @ref          ECUC_Fls_00293
 */
#define FLS_VERSION_INFO_API                        (STD_ON)

/**
 * @brief        Compile switch to enable write verification.
 * @details      true: written data is compared directly after write.
              false: written date is not compared directly after write. 
 * @ref          ECUC_Fls_00320
 */
#define FLS_WRITE_VERIFICATION_ENABLED              (STD_OFF)

/**
* @brief Internal sectors are present or not in the current configuration. 
* @details true: Internal sectors are present.
                      false: Internal sectors are not present. 
* @ref          ECUC_Fls_00320
*/
#define FLS_INTERNAL_SECTORS_CONFIGURED            (STD_ON)

/**
 * @brief       External sectors are present or not in the current configuration.
 * @details     true: External sectors are present.
               false: External sectors are not present.
 */
#define FLS_QSPI_SECTORS_CONFIGURED                 (STD_OFF)

/**
 * @brief       Pre-compile Support.
 * @details     true: Pre-compile support is enabled.
               false: Pre-compile support is disabled.
*/
#define FLS_FIXED_PB_CONFIG                        (STD_OFF)

/**
 * @brief       SchM Support.
 * @details     true: SchM support is enabled.
                false: SchM support is disabled.
*/
#define FLS_SCHM_SUPPORT                           (STD_ON)

/**
 * @brief Internal sectors protection support. 
 * @details true: Internal sectors protection is supported.
            false: Internal sectors protection is not supported.
 */
#define FLS_INTERNAL_SECTORS_PROTECTION            (STD_ON) 

/**
 * @brief        Fls ecc uncorrectable error handle bus fault independently.
 * @details      true: Fls ecc uncorrectable error handle bus fault independently.
                 false: Fls ecc uncorrectable error don't handle bus fault independently.
 */
#define FLS_HANDLE_BUSFAULT_INDEPENDENT             (STD_OFF)

/**
 * @brief        Fls ecc error interrupt enable.
 * @details      true: Fls ecc error interrupt enable.
                 false: Fls ecc error interrupt disable.
 */
#define FLS_ECC_ERROR_INTERRUPT_ENABLE              (STD_OFF)


#ifdef FLS_USER_MODE_SUPPORTED
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
#error "Must define MCAL_ENABLE_USER_MODE_SUPPORT if FLS_USER_MODE_SUPPORTED is defined"
#endif
#endif

/**
 * @brief  Fls Write enable bit is avariable or not in CTRL
 * 
 */
#define FLS_WEBIT_AVAILABLE                     (STD_OFF)

/**
 * @brief        Fls Erase retry feature enable or not.
*/
#define FLS_QUICK_ERASE_FEATURE_ENABLE          (STD_OFF)

#if (FLS_ERASE_VERIFICATION_ENABLED == STD_ON)
/* The maximum number of bytes to blank check in one cycle of the flash driver job processing function */
#define FLS_MAX_ERASE_BLANK_CHECK               (256U)
#endif

/**
 * @brief        The flash memory start address (see also SWS_Fls_00208 and SWS_Fls_00209).
 * @details      This parameter defines the lower boundary for read / write / erase and compare jobs. 
 * @ref          ECUC_Fls_00169
 */
#define FLS_BASE_ADDRESS                           (0U)

/**
 * @brief        Index of the driver, used by FEE.
 * @details       
 * @ref          ECUC_Fls_00288
 */
#define FLS_DRIVER_INDEX                           (0U)




/**
 * @brief        Position in RAM, to which the erase flash access code has to be loaded.
 * @details      Only relevant if the erase flash access code is not position independent. If this information is not provided it is assumed that the erase flash access code is position independent and that therefore the RAM position can be freely configured. 
 * @ref          ECUC_Fls_00294
 */
#define FLS_AC_LOCATION_ERASE                       (0U)

/**
 * @brief        Position in RAM, to which the write flash access code has to be loaded.
 * @details      Only relevant if the write flash access code is not position independent. If this information is not provided it is assumed that the write flash access code is position independent and that therefore the RAM position can be freely configured. 
 * @ref          ECUC_Fls_00295
 */
#define FLS_AC_LOCATION_WRITE                       (0U)

/**
 * @brief        Number of bytes in RAM needed for the erase flash access code.
 * @details       
 * @ref          ECUC_Fls_00296
 */
#define FLS_AC_SIZE_ERASE                           (0U)

/**
 * @brief        Number of bytes in RAM needed for the write flash access code.
 * @details       
 * @ref          ECUC_Fls_00297
 */
#define FLS_AC_SIZE_WRITE                           (0U)

/**
 * @brief        The contents of an erased flash memory cell.
 * @details       
 * @ref          ECUC_Fls_00299
 */
#define FLS_ERASED_VALUE                           (4294967295U)

/**
 * @brief        Number of erase cycles specified for the flash device (usually given in the device data sheet).
 * @details      If the number of specified erase cycles depends on the operating environment (temperature, voltage, ...) during reprogramming of the flash device, the minimum number for which a data retention of at least 15 years over the temperature range from -40°C .. +125°C can be guaranteed shall be given.

              Note: If there are different numbers of specified erase cycles for different flash sectors of the device this parameter has to be extended to a parameter list (similar to the sector list above). 
 * @ref          ECUC_Fls_00198
 */
#define FLS_SPECIFIED_ERASE_CYCLES                  (100000U)

/**
 * @brief        Unique identifier of the hardware device that is expected by this driver (the device for which this driver has been implemented).
 * @details      Only relevant for external flash drivers. 
 * @ref          ECUC_Fls_00300
 */
#define FLS_EXPECTED_HW_ID                          (0U)


/**
 * @brief        Maximum time to erase one complete flash sector.
 * @details       
 * @ref          ECUC_Fls_00298
 */
#define FLS_ERASE_TIME                             (5.0)

/**
 * @brief        Maximum time to program one complete flash page.
 * @details
 * @ref          ECUC_Fls_00301
 */
#define FLS_WRITE_TIME                             (0.0005)

/**
 * @brief        The information of internal flash,such as base addr，total size, program size.
 * @details
 * @ref
 */
#define FLS_PROG_FLASH_SECTOR_SIZE                (0x400U)
#define FLS_PROG_FLASH_PAGE_SIZE                  (0x8U)
#define FLS_PROG_FLASH_BASE_ADDR                  (0x0U)
#define FLS_PROG_FLASH_SIZE                       (0x80000U)

#define FLS_NVR_FLASH_SECTOR_SIZE                 (0x200U)
#define FLS_NVR_FLASH_PAGE_SIZE                   (0x20U)
#define FLS_NVR_FLASH_BASE_ADDR                   (0x10000200U)
#define FLS_NVR_FLASH_SIZE                        (0x200U)


/* @brief Valid P_FLASH address */
#define FLS_ADDRESS_VALID_P_FLASH(addr)     ((addr) < (FLS_PROG_FLASH_BASE_ADDR + FLS_PROG_FLASH_SIZE))

/* @brief Valid D_FLASH address */
#define FLS_ADDRESS_VALID_D_FLASH(addr)     (FALSE)

/* @brief Valid NVR_FLASH address*/
#define  FLS_ADDRESS_VALID_NVR_FLASH(addr)  ((FLS_NVR_FLASH_BASE_ADDR <= (addr)) && ((addr) < (FLS_NVR_FLASH_BASE_ADDR + FLS_NVR_FLASH_SIZE)))

/* @brief Valid P_FLASH or D_FLASH address */
#define FLS_ADDRESS_VALID(addr)             (FLS_ADDRESS_VALID_P_FLASH(addr) || FLS_ADDRESS_VALID_D_FLASH(addr))

/* Internal flash block number */
#define FLS_INTERNAL_BLOCK_NUM              (2U)

/*! Invalid device instance */
#define FLS_DEVICE_INSTANCE_INVALID       (0xFFU)

#endif /* FLS_CFG_H */

