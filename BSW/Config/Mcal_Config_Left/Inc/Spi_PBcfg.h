/**************************************************************************************************/
/**
 * @file      : Spi_PBcfg.h
 * @brief     : Spi AUTOSAR level - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef SPI_PBCFG_H
#define SPI_PBCFG_H

/** @addtogroup Spi_Module
 *  @{
 */

/** @addtogroup Spi_Configuration
 *  @brief Spi AUTOSAR level configuration
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define SPI_PBCFG_H_VENDOR_ID                   0x00B3U
#define SPI_PBCFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define SPI_PBCFG_H_AR_RELEASE_MINOR_VERSION    6U
#define SPI_PBCFG_H_AR_RELEASE_REVISION_VERSION 0U
#define SPI_PBCFG_H_SW_MAJOR_VERSION            1U
#define SPI_PBCFG_H_SW_MINOR_VERSION            2U
#define SPI_PBCFG_H_SW_PATCH_VERSION            1U

/**
 * @brief Defines SPI configuration
 */
#define SPI_CONFIG_PB \
    extern const Spi_ConfigType Spi_Config;

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
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"


/**
* @brief Job Start Notification for Job 'SpiJob_Boost'
*/
extern void SpiJob_BoostStart(void);

/**
* @brief Job Start Notification for Job 'SpiJob_Buck1'
*/
extern void SpiJob_Buck1Start(void);

/**
* @brief Job Start Notification for Job 'SpiJob_Buck2'
*/
extern void SpiJob_Buck2Start(void);

/**
* @brief Job Start Notification for Job 'SpiJob_Buck3'
*/
extern void SpiJob_Buck3Start(void);

/**
* @brief Job Start Notification for Job 'SpiJob_Buck4'
*/
extern void SpiJob_Buck4Start(void);

/**
* @brief Job Start Notification for Job 'SpiJob_Motor1'
*/
extern void SpiJob_Motor1Start(void);

/**
* @brief Job Start Notification for Job 'SpiJob_Motor2'
*/
extern void SpiJob_Motor2Start(void);

/**
* @brief Job End Notification for Job 'SpiJob_Boost'
*/
extern void SpiJob_BoostEnd(void);

/**
* @brief Job End Notification for Job 'SpiJob_Buck1'
*/
extern void SpiJob_Buck1End(void);

/**
* @brief Job End Notification for Job 'SpiJob_Buck2'
*/
extern void SpiJob_Buck2End(void);

/**
* @brief Job End Notification for Job 'SpiJob_Buck3'
*/
extern void SpiJob_Buck3End(void);

/**
* @brief Job End Notification for Job 'SpiJob_Buck4'
*/
extern void SpiJob_Buck4End(void);

/**
* @brief Job End Notification for Job 'SpiJob_Motor1'
*/
extern void SpiJob_Motor1End(void);

/**
* @brief Job End Notification for Job 'SpiJob_Motor2'
*/
extern void SpiJob_Motor2End(void);


#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Spi_Configuration */

/** @} end of group Spi_Module */

#endif
