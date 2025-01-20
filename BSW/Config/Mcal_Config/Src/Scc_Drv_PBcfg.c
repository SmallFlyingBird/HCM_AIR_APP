/**************************************************************************************************/
/**
 * @file      : Scc_Drv_PBcfg.c
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

/** @addtogroup Scc_Drv_Configuration
 *  @brief SCC driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Scc_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */

#define SCC_DRV_PBCFG_C_VENDOR_ID                   0x00B3U
#define SCC_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define SCC_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define SCC_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define SCC_DRV_PBCFG_C_SW_MAJOR_VERSION            1U
#define SCC_DRV_PBCFG_C_SW_MINOR_VERSION            2U
#define SCC_DRV_PBCFG_C_SW_PATCH_VERSION            2U


/* Check if current file and Scc_Drv.h file are of the same vendor */
#if (SCC_DRV_PBCFG_C_VENDOR_ID != SCC_DRV_H_VENDOR_ID)
    #error "Vendor ID of Scc_Drv_PBcfg.c and Scc_Drv.h are different"
#endif

/* Check if current file and Scc_Drv.h file are of the same Autosar version */
#if ((SCC_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    != SCC_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (SCC_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    != SCC_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (SCC_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION != SCC_DRV_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version of Scc_Drv_PBcfg.c and Scc_Drv.h are different"
#endif

/* Check if current file and Scc_Drv.h file are of the same Software version */
#if ((SCC_DRV_PBCFG_C_SW_MAJOR_VERSION != SCC_DRV_H_SW_MAJOR_VERSION) || \
     (SCC_DRV_PBCFG_C_SW_MINOR_VERSION != SCC_DRV_H_SW_MINOR_VERSION) || \
     (SCC_DRV_PBCFG_C_SW_PATCH_VERSION != SCC_DRV_H_SW_PATCH_VERSION) \
    )
  #error "Software Version of Scc_Drv_PBcfg.c and Scc_Drv.h are different"
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

const Scc_Drv_ClockConfigType Scc_Drv_ClockConfig[1U] =
{
    {
        /* System clock config */
        {
            /* System clock source config */
            SCC_DRV_SYS_CLOCK_PLL,
            
            /* System clock source frequency */
            (uint32)1.6E8,
            
            /* Core clock divider, from system clock */
            (Scc_Drv_SysClockDividerType)0U,
            
            /* Bus clock divider, from core clock */
            (Scc_Drv_SysClockDividerType)1U,
            
            /* Slow(flash) clock divider, from core clock */
            (Scc_Drv_SysClockDividerType)3U,
        },
        
        /* FIRC clock config */
        {
            /* Enable/Disable FIRC in stop mode. */
            0U,
            
            /* Enable/Disable FIRC clock */
            1U,
            
            /* Loss of FIRC clock callback function */
            NULL_PTR
        },
        
        /* Fast OSC clock config */
        {
            /* Low/High Frequency Mode. */
            (Scc_Drv_FOscFreqModeType)1U,
            
            /*!< Current trim */
            (uint32)1U,
            
            /* Enable/Disable fast OSC clock in stop mode. */
            0U,
            
            /* Mode:internal/external */
            SCC_DRV_OSC_XTAL,
            
            /* Fast OSC clock enabled */
            1U,
            
            /* Loss of FOSC clock callback function */
            NULL_PTR
        },
        
        /* PLL clock config */
        {
            /* PLL configuration */
            {
                /* PLL pre-divider */
                (Scc_Drv_PllPreDivType)1U,
                
                /* PLL post-divider */
                (Scc_Drv_PllPostDivType)3U,
                
                /* PLL multiplier */
                (uint32)80U,
                
                /* PLL reference clock */
                SCC_DRV_PLL_REF_FOSC,
                
                /* PLL pre-scaler */
                (Scc_Drv_PllPreScalerType)0U,
                
                /* PLL frequency */
                (uint32)1.6E8
            },
            
            /* Enable/Disable PLL in stop mode. */
            0U,
            
            /* PLL clock enable */
            1U,
        },
        
        /* Slow OSC clock config */
        {
            /* Mode:internal/external */
            SCC_DRV_OSC_XTAL,
            
            /* Slow OSC clock enabled */
            0U,
        },
        
    },
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

/** @} end of group Scc_Drv_Configuration */

/** @} end of group Mcu_Module */
