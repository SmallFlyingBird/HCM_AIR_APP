/**************************************************************************************************/
/**
 * @file      : Os_Api.c
 * @brief     : AUTOSAR Os API source file. It is a stub file. Integrators shall replace this file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

#include "Os.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

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
StatusType GetCounterValue(CounterType CounterId, TickRefType Value)
{
    (void)CounterId;
    (void)Value;
    return (StatusType)E_OK;
}

StatusType GetElapsedValue(CounterType CounterId, TickRefType Value, TickRefType ElapsedValue)
{
    (void)CounterId;
    (void)Value;
    (void)ElapsedValue;
    return (StatusType)E_OK;
}



/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif
