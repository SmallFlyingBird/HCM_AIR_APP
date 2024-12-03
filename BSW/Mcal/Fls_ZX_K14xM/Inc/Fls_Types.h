/**************************************************************************************************/
/**
 * @file      : Fls_Types.h  
 * @brief     : AUTOSAR Flash driver types definition header file
 *              - Platform: Z20K14xM
 *              - Autosar Version : 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef FLS_TYPES_H
#define FLS_TYPES_H

/** @addtogroup Fls_Module
 *  @{
 */

/** @addtogroup Fls
 *  @brief Fls types definition
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Fls_Cfg.h"
#include "Fls_Drvw_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define FLS_TYPES_H_VENDOR_ID                   0x00B3U
#define FLS_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define FLS_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define FLS_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define FLS_TYPES_H_SW_MAJOR_VERSION            1U
#define FLS_TYPES_H_SW_MINOR_VERSION            2U
#define FLS_TYPES_H_SW_PATCH_VERSION            2U

/* Check if current file and Fls_Cfg.h are the same vendor */
#if (FLS_TYPES_H_VENDOR_ID != FLS_CFG_H_VENDOR_ID)
	#error "Vendor ID of Fls_Types.h and Fls_Cfg.h are different"
#endif
/* Check if current file and Fls_Cfg.h are the same Autosar version */
#if((FLS_TYPES_H_AR_RELEASE_MAJOR_VERSION != FLS_CFG_H_AR_RELEASE_MAJOR_VERSION) || \
	(FLS_TYPES_H_AR_RELEASE_MINOR_VERSION != FLS_CFG_H_AR_RELEASE_MINOR_VERSION) || \
	(FLS_TYPES_H_AR_RELEASE_REVISION_VERSION != FLS_CFG_H_AR_RELEASE_REVISION_VERSION))
	#error "AutoSar Version of Fls_Types.h and Fls_Cfg.h are different"
#endif
/* Check if current file and Fls_Cfg.h are the same Software version */
#if((FLS_TYPES_H_SW_MAJOR_VERSION != FLS_CFG_H_SW_MAJOR_VERSION) || \
	(FLS_TYPES_H_SW_MINOR_VERSION != FLS_CFG_H_SW_MINOR_VERSION) || \
	(FLS_TYPES_H_SW_PATCH_VERSION != FLS_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Fls_Types.h and Fls_Cfg.h are different"
#endif

/* Check if current file and Flash_Drvw_Types.h are the same vendor */
#if (FLS_TYPES_H_VENDOR_ID != FLS_DRVW_TYPES_H_VENDOR_ID)
	#error "Vendor ID of Fls_Types.h and Flash_Drvw_Types.h are different"
#endif
/* Check if current file and Flash_Drvw_Types.h are the same Autosar version */
#if((FLS_TYPES_H_AR_RELEASE_MAJOR_VERSION != FLS_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
	(FLS_TYPES_H_AR_RELEASE_MINOR_VERSION != FLS_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION) || \
	(FLS_TYPES_H_AR_RELEASE_REVISION_VERSION != FLS_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION))
	#error "AutoSar Version of Fls_Types.h and Flash_Drvw_Types.h are different"
#endif
/* Check if current file and Flash_Drvw_Types.h are the same Software version */
#if((FLS_TYPES_H_SW_MAJOR_VERSION != FLS_DRVW_TYPES_H_SW_MAJOR_VERSION) || \
	(FLS_TYPES_H_SW_MINOR_VERSION != FLS_DRVW_TYPES_H_SW_MINOR_VERSION) || \
	(FLS_TYPES_H_SW_PATCH_VERSION != FLS_DRVW_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Fls_Types.h and Flash_Drvw_Types.h are different"
#endif
/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */
/**
 * @brief  Type of job executed by Fls_MainFunction.
 */
typedef enum
{
    FLS_JOB_ERASE = 0U,  /*!< erase one or more complete flash sectors */
    FLS_JOB_WRITE,       /*!< write one or more complete flash pages */
    FLS_JOB_READ,        /*!< read from flash memory */
    FLS_JOB_COMPARE,     /*!< compare the contents of an area of flash memory with that of an 
                              application data buffer */
    FLS_JOB_BLANK_CHECK  /*!< verify whether a given memory area has been erased but not (yet) 
                              re-programmed */
} Fls_JobType;
	
typedef enum
{
	MEMIF_UNINIT = 0,
	MEMIF_IDLE = 1,
	MEMIF_BUSY = 2,
	MEMIF_BUSY_INTERNAL = 3
} MemIf_StatusType;
	
typedef enum
{
	MEMIF_JOB_OK = 0,
	MEMIF_JOB_FAILED = 1,
	MEMIF_JOB_PENDING = 2,
	MEMIF_JOB_CANCELED = 3,
	MEMIF_BLOCK_INCONSISTENT = 4,
	MEMIF_BLOCK_INVALID = 5
} MemIf_JobResultType;

typedef enum
{
    /*The underlying memory abstraction modules and drivers are working in slow mode.*/
    MEMIF_MODE_SLOW = 0,
    /*The underlying memory abstraction modules and drivers are working in fast mode.*/
    MEMIF_MODE_FAST = 1
} MemIf_ModeType;

/**
 * @brief  Fls Address Type. Used as address offset from the configured flash base address to access
 *         a certain flash memory area
 */
/* SWS_Fls_00369, SWS_Fls_00216 */
typedef Fls_Drvw_AddrType Fls_AddressType;

/**
 * @brief  Fls Length Type. Specifies the number of bytes to read/write/erase/compare
 */
/* SWS_Fls_00370 */
typedef Fls_Drvw_LenType Fls_LengthType;

/**
 * @brief   Fls logical sector index type
 */
typedef uint32 Fls_SectorIndexType;

/**
 * @brief   Fls Notification function pointer type
 */
/* SWS_Fls_00110 */
typedef void (*Fls_NotificationPtrType)(void);

/**
 * @brief   Temp configuration type
 */
typedef Fls_Drvw_ConfigType Fls_TempConfigType;

/**
 * @brief Flash access code callback function pointer type
 */
typedef void (*Fls_AcCallbackPtrType)(void); 

/**
    @brief  access code function pointer type
*/
typedef void (*Fls_AcPtrType)(void (*CallBack)(void));

/**
 * @brief   Fls logical sector configuration type
 */
typedef struct 
{    
    Fls_LengthType SectorSize;   /*!< the physical sector size */    
    Fls_LengthType PageSize;     /*!< the page size */
    Fls_AddressType EndAddr;     /*!< the end address of this logical sector */
    Fls_AddressType PhysicalStartAddr; /*!< the physical start address of this 
                                            logical sector */
    boolean EraseAsyncFlag;       /*!< it indicates if the erase operation
                                      on this sector is asynchronous*/
    boolean WriteAsyncFlag;       /*!< it indicates if the write operation
                                      on this sector is asynchronous*/
     
} Fls_SectorConfigType;

/**
 * @brief   Fls configuration type
 */
/* SWS_Fls_00368, SWS_Fls_00109 */
typedef struct 
{   
    Fls_NotificationPtrType JobEndNotificationPtr;   /*!< a pointer to job end 
                                                          notification function */    
    Fls_NotificationPtrType JobErrorNotificationPtr; /*!< a pointer to job error 
                                                          notification function */   
    MemIf_ModeType DefaultMode;                      /*!< default FLS device mode 
                                                          after initialization */
    Fls_LengthType MaxReadFastMode;     /*!< The maximum number of bytes to read or compare 
                                             in one cycle of Fls_MainFunction in fast mode */     
    Fls_LengthType MaxReadNormalMode;   /*!< The maximum number of bytes to read or compare
                                             in one cycle of Fls_MainFunction in normal mode */    
    Fls_LengthType MaxWriteFastMode;    /*!< The maximum number of bytes to write in 
                                             one cycle of Fls_MainFunction in fast mode */    
    Fls_LengthType MaxWriteNormalMode;  /*!< The maximum number of bytes to write in 
                                             one cycle of Fls_MainFunction in normal mode */
    uint32 SectorNum;                   /*!< The total logical sector number in the sector list */ 
    const Fls_SectorConfigType * const *SectorList;        /*!< It points to the sector list */
	const Fls_TempConfigType * WrapperConfigSetPtr; /*!< Pointer to configuration structure
                                                               defined in driver wrapper level. */
} Fls_ConfigType;

/**
 * @brief   Fls runtime job parameter type
 */
typedef struct 
{      
    Fls_JobType Job;                /*!< The job that is executing or the last job */
    MemIf_JobResultType JobResult;  /*!< The job result */ 
    Fls_SectorIndexType SectorCur;  /*!< Current sector that is being accessed */ 
    Fls_SectorIndexType SectorEnd;  /*!< End sector of the job */ 
    Fls_AddressType AddrCur;        /*!< Current address that is being accessed */ 
    Fls_AddressType AddrEnd;        /*!< End address of the job */ 
    const uint8 * DataSrcPtr;       /*!< Pointer to the source data buffer */ 
    uint8 * DataDestPtr;            /*!< Pointer to the destination data buffer */ 
    boolean AsyncExecutingFlag;     /*!< Job executing in asynchronous mode or not */ 
} Fls_JobParamType;
/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *	@{
 */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *	@{
 */

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Fls */

/** @} end of group Fls_Module */

#endif /* FLS_TYPES_H */
