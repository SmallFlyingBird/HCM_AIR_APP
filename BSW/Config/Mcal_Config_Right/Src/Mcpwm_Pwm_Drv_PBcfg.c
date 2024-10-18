/*************************************************************************************/
/**
 * @file      : Mcpwm_Pwm_Drv_PBcfg.c  
 * @brief     : Pwm low level driver - Post-Build(PB) configuration file code template 
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 *************************************************************************************/
/** @addtogroup  Pwm_Module
 *  @{
 */

/** @addtogroup Mcpwm_Pwm_Drv_Configuration
 *  @brief Pwm low level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Mcpwm_Pwm_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define MCPWM_PWM_DRV_PBCFG_C_VENDOR_ID                   0x00B3U
#define MCPWM_PWM_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define MCPWM_PWM_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define MCPWM_PWM_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define MCPWM_PWM_DRV_PBCFG_C_SW_MAJOR_VERSION            1U
#define MCPWM_PWM_DRV_PBCFG_C_SW_MINOR_VERSION            2U
#define MCPWM_PWM_DRV_PBCFG_C_SW_PATCH_VERSION            1U

/* Check if source file and Mcpwm_Pwm_Drv.h header file are of the same vendor */
#if (MCPWM_PWM_DRV_PBCFG_C_VENDOR_ID != MCPWM_PWM_DRV_H_VENDOR_ID)
    #error "Vendor IDs of Mcpwm_Pwm_Drv_PBcfg.c and Mcpwm_Pwm_Drv.h are different."
#endif

/* Check if source file and Mcpwm_Pwm_Drv.h header file are of the same AUTOSAR version */
#if ((MCPWM_PWM_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != MCPWM_PWM_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (MCPWM_PWM_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    != MCPWM_PWM_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (MCPWM_PWM_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION != MCPWM_PWM_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Mcpwm_Pwm_Drv_PBcfg.c and Mcpwm_Pwm_Drv.h are different."
#endif

/* Check if source file and Mcpwm_Pwm_Drv.h header file are of the same software version */
#if ((MCPWM_PWM_DRV_PBCFG_C_SW_MAJOR_VERSION != MCPWM_PWM_DRV_H_SW_MAJOR_VERSION) || \
     (MCPWM_PWM_DRV_PBCFG_C_SW_MINOR_VERSION != MCPWM_PWM_DRV_H_SW_MINOR_VERSION) || \
     (MCPWM_PWM_DRV_PBCFG_C_SW_PATCH_VERSION != MCPWM_PWM_DRV_H_SW_PATCH_VERSION))
    #error "Software version numbers of Mcpwm_Pwm_Drv_PBcfg.c and Mcpwm_Pwm_Drv.h are different."
#endif

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

extern void ALS_PWM_Notification(void);
extern void AFS_PWM_Notification(void);

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

/** @} end of group Private_VariableDefinition */

/** @defgroup Global_VariableDefinition
 *  @{
 */

#ifndef MCPWM_PWM_IP_PRECOMPILE_SUPPORT
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

static const Mcpwm_Pwm_Drv_CounterType Pwm_Drv_I0_Counter0_Cfg =
{
    .CntId = 0U,
    .PwmPeriod = 20000U,
    .PwmPeriodDither = 0U,
    .DeadTimeVal = 1U,
    .OverflowIrqEn = (boolean)TRUE,
    .OverflowCb = NULL_PTR
}; 
static const Mcpwm_Pwm_Drv_CounterType Pwm_Drv_I0_Counter1_Cfg =
{
    .CntId = 1U,
    .PwmPeriod = 20000U,
    .PwmPeriodDither = 0U,
    .DeadTimeVal = 1U,
    .OverflowIrqEn = (boolean)TRUE,
    .OverflowCb = NULL_PTR
}; 
static const Mcpwm_Pwm_Drv_CounterType Pwm_Drv_I0_Counter2_Cfg =
{
    .CntId = 2U,
    .PwmPeriod = 20000U,
    .PwmPeriodDither = 0U,
    .DeadTimeVal = 1U,
    .OverflowIrqEn = (boolean)TRUE,
    .OverflowCb = NULL_PTR
}; 
static const Mcpwm_Pwm_Drv_CounterType Pwm_Drv_I0_Counter3_Cfg =
{
    .CntId = 3U,
    .PwmPeriod = 20000U,
    .PwmPeriodDither = 0U,
    .DeadTimeVal = 1U,
    .OverflowIrqEn = (boolean)TRUE,
    .OverflowCb = NULL_PTR
}; 
static const Mcpwm_Pwm_Drv_CounterType Pwm_Drv_I1_Counter0_Cfg =
{
    .CntId = 0U,
    .PwmPeriod = 2000U,
    .PwmPeriodDither = 0U,
    .DeadTimeVal = 1U,
    .OverflowIrqEn = (boolean)TRUE,
    .OverflowCb = NULL_PTR
}; 
static const Mcpwm_Pwm_Drv_CounterType Pwm_Drv_I1_Counter1_Cfg =
{
    .CntId = 1U,
    .PwmPeriod = 2000U,
    .PwmPeriodDither = 0U,
    .DeadTimeVal = 1U,
    .OverflowIrqEn = (boolean)TRUE,
    .OverflowCb = NULL_PTR
}; 
static const Mcpwm_Pwm_Drv_CounterType Pwm_Drv_I1_Counter2_Cfg =
{
    .CntId = 2U,
    .PwmPeriod = 2000U,
    .PwmPeriodDither = 0U,
    .DeadTimeVal = 1U,
    .OverflowIrqEn = (boolean)TRUE,
    .OverflowCb = NULL_PTR
}; 
static const Mcpwm_Pwm_Drv_CounterType Pwm_Drv_I1_Counter3_Cfg =
{
    .CntId = 3U,
    .PwmPeriod = 2000U,
    .PwmPeriodDither = 0U,
    .DeadTimeVal = 1U,
    .OverflowIrqEn = (boolean)TRUE,
    .OverflowCb = NULL_PTR
}; 

static const Mcpwm_Pwm_Drv_CounterType* const Pwm_Drv_I0_CounterArrayPtr[4U] =
{
    &Pwm_Drv_I0_Counter0_Cfg,
    &Pwm_Drv_I0_Counter1_Cfg,
    &Pwm_Drv_I0_Counter2_Cfg,
    &Pwm_Drv_I0_Counter3_Cfg
};
static const Mcpwm_Pwm_Drv_CounterType* const Pwm_Drv_I1_CounterArrayPtr[4U] =
{
    &Pwm_Drv_I1_Counter0_Cfg,
    &Pwm_Drv_I1_Counter1_Cfg,
    &Pwm_Drv_I1_Counter2_Cfg,
    &Pwm_Drv_I1_Counter3_Cfg
};

static const Mcpwm_Pwm_Drv_ConfigType Pwm_Drv_Inst0_Cfg =
{
    .ClkSrc = MCPWM_PWM_DRV_CLK_SOURCE_FUNCTION,
    .ClkDiv = MCPWM_PWM_DRV_CLK_DIVIDE_2,
    .GlobalCntEn = (boolean)FALSE,
    .InitTrigEn = (boolean)FALSE,
    .CounterNum = 4U,
    .CounterConfig = Pwm_Drv_I0_CounterArrayPtr,
};
static const Mcpwm_Pwm_Drv_ConfigType Pwm_Drv_Inst1_Cfg =
{
    .ClkSrc = MCPWM_PWM_DRV_CLK_SOURCE_FUNCTION,
    .ClkDiv = MCPWM_PWM_DRV_CLK_DIVIDE_2,
    .GlobalCntEn = (boolean)FALSE,
    .InitTrigEn = (boolean)FALSE,
    .CounterNum = 4U,
    .CounterConfig = Pwm_Drv_I1_CounterArrayPtr,
};


const Mcpwm_Pwm_Drv_ChannelConfigType Mcpwm_Pwm_Drv_I0_Ch0_Cfg =
{
    .ChannelId = 0U,
    .ChIrqEn = (boolean)TRUE,
    .ChannelCb = NULL_PTR,
    .ChannelOutputEnable = (boolean)TRUE,
    .Polarity = MCPWM_PWM_DRV_POL_HIGH,
    .ChannelMode = MCPWM_PWM_DRV_MODE_EDGE_ALIGNED,
    .ChannelDither = 0U,
    .ChannelMatchTrigEnable = (boolean)TRUE,
    .DmaEn = (boolean)FALSE,
    .PairCfg = NULL_PTR
};
const Mcpwm_Pwm_Drv_ChannelConfigType Mcpwm_Pwm_Drv_I0_Ch2_Cfg =
{
    .ChannelId = 2U,
    .ChIrqEn = (boolean)TRUE,
    .ChannelCb = NULL_PTR,
    .ChannelOutputEnable = (boolean)TRUE,
    .Polarity = MCPWM_PWM_DRV_POL_HIGH,
    .ChannelMode = MCPWM_PWM_DRV_MODE_EDGE_ALIGNED,
    .ChannelDither = 0U,
    .ChannelMatchTrigEnable = (boolean)TRUE,
    .DmaEn = (boolean)FALSE,
    .PairCfg = NULL_PTR
};
const Mcpwm_Pwm_Drv_ChannelConfigType Mcpwm_Pwm_Drv_I1_Ch0_Cfg =
{
    .ChannelId = 0U,
    .ChIrqEn = (boolean)TRUE,
    .ChannelCb = ALS_PWM_Notification,
    .ChannelOutputEnable = (boolean)TRUE,
    .Polarity = MCPWM_PWM_DRV_POL_HIGH,
    .ChannelMode = MCPWM_PWM_DRV_MODE_EDGE_ALIGNED,
    .ChannelDither = 0U,
    .ChannelMatchTrigEnable = (boolean)TRUE,
    .DmaEn = (boolean)FALSE,
    .PairCfg = NULL_PTR
};
const Mcpwm_Pwm_Drv_ChannelConfigType Mcpwm_Pwm_Drv_I1_Ch6_Cfg =
{
    .ChannelId = 6U,
    .ChIrqEn = (boolean)TRUE,
    .ChannelCb = AFS_PWM_Notification,
    .ChannelOutputEnable = (boolean)TRUE,
    .Polarity = MCPWM_PWM_DRV_POL_HIGH,
    .ChannelMode = MCPWM_PWM_DRV_MODE_EDGE_ALIGNED,
    .ChannelDither = 0U,
    .ChannelMatchTrigEnable = (boolean)TRUE,
    .DmaEn = (boolean)FALSE,
    .PairCfg = NULL_PTR
};

static const Mcpwm_Pwm_Drv_ChannelConfigType * const Pwm_Drv_I0_ChArrayPtr[2U] =
{
    &Mcpwm_Pwm_Drv_I0_Ch0_Cfg,
    &Mcpwm_Pwm_Drv_I0_Ch2_Cfg
};
static const Mcpwm_Pwm_Drv_ChannelConfigType * const Pwm_Drv_I1_ChArrayPtr[2U] =
{
    &Mcpwm_Pwm_Drv_I1_Ch0_Cfg,
    &Mcpwm_Pwm_Drv_I1_Ch6_Cfg
};

const Mcpwm_Pwm_Drv_UserCfgType Mcpwm_Pwm_Drv_User0_Cfg =
{
    .InstanceCfg = &Pwm_Drv_Inst0_Cfg,
    .ConfiguredChArray = Pwm_Drv_I0_ChArrayPtr,
    .NoOfConfiguredCh = 2U
};
const Mcpwm_Pwm_Drv_UserCfgType Mcpwm_Pwm_Drv_User1_Cfg =
{
    .InstanceCfg = &Pwm_Drv_Inst1_Cfg,
    .ConfiguredChArray = Pwm_Drv_I1_ChArrayPtr,
    .NoOfConfiguredCh = 2U
};


#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

#endif  /*MCPWM_PWM_DRV_PRECOMPILE_SUPPORT */

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_FunctionDeclaration
 *  @{
 */

/** @} end of group Private_FunctionDeclaration */

/** @defgroup Private_FunctionDefinition
 *  @{
 */

/** @} end of group Private_FunctionDefinition */

/** @defgroup Public_FunctionDefinition
 *  @{
 */

/** @} end of group Public_FunctionDefinition */

#ifdef __cplusplus
}
#endif

/** @} end of group Mcpwm_Pwm_Drv_Configuration */

/** @} end of group Pwm_Module */
