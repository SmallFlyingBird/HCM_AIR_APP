/**************************************************************************************************/
/**
 * @file      : Pmu_Drv_PBcfg.c
 * @brief     : AUTOSAR Mcu - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup Mcu_Module
 *  @{
 */

/** @addtogroup Pmu_Drv_Configuration
 *  @brief PMU driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Pmu_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

#define PMU_DRV_PBCFG_C_VENDOR_ID                   0x00B3U
#define PMU_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define PMU_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define PMU_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define PMU_DRV_PBCFG_C_SW_MAJOR_VERSION            1U
#define PMU_DRV_PBCFG_C_SW_MINOR_VERSION            2U
#define PMU_DRV_PBCFG_C_SW_PATCH_VERSION            1U


/* Check if current file and Pmu_Drv.h file are of the same vendor */
#if (PMU_DRV_PBCFG_C_VENDOR_ID != PMU_DRV_H_VENDOR_ID)
    #error "Vendor ID of Pmu_Drv_PBcfg.c and Pmu_Drv.h are different"
#endif

/* Check if current file and Pmu_Drv.h file are of the same Autosar version */
#if ((PMU_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != PMU_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (PMU_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    != PMU_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (PMU_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION != PMU_DRV_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version of Pmu_Drv_PBcfg.c and Pmu_Drv.h are different"
#endif

/* Check if current file and Pmu_Drv.h file are of the same Software version */
#if ((PMU_DRV_PBCFG_C_SW_MAJOR_VERSION != PMU_DRV_H_SW_MAJOR_VERSION) || \
     (PMU_DRV_PBCFG_C_SW_MINOR_VERSION != PMU_DRV_H_SW_MINOR_VERSION) || \
     (PMU_DRV_PBCFG_C_SW_PATCH_VERSION != PMU_DRV_H_SW_PATCH_VERSION) \
    )
  #error "Software Version of Pmu_Drv_PBcfg.c and Pmu_Drv.h are different"
#endif

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */


/** @defgroup Global_VariableDefinition
 *  @{
 */

#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

/* PMU configuration */
const Pmu_Drv_ConfigType Pmu_Drv_Config = 
{
    /* PMU LVD Under Low Power Enable */
    0U,

    /* PMU LVD Under Active Enable */
    1U,
    
    /* PMU LVD Reset Enable */
    1U,
    
    /* PMU LVW Enable */
    0U,
    
    /* PMU Reference 1V Enable */
    1U,
    
    /* PMU LVD Interrupt Enable */
    0U,

    /* PMU LVD Interrupt callback function */
    NULL_PTR,
    
    /* PMU LVW Interrupt Enable */
    0U,

    /* PMU LVW Interrupt callback function */
    NULL_PTR,
};

#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

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

/** @} end of group Pmu_Drv_Configuration */

/** @} end of group Mcu_Module */
