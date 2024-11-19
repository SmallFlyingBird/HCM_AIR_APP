/**************************************************************************************************/
/**
 * @file      : Lin_Drvw_Types.h
 * @brief     : AUTOSAR LIN driver header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved. 
 **************************************************************************************************/
#ifndef LIN_DRVW_TYPES_H
#define LIN_DRVW_TYPES_H

/** @addtogroup  Lin_Module
 *  @{
 */

/** @defgroup Lin
 *  @brief Lin
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Lin_Drvw_Cfg.h"
#include "Uart_Drv_Types.h"
#if (STD_ON == LIN_DRVW_WAKEUP_DETECTION)
#include "EcuM.h"
#endif
/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define LIN_DRVW_TYPES_H_VENDOR_ID                   0x00B3U
#define LIN_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION    4U
#define LIN_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION    6U
#define LIN_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION 0U
#define LIN_DRVW_TYPES_H_SW_MAJOR_VERSION            1U
#define LIN_DRVW_TYPES_H_SW_MINOR_VERSION            2U
#define LIN_DRVW_TYPES_H_SW_PATCH_VERSION            2U

/* Check if current file and Lin_Defines header file are of the same vendor */
#if (LIN_DRVW_TYPES_H_VENDOR_ID != LIN_DRVW_CFG_H_VENDOR_ID)
    #error "Vendor ID of Lin_Drvw_Types.h and Lin_Drvw_Cfg.h are different "
#endif
/* Check if current file and Lin_Defines header file are of the same Autosar version */
#if ((LIN_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION != LIN_DRVW_CFG_H_AR_RELEASE_MAJOR_VERSION) ||    \
     (LIN_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION != LIN_DRVW_CFG_H_AR_RELEASE_MINOR_VERSION) ||     \
     (LIN_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION != LIN_DRVW_CFG_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Lin_Drvw_Types.h and Lin_Drvw_Cfg.h are different"
#endif
/* Check if current file and Lin_Defines header file are of the same Software version */
#if ((LIN_DRVW_TYPES_H_SW_MAJOR_VERSION != LIN_DRVW_CFG_H_SW_MAJOR_VERSION) ||                     \
     (LIN_DRVW_TYPES_H_SW_MINOR_VERSION != LIN_DRVW_CFG_H_SW_MINOR_VERSION) ||                     \
     (LIN_DRVW_TYPES_H_SW_PATCH_VERSION != LIN_DRVW_CFG_H_SW_PATCH_VERSION))
    #error "Software Version of Lin_Drvw_Types.h and Lin_Drvw_Cfg.h are different"
#endif
/* Check if current file and Uart_Drv_Types header file are of the same vendor */
#if (LIN_DRVW_TYPES_H_VENDOR_ID != UART_DRV_TYPES_H_VENDOR_ID)
    #error "Vendor ID of Lin_Drvw_Types.h and Uart_Drv_Types.h are different"
#endif
/* Check if current file and Lin_Defines header file are of the same Autosar version */
#if ((LIN_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION != UART_DRV_TYPES_H_AR_RELEASE_MAJOR_VERSION) ||   \
     (LIN_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION != UART_DRV_TYPES_H_AR_RELEASE_MINOR_VERSION) ||   \
     (LIN_DRVW_TYPES_H_AR_RELEASE_REVISION_VERSION != UART_DRV_TYPES_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Lin_Drvw_Types.h and Uart_Drv_Types.h are different"
#endif

/* Check if current file and Lin_Defines header file are of the same Software version */
#if ((LIN_DRVW_TYPES_H_SW_MAJOR_VERSION != UART_DRV_TYPES_H_SW_MAJOR_VERSION) ||                   \
     (LIN_DRVW_TYPES_H_SW_MINOR_VERSION != UART_DRV_TYPES_H_SW_MINOR_VERSION) ||                   \
     (LIN_DRVW_TYPES_H_SW_PATCH_VERSION != UART_DRV_TYPES_H_SW_PATCH_VERSION))
    #error "Software Version of Lin_Drvw_Types.h and Uart_Drv_Types.h are different"
#endif

#ifdef MCAL_INTER_MODULE_ASR_CHECK_ENABLE
    #if(STD_ON == LIN_DRVW_WAKEUP_DETECTION)
        /* Check if current file and McalLib.h are the same Autosar version */
        #if ((LIN_DRVW_TYPES_H_AR_RELEASE_MAJOR_VERSION != ECUM_AR_RELEASE_MAJOR_VERSION) || \
            (LIN_DRVW_TYPES_H_AR_RELEASE_MINOR_VERSION != ECUM_AR_RELEASE_MINOR_VERSION) )
            #error "AutoSar Version of Lin_Drvw_Types.h and EcuM.h are different"
        #endif
    #endif
#endif /* MCAL_INTER_MODULE_ASR_CHECK_ENABLE */

/* LIN TX command */
#define LIN_DRVW_TX_COMMAND_NO         (uint8)0x00U /*!< No tx master command pending. */
#define LIN_DRVW_TX_COMMAND_MASTER_RES (uint8)0x01U /*!< The frame response is from master */
#define LIN_DRVW_TX_COMMAND_SLAVE_RES  (uint8)0x02U /*!< The frame response is from slave */
#define LIN_DRVW_TX_COMMAND_SLEEP      (uint8)0x03U /*!< The frame commands to sleep */
#define LIN_DRVW_TX_COMMAND_SLAVE_TO_SLAVE                                                         \
    (uint8)0x04U /*!< The frame response is from slave to slave                                    \
                  */

/**
 * @brief Return code for timeout error.
 */
#define LIN_DRVW_TIMEOUT_ERROR 0x02

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 * @brief  This type is used to specify the LIN node type of this channel.
 */
typedef enum
{
    LIN_DRVW_NODE_SLAVE = 0U, /*!<  This is slave node */
    LIN_DRVW_NODE_MASTER      /*!<  This is master node */
} Lin_Drvw_NodeType;

/**
 * @brief        Structure which brings together all the hardware specific information regarding a
 *               channel
 * @details      This structure contains:
 *               - LinHwChannel which specifies the number of hardware instance configured for the
 *                 current channel.
 *               - LinChannelWakeupSupport 
 *               - LinChannelEcuMWakeupSource
 *               - LinNodeType
 *              - DrvConfig member containing a singular valid pointer to a hardware specific user
 *                configured structure.
 * */
typedef struct
{
    const uint8 LinHwChannel; /**< @brief The number of lin physical channel*/

#if (LIN_DRVW_WAKEUP_DETECTION == STD_ON)
    boolean LinChannelWakeupSupport; /*!< @brief Is wake-up supported by the LIN channel.*/
    EcuM_WakeupSourceType
        LinChannelEcuMWakeupSource; /*!< @brief [SWS_Lin_00098] This parameter contains a reference
                                       to the Wakeup Source for this controller as defined in the
                                          ECU State Manager.*/
#endif

    const Lin_Drvw_NodeType             LinNodeType; /*!< @brief LIN Node Type.*/
    const Uart_Drv_ConfigType *DrvConfig; /*!< @brief A structure contains pointer to a hardware
                                                specific user configured structure */
} Lin_Drvw_HwConfigType;


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

/** @} end of group Lin */

/** @} end of group Lin_Module */

#endif /* LIN_TYPES_H */
