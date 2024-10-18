/**************************************************************************************************/
/**
 * @file      : SchM_Wdg_179_Ewdt.c
 * @brief     : AUTOSAR RTE source file. It is a stub file. Integrators shall replace this file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/**
 * @file SchM_Wdg_179_Ewdt.c
 * @brief Ewdt schedule source file. This is a stub file.
 *
 */

/** @addtogroup  Rte_Module
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "McalLib.h"
#include "SchM_Wdg_179_Ewdt.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define SCHM_WDG_179_EWDT_C_VENDOR_ID                   0x00B3U
#define SCHM_WDG_179_EWDT_C_AR_RELEASE_MAJOR_VERSION    4U
#define SCHM_WDG_179_EWDT_C_AR_RELEASE_MINOR_VERSION    6U
#define SCHM_WDG_179_EWDT_C_AR_RELEASE_REVISION_VERSION 0U
#define SCHM_WDG_179_EWDT_C_SW_MAJOR_VERSION            1U
#define SCHM_WDG_179_EWDT_C_SW_MINOR_VERSION            2U
#define SCHM_WDG_179_EWDT_C_SW_PATCH_VERSION            1U

/* Check if current file and SchM_Wdg_179_Ewdt.h are the same vendor */
#if (SCHM_WDG_179_EWDT_C_VENDOR_ID != SCHM_WDG_179_EWDT_H_VENDOR_ID)
    #error "Vendor ID of SchM_Wdg_179_Ewdt.c and SchM_Wdg_179_Ewdt.h are different"
#endif
/* Check if current file and SchM_Wdg_179_Ewdt.h are the same AutoSar version */
#if ((SCHM_WDG_179_EWDT_C_AR_RELEASE_MAJOR_VERSION    != SCHM_WDG_179_EWDT_H_AR_RELEASE_MAJOR_VERSION) || \
     (SCHM_WDG_179_EWDT_C_AR_RELEASE_MINOR_VERSION    != SCHM_WDG_179_EWDT_H_AR_RELEASE_MINOR_VERSION) || \
     (SCHM_WDG_179_EWDT_C_AR_RELEASE_REVISION_VERSION != SCHM_WDG_179_EWDT_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of SchM_Wdg_179_Ewdt.c and SchM_Wdg_179_Ewdt.h are different"
#endif
/* Check if current file and SchM_Wdg_179_Ewdt.h are the same Software version */
#if ((SCHM_WDG_179_EWDT_C_SW_MAJOR_VERSION != SCHM_WDG_179_EWDT_H_SW_MAJOR_VERSION) || \
     (SCHM_WDG_179_EWDT_C_SW_MINOR_VERSION != SCHM_WDG_179_EWDT_H_SW_MINOR_VERSION) || \
     (SCHM_WDG_179_EWDT_C_SW_PATCH_VERSION != SCHM_WDG_179_EWDT_H_SW_PATCH_VERSION))
    #error "Software Version of SchM_Wdg_179_Ewdt.c and SchM_Wdg_179_Ewdt.h are different"
#endif
/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */
/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

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
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"

void SchM_Enter_Wdg_179_Ewdt_ProtectEwdtTimeoutValue(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Wdg_179_Ewdt_ProtectEwdtTimeoutValue(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Wdg_179_Ewdt_ProtectEwdtGptPeriod(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Wdg_179_Ewdt_ProtectEwdtGptPeriod(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Wdg_179_Ewdt_ProtectEwdtState(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Wdg_179_Ewdt_ProtectEwdtState(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Wdg_179_Ewdt_WriteRegData(void)
{
    SuspendAllInterrupts();
}
void SchM_Exit_Wdg_179_Ewdt_WriteRegData(void)
{
    ResumeAllInterrupts();
}

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Rte_Module */
