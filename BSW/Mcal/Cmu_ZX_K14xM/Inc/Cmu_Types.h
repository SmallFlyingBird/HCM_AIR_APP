/**************************************************************************************************/
/**
 * @file      : Cmu_Types.h
 * @brief     : AUTOSAR Cmu driver type definition header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef CMU_TYPES_H
#define CMU_TYPES_H

/** @addtogroup Cmu_Module
 *  @{
 */

/** @addtogroup Cmu
 *  @brief Cmu high level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Cmu_Drv_Types.h"
#include "Cmu_Cfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define CMU_TYPES_H_VENDOR_ID                   0x00B3U
#define CMU_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define CMU_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define CMU_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define CMU_TYPES_H_SW_MAJOR_VERSION            1U
#define CMU_TYPES_H_SW_MINOR_VERSION            1U
#define CMU_TYPES_H_SW_PATCH_VERSION            0U

/* Check if current file and Cmu_Drv_Types.h file are of the same vendor */
#if (CMU_TYPES_H_VENDOR_ID != CMU_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Cmu_Types.h and Cmu_Drv_Types.h are different"
#endif

/* Check if current file and Cmu_Drv_Types.h file are of the same Autosar version */
#if ((CMU_TYPES_H_AR_RELEASE_MAJOR_VERSION != CMU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||         \
     (CMU_TYPES_H_AR_RELEASE_MINOR_VERSION != CMU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||         \
     (CMU_TYPES_H_AR_RELEASE_REVISION_VERSION != CMU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Cmu_Types.h and Cmu_Drv_Types.h are different"
#endif

/* Check if current file and Cmu_Drv_Types.h file are of the same software version */
#if ((CMU_TYPES_H_SW_MAJOR_VERSION != CMU_DRV_TYPES_H_SW_MAJOR_VERSION) ||                         \
     (CMU_TYPES_H_SW_MINOR_VERSION != CMU_DRV_TYPES_H_SW_MINOR_VERSION) ||                         \
     (CMU_TYPES_H_SW_PATCH_VERSION != CMU_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Cmu_Types.h and Cmu_Drv_Types.h are different"
#endif

/* Check if current file and Cmu_Cfg.h file are of the same vendor */
#if (CMU_TYPES_H_VENDOR_ID != CMU_CFG_H_VENDOR_ID)
    #error "Vendor ID of Cmu_Types.h and Cmu_Cfg.h are different"
#endif

/* Check if current file and Cmu_Cfg.h file are of the same Autosar version */
#if ((CMU_TYPES_H_AR_RELEASE_MAJOR_VERSION != CMU_CFG_H_AR_RELEASE_MAJOR_VERSION) ||               \
     (CMU_TYPES_H_AR_RELEASE_MINOR_VERSION != CMU_CFG_H_AR_RELEASE_MINOR_VERSION) ||               \
     (CMU_TYPES_H_AR_RELEASE_REVISION_VERSION != CMU_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Cmu_Types.h and Cmu_Cfg.h are different"
#endif

/* Check if current file and Cmu_Cfg.h file are of the same software version */
#if ((CMU_TYPES_H_SW_MAJOR_VERSION != CMU_CFG_H_SW_MAJOR_VERSION) ||                               \
     (CMU_TYPES_H_SW_MINOR_VERSION != CMU_CFG_H_SW_MINOR_VERSION) ||                               \
     (CMU_TYPES_H_SW_PATCH_VERSION != CMU_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Cmu_Types.h and Cmu_Cfg.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 *  @brief Type definition of CMU ID
 */

typedef uint32 Cmu_IdType;



/**
 *  @brief Type definition of CMU mode
 */

typedef enum
{
    CMU_MONITOR_MODE = 0U, /*!< CMU monitor mode */
    CMU_MEASURE_MODE = 1U  /*!< CMU measure mode */
} Cmu_ModeType;

/**
 *  @brief Type definition of CMU state
 */

typedef enum
{
    CMU_STATE_CFG_UPDATABLE = 0U,  /*!< CMU configuration can be updated */
    CMU_STATE_CFG_LOCKED = 1U,     /*!< CMU configuration is locked */
    CMU_STATE_MONITOR_RUNNING = 2U /*!< CMU is running */
} Cmu_StateType;


/**
 *  @brief System cmu configuration parameters definition
 */

typedef struct
{
    const Cmu_Drv_ConfigType *SysCmuConfigPtr;     /*!< Cmu config */
    uint8                     NumberOfConfigedCmu; /*!< Number of configured cmu */
} Cmu_ConfigType;

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

/** @} end of group Cmu */

/** @} end of group Cmu_Module */

#endif /* CMU_TYPES_H */
