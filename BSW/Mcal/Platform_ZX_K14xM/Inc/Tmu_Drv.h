/**************************************************************************************************/
/**
 * @file      : Tmu_Drv.h
 * @brief     : Interrupt Control low level driver header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef TMU_DRV_H
#define TMU_DRV_H

/** @addtogroup  Platform_Module
 *  @{
 */

/** @addtogroup Tmu_Drv
 *  @brief Interrupt Control low level driver header file.
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Tmu_Drv_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

#define TMU_DRV_H_VENDOR_ID                   0x00B3U
#define TMU_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define TMU_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define TMU_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define TMU_DRV_H_SW_MAJOR_VERSION            1U
#define TMU_DRV_H_SW_MINOR_VERSION            2U
#define TMU_DRV_H_SW_PATCH_VERSION            1U

/* Check if current file and Tmu_Drv_Types.h are the same vendor */
#if (TMU_DRV_H_VENDOR_ID != TMU_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Tmu_Drv.h and Tmu_Drv_Types.h are different"
#endif
/* Check if current file and Tmu_Drv_Types.h are the same Autosar version */
#if ((TMU_DRV_H_AR_RELEASE_MAJOR_VERSION != TMU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||           \
     (TMU_DRV_H_AR_RELEASE_MINOR_VERSION != TMU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||           \
     (TMU_DRV_H_AR_RELEASE_REVISION_VERSION != TMU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Tmu_Drv.h and Tmu_Drv_Types.h are different"
#endif
/* Check if current file and Tmu_Drv_Types.h are the same Software version */
#if ((TMU_DRV_H_SW_MAJOR_VERSION != TMU_DRV_TYPES_H_SW_MAJOR_VERSION) ||                           \
     (TMU_DRV_H_SW_MINOR_VERSION != TMU_DRV_TYPES_H_SW_MINOR_VERSION) ||                           \
     (TMU_DRV_H_SW_PATCH_VERSION != TMU_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Tmu_Drv.h and Tmu_Drv_Types.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#if (STD_ON == TMU_DRV_TRIG_MUX_ENABLE)
    #define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Platform_MemMap.h"

TMU_DRV_CONFIG_EXT

    #define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Platform_MemMap.h"
#endif /* (STD_ON == TMU_DRV_TRIG_MUX_ENABLE) */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

/**
 * @brief     This function initializes the configured TMU.
 *
 * @param[in] ConfigPtr: pointer to configuration structure for TMU.
 *
 * @return    None.
 */
void Tmu_Drv_Init(const Tmu_Drv_ConfigType *ConfigPtr);

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Tmu_Drv */

/** @} end of group Platform_Module */

#endif /* TMU_DRV_H */
