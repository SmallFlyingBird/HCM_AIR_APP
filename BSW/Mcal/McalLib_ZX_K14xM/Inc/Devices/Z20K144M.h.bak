/**************************************************************************************************/
/**
 * @file      : Z20K144M.h
 * @brief     : Z20K144M device header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef Z20K144M_H
#define Z20K144M_H

#include "Platform_Types.h"

#define Z20K144M_H_VENDOR_ID                   0x00B3U
#define Z20K144M_H_AR_RELEASE_MAJOR_VERSION    4U
#define Z20K144M_H_AR_RELEASE_MINOR_VERSION    6U
#define Z20K144M_H_AR_RELEASE_REVISION_VERSION 0U
#define Z20K144M_H_SW_MAJOR_VERSION            1U
#define Z20K144M_H_SW_MINOR_VERSION            2U
#define Z20K144M_H_SW_PATCH_VERSION            1U

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if ((Z20K144M_H_AR_RELEASE_MAJOR_VERSION != PLATFORM_TYPES_AR_RELEASE_MAJOR_VERSION) ||       \
         (Z20K144M_H_AR_RELEASE_MINOR_VERSION != PLATFORM_TYPES_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of Z20K144M.h and Platform_Types.h and are different"
    #endif
#endif

#ifndef IO
    #define RO volatile const /*!< Read only permission */
    #define WO volatile       /*!< Write only permission */
    #define RW volatile       /*!< Read/Write permission */
#endif

/**
 * @brief IRQ Number Definition
 */
typedef enum IRQn
{
    /******  Cortex-M4F Processor IRQ Numbers *******************************/
    NMI_IRQn = -14,            /*!< 2 Non Maskable Interrupt */
    HardFalut_IRQn = -13,      /*!< 3 Hardfault Interrupt */
    MemManageFault_IRQn = -12, /*!< 4 memory manage fault Interrupt */
    BusFault_IRQn = -11,       /*!< 5 bus fault Interrupt */
    UsageFault_IRQn = -10,     /*!< 6 usage fault Interrupt */
    SVCall_IRQn = -5,          /*!< 11 SV Call Interrupt */
    DebugMonitor_IRQn = -4,    /*!< 12 debug monitor Interrupt */
    PendSV_IRQn = -2,          /*!< 14 Pend SV Interrupt  */
    SysTick_IRQn = -1,         /*!< 15 System Tick Interrupt  */

    /******  specific IRQ Numbers *************************************/
    DMA_Ch0_IRQn = 0,            /*!< DMA channel 0 transfer complete Interrupt */
    DMA_Ch1_IRQn = 1,            /*!< DMA channel 1 transfer complete Interrupt */
    DMA_Ch2_IRQn = 2,            /*!< DMA channel 2 transfer complete Interrupt */
    DMA_Ch3_IRQn = 3,            /*!< DMA channel 3 transfer complete Interrupt */
    DMA_Ch4_IRQn = 4,            /*!< DMA channel 4 transfer complete Interrupt */
    DMA_Ch5_IRQn = 5,            /*!< DMA channel 5 transfer complete Interrupt */
    DMA_Ch6_IRQn = 6,            /*!< DMA channel 6 transfer complete Interrupt */
    DMA_Ch7_IRQn = 7,            /*!< DMA channel 7 transfer complete Interrupt */
    DMA_Ch8_IRQn = 8,            /*!< DMA channel 8 transfer complete Interrupt */
    DMA_Ch9_IRQn = 9,            /*!< DMA channel 9 transfer complete Interrupt */
    DMA_Ch10_IRQn = 10,          /*!< DMA channel 10 transfer complete Interrupt */
    DMA_Ch11_IRQn = 11,          /*!< DMA channel 11 transfer complete Interrupt */
    DMA_Ch12_IRQn = 12,          /*!< DMA channel 12 transfer complete Interrupt */
    DMA_Ch13_IRQn = 13,          /*!< DMA channel 13 transfer complete Interrupt */
    DMA_Ch14_IRQn = 14,          /*!< DMA channel 14 transfer complete Interrupt */
    DMA_Ch15_IRQn = 15,          /*!< DMA channel 15 transfer complete Interrupt */
    DMA_Err_IRQn = 16,           /*!< DMA channel 0-15 error Interrupt */
    FLASH_CmdComplete_IRQn = 17, /*!< flash command complete Interrupt */
    FLASH_Ecc_IRQn = 18,         /*!< flash multi-bit or single-bit ECC Interrupt */
    PMU_IRQn = 19,               /*!< PMU Interrupt */
    WDOG_IRQn = 20,              /*!< watchdog Interrupt */
    EWDT_IRQn = 21,              /*!< external watchdog monitor Interrupt */
    SRMC_IRQn = 22,              /*!< system reset and mode control Interrupt */
    I2C0_IRQn = 23,              /*!< I2C 0 Interrupt */
    I2C1_IRQn = 24,              /*!< I2C 1 Interrupt */
    SPI0_Txe_IRQn = 25,          /*!< SPI 0 TXE Interrupt */
    SPI0_Txo_IRQn = 26,          /*!< SPI 0 TXO Interrupt */
    SPI0_Rxf_IRQn = 27,          /*!< SPI 0 RXF Interrupt */
    SPI0_Rxo_IRQn = 28,          /*!< SPI 0 RXO Interrupt */
    SPI0_Rxu_IRQn = 29,          /*!< SPI 0 RXU Interrupt */
    Reserved30_IRQn = 30,        /*!< Reserved interrupt */
    SPI1_Txe_IRQn = 31,          /*!< SPI 1 TXE Interrupt */
    SPI1_Txo_IRQn = 32,          /*!< SPI 1 TXO Interrupt */
    SPI1_Rxf_IRQn = 33,          /*!< SPI 1 RXF Interrupt */
    SPI1_Rxo_IRQn = 34,          /*!< SPI 1 RXO Interrupt */
    SPI1_Rxu_IRQn = 35,          /*!< SPI 1 RXU Interrupt */
    Reserved36_IRQn = 36,        /*!< Reserved interrupt */
    SPI2_Txe_IRQn = 37,          /*!< SPI 2 TXE Interrupt */
    SPI2_Txo_IRQn = 38,          /*!< SPI 2 TXO Interrupt */
    SPI2_Rxf_IRQn = 39,          /*!< SPI 2 RXF Interrupt */
    SPI2_Rxo_IRQn = 40,          /*!< SPI 2 RXO Interrupt */
    SPI2_Rxu_IRQn = 41,          /*!< SPI 2 RXU Interrupt */
    Reserved42_IRQn = 42,        /*!< Reserved interrupt */
    SPI3_Txe_IRQn = 43,          /*!< SPI 3 TXE Interrupt */
    SPI3_Txo_IRQn = 44,          /*!< SPI 3 TXO Interrupt */
    SPI3_Rxf_IRQn = 45,          /*!< SPI 3 RXF Interrupt */
    SPI3_Rxo_IRQn = 46,          /*!< SPI 3 RXO Interrupt */
    SPI3_Rxu_IRQn = 47,          /*!< SPI 3 RXU Interrupt */
    Reserved48_IRQn = 48,        /*!< Reserved interrupt */
    UART0_IRQn = 49,             /*!< UART 0 Interrupt */
    UART1_IRQn = 50,             /*!< UART 1 Interrupt */
    UART2_IRQn = 51,             /*!< UART 2 Interrupt */
    UART3_IRQn = 52,             /*!< UART 3 Interrupt */
    UART4_IRQn = 53,             /*!< UART 4 Interrupt */
    UART5_IRQn = 54,             /*!< UART 5 Interrupt */
    CAN0_BusOff_IRQn = 55,       /*!< CAN 0 bus off/ bus off done Interrupt */
    CAN0_TxWarn_IRQn = 56,       /*!< CAN 0 TX warning Interrupt */
    CAN0_RxWarn_IRQn = 57,       /*!< CAN 0 RX warning Interrupt */
    CAN0_Err_IRQn = 58,          /*!< CAN 0 error Interrupt */
    CAN0_ErrFd_IRQn = 59,        /*!< CAN 0 error FD Interrupt */
    CAN0_PnWake_IRQn = 60,       /*!< CAN 0 PN wakeup Interrupt */
    CAN0_SelfWakeup_IRQn = 61,   /*!< CAN 0 self wakeup Interrupt */
    CAN0_Ecc_IRQn = 62,          /*!< CAN 0 ECC Interrupt */
    CAN0_Mb0To15_IRQn = 63,      /*!< CAN 0 message buffer 0-15 Interrupt */
    CAN0_Mb16To31_IRQn = 64,     /*!< CAN 0 message buffer 16-31 Interrupt */
    CAN0_Mb32To47_IRQn = 65,     /*!< CAN 0 message buffer 32-47 Interrupt */
    CAN0_Mb48To63_IRQn = 66,     /*!< CAN 0 message buffer 48-63 Interrupt */
    CAN1_BusOff_IRQn = 67,       /*!< CAN 1 bus off/ bus off done Interrupt */
    CAN1_TxWarn_IRQn = 68,       /*!< CAN 1 TX warning Interrupt */
    CAN1_RxWarn_IRQn = 69,       /*!< CAN 1 RX warning Interrupt */
    CAN1_Err_IRQn = 70,          /*!< CAN 1 error Interrupt */
    CAN1_ErrFd_IRQn = 71,        /*!< CAN 1 error FD Interrupt */
    CAN1_PnWake_IRQn = 72,       /*!< CAN 1 PN wakeup Interrupt */
    CAN1_SelfWakeup_IRQn = 73,   /*!< CAN 1 self wakeup Interrupt */
    CAN1_Ecc_IRQn = 74,          /*!< CAN 1 ECC Interrupt */
    CAN1_Mb0To15_IRQn = 75,      /*!< CAN 1 message buffer 0-15 Interrupt */
    CAN1_Mb16To31_IRQn = 76,     /*!< CAN 1 message buffer 16-31 Interrupt */
    CAN1_Mb32To47_IRQn = 77,     /*!< CAN 1 message buffer 32-47 Interrupt */
    CAN1_Mb48To63_IRQn = 78,     /*!< CAN 1 message buffer 48-63 Interrupt */
    CAN2_BusOff_IRQn = 79,       /*!< CAN 2 bus off/ bus off done Interrupt */
    CAN2_TxWarn_IRQn = 80,       /*!< CAN 2 TX warning Interrupt */
    CAN2_RxWarn_IRQn = 81,       /*!< CAN 2 RX warning Interrupt */
    CAN2_Err_IRQn = 82,          /*!< CAN 2 error Interrupt */
    CAN2_ErrFd_IRQn = 83,        /*!< CAN 2 error FD Interrupt */
    CAN2_PnWake_IRQn = 84,       /*!< CAN 2 PN wakeup Interrupt */
    CAN2_SelfWakeup_IRQn = 85,   /*!< CAN 2 self wakeup Interrupt */
    CAN2_Ecc_IRQn = 86,          /*!< CAN 2 ECC Interrupt */
    CAN2_Mb0To15_IRQn = 87,      /*!< CAN 2 message buffer 0-15 Interrupt */
    CAN2_Mb16To31_IRQn = 88,     /*!< CAN 2 message buffer 16-31 Interrupt */
    CAN2_Mb32To47_IRQn = 89,     /*!< CAN 2 message buffer 32-47 Interrupt */
    CAN2_Mb48To63_IRQn = 90,     /*!< CAN 2 message buffer 48-63 Interrupt */
    CAN3_BusOff_IRQn = 91,       /*!< CAN 3 bus off/ bus off done Interrupt */
    CAN3_TxWarn_IRQn = 92,       /*!< CAN 3 TX warning Interrupt */
    CAN3_RxWarn_IRQn = 93,       /*!< CAN 3 RX warning Interrupt */
    CAN3_Err_IRQn = 94,          /*!< CAN 3 error Interrupt */
    CAN3_ErrFd_IRQn = 95,        /*!< CAN 3 error FD Interrupt */
    CAN3_PnWake_IRQn = 96,       /*!< CAN 3 PN wakeup Interrupt */
    CAN3_SelfWakeup_IRQn = 97,   /*!< CAN 3 self wakeup Interrupt */
    CAN3_Ecc_IRQn = 98,          /*!< CAN 3 ECC Interrupt */
    CAN3_Mb0To15_IRQn = 99,      /*!< CAN 3 message buffer 0-15 Interrupt */
    CAN3_Mb16To31_IRQn = 100,    /*!< CAN 3 message buffer 16-31 Interrupt */
    CAN3_Mb32To47_IRQn = 101,    /*!< CAN 3 message buffer 32-47 Interrupt */
    CAN3_Mb48To63_IRQn = 102,    /*!< CAN 3 message buffer 48-63 Interrupt */
    Reserved103_IRQn = 103,      /*!< Reserved103 */
    Reserved104_IRQn = 104,      /*!< Reserved104 */
    Reserved105_IRQn = 105,      /*!< Reserved105 */
    Reserved106_IRQn = 106,      /*!< Reserved106 */
    Reserved107_IRQn = 107,      /*!< Reserved107 */
    Reserved108_IRQn = 108,      /*!< Reserved108 */
    Reserved109_IRQn = 109,      /*!< Reserved109 */
    Reserved110_IRQn = 110,      /*!< Reserved110 */
    Reserved111_IRQn = 111,      /*!< Reserved111 */
    Reserved112_IRQn = 112,      /*!< Reserved112 */
    Reserved113_IRQn = 113,      /*!< Reserved113 */
    Reserved114_IRQn = 114,      /*!< Reserved114 */
    Reserved115_IRQn = 115,      /*!< Reserved115 */
    Reserved116_IRQn = 116,      /*!< Reserved116 */
    Reserved117_IRQn = 117,      /*!< Reserved117 */
    Reserved118_IRQn = 118,      /*!< Reserved118 */
    Reserved119_IRQn = 119,      /*!< Reserved119 */
    Reserved120_IRQn = 120,      /*!< Reserved120 */
    Reserved121_IRQn = 121,      /*!< Reserved121 */
    Reserved122_IRQn = 122,      /*!< Reserved122 */
    Reserved123_IRQn = 123,      /*!< Reserved123 */
    Reserved124_IRQn = 124,      /*!< Reserved124 */
    Reserved125_IRQn = 125,      /*!< Reserved125 */
    Reserved126_IRQn = 126,      /*!< Reserved126 */
    Reserved127_IRQn = 127,      /*!< Reserved127 */
    Reserved128_IRQn = 128,      /*!< Reserved128 */
    Reserved129_IRQn = 129,      /*!< Reserved129 */
    Reserved130_IRQn = 130,      /*!< Reserved130 */
    Reserved131_IRQn = 131,      /*!< Reserved131 */
    Reserved132_IRQn = 132,      /*!< Reserved132 */
    Reserved133_IRQn = 133,      /*!< Reserved133 */
    Reserved134_IRQn = 134,      /*!< Reserved134 */
    Reserved135_IRQn = 135,      /*!< Reserved135 */
    Reserved136_IRQn = 136,      /*!< Reserved136 */
    Reserved137_IRQn = 137,      /*!< Reserved137 */
    Reserved138_IRQn = 138,      /*!< Reserved138 */
    Reserved139_IRQn = 139,      /*!< Reserved139 */
    Reserved140_IRQn = 140,      /*!< Reserved140 */
    Reserved141_IRQn = 141,      /*!< Reserved141 */
    Reserved142_IRQn = 142,      /*!< Reserved142 */
    Reserved143_IRQn = 143,      /*!< Reserved143 */
    Reserved144_IRQn = 144,      /*!< Reserved144 */
    Reserved145_IRQn = 145,      /*!< Reserved145 */
    Reserved146_IRQn = 146,      /*!< Reserved146 */
    Reserved147_IRQn = 147,      /*!< Reserved147 */
    Reserved148_IRQn = 148,      /*!< Reserved148 */
    Reserved149_IRQn = 149,      /*!< Reserved149 */
    Reserved150_IRQn = 150,      /*!< Reserved150 */
    Reserved151_IRQn = 151,      /*!< Reserved151 Interrupt */
    Reserved152_IRQn = 152,      /*!< Reserved152 Interrupt */
    Reserved153_IRQn = 153,      /*!< Reserved153 Interrupt */
    TIM0_Ch_IRQn = 154,          /*!< TIM0 CH Interrupt */
    TIM0_Fault_IRQn = 155,       /*!< TIM0 Fault Interrupt */
    TIM0_Overflow_IRQn = 156,    /*!< TIM0 overflow Interrupt */
    TIM0_Rlfl_IRQn = 157,        /*!< TIM0 Rlfl Interrupt */
    TIM1_Ch_IRQn = 158,          /*!< TIM1 CH Interrupt */
    TIM1_Fault_IRQn = 159,       /*!< TIM1 Fault Interrupt */
    TIM1_Overflow_IRQn = 160,    /*!< TIM1 overflow Interrupt */
    TIM1_Rlfl_IRQn = 161,        /*!< TIM1 Rlfl Interrupt */
    TIM2_Ch_IRQn = 162,          /*!< TIM2 CH Interrupt */
    TIM2_Fault_IRQn = 163,       /*!< TIM2 Fault Interrupt */
    TIM2_Overflow_IRQn = 164,    /*!< TIM2 overflow Interrupt */
    TIM2_Rlfl_IRQn = 165,        /*!< TIM2 Rlfl Interrupt */
    TIM3_Ch_IRQn = 166,          /*!< TIM3 CH Interrupt */
    TIM3_Fault_IRQn = 167,       /*!< TIM3 Fault Interrupt */
    TIM3_Overflow_IRQn = 168,    /*!< TIM3 overflow Interrupt */
    TIM3_Rlfl_IRQn = 169,        /*!< TIM3 Rlfl Interrupt */
    TDG0_Tco_IRQn = 170,         /*!< TDG0 TCO Interrupt */
    TDG0_Err_IRQn = 171,         /*!< TDG0 ERR Interrupt */
    TDG1_Tco_IRQn = 172,         /*!< TDG1 TCO Interrupt */
    TDG1_Err_IRQn = 173,         /*!< TDG1 ERR Interrupt */
    I2S0_IRQn = 174,             /*!< I2S0 Interrupt */
    Reserved175_IRQn = 175,      /*!< Reserved175 */
    PORTA_IRQn = 176,            /*!< port A Interrupt */
    PORTB_IRQn = 177,            /*!< port B Interrupt */
    PORTC_IRQn = 178,            /*!< port C Interrupt */
    PORTD_IRQn = 179,            /*!< port D Interrupt */
    PORTE_IRQn = 180,            /*!< port E Interrupt */
    STIM_IRQn = 181,             /*!< STIM Interrupt */
    RTC_Alarm_IRQn = 182,        /*!< RTC alarm Interrupt */
    RTC_Second_IRQn = 183,       /*!< RTC second Interrupt */
    AES_IRQn = 184,              /*!< AES Interrupt */
    TRNG_IRQn = 185,             /*!< TRNG Interrupt */
    CMU0_IRQn = 186,             /*!< CMU0 Interrupt */
    CMU1_IRQn = 187,             /*!< CMU1 Interrupt */
    CMU2_IRQn = 188,             /*!< CMU2 Interrupt */
    SERU_ParityErr_IRQn = 189,   /*!< SERU parity error Interrupt */
    SERU_ChErr_IRQn = 190,       /*!< SERU channel error Interrupt */
    SCC_IRQn = 191,              /*!< SCC Interrupt */
    MCPWM0_Ch_IRQn = 192,        /*!< MCPWM0 CH Interrupt */
    MCPWM0_Fault_IRQn = 193,     /*!< MCPWM0 fault Interrupt */
    MCPWM0_Overflow_IRQn = 194,  /*!< MCPWM0 overflow Interrupt */
    MCPWM0_Rlfl_IRQn = 195,      /*!< MCPWM0 Rlfl Interrupt */
    MCPWM1_Ch_IRQn = 196,        /*!< MCPWM1 CH Interrupt */
    MCPWM1_Fault_IRQn = 197,     /*!< MCPWM1 fault Interrupt */
    MCPWM1_Overflow_IRQn = 198,  /*!< MCPWM1 overflow Interrupt */
    MCPWM1_Rlfl_IRQn = 199,      /*!< MCPWM1 Rlfl Interrupt */
    ADC0_IRQn = 200,             /*!< ADC0 Interrupt */
    ADC1_IRQn = 201,             /*!< ADC1 Interrupt */
    CMP_IRQn = 202,              /*!< CMP Interrupt */
    FPU_Err_IRQn = 203,          /*!< FPU error Interrupt */
    CACHE_Err_IRQn = 204,        /*!< CACHE error Interrupt */
} IRQn_Type;

/*Peripheral Base Address*/
#define FLASH_CODE_BASE_ADDR ((uint32)0x00000000U) /*!< program/Code flash base address */
#define FLASH_CODE_END_ADDR  ((uint32)0x0007FFFFU) /*!< program/Code flash end address */
#define FLASH_DATA_BASE_ADDR ((uint32)0x01000000U) /*!< Data flash base address */
#define FLASH_DATA_END_ADDR  ((uint32)0x0101FFFFU) /*!< Data flash end address */
#define FLASH_IFR_BASE_ADDR  ((uint32)0x02000000U) /*!< flash IFR base address */
#define FLASH_IFR_END_ADDR   ((uint32)0x02007FFFU) /*!< flash IFR end address */
#define SRAMU_BASE_ADDR      ((uint32)0x20000000U) /*!< SRAMU base address */
#define SRAMU_END_ADDR       ((uint32)0x2000FFFFU) /*!< SRAMU end address */
#define PERIPHERAL_BASE_ADDR ((uint32)0x40000000U) /*!< Peripheral area base address */
#define AIPS0_BASE_ADDR      ((uint32)0x40000000U) /*!< AIPS0 base address */

#define PRI_PERI_BUS_BASE_ADDR ((uint32)0xE0000000U) /*!< private Peripheral base address */

#define DMA_BASE_ADDR (PERIPHERAL_BASE_ADDR + 0x8000UL) /*!< DMA controller base address */
#define DMAMUX_BASE_ADDR                                                                           \
    (PERIPHERAL_BASE_ADDR + 0x9000UL) /*!< DMA channel Multiplexer base address */
#define SMPU_BASE_ADDR    (PERIPHERAL_BASE_ADDR + 0xA000UL)  /*!< SMPU base address */
#define EIRU_BASE_ADDR    (PERIPHERAL_BASE_ADDR + 0xB000UL)  /*!< EIRU base address */
#define TIM0_BASE_ADDR    (PERIPHERAL_BASE_ADDR + 0xC000UL)  /*!< TIM0 base address */
#define TIM1_BASE_ADDR    (PERIPHERAL_BASE_ADDR + 0xD000UL)  /*!< TIM1 base address */
#define MCPWM0_BASE_ADDR  (PERIPHERAL_BASE_ADDR + 0xE000UL)  /*!< MCPWM0 base address */
#define TDG0_BASE_ADDR    (PERIPHERAL_BASE_ADDR + 0xF000UL)  /*!< TDG0 base address */
#define TIM2_BASE_ADDR    (PERIPHERAL_BASE_ADDR + 0x18000UL) /*!< TIM2 base address */
#define TIM3_BASE_ADDR    (PERIPHERAL_BASE_ADDR + 0x19000UL) /*!< TIM3 base address */
#define MCPWM1_BASE_ADDR  (PERIPHERAL_BASE_ADDR + 0x1A000UL) /*!< MCPWM1 base address */
#define TDG1_BASE_ADDR    (PERIPHERAL_BASE_ADDR + 0x1B000UL) /*!< TDG1 base address */
#define FLASHC_BASE_ADDR  (PERIPHERAL_BASE_ADDR + 0x20000UL) /*!< flash controller base address */
#define CAN0_BASE_ADDR    (PERIPHERAL_BASE_ADDR + 0x24000UL) /*!< CAN0 base address */
#define CAN1_BASE_ADDR    (PERIPHERAL_BASE_ADDR + 0x25000UL) /*!< CAN1 base address */
#define ADC1_BASE_ADDR    (PERIPHERAL_BASE_ADDR + 0x27000UL) /*!< ADC1 base address */
#define SPI0_BASE_ADDR    (PERIPHERAL_BASE_ADDR + 0x2C000UL) /*!< SPI0 base address */
#define SPI1_BASE_ADDR    (PERIPHERAL_BASE_ADDR + 0x2D000UL) /*!< SPI1 base address */
#define SPI2_BASE_ADDR    (PERIPHERAL_BASE_ADDR + 0x30000UL) /*!< SPI2 base address */
#define SPI3_BASE_ADDR    (PERIPHERAL_BASE_ADDR + 0x31000UL) /*!< SPI3 base address */
#define CRC_BASE_ADDR     (PERIPHERAL_BASE_ADDR + 0x32000UL) /*!< CRC base address */
#define AES_BASE_ADDR     (PERIPHERAL_BASE_ADDR + 0x33000UL) /*!< AES base address */
#define TRNG_BASE_ADDR    (PERIPHERAL_BASE_ADDR + 0x34000UL) /*!< TRNG base address */
#define CAN2_BASE_ADDR    (PERIPHERAL_BASE_ADDR + 0x38000UL) /*!< CAN2 base address */
#define CAN3_BASE_ADDR    (PERIPHERAL_BASE_ADDR + 0x39000UL) /*!< CAN3 base address */
#define ADC0_BASE_ADDR    (PERIPHERAL_BASE_ADDR + 0x3B000UL) /*!< ADC0 base address */
#define CMU0_BASE_ADDR    (PERIPHERAL_BASE_ADDR + 0x3E000UL) /*!< CMU0 base address */
#define STIM_BASE_ADDR    (PERIPHERAL_BASE_ADDR + 0x40000UL) /*!< STIM base address */
#define CMU1_BASE_ADDR    (PERIPHERAL_BASE_ADDR + 0x42000UL) /*!< CMU1 base address */
#define CMU2_BASE_ADDR    (PERIPHERAL_BASE_ADDR + 0x43000UL) /*!< CMU2 base address */
#define SCM_BASE_ADDR     (PERIPHERAL_BASE_ADDR + 0x48000UL) /*!< SCM base address */
#define PORTA_BASE_ADDR   (PERIPHERAL_BASE_ADDR + 0x49000UL) /*!< PORTA multiplexing base address */
#define PORTB_BASE_ADDR   (PERIPHERAL_BASE_ADDR + 0x4A000UL) /*!< PORTB multiplexing base address */
#define PORTC_BASE_ADDR   (PERIPHERAL_BASE_ADDR + 0x4B000UL) /*!< PORTC multiplexing base address */
#define PORTD_BASE_ADDR   (PERIPHERAL_BASE_ADDR + 0x50000UL) /*!< PORTD multiplexing base address */
#define PORTE_BASE_ADDR   (PERIPHERAL_BASE_ADDR + 0x51000UL) /*!< PORTE multiplexing base address */
#define WDOG_BASE_ADDR    (PERIPHERAL_BASE_ADDR + 0x52000UL) /*!< WDOG base address */
#define I2S0_BASE_ADDR    (PERIPHERAL_BASE_ADDR + 0x54000UL) /*!< I2S0 base address */
#define I2C1_BASE_ADDR    (PERIPHERAL_BASE_ADDR + 0x58000UL) /*!< I2C1 base address */
#define EWDT_BASE_ADDR    (PERIPHERAL_BASE_ADDR + 0x61000UL) /*!< EWDT base address */
#define TMU_BASE_ADDR     (PERIPHERAL_BASE_ADDR + 0x63000UL) /*!< TMU base address */
#define SCC_BASE_ADDR     (PERIPHERAL_BASE_ADDR + 0x64000UL) /*!< SCC base address */
#define PARCC_BASE_ADDR   (PERIPHERAL_BASE_ADDR + 0x65000UL) /*!< PARCC base address */
#define I2C0_BASE_ADDR    (PERIPHERAL_BASE_ADDR + 0x66000UL) /*!< I2C0 base address */
#define UART0_BASE_ADDR   (PERIPHERAL_BASE_ADDR + 0x6A000UL) /*!< UART0 base address */
#define UART1_BASE_ADDR   (PERIPHERAL_BASE_ADDR + 0x6B000UL) /*!< UART1 base address */
#define UART2_BASE_ADDR   (PERIPHERAL_BASE_ADDR + 0x6C000UL) /*!< UART2 base address */
#define UART3_BASE_ADDR   (PERIPHERAL_BASE_ADDR + 0x70000UL) /*!< UART3 base address */
#define UART4_BASE_ADDR   (PERIPHERAL_BASE_ADDR + 0x71000UL) /*!< UART4 base address */
#define UART5_BASE_ADDR   (PERIPHERAL_BASE_ADDR + 0x72000UL) /*!< UART5 base address */
#define CMP_BASE_ADDR     (PERIPHERAL_BASE_ADDR + 0x73000UL) /*!< CMP base address */
#define RTC_BASE_ADDR     (PERIPHERAL_BASE_ADDR + 0x79000UL) /*!< RTC base address */
#define REGFILE_BASE_ADDR (PERIPHERAL_BASE_ADDR + 0x7C000UL) /*!< REGFILE base address */
#define PMU_BASE_ADDR     (PERIPHERAL_BASE_ADDR + 0x7D000UL) /*!< PMU base address */
#define SRMC_BASE_ADDR    (PERIPHERAL_BASE_ADDR + 0x7E000UL) /*!< SRMC base address */
#define SERU_BASE_ADDR    (PERIPHERAL_BASE_ADDR + 0x7F000UL) /*!< SERU base address */
#define GPIO_BASE_ADDR    ((uint32)0x400FF000)               /*!< GPIO base address */
#define GPIOA_BASE_ADDR   (GPIO_BASE_ADDR + 0x00UL)          /*!< GPIOA base address */
#define GPIOB_BASE_ADDR   (GPIO_BASE_ADDR + 0x40UL)          /*!< GPIOB base address */
#define GPIOC_BASE_ADDR   (GPIO_BASE_ADDR + 0x80UL)          /*!< GPIOC base address */
#define GPIOD_BASE_ADDR   (GPIO_BASE_ADDR + 0xC0UL)          /*!< GPIOD base address */
#define GPIOE_BASE_ADDR   (GPIO_BASE_ADDR + 0x100UL)         /*!< GPIOE base address */

/**
  @brief  Structure type to access the System Control and ID Register not in the SCB.
 */
typedef struct
{
    uint32    RESERVED0[1U];
    RO uint32 ICTR;  /*!< Offset: 0x004 (R/ )  Interrupt Controller Type Register */
    RW uint32 ACTLR; /*!< Offset: 0x008 (R/W)  Auxiliary Control Register */
} Z20_SCnSCBType;

/**
 * @brief  Structure type to access the System Control Block (SCB).
 */
typedef struct
{
    RO uint32 CPUID; /*!< Offset: 0x000 (R/ )  CPUID Base Register */
    RW uint32 ICSR;  /*!< Offset: 0x004 (R/W)  Interrupt Control and State Register */
    RW uint32 VTOR;  /*!< Offset: 0x008 (R/W)  Vector Table Offset Register */
    RW uint32 AIRCR; /*!< Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register */
    RW uint32 SCR;   /*!< Offset: 0x010 (R/W)  System Control Register */
    RW uint32 CCR;   /*!< Offset: 0x014 (R/W)  Configuration Control Register */
    RW uint8
        SHP[12U]; /*!< Offset: 0x018 (R/W)  System Handlers Priority Registers (4-7, 8-11, 12-15) */
    RW uint32 SHCSR;    /*!< Offset: 0x024 (R/W)  System Handler Control and State Register */
    RW uint32 CFSR;     /*!< Offset: 0x028 (R/W)  Configurable Fault Status Register */
    RW uint32 HFSR;     /*!< Offset: 0x02C (R/W)  HardFault Status Register */
    RW uint32 DFSR;     /*!< Offset: 0x030 (R/W)  Debug Fault Status Register */
    RW uint32 MMFAR;    /*!< Offset: 0x034 (R/W)  MemManage Fault Address Register */
    RW uint32 BFAR;     /*!< Offset: 0x038 (R/W)  BusFault Address Register */
    RW uint32 AFSR;     /*!< Offset: 0x03C (R/W)  Auxiliary Fault Status Register */
    RO uint32 PFR[2U];  /*!< Offset: 0x040 (R/ )  Processor Feature Register */
    RO uint32 DFR;      /*!< Offset: 0x048 (R/ )  Debug Feature Register */
    RO uint32 ADR;      /*!< Offset: 0x04C (R/ )  Auxiliary Feature Register */
    RO uint32 MMFR[4U]; /*!< Offset: 0x050 (R/ )  Memory Model Feature Register */
    RO uint32 ISAR[5U]; /*!< Offset: 0x060 (R/ )  Instruction Set Attributes Register */
    uint32    RESERVED0[5U];
    RW uint32 CPACR; /*!< Offset: 0x088 (R/W)  Coprocessor Access Control Register */
} Z20_SCBType;

/**
  @brief  Structure type to access the System Timer (SysTick).
 */
typedef struct
{
    RW uint32 CTRL;  /*!< Offset: 0x000 (R/W)  SysTick Control and Status Register */
    RW uint32 LOAD;  /*!< Offset: 0x004 (R/W)  SysTick Reload Value Register */
    RW uint32 VAL;   /*!< Offset: 0x008 (R/W)  SysTick Current Value Register */
    RO uint32 CALIB; /*!< Offset: 0x00C (R/ )  SysTick Calibration Register */
} Z20_SysTickType;

/**
 * @brief  Structure type to access the Nested Vectored Interrupt Controller (NVIC).
 */
typedef struct
{
    RW uint32 ISER[8U]; /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
    uint32    RESERVED0[24U];
    RW uint32 ICER[8U]; /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
    uint32    RSERVED1[24U];
    RW uint32 ISPR[8U]; /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
    uint32    RESERVED2[24U];
    RW uint32 ICPR[8U]; /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
    uint32    RESERVED3[24U];
    RW uint32 IABR[8U]; /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register */
    uint32    RESERVED4[56U];
    RW uint8  IP[240U]; /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
    uint32    RESERVED5[644U];
    WO uint32 STIR; /*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register */
} Z20_NVICType;

/**
  @brief  Structure type to access the Data Watchpoint and Trace Register (DWT).
 */
typedef struct
{
    RW uint32 CTRL;      /*!< Offset: 0x000 (R/W)  Control Register */
    RW uint32 CYCCNT;    /*!< Offset: 0x004 (R/W)  Cycle Count Register */
    RW uint32 CPICNT;    /*!< Offset: 0x008 (R/W)  CPI Count Register */
    RW uint32 EXCCNT;    /*!< Offset: 0x00C (R/W)  Exception Overhead Count Register */
    RW uint32 SLEEPCNT;  /*!< Offset: 0x010 (R/W)  Sleep Count Register */
    RW uint32 LSUCNT;    /*!< Offset: 0x014 (R/W)  LSU Count Register */
    RW uint32 FOLDCNT;   /*!< Offset: 0x018 (R/W)  Folded-instruction Count Register */
    RO uint32 PCSR;      /*!< Offset: 0x01C (R/ )  Program Counter Sample Register */
    RW uint32 COMP0;     /*!< Offset: 0x020 (R/W)  Comparator Register 0 */
    RW uint32 MASK0;     /*!< Offset: 0x024 (R/W)  Mask Register 0 */
    RW uint32 FUNCTION0; /*!< Offset: 0x028 (R/W)  Function Register 0 */
    uint32    RESERVED0[1U];
    RW uint32 COMP1;     /*!< Offset: 0x030 (R/W)  Comparator Register 1 */
    RW uint32 MASK1;     /*!< Offset: 0x034 (R/W)  Mask Register 1 */
    RW uint32 FUNCTION1; /*!< Offset: 0x038 (R/W)  Function Register 1 */
    uint32    RESERVED1[1U];
    RW uint32 COMP2;     /*!< Offset: 0x040 (R/W)  Comparator Register 2 */
    RW uint32 MASK2;     /*!< Offset: 0x044 (R/W)  Mask Register 2 */
    RW uint32 FUNCTION2; /*!< Offset: 0x048 (R/W)  Function Register 2 */
    uint32    RESERVED2[1U];
    RW uint32 COMP3;     /*!< Offset: 0x050 (R/W)  Comparator Register 3 */
    RW uint32 MASK3;     /*!< Offset: 0x054 (R/W)  Mask Register 3 */
    RW uint32 FUNCTION3; /*!< Offset: 0x058 (R/W)  Function Register 3 */
} Z20_DWTType;

/**
  @brief  Structure type to access the Core Debug Register (CoreDebug).
 */
typedef struct
{
    RW uint32 DHCSR; /*!< Offset: 0x000 (R/W)  Debug Halting Control and Status Register */
    WO uint32 DCRSR; /*!< Offset: 0x004 ( /W)  Debug Core Register Selector Register */
    RW uint32 DCRDR; /*!< Offset: 0x008 (R/W)  Debug Core Register Data Register */
    RW uint32 DEMCR; /*!< Offset: 0x00C (R/W)  Debug Exception and Monitor Control Register */
} Z20_CoreDebugType;

/**
  @brief  Structure type to access the Floating Point Unit (FPU).
 */
typedef struct
{
    uint32    RESERVED0[1U];
    RW uint32 FPCCR;  /*!< Offset: 0x004 (R/W)  Floating-Point Context Control Register */
    RW uint32 FPCAR;  /*!< Offset: 0x008 (R/W)  Floating-Point Context Address Register */
    RW uint32 FPDSCR; /*!< Offset: 0x00C (R/W)  Floating-Point Default Status Control Register */
    RO uint32 MVFR0;  /*!< Offset: 0x010 (R/ )  Media and FP Feature Register 0 */
    RO uint32 MVFR1;  /*!< Offset: 0x014 (R/ )  Media and FP Feature Register 1 */
} Z20_FPUType;

/* Memory mapping of Core Hardware */
#define Z20_SCS_BASE        (0xE000E000U)            /*!< System Control Space Base Address */
#define Z20_ITM_BASE        (0xE0000000U)            /*!< ITM Base Address */
#define Z20_DWT_BASE        (0xE0001000U)            /*!< DWT Base Address */
#define Z20_CORE_DEBUG_BASE (0xE000EDF0U)            /*!< Core Debug Base Address */
#define Z20_SYSTICK_BASE    (Z20_SCS_BASE + 0x0010U) /*!< SysTick Base Address */
#define Z20_NVIC_BASE       (Z20_SCS_BASE + 0x0100U) /*!< NVIC Base Address */
#define Z20_SCB_BASE        (Z20_SCS_BASE + 0x0D00U) /*!< System Control Block Base Address */

#define Z20_SCnSCB  ((Z20_SCnSCBType *)Z20_SCS_BASE)      /*!< System control Register not in SCB */
#define Z20_SCB     ((Z20_SCBType *)Z20_SCB_BASE)         /*!< SCB configuration struct */
#define Z20_SYSTICK ((Z20_SysTickType *)Z20_SYSTICK_BASE) /*!< SysTick configuration struct */
#define Z20_NVIC    ((Z20_NVICType *)Z20_NVIC_BASE)       /*!< NVIC configuration struct */
#define Z20_DWT     ((Z20_DWTType *)Z20_DWT_BASE)         /*!< DWT configuration struct */
#define Z20_CORE_DEBUG                                                                             \
    ((Z20_CoreDebugType *)Z20_CORE_DEBUG_BASE)     /*!< Core Debug configuration struct */
#define Z20_FPU_BASE (Z20_SCS_BASE + 0x0F30U)      /*!< Floating Point Unit */
#define Z20_FPU      ((Z20_FPUType *)Z20_FPU_BASE) /*!< Floating Point Unit */

/**
 * Peripheral Register Defination
 */

struct Reg_Adc_Bf
{
    /* 0x000*/
    uint32 zResverd0x000;
    /* 0x004*/
    struct
    {
        uint32 RSVD_7_0   : 8;  /* [7:0]          ro         */
        uint32 FIFO_SIZE  : 8;  /* [15:8]         ro         */
        uint32 RSVD_31_16 : 16; /* [31:16]        ro         */
    } ADC_PARAM;

    /* 0x008*/
    struct
    {
        uint32 ADC_EN           : 1;  /* [0]            r/w        */
        uint32 CAL_REQ          : 1;  /* [1]            r/w        */
        uint32 RST              : 1;  /* [2]            r/w        */
        uint32 DOZEN            : 1;  /* [3]            r/w        */
        uint32 TRIG_MODE_ENABLE : 1;  /* [4]            r/w        */
        uint32 TRIG_MODE        : 1;  /* [5]            r/w        */
        uint32 MODE1_RST        : 1;  /* [6]            r/w        */
        uint32 LMD              : 3;  /* [9:7]          r/w        */
        uint32 IREF_SEL         : 1;  /* [10]           r/w        */
        uint32 STABLE_T         : 11; /* [21:11]        r/w        */
        uint32 RSVD_31_22       : 10; /* [31:22]        ro         */
    } ADC_CTRL;

    /* 0x00C*/
    struct
    {
        uint32 FWM_INT    : 1;  /* [0]            r/w1c      */
        uint32 FOF        : 1;  /* [1]            r/w1c      */
        uint32 TCOMP_INT  : 1;  /* [2]            r/w1c      */
        uint32 CMP_INT    : 1;  /* [3]            r/w1c      */
        uint32 DMA_REQ    : 1;  /* [4]            ro         */
        uint32 RDY        : 1;  /* [5]            ro         */
        uint32 CAL_RDY    : 1;  /* [6]            ro         */
        uint32 ADC_ACTIVE : 1;  /* [7]            ro         */
        uint32 LSI        : 1;  /* [8]            ro         */
        uint32 TC_ERR     : 1;  /* [9]            ro         */
        uint32 RSVD_31_10 : 22; /* [31:10]        ro         */
    } ADC_STAT;

    /* 0x010*/
    struct
    {
        uint32 FWM_IE     : 1;  /* [0]            r/w        */
        uint32 FOF_IE     : 1;  /* [1]            r/w        */
        uint32 TCOM_IE    : 1;  /* [2]            r/w        */
        uint32 CMP_IE     : 1;  /* [3]            r/w        */
        uint32 FWMDE      : 1;  /* [4]            r/w        */
        uint32 ERR_INT_IE : 1;  /* [5]            r/w        */
        uint32 RSVD_31_6  : 26; /* [31:6]         ro         */
    } ADC_IE;

    /* 0x014*/
    struct
    {
        uint32 DIFF_MODE : 1;  /* [0]            r/w        */
        uint32 CHSELP    : 5;  /* [5:1]          r/w        */
        uint32 CHSELN    : 2;  /* [7:6]          r/w        */
        uint32 RSVD_10_8 : 3;  /* [10:8]         ro         */
        uint32 CTYPE     : 1;  /* [11]           r/w        */
        uint32 CMPS      : 3;  /* [14:12]        r/w        */
        uint32 HWT_EN    : 1;  /* [15]           r/w        */
        uint32 REF_SEL   : 1;  /* [16]           r/w        */
        uint32 RES       : 2;  /* [18:17]        r/w        */
        uint32 AVGS      : 3;  /* [21:19]        r/w        */
        uint32 STS       : 10; /* [31:22]        r/w        */
    } ADC_CFG;

    /* 0x018*/
    struct
    {
        uint32 CVL        : 12; /* [11:0]         r/w        */
        uint32 RSVD_15_12 : 4;  /* [15:12]        ro         */
        uint32 CVH        : 12; /* [27:16]        r/w        */
        uint32 RSVD_31_28 : 4;  /* [31:28]        ro         */
    } ADC_CV;

    /* 0x01C*/
    uint8 zResverd0x01C[4]; /*pad 0x01C - 01F*/

    /* 0x020*/
    struct
    {
        uint32 ADC_DATA_RD : 17; /* [16:0]         ro         */
        uint32 RSVD_31_17  : 15; /* [31:17]        ro         */
    } ADC_DATA_RD;

    /* 0x024*/
    struct
    {
        uint32 FCOUNT     : 5;  /* [4:0]          ro         */
        uint32 RSVD_15_5  : 11; /* [15:5]         ro         */
        uint32 FWMARK     : 4;  /* [19:16]        r/w        */
        uint32 FDRD       : 5;  /* [24:20]        r/w        */
        uint32 RSVD_31_25 : 7;  /* [31:25]        ro         */
    } ADC_FCTRL;

    /* 0x028*/
    struct
    {
        uint32 ADC_SWTRIG : 1;  /* [0]            r/w        */
        uint32 RSVD_31_1  : 31; /* [31:1]         ro         */
    } ADC_SWTRIG;

    /* 0x02C*/
    struct
    {
        uint32 ADC_CAL_VAL : 13; /* [12:0]         ro         */
        uint32 RSVD_31_13  : 19; /* [31:13]        ro         */
    } ADC_CAL_VAL;

    /* 0x030*/
    struct
    {
        uint32 CMD0        : 5; /* [4:0]          r/w        */
        uint32 CMD0_INT_EN : 1; /* [5]            r/w        */
        uint32 RSVD_7_6    : 2; /* [7:6]          ro         */
        uint32 CMD1        : 5; /* [12:8]         r/w        */
        uint32 CMD1_INT_EN : 1; /* [13]           r/w        */
        uint32 RSVD_15_14  : 2; /* [15:14]        ro         */
        uint32 CMD2        : 5; /* [20:16]        r/w        */
        uint32 CMD2_INT_EN : 1; /* [21]           r/w        */
        uint32 RSVD_23_22  : 2; /* [23:22]        ro         */
        uint32 CMD3        : 5; /* [28:24]        r/w        */
        uint32 CMD3_INT_EN : 1; /* [29]           r/w        */
        uint32 RSVD_31_30  : 2; /* [31:30]        ro         */
    } ADC_CMD_BUFF0;

    /* 0x034*/
    struct
    {
        uint32 CMD4        : 5;  /* [4:0]          r/w        */
        uint32 CMD4_INT_EN : 1;  /* [5]            r/w        */
        uint32 RSVD_7_6    : 2;  /* [7:6]          ro         */
        uint32 CMD5        : 5;  /* [12:8]         r/w        */
        uint32 CMD5_INT_EN : 1;  /* [13]           r/w        */
        uint32 RSVD_31_14  : 18; /* [31:14]        ro         */
    } ADC_CMD_BUFF1;

}; /*adc*/

struct Reg_Adc_W
{
    /* 0x000*/
    uint32 zResverd0x000;
    /* 0x004*/
    uint32 ADC_PARAM;
    /* 0x008*/
    uint32 ADC_CTRL;
    /* 0x00C*/
    uint32 ADC_STAT;
    /* 0x010*/
    uint32 ADC_IE;
    /* 0x014*/
    uint32 ADC_CFG;
    /* 0x018*/
    uint32 ADC_CV;
    /* 0x01C*/
    uint8 zResverd0x01C[4]; /*pad 0x01C - 01F*/
    /* 0x020*/
    uint32 ADC_DATA_RD;
    /* 0x024*/
    uint32 ADC_FCTRL;
    /* 0x028*/
    uint32 ADC_SWTRIG;
    /* 0x02C*/
    uint32 ADC_CAL_VAL;
    /* 0x030*/
    uint32 ADC_CMD_BUFF0;
    /* 0x034*/
    uint32 ADC_CMD_BUFF1;
}; /*adc*/

typedef volatile struct Reg_Adc_Bf Reg_Adc_BfType;
typedef volatile struct Reg_Adc_W  Reg_Adc_WType;

struct Reg_Aes_Bf
{
    /* 0x0000*/
    uint32 zResverd0x0000;
    /* 0x0004*/
    struct
    {
        uint32 R         : 1;  /* [0]            ro         */
        uint32 ERR       : 8;  /* [8:1]          ro         */
        uint32 RSVD_31_9 : 23; /* [31:9]         ro         */
    } AES_STATUS;

    /* 0x0008*/
    struct
    {
        uint32 S         : 1;  /* [0]            wo         */
        uint32 RND       : 4;  /* [4:1]          wo         */
        uint32 RSVD_31_5 : 27; /* [31:5]         wo         */
    } AES_CONTROL;

    /* 0x000c*/
    struct
    {
        uint32 CD       : 1; /* [0]            wo         */
        uint32 KSS      : 2; /* [2:1]          wo         */
        uint32 RSVD_3   : 1; /* [3]            wo         */
        uint32 RSVD_7_4 : 4; /* [7:4]          wo         */
        uint32 MODE     : 8; /* [15:8]         wo         */
        uint32 BS       : 8; /* [23:16]        wo         */
        uint32 ALGO     : 8; /* [31:24]        wo         */
    } AES_CONFIG;

    uint8 zResverd0x010[12]; /*pad 0x010 - 01B*/

    /* 0x001c*/
    struct
    {
        uint32 DATA_I : 32; /* [31:0]         wo         */
    } AES_DATA_I0;

    /* 0x0020*/
    struct
    {
        uint32 DATA_I : 32; /* [31:0]         wo         */
    } AES_DATA_I1;

    /* 0x0024*/
    struct
    {
        uint32 DATA_I : 32; /* [31:0]         wo         */
    } AES_DATA_I2;

    /* 0x0028*/
    struct
    {
        uint32 DATA_I : 32; /* [31:0]         wo         */
    } AES_DATA_I3;

    /* 0x002c*/
    struct
    {
        uint32 DATA_O : 32; /* [31:0]         ro         */
    } AES_DATA_O0;

    /* 0x0030*/
    struct
    {
        uint32 DATA_O : 32; /* [31:0]         ro         */
    } AES_DATA_O1;

    /* 0x0034*/
    struct
    {
        uint32 DATA_O : 32; /* [31:0]         ro         */
    } AES_DATA_O2;

    /* 0x0038*/
    struct
    {
        uint32 DATA_O : 32; /* [31:0]         ro         */
    } AES_DATA_O3;

    /* 0x003c*/
    struct
    {
        uint32 KEY0 : 32; /* [31:0]         rw         */
    } AES_KEY0;

    /* 0x0040*/
    struct
    {
        uint32 KEY1 : 32; /* [31:0]         rw         */
    } AES_KEY1;

    /* 0x0044*/
    struct
    {
        uint32 KEY2 : 32; /* [31:0]         rw         */
    } AES_KEY2;

    /* 0x0048*/
    struct
    {
        uint32 KEY3 : 32; /* [31:0]         rw         */
    } AES_KEY3;

    uint8 zResverd0x04C[16]; /*pad 0x04C - 05B*/

    /* 0x005c*/
    struct
    {
        uint32 IV0 : 32; /* [31:0]         wo         */
    } AES_IV0;

    /* 0x0060*/
    struct
    {
        uint32 IV1 : 32; /* [31:0]         wo         */
    } AES_IV1;

    /* 0x0064*/
    struct
    {
        uint32 IV2 : 32; /* [31:0]         wo         */
    } AES_IV2;

    /* 0x0068*/
    struct
    {
        uint32 IV3 : 32; /* [31:0]         wo         */
    } AES_IV3;

}; /*aes*/

struct Reg_Aes_W
{
    /* 0x0000*/
    uint32 zResverd0x0000;
    /* 0x0004*/
    uint32 AES_STATUS;
    /* 0x0008*/
    uint32 AES_CONTROL;
    /* 0x000c*/
    uint32 AES_CONFIG;
    uint8  zResverd0x010[12]; /*pad 0x010 - 01B*/

    /* 0x001c*/
    uint32 AES_DATA_I0;
    /* 0x0020*/
    uint32 AES_DATA_I1;
    /* 0x0024*/
    uint32 AES_DATA_I2;
    /* 0x0028*/
    uint32 AES_DATA_I3;
    /* 0x002c*/
    uint32 AES_DATA_O0;
    /* 0x0030*/
    uint32 AES_DATA_O1;
    /* 0x0034*/
    uint32 AES_DATA_O2;
    /* 0x0038*/
    uint32 AES_DATA_O3;
    /* 0x003c*/
    uint32 AES_KEY0;
    /* 0x0040*/
    uint32 AES_KEY1;
    /* 0x0044*/
    uint32 AES_KEY2;
    /* 0x0048*/
    uint32 AES_KEY3;
    uint8  zResverd0x04C[16]; /*pad 0x04C - 05B*/

    /* 0x005c*/
    uint32 AES_IV0;
    /* 0x0060*/
    uint32 AES_IV1;
    /* 0x0064*/
    uint32 AES_IV2;
    /* 0x0068*/
    uint32 AES_IV3;
}; /*aes*/

typedef volatile struct Reg_Aes_Bf Reg_Aes_BfType;
typedef volatile struct Reg_Aes_W  Reg_Aes_WType;

struct Reg_Can_Bf
{
    /* 0x00*/
    struct
    {
        uint32 MAXMB   : 7; /* [6:0]          r/w        */
        uint32 RSVD_7  : 1; /* [7]            reserve    */
        uint32 IDAM    : 2; /* [9:8]          r/w        */
        uint32 RSVD_10 : 1; /* [10]           ro         */
        uint32 FDEN    : 1; /* [11]           r/w        */
        uint32 AEN     : 1; /* [12]           r/w        */
        uint32 LPRIOEN : 1; /* [13]           r/w        */
        uint32 PNET_EN : 1; /* [14]           r/w        */
        uint32 DMAE    : 1; /* [15]           r/w        */
        uint32 IRMQ    : 1; /* [16]           r/w        */
        uint32 SRXDIS  : 1; /* [17]           r/w        */
        uint32 DOZE    : 1; /* [18]           r/w        */
        uint32 WAKSRC  : 1; /* [19]           r/w        */
        uint32 LPMACK  : 1; /* [20]           ro         */
        uint32 WRNEN   : 1; /* [21]           r/w        */
        uint32 SLFWAK  : 1; /* [22]           r/w        */
        uint32 SUPV    : 1; /* [23]           r/w        */
        uint32 FRZACK  : 1; /* [24]           ro         */
        uint32 SOFTRST : 1; /* [25]           r/w        */
        uint32 WAKMSK  : 1; /* [26]           r/w        */
        uint32 NOTRDY  : 1; /* [27]           ro         */
        uint32 HALT    : 1; /* [28]           r/w        */
        uint32 RFEN    : 1; /* [29]           r/w        */
        uint32 FRZ     : 1; /* [30]           r/w        */
        uint32 MDIS    : 1; /* [31]           r/w        */
    } CAN_MCR;

    /* 0x04*/
    struct
    {
        uint32 PROPSEG  : 3; /* [2:0]          r/w        */
        uint32 LOM      : 1; /* [3]            r/w        */
        uint32 LBUF     : 1; /* [4]            r/w        */
        uint32 TSYC     : 1; /* [5]            r/w        */
        uint32 BOFFREC  : 1; /* [6]            r/w        */
        uint32 SMP      : 1; /* [7]            r/w        */
        uint32 RSVD_9_8 : 2; /* [9:8]          ro         */
        uint32 RWRNMSK  : 1; /* [10]           r/w        */
        uint32 TWRNMSK  : 1; /* [11]           r/w        */
        uint32 LPB      : 1; /* [12]           r/w        */
        uint32 RSVD_13  : 1; /* [13]           reserve    */
        uint32 ERRMSK   : 1; /* [14]           r/w        */
        uint32 BOFFMSK  : 1; /* [15]           r/w        */
        uint32 PSEG2    : 3; /* [18:16]        r/w        */
        uint32 PSEG1    : 3; /* [21:19]        r/w        */
        uint32 RJW      : 2; /* [23:22]        r/w        */
        uint32 PRESDIV  : 8; /* [31:24]        r/w        */
    } CAN_CTRL1;

    /* 0x08*/
    struct
    {
        uint32 TIMER      : 16; /* [15:0]         r/w        */
        uint32 RSVD_31_16 : 16; /* [31:16]        ro         */
    } CAN_TIMER;

    uint8 zResverd0x0C[4]; /*pad 0x0C - 0F*/

    /* 0x10*/
    struct
    {
        uint32 MG : 32; /* [31:0]         r/w        */
    } CAN_RXMGMSK;

    /* 0x14*/
    struct
    {
        uint32 RX14M : 32; /* [31:0]         r/w        */
    } CAN_RX14MASK;

    /* 0x18*/
    struct
    {
        uint32 RX15M : 32; /* [31:0]         r/w        */
    } CAN_RX15MASK;

    /* 0x1c*/
    struct
    {
        uint32 TXERRCNT       : 8; /* [7:0]          r/w        */
        uint32 RXERRCNT       : 8; /* [15:8]         r/w        */
        uint32 TX_ERRCNT_FAST : 8; /* [23:16]        r/w        */
        uint32 RX_ERRCNT_FAST : 8; /* [31:24]        r/w        */
    } CAN_ECR;

    /* 0x20*/
    struct
    {
        uint32 WAKINT        : 1; /* [0]            w1c        */
        uint32 ERRINT        : 1; /* [1]            w1c        */
        uint32 BOFFINT       : 1; /* [2]            w1c        */
        uint32 RX            : 1; /* [3]            ro         */
        uint32 FLTCONF       : 2; /* [5:4]          ro         */
        uint32 TX            : 1; /* [6]            ro         */
        uint32 IDLE          : 1; /* [7]            ro         */
        uint32 RXWRN         : 1; /* [8]            ro         */
        uint32 TXWRN         : 1; /* [9]            ro         */
        uint32 STFERR        : 1; /* [10]           ro         */
        uint32 FRAMERR       : 1; /* [11]           ro         */
        uint32 CRCERR        : 1; /* [12]           ro         */
        uint32 ACKERR        : 1; /* [13]           ro         */
        uint32 BIT0ERR       : 1; /* [14]           ro         */
        uint32 BIT1ERR       : 1; /* [15]           ro         */
        uint32 RWRNINT       : 1; /* [16]           ro         */
        uint32 TWRNINT       : 1; /* [17]           ro         */
        uint32 SYNCH         : 1; /* [18]           ro         */
        uint32 BUSOFFDONEINT : 1; /* [19]           w1c        */
        uint32 ERRINT_FAST   : 1; /* [20]           w1c        */
        uint32 ERROVR        : 1; /* [21]           w1c        */
        uint32 RSVD_25_22    : 4; /* [25:22]        ro         */
        uint32 STFERR_FAST   : 1; /* [26]           ro         */
        uint32 FRAMERR_FAST  : 1; /* [27]           ro         */
        uint32 CRCERR_FAST   : 1; /* [28]           ro         */
        uint32 RSVD_29       : 1; /* [29]           ro         */
        uint32 BIT0ERR_FAST  : 1; /* [30]           ro         */
        uint32 BIT1ERR_FAST  : 1; /* [31]           ro         */
    } CAN_ESR1;

    /* 0x24*/
    struct
    {
        uint32 BUF63TO32M : 32; /* [31:0]         r/w        */
    } CAN_IMASK2;

    /* 0x28*/
    struct
    {
        uint32 BUF31TO0M : 32; /* [31:0]         r/w        */
    } CAN_IMASK1;

    /* 0x2c*/
    struct
    {
        uint32 BUF63TO32I : 32; /* [31:0]         r/w        */
    } CAN_IFLAG2;

    /* 0x30*/
    struct
    {
        uint32 BUF0I     : 1;  /* [0]            w1c        */
        uint32 BUF4TO1I  : 4;  /* [4:1]          w1c        */
        uint32 BUF5I     : 1;  /* [5]            w1c        */
        uint32 BUF6I     : 1;  /* [6]            w1c        */
        uint32 BUF7I     : 1;  /* [7]            w1c        */
        uint32 BUF31TO8I : 24; /* [31:8]         w1c        */
    } CAN_IFLAG1;

    /* 0x34*/
    struct
    {
        uint32 RSVD_10_0    : 11; /* [10:0]         ro         */
        uint32 EDFLTDIS     : 1;  /* [11]           r/w        */
        uint32 ISOCANFDEN   : 1;  /* [12]           r/w        */
        uint32 RSVD_13      : 1;  /* [13]           ro         */
        uint32 PREXCEN      : 1;  /* [14]           r/w        */
        uint32 TIMER_SRC    : 1;  /* [15]           r/w        */
        uint32 EACEN        : 1;  /* [16]           r/w        */
        uint32 RRS          : 1;  /* [17]           r/w        */
        uint32 MRP          : 1;  /* [18]           r/w        */
        uint32 TASD         : 5;  /* [23:19]        r/w        */
        uint32 RFFN         : 4;  /* [27:24]        r/w        */
        uint32 WRMFRZ       : 1;  /* [28]           r/w        */
        uint32 ECRWRE       : 1;  /* [29]           r/w        */
        uint32 BOFFDONEMSK  : 1;  /* [30]           r/w        */
        uint32 ERRMASK_FAST : 1;  /* [31]           r/w        */
    } CAN_CTRL2;

    /* 0x38*/
    struct
    {
        uint32 RSVD_12_0  : 13; /* [12:0]         ro         */
        uint32 IMB        : 1;  /* [13]           ro         */
        uint32 VPS        : 1;  /* [14]           ro         */
        uint32 RSVD_15    : 1;  /* [15]           ro         */
        uint32 LPTM       : 7;  /* [22:16]        ro         */
        uint32 RSVD_31_23 : 9;  /* [31:23]        ro         */
    } CAN_ESR2;

    uint8 zResverd0x03C[8]; /*pad 0x03C - 043*/

    /* 0x44*/
    struct
    {
        uint32 TXCRC      : 15; /* [14:0]         ro         */
        uint32 RSVD_15    : 1;  /* [15]           ro         */
        uint32 MBCRC      : 7;  /* [22:16]        ro         */
        uint32 RSVD_31_23 : 9;  /* [31:23]        ro         */
    } CAN_CRCR;

    /* 0x48*/
    struct
    {
        uint32 FGM : 32; /* [31:0]         r/w        */
    } CAN_RXFGMASK;

    /* 0x4c*/
    struct
    {
        uint32 IDHIT     : 9;  /* [8:0]          ro         */
        uint32 RSVD_31_9 : 23; /* [31:9]         ro         */
    } CAN_RXFIR;

    /* 0x50*/
    struct
    {
        uint32 EPSEG2   : 5;  /* [4:0]          r/w        */
        uint32 EPSEG1   : 5;  /* [9:5]          r/w        */
        uint32 EPROPSEG : 6;  /* [15:10]        r/w        */
        uint32 ERJW     : 5;  /* [20:16]        r/w        */
        uint32 EPRESDIV : 10; /* [30:21]        r/w        */
        uint32 BTF      : 1;  /* [31]           r/w        */
    } CAN_CBT;

    uint8 zResverd0x054[20]; /*pad 0x054 - 067*/

    /* 0x68*/
    struct
    {
        uint32 BUF127TO96M : 32; /* [31:0]         r/w        */
    } CAN_IMASK4;

    /* 0x6c*/
    struct
    {
        uint32 BUF95TO64M : 32; /* [31:0]         r/w        */
    } CAN_IMASK3;

    /* 0x70*/
    struct
    {
        uint32 BUF127TO96I : 32; /* [31:0]         w1c        */
    } CAN_IFLAG4;

    /* 0x74*/
    struct
    {
        uint32 BUF95TO64I : 32; /* [31:0]         w1c        */
    } CAN_IFLAG3;

    uint8 zResverd0x078[8]; /*pad 0x078 - 07F*/

    /* 0x80*/
    struct {
    struct
    {
        uint32 TIME_STAMP : 16; /* [15:0]         r/w        */
        uint32 DLC        : 4;  /* [19:16]        r/w        */
        uint32 RTR        : 1;  /* [20]           r/w        */
        uint32 IDE        : 1;  /* [21]           r/w        */
        uint32 SRR        : 1;  /* [22]           r/w        */
        uint32 RSVD_23    : 1;  /* [23]           ro         */
        uint32 CODE       : 4;  /* [27:24]        r/w        */
        uint32 RSVD_28    : 1;  /* [28]           ro         */
        uint32 ESI        : 1;  /* [29]           r/w        */
        uint32 BRS        : 1;  /* [30]           r/w        */
        uint32 EDL        : 1;  /* [31]           r/w        */
    } CAN_MB_CS;

    /* 0x84*/
    struct
    {
        uint32 ID_EXTEND  : 18; /* [17:0]         r/w        */
        uint32 ID_STD_EXD : 11; /* [28:18]        r/w        */
        uint32 PRIO       : 3;  /* [31:29]        ro         */
    } CAN_MB_ID;

    /* 0x88*/
    struct
    {
        uint32 DATA_BYTE03 : 32; /* [31:0]         r/w        */
    } CAN_MB_DATA03;

    /* 0x8c*/
    struct
    {
        uint32 DATA_BYTE47 : 32; /* [31:0]         r/w        */
    } CAN_MB_DATA47;
    } CAN_MB[128];

    /* 0x880*/
    struct
    {
        uint32 MI : 32; /* [31:0]         r/w        */
    } CAN_RXIMRn[128];

    uint8 zResverd0x0A80[96]; /*pad 0x0A80 - 0ADF*/

    /* 0xAE0*/
    struct
    {
        uint32 RSVD_6_0   : 7;  /* [6:0]          ro         */
        uint32 NCEFAFRZ   : 1;  /* [7]            r/w        */
        uint32 ECCDIS     : 1;  /* [8]            r/w        */
        uint32 RERRDIS    : 1;  /* [9]            r/w        */
        uint32 RSVD_12_10 : 3;  /* [12:10]        ro         */
        uint32 EXTERRIE   : 1;  /* [13]           r/w        */
        uint32 FAERRIE    : 1;  /* [14]           r/w        */
        uint32 HAERRI     : 1;  /* [15]           r/w        */
        uint32 CEI_MSK    : 1;  /* [16]           r/w        */
        uint32 RSVD_17    : 1;  /* [17]           ro         */
        uint32 FANCEI_MSK : 1;  /* [18]           r/w        */
        uint32 HANCEI_MSK : 1;  /* [19]           r/w        */
        uint32 RSVD_30_20 : 11; /* [30:20]        ro         */
        uint32 ECRWRDIS   : 1;  /* [31]           r/w        */
    } CAN_MECR;

    /* 0xAE4*/
    struct
    {
        uint32 INJADDR_L  : 2;  /* [1:0]          r/w        */
        uint32 INJADDR_H  : 12; /* [13:2]         r/w        */
        uint32 RSVD_31_14 : 18; /* [31:14]        reserve    */
    } CAN_ERRIAR;

    /* 0xAE8*/
    struct
    {
        uint32 DFLIP : 32; /* [31:0]         r/w        */
    } CAN_ERRIDPR;

    /* 0xAEC*/
    struct
    {
        uint32 PFLIP0     : 5; /* [4:0]          r/w        */
        uint32 RSVD_7_5   : 3; /* [7:5]          ro         */
        uint32 PFLIP1     : 5; /* [12:8]         r/w        */
        uint32 RSVD_15_13 : 3; /* [15:13]        ro         */
        uint32 PFLIP2     : 5; /* [20:16]        r/w        */
        uint32 RSVD_23_21 : 3; /* [23:21]        ro         */
        uint32 PFLIP3     : 5; /* [28:24]        r/w        */
        uint32 RSVD_31_29 : 3; /* [31:29]        ro         */
    } CAN_ERRIPPR;

    /* 0xAF0*/
    struct
    {
        uint32 ERRADDR    : 14; /* [13:0]         ro         */
        uint32 RSVD_15_14 : 2;  /* [15:14]        ro         */
        uint32 SAID       : 3;  /* [18:16]        ro         */
        uint32 RSVD_23_19 : 5;  /* [23:19]        ro         */
        uint32 NCE        : 1;  /* [24]           ro         */
        uint32 RSVD_31_25 : 7;  /* [31:25]        ro         */
    } CAN_RERRAR;

    /* 0xAF4*/
    struct
    {
        uint32 RDATA : 32; /* [31:0]         ro         */
    } CAN_RERRDR;

    /* 0xAF8*/
    struct
    {
        uint32 SYND0      : 5; /* [4:0]          ro         */
        uint32 RSVD_6_5   : 2; /* [6:5]          ro         */
        uint32 BE0        : 1; /* [7]            ro         */
        uint32 SYND1      : 5; /* [12:8]         ro         */
        uint32 RSVD_14_13 : 2; /* [14:13]        ro         */
        uint32 BE1        : 1; /* [15]           ro         */
        uint32 SYND2      : 5; /* [20:16]        ro         */
        uint32 RSVD_22_21 : 2; /* [22:21]        ro         */
        uint32 BE2        : 1; /* [23]           ro         */
        uint32 SYND3      : 5; /* [28:24]        ro         */
        uint32 RSVD_30_29 : 2; /* [30:29]        ro         */
        uint32 BE3        : 1; /* [31]           ro         */
    } CAN_RERRSYNR;

    /* 0xAFC*/
    struct
    {
        uint32 CEIOF      : 1;  /* [0]            w1c        */
        uint32 RSVD_1     : 1;  /* [1]            ro         */
        uint32 FANCEIOF   : 1;  /* [2]            w1c        */
        uint32 HANCEIOF   : 1;  /* [3]            w1c        */
        uint32 RSVD_15_4  : 12; /* [15:4]         ro         */
        uint32 CEIF       : 1;  /* [16]           w1c        */
        uint32 RSVD_17    : 1;  /* [17]           ro         */
        uint32 FANCEIF    : 1;  /* [18]           w1c        */
        uint32 HANCEIF    : 1;  /* [19]           w1c        */
        uint32 RSVD_31_20 : 12; /* [31:20]        ro         */
    } CAN_ERRSR;

    /* 0xB00*/
    struct
    {
        uint32 FCS        : 2;  /* [1:0]          r/w        */
        uint32 IDFS       : 2;  /* [3:2]          r/w        */
        uint32 PLFS       : 2;  /* [5:4]          r/w        */
        uint32 RSVD_7_6   : 2;  /* [7:6]          ro         */
        uint32 NMATCH     : 8;  /* [15:8 ]         r/w        */
        uint32 WUMF_MSK   : 1;  /* [16]           r/w        */
        uint32 WTOF_MSK   : 1;  /* [17]           r/w        */
        uint32 RSVD_31_18 : 14; /* [31:18]        ro         */
    } CAN_CTRL1_PN;

    /* 0xB04*/
    struct
    {
        uint32 MATCHTO    : 16; /* [15:0]         r/w        */
        uint32 RSVD_31_16 : 16; /* [31:16]        ro         */
    } CAN_CTRL2_PN;

    /* 0xB08*/
    struct
    {
        uint32 RSVD_7_0   : 8;  /* [7:0]          reserve    */
        uint32 MCOUNTER   : 8;  /* [15:8]         ro         */
        uint32 WUMF       : 1;  /* [16]           r/w1c      */
        uint32 WTOF       : 1;  /* [17]           r/w1c      */
        uint32 RSVD_31_18 : 14; /* [31:18]        ro         */
    } CAN_WU_MTC;

    /* 0xB0C*/
    struct
    {
        uint32 FLT_ID1 : 29; /* [28:0]         r/w        */
        uint32 FLT_RTR : 1;  /* [29]           r/w        */
        uint32 FLT_IDE : 1;  /* [30]           r/w        */
        uint32 RSVD_31 : 1;  /* [31]           ro         */
    } CAN_FLT_ID1;

    /* 0xB10*/
    struct
    {
        uint32 FLT_DLC_HI : 4;  /* [3:0]                     */
        uint32 RSVD_15_4  : 12; /* [15:4]         ro         */
        uint32 FLT_DLC_LO : 4;  /* [19:16]        r/w        */
        uint32 RSVD_31_20 : 12; /* [31:20]        r/w        */
    } CAN_FLT_DLC;

    /* 0xB14*/
    struct
    {
        uint32 DATA_BYTE_3 : 8; /* [7:0]          r/w        */
        uint32 DATA_BYTE_2 : 8; /* [15:8]         r/w        */
        uint32 DATA_BYTE_1 : 8; /* [23:16]        r/w        */
        uint32 DATA_BYTE_0 : 8; /* [31:24]        r/w        */
    } CAN_PL1_LO;

    /* 0xB18*/
    struct
    {
        uint32 DATA_BYTE_7 : 8; /* [7:0]          r/w        */
        uint32 DATA_BYTE_6 : 8; /* [15:8]         r/w        */
        uint32 DATA_BYTE_5 : 8; /* [23:16]        r/w        */
        uint32 DATA_BYTE_4 : 8; /* [31:24]        r/w        */
    } CAN_PL1_HI;

    /* 0xB1C*/
    struct
    {
        uint32 FLT_ID2_IDMASK : 29; /* [28:0]         r/w        */
        uint32 RTR_MSK        : 1;  /* [29]           r/w        */
        uint32 IDE_MSK        : 1;  /* [30]           r/w        */
        uint32 RSVD_31        : 1;  /* [31]           ro         */
    } CAN_FLT_ID2_IDMASK;

    /* 0xB20*/
    struct
    {
        uint32 DATA_BYTE_3 : 8; /* [7:0]          r/w        */
        uint32 DATA_BYTE_2 : 8; /* [15:8]         r/w        */
        uint32 DATA_BYTE_1 : 8; /* [23:16]        r/w        */
        uint32 DATA_BYTE_0 : 8; /* [31:24]        r/w        */
    } CAN_PL2_PLMASK_LO;

    /* 0xB24*/
    struct
    {
        uint32 DATA_BYTE_7 : 8; /* [7:0]          r/w        */
        uint32 DATA_BYTE_6 : 8; /* [15:8]         r/w        */
        uint32 DATA_BYTE_5 : 8; /* [23:16]        r/w        */
        uint32 DATA_BYTE_4 : 8; /* [31:24]        r/w        */
    } CAN_PL2_PLMASK_HI;

    uint8 zResverd0x0B28[24]; /*pad 0x0B28 - 0B3F*/
    
    struct {
    /* 0xB40*/
    struct
    {
        uint32 RSVD_15_0  : 16; /* [15:0]         ro         */
        uint32 DLC        : 4;  /* [19:16]        ro         */
        uint32 RTR        : 1;  /* [20]           ro         */
        uint32 IDE        : 1;  /* [21]           ro         */
        uint32 SRR        : 1;  /* [22]           ro         */
        uint32 RSVD_31_23 : 9;  /* [31:23]        ro         */
    } CAN_WMB_CS;

    /* 0xB44*/
    struct
    {
        uint32 ID         : 29; /* [28:0]         ro         */
        uint32 RSVD_31_29 : 3;  /* [31:29]        ro         */
    } CAN_WMB_ID;

    /* 0xB48*/
    struct
    {
        uint32 DATA_BYTE_3 : 8; /* [7:0]          ro         */
        uint32 DATA_BYTE_2 : 8; /* [15:8]         ro         */
        uint32 DATA_BYTE_1 : 8; /* [23:16]        ro         */
        uint32 DATA_BYTE_0 : 8; /* [31:24]        ro         */
    } CAN_WMB_D03;

    /* 0xB4C*/
    struct
    {
        uint32 DATA_BYTE_7 : 8; /* [7:0]          ro         */
        uint32 DATA_BYTE_6 : 8; /* [15:8]         ro         */
        uint32 DATA_BYTE_5 : 8; /* [23:16]        ro         */
        uint32 DATA_BYTE_4 : 8; /* [31:24]        ro         */
    } CAN_WMB_D47;
    } CAN_WMB[4];

    uint8 zResverd0x0B80[128]; /*pad 0x0B80 - 0BFF*/

    /* 0xC00*/
    struct
    {
        uint32 TDCVAL     : 6; /* [5:0]          ro         */
        uint32 RSVD_7_6   : 2; /* [7:6]          ro         */
        uint32 TDCOFF     : 5; /* [12:8]         ro         */
        uint32 RSVD_13    : 1; /* [13]           ro         */
        uint32 TDCFAIL    : 1; /* [14]           w1c        */
        uint32 TDCEN      : 1; /* [15]           r/w        */
        uint32 MBDSR0     : 2; /* [17:16]        r/w        */
        uint32 RSVD_18    : 1; /* [18]           ro         */
        uint32 MBDSR1     : 2; /* [20:19]        r/w        */
        uint32 RSVD_21    : 1; /* [21]           ro         */
        uint32 MBDSR2     : 2; /* [23:22]        r/w        */
        uint32 RSVD_24    : 1; /* [24]           ro         */
        uint32 MBDSR3     : 2; /* [26:25]        r/w        */
        uint32 RSVD_30_27 : 4; /* [30:27]        ro         */
        uint32 FD_RATE    : 1; /* [31]           r/w        */
    } CAN_FDCTRL;

    /* 0xC04*/
    struct
    {
        uint32 FPSEG2     : 3;  /* [2:0]          r/w        */
        uint32 RSVD_4_3   : 2;  /* [4:3]          ro         */
        uint32 FPSEG1     : 3;  /* [7:5]          r/w        */
        uint32 RSVD_9_8   : 2;  /* [9:8]          ro         */
        uint32 FPROPSEG   : 5;  /* [14:10]        r/w        */
        uint32 RSVD_15    : 1;  /* [15]           ro         */
        uint32 FRJW       : 3;  /* [18:16]        r/w        */
        uint32 RSVD_19    : 1;  /* [19]           ro         */
        uint32 FPRESDIV   : 10; /* [29:20]        r/w        */
        uint32 RSVD_31_30 : 2;  /* [31:30]        ro         */
    } CAN_FDCBT;

    /* 0xC08*/
    struct
    {
        uint32 FD_TXCRC   : 21; /* [20:0]         ro         */
        uint32 RSVD_23_21 : 3;  /* [23:21]        ro         */
        uint32 FD_MBCRC   : 7;  /* [30:24]        ro         */
        uint32 RSVD_31    : 1;  /* [31]           ro         */
    } CAN_FDCRC;

}; /*can*/

struct Reg_Can_W
{
    /* 0x00*/
    uint32 CAN_MCR;
    /* 0x04*/
    uint32 CAN_CTRL1;
    /* 0x08*/
    uint32 CAN_TIMER;
    uint8  zResverd0x0C[4]; /*pad 0x0C - 0F*/

    /* 0x10*/
    uint32 CAN_RXMGMSK;
    /* 0x14*/
    uint32 CAN_RX14MASK;
    /* 0x18*/
    uint32 CAN_RX15MASK;
    /* 0x1c*/
    uint32 CAN_ECR;
    /* 0x20*/
    uint32 CAN_ESR1;
    /* 0x24*/
    uint32 CAN_IMASK2;
    /* 0x28*/
    uint32 CAN_IMASK1;
    /* 0x2c*/
    uint32 CAN_IFLAG2;
    /* 0x30*/
    uint32 CAN_IFLAG1;
    /* 0x34*/
    uint32 CAN_CTRL2;
    /* 0x38*/
    uint32 CAN_ESR2;
    uint8  zResverd0x03C[8]; /*pad 0x03C - 043*/

    /* 0x44*/
    uint32 CAN_CRCR;
    /* 0x48*/
    uint32 CAN_RXFGMASK;
    /* 0x4c*/
    uint32 CAN_RXFIR;
    /* 0x50*/
    uint32 CAN_CBT;
    uint8  zResverd0x054[20]; /*pad 0x054 - 067*/

    /* 0x68*/
    uint32 CAN_IMASK4;
    /* 0x6c*/
    uint32 CAN_IMASK3;
    /* 0x70*/
    uint32 CAN_IFLAG4;
    /* 0x74*/
    uint32 CAN_IFLAG3;
    uint8  zResverd0x078[8]; /*pad 0x078 - 07F*/

    struct
    {
        /* 0x80 */
        uint32 MB0;
        /* 0x84*/
        uint32 MB1;
        /* 0x88*/
        uint32 MB2;
        /* 0x8c*/
        uint32 MB3;
    } CAN_MB[128];

    /* 0x880*/
    uint32 CAN_RXIMR[128];
    uint8  zResverd0x0A80[96]; /*pad 0x0A80 - 0ADF*/

    /* 0xAE0*/
    uint32 CAN_MECR;
    /* 0xAE4*/
    uint32 CAN_ERRIAR;
    /* 0xAE8*/
    uint32 CAN_ERRIDPR;
    /* 0xAEC*/
    uint32 CAN_ERRIPPR;
    /* 0xAF0*/
    uint32 CAN_RERRAR;
    /* 0xAF4*/
    uint32 CAN_RERRDR;
    /* 0xAF8*/
    uint32 CAN_RERRSYNR;
    /* 0xAFC*/
    uint32 CAN_ERRSR;
    /* 0xB00*/
    uint32 CAN_CTRL1_PN;
    /* 0xB04*/
    uint32 CAN_CTRL2_PN;
    /* 0xB08*/
    uint32 CAN_WU_MTC;
    /* 0xB0C*/
    uint32 CAN_FLT_ID1;
    /* 0xB10*/
    uint32 CAN_FLT_DLC;
    /* 0xB14*/
    uint32 CAN_PL1_LO;
    /* 0xB18*/
    uint32 CAN_PL1_HI;
    /* 0xB1C*/
    uint32 CAN_FLT_ID2_IDMASK;
    /* 0xB20*/
    uint32 CAN_PL2_PLMASK_LO;
    /* 0xB24*/
    uint32 CAN_PL2_PLMASK_HI;
    uint8  zResverd0x0B28[24]; /*pad 0x0B28 - 0B3F*/
    struct {
    /* 0xB40*/
    uint32 CAN_WMB_CS;
    /* 0xB44*/
    uint32 CAN_WMB_ID;
    /* 0xB48*/
    uint32 CAN_WMB_D03;
    /* 0xB4C*/
    uint32 CAN_WMB_D47;
    } CAN_WMB[4];
    
    uint8  zResverd0x0B80[128]; /*pad 0x0B80 - 0BFF*/

    /* 0xC00*/
    uint32 CAN_FDCTRL;
    /* 0xC04*/
    uint32 CAN_FDCBT;
    /* 0xC08*/
    uint32 CAN_FDCRC;
}; /*can*/

typedef volatile struct Reg_Can_Bf Reg_Can_BfType;
typedef volatile struct Reg_Can_W  Reg_Can_WType;

struct Reg_Cmp_Bf
{
    /* 0x0*/
    uint32 zResverd0x0;
    /* 0x4*/
    struct
    {
        uint32 DAC_RES   : 4;  /* [3:0]          ro         */
        uint32 RSVD_31_4 : 28; /* [31:4]                    */
    } CMP_PARAM;

    /* 0x8*/
    struct
    {
        uint32 CMP_SEL    : 1;  /* [0]            r/w        */
        uint32 CMP_EN     : 1;  /* [1]            r/w        */
        uint32 SOC_TRG_EN : 1;  /* [2]            r/w        */
        uint32 STOP_EN    : 1;  /* [3]            r/w        */
        uint32 RSVD_31_4  : 28; /* [31:4]                    */
    } CMP_CCR0;

    /* 0xC*/
    struct
    {
        uint32 WINDOW_EN  : 1; /* [0]            r/w        */
        uint32 SAMPLE_EN  : 1; /* [1]            r/w        */
        uint32 DMA_EN     : 1; /* [2]            r/w        */
        uint32 COUT_INV   : 1; /* [3]            r/w        */
        uint32 COUT_SEL   : 1; /* [4]            r/w        */
        uint32 COUT_PEN   : 1; /* [5]            r/w        */
        uint32 COUT_OWE   : 1; /* [6]            r/w        */
        uint32 COUT_OW    : 1; /* [7]            r/w        */
        uint32 RSVD_15_8  : 8; /* [15:8]                    */
        uint32 FILT_CNT   : 3; /* [18:16]        r/w        */
        uint32 RSVD_23_19 : 5; /* [23:19]                   */
        uint32 FILT_PER   : 8; /* [31:24]        r/w        */
    } CMP_CCR1;

    /* 0x10*/
    struct
    {
        uint32 HS_HSTCTR : 2;  /* [1:0]          r/w        */
        uint32 RSVD_3_2  : 2;  /* [3:2]                     */
        uint32 LS_HSTCTR : 2;  /* [5:4]          r/w        */
        uint32 RSVD_15_6 : 10; /* [15:6]                    */
        uint32 HS_PSEL   : 4;  /* [19:16]        r/w        */
        uint32 HS_MSEL   : 4;  /* [23:20]        r/w        */
        uint32 LS_PSEL   : 4;  /* [27:24]        r/w        */
        uint32 LS_MSEL   : 4;  /* [31:28]        r/w        */
    } CMP_CCR2;

    /* 0x14*/
    struct
    {
        uint32 DAC_EN      : 1; /* [0]            r/w        */
        uint32 DAC_BUFF_EN : 1; /* [1]            r/w        */
        uint32 RSVD_7_2    : 6; /* [7:2]                     */
        uint32 VREF_SEL    : 1; /* [8]            r/w        */
        uint32 RSVD_15_9   : 7; /* [15:9]                    */
        uint32 DAC_SEL     : 8; /* [23:16]        r/w        */
        uint32 RSVD_31_24  : 8; /* [31:24]                   */
    } CMP_DCR;

    /* 0x18*/
    struct
    {
        uint32 CFR_IE    : 1;  /* [0]            r/w        */
        uint32 CFF_IE    : 1;  /* [1]            r/w        */
        uint32 RSVD_31_2 : 30; /* [31:2]                    */
    } CMP_IER;

    /* 0x1C*/
    struct
    {
        uint32 CFR       : 1;  /* [0]            r/w1c      */
        uint32 CFF       : 1;  /* [1]            r/w1c      */
        uint32 RSVD_7_2  : 6;  /* [7:2]                     */
        uint32 COUT      : 1;  /* [8]            ro         */
        uint32 RSVD_31_9 : 23; /* [31:9]                    */
    } CMP_CSR;

}; /*cmp*/

struct Reg_Cmp_W
{
    /* 0x0*/
    uint32 zResverd0x0;
    /* 0x4*/
    uint32 CMP_PARAM;
    /* 0x8*/
    uint32 CMP_CCR0;
    /* 0xC*/
    uint32 CMP_CCR1;
    /* 0x10*/
    uint32 CMP_CCR2;
    /* 0x14*/
    uint32 CMP_DCR;
    /* 0x18*/
    uint32 CMP_IER;
    /* 0x1C*/
    uint32 CMP_CSR;
}; /*cmp*/

typedef volatile struct Reg_Cmp_Bf Reg_Cmp_BfType;
typedef volatile struct Reg_Cmp_W  Reg_Cmp_WType;

struct Reg_Cmu_Bf
{
    /* 0x0*/
    uint32 zResverd0x0;
    /* 0x4*/
    struct
    {
        uint32 RST_IMP   : 1;  /* [0]            r          */
        uint32 RSVD_31_1 : 31; /* [31:1]         ro         */
    } CMU_PARAM;

    /* 0x8*/
    struct
    {
        uint32 CME        : 1;  /* [0]            r/w        */
        uint32 RSVD_3_1   : 3;  /* [3:1]          ro         */
        uint32 CMMD       : 1;  /* [4]            r/w        */
        uint32 RSVD_7_5   : 3;  /* [7:5]          ro         */
        uint32 FAHTRSTE   : 1;  /* [8]            r/w        */
        uint32 FBLTRSTE   : 1;  /* [9]            r/w        */
        uint32 RSVD_15_10 : 6;  /* [15:10]        ro         */
        uint32 FAHTIE     : 1;  /* [16]           r/w        */
        uint32 FBLTIE     : 1;  /* [17]           r/w        */
        uint32 RSVD_30_18 : 13; /* [30:18]        ro         */
        uint32 LOCK       : 1;  /* [31]           r/w        */
    } CMU_CTRL;

    /* 0xC*/
    struct
    {
        uint32 MONST      : 2;  /* [1:0]          ro         */
        uint32 RSVD_3_2   : 2;  /* [3:2]          ro         */
        uint32 STARTMEA   : 1;  /* [4]            r/w        */
        uint32 RSVD_15_5  : 11; /* [15:5]         ro         */
        uint32 FAHTIF     : 1;  /* [16]           w1c        */
        uint32 FBLTIF     : 1;  /* [17]           w1c        */
        uint32 RSVD_31_18 : 14; /* [31:18]        ro         */
    } CMU_STAT;

    /* 0x10*/
    struct
    {
        uint32 MONWIN : 32; /* [31:0]         r/w        */
    } CMU_MONWIN;

    /* 0x14*/
    struct
    {
        uint32 HCT4INT : 32; /* [31:0]         r/w        */
    } CMU_CUMHCT4INT;

    /* 0x18*/
    struct
    {
        uint32 LCT4INT : 32; /* [31:0]         r/w        */
    } CMU_CUMLCT4INT;

    /* 0x1C*/
    struct
    {
        uint32 HCT4RST : 32; /* [31:0]         r/w        */
    } CMU_CUMHCT4RST;

    /* 0x20*/
    struct
    {
        uint32 LCT4RST : 32; /* [31:0]         r/w        */
    } CMU_CUMLCT4RST;

    /* 0x24*/
    struct
    {
        uint32 MEARSLT : 32; /* [31:0]         ro         */
    } CMU_CUMMEARSLT;

}; /*cmu*/

struct Reg_Cmu_W
{
    /* 0x0*/
    uint32 zResverd0x0;
    /* 0x4*/
    uint32 CMU_PARAM;
    /* 0x8*/
    uint32 CMU_CTRL;
    /* 0xC*/
    uint32 CMU_STAT;
    /* 0x10*/
    uint32 CMU_MONWIN;
    /* 0x14*/
    uint32 CMU_CUMHCT4INT;
    /* 0x18*/
    uint32 CMU_CUMLCT4INT;
    /* 0x1C*/
    uint32 CMU_CUMHCT4RST;
    /* 0x20*/
    uint32 CMU_CUMLCT4RST;
    /* 0x24*/
    uint32 CMU_CUMMEARSLT;
}; /*cmu*/

typedef volatile struct Reg_Cmu_Bf Reg_Cmu_BfType;
typedef volatile struct Reg_Cmu_W  Reg_Cmu_WType;

struct Reg_Crc_Bf
{
    /* 0x0*/
    uint32 zResverd0x0;
    /* 0x4*/
    struct
    {
        uint32 RSVD_31_0 : 32; /* [31:0]         ro         */
    } CRC_PARAM;

    /* 0x8*/
    struct
    {
        uint32 BYTE0 : 8; /* [7:0]          r/w        */
        uint32 BYTE1 : 8; /* [15:8]         r/w        */
        uint32 BYTE2 : 8; /* [23:16]        r/w        */
        uint32 BYTE3 : 8; /* [31:24]        r/w        */
    } CRC_DATA;

    /* 0xC*/
    struct
    {
        uint32 LPHW : 16; /* [15:0]         r/w        */
        uint32 HPHW : 16; /* [31:16]        r/w        */
    } CRC_POLY;

    /* 0x10*/
    struct
    {
        uint32 MODE      : 1;  /* [0]            r/w        */
        uint32 WS        : 1;  /* [1]            r/w        */
        uint32 CR        : 1;  /* [2]            r/w        */
        uint32 RSVD_3    : 1;  /* [3]            ro         */
        uint32 RT        : 2;  /* [5:4]          r/w        */
        uint32 WT        : 2;  /* [7:6]          r/w        */
        uint32 RSVD_31_8 : 24; /* [31:8]         ro         */
    } CRC_CTRL;

}; /*crc*/

struct Reg_Crc_W
{
    /* 0x0*/
    uint32 zResverd0x0;
    /* 0x4*/
    uint32 CRC_PARAM;
    /* 0x8*/
    uint32 CRC_DATA;
    /* 0xC*/
    uint32 CRC_POLY;
    /* 0x10*/
    uint32 CRC_CTRL;
}; /*crc*/

typedef volatile struct Reg_Crc_Bf Reg_Crc_BfType;
typedef volatile struct Reg_Crc_W  Reg_Crc_WType;

struct Reg_Dmamux_Bf
{
    /* 0x00 */
    struct
    {
        uint32 ENABLE    : 1;  /* [0]            r/w        */
        uint32 SRC_MUX   : 7;  /* [7:1]          r/w        */
        uint32 RSVD_31_8 : 24; /* [31:8]         reserve    */
    } DMA_MUX_CH_CFG[16];

}; /* Reg_Dmamux_Bf */

struct Reg_Dmamux_W
{
    /* 0x00 */
    uint32 DMA_MUX_CH_CFG[16];
}; /* Reg_Dmamux_W */

struct Reg_Dma_Bf
{
    /* 0x00*/
    struct
    {
        uint32 HALT      : 1;  /* [0]            r/w        */
        uint32 HOEE      : 1;  /* [1]            r/w        */
        uint32 RRCAE     : 1;  /* [2]            r/w        */
        uint32 DBGE      : 1;  /* [3]            r/w        */
        uint32 RSVD_5_4  : 2;  /* [5:4]                     */
        uint32 BUSY      : 1;  /* [6]            r/o        */
        uint32 RSVD_31_7 : 25; /* [31:7]                    */
    } DMA_CONF;

    /* 0x04*/
    struct
    {
        uint32 DMAE0      : 1;  /* [0]            r/w        */
        uint32 DMAE1      : 1;  /* [1]            r/w        */
        uint32 DMAE2      : 1;  /* [2]            r/w        */
        uint32 DMAE3      : 1;  /* [3]            r/w        */
        uint32 DMAE4      : 1;  /* [4]            r/w        */
        uint32 DMAE5      : 1;  /* [5]            r/w        */
        uint32 DMAE6      : 1;  /* [6]            r/w        */
        uint32 DMAE7      : 1;  /* [7]            r/w        */
        uint32 DMAE8      : 1;  /* [8]            r/w        */
        uint32 DMAE9      : 1;  /* [9]            r/w        */
        uint32 DMAE10     : 1;  /* [10]           r/w        */
        uint32 DMAE11     : 1;  /* [11]           r/w        */
        uint32 DMAE12     : 1;  /* [12]           r/w        */
        uint32 DMAE13     : 1;  /* [13]           r/w        */
        uint32 DMAE14     : 1;  /* [14]           r/w        */
        uint32 DMAE15     : 1;  /* [15]           r/w        */
        uint32 RSVD_31_16 : 16; /* [31:16]                   */
    } DMA_DMAE;

    uint8 zResverd0x08[4]; /*pad 0x08 - 0B*/

    /* 0x0C*/
    struct
    {
        uint32 EIE0       : 1;  /* [0]            r/w        */
        uint32 EIE1       : 1;  /* [1]            r/w        */
        uint32 EIE2       : 1;  /* [2]            r/w        */
        uint32 EIE3       : 1;  /* [3]            r/w        */
        uint32 EIE4       : 1;  /* [4]            r/w        */
        uint32 EIE5       : 1;  /* [5]            r/w        */
        uint32 EIE6       : 1;  /* [6]            r/w        */
        uint32 EIE7       : 1;  /* [7]            r/w        */
        uint32 EIE8       : 1;  /* [8]            r/w        */
        uint32 EIE9       : 1;  /* [9]            r/w        */
        uint32 EIE10      : 1;  /* [10]           r/w        */
        uint32 EIE11      : 1;  /* [11]           r/w        */
        uint32 EIE12      : 1;  /* [12]           r/w        */
        uint32 EIE13      : 1;  /* [13]           r/w        */
        uint32 EIE14      : 1;  /* [14]           r/w        */
        uint32 EIE15      : 1;  /* [15]           r/w        */
        uint32 RSVD_31_16 : 16; /* [31:16]                   */
    } DMA_EIE;

    uint8 zResverd0x010[4]; /*pad 0x010 - 013*/

    /* 0x14*/
    struct
    {
        uint32 CCDONE     : 4; /* [3:0]          w/o        */
        uint32 RSVD_5_4   : 2; /* [5:4]                     */
        uint32 CACDONE    : 1; /* [6]            w/o        */
        uint32 WPEN0      : 1; /* [7]            w/o        */
        uint32 SCSTART    : 4; /* [11:8]         w/o        */
        uint32 RSVD_13_12 : 2; /* [13:12]                   */
        uint32 SACSTART   : 1; /* [14]           w/o        */
        uint32 WPEN1      : 1; /* [15]           w/o        */
        uint32 CCES       : 4; /* [19:16]        w/o        */
        uint32 RSVD_21_20 : 2; /* [21:20]                   */
        uint32 CACES      : 1; /* [22]           w/o        */
        uint32 WPEN2      : 1; /* [23]           w/o        */
        uint32 CCIS       : 4; /* [27:24]        w/o        */
        uint32 RSVD_29_28 : 2; /* [29:28]                   */
        uint32 CACIS      : 1; /* [30]           w/o        */
        uint32 WPEN3      : 1; /* [31]           w/o        */
    } DMA_GCC;

    /* 0x18*/
    struct
    {
        uint32 DBEF       : 1;  /* [0]            r/o        */
        uint32 SBEF       : 1;  /* [1]            r/o        */
        uint32 RSVD_2     : 1;  /* [2]                       */
        uint32 NUMEF      : 1;  /* [3]            r/o        */
        uint32 DOEF       : 1;  /* [4]            r/o        */
        uint32 DAEF       : 1;  /* [5]            r/o        */
        uint32 SOEF       : 1;  /* [6]            r/o        */
        uint32 SAEF       : 1;  /* [7]            r/o        */
        uint32 CHEF       : 4;  /* [11:8]         r/o        */
        uint32 RSVD_12    : 1;  /* [12]                      */
        uint32 PRIEF      : 1;  /* [13]           r/o        */
        uint32 RSVD_14    : 1;  /* [14]                      */
        uint32 ERRF       : 1;  /* [15]           r/o        */
        uint32 RSVD_31_16 : 16; /* [31:16]                   */
    } DMA_ES;

    /* 0x1C*/
    struct
    {
        uint32 ERR0       : 1;  /* [0]            r/o        */
        uint32 ERR1       : 1;  /* [1]            r/o        */
        uint32 ERR2       : 1;  /* [2]            r/o        */
        uint32 ERR3       : 1;  /* [3]            r/o        */
        uint32 ERR4       : 1;  /* [4]            r/o        */
        uint32 ERR5       : 1;  /* [5]            r/o        */
        uint32 ERR6       : 1;  /* [6]            r/o        */
        uint32 ERR7       : 1;  /* [7]            r/o        */
        uint32 ERR8       : 1;  /* [8]            r/o        */
        uint32 ERR9       : 1;  /* [9]            r/o        */
        uint32 ERR10      : 1;  /* [10]           r/o        */
        uint32 ERR11      : 1;  /* [11]           r/o        */
        uint32 ERR12      : 1;  /* [12]           r/o        */
        uint32 ERR13      : 1;  /* [13]           r/o        */
        uint32 ERR14      : 1;  /* [14]           r/o        */
        uint32 ERR15      : 1;  /* [15]           r/o        */
        uint32 RSVD_31_16 : 16; /* [31:16]                   */
    } DMA_CES;

    /* 0x20*/
    struct
    {
        uint32 INT0       : 1;  /* [0]            r/o        */
        uint32 INT1       : 1;  /* [1]            r/o        */
        uint32 INT2       : 1;  /* [2]            r/o        */
        uint32 INT3       : 1;  /* [3]            r/o        */
        uint32 INT4       : 1;  /* [4]            r/o        */
        uint32 INT5       : 1;  /* [5]            r/o        */
        uint32 INT6       : 1;  /* [6]            r/o        */
        uint32 INT7       : 1;  /* [7]            r/o        */
        uint32 INT8       : 1;  /* [8]            r/o        */
        uint32 INT9       : 1;  /* [9]            r/o        */
        uint32 INT10      : 1;  /* [10]           r/o        */
        uint32 INT11      : 1;  /* [11]           r/o        */
        uint32 INT12      : 1;  /* [12]           r/o        */
        uint32 INT13      : 1;  /* [13]           r/o        */
        uint32 INT14      : 1;  /* [14]           r/o        */
        uint32 INT15      : 1;  /* [15]           r/o        */
        uint32 RSVD_31_16 : 16; /* [31:16]                   */
    } DMA_CIS;

    /* 0x24*/
    struct
    {
        uint32 HRS0       : 1;  /* [0]            r/o        */
        uint32 HRS1       : 1;  /* [1]            r/o        */
        uint32 HRS2       : 1;  /* [2]            r/o        */
        uint32 HRS3       : 1;  /* [3]            r/o        */
        uint32 HRS4       : 1;  /* [4]            r/o        */
        uint32 HRS5       : 1;  /* [5]            r/o        */
        uint32 HRS6       : 1;  /* [6]            r/o        */
        uint32 HRS7       : 1;  /* [7]            r/o        */
        uint32 HRS8       : 1;  /* [8]            r/o        */
        uint32 HRS9       : 1;  /* [9]            r/o        */
        uint32 HRS10      : 1;  /* [10]           r/o        */
        uint32 HRS11      : 1;  /* [11]           r/o        */
        uint32 HRS12      : 1;  /* [12]           r/o        */
        uint32 HRS13      : 1;  /* [13]           r/o        */
        uint32 HRS14      : 1;  /* [14]           r/o        */
        uint32 HRS15      : 1;  /* [15]           r/o        */
        uint32 RSVD_31_16 : 16; /* [31:16]                   */
    } DMA_CHRS;

    /* 0x28*/
    struct
    {
        uint32 CPRI3      : 4; /* [3:0]          r/w        */
        uint32 RSVD_5_4   : 2; /* [5:4]                     */
        uint32 CPDIS3     : 1; /* [6]            r/w        */
        uint32 CSE3       : 1; /* [7]            r/w        */
        uint32 CPRI2      : 4; /* [11:8]         r/w        */
        uint32 RSVD_13_12 : 2; /* [13:12]                   */
        uint32 CPDIS2     : 1; /* [14]           r/w        */
        uint32 CSE2       : 1; /* [15]           r/w        */
        uint32 CPRI1      : 4; /* [19:16]        r/w        */
        uint32 RSVD_21_20 : 2; /* [21:20]                   */
        uint32 CPDIS1     : 1; /* [22]           r/w        */
        uint32 CSE1       : 1; /* [23]           r/w        */
        uint32 CPRI0      : 4; /* [27:24]        r/w        */
        uint32 RSVD_29_28 : 2; /* [29:28]                   */
        uint32 CPDIS0     : 1; /* [30]           r/w        */
        uint32 CSE0       : 1; /* [31]           r/w        */
    } DMA_CPRI0;

    /* 0x2C*/
    struct
    {
        uint32 CPRI7      : 4; /* [3:0]          r/w        */
        uint32 RSVD_5_4   : 2; /* [5:4]                     */
        uint32 CPDIS7     : 1; /* [6]            r/w        */
        uint32 CSE7       : 1; /* [7]            r/w        */
        uint32 CPRI6      : 4; /* [11:8]         r/w        */
        uint32 RSVD_13_12 : 2; /* [13:12]                   */
        uint32 CPDIS6     : 1; /* [14]           r/w        */
        uint32 CSE6       : 1; /* [15]           r/w        */
        uint32 CPRI5      : 4; /* [19:16]        r/w        */
        uint32 RSVD_21_20 : 2; /* [21:20]                   */
        uint32 CPDIS5     : 1; /* [22]           r/w        */
        uint32 CSE5       : 1; /* [23]           r/w        */
        uint32 CPRI4      : 4; /* [27:24]        r/w        */
        uint32 RSVD_29_28 : 2; /* [29:28]                   */
        uint32 CPDIS4     : 1; /* [30]           r/w        */
        uint32 CSE4       : 1; /* [31]           r/w        */
    } DMA_CPRI1;

    /* 0x30*/
    struct
    {
        uint32 CPRI11     : 4; /* [3:0]          r/w        */
        uint32 RSVD_5_4   : 2; /* [5:4]                     */
        uint32 CPDIS11    : 1; /* [6]            r/w        */
        uint32 CSE11      : 1; /* [7]            r/w        */
        uint32 CPRI10     : 4; /* [11:8]         r/w        */
        uint32 RSVD_13_12 : 2; /* [13:12]                   */
        uint32 CPDIS10    : 1; /* [14]           r/w        */
        uint32 CSE10      : 1; /* [15]           r/w        */
        uint32 CPRI9      : 4; /* [19:16]        r/w        */
        uint32 RSVD_21_20 : 2; /* [21:20]                   */
        uint32 CPDIS9     : 1; /* [22]           r/w        */
        uint32 CSE9       : 1; /* [23]           r/w        */
        uint32 CPRI8      : 4; /* [27:24]        r/w        */
        uint32 RSVD_29_28 : 2; /* [29:28]                   */
        uint32 CPDIS8     : 1; /* [30]           r/w        */
        uint32 CSE8       : 1; /* [31]           r/w        */
    } DMA_CPRI2;

    /* 0x34*/
    struct
    {
        uint32 CPRI15     : 4; /* [3:0]          r/w        */
        uint32 RSVD_5_4   : 2; /* [5:4]                     */
        uint32 CPDIS15    : 1; /* [6]            r/w        */
        uint32 CSE15      : 1; /* [7]            r/w        */
        uint32 CPRI14     : 4; /* [11:8]         r/w        */
        uint32 RSVD_13_12 : 2; /* [13:12]                   */
        uint32 CPDIS14    : 1; /* [14]           r/w        */
        uint32 CSE14      : 1; /* [15]           r/w        */
        uint32 CPRI13     : 4; /* [19:16]        r/w        */
        uint32 RSVD_21_20 : 2; /* [21:20]                   */
        uint32 CPDIS13    : 1; /* [22]           r/w        */
        uint32 CSE13      : 1; /* [23]           r/w        */
        uint32 CPRI12     : 4; /* [27:24]        r/w        */
        uint32 RSVD_29_28 : 2; /* [29:28]                   */
        uint32 CPDIS12    : 1; /* [30]           r/w        */
        uint32 CSE12      : 1; /* [31]           r/w        */
    } DMA_CPRI3;

    uint8 zResverd0x038[456]; /*pad 0x038 - 01FF*/

    struct
    {
        /* 0x200*/
        struct
        {
            uint32 SADDR : 32; /* [31:0]         r/w        */
        } DMA_SADDR;

        /* 0x204*/
        struct
        {
            uint32 DADDR : 32; /* [31:0]         r/w        */
        } DMA_DADDR;

        /* 0x208*/
        struct
        {
            sint32 SAOFF : 16; /* [15:0]         r/w        */
            sint32 DAOFF : 16; /* [31:16]        r/w        */
        } DMA_AOFF;

        /* 0x20C*/
        struct
        {
            sint32 MLSAOFF : 16; /* [15:0]         r/w        */
            sint32 MLDAOFF : 16; /* [31:16]        r/w        */
        } DMA_MLAOFF;

        /* 0x210*/
        struct
        {
            uint32 NUM : 32; /* [31:0]         r/w        */
        } DMA_NUM;

        /* 0x214*/
        struct
        {
            uint32 MLITER : 16; /* [15:0]         r/w        */
            uint32 MLSTA  : 16; /* [31:16]        r/o        */
        } DMA_ITER;

        /* 0x218*/
        struct
        {
            uint32 START      : 1; /* [0]            r/w        */
            uint32 INTE       : 1; /* [1]            r/w        */
            uint32 RSVD_2     : 1; /* [2]                       */
            uint32 REQDIS     : 1; /* [3]            r/w        */
            uint32 RSVD_5_4   : 2; /* [5:4]                     */
            uint32 BUSY       : 1; /* [6]            r/o        */
            uint32 DONE       : 1; /* [7]            r/w        */
            uint32 RSVD_15_8  : 8; /* [15:8]                    */
            uint32 DSIZE      : 2; /* [17:16]        r/w        */
            uint32 RSVD_23_18 : 6; /* [23:18]                   */
            uint32 SSIZE      : 2; /* [25:24]        r/w        */
            uint32 RSVD_31_26 : 6; /* [31:26]                   */
        } DMA_CS;

        uint8 zResverd[4]; /*pad 4 bytes*/
    } DMA_CH_CONFIG[16];
}; /*dma_reg*/

struct Reg_Dma_W
{
    /* 0x00*/
    uint32 DMA_CONF;
    /* 0x04*/
    uint32 DMA_DMAE;
    uint8  zResverd0x08[4]; /*pad 0x08 - 0B*/

    /* 0x0C*/
    uint32 DMA_EIE;
    uint8  zResverd0x010[4]; /*pad 0x010 - 013*/

    /* 0x14*/
    uint32 DMA_GCC;
    /* 0x18*/
    uint32 DMA_ES;
    /* 0x1C*/
    uint32 DMA_CES;
    /* 0x20*/
    uint32 DMA_CIS;
    /* 0x24*/
    uint32 DMA_CHRS;
    /* 0x28*/
    uint32 DMA_CPRI0;
    /* 0x2C*/
    uint32 DMA_CPRI1;
    /* 0x30*/
    uint32 DMA_CPRI2;
    /* 0x34*/
    uint32 DMA_CPRI3;
    uint8  zResverd0x038[456]; /*pad 0x038 - 01FF*/

    struct
    {
        /* 0x200*/
        uint32 DMA_SADDR;
        /* 0x204*/
        uint32 DMA_DADDR;
        /* 0x208*/
        uint32 DMA_AOFF;
        /* 0x20C*/
        uint32 DMA_MLAOFF;
        /* 0x210*/
        uint32 DMA_NUM;
        /* 0x214*/
        uint32 DMA_ITER;
        /* 0x218*/
        uint32 DMA_CS;

        uint8 zResverd[4]; /*pad 4 bytes*/
    } DMA_CH_CONFIG[16];
}; /*dma_reg*/

typedef volatile struct Reg_Dmamux_Bf Reg_Dmamux_BfType;
typedef volatile struct Reg_Dmamux_W  Reg_Dmamux_WType;

typedef volatile struct Reg_Dma_Bf Reg_Dma_BfType;
typedef volatile struct Reg_Dma_W  Reg_Dma_WType;

struct Reg_Eiru_Bf
{
    /* 0x00*/
    struct
    {
        uint32 SRAM0_ER_DIS  : 1;  /* [0]            r/w        */
        uint32 SRAM0_EW_DIS  : 1;  /* [1]            r/w        */
        uint32 SRAM0_ESB_DIS : 1;  /* [2]            r/w        */
        uint32 SRAM0_EMB_DIS : 1;  /* [3]            r/w        */
        uint32 SRAM0_EEI_EN  : 1;  /* [4]            r/w        */
        uint32 RSVD_7_5      : 3;  /* [7:5]          ro         */
        uint32 SRAM1_ER_DIS  : 1;  /* [8]            r/w        */
        uint32 SRAM1_EW_DIS  : 1;  /* [9]            r/w        */
        uint32 SRAM1_ESB_DIS : 1;  /* [10]           r/w        */
        uint32 SRAM1_EMB_DIS : 1;  /* [11]           r/w        */
        uint32 SRAM1_EEI_EN  : 1;  /* [12]           r/w        */
        uint32 RSVD_30_13    : 18; /* [30:13]        ro         */
        uint32 LOCK          : 1;  /* [31]           r/w        */
    } EIRU_CR;

    /* 0x04*/
    struct
    {
        uint32 RSVD_1_0 : 2;  /* [1:0]          ro         */
        uint32 EEIADDR  : 30; /* [31:2]         r/w        */
    } EIRU_EEIADDR;

    uint8 zResverd0x08[8]; /*pad 0x08 - 0F*/
    struct
    {
        /* 0x10*/
        struct
        {
            uint32 EFPROT     : 4;  /* [3:0]          ro         */
            uint32 EFSIZE     : 3;  /* [6:4]          ro         */
            uint32 RSVD_7     : 1;  /* [7]            ro         */
            uint32 EFMST      : 8;  /* [15:8]         ro         */
            uint32 RSVD_28_16 : 13; /* [28:16]        ro         */
            uint32 SBERR      : 1;  /* [29]           w1c        */
            uint32 MBERR      : 1;  /* [30]           w1c        */
            uint32 OVERRUN    : 1;  /* [31]           w1c        */
        } EIRU_SRAMn_EESR;

        /* 0x14*/
        struct
        {
            uint32 EFADDR : 32; /* [31:0]         ro         */
        } EIRU_SRAMn_FADDR;

        /* 0x18*/
        struct
        {
            uint32 EFDATA : 32; /* [31:0]         ro         */
        } EIRU_SRAMn_FDATA;

        /* 0x1C*/
        struct
        {
            uint32 ECCMASK   : 7;  /* [6:0]          r/w        */
            uint32 RSVD_31_7 : 25; /* [31:7]                    */
        } EIRU_SRAMn_ECCMASK;

        /* 0x20*/
        struct
        {
            uint32 DATAMASK : 32; /* [31:0]         r/w        */
        } EIRU_SRAMn_DATAMASK;
        uint8 zResverd0x024[12]; /*pad 0x24 - 2F*/
    } EIRU_SRAMn_SC[2];
}; /*eiru*/

struct Reg_Eiru_W
{
    /* 0x00*/
    uint32 EIRU_CR;
    /* 0x04*/
    uint32 EIRU_EEIADDR;
    uint8  zResverd0x08[8]; /*pad 0x08 - 0F*/
    struct
    {
        /* 0x10*/
        uint32 EIRU_SRAMn_EESR;
        /* 0x14*/
        uint32 EIRU_SRAMn_FADDR;
        /* 0x18*/
        uint32 EIRU_SRAMn_FDATA;
        /* 0x1C*/
        uint32 EIRU_SRAMn_ECCMASK;
        /* 0x20*/
        uint32 EIRU_SRAMn_DATAMASK;
        uint8  zResverd0x024[12]; /*pad 0x24 - 2F*/
    } EIRU_SRAMn_SC[2];
}; /*eiru*/

typedef volatile struct Reg_Eiru_Bf Reg_Eiru_BfType;
typedef volatile struct Reg_Eiru_W  Reg_Eiru_WType;

struct Reg_Ewdt_Bf
{
    /* 0x0*/
    uint32 zResverd0x0;
    /* 0x4*/
    struct
    {
        uint32 RSVD_31_0 : 32; /* [31:0]         ro         */
    } EWDT_PARAM;

    /* 0x8*/
    struct
    {
        uint32 EWDTE      : 1;  /* [0]            r/w        */
        uint32 DEBUGE     : 1;  /* [1]            r/w        */
        uint32 WAITE      : 1;  /* [2]            r/w        */
        uint32 RSVD_3     : 1;  /* [3]            ro         */
        uint32 INTE       : 1;  /* [4]            r/w        */
        uint32 INPE       : 1;  /* [5]            r/w        */
        uint32 INPP       : 1;  /* [6]            r/w        */
        uint32 RSVD_23_7  : 17; /* [23:7]                    */
        uint32 INTF       : 1;  /* [24]           w1c        */
        uint32 RSVD_31_25 : 7;  /* [31:25]        ro         */
    } EWDT_CS;

    /* 0xC*/
    struct
    {
        uint32 COMPH : 32; /* [31:0]         r/w        */
    } EWDT_COMPH;

    /* 0x10*/
    struct
    {
        uint32 COMPL : 32; /* [31:0]         r/w        */
    } EWDT_COMPL;

    /* 0x14*/
    struct
    {
        uint32 CNT : 32; /* [31:0]         r/w        */
    } EWDT_CNT;

}; /*ewdt*/

struct Reg_Ewdt_W
{
    /* 0x0*/
    uint32 zResverd0x0;
    /* 0x4*/
    uint32 EWDT_PARAM;
    /* 0x8*/
    uint32 EWDT_CS;
    /* 0xC*/
    uint32 EWDT_COMPH;
    /* 0x10*/
    uint32 EWDT_COMPL;
    /* 0x14*/
    uint32 EWDT_CNT;
}; /*ewdt*/

typedef volatile struct Reg_Ewdt_Bf Reg_Ewdt_BfType;
typedef volatile struct Reg_Ewdt_W  Reg_Ewdt_WType;

struct Reg_Flash_Bf
{
    /* 0x0*/
    struct
    {
        uint32 FAIL           : 1;  /* [0]            r          */
        uint32 RSVD_1         : 1;  /* [1]            r          */
        uint32 CMDABT         : 1;  /* [2]            r/w1c      */
        uint32 RSVD_4_3       : 2;  /* [4:3]          r          */
        uint32 ACCERR         : 1;  /* [5]            r/w1c      */
        uint32 PREABT         : 1;  /* [6]            r/w1c      */
        uint32 CCIF           : 1;  /* [7]            r/w1c      */
        uint32 RSVD_10_8      : 3;  /* [10:8]         r          */
        uint32 CMDWRF         : 1;  /* [11]           r          */
        uint32 RSVD_15_12     : 4;  /* [15:12]        r          */
        uint32 DFDIF          : 1;  /* [16]           r/w1c      */
        uint32 SFDIF          : 1;  /* [17]           r/w1c      */
        uint32 RSVD_29_18     : 12; /* [29:18]        r          */
        uint32 DBG_ERSALL_DIS : 1;  /* [30]           r          */
        uint32 FSEC           : 1;  /* [31]           r          */
    } FLASH_FSTAT;

    /* 0x4*/
    struct
    {
        uint32 BK_QUERY    : 1;  /* [0]            r/w        */
        uint32 RSVD_6_1    : 6;  /* [6:1]          r          */
        uint32 CCIE        : 1;  /* [7]            r/w        */
        uint32 DBG_ERS_FLG : 1;  /* [8]            r          */
        uint32 RSVD_15_9   : 7;  /* [15:9]         r          */
        uint32 DFDIE       : 1;  /* [16]           r/w        */
        uint32 SFDIE       : 1;  /* [17]           r/w        */
        uint32 RSVD_31_18  : 14; /* [31:18]        r          */
    } FLASH_FCNFG;

    /* 0x8*/
    struct
    {
        uint32 RWSC       : 4; /* [3:0]          r/w        */
        uint32 RSVD_7_4   : 4; /* [7:4]          r          */
        uint32 LSMODE     : 1; /* [8]            r/w        */
        uint32 RSVD_15_9  : 7; /* [15:9]         r          */
        uint32 FECCF      : 1; /* [16]           r/w        */
        uint32 RSVD_23_17 : 7; /* [23:17]        r          */
        uint32 ABTREQ     : 1; /* [24]           r/w        */
        uint32 RSVD_31_25 : 7; /* [31:25]        r          */
    } FLASH_FCTRL;

    uint8 zResverd0x0C[4]; /*pad 0x0C - 0F*/

    /* 0x10*/
    struct
    {
        uint32 CMDCODE   : 8;  /* [7:0]          r/w        */
        uint32 RSVD_31_8 : 24; /* [31:8]         r          */
    } FLASH_FCMD;

    uint8 zResverd0x14[4]; /*pad 0x14 - 0x17*/

    /* 0x18*/
    struct
    {
        uint32 CMDADDR : 32; /* [31:0]         r/w        */
    } FLASH_FADDR;

    /* 0x1C*/
    struct
    {
        uint32 CMDADDRE : 32; /* [31:0]         r/w        */
    } FLASH_FADDR_END;

    /* 0x20*/
    struct
    {
        uint32 CMDDATA0 : 32; /* [31:0]         r/w        */
    } FLASH_FDATA0;

    /* 0x24*/
    struct
    {
        uint32 CMDDATA1 : 32; /* [31:0]         r/w        */
    } FLASH_FDATA1;

    /* 0x28*/
    struct
    {
        uint32 CMDDATA2 : 32; /* [31:0]         r/w        */
    } FLASH_FDATA2;

    /* 0x2C*/
    struct
    {
        uint32 CMDDATA3 : 32; /* [31:0]         r/w        */
    } FLASH_FDATA3;

    /* 0x30*/
    struct
    {
        uint32 RSVD_3_0      : 4;  /* [3:0]          r          */
        uint32 BED_ADDR_STRT : 28; /* [31:4]         r/w        */
    } FLASH_BED_ADDR_STRT;

    /* 0x34*/
    struct
    {
        uint32 RSVD_3_0     : 4;  /* [3:0]          r          */
        uint32 BED_ADDR_END : 28; /* [31:4]         r/w        */
    } FLASH_BED_ADDR_END;

    /* 0x38*/
    struct
    {
        uint32 RSVD_3_0    : 4;  /* [3:0]          r          */
        uint32 ECC_IN_ADDR : 28; /* [31:4]         r/w        */
    } FLASH_ECC_IN_ADDR;

    /* 0x3C*/
    struct
    {
        uint32 ECC_9BIT   : 9;  /* [8:0]          r/w        */
        uint32 ECC_IN_EN  : 1;  /* [9]            r/w        */
        uint32 RSVD_30_10 : 21; /* [30:10]        r          */
        uint32 LOCK       : 1;  /* [31]           r/w        */
    } FLASH_ECC_IN_CTRL;

    /* 0x40*/
    struct
    {
        uint32 MBE_FLAG    : 1;  /* [0]            r/w1c      */
        uint32 MBE_OVERRUN : 1;  /* [1]            ro         */
        uint32 RSVD_3_2    : 2;  /* [3:2]          r          */
        uint32 MBE_ADDR    : 28; /* [31:4]         ro         */
    } FLASH_MBE_STATE;

    /* 0x44*/
    struct
    {
        uint32 SBE_FLAG    : 1;  /* [0]            r/w1c      */
        uint32 SBE_OVERRUN : 1;  /* [1]            ro         */
        uint32 RSVD_3_2    : 2;  /* [3:2]          r          */
        uint32 SBE_ADDR    : 28; /* [31:4]         ro         */
    } FLASH_SBE_STATE;

}; /*flash*/

struct Reg_Flash_W
{
    /* 0x0*/
    uint32 FLASH_FSTAT;
    /* 0x4*/
    uint32 FLASH_FCNFG;
    /* 0x8*/
    uint32 FLASH_FCTRL;
    uint8  zResverd0x0C[4]; /*pad 0x0C - 0F*/

    /* 0x10*/
    uint32 FLASH_FCMD;
    uint8  zResverd0x14[4]; /*pad 0x14 - 0x17*/
    /* 0x18*/
    uint32 FLASH_FADDR;
    /* 0x1C*/
    uint32 FLASH_FADDR_END;
    /* 0x20*/
    uint32 FLASH_FDATA0;
    /* 0x24*/
    uint32 FLASH_FDATA1;
    /* 0x28*/
    uint32 FLASH_FDATA2;
    /* 0x2C*/
    uint32 FLASH_FDATA3;
    /* 0x30*/
    uint32 FLASH_BED_ADDR_STRT;
    /* 0x34*/
    uint32 FLASH_BED_ADDR_END;
    /* 0x38*/
    uint32 FLASH_ECC_IN_ADDR;
    /* 0x3C*/
    uint32 FLASH_ECC_IN_CTRL;
    /* 0x40*/
    uint32 FLASH_MBE_STATE;
    /* 0x44*/
    uint32 FLASH_SBE_STATE;
}; /*flash*/

typedef volatile struct Reg_Flash_Bf Reg_Flash_BfType;
typedef volatile struct Reg_Flash_W  Reg_Flash_WType;

struct Reg_Gpio_Bf
{
    /* 0x0*/
    struct
    {
        uint32 PDO : 32; /* [31:0]         r/w        */
    } GPIOx_PDOR;

    /* 0x4*/
    struct
    {
        uint32 PSO : 32; /* [31:0]         wo         */
    } GPIOx_PSOR;

    /* 0x8*/
    struct
    {
        uint32 PCO : 32; /* [31:0]         wo         */
    } GPIOx_PCOR;

    /* 0xC*/
    struct
    {
        uint32 PTO : 32; /* [31:0]         wo         */
    } GPIOx_PTOR;

    /* 0x10*/
    struct
    {
        uint32 PDI : 32; /* [31:0]         ro         */
    } GPIOx_PDIR;

    /* 0x14*/
    struct
    {
        uint32 PDD : 32; /* [31:0]         r/w        */
    } GPIOx_PDDR;

}; /*gpio_reg*/

struct Reg_Gpio_W
{
    /* 0x0 */
    uint32 GPIOx_PDOR;
    /* 0x4 */
    uint32 GPIOx_PSOR;
    /* 0x8 */
    uint32 GPIOx_PCOR;
    /* 0xC */
    uint32 GPIOx_PTOR;
    /* 0x10 */
    uint32 GPIOx_PDIR;
    /* 0x14 */
    uint32 GPIOx_PDDR;

}; /* gpio_reg */

typedef volatile struct Reg_Gpio_Bf Reg_Gpio_BfType;
typedef volatile struct Reg_Gpio_W  Reg_Gpio_WType;

struct Reg_I2c_Bf
{
    /* 0x00*/
    uint32 zResverd0x00;
    /* 0x04*/
    struct
    {
        uint32 I2C_SUPPORT_SPEED : 2;  /* [1:0]          ro         */
        uint32 DMA_SUPPORT       : 1;  /* [2]            ro         */
        uint32 TXFIFO_DEPTH      : 4;  /* [6:3]          ro         */
        uint32 RXFIFO_DEPTH      : 4;  /* [10:7]         ro         */
        uint32 RSVD_31_11        : 21; /* [31:11]        ro         */
    } I2C_PARAMETER;

    /* 0x08*/
    struct
    {
        uint32 MODULE_EN             : 1;  /* [0]            r/w        */
        uint32 SLAVE_ACK_GENCALL     : 1;  /* [1]            r/w        */
        uint32 SLAVE_NACK            : 1;  /* [2]            r/w        */
        uint32 SDA_RECOVER_EN        : 1;  /* [3]            r/w        */
        uint32 MASTER_ABORT          : 1;  /* [4]            r/w        */
        uint32 MASTER_BUS_RECOVER_EN : 1;  /* [5]            r/w        */
        uint32 MASTER_BLK_TXFIFO     : 1;  /* [6]            r/w        */
        uint32 H_MCODE               : 3;  /* [9:7]          r/w        */
        uint32 RSVD_31_10            : 22; /* [31:10]        ro         */
    } I2C_CONFIG0;

    /* 0x0c*/
    struct
    {
        uint32 SLAVE_MODE_DIS        : 1;  /* [0]            r/w        */
        uint32 MASTER_MODE_EN        : 1;  /* [1]            r/w        */
        uint32 MASTER_RESTART_EN     : 1;  /* [2]            r/w        */
        uint32 SLAVE_STOP_DET_EN     : 1;  /* [3]            r/w        */
        uint32 MASTER_STOP_DET_EN    : 1;  /* [4]            r/w        */
        uint32 TXFIFO_EMPTY_EN       : 1;  /* [5]            r/w        */
        uint32 SPEED_SEL             : 2;  /* [7:6]          r/w        */
        uint32 HOLD_EN_RXFIFO_FULL   : 1;  /* [8]            r/w        */
        uint32 SLAVE_10BIT_ADDR_SEL  : 1;  /* [9]            r/w        */
        uint32 MASTER_10BIT_ADDR_SEL : 1;  /* [10]           r/w        */
        uint32 RSVD_31_11            : 21; /* [31:11]        ro         */
    } I2C_CONFIG1;

    /* 0x10*/
    struct
    {
        uint32 SDA_SETUP_TIMING : 8;  /* [7:0]          r/w        */
        uint32 RSVD_31_8        : 24; /* [31:8]         ro         */
    } I2C_SDA_SETUP_TIMING;

    /* 0x14*/
    struct
    {
        uint32 SDA_TX_HOLD_TIMING : 16; /* [15:0]         r/w        */
        uint32 SDA_RX_HOLD_TIMING : 8;  /* [23:16]        r/w        */
        uint32 RSVD_31_24         : 8;  /* [31:24]        ro         */
    } I2C_SDA_HOLD_TIMING;

    /* 0x18*/
    struct
    {
        uint32 RXFIFO_DMA_EN        : 1;  /* [0]            r/w        */
        uint32 TXFIFO_DMA_EN        : 1;  /* [1]            r/w        */
        uint32 DMA_TXFIFO_WATERMARK : 2;  /* [3:2]          r/w        */
        uint32 DMA_RXFIFO_WATERMARK : 2;  /* [5:4]          r/w        */
        uint32 RSVD_31_6            : 26; /* [31:6]         ro         */
    } I2C_DMA_CTRL;

    /* 0x1c*/
    struct
    {
        uint32 I2C_CALL_IE         : 1;  /* [0]            r/w        */
        uint32 I2C_TX_OVF_IE       : 1;  /* [1]            r/w        */
        uint32 I2C_ERROR_ABORT_IE  : 1;  /* [2]            r/w        */
        uint32 I2C_ACTIVITY_DET_IE : 1;  /* [3]            r/w        */
        uint32 I2C_STOP_DET_IE     : 1;  /* [4]            r/w        */
        uint32 I2C_START_DET_IE    : 1;  /* [5]            r/w        */
        uint32 RSVD_21_6           : 16; /* [21:6]         ro         */
        uint32 SLAVE_RD_REQ_IE     : 1;  /* [22]           r/w        */
        uint32 RX_DONE_IE          : 1;  /* [23]           r/w        */
        uint32 RX_UNDER_IE         : 1;  /* [24]           r/w        */
        uint32 RX_OVF_IE           : 1;  /* [25]           r/w        */
        uint32 RESTART_DET_IE      : 1;  /* [26]           r/w        */
        uint32 SCL_STUCK_AT_LOW_IE : 1;  /* [27]           r/w        */
        uint32 RSVD_29_28          : 2;  /* [29:28]        ro         */
        uint32 RX_FULL_IE          : 1;  /* [30]           r/w        */
        uint32 TX_EMPTY_IE         : 1;  /* [31]           r/w        */
    } I2C_INT_ENABLE;

    /* 0x20*/
    struct
    {
        uint32 DATA                 : 8;  /* [7:0]          r/w        */
        uint32 CMD_MASTER_DIRECTION : 1;  /* [8]            wo         */
        uint32 CMD_STOP             : 1;  /* [9]            wo         */
        uint32 CMD_RESTART          : 1;  /* [10]           wo         */
        uint32 RSVD_31_11           : 21; /* [31:11]        ro         */
    } I2C_COMMAND_DATA;

    /* 0x24*/
    struct
    {
        uint32 DEST_ADDR      : 10; /* [9:0]          r/w        */
        uint32 MASTER_CMD_SEL : 2;  /* [11:10]        r/w        */
        uint32 RSVD_31_12     : 20; /* [31:12]        ro         */
    } I2C_DEST_ADDR;

    /* 0x28*/
    struct
    {
        uint32 SLV_ADDR   : 10; /* [9:0]          r/w        */
        uint32 RSVD_31_10 : 22; /* [31:10]        ro         */
    } I2C_SLAVE_ADDR;

    /* 0x2c*/
    struct
    {
        uint32 STD_SCL_HCNT : 16; /* [15:0]         r/w        */
        uint32 RSVD_31_16   : 16; /* [31:16]        ro         */
    } I2C_STD_SCL_HCNT;

    /* 0x30*/
    struct
    {
        uint32 STD_SCL_LCNT : 16; /* [15:0]         r/w        */
        uint32 RSVD_31_16   : 16; /* [31:16]        ro         */
    } I2C_STD_SCL_LCNT;

    /* 0x34*/
    struct
    {
        uint32 FST_SCL_HCNT : 16; /* [15:0]         r/w        */
        uint32 RSVD_31_16   : 16; /* [31:16]        reserve    */
    } I2C_FST_SCL_HCNT;

    /* 0x38*/
    struct
    {
        uint32 FST_SCL_LCNT : 16; /* [15:0]         r/w        */
        uint32 RSVD_31_16   : 16; /* [31:16]        ro         */
    } I2C_FST_SCL_LCNT;

    /* 0x3c*/
    struct
    {
        uint32 HS_SCL_HCNT : 16; /* [15:0]         r/w        */
        uint32 RSVD_31_16  : 16; /* [31:16]        ro         */
    } I2C_HS_SCL_HCNT;

    /* 0x40*/
    struct
    {
        uint32 HS_SCL_LCNT : 16; /* [15:0]         r/w        */
        uint32 RSVD_31_16  : 16; /* [31:16]        ro         */
    } I2C_HS_SCL_LCNT;

    /* 0x44*/
    struct
    {
        uint32 RXFIFO_WATER_MARK : 2;  /* [1:0]          r/w        */
        uint32 RSVD_31_2         : 30; /* [31:2]         ro         */
    } I2C_RXFIFO_WATER_MARK;

    /* 0x48*/
    struct
    {
        uint32 TXFIFO_WATER_MARK : 2;  /* [1:0]          r/w        */
        uint32 RSVD_31_2         : 30; /* [31:2]         ro         */
    } I2C_TXFIFO_WATER_MARK;

    /* 0x4c*/
    struct
    {
        uint32 TX_FIFO_CNT : 3;  /* [2:0]          ro         */
        uint32 RSVD_31_3   : 29; /* [31:3]         ro         */
    } I2C_TX_FIFO_CNT;

    /* 0x50*/
    struct
    {
        uint32 RX_FIFO_CNT : 3;  /* [2:0]          ro         */
        uint32 RSVD_31_3   : 29; /* [31:3]         ro         */
    } I2C_RX_FIFO_CNT;

    /* 0x54*/
    struct
    {
        uint32 FSTD_SPKLEN : 8;  /* [7:0]          r/w        */
        uint32 RSVD_31_8   : 24; /* [31:8]         ro         */
    } I2C_FSTD_SPKCNT;

    /* 0x58*/
    struct
    {
        uint32 HS_SPKLEN : 8;  /* [7:0]          r/w        */
        uint32 RSVD_31_8 : 24; /* [31:8]         ro         */
    } I2C_HS_SPKCNT;

    /* 0x5c*/
    struct
    {
        uint32 GENERAL_CALL     : 1;  /* [0]            w1c        */
        uint32 TXFIFO_OVERUN    : 1;  /* [1]            w1c        */
        uint32 ERROR_ABORT      : 1;  /* [2]            w1c        */
        uint32 ACTIVITY         : 1;  /* [3]            w1c        */
        uint32 STOP_DETECT      : 1;  /* [4]            w1c        */
        uint32 START_DETECT     : 1;  /* [5]            w1c        */
        uint32 RSVD_21_6        : 16; /* [21:6]         ro         */
        uint32 SLAVE_READ_REQ   : 1;  /* [22]           w1c        */
        uint32 RXFIFO_DONE      : 1;  /* [23]           w1c        */
        uint32 RXFIFO_UNDERUN   : 1;  /* [24]           w1c        */
        uint32 RXFIFO_OVERUN    : 1;  /* [25]           w1c        */
        uint32 RESTART_DET      : 1;  /* [26]           w1c        */
        uint32 SCL_STUCK_AT_LOW : 1;  /* [27]           w1c        */
        uint32 RSVD_29_28       : 2;  /* [29:28]        ro         */
        uint32 RXFIFO_FULL      : 1;  /* [30]           ro         */
        uint32 TXFIFO_EMPTY     : 1;  /* [31]           ro         */
    } I2C_STATUS0;

    /* 0x60*/
    struct
    {
        uint32 MASTER_IS_ACTIVE            : 1;  /* [0]            ro         */
        uint32 SLAVE_IS_ACTIVE             : 1;  /* [1]            ro         */
        uint32 TXFIFO_EMPTY_MASTER_HOLD    : 1;  /* [2]            ro         */
        uint32 TXFIFO_EMPTY_SLAVE_HOLD     : 1;  /* [3]            ro         */
        uint32 RXFIFO_FULL_MASTER_HOLD     : 1;  /* [4]            ro         */
        uint32 RXFIFO_FULL_SLAVE_HOLD      : 1;  /* [5]            ro         */
        uint32 TXFIO_IS_NOT_FULL           : 1;  /* [6]            ro         */
        uint32 TXFIFO_IS_EMPTY             : 1;  /* [7]            ro         */
        uint32 RXFIFO_IS_NOT_EMPTY         : 1;  /* [8]            ro         */
        uint32 RXFIO_IS_FULL               : 1;  /* [9]            ro         */
        uint32 SDA_ERR_RECOVER_STUCK_LOW   : 1;  /* [10]           ro         */
        uint32 SLAVE_IS_DISABLED_UNDER_ACT : 1;  /* [11]           ro         */
        uint32 SLAVE_RX_DATA_DISCARD       : 1;  /* [12]           ro         */
        uint32 I2C_IS_ENABLE               : 1;  /* [13]           ro         */
        uint32 RSVD_31_14                  : 18; /* [31:14]        ro         */
    } I2C_STATUS1;

    /* 0x64*/
    struct
    {
        uint32 ERR_GEN_CALL_NO_ACK     : 1;  /* [0]            ro         */
        uint32 ERR_GEN_CALL_READ       : 1;  /* [1]            ro         */
        uint32 ERR_START_BYTE_ACK_DET  : 1;  /* [2]            ro         */
        uint32 ERR_SBYTE_NORSTRT       : 1;  /* [3]            ro         */
        uint32 ERR_H_NO_RSTRT          : 1;  /* [4]            ro         */
        uint32 ERR_H_MCODE_ACK_DET     : 1;  /* [5]            ro         */
        uint32 ERR_7BIT_ADDR_NO_ACK    : 1;  /* [6]            ro         */
        uint32 ERR_10BIT_ADDR1_NO_ACK  : 1;  /* [7]            ro         */
        uint32 ERR_10BIT_ADDR2_NO_ACK  : 1;  /* [8]            ro         */
        uint32 ERR_10BIT_READ_NO_RSTRT : 1;  /* [9]            ro         */
        uint32 ERR_DATA_NO_ACK         : 1;  /* [10]           ro         */
        uint32 ERR_MASTER_ABRT         : 1;  /* [11]           ro         */
        uint32 ERR_MASTER_DIS          : 1;  /* [12]           ro         */
        uint32 ERR_SLAVE_ARBLOST       : 1;  /* [13]           ro         */
        uint32 ERR_MASTER_LOST         : 1;  /* [14]           ro         */
        uint32 ERR_SLAVE_READ_REQ      : 1;  /* [15]           ro         */
        uint32 ERR_SLAVE_FLUSH_TXFIFO  : 1;  /* [16]           ro         */
        uint32 ERR_SDA_LOW_TIMEOUT     : 1;  /* [17]           ro         */
        uint32 ERR_TXFIFO_FLUSH_CNT    : 3;  /* [20:18]        ro         */
        uint32 RSVD_31_21              : 11; /* [31:21]        ro         */
    } I2C_ERROR_STATUS;

    /* 0x68*/
    struct
    {
        uint32 SCL_LOW_TIMEOUT : 32; /* [31:0]         r/w        */
    } I2C_SCL_LOW_TIMEOUT;

    /* 0x6c*/
    struct
    {
        uint32 SDA_LOW_TIMEOUT : 32; /* [31:0]         r/w        */
    } I2C_SDA_LOW_TIMEOUT;

    /* 0x70*/
    struct
    {
        uint32 CLR_ERR   : 1;  /* [0]            ro         */
        uint32 RSVD_31_1 : 31; /* [31:1]         ro         */
    } I2C_RD_CLR_ERR_STATUS;

}; /*i2c*/

struct Reg_I2c_W
{
    /* 0x00*/
    uint32 zResverd0x00;
    /* 0x04*/
    uint32 I2C_PARAMETER;
    /* 0x08*/
    uint32 I2C_CONFIG0;
    /* 0x0c*/
    uint32 I2C_CONFIG1;
    /* 0x10*/
    uint32 I2C_SDA_SETUP_TIMING;
    /* 0x14*/
    uint32 I2C_SDA_HOLD_TIMING;
    /* 0x18*/
    uint32 I2C_DMA_CTRL;
    /* 0x1c*/
    uint32 I2C_INT_ENABLE;
    /* 0x20*/
    uint32 I2C_COMMAND_DATA;
    /* 0x24*/
    uint32 I2C_DEST_ADDR;
    /* 0x28*/
    uint32 I2C_SLAVE_ADDR;
    /* 0x2c*/
    uint32 I2C_STD_SCL_HCNT;
    /* 0x30*/
    uint32 I2C_STD_SCL_LCNT;
    /* 0x34*/
    uint32 I2C_FST_SCL_HCNT;
    /* 0x38*/
    uint32 I2C_FST_SCL_LCNT;
    /* 0x3c*/
    uint32 I2C_HS_SCL_HCNT;
    /* 0x40*/
    uint32 I2C_HS_SCL_LCNT;
    /* 0x44*/
    uint32 I2C_RXFIFO_WATER_MARK;
    /* 0x48*/
    uint32 I2C_TXFIFO_WATER_MARK;
    /* 0x4c*/
    uint32 I2C_TX_FIFO_CNT;
    /* 0x50*/
    uint32 I2C_RX_FIFO_CNT;
    /* 0x54*/
    uint32 I2C_FSTD_SPKCNT;
    /* 0x58*/
    uint32 I2C_HS_SPKCNT;
    /* 0x5c*/
    uint32 I2C_STATUS0;
    /* 0x60*/
    uint32 I2C_STATUS1;
    /* 0x64*/
    uint32 I2C_ERROR_STATUS;
    /* 0x68*/
    uint32 I2C_SCL_LOW_TIMEOUT;
    /* 0x6c*/
    uint32 I2C_SDA_LOW_TIMEOUT;
    /* 0x70*/
    uint32 I2C_RD_CLR_ERR_STATUS;
}; /*i2c*/

typedef volatile struct Reg_I2c_Bf Reg_I2c_BfType;
typedef volatile struct Reg_I2c_W  Reg_I2c_WType;

struct Reg_I2s_Bf
{
    /* 0x00*/
    struct
    {
        uint32 I2S_MODULE_EN    : 1;  /* [0]            r/w        */
        uint32 I2S_TE           : 1;  /* [1]            r/w        */
        uint32 I2S_RE           : 1;  /* [2]            r/w        */
        uint32 I2S_TXFIFO_RESET : 1;  /* [3]            wo         */
        uint32 I2S_RXFIFO_RESET : 1;  /* [4]            wo         */
        uint32 RSVD_31_5        : 27; /* [31:5]         ro         */
    } I2S_CONTROL;

    /* 0x04*/
    struct
    {
        uint32 I2S_MASTER_EN     : 1;  /* [0]            r/w        */
        uint32 I2S_NUM_BCLK      : 2;  /* [2:1]          r/w        */
        uint32 RSVD_4_3          : 2;  /* [4:3]          ro         */
        uint32 I2S_NUM_BCLK_GATE : 3;  /* [7:5]          r/w        */
        uint32 MCK_DIV           : 8;  /* [15:8]         r/w        */
        uint32 RSVD_31_16        : 16; /* [31:16]         ro         */
    } I2S_MASTER_CONFIG;

    /* 0x08*/
    struct
    {
        struct
        {
            uint32 LEFT_DATA : 32; /* [31:0]         r/w        */
        } I2S_CHn_LEFT_DATA;

        /* 0x0c*/
        struct
        {
            uint32 RIGHT_DATA : 32; /* [31:0]         r/w        */
        } I2S_CHn_RIGHT_DATA;

        /* 0x10*/
        struct
        {
            uint32 TX_EN               : 1;  /* [0]            r/w        */
            uint32 RX_EN               : 1;  /* [1]            r/w        */
            uint32 TX_AUDIO_RESOLUTION : 3;  /* [4:2]          r/w        */
            uint32 RX_AUDIO_RESOLUTION : 3;  /* [7:5]          r/w        */
            uint32 RSVD_31_8           : 24; /* [31:8]         ro         */
        } I2S_CHn_CFG;

        /* 0x14*/
        struct
        {
            uint32 RXFIFO_AVAILABLE_IE : 1;  /* [0]            r/w        */
            uint32 RXFIFO_OVERUN_IE    : 1;  /* [1]            r/w        */
            uint32 TXFIFO_EMPTY_IE     : 1;  /* [2]            r/w        */
            uint32 TXFIFO_OVERUN_IE    : 1;  /* [3]            r/w        */
            uint32 RXFIFO_DAF          : 1;  /* [4]            ro         */
            uint32 RXFIFO_ORF          : 1;  /* [5]            r/w        */
            uint32 TXFIFO_EMPTYF       : 1;  /* [6]            ro         */
            uint32 TXFIFO_ORF          : 1;  /* [7]            r/w        */
            uint32 RSVD_31_8           : 24; /* [31:8]         ro         */
        } I2S_CHn_INT_CFG;

        /* 0x18*/
        struct
        {
            uint32 RXFIFO_FULL_TRIG_LEV  : 4;  /* [3:0]          r/w        */
            uint32 TXFIFO_EMPTY_TRIG_LEV : 4;  /* [7:4]          r/w        */
            uint32 CH_TXFIFO_RESET       : 1;  /* [8]            wo         */
            uint32 CH_RXFIFO_RESET       : 1;  /* [9]            wo         */
            uint32 RSVD_31_10            : 22; /* [31:10]        ro         */
        } I2S_CHn_TRIGGER_LEVEL_CFG;
    } I2S_CHANNEL_REG[4];

    /* 0x58*/
    struct
    {
        uint32 CYCLE_TX_DATA : 32; /* [31:0]         wo         */
    } I2S_CYCLE_TX_DATA;

    /* 0x5c*/
    struct
    {
        uint32 CYCLE_TX_RESET : 1;  /* [0]            wo         */
        uint32 RSVD_31_1      : 31; /* [31:1]         ro         */
    } I2S_CYCLE_TX_RESET;

    /* 0x60*/
    struct
    {
        uint32 CYCLE_RX_DATA : 32; /* [31:0]         ro         */
    } I2S_CYCLE_RX_DATA;

    /* 0x64*/
    struct
    {
        uint32 CYCLE_RX_RESET : 1;  /* [0]            wo         */
        uint32 RSVD_31_1      : 31; /* [31:1]         ro         */
    } I2S_CYCLE_RX_RESET;

}; /*i2s*/

struct Reg_I2s_W
{
    /* 0x00*/
    uint32 I2S_CONTROL;
    /* 0x04*/
    uint32 I2S_MASTER_CONFIG;
    struct
    {
        /* 0x08*/
        uint32 I2S_CHn_LEFT_DATA;
        /* 0x0c*/
        uint32 I2S_CHn_RIGHT_DATA;
        /* 0x10*/
        uint32 I2S_CHn_CFG;
        /* 0x14*/
        uint32 I2S_CHn_INT_CFG;
        /* 0x18*/
        uint32 I2S_CHn_TRIGGER_LEVEL_CFG;
    } I2S_CHANNEL_REG[4];
    /* 0x58*/
    uint32 I2S_CYCLE_TX_DATA;
    /* 0x5c*/
    uint32 I2S_CYCLE_TX_RESET;
    /* 0x60*/
    uint32 I2S_CYCLE_RX_DATA;
    /* 0x64*/
    uint32 I2S_CYCLE_RX_RESET;

}; /*i2s*/

typedef volatile struct Reg_I2s_Bf Reg_I2s_BfType;
typedef volatile struct Reg_I2s_W  Reg_I2s_WType;

struct Reg_Mcpwm_Bf
{
    /* 0x00*/
    struct
    {
        uint32 CKSRC     : 2;  /* [1:0]          r/w        */
        uint32 PSDIV     : 3;  /* [4:2]          r/w        */
        uint32 DBGM      : 2;  /* [6:5]          r/w        */
        uint32 RSVD_31_7 : 25; /* [31:7]                    */
    } MCPWM_TIMEBASE;

    /* 0x04*/
    struct
    {
        uint32 CNT        : 16; /* [15:0]         r/w        */
        uint32 RSVD_31_16 : 16; /* [31:16]                   */
    } MCPWM_CNTn[4];

    /* 0x14*/
    struct
    {
        uint32 MOD        : 16; /* [15:0]         r/w        */
        uint32 RSVD_31_16 : 16; /* [31:16]                   */
    } MCPWM_MODn[4];

    /* 0x24*/
    struct
    {
        uint32 DTVAL      : 12; /* [11:0]         r/w        */
        uint32 RSVD_31_12 : 20; /* [31:12]                   */
    } MCPWM_DTVALn[4];

    /* 0x34*/
    struct
    {
        uint32 CHOE0      : 1; /* [0]            r/w        */
        uint32 CHOE1      : 1; /* [1]            r/w        */
        uint32 CHOE2      : 1; /* [2]            r/w        */
        uint32 CHOE3      : 1; /* [3]            r/w        */
        uint32 CHOE4      : 1; /* [4]            r/w        */
        uint32 CHOE5      : 1; /* [5]            r/w        */
        uint32 CHOE6      : 1; /* [6]            r/w        */
        uint32 CHOE7      : 1; /* [7]            r/w        */
        uint32 CNTM0      : 1; /* [8]            r/w        */
        uint32 CNTM1      : 1; /* [9]            r/w        */
        uint32 CNTM2      : 1; /* [10]           r/w        */
        uint32 CNTM3      : 1; /* [11]           r/w        */
        uint32 CNTEN0     : 1; /* [12]                      */
        uint32 CNTEN1     : 1; /* [13]                      */
        uint32 CNTEN2     : 1; /* [14]                      */
        uint32 CNTEN3     : 1; /* [15]                      */
        uint32 RLDIE0     : 1; /* [16]           r/w        */
        uint32 RLDIE1     : 1; /* [17]           r/w        */
        uint32 RLDIE2     : 1; /* [18]           r/w        */
        uint32 RLDIE3     : 1; /* [19]           r/w        */
        uint32 TOIE0      : 1; /* [20]           r/w        */
        uint32 TOIE1      : 1; /* [21]           r/w        */
        uint32 TOIE2      : 1; /* [22]           r/w        */
        uint32 TOIE3      : 1; /* [23]           r/w        */
        uint32 RSVD_29_24 : 6; /* [29:24]                   */
        uint32 WPEN       : 1; /* [30]           r/w        */
        uint32 GLBCNTEN   : 1; /* [31]           r/w        */
    } MCPWM_GLBCR;

    /* 0x38*/
    struct
    {
        uint32 CH0F       : 1;  /* [0]            r/o        */
        uint32 CH1F       : 1;  /* [1]            r/o        */
        uint32 CH2F       : 1;  /* [2]            r/o        */
        uint32 CH3F       : 1;  /* [3]            r/o        */
        uint32 CH4F       : 1;  /* [4]            r/o        */
        uint32 CH5F       : 1;  /* [5]            r/o        */
        uint32 CH6F       : 1;  /* [6]            r/o        */
        uint32 CH7F       : 1;  /* [7]            r/o        */
        uint32 RLDF0      : 1;  /* [8]            r/o        */
        uint32 RLDF1      : 1;  /* [9]            r/o        */
        uint32 RLDF2      : 1;  /* [10]           r/o        */
        uint32 RLDF3      : 1;  /* [11]           r/o        */
        uint32 TOF0       : 1;  /* [12]           r/o        */
        uint32 TOF1       : 1;  /* [13]           r/o        */
        uint32 TOF2       : 1;  /* [14]           r/o        */
        uint32 TOF3       : 1;  /* [15]           r/o        */
        uint32 WPDIS      : 1;  /* [16]           r/w        */
        uint32 RSVD_31_17 : 15; /* [31:17]                   */
    } MCPWM_GLBSR;

    /* 0x3C*/
    struct
    {
        uint32 CPP       : 1;  /* [0]            r/w        */
        uint32 RSVD_3_1  : 3;  /* [3:1]                     */
        uint32 CHIE      : 1;  /* [4]            r/w        */
        uint32 CHF       : 1;  /* [5]            r/o        */
        uint32 DMA       : 1;  /* [6]            r/w        */
        uint32 RSVD_31_7 : 25; /* [31:7]                    */
    } MCPWM_CFGn[8];

    /* 0x5C*/
    struct
    {
        uint32 CV         : 16; /* [15:0]         r/w        */
        uint32 RSVD_31_16 : 16; /* [31:16]                   */
    } MCPWM_CVn[8];

    /* 0x7C*/
    struct
    {
        uint32 POL0       : 1;  /* [0]            r/w        */
        uint32 POL1       : 1;  /* [1]            r/w        */
        uint32 POL2       : 1;  /* [2]            r/w        */
        uint32 POL3       : 1;  /* [3]            r/w        */
        uint32 POL4       : 1;  /* [4]            r/w        */
        uint32 POL5       : 1;  /* [5]            r/w        */
        uint32 POL6       : 1;  /* [6]            r/w        */
        uint32 POL7       : 1;  /* [7]            r/w        */
        uint32 OFFVAL0    : 1;  /* [8]            r/w        */
        uint32 OFFVAL1    : 1;  /* [9]            r/w        */
        uint32 OFFVAL2    : 1;  /* [10]           r/w        */
        uint32 OFFVAL3    : 1;  /* [11]           r/w        */
        uint32 OFFVAL4    : 1;  /* [12]           r/w        */
        uint32 OFFVAL5    : 1;  /* [13]           r/w        */
        uint32 OFFVAL6    : 1;  /* [14]           r/w        */
        uint32 OFFVAL7    : 1;  /* [15]           r/w        */
        uint32 RSVD_31_16 : 16; /* [31:16]                   */
    } MCPWM_OUTCR;

    /* 0x80*/
    struct
    {
        uint32 TRIGE0     : 1;  /* [0]            r/w        */
        uint32 TRIGE1     : 1;  /* [1]            r/w        */
        uint32 TRIGE2     : 1;  /* [2]            r/w        */
        uint32 TRIGE3     : 1;  /* [3]            r/w        */
        uint32 TRIGE4     : 1;  /* [4]            r/w        */
        uint32 TRIGE5     : 1;  /* [5]            r/w        */
        uint32 TRIGE6     : 1;  /* [6]            r/w        */
        uint32 TRIGE7     : 1;  /* [7]            r/w        */
        uint32 INITRIGE   : 1;  /* [8]            r/w        */
        uint32 TRIGF      : 1;  /* [9]            r/o        */
        uint32 RSVD_31_10 : 22; /* [31:10]                   */
    } MCPWM_OUTTRIG;

    /* 0x84*/
    struct
    {
        uint32 CH0OC      : 1;  /* [0]            r/w        */
        uint32 CH1OC      : 1;  /* [1]            r/w        */
        uint32 CH2OC      : 1;  /* [2]            r/w        */
        uint32 CH3OC      : 1;  /* [3]            r/w        */
        uint32 CH4OC      : 1;  /* [4]            r/w        */
        uint32 CH5OC      : 1;  /* [5]            r/w        */
        uint32 CH6OC      : 1;  /* [6]            r/w        */
        uint32 CH7OC      : 1;  /* [7]            r/w        */
        uint32 CH0OCV     : 1;  /* [8]            r/w        */
        uint32 CH1OCV     : 1;  /* [9]            r/w        */
        uint32 CH2OCV     : 1;  /* [10]           r/w        */
        uint32 CH3OCV     : 1;  /* [11]           r/w        */
        uint32 CH4OCV     : 1;  /* [12]           r/w        */
        uint32 CH5OCV     : 1;  /* [13]           r/w        */
        uint32 CH6OCV     : 1;  /* [14]           r/w        */
        uint32 CH7OCV     : 1;  /* [15]           r/w        */
        uint32 RSVD_31_16 : 16; /* [31:16]                   */
    } MCPWM_OUTSWCR;

    /* 0x88*/
    struct
    {
        uint32 FCTLEN0 : 1; /* [0]            r/w        */
        uint32 DTEN0   : 1; /* [1]            r/w        */
        uint32 SYNCEN0 : 1; /* [2]            r/w        */
        uint32 ASYMEN0 : 1; /* [3]                       */
        uint32 CVSEL0  : 1; /* [4]                       */
        uint32 PEC0    : 1; /* [5]                       */
        uint32 COMB0   : 1; /* [6]            r/w        */
        uint32 RSVD_7  : 1; /* [7]                       */
        uint32 FCTLEN1 : 1; /* [8]            r/w        */
        uint32 DTEN1   : 1; /* [9]            r/w        */
        uint32 SYNCEN1 : 1; /* [10]           r/w        */
        uint32 ASYMEN1 : 1; /* [11]                      */
        uint32 CVSEL1  : 1; /* [12]                      */
        uint32 PEC1    : 1; /* [13]                      */
        uint32 COMB1   : 1; /* [14]           r/w        */
        uint32 RSVD_15 : 1; /* [15]                      */
        uint32 FCTLEN2 : 1; /* [16]           r/w        */
        uint32 DTEN2   : 1; /* [17]           r/w        */
        uint32 SYNCEN2 : 1; /* [18]           r/w        */
        uint32 ASYMEN2 : 1; /* [19]                      */
        uint32 CVSEL2  : 1; /* [20]                      */
        uint32 PEC2    : 1; /* [21]                      */
        uint32 COMB2   : 1; /* [22]           r/w        */
        uint32 RSVD_23 : 1; /* [23]                      */
        uint32 FCTLEN3 : 1; /* [24]           r/w        */
        uint32 DTEN3   : 1; /* [25]           r/w        */
        uint32 SYNCEN3 : 1; /* [26]           r/w        */
        uint32 ASYMEN3 : 1; /* [27]                      */
        uint32 CVSEL3  : 1; /* [28]                      */
        uint32 PEC3    : 1; /* [29]                      */
        uint32 COMB3   : 1; /* [30]           r/w        */
        uint32 RSVD_31 : 1; /* [31]                      */
    } MCPWM_PCR;

    /* 0x8C*/
    struct
    {
        uint32 FIFEN0     : 1;  /* [0]            r/w        */
        uint32 FIFEN1     : 1;  /* [1]            r/w        */
        uint32 FIFEN2     : 1;  /* [2]            r/w        */
        uint32 FIFEN3     : 1;  /* [3]            r/w        */
        uint32 FLTEN0     : 1;  /* [4]            r/w        */
        uint32 FLTEN1     : 1;  /* [5]            r/w        */
        uint32 FLTEN2     : 1;  /* [6]            r/w        */
        uint32 FLTEN3     : 1;  /* [7]            r/w        */
        uint32 FLTPOL0    : 1;  /* [8]            r/w        */
        uint32 FLTPOL1    : 1;  /* [9]            r/w        */
        uint32 FLTPOL2    : 1;  /* [10]           r/w        */
        uint32 FLTPOL3    : 1;  /* [11]           r/w        */
        uint32 FLTIE      : 1;  /* [12]           r/w        */
        uint32 FLTCM      : 1;  /* [13]           r/w        */
        uint32 RSVD_15_14 : 2;  /* [15:14]                   */
        uint32 FIFVAL     : 4;  /* [19:16]        r/w        */
        uint32 FSTATE     : 1;  /* [20]           r/w        */
        uint32 RSVD_31_21 : 11; /* [31:21]                   */
    } MCPWM_FLTCR;

    /* 0x90*/
    struct
    {
        uint32 FAULTF0   : 1;  /* [0]            r/w        */
        uint32 FAULTF1   : 1;  /* [1]            r/w        */
        uint32 FAULTF2   : 1;  /* [2]            r/w        */
        uint32 FAULTF3   : 1;  /* [3]            r/w        */
        uint32 FAULTFA   : 1;  /* [4]            r/w        */
        uint32 FAULTFB   : 1;  /* [5]            r/w        */
        uint32 FAULTINA  : 1;  /* [6]            r/o        */
        uint32 FAULTINB  : 1;  /* [7]            r/o        */
        uint32 RSVD_31_8 : 24; /* [31:8]                    */
    } MCPWM_FLTSR;

    /* 0x94*/
    struct
    {
        uint32 FLTASS0   : 1;  /* [0]            r/w        */
        uint32 FLTASS1   : 1;  /* [1]            r/w        */
        uint32 FLTASS2   : 1;  /* [2]            r/w        */
        uint32 FLTASS3   : 1;  /* [3]            r/w        */
        uint32 FLTASS4   : 1;  /* [4]            r/w        */
        uint32 FLTASS5   : 1;  /* [5]            r/w        */
        uint32 FLTASS6   : 1;  /* [6]            r/w        */
        uint32 FLTASS7   : 1;  /* [7]            r/w        */
        uint32 RSVD_31_8 : 24; /* [31:8]                    */
    } MCPWM_FLTASS;

    /* 0x98*/
    struct
    {
        uint32 FLTBSS0   : 1;  /* [0]            r/w        */
        uint32 FLTBSS1   : 1;  /* [1]            r/w        */
        uint32 FLTBSS2   : 1;  /* [2]            r/w        */
        uint32 FLTBSS3   : 1;  /* [3]            r/w        */
        uint32 FLTBSS4   : 1;  /* [4]            r/w        */
        uint32 FLTBSS5   : 1;  /* [5]            r/w        */
        uint32 FLTBSS6   : 1;  /* [6]            r/w        */
        uint32 FLTBSS7   : 1;  /* [7]            r/w        */
        uint32 RSVD_31_8 : 24; /* [31:8]                    */
    } MCPWM_FLTBSS;

    /* 0x9C*/
    struct
    {
        uint32 SWTRIG    : 1;  /* [0]            r/w        */
        uint32 SYNCOSWC  : 1;  /* [1]            r/w        */
        uint32 SWWRBUF   : 1;  /* [2]            r/w        */
        uint32 SWRSTCNT  : 1;  /* [3]            r/w        */
        uint32 RSVD_31_4 : 28; /* [31:4]                    */
    } MCPWM_SYNC;

    /* 0xA0*/
    struct
    {
        uint32 CPWMFCR0   : 1;  /* [0]            r/w        */
        uint32 CPWMFCR1   : 1;  /* [1]            r/w        */
        uint32 CPWMFCR2   : 1;  /* [2]            r/w        */
        uint32 CPWMFCR3   : 1;  /* [3]            r/w        */
        uint32 CPWMHCR0   : 1;  /* [4]            r/w        */
        uint32 CPWMHCR1   : 1;  /* [5]            r/w        */
        uint32 CPWMHCR2   : 1;  /* [6]            r/w        */
        uint32 CPWMHCR3   : 1;  /* [7]            r/w        */
        uint32 LOADEN0    : 1;  /* [8]            r/w        */
        uint32 LOADEN1    : 1;  /* [9]            r/w        */
        uint32 LOADEN2    : 1;  /* [10]           r/w        */
        uint32 LOADEN3    : 1;  /* [11]           r/w        */
        uint32 RSVD_31_12 : 20; /* [31:12]                   */
    } MCPWM_RELOAD;

    /* 0xA4*/
    struct
    {
        uint32 LDFREQ0    : 5; /* [4:0]          r/w        */
        uint32 RSVD_7_5   : 3; /* [7:5]                     */
        uint32 LDFREQ1    : 5; /* [12:8]         r/w        */
        uint32 RSVD_15_13 : 3; /* [15:13]                   */
        uint32 LDFREQ2    : 5; /* [20:16]        r/w        */
        uint32 RSVD_23_21 : 3; /* [23:21]                   */
        uint32 LDFREQ3    : 5; /* [28:24]        r/w        */
        uint32 RSVD_31_29 : 3; /* [31:29]                   */
    } MCPWM_LDFREQ;

    uint8 zResverd0x0A8[88]; /*pad 0x0A8 - 0FF*/

    /* 0x100*/
    struct
    {
        uint32 MOD_DITHER : 5;  /* [4:0]          r/w        */
        uint32 RSVD_31_5  : 27; /* [31:5]                    */
    } MCPWM_MODn_DITHER[4];

    /* 0x110*/
    struct
    {
        uint32 CV_DITHER : 5;  /* [4:0]          r/w        */
        uint32 RSVD_31_5 : 27; /* [31:5]                    */
    } MCPWM_CVn_DITHER[8];

}; /*mcpwm*/

struct Reg_Mcpwm_W
{
    /* 0x00*/
    uint32 MCPWM_TIMEBASE;
    /* 0x04*/
    uint32 MCPWM_CNTn[4];
    /* 0x14*/
    uint32 MCPWM_MODn[4];
    /* 0x24*/
    uint32 MCPWM_DTVALn[4];
    /* 0x34*/
    uint32 MCPWM_GLBCR;
    /* 0x38*/
    uint32 MCPWM_GLBSR;
    /* 0x3C*/
    uint32 MCPWM_CFGn[8];
    /* 0x5C*/
    uint32 MCPWM_CVn[8];
    /* 0x7C*/
    uint32 MCPWM_OUTCR;
    /* 0x80*/
    uint32 MCPWM_OUTTRIG;
    /* 0x84*/
    uint32 MCPWM_OUTSWCR;
    /* 0x88*/
    uint32 MCPWM_PCR;
    /* 0x8C*/
    uint32 MCPWM_FLTCR;
    /* 0x90*/
    uint32 MCPWM_FLTSR;
    /* 0x94*/
    uint32 MCPWM_FLTASS;
    /* 0x98*/
    uint32 MCPWM_FLTBSS;
    /* 0x9C*/
    uint32 MCPWM_SYNC;
    /* 0xA0*/
    uint32 MCPWM_RELOAD;
    /* 0xA4*/
    uint32 MCPWM_LDFREQ;
    uint8  zResverd0x0A8[88]; /*pad 0x0A8 - 0FF*/

    /* 0x100*/
    uint32 MCPWM_MODn_DITHER[4];
    /* 0x110*/
    uint32 MCPWM_CVn_DITHER[8];
}; /*mcpwm*/

typedef volatile struct Reg_Mcpwm_Bf Reg_Mcpwm_BfType;
typedef volatile struct Reg_Mcpwm_W  Reg_Mcpwm_WType;

struct Reg_Parcc_Bf
{
    /* 0x0*/
    struct
    {
        uint32 PCKMD      : 2;  /* [1:0]          r/w        */
        uint32 RSVD_15_2  : 14; /* [15:2]         r          */
        uint32 PWLK       : 1;  /* [16]           r/w        */
        uint32 RSVD_19_17 : 3;  /* [19:17]        r          */
        uint32 PSUPVACEN  : 1;  /* [20]           r/w        */
        uint32 PRSTB      : 1;  /* [21]           r/w        */
        uint32 RSVD_23_22 : 2;  /* [23:22]        r          */
        uint32 PPR        : 1;  /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1;  /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1;  /* [26]           r/w        */
        uint32 PSUPVACPR  : 1;  /* [27]           r/w        */
        uint32 RSVD_30_28 : 3;  /* [30:28]        r          */
        uint32 LOCK       : 1;  /* [31]           r/w        */
    } PARCC_WDOG;

    /* 0x4*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_EWDT;

    /* 0x8*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_STIM;

    /* 0xC*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_TIM0;

    /* 0x10*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_TIM1;

    /* 0x14*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_TIM2;

    /* 0x18*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_TIM3;

    /* 0x1C*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_MCPWM0;

    /* 0x20*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_MCPWM1;

    /* 0x24*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_TDG0;

    /* 0x28*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_TDG1;

    /* 0x2C*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_CAN0;

    /* 0x30*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_CAN1;

    /* 0x34*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_CAN2;

    /* 0x38*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_CAN3;

    /* 0x3C*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_CAN4;

    /* 0x40*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_CAN5;

    /* 0x44*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_CAN6;

    /* 0x48*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_CAN7;

    /* 0x4C*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_UART0;

    /* 0x50*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_UART1;

    /* 0x54*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_UART2;

    /* 0x58*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_UART3;

    /* 0x5C*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_UART4;

    /* 0x60*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_UART5;

    /* 0x64*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_SPI0;

    /* 0x68*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_SPI1;

    /* 0x6C*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_SPI2;

    /* 0x70*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_SPI3;

    /* 0x74*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_I2C0;

    /* 0x78*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_I2C1;

    /* 0x7C*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_I2S0;

    /* 0x80*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_I2S1;

    /* 0x84*/
    uint32 zResverd0x84;
    /* 0x88*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_ADC0;

    /* 0x8C*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_ADC1;

    /* 0x90*/
    struct
    {
        uint32 PCKMD      : 2;  /* [1:0]          r/w        */
        uint32 RSVD_15_2  : 14; /* [15:2]         r          */
        uint32 PWLK       : 1;  /* [16]           r/w        */
        uint32 RSVD_19_17 : 3;  /* [19:17]        r          */
        uint32 PSUPVACEN  : 1;  /* [20]           r/w        */
        uint32 PRSTB      : 1;  /* [21]           r/w        */
        uint32 RSVD_23_22 : 2;  /* [23:22]        r          */
        uint32 PPR        : 1;  /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1;  /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1;  /* [26]           r/w        */
        uint32 PSUPVACPR  : 1;  /* [27]           r/w        */
        uint32 RSVD_30_28 : 3;  /* [30:28]        r          */
        uint32 LOCK       : 1;  /* [31]           r/w        */
    } PARCC_CMP0;

    /* 0x94*/
    struct
    {
        uint32 PCKMD      : 2;  /* [1:0]          r/w        */
        uint32 RSVD_15_2  : 14; /* [15:2]         r          */
        uint32 PWLK       : 1;  /* [16]           r/w        */
        uint32 RSVD_19_17 : 3;  /* [19:17]        r          */
        uint32 PSUPVACEN  : 1;  /* [20]           r/w        */
        uint32 PRSTB      : 1;  /* [21]           r/w        */
        uint32 RSVD_23_22 : 2;  /* [23:22]        r          */
        uint32 PPR        : 1;  /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1;  /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1;  /* [26]           r/w        */
        uint32 PSUPVACPR  : 1;  /* [27]           r/w        */
        uint32 RSVD_30_28 : 3;  /* [30:28]        r          */
        uint32 LOCK       : 1;  /* [31]           r/w        */
    } PARCC_CRC;

    /* 0x98*/
    struct
    {
        uint32 PCKMD      : 2;  /* [1:0]          r/w        */
        uint32 RSVD_15_2  : 14; /* [15:2]         r          */
        uint32 PWLK       : 1;  /* [16]           r/w        */
        uint32 RSVD_19_17 : 3;  /* [19:17]        r          */
        uint32 PSUPVACEN  : 1;  /* [20]           r/w        */
        uint32 PRSTB      : 1;  /* [21]           r/w        */
        uint32 RSVD_23_22 : 2;  /* [23:22]        r          */
        uint32 PPR        : 1;  /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1;  /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1;  /* [26]           r/w        */
        uint32 PSUPVACPR  : 1;  /* [27]           r/w        */
        uint32 RSVD_30_28 : 3;  /* [30:28]        r          */
        uint32 LOCK       : 1;  /* [31]           r/w        */
    } PARCC_AES;

    /* 0x9C*/
    struct
    {
        uint32 PCKMD      : 2;  /* [1:0]          r/w        */
        uint32 RSVD_15_2  : 14; /* [15:2]         r          */
        uint32 PWLK       : 1;  /* [16]           r/w        */
        uint32 RSVD_19_17 : 3;  /* [19:17]        r          */
        uint32 PSUPVACEN  : 1;  /* [20]           r/w        */
        uint32 PRSTB      : 1;  /* [21]           r/w        */
        uint32 RSVD_23_22 : 2;  /* [23:22]        r          */
        uint32 PPR        : 1;  /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1;  /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1;  /* [26]           r/w        */
        uint32 PSUPVACPR  : 1;  /* [27]           r/w        */
        uint32 RSVD_30_28 : 3;  /* [30:28]        r          */
        uint32 LOCK       : 1;  /* [31]           r/w        */
    } PARCC_TRNG;

    /* 0xA0*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 RSVD_16    : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 RSVD_20    : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_FLASH;

    /* 0xA4*/
    uint32 zResverd0xA4;
    /* 0xA8*/
    struct
    {
        uint32 PCKMD      : 2;  /* [1:0]          r/w        */
        uint32 RSVD_15_2  : 14; /* [15:2]         r          */
        uint32 PWLK       : 1;  /* [16]           r/w        */
        uint32 RSVD_19_17 : 3;  /* [19:17]        r          */
        uint32 PSUPVACEN  : 1;  /* [20]           r/w        */
        uint32 PRSTB      : 1;  /* [21]           r/w        */
        uint32 RSVD_23_22 : 2;  /* [23:22]        r          */
        uint32 PPR        : 1;  /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1;  /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1;  /* [26]           r/w        */
        uint32 PSUPVACPR  : 1;  /* [27]           r/w        */
        uint32 RSVD_30_28 : 3;  /* [30:28]        r          */
        uint32 LOCK       : 1;  /* [31]           r/w        */
    } PARCC_DMA;

    /* 0xAC*/
    struct
    {
        uint32 PCKMD      : 2;  /* [1:0]          r/w        */
        uint32 RSVD_15_2  : 14; /* [15:2]         r          */
        uint32 PWLK       : 1;  /* [16]           r/w        */
        uint32 RSVD_19_17 : 3;  /* [19:17]        r          */
        uint32 PSUPVACEN  : 1;  /* [20]           r/w        */
        uint32 PRSTB      : 1;  /* [21]           r/w        */
        uint32 RSVD_23_22 : 2;  /* [23:22]        r          */
        uint32 PPR        : 1;  /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1;  /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1;  /* [26]           r/w        */
        uint32 PSUPVACPR  : 1;  /* [27]           r/w        */
        uint32 RSVD_30_28 : 3;  /* [30:28]        r          */
        uint32 LOCK       : 1;  /* [31]           r/w        */
    } PARCC_DMAMUX;

    /* 0xB0*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_PORTA;

    /* 0xB4*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_PORTB;

    /* 0xB8*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_PORTC;

    /* 0xBC*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_PORTD;

    /* 0xC0*/
    struct
    {
        uint32 PCKMD      : 2; /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 CLKMUX     : 3; /* [6:4]          r/w        */
        uint32 RSVD_7     : 1; /* [7]            r          */
        uint32 CLKDIV     : 4; /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r          */
        uint32 PWLK       : 1; /* [16]           r/w        */
        uint32 RSVD_19_17 : 3; /* [19:17]        r          */
        uint32 PSUPVACEN  : 1; /* [20]           r/w        */
        uint32 PRSTB      : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]        r          */
        uint32 PPR        : 1; /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1; /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1; /* [26]           r/w        */
        uint32 PSUPVACPR  : 1; /* [27]           r/w        */
        uint32 RSVD_30_28 : 3; /* [30:28]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } PARCC_PORTE;

    /* 0xC4*/
    struct
    {
        uint32 PCKMD      : 2;  /* [1:0]          r/w        */
        uint32 RSVD_15_2  : 14; /* [15:2]         r          */
        uint32 PWLK       : 1;  /* [16]           r/w        */
        uint32 RSVD_19_17 : 3;  /* [19:17]        r          */
        uint32 PSUPVACEN  : 1;  /* [20]           r/w        */
        uint32 PRSTB      : 1;  /* [21]           r/w        */
        uint32 RSVD_23_22 : 2;  /* [23:22]        r          */
        uint32 PPR        : 1;  /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1;  /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1;  /* [26]           r/w        */
        uint32 PSUPVACPR  : 1;  /* [27]           r/w        */
        uint32 RSVD_30_28 : 3;  /* [30:28]        r          */
        uint32 LOCK       : 1;  /* [31]           r/w        */
    } PARCC_TMU;

    /* 0xC8*/
    struct
    {
        uint32 PCKMD      : 2;  /* [1:0]          r/w        */
        uint32 RSVD_15_2  : 14; /* [15:2]         r          */
        uint32 PWLK       : 1;  /* [16]           r/w        */
        uint32 RSVD_19_17 : 3;  /* [19:17]        r          */
        uint32 PSUPVACEN  : 1;  /* [20]           r/w        */
        uint32 PRSTB      : 1;  /* [21]           r/w        */
        uint32 RSVD_23_22 : 2;  /* [23:22]        r          */
        uint32 PPR        : 1;  /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1;  /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1;  /* [26]           r/w        */
        uint32 PSUPVACPR  : 1;  /* [27]           r/w        */
        uint32 RSVD_30_28 : 3;  /* [30:28]        r          */
        uint32 LOCK       : 1;  /* [31]           r/w        */
    } PARCC_REGFILE;

    /* 0xCC*/
    struct
    {
        uint32 PCKMD      : 2;  /* [1:0]          r/w        */
        uint32 RSVD_15_2  : 14; /* [15:2]         r          */
        uint32 PWLK       : 1;  /* [16]           r/w        */
        uint32 RSVD_19_17 : 3;  /* [19:17]        r          */
        uint32 PSUPVACEN  : 1;  /* [20]           r/w        */
        uint32 PRSTB      : 1;  /* [21]           r/w        */
        uint32 RSVD_23_22 : 2;  /* [23:22]        r          */
        uint32 PPR        : 1;  /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1;  /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1;  /* [26]           r/w        */
        uint32 PSUPVACPR  : 1;  /* [27]           r/w        */
        uint32 RSVD_30_28 : 3;  /* [30:28]        r          */
        uint32 LOCK       : 1;  /* [31]           r/w        */
    } PARCC_SMPU;

    /* 0xD0*/
    struct
    {
        uint32 PCKMD      : 2;  /* [1:0]          r/w        */
        uint32 RSVD_15_2  : 14; /* [15:2]         r          */
        uint32 PWLK       : 1;  /* [16]           r/w        */
        uint32 RSVD_19_17 : 3;  /* [19:17]        r          */
        uint32 PSUPVACEN  : 1;  /* [20]           r/w        */
        uint32 PRSTB      : 1;  /* [21]           r/w        */
        uint32 RSVD_23_22 : 2;  /* [23:22]        r          */
        uint32 PPR        : 1;  /* [24]           r/w        */
        uint32 PCLKMUXPR  : 1;  /* [25]           r/w        */
        uint32 PCLKDIVPR  : 1;  /* [26]           r/w        */
        uint32 PSUPVACPR  : 1;  /* [27]           r/w        */
        uint32 RSVD_30_28 : 3;  /* [30:28]        r          */
        uint32 LOCK       : 1;  /* [31]           r/w        */
    } PARCC_GPIO;

}; /*parcc*/

struct Reg_Parcc_W
{
    /* 0x0*/
    uint32 PARCC_WDOG;
    /* 0x4*/
    uint32 PARCC_EWDT;
    /* 0x8*/
    uint32 PARCC_STIM;
    /* 0xC*/
    uint32 PARCC_TIM0;
    /* 0x10*/
    uint32 PARCC_TIM1;
    /* 0x14*/
    uint32 PARCC_TIM2;
    /* 0x18*/
    uint32 PARCC_TIM3;
    /* 0x1C*/
    uint32 PARCC_MCPWM0;
    /* 0x20*/
    uint32 PARCC_MCPWM1;
    /* 0x24*/
    uint32 PARCC_TDG0;
    /* 0x28*/
    uint32 PARCC_TDG1;
    /* 0x2C*/
    uint32 PARCC_CAN0;
    /* 0x30*/
    uint32 PARCC_CAN1;
    /* 0x34*/
    uint32 PARCC_CAN2;
    /* 0x38*/
    uint32 PARCC_CAN3;
    /* 0x3C*/
    uint32 PARCC_CAN4;
    /* 0x40*/
    uint32 PARCC_CAN5;
    /* 0x44*/
    uint32 PARCC_CAN6;
    /* 0x48*/
    uint32 PARCC_CAN7;
    /* 0x4C*/
    uint32 PARCC_UART0;
    /* 0x50*/
    uint32 PARCC_UART1;
    /* 0x54*/
    uint32 PARCC_UART2;
    /* 0x58*/
    uint32 PARCC_UART3;
    /* 0x5C*/
    uint32 PARCC_UART4;
    /* 0x60*/
    uint32 PARCC_UART5;
    /* 0x64*/
    uint32 PARCC_SPI0;
    /* 0x68*/
    uint32 PARCC_SPI1;
    /* 0x6C*/
    uint32 PARCC_SPI2;
    /* 0x70*/
    uint32 PARCC_SPI3;
    /* 0x74*/
    uint32 PARCC_I2C0;
    /* 0x78*/
    uint32 PARCC_I2C1;
    /* 0x7C*/
    uint32 PARCC_I2S0;
    /* 0x80*/
    uint32 PARCC_I2S1;
    /* 0x84*/
    uint32 zResverd0x84;
    /* 0x88*/
    uint32 PARCC_ADC0;
    /* 0x8C*/
    uint32 PARCC_ADC1;
    /* 0x90*/
    uint32 PARCC_CMP0;
    /* 0x94*/
    uint32 PARCC_CRC;
    /* 0x98*/
    uint32 PARCC_AES;
    /* 0x9C*/
    uint32 PARCC_TRNG;
    /* 0xA0*/
    uint32 PARCC_FLASH;
    /* 0xA4*/
    uint32 zResverd0xA4;
    /* 0xA8*/
    uint32 PARCC_DMA;
    /* 0xAC*/
    uint32 PARCC_DMAMUX;
    /* 0xB0*/
    uint32 PARCC_PORTA;
    /* 0xB4*/
    uint32 PARCC_PORTB;
    /* 0xB8*/
    uint32 PARCC_PORTC;
    /* 0xBC*/
    uint32 PARCC_PORTD;
    /* 0xC0*/
    uint32 PARCC_PORTE;
    /* 0xC4*/
    uint32 PARCC_TMU;
    /* 0xC8*/
    uint32 PARCC_REGFILE;
    /* 0xCC*/
    uint32 PARCC_SMPU;
    /* 0xD0*/
    uint32 PARCC_GPIO;
}; /*parcc*/

typedef volatile struct Reg_Parcc_Bf Reg_Parcc_BfType;
typedef volatile struct Reg_Parcc_W  Reg_Parcc_WType;

struct Reg_Pmu_Bf
{
    /* 0x00*/
    struct
    {
        uint32 RSVD_30_0 : 31; /* [30:0]         ro         */
        uint32 LOCK      : 1;  /* [31]           w/r        */
    } PMU_LOCK;

    /* 0x04*/
    struct
    {
        uint32 LPO_CLK_DIS   : 1;  /* [0]            r/w        */
        uint32 RSVD_1        : 1;  /* [1]            r/w        */
        uint32 LPO_CLK_READY : 1;  /* [2]            r          */
        uint32 RSVD_31_3     : 29; /* [31:3]         ro         */
    } PMU_LPO_32K_CFG;

    uint8 zResverd0x08[4]; /*pad 0x08 - 0B*/

    /* 0x0c*/
    struct
    {
        uint32 ISO_CLR   : 1;  /* [0]            w1c        */
        uint32 RSVD_31_1 : 31; /* [31:1]         ro         */
    } PMU_ISO_CLR;

    /* 0x10*/
    struct
    {
        uint32 VDD_LVD_LP_EN  : 1;  /* [0]            r/w        */
        uint32 VDD_LVD_ACT_EN : 1;  /* [1]            r/w        */
        uint32 VDD_LVD_IE     : 1;  /* [2]            r/w        */
        uint32 VDD_LVD_RE     : 1;  /* [3]            r/w        */
        uint32 VDD_LVW_EN     : 1;  /* [4]            r/w        */
        uint32 VDD_LVW_IE     : 1;  /* [5]            r/w        */
        uint32 LVWF_VDD       : 1;  /* [6]            w1c        */
        uint32 LVDF_VDD       : 1;  /* [7]            w1c        */
        uint32 REF_BUF_1V_EN  : 1;  /* [8]            r/w        */
        uint32 RSVD_31_9      : 23; /* [31:9]         ro         */

    } PMU_CSR;

    /* 0x14*/
    struct
    {
        uint32 LDO_CORE_EN    : 1;  /* [0]            r/w        */
        uint32 LDO_CLOCK_EN   : 1;  /* [1]            r/w        */
        uint32 LDO_FLASH_EN   : 1;  /* [2]            r/w        */
        uint32 RSVD_3         : 1;  /* [3]            ro         */
        uint32 LDO_CORE_LPEN  : 1;  /* [4]            r/w        */
        uint32 LDO_CLOCK_LPEN : 1;  /* [5]            r/w        */
        uint32 LDO_FLASH_LPEN : 1;  /* [6]            r/w        */
        uint32 RSVD_31_7      : 25; /* [31:7]         ro         */
    } PMU_LDO_EN_CFG;

    /* 0x18*/
    struct
    {
        uint32 LVD_CORE_FLAG  : 1;  /* [0]            w1c        */
        uint32 LVD_CLOCK_FLAG : 1;  /* [1]            w1c        */
        uint32 LVD_FLASH_FLAG : 1;  /* [2]            w1c        */
        uint32 RSVD_3         : 1;  /* [3]            ro         */
        uint32 LVD_AOA_FLAG   : 1;  /* [4]            w1c        */
        uint32 RSVD_31_5      : 27; /* [31:5]         ro         */
    } PMU_LDO_LVD_STATUS;

    /* 0x1c*/
    struct
    {
        uint32 LVD_CORE_RE    : 1;  /* [0]            r/w        */
        uint32 LVD_CLOCK_RE   : 1;  /* [1]            r/w        */
        uint32 LVD_FLASH_RE   : 1;  /* [2]            r/w        */
        uint32 RSVD_3         : 1;  /* [3]            ro         */
        uint32 LVD_AOA_RE     : 1;  /* [4]            r/w        */
        uint32 ACT_CORE_LVDE  : 1;  /* [5]            r/w        */
        uint32 ACT_CLOCK_LVDE : 1;  /* [6]            r/w        */
        uint32 RSVD_8_7       : 2;  /* [8:7]          ro         */
        uint32 ACT_AOA_LVDE   : 1;  /* [9]            r/w        */
        uint32 LP_CORE_LVDE   : 1;  /* [10]           r/w        */
        uint32 LP_CLOCK_LVDE  : 1;  /* [11]           r/w        */
        uint32 RSVD_13_12     : 2;  /* [13:12]        ro         */
        uint32 LP_AOA_LVDE    : 1;  /* [14]           r/w        */
        uint32 RSVD_31_15     : 17; /* [31:15]        ro         */
    } PMU_LDO_LVD_CFG;

}; /*pmu_reg*/

struct Reg_Pmu_W
{
    /* 0x00*/
    uint32 PMU_LOCK;
    /* 0x04*/
    uint32 PMU_LPO_32K_CFG;
    /* 0x08*/
    uint8 zResverd0x08[4]; /*pad 0x08 - 0B*/
    /* 0x0c*/
    uint32 PMU_ISO_CLR;
    /* 0x10*/
    uint32 PMU_CSR;
    /* 0x14*/
    uint32 PMU_LDO_EN_CFG;
    /* 0x18*/
    uint32 PMU_LDO_LVD_STATUS;
    /* 0x1c*/
    uint32 PMU_LDO_LVD_CFG;

}; /*pmu*/

typedef volatile struct Reg_Pmu_Bf Reg_Pmu_BfType;
typedef volatile struct Reg_Pmu_W  Reg_Pmu_WType;

struct Reg_Port_Bf
{
    /* 0x0*/
    uint8 zResverd0x0[8];

    /* 0x8*/
    struct
    {
        uint32 GPWD : 32; /* [31:0]         r/w        */
    } PORTx_GLBDAT;

    /* 0xC*/
    struct
    {
        uint32 GPWE : 32; /* [31:0]         wo         */
    } PORTx_GLBCTL;

    /* 0x10*/
    struct
    {
        uint32 PS         : 1; /* [0]            r/w        */
        uint32 PE         : 1; /* [1]            r/w        */
        uint32 RSVD_2     : 1; /* [2]            ro         */
        uint32 SRE        : 1; /* [3]            r/w        */
        uint32 PFE        : 1; /* [4]            r/w        */
        uint32 ODE        : 1; /* [5]            r/w        */
        uint32 RSVD_7_6   : 2; /* [7:6]          ro         */
        uint32 MUX        : 3; /* [10:8]         r/w        */
        uint32 RSVD_14_11 : 4; /* [14:11]        ro         */
        uint32 LK         : 1; /* [15]           r/w        */
        uint32 IRQC       : 4; /* [19:16]        r/w        */
        uint32 RSVD_22_20 : 3; /* [22:20]        ro         */
        uint32 ISF        : 1; /* [23]           r/w        */
        uint32 FLT        : 5; /* [28:24]        r/w        */
        uint32 RSVD_30_29 : 2; /* [30:29]        ro         */
        uint32 FLTEN      : 1; /* [31]           r/w        */
    } PORTx_PCRn[32];

    /* 0x90*/
    struct
    {
        uint32 ISF : 32; /* [31:0]         r/w        */
    } PORTx_IRQFLG;

}; /*port*/

struct Reg_Port_W
{
    /* 0x0*/
    uint8 zResverd0x0[8];
    /* 0x8*/
    uint32 PORTx_GLBDAT;
    /* 0xC*/
    uint32 PORTx_GLBCTL;
    /* 0x10*/
    uint32 PORTx_PCRn[32];
    /* 0x90*/
    uint32 PORTx_IRQFLG;
}; /*port*/

typedef volatile struct Reg_Port_Bf Reg_Port_BfType;
typedef volatile struct Reg_Port_W  Reg_Port_WType;

struct Reg_Regfile_Bf
{
    /* 0x0*/
    struct
    {
        uint32 DATA : 32; /* [31:0]         rw         */
    } REGFILE_REGn[32];

}; /*regfile*/

struct Reg_Regfile_W
{
    /* 0x0*/
    uint32 REGFILE_REGn[32];
}; /*regfile*/

typedef volatile struct Reg_Regfile_Bf Reg_Regfile_BfType;
typedef volatile struct Reg_Regfile_W  Reg_Regfile_WType;

struct Reg_Rtc_Bf
{
    /* 0x00*/
    struct
    {
        uint32 CRYSTAL_EN         : 1;  /* [0]            r/w        */
        uint32 CNT_CLK_SEL        : 1;  /* [1]            r/w        */
        uint32 CLKOUT_SEL         : 1;  /* [2]            r/w        */
        uint32 CLKOUT_PIN_EN      : 1;  /* [3]            r/w        */
        uint32 SUP_EN             : 1;  /* [4]            r/w        */
        uint32 SW_RST             : 1;  /* [5]            r/w        */
        uint32 COUNT_EN           : 1;  /* [6]            r/w        */
        uint32 OVF                : 1;  /* [7]            ro         */
        uint32 ALARM_MATCHF       : 1;  /* [8]            ro         */
        uint32 OSC_RDY            : 1;  /* [9]            ro         */
        uint32 EXTAL_32K_EN       : 1;  /* [10]           r/w        */
        uint32 SECONDS_INT_FLAG   : 1;  /* [11]           w1c        */
        uint32 PERIODIC_CNT_EN    : 1;  /* [12]           r/w        */
        uint32 PERIODIC_MATCH_FLG : 1;  /* [13]           w1c        */
        uint32 RSVD_31_14         : 18; /* [31:14]        ro         */
    } RTC_CSR;

    /* 0x04*/
    struct
    {
        uint32 SECOND_INT_MUX_SEL : 3;  /* [2:0]          r/w        */
        uint32 OVFLOW_IE          : 1;  /* [3]            r/w        */
        uint32 ALARM_IE           : 1;  /* [4]            r/w        */
        uint32 SECONDS_IE         : 1;  /* [5]            r/w        */
        uint32 PERIODIC_IE        : 1;  /* [6]            r/w        */
        uint32 RSVD_31_7          : 25; /* [31:7]         ro         */
    } RTC_IER;

    /* 0x08*/
    struct
    {
        uint32 ALARM_CNT : 32; /* [31:0]         r/w        */
    } RTC_ALARM_CNTR;

    /* 0x0c*/
    struct
    {
        uint32 ONE_SECOND_CNT : 16; /* [15:0]         r/w        */
        uint32 RSVD_31_16     : 16; /* [31:16]        ro         */
    } RTC_ONE_SECOND_CNTR;

    /* 0x10*/
    struct
    {
        uint32 MATCH_CNT : 32; /* [31:0]         r/w        */
    } RTC_MATCH_CNTR;

    /* 0x14*/
    struct
    {
        uint32 COMP_CNT       : 7; /* [6:0]          r/w        */
        uint32 COMP_DIRECTION : 1; /* [7]            r/w        */
        uint32 DLY            : 8; /* [15:8]         r/w        */
        uint32 CCOMP_CNT      : 8; /* [23:16]        ro         */
        uint32 CDLY           : 8; /* [31:24]        ro         */
    } RTC_COMPENSATIONR;

    /* 0x18*/
    struct
    {
        uint32 RSVD_30_0 : 31; /* [30:0]         ro         */
        uint32 LOCK      : 1;  /* [31]           r/w        */
    } RTC_LOCKR;

    /* 0x1c*/
    uint8 zResverd0x01C[4]; /*pad 0x01C - 01F*/

    /* 0x20*/
    struct
    {
        uint32 PERIODIC_TMR_CNT : 32; /* [31:0]         r/w        */
    } RTC_PERIODIC_TMR_CNT;

    /* 0x24*/
    struct
    {
        uint32 PERIODIC_MATCH_CNT : 32; /* [31:0]         r/w        */
    } RTC_PERIODIC_TMR_MATCH_CNT;

}; /*rtc*/

struct Reg_Rtc_W
{
    /* 0x00*/
    uint32 RTC_CSR;
    /* 0x04*/
    uint32 RTC_IER;
    /* 0x08*/
    uint32 RTC_ALARM_CNTR;
    /* 0x0c*/
    uint32 RTC_ONE_SECOND_CNTR;
    /* 0x10*/
    uint32 RTC_MATCH_CNTR;
    /* 0x14*/
    uint32 RTC_COMPENSATIONR;
    /* 0x18*/
    uint32 RTC_LOCKR;
    /* 0x1c*/
    uint8 zResverd0x01C[4]; /*pad 0x01C - 01F*/
    /* 0x20*/
    uint32 RTC_PERIODIC_TMR_CNT;
    /* 0x24*/
    uint32 RTC_PERIODIC_TMR_MATCH_CNT;
}; /*rtc*/

typedef volatile struct Reg_Rtc_Bf Reg_Rtc_BfType;
typedef volatile struct Reg_Rtc_W  Reg_Rtc_WType;

struct Reg_Scc_Bf
{
    /* 0x0*/
    uint32 zResverd0x0;

    /* 0x4*/
    struct
    {
        uint32 CLKSPRES  : 5;  /* [4:0]          r          */
        uint32 RSVD_27_5 : 23; /* [27:5]         r          */
        uint32 DIVPRES   : 3;  /* [30:28]        r          */
        uint32 RSVD_31   : 1;  /* [31]           r          */
    } SCC_PARAM;

    /* 0x8*/
    struct
    {
        uint32 DIVSLOW    : 4;  /* [3:0]          r          */
        uint32 DIVBUS     : 4;  /* [7:4]          r          */
        uint32 DIVCORE    : 4;  /* [11:8]         r          */
        uint32 RSVD_15_12 : 4;  /* [15:12]        r          */
        uint32 SCS        : 3;  /* [18:16]        r          */
        uint32 RSVD_31_19 : 13; /* [31:19]        r          */
    } SCC_CST;

    /* 0xC*/
    struct
    {
        uint32 DIVSLOW    : 4;  /* [3:0]          r/w        */
        uint32 DIVBUS     : 4;  /* [7:4]          r/w        */
        uint32 DIVCORE    : 4;  /* [11:8]         r/w        */
        uint32 RSVD_15_12 : 4;  /* [15:12]        r          */
        uint32 SCS        : 3;  /* [18:16]        r/w        */
        uint32 RSVD_30_19 : 12; /* [30:19]        r          */
        uint32 LOCK       : 1;  /* [31]           r/w        */
    } SCC_CFG;

    /* 0x10*/
    struct
    {
        uint32 RSVD_15_0  : 16; /* [15:0]         r          */
        uint32 CLKOUTSEL  : 4;  /* [19:16]        r/w        */
        uint32 RSVD_31_20 : 12; /* [31:20]                   */
    } SCC_CLKOUTCFG;

    /* 0x14*/
    struct
    {
        uint32 OSCEN       : 1;  /* [0]            r/w        */
        uint32 OSCSTOPEN   : 1;  /* [1]            r/w        */
        uint32 RSVD_3_2    : 2;  /* [3:2]          r          */
        uint32 OSCLOCINTEN : 1;  /* [4]            r/w        */
        uint32 RSVD_8_5    : 4;  /* [8:5]          r          */
        uint32 OSCCME      : 1;  /* [9]            r/w        */
        uint32 OSCCMRE     : 1;  /* [10]           r/w        */
        uint32 RSVD_15_11  : 5;  /* [15:11]        r          */
        uint32 OSCRDY      : 1;  /* [16]           r          */
        uint32 OSCSELD     : 1;  /* [17]           r          */
        uint32 OSCLOC      : 1;  /* [18]           r/w        */
        uint32 RSVD_30_19  : 12; /* [30:19]        r          */
        uint32 LOCK        : 1;  /* [31]           r/w        */
    } SCC_OSCCS;

    /* 0x18*/
    struct
    {
        uint32 EXCLKS     : 1;  /* [0]            r/w        */
        uint32 OLMEN      : 1;  /* [1]            r/w        */
        uint32 HFREQ      : 1;  /* [2]            r/w        */
        uint32 RSVD_7_3   : 5;  /* [7:3]          r          */
        uint32 ITRIM      : 2;  /* [9:8]          r/w        */
        uint32 RSVD_30_10 : 21; /* [30:10]        r          */
        uint32 LOCK       : 1;  /* [31]           r/w        */
    } SCC_OSCCFG;

    /* 0x1C*/
    struct
    {
        uint32 FIRCEN       : 1;  /* [0]            r/w        */
        uint32 FIRCSTOPEN   : 1;  /* [1]            r/w        */
        uint32 RSVD_3_2     : 2;  /* [3:2]          r          */
        uint32 FIRCLOCINTEN : 1;  /* [4]            r/w        */
        uint32 RSVD_8_5     : 4;  /* [8:5]          r          */
        uint32 FIRCCME      : 1;  /* [9]            r/w        */
        uint32 FIRCCMRE     : 1;  /* [10]           r/w        */
        uint32 RSVD_11      : 1;  /* [11]           r          */
        uint32 RSVD_12      : 1;  /* [12]           r/w        */
        uint32 RSVD_15_13   : 3;  /* [15:13]        r          */
        uint32 FIRCRDY      : 1;  /* [16]           r          */
        uint32 FIRCSELD     : 1;  /* [17]           r          */
        uint32 FIRCLOC      : 1;  /* [18]           r/w        */
        uint32 RSVD_30_19   : 12; /* [30:19]        r          */
        uint32 LOCK         : 1;  /* [31]           r/w        */
    } SCC_FIRCCS;

    uint8 zResverd0x020[8]; /*pad 0x020 - 027*/

    /* 0x28*/
    struct
    {
        uint32 SPLLEN     : 1; /* [0]            r/w        */
        uint32 SPLLSTOPEN : 1; /* [1]            r/w        */
        uint32 RSVD_3_2   : 2; /* [3:2]          r          */
        uint32 RSVD_4     : 1; /* [4]            r/w        */
        uint32 RSVD_8_5   : 4; /* [8:5]          r          */
        uint32 RDYEN      : 1; /* [9]            r/w        */
        uint32 RSVD_10    : 1; /* [10]           r/w        */
        uint32 RSVD_11    : 1; /* [11]           r          */
        uint32 LOCKWIN    : 2; /* [13:12]        r/w        */
        uint32 RSVD_15_14 : 2; /* [15:14]        r          */
        uint32 SPLLRDY    : 1; /* [16]           r          */
        uint32 SPLLSELD   : 1; /* [17]           r          */
        uint32 RSVD_18    : 1; /* [18]           r/w        */
        uint32 RSVD_24_19 : 6; /* [24:19]        r          */
        uint32 OUTEN      : 1; /* [25]           r/w        */
        uint32 RSVD_30_26 : 5; /* [30:26]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } SCC_SPLLCS;

    /* 0x2C*/
    struct
    {
        uint32 PREDIV     : 2;  /* [1:0]          r/w        */
        uint32 RSVD_3_2   : 2;  /* [3:2]          r          */
        uint32 FBPRESEN   : 1;  /* [4]            r/w        */
        uint32 REFCKS     : 1;  /* [5]            r/w        */
        uint32 RSVD_7_6   : 2;  /* [7:6]          r          */
        uint32 MULT       : 8;  /* [15:8]         r/w        */
        uint32 POSTDIV    : 3;  /* [18:16]        r/w        */
        uint32 RSVD_30_19 : 12; /* [30:19]        r          */
        uint32 LOCK       : 1;  /* [31]           r/w        */
    } SCC_SPLLCFG1;

    /* 0x30*/
    struct
    {
        uint32 CPIR       : 2; /* [1:0]          r/w        */
        uint32 CPIC       : 2; /* [3:2]          r/w        */
        uint32 CS         : 2; /* [5:4]          r/w        */
        uint32 CAP        : 2; /* [7:6]          r/w        */
        uint32 RES        : 3; /* [10:8]         r/w        */
        uint32 KVCO       : 1; /* [11]           r/w        */
        uint32 VCODIV     : 1; /* [12]           r/w        */
        uint32 PFDDIEN    : 1; /* [13]           r/w        */
        uint32 CPISEL     : 1; /* [14]           r/w        */
        uint32 RSVD_15    : 1; /* [15]           r          */
        uint32 RSVD_23_16 : 8; /* [23:16]        r          */
        uint32 LDOODEN    : 1; /* [24]           r/w        */
        uint32 RSVD_30_25 : 6; /* [30:25]        r          */
        uint32 LOCK       : 1; /* [31]           r/w        */
    } SCC_SPLLCFG2;
}; /*scc*/

struct Reg_Scc_W
{
    /* 0x0*/
    uint32 zResverd0x0;
    /* 0x4*/
    uint32 SCC_PARAM;
    /* 0x8*/
    uint32 SCC_CST;
    /* 0xC*/
    uint32 SCC_CFG;
    /* 0x10*/
    uint32 SCC_CLKOUTCFG;
    /* 0x14*/
    uint32 SCC_OSCCS;
    /* 0x18*/
    uint32 SCC_OSCCFG;
    /* 0x1C*/
    uint32 SCC_FIRCCS;
    uint8  zResverd0x020[8]; /*pad 0x020 - 027*/
    /* 0x28*/
    uint32 SCC_SPLLCS;
    /* 0x2C*/
    uint32 SCC_SPLLCFG1;
    /* 0x30*/
    uint32 SCC_SPLLCFG2;
}; /*scc*/

typedef volatile struct Reg_Scc_Bf Reg_Scc_BfType;
typedef volatile struct Reg_Scc_W  Reg_Scc_WType;

struct Reg_Scm_Bf
{
    /* 0x00*/
    struct
    {
        uint32 RSVD_3_0   : 4;  /* [3:0]          ro         */
        uint32 CLKOUTSEL  : 2;  /* [5:4]          r/w        */
        uint32 RSVD_7_6   : 2;  /* [7:6]          ro         */
        uint32 CLKOUTDIV  : 3;  /* [10:8]         r/w        */
        uint32 CLKOUTEN   : 1;  /* [11]           r/w        */
        uint32 RSVD_31_12 : 20; /* [31:12]        ro         */
    } SCM_CHIPCTL;

    /* 0x04*/
    struct
    {
        uint32 SWTRIG0                : 1; /* [0]            r/w        */
        uint32 SWTRIG1                : 1; /* [1]            r/w        */
        uint32 SWTRIG2                : 1; /* [2]            r/w        */
        uint32 SWTRIG3                : 1; /* [3]            r/w        */
        uint32 SRAML_READ_BUFF_EN     : 1; /* [4]            r/w        */
        uint32 SRAMU_READ_BUFF_EN     : 1; /* [5]            r/w        */
        uint32 XBAR_ROUND_ROBIN       : 1; /* [6]            r/w        */
        uint32 RSVD_7                 : 1; /* [7]            r/w        */
        uint32 RSVD_8                 : 1; /* [8]            r/w        */
        uint32 RSVD_9                 : 1; /* [9]            r/w        */
        uint32 RSVD_10                : 1; /* [10]           r/w        */
        uint32 CCACHE_CLR             : 1; /* [11]           r/w        */
        uint32 CCACHE_PARITY_MISS_EN  : 1; /* [12]           r/w        */
        uint32 CCACHE_PARITY_FAULT_EN : 1; /* [13]           r/w        */
        uint32 CACHE_DIS              : 1; /* [14]           r/w        */
        uint32 RSVD_15                : 1; /* [15]           r/w        */
        uint32 CCACHE_BE_INT_EN       : 1; /* [16]           r/w        */
        uint32 RSVD_23_17             : 7; /* [23:17]        ro         */
        uint32 FPU_INEXACT_INT_EN     : 1; /* [24]           r/w        */
        uint32 FPU_OVERFLOW_INT_EN    : 1; /* [25]           r/w        */
        uint32 FPU_UNDERFLOW_INT_EN   : 1; /* [26]           r/w        */
        uint32 FPU_INVALIDOP_INT_EN   : 1; /* [27]           r/w        */
        uint32 FPU_DIVZERO_INT_EN     : 1; /* [28]           r/w        */
        uint32 FPU_DENORMALIN_INT_EN  : 1; /* [29]           r/w        */
        uint32 RSVD_31_30             : 2; /* [31:30]        ro         */
    } SCM_MISCCTL1;

    uint8 zResverd0x08[32]; /*pad 0x08 - 027*/

    /* 0x28*/
    struct
    {
        uint32 RSVD_7_0        : 8; /* [7:0]          ro         */
        uint32 MCPWM0_TCLK_SEL : 2; /* [9:8]          r/w        */
        uint32 MCPWM1_TCLK_SEL : 2; /* [11:10]        r/w        */
        uint32 TIM0_TCLK_SEL   : 2; /* [13:12]        r/w        */
        uint32 TIM1_TCLK_SEL   : 2; /* [15:14]        r/w        */
        uint32 TIM2_TCLK_SEL   : 2; /* [17:16]        r/w        */
        uint32 TIM3_TCLK_SEL   : 2; /* [19:18]        r/w        */
        uint32 RSVD_23_20      : 4; /* [23:20]        ro         */
        uint32 ADC0_CH8_SEL    : 1; /* [24]           r/w        */
        uint32 ADC0_CH9_SEL    : 1; /* [25]           r/w        */
        uint32 ADC1_CH14_SEL   : 1; /* [26]           r/w        */
        uint32 ADC1_CH15_SEL   : 1; /* [27]           r/w        */
        uint32 RSVD_31_28      : 4; /* [31:28]        ro         */
    } SCM_MISCCTL2;

    uint8 zResverd0x02C[20]; /*pad 0x02C - 03F*/

    /* 0x40*/
    struct
    {
        uint32 RSVD_14_0           : 15; /* [14:0]         ro         */
        uint32 RSVD_15             : 1;  /* [15]           r/w        */
        uint32 CCACHE_BE_FLAG      : 8;  /* [23:16]        r/w        */
        uint32 FPU_INEXACT_FLAG    : 1;  /* [24]           r/w        */
        uint32 FPU_OVERFLOW_FLAG   : 1;  /* [25]           r/w        */
        uint32 FPU_UNDERFLOW_FLAG  : 1;  /* [26]           r/w        */
        uint32 FPU_INVALIDOP_FLAG  : 1;  /* [27]           r/w        */
        uint32 FPU_DIVZERO_FLAG    : 1;  /* [28]           r/w        */
        uint32 FPU_DENORMALIN_FLAG : 1;  /* [29]           r/w        */
        uint32 RSVD_31_30          : 2;  /* [31:30]        ro         */
    } SCM_MISCSTAT1;

    /* 0x44*/
    struct
    {
        uint32 CACHE_BE_ADDR : 32; /* [31:0]         ro         */
    } SCM_MISCDATA1;

    /* 0x48*/
    struct
    {
        uint32 CACHE_BE_DATA : 32; /* [31:0]         ro         */
    } SCM_MISCDATA2;

    uint8 zResverd0x04C[180]; /*pad 0x04C - 0FF*/

    /* 0x100*/
    struct
    {
        uint32 CCACHE_DIS_IFR : 1;  /* [0]            ro         */
        uint32 FPU_DIS        : 1;  /* [1]            r/w        */
        uint32 RSVD_31_2      : 30; /* [31:2]         ro         */
    } SCM_CHIPOPT;

    /* 0x104*/
    struct
    {
        uint32 RSVD_23_0 : 24; /* [23:0]         ro         */
        uint32 PFSIZE    : 4;  /* [27:24]        ro         */
        uint32 DFSIZE    : 4;  /* [31:28]        ro         */
    } SCM_FLSCFG;

    /* 0x108*/
    struct
    {
        uint32 CACHESIZE : 4;  /* [3:0]          ro         */
        uint32 RSVD_27_4 : 24; /* [27:4]         ro         */
        uint32 RAMSIZE   : 4;  /* [31:28]        ro         */
    } SCM_RAMCFG;

    uint8 zResverd0x010C[16]; /*pad 0x010C - 011B*/

    /* 0x11C*/
    struct
    {
        uint32 MEMSIZE_ID   : 4; /* [3:0]          ro         */
        uint32 SERIES_ID    : 3; /* [6:4]          ro         */
        uint32 SUBFAMILY_ID : 5; /* [11:7]         ro         */
        uint32 FAMILY_ID    : 4; /* [15:12]        ro         */
        uint32 REV_ID       : 4; /* [19:16]        ro         */
        uint32 FEATURE_ID   : 7; /* [26:20]        ro         */
        uint32 PACKAGE_ID   : 5; /* [31:27]        ro         */
    } SCM_DEVID;

    /* 0x120*/
    struct
    {
        uint32 UID_31_0 : 32; /* [31:0]         ro         */
    } SCM_UNIQUE0;

    /* 0x124*/
    struct
    {
        uint32 UID_63_32 : 32; /* [31:0]         ro         */
    } SCM_UNIQUE1;

    /* 0x128*/
    struct
    {
        uint32 UID_95_64 : 32; /* [31:0]         ro         */
    } SCM_UNIQUE2;

    /* 0x12C*/
    struct
    {
        uint32 UID_127_96 : 32; /* [31:0]         ro         */
    } SCM_UNIQUE3;

}; /*scm*/

struct Reg_Scm_W
{
    /* 0x00*/
    uint32 SCM_CHIPCTL;
    /* 0x04*/
    uint32 SCM_MISCCTL1;
    uint8  zResverd0x08[32]; /*pad 0x08 - 027*/

    /* 0x28*/
    uint32 SCM_MISCCTL2;
    uint8  zResverd0x02C[20]; /*pad 0x02C - 03F*/

    /* 0x40*/
    uint32 SCM_MISCSTAT1;
    /* 0x44*/
    uint32 SCM_MISCDATA1;
    /* 0x48*/
    uint32 SCM_MISCDATA2;
    uint8  zResverd0x04C[180]; /*pad 0x04C - 0FF*/

    /* 0x100*/
    uint32 SCM_CHIPOPT;
    /* 0x104*/
    uint32 SCM_FLSCFG;
    /* 0x108*/
    uint32 SCM_RAMCFG;
    uint8  zResverd0x010C[16]; /*pad 0x010C - 011B*/

    /* 0x11C*/
    uint32 SCM_DEVID;
    /* 0x120*/
    uint32 SCM_UNIQUE0;
    /* 0x124*/
    uint32 SCM_UNIQUE1;
    /* 0x128*/
    uint32 SCM_UNIQUE2;
    /* 0x12C*/
    uint32 SCM_UNIQUE3;
}; /*scm*/

typedef volatile struct Reg_Scm_Bf Reg_Scm_BfType;
typedef volatile struct Reg_Scm_W  Reg_Scm_WType;

struct Reg_Seru_Bf
{
    /* 0x0*/
    uint32 zResverd0x0;
    /* 0x4*/
    struct
    {
        uint32 PARAM : 32; /* [31:0]         r          */
    } SERU_PARAM;

    /* 0x8*/
    struct
    {
        uint32 CRPAR_INT_EN : 1;  /* [0]            r/w        */
        uint32 RSVD_3_1     : 3;  /* [3:1]          r/w        */
        uint32 EOUT_PS      : 1;  /* [4]            r/w        */
        uint32 EOUT0_IO_EN  : 1;  /* [5]            r/w        */
        uint32 EOUT1_IO_EN  : 1;  /* [6]            r/w        */
        uint32 FFI_EN       : 1;  /* [7]            r/w        */
        uint32 CFG_MODE     : 1;  /* [8]            r          */
        uint32 RSVD_31_9    : 23; /* [31:9]         r          */
    } SERU_CSR;

    /* 0xC*/
    struct
    {
        uint32 S_CRPAR_ERR : 1;  /* [0]            r/w1c      */
        uint32 RSVD_31_1   : 31; /* [31:1]         r/w        */
    } SERU_INTF;

    /* 0x10*/
    struct
    {
        uint32 KEY : 32; /* [31:0]         r/w        */
    } SERU_CFG_KEY;

    /* 0x14*/
    struct
    {
        uint32 CH_FFI_6_0  : 7;  /* [6:0]          r/w        */
        uint32 RSVD_7      : 1;  /* [7]            r          */
        uint32 CH_FFI_14_8 : 7;  /* [14:8]         r/w        */
        uint32 RSVD_15     : 1;  /* [15]           r          */
        uint32 CH_FFI_16   : 1;  /* [16]           r/w        */
        uint32 RSVD_31_17  : 15; /* [31:17]        r          */
    } SERU_CH_FFI;

    /* 0x18*/
    struct
    {
        uint32 SWERR_CH0 : 1;  /* [0]            r/w        */
        uint32 SWERR_CH1 : 1;  /* [1]            r/w        */
        uint32 SWERR_CH2 : 1;  /* [2]            r/w        */
        uint32 RSVD_31_3 : 29; /* [31:3]         r/w        */
    } SERU_SWERR_GNT;

    /* 0x1C*/
    struct
    {
        uint32 CH_FLAG_6_0  : 7;  /* [6:0]          r/w1c      */
        uint32 RSVD_7       : 1;  /* [7]            r          */
        uint32 CH_FLAG_14_8 : 7;  /* [14:8]         r/w1c      */
        uint32 RSVD_15      : 1;  /* [15]           r          */
        uint32 CH_FLAG_16   : 1;  /* [16]           r/w1c      */
        uint32 RSVD_31_17   : 15; /* [31:17]        r          */
    } SERU_CH_FLAG;

    /* 0x20*/
    struct
    {
        uint32 CH_EN        : 1;  /* [0]            r/w        */
        uint32 CH_INT_CFG   : 1;  /* [1]            r/w        */
        uint32 CH_INT_TYP   : 1;  /* [2]            r/w        */
        uint32 CH_EOUT_CFG  : 1;  /* [3]            r/w        */
        uint32 CH_RESET_CFG : 1;  /* [4]            r/w        */
        uint32 CH_RESET_TYP : 1;  /* [5]            r/w        */
        uint32 CH_RESET_DLY : 2;  /* [7:6]          r/w        */
        uint32 CH_FLAG      : 1;  /* [8]            r/w1c      */
        uint32 RSVD_31_9    : 23; /* [31:9]         r/w        */
    } SERU_CFG_CHn[17];

}; /*seru*/

struct Reg_Seru_W
{
    /* 0x0*/
    uint32 zResverd0x0;
    /* 0x4*/
    uint32 SERU_PARAM;
    /* 0x8*/
    uint32 SERU_CSR;
    /* 0xC*/
    uint32 SERU_INTF;
    /* 0x10*/
    uint32 SERU_CFG_KEY;
    /* 0x14*/
    uint32 SERU_CH_FFI;
    /* 0x18*/
    uint32 SERU_SWERR_GNT;
    /* 0x1C*/
    uint32 SERU_CH_FLAG;
    /* 0x20*/
    uint32 SERU_CFG_CHn[17];
}; /*seru*/

typedef volatile struct Reg_Seru_Bf Reg_Seru_BfType;
typedef volatile struct Reg_Seru_W  Reg_Seru_WType;

struct Reg_Smpu_Bf
{
    /* 0x00*/
    uint32 zResverd0x00;
    /* 0x04*/
    struct
    {
        uint32 S0ERR     : 1;  /* [0]            rw         */
        uint32 S1ERR     : 1;  /* [1]            rw         */
        uint32 S2ERR     : 1;  /* [2]            rw         */
        uint32 RSVD_3    : 1;  /* [3]            ro         */
        uint32 RSVD_7_4  : 4;  /* [7:4]                     */
        uint32 GLBEN     : 1;  /* [8]            rw         */
        uint32 RSVD_31_9 : 23; /* [31:9]                    */
    } SMPU_CS;

    uint8 zResverd0x08[8]; /*pad 0x08 - 0F*/

    /* 0x10*/
    struct
    {
        uint32 EADDR : 32; /* [31:0]         ro         */
    } SMPU_Sn_EA[3];

    uint8 zResverd0x01C[20]; /*pad 0x01C - 02F*/

    /* 0x30*/
    struct
    {
        uint32 EMRC       : 16; /* [15:0]         ro         */
        uint32 RSVD_23_16 : 8;  /* [23:16]        ro         */
        uint32 EMN        : 4;  /* [27:24]        ro         */
        uint32 EATTR      : 1;  /* [28]           ro         */
        uint32 EUS        : 1;  /* [29]           ro         */
        uint32 RSVD_30    : 1;  /* [30]           ro         */
        uint32 ERW        : 1;  /* [31]           ro         */
    } SMPU_Sn_ES[3];

    uint8 zResverd0x03C[196]; /*pad 0x03C - 0FF*/
    struct
    {
        /* 0x100*/
        struct
        {
            uint32 RSVD_4_0 : 5;  /* [4:0]          rw         */
            uint32 SADDR    : 27; /* [31:5]         rw         */
        } SMPU_MRCn_W0;

        /* 0x104*/
        struct
        {
            uint32 RSVD_4_0 : 5;  /* [4:0]          rw         */
            uint32 EADDR    : 27; /* [31:5]         rw         */
        } SMPU_MRCn_W1;

        /* 0x108*/
        struct
        {
            uint32 M0UX       : 1;  /* [0]            rw         */
            uint32 M0UW       : 1;  /* [1]            rw         */
            uint32 M0UR       : 1;  /* [2]            rw         */
            uint32 M0SM       : 2;  /* [4:3]          rw         */
            uint32 RSVD_5     : 1;  /* [5]            rw         */
            uint32 M1UX       : 1;  /* [6]            rw         */
            uint32 M1UW       : 1;  /* [7]            rw         */
            uint32 M1UR       : 1;  /* [8]            rw         */
            uint32 M1SM       : 2;  /* [10:9]         rw         */
            uint32 RSVD_11    : 1;  /* [11]           rw         */
            uint32 M2UX       : 1;  /* [12]           rw         */
            uint32 M2UW       : 1;  /* [13]           rw         */
            uint32 M2UR       : 1;  /* [14]           rw         */
            uint32 M2SM       : 2;  /* [16:15]        rw         */
            uint32 RSVD_31_17 : 15; /* [31:17]        ro         */
        } SMPU_MRCn_W2;

        /* 0x10C*/
        struct
        {
            uint32 RSVD_15_0  : 16; /* [15:0]         rw         */
            uint32 EN         : 1;  /* [16]           rw         */
            uint32 RSVD_31_17 : 15; /* [31:17]        rw         */
        } SMPU_MRCn_W3;
    } SMPU_MRCn_W[16];
}; /*smpu*/

struct Reg_Smpu_W
{
    /* 0x00*/
    uint32 zResverd0x00;
    /* 0x04*/
    uint32 SMPU_CS;
    uint8  zResverd0x08[8]; /*pad 0x08 - 0F*/

    /* 0x10*/
    uint32 SMPU_Sn_EA[3];
    uint8  zResverd0x01C[20]; /*pad 0x01C - 02F*/

    /* 0x30*/
    uint32 SMPU_Sn_ES[3];
    uint8  zResverd0x03C[196]; /*pad 0x03C - 0FF*/
    struct
    {
        /* 0x100*/
        uint32 SMPU_MRCn_W0;
        /* 0x104*/
        uint32 SMPU_MRCn_W1;
        /* 0x108*/
        uint32 SMPU_MRCn_W2;
        /* 0x10C*/
        uint32 SMPU_MRCn_W3;
    } SMPU_MRCn_W[16];
}; /*smpu*/

typedef volatile struct Reg_Smpu_Bf Reg_Smpu_BfType;
typedef volatile struct Reg_Smpu_W  Reg_Smpu_WType;

struct Reg_Spi_Bf
{
    /* 0x0*/
    struct
    {
        uint32 RSVD_5_0   : 6; /* [5:0]          ro         */
        uint32 SCPH       : 1; /* [6]            r/w        */
        uint32 SCPOL      : 1; /* [7]            r/w        */
        uint32 TMOD       : 2; /* [9:8]          r/w        */
        uint32 RSVD_10    : 1; /* [10]           r/w        */
        uint32 RSVD_11    : 1; /* [11]           r/w        */
        uint32 RSVD_15_12 : 4; /* [15:12]        r/w        */
        uint32 DFS_32     : 5; /* [20:16]        r/w        */
        uint32 MST_MODE   : 1; /* [21]           r/w        */
        uint32 RSVD_22    : 1; /* [22]           r/w        */
        uint32 RSVD_23    : 1; /* [23]           r/w        */
        uint32 RSVD_24    : 1; /* [24]           r/w        */
        uint32 RSVD_31_25 : 7; /* [31:25]        ro         */
    } SPI_CTRLR0;

    /* 0x4*/
    struct
    {
        uint32 NDF        : 16; /* [15:0]         r/w        */
        uint32 RSVD_31_16 : 16; /* [31:16]        ro         */
    } SPI_CTRLR1;

    /* 0x8*/
    struct
    {
        uint32 SPI_EN     : 1;  /* [0]            r/w        */
        uint32 RSVD_15_1  : 15; /* [15:1]         ro         */
        uint32 SER        : 2;  /* [17:16]        r/w        */
        uint32 RSVD_31_18 : 14; /* [31:18]        ro         */
    } SPI_SSENR;

    /* 0xC*/
    struct
    {
        uint32 SCKDV      : 16; /* [15:0]         r/w        */
        uint32 RSVD_31_16 : 16; /* [31:16]        ro         */
    } SPI_BAUDR;

    /* 0x10*/
    struct
    {
        uint32 TFT        : 2;  /* [1:0]          r/w        */
        uint32 RSVD_15_2  : 14; /* [15:2]         ro         */
        uint32 RFT        : 2;  /* [17:16]        r/w        */
        uint32 RSVD_31_18 : 14; /* [31:18]        ro         */
    } SPI_FTLR;

    /* 0x14*/
    struct
    {
        uint32 TXTFL      : 3;  /* [2:0]          ro         */
        uint32 RSVD_15_3  : 13; /* [15:3]         ro         */
        uint32 RXTFL      : 3;  /* [18:16]        ro         */
        uint32 RSVD_31_19 : 13; /* [31:19]        ro         */
    } SPI_FLR;

    /* 0x18*/
    struct
    {
        uint32 BUSY      : 1;  /* [0]            ro         */
        uint32 TFNF      : 1;  /* [1]            ro         */
        uint32 TFE       : 1;  /* [2]            ro         */
        uint32 RFNE      : 1;  /* [3]            ro         */
        uint32 RFF       : 1;  /* [4]            ro         */
        uint32 TXE       : 1;  /* [5]            ro         */
        uint32 RSVD_31_6 : 26; /* [31:6]         ro         */
    } SPI_SR;

    /* 0x1C*/
    struct
    {
        uint32 TXEIE     : 1;  /* [0]            r/w        */
        uint32 TXOIE     : 1;  /* [1]            r/w        */
        uint32 RXUIE     : 1;  /* [2]            r/w        */
        uint32 RXOIE     : 1;  /* [3]            r/w        */
        uint32 RXFIE     : 1;  /* [4]            r/w        */
        uint32 RSVD_31_5 : 27; /* [31:5]         ro         */
    } SPI_IER;

    /* 0x20*/
    struct
    {
        uint32 TXEIS      : 1;  /* [0]            ro         */
        uint32 TXOIS      : 1;  /* [1]            ro         */
        uint32 RXUIS      : 1;  /* [2]            ro         */
        uint32 RXOIS      : 1;  /* [3]            ro         */
        uint32 RXFIS      : 1;  /* [4]            ro         */
        uint32 RSVD_15_5  : 11; /* [15:5]         ro         */
        uint32 TXEIR      : 1;  /* [16]           ro         */
        uint32 TXOIR      : 1;  /* [17]           ro         */
        uint32 RXUIR      : 1;  /* [18]           ro         */
        uint32 RXOIR      : 1;  /* [19]           ro         */
        uint32 RXFIR      : 1;  /* [20]           ro         */
        uint32 RSVD_31_21 : 11; /* [31:21]        ro         */
    } SPI_ISR;

    /* 0x24*/
    struct
    {
        uint32 TXOICR    : 1;  /* [0]            ro         */
        uint32 RSVD_31_1 : 31; /* [31:1]         ro         */
    } SPI_TXOICR;

    /* 0x28*/
    struct
    {
        uint32 RXOICR    : 1;  /* [0]            ro         */
        uint32 RSVD_31_1 : 31; /* [31:1]         ro         */
    } SPI_RXOICR;

    /* 0x2c*/
    struct
    {
        uint32 RXUICR    : 1;  /* [0]            ro         */
        uint32 RSVD_31_1 : 31; /* [31:1]         ro         */
    } SPI_RXUICR;

    uint8 zResverd0x030[4]; /*pad 0x030 - 033*/

    /* 0x34*/
    struct
    {
        uint32 ICR       : 1;  /* [0]            ro         */
        uint32 RSVD_31_1 : 31; /* [31:1]         ro         */
    } SPI_ICR;

    /* 0x38*/
    struct
    {
        uint32 RDMAE     : 1;  /* [0]            r/w        */
        uint32 TDMAE     : 1;  /* [1]            r/w        */
        uint32 RSVD_31_2 : 30; /* [31:2]         ro         */
    } SPI_DMACR;

    /* 0x3C*/
    struct
    {
        uint32 DMATDL    : 2;  /* [1:0]          r/w        */
        uint32 RSVD_31_2 : 30; /* [31:2]         ro         */
    } SPI_DMATDLR;

    /* 0x40*/
    struct
    {
        uint32 DMARDL    : 2;  /* [1:0]          r/w        */
        uint32 RSVD_31_2 : 30; /* [31:2]         ro         */
    } SPI_DMARDLR;

    uint8 zResverd0x044[28]; /*pad 0x044 - 05F*/

    /* 0x60*/
    struct
    {
        uint32 DR : 32; /* [31:0]         r/w        */
    } SPI_DR_LOW;

    uint8 zResverd0x064[136]; /*pad 0x064 - 0EB*/

    /* 0xEC*/
    struct
    {
        uint32 DR : 32; /* [31:0]         r/w        */
    } SPI_DR_HIGH;

}; /*spi*/

struct Reg_Spi_W
{
    /* 0x0*/
    uint32 SPI_CTRLR0;
    /* 0x4*/
    uint32 SPI_CTRLR1;
    /* 0x8*/
    uint32 SPI_SSENR;
    /* 0xC*/
    uint32 SPI_BAUDR;
    /* 0x10*/
    uint32 SPI_FTLR;
    /* 0x14*/
    uint32 SPI_FLR;
    /* 0x18*/
    uint32 SPI_SR;
    /* 0x1C*/
    uint32 SPI_IER;
    /* 0x20*/
    uint32 SPI_ISR;
    /* 0x24*/
    uint32 SPI_TXOICR;
    /* 0x28*/
    uint32 SPI_RXOICR;
    /* 0x2c*/
    uint32 SPI_RXUICR;
    uint8  zResverd0x030[4]; /*pad 0x030 - 033*/

    /* 0x34*/
    uint32 SPI_ICR;
    /* 0x38*/
    uint32 SPI_DMACR;
    /* 0x3C*/
    uint32 SPI_DMATDLR;
    /* 0x40*/
    uint32 SPI_DMARDLR;
    /* 0x44*/
    uint8 zResverd0x044[28]; /*pad 0x044 - 05F*/

    /* 0x60*/
    uint32 SPI_DR_LOW;
    uint8  zResverd0x064[136]; /*pad 0x064 - 0EB*/

    /* 0xEC*/
    uint32 SPI_DR_HIGH;
}; /*spi*/

typedef volatile struct Reg_Spi_Bf Reg_Spi_BfType;
typedef volatile struct Reg_Spi_W  Reg_Spi_WType;

struct Reg_Srmc_Bf
{
    /* 0x00*/
    uint32 zResverd0x00;
    /* 0x04*/
    struct
    {
        uint32 EWAKEUP    : 1;  /* [0]            ro         */
        uint32 ELVD       : 1;  /* [1]            ro         */
        uint32 ELOC       : 1;  /* [2]            ro         */
        uint32 RSVD_3     : 1;  /* [3]            ro         */
        uint32 RSVD_4     : 1;  /* [4]            ro         */
        uint32 EWDOG      : 1;  /* [5]            ro         */
        uint32 EPIN       : 1;  /* [6]            ro         */
        uint32 EPOR       : 1;  /* [7]            ro         */
        uint32 RSVD_8     : 1;  /* [8]            ro         */
        uint32 ELOCKUP    : 1;  /* [9]            ro         */
        uint32 ESW        : 1;  /* [10]           ro         */
        uint32 EADM_AP    : 1;  /* [11]           ro         */
        uint32 RSVD_12    : 1;  /* [12]           ro         */
        uint32 ESACKERR   : 1;  /* [13]           ro         */
        uint32 RSVD_15_14 : 2;  /* [15:14]        ro         */
        uint32 ESTB       : 1;  /* [16]           ro         */
        uint32 RSVD_31_17 : 15; /* [31:17]        ro         */
    } SRMC_PARAM;

    /* 0x08*/
    struct
    {
        uint32 WAKEUP     : 1;  /* [0]            ro        */
        uint32 LVD        : 1;  /* [1]            ro        */
        uint32 LOC        : 1;  /* [2]            ro        */
        uint32 RSVD_4_3   : 2;  /* [4:3]          ro        */
        uint32 WDOG       : 1;  /* [5]            ro        */
        uint32 PIN        : 1;  /* [6]            ro        */
        uint32 POR        : 1;  /* [7]            ro        */
        uint32 RSVD_8     : 1;  /* [8]            ro        */
        uint32 LOCKUP     : 1;  /* [9]            ro        */
        uint32 SW         : 1;  /* [10]           ro        */
        uint32 ADM_AP     : 1;  /* [11]           ro        */
        uint32 SERU_COLD  : 1;  /* [12]           ro        */
        uint32 SERU_SYS   : 1;  /* [13]           ro        */
        uint32 RSVD_14    : 1;  /* [14]           ro        */
        uint32 SACKERR    : 1;  /* [15]           ro        */
        uint32 RSVD_31_16 : 16; /* [31:16]        ro        */
    } SRMC_SRS;

    /* 0x0C*/
    struct
    {
        uint32 RSTFLTSRW     : 2;  /* [1:0]          r/w        */
        uint32 RSTFLTSS      : 1;  /* [2]            r/w        */
        uint32 RSVD_7_3      : 5;  /* [7:3]          r/w        */
        uint32 RSTFLTSEL     : 5;  /* [12:8]         r/w        */
        uint32 RSVD_30_13    : 18; /* [30:13]        r          */
        uint32 LOCKUP_RST_EN : 1;  /* [31]           r/w        */
    } SRMC_CTRL;

    uint8 zResverd0x010[8]; /*pad 0x010 - 017*/

    /* 0x18*/
    struct
    {
        uint32 SWAKEUP    : 1;  /* [0]            w1c         */
        uint32 SLVD       : 1;  /* [1]            w1c         */
        uint32 SLOC       : 1;  /* [2]            w1c         */
        uint32 RSVD_4_3   : 2;  /* [4:3]          ro          */
        uint32 SWDOG      : 1;  /* [5]            w1c         */
        uint32 SPIN       : 1;  /* [6]            w1c         */
        uint32 SPOR       : 1;  /* [7]            w1c         */
        uint32 RSVD_8     : 1;  /* [8]            ro          */
        uint32 SLOCKUP    : 1;  /* [9]            w1c         */
        uint32 SSW        : 1;  /* [10]           w1c         */
        uint32 SADM_AP    : 1;  /* [11]           w1c         */
        uint32 SSERU_COLD : 1;  /* [12]           w1c         */
        uint32 SSERU_SYS  : 1;  /* [13]           w1c         */
        uint32 RSVD_14    : 1;  /* [14]           ro          */
        uint32 SSACKERR   : 1;  /* [15]           w1c         */
        uint32 RSVD_31_16 : 16; /* [31:16]        ro          */
    } SRMC_SSRS;

    /* 0x1C*/
    struct
    {
        uint32 DELAY      : 2;  /* [1:0]          r/w        */
        uint32 LOC        : 1;  /* [2]            r/w        */
        uint32 RSVD_4_3   : 2;  /* [4:3]          ro         */
        uint32 WDOG       : 1;  /* [5]            r/w        */
        uint32 PIN        : 1;  /* [6]            r/w        */
        uint32 GIE        : 1;  /* [7]            r/w        */
        uint32 RSVD_8     : 1;  /* [8]            ro         */
        uint32 LOCKUP     : 1;  /* [9]            r/w        */
        uint32 SW         : 1;  /* [10]           r/w        */
        uint32 RSVD_11    : 1;  /* [11]           ro         */
        uint32 SERU_COLD  : 1;  /* [12]           w1c        */
        uint32 SERU_SYS   : 1;  /* [13]           w1c        */
        uint32 RSVD_14    : 1;  /* [14]           ro         */
        uint32 SACKERR    : 1;  /* [15]           r/w        */
        uint32 RSVD_31_16 : 16; /* [31:16]        ro         */
    } SRMC_SRIE;

    /* 0x20*/
    struct
    {
        uint32 APD       : 1;  /* [0]            r/w        */
        uint32 RSVD_31_1 : 31; /* [31:1]         ro         */
    } SRMC_PMPORT;

    /* 0x24*/
    struct
    {
        uint32 DSMC       : 2;  /* [1:0]          r/w        */
        uint32 RSVD_7_2   : 6;  /* [7:2]          ro         */
        uint32 DSMACKTMO  : 8;  /* [15:8]         r/w        */
        uint32 RSVD_31_16 : 16; /* [31:16]        ro         */
    } SRMC_PMCTRL;

    /* 0x28*/
    struct
    {
        uint32 PMSTAT    : 4;  /* [3:0]          ro         */
        uint32 RSVD_7_4  : 4;  /* [7:4]          ro         */
        uint32 DSMABORT  : 1;  /* [8]            ro         */
        uint32 RSVD_31_9 : 23; /* [31:9]         ro         */
    } SRMC_PMSTAT;

    /* 0x2C*/
    struct
    {
        uint32 WUPSRC_EN2_0  : 3;  /* [2:0]          r/w        */
        uint32 RSVD_3        : 1;  /* [3]            ro         */
        uint32 WUPSRC_EN15_4 : 12; /* [15:4]         r/w        */
        uint32 WUPSRC_PL2_0  : 3;  /* [18:16]        r/w        */
        uint32 RSVD_19       : 1;  /* [19]           ro         */
        uint32 WUPSRC_PL14_4 : 11; /* [30:20]        r/w        */
        uint32 RSVD_31       : 1;  /* [31]           r/w        */
    } SRMC_DSMWUPC1;

    /* 0x30*/
    struct
    {
        uint32 WUPSRC_EN16 : 1;  /* [0]            r/w        */
        uint32 RSVD_31_1   : 31; /* [31:1]         ro         */
    } SRMC_DSMWUPC2;

    /* 0x34*/
    struct
    {
        uint32 WUPS_2_0   : 3;  /* [2:0]          w1c        */
        uint32 RSVD_3     : 1;  /* [3]            ro         */
        uint32 WUPS_16_4  : 13; /* [16:4]         w1c        */
        uint32 RSVD_31_17 : 15; /* [31:17]        ro         */
    } SRMC_DSMWUPS;

}; /*srmc*/

struct Reg_Srmc_W
{
    /* 0x00*/
    uint32 zResverd0x00;
    /* 0x04*/
    uint32 SRMC_PARAM;
    /* 0x08*/
    uint32 SRMC_SRS;
    /* 0x0C*/
    uint32 SRMC_CTRL;
    uint8  zResverd0x010[8]; /*pad 0x010 - 017*/

    /* 0x18*/
    uint32 SRMC_SSRS;
    /* 0x1C*/
    uint32 SRMC_SRIE;
    /* 0x20*/
    uint32 SRMC_PMPORT;
    /* 0x24*/
    uint32 SRMC_PMCTRL;
    /* 0x28*/
    uint32 SRMC_PMSTAT;
    /* 0x2C*/
    uint32 SRMC_DSMWUPC1;
    /* 0x30*/
    uint32 SRMC_DSMWUPC2;
    /* 0x34*/
    uint32 SRMC_DSMWUPS;
}; /*srmc*/

typedef volatile struct Reg_Srmc_Bf Reg_Srmc_BfType;
typedef volatile struct Reg_Srmc_W  Reg_Srmc_WType;

struct Reg_Stim_Bf
{
    /* 0x00*/
    uint32 zResverd0x00;
    /* 0x04*/
    struct
    {
        uint32 CNT : 32; /* [31:0]         ro         */
    } STIM_CNTn[4];

    /* 0x14*/
    struct
    {
        uint32 CV : 32; /* [31:0]         r/w        */
    } STIM_CVn[4];

    /* 0x24*/
    struct
    {
        uint32 CLKS       : 2;  /* [1:0]          r/w        */
        uint32 PSDIV      : 4;  /* [5:2]          r/w        */
        uint32 PSEN       : 1;  /* [6]            r/w        */
        uint32 POL        : 1;  /* [7]            r/w        */
        uint32 PSRC       : 2;  /* [9:8]          r/w        */
        uint32 MODE       : 1;  /* [10]           r/w        */
        uint32 RSTDIS     : 1;  /* [11]           r/w        */
        uint32 DMAE       : 1;  /* [12]           r/w        */
        uint32 IE         : 1;  /* [13]           r/w        */
        uint32 EN         : 1;  /* [14]           r/w        */
        uint32 FLAG       : 1;  /* [15]           w1c        */
        uint32 RSVD_31_16 : 16; /* [31:16]                   */
    } STIM_SCn[4];

}; /*stim*/

struct Reg_Stim_W
{
    /* 0x00*/
    uint32 zResverd0x00;
    /* 0x04*/
    uint32 STIM_CNTn[4];
    /* 0x14*/
    uint32 STIM_CVn[4];
    /* 0x24*/
    uint32 STIM_SCn[4];
}; /*stim*/

typedef volatile struct Reg_Stim_Bf Reg_Stim_BfType;
typedef volatile struct Reg_Stim_W  Reg_Stim_WType;

struct Reg_Tdg_Bf
{
    /* 0x0*/
    uint32 zResverd0x0;
    /* 0x4*/
    struct
    {
        uint32 DOPNUM    : 4;  /* [3:0]          ro         */
        uint32 CHNUM     : 4;  /* [7:4]          ro         */
        uint32 RSVD_31_8 : 24; /* [31:8]         ro         */
    } TDG_PARAM;

    /* 0x8*/
    struct
    {
        uint32 TDGEN      : 1;  /* [0]            r/w        */
        uint32 RSVD_3_1   : 3;  /* [3:1]          ro         */
        uint32 TRIGS      : 1;  /* [4]            r/w        */
        uint32 CNTMD      : 1;  /* [5]            r/w        */
        uint32 CLRMD      : 1;  /* [6]            r/w        */
        uint32 RSVD_7     : 1;  /* [7]            ro         */
        uint32 PRES       : 3;  /* [10:8]         r/w        */
        uint32 RSVD_15_11 : 5;  /* [15:11]        ro         */
        uint32 CFGUP      : 1;  /* [16]           r/w        */
        uint32 SWTRG      : 1;  /* [17]           r/w        */
        uint32 RSVD_19_18 : 2;  /* [19:18]        ro         */
        uint32 UPMD       : 2;  /* [21:20]        r/w        */
        uint32 RSVD_31_22 : 10; /* [31:22]        ro         */
    } TDG_CTRL1;

    /* 0xC*/
    struct
    {
        uint32 CDO0IE     : 1;  /* [0]            r/w        */
        uint32 CDO1IE     : 1;  /* [1]            r/w        */
        uint32 CDO2IE     : 1;  /* [2]            r/w        */
        uint32 CDO3IE     : 1;  /* [3]            r/w        */
        uint32 CDO4IE     : 1;  /* [4]            r/w        */
        uint32 CDO5IE     : 1;  /* [5]            r/w        */
        uint32 RSVD_7_6   : 2;  /* [7:6]          ro         */
        uint32 ERRIE      : 1;  /* [8]            r/w        */
        uint32 RSVD_15_9  : 7;  /* [15:9]         ro         */
        uint32 CH0E       : 1;  /* [16]           r/w        */
        uint32 CH1E       : 1;  /* [17]           r/w        */
        uint32 CH2E       : 1;  /* [18]           r/w        */
        uint32 CH3E       : 1;  /* [19]           r/w        */
        uint32 CH4E       : 1;  /* [20]           r/w        */
        uint32 CH5E       : 1;  /* [21]           r/w        */
        uint32 RSVD_31_22 : 10; /* [31:22]        ro         */
    } TDG_CTRL2;

    /* 0x10*/
    struct
    {
        uint32 CDO0IF    : 1;  /* [0]            w1c        */
        uint32 CDO1IF    : 1;  /* [1]            w1c        */
        uint32 CDO2IF    : 1;  /* [2]            w1c        */
        uint32 CDO3IF    : 1;  /* [3]            w1c        */
        uint32 CDO4IF    : 1;  /* [4]            w1c        */
        uint32 CDO5IF    : 1;  /* [5]            w1c        */
        uint32 RSVD_7_6  : 2;  /* [7:6]          ro         */
        uint32 ERRIF     : 1;  /* [8]            w1c        */
        uint32 RSVD_31_9 : 23; /* [31:9]         ro         */
    } TDG_STAT;

    /* 0x14*/
    struct
    {
        uint32 MOD        : 16; /* [15:0]         r/w        */
        uint32 RSVD_31_16 : 16; /* [31:16]        ro         */
    } TDG_MOD;

    /* 0x18*/
    struct
    {
        uint32 CNT        : 16; /* [15:0]         ro         */
        uint32 RSVD_31_16 : 16; /* [31:16]        ro         */
    } TDG_CNT;

    struct
    {
        /* 0x1C*/
        struct
        {
            uint32 RSVD_7_0   : 8;  /* [7:0]                     */
            uint32 DO0E       : 1;  /* [8]            r/w        */
            uint32 DO1E       : 1;  /* [9]            r/w        */
            uint32 DO2E       : 1;  /* [10]           r/w        */
            uint32 DO3E       : 1;  /* [11]           r/w        */
            uint32 DO4E       : 1;  /* [12]           r/w        */
            uint32 DO5E       : 1;  /* [13]           r/w        */
            uint32 DO6E       : 1;  /* [14]           r/w        */
            uint32 DO7E       : 1;  /* [15]           r/w        */
            uint32 RSVD_31_16 : 16; /* [31:16]        ro         */
        } TDG_CHCTRL;

        /* 0x20 - 0x3F */
        struct
        {
            uint32 DO0OFS     : 16; /* [15:0]         r/w        */
            uint32 RSVD_31_16 : 16; /* [31:16]        ro         */
        } TDG_CHDOOFS[8];

        /* 0x40*/
        struct
        {
            uint32 CDOINTDLY  : 10; /* [9:0]          r/w        */
            uint32 RSVD_15_10 : 6;  /* [15:10]        ro         */
            uint32 LDCO       : 1;  /* [16]           ro         */
            uint32 RSVD_31_17 : 15; /* [31:17]        ro         */
        } TDG_CHCDOINTDLY;
    } TDG_CHCFG[6];
}; /*tdg*/

struct Reg_Tdg_W
{
    /* 0x0*/
    uint32 zResverd0x0;
    /* 0x4*/
    uint32 TDG_PARAM;
    /* 0x8*/
    uint32 TDG_CTRL1;
    /* 0xC*/
    uint32 TDG_CTRL2;
    /* 0x10*/
    uint32 TDG_STAT;
    /* 0x14*/
    uint32 TDG_MOD;
    /* 0x18*/
    uint32 TDG_CNT;

    struct
    {
        /* 0x1C*/
        uint32 TDG_CHCTRL;
        /* 0x20 -0x3F */
        uint32 TDG_CHDOOFS[8];
        /* 0x40*/
        uint32 TDG_CHCDOINTDLY;
    } TDG_CHCFG[6];
}; /*tdg*/

typedef volatile struct Reg_Tdg_Bf Reg_Tdg_BfType;
typedef volatile struct Reg_Tdg_W  Reg_Tdg_WType;

struct Reg_Tim_Bf
{
    /* 0x00*/
    struct
    {
        uint32 CKSRC     : 2;  /* [1:0]          r/w        */
        uint32 PSDIV     : 3;  /* [4:2]          r/w        */
        uint32 DBGM      : 2;  /* [6:5]          r/w        */
        uint32 RSVD_31_7 : 25; /* [31:7]                    */
    } TIM_TIMEBASE;

    /* 0x04*/
    struct
    {
        uint32 CNT        : 16; /* [15:0]         r/w        */
        uint32 RSVD_31_16 : 16; /* [31:16]                   */
    } TIM_CNT;

    /* 0x08*/
    struct
    {
        uint32 CNTINIT    : 16; /* [15:0]         r/w        */
        uint32 RSVD_31_16 : 16; /* [31:16]                   */
    } TIM_CNTINIT;

    /* 0x0C*/
    struct
    {
        uint32 MOD        : 16; /* [15:0]         r/w        */
        uint32 RSVD_31_16 : 16; /* [31:16]                   */
    } TIM_MOD;

    /* 0x10*/
    struct
    {
        uint32 CHOE0      : 1;  /* [0]            r/w        */
        uint32 CHOE1      : 1;  /* [1]            r/w        */
        uint32 CHOE2      : 1;  /* [2]            r/w        */
        uint32 CHOE3      : 1;  /* [3]            r/w        */
        uint32 CHOE4      : 1;  /* [4]            r/w        */
        uint32 CHOE5      : 1;  /* [5]            r/w        */
        uint32 CHOE6      : 1;  /* [6]            r/w        */
        uint32 CHOE7      : 1;  /* [7]            r/w        */
        uint32 RLDIE      : 1;  /* [8]            r/w        */
        uint32 TOIE       : 1;  /* [9]            r/w        */
        uint32 CNTMODE    : 1;  /* [10]           r/w        */
        uint32 INIT       : 1;  /* [11]           w/o        */
        uint32 RSVD_31_12 : 20; /* [31:12]                   */
    } TIM_GLBCR;

    /* 0x14*/
    struct
    {
        uint32 CH0F       : 1;  /* [0]            r/o        */
        uint32 CH1F       : 1;  /* [1]            r/o        */
        uint32 CH2F       : 1;  /* [2]            r/o        */
        uint32 CH3F       : 1;  /* [3]            r/o        */
        uint32 CH4F       : 1;  /* [4]            r/o        */
        uint32 CH5F       : 1;  /* [5]            r/o        */
        uint32 CH6F       : 1;  /* [6]            r/o        */
        uint32 CH7F       : 1;  /* [7]            r/o        */
        uint32 RLDF       : 1;  /* [8]            r/o        */
        uint32 TOF        : 1;  /* [9]            r/o        */
        uint32 WPDIS      : 1;  /* [10]           r/w        */
        uint32 RSVD_31_11 : 21; /* [31:11]                   */
    } TIM_GLBSR;

    /* 0x18*/
    struct
    {
        uint32 ELS       : 2;  /* [1:0]          r/w        */
        uint32 CMS       : 2;  /* [3:2]          r/w        */
        uint32 CHIE      : 1;  /* [4]            r/w        */
        uint32 CHF       : 1;  /* [5]            r/o        */
        uint32 DMAEN     : 1;  /* [6]            r/w        */
        uint32 ICRST     : 1;  /* [7]            r/w        */
        uint32 RSVD_31_8 : 24; /* [31:8]                    */
    } TIM_CMCn[8];

    /* 0x38*/
    struct
    {
        uint32 CCV        : 16; /* [15:0]         r/w        */
        uint32 RSVD_31_16 : 16; /* [31:16]                   */
    } TIM_CCVn[8];

    /* 0x58*/
    struct
    {
        uint32 INIT0      : 1; /* [0]            r/w        */
        uint32 INIT1      : 1; /* [1]            r/w        */
        uint32 INIT2      : 1; /* [2]            r/w        */
        uint32 INIT3      : 1; /* [3]            r/w        */
        uint32 INIT4      : 1; /* [4]            r/w        */
        uint32 INIT5      : 1; /* [5]            r/w        */
        uint32 INIT6      : 1; /* [6]            r/w        */
        uint32 INIT7      : 1; /* [7]            r/w        */
        uint32 POL0       : 1; /* [8]            r/w        */
        uint32 POL1       : 1; /* [9]            r/w        */
        uint32 POL2       : 1; /* [10]           r/w        */
        uint32 POL3       : 1; /* [11]           r/w        */
        uint32 POL4       : 1; /* [12]           r/w        */
        uint32 POL5       : 1; /* [13]           r/w        */
        uint32 POL6       : 1; /* [14]           r/w        */
        uint32 POL7       : 1; /* [15]           r/w        */
        uint32 TRIGE0     : 1; /* [16]           r/w        */
        uint32 TRIGE1     : 1; /* [17]           r/w        */
        uint32 TRIGE2     : 1; /* [18]           r/w        */
        uint32 TRIGE3     : 1; /* [19]           r/w        */
        uint32 TRIGE4     : 1; /* [20]           r/w        */
        uint32 TRIGE5     : 1; /* [21]           r/w        */
        uint32 TRIGE6     : 1; /* [22]           r/w        */
        uint32 TRIGE7     : 1; /* [23]           r/w        */
        uint32 INITRIGE   : 1; /* [24]           r/w        */
        uint32 TRIGF      : 1; /* [25]           r/o        */
        uint32 RSVD_31_26 : 6; /* [31:26]                   */
    } TIM_OUTCR;

    /* 0x5C*/
    struct
    {
        uint32 CH0OC      : 1;  /* [0]            r/w        */
        uint32 CH1OC      : 1;  /* [1]            r/w        */
        uint32 CH2OC      : 1;  /* [2]            r/w        */
        uint32 CH3OC      : 1;  /* [3]            r/w        */
        uint32 CH4OC      : 1;  /* [4]            r/w        */
        uint32 CH5OC      : 1;  /* [5]            r/w        */
        uint32 CH6OC      : 1;  /* [6]            r/w        */
        uint32 CH7OC      : 1;  /* [7]            r/w        */
        uint32 CH0OCV     : 1;  /* [8]            r/w        */
        uint32 CH1OCV     : 1;  /* [9]            r/w        */
        uint32 CH2OCV     : 1;  /* [10]           r/w        */
        uint32 CH3OCV     : 1;  /* [11]           r/w        */
        uint32 CH4OCV     : 1;  /* [12]           r/w        */
        uint32 CH5OCV     : 1;  /* [13]           r/w        */
        uint32 CH6OCV     : 1;  /* [14]           r/w        */
        uint32 CH7OCV     : 1;  /* [15]           r/w        */
        uint32 RSVD_31_16 : 16; /* [31:16]                   */
    } TIM_OUTSWCR;

    /* 0x60*/
    struct
    {
        uint32 FCTLEN0    : 1; /* [0]            r/w        */
        uint32 DTEN0      : 1; /* [1]            r/w        */
        uint32 COMB0      : 1; /* [2]            r/w        */
        uint32 SYNCEN0    : 1; /* [3]            r/w        */
        uint32 DECAPEN0   : 1; /* [4]            r/w        */
        uint32 DECAP0     : 1; /* [5]            r/w        */
        uint32 RSVD_7_6   : 2; /* [7:6]                     */
        uint32 FCTLEN1    : 1; /* [8]            r/w        */
        uint32 DTEN1      : 1; /* [9]            r/w        */
        uint32 COMB1      : 1; /* [10]           r/w        */
        uint32 SYNCEN1    : 1; /* [11]           r/w        */
        uint32 DECAPEN1   : 1; /* [12]           r/w        */
        uint32 DECAP1     : 1; /* [13]           r/w        */
        uint32 RSVD_15_14 : 2; /* [15:14]                   */
        uint32 FCTLEN2    : 1; /* [16]           r/w        */
        uint32 DTEN2      : 1; /* [17]           r/w        */
        uint32 COMB2      : 1; /* [18]           r/w        */
        uint32 SYNCEN2    : 1; /* [19]           r/w        */
        uint32 DECAPEN2   : 1; /* [20]           r/w        */
        uint32 DECAP2     : 1; /* [21]           r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]                   */
        uint32 FCTLEN3    : 1; /* [24]           r/w        */
        uint32 DTEN3      : 1; /* [25]           r/w        */
        uint32 COMB3      : 1; /* [26]           r/w        */
        uint32 SYNCEN3    : 1; /* [27]           r/w        */
        uint32 DECAPEN3   : 1; /* [28]           r/w        */
        uint32 DECAP3     : 1; /* [29]           r/w        */
        uint32 RSVD_31_30 : 2; /* [31:30]                   */
    } TIM_PCR;

    /* 0x64*/
    struct
    {
        uint32 FILVAL0    : 4; /* [3:0]          r/w        */
        uint32 FILVAL1    : 4; /* [7:4]          r/w        */
        uint32 FILVAL2    : 4; /* [11:8]         r/w        */
        uint32 FILVAL3    : 4; /* [15:12]        r/w        */
        uint32 DTPS       : 2; /* [17:16]        r/w        */
        uint32 DTVAL      : 6; /* [23:18]        r/w        */
        uint32 RSVD_31_24 : 8; /* [31:24]                   */
    } TIM_FILTER;

    /* 0x68*/
    struct
    {
        uint32 FAULTEN0   : 1;  /* [0]            r/w        */
        uint32 FIFEN0     : 1;  /* [1]            r/w        */
        uint32 FLTPOL0    : 1;  /* [2]            r/w        */
        uint32 FAULTEN1   : 1;  /* [3]            r/w        */
        uint32 FIFEN1     : 1;  /* [4]            r/w        */
        uint32 FLTPOL1    : 1;  /* [5]            r/w        */
        uint32 FLTIE      : 1;  /* [6]            r/w        */
        uint32 FLTCEN     : 1;  /* [7]            r/w        */
        uint32 FLTCM      : 1;  /* [8]            r/w        */
        uint32 RSVD_10_9  : 2;  /* [10:9]                    */
        uint32 FIFVAL     : 4;  /* [14:11]        r/w        */
        uint32 FSTATE     : 1;  /* [15]           r/w        */
        uint32 RSVD_31_16 : 16; /* [31:16]                   */
    } TIM_FLTCR;

    /* 0x6C*/
    struct
    {
        uint32 FAULTF0   : 1;  /* [0]            r/o        */
        uint32 FAULTF1   : 1;  /* [1]            r/o        */
        uint32 RSVD_3_2  : 2;  /* [3:2]                     */
        uint32 FAULTF    : 1;  /* [4]            r/o        */
        uint32 FAULTIN   : 1;  /* [5]            r/o        */
        uint32 WPEN      : 1;  /* [6]            r/w        */
        uint32 RSVD_31_7 : 25; /* [31:7]                    */
    } TIM_FLTSR;

    /* 0x70*/
    struct
    {
        uint32 SWTRIG     : 1;  /* [0]            r/w        */
        uint32 RSVD_7_1   : 7;  /* [7:1]                     */
        uint32 SYNCINIT   : 1;  /* [8]            r/w        */
        uint32 SYNCOSWC   : 1;  /* [9]            r/w        */
        uint32 RSVD_17_10 : 8;  /* [17:10]                   */
        uint32 SWWRBUF    : 1;  /* [18]           r/w        */
        uint32 SWRSTCNT   : 1;  /* [19]           r/w        */
        uint32 RSVD_31_20 : 12; /* [31:20]                   */
    } TIM_SYNC;

    /* 0x74*/
    struct
    {
        uint32 CH0SEL     : 1;  /* [0]            r/w        */
        uint32 CH1SEL     : 1;  /* [1]            r/w        */
        uint32 CH2SEL     : 1;  /* [2]            r/w        */
        uint32 CH3SEL     : 1;  /* [3]            r/w        */
        uint32 CH4SEL     : 1;  /* [4]            r/w        */
        uint32 CH5SEL     : 1;  /* [5]            r/w        */
        uint32 CH6SEL     : 1;  /* [6]            r/w        */
        uint32 CH7SEL     : 1;  /* [7]            r/w        */
        uint32 LOADEN     : 1;  /* [8]            r/w        */
        uint32 RSVD_10_9  : 2;  /* [10:9]                    */
        uint32 HCSEL      : 1;  /* [11]           r/w        */
        uint32 RSVD_15_12 : 4;  /* [15:12]                   */
        uint32 LDFREQ     : 5;  /* [20:16]        r/w        */
        uint32 RSVD_31_21 : 11; /* [31:21]                   */
    } TIM_RELOAD;

    /* 0x78*/
    struct
    {
        uint32 HCV        : 16; /* [15:0]         r/w        */
        uint32 RSVD_31_16 : 16; /* [31:16]                   */
    } TIM_HCV;

}; /*tim*/

struct Reg_Tim_W
{
    /* 0x00*/
    uint32 TIM_TIMEBASE;
    /* 0x04*/
    uint32 TIM_CNT;
    /* 0x08*/
    uint32 TIM_CNTINIT;
    /* 0x0C*/
    uint32 TIM_MOD;
    /* 0x10*/
    uint32 TIM_GLBCR;
    /* 0x14*/
    uint32 TIM_GLBSR;
    /* 0x18*/
    uint32 TIM_CMCn[8];
    /* 0x38*/
    uint32 TIM_CCVn[8];
    /* 0x58*/
    uint32 TIM_OUTCR;
    /* 0x5C*/
    uint32 TIM_OUTSWCR;
    /* 0x60*/
    uint32 TIM_PCR;
    /* 0x64*/
    uint32 TIM_FILTER;
    /* 0x68*/
    uint32 TIM_FLTCR;
    /* 0x6C*/
    uint32 TIM_FLTSR;
    /* 0x70*/
    uint32 TIM_SYNC;
    /* 0x74*/
    uint32 TIM_RELOAD;
    /* 0x78*/
    uint32 TIM_HCV;
}; /*tim*/

typedef volatile struct Reg_Tim_Bf Reg_Tim_BfType;
typedef volatile struct Reg_Tim_W  Reg_Tim_WType;

struct Reg_Tmu_Bf
{
    /* 0x0*/
    struct
    {
        uint32 SEL        : 16; /* [15:0]         r/w        */
        uint32 EN         : 1;  /* [16]           r/w        */
        uint32 RSVD_30_17 : 14; /* [30:17]        ro         */
        uint32 LOCK       : 1;  /* [31]           r/w        */
    } TMU_CFGn[40];

}; /*tmu*/

struct Reg_Tmu_W
{
    /* 0x0*/
    uint32 TMU_CFGn[40];
}; /*tmu*/

typedef volatile struct Reg_Tmu_Bf Reg_Tmu_BfType;
typedef volatile struct Reg_Tmu_W  Reg_Tmu_WType;

struct Reg_Trng_Bf
{
    /* 0x0000*/
    uint32 zResverd0x0000;
    /* 0x0004*/
    uint32 zResverd0x0004;
    /* 0x0008*/
    struct
    {
        uint32 RD        : 1;  /* [0]            ro         */
        uint32 IN        : 1;  /* [1]            ro         */
        uint32 TA        : 1;  /* [2]            ro         */
        uint32 CA        : 1;  /* [3]            ro         */
        uint32 RSVD_31_4 : 28; /* [31:4]         ro         */
    } TRNG_STATUS;

    /* 0x000c*/
    struct
    {
        uint32 EN         : 1;  /* [0]            rw         */
        uint32 SM         : 1;  /* [1]            rw         */
        uint32 RSVD_3_2   : 2;  /* [3:2]          rw         */
        uint32 DEC        : 10; /* [13:4]         rw         */
        uint32 LP         : 5;  /* [18:14]        rw         */
        uint32 RSVD_31_19 : 13; /* [31:19]        rw         */
    } TRNG_CONFIG;

    /* 0x0010*/
    struct
    {
        uint32 GE        : 1;  /* [0]            wo         */
        uint32 IN        : 1;  /* [1]            wo         */
        uint32 HT        : 1;  /* [2]            wo         */
        uint32 UN        : 1;  /* [3]            wo         */
        uint32 RS        : 1;  /* [4]            wo         */
        uint32 AK        : 1;  /* [5]            wo         */
        uint32 RSVD_31_6 : 26; /* [31:6]         wo         */
    } CTR_DRBG_CONTROL;

    /* 0x0014*/
    struct
    {
        uint32 RS : 12; /* [11:0]         rw         */
        uint32 RP : 20; /* [31:12]        rw         */
    } CTR_DRBG_REQUEST_SIZE;

    /* 0x0018*/
    struct
    {
        uint32 RP : 32; /* [31:0]         rw         */
    } CTR_DRBG_CONFIG_1;

    /* 0x001c*/
    struct
    {
        uint32 HTP : 32; /* [31:0]         rw         */
    } CTR_DRBG_CONFIG_2;

    /* 0x0020*/
    struct
    {
        uint32 AL0       : 1;  /* [0]            ro         */
        uint32 AL1       : 1;  /* [1]            ro         */
        uint32 AL2       : 1;  /* [2]            ro         */
        uint32 AL3       : 1;  /* [3]            ro         */
        uint32 VA        : 1;  /* [4]            ro         */
        uint32 RSVD_31_5 : 27; /* [31:5]         ro         */
    } TRNG_ALARM;

    /* 0x0024*/
    struct
    {
        uint32 AL0       : 1;  /* [0]            ro         */
        uint32 AL1       : 1;  /* [1]            ro         */
        uint32 AL2       : 1;  /* [2]            ro         */
        uint32 VA        : 1;  /* [3]            ro         */
        uint32 RSVD_31_4 : 28; /* [31:4]         ro         */
    } CTR_DRBG_ALARM;

    /* 0x0028*/
    struct
    {
        uint32 FL        : 1;  /* [0]            wo         */
        uint32 RSVD_31_1 : 31; /* [31:1]         wo         */
    } TRNG_RAW_RANDOM_CONTROL;

    /* 0x002c*/
    struct
    {
        uint32 DATA       : 16; /* [15:0]         ro         */
        uint32 VA         : 1;  /* [16]           ro         */
        uint32 RSVD_31_17 : 15; /* [31:17]        ro         */
    } TRNG_RAW_RANDOM_DATA;

    /* 0x0030*/
    struct
    {
        uint32 DATA       : 16; /* [15:0]         ro         */
        uint32 VA         : 1;  /* [16]           ro         */
        uint32 RSVD_31_17 : 15; /* [31:17]        ro         */
    } CTR_DRBG_RANDOM_DATA;

    /* 0x0034*/
    struct
    {
        uint32 I0         : 1;  /* [0]            rw         */
        uint32 I1         : 1;  /* [1]            rw         */
        uint32 I2         : 1;  /* [2]            rw         */
        uint32 I3         : 1;  /* [3]            rw         */
        uint32 MC         : 1;  /* [4]            rw         */
        uint32 RE         : 1;  /* [5]            rw         */
        uint32 E0         : 1;  /* [6]            rw         */
        uint32 E1         : 1;  /* [7]            rw         */
        uint32 E2         : 1;  /* [8]            rw         */
        uint32 E3         : 1;  /* [9]            rw         */
        uint32 SE         : 1;  /* [10]           rw         */
        uint32 RSVD_31_11 : 21; /* [31:11]        rw         */
    } ADDITIONAL_CONFIG_0;

    /* 0x0038*/
    struct
    {
        uint32 AC1        : 11; /* [10:0]         rw         */
        uint32 RSVD_31_11 : 21; /* [31:11]        rw         */
    } ADDITIONAL_CONFIG_1;

    /* 0x003c*/
    struct
    {
        uint32 AC2 : 32; /* [31:0]         rw         */
    } ADDITIONAL_CONFIG_2;

    /* 0x0040*/
    struct
    {
        uint32 NS        : 1;  /* [0]            wo         */
        uint32 RSVD_31_1 : 31; /* [31:1]         wo         */
    } ADDITIONAL_MEAS_CONTROL;

    /* 0x0044*/
    struct
    {
        uint32 TIME : 30; /* [29:0]         rw         */
        uint32 SEL  : 2;  /* [31:30]        rw         */
    } ADDITIONAL_MEAS_CONFIG;

    /* 0x0048*/
    struct
    {
        uint32 RD        : 1;  /* [0]            ro         */
        uint32 OV        : 1;  /* [1]            ro         */
        uint32 RSVD_31_2 : 30; /* [31:2]         ro         */
    } ADDITIONAL_MEAS_STATUS;

    /* 0x004c*/
    struct
    {
        uint32 D0 : 32; /* [31:0]         ro         */
    } ADDITIONAL_MEAS_DATA_0;

    /* 0x0050*/
    struct
    {
        uint32 D1 : 32; /* [31:0]         ro         */
    } ADDITIONAL_MEAS_DATA_1;

    /* 0x0054*/
    struct
    {
        uint32 IS0       : 1;  /* [0]            ro         */
        uint32 IS1       : 1;  /* [1]            ro         */
        uint32 IS2       : 1;  /* [2]            ro         */
        uint32 IS3       : 1;  /* [3]            ro         */
        uint32 RSVD_31_4 : 28; /* [31:4]         ro         */
    } IRQ_STATUS;

    /* 0x0058*/
    struct
    {
        uint32 CL0       : 1;  /* [0]            wo         */
        uint32 CL1       : 1;  /* [1]            wo         */
        uint32 CL2       : 1;  /* [2]            wo         */
        uint32 CL3       : 1;  /* [3]            wo         */
        uint32 RSVD_31_4 : 28; /* [31:4]         wo         */
    } IRQ_CLEAR;

    /* 0x005c*/
    struct
    {
        uint32 E0        : 1;  /* [0]            rw         */
        uint32 E1        : 1;  /* [1]            rw         */
        uint32 E2        : 1;  /* [2]            rw         */
        uint32 E3        : 1;  /* [3]            rw         */
        uint32 RSVD_31_4 : 28; /* [31:4]         rw         */
    } IRQ_CONFIG;

    /* 0x0060*/
    struct
    {
        uint32 TIMEOUT : 32; /* [31:0]         rw         */
    } ERROR_CONFIG;

    /* 0x0064*/
    struct
    {
        uint32 ST        : 1;  /* [0]            wo         */
        uint32 RSVD_31_1 : 31; /* [31:1]         wo         */
    } ERROR_CONTROL;

    /* 0x0068*/
    struct
    {
        uint32 RD        : 1;  /* [0]            ro         */
        uint32 OV        : 1;  /* [1]            ro         */
        uint32 TR        : 1;  /* [2]            ro         */
        uint32 RSVD_31_3 : 29; /* [31:3]         ro         */
    } ERROR_STATUS;

    /* 0x006c*/
    struct
    {
        uint32 MO        : 1;  /* [0]            rw         */
        uint32 RSVD_31_1 : 31; /* [31:1]         rw         */
    } STATS_CONFIG;

    /* 0x0070*/
    struct
    {
        uint32 CL        : 1;  /* [0]            wo         */
        uint32 RSVD_31_1 : 31; /* [31:1]         wo         */
    } STATS_CONTROL;

    /* 0x0074*/
    struct
    {
        uint32 EV : 16; /* [15:0]         ro         */
        uint32 PA : 16; /* [31:16]        ro         */
    } STATS_DATA;

}; /*trng*/

struct Reg_Trng_W
{
    /* 0x0000*/
    uint32 zResverd0x0000;
    /* 0x0004*/
    uint32 zResverd0x0004;
    /* 0x0008*/
    uint32 TRNG_STATUS;
    /* 0x000c*/
    uint32 TRNG_CONFIG;
    /* 0x0010*/
    uint32 CTR_DRBG_CONTROL;
    /* 0x0014*/
    uint32 CTR_DRBG_REQUEST_SIZE;
    /* 0x0018*/
    uint32 CTR_DRBG_CONFIG_1;
    /* 0x001c*/
    uint32 CTR_DRBG_CONFIG_2;
    /* 0x0020*/
    uint32 TRNG_ALARM;
    /* 0x0024*/
    uint32 CTR_DRBG_ALARM;
    /* 0x0028*/
    uint32 TRNG_RAW_RANDOM_CONTROL;
    /* 0x002c*/
    uint32 TRNG_RAW_RANDOM_DATA;
    /* 0x0030*/
    uint32 CTR_DRBG_RANDOM_DATA;
    /* 0x0034*/
    uint32 ADDITIONAL_CONFIG_0;
    /* 0x0038*/
    uint32 ADDITIONAL_CONFIG_1;
    /* 0x003c*/
    uint32 ADDITIONAL_CONFIG_2;
    /* 0x0040*/
    uint32 ADDITIONAL_MEAS_CONTROL;
    /* 0x0044*/
    uint32 ADDITIONAL_MEAS_CONFIG;
    /* 0x0048*/
    uint32 ADDITIONAL_MEAS_STATUS;
    /* 0x004c*/
    uint32 ADDITIONAL_MEAS_DATA_0;
    /* 0x0050*/
    uint32 ADDITIONAL_MEAS_DATA_1;
    /* 0x0054*/
    uint32 IRQ_STATUS;
    /* 0x0058*/
    uint32 IRQ_CLEAR;
    /* 0x005c*/
    uint32 IRQ_CONFIG;
    /* 0x0060*/
    uint32 ERROR_CONFIG;
    /* 0x0064*/
    uint32 ERROR_CONTROL;
    /* 0x0068*/
    uint32 ERROR_STATUS;
    /* 0x006c*/
    uint32 STATS_CONFIG;
    /* 0x0070*/
    uint32 STATS_CONTROL;
    /* 0x0074*/
    uint32 STATS_DATA;
}; /*trng*/

typedef volatile struct Reg_Trng_Bf Reg_Trng_BfType;
typedef volatile struct Reg_Trng_W  Reg_Trng_WType;

struct Reg_Uart_Bf
{
    /* 0x0*/
    union {
        struct
        {
            uint32 RBR_LSB   : 8;  /* [7:0]          ro         */
            uint32 RBR_MSB   : 1;  /* [8]            ro         */
            uint32 RSVD_31_9 : 23; /* [31:9]                    */
        } UART_RBR;
        struct
        {
            uint32 THR_LSB   : 8;  /* [7:0]          wo         */
            uint32 THR_MSB   : 1;  /* [8]            wo         */
            uint32 RSVD_31_9 : 23; /* [31:9]                    */
        } UART_THR;
        struct
        {
            uint32 DL_L      : 8;  /* [7:0]          r/w        */
            uint32 RSVD_31_8 : 24; /* [31:8]                    */
        } UART_DLL;
    } UART_RBR_THR_DLL;

    /* 0x4*/
    union {
        struct
        {
            uint32 DL_H      : 8;  /* [7:0]          r/w        */
            uint32 RSVD_31_8 : 24; /* [31:8]                    */
        } UART_DLH;
        struct
        {
            uint32 ERBFI              : 1;  /* [0]            r/w        */
            uint32 ETBEI              : 1;  /* [1]            r/w        */
            uint32 ELSI               : 1;  /* [2]            r/w        */
            uint32 EDSSI              : 1;  /* [3]            r/w        */
            uint32 RSVD_6_4           : 3;  /* [6:4]          r/w        */
            uint32 PTIME              : 1;  /* [7]            r/w        */
            uint32 HEADER_DONE_INT_EN : 1;  /* [8]            r/w        */
            uint32 RSP_DONE_INT_EN    : 1;  /* [9]            r/w        */
            uint32 ASYNC_INT_EN       : 1;  /* [10]           r/w        */
            uint32 RSVD_31_11         : 21; /* [31:11]                   */
        } UART_IER;
    } UART_DLH_IER;

    /* 0x8*/
    union {
        struct
        {
            uint32 IID       : 4;  /* [3:0]          ro         */
            uint32 RSVD_5_4  : 2;  /* [5:4]                     */
            uint32 FIFOSE    : 2;  /* [7:6]          ro         */
            uint32 RSVD_31_8 : 24; /* [31:8]                    */
        } UART_IIR;
        struct
        {
            uint32 FIFOE     : 1;  /* [0]            wo         */
            uint32 RFIFOR    : 1;  /* [1]            wo         */
            uint32 XFIFOR    : 1;  /* [2]            wo         */
            uint32 RSVD_3    : 1;  /* [3]            wo         */
            uint32 TET       : 2;  /* [5:4]          wo         */
            uint32 RCVR      : 2;  /* [7:6]          wo         */
            uint32 RSVD_31_8 : 24; /* [31:8]                    */
        } UART_FCR;
    } UART_IIR_FCR;

    /* 0xC*/
    struct
    {
        uint32 DLS             : 2;  /* [1:0]          r/w        */
        uint32 STOP            : 1;  /* [2]            r/w        */
        uint32 PEN             : 1;  /* [3 ]            r/w        */
        uint32 EPS             : 1;  /* [4]            r/w        */
        uint32 RSVD_5          : 1;  /* [5 ]            r/w        */
        uint32 BC              : 1;  /* [6]            r/w        */
        uint32 DLAB            : 1;  /* [7]            r/w        */
        uint32 LBKEN           : 1;  /* [8]            r/w        */
        uint32 LBKM            : 5;  /* [13:9]         r/w        */
        uint32 IDLE_DET_LENGTH : 3;  /* [16:14]        r/w        */
        uint32 IDLE_DET_EN     : 1;  /* [17]           r/w        */
        uint32 AUTO_SYNC_EN    : 1;  /* [18]           r/w        */
        uint32 DEBUG_EN        : 1;  /* [19]           r/w        */
        uint32 RSVD_31_20      : 12; /* [31:20]                   */
    } UART_LCR;

    /* 0x10*/
    struct
    {
        uint32 RSVD_0    : 1;  /* [0]                       */
        uint32 RTS       : 1;  /* [1]            r/w        */
        uint32 RSVD_2    : 1;  /* [2]                       */
        uint32 RSVD_3    : 1;  /* [3 ]                       */
        uint32 LB        : 1;  /* [4]            r/w        */
        uint32 AFCE      : 1;  /* [5 ]            r/w        */
        uint32 RSVD_6    : 1;  /* [6]            r/w        */
        uint32 RSVD_31_7 : 25; /* [31:7]                    */
    } UART_AFCR;

    /* 0x14*/
    struct
    {
        uint32 DR               : 1;  /* [0]            ro         */
        uint32 OE               : 1;  /* [1]            ro         */
        uint32 PE               : 1;  /* [2]            ro         */
        uint32 FE               : 1;  /* [3 ]            ro         */
        uint32 BI               : 1;  /* [4]            ro         */
        uint32 THRE             : 1;  /* [5 ]            ro         */
        uint32 TEMT             : 1;  /* [6]            ro         */
        uint32 RFE              : 1;  /* [7]            ro         */
        uint32 ADDR_RCVD        : 1;  /* [8]            ro         */
        uint32 ASYNC_INT        : 1;  /* [9]            ro         */
        uint32 SYNC_FIELD_ERROR : 1;  /* [10]           ro         */
        uint32 PID_ERR          : 1;  /* [11]           ro         */
        uint32 CHECKSUM_ERROR   : 1;  /* [12]           ro         */
        uint32 TO_ERROR         : 1;  /* [13]           ro         */
        uint32 HEADER_OP_DONE   : 1;  /* [14]           ro         */
        uint32 RSP_OP_DONE      : 1;  /* [15]           ro         */
        uint32 RSVD_31_16       : 16; /* [31:16]                   */
    } UART_LSR;

    /* 0x18*/
    struct
    {
        uint32 RSVD_3_0  : 4;  /* [3:0]                     */
        uint32 CTS       : 1;  /* [4]            ro         */
        uint32 RSVD_31_5 : 27; /* [31:5]                    */
    } UART_MSR;

    uint8 zResverd0x01C[96]; /*pad 0x01C - 07B*/

    /* 0x7C*/
    struct
    {
        uint32 BUSY      : 1;  /* [0]            ro         */
        uint32 RSVD_31_1 : 31; /* [31:1]                    */
    } UART_USR;

    uint8 zResverd0x080[40]; /*pad 0x080 - 0A7*/

    /* 0xA8*/
    struct
    {
        uint32 RSVD_0    : 1;  /* [0]            wo         */
        uint32 RSVD_31_1 : 31; /* [31:1]                    */
    } UART_DMA_SA;

    uint8 zResverd0x0AC[20]; /*pad 0x0AC - 0BF*/

    /* 0xC0*/
    struct
    {
        uint32 FD        : 4;  /* [3:0]          r/w        */
        uint32 RSVD_31_4 : 28; /* [31:4]                    */
    } UART_FD;

    /* 0xC4*/
    struct
    {
        uint32 RAR       : 8;  /* [7:0]          r/w        */
        uint32 RSVD_31_8 : 24; /* [31:8]                    */
    } UART_RAR;

    /* 0xC8*/
    struct
    {
        uint32 TAR       : 8;  /* [7:0]          r/w        */
        uint32 RSVD_31_8 : 24; /* [31:8]                    */
    } UART_TAR;

    /* 0xCC*/
    struct
    {
        uint32 DLS_E          : 1;  /* [0]            r/w        */
        uint32 ADDR_MATCH     : 1;  /* [1]            r/w        */
        uint32 SEND_ADDR      : 1;  /* [2]            r/w        */
        uint32 TRANSMIST_MODE : 1;  /* [3]            r/w        */
        uint32 RSVD_31_4      : 28; /* [31:4]                    */
    } UART_LCR_EXT;

    uint8 zResverd0x0D0[48]; /*pad 0x0D0 - 0FF*/

    /* 0x100*/
    struct
    {
        uint32 LIN_MODE        : 1;  /* [0]            r/w        */
        uint32 MASTER_MODE     : 1;  /* [1]            r/w        */
        uint32 HEADER_OP_START : 1;  /* [2]            r/w        */
        uint32 RSP_OP_START    : 1;  /* [3 ]            r/w        */
        uint32 RSP_DIR         : 1;  /* [4]            r/w        */
        uint32 RSVD_31_5       : 27; /* [31:5]                    */
    } UART_LIN_CTL;

    /* 0x104*/
    struct
    {
        uint32 RSP_LENGTH : 4;  /* [3:0]          r/w        */
        uint32 RSVD_31_4  : 28; /* [31:4]                    */
    } UART_LIN_RSP_LENGTH;

    /* 0x108*/
    struct
    {
        uint32 PID       : 8;  /* [7:0]          r/w        */
        uint32 RSVD_31_8 : 24; /* [31:8]                    */
    } UART_LIN_PID_VALUE;

    /* 0x10C*/
    struct
    {
        uint32 CHECKSUM_TYPE : 1;  /* [0]            r/w        */
        uint32 RSVD_7_1      : 7;  /* [7:1]                     */
        uint32 RSVD_31_8     : 24; /* [31:8]                    */
    } UART_LIN_CHECKSUM;

    /* 0x110*/
    struct
    {
        uint32 LIN_DEL_LENGTH : 3;  /* [2:0]          r/w        */
        uint32 RSVD_31_3      : 29; /* [31:3]                    */
    } UART_LIN_DEL_LENGTH;

    /* 0x114*/
    struct
    {
        uint32 FID0       : 6; /* [5:0]          r/w        */
        uint32 RSVD_7_6   : 2; /* [7:6]                     */
        uint32 FID1       : 6; /* [13:8]         r/w        */
        uint32 RSVD_15_14 : 2; /* [15:14]                   */
        uint32 FID2       : 6; /* [21:16]        r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]                   */
        uint32 FID3       : 6; /* [29:24]        r/w        */
        uint32 RSVD_31_30 : 2; /* [31:30]                   */
    } UART_LIN_PID_FILTER_0;

    /* 0x118*/
    struct
    {
        uint32 FID4       : 6; /* [5:0]          r/w        */
        uint32 RSVD_7_6   : 2; /* [7:6]                     */
        uint32 FID5       : 6; /* [13:8]         r/w        */
        uint32 RSVD_15_14 : 2; /* [15:14]                   */
        uint32 FID6       : 6; /* [21:16]        r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]                   */
        uint32 FID7       : 6; /* [29:24]        r/w        */
        uint32 RSVD_31_30 : 2; /* [31:30]                   */
    } UART_LIN_PID_FILTER_1;

    /* 0x11c*/
    struct
    {
        uint32 FID8       : 6; /* [5:0]          r/w        */
        uint32 RSVD_7_6   : 2; /* [7:6]                     */
        uint32 FID9       : 6; /* [13:8]         r/w        */
        uint32 RSVD_15_14 : 2; /* [15:14]                   */
        uint32 FID10      : 6; /* [21:16]        r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]                   */
        uint32 FID11      : 6; /* [29:24]        r/w        */
        uint32 RSVD_31_30 : 2; /* [31:30]                   */
    } UART_LIN_PID_FILTER_2;

    /* 0x120*/
    struct
    {
        uint32 FID12      : 6; /* [5:0]          r/w        */
        uint32 RSVD_7_6   : 2; /* [7:6]                     */
        uint32 FID13      : 6; /* [13:8]         r/w        */
        uint32 RSVD_15_14 : 2; /* [15:14]                   */
        uint32 FID14      : 6; /* [21:16]        r/w        */
        uint32 RSVD_23_22 : 2; /* [23:22]                   */
        uint32 FID15      : 6; /* [29:24]        r/w        */
        uint32 RSVD_31_30 : 2; /* [31:30]                   */
    } UART_LIN_PID_FILTER_3;

    /* 0x124*/
    struct
    {
        uint32 FID_VAGUE : 6;  /* [5:0]          r/w        */
        uint32 RSVD_31_6 : 26; /* [31:6]                    */
    } UART_LIN_PID_FILTER_VAGUE;

    /* 0x128*/
    struct
    {
        uint32 FID_MASK       : 17; /* [16:0]         r/w        */
        uint32 FID_VAGUE_MASK : 6;  /* [22:17]        r/w        */
        uint32 LIN_FILTER_EN  : 1;  /* [23]           r/w        */
        uint32 RSVD_31_24     : 8;  /* [31:24]                   */
    } UART_LIN_PID_FILTER_CTRL;

}; /*uart*/

struct Reg_Uart_W
{
    /* 0x0*/
    union {
        uint32 UART_RBR;
        uint32 UART_THR;
        uint32 UART_DLL;
    } UART_RBR_THR_DLL;
    /* 0x4*/
    union {
        uint32 UART_DLH;
        uint32 UART_IER;
    } UART_DLH_IER;
    /* 0x8*/
    union {
        uint32 UART_IIR;
        uint32 UART_FCR;
    } UART_IIR_FCR;
    /* 0xC*/
    uint32 UART_LCR;
    /* 0x10*/
    uint32 UART_AFCR;
    /* 0x14*/
    uint32 UART_LSR;
    /* 0x18*/
    uint32 UART_MSR;
    uint8  zResverd0x01C[96]; /*pad 0x01C - 07B*/

    /* 0x7C*/
    uint32 UART_USR;
    uint8  zResverd0x080[40]; /*pad 0x080 - 0A7*/

    /* 0xA8*/
    uint32 UART_DMA_SA;
    uint8  zResverd0x0AC[20]; /*pad 0x0AC - 0BF*/

    /* 0xC0*/
    uint32 UART_FD;
    /* 0xC4*/
    uint32 UART_RAR;
    /* 0xC8*/
    uint32 UART_TAR;
    /* 0xCC*/
    uint32 UART_LCR_EXT;
    uint8  zResverd0x0D0[48]; /*pad 0x0D0 - 0FF*/

    /* 0x100*/
    uint32 UART_LIN_CTL;
    /* 0x104*/
    uint32 UART_LIN_RSP_LENGTH;
    /* 0x108*/
    uint32 UART_LIN_PID_VALUE;
    /* 0x10C*/
    uint32 UART_LIN_CHECKSUM;
    /* 0x110*/
    uint32 UART_LIN_DEL_LENGTH;
    /* 0x114*/
    uint32 UART_LIN_PID_FILTER_0;
    /* 0x118*/
    uint32 UART_LIN_PID_FILTER_1;
    /* 0x11c*/
    uint32 UART_LIN_PID_FILTER_2;
    /* 0x120*/
    uint32 UART_LIN_PID_FILTER_3;
    /* 0x124*/
    uint32 UART_LIN_PID_FILTER_VAGUE;
    /* 0x128*/
    uint32 UART_LIN_PID_FILTER_CTRL;
}; /*uart*/

typedef volatile struct Reg_Uart_Bf Reg_Uart_BfType;
typedef volatile struct Reg_Uart_W  Reg_Uart_WType;

struct Reg_Wdog_Bf
{
    /* 0x0*/
    uint32 zResverd0x0;
    /* 0x4*/
    struct
    {
        uint32 INT_PRESENT : 1;  /* [0]            ro         */
        uint32 RSVD_31_1   : 31; /* [31:1]         ro         */
    } WDOG_PARAM;

    /* 0x8*/
    struct
    {
        uint32 WDOGE      : 1; /* [0]            r/w        */
        uint32 DEBUGE     : 1; /* [1]            r/w        */
        uint32 WAITE      : 1; /* [2]            r/w        */
        uint32 STOPE      : 1; /* [3]            r/w        */
        uint32 INTE       : 1; /* [4]            r/w        */
        uint32 WINE       : 1; /* [5]            r/w        */
        uint32 CFGUA      : 1; /* [6]            r/w        */
        uint32 RSVD_7     : 1; /* [7]            ro         */
        uint32 CLKS       : 2; /* [9:8]          r/w        */
        uint32 RSVD_15_10 : 6; /* [15:10]        ro         */
        uint32 TSTM       : 3; /* [18:16]        r/w        */
        uint32 RSVD_23_19 : 5; /* [23:19]        ro         */
        uint32 CFGUF      : 1; /* [24]           ro         */
        uint32 UNLKF      : 1; /* [25]           ro         */
        uint32 INTF       : 1; /* [26]           r/w        */
        uint32 RSVD_31_27 : 5; /* [31:27]        ro         */
    } WDOG_CS;

    /* 0xC*/
    struct
    {
        uint32 TMO : 32; /* [31:0]         r/w        */
    } WDOG_TMO;

    /* 0x10*/
    struct
    {
        uint32 WIN : 32; /* [31:0]         r/w        */
    } WDOG_WIN;

    /* 0x14*/
    struct
    {
        uint32 CNT : 32; /* [31:0]         r/w        */
    } WDOG_CNT;

}; /*wdog*/

struct Reg_Wdog_W
{
    /* 0x0*/
    uint32 zResverd0x0;
    /* 0x4*/
    uint32 WDOG_PARAM;
    /* 0x8*/
    uint32 WDOG_CS;
    /* 0xC*/
    uint32 WDOG_TMO;
    /* 0x10*/
    uint32 WDOG_WIN;
    /* 0x14*/
    uint32 WDOG_CNT;
}; /*wdog*/

typedef volatile struct Reg_Wdog_Bf Reg_Wdog_BfType;
typedef volatile struct Reg_Wdog_W  Reg_Wdog_WType;

#endif /*Z20K144M_H*/
