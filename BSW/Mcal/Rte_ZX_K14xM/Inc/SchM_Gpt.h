/**************************************************************************************************/
/**
 * @file      : SchM_Gpt.h
 * @brief     : AUTOSAR RTE header file. It is a stub file. Integrators shall replace this file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef SCHM_GPT_H
#define SCHM_GPT_H

/**
 *   @addtogroup Rte_Module
 *   @{
 */

/** @addtogroup SchM_Gpt
 *  @brief Gpt schedule manager header file. This is a stub file.
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif
/** @defgroup Private_MacroDefinition
 *  @{
 */
/* Published information */
#define SCHM_GPT_H_AR_RELEASE_MAJOR_VERSION    4U
#define SCHM_GPT_H_AR_RELEASE_MINOR_VERSION    6U
#define SCHM_GPT_H_AR_RELEASE_REVISION_VERSION 0U
#define SCHM_GPT_H_SW_MAJOR_VERSION            1U
#define SCHM_GPT_H_SW_MINOR_VERSION            2U
#define SCHM_GPT_H_SW_PATCH_VERSION            1U

/** @} end of Private_MacroDefinition */

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
  
extern void SchM_Enter_Gpt_TimGetValue(void);
extern void SchM_Exit_Gpt_TimGetValue(void);

extern void SchM_Enter_Gpt_TimBaseReg(void);
extern void SchM_Exit_Gpt_TimBaseReg(void);

extern void SchM_Enter_Gpt_TimEnableOutputCompare(void);
extern void SchM_Exit_Gpt_TimEnableOutputCompare(void);

extern void SchM_Enter_Gpt_TimChannelConfigurationReg(void);
extern void SchM_Exit_Gpt_TimChannelConfigurationReg(void);

extern void SchM_Enter_Gpt_StimControlAndStatusReg(void);
extern void SchM_Exit_Gpt_StimControlAndStatusReg(void);

extern void SchM_Enter_Gpt_RtcEnableInt(void);
extern void SchM_Exit_Gpt_RtcEnableInt(void);

extern void SchM_Enter_Gpt_RtcClearIntStatus(void);
extern void SchM_Exit_Gpt_RtcClearIntStatus(void);

extern void SchM_Enter_Gpt_RtcEnableCounter(void);
extern void SchM_Exit_Gpt_RtcEnableCounter(void);

extern void SchM_Enter_Gpt_RtcSelectClockOut(void);
extern void SchM_Exit_Gpt_RtcSelectClockOut(void);

extern void SchM_Enter_Gpt_RtcSetCompDelayValue(void);
extern void SchM_Exit_Gpt_RtcSetCompDelayValue(void);

extern void SchM_Enter_Gpt_RtcSetCompensationValue(void);
extern void SchM_Exit_Gpt_RtcSetCompensationValue(void);

extern void SchM_Enter_Gpt_RtcSetCompDirection(void);
extern void SchM_Exit_Gpt_RtcSetCompDirection(void);

extern void SchM_Enter_Gpt_RtcConfigSecondIntMux(void);
extern void SchM_Exit_Gpt_RtcConfigSecondIntMux(void);

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group SchM_Gpt */

/** @} end of group Rte_Module */


#endif /* SCHM_GPT_H */
