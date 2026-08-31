/*
* @file    Spi_Lld.h
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Spi_Lld
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V2.3.0
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

#ifndef SPI_LLD_H
#define SPI_LLD_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"

/*==================================================================================================
                                      HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_LLD_VENDOR_ID                      (180)
#define SPI_LLD_AR_RELEASE_MAJOR_VERSION       (4)
#define SPI_LLD_AR_RELEASE_MINOR_VERSION       (4)
#define SPI_LLD_AR_RELEASE_REVISION_VERSION    (0)
#define SPI_LLD_SW_MAJOR_VERSION               (2)
#define SPI_LLD_SW_MINOR_VERSION               (3)
#define SPI_LLD_SW_PATCH_VERSION               (0)

/*==================================================================================================
                                                ENUMS
==================================================================================================*/

/*==================================================================================================
                                                DEFINES AND MACROS
==================================================================================================*/

#define SPI_FUNCTION_CLK_DIV_COUNT                  (8U)
#define SPI_MAX_SCALER_VALUE                        (256U)
#define SPI_HW_UNIT_TRANSMIT_FINISHED               (0xFFU)
#define SPI_SCALER_OFFSET                           (2U)

/*==================================================================================================
                                                EXTERNAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                                FUNCTION PROTOTYPES
==================================================================================================*/

Std_ReturnType Spi_Lld_DeInit(uint8 Instance);

Std_ReturnType  Spi_Lld_GlobalStateInit(Spi_HWUnitType HWUnit);

void Spi_Lld_SetPcsPolarityMode(const Spi_ConfigType *ConfigPtr, Spi_JobType JobId);

#if (SPI_LEVEL_DELIVERED == LEVEL0 || SPI_LEVEL_DELIVERED == LEVEL2)
Std_ReturnType Spi_Lld_SyncTransmit(Spi_SequenceType Sequence);
#endif /*#if (SPI_LEVEL_DELIVERED == LEVEL0 || SPI_LEVEL_DELIVERED == LEVEL2)*/

#if (SPI_LEVEL_DELIVERED == LEVEL2)
void Spi_Lld_SetAsyncMode(const Spi_HWUnitType HwUnit, Spi_AsyncModeType Mode);
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
void Spi_Lld_IrqPolling(uint8 Instance);
#endif

#if ((SPI_SLAVE_SUPPORT == STD_ON) && (SPI_CANCEL_API == STD_ON))
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
void Spi_Lld_SlaveCancel(const Spi_JobConfigType *JobConfig);
#endif /*#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))*/
#endif /*#if ((SPI_SLAVE_SUPPORT == STD_ON) && (SPI_CANCEL_API == STD_ON))*/

#ifdef __cplusplus
}
#endif

#endif /* End of file Spi_Lld.h */

