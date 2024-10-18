/**************************************************************************************************/
/**
 * @file      : Port_Cfg.h
 * @brief     : AUTOSAR Port config file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
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
#define PORT_CFG_H_SW_PATCH_VERSION            1U

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

/**
* @brief Defines PORT configuration
*/
#define PORT_CONFIG_EXT \
    PORT_CONFIG_PB 
    


#define PORT_PRECOMPILE_SUPPORT     (STD_OFF)

#define PORT_DEV_ERROR_DETECT           PORT_DRVW_DEV_ERROR_DETECT

#define PORT_SET_PIN_DIRECTION_API      PORT_DRVW_SET_PIN_DIRECTION_API

#define PORT_SET_PIN_MODE_API           PORT_DRVW_SET_PIN_MODE_API

#define PORT_VERSION_INFO_API           (STD_ON)

#define PORT_NUMBER_OF_PARTITION              (1U)

#define PORT_TOTAL_PIN_NUMBER    ((uint16)144)

#define PORT_NUMBER_OF_CONFIG_PINS      PORT_DRVW_NUMBER_OF_CONFIG_PINS

#define PORT_MAX_PINMUX_NUMBER          PORT_DRVW_MAX_PINMUX_NUMBER


#define PortConf_PortPin_SBC_EN_OR_SPI3_MISO  0
#define PortConf_PortPin_ERR_N_OR_SPI3_SCK  1
#define PortConf_PortPin_SBC_STB_OR_SPI3_CS  2
#define PortConf_PortPin_CAN_TX_BODY  3
#define PortConf_PortPin_LIMP_CON  4
#define PortConf_PortPin_SPI_BD_CS1  5
#define PortConf_PortPin_SPI_BD_CS4  6
#define PortConf_PortPin_SPI_BD_CS3  7
#define PortConf_PortPin_FAN_DIAG_MCU  8
#define PortConf_PortPin_SPI_BD_CS2  9
#define PortConf_PortPin_Fault_92682  10
#define PortConf_PortPin_ALS_DIR  11
#define PortConf_PortPin_SPI_BD_CLK  12
#define PortConf_PortPin_ALS_NXT  13
#define PortConf_PortPin_SPI_BD_CS_BOOST  14
#define PortConf_PortPin_EN_92682  15
#define PortConf_PortPin_CS_ALS  16
#define PortConf_PortPin_MCU_AD3  17
#define PortConf_PortPin_MCU_AD4  18
#define PortConf_PortPin_MotorOut_Con_ALS  19
#define PortConf_PortPin_MotorOut_Con_AFS  20
#define PortConf_PortPin_MOTOR_ERR  21
#define PortConf_PortPin_SPI_BD_MOSI  22
#define PortConf_PortPin_SPI_BD_MISO  23
#define PortConf_PortPin_MCU_AD1  24
#define PortConf_PortPin_MCU_AD5  25
#define PortConf_PortPin_AFS_NXT  26
#define PortConf_PortPin_MCU_AD6  27
#define PortConf_PortPin_MCU_AD2  28
#define PortConf_PortPin_HALL_SIG_GET  29
#define PortConf_PortPin_HSD_EN4  30
#define PortConf_PortPin_HSD_EN2  31
#define PortConf_PortPin_AFS_DIR  32
#define PortConf_PortPin_CS_AFS  33
#define PortConf_PortPin_NC_OR_SPI3_MOSI  34
#define PortConf_PortPin_CAN_RX_S  35
#define PortConf_PortPin_CAN_TX_S  36
#define PortConf_PortPin_DC_Ctr  37
#define PortConf_PortPin_FAN_CTR  38
#define PortConf_PortPin_MCU_AD7  39
#define PortConf_PortPin_OUT_CON_5V  40
#define PortConf_PortPin_CAN_RX_S_ADB_Master  41
#define PortConf_PortPin_CAN_TX_S_ADB_Master  42
#define PortConf_PortPin_DC_Ctr_AD  43
#define PortConf_PortPin_FAN_Ctr_AD  44
#define PortConf_PortPin_AD_5V_2  45
#define PortConf_PortPin_CAN_RX_BODY  46
#define PortConf_PortPin_LIN1_RX  47
#define PortConf_PortPin_LIN1_TX  48
#define PortConf_PortPin_WD_Feed  49
#define PortConf_PortPin_HSD2_SNS  50
#define PortConf_PortPin_HSD_EN3  51
#define PortConf_PortPin_KL15_Vol_Get  52
#define PortConf_PortPin_KL56_Vol_Get  53
#define PortConf_PortPin_SPI2_SCLK  54
#define PortConf_PortPin_SPI2_MISO  55
#define PortConf_PortPin_SPI2_MOSI  56
#define PortConf_PortPin_PG_LDO1  57
#define PortConf_PortPin_HSD_EN1  58
#define PortConf_PortPin_LR_Identify  59
#define PortConf_PortPin_HSD1_SNS  60
#define PortConf_PortPin_HSD1_SEL1  61
#define PortConf_PortPin_HSD1_SEL2  62
#define PortConf_PortPin_AD_5V_3  63
#define PortConf_PortPin_HSD2_SEL2  64
#define PortConf_PortPin_HSD2_SEL1  65


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
