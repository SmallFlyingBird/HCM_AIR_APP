/**************************************************************************************************/
/**
 * @file      : Uart_Drv_Cfg.h  
 * @brief     : Uart low level driver - Pre-Compile(PC) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/


#ifndef UART_DRV_CFG_H
#define UART_DRV_CFG_H


/** @addtogroup  Lin_Module
 *  @{
 */

/** @addtogroup Lin_Configuration
 *  @brief Lin low level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "Uart_Drv_PBcfg.h"


/** @defgroup Public_MacroDefinition
 *  @{
 */
#define UART_DRV_CFG_H_VENDOR_ID                   0x00B3U
#define UART_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define UART_DRV_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define UART_DRV_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define UART_DRV_CFG_H_SW_MAJOR_VERSION            1U
#define UART_DRV_CFG_H_SW_MINOR_VERSION            2U
#define UART_DRV_CFG_H_SW_PATCH_VERSION            2U



/* Checks against Uart_Drv_PBcfg.h */
#if (UART_DRV_PBCFG_H_VENDOR_ID != UART_DRV_CFG_H_VENDOR_ID)
    #error "Vendor ID of Uart_Drv_PBcfg.h and Uart_Drv_Cfg.h are different"
#endif
    /* Check if Uart_Drv_PBcfg header file and Uart configuration header file are of the same Autosar version */
#if ((UART_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION     != UART_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (UART_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION     != UART_DRV_CFG_H_AR_RELEASE_MINOR_VERSION) || \
     (UART_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION  != UART_DRV_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Uart_Drv_PBcfg.h and Uart_Drv_Cfg.h are different"
#endif
/* Check if Uart_Drv__PBcfg header file and Uart configuration header file are of the same software version */
#if ((UART_DRV_PBCFG_H_SW_MAJOR_VERSION != UART_DRV_CFG_H_SW_MAJOR_VERSION) || \
     (UART_DRV_PBCFG_H_SW_MINOR_VERSION != UART_DRV_CFG_H_SW_MINOR_VERSION) || \
     (UART_DRV_PBCFG_H_SW_PATCH_VERSION != UART_DRV_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Uart_Drv_PBcfg.h and Uart_Drv_Cfg.h are different"
#endif


#define UART_DRV_CONFIG_EXT \
    UART_DRV_CONFIG_PB




/**
* @brief   Switches the Development Error Detection ON or OFF.
*
*/
#define UART_DRV_DEV_ERROR_DETECT               (STD_ON) /*!< Development error detection */

/**
* @brief   No. of Channels configured for Uart
*
* 
*/
#define UART_DRV_NUMBER_OF_INSTANCES_USED         (1U)


/**
* @brief          Define Uart timeout type
* 
*/
#define  UART_DRV_TIMEOUT_TYPE       (MCALLIB_COUNTER_SOFTWARE)

/**
* @brief   Number of loops before returning busy.
*
*/
#define UART_DRV_TIMEOUT_VALUE_US    (1000U)

/**
* @brief   Switches the UART software simulate LIN  ON or OFF.
*
*/
#define UART_DRV_SOFTWARE_SIMULATION               (STD_ON) 

/**
* @brief   Switches the UART software simulate LIN timeout ON or OFF.
*
*/
#define UART_DRV_SOFTWARE_SIMULATION_TIMEOUT               (STD_OFF) 


/**
* @brief  LIN polling ON or OFF.
*
*/
#define UART_DRV_SOFTWARE_POLLING               (STD_OFF) 

/**
* @brief          Lin config master node
*
*/
#define UART_DRV_MASTER_SUPPORT  (STD_OFF) /* not config to be master node */






/**
* @brief    Switches the LIN auto sync mode on or off 
*
*/
#define UART_DRV_AUTOSYNC_ENABLED  (STD_OFF) /* disable auto sync */

/**
* @brief    When hardware lin autosync enabled, it's recomend to turn on this. 
*
*/





/**
* @brief    When Simulation Lin start timeout enabled, it's recomend to turn on this. 
*
*/




/**
* @brief    When Simulation Lin stop timeout enabled, it's recomend to turn on this. 
*
*/





/**
*
* @brief          Lin Wakeup detection on/off 
*
*/
#define UART_DRV_WAKEUP_DETECTION (STD_ON) /* Support wakeup detection */

/**
* @brief   Total number of available hardware lin channels.
*
*/
#define UART_DRV_INSTANCE_NUM 6U

/** 
 * @brief Defines HW Units enanble or not.
 */
#define UART_DRV_0_ENABLE    (STD_OFF)
#define UART_DRV_1_ENABLE    (STD_OFF)
#define UART_DRV_2_ENABLE    (STD_OFF)
#define UART_DRV_3_ENABLE    (STD_ON)
#define UART_DRV_4_ENABLE    (STD_OFF)
#define UART_DRV_5_ENABLE    (STD_OFF)



/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define UART_DRV_EXT    UART_DRV_CONFIG
/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

#define UART_DRV_CALLBACK_EXT   UART_DRV_CALLBACK

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Uart_Drv_Configuration */

/** @} end of group Lin_Module */


#endif
