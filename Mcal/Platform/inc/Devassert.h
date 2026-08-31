/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           :
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
*
*   YUNTU Confidential. This software is owned or controlled by YUNTU and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef DEVASSERT_H
#define DEVASSERT_H

#include "Platform_Types.h"
#include "Platform_Cfg.h"
#include "Mcal.h"

/*
    Drivers can use a mechanism to validate data coming from upper software layers (application code) by performing
    a number of checks on input parameters' range or other invariants that can be statically checked (not dependent on
    runtime conditions). A failed validation is indicative of a software bug in application code, therefore it is important
    to use this mechanism during development.
*/

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DEVASSERT_VENDOR_ID                    (180)
#define DEVASSERT_AR_RELEASE_MAJOR_VERSION     (4)
#define DEVASSERT_AR_RELEASE_MINOR_VERSION     (4)
#define DEVASSERT_AR_RELEASE_REVISION_VERSION  (0)
#define DEVASSERT_SW_MAJOR_VERSION             (2)
#define DEVASSERT_SW_MINOR_VERSION             (3)
#define DEVASSERT_SW_PATCH_VERSION             (0)

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef CCOV_ENABLE
#define DevAssert(Value)
#else

#if ((MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64) || \
     (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH32) || \
     (MCAL_PLATFORM_ARM == MCAL_ARM_RARCH))
// #define BREAKPOINT_INSTR        "HLT #0"
#define BREAKPOINT_INSTR        "BKPT #0"
#elif (MCAL_PLATFORM_ARM == MCAL_ARM_MARCH)
#define BREAKPOINT_INSTR        "BKPT #0"
#else
#error "Unsupported architecture!"
#endif

/* Implement default assert macro */
static inline void DevAssert(boolean Value)
{
    if (Value)  /*NOSONAR, Value is a Boolean data, but the boolean does not recognized by Sonar */
    {
        /* do nothing */
    }
    else
    {
        for (;;)
        {
#ifdef PLATFORM_COMP_TEST   /* for the Platform integration test only */
            break;
#else
            __ASM(BREAKPOINT_INSTR);
#endif
        }
    }
}
#endif

#endif /* DEVASSERT_H */

/*******************************************************************************
 * EOF
 ******************************************************************************/

