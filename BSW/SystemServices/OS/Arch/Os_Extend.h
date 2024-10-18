/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Os_Extend.h>
 *  @brief      <>
 *
 * <Compiler: S32K    MCU:S32K344>
 *
 *  @author     <jiansen.zhao>
 *  @date       <04-01-2022>
 */
/*============================================================================*/
/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>       <AUTHOR>          <REVISION LOG>
 *  V0.1.0      2021070705   jiansen.zhao     Initial version
 */
/*============================================================================*/
#ifndef OS_EXTEND_H
#define OS_EXTEND_H

/*=======[M I S R A C  R U L E  V I O L A T I O N]============================*/
/*  <MESSAGE ID>    <CODE LINE>    <REASON>
 */
/*============================================================================*/

/*=======[V E R S I O N  I N F O R M A T I O N]===============================*/
#define OS_EXTEND_H_VENDOR_ID        0
#define OS_EXTEND_H_MODULE_ID        0
#define OS_EXTEND_H_AR_MAJOR_VERSION 4
#define OS_EXTEND_H_AR_MINOR_VERSION 5
#define OS_EXTEND_H_AR_PATCH_VERSION 0
#define OS_EXTEND_H_SW_MAJOR_VERSION 0
#define OS_EXTEND_H_SW_MINOR_VERSION 1
#define OS_EXTEND_H_SW_PATCH_VERSION 0
#define OS_EXTEND_H_VENDOR_API_INFIX 0

/*=======[I N C L U D E S]====================================================*/
#include "Os_Types.h"

/*=======[M A C R O S]========================================================*/
typedef uint32 osStackUsageType;
typedef uint32 osCsaUsageType;
typedef enum
{
    OS_STACK_SYSTEM = 0U,
    OS_STACK_TASK = 1U,
    OS_STACK_ISR2 = 2U
} osStackObject;

/*=======[E X T E R N A L   D A T A]==========================================*/

/*=======[F U N C T I O N   D E C L A R A T I O N S]========*/
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/********************************************************************/
/*
 * Brief                 <Get max usage of system,task,ISR2 stack.>
 * Service ID            <none>
 * Sync/Async            <none>
 * Reentrancy            <Yes>
 * param-eventId[in]     <id>
 * Param-Name[out]       <None>
 * Param-Name[in/out]    <None>
 * return                <osStackUsageType>
 * PreCondition          <None>
 *
 * Revision History:
 *
 *   1. 2016-07-27: ***; Initial version, add this function.
 */
/********************************************************************/
FUNC(osStackUsageType, OS_CODE) osGetStackUsage(osStackObject stack, uint16 id);

/********************************************************************/
/*
 * Brief                <check whether CPU information is correct.>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <Yes>
 * param-eventId[in]    <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <StatusType>
 * PreCondition         <None>
 * REQ ID               <None>
 */
/********************************************************************/
FUNC(void, OS_CODE) osCheckCPUInformation(void);

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /* #ifndef OS_EXTEND_H */

/*=======[E N D   O F   F I L E]==============================================*/
