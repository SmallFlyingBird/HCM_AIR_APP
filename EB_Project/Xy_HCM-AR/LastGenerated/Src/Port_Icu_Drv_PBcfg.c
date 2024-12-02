/**************************************************************************************************/
/**
 * @file      : Port_Icu_Drv_PBcfg.c
 * @brief     : AUTOSAR Port Icu Drv post-build configure source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup  Icu_Module
 *  @{
 */

/** @addtogroup  Icu_Drv
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Port_Icu_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define PORT_ICU_DRV_PBCFG_C_VENDOR_ID                   0x00B3U
#define PORT_ICU_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define PORT_ICU_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define PORT_ICU_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define PORT_ICU_DRV_PBCFG_C_SW_MAJOR_VERSION            1U
#define PORT_ICU_DRV_PBCFG_C_SW_MINOR_VERSION            2U
#define PORT_ICU_DRV_PBCFG_C_SW_PATCH_VERSION            2U


#if (PORT_ICU_DRV_PBCFG_C_VENDOR_ID != PORT_ICU_DRV_H_VENDOR_ID)
    #error "Vendor ID Port_Icu_Drv_PBcfg.c and Port_Icu_Drv.h have different"
#endif

#if ((PORT_ICU_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION != PORT_ICU_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
        (PORT_ICU_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION != PORT_ICU_DRV_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of Port_Icu_Drv_PBcfg.c and Port_Icu_Drv.h are different"
#endif

#if ((PORT_ICU_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION != PORT_ICU_DRV_H_AR_RELEASE_REVISION_VERSION) || \
        (PORT_ICU_DRV_PBCFG_C_SW_PATCH_VERSION != PORT_ICU_DRV_H_SW_PATCH_VERSION))
    #error "AutoSar version of Port_Icu_Drv_PBcfg.c and Port_Icu_Drv.h are different"
#endif

#if ((PORT_ICU_DRV_PBCFG_C_SW_MAJOR_VERSION != PORT_ICU_DRV_H_SW_MAJOR_VERSION) || \
        (PORT_ICU_DRV_PBCFG_C_SW_MINOR_VERSION != PORT_ICU_DRV_H_SW_MINOR_VERSION))
    #error "Software version of Port_Icu_Drv_PBcfg.c and Port_Icu_Drv.h are different"
#endif


/** @} end of group Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */



/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

void Icu_EventNotification(uint16 Channel, boolean OvfFlag);

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

/** @defgroup Global_VariableDefinition
 *  @{
 */

#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"
/** 
 * @brief   Icu port channel related configuration array
 */
/** 
 * @brief   Icu port instance related configuration array
 */
#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

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

/** @} end of group Icu_Drv */
/** @} end of group Icu_Module */

