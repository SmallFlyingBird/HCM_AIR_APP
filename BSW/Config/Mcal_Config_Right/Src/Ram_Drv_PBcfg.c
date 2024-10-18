/**************************************************************************************************/
/**
 * @file      : Ram_Drv_PBcfg.c
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

/** @addtogroup Ram_Drv_Configuration
 *  @brief RAM driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Ram_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

#define RAM_DRV_PBCFG_C_VENDOR_ID                   0x00B3U
#define RAM_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define RAM_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define RAM_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define RAM_DRV_PBCFG_C_SW_MAJOR_VERSION            1U
#define RAM_DRV_PBCFG_C_SW_MINOR_VERSION            2U
#define RAM_DRV_PBCFG_C_SW_PATCH_VERSION            1U


/* Check if current file and Ram_Drv.h file are of the same vendor */
#if (RAM_DRV_PBCFG_C_VENDOR_ID != RAM_DRV_H_VENDOR_ID)
    #error "Vendor ID of Ram_Drv_PBcfg.c and Ram_Drv.h are different"
#endif

/* Check if current file and Ram_Drv.h file are of the same Autosar version */
#if ((RAM_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != RAM_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (RAM_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    != RAM_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (RAM_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION != RAM_DRV_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version of Ram_Drv_PBcfg.c and Ram_Drv.h are different"
#endif

/* Check if current file and Ram_Drv.h file are of the same Software version */
#if ((RAM_DRV_PBCFG_C_SW_MAJOR_VERSION != RAM_DRV_H_SW_MAJOR_VERSION) || \
     (RAM_DRV_PBCFG_C_SW_MINOR_VERSION != RAM_DRV_H_SW_MINOR_VERSION) || \
     (RAM_DRV_PBCFG_C_SW_PATCH_VERSION != RAM_DRV_H_SW_PATCH_VERSION) \
    )
  #error "Software Version of Ram_Drv_PBcfg.c and Ram_Drv.h are different"
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

/** @} end of group Ram_Drv_Configuration */

/** @} end of group Mcu_Module */
