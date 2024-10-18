/**************************************************************************************************/
/**
 * @file      : SchM_Gpt.c
 * @brief     : AUTOSAR RTE source file. It is a stub file. Integrators shall replace this file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup Rte_Module
 *  @{
 */

/** @addtogroup SchM_Gpt
 *  @brief Gpt schedule manager source file. This is a stub file.
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "McalLib.h"
#include "SchM_Gpt.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define SCHM_GPT_C_AR_RELEASE_MAJOR_VERSION    4U
#define SCHM_GPT_C_AR_RELEASE_MINOR_VERSION    6U
#define SCHM_GPT_C_AR_RELEASE_REVISION_VERSION 0U
#define SCHM_GPT_C_SW_MAJOR_VERSION            1U
#define SCHM_GPT_C_SW_MINOR_VERSION            2U
#define SCHM_GPT_C_SW_PATCH_VERSION            1U

#if ((SCHM_GPT_C_AR_RELEASE_MAJOR_VERSION != SCHM_GPT_H_AR_RELEASE_MAJOR_VERSION) ||           \
        (SCHM_GPT_C_AR_RELEASE_MINOR_VERSION != SCHM_GPT_H_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar version of SchM_Gpt.c and SchM_Gpt.h are different"
#endif

#if ((SCHM_GPT_C_SW_MAJOR_VERSION != SCHM_GPT_H_SW_MAJOR_VERSION) ||                           \
        (SCHM_GPT_C_SW_MINOR_VERSION != SCHM_GPT_H_SW_MINOR_VERSION))
    #error "Software version of SchM_Gpt.c and SchM_Gpt.h are different"
#endif

#if ((SCHM_GPT_C_AR_RELEASE_REVISION_VERSION != SCHM_GPT_H_AR_RELEASE_REVISION_VERSION) ||                           \
        (SCHM_GPT_C_SW_PATCH_VERSION != SCHM_GPT_H_SW_PATCH_VERSION))
    #error "Software version of SchM_Gpt.c and SchM_Gpt.h are different"
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

void SchM_Enter_Gpt_TimGetValue(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Gpt_TimGetValue(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Gpt_TimBaseReg(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Gpt_TimBaseReg(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Gpt_TimEnableOutputCompare(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Gpt_TimEnableOutputCompare(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Gpt_TimChannelConfigurationReg(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Gpt_TimChannelConfigurationReg(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Gpt_StimControlAndStatusReg(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Gpt_StimControlAndStatusReg(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Gpt_RtcEnableInt(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Gpt_RtcEnableInt(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Gpt_RtcClearIntStatus(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Gpt_RtcClearIntStatus(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Gpt_RtcEnableCounter(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Gpt_RtcEnableCounter(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Gpt_RtcSelectClockOut(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Gpt_RtcSelectClockOut(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Gpt_RtcSetCompDelayValue(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Gpt_RtcSetCompDelayValue(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Gpt_RtcSetCompensationValue(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Gpt_RtcSetCompensationValue(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Gpt_RtcSetCompDirection(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Gpt_RtcSetCompDirection(void)
{
    ResumeAllInterrupts();
}

void SchM_Enter_Gpt_RtcConfigSecondIntMux(void)
{
    SuspendAllInterrupts();
}

void SchM_Exit_Gpt_RtcConfigSecondIntMux(void)
{
    ResumeAllInterrupts();
}

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group SchM_Gpt */

/** @} end of group Rte_Module */
