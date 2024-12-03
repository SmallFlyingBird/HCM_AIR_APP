/**************************************************************************************************/
/**
 * @file      : Os.h
 * @brief     : AUTOSAR Os header file. It is a stub file. Integrators shall replace this file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef OS_H
#define OS_H

/** @addtogroup  Os_Module
 *  @{
 */

/** @defgroup Os
 *  @brief Os
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Os_Cfg.h"
#include "Std_Types.h"
#include "Rte_Os_Type.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
#define ResumeAllInterrupts()  ASM_KEYWORD(" cpsie i")
#define SuspendAllInterrupts() ASM_KEYWORD(" cpsid i")

#define ISR(IsrName) void IsrName(void)

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */
typedef uint32    TickType;
typedef TickType *TickRefType;

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
StatusType GetCounterValue(CounterType CounterId, TickRefType Value);
StatusType GetElapsedValue(CounterType CounterId, TickRefType Value, TickRefType ElapsedValue);

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Os */

/** @} end of group Os_Module */

#endif /* OS_H */
