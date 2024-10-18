/**************************************************************************************************/
/**
 * @file      : SchM_Fls.h
 * @brief     : AUTOSAR RTE header file. It is a stub file. Integrators shall replace this file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef SCHM_FLS_H
#define SCHM_FLS_H

/** @addtogroup Rte_Module
 *  @{
 */

/** @addtogroup SchM_Fls
 *  @brief Fls schedule manager header file. This is a stub file.
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define SCHM_FLS_H_AR_RELEASE_MAJOR_VERSION    4U
#define SCHM_FLS_H_AR_RELEASE_MINOR_VERSION    6U
#define SCHM_FLS_H_AR_RELEASE_REVISION_VERSION 0U
#define SCHM_FLS_H_SW_MAJOR_VERSION            1U
#define SCHM_FLS_H_SW_MINOR_VERSION            2U
#define SCHM_FLS_H_SW_PATCH_VERSION            1U
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

void SchM_Enter_Fls_TransferStatus(void);
void SchM_Exit_Fls_TransferStatus(void);

void SchM_Enter_Fls_FCMD(void);
void SchM_Exit_Fls_FCMD(void);

void SchM_Enter_Fls_FCTRL(void);
void SchM_Exit_Fls_FCTRL(void);

void SchM_Enter_Fls_BEDStartAddr(void);
void SchM_Exit_Fls_BEDStartAddr(void);

void SchM_Enter_Fls_BEDEndAddr(void);
void SchM_Exit_Fls_BEDEndAddr(void);

void SchM_Enter_Fls_MBEState(void);
void SchM_Exit_Fls_MBEState(void);

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group SchM_Fls */

/** @} end of group Rte_Module */

#endif /* SCHM_FLS_H */

