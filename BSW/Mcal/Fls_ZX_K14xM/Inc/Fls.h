/**************************************************************************************************/
/**
 * @file      : Fls.h  
 * @brief     : AUTOSAR Flash driver header file
 *              - Platform: Z20K14xM
 *              - Autosar Version : 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef FLS_H
#define FLS_H

/** @addtogroup Fls_Module
 *  @{
 */

/** @addtogroup Fls
 *  @brief Flash AUTOSAR level
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Fls_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define FLS_MODULE_ID                   92U
#define FLS_VENDOR_ID                   0x00B3U
#define FLS_AR_RELEASE_MAJOR_VERSION    4U
#define FLS_AR_RELEASE_MINOR_VERSION    6U
#define FLS_AR_RELEASE_REVISION_VERSION 0U
#define FLS_SW_MAJOR_VERSION            1U
#define FLS_SW_MINOR_VERSION            2U
#define FLS_SW_PATCH_VERSION            1U

/* Check if current file and Fls_Types.h are the same vendor */
#if (FLS_VENDOR_ID != FLS_TYPES_H_VENDOR_ID)
	#error "Vendor ID of Fls.h and Fls_Types.h are different"
#endif
/* Check if current file and Fls_Types.h are the same Autosar version */
#if((FLS_AR_RELEASE_MAJOR_VERSION != FLS_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||\
    (FLS_AR_RELEASE_MINOR_VERSION != FLS_TYPES_H_AR_RELEASE_MINOR_VERSION) || \
    (FLS_AR_RELEASE_REVISION_VERSION != FLS_TYPES_H_AR_RELEASE_REVISION_VERSION))
	#error "AutoSar Version of Fls.h and Fls_Types.h are different"
#endif
/* Check if current file and Fls_Types.h are the same Software version */
#if((FLS_SW_MAJOR_VERSION != FLS_TYPES_H_SW_MAJOR_VERSION) || \
    (FLS_SW_MINOR_VERSION != FLS_TYPES_H_SW_MINOR_VERSION) || \
    (FLS_SW_PATCH_VERSION != FLS_TYPES_H_SW_PATCH_VERSION))
	#error "Software Version of Fls.h and Fls_Types.h are different"
#endif

/**
 * @brief Development errors
 */
/* SWS_Fls_00004 */
#define FLS_E_PARAM_CONFIG           0x01U /*!< API service called with wrong parameter */
#define FLS_E_PARAM_ADDRESS          0x02U /*!< API service called with wrong parameter */
#define FLS_E_PARAM_LENGTH           0x03U /*!< API service called with wrong parameter */
#define FLS_E_PARAM_DATA             0x04U /*!< API service called with wrong parameter */
#define FLS_E_UNINIT                 0x05U /*!< API service called without module initialization */
#define FLS_E_BUSY                   0x06U /*!< API service called while driver still busy */
#define FLS_E_PARAM_POINTER          0x0AU /*!< API service called with NULL pointer */

/**
 * @brief Runtime errors
 */
/* SWS_Fls_91001 */
#define FLS_E_VERIFY_ERASE_FAILED    0x07U /*!< Erase verification (blank check) failed */
#define FLS_E_VERIFY_WRITE_FAILED    0x08U /*!< Write verification (compare) failed */
#define FLS_E_TIMEOUT                0x09U /*!< Timeout exceeded */

/**
 * @brief Transient faults errors
 */
/* SWS_Fls_91002 */
#define FLS_E_ERASE_FAILED           0x01U /*!< Flash erase failed (HW) */
#define FLS_E_WRITE_FAILED           0x02U /*!< Flash write failed (HW) */
#define FLS_E_READ_FAILED            0x03U /*!< Flash read failed (HW) */
#define FLS_E_COMPARE_FAILED         0x04U /*!< Flash compare failed (HW) */
#define FLS_E_UNEXPECTED_FLASH_ID    0x05U /*!< Expected hardware ID not matched */
#define FLS_E_INIT_FAILED            0x06U /*!< Vendor specific:Flash initialization failed (HW) */

/**
 * @brief service IDs
 */
#define FLS_SID_INIT                 0x00U /*!< service ID of Fls_Init() */
#define FLS_SID_ERASE                0x01U /*!< service ID of Fls_Erase() */
#define FLS_SID_WRITE                0x02U /*!< service ID of Fls_Write() */
#define FLS_SID_CANCEL               0x03U /*!< service ID of Fls_Cancel() */
#define FLS_SID_GET_STATUS           0x04U /*!< service ID of Fls_GetStatus() */
#define FLS_SID_GET_JOB_RESULT       0x05U /*!< service ID of Fls_GetJobResult() */
#define FLS_SID_READ                 0x06U /*!< service ID of Fls_Read() */
#define FLS_SID_COMPARE              0x07U /*!< service ID of Fls_Compare() */
#define FLS_SID_SET_MODE             0x08U /*!< service ID of Fls_SetMode() */
#define FLS_SID_GET_VERSION_INFO     0x09U /*!< service ID of Fls_GetVersionInfo() */
#define FLS_SID_BLANK_CHECK          0x0AU /*!< service ID of Fls_BlankCheck() */
#define FLS_SID_MAIN_FUNCTION        0x0BU /*!< service ID of Fls_MainFunction() */
/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#if (FLS_PRECOMPILE_SUPPORT == STD_ON)
#define FLS_START_SEC_CONFIG_DATA_PTR
#include "Fls_MemMap.h"
extern const Fls_ConfigType * const Fls_PreDefinedConfigPtr;
#define FLS_STOP_SEC_CONFIG_DATA_PTR
#include "Fls_MemMap.h"
#else
#define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"
FLS_CONFIG_EXT
#define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"
#endif
/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
/**
 * @brief   Start of Fls section CODE
 */
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
/**
 * @brief     Initializes the Flash Driver. 
 *
 * @param[in] ConfigPtr: Pointer to flash driver configuration set.
 *
 * @return    None
 *
 */
void Fls_Init(const Fls_ConfigType* ConfigPtr);

/**
 * @brief     Erase one or more flash sectors. It starts an erase job asynchronously. The actual job 
 *            is performed by Fls_MainFunction() function. 
 *
 * @param[in] TargetAddress: Target address in flash memory.
 * @param[in] Length: Number of bytes to erase.
 *
 * @return    Std_ReturnType
 * @retval    E_OK - Erase command has been accepted.
 * @retval    E_NOT_OK - Erase command has not been accepted.
 *
 */
Std_ReturnType Fls_Erase(Fls_AddressType TargetAddress, Fls_LengthType Length);

/**
 * @brief     Writes one or more complete flash pages. 
 *
 * @param[in] TargetAddress: Target address in flash memory.
 * @param[in] SourceAddressPtr: Pointer to source data buffer
 * @param[in] Length: Number of bytes to write.
 *
 * @return    Std_ReturnType
 * @retval    E_OK - Write command has been accepted.
 * @retval    E_NOT_OK - Write command has not been accepted.
 *
 */
Std_ReturnType Fls_Write(Fls_AddressType TargetAddress, const uint8* SourceAddressPtr, 
                         Fls_LengthType Length );

#if(FLS_CANCEL_API == STD_ON)
/**
 * @brief     Cancels an ongoing job. 
 *
 * @param[in] None
 *
 * @return    None
 *
 */
void Fls_Cancel(void);
#endif /* FLS_CANCEL_API == STD_ON */

#if(FLS_GET_STATUS_API == STD_ON)
/**
 * @brief     Return the driver status. 
 *
 * @param[in] None
 *
 * @return    MemIf_StatusType
 * @retval    MEMIF_UNINIT
 * @retval    MEMIF_IDLE
 * @retval    MEMIF_BUSY
 *
 */
MemIf_StatusType Fls_GetStatus(void);
#endif  /* FLS_GET_STATUS_API == STD_ON */

#if(FLS_GET_JOB_RESULT_API == STD_ON)
/**
 * @brief     Returns the result of the last job.
 *
 * @param[in] None
 *
 * @return    MemIf_JobResultType
 * @retval    MEMIF_JOB_OK              Successfully completed job.
 * @retval    MEMIF_JOB_FAILED          The job has not been finished successfully.
 * @retval    MEMIF_JOB_PENDING         The job has not yet been finished.
 * @retval    MEMIF_JOB_CANCELED        The job has been canceled.
 * @retval    MEMIF_BLOCK_INCONSISTENT  1. The requested block is inconsistent, it may contain 
 *                                      corrupted data. 2. Block is NOT found.
 * @retval    MEMIF_BLOCK_INVALID       The requested block has been marked as invalid, the 
 *                                      requested operation can not be performed.
 *
 */
MemIf_JobResultType Fls_GetJobResult(void);
#endif /* FLS_GET_JOB_RESULT_API == STD_ON */

/**
 * @brief     Reads from flash memory. 
 *
 * @param[in] SourceAddress: Source address in flash memory.
 * @param[in] Length: Number of bytes to read.
 * @param[out] TargetAddressPtr: Pointer to target data buffer
 *
 * @return    Std_ReturnType
 * @retval    E_OK - Read command has been accepted.
 * @retval    E_NOT_OK - Read command has not been accepted.
 */
Std_ReturnType Fls_Read(Fls_AddressType SourceAddress, uint8* TargetAddressPtr, 
                        Fls_LengthType Length);

#if(FLS_COMPARE_API == STD_ON)
/**
 * @brief     Compares the contents of an area of flash memory with that of an application data 
 *            buffer. 
 *
 * @param[in] SourceAddress: Source address in flash memory.
 * @param[in] Length: Number of bytes to compare.
 * @param[out] TargetAddressPtr: Pointer to target data buffer
 *
 * @return    Std_ReturnType
 * @retval    E_OK - Compare command has been accepted.
 * @retval    E_NOT_OK - Compare command has not been accepted.
 *
 */
Std_ReturnType Fls_Compare(Fls_AddressType SourceAddress, const uint8* TargetAddressPtr, 
                           Fls_LengthType Length );
#endif /* FLS_COMPARE_API == STD_ON */

#if(FLS_SET_MODE_API == STD_ON)
/**
 * @brief     Sets the flash driver's operation mode.
 *
 * @param[in] Mode: MEMIF_MODE_SLOW - Slow read access / normal SPI access
 *                  MEMIF_MODE_FAST - Fast read access / SPI burst access.
 *
 * @return    None
 *
 */
void Fls_SetMode(MemIf_ModeType Mode);
#endif /* FLS_SET_MODE_API == STD_ON */

#if(FLS_VERSION_INFO_API == STD_ON)
/**
 * @brief     Returns the version information of this module.
 *
 * @param[out] VersioninfoPtr: Pointer to where to store the version information of this module.
 *
 * @return    None
 *
 */
void Fls_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr);
#endif /* FLS_VERSION_INFO_API == STD_ON */

#if(FLS_BLANK_CHECK_API == STD_ON)
/**
 * @brief     The function Fls_BlankCheck shall verify, whether a given memory area has been erased 
 *            but not (yet) programmed. The function shall limit the maximum number of checked flash
 *            cells per main function cycle to the configured value FlsMaxReadNormalMode or 
 *            FlsMaxReadFastMode respectively. 
 *
 * @param[in] TargetAddress: Address in flash memory from which the blank check should be started
 * @param[in] Length: Number of bytes to be checked for erase pattern
 *
 * @return    Std_ReturnType
 * @retval    E_OK - request for blank checking has been accepted by the module
 * @retval    E_NOT_OK - request for blank checking has not been accepted by the module
 *
 */
Std_ReturnType Fls_BlankCheck(Fls_AddressType TargetAddress, Fls_LengthType Length);
#endif /* FLS_BLANK_CHECK_API == STD_ON */

/**
 * @brief     Performs the processing of jobs.
 *
 * @param[in] None
 *
 * @return    None
 *
 */
void Fls_MainFunction(void);

/**
 * @brief   Stop of Fls section CODE
 */
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Fls */

/** @} end of group Fls_Module */

#endif /* FLS_H */
