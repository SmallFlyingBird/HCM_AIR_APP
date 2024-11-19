/**************************************************************************************************/
/**
 * @file      : Parcc_Drv_Cfg.c 
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

#ifdef __cplusplus
extern "C"
{
#endif

#include "Parcc_Drv.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

#define PARCC_DRV_CFG_C_VENDOR_ID                   0x00B3U
#define PARCC_DRV_CFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define PARCC_DRV_CFG_C_AR_RELEASE_MINOR_VERSION    6U
#define PARCC_DRV_CFG_C_AR_RELEASE_REVISION_VERSION 0U
#define PARCC_DRV_CFG_C_SW_MAJOR_VERSION            1U
#define PARCC_DRV_CFG_C_SW_MINOR_VERSION            2U
#define PARCC_DRV_CFG_C_SW_PATCH_VERSION            2U

/* Check if current file and Parcc_Drv.h file are of the same vendor */
#if (PARCC_DRV_CFG_C_VENDOR_ID != PARCC_DRV_H_VENDOR_ID)
    #error "Vendor ID of Parcc_Drv_Cfg.c and Parcc_Drv.h are different"
#endif

/* Check if current file and Parcc_Drv.h file are of the same Autosar version */
#if ((PARCC_DRV_CFG_C_AR_RELEASE_MAJOR_VERSION != PARCC_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (PARCC_DRV_CFG_C_AR_RELEASE_MINOR_VERSION != PARCC_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (PARCC_DRV_CFG_C_AR_RELEASE_REVISION_VERSION != PARCC_DRV_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version of Parcc_Drv_Cfg.c and Parcc_Drv.h are different"
#endif

/* Check if current file and Parcc_Drv.h file are of the same Software version */
#if ((PARCC_DRV_CFG_C_SW_MAJOR_VERSION != PARCC_DRV_H_SW_MAJOR_VERSION) || \
     (PARCC_DRV_CFG_C_SW_MINOR_VERSION != PARCC_DRV_H_SW_MINOR_VERSION) || \
     (PARCC_DRV_CFG_C_SW_PATCH_VERSION != PARCC_DRV_H_SW_PATCH_VERSION) \
    )
  #error "Software Version of Parcc_Drv_Cfg.c and Parcc_Drv.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

/**
 *  @brief Parcc registers info(address, reset value)
 *
 */
const Parcc_Drv_RegDefinitionType Parcc_Drv_ParccRegsTab[46U] =
{
    /* WDOG */
    {
        .Addr = (0x40065000U + 0x0U), 
        .ResetVal = 0x89200001U
    }, 
    /* EWDT */
    {
        .Addr = (0x40065000U + 0x4U), 
        .ResetVal = 0x8F000000U
    }, 
    /* STIM */
    {
        .Addr = (0x40065000U + 0x8U), 
        .ResetVal = 0x8F000000U
    }, 
    /* TIM0 */
    {
        .Addr = (0x40065000U + 0xCU), 
        .ResetVal = 0x8F000000U
    }, 
    /* TIM1 */
    {
        .Addr = (0x40065000U + 0x10U), 
        .ResetVal = 0x8F000000U
    }, 
    /* TIM2 */
    {
        .Addr = (0x40065000U + 0x14U), 
        .ResetVal = 0x8F000000U
    }, 
    /* TIM3 */
    {
        .Addr = (0x40065000U + 0x18U), 
        .ResetVal = 0x8F000000U
    }, 
    /* MCPWM0 */
    {
        .Addr = (0x40065000U + 0x1CU), 
        .ResetVal = 0x8F000000U
    }, 
    /* MCPWM1 */
    {
        .Addr = (0x40065000U + 0x20U), 
        .ResetVal = 0x8F000000U
    }, 
    /* TDG0 */
    {
        .Addr = (0x40065000U + 0x24U), 
        .ResetVal = 0x8F000000U
    }, 
    /* TDG1 */
    {
        .Addr = (0x40065000U + 0x28U), 
        .ResetVal = 0x8F000000U
    }, 
    /* CAN0 */
    {
        .Addr = (0x40065000U + 0x2CU), 
        .ResetVal = 0x8F000000U
    }, 
    /* CAN1 */
    {
        .Addr = (0x40065000U + 0x30U), 
        .ResetVal = 0x8F000000U
    }, 
    /* CAN2 */
    {
        .Addr = (0x40065000U + 0x34U), 
        .ResetVal = 0x8F000000U
    }, 
    /* CAN3 */
    {
        .Addr = (0x40065000U + 0x38U), 
        .ResetVal = 0x8F000000U
    }, 
    /* UART0 */
    {
        .Addr = (0x40065000U + 0x4CU), 
        .ResetVal = 0x8F000000U
    }, 
    /* UART1 */
    {
        .Addr = (0x40065000U + 0x50U), 
        .ResetVal = 0x8F000000U
    }, 
    /* UART2 */
    {
        .Addr = (0x40065000U + 0x54U), 
        .ResetVal = 0x8F000000U
    }, 
    /* UART3 */
    {
        .Addr = (0x40065000U + 0x58U), 
        .ResetVal = 0x8F000000U
    }, 
    /* UART4 */
    {
        .Addr = (0x40065000U + 0x5CU), 
        .ResetVal = 0x8F000000U
    }, 
    /* UART5 */
    {
        .Addr = (0x40065000U + 0x60U), 
        .ResetVal = 0x8F000000U
    }, 
    /* SPI0 */
    {
        .Addr = (0x40065000U + 0x64U), 
        .ResetVal = 0x8F000000U
    }, 
    /* SPI1 */
    {
        .Addr = (0x40065000U + 0x68U), 
        .ResetVal = 0x8F000000U
    }, 
    /* SPI2 */
    {
        .Addr = (0x40065000U + 0x6CU), 
        .ResetVal = 0x8F000000U
    }, 
    /* SPI3 */
    {
        .Addr = (0x40065000U + 0x70U), 
        .ResetVal = 0x8F000000U
    }, 
    /* I2C0 */
    {
        .Addr = (0x40065000U + 0x74U), 
        .ResetVal = 0x8F000000U
    }, 
    /* I2C1 */
    {
        .Addr = (0x40065000U + 0x78U), 
        .ResetVal = 0x8F000000U
    }, 
    /* I2S0 */
    {
        .Addr = (0x40065000U + 0x7CU), 
        .ResetVal = 0x8F000000U
    }, 
    /* ADC0 */
    {
        .Addr = (0x40065000U + 0x88U), 
        .ResetVal = 0x8F000000U
    }, 
    /* ADC1 */
    {
        .Addr = (0x40065000U + 0x8CU), 
        .ResetVal = 0x8F000000U
    }, 
    /* CMP0 */
    {
        .Addr = (0x40065000U + 0x90U), 
        .ResetVal = 0x89200000U
    }, 
    /* CRC */
    {
        .Addr = (0x40065000U + 0x94U), 
        .ResetVal = 0x89200000U
    }, 
    /* AES */
    {
        .Addr = (0x40065000U + 0x98U), 
        .ResetVal = 0x89200000U
    }, 
    /* TRNG */
    {
        .Addr = (0x40065000U + 0x9CU), 
        .ResetVal = 0x89200000U
    }, 
    /* FLASH */
    {
        .Addr = (0x40065000U + 0xA0U), 
        .ResetVal = 0x89200731U
    }, 
    /* DMA */
    {
        .Addr = (0x40065000U + 0xA8U), 
        .ResetVal = 0x89200000U
    }, 
    /* DMAMUX */
    {
        .Addr = (0x40065000U + 0xACU), 
        .ResetVal = 0x89200000U
    }, 
    /* PORTA */
    {
        .Addr = (0x40065000U + 0xB0U), 
        .ResetVal = 0x8F000000U
    }, 
    /* PORTB */
    {
        .Addr = (0x40065000U + 0xB4U), 
        .ResetVal = 0x8F000000U
    }, 
    /* PORTC */
    {
        .Addr = (0x40065000U + 0xB8U), 
        .ResetVal = 0x8F000000U
    }, 
    /* PORTD */
    {
        .Addr = (0x40065000U + 0xBCU), 
        .ResetVal = 0x8F000000U
    }, 
    /* PORTE */
    {
        .Addr = (0x40065000U + 0xC0U), 
        .ResetVal = 0x8F000000U
    }, 
    /* TMU */
    {
        .Addr = (0x40065000U + 0xC4U), 
        .ResetVal = 0x89200000U
    }, 
    /* REGFILE */
    {
        .Addr = (0x40065000U + 0xC8U), 
        .ResetVal = 0x89200000U
    }, 
    /* SMPU */
    {
        .Addr = (0x40065000U + 0xCCU), 
        .ResetVal = 0x89200001U
    }, 
    /* GPIO */
    {
        .Addr = (0x40065000U + 0xD0U), 
        .ResetVal = 0x89200000U
    } 
};

#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

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



#ifdef __cplusplus
}
#endif

/** @} end of group Parcc_Drv_Configuration */

/** @} end of group Mcu_Module */
