/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Os_Processor.h>
 *  @brief      <>
 *
 * <Compiler: S32K    MCU:S32K344>
 *
 *  @author     <jiansen.zhao>
 *  @date       <04-01-2022>
 */
/*============================================================================*/
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>        <AUTHOR>         <REVISION LOG>
 *  V0.1.0      2021070705   jiansen.zhao      Initial version
 */
/*============================================================================*/
#ifndef OS_PROCESSOR_H
#define OS_PROCESSOR_H

/*=======[M I S R A C  R U L E  V I O L A T I O N]============================*/
/*  <MESSAGE ID>    <CODE LINE>    <REASON>
 */
/*============================================================================*/

/*=======[V E R S I O N  I N F O R M A T I O N]===============================*/
#define OS_PROCESSOR_H_VENDOR_ID        62
#define OS_PROCESSOR_H_MODULE_ID        1
#define OS_PROCESSOR_H_AR_MAJOR_VERSION 4
#define OS_PROCESSOR_H_AR_MINOR_VERSION 5
#define OS_PROCESSOR_H_AR_PATCH_VERSION 0
#define OS_PROCESSOR_H_SW_MAJOR_VERSION 0
#define OS_PROCESSOR_H_SW_MINOR_VERSION 1
#define OS_PROCESSOR_H_SW_PATCH_VERSION 0
#define OS_PROCESSOR_H_VENDOR_API_INFIX 0

/*=======[I N C L U D E S]====================================================*/
#include "Os.h"
#include "Os_Mpu.h"
#include "smpu_drv_os.h"
#include "Z20K148M.h"
/*---------------------------------Compiler OS--------------------------------*/
#define OS_REG32(address) (*(volatile uint32*)(address)) /* 32-bit register */
#define OS_REG8(address)  (*(volatile uint8*)(address))  /*  8-bit register */

/*-----------------------------S32K3XX Register-------------------------------*/
/* Interrupt Service Provider */
#define OS_ARCH_INT_CPU0 (0x00000000u)

/*=======[Register Address]======================================================*/

#ifndef false
#define false (0U)
#endif

#ifndef true
#define true (1U)
#endif

/* Nested Vectored Interrupt Controller(NVIC) */
#define SYS_EXCEPTION_NUM               (16u)
#define OS_NVIC_NUM      (240u)
/* Core interrupts */
#define OS_INITSTACK_IRQn                   (0u)
#define OS_RESET_IRQn                       (1u)
#define OS_NonMaskableInt_IRQn              (2u)                               /**< Non Maskable Interrupt */
#define OS_HardFault_IRQn                   (3u)                               /**< Cortex-M7 SV Hard Fault Interrupt */
#define OS_MemoryManagement_IRQn            (4u)                               /**< Cortex-M7 Memory Management Interrupt */
#define OS_BusFault_IRQn                    (5u)                               /**< Cortex-M7 Bus Fault Interrupt */
#define OS_UsageFault_IRQn                  (6u)                               /**< Cortex-M7 Usage Fault Interrupt */
#define OS_SVCall_IRQn                      (11u)                              /**< Cortex-M7 SV Call Interrupt */
#define OS_DebugMonitor_IRQn                (12u)                              /**< Cortex-M7 Debug Monitor Interrupt */
#define OS_PendSV_IRQn                      (14u)                              /**< Cortex-M7 Pend SV Interrupt */
#define OS_SysTick_IRQn                     (15u)                              /**< Cortex-M7 System Tick Interrupt */
/* Device specific interrupts id */
#define OS_DMA_CH0_TX_COMPLETE_IRQn     (SYS_EXCEPTION_NUM+0u)  /* DMA channel 0 transfer complete */
#define OS_DMA_CH1_TX_COMPLETE_IRQn     (SYS_EXCEPTION_NUM+1u)  /* DMA channel 1 transfer complete */
#define OS_DMA_CH2_TX_COMPLETE_IRQn     (SYS_EXCEPTION_NUM+2u)  /* DMA channel 2 transfer complete */
#define OS_DMA_CH3_TX_COMPLETE_IRQn     (SYS_EXCEPTION_NUM+3u)  /* DMA channel 3 transfer complete */
#define OS_DMA_CH4_TX_COMPLETE_IRQn     (SYS_EXCEPTION_NUM+4u)  /* DMA channel 4 transfer complete */
#define OS_DMA_CH5_TX_COMPLETE_IRQn     (SYS_EXCEPTION_NUM+5u)  /* DMA channel 5 transfer complete */
#define OS_DMA_CH6_TX_COMPLETE_IRQn     (SYS_EXCEPTION_NUM+6u)  /* DMA channel 6 transfer complete */
#define OS_DMA_CH7_TX_COMPLETE_IRQn     (SYS_EXCEPTION_NUM+7u)  /* DMA channel 7 transfer complete */
#define OS_DMA_CH8_TX_COMPLETE_IRQn     (SYS_EXCEPTION_NUM+8u)  /* DMA channel 8 transfer complete */
#define OS_DMA_CH9_TX_COMPLETE_IRQn     (SYS_EXCEPTION_NUM+9u)  /* DMA channel 9 transfer complete */
#define OS_DMA_CH10_TX_COMPLETE_IRQn    (SYS_EXCEPTION_NUM+10u)  /* DMA channel 10 transfer complete */
#define OS_DMA_CH11_TX_COMPLETE_IRQn    (SYS_EXCEPTION_NUM+11u)  /* DMA channel 11 transfer complete */
#define OS_DMA_CH12_TX_COMPLETE_IRQn    (SYS_EXCEPTION_NUM+12u)  /* DMA channel 12 transfer complete */
#define OS_DMA_CH13_TX_COMPLETE_IRQn    (SYS_EXCEPTION_NUM+13u)  /* DMA channel 13 transfer complete */
#define OS_DMA_CH14_TX_COMPLETE_IRQn    (SYS_EXCEPTION_NUM+14u)  /* DMA channel 14 transfer complete */
#define OS_DMA_CH15_TX_COMPLETE_IRQn    (SYS_EXCEPTION_NUM+15u)  /* DMA channel 15 transfer complete */
#define OS_DMA_ERROR_INTR_IRQn          (SYS_EXCEPTION_NUM+16u)  /* DMA channels 0-15 error interrupt */
#define OS_FLASH_CMD_COMPLETE_IRQn      (SYS_EXCEPTION_NUM+17u)  /* Command complete */
#define OS_FLASH_ECC_ERRPR_IRQn         (SYS_EXCEPTION_NUM+18u)  /* ECC error */
#define OS_PMU_LVD_LVW_IRQn             (SYS_EXCEPTION_NUM+19u)  /* LVD, LVW */
#define OS_WDG_IRQn                     (SYS_EXCEPTION_NUM+20u)  /* Watch dog */
#define OS_EXT_WDG_MONITOR_IRQn         (SYS_EXCEPTION_NUM+21u)  /* External watchdog monitor */
#define OS_SYS_RST_MODE_CTRL_IRQn       (SYS_EXCEPTION_NUM+22u)  /* System reset and mode control */
#define OS_I2C0_INTR_IRQn               (SYS_EXCEPTION_NUM+23u)  /* I2C0 Interrupt */
#define OS_I2C1_INTR_IRQn               (SYS_EXCEPTION_NUM+24u)  /* I2C1 Interrupt */
#define OS_SPI0_TXE_IRQn                (SYS_EXCEPTION_NUM+25u)  /* SPI0 txe Interrup */
#define OS_SPI0_TXO_IRQn                (SYS_EXCEPTION_NUM+26u)  /* SPI0 txo Interrupt */
#define OS_SPI0_RXF_IRQn                (SYS_EXCEPTION_NUM+27u)  /* SPI0 rxf Interrupt */
#define OS_SPI0_RXO_IRQn                (SYS_EXCEPTION_NUM+28u)  /* SPI0 rxo Interrupt */
#define OS_SPI0_RXU_IRQn                (SYS_EXCEPTION_NUM+29u)  /* SPI0 rxu Interrupt */
#define OS_RESERVED_30_IRQn             (SYS_EXCEPTION_NUM+30u)  /* Reserved */
#define OS_SPI1_TXE_IRQn                (SYS_EXCEPTION_NUM+31u)  /* SPI1 txe Interrupt */
#define OS_SPI1_TXO_IRQn                (SYS_EXCEPTION_NUM+32u)  /* SPI1 txo Interrup */
#define OS_SPI1_RXF_IRQn                (SYS_EXCEPTION_NUM+33u)  /* SPI1 rxf Interrup */
#define OS_SPI1_RXO_IRQn                (SYS_EXCEPTION_NUM+34u)  /* SPI1 rxo Interrupt */
#define OS_SPI1_RXU_IRQn                (SYS_EXCEPTION_NUM+35u)  /* SPI1 rxu Interrupt */
#define OS_RESERVED_36_IRQn             (SYS_EXCEPTION_NUM+36u)  /* Reserved */
#define OS_SPI2_TXE_IRQn                (SYS_EXCEPTION_NUM+37u)  /* SPI2 txe Interrupt */
#define OS_SPI2_TXO_IRQn                (SYS_EXCEPTION_NUM+38u)  /* SPI2 txo Interrupt */
#define OS_SPI2_RXF_IRQn                (SYS_EXCEPTION_NUM+39u)  /* SPI2 rxf Interrup */
#define OS_SPI2_RXO_IRQn                (SYS_EXCEPTION_NUM+40u)  /* SPI2 rxo Interrupt */
#define OS_SPI2_RXU_IRQn                (SYS_EXCEPTION_NUM+41u)  /* SPI2 rxu Interrupt */
#define OS_RESERVED_42_IRQn             (SYS_EXCEPTION_NUM+42u)  /* Reserved */
#define OS_SPI3_TXE_IRQn                (SYS_EXCEPTION_NUM+43u)  /* SPI3 txe Interrup */
#define OS_SPI3_TXO_IRQn                (SYS_EXCEPTION_NUM+44u)  /* SPI3 txo Interrupt */
#define OS_SPI3_RXF_IRQn                (SYS_EXCEPTION_NUM+45u)  /* SPI3 rxf Interrupt */
#define OS_SPI3_RXO_IRQn                (SYS_EXCEPTION_NUM+46u)  /* SPI3 rxo Interrupt */
#define OS_SPI3_RXU_IRQn                (SYS_EXCEPTION_NUM+47u)  /* SPI3 rxu Interrupt */
#define OS_RESERVED_48_IRQn             (SYS_EXCEPTION_NUM+48u)  /* Reserved */
#define OS_UART0_IRQn                   (SYS_EXCEPTION_NUM+49u)  /* UART0 Interrupt */
#define OS_UART1_IRQn                   (SYS_EXCEPTION_NUM+50u)  /* UART1 Interrupt */
#define OS_UART2_IRQn                   (SYS_EXCEPTION_NUM+51u)  /* UART2 Interrupt */
#define OS_UART3_IRQn                   (SYS_EXCEPTION_NUM+52u)  /* UART3 Interrupt */
#define OS_UART4_IRQn                   (SYS_EXCEPTION_NUM+53u)  /* UART4 Interrupt */
#define OS_UART5_IRQn                   (SYS_EXCEPTION_NUM+54u)  /* UART5 Interrupt */
#define OS_CAN0_BusOff_IRQn             (SYS_EXCEPTION_NUM+55u)  /* CAN 0 bus off */
#define OS_CAN0_TX_WARNING_IRQn         (SYS_EXCEPTION_NUM+56u)  /* CAN 0 tx warning */
#define OS_CAN0_RX_WARNING_IRQn         (SYS_EXCEPTION_NUM+57u)  /* CAN 0 rx warning */
#define OS_CAN0_ERROR_IRQn              (SYS_EXCEPTION_NUM+58u)  /* CAN 0 error Interrupt */
#define OS_CAN0_FD_ERROR_IRQn           (SYS_EXCEPTION_NUM+59u)  /* CAN 0 FD error Interrupt */
#define OS_CAN0_PRETENDED_WKUP_IRQn     (SYS_EXCEPTION_NUM+60u)  /* CAN 0 pretended network wakeup Interrupt */
#define OS_CAN0_SELF_WKUP_IRQn          (SYS_EXCEPTION_NUM+61u)  /* CAN 0 self-wakeup Interrupt */
#define OS_CAN0_ECC_IRQn                (SYS_EXCEPTION_NUM+62u)  /* CAN 0 ECC interrupt */
#define OS_CAN0_Mb0To15_IRQn            (SYS_EXCEPTION_NUM+63u)  /* CAN 0 Message buffer (0-15) */
#define OS_CAN0_Mb16To31_IRQn           (SYS_EXCEPTION_NUM+64u)  /* CAN 0 Message buffer (16-31) */
#define OS_CAN0_Mb32To47_IRQn           (SYS_EXCEPTION_NUM+65u)  /* CAN 0 Message buffer (32-47) */
#define OS_CAN0_Mb48To63_IRQn           (SYS_EXCEPTION_NUM+66u)  /* CAN 0 Message buffer (48-63) */
#define OS_CAN1_BUSOFF_IRQn             (SYS_EXCEPTION_NUM+67u)  /* CAN 1 bus off */
#define OS_CAN1_TX_WARNING_IRQn         (SYS_EXCEPTION_NUM+68u)  /* CAN 1 tx warning */
#define OS_CAN1_RX_WARNING_IRQn         (SYS_EXCEPTION_NUM+69u)  /* CAN 1 rx warnin */
#define OS_CAN1_ERROR_IRQn              (SYS_EXCEPTION_NUM+70u)  /* CAN 1 error Interrupt */
#define OS_CAN1_FD_ERROR_IRQn           (SYS_EXCEPTION_NUM+71u)  /* CAN 1 FD error Interrupt */
#define OS_CAN1_PRETENDED_WKUP_IRQn     (SYS_EXCEPTION_NUM+72u)  /* CAN 1 pretended network wakeup Interrupt */
#define OS_CAN1_SELF_WKUP_IRQn          (SYS_EXCEPTION_NUM+73u)  /* CAN 1 self-wakeup Interrupt */
#define OS_CAN1_ECC_IRQn                (SYS_EXCEPTION_NUM+74u)  /* CAN 1 ECC interrup */
#define OS_CAN1_MSG_0_15_IRQn           (SYS_EXCEPTION_NUM+75u)  /* CAN 1 Message buffer (0-15) */
#define OS_CAN1_MSG_16_31_IRQn          (SYS_EXCEPTION_NUM+76u)  /* CAN 1 Message buffer (16-31) */
#define OS_CAN1_MSG_32_47_IRQn          (SYS_EXCEPTION_NUM+77u)  /* CAN 1 Message buffer (32-47) */
#define OS_CAN1_MSG_48_63_IRQn          (SYS_EXCEPTION_NUM+78u)  /* CAN 1 Message buffer (48-63) */
#define OS_CAN2_BUSOFF_IRQn             (SYS_EXCEPTION_NUM+79u)  /* CAN 2 bus off */
#define OS_CAN2_TX_WARNING_IRQn         (SYS_EXCEPTION_NUM+80u)  /* CAN 2 tx warning */
#define OS_CAN2_RX_WARNING_IRQn         (SYS_EXCEPTION_NUM+81u)  /* CAN 2 rx warning */
#define OS_CAN2_ERROR_IRQn              (SYS_EXCEPTION_NUM+82u)  /* CAN 2 error Interrupt */
#define OS_CAN2_FD_ERROR_IRQn           (SYS_EXCEPTION_NUM+83u)  /*  CAN 2 FD error Interrupt */
#define OS_CAN2_PRETENDED_WKUP_IRQn     (SYS_EXCEPTION_NUM+84u)  /* CAN 2 pretended network wakeup Interrupt */
#define OS_CAN2_SELF_WKUP_IRQn          (SYS_EXCEPTION_NUM+85u)  /* CAN 2 self-wakeup Interrupt */
#define OS_CAN2_ECC_IRQn                (SYS_EXCEPTION_NUM+86u)  /* CAN 2 ECC interrupt */
#define OS_CAN2_MSG_0_15_IRQn           (SYS_EXCEPTION_NUM+87u)  /* CAN 2 Message buffer (0-15) */
#define OS_CAN2_MSG_16_31_IRQn          (SYS_EXCEPTION_NUM+88u)  /* CAN 2 Message buffer (16-31) */
#define OS_CAN2_MSG_32_47_IRQn          (SYS_EXCEPTION_NUM+89u)  /* CAN 2 Message buffer (32-47) */
#define OS_CAN2_MSG_48_63_IRQn          (SYS_EXCEPTION_NUM+90u)  /* CAN 2 Message buffer (48-63) */
#define OS_CAN3_BUSOFF_IRQn             (SYS_EXCEPTION_NUM+91u)  /* CAN 3 bus off */
#define OS_CAN3_TX_WARNING_IRQn         (SYS_EXCEPTION_NUM+92u)  /* CAN 3 tx warning */
#define OS_CAN3_RX_WARNING_IRQn         (SYS_EXCEPTION_NUM+93u)  /* CAN 3 rx warning */
#define OS_CAN3_ERROR_IRQn              (SYS_EXCEPTION_NUM+94u)  /* CAN 3 error Interrupt */
#define OS_CAN3_FD_ERROR_IRQn           (SYS_EXCEPTION_NUM+95u)  /* CAN 3 FD error Interrupt */
#define OS_CAN3_PRETENDED_WKUP_IRQn     (SYS_EXCEPTION_NUM+96u)  /* CAN 3 pretended network wakeup Interrupt */
#define OS_CAN3_SELF_WKUP_IRQn          (SYS_EXCEPTION_NUM+97u)  /* CAN 3 self-wakeup Interrupt */
#define OS_CAN3_ECC_IRQn                (SYS_EXCEPTION_NUM+98u)  /* CAN 3 ECC interrupt */
#define OS_CAN3_MSG_0_15_IRQn           (SYS_EXCEPTION_NUM+99u)  /* CAN 3 Message buffer (0-15) */
#define OS_CAN3_MSG_16_31_IRQn          (SYS_EXCEPTION_NUM+100u)  /* CAN 3 Message buffer (16-31) */
#define OS_CAN3_MSG_32_47_IRQn          (SYS_EXCEPTION_NUM+101u)  /* CAN 3 Message buffer (32-47) */
#define OS_CAN3_MSG_48_63_IRQn          (SYS_EXCEPTION_NUM+102u)  /* CAN 3 Message buffer (48-63) */
#define OS_CAN4_BUSOFF_IRQn             (SYS_EXCEPTION_NUM+103u)  /* CAN 4 bus off */
#define OS_CAN4_TX_WARNING_IRQn         (SYS_EXCEPTION_NUM+104u)  /* CAN 4 tx warning */
#define OS_CAN4_RX_WARNING_IRQn         (SYS_EXCEPTION_NUM+105u)  /* CAN 4 rx warning */
#define OS_CAN4_ERROR_IRQn              (SYS_EXCEPTION_NUM+106u)  /* CAN 4 error Interrupt */
#define OS_CAN4_FD_ERROR_IRQn           (SYS_EXCEPTION_NUM+107u)  /* CAN 4 FD error Interrupt */
#define OS_CAN4_PRETENDED_WKUP_IRQn     (SYS_EXCEPTION_NUM+108u)  /* CAN 4 pretended network wakeup Interrupt */
#define OS_CAN4_SELF_WKUP_IRQn          (SYS_EXCEPTION_NUM+109u)  /* CAN 4 self-wakeup Interrupt */
#define OS_CAN4_ECC_IRQn                (SYS_EXCEPTION_NUM+110u)  /* CAN 4 ECC interrupt */
#define OS_CAN4_MSG_0_15_IRQn           (SYS_EXCEPTION_NUM+111u)  /* CAN 4 Message buffer (0-15) */
#define OS_CAN4_MSG_16_31_IRQn          (SYS_EXCEPTION_NUM+112u)  /* CAN 4 Message buffer (16-31) */
#define OS_CAN4_MSG_32_47_IRQn          (SYS_EXCEPTION_NUM+113u)  /* CAN 4 Message buffer (32-47) */
#define OS_CAN4_MSG_48_63_IRQn          (SYS_EXCEPTION_NUM+114u)  /* CAN 4 Message buffer (48-63) */
#define OS_CAN5_BUSOFF_IRQn             (SYS_EXCEPTION_NUM+115u)  /* CAN 5 bus off */
#define OS_CAN5_TX_WARNING_IRQn         (SYS_EXCEPTION_NUM+116u)  /* CAN 5 tx warning */
#define OS_CAN5_RX_WARNING_IRQn         (SYS_EXCEPTION_NUM+117u)  /* CAN 5 rx warning */
#define OS_CAN5_ERROR_IRQn              (SYS_EXCEPTION_NUM+118u)  /* CAN 5 error Interrupt */
#define OS_CAN5_FD_ERROR_IRQn           (SYS_EXCEPTION_NUM+119u)  /* CAN 5 FD error Interrupt */
#define OS_CAN5_PRETENDED_WKUP_IRQn     (SYS_EXCEPTION_NUM+120u)  /* CAN 5 pretended network wakeup Interrupt */
#define OS_CAN5_SELF_WKUP_IRQn          (SYS_EXCEPTION_NUM+121u)  /* CAN 5 self-wakeup Interrupt */
#define OS_CAN5_ECC_IRQn                (SYS_EXCEPTION_NUM+122u)  /* CAN 5 ECC interrupt */
#define OS_CAN5_MSG_0_15_IRQn           (SYS_EXCEPTION_NUM+123u)  /* CAN 5 Message buffer (0-15) */
#define OS_CAN5_MSG_16_31_IRQn          (SYS_EXCEPTION_NUM+124u)  /* CAN 5 Message buffer (16-31) */
#define OS_CAN5_MSG_32_47_IRQn          (SYS_EXCEPTION_NUM+125u)  /* CAN 5 Message buffer (32-47) */
#define OS_CAN5_MSG_48_63_IRQn          (SYS_EXCEPTION_NUM+126u)  /* CAN 5 Message buffer (48-63) */
#define OS_CAN6_BUSOFF_IRQn             (SYS_EXCEPTION_NUM+127u)  /* CAN 6 bus off */
#define OS_CAN6_TX_WARNING_IRQn         (SYS_EXCEPTION_NUM+128u)  /* CAN 6 tx warning */
#define OS_CAN6_RX_WARNING_IRQn         (SYS_EXCEPTION_NUM+129u)  /* CAN 6 rx warning */
#define OS_CAN6_ERROR_IRQn              (SYS_EXCEPTION_NUM+130u)  /* CAN 6 error Interrupt */
#define OS_CAN6_FD_ERROR_IRQn           (SYS_EXCEPTION_NUM+131u)  /* CAN 6 FD error Interrupt */
#define OS_CAN6_PRETENDED_WKUP_IRQn     (SYS_EXCEPTION_NUM+132u)  /* CAN 6 pretended network wakeup Interrupt */
#define OS_CAN6_SELF_WKUP_IRQn          (SYS_EXCEPTION_NUM+133u)  /* CAN 6 self-wakeup Interrupt */
#define OS_CAN6_ECC_IRQn                (SYS_EXCEPTION_NUM+134u)  /* CAN 6 ECC interrupt */
#define OS_CAN6_MSG_0_31_IRQn           (SYS_EXCEPTION_NUM+135u)  /* CAN 6 Message buffer (0-31) */
#define OS_CAN6_MSG_32_63_IRQn          (SYS_EXCEPTION_NUM+136u)  /* CAN 6 Message buffer (32-63) */
#define OS_CAN6_MSG_64_95_IRQn          (SYS_EXCEPTION_NUM+137u)  /* CAN 6 Message buffer (64-95) */
#define OS_CAN6_MSG_96_127_IRQn         (SYS_EXCEPTION_NUM+138u)  /* CAN 6 Message buffer (96-127) */
#define OS_CAN7_BUSOFF_IRQn             (SYS_EXCEPTION_NUM+139u)  /* CAN 7 bus off */
#define OS_CAN7_TX_WARNING_IRQn         (SYS_EXCEPTION_NUM+140u)  /* CAN 7 tx warning */
#define OS_CAN7_RX_WARNING_IRQn         (SYS_EXCEPTION_NUM+141u)  /* CAN 7 rx warning */
#define OS_CAN7_ERROR_IRQn              (SYS_EXCEPTION_NUM+142u)  /* CAN 7 error Interrupt */
#define OS_CAN7_FD_ERROR_IRQn           (SYS_EXCEPTION_NUM+143u)  /* CAN 7 FD error Interrupt */
#define OS_CAN7_PRETENDED_WKUP_IRQn     (SYS_EXCEPTION_NUM+144u)  /* CAN 7 pretended network wakeup Interrupt */
#define OS_CAN7_SELF_WKUP_IRQn          (SYS_EXCEPTION_NUM+145u)  /* CAN 7 self-wakeup Interrupt */
#define OS_CAN7_ECC_IRQn                (SYS_EXCEPTION_NUM+146u)  /* CAN 7 ECC interrupt */
#define OS_CAN7_MSG_0_31_IRQn           (SYS_EXCEPTION_NUM+147u)  /* CAN 7 Message buffer (0-31) */
#define OS_CAN7_MSG_32_63_IRQn          (SYS_EXCEPTION_NUM+148u)  /* CAN 7 Message buffer (32-63) */
#define OS_CAN7_MSG_64_95_IRQn          (SYS_EXCEPTION_NUM+149u)  /* CAN 7 Message buffer (64-95) */
#define OS_CAN7_MSG_96_127_IRQn         (SYS_EXCEPTION_NUM+150u)  /* CAN 7 Message buffer (96-127) */
#define OS_RESERVED_151_IRQn            (SYS_EXCEPTION_NUM+151u)  /* Reserved */
#define OS_RESERVED_152_IRQn            (SYS_EXCEPTION_NUM+152u)  /* Reserved */
#define OS_RESERVED_153_IRQn            (SYS_EXCEPTION_NUM+153u)  /* Reserved */
#define OS_TIM0_IRQn                    (SYS_EXCEPTION_NUM+154u)  /* TIM0 channel interrupt */
#define OS_TIM0_FAULT_IRQn              (SYS_EXCEPTION_NUM+155u)  /* TIM0 fault interrupt */
#define OS_TIM0_OVF_IRQn                (SYS_EXCEPTION_NUM+156u)  /* TIM0 overflow interrupt */
#define OS_TIM0_RELOAD_IRQn             (SYS_EXCEPTION_NUM+157u)  /* TIM0 reload interrupt */
#define OS_TIM1_IRQn                    (SYS_EXCEPTION_NUM+158u)  /* TIM1 channel interrupt */
#define OS_TIM1_FAULT_IRQn              (SYS_EXCEPTION_NUM+159u)  /* TIM1 fault interrupt */
#define OS_TIM1_OVF_IRQn                (SYS_EXCEPTION_NUM+160u)  /* TIM1 overflow interrupt */
#define OS_TIM1_RELOAD_IRQn             (SYS_EXCEPTION_NUM+161u)  /* TIM1 reload interrupt */
#define OS_TIM2_IRQn                    (SYS_EXCEPTION_NUM+162u)  /* TIM2 channel interrupt */
#define OS_TIM2_FAULT_IRQn              (SYS_EXCEPTION_NUM+163u)  /* TIM2 fault interrupt */
#define OS_TIM2_OVF_IRQn                (SYS_EXCEPTION_NUM+164u)  /* TIM2 overflow interrupt */
#define OS_TIM2_RELOAD_IRQn             (SYS_EXCEPTION_NUM+165u)  /* TIM2 reload interrupt */
#define OS_TIM3_IRQn                    (SYS_EXCEPTION_NUM+166u)  /* TIM3 channel interrupt */
#define OS_TIM3_FAULT_IRQn              (SYS_EXCEPTION_NUM+167u)  /* TIM3 fault interrupt */
#define OS_TIM3_OVF_IRQn                (SYS_EXCEPTION_NUM+168u)  /* TIM3 overflow interrupt */
#define OS_TIM3_RELOAD_IRQn             (SYS_EXCEPTION_NUM+169u)  /* TIM3 reload interrupt */
#define OS_TDG0_TCO_IRQn                (SYS_EXCEPTION_NUM+170u)  /* TDG0 tco interrupt */
#define OS_TDG0_ERR_IRQn                (SYS_EXCEPTION_NUM+171u)  /* TDG0 err interrupt */
#define OS_TDG1_TCO_IRQn                (SYS_EXCEPTION_NUM+172u)  /* TDG1 tco interrupt */
#define OS_TDG1_ERR_IRQn                (SYS_EXCEPTION_NUM+173u)  /* TDG1 err interrupt */
#define OS_I2S0_IRQn                    (SYS_EXCEPTION_NUM+174u)  /* I2S0 interrupt */
#define OS_I2S1_IRQn                    (SYS_EXCEPTION_NUM+175u)  /* I2S1 interrupt */
#define OS_PORTA_IRQn                   (SYS_EXCEPTION_NUM+176u)  /* PORTA Interrupt */
#define OS_PORTB_IRQn                   (SYS_EXCEPTION_NUM+177u)  /* PORTB Interrupt */
#define OS_PORTC_IRQn                   (SYS_EXCEPTION_NUM+178u)  /* PORTC Interrupt */
#define OS_PORTD_IRQn                   (SYS_EXCEPTION_NUM+179u)  /* PORTD Interrupt */
#define OS_PORTE_IRQn                   (SYS_EXCEPTION_NUM+180u)  /* PORTE Interrupt */
#define OS_STIM_IRQn                    (SYS_EXCEPTION_NUM+181u)  /* STIM interrupt */
#define OS_RTC_ALARM_IRQn               (SYS_EXCEPTION_NUM+182u)  /* RTC alarm */
#define OS_RTC_SECOND_IRQn              (SYS_EXCEPTION_NUM+183u)  /* RTC second */
#define OS_AES_INTR_IRQn                (SYS_EXCEPTION_NUM+184u)  /* AES interrupt */
#define OS_TRNG_INTR_IRQn               (SYS_EXCEPTION_NUM+185u)  /* TRNG interrupt */
#define OS_CMU0_IRQn                    (SYS_EXCEPTION_NUM+186u)  /* Reserved */
#define OS_CMU1_IRQn                    (SYS_EXCEPTION_NUM+187u)  /* CMU1 interrupt */
#define OS_CMU2_IRQn                    (SYS_EXCEPTION_NUM+188u)  /* CMU2 interrupt */
#define OS_SERU_PARITY_ERR_IRQn         (SYS_EXCEPTION_NUM+189u)  /* SERU parity error interrupt */
#define OS_SERU_CHANNEL_ERR_IRQn        (SYS_EXCEPTION_NUM+190u)  /* SERU channel error interrupt1 */
#define OS_SYS_CLOCK_IRQn               (SYS_EXCEPTION_NUM+191u)  /* System clock controller */
#define OS_MCPWM0_CH_IRQn               (SYS_EXCEPTION_NUM+192u)  /* MCPWM0 CH interrupt */
#define OS_MCPWM0_FAULT_IRQn            (SYS_EXCEPTION_NUM+193u)  /* MCPWM0 FAULT interrupt */
#define OS_MCPWM0_OVFL_IRQn             (SYS_EXCEPTION_NUM+194u)  /* MCPWM0 OVFL interrupt */
#define OS_MCPWM0_RLFL_IRQn             (SYS_EXCEPTION_NUM+195u)  /* MCPWM0 RLFL interrupt */
#define OS_MCPWM1_CH_IRQn               (SYS_EXCEPTION_NUM+196u)  /* MCPWM1 CH interrupt */
#define OS_MCPWM1_FAULT_IRQn            (SYS_EXCEPTION_NUM+197u)  /* MCPWM1 FAULT interrupt */
#define OS_MCPWM1_OVFL_IRQn             (SYS_EXCEPTION_NUM+198u)  /* MCPWM1 OVFL interrupt */
#define OS_MCPWM1_RLFL_IRQn             (SYS_EXCEPTION_NUM+199u)  /* MCPWM1 RLFL interrupt */
#define OS_ADC0_IRQn                    (SYS_EXCEPTION_NUM+200u)  /* ADC0 interrupt request */
#define OS_ADC1_IRQn                    (SYS_EXCEPTION_NUM+201u)  /* ADC1 interrupt request */
#define OS_CMP_IRQn                     (SYS_EXCEPTION_NUM+202u)  /* CMP interrupt request */
#define OS_FPU_ERROR_IRQn               (SYS_EXCEPTION_NUM+203u)  /* FPU error interrupt */
#define OS_CACHE_ERROR_IRQn             (SYS_EXCEPTION_NUM+204u)  /* cache error interrupt */

#define OS_NVIC_ISER_BASE_ADDRESS 0xE000E100u /* Interrupt Set-Enable Register0-15:0xE000E100->0xE000E13C */
#define OS_NVIC_ICER_BASE_ADDRESS 0xE000E180u /* Interrupt Clear-Enable Register0-15:0xE000E180->0xE000E1BC */
#define OS_NVIC_ICPR_BASE_ADDRESS 0xE000E280u /* Interrupt Clear-Pending Register 0-15:0xE000E280->0xE000E2BC */
#define OS_NVIC_IABR_BASE_ADDRESS 0xE000E300u /* Active Bit Register Register 0-15:0xE000E300->0xE000E37C */
#define OS_NVIC_IPR_BASE_ADDRESS  0xE000E400u /* Interrupt Priority Register 0-123:0xE000E400->0xE000E7EC */
#define OS_NVIC_STIR_ADDRESS      0xE000EF00u /* Software Trigger Interrupt Register */
#define OS_NVIC_SEPR_BASE_ADDRESS 0xE000ED18u

/* STIM Base Address*/
#define OS_STIM_BASE_ADDRESS        0x40040000u

#define OS_STIM_CNT                 OS_REG32(OS_STIM_BASE_ADDRESS)          /* Stim Channel Counter Register */
#define OS_STIM_CV                  OS_REG32(OS_STIM_BASE_ADDRESS + 0x14u)  /* Stim Compare Value Register */
#define OS_STIM_CTRL                OS_REG32(OS_STIM_BASE_ADDRESS + 0x24u)  /* Stim Channel Status and Control Register */

/* FLASH address */
#define PFLASH_START    (0x00000000U)
#define PFLASH_END      (0x001FFFFFU)

/* SRAM address */
#define SRAM_START     (0x1FFE0000U)
#define SRAM_END       (0x20020000U)

/* Peripheral address */
#define PERIPHERAL_START 0x40000000U
#define PERIPHERAL_END   0x400FFFFFU

/* Interrupt priority conversion */
#define OS_NVIC_PRIO_MIN    0x00u
#define OS_NVIC_PRIO_MAX    0xFFu

/* OS exception priority configuration (logic interrupt priority)*/
#define OS_NVIC_CONVERT_GET_PRIO(prio) (uint8)(((prio) ^ 0xFFu) >> 4u)
#define OS_NVIC_CONVERT_SET_PRIO(prio) (uint8)(((prio) ^ 0xFFu) << 4u)

/* SysTick Timer */
#define OS_SYSTICK_ENABLE_BIT   (1u << 0u)
#define OS_SYSTICK_INT_BIT      (1u << 1u)
#define OS_SYSTICK_CLK_BIT      (1u << 2u)

#define OS_SYSTICK_BASE_ADDRESS (0xE000E010U)
#define OS_SYSTICK_CTRL_REG     OS_REG32(OS_SYSTICK_BASE_ADDRESS)
#define OS_SYSTICK_RELOAD_REG   OS_REG32(OS_SYSTICK_BASE_ADDRESS + 0x4u)
#define OS_SYSTICK_COUNTER_REG  OS_REG32(OS_SYSTICK_BASE_ADDRESS + 0x8u)
#define OS_SYSTICK_CHECK_REG    OS_REG32(OS_SYSTICK_BASE_ADDRESS + 0xCu)

/*=======[Porting Macro]=====================================================*/
/* Common macros */
#define ASM                       __asm volatile
#define OS_MSR_PRIMASK_BIT0       (0x00000001U)
#define OS_ARCH_STACK_ALIGN(addr) (addr & 0xFFFFFFF8u)
#define OS_ARCH_INT_CORE0         OS_ARCH_INT_CPU0

/* Msync/Isynch core instruction macros */
#define OS_ARCH_ISYNC() ASM("isb")
#define OS_ARCH_DSYNC() ASM("dsb")

/* Disable/Enable HW Interrupts */
#define Os_ArchDisableInt() ASM("cpsid i")
#define Os_ArchEnableInt()  ASM("dsb\n cpsie i\n")

/* Critical Macro */
#define OS_ARCH_DECLARE_CRITICAL() Os_ArchMsrType msr
#define OS_ARCH_ENTRY_CRITICAL()   Os_ArchSuspendInt(&msr)
#define OS_ARCH_EXIT_CRITICAL()    Os_ArchRestoreInt(msr)

#define CFG_PLATFORM_S32K3xx       FALSE

/* Save/Resume context */
#define OS_ARCH_SAVE_CONTEXT()                       \
    ASM("    cpsid i                            \n"  \
        "    pop {r8, lr}                   \n"      \
        "    ldr.w r1, = Os_ArchTempSp       \n"     \
        "    mrs r0, psp                     \n"     \
        "    sub r0, r0, #0x28               \n"     \
        "    sub r0, r0, #0x80               \n"     \
        "    str r0, [r1]                    \n"     \
        "    ldr r2, = 0xE000EF38            \n"     \
        "    ldr r2, [r2]                        \n" \
        "    mrs r3,control                  \n"     \
        "    vstmia r0, {s0-s15}             \n"     \
        "    add r0, r0, #0x40                \n"    \
        "    vstmia r0, {s16-s31}            \n"     \
        "    add r0, r0, #0x40                \n"    \
        "    stmia r0, {r2-r11}              \n"     \
        "   push {r8, lr}                  \n"       \
        "    dsb                             \n"     \
        "    isb                             \n");   \
    Os_TaskCBExt[Os_SCB.sysRunningTaskID] = Os_ArchTempSp;

#define OS_ARCH_RESUME_CONTEXT()                           \
    Os_ArchTempSp = Os_TaskCBExt[Os_SCB.sysRunningTaskID]; \
    ASM("    cpsid i                            \n"        \
        "    pop {r8, lr}                   \n"            \
        "    ldr r0, =Os_ArchTempSp         \n"            \
        "    ldr r0, [r0]                    \n"           \
        "    vldmia r0, {s0-s15}             \n"           \
        "    add r0, r0, #0x40                \n"          \
        "    vldmia r0, {s16-s31}             \n"          \
        "    add r0, r0, #0x40                \n"          \
        "    ldmia r0, {r2-r11}              \n"           \
        "    add r0, r0, #0x28               \n"           \
        "    ldr r1, = 0xE000EF38            \n"           \
        "    str r2, [r1]                    \n"           \
        "    msr control,r3                  \n"           \
        "    msr psp, r0                     \n"           \
        "    tst lr, #0x8                    \n"           \
        "    it ne                            \n"          \
        "    movne lr, #0xfffffffd           \n"           \
        "    dsb                             \n"           \
        "    isb                             \n"           \
        "    cpsie i                         \n"           \
        "    bx lr                           \n")

/*-----------------------------Interrupt Macro-------------------------------*/
/* Disable/Enable interrupt X */
#define OS_INTERRUPT_ENABLE(id)                                                                                     \
    if (id >= 16)                                                                                                   \
        OS_REG32(OS_NVIC_ISER_BASE_ADDRESS + (((id - 16) >> 5) << 2)) = (uint32)1u << ((uint32)(id - 16u) & 0x1Fu); \
    else if (id == 15)                                                                                              \
    OS_SYSTICK_CTRL_REG |= 1

#define OS_INTERRUPT_DISABLE(id)                                                                                    \
    if (id >= 16)                                                                                                   \
        OS_REG32(OS_NVIC_ICER_BASE_ADDRESS + (((id - 16) >> 5) << 2)) = (uint32)1u << ((uint32)(id - 16u) & 0x1Fu); \
    else if (id == 15)                                                                                              \
    OS_SYSTICK_CTRL_REG = ~((~OS_SYSTICK_CTRL_REG) | 1)

/* Set/Clear interrupt pending X */
#define OS_INTERRUPT_SET_PENDING(id) \
    if (id >= 16)                    \
    OS_REG32(OS_NVIC_STIR_ADDRESS) = (id - 16) & 0x1FFu

#define OS_INTERRUPT_CLEAR_PENDING(id) \
    if (id >= 16)                      \
    OS_REG32(OS_NVIC_ICPR_BASE_ADDRESS + (((id - 16) >> 5) << 2)) = (uint32)1u << ((uint32)(id - 16) & 0x1Fu)

/* Get interrupt X pending/active status */
#define OS_INTERRUPT_PENDING_STATUS(id) \
    ((id >= 16) ? ((OS_REG32(OS_NVIC_ICPR_BASE_ADDRESS + (((id - 16) >> 5) << 2)) >> ((id - 16) & 0x1Fu)) & 0x01u) : 0)

#define OS_INTERRUPT_ACTIVE_STATUS(id) \
    ((id >= 16) ? ((OS_REG32(OS_NVIC_IABR_BASE_ADDRESS + (((id - 16) >> 5) << 2)) >> ((id - 16) & 0x1Fu)) & 0x01u) : 0)

#define OS_INTERRUPT_PENDING_OR_ACTIVE_STATUS(id)                                                                \
    ((id >= 16)                                                                                                  \
         ? (((OS_REG32(OS_NVIC_IABR_BASE_ADDRESS + (((id - 16) >> 5) << 2)) >> ((id - 16) & 0x1Fu)) & 0x01u)     \
            || ((OS_REG32(OS_NVIC_ICPR_BASE_ADDRESS + (((id - 16) >> 5) << 2)) >> ((id - 16) & 0x1Fu)) & 0x01u)) \
         : 0)

/* Set interrupt priority */
#define OS_INTERRUPT_SYS_PRIO(id)  OS_REG8(OS_NVIC_SEPR_BASE_ADDRESS + id)

#define OS_INTERRUPT_NVIC_PRIO(id) OS_REG8(OS_NVIC_IPR_BASE_ADDRESS + id)

#define OS_INTERRUPT_SET_PRIO(id, prio)                  \
    if (id >= 16)                                        \
    {                                                    \
        OS_INTERRUPT_NVIC_PRIO(id - 16) = (uint8)(prio); \
    }                                                    \
    else if (id >= 4)                                    \
    {                                                    \
        OS_INTERRUPT_SYS_PRIO(id - 4) = (uint8)(prio);   \
    }                                                    \
    else                                                 \
    {                                                    \
    }

/* Install interrupt */
#define OS_INTERRUPT_INSTALL(id, prio, srcType)                \
    OS_INTERRUPT_SET_PRIO(id, OS_NVIC_CONVERT_SET_PRIO(prio)); \
    OS_INTERRUPT_ENABLE(id)
#define OS_INTERRUPT_Unload(id, prio, srcType) OS_INTERRUPT_DISABLE(id)
/* Check interrupt enable status */
#define OS_INTERRUPT_CHECK_STATUS(id) \
    ((id >= 16) ? ((OS_REG32(OS_NVIC_ISER_BASE_ADDRESS + (((id - 16) >> 5) << 2)) >> ((id - 16) & 0x1Fu)) & 0x01u) : 0)

#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
/* Get/Set special register---control*/
#define Os_ArchGetControl()                \
    ASM("push {r0,r1}                  \n" \
        "ldr r1, =Os_ArchControl       \n" \
        "mrs r0, control               \n" \
        "str r0, [r1]                  \n" \
        "pop {r0,r1}                   \n")
#define Os_ArchSetControl()                \
    ASM("ldr r0, =Os_ArchControl       \n" \
        "ldr r0, [r0]                  \n" \
        "msr control, r0               \n")

#define Os_ArchCheckCpuMode()               \
{                                           \
    if (FALSE == Os_AppCfg[Os_SCB.sysRunningAppID].OsTrusted)\
    {                                       \
           Os_SetCpuMode(OS_CPUMODE_USER0);  \
    }                                       \
    else                                    \
    {                                       \
    }                                       \
}

#define OS_CHANGCPUMODE(CpuMode)            \
{                                           \
	MPU_Group = 0;							\
    if((1u == (getControlValue() & 0x00000001u)) && (Os_GetIsrIPSR() != 3))       \
    {                                       \
         Os_ArchSyscall();                  \
         MPU_Group = 1;                     \
    }                                       \
    else                                    \
    {                                       \
    }                                       \
}

#define OS_RESUMECPUMODE()                  \
        if(MPU_Group > 0)                   \
        {                                   \
            Os_SetCpuMode(OS_CPUMODE_USER0);\
        }

#endif

/**
 * trigger the specific interrupt source by setting the request bit, just for debug.
 * write 1 to the bit26 SETR(set request)
 */
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
#define OS_INTERRUPT_SETREQ(src) (*(uint32 volatile*)src) = ((*(uint32 volatile*)src) | 0x04000000u);
#else
#define OS_INTERRUPT_SETREQ(src) (*(uint32 volatile*)src) = ((*(uint32 volatile*)src) | 0x04000000u)
#endif /* #if (CFG_SRV_SHELLOS == TRUE) */

#define Os_ArchRemoteCall(respondCoreId)

#define Os_ArchPreSwitch2System()

/* Switch msp to system stack*/
#define Os_ArchSwitch2System()                                                 \
    do                                                                         \
    {                                                                          \
        Os_ArchTempSp = OS_ARCH_STACK_ALIGN((uint32)Os_SystemStack->stackTop); \
        ASM("msr msp, %[sysSP]" ::[sysSP] "r"(Os_ArchTempSp));    \
    } while (0)

#if (CFG_ISR2_MAX > 0U)
/* Save msp in "Os_ArchMasterSp" and switch msp to ISR2 stack */
#define Os_ArchSwitch2ISR2Stk(isrId)                                               \
    {                                                                              \
        Os_ArchTempSp = OS_ARCH_STACK_ALIGN((uint32)Os_ISR2Stack[isrId].stackTop); \
        Os_ArchMasterSp_New = &Os_ArchMasterSp_ARRAY[Os_IntNestISR2];              \
        ASM("    ldr r0, = Os_ArchMasterSp_New  \n"                                \
            "    ldr r0, [r0]                   \n"                                \
            "    mrs r1, msp                    \n"                                \
            "    str r1, [r0]                   \n"                                \
            "    ldr r0, = Os_ArchTempSp        \n"                                \
            "    ldr r1, [r0]                   \n"                                \
            "    msr msp, r1                    \n");                              \
    }

/* Resume msp */
#define Os_ArchSwitch2MasterStk()                                     \
    {                                                                 \
        Os_ArchMasterSp_New = &Os_ArchMasterSp_ARRAY[Os_IntNestISR2]; \
        ASM("    ldr r0, = Os_ArchMasterSp_New      \n"               \
            "    ldr r0, [r0]                   \n"                   \
            "    ldr r1, [r0]                   \n"                   \
            "    msr msp, r1                    \n");                 \
    }

#else
#define Os_ArchSwitch2ISR2Stk(isrId)
#define Os_ArchSwitch2MasterStk(isrId)
#endif

#if ((OS_NOSC == CFG_SC) || (OS_SC1 == CFG_SC) || (OS_SC2 == CFG_SC))
#define OS_ARCH_ISR2_EPILOGUE() OS_ARCH_ISR2_EPILOGUE_1()
#else
#define OS_ARCH_ISR2_EPILOGUE() OS_ARCH_ISR2_EPILOGUE_1()
#endif

/*=======[I N T E R N A L   M A C R O]=======================================*/
/*  */
#if (TRUE == CFG_INT_NEST_ENABLE)
#define OS_ARCH_ISR1_PROLOGUE(isrId)                          \
    {                                                         \
        Os_ArchDisableInt();                                  \
        if (0U == Os_IntNestISR1)                             \
        {                                                     \
            Os_SaveLevelISR1 = Os_SCB.sysOsLevel;             \
            Os_SCB.sysOsLevel = OS_LEVEL_ISR1;                \
        }                                                     \
        Os_EnterISR1();                                       \
        Os_IntNestISR1++;                                     \
        if (TRUE == Os_IsrCfg[Os_IntCfgIsrId].OsNestedEnable) \
        {                                                     \
            Os_ArchEnableInt();                               \
        }                                                     \
    }

#define OS_ARCH_ISR1_EPILOGUE()                   \
    {                                             \
        Os_ArchDisableInt();                      \
        Os_ExitISR1();                            \
        Os_IntNestISR1--;                         \
        if (0U == Os_IntNestISR1)                 \
        {                                         \
            Os_SCB.sysOsLevel = Os_SaveLevelISR1; \
        }                                         \
        Os_ArchEnableInt();                       \
    }

#else
#define OS_ARCH_ISR1_PROLOGUE(isrId)          \
    {                                         \
        Os_ArchDisableInt();                  \
        Os_SaveLevelISR1 = Os_SCB.sysOsLevel; \
        Os_SCB.sysOsLevel = OS_LEVEL_ISR1;    \
        Os_EnterISR1();                       \
    }

#define OS_ARCH_ISR1_EPILOGUE()               \
    {                                         \
        Os_SCB.sysOsLevel = Os_SaveLevelISR1; \
        Os_ExitISR1();                        \
        Os_ArchEnableInt();                   \
    }
#endif /* #if (TRUE == CFG_INT_NEST_ENABLE) */

#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
#define OS_ARCH_ISR2_PROLOGUE(isrId)                                       \
    {                                                                      \
        __asm(" cpsid i");                                                 \
        Os_IntCfgIsrId = isrId;                                            \
        if (E_OK != Os_TmProtIsrFrameChk(Os_IntCfgIsrId))                  \
        {                                                                  \
            __asm(" cpsie i");                                             \
            return;                                                        \
        }                                                                  \
        __asm("    pop {r8}                       \n"                      \
              "    push {r8}                       \n"                     \
              "    mrs r0, msp                    \n"                      \
              "    sub r0, r0, #0x28              \n"                      \
              "    sub r0, r0, #0x80              \n"                      \
              "    msr msp, r0                    \n"                      \
              "    ldr r2, = 0xE000EF38           \n"                      \
              "    ldr r2, [r2]                     \n"                    \
              "    mrs r3,control             \n"                          \
              "    vstmia r0, {s0-s15}            \n"                      \
              "    add r0, r0, #0x40              \n"                      \
              "    vstmia r0, {s16-s31}           \n"                      \
              "    add r0, r0, #0x40              \n"                      \
              "    stmia r0, {r2-r11}             \n");                    \
        Os_ArchSwitch2ISR2Stk(isrId) Os_SetCpuMode(OS_CPUMODE_SUPERVISOR); \
        Os_EnterISR2();                                                    \
        if (TRUE == Os_IsrCfg[Os_IntCfgIsrId].OsNestedEnable)              \
        {                                                                  \
            Os_ArchEnableInt();                                            \
        }                                                                  \
    }

#define OS_ARCH_ISR2_EPILOGUE_1()                                                              \
    {                                                                                          \
        OS_ISR2OCCUPYINTRES();                                                                 \
        Os_ArchDisableInt();                                                                   \
        if ((TRUE == Os_TprotTerminateIsr) && (Os_IntNestISR2 >= 2))                           \
        {                                                                                      \
            Os_ArchMasterSp_ARRAY[Os_IntNestISR2 - 1] = Os_ArchMasterSp_ARRAY[Os_IntNestISR2]; \
            Os_IntNestISR2--;                                                                  \
            Os_TprotTerminateIsr = FALSE;                                                      \
        }                                                                                      \
        Os_ExitISR2();                                                                         \
        Os_ArchSwitch2MasterStk();                                                             \
        if (TRUE == Os_TprotTerminateTask)                                                     \
        {                                                                                      \
            OS_INTERRUPT_SET_PRIO(OS_PendSV_IRQn, OS_NVIC_CONVERT_SET_PRIO(12));               \
        }                                                                                      \
        __asm("    mrs r0, msp                     \n"                                         \
              "    vldmia r0, {s0-s15}             \n"                                         \
              "    add r0, r0, #0x40                \n"                                        \
              "    vldmia r0, {s16-s31}             \n"                                        \
              "    add r0, r0, #0x40                \n"                                        \
              "    ldmia r0, {r2-r11}              \n"                                         \
              "    add r0, r0, #0x28               \n"                                         \
              "    ldr r1, = 0xE000EF38            \n"                                         \
              "    str r2, [r1]                    \n"                                         \
              "    msr control,r3                 \n"                                          \
              "    msr msp, r0                     \n");                                       \
        __asm(" cpsie i");                                                                     \
    }

#define OS_ARCH_ISR2_EPILOGUE_TERMINATEISR()                                     \
    {                                                                            \
        OS_ISR2OCCUPYINTRES();                                                   \
        Os_ArchDisableInt();                                                     \
        Os_ExitISR2();                                                           \
        Os_ArchSwitch2MasterStk();                                               \
        if (TRUE == Os_TprotTerminateTask)                                       \
        {                                                                        \
            OS_INTERRUPT_SET_PRIO(OS_PendSV_IRQn, OS_NVIC_CONVERT_SET_PRIO(12)); \
        }                                                                        \
        __asm("    mrs r0, msp                     \n"                           \
              "    vldmia r0, {s0-s15}             \n"                           \
              "    add r0, r0, #0x40                \n"                          \
              "    vldmia r0, {s16-s31}             \n"                          \
              "    add r0, r0, #0x40                \n"                          \
              "    ldmia r0, {r2-r11}              \n"                           \
              "    add r0, r0, #0x28               \n"                           \
              "    ldr r1, = 0xE000EF38            \n"                           \
              "    str r2, [r1]                    \n"                           \
              "    msr control,r3                 \n"                            \
              "    msr msp, r0                     \n");                         \
        __asm("    mov lr, #0xfffffffd ");                                       \
        __asm(" cpsie i");                                                       \
        __asm(" bx lr");                                                         \
    }

#elif (TRUE == CFG_INT_NEST_ENABLE) /*#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)*/

#if ((CFG_SC == OS_SC3) || (CFG_SC == OS_SC4))
#define OS_ARCH_ISR2_PROLOGUE(isrId)                          \
    {                                                         \
        __asm(" cpsid i");                                    \
        __asm("    pop {r8}                       \n"         \
              "    push {r8}                       \n"        \
              "    mrs r0, msp                    \n"         \
              "    sub r0, r0, #0x28              \n"         \
              "    sub r0, r0, #0x80              \n"         \
              "    msr msp, r0                    \n"         \
              "    ldr r2, = 0xE000EF38           \n"         \
              "    ldr r2, [r2]                     \n"       \
              "    mrs r3,control             \n"             \
              "    vstmia r0, {s0-s15}            \n"         \
              "    add r0, r0, #0x40              \n"         \
              "    vstmia r0, {s16-s31}           \n"         \
              "    add r0, r0, #0x40              \n"         \
              "    stmia r0, {r2-r11}             \n");       \
        Os_ArchSwitch2ISR2Stk(isrId);                         \
        Os_SetCpuMode(OS_CPUMODE_SUPERVISOR);                 \
        Os_IntCfgIsrId = isrId;                               \
        Os_EnterISR2();                                       \
        if (TRUE == Os_IsrCfg[Os_IntCfgIsrId].OsNestedEnable) \
        {                                                     \
            Os_ArchEnableInt();                               \
        }                                                     \
    }

#define OS_ARCH_ISR2_EPILOGUE_1()                        \
    {                                                    \
        __asm(" cpsid i");                               \
        OS_ISR2OCCUPYINTRES();                           \
        Os_ExitISR2();                                   \
        Os_ArchSwitch2MasterStk();                       \
        __asm("    mrs r0, msp                     \n"   \
              "    vldmia r0, {s0-s15}             \n"   \
              "    add r0, r0, #0x40                \n"  \
              "    vldmia r0, {s16-s31}             \n"  \
              "    add r0, r0, #0x40                \n"  \
              "    ldmia r0, {r2-r11}              \n"   \
              "    add r0, r0, #0x28               \n"   \
              "    ldr r1, = 0xE000EF38            \n"   \
              "    str r2, [r1]                    \n"   \
              "    msr control,r3                 \n"    \
              "    msr msp, r0                     \n"); \
        __asm(" cpsie i");                               \
    }

#define OS_ARCH_ISR2_EPILOGUE_TERMINATEISR()             \
    {                                                    \
        OS_ISR2OCCUPYINTRES();                           \
        Os_ArchDisableInt();                             \
        Os_ExitISR2();                                   \
        Os_ArchSwitch2MasterStk();                       \
        __asm("    mrs r0, msp                     \n"   \
              "    vldmia r0, {s0-s15}             \n"   \
              "    add r0, r0, #0x40                \n"  \
              "    vldmia r0, {s16-s31}             \n"  \
              "    add r0, r0, #0x40                \n"  \
              "    ldmia r0, {r2-r11}              \n"   \
              "    add r0, r0, #0x28               \n"   \
              "    ldr r1, = 0xE000EF38            \n"   \
              "    str r2, [r1]                    \n"   \
              "    msr control,r3                 \n"    \
              "    msr msp, r0                     \n"); \
        __asm("    mov lr, #0xfffffffd ");               \
        __asm(" cpsie i");                               \
        __asm(" bx lr");                                 \
    }
#else /*#elif  ((CFG_SC == OS_SC3)||(CFG_SC == OS_SC4))*/
#define OS_ARCH_ISR2_PROLOGUE(isrId)                          \
    {                                                         \
        __asm(" cpsid i");                                    \
        __asm("    pop {r8}                       \n"         \
              "    push {r8}                       \n"        \
              "    mrs r0, msp                    \n"         \
              "    sub r0, r0, #0x28              \n"         \
              "    sub r0, r0, #0x80              \n"         \
              "    msr msp, r0                    \n"         \
              "    ldr r2, = 0xE000EF38           \n"         \
              "    ldr r2, [r2]                     \n"       \
              "    mrs r3,control             \n"             \
              "    vstmia r0, {s0-s15}            \n"         \
              "    add r0, r0, #0x40              \n"         \
              "    vstmia r0, {s16-s31}           \n"         \
              "    add r0, r0, #0x40              \n"         \
              "    stmia r0, {r2-r11}             \n");       \
        Os_ArchSwitch2ISR2Stk(isrId);                         \
        Os_SetCpuMode(OS_CPUMODE_SUPERVISOR);                 \
        Os_IntCfgIsrId = isrId;                               \
        Os_EnterISR2();                                       \
        if (TRUE == Os_IsrCfg[Os_IntCfgIsrId].OsNestedEnable) \
        {                                                     \
            Os_ArchEnableInt();                               \
        }                                                     \
    }

#define OS_ARCH_ISR2_EPILOGUE_1()                        \
    {                                                    \
        __asm(" cpsid i");                               \
        OS_ISR2OCCUPYINTRES();                           \
        Os_ExitISR2();                                   \
        Os_ArchSwitch2MasterStk();                       \
        __asm("    mrs r0, msp                     \n"   \
              "    vldmia r0, {s0-s15}             \n"   \
              "    add r0, r0, #0x40                \n"  \
              "    vldmia r0, {s16-s31}             \n"  \
              "    add r0, r0, #0x40                \n"  \
              "    ldmia r0, {r2-r11}              \n"   \
              "    add r0, r0, #0x28               \n"   \
              "    ldr r1, = 0xE000EF38            \n"   \
              "    str r2, [r1]                    \n"   \
              "    msr control,r3                 \n"    \
              "    msr msp, r0                     \n"); \
        __asm(" cpsie i");                               \
    }

#define OS_ARCH_ISR2_EPILOGUE_TERMINATEISR()             \
    {                                                    \
        OS_ISR2OCCUPYINTRES();                           \
        Os_ArchDisableInt();                             \
        Os_ExitISR2();                                   \
        Os_ArchSwitch2MasterStk();                       \
        __asm("    mrs r0, msp                     \n"   \
              "    vldmia r0, {s0-s15}             \n"   \
              "    add r0, r0, #0x40                \n"  \
              "    vldmia r0, {s16-s31}             \n"  \
              "    add r0, r0, #0x40                \n"  \
              "    ldmia r0, {r2-r11}              \n"   \
              "    add r0, r0, #0x28               \n"   \
              "    ldr r1, = 0xE000EF38            \n"   \
              "    str r2, [r1]                    \n"   \
              "    msr control,r3                 \n"    \
              "    msr msp, r0                     \n"); \
        __asm("    mov lr, #0xfffffffd ");               \
        __asm(" cpsie i");                               \
        __asm(" bx lr");                                 \
    }

#endif
#else
#if ((CFG_SC == OS_SC3) || (CFG_SC == OS_SC4))
#define OS_ARCH_ISR2_PROLOGUE(isrId)                    \
    {                                                   \
        __asm(" cpsid i");                              \
        __asm("    pop {r8}                       \n"   \
              "    push {r8}                       \n"  \
              "    mrs r0, msp                    \n"   \
              "    sub r0, r0, #0x28              \n"   \
              "    sub r0, r0, #0x80              \n"   \
              "    msr msp, r0                    \n"   \
              "    ldr r2, = 0xE000EF38           \n"   \
              "    ldr r2, [r2]                     \n" \
              "    mrs r3,control             \n"       \
              "    vstmia r0, {s0-s15}            \n"   \
              "    add r0, r0, #0x40              \n"   \
              "    vstmia r0, {s16-s31}           \n"   \
              "    add r0, r0, #0x40              \n"   \
              "    stmia r0, {r2-r11}             \n"); \
        Os_ArchSwitch2ISR2Stk(isrId);                   \
        Os_SetCpuMode(OS_CPUMODE_SUPERVISOR);           \
        Os_IntCfgIsrId = isrId;                         \
        Os_EnterISR2();                                 \
    }

#define OS_ARCH_ISR2_EPILOGUE_1()                        \
    {                                                    \
        __asm(" cpsid i");                               \
        OS_ISR2OCCUPYINTRES();                           \
        Os_ExitISR2();                                   \
        Os_ArchSwitch2MasterStk();                       \
        __asm("    mrs r0, msp                     \n"   \
              "    vldmia r0, {s0-s15}             \n"   \
              "    add r0, r0, #0x40                \n"  \
              "    vldmia r0, {s16-s31}             \n"  \
              "    add r0, r0, #0x40                \n"  \
              "    ldmia r0, {r2-r11}              \n"   \
              "    add r0, r0, #0x28               \n"   \
              "    ldr r1, = 0xE000EF38            \n"   \
              "    str r2, [r1]                    \n"   \
              "    msr control,r3                 \n"    \
              "    msr msp, r0                     \n"); \
        __asm(" cpsie i");                               \
    }

#define OS_ARCH_ISR2_EPILOGUE_TERMINATEISR()             \
    {                                                    \
        OS_ISR2OCCUPYINTRES();                           \
        Os_ArchDisableInt();                             \
        Os_ExitISR2();                                   \
        Os_ArchSwitch2MasterStk();                       \
        __asm("    mrs r0, msp                     \n"   \
              "    vldmia r0, {s0-s15}             \n"   \
              "    add r0, r0, #0x40                \n"  \
              "    vldmia r0, {s16-s31}             \n"  \
              "    add r0, r0, #0x40                \n"  \
              "    ldmia r0, {r2-r11}              \n"   \
              "    add r0, r0, #0x28               \n"   \
              "    ldr r1, = 0xE000EF38            \n"   \
              "    str r2, [r1]                    \n"   \
              "    msr control,r3                 \n"    \
              "    msr msp, r0                     \n"); \
        __asm("    mov lr, #0xfffffffd ");               \
        __asm(" cpsie i");                               \
        __asm(" bx lr");                                 \
    }
#else
#define OS_ARCH_ISR2_PROLOGUE(isrId)                    \
    {                                                   \
        __asm(" cpsid i");                              \
        __asm("    pop {r8}                       \n"   \
              "    push {r8}                       \n"  \
              "    mrs r0, msp                    \n"   \
              "    sub r0, r0, #0x28              \n"   \
              "    sub r0, r0, #0x80              \n"   \
              "    msr msp, r0                    \n"   \
              "    ldr r2, = 0xE000EF38           \n"   \
              "    ldr r2, [r2]                     \n" \
              "    mrs r3,control             \n"       \
              "    vstmia r0, {s0-s15}            \n"   \
              "    add r0, r0, #0x40              \n"   \
              "    vstmia r0, {s16-s31}           \n"   \
              "    add r0, r0, #0x40              \n"   \
              "    stmia r0, {r2-r11}             \n"); \
        Os_ArchSwitch2ISR2Stk(isrId);                   \
        Os_SetCpuMode(OS_CPUMODE_SUPERVISOR);           \
        Os_IntCfgIsrId = isrId;                         \
        Os_EnterISR2();                                 \
    }

#define OS_ARCH_ISR2_EPILOGUE_1()                        \
    {                                                    \
        __asm(" cpsid i");                               \
        OS_ISR2OCCUPYINTRES();                           \
        Os_ExitISR2();                                   \
        Os_ArchSwitch2MasterStk();                       \
        __asm("    pop {r8}                       \n"   \
              "    push {r8}                       \n"  \
              "    mrs r0, msp                    \n"   \
              "    vldmia r0, {s0-s15}             \n"   \
              "    add r0, r0, #0x40                \n"  \
              "    vldmia r0, {s16-s31}             \n"  \
              "    add r0, r0, #0x40                \n"  \
              "    ldmia r0, {r2-r11}              \n"   \
              "    add r0, r0, #0x28               \n"   \
              "    ldr r1, = 0xE000EF38            \n"   \
              "    str r2, [r1]                    \n"   \
              "    msr control,r3                 \n"    \
              "    msr msp, r0                     \n"); \
        __asm(" cpsie i");                               \
    }

#endif
#endif

#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
#define OS_ISR2OCCUPYINTRES() Os_Isr2OccupyIntRes()
#else
#define OS_ISR2OCCUPYINTRES()
#endif /*#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)*/

/*=======[T Y P E   D E F I N I T I O N S]====================================*/
typedef uint32 Os_ArchMsrType;
typedef uint32 Os_TaskCBExtType;

typedef struct
{
    uint32 reg[16];
} Os_ArchCsaType;

/* type of an Trap */
typedef void (*Os_traphnd)(uint16 Os_Tin);

/* type of an Interrupt Service Routine (ISR) */
typedef void (*Os_isrhnd)(void);

/* Core Mode */
typedef enum
{
    OS_CORE_MODE_HALT = 0U,
    OS_CORE_MODE_RUN = 1U,
    OS_CORE_MODE_IDLE = 2U,
    OS_CORE_MODE_SLEEP = 3U,
    OS_CORE_MODE_STANDBY = 4U,
    OS_CORE_MODE_UNKNOWN = 5U
} Os_CoreModeType;

/*=======[E X T E R N A L   D A T A]==========================================*/
extern VAR(Os_TaskCBExtType, OS_VAR) Os_TaskCBExtCore0[CFG_TASK_MAX_CORE0];

#define OS_START_SEC_VAR_CLONE_512
#include "Os_MemMap.h"
extern P2VAR(volatile Os_ArchCsaType, AUTOMATIC, OS_VAR) Os_Csas;
#define OS_STOP_SEC_VAR_CLONE_512
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"

extern P2VAR(uint32, AUTOMATIC, OS_VAR) Os_ArchMasterSp_New;
extern VAR(uint32, OS_VAR) Os_ArchMasterSp_ARRAY[20];

extern P2VAR(uint32, AUTOMATIC, OS_VAR) Os_ArchTopStkPtr;
extern VAR(volatile uint32, OS_VAR) Os_ArchTempSp;
extern VAR(volatile uint32, OS_VAR) Os_ArchControl;
extern P2VAR(uint32, AUTOMATIC, OS_VAR) Os_TaskCBExt;
extern P2VAR(uint32, AUTOMATIC, OS_VAR) Os_IsrNestPcxStack;
extern P2CONST(OS_ISR_ADDR, AUTOMATIC, OS_VAR) Os_IsrDAddr;
extern P2CONST(OS_TASK_ADDR, AUTOMATIC, OS_VAR) Os_TaskDAddr;
#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
#endif
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

extern uint32 IntcOsIsrVectorTable[256];
extern VAR(uint32, OS_VAR)    Os_IsrIPSR[CFG_ISR_MAX_CORE0];

#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
extern VAR(volatile uint32, OS_VAR) Os_TprotTerminateIsr;
extern VAR(volatile uint32, OS_VAR) Os_TprotTerminateTask;
#endif

#if (CFG_ISR_MAX > 0U)
extern VAR(uint32, OS_VAR) Os_IsrNestPcxStackCore0[CFG_ISR_MAX_CORE0];

extern VAR(Os_CallLevelType, OS_VAR) Os_SaveLevelISR1;
#endif

/*=======[E X T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
extern FUNC(Os_IPLType, OS_CODE) Os_ArchGetIpl(void);
extern FUNC(void, OS_CODE) Os_ArchSetIpl(Os_IPLType ipl, Os_IsrDescriptionType isrdesc);
extern FUNC(void, OS_CODE) Os_ArchSuspendInt(P2VAR(Os_ArchMsrType, AUTOMATIC, OS_VAR) msr);
extern FUNC(void, OS_CODE) Os_ArchRestoreInt(Os_ArchMsrType msr);
extern FUNC(void, OS_CODE) Os_ArchInitCPU(void);
extern FUNC(void, OS_CODE) Os_ArchFirstEnterTask(void);
extern FUNC(void, OS_CODE) Os_ArchStartScheduler(void);
extern FUNC(void, OS_CODE) Os_ArchDispatch(void);
extern FUNC(void, OS_CODE) Os_ArchDispatch_ISR(void);

/* Shell protection */
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
extern FUNC(void, OS_CODE) Os_ArchSyscall(void);
extern FUNC(Os_CPUModeType, OS_CODE) Os_GetCpuMode(void);
extern FUNC(void, OS_CODE) SVC_Handler(void);
#endif

extern FUNC(void, OS_CODE) Reset_Handler(void);
extern FUNC(void, OS_CODE) HardFault_Handler(void);
extern FUNC(void, OS_CODE) UsageFault_Handler(void);
extern FUNC(void, OS_CODE) BusFault_Handler(void);
extern FUNC(void, OS_CODE) NMI_Handler(void);
extern FUNC(void, OS_CODE) Os_IntHandler(void);
extern FUNC(void, OS_CODE) PendSV_Handler(void);
extern FUNC(void, OS_CODE) TERMINATEISR_ISR(void);
extern FUNC(void, OS_CODE) Os_SetCpuMode(Os_CPUModeType mode);
extern FUNC(void, OS_CODE) Os_TaskSchedule(void);
/* Memory protection. */
#if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
extern FUNC(void, OS_CODE) Os_ArchInitKnMemMap(void);
extern FUNC(void, OS_CODE) Os_ArchSetTaskMemMap(TaskType TaskId, ApplicationType HostAppId, uint32 isTrusted);
extern FUNC(void, OS_CODE) Os_ArchSetIsrMemMap(TaskType IsrId, ApplicationType HostAppId, uint32 isTrusted);
extern FUNC(void, OS_CODE) Os_ArchMpDefaultConfigSwitch(void);

#define Os_RaisePrivilege() Os_ArchSyscall()
#define Os_LowerPrivilege() Os_SetCpuMode(OS_CPUMODE_USER0)

#if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)

extern VAR(uint16, OS_VAR) HardFault_Flag;
/* Memory Protection Set */

#else
#define OS_ARCH_API_DEFINE()
#define OS_ARCH_API_ENTRY()
#define OS_ARCH_API_EXIT()
#endif
#endif
extern VAR(uint32, OS_VAR)                         Os_IsrTempIPSR;
/* Time protection */
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
extern FUNC(void, OS_CODE) Os_ArchDisableAllInt_ButTimingProtInt(void);
extern FUNC(void, OS_CODE) Os_ArchEnableAllInt_ButTimingProtInt(void);
#endif /* #if (TRUE == CFG_TIMING_PROTECTION_ENABLE) */

extern FUNC(void, OS_CODE) Os_ArchInitIntPrio(void);

#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
#if (CFG_ISR_MAX > 0)
extern FUNC(void, OS_CODE) Os_ArchDisableIntInApp(P2CONST(Os_ApplicationCfgType, AUTOMATIC, OS_VAR) posCurAppCfg);
extern FUNC(void, OS_CODE) Os_ArchAppTerminateIsrProc(Os_IsrType OsIsrID);
#endif
extern FUNC(void, OS_CODE) Os_ArchAppTerminateTaskProc(Os_TaskType OsTaskID);
#endif

extern uint32 Os_CmpSwapW(uint32* address, uint32 compareVal, uint32 exchangedVal);
extern FUNC(void, OS_CODE) Os_InterruptInstall(uint8 id, uint8 prio, uint32 srcType, Os_isrhnd isrProc);
extern FUNC(void, OS_CODE) Os_InterruptUnload(uint8 id, uint8 prio, uint32 srcType, Os_isrhnd isrProc);
extern FUNC(Os_CoreIdType, OS_CODE) Os_ArchGetCoreID(void);
extern FUNC(void, OS_CODE) Os_ArchStartCore(Os_CoreIdType coreId);
extern FUNC(Os_CoreModeType, OS_CODE) Os_GetCoreMode(Os_CoreIdType core);
extern FUNC(boolean, OS_CODE) Os_SetCoreMode(Os_CoreIdType core, Os_CoreModeType coreMode);
extern FUNC(void, OS_CODE) FPU_AutoStoreFunctionClose(void);
extern uint32 getControlValue(void);
extern FUNC(uint32, OS_CODE) Os_GetIsrIPSR(void);
extern FUNC(void, OS_CODE) MSCM_MSI0_IRQHandler(void);
extern FUNC(void, OS_CODE) MSCM_MSI2_IRQHandler(void);
extern void STIM0_ClearStatusFlags(void);
extern FUNC(void, OS_CODE_FAST) Terminate_ISR(void);
/*============[STACK CHECK]=====================*/
#define IF_STACK_CHECK_ENTER_ISR1_FROM_TASK()                                                                      \
    if ((OS_STACK_FILL_PATTERN != (*(StackPtr))) || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)1))) \
        || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)2)))                                          \
        || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)3))))
#define IF_STACK_CHECK_ENTER_ISR1_FROM_ISR2()                                                                      \
    if ((OS_STACK_FILL_PATTERN != (*(StackPtr))) || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)1))) \
        || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)2)))                                          \
        || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)3))))
#define IF_STACK_CHECK_ENTER_ISR1_FROM_ISR1()                                                                      \
    if ((OS_STACK_FILL_PATTERN != (*(StackPtr))) || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)1))) \
        || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)2)))                                          \
        || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)3))))
#define IF_STACK_CHECK_EXIT_ISR1()                                                                                 \
    if ((OS_STACK_FILL_PATTERN != (*(StackPtr))) || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)1))) \
        || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)2)))                                          \
        || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)3))))
#define IF_STACK_CHECK_ENTER_ISR2_FORM_TASK()                                                                      \
    if ((OS_STACK_FILL_PATTERN != (*(StackPtr))) || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)1))) \
        || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)2)))                                          \
        || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)3))))
#define IF_STACK_CHECK_ENTER_ISR2_FORM_ISR2()                                                                      \
    if ((OS_STACK_FILL_PATTERN != (*(StackPtr))) || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)1))) \
        || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)2)))                                          \
        || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)3))))
#define IF_STACK_CHECK_EXIT_ISR2()                                                                                 \
    if ((OS_STACK_FILL_PATTERN != (*(StackPtr))) || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)1))) \
        || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)2)))                                          \
        || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)3))))
#define IF_STACK_CHECK_SWITCH_TASK()                                                                               \
    if ((OS_STACK_FILL_PATTERN != (*(StackPtr))) || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)1))) \
        || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)2)))                                          \
        || (OS_STACK_FILL_PATTERN != (*(StackPtr + (Os_StackDataType)3))))
#define OS_FILL_SAFET_STACK()                                 \
    {                                                         \
        *ptr = OS_STACK_FILL_PATTERN;                         \
        *(ptr + (Os_StackDataType)1) = OS_STACK_FILL_PATTERN; \
        *(ptr + (Os_StackDataType)2) = OS_STACK_FILL_PATTERN; \
        *(ptr + (Os_StackDataType)3) = OS_STACK_FILL_PATTERN; \
    }

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /* #ifndef OS_PROCESSOR_H */
/*=======[E N D   O F   F I L E]==============================================*/
