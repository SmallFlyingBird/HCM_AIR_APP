/**************************************************************************************************/
/**
 * @file      : Uart_Drv_Irq.c
 * @brief     : Lin low level driver interrupt source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Lin_Module
 *  @{
 */

/** @addtogroup Uart_Drv
 *  @brief Uart low level driver
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "CpuLoad.h"
#include "Uart_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
/* Published information */
#define UART_DRV_IRQ_C_VENDOR_ID                   0x00B3U
#define UART_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION    4U
#define UART_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION    6U
#define UART_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION 0U
#define UART_DRV_IRQ_C_SW_MAJOR_VERSION            1U
#define UART_DRV_IRQ_C_SW_MINOR_VERSION            2U
#define UART_DRV_IRQ_C_SW_PATCH_VERSION            2U

#if (UART_DRV_IRQ_C_VENDOR_ID != UART_DRV_H_VENDOR_ID)
#error "Vendor ID of Uart_Drv_Irq.c and Uart_Drv.h are different"
#endif

/* Check if  source file and Ocu_Drv_Irq.h file are of the same Autosar version */
#if ((UART_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION != UART_DRV_H_AR_RELEASE_MAJOR_VERSION) ||           \
     (UART_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION != UART_DRV_H_AR_RELEASE_MINOR_VERSION) ||           \
     (UART_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION != UART_DRV_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Uart_Drv_Irq.c and Uart_Drv.h are different"
#endif

/* Check if source file and Ocu_Drv_Irq.h file are of the same Software version */
#if ((UART_DRV_IRQ_C_SW_MAJOR_VERSION != UART_DRV_H_SW_MAJOR_VERSION) ||                           \
     (UART_DRV_IRQ_C_SW_MINOR_VERSION != UART_DRV_H_SW_MINOR_VERSION) ||                           \
     (UART_DRV_IRQ_C_SW_PATCH_VERSION != UART_DRV_H_SW_PATCH_VERSION))
#error "Software Version of Uart_Drv_Irq.c and Uart_Drv.h are different"
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

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"

#if (UART_DRV_0_ENABLE == STD_ON)
ISR(Uart_Drv_0_IrqHandler);
#endif /* (UART_DRV_0_ENABLE == STD_ON) */

#if (UART_DRV_1_ENABLE == STD_ON)
ISR(Uart_Drv_1_IrqHandler);
#endif /* (UART_DRV_1_ENABLE == STD_ON) */

#if (UART_DRV_2_ENABLE == STD_ON)
ISR(Uart_Drv_2_IrqHandler);
#endif /* (UART_DRV_2_ENABLE == STD_ON) */

#if (UART_DRV_3_ENABLE == STD_ON)
ISR(Uart_Drv_3_IrqHandler);
#endif /* (UART_DRV_3_ENABLE == STD_ON) */

#if (UART_DRV_4_ENABLE == STD_ON)
ISR(Uart_Drv_4_IrqHandler);
#endif /* (UART_DRV_4_ENABLE == STD_ON) */

#if (UART_DRV_5_ENABLE == STD_ON)
ISR(Uart_Drv_5_IrqHandler);
#endif /* (UART_DRV_5_ENABLE == STD_ON) */

#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
/** @} end of group Public_FunctionDeclaration */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"

/**
 *
 * @brief  Uart 0 interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
#if (UART_DRV_0_ENABLE == STD_ON)
ISR(Uart_Drv_0_IrqHandler)
{
    Uart_Drv_IntHandler(0U);

    EXIT_INTERRUPT();
}
#endif /* (UART_DRV_0_ENABLE == STD_ON) */

/**
 *
 * @brief  Uart 1 interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
 #if (UART_DRV_1_ENABLE == STD_ON)
ISR(Uart_Drv_1_IrqHandler)
{
    Uart_Drv_IntHandler(1U);

    EXIT_INTERRUPT();
}
#endif /* if (UART_DRV_1_ENABLE == STD_ON) */

/**
 *
 * @brief  Uart 2 interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
#if (UART_DRV_2_ENABLE == STD_ON)
ISR(Uart_Drv_2_IrqHandler)
{
    Uart_Drv_IntHandler(2U);

    EXIT_INTERRUPT();
}
#endif /* if (UART_DRV_2_ENABLE == STD_ON) */

/**
 *
 * @brief  Uart 3 interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
#if (UART_DRV_3_ENABLE == STD_ON)
ISR(Uart_Drv_3_IrqHandler)
{
	CpuLoad_EntryTime(CpuLoad_Index_Uart_Drv_3_Irq);

    Uart_Drv_IntHandler(3U);

    EXIT_INTERRUPT();
	
	CpuLoad_ExitTime(CpuLoad_Index_Uart_Drv_3_Irq);
}
#endif /* if (UART_DRV_3_ENABLE == STD_ON) */

/**
 *
 * @brief  Uart 4 interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
#if (UART_DRV_4_ENABLE == STD_ON)
ISR(Uart_Drv_4_IrqHandler)
{
    Uart_Drv_IntHandler(4U);

    EXIT_INTERRUPT();
}
#endif /* if (UART_DRV_4_ENABLE == STD_ON) */

/**
 *
 * @brief  Uart 5 interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
#if (UART_DRV_5_ENABLE == STD_ON)
ISR(Uart_Drv_5_IrqHandler)
{
    Uart_Drv_IntHandler(5U);

    EXIT_INTERRUPT();
}
#endif /* if (UART_DRV_5_ENABLE == STD_ON) */

#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Uart_Drv */

/** @} end of group Lin_Module */
