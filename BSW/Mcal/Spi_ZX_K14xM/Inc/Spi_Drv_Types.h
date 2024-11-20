/**************************************************************************************************/
/**
 * @file      : Spi_Drv_Types.h
 * @brief     : Spi low level driver type definition file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef SPI_DRV_TYPES_H
#define SPI_DRV_TYPES_H

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

#include "Std_Types.h"
#include "McalLib.h"
#include "Spi_Drv_Cfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define SPI_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define SPI_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define SPI_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define SPI_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define SPI_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define SPI_DRV_TYPES_H_SW_MINOR_VERSION            2U
#define SPI_DRV_TYPES_H_SW_PATCH_VERSION            2U

/* Check if current file and Spi_Drv_Cfg.h are the same vendor */
#if (SPI_DRV_TYPES_H_VENDOR_ID != SPI_DRV_CFG_H_VENDOR_ID)
    #error "Vendor ID of Spi_Drv_Types.h and Spi_Drv_Cfg.h are different"
#endif
/* Check if current file and Spi_Drv_Cfg.h are the same Autosar version */
#if ((SPI_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != SPI_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) ||       \
     (SPI_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != SPI_DRV_CFG_H_AR_RELEASE_MINOR_VERSION) ||       \
     (SPI_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION != SPI_DRV_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Spi_Drv_Types.h and Spi_Drv_Cfg.h are different"
#endif
/* Check if current file and Spi_Drv_Cfg.h are the same software version */
#if ((SPI_DRV_TYPES_H_SW_MAJOR_VERSION != SPI_DRV_CFG_H_SW_MAJOR_VERSION) ||                       \
     (SPI_DRV_TYPES_H_SW_MINOR_VERSION != SPI_DRV_CFG_H_SW_MINOR_VERSION) ||                       \
     (SPI_DRV_TYPES_H_SW_PATCH_VERSION != SPI_DRV_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Spi_Drv_Types.h and Spi_Drv_Cfg.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Std_Types.h are the same Autosar version */
    #if ((SPI_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) ||             \
         (SPI_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Spi_Drv_Types.h and Std_Types.h are different"
    #endif

    /* Check if current file and McalLib.h are the same Autosar version */
    #if ((SPI_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) ||         \
         (SPI_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Spi_Drv_Types.h and McalLib.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 * @brief Defines events of transfer end callback.
 */
typedef enum
{
    SPI_DRV_EVENT_SUCCESS = 0U, /*!< Successful transfer */
    SPI_DRV_EVENT_FAULT         /*!< Failed transfer */
} Spi_Drv_EventType;

/**
 * @brief  Defines transfer end Callback.
 */
typedef void (*Spi_Drv_CallbackType)(uint8 Instance, Spi_Drv_EventType Event);

/**
 * @brief Defines the transfer modes.
 */
typedef enum
{
    SPI_DRV_POLLING = 0U, /*!< Polling mode */
    SPI_DRV_INTERRUPT     /*!< Interrupt mode */
} Spi_Drv_AsyncModeType;

/**
 * @brief Defines states of SPI hardware unit.
 */
typedef enum
{
    SPI_DRV_UNINIT = 0U, /*!< Not initialized */
    SPI_DRV_IDLE,        /*!< Idle */
    SPI_DRV_BUSY,        /*!< Transfer is ongoing. */
    SPI_DRV_FAULT        /*!< Failed transfer occurred. */
} Spi_Drv_StatusType;

/**
 * @brief   Structure defining some parameters often change of the spi bus.
 */
typedef struct
{
    uint8   FrameSize;   /*!< Frame size */
    boolean Lsb;         /*!< LSB or MSB first */
    uint32  DefaultData; /*!< Default data to send when TxBuffer is NULL */
} Spi_Drv_DeviceParamType;

/**
 * @brief   Structure defining the parameters of the spi bus.
 */
typedef struct
{
    uint8                    Instance;        /*!< hardware unit Instance */
    uint8                    CsIdentifier;    /*!< Cs Identifier */
    uint8                    ClockPhase;      /*!< Clock Phase */
    uint8                    ClockPolarity;   /*!< Clock Polarity */
    uint32                   ClockDivider;    /*!< Clock Divider */
    uint32                   TxFifoThreshold; /*!< Transmit FIFO threshold */
    uint32                   RxFifoThreshold; /*!< Receive FIFO threshold */
    Spi_Drv_DeviceParamType *DeviceParamPtr;  /*!< Contain configuration for bit order, frame
                                                size, default transmit data. */
} Spi_Drv_ExternalDeviceType;

/**
 *  @brief   Structure defining configuration data needed for SPI driver initialization.
 */
typedef struct
{
    uint8 Instance; /*!< Instance of the HWUnit */
#if (SPI_DRV_SLAVE_SUPPORT == STD_ON)
    boolean SlaveMode; /*!< Slave support or not */
#endif
#if (SPI_DRV_DMA_USED == STD_ON)
    boolean DmaUsed;      /*!< DMA used or not */
    uint8   TxDmaChannel; /*!< Id of Transmission DMA channel */
    uint8   RxDmaChannel; /*!< Id of Receive DMA channel */
#endif
    Spi_Drv_AsyncModeType AsyncMode;  /*!< Transfer mode for HWUnit */
} Spi_Drv_PhyUnitConfigType;

/**
 * @brief   Structure defining information needed for internal state of the driver.
 */
typedef struct
{
    Spi_Drv_AsyncModeType            AsyncMode; /*!< Polling or Interrupt mode of hardware unit */
    Spi_Drv_StatusType               Status;    /*!< Status of hardware unit */
    uint8                           *RxBuffer;  /*!< Pointer to Rx buffer */
    uint8                           *TxBuffer;  /*!< Pointer to Tx buffer */
    Spi_Drv_CallbackType             Callback;  /*!< Pointer to callback function */
    uint16                           RxIndex;   /*!< current Rx index to receive data in RxBuffer */
    uint16                           TxIndex; /*!< current Tx index to transmit data in TxBuffer */
    uint16                           ExpectReadNum;  /*!< Number of frames needs to be received */
    uint16                           ExpectWriteNum; /*!< Number of frames needs to be transmit */
    boolean                          ContinueTransferFlag; /*!< Flag of continue to transfer. */
    boolean                          FirstTransferFlag;    /*!< Flag of first transfer. */
    const Spi_Drv_PhyUnitConfigType *PhyUnitConfig;        /*!< Pointer to PhyUnit configuration */
    const Spi_Drv_ExternalDeviceType
           *ExternalDevice;  /*!< Pointer to external device configuration */
    uint8   FrameSize;       /*!< Frame size */
    boolean TxLsb;           /*!< LSB or MSB first */
    boolean
        NextTransferConfigAvailable; /*!< Flag to check next transfer configuration is available */
    uint8   CurrentTxFifoSlot;       /*!< Number of TX FIFO slots are current available. */
    boolean TxDoneFlag;              /*!< Flag of TX is done */
} Spi_Drv_TransferConfigType;

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

/** @} end of group Spi_Drv */

/** @} end of group Spi_Module */

#endif /*SPI_DRV_TYPES*/
