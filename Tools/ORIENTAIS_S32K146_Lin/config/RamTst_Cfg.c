

/*  Copyright (C) 2021, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  file       <RamTst_Cfg.c>
 *  brief
 *
 *  <Compiler: GHS 202014  MCU:S32K14X>
 *
 *  author     <Xin.Liu>
 *  date       <2024-12-16>
 */
/*============================================================================*/

/*======================[R E V I S I O N   H I S T O R Y]=====================*/
/*  <VERSION>    <DATE>    <AUTHOR>   <REVISION LOG>
 *  V1.0.0     20210914     Xin.Liu   Initial version
 */
/*============================================================================*/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "RamTst_Cfg.h"
#include "RamTst_Types.h"
#include "RamTst.h"
#include "Os.h"
#include "Rte_RamTst.h"


#define RAMTST_START_SEC_CONST_UNSPECIFIED
#include "RamTst_MemMap.h"

#define RAMTST_CFG_C_SW_MAJOR_VERSION 1u /*Major Version*/
#define RAMTST_CFG_C_SW_MINOR_VERSION 0u /*Minor Version*/
#define RAMTST_CFG_C_SW_PATCH_VERSION 0u /*Patch Version*/
#define RAMTST_CFG_C_AR_MAJOR_VERSION 4u /*Autosar Major Version*/
#define RAMTST_CFG_C_AR_MINOR_VERSION 2u /*Autosar Minor Version*/
#define RAMTST_CFG_C_AR_PATCH_VERSION 2u /*Autosar Patch Version*/

/*=======================[V E R S I O N  C H E C K]====================================*/
#if (RAMTST_CFG_C_AR_MAJOR_VERSION != RAMTST_CFG_H_AR_MAJOR_VERSION)
#error "RamTst_Cfg.c : Mismatch in Specification Major Version"
#endif 
#if (RAMTST_CFG_C_AR_MINOR_VERSION != RAMTST_CFG_H_AR_MINOR_VERSION)
#error "RamTst_Cfg.c : Mismatch in Specification Minor Version"
#endif 
#if (RAMTST_CFG_C_AR_PATCH_VERSION != RAMTST_CFG_H_AR_PATCH_VERSION)
#error "RamTst_Cfg.c : Mismatch in Specification Patch Version"
#endif 
#if (RAMTST_CFG_C_SW_MAJOR_VERSION != RAMTST_CFG_H_SW_MAJOR_VERSION)
#error "RamTst_Cfg.c : Mismatch in Specification Major Version"
#endif 
#if (RAMTST_CFG_C_SW_MINOR_VERSION != RAMTST_CFG_H_SW_MINOR_VERSION)
#error "RamTst_Cfg.c : Mismatch in Specification Minor Version"
#endif 


static const RamTst_BlockParams RamTstBlockParams_Alg1[] = 
{
        {
            1,                              /* RamTstBlockId */
            0x1fff09ff,                     /* RamTstEndAddress */
            0x1fff0400,                     /* RamTstStartAddress */
            0,                              /* RamTstFillPattern */
            RAMTEST_NON_DESTRUCTIVE,        /* RamTst_Policy */
            BLOCK_TEST_USED_METHOD_FOREGROUND,
        },
        {
            2,                              /* RamTstBlockId */
            0x200043a7,                     /* RamTstEndAddress */
            0x20000000,                     /* RamTstStartAddress */
            0,                              /* RamTstFillPattern */
            RAMTEST_DESTRUCTIVE,        /* RamTst_Policy */
            BLOCK_TEST_USED_METHOD_FOREGROUND,
        },
        {
            3,                              /* RamTstBlockId */
            0x20006053,                     /* RamTstEndAddress */
            0x20006050,                     /* RamTstStartAddress */
            0,                              /* RamTstFillPattern */
            RAMTEST_NON_DESTRUCTIVE,        /* RamTst_Policy */
            BLOCK_TEST_USED_METHOD_FOREGROUND,
        },
        {
            4,                              /* RamTstBlockId */
            0x20006c7b,                     /* RamTstEndAddress */
            0x20006054,                     /* RamTstStartAddress */
            0,                              /* RamTstFillPattern */
            RAMTEST_DESTRUCTIVE,        /* RamTst_Policy */
            BLOCK_TEST_USED_METHOD_FOREGROUND,
        },
        {
            5,                              /* RamTstBlockId */
            0x20006cab,                     /* RamTstEndAddress */
            0x20006c7c,                     /* RamTstStartAddress */
            0,                              /* RamTstFillPattern */
            RAMTEST_NON_DESTRUCTIVE,        /* RamTst_Policy */
            BLOCK_TEST_USED_METHOD_FOREGROUND,
        },
        {
            6,                              /* RamTstBlockId */
            0x20009f23,                     /* RamTstEndAddress */
            0x20006cac,                     /* RamTstStartAddress */
            0,                              /* RamTstFillPattern */
            RAMTEST_DESTRUCTIVE,        /* RamTst_Policy */
            BLOCK_TEST_USED_METHOD_FOREGROUND,
        },
};

static const RamTst_AlgParams RamTstAlgParamsSet[] = 
{
    {
        RAMTST_MARCH_TEST,                  /* RamTstAlgorithm */
        1,                                  /* RamTst_AlgParamsIdType */
        4096,                               /* RamTstExtNumberOfTestedCells */
        4096,                               /* RamTstMaxNumberOfTestedCells */
        6,                                  /* RamTstNumberOfBlocks */
        20,                                 /* RamTstNumberOfTestedCells */
        &RamTstBlockParams_Alg1,            /* RamTst_BlockParams */
    },
};

const RamTst_ConfigType RamTstConfigRoot[] = 
{
    {
        {
            1,                          /* RamTstDefaultAlgParamsId */
            4,                          /* RamTstMinNumberOfTestedCells */
            1,                          /* RamTstNumberOfAlgParamSets */
            &RamTstAlgParamsSet,        /* RamTstAlgParams */
        #if RAMTST_TEST_COMPLETE_NOTIFICATION_API_ENABLE
            TestCompletedNotification,                   /* RamTst_TestCompletedNotificationPtr */
        #endif
        #if RAMTST_TEST_ERROR_NOTIFICATION_API_ENABLE
            TestErrorNotification,                   /* RamTst_ErrorNotificationPtr */
        #endif
        },
        {
            FALSE,
            FALSE,
            FALSE,
            TRUE,                        /* RamTstMarchTestSelected */
            FALSE,
            FALSE,
        }
    },
};

#define RAMTST_STOP_SEC_CONST_UNSPECIFIED
#include "RamTst_MemMap.h"



