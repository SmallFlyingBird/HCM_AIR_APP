/**************************************************************************************************/
/**
 * @file      : Pmu_Drv_Types.h
 * @brief     : PMU low level driver type definition header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef PMU_DRV_TYPES_H
#define PMU_DRV_TYPES_H

/** @addtogroup Mcu_Module
 *  @{
 */

/** @addtogroup Pmu_Drv
 *  @brief PMU low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Pmu_Drv_Cfg.h"
#include "Std_Types.h"
#include "McalLib.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define PMU_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define PMU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define PMU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define PMU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define PMU_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define PMU_DRV_TYPES_H_SW_MINOR_VERSION            2U
#define PMU_DRV_TYPES_H_SW_PATCH_VERSION            1U

/* Check if current file and Pmu_Drv_Cfg.h file are of the same vendor */
#if (PMU_DRV_TYPES_H_VENDOR_ID != PMU_DRV_CFG_H_VENDOR_ID)
    #error "Vendor ID of Pmu_Drv_Types.h and Pmu_Drv_Cfg.h are different"
#endif

/* Check if current file and Pmu_Drv_Cfg.h file are of the same Autosar version */
#if ((PMU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != PMU_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) ||       \
     (PMU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != PMU_DRV_CFG_H_AR_RELEASE_MINOR_VERSION) ||       \
     (PMU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION != PMU_DRV_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Pmu_Drv_Types.h and Pmu_Drv_Cfg.h are different"
#endif

/* Check if current file and Pmu_Drv_Cfg.h file are of the same Software version */
#if ((PMU_DRV_TYPES_H_SW_MAJOR_VERSION != PMU_DRV_CFG_H_SW_MAJOR_VERSION) ||                       \
     (PMU_DRV_TYPES_H_SW_MINOR_VERSION != PMU_DRV_CFG_H_SW_MINOR_VERSION) ||                       \
     (PMU_DRV_TYPES_H_SW_PATCH_VERSION != PMU_DRV_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Pmu_Drv_Types.h and Pmu_Drv_Cfg.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Std_Types.h file are of the same Autosar version */
    #if ((PMU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) ||             \
         (PMU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Pmu_Drv_Types.h and Std_Types.h are different"
    #endif

    /* Check if current file and McalLib.h file are of the same Autosar version */
    #if ((PMU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) ||         \
         (PMU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Pmu_Drv_Types.h and McalLib.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 *  @brief Type of  PMU voltage of LVD and LVW.
 *
 */
typedef enum
{
    PMU_DRV_VDD_LVD_LP =
        0U, /*!< PMU VDD 5V LVD(detecting) detect enable/disable under low power mode */
    PMU_DRV_VDD_LVD_ACT =
        1U, /*!< PMU VDD 5V LVD(detecting) detect enable/disable under active mode */
    PMU_DRV_VDD_LVD_RE = 3U, /*!< PMU VDD 5V LVD(detecting) reset enable/disable */
    PMU_DRV_VDD_LVW = 4U,    /*!< PMU VDD 5V LVW(warning) detect control */
    PMU_DRV_REF_BUF_1V = 8U  /*!< PMU Reference 1V output enable with buf control */
} Pmu_Drv_CtrlType;

/**
 *  @brief Type of PMU interrupt.
 *
 */
typedef enum
{
    PMU_DRV_VDD_LVW_INT = 0U, /*!< PMU VDD 5V LVW INT */
    PMU_DRV_VDD_LVD_INT      /*!< PMU VDD 5V LVD INT */
} Pmu_Drv_IntType;

/**
 *  @brief Type definition of callback function of LVD/LVW.
 *
 */
typedef void (*Pmu_Drv_CallbackFunc)(void);

/**
 *  @brief Type of PMU configuration.
 *
 */
typedef struct
{
    boolean              PmuCtrlLVDLowPowerEnable;    /* PMU LVD Under Low Power Enable */
    boolean              PmuCtrlLVDActiveEnable;      /* PMU LVD Under Active Enable */
    boolean              PmuCtrlLVDResetEnable;       /* PMU LVD Reset Enable */
    boolean              PmuCtrlLVWEnable;            /* PMU LVW Under Low Power Enable */
    boolean              PmuCtrlRef1VEnable;          /* PMU Reference 1V Enable */
    boolean              PmuLVDInterruptEnable;       /* PMU LVD Interrupt Enable */
    Pmu_Drv_CallbackFunc PmuLVDInterruptCallbackFunc; /* PMU LVD Interrupt callback function */
    boolean              PmuLVWInterruptEnable;       /* PMU LVW Interrupt Enable */
    Pmu_Drv_CallbackFunc PmuLVWInterruptCallbackFunc; /* PMU LVW Interrupt callback function */
} Pmu_Drv_ConfigType;

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

/** @} end of group Pmu_Drv */

/** @} end of group Mcu_Module */

#endif /* PMU_DRV_TYPES_H */
