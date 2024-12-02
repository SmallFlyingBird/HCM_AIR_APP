/**************************************************************************************************/
/**
 * @file      : Icu_Cfg.c
 * @brief     : AUTOSAR Icu pre-compile configure source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup  Icu_Module
 *  @{
 */

/** @addtogroup  Icu
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Icu.h"
#include "Icu_Drvw.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define ICU_CFG_C_VENDOR_ID                   0x00B3U
#define ICU_CFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define ICU_CFG_C_AR_RELEASE_MINOR_VERSION    6U
#define ICU_CFG_C_AR_RELEASE_REVISION_VERSION 0U
#define ICU_CFG_C_SW_MAJOR_VERSION            1U
#define ICU_CFG_C_SW_MINOR_VERSION            2U
#define ICU_CFG_C_SW_PATCH_VERSION            2U

#if (ICU_CFG_C_VENDOR_ID != ICU_VENDOR_ID)
    #error "Vendor ID Icu_Cfg.c and Icu.h have different"
#endif
    
#if ((ICU_CFG_C_AR_RELEASE_MAJOR_VERSION != ICU_AR_RELEASE_MAJOR_VERSION) || \
        (ICU_CFG_C_AR_RELEASE_MINOR_VERSION != ICU_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Icu_Cfg.c and Icu.h are different"
#endif
    
#if ((ICU_CFG_C_SW_MAJOR_VERSION != ICU_SW_MAJOR_VERSION) || \
        (ICU_CFG_C_SW_MINOR_VERSION != ICU_SW_MINOR_VERSION))
    #error "Software version of Icu_Cfg.c and Icu.h are different"
#endif

#if ((ICU_CFG_C_AR_RELEASE_REVISION_VERSION != ICU_AR_RELEASE_REVISION_VERSION) || \
        (ICU_CFG_C_SW_PATCH_VERSION != ICU_SW_PATCH_VERSION))
    #error "Software version of Icu_Cfg.c and Icu.h are different"
#endif

#if (ICU_CFG_C_VENDOR_ID != ICU_DRVW_H_VENDOR_ID)
    #error "Vendor ID Icu_Cfg.c and Icu_Drvw.h have different"
#endif
    
#if ((ICU_CFG_C_AR_RELEASE_MAJOR_VERSION != ICU_DRVW_H_AR_RELEASE_MAJOR_VERSION) || \
        (ICU_CFG_C_AR_RELEASE_MINOR_VERSION != ICU_DRVW_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Icu_Cfg.c and Icu_Drvw.h are different"
#endif

#if ((ICU_CFG_C_SW_MAJOR_VERSION != ICU_DRVW_H_SW_MAJOR_VERSION) || \
        (ICU_CFG_C_SW_MINOR_VERSION != ICU_DRVW_H_SW_MINOR_VERSION))
    #error "Software version of Icu_Cfg.c and Icu_Drvw.h are different"
#endif

#if ((ICU_CFG_C_AR_RELEASE_REVISION_VERSION != ICU_DRVW_H_AR_RELEASE_REVISION_VERSION) || \
        (ICU_CFG_C_SW_PATCH_VERSION != ICU_DRVW_H_SW_PATCH_VERSION))
    #error "Software version of Icu_Cfg.c and Icu_Drvw.h are different"
#endif

/** @} end of group Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */


/** @} end of group Private_FunctionDeclaration */

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

/** @} end of group Icu */
/** @} end of group Icu_Module */

