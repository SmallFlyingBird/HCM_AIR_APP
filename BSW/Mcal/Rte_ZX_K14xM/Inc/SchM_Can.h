/**************************************************************************************************/
/**
 * @file      : SchM_Can.h
 * @brief     : AUTOSAR RTE header file. It is a stub file. Integrators shall replace this file.
 *              - Platform: Z20K14xM
 *              - Autosar Version: 4.6.0
 * @version   : 1.2.1
 * @author    : Zhixin Semiconductor
 * @note      : None
 *
 * @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.
 **************************************************************************************************/

#ifndef SCHM_CAN_H
#define SCHM_CAN_H

/** @addtogroup Rte_Module
 *  @{
 */

/** @addtogroup SchM_Can
 *  @brief Can schedule manager header file. This is a stub file.
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif
/** @defgroup Public_MacroDefinition
 *  @{
 */
/* Published information */
#define SCHM_CAN_H_VENDOR_ID                   0x00B3U
#define SCHM_CAN_H_AR_RELEASE_MAJOR_VERSION    4U
#define SCHM_CAN_H_AR_RELEASE_MINOR_VERSION    6U
#define SCHM_CAN_H_AR_RELEASE_REVISION_VERSION 0U
#define SCHM_CAN_H_SW_MAJOR_VERSION            1U
#define SCHM_CAN_H_SW_MINOR_VERSION            2U
#define SCHM_CAN_H_SW_PATCH_VERSION            1U

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
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"


extern void SchM_Enter_Can_DisableIntGlobal(void);
extern void SchM_Exit_Can_DisableIntGlobal(void);

extern void SchM_Enter_Can_DisableModule(void);
extern void SchM_Exit_Can_DisableModule(void);

extern void SchM_Enter_Can_DisableClock(void);
extern void SchM_Exit_Can_DisableClock(void);

extern void SchM_Enter_Can_SetStandardBitTiming(void);
extern void SchM_Exit_Can_SetStandardBitTiming(void);

extern void SchM_Enter_Can_ConfigFdDataBitTiming(void);
extern void SchM_Exit_Can_ConfigFdDataBitTiming(void);

extern void SchM_Enter_Can_ConfigFdCompensation(void);
extern void SchM_Exit_Can_ConfigFdCompensation(void);

extern void SchM_Enter_Can_SetTxArbitrationDelay(void);
extern void SchM_Exit_Can_SetTxArbitrationDelay(void);

extern void SchM_Enter_Can_InterMaskBuff(void);
extern void SchM_Exit_Can_InterMaskBuff(void);

extern void SchM_Enter_Can_ConfigTimeStamp(void);
extern void SchM_Exit_Can_ConfigTimeStamp(void);

extern void SchM_Enter_Can_RecoveryBusOff(void);
extern void SchM_Exit_Can_RecoveryBusOff(void);

extern void SchM_Enter_Can_CanCtl1Reg(void);
extern void SchM_Exit_Can_CanCtl1Reg(void);

extern void SchM_Enter_Can_CanCtl2Reg(void);
extern void SchM_Exit_Can_CanCtl2Reg(void);

extern void SchM_Enter_Can_CanMcrReg(void);
extern void SchM_Exit_Can_CanMcrReg(void);

extern void SchM_Enter_Can_CanMecrReg(void);
extern void SchM_Exit_Can_CanMecrReg(void);

extern void SchM_Enter_Can_CanRxmgMskReg(void);
extern void SchM_Exit_Can_CanRxmgMskReg(void);

extern void SchM_Enter_Can_SetFdArbitrationBitTiming(void);
extern void SchM_Exit_Can_SetFdArbitrationBitTiming(void);

extern void SchM_Enter_Can_SetSelfWakeup(void);
extern void SchM_Exit_Can_SetSelfWakeup(void);

#ifdef CAN_MAINFUNCTION_MULTIPLE_WRITE
#if (CAN_MAINFUNCTION_MULTIPLE_WRITE == STD_ON)
#ifdef CAN_MAINFUNCTION_WRITE_PERIOD_0
extern void Can_MainFunction_Write_0(void);
#endif

#ifdef CAN_MAINFUNCTION_WRITE_PERIOD_1
extern void Can_MainFunction_Write_1(void);
#endif

#ifdef CAN_MAINFUNCTION_WRITE_PERIOD_2
extern void Can_MainFunction_Write_2(void);
#endif

#ifdef CAN_MAINFUNCTION_WRITE_PERIOD_3
extern void Can_MainFunction_Write_3(void);
#endif

#ifdef CAN_MAINFUNCTION_WRITE_PERIOD_4
extern void Can_MainFunction_Write_4(void);
#endif

#ifdef CAN_MAINFUNCTION_WRITE_PERIOD_5
extern void Can_MainFunction_Write_5(void);
#endif

#ifdef CAN_MAINFUNCTION_WRITE_PERIOD_6
extern void Can_MainFunction_Write_6(void);
#endif

#ifdef CAN_MAINFUNCTION_WRITE_PERIOD_7
extern void Can_MainFunction_Write_7(void);
#endif

#ifdef CAN_MAINFUNCTION_WRITE_PERIOD_8
extern void Can_MainFunction_Write_8(void);
#endif

#ifdef CAN_MAINFUNCTION_WRITE_PERIOD_9
extern void Can_MainFunction_Write_9(void);
#endif

#ifdef CAN_MAINFUNCTION_WRITE_PERIOD_10
extern void Can_MainFunction_Write_10(void);
#endif

#endif
#endif

#ifdef CAN_MAINFUNCTION_MULTIPLE_READ
#if (CAN_MAINFUNCTION_MULTIPLE_READ == STD_ON)
#ifdef CAN_MAINFUNCTION_READ_PERIOD_0
extern void Can_MainFunction_Read_0(void);
#endif

#ifdef CAN_MAINFUNCTION_READ_PERIOD_1
extern void Can_MainFunction_Read_1(void);
#endif

#ifdef CAN_MAINFUNCTION_READ_PERIOD_2
extern void Can_MainFunction_Read_2(void);
#endif

#ifdef CAN_MAINFUNCTION_READ_PERIOD_3
extern void Can_MainFunction_Read_3(void);
#endif

#ifdef CAN_MAINFUNCTION_READ_PERIOD_4
extern void Can_MainFunction_Read_4(void);
#endif

#ifdef CAN_MAINFUNCTION_READ_PERIOD_5
extern void Can_MainFunction_Read_5(void);
#endif

#ifdef CAN_MAINFUNCTION_READ_PERIOD_6
extern void Can_MainFunction_Read_6(void);
#endif

#ifdef CAN_MAINFUNCTION_READ_PERIOD_7
extern void Can_MainFunction_Read_7(void);
#endif

#ifdef CAN_MAINFUNCTION_READ_PERIOD_8
extern void Can_MainFunction_Read_8(void);
#endif

#ifdef CAN_MAINFUNCTION_READ_PERIOD_9
extern void Can_MainFunction_Read_9(void);
#endif

#ifdef CAN_MAINFUNCTION_READ_PERIOD_10
extern void Can_MainFunction_Read_10(void);
#endif

#endif
#endif

extern void Can_MainFunction_BusOff(void);

#ifdef CAN_MAINFUNCTION_MULTIPLE_WRITE
#if (CAN_MAINFUNCTION_MULTIPLE_WRITE == STD_OFF)
extern void Can_MainFunction_Write(void);
#endif
#endif

#ifdef CAN_MAINFUNCTION_MULTIPLE_READ
#if (CAN_MAINFUNCTION_MULTIPLE_READ == STD_OFF)
extern void Can_MainFunction_Read(void);
#endif
#endif

#ifdef CAN_WAKEUP_POLLING_SUPPORT
#if (CAN_WAKEUP_POLLING_SUPPORT == STD_ON)
extern void Can_MainFunction_Wakeup(void);
#endif
#endif

extern void Can_MainFunction_Mode(void);

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/** @} end of group Public_FunctionDeclaration */

#ifdef __cplusplus
}
#endif

/** @} end of group SchM_Can*/

/** @} end of group Rte_Module */

#endif /* SCHM_CAN_H */
