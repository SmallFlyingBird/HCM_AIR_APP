/**************************************************************************************************/
/**
 * @file      : Cmu_Drv_Types.h
 * @brief     : AUTOSAR Cmu driver type definition header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef CMU_DRV_TYPES_H
#define CMU_DRV_TYPES_H

/** @addtogroup Cmu_Module
 *  @{
 */

/** @addtogroup Cmu
 *  @brief  Cmu low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "McalLib.h"
#include "Device_Regs.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define CMU_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define CMU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define CMU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define CMU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define CMU_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define CMU_DRV_TYPES_H_SW_MINOR_VERSION            1U
#define CMU_DRV_TYPES_H_SW_PATCH_VERSION            0U

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and McalLib.h file are of the same Autosar version */
    #if ((CMU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) ||         \
         (CMU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Cmu_Drv_Types.h and McalLib.h are different"
    #endif

    /* Check if current file and Device_Regs.h file are of the same Autosar version */
    #if ((CMU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MAJOR_VERSION) ||   \
         (CMU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != DEVICE_REGS_H_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Cmu_Drv_Types.h and Device_Regs.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 *  @brief Type definition of CMU ID
 */
typedef enum
{
    CMU_DRV_ID_0 = 0U, /*!< CMU0: use FIRC64M clock to monitor bus clock */
    CMU_DRV_ID_1 = 1U, /*!< CMU1: use OSC40M clock to monitor FIRC64M clock */
    CMU_DRV_ID_2 = 2U  /*!< CMU2: use OSC40M clock to monitor LPO32K clock */
} Cmu_Drv_IdType;

/**
 *  @brief Type definition of CMU state
 */
typedef enum
{
    CMU_DRV_STATE_CFG_UPDATABLE = 0U,  /*!< CMU configuration can be updated */
    CMU_DRV_STATE_CFG_LOCKED = 1U,     /*!< CMU configuration is locked */
    CMU_DRV_STATE_MONITOR_RUNNING = 2U /*!< CMU is running */
} Cmu_Drv_StateType;

/**
 *  @brief Type definition of CMU interrupt
 */
typedef enum
{
    CMU_DRV_INT_BELOW_LOW_THRE = 0U,  /*!< CMU interrupt: frequency below low Threshold */
    CMU_DRV_INT_ABOVE_HIGH_THRE = 1U, /*!< CMU interrupt: frequency above high Threshold */
    CMU_DRV_INT_ALL = 2U
} Cmu_Drv_InterruptType;

/**
 *  @brief Type definition of CMU mode
 */
typedef enum
{
    CMU_DRV_MONITOR_MODE = 0U, /*!< CMU monitor mode */
    CMU_DRV_MEASURE_MODE = 1U  /*!< CMU measure mode */
} Cmu_Drv_ModeType;

/**
 *  @brief CMU monitor mode config struct
 */
typedef struct
{
    /*!< Cmu ID */
    uint32 CmuId;
    /*!< Specifies the monitor window */
    uint32 MonitorWindow;
    /*!< Specifies if frequency Below Low Threshold Interrupt is enabled/disabled. */
    boolean BelowLowThresholdIntEn;
    /*!< Below Low Threshold Interrupt callback function */
    void (*BelowLowThresholdNotification)(void);
    /*!< Specifies if frequency above high Threshold Interrupt is enabled/disabled. */
    boolean AboveHighThresholdIntEn;
    /*!< Above high Threshold Interrupt callback function */
    void (*AboveHighThresholdNotification)(void);
    /*!< Clock Monitor ID */
    Cmu_Drv_IdType ClockMonitorId;
    /*!< Specifies if frequency Below Low Threshold Reset is enabled/disabled. */
    boolean BelowLowThresholdResetEn;
    /*!< Specifies if frequency above high Threshold Reset is enabled/disabled. */
    boolean AboveHighThresholdResetEn;
    /*!< Specifies the low threshold for interrupt */
    uint32 IntLowThreshold;
    /*!< Specifies the high threshold for interrupt */
    uint32 IntHighThreshold;
    /*!< Specifies the low threshold for reset */
    uint32 ResetLowThreshold;
    /*!< Specifies the high threshold for reset */
    uint32 ResetHighThreshold;
    /*!< Specifies the cmu mode */
    Cmu_Drv_ModeType Mode;
} Cmu_Drv_ConfigType;

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

#endif /* CMU_DRV_TYPES_H */
