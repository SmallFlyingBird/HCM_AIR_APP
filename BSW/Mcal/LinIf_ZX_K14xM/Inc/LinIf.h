/**************************************************************************************************/
/**
 * @file      : LinIf.h
 * @brief     : LinIf AUTOSAR level header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef LIN_IF_H
#define LIN_IF_H

/** @addtogroup  LinIf_Module
 *  @{
 */

/** @addtogroup LinIf
 *  @brief LinIf AUTOSAR level
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif


#include "Lin_GeneralTypes.h"
#include "EcuM.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define LINIF_VENDOR_ID                   0x00B3U
#define LINIF_MODULE_ID                   62U
#define LINIF_AR_RELEASE_MAJOR_VERSION    4U
#define LINIF_AR_RELEASE_MINOR_VERSION    6U
#define LINIF_AR_RELEASE_REVISION_VERSION 0U
#define LINIF_SW_MAJOR_VERSION            1U
#define LINIF_SW_MINOR_VERSION            2U
#define LINIF_SW_PATCH_VERSION            1U
/** @} end of Public_MacroDefinition */

/** @defgroup Public_MacroDefinition
 *  @{
 */

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */
#define LINIF_WAKEUP_SUPPORT (STD_ON)
typedef uint8  NetworkHandleType;
/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
Std_ReturnType LinIf_CheckWakeup(EcuM_WakeupSourceType WakeupSource);

void           LinIf_WakeupConfirmation(EcuM_WakeupSourceType WakeupSource);
Std_ReturnType LinIf_HeaderIndication(NetworkHandleType Channel, Lin_PduType *PduPtr);
void           LinIf_RxIndication(NetworkHandleType Channel, uint8 *Lin_SduPtr);
void           LinIf_TxConfirmation(NetworkHandleType Channel);
void           LinIf_LinErrorIndication(NetworkHandleType Channel, Lin_SlaveErrorType ErrorStatus);
/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group LinIf */

/** @} end of group LinIf_Module */

#endif /* LINIF_H */
