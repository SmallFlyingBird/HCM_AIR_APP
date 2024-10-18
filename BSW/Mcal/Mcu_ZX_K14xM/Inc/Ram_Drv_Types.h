/**************************************************************************************************/
/**
 * @file      : Ram_Drv_Types.h
 * @brief     : RAM low level driver type definition header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef RAM_DRV_TYPES_H
#define RAM_DRV_TYPES_H

/** @addtogroup Mcu_Module
 *  @{
 */

/** @addtogroup Ram_Drv
 *  @brief RAM low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Ram_Drv_Cfg.h"
#include "Std_Types.h"
#include "McalLib.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define RAM_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define RAM_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define RAM_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define RAM_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define RAM_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define RAM_DRV_TYPES_H_SW_MINOR_VERSION            2U
#define RAM_DRV_TYPES_H_SW_PATCH_VERSION            1U

/* Check if current file and Ram_Drv_Cfg.h file are of the same vendor */
#if (RAM_DRV_TYPES_H_VENDOR_ID != RAM_DRV_CFG_H_VENDOR_ID)
    #error "Vendor ID of Ram_Drv_Types.h and Ram_Drv_Cfg.h are different"
#endif

/* Check if current file and Ram_Drv_Cfg.h file are of the same Autosar version */
#if ((RAM_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != RAM_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) ||       \
     (RAM_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != RAM_DRV_CFG_H_AR_RELEASE_MINOR_VERSION) ||       \
     (RAM_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION != RAM_DRV_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Ram_Drv_Types.h and Ram_Drv_Cfg.h are different"
#endif

/* Check if current file and Ram_Drv_Cfg.h file are of the same Software version */
#if ((RAM_DRV_TYPES_H_SW_MAJOR_VERSION != RAM_DRV_CFG_H_SW_MAJOR_VERSION) ||                       \
     (RAM_DRV_TYPES_H_SW_MINOR_VERSION != RAM_DRV_CFG_H_SW_MINOR_VERSION) ||                       \
     (RAM_DRV_TYPES_H_SW_PATCH_VERSION != RAM_DRV_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Ram_Drv_Types.h and Ram_Drv_Cfg.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Std_Types.h file are of the same Autosar version */
    #if ((RAM_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) ||             \
         (RAM_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Ram_Drv_Types.h and Std_Types.h are different"
    #endif

    /* Check if current file and McalLib.h file are of the same Autosar version */
    #if ((RAM_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) ||         \
         (RAM_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Ram_Drv_Types.h and McalLib.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 * @brief   Type of RAM status.
 *
 */
typedef enum
{
    RAM_DRV_STATUS_OK = 0x00U,       /*!< RAM Ok status */
    RAM_DRV_STATUS_NOT_OK = 0x01U,   /*!< RAM Not ok status */
    RAM_DRV_STATUS_UNDEFINED = 0x02U /*!< RAM Status is unknown */
} Ram_Drv_StatusType;

/**
 * @brief The Ram_Drv_SectorSizeType specifies the RAM section size.
 *
 */
typedef uint32 Ram_Drv_SectorSizeType;

/**
 * @brief The Ram_Drv_WriteSizeType specifies the RAM section write size.
 *
 */
typedef uint32 Ram_Drv_WriteSizeType;

/**
 * @brief The Ram_Drv_IndexType specifies the variable for index of RAM sections.
 *
 */
typedef uint32 Ram_Drv_IndexType;

/**
 * @brief  Type of RAM sector driver configuration.
 *
 */
typedef struct
{
    uint32 RamBaseAddr;     /*!< RAM section base address. */
    uint32 RamSize;         /*!< RAM section size. */
    uint64 RamDefaultValue; /*!< RAM default value for initialization. */
    uint32 RamWriteSize;    /*!< RAM section write size. */
} Ram_Drv_ConfigType;

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

/** @} end of group Ram_Drv */

/** @} end of group Mcu_Module */

#endif /* RAM_DRV_TYPES_H */
