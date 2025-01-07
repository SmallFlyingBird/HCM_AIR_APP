/**************************************************************************************************/
/**
 * @file      : LinIf.h
 * @brief     : LinIf AUTOSAR level header file
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.2
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.
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
#include "LinIf_Types.h"
#include "LinIf_Cfg.h"
#include "LinTp.h"
#include "LinIf_MemMap.h"
#include "SchM_LinIf.h"
#include "LinIf.h"
#include "ComStack_Types.h"
#include "Ex_Lin.h"

/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define LINIF_VENDOR_ID                   0x00B3U
#define LINIF_MODULE_ID                   62U
#define LINIF_H_AR_RELEASE_MAJOR_VERSION    4U
#define LINIF_H_AR_RELEASE_MINOR_VERSION    6U
#define LINIF_H_AR_RELEASE_REVISION_VERSION 0U
#define LINIF_H_SW_MAJOR_VERSION            1U
#define LINIF_SW_MINOR_VERSION            2U
#define LINIF_H_SW_PATCH_VERSION            2U
/** @} end of Public_MacroDefinition */

/*instance id*/
#define LINIF_INSTANCE_ID (uint8)0x00
/** @} end of instance id */

/* Runtime errors */
#define LINIF_E_RESPONSE (uint8)0x60
#define LINIF_E_NC_NO_RESPONSE (uint8)0x61
/** @} end of Runtime errors */

/*service id*/
#define LINIF_INIT_ID (uint8)0x01
#define LINIF_GETVERSIONINFO_ID (uint8)0x03
#define LINIF_TRANSMIT_ID (uint8)0x04
#define LINIF_SCHEDULEREQUEST_ID (uint8)0x05
#define LINIF_GOTOSLEEP_ID (uint8)0x06
#define LINIF_WAKEUP_ID (uint8)0x07
#define LINIF_SETTRCVMODE_ID (uint8)0x08
#define LINIF_GETTRCVMODE_ID (uint8)0x09
#define LINIF_GETTRCVWAKEUPREASON_ID (uint8)0x0A
#define LINIF_SETTRCVWAKEUPREASON_ID (uint8)0x0B
#define LINIF_CANCELTRANSMIT_ID (uint8)0x0C
#define LINIF_CHECKWAKEUP_ID (uint8)0x60
#define LINIF_WAKEUPCONFIRMATION_ID (uint8)0x61
#define LINIF_MAINFUNCTION_ID (uint8)0x80
#define LINIF_GETPIDTABLE_ID (uint8)0x72
#define LINIF_SETPIDTABLE_ID (uint8)0x73
#define LINIF_GETCONFIGUREDNAD_ID (uint8)0x70
#define LINIF_SETCONFIGUREDNAD_ID (uint8)0x71
#define LINIF_HEADERINDICATION_ID (uint8)0x78
#define LINIF_RXINDICATION_ID (uint8)0x79
#define LINIF_TXCONFIRMATION_ID (uint8)0x7a
#define LINIF_LINERRORINDICATION_ID (uint8)0x7b
/** @} end of service id */
/** @defgroup Public_MacroDefinition
 *  @{
 */

/** @} end of Public_MacroDefinition */

/** @defgroup Public_TypeDefinition
 *  @{
 */
/** @} end of group Public_TypeDefinition */

/** @defgroup Global_VariableDeclaration
 *  @{
 */

/** @} end of group Global_VariableDeclaration */
extern CONST(Lin_DriverApiType, LINIF_CONST) Lin_DriverApi[];
extern CONST(LinIf_ConfigType, LINIF_CONST) LinIf_PCConfig;

/** @defgroup Public_FunctionDeclaration
 *  @{
 */
FUNC(void, LINIF_CODE)LinIf_Init(P2CONST(LinIf_ConfigType, AUTOMATIC, LINIF_APPL_CONST) ConfigPtr);
Std_ReturnType LinIf_CheckWakeup(EcuM_WakeupSourceType WakeupSource);
FUNC(Std_ReturnType, LINIF_CODE) LinIf_Wakeup(NetworkHandleType Channel);
void           LinIf_WakeupConfirmation(EcuM_WakeupSourceType WakeupSource);
Std_ReturnType LinIf_HeaderIndication(NetworkHandleType Channel, Lin_PduType *PduPtr);
void           LinIf_RxIndication(NetworkHandleType Channel, uint8 *Lin_SduPtr);
void           LinIf_TxConfirmation(NetworkHandleType Channel);
void           LinIf_LinErrorIndication(NetworkHandleType Channel, Lin_SlaveErrorType ErrorStatus);
/** @} end of group Public_FunctionDeclaration */
static FUNC(NetworkHandleType, LINIF_CODE) LinIf_GetLinIfChannel(NetworkHandleType channel);
static FUNC(NetworkHandleType, LINIF_CODE) LinIf_GetLinIfChannelByDriverChId(NetworkHandleType channel);
static FUNC(void, LINIF_CODE) LinIf_SlaveMainHandle(void);

#ifdef __cplusplus
}
#endif

/** @} end of group LinIf */

/** @} end of group LinIf_Module */

#endif /* LINIF_H */
