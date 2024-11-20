/**************************************************************************************************/
/**
 * @file      : Spi_Cfg.h  
 * @brief     : Spi AUTOSAR level - Pre-Compile(PC) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef SPI_CFG_H
#define SPI_CFG_H

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
#include "Spi_PBcfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define SPI_CFG_H_VENDOR_ID                   0x00B3U
#define SPI_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define SPI_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define SPI_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define SPI_CFG_H_SW_MAJOR_VERSION            1U
#define SPI_CFG_H_SW_MINOR_VERSION            2U
#define SPI_CFG_H_SW_PATCH_VERSION            2U

/* Check if current file and Spi_PBcfg.h are the same vendor */
#if (SPI_CFG_H_VENDOR_ID != SPI_PBCFG_H_VENDOR_ID)
    #error "Vendor ID of Spi_Cfg.h and Spi_PBcfg.h are different."
#endif
/* Check if current file and Spi_PBcfg.h are the same Autosar version */
#if ((SPI_CFG_H_AR_RELEASE_MAJOR_VERSION != SPI_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_CFG_H_AR_RELEASE_MINOR_VERSION != SPI_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
     (SPI_CFG_H_AR_RELEASE_REVISION_VERSION != SPI_PBCFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Spi_Cfg.h and Spi_PBcfg.h are different"
#endif
/* Check if current file and Spi_PBcfg.h are the same software version */
#if ((SPI_CFG_H_SW_MAJOR_VERSION != SPI_PBCFG_H_SW_MAJOR_VERSION) || \
     (SPI_CFG_H_SW_MINOR_VERSION != SPI_PBCFG_H_SW_MINOR_VERSION) || \
     (SPI_CFG_H_SW_PATCH_VERSION != SPI_PBCFG_H_SW_PATCH_VERSION))
    #error "Software Version of Spi_Cfg.h and Spi_PBcfg.h are different"
#endif

/**
* @brief Defines SPI configuration
*/
#define SPI_CONFIG_EXT \
    SPI_CONFIG_PB

/**
 * @brief Switches the development error ON or OFF.
 */
#define SPI_DEV_ERROR_DETECT    (STD_ON)

/**
 * @brief Switches the Version Information API functionality ON or OFF.
 */
#define SPI_VERSION_INFO_API    (STD_OFF)

/**
 * @brief Switches the Interruptible Sequences handling functionality ON or OFF.
 * @details This parameter depends on SPI_LEVEL_DELIVERED value.
 *        It is only used for SPI_LEVEL_DELIVERED configured to 1 or 2.
 */
#define SPI_INTERRUPTIBLE_SEQ_ALLOWED    (STD_OFF)

/**
 * @brief Switches the Spi_GetHWUnitStatus function ON or OFF.
 */
#define SPI_HW_STATUS_API    (STD_ON)

/**
 * @brief Switches the Spi_Cancel function ON or OFF.
 */
#define SPI_CANCEL_API    (SPI_DRVW_CANCEL_API)

/**
 * @brief Selects the SPI Handler Driver Channel Buffers usage allowed and delivered.
 */
#define SPI_CHANNEL_BUFFERS_ALLOWED    (USAGE2)

/**
 * @brief Selects the 3 level of Scalable Functionality for the SPI Handler/Driver.
 */
#define SPI_LEVEL_DELIVERED            (SPI_DRVW_LEVEL_DELIVERED)

/**
 * @brief Defines the maximum number of supported channels.
 */
#define SPI_MAX_CFG_CHANNELS  (7U)

/**
 * @brief Symbolic channels names configured.
 */
#define SpiConf_SpiChannel_SpiChannel_Boost    ((Spi_ChannelType)0U)
#define SpiConf_SpiChannel_SpiChannel_Buck1    ((Spi_ChannelType)1U)
#define SpiConf_SpiChannel_SpiChannel_Buck2    ((Spi_ChannelType)2U)
#define SpiConf_SpiChannel_SpiChannel_Buck3    ((Spi_ChannelType)3U)
#define SpiConf_SpiChannel_SpiChannel_Buck4    ((Spi_ChannelType)4U)
#define SpiConf_SpiChannel_SpiChannel_Motor1    ((Spi_ChannelType)5U)
#define SpiConf_SpiChannel_SpiChannel_Motor2    ((Spi_ChannelType)6U)

/**
 * @brief Defines total number of Jobs configured.
 */
#define SPI_MAX_CFG_JOBS     (7U)

/**
 * @brief Symbolic jobs names configured.
 */
#define SpiConf_SpiJob_SpiJob_Boost    ((Spi_JobType)0U)
#define SpiConf_SpiJob_SpiJob_Buck1    ((Spi_JobType)1U)
#define SpiConf_SpiJob_SpiJob_Buck2    ((Spi_JobType)2U)
#define SpiConf_SpiJob_SpiJob_Buck3    ((Spi_JobType)3U)
#define SpiConf_SpiJob_SpiJob_Buck4    ((Spi_JobType)4U)
#define SpiConf_SpiJob_SpiJob_Motor1    ((Spi_JobType)5U)
#define SpiConf_SpiJob_SpiJob_Motor2    ((Spi_JobType)6U)

/**
 * @brief Defines total number of Sequences configured.
 */
#define SPI_MAX_CFG_SEQUENCES    (7U)

/**
 * @brief Symbolic sequences names configured.
 */
#define SpiConf_SpiSequence_SpiSequence_Boost    ((Spi_SequenceType)0U)
#define SpiConf_SpiSequence_SpiSequence_Buck1    ((Spi_SequenceType)1U)
#define SpiConf_SpiSequence_SpiSequence_Buck2    ((Spi_SequenceType)2U)
#define SpiConf_SpiSequence_SpiSequence_Buck3    ((Spi_SequenceType)3U)
#define SpiConf_SpiSequence_SpiSequence_Buck4    ((Spi_SequenceType)4U)
#define SpiConf_SpiSequence_SpiSequence_Motor1    ((Spi_SequenceType)5U)
#define SpiConf_SpiSequence_SpiSequence_Motor2    ((Spi_SequenceType)6U)

/**
 * @brief Defines the SPI peripherals configured.
 */
#define CSIB0    ((uint8)0U)
#define CSIB1    ((uint8)1U)

/**
 * @brief Total number of SpiPhyUnit configured.
 */
#define SPI_MAX_CFG_HWUNITS    (SPI_DRVW_MAX_HWUNITS_CFG)

/**
 * @brief Defines the external devices configured.
 */
#define SPI_EXTERNAL_DEVICE_CONF_BD18397    ((Spi_ExternalDeviceType)0U)
#define SPI_EXTERNAL_DEVICE_CONF_TPS92682    ((Spi_ExternalDeviceType)1U)
#define SPI_EXTERNAL_DEVICE_CONF_DRV8889    ((Spi_ExternalDeviceType)2U)

/**
* @brief Define precompile support.
*/
#define SPI_PRECOMPILE_SUPPORT      (STD_OFF)

/**
* @brief Allow simultaneous calls to Spi_SyncTransmit() for different threads.
*/
#define SPI_CONCURRENT_SYNC_TRANSMIT_SUPPORT    (STD_OFF)

/**
 * @brief Asyncronous operation mode (POLLING or INTERRUPT)
 * @details If enabled, the asyncronous operation mode (POLLING or INTERRUPT) can
 *       be defined independently for each HWUnit using Spi_SetHWUnitAsyncMode().
 */
#define SPI_HWUNIT_ASYNC_MODE    (STD_OFF)


/**
 * @brief Total number of partitions configured in Ecu.
 */
#define SPI_MAX_PARTITIONS    (1U)

/**
 * @brief   The number of allowed job priority levels (0..3), The Priority is sint8.
 */
#define SPI_JOB_PRIORITY_LEVELS_COUNT    (4U)

/**
 * @brief Defines Get SPI Core ID.
 */
#define Spi_GetCoreID()     ((uint32)McalLib_GetCoreID())

/**
* @brief  Defines if Slave support or not
*/
#define SPI_SLAVE_SUPPORT   (SPI_DRVW_SLAVE_SUPPORT)


/**
* @brief Defines SPI_E_HARDWARE_ERROR enable or not
*/
#define SPI_E_HARDWARE_ERROR_ENABLE    (STD_OFF)


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

/** @} end of group Spi_Configuration */

/** @} end of group Spi_Module */

#endif /*SPI_CFG_H*/
