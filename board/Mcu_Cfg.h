/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Mcu_Cfg.h
 * @brief 
 * 
 */


#ifndef MCU_CFG_H
#define MCU_CFG_H


/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
#include "Mcu_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_VENDOR_ID_CFG                      (180)
#define MCU_AR_RELEASE_MAJOR_VERSION_CFG       (4)
#define MCU_AR_RELEASE_MINOR_VERSION_CFG       (4)
#define MCU_AR_RELEASE_REVISION_VERSION_CFG    (0)
#define MCU_SW_MAJOR_VERSION_CFG               (2)
#define MCU_SW_MINOR_VERSION_CFG               (3)
#define MCU_SW_PATCH_VERSION_CFG               (0)



/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/**
 * @brief This macro is used to indicate whether the chip supports the SXOSC clock.
 */
#define MCU_HAS_SXOSC                   (STD_OFF)

/**
 * @brief This macro is used to indicate whether the chip supports the PAD state keep function
 * when wakeup form Powerdown mode.
 */
#define MCU_HAS_PKE                     (STD_ON)

/**
 * @brief This macro defines whether the chip has advanced features of the PLL, including Fractional
 *        mode, spread spectrum mode, and dithering.
 */
#define MCU_PLL_ADVANCED_MODE_SUPPORT   (STD_OFF)

/**
 * @brief This macro is used to indicate whether the chip supports the Fault Management Unit (FMU).
 */
#define MCU_FMU_SUPPORT                 (STD_OFF)

/**
 * @brief This macro is used to indicate whether the chip supports the PowerDown mode.
 */
#define MCU_POWERDOWN_MODE_SUPPORT      (STD_ON)

/**
 * @brief This macro is used to indicate whether the chip supports the FIRC clock out delay.
 */
#define MCU_FIRC_DELAY_SUPPORT          (STD_OFF)

/**
 * @brief This macro is used to indicate whether the chip supports the FXOSC clock out delay.
 */
#define MCU_FXOSC_DELAY_SUPPORT         (STD_OFF)

/**
 * @brief This macro is used to indicate whether the CMU reference clock is changeable.
 */
#define MCU_CMU_REFERENCE_CHANGEABLE    (STD_ON)

/**
 * @brief Pre-processor switch to enable / disable the use of the Irq function PCU_IRQHandler
 */
#define MCU_LLD_PCU_ISR_USED            (STD_OFF)

/**
 * @brief Pre-processor switch to enable / disable the use of the Irq function SCU_IRQHandler
 */
#define MCU_LLD_SCU_ISR_USED            (STD_OFF)


/**
 * @brief Switches the development error detection and notification on or off.
 * @details - true: detection and notification is enabled.
 *          - false: detection and notification is disabled.
 *
 * @ref ECUC_Mcu_00166
 */
#define MCU_DEV_ERROR_DETECT            (STD_OFF)


/**
 * @brief Pre-processor switch to enable/disable the API Mcu_GetRamState.
 * @details (e.g. If the H/W does not support the functionality, this parameter can be used to disable the Api).
 *
 * @ref ECUC_Mcu_00181
 */
#define MCU_GET_RAM_STATE_API           (STD_OFF)


/**
 * @brief Pre-processor switch to enable / disable the API to read out the modules version information.
 *
 * @ref ECUC_Mcu_00168
 */
#define MCU_VERSION_INFO_API            (STD_OFF)


/**
 * @brief Pre-processor switch to enable / disable the API `Mcu_GetSxoscStatu()`.
 */
#define MCU_GET_SXOSC_STATU_API         (STD_OFF)

/**
 * @brief If this parameter is set to FALSE, the clock initialization has to be disabled from the MCU
 *        driver. This concept applies when there are some write once clock registers and a bootloader
 *        is present. If this parameter is set to TRUE, the MCU driver is responsible of the clock
 *        initialization.
 * @details
 *
 * @ref ECUC_Mcu_00182
 */
#define MCU_INIT_CLOCK                  (STD_ON)


/**
 * @brief This parameter shall be set True, if the H/W does not have a PLL or the PLL circuitry is
 *        enabled after the power on without S/W intervention. In this case MCU_DistributePllClock
 *        has to be disabled and  MCU_GetPllStatus has to return MCU_PLL_STATUS_UNDEFINED. Otherwise
 *        this parameters has to be set False
 * @details
 *
 * @ref ECUC_Mcu_00180
 */
#define MCU_NO_PLL                      (STD_OFF)


/**
 * @brief Pre-processor switch to enable / disable the use of the function Mcu_PerformReset()
 * @details
 *
 * @ref ECUC_Mcu_00167
 */
#define MCU_PERFORM_RESET_API           (STD_OFF)

/**
 * @brief Pre-processor Mcu init clock timeout, dummy time.
 * @details
 *         
 */
#define MCU_CLOCK_TIMEOUT_COUNT         (50000U)

/**
 * @brief Pre-processor Mcu PCU High voltage domain nums.
 */
#define MCU_PCU_DOMAIN_NUMS             (3U)

/**
 * @brief Pre-processor Mcu PCU High voltage domain nums.
 */
#define MCU_CMU_CHANNEL_NUMS            (4U)

/**
 * @brief Pre-compile Support.
 */
#define MCU_FIXED_PB_CONFIG             (STD_OFF)


/**
 * @brief The function Mcu_GetResetRawValue shall return an implementation specific value which does
 *        not correspond to a valid value of the reset status register and is not equal to 0 if this
 *        function is called prior to calling of the function Mcu_Init, and if supported by the
 *        hardware.
 * @note The value 0xFFFFFFFF is reserved for this purpose.
 *
 */
#define MCU_RAW_RESET_DEFAULT           ((uint32)0xFFFFFFFFUL)




#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
#error "Must define MCAL_ENABLE_USER_MODE_SUPPORT if MCU_ENABLE_USER_MODE_SUPPORT is defined"
#endif
#endif


/**
 * @brief Support for SchM: sync/atomic operations, global interrupt disable/enable.
 * @note - If this parameter has been configured to 'STD_ON', the MCAL driver code supports sync/atomic
 *         operations for key resource protection.
 *       - If it is enabled, all the SchM codes in MCAL Dio driver codes will work and support sync/atomic
 *         operation with CPU global interrupt enable/disable for key resource protection. 
 *       - Disable it can reduce code size, but may cause potential risks when access to some critical resource!
 */
#define MCU_SCHM_SUPPORT                ( (STD_ON))

/**
 * @brief Pre-compile enable MCU_DEM_REPORT_ERROR_STATUS
 */
#define MCU_ENABLE_DEM_REPORT_ERROR_STATUS  (STD_OFF)

/**
 * @brief Create defines with the values assigned to Mcu Reset Reason configurations.
 * @note These values can be  retrieved from Mcu_GetResetReason Api.
 */
#define McuConf_McuResetReasonConf_MCU_HVD_RESET             ((uint8)0U)

#define McuConf_McuResetReasonConf_MCU_DEEPSLEEP_ACK_RESET   ((uint8)1U)

#define McuConf_McuResetReasonConf_MCU_WATCHDOG_RESET        ((uint8)2U)

#define McuConf_McuResetReasonConf_MCU_CMU_RESET             ((uint8)3U)

#define McuConf_McuResetReasonConf_MCU_CORE_LOCK_RESET       ((uint8)4U)

#define McuConf_McuResetReasonConf_MCU_DEBUG_RESET           ((uint8)5U)

#define McuConf_McuResetReasonConf_MCU_SW_RESET              ((uint8)6U)

#define McuConf_McuResetReasonConf_MCU_RESETB_RESET          ((uint8)7U)

#define McuConf_McuResetReasonConf_MCU_POWER_ON_RESET        ((uint8)8U)

#define McuConf_McuResetReasonConf_MCU_MUTI_REASON_RESET     ((uint8)9U)

#define McuConf_McuResetReasonConf_MCU_RESET_UNDEFINED       ((uint8)10U)


/**
 * @brief The parameter represents the different type of reset that a Micro supports. This parameter is
 *        referenced by the parameter EcuMResetReason in the ECU State manager module.
 * @details
 *
 * @ref ECUC_Mcu_00186
 */
typedef enum
{
    MCU_HVD_RESET             = McuConf_McuResetReasonConf_MCU_HVD_RESET,
    MCU_DEEPSLEEP_ACK_RESET   = McuConf_McuResetReasonConf_MCU_DEEPSLEEP_ACK_RESET,
    MCU_WATCHDOG_RESET        = McuConf_McuResetReasonConf_MCU_WATCHDOG_RESET,
    MCU_CMU_RESET             = McuConf_McuResetReasonConf_MCU_CMU_RESET,
    MCU_CORE_LOCK_RESET       = McuConf_McuResetReasonConf_MCU_CORE_LOCK_RESET,
    MCU_DEBUG_RESET           = McuConf_McuResetReasonConf_MCU_DEBUG_RESET,
    MCU_SW_RESET              = McuConf_McuResetReasonConf_MCU_SW_RESET,
    MCU_RESETB_RESET          = McuConf_McuResetReasonConf_MCU_RESETB_RESET,
    MCU_POWER_ON_RESET        = McuConf_McuResetReasonConf_MCU_POWER_ON_RESET,
    MCU_MUTI_REASON_RESET     = McuConf_McuResetReasonConf_MCU_MUTI_REASON_RESET,
    MCU_RESET_UNDEFINED       = McuConf_McuResetReasonConf_MCU_RESET_UNDEFINED,
} Mcu_ResetType;

/**
 * @brief The Mcu_ModeType specifies the identification (ID) for a MCU mode, configured via configuration
 *        structure.
 * @details The type shall be uint8, uint16, or uint32.
 *
 * @implements Mcu_ModeType_typedef
 */
typedef uint32 Mcu_ModeType;


/**
 * @brief Create defines with the IDs assigned to Mcu Mode.
 *        These IDs will be transmitted as input parameters for Mcu_SetMode() API.
 */
#define McuConf_McuModeSettingConf_McuModeSettingConf_0 ((Mcu_ModeType)0)  


#if (MCU_INIT_CLOCK == STD_ON)
/**
 * @brief Create defines with the IDs assigned to Mcu Clock configurations.
 *        These IDs will be transmitted as input parameters for Mcu_InitClock() API.
 */

#define McuClockSettingConfig_0   ((Mcu_ClockType)0U)

#define McuConf_McuClockSettingConfig_McuClockSettingConfig_0   ((Mcu_ClockType)0U)

#endif /* #if (MCU_INIT_CLOCK == STD_ON) */

/*! @brief Peripheral Clock Index. */
typedef enum
{
    MCU_IPC_DMA_INDEX         = 8U,
    MCU_IPC_TRACE_INDEX       = 15U,
    MCU_IPC_EFM_INDEX         = 16U,
    MCU_IPC_GPIO_INDEX        = 17U,
    MCU_IPC_PCTRLA_INDEX      = 18U,
    MCU_IPC_PCTRLB_INDEX      = 19U,
    MCU_IPC_PCTRLC_INDEX      = 20U,
    MCU_IPC_PCTRLD_INDEX      = 21U,
    MCU_IPC_PCTRLE_INDEX      = 22U,
    MCU_IPC_LINFLEXD0_INDEX   = 27U,
    MCU_IPC_LINFLEXD1_INDEX   = 28U,
    MCU_IPC_LINFLEXD2_INDEX   = 29U,
    MCU_IPC_SENT0_INDEX       = 33U,
    MCU_IPC_I2C0_INDEX        = 35U,
    MCU_IPC_I2C1_INDEX        = 36U,
    MCU_IPC_SPI0_INDEX        = 42U,
    MCU_IPC_SPI1_INDEX        = 43U,
    MCU_IPC_SPI2_INDEX        = 44U,
    MCU_IPC_SPI3_INDEX        = 45U,
    MCU_IPC_FLEXCAN0_INDEX    = 48U,
    MCU_IPC_FLEXCAN1_INDEX    = 52U,
    MCU_IPC_FLEXCAN2_INDEX    = 56U,
    MCU_IPC_ADC0_INDEX        = 64U,
    MCU_IPC_ACMP0_INDEX       = 67U,
    MCU_IPC_PTU0_INDEX        = 70U,
    MCU_IPC_TMU_INDEX         = 72U,
    MCU_IPC_ETMR0_INDEX       = 73U,
    MCU_IPC_ETMR1_INDEX       = 74U,
    MCU_IPC_ETMR2_INDEX       = 75U,
    MCU_IPC_ETMR3_INDEX       = 76U,
    MCU_IPC_TMR0_INDEX        = 84U,
    MCU_IPC_PTMR0_INDEX       = 90U,
    MCU_IPC_LPTMR0_INDEX      = 93U,
    MCU_IPC_RTC_INDEX         = 96U,
    MCU_IPC_WKU_INDEX         = 98U,
    MCU_IPC_CRC_INDEX         = 101U,
    MCU_IPC_TRNG_INDEX        = 102U,
    MCU_IPC_HCU_INDEX         = 103U,
    MCU_IPC_WDG_INDEX         = 106U,
    MCU_IPC_EWDG_INDEX        = 107U,
    MCU_IPC_EMU_INDEX         = 114U,
    MCU_IPC_CIM_INDEX         = 123U,
    MCU_IPC_SCU_INDEX         = 124U,
    MCU_IPC_PCU_INDEX         = 126U,
    MCU_IPC_RCU_INDEX         = 127U,
    MCU_IPC_INVALID_INDEX     = 128U,
} Mcu_PeripheralIndexType;


#endif /* #ifndef MCU_CFG_H */

