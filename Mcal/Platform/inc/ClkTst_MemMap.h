/**
 * @file    ClkTst_MemMap.h
 * @version V2.3.0
 *
 * @brief   AUTOSAR MemMap module
 * @details ClkTst MemMap
 *
 * @addtogroup MEMMAP_MODULE
 * @{
 */
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : ClkTst
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/


#ifdef __cplusplus
extern "C" {
#endif

/* PRQA S 0841,0883 EOF */
/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
/*==================================================================================================
                                      HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define CLKTST_MEMMAP_VENDOR_ID                      (180)
#define CLKTST_MEMMAP_AR_RELEASE_MAJOR_VERSION       (4)
#define CLKTST_MEMMAP_AR_RELEASE_MINOR_VERSION       (4)
#define CLKTST_MEMMAP_AR_RELEASE_REVISION_VERSION    (0)
#define CLKTST_MEMMAP_SW_MAJOR_VERSION               (2)
#define CLKTST_MEMMAP_SW_MINOR_VERSION               (3)
#define CLKTST_MEMMAP_SW_PATCH_VERSION               (0)
/*==================================================================================================
                                                DEFINES AND MACROS
==================================================================================================*/
/**
* @brief Symbol used for checking correctness of the includes
*/
#define MEMMAP_ERROR

#ifdef USING_OS_AUTOSAROS
#include "Os_memmap.h"
#endif

#ifdef CLKTST_START_SEC_CONFIG_DATA_8
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_CONFIG_DATA_8
#define ENTERED_CLKTST_START_SEC_CONFIG_DATA_8
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_CONFIG_DATA_8
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR
#define CLKTST_CONST __attribute__((section(".mcal_const_cfg"), aligned(1)))
#endif

#ifdef CLKTST_STOP_SEC_CONFIG_DATA_8
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_CONFIG_DATA_8
#undef ENTERED_CLKTST_START_SEC_CONFIG_DATA_8
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_CONFIG_DATA_8
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_CONFIG_DATA_16
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_CONFIG_DATA_16
#define ENTERED_CLKTST_START_SEC_CONFIG_DATA_16
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_CONFIG_DATA_16
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR
#define CLKTST_CONST __attribute__((section(".mcal_const_cfg"), aligned(2)))
#endif

#ifdef CLKTST_STOP_SEC_CONFIG_DATA_16
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_CONFIG_DATA_16
#undef ENTERED_CLKTST_START_SEC_CONFIG_DATA_16
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_CONFIG_DATA_16
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_CONFIG_DATA_32
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_CONFIG_DATA_32
#define ENTERED_CLKTST_START_SEC_CONFIG_DATA_32
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_CONFIG_DATA_32
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR
#define CLKTST_CONST __attribute__((section(".mcal_const_cfg"), aligned(4)))
#endif

#ifdef CLKTST_STOP_SEC_CONFIG_DATA_32
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_CONFIG_DATA_32
#undef ENTERED_CLKTST_START_SEC_CONFIG_DATA_32
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_CONFIG_DATA_32
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_CONFIG_DATA_UNSPECIFIED
#define ENTERED_CLKTST_START_SEC_CONFIG_DATA_UNSPECIFIED
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR
#define CLKTST_CONST  __attribute__((section(".mcal_const_cfg")))
#endif

#ifdef CLKTST_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_CONFIG_DATA_UNSPECIFIED
#undef ENTERED_CLKTST_START_SEC_CONFIG_DATA_UNSPECIFIED
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
#define ENTERED_CLKTST_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_CONFIG_DATA_8_NO_CACHEABLE
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR
#define CLKTST_CONST __attribute__((section(".mcal_const_no_cacheable"), aligned(1)))
#endif

#ifdef CLKTST_STOP_SEC_CONFIG_DATA_8_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
#undef ENTERED_CLKTST_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_CONFIG_DATA_8_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
#define ENTERED_CLKTST_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_CONFIG_DATA_16_NO_CACHEABLE
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR
#define CLKTST_CONST __attribute__((section(".mcal_const_no_cacheable"), aligned(2)))
#endif

#ifdef CLKTST_STOP_SEC_CONFIG_DATA_16_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
#undef ENTERED_CLKTST_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_CONFIG_DATA_16_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
#define ENTERED_CLKTST_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_CONFIG_DATA_32_NO_CACHEABLE
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR
#define CLKTST_CONST __attribute__((section(".mcal_const_no_cacheable"), aligned(4)))
#endif

#ifdef CLKTST_STOP_SEC_CONFIG_DATA_32_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
#undef ENTERED_CLKTST_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_CONFIG_DATA_32_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
#define ENTERED_CLKTST_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR
#define CLKTST_CONST  __attribute__((section(".mcal_const_no_cacheable")))
#endif

#ifdef CLKTST_STOP_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
#undef ENTERED_CLKTST_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_CONST_BOOLEAN
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_CONST_BOOLEAN
#define ENTERED_CLKTST_START_SEC_CONST_BOOLEAN
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_CONST_BOOLEAN
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR
#define CLKTST_CONST  __attribute__((section(".mcal_const")))
#endif

#ifdef CLKTST_STOP_SEC_CONST_BOOLEAN
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_CONST_BOOLEAN
#undef ENTERED_CLKTST_START_SEC_CONST_BOOLEAN
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_CONST_BOOLEAN
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_CONST_8
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_CONST_8
#define ENTERED_CLKTST_START_SEC_CONST_8
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_CONST_8
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR
#define CLKTST_CONST __attribute__((section(".mcal_const"), aligned(1)))
#endif

#ifdef CLKTST_STOP_SEC_CONST_8
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_CONST_8
#undef ENTERED_CLKTST_START_SEC_CONST_8
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_CONST_8
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_CONST_16
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_CONST_16
#define ENTERED_CLKTST_START_SEC_CONST_16
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_CONST_16
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR
#define CLKTST_CONST __attribute__((section(".mcal_const"), aligned(2)))
#endif

#ifdef CLKTST_STOP_SEC_CONST_16
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_CONST_16
#undef ENTERED_CLKTST_START_SEC_CONST_16
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_CONST_16
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_CONST_32
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_CONST_32
#define ENTERED_CLKTST_START_SEC_CONST_32
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_CONST_32
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR
#define CLKTST_CONST __attribute__((section(".mcal_const"), aligned(4)))
#endif

#ifdef CLKTST_STOP_SEC_CONST_32
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_CONST_32
#undef ENTERED_CLKTST_START_SEC_CONST_32
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_CONST_32
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_CONST_UNSPECIFIED
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_CONST_UNSPECIFIED
#define ENTERED_CLKTST_START_SEC_CONST_UNSPECIFIED
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_CONST_UNSPECIFIED
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR
#define CLKTST_CONST  __attribute__((section(".mcal_const")))
#endif

#ifdef CLKTST_STOP_SEC_CONST_UNSPECIFIED
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_CONST_UNSPECIFIED
#undef ENTERED_CLKTST_START_SEC_CONST_UNSPECIFIED
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_CONST_UNSPECIFIED
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_CODE
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_CODE
#define ENTERED_CLKTST_START_SEC_CODE
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_CODE
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC __attribute__((section(".mcal_text")))
#define CLKTST_VAR
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_CODE
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_CODE
#undef ENTERED_CLKTST_START_SEC_CODE
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_CODE
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_RAMCODE
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_RAMCODE
#define ENTERED_CLKTST_START_SEC_RAMCODE
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_RAMCODE
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC __attribute__((section(".ramcode"), noinline))
#define CLKTST_VAR
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_RAMCODE
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_RAMCODE
#undef ENTERED_CLKTST_START_SEC_RAMCODE
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_RAMCODE
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_CODE_AC
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_CODE_AC
#define ENTERED_CLKTST_START_SEC_CODE_AC
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_CODE_AC
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC __attribute__((section(".acport_code_rom")))
#define CLKTST_VAR
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_CODE_AC
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_CODE_AC
#undef ENTERED_CLKTST_START_SEC_CODE_AC
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_CODE_AC
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_VAR_CLEARED_BOOLEAN
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_VAR_CLEARED_BOOLEAN
#define ENTERED_CLKTST_START_SEC_VAR_CLEARED_BOOLEAN
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_VAR_CLEARED_BOOLEAN
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR __attribute__((section(".mcal_bss")))
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_VAR_CLEARED_BOOLEAN
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_VAR_CLEARED_BOOLEAN
#undef ENTERED_CLKTST_START_SEC_VAR_CLEARED_BOOLEAN
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_VAR_CLEARED_BOOLEAN
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_VAR_CLEARED_8
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_VAR_CLEARED_8
#define ENTERED_CLKTST_START_SEC_VAR_CLEARED_8
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_VAR_CLEARED_8
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR __attribute__((section(".mcal_bss"), aligned(1)))
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_VAR_CLEARED_8
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_VAR_CLEARED_8
#undef ENTERED_CLKTST_START_SEC_VAR_CLEARED_8
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_VAR_CLEARED_8
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_VAR_CLEARED_16
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_VAR_CLEARED_16
#define ENTERED_CLKTST_START_SEC_VAR_CLEARED_16
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_VAR_CLEARED_16
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR __attribute__((section(".mcal_bss"), aligned(2)))
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_VAR_CLEARED_16
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_VAR_CLEARED_16
#undef ENTERED_CLKTST_START_SEC_VAR_CLEARED_16
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_VAR_CLEARED_16
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_VAR_CLEARED_32
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_VAR_CLEARED_32
#define ENTERED_CLKTST_START_SEC_VAR_CLEARED_32
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_VAR_CLEARED_32
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR __attribute__((section(".mcal_bss"), aligned(4)))
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_VAR_CLEARED_32
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_VAR_CLEARED_32
#undef ENTERED_CLKTST_START_SEC_VAR_CLEARED_32
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_VAR_CLEARED_32
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_VAR_CLEARED_UNSPECIFIED
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_VAR_CLEARED_UNSPECIFIED
#define ENTERED_CLKTST_START_SEC_VAR_CLEARED_UNSPECIFIED
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR __attribute__((section(".mcal_bss")))
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_VAR_CLEARED_UNSPECIFIED
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_VAR_CLEARED_UNSPECIFIED
#undef ENTERED_CLKTST_START_SEC_VAR_CLEARED_UNSPECIFIED
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_VAR_CLEARED_UNSPECIFIED
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_VAR_INIT_BOOLEAN
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_VAR_INIT_BOOLEAN
#define ENTERED_CLKTST_START_SEC_VAR_INIT_BOOLEAN
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_VAR_INIT_BOOLEAN
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR __attribute__((section(".mcal_data")))
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_VAR_INIT_BOOLEAN
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_VAR_INIT_BOOLEAN
#undef ENTERED_CLKTST_START_SEC_VAR_INIT_BOOLEAN
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_VAR_INIT_BOOLEAN
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_VAR_INIT_8
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_VAR_INIT_8
#define ENTERED_CLKTST_START_SEC_VAR_INIT_8
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_VAR_INIT_8
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR __attribute__((section(".mcal_data"), aligned(1)))
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_VAR_INIT_8
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_VAR_INIT_8
#undef ENTERED_CLKTST_START_SEC_VAR_INIT_8
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_VAR_INIT_8
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_VAR_INIT_16
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_VAR_INIT_16
#define ENTERED_CLKTST_START_SEC_VAR_INIT_16
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_VAR_INIT_16
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR __attribute__((section(".mcal_data"), aligned(2)))
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_VAR_INIT_16
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_VAR_INIT_16
#undef ENTERED_CLKTST_START_SEC_VAR_INIT_16
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_VAR_INIT_16
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_VAR_INIT_32
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_VAR_INIT_32
#define ENTERED_CLKTST_START_SEC_VAR_INIT_32
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_VAR_INIT_32
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR __attribute__((section(".mcal_data"), aligned(4)))
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_VAR_INIT_32
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_VAR_INIT_32
#undef ENTERED_CLKTST_START_SEC_VAR_INIT_32
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_VAR_INIT_32
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_VAR_INIT_UNSPECIFIED
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_VAR_INIT_UNSPECIFIED
#define ENTERED_CLKTST_START_SEC_VAR_INIT_UNSPECIFIED
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_VAR_INIT_UNSPECIFIED
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR __attribute__((section(".mcal_data")))
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_VAR_INIT_UNSPECIFIED
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_VAR_INIT_UNSPECIFIED
#undef ENTERED_CLKTST_START_SEC_VAR_INIT_UNSPECIFIED
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_VAR_INIT_UNSPECIFIED
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
#define ENTERED_CLKTST_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR __attribute__((section(".mcal_bss_no_cacheable")))
#define CLKTST_CONST

#endif

#ifdef CLKTST_STOP_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
#undef ENTERED_CLKTST_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#define ENTERED_CLKTST_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR __attribute__((section(".mcal_bss_no_cacheable"), aligned(1)))
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#undef ENTERED_CLKTST_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
#define ENTERED_CLKTST_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_VAR_CLEARED_16_NO_CACHEABLE
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR __attribute__((section(".mcal_bss_no_cacheable"), aligned(2)))
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_VAR_CLEARED_16_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
#undef ENTERED_CLKTST_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_VAR_CLEARED_16_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
#define ENTERED_CLKTST_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR __attribute__((section(".mcal_bss_no_cacheable"), aligned(4)))
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
#undef ENTERED_CLKTST_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#define ENTERED_CLKTST_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR __attribute__((section(".mcal_bss_no_cacheable")))
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#undef ENTERED_CLKTST_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
#define ENTERED_CLKTST_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR __attribute__((section(".mcal_data_no_cacheable")))
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
#undef ENTERED_CLKTST_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_VAR_INIT_8_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_VAR_INIT_8_NO_CACHEABLE
#define ENTERED_CLKTST_START_SEC_VAR_INIT_8_NO_CACHEABLE
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR __attribute__((section(".mcal_data_no_cacheable"), aligned(1)))
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_VAR_INIT_8_NO_CACHEABLE
#undef ENTERED_CLKTST_START_SEC_VAR_INIT_8_NO_CACHEABLE
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_VAR_INIT_16_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_VAR_INIT_16_NO_CACHEABLE
#define ENTERED_CLKTST_START_SEC_VAR_INIT_16_NO_CACHEABLE
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR __attribute__((section(".mcal_data_no_cacheable"), aligned(2)))
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_VAR_INIT_16_NO_CACHEABLE
#undef ENTERED_CLKTST_START_SEC_VAR_INIT_16_NO_CACHEABLE
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_VAR_INIT_32_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_VAR_INIT_32_NO_CACHEABLE
#define ENTERED_CLKTST_START_SEC_VAR_INIT_32_NO_CACHEABLE
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR __attribute__((section(".mcal_data_no_cacheable"), aligned(4)))
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_VAR_INIT_32_NO_CACHEABLE
#undef ENTERED_CLKTST_START_SEC_VAR_INIT_32_NO_CACHEABLE
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#define ENTERED_CLKTST_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR __attribute__((section(".mcal_data_no_cacheable")))
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#undef ENTERED_CLKTST_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif


#ifdef CLKTST_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
#define ENTERED_CLKTST_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR __attribute__((section(".mcal_shared_data")))
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
#undef ENTERED_CLKTST_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
#define ENTERED_CLKTST_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR __attribute__((section(".mcal_shared_bss")))
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
#undef ENTERED_CLKTST_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#define ENTERED_CLKTST_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR __attribute__((section(".mcal_por_bss")))
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#undef ENTERED_CLKTST_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_VAR_POWER_ON_CLEARED_8
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_VAR_POWER_ON_CLEARED_8
#define ENTERED_CLKTST_START_SEC_VAR_POWER_ON_CLEARED_8
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_VAR_POWER_ON_CLEARED_8
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR __attribute__((section(".mcal_por_bss"), aligned(1)))
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_VAR_POWER_ON_CLEARED_8
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_VAR_POWER_ON_CLEARED_8
#undef ENTERED_CLKTST_START_SEC_VAR_POWER_ON_CLEARED_8
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_VAR_POWER_ON_CLEARED_8
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_VAR_POWER_ON_CLEARED_16
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_VAR_POWER_ON_CLEARED_16
#define ENTERED_CLKTST_START_SEC_VAR_POWER_ON_CLEARED_16
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_VAR_POWER_ON_CLEARED_16
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR __attribute__((section(".mcal_por_bss"), aligned(2)))
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_VAR_POWER_ON_CLEARED_16
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_VAR_POWER_ON_CLEARED_16
#undef ENTERED_CLKTST_START_SEC_VAR_POWER_ON_CLEARED_16
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_VAR_POWER_ON_CLEARED_16
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_VAR_POWER_ON_CLEARED_32
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_VAR_POWER_ON_CLEARED_32
#define ENTERED_CLKTST_START_SEC_VAR_POWER_ON_CLEARED_32
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_VAR_POWER_ON_CLEARED_32
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR __attribute__((section(".mcal_por_bss"), aligned(4)))
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_VAR_POWER_ON_CLEARED_32
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_VAR_POWER_ON_CLEARED_32
#undef ENTERED_CLKTST_START_SEC_VAR_POWER_ON_CLEARED_32
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_VAR_POWER_ON_CLEARED_32
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
#define ENTERED_CLKTST_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR __attribute__((section(".mcal_por_bss")))
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
#undef ENTERED_CLKTST_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_VAR_POWER_ON_INIT_BOOLEAN
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_VAR_POWER_ON_INIT_BOOLEAN
#define ENTERED_CLKTST_START_SEC_VAR_POWER_ON_INIT_BOOLEAN
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR __attribute__((section(".mcal_por_data")))
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_VAR_POWER_ON_INIT_BOOLEAN
#undef ENTERED_CLKTST_START_SEC_VAR_POWER_ON_INIT_BOOLEAN
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_VAR_POWER_ON_INIT_8
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_VAR_POWER_ON_INIT_8
#define ENTERED_CLKTST_START_SEC_VAR_POWER_ON_INIT_8
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_VAR_POWER_ON_INIT_8
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR __attribute__((section(".mcal_por_data"), aligned(1)))
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_VAR_POWER_ON_INIT_8
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_VAR_POWER_ON_INIT_8
#undef ENTERED_CLKTST_START_SEC_VAR_POWER_ON_INIT_8
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_VAR_POWER_ON_INIT_8
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_VAR_POWER_ON_INIT_16
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_VAR_POWER_ON_INIT_16
#define ENTERED_CLKTST_START_SEC_VAR_POWER_ON_INIT_16
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_VAR_POWER_ON_INIT_16
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR __attribute__((section(".mcal_por_data"), aligned(2)))
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_VAR_POWER_ON_INIT_16
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_VAR_POWER_ON_INIT_16
#undef ENTERED_CLKTST_START_SEC_VAR_POWER_ON_INIT_16
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_VAR_POWER_ON_INIT_16
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_VAR_POWER_ON_INIT_32
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_VAR_POWER_ON_INIT_32
#define ENTERED_CLKTST_START_SEC_VAR_POWER_ON_INIT_32
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_VAR_POWER_ON_INIT_32
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR __attribute__((section(".mcal_por_data"), aligned(4)))
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_VAR_POWER_ON_INIT_32
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_VAR_POWER_ON_INIT_32
#undef ENTERED_CLKTST_START_SEC_VAR_POWER_ON_INIT_32
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_VAR_POWER_ON_INIT_32
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

#ifdef CLKTST_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
/**
* @file ClkTst_MemMap.h
*/
#undef CLKTST_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#define ENTERED_CLKTST_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#ifndef MEMMAP_MATCH_ERROR
#define MEMMAP_MATCH_ERROR
#else
#ifndef CLKTST_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#endif
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#define CLKTST_FUNC
#define CLKTST_VAR __attribute__((section(".mcal_por_data")))
#define CLKTST_CONST
#endif

#ifdef CLKTST_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
/**
* @file ClkTst_MemMap.h
*/
#ifdef ENTERED_CLKTST_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#undef ENTERED_CLKTST_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#else
#error "MemMap.h, no valid matching start-stop section defined."
#endif
#ifdef MEMMAP_MATCH_ERROR
#undef MEMMAP_MATCH_ERROR
#endif
#undef CLKTST_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
/**
* @file ClkTst_MemMap.h
*/
#undef MEMMAP_ERROR
#undef CLKTST_FUNC
#undef CLKTST_VAR
#undef CLKTST_CONST
#endif

/*==================================================================================================
 *                                        Report error
==================================================================================================*/
#ifdef CLKTST_MEMMAP_ERROR
#error "ClkTst_MemMap.h, no valid memory mapping symbol defined."
#endif

#ifdef __cplusplus
}
#endif

/** @} */

/* End of file ClkTst_MemMap.h */
