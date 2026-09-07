/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Port_Cfg.h
 * @brief 
 * 
 */


#ifndef PORT_CFG_H
#define PORT_CFG_H

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
#define PORT_VENDOR_ID_CFG                      (180)
#define PORT_AR_RELEASE_MAJOR_VERSION_CFG       (4)
#define PORT_AR_RELEASE_MINOR_VERSION_CFG       (4)
#define PORT_AR_RELEASE_REVISION_VERSION_CFG    (0)
#define PORT_SW_MAJOR_VERSION_CFG               (2)
#define PORT_SW_MINOR_VERSION_CFG               (3)
#define PORT_SW_PATCH_VERSION_CFG               (0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
 *                                       LOCAL MACROS
==================================================================================================*/
// PortGeneral
/**
 * @brief Switches the development error detection and notification on or off.
 * @note Trace: ECUC_Port_00123
 *       range: STD_ON, STD_OFF
 */
#define PORT_DEV_ERROR_DETECT                       (STD_ON)

/**
 * @brief Pre-processor switch to enable / disable the use of the function Port_SetPinDirection().
 * @note Trace: ECUC_Port_00131
 *       range: STD_ON, STD_OFF
 */
#define PORT_SET_PIN_DIRECTION_API                   (STD_ON)

/**
 * @brief Pre-processor switch to enable / disable the use of the function Port_SetPinMode().
 * @note Trace: ECUC_Port_00132
 *       range: STD_ON, STD_OFF
 */
#define PORT_SET_PIN_MODE_API                        (STD_ON)

/**
 * @brief Pre-processor switch to enable / disable the API to read out the modules version information.
 * @note Trace: ECUC_Port_00133
 *       range: STD_ON, STD_OFF
 */
#define PORT_VERSION_INFO_API                       (STD_ON)
/**
 * @brief Pre-processor switch to use or not use the post-build config
 * @note range: STD_ON, STD_OFF      
 */
#define PORT_FIXED_PB_CONFIG (STD_OFF)


/**
 * @brief        Pre-compile PORT_HAS_DIGITAL_FILTER
 */
#define PORT_HAS_DIGITAL_FILTER (STD_ON)


/**
 * @brief        Pre-compile PORT_HAS_DIGITAL_FILTER
 */
#define PORT_HAS_SLEW_RATE (STD_ON)


/**
 * @brief        Pre-compile enable PORT_READBACK_ENABLE
 */
#define PORT_READBACK_ENABLE                        (STD_OFF)


#ifdef PORT_ENABLE_USER_MODE_SUPPORT
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
#error "Must define MCAL_ENABLE_USER_MODE_SUPPORT if PORT_ENABLE_USER_MODE_SUPPORT is defined"
#endif
#endif

/**
* @brief Support for SchM: sync/atomic operations, global interrupt disable/enable.
*        If this parameter has been configured to 'STD_ON', the MCAL driver code supports sync/atomic operations for key resource protection.
*        If it is enabled, all the SchM codes in MCAL Port driver codes will work and support sync/atomic operation with CPU global interrupt enable/disable for key resource protection. 
*        Disable it can reduce code size, but may cause potential risks when access to some critical resource!
*/
#define PORT_SCHM_SUPPORT  (STD_ON) 

/**
* @brief Port Pin symbolic names
* @details Get All Symbolic Names from configuration tool
*
*/

#define PortConf_PortPin_PTA6              ((Port_PinType)(((0)<<8)|6))
#define PortConf_PortPin_PTB0              ((Port_PinType)(((1)<<8)|0))
#define PortConf_PortPin_PTB4              ((Port_PinType)(((1)<<8)|4))
#define PortConf_PortPin_PTB8              ((Port_PinType)(((1)<<8)|8))
#define PortConf_PortPin_PTB17             ((Port_PinType)(((1)<<8)|17))
#define PortConf_PortPin_PTB2              ((Port_PinType)(((1)<<8)|2))
#define PortConf_PortPin_PTB11             ((Port_PinType)(((1)<<8)|11))
#define PortConf_PortPin_PTC8              ((Port_PinType)(((2)<<8)|8))
#define PortConf_PortPin_PTD2              ((Port_PinType)(((3)<<8)|2))
#define PortConf_PortPin_PTD15_CS          ((Port_PinType)(((3)<<8)|15))
#define PortConf_PortPin_PTD16             ((Port_PinType)(((3)<<8)|16))
#define PortConf_PortPin_PTE3_CS_U1        ((Port_PinType)(((4)<<8)|3))
#define PortConf_PortPin_PTE11             ((Port_PinType)(((4)<<8)|11))
#define PortConf_PortPin_PTE16             ((Port_PinType)(((4)<<8)|16))
#define PortConf_PortPin_PTE_7             ((Port_PinType)(((4)<<8)|7))
#define PortConf_PortPin_ADC0_SE0          ((Port_PinType)(((0)<<8)|0))
#define PortConf_PortPin_ADC0_SE3          ((Port_PinType)(((0)<<8)|7))
#define PortConf_PortPin_ADC0_SE7          ((Port_PinType)(((1)<<8)|3))
#define PortConf_PortPin_ADC0_SE10         ((Port_PinType)(((2)<<8)|2))
#define PortConf_PortPin_ADC0_SE11         ((Port_PinType)(((2)<<8)|3))
#define PortConf_PortPin_ADC0_SE12         ((Port_PinType)(((2)<<8)|14))
#define PortConf_PortPin_ADC0_SE13         ((Port_PinType)(((2)<<8)|15))
#define PortConf_PortPin_ADC0_SE14         ((Port_PinType)(((2)<<8)|16))
#define PortConf_PortPin_ADC0_SE15         ((Port_PinType)(((2)<<8)|17))
#define PortConf_PortPin_ADC0_SE23         ((Port_PinType)(((1)<<8)|12))
#define PortConf_PortPin_SPI2_SIN          ((Port_PinType)(((2)<<8)|0))
#define PortConf_PortPin_SPI2_SOUT         ((Port_PinType)(((2)<<8)|1))
#define PortConf_PortPin_SPI2_SCK          ((Port_PinType)(((4)<<8)|15))
#define PortConf_PortPin_Etmr0_CH6         ((Port_PinType)(((4)<<8)|8))
#define PortConf_PortPin_Etmr1_CH7         ((Port_PinType)(((0)<<8)|13))
#define PortConf_PortPin_Etmr3_Ch0         ((Port_PinType)(((0)<<8)|2))
#define PortConf_PortPin_Etmr1_CH6         ((Port_PinType)(((0)<<8)|12))
#define PortConf_PortPin_Etmr3_CH1         ((Port_PinType)(((1)<<8)|9))
#define PortConf_PortPin_LINFlexD1_TX      ((Port_PinType)(((2)<<8)|7))
#define PortConf_PortPin_LINFlexD1_RX      ((Port_PinType)(((2)<<8)|6))

#ifdef __cplusplus
}
#endif

#endif /* PORT_CFG_H */

/** @} */

