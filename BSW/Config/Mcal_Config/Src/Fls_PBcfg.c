/**************************************************************************************************/
/**
 * @file      : Fls_PBcfg.c
 * @brief     : Fls postbuild configuration source file.
 *              - Platform: Z20K14xM
 *              - Autosar Version : 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Fls_Module
 *  @{
 */

/** @addtogroup Fls_Configuration
 *  @brief Flash AutoSar level configuration file
 *  @{
 */
 
#ifdef __cplusplus
extern "C"{
#endif

#include "Fls.h"
#include "Fls_Drvw.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
/* Published information */
#define FLS_PBCFG_C_VENDOR_ID                   0x00B3U
#define FLS_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define FLS_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define FLS_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define FLS_PBCFG_C_SW_MAJOR_VERSION            1U
#define FLS_PBCFG_C_SW_MINOR_VERSION            2U
#define FLS_PBCFG_C_SW_PATCH_VERSION            2U

/* Check if current file and Fls.h are the same vendor */
#if (FLS_PBCFG_C_VENDOR_ID != FLS_VENDOR_ID)
	#error "Vendor ID of Fls_PBcfg.c and Fls.h are different"
#endif
/* Check if current file and Fls.h are the same Autosar version */
#if ((FLS_PBCFG_C_AR_RELEASE_MAJOR_VERSION != FLS_AR_RELEASE_MAJOR_VERSION) ||                     \
     (FLS_PBCFG_C_AR_RELEASE_MINOR_VERSION != FLS_AR_RELEASE_MINOR_VERSION) ||                     \
     (FLS_PBCFG_C_AR_RELEASE_REVISION_VERSION != FLS_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Fls_PBcfg.c and Fls.h are different"
#endif
/* Check if current file and Fls.h are the same Software version */
#if ((FLS_PBCFG_C_SW_MAJOR_VERSION != FLS_SW_MAJOR_VERSION) ||                                     \
     (FLS_PBCFG_C_SW_MINOR_VERSION != FLS_SW_MINOR_VERSION) ||                                     \
     (FLS_PBCFG_C_SW_PATCH_VERSION != FLS_SW_PATCH_VERSION))
    #error "Software Version of Fls_PBcfg.c and Fls.h are different"
#endif

/* Check if current file and Fls_Drvw.h are the same vendor */
#if (FLS_PBCFG_C_VENDOR_ID != FLS_DRVW_H_VENDOR_ID)
	#error "Vendor ID of Fls_PBcfg.c and Fls_Drvw.h are different"
#endif
/* Check if current file and Fls_Drvw.h are the same Autosar version */
#if ((FLS_PBCFG_C_AR_RELEASE_MAJOR_VERSION != FLS_DRVW_H_AR_RELEASE_MAJOR_VERSION) ||                     \
     (FLS_PBCFG_C_AR_RELEASE_MINOR_VERSION != FLS_DRVW_H_AR_RELEASE_MINOR_VERSION) ||                     \
     (FLS_PBCFG_C_AR_RELEASE_REVISION_VERSION != FLS_DRVW_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Fls_PBcfg.c and Fls_Drvw.h are different"
#endif
/* Check if current file and Fls_Drvw.h are the same Software version */
#if ((FLS_PBCFG_C_SW_MAJOR_VERSION != FLS_DRVW_H_SW_MAJOR_VERSION) ||                                     \
     (FLS_PBCFG_C_SW_MINOR_VERSION != FLS_DRVW_H_SW_MINOR_VERSION) ||                                     \
     (FLS_PBCFG_C_SW_PATCH_VERSION != FLS_DRVW_H_SW_PATCH_VERSION))
    #error "Software Version of Fls_PBcfg.c and Fls_Drvw.h are different"
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


#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
/** @} end of group Private_FunctionDeclaration */

/** @defgroup Global_VariableDefinition
 *  @{
 */
#define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"
static const Fls_SectorConfigType Fls_Sector0 =
{
    .SectorSize = 8192U,
    .PageSize = 16U,
    .EndAddr = 0x1fffU,
    .PhysicalStartAddr = 0x01000000U,
    .EraseAsyncFlag = 0,
    .WriteAsyncFlag = 0,
};
#define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"

#define FLS_START_SEC_CONFIG_DATA_PTR
#include "Fls_MemMap.h"
static const Fls_SectorConfigType *const Fls_SectorListPtr[1U] =
{
    &Fls_Sector0,
};
#define FLS_STOP_SEC_CONFIG_DATA_PTR
#include "Fls_MemMap.h"

#define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"
static const Fls_ConfigType Fls_Config =
{
    .JobEndNotificationPtr = NULL_PTR,
    .JobErrorNotificationPtr = NULL_PTR,
    .DefaultMode = MEMIF_MODE_SLOW,
    .MaxReadFastMode = 65536U,
    .MaxReadNormalMode = 1024U,
    .MaxWriteFastMode = 256U,
    .MaxWriteNormalMode = 16U,
    .SectorNum = 1U,
    .SectorList = Fls_SectorListPtr,
    .WrapperConfigSetPtr = &Fls_DrvwConfig   
};
#define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"

#define FLS_START_SEC_CONFIG_DATA_PTR
#include "Fls_MemMap.h"

const Fls_ConfigType * const Fls_PreDefinedConfigPtr =
{
	&Fls_Config
};
#define FLS_STOP_SEC_CONFIG_DATA_PTR
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

/** @} end of group Fls_Configuration */

/** @} end of group Fls_Module */

