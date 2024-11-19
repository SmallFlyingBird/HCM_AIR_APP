/***************************************************************************************************/
/**
 * @file      : Can_Drv_Irq.c
 * @brief     : Can Interrupt Source file
 *                - Platform: Z20K14xM
 *                - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup  Can_Module
 *  @{
 */

/** @addtogroup Can_Drv
 *  @brief Can low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Can_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define CAN_DRV_IRQ_C_VENDOR_ID                   0x00B3U
#define CAN_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION    4U
#define CAN_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION    6U
#define CAN_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION 0U
#define CAN_DRV_IRQ_C_SW_MAJOR_VERSION            1U
#define CAN_DRV_IRQ_C_SW_MINOR_VERSION            2U
#define CAN_DRV_IRQ_C_SW_PATCH_VERSION            2U

/* Check if current file and Can_Drv.h are the same vendor */
#if (CAN_DRV_IRQ_C_VENDOR_ID != CAN_DRV_H_VENDOR_ID)
    #error "Vendor ID of Can_Irq.c and Can_Drv.h are different"
#endif
/* Check if current file and Can_Drv.h are of the same Autosar version */
#if ((CAN_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION != CAN_DRV_H_AR_RELEASE_MAJOR_VERSION) ||             \
     (CAN_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION != CAN_DRV_H_AR_RELEASE_MINOR_VERSION) ||             \
     (CAN_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION != CAN_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Can_Drv_Irq.c and Can_Drv.h are different"
#endif

/* Check if current file and Can_Drv.h are of the same Software version */
#if ((CAN_DRV_IRQ_C_SW_MAJOR_VERSION != CAN_DRV_H_SW_MAJOR_VERSION) ||                             \
     (CAN_DRV_IRQ_C_SW_MINOR_VERSION != CAN_DRV_H_SW_MINOR_VERSION) ||                             \
     (CAN_DRV_IRQ_C_SW_PATCH_VERSION != CAN_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Can_Drv_Irq.c and Can_Drv.h are different"
#endif

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

/** @} end of group Private_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */
/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
#if (STD_ON == CAN_DRV_0_ENABLE)
ISR(Can_Drv_0_BusOffIrqHandler);

ISR(Can_Drv_0_ErrIrqHandler);

    #if (CAN_DRV_FD_CH0_ENABLE == STD_ON)
ISR(Can_Drv_0_ErrFdIrqHandler);
    #endif

ISR(Can_Drv_0_Mb0To15IrqHandler);

ISR(Can_Drv_0_Mb16To31IrqHandler);

ISR(Can_Drv_0_Mb32To47IrqHandler);

ISR(Can_Drv_0_Mb48To63IrqHandler);

ISR(Can_Drv_0_TxWarnIrqHandler);

ISR(Can_Drv_0_RxWarnIrqHandler);

ISR(Can_Drv_0_SelfWakeupIrqHandler);

ISR(Can_Drv_0_EccIrqHandler);
#endif

#if (STD_ON == CAN_DRV_1_ENABLE)
ISR(Can_Drv_1_BusOffIrqHandler);

ISR(Can_Drv_1_ErrIrqHandler);

    #if (CAN_DRV_FD_CH1_ENABLE == STD_ON)
ISR(Can_Drv_1_ErrFdIrqHandler);
    #endif

ISR(Can_Drv_1_Mb0To15IrqHandler);

ISR(Can_Drv_1_Mb16To31IrqHandler);

ISR(Can_Drv_1_Mb32To47IrqHandler);

ISR(Can_Drv_1_Mb48To63IrqHandler);

ISR(Can_Drv_1_TxWarnIrqHandler);

ISR(Can_Drv_1_RxWarnIrqHandler);

ISR(Can_Drv_1_SelfWakeupIrqHandler);

ISR(Can_Drv_1_EccIrqHandler);
#endif

#if (STD_ON == CAN_DRV_2_ENABLE)

ISR(Can_Drv_2_BusOffIrqHandler);

ISR(Can_Drv_2_ErrIrqHandler);

    #if (CAN_DRV_FD_CH2_ENABLE == STD_ON)
ISR(Can_Drv_2_ErrFdIrqHandler);
    #endif

ISR(Can_Drv_2_Mb0To15IrqHandler);

ISR(Can_Drv_2_Mb16To31IrqHandler);

ISR(Can_Drv_2_Mb32To47IrqHandler);

ISR(Can_Drv_2_Mb48To63IrqHandler);

ISR(Can_Drv_2_TxWarnIrqHandler);

ISR(Can_Drv_2_RxWarnIrqHandler);

ISR(Can_Drv_2_SelfWakeupIrqHandler);

ISR(Can_Drv_2_EccIrqHandler);

#endif

#if (STD_ON == CAN_DRV_3_ENABLE)

ISR(Can_Drv_3_BusOffIrqHandler);

ISR(Can_Drv_3_ErrIrqHandler);

    #if (CAN_DRV_FD_CH3_ENABLE == STD_ON)
ISR(Can_Drv_3_ErrFdIrqHandler);
    #endif

ISR(Can_Drv_3_Mb0To15IrqHandler);

ISR(Can_Drv_3_Mb16To31IrqHandler);

ISR(Can_Drv_3_Mb32To47IrqHandler);

ISR(Can_Drv_3_Mb48To63IrqHandler);

ISR(Can_Drv_3_TxWarnIrqHandler);

ISR(Can_Drv_3_RxWarnIrqHandler);

ISR(Can_Drv_3_SelfWakeupIrqHandler);

ISR(Can_Drv_3_EccIrqHandler);

#endif

#if ((CAN_DRV_TOTAL_NUM > 6) || ((CAN_DRV_TOTAL_NUM > 4)))

    #if (STD_ON == CAN_DRV_4_ENABLE)

ISR(Can_Drv_4_BusOffIrqHandler);

ISR(Can_Drv_4_ErrIrqHandler);

        #if (CAN_DRV_FD_CH4_ENABLE == STD_ON)
ISR(Can_Drv_4_ErrFdIrqHandler);
        #endif

ISR(Can_Drv_4_Mb0To15IrqHandler);

ISR(Can_Drv_4_Mb16To31IrqHandler);

ISR(Can_Drv_4_Mb32To47IrqHandler);

ISR(Can_Drv_4_Mb48To63IrqHandler);

ISR(Can_Drv_4_TxWarnIrqHandler);

ISR(Can_Drv_4_RxWarnIrqHandler);

ISR(Can_Drv_4_SelfWakeupIrqHandler);

ISR(Can_Drv_4_EccIrqHandler);

    #endif

    #if (STD_ON == CAN_DRV_5_ENABLE)

ISR(Can_Drv_5_BusOffIrqHandler);

ISR(Can_Drv_5_ErrIrqHandler);

        #if (CAN_DRV_FD_CH5_ENABLE == STD_ON)
ISR(Can_Drv_5_ErrFdIrqHandler);
        #endif

ISR(Can_Drv_5_Mb0To15IrqHandler);

ISR(Can_Drv_5_Mb16To31IrqHandler);

ISR(Can_Drv_5_Mb32To47IrqHandler);

ISR(Can_Drv_5_Mb48To63IrqHandler);

ISR(Can_Drv_5_TxWarnIrqHandler);

ISR(Can_Drv_5_RxWarnIrqHandler);
ISR(Can_Drv_5_SelfWakeupIrqHandler);

ISR(Can_Drv_5_EccIrqHandler);

    #endif
#endif
#if (CAN_DRV_TOTAL_NUM > 6)
    #if (STD_ON == CAN_DRV_6_ENABLE)

ISR(Can_Drv_6_BusOffIrqHandler);

ISR(Can_Drv_6_ErrIrqHandler);

        #if (CAN_DRV_FD_CH6_ENABLE == STD_ON)
ISR(Can_Drv_6_ErrFdIrqHandler);
        #endif

ISR(Can_Drv_6_Mb0To31IrqHandler);

ISR(Can_Drv_6_Mb32To63IrqHandler);

ISR(Can_Drv_6_Mb64To95IrqHandler);

ISR(Can_Drv_6_Mb96To127IrqHandler);

ISR(Can_Drv_6_TxWarnIrqHandler);

ISR(Can_Drv_6_RxWarnIrqHandler);

ISR(Can_Drv_6_SelfWakeupIrqHandler);

ISR(Can_Drv_6_EccIrqHandler);

    #endif

    #if (STD_ON == CAN_DRV_7_ENABLE)

ISR(Can_Drv_7_BusOffIrqHandler);

ISR(Can_Drv_7_ErrIrqHandler);
        #if (CAN_DRV_FD_CH7_ENABLE == STD_ON)
ISR(Can_Drv_7_ErrFdIrqHandler);
        #endif

ISR(Can_Drv_7_Mb0To31IrqHandler);

ISR(Can_Drv_7_Mb32To63IrqHandler);

ISR(Can_Drv_7_Mb64To95IrqHandler);

ISR(Can_Drv_7_Mb96To127IrqHandler);

ISR(Can_Drv_7_TxWarnIrqHandler);

ISR(Can_Drv_7_RxWarnIrqHandler);

ISR(Can_Drv_7_SelfWakeupIrqHandler);

ISR(Can_Drv_7_EccIrqHandler);

    #endif
#endif

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"
/** @} end of group Public_FunctionDeclaration */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
#if (STD_ON == CAN_DRV_0_ENABLE)
/**
 * @brief  Can 0 bus off interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_0_BusOffIrqHandler)
{
    Can_Drv_BusOffIntHandler(0U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 0 error interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_0_ErrIrqHandler)
{
    Can_Drv_ErrorIntHandler(0U);
    EXIT_INTERRUPT();
}

    #if (CAN_DRV_FD_CH0_ENABLE == STD_ON)
/**
 * @brief  Can 0 fd error interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_0_ErrFdIrqHandler)
{
    Can_Drv_FdErrorIntHandler(0U);
    EXIT_INTERRUPT();
}
    #endif

/**
 * @brief  Can 0 MB0TO15 interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_0_Mb0To15IrqHandler)
{
    Can_Drv_IntHandler(0U, 0U, 15U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 0 MB16TO31 interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_0_Mb16To31IrqHandler)
{
    Can_Drv_IntHandler(0U, 16U, 31U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 0 MB32TO47 interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_0_Mb32To47IrqHandler)
{
    Can_Drv_IntHandler(0U, 32U, 47U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 0 MB48TO63 interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_0_Mb48To63IrqHandler)
{
    Can_Drv_IntHandler(0U, 48U, 63U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 0 TX warn interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_0_TxWarnIrqHandler)
{
    Can_Drv_TxWarnIntHandler(0U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 0 RX warn interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_0_RxWarnIrqHandler)
{
    Can_Drv_RxWarnIntHandler(0U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 0 self wakeup interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_0_SelfWakeupIrqHandler)
{
    Can_Drv_WakeUpIntHandler(0U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 0 ecc interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_0_EccIrqHandler)
{
    Can_Drv_EccIntHandler(0U);
    EXIT_INTERRUPT();
}
#endif

#if (STD_ON == CAN_DRV_1_ENABLE)
/**
 * @brief  Can 1 bus off interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_1_BusOffIrqHandler)
{
    Can_Drv_BusOffIntHandler(1U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 1 error interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_1_ErrIrqHandler)
{
    Can_Drv_ErrorIntHandler(1U);
    EXIT_INTERRUPT();
}

#if (CAN_DRV_FD_CH1_ENABLE == STD_ON)
/**
 * @brief  Can 1 fd error interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_1_ErrFdIrqHandler)
{
    Can_Drv_FdErrorIntHandler(1U);
    EXIT_INTERRUPT();
}
    #endif

/**
 * @brief  Can 1 MB0TO15 interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_1_Mb0To15IrqHandler)
{
    Can_Drv_IntHandler(1U, 0U, 15U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 1 MB16TO31 interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_1_Mb16To31IrqHandler)
{
    Can_Drv_IntHandler(1U, 16U, 31U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 1 MB32TO47 interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_1_Mb32To47IrqHandler)
{
    Can_Drv_IntHandler(1U, 32U, 47U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 1 MB48TO63 interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_1_Mb48To63IrqHandler)
{
    Can_Drv_IntHandler(1U, 48U, 63U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 1 TX warn interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_1_TxWarnIrqHandler)
{
    Can_Drv_TxWarnIntHandler(1U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 1 RX warn interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_1_RxWarnIrqHandler)
{
    Can_Drv_RxWarnIntHandler(1U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 1 self wakeup interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_1_SelfWakeupIrqHandler)
{
    Can_Drv_WakeUpIntHandler(1U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 1 ecc interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_1_EccIrqHandler)
{
    Can_Drv_EccIntHandler(1U);
    EXIT_INTERRUPT();
}
#endif

#if (STD_ON == CAN_DRV_2_ENABLE)
/**
 * @brief  Can 2 bus off interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_2_BusOffIrqHandler)
{
    Can_Drv_BusOffIntHandler(2U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 2 error interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_2_ErrIrqHandler)
{
    Can_Drv_ErrorIntHandler(2U);
    EXIT_INTERRUPT();
}

#if (CAN_DRV_FD_CH2_ENABLE == STD_ON)
/**
 * @brief  Can 2 error fd interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_2_ErrFdIrqHandler)
{
    Can_Drv_FdErrorIntHandler(2U);
    EXIT_INTERRUPT();
}
    #endif

/**
 * @brief  Can 2 MB0TO15 interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_2_Mb0To15IrqHandler)
{
    Can_Drv_IntHandler(2U, 0U, 15U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 2 MB16TO31 interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_2_Mb16To31IrqHandler)
{
    Can_Drv_IntHandler(2U, 16U, 31U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 2 MB32TO47 interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_2_Mb32To47IrqHandler)
{
    Can_Drv_IntHandler(2U, 32U, 47U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 2 MB48TO63 interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_2_Mb48To63IrqHandler)
{
    Can_Drv_IntHandler(2U, 48U, 63U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 2 TX warn interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_2_TxWarnIrqHandler)
{
    Can_Drv_TxWarnIntHandler(2U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 2 RX warn interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_2_RxWarnIrqHandler)
{
    Can_Drv_RxWarnIntHandler(2U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 2 self wakeup interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_2_SelfWakeupIrqHandler)
{
    Can_Drv_WakeUpIntHandler(2U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 2 ecc interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_2_EccIrqHandler)
{
    Can_Drv_EccIntHandler(2U);
    EXIT_INTERRUPT();
}

#endif

#if (STD_ON == CAN_DRV_3_ENABLE)
/**
 * @brief  Can 3 bus off interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_3_BusOffIrqHandler)
{
    Can_Drv_BusOffIntHandler(3U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 3 error interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_3_ErrIrqHandler)
{
    Can_Drv_ErrorIntHandler(3U);
    EXIT_INTERRUPT();
}

    #if (CAN_DRV_FD_CH3_ENABLE == STD_ON)
/**
 * @brief  Can 3 error fd interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_3_ErrFdIrqHandler)
{
    Can_Drv_FdErrorIntHandler(3U);
    EXIT_INTERRUPT();
}
    #endif

/**
 * @brief  Can 3 MB0TO15 interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_3_Mb0To15IrqHandler)
{
    Can_Drv_IntHandler(3U, 0U, 15U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 3 MB16TO31 interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_3_Mb16To31IrqHandler)
{
    Can_Drv_IntHandler(3U, 16U, 31U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 3 MB32TO47 interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_3_Mb32To47IrqHandler)
{
    Can_Drv_IntHandler(3U, 32U, 47U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 3 MB48TO63 interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_3_Mb48To63IrqHandler)
{
    Can_Drv_IntHandler(3U, 48U, 63U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 3 TX warn interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_3_TxWarnIrqHandler)
{
    Can_Drv_TxWarnIntHandler(3U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 3 RX warn interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_3_RxWarnIrqHandler)
{
    Can_Drv_RxWarnIntHandler(3U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 3 self wakeup interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_3_SelfWakeupIrqHandler)
{
    Can_Drv_WakeUpIntHandler(3U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 3 ecc interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_3_EccIrqHandler)
{
    Can_Drv_EccIntHandler(3U);
    EXIT_INTERRUPT();
}

#endif

#if ((CAN_DRV_TOTAL_NUM > 6) || ((CAN_DRV_TOTAL_NUM > 4)))

#if (STD_ON == CAN_DRV_4_ENABLE)
/**
 * @brief  Can 4 bus off interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_4_BusOffIrqHandler)
{
    Can_Drv_BusOffIntHandler(4U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 4 error interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_4_ErrIrqHandler)
{
    Can_Drv_ErrorIntHandler(4U);
    EXIT_INTERRUPT();
}

#if (CAN_DRV_FD_CH4_ENABLE == STD_ON)
/**
 * @brief  Can 4 error fd interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_4_ErrFdIrqHandler)
{
    Can_Drv_FdErrorIntHandler(4U);
    EXIT_INTERRUPT();
}
        #endif

/**
 * @brief  Can 4 MB0TO15 interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_4_Mb0To15IrqHandler)
{
    Can_Drv_IntHandler(4U, 0U, 15U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 4 MB16TO31 interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_4_Mb16To31IrqHandler)
{
    Can_Drv_IntHandler(4U, 16U, 31U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 4 MB32TO47 interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_4_Mb32To47IrqHandler)
{
    Can_Drv_IntHandler(4U, 32U, 47U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 4 MB48TO63 interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_4_Mb48To63IrqHandler)
{
    Can_Drv_IntHandler(4U, 48U, 63U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 4 TX warn interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_4_TxWarnIrqHandler)
{
    Can_Drv_TxWarnIntHandler(4U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 4 RX warn interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_4_RxWarnIrqHandler)
{
    Can_Drv_RxWarnIntHandler(4U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 4 self wakeup interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_4_SelfWakeupIrqHandler)
{
    Can_Drv_WakeUpIntHandler(4U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 4 ecc interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_4_EccIrqHandler)
{
    Can_Drv_EccIntHandler(4U);
    EXIT_INTERRUPT();
}

#endif

#if (STD_ON == CAN_DRV_5_ENABLE)
/**
 * @brief  Can 5 bus off interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_5_BusOffIrqHandler)
{
    Can_Drv_BusOffIntHandler(5U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 5 error interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_5_ErrIrqHandler)
{
    Can_Drv_ErrorIntHandler(5U);
    EXIT_INTERRUPT();
}

#if (CAN_DRV_FD_CH5_ENABLE == STD_ON)
/**
 * @brief  Can 5 error fd interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_5_ErrFdIrqHandler)
{
    Can_Drv_FdErrorIntHandler(5U);
    EXIT_INTERRUPT();
}
        #endif

/**
 * @brief  Can 5 MB0TO15 interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_5_Mb0To15IrqHandler)
{
    Can_Drv_IntHandler(5U, 0U, 15U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 5 MB16TO31 interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_5_Mb16To31IrqHandler)
{
    Can_Drv_IntHandler(5U, 16U, 31U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 5 MB32TO47 interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_5_Mb32To47IrqHandler)
{
    Can_Drv_IntHandler(5U, 32U, 47U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 5 MB48TO63 interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_5_Mb48To63IrqHandler)
{
    Can_Drv_IntHandler(5U, 48U, 63U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 5 TX warn interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_5_TxWarnIrqHandler)
{
    Can_Drv_TxWarnIntHandler(5U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 5 RX warn interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_5_RxWarnIrqHandler)
{
    Can_Drv_RxWarnIntHandler(5U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 5 self wakeup interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_5_SelfWakeupIrqHandler)
{
    Can_Drv_WakeUpIntHandler(5U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 5 ecc interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_5_EccIrqHandler)
{
    Can_Drv_EccIntHandler(5U);
    EXIT_INTERRUPT();
}

    #endif
#endif
#if (CAN_DRV_TOTAL_NUM > 6)
#if (STD_ON == CAN_DRV_6_ENABLE)
/**
 * @brief  Can 6 bus off interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_6_BusOffIrqHandler)
{
    Can_Drv_BusOffIntHandler(6U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 6 error interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_6_ErrIrqHandler)
{
    Can_Drv_ErrorIntHandler(6U);
    EXIT_INTERRUPT();
}

#if (CAN_DRV_FD_CH6_ENABLE == STD_ON)
/**
 * @brief  Can 6 error fd interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_6_ErrFdIrqHandler)
{
    Can_Drv_FdErrorIntHandler(6U);
    EXIT_INTERRUPT();
}
#endif

/**
 * @brief  Can 6 MB0TO31 interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_6_Mb0To31IrqHandler)
{
    Can_Drv_IntHandler(6U, 0U, 31U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 6 MB32TO63 interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_6_Mb32To63IrqHandler)
{
    Can_Drv_IntHandler(6U, 32U, 63U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 6 MB64TO95 interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_6_Mb64To95IrqHandler)
{
    Can_Drv_IntHandler(6U, 64U, 95U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 6 MB96TO127 interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_6_Mb96To127IrqHandler)
{
    Can_Drv_IntHandler(6U, 96U, 127U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 6 TX warn interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_6_TxWarnIrqHandler)
{
    Can_Drv_TxWarnIntHandler(6U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 6 RX warn interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_6_RxWarnIrqHandler)
{
    Can_Drv_RxWarnIntHandler(6U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 6 self wakeup interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_6_SelfWakeupIrqHandler)
{
    Can_Drv_WakeUpIntHandler(6U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 6 ecc interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_6_EccIrqHandler)
{
    Can_Drv_EccIntHandler(6U);
    EXIT_INTERRUPT();
}

#endif

#if (STD_ON == CAN_DRV_7_ENABLE)
/**
 * @brief  Can 7 bus off interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_7_BusOffIrqHandler)
{
    Can_Drv_BusOffIntHandler(7U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 7 error interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_7_ErrIrqHandler)
{
    Can_Drv_ErrorIntHandler(7U);
    EXIT_INTERRUPT();
}

#if (CAN_DRV_FD_CH7_ENABLE == STD_ON)
/**
 * @brief  Can 7 error fd interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_7_ErrFdIrqHandler)
{
    Can_Drv_FdErrorIntHandler(7U);
    EXIT_INTERRUPT();
}
#endif

/**
 * @brief  Can 7 MB0TO31 interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_7_Mb0To31IrqHandler)
{
    Can_Drv_IntHandler(7U, 0U, 31U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 7 MB32TO63 interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_7_Mb32To63IrqHandler)
{
    Can_Drv_IntHandler(7U, 32U, 63U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 7 MB64TO95 interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_7_Mb64To95IrqHandler)
{
    Can_Drv_IntHandler(7U, 64U, 95U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 7 MB96TO127 interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_7_Mb96To127IrqHandler)
{
    Can_Drv_IntHandler(7U, 96U, 127U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 7 TX warn interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_7_TxWarnIrqHandler)
{
    Can_Drv_TxWarnIntHandler(7U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 7 RX warn interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_7_RxWarnIrqHandler)
{
    Can_Drv_RxWarnIntHandler(7U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 7 self wakeup interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_7_SelfWakeupIrqHandler)
{
    Can_Drv_WakeUpIntHandler(7U);
    EXIT_INTERRUPT();
}

/**
 * @brief  Can 7 ecc interrupt handler.
 *
 * @param  None
 *
 * @return None
 *
 */
ISR(Can_Drv_7_EccIrqHandler)
{
    Can_Drv_EccIntHandler(7U);
    EXIT_INTERRUPT();
}

#endif
#endif

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Can_Drv */

/** @} end of group Can_Module */
