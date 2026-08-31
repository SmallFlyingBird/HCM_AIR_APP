/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file undefined
 * @brief 
 * 
 */


#ifndef SPI_PB_CFG_H
#define SPI_PB_CFG_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_VENDOR_ID_PBCFG                      (180)
#define SPI_AR_RELEASE_MAJOR_VERSION_PBCFG       (4)
#define SPI_AR_RELEASE_MINOR_VERSION_PBCFG       (4)
#define SPI_AR_RELEASE_REVISION_VERSION_PBCFG    (0)
#define SPI_SW_MAJOR_VERSION_PBCFG               (2)
#define SPI_SW_MINOR_VERSION_PBCFG               (3)
#define SPI_SW_PATCH_VERSION_PBCFG               (0)

/**
 * @brief        This parameter contains the number of Channels configured. It will be gathered by tools during the configuration stage.
 * @details      Defines the maximum number of supported channels for all the driver configurations.
 *
 * @ref          ECUC_Spi_00197
 */
#define SpiConf_SpiChannel_SpiChannel_0             ((Spi_ChannelType)0U)
#define SPI_MAX_CHANNEL                             (1U)

/**
 * @brief        Total number of Jobs configured.
 * @details      Defines the maximum number of supported jobs for all the driver configurations.
 *
 * @ref          ECUC_Spi_00198
 */
#define SpiConf_SpiJob_SpiJob_Buck1                     ((Spi_JobType)0U)
#define SpiConf_SpiJob_SpiJob_Buck2                     ((Spi_JobType)1U)
#define SPI_MAX_JOB                                 (2U)

/**
 * @brief        Total number of Sequences configured.
 * @details      Defines the maximum number of supported sequences for all the driver configurations.
 *
 * @ref          ECUC_Spi_00199
 */
#define SpiConf_SpiSequence_SpiSequence_0           ((Spi_SequenceType)0U)
#define SpiConf_SpiSequence_SpiSequence_1           ((Spi_SequenceType)1U)
#define SPI_MAX_SEQUENCE                            (2U)

/**
 * @brief        Total number of Spi HW Units configured.
 * @details      Defines the maximum number of supported HW units for all the driver configurations.
 */
#define CSIB0                                       ((uint8)0U)
#define SPI_MAX_HWUNIT                              (1U)

#define SPI_CONFIG_PB \
    extern const Spi_ConfigType Spi_Config;

#endif

