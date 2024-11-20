/**************************************************************************************************/
/**
 * @file      : Flash_Drv_PBcfg.c
 * @brief     : Internal Flash driver postbuild configuration source file.
 *              - Platform: Z20K14xM
 *              - Autosar Version : 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Fls_Module
 *  @{
 */

/** @addtogroup Flash_Drv_Configuration
 *  @brief Flash driver level configuration file
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Flash_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
/* Published information */
#define FLASH_DRV_PBCFG_C_VENDOR_ID                   0x00B3U
#define FLASH_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define FLASH_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define FLASH_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define FLASH_DRV_PBCFG_C_SW_MAJOR_VERSION            1U
#define FLASH_DRV_PBCFG_C_SW_MINOR_VERSION            2U
#define FLASH_DRV_PBCFG_C_SW_PATCH_VERSION            2U

/* Check if current file and Flash_Drv.h are the same vendor */
#if (FLASH_DRV_PBCFG_C_VENDOR_ID != FLASH_DRV_H_VENDOR_ID)
    #error "Vendor ID of Flash_Drv_PBcfg.c and Flash_Drv.h are different"
#endif
/* Check if current file and Flash_Drv.h are the same Autosar version */
#if ((FLASH_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION != FLASH_DRV_H_AR_RELEASE_MAJOR_VERSION) ||       \
     (FLASH_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION != FLASH_DRV_H_AR_RELEASE_MINOR_VERSION) ||       \
     (FLASH_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION != FLASH_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Flash_Drv_PBcfg.c and Flash_Drv.h are different"
#endif
/* Check if current file and Flash_Drv.h are the same Software version */
#if ((FLASH_DRV_PBCFG_C_SW_MAJOR_VERSION != FLASH_DRV_H_SW_MAJOR_VERSION) ||                       \
     (FLASH_DRV_PBCFG_C_SW_MINOR_VERSION != FLASH_DRV_H_SW_MINOR_VERSION) ||                       \
     (FLASH_DRV_PBCFG_C_SW_PATCH_VERSION != FLASH_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Flash_Drv_PBcfg.c and Flash_Drv.h are different"
#endif
/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
	

extern void Fls_AccessFinishNotif(void);

extern void Fls_AccessStartNotif(void);
	
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Global_VariableDefinition
 *  @{
 */
#define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"

const Flash_Drv_ConfigType Flash_DrvConfig = 
{
	.StartNotifPtr = Fls_AccessStartNotif,	
	.FinishNotifPtr = Fls_AccessFinishNotif, 
	.IgnoreBusErrStartAddr = 0x0U,
	.IgnoreBusErrEndAddr = 0xfffffff0U
};

#define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"
/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Flash_Drv_Configuration */

/** @} end of group Fls_Module */

