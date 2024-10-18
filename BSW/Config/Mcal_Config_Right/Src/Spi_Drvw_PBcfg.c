/**************************************************************************************************/
/**
 * @file      : Spi_Drvw_PBcfg.c
 * @brief     : Spi driver wrapper - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Spi_Module
 *  @{
 */

/** @addtogroup Spi_Drvw_Configuration
 *  @brief Spi driver wrapper configuration
 *  @{
 */
#ifdef __cplusplus
extern "C"{
#endif

#include "Spi_Drvw.h"
#include "Spi_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define SPI_DRVW_PBCFG_C_VENDOR_ID                   0x00B3U
#define SPI_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define SPI_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define SPI_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define SPI_DRVW_PBCFG_C_SW_MAJOR_VERSION            1U
#define SPI_DRVW_PBCFG_C_SW_MINOR_VERSION            2U
#define SPI_DRVW_PBCFG_C_SW_PATCH_VERSION            1U

/* Check if current file and Spi_Drvw.h are the same vendor */
#if (SPI_DRVW_PBCFG_C_VENDOR_ID != SPI_DRVW_H_VENDOR_ID)
    #error "Vendor ID of Spi_Drvw_PBcfg.c and Spi_Drvw.h are different"
#endif
/* Check if current file and Spi_Drvw.h are the same Autosar version */
#if ((SPI_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION != SPI_DRVW_H_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION != SPI_DRVW_H_AR_RELEASE_MINOR_VERSION) || \
     (SPI_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION != SPI_DRVW_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Spi_Drvw_PBcfg.c and Spi_Drvw.h are different"
#endif
/* Check if current file and Spi_Drvw.h are the same software version */
#if ((SPI_DRVW_PBCFG_C_SW_MAJOR_VERSION != SPI_DRVW_H_SW_MAJOR_VERSION) || \
     (SPI_DRVW_PBCFG_C_SW_MINOR_VERSION != SPI_DRVW_H_SW_MINOR_VERSION) || \
     (SPI_DRVW_PBCFG_C_SW_PATCH_VERSION != SPI_DRVW_H_SW_PATCH_VERSION))
    #error "Software Version of Spi_Drvw_PBcfg.c and Spi_Drvw.h are different"
#endif

/* Check if current file and Spi_Drv.h are the same vendor */
#if (SPI_DRVW_PBCFG_C_VENDOR_ID != SPI_DRV_H_VENDOR_ID)
    #error "Vendor ID of Spi_Drvw_PBcfg.c and Spi_Drv.h are different"
#endif
/* Check if current file and Spi_Drv.h are the same Autosar version */
#if ((SPI_DRVW_PBCFG_C_AR_RELEASE_MAJOR_VERSION != SPI_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_DRVW_PBCFG_C_AR_RELEASE_MINOR_VERSION != SPI_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (SPI_DRVW_PBCFG_C_AR_RELEASE_REVISION_VERSION != SPI_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Spi_Drvw_PBcfg.c and Spi_Drv.h are different"
#endif
/* Check if current file and Spi_Drv.h are the same software version */
#if ((SPI_DRVW_PBCFG_C_SW_MAJOR_VERSION != SPI_DRV_H_SW_MAJOR_VERSION) || \
     (SPI_DRVW_PBCFG_C_SW_MINOR_VERSION != SPI_DRV_H_SW_MINOR_VERSION) || \
     (SPI_DRVW_PBCFG_C_SW_PATCH_VERSION != SPI_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Spi_Drvw_PBcfg.c and Spi_Drv.h are different"
#endif

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */
#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

/**
* @brief Spi External device configuration: Spi_ExternalDeviceConfig_BD18397
*/
static const Spi_Drvw_ExternalDeviceConfigType Spi_ExternalDeviceConfig_BD18397 =
{
    3U, /*!< Instance */
    0U, /*!< SpiCoreUse */
    &Spi_Drv_ExternalDeviceConfig_BD18397 /*!< DrvExternalDeviceConfigPtr */
};

/**
* @brief Spi External device configuration: Spi_ExternalDeviceConfig_TPS92682
*/
static const Spi_Drvw_ExternalDeviceConfigType Spi_ExternalDeviceConfig_TPS92682 =
{
    3U, /*!< Instance */
    0U, /*!< SpiCoreUse */
    &Spi_Drv_ExternalDeviceConfig_TPS92682 /*!< DrvExternalDeviceConfigPtr */
};

/**
* @brief Spi External device configuration: Spi_ExternalDeviceConfig_DRV8889
*/
static const Spi_Drvw_ExternalDeviceConfigType Spi_ExternalDeviceConfig_DRV8889 =
{
    1U, /*!< Instance */
    0U, /*!< SpiCoreUse */
    &Spi_Drv_ExternalDeviceConfig_DRV8889 /*!< DrvExternalDeviceConfigPtr */
};


/**
* @brief Spi External device configuration list: Spi_ExternalDeviceConfigList[3U]
*/
const Spi_Drvw_ExternalDeviceListType Spi_ExternalDeviceConfigList[3U] =
{
    {&Spi_ExternalDeviceConfig_BD18397},
    {&Spi_ExternalDeviceConfig_TPS92682},
    {&Spi_ExternalDeviceConfig_DRV8889}
};


/**
* @brief Spi HWUnit configuration: Spi_HwUnitConfig_SpiPhyUnit_BoostBuck
*/
static const Spi_Drvw_HWUnitConfigType Spi_HwUnitConfig_SpiPhyUnit_BoostBuck =
{
    (uint8)3U, /*!< Instance */
    SPI_DRVW_PHYUNIT_SYNC, /* IsSync */
    0U, /* SpiCoreUse */
    &Spi_Drv_PhyUnitConfig_SpiPhyUnit_BoostBuck /* PhyUnitConfigPtr */
};

/**
* @brief Spi HWUnit configuration: Spi_HwUnitConfig_SpiPhyUnit_Motor
*/
static const Spi_Drvw_HWUnitConfigType Spi_HwUnitConfig_SpiPhyUnit_Motor =
{
    (uint8)1U, /*!< Instance */
    SPI_DRVW_PHYUNIT_SYNC, /* IsSync */
    0U, /* SpiCoreUse */
    &Spi_Drv_PhyUnitConfig_SpiPhyUnit_Motor /* PhyUnitConfigPtr */
};

/**
* @brief Spi HWUnit configuration list: Spi_HwUnitConfigList[SPI_DRVW_MAX_HWUNITS_CFG]
*/
const Spi_Drvw_HWUnitConfigListType Spi_HwUnitConfigList[SPI_DRVW_MAX_HWUNITS_CFG] =
{
    {&Spi_HwUnitConfig_SpiPhyUnit_BoostBuck},
    {&Spi_HwUnitConfig_SpiPhyUnit_Motor}
};


#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"
/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

/** @} end of group Private_VariableDefinition */

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

/** @} end of group Spi_Drvw_Configuration */

/** @} end of group Spi_Module */
