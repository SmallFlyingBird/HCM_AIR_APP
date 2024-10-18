/**************************************************************************************************/
/**
 * @file      : Scc_Drv_Types.h
 * @brief     : SCC low level driver type definition header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef SCC_DRV_TYPES_H
#define SCC_DRV_TYPES_H

/** @addtogroup Mcu_Module
 *  @{
 */

/** @addtogroup Scc_Drv
 *  @brief SCC low level driver
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Scc_Drv_Cfg.h"
#include "Std_Types.h"
#include "McalLib.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define SCC_DRV_TYPES_H_VENDOR_ID                   0x00B3U
#define SCC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define SCC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define SCC_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define SCC_DRV_TYPES_H_SW_MAJOR_VERSION            1U
#define SCC_DRV_TYPES_H_SW_MINOR_VERSION            2U
#define SCC_DRV_TYPES_H_SW_PATCH_VERSION            1U

/* Check if current file and Scc_Drv_Cfg.h file are of the same vendor */
#if (SCC_DRV_TYPES_H_VENDOR_ID != SCC_DRV_CFG_H_VENDOR_ID)
    #error "Vendor ID of Scc_Drv_Types.h and Scc_Drv_Cfg.h are different"
#endif

/* Check if current file and Scc_Drv_Cfg.h file are of the same Autosar version */
#if ((SCC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != SCC_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) ||       \
     (SCC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != SCC_DRV_CFG_H_AR_RELEASE_MINOR_VERSION) ||       \
     (SCC_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION != SCC_DRV_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Scc_Drv_Types.h and Scc_Drv_Cfg.h are different"
#endif

/* Check if current file and Scc_Drv_Cfg.h file are of the same Software version */
#if ((SCC_DRV_TYPES_H_SW_MAJOR_VERSION != SCC_DRV_CFG_H_SW_MAJOR_VERSION) ||                       \
     (SCC_DRV_TYPES_H_SW_MINOR_VERSION != SCC_DRV_CFG_H_SW_MINOR_VERSION) ||                       \
     (SCC_DRV_TYPES_H_SW_PATCH_VERSION != SCC_DRV_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Scc_Drv_Types.h and Scc_Drv_Cfg.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    /* Check if current file and Std_Types.h file are of the same Autosar version */
    #if ((SCC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) ||             \
         (SCC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of c.h and Std_Types.h are different"
    #endif

    /* Check if current file and McalLib.h file are of the same Autosar version */
    #if ((SCC_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION != MCALLIB_AR_RELEASE_MAJOR_VERSION) ||         \
         (SCC_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION != MCALLIB_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version of Scc_Drv_Types.h and McalLib.h are different"
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 *  @brief Type of clock source.
 *
 */
typedef enum
{
    SCC_DRV_CLOCK_SRC_NO = 0U, /*!< None is selected */
    SCC_DRV_CLOCK_SRC_LPO32K,  /*!< LPO32K */
    SCC_DRV_CLOCK_SRC_SOSC,    /*!< Slow OSC clock */
    SCC_DRV_CLOCK_SRC_FIRC64M, /*!< FIRC64M */
    SCC_DRV_CLOCK_SRC_FOSC,    /*!< Fast OSC clock */
    SCC_DRV_CLOCK_SRC_PLL      /*!< PLL */
} Scc_Drv_ClockSrcType;

/**
 *  @brief Type of the system clock source.
 *
 */
typedef enum
{
    SCC_DRV_SYS_CLOCK_FIRC64M = 1U, /*!< FIRC64M System Clock */
    SCC_DRV_SYS_CLOCK_FOSC = 2U,    /*!< Fast OSC System Clock */
    SCC_DRV_SYS_CLOCK_PLL = 3U      /*!< PLL System Clock */
} Scc_Drv_SystemClockType;

/**
 *  @brief Type of fast OSC/Slow OSC clock mode.
 *
 */
typedef enum
{
    SCC_DRV_OSC_XTAL = 0U, /*!< Internal oscillator mode */
    SCC_DRV_OSC_EXT_SRC    /*!< External oscillator mode */
} Scc_Drv_OscModeType;

/**
 *  @brief Type of FOSC clock high frequency mode.
 *
 */
typedef enum
{
    SCC_DRV_FOSC_FREQ_MODE_LOW = 0U, /*!< Fast OSC clock works in low frequency mode */
    SCC_DRV_FOSC_FREQ_MODE_HIGH      /*!< Fast OSC clock works in high frequency mode */
} Scc_Drv_FOscFreqModeType;

/**
 *  @brief Type of loss of OSC clock detected action.
 *
 */
typedef enum
{
    SCC_DRV_OSC_CLOCK_LOSS_INT = 0U, /*!< Generated interrupt if loss of clock is detected */
    SCC_DRV_OSC_CLOCK_LOSS_RST       /*!< Generated reset if loss of clock is detected */
} Scc_Drv_OscClockLossActType;

/**
 *  @brief Type of loss of FIRC64M clock detected action.
 *
 */
typedef enum
{
    SCC_DRV_FIRC64M_CLOCK_LOSS_INT = 0U, /*!< Generated interrupt if loss of clock is detected */
    SCC_DRV_FIRC64M_CLOCK_LOSS_RST       /*!< Generated reset if loss of clock is detected */
} Scc_Drv_Firc64MClockLossActType;

#if (SCC_DRV_ENABLE_PLL_MONITOR_API == STD_ON)
/**
 *  @brief Type of loss of PLL clock detected action.
 *
 */
typedef enum
{
    SCC_DRV_PLL_CLOCK_LOSS_INT = 0U, /*!< Generated interrupt if loss of clock is detected */
    SCC_DRV_PLL_CLOCK_LOSS_RST       /*!< Generated reset if loss of clock is detected */
} Scc_Drv_PllClockLossActType;
#endif

/**
 *  @brief Type of PLL reference clock selection.
 *
 */
typedef enum
{
    SCC_DRV_PLL_REF_FIRC64M = 0U, /*!< PLL select FIRC as reference clock */
    SCC_DRV_PLL_REF_FOSC          /*!< PLL select Fast OSC as reference clock */
} Scc_Drv_PllRefClockType;

/**
 *  @brief Type of PLL clock pre-divider selection.
 *
 */
typedef enum
{
    SCC_DRV_PLL_PRE_DIV_1 = 0U, /*!< PLL pre-divider value is 1 */
    SCC_DRV_PLL_PRE_DIV_2 = 1U, /*!< PLL pre-divider value is 2 */
    SCC_DRV_PLL_PRE_DIV_4 = 2U  /*!< PLL pre-divider value is 4 */
} Scc_Drv_PllPreDivType;

/**
 *  @brief Type of PLL clock post-divider selection.
 *
 */
typedef enum
{
    SCC_DRV_PLL_POST_DIV_6 = 3U,  /*!< PLL post divider value is 6 */
    SCC_DRV_PLL_POST_DIV_8 = 4U,  /*!< PLL post divider value is 8 */
    SCC_DRV_PLL_POST_DIV_10 = 5U, /*!< PLL post divider value is 10 */
    SCC_DRV_PLL_POST_DIV_12 = 6U, /*!< PLL post divider value is 12 */
    SCC_DRV_PLL_POST_DIV_14 = 7U  /*!< PLL post divider value is 14 */
} Scc_Drv_PllPostDivType;

/**
 *  @brief Type of PLL clock pre-scaler selection.
 *
 */
typedef enum
{
    SCC_DRV_PLL_SCALER_1 = 0U, /*!< PLL pre-scaler value is 1 */
    SCC_DRV_PLL_SCALER_2 = 1U  /*!< PLL pre-scaler value is 2 */
} Scc_Drv_PllPreScalerType;

/**
 *  @brief Type of the system clock.
 *
 */
typedef enum
{
    SCC_DRV_SYS_CLOCK_CORE = 0x85U, /*!< Core */
    SCC_DRV_SYS_CLOCK_BUS = 0x86U,  /*!< Bus */
    SCC_DRV_SYS_CLOCK_SLOW = 0x87U  /*!< Slow */
} Scc_Drv_SysClockType;

/**
 *  @brief Type of the system clock divider.
 *
 */
typedef enum
{
    SCC_DRV_SYS_CLOCK_DIV_1 = 0U, /*!< clock divided by 1 */
    SCC_DRV_SYS_CLOCK_DIV_2,      /*!< clock divided by 2 */
    SCC_DRV_SYS_CLOCK_DIV_3,      /*!< clock divided by 3 */
    SCC_DRV_SYS_CLOCK_DIV_4,      /*!< clock divided by 4 */
    SCC_DRV_SYS_CLOCK_DIV_5,      /*!< clock divided by 5 */
    SCC_DRV_SYS_CLOCK_DIV_6,      /*!< clock divided by 6 */
    SCC_DRV_SYS_CLOCK_DIV_7,      /*!< clock divided by 7 */
    SCC_DRV_SYS_CLOCK_DIV_8,      /*!< clock divided by 8 */
    SCC_DRV_SYS_CLOCK_DIV_9,      /*!< clock divided by 9 */
    SCC_DRV_SYS_CLOCK_DIV_10,     /*!< clock divided by 10 */
    SCC_DRV_SYS_CLOCK_DIV_11,     /*!< clock divided by 11 */
    SCC_DRV_SYS_CLOCK_DIV_12,     /*!< clock divided by 12 */
    SCC_DRV_SYS_CLOCK_DIV_13,     /*!< clock divided by 13 */
    SCC_DRV_SYS_CLOCK_DIV_14,     /*!< clock divided by 14 */
    SCC_DRV_SYS_CLOCK_DIV_15,     /*!< clock divided by 15 */
    SCC_DRV_SYS_CLOCK_DIV_16      /*!< clock divided by 16 */
} Scc_Drv_SysClockDividerType;

/**
 *  @brief Type of the PLL clock parameter configuration.
 *
 */
typedef struct
{
    Scc_Drv_PllPreDivType    PllPreDivider;  /*!< PLL pre-divider */
    Scc_Drv_PllPostDivType   PllPostDivider; /*!< PLL post-divider */
    uint32                   PllMultiplier;  /*!< PLL multiplier */
    Scc_Drv_PllRefClockType  PllRefClock;    /*!< PLL reference clock */
    Scc_Drv_PllPreScalerType PllPreScaler;   /*!< PLL pre-scaler */
    uint32                   PllFreq;        /*!< PLL frequency */
} Scc_Drv_PllParamConfigType;

/**
 *  @brief Type of the PLL clock configuration.
 *
 */
typedef struct
{
    Scc_Drv_PllParamConfigType SccPllClockParamConfig;
    boolean                    SccPllEnableUnderStop; /*!< Enable/Disable PLL in stop mode. */
    boolean                    Enable;
} Scc_Drv_PllClockConfigType;

/**
 *  @brief Type definition of loss of clock call back function of FIRC clock and FOSC clock.
 *
 */
typedef void (*Scc_Drv_LocCallbackFunc)(void);

/**
 *  @brief Type of FIRC64M clock configuration.
 *
 */
typedef struct
{
    /*!< Enable/Disable FIRC in stop mode. */
    boolean Firc64MStopEn;
    /*!< FIRC clock enable */
    boolean Enable;
    /*!< Loss of FIRC clock callback function */
    Scc_Drv_LocCallbackFunc Firc64MLocCallbackFunc;
} Scc_Drv_Firc64MClockConfigType;

/**
 *  @brief Type of FOSC clock configuration.
 *
 */
typedef struct
{
    /*!< Low/High Frequency Mode */
    Scc_Drv_FOscFreqModeType SccOscHfreq;
    /*!< Enable/Disable fast OSC clock in stop mode. */
    boolean SccOscEnableUnderStop;
    /*!< Mode:  internal/external */
    Scc_Drv_OscModeType Mode;
    /*!< Fast OSC clock enabled */
    boolean Enable;
    /*!< Loss of FOSC clock callback function */
    Scc_Drv_LocCallbackFunc LocCallbackFunc;
} Scc_Drv_FOscClockConfigType;

/**
 *  @brief Type of SOSC clock configuration.
 *
 */
typedef struct
{
    Scc_Drv_OscModeType Mode;   /*!< Mode:  internal/external */
    boolean             Enable; /*!< Slow OSC clock enabled */
} Scc_Drv_SOscClockConfigType;

/**
 *  @brief Type of LPO32K configuration.
 */
typedef struct
{
    uint32 Enable; /*!< LPO32K clock enable */
} Scc_Drv_LpoClockConfigType;

/**
 *  @brief Type of the system clock configuration.
 *
 */
typedef struct
{
    Scc_Drv_SystemClockType     SccSystemClockSource; /*!< System clock source config */
    uint32                      SccSystemClockFreq;   /*!< System clock source frequency */
    Scc_Drv_SysClockDividerType SccCoreClockDivider;  /*!< Core clock divider */
    Scc_Drv_SysClockDividerType SccBusClockDivider;   /*!< Bus clock divider */
    Scc_Drv_SysClockDividerType SccSlowClockDivider;  /*!< Slow(flash) clock divider */
} Scc_Drv_SystemClockConfigType;

/**
 *  @brief Type of the SCC clock configuration.
 *
 */
typedef struct
{
    Scc_Drv_SystemClockConfigType  SccSystemClockConfig; /*!< System clock config */
    Scc_Drv_Firc64MClockConfigType SccFircClockConfig;   /*!< FIRC clock config */
    Scc_Drv_FOscClockConfigType    SccFOscClockConfig;   /*!< FOsc clock config */
    Scc_Drv_PllClockConfigType     SccPllClockConfig;    /*!< PLL clock config */
    Scc_Drv_SOscClockConfigType    SccSOscClockConfig;   /*!< SOsc clock config */
    Scc_Drv_LpoClockConfigType     SccLpoClockConfig;    /*!< LPO32K clock config */
} Scc_Drv_ClockConfigType;

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

/** @} end of group Scc_Drv */

/** @} end of group Mcu_Module */

#endif /* SCC_DRV_TYPES_H */
