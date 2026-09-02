/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file vector.S
 * @brief 
 * 
 */


    .section .isr_vector, "a"
    .align 2
    .thumb
    .globl  IVT_Table
IVT_Table:
    .long   STACK_end       /* Top of Stack */
    .long   Reset_Handler   /* Reset Handler */
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   NMI_Handler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   HardFault_Handler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MemManage_Handler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   BusFault_Handler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   UsageFault_Handler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   SVC_Handler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DebugMon_Handler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   PendSV_Handler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   SysTick_Handler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DMA0_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DMA1_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DMA2_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DMA3_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DMA4_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DMA5_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DMA6_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DMA7_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DMA8_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DMA9_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DMA10_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DMA11_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DMA12_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DMA13_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DMA14_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DMA15_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DMA_Error_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   FPU_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   EFM_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   EFM_Error_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   PCU_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   EFM_Ecc_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   Wdg_Mld_Isr
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   I2C0_Master_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   I2C0_Slave_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   SPI0_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   SPI1_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   SPI2_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   I2C1_Master_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   LINFlexD0_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   LINFlexD1_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   LINFlexD2_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   ADC0_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   ACMP0_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   EMU_SB_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   EMU_DB_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   RTC_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   RTC_Seconds_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   pTMR_Ch0_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   pTMR_Ch1_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   pTMR_Ch2_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   pTMR_Ch3_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   PTU0_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   SCU_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   lpTMR0_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   GPIOA_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   GPIOB_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   GPIOC_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   GPIOD_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   GPIOE_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN0_ORed_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN0_Error_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN0_Wake_Up_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN0_ORed_0_15_MB_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN0_ORed_16_31_MB_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN0_ORed_32_47_MB_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN0_ORed_48_63_MB_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN1_ORed_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN1_Error_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN1_Wake_Up_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN1_ORed_0_15_MB_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN1_ORed_16_31_MB_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN2_ORed_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN2_Error_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN2_Wake_Up_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN2_ORed_0_15_MB_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN2_ORed_16_31_MB_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR0_Ch0_Ch1_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR0_Ch2_Ch3_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR0_Ch4_Ch5_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR0_Ch6_Ch7_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR0_Fault_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR0_Ovf_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR1_Ch0_Ch1_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR1_Ch2_Ch3_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR1_Ch4_Ch5_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR1_Ch6_Ch7_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR1_Fault_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR1_Ovf_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR2_Ch0_Ch1_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR2_Ch2_Ch3_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR2_Ch4_Ch5_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR2_Ch6_Ch7_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR2_Fault_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR2_Ovf_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR3_Ch0_Ch1_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR3_Ch2_Ch3_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR3_Ch4_Ch5_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR3_Ch6_Ch7_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR3_Fault_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR3_Ovf_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   TRNG_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   HCU_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   TMR0_Ch0_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   TMR0_Ch1_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   TMR0_Ch2_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   TMR0_Ch3_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   SPI3_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   SENT0_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   WKU_IRQHandler
#endif
