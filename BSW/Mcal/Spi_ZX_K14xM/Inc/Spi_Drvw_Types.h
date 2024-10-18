/**************************************************************************************************/
/**
 * @file      : Spi_Drvw_Types.h
 * @brief     : Spi driver wrapper type definition file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef SPI_DRVW_TYPES_H
#define SPI_DRVW_TYPES_H

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

#include "Spi_Drvw_Cfg.h"
#include "Spi_Drv_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define SPI_DRVW_TYPES_H_VENDOR_ID                   0x00B3U
#define SPI_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define SPI_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define SPI_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define SPI_DRVW_TYPES_H_SW_MAJOR_VERSION            1U
#define SPI_DRVW_TYPES_H_SW_MINOR_VERSION            2U
#define SPI_DRVW_TYPES_H_SW_PATCH_VERSION            1U

/* Check if current file and Spi_Drv_Types.h are the same vendor */
#if (SPI_DRVW_TYPES_H_VENDOR_ID != SPI_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Spi_Drvw_Types.h and Spi_Drv_Types.h are different"
#endif
/* Check if current file and Spi_Drv_Types.h are the same Autosar version */
#if ((SPI_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION != SPI_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||    \
     (SPI_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION != SPI_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||    \
     (SPI_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION !=                                              \
      SPI_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Spi_Drvw_Types.h and Spi_Drv_Types.h are different"
#endif
/* Check if current file and Spi_Drv_Types.h are the same Software version */
#if ((SPI_DRVW_TYPES_H_SW_MAJOR_VERSION != SPI_DRV_TYPES_H_SW_MAJOR_VERSION) ||                    \
     (SPI_DRVW_TYPES_H_SW_MINOR_VERSION != SPI_DRV_TYPES_H_SW_MINOR_VERSION) ||                    \
     (SPI_DRVW_TYPES_H_SW_PATCH_VERSION != SPI_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Spi_Drvw_Types.h and Spi_Drv_Types.h are different"
#endif

/* Check if current file and Spi_Drvw_Cfg.h are the same vendor */
#if (SPI_DRVW_TYPES_H_VENDOR_ID != SPI_DRVW_CFG_H_VENDOR_ID)
    #error "Vendor ID of Spi_Drvw_Types.h and Spi_Drvw_Cfg.h are different"
#endif
/* Check if current file and Spi_Drvw_Cfg.h are the same Autosar version */
#if ((SPI_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION != SPI_DRVW_CFG_H_AR_RELEASE_MAJOR_VERSION) ||     \
     (SPI_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION != SPI_DRVW_CFG_H_AR_RELEASE_MINOR_VERSION) ||     \
     (SPI_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION != SPI_DRVW_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Spi_Drvw_Types.h and Spi_Drvw_Cfg.h are different"
#endif
/* Check if current file and Spi_Drvw_Cfg.h are the same Software version */
#if ((SPI_DRVW_TYPES_H_SW_MAJOR_VERSION != SPI_DRVW_CFG_H_SW_MAJOR_VERSION) ||                     \
     (SPI_DRVW_TYPES_H_SW_MINOR_VERSION != SPI_DRVW_CFG_H_SW_MINOR_VERSION) ||                     \
     (SPI_DRVW_TYPES_H_SW_PATCH_VERSION != SPI_DRVW_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Spi_Drvw_Types.h and Spi_Drvw_Cfg.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 * @brief   Defines buffer types (internal or external).
 */
typedef enum
{
    IB = 0, /*!< Internal Buffer. */
    EB      /*!< External Buffer. */
} Spi_Drvw_BufferType;

/**
 * @brief Specifies the asynchronous mechanism mode for SPI buses handled asynchronously in Level2
 *
 */
/* SWS_Spi_00382 */
typedef enum
{
    SPI_DRVW_POLLING_MODE = 0, /*!< The asynchronous mechanism is ensured by polling, so interrupts
                                  related to SPI buses handled asynchronously are disabled. */
    SPI_DRVW_INTERRUPT_MODE /*!< The asynchronous mechanism is ensured by interrupt, so interrupts
                               related to SPI buses handled asynchronously are enabled. */
} Spi_Drvw_AsyncModeType;

/**
 * @brief   Specifies the identification (ID) for a SPI Hardware microcontroller peripheral (unit).
 */
/* SWS_Spi_00381 */
typedef uint8 Spi_Drvw_HWUnitType;

/**
 * @brief Type for defining the number of data elements of the type Spi_DataBufferType
 *          to send and/or receive by Channel.
 */
/* SWS_Spi_00377 */
typedef uint16 Spi_Drvw_NumberOfDataType;

/**
 * @brief   Type of application data buffer elements.
 */
/* SWS_Spi_00376 */
typedef uint8 Spi_Drvw_DataBufferType;

/**
 * @brief This structure holds the HWUnit configuration parameters.
 *
 */
typedef struct
{
    uint8                            Instance;
    uint32                           IsSync;
    uint32                           SpiCoreUse;
    const Spi_Drv_PhyUnitConfigType *PhyUnitConfigPtr;
} Spi_Drvw_HWUnitConfigType;

/**
 * @brief Defines the list type of HWUnit Configuration.
 */
typedef struct
{
    const Spi_Drvw_HWUnitConfigType *DrvwHWUnitConfig; /*!< Pointer to HWUnit configuration */
} Spi_Drvw_HWUnitConfigListType;

/**
 * @brief Defines the configuration parameters for each ExternalDevice.
 */
typedef struct
{
    uint8                             Instance;
    uint32                            SpiCoreUse;
    const Spi_Drv_ExternalDeviceType *DrvExternalDeviceConfigPtr;
} Spi_Drvw_ExternalDeviceConfigType;

/**
 * @brief   This structure holds the ExternalDevice configuration.
 */
typedef struct
{
    /** @brief Pointer to ExternalDevice configuration. */
    const Spi_Drvw_ExternalDeviceConfigType *DrvwExternalDeviceConfigPtr;
} Spi_Drvw_ExternalDeviceListType;

/**
 * @brief Defines the structure contains the pointers to the Tx/Rx Buffer
 */
typedef struct
{
    Spi_Drvw_DataBufferType *TxBuffer; /*!< Transmit buffer */
    Spi_Drvw_DataBufferType *RxBuffer; /*!< Receive buffer */
} Spi_Drvw_BufferDescriptorType;

/**
 * @brief Defines channel state structure.
 */
typedef struct
{
    uint8                     Flags;  /*!< Default Transmit Enabled. */
    Spi_Drvw_NumberOfDataType Length; /*!< Actual Transfer size for EB. */
} Spi_Drvw_ChannelStateType;

/**
 * @brief   The structure contains the channel configuration parameters.
 */
typedef struct
{
    Spi_Drvw_BufferType            BufferType;           /*!< Buffer Type IB/EB. */
    uint8                          FrameSize;            /*!< Data frame size. */
    boolean                        Lsb;                  /*!< Lsb or Msb first. */
    uint32                         DefaultTransmitValue; /*!< Default Transmit Value. */
    Spi_Drvw_NumberOfDataType      Length;               /*!< Data length */
    Spi_Drvw_BufferDescriptorType *BufferDescriptor;     /*!< Buffer Descriptor */
    uint32                         SpiCoreUse;           /*!< Used Core ID */
    Spi_Drvw_ChannelStateType     *ChannelState;         /*!< Pointer to channel state array */
} Spi_Drvw_ChannelConfigType;

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

/** @} end of group Spi_Drvw */

/** @} end of group Spi_Module */

#endif /*SPI_DRVW_TYPES_H*/
