/**************************************************************************************************/
/**
 * @file      : Dma_Drv_Irq.c
 * @brief     : AUTOSAR dma driver source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup  Dma_Module
 *  @{
 */

/** @addtogroup  Dma_Drv_Irq
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Dma_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define DMA_DRV_IRQ_C_VENDOR_ID                   0x00B3U
#define DMA_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION    4U
#define DMA_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION    6U
#define DMA_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION 0U
#define DMA_DRV_IRQ_C_SW_MAJOR_VERSION            1U
#define DMA_DRV_IRQ_C_SW_MINOR_VERSION            2U
#define DMA_DRV_IRQ_C_SW_PATCH_VERSION            1U


#if (DMA_DRV_IRQ_C_VENDOR_ID != DMA_DRV_H_VENDOR_ID)
    #error "Vendor ID of Dma_Drv_Irq.c and Dma_Drv.h are different"
#endif
             
#if ((DMA_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION != DMA_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
    (DMA_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION != DMA_DRV_H_AR_RELEASE_MINOR_VERSION) || \
    (DMA_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION != DMA_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar version of Dma_Drv_Irq.c and Dma_Drv.h are different"
#endif
             
#if ((DMA_DRV_IRQ_C_SW_MAJOR_VERSION != DMA_DRV_H_SW_MAJOR_VERSION) || \
    (DMA_DRV_IRQ_C_SW_MINOR_VERSION != DMA_DRV_H_SW_MINOR_VERSION) || \
    (DMA_DRV_IRQ_C_SW_PATCH_VERSION != DMA_DRV_H_SW_PATCH_VERSION))
    #error "Software version of Dma_Drv_Irq.c and Dma_Drv.h are different"
#endif


/** @} end of group Private_MacroDefinition */

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
#define DMA_START_SEC_CODE
#include "Dma_MemMap.h"

#if (DMA_DRV_CH_0_ENABLE==STD_ON)
ISR(Dma_Drv_Ch0IrqHandler);
#endif

#if (DMA_DRV_CH_1_ENABLE==STD_ON)
ISR(Dma_Drv_Ch1IrqHandler);
#endif

#if (DMA_DRV_CH_2_ENABLE==STD_ON)
ISR(Dma_Drv_Ch2IrqHandler);
#endif

#if (DMA_DRV_CH_3_ENABLE==STD_ON)
ISR(Dma_Drv_Ch3IrqHandler);
#endif

#if (DMA_DRV_CH_4_ENABLE==STD_ON)
ISR(Dma_Drv_Ch4IrqHandler);
#endif

#if (DMA_DRV_CH_5_ENABLE==STD_ON)
ISR(Dma_Drv_Ch5IrqHandler);
#endif

#if (DMA_DRV_CH_6_ENABLE==STD_ON)
ISR(Dma_Drv_Ch6IrqHandler);
#endif

#if (DMA_DRV_CH_7_ENABLE==STD_ON)
ISR(Dma_Drv_Ch7IrqHandler);
#endif

#if (DMA_DRV_CH_8_ENABLE==STD_ON)
ISR(Dma_Drv_Ch8IrqHandler);
#endif

#if (DMA_DRV_CH_9_ENABLE==STD_ON)
ISR(Dma_Drv_Ch9IrqHandler);
#endif

#if (DMA_DRV_CH_10_ENABLE==STD_ON)
ISR(Dma_Drv_Ch10IrqHandler);
#endif

#if (DMA_DRV_CH_11_ENABLE==STD_ON)
ISR(Dma_Drv_Ch11IrqHandler);
#endif

#if (DMA_DRV_CH_12_ENABLE==STD_ON)
ISR(Dma_Drv_Ch12IrqHandler);
#endif

#if (DMA_DRV_CH_13_ENABLE==STD_ON)
ISR(Dma_Drv_Ch13IrqHandler);
#endif

#if (DMA_DRV_CH_14_ENABLE==STD_ON)
ISR(Dma_Drv_Ch14IrqHandler);
#endif

#if (DMA_DRV_CH_15_ENABLE==STD_ON)
ISR(Dma_Drv_Ch15IrqHandler);
#endif

#if(DMA_DRV_PHYS_CH_USED == STD_ON)
ISR(Dma_Drv_ErrIrqHandler);
#endif

#define DMA_STOP_SEC_CODE
#include "Dma_MemMap.h"
/** @} end of group Private_FunctionDeclaration */


/** @defgroup Private_FunctionDefinition
 *  @{
 */

/** @} end of group Private_FunctionDefinition */


/** @defgroup Public_FunctionDefinition
 *  @{
 */
#define DMA_START_SEC_CODE
#include "Dma_MemMap.h"

/**
 * @brief  DMA channel 0 interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
#if (DMA_DRV_CH_0_ENABLE==STD_ON)
ISR(Dma_Drv_Ch0IrqHandler)
{
    Dma_Drv_DoneIntHandler(DMA_DRV_PHYS_CH_0);
    EXIT_INTERRUPT();
}
#endif

/**
 * @brief  DMA channel 1 interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
#if (DMA_DRV_CH_1_ENABLE==STD_ON)
ISR(Dma_Drv_Ch1IrqHandler)
{
    Dma_Drv_DoneIntHandler(DMA_DRV_PHYS_CH_1);
    EXIT_INTERRUPT();
}
#endif
/**
 * @brief  DMA channel 2 interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
#if (DMA_DRV_CH_2_ENABLE==STD_ON)
ISR(Dma_Drv_Ch2IrqHandler)
{
    Dma_Drv_DoneIntHandler(DMA_DRV_PHYS_CH_2);
    EXIT_INTERRUPT();
}
#endif
/**
 * @brief  DMA channel 3 interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
#if (DMA_DRV_CH_3_ENABLE==STD_ON)
ISR(Dma_Drv_Ch3IrqHandler)
{
    Dma_Drv_DoneIntHandler(DMA_DRV_PHYS_CH_3);
    EXIT_INTERRUPT();
}
#endif
/**
 * @brief  DMA channel 4 interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
#if (DMA_DRV_CH_4_ENABLE==STD_ON)
ISR(Dma_Drv_Ch4IrqHandler)
{
    Dma_Drv_DoneIntHandler(DMA_DRV_PHYS_CH_4);
    EXIT_INTERRUPT();
}
#endif
/**
 * @brief  DMA channel 5 interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
#if (DMA_DRV_CH_5_ENABLE==STD_ON)
ISR(Dma_Drv_Ch5IrqHandler)
{
    Dma_Drv_DoneIntHandler(DMA_DRV_PHYS_CH_5);
    EXIT_INTERRUPT();
}
#endif
/**
 * @brief  DMA channel 6 interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
#if (DMA_DRV_CH_6_ENABLE==STD_ON)
ISR(Dma_Drv_Ch6IrqHandler)
{
    Dma_Drv_DoneIntHandler(DMA_DRV_PHYS_CH_6);
    EXIT_INTERRUPT();
}
#endif
/**
 * @brief  DMA channel 7 interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
#if (DMA_DRV_CH_7_ENABLE==STD_ON)
ISR(Dma_Drv_Ch7IrqHandler)
{
    Dma_Drv_DoneIntHandler(DMA_DRV_PHYS_CH_7);
    EXIT_INTERRUPT();
}
#endif
/**
 * @brief  DMA channel 8 interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
#if (DMA_DRV_CH_8_ENABLE==STD_ON)
ISR(Dma_Drv_Ch8IrqHandler)
{
    Dma_Drv_DoneIntHandler(DMA_DRV_PHYS_CH_8);
    EXIT_INTERRUPT();
}
#endif
/**
 * @brief  DMA channel 9 interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
#if (DMA_DRV_CH_9_ENABLE==STD_ON)
ISR(Dma_Drv_Ch9IrqHandler)
{
    Dma_Drv_DoneIntHandler(DMA_DRV_PHYS_CH_9);
    EXIT_INTERRUPT();
}
#endif
/**
 * @brief  DMA channel 10 interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
#if (DMA_DRV_CH_10_ENABLE==STD_ON)
ISR(Dma_Drv_Ch10IrqHandler)
{
    Dma_Drv_DoneIntHandler(DMA_DRV_PHYS_CH_10);
    EXIT_INTERRUPT();
}
#endif
/**
 * @brief  DMA channel 11 interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
#if (DMA_DRV_CH_11_ENABLE==STD_ON)
ISR(Dma_Drv_Ch11IrqHandler)
{
    Dma_Drv_DoneIntHandler(DMA_DRV_PHYS_CH_11);
    EXIT_INTERRUPT();
}
#endif
/**
 * @brief  DMA channel 12 interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
#if (DMA_DRV_CH_12_ENABLE==STD_ON)
ISR(Dma_Drv_Ch12IrqHandler)
{
    Dma_Drv_DoneIntHandler(DMA_DRV_PHYS_CH_12);
    EXIT_INTERRUPT();
}
#endif
/**
 * @brief  DMA channel 13 interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
#if (DMA_DRV_CH_13_ENABLE==STD_ON)
ISR(Dma_Drv_Ch13IrqHandler)
{
    Dma_Drv_DoneIntHandler(DMA_DRV_PHYS_CH_13);
    EXIT_INTERRUPT();
}
#endif
/**
 * @brief  DMA channel 14 interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
#if (DMA_DRV_CH_14_ENABLE == STD_ON)
ISR(Dma_Drv_Ch14IrqHandler)
{
    Dma_Drv_DoneIntHandler(DMA_DRV_PHYS_CH_14);
    EXIT_INTERRUPT();
}
#endif
/**
 * @brief  DMA channel 15 interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
#if (DMA_DRV_CH_15_ENABLE == STD_ON)
ISR(Dma_Drv_Ch15IrqHandler)
{
    Dma_Drv_DoneIntHandler(DMA_DRV_PHYS_CH_15);
    EXIT_INTERRUPT();
}
#endif
/**
 * @brief  DMA error interrupt function
 *
 * @param  none
 *
 * @return none
 *
 */
#if(DMA_DRV_PHYS_CH_USED == STD_ON)
ISR(Dma_Drv_ErrIrqHandler)
{
    Dma_Drv_ErrorIntHandler();
    EXIT_INTERRUPT();
}
#endif

#define DMA_STOP_SEC_CODE
#include "Dma_MemMap.h"

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Dma_Drv */
/** @} end of group Dma_Module */


