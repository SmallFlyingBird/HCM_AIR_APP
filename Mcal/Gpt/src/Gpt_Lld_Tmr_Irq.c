/**
 * @file    Gpt_Lld_Tmr_Irq.c
 * @version V2.3.0
 *
 * @brief   MCU Gpt module interface
 * @details API implementation for GPT driver
 *
 * @addtogroup GPT_LLD_TMR_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Tmr
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

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Gpt_Lld_Tmr.h"
#include "OsIf.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_LLD_TMR_IRQ_VENDOR_ID_C                      (180)
#define GPT_LLD_TMR_IRQ_AR_RELEASE_MAJOR_VERSION_C       (4)
#define GPT_LLD_TMR_IRQ_AR_RELEASE_MINOR_VERSION_C       (4)
#define GPT_LLD_TMR_IRQ_AR_RELEASE_REVISION_VERSION_C    (0)
#define GPT_LLD_TMR_IRQ_SW_MAJOR_VERSION_C               (2)
#define GPT_LLD_TMR_IRQ_SW_MINOR_VERSION_C               (3)
#define GPT_LLD_TMR_IRQ_SW_PATCH_VERSION_C               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and GPT_LLD_RTC header file are of the same vendor */
#if (GPT_LLD_TMR_IRQ_VENDOR_ID_C != GPT_LLD_TMR_VENDOR_ID)
#error "Gpt_Lld_Tmr_Irq.c and Gpt_Lld_Tmr.h have different vendor ids"
#endif

/* Check if source file and GPT_LLD_RTC header file are of the same Autosar version */
#if ((GPT_LLD_TMR_IRQ_AR_RELEASE_MAJOR_VERSION_C != GPT_LLD_TMR_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_LLD_TMR_IRQ_AR_RELEASE_MINOR_VERSION_C != GPT_LLD_TMR_AR_RELEASE_MINOR_VERSION) || \
     (GPT_LLD_TMR_IRQ_AR_RELEASE_REVISION_VERSION_C != GPT_LLD_TMR_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Gpt_Lld_Tmr_Irq.c and Gpt_Lld_Tmr.h are different"
#endif

/* Check if source file and GPT_LLD_RTC header file are of the same Software version */
#if ((GPT_LLD_TMR_IRQ_SW_MAJOR_VERSION_C != GPT_LLD_TMR_SW_MAJOR_VERSION) || \
     (GPT_LLD_TMR_IRQ_SW_MINOR_VERSION_C != GPT_LLD_TMR_SW_MINOR_VERSION) || \
     (GPT_LLD_TMR_IRQ_SW_PATCH_VERSION_C != GPT_LLD_TMR_SW_PATCH_VERSION))
#error "Software Version Numbers of Gpt_Lld_Tmr_Irq.c and Gpt_Lld_Tmr.h are different"
#endif

/*==================================================================================================
 *                                   GLOBAL FUNCTIONS PROTOTYPES
==================================================================================================*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

#if defined(CPU_YTM32B1MD1) || defined(CPU_YTM32B1ME0)
#if defined(GPT_LLD_TMR_0_CH_0_ISR_USED)
GPT_FUNC ISR(TMR0_Ch0_IRQHandler);
#endif

#if defined(GPT_LLD_TMR_0_CH_1_ISR_USED)
GPT_FUNC ISR(TMR0_Ch1_IRQHandler);
#endif

#if defined(GPT_LLD_TMR_0_CH_2_ISR_USED)
GPT_FUNC ISR(TMR0_Ch2_IRQHandler);
#endif

#if defined(GPT_LLD_TMR_0_CH_3_ISR_USED)
GPT_FUNC ISR(TMR0_Ch3_IRQHandler);
#endif
#endif

#if defined(CPU_YTM32B1HA0)
#if defined(GPT_LLD_TMR_1_CH_0_ISR_USED)
GPT_FUNC ISR(TMR0_IRQHandler);
#endif

#if defined(GPT_LLD_TMR_1_CH_1_ISR_USED)
GPT_FUNC ISR(TMR1_IRQHandler);
#endif
#endif

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
==================================================================================================*/
#if defined(CPU_YTM32B1MD1) || defined(CPU_YTM32B1ME0)
#if defined(GPT_LLD_TMR_0_CH_0_ISR_USED)
/**
 * @brief       TMR0 CH0 IRQ handler.
 * @return      void
 */
GPT_FUNC ISR(TMR0_Ch0_IRQHandler)
{
    Gpt_Lld_Tmr_ChannelIrqProcess(0U, 0U);
}
#endif

#if defined(GPT_LLD_TMR_0_CH_1_ISR_USED)
/**
 * @brief       TMR0 CH1 IRQ handler.
 * @return      void
 */
GPT_FUNC ISR(TMR0_Ch1_IRQHandler)
{
    Gpt_Lld_Tmr_ChannelIrqProcess(0U, 1U);
}
#endif

#if defined(GPT_LLD_TMR_0_CH_2_ISR_USED)
/**
 * @brief       TMR0 CH2 IRQ handler.
 * @return      void
 */
GPT_FUNC ISR(TMR0_Ch2_IRQHandler)
{
    Gpt_Lld_Tmr_ChannelIrqProcess(0U, 2U);
}
#endif

#if defined(GPT_LLD_TMR_0_CH_3_ISR_USED)
/**
 * @brief       TMR0 CH3 IRQ handler.
 * @return      void
 */
GPT_FUNC ISR(TMR0_Ch3_IRQHandler)
{
    Gpt_Lld_Tmr_ChannelIrqProcess(0U, 3U);
}
#endif
#endif

#if defined(CPU_YTM32B1HA0)
#if defined(GPT_LLD_TMR_0_CH_0_ISR_USED) || defined(GPT_LLD_TMR_0_CH_1_ISR_USED) \
|| defined(GPT_LLD_TMR_0_CH_2_ISR_USED) || defined(GPT_LLD_TMR_0_CH_3_ISR_USED)
/**
 * @brief       TMR0 IRQ handler.
 * @return      void
 */
GPT_FUNC ISR(TMR0_IRQHandler)
{
    Gpt_Lld_Tmr_ChannelIrqProcess(0U);
}
#endif

#if defined(GPT_LLD_TMR_1_CH_0_ISR_USED) || defined(GPT_LLD_TMR_1_CH_1_ISR_USED) \
|| defined(GPT_LLD_TMR_1_CH_2_ISR_USED) || defined(GPT_LLD_TMR_1_CH_3_ISR_USED)
/**
 * @brief       TMR1 IRQ handler.
 * @return      void
 */
GPT_FUNC ISR(TMR1_IRQHandler)
{
    Gpt_Lld_Tmr_ChannelIrqProcess(1U);
}
#endif
#endif

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

