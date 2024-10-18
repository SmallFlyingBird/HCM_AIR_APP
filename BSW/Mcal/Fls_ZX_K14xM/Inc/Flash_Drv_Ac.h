/**************************************************************************************************/
/**
 * @file      : Flash_Drv_Ac.h  
 * @brief     : Internal flash access code header file
 *              - Platform: Z20K14xM
 *              - Autosar Version : 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef FLASH_DRV_AC_H
#define FLASH_DRV_AC_H

/** @addtogroup Fls_Module
 *  @{
 */

/** @addtogroup Flash_Drv_Ac
 *  @brief Internal Flash access code
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
#define FLASH_DRV_AC_H_VENDOR_ID                   0x00B3U
#define FLASH_DRV_AC_H_AR_RELEASE_MAJOR_VERSION    4U
#define FLASH_DRV_AC_H_AR_RELEASE_MINOR_VERSION    6U
#define FLASH_DRV_AC_H_AR_RELEASE_REVISION_VERSION 0U
#define FLASH_DRV_AC_H_SW_MAJOR_VERSION            1U
#define FLASH_DRV_AC_H_SW_MINOR_VERSION            2U
#define FLASH_DRV_AC_H_SW_PATCH_VERSION            1U

/* Check if current file and Flash_Drv_Types.h are the same vendor */
#if (FLASH_DRV_AC_H_VENDOR_ID != FLASH_DRV_TYPES_H_VENDOR_ID) 
    #error "Vendor ID of Flash_Drv.h and Flash_Drv_Types.h are different"
#endif
/* Check if current file and Flash_Drv_Types.h are the same Autosar version */
#if((FLASH_DRV_AC_H_AR_RELEASE_MAJOR_VERSION != FLASH_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) || \
	(FLASH_DRV_AC_H_AR_RELEASE_MINOR_VERSION != FLASH_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) || \
	(FLASH_DRV_AC_H_AR_RELEASE_REVISION_VERSION != FLASH_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Flash_Drv.h and Flash_Drv_Types.h are different"
#endif
/* Check if current file and Flash_Drv_Types.h are the same Software version */
#if((FLASH_DRV_AC_H_SW_MAJOR_VERSION != FLASH_DRV_TYPES_H_SW_MAJOR_VERSION) || \
	(FLASH_DRV_AC_H_SW_MINOR_VERSION != FLASH_DRV_TYPES_H_SW_MINOR_VERSION) || \
	(FLASH_DRV_AC_H_SW_PATCH_VERSION != FLASH_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Flash_Drv.h and Flash_Drv_Types.h are different"
#endif
/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define FLS_START_SEC_VAR_CLEARED_32
#include "Fls_MemMap.h"
	
#if (FLASH_DRV_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
extern uint32 Flash_Drv_ElapsedTicks;
extern uint32 Flash_Drv_TimeoutTicks;
#endif /* (FLASH_DRV_TIMEOUT_SUPERVISION_ENABLED == STD_ON) */
	
#define FLS_STOP_SEC_VAR_CLEARED_32
#include "Fls_MemMap.h"
/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define FLS_START_SEC_CODE_AC
#include "Fls_MemMap.h"

/**
 * @brief     Flash Access code 
 *
 * @param[in] CallBack: It points to the callback function that will be called while waiting for 
 *                      completing the command.  If no callback function is needed, please set
 *                      this parameter to NULL.                    
 *
 * @return none
 */
void Flash_Drv_AccessCode(void (*CallBack)(void));

#define FLS_STOP_SEC_CODE_AC
#include "Fls_MemMap.h"
/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Flash_Drv_Ac */

/** @} end of group Fls_Module */

#endif /* FLASH_DRV_AC_H */
