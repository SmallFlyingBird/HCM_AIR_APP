/**************************************************************************************************/
/**
 * @file      : Meh_Types.h
 * @brief     : Meh Extended MicroController Error Handle Types header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef MEH_TYPES_H
#define MEH_TYPES_H

/** @addtogroup  Meh_Module
 *  @{
 */

/** @defgroup Meh
 *  @brief Extended MicroController Error Handle
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Eiru_Drv_Types.h"
#include "Seru_Drv_Types.h"
#include "Meh_Cfg.h"


/** @defgroup Private_MacroDefinition
 *  @{
 */
/**
 *  @brief Published information
 */
#define MEH_TYPES_H_VENDOR_ID                   0x00B3U
#define MEH_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define MEH_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define MEH_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define MEH_TYPES_H_SW_MAJOR_VERSION            1U
#define MEH_TYPES_H_SW_MINOR_VERSION            1U
#define MEH_TYPES_H_SW_PATCH_VERSION            0U

/**
 *  @brief Check if current file and Seru_Drv_Types.h are of the same vendor
 */
#if (SERU_DRV_TYPES_H_VENDOR_ID != MEH_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Seru_Drv_Types.h and Meh_Types.h are different"
#endif

/**
 *  @brief Check if current file and Seru_Drv_Types.h are of the same Autosar version
 */
#if ((SERU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MEH_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||    \
        (SERU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MEH_TYPES_H_AR_RELEASE_MINOR_VERSION) ||    \
        (SERU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION !=                                          \
        MEH_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Seru_Drv_Types.h and Meh_Types.h are different"
#endif

/**
 *  @brief Check if current file and Seru_Drv_Types.h are of the same SW version
 */
#if ((SERU_DRV_TYPES_H_SW_MAJOR_VERSION != MEH_TYPES_H_SW_MAJOR_VERSION) ||                    \
        (SERU_DRV_TYPES_H_SW_MINOR_VERSION != MEH_TYPES_H_SW_MINOR_VERSION) ||                    \
        (SERU_DRV_TYPES_H_SW_PATCH_VERSION != MEH_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Seru_Drv_Types.h and Meh_Types.h are different"
#endif

/**
 *  @brief Check if current file and Eiru_Drv_Types.h are of the same vendor
 */
#if (EIRU_DRV_TYPES_H_VENDOR_ID != MEH_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Eiru_Drv_Types.h and Meh_Types.h are different"
#endif

/**
 *  @brief Check if current file and Eiru_Drv_Types.h are of the same Autosar version
 */
#if ((EIRU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MEH_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||    \
        (EIRU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MEH_TYPES_H_AR_RELEASE_MINOR_VERSION) ||    \
        (EIRU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION !=                                          \
        MEH_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Eiru_Drv_Types.h and Meh_Types.h are different"
#endif

/**
 *  @brief Check if current file and Eiru_Drv_Types.h are of the same SW version
 */
#if ((EIRU_DRV_TYPES_H_SW_MAJOR_VERSION != MEH_TYPES_H_SW_MAJOR_VERSION) ||                    \
        (EIRU_DRV_TYPES_H_SW_MINOR_VERSION != MEH_TYPES_H_SW_MINOR_VERSION) ||                    \
        (EIRU_DRV_TYPES_H_SW_PATCH_VERSION != MEH_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Eiru_Drv_Types.h and Meh_Types.h are different"
#endif

/**
 *  @brief Check if current file and Meh_Cfg.h are of the same vendor
 */
#if (MEH_CFG_H_VENDOR_ID != MEH_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Meh_Cfg.h and Meh_Types.h are different"
#endif

/**
 *  @brief Check if current file and Meh_Cfg.h are of the same Autosar version
 */
#if ((MEH_CFG_H_AR_RELEASE_MAJOR_VERSION != MEH_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||           \
        (MEH_CFG_H_AR_RELEASE_MINOR_VERSION != MEH_TYPES_H_AR_RELEASE_MINOR_VERSION) ||           \
        (MEH_CFG_H_AR_RELEASE_REVISION_VERSION != MEH_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Meh_Cfg.h and Meh_Types.h are different"
#endif

/**
 *  @brief Check if current file and Meh_Cfg.h are of the same SW version
 */
#if ((MEH_CFG_H_SW_MAJOR_VERSION != MEH_TYPES_H_SW_MAJOR_VERSION) ||                           \
        (MEH_CFG_H_SW_MINOR_VERSION != MEH_TYPES_H_SW_MINOR_VERSION) ||                           \
        (MEH_CFG_H_SW_PATCH_VERSION != MEH_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Meh_Cfg.h and Meh_Types.h are different"
#endif
/** @} end of group Private_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 *  @brief EIRU master definition
 */
typedef enum
{
    MEH_MASTER_CORE = 0U, /*!< Master: CPU */
    MEH_MASTER_DEBUGGER,  /*!< Master: DEBUGGER */
    MEH_MASTER_DMA,       /*!< Master: DMA */
} Meh_MasterType;

/**
 *  @brief EIRU access size definition
 */
typedef enum
{
    MEH_ACC_SIZE_8BIT = 0U, /*!< access size: 8 bits */
    MEH_ACC_SIZE_16BIT,     /*!< access size: 16 bits */
    MEH_ACC_SIZE_32BIT      /*!< access size: 32 bits */
} Meh_AccessSizeType;

/**
 *  @brief EIRU access type definition
 */
typedef enum
{
    MEH_ACC_TYPE_OPCODE = 0U, /*!< access type: opcode fetch */
    MEH_ACC_TYPE_DATA         /*!< access type: data access */
} Meh_AccessType;

/**
 *  @brief EIRU access mode definition
 */
typedef enum
{
    MEH_ACC_MODE_USER = 0U, /*!< access mode: user */
    MEH_ACC_MODE_PRIVIL     /*!< access mode: privileged */
} Meh_AccessModeType;

/**
 *  @brief EIRU SRAM ECC error cause struct definition
 */
typedef struct
{
    uint32                  ErrFaultAddr;   /*!< The access address that caused ECC error */
    uint32                  ErrFaultData;   /*!< The fault data  */
    Meh_MasterType          ErrFaultMaster; /*!< Indicates error caused by which master.*/
    Meh_AccessSizeType      ErrFaultSize;   /*!< Indicates error caused by  what size of access.*/
    Meh_AccessType          AccessType;     /*!< Indicates error caused by which type of access.*/
    Meh_AccessModeType      AccessMode;     /*!< Indicates error caused in which mode */
} Meh_SramEccErrCauseType;

/**
 *  @brief EIRU SRAM ECC error status definition
 */
typedef enum
{
    MEH_SRAM_ECC_ERR_SINGLEBIT = 0x2U, /*!< SRAM ECC single bit error */
    MEH_SRAM_ECC_ERR_MULTIBIT = 0x4U,  /*!< SRAM ECC multi bit error */
    MEH_SRAM_ECC_ERR_OVERRUN = 0x8U,   /*!< SRAM ECC error overrun */
} Meh_SramEccErrStatusType;

/**
 *  @brief SRAM ID type definition
 */
typedef enum
{
    MEH_SRAM_L = 0U, /*!< SRAML  */
    MEH_SRAM_U       /*!< SRAMU  */
} Meh_SramType;

/**
 *  @brief Error callback function type
 */
typedef void(Meh_EiruErrCallBackFunType)(const Meh_SramType             Sram,
                                         const Meh_SramEccErrStatusType ErrorStatus,
                                         Meh_SramEccErrCauseType       *ErrorCausePtr);
/**
 *  @brief Meh init configure struct definition
 */
typedef struct
{
    const Eiru_Drv_SramEccConfigType *EiruConfigPtr;
    const Seru_Drv_ConfigType        *SeruConfigPtr;
} Meh_ConfigType;

/** @} end of group Public_TypeDefinition */

    #ifdef __cplusplus
}
    #endif

/** @} end of group Meh */
/** @} end of group Meh_Module */

#endif /* MEH_TYPES_H */

/** @} */
