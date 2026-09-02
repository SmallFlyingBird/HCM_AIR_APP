/**
 * @file    Fls_Types.h
 * @version
 *
 * @brief   AUTOSAR Fls module interface
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

#ifndef FLS_TYPES_H
#define FLS_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif
/*
 * @page misra_violations MISRA-C:2012 violations list
 * PRQA S 0779 Rule 5.2: Identifiers declared in the same scope and name space shall be distinct.
 *
 */


/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include "Std_Types.h"
#include "MemIf_Types.h"
#include "Fls_Cfg.h"
#include "Fls_Lld_Reg.h"
#if(FLS_QSPI_SECTORS_CONFIGURED==STD_ON)
#include "Fls_Qspi_Types.h"
#endif

/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_TYPES_VENDOR_ID                      (180)
#define FLS_TYPES_AR_RELEASE_MAJOR_VERSION       (4)
#define FLS_TYPES_AR_RELEASE_MINOR_VERSION       (4)
#define FLS_TYPES_AR_RELEASE_REVISION_VERSION    (0)
#define FLS_TYPES_SW_MAJOR_VERSION               (2)
#define FLS_TYPES_SW_MINOR_VERSION               (3)
#define FLS_TYPES_SW_PATCH_VERSION               (0)


/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
#if (FLS_QSPI_SECTORS_CONFIGURED==STD_ON)

/* Check if source file and Fls_Qspi_types.h file are of the same vendor */
#if (FLS_TYPES_VENDOR_ID != FLS_QSPI_TYPES_VENDOR_ID)
#error "Fls_Types.h and Fls_Qspi_Types.h have different vendor ids"
#endif

/* Check if source file and Fls_Qspi_types.h file are of the same Autosar version */
#if ((FLS_TYPES_AR_RELEASE_MAJOR_VERSION != FLS_QSPI_TYPES_AR_REL_MAJOR_VERSION) || \
     (FLS_TYPES_AR_RELEASE_MINOR_VERSION != FLS_QSPI_TYPES_AR_REL_MINOR_VERSION) || \
     (FLS_TYPES_AR_RELEASE_REVISION_VERSION != FLS_QSPI_TYPES_AR_REL_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Fls_Types.h and Fls_Qspi_Types.h are different"
#endif

/* Check if source file and Fls_Qspi_types.h file are of the same software version */
#if ((FLS_TYPES_SW_MAJOR_VERSION != FLS_QSPI_TYPES_SW_MAJOR_VERSION) || \
     (FLS_TYPES_SW_MINOR_VERSION != FLS_QSPI_TYPES_SW_MINOR_VERSION) || \
     (FLS_TYPES_SW_PATCH_VERSION != FLS_QSPI_TYPES_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Fls_Types.h and Fls_Qspi_Types.h are different"
#endif

#endif
/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
#define FLS_INVALID_SECTOR_INDEX              (0xFFFFU)
/*==================================================================================================
 *                                         EXTERNAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                             ENUMS
==================================================================================================*/

/**
 * @brief      Fls Address Type
 * @details       Target address type of the flash device.
 */
typedef uint32  Fls_AddressType;

/**
 * @brief     Fls Length Type
 * @details      Flash length type of the flash device.
 */
typedef uint32 Fls_LengthType;

/**
 * @brief Fls Sector Protect Type
 * @details   Fls sectors protect configuration data type of the flash device.
 */
typedef uint32 Fls_SectorProtectType;

/**
* @brief          Logical sector index.
*/
typedef uint32 Fls_SectorIndexType;

/**
 * @brief      Fls Job End Notification Pointer Type
 * @details       Pointer type of Fls_JobEndNotification function
 */
typedef void (*Fls_JobEndNotificationPtrType)(void);
/**
 * @brief      Fls Job Error Notification Pointer Type
 * @details       Pointer type of Fls_JobErrorNotification function
 */
typedef void (*Fls_JobErrorNotificationPtrType)(void);

#if (FLS_HANDLE_BUSFAULT_INDEPENDENT ==STD_ON)||(FLS_ECC_ERROR_INTERRUPT_ENABLE == STD_ON)
/**
 * @brief      Fls read caused bus fault notification
 * @details    Pointer type of irq handle function.
 */
typedef void (*Fls_NotificationPtrType)(void);
#endif

/**
 * @brief      Fls Callback Type
 * @details       Pointer type of Fls callback function
 */
typedef void (*Fls_CallbackType)(void);

/**
 * @brief      Fls AcErase Pointer Type
 * @details       Pointer type of Fls_AcErase function
 */
typedef void (*Fls_AcErasePtrType)(const EFM_Type *Base, Fls_CallbackType CallBack);

/**
 * @brief      Fls AcWrite Pointer Type
 * @details       Pointer type of Fls_AcWrite function
 */
typedef void (*Fls_AcWritePtrType)(const EFM_Type *Base, Fls_CallbackType CallBack);

/**
* @brief     Fls Job Type
* @details   Type of job currently executed by Fls_MainFunction.
*/
typedef enum
{
    FLS_JOB_ERASE = 0U,      /*!< Erase one or more complete flash sectors */
    FLS_JOB_WRITE = 1U,          /*!< Write one or more complete flash pages */
    FLS_JOB_READ = 2U,           /*!< Read one or more bytes from flash memory */
    FLS_JOB_COMPARE = 3U,        /*!< Compare data buffer with content of flash memory */
    FLS_JOB_BLANK_CHECK = 4U,    /*!< Check content of erased flash memory area */
    FLS_JOB_IDLE = 5U            /*!< Job idle */
} Fls_JobType;

/**
* @brief     Fls Job Result Type
* @details   Result of low-level flash operation.
*/
typedef enum
{
    FLASH_E_OK = 0U,                 /*!<  Operation succeeded */
    FLASH_E_FAILED = 1U,                 /*!<  Operation failed due to hardware error */
    FLASH_E_BLOCK_INCONSISTENT = 2U,     /*!<  Data buffer doesn't match with content of flash memory */
    FLASH_E_PENDING = 3U,                /*!<  Operation is pending */
    FLASH_E_PARTITION_ERR = 4U           /*!<  FlexNVM partition ratio error */
} Fls_Lld_ReturnType;

/**
* @brief   Fls LLD Job Type
* @details Type of job currently executed by Fls_LLDMainFunction.
*/
typedef enum
{
    FLASH_JOB_NONE = 0U, /*!< No job executed by Fls_LLDMainFunction  */
    FLASH_JOB_ERASE = 1U, /*!< Erase one flash sector */
    FLASH_JOB_ERASE_TEMP = 2U, /*!< Complete erase and start an interleaved erase flash sector */
    FLASH_JOB_WRITE = 3U,  /*!< Write one or more complete flash pages */
    FLASH_JOB_ERASE_BLANK_CHECK = 4u  /*!< Erase blank check of flash sector */
} Fls_Lld_JobType;

/**
    @brief Flash sector channel type.
*/
typedef enum
{
    FLS_CH_INTERN = 0,
    FLS_CH_QSPI = 1
} Fls_HwChType;

/**
 * @brief     Fls Sector Type
 * @details   Fls sector type of the flash device.
 */
typedef struct
{
    uint32 SectorId; /*!< Number of continuous sectors with identical values for FlsSectorSize and FlsPageSize.*/
    Fls_AddressType SectorStartAddress; /*!< Start address of this sector. */
    Fls_LengthType SectorSize; /*!< logic size of this sector. */
    Fls_LengthType PageSize; /*!< Size of one page of this sector. */
    Fls_AddressType SectorHwStartAddress; /*!< Start address of this sector in hardware. */
    Fls_LengthType PhySectorSize;   /*!< Physical sector size of this sector for each earase command. */
    boolean      AsyncAccess; /*!< Access flag if this sector support async erase or async write. */
    Fls_HwChType SectorHwCh; /*!< The hardware channel of this sector. */
#if(FLS_QSPI_SECTORS_CONFIGURED==STD_ON)
    uint8  SectFlashUnit; /*!<  External flash unit assigned to each sector. */
#endif
} Fls_SectorType;

/**
* @brief   Fls Job State Strcuture
* @details The data store the job state, operation datas and result.
*/
typedef struct
{
    MemIf_JobResultType JobResult;      /**<  Job result type */
    Fls_AddressType JobCurrentAddr;     /**<  Job current address */
    Fls_AddressType JobEndAddr;         /**<  Job end address */
    Fls_JobType JobType;                /**<  Job type */
    const uint8 *JobWriteDataPtr;       /**<  Job write data pointer */
    uint8 *JobReadDataPtr;              /**<  Job read data pointer */
    uint8 JobStart;                     /**<  Job start flag data>*/
    uint16 JobSectorIt;                 /**<  Whitch flash sector currently processed by a job>*/
    uint16 JobSectorEnd;                /**<  Last logical address to be processed by a job>*/
} Fls_JobStateType;

/**
    @brief Enumeration of checking status errors or not.
*/
/* MR12 Rule 5.2 VIOLATION: In this specific case, the STATUS_FTFC_FLS_IP_ERROR_USER_TEST_BREAK_DBD is
*                           a federation member reserved for further functions, it couldn't adhere to M3CM Rule-5.2.
*/
typedef enum
{
    STATUS_FTFC_FLS_IP_SUCCESS                   = 0x5AA5U,    /*!< Successful job */
    STATUS_FTFC_FLS_IP_BUSY                      = 0xE742U,    /*!< IP is performing an operation */
    STATUS_FTFC_FLS_IP_ERROR                     = 0x27E4U,    /*!< Error - general code */
    STATUS_FTFC_FLS_IP_ERROR_TIMEOUT             = 0x2BD4U,    /*!< Error - exceeded timeout */
    STATUS_FTFC_FLS_IP_ERROR_INPUT_PARAM         = 0x2DB4U,    /*!< Error - wrong input parameter */
    STATUS_FTFC_FLS_IP_ERROR_BLANK_CHECK         = 0x2E74U,    /*!< Error - selected memory area is not erased */
    STATUS_FTFC_FLS_IP_ERROR_PROGRAM_VERIFY      = 0x33CCU,    /*!< Error - selected memory area doesn't contain desired value */
    STATUS_FTFC_FLS_IP_ERROR_USER_TEST_BREAK_SBC = 0x35ACU,    /*!< Error - single bit correction */
    STATUS_FTFC_FLS_IP_ERROR_USER_TEST_BREAK_DBD = 0x366CU,    /*!< Error - double bit detection */ /*PRQA S 0779*/
    STATUS_FTFC_FLS_IP_SECTOR_UNPROTECTED        = 0xFA22U,    /*!< Checked sector is unlocked */
    STATUS_FTFC_FLS_IP_SECTOR_PROTECTED          = 0xE8B8U     /*!< Checked sector is locked */
} Fls_Lld_StatusType;

#if(FLS_QSPI_SECTORS_CONFIGURED==STD_ON)
/**

*/
typedef struct
{
    /**
    * @brief Connection for each external memory device to available controllers. Size: FlashUnitsCount
    */
    const Qspi_MemoryConnectionType *FlashConnectionCfg;
    /**
    * @brief Configuration index used for each flash unit. Size: FlashUnitsCount
    */
    uint8 FlashUnitId;
    /**
    * @brief AHB direct reads configurations. Size: FlashUnitsCount
    */
    boolean AHBReadCfg;

} Fls_QspiFlsMenConfigType;
/**
* @brief          External fls Config Type
* @details        External fls Config Type
*/
typedef struct
{
    /**
    * @brief Number of serial flash instances.
    */
    uint8 FlashUnitsCount;
    /**
    * @brief External Flash devices configurations. Size: FlashUnitsCount
    */
    const Fls_QspiFlsMenConfigType *FlashMemCfg;
    /**
    * @brief Number of serial flash configurations.
    */
    uint8 FlashConfigCount;
    /**
    * @brief External memory devices configurations. Size: FlashConfigCount
    */
    const Qspi_MemoryConfigType *MemCfg;
    /**
    * @brief Number of QSPI hardware instances.
    */
    uint8 QspiUnitsCount;
    /**
    * @brief Configuration for each QSPI unit. Size: QspiUnitsCount
    */
    const uint8 *QspiConfig;
    /**
    * @brief Number of QSPI configurations.
    */
    uint8 QspiConfigCount;
    /**
    * @brief QSPI configurations. Size: QspiConfigCount
    */
    const Qspi_ControllerConfigType *QspiUnitCfg;
} Fls_ExtFlsConfigType;
#endif


/* FlsConfigSet */

/**
 * @brief    Fls Driver Configuration Structure
 * @details  Container for runtime configuration parameters of the flash driver.
 * @note            trace: ECUC_Fls_00174
 */
typedef struct
{

    Fls_AcErasePtrType AcEraseFunPtr; /*!< Address offset in RAM to which the erase flash access code shall be loaded.*/
    Fls_AcWritePtrType AcWriteFunPtr; /*!< Address offset in RAM to which the write flash access code shall be loaded.*/
    Fls_JobEndNotificationPtrType JobEndNotificationFunPtr;/*!< The job end notification ptr routine provided by some upper layer module.*/
    Fls_JobErrorNotificationPtrType JobErrorNotificationFunPtr;/*!< The job error notification ptr routine provided by some upper layer module.*/
#if (FLS_HANDLE_BUSFAULT_INDEPENDENT == STD_ON)
    Fls_NotificationPtrType BusFaultNotificationFunPtr; /*!< The bus fault notification ptr routine provided by some upper layer module.*/
#endif
#if (FLS_ECC_ERROR_INTERRUPT_ENABLE == STD_ON)
    Fls_NotificationPtrType EccErrorNotificationFunPtr; /*!< The ECC error notification ptr routine provided by some upper layer module.*/
#endif
    MemIf_ModeType DefaultMode;/*!< The default mode of the flash driver after initialization.*/
    Fls_LengthType MaxReadFastMode; /*!< The maximum number of bytes to read or compare in one cycle of the flash driver's job processing function in fast mode.*/
    Fls_LengthType MaxReadNormalMode;/*!< The maximum number of bytes to read or compare in one cycle of the flash driver's job processing function in normal mode.*/
    Fls_LengthType MaxWriteFastMode;/*!< The maximum number of bytes to write in one cycle of the flash driver's job processing function in fast mode.*/
    Fls_LengthType MaxWriteNormalMode;/*!< The maximum number of bytes to write in one cycle of the flash driver's job processing function in normal mode.*/
    uint16 ConfiguredSectorNumber;/*!< The number of configured flash sectors.*/
    Fls_SectorType const *SectorList; /*!< List of flashable sectors and pages.*/
#if (FLS_INTERNAL_SECTORS_PROTECTION==STD_ON)
    Fls_SectorProtectType const *SectorProtection; /*!< List of protecting sectors configured data.*/
#endif
#if(FLS_QSPI_SECTORS_CONFIGURED==STD_ON)
    Fls_ExtFlsConfigType const *ExtFlsCfgConfig;  /*!<  Pointer to configuration structure of external flash.*/
#endif

} Fls_ConfigType;


#ifdef __cplusplus
}
#endif

#endif /* FLS_H */

/** @} */

