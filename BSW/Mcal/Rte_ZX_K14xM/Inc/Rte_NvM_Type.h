/**************************************************************************************************/
/**
 * @file      : Rte_NvM_Type.h
 * @brief     : AUTOSAR Rte Nvm Manager header file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef RTE_NVM_TYPE_H
#define RTE_NVM_TYPE_H

/** @addtogroup Rte_Module
 *  @{
 */

/** @addtogroup Rte_Nvm_Type
 *  @brief Rte NVM type
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define RTE_NVM_TYPE_H_AR_RELEASE_MAJOR_VERSION    4U
#define RTE_NVM_TYPE_H_AR_RELEASE_MINOR_VERSION    6U
#define RTE_NVM_TYPE_H_AR_RELEASE_REVISION_VERSION 0U
#define RTE_NVM_TYPE_H_SW_MAJOR_VERSION            1U
#define RTE_NVM_TYPE_H_SW_MINOR_VERSION            2U
#define RTE_NVM_TYPE_H_SW_PATCH_VERSION            2U
/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */
/*
 * This is an asynchronous request result returned by the API service NvM_GetErrorStatus.
 * The availability of an asynchronous request result can be additionally signaled
 * via a callback function.
 */
typedef enum
{
	/*The last asynchronous request has been finished successfully. This shall be the default value after rese*/
	NVM_REQ_OK,
	/*The last asynchronous read/write/control request has been finished unsuccessfully*/
	NVM_REQ_NOT_OK,
	/*An asynchronous read/write/control request is currently pending*/
	NVM_REQ_PENDING,
	/* The result of the last asynchronous request NvM_ReadBlock or
	* NvM_ReadAll is a data integrity failure.
	* In case of NvM_ReadBlock the content of the RAM block has changed but has become invalid.
	* The application is responsible to renew and validate the RAM block content.*/
	NVM_REQ_INTEGRITY_FAILED,
	/* The referenced block was skipped during execution of NvM_ReadAll or NvM_WriteAll,
	 * Dataset NVRAM blocks (NvM_ReadAll) or NVRAM blocks without a permanently configured RAM block.*/
	NVM_REQ_BLOCK_SKIPPED,
	/*The referenced NV block is invalidated*/
	NVM_REQ_NV_INVALIDATED,
	/*The multi block request NvM_WriteAll was cancelled by calling NvM_CancelWriteAll.*/
	NVM_REQ_CANCELED,
	/*The required redundancy of the referenced NV block is lost*/
	NVM_REQ_REDUNDANCY_FAILED,
	/*The referenced NV block had the default values copied to the RAM image.*/
	NVM_REQ_RESTORED_FROM_ROM
} NvM_RequestResultType;
	
typedef uint16 NvM_BlockIdType; 	/* req NVM471 */
	
typedef enum
{
	/*NvM_ReadBlock/ NvM_ReadPRAMBlock is requested on the block*/
	NVM_INIT_READ_BLOCK,
	/*NvM_RestoreBlockDefaults/ NvM_RestorePRAMBlockDefaults is requested on the block*/
	NVM_INIT_RESTORE_BLOCK_DEFAULTS,
	/*NvM_ReadAll is processing this block*/
	NVM_INIT_READ_ALL_BLOCK,
	/*NvM_FirstInitAll is processing this block*/
	NVM_INIT_FIRST_INIT_ALL
} NvM_InitBlockRequestType;
	
/* PRQA S 0602,0603++ */ /* MISRA Rule 21.2,Rule 1.3 */
#define _DEFINED_TYPEDEF_FOR_NvM_InitBlockRequestType_

typedef enum
{
	/*NvM_ReadBlock/ NvM_ReadPRAMBlock was performed on the block*/
	NVM_READ_BLOCK,
	/*NvM_WriteBlock/ NvM_WritePRAMBlock was performed on the block*/
	NVM_WRITE_BLOCK,
	/*NvM_RestoreBlockDefaults/ NvM_RestorePRAMBlockDefaults was performed on the block*/
	NVM_RESTORE_BLOCK_DEFAULTS,
	/*NvM_EraseNvBlock was performed on the block*/
	NVM_ERASE_NV_BLOCK,
	/*NvM_InvalidateNvBlock was performed on the block*/
	NVM_INVALIDATE_NV_BLOCK,
	/*NvM_ReadAll has finished processing this block*/
	NVM_READ_ALL_BLOCK
} NvM_BlockRequestType;
	
#define _DEFINED_TYPEDEF_FOR_NvM_BlockRequestType_
/* PRQA S 0602,0603-- */ /* MISRA Rule 21.2,Rule 1.3 */

#endif /* RTE_NVM_TYPE_H */
