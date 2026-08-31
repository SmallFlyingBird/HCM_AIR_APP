/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           :
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
*
*   YUNTU Confidential. This software is owned or controlled by YUNTU and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef INTCTRL_LLD_TYPESDEF_H_
#define INTCTRL_LLD_TYPESDEF_H_

/**
*   @file
*
*   @addtogroup IntCtrl_Lld
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
#include "IntCtrl_Lld_CfgDefines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PLATFORM_INTCTRL_LLD_TYPESDEF_TYPES_VENDOR_ID                    (180)
#define PLATFORM_INTCTRL_LLD_TYPESDEF_SW_MAJOR_VERSION                   (2)
#define PLATFORM_INTCTRL_LLD_TYPESDEF_SW_MINOR_VERSION                   (3)
#define PLATFORM_INTCTRL_LLD_TYPESDEF_SW_PATCH_VERSION                   (0)

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

#if defined(CPU_YTM32B1ME0)

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 208u          /**< Number of interrupts in the Vector table */

/**
 * @brief Defines the Interrupt Numbers definitions
 *
 * This enumeration is used to configure the interrupts.
 *
 * Implements : IRQn_Type_Class
 */
typedef enum
{
    /* Auxiliary constants */
    NotAvail_IRQn     = -128,                /**< Not available device specific interrupt */

    /* Core interrupts */
    NMI_IRQn                    =  -14,                /**< NMI Interrupt */
    HardFault_IRQn              =  -13,                /**< HardFault Interrupt */
    MemManage_IRQn              =  -12,                /**< MemManage Interrupt */
    BusFault_IRQn               =  -11,                /**< BusFault Interrupt */
    UsageFault_IRQn             =  -10,                /**< UsageFault Interrupt */
    SVC_IRQn                    =   -5,                /**< SVC Interrupt */
    DebugMon_IRQn               =   -4,                /**< DebugMon Interrupt */
    PendSV_IRQn                 =   -2,                /**< PendSV Interrupt */
    SysTick_IRQn                =   -1,                /**< SysTick Interrupt */
    /* Device specific interrupts */
    DMA0_IRQn                   =    0,                /**< DMA0 Interrupt */
    DMA1_IRQn                   =    1,                /**< DMA1 Interrupt */
    DMA2_IRQn                   =    2,                /**< DMA2 Interrupt */
    DMA3_IRQn                   =    3,                /**< DMA3 Interrupt */
    DMA4_IRQn                   =    4,                /**< DMA4 Interrupt */
    DMA5_IRQn                   =    5,                /**< DMA5 Interrupt */
    DMA6_IRQn                   =    6,                /**< DMA6 Interrupt */
    DMA7_IRQn                   =    7,                /**< DMA7 Interrupt */
    DMA8_IRQn                   =    8,                /**< DMA8 Interrupt */
    DMA9_IRQn                   =    9,                /**< DMA9 Interrupt */
    DMA10_IRQn                  =   10,                /**< DMA10 Interrupt */
    DMA11_IRQn                  =   11,                /**< DMA11 Interrupt */
    DMA12_IRQn                  =   12,                /**< DMA12 Interrupt */
    DMA13_IRQn                  =   13,                /**< DMA13 Interrupt */
    DMA14_IRQn                  =   14,                /**< DMA14 Interrupt */
    DMA15_IRQn                  =   15,                /**< DMA15 Interrupt */
    DMA_Error_IRQn              =   16,                /**< DMA_Error Interrupt */
    FPU_IRQn                    =   17,                /**< FPU Interrupt */
    EFM_IRQn                    =   18,                /**< EFM Interrupt */
    EFM_Error_IRQn              =   19,                /**< EFM_Error Interrupt */
    PCU_IRQn                    =   20,                /**< PCU Interrupt */
    EFM_Ecc_IRQn                =   21,                /**< EFM_Ecc Interrupt */
    WDG_IRQn                    =   22,                /**< WDG Interrupt */
    RCU_IRQn                    =   23,                /**< RCU Interrupt */
    I2C0_Master_IRQn            =   24,                /**< I2C0_Master Interrupt */
    I2C0_Slave_IRQn             =   25,                /**< I2C0_Slave Interrupt */
    SPI0_IRQn                   =   26,                /**< SPI0 Interrupt */
    SPI1_IRQn                   =   27,                /**< SPI1 Interrupt */
    SPI2_IRQn                   =   28,                /**< SPI2 Interrupt */
    I2C1_Master_IRQn            =   29,                /**< I2C1_Master Interrupt */
    I2C1_Slave_IRQn             =   30,                /**< I2C1_Slave Interrupt */
    LINFlexD0_IRQn              =   31,                /**< LINFlexD0 Interrupt */
    Reserved5_IRQn              =   32,                /**< Reserved5 Interrupt */
    LINFlexD1_IRQn              =   33,                /**< LINFlexD1 Interrupt */
    Reserved6_IRQn              =   34,                /**< Reserved6 Interrupt */
    LINFlexD2_IRQn              =   35,                /**< LINFlexD2 Interrupt */
    Reserved7_IRQn              =   36,                /**< Reserved7 Interrupt */
    Reserved8_IRQn              =   37,                /**< Reserved8 Interrupt */
    Reserved9_IRQn              =   38,                /**< Reserved9 Interrupt */
    ADC0_IRQn                   =   39,                /**< ADC0 Interrupt */
    ADC1_IRQn                   =   40,                /**< ADC1 Interrupt */
    ACMP0_IRQn                  =   41,                /**< ACMP0 Interrupt */
    Reserved10_IRQn             =   42,                /**< Reserved10 Interrupt */
    Reserved11_IRQn             =   43,                /**< Reserved11 Interrupt */
    EMU_IRQn                    =   44,                /**< EMU Interrupt */
    Reserved12_IRQn             =   45,                /**< Reserved12 Interrupt */
    RTC_IRQn                    =   46,                /**< RTC Interrupt */
    RTC_Seconds_IRQn            =   47,                /**< RTC_Seconds Interrupt */
    pTMR_Ch0_IRQn               =   48,                /**< pTMR_Ch0 Interrupt */
    pTMR_Ch1_IRQn               =   49,                /**< pTMR_Ch1 Interrupt */
    pTMR_Ch2_IRQn               =   50,                /**< pTMR_Ch2 Interrupt */
    pTMR_Ch3_IRQn               =   51,                /**< pTMR_Ch3 Interrupt */
    PTU0_IRQn                   =   52,                /**< PTU0 Interrupt */
    Reserved13_IRQn             =   53,                /**< Reserved13 Interrupt */
    Reserved14_IRQn             =   54,                /**< Reserved14 Interrupt */
    Reserved15_IRQn             =   55,                /**< Reserved15 Interrupt */
    Reserved16_IRQn             =   56,                /**< Reserved16 Interrupt */
    SCU_IRQn                    =   57,                /**< SCU Interrupt */
    lpTMR0_IRQn                 =   58,                /**< lpTMR0 Interrupt */
    GPIOA_IRQn                  =   59,                /**< GPIOA Interrupt */
    GPIOB_IRQn                  =   60,                /**< GPIOB Interrupt */
    GPIOC_IRQn                  =   61,                /**< GPIOC Interrupt */
    GPIOD_IRQn                  =   62,                /**< GPIOD Interrupt */
    GPIOE_IRQn                  =   63,                /**< GPIOE Interrupt */
    Reserved17_IRQn             =   64,                /**< Reserved17 Interrupt */
    Reserved18_IRQn             =   65,                /**< Reserved18 Interrupt */
    Reserved19_IRQn             =   66,                /**< Reserved19 Interrupt */
    Reserved20_IRQn             =   67,                /**< Reserved20 Interrupt */
    PTU1_IRQn                   =   68,                /**< PTU1 Interrupt */
    Reserved21_IRQn             =   69,                /**< Reserved21 Interrupt */
    Reserved22_IRQn             =   70,                /**< Reserved22 Interrupt */
    Reserved23_IRQn             =   71,                /**< Reserved23 Interrupt */
    Reserved24_IRQn             =   72,                /**< Reserved24 Interrupt */
    Reserved25_IRQn             =   73,                /**< Reserved25 Interrupt */
    Reserved26_IRQn             =   74,                /**< Reserved26 Interrupt */
    Reserved27_IRQn             =   75,                /**< Reserved27 Interrupt */
    Reserved28_IRQn             =   76,                /**< Reserved28 Interrupt */
    Reserved29_IRQn             =   77,                /**< Reserved29 Interrupt */
    CAN0_ORed_IRQn              =   78,                /**< CAN0_ORed Interrupt */
    CAN0_Error_IRQn             =   79,                /**< CAN0_Error Interrupt */
    CAN0_Wake_Up_IRQn           =   80,                /**< CAN0_Wake_Up Interrupt */
    CAN0_ORed_0_15_MB_IRQn      =   81,                /**< CAN0_ORed_0_15_MB Interrupt */
    CAN0_ORed_16_31_MB_IRQn     =   82,                /**< CAN0_ORed_16_31_MB Interrupt */
    CAN0_ORed_32_47_MB_IRQn     =   83,                /**< CAN0_ORed_32_47_MB Interrupt */
    CAN0_ORed_48_63_MB_IRQn     =   84,                /**< CAN0_ORed_48_63_MB Interrupt */
    CAN1_ORed_IRQn              =   85,                /**< CAN1_ORed Interrupt */
    CAN1_Error_IRQn             =   86,                /**< CAN1_Error Interrupt */
    CAN1_Wake_Up_IRQn           =   87,                /**< CAN1_Wake_Up Interrupt */
    CAN1_ORed_0_15_MB_IRQn      =   88,                /**< CAN1_ORed_0_15_MB Interrupt */
    CAN1_ORed_16_31_MB_IRQn     =   89,                /**< CAN1_ORed_16_31_MB Interrupt */
    CAN1_ORed_32_47_MB_IRQn     =   90,                /**< CAN1_ORed_32_47_MB Interrupt */
    CAN1_ORed_48_63_MB_IRQn     =   91,                /**< CAN1_ORed_48_63_MB Interrupt */
    CAN2_ORed_IRQn              =   92,                /**< CAN2_ORed Interrupt */
    CAN2_Error_IRQn             =   93,                /**< CAN2_Error Interrupt */
    CAN2_Wake_Up_IRQn           =   94,                /**< CAN2_Wake_Up Interrupt */
    CAN2_ORed_0_15_MB_IRQn      =   95,                /**< CAN2_ORed_0_15_MB Interrupt */
    CAN2_ORed_16_31_MB_IRQn     =   96,                /**< CAN2_ORed_16_31_MB Interrupt */
    CAN2_ORed_32_47_MB_IRQn     =   97,                /**< CAN2_ORed_32_47_MB Interrupt */
    CAN2_ORed_48_63_MB_IRQn     =   98,                /**< CAN2_ORed_48_63_MB Interrupt */
    eTMR0_Ch0_Ch1_IRQn          =   99,                /**< eTMR0_Ch0_Ch1 Interrupt */
    eTMR0_Ch2_Ch3_IRQn          =  100,                /**< eTMR0_Ch2_Ch3 Interrupt */
    eTMR0_Ch4_Ch5_IRQn          =  101,                /**< eTMR0_Ch4_Ch5 Interrupt */
    eTMR0_Ch6_Ch7_IRQn          =  102,                /**< eTMR0_Ch6_Ch7 Interrupt */
    eTMR0_Fault_IRQn            =  103,                /**< eTMR0_Fault Interrupt */
    eTMR0_Ovf_IRQn              =  104,                /**< eTMR0_Ovf Interrupt */
    eTMR1_Ch0_Ch1_IRQn          =  105,                /**< eTMR1_Ch0_Ch1 Interrupt */
    eTMR1_Ch2_Ch3_IRQn          =  106,                /**< eTMR1_Ch2_Ch3 Interrupt */
    eTMR1_Ch4_Ch5_IRQn          =  107,                /**< eTMR1_Ch4_Ch5 Interrupt */
    eTMR1_Ch6_Ch7_IRQn          =  108,                /**< eTMR1_Ch6_Ch7 Interrupt */
    eTMR1_Fault_IRQn            =  109,                /**< eTMR1_Fault Interrupt */
    eTMR1_Ovf_IRQn              =  110,                /**< eTMR1_Ovf Interrupt */
    eTMR2_Ch0_Ch1_IRQn          =  111,                /**< eTMR2_Ch0_Ch1 Interrupt */
    eTMR2_Ch2_Ch3_IRQn          =  112,                /**< eTMR2_Ch2_Ch3 Interrupt */
    eTMR2_Ch4_Ch5_IRQn          =  113,                /**< eTMR2_Ch4_Ch5 Interrupt */
    eTMR2_Ch6_Ch7_IRQn          =  114,                /**< eTMR2_Ch6_Ch7 Interrupt */
    eTMR2_Fault_IRQn            =  115,                /**< eTMR2_Fault Interrupt */
    eTMR2_Ovf_IRQn              =  116,                /**< eTMR2_Ovf Interrupt */
    eTMR3_Ch0_Ch1_IRQn          =  117,                /**< eTMR3_Ch0_Ch1 Interrupt */
    eTMR3_Ch2_Ch3_IRQn          =  118,                /**< eTMR3_Ch2_Ch3 Interrupt */
    eTMR3_Ch4_Ch5_IRQn          =  119,                /**< eTMR3_Ch4_Ch5 Interrupt */
    eTMR3_Ch6_Ch7_IRQn          =  120,                /**< eTMR3_Ch6_Ch7 Interrupt */
    eTMR3_Fault_IRQn            =  121,                /**< eTMR3_Fault Interrupt */
    eTMR3_Ovf_IRQn              =  122,                /**< eTMR3_Ovf Interrupt */
    eTMR4_Ch0_Ch1_IRQn          =  123,                /**< eTMR4_Ch0_Ch1 Interrupt */
    eTMR4_Ch2_Ch3_IRQn          =  124,                /**< eTMR4_Ch2_Ch3 Interrupt */
    eTMR4_Ch4_Ch5_IRQn          =  125,                /**< eTMR4_Ch4_Ch5 Interrupt */
    eTMR4_Ch6_Ch7_IRQn          =  126,                /**< eTMR4_Ch6_Ch7 Interrupt */
    eTMR4_Fault_IRQn            =  127,                /**< eTMR4_Fault Interrupt */
    eTMR4_Ovf_IRQn              =  128,                /**< eTMR4_Ovf Interrupt */
    eTMR5_Ch0_Ch1_IRQn          =  129,                /**< eTMR5_Ch0_Ch1 Interrupt */
    eTMR5_Ch2_Ch3_IRQn          =  130,                /**< eTMR5_Ch2_Ch3 Interrupt */
    eTMR5_Ch4_Ch5_IRQn          =  131,                /**< eTMR5_Ch4_Ch5 Interrupt */
    eTMR5_Ch6_Ch7_IRQn          =  132,                /**< eTMR5_Ch6_Ch7 Interrupt */
    eTMR5_Fault_IRQn            =  133,                /**< eTMR5_Fault Interrupt */
    eTMR5_Ovf_IRQn              =  134,                /**< eTMR5_Ovf Interrupt */
    Reserved30_IRQn             =  135,                /**< Reserved30 Interrupt */
    Reserved31_IRQn             =  136,                /**< Reserved31 Interrupt */
    Reserved32_IRQn             =  137,                /**< Reserved32 Interrupt */
    Reserved33_IRQn             =  138,                /**< Reserved33 Interrupt */
    Reserved34_IRQn             =  139,                /**< Reserved34 Interrupt */
    Reserved35_IRQn             =  140,                /**< Reserved35 Interrupt */
    Reserved36_IRQn             =  141,                /**< Reserved36 Interrupt */
    Reserved37_IRQn             =  142,                /**< Reserved37 Interrupt */
    Reserved38_IRQn             =  143,                /**< Reserved38 Interrupt */
    Reserved39_IRQn             =  144,                /**< Reserved39 Interrupt */
    Reserved40_IRQn             =  145,                /**< Reserved40 Interrupt */
    Reserved41_IRQn             =  146,                /**< Reserved41 Interrupt */
    Reserved42_IRQn             =  147,                /**< Reserved42 Interrupt */
    Reserved43_IRQn             =  148,                /**< Reserved43 Interrupt */
    Reserved44_IRQn             =  149,                /**< Reserved44 Interrupt */
    Reserved45_IRQn             =  150,                /**< Reserved45 Interrupt */
    Reserved46_IRQn             =  151,                /**< Reserved46 Interrupt */
    Reserved47_IRQn             =  152,                /**< Reserved47 Interrupt */
    Reserved48_IRQn             =  153,                /**< Reserved48 Interrupt */
    Reserved49_IRQn             =  154,                /**< Reserved49 Interrupt */
    Reserved50_IRQn             =  155,                /**< Reserved50 Interrupt */
    TRNG_IRQn                   =  156,                /**< TRNG Interrupt */
    HCU_IRQn                    =  157,                /**< HCU Interrupt */
    INTM_IRQn                   =  158,                /**< INTM Interrupt */
    TMR0_Ch0_IRQn               =  159,                /**< TMR0_Ch0 Interrupt */
    TMR0_Ch1_IRQn               =  160,                /**< TMR0_Ch1 Interrupt */
    TMR0_Ch2_IRQn               =  161,                /**< TMR0_Ch2 Interrupt */
    TMR0_Ch3_IRQn               =  162,                /**< TMR0_Ch3 Interrupt */
    LINFlexD3_IRQn              =  163,                /**< LINFlexD3 Interrupt */
    LINFlexD4_IRQn              =  164,                /**< LINFlexD4 Interrupt */
    LINFlexD5_IRQn              =  165,                /**< LINFlexD5 Interrupt */
    I2C2_Master_IRQn            =  166,                /**< I2C2_Master Interrupt */
    I2C2_Slave_IRQn             =  167,                /**< I2C2_Slave Interrupt */
    SPI3_IRQn                   =  168,                /**< SPI3 Interrupt */
    SPI4_IRQn                   =  169,                /**< SPI4 Interrupt */
    SPI5_IRQn                   =  170,                /**< SPI5 Interrupt */
    CAN3_ORed_IRQn              =  171,                /**< CAN3_ORed Interrupt */
    CAN3_Error_IRQn             =  172,                /**< CAN3_Error Interrupt */
    CAN3_Wake_Up_IRQn           =  173,                /**< CAN3_Wake_Up Interrupt */
    CAN3_ORed_0_15_MB_IRQn      =  174,                /**< CAN3_ORed_0_15_MB Interrupt */
    CAN3_ORed_16_31_MB_IRQn     =  175,                /**< CAN3_ORed_16_31_MB Interrupt */
    Reserved51_IRQn             =  176,                /**< Reserved51 Interrupt */
    Reserved52_IRQn             =  177,                /**< Reserved52 Interrupt */
    CAN4_ORed_IRQn              =  178,                /**< CAN4_ORed Interrupt */
    CAN4_Error_IRQn             =  179,                /**< CAN4_Error Interrupt */
    CAN4_Wake_Up_IRQn           =  180,                /**< CAN4_Wake_Up Interrupt */
    CAN4_ORed_0_15_MB_IRQn      =  181,                /**< CAN4_ORed_0_15_MB Interrupt */
    CAN4_ORed_16_31_MB_IRQn     =  182,                /**< CAN4_ORed_16_31_MB Interrupt */
    Reserved53_IRQn             =  183,                /**< Reserved53 Interrupt */
    Reserved54_IRQn             =  184,                /**< Reserved54 Interrupt */
    CAN5_ORed_IRQn              =  185,                /**< CAN5_ORed Interrupt */
    CAN5_Error_IRQn             =  186,                /**< CAN5_Error Interrupt */
    CAN5_Wake_Up_IRQn           =  187,                /**< CAN5_Wake_Up Interrupt */
    CAN5_ORed_0_15_MB_IRQn      =  188,                /**< CAN5_ORed_0_15_MB Interrupt */
    CAN5_ORed_16_31_MB_IRQn     =  189,                /**< CAN5_ORed_16_31_MB Interrupt */
    WKU_IRQn                    =  190                 /**< WKU Interrupt */
} IRQn_Type;

#elif (defined(CPU_YTM32B1MD1))
/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 208u          /**< Number of interrupts in the Vector table */

/**
 * @brief Defines the Interrupt Numbers definitions
 *
 * This enumeration is used to configure the interrupts.
 *
 * Implements : IRQn_Type_Class
 */
typedef enum
{
    /* Auxiliary constants */
    NotAvail_IRQn     = -128,                /**< Not available device specific interrupt */

    /* Core interrupts */
    NMI_IRQn                    =  -14,                /**< NMI Interrupt */
    HardFault_IRQn              =  -13,                /**< HardFault Interrupt */
    MemManage_IRQn              =  -12,                /**< MemManage Interrupt */
    BusFault_IRQn               =  -11,                /**< BusFault Interrupt */
    UsageFault_IRQn             =  -10,                /**< UsageFault Interrupt */
    SVC_IRQn                    =   -5,                /**< SVC Interrupt */
    DebugMon_IRQn               =   -4,                /**< DebugMon Interrupt */
    PendSV_IRQn                 =   -2,                /**< PendSV Interrupt */
    SysTick_IRQn                =   -1,                /**< SysTick Interrupt */
    /* Device specific interrupts */
    DMA0_IRQn                   =    0,                /**< DMA0 Interrupt */
    DMA1_IRQn                   =    1,                /**< DMA1 Interrupt */
    DMA2_IRQn                   =    2,                /**< DMA2 Interrupt */
    DMA3_IRQn                   =    3,                /**< DMA3 Interrupt */
    DMA4_IRQn                   =    4,                /**< DMA4 Interrupt */
    DMA5_IRQn                   =    5,                /**< DMA5 Interrupt */
    DMA6_IRQn                   =    6,                /**< DMA6 Interrupt */
    DMA7_IRQn                   =    7,                /**< DMA7 Interrupt */
    DMA8_IRQn                   =    8,                /**< DMA8 Interrupt */
    DMA9_IRQn                   =    9,                /**< DMA9 Interrupt */
    DMA10_IRQn                  =   10,                /**< DMA10 Interrupt */
    DMA11_IRQn                  =   11,                /**< DMA11 Interrupt */
    DMA12_IRQn                  =   12,                /**< DMA12 Interrupt */
    DMA13_IRQn                  =   13,                /**< DMA13 Interrupt */
    DMA14_IRQn                  =   14,                /**< DMA14 Interrupt */
    DMA15_IRQn                  =   15,                /**< DMA15 Interrupt */
    DMA_Error_IRQn              =   16,                /**< DMA_Error Interrupt */
    FPU_IRQn                    =   17,                /**< FPU Interrupt */
    EFM_IRQn                    =   18,                /**< EFM Interrupt */
    EFM_Error_IRQn              =   19,                /**< EFM_Error Interrupt */
    PCU_IRQn                    =   20,                /**< PCU Interrupt */
    EFM_Ecc_IRQn                =   21,                /**< EFM_Ecc Interrupt */
    WDG_IRQn                    =   22,                /**< WDG Interrupt */
    Reserved5_IRQn              =   23,                /**< Reserved5 Interrupt */
    I2C0_Master_IRQn            =   24,                /**< I2C0_Master Interrupt */
    I2C0_Slave_IRQn             =   25,                /**< I2C0_Slave Interrupt */
    SPI0_IRQn                   =   26,                /**< SPI0 Interrupt */
    SPI1_IRQn                   =   27,                /**< SPI1 Interrupt */
    SPI2_IRQn                   =   28,                /**< SPI2 Interrupt */
    I2C1_Master_IRQn            =   29,                /**< I2C1_Master Interrupt */
    Reserved6_IRQn              =   30,                /**< Reserved6 Interrupt */
    LINFlexD0_IRQn              =   31,                /**< LINFlexD0 Interrupt */
    Reserved7_IRQn              =   32,                /**< Reserved7 Interrupt */
    LINFlexD1_IRQn              =   33,                /**< LINFlexD1 Interrupt */
    Reserved8_IRQn              =   34,                /**< Reserved8 Interrupt */
    LINFlexD2_IRQn              =   35,                /**< LINFlexD2 Interrupt */
    Reserved9_IRQn              =   36,                /**< Reserved9 Interrupt */
    Reserved10_IRQn             =   37,                /**< Reserved10 Interrupt */
    Reserved11_IRQn             =   38,                /**< Reserved11 Interrupt */
    ADC0_IRQn                   =   39,                /**< ADC0 Interrupt */
    Reserved12_IRQn             =   40,                /**< Reserved12 Interrupt */
    ACMP0_IRQn                  =   41,                /**< ACMP0 Interrupt */
    Reserved13_IRQn             =   42,                /**< Reserved13 Interrupt */
    Reserved14_IRQn             =   43,                /**< Reserved14 Interrupt */
    EMU_SB_IRQn                 =   44,                /**< EMU_SB Interrupt */
    EMU_DB_IRQn                 =   45,                /**< EMU_DB Interrupt */
    RTC_IRQn                    =   46,                /**< RTC Interrupt */
    RTC_Seconds_IRQn            =   47,                /**< RTC_Seconds Interrupt */
    pTMR_Ch0_IRQn               =   48,                /**< pTMR_Ch0 Interrupt */
    pTMR_Ch1_IRQn               =   49,                /**< pTMR_Ch1 Interrupt */
    pTMR_Ch2_IRQn               =   50,                /**< pTMR_Ch2 Interrupt */
    pTMR_Ch3_IRQn               =   51,                /**< pTMR_Ch3 Interrupt */
    PTU0_IRQn                   =   52,                /**< PTU0 Interrupt */
    Reserved15_IRQn             =   53,                /**< Reserved15 Interrupt */
    Reserved16_IRQn             =   54,                /**< Reserved16 Interrupt */
    Reserved17_IRQn             =   55,                /**< Reserved17 Interrupt */
    Reserved18_IRQn             =   56,                /**< Reserved18 Interrupt */
    SCU_IRQn                    =   57,                /**< SCU Interrupt */
    lpTMR0_IRQn                 =   58,                /**< lpTMR0 Interrupt */
    GPIOA_IRQn                  =   59,                /**< GPIOA Interrupt */
    GPIOB_IRQn                  =   60,                /**< GPIOB Interrupt */
    GPIOC_IRQn                  =   61,                /**< GPIOC Interrupt */
    GPIOD_IRQn                  =   62,                /**< GPIOD Interrupt */
    GPIOE_IRQn                  =   63,                /**< GPIOE Interrupt */
    Reserved19_IRQn             =   64,                /**< Reserved19 Interrupt */
    Reserved20_IRQn             =   65,                /**< Reserved20 Interrupt */
    Reserved21_IRQn             =   66,                /**< Reserved21 Interrupt */
    Reserved22_IRQn             =   67,                /**< Reserved22 Interrupt */
    Reserved23_IRQn             =   68,                /**< Reserved23 Interrupt */
    Reserved24_IRQn             =   69,                /**< Reserved24 Interrupt */
    Reserved25_IRQn             =   70,                /**< Reserved25 Interrupt */
    Reserved26_IRQn             =   71,                /**< Reserved26 Interrupt */
    Reserved27_IRQn             =   72,                /**< Reserved27 Interrupt */
    Reserved28_IRQn             =   73,                /**< Reserved28 Interrupt */
    Reserved29_IRQn             =   74,                /**< Reserved29 Interrupt */
    Reserved30_IRQn             =   75,                /**< Reserved30 Interrupt */
    Reserved31_IRQn             =   76,                /**< Reserved31 Interrupt */
    Reserved32_IRQn             =   77,                /**< Reserved32 Interrupt */
    CAN0_ORed_IRQn              =   78,                /**< CAN0_ORed Interrupt */
    CAN0_Error_IRQn             =   79,                /**< CAN0_Error Interrupt */
    CAN0_Wake_Up_IRQn           =   80,                /**< CAN0_Wake_Up Interrupt */
    CAN0_ORed_0_15_MB_IRQn      =   81,                /**< CAN0_ORed_0_15_MB Interrupt */
    CAN0_ORed_16_31_MB_IRQn     =   82,                /**< CAN0_ORed_16_31_MB Interrupt */
    CAN0_ORed_32_47_MB_IRQn     =   83,                /**< CAN0_ORed_32_47_MB Interrupt */
    CAN0_ORed_48_63_MB_IRQn     =   84,                /**< CAN0_ORed_48_63_MB Interrupt */
    CAN1_ORed_IRQn              =   85,                /**< CAN1_ORed Interrupt */
    CAN1_Error_IRQn             =   86,                /**< CAN1_Error Interrupt */
    CAN1_Wake_Up_IRQn           =   87,                /**< CAN1_Wake_Up Interrupt */
    CAN1_ORed_0_15_MB_IRQn      =   88,                /**< CAN1_ORed_0_15_MB Interrupt */
    CAN1_ORed_16_31_MB_IRQn     =   89,                /**< CAN1_ORed_16_31_MB Interrupt */
    Reserved33_IRQn             =   90,                /**< Reserved33 Interrupt */
    Reserved34_IRQn             =   91,                /**< Reserved34 Interrupt */
    CAN2_ORed_IRQn              =   92,                /**< CAN2_ORed Interrupt */
    CAN2_Error_IRQn             =   93,                /**< CAN2_Error Interrupt */
    CAN2_Wake_Up_IRQn           =   94,                /**< CAN2_Wake_Up Interrupt */
    CAN2_ORed_0_15_MB_IRQn      =   95,                /**< CAN2_ORed_0_15_MB Interrupt */
    CAN2_ORed_16_31_MB_IRQn     =   96,                /**< CAN2_ORed_16_31_MB Interrupt */
    Reserved35_IRQn             =   97,                /**< Reserved35 Interrupt */
    Reserved36_IRQn             =   98,                /**< Reserved36 Interrupt */
    eTMR0_Ch0_Ch1_IRQn          =   99,                /**< eTMR0_Ch0_Ch1 Interrupt */
    eTMR0_Ch2_Ch3_IRQn          =  100,                /**< eTMR0_Ch2_Ch3 Interrupt */
    eTMR0_Ch4_Ch5_IRQn          =  101,                /**< eTMR0_Ch4_Ch5 Interrupt */
    eTMR0_Ch6_Ch7_IRQn          =  102,                /**< eTMR0_Ch6_Ch7 Interrupt */
    eTMR0_Fault_IRQn            =  103,                /**< eTMR0_Fault Interrupt */
    eTMR0_Ovf_IRQn              =  104,                /**< eTMR0_Ovf Interrupt */
    eTMR1_Ch0_Ch1_IRQn          =  105,                /**< eTMR1_Ch0_Ch1 Interrupt */
    eTMR1_Ch2_Ch3_IRQn          =  106,                /**< eTMR1_Ch2_Ch3 Interrupt */
    eTMR1_Ch4_Ch5_IRQn          =  107,                /**< eTMR1_Ch4_Ch5 Interrupt */
    eTMR1_Ch6_Ch7_IRQn          =  108,                /**< eTMR1_Ch6_Ch7 Interrupt */
    eTMR1_Fault_IRQn            =  109,                /**< eTMR1_Fault Interrupt */
    eTMR1_Ovf_IRQn              =  110,                /**< eTMR1_Ovf Interrupt */
    eTMR2_Ch0_Ch1_IRQn          =  111,                /**< eTMR2_Ch0_Ch1 Interrupt */
    eTMR2_Ch2_Ch3_IRQn          =  112,                /**< eTMR2_Ch2_Ch3 Interrupt */
    eTMR2_Ch4_Ch5_IRQn          =  113,                /**< eTMR2_Ch4_Ch5 Interrupt */
    eTMR2_Ch6_Ch7_IRQn          =  114,                /**< eTMR2_Ch6_Ch7 Interrupt */
    eTMR2_Fault_IRQn            =  115,                /**< eTMR2_Fault Interrupt */
    eTMR2_Ovf_IRQn              =  116,                /**< eTMR2_Ovf Interrupt */
    eTMR3_Ch0_Ch1_IRQn          =  117,                /**< eTMR3_Ch0_Ch1 Interrupt */
    eTMR3_Ch2_Ch3_IRQn          =  118,                /**< eTMR3_Ch2_Ch3 Interrupt */
    eTMR3_Ch4_Ch5_IRQn          =  119,                /**< eTMR3_Ch4_Ch5 Interrupt */
    eTMR3_Ch6_Ch7_IRQn          =  120,                /**< eTMR3_Ch6_Ch7 Interrupt */
    eTMR3_Fault_IRQn            =  121,                /**< eTMR3_Fault Interrupt */
    eTMR3_Ovf_IRQn              =  122,                /**< eTMR3_Ovf Interrupt */
    Reserved37_IRQn             =  123,                /**< Reserved37 Interrupt */
    Reserved38_IRQn             =  124,                /**< Reserved38 Interrupt */
    Reserved39_IRQn             =  125,                /**< Reserved39 Interrupt */
    Reserved40_IRQn             =  126,                /**< Reserved40 Interrupt */
    Reserved41_IRQn             =  127,                /**< Reserved41 Interrupt */
    Reserved42_IRQn             =  128,                /**< Reserved42 Interrupt */
    Reserved43_IRQn             =  129,                /**< Reserved43 Interrupt */
    Reserved44_IRQn             =  130,                /**< Reserved44 Interrupt */
    Reserved45_IRQn             =  131,                /**< Reserved45 Interrupt */
    Reserved46_IRQn             =  132,                /**< Reserved46 Interrupt */
    Reserved47_IRQn             =  133,                /**< Reserved47 Interrupt */
    Reserved48_IRQn             =  134,                /**< Reserved48 Interrupt */
    Reserved49_IRQn             =  135,                /**< Reserved49 Interrupt */
    Reserved50_IRQn             =  136,                /**< Reserved50 Interrupt */
    Reserved51_IRQn             =  137,                /**< Reserved51 Interrupt */
    Reserved52_IRQn             =  138,                /**< Reserved52 Interrupt */
    Reserved53_IRQn             =  139,                /**< Reserved53 Interrupt */
    Reserved54_IRQn             =  140,                /**< Reserved54 Interrupt */
    Reserved55_IRQn             =  141,                /**< Reserved55 Interrupt */
    Reserved56_IRQn             =  142,                /**< Reserved56 Interrupt */
    Reserved57_IRQn             =  143,                /**< Reserved57 Interrupt */
    Reserved58_IRQn             =  144,                /**< Reserved58 Interrupt */
    Reserved59_IRQn             =  145,                /**< Reserved59 Interrupt */
    Reserved60_IRQn             =  146,                /**< Reserved60 Interrupt */
    Reserved61_IRQn             =  147,                /**< Reserved61 Interrupt */
    Reserved62_IRQn             =  148,                /**< Reserved62 Interrupt */
    Reserved63_IRQn             =  149,                /**< Reserved63 Interrupt */
    Reserved64_IRQn             =  150,                /**< Reserved64 Interrupt */
    Reserved65_IRQn             =  151,                /**< Reserved65 Interrupt */
    Reserved66_IRQn             =  152,                /**< Reserved66 Interrupt */
    Reserved67_IRQn             =  153,                /**< Reserved67 Interrupt */
    Reserved68_IRQn             =  154,                /**< Reserved68 Interrupt */
    Reserved69_IRQn             =  155,                /**< Reserved69 Interrupt */
    TRNG_IRQn                   =  156,                /**< TRNG Interrupt */
    HCU_IRQn                    =  157,                /**< HCU Interrupt */
    Reserved70_IRQn             =  158,                /**< Reserved70 Interrupt */
    TMR0_Ch0_IRQn               =  159,                /**< TMR0_Ch0 Interrupt */
    TMR0_Ch1_IRQn               =  160,                /**< TMR0_Ch1 Interrupt */
    TMR0_Ch2_IRQn               =  161,                /**< TMR0_Ch2 Interrupt */
    TMR0_Ch3_IRQn               =  162,                /**< TMR0_Ch3 Interrupt */
    Reserved71_IRQn             =  163,                /**< Reserved71 Interrupt */
    Reserved72_IRQn             =  164,                /**< Reserved72 Interrupt */
    Reserved73_IRQn             =  165,                /**< Reserved73 Interrupt */
    Reserved74_IRQn             =  166,                /**< Reserved74 Interrupt */
    Reserved75_IRQn             =  167,                /**< Reserved75 Interrupt */
    SPI3_IRQn                   =  168,                /**< SPI3 Interrupt */
    Reserved76_IRQn             =  169,                /**< Reserved76 Interrupt */
    Reserved77_IRQn             =  170,                /**< Reserved77 Interrupt */
    Reserved78_IRQn             =  171,                /**< Reserved78 Interrupt */
    Reserved79_IRQn             =  172,                /**< Reserved79 Interrupt */
    Reserved80_IRQn             =  173,                /**< Reserved80 Interrupt */
    Reserved81_IRQn             =  174,                /**< Reserved81 Interrupt */
    Reserved82_IRQn             =  175,                /**< Reserved82 Interrupt */
    Reserved83_IRQn             =  176,                /**< Reserved83 Interrupt */
    Reserved84_IRQn             =  177,                /**< Reserved84 Interrupt */
    Reserved85_IRQn             =  178,                /**< Reserved85 Interrupt */
    Reserved86_IRQn             =  179,                /**< Reserved86 Interrupt */
    SENT0_IRQn                  =  180,                /**< SENT0 Interrupt */
    Reserved87_IRQn             =  181,                /**< Reserved87 Interrupt */
    Reserved88_IRQn             =  182,                /**< Reserved88 Interrupt */
    Reserved89_IRQn             =  183,                /**< Reserved89 Interrupt */
    Reserved90_IRQn             =  184,                /**< Reserved90 Interrupt */
    Reserved91_IRQn             =  185,                /**< Reserved91 Interrupt */
    Reserved92_IRQn             =  186,                /**< Reserved92 Interrupt */
    Reserved93_IRQn             =  187,                /**< Reserved93 Interrupt */
    Reserved94_IRQn             =  188,                /**< Reserved94 Interrupt */
    Reserved95_IRQn             =  189,                /**< Reserved95 Interrupt */
    WKU_IRQn                    =  190                 /**< WKU Interrupt */
} IRQn_Type;

#elif (defined(CPU_YTM32B1HA0))

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 245u          /**< Number of interrupts in the Vector table */

/**
 * @brief Defines the Interrupt Numbers definitions
 *
 * This enumeration is used to configure the interrupts.
 *
 * Implements : IRQn_Type_Class
 */
typedef enum
{
    /* Auxiliary constants */
    NotAvail_IRQn     = -128,                /**< Not available device specific interrupt */

    /* Core interrupts */
    NMI_IRQn                    =  -14,                /**< NMI Interrupt */
    HardFault_IRQn              =  -13,                /**< HardFault Interrupt */
    MemManage_IRQn              =  -12,                /**< MemManage Interrupt */
    BusFault_IRQn               =  -11,                /**< BusFault Interrupt */
    UsageFault_IRQn             =  -10,                /**< UsageFault Interrupt */
    SVC_IRQn                    =   -5,                /**< SVC Interrupt */
    DebugMon_IRQn               =   -4,                /**< DebugMon Interrupt */
    PendSV_IRQn                 =   -2,                /**< PendSV Interrupt */
    SysTick_IRQn                =   -1,                /**< SysTick Interrupt */
    /* Device specific interrupts */
    DMA0_IRQn                   =    0,                /**< DMA0 Interrupt */
    DMA1_IRQn                   =    1,                /**< DMA1 Interrupt */
    DMA2_IRQn                   =    2,                /**< DMA2 Interrupt */
    DMA3_IRQn                   =    3,                /**< DMA3 Interrupt */
    DMA4_IRQn                   =    4,                /**< DMA4 Interrupt */
    DMA5_IRQn                   =    5,                /**< DMA5 Interrupt */
    DMA6_IRQn                   =    6,                /**< DMA6 Interrupt */
    DMA7_IRQn                   =    7,                /**< DMA7 Interrupt */
    DMA8_IRQn                   =    8,                /**< DMA8 Interrupt */
    DMA9_IRQn                   =    9,                /**< DMA9 Interrupt */
    DMA10_IRQn                  =   10,                /**< DMA10 Interrupt */
    DMA11_IRQn                  =   11,                /**< DMA11 Interrupt */
    DMA12_IRQn                  =   12,                /**< DMA12 Interrupt */
    DMA13_IRQn                  =   13,                /**< DMA13 Interrupt */
    DMA14_IRQn                  =   14,                /**< DMA14 Interrupt */
    DMA15_IRQn                  =   15,                /**< DMA15 Interrupt */
    DMA16_IRQn                  =   16,                /**< DMA16 Interrupt */
    DMA17_IRQn                  =   17,                /**< DMA17 Interrupt */
    DMA18_IRQn                  =   18,                /**< DMA18 Interrupt */
    DMA19_IRQn                  =   19,                /**< DMA19 Interrupt */
    DMA20_IRQn                  =   20,                /**< DMA20 Interrupt */
    DMA21_IRQn                  =   21,                /**< DMA21 Interrupt */
    DMA22_IRQn                  =   22,                /**< DMA22 Interrupt */
    DMA23_IRQn                  =   23,                /**< DMA23 Interrupt */
    DMA24_IRQn                  =   24,                /**< DMA24 Interrupt */
    DMA25_IRQn                  =   25,                /**< DMA25 Interrupt */
    DMA26_IRQn                  =   26,                /**< DMA26 Interrupt */
    DMA27_IRQn                  =   27,                /**< DMA27 Interrupt */
    DMA28_IRQn                  =   28,                /**< DMA28 Interrupt */
    DMA29_IRQn                  =   29,                /**< DMA29 Interrupt */
    DMA30_IRQn                  =   30,                /**< DMA30 Interrupt */
    DMA31_IRQn                  =   31,                /**< DMA31 Interrupt */
    DMA_Error_IRQn              =   32,                /**< DMA_Error Interrupt */
    FPU_IRQn                    =   33,                /**< FPU Interrupt */
    EFM_IRQn                    =   34,                /**< EFM Interrupt */
    EFM_Error_IRQn              =   35,                /**< EFM_Error Interrupt */
    PCU_IRQn                    =   36,                /**< PCU Interrupt */
    EFM_Ecc_IRQn                =   37,                /**< EFM_Ecc Interrupt */
    WDG_IRQn                    =   38,                /**< WDG Interrupt */
    Reserved5_IRQn              =   39,                /**< Reserved5 Interrupt */
    I2C0_Master_Slave_IRQn      =   40,                /**< I2C0_Master_Slave Interrupt */
    SPI0_IRQn                   =   41,                /**< SPI0 Interrupt */
    SPI1_IRQn                   =   42,                /**< SPI1 Interrupt */
    SPI2_IRQn                   =   43,                /**< SPI2 Interrupt */
    I2C1_Master_Slave_IRQn      =   44,                /**< I2C1_Master_Slave Interrupt */
    LINFlexD0_IRQn              =   45,                /**< LINFlexD0 Interrupt */
    Reserved6_IRQn              =   46,                /**< Reserved6 Interrupt */
    LINFlexD1_IRQn              =   47,                /**< LINFlexD1 Interrupt */
    Reserved7_IRQn              =   48,                /**< Reserved7 Interrupt */
    LINFlexD2_IRQn              =   49,                /**< LINFlexD2 Interrupt */
    Reserved8_IRQn              =   50,                /**< Reserved8 Interrupt */
    QSPI_IRQn                   =   51,                /**< QSPI Interrupt */
    Reserved9_IRQn              =   52,                /**< Reserved9 Interrupt */
    ADC0_IRQn                   =   53,                /**< ADC0 Interrupt */
    ADC1_IRQn                   =   54,                /**< ADC1 Interrupt */
    ACMP0_IRQn                  =   55,                /**< ACMP0 Interrupt */
    ACMP1_IRQn                  =   56,                /**< ACMP1 Interrupt */
    Reserved10_IRQn             =   57,                /**< Reserved10 Interrupt */
    EMU_IRQn                    =   58,                /**< EMU Interrupt */
    Reserved11_IRQn             =   59,                /**< Reserved11 Interrupt */
    RTC_IRQn                    =   60,                /**< RTC Interrupt */
    RTC_Seconds_IRQn            =   61,                /**< RTC_Seconds Interrupt */
    pTMR0_Ch0_IRQn              =   62,                /**< pTMR0_Ch0 Interrupt */
    pTMR0_Ch1_IRQn              =   63,                /**< pTMR0_Ch1 Interrupt */
    pTMR0_Ch2_IRQn              =   64,                /**< pTMR0_Ch2 Interrupt */
    pTMR0_Ch3_IRQn              =   65,                /**< pTMR0_Ch3 Interrupt */
    PTU0_IRQn                   =   66,                /**< PTU0 Interrupt */
    pTMR1_Ch0_IRQn              =   67,                /**< pTMR1_Ch0 Interrupt */
    pTMR1_Ch1_IRQn              =   68,                /**< pTMR1_Ch1 Interrupt */
    pTMR1_Ch2_IRQn              =   69,                /**< pTMR1_Ch2 Interrupt */
    pTMR1_Ch3_IRQn              =   70,                /**< pTMR1_Ch3 Interrupt */
    SCU_IRQn                    =   71,                /**< SCU Interrupt */
    lpTMR0_IRQn                 =   72,                /**< lpTMR0 Interrupt */
    GPIOA_IRQn                  =   73,                /**< GPIOA Interrupt */
    GPIOB_IRQn                  =   74,                /**< GPIOB Interrupt */
    GPIOC_IRQn                  =   75,                /**< GPIOC Interrupt */
    GPIOD_IRQn                  =   76,                /**< GPIOD Interrupt */
    GPIOE_IRQn                  =   77,                /**< GPIOE Interrupt */
    Reserved12_IRQn             =   78,                /**< Reserved12 Interrupt */
    Reserved13_IRQn             =   79,                /**< Reserved13 Interrupt */
    Reserved14_IRQn             =   80,                /**< Reserved14 Interrupt */
    Reserved15_IRQn             =   81,                /**< Reserved15 Interrupt */
    PTU1_IRQn                   =   82,                /**< PTU1 Interrupt */
    Reserved16_IRQn             =   83,                /**< Reserved16 Interrupt */
    CAN0_ORed_BusOff_Warning_IRQn   =   84,            /**< CAN0_ORed_BusOff_Warning Interrupt */
    CAN0_Error_IRQn             =   85,                /**< CAN0_Error Interrupt */
    CAN0_Wake_Up_IRQn           =   86,                /**< CAN0_Wake_Up Interrupt */
    CAN0_ORed_0_15_MB_IRQn      =   87,                /**< CAN0_ORed_0_15_MB Interrupt */
    CAN0_ORed_16_31_MB_IRQn     =   88,                /**< CAN0_ORed_16_31_MB Interrupt */
    CAN0_ORed_32_47_MB_IRQn     =   89,                /**< CAN0_ORed_32_47_MB Interrupt */
    CAN0_ORed_48_63_MB_IRQn     =   90,                /**< CAN0_ORed_48_63_MB Interrupt */
    CAN0_ORed_64_79_MB_IRQn     =   91,                /**< CAN0_ORed_64_79_MB Interrupt */
    CAN0_ORed_80_95_MB_IRQn     =   92,                /**< CAN0_ORed_80_95_MB Interrupt */
    CAN0_ORed_96_111_MB_IRQn    =   93,                /**< CAN0_ORed_96_111_MB Interrupt */
    CAN0_ORed_112_127_MB_IRQn   =   94,                /**< CAN0_ORed_112_127_MB Interrupt */
    CAN1_ORed_BusOff_Warning_IRQn   =   95,            /**< CAN1_ORed_BusOff_Warning Interrupt */
    CAN1_Error_IRQn             =   96,                /**< CAN1_Error Interrupt */
    CAN1_Wake_Up_IRQn           =   97,                /**< CAN1_Wake_Up Interrupt */
    CAN1_ORed_0_15_MB_IRQn      =   98,                /**< CAN1_ORed_0_15_MB Interrupt */
    CAN1_ORed_16_31_MB_IRQn     =   99,                /**< CAN1_ORed_16_31_MB Interrupt */
    CAN1_ORed_32_47_MB_IRQn     =  100,                /**< CAN1_ORed_32_47_MB Interrupt */
    CAN1_ORed_48_63_MB_IRQn     =  101,                /**< CAN1_ORed_48_63_MB Interrupt */
    CAN1_ORed_64_79_MB_IRQn     =  102,                /**< CAN1_ORed_64_79_MB Interrupt */
    CAN1_ORed_80_95_MB_IRQn     =  103,                /**< CAN1_ORed_80_95_MB Interrupt */
    CAN1_ORed_96_111_MB_IRQn    =  104,                /**< CAN1_ORed_96_111_MB Interrupt */
    CAN1_ORed_112_127_MB_IRQn   =  105,                /**< CAN1_ORed_112_127_MB Interrupt */
    CAN2_ORed_BusOff_Warning_IRQn   =  106,            /**< CAN2_ORed_BusOff_Warning Interrupt */
    CAN2_Error_IRQn             =  107,                /**< CAN2_Error Interrupt */
    CAN2_Wake_Up_IRQn           =  108,                /**< CAN2_Wake_Up Interrupt */
    CAN2_ORed_0_15_MB_IRQn      =  109,                /**< CAN2_ORed_0_15_MB Interrupt */
    CAN2_ORed_16_31_MB_IRQn     =  110,                /**< CAN2_ORed_16_31_MB Interrupt */
    CAN2_ORed_32_47_MB_IRQn     =  111,                /**< CAN2_ORed_32_47_MB Interrupt */
    CAN2_ORed_48_63_MB_IRQn     =  112,                /**< CAN2_ORed_48_63_MB Interrupt */
    eTMR0_Ch0_Ch1_IRQn          =  113,                /**< eTMR0_Ch0_Ch1 Interrupt */
    eTMR0_Ch2_Ch3_IRQn          =  114,                /**< eTMR0_Ch2_Ch3 Interrupt */
    eTMR0_Ch4_Ch5_IRQn          =  115,                /**< eTMR0_Ch4_Ch5 Interrupt */
    eTMR0_Ch6_Ch7_IRQn          =  116,                /**< eTMR0_Ch6_Ch7 Interrupt */
    eTMR0_Fault_IRQn            =  117,                /**< eTMR0_Fault Interrupt */
    eTMR0_Ovf_IRQn              =  118,                /**< eTMR0_Ovf Interrupt */
    eTMR1_Ch0_Ch1_IRQn          =  119,                /**< eTMR1_Ch0_Ch1 Interrupt */
    eTMR1_Ch2_Ch3_IRQn          =  120,                /**< eTMR1_Ch2_Ch3 Interrupt */
    eTMR1_Ch4_Ch5_IRQn          =  121,                /**< eTMR1_Ch4_Ch5 Interrupt */
    eTMR1_Ch6_Ch7_IRQn          =  122,                /**< eTMR1_Ch6_Ch7 Interrupt */
    eTMR1_Fault_IRQn            =  123,                /**< eTMR1_Fault Interrupt */
    eTMR1_Ovf_IRQn              =  124,                /**< eTMR1_Ovf Interrupt */
    eTMR2_Ch0_Ch1_IRQn          =  125,                /**< eTMR2_Ch0_Ch1 Interrupt */
    eTMR2_Ch2_Ch3_IRQn          =  126,                /**< eTMR2_Ch2_Ch3 Interrupt */
    eTMR2_Ch4_Ch5_IRQn          =  127,                /**< eTMR2_Ch4_Ch5 Interrupt */
    eTMR2_Ch6_Ch7_IRQn          =  128,                /**< eTMR2_Ch6_Ch7 Interrupt */
    eTMR2_Fault_IRQn            =  129,                /**< eTMR2_Fault Interrupt */
    eTMR2_Ovf_IRQn              =  130,                /**< eTMR2_Ovf Interrupt */
    eTMR3_Ch0_Ch1_IRQn          =  131,                /**< eTMR3_Ch0_Ch1 Interrupt */
    eTMR3_Ch2_Ch3_IRQn          =  132,                /**< eTMR3_Ch2_Ch3 Interrupt */
    eTMR3_Ch4_Ch5_IRQn          =  133,                /**< eTMR3_Ch4_Ch5 Interrupt */
    eTMR3_Ch6_Ch7_IRQn          =  134,                /**< eTMR3_Ch6_Ch7 Interrupt */
    eTMR3_Fault_IRQn            =  135,                /**< eTMR3_Fault Interrupt */
    eTMR3_Ovf_IRQn              =  136,                /**< eTMR3_Ovf Interrupt */
    eTMR4_Ch0_Ch1_IRQn          =  137,                /**< eTMR4_Ch0_Ch1 Interrupt */
    eTMR4_Ch2_Ch3_IRQn          =  138,                /**< eTMR4_Ch2_Ch3 Interrupt */
    eTMR4_Ch4_Ch5_IRQn          =  139,                /**< eTMR4_Ch4_Ch5 Interrupt */
    eTMR4_Ch6_Ch7_IRQn          =  140,                /**< eTMR4_Ch6_Ch7 Interrupt */
    eTMR4_Fault_IRQn            =  141,                /**< eTMR4_Fault Interrupt */
    eTMR4_Ovf_IRQn              =  142,                /**< eTMR4_Ovf Interrupt */
    eTMR5_Ch0_Ch1_IRQn          =  143,                /**< eTMR5_Ch0_Ch1 Interrupt */
    eTMR5_Ch2_Ch3_IRQn          =  144,                /**< eTMR5_Ch2_Ch3 Interrupt */
    eTMR5_Ch4_Ch5_IRQn          =  145,                /**< eTMR5_Ch4_Ch5 Interrupt */
    eTMR5_Ch6_Ch7_IRQn          =  146,                /**< eTMR5_Ch6_Ch7 Interrupt */
    eTMR5_Fault_IRQn            =  147,                /**< eTMR5_Fault Interrupt */
    eTMR5_Ovf_IRQn              =  148,                /**< eTMR5_Ovf Interrupt */
    pTMR2_Ch0_IRQn              =  149,                /**< pTMR2_Ch0 Interrupt */
    pTMR2_Ch1_IRQn              =  150,                /**< pTMR2_Ch1 Interrupt */
    pTMR2_Ch2_IRQn              =  151,                /**< pTMR2_Ch2 Interrupt */
    pTMR2_Ch3_IRQn              =  152,                /**< pTMR2_Ch3 Interrupt */
    Reserved17_IRQn             =  153,                /**< Reserved17 Interrupt */
    Reserved18_IRQn             =  154,                /**< Reserved18 Interrupt */
    Reserved19_IRQn             =  155,                /**< Reserved19 Interrupt */
    Reserved20_IRQn             =  156,                /**< Reserved20 Interrupt */
    SENT0_IRQn                  =  157,                /**< SENT0 Interrupt */
    SENT1_IRQn                  =  158,                /**< SENT1 Interrupt */
    FMU_Alarm_IRQn              =  159,                /**< FMU_Alarm Interrupt */
    FMU_MISC_IRQn               =  160,                /**< FMU_MISC Interrupt */
    TRNG_IRQn                   =  161,                /**< TRNG Interrupt */
    HCU_IRQn                    =  162,                /**< HCU Interrupt */
    INTM_IRQn                   =  163,                /**< INTM Interrupt */
    TMR0_IRQn                   =  164,                /**< TMR0 Interrupt */
    LINFlexD3_IRQn              =  165,                /**< LINFlexD3 Interrupt */
    LINFlexD4_IRQn              =  166,                /**< LINFlexD4 Interrupt */
    LINFlexD5_IRQn              =  167,                /**< LINFlexD5 Interrupt */
    I2C2_Master_Slave_IRQn      =  168,                /**< I2C2_Master_Slave Interrupt */
    SPI3_IRQn                   =  169,                /**< SPI3 Interrupt */
    SPI4_IRQn                   =  170,                /**< SPI4 Interrupt */
    SPI5_IRQn                   =  171,                /**< SPI5 Interrupt */
    CAN3_ORed_BusOff_Warning_IRQn   =  172,            /**< CAN3_ORed_BusOff_Warning Interrupt */
    CAN3_Error_IRQn             =  173,                /**< CAN3_Error Interrupt */
    CAN3_Wake_Up_IRQn           =  174,                /**< CAN3_Wake_Up Interrupt */
    CAN3_ORed_0_15_MB_IRQn      =  175,                /**< CAN3_ORed_0_15_MB Interrupt */
    CAN3_ORed_16_31_MB_IRQn     =  176,                /**< CAN3_ORed_16_31_MB Interrupt */
    CAN3_ORed_32_47_MB_IRQn     =  177,                /**< CAN3_ORed_32_47_MB Interrupt */
    CAN3_ORed_48_63_MB_IRQn     =  178,                /**< CAN3_ORed_48_63_MB Interrupt */
    CAN4_ORed_BusOff_Warning_IRQn   =  179,            /**< CAN4_ORed_BusOff_Warning Interrupt */
    CAN4_Error_IRQn             =  180,                /**< CAN4_Error Interrupt */
    CAN4_Wake_Up_IRQn           =  181,                /**< CAN4_Wake_Up Interrupt */
    CAN4_ORed_0_15_MB_IRQn      =  182,                /**< CAN4_ORed_0_15_MB Interrupt */
    CAN4_ORed_16_31_MB_IRQn     =  183,                /**< CAN4_ORed_16_31_MB Interrupt */
    CAN4_ORed_32_47_MB_IRQn     =  184,                /**< CAN4_ORed_32_47_MB Interrupt */
    CAN4_ORed_48_63_MB_IRQn     =  185,                /**< CAN4_ORed_48_63_MB Interrupt */
    CAN5_ORed_BusOff_Warning_IRQn   =  186,            /**< CAN5_ORed_BusOff_Warning Interrupt */
    CAN5_Error_IRQn             =  187,                /**< CAN5_Error Interrupt */
    CAN5_Wake_Up_IRQn           =  188,                /**< CAN5_Wake_Up Interrupt */
    CAN5_ORed_0_15_MB_IRQn      =  189,                /**< CAN5_ORed_0_15_MB Interrupt */
    CAN5_ORed_16_31_MB_IRQn     =  190,                /**< CAN5_ORed_16_31_MB Interrupt */
    WKU_IRQn                    =  191,                /**< WKU Interrupt */
    LINFlexD6_IRQn              =  192,                /**< LINFlexD6 Interrupt */
    LINFlexD7_IRQn              =  193,                /**< LINFlexD7 Interrupt */
    LINFlexD8_IRQn              =  194,                /**< LINFlexD8 Interrupt */
    LINFlexD9_IRQn              =  195,                /**< LINFlexD9 Interrupt */
    SPI6_IRQn                   =  196,                /**< SPI6 Interrupt */
    SPI7_IRQn                   =  197,                /**< SPI7 Interrupt */
    I2C3_Master_Slave_IRQn      =  198,                /**< I2C3_Master_Slave Interrupt */
    I2C4_Master_Slave_IRQn      =  199,                /**< I2C4_Master_Slave Interrupt */
    Reserved21_IRQn             =  200,                /**< Reserved21 Interrupt */
    CAN6_ORed_BusOff_Warning_IRQn   =  201,            /**< CAN6_ORed_BusOff_Warning Interrupt */
    CAN6_Error_IRQn             =  202,                /**< CAN6_Error Interrupt */
    CAN6_Wake_Up_IRQn           =  203,                /**< CAN6_Wake_Up Interrupt */
    CAN6_ORed_0_15_MB_IRQn      =  204,                /**< CAN6_ORed_0_15_MB Interrupt */
    CAN6_ORed_16_31_MB_IRQn     =  205,                /**< CAN6_ORed_16_31_MB Interrupt */
    TMR1_IRQn                   =  206,                /**< TMR1 Interrupt */
    Reserved22_IRQn             =  207,                /**< Reserved22 Interrupt */
    CORE_CTI_IRQn               =  208,                /**< CORE_CTI Interrupt */
    Reserved23_IRQn             =  209,                /**< Reserved23 Interrupt */
    SAI0_IRQn                   =  210,                /**< SAI0 Interrupt */
    SAI1_IRQn                   =  211,                /**< SAI1 Interrupt */
    ENET_IRQn                   =  212,                /**< ENET Interrupt */
    ENET_TX_IRQn                =  213,                /**< ENET_TX Interrupt */
    ENET_RX_IRQn                =  214,                /**< ENET_RX Interrupt */
    ENET_ECC_IRQn               =  215,                /**< ENET_ECC Interrupt */
    Reserved24_IRQn             =  216,                /**< Reserved24 Interrupt */
    Reserved25_IRQn             =  217,                /**< Reserved25 Interrupt */
    CAN7_ORed_BusOff_Warning_IRQn   =  218,            /**< CAN7_ORed_BusOff_Warning Interrupt */
    CAN7_Error_IRQn             =  219,                /**< CAN7_Error Interrupt */
    CAN7_Wake_Up_IRQn           =  220,                /**< CAN7_Wake_Up Interrupt */
    CAN7_ORed_0_15_MB_IRQn      =  221,                /**< CAN7_ORed_0_15_MB Interrupt */
    CAN7_ORed_16_31_MB_IRQn     =  222,                /**< CAN7_ORed_16_31_MB Interrupt */
    MPWM0_Ch0_Ch7_IRQn          =  223,                /**< MPWM0_Ch0_Ch7 Interrupt */
    MPWM0_Ch8_Ch15_IRQn         =  224,                /**< MPWM0_Ch8_Ch15 Interrupt */
    MPWM1_Ch0_Ch7_IRQn          =  225,                /**< MPWM1_Ch0_Ch7 Interrupt */
    MPWM1_Ch8_Ch15_IRQn         =  226,                /**< MPWM1_Ch8_Ch15 Interrupt */
    MPWM2_Ch0_Ch7_IRQn          =  227,                /**< MPWM2_Ch0_Ch7 Interrupt */
    MPWM2_Ch8_Ch15_IRQn         =  228,                /**< MPWM2_Ch8_Ch15 Interrupt */
} IRQn_Type;

#elif (defined(CPU_YTM32B1MC0))

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 174u          /**< Number of interrupts in the Vector table */

/**
 * @brief Defines the Interrupt Numbers definitions
 *
 * This enumeration is used to configure the interrupts.
 *
 * Implements : IRQn_Type_Class
 */
typedef enum
{
    /* Auxiliary constants */
    NotAvail_IRQn     = -128,                /**< Not available device specific interrupt */

    /* Core interrupts */
    NMI_IRQn                    =  -14,                /**< NMI Interrupt */
    HardFault_IRQn              =  -13,                /**< HardFault Interrupt */
    MemManage_IRQn              =  -12,                /**< MemManage Interrupt */
    BusFault_IRQn               =  -11,                /**< BusFault Interrupt */
    UsageFault_IRQn             =  -10,                /**< UsageFault Interrupt */
    SVC_IRQn                    =   -5,                /**< SVC Interrupt */
    DebugMon_IRQn               =   -4,                /**< DebugMon Interrupt */
    PendSV_IRQn                 =   -2,                /**< PendSV Interrupt */
    SysTick_IRQn                =   -1,                /**< SysTick Interrupt */
    /* Device specific interrupts */
    DMA0_IRQn                   =    0,                /**< DMA0 Interrupt */
    DMA1_IRQn                   =    1,                /**< DMA1 Interrupt */
    DMA2_IRQn                   =    2,                /**< DMA2 Interrupt */
    DMA3_IRQn                   =    3,                /**< DMA3 Interrupt */
    Reserved5_IRQn              =    4,                /**< Reserved5 Interrupt */
    Reserved6_IRQn              =    5,                /**< Reserved6 Interrupt */
    Reserved7_IRQn              =    6,                /**< Reserved7 Interrupt */
    Reserved8_IRQn              =    7,                /**< Reserved8 Interrupt */
    Reserved9_IRQn              =    8,                /**< Reserved9 Interrupt */
    Reserved10_IRQn             =    9,                /**< Reserved10 Interrupt */
    Reserved11_IRQn             =   10,                /**< Reserved11 Interrupt */
    Reserved12_IRQn             =   11,                /**< Reserved12 Interrupt */
    Reserved13_IRQn             =   12,                /**< Reserved13 Interrupt */
    Reserved14_IRQn             =   13,                /**< Reserved14 Interrupt */
    Reserved15_IRQn             =   14,                /**< Reserved15 Interrupt */
    Reserved16_IRQn             =   15,                /**< Reserved16 Interrupt */
    DMA_Error_IRQn              =   16,                /**< DMA_Error Interrupt */
    Reserved17_IRQn             =   17,                /**< Reserved17 Interrupt */
    EFM_IRQn                    =   18,                /**< EFM Interrupt */
    EFM_Error_IRQn              =   19,                /**< EFM_Error Interrupt */
    PCU_IRQn                    =   20,                /**< PCU Interrupt */
    EFM_Ecc_IRQn                =   21,                /**< EFM_Ecc Interrupt */
    WDG_IRQn                    =   22,                /**< WDG Interrupt */
    Reserved18_IRQn             =   23,                /**< Reserved18 Interrupt */
    I2C0_Master_IRQn            =   24,                /**< I2C0_Master Interrupt */
    I2C0_Slave_IRQn             =   25,                /**< I2C0_Slave Interrupt */
    SPI0_IRQn                   =   26,                /**< SPI0 Interrupt */
    SPI1_IRQn                   =   27,                /**< SPI1 Interrupt */
    SPI2_IRQn                   =   28,                /**< SPI2 Interrupt */
    I2C1_Master_IRQn            =   29,                /**< I2C1_Master Interrupt */
    Reserved19_IRQn             =   30,                /**< Reserved19 Interrupt */
    UART0_IRQn                  =   31,                /**< UART0 Interrupt */
    Reserved20_IRQn             =   32,                /**< Reserved20 Interrupt */
    UART1_IRQn                  =   33,                /**< UART1 Interrupt */
    Reserved21_IRQn             =   34,                /**< Reserved21 Interrupt */
    UART2_IRQn                  =   35,                /**< UART2 Interrupt */
    Reserved22_IRQn             =   36,                /**< Reserved22 Interrupt */
    Reserved23_IRQn             =   37,                /**< Reserved23 Interrupt */
    Reserved24_IRQn             =   38,                /**< Reserved24 Interrupt */
    ADC0_IRQn                   =   39,                /**< ADC0 Interrupt */
    Reserved25_IRQn             =   40,                /**< Reserved25 Interrupt */
    ACMP0_IRQn                  =   41,                /**< ACMP0 Interrupt */
    Reserved26_IRQn             =   42,                /**< Reserved26 Interrupt */
    Reserved27_IRQn             =   43,                /**< Reserved27 Interrupt */
    EMU_SB_IRQn                 =   44,                /**< EMU_SB Interrupt */
    EMU_DB_IRQn                 =   45,                /**< EMU_DB Interrupt */
    Reserved28_IRQn             =   46,                /**< Reserved28 Interrupt */
    Reserved29_IRQn             =   47,                /**< Reserved29 Interrupt */
    pTMR_Ch0_IRQn               =   48,                /**< pTMR_Ch0 Interrupt */
    pTMR_Ch1_IRQn               =   49,                /**< pTMR_Ch1 Interrupt */
    pTMR_Ch2_IRQn               =   50,                /**< pTMR_Ch2 Interrupt */
    pTMR_Ch3_IRQn               =   51,                /**< pTMR_Ch3 Interrupt */
    Reserved30_IRQn             =   52,                /**< Reserved30 Interrupt */
    Reserved31_IRQn             =   53,                /**< Reserved31 Interrupt */
    Reserved32_IRQn             =   54,                /**< Reserved32 Interrupt */
    Reserved33_IRQn             =   55,                /**< Reserved33 Interrupt */
    Reserved34_IRQn             =   56,                /**< Reserved34 Interrupt */
    SCU_IRQn                    =   57,                /**< SCU Interrupt */
    lpTMR0_IRQn                 =   58,                /**< lpTMR0 Interrupt */
    GPIOA_IRQn                  =   59,                /**< GPIOA Interrupt */
    GPIOB_IRQn                  =   60,                /**< GPIOB Interrupt */
    GPIOC_IRQn                  =   61,                /**< GPIOC Interrupt */
    GPIOD_IRQn                  =   62,                /**< GPIOD Interrupt */
    GPIOE_IRQn                  =   63,                /**< GPIOE Interrupt */
    Reserved35_IRQn             =   64,                /**< Reserved35 Interrupt */
    Reserved36_IRQn             =   65,                /**< Reserved36 Interrupt */
    Reserved37_IRQn             =   66,                /**< Reserved37 Interrupt */
    Reserved38_IRQn             =   67,                /**< Reserved38 Interrupt */
    Reserved39_IRQn             =   68,                /**< Reserved39 Interrupt */
    Reserved40_IRQn             =   69,                /**< Reserved40 Interrupt */
    Reserved41_IRQn             =   70,                /**< Reserved41 Interrupt */
    Reserved42_IRQn             =   71,                /**< Reserved42 Interrupt */
    Reserved43_IRQn             =   72,                /**< Reserved43 Interrupt */
    Reserved44_IRQn             =   73,                /**< Reserved44 Interrupt */
    Reserved45_IRQn             =   74,                /**< Reserved45 Interrupt */
    Reserved46_IRQn             =   75,                /**< Reserved46 Interrupt */
    Reserved47_IRQn             =   76,                /**< Reserved47 Interrupt */
    Reserved48_IRQn             =   77,                /**< Reserved48 Interrupt */
    CAN0_ORed_IRQn              =   78,                /**< CAN0_ORed Interrupt */
    CAN0_Error_IRQn             =   79,                /**< CAN0_Error Interrupt */
    CAN0_Wake_Up_IRQn           =   80,                /**< CAN0_Wake_Up Interrupt */
    CAN0_ORed_0_15_MB_IRQn      =   81,                /**< CAN0_ORed_0_15_MB Interrupt */
    CAN0_ORed_16_31_MB_IRQn     =   82,                /**< CAN0_ORed_16_31_MB Interrupt */
    CAN0_ORed_32_47_MB_IRQn     =   83,                /**< CAN0_ORed_32_47_MB Interrupt */
    CAN0_ORed_48_63_MB_IRQn     =   84,                /**< CAN0_ORed_48_63_MB Interrupt */
    CAN1_ORed_IRQn              =   85,                /**< CAN1_ORed Interrupt */
    CAN1_Error_IRQn             =   86,                /**< CAN1_Error Interrupt */
    CAN1_Wake_Up_IRQn           =   87,                /**< CAN1_Wake_Up Interrupt */
    CAN1_ORed_0_15_MB_IRQn      =   88,                /**< CAN1_ORed_0_15_MB Interrupt */
    CAN1_ORed_16_31_MB_IRQn     =   89,                /**< CAN1_ORed_16_31_MB Interrupt */
    CAN1_ORed_32_47_MB_IRQn     =   90,                /**< CAN1_ORed_32_47_MB Interrupt */
    CAN1_ORed_48_63_MB_IRQn     =   91,                /**< CAN1_ORed_48_63_MB Interrupt */
    Reserved49_IRQn             =   92,                /**< Reserved49 Interrupt */
    Reserved50_IRQn             =   93,                /**< Reserved50 Interrupt */
    Reserved51_IRQn             =   94,                /**< Reserved51 Interrupt */
    Reserved52_IRQn             =   95,                /**< Reserved52 Interrupt */
    Reserved53_IRQn             =   96,                /**< Reserved53 Interrupt */
    Reserved54_IRQn             =   97,                /**< Reserved54 Interrupt */
    Reserved55_IRQn             =   98,                /**< Reserved55 Interrupt */
    eTMR0_Ch0_Ch1_IRQn          =   99,                /**< eTMR0_Ch0_Ch1 Interrupt */
    eTMR0_Ch2_Ch3_IRQn          =  100,                /**< eTMR0_Ch2_Ch3 Interrupt */
    eTMR0_Ch4_Ch5_IRQn          =  101,                /**< eTMR0_Ch4_Ch5 Interrupt */
    eTMR0_Ch6_Ch7_IRQn          =  102,                /**< eTMR0_Ch6_Ch7 Interrupt */
    eTMR0_Fault_IRQn            =  103,                /**< eTMR0_Fault Interrupt */
    eTMR0_Ovf_IRQn              =  104,                /**< eTMR0_Ovf Interrupt */
    eTMR1_Ch0_Ch1_IRQn          =  105,                /**< eTMR1_Ch0_Ch1 Interrupt */
    eTMR1_Ch2_Ch3_IRQn          =  106,                /**< eTMR1_Ch2_Ch3 Interrupt */
    eTMR1_Ch4_Ch5_IRQn          =  107,                /**< eTMR1_Ch4_Ch5 Interrupt */
    eTMR1_Ch6_Ch7_IRQn          =  108,                /**< eTMR1_Ch6_Ch7 Interrupt */
    eTMR1_Fault_IRQn            =  109,                /**< eTMR1_Fault Interrupt */
    eTMR1_Ovf_IRQn              =  110,                /**< eTMR1_Ovf Interrupt */
    Reserved56_IRQn             =  111,                /**< Reserved56 Interrupt */
    Reserved57_IRQn             =  112,                /**< Reserved57 Interrupt */
    Reserved58_IRQn             =  113,                /**< Reserved58 Interrupt */
    Reserved59_IRQn             =  114,                /**< Reserved59 Interrupt */
    Reserved60_IRQn             =  115,                /**< Reserved60 Interrupt */
    Reserved61_IRQn             =  116,                /**< Reserved61 Interrupt */
    Reserved62_IRQn             =  117,                /**< Reserved62 Interrupt */
    Reserved63_IRQn             =  118,                /**< Reserved63 Interrupt */
    Reserved64_IRQn             =  119,                /**< Reserved64 Interrupt */
    Reserved65_IRQn             =  120,                /**< Reserved65 Interrupt */
    Reserved66_IRQn             =  121,                /**< Reserved66 Interrupt */
    Reserved67_IRQn             =  122,                /**< Reserved67 Interrupt */
    Reserved68_IRQn             =  123,                /**< Reserved68 Interrupt */
    Reserved69_IRQn             =  124,                /**< Reserved69 Interrupt */
    Reserved70_IRQn             =  125,                /**< Reserved70 Interrupt */
    Reserved71_IRQn             =  126,                /**< Reserved71 Interrupt */
    Reserved72_IRQn             =  127,                /**< Reserved72 Interrupt */
    Reserved73_IRQn             =  128,                /**< Reserved73 Interrupt */
    Reserved74_IRQn             =  129,                /**< Reserved74 Interrupt */
    Reserved75_IRQn             =  130,                /**< Reserved75 Interrupt */
    Reserved76_IRQn             =  131,                /**< Reserved76 Interrupt */
    Reserved77_IRQn             =  132,                /**< Reserved77 Interrupt */
    Reserved78_IRQn             =  133,                /**< Reserved78 Interrupt */
    Reserved79_IRQn             =  134,                /**< Reserved79 Interrupt */
    MPWM0_Ch0_Ovf_IRQn          =  135,                /**< MPWM0_Ch0_Ovf Interrupt */
    MPWM0_Ch1_Ovf_IRQn          =  136,                /**< MPWM0_Ch1_Ovf Interrupt */
    MPWM0_Ch2_Ovf_IRQn          =  137,                /**< MPWM0_Ch2_Ovf Interrupt */
    MPWM0_Ch3_Ovf_IRQn          =  138,                /**< MPWM0_Ch3_Ovf Interrupt */
    MPWM0_Ch4_Ovf_IRQn          =  139,                /**< MPWM0_Ch4_Ovf Interrupt */
    MPWM0_Ch5_Ovf_IRQn          =  140,                /**< MPWM0_Ch5_Ovf Interrupt */
    MPWM0_Ch6_Ovf_IRQn          =  141,                /**< MPWM0_Ch6_Ovf Interrupt */
    MPWM0_Ch7_Ovf_IRQn          =  142,                /**< MPWM0_Ch7_Ovf Interrupt */
    MPWM0_Ch0_IRQn              =  143,                /**< MPWM0_Ch0 Interrupt */
    MPWM0_Ch1_IRQn              =  144,                /**< MPWM0_Ch1 Interrupt */
    MPWM0_Ch2_IRQn              =  145,                /**< MPWM0_Ch2 Interrupt */
    MPWM0_Ch3_IRQn              =  146,                /**< MPWM0_Ch3 Interrupt */
    MPWM0_Ch4_IRQn              =  147,                /**< MPWM0_Ch4 Interrupt */
    MPWM0_Ch5_IRQn              =  148,                /**< MPWM0_Ch5 Interrupt */
    MPWM0_Ch6_IRQn              =  149,                /**< MPWM0_Ch6 Interrupt */
    MPWM0_Ch7_IRQn              =  150,                /**< MPWM0_Ch7 Interrupt */
    Reserved80_IRQn             =  151,                /**< Reserved80 Interrupt */
    Reserved81_IRQn             =  152,                /**< Reserved81 Interrupt */
    Reserved82_IRQn             =  153,                /**< Reserved82 Interrupt */
    Reserved83_IRQn             =  154,                /**< Reserved83 Interrupt */
    Reserved84_IRQn             =  155,                /**< Reserved84 Interrupt */
    TRNG_IRQn                   =  156,                /**< TRNG Interrupt */
    HCU_IRQn                    =  157,                /**< HCU Interrupt */
} IRQn_Type;

#elif defined(UNIT_TEST)
/* void  for Tessy unit test */
typedef sint16 IRQn_Type;
#define DMA0_IRQn     0U
#define DMA1_IRQn     1U
#define DMA2_IRQn     2U
#define DMA3_IRQn     3U
#define WKU_IRQn      100U
#define NotAvail_IRQn 512U

#else
#error "Wrong MCU part number"
#endif /* end CPU check of IRQn_Type*/

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers YTM32B1MX */


/**
* @brief          Interrupt handler type.
* @implements     IntCtrl_Lld_IrqHandlerType_typedef
*/
typedef void (*IntCtrl_Lld_IrqHandlerType)(void);

/**
* @brief          Structure storing the routing and handler configuration for an interrupt request.
* @implements     IntCtrl_Lld_IrqRouteConfigType_typedef
*/
typedef struct
{
    /** @brief Interrupt number */
    IRQn_Type IrqNumber;
    /** @brief Target cores for the interrupt */
    uint8 TargetCores;
    /** @brief Interrupt handler */
    IntCtrl_Lld_IrqHandlerType Handler;
} IntCtrl_Lld_IrqRouteConfigType;

/**
* @brief          Structure storing the list of routing configurations for all configured interrupts.
* @implements     IntCtrl_Lld_GlobalRouteConfigType_typedef
*/
typedef struct
{
    /** @brief Number of configured interrupts */
    uint32 ConfigIrqCount;
    /** @brief List of interrupts configurations */
    const IntCtrl_Lld_IrqRouteConfigType *IrqConfig;
} IntCtrl_Lld_GlobalRouteConfigType;

/**
* @brief          Structure storing the state and priority configuration for an interrupt request.
* @implements     IntCtrl_Lld_IrqConfigType_typedef
*/
typedef struct
{
    /** @brief Interrupt number */
    IRQn_Type IrqNumber;
    /** @brief Interrupt state (enabled/disabled) */
    boolean IrqEnabled;
    /** @brief Interrupt priority */
    uint8 IrqPriority;
} IntCtrl_Lld_IrqConfigType;

/**
* @brief          Structure storing the list of state configurations for all configured interrupts.
* @implements     IntCtrl_Lld_CtrlConfigType_typedef
*/
typedef struct
{
    /** @brief Number of configured interrupts */
    uint32 ConfigIrqCount;
#if (INTCTRL_LLD_ENABLE_VTOR_CONFIG == STD_ON)
    /** @brief  Vector Table address */
    uint32 VectorTableAddress;
#endif /* INTCTRL_LLD_ENABLE_VTOR_CONFIG */
    /** @brief List of interrupts configurations */
    const IntCtrl_Lld_IrqConfigType *IrqConfig;
} IntCtrl_Lld_CtrlConfigType;

/**
* @brief          Enumeration listing the possible error codes returned by IntCtrl_Lld API.
* @implements     IntCtrl_Lld_StatusType_typedef
*/
typedef enum
{
    /** @brief Status SUCCESS */
    INTCTRL_LLD_STATUS_SUCCESS = 0U,
    /** @brief Status ERROR */
    INTCTRL_LLD_STATUS_ERROR   = 1U
} IntCtrl_Lld_StatusType;


#endif /* INTCTRL_LLD_TYPESDEF_H_ */


/** @} */

