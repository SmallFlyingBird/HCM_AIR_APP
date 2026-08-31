/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Pwm_Lld_Etmr_PBcfg.c
 * @brief 
 * 
 */


#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Pwm_Lld_Etmr_PBcfg.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_LLD_ETMR_VENDOR_ID_PBCFG_C                      (180)
#define PWM_LLD_ETMR_AR_RELEASE_MAJOR_VERSION_PBCFG_C       (4)
#define PWM_LLD_ETMR_AR_RELEASE_MINOR_VERSION_PBCFG_C       (4)
#define PWM_LLD_ETMR_AR_RELEASE_REVISION_VERSION_PBCFG_C    (0)
#define PWM_LLD_ETMR_SW_MAJOR_VERSION_PBCFG_C               (2)
#define PWM_LLD_ETMR_SW_MINOR_VERSION_PBCFG_C               (3)
#define PWM_LLD_ETMR_SW_PATCH_VERSION_PBCFG_C               (0)

/*==================================================================================================
 *                                         GLOBAL CONSTANTS                                         
==================================================================================================*/
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"
                        

/*================================================================================================*/
/* Instance configuration structure PwmEtmr_0 */
PWM_CONST const Pwm_Lld_Etmr_InstCfgType Pwm_Lld_Etmr_InstCfg_Inst0 = 
{
    .DebugModeEnable = TRUE,
    .OvfIrqEn = FALSE,
    .ModTrgEn = FALSE,
    .MidTrgEn = FALSE,
    .InitTrgEn = FALSE,
    .Period = 10909U,
    .ClockPrescaler = 10U,
    .OutTrgWidth = 0,
    .OutTrgFreq = 0U,
    .PulseSrc = PWM_LLD_ETMR_OUTPULSESRC_CH0,
    .ClockSource = PWM_LLD_ETMR_CLKSRC_BUS,
    .ExClockSource = PWM_LLD_ETMR_EXCLKSRC_TCLK_IN0,
    .OutTrgSrc = PWM_LLD_ETMR_OUTTRGSRC_MATCH,
    .OvfCallback = NULL_PTR
};

/* Channel configuration PwmEtmr0Ch_7 */
PWM_CONST const Pwm_Lld_Etmr_ChCfgType Pwm_Lld_Etmr_ChCfg_Inst0_Ch7 = 
{
    .Val0TrgEn = FALSE,
    .Val1TrgEn = FALSE,
    .ChannelId = 7U,
    .DutyCycle = 0U,
    .DeadTime = 0U,
    .AlignMode = PWM_LLD_ETMR_ALIGN_MODE_LEFT_EDGE,
    .Polarity = PWM_LLD_ETMR_POLARITY_INVERT,
    .IdleState = PWM_LLD_ETMR_OUTPUT_STATE_LOW,
    .ChMode = PWM_LLD_ETMR_MODE_INDEPENDENT
};

PWM_CONST static const Pwm_Lld_Etmr_ChCfgType * const Pwm_Lld_Etmr_ChCfgArr_Inst0[1U] = 
{
    &Pwm_Lld_Etmr_ChCfg_Inst0_Ch7,
};

/* User configuration structure PwmEtmr_0 */
PWM_CONST const Pwm_Lld_Etmr_CfgType Pwm_Lld_Etmr_Cfg_Inst0 = 
{
    .ChannelCount = 1U,
    .InstCfg = &Pwm_Lld_Etmr_InstCfg_Inst0,
    .ChCfgArr = Pwm_Lld_Etmr_ChCfgArr_Inst0
};

/*================================================================================================*/
/* Instance configuration structure PwmEtmr_1 */
PWM_CONST const Pwm_Lld_Etmr_InstCfgType Pwm_Lld_Etmr_InstCfg_Inst1 = 
{
    .DebugModeEnable = TRUE,
    .OvfIrqEn = FALSE,
    .ModTrgEn = FALSE,
    .MidTrgEn = FALSE,
    .InitTrgEn = FALSE,
    .Period = 10000U,
    .ClockPrescaler = 11U,
    .OutTrgWidth = 0,
    .OutTrgFreq = 0U,
    .PulseSrc = PWM_LLD_ETMR_OUTPULSESRC_CH0,
    .ClockSource = PWM_LLD_ETMR_CLKSRC_BUS,
    .ExClockSource = PWM_LLD_ETMR_EXCLKSRC_TCLK_IN0,
    .OutTrgSrc = PWM_LLD_ETMR_OUTTRGSRC_MATCH,
    .OvfCallback = NULL_PTR
};

/* Channel configuration PwmEtmr1Ch_0 */
PWM_CONST const Pwm_Lld_Etmr_ChCfgType Pwm_Lld_Etmr_ChCfg_Inst1_Ch0 = 
{
    .Val0TrgEn = FALSE,
    .Val1TrgEn = FALSE,
    .ChannelId = 0U,
    .DutyCycle = 0U,
    .DeadTime = 0U,
    .AlignMode = PWM_LLD_ETMR_ALIGN_MODE_LEFT_EDGE,
    .Polarity = PWM_LLD_ETMR_POLARITY_INVERT,
    .IdleState = PWM_LLD_ETMR_OUTPUT_STATE_LOW,
    .ChMode = PWM_LLD_ETMR_MODE_INDEPENDENT
};
/* Channel configuration PwmEtmr1Ch_7 */
PWM_CONST const Pwm_Lld_Etmr_ChCfgType Pwm_Lld_Etmr_ChCfg_Inst1_Ch7 = 
{
    .Val0TrgEn = FALSE,
    .Val1TrgEn = FALSE,
    .ChannelId = 7U,
    .DutyCycle = 0U,
    .DeadTime = 0U,
    .AlignMode = PWM_LLD_ETMR_ALIGN_MODE_LEFT_EDGE,
    .Polarity = PWM_LLD_ETMR_POLARITY_NOT_INVERT,
    .IdleState = PWM_LLD_ETMR_OUTPUT_STATE_LOW,
    .ChMode = PWM_LLD_ETMR_MODE_INDEPENDENT
};

PWM_CONST static const Pwm_Lld_Etmr_ChCfgType * const Pwm_Lld_Etmr_ChCfgArr_Inst1[2U] = 
{
    &Pwm_Lld_Etmr_ChCfg_Inst1_Ch0,
    &Pwm_Lld_Etmr_ChCfg_Inst1_Ch7,
};

/* User configuration structure PwmEtmr_1 */
PWM_CONST const Pwm_Lld_Etmr_CfgType Pwm_Lld_Etmr_Cfg_Inst1 = 
{
    .ChannelCount = 2U,
    .InstCfg = &Pwm_Lld_Etmr_InstCfg_Inst1,
    .ChCfgArr = Pwm_Lld_Etmr_ChCfgArr_Inst1
};

#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

