/**************************************************************************************************/
/**
 * @file      : Mcu_Drvw_PBcfg.c
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

/** @addtogroup Mcu_Drvw_Configuration
 *  @brief Mcu driver wrapper configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Mcu_Drvw.h"
#include "Scc_Drv.h"
#include "Parcc_Drv.h"
#include "Pmu_Drv.h"
#include "Ram_Drv.h"
#include "Scm_Mcu_Drv.h"
#include "Srmc_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

#define MCU_DRVW_PBCFG_C_VENDOR_ID                   0x00B3U
#define MCU_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define MCU_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define MCU_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define MCU_DRVW_PBCFG_C_SW_MAJOR_VERSION            1U
#define MCU_DRVW_PBCFG_C_SW_MINOR_VERSION            2U
#define MCU_DRVW_PBCFG_C_SW_PATCH_VERSION            1U


/* Check if current file and Mcu_Drvw.h file are of the same vendor */
#if (MCU_DRVW_PBCFG_C_VENDOR_ID != MCU_DRVW_H_VENDOR_ID)
    #error "Vendor ID of Mcu_Drvw_PBcfg.c and Mcu_Drvw.h are different"
#endif

/* Check if current file and Mcu_Drvw.h file are of the same Autosar version */
#if ((MCU_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != MCU_DRVW_H_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION    != MCU_DRVW_H_AR_RELEASE_MINOR_VERSION) || \
     (MCU_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION != MCU_DRVW_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version of Mcu_Drvw_PBcfg.c and Mcu_Drvw.h are different"
#endif

/* Check if current file and Mcu_Drvw.h file are of the same Software version */
#if ((MCU_DRVW_PBCFG_C_SW_MAJOR_VERSION != MCU_DRVW_H_SW_MAJOR_VERSION) || \
     (MCU_DRVW_PBCFG_C_SW_MINOR_VERSION != MCU_DRVW_H_SW_MINOR_VERSION) || \
     (MCU_DRVW_PBCFG_C_SW_PATCH_VERSION != MCU_DRVW_H_SW_PATCH_VERSION) \
    )
  #error "Software Version of Mcu_Drvw_PBcfg.c and Mcu_Drvw.h are different"
#endif

/* Check if current file and Scc_Drv.h file are of the same vendor */
#if (MCU_DRVW_PBCFG_C_VENDOR_ID != SCC_DRV_H_VENDOR_ID)
    #error "Vendor ID of Mcu_Drvw_PBcfg.c and Scc_Drv.h are different"
#endif

/* Check if current file and Scc_Drv.h file are of the same Autosar version */
#if ((MCU_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != SCC_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION    != SCC_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (MCU_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION != SCC_DRV_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version of Mcu_Drvw_PBcfg.c and Scc_Drv.h are different"
#endif

/* Check if current file and Scc_Drv.h file are of the same Software version */
#if ((MCU_DRVW_PBCFG_C_SW_MAJOR_VERSION != SCC_DRV_H_SW_MAJOR_VERSION) || \
     (MCU_DRVW_PBCFG_C_SW_MINOR_VERSION != SCC_DRV_H_SW_MINOR_VERSION) || \
     (MCU_DRVW_PBCFG_C_SW_PATCH_VERSION != SCC_DRV_H_SW_PATCH_VERSION) \
    )
  #error "Software Version of Mcu_Drvw_PBcfg.c and Scc_Drv.h are different"
#endif

/* Check if current file and Parcc_Drv.h file are of the same vendor */
#if (MCU_DRVW_PBCFG_C_VENDOR_ID != PARCC_DRV_H_VENDOR_ID)
    #error "Vendor ID of Mcu_Drvw_PBcfg.c and Parcc_Drv.h are different"
#endif

/* Check if current file and Parcc_Drv.h file are of the same Autosar version */
#if ((MCU_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != PARCC_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION    != PARCC_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (MCU_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION != PARCC_DRV_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version of Mcu_Drvw_PBcfg.c and Parcc_Drv.h are different"
#endif

/* Check if current file and Parcc_Drv.h file are of the same Software version */
#if ((MCU_DRVW_PBCFG_C_SW_MAJOR_VERSION != PARCC_DRV_H_SW_MAJOR_VERSION) || \
     (MCU_DRVW_PBCFG_C_SW_MINOR_VERSION != PARCC_DRV_H_SW_MINOR_VERSION) || \
     (MCU_DRVW_PBCFG_C_SW_PATCH_VERSION != PARCC_DRV_H_SW_PATCH_VERSION) \
    )
  #error "Software Version of Mcu_Drvw_PBcfg.c and Parcc_Drv.h are different"
#endif

/* Check if current file and Pmu_Drv.h file are of the same vendor */
#if (MCU_DRVW_PBCFG_C_VENDOR_ID != PMU_DRV_H_VENDOR_ID)
    #error "Vendor ID of Mcu_Drvw_PBcfg.c and Pmu_Drv.h are different"
#endif

/* Check if current file and Pmu_Drv.h file are of the same Autosar version */
#if ((MCU_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != PMU_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION    != PMU_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (MCU_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION != PMU_DRV_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version of Mcu_Drvw_PBcfg.c and Pmu_Drv.h are different"
#endif

/* Check if current file and Pmu_Drv.h file are of the same Software version */
#if ((MCU_DRVW_PBCFG_C_SW_MAJOR_VERSION != PMU_DRV_H_SW_MAJOR_VERSION) || \
     (MCU_DRVW_PBCFG_C_SW_MINOR_VERSION != PMU_DRV_H_SW_MINOR_VERSION) || \
     (MCU_DRVW_PBCFG_C_SW_PATCH_VERSION != PMU_DRV_H_SW_PATCH_VERSION) \
    )
  #error "Software Version of Mcu_Drvw_PBcfg.c and Pmu_Drv.h are different"
#endif

/* Check if current file and Ram_Drv.h file are of the same vendor */
#if (MCU_DRVW_PBCFG_C_VENDOR_ID != RAM_DRV_H_VENDOR_ID)
    #error "Vendor ID of Mcu_Drvw_PBcfg.c and Ram_Drv.h are different"
#endif

/* Check if current file and Ram_Drv.h file are of the same Autosar version */
#if ((MCU_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != RAM_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION    != RAM_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (MCU_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION != RAM_DRV_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version of Mcu_Drvw_PBcfg.c and Ram_Drv.h are different"
#endif

/* Check if current file and Ram_Drv.h file are of the same Software version */
#if ((MCU_DRVW_PBCFG_C_SW_MAJOR_VERSION != RAM_DRV_H_SW_MAJOR_VERSION) || \
     (MCU_DRVW_PBCFG_C_SW_MINOR_VERSION != RAM_DRV_H_SW_MINOR_VERSION) || \
     (MCU_DRVW_PBCFG_C_SW_PATCH_VERSION != RAM_DRV_H_SW_PATCH_VERSION) \
    )
  #error "Software Version of Mcu_Drvw_PBcfg.c and Ram_Drv.h are different"
#endif

/* Check if current file and Scm_Mcu_Drv.h file are of the same vendor */
#if (MCU_DRVW_PBCFG_C_VENDOR_ID != SCM_MCU_DRV_H_VENDOR_ID)
    #error "Vendor ID of Mcu_Drvw_PBcfg.c and Scm_Mcu_Drv.h are different"
#endif

/* Check if current file and Scm_Mcu_Drv.h file are of the same Autosar version */
#if ((MCU_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != SCM_MCU_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION    != SCM_MCU_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (MCU_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION != SCM_MCU_DRV_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version of Mcu_Drvw_PBcfg.c and Scm_Mcu_Drv.h are different"
#endif

/* Check if current file and Scm_Mcu_Drv.h file are of the same Software version */
#if ((MCU_DRVW_PBCFG_C_SW_MAJOR_VERSION != SCM_MCU_DRV_H_SW_MAJOR_VERSION) || \
     (MCU_DRVW_PBCFG_C_SW_MINOR_VERSION != SCM_MCU_DRV_H_SW_MINOR_VERSION) || \
     (MCU_DRVW_PBCFG_C_SW_PATCH_VERSION != SCM_MCU_DRV_H_SW_PATCH_VERSION) \
    )
  #error "Software Version of Mcu_Drvw_PBcfg.c and Scm_Mcu_Drv.h are different"
#endif

/* Check if current file and Srmc_Drv.h file are of the same vendor */
#if (MCU_DRVW_PBCFG_C_VENDOR_ID != SRMC_DRV_H_VENDOR_ID)
    #error "Vendor ID of Mcu_Drvw_PBcfg.c and Srmc_Drv.h are different"
#endif

/* Check if current file and Srmc_Drv.h file are of the same Autosar version */
#if ((MCU_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != SRMC_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION    != SRMC_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (MCU_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION != SRMC_DRV_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version of Mcu_Drvw_PBcfg.c and Srmc_Drv.h are different"
#endif

/* Check if current file and Srmc_Drv.h file are of the same Software version */
#if ((MCU_DRVW_PBCFG_C_SW_MAJOR_VERSION != SRMC_DRV_H_SW_MAJOR_VERSION) || \
     (MCU_DRVW_PBCFG_C_SW_MINOR_VERSION != SRMC_DRV_H_SW_MINOR_VERSION) || \
     (MCU_DRVW_PBCFG_C_SW_PATCH_VERSION != SRMC_DRV_H_SW_PATCH_VERSION) \
    )
  #error "Software Version of Mcu_Drvw_PBcfg.c and Srmc_Drv.h are different"
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

/**
* @brief Clock configuration.
*
*/
const Mcu_Drvw_ClockConfigType Mcu_Drvw_ClockConfig[1U] =
{
    /* Start of Mcu_ClockConfig[0] */
    {
        /* SCC Clock settings. */
        &Scc_Drv_ClockConfig[0],

        /* SCM Clock settings*/
        &Scm_Mcu_Drv_ClockConfig[0],

        /* PARCC settings. */
        &Parcc_Drv_Config[0],
    } /* End of  Mcu_ClockConfig[0] */
};

/* Pointer to HW data generic configuration. */
const Mcu_Drvw_HwConfigType Mcu_Drvw_HwConfig = 
{
    /**< @brief Configuration for reset hardware, part of SRMC. */
    &Srmc_Drv_ResetConfig,
        
    /**< @brief Configuration for power mode, part of SRMC. */
    &Srmc_Drv_PowerModeConfig,
        
    /**< @brief Configuration for SIM (System Integration Module) hardware. */
    &Scm_Mcu_Drv_Config,

    /**< @brief Configuration for SMC hardware. */
    &Pmu_Drv_Config,
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

/** @} end of group MCU_DRVW_Configuration */

/** @} end of group Mcu_Module */
