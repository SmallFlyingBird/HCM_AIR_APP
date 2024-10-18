/**************************************************************************************************/
/**
 * @file      : Eiru_Drv_Types.h
 * @brief     : Meh Extended MicroController Error Handle Types header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef EIRU_DRV_TYPES_H
#define EIRU_DRV_TYPES_H

/** @addtogroup  Meh_Module
 *  @{
 */

/** @defgroup Eiru_Drv
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "McalLib.h"
#include "Eiru_Drv_Cfg.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
/**
 *  @brief Published information
 */
#define EIRU_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define EIRU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define EIRU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define EIRU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define EIRU_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define EIRU_DRV_TYPES_H_SW_MINOR_VERSION            1U
#define EIRU_DRV_TYPES_H_SW_PATCH_VERSION            0U

/**
 *  @brief Check if current file and Eiru_Drv_Cfg.h are of the same vendor
 */
#if (EIRU_DRV_TYPES_H_VENDOR_ID != EIRU_DRV_CFG_H_VENDOR_ID)
    #error "Vendor ID of Eiru_Drv_Types.h and Eiru_Drv_Cfg.h are different"
#endif

/**
 *  @brief Check if current file and Eiru_Drv_Cfg.h are of the same Autosar version
 */
#if ((EIRU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != EIRU_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) ||     \
     (EIRU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != EIRU_DRV_CFG_H_AR_RELEASE_MINOR_VERSION) ||     \
     (EIRU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION != EIRU_DRV_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Eiru_Drv_Types.h and Eiru_Drv_Cfg.h are different"
#endif

/**
 *  @brief Check if current file and Eiru_Drv_Cfg.h are of the same SW version
 */
#if ((EIRU_DRV_TYPES_H_SW_MAJOR_VERSION != EIRU_DRV_CFG_H_SW_MAJOR_VERSION) ||                     \
     (EIRU_DRV_TYPES_H_SW_MINOR_VERSION != EIRU_DRV_CFG_H_SW_MINOR_VERSION) ||                     \
     (EIRU_DRV_TYPES_H_SW_PATCH_VERSION != EIRU_DRV_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Eiru_Drv_Types.h and Eiru_Drv_Cfg.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if Std_Types.h and Eiru_Drv_Types.h header files are of the same AUTOSAR version */
    #if ((STD_AR_RELEASE_MAJOR_VERSION != EIRU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||            \
         (STD_AR_RELEASE_MINOR_VERSION != EIRU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of Std_Types.h and Eiru_Drv_Types.h are different"
    #endif
    /* Check if McalLib.h and Eiru_Drv_Types.h header files are of the same AUTOSAR version */
    #if ((MCALLIB_AR_RELEASE_MAJOR_VERSION != EIRU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||        \
         (MCALLIB_AR_RELEASE_MINOR_VERSION != EIRU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of McalLib.h and Eiru_Drv_Types.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

#define EIRU_DRV_SRAM_ECC_ERR_OFFSET    28U
/** @} end of group Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/**
 *  @brief SRAM ID type definition
 */
typedef enum
{
    EIRU_DRV_SRAM_L = 0U, /*!< SRAML  */
    EIRU_DRV_SRAM_U       /*!< SRAMU  */
} Eiru_Drv_SramType;

/**
 *  @brief EIRU SRAM ECC error status definition
 */
typedef enum
{
    EIRU_DRV_SRAM_ECC_ERR_SINGLEBIT = 0x2U, /*!< SRAM ECC single bit error */
    EIRU_DRV_SRAM_ECC_ERR_MULTIBIT = 0x4U,  /*!< SRAM ECC multi bit error */
    EIRU_DRV_SRAM_ECC_ERR_OVERRUN = 0x8U,   /*!< SRAM ECC error overrun */
} Eiru_Drv_SramEccErrStatusType;

/**
 *  @brief EIRU master definition
 */
typedef enum
{
    EIRU_DRV_MASTER_CORE = 0U, /*!< Master: CPU */
    EIRU_DRV_MASTER_DEBUGGER,  /*!< Master: DEBUGGER */
    EIRU_DRV_MASTER_DMA,       /*!< Master: DMA */
} Eiru_Drv_MasterType;

/**
 *  @brief EIRU access size definition
 */
typedef enum
{
    EIRU_DRV_ACC_SIZE_8BIT = 0U, /*!< access size: 8 bits */
    EIRU_DRV_ACC_SIZE_16BIT,     /*!< access size: 16 bits */
    EIRU_DRV_ACC_SIZE_32BIT      /*!< access size: 32 bits */
} Eiru_Drv_AccessSizeType;

/**
 *  @brief EIRU access type definition
 */
typedef enum
{
    EIRU_DRV_ACC_TYPE_OPCODE = 0U, /*!< access type: opcode fetch */
    EIRU_DRV_ACC_TYPE_DATA         /*!< access type: data access */
} Eiru_Drv_AccessType;

/**
 *  @brief EIRU access mode definition
 */
typedef enum
{
    EIRU_DRV_ACC_MODE_USER = 0U, /*!< access mode: user */
    EIRU_DRV_ACC_MODE_PRIVIL     /*!< access mode: privileged */
} Eiru_Drv_AccessModeType;

/**
 *  @brief EIRU SRAM config struct definition
 */
typedef struct
{
    boolean SramLEccErrorInjectEnable; /*!< EIRU ECC error injection enable */
    boolean SramLSingleBitDisable; /*!< Disable single bit ECC when accesses SRAM */
    boolean SramLMultiBitDisable;  /*!< Enable/disable multi bit ECC when accesses SRAM */

    boolean SramUEccErrorInjectEnable; /*!< EIRU ECC error injection enable */
    boolean SramUSingleBitDisable; /*!< Disable single bit ECC when accesses SRAM */
    boolean SramUMultiBitDisable;  /*!< Enable/disable multi bit ECC when accesses SRAM */
} Eiru_Drv_SramEccConfigType;

/**
 *  @brief EIRU SRAM ECC error cause struct definition
 */
typedef struct
{
    uint32                  ErrFaultAddr;   /*!< The access address that caused ECC error */
    uint32                  ErrFaultData;   /*!< The fault data  */
    Eiru_Drv_MasterType     ErrFaultMaster; /*!< Indicates error caused by which master.*/
    Eiru_Drv_AccessSizeType ErrFaultSize;   /*!< Indicates error caused by  what size of access.*/
    Eiru_Drv_AccessType     AccessType;     /*!< Indicates error caused by which type of access.*/
    Eiru_Drv_AccessModeType AccessMode;     /*!< Indicates error caused in which mode */
} Eiru_Drv_SramEccErrCauseType;

/** @} end of group Private_TypeDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Eiru_Drv */

/** @} end of group Meh_Module */
#endif /* EIRU_DRV_TYPES_H */
