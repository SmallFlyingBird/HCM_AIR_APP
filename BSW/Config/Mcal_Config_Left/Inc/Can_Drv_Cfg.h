/**************************************************************************************************/
/**
 * @file      : Can_Drv_Cfg.h  
 * @brief     : Can low level driver - Pre-Compile(PC) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef CAN_DRV_CFG_H
#define CAN_DRV_CFG_H

/** @addtogroup Can_Module
 *  @{
 */

/** @addtogroup Can_Configuration
 *  @brief Can low level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif


#include "Can_Drv_PBcfg.h"
/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define CAN_DRV_CFG_H_VENDOR_ID                   0x00B3U
#define CAN_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define CAN_DRV_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define CAN_DRV_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define CAN_DRV_CFG_H_SW_MAJOR_VERSION            1U
#define CAN_DRV_CFG_H_SW_MINOR_VERSION            2U
#define CAN_DRV_CFG_H_SW_PATCH_VERSION            2U



 /* Check if current file and Can_Drv_PBcfg.h are of the same vendor */
#if (CAN_DRV_CFG_H_VENDOR_ID != CAN_DRV_PBCFG_H_VENDOR_ID)
    #error "Vendor ID of Can_Drv_Cfg.h and Can_Drv_PBcfg.h are different"
#endif
/* Check if current file and Can_Drv_PBcfg.h are of the same Autosar version */
#if ((CAN_DRV_CFG_H_AR_RELEASE_MAJOR_VERSION != CAN_DRV_PBCFG_H_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_DRV_CFG_H_AR_RELEASE_MINOR_VERSION != CAN_DRV_PBCFG_H_AR_RELEASE_MINOR_VERSION) || \
     (CAN_DRV_CFG_H_AR_RELEASE_REVISION_VERSION != CAN_DRV_PBCFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Can_Drv_Cfg.h and Can_Drv_PBcfg.h are different"
#endif
/* Check if current file and Can_Drv_PBcfg.h are of the same software version */
#if ((CAN_DRV_CFG_H_SW_MAJOR_VERSION != CAN_DRV_PBCFG_H_SW_MAJOR_VERSION) || \
    (CAN_DRV_CFG_H_SW_MINOR_VERSION != CAN_DRV_PBCFG_H_SW_MINOR_VERSION)|| \
    (CAN_DRV_CFG_H_SW_PATCH_VERSION != CAN_DRV_PBCFG_H_SW_PATCH_VERSION))
     #error "Software Version of Can_Drv_Cfg.h and Can_Drv_PBcfg.h are different"
#endif



#define CAN_DRV_CONFIG_EXT \
    CAN_DRV_PB_CFG


/**
 * @brief Total number of Can.
 */
#define CAN_DRV_TOTAL_NUM   (8U)

#define CAN_DRV_0_ENABLE    (STD_OFF)
#define CAN_DRV_1_ENABLE    (STD_OFF)
#define CAN_DRV_2_ENABLE    (STD_OFF)
#define CAN_DRV_3_ENABLE    (STD_OFF)
#define CAN_DRV_4_ENABLE    (STD_OFF)
#define CAN_DRV_5_ENABLE    (STD_OFF)
#define CAN_DRV_6_ENABLE    (STD_ON)
#define CAN_DRV_7_ENABLE    (STD_OFF)



/**
*   @brief      can drv abort configure
*/
#define CAN_DRV_ABORT_EN    (STD_ON)


/**
 *  @brief Enable Development Error Detection
 */
#define CAN_DRV_DEV_ERROR_DETECT    (STD_OFF)


/**
*   @brief     Time out value in uS
*/
#define CAN_DRV_TIMEOUT_DURATION    (1000000U)

/**
*   @brief     This this will set the timer source
*/
#define CAN_DRV_SERVICE_TIMEOUT_TYPE    (MCALLIB_COUNTER_SOFTWARE)


/**
*   @brief      Can Drv Rx/Tx common interrupt support
*/
#define CAN_DRV_MB_INTERRUPT_SUPPORT    (STD_ON)


/**
*   @brief      Can error interrupt support
*/
#define CAN_DRV_ERROR_INTERRUPT_SUPPORT    (STD_OFF)


/**
*   @brief      Can ecc interrupt support
*/
#define CAN_DRV_ECC_INTERRUPT_SUPPORT    (STD_OFF)


/**
*   @brief      Can error injection support
*/
#define CAN_DRV_ERROR_INJECTION_SUPPORT    (STD_OFF)



/**
 *  @brief Maximum number of Message Buffers supported for payload size 8 for any of the CAN instances
 */
#define CAN_DRV_MAX_MB_NUM    (128)

/**
 *  @brief Can mailbox number
 */
#define CAN_DRV_SUPPORT_MAX_MB_NUM    (128U)

/**
 *  @brief Defines the No Of Message Buffers partitions support MBDSR regions
 */
#define CAN_DRV_FEATURE_MBDSR_COUNT    (4U)


/**
 *  @brief Enable/Disable CAN RXFIFO Mode.
 */
#define CAN_DRV_RX_FIFO_ENABLE    (STD_OFF)


/**
 *  @brief Enable/Disable CAN FD mode
 */
#define CAN_DRV_FEATURE_HAS_FD    (STD_OFF)


#define CAN_DRV_FEATURE_HAS_DMA_ENABLE    (STD_OFF)

#define CAN_DRV_FD_CH6_ENABLE    (STD_OFF)


/**
 *  @brief Enable/Disable CAN FD mode
 */
#define CAN_DRV_FD_MODE_ENABLE    (STD_OFF)


/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */
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

/** @} end of group Can_Drv_Configuration */

/** @} end of group Can_Module */

#endif /* CAN_DRV_CFG_H */
