/**************************************************************************************************/
/**
 * @file      : Fls_Drvw.h  
 * @brief     : Fls driver wrapper layer header file
 *              - Platform: Z20K14xM
 *              - Autosar Version : 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef FLS_DRVW_H
#define FLS_DRVW_H

/** @addtogroup Fls_Module
 *  @{
 */

/** @addtogroup Fls_Drvw
 *  @brief Flash driver wrapper
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Fls_Drvw_Types.h"
#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#include "System.h"
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define FLS_DRVW_H_VENDOR_ID                   0x00B3U
#define FLS_DRVW_H_AR_RELEASE_MAJOR_VERSION    4U
#define FLS_DRVW_H_AR_RELEASE_MINOR_VERSION    6U
#define FLS_DRVW_H_AR_RELEASE_REVISION_VERSION 0U
#define FLS_DRVW_H_SW_MAJOR_VERSION            1U
#define FLS_DRVW_H_SW_MINOR_VERSION            2U
#define FLS_DRVW_H_SW_PATCH_VERSION            2U

/* Check if current file and Flash_Drvw_Types.h are the same vendor */
#if (FLS_DRVW_H_VENDOR_ID != FLS_DRVW_TYPES_H_VENDOR_ID)
	#error "Vendor ID of Fls_Drvw.h and Flash_Drvw_Types.h are different"
#endif
/* Check if current file and Flash_Drvw_Types.h are the same Autosar version */
#if((FLS_DRVW_H_AR_RELEASE_MAJOR_VERSION != FLS_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
	(FLS_DRVW_H_AR_RELEASE_MINOR_VERSION != FLS_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION) || \
	(FLS_DRVW_H_AR_RELEASE_REVISION_VERSION != FLS_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION))
	#error "AutoSar Version of Fls_Drvw.h and Flash_Drvw_Types.h are different"
#endif
/* Check if current file and Flash_Drvw_Types.h are the same Software version */
#if((FLS_DRVW_H_SW_MAJOR_VERSION != FLS_DRVW_TYPES_H_SW_MAJOR_VERSION) || \
	(FLS_DRVW_H_SW_MINOR_VERSION != FLS_DRVW_TYPES_H_SW_MINOR_VERSION) || \
	(FLS_DRVW_H_SW_PATCH_VERSION != FLS_DRVW_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Fls_Drvw.h and Flash_Drvw_Types.h are different"
#endif

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and System.h are the same Autosar version */
    #if ((FLS_DRVW_H_AR_RELEASE_MAJOR_VERSION != SYSTEM_H_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_DRVW_H_AR_RELEASE_MINOR_VERSION != SYSTEM_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Fls_Drvw.h and System.h are different"
    #endif
#endif
#endif
/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */
/**
 * @brief  Result of low-level flash operation.
 */
typedef enum
{
    FLS_DRVW_E_OK = 0U,                /*!< operation success */
    FLS_DRVW_E_FAILED,                 /*!< operation failed due to hardware error or input 
                                            parameters */
    FLS_DRVW_E_BLANK_CHECK,            /*!< Error - checked memory area is not erased */
    FLS_DRVW_E_COMPARE,                /*!< data buffer doesn't match content of flash memory */ 
    FLS_DRVW_E_PENDING,                /*!< operation is pending */
    FLS_DRVW_E_TIMEOUT,                /*!< Error - timeout */ 
    FLS_DRVW_E_BUSY,                   /*!< busy */
    FLS_DRVW_E_HW_FAIL,                /*!< Error - hardware fail */
    FLS_DRVW_E_CMD_ABORTED,            /*!< a flash command has been aborted  */
    FLS_DRVW_E_PARAM_DATA,             /*!< Error - wrong parameter */
} Fls_Drvw_ResultType;
/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define FLS_START_SEC_CONST_32
#include "Fls_MemMap.h"	
/* Start address and size of erase access code in flash */
extern const uint32 Fls_Drvw_AcEraseRomStart;
extern const uint32 Fls_Drvw_AcEraseSize;
/* Start address and size of write access code in flash */
extern const uint32 Fls_Drvw_AcWriteRomStart;
extern const uint32 Fls_Drvw_AcWriteSize;
#define FLS_STOP_SEC_CONST_32
#include "Fls_MemMap.h"

#define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"
FLS_DRVW_CONFIG_EXT
#define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"
/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
/**
 * @brief     Initialize flash 
 *
 * @param[in] ConfigPtr: Pointer to driver wrapper configuration set parameters.
 *
 * @return    Fls_Drvw_ResultType
 * @retval    FLS_DRVW_E_OK
 * @retval    FLS_DRVW_E_HW_FAIL
 * @retval    FLS_DRVW_E_BUSY
 * @retval    FLS_DRVW_E_PARAM_DATA
 *
 */
Fls_Drvw_ResultType Fls_Drvw_Init(const Fls_Drvw_ConfigType * ConfigPtr);

#if(FLS_DRVW_CANCEL_API == STD_ON)
/** 
 * @brief     Check if the hardware is idle or not
 *
 * @param[in] none
 *
 * @return    boolean
 * @retval    TRUE: hardware is idle
 * @retval    FALSE: hardware is busy
 *
 */
boolean Fls_Drvw_CheckHwStatus(void);

/**
 * @brief     Unload the flash access code for cancelling a job
 *
 * @param[in] Job: the current job
 *
 * @return    none
 *
 */
void Fls_Drvw_Cancel(Fls_Drvw_JobType Job);
#endif /* FLS_DRVW_CANCEL_API == STD_ON */

/**
 * @brief     Handle asynchronous job 
 *
 * @param[in] PhyAddr: physical start address of the current job
 * @param[in] Length: the length of data in byte
 *
 * @return    Fls_Drvw_ResultType
 * @retval    FLS_DRVW_E_BUSY
 * @retval    FLS_DRVW_E_FAILED
 * @retval    FLS_DRVW_E_TIMEOUT
 * @retval    FLS_DRVW_E_OK
 * @retval    FLS_DRVW_E_BLANK_CHECK
 *
 */
Fls_Drvw_ResultType Fls_Drvw_HandleAsyncEraseJob(Fls_Drvw_AddrType PhyAddr, 
                                                 Fls_Drvw_LenType Length);

/**
 * @brief     Handle asynchronous job 
 *
 * @param[in] PhyAddr: physical start address of the current job
 * @param[in] DataSrcPtr: Pointer to the source data buffer
 * @param[in] Length: the length of data in byte
 *
 * @return    Fls_Drvw_ResultType
 * @retval    FLS_DRVW_E_BUSY
 * @retval    FLS_DRVW_E_FAILED
 * @retval    FLS_DRVW_E_TIMEOUT
 * @retval    FLS_DRVW_E_OK
 * @retval    FLS_DRVW_E_COMPARE
 *
 */
Fls_Drvw_ResultType Fls_Drvw_HandleAsyncWriteJob(Fls_Drvw_AddrType PhyAddr, 
                                                 const uint8 * DataSrcPtr, 
                                                 Fls_Drvw_LenType Length);

/**
 * @brief      Read flash data from a logical sector
 *
 * @param[in]  PhyAddr: physical start address of the current job
 * @param[in]  Len: the length of data to be read
 * @param[in]  DataDestPtr: Pointer to the destination buffer where to store the readout data
 *
 * @return    Fls_Drvw_ResultType
 * @retval    FLS_DRVW_E_OK
 * @retval    FLS_DRVW_E_FAILED
 *
 */
Fls_Drvw_ResultType Fls_Drvw_ReadSector(Fls_Drvw_AddrType PhyAddr, 
                                        const Fls_Drvw_LenType Len, 
                                        uint8 const * DataDestPtr);

#if(FLS_DRVW_COMPARE_API == STD_ON)
/**
 * @brief      Compare flash data in a logical sector with the data in a buffer
 *
 * @param[in]  PhyAddr: physical start address of the current job
 * @param[in]  Len: the length of data to be read
 * @param[in]  DataSrcPtr: Pointer to a source buffer where the compare data is stored
 *
 * @return    Fls_Drvw_ResultType
 * @retval    FLS_DRVW_E_OK
 * @retval    FLS_DRVW_E_COMPARE
 * @retval    FLS_DRVW_E_FAILED
 *
 */
Fls_Drvw_ResultType Fls_Drvw_CompareSector(Fls_Drvw_AddrType PhyAddr, 
                                           const Fls_Drvw_LenType Len, 
                                           const uint8 * DataSrcPtr);
#endif

#if(FLS_DRVW_BLANK_CHECK_API == STD_ON)
/**
 * @brief      Check if the flash data is equal to the erased value
 *
 * @param[in]  PhyAddr: physical start address of the current job
 * @param[in]  Len: the length of data to be read
 *
 * @return    Fls_Drvw_ResultType
 * @retval    FLS_DRVW_E_OK
 * @retval    FLS_DRVW_E_BLANK_CHECK
 * @retval    FLS_DRVW_E_FAILED
 *
 */
Fls_Drvw_ResultType Fls_Drvw_BlankCheckSector(Fls_Drvw_AddrType PhyAddr, 
                                              const Fls_Drvw_LenType Len);
#endif

/**
 * @brief     Erase a physical sector in the current working logical sector
 *
 * @param[in] PhyAddr: physical start address of the current job
 * @param[in] AsyncFlag: it indicates if the operation is in asynchronous mode
 *
 * @return    Fls_Drvw_ResultType
 * @retval    FLS_DRVW_E_OK
 * @retval    FLS_DRVW_E_BLANK_CHECK
 * @retval    FLS_DRVW_E_FAILED
 * @retval    FLS_DRVW_E_PENDING
 * @retval    FLS_DRVW_E_BUSY
 * @retval    FLS_DRVW_E_TIMEOUT
 *
 */
Fls_Drvw_ResultType Fls_Drvw_EraseSector(Fls_Drvw_AddrType PhyAddr, const boolean AsyncFlag);

/**
* @brief 	 Write data in the current working logical sector
*
* @param[in]  PhyAddr: physical start address of the current job
* @param[in]  Len: the length of data to be written
* @param[in]  DataSrcPtr: Pointer to the data buffer that will be written into flash
* @param[in]  AsyncFlag: it indicates if the operation is in asynchronous mode
*
* @return	Fls_Drvw_ResultType
* @retval	FLS_DRVW_E_OK
* @retval	 FLS_DRVW_E_BLANK_CHECK
* @retval	 FLS_DRVW_E_COMPARE
* @retval	FLS_DRVW_E_FAILED
* @retval	FLS_DRVW_E_PENDING
* @retval	FLS_DRVW_E_BUSY
* @retval	FLS_DRVW_E_TIMEOUT
*
*/
Fls_Drvw_ResultType Fls_Drvw_WriteSector(Fls_Drvw_AddrType PhyAddr,
                                                  Fls_Drvw_LenType Len, 
                                                  const uint8 * DataSrcPtr, 
                                                  const boolean AsyncFlag);

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Fls_Drvw */

/** @} end of group Fls_Module */

#endif /* FLS_DRVW_H */
