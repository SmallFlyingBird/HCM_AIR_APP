/**************************************************************************************************/
/**
 * @file      : Spi_Drvw_PBcfg.h
 * @brief     : Spi driver wrapper - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef SPI_DRVW_PBCFG_H
#define SPI_DRVW_PBCFG_H

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

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define SPI_DRVW_PBCFG_H_VENDOR_ID                   0x00B3U
#define SPI_DRVW_PBCFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define SPI_DRVW_PBCFG_H_AR_RELEASE_MINOR_VERSION    6U
#define SPI_DRVW_PBCFG_H_AR_RELEASE_REVISION_VERSION 0U
#define SPI_DRVW_PBCFG_H_SW_MAJOR_VERSION            1U
#define SPI_DRVW_PBCFG_H_SW_MINOR_VERSION            2U
#define SPI_DRVW_PBCFG_H_SW_PATCH_VERSION            2U

/**
 * @brief Defines SPI Driver Wrapper Configuration
*/
#define SPI_DRVW_CONFIG_PB \
    extern const Spi_Drvw_ExternalDeviceListType Spi_ExternalDeviceConfigList[3U]; \
    extern const Spi_Drvw_HWUnitConfigListType Spi_HwUnitConfigList[SPI_DRVW_MAX_HWUNITS_CFG]; \

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
