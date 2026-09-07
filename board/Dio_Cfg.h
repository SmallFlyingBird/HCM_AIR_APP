/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Dio_Cfg.h
 * @brief 
 * 
 */


#ifndef DIO_CFG_H
#define DIO_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DIO_VENDOR_ID_CFG                      (180)
#define DIO_AR_RELEASE_MAJOR_VERSION_CFG       (4)
#define DIO_AR_RELEASE_MINOR_VERSION_CFG       (4)
#define DIO_AR_RELEASE_REVISION_VERSION_CFG    (0)
#define DIO_SW_MAJOR_VERSION_CFG               (2)
#define DIO_SW_MINOR_VERSION_CFG               (3)
#define DIO_SW_PATCH_VERSION_CFG               (0)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/**
 * @defgroup Container_DioGeneral 
 * @brief Definitions port pin ID
*/
/** @{ */
/**
 * @brief Switches the Default Error Tracer (Det) detection and notification ON or OFF
 * @trace ECUC_Dio_00142
 * @option STD_ON, STD_OFF
 */
#define DIO_DEV_ERROR_DETECT (STD_ON)

/** @{ */
/**
 * @brief Switches the GPIO IP Dio Development Error Detect ON or OFF
 * @trace ECUC_Dio_00142
 * @option STD_ON, STD_OFF
 */
#define GPIO_DEV_ERROR_DETECT (STD_ON)

/**
 * @brief Adds / removes the service Dio_FlipChannel() from the code
 * @trace ECUC_Dio_00153
 * @option STD_ON, STD_OFF
 */
#define DIO_FLIP_CHANNEL_API (STD_ON)

/**
 * @brief Adds / removes the service Dio_GetVersionInfo() from the code
 * @trace ECUC_Dio_00143
 * @option STD_ON, STD_OFF
 */
#define DIO_VERSION_INFO_API (STD_OFF)

/**
 * @brief Enable / Disable the possibility to support continual Dio channel ID.
 * @option STD_ON, STD_OFF
 */
#define DIO_CHANNELID_CONTINUITY (STD_OFF)

/**
 * @brief Adds / removes the service Dio_MaskedWritePort() from the code
 * @option STD_ON, STD_OFF
 */
#define DIO_MASKED_WRITE_PORT_API (STD_ON)


#ifdef DIO_ENABLE_USER_MODE_SUPPORT
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
#error "Must define MCAL_ENABLE_USER_MODE_SUPPORT if DIO_ENABLE_USER_MODE_SUPPORT is defined"
#endif
#endif

/**
* @brief Support for SchM: sync/atomic operations, global interrupt disable/enable.
*        If this parameter has been configured to 'STD_ON', the MCAL driver code supports sync/atomic operations for key resource protection.
*        If it is enabled, all the SchM codes in MCAL Dio driver codes will work and support sync/atomic operation with CPU global interrupt enable/disable for key resource protection. 
*        Disable it can reduce code size, but may cause potential risks when access to some critical resource!
*/
#define DIO_SCHM_SUPPORT  (STD_ON) 

/**
 * @brief Enable / Disable the possibility to support multicore.
 * @option STD_ON, STD_OFF
 */
#define DIO_MULTICORE_SUPPORT (STD_OFF)

/* For YTM32B1MD1-LQFP-100 */
/**
 * @defgroup Dio_Port_Pin_Mask
 * @brief Define the hardware port pin mask of each port
 */
/** @{ */
#define DIO_PORTA_PINS_MASK (0x3ffffU) /* available pin of PORTA */
#define DIO_PORTB_PINS_MASK (0x3ffffU) /* available pin of PORTB */
#define DIO_PORTC_PINS_MASK (0x3ffffU) /* available pin of PORTC */
#define DIO_PORTD_PINS_MASK (0x3fffcU) /* available pin of PORTD */
#define DIO_PORTE_PINS_MASK (0x1ffffU)  /* available pin of PORTE */
/** @} */

/**
 * @defgroup Symbolic name for the static Dio_Port_ID
 * @brief Numeric identifier of the DIO port. 
 * @details user can use either the static Dio_Port_ID or dynamic Dio_Port_ID by the tool
 * @trace ECUC_Dio_00145, SWS_Dio_00113， SWS_Dio_00026
 */
/** @{ */
#define DioPort_PORT_A (0x00U)
#define DioPort_PORT_B (0x01U)
#define DioPort_PORT_C (0x02U)
#define DioPort_PORT_D (0x03U)
#define DioPort_PORT_E (0x04U)
/** @} */

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
/**
 * @defgroup Symbolic name for the dynamic Dio_Port_ID
 * @brief Numeric identifier of the DIO port. 
 * @details Not all MCU ports may be used for DIO, thus there may be "gaps" in the list of all IDs. 
 *      This value will be assigned to the DIO port symbolic name (i.e. the SHORT-NAME of the DioPort 
 *      container)
 *      user can use either the static Dio_Port_ID or dynamic Dio_Port_ID by the tool
 * @trace ECUC_Dio_00145, SWS_Dio_00113， SWS_Dio_00026
 */
/** @{ */
#define DioConf_DioPort_PORT_A (0x0U)
#define DioConf_DioPort_PORT_B (0x1U)
#define DioConf_DioPort_PORT_C (0x2U)
#define DioConf_DioPort_PORT_D (0x3U)
#define DioConf_DioPort_PORT_E (0x4U)

/**
 * @defgroup Symbolic name for Dio_Channel_ID
 * @brief Numeric identifier of the DIO channel. 
 * @details It's generated by the tool, the value is the index of the channel in the port with the 
 *           port name.
 * @trace ECUC_Dio_00147， SWS_Dio_00026
 */
/** @{ */
#define DioConf_DioChannel_LR_Identify        (((0U << 8U) + 6U))
#define DioConf_DioChannel_HSD1_SEL2        (((1U << 8U) + 0U))
#define DioConf_DioChannel_CC_Boost_EN        (((1U << 8U) + 4U))
#define DioConf_DioChannel_DRL_Ctrl        (((1U << 8U) + 8U))
#define DioConf_DioChannel_TL_Ctrl        (((1U << 8U) + 11U))
#define DioConf_DioChannel_PG_LDO1        (((1U << 8U) + 17U))
#define DioConf_DioChannel_HSD_EN1        (((1U << 8U) + 2U))
#define DioConf_DioChannel_HSD1_SEL1        (((2U << 8U) + 8U))
#define DioConf_DioChannel_WD_Feed        (((3U << 8U) + 2U))
#define DioConf_DioChannel_SPI_BD_CS2        (((3U << 8U) + 15U))
#define DioConf_DioChannel_FAN_DIAG_MCU        (((3U << 8U) + 16U))
#define DioConf_DioChannel_SPI_BD_CS1        (((4U << 8U) + 3U))
#define DioConf_DioChannel_LIN_Wake_N        (((4U << 8U) + 11U))
#define DioConf_DioChannel_LIN_SLP_N        (((4U << 8U) + 16U))
#define DioConf_DioChannel_HSD_EN2        (((4U << 8U) + 7U))
/** @} */

/**
 * @defgroup Symbolic name for Dio_Channel_Group_ID
 * @brief Numeric identifier of the DIO channel group. 
 * @details It's generated by the tool, the value is the index of the channel group in the port with the 
 *           port name.
 * @trace ECUC_Dio_00147， SWS_Dio_00026
 */
/** @{ */
/** @} */

#define DIO_CHANNEL_GROUP_0 0U
#define DIO_CHANNEL_GROUP_1 0U
#define DIO_CHANNEL_GROUP_2 0U
#define DIO_CHANNEL_GROUP_3 0U
#define DIO_CHANNEL_GROUP_4 0U

/**
 * @brief Define the channel group number used in the application
 *        if the group number larger than zero, enable chanel group operations APIs
 * @option actual
 */
#define DIO_CHANNEL_GROUP_NUMBER (0U  + DIO_CHANNEL_GROUP_0  + DIO_CHANNEL_GROUP_1  + DIO_CHANNEL_GROUP_2  + DIO_CHANNEL_GROUP_3  + DIO_CHANNEL_GROUP_4 )

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* for DIO_CFG_H */

/** @} */

