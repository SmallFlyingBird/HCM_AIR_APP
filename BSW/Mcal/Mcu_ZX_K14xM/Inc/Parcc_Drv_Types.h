/**************************************************************************************************/
/**
 * @file      : Parcc_Drv_Types.h
 * @brief     : PARCC low level driver type definition header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef PARCC_DRV_TYPES_H
#define PARCC_DRV_TYPES_H

/** @addtogroup Mcu_Module
 *  @{
 */

/** @addtogroup Parcc_Drv
 *  @brief PARCC low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Parcc_Drv_Cfg.h"
#include "Std_Types.h"
#include "McalLib.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define PARCC_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define PARCC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define PARCC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define PARCC_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define PARCC_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define PARCC_DRV_TYPES_H_SW_MINOR_VERSION            2U
#define PARCC_DRV_TYPES_H_SW_PATCH_VERSION            2U

/* Check if current file and Parcc_Drv_Cfg.h file are of the same vendor */
#if (PARCC_DRV_TYPES_H_VENDOR_ID != PARCC_DRV_CFG_H_VENDOR_ID)
    #error "Vendor ID of Parcc_Drv_Types.h and Parcc_Drv_Cfg.h are different"
#endif

/* Check if current file and Parcc_Drv_Cfg.h file are of the same Autosar version */
#if ((PARCC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != PARCC_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) ||   \
     (PARCC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != PARCC_DRV_CFG_H_AR_RELEASE_MINOR_VERSION) ||   \
     (PARCC_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION !=                                             \
      PARCC_DRV_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Parcc_Drv_Types.h and Parcc_Drv_Cfg.h are different"
#endif

/* Check if current file and Parcc_Drv_Cfg.h file are of the same Software version */
#if ((PARCC_DRV_TYPES_H_SW_MAJOR_VERSION != PARCC_DRV_CFG_H_SW_MAJOR_VERSION) ||                   \
     (PARCC_DRV_TYPES_H_SW_MINOR_VERSION != PARCC_DRV_CFG_H_SW_MINOR_VERSION) ||                   \
     (PARCC_DRV_TYPES_H_SW_PATCH_VERSION != PARCC_DRV_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Parcc_Drv_Types.h and Parcc_Drv_Cfg.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Std_Types.h file are of the same Autosar version */
    #if ((PARCC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) ||           \
         (PARCC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Parcc_Drv_Types.h and Std_Types.h are different"
    #endif

    /* Check if current file and McalLib.h file are of the same Autosar version */
    #if ((PARCC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) ||       \
         (PARCC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Parcc_Drv_Types.h and McalLib.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 *  @brief Type of PARCC clock source.
 *
 */
typedef enum
{
    PARCC_DRV_CLOCK_SRC_NO = 0U,      /*!< none is selected */
    PARCC_DRV_CLOCK_SRC_LPO32K = 1U,  /*!< LPO32K clock */
    PARCC_DRV_CLOCK_SRC_SOSC = 2U,    /*!< Slow OSC clock */
    PARCC_DRV_CLOCK_SRC_FIRC64M = 3U, /*!< FIRC64M clock */
    PARCC_DRV_CLOCK_SRC_FOSC = 4U,    /*!< Fast OSC clock */
    PARCC_DRV_CLOCK_SRC_PLL = 5U,     /*!< PLL clock */
    PARCC_DRV_CLOCK_SRC_SLOW = 6U,    /*!< SLOW clock */
    PARCC_DRV_CLOCK_SRC_BUS = 7U,     /*!< BUS clock */
    PARCC_DRV_CLOCK_SRC_CORE = 8U     /*!< CORE clock */
} Parcc_Drv_ClockSrcType;

/**
 *  @brief Type of PARCC clock divider.
 *
 */
typedef enum
{
    PARCC_DRV_CLOCK_DIV_1 = 0U, /*!< clock divided by 1 */
    PARCC_DRV_CLOCK_DIV_2,      /*!< clock divided by 2 */
    PARCC_DRV_CLOCK_DIV_3,      /*!< clock divided by 3 */
    PARCC_DRV_CLOCK_DIV_4,      /*!< clock divided by 4 */
    PARCC_DRV_CLOCK_DIV_5,      /*!< clock divided by 5 */
    PARCC_DRV_CLOCK_DIV_6,      /*!< clock divided by 6 */
    PARCC_DRV_CLOCK_DIV_7,      /*!< clock divided by 7 */
    PARCC_DRV_CLOCK_DIV_8,      /*!< clock divided by 8 */
    PARCC_DRV_CLOCK_DIV_9,      /*!< clock divided by 9 */
    PARCC_DRV_CLOCK_DIV_10,     /*!< clock divided by 10 */
    PARCC_DRV_CLOCK_DIV_11,     /*!< clock divided by 11 */
    PARCC_DRV_CLOCK_DIV_12,     /*!< clock divided by 12 */
    PARCC_DRV_CLOCK_DIV_13,     /*!< clock divided by 13 */
    PARCC_DRV_CLOCK_DIV_14,     /*!< clock divided by 14 */
    PARCC_DRV_CLOCK_DIV_15,     /*!< clock divided by 15 */
    PARCC_DRV_CLOCK_DIV_16      /*!< clock divided by 16 */
} Parcc_Drv_ClockDividerType;

/**
 * @brief   Type of PARCC status.
 *
 */
typedef enum
{
    PARCC_DRV_STATUS_OK = 0x00U,       /*!< PARCC Ok status */
    PARCC_DRV_STATUS_NOT_OK = 0x01U,   /*!< PARCC Not ok status */
    PARCC_DRV_STATUS_UNDEFINED = 0x02U /*!< PARCC Status is unknown */
} Parcc_Drv_StatusType;

/**
 *  @brief Type of specify PARCC module configuration.
 */
typedef struct
{
    Parcc_Drv_ModuleType       ParccModule;            /*!< Module name id */
    Parcc_Drv_ClockSrcType     ParccModuleSrc;         /*!< Module clock source */
    Parcc_Drv_ClockDividerType ParccModuleDivider;     /*!< Module clock divider */
    boolean                    Enable;                 /*!< Module enable / disable */
    boolean                    SupervisorAccessEnable; /*!< Supervisor access enable/disable */
    boolean                    WriteLockEnable;        /*!< Write lock enable/disable */
} Parcc_Drv_ModuleConfigType;

/**
 *  @brief Type of the system PARCC configuration.
 *
 */
typedef struct
{
    uint32                            NumberOfModule;       /*!< Number of parcc modules */
    const Parcc_Drv_ModuleConfigType *SystemParccConfigPtr; /*!< System parcc configuration */
} Parcc_Drv_SystemParccConfigType;

/**
 *  @brief Type definition of PARCC register definition.
 *
 */
typedef struct
{
    uint32 Addr;
    uint32 ResetVal;
}Parcc_Drv_RegDefinitionType;

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

/** @} end of group Parcc_Drv */

/** @} end of group Mcu_Module */

#endif /* PARCC_DRV_TYPES_H */
