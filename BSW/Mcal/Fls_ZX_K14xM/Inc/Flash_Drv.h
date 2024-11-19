/**************************************************************************************************/
/**
 * @file      : Flash_Drv.h  
 * @brief     : Internal flash low level driver header file
 *              - Platform: Z20K14xM
 *              - Autosar Version : 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef FLASH_DRV_H
#define FLASH_DRV_H

/** @addtogroup Fls_Module
 *  @{
 */

/** @addtogroup Flash_Drv
 *  @brief Internal Flash low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Flash_Drv_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define FLASH_DRV_H_VENDOR_ID                   0x00B3U
#define FLASH_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define FLASH_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define FLASH_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define FLASH_DRV_H_SW_MAJOR_VERSION            1U
#define FLASH_DRV_H_SW_MINOR_VERSION            2U
#define FLASH_DRV_H_SW_PATCH_VERSION            2U

/* Check if current file and Flash_Drv_Types.h are the same vendor */
#if (FLASH_DRV_H_VENDOR_ID != FLASH_DRV_TYPES_H_VENDOR_ID) 
    #error "Vendor ID of Flash_Drv.h and Flash_Drv_Types.h are different"
#endif
/* Check if current file and Flash_Drv_Types.h are the same Autosar version */
#if((FLASH_DRV_H_AR_RELEASE_MAJOR_VERSION != FLASH_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
	(FLASH_DRV_H_AR_RELEASE_MINOR_VERSION != FLASH_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) || \
	(FLASH_DRV_H_AR_RELEASE_REVISION_VERSION != FLASH_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Flash_Drv.h and Flash_Drv_Types.h are different"
#endif
/* Check if current file and Flash_Drv_Types.h are the same Software version */
#if((FLASH_DRV_H_SW_MAJOR_VERSION != FLASH_DRV_TYPES_H_SW_MAJOR_VERSION) || \
	(FLASH_DRV_H_SW_MINOR_VERSION != FLASH_DRV_TYPES_H_SW_MINOR_VERSION) || \
	(FLASH_DRV_H_SW_PATCH_VERSION != FLASH_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Flash_Drv.h and Flash_Drv_Types.h are different"
#endif

/**
 * @brief Flash block numbers
 *
 */
#define FLASH_DRV_BLOCK_INVALID      0U
#define FLASH_DRV_BLOCK_PFLASH       1U
#define FLASH_DRV_BLOCK_DFLASH       2U
/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"		
FLASH_DRV_CONFIG_EXT
#define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_CLEARED_32
#include "Fls_MemMap.h"

#if(FLASH_DRV_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
extern uint32 Flash_Drv_ElapsedTicks;
extern uint32 Flash_Drv_TimeoutTicks;
#endif /* (FLASH_DRV_TIMEOUT_SUPERVISION_ENABLED == STD_ON) */

#define FLS_STOP_SEC_VAR_CLEARED_32
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fls_MemMap.h"
extern Flash_Drv_ReadStateType Flash_Drv_ReadState;
#define FLS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fls_MemMap.h"
/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
/**
 * @brief     De-initialize flash
 *
 * @param[in] None
 *
 * @return    None
 *
 */
void Flash_Drv_DeInit(void);

/**
 * @brief     Initialize internal flash 
 *
 * @param[in] ConfigPtr: Pointer to internal flash driver configuration parameters.
 *
 * @return    Flash_Drv_ReturnType
 * @retval    FLASH_DRV_SUCCESS
 * @retval    FLASH_DRV_BUSY
 * @retval    FLASH_DRV_ERR_HW_FAIL
 *
 */
Flash_Drv_ReturnType Flash_Drv_Init(const Flash_Drv_ConfigType* ConfigPtr);

/** 
 * @brief     Check if the flash controller is idle or not
 *
 * @param[in] none
 *
 * @return    boolean
 * @retval    TRUE: flash controller is idle
 * @retval    FALSE: flash controller is busy
 *
 */
boolean Flash_Drv_CheckIdleStatus(void);

/**
 * @brief     Abort flash operation. 
 *
 * @param[in] none
 *
 * @return    Flash_Drv_ReturnType
 * @retval    FLASH_DRV_SUCCESS - command is finished successfully, so no command is aborted
 * @retval    FLASH_DRV_CMD_ABORTED
 * @retval    FLASH_DRV_ERR_TIMEOUT
 *
 */
Flash_Drv_ReturnType Flash_Drv_Abort(void);

/**
 * @brief     Erase one flash sector 
 *
 * @param[in] Addr: sector start address in flash memory.
 * @param[in] CmdActPtr: It points to the command action configuration.
 *
 * @return    Flash_Drv_ReturnType
 * @retval    FLASH_DRV_SUCCESS
 * @retval    FLASH_DRV_BUSY
 * @retval    FLASH_DRV_ERR_INPUT_PARAM
 * @retval    FLASH_DRV_ERR_TIMEOUT
 *
 */
Flash_Drv_ReturnType Flash_Drv_EraseSector(const uint32 Addr, 
                                           const Flash_Drv_CmdActionType * CmdActPtr);

/**
 * @brief  Program data with specified length into the flash memory array. 
 *
 * @param[in] FlashAddr: phrase start address where to write in the flash memory. This address 
 *                       should be aligned to 4 words(16 bytes)
 * @param[in] Len: the length of data to be written. This length should be aligned to 
 *                 4 words(16 bytes).
 * @param[in] SourceAddrPtr: point to the Source buffer
 * @param[in] CmdActPtr: It points to the command action configuration.
 *
 * @return    Flash_Drv_ReturnType
 * @retval    FLASH_DRV_SUCCESS
 * @retval    FLASH_DRV_BUSY
 * @retval    FLASH_DRV_ERR_INPUT_PARAM
 * @retval    FLASH_DRV_ERR_TIMEOUT
 *
 */
Flash_Drv_ReturnType Flash_Drv_Write(const uint32 FlashAddr, const uint32 Len,
                                     const uint8 *SourceAddrPtr,  
                                     const Flash_Drv_CmdActionType * CmdActPtr);

/**
 * @brief  Read data from the flash memory array. 
 *
 * @param[in] SrcAddr: start address where to read in the flash memory.
 * @param[in] DestAddrPtr: it points to the destination buffer start address
 * @param[in] Length: the length of data in byte
 *
 * @return    Flash_Drv_ReturnType
 * @retval    FLASH_DRV_SUCCESS
 * @retval    FLASH_DRV_ERR_INPUT_PARAM
 * @retval    FLASH_DRV_ERR_ECC_M
 *
 */
Flash_Drv_ReturnType Flash_Drv_Read(uint32 SrcAddr, uint8 const *DestAddrPtr, uint32 Length);

/**
 * @brief  Compare data in the flash memory with the expected value. 
 *
 * @param[in] SrcAddr: start address where to read in the flash memory.
 * @param[in] CompareBufPtr: it points to the start address where the expected values are stored
 * @param[in] Length: the length of data in byte
 *
 * @return    Flash_Drv_ReturnType
 * @retval    FLASH_DRV_SUCCESS - all the values are the same as the expected value
 * @retval    FLASH_DRV_ERR_INPUT_PARAM
 * @retval    FLASH_DRV_ERR_ECC_M
 *
 */
Flash_Drv_ReturnType Flash_Drv_Compare(uint32 SrcAddr, const uint8 *CompareBufPtr, uint32 Length);

/**
 * @brief  Check if the data value in the flash memory is the erased value. 
 *
 * @param[in] SrcAddr: start address where to check in the flash memory.
 * @param[in] Length: the length of data in byte
 *
 * @return    Flash_Drv_ReturnType
 * @retval    FLASH_DRV_SUCCESS - all the data checked are erased value
 * @retval    FLASH_DRV_ERR_INPUT_PARAM
 * @retval    FLASH_DRV_ERR_ECC_M
 *
 */
Flash_Drv_ReturnType Flash_Drv_CheckBlank(uint32 SrcAddr, uint32 Length);

/**
 * @brief      Poll the erase/program command complete status. If timeout supervisor is enabled, 
 *             it checks if it is timeout and command is not completed yet. It can be called when
 *             erase/program in asynchronous mode. If it is required, cache is cleared after erase
 *             /program is completed.
 *
 * @param[in]  None
 *
 * @return    Flash_Drv_ReturnType
 * @retval    FLASH_DRV_SUCCESS
 * @retval    FLASH_DRV_BUSY
 * @retval    FLASH_DRV_ERR
 * @retval    FLASH_DRV_ERR_TIMEOUT
 */
Flash_Drv_ReturnType Flash_Drv_PollEraseWriteStatus(void);

/**
 * @brief      Get flash block number from address
 *
 * @param[in]  Address: the address
 *
 * @return    the block number
 * @retval    FLASH_DRV_BLOCK_INVALID
 * @retval    FLASH_DRV_BLOCK_PFLASH
 * @retval    FLASH_DRV_BLOCK_DFLASH
 *
 */ 
uint32 Flash_Drv_GetBlockNumFromAddr(uint32 Address);

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Flash_Drv */

/** @} end of group Fls_Module */

#endif /* FLASH_DRV_H */
