/**************************************************************************************************/
/**
 * @file      : Spi_Drv_Irq.c
 * @brief     : Spi low level driver interrupt source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Spi_Module
 *  @{
 */

/** @addtogroup Spi_Drv
 *  @brief Spi low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Spi_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define SPI_DRV_IRQ_C_VENDOR_ID                   0x00B3U
#define SPI_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION    4U
#define SPI_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION    6U
#define SPI_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION 0U
#define SPI_DRV_IRQ_C_SW_MAJOR_VERSION            1U
#define SPI_DRV_IRQ_C_SW_MINOR_VERSION            2U
#define SPI_DRV_IRQ_C_SW_PATCH_VERSION            1U

/* Check if current file and Spi_Drv.h are the same vendor */
#if (SPI_DRV_IRQ_C_VENDOR_ID != SPI_DRV_H_VENDOR_ID)
    #error "Vendor ID of Spi_Drv_Irq.c and Spi_Drv.h are different"
#endif
/* Check if current file and Spi_Drv.h are the same Autosar version */
#if ((SPI_DRV_IRQ_C_AR_RELEASE_MAJOR_VERSION != SPI_DRV_H_AR_RELEASE_MAJOR_VERSION) ||             \
     (SPI_DRV_IRQ_C_AR_RELEASE_MINOR_VERSION != SPI_DRV_H_AR_RELEASE_MINOR_VERSION) ||             \
     (SPI_DRV_IRQ_C_AR_RELEASE_REVISION_VERSION != SPI_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Spi_Drv_Irq.c and Spi_Drv.h are different"
#endif
/* Check if current file and Spi_Drv.h are the same Software version */
#if ((SPI_DRV_IRQ_C_SW_MAJOR_VERSION != SPI_DRV_H_SW_MAJOR_VERSION) ||                             \
     (SPI_DRV_IRQ_C_SW_MINOR_VERSION != SPI_DRV_H_SW_MINOR_VERSION) ||                             \
     (SPI_DRV_IRQ_C_SW_PATCH_VERSION != SPI_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Spi_Drv_Irq.c and Spi_Drv.h are different"
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
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

#if (SPI_DRV_0_ENABLE == STD_ON)
ISR(Spi_Drv_0_TxeIrqHandler);
ISR(Spi_Drv_0_TxoIrqHandler);
ISR(Spi_Drv_0_RxfIrqHandler);
ISR(Spi_Drv_0_RxoIrqHandler);
ISR(Spi_Drv_0_RxuIrqHandler);
void Spi_Drv_0_DmaTxIrqHandler(void);
void Spi_Drv_0_DmaRxIrqHandler(void);
#endif /* (SPI_DRV_0_ENABLE == STD_ON) */

#if (SPI_DRV_1_ENABLE == STD_ON)
ISR(Spi_Drv_1_TxeIrqHandler);
ISR(Spi_Drv_1_TxoIrqHandler);
ISR(Spi_Drv_1_RxfIrqHandler);
ISR(Spi_Drv_1_RxoIrqHandler);
ISR(Spi_Drv_1_RxuIrqHandler);
    #if (SPI_DRV_DMA_USED == STD_ON)
void Spi_Drv_1_DmaTxIrqHandler(void);
void Spi_Drv_1_DmaRxIrqHandler(void);
    #endif /* (SPI_DRV_DMA_USED == STD_ON) */
#endif     /* (SPI_DRV_1_ENABLE == STD_ON) */

#if (SPI_DRV_2_ENABLE == STD_ON)
ISR(Spi_Drv_2_TxeIrqHandler);
ISR(Spi_Drv_2_TxoIrqHandler);
ISR(Spi_Drv_2_RxfIrqHandler);
ISR(Spi_Drv_2_RxoIrqHandler);
ISR(Spi_Drv_2_RxuIrqHandler);
    #if (SPI_DRV_DMA_USED == STD_ON)
void Spi_Drv_2_DmaTxIrqHandler(void);
void Spi_Drv_2_DmaRxIrqHandler(void);
    #endif /* (SPI_DRV_DMA_USED == STD_ON) */
#endif /* (SPI_DRV_2_ENABLE == STD_ON) */

#if (SPI_DRV_3_ENABLE == STD_ON)
ISR(Spi_Drv_3_TxeIrqHandler);
ISR(Spi_Drv_3_TxoIrqHandler);
ISR(Spi_Drv_3_RxfIrqHandler);
ISR(Spi_Drv_3_RxoIrqHandler);
ISR(Spi_Drv_3_RxuIrqHandler);
    #if (SPI_DRV_DMA_USED == STD_ON)
void Spi_Drv_3_DmaTxIrqHandler(void);
void Spi_Drv_3_DmaRxIrqHandler(void);
    #endif /* (SPI_DRV_DMA_USED == STD_ON) */
#endif /* (SPI_DRV_3_ENABLE == STD_ON) */

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
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
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

#if (SPI_DRV_0_ENABLE == STD_ON)
/**
 * @brief     This function will process TX FIFO empty interrupt of SPI0.
 *
 * @return    None
 */
ISR(Spi_Drv_0_TxeIrqHandler)
{
    Spi_Drv_IntHandler(0u);
    EXIT_INTERRUPT();
}

/**
 * @brief     This function will process TX FIFO overflow interrupt of SPI0.
 *
 * @return    None
 */
ISR(Spi_Drv_0_TxoIrqHandler)
{
    Spi_Drv_IntHandler(0u);
    EXIT_INTERRUPT();
}

/**
 * @brief     This function will process RX FIFO full interrupt of SPI0.
 *
 * @return    None
 */
ISR(Spi_Drv_0_RxfIrqHandler)
{
    Spi_Drv_IntHandler(0u);
    EXIT_INTERRUPT();
}

/**
 * @brief     This function will process RX FIFO overflow interrupt of SPI0.
 *
 * @return    None
 */
ISR(Spi_Drv_0_RxoIrqHandler)
{
    Spi_Drv_IntHandler(0u);
    EXIT_INTERRUPT();
}

/**
 * @brief     This function will process RX FIFO underflow interrupt of SPI0.
 *
 * @return    None
 */
ISR(Spi_Drv_0_RxuIrqHandler)
{
    Spi_Drv_IntHandler(0u);
    EXIT_INTERRUPT();
}
    #if (SPI_DRV_DMA_USED == STD_ON)
/**
 * @brief     This function will process TX DMA transfer complete interrupt of SPI0.
 *
 * @return    None
 */
void Spi_Drv_0_DmaTxIrqHandler(void)
{
    Spi_Drv_DmaTxIntHandler(0u);
}

/**
 * @brief     This function will process RX DMA transfer complete interrupt of SPI0.
 *
 * @return    None
 */
void Spi_Drv_0_DmaRxIrqHandler(void)
{
    Spi_Drv_DmaRxIntHandler(0u);
}
    #endif /* (SPI_DRV_DMA_USED == STD_ON) */
#endif     /* (SPI_DRV_0_ENABLE == STD_ON) */

#if (SPI_DRV_1_ENABLE == STD_ON)
/**
 * @brief     This function will process TX FIFO empty interrupt of SPI1.
 *
 * @return    None
 */
ISR(Spi_Drv_1_TxeIrqHandler)
{
    Spi_Drv_IntHandler(1u);
    EXIT_INTERRUPT();
}

/**
 * @brief     This function will process TX FIFO overflow interrupt of SPI1.
 *
 * @return    None
 */
ISR(Spi_Drv_1_TxoIrqHandler)
{
    Spi_Drv_IntHandler(1u);
    EXIT_INTERRUPT();
}

/**
 * @brief     This function will process RX FIFO full interrupt of SPI1.
 *
 * @return    None
 */
ISR(Spi_Drv_1_RxfIrqHandler)
{
    Spi_Drv_IntHandler(1u);
    EXIT_INTERRUPT();
}

/**
 * @brief     This function will process RX FIFO overflow interrupt of SPI1.
 *
 * @return    None
 */
ISR(Spi_Drv_1_RxoIrqHandler)
{
    Spi_Drv_IntHandler(1u);
    EXIT_INTERRUPT();
}

/**
 * @brief     This function will process RX FIFO underflow interrupt of SPI1.
 *
 * @return    None
 */
ISR(Spi_Drv_1_RxuIrqHandler)
{
    Spi_Drv_IntHandler(1u);
    EXIT_INTERRUPT();
}
    #if (SPI_DRV_DMA_USED == STD_ON)
/**
 * @brief     This function will process TX DMA transfer complete interrupt of SPI1.
 *
 * @return    None
 */
void Spi_Drv_1_DmaTxIrqHandler(void)
{
    Spi_Drv_DmaTxIntHandler(1u);
}

/**
 * @brief     This function will process RX DMA transfer complete interrupt of SPI1.
 *
 * @return    None
 */
void Spi_Drv_1_DmaRxIrqHandler(void)
{
    Spi_Drv_DmaRxIntHandler(1u);
}
    #endif /* (SPI_DRV_DMA_USED == STD_ON) */
#endif     /* (SPI_DRV_1_ENABLE == STD_ON) */

#if (SPI_DRV_2_ENABLE == STD_ON)
/**
 * @brief     This function will process TX FIFO empty interrupt of SPI2.
 *
 * @return    None
 */
ISR(Spi_Drv_2_TxeIrqHandler)
{
    Spi_Drv_IntHandler(2u);
    EXIT_INTERRUPT();
}

/**
 * @brief     This function will process TX FIFO overflow interrupt of SPI2.
 *
 * @return    None
 */
ISR(Spi_Drv_2_TxoIrqHandler)
{
    Spi_Drv_IntHandler(2u);
    EXIT_INTERRUPT();
}

/**
 * @brief     This function will process RX FIFO full interrupt of SPI2.
 *
 * @return    None
 */
ISR(Spi_Drv_2_RxfIrqHandler)
{
    Spi_Drv_IntHandler(2u);
    EXIT_INTERRUPT();
}

/**
 * @brief     This function will process RX FIFO overflow interrupt of SPI2.
 *
 * @return    None
 */
ISR(Spi_Drv_2_RxoIrqHandler)
{
    Spi_Drv_IntHandler(2u);
    EXIT_INTERRUPT();
}

/**
 * @brief     This function will process RX FIFO underflow interrupt of SPI2.
 *
 * @return    None
 */
ISR(Spi_Drv_2_RxuIrqHandler)
{
    Spi_Drv_IntHandler(2u);
    EXIT_INTERRUPT();
}
    #if (SPI_DRV_DMA_USED == STD_ON)
/**
 * @brief     This function will process TX DMA transfer complete interrupt of SPI2.
 *
 * @return    None
 */
void Spi_Drv_2_DmaTxIrqHandler(void)
{
    Spi_Drv_DmaTxIntHandler(2u);
}

/**
 * @brief     This function will process RX DMA transfer complete interrupt of SPI2.
 *
 * @return    None
 */
void Spi_Drv_2_DmaRxIrqHandler(void)
{
    Spi_Drv_DmaRxIntHandler(2u);
}
    #endif /* (SPI_DRV_DMA_USED == STD_ON) */
#endif     /* (SPI_DRV_2_ENABLE == STD_ON) */

#if (SPI_DRV_3_ENABLE == STD_ON)
/**
 * @brief     This function will process TX FIFO empty interrupt of SPI3.
 *
 * @return    None
 */
ISR(Spi_Drv_3_TxeIrqHandler)
{
    Spi_Drv_IntHandler(3u);
    EXIT_INTERRUPT();
}

/**
 * @brief     This function will process TX FIFO overflow interrupt of SPI3.
 *
 * @return    None
 */
ISR(Spi_Drv_3_TxoIrqHandler)
{
    Spi_Drv_IntHandler(3u);
    EXIT_INTERRUPT();
}

/**
 * @brief     This function will process RX FIFO full interrupt of SPI3.
 *
 * @return    None
 */
ISR(Spi_Drv_3_RxfIrqHandler)
{
    Spi_Drv_IntHandler(3u);
    EXIT_INTERRUPT();
}

/**
 * @brief     This function will process RX FIFO overflow interrupt of SPI3.
 *
 * @return    None
 */
ISR(Spi_Drv_3_RxoIrqHandler)
{
    Spi_Drv_IntHandler(3u);
    EXIT_INTERRUPT();
}

/**
 * @brief     This function will process RX FIFO underflow interrupt of SPI3.
 *
 * @return    None
 */
ISR(Spi_Drv_3_RxuIrqHandler)
{
    Spi_Drv_IntHandler(3u);
    EXIT_INTERRUPT();
}
    #if (SPI_DRV_DMA_USED == STD_ON)
/**
 * @brief     This function will process TX DMA transfer complete interrupt of SPI3.
 *
 * @return    None
 */
void Spi_Drv_3_DmaTxIrqHandler(void)
{
    Spi_Drv_DmaTxIntHandler(3u);
}

/**
 * @brief     This function will process RX DMA transfer complete interrupt of SPI3.
 *
 * @return    None
 */
void Spi_Drv_3_DmaRxIrqHandler(void)
{
    Spi_Drv_DmaRxIntHandler(3u);
}
    #endif /* (SPI_DRV_DMA_USED == STD_ON) */
#endif     /* (SPI_DRV_3_ENABLE == STD_ON) */

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Spi_Drv */

/** @} end of group Spi_Module */
