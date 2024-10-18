/**************************************************************************************************/
/**
 * @file      : Smpu_Drv_Types.h
 * @brief     : System memory protect unit Types header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef SMPU_DRV_TYPES_H
#define SMPU_DRV_TYPES_H

/** @addtogroup  Smpu_Module
 *  @{
 */

/** @addtogroup  Smpu
 *  @brief Smpu Types
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "McalLib.h"
#include "Smpu_Drv_Cfg.h"
/** @defgroup Private_MacroDefinition
 *  @{
 */

/**
 *  @brief Published information
 */
#define SMPU_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define SMPU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define SMPU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define SMPU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define SMPU_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define SMPU_DRV_TYPES_H_SW_MINOR_VERSION            1U
#define SMPU_DRV_TYPES_H_SW_PATCH_VERSION            0U

/**
 *  @brief Check if current file and Smpu_Drv_Cfg.h are of the same vendor
 */
#if (SMPU_DRV_TYPES_H_VENDOR_ID != SMPU_DRV_CFG_H_VENDOR_ID)
    #error "Vendor ID of Smpu_Drv_Types.h and Smpu_Drv_Cfg.h are different"
#endif

/**
 *  @brief Check if current file and Smpu_Drv_Cfg.h are of the same Autosar version
 */
#if ((SMPU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != SMPU_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) ||     \
     (SMPU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != SMPU_DRV_CFG_H_AR_RELEASE_MINOR_VERSION) ||     \
     (SMPU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION != SMPU_DRV_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Smpu_Drv_Types.h and Smpu_Drv_Cfg.h are different"
#endif

/**
 *  @brief Check if current file and Smpu_Drv_Cfg.h are of the same SW version
 */
#if ((SMPU_DRV_TYPES_H_SW_MAJOR_VERSION != SMPU_DRV_CFG_H_SW_MAJOR_VERSION) ||                     \
     (SMPU_DRV_TYPES_H_SW_MINOR_VERSION != SMPU_DRV_CFG_H_SW_MINOR_VERSION) ||                     \
     (SMPU_DRV_TYPES_H_SW_PATCH_VERSION != SMPU_DRV_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Smpu_Drv_Types.h and Smpu_Drv_Cfg.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if Std_Types.h and Smpu_Drv_Types.h header files are of the same AUTOSAR version */
    #if ((STD_AR_RELEASE_MAJOR_VERSION != SMPU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||            \
         (STD_AR_RELEASE_MINOR_VERSION != SMPU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of Std_Types.h and Smpu_Drv_Types.h are different"
    #endif
    /* Check if McalLib.h and Smpu_Drv_Types.h header files are of the same AUTOSAR version */
    #if ((MCALLIB_AR_RELEASE_MAJOR_VERSION != SMPU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||        \
         (MCALLIB_AR_RELEASE_MINOR_VERSION != SMPU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version of McalLib.h and Smpu_Drv_Types.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/** @} end of group Private_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 *  @brief SMPU bus master type definition
 */
typedef enum
{
    SMPU_DRV_BUS_MASTER_0 = 0U, /*!< Bus master 0,indicate core */
    SMPU_DRV_BUS_MASTER_1,      /*!< Bus master 1,indicate debug */
    SMPU_DRV_BUS_MASTER_2,      /*!< Bus master 2,indicate dma*/
    SMPU_DRV_BUS_MASTER_ALL,    /*!< All master ports numbers */
} Smpu_Drv_BusMasterType;

/**
 *  @brief SMPU slave port type definition
 */
typedef enum
{
    SMPU_DRV_SLV_PORT_0 = 0U, /*!< Slave port 0,indicate flash  */
    SMPU_DRV_SLV_PORT_1,      /*!< Slave port 1,indicate sraml  */
    SMPU_DRV_SLV_PORT_2,      /*!< Slave port 2,indicate sramu  */
    SMPU_DRV_SLV_PORT_ALL,    /*!< All slave ports numbers */
} Smpu_Drv_SlavePortType;


/**
 *  @brief Smpu access control for bus master in supervisor mode type definition
 */
typedef enum
{
    SMPU_DRV_ALL_ALLOWED = 0U,   /*!< Read/write/execute are all allowed */
    SMPU_DRV_READ_EXE_ALLOWED,   /*!< Read/execute are allowed, write is not allowed */
    SMPU_DRV_READ_WRITE_ALLOWED, /*!< Read/write are allowed, execute is not allowed */
    SMPU_DRV_SAME_WITH_USERMODE, /*!< Access control are same with user mode */
} Smpu_Drv_SupervisorModeAccessType;

/**
 *  @brief SMPU access type definition
 */
typedef enum
{
    SMPU_DRV_ACC_TYPE_INS = 0U, /*!< Access type: instruction access  */
    SMPU_DRV_ACC_TYPE_DATA      /*!< Access type: data access     */
} Smpu_Drv_AccessErrorType;

/**
 *  @brief Smpu access mode definition
 */
typedef enum
{
    SMPU_DRV_ACC_MODE_USER = 0U, /*!< Access mode: user mode       */
    SMPU_DRV_ACC_MODE_SVR        /*!< Access mode: supervisor mode */
} Smpu_Drv_AccessModeType;

/**
 *  @brief SMPU slave port error cause struct definition
 */
typedef struct
{
    uint32                    ErrorAddress; /*!< Error Address.         */
    uint16 MrcnIndication;    /*!< MRC Number by MRCn(n=0~15) ,Bit n corresponds to MRCn, 
                                     bit n set 1 when error occurs in MRCn.*/
    Smpu_Drv_BusMasterType    BusMasterId;  /*!< Bus Master Id.        */
    Smpu_Drv_AccessErrorType  AccessError;  /*!< Indicates error caused by which type of access */
    Smpu_Drv_AccessModeType   AccessMode;   /*!< Indicates error caused in which mode. */
    boolean                   IsWriteError; /*!< whether slave port is caused by writing operation
                                                     - FALSE: it is caused by reading
                                                     - TRUE: it is caused by writing */
} Smpu_Drv_SalveErrorType;

/**
 *  @brief SMPU init configure struct definition
 */
typedef struct
{
    Smpu_Drv_BusMasterType BusMaster; /*!< Bus master number.
                                  - SMPU_DRV_BUS_MASTER_0
                                  - SMPU_DRV_BUS_MASTER_1
                                  - SMPU_DRV_BUS_MASTER_2 */
    boolean UserExeAllow;            /*!< Enable/Disable execute access.*/
    boolean UserWriteAllow;          /*!< Enable/Disable write access. */
    boolean UserReadAllow;           /*!< Enable/Disable read access.  */
    Smpu_Drv_SupervisorModeAccessType
        SupervisorModeAccess; /*!< Access control in supervisor mode.*/
} Smpu_Drv_RegionMasterAccessType;

/**
 *  @brief Smpu init configure struct definition
 */
typedef struct
{
    uint32                          RegionId;       /*!< Region ID pointer to MRCn(n=0~15) */
    uint32                          StartAddress;   /*!< Start address protected by MRCn(n=0~15) */
    uint32                          EndAddress;     /*!< End address protected by MRCn(n=0~15) */
    boolean                         RegionState;    /*!< Enable/Disable current region.        */
    Smpu_Drv_RegionMasterAccessType MasterAccess[3]; /*!< Access control for bus master.*/
} Smpu_Drv_RegionConfigType;

/** @} end of group Public_TypeDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Smpu */

/** @} end of group Smpu_Module */
#endif /* SMPU_DRV_TYPES_H */
