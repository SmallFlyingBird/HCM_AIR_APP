/**************************************************************************************************/
/**
 * @file      : Spi_Drv.h
 * @brief     : Spi low level driver header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef SPI_DRV_H
#define SPI_DRV_H

/** @addtogroup  Spi_Module
 *  @{
 */

/** @addtogroup Spi_Drv
 *  @brief Spi low level driver
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Spi_Drv_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define SPI_DRV_H_VENDOR_ID                   0x00B3U
#define SPI_DRV_H_AR_RELEASE_MAJOR_VERSION    4U
#define SPI_DRV_H_AR_RELEASE_MINOR_VERSION    6U
#define SPI_DRV_H_AR_RELEASE_REVISION_VERSION 0U
#define SPI_DRV_H_SW_MAJOR_VERSION            1U
#define SPI_DRV_H_SW_MINOR_VERSION            2U
#define SPI_DRV_H_SW_PATCH_VERSION            2U

/* Check if current file and Spi_Drv_Types.h are the same vendor */
#if (SPI_DRV_H_VENDOR_ID != SPI_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Spi_Drv.h and Spi_Drv_Types.h are different"
#endif
/* Check if current file and Spi_Drv_Types.h are the same Autosar version */
#if ((SPI_DRV_H_AR_RELEASE_MAJOR_VERSION != SPI_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||           \
     (SPI_DRV_H_AR_RELEASE_MINOR_VERSION != SPI_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||           \
     (SPI_DRV_H_AR_RELEASE_REVISION_VERSION != SPI_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Spi_Drv.h and Spi_Drv_Types.h are different"
#endif
/* Check if current file and Spi_Drv_Types.h are the same Software version */
#if ((SPI_DRV_H_SW_MAJOR_VERSION != SPI_DRV_TYPES_H_SW_MAJOR_VERSION) ||                           \
     (SPI_DRV_H_SW_MINOR_VERSION != SPI_DRV_TYPES_H_SW_MINOR_VERSION) ||                           \
     (SPI_DRV_H_SW_PATCH_VERSION != SPI_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Spi_Drv.h and Spi_Drv_Types.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"

extern Spi_Drv_DeviceParamType Spi_Drv_DeviceParamArray[SPI_DRV_MAX_CFG_DEVICES];

#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"

#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"
/**
 * @brief   Export Post-Build configurations.
 */
SPI_DRV_CONFIG_EXT

#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

/**
 * @brief     The function initializes the SPI hardware unit of given configuration.
 *
 * @param[in] PhyUnitConfigPtr: Pointer to the SPI HW Unit configuration
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Successful.
 * @retval    E_NOT_OK: Failed.
 */
Std_ReturnType Spi_Drv_Init(const Spi_Drv_PhyUnitConfigType *PhyUnitConfigPtr);

/**
 * @brief     The function de-initializes the SPI hardware unit.
 * @details   The function de-initializes the SPI hardware unit.
 *
 * @param[in] Instance: SPI peripheral instance number
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Successful.
 * @retval    E_NOT_OK: Failed.
 */
Std_ReturnType Spi_Drv_DeInit(uint8 Instance);

/**
 * @brief     This function updates Frame Size, default data and Lsb of given external device.
 *
 * @param[in] DevicePtr: Pointer to the external device configuration
 * @param[in] FrameSize: Frame Size
 * @param[in] Lsb: Lsb or Msb first
 * @param[in] DefaultData: Default data of transmission
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Successfully
 * @retval    E_NOT_OK: Failed
 */
Std_ReturnType Spi_Drv_SetDeviceParams(const Spi_Drv_ExternalDeviceType *DevicePtr, uint8 FrameSize,
                                       boolean Lsb, uint32 DefaultData);

/**
 * @brief     The function initializes a synchronous transmission.
 *
 * @param[in] ExternalDevice: Pointer to the external device where data is transmitted
 * @param[in] TxBuffer: Pointer to Tx buffer
 * @param[in,out] RxBuffer: Pointer to Rx buffer
 * @param[in] Length: Number of bytes to be sent
 * @param[in] TimeOut: Wait time to avoid end loop
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Successfully.
 * @retval    E_NOT_OK: Failed.
 */
Std_ReturnType Spi_Drv_SyncTransmit(const Spi_Drv_ExternalDeviceType *ExternalDevice,
                                    uint8 *TxBuffer, uint8 *RxBuffer, uint16 Length,
                                    uint32 TimeOut);

/**
 * @brief     The function initializes a asynchronous transmission.
 *
 * @param[in] ExternalDevice: Pointer to the external device configuration
 * @param[in] TxBuffer: Pointer to Tx buffer
 * @param[in,out] RxBuffer: Pointer to Rx buffer
 * @param[in] Length: Number of bytes to be sent
 * @param[in] EndCallback: Callback function at the end of transfer.
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Successfully.
 * @retval    E_NOT_OK: Failed.
 */
Std_ReturnType Spi_Drv_AsyncTransmit(const Spi_Drv_ExternalDeviceType *ExternalDevice,
                                     uint8 *TxBuffer, uint8 *RxBuffer, uint16 Length,
                                     Spi_Drv_CallbackType EndCallback);

/**
 * @brief     This function polls the SPI interrupts for asynchronous transmission.
 *
 * @param[in] Instance: SPI peripheral instance number
 *
 * @return    None
 */
void Spi_Drv_PollAsyncTransmit(uint8 Instance);

/**
 * @brief     This function set polling or interrupt mode for asynchronous transmission.
 *
 * @param[in] Instance: SPI peripheral instance number
 * @param[in] Mode: Polling or Interrupt mode.
 *
 * @return    Std_ReturnType
 * @retval    E_OK:     Successfully.
 * @retval    E_NOT_OK: Failed.
 */
Std_ReturnType Spi_Drv_SetAsyncMode(uint8 Instance, Spi_Drv_AsyncModeType Mode);

/**
 * @brief     This function cancels current asynchronous transmission.
 *
 * @param[in] Instance: SPI peripheral instance number
 *
 * @return    None
 */
void Spi_Drv_Cancel(uint8 Instance);

/**
 * @brief     This function gets status of hardware unit.
 *
 * @param[in] Instance: SPI peripheral instance number
 *
 * @return    Spi_Drv_StatusType
 * @retval    SPI_DRV_UNINIT
 * @retval    SPI_DRV_IDLE
 * @retval    SPI_DRV_BUSY
 * @retval    SPI_DRV_FAULT
 */
Spi_Drv_StatusType Spi_Drv_GetStatus(uint8 Instance);

/**
 * @brief     This function processes SPI ISR.
 *
 * @param[in] Instance: SPI peripheral instance number
 *
 * @return    None
 */
void Spi_Drv_IntHandler(uint8 Instance);

#if (SPI_DRV_DMA_USED == STD_ON)
/**
 * @brief     This function process DMA interrupt when Tx transfer is completed.
 *
 * @param[in] Instance: SPI peripheral instance number.
 * @return    None
 */
void Spi_Drv_DmaTxIntHandler(uint8 Instance);

/**
 * @brief     This function process DMA interrupt when Rx transfer is completed.
 *
 * @param[in] Instance: SPI peripheral instance number.
 * @return    None
 */
void Spi_Drv_DmaRxIntHandler(uint8 Instance);
#endif

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Spi_Drv */

/** @} end of group Spi_Module */

#endif /* SPI_DRV_H */
