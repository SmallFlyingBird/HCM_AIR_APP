/**************************************************************************************************/
/**
 * @file      : SchM_Ewdt.h
 * @brief     : AUTOSAR RTE header file. It is a stub file. Integrators shall replace this file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef SCHM_WDG_179_EWDT_H
#define SCHM_WDG_179_EWDT_H

/**
*   @addtogroup Rte_Module
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif
/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define SCHM_WDG_179_EWDT_H_VENDOR_ID                   0x00B3U
#define SCHM_WDG_179_EWDT_H_AR_RELEASE_MAJOR_VERSION    4U
#define SCHM_WDG_179_EWDT_H_AR_RELEASE_MINOR_VERSION    6U
#define SCHM_WDG_179_EWDT_H_AR_RELEASE_REVISION_VERSION 0U
#define SCHM_WDG_179_EWDT_H_SW_MAJOR_VERSION            1U
#define SCHM_WDG_179_EWDT_H_SW_MINOR_VERSION            2U
#define SCHM_WDG_179_EWDT_H_SW_PATCH_VERSION            1U

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"

extern void SchM_Enter_Wdg_179_Ewdt_ProtectEwdtGptPeriod(void);
extern void SchM_Exit_Wdg_179_Ewdt_ProtectEwdtGptPeriod(void);

extern void SchM_Enter_Wdg_179_Ewdt_ProtectEwdtTimeoutValue(void);
extern void SchM_Exit_Wdg_179_Ewdt_ProtectEwdtTimeoutValue(void);

extern void SchM_Enter_Wdg_179_Ewdt_ProtectEwdtState(void);
extern void SchM_Exit_Wdg_179_Ewdt_ProtectEwdtState(void);

extern void SchM_Enter_Wdg_179_Ewdt_WriteRegData(void);
extern void SchM_Exit_Wdg_179_Ewdt_WriteRegData(void);

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SCHM_WDG_179_EWDT_H */
