/**************************************************************************************************/
/**
 * @file      : Platform_Cfg.c
 * @brief     : Platform configuration source file.
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

/** @addtogroup Platform
 *  @brief Platform configuration source file
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Platform.h"
#include "Interrupt_Drv.h"
#if (STD_ON == PLATFORM_TRIG_MUX_ENABLE)
#include "Tmu_Drv.h"
#endif /* (STD_ON == PLATFORM_TRIG_MUX_ENABLE) */

/** @defgroup Private_MacroDefinition
 *  @{
 */

#define PLATFORM_CFG_C_VENDOR_ID                   0x00B3U
#define PLATFORM_CFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define PLATFORM_CFG_C_AR_RELEASE_MINOR_VERSION    6U
#define PLATFORM_CFG_C_AR_RELEASE_REVISION_VERSION 0U
#define PLATFORM_CFG_C_SW_MAJOR_VERSION            1U
#define PLATFORM_CFG_C_SW_MINOR_VERSION            2U
#define PLATFORM_CFG_C_SW_PATCH_VERSION            2U

/* Check if current file and Platform.h are the same vendor */
#if (PLATFORM_CFG_C_VENDOR_ID != PLATFORM_VENDOR_ID)
    #error "Platform_Cfg.c and Platform.h have different vendor ids"
#endif
/* Check if current file and Platform.h are the same Autosar version */
#if ((PLATFORM_CFG_C_AR_RELEASE_MAJOR_VERSION    != PLATFORM_AR_RELEASE_MAJOR_VERSION) || \
    (PLATFORM_CFG_C_AR_RELEASE_MINOR_VERSION    != PLATFORM_AR_RELEASE_MINOR_VERSION) || \
    (PLATFORM_CFG_C_AR_RELEASE_REVISION_VERSION != PLATFORM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Cfg.c and Platform.h are different"
#endif
/* Check if current file and Platform.h are the same Software version */
#if ((PLATFORM_CFG_C_SW_MAJOR_VERSION != PLATFORM_SW_MAJOR_VERSION) || \
    (PLATFORM_CFG_C_SW_MINOR_VERSION != PLATFORM_SW_MINOR_VERSION) || \
    (PLATFORM_CFG_C_SW_PATCH_VERSION != PLATFORM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Cfg.c and Platform.h are different"
#endif


/* Check if current file and Interrupt_Drv.h are the same vendor */
#if (PLATFORM_CFG_C_VENDOR_ID !=INTERRUPT_DRV_H_VENDOR_ID)
    #error "Platform_Cfg.c and Interrupt_Drv.h have different vendor ids"
#endif
/* Check if current file and Interrupt_Drv.h are the same Autosar version */
#if ((PLATFORM_CFG_C_AR_RELEASE_MAJOR_VERSION    !=INTERRUPT_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
    (PLATFORM_CFG_C_AR_RELEASE_MINOR_VERSION    !=INTERRUPT_DRV_H_AR_RELEASE_MINOR_VERSION) || \
    (PLATFORM_CFG_C_AR_RELEASE_REVISION_VERSION !=INTERRUPT_DRV_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Cfg.c and Interrupt_Drv.h are different"
#endif
/* Check if current file and Interrupt_Drv.h are the same Software version */
#if ((PLATFORM_CFG_C_SW_MAJOR_VERSION !=INTERRUPT_DRV_H_SW_MAJOR_VERSION) || \
    (PLATFORM_CFG_C_SW_MINOR_VERSION !=INTERRUPT_DRV_H_SW_MINOR_VERSION) || \
    (PLATFORM_CFG_C_SW_PATCH_VERSION !=INTERRUPT_DRV_H_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Cfg.c and Interrupt_Drv.h are different"
#endif

#if (STD_ON == PLATFORM_TRIG_MUX_ENABLE)
/* Check if current file and Tmu_Drv.h are the same vendor */
#if (PLATFORM_CFG_C_VENDOR_ID != TMU_DRV_H_VENDOR_ID)
    #error "Vendor ID of Platform_Cfg.c and Tmu_Drv.h are different"
#endif
/* Check if current file and Tmu_Drv.h are the same Autosar version */
#if ((PLATFORM_CFG_C_AR_RELEASE_MAJOR_VERSION != TMU_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (PLATFORM_CFG_C_AR_RELEASE_MINOR_VERSION != TMU_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (PLATFORM_CFG_C_AR_RELEASE_REVISION_VERSION != TMU_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Platform_Cfg.c and Tmu_Drv.h are different"
#endif
/* Check if current file and Tmu_Drv.h are the same Software version */
#if ((PLATFORM_CFG_C_SW_MAJOR_VERSION != TMU_DRV_H_SW_MAJOR_VERSION) || \
     (PLATFORM_CFG_C_SW_MINOR_VERSION != TMU_DRV_H_SW_MINOR_VERSION) || \
     (PLATFORM_CFG_C_SW_PATCH_VERSION != TMU_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Platform_Cfg.c and Tmu_Drv.h are different"
#endif
#endif /* (STD_ON == PLATFORM_TRIG_MUX_ENABLE) */

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */
#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"


const Platform_ConfigType Platform_Configuration =
{
    &Interrupt_Drv_Config /* Interrupt controller configuration */
};

#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

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

/** @} end of group Platform */

/** @} end of group Platform_Module */
