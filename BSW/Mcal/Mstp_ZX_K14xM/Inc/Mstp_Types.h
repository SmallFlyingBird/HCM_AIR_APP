/**************************************************************************************************/
/**
 * @file      : Mstp_Types.h
 * @brief     : Mstp_Types AUTOSAR level header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef MSTP_TYPES_H
#define MSTP_TYPES_H

/** @addtogroup Mstp_Module
 *  @{
 */

/** @addtogroup Mstp Types
 *  @brief Mstp Types define
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Mstp_Cfg.h"
#include "Std_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define MSTP_TYPES_H_VENDOR_ID                   0x00B3U
#define MSTP_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define MSTP_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define MSTP_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define MSTP_TYPES_H_SW_MAJOR_VERSION            1U
#define MSTP_TYPES_H_SW_MINOR_VERSION            1U
#define MSTP_TYPES_H_SW_PATCH_VERSION            0U

/* Check if current file and Mstp_Cfg.h file are of the same vendor */
#if (MSTP_TYPES_H_VENDOR_ID != MSTP_CFG_H_VENDOR_ID)
    #error "Vendor ID of Mstp_Types.h and Mstp_Cfg.h are different"
#endif

/* Check if current file and Mstp_Cfg.h file are of the same Autosar version */
#if ((MSTP_TYPES_H_AR_RELEASE_MAJOR_VERSION != MSTP_CFG_H_AR_RELEASE_MAJOR_VERSION) ||             \
     (MSTP_TYPES_H_AR_RELEASE_MINOR_VERSION != MSTP_CFG_H_AR_RELEASE_MINOR_VERSION) ||             \
     (MSTP_TYPES_H_AR_RELEASE_REVISION_VERSION != MSTP_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Mstp_Types.h and Mstp_Cfg.h are different"
#endif

/* Check if current file and Mstp_Cfg.h file are of the same Software version */
#if ((MSTP_TYPES_H_SW_MAJOR_VERSION != MSTP_CFG_H_SW_MAJOR_VERSION) ||                             \
     (MSTP_TYPES_H_SW_MINOR_VERSION != MSTP_CFG_H_SW_MINOR_VERSION) ||                             \
     (MSTP_TYPES_H_SW_PATCH_VERSION != MSTP_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Mstp_Types.h and Mstp_Cfg.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Std_Types.h files are of the same AUTOSAR version */
    #if ((MSTP_TYPES_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) ||                \
         (MSTP_TYPES_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of Mstp_Types.h and Std_Types.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */
/**
 * @brief Type definition of self-test state.
 */
typedef enum
{
    MSTP_SELFTEST_STATE_IDLE = 0x00U, /*!< Self-test is not running. */
    MSTP_SELFTEST_STATE_BUSY = 0x01U  /*!< Self-test is running. */
} Mstp_SelfTestStateType;

/**
 * @brief Type definition of specify module self-test flag.
 */
typedef enum
{
    MSTP_SELFTEST_FLAG_UNINIT = 0U, /*!< Module self-test is not triggered. */
    MSTP_SELFTEST_FLAG_INIT,        /*!< Module self-test is triggered. */
    MSTP_SELFTEST_FLAG_FAILED,      /*!< Module self-test executed failed. */
    MSTP_SELFTEST_FLAG_SUCCESS      /*!< Module self-test executed success. */
} Mstp_SelfTestFlagType;

/**
 * @brief Type definition of self-test module.
 */
typedef enum
{
    MSTP_SELFTEST_SERU = 0U, /*!< SERU module test */
    MSTP_SELFTEST_EWDT,      /*!< EWDT module test */
    MSTP_SELFTEST_FLASHECC,  /*!< FLASH ECC function test */
    MSTP_SELFTEST_SRAMECC,   /*!< SRAM ECC function test */
    MSTP_SELFTEST_PARCC,     /*!< PARCC write protection test */
    MSTP_SELFTEST_PMU,       /*!< PMU module test */
    MSTP_SELFTEST_CMU,       /*!< CMU module test */
    MSTP_SELFTEST_SMPU,      /*!< SMPU module test */
    MSTP_SELFTEST_CRC,       /*!< CRC module test */
    MSTP_SELFTEST_WDOG       /*!< WDOG module test */
} Mstp_SelfTestModuleIdType;

/**
 * @brief Type definition of self-test result.
 */
typedef enum
{
    MSTP_SELFTEST_RESULT_SUCCESS = 0U, /*!< Self-test executed success. */
    MSTP_SELFTEST_RESULT_FAILED        /*!< Self-test executed failed. */
} Mstp_SelfTestResultType;

/**
 * @brief Type definition of configuration check peripheral.
 */
typedef enum
{
    MSTP_REG_CHECK_SERU = 0U, /*!< SERU */
    MSTP_REG_CHECK_PMU,       /*!< PMU */
    MSTP_REG_CHECK_SRMC,      /*!< SRMC */
    MSTP_REG_CHECK_SCC,       /*!< SCC */
    MSTP_REG_CHECK_SCM,       /*!< SCM */
    MSTP_REG_CHECK_CMU0,      /*!< CMU0 */
    MSTP_REG_CHECK_CMU1,      /*!< CMU1 */
    MSTP_REG_CHECK_CMU2,      /*!< CMU2 */
    MSTP_REG_CHECK_WDOG,      /*!< WDOG */
    MSTP_REG_CHECK_EWDT,      /*!< EWDT */
    MSTP_REG_CHECK_SMPU,      /*!< SMPU */
    MSTP_REG_CHECK_DMA,       /*!< DMA */
    MSTP_REG_CHECK_STIM,      /*!< STIM */
    MSTP_REG_CHECK_ADC0,      /*!< ADC0 */
    MSTP_REG_CHECK_ADC1,      /*!< ADC1 */
    MSTP_REG_CHECK_CMP,       /*!< CMP */
    MSTP_REG_CHECK_TIM0,      /*!< TIM0 */
    MSTP_REG_CHECK_TIM1,      /*!< TIM1 */
    MSTP_REG_CHECK_TIM2,      /*!< TIM2 */
    MSTP_REG_CHECK_TIM3,      /*!< TIM3 */
    MSTP_REG_CHECK_MCPWM0,    /*!< MCPWM0 */
    MSTP_REG_CHECK_MCPWM1,    /*!< MCPWM1 */
    MSTP_REG_CHECK_TMU,       /*!< TMU */
    MSTP_REG_CHECK_TDG0,      /*!< TDG0 */
    MSTP_REG_CHECK_TDG1,      /*!< TDG1 */
    MSTP_REG_CHECK_PORTA,     /*!< PORTA */
    MSTP_REG_CHECK_PORTB,     /*!< PORTB */
    MSTP_REG_CHECK_PORTC,     /*!< PORTC */
    MSTP_REG_CHECK_PORTD,     /*!< PORTD */
    MSTP_REG_CHECK_PORTE,     /*!< PORTE */
    MSTP_REG_CHECK_PARCC,     /*!< PARCC*/
    MSTP_REG_CHECK_END
} Mstp_RegCheckModuleIdType;

/**
 * @brief Type definition of RAM test policy.
 */
typedef enum
{
    MSTP_RAMTEST_DESTRUCTIVE = 0U, /*!< Destructive test. */
    MSTP_RAMTEST_NON_DESTRUCTIVE   /*!< Non-destructive test. */
} Mstp_RamTestPolicyType;

/**
 * @brief Type definition of RAM test result.
 */
typedef enum
{
    MSTP_RAMTST_RESULT_NOT_TESTED = 0x00U, /*!< The RAM Test is not executed. */
    MSTP_RAMTST_RESULT_OK,                 /*!< The RAM Test has been tested with OK result. */
    MSTP_RAMTST_RESULT_NOT_OK,             /*!< The RAM Test has been tested with NOT-OK result. */
    MSTP_RAMTST_RESULT_UNDEFINED           /*!< The RAM Test is currently running. */
} Mstp_RamTestResultType;

/**
 *  @brief Type definition of PARCC module.
 *
 */
typedef enum
{
    MSTP_PARCC_WDOG = 0x00U, /*!< WDOG */
    MSTP_PARCC_EWDT,         /*!< EWDT */
    MSTP_PARCC_STIM,         /*!< STIM */
    MSTP_PARCC_TIM0,         /*!< TIM0 */
    MSTP_PARCC_TIM1,         /*!< TIM1 */
    MSTP_PARCC_TIM2,         /*!< TIM2 */
    MSTP_PARCC_TIM3,         /*!< TIM3 */
    MSTP_PARCC_MCPWM0,       /*!< MCPWM0 */
    MSTP_PARCC_MCPWM1,       /*!< MCPWM1 */
    MSTP_PARCC_TDG0,         /*!< TDG0 */
    MSTP_PARCC_TDG1,         /*!< TDG1 */
    MSTP_PARCC_CAN0,         /*!< CAN0 */
    MSTP_PARCC_CAN1,         /*!< CAN1 */
    MSTP_PARCC_CAN2,         /*!< CAN2 */
    MSTP_PARCC_CAN3,         /*!< CAN3 */
    MSTP_PARCC_CAN4,         /*!< CAN4 */
    MSTP_PARCC_CAN5,         /*!< CAN5 */
    MSTP_PARCC_CAN6,         /*!< CAN6 */
    MSTP_PARCC_CAN7,         /*!< CAN7 */
    MSTP_PARCC_UART0,        /*!< UART0 */
    MSTP_PARCC_UART1,        /*!< UART1 */
    MSTP_PARCC_UART2,        /*!< UART2 */
    MSTP_PARCC_UART3,        /*!< UART3 */
    MSTP_PARCC_UART4,        /*!< UART4 */
    MSTP_PARCC_UART5,        /*!< UART5 */
    MSTP_PARCC_SPI0,         /*!< SPI0 */
    MSTP_PARCC_SPI1,         /*!< SPI1 */
    MSTP_PARCC_SPI2,         /*!< SPI2 */
    MSTP_PARCC_SPI3,         /*!< SPI3 */
    MSTP_PARCC_I2C0,         /*!< I2C0 */
    MSTP_PARCC_I2C1,         /*!< I2C1 */
    MSTP_PARCC_I2S0,         /*!< I2S0 */
    MSTP_PARCC_I2S1,         /*!< I2S1 */
    MSTP_PARCC_RESERVED1,    /*!< Reserved */
    MSTP_PARCC_ADC0,         /*!< ADC0 */
    MSTP_PARCC_ADC1,         /*!< ADC1 */
    MSTP_PARCC_CMP0,         /*!< CMP0 */
    MSTP_PARCC_CRC,          /*!< CRC */
    MSTP_PARCC_AES,          /*!< AES */
    MSTP_PARCC_TRNG,         /*!< TRNG */
    MSTP_PARCC_FLASH,        /*!< FLASH */
    MSTP_PARCC_RESERVED2,    /*!< Reserved */
    MSTP_PARCC_DMA,          /*!< DMA */
    MSTP_PARCC_DMAMUX,       /*!< DMAMUX */
    MSTP_PARCC_PORTA,        /*!< PORTA */
    MSTP_PARCC_PORTB,        /*!< PORTB */
    MSTP_PARCC_PORTC,        /*!< PORTC */
    MSTP_PARCC_PORTD,        /*!< PORTD */
    MSTP_PARCC_PORTE,        /*!< PORTE */
    MSTP_PARCC_TMU,          /*!< TMU */
    MSTP_PARCC_REGFILE,      /*!< REGFILE */
    MSTP_PARCC_SMPU,         /*!< SMPU */
    MSTP_PARCC_GPIO          /*!< GPIO */
} Mstp_ParccModuleIdType;

/**
 * @brief Type definition of PARCC self test configuration.
 */
typedef struct
{
    const Mstp_ParccModuleIdType *ParccTestModules; /*!< Pointer to store the tested peripherals */
    uint32                      NumberOfParccTestModules; /*!< Number of peripherals to be tested */
} Mstp_ParccTestConfigType;

/**
 * @brief Type definition of configuration registers check configuration.
 */
typedef struct
{
    const Mstp_RegCheckModuleIdType *ModuleIdPtr; /*!< Pointer to store the checked modules. */
    const Mstp_ParccTestConfigType
         *ParccCrcCheckConfigPtr;                 /*!< Pointer to store the checked peripherals. */
    uint8 NumberOfRegCheckModules;                /*!< Number of the checked modules. */
} Mstp_RegCheckConfigType;

/**
 * @brief Type definition of RAM test parameters.
 */
typedef struct
{
    uint32                 BlockId;    /*!< ID of tested RAM block */
    uint32                 StartAddr;  /*!< Start address of tested RAM block */
    uint32                 EndAddr;    /*!< End address of tested RAM block */
    Mstp_RamTestPolicyType TestPolicy; /*!< Test policy of this tested RAM block */
} Mstp_RamTestParamsType;

/**
 * @brief Type definition of RAM test configuration.
 */
typedef struct
{
    uint32 NumberOfTestedBlocks;             /*!< Number of tested RAM blocks */
    uint32 NumberOfTestedCells;              /*!< Number of tested cells each test cycle */
    void (*TestCompleteNotifyFuncPtr)(void); /*!< All blocks test complete callback function */
    void (*TestErrorNotifyFuncPtr)(void);    /*!< Test error notification callback function */
    const Mstp_RamTestParamsType *TestedBlocksParams; /*!< Configuration of tested RAM blocks */
} Mstp_RamTestConfigType;

/**
 * @brief Type definition of module self-test configuration.
 */
typedef struct
{
    const Mstp_ParccTestConfigType *ParccSelfTestConfigPtr; /*!< Configuration of PARCC self test */
    const float32                   PmuSelfTestVddRef;      /*!< VDD ref for PMU self test */
} Mstp_SelfTestConfigType;

/**
 * @brief Type definition of MSTP configuration.
 */
typedef struct
{
    const Mstp_SelfTestConfigType *SelfTestConfigPtr; /*!< Configuration of module self test */
    const Mstp_RamTestConfigType  *RamTestConfigPtr;  /*!< Configuration of RAM test */
    const Mstp_RegCheckConfigType *RegCheckConfigPtr; /*!< Configuration of reg check test */
} Mstp_ConfigType;

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Mstp */

/** @} end of group Mstp_Module */

#endif /* MSTP_TYPES_H */
