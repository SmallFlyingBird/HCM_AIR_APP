/**************************************************************************************************/
/**
 * @file      : Fls_Drvw_Types.h
 * @brief     : Fls driver wrapper type definition file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef FLS_DRVW_TYPES_H
#define FLS_DRVW_TYPES_H

/** @addtogroup Fls_Module
 *  @{
 */

/** @addtogroup Fls_Drvw_Types
 *  @brief Fls driver wrapper level types definition
 *  @{
 */
 
#ifdef __cplusplus
extern "C" {
#endif

#include "Fls_Drvw_Cfg.h"
#include "Flash_Drv_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define FLS_DRVW_TYPES_H_VENDOR_ID                   0x00B3U
#define FLS_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define FLS_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define FLS_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define FLS_DRVW_TYPES_H_SW_MAJOR_VERSION            1U
#define FLS_DRVW_TYPES_H_SW_MINOR_VERSION            2U
#define FLS_DRVW_TYPES_H_SW_PATCH_VERSION            2U

/* Check if current file and Flash_Drv_Types.h are of the same vendor */
#if (FLS_DRVW_TYPES_H_VENDOR_ID != FLASH_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Fls_Drvw_Types.h and Flash_Drv_Types.h are different"
#endif
/* Check if current file and Flash_Drv_Types.h are of the same Autosar version */
#if ((FLS_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION != FLASH_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION != FLASH_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) || \
     (FLS_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION != \
      FLASH_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Fls_Drvw_Types.h and Flash_Drv_Types.h are different"
#endif
/* Check if current file and Flash_Drv_Types.h are of the same Software version */
#if ((FLS_DRVW_TYPES_H_SW_MAJOR_VERSION != FLASH_DRV_TYPES_H_SW_MAJOR_VERSION) || \
     (FLS_DRVW_TYPES_H_SW_MINOR_VERSION != FLASH_DRV_TYPES_H_SW_MINOR_VERSION) || \
     (FLS_DRVW_TYPES_H_SW_PATCH_VERSION != FLASH_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Fls_Drvw_Types.h and Flash_Drv_Types.h are different"
#endif

/* Check if current file and Fls_Drvw_Cfg.h are of the same vendor */
#if (FLS_DRVW_TYPES_H_VENDOR_ID != FLS_DRVW_CFG_H_VENDOR_ID)
    #error "Vendor ID of Fls_Drvw_Types.h and Fls_Drvw_Cfg.h and are different"
#endif
/* Check if current file and Fls_Drvw_Cfg.h are of the same Autosar version */
#if ((FLS_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION != FLS_DRVW_CFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION != FLS_DRVW_CFG_H_AR_RELEASE_MINOR_VERSION) || \
     (FLS_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION != FLS_DRVW_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Fls_Drvw_Types.h and Fls_Drvw_Cfg.h are different"
#endif
/* Check if current file and Fls_Drvw_Cfg.h are of the same Software version */
#if ((FLS_DRVW_TYPES_H_SW_MAJOR_VERSION != FLS_DRVW_CFG_H_SW_MAJOR_VERSION) || \
     (FLS_DRVW_TYPES_H_SW_MINOR_VERSION != FLS_DRVW_CFG_H_SW_MINOR_VERSION) || \
     (FLS_DRVW_TYPES_H_SW_PATCH_VERSION != FLS_DRVW_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Fls_Drvw_Types.h and Fls_Drvw_Cfg.h are different"
#endif
/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */
/**
 * @brief Type of job executed by Fls_MainFunction.
 */
typedef enum
{
	FLS_DRVW_JOB_ERASE = 0U,  /*!< erase one or more complete flash sectors */
	FLS_DRVW_JOB_WRITE,		 /*!< write one or more complete flash pages */
	FLS_DRVW_JOB_READ,		 /*!< read from flash memory */
	FLS_DRVW_JOB_COMPARE,	 /*!< compare the contents of an area of flash memory with that of an 
							  application data buffer */
	FLS_DRVW_JOB_BLANK_CHECK  /*!< verify whether a given memory area has been erased but not (yet) 
							  re-programmed */
} Fls_Drvw_JobType;

/**
 * @brief  Fls driver wrapper Address Type. Used as physical start address of the current job.        
 */
typedef uint32 Fls_Drvw_AddrType;

/**
 * @brief  Fls driver wrapper Length Type. Specifies the number of bytes to read/write/erase/compare
 */
typedef uint32 Fls_Drvw_LenType;

/**
 *  @brief Fls access code function pointer type
 */
typedef void (*Fls_Drvw_AcPtrType)(void (*CallBack)(void));

/**
 * @brief Fls access code callback function pointer type
 */
typedef void (*Fls_Drvw_AcCallbackPtrType)(void);

/**
 * @brief  Fls driver wrapper level temporary configuration type
 */
typedef Flash_Drv_ConfigType Fls_Drvw_TempConfigType;

/**
 *  @brief Fls driver wrapper configuration type
 */
typedef struct 
{  
    Fls_Drvw_AcPtrType AcErasePtr;                         /*!< a pointer to AC erase function */
	Fls_Drvw_AcPtrType AcWritePtr;                         /*!< a pointer to AC write function */ 
	Fls_Drvw_AcCallbackPtrType AcCallbackPtr;              /*!< a pointer to AC callback function */
	const Fls_Drvw_TempConfigType * DriverConfigSetPtr;    /*!< Pointer to configuration structure
                                                                               of internal flash. */
} Fls_Drvw_ConfigType;
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

/** @} end of group Fls_Drvw_Types */

/** @} end of group Fls_Module */

#endif /*FLS_DRVW_TYPES_H*/
