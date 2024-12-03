/**************************************************************************************************/
/**
 * @file      : Compiler_Cfg.h
 * @brief     : The file Compiler_Cfg.h shall contain the module/component specific parameters
 *              (ptrclass and memclass) that are passed to the macros defined in Compiler.h.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef COMPILER_CFG_H
#define COMPILER_CFG_H

/** @addtogroup  Base_Module
 *  @{
 */

/** @defgroup Compiler_Cfg
 *  @brief contain the module/component specific parameters (ptrclass and memclass) that are passed
 *  to the macros defined in Compiler.h.
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */

#define REGSPASE

/**
 * @brief ADC memory and pointer classes.
 */
#define ADC_CODE
#define ADC_CODE_FAST
#define ADC_CONST
#define ADC_CONFIG_DATA
#define ADC_APPL_DATA
#define ADC_APPL_CONST
#define ADC_APPL_CODE
#define ADC_VAR_NOINIT
#define ADC_VAR_CLEARD
#define ADC_VAR_POWER_ON_CLEARD
#define ADC_VAR_INIT
#define ADC_VAR_POWER_ON_INIT
#define ADC_VAR

/**
 * @brief CAN memory and pointer classes.
 */
#define CAN_CODE
#define CAN_CODE_FAST
#define CAN_CONST
#define CAN_CONFIG_DATA
#define CAN_APPL_DATA
#define CAN_APPL_CONST
#define CAN_APPL_CODE
#define CAN_VAR_NOINIT
#define CAN_VAR_CLEARD
#define CAN_VAR_POWER_ON_CLEARD
#define CAN_VAR_INIT
#define CAN_VAR_POWER_ON_INIT
#define CAN_VAR

/**
 * @brief CANIF memory and pointer classes.
 */
#define CANIF_CODE
#define CANIF_CODE_FAST
#define CANIF_CONST
#define CANIF_CONFIG_DATA
#define CANIF_APPL_DATA
#define CANIF_APPL_CONST
#define CANIF_APPL_CODE
#define CANIF_VAR_NOINIT
#define CANIF_VAR_CLEARD
#define CANIF_VAR_POWER_ON_CLEARD
#define CANIF_VAR_INIT
#define CANIF_VAR_POWER_ON_INIT
#define CANIF_VAR

/**
 * @brief DEM memory and pointer classes.
 */
#define DEM_CODE
#define DEM_CODE_FAST
#define DEM_CONST
#define DEM_CONFIG_DATA
#define DEM_APPL_DATA
#define DEM_APPL_CONST
#define DEM_APPL_CODE
#define DEM_VAR_NOINIT
#define DEM_VAR_CLEARD
#define DEM_VAR_POWER_ON_CLEARD
#define DEM_VAR_INIT
#define DEM_VAR_POWER_ON_INIT
#define DEM_VAR

/**
 * @brief DET memory and pointer classes.
 */
#define DET_CODE
#define DET_CODE_FAST
#define DET_CONST
#define DET_CONFIG_DATA
#define DET_APPL_DATA
#define DET_APPL_CONST
#define DET_APPL_CODE
#define DET_VAR_NOINIT
#define DET_VAR_CLEARD
#define DET_VAR_POWER_ON_CLEARD
#define DET_VAR_INIT
#define DET_VAR_POWER_ON_INIT
#define DET_VAR

/**
 * @brief DIO memory and pointer classes.
 */
#define DIO_CODE
#define DIO_CODE_FAST
#define DIO_CONST
#define DIO_CONFIG_DATA
#define DIO_APPL_DATA
#define DIO_APPL_CONST
#define DIO_APPL_CODE
#define DIO_VAR_NOINIT
#define DIO_VAR_CLEARD
#define DIO_VAR_POWER_ON_CLEARD
#define DIO_VAR_INIT
#define DIO_VAR_POWER_ON_INIT
#define DIO_VAR

/**
 * @brief ETH memory and pointer classes.
 */
#define ETH_CODE
#define ETH_CODE_FAST
#define ETH_CONST
#define ETH_CONFIG_DATA
#define ETH_APPL_DATA
#define ETH_APPL_CONST
#define ETH_APPL_CODE
#define ETH_VAR_NOINIT
#define ETH_VAR_CLEARD
#define ETH_VAR_POWER_ON_CLEARD
#define ETH_VAR_INIT
#define ETH_VAR_POWER_ON_INIT
#define ETH_VAR

/**
 * @brief ETHIF memory and pointer classes.
 */
#define ETHIF_CODE
#define ETHIF_CODE_FAST
#define ETHIF_CONST
#define ETHIF_CONFIG_DATA
#define ETHIF_APPL_DATA
#define ETHIF_APPL_CONST
#define ETHIF_APPL_CODE
#define ETHIF_VAR_NOINIT
#define ETHIF_VAR_CLEARD
#define ETHIF_VAR_POWER_ON_CLEARD
#define ETHIF_VAR_INIT
#define ETHIF_VAR_POWER_ON_INIT
#define ETHIF_VAR

/**
 * @brief FEE memory and pointer classes.
 */
#define FEE_CODE
#define FEE_CODE_FAST
#define FEE_CONST
#define FEE_CONFIG_DATA
#define FEE_APPL_DATA
#define FEE_APPL_CONST
#define FEE_APPL_CODE
#define FEE_VAR_NOINIT
#define FEE_VAR_CLEARD
#define FEE_VAR_POWER_ON_CLEARD
#define FEE_VAR_INIT
#define FEE_VAR_POWER_ON_INIT
#define FEE_VAR

/**
 * @brief FLS memory and pointer classes.
 */
#define FLS_CODE
#define FLS_CODE_FAST
#define FLS_CONST
#define FLS_CONFIG_DATA
#define FLS_APPL_DATA
#define FLS_APPL_CONST
#define FLS_APPL_CODE
#define FLS_VAR_NOINIT
#define FLS_VAR_CLEARD
#define FLS_VAR_POWER_ON_CLEARD
#define FLS_VAR_INIT
#define FLS_VAR_POWER_ON_INIT
#define FLS_VAR

/**
 * @brief GPT memory and pointer classes.
 */
#define GPT_CODE
#define GPT_CODE_FAST
#define GPT_CONST
#define GPT_CONFIG_DATA
#define GPT_APPL_DATA
#define GPT_APPL_CONST
#define GPT_APPL_CODE
#define GPT_VAR_NOINIT
#define GPT_VAR_CLEARD
#define GPT_VAR_POWER_ON_CLEARD
#define GPT_VAR_INIT
#define GPT_VAR_POWER_ON_INIT
#define GPT_VAR

/**
 * @brief ICU memory and pointer classes.
 */
#define ICU_CODE
#define ICU_CODE_FAST
#define ICU_CONST
#define ICU_CONFIG_DATA
#define ICU_APPL_DATA
#define ICU_APPL_CONST
#define ICU_APPL_CODE
#define ICU_VAR_NOINIT
#define ICU_VAR_CLEARD
#define ICU_VAR_POWER_ON_CLEARD
#define ICU_VAR_INIT
#define ICU_VAR_POWER_ON_INIT
#define ICU_VAR

/**
 * @brief LIN memory and pointer classes.
 */
#define LIN_CODE
#define LIN_CODE_FAST
#define LIN_CONST
#define LIN_CONFIG_DATA
#define LIN_APPL_DATA
#define LIN_APPL_CONST
#define LIN_APPL_CODE
#define LIN_VAR_NOINIT
#define LIN_VAR_CLEARD
#define LIN_VAR_POWER_ON_CLEARD
#define LIN_VAR_INIT
#define LIN_VAR_POWER_ON_INIT
#define LIN_VAR

/**
 * @brief LINIF memory and pointer classes.
 */
#define LINIF_CODE
#define LINIF_CODE_FAST
#define LINIF_CONST
#define LINIF_CONFIG_DATA
#define LINIF_APPL_DATA
#define LINIF_APPL_CONST
#define LINIF_APPL_CODE
#define LINIF_VAR_NOINIT
#define LINIF_VAR_CLEARD
#define LINIF_VAR_POWER_ON_CLEARD
#define LINIF_VAR_INIT
#define LINIF_VAR_POWER_ON_INIT
#define LINIF_VAR

/**
 * @brief MCU memory and pointer classes.
 */
#define MCU_CODE
#define MCU_CODE_FAST
#define MCU_CONST
#define MCU_CONFIG_DATA
#define MCU_APPL_DATA
#define MCU_APPL_CONST
#define MCU_APPL_CODE
#define MCU_VAR_NOINIT
#define MCU_VAR_CLEARD
#define MCU_VAR_POWER_ON_CLEARD
#define MCU_VAR_INIT
#define MCU_VAR_POWER_ON_INIT
#define MCU_VAR

/**
 * @brief OCU memory and pointer classes.
 */
#define OCU_CODE
#define OCU_CODE_FAST
#define OCU_CONST
#define OCU_CONFIG_DATA
#define OCU_APPL_DATA
#define OCU_APPL_CONST
#define OCU_APPL_CODE
#define OCU_VAR_NOINIT
#define OCU_VAR_CLEARD
#define OCU_VAR_POWER_ON_CLEARD
#define OCU_VAR_INIT
#define OCU_VAR_POWER_ON_INIT
#define OCU_VAR

/**
 * @brief PORT memory and pointer classes.
 */
#define PORT_CODE
#define PORT_CODE_FAST
#define PORT_CONST
#define PORT_CONFIG_DATA
#define PORT_APPL_DATA
#define PORT_APPL_CONST
#define PORT_APPL_CODE
#define PORT_VAR_NOINIT
#define PORT_VAR_CLEARD
#define PORT_VAR_POWER_ON_CLEARD
#define PORT_VAR_INIT
#define PORT_VAR_POWER_ON_INIT
#define PORT_VAR

/**
 * @brief PWM memory and pointer classes.
 */
#define PWM_CODE
#define PWM_CODE_FAST
#define PWM_CONST
#define PWM_CONFIG_DATA
#define PWM_APPL_DATA
#define PWM_APPL_CONST
#define PWM_APPL_CODE
#define PWM_VAR_NOINIT
#define PWM_VAR_CLEARD
#define PWM_VAR_POWER_ON_CLEARD
#define PWM_VAR_INIT
#define PWM_VAR_POWER_ON_INIT
#define PWM_VAR

/**
 * @brief RAMTST memory and pointer classes.
 */
#define RAMTST_CODE
#define RAMTST_CODE_FAST
#define RAMTST_CONST
#define RAMTST_CONFIG_DATA
#define RAMTST_APPL_DATA
#define RAMTST_APPL_CONST
#define RAMTST_APPL_CODE
#define RAMTST_VAR_NOINIT
#define RAMTST_VAR_CLEARD
#define RAMTST_VAR_POWER_ON_CLEARD
#define RAMTST_VAR_INIT
#define RAMTST_VAR_POWER_ON_INIT
#define RAMTST_VAR

/**
 * @brief SCHM memory and pointer classes.
 */
#define SCHM_CODE
#define SCHM_CODE_FAST
#define SCHM_CONST
#define SCHM_CONFIG_DATA
#define SCHM_APPL_DATA
#define SCHM_APPL_CONST
#define SCHM_APPL_CODE
#define SCHM_VAR_NOINIT
#define SCHM_VAR_CLEARD
#define SCHM_VAR_POWER_ON_CLEARD
#define SCHM_VAR_INIT
#define SCHM_VAR_POWER_ON_INIT
#define SCHM_VAR

/**
 * @brief SPI memory and pointer classes.
 */
#define SPI_CODE
#define SPI_CODE_FAST
#define SPI_CONST
#define SPI_CONFIG_DATA
#define SPI_APPL_DATA
#define SPI_APPL_CONST
#define SPI_APPL_CODE
#define SPI_VAR_NOINIT
#define SPI_VAR_CLEARD
#define SPI_VAR_POWER_ON_CLEARD
#define SPI_VAR_INIT
#define SPI_VAR_POWER_ON_INIT
#define SPI_VAR

/**
 * @brief WDG memory and pointer classes.
 */
#define WDG_CODE
#define WDG_CODE_FAST
#define WDG_CONST
#define WDG_CONFIG_DATA
#define WDG_APPL_DATA
#define WDG_APPL_CONST
#define WDG_APPL_CODE
#define WDG_VAR_NOINIT
#define WDG_VAR_CLEARD
#define WDG_VAR_POWER_ON_CLEARD
#define WDG_VAR_INIT
#define WDG_VAR_POWER_ON_INIT
#define WDG_VAR

/**
 * @brief WDGIF memory and pointer classes.
 */
#define WDGIF_CODE
#define WDGIF_CODE_FAST
#define WDGIF_CONST
#define WDGIF_CONFIG_DATA
#define WDGIF_APPL_DATA
#define WDGIF_APPL_CONST
#define WDGIF_APPL_CODE
#define WDGIF_VAR_NOINIT
#define WDGIF_VAR_CLEARD
#define WDGIF_VAR_POWER_ON_CLEARD
#define WDGIF_VAR_INIT
#define WDGIF_VAR_POWER_ON_INIT
#define WDGIF_VAR

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

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

/** @} end of group Compiler_Cfg */

/** @} end of group Base_Module */

#endif /* COMPILER_CFG_H */
