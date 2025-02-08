
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
**  FILENAME    : Fee_Cfg.c                                                   **
**                                                                            **
**  Created on  : 2024/06/22 16:02:20                                         **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Configuration parameter of Fee                              **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19_11                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Fee_Cfg.h"
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define FEE_CFG_C_AR_MAJOR_VERSION  4u
#define FEE_CFG_C_AR_MINOR_VERSION  5u
#define FEE_CFG_C_AR_PATCH_VERSION  0u
#define FEE_CFG_C_SW_MAJOR_VERSION  2u
#define FEE_CFG_C_SW_MINOR_VERSION  0u
#define FEE_CFG_C_SW_PATCH_VERSION  0u
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (FEE_CFG_C_AR_MAJOR_VERSION != FEE_CFG_H_AR_MAJOR_VERSION)
    #error "Fee_Cfg.c:Mismatch in Specification Major Version"
#endif

#if (FEE_CFG_C_AR_MINOR_VERSION != FEE_CFG_H_AR_MINOR_VERSION)
    #error "Fee_Cfg.c:Mismatch in Specification Minor Version"
#endif

#if (FEE_CFG_C_AR_PATCH_VERSION != FEE_CFG_H_AR_PATCH_VERSION)
    #error "Fee_Cfg.c:Mismatch in Specification Patch Version"
#endif

#if (FEE_CFG_C_SW_MAJOR_VERSION != FEE_CFG_H_SW_MAJOR_VERSION)
    #error "Fee_Cfg.c:Mismatch in Specification Major Version"
#endif

#if (FEE_CFG_C_SW_MINOR_VERSION != FEE_CFG_H_SW_MINOR_VERSION)
    #error "Fee_Cfg.c:Mismatch in Specification Minor Version"
#endif
/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define FEE_START_SEC_PCCONFIG_DATA_UNSPECIFIED
#include "Fee_MemMap.h"
/* PRQA S 3408,1531++ */ /* MISRA Rule 8.4,Rule 8.7 */
CONST(Fee_BankConfigType, FEE_CONST_PCCFG) Fee_BankConfig[FEE_BANK_NUM] =
/* PRQA S 3408,1531-- */ /* MISRA Rule 8.4,Rule 8.7 */
{
    {
        0x0u,
        0x4000u,
    },
    {
        0x4000u,
        0x4000u,
    },
};
#define FEE_STOP_SEC_PCCONFIG_DATA_UNSPECIFIED
#include "Fee_MemMap.h"

#define FEE_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Fee_MemMap.h"
/* PRQA S 3408,1504++ */ /* MISRA Rule 8.4,Rule 8.7 */
CONST(Fee_BlockConfigType, FEE_CONST_PBCFG) Fee_BlockConfig[9] =
/* PRQA S 3408,1504++ */ /* MISRA Rule 8.4,Rule 8.7 */
{
    {
        0x100u,
        0x10u,
        FALSE
    },
    {
        0x200u,
        0x500u,
        FALSE
    },
    {
        0x300u,
        0x500u,
        FALSE
    },
    {
        0x400u,
        0x500u,
        FALSE
    },
    {
        0x500u,
        0x500u,
        FALSE
    },
    {
        0x600u,
        0x500u,
        FALSE
    },
    {
        0x700u,
        0x80u,
        FALSE
    },
    {
        0x800u,
        0x80u,
        FALSE
    },
    {
        0x900u,
        0x80u,
        FALSE
    },
};
#define FEE_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Fee_MemMap.h"

#define FEE_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Fee_MemMap.h"
/* PRQA S 3408++ */ /* MISRA Rule 8.4 */
CONST(Fee_ConfigType, FEE_CONST_PBCFG) Fee_ConfigData =
/* PRQA S 3408++ */ /* MISRA Rule 8.4 */
{
    9u,
    &Fee_BlockConfig[0]
};
#define FEE_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "Fee_MemMap.h"

