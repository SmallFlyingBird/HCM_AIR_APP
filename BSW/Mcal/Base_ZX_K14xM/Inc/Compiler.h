/**************************************************************************************************/
/**
 * @file      : Compiler.h
 * @brief     : AUTOSAR compiler abstraction. It provides macros for the encapsulation of
 *              definitions and declarations
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef COMPILER_H
#define COMPILER_H

/** @addtogroup  Base_Module
 *  @{
 */

/** @defgroup Compiler
 *  @brief AUTOSAR compiler abstraction. It provides macros for the encapsulation of definitions and
 *  declarations
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Compiler_Cfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* published information */
#define COMPILER_VENDOR_ID                   0x00B3U
#define COMPILER_AR_RELEASE_MAJOR_VERSION    4U
#define COMPILER_AR_RELEASE_MINOR_VERSION    6U
#define COMPILER_AR_RELEASE_REVISION_VERSION 0U
#define COMPILER_SW_MAJOR_VERSION            1U
#define COMPILER_SW_MINOR_VERSION            2U
#define COMPILER_SW_PATCH_VERSION            2U

#ifdef __ICCARM__
    /**
     * @brief Symbol required to be defined when IAR compiler is used.
     */
    #define _IAR_C_Z20K14XM_
#endif

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
    /**
     * @brief Symbol required to be defined when ARMCLANG compiler is used.
     */
    #define _ARMCLANG_C_Z20K14XM_
#endif

#ifdef __ghs__
    /**
     * @brief Symbol required to be defined when Green Hills compiler is used.
     */
    #define _GHS_C_Z20K14XM_
#endif

/**
 * @brief The memory class AUTOMATIC shall be provided as empty definition, used for the declaration
 *        of local pointers.
 */
#define AUTOMATIC

/**
 * @brief The memory class TYPEDEF shall be provided as empty definition. This memory class shall be
 *        used within type definitions, where no memory qualifier can be specified. This can be
 *        necessary for defining pointer types, with e.g. P2VAR, where the macros require two
 *        parameters. First parameter can be specified in the type definition (distance to the
 *        memory location referenced by the pointer), but the second one (memory allocation of the
 *        pointer itself) cannot be defined at this time. Hence, memory class TYPEDEF shall be
 *        applied.
 */
#define TYPEDEF

/**
 * @brief The compiler abstraction shall provide the NULL_PTR define with a void pointer to zero
 *        definition.
 */
#define NULL_PTR ((void *)0)

#ifdef _IAR_C_Z20K14XM_

/**
 * @brief the INLINE define for abstraction of the keyword inline.
 */
#define INLINE inline

/**
 * @brief the LOCAL_INLINE define for abstraction of the keyword inline in functions with
 *        "static" scope
 */
#define LOCAL_INLINE static inline

#elif defined _ARMCLANG_C_Z20K14XM_
/**
 * @brief the INLINE define for abstraction of the keyword inline.
 */
#define INLINE inline

/**
 * @brief the LOCAL_INLINE define for abstraction of the keyword inline in functions with
 *        "static" scope
 */
#define LOCAL_INLINE static inline

#elif defined(_GHS_C_Z20K14XM_)
/**
 * @brief the INLINE define for abstraction of the keyword inline.
 */
#define INLINE __inline

/**
 * @brief the LOCAL_INLINE define for abstraction of the keyword inline in functions with
 *        "static" scope
 */
#define LOCAL_INLINE static __inline

#else
    #error "Unsupported compiler."
#endif /* _IAR_C_Z20K14XM_ */

/**
 * @brief The compiler abstraction shall define the FUNC macro for the declaration and definition of
 *        functions, that ensures correct syntax of function declarations as required by a specific
 *        compiler.
 */
#define FUNC(rettype, memclass) rettype

/**
 * @brief The compiler abstraction shall define the FUNC_P2CONST macro for the declaration and
 *        definition of functions returning a pointer to a constant
 */
#define FUNC_P2CONST(rettype, ptrclass, memclass) const rettype *

/**
 * @brief The compiler abstraction shall define the FUNC_P2VAR macro for the declaration and
 *        definition of functions returning a pointer to a variable.
 */
#define FUNC_P2VAR(rettype, ptrclass, memclass) rettype *

/**
 * @brief The compiler abstraction shall define the P2VAR macro for the declaration and definition
 *        of pointers in RAM, pointing to variables.
 */
#define P2VAR(ptrtype, memclass, ptrclass) ptrtype *

/**
 * @brief The compiler abstraction shall define the P2CONST macro for the declaration and definition
 *        of pointers in RAM pointing to constants.
 */
#define P2CONST(ptrtype, memclass, ptrclass) const ptrtype *

/**
 * @brief The compiler abstraction shall define the CONSTP2VAR macro for the declaration and
 *        definition of constant pointers accessing variables.
 */
#define CONSTP2VAR(ptrtype, memclass, ptrclass) ptrtype *const

/**
 * @brief The compiler abstraction shall define the CONSTP2CONST macro for the declaration and
 *        definition of constant pointers accessing constants.
 */
#define CONSTP2CONST(ptrtype, memclass, ptrclass) const ptrtype *const

/**
 * @brief The compiler abstraction shall define the P2FUNC macro for the type definition of pointers
 *        to functions.
 */
#define P2FUNC(rettype, ptrclass, fctname) rettype(*fctname)

/**
 * @brief The compiler abstraction shall define the CONSTP2FUNC macro for the type definition of
 *        constant pointers to functions
 */
#define CONSTP2FUNC(rettype, ptrclass, fctname) rettype(*const fctname)

/**
 * @brief The compiler abstraction shall define the CONST macro for the declaration and definition
 *        of constants.
 */
#define CONST(consttype, memclass) const consttype

/**
 * @brief The compiler abstraction shall define the VAR macro for the declaration and definition of
 *        variables.
 */
#define VAR(vartype, memclass) vartype

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

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Compiler */
/** @} end of group Base_Module */

#endif /* COMPILER_H */
