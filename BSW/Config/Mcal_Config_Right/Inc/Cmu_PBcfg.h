/**************************************************************************************************/
/**
 * @file      : Cmu_PBcfg.h
 * @brief     : AUTOSAR Cmu - Post-Build(PB) configuration file code template
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.1.0
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
  * @copyright: Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

/** @addtogroup Cmu_Module
 *  @{
 */

/** @addtogroup Cmu_Configuration
 *  @brief Cmu configuration
 *  @{
 */

#ifndef CMU_PBCFG_H
#define CMU_PBCFG_H

#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup Public_MacroDefinition
 *  @{
 */

#define CMU_PBCFG_H_VENDOR_ID                   0x00B3U
#define CMU_PBCFG_H_AR_RELEASE_MAJOR_VERSION    4U
#define CMU_PBCFG_H_AR_RELEASE_MINOR_VERSION    6U
#define CMU_PBCFG_H_AR_RELEASE_REVISION_VERSION 0U
#define CMU_PBCFG_H_SW_MAJOR_VERSION            1U
#define CMU_PBCFG_H_SW_MINOR_VERSION            1U
#define CMU_PBCFG_H_SW_PATCH_VERSION            0U


/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

#define CMU_CONFIG_PB \
 extern const Cmu_ConfigType Cmu_Config;

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */



/**
* @brief Above high Threshold Interrupt callback function
*/
extern void CmuBusHighNotification(void);

/**
* @brief Above high Threshold Interrupt callback function
*/
extern void CmuFIRC64HighNotification(void);

/**
* @brief Above high Threshold Interrupt callback function
*/
extern void CmuLPO32KHighNotification(void);

/**
* @brief Below Low Threshold Interrupt callback function
*/
extern void CmuBusLowNotification(void);

/**
* @brief Below Low Threshold Interrupt callback function
*/
extern void CmuFIRC64LowNotification(void);

/**
* @brief Below Low Threshold Interrupt callback function
*/
extern void CmuLPO32KLowNotification(void);

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* #ifndef CMU_PBCFG_H */


/** @} end of group Cmu_Configuration */

/** @} end of group Cmu_Module */
