/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2022)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Os_MemMap.h                                                 **
**                                                                            **
**  Created on  : 2018-08-12                                                  **
**  Author      : shun.li                                                     **
**  Vendor      :                                                             **
**  DESCRIPTION : Memory mapping abstraction declaration of OS                **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>    <AUTHOR>    <REVISION LOG>
 *  V0.1.0      2018-08-12   ss         Initial version.
 *  V0.2.0      2019-08-21   shun.li & zhiqiang.huang   Functional safety initial version.
 *  V1.0.0      2019-11-21   shun.li    Functional safety version.
 */
/*============================================================================*/
/*
 * <SIZE> -- BOOLEAN/8BIT/16BIT/32BIT/UNSPECIFIED
 */

/*
 * <MSN>_START_SEC_CODE
 * <MSN>_STOP_SEC_CODE
 * To be used for mapping code to applicaiton block,boot block,external flash etc.
 */

/*
 * <MSN>_START_SEC_CODE_FAST
 * <MSN>_STOP_SEC_CODE_FAST
 * To be used for mapping code to local block,boot block of ISR API.
 */

/*
 * <MSN>_START_SEC_VAR_NOINIT_<SIZE>
 * <MSN>_STOP_SEC_VAR_NOINIT_<SIZE>
 * To be used for all global or static variables that are never initialized.
 */

/*
 * <MSN>_START_SEC_VAR_POWER_ON_INIT_<SIZE>
 * <MSN>_STOP_SEC_VAR_POWER_ON_INIT_<SIZE>
 * To be used for all global or static variables that are initialized only after
 * power on reset.
 */

/*
 * <MSN>_START_SEC_VAR_<SIZE>
 * <MSN>_STOP_SEC_VAR_<SIZE>
 * To be used for all global or static variables that are initialized after every
 * reset(the normal case).
 */

/*
 * <MSN>_START_SEC_VAR_FAST_NOINIT_<SIZE>
 * <MSN>_STOP_SEC_VAR_FAST_NOINIT_<SIZE>
 * To be used for all global or static variables that have at least one of the following
 * properties:
 *      *accessed bitwise
 *      *frequently used
 *      *high number of accesses in source code
 *  Some platforms allow the use of bit instructions for variables located in this specific
 *  RAM area as well as shorter addressing instructions.This saves code and runtime.
 */

/*
 * <MSN>_START_SEC_VAR_FAST_POWER_ON_INIT_<SIZE>
 * <MSN>_STOP_SEC_VAR_FAST_POWER_ON_INIT_<SIZE>
 * To be used for all global or static variables that have at least one of the following
 * properties:
 *      *accessed bitwise
 *      *frequently used
 *      *high number of accesses in source code
 *  Some platforms allow the use of bit instructions for variables located in this
 *  specific RAM area as well as shorter addressing instructions.This saves code and runtime.
 */

/*
 * <MSN>_START_SEC_VAR_FAST_<SIZE>
 * <MSN>_STOP_SEC_VAR_FAST_<SIZE>
 * To be used for all global or static variables that have at least one of the following
 * properties:
 *      *accessed bitwise
 *      *frequently used
 *      *high number of accesses in source code
 *  Some platforms allow the use of bit instructions for variables located in this s
 *  pecific RAM area as well as shorter addressing instructions.This saves code and runtime.
 */

/*
 * <MSN>_START_SEC_CONST_<SIZE>
 * <MSN>_STOP_SEC_CONST_<SIZE>
 * To be used for all global or static constants.
 */

/*
 * <MSN>_START_SEC_CONST_FAST_<SIZE>
 * <MSN>_STOP_SEC_CONST_FAST_<SIZE>
 * To be used for all global or static constants in fast segment block.
 */

/*
 * <MSN>_START_CONST_PBCFG
 * <MSN>_STOP_CONST_PBCFG
 * Constants with attributes that show that they reside in one segment for module
 * configuration.
 */

/*
 * <MSN>_START_CONST_PBCFG_ROOT
 * <MSN>_STOP_CONST_PBCFG_ROOT
 * Constants with attributes that show that they reside in one segment for module
 * configuration for root structure.
 */

/* @req MEMMAP010 @req MEMMAP004 @req MEMMAP021 @req MEMMAP003 @req MEMMAP018 */
/*=======[M A C R O S]========================================================*/
#if defined(START_WITH_IF)

/*=======[C A N]==============================================================*/
#elif defined(OS_START_SEC_VAR_NOINIT_GLOBAL)
#undef OS_START_SEC_VAR_NOINIT_GLOBAL
#define START_SEC_VAR_NOINIT_GLOBAL
#elif defined(OS_STOP_SEC_VAR_NOINIT_GLOBAL)
#undef OS_STOP_SEC_VAR_NOINIT_GLOBAL
#define STOP_SEC_VAR_NOINIT_GLOBAL

#elif defined(OS_START_SEC_VAR_CLONE)
#undef OS_START_SEC_VAR_CLONE
#define START_SEC_VAR_CLONE
#elif defined(OS_STOP_SEC_VAR_CLONE)
#undef OS_STOP_SEC_VAR_CLONE
#define STOP_SEC_VAR_CLONE

#elif defined(OS_START_SEC_VAR_CLONE_32)
#undef OS_START_SEC_VAR_CLONE_32
#define START_SEC_VAR_CLONE_32
#elif defined(OS_STOP_SEC_VAR_CLONE_32)
#undef OS_STOP_SEC_VAR_CLONE_32
#define STOP_SEC_VAR_CLONE_32

#elif defined(OS_START_SEC_VAR_CLONE_512)
#undef OS_START_SEC_VAR_CLONE_512
#define START_SEC_VAR_CLONE_512
#elif defined(OS_STOP_SEC_VAR_CLONE_512)
#undef OS_STOP_SEC_VAR_CLONE_512
#define STOP_SEC_VAR_CLONE_512

#elif defined(OS_START_SEC_CODE)
#undef OS_START_SEC_CODE
#define START_SEC_CODE
#elif defined(OS_STOP_SEC_CODE)
#undef OS_STOP_SEC_CODE
#define STOP_SEC_CODE

#elif defined(OS_START_SEC_CODE_FAST)
#undef OS_START_SEC_CODE_FAST
#define START_SEC_CODE_FAST
#elif defined(OS_STOP_SEC_CODE_FAST)
#undef OS_STOP_SEC_CODE_FAST
#define STOP_SEC_CODE_FAST

#elif defined(OS_START_SEC_VAR_STACK)
#undef OS_START_SEC_VAR_STACK
#elif defined(OS_STOP_SEC_VAR_STACK)
#undef OS_STOP_SEC_VAR_STACK

#elif defined(OS_START_SEC_VAR_NOINIT_BOOLEAN)
#undef OS_START_SEC_VAR_NOINIT_BOOLEAN
#define START_SEC_VAR_NOINIT_BOOLEAN
#elif defined(OS_STOP_SEC_VAR_NOINIT_BOOLEAN)
#undef OS_STOP_SEC_VAR_NOINIT_BOOLEAN
#define STOP_SEC_VAR_NOINIT_BOOLEAN

#elif defined(OS_START_SEC_VAR_NOINIT_8BIT)
#undef OS_START_SEC_VAR_NOINIT_8BIT
#define START_SEC_VAR_NOINIT_8BIT
#elif defined(OS_STOP_SEC_VAR_NOINIT_8BIT)
#undef OS_STOP_SEC_VAR_NOINIT_8BIT
#define STOP_SEC_VAR_NOINIT_8BIT

#elif defined(OS_START_SEC_VAR_NOINIT_16BIT)
#undef OS_START_SEC_VAR_NOINIT_16BIT
#define START_SEC_VAR_NOINIT_16BIT
#elif defined(OS_STOP_SEC_VAR_NOINIT_16BIT)
#undef OS_STOP_SEC_VAR_NOINIT_16BIT
#define STOP_SEC_VAR_NOINIT_16BIT

#elif defined(OS_START_SEC_VAR_NOINIT_32BIT)
#undef OS_START_SEC_VAR_NOINIT_32BIT
#define START_SEC_VAR_NOINIT_32BIT
#elif defined(OS_STOP_SEC_VAR_NOINIT_32BIT)
#undef OS_STOP_SEC_VAR_NOINIT_32BIT
#define STOP_SEC_VAR_NOINIT_32BIT

#elif defined(OS_START_SEC_VAR_NOINIT_UNSPECIFIED)
#undef OS_START_SEC_VAR_NOINIT_UNSPECIFIED
#define START_SEC_VAR_NOINIT_UNSPECIFIED
#elif defined(OS_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
#undef OS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#define STOP_SEC_VAR_NOINIT_UNSPECIFIED

#elif defined(OS_START_SEC_VAR_POWER_ON_INIT_BOOLEAN)
#undef OS_START_SEC_VAR_POWER_ON_INIT_BOOLEAN
#define START_SEC_VAR_POWER_ON_INIT_BOOLEAN
#elif defined(OS_STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN)
#undef OS_STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN
#define STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN

#elif defined(OS_START_SEC_VAR_POWER_ON_INIT_8BIT)
#undef OS_START_SEC_VAR_POWER_ON_INIT_8BIT
#define START_SEC_VAR_POWER_ON_INIT_8BIT
#elif defined(OS_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
#undef OS_STOP_SEC_VAR_POWER_ON_INIT_8BIT
#define STOP_SEC_VAR_POWER_ON_INIT_8BIT

#elif defined(OS_START_SEC_VAR_POWER_ON_INIT_16BIT)
#undef OS_START_SEC_VAR_POWER_ON_INIT_16BIT
#define START_SEC_VAR_POWER_ON_INIT_16BIT
#elif defined(OS_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
#undef OS_STOP_SEC_VAR_POWER_ON_INIT_16BIT
#define STOP_SEC_VAR_POWER_ON_INIT_16BIT

#elif defined(OS_START_SEC_VAR_POWER_ON_INIT_32BIT)
#undef OS_START_SEC_VAR_POWER_ON_INIT_32BIT
#define START_SEC_VAR_POWER_ON_INIT_32BIT
#elif defined(OS_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
#undef OS_STOP_SEC_VAR_POWER_ON_INIT_32BIT
#define STOP_SEC_VAR_POWER_ON_INIT_32BIT

#elif defined(OS_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
#undef OS_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#define START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#elif defined(OS_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
#undef OS_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#define STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED

#elif defined(OS_START_SEC_VAR_BOOLEAN)
#undef OS_START_SEC_VAR_BOOLEAN
#define START_SEC_VAR_BOOLEAN
#elif defined(OS_STOP_SEC_VAR_BOOLEAN)
#undef OS_STOP_SEC_VAR_BOOLEAN
#define STOP_SEC_VAR_BOOLEAN

#elif defined(OS_START_SEC_VAR_8BIT)
#undef OS_START_SEC_VAR_8BIT
#define START_SEC_VAR_8BIT
#elif defined(OS_STOP_SEC_VAR_8BIT)
#undef OS_STOP_SEC_VAR_8BIT
#define STOP_SEC_VAR_8BIT

#elif defined(OS_START_SEC_VAR_16BIT)
#undef OS_START_SEC_VAR_16BIT
#define START_SEC_VAR_16BIT
#elif defined(OS_STOP_SEC_VAR_16BIT)
#undef OS_STOP_SEC_VAR_16BIT
#define STOP_SEC_VAR_16BIT

#elif defined(OS_START_SEC_VAR_32BIT)
#undef OS_START_SEC_VAR_32BIT
#define START_SEC_VAR_32BIT
#elif defined(OS_STOP_SEC_VAR_32BIT)
#undef OS_STOP_SEC_VAR_32BIT
#define STOP_SEC_VAR_32BIT

#elif defined(OS_START_SEC_VAR_UNSPECIFIED)
#undef OS_START_SEC_VAR_UNSPECIFIED
#define START_SEC_VAR_UNSPECIFIED
#elif defined(OS_STOP_SEC_VAR_UNSPECIFIED)
#undef OS_STOP_SEC_VAR_UNSPECIFIED
#define STOP_SEC_VAR_UNSPECIFIED

#elif defined(OS_START_SEC_VAR_FAST_NOINIT_BOOLEAN)
#undef OS_START_SEC_VAR_FAST_NOINIT_BOOLEAN
#define START_SEC_VAR_FAST_NOINIT_BOOLEAN
#elif defined(OS_STOP_SEC_VAR_FAST_NOINIT_BOOLEAN)
#undef OS_STOP_SEC_VAR_FAST_NOINIT_BOOLEAN
#define STOP_SEC_VAR_FAST_NOINIT_BOOLEAN

#elif defined(OS_START_SEC_VAR_FAST_NOINIT_8BIT)
#undef OS_START_SEC_VAR_FAST_NOINIT_8BIT
#define START_SEC_VAR_FAST_NOINIT_8BIT
#elif defined(OS_STOP_SEC_VAR_FAST_NOINIT_8BIT)
#undef OS_STOP_SEC_VAR_FAST_NOINIT_8BIT
#define STOP_SEC_VAR_FAST_NOINIT_8BIT

#elif defined(OS_START_SEC_VAR_FAST_NOINIT_16BIT)
#undef OS_START_SEC_VAR_FAST_NOINIT_16BIT
#define START_SEC_VAR_FAST_NOINIT_16BIT
#elif defined(OS_STOP_SEC_VAR_FAST_NOINIT_16BIT)
#undef OS_STOP_SEC_VAR_FAST_NOINIT_16BIT
#define STOP_SEC_VAR_FAST_NOINIT_16BIT

#elif defined(OS_START_SEC_VAR_FAST_NOINIT_32BIT)
#undef OS_START_SEC_VAR_FAST_NOINIT_32BIT
#define START_SEC_VAR_FAST_NOINIT_32BIT
#elif defined(OS_STOP_SEC_VAR_FAST_NOINIT_32BIT)
#undef OS_STOP_SEC_VAR_FAST_NOINIT_32BIT
#define STOP_SEC_VAR_FAST_NOINIT_32BIT

#elif defined(OS_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
#undef OS_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#elif defined(OS_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
#undef OS_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#define STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED

#elif defined(OS_START_SEC_VAR_FAST_POWER_ON_INIT_BOOLEAN)
#undef OS_START_SEC_VAR_FAST_POWER_ON_INIT_BOOLEAN
#define START_SEC_VAR_FAST_POWER_ON_INIT_BOOLEAN
#elif defined(OS_STOP_SEC_VAR_FAST_POWER_ON_INIT_BOOLEAN)
#undef OS_STOP_SEC_VAR_FAST_POWER_ON_INIT_BOOLEAN
#define STOP_SEC_VAR_FAST_POWER_ON_INIT_BOOLEAN

#elif defined(OS_START_SEC_VAR_FAST_POWER_ON_INIT_8BIT)
#undef OS_START_SEC_VAR_FAST_POWER_ON_INIT_8BIT
#define START_SEC_VAR_FAST_POWER_ON_INIT_8BIT
#elif defined(OS_STOP_SEC_VAR_FAST_POWER_ON_INIT_8BIT)
#undef OS_STOP_SEC_VAR_FAST_POWER_ON_INIT_8BIT
#define STOP_SEC_VAR_FAST_POWER_ON_INIT_8BIT

#elif defined(OS_START_SEC_VAR_FAST_POWER_ON_INIT_16BIT)
#undef OS_START_SEC_VAR_FAST_POWER_ON_INIT_16BIT
#define START_SEC_VAR_FAST_POWER_ON_INIT_16BIT
#elif defined(OS_STOP_SEC_VAR_FAST_POWER_ON_INIT_16BIT)
#undef OS_STOP_SEC_VAR_FAST_POWER_ON_INIT_16BIT
#define STOP_SEC_VAR_FAST_POWER_ON_INIT_16BIT

#elif defined(OS_START_SEC_VAR_FAST_POWER_ON_INIT_32BIT)
#undef OS_START_SEC_VAR_FAST_POWER_ON_INIT_32BIT
#define START_SEC_VAR_FAST_POWER_ON_INIT_32BIT
#elif defined(OS_STOP_SEC_VAR_FAST_POWER_ON_INIT_32BIT)
#undef OS_STOP_SEC_VAR_FAST_POWER_ON_INIT_32BIT
#define STOP_SEC_VAR_FAST_POWER_ON_INIT_32BIT

#elif defined(OS_START_SEC_VAR_FAST_POWER_ON_INIT_UNSPECIFIED)
#undef OS_START_SEC_VAR_FAST_POWER_ON_INIT_UNSPECIFIED
#define START_SEC_VAR_FAST_POWER_ON_INIT_UNSPECIFIED
#elif defined(OS_STOP_SEC_VAR_FAST_POWER_ON_INIT_UNSPECIFIED)
#undef OS_STOP_SEC_VAR_FAST_POWER_ON_INIT_UNSPECIFIED
#define STOP_SEC_VAR_FAST_POWER_ON_INIT_UNSPECIFIED

#elif defined(OS_START_SEC_VAR_FAST_BOOLEAN)
#undef OS_START_SEC_VAR_FAST_BOOLEAN
#define START_SEC_VAR_FAST_BOOLEAN
#elif defined(OS_STOP_SEC_VAR_FAST_BOOLEAN)
#undef OS_STOP_SEC_VAR_FAST_BOOLEAN
#define STOP_SEC_VAR_FAST_BOOLEAN

#elif defined(OS_START_SEC_VAR_FAST_8BIT)
#undef OS_START_SEC_VAR_FAST_8BIT
#define START_SEC_VAR_FAST_8BIT
#elif defined(OS_STOP_SEC_VAR_FAST_8BIT)
#undef OS_STOP_SEC_VAR_FAST_8BIT
#define STOP_SEC_VAR_FAST_8BIT

#elif defined(OS_START_SEC_VAR_FAST_16BIT)
#undef OS_START_SEC_VAR_FAST_16BIT
#define START_SEC_VAR_FAST_16BIT
#elif defined(OS_STOP_SEC_VAR_FAST_16BIT)
#undef OS_STOP_SEC_VAR_FAST_16BIT
#define STOP_SEC_VAR_FAST_16BIT

#elif defined(OS_START_SEC_VAR_FAST_32BIT)
#undef OS_START_SEC_VAR_FAST_32BIT
#define START_SEC_VAR_FAST_32BIT
#elif defined(OS_STOP_SEC_VAR_FAST_32BIT)
#undef OS_STOP_SEC_VAR_FAST_32BIT
#define STOP_SEC_VAR_FAST_32BIT

#elif defined(OS_START_SEC_VAR_FAST_UNSPECIFIED)
#undef OS_START_SEC_VAR_FAST_UNSPECIFIED
#define START_SEC_VAR_FAST_UNSPECIFIED
#elif defined(OS_STOP_SEC_VAR_FAST_UNSPECIFIED)
#undef OS_STOP_SEC_VAR_FAST_UNSPECIFIED
#define STOP_SEC_VAR_FAST_UNSPECIFIED

#elif defined(OS_START_SEC_CONST_BOOLEAN)
#undef OS_START_SEC_CONST_BOOLEAN
#define START_SEC_CONST_BOOLEAN
#elif defined(OS_STOP_SEC_CONST_BOOLEAN)
#undef OS_STOP_SEC_CONST_BOOLEAN
#define STOP_SEC_CONST_BOOLEAN

#elif defined(OS_START_SEC_CONST_8BIT)
#undef OS_START_SEC_CONST_8BIT
#define START_SEC_CONST_8BIT
#elif defined(OS_STOP_SEC_CONST_8BIT)
#undef OS_STOP_SEC_CONST_8BIT
#define STOP_SEC_CONST_8BIT

#elif defined(OS_START_SEC_CONST_16BIT)
#undef OS_START_SEC_CONST_16BIT
#define START_SEC_CONST_16BIT
#elif defined(OS_STOP_SEC_CONST_16BIT)
#undef OS_STOP_SEC_CONST_16BIT
#define STOP_SEC_CONST_16BIT

#elif defined(OS_START_SEC_CONST_32BIT)
#undef OS_START_SEC_CONST_32BIT
#define START_SEC_CONST_32BIT
#elif defined(OS_STOP_SEC_CONST_32BIT)
#undef OS_STOP_SEC_CONST_32BIT
#define STOP_SEC_CONST_32BIT

#elif defined(OS_START_SEC_CONST_UNSPECIFIED)
#undef OS_START_SEC_CONST_UNSPECIFIED
#define START_SEC_CONST_UNSPECIFIED

#elif defined(OS_STOP_SEC_CONST_UNSPECIFIED)
#undef OS_STOP_SEC_CONST_UNSPECIFIED
#define STOP_SEC_CONST_UNSPECIFIED

#elif defined(OS_START_SEC_CONST_FAST_BOOLEAN)
#undef OS_START_SEC_CONST_FAST_BOOLEAN
#define START_SEC_CONST_FAST_BOOLEAN
#elif defined(OS_STOP_SEC_CONST_FAST_BOOLEAN)
#undef OS_STOP_SEC_CONST_FAST_BOOLEAN
#define STOP_SEC_CONST_FAST_BOOLEAN

#elif defined(OS_START_SEC_CONST_FAST_8BIT)
#undef OS_START_SEC_CONST_FAST_8BIT
#define START_SEC_CONST_FAST_8BIT
#elif defined(OS_STOP_SEC_CONST_FAST_8BIT)
#undef OS_STOP_SEC_CONST_FAST_8BIT
#define STOP_SEC_CONST_FAST_8BIT

#elif defined(OS_START_SEC_CONST_FAST_16BIT)
#undef OS_START_SEC_CONST_FAST_16BIT
#define START_SEC_CONST_FAST_16BIT
#elif defined(OS_STOP_SEC_CONST_FAST_16BIT)
#undef OS_STOP_SEC_CONST_FAST_16BIT
#define STOP_SEC_CONST_FAST_16BIT

#elif defined(OS_START_SEC_CONST_FAST_32BIT)
#undef OS_START_SEC_CONST_FAST_32BIT
#define START_SEC_CONST_FAST_32BIT
#elif defined(OS_STOP_SEC_CONST_FAST_32BIT)
#undef OS_STOP_SEC_CONST_FAST_32BIT
#define STOP_SEC_CONST_FAST_32BIT

#elif defined(OS_START_SEC_CONST_FAST_UNSPECIFIED)
#undef OS_START_SEC_CONST_FAST_UNSPECIFIED
#define START_SEC_CONST_FAST_UNSPECIFIED
#elif defined(OS_STOP_SEC_CONST_FAST_UNSPECIFIED)
#undef OS_STOP_SEC_CONST_FAST_UNSPECIFIED
#define STOP_SEC_CONST_FAST_UNSPECIFIED

#elif defined(OS_START_CONST_PBCFG)
#undef OS_START_CONST_PBCFG
#define START_CONST_PBCFG
#elif defined(OS_STOP_CONST_PBCFG)
#undef OS_STOP_CONST_PBCFG
#define STOP_CONST_PBCFG

#elif defined(OS_START_CONST_PBCFG_ROOT)
#undef OS_START_CONST_PBCFG_ROOT
#define START_CONST_PBCFG_ROOT
#elif defined(OS_STOP_CONST_PBCFG_ROOT)
#undef OS_STOP_CONST_PBCFG_ROOT
#define STOP_CONST_PBCFG_ROOT

#elif defined(OS_START_SEC_VAR_STACK_CORE0)
#undef OS_START_SEC_VAR_STACK_CORE0
#define START_SEC_VAR_STACK_CORE0
#elif defined(OS_STOP_SEC_VAR_STACK_CORE0)
#undef OS_STOP_SEC_VAR_STACK_CORE0
#define STOP_SEC_VAR_STACK_CORE0

#elif defined(OS_START_SEC_VAR_STACK_CORE1)
#undef OS_START_SEC_VAR_STACK_CORE1
#define START_SEC_VAR_STACK_CORE1
#elif defined(OS_STOP_SEC_VAR_STACK_CORE1)
#undef OS_STOP_SEC_VAR_STACK_CORE1
#define STOP_SEC_VAR_STACK_CORE1

#elif defined(OS_START_SEC_VAR_STACK_CORE2)
#undef OS_START_SEC_VAR_STACK_CORE2
#define START_SEC_VAR_STACK_CORE2
#elif defined(OS_STOP_SEC_VAR_STACK_CORE2)
#undef OS_STOP_SEC_VAR_STACK_CORE2
#define STOP_SEC_VAR_STACK_CORE2

#elif defined(OS_START_SEC_VAR_STACK_CORE3)
#undef OS_START_SEC_VAR_STACK_CORE3
#define START_SEC_VAR_STACK_CORE3
#elif defined(OS_STOP_SEC_VAR_STACK_CORE3)
#undef OS_STOP_SEC_VAR_STACK_CORE3
#define STOP_SEC_VAR_STACK_CORE3

#elif defined(OS_START_SEC_VAR_STACK_CORE4)
#undef OS_START_SEC_VAR_STACK_CORE4
#define START_SEC_VAR_STACK_CORE4
#elif defined(OS_STOP_SEC_VAR_STACK_CORE4)
#undef OS_STOP_SEC_VAR_STACK_CORE4
#define STOP_SEC_VAR_STACK_CORE4

#elif defined(OS_START_SEC_VAR_STACK_CORE5)
#undef OS_START_SEC_VAR_STACK_CORE5
#define START_SEC_VAR_STACK_CORE5
#elif defined(OS_STOP_SEC_VAR_STACK_CORE5)
#undef OS_STOP_SEC_VAR_STACK_CORE5
#define STOP_SEC_VAR_STACK_CORE5

#elif defined(OS_START_SEC_VAR_CLEARED_LOCAL_16)
#undef OS_START_SEC_VAR_CLEARED_LOCAL_16
#define START_SEC_VAR_CLEARED_LOCAL_16
#elif defined(OS_STOP_SEC_VAR_CLEARED_LOCAL_16)
#undef OS_STOP_SEC_VAR_CLEARED_LOCAL_16
#define STOP_SEC_VAR_CLEARED_LOCAL_16

#endif /* START_WITH_IF */

#include "MemMap.h"

/*=======[E N D   O F   F I L E]==============================================*/
/* PRQA S 0883 */ /* Dir-4.10 */
