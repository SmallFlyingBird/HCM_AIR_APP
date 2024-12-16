/**************************************************************************************************/
/**
 * @file      : Tmu_Drv_Cfg.c
 * @brief     : Tmu driver configuration source file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup  Platform_Module
 *  @{
 */

/** @addtogroup Tmu_Drv
 *  @brief Tmu driver configuration source file
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Tmu_Drv.h"
/** @defgroup Public_MacroDefinition
 *  @{
 */
#define TMU_DRV_CFG_C_VENDOR_ID                   0x00B3U
#define TMU_DRV_CFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define TMU_DRV_CFG_C_AR_RELEASE_MINOR_VERSION    6U
#define TMU_DRV_CFG_C_AR_RELEASE_REVISION_VERSION 0U
#define TMU_DRV_CFG_C_SW_MAJOR_VERSION            1U
#define TMU_DRV_CFG_C_SW_MINOR_VERSION            2U
#define TMU_DRV_CFG_C_SW_PATCH_VERSION            2U

/* Check if current file and Tmu_Drv.h are the same vendor */
#if (TMU_DRV_CFG_C_VENDOR_ID !=TMU_DRV_H_VENDOR_ID)
    #error "Vendor ID of Tmu_Drv_Cfg.c and Tmu_Drv.h are different"
#endif
/* Check if current file and Tmu_Drv.h are the same Autosar version */
#if ((TMU_DRV_CFG_C_AR_RELEASE_MAJOR_VERSION    !=TMU_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
    (TMU_DRV_CFG_C_AR_RELEASE_MINOR_VERSION    !=TMU_DRV_H_AR_RELEASE_MINOR_VERSION) || \
    (TMU_DRV_CFG_C_AR_RELEASE_REVISION_VERSION !=TMU_DRV_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version of Tmu_Drv_Cfg.c and Tmu_Drv.h are different"
#endif
/* Check if current file and Tmu_Drv.h are the same Software version */
#if ((TMU_DRV_CFG_C_SW_MAJOR_VERSION !=TMU_DRV_H_SW_MAJOR_VERSION) || \
    (TMU_DRV_CFG_C_SW_MINOR_VERSION !=TMU_DRV_H_SW_MINOR_VERSION) || \
    (TMU_DRV_CFG_C_SW_PATCH_VERSION !=TMU_DRV_H_SW_PATCH_VERSION) \
    )
    #error "Software Version of Tmu_Drv_Cfg.c and Tmu_Drv.h are different"
#endif

/** @} end of Private_MacroDefinition */

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
#ifdef __cplusplus
}
#endif

/** @} end of group Tmu_Drv */

/** @} end of group Platform_Module */
