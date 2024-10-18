/*===========================================================================*/
/*  Copyright (C) 2020, iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *
 *  All rights reserved. This software is iSOFT property. Duplication
 *  or disclosure without iSOFT written authorization is prohibited.
 *
 *  file       <Os_Mpu.h>
 *  brief      <>
 *
 * <Compiler: S32K    MCU:S32K14X>
 *
 *  author     <xiaohong.hu>
 *  date       <05-12-2020>
 */
/*===========================================================================*/

/*=======[R E V I S I O N   H I S T O R Y]===================================*/
/*  <VERSION>    <DATE>    <AUTHOR>    		<REVISION LOG>
 *  V0.1.0       20201205  xiaohong.hu     	Initial version
 */
/*===========================================================================*/

/*=======[M I S R A C  R U L E  V I O L A T I O N]===========================*/
/*  <MESSAGE ID>    <CODE LINE>    <REASON>
 */
/*===========================================================================*/
/*=======[I N C L U D E S]===================================================*/
#include "Os.h"
#include "Os_Processor.h"
#include "Os_Internal.h"
#include "smpu_drv_os.h"


/*=======[V E R S I O N  C H E C K]==========================================*/


/*=======[M A C R O S]=======================================================*/
#define SMPU_MASTER_CACHE          SMPU_BUS_MASTER_0
#define SMPU_MASTER_CORE           SMPU_BUS_MASTER_0
#define SMPU_MASTER_DMA            SMPU_BUS_MASTER_2

/*=======[E X T E R N A L   D A T A]=========================================*/

/*=======[E X C I P T I O N]==================================================*/
#define OS_START_SEC_CODE
#include "Os_MemMap.h"

/* For memory protection. */
#if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
/******************************************************************************/
/*
 * Brief                <In MPU default Configuration, All permissions are
 *                      allowed in privilege mode and User mode>
 * Service ID           <Os_ArchMpDefaultConfigSwitch>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <StatusType>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <None>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ArchMpDefaultConfigSwitch(void)
{
    SMPU_Disable();

    SMPU_MemoryRegionConfigDisable(SMPU_MEMORY_REGION_0);
    SMPU_MemoryRegionRange(SMPU_MEMORY_REGION_0, (uint32)0x00000000u, (uint32)0xFFFFFFFFu);
    SMPU_BusMstUserModeExeControl(SMPU_MEMORY_REGION_0, SMPU_MASTER_CORE, SMPU_ENABLE);
    SMPU_BusMstUserModeWriteControl(SMPU_MEMORY_REGION_0, SMPU_MASTER_CORE, SMPU_ENABLE);
    SMPU_BusMstUserModeReadControl(SMPU_MEMORY_REGION_0, SMPU_MASTER_CORE, SMPU_ENABLE);
    SMPU_BusMstSvrModeAccessControl(SMPU_MEMORY_REGION_0, SMPU_MASTER_CORE, SMPU_ALL_ALLOWED);
    SMPU_MemoryRegionConfigEnable(SMPU_MEMORY_REGION_0);

    SMPU_MemoryRegionRange(SMPU_MEMORY_REGION_1, (uint32)PFLASH_START, (uint32)PFLASH_END);
    SMPU_BusMstUserModeExeControl(SMPU_MEMORY_REGION_1, SMPU_MASTER_CORE, SMPU_ENABLE);
    SMPU_BusMstUserModeWriteControl(SMPU_MEMORY_REGION_1, SMPU_MASTER_CORE, SMPU_ENABLE);
    SMPU_BusMstUserModeReadControl(SMPU_MEMORY_REGION_1, SMPU_MASTER_CORE, SMPU_ENABLE);
    SMPU_BusMstSvrModeAccessControl(SMPU_MEMORY_REGION_1, SMPU_MASTER_CORE, SMPU_ALL_ALLOWED);
    SMPU_MemoryRegionConfigEnable(SMPU_MEMORY_REGION_1);

    SMPU_MemoryRegionRange(SMPU_MEMORY_REGION_2, (uint32)SRAM_START, (uint32)SRAM_END);
    SMPU_BusMstUserModeExeControl(SMPU_MEMORY_REGION_2, SMPU_MASTER_CORE, SMPU_ENABLE);
    SMPU_BusMstUserModeWriteControl(SMPU_MEMORY_REGION_2, SMPU_MASTER_CORE, SMPU_ENABLE);
    SMPU_BusMstUserModeReadControl(SMPU_MEMORY_REGION_2, SMPU_MASTER_CORE, SMPU_ENABLE);
    SMPU_BusMstSvrModeAccessControl(SMPU_MEMORY_REGION_2, SMPU_MASTER_CORE, SMPU_ALL_ALLOWED);
    SMPU_MemoryRegionConfigEnable(SMPU_MEMORY_REGION_2);

    SMPU_MemoryRegionRange(SMPU_MEMORY_REGION_3, (uint32)PERIPHERAL_START, (uint32)PERIPHERAL_END);
    SMPU_BusMstUserModeExeControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_ENABLE);
    SMPU_BusMstUserModeWriteControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_ENABLE);
    SMPU_BusMstUserModeReadControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_ENABLE);
    SMPU_BusMstSvrModeAccessControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_ALL_ALLOWED);
    SMPU_MemoryRegionConfigEnable(SMPU_MEMORY_REGION_3);

    SMPU_Enable();
}

/******************************************************************************/
/*
 * Brief                <In MPU Trust Task Configuration, All permissions are
 *                      allowed in privilege mode ,but in user mode,Peripheral is restrict>
 * Service ID           <Os_ArchMpTrustTaskThreadSwitch>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <StatusType>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <None>
 */
/******************************************************************************/
/* PRQA S 0306++ */ /* MISRA Rule 11.4 */
static FUNC(void, OS_CODE) Os_ArchMpTrustTaskThreadSwitch(TaskType TaskId, ApplicationType HostAppId)
{
    SMPU_Disable();

    SMPU_MemoryRegionRange(SMPU_MEMORY_REGION_0, (uint32)PFLASH_START, (uint32)PFLASH_END);
    SMPU_BusMstUserModeExeControl(SMPU_MEMORY_REGION_0, SMPU_MASTER_CORE, SMPU_ENABLE);
    SMPU_BusMstUserModeWriteControl(SMPU_MEMORY_REGION_0, SMPU_MASTER_CORE, SMPU_ENABLE);
    SMPU_BusMstUserModeReadControl(SMPU_MEMORY_REGION_0, SMPU_MASTER_CORE, SMPU_ENABLE);
    SMPU_BusMstSvrModeAccessControl(SMPU_MEMORY_REGION_0, SMPU_MASTER_CORE, SMPU_ALL_ALLOWED);
    SMPU_MemoryRegionConfigEnable(SMPU_MEMORY_REGION_0);

    SMPU_MemoryRegionRange(SMPU_MEMORY_REGION_1, (uint32)SRAM_START,  (uint32)Os_Core_App_DAddr[0].APP_ADDR_START);
    SMPU_BusMstUserModeExeControl(SMPU_MEMORY_REGION_1, SMPU_MASTER_CORE, SMPU_ENABLE);
    SMPU_BusMstUserModeWriteControl(SMPU_MEMORY_REGION_1, SMPU_MASTER_CORE, SMPU_ENABLE);
    SMPU_BusMstUserModeReadControl(SMPU_MEMORY_REGION_1, SMPU_MASTER_CORE, SMPU_ENABLE);
    SMPU_BusMstSvrModeAccessControl(SMPU_MEMORY_REGION_1, SMPU_MASTER_CORE, SMPU_ALL_ALLOWED);
    SMPU_MemoryRegionConfigEnable(SMPU_MEMORY_REGION_1);

    if (Os_AppPriDataAddr[HostAppId].APP_ADDR_START < Os_AppPriDataAddr[HostAppId].APP_ADDR_END){
        SMPU_MemoryRegionRange(SMPU_MEMORY_REGION_2, (uint32)Os_AppPriDataAddr[HostAppId].APP_ADDR_START, (uint32)Os_AppPriDataAddr[HostAppId].APP_ADDR_END);
        SMPU_BusMstUserModeExeControl(SMPU_MEMORY_REGION_2, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstUserModeWriteControl(SMPU_MEMORY_REGION_2, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstUserModeReadControl(SMPU_MEMORY_REGION_2, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstSvrModeAccessControl(SMPU_MEMORY_REGION_2, SMPU_MASTER_CORE, SMPU_ALL_ALLOWED);
        SMPU_MemoryRegionConfigEnable(SMPU_MEMORY_REGION_2);

        SMPU_MemoryRegionRange(SMPU_MEMORY_REGION_3, (uint32)Os_TaskDAddr[TaskId].Task_ADDR_START, (uint32)Os_TaskDAddr[TaskId].Task_ADDR_END);
        SMPU_BusMstUserModeExeControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstUserModeWriteControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstUserModeReadControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstSvrModeAccessControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_ALL_ALLOWED);
        SMPU_MemoryRegionConfigEnable(SMPU_MEMORY_REGION_3);

        SMPU_MemoryRegionRange(SMPU_MEMORY_REGION_4, (uint32)PERIPHERAL_START, (uint32)PERIPHERAL_END);
        SMPU_BusMstUserModeExeControl(SMPU_MEMORY_REGION_4, SMPU_MASTER_CORE, SMPU_DISABLE);
        SMPU_BusMstUserModeWriteControl(SMPU_MEMORY_REGION_4, SMPU_MASTER_CORE, SMPU_DISABLE);
        SMPU_BusMstUserModeReadControl(SMPU_MEMORY_REGION_4, SMPU_MASTER_CORE, SMPU_DISABLE);
        SMPU_BusMstSvrModeAccessControl(SMPU_MEMORY_REGION_4, SMPU_MASTER_CORE, SMPU_ALL_ALLOWED);
        SMPU_MemoryRegionConfigEnable(SMPU_MEMORY_REGION_4);
    } else {
        SMPU_MemoryRegionRange(SMPU_MEMORY_REGION_2, (uint32)Os_TaskDAddr[TaskId].Task_ADDR_START, (uint32)Os_TaskDAddr[TaskId].Task_ADDR_END);
        SMPU_BusMstUserModeExeControl(SMPU_MEMORY_REGION_2, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstUserModeWriteControl(SMPU_MEMORY_REGION_2, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstUserModeReadControl(SMPU_MEMORY_REGION_2, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstSvrModeAccessControl(SMPU_MEMORY_REGION_2, SMPU_MASTER_CORE, SMPU_ALL_ALLOWED);
        SMPU_MemoryRegionConfigEnable(SMPU_MEMORY_REGION_2);

        SMPU_MemoryRegionRange(SMPU_MEMORY_REGION_3, (uint32)PERIPHERAL_START, (uint32)PERIPHERAL_END);
        SMPU_BusMstUserModeExeControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_DISABLE);
        SMPU_BusMstUserModeWriteControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_DISABLE);
        SMPU_BusMstUserModeReadControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_DISABLE);
        SMPU_BusMstSvrModeAccessControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_ALL_ALLOWED);
        SMPU_MemoryRegionConfigEnable(SMPU_MEMORY_REGION_3);

        SMPU_MemoryRegionConfigDisable(SMPU_MEMORY_REGION_4);
    }

    SMPU_Enable();
}

/******************************************************************************/
/*
 * Brief                <In MPU No Trust Task Configuration, All permissions are
 *                      allowed in privilege mode ,but in user mode,it has some restrict>
 * Service ID           <Os_ArchMpNonTrustTaskThreadSwitch>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <StatusType>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <None>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_ArchMpNonTrustTaskThreadSwitch(TaskType TaskId, ApplicationType HostAppId)
{
    SMPU_Disable();

    SMPU_MemoryRegionConfigDisable(SMPU_MEMORY_REGION_0);
    SMPU_MemoryRegionRange(SMPU_MEMORY_REGION_0, (uint32)0x00000000u, (uint32)0xFFFFFFFFu);
    SMPU_BusMstUserModeExeControl(SMPU_MEMORY_REGION_0, SMPU_MASTER_CORE, SMPU_DISABLE);
    SMPU_BusMstUserModeWriteControl(SMPU_MEMORY_REGION_0, SMPU_MASTER_CORE, SMPU_DISABLE);
    SMPU_BusMstUserModeReadControl(SMPU_MEMORY_REGION_0, SMPU_MASTER_CORE, SMPU_DISABLE);
    SMPU_BusMstSvrModeAccessControl(SMPU_MEMORY_REGION_0, SMPU_MASTER_CORE, SMPU_ALL_ALLOWED);
    SMPU_MemoryRegionConfigEnable(SMPU_MEMORY_REGION_0);

    SMPU_MemoryRegionRange(SMPU_MEMORY_REGION_1, (uint32)PFLASH_START, (uint32)PFLASH_END);
    SMPU_BusMstUserModeExeControl(SMPU_MEMORY_REGION_1, SMPU_MASTER_CORE, SMPU_ENABLE);
    SMPU_BusMstUserModeWriteControl(SMPU_MEMORY_REGION_1, SMPU_MASTER_CORE, SMPU_ENABLE);
    SMPU_BusMstUserModeReadControl(SMPU_MEMORY_REGION_1, SMPU_MASTER_CORE, SMPU_ENABLE);
    SMPU_BusMstSvrModeAccessControl(SMPU_MEMORY_REGION_1, SMPU_MASTER_CORE, SMPU_ALL_ALLOWED);
    SMPU_MemoryRegionConfigEnable(SMPU_MEMORY_REGION_1);

    SMPU_MemoryRegionRange(SMPU_MEMORY_REGION_2, (uint32)SRAM_START, (uint32)Os_Core_App_DAddr[0].APP_ADDR_START);
    SMPU_BusMstUserModeExeControl(SMPU_MEMORY_REGION_2, SMPU_MASTER_CORE, SMPU_DISABLE);
    SMPU_BusMstUserModeWriteControl(SMPU_MEMORY_REGION_2, SMPU_MASTER_CORE, SMPU_DISABLE);
    SMPU_BusMstUserModeReadControl(SMPU_MEMORY_REGION_2, SMPU_MASTER_CORE, SMPU_DISABLE);
    SMPU_BusMstSvrModeAccessControl(SMPU_MEMORY_REGION_2, SMPU_MASTER_CORE, SMPU_ALL_ALLOWED);
    SMPU_MemoryRegionConfigEnable(SMPU_MEMORY_REGION_2);

    if (Os_AppPriDataAddr[HostAppId].APP_ADDR_START < Os_AppPriDataAddr[HostAppId].APP_ADDR_END)
    {
        SMPU_MemoryRegionRange(SMPU_MEMORY_REGION_3, (uint32)Os_AppPriDataAddr[HostAppId].APP_ADDR_START, (uint32)Os_AppPriDataAddr[HostAppId].APP_ADDR_END);
        SMPU_BusMstUserModeExeControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstUserModeWriteControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstUserModeReadControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstSvrModeAccessControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_ALL_ALLOWED);
        SMPU_MemoryRegionConfigEnable(SMPU_MEMORY_REGION_3);

        SMPU_MemoryRegionRange(SMPU_MEMORY_REGION_4, (uint32)Os_TaskDAddr[TaskId].Task_ADDR_START, (uint32)Os_TaskDAddr[TaskId].Task_ADDR_END);
        SMPU_BusMstUserModeExeControl(SMPU_MEMORY_REGION_4, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstUserModeWriteControl(SMPU_MEMORY_REGION_4, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstUserModeReadControl(SMPU_MEMORY_REGION_4, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstSvrModeAccessControl(SMPU_MEMORY_REGION_4, SMPU_MASTER_CORE, SMPU_ALL_ALLOWED);
        SMPU_MemoryRegionConfigEnable(SMPU_MEMORY_REGION_4);

        SMPU_MemoryRegionRange(SMPU_MEMORY_REGION_5, (uint32)PERIPHERAL_START, (uint32)PERIPHERAL_END);
        SMPU_BusMstUserModeExeControl(SMPU_MEMORY_REGION_5, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstUserModeWriteControl(SMPU_MEMORY_REGION_5, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstUserModeReadControl(SMPU_MEMORY_REGION_5, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstSvrModeAccessControl(SMPU_MEMORY_REGION_5, SMPU_MASTER_CORE, SMPU_ALL_ALLOWED);
        SMPU_MemoryRegionConfigEnable(SMPU_MEMORY_REGION_5);
    } else {
        SMPU_MemoryRegionRange(SMPU_MEMORY_REGION_3, (uint32)Os_TaskDAddr[TaskId].Task_ADDR_START, (uint32)Os_TaskDAddr[TaskId].Task_ADDR_END);
        SMPU_BusMstUserModeExeControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstUserModeWriteControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstUserModeReadControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstSvrModeAccessControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_ALL_ALLOWED);
        SMPU_MemoryRegionConfigEnable(SMPU_MEMORY_REGION_3);

        SMPU_MemoryRegionRange(SMPU_MEMORY_REGION_4, (uint32)PERIPHERAL_START, (uint32)PERIPHERAL_END);
        SMPU_BusMstUserModeExeControl(SMPU_MEMORY_REGION_4, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstUserModeWriteControl(SMPU_MEMORY_REGION_4, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstUserModeReadControl(SMPU_MEMORY_REGION_4, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstSvrModeAccessControl(SMPU_MEMORY_REGION_4, SMPU_MASTER_CORE, SMPU_ALL_ALLOWED);
        SMPU_MemoryRegionConfigEnable(SMPU_MEMORY_REGION_4);

        SMPU_MemoryRegionConfigDisable(SMPU_MEMORY_REGION_5);
    }

    SMPU_Enable();
}

/******************************************************************************/
/*
 * Brief                <In MPU Trust Isr Configuration, All permissions are
 *                      allowed in privilege mode ,but in user mode,it has some restrict>
 * Service ID           <Os_ArchMpTrustIsrThreadSwitch>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <StatusType>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <None>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_ArchMpTrustIsrThreadSwitch(ISRType IsrId, ApplicationType HostAppId)
{
    SMPU_Disable();

    SMPU_MemoryRegionRange(SMPU_MEMORY_REGION_0, (uint32)PFLASH_START, (uint32)PFLASH_END);
    SMPU_BusMstUserModeExeControl(SMPU_MEMORY_REGION_0, SMPU_MASTER_CORE, SMPU_ENABLE);
    SMPU_BusMstUserModeWriteControl(SMPU_MEMORY_REGION_0, SMPU_MASTER_CORE, SMPU_ENABLE);
    SMPU_BusMstUserModeReadControl(SMPU_MEMORY_REGION_0, SMPU_MASTER_CORE, SMPU_ENABLE);
    SMPU_BusMstSvrModeAccessControl(SMPU_MEMORY_REGION_0, SMPU_MASTER_CORE, SMPU_ALL_ALLOWED);
    SMPU_MemoryRegionConfigEnable(SMPU_MEMORY_REGION_0);

    SMPU_MemoryRegionRange(SMPU_MEMORY_REGION_1, (uint32)SRAM_START, (uint32)Os_Core_App_DAddr[0].APP_ADDR_START);
    SMPU_BusMstUserModeExeControl(SMPU_MEMORY_REGION_1, SMPU_MASTER_CORE, SMPU_ENABLE);
    SMPU_BusMstUserModeWriteControl(SMPU_MEMORY_REGION_1, SMPU_MASTER_CORE, SMPU_ENABLE);
    SMPU_BusMstUserModeReadControl(SMPU_MEMORY_REGION_1, SMPU_MASTER_CORE, SMPU_ENABLE);
    SMPU_BusMstSvrModeAccessControl(SMPU_MEMORY_REGION_1, SMPU_MASTER_CORE, SMPU_ALL_ALLOWED);
    SMPU_MemoryRegionConfigEnable(SMPU_MEMORY_REGION_1);

    if (Os_AppPriDataAddr[HostAppId].APP_ADDR_START < Os_AppPriDataAddr[HostAppId].APP_ADDR_END) {
        SMPU_MemoryRegionRange(SMPU_MEMORY_REGION_2, (uint32)Os_AppPriDataAddr[HostAppId].APP_ADDR_START, (uint32)Os_AppPriDataAddr[HostAppId].APP_ADDR_END);
        SMPU_BusMstUserModeExeControl(SMPU_MEMORY_REGION_2, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstUserModeWriteControl(SMPU_MEMORY_REGION_2, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstUserModeReadControl(SMPU_MEMORY_REGION_2, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstSvrModeAccessControl(SMPU_MEMORY_REGION_2, SMPU_MASTER_CORE, SMPU_ALL_ALLOWED);
        SMPU_MemoryRegionConfigEnable(SMPU_MEMORY_REGION_2);

        SMPU_MemoryRegionRange(SMPU_MEMORY_REGION_3, (uint32)Os_IsrDAddr[IsrId].ISR_ADDR_START, (uint32)Os_IsrDAddr[IsrId].ISR_ADDR_END);
        SMPU_BusMstUserModeExeControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstUserModeWriteControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstUserModeReadControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstSvrModeAccessControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_ALL_ALLOWED);
        SMPU_MemoryRegionConfigEnable(SMPU_MEMORY_REGION_3);

        SMPU_MemoryRegionRange(SMPU_MEMORY_REGION_4, (uint32)PERIPHERAL_START, (uint32)PERIPHERAL_END);
        SMPU_BusMstUserModeExeControl(SMPU_MEMORY_REGION_4, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstUserModeWriteControl(SMPU_MEMORY_REGION_4, SMPU_MASTER_CORE, SMPU_DISABLE);
        SMPU_BusMstUserModeReadControl(SMPU_MEMORY_REGION_4, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstSvrModeAccessControl(SMPU_MEMORY_REGION_4, SMPU_MASTER_CORE, SMPU_ALL_ALLOWED);
        SMPU_MemoryRegionConfigEnable(SMPU_MEMORY_REGION_4);
    } else {
        SMPU_MemoryRegionRange(SMPU_MEMORY_REGION_2, (uint32)Os_IsrDAddr[IsrId].ISR_ADDR_START, (uint32)Os_IsrDAddr[IsrId].ISR_ADDR_END);
        SMPU_BusMstUserModeExeControl(SMPU_MEMORY_REGION_2, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstUserModeWriteControl(SMPU_MEMORY_REGION_2, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstUserModeReadControl(SMPU_MEMORY_REGION_2, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstSvrModeAccessControl(SMPU_MEMORY_REGION_2, SMPU_MASTER_CORE, SMPU_ALL_ALLOWED);
        SMPU_MemoryRegionConfigEnable(SMPU_MEMORY_REGION_2);

        SMPU_MemoryRegionRange(SMPU_MEMORY_REGION_3, (uint32)PERIPHERAL_START, (uint32)PERIPHERAL_END);
        SMPU_BusMstUserModeExeControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstUserModeWriteControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_DISABLE);
        SMPU_BusMstUserModeReadControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstSvrModeAccessControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_ALL_ALLOWED);
        SMPU_MemoryRegionConfigEnable(SMPU_MEMORY_REGION_3);

        SMPU_MemoryRegionConfigDisable(SMPU_MEMORY_REGION_4);
    }

    SMPU_Enable();
}

/******************************************************************************/
/*
 * Brief                <In MPU No Trust Isr Configuration, All permissions are
 *                      allowed in privilege mode ,but in user mode,it has some restrict>
 * Service ID           <Os_ArchMpNonTrustIsrThreadSwitch>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <StatusType>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <None>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_ArchMpNonTrustIsrThreadSwitch(ISRType IsrId, ApplicationType HostAppId)
{
    SMPU_Disable();

    SMPU_MemoryRegionRange(SMPU_MEMORY_REGION_0, (uint32)PFLASH_START, (uint32)PFLASH_END);
    SMPU_BusMstUserModeExeControl(SMPU_MEMORY_REGION_0, SMPU_MASTER_CORE, SMPU_ENABLE);
    SMPU_BusMstUserModeWriteControl(SMPU_MEMORY_REGION_0, SMPU_MASTER_CORE, SMPU_ENABLE);
    SMPU_BusMstUserModeReadControl(SMPU_MEMORY_REGION_0, SMPU_MASTER_CORE, SMPU_ENABLE);
    SMPU_BusMstSvrModeAccessControl(SMPU_MEMORY_REGION_0, SMPU_MASTER_CORE, SMPU_ALL_ALLOWED);
    SMPU_MemoryRegionConfigEnable(SMPU_MEMORY_REGION_0);

    SMPU_MemoryRegionRange(SMPU_MEMORY_REGION_1, (uint32)SRAM_START, (uint32)Os_Core_App_DAddr[0].APP_ADDR_START);
    SMPU_BusMstUserModeExeControl(SMPU_MEMORY_REGION_1, SMPU_MASTER_CORE, SMPU_DISABLE);
    SMPU_BusMstUserModeWriteControl(SMPU_MEMORY_REGION_1, SMPU_MASTER_CORE, SMPU_DISABLE);
    SMPU_BusMstUserModeReadControl(SMPU_MEMORY_REGION_1, SMPU_MASTER_CORE, SMPU_DISABLE);
    SMPU_BusMstSvrModeAccessControl(SMPU_MEMORY_REGION_1, SMPU_MASTER_CORE, SMPU_ALL_ALLOWED);
    SMPU_MemoryRegionConfigEnable(SMPU_MEMORY_REGION_1);

    if (Os_AppPriDataAddr[HostAppId].APP_ADDR_START < Os_AppPriDataAddr[HostAppId].APP_ADDR_END) {
        SMPU_MemoryRegionRange(SMPU_MEMORY_REGION_2, (uint32)Os_AppPriDataAddr[HostAppId].APP_ADDR_START, (uint32)Os_AppPriDataAddr[HostAppId].APP_ADDR_END);
        SMPU_BusMstUserModeExeControl(SMPU_MEMORY_REGION_2, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstUserModeWriteControl(SMPU_MEMORY_REGION_2, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstUserModeReadControl(SMPU_MEMORY_REGION_2, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstSvrModeAccessControl(SMPU_MEMORY_REGION_2, SMPU_MASTER_CORE, SMPU_ALL_ALLOWED);
        SMPU_MemoryRegionConfigEnable(SMPU_MEMORY_REGION_2);

        SMPU_MemoryRegionRange(SMPU_MEMORY_REGION_3, (uint32)Os_IsrDAddr[IsrId].ISR_ADDR_START, (uint32)Os_IsrDAddr[IsrId].ISR_ADDR_END);
        SMPU_BusMstUserModeExeControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstUserModeWriteControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstUserModeReadControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstSvrModeAccessControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_ALL_ALLOWED);
        SMPU_MemoryRegionConfigEnable(SMPU_MEMORY_REGION_3);

        SMPU_MemoryRegionRange(SMPU_MEMORY_REGION_4, (uint32)PERIPHERAL_START, (uint32)PERIPHERAL_END);
        SMPU_BusMstUserModeExeControl(SMPU_MEMORY_REGION_4, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstUserModeWriteControl(SMPU_MEMORY_REGION_4, SMPU_MASTER_CORE, SMPU_DISABLE);
        SMPU_BusMstUserModeReadControl(SMPU_MEMORY_REGION_4, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstSvrModeAccessControl(SMPU_MEMORY_REGION_4, SMPU_MASTER_CORE, SMPU_ALL_ALLOWED);
        SMPU_MemoryRegionConfigEnable(SMPU_MEMORY_REGION_4);
    } else {
        SMPU_MemoryRegionRange(SMPU_MEMORY_REGION_2, (uint32)Os_IsrDAddr[IsrId].ISR_ADDR_START, (uint32)Os_IsrDAddr[IsrId].ISR_ADDR_END);
        SMPU_BusMstUserModeExeControl(SMPU_MEMORY_REGION_2, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstUserModeWriteControl(SMPU_MEMORY_REGION_2, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstUserModeReadControl(SMPU_MEMORY_REGION_2, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstSvrModeAccessControl(SMPU_MEMORY_REGION_2, SMPU_MASTER_CORE, SMPU_ALL_ALLOWED);
        SMPU_MemoryRegionConfigEnable(SMPU_MEMORY_REGION_2);

        SMPU_MemoryRegionRange(SMPU_MEMORY_REGION_3, (uint32)PERIPHERAL_START, (uint32)PERIPHERAL_END);
        SMPU_BusMstUserModeExeControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstUserModeWriteControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_DISABLE);
        SMPU_BusMstUserModeReadControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_ENABLE);
        SMPU_BusMstSvrModeAccessControl(SMPU_MEMORY_REGION_3, SMPU_MASTER_CORE, SMPU_ALL_ALLOWED);
        SMPU_MemoryRegionConfigEnable(SMPU_MEMORY_REGION_3);

        SMPU_MemoryRegionConfigDisable(SMPU_MEMORY_REGION_4);
    }

    SMPU_Enable();
}
 /* PRQA S 0306-- */ /* MISRA Rule 11.4 */
/*****************************************************************************/
/*
 * Brief                <Os_ArchInitKnMemMap>
 * ServiceId            <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_ArchInitCPU>
 */
/*****************************************************************************/
FUNC(void, OS_CODE) Os_ArchInitKnMemMap(void)
{
    Os_ArchMpDefaultConfigSwitch();
}

/********************************************************************/
/*
 * Brief                <Memory Protect Function Enable.>
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
FUNC(void, OS_CODE) Os_ArchMemProtEnable(void)
{
    /*SMPU_Enable();*/ 
}

/******************************************************************************/
/*
 * Brief                <Os_ArchSetIsrMemMap>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * param[in]           <None>
 * param[out]          <None>
 * param[in/out]       <None>
 * return              <None>
 * PreCondition         <None>
 * CallByAPI            <None>
 */
/******************************************************************************/
FUNC(void,OS_CODE) Os_ArchSetIsrMemMap /* PRQA S 0624 */ /* MISRA Rule 8.3 */
(
    ISRType         IsrId,
    ApplicationType HostAppId,
    uint32          isTrusted
)
{

    if (TRUE != isTrusted)              /* Non-trusted app running. */
    {
        Os_ArchMpNonTrustIsrThreadSwitch(IsrId, HostAppId);
    }
    else                                /* Trusted app or os_kernel running. */
    {
        /*OSTrustedApplicationWithProtection != TRUE*/
        if (Os_AppCfg[HostAppId].OsTrustedAppWithProtection != TRUE)
        {
            Os_ArchMpDefaultConfigSwitch();
        }
        else
        {
            Os_ArchMpTrustIsrThreadSwitch(IsrId, HostAppId);
        }
    }
}


/******************************************************************************/
/*
 * Brief                <Os_ArchSetTaskMemMap>
 *
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * param[in]           <None>
 * param[out]          <None>
 * param[in/out]       <None>
 * return              <None>
 * PreCondition         <None>
 * CallByAPI            <None>
 */
/******************************************************************************/
FUNC(void,OS_CODE) Os_ArchSetTaskMemMap
(
    TaskType        TaskId,
    ApplicationType HostAppId,
    uint32          isTrusted
)
{

    if (TRUE != isTrusted) /* Non-trusted app running. */
    {
        Os_ArchMpNonTrustTaskThreadSwitch(TaskId, HostAppId);
    }
    else  /* Trusted app or os_kernel running. */
    {
        if (Os_AppCfg[HostAppId].OsTrustedAppWithProtection != TRUE)
        {
            Os_ArchMpDefaultConfigSwitch();
        }
        else
        {
            Os_ArchMpTrustTaskThreadSwitch(TaskId, HostAppId);
        }
    }

}
#endif

