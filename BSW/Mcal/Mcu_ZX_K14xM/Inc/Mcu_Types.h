/**************************************************************************************************/
/**
 * @file      : Mcu_Types.h
 * @brief     : AUTOSAR Mcu driver type definition header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef MCU_TYPES_H
#define MCU_TYPES_H

/** @addtogroup Mcu_Module
 *  @{
 */

/** @addtogroup Mcu
 *  @brief Mcu high level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Mcu_Drvw_Types.h"
#include "Mcu_Cfg.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define MCU_TYPES_H_VENDOR_ID                   0x00B3U
#define MCU_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define MCU_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define MCU_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define MCU_TYPES_H_SW_MAJOR_VERSION            1U
#define MCU_TYPES_H_SW_MINOR_VERSION            2U
#define MCU_TYPES_H_SW_PATCH_VERSION            1U

/* Check if current file and Mcu_Drvw_Types.h file are of the same vendor */
#if (MCU_TYPES_H_VENDOR_ID != MCU_DRVW_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Mcu_Types.h and Mcu_Drvw_Types.h are different"
#endif

/* Check if current file and Mcu_Drvw_Types.h file are of the same Autosar version */
#if ((MCU_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCU_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||        \
     (MCU_TYPES_H_AR_RELEASE_MINOR_VERSION != MCU_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION) ||        \
     (MCU_TYPES_H_AR_RELEASE_REVISION_VERSION != MCU_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Mcu_Types.h and Mcu_Drvw_Types.h are different"
#endif

/* Check if current file and Mcu_Drvw_Types.h file are of the same software version */
#if ((MCU_TYPES_H_SW_MAJOR_VERSION != MCU_DRVW_TYPES_H_SW_MAJOR_VERSION) ||                        \
     (MCU_TYPES_H_SW_MINOR_VERSION != MCU_DRVW_TYPES_H_SW_MINOR_VERSION) ||                        \
     (MCU_TYPES_H_SW_PATCH_VERSION != MCU_DRVW_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Mcu_Types.h and Mcu_Drvw_Types.h are different"
#endif

/* Check if current file and Mcu_Cfg.h file are of the same vendor */
#if (MCU_TYPES_H_VENDOR_ID != MCU_CFG_H_VENDOR_ID)
    #error "Vendor ID of Mcu_Types.h and Mcu_Cfg.h are different"
#endif

/* Check if current file and Mcu_Cfg.h file are of the same Autosar version */
#if ((MCU_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCU_CFG_H_AR_RELEASE_MAJOR_VERSION) ||               \
     (MCU_TYPES_H_AR_RELEASE_MINOR_VERSION != MCU_CFG_H_AR_RELEASE_MINOR_VERSION) ||               \
     (MCU_TYPES_H_AR_RELEASE_REVISION_VERSION != MCU_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Mcu_Types.h and Mcu_Cfg.h are different"
#endif

/* Check if current file and Mcu_Cfg.h file are of the same software version */
#if ((MCU_TYPES_H_SW_MAJOR_VERSION != MCU_CFG_H_SW_MAJOR_VERSION) ||                               \
     (MCU_TYPES_H_SW_MINOR_VERSION != MCU_CFG_H_SW_MINOR_VERSION) ||                               \
     (MCU_TYPES_H_SW_PATCH_VERSION != MCU_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Mcu_Types.h and Mcu_Cfg.h are different"
#endif

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 * @brief Type of the MCU reset reason.
 */
/* SWS_Mcu_00252, SWS_Mcu_00234, SWS_Mcu_00134 */
typedef enum
{
    MCU_POWER_ON_RESET = 0x00U, /*!< Power On Reset */
    MCU_WATCHDOG_RESET,         /*!< Internal WatchDog Timer Reset */
    MCU_SW_RESET,               /*!< Software Reset */
    MCU_RESET_UNDEFINED,        /*!< Reset is undefined */
    MCU_WAKEUP_RESET,           /*!< Reset caused by a standby wakeup */
    MCU_LVD_RESET,              /*!< Low Voltage detected Reset */
    MCU_LOC_RESET,              /*!< Loss of External Clock Reset */
    MCU_PIN_RESET,              /*!< the External RESET Pin Reset */
    MCU_LOCKUP_RESET,           /*!< ARM Core Indication of a LOCKUP event Reset */
    MCU_MDM_AP_RESET,    /*!< Host Debugger System Setting in the MDM-AP Control Register Reset */
    MCU_SERU_COLD_RESET, /*!< SERU Cold Reset Request Reset */
    MCU_SERU_SYS_RESET,  /*!< SERU System Reset Request Reset */
    MCU_SERU_SACKERR,    /*!< Fail to ACK attempt to Enter Stop Mode Reset */
    MCU_HW_TEST_RESET,   /*!< Hardware Test Reset */
    MCU_MULTIPLE_RESET_REASON /*!< More than one reset events are logged except "Power on event" */
} Mcu_ResetType;

#if (MCU_GET_RAM_STATE_API == STD_ON)
/**
 * @brief  Type of RAM state.
 */
/* SWS_Mcu_00256 */
typedef enum
{
    MCU_RAMSTATE_INVALID = 0U, /*!< Ram content is not valid or unknown (default) */
    MCU_RAMSTATE_VALID = 1U    /*!< Ram content is valid */
} Mcu_RamStateType;
#endif

/**
 *  @brief Type of loss of OSC clock detected action.
 */
typedef enum
{
    MCU_OSC_CLOCK_LOSS_INT = 0U, /*!< Generated interrupt if loss of clock is detected */
    MCU_OSC_CLOCK_LOSS_RST       /*!< Generated reset if loss of clock is detected */
} Mcu_OscClockLossActType;

/**
 *  @brief Type of loss of FIRC64M clock detected action.
 */
typedef enum
{
    MCU_FIRC64M_CLOCK_LOSS_INT = 0U, /*!< Generated interrupt if loss of clock is detected */
    MCU_FIRC64M_CLOCK_LOSS_RST       /*!< Generated reset if loss of clock is detected */
} Mcu_Firc64MClockLossActType;

#if (MCU_ENABLE_PLL_MONITOR_API == STD_ON)
/**
 *  @brief Type of loss of PLL clock detected action.
 */
typedef enum
{
    MCU_PLL_CLOCK_LOSS_INT = 0U, /*!< Generated interrupt if loss of clock is detected */
    MCU_PLL_CLOCK_LOSS_RST       /*!< Generated reset if loss of clock is detected */
} Mcu_PllClockLossActType;
#endif

/**
 *  @brief Type of wakeup source.
 */
typedef enum
{
    MCU_WUPSRC_PTD0 = 0x0U,  /*!< Wakeup source: PTD0 pin */
    MCU_WUPSRC_PTD1 = 0x1U,  /*!< Wakeup source: PTD1 pin */
    MCU_WUPSRC_PTA4 = 0x2U,  /*!< Wakeup source: PTA4 pin */
    MCU_WUPSRC_PTC4 = 0x4U,  /*!< Wakeup source: PTC4 pin */
    MCU_WUPSRC_PTC5 = 0x5U,  /*!< Wakeup source: PTC5 pin */
    MCU_WUPSRC_PTE0 = 0x6U,  /*!< Wakeup source: PTE0 pin */
    MCU_WUPSRC_PTE1 = 0x7U,  /*!< Wakeup source: PTE1 pin */
    MCU_WUPSRC_PTE11 = 0x8U, /*!< Wakeup source: PTE11 pin */
    MCU_WUPSRC_PTE13 = 0x9U, /*!< Wakeup source: PTE13 pin */
    MCU_WUPSRC_PTE15 = 0xAU, /*!< Wakeup source: PTE15 pin */
    MCU_WUPSRC_PTE16 = 0xBU, /*!< Wakeup source: PTE16 pin */
    MCU_WUPSRC_PTA8 = 0xCU,  /*!< Wakeup source: PTA8 pin */
    MCU_WUPSRC_PTA9 = 0xDU,  /*!< Wakeup source: PTA9 pin */
    MCU_WUPSRC_PTA25 = 0xEU, /*!< Wakeup source: PTA25 pin */
    MCU_WUPSRC_PMU = 0xFU,   /*!< Wakeup source: PMU */
    MCU_WUPSRC_RTC = 0x10U   /*!< Wakeup source: RTC */
} Mcu_WakeupSourceType;

/**
 * @brief Type of PLL lock status.
 */
/* SWS_Mcu_00250, SWS_Mcu_00231 */
typedef enum
{
    MCU_PLL_LOCKED = 0U,          /*!< PLL is locked */
    MCU_PLL_UNLOCKED = 1U,        /*!< PLL is unlocked */
    MCU_PLL_STATUS_UNDEFINED = 2U /*!< PLL status is unknown */
} Mcu_PllStatusType;

/**
 *  @brief Type of MCU mode.
 */
typedef enum
{
    MCU_POWERMODE_RUN = 0U, /*!< Run mode */
    MCU_POWERMODE_WAIT,     /*!< Wait mode */
    MCU_POWERMODE_STOP,     /*!< Stop mode */
    MCU_POWERMODE_STANDBY   /*!< Standby mode */
} Mcu_PowerModeType;

/**
 * @brief  This type specifies the identification (ID) for a RAM section, which is configured in the
 *         configuration structure.
 *
 */
/* SWS_Mcu_00255, SWS_Mcu_00240 */
typedef uint32 Mcu_RamSectionType;

/**
 * @brief  This type specifies the identification (ID) for a MCU mode, which is configured in the
 *         configuration structure.
 *
 */
/* SWS_Mcu_00254, SWS_Mcu_00238 */
typedef uint32 Mcu_ModeType;

/**
 * @brief  Specifies the identification (ID) for a clock setting, which is configured in the
 *         configuration structure.
 *
 */
/* SWS_Mcu_00251, SWS_Mcu_00233 */
typedef uint32 Mcu_ClockType;

/**
 * @brief   This type specifies the reset reason in raw register format read from a reset status
 *          register.
 *
 */
/* SWS_Mcu_00253, SWS_Mcu_00236 */
typedef uint32 Mcu_RawResetType;

/**
 * @brief  Type of RAM sector configuration.
 *
 */
/* SWS_Mcu_00239 */
typedef struct
{
    Mcu_RamSectionType RamSectorId;     /*!< Ram sector id */
    uint32             RamBaseAddr;     /*!< RAM section base address. */
    uint32             RamSize;         /*!< RAM section size. */
    uint64             RamDefaultValue; /*!< RAM default value for initialization. */
    uint32             RamWriteSize;    /*!< RAM section write size. */
} Mcu_RamConfigType;

/**
 * @brief  Type of MCU mode section in the configuration structure.
 *
 */
/* SWS_Mcu_00237 */
typedef struct
{
    Mcu_ModeType      ModeConfigId; /*!< @brief The ID for Power Mode configuration. */
    Mcu_PowerModeType PowerMode;    /*!< @brief Power modes control configuration */
} Mcu_ModeConfigType;

/**
 * @brief  Type of clock configuration.
 *
 */
/* SWS_Mcu_00232 */
typedef struct
{
    Mcu_ClockType                   ClockConfigId;  /*!< The ID for Clock configuration. */
    const Mcu_Drvw_ClockConfigType *ClockConfigPtr; /*!< Clock configuration */
} Mcu_ClockConfigType;

/**
 * @brief   A pointer to such a structure is provided to the MCU initialization routines for
 *          configuration.
 *
 */
/* SWS_Mcu_00249, SWS_Mcu_00131, SWS_Mcu_00035, SWS_Mcu_00031, SWS_Mcu_00030, SWS_Mcu_00237 */
typedef struct
{
    /*!< Total number of RAM sections. */
    Mcu_RamSectionType NoOfRamConfigs;

    /*!< Total number of  MCU modes. */
    Mcu_ModeType NoOfModeConfigs;

#if (MCU_INIT_CLOCK == STD_ON)
    /*!< Total number of MCU clock configurations. */
    Mcu_ClockType NoOfClkConfigs;
#endif /* (MCU_INIT_CLOCK == STD_ON) */
#ifndef MCU_MAX_NORAMCONFIGS
    const Mcu_RamConfigType (*RamConfigPtr)[MCU_MAX_RAMCONFIGS]; /*!< RAM data configuration. */
#endif
    /*!< Power Modes data configuration. */
    const Mcu_ModeConfigType (*ModeConfigPtr)[MCU_MAX_MODECONFIGS];

#if (MCU_INIT_CLOCK == STD_ON)
    /*!< Clock data configuration. */
    const Mcu_ClockConfigType (*ClockConfigPtr)[MCU_MAX_CLKCONFIGS];
#endif /* (MCU_INIT_CLOCK == STD_ON) */
    /*!< data generic configuration. */
    const Mcu_Drvw_HwConfigType *HwConfigPtr;
} Mcu_ConfigType;

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

/** @} end of group Mcu */

/** @} end of group Mcu_Module */

#endif /* MCU_TYPES_H */
