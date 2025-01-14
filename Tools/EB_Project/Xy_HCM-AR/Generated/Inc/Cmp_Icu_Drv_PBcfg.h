/**************************************************************************************************/
/**
 * @file      : Cmp_Icu_Drv_PBcfg.h
 * @brief     : AUTOSAR Cmp Icu post-build configure head file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef CMP_ICU_DRV_PBCFG_H
#define CMP_ICU_DRV_PBCFG_H

/** @addtogroup  Icu_Module
 *  @{
 */

/** @addtogroup  Icu_Drv
 *  @{
 */

#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */

#define CMP_ICU_DRV_PBCFG_H_VENDOR_ID                   0x00B3U
#define CMP_ICU_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define CMP_ICU_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION    6U
#define CMP_ICU_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION 0U
#define CMP_ICU_DRV_PBCFG_H_SW_MAJOR_VERSION            1U
#define CMP_ICU_DRV_PBCFG_H_SW_MINOR_VERSION            2U
#define CMP_ICU_DRV_PBCFG_H_SW_PATCH_VERSION            2U


/** @} end of group Public_MacroDefinition */

/** @defgroup Public_TypeDefinition 
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

#define CMP_ICU_DRV_CONFIG_PB \

#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"
/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif
    
/** @} end of group Cmp_Icu_Drv  */
/** @} end of group Icu_Module */

#endif /* CMP_ICU_DRV_PBCFG_H */

