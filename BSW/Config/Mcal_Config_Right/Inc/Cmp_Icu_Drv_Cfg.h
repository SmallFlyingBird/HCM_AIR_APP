/**************************************************************************************************/
/**
 * @file      : Cmp_Icu_Drv_Cfg.h
 * @brief     : AUTOSAR Cmp Icu Drv pre-compile configure head file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef CMP_ICU_DRV_CFG_H
#define CMP_ICU_DRV_CFG_H

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

#include "Cmp_Icu_Drv_PBcfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
#define CMP_ICU_DRV_CFG_H_VENDOR_ID                   0x00B3U
#define CMP_ICU_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define CMP_ICU_DRV_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define CMP_ICU_DRV_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define CMP_ICU_DRV_CFG_H_SW_MAJOR_VERSION            1U
#define CMP_ICU_DRV_CFG_H_SW_MINOR_VERSION            2U
#define CMP_ICU_DRV_CFG_H_SW_PATCH_VERSION            2U


#if (CMP_ICU_DRV_CFG_H_VENDOR_ID != CMP_ICU_DRV_PBCFG_H_VENDOR_ID)
    #error "Vendor ID Cmp_Icu_Drv_Cfg.h and Cmp_Icu_Drv_PBcfg.h have different"
#endif

#if ((CMP_ICU_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION != CMP_ICU_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
        (CMP_ICU_DRV_CFG_H_AR_RELEASE_MINOR_VERSION != CMP_ICU_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Cmp_Icu_Drv_Cfg.h and Cmp_Icu_Drv_PBcfg.h are different"
#endif

#if ((CMP_ICU_DRV_CFG_H_AR_RELEASE_REVISION_VERSION != CMP_ICU_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION) || \
        (CMP_ICU_DRV_CFG_H_SW_PATCH_VERSION != CMP_ICU_DRV_PBCFG_H_SW_PATCH_VERSION))
    #error "AutoSar Version Numbers of Cmp_Icu_Drv_Cfg.h and Cmp_Icu_Drv_PBcfg.h are different"
#endif

#if ((CMP_ICU_DRV_CFG_H_SW_MAJOR_VERSION != CMP_ICU_DRV_PBCFG_H_SW_MAJOR_VERSION) || \
        (CMP_ICU_DRV_CFG_H_SW_MINOR_VERSION != CMP_ICU_DRV_PBCFG_H_SW_MINOR_VERSION))
    #error "Software Version Numbers of Cmp_Icu_Drv_Cfg.h and Cmp_Icu_Drv_PBcfg.h are different"
#endif

#define CMP_ICU_DRV_CONFIG_EXT \
    CMP_ICU_DRV_CONFIG_PB

#define CMP_ICU_DRV_INSTANCE_SUMCNT                 (1U)

#define CMP_ICU_DRV_DEINIT_API                      (STD_ON)

#define CMP_ICU_DRV_GET_INPUT_STATE_API               (STD_ON)

#define CMP_ICU_DRV_SET_MODE_API                     (STD_ON)

#define CMP_ICU_DRV_EDGE_DETECT_API                  (STD_ON)


/** @} end of group Public_MacroDefinition */

/** @defgroup Public_TypeDefinition 
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

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

#endif    /* CMP_ICU_DRV_CFG_H */

