/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  @file       <Os_Extend.c>
 *  @brief      <>
 *
 * <Compiler: S32K    MCU:S32K344>
 *
 *  @author     <jiansen.zhao>
 *  @date       <04-01-2022>
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/
#include "Os_Extend.h"
#include "Os_Processor.h"
#include "Os_Internal.h"

/*=======[I N T E R N A L   D A T A]==========================================*/

/*=======[F U N C T I O N   I M P L E M E N T A T I O N S]====================*/
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
FUNC(osStackUsageType, OS_CODE) osGetStackUsage(osStackObject stack, uint16 id)
{
    osStackUsageType MaxUsage = 0;
    Os_StackPtrType ptr;
    Os_StackPtrType stackBottom;
    Os_StackPtrType stackTop;

    OS_ARCH_DECLARE_CRITICAL();

    id = Os_GetObjLocalId(id);

    switch (stack)
    {
    case OS_STACK_SYSTEM: {
        stackBottom = Os_SystemStack->stackBottom;
        stackTop = Os_SystemStack->stackTop;
    }
    break;

#if (CFG_TASK_MAX > 0U)
    case OS_STACK_TASK: {
        /* Input_para check. */
        if (id >= Os_CfgTaskMax)
        {
            return 0;
        }

        stackBottom = Os_TaskStack[id].stackBottom;
        stackTop = Os_TaskStack[id].stackTop;
    }
    break;
#endif

#if (CFG_ISR2_MAX > 0U)
    case OS_STACK_ISR2: {
        /* Input_para check. */
        if (id >= Os_CfgIsr2Max)
        {
            return 0;
        }

        stackBottom = Os_ISR2Stack[id].stackBottom;
        stackTop = Os_ISR2Stack[id].stackTop;
    }
    break;
#endif

    default:
        return 0;
    }

    OS_ARCH_ENTRY_CRITICAL();

    /*
     * MISRA-C:2004 Rule 17.4
     * Msg(4:0489) The integer value 1 is being added or subtracted from a pointer.
     */
    /* In stack storage area, all bytes are initialized to magic word(0xCC).
     * if this byte is used, the value will be changed. */
    for (ptr = stackBottom; ptr < stackTop; ptr++)
    {
        if (OS_STACK_FILL_PATTERN != (*ptr))
        {
            break;
        }
    }
    /* PRQA S 0488++ */ /* MISRA Rule 18.4 */
    MaxUsage = (osStackUsageType)(stackTop - ptr);
    /* PRQA S 0488-- */ /* MISRA Rule 18.4 */
    OS_ARCH_EXIT_CRITICAL();

    return MaxUsage;
}

/********************************************************************/
/*
 * Brief                <check ISR source>
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
FUNC(StatusType, OS_CODE) osCheckISRSource(uint32 Source) /* PRQA S 3408 */ /* MISRA Rule 8.4 */
{
    StatusType osRet = FALSE;

/* OS263. */
#if ((CFG_ISR2_MAX > 0) && (CFG_SC == OS_SC4))
    if (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel)
    {
        if (OS_ISR_CATEGORY2 == Os_IsrCfg[Os_IntCfgIsrId].OsIsrCatType)
        {
            if (Source == Os_IsrCfg[Os_IntCfgIsrId].OsIsrSrc)
            {
                osRet = TRUE;
            }
        }
    }
#else
    (void)Source;
#endif /* (CFG_ISR2_MAX > 0) && (CFG_SC == OS_SC4) */

    return osRet;
}

/********************************************************************/
/*
 * Brief                <Provide Version information to user.>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <Yes>
 * param-eventId[in]    <Versioninfo>
 * Param-Name[out]      <no>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * REQ ID               <None>
 */
/********************************************************************/
FUNC(void, OS_CODE) osGetVersionInfo(Std_VersionInfoType* osVerInfoPtr) /* PRQA S 3408 */ /* MISRA Rule 8.4 */
{
    if (NULL_PTR == osVerInfoPtr)
    {
        /*nothing to do*/
    }
    else
    {
        osVerInfoPtr->vendorID = OS_VENDOR_ID;
        osVerInfoPtr->moduleID = OS_MODULE_ID;
        /* osVerInfoPtr->instanceID = 0;*/
        osVerInfoPtr->sw_major_version = OS_CFG_H_SW_MAJOR_VERSION;
        osVerInfoPtr->sw_minor_version = OS_CFG_H_SW_MINOR_VERSION;
        osVerInfoPtr->sw_patch_version = OS_CFG_H_SW_PATCH_VERSION;
    }
}

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
FUNC(void, OS_CODE) osCheckCPUInformation(void)
{
    uint32 CPUID = 0u;

    StatusType osRet = TRUE;
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
