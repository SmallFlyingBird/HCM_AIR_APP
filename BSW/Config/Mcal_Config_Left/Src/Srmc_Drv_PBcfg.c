/**************************************************************************************************/
/**
 * @file      : Srmc_Drv_PBcfg.c
 * @brief     : AUTOSAR Mcu - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup Mcu_Module
 *  @{
 */

/** @addtogroup Srmc_Drv_Configuration
 *  @brief SRMC driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Srmc_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

#define SRMC_DRV_PBCFG_C_VENDOR_ID                   0x00B3U
#define SRMC_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define SRMC_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define SRMC_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define SRMC_DRV_PBCFG_C_SW_MAJOR_VERSION            1U
#define SRMC_DRV_PBCFG_C_SW_MINOR_VERSION            2U
#define SRMC_DRV_PBCFG_C_SW_PATCH_VERSION            2U


/* Check if current file and Srmc_Drv.h file are of the same vendor */
#if (SRMC_DRV_PBCFG_C_VENDOR_ID != SRMC_DRV_H_VENDOR_ID)
    #error "Vendor ID of Srmc_Drv_PBcfg.c and Srmc_Drv.h are different"
#endif

/* Check if current file and Srmc_Drv.h file are of the same Autosar version */
#if ((SRMC_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != SRMC_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (SRMC_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    != SRMC_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (SRMC_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION != SRMC_DRV_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version of Srmc_Drv_PBcfg.c and Srmc_Drv.h are different"
#endif

/* Check if current file and Srmc_Drv.h file are of the same Software version */
#if ((SRMC_DRV_PBCFG_C_SW_MAJOR_VERSION != SRMC_DRV_H_SW_MAJOR_VERSION) || \
     (SRMC_DRV_PBCFG_C_SW_MINOR_VERSION != SRMC_DRV_H_SW_MINOR_VERSION) || \
     (SRMC_DRV_PBCFG_C_SW_PATCH_VERSION != SRMC_DRV_H_SW_PATCH_VERSION) \
    )
  #error "Software Version of Srmc_Drv_PBcfg.c and Srmc_Drv.h are different"
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

/* SRMC reset configuration*/
const Srmc_Drv_ResetConfigType Srmc_Drv_ResetConfig =
{
    /* SRMC reset Pin Filter in normal mode */
    SRMC_DRV_RESET_PIN_DISABLE_FILTER,

    /* SRMC reset Pin Filter in stop mode */
    SRMC_DRV_RESET_PIN_DISABLE_FILTER,

    /* SRMC reset Pin Filter Bus Clock Select */
    0U,

    /* Enable/disable Core Lockup Reset */
    0U,

    /* The maximum reset delay time from when the interrupt is asserted and the system reset occurs. */
    SRMC_DRV_DELAY_8_LPO_CYCLES,

    /* System Reset Interrupt Enable Register */
    (
        SRMC_DRV_INT_TYPE_LOCKUP_DIS |
        SRMC_DRV_INT_TYPE_PIN_DIS |
        SRMC_DRV_INT_TYPE_LOC_DIS |
        SRMC_DRV_INT_TYPE_SERU_COLD_DIS |
        SRMC_DRV_INT_TYPE_SERU_SYS_DIS |
        SRMC_DRV_INT_TYPE_SW_DIS |
        SRMC_DRV_INT_TYPE_SACKERR_DIS |
        SRMC_DRV_INT_TYPE_WDOG_DIS
    )
};

/* SRMC power mode configuration*/
const Srmc_Drv_PowerModeConfigType Srmc_Drv_PowerModeConfig = 
{
    /* Allow standby mode config, SRMC_PMPORT[ASTB] */
    0U,
    
    /* Stop mode acknowledge config SRMC_PMCTRL[DSMACKTMO]*/
    0U,
    
    /* Standby Wakeup control 1 SRMC_DSMWUPC1*/
    (
        SRMC_DRV_WUPSRC_PTD0_DIS |
        SRMC_DRV_WUPSRC_PTD1_DIS |
        SRMC_DRV_WUPSRC_PTA4_DIS |
        SRMC_DRV_WUPSRC_PTC4_DIS |
        SRMC_DRV_WUPSRC_PTC5_DIS |
        SRMC_DRV_WUPSRC_PTE0_DIS |
        SRMC_DRV_WUPSRC_PTE1_DIS |
        SRMC_DRV_WUPSRC_PTE11_DIS |
        SRMC_DRV_WUPSRC_PTE13_DIS |
        SRMC_DRV_WUPSRC_PTE15_DIS |
        SRMC_DRV_WUPSRC_PTE16_DIS |
        SRMC_DRV_WUPSRC_PTA8_DIS |
        SRMC_DRV_WUPSRC_PTA9_DIS |
        SRMC_DRV_WUPSRC_PTA25_DIS |
        SRMC_DRV_WUPSRC_PMU_DIS |
        SRMC_DRV_WUPSRC_PTD0_LOW |
        SRMC_DRV_WUPSRC_PTD1_LOW |
        SRMC_DRV_WUPSRC_PTA4_LOW |
        SRMC_DRV_WUPSRC_PTC4_LOW |
        SRMC_DRV_WUPSRC_PTC5_LOW |
        SRMC_DRV_WUPSRC_PTE0_LOW |
        SRMC_DRV_WUPSRC_PTE1_LOW |
        SRMC_DRV_WUPSRC_PTE11_LOW |
        SRMC_DRV_WUPSRC_PTE13_LOW |
        SRMC_DRV_WUPSRC_PTE15_LOW |
        SRMC_DRV_WUPSRC_PTE16_LOW |
        SRMC_DRV_WUPSRC_PTA8_LOW |
        SRMC_DRV_WUPSRC_PTA9_LOW |
        SRMC_DRV_WUPSRC_PTA25_LOW
    ),
    
    /* Standby Wakeup control 2 SRMC_DSMWUPC2*/
    SRMC_DRV_WUPSRC_RTC_DIS
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

/** @} end of group Srmc_Drv_Configuration */

/** @} end of group Mcu_Module */
