/**
*   @file    Complier.h
*   @version
*
*   @brief   AUTOSAR complier abstraction
*
*   @addtogroup GENERAL
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : V2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef COMPILER_H
#define COMPILER_H

/******************************************************************************
*                      Include Files                                          *
******************************************************************************/
#include "Compiler_Cfg.h"
#include "Platform_Types.h"

/******************************************************************************
*                      Macro definitions                                      *
******************************************************************************/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define COMPILER_VENDOR_ID                    (180)
#define COMPILER_MODULE_ID                    (0)
#define COMPILER_AR_RELEASE_MAJOR_VERSION     (4)
#define COMPILER_AR_RELEASE_MINOR_VERSION     (4)
#define COMPILER_AR_RELEASE_REVISION_VERSION  (0)
#define COMPILER_SW_MAJOR_VERSION             (2)
#define COMPILER_SW_MINOR_VERSION             (3)
#define COMPILER_SW_PATCH_VERSION             (0)

/**
 * @brief AUTOMATIC used for the declaration of local pointers
 */
#define AUTOMATIC

/**
 * @brief typedef abstraction
 * @details This memory class shall be used within type definitions, where no memory
 *          qualifier can be specified. This can be necessary for defining pointer types,
 *          with e.g. P2VAR, where the macros require two parameters. First parameter
 *          can be specified in the type definition (distance to the memory location
 *          referenced by the pointer), but the second one (memory allocation of the
 *          pointer itself) cannot be defined at this time. Hence, memory class TYPEDEF
 *          shall be applied.
 */
#define TYPEDEF

#ifndef NULL_PTR
/**
 * @brief NULL_PTR define
 */
#define NULL_PTR  ((void *)0)
#endif

/**
 * @brief inline assembly keyword abstraction
 * @details Used by modules ported from other platforms (e.g. Os.h:
 *          ASM_KEYWORD(" cpsid i")). Supported by GHS, ARMCC and GCC.
 */
#ifndef ASM_KEYWORD
#define ASM_KEYWORD __asm
#endif

/**
 * @brief inline abstraction
 */
#define INLINE inline
/**
 * @brief static inline abstraction
 */
#define LOCAL_INLINE static inline


/**
 * @brief FUNC macro
 * @details The compiler abstraction shall define the FUNC macro for the declaration and
 *          definition of functions, that ensures correct syntax of function declarations
 *          as required by a specific compiler. - used for API functions
 *          - rettype : return type of the function
 *          - memclass : classification of the function itself
 */
#define FUNC(type, memclass) type

/**
 * @brief FUNC_P2CONST macro
 * @details he compiler abstraction shall define the FUNC_P2CONST macro for the
 *          declaration and definition of functions returning a pointer to a
 *          constant. This shall ensure the correct syntax of function declarations
 *          as required by a specific compiler.
 *          - rettype      : return type of the function
 *          - ptrclass     : defines the classification of the pointer's distance
 *          - memclass     : classification of the function itself
 */
#define FUNC_P2CONST(rettype, ptrclass, memclass) const ptrclass rettype * memclass

/**
 * @brief FUNC_P2VAR macro
 * @details The compiler abstraction shall define the FUNC_P2VAR macro for the declaration
 *          and definition of functions returning a pointer to a variable. This shall ensure
 *          the correct syntax of function declarations as required by a specific compiler.
 *          - rettype      : return type of the function
 *          - ptrclass     : defines the classification of the pointer's distance
 *          - memclass     : classification of the function itself
 */
#define FUNC_P2VAR(rettype, ptrclass, memclass) ptrclass rettype * memclass

/**
 * @brief Pointer to variable data
 * @details
 *              - ptrtype      : type of the referenced data
 *              - memclass     : classification of the pointer's variable itself
 *              - ptrclass     : defines the classification of the pointer's distance
 */
#define P2VAR(ptrtype, memclass, ptrclass) ptrtype *

/**
 * @brief Pointer to constant data
 * @details
 *              - ptrtype      : type of the referenced data
 *              - memclass     : classification of the pointer's variable itself
 *              - ptrclass     : defines the classification of the pointer's distance
 */
#define P2CONST(ptrtype, memclass, ptrclass)  const ptrtype *

/**
 * @brief Const pointer to variable data
 * @details
 *             - ptrtype      : type of the referenced data
 *             - memclass     : classification of the pointer's variable itself
 *             - ptrclass     : defines the classification of the pointer's distance
 */
#define CONSTP2VAR(ptrtype, memclass, ptrclass) ptrtype * const

/**
 * @brief Const pointer to constant data
 * @details
 *            - ptrtype      : type of the referenced data
 *            - memclass     : classification of the pointer's variable itself
 *            - ptrclass     : defines the classification of the pointer's distance
 */
#define CONSTP2CONST(ptrtype, memclass, ptrclass) const ptrtype * const

/**
 * @brief Type definition of pointers to functions
 * @details
 *           - rettype      : return type of the function
 *           - ptrclass     : defines the classification of the pointer's distance
 *           - fctname      : function name respectivly name of the defined type
 */
#define P2FUNC(rettype, ptrclass, fctname) rettype (*fctname)

/**
 * @brief Type definition of const pointers to functions
 * @details
 *           - rettype      : return type of the function
 *           - ptrclass     : defines the classification of the pointer's distance
 *           - fctname      : function name respectivly name of the defined type
 */
#define CONSTP2FUNC(rettype, ptrclass, fctname)  rettype (*const fctname)

/**
 * @brief CONST macro
 * @details The compiler abstraction shall define the CONST macro for the declaration
 *          and definition of constants.
 *          - consttype    : type of the constant
 *          - memclass     : classification of the constant itself
 */
#define CONST(type, memclass) const type

/**
 * @brief VAR macro
 * @details The compiler abstraction shall define the VAR macro for the declaration
 *          and definition of variables.
 *          - type        type of the variable
 *          - memclass    classification of the variable
 */
#define VAR(type, memclass) type

#endif /* COMPILER_H */

/** @} */

