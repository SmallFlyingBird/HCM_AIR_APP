/**************************************************************************************************/
/**
 * @file      : Spi_PBcfg.c
 * @brief     : Spi AUTOSAR level - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Spi_Module
 *  @{
 */

/** @addtogroup Spi_Configuration
 *  @brief Spi AUTOSAR level configuration
 *  @{
 */
#ifdef __cplusplus
extern "C"{
#endif

#include "Spi.h"
#include "Spi_Drvw.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define SPI_PBCFG_C_VENDOR_ID                   0x00B3U
#define SPI_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define SPI_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define SPI_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define SPI_PBCFG_C_SW_MAJOR_VERSION            1U
#define SPI_PBCFG_C_SW_MINOR_VERSION            2U
#define SPI_PBCFG_C_SW_PATCH_VERSION            2U

/* Check if current file and Spi.h are the same vendor */
#if (SPI_PBCFG_C_VENDOR_ID != SPI_VENDOR_ID)
    #error "Vendor ID of Spi_PBCfg.c and Spi.h are different"
#endif
/* Check if current file and Spi.h are the same Autosar version */
#if ((SPI_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != SPI_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_PBCFG_C_AR_RELEASE_MINOR_VERSION    != SPI_AR_RELEASE_MINOR_VERSION) || \
     (SPI_PBCFG_C_AR_RELEASE_REVISION_VERSION != SPI_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Spi_PBCfg.c and Spi.h are different"
#endif
/* Check if current file and Spi.h are the same Software version */
#if ((SPI_PBCFG_C_SW_MAJOR_VERSION != SPI_SW_MAJOR_VERSION) || \
     (SPI_PBCFG_C_SW_MINOR_VERSION != SPI_SW_MINOR_VERSION) || \
     (SPI_PBCFG_C_SW_PATCH_VERSION != SPI_SW_PATCH_VERSION))
    #error "Software Version of Spi_PBCfg.c and Spi.h are different"
#endif

/* Check if current file and Spi_Drvw.h are the same vendor */
#if (SPI_PBCFG_C_VENDOR_ID != SPI_DRVW_H_VENDOR_ID)
    #error "Vendor ID of Spi_PBCfg.c and Spi_Drvw.h are different"
#endif
/* Check if current file and Spi_Drvw.h are the same Autosar version */
#if ((SPI_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != SPI_DRVW_H_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_PBCFG_C_AR_RELEASE_MINOR_VERSION    != SPI_DRVW_H_AR_RELEASE_MINOR_VERSION) || \
     (SPI_PBCFG_C_AR_RELEASE_REVISION_VERSION != SPI_DRVW_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Spi_PBCfg.c and Spi_Drvw.h are different"
#endif
/* Check if current file and Spi_Drvw.h are the same Software version */
#if ((SPI_PBCFG_C_SW_MAJOR_VERSION != SPI_DRVW_H_SW_MAJOR_VERSION) || \
     (SPI_PBCFG_C_SW_MINOR_VERSION != SPI_DRVW_H_SW_MINOR_VERSION) || \
     (SPI_PBCFG_C_SW_PATCH_VERSION != SPI_DRVW_H_SW_PATCH_VERSION))
    #error "Software Version of Spi_PBCfg.c and Spi_Drvw.h are different"
#endif

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */
#define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"


// static Spi_Drvw_BufferDescriptorType Spi_BufferSpiChannel_Buck1;
#if (CPU_TYPE == CPU_TYPE_64)
VAR_ALIGN(static Spi_Drvw_BufferDescriptorType Spi_BufferSpiChannel_Buck1, (8))
#else
VAR_ALIGN(static Spi_Drvw_BufferDescriptorType Spi_BufferSpiChannel_Buck1, (4))
#endif
static Spi_Drvw_BufferDescriptorType Spi_BufferSpiChannel_Buck2;


#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_INIT_UNSPECIFIED
#include "Spi_MemMap.h"



#define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Spi_MemMap.h"

#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

/**
* @brief Channel Configuration for Channel 'SpiChannel_Buck1'
*/
static const Spi_Drvw_ChannelConfigType Spi_ChannelConfig_SpiChannel_Buck1 =
{
    EB, /*!< BufferType IB or EB */
    24U, /*!< FrameSize */
    (boolean)FALSE, /*!< Lsb */
    (uint32)1U, /*!< DefaultTransmitValue */
    32U, /*!< Length for SpiEbMaxLength */
    &Spi_BufferSpiChannel_Buck1, /*!< BufferDescriptor */
    0U, /*!< SpiCoreUse */
    &Spi_ChannelStateArray[0U] /*!< ChannelState */
};

/**
* @brief Channel Configuration for Channel 'SpiChannel_Buck2'
*/
static const Spi_Drvw_ChannelConfigType Spi_ChannelConfig_SpiChannel_Buck2 =
{
    EB, /*!< BufferType IB or EB */
    8U, /*!< FrameSize */
    (boolean)FALSE, /*!< Lsb */
    (uint32)1U, /*!< DefaultTransmitValue */
    32U, /*!< Length for SpiEbMaxLength */
    &Spi_BufferSpiChannel_Buck2, /*!< BufferDescriptor */
    0U, /*!< SpiCoreUse */
    &Spi_ChannelStateArray[1U] /*!< ChannelState */
};


/**
* @brief Channel Configuration list: Spi_ChannelConfigList[2]
*/
static const Spi_ChannelConfigListType Spi_ChannelConfigList[2] =
{
    {&Spi_ChannelConfig_SpiChannel_Buck1},
    {&Spi_ChannelConfig_SpiChannel_Buck2}
};


/**
* @brief Channel Assignment of Jobs
*/
static const Spi_ChannelType Spi_ChannelAssignment_SpiJob_Buck1[1] =
{
    SpiConf_SpiChannel_SpiChannel_Buck1
};

/**
* @brief Channel Assignment of Jobs
*/
static const Spi_ChannelType Spi_ChannelAssignment_SpiJob_Buck2[1] =
{
    SpiConf_SpiChannel_SpiChannel_Buck2
};

/**
* @brief Job Configuration for Job 'SpiJob_Buck1'
*/
static const Spi_JobConfigType Spi_JobConfig_SpiJob_Buck1 =
{
    (Spi_ChannelType)1U, /*!< ChannelNum field */
    Spi_ChannelAssignment_SpiJob_Buck1, /*!< List of Channels */
    &SpiJob_Buck1End, /*!< End Notification */
    &SpiJob_Buck1Start, /*!< Start Notification */
    (sint8)0, /*!< Priority */
    0U, /*!< Core ID */
    &Spi_JobStateArray[0], /* Pointer to Job State */
    CSIB0, /*!< HWUnit index */
    SPI_EXTERNAL_DEVICE_CONF_BD18397, /*!< External Device */
    &Spi_ExternalDeviceConfigList[SPI_EXTERNAL_DEVICE_CONF_BD18397] /*!< ExternalDeviceConfig */
};

/**
* @brief Job Configuration for Job 'SpiJob_Buck2'
*/
static const Spi_JobConfigType Spi_JobConfig_SpiJob_Buck2 =
{
    (Spi_ChannelType)1U, /*!< ChannelNum field */
    Spi_ChannelAssignment_SpiJob_Buck2, /*!< List of Channels */
    &SpiJob_Buck2End, /*!< End Notification */
    &SpiJob_Buck2Start, /*!< Start Notification */
    (sint8)0, /*!< Priority */
    0U, /*!< Core ID */
    &Spi_JobStateArray[1], /* Pointer to Job State */
    CSIB0, /*!< HWUnit index */
    SPI_EXTERNAL_DEVICE_CONF_BD18397, /*!< External Device */
    &Spi_ExternalDeviceConfigList[SPI_EXTERNAL_DEVICE_CONF_BD18397] /*!< ExternalDeviceConfig */
};


/**
* @brief Job Configuration list: Spi_JobConfigList[2]
*/
static const Spi_JobConfigListType Spi_JobConfigList[2] =
{
    {&Spi_JobConfig_SpiJob_Buck1},
    {&Spi_JobConfig_SpiJob_Buck2}
};


/**
* @brief Job Assignment of Sequences
*/
static const Spi_JobType Spi_JobAssignment_SpiSequence_Buck1[1] =
{
    SpiConf_SpiJob_SpiJob_Buck1
};

/**
* @brief Job Assignment of Sequences
*/
static const Spi_JobType Spi_JobAssignment_SpiSequence_Buck2[1] =
{
    SpiConf_SpiJob_SpiJob_Buck2
};

/**
* @brief Sequence Configuration for Sequence 'SpiSequence_Buck1'
*/
static const Spi_SequenceConfigType Spi_SequenceConfig_SpiSequence_Buck1 =
{
    (Spi_JobType)1U, /* JobNum */
    0U, /* SpiCoreUse */
    Spi_JobAssignment_SpiSequence_Buck1, /* List of Jobs */
    &Ex_Spi_MasterSequenceEndNotification, /* End Notification */
    (uint8)FALSE /* Interruptible */
};

/**
* @brief Sequence Configuration for Sequence 'SpiSequence_Buck2'
*/
static const Spi_SequenceConfigType Spi_SequenceConfig_SpiSequence_Buck2 =
{
    (Spi_JobType)1U, /* JobNum */
    0U, /* SpiCoreUse */
    Spi_JobAssignment_SpiSequence_Buck2, /* List of Jobs */
    NULL_PTR, /* End Notification */
    (uint8)FALSE /* Interruptible */
};


/**
* @brief Sequence Configuration list: Spi_SequenceConfigList[2]
*/
static const Spi_SequenceConfigListType Spi_SequenceConfigList[2] =
{
    {&Spi_SequenceConfig_SpiSequence_Buck1},
    {&Spi_SequenceConfig_SpiSequence_Buck2},
};


#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

/** @} end of group Private_VariableDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

/**
* @brief SPI Configuration
*/
static const Spi_ConfigType Spi_Config=
{
    1U, /*!< Configured External Devices */
    1U, /*!< Configured Channels */
    1U, /*!< Configured Jobs */
    1U, /*!< Configured Sequences */
    0U, /*!< SpiCoreUse */
    Spi_ChannelConfigList, /*!< ChannelConfigList */
    Spi_JobConfigList, /*!< JobConfigList */
    Spi_SequenceConfigList, /*!< SequenceConfigList */
    Spi_ExternalDeviceConfigList, /*!< ExternalDeviceConfigList */
    Spi_HwUnitConfigList /*!< HWUnitConfigList */
};


#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

#define SPI_START_SEC_CONFIG_DATA_PTR
#include "Spi_MemMap.h"

/**
* @brief Pointer to SPI Configuration
*/
const Spi_ConfigType * const Spi_PreDefinedConfigPtr[SPI_MAX_PARTITIONS]=
{
    &Spi_Config
};


#define SPI_STOP_SEC_CONFIG_DATA_PTR
#include "Spi_MemMap.h"
/** @} end of group Global_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
/** @} end of group Public_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Spi_Configuration */

/** @} end of group Spi_Module */
