/**************************************************************************************************/
/**
 * @file      : Fls_Drvw_PBcfg.c
 * @brief     : Fls driver wrapper postbuild configuration source file.
 *              - Platform: Z20K14xM
 *              - Autosar Version : 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Fls_Module
 *	@{
 */

/** @addtogroup Fls_Drvw_Configuration
 *	@brief Flash driver wrapper level configuration file
 *	@{
 */
 
#ifdef __cplusplus
extern "C"{
#endif

#include "Fls_Drvw.h"
#include "Flash_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
/* Published information */
#define FLS_DRVW_PBCFG_C_VENDOR_ID                   0x00B3U
#define FLS_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define FLS_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define FLS_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define FLS_DRVW_PBCFG_C_SW_MAJOR_VERSION            1U
#define FLS_DRVW_PBCFG_C_SW_MINOR_VERSION            2U
#define FLS_DRVW_PBCFG_C_SW_PATCH_VERSION            1U

/* Check if current file and Fls_Drvw.h are the same vendor */
#if (FLS_DRVW_PBCFG_C_VENDOR_ID != FLS_DRVW_H_VENDOR_ID)
	#error "Vendor ID of Fls_DRVW_PBcfg.c and Fls_Drvw.h are different"
#endif
/* Check if current file and Fls_Drvw.h are the same Autosar version */
#if ((FLS_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION != FLS_DRVW_H_AR_RELEASE_MAJOR_VERSION) ||                     \
     (FLS_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION != FLS_DRVW_H_AR_RELEASE_MINOR_VERSION) ||                     \
     (FLS_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION != FLS_DRVW_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Fls_DRVW_PBcfg.c and Fls_Drvw.h are different"
#endif
/* Check if current file and Fls_Drvw.h are the same Software version */
#if ((FLS_DRVW_PBCFG_C_SW_MAJOR_VERSION != FLS_DRVW_H_SW_MAJOR_VERSION) ||                                     \
     (FLS_DRVW_PBCFG_C_SW_MINOR_VERSION != FLS_DRVW_H_SW_MINOR_VERSION) ||                                     \
     (FLS_DRVW_PBCFG_C_SW_PATCH_VERSION != FLS_DRVW_H_SW_PATCH_VERSION))
    #error "Software Version of Fls_DRVW_PBcfg.c and Fls_Drvw.h are different"
#endif

/* Check if current file and Flash_Drv.h are the same vendor */
#if (FLS_DRVW_PBCFG_C_VENDOR_ID != FLASH_DRV_H_VENDOR_ID)
	#error "Vendor ID of Fls_DRVW_PBcfg.c and Flash_Drv.h are different"
#endif
/* Check if current file and Flash_Drv.h are the same Autosar version */
#if ((FLS_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION != FLASH_DRV_H_AR_RELEASE_MAJOR_VERSION) ||                     \
     (FLS_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION != FLASH_DRV_H_AR_RELEASE_MINOR_VERSION) ||                     \
     (FLS_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION != FLASH_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Fls_DRVW_PBcfg.c and Flash_Drv.h are different"
#endif
/* Check if current file and Flash_Drv.h are the same Software version */
#if ((FLS_DRVW_PBCFG_C_SW_MAJOR_VERSION != FLASH_DRV_H_SW_MAJOR_VERSION) ||                                     \
     (FLS_DRVW_PBCFG_C_SW_MINOR_VERSION != FLASH_DRV_H_SW_MINOR_VERSION) ||                                     \
     (FLS_DRVW_PBCFG_C_SW_PATCH_VERSION != FLASH_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Fls_DRVW_PBcfg.c and Flash_Drv.h are different"
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

/* Declaration of Fls Access erase Code Pointer*/
extern void FLS_AC_ERASE_ADDR(void (*CallBack)(void));
/* Declaration of Fls Access write Code Pointer */
extern void FLS_AC_WRITE_ADDR(void (*CallBack)(void));

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Global_VariableDefinition
 *  @{
 */
#define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"
const Fls_Drvw_ConfigType Fls_DrvwConfig =
{
    .AcErasePtr = &FLS_AC_ERASE_ADDR,
    .AcWritePtr = &FLS_AC_WRITE_ADDR,
    .AcCallbackPtr = NULL_PTR,
    .DriverConfigSetPtr = &Flash_DrvConfig
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

/** @} end of group Fls_Drvw_Configuration */

/** @} end of group Fls_Module */


