/**************************************************************************************************/
/**
 * @file      : Tim_Ocu_Drv_Irq.c
 * @brief     : Ocu low level driver interrupt source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Ocu_Module
 *  @{
 */

/** @addtogroup Tim_Ocu_Drv_Irq
 *  @brief Ocu driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Tim_Ocu_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define TIM_OCU_DRV_IRQ_C_VENDOR_ID                   0x00B3U
#define TIM_OCU_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION    4U
#define TIM_OCU_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION    6U
#define TIM_OCU_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION 0U
#define TIM_OCU_DRV_IRQ_C_SW_MAJOR_VERSION            1U
#define TIM_OCU_DRV_IRQ_C_SW_MINOR_VERSION            2U
#define TIM_OCU_DRV_IRQ_C_SW_PATCH_VERSION            1U

/* Check if current file and Tim_Ocu_Drv.h are of the same vendor */
#if (TIM_OCU_DRV_IRQ_C_VENDOR_ID != TIM_OCU_DRV_H_VENDOR_ID)
    #error "Vendor ID of Tim_Ocu_Drv_Irq.c and Tim_Ocu_Drv.h are different"
#endif

/* Check if  source file and Tim_Ocu_Drv.h file are of the same Autosar version */
#if ((TIM_OCU_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION != TIM_OCU_DRV_H_AR_RELEASE_MAJOR_VERSION) ||         \
     (TIM_OCU_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION != TIM_OCU_DRV_H_AR_RELEASE_MINOR_VERSION) ||         \
     (TIM_OCU_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION != TIM_OCU_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Tim_Ocu_Drv_Irq.c and Tim_Ocu_Drv.h are different"
#endif

/* Check if current file and Tim_Ocu_Drv.h are of the same Software version */
#if ((TIM_OCU_DRV_IRQ_C_SW_MAJOR_VERSION != TIM_OCU_DRV_H_SW_MAJOR_VERSION) ||                    \
     (TIM_OCU_DRV_IRQ_C_SW_MINOR_VERSION != TIM_OCU_DRV_H_SW_MINOR_VERSION) ||           \
     (TIM_OCU_DRV_IRQ_C_SW_PATCH_VERSION != TIM_OCU_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Tim_Ocu_Drv_Irq.c and Tim_Ocu_Drv.h are different"
#endif

#define OCU_START_SEC_CODE
#include "Ocu_MemMap.h"

#if (TIM_OCU_DRV_NOTIFICATION_SUPPORTED == STD_ON)

#ifdef TIM_OCU_DRV_0_ENABLE
#if (TIM_OCU_DRV_0_ENABLE == STD_ON)
    ISR(Tim_Drv_0_ChIrqHandler);
#endif
#endif

#ifdef TIM_OCU_DRV_1_ENABLE
#if (TIM_OCU_DRV_1_ENABLE == STD_ON)
    ISR(Tim_Drv_1_ChIrqHandler);
#endif
#endif

#ifdef TIM_OCU_DRV_2_ENABLE
#if (TIM_OCU_DRV_2_ENABLE == STD_ON)
    ISR(Tim_Drv_2_ChIrqHandler);
#endif
#endif

#ifdef TIM_OCU_DRV_3_ENABLE
#if (TIM_OCU_DRV_3_ENABLE == STD_ON)
    ISR(Tim_Drv_3_ChIrqHandler);
#endif
#endif

#ifdef TIM_OCU_DRV_0_ENABLE
#if (TIM_OCU_DRV_0_ENABLE == STD_ON)
/**
 * @brief      TIM 0 Channel IRQHandler
 *
 * @param[in]  none
 *
 * @return    none
 *
 */
ISR(Tim_Drv_0_ChIrqHandler)
{
    Tim_Ocu_Drv_ChIntHandler(TIM_OCU_DRV_ID_0);
    EXIT_INTERRUPT();
}
#endif
#endif

#ifdef TIM_OCU_DRV_1_ENABLE
#if (TIM_OCU_DRV_1_ENABLE == STD_ON)
/**
 * @brief      TIM 1 Channel IRQHandler
 *
 * @param[in]  none
 *
 * @return    none
 *
 */
ISR(Tim_Drv_1_ChIrqHandler)
{
    Tim_Ocu_Drv_ChIntHandler(TIM_OCU_DRV_ID_1);
    EXIT_INTERRUPT();
}
#endif
#endif

#ifdef TIM_OCU_DRV_2_ENABLE
#if (TIM_OCU_DRV_2_ENABLE == STD_ON)
/**
 * @brief      TIM 2 Channel IRQHandler
 *
 * @param[in]  none
 *
 * @return    none
 *
 */
ISR(Tim_Drv_2_ChIrqHandler)
{
    Tim_Ocu_Drv_ChIntHandler(TIM_OCU_DRV_ID_2);
    EXIT_INTERRUPT();
}
#endif
#endif

#ifdef TIM_OCU_DRV_3_ENABLE
#if (TIM_OCU_DRV_3_ENABLE == STD_ON)
/**
 * @brief      TIM 3 Channel IRQHandler
 *
 * @param[in]  none
 *
 * @return    none
 *
 */
ISR(Tim_Drv_3_ChIrqHandler)
{
    Tim_Ocu_Drv_ChIntHandler(TIM_OCU_DRV_ID_3);
    EXIT_INTERRUPT();
}
#endif
#endif

#endif

#define OCU_STOP_SEC_CODE
#include "Ocu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} end of group Tim_Ocu_Drv_Irq */

/** @} end of group Ocu_Module */
