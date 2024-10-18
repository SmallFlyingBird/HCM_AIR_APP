/**************************************************************************************************/
/**
 * @file      : Gpt_Drvw_PBcfg.h
 * @brief     : AUTOSAR Gpt drvw - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 * 
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef GPT_DRVW_PBCFG_H
#define GPT_DRVW_PBCFG_H

/** @addtogroup Gpt_Module
 *  @{
 */

/** @addtogroup Gpt_Drvw_Configuration
 *  @brief Gpt driver wrapper configuration
 *  @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define GPT_DRVW_PBCFG_H_VENDOR_ID                   0x00B3U
#define GPT_DRVW_PBCFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define GPT_DRVW_PBCFG_H_AR_RELEASE_MINOR_VERSION    6U
#define GPT_DRVW_PBCFG_H_AR_RELEASE_REVISION_VERSION 0U
#define GPT_DRVW_PBCFG_H_SW_MAJOR_VERSION            1U
#define GPT_DRVW_PBCFG_H_SW_MINOR_VERSION            2U
#define GPT_DRVW_PBCFG_H_SW_PATCH_VERSION            1U

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */
#define GPT_DRVW_CONFIG_PB \
extern const Gpt_Drvw_HwInstanceConfigType Gpt_Drvw_InstanceConfig[2U]; \
extern const Gpt_Drvw_HwChannelConfigType Gpt_Drvw_ChannelConfig[5U];


/** @} end of group Global_VariableDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group Gpt_Drvw_Configuration */

/** @} end of group Gpt_Module */

#endif 
