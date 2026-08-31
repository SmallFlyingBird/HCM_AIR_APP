/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Lin_Cfg.h
 * @brief 
 * 
 */


#ifndef LIN_CFG_H
#define LIN_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
#include "EcuM.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LIN_VENDOR_ID_CFG                      (180)
#define LIN_AR_RELEASE_MAJOR_VERSION_CFG       (4)
#define LIN_AR_RELEASE_MINOR_VERSION_CFG       (4)
#define LIN_AR_RELEASE_REVISION_VERSION_CFG    (0)
#define LIN_SW_MAJOR_VERSION_CFG               (2)
#define LIN_SW_MINOR_VERSION_CFG               (3)
#define LIN_SW_PATCH_VERSION_CFG               (0)

/*==================================================================================================
 *                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
 *                                        LinGeneral
==================================================================================================*/

/**
 * @brief       Switches the development error detection and notification on or off.
 * @details     * true: detection and notification is enabled.
                * false: detection and notification is disabled.
 * @ref         ECUC_Lin_00066
 */
#define LIN_DEV_ERROR_DETECT                        (STD_OFF)
/**
 * @brief        Switches the Lin_GetVersionInfo function ON or OFF.
 * @ref          ECUC_Lin_00067
 */
#define LIN_VERSION_INFO_API                        (STD_OFF)
/**
 * @brief        Specifies the InstanceId of this module instance. If only one instance is present it shall have the Id 0.
 * @ref          ECUC_Lin_00179
 */
#define LIN_INDEX                                   (0)
/**
 * @brief        Specifies the maximum number of loops for blocking function until a timeout is raised in short term wait loops
 * @ref          ECUC_Lin_00093
 */
#define LIN_TIMEOUT_DURATION                        (1000)

/**
 * @brief        Specifies if the LIN hardware channel supports wake up functionality
 * @ref          ECUC_Lin_00182
 */
#define LIN_CHANNEL_WAKEUP_SUPPORT                  (STD_ON)

/**
 * @brief        Specifies if the LIN hardware frame timeout detection is enabled.
 * @details
 */
#define LIN_FRAME_TIMEOUT_DISABLE                  (STD_OFF)

/**
 * @brief        Specifies if the LIN hardware Dem is enabled.
 * @details
 */
#define LIN_DEM_DISABLE                            (STD_ON)


#define LIN_DEM_EVENT_ID  0

/**
 * @brief        LIN have one unified interrupt.
 * @details      This define enable when LINFlexd only have one interrupt for each channel
 */
#define LIN_HAS_UNIFIED_INTERRUPT                   (TRUE)

/**
 * @brief        Number of configured channels
 */
#define LIN_CHANNEL_USED_NUM                        (1)

/**
 * @brief        Number of Max channels of the IC
 */
#define LIN_CHANNEL_MAX_NUM                         (3)

/**
 * @brief       Max number of data bytes in one frame
 */
#define LIN_MAX_DATA_LENGTH                         (8U)


#define LIN_IP_LINFLEXD                                 (STD_ON)
#define LIN_IP_UART                                     (STD_OFF)

#define LIN_MASTER_API_SUPPORT                      (STD_OFF)


#define LIN_SLAVE_API_SUPPORT                       (STD_OFF)

#undef  LIN_SLAVE_API_SUPPORT
#define LIN_SLAVE_API_SUPPORT                       (STD_ON)

#define LIN_DEINIT_API_SUPPORT                      (STD_OFF)

#define LIN_SCHM_SUPPORT                            (STD_ON)

#ifdef LIN_ENABLE_USER_MODE_SUPPORT
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
#error "Must define MCAL_ENABLE_USER_MODE_SUPPORT if LIN_ENABLE_USER_MODE_SUPPORT is defined"
#endif
#endif

#define LINFLEXD_IP_1_LIN_OCCUPY

#define LIN_INSTANCE_ID_1   ((uint8)1U)

/**
* @brief            Pre-compile Support.
*/
#define LIN_FIXED_PB_CONFIG  (STD_OFF)

/*==================================================================================================
 *                                       SYMBOLIC NAME
==================================================================================================*/
#define LinConf_LinChannel_LinChannel0 (0U)


/*==================================================================================================
 *                                       
==================================================================================================*/
/** @brief        Sleep Command Frame ID 0x3C.  */
#define LIN_DRV_SLEEP_COMMAND_ID                ((uint32)0x3CU)
/** @brief        Sleep Command Frame Length.  */
#define LIN_DRV_SLEEP_COMMAND_DATA_LENGTH       ((uint32)0x8U)

/** @brief        Master Request Diagnostic Frame ID 0x3C.  */
#define LIN_DRV_MASTER_REQUEST_DIAGNOSTIC_ID    ((uint32)0x3CU)

/** @brief        Slave Response Diagnostic Frame ID 0x3D.  */
#define LIN_DRV_SLAVE_RESPONSE_DIAGNOSTIC_ID    ((uint32)0x3DU)

#define LIN_CONST_UART_ID_START_NUMBER          ((uint8)0x40U)
#define LIN_CONST_THEORETICAL_MAX_CHANNEL_NUM   (16U)
#define LIN_CONST_CONST_WHOLE_OF_BYTE_ALL_TRUE  (0xFFU)
#define LIN_CONST_DECIMAL_BITS                  (16U)
#define LIN_CONST_LINTOCR_DEFAULT_VALUE         (0x0000FFFFU)
#define LIN_CONST_LINCR1_DEFAULT_VALUE          (0x00000082U)
#define LIN_CONST_MAX_FRAME_BYTES_NUM           ((uint8)8U)
#define LIN_CONST_PARA_NUM_1                    (1U)
#define LIN_CONST_PARA_NUM_2                    (2U)
#define LIN_CONST_PARA_NUM_8                    (8U)
#define LIN_CONST_PARA_NUM_9                    (9U)
#define LIN_CONST_BAUDRATE_OSRVAL_16            (16U)
#define LIN_CONST_PARA_BYTE_US_TIME_DIVIDEND    ((uint32)10000000U)
#define LIN_CONST_PARA_US_OF_SECOND             ((uint32)1000000U)
#define LIN_CONST_PARA_400US_DIVIDEND           ((uint32)4000U)
#define LIN_CONST_SYNC_FIELD_DATA               (0x55U)
#define LIN_CONST_GPT_500US_DIVISOR             ((uint32)2000U)
#define LIN_CONST_GPT_TICS_500US                ((uint32)500U)
#define LIN_CONST_TIMEOUT_BREAK_CYCLES          ((uint32)48U)
#define LIN_CONST_TIMEOUT_HEADER_CYCLES         ((uint32)34U)
#define LIN_CONST_UART_ERROR_INTE_MASK          (0x00000040U)

#define LIN_CONST_UART_7_BIT_DATA_MODE          (0x00U)
#define LIN_CONST_UART_8_BIT_DATA_MODE          (0x01U)
#define LIN_CONST_UART_9_BIT_DATA_MODE          (0x02U)
#define LIN_CONST_UART_10_BIT_DATA_MODE         (0x03U)


#ifdef __cplusplus
}
#endif

#endif /* LIN_CFG_H */

/** @} */

