/**************************************************************************************************/
/**
 * @file      : Interrupt_Drv_Cfg.c
 * @brief     : Intrrupt control driver configuration source file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup  Platform_Module
 *  @{
 */

/** @addtogroup Interrupt_Drv
 *  @brief Interrupt control driver configuration source file
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Interrupt_Drv.h"
/** @defgroup Public_MacroDefinition
 *  @{
 */
#define INTERRUPT_DRV_CFG_C_VENDOR_ID                   0x00B3U
#define INTERRUPT_DRV_CFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define INTERRUPT_DRV_CFG_C_AR_RELEASE_MINOR_VERSION    6U
#define INTERRUPT_DRV_CFG_C_AR_RELEASE_REVISION_VERSION 0U
#define INTERRUPT_DRV_CFG_C_SW_MAJOR_VERSION            1U
#define INTERRUPT_DRV_CFG_C_SW_MINOR_VERSION            2U
#define INTERRUPT_DRV_CFG_C_SW_PATCH_VERSION            1U

/* Check if current file and Interrupt_Drv.h are the same vendor */
#if (INTERRUPT_DRV_CFG_C_VENDOR_ID !=INTERRUPT_DRV_H_VENDOR_ID)
    #error "Vendor ID of Interrupt_Drv_Cfg.c and Interrupt_Drv.h are different"
#endif
/* Check if current file and Interrupt_Drv.h are the same Autosar version */
#if ((INTERRUPT_DRV_CFG_C_AR_RELEASE_MAJOR_VERSION    !=INTERRUPT_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
    (INTERRUPT_DRV_CFG_C_AR_RELEASE_MINOR_VERSION    !=INTERRUPT_DRV_H_AR_RELEASE_MINOR_VERSION) || \
    (INTERRUPT_DRV_CFG_C_AR_RELEASE_REVISION_VERSION !=INTERRUPT_DRV_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version of Interrupt_Drv_Cfg.c and Interrupt_Drv.h are different"
#endif
/* Check if current file and Interrupt_Drv.h are the same Software version */
#if ((INTERRUPT_DRV_CFG_C_SW_MAJOR_VERSION !=INTERRUPT_DRV_H_SW_MAJOR_VERSION) || \
    (INTERRUPT_DRV_CFG_C_SW_MINOR_VERSION !=INTERRUPT_DRV_H_SW_MINOR_VERSION) || \
    (INTERRUPT_DRV_CFG_C_SW_PATCH_VERSION !=INTERRUPT_DRV_H_SW_PATCH_VERSION) \
    )
    #error "Software Version of Interrupt_Drv_Cfg.c and Interrupt_Drv.h are different"
#endif

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */
#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

/**
 * @brief List of configurations for interrupts 
 */
static const Interrupt_Drv_IrqConfigType Interrupt_Drv_IrqConfigList[205] =
{
    {DMA_Ch0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {DMA_Ch1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {DMA_Ch2_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {DMA_Ch3_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {DMA_Ch4_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {DMA_Ch5_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {DMA_Ch6_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {DMA_Ch7_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {DMA_Ch8_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {DMA_Ch9_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {DMA_Ch10_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {DMA_Ch11_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {DMA_Ch12_IRQn, (boolean)TRUE, 0U, Dma_Drv_Ch12IrqHandler},
    {DMA_Ch13_IRQn, (boolean)TRUE, 0U, Dma_Drv_Ch13IrqHandler},
    {DMA_Ch14_IRQn, (boolean)TRUE, 0U, Dma_Drv_Ch14IrqHandler},
    {DMA_Ch15_IRQn, (boolean)TRUE, 0U, Dma_Drv_Ch15IrqHandler},
    {DMA_Err_IRQn, (boolean)TRUE, 0U, Dma_Drv_ErrIrqHandler},
    {FLASH_CmdComplete_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {FLASH_Ecc_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PMU_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {WDOG_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {EWDT_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SRMC_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {I2C0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {I2C1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SPI0_Txe_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SPI0_Txo_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SPI0_Rxf_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SPI0_Rxo_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SPI0_Rxu_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {Reserved30_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SPI1_Txe_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SPI1_Txo_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SPI1_Rxf_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SPI1_Rxo_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SPI1_Rxu_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {Reserved36_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SPI2_Txe_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SPI2_Txo_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SPI2_Rxf_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SPI2_Rxo_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SPI2_Rxu_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {Reserved42_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SPI3_Txe_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SPI3_Txo_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SPI3_Rxf_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SPI3_Rxo_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {SPI3_Rxu_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {Reserved48_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {UART0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {UART1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {UART2_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {UART3_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {UART4_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {UART5_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN0_BusOff_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN0_TxWarn_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN0_RxWarn_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN0_Err_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN0_ErrFd_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN0_PnWake_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN0_SelfWakeup_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN0_Ecc_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN0_Mb0To15_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN0_Mb16To31_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN0_Mb32To47_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN0_Mb48To63_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN1_BusOff_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN1_TxWarn_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN1_RxWarn_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN1_Err_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN1_ErrFd_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN1_PnWake_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN1_SelfWakeup_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN1_Ecc_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN1_Mb0To15_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN1_Mb16To31_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN1_Mb32To47_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN1_Mb48To63_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN2_BusOff_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN2_TxWarn_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN2_RxWarn_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN2_Err_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN2_ErrFd_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN2_PnWake_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN2_SelfWakeup_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN2_Ecc_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN2_Mb0To15_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN2_Mb16To31_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN2_Mb32To47_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN2_Mb48To63_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN3_BusOff_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN3_TxWarn_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN3_RxWarn_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN3_Err_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN3_ErrFd_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN3_PnWake_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN3_SelfWakeup_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN3_Ecc_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN3_Mb0To15_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN3_Mb16To31_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN3_Mb32To47_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN3_Mb48To63_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN4_BusOff_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN4_TxWarn_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN4_RxWarn_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN4_Err_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN4_ErrFd_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN4_PnWake_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN4_SelfWakeup_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN4_Ecc_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN4_Mb0To15_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN4_Mb16To31_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN4_Mb32To47_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN4_Mb48To63_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN5_BusOff_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN5_TxWarn_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN5_RxWarn_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN5_Err_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN5_ErrFd_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN5_PnWake_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN5_SelfWakeup_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN5_Ecc_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN5_Mb0To15_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN5_Mb16To31_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN5_Mb32To47_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN5_Mb48To63_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN6_BusOff_IRQn, (boolean)TRUE, 1U, Can_Drv_6_BusOffIrqHandler},
    {CAN6_TxWarn_IRQn, (boolean)TRUE, 1U, Can_Drv_6_TxWarnIrqHandler},
    {CAN6_RxWarn_IRQn, (boolean)TRUE, 1U, Can_Drv_6_RxWarnIrqHandler},
    {CAN6_Err_IRQn, (boolean)TRUE, 1U, Can_Drv_6_ErrIrqHandler},
    {CAN6_ErrFd_IRQn, (boolean)FALSE, 1U, undefined_handler},
    {CAN6_PnWake_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN6_SelfWakeup_IRQn, (boolean)TRUE, 1U, Can_Drv_6_SelfWakeupIrqHandler},
    {CAN6_Ecc_IRQn, (boolean)TRUE, 1U, Can_Drv_6_EccIrqHandler},
    {CAN6_Mb0To31_IRQn, (boolean)TRUE, 1U, Can_Drv_6_Mb0To31IrqHandler},
    {CAN6_Mb32To63_IRQn, (boolean)TRUE, 1U, Can_Drv_6_Mb32To63IrqHandler},
    {CAN6_Mb64To95_IRQn, (boolean)TRUE, 1U, Can_Drv_6_Mb64To95IrqHandler},
    {CAN6_Mb96To127_IRQn, (boolean)TRUE, 1U, Can_Drv_6_Mb96To127IrqHandler},
    {CAN7_BusOff_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN7_TxWarn_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN7_RxWarn_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN7_Err_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN7_ErrFd_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN7_PnWake_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN7_SelfWakeup_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN7_Ecc_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN7_Mb0To31_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN7_Mb32To63_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN7_Mb64To95_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CAN7_Mb96To127_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {Reserved151_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {Reserved152_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {Reserved153_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {TIM0_Ch_IRQn, (boolean)TRUE, 0U, Tim_Drv_0_ChIrqHandler},
    {TIM0_Fault_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {TIM0_Overflow_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {TIM0_Rlfl_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {TIM1_Ch_IRQn, (boolean)TRUE, 0U, Tim_Drv_1_ChIrqHandler},
    {TIM1_Fault_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {TIM1_Overflow_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {TIM1_Rlfl_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {TIM2_Ch_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {TIM2_Fault_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {TIM2_Overflow_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {TIM2_Rlfl_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {TIM3_Ch_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {TIM3_Fault_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {TIM3_Overflow_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {TIM3_Rlfl_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {TDG0_Tco_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {TDG0_Err_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {TDG1_Tco_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {TDG1_Err_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {I2S0_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {I2S1_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PORTA_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PORTB_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PORTC_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PORTD_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {PORTE_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {STIM_IRQn, (boolean)TRUE, 0U, Stim_Drv_IrqHandler},
    {RTC_Alarm_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {RTC_Second_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {AES_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {TRNG_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CMU0_IRQn, (boolean)TRUE, 0U, Cmu_Drv_0_IrqHandler},
    {CMU1_IRQn, (boolean)TRUE, 0U, Cmu_Drv_1_IrqHandler},
    {CMU2_IRQn, (boolean)TRUE, 0U, Cmu_Drv_2_IrqHandler},
    {SERU_ParityErr_IRQn, (boolean)TRUE, 0U, Seru_Drv_ParityErrIrqHandler},
    {SERU_ChErr_IRQn, (boolean)TRUE, 0U, Seru_Drv_ChErrIrqHandler},
    {SCC_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {MCPWM0_Ch_IRQn, (boolean)TRUE, 0U, Mcpwm_Drv_0_ChIrqHandler},
    {MCPWM0_Fault_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {MCPWM0_Overflow_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {MCPWM0_Rlfl_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {MCPWM1_Ch_IRQn, (boolean)TRUE, 0U, Mcpwm_Drv_1_ChIrqHandler},
    {MCPWM1_Fault_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {MCPWM1_Overflow_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {MCPWM1_Rlfl_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {ADC0_IRQn, (boolean)TRUE, 2U, Adc_Drv_0_IrqHandler},
    {ADC1_IRQn, (boolean)TRUE, 2U, Adc_Drv_1_IrqHandler},
    {CMP_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {FPU_Err_IRQn, (boolean)FALSE, 0U, undefined_handler},
    {CACHE_Err_IRQn, (boolean)FALSE, 0U, undefined_handler}
};


#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"
/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */
#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"


/**
 * @brief Configuration structure for interrupt controller 
 */
const Interrupt_Drv_ConfigType Interrupt_Drv_Config =
{
    205U,
    Interrupt_Drv_IrqConfigList
};

#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"
/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

/** @} end of group Private_VariableDefinition */

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
#ifdef __cplusplus
}
#endif

/** @} end of group Interrupt_Drv */

/** @} end of group Platform_Module */
