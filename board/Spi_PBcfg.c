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


/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Spi_Cfg.h"
#include "Spi.h"
#if (SPI_DMA_USED == STD_ON)
#include "CddDma_Cfg.h"
#endif

#if (SPI_ENABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
#include "Dem.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_VENDOR_ID_PBCFG_C                      (180)
#define SPI_AR_RELEASE_MAJOR_VERSION_PBCFG_C       (4)
#define SPI_AR_RELEASE_MINOR_VERSION_PBCFG_C       (4)
#define SPI_AR_RELEASE_REVISION_VERSION_PBCFG_C    (0)
#define SPI_SW_MAJOR_VERSION_PBCFG_C               (2)
#define SPI_SW_MINOR_VERSION_PBCFG_C               (3)
#define SPI_SW_PATCH_VERSION_PBCFG_C               (0)

/*================================================================================================== */
#if (SPI_ENABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
/* Check if Spi_PBcfg.c file and Dem.h file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_PBCFG_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_AR_RELEASE_MINOR_VERSION_PBCFG_C != DEM_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Spi_PBcfg.c and Dem.h are different"
#endif
#endif

/*================================================================================================== 
*                              GLOBAL FUNCTIONS
==================================================================================================*/

/* List of Notification Functions*/
/* Job end notifications*/
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
SPI_FUNC extern void SpiJob_Buck1End(void); /*End Notification for SpiJob_0*/
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
SPI_FUNC extern void SpiJob_Buck2End(void); /*End Notification for SpiJob_1*/
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
SPI_FUNC extern void SpiJob_Buck1Start(void); /*Start Notification for SpiJob_0*/
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
SPI_FUNC extern void SpiJob_Buck2Start(void); /*Start Notification for SpiJob_1*/
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

/* Sequence end notifications*/
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
SPI_FUNC extern void Ex_Spi_MasterSequenceEndNotification0(void);/*End Notification for Sequence_0*/
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"
SPI_FUNC extern void Ex_Spi_MasterSequenceEndNotification1(void);/*End Notification for SpiJob_1*/
#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"



/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
#if ((SPI_DMA_USED == STD_ON) && ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
#define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
#define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Spi_MemMap.h"

/* Buffers Descriptors for EB Channels and Allocate Buffers for IB Channels */
SPI_VAR __attribute__((aligned(4))) static Spi_BufferDescriptorType Spi_EbDefaultBuffer_SpiChannel_SpiChannel_0;

#if ((SPI_DMA_USED == STD_ON) && ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_INIT_UNSPECIFIED
#include "Spi_MemMap.h"

/* Buffers Descriptors for IB Channels */

/* Channel Configuration */
SPI_VAR static Spi_ChannelConfigType Spi_ChannelConfigs[1] =
{
    /* Channel Configuration for SpiChannel_ID: 0*/
    {
        .BufferType = SPI_EB,
        .DataWidth = 24U,
        .Length =  40,
        .MsbOrLsbFirst = MSB_FIRST,
        .DefaultValue = 1U,
        .BufferDescriptorPtr = &Spi_EbDefaultBuffer_SpiChannel_SpiChannel_0,
    },
};

#define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Spi_MemMap.h"

#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

/* Channel Assignment of Jobs*/
/* Spi Job_ID: 0*/
SPI_CONST static const Spi_ChannelType Spi_Job_0_ChannelAssignment[1] =
{
    SpiConf_SpiChannel_SpiChannel_0,
};
/* Spi Job_ID: 1*/
SPI_CONST static const Spi_ChannelType Spi_Job_1_ChannelAssignment[1] =
{
    SpiConf_SpiChannel_SpiChannel_0,
};

/* Configuration of Jobs*/
SPI_CONST static const Spi_JobConfigType Spi_JobConfigs[2] =
{ 
    /* Job configuration for SpiJob_ID: 0*/
    {
        .HWUnit = (uint8)CSIB0,
        .ExternalDeviceId = 0U,
        .Priority = 0,
        .ChannelLinkPtr = Spi_Job_0_ChannelAssignment,
        .NumChannels = 1U,
        .JobEndNotification = SpiJob_Buck1End,
        .JobStartNotification = SpiJob_Buck1Start,
        .JobStatePtr = &Spi_JobState[0],
    },
    /* Job configuration for SpiJob_ID: 1*/
    {
        .HWUnit = (uint8)CSIB0,
        .ExternalDeviceId = 1U,
        .Priority = 0,
        .ChannelLinkPtr = Spi_Job_1_ChannelAssignment,
        .NumChannels = 1U,
        .JobEndNotification = SpiJob_Buck2End,
        .JobStartNotification = SpiJob_Buck2Start,
        .JobStatePtr = &Spi_JobState[1],
    },
};

/* Job Assignment of Sequence*/
/* Spi Sequence_ID: 0*/
SPI_CONST static const Spi_JobType Spi_Sequence_0_JobAssignment[1] =
{
    SpiConf_SpiJob_SpiJob_Buck1,
};
/* Spi Sequence_ID: 1*/
SPI_CONST static const Spi_JobType Spi_Sequence_1_JobAssignment[1] =
{
    SpiConf_SpiJob_SpiJob_Buck2,
};

/* Configuration of Sequences */
SPI_CONST static const Spi_SequenceConfigType Spi_SequenceConfigs[2] =
{
    /* Sequence Configuration for SpiSequence_ID: 0 */
    {
        .NumJobs = 1U,
        .SeqEndNotification = NULL_PTR,
        .JobIndexListPtr = Spi_Sequence_0_JobAssignment,
#if (SPI_INTERRUPTIBLE_SEQ_ALLOWED == STD_ON)
        .Interruptible = TRUE,
#endif
    },
    /* Sequence Configuration for SpiSequence_ID: 1 */
    {
        .NumJobs = 1U,
        .SeqEndNotification = NULL_PTR,
        .JobIndexListPtr = Spi_Sequence_1_JobAssignment,
#if (SPI_INTERRUPTIBLE_SEQ_ALLOWED == STD_ON)
        .Interruptible = TRUE,
#endif
    },
};

/* Configuration of External device unit */
SPI_CONST static const Spi_ExternalDeviceConfigType Spi_ExternalDeviceConfigs[2] =
{
    
    /*External Device 0 at CSIB0, configuration*/
    {
        .HWUnitId = CSIB0,
#if (SPI_SLAVE_SUPPORT == STD_ON)
        .SlaveMode = FALSE,
#endif
        .WhichPcs = SPI_PCS0,
        .DualEn = FALSE,
        .SamplePoint = 0U,
        .PinConfig = 0U,
        .PcsPolarity = SPI_ACTIVE_LOW,
        .BaudRate = 1000000,
        .TimeClkToCs = 0U,
        .TimeCsToClk = 0U,
        .TimeCsToCs = 0U,
        .ClkPolarity = SPI_SCK_IDLE_LOW,
        .ClkPhase = SPI_DATA_SHIFT_TRAILING,
        .SrcClk = 40000000U,
        .IsSync = TRUE,
        .IsPcsContinuous = TRUE,
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (SPI_DMA_USED == STD_ON)
        .UseDma = FALSE,
#endif /* SPI_DMA_USED == STD_ON*/
#endif /* (SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)*/
    },
    
    /*External Device 1 at CSIB0, configuration*/
    {
        .HWUnitId = CSIB0,
#if (SPI_SLAVE_SUPPORT == STD_ON)
        .SlaveMode = FALSE,
#endif
        .WhichPcs = SPI_PCS1,
        .DualEn = FALSE,
        .SamplePoint = 0U,
        .PinConfig = 0U,
        .PcsPolarity = SPI_ACTIVE_LOW,
        .BaudRate = 1000000,
        .TimeClkToCs = 0U,
        .TimeCsToClk = 0U,
        .TimeCsToCs = 0U,
        .ClkPolarity = SPI_SCK_IDLE_LOW,
        .ClkPhase = SPI_DATA_SHIFT_TRAILING,
        .SrcClk = 40000000U,
        .IsSync = TRUE,
        .IsPcsContinuous = TRUE,
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (SPI_DMA_USED == STD_ON)
        .UseDma = FALSE,
#endif /* SPI_DMA_USED == STD_ON*/
#endif /* (SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)*/
    },
};

SPI_CONST static const Spi_HWUnitConfigType Spi_HWUnitConfigs[SPI_MAX_HWUNIT] = 
{
    {
        .Instance = (uint8)SPI_2,
        .IsSync = TRUE,
    },
};

/* Spi Configuration */
SPI_CONST const Spi_ConfigType Spi_Config =
{
    .ChannelConfigPtr = Spi_ChannelConfigs, /* ChannelConfig */
    .JobConfigPtr = Spi_JobConfigs, /* JobConfig */
    .SequenceConfigPtr = Spi_SequenceConfigs, /* SequenceConfig */
    .ExternalDeviceConfigPtr = Spi_ExternalDeviceConfigs, /* ExternalDeviceConfig */

    .MaxJob = 2U, /* SpiMaxJob - number of jobs */
    .MaxChannel = 1U, /* SpiMaxChannel - number of channels */
    .MaxSequence = 2U, /* SpiMaxSequence - number of sequences */
    .MaxHWUnitUsed = 1U, /* MaxExternalDevice - number of external devices */
    .HWUnitConfigPtr = Spi_HWUnitConfigs, /* HWUnitConfig */
#if (SPI_ENABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
    .SpiErrorHardwareCfg.Id = 0, /* SPI_E_HARDWARE_ERROR parameters ID of DEM error */
    .SpiErrorHardwareCfg.State = STD_OFF, /* SPI_E_HARDWARE_ERROR parameters enabling the DEM error */
#endif
};

#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

