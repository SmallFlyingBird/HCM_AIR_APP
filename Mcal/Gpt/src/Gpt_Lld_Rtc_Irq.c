/**
 * @file    Gpt_Lld_Rtc_Irq.c
 * @version V2.3.0
 *
 * @brief   MCU Gpt module interface
 * @details API implementation for GPT driver
 *
 * @addtogroup GPT_LLD_RTC_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Rtc
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

#ifdef __cplusplus
extern "C"
{
#endif

/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include "Gpt_Lld_Rtc.h"
#include "OsIf.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_LLD_RTC_IRQ_VENDOR_ID_C                      (180)
#define GPT_LLD_RTC_IRQ_AR_RELEASE_MAJOR_VERSION_C       (4)
#define GPT_LLD_RTC_IRQ_AR_RELEASE_MINOR_VERSION_C       (4)
#define GPT_LLD_RTC_IRQ_AR_RELEASE_REVISION_VERSION_C    (0)
#define GPT_LLD_RTC_IRQ_SW_MAJOR_VERSION_C               (2)
#define GPT_LLD_RTC_IRQ_SW_MINOR_VERSION_C               (3)
#define GPT_LLD_RTC_IRQ_SW_PATCH_VERSION_C               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and GPT_LLD_RTC header file are of the same vendor */
#if (GPT_LLD_RTC_IRQ_VENDOR_ID_C != GPT_LLD_RTC_VENDOR_ID)
#error "Gpt_Lld_Rtc_Irq.c and Gpt_Lld_Rtc.h have different vendor ids"
#endif

/* Check if source file and GPT_LLD_RTC header file are of the same Autosar version */
#if ((GPT_LLD_RTC_IRQ_AR_RELEASE_MAJOR_VERSION_C != GPT_LLD_RTC_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_LLD_RTC_IRQ_AR_RELEASE_MINOR_VERSION_C != GPT_LLD_RTC_AR_RELEASE_MINOR_VERSION) || \
     (GPT_LLD_RTC_IRQ_AR_RELEASE_REVISION_VERSION_C != GPT_LLD_RTC_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Gpt_Lld_Rtc_Irq.c and Gpt_Lld_Rtc.h are different"
#endif

/* Check if source file and GPT_LLD_RTC header file are of the same Software version */
#if ((GPT_LLD_RTC_IRQ_SW_MAJOR_VERSION_C != GPT_LLD_RTC_SW_MAJOR_VERSION) || \
     (GPT_LLD_RTC_IRQ_SW_MINOR_VERSION_C != GPT_LLD_RTC_SW_MINOR_VERSION) || \
     (GPT_LLD_RTC_IRQ_SW_PATCH_VERSION_C != GPT_LLD_RTC_SW_PATCH_VERSION))
#error "Software Version Numbers of Gpt_Lld_Rtc_Irq.c and Gpt_Lld_Rtc.h are different"
#endif

/*==================================================================================================
 *                                   GLOBAL FUNCTIONS PROTOTYPES
==================================================================================================*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

#if defined(GPT_LLD_RTC_0_CH_0_ISR_USED)
GPT_FUNC ISR(RTC_IRQHandler);
#endif

/*==================================================================================================
                                        GLOBAL FUNCTIONS
==================================================================================================*/
#if defined(GPT_LLD_RTC_0_CH_0_ISR_USED)
/**
 * @brief       RTC0 IRQ handler.
 * @return      void
 */
GPT_FUNC ISR(RTC_IRQHandler)
{
    Gpt_Lld_Rtc_IrqProcess();
}
#endif

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

