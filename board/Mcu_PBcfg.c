/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Mcu_PBcfg.c
 * @brief 
 * 
 */



#include "Mcu.h"
#if (MCU_ENABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
#include "Dem.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_VENDOR_ID_PBCFG_C                      (180)
#define MCU_AR_RELEASE_MAJOR_VERSION_PBCFG_C       (4)
#define MCU_AR_RELEASE_MINOR_VERSION_PBCFG_C       (4)
#define MCU_AR_RELEASE_REVISION_VERSION_PBCFG_C    (0)
#define MCU_SW_MAJOR_VERSION_PBCFG_C               (2)
#define MCU_SW_MINOR_VERSION_PBCFG_C               (3)
#define MCU_SW_PATCH_VERSION_PBCFG_C               (0)

/*================================================================================================== */


#if (MCU_ENABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
/* Check if Mcu_Cfg.c file and Dem.h file are of the same Autosar version */
#if ((MCU_AR_RELEASE_MAJOR_VERSION_PBCFG_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_AR_RELEASE_MINOR_VERSION_PBCFG_C != DEM_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Mcu_PBcfg.c and Dem.h are different"
#endif

#endif



#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

MCU_CONST const Mcu_SircConfigType Mcu_RootSircConfig[1] = {
    {
        .SircClockRefPointFrequency = 12000000U,
        .SircDeepSleepEnable = (boolean)STD_OFF,
        .SircPowerDownEnable = (boolean)STD_OFF,
        .SircStandbyEnable = (boolean)STD_OFF,
    },
};

MCU_CONST const Mcu_FircConfigType Mcu_RootFircConfig[1] = {
    {
        .FircClockRefPointFrequency = 96000000U,
        .FircDeepSleepEnable = (boolean)STD_OFF,
    },
};

MCU_CONST const Mcu_FxoscConfigType Mcu_RootFxoscConfig[1] = {
    {
        .ClockRefPointFrequency = 16000000U,
        .BypassMode = (boolean)STD_OFF,
        .GainSelection = 5U,
        .DeepSleepEnable = (boolean)STD_OFF,
    },
};

#if MCU_NO_PLL == STD_OFF
MCU_CONST const Mcu_PllConfigType Mcu_RootPllConfig[1] = {
    {
        .ClockRef = MCU_PLL_CLOCK_REFERENCE_FXOSC,
        .RefDiv = 0U,
        .FeedbackDiv = 14U,
    },
};
#endif /* #if MCU_NO_PLL == STD_OFF */


MCU_CONST const Mcu_ClockOutConfigType Mcu_RootClockOutConfig[1] = {
    {
        .Source = MCU_CLOCK_OUT_SOURCE_FIRC,
        .ClockOutDiv = 2U,
    },
};



MCU_CONST const Mcu_IpcConfigType Mcu_RootIpcConfig_0[45] = {
    {
        .PeripheralIndex = MCU_IPC_DMA_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_TRACE_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_EFM_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_GPIO_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_SIRC,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_PCTRLA_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_PCTRLB_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_PCTRLC_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_PCTRLD_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_PCTRLE_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_LINFLEXD0_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_PLL,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_LINFLEXD1_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_PLL,
        .ClockDiv = 2U,
    },
    {
        .PeripheralIndex = MCU_IPC_LINFLEXD2_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_SENT0_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_I2C0_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_I2C1_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_SPI0_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_SPI1_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_SPI2_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_PLL,
        .ClockDiv = 2U,
    },
    {
        .PeripheralIndex = MCU_IPC_SPI3_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_FLEXCAN0_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_FLEXCAN1_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_FLEXCAN2_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_ADC0_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_SIRC,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_ACMP0_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_PTU0_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_TMU_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_ETMR0_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_ETMR1_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_ETMR2_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_ETMR3_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_TMR0_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_PTMR0_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_LPTMR0_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_PLL,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_RTC_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_WKU_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_CRC_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_TRNG_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_HCU_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_WDG_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_EWDG_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_EMU_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_CIM_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_SCU_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_PCU_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_RCU_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
};

MCU_CONST const Mcu_PeripheralClockConfigType Mcu_RootPeripheralClockConfig[1] = {
    {
        .IpcCount = 45U,
        .IpcConfig = (Mcu_IpcConfigType *)&Mcu_RootIpcConfig_0[0],
    },
};



MCU_CONST const Mcu_ClockConfigType Mcu_RootClockConfig[1] = {
    [0] = {
        .SystemClockSource = MCU_SYSTEM_CLOCK_SOURCE_PLL,
        .CoreClockDiv = 0U,
        .FastBusClockDiv = 0U,
        .SlowBusClockDiv = 2U,
        .EfmPrescaleValue = 60U,
        .EfmWRSValue = 2U,

        .SircUnderUserCtrl = (boolean)STD_ON,
        .SircConfig = &Mcu_RootSircConfig[0],

        .FircUnderUserCtrl = (boolean)STD_ON,
        .FircEnable = (boolean)STD_ON,
        .FircConfig = &Mcu_RootFircConfig[0],

        .FxoscUnderUserCtrl = (boolean)STD_ON,
        .FxoscEnable = (boolean)STD_ON,
        .FxoscConfig = &Mcu_RootFxoscConfig[0],
#if (MCU_NO_PLL == STD_OFF)
        .PllUnderUserCtrl = (boolean)STD_ON,
        .PllEnable = (boolean)STD_ON,
        .PllConfig = (Mcu_PllConfigType *)&Mcu_RootPllConfig[0],
#endif
        .ClockOutEnable = (boolean)STD_OFF,
        .ClockOutConfig = &Mcu_RootClockOutConfig[0],

        .ClockMonitorConfig = NULL_PTR,
        .ClockMonitorConfigNums = 0,

        .PeripheralClockConfig = &Mcu_RootPeripheralClockConfig[0],
    },
};

MCU_CONST const Mcu_ResetConfigType Mcu_RootResetConfig={
    .HwResetPinOutputEnable = STD_OFF,
    .HwResetPinFilterEnable = STD_OFF,
    .HwResetPinFilterCount = 0U,
};

MCU_CONST const Mcu_PcuHvdConfigType Mcu_PcuHvdConfig = {
    .ResetEnable = STD_OFF,
    .HVD11IntEnable = STD_OFF,
    .HVD11NotificationPtr = NULL_PTR,

    .HVD25IntEnable = STD_OFF,
    .HVD25NotificationPtr = NULL_PTR,

    .HVD50IntEnable = STD_OFF,
    .HVD50NotificationPtr = NULL_PTR,

};

MCU_CONST const Mcu_PcuConfigType Mcu_PcuConfig = {
    .HvdConfigPtr = &Mcu_PcuHvdConfig,
    .FastRecoveryEnable = STD_OFF,
    .PadKeepEnable = STD_OFF
};
MCU_CONST const Mcu_PowerModeType PowerModeMap[1]={
    MCU_POWER_MODE_RUN,
};


MCU_CONST const Mcu_PowerConfigType McuPowerConfig = {
    .ModeMap = PowerModeMap
};

MCU_CONST const Mcu_ConfigType Mcu_Config = {
    .ClockConfig = Mcu_RootClockConfig,
    .ClockConfigNum = (1U),
    .RamSectionConfig = NULL_PTR,
    .ResetConfig = &Mcu_RootResetConfig,
    .RamSectionConfigNum = 0U,
    .ModeConfigNum = 1U,
    .PowerConfig = &McuPowerConfig,
    .PcuConfig = &Mcu_PcuConfig,
};


#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

