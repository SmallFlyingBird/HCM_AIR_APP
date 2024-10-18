/**************************************************************************************************/
/**
 * @file      : Spi_Drvw_Cfg.h  
 * @brief     : Spi driver wrapper - Pre-Compile(PC) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef SPI_DRVW_CFG_H
#define SPI_DRVW_CFG_H

/** @addtogroup Spi_Module
 *  @{
 */

/** @addtogroup Spi_Drvw_Configuration
 *  @brief Spi driver wrapper configuration
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif
#include "Spi_Drvw_PBcfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define SPI_DRVW_CFG_H_VENDOR_ID                   0x00B3U
#define SPI_DRVW_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define SPI_DRVW_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define SPI_DRVW_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define SPI_DRVW_CFG_H_SW_MAJOR_VERSION            1U
#define SPI_DRVW_CFG_H_SW_MINOR_VERSION            2U
#define SPI_DRVW_CFG_H_SW_PATCH_VERSION            1U

/* Check if current file and Spi_Drvw_PBcfg.h are the same vendor */
#if (SPI_DRVW_CFG_H_VENDOR_ID != SPI_DRVW_PBCFG_H_VENDOR_ID)
    #error "Vendor ID of Spi_Drvw_Cfg.h and Spi_Drvw_PBcfg.h are different"
#endif
    /* Check if current file and Spi_Drvw_PBcfg.h are the same Autosar version */
#if ((SPI_DRVW_CFG_H_AR_RELEASE_MAJOR_VERSION != SPI_DRVW_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_DRVW_CFG_H_AR_RELEASE_MINOR_VERSION != SPI_DRVW_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
     (SPI_DRVW_CFG_H_AR_RELEASE_REVISION_VERSION != SPI_DRVW_PBCFG_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Spi_Drvw_Cfg.h and Spi_Drvw_PBcfg.h are different"
#endif
/* Check if current file and Spi_Drvw_PBcfg.h are the same software version */
#if ((SPI_DRVW_CFG_H_SW_MAJOR_VERSION != SPI_DRVW_PBCFG_H_SW_MAJOR_VERSION) || \
     (SPI_DRVW_CFG_H_SW_MINOR_VERSION != SPI_DRVW_PBCFG_H_SW_MINOR_VERSION) || \
     (SPI_DRVW_CFG_H_SW_PATCH_VERSION != SPI_DRVW_PBCFG_H_SW_PATCH_VERSION))
#error "Software Version of Spi_Drvw_Cfg.h and Spi_Drvw_PBcfg.h are different"
#endif

/** 
 * @brief Defines SPI Driver Wrapper configuration.
 */
#define SPI_DRVW_CONFIG_EXT \
    SPI_DRVW_CONFIG_PB

/**
 * @brief Switches development error detect ON or OFF.
 */
#define SPI_DRVW_DEV_ERROR_DETECT    (STD_ON)

/**
 * @brief Simple Synchronous SPI Handler/Driver.
 */
#define LEVEL0 (0U)

/**
 * @brief Basic Asynchronous SPI Handler/Driver.
 */
#define LEVEL1 (1U)

/**
 * @brief Enhanced (Synchronous or Asynchronous) SPI Handler/Driver.
 */
#define LEVEL2 (2U)

/**
 * @brief Selects the 3 level of Scalable Functionality for the SPI Handler/Driver.
 */
#define SPI_DRVW_LEVEL_DELIVERED            (LEVEL2)

/**
 * @brief Switches the Spi_Cancel function ON or OFF for driver wrapper layer.
 */
#define SPI_DRVW_CANCEL_API    (STD_ON)

/**
 * @brief Total number of SpiPhyUnit configured.
 */
#define SPI_DRVW_MAX_HWUNITS_CFG    (2U)

/** 
 * @brief Defines if Slave support or not.
 */
#define SPI_DRVW_SLAVE_SUPPORT    (SPI_DRV_SLAVE_SUPPORT)

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

/** @} end of group Spi_Drvw_Configuration */

/** @} end of group Spi_Module */

#endif 
