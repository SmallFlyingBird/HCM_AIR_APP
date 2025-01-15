/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2023)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Appl_Callout.c                                              **
**                                                                            **
**  Created on  : 2023/09/20 11:21:28                                         **
**  Author      : long.zhu                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Implementation for Appl .                                   **
**                                                                            **
**  SPECIFICATION(S) : NONE                                                   **
**                                                                            **
*******************************************************************************/
/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/*  <VERSION>    <DATE>      <AUTHOR>     <REVISION LOG>
 *   V1.0.0     20230818     long.zhu        Initial version
 */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Appl_Callout.h"

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
#define DIAGNOSTIC_LEFT

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/**********************************************************************************************/
/**
 * @brief               <ECU Dependency Driver Initialization>
 * <This routine should be called by the boot code to initialize the ECU Dependency Driver> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/**********************************************************************************************/
extern const Can_ConfigType Can_Config_R;
void Appl_EcuDrvInit(void)
{
    McalLib_Init();
    Mcu_Init(NULL_PTR);
    Mcu_InitClock(McuConf_McuClockSettingConfig_McuClockSettingConfig_0);
    Lin_Init(NULL_PTR);
    Port_Init(NULL_PTR);
    Platform_Init(NULL_PTR);
    GptIf_Init();

    
    //CryIf_Init();

}

/**********************************************************************************************/
/**
 * @brief               <ECU Network Bus initialize>
 * <This routine should be called by the boot code to initialize the network bus protocol> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/**********************************************************************************************/
void Appl_EcuNetBusInit(void)
{
    /*LinIf Module Initialize*/
    LinIf_Init(&LinIf_PCConfig);

#ifdef DIAGNOSTIC_LEFT
    LinTp_Init(&LinTp_PCConfig_L);
#else
    LinTp_Init(&LinTp_PCConfig_R);
#endif
    LinIf_Wakeup(0u);
}

/**********************************************************************************************/
/**
 * @brief               <ECU Clockr Deinitialization>
 * <This routine should be called by the boot code to deinitialize the ECU Clock Driver> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/**********************************************************************************************/
int ClockDeinit(void)
{
    uint8 ret = 1;
    volatile uint32 localCnt = 0;
    static Reg_Scc_BfType * const sccRegBfPtr = (Reg_Scc_BfType *)SCC_BASE_ADDR;
    static Reg_Scc_WType * const sccRegWPtr = (Reg_Scc_WType *)SCC_BASE_ADDR;

    /* 将系统时钟选择为FIRC */
    while( sccRegBfPtr->SCC_FIRCCS.FIRCRDY == 0)
    {
        if( localCnt > 100000U)
        {
            return 0;
        }
        else
        {
            localCnt++;
        }
    }
    if( sccRegBfPtr->SCC_CFG.LOCK !=0 )
    {
         sccRegWPtr->SCC_CFG = 0x5B000000U;
    }
    sccRegWPtr->SCC_CFG = (sccRegWPtr->SCC_CFG & 0xFFF8FFFFU) | (1UL << 16U);
    sccRegBfPtr->SCC_CFG.LOCK = 1U;

    /* 恢复 core时钟 */
    if(sccRegBfPtr->SCC_CFG.LOCK != 0U)
    {
        /* unlock this register */
        sccRegWPtr->SCC_CFG = 0x5B000000U;
    }

    sccRegWPtr->SCC_CFG = (sccRegWPtr->SCC_CFG & 0xFFFFF0FFU) | ((uint32)1 << 8U);
    sccRegBfPtr->SCC_CFG.LOCK = 1;

    /* 恢复 bus 时钟 */
    if(sccRegBfPtr->SCC_CFG.LOCK != 0U)
   {
        /* unlock this register */
        sccRegWPtr->SCC_CFG = 0x5B000000U;
   }
   sccRegWPtr->SCC_CFG = (sccRegWPtr->SCC_CFG & 0xFFFFFF0FU) | ((uint32)1 << 4U);
   sccRegBfPtr->SCC_CFG.LOCK = 1U;

   /* 恢复 slow 时钟 */       
   if(sccRegBfPtr->SCC_CFG.LOCK != 0U)
   {
       /* unlock this register */
       sccRegWPtr->SCC_CFG = 0x5B000000U;
   }
   sccRegWPtr->SCC_CFG = (sccRegWPtr->SCC_CFG & 0xFFFFFFF0U) | (uint32)3;
   sccRegBfPtr->SCC_CFG.LOCK = 1U;

   /* 关闭PLL时钟 */
    if(sccRegBfPtr->SCC_SPLLCS.LOCK != 0U)
    {
        /* unlock this register */
        sccRegWPtr->SCC_SPLLCS = 0x5B000000;
    }
    sccRegBfPtr->SCC_SPLLCS.SPLLEN = 0;
    sccRegBfPtr->SCC_SPLLCS.OUTEN = 0;
    /* lock this register */
    sccRegBfPtr->SCC_SPLLCS.LOCK = 1;

    /* 关闭外部时钟 */
    if(sccRegBfPtr->SCC_OSCCS.LOCK != 0U)
    {
        /* unlock this register */
        sccRegWPtr->SCC_OSCCS = 0x5B000000;
    }
    if(sccRegBfPtr->SCC_OSCCFG.LOCK != 0U)
    {
        /* unlock this register */
        sccRegWPtr->SCC_OSCCFG = 0x5B000000U;
    }
    sccRegBfPtr->SCC_OSCCS.OSCEN = 0U;
    sccRegBfPtr->SCC_OSCCFG.OLMEN = 0U;
    /* lock */
    sccRegBfPtr->SCC_OSCCS.LOCK = 1U;
    sccRegBfPtr->SCC_OSCCFG.LOCK = 1U;

    return ret;
}

/**********************************************************************************************/
/**
 * @brief               <ECU Dependency Driver Deinitialization>
 * <This routine should be called by the boot code to deinitialize the ECU Dependency Driver> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/**********************************************************************************************/

void Appl_EcuDrvDeinit(void)
{
    WdgIf_SetTriggerCondition();
    GptIf_Deinit();
    Lin_DeInit();
    Platform_SetIrq(STIM_IRQn,FALSE);
    Platform_SetIrq(UART3_IRQn,FALSE);
	ClockDeinit();

    SuspendAllInterrupts();

}
/******************************************************************************/
/**
 * @brief               <check application software Dependence>
 *
 * <This routine shall be called by the flashloader to check whether the
 *  individual parts (logical blocks) that make up the application software of
 *  an ECU are consistent with each other.> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <FL_ResultType>
 */
/******************************************************************************/
FL_ResultType Appl_CheckDependence(void)
{
    FL_ResultType retVal = FL_OK;
    /*
     *0x21008 - 0x2100B??????????,???????????????????
     *0x2100C - 0x2100F??????????,???????????????????
    */
    uint8 *TemplateVersionAddress_H=(uint8 *)0x21008;
    uint8 *TemplateVersionAddress_L=(uint8 *)0x2100C;

    uint8 *TemplateVersion_Address_Comple_Value;
    uint8 *TemplateVersion_Address_Store_Value;


    TemplateVersion_Address_Store_Value = ((((uint32)TemplateVersionAddress_H[0])<<24) & 0xFF000000) + 
                                          ((((uint32)TemplateVersionAddress_H[1])<<16) & 0x00FF0000) +
                                          ((((uint32)TemplateVersionAddress_H[2])<<8) & 0x0000FF00)  +
                                           TemplateVersionAddress_H[3];
    
    /*Out of Plash Address*/
    if(TemplateVersion_Address_Store_Value > 0x001FFFFF)
        return FL_FAILED;
    
    /*Hex?????????????*/
    TemplateVersion_Address_Comple_Value = (uint8 *)0x21010;

    if((*TemplateVersion_Address_Comple_Value) != (*TemplateVersion_Address_Store_Value))
        return FL_FAILED;
    
    
    TemplateVersion_Address_Store_Value = ((((uint32)TemplateVersionAddress_L[0])<<24) & 0xFF000000) + 
                                          ((((uint32)TemplateVersionAddress_L[1])<<16) & 0x00FF0000) +
                                          ((((uint32)TemplateVersionAddress_L[2])<<8) & 0x0000FF00)  +
                                          TemplateVersionAddress_L[3];
                                          
    /*Out of Plash Address*/
    if(TemplateVersion_Address_Store_Value > 0x001FFFFF)   
        return FL_FAILED; 

    /*Hex?????????????*/
    TemplateVersion_Address_Comple_Value = (uint8 *)0x21011;

    if((*TemplateVersion_Address_Comple_Value) != (*TemplateVersion_Address_Store_Value))
        return FL_FAILED;
    
    /* todo */
    retVal = (uint8)FL_OK;

    return retVal;
}

/******************************************************************************/
/**
 * @brief               <jump to application software>
 *
 * <jump to application software> .
 * @param[in]           <address:Jump address.>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Appl_AdaptiveJumpApp(uint32 address)
{
   ((void (*) (void))((address)))();/*PRQA S 0305*/
}
#if (APPL_SLEEP_TIMER > 0u)
/******************************************************************************/
/**
 * @brief               <ECU goto sleep mode>
 *
 * <This routine shall be called by the flash loader to shut down the ECU (put
 *  the ECU to sleep).> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Appl_EcuShutdown(void)
{
    /* do nothing */
    /* reserved for user, application related */
    return;
}
#endif

#if (APPL_ENABLE_WATCHDOG_MONITORING_IN_BOOT == STD_ON)
/******************************************************************************/
/**
 * @brief               <Timeout watchdog feed the dog.>
 *
 * <Timeout watchdog feed the dog.> .
 * Service ID   :       <NONE>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <NONE>
 * @param[out]          <NONE>
 * @param[in/out]       <NONE>
 * @return              <NONE>
 */
/******************************************************************************/
void Appl_wdTriggerFct(void)
{
	WdgIf_MainFunction();
}
#endif

boolean Appl_CheckAppAddr(void)
{
    uint32 AppEnterAddress;
    uint8 i = 0u;
    /* should de-initialize hardware module first */
    /* if has interrupt, disable interrupt first
     * 1. Gpt-Deinit  ;
     * 2. CAN-Deinit  ;
     * 3. Port-Deinit ;
     * 4. MCU-Deinit  ;
     * 4. Wdg should not Deinit;
     * */
    AppEnterAddress = *(uint32*)(FL_essInfo.appStartAddr + 4);
    for (i = 0; i < FL_essInfo.numOfLogicalBlocks; i++)
    {
        /* code */
        if (FL_essInfo.logicalBlockLayoutStruct[i].swPartType == FL_EXE)
        {
            break;
        }
    }

    if (i >= FL_essInfo.numOfLogicalBlocks)
    {
        return FALSE;
    }

    if ((AppEnterAddress < FL_essInfo.logicalBlockLayoutStruct[i].startAddress)
        || (AppEnterAddress >= (FL_essInfo.logicalBlockLayoutStruct[i].startAddress + FL_essInfo.logicalBlockLayoutStruct[i].length))
       )
    {
        return FALSE;
    }
    return TRUE;
}
/*=======[E N D   O F   F I L E]==============================================*/
