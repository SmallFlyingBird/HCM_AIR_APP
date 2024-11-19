/**************************************************************************************************/
/**
 * @file      : Spi.h
 * @brief     : Spi AUTOSAR level header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef SPI_H
#define SPI_H

/** @addtogroup  Spi_Module
 *  @{
 */

/** @addtogroup Spi
 *  @brief Spi AUTOSAR level
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Spi_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define SPI_MODULE_ID                   83U
#define SPI_VENDOR_ID                   0x00B3U
#define SPI_AR_RELEASE_MAJOR_VERSION    4U
#define SPI_AR_RELEASE_MINOR_VERSION    6U
#define SPI_AR_RELEASE_REVISION_VERSION 0U
#define SPI_SW_MAJOR_VERSION            1U
#define SPI_SW_MINOR_VERSION            2U
#define SPI_SW_PATCH_VERSION            2U

/* Check if current file and Spi_Types.h are the same vendor */
#if (SPI_VENDOR_ID != SPI_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Spi.h and Spi_Types.h are different"
#endif
/* Check if current file and Spi_Types.h are the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION != SPI_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||                     \
     (SPI_AR_RELEASE_MINOR_VERSION != SPI_TYPES_H_AR_RELEASE_MINOR_VERSION) ||                     \
     (SPI_AR_RELEASE_REVISION_VERSION != SPI_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Spi.h and Spi_Types.h are different"
#endif
/* Check if current file and Spi_Types.h are the same Software version */
#if ((SPI_SW_MAJOR_VERSION != SPI_TYPES_H_SW_MAJOR_VERSION) ||                                     \
     (SPI_SW_MINOR_VERSION != SPI_TYPES_H_SW_MINOR_VERSION) ||                                     \
     (SPI_SW_PATCH_VERSION != SPI_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Spi.h and Spi_Types.h are different"
#endif

/**
 * @brief API service called with wrong parameter of Channel.
 */
#define SPI_E_PARAM_CHANNEL ((uint8)0x0AU)

/**
 * @brief API service called with wrong parameter of Job.
 *
 */
#define SPI_E_PARAM_JOB ((uint8)0x0BU)

/**
 * @brief API service called with wrong parameter of Sequence.
 *
 */
#define SPI_E_PARAM_SEQ ((uint8)0x0CU)
/**
 * @brief API service called with wrong parameter of external buffer length.
 *
 */
#define SPI_E_PARAM_LENGTH ((uint8)0x0DU)

/**
 * @brief API service called with wrong parameter of HWUnit.
 *
 */
#define SPI_E_PARAM_UNIT ((uint8)0x0EU)

/**
 * @brief API service called with wrong resource assigned.
 *
 */
#define SPI_E_PARAM_CONFIG ((uint8)0x0FU)

/**
 * @brief API service used without module initialization.
 *
 */
#define SPI_E_UNINIT ((uint8)0x1AU)
/**
 * @brief Services called in a wrong sequence.
 *
 */
#define SPI_E_SEQ_PENDING ((uint8)0x2AU)

/**
 * @brief Synchronous transmission service called at wrong time.
 *
 */
#define SPI_E_SEQ_IN_PROCESS ((uint8)0x3AU)

/**
 * @brief API SPI_Init service called while the SPI driver has already been initialized.
 *
 */
#define SPI_E_ALREADY_INITIALIZED ((uint8)0x4AU)

/**
 * @brief   The number of sequences, jobs or channels exceeds precompile time sizes.
 *
 */
#define SPI_E_CONFIG_OUT_OF_RANGE ((uint8)0x5AU)

/**
 * @brief API Spi_Init was called with wrong configuration pointer.
 *
 */
#define SPI_E_INIT_FAILED ((uint8)0x6AU)

/**
 * @brief   When a sequence contains uninitialized external buffers.
 *
 */
#define SPI_E_PARAM_EB_UNIT ((uint8)0x5BU)

/**
 * @brief   No job in sequence.
 *
 */
#define SPI_E_SEQ_EMPTY ((uint8)0x5CU)

/**
 * @brief   No channel in job.
 *
 */
#define SPI_E_JOB_EMPTY ((uint8)0x5DU)

/**
 * @brief   If the parameter versioninfo or Spi configuration is NULL_PTR.
 *
 */
#define SPI_E_PARAM_POINTER ((uint8)0x10U)

/**
 * @brief   Invalid pointer, e.g., NULL_PTR.
 *
 */
#define SPI_E_POINTER_INVALID ((uint8)0x60U)

/**
 * @brief API service called with wrong HW Unit.
 *
 */
#define SPI_E_PARAM_HWUNIT ((uint8)0x61U)

/**
 * @brief API service ID for SPI Init function.
 *
 */
#define SPI_SID_INIT ((uint8)0x00U)

/**
 * @brief API service ID for SPI DeInit function.
 *
 */
#define SPI_SID_DEINIT ((uint8)0x01U)

/**
 * @brief API service ID for SPI write IB function.
 *
 */
#define SPI_SID_WRITE_IB ((uint8)0x02U)

/**
 * @brief API service ID for SPI async transmit function.
 *
 */
#define SPI_SID_ASYNC_TRANSMIT ((uint8)0x03U)

/**
 * @brief API service ID for SPI read IB function.
 *
 */
#define SPI_SID_READ_IB ((uint8)0x04U)

/**
 * @brief API service ID for SPI setup EB function.
 *
 */
#define SPI_SID_SETUP_EB ((uint8)0x05U)

/**
 * @brief API service ID for SPI get status function.
 *
 */
#define SPI_SID_GET_STATUS ((uint8)0x06U)

/**
 * @brief API service ID for SPI get job result function.
 *
 */
#define SPI_SID_GET_JOB_RESULT ((uint8)0x07U)

/**
 * @brief API service ID for SPI get sequence result function.
 *
 */
#define SPI_SID_GET_SEQUENCE_RESULT ((uint8)0x08U)

/**
 * @brief API service ID for SPI get version info function.
 *
 */
#define SPI_SID_GET_VERSION_INFO ((uint8)0x09U)

/**
 * @brief API service ID for SPI sync transmit function.
 *
 */
#define SPI_SID_SYNC_TRANSMIT ((uint8)0x0AU)

/**
 * @brief API service ID for SPI get hwunit status function.
 *
 */
#define SPI_SID_GET_HWUNIT_STATUS ((uint8)0x0BU)

/**
 * @brief API service ID for SPI cancel transmission.
 *
 */
#define SPI_SID_CANCEL ((uint8)0x0CU)

/**
 * @brief API service ID for SPI set async mode function.
 *
 */
#define SPI_SID_SET_ASYNC_MODE ((uint8)0x0DU)

/**
 * @brief API service ID for SPI main function
 */
#define SPI_SID_MAIN_FUNCTION_HANDLING ((uint8)0x10U)

/**
 * @brief API service ID for SPI set HW Unit async mode.
 *
 */
#define SPI_SID_SET_HWUNIT_ASYNC_MODE ((uint8)0x60U)

/**
 * @brief the SPI Handler/Driver manages only Internal Buffers.
 */
#define USAGE0 (0U)

/**
 * @brief  the SPI Handler/Driver manages only External Buffers.
 */
#define USAGE1 (1U)

/**
 * @brief the SPI Handler/Driver manages both buffers types.
 */
#define USAGE2 (2U)

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#if (SPI_PRECOMPILE_SUPPORT == STD_ON)
    #define SPI_START_SEC_CONFIG_DATA_PTR
    #include "Spi_MemMap.h"
extern const Spi_ConfigType *const Spi_PreDefinedConfigPtr[SPI_MAX_PARTITIONS];
    #define SPI_STOP_SEC_CONFIG_DATA_PTR
    #include "Spi_MemMap.h"
#else
    #define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Spi_MemMap.h"
/**
 * @brief   Export Post-Build configurations.
 */
SPI_CONFIG_EXT

    #define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #include "Spi_MemMap.h"
#endif /* (SPI_PRECOMPILE_SUPPORT == STD_ON) */

#define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"
/**
 * @brief Extern arrays contain the state of Sequences, Jobs and Channels.
 */
extern Spi_JobStateType          Spi_JobStateArray[SPI_MAX_CFG_JOBS];
extern Spi_Drvw_ChannelStateType Spi_ChannelStateArray[SPI_MAX_CFG_CHANNELS];
#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

/**
 * @brief      Service for SPI initialization.
 *             - Service ID: 0x00
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Non-Reentrant
 *
 * @param[in]  ConfigPtr: Pointer to configuration set
 *
 * @return     None
 */
void Spi_Init(const Spi_ConfigType *ConfigPtr);

/**
 * @brief      Service for SPI de-initialization.
 *             - Service ID: 0x01
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Non-Reentrant
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      de-initialisation command has been accepted
 * @retval     E_NOT_OK:  de-initialisation command has not been accepted
 *
 */
Std_ReturnType Spi_DeInit(void);

#if ((USAGE0 == SPI_CHANNEL_BUFFERS_ALLOWED) || (USAGE2 == SPI_CHANNEL_BUFFERS_ALLOWED))
/**
 * @brief      Service for writing one or more data to an IB SPI Handler/Driver Channel specified by
 * parameter.
 *             - Service ID: 0x02
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Reentrant
 *
 * @param[in]  Channel: Channel ID
 * @param[in]  DataBufferPtr: Pointer to source data buffer. If this pointer is null, it is assumed
 * that the data to be transmitted is not relevant and the default transmit value of this channel
 * will be used instead.
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      Command has been accepted
 * @retval     E_NOT_OK:  Command has not been accepted
 *
 */
Std_ReturnType Spi_WriteIB(Spi_ChannelType Channel, const Spi_DataBufferType *DataBufferPtr);
#endif /* ((USAGE0 == SPI_CHANNEL_BUFFERS_ALLOWED) || (USAGE2 == SPI_CHANNEL_BUFFERS_ALLOWED )) */

#if ((LEVEL2 == SPI_LEVEL_DELIVERED) || (LEVEL1 == SPI_LEVEL_DELIVERED))
/**
 * @brief      Service to transmit data on the SPI bus.
 *             - Service ID: 0x03
 *             - Sync or Async: Asynchronous
 *             - Reentrancy: Reentrant
 *
 * @param[in]  Sequence: Sequence ID
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      Transmission command has been accepted
 * @retval     E_NOT_OK:  Transmission command has not been accepted
 *
 */
Std_ReturnType Spi_AsyncTransmit(Spi_SequenceType Sequence);
#endif /* ((LEVEL2 == SPI_LEVEL_DELIVERED) || (LEVEL1 == SPI_LEVEL_DELIVERED)) */

#if ((USAGE0 == SPI_CHANNEL_BUFFERS_ALLOWED) || (USAGE2 == SPI_CHANNEL_BUFFERS_ALLOWED))
/**
 * @brief      Service to setup the buffers and the length of data for the EB SPI Handler/Driver
 * Channel specified.
 *             - Service ID: 0x05
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Reentrant
 *
 * @param[in]  Channel: Channel ID
 * @param[in]  SrcDataBufferPtr: Pointer to source data buffer
 * @param[out] DesDataBufferPtr: Pointer to destination data buffer in RAM.
 * @param[in]  Length: Length (number of data elements) of the data to be transmitted from
 * SrcDataBufferPtr and/or received from DesDataBufferPtr Min.: 1 Max.: Max of data specified at
 * configuration for this channel.
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      Setup command has been accepted
 * @retval     E_NOT_OK:  Setup command has not been accepted
 *
 */
Std_ReturnType Spi_ReadIB(Spi_ChannelType Channel, Spi_DataBufferType *DataBufferPtr);
#endif /* ((USAGE0 == SPI_CHANNEL_BUFFERS_ALLOWED) || (USAGE2 == SPI_CHANNEL_BUFFERS_ALLOWED )) */

#if ((USAGE1 == SPI_CHANNEL_BUFFERS_ALLOWED) || (USAGE2 == SPI_CHANNEL_BUFFERS_ALLOWED))
/**
 * @brief      Service to setup the buffers and the length of data for the EB SPI Handler/Driver
 * Channel specified.
 *             - Service ID: 0x05
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Reentrant
 *
 * @param[in]  Channel: Channel ID
 * @param[in]  SrcDataBufferPtr: Pointer to source data buffer
 * @param[out] DesDataBufferPtr: Pointer to destination data buffer in RAM.
 * @param[in]  Length: Length (number of data elements) of the data to be transmitted from
 * SrcDataBufferPtr and/or received from DesDataBufferPtr Min.: 1 Max.: Max of data specified at
 * configuration for this channel.
 *
 * @return     Std_ReturnType
 * @retval     E_OK:      Setup command has been accepted
 * @retval     E_NOT_OK:  Setup command has not been accepted
 *
 */
Std_ReturnType Spi_SetupEB(Spi_ChannelType Channel, Spi_DataBufferType *SrcDataBufferPtr,
                           Spi_DataBufferType *DesDataBufferPtr, Spi_NumberOfDataType Length);
#endif /* ( (USAGE1 == SPI_CHANNEL_BUFFERS_ALLOWED) || ( USAGE2 == SPI_CHANNEL_BUFFERS_ALLOWED) )  \
        */

/**
 * @brief     Service returns the SPI Handler/Driver software module status.
 *            - Service ID: 0x06
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @return    Spi_StatusType
 * @retval    SPI_UNINIT:  The driver is un-initialized
 * @retval    SPI_IDLE:    The driver has no pending transfers
 * @retval    SPI_BUSY:    The driver is busy
 *
 */
Spi_StatusType Spi_GetStatus(void);

/**
 * @brief     This service returns the last transmission result of the specified Job.
 *            - Service ID: 0x07
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Job: Job ID
 *
 * @return    Spi_JobResultType
 * @retval    SPI_JOB_OK:        The job ended successfully
 * @retval    SPI_JOB_PENDING:   The job is pending
 * @retval    SPI_JOB_FAILED:    The job has failed
 * @retval    SPI_JOB_QUEUED:    The job has been accepted
 */
Spi_JobResultType Spi_GetJobResult(Spi_JobType Job);

/**
 * @brief     This service returns the last transmission result of the specified Sequence.
 *            - Service ID: 0x08
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Sequence: Sequence ID. An invalid sequence ID will return an undefined result.
 *
 * @return    Spi_SeqResultType
 * @retval    SPI_SEQ_OK:       The sequence ended successfully
 * @retval    SPI_SEQ_PENDING:  The sequence is pending
 * @retval    SPI_SEQ_FAILED:   The sequence has failed
 * @retval    SPI_SEQ_CANCELLED:The sequence has been canceled
 */
Spi_SeqResultType Spi_GetSequenceResult(Spi_SequenceType Sequence);

#if (SPI_VERSION_INFO_API == STD_ON)
/**
 * @brief      This service returns the version information of this module.
 *             pre-established configurations
 *             - Service ID: 0x09
 *             - Sync or Async: Synchronous
 *             - Reentrancy: Reentrant
 *
 * @param[inout] versioninfo: Pointer to where to store the version information of this module.
 *
 * @return     None
 */
void Spi_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif /* (SPI_VERSION_INFO_API == STD_ON) */

#if ((LEVEL2 == SPI_LEVEL_DELIVERED) || (LEVEL0 == SPI_LEVEL_DELIVERED))
/**
 * @brief     Service to transmit data on the SPI bus.
 *            - Service ID: 0x0a
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Sequence: Sequence ID
 *
 * @return    Std_ReturnType
 * @retval    E_OK:       Transmission command has been completed successfully
 * @retval    E_NOT_OK:   Transmission command has not been accepted
 *
 */
Std_ReturnType Spi_SyncTransmit(Spi_SequenceType Sequence);
#endif /* ((LEVEL2 == SPI_LEVEL_DELIVERED) || (LEVEL0 == SPI_LEVEL_DELIVERED)) */

#if (SPI_HW_STATUS_API == STD_ON)
/**
 * @brief     This service returns the status of the specified SPI Hardware microcontroller
 * peripheral.
 *            - Service ID: 0x0b
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] HWUnit: SPI Hardware microcontroller peripheral (unit) ID.
 *
 * @return    Spi_StatusType
 * @retval    SPI_UNINIT:  The peripheral is un-initialized
 * @retval    SPI_IDLE:    The peripheral is in idle state
 * @retval    SPI_BUSY:    The peripheral is busy
 *
 */
Spi_StatusType Spi_GetHWUnitStatus(Spi_HWUnitType HWUnit);
#endif /* (SPI_HW_STATUS_API == STD_ON) */

#if (SPI_CANCEL_API == STD_ON)
/**
 * @brief     Service cancels the specified on-going sequence transmission.
 *            - Service ID: 0x0c
 *            - Sync or Async: Asynchronous
 *            - Reentrancy: Reentrant
 *
 * @param[in] Sequence: Sequence ID
 *
 * @return    Std_ReturnType
 * @retval    E_OK       The command ended successfully
 * @retval    E_NOT_OK   The command has failed.
 *
 */
void Spi_Cancel(Spi_SequenceType Sequence);
#endif /* (SPI_CANCEL_API == STD_ON) */

#if (SPI_LEVEL_DELIVERED == LEVEL2)
/**
 * @brief     Service to set the asynchronous mechanism mode for SPI busses handled asynchronously.
 *            - Service ID: 0x0d
 *            - Sync or Async: Synchronous
 *            - Reentrancy: Non-Reentrant
 *
 * @param[in] Mode: New mode required.
 *
 * @return    Std_ReturnType
 * @retval    E_OK:       Setting command has been done.
 * @retval    E_NOT_OK:   setting command has not been accepted.
 *
 */
Std_ReturnType Spi_SetAsyncMode(Spi_AsyncModeType Mode);
#endif /* (SPI_LEVEL_DELIVERED == LEVEL2) */

/**
 * @brief     Service to set the asynchronous mechanism mode for a specified HWUnit.
 *
 * @param[in] HWUnit: The ID of the HWUnit to be configured.
 * @param[in] Mode: Polling or Interrupt mode
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Setting command has been done
 * @retval    E_NOT_OK: setting command has not been accepted.
 *
 */
#if ((SPI_LEVEL_DELIVERED == LEVEL2) && (SPI_HWUNIT_ASYNC_MODE == STD_ON))
Std_ReturnType Spi_SetHWUnitAsyncMode(Spi_HWUnitType HWUnit, Spi_AsyncModeType Mode);
#endif /* (SPI_LEVEL_DELIVERED == LEVEL2) && (SPI_HWUNIT_ASYNC_MODE == STD_ON) */

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Spi */

/** @} end of group Spi_Module */

#endif /* SPI_H */
