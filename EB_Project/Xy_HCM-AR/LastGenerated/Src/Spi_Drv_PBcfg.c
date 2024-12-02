/**************************************************************************************************/
/**
 * @file      : Spi_Drv_PBcfg.c  
 * @brief     : Spi low level driver - Post-Build(PB) configuration file code template
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

/** @addtogroup Spi_Drv_Configuration
 *  @brief Spi low level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"
{
#endif

#include "Spi_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define SPI_DRV_PBCFG_C_VENDOR_ID                   0x00B3U
#define SPI_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define SPI_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define SPI_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define SPI_DRV_PBCFG_C_SW_MAJOR_VERSION            1U
#define SPI_DRV_PBCFG_C_SW_MINOR_VERSION            2U
#define SPI_DRV_PBCFG_C_SW_PATCH_VERSION            2U

/* Check if current file and Spi_Drv.h are the same vendor */
#if (SPI_DRV_PBCFG_C_VENDOR_ID != SPI_DRV_H_VENDOR_ID)
    #error "Vendor ID of Spi_Drv_PBcfg.c and Spi_Drv.h are different"
#endif
/* Check if current file and Spi_Drv.h are the same Autosar version */
#if ((SPI_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION != SPI_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION != SPI_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (SPI_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION != SPI_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Spi_Drv_PBcfg.c and Spi_Drv.h are different"
#endif
/* Check if current file and Spi_Drv.h are the same software version */
#if ((SPI_DRV_PBCFG_C_SW_MAJOR_VERSION != SPI_DRV_H_SW_MAJOR_VERSION) || \
     (SPI_DRV_PBCFG_C_SW_MINOR_VERSION != SPI_DRV_H_SW_MINOR_VERSION) || \
     (SPI_DRV_PBCFG_C_SW_PATCH_VERSION != SPI_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Spi_Drv_PBcfg.c and Spi_Drv.h are different"
#endif

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

/** @} end of group Private_VariableDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */
#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

/**
 * @brief External Device configuration: Spi_Drv_ExternalDeviceConfig_BD18397
 */
const Spi_Drv_ExternalDeviceType Spi_Drv_ExternalDeviceConfig_BD18397 =
{
    3U, /*!< Instance */
    1U, /*!< CS Identifier */
    0U, /*!< Clock Phase */
    0U, /*!< Clock Polarity */
    (uint32)24U, /*!< Clock Divider */
    0U, /*!< Transmit FIFO threshold */
    0U, /*!< Receive FIFO threshold */
    &Spi_Drv_DeviceParamArray[0U] /*!< Device Parameters */
};


/**
* @brief Spi PhyUnit configuration: Spi_Drv_PhyUnitConfig_SpiPhyUnit_0
*/
const Spi_Drv_PhyUnitConfigType Spi_Drv_PhyUnitConfig_SpiPhyUnit_0 =
{
    3U,  /*!< Instance */
    #if (SPI_DRV_SLAVE_SUPPORT == STD_ON)
        (boolean)FALSE, /*!< SlaveMode */
    #endif /* (SPI_DRV_SLAVE_SUPPORT == STD_ON) */
    #if (SPI_DRV_DMA_USED == STD_ON)
        (boolean)FALSE, /*!< DmaUsed */
        (uint8)0U, /*!< TxDmaChannel */
        (uint8)0U, /*!< RxDmaChannel */
    #endif /* (SPI_DRV_DMA_USED == STD_ON) */
    SPI_DRV_POLLING /*!< AsyncMode */
};


#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

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

/** @} end of group Spi_Drv_Configuration */

/** @} end of group Spi_Module */
