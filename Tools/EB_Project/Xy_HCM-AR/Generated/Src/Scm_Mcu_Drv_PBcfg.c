/**************************************************************************************************/
/**
 * @file      : Scm_Drv_PBcfg.c
 * @brief     : AUTOSAR Mcu - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup Mcu_Module
 *  @{
 */

/** @addtogroup Scm_Mcu_Drv_Configuration
 *  @brief SCM driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Scm_Mcu_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

#define SCM_MCU_DRV_PBCFG_C_VENDOR_ID                   0x00B3U
#define SCM_MCU_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define SCM_MCU_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define SCM_MCU_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define SCM_MCU_DRV_PBCFG_C_SW_MAJOR_VERSION            1U
#define SCM_MCU_DRV_PBCFG_C_SW_MINOR_VERSION            2U
#define SCM_MCU_DRV_PBCFG_C_SW_PATCH_VERSION            2U


/* Check if current file and Scm_Mcu_Drv.h file are of the same vendor */
#if (SCM_MCU_DRV_PBCFG_C_VENDOR_ID != SCM_MCU_DRV_H_VENDOR_ID)
    #error "Vendor ID of Scm_Drv_PBcfg.c and Scm_Mcu_Drv.h are different"
#endif

/* Check if current file and Scm_Mcu_Drv.h file are of the same Autosar version */
#if ((SCM_MCU_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != SCM_MCU_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (SCM_MCU_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    != SCM_MCU_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (SCM_MCU_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION != SCM_MCU_DRV_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version of Scm_Drv_PBcfg.c and Scm_Mcu_Drv.h are different"
#endif

/* Check if current file and Scm_Mcu_Drv.h file are of the same Software version */
#if ((SCM_MCU_DRV_PBCFG_C_SW_MAJOR_VERSION != SCM_MCU_DRV_H_SW_MAJOR_VERSION) || \
     (SCM_MCU_DRV_PBCFG_C_SW_MINOR_VERSION != SCM_MCU_DRV_H_SW_MINOR_VERSION) || \
     (SCM_MCU_DRV_PBCFG_C_SW_PATCH_VERSION != SCM_MCU_DRV_H_SW_PATCH_VERSION) \
    )
  #error "Software Version of Scm_Drv_PBcfg.c and Scm_Mcu_Drv.h are different"
#endif

/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */


/** @defgroup Global_VariableDefinition
 *  @{
 */

#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

const Scm_Mcu_Drv_ClockConfigType Scm_Mcu_Drv_ClockConfig[1U] =
{
    {
        {
            /* Clock output source */
            SCM_MCU_DRV_CLOCK_OUT_FIRC64M,
            
            /* Clock output divider */
            (Scm_Mcu_Drv_ClockOutDivType)0U,
            
            /* Clock output enable/disable */
            1U,
        },
    },
};


/* SCM configuration*/
const Scm_Mcu_Drv_ConfigType Scm_Mcu_Drv_Config = 
{
    /* Cache bit error interrupt enable */
    0U,

    /* FPU inexat interrupt enable */
    0U,

    /* FPU overflow interrupt enable */
    0U,

    /* FPU underflow interrupt enable */
    0U,

    /* FPU invalidop interrupt enable */
    0U,

    /* FPU divzero interrupt enable */
    0U,

    /* FPU denormal interrupt enable */
    0U,

    /* Cache enable */
    0U,

    /* Cache parity fault enable */
    0U,

    /* Cache parity miss enable */
    0U,

    /* MCPWM0 external input clock select */
    SCM_MCU_DRV_TCLK0,
    
    /* MCPWM1 external input clock select */
    SCM_MCU_DRV_TCLK0,

    /* TIM0 external input clock select */
    SCM_MCU_DRV_TCLK0,

    /* TIM1 external input clock select */
    SCM_MCU_DRV_TCLK0,

    /* TIM2 external input clock select */
    SCM_MCU_DRV_TCLK0,

    /* TIM3 external input clock select */
    SCM_MCU_DRV_TCLK0,

    /* ADC0 channel 8 mux select */
    SCM_MCU_DRV_ADCMUX1,

    /* ADC0 channel 9 mux select */
    SCM_MCU_DRV_ADCMUX1,

    /* ADC1 channel 14 mux select */
    SCM_MCU_DRV_ADCMUX0,

    /* ADC1 channel 15 mux select */
    SCM_MCU_DRV_ADCMUX0
};

#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

/** @} end of group Global_VariableDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

/** @} end of group Private_VariableDefinition */

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

/** @} end of group Scm_Mcu_Drv_Configuration */

/** @} end of group Mcu_Module */
