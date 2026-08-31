/**
 * @file    Gpt_Lld_Lptmr_Reg.h
 * @version V2.3.0
 *
 * @brief   AUTOSAR Gpt module interface
 * @details API implementation for Gpt driver
 *
 * @addtogroup GPT_LLD_LPTMR_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Lptmr
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

#ifndef GPT_LLD_LPTMR_REG_H
#define GPT_LLD_LPTMR_REG_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                      INCLUDE FILES
==================================================================================================*/
#include "pSIP_Lptmr.h"


#if (GPT_SUPPORT_POWERDOWN_WAKEUP == STD_ON)
#include "pSIP_Wku.h"
#endif

/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_LLD_LPTMR_REG_VENDOR_ID                      (180)
#define GPT_LLD_LPTMR_REG_AR_RELEASE_MAJOR_VERSION       (4)
#define GPT_LLD_LPTMR_REG_AR_RELEASE_MINOR_VERSION       (4)
#define GPT_LLD_LPTMR_REG_AR_RELEASE_REVISION_VERSION    (0)
#define GPT_LLD_LPTMR_REG_SW_MAJOR_VERSION               (2)
#define GPT_LLD_LPTMR_REG_SW_MINOR_VERSION               (3)
#define GPT_LLD_LPTMR_REG_SW_PATCH_VERSION               (0)

#ifdef __cplusplus
}
#endif

#endif /* GPT_LLD_LPTMR_REG_H */

/** @} */

