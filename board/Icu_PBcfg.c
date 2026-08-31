/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Icu_PBcfg.c
 * @brief 
 * 
 */


#include "Icu.h"
#include "Icu_Lld_Etmr.h"
#include "Icu_Lld_Port.h"
#include "Icu_Base.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_VENDOR_ID_PBCFG_C                      (180)
#define ICU_AR_RELEASE_MAJOR_VERSION_PBCFG_C       (4)
#define ICU_AR_RELEASE_MINOR_VERSION_PBCFG_C       (4)
#define ICU_AR_RELEASE_REVISION_VERSION_PBCFG_C    (0)
#define ICU_SW_MAJOR_VERSION_PBCFG_C               (2)
#define ICU_SW_MINOR_VERSION_PBCFG_C               (3)
#define ICU_SW_PATCH_VERSION_PBCFG_C               (0)

/*================================================================================================== */






#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

ICU_CONST const Icu_ChannelConfigType Icu_ChannelConfig[1] = 
{
    {
        .IcuChannelId = 0,
        .IcuHwIp = ICU_ETMR,
        .IcuHwIpInstance = ICU_ETMR0,
        .IcuHwChannel = 6,
        .IcuDefaultStartEdge = ICU_RISING_EDGE,
        .IcuWakeupCapability = FALSE,
#if (ICU_WAKEUP_FUNCTIONALITY_API == STD_ON)
        .IcuWakeupSource = (EcuM_WakeupSourceType)0,
#endif
        .IcuMeasurementMode = ICU_MODE_SIGNAL_MEASUREMENT,        
        .SignalMeasurementProperty = ICU_DUTY_CYCLE,
    },
};

 
ICU_CONST const IcuEtmrChannelType EtmrListChannels_0[1]=
{
    {         
        .ChannelNum = 6,
        },
};


ICU_CONST const Icu_EtmrConfigType Icu_EtmrConfig[1]=
{
    {
        .IcuEtmrModule = ICU_ETMR0,
        .IcuEtmrCount = 1,
        .IcuEtmrChannelPtr = (IcuEtmrChannelType*)EtmrListChannels_0,
        .IcuEtmrClockSource = ICU_MC_CLOCK_SOURCE_FASTBUSCLK,
        .IcuEtmrClockOthers = ICU_MC_CLOCK_OTHERS_EXTERNAL_IN0,
        .IcuEtmrPrescaler = 10,    
        .IcuEtmrModValue = 0,
    },    
};
/*
ICU_CONST const Icu_LptmrConfigType Icu_LptmrConfig[0]=
{

};
*/





ICU_CONST const Icu_HwInterruptConfigType Icu_HwInterruptConfig[1]=
{
    {         
        .IcuIsrHwId = ICU_ETMR_0_CH_6,
        .IcuIsrEnable = TRUE,     
    },
};
ICU_CONST const Icu_ConfigType Icu_Config = {
    .ChannelConfigPtr = (Icu_ChannelConfigType*)Icu_ChannelConfig,
    .IcuEtmrConfigPtr = (Icu_EtmrConfigType*) Icu_EtmrConfig,
    .IcuLptmrConfigPtr = (Icu_LptmrConfigType*)NULL_PTR,
    .IcuPortConfigPtr = (Icu_PortConfigType*) NULL_PTR,
    .IcuLpCmpConfigPtr = (Icu_LpCmpConfigType*) NULL_PTR,
    .IcuHwInterruptConfigPtr = (Icu_HwInterruptConfigType*)Icu_HwInterruptConfig,
#if WKU_SUPPORT == STD_ON
    .IcuWakeUpNotificationPtr = NULL_PTR,
#endif
    .IcuChannelCount = 1,
};
#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

