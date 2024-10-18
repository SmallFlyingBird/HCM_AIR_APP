/**************************************************************************************************/
/**
 * @file      : Mstp_Cfg.c
 * @brief     : AUTOSAR Mstp - Pre-Compile(PC) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup  Mstp_Module
 *  @{
 */

/** @addtogroup Mstp_Configuration
 *  @brief Mstp high level configuration
 *  @{
 */
#ifdef __cplusplus
extern "C"{
#endif
#include "Mstp.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

#define MSTP_CFG_C_VENDOR_ID                   0x00B3U
#define MSTP_CFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define MSTP_CFG_C_AR_RELEASE_MINOR_VERSION    6U
#define MSTP_CFG_C_AR_RELEASE_REVISION_VERSION 0U
#define MSTP_CFG_C_SW_MAJOR_VERSION            1U
#define MSTP_CFG_C_SW_MINOR_VERSION            1U
#define MSTP_CFG_C_SW_PATCH_VERSION            0U

/* Check if current file and Mstp.h file are of the same vendor */
#if (MSTP_CFG_C_VENDOR_ID != MSTP_VENDOR_ID)
    #error "Vendor ID of Mstp_Cfg.c and Mstp.h are different"
#endif

/* Check if current file and Mstp.h file are of the same Autosar version */
#if ((MSTP_CFG_C_AR_RELEASE_MAJOR_VERSION != MSTP_AR_RELEASE_MAJOR_VERSION) ||                     \
     (MSTP_CFG_C_AR_RELEASE_MINOR_VERSION != MSTP_AR_RELEASE_MINOR_VERSION) ||                     \
     (MSTP_CFG_C_AR_RELEASE_REVISION_VERSION != MSTP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Mstp_Cfg.c and Mstp.h are different"
#endif

/* Check if current file and Mstp.h file are of the same software version */
#if ((MSTP_CFG_C_SW_MAJOR_VERSION != MSTP_SW_MAJOR_VERSION) ||                                     \
     (MSTP_CFG_C_SW_MINOR_VERSION != MSTP_SW_MINOR_VERSION) ||                                     \
     (MSTP_CFG_C_SW_PATCH_VERSION != MSTP_SW_PATCH_VERSION))
    #error "Software Version of Mstp_Cfg.c and Mstp.h are different"
#endif

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

#define MSTP_START_SEC_CONFIG_DATA_PTR
#include "Mstp_MemMap.h"

/**
 *  @brief CRC Register
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following two lines of code also violate this rule with the same reason. */
Reg_Crc_BfType *const Mstp_CrcRegBfPtr = (Reg_Crc_BfType *)CRC_BASE_ADDR;
Reg_Crc_WType *const  Mstp_CrcRegWPtr = (Reg_Crc_WType *)CRC_BASE_ADDR;

/**
 *  @brief PARCC Register
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following two lines of code also violate this rule with the same reason. */
Reg_Parcc_BfType *const Mstp_ParccRegBfPtr = (Reg_Parcc_BfType *)PARCC_BASE_ADDR;
Reg_Parcc_WType *const  Mstp_ParccRegWPtr = (Reg_Parcc_WType *)PARCC_BASE_ADDR;

/* MISRA2012 Rule-11.4 violation: Cast between a pointer to object and an integral type,
no side effects forseen by violating this rule.
The following two lines of code also violate this rule with the same reason. */
Mstp_PeripheralCfgBfType *const Mstp_PeripheralRegBfPtr = (Mstp_PeripheralCfgBfType *)PARCC_BASE_ADDR;
Mstp_PeripheralCfgWType *const Mstp_PeripheralRegWPtr = (Mstp_PeripheralCfgWType *)PARCC_BASE_ADDR;

/**
 *  @brief SERU Register
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following two lines of code also violate this rule with the same reason. */
Reg_Seru_WType *const  Mstp_SeruRegWPtr = (Reg_Seru_WType *)SERU_BASE_ADDR;
Reg_Seru_BfType *const Mstp_SeruRegBfPtr = (Reg_Seru_BfType *)SERU_BASE_ADDR;

/**
 *  @brief EIRU Register
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following two lines of code also violate this rule with the same reason. */
Reg_Eiru_BfType *const Mstp_EiruRegBfPtr = (Reg_Eiru_BfType *)(EIRU_BASE_ADDR);
Reg_Eiru_WType *const  Mstp_EiruRegWPtr = (Reg_Eiru_WType *)(EIRU_BASE_ADDR);

/**
 *  @brief PMU Register
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following two lines of code also violate this rule with the same reason. */
Reg_Pmu_WType *const  Mstp_PmuRegWPtr = (Reg_Pmu_WType *)PMU_BASE_ADDR;
Reg_Pmu_BfType *const Mstp_PmuRegBfPtr = (Reg_Pmu_BfType *)PMU_BASE_ADDR;

/**
 *  @brief SRMC Register
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following two lines of code also violate this rule with the same reason. */
Reg_Srmc_WType *const Mstp_SrmcRegWPtr = (Reg_Srmc_WType *)SRMC_BASE_ADDR;

/**
 *  @brief SCC Register
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule. */
Reg_Scc_WType *const Mstp_SccRegWPtr = (Reg_Scc_WType *)SCC_BASE_ADDR;

/**
 *  @brief SCM Register
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following two lines of code also violate this rule with the same reason. */
Reg_Scm_WType *const  Mstp_ScmRegWPtr = (Reg_Scm_WType *)SCM_BASE_ADDR;
Reg_Scm_BfType *const Mstp_ScmRegBfPtr = (Reg_Scm_BfType *)SCM_BASE_ADDR;

/**
 *  @brief CMU Register
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following nine lines of code also violate this rule with the same reason. */
Reg_Cmu_WType *const Mstp_Cmu0RegWPtr = (Reg_Cmu_WType *)CMU0_BASE_ADDR;
Reg_Cmu_WType *const Mstp_Cmu1RegWPtr = (Reg_Cmu_WType *)CMU1_BASE_ADDR;
Reg_Cmu_WType *const Mstp_Cmu2RegWPtr = (Reg_Cmu_WType *)CMU2_BASE_ADDR;

Reg_Cmu_BfType *const Mstp_CmuRegBfPtr[3U] = {(Reg_Cmu_BfType *)CMU0_BASE_ADDR,
                                                   (Reg_Cmu_BfType *)CMU1_BASE_ADDR,
                                                   (Reg_Cmu_BfType *)CMU2_BASE_ADDR};
Reg_Cmu_WType *const  Mstp_CmuRegWPtr[3U] = {(Reg_Cmu_WType *)CMU0_BASE_ADDR,
                                                  (Reg_Cmu_WType *)CMU1_BASE_ADDR,
                                                  (Reg_Cmu_WType *)CMU2_BASE_ADDR};

/**
 *  @brief FLASHC Register
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following two lines of code also violate this rule with the same reason. */
Reg_Flash_BfType *const Mstp_FlashRegBfPtr = (Reg_Flash_BfType *)FLASHC_BASE_ADDR;
Reg_Flash_WType *const  Mstp_FlashRegWPtr = (Reg_Flash_WType *)FLASHC_BASE_ADDR;

/**
 *  @brief WDOG Register
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following two lines of code also violate this rule with the same reason. */
Reg_Wdog_BfType *const Mstp_WdogRegBfPtr = (Reg_Wdog_BfType *)WDOG_BASE_ADDR;
Reg_Wdog_WType *const  Mstp_WdogRegWPtr = (Reg_Wdog_WType *)WDOG_BASE_ADDR;

/**
 *  @brief EWDT Register
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following two lines of code also violate this rule with the same reason. */
Reg_Ewdt_BfType *const Mstp_EwdtRegBfPtr = (Reg_Ewdt_BfType *)EWDT_BASE_ADDR;
Reg_Ewdt_WType *const  Mstp_EwdtRegWPtr = (Reg_Ewdt_WType *)EWDT_BASE_ADDR;

/**
 *  @brief STIM Register
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following two lines of code also violate this rule with the same reason. */
Reg_Stim_BfType *const Mstp_StimRegBfPtr = (Reg_Stim_BfType *)STIM_BASE_ADDR;
Reg_Stim_WType *const  Mstp_StimRegWPtr = (Reg_Stim_WType *)STIM_BASE_ADDR;

/**
 *  @brief TIM0, TIM1, TIM2 TIM3 address array
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following eight lines of code also violate this rule with the same reason. */
Reg_Tim_BfType *const Mstp_TimRegBfPtr[4U] = {
    (Reg_Tim_BfType *)TIM0_BASE_ADDR, /* TIM0 base address */
    (Reg_Tim_BfType *)TIM1_BASE_ADDR, /* TIM1 base address */
    (Reg_Tim_BfType *)TIM2_BASE_ADDR, /* TIM2 base address */
    (Reg_Tim_BfType *)TIM3_BASE_ADDR  /* TIM3 base address */
};
Reg_Tim_WType *const Mstp_Tim0RegWPtr = (Reg_Tim_WType *)TIM0_BASE_ADDR;
Reg_Tim_WType *const Mstp_Tim1RegWPtr = (Reg_Tim_WType *)TIM1_BASE_ADDR;
Reg_Tim_WType *const Mstp_Tim2RegWPtr = (Reg_Tim_WType *)TIM2_BASE_ADDR;
Reg_Tim_WType *const Mstp_Tim3RegWPtr = (Reg_Tim_WType *)TIM3_BASE_ADDR;

/**
 *  @brief MCPWM peripheral (MCPWM0 MCPWM1) base address array
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following three lines of code also violate this rule with the same reason. */
Reg_Mcpwm_BfType *const Mstp_McpwmRegBfPtr[2U] = {(Reg_Mcpwm_BfType *)MCPWM0_BASE_ADDR,
                                                       (Reg_Mcpwm_BfType *)MCPWM1_BASE_ADDR};
Reg_Mcpwm_WType *const  Mstp_Mcpwm0RegWPtr = (Reg_Mcpwm_WType *)MCPWM0_BASE_ADDR;
Reg_Mcpwm_WType *const  Mstp_Mcpwm1RegWPtr = (Reg_Mcpwm_WType *)MCPWM1_BASE_ADDR;

/**
 *  @brief TDG peripheral (TDG0 TDG1) base address array
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following four lines of code also violate this rule with the same reason. */
Reg_Tdg_BfType *const Mstp_TdgRegBfPtr[2U] = {
    (Reg_Tdg_BfType *)TDG0_BASE_ADDR, /*!< TDG0 base address */
    (Reg_Tdg_BfType *)TDG1_BASE_ADDR  /*!< TDG1 base address */
};
Reg_Tdg_WType *const Mstp_Tdg0RegWPtr = (Reg_Tdg_WType *)TDG0_BASE_ADDR;
Reg_Tdg_WType *const Mstp_Tdg1RegWPtr = (Reg_Tdg_WType *)TDG1_BASE_ADDR;

/**
 *  @brief UART peripheral (UART0 ~ UART5) base address array
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following three lines of code also violate this rule with the same reason. */
Reg_Uart_BfType *const Mstp_UartRegBfPtr[6U] = {
    (Reg_Uart_BfType *)UART0_BASE_ADDR, (Reg_Uart_BfType *)UART1_BASE_ADDR,
    (Reg_Uart_BfType *)UART2_BASE_ADDR, (Reg_Uart_BfType *)UART3_BASE_ADDR,
    (Reg_Uart_BfType *)UART4_BASE_ADDR, (Reg_Uart_BfType *)UART5_BASE_ADDR,
};

/**
 *  @brief SPI peripheral (SPI0 SPI1 SPI2 SPI3) base address array
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following four lines of code also violate this rule with the same reason. */
Reg_Spi_BfType *const Mstp_SpiRegBfPtr[4U] = {
    (Reg_Spi_BfType *)SPI0_BASE_ADDR, /*!< SPI0 base address */
    (Reg_Spi_BfType *)SPI1_BASE_ADDR, /*!< SPI1 base address */
    (Reg_Spi_BfType *)SPI2_BASE_ADDR, /*!< SPI2 base address */
    (Reg_Spi_BfType *)SPI3_BASE_ADDR  /*!< SPI3 base address */
};

/**
 *  @brief I2C peripheral base address array
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following lines of code also violate this rule with the same reason. */
Reg_I2c_BfType *const Mstp_I2cRegBfPtr[2U] = {
        (Reg_I2c_BfType *)I2C0_BASE_ADDR, /*!< I2C0 base address */
        (Reg_I2c_BfType *)I2C1_BASE_ADDR  /*!< I2C1 base address */
};

#if (defined(DEV_Z20K148M))
/**
 *  @brief CAN peripheral base address array
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following lines of code also violate this rule with the same reason. */
Reg_Can_BfType *const Mstp_CanRegBfPtr[8U] = {
        (Reg_Can_BfType *)CAN0_BASE_ADDR, (Reg_Can_BfType *)CAN1_BASE_ADDR,
        (Reg_Can_BfType *)CAN2_BASE_ADDR, (Reg_Can_BfType *)CAN3_BASE_ADDR,
        (Reg_Can_BfType *)CAN4_BASE_ADDR, (Reg_Can_BfType *)CAN5_BASE_ADDR,
        (Reg_Can_BfType *)CAN6_BASE_ADDR, (Reg_Can_BfType *)CAN7_BASE_ADDR
}; 

/**
 *  @brief I2S peripheral base address array
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following lines of code also violate this rule with the same reason. */
Reg_I2s_BfType *const Mstp_I2sRegBfPtr[2U] = {
        (Reg_I2s_BfType *)I2S0_BASE_ADDR, /*!< I2S0 base address */
        (Reg_I2s_BfType *)I2S1_BASE_ADDR  /*!< I2S1 base address */
};
#elif (defined(DEV_Z20K146M))
/**
 *  @brief CAN peripheral base address array
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following lines of code also violate this rule with the same reason. */
Reg_Can_BfType *const Mstp_CanRegBfPtr[6U] = {
        (Reg_Can_BfType *)CAN0_BASE_ADDR, (Reg_Can_BfType *)CAN1_BASE_ADDR,
        (Reg_Can_BfType *)CAN2_BASE_ADDR, (Reg_Can_BfType *)CAN3_BASE_ADDR,
        (Reg_Can_BfType *)CAN4_BASE_ADDR, (Reg_Can_BfType *)CAN5_BASE_ADDR
}; 

/**
 *  @brief I2S peripheral base address array
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following lines of code also violate this rule with the same reason. */
Reg_I2s_BfType *const Mstp_I2sRegBfPtr[1U] = {
        (Reg_I2s_BfType *)I2S0_BASE_ADDR
};
#elif (defined(DEV_Z20K144M))
/**
 *  @brief CAN peripheral base address array
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following lines of code also violate this rule with the same reason. */
Reg_Can_BfType *const Mstp_CanRegBfPtr[4U] = {
        (Reg_Can_BfType *)CAN0_BASE_ADDR, (Reg_Can_BfType *)CAN1_BASE_ADDR,
        (Reg_Can_BfType *)CAN2_BASE_ADDR, (Reg_Can_BfType *)CAN3_BASE_ADDR
}; 

/**
 *  @brief I2S peripheral base address array
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following lines of code also violate this rule with the same reason. */
Reg_I2s_BfType *const Mstp_I2sRegBfPtr[1U] = {
        (Reg_I2s_BfType *)I2S0_BASE_ADDR
};
#else
    #error "No valid CPU defined!"
#endif

/**
 *  @brief ADC peripheral (ADC0 ADC1) base address array
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following five lines of code also violate this rule with the same reason. */
Reg_Adc_BfType *const Mstp_AdcRegBfPtr[2U] = {
    (Reg_Adc_BfType *)ADC0_BASE_ADDR, /*!< ADC0 base address */
    (Reg_Adc_BfType *)ADC1_BASE_ADDR  /*!< ADC1 base address */
};

Reg_Adc_WType *const  Mstp_Adc0RegWPtr = (Reg_Adc_WType *)ADC0_BASE_ADDR;
Reg_Adc_BfType *const Mstp_Adc0RegBfPtr = (Reg_Adc_BfType *)ADC0_BASE_ADDR;
Reg_Adc_WType *const  Mstp_Adc1RegWPtr = (Reg_Adc_WType *)ADC1_BASE_ADDR;

/**
 *  @brief CMP Register
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following two lines of code also violate this rule with the same reason. */
Reg_Cmp_BfType *const Mstp_CmpRegBfPtr = (Reg_Cmp_BfType *)CMP_BASE_ADDR;
Reg_Cmp_WType *const  Mstp_CmpRegWPtr = (Reg_Cmp_WType *)CMP_BASE_ADDR;

/**
 *  @brief AES Register
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule. */
Reg_Aes_BfType *const Mstp_AesRegBfPtr = (Reg_Aes_BfType *)AES_BASE_ADDR;

/**
 *  @brief TRNG Register
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule. */
Reg_Trng_BfType *const Mstp_TrngRegBfPtr = (Reg_Trng_BfType *)TRNG_BASE_ADDR;

/**
 *  @brief DMA Register
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule. */
Reg_Dma_BfType *const Mstp_DmaRegBfPtr = (Reg_Dma_BfType *)DMA_BASE_ADDR;
Reg_Dma_WType *const  Mstp_DmaRegWPtr = (Reg_Dma_WType *)DMA_BASE_ADDR;

/**
 *  @brief DMAMUX Register
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule. */
Reg_Dmamux_BfType *const Mstp_DmamuxRegBfPtr = (Reg_Dmamux_BfType *)DMAMUX_BASE_ADDR;

/**
 *  @brief PORT Register
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following ten lines of code also violate this rule with the same reason. */
Reg_Port_BfType *const Mstp_PortRegBfPtr[5U] = {
    (Reg_Port_BfType *)PORTA_BASE_ADDR, (Reg_Port_BfType *)PORTB_BASE_ADDR,
    (Reg_Port_BfType *)PORTC_BASE_ADDR, (Reg_Port_BfType *)PORTD_BASE_ADDR,
    (Reg_Port_BfType *)PORTE_BASE_ADDR};
    
Reg_Port_WType *const Mstp_PortRegWPtr[5U] = {
    (Reg_Port_WType *)PORTA_BASE_ADDR, (Reg_Port_WType *)PORTB_BASE_ADDR,
    (Reg_Port_WType *)PORTC_BASE_ADDR, (Reg_Port_WType *)PORTD_BASE_ADDR,
    (Reg_Port_WType *)PORTE_BASE_ADDR};

Reg_Port_WType *const Mstp_PortARegWPtr = (Reg_Port_WType *)PORTA_BASE_ADDR;
Reg_Port_WType *const Mstp_PortBRegWPtr = (Reg_Port_WType *)PORTB_BASE_ADDR;
Reg_Port_WType *const Mstp_PortCRegWPtr = (Reg_Port_WType *)PORTC_BASE_ADDR;
Reg_Port_WType *const Mstp_PortDRegWPtr = (Reg_Port_WType *)PORTD_BASE_ADDR;
Reg_Port_WType *const Mstp_PortERegWPtr = (Reg_Port_WType *)PORTE_BASE_ADDR;

/**
 *  @brief TMU Register
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following two lines of code also violate this rule with the same reason. */
Reg_Tmu_BfType *const Mstp_TmuRegBfPtr = (Reg_Tmu_BfType *)TMU_BASE_ADDR;
Reg_Tmu_WType *const  Mstp_TmuRegWPtr = (Reg_Tmu_WType *)TMU_BASE_ADDR;

/**
 *  @brief REGFILE Register
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following two lines of code also violate this rule with the same reason. */
Reg_Regfile_BfType *const Mstp_RegfileRegBfPtr = (Reg_Regfile_BfType *)REGFILE_BASE_ADDR;
Reg_Regfile_WType *const  Mstp_RegfileRegWPtr = (Reg_Regfile_WType *)REGFILE_BASE_ADDR;

/**
 *  @brief SMPU Register
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule.
The following two lines of code also violate this rule with the same reason. */
Reg_Smpu_BfType *const Mstp_SmpuRegBfPtr = (Reg_Smpu_BfType *)SMPU_BASE_ADDR;
Reg_Smpu_WType *const  Mstp_SmpuRegWPtr = (Reg_Smpu_WType *)SMPU_BASE_ADDR;

/**
 *  @brief GPIO Register
 */
/* MISRA2012 Rule-11.4 violation: Cast between a pointer to volatile object and an integral type,
no side effects forseen by violating this rule. */
Reg_Gpio_BfType *const Mstp_GpioRegBfPtr = (Reg_Gpio_BfType *)GPIO_BASE_ADDR;

#define MSTP_STOP_SEC_CONFIG_DATA_PTR
#include "Mstp_MemMap.h"

#define MSTP_START_SEC_CONFIG_DATA_8
#include "Mstp_MemMap.h"

/**
* @brief Enable/Disable the default error detection and reporting to the DET.
*
*/
const uint8 Mstp_DetFlag = 1U;

/**
* @brief RegFile index of store self test result.

*/
const uint8 Mstp_SelfTestRetRegFileIdx = 0U;

/**
* @brief RegFile index of store self test state.

*/
const uint8 Mstp_SelfTestStateRegFileIdx = 1U;

#define MSTP_STOP_SEC_CONFIG_DATA_8
#include "Mstp_MemMap.h"

#define MSTP_START_SEC_CONFIG_DATA_32
#include "Mstp_MemMap.h"

/**
* @brief Program flash memory start address and end address.
*/
const uint32 Mstp_PFlashStartAddress = 0x0U;
const uint32 Mstp_PFlashEndAddress = 0x1fffffU;

/**
* @brief SRAM memory start address and end address.
*/
const uint32 Mstp_SramStartAddress = 0x1ffe0000U;
const uint32 Mstp_SramEndAddress = 0x2001ffffU;

/**
* @brief SRAM memory start address and end address.
*/
const uint32 Mstp_DFlashStartAddress = 0x1000000U;
const uint32 Mstp_DFlashEndAddress = 0x101ffffU;

/**
* @brief Program flash IFR memory start address and end address.
*/
const uint32 Mstp_PFlashIFRStartAddress = 0x2000000U;
const uint32 Mstp_PFlashIFREndAddress = 0x2007fffU;

#define MSTP_STOP_SEC_CONFIG_DATA_32
#include "Mstp_MemMap.h"


#define MSTP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mstp_MemMap.h"

/**
* @brief   Configured module ids to do register check.
*
*/
static const Mstp_RegCheckModuleIdType Mstp_RegCheckModules[] =
{
    MSTP_REG_CHECK_CMU0,
    MSTP_REG_CHECK_CMU1,
    MSTP_REG_CHECK_CMU2,
    MSTP_REG_CHECK_WDOG,
    MSTP_REG_CHECK_SMPU,
    MSTP_REG_CHECK_STIM,
    MSTP_REG_CHECK_ADC0,
    MSTP_REG_CHECK_ADC1,
    MSTP_REG_CHECK_PARCC,
    MSTP_REG_CHECK_SERU,
    MSTP_REG_CHECK_SCC,
    MSTP_REG_CHECK_MCPWM0,
    MSTP_REG_CHECK_MCPWM1,
    MSTP_REG_CHECK_TIM0,
    MSTP_REG_CHECK_TIM1,
    MSTP_REG_CHECK_TIM2,
    MSTP_REG_CHECK_TIM3,
    MSTP_REG_CHECK_PORTA,
    MSTP_REG_CHECK_PORTB,
    MSTP_REG_CHECK_PORTC,
    MSTP_REG_CHECK_PORTD,
    MSTP_REG_CHECK_PORTE,
    MSTP_REG_CHECK_SCM,
    MSTP_REG_CHECK_SRMC,
    MSTP_REG_CHECK_PMU,
    MSTP_REG_CHECK_TDG0,
    MSTP_REG_CHECK_TDG1
};

/**
* @brief   Configuration of PARCC self test modules .
*
*/
static const Mstp_ParccModuleIdType Mstp_ParccCrcCheckModules[] =
{
    MSTP_PARCC_STIM,
    MSTP_PARCC_TIM0,
    MSTP_PARCC_TIM1,
    MSTP_PARCC_TIM2,
    MSTP_PARCC_TIM3,
    MSTP_PARCC_MCPWM0,
    MSTP_PARCC_MCPWM1,
    MSTP_PARCC_TDG0,
    MSTP_PARCC_TDG1,
    MSTP_PARCC_CAN6,
    MSTP_PARCC_UART0,
    MSTP_PARCC_UART1,
    MSTP_PARCC_SPI1,
    MSTP_PARCC_SPI3,
    MSTP_PARCC_ADC0,
    MSTP_PARCC_ADC1,
    MSTP_PARCC_CRC,
    MSTP_PARCC_FLASH,
    MSTP_PARCC_DMA,
    MSTP_PARCC_DMAMUX,
    MSTP_PARCC_PORTA,
    MSTP_PARCC_PORTB,
    MSTP_PARCC_PORTC,
    MSTP_PARCC_PORTD,
    MSTP_PARCC_PORTE,
    MSTP_PARCC_REGFILE,
    MSTP_PARCC_SMPU,
    MSTP_PARCC_GPIO
};

#define MSTP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mstp_MemMap.h"

#define MSTP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mstp_MemMap.h"

/**
* @brief   Configuration of CRC check PARCC modules.
*
*/
static const Mstp_ParccTestConfigType Mstp_ParccCrcCheckConfig =
{
    /* Configured to be checked PARCC modules */
    Mstp_ParccCrcCheckModules,

    /* Number of PARCC modules to be checked */
    28U
};

/**
* @brief   Configuration of register check.
*
*/
static const Mstp_RegCheckConfigType Mstp_RegCheckConfig =
{
    /*!< @brief Identifies the module to be checked */
    Mstp_RegCheckModules,
    /*!< @brief Configuration of PARCC CRC check */
    &Mstp_ParccCrcCheckConfig,
    /*!< @brief Number of test group for configuration register check */
    27U
};

#define MSTP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mstp_MemMap.h"




#define MSTP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mstp_MemMap.h"

/**
* @brief   Configuration of PARCC self test modules .
*
*/
static const Mstp_ParccModuleIdType Mstp_ParccSelfTestModules[] =
{
    MSTP_PARCC_STIM,
    MSTP_PARCC_TIM0,
    MSTP_PARCC_TIM1,
    MSTP_PARCC_TIM2,
    MSTP_PARCC_TIM3,
    MSTP_PARCC_MCPWM0,
    MSTP_PARCC_MCPWM1,
    MSTP_PARCC_TDG0,
    MSTP_PARCC_TDG1,
    MSTP_PARCC_CAN6,
    MSTP_PARCC_UART0,
    MSTP_PARCC_UART1,
    MSTP_PARCC_SPI1,
    MSTP_PARCC_SPI3,
    MSTP_PARCC_ADC0,
    MSTP_PARCC_ADC1,
    MSTP_PARCC_CRC,
    MSTP_PARCC_DMA,
    MSTP_PARCC_DMAMUX,
    MSTP_PARCC_PORTA,
    MSTP_PARCC_PORTB,
    MSTP_PARCC_PORTC,
    MSTP_PARCC_PORTD,
    MSTP_PARCC_PORTE,
    MSTP_PARCC_REGFILE,
    MSTP_PARCC_SMPU,
    MSTP_PARCC_GPIO
};

#define MSTP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mstp_MemMap.h"

#define MSTP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mstp_MemMap.h"

/**
* @brief   Configuration of PARCC module self test.
*
*/
static const Mstp_ParccTestConfigType Mstp_ParccSelfTestConfig =
{
    /* Configured to be tested PARCC modules */
    Mstp_ParccSelfTestModules,

    /* Number of PARCC modules to be tested */
    27U
};

/**
* @brief   Configuration of module self test.
*
*/
static const Mstp_SelfTestConfigType Mstp_SelfTestConfig =
{
    /* Configuration of PARCC self test */
    &Mstp_ParccSelfTestConfig,

    5.0f
};

#define MSTP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mstp_MemMap.h"



#define MSTP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mstp_MemMap.h"

/**
* @brief   Configuration of RAM test parameters.
*
*/
static const Mstp_RamTestParamsType Mstp_RamTestParams[] =
{
    {
        /* ID of tested RAM block */
        1,
        /* Start address of tested RAM block */
        0x20010000,
        /* End address of tested RAM block */
        0x20010008,
        /* Test policy of this tested RAM block */
        MSTP_RAMTEST_NON_DESTRUCTIVE
    }
};

/**
* @brief   Configuration of RAM test.
*
*/
static const Mstp_RamTestConfigType Mstp_RamTestConfig =
{
    
    /* Number of tested RAM blocks */
    1,
    /* Number of tested cells each test cycle */
    2,
    /* All blocks test complete callback function */
    RamTestCompletedNotification,
    /* Test error notification callback function */
    RamTestErrorNotification,
    /* Configuration of tested RAM blocks */
    Mstp_RamTestParams
};

#define MSTP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mstp_MemMap.h"



#define MSTP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mstp_MemMap.h"

/**
* @brief   Configuration of MSTP.
*
*/
static const Mstp_ConfigType Mstp_Config =
{
    &Mstp_SelfTestConfig,
    &Mstp_RamTestConfig,
    &Mstp_RegCheckConfig
};

#define MSTP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mstp_MemMap.h"



#define MSTP_START_SEC_CONFIG_DATA_PTR
#include "Mstp_MemMap.h"

/**
* @brief Mstp configuration data for Mstp_PreDefinedConfigPtr.
*
*/
const Mstp_ConfigType * const Mstp_PreDefinedConfigPtr = &Mstp_Config;

#define MSTP_STOP_SEC_CONFIG_DATA_PTR
#include "Mstp_MemMap.h"


#define MSTP_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mstp_MemMap.h"

/**
* @brief RAM test result.
*/
Mstp_RamTestResultType Mstp_RamTestResult[1U];

#define MSTP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mstp_MemMap.h"

#ifdef __cplusplus
}
#endif

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


/** @} end of group Public_FunctionDefinition */

/** @} end of group Mstp_Configuration */

/** @} end of group Mstp_Module */
