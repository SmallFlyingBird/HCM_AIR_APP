/**************************************************************************************************/
/**
 * @file      : Spi_Drv_PBcfg.h
 * @brief     : Spi low level driver - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef SPI_DRV_PBCFG_H
#define SPI_DRV_PBCFG_H

/** @addtogroup Spi_Module
 *  @{
 */

/** @addtogroup Spi_Drv_Configuration
 *  @brief Spi low level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define SPI_DRV_PBCFG_H_VENDOR_ID                   0x00B3U
#define SPI_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define SPI_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION    6U
#define SPI_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION 0U
#define SPI_DRV_PBCFG_H_SW_MAJOR_VERSION            1U
#define SPI_DRV_PBCFG_H_SW_MINOR_VERSION            2U
#define SPI_DRV_PBCFG_H_SW_PATCH_VERSION            2U

/**
 * @brief Defines SPI Driver Configuration
 */
#define SPI_DRV_CONFIG_PB \
    extern const Spi_Drv_ExternalDeviceType Spi_Drv_ExternalDeviceConfig_BD18397; \
    extern const Spi_Drv_ExternalDeviceType Spi_Drv_ExternalDeviceConfig_TPS92682; \
    extern const Spi_Drv_ExternalDeviceType Spi_Drv_ExternalDeviceConfig_DRV8889; \
    extern const Spi_Drv_PhyUnitConfigType Spi_Drv_PhyUnitConfig_SpiPhyUnit_BoostBuck; \
    extern const Spi_Drv_PhyUnitConfigType Spi_Drv_PhyUnitConfig_SpiPhyUnit_Motor; \

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
