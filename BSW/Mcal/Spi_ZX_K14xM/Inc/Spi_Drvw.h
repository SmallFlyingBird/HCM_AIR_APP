/**************************************************************************************************/
/**
 * @file      : Spi_Drvw.h
 * @brief     : Spi driver wrapper header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef SPI_DRVW_H
#define SPI_DRVW_H

/** @addtogroup Spi_Module
 *  @{
 */

/** @addtogroup Spi_Drvw
 *  @brief Spi driver wrapper
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Spi_Drvw_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define SPI_DRVW_H_VENDOR_ID                   0x00B3U
#define SPI_DRVW_H_AR_RELEASE_MAJOR_VERSION    4U
#define SPI_DRVW_H_AR_RELEASE_MINOR_VERSION    6U
#define SPI_DRVW_H_AR_RELEASE_REVISION_VERSION 0U
#define SPI_DRVW_H_SW_MAJOR_VERSION            1U
#define SPI_DRVW_H_SW_MINOR_VERSION            2U
#define SPI_DRVW_H_SW_PATCH_VERSION            2U

/* Check if current file and Spi_Drvw_Types.h are the same vendor */
#if (SPI_DRVW_H_VENDOR_ID != SPI_DRVW_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Spi_Drvw.h and Spi_Drvw_Types.h are different"
#endif
/* Check if current file and Spi_Drvw_Types.h are the same Autosar version */
#if ((SPI_DRVW_H_AR_RELEASE_MAJOR_VERSION != SPI_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||         \
     (SPI_DRVW_H_AR_RELEASE_MINOR_VERSION != SPI_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION) ||         \
     (SPI_DRVW_H_AR_RELEASE_REVISION_VERSION != SPI_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Spi_Drvw.h and Spi_Drvw_Types.h are different"
#endif
/* Check if current file and Spi_Drvw_Types.h are the same Software version */
#if ((SPI_DRVW_H_SW_MAJOR_VERSION != SPI_DRVW_TYPES_H_SW_MAJOR_VERSION) ||                         \
     (SPI_DRVW_H_SW_MINOR_VERSION != SPI_DRVW_TYPES_H_SW_MINOR_VERSION) ||                         \
     (SPI_DRVW_H_SW_PATCH_VERSION != SPI_DRVW_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Spi_Drvw.h and Spi_Drvw_Types.h are different"
#endif

/**
 * @brief Defines channel flag of transmit default data.
 */
#define SPI_DRVW_CHANNEL_FLAG_TX_DEFAULT ((uint8)0x01U)

/**
 * @brief Defines channel flag of discard received data.
 */
#define SPI_DRVW_CHANNEL_FLAG_RX_DISCARD ((uint8)0x02U)

/**
 * @brief Defines asynchronous transmission state of hardware unit.
 */
#define SPI_DRVW_PHYUNIT_ASYNC (0U)

/**
 * @brief Defines synchronous transmission state of hardware unit.
 */
#define SPI_DRVW_PHYUNIT_SYNC (1U)

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"
/**
 * @brief   Export Post-Build configurations.
 */
SPI_DRVW_CONFIG_EXT

#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"
/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

/**
 * @brief     The function initialize the given SPI HW Unit.
 *
 * @param[in] HWUnit: Id of Spi HW Unit
 * @param[in] HWUnitCfgPtr: pointer to the SPI HW Unit Configuration
 *
 * @return    None
 *
 */
void Spi_Drvw_Init(const Spi_Drvw_HWUnitType HWUnit, const Spi_Drvw_HWUnitConfigType *HWUnitCfgPtr);

/**
 * @brief     The function de-initialize the given SPI HW Unit.
 *
 * @param[in] HWUnit: Id of SPI HW Unit
 *
 * @return    None
 *
 */
void Spi_Drvw_DeInit(Spi_Drvw_HWUnitType HWUnit);

/**
 * @brief   The function processes synchronous or asynchronous transmission of one channel.
 *
 * @param[in] ChannelCfgPtr: Pointer to channel configuration
 * @param[in] ExternalDeviceCfgPtr: Pointer to external device configuration
 * @param[in] IsFirstChannel: first channel of job or not
 * @param[in] IsLastChannel: last channel of job or not
 * @param[in] IsSync: synchronous or asynchronous transmission. TRUE is Sync, and FALSE is Async.
 *
 * @return    Std_ReturnType
 * @retval    E_OK: Channel transmission successfully
 * @retval    E_NOT_OK: Channel transmission failed
 *
 */
Std_ReturnType
Spi_Drvw_TransmitChannel(const Spi_Drvw_ChannelConfigType        *ChannelCfgPtr,
                         const Spi_Drvw_ExternalDeviceConfigType *ExternalDeviceCfgPtr,
                         const boolean IsFirstChannel, const boolean IsLastChannel,
                         const boolean IsSync);

#if ((SPI_DRVW_LEVEL_DELIVERED == LEVEL1) || (SPI_DRVW_LEVEL_DELIVERED == LEVEL2))
/**
 * @brief     The function polls to process asynchronous transmission.
 *
 * @param[in] HWUnit: Id of SPI HW Unit
 *
 * @return    None
 *
 */
void Spi_Drvw_PollAsyncTransmit(Spi_Drvw_HWUnitType HWUnit);

/**
 * @brief     The function configures transfer mdoe as polling or interrupt.
 *
 * @param[in] HWUnit: Id of Spi HW Unit
 * @param[in] Mode: set polling or interrupt mode
 *
 * @return    None
 *
 */
void Spi_Drvw_SetAsyncMode(Spi_Drvw_HWUnitType HWUnit, Spi_Drvw_AsyncModeType Mode);
#endif

#if ((SPI_DRVW_SLAVE_SUPPORT == STD_ON) && (SPI_DRVW_CANCEL_API == STD_ON))
    #if ((SPI_DRVW_LEVEL_DELIVERED == LEVEL1) || (SPI_DRVW_LEVEL_DELIVERED == LEVEL2))
/**
 * @brief     The function cancels transmission of slave mode.
 *
 * @param[in] HWUnit: Id of Spi HW Unit
 *
 * @return    None
 */
void Spi_Drvw_SlaveCancel(const Spi_Drvw_HWUnitType HWUnit);
    #endif
#endif

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Spi_Drvw */

/** @} end of group Spi_Module */

#endif /*SPI_DRVW_H*/
