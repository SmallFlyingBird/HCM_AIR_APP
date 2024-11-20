/**************************************************************************************************/
/**
 * @file      : EcuM.h
 * @brief     : AUTOSAR EcuM header file. It is a stub file. Integrators shall replace this file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef ECUM_H
#define ECUM_H

/** @addtogroup EcuM_Module
 *  @{
 */

/** @addtogroup EcuM
 *  @brief AUTOSAR EcuM header file. It is a stub file.
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */

/* Published information */
#define ECUM_VENDOR_ID                   0x00B3U
#define ECUM_MODULE_ID                   10U
#define ECUM_AR_RELEASE_MAJOR_VERSION    4U
#define ECUM_AR_RELEASE_MINOR_VERSION    6U
#define ECUM_AR_RELEASE_REVISION_VERSION 0U
#define ECUM_SW_MAJOR_VERSION            1U
#define ECUM_SW_MINOR_VERSION            2U
#define ECUM_SW_PATCH_VERSION            2U

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
 * @brief Defines a bitfield with 5 pre-defined positions. The bitfield provides one bit for each
 * wakeup source.
 */
typedef uint32 EcuM_WakeupSourceType;

/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/**
 * @brief last wakeup event to EcuM.
 */
extern EcuM_WakeupSourceType EcuMLastWakeupEvent;

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */

/**
* @brief     This function sets the wakeup event of the ECUM.
* 
* @param[in] sources  wakeup source to be set
* 
*/
void EcuM_SetWakeupEvent(EcuM_WakeupSourceType sources);

/**
* @brief     This function validates the wakeup event.
* 
* @param[in] sources: wakeup source to be validated
*/
void EcuM_ValidateWakeupEvent(EcuM_WakeupSourceType sources);

/**
* @brief     This function checks the wakeup source against possible sources of wakeup.
* @details   This is a function stub only.
* 
* @param[in] WakeupSource: wakeup source ID
* 
*/
void EcuM_CheckWakeup(EcuM_WakeupSourceType WakeupSource);

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group EcuM */

/** @} end of group EcuM_Module */

#endif /* ECUM_H */
