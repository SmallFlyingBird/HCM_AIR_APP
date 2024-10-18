
/*******************************************************************************
**                                                                            **
** Copyright(C)iSOFT (2022)                                                   **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document,and communication                  **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : RamTst_Cfg.c                                                **
**                                                                            **
**  Created on  : <2024-04-11>                      **
**  Author      : peng.wu                                                     **
**  Vendor      : iSOFT                                                       **
**  DESCRIPTION : Post-build configuration parameter of RamTst                **
**                                                                            **
**  SPECIFICATION(S):   AUTOSAR classic Platform R19-11                       **
**                                                                            **
*******************************************************************************/
/*===========================[V E R S I O N  I N F O R M A T I O N]===============================*/
#define RAMTST_CFG_C_SW_MAJOR_VERSION  (4U)
#define RAMTST_CFG_C_SW_MINOR_VERSION  (5U)
#define RAMTST_CFG_C_SW_PATCH_VERSION  (0U)
#define RAMTST_CFG_C_AR_MAJOR_VERSION  (2U)
#define RAMTST_CFG_C_AR_MINOR_VERSION  (0U)
#define RAMTST_CFG_C_AR_PATCH_VERSION  (0U)

/*===========================[I N C L U D E S]====================================================*/
#include "RamTst_Cfg.h"
#include "RamTst_Types.h"

/*===========================[V E R S I O N  C H E C K]===========================================*/
#if (RAMTST_CFG_C_AR_MAJOR_VERSION != RAMTST_CFG_H_AR_MAJOR_VERSION)
#error "RamTst_Cfg.c : Mismatch in Specification Major Version"
#endif /* RAMTST_CFG_C_AR_MAJOR_VERSION != RAMTST_CFG_H_AR_MAJOR_VERSION */
#if (RAMTST_CFG_C_AR_MINOR_VERSION != RAMTST_CFG_H_AR_MINOR_VERSION)
#error "RamTst_Cfg.c : Mismatch in Specification Minor Version"
#endif /* RAMTST_CFG_C_AR_MINOR_VERSION != RAMTST_CFG_H_AR_MINOR_VERSION */
#if (RAMTST_CFG_C_AR_PATCH_VERSION != RAMTST_CFG_H_AR_PATCH_VERSION)
#error "RamTst_Cfg.c : Mismatch in Specification Patch Version"
#endif /* RAMTST_CFG_C_AR_PATCH_VERSION != RAMTST_CFG_H_AR_PATCH_VERSION */
#if (RAMTST_CFG_C_SW_MAJOR_VERSION != RAMTST_CFG_H_SW_MAJOR_VERSION)
#error "RamTst_Cfg.c : Mismatch in Specification Major Version"
#endif /* RAMTST_CFG_C_SW_MAJOR_VERSION != RAMTST_CFG_H_SW_MAJOR_VERSION */
#if (RAMTST_CFG_C_SW_MINOR_VERSION != RAMTST_CFG_H_SW_MINOR_VERSION)
#error "RamTst_Cfg.c : Mismatch in Specification Minor Version"
#endif /* RAMTST_CFG_C_SW_MINOR_VERSION != RAMTST_CFG_H_SW_MINOR_VERSION */

/*===========================[M A C R O S]========================================================*/
/*===========================[T Y P E   D E F I N I T I O N S]====================================*/
/*===========================[E X T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/
/*===========================[I N T E R N A L   D A T A]==========================================*/
/*===========================[I N T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/
/*===========================[F U N C T I O N   I M P L E M E N T A T I O N S]====================*/

#define RAMTST_START_SEC_CONST_UNSPECIFIED
#include "RamTst_MemMap.h"

static RamTst_BlockParams RamTstBlockParams_Alg1[] =
{
        {
            1,                              /* RamTstBlockId */
            0x1fff12ff,                     /* RamTstEndAddress */
            0x1fff1000,                     /* RamTstStartAddress */
            0,                              /* RamTstFillPattern */
            RAMTEST_NON_DESTRUCTIVE,        /* RamTst_Policy */
            BLOCK_TEST_USED_METHOD_FOREGROUND,
        },
        {
            2,                              /* RamTstBlockId */
            0x1fff22ff,                     /* RamTstEndAddress */
            0x1fff2000,                     /* RamTstStartAddress */
            0,                              /* RamTstFillPattern */
            RAMTEST_NON_DESTRUCTIVE,        /* RamTst_Policy */
            BLOCK_TEST_USED_METHOD_FOREGROUND,
        },
        {
            3,                              /* RamTstBlockId */
            0x1fff32ff,                     /* RamTstEndAddress */
            0x1fff3000,                     /* RamTstStartAddress */
            0,                              /* RamTstFillPattern */
            RAMTEST_NON_DESTRUCTIVE,        /* RamTst_Policy */
            BLOCK_TEST_USED_METHOD_FOREGROUND,
        },
        {
            4,                              /* RamTstBlockId */
            0x1fff42ff,                     /* RamTstEndAddress */
            0x1fff4000,                     /* RamTstStartAddress */
            0,                              /* RamTstFillPattern */
            RAMTEST_NON_DESTRUCTIVE,        /* RamTst_Policy */
            BLOCK_TEST_USED_METHOD_FOREGROUND,
        },
        {
            5,                              /* RamTstBlockId */
            0x1fff52ff,                     /* RamTstEndAddress */
            0x1fff5000,                     /* RamTstStartAddress */
            0,                              /* RamTstFillPattern */
            RAMTEST_NON_DESTRUCTIVE,        /* RamTst_Policy */
            BLOCK_TEST_USED_METHOD_FOREGROUND,
        },
        {
            6,                              /* RamTstBlockId */
            0x1fff62ff,                     /* RamTstEndAddress */
            0x1fff6000,                     /* RamTstStartAddress */
            0,                              /* RamTstFillPattern */
            RAMTEST_NON_DESTRUCTIVE,        /* RamTst_Policy */
            BLOCK_TEST_USED_METHOD_FOREGROUND,
        },
};

static RamTst_AlgParams RamTstAlgParamsSet[] =
{
    {
        RAMTST_MARCH_TEST,                  /* RamTstAlgorithm */
        1,                                  /* RamTst_AlgParamsIdType */
        4096,                               /* RamTstExtNumberOfTestedCells */
        4096,                               /* RamTstMaxNumberOfTestedCells */
        6,                                  /* RamTstNumberOfBlocks */
        20,                                 /* RamTstNumberOfTestedCells */
        RamTstBlockParams_Alg1,            /* RamTst_BlockParams */
    },
};

/* PRQA S 3408++ */ /* MISRA Rule 8.4 */
const RamTst_ConfigType RamTstConfigRoot[] =
/* PRQA S 3408-- */ /* MISRA Rule 8.4 */
{
    {
        {
            1,                          /* RamTstDefaultAlgParamsId */
            4,                          /* RamTstMinNumberOfTestedCells */
            1,                          /* RamTstNumberOfAlgParamSets */
            RamTstAlgParamsSet,        /* RamTstAlgParams */
        #if RAMTST_TEST_COMPLETE_NOTIFICATION_API_ENABLE
            TestcompleteNotification,                   /* RamTst_TestCompletedNotificationPtr */
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

/*===========================[E N D   O F   F I L E]==============================================*/

