/**************************************************************************************************/
/**
 * @file      : Eiru_Drv_PBcfg.c  
 * @brief     : Eiru low level driver - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Eiru_Module
 *  @{
 */

/** @addtogroup Eiru_Drv_Configuration
 *  @brief Eiru low level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"
{
#endif

#include "Eiru_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define EIRU_DRV_PBCFG_C_VENDOR_ID                   0x00B3U
#define EIRU_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define EIRU_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define EIRU_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define EIRU_DRV_PBCFG_C_SW_MAJOR_VERSION            1U
#define EIRU_DRV_PBCFG_C_SW_MINOR_VERSION            1U
#define EIRU_DRV_PBCFG_C_SW_PATCH_VERSION            0U

/* Check if current file and Eiru_Drv.h are the same vendor */
#if (EIRU_DRV_PBCFG_C_VENDOR_ID != EIRU_DRV_H_VENDOR_ID)
    #error "Vendor ID of Eiru_Drv_PBcfg.c and Eiru_Drv.h are different"
#endif
/* Check if current file and Eiru_Drv.h are the same Autosar version */
#if ((EIRU_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION != EIRU_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (EIRU_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION != EIRU_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (EIRU_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION != EIRU_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Eiru_Drv_PBcfg.c and Eiru_Drv.h are different"
#endif
/* Check if current file and Eiru_Drv.h are the same software version */
#if ((EIRU_DRV_PBCFG_C_SW_MAJOR_VERSION != EIRU_DRV_H_SW_MAJOR_VERSION) || \
     (EIRU_DRV_PBCFG_C_SW_MINOR_VERSION != EIRU_DRV_H_SW_MINOR_VERSION) || \
     (EIRU_DRV_PBCFG_C_SW_PATCH_VERSION != EIRU_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Eiru_Drv_PBcfg.c and Eiru_Drv.h are different"
#endif

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

/** @} end of group Private_VariableDefinition */

#define MEH_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Meh_MemMap.h"
/** @defgroup Global_VariableDefinition
 *  @{
 */
/**
* @brief Eiru configuration.
*
*/
const Eiru_Drv_SramEccConfigType      Eiru_Drv_Config= {
    /*EIRU_DRV_SRAM_L*/
    TRUE,      /*!< EIRU ECC error injection enable */
    FALSE,        /*!< Disable single bit ECC when accesses SRAM */
    FALSE,         /*!< Enable/disable multi bit ECC when accesses SRAM */
    
    /*EIRU_DRV_SRAM_U*/
    TRUE,      /*!< EIRU ECC error injection enable */
    FALSE,        /*!< Disable single bit ECC when accesses SRAM */
    FALSE,         /*!< Enable/disable multi bit ECC when accesses SRAM */
};

/** @} end of group Global_VariableDefinition */
#define MEH_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Meh_MemMap.h"

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

/** @} end of group Eiru_Drv_Configuration */

/** @} end of group Eiru_Module */
