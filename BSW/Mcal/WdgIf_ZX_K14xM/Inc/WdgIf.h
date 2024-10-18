/**************************************************************************************************/
/**
 * @file      : WdgIf.h
 * @brief     : AUTOSAR Wdg Interface header file. It is a stub file. Integrators shall replace this file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/
#ifndef WDGIF_H
#define WDGIF_H

/** @addtogroup WdgIf_Module
 *  @{
 */

/** @addtogroup WdgIf
 *  @brief AUTOSAR WdgIf header file. It is a stub file.
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
#define WDGIF_VENDOR_ID                   0x00B3U
#define WDGIF_MODULE_ID                   43U
#define WDGIF_AR_RELEASE_MAJOR_VERSION    4U
#define WDGIF_AR_RELEASE_MINOR_VERSION    6U
#define WDGIF_AR_RELEASE_REVISION_VERSION 0U
#define WDGIF_SW_MAJOR_VERSION            1U
#define WDGIF_SW_MINOR_VERSION            2U
#define WDGIF_SW_PATCH_VERSION            1U

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */

/**
*   @brief  This enumerated type will contain the watchdog driver's possible modes
*/
typedef enum {
    WDGIF_OFF_MODE      = 0x00U,  /**< @brief  = 0x00 In this mode, the watchdog driver is disabled (switched off). */
    WDGIF_SLOW_MODE     = 0x01U,  /**< @brief  = 0x01 In this mode, the watchdog driver is set up for a long timeout period (slow triggering).*/
    WDGIF_FAST_MODE     = 0x02U   /**< @brief  = 0x02 In this mode, the watchdog driver is set up for a short timeout period (fast triggering).*/
} WdgIf_ModeType;

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

/** @} end of group WdgIf */

/** @} end of group WdgIf_Module */

#endif /* WDGIF_H */
