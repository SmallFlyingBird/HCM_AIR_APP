/**************************************************************************************************/
/**
 * @file      : Spi_Drv_Cfg.h  
 * @brief     : Spi low level driver - Pre-Compile(PC) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef SPI_DRV_CFG_H
#define SPI_DRV_CFG_H

/** @addtogroup Spi_Module
 *  @{
 */

/** @addtogroup Spi_Configuration
 *  @brief Spi low level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif
#include "Spi_Drv_PBcfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define SPI_DRV_CFG_H_VENDOR_ID                   0x00B3U
#define SPI_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define SPI_DRV_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define SPI_DRV_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define SPI_DRV_CFG_H_SW_MAJOR_VERSION            1U
#define SPI_DRV_CFG_H_SW_MINOR_VERSION            2U
#define SPI_DRV_CFG_H_SW_PATCH_VERSION            2U

/* Check if current file and Spi_Drv_PBcfg.h are the same vendor */
#if (SPI_DRV_CFG_H_VENDOR_ID != SPI_DRV_PBCFG_H_VENDOR_ID)
    #error "Vendor ID of Spi_Drv_Cfg.h and Spi_Drv_PBcfg.h are different"
#endif
    /* Check if current file and Spi_Drv_PBcfg.h are the same Autosar version */
#if ((SPI_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION != SPI_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_DRV_CFG_H_AR_RELEASE_MINOR_VERSION != SPI_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
     (SPI_DRV_CFG_H_AR_RELEASE_REVISION_VERSION != SPI_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version of Spi_Drv_Cfg.h and Spi_Drv_PBcfg.h are different"
#endif
/* Check if current file and Spi_Drv_PBcfg.h are the same software version */
#if ((SPI_DRV_CFG_H_SW_MAJOR_VERSION != SPI_DRV_PBCFG_H_SW_MAJOR_VERSION) || \
     (SPI_DRV_CFG_H_SW_MINOR_VERSION != SPI_DRV_PBCFG_H_SW_MINOR_VERSION) || \
     (SPI_DRV_CFG_H_SW_PATCH_VERSION != SPI_DRV_PBCFG_H_SW_PATCH_VERSION))
#error "Software Version of Spi_Drv_Cfg.h and Spi_Drv_PBcfg.h are different"
#endif

/**
 * @brief Defines SPI Driver configuration.
 */
#define SPI_DRV_CONFIG_EXT \
    SPI_DRV_CONFIG_PB

/**
 * @brief Defines total number of SpiPhyUnit.
 */
#define SPI_DRV_HWUNITS_COUNT           (4U)

/**
 * @brief Defines number of configured SpiPhyUnit .
 */
#define SPI_DRV_MAX_CFG_HWUNITS     (2U)

/**
 * @brief Defines number of configured External Devices.
 */
#define SPI_DRV_MAX_CFG_DEVICES    (3U)

/**
 * @brief Defines FIFO size.
 */
#define SPI_DRV_FIFO_SIZE    ((uint8)4U)

/** 
 * @brief Defines HW Units enable or not.
 */
#define SPI_DRV_0_ENABLE    (STD_OFF)
#define SPI_DRV_1_ENABLE    (STD_ON)
#define SPI_DRV_2_ENABLE    (STD_OFF)
#define SPI_DRV_3_ENABLE    (STD_ON)

/** 
 * @brief Defines if Slave support or not.
 */
#define SPI_DRV_SLAVE_SUPPORT    (STD_OFF)

/**
 * @brief Defines if DMA or FIFO is used.
 * @details As long as Dma is enabled by one SPI HWUnit, SPI_DRV_DMA_USED will be STD_ON.
 */
#define SPI_DRV_DMA_USED    (STD_OFF)


/**
 * @brief Define Timeout Method from McalLib.
 */
#define SPI_DRV_TIMEOUT_METHOD           (MCALLIB_COUNTER_SOFTWARE)

/**
 * @brief Switches development error detect ON or OFF.
 */
#define SPI_DRV_DEV_ERROR_DETECT    (STD_ON)

/**
* @brief Defines the timeout counter.
*/
#define SPI_DRV_TIMEOUT_COUNTER     ((uint32)(10000))

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

/** @} end of group Spi_Drv_Configuration */

/** @} end of group Spi_Module */

#endif 
