/**************************************************************************************************/
/**
 * @file      : Mcu_Drvw_Types.h
 * @brief     : AUTOSAR Mcu driver wrapper type definition header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef MCU_DRVW_TYPES_H
#define MCU_DRVW_TYPES_H

/** @addtogroup Mcu_Module
 *  @{
 */

/** @addtogroup Mcu_Drvw
 *  @brief Mcu middle level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Mcu_Drvw_Cfg.h"
#include "Scc_Drv_Types.h"
#include "Parcc_Drv_Types.h"
#include "Pmu_Drv_Types.h"
#include "Scm_Mcu_Drv_Types.h"
#include "Srmc_Drv_Types.h"
#include "Ram_Drv_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define MCU_DRVW_TYPES_H_VENDOR_ID                   0x00B3U
#define MCU_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define MCU_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define MCU_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define MCU_DRVW_TYPES_H_SW_MAJOR_VERSION            1U
#define MCU_DRVW_TYPES_H_SW_MINOR_VERSION            2U
#define MCU_DRVW_TYPES_H_SW_PATCH_VERSION            1U

/* Check if current file and Mcu_Drvw_Cfg.h file are of the same vendor */
#if (MCU_DRVW_TYPES_H_VENDOR_ID != MCU_DRVW_CFG_H_VENDOR_ID)
    #error "Vendor ID of Mcu_Drvw_Types.h and Mcu_Drvw_Cfg.h are different"
#endif

/* Check if current file and Mcu_Drvw_Cfg.h file are of the same Autosar version */
#if ((MCU_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCU_DRVW_CFG_H_AR_RELEASE_MAJOR_VERSION) ||     \
     (MCU_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION != MCU_DRVW_CFG_H_AR_RELEASE_MINOR_VERSION) ||     \
     (MCU_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION != MCU_DRVW_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Mcu_Drvw_Types.h and Mcu_Drvw_Cfg.h are different"
#endif

/* Check if current file and Mcu_Drvw_Cfg.h file are of the same software version */
#if ((MCU_DRVW_TYPES_H_SW_MAJOR_VERSION != MCU_DRVW_CFG_H_SW_MAJOR_VERSION) ||                     \
     (MCU_DRVW_TYPES_H_SW_MINOR_VERSION != MCU_DRVW_CFG_H_SW_MINOR_VERSION) ||                     \
     (MCU_DRVW_TYPES_H_SW_PATCH_VERSION != MCU_DRVW_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Mcu_Drvw_Types.h and Mcu_Drvw_Cfg.h are different"
#endif

/* Check if current file and Scc_Drv_Types.h file are of the same vendor */
#if (MCU_DRVW_TYPES_H_VENDOR_ID != SCC_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Mcu_Drvw_Types.h and Scc_Drv_Types.h are different"
#endif

/* Check if current file and Scc_Drv_Types.h file are of the same Autosar version */
#if ((MCU_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION != SCC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||    \
     (MCU_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION != SCC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||    \
     (MCU_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION !=                                              \
      SCC_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Mcu_Drvw_Types.h and Scc_Drv_Types.h are different"
#endif

/* Check if current file and Scc_Drv_Types.h file are of the same software version */
#if ((MCU_DRVW_TYPES_H_SW_MAJOR_VERSION != SCC_DRV_TYPES_H_SW_MAJOR_VERSION) ||                    \
     (MCU_DRVW_TYPES_H_SW_MINOR_VERSION != SCC_DRV_TYPES_H_SW_MINOR_VERSION) ||                    \
     (MCU_DRVW_TYPES_H_SW_PATCH_VERSION != SCC_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Mcu_Drvw_Types.h and Scc_Drv_Types.h are different"
#endif

/* Check if current file and Parcc_Drv_Types.h file are of the same vendor */
#if (MCU_DRVW_TYPES_H_VENDOR_ID != PARCC_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Mcu_Drvw_Types.h and Parcc_Drv_Types.h are different"
#endif

/* Check if current file and Parcc_Drv_Types.h file are of the same Autosar version */
#if ((MCU_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION != PARCC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||  \
     (MCU_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION != PARCC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||  \
     (MCU_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION !=                                              \
      PARCC_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Mcu_Drvw_Types.h and Parcc_Drv_Types.h are different"
#endif

/* Check if current file and Parcc_Drv_Types.h file are of the same software version */
#if ((MCU_DRVW_TYPES_H_SW_MAJOR_VERSION != PARCC_DRV_TYPES_H_SW_MAJOR_VERSION) ||                  \
     (MCU_DRVW_TYPES_H_SW_MINOR_VERSION != PARCC_DRV_TYPES_H_SW_MINOR_VERSION) ||                  \
     (MCU_DRVW_TYPES_H_SW_PATCH_VERSION != PARCC_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Mcu_Drvw_Types.h and Parcc_Drv_Types.h are different"
#endif

/* Check if current file and Pmu_Drv_Types.h file are of the same vendor */
#if (MCU_DRVW_TYPES_H_VENDOR_ID != PMU_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Mcu_Drvw_Types.h and Pmu_Drv_Types.h are different"
#endif

/* Check if current file and Pmu_Drv_Types.h file are of the same Autosar version */
#if ((MCU_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION != PMU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||    \
     (MCU_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION != PMU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||    \
     (MCU_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION !=                                              \
      PMU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Mcu_Drvw_Types.h and Pmu_Drv_Types.h are different"
#endif

/* Check if current file and Pmu_Drv_Types.h file are of the same software version */
#if ((MCU_DRVW_TYPES_H_SW_MAJOR_VERSION != PMU_DRV_TYPES_H_SW_MAJOR_VERSION) ||                    \
     (MCU_DRVW_TYPES_H_SW_MINOR_VERSION != PMU_DRV_TYPES_H_SW_MINOR_VERSION) ||                    \
     (MCU_DRVW_TYPES_H_SW_PATCH_VERSION != PMU_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Mcu_Drvw_Types.h and Pmu_Drv_Types.h are different"
#endif

/* Check if current file and Scm_Mcu_Drv_Types.h file are of the same vendor */
#if (MCU_DRVW_TYPES_H_VENDOR_ID != SCM_MCU_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Mcu_Drvw_Types.h and Scm_Mcu_Drv_Types.h are different"
#endif

/* Check if current file and Scm_Mcu_Drv_Types.h file are of the same Autosar version */
#if ((MCU_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION !=                                                 \
      SCM_MCU_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||                                             \
     (MCU_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION !=                                                 \
      SCM_MCU_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||                                             \
     (MCU_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION !=                                              \
      SCM_MCU_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Mcu_Drvw_Types.h and Scm_Mcu_Drv_Types.h are different"
#endif

/* Check if current file and Scm_Mcu_Drv_Types.h file are of the same software version */
#if ((MCU_DRVW_TYPES_H_SW_MAJOR_VERSION != SCM_MCU_DRV_TYPES_H_SW_MAJOR_VERSION) ||                \
     (MCU_DRVW_TYPES_H_SW_MINOR_VERSION != SCM_MCU_DRV_TYPES_H_SW_MINOR_VERSION) ||                \
     (MCU_DRVW_TYPES_H_SW_PATCH_VERSION != SCM_MCU_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Mcu_Drvw_Types.h and Scm_Mcu_Drv_Types.h are different"
#endif

/* Check if current file and Srmc_Drv_Types.h file are of the same vendor */
#if (MCU_DRVW_TYPES_H_VENDOR_ID != SRMC_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Mcu_Drvw_Types.h and Srmc_Drv_Types.h are different"
#endif

/* Check if current file and Srmc_Drv_Types.h file are of the same Autosar version */
#if ((MCU_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION != SRMC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||   \
     (MCU_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION != SRMC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||   \
     (MCU_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION !=                                              \
      SRMC_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Mcu_Drvw_Types.h and Srmc_Drv_Types.h are different"
#endif

/* Check if current file and Srmc_Drv_Types.h file are of the same software version */
#if ((MCU_DRVW_TYPES_H_SW_MAJOR_VERSION != SRMC_DRV_TYPES_H_SW_MAJOR_VERSION) ||                   \
     (MCU_DRVW_TYPES_H_SW_MINOR_VERSION != SRMC_DRV_TYPES_H_SW_MINOR_VERSION) ||                   \
     (MCU_DRVW_TYPES_H_SW_PATCH_VERSION != SRMC_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Mcu_Drvw_Types.h and Srmc_Drv_Types.h are different"
#endif

/* Check if current file and Ram_Drv_Types.h file are of the same vendor */
#if (MCU_DRVW_TYPES_H_VENDOR_ID != RAM_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Mcu_Drvw_Types.h and Ram_Drv_Types.h are different"
#endif

/* Check if current file and Ram_Drv_Types.h file are of the same Autosar version */
#if ((MCU_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION != RAM_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||    \
     (MCU_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION != RAM_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||    \
     (MCU_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION !=                                              \
      RAM_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Mcu_Drvw_Types.h and Ram_Drv_Types.h are different"
#endif

/* Check if current file and Ram_Drv_Types.h file are of the same software version */
#if ((MCU_DRVW_TYPES_H_SW_MAJOR_VERSION != RAM_DRV_TYPES_H_SW_MAJOR_VERSION) ||                    \
     (MCU_DRVW_TYPES_H_SW_MINOR_VERSION != RAM_DRV_TYPES_H_SW_MINOR_VERSION) ||                    \
     (MCU_DRVW_TYPES_H_SW_PATCH_VERSION != RAM_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Mcu_Drvw_Types.h and Ram_Drv_Types.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 *  @brief Type of loss of OSC clock detected action.
 *
 */
typedef enum
{
    MCU_DRVW_OSC_CLOCK_LOSS_INT = 0U, /*!< Generated interrupt if loss of clock is detected */
    MCU_DRVW_OSC_CLOCK_LOSS_RST       /*!< Generated reset if loss of clock is detected */
} Mcu_Drvw_OscClockLossActType;

/**
 *  @brief Type of loss of FIRC64M clock detected action.
 *
 */
typedef enum
{
    MCU_DRVW_FIRC64M_CLOCK_LOSS_INT = 0U, /*!< Generated interrupt if loss of clock is detected */
    MCU_DRVW_FIRC64M_CLOCK_LOSS_RST       /*!< Generated reset if loss of clock is detected */
} Mcu_Drvw_Firc64MClockLossActType;

/**
 *  @brief Type of wakeup source.
 *
 */
typedef enum
{
    MCU_DRVW_WUPSRC_PTD0 = 0x0U,  /*!< Wakeup source: PTD0 pin */
    MCU_DRVW_WUPSRC_PTD1 = 0x1U,  /*!< Wakeup source: PTD1 pin */
    MCU_DRVW_WUPSRC_PTA4 = 0x2U,  /*!< Wakeup source: PTA4 pin */
    MCU_DRVW_WUPSRC_PTC4 = 0x4U,  /*!< Wakeup source: PTC4 pin */
    MCU_DRVW_WUPSRC_PTC5 = 0x5U,  /*!< Wakeup source: PTC5 pin */
    MCU_DRVW_WUPSRC_PTE0 = 0x6U,  /*!< Wakeup source: PTE0 pin */
    MCU_DRVW_WUPSRC_PTE1 = 0x7U,  /*!< Wakeup source: PTE1 pin */
    MCU_DRVW_WUPSRC_PTE11 = 0x8U, /*!< Wakeup source: PTE11 pin */
    MCU_DRVW_WUPSRC_PTE13 = 0x9U, /*!< Wakeup source: PTE13 pin */
    MCU_DRVW_WUPSRC_PTE15 = 0xAU, /*!< Wakeup source: PTE15 pin */
    MCU_DRVW_WUPSRC_PTE16 = 0xBU, /*!< Wakeup source: PTE16 pin */
    MCU_DRVW_WUPSRC_PTA8 = 0xCU,  /*!< Wakeup source: PTA8 pin */
    MCU_DRVW_WUPSRC_PTA9 = 0xDU,  /*!< Wakeup source: PTA9 pin */
    MCU_DRVW_WUPSRC_PTA25 = 0xEU, /*!< Wakeup source: PTA25 pin */
    MCU_DRVW_WUPSRC_PMU = 0xFU,   /*!< Wakeup source: PMU */
    MCU_DRVW_WUPSRC_RTC = 0x10U   /*!< Wakeup source: RTC */
} Mcu_Drvw_WakeupSourceType;

/**
 *  @brief Type of clock source.
 *
 */
typedef enum
{
    MCU_DRVW_CLOCK_SRC_NO = 0U,      /*!< None is selected */
    MCU_DRVW_CLOCK_SRC_LPO32K = 1U,  /*!< LPO32K */
    MCU_DRVW_CLOCK_SRC_SOSC = 2U,    /*!< Slow OSC clock */
    MCU_DRVW_CLOCK_SRC_FIRC64M = 3U, /*!< FIRC64M */
    MCU_DRVW_CLOCK_SRC_FOSC = 4U,    /*!< Fast OSC clock */
    MCU_DRVW_CLOCK_SRC_PLL = 5U      /*!< PLL */
} Mcu_Drvw_ClockSrcType;

#if (MCU_DRVW_ENABLE_PLL_MONITOR_API == STD_ON)
/**
 *  @brief Type of loss of PLL clock detected action.
 *
 */
typedef enum
{
    MCU_DRVW_PLL_CLOCK_LOSS_INT = 0U, /*!< Generated interrupt if loss of clock is detected */
    MCU_DRVW_PLL_CLOCK_LOSS_RST       /*!< Generated reset if loss of clock is detected */
} Mcu_Drvw_PllClockLossActType;
#endif

/**
 * @brief Type of reset reason.
 */
typedef enum
{
    MCU_DRVW_WAKEUP_RESET = 0U,   /*!< Reset caused by a standby wakeup */
    MCU_DRVW_LVD_RESET = 1U,      /*!< Low Voltage detected Reset */
    MCU_DRVW_LOC_RESET = 2U,      /*!< Loss of External Clock Reset */
    MCU_DRVW_WATCHDOG_RESET = 5U, /*!< Internal WatchDog Timer Reset */
    MCU_DRVW_PIN_RESET = 6U,      /*!< the External RESET Pin Reset */
    MCU_DRVW_POWER_ON_RESET = 7U, /*!< Power On Reset */
    MCU_DRVW_LOCKUP_RESET = 9U,   /*!< ARM Core Indication of a LOCKUP event Reset */
    MCU_DRVW_SW_RESET = 10U,      /*!< Software Reset */
    MCU_DRVW_MDM_AP_RESET =
        11U, /*!< Host Debugger System Setting in the MDM-AP Control Register Reset */
    MCU_DRVW_SERU_COLD_RESET = 12U, /*!< SERU Cold Reset Request Reset */
    MCU_DRVW_SERU_SYS_RESET = 13U,  /*!< SERU System Reset Request Reset */
    MCU_DRVW_SERU_SACKERR = 15U,    /*!< Fail to ACK Attempt to Enter Stop Mode Reset */
    MCU_DRVW_MULTIPLE_RESET_REASON =
        0x55U, /**< More than one reset events are logged except "Power on event" */
    MCU_DRVW_RESET_UNDEFINED = 0xFFU /*!< Reset is undefined */
} Mcu_Drvw_ResetType;

/**
 *  @brief Type of MCU mode.
 */
typedef enum
{
    MCU_DRVW_POWERMODE_RUN = 0U, /*!< Run mode */
    MCU_DRVW_POWERMODE_WAIT,     /*!< Wait mode */
    MCU_DRVW_POWERMODE_STOP,     /*!< Stop mode */
    MCU_DRVW_POWERMODE_STANDBY   /*!< Standby mode */
} Mcu_Drvw_PowerModeType;

/**
 * @brief  Type of clock configuration.
 *
 */
typedef struct
{
    const Scc_Drv_ClockConfigType         *SccClockConfigPtr; /*!< SCC Clock settings. */
    const Scm_Mcu_Drv_ClockConfigType     *ScmClockConfigPtr; /*!< SCM settings. */
    const Parcc_Drv_SystemParccConfigType *ParccConfigPtr;    /*!< PARCC settings. */
} Mcu_Drvw_ClockConfigType;

/**
 * @brief   Type of Mcu driver configuration.
 * @details Configuration of System reset and mode control (SRMC).
 *          Configuration of System control module (SCM).
 *          Configuration of Power management unit (PMU).
 *
 */
typedef struct
{
    /*!< SRMC reset configuration. */
    const Srmc_Drv_ResetConfigType *SrmcResetConfigPtr;
    /*!< SRMC mode configuration. */
    const Srmc_Drv_PowerModeConfigType *SrmcPowerModeConfigPtr;
    /*!< SCM configuration. */
    const Scm_Mcu_Drv_ConfigType *ScmConfigPtr;
    /*!< PMU configuration. */
    const Pmu_Drv_ConfigType *PmuConfigPtr;
} Mcu_Drvw_HwConfigType;

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

/** @} end of group Mcu_Drvw */

/** @} end of group Mcu_Module */

#endif /* MCU_DRVW_TYPES_H */
