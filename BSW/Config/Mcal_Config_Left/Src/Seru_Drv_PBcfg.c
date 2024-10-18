/**************************************************************************************************/
/**
 * @file      : Seru_Drv_PBcfg.c  
 * @brief     : Seru low level driver - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
/** @addtogroup Seru_Module
 *  @{
 */

/** @addtogroup Seru_Drv_Configuration
 *  @brief Seru low level driver configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"
{
#endif

#include "Seru_Drv.h"

/** @defgroup Private_MacroDefinition
 *  @{
 */
#define SERU_DRV_PBCFG_C_VENDOR_ID                   0x00B3U
#define SERU_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION    4U
#define SERU_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION    6U
#define SERU_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION 0U
#define SERU_DRV_PBCFG_C_SW_MAJOR_VERSION            1U
#define SERU_DRV_PBCFG_C_SW_MINOR_VERSION            1U
#define SERU_DRV_PBCFG_C_SW_PATCH_VERSION            0U

/* Check if current file and Seru_Drv.h are the same vendor */
#if (SERU_DRV_PBCFG_C_VENDOR_ID != SERU_DRV_H_VENDOR_ID)
    #error "Vendor ID of Seru_Drv_PBcfg.c and Seru_Drv.h are different"
#endif
/* Check if current file and Seru_Drv.h are the same Autosar version */
#if ((SERU_DRV_PBCFG_C_AR_RELEASE_MAJOR_VERSION != SERU_DRV_H_AR_RELEASE_MAJOR_VERSION) || \
     (SERU_DRV_PBCFG_C_AR_RELEASE_MINOR_VERSION != SERU_DRV_H_AR_RELEASE_MINOR_VERSION) || \
     (SERU_DRV_PBCFG_C_AR_RELEASE_REVISION_VERSION != SERU_DRV_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version of Seru_Drv_PBcfg.c and Seru_Drv.h are different"
#endif
/* Check if current file and Seru_Drv.h are the same software version */
#if ((SERU_DRV_PBCFG_C_SW_MAJOR_VERSION != SERU_DRV_H_SW_MAJOR_VERSION) || \
     (SERU_DRV_PBCFG_C_SW_MINOR_VERSION != SERU_DRV_H_SW_MINOR_VERSION) || \
     (SERU_DRV_PBCFG_C_SW_PATCH_VERSION != SERU_DRV_H_SW_PATCH_VERSION))
    #error "Software Version of Seru_Drv_PBcfg.c and Seru_Drv.h are different"
#endif

#define SERU_DRV_CHANNEL_NUM   (9U)
/** @} end of Private_MacroDefinition */

/** @defgroup Private_TypeDefinition
 *  @{
 */

/** @} end of group Private_TypeDefinition */

/** @defgroup Private_VariableDefinition
 *  @{
 */

/** @} end of group Private_VariableDefinition */

#define MEH_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Meh_MemMap.h"
/** @defgroup Global_VariableDefinition
 *  @{
 */

/**
* @brief Seru channels configuration.
*
*/
static const Seru_Drv_ChannelConfigType Seru_Drv_ChannelConfig[SERU_DRV_CHANNEL_NUM] = 
{
{
    SERU_DRV_SEL_RST_NORMAL,    /*!< Configure SERU RESET type*/
    SERU_DRV_RST_DELAY_NO,    /*!< Configure reset generation delay*/
FALSE,    /*!< Enable or disable RESET generation*/
FALSE,    /*!< Enable or disable EOUT report*/
    SERU_DRV_SEL_INT_NORMAL,    /*!< Set INT type */
TRUE,    /*!< Enable or disable INT generation*/
TRUE,    /*!< Enable or disable channel*/
    SERU_DRV_SRAMU_ECC_ERROR,    /*!< Channel number*/
},
{
    SERU_DRV_SEL_RST_NORMAL,    /*!< Configure SERU RESET type*/
    SERU_DRV_RST_DELAY_NO,    /*!< Configure reset generation delay*/
FALSE,    /*!< Enable or disable RESET generation*/
FALSE,    /*!< Enable or disable EOUT report*/
    SERU_DRV_SEL_INT_NORMAL,    /*!< Set INT type */
TRUE,    /*!< Enable or disable INT generation*/
TRUE,    /*!< Enable or disable channel*/
    SERU_DRV_SRAML_ECC_ERROR,    /*!< Channel number*/
},
{
    SERU_DRV_SEL_RST_NORMAL,    /*!< Configure SERU RESET type*/
    SERU_DRV_RST_DELAY_NO,    /*!< Configure reset generation delay*/
TRUE,    /*!< Enable or disable RESET generation*/
FALSE,    /*!< Enable or disable EOUT report*/
    SERU_DRV_SEL_INT_NORMAL,    /*!< Set INT type */
TRUE,    /*!< Enable or disable INT generation*/
TRUE,    /*!< Enable or disable channel*/
    SERU_DRV_FLASH_ECC_ERROR,    /*!< Channel number*/
},
{
    SERU_DRV_SEL_RST_NORMAL,    /*!< Configure SERU RESET type*/
    SERU_DRV_RST_DELAY_NO,    /*!< Configure reset generation delay*/
FALSE,    /*!< Enable or disable RESET generation*/
FALSE,    /*!< Enable or disable EOUT report*/
    SERU_DRV_SEL_INT_NORMAL,    /*!< Set INT type */
TRUE,    /*!< Enable or disable INT generation*/
TRUE,    /*!< Enable or disable channel*/
    SERU_DRV_PMU_LVW_FLAG,    /*!< Channel number*/
},
{
    SERU_DRV_SEL_RST_NORMAL,    /*!< Configure SERU RESET type*/
    SERU_DRV_RST_DELAY_NO,    /*!< Configure reset generation delay*/
FALSE,    /*!< Enable or disable RESET generation*/
FALSE,    /*!< Enable or disable EOUT report*/
    SERU_DRV_SEL_INT_NORMAL,    /*!< Set INT type */
TRUE,    /*!< Enable or disable INT generation*/
TRUE,    /*!< Enable or disable channel*/
    SERU_DRV_CMU0_BUS_CLOCK_ERROR,    /*!< Channel number*/
},
{
    SERU_DRV_SEL_RST_NORMAL,    /*!< Configure SERU RESET type*/
    SERU_DRV_RST_DELAY_NO,    /*!< Configure reset generation delay*/
FALSE,    /*!< Enable or disable RESET generation*/
FALSE,    /*!< Enable or disable EOUT report*/
    SERU_DRV_SEL_INT_NORMAL,    /*!< Set INT type */
TRUE,    /*!< Enable or disable INT generation*/
TRUE,    /*!< Enable or disable channel*/
    SERU_DRV_CMU2_LPO_ERROR,    /*!< Channel number*/
},
{
    SERU_DRV_SEL_RST_NORMAL,    /*!< Configure SERU RESET type*/
    SERU_DRV_RST_DELAY_NO,    /*!< Configure reset generation delay*/
FALSE,    /*!< Enable or disable RESET generation*/
FALSE,    /*!< Enable or disable EOUT report*/
    SERU_DRV_SEL_INT_NORMAL,    /*!< Set INT type */
TRUE,    /*!< Enable or disable INT generation*/
TRUE,    /*!< Enable or disable channel*/
    SERU_DRV_SW_ERR0,    /*!< Channel number*/
},
{
    SERU_DRV_SEL_RST_NORMAL,    /*!< Configure SERU RESET type*/
    SERU_DRV_RST_DELAY_NO,    /*!< Configure reset generation delay*/
FALSE,    /*!< Enable or disable RESET generation*/
FALSE,    /*!< Enable or disable EOUT report*/
    SERU_DRV_SEL_INT_NORMAL,    /*!< Set INT type */
TRUE,    /*!< Enable or disable INT generation*/
TRUE,    /*!< Enable or disable channel*/
    SERU_DRV_CPU_LOCKUPFLAG,    /*!< Channel number*/
},
{
    SERU_DRV_SEL_RST_NORMAL,    /*!< Configure SERU RESET type*/
    SERU_DRV_RST_DELAY_NO,    /*!< Configure reset generation delay*/
FALSE,    /*!< Enable or disable RESET generation*/
FALSE,    /*!< Enable or disable EOUT report*/
    SERU_DRV_SEL_INT_NORMAL,    /*!< Set INT type */
TRUE,    /*!< Enable or disable INT generation*/
FALSE,    /*!< Enable or disable channel*/
    SERU_DRV_CPU_DEBUG_HALT,    /*!< Channel number*/
},
};

/**
* @brief Seru configuration.
*
*/
const Seru_Drv_ConfigType  Seru_Drv_Config= {
    TRUE,    /*!< Enable or disable error interrupt */
    SERU_DRV_EOUT0_HIGH_EOUT1_LOW,             /*!< default value selection for EOUT */
    SERU_DRV_EOUT_PORT,        /*!< Eout0 Mode Select*/
    SERU_DRV_EOUT_PORT,        /*!< Eout1 Mode Select*/
    TRUE,    /*!< Enable or disable fake fault injection */
    9U,    /*!< Channel count that user configured */ 
    Seru_Drv_ChannelConfig};

/** @} end of group Global_VariableDefinition */
#define MEH_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Meh_MemMap.h"

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

/** @} end of group Seru_Drv_Configuration */

/** @} end of group Seru_Module */
