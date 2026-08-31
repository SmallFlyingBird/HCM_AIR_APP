/**
* @file    Mcu_Lld_Irq.c
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Mcu_Lld_Irq
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
extern "C"
{
#endif

/*==================================================================================================
                                           INCLUDE FILES
==================================================================================================*/
#include "Mcal.h"
#include "Mcu.h"
#include "Mcu_Lld.h"
#include "OsIf.h"
/*==================================================================================================
                                  SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_LLD_IRQ_VENDOR_ID_C                      (180)
#define MCU_LLD_IRQ_AR_RELEASE_MAJOR_VERSION_C       (4)
#define MCU_LLD_IRQ_AR_RELEASE_MINOR_VERSION_C       (4)
#define MCU_LLD_IRQ_AR_RELEASE_REVISION_VERSION_C    (0)
#define MCU_LLD_IRQ_SW_MAJOR_VERSION_C               (2)
#define MCU_LLD_IRQ_SW_MINOR_VERSION_C               (3)
#define MCU_LLD_IRQ_SW_PATCH_VERSION_C               (0)
/*==================================================================================================
                                        FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and MCU_LLD_IRQ header file are of the same vendor */
#if (MCU_LLD_IRQ_VENDOR_ID_C != MCU_LLD_VENDOR_ID)
#error "Mcu_Lld_Irq.c and Mcu_Lld_Irq.h have different vendor ids"
#endif

/* Check if source file and MCU_LLD_IRQ header file are of the same Autosar version */
#if (( MCU_LLD_IRQ_AR_RELEASE_MAJOR_VERSION_C != MCU_LLD_AR_RELEASE_MAJOR_VERSION) || \
      ( MCU_LLD_IRQ_AR_RELEASE_MINOR_VERSION_C != MCU_LLD_AR_RELEASE_MINOR_VERSION) || \
      ( MCU_LLD_IRQ_AR_RELEASE_REVISION_VERSION_C != MCU_LLD_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Mcu_Lld_Irq.c and Mcu_Lld_Irq.h are different"
#endif

/* Check if source file and MCU_LLD_IRQ header file are of the same Software version */
#if (( MCU_LLD_IRQ_SW_MAJOR_VERSION_C != MCU_LLD_SW_MAJOR_VERSION) || \
      ( MCU_LLD_IRQ_SW_MINOR_VERSION_C != MCU_LLD_SW_MINOR_VERSION) || \
      ( MCU_LLD_IRQ_SW_PATCH_VERSION_C != MCU_LLD_SW_PATCH_VERSION))
#error "Software Version Numbers of Mcu_Lld_Irq.c and Mcu_Lld_Irq.h are different"
#endif



/*==================================================================================================
                                          GLOBAL VARIABLES
==================================================================================================*/

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

#if (MCU_LLD_PCU_ISR_USED == STD_ON)
MCU_FUNC ISR(PCU_IRQHandler);
#endif

#if (MCU_LLD_SCU_ISR_USED == STD_ON)
MCU_FUNC ISR(SCU_IRQHandler);
#endif
/*==================================================================================================
                                         LOCAL VARIABLES
==================================================================================================*/
/**
 * GCOVR_EXCL_START: The following function is intended for interrupts. Since we cannot simulate
 * interrupt conditions in integration tests, we have excluded the following code from gcov testing.
 */

#if (MCU_LLD_PCU_ISR_USED == STD_ON)
MCU_FUNC ISR(PCU_IRQHandler) {
    Mcu_Lld_Pcu_ChannelIrqProcess();
}
#endif

#if (MCU_LLD_SCU_ISR_USED == STD_ON)
MCU_FUNC ISR(SCU_IRQHandler) {
    Mcu_Lld_Cmu_ChannelIrqProcess();
}
#endif
/* GCOVR_EXCL_STOP */
/*==================================================================================================
                                          LOCAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
                                            LOCAL MACROS
==================================================================================================*/
/*==================================================================================================
                                         LOCAL FUNCTIONS
==================================================================================================*/
/*==================================================================================================
                                          GLOBAL FUNCTIONS
==================================================================================================*/

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

/* End of file Mcu_Lld_Irq.c */

