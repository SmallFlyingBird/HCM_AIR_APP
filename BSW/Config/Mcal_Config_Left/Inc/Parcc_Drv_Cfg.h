/**************************************************************************************************/
/**
 * @file      : Parcc_Drv_Cfg.h
 * @brief     : AUTOSAR Mcu - Pre-Compile(PC) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup Mcu_Module
 *  @{
 */

/** @addtogroup Parcc_Drv_Configuration
 *  @brief PARCC driver configuration
 *  @{
 */

#ifndef PARCC_DRV_CFG_H
#define PARCC_DRV_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Parcc_Drv_PBcfg.h"


/** @defgroup Public_MacroDefinition
 *  @{
 */

#define PARCC_DRV_CFG_H_VENDOR_ID                   0x00B3U
#define PARCC_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define PARCC_DRV_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define PARCC_DRV_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define PARCC_DRV_CFG_H_SW_MAJOR_VERSION            1U
#define PARCC_DRV_CFG_H_SW_MINOR_VERSION            2U
#define PARCC_DRV_CFG_H_SW_PATCH_VERSION            2U

/* Check if current file and Parcc_Drv_PBcfg.h are of the same vendor */
#if (PARCC_DRV_CFG_H_VENDOR_ID != PARCC_DRV_PBCFG_H_VENDOR_ID)
    #error "Vendor ID of Parcc_Drv_Cfg.h and Parcc_Drv_PBcfg.h are different"
#endif
    /* Check if current file and Parcc_Drv_PBcfg.h are of the same Autosar version */
#if ((PARCC_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION != PARCC_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (PARCC_DRV_CFG_H_AR_RELEASE_MINOR_VERSION != PARCC_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
     (PARCC_DRV_CFG_H_AR_RELEASE_REVISION_VERSION != PARCC_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Parcc_Drv_Cfg.h and Parcc_Drv_PBcfg.h are different"
#endif
/* Check if current file and Parcc_Drv_PBcfg.h are of the same software version */
#if ((PARCC_DRV_CFG_H_SW_MAJOR_VERSION != PARCC_DRV_PBCFG_H_SW_MAJOR_VERSION) || \
     (PARCC_DRV_CFG_H_SW_MINOR_VERSION != PARCC_DRV_PBCFG_H_SW_MINOR_VERSION) || \
     (PARCC_DRV_CFG_H_SW_PATCH_VERSION != PARCC_DRV_PBCFG_H_SW_PATCH_VERSION))
#error "Software Version of Parcc_Drv_Cfg.h and Parcc_Drv_PBcfg.h are different"
#endif

#define PARCC_DRV_SUPPORTED_PERIPHERAL_NUM (46U)

#define PARCC_DRV_CONFIG_EXT \
    PARCC_DRV_CONFIG_PB

#define PARCC_DRV_REGISTERS_DEFINITION \
    extern const Parcc_Drv_RegDefinitionType Parcc_Drv_ParccRegsTab[46];
    
/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 *  @brief Type definition of PARCC module.
 *
 */
typedef enum
{
    PARCC_DRV_WDOG = 0, /* WDOG */
    PARCC_DRV_EWDT = 1, /* EWDT */
    PARCC_DRV_STIM = 2, /* STIM */
    PARCC_DRV_TIM0 = 3, /* TIM0 */
    PARCC_DRV_TIM1 = 4, /* TIM1 */
    PARCC_DRV_TIM2 = 5, /* TIM2 */
    PARCC_DRV_TIM3 = 6, /* TIM3 */
    PARCC_DRV_MCPWM0 = 7, /* MCPWM0 */
    PARCC_DRV_MCPWM1 = 8, /* MCPWM1 */
    PARCC_DRV_TDG0 = 9, /* TDG0 */
    PARCC_DRV_TDG1 = 10, /* TDG1 */
    PARCC_DRV_CAN0 = 11, /* CAN0 */
    PARCC_DRV_CAN1 = 12, /* CAN1 */
    PARCC_DRV_CAN2 = 13, /* CAN2 */
    PARCC_DRV_CAN3 = 14, /* CAN3 */
    PARCC_DRV_UART0 = 19, /* UART0 */
    PARCC_DRV_UART1 = 20, /* UART1 */
    PARCC_DRV_UART2 = 21, /* UART2 */
    PARCC_DRV_UART3 = 22, /* UART3 */
    PARCC_DRV_UART4 = 23, /* UART4 */
    PARCC_DRV_UART5 = 24, /* UART5 */
    PARCC_DRV_SPI0 = 25, /* SPI0 */
    PARCC_DRV_SPI1 = 26, /* SPI1 */
    PARCC_DRV_SPI2 = 27, /* SPI2 */
    PARCC_DRV_SPI3 = 28, /* SPI3 */
    PARCC_DRV_I2C0 = 29, /* I2C0 */
    PARCC_DRV_I2C1 = 30, /* I2C1 */
    PARCC_DRV_I2S0 = 31, /* I2S0 */
    PARCC_DRV_ADC0 = 34, /* ADC0 */
    PARCC_DRV_ADC1 = 35, /* ADC1 */
    PARCC_DRV_CMP0 = 36, /* CMP0 */
    PARCC_DRV_CRC = 37, /* CRC */
    PARCC_DRV_AES = 38, /* AES */
    PARCC_DRV_TRNG = 39, /* TRNG */
    PARCC_DRV_FLASH = 40, /* FLASH */
    PARCC_DRV_DMA = 42, /* DMA */
    PARCC_DRV_DMAMUX = 43, /* DMAMUX */
    PARCC_DRV_PORTA = 44, /* PORTA */
    PARCC_DRV_PORTB = 45, /* PORTB */
    PARCC_DRV_PORTC = 46, /* PORTC */
    PARCC_DRV_PORTD = 47, /* PORTD */
    PARCC_DRV_PORTE = 48, /* PORTE */
    PARCC_DRV_TMU = 49, /* TMU */
    PARCC_DRV_REGFILE = 50, /* REGFILE */
    PARCC_DRV_SMPU = 51, /* SMPU */
    PARCC_DRV_GPIO = 52 /* GPIO */
} Parcc_Drv_ModuleType;

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

#endif /* #ifndef PARCC_DRV_CFG_H */

/** @} end of group Parcc_Drv_Configuration */

/** @} end of group Mcu_Module */
