/**************************************************************************************************/
/**
 * @file      : Port_Cfg.h
 * @brief     : AUTOSAR Port config file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef PORT_CFG_H
#define PORT_CFG_H

/** @addtogroup Port_Module
 *  @{
 */

/** @addtogroup Port_Configuration
 *  @brief Port AUTOSAR level configuration
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Port_PBcfg.h"



/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define PORT_CFG_H_VENDOR_ID                   0x00B3U
#define PORT_CFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define PORT_CFG_H_AR_RELEASE_MINOR_VERSION    6U
#define PORT_CFG_H_AR_RELEASE_REVISION_VERSION 0U
#define PORT_CFG_H_SW_MAJOR_VERSION            1U
#define PORT_CFG_H_SW_MINOR_VERSION            2U
#define PORT_CFG_H_SW_PATCH_VERSION            2U

/* Check if the vendor id of current file and Port_PBcfg.h are the same  */
#if (PORT_CFG_H_VENDOR_ID != PORT_PBCFG_H_VENDOR_ID)
    #error "Vendor if of Port_Cfg.h and Port_PBcfg.h are different"
#endif
/* Check if autodsar version of current file and Port_PBcfg.h are the same */
#if ((PORT_CFG_H_AR_RELEASE_MAJOR_VERSION != PORT_PBCFG_H_AR_RELEASE_MAJOR_VERSION) ||    \
     (PORT_CFG_H_AR_RELEASE_MINOR_VERSION != PORT_PBCFG_H_AR_RELEASE_MINOR_VERSION) ||    \
     (PORT_CFG_H_AR_RELEASE_REVISION_VERSION != PORT_PBCFG_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar version of Port_Cfg.h and Port_PBcfg.h are different"
#endif
/* Check if the software version of current file and Port_PBcfg.h are the same*/
#if ((PORT_CFG_H_SW_MAJOR_VERSION != PORT_PBCFG_H_SW_MAJOR_VERSION) ||  \
     (PORT_CFG_H_SW_MINOR_VERSION != PORT_PBCFG_H_SW_MINOR_VERSION) ||  \
     (PORT_CFG_H_SW_PATCH_VERSION != PORT_PBCFG_H_SW_PATCH_VERSION)     \
    )
    #error "Software version of Port_Cfg.h and Port_PBcfg.h are different"
#endif


    


#define PORT_PRECOMPILE_SUPPORT     (STD_ON)

#define PORT_DEV_ERROR_DETECT           PORT_DRVW_DEV_ERROR_DETECT

#define PORT_SET_PIN_DIRECTION_API      PORT_DRVW_SET_PIN_DIRECTION_API

#define PORT_SET_PIN_MODE_API           PORT_DRVW_SET_PIN_MODE_API

#define PORT_VERSION_INFO_API           (STD_ON)

#define PORT_NUMBER_OF_PARTITION              (1U)

#define PORT_TOTAL_PIN_NUMBER    ((uint16)144)

#define PORT_NUMBER_OF_CONFIG_PINS      PORT_DRVW_NUMBER_OF_CONFIG_PINS

#define PORT_MAX_PINMUX_NUMBER          PORT_DRVW_MAX_PINMUX_NUMBER


#define PortConf_PortPin_HSD1_SNS  20
#define PortConf_PortPin_L_R_Identify_To_MCU  21
#define PortConf_PortPin_Trigger_Ctrl2  26
#define PortConf_PortPin_DC_Ctr_AD  30
#define PortConf_PortPin_DC_Ctr  33
#define PortConf_PortPin_H_L_Ctrl  34
#define PortConf_PortPin_CAN1_TX  35
#define PortConf_PortPin_CAN1_RX  36
#define PortConf_PortPin_CC_Boost_EN  9
#define PortConf_PortPin_HSD_EN1  18
#define PortConf_PortPin_HSD1_SEL2  19
#define PortConf_PortPin_PG_LDO1  23
#define PortConf_PortPin_KL56_Vol_Get  24
#define PortConf_PortPin_TL_Ctrl  27
#define PortConf_PortPin_Trigger_Ctrl  28
#define PortConf_PortPin_DRL_Ctrl  29
#define PortConf_PortPin_MCU_AD2  10
#define PortConf_PortPin_MCU_AD4  11
#define PortConf_PortPin_MCU_AD3  13
#define PortConf_PortPin_MCU_AD5  14
#define PortConf_PortPin_MCU_AD1  15
#define PortConf_PortPin_MCU_AD6  16
#define PortConf_PortPin_HSD1_SEL1  17
#define PortConf_PortPin_CAN2_TX  31
#define PortConf_PortPin_CAN2_RX  32
#define PortConf_PortPin_MCU_AD7  40
#define PortConf_PortPin_FAN_DIAG_MCU  4
#define PortConf_PortPin_SPI_BD_CS2  5
#define PortConf_PortPin_SPI_BD_CLK  6
#define PortConf_PortPin_SPI_BD_MOSI  7
#define PortConf_PortPin_SPI_BD_MISO  12
#define PortConf_PortPin_WD_Feed  25
#define PortConf_PortPin_PTD14_CLKOUT  39
#define PortConf_PortPin_LIN_SLP_N  0
#define PortConf_PortPin_LIN_Wake_N  1
#define PortConf_PortPin_SPI_BD_CS1  2
#define PortConf_PortPin_TRK_CC_BOOST  3
#define PortConf_PortPin_PTE8_PWM_OUT  8
#define PortConf_PortPin_HSD_EN2  22
#define PortConf_PortPin_LIN1_TX  37
#define PortConf_PortPin_LIN1_RX  38


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

/** @} end of group Port_Configuration */

/** @} end of group Port_Module */

#endif /* PORT_CFG_H */

/* End of File */
