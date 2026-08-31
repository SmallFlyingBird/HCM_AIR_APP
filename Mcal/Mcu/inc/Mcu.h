/**
 * @file    Mcu.h
 * @version
 *
 * @brief   AUTOSAR Mcu module interface
 * @details API implementation for MCU driver
 *
 * @addtogroup MCU_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Mcu
 *   Dependencies         : none
 *
 *   Autosar Version      : V4.4.0
 *   Autosar Revision     : ASR_REL_4_4_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           : V2.3.0
 *
 *
 *   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
 *   All Rights Reserved.
==================================================================================================*/
#ifndef MCU_H
#define MCU_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section Mcu_PBCfg_C_REF_1
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers.
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 *
 * @section Mcu_PBCfg_C_REF_2
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers.
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 */

/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include "Std_Types.h"
#include "Mcu_Cfg.h"

/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_VENDOR_ID                      (0xB4)
#define MCU_AR_RELEASE_MAJOR_VERSION       (4)
#define MCU_AR_RELEASE_MINOR_VERSION       (4)
#define MCU_AR_RELEASE_REVISION_VERSION    (0)
#define MCU_SW_MAJOR_VERSION               (2)
#define MCU_SW_MINOR_VERSION               (3)
#define MCU_SW_PATCH_VERSION               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and MCU configuration header file are of the same vendor */
#if (MCU_VENDOR_ID != MCU_VENDOR_ID_CFG)
#error "Mcu.h and Mcu_Cfg.h have different vendor ids"
#endif

/* Check if source file and MCU configuration header file are of the same Autosar version */
#if ((MCU_AR_RELEASE_MAJOR_VERSION != MCU_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (MCU_AR_RELEASE_MINOR_VERSION != MCU_AR_RELEASE_MINOR_VERSION_CFG) || \
     (MCU_AR_RELEASE_REVISION_VERSION != MCU_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Mcu.h and Mcu_Cfg.h are different"
#endif

/* Check if source file and MCU configuration header file are of the same software version */
#if ((MCU_SW_MAJOR_VERSION != MCU_SW_MAJOR_VERSION_CFG) || \
     (MCU_SW_MINOR_VERSION != MCU_SW_MINOR_VERSION_CFG) || \
     (MCU_SW_PATCH_VERSION != MCU_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Mcu.h and Mcu_Cfg.h are different"
#endif

/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief MCU MODULE INSTANCE ID */
#define MCU_INSTANCE_ID                 ((uint8)0U)

/** @brief MCU MODULE ID */
#define MCU_MODULE_ID                   ((uint8)101U)

#if (MCU_DEV_ERROR_DETECT == STD_ON)
/**
 * @defgroup        Mcu_DEV_ERROR
 * @brief           MCU development errors
 * @{
 */
/** @brief MCU API service is called using an invalid pointer (e.g. the pointer should not be NULL).  */
#define MCU_E_PARAM_CONFIG              (0x0AU)
#define MCU_E_PARAM_CLOCK               (0x0BU)
#define MCU_E_PARAM_MODE                (0x0CU)
#define MCU_E_PARAM_RAMSECTION          (0x0DU)
#define MCU_E_PLL_NOT_LOCKED            (0x0EU)
#define MCU_E_UNINIT                    (0x0FU)
#define MCU_E_PARAM_POINTER             (0x10U)
#define MCU_E_INIT_FAILED               (0x11U)
/** @} */
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */

/**
 * @defgroup        Mcu_SID
 * @brief           Service ID number for all MCU driver services
 * @{
 */
/** @brief API Service ID for Mcu_DistributePllClock */
#define MCU_SID_DISTRIBUTE_PLL_CLOCK    (0x03U)
/** @brief API Service ID for Mcu_GetPllStatus */
#define MCU_SID_GET_PLL_STATUS          (0x04U)
/** @brief API Service ID for Mcu_GetRamState */
#define MCU_SID_GET_RAM_STATE           (0x0aU)
/** @brief API Service ID for Mcu_GetResetRawValue */
#define MCU_SID_GET_RESET_RAW_VALUE     (0x06U)
/** @brief API Service ID for Mcu_GetResetReason */
#define MCU_SID_GET_RESET_REASON        (0x05U)
/** @brief API Service ID for Mcu_GetVersionInfo */
#define MCU_SID_GET_VERSION_INFO        (0x09U)
/** @brief API Service ID for Mcu_Init */
#define MCU_SID_INIT                    (0x00U)
/** @brief API Service ID for Mcu_InitClock */
#define MCU_SID_INIT_CLOCK              (0x02U)
/** @brief API Service ID for Mcu_InitRamSection */
#define MCU_SID_INIT_RAM_SECTION        (0x01U)
/** @brief API Service ID for Mcu_PerformReset */
#define MCU_SID_PERFORM_RESET           (0x07U)
/** @brief API Service ID for Mcu_SetMode */
#define MCU_SID_SET_MODE                (0x08U)
/** @brief API Service ID for Mcu_SetEventStatus */
#define MCU_SID_SET_EVENT_STATUS        (0x0BU)
/** @brief API Service ID for Mcu_GetSxoscStatus */
#define MCU_SID_GET_SXOSC_STATUS        (0x0CU)
/** @} */

/* Define the MCU clock source */
#define MCU_CLOCK_SOURCE_FIRC           (0U)
#define MCU_CLOCK_SOURCE_PLL            (1U)
#define MCU_CLOCK_SOURCE_FXOSC          (2U)
#define MCU_CLOCK_SOURCE_SIRC           (3U)

#if (MCU_HAS_SXOSC == STD_ON)
#define MCU_CLOCK_SOURCE_SXOSC          (4U)
#endif


#if (((MCU_VERSION_INFO_API == STD_ON) && (MCU_DEV_ERROR_DETECT == STD_ON)))
/**
 * @brief            Returns the version information of this module.
 * @details
 *
 * @param[out]       versioninfo Pointer to where to store version information of this module
 *
 * @return           void
 */
#define Mcu_GetVersionInfo(versioninfo)                                       \
    {                                                                         \
        /* Check for DET: MCU_E_PARAM_POINTER */                              \
        if ((versioninfo) == NULL_PTR)                                        \
        {                                                                     \
            /* Report MCU_E_PARAM_POINTER DET if service called with          \
               NULL_PTR                                                       \
            */                                                                \
            Det_ReportError(                                                  \
                (uint16)MCU_MODULE_ID,                                        \
                MCU_INSTANCE_ID,                                              \
                MCU_GET_VERSION_INFO_SID,                                     \
                MCU_E_PARAM_POINTER);                                         \
        }                                                                     \
        else                                                                  \
        {                                                                     \
            /* Vendor ID information */                                       \
            ((Std_VersionInfoType *)(versioninfo))->vendorID = MCU_VENDOR_ID; \
            /* Mcu module ID information */                                   \
            ((Std_VersionInfoType *)(versioninfo))->moduleID = MCU_MODULE_ID; \
            /* Mcu module Software major version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_major_version =        \
                (uint8)MCU_SW_MAJOR_VERSION;                                      \
            /* Mcu module Software minor version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_minor_version =        \
                (uint8)MCU_SW_MINOR_VERSION;                                      \
            /* Mcu module Software patch version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_patch_version =        \
                (uint8)MCU_SW_PATCH_VERSION;                                      \
        }                                                                     \
    }
#elif (((MCU_VERSION_INFO_API == STD_ON) && (MCU_DEV_ERROR_DETECT == STD_OFF)))
#define Mcu_GetVersionInfo(versioninfo)                                   \
    {                                                                     \
        /* Vendor ID information */                                       \
        ((Std_VersionInfoType *)(versioninfo))->vendorID = MCU_VENDOR_ID; \
        /* Mcu module ID information */                                   \
        ((Std_VersionInfoType *)(versioninfo))->moduleID = MCU_MODULE_ID; \
        /* Mcu module Software major version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_major_version =        \
            (uint8)MCU_SW_MAJOR_VERSION;                                      \
        /* Mcu module Software minor version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_minor_version =        \
            (uint8)MCU_SW_MINOR_VERSION;                                      \
        /* Mcu module Software patch version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_patch_version =        \
            (uint8)MCU_SW_PATCH_VERSION;                                      \
    }
#endif /* MCU_VERSION_INFO_API == STD_ON && MCU_DEV_ERROR_DETECT == STD_ON */

/*==================================================================================================
 *                                       EXTERNAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                             ENUMS
==================================================================================================*/
/**
 * @brief This enumeration type is used to enumerate the status of the PLL clock.
 */
typedef enum
{
    MCU_PLL_LOCKED = 0U,                 /**< PLL is locked */
    MCU_PLL_UNLOCKED = 1U,               /**< PLL is locked */
    MCU_PLL_STATUS_UNDEFINED = 2U,       /**< reverse */
} Mcu_PllStatusType;

#if (MCU_GET_SXOSC_STATU_API == STD_ON)
/**
 * @brief This enumeration type is used to enumerate the status of the Sxosc clock.
 */
typedef enum
{
    MCU_SXOSC_INVALID = 0U,             /**< Sxosc is locked */
    MCU_SXOSC_VALID = 1U,               /**< Sxosc is locked */
} Mcu_SxoscStatusType;
#endif

/**
 * @brief This enumeration type is used to enumerate the status of the RAM.
 */
typedef enum
{
    MCU_RAMSTATE_INVALID = 0U,           /**< RAM state is invalid */
    MCU_RAMSTATE_VALID = 1U,             /**< RAM state is valid */
} Mcu_RamStateType;

/**
 * @brief This enumeration type is used to enumerate the system clock sources of the Mcu.
 */
typedef enum
{
    MCU_SYSTEM_CLOCK_SOURCE_FIRC = 0U,  /**< Choose FIRC as system clock */
    MCU_SYSTEM_CLOCK_SOURCE_PLL = 1U,   /**< Choose PLL as system clock */
    MCU_SYSTEM_CLOCK_SOURCE_FXOSC = 2U, /**< Choose FXOSC as system clock */
    MCU_SYSTEM_CLOCK_SOURCE_SIRC = 3U,  /**< Choose SIRC as system clock */
} Mcu_SystemClockSourceType;

/**
 * @brief This enumeration type is used to enumerate the system clock output sources of the Mcu.
 */
#if defined(CPU_YTM32B1MD1) || defined(CPU_YTM32B1ME0)
typedef enum
{
    MCU_CLOCK_OUT_SOURCE_OFF   = 0U,    /**< No clock is choosen as system clock output */
    MCU_CLOCK_OUT_SOURCE_FIRC  = 1U,    /**< Choose FIRC as system clock output */
    MCU_CLOCK_OUT_SOURCE_SIRC  = 2U,    /**< Choose SIRC as system clock output */
    MCU_CLOCK_OUT_SOURCE_FXOSC = 3U,    /**< Choose FXOSC as system clock output */
#if (MCU_HAS_SXOSC == STD_ON)
    MCU_CLOCK_OUT_SOURCE_SXOSC = 4U,    /**< Choose SXOSC as system clock output */
#endif
    MCU_CLOCK_OUT_SOURCE_PLL   = 5U,    /**< Choose PLL as system clock output */
} Mcu_ClockOutSourceType;
#elif defined(CPU_YTM32B1HA0)
typedef enum
{
    MCU_CLOCK_OUT_SOURCE_OFF   = 0U,    /**< No clock is choosen as system clock output */
    MCU_CLOCK_OUT_SOURCE_FIRC  = 1U,    /**< Choose FIRC as system clock output */
    MCU_CLOCK_OUT_SOURCE_SIRC  = 2U,    /**< Choose SIRC as system clock output */
    MCU_CLOCK_OUT_SOURCE_FXOSC = 3U,    /**< Choose FXOSC as system clock output */
    MCU_CLOCK_OUT_SOURCE_SXOSC = 4U,    /**< Choose SXOSC as system clock output */
    MCU_CLOCK_OUT_SOURCE_PLL   = 5U,    /**< Choose PLL as system clock output */
    MCU_CLOCK_OUT_SOURCE_TRNG  = 6U,    /**< Choose TRNG ring oscillator as system clock output */
    MCU_CLOCK_OUT_SOURCE_CORE  = 7U,    /**< Choose Core clock as system clock output */
} Mcu_ClockOutSourceType;
#elif defined(CPU_YTM32B1MC0)
typedef enum
{
    MCU_CLOCK_OUT_SOURCE_OFF   = 0U,    /**< No clock is choosen as system clock output */
    MCU_CLOCK_OUT_SOURCE_FIRC  = 1U,    /**< Choose FIRC as system clock output */
    MCU_CLOCK_OUT_SOURCE_SIRC  = 2U,    /**< Choose SIRC as system clock output */
    MCU_CLOCK_OUT_SOURCE_FXOSC = 3U,    /**< Choose FXOSC as system clock output */

    MCU_CLOCK_OUT_SOURCE_LPO   = 5U,    /**< Choose LPO clock as system clock output */
    MCU_CLOCK_OUT_SOURCE_TRNG  = 6U,    /**< Choose TRNG ring oscillator as system clock output */
    MCU_CLOCK_OUT_SOURCE_CORE  = 7U,    /**< Choose Core clock as system clock output */
} Mcu_ClockOutSourceType;
#endif

/**
 * @brief This enumeration type is used to enumerate the clock monitor unit(CMU) reference clock.
 *
 */
typedef enum
{
    MCU_CMU_CLOCK_REFERENCE_SIRC = 0U,  /**< Choose SIRC as reference clock */
    MCU_CMU_CLOCK_REFERENCE_FXOSC = 1U, /**< Choose FXOSC as reference clock */
} Mcu_CmuClockReferenceType;

/**
 * @brief This enumeration type is used to enumerate the PLL reference clock.
 */
typedef enum
{
    MCU_PLL_CLOCK_REFERENCE_FXOSC = 0U, /**< Choose FXOSC as PLL reference clock */
    MCU_PLL_CLOCK_REFERENCE_FIRC = 1U,  /**< Choose FIRC as PLL reference clock */
} Mcu_PllClockRefType;

/**
 * @brief This enumeration type is used to enumerate the IPC clock source.
 */
#if defined(CPU_YTM32B1HA0)
typedef enum
{
    MCU_IPC_CLK_SRC_OFF       = 0x00U,  /**< IPC clock is off */
    MCU_IPC_CLK_SRC_FIRC      = 0x01U,  /**< Choose FIRC as IPC clock */
    MCU_IPC_CLK_SRC_SIRC_DIV4 = 0x02U,  /**< Choose SIRC_DIV4 as IPC clock */
    MCU_IPC_CLK_SRC_FXOSC     = 0x03U,  /**< Choose FXOSC as IPC clock */
    MCU_IPC_CLK_SRC_SXOSC     = 0x04U,  /**< Choose SXOSC as IPC clock */
    MCU_IPC_CLK_SRC_PLL       = 0x05U,  /**< Choose PLL as IPC clock */

    MCU_IPC_CLK_SRC_FAST_BUS  = 0x07U,  /**< Choose Fast bus as IPC clock */
} Mcu_PeripheralClockSourceType;
#elif defined(CPU_YTM32B1ME0) || defined(CPU_YTM32B1MD1)
typedef enum
{
    MCU_IPC_CLK_SRC_OFF       = 0x00U,  /**< IPC clock is off */
    MCU_IPC_CLK_SRC_FIRC      = 0x01U,  /**< Choose FIRC as IPC clock */
    MCU_IPC_CLK_SRC_SIRC      = 0x02U,  /**< Choose SIRC as IPC clock */
    MCU_IPC_CLK_SRC_FXOSC = 0x03U,      /**< Choose FXOSC as IPC clock */
#if (MCU_HAS_SXOSC == STD_ON)
    MCU_IPC_CLK_SRC_SXOSC     = 0x04U,  /**< Choose SXOSC as IPC clock */
#endif
    MCU_IPC_CLK_SRC_PLL       = 0x05U,  /**< Choose PLL as IPC clock */
} Mcu_PeripheralClockSourceType;
#elif defined(CPU_YTM32B1MC0)
typedef enum
{
    MCU_IPC_CLK_SRC_OFF       = 0x00U,  /**< IPC clock is off */
    MCU_IPC_CLK_SRC_FIRC      = 0x01U,  /**< Choose FIRC as IPC clock */
    MCU_IPC_CLK_SRC_SIRC      = 0x02U,  /**< Choose SIRC as IPC clock */
    MCU_IPC_CLK_SRC_FXOSC     = 0x03U,  /**< Choose FXOSC as IPC clock */
    MCU_IPC_CLK_SRC_LPO       = 0x04U,  /**< Choose LPO clock as IPC clock */

    MCU_IPC_CLK_SRC_FAST_BUS  = 0x07U,  /**< Choose Fast bus as IPC clock */
} Mcu_PeripheralClockSourceType;
#endif

/**
 * @brief This enumeration type is used to enumerate the Mcu error types.
 */
typedef enum
{
    MCU_E_CLOCK_FAILURE = 0U,           /**< Error in clock setting */
    MCU_E_CMU_FAILURE = 1U,             /**< Error in monitored clock frequency is checked */
} Mcu_ErrorType;

#if (MCU_ENABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
typedef enum
{
    MCU_EVENT_STATUS_PASSED = 0U,                   /**< @brief Mcu event passed */
    MCU_EVENT_STATUS_FAILED = 1U,                   /**< @brief Mcu event failed */
    MCU_EVENT_STATUS_PREPASSED = 2U,                /**< @brief Mcu event pre-passed */
    MCU_EVENT_STATUS_PREFAILED = 3U,                /**< @brief Mcu event pre-failed */
    MCU_EVENT_STATUS_FDC_THRESHOLD_REACHED = 4U     /**< @brief Mcu event pre-failed */
} Mcu_EventStatusType;
#endif

#if defined(CPU_YTM32B1MC0)
typedef enum
{
    MCU_PCU_LVD5V = 0U,
} Mcu_PcuLvdType;

typedef enum
{
    MCU_PCU_LVD5V_TRIM_1850MV = 0U,      /**< LVD5V threshold voltage is 1.850V */
    MCU_PCU_LVD5V_TRIM_2090MV = 1U,      /**< LVD5V threshold voltage is 2.090V */
    MCU_PCU_LVD5V_TRIM_2330MV = 2U,      /**< LVD5V threshold voltage is 2.330V */
    MCU_PCU_LVD5V_TRIM_2570MV = 3U,      /**< LVD5V threshold voltage is 2.570V */
    MCU_PCU_LVD5V_TRIM_2810MV = 4U,      /**< LVD5V threshold voltage is 2.810V */
    MCU_PCU_LVD5V_TRIM_3050MV = 5U,      /**< LVD5V threshold voltage is 3.050V */
    MCU_PCU_LVD5V_TRIM_3290MV = 6U,      /**< LVD5V threshold voltage is 3.290V */
    MCU_PCU_LVD5V_TRIM_3530MV = 7U,      /**< LVD5V threshold voltage is 3.530V */
    MCU_PCU_LVD5V_TRIM_3770MV = 8U,      /**< LVD5V threshold voltage is 3.770V */
    MCU_PCU_LVD5V_TRIM_4010MV = 9U,      /**< LVD5V threshold voltage is 4.010V */
    MCU_PCU_LVD5V_TRIM_4250MV = 10U,     /**< LVD5V threshold voltage is 4.250V */
    MCU_PCU_LVD5V_TRIM_4490MV = 11U,     /**< LVD5V threshold voltage is 4.490V */
    MCU_PCU_LVD5V_TRIM_4730MV = 12U,     /**< LVD5V threshold voltage is 4.730V */
    MCU_PCU_LVD5V_TRIM_4970MV = 13U,     /**< LVD5V threshold voltage is 4.970V */
} Mcu_PcuLvdTrimType;

typedef enum
{
    MCU_PCU_LVD5V_HYS_PERCENT_0P0 = 0U,  /**< LVD5V hysteresis is 0% */
    MCU_PCU_LVD5V_HYS_PERCENT_2P0 = 1U,  /**< LVD5V hysteresis is 2% */
    MCU_PCU_LVD5V_HYS_PERCENT_4P2 = 2U,  /**< LVD5V hysteresis is 4.2% */
    MCU_PCU_LVD5V_HYS_PERCENT_8P4 = 3U,  /**< LVD5V hysteresis is 8.4% */
} Mcu_PcuLvdHysteresisType;

typedef enum
{
    MCU_PCU_ESCFG_INDEX_0 = 0U,           /**< 0.10% of normal mode, Sampling period is 512ms */
    MCU_PCU_ESCFG_INDEX_1 = 1U,           /**< 0.20% of normal mode, Sampling period is 256ms */
    MCU_PCU_ESCFG_INDEX_2 = 2U,           /**< 0.40% of normal mode, Sampling period is 128ms */
    MCU_PCU_ESCFG_INDEX_3 = 3U,           /**< 0.80% of normal mode, Sampling period is 64ms */
    MCU_PCU_ESCFG_INDEX_4 = 4U,           /**< 1.56% of normal mode, Sampling period is 32ms */
    MCU_PCU_ESCFG_INDEX_5 = 5U,           /**< 3.10% of normal mode, Sampling period is 16ms */
    MCU_PCU_ESCFG_INDEX_6 = 6U,           /**< 6.25% of normal mode, Sampling period is 8ms */
    MCU_PCU_ESCFG_INDEX_7 = 7U,           /**< 12.5% of normal mode, Sampling period is 4ms */
    MCU_PCU_ESCFG_INDEX_8 = 8U,           /**< 25.0% of normal mode, Sampling period is 2ms */
    MCU_PCU_ESCFG_INDEX_9 = 9U,           /**< 50.0% of normal mode, Sampling period is 1ms */
} Mcu_PcuLvdESConfigureType;

typedef enum
{
    MCU_PCU_PMCHPRDY_DELAY_80US  = 0U,   /**< PMC high power ready delay time is 80us */
    MCU_PCU_PMCHPRDY_DELAY_160US = 1U,   /**< PMC high power ready delay time is 160us */
    MCU_PCU_PMCHPRDY_DELAY_240US = 2U,   /**< PMC high power ready delay time is 240us */
    MCU_PCU_PMCHPRDY_DELAY_320US = 3U,   /**< PMC high power ready delay time is 320us */
} Mcu_PcuPMCHPRDYDelayType;

#else
typedef enum
{
    MCU_PCU_HVD11 = 0U,                 /**< High voltage domain name on VDD11 area */
    MCU_PCU_HVD25 = 1U,                 /**< High voltage domain name on VDD25 area */
    MCU_PCU_HVD50 = 2U,                 /**< High voltage domain name on VDD area */
} Mcu_PcuHvdType;
#endif

/**
 * @brief This enumeration type is used to enumerate the Mcu power mode.
 */
typedef enum
{
    MCU_POWER_MODE_RUN,                 /**< Mcu power mode Run */
    MCU_POWER_MODE_STANDBY,             /**< Mcu power mode Standby */
    MCU_POWER_MODE_SLEEP,               /**< Mcu power mode Sleep */
    MCU_POWER_MODE_DEEPSLEEP,           /**< Mcu power mode Deep Sleep */
#if (MCU_POWERDOWN_MODE_SUPPORT == STD_ON)
    MCU_POWER_MODE_POWERDOWN,           /**< Mcu power mode Power Down */
#endif
} Mcu_PowerModeType;

#if (MCU_FXOSC_DELAY_SUPPORT == STD_ON)
/**
 * @brief This enumeration type is used to enumerate the FXOSC clock output delay select.
 */
typedef enum
{
    MCU_FXOSC_DELAY_4096_CYCLES  = 0U, /**< Delay 4096 cycles*/
    MCU_FXOSC_DELAY_8192_CYCLES  = 1U, /**< Delay 8192 cycles*/
    MCU_FXOSC_DELAY_16384_CYCLES = 2U, /**< Delay 16384 cycles*/
    MCU_FXOSC_DELAY_32768_CYCLES = 3U, /**< Delay 32768 cycles*/
} Mcu_FxoscDelayTypes;
#endif

/**
 * @brief Definition of Mcu Clock Type This typedef defines the MCU clock type as an 8-bit unsigned integer (uint8).
 */
typedef uint8 Mcu_ClockType;

/**
 * @brief MCU raw reset type definition
 */
typedef uint32 Mcu_RawResetType;

/**
 * @brief This type specifies the identification (ID) for a RAM section, which is configured in the configuration structure
 */
typedef uint8 Mcu_RamSectionType;

/**
 * @brief Mcu module notification function type definition
 */
typedef void (*Mcu_NotificationType)(void);

/**
 * @brief Mcu module Cmu notification function type definition
 */
typedef void (*Mcu_CmuNotificationType)(Mcu_CmuErrorType);

/**
 * @brief Type definition of struct that contains the configuration of an MCU RAM block or section.
*/
typedef struct
{
    uint8 *BaseAddress;                 /**< Base address of the RAM block or section. */
    uint32 SectionSize;                 /**< Size of the RAM block or section in bytes. */
    uint8 DefaultValue;                 /**< Default value of the RAM block or section. */
} Mcu_RamSectionConfigType;

/**
 * @brief Configuration structure for the Mcu Clock Monitor.
 */
typedef struct
{
    boolean Enable;                                 /**< If set to true, enables the Clock Monitor. */
    Mcu_CmuClockReferenceType ClockReference;       /**< Selects the clock reference to be used by the CMU. */
    boolean ResetEnable;                            /**< Configures whether to reset the chip once CMU error detected */
    uint16 CmuCmpLValue;                            /**< Configures the low value of CMU compare register */
    uint16 CmuCmpHValue;                            /**< Configures the high value of CMU compare register */
    boolean CmuIntEnable;                           /**< Configures the interrupt enable of CMU */
    Mcu_CmuNotificationType NotificationPtr;        /**< Configures the notification of CMU */
    uint8 CmuChannelIdx;                            /**< Configures the current CMU channel Id */
} Mcu_ClockMonitorConfigType;

/**
 * @brief SCU FXOSC configuration.
 */
typedef struct
{
    uint32 ClockRefPointFrequency;      /**< Clock reference point frequency */
    boolean BypassMode;                 /**< FXOSC bypass mode*/
    uint8 GainSelection;                /**< FXOSC gain selection */
    boolean DeepSleepEnable;            /**< FXOSC deep sleep enable */
#if (MCU_FXOSC_DELAY_SUPPORT == STD_ON)
    Mcu_FxoscDelayTypes DelaySelect;    /**< FXOSC clock out delay enable */
#endif
} Mcu_FxoscConfigType;

#if (MCU_HAS_SXOSC == STD_ON)
/**
 * @brief SCU SXOSC configuration.
 */
typedef struct
{
    uint32 ClockRefPointFrequency;      /**< Clock reference point frequency */
    boolean BypassMode;                 /**< SXOSC bypass mode*/
    uint8 GainSelection;                /**< SXOSC gain selection */
    boolean DeepSleepEnable;            /**< SXOSC deep sleep enable */
    boolean StandbyEnable;              /**< SXOSC standby enable */
    boolean PowerDownEnable;            /**< SXOSC power down enable */
} Mcu_SxoscConfigType;
#endif

/**
 * @brief SCU SIRC configuration.
 */
typedef struct {
    uint32 SircClockRefPointFrequency;
    boolean SircDeepSleepEnable;        /** SIRC DeepSleep mode enable */
    boolean SircStandbyEnable;          /** SIRC Standby mode enable */
#if (MCU_POWERDOWN_MODE_SUPPORT == STD_ON)
    boolean SircPowerDownEnable;        /** SIRC PowerDown mode enable */
#endif
} Mcu_SircConfigType;

/**
 * @brief SCU FIRC configuration.
 */
typedef struct {
#if (MCU_FIRC_DELAY_SUPPORT == STD_ON)
    boolean FircDelayEnable;            /** FIRC clock out delay enable */
#endif
    uint32 FircClockRefPointFrequency;
    boolean FircDeepSleepEnable;        /** FIRC DeepSleep mode enable */
} Mcu_FircConfigType;

/**
 * @brief ClockOut configuration.
 */
typedef struct
{
    Mcu_ClockOutSourceType Source;      /**< Selects the clock source to be output on the CLKOUT pin */
    uint8 ClockOutDiv;                  /**< Selects the clock divider to be used by the CLKOUT pin */
} Mcu_ClockOutConfigType;

/*!
 * @brief PLL configuration.
*/
typedef struct
{
    Mcu_PllClockRefType ClockRef;       /**< Selects the clock reference to be used by the PLL */
    uint8 RefDiv;                       /**< Selects the PLL reference clock divider */
    uint8 FeedbackDiv;                  /**< Selects the PLL feedback divider */
#if (MCU_PLL_ADVANCED_MODE_SUPPORT == STD_ON)
    boolean PLLDitherEnable;            /**< PLL Dither enable */
    uint8 PLLDitherGain;                /**< Dither gain control bit. Replace one bit of the accumulator with the output of the LFSR */
    boolean PLLFMModeEnable;            /**< PLL spread spectrum mode enable, enable or disable spread spectrum mode */
    uint32 PLLFMStepSize;               /**< Frequency Modulation Step Size */
    uint32 PLLFMStepNum;                /**< Frequency Modulation Number of Steps */
    boolean PLLFracModeEnable;          /**< PLL fractional mode enable */
    uint16 PLLFracLoopDivFactor;        /**< Numerator of Fractional Loop Division Factor */
#endif
} Mcu_PllConfigType;

/*!
 * @brief IPC configuration.
*/
typedef struct
{
    Mcu_PeripheralIndexType PeripheralIndex;        /**< Peripheral index */
    boolean ClockEnable;                            /**< Clock enable */
    Mcu_PeripheralClockSourceType ClockSource;      /**< Clock source */
    uint8 ClockDiv;                                 /**< Clock divider */
} Mcu_IpcConfigType;

/*!
 * @brief Peripheral clock configuration.
*/
typedef struct
{
    uint8 IpcCount;                     /**< IPC count */
    Mcu_IpcConfigType *IpcConfig;       /**< IPC configuration */
} Mcu_PeripheralClockConfigType;

/**
 * @brief   Mcu driver configuration structure.
 */
typedef struct
{
    Mcu_SystemClockSourceType SystemClockSource;    /**< System clock source */
    uint8 CoreClockDiv;                             /**< Core clock divider */
    uint8 FastBusClockDiv;                          /**< Fast bus clock divider */
    uint8 SlowBusClockDiv;                          /**< Slow bus clock divider */
    uint8 EfmPrescaleValue;                         /**< EFM prescale value */
    uint8 EfmWRSValue;                              /**< EFM WRS value */

    boolean SircUnderUserCtrl;                      /**< SIRC under user control */
    const Mcu_SircConfigType *SircConfig;           /**< SIRC configuration */

    boolean FircUnderUserCtrl;                      /**< FIRC under user control */
    boolean FircEnable;                             /**< FIRC enable */
    const Mcu_FircConfigType *FircConfig;           /**< FIRC configuration */

    boolean FxoscUnderUserCtrl;                     /**< FXOSC under user control */
    boolean FxoscEnable;                            /**< FXOSC enable */
    const Mcu_FxoscConfigType *FxoscConfig;         /**< FXOSC configuration */

#if (MCU_HAS_SXOSC == STD_ON)
    boolean SxoscUnderUserCtrl;                     /**< SXOSC under user control */
    boolean SxoscEnable;                            /**< SXOSC enable */
    const Mcu_SxoscConfigType *SxoscConfig;         /**< SXOSC configuration */
#endif

    boolean PllUnderUserCtrl;                       /**< PLL under user control */
    boolean PllEnable;                              /**< PLL enable */
    const Mcu_PllConfigType *PllConfig;             /**< PLL configuration */

    boolean ClockOutEnable;                         /**< Clock out enable */
    const Mcu_ClockOutConfigType *ClockOutConfig;   /**< Clock out configuration */

    const Mcu_ClockMonitorConfigType *ClockMonitorConfig;   /**< Clock monitor configuration */
    const uint8 ClockMonitorConfigNums;             /**< Clock monitor configuration number */
    const Mcu_PeripheralClockConfigType *PeripheralClockConfig;  /**< Peripheral clock configuration */
} Mcu_ClockConfigType;

/**
@brief Struct representing configuration for MCU reset parameters.
*/
typedef struct
{
    boolean HwResetPinOutputEnable;     /**< Enables/disables the hardware reset output pin. */
    boolean HwResetPinFilterEnable;     /**< Enables/disables the filter for the hardware reset output pin. */
    uint8 HwResetPinFilterCount;        /**< Sets the number of filtered reset events after which the hardware reset output is triggered. */
} Mcu_ResetConfigType;



#if defined(CPU_YTM32B1MC0)
/**
 * @brief Pcu config type for MC chip.
 */
typedef struct {
    struct {
        uint8 BOREnable               : 1;          /**< Controls the enablement of Brown-out-reset (BOR). */
        uint8 BORLowPowerModeEnable   : 1;          /**< Controls the enablement of BOR Low Power Mode. */
        uint8 LVD5VEnable             : 1;          /**< Controls the enablement of LVD5V. */
        uint8 LVD1P5VEnable           : 1;          /**< Controls the enablement of LVD1P5. */
        uint8 LVD5VLowPowerModeEnable : 1;          /**< Controls the enablement of LVD5V Low Power Mode. */
        uint8 LVD5VReset              : 1;          /**< Controls whether to trigger a reset upon detecting the LVD5V flag. */
        uint8 LVD5VFilterEnable       : 1;          /**< Controls the enablement of the LVD5V filter. */
        uint8 LVD5VIntEnable          : 1;          /**< Controls the enablement of LVD5V interrupt. */
    } EnableBitList;
    uint8 LVD5VFilterWidth;                         /**< LVD5V filter width. */
    Mcu_NotificationType LVD5VNotificationPtr;      /**< Pointer to the interrupt function for LVD5V. */
    Mcu_PcuLvdTrimType LVD5VTrim;                   /**< LVD5V detection voltage setting. */
    Mcu_PcuLvdHysteresisType LVD5VHysteresis;       /**< Hysteresis for LVD5V voltage detection. */
} Mcu_PcuLvdConfigType;

#else
/**
 * @brief Pcu config type.
 */
typedef struct
{
    boolean ResetEnable;                            /**< High voltage detect reset enable */
    boolean HVD11IntEnable;                         /**< HVD11 interrupt enable */
    Mcu_NotificationType HVD11NotificationPtr;      /**< HVD11 interrupt notification fun ptr */
    boolean HVD25IntEnable;                         /**< HVD25 interrupt enable */
    Mcu_NotificationType HVD25NotificationPtr;      /**< HVD25 interrupt notification fun ptr */
    boolean HVD50IntEnable;                         /**< HVD50 interrupt enable */
    Mcu_NotificationType HVD50NotificationPtr;      /**< HVD50 interrupt notification fun ptr */
} Mcu_PcuHvdConfigType;
#endif
/**
 * Mcu pcu config type
 * The HVD/LVD detect is default enabled by hardware
*/
typedef struct
{
#if defined(CPU_YTM32B1MC0)
    const Mcu_PcuLvdConfigType *LvdConfigPtr;       /**< Lvd config ptr */
    boolean SetCoreVoltage;                         /**< Set Core supply to 1V when PMC is in low power mode */
    Mcu_PcuPMCHPRDYDelayType PMCHPRDYConfigure;     /**< PMC high power mode ready delay configure */
    Mcu_PcuLvdESConfigureType EnergySavingConfigure;/**< control the sampling time in low power mode */
#else
    const Mcu_PcuHvdConfigType *HvdConfigPtr;       /**< Interrupt config ptr */
    boolean FastRecoveryEnable;                     /**< Fast recovery from LPM enable */
#if (MCU_HAS_PKE == STD_ON)
    boolean PadKeepEnable;                          /**< PAD keep enable, ME series chip is not support*/
#endif
#endif
} Mcu_PcuConfigType;

/**
 * @brief Dem error type, contains Dem error enable and error ID
 */
typedef struct
{
    uint32 Enable;                      /**< enabling/disabling the DEM error: Active=STD_ON/ Inactive=STD_OFF */
    uint32 EventId;                     /**< ID of DEM error (0 if STD_OFF)*/
} Mcu_DemErrorType;


/**
* @brief DEM error reporting configuration.
* @details This structure contains information DEM error reporting
*/
typedef struct
{
    Mcu_DemErrorType ErrorClockFailureCfg;          /**< DEM error reporting configuration for clock failure */
    Mcu_DemErrorType ErrorCMUFailureCfg;            /**< DEM error reporting CMU clock failure */
} Mcu_DemConfigType;



/**
 * @brief Configuration structure for the MCU power configuration
 */
typedef struct
{
    const Mcu_PowerModeType* ModeMap; /**< Pointer to an array of structures containing ModeMap */
} Mcu_PowerConfigType;

/**

@brief Configuration structure for the MCU driver
*/
typedef struct
{
#if (MCU_ENABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
    const Mcu_DemConfigType *DemConfig;            /**< DEM error reporting configuration. */
#endif
    const Mcu_ClockConfigType *ClockConfig;         /**< Pointer to an array of structures containing clock configuration data */
    uint8 ClockConfigNum;                           /**< The number of clock configurations contained in the array pointed by ClockConfig */
    Mcu_RamSectionConfigType *RamSectionConfig;     /**< Pointer to an array of structures containing RAM section configuration data */
    const Mcu_ResetConfigType *ResetConfig;         /**< Pointer to a structure containing reset configuration data */
    uint8 ModeConfigNum;                            /**< Number of power modes that can be configured within this device */
    const Mcu_PowerConfigType *PowerConfig;         /**< Pointer to an array of structures containing power mode configuration data */
    uint8 RamSectionConfigNum;                      /**< Number of RAM sections that are available within this device */
    const Mcu_PcuConfigType *PcuConfig;             /**< Pointer to a structure containing PCU configuration data */
} Mcu_ConfigType;


/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#if MCU_NO_PLL == STD_OFF
/**
 * @brief            This service activates the PLL clock to the MCU clock distribution.
 * @details
 * @return           Std_ReturnType
 * @note             service_id:       0x03
 *                   is_reentrant:     false
 *                   is_synchronous:   true
 *                   autosar_api:      true
 */
Std_ReturnType Mcu_DistributePllClock(void);
#endif

/**
 * @brief Resets the CM33 system.
 *
 * This function is responsible for resetting the CM33 system. It does not return any value.
 *
 * @note This function should only be called when a system reset is required.
 */
void Mcu_Lld_SystemReset(void);

/**
 * @brief            This service provides the lock status of the PLL.
 * @details
 * @return           Mcu_PllStatusType
 * @note             service_id:       0x04
 *                   is_reentrant:     true
 *                   is_synchronous:   true
 *                   autosar_api:      true
 */
Mcu_PllStatusType Mcu_GetPllStatus(void);

#if (MCU_GET_SXOSC_STATU_API == STD_ON)
/**
 * @brief            This service provides the lock status of the SXOSC.
 * @details
 * @return           Mcu_PllStatusType
 * @note             service_id:       0x0C
 *                   is_reentrant:     true
 *                   is_synchronous:   true
 *                   autosar_api:      false
 */
Mcu_SxoscStatusType Mcu_GetSxoscStatus(void);
#endif

/**
 * @brief            This service provides the actual status of the microcontroller Ram. (if supported)
 * @details
 * @return           Mcu_RamStateType
 * @note             service_id:       0x0a
 *                   is_reentrant:     true
 *                   is_synchronous:   true
 *                   autosar_api:      true
 */
Mcu_RamStateType Mcu_GetRamState(void);

/**
 * @brief            The service reads the reset type from the hardware, if supported.
 * @details
 * @return           Mcu_ResetType
 * @note             service_id:       0x05
 *                   is_reentrant:     true
 *                   is_synchronous:   true
 *                   autosar_api:      true
 */
Mcu_ResetType Mcu_GetResetReason(void);

/**
 * @brief            This service initializes the MCU driver.
 * @details
 * @param[in]        ConfigPtr Pointer to MCU driver configuration set.
 * @return           void
 *
 * @note             service_id:       0x00
 *                   is_reentrant:     false
 *                   is_synchronous:   true
 *                   bsw_entry_kind:   CONCRETE
 *                   autosar_api:      true
 */
void Mcu_Init(const Mcu_ConfigType *ConfigPtr);

#if (MCU_INIT_CLOCK == STD_ON)
/**
 * @brief            This service initializes the PLL and other MCU specific clock options.
 * @details
 *
 * @param[in]        ClockSetting Clock setting
 *
 * @return           Std_ReturnType
 *
 * @note             service_id:       0x02
 *                   is_reentrant:     false
 *                   is_synchronous:   true
 *                   bsw_entry_kind:   CONCRETE
 *                   autosar_api:      true
 */
Std_ReturnType Mcu_InitClock(Mcu_ClockType ClockSetting);

/**
 * @brief            Get the current MCU core clock frequency, must call Mcu_InitClock() first.
 * @details
 * @return           uint32
 */
uint32 Mcu_180_GetCoreClockFrequency(void);
#endif

/**
 * @brief            This service initializes the RAM section wise.
 * @details
 *
 * @param[in]        RamSection Selects RAM memory section provided in configuration set
 *
 * @return           Std_ReturnType
 *
 * @note             service_id:       0x01
 *                   is_reentrant:     false
 *                   is_synchronous:   true
 *                   bsw_entry_kind:   CONCRETE
 *                   autosar_api:      true
 */
Std_ReturnType Mcu_InitRamSection(Mcu_RamSectionType RamSection);

/**
 * @brief            The service performs a microcontroller reset.
 * @details
 *
 *
 * @return           void
 *
 * @note             service_id:       0x07
 *                   is_reentrant:     false
 *                   is_synchronous:   true
 *                   bsw_entry_kind:   CONCRETE
 *                   autosar_api:      true
 */
void Mcu_PerformReset(void);

/**
 * @brief            This service activates the MCU power modes.
 * @details
 *
 * @param[in]        McuMode Set different MCU power modes configured in the configuration set
 *
 * @return           void
 *
 * @note             service_id:       0x08
 *                   is_reentrant:     true
 *                   is_synchronous:   true
 *                   bsw_entry_kind:   CONCRETE
 *                   autosar_api:      true
 * @note             This function will disable all CMU channels when the power mode is switched
 *                   to PowerDown or StandBy mode.
 */
void Mcu_SetMode(Mcu_ModeType McuMode);

/**
 * @brief  Get raw reset value.
 * @return  Mcu_RawResetType
 */
Mcu_RawResetType Mcu_GetResetRawValue(void);

#if (MCU_ENABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
/**
 * @brief Sets the status of a given event.
 *        This function will invoke Dem_SetEventStatus to configure the event status. It serves
 *        as a bridge because certain error detection mechanisms within the Mcu module necessitate
 *        the invocation of Dem_SetEventStatus within interrupt functions. This abstraction helps
 *        maintain a clear separation between low-level operations and higher-level abstractions.
 *
 * @param[in] EventId The Event name in the Mcu module
 * @param[in] EventStatus The status to be set for the given event.
 *
 * @return Std_ReturnType The standard return type indicating if the operation was successful
*/
Std_ReturnType Mcu_SetEventStatus(Mcu_ErrorType ErrorType, Mcu_EventStatusType EventStatus);
#endif /* MCU_ENABLE_DEM_REPORT_ERROR_STATUS == STD_ON */

#ifdef __cplusplus
}
#endif

#endif /* MCU_H */

/** @} */

