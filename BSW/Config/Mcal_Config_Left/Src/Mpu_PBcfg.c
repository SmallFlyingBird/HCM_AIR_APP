/**************************************************************************************************/
/**
 * @file      : Mpu_PBcfg.c
 * @brief     : Memory protect unit header file configuration source file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Mpu_Module
 *  @{
 */

/** @addtogroup Mpu configuration
 *  @brief Mpu configuration source file
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Mpu.h"
/** @defgroup Public_MacroDefinition
 *  @{
 */

/**
 *  @brief Published information
 */
#define MPU_PBCFG_C_VENDOR_ID                   0x00B3U
#define MPU_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define MPU_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define MPU_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define MPU_PBCFG_C_SW_MAJOR_VERSION            1U
#define MPU_PBCFG_C_SW_MINOR_VERSION            1U
#define MPU_PBCFG_C_SW_PATCH_VERSION            0U

/**
 *  @brief Check if current file and Mpu.h are of the same vendor
 */
#if (MPU_PBCFG_C_VENDOR_ID != MPU_VENDOR_ID)
    #error "Vendor ID of Mpu_PBcfg.c and Mpu.h are different"
#endif

/**
 *  @brief Check if current file and Mpu.h are of the same Autosar version
 */
#if ((MPU_PBCFG_C_AR_RELEASE_MAJOR_VERSION != MPU_AR_RELEASE_MAJOR_VERSION) ||                 \
     (MPU_PBCFG_C_AR_RELEASE_MINOR_VERSION != MPU_AR_RELEASE_MINOR_VERSION) ||                 \
     (MPU_PBCFG_C_AR_RELEASE_REVISION_VERSION != MPU_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version of Mpu_PBcfg.c and Mpu.h are different"
#endif

/**
 *  @brief Check if current file and Mpu.h are of the same SW version
 */
#if ((MPU_PBCFG_C_SW_MAJOR_VERSION != MPU_SW_MAJOR_VERSION) ||                                 \
     (MPU_PBCFG_C_SW_MINOR_VERSION != MPU_SW_MINOR_VERSION) ||                                 \
     (MPU_PBCFG_C_SW_PATCH_VERSION != MPU_SW_PATCH_VERSION))
    #error "Software Version of Mpu_PBcfg.c and Mpu.h are different"
#endif
/** @} end of group Public_MacroDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */
#define MPU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mpu_MemMap.h"
/**
* @brief Mpu regions configuration.
*
*/
static const Mpu_RegionConfigType Mpu_RegionConfig[MPU_CONFIG_REGION_NUM] =    
{

    /*Memory Region configuration */
    {
    0U,                                             /*!< Memory Region ID */
    0x20000000U,                        /*!< Memory Region Start Address */
    0x20000040U,                        /*!< Memory Region End Address */
    FALSE,                             /*!< Memory Region State :TRUE or FALSE */
    {
        
        {
            SMPU_DRV_BUS_MASTER_0,              /*!< Master 0 */
            TRUE,                         /*!< Master 0 user execute allow*/
            TRUE,                         /*!< Master 0 user write allow*/
            TRUE,                         /*!< Master 0 user read allow*/
            SMPU_DRV_ALL_ALLOWED,        /*!< Master 0 supervisor access allow type*/
        },
        
        {
            SMPU_DRV_BUS_MASTER_1,              /*!< Master 1 */
            TRUE,                         /*!< Master 1 user execute allow*/
            TRUE,                         /*!< Master 1 user write allow*/
            TRUE,                         /*!< Master 1 user read allow*/
            SMPU_DRV_ALL_ALLOWED,        /*!< Master 1 supervisor access allow type*/
        },
        
        {
            SMPU_DRV_BUS_MASTER_2,              /*!< Master 2 */
            TRUE,                         /*!< Master 2 user execute allow*/
            TRUE,                         /*!< Master 2 user write allow*/
            TRUE,                         /*!< Master 2 user read allow*/
            SMPU_DRV_ALL_ALLOWED,        /*!< Master 2 supervisor access allow type*/
        },
        
    }  
    },

    /*Memory Region configuration */
    {
    1U,                                             /*!< Memory Region ID */
    0x0U,                        /*!< Memory Region Start Address */
    0x1fffffU,                        /*!< Memory Region End Address */
    TRUE,                             /*!< Memory Region State :TRUE or FALSE */
    {
        
        {
            SMPU_DRV_BUS_MASTER_0,              /*!< Master 0 */
            TRUE,                         /*!< Master 0 user execute allow*/
            TRUE,                         /*!< Master 0 user write allow*/
            TRUE,                         /*!< Master 0 user read allow*/
            SMPU_DRV_ALL_ALLOWED,        /*!< Master 0 supervisor access allow type*/
        },
        
        {
            SMPU_DRV_BUS_MASTER_1,              /*!< Master 1 */
            TRUE,                         /*!< Master 1 user execute allow*/
            TRUE,                         /*!< Master 1 user write allow*/
            TRUE,                         /*!< Master 1 user read allow*/
            SMPU_DRV_ALL_ALLOWED,        /*!< Master 1 supervisor access allow type*/
        },
        
        {
            SMPU_DRV_BUS_MASTER_2,              /*!< Master 2 */
            TRUE,                         /*!< Master 2 user execute allow*/
            TRUE,                         /*!< Master 2 user write allow*/
            TRUE,                         /*!< Master 2 user read allow*/
            SMPU_DRV_ALL_ALLOWED,        /*!< Master 2 supervisor access allow type*/
        },
        
    }  
    },

    /*Memory Region configuration */
    {
    2U,                                             /*!< Memory Region ID */
    0x1000000U,                        /*!< Memory Region Start Address */
    0x101ffffU,                        /*!< Memory Region End Address */
    TRUE,                             /*!< Memory Region State :TRUE or FALSE */
    {
        
        {
            SMPU_DRV_BUS_MASTER_0,              /*!< Master 0 */
            TRUE,                         /*!< Master 0 user execute allow*/
            TRUE,                         /*!< Master 0 user write allow*/
            TRUE,                         /*!< Master 0 user read allow*/
            SMPU_DRV_ALL_ALLOWED,        /*!< Master 0 supervisor access allow type*/
        },
        
        {
            SMPU_DRV_BUS_MASTER_1,              /*!< Master 1 */
            TRUE,                         /*!< Master 1 user execute allow*/
            TRUE,                         /*!< Master 1 user write allow*/
            TRUE,                         /*!< Master 1 user read allow*/
            SMPU_DRV_ALL_ALLOWED,        /*!< Master 1 supervisor access allow type*/
        },
        
        {
            SMPU_DRV_BUS_MASTER_2,              /*!< Master 2 */
            TRUE,                         /*!< Master 2 user execute allow*/
            TRUE,                         /*!< Master 2 user write allow*/
            TRUE,                         /*!< Master 2 user read allow*/
            SMPU_DRV_ALL_ALLOWED,        /*!< Master 2 supervisor access allow type*/
        },
        
    }  
    },

    /*Memory Region configuration */
    {
    3U,                                             /*!< Memory Region ID */
    0x1ffe0000U,                        /*!< Memory Region Start Address */
    0x1fffffffU,                        /*!< Memory Region End Address */
    TRUE,                             /*!< Memory Region State :TRUE or FALSE */
    {
        
        {
            SMPU_DRV_BUS_MASTER_0,              /*!< Master 0 */
            TRUE,                         /*!< Master 0 user execute allow*/
            TRUE,                         /*!< Master 0 user write allow*/
            TRUE,                         /*!< Master 0 user read allow*/
            SMPU_DRV_ALL_ALLOWED,        /*!< Master 0 supervisor access allow type*/
        },
        
        {
            SMPU_DRV_BUS_MASTER_1,              /*!< Master 1 */
            TRUE,                         /*!< Master 1 user execute allow*/
            TRUE,                         /*!< Master 1 user write allow*/
            TRUE,                         /*!< Master 1 user read allow*/
            SMPU_DRV_ALL_ALLOWED,        /*!< Master 1 supervisor access allow type*/
        },
        
        {
            SMPU_DRV_BUS_MASTER_2,              /*!< Master 2 */
            TRUE,                         /*!< Master 2 user execute allow*/
            TRUE,                         /*!< Master 2 user write allow*/
            TRUE,                         /*!< Master 2 user read allow*/
            SMPU_DRV_ALL_ALLOWED,        /*!< Master 2 supervisor access allow type*/
        },
        
    }  
    },

    /*Memory Region configuration */
    {
    4U,                                             /*!< Memory Region ID */
    0x2000000U,                        /*!< Memory Region Start Address */
    0x2007fffU,                        /*!< Memory Region End Address */
    TRUE,                             /*!< Memory Region State :TRUE or FALSE */
    {
        
        {
            SMPU_DRV_BUS_MASTER_0,              /*!< Master 0 */
            TRUE,                         /*!< Master 0 user execute allow*/
            TRUE,                         /*!< Master 0 user write allow*/
            TRUE,                         /*!< Master 0 user read allow*/
            SMPU_DRV_ALL_ALLOWED,        /*!< Master 0 supervisor access allow type*/
        },
        
        {
            SMPU_DRV_BUS_MASTER_1,              /*!< Master 1 */
            TRUE,                         /*!< Master 1 user execute allow*/
            TRUE,                         /*!< Master 1 user write allow*/
            TRUE,                         /*!< Master 1 user read allow*/
            SMPU_DRV_ALL_ALLOWED,        /*!< Master 1 supervisor access allow type*/
        },
        
        {
            SMPU_DRV_BUS_MASTER_2,              /*!< Master 2 */
            TRUE,                         /*!< Master 2 user execute allow*/
            TRUE,                         /*!< Master 2 user write allow*/
            TRUE,                         /*!< Master 2 user read allow*/
            SMPU_DRV_ALL_ALLOWED,        /*!< Master 2 supervisor access allow type*/
        },
        
    }  
    },

    /*Memory Region configuration */
    {
    5U,                                             /*!< Memory Region ID */
    0x20000040U,                        /*!< Memory Region Start Address */
    0x2001ffffU,                        /*!< Memory Region End Address */
    TRUE,                             /*!< Memory Region State :TRUE or FALSE */
    {
        
        {
            SMPU_DRV_BUS_MASTER_0,              /*!< Master 0 */
            TRUE,                         /*!< Master 0 user execute allow*/
            TRUE,                         /*!< Master 0 user write allow*/
            TRUE,                         /*!< Master 0 user read allow*/
            SMPU_DRV_ALL_ALLOWED,        /*!< Master 0 supervisor access allow type*/
        },
        
        {
            SMPU_DRV_BUS_MASTER_1,              /*!< Master 1 */
            TRUE,                         /*!< Master 1 user execute allow*/
            TRUE,                         /*!< Master 1 user write allow*/
            TRUE,                         /*!< Master 1 user read allow*/
            SMPU_DRV_ALL_ALLOWED,        /*!< Master 1 supervisor access allow type*/
        },
        
        {
            SMPU_DRV_BUS_MASTER_2,              /*!< Master 2 */
            TRUE,                         /*!< Master 2 user execute allow*/
            TRUE,                         /*!< Master 2 user write allow*/
            TRUE,                         /*!< Master 2 user read allow*/
            SMPU_DRV_ALL_ALLOWED,        /*!< Master 2 supervisor access allow type*/
        },
        
    }  
    },

};
/**
* @brief Mpu configuration.
*
*/
static const Mpu_ConfigType Mpu_Config = 
{
    FALSE,       /*boolean GlobalMpuControlState */
    6U,      /*Number of regions that are configured */
    Mpu_RegionConfig
};
#define MPU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mpu_MemMap.h"
#define MPU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mpu_MemMap.h"
/**
* @brief Mpu configuration data for Mpu_PreDefinedConfigPtr.
*
*/
const Mpu_ConfigType * const Mpu_PreDefinedConfigPtr = &Mpu_Config;

#define MPU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mpu_MemMap.h"
/** @} end of group Global_VariableDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Mpu configuration */

/** @} end of group Mpu_Module */
