/**************************************************************************************************/
/**
 * @file      : Cmu_PBcfg.c
 * @brief     : AUTOSAR Cmu - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup  Cmu_Module
 *  @{
 */

/** @addtogroup Cmu_Configuration
 *  @brief Cmu high level driver configuration
 *  @{
 */
#ifdef __cplusplus
extern "C"{
#endif

#include "Cmu.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

#define CMU_PBCFG_C_VENDOR_ID                   0x00B3U
#define CMU_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define CMU_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define CMU_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define CMU_PBCFG_C_SW_MAJOR_VERSION            1U
#define CMU_PBCFG_C_SW_MINOR_VERSION            1U
#define CMU_PBCFG_C_SW_PATCH_VERSION            0U


/* Check if current file and Cmu.h file are of the same vendor */
#if (CMU_PBCFG_C_VENDOR_ID != CMU_VENDOR_ID)
    #error "Vender ID of Cmu_PBcfg.c and Cmu.h are different "
#endif

/* Check if current file and Cmu.h file are of the same Autosar version */
#if ((CMU_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != CMU_AR_RELEASE_MAJOR_VERSION) || \
     (CMU_PBCFG_C_AR_RELEASE_MINOR_VERSION    != CMU_AR_RELEASE_MINOR_VERSION) || \
     (CMU_PBCFG_C_AR_RELEASE_REVISION_VERSION != CMU_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Cmu_PBcfg.c and Cmu.h are different"
#endif

/* Check if current file and Cmu.h file are of the same Software version */
#if ((CMU_PBCFG_C_SW_MAJOR_VERSION != CMU_SW_MAJOR_VERSION) || \
     (CMU_PBCFG_C_SW_MINOR_VERSION != CMU_SW_MINOR_VERSION) || \
     (CMU_PBCFG_C_SW_PATCH_VERSION != CMU_SW_PATCH_VERSION))
    #error "Software Version of Cmu_PBcfg.c and Cmu.h are different"
#endif


/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

#define CMU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Cmu_MemMap.h"


/**
* @brief   System cmu configuration.
*
*/
static const Cmu_Drv_ConfigType Cmu_SysCmuConfig[] = 
{
    /* Start of 0 configuration */
    {
        /*!< Cmu ID */
        0U,
        /*!< Specifies the monitor window */
        30000,
        /*!< Specifies if frequency Below Low Threshold Interrupt is enabled/disabled. */
        1U,
        /*!< Below Low Threshold Interrupt callback function */
        CmuBusLowNotification,
        /*!< Specifies if frequency above high Threshold Interrupt is enabled/disabled. */
        1U,
        /*!< Above high Threshold Interrupt callback function */
        CmuBusHighNotification,
        /*!< Cmu Monitor ID */
        (Cmu_Drv_IdType)CMU_DRV_ID_0,
        /*!< Specifies if frequency Below Low Threshold Reset is enabled/disabled. */
        0U,
        /*!< Specifies if frequency above high Threshold Reset is enabled/disabled. */
        0U,
        /*!< Specifies the low threshold for interrupt */
        34090U,
        /*!< Specifies the high threshold for interrupt */
        41666U,
        /*!< Specifies the low threshold for reset */
        0U,
        /*!< Specifies the high threshold for reset */
        4294967295U,
        /*!< Specifies the cmu mode */
        CMU_DRV_MONITOR_MODE
        
    }, /* End of 0 configuration */
    /* Start of 1 configuration */
    {
        /*!< Cmu ID */
        1U,
        /*!< Specifies the monitor window */
        30000,
        /*!< Specifies if frequency Below Low Threshold Interrupt is enabled/disabled. */
        1U,
        /*!< Below Low Threshold Interrupt callback function */
        CmuFIRC64LowNotification,
        /*!< Specifies if frequency above high Threshold Interrupt is enabled/disabled. */
        1U,
        /*!< Above high Threshold Interrupt callback function */
        CmuFIRC64HighNotification,
        /*!< Cmu Monitor ID */
        (Cmu_Drv_IdType)CMU_DRV_ID_1,
        /*!< Specifies if frequency Below Low Threshold Reset is enabled/disabled. */
        0U,
        /*!< Specifies if frequency above high Threshold Reset is enabled/disabled. */
        0U,
        /*!< Specifies the low threshold for interrupt */
        72727U,
        /*!< Specifies the high threshold for interrupt */
        88889U,
        /*!< Specifies the low threshold for reset */
        0U,
        /*!< Specifies the high threshold for reset */
        4294967295U,
        /*!< Specifies the cmu mode */
        CMU_DRV_MONITOR_MODE
        
    }, /* End of 1 configuration */
    /* Start of 2 configuration */
    {
        /*!< Cmu ID */
        2U,
        /*!< Specifies the monitor window */
        30000,
        /*!< Specifies if frequency Below Low Threshold Interrupt is enabled/disabled. */
        1U,
        /*!< Below Low Threshold Interrupt callback function */
        CmuLPO32KLowNotification,
        /*!< Specifies if frequency above high Threshold Interrupt is enabled/disabled. */
        1U,
        /*!< Above high Threshold Interrupt callback function */
        CmuLPO32KHighNotification,
        /*!< Cmu Monitor ID */
        (Cmu_Drv_IdType)CMU_DRV_ID_2,
        /*!< Specifies if frequency Below Low Threshold Reset is enabled/disabled. */
        0U,
        /*!< Specifies if frequency above high Threshold Reset is enabled/disabled. */
        0U,
        /*!< Specifies the low threshold for interrupt */
        32U,
        /*!< Specifies the high threshold for interrupt */
        48U,
        /*!< Specifies the low threshold for reset */
        0U,
        /*!< Specifies the high threshold for reset */
        4294967295U,
        /*!< Specifies the cmu mode */
        CMU_DRV_MONITOR_MODE
        
    } /* End of 2 configuration */
};


/**
* @brief   Initialization data for the cmu driver.
* @details A pointer to such a structure is provided to the cmu initialization routines for configuration.
*
*/
const Cmu_ConfigType Cmu_Config =
{
    Cmu_SysCmuConfig,  /*!< Cmu config */
    3U   /* Number of configured cmu */
};


#define CMU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Cmu_MemMap.h"



#ifdef __cplusplus
}
#endif


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

/** @} end of group Cmu_Configuration */

/** @} end of group Cmu_Module */
