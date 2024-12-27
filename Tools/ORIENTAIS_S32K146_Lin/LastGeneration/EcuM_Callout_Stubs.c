/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2016)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : EcuM_Callout_Stubs.c                                        **
**                                                                            **
**  Created on  :                                                             **
**  Author      : stanleyluo                                                  **
**  Vendor      :                                                             **
**  DESCRIPTION :  Implementations for EcuM callouts                          **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "EcuM.h"
#include "EcuM_Internal.h"

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/



/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
void EcuM_GetSourceInfo4WakeSource(uint32 wakeupSource)
{
    return;
}


#define ECUM_START_SEC_ERRORHOOK_CODE
#include "EcuM_MemMap.h"
/**
 * The ECU State Manager will call the error hook if the error codes
 * "ECUM_E_RAM_CHECK_FAILED" or "ECUM_E_CONFIGURATION_DATA_INCONSISTENT" occur.
 * In this situation it is not possible to continue processing and the ECU must
 * be stopped. The integrator may choose the modality how the ECU is stopped,
 * i.e. reset, halt, restart, safe state etc.
 * EcuM_ErrorHook is integration code and the integrator is free to define
 * additional individual error codes to be passed as the reason parameter.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): reason, Reason for calling the error hook
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_ERRORHOOK_CODE) EcuM_ErrorHook
(
    uint16 reason
)
{
    /*todo*/
}
#define ECUM_STOP_SEC_ERRORHOOK_CODE
#include "EcuM_MemMap.h"

#if (ECUM_SET_PROGRAMMABLE_INTERRUPTS == STD_ON)
#define ECUM_START_SEC_AL_SETPROGRAMMABLEINTERRUPTS_CODE
#include "EcuM_MemMap.h"
/**
 * If the configuration parameter EcuMSetProgrammableInterrupts is set to true,
 * this callout EcuM_AL_SetProgrammableInterrupts is executed and shall set the
 * interrupts on ECUs with programmable interrupts.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_AL_SETPROGRAMMABLEINTERRUPTS_CODE) EcuM_AL_SetProgrammableInterrupts
(
    void
)
{
    /*todo*/
}
#define ECUM_STOP_SEC_AL_SETPROGRAMMABLEINTERRUPTS_CODE
#include "EcuM_MemMap.h"
#endif /*#if (ECUM_SET_PROGRAMMABLE_INTERRUPTS == STD_ON)*/

#if (ECUM_DRIVER_INIT_LIST_ZERO == STD_ON)
#define ECUM_START_SEC_AL_DRIVERINITZERO_CODE
#include "EcuM_MemMap.h"
/**
 * This callout shall provide driver initialization and other hardware-related
 * startup activities for loading the post-build configuration data. Beware:
 * Here only pre-compile and link-time configurable modules may be used.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_AL_DRIVERINITZERO_CODE) EcuM_AL_DriverInitZero
(
	void
)
{
}
#define ECUM_STOP_SEC_AL_DRIVERINITZERO_CODE
#include "EcuM_MemMap.h"
#endif /*#if (ECUM_DRIVER_INIT_LIST_ZERO == STD_ON)*/

#define ECUM_START_SEC_DETERMINEPBCONFIGURATION_CODE
#include "EcuM_MemMap.h"
/**
 * This callout should evaluate some condition, like port pin or NVRAM value,
 * to determine which post-build configuration shall be used in the remainder
 * of the startup process. It shall load this configuration data into a piece
 * of memory that is accessible by all BSW modules and shall return a pointer
 * to the EcuM post-build configuration as a base for all BSW module post-build
 * configurations.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: Pointer to the EcuM post-build configuration which contains
 *               pointers to all other BSW module post-build configurations.
 */
FUNC_P2CONST(EcuM_ConfigType, ECUM_CONFIG_DATA, ECUM_DETERMINEPBCONFIGURATION_CODE) EcuM_DeterminePbConfiguration
(
    void
)
{
    /*todo*/
    return (&EcuM_Config);
}
#define ECUM_STOP_SEC_DETERMINEPBCONFIGURATION_CODE
#include "EcuM_MemMap.h"

#if (ECUM_DRIVER_INIT_LIST_ONE == STD_ON)
#define ECUM_START_SEC_AL_DRIVERINITONE_CODE
#include "EcuM_MemMap.h"
/**
 * This callout shall provide driver initialization and other hardware-related
 * startup activities in case of a power on reset.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): ConfigPtr, pointer to the EcuM post-build configuration which
 *                             contains pointers to all other BSW module post-build
 *                             configurations.
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_AL_DRIVERINITONE_CODE) EcuM_AL_DriverInitOne
(
	P2CONST(EcuM_ConfigType, AUTOMATIC, ECUM_APPL_CONST) ConfigPtr
)
{
}
#define ECUM_STOP_SEC_AL_DRIVERINITONE_CODE
#include "EcuM_MemMap.h"
#endif /*#if (ECUM_DRIVER_INIT_LIST_ONE == STD_ON)*/

#if (ECUM_RESET_LOOP_DETECTION == STD_ON)
#define ECUM_START_SEC_LOOPDETECTION_CODE
#include "EcuM_MemMap.h"
/**
 * If the configuration parameter EcuMResetLoopDetection is set to true,
 * this callout EcuM_LoopDetection is called on every startup.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: FALSE: no reset loop is detected
 *               TRUE: reset loop is detected
 */
FUNC(boolean, ECUM_LOOPDETECTION_CODE) EcuM_LoopDetection
(
    void
)
{
    /*todo*/
    return FALSE;
}
#define ECUM_STOP_SEC_LOOPDETECTION_CODE
#include "EcuM_MemMap.h"
#endif /*#if (ECUM_RESET_LOOP_DETECTION == STD_ON)*/

#define ECUM_START_SEC_ONGOOFFONE_CODE
#include "EcuM_MemMap.h"
/**
 * This call allows the system designer to notify that the GO OFF I state is
 * about to be entered.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_ONGOOFFONE_CODE) EcuM_OnGoOffOne
(
    void
)
{
    /*todo*/
}
#define ECUM_STOP_SEC_ONGOOFFONE_CODE
#include "EcuM_MemMap.h"

#define ECUM_START_SEC_ONGOOFFTWO_CODE
#include "EcuM_MemMap.h"
/**
 * This call allows the system designer to notify that the GO OFF II state is
 * about to be entered.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_ONGOOFFTWO_CODE) EcuM_OnGoOffTwo
(
    void
)
{
    /*todo*/
}
#define ECUM_STOP_SEC_ONGOOFFTWO_CODE
#include "EcuM_MemMap.h"

#define ECUM_START_SEC_AL_SWITCHOFF_CODE
#include "EcuM_MemMap.h"
/**
 * This callout shall take the code for shutting off the power supply of the ECU.
 * If the ECU cannot unpower itself, a reset may be an adequate reaction.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_AL_SWITCHOFF_CODE) EcuM_AL_SwitchOff
(
    void
)
{
    /*todo*/
}
#define ECUM_STOP_SEC_AL_SWITCHOFF_CODE
#include "EcuM_MemMap.h"

#define ECUM_START_SEC_AL_RESET_CODE
#include "EcuM_MemMap.h"
/**
 * This callout shall take the code for resetting the ECU.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): reset, type of reset to be performed.
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_AL_RESET_CODE) EcuM_AL_Reset
(
    EcuM_ResetType reset
)
{
    Mcu_PerformReset();
}
#define ECUM_STOP_SEC_AL_RESET_CODE
#include "EcuM_MemMap.h"



#define ECUM_START_SEC_ENABLEWAKEUPSOURCES_CODE
#include "EcuM_MemMap.h"
/**
 * The ECU Manager Module calls EcuM_EnableWakeupSource to allow the system
 * designer to notify wakeup sources defined in the wakeupSource bitfield that
 * SLEEP will be entered and to adjust their source accordingly.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_ENABLEWAKEUPSOURCES_CODE) EcuM_EnableWakeupSources
(
    EcuM_WakeupSourceType wakeupSource
)
{
    /*Get module which is the source for wakupSource*/
    EcuM_GetSourceInfo4WakeSource(wakeupSource);
     	
	 if (EcuMWakeupSource_Lin_WKSID == (wakeupSource & EcuMWakeupSource_Lin_WKSID))
    {
        /*todo*/
    } 
   	
   
}
#define ECUM_STOP_SEC_ENABLEWAKEUPSOURCES_CODE
#include "EcuM_MemMap.h"

#define ECUM_START_SEC_GENERATERAMHASH_CODE
#include "EcuM_MemMap.h"
/**
 * Generate code for RAM integrity test.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_GENERATERAMHASH_CODE) EcuM_GenerateRamHash
(
    void
)
{
    /*todo*/
}
#define ECUM_STOP_SEC_GENERATERAMHASH_CODE
#include "EcuM_MemMap.h"

#define ECUM_START_SEC_SLEEPACTIVITY_CODE
#include "EcuM_MemMap.h"
/**
 * This callout is invoked periodically in all reduced clock sleep modes.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_SLEEPACTIVITY_CODE) EcuM_SleepActivity
(
    void
)
{
    /*todo*/
}
#define ECUM_STOP_SEC_SLEEPACTIVITY_CODE
#include "EcuM_MemMap.h"

#define ECUM_START_SEC_STARTCHECKWAKEUP_CODE
#include "EcuM_MemMap.h"
/**
 * This API is called by the ECU Firmware to start the CheckWakeupTimer for the
 * corresponding WakeupSource. If EcuMCheckWakeupTimeout > 0 the CheckWakeupTimer
 * for the WakeupSource is started. If EcuMCheckWakeupTimeout ?? 0 the API call
 * is ignored by the EcuM.
 * Service ID[hex]: 0x28
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource, For this wakeup source the corresponding
 *                                CheckWakeupTimer shall be started.
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_STARTCHECKWAKEUP_CODE) EcuM_StartCheckWakeup
(
    EcuM_WakeupSourceType WakeupSource
)
{
    P2VAR(EcuM_RunTimeType, AUTOMATIC, ECUM_VAR)pRt = &EcuMRunData;
    uint8 index;

    for (index = 0; index < ECUM_MAX_WAKE_UP_SOURCE_NUM; index ++)
    {
        if ((EcuM_WkSourceCfgs[index].wkSource & WakeupSource) != 0)
        {
            if ((EcuM_WkSourceCfgs[index].checkWkupTimeout > 0) 
                    && (pRt->Wks.StartTime[index] == ECUM_TIMEOUT))
            {
                EcuM_GetCurrentTime(&pRt->Wks.StartTime[index]);
            }
        }
    }
}
#define ECUM_STOP_SEC_STARTCHECKWAKEUP_CODE
#include "EcuM_MemMap.h"

#define ECUM_START_SEC_CHECKWAKEUP_CODE
#include "EcuM_MemMap.h"
/**
 * This callout is called by the EcuM to poll a wakeup source.
 * It shall also be called by the ISR of a wakeup source to set up the PLL and
 * check other wakeup sources that may be connected to the same interrupt.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_CHECKWAKEUP_CODE) EcuM_CheckWakeup
(
    EcuM_WakeupSourceType wakeupSource
)
{
    /* Which module does this wakeup source belongs to?*/
  
#if (ECUM_DEV_ERROR_DETECT == STD_ON)
    /* Init Check */
    if (FALSE == EcuM_IsInit)
    {
        Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_SID_CHECKWAKEUP, ECUM_E_UNINIT);
    }
    else
#endif/* (ECUM_DEV_ERROR_DETECT == STD_ON) */
    {
    
	 if(EcuMWakeupSource_Lin_WKSID == (wakeupSource & EcuMWakeupSource_Lin_WKSID))
            CanIf_CheckWakeup(EcuMWakeupSource_Lin_WKSID);  
    }
}

#define ECUM_STOP_SEC_CHECKWAKEUP_CODE
#include "EcuM_MemMap.h"

#define ECUM_START_SEC_ENDCHECKWAKEUP_CODE
#include "EcuM_MemMap.h"
/**
 * This API is called by any SW Module whose wakeup source is checked
 * asynchronously (e.g. asynchronous Can Trcv Driver) and the Check of the Wakeup
 * returns a negative Result (no Wakeup by this Source). The API cancels the
 * CheckWakeupTimer for the WakeupSource. If the correponding CheckWakeupTimer is
 * canceled the check of this wakeup source is finished.
 * Service ID[hex]: 0x29
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource, For this wakeup source the corresponding
 *                                CheckWakeupTimer shall be canceled.
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_ENDCHECKWAKEUP_CODE) EcuM_EndCheckWakeup
(
    EcuM_WakeupSourceType WakeupSource
)
{
    P2VAR(EcuM_RunTimeType, AUTOMATIC, ECUM_VAR)pRt = &EcuMRunData;
    TickType startTime = 0;
    TickType elapsedValue = 0;
    uint8 index;

    for (index = 0; index < ECUM_MAX_WAKE_UP_SOURCE_NUM; index ++)
    {
        if ((EcuM_WkSourceCfgs[index].wkSource & WakeupSource) != 0)
        {
            if ((EcuM_WkSourceCfgs[index].checkWkupTimeout > 0) 
                    && (pRt->Wks.StartTime[index] != ECUM_TIMEOUT))
            {
                startTime = pRt->Wks.StartTime[index];
                elapsedValue = Frt_CalculateElapsedMS(startTime);

                if (elapsedValue > EcuM_WkSourceCfgs[index].checkWkupTimeout)
                {
                    pRt->Wks.Expired = pRt->Wks.Expired | EcuM_WkSourceCfgs[index].wkSource;
                    pRt->Wks.Pending = pRt->Wks.Pending & (~EcuM_WkSourceCfgs[index].wkSource);
                }
            }
        }
    }
}
#define ECUM_STOP_SEC_ENDCHECKWAKEUP_CODE
#include "EcuM_MemMap.h"

#define ECUM_START_SEC_CHECKRAMHASH_CODE
#include "EcuM_MemMap.h"
/**
 * This callout is intended to provide a RAM integrity test. The goal of this
 * test is to ensure that after a long SLEEP duration, RAM contents is still
 * consistent. The check does not need to be exhaustive since this would consume
 * quite some processing time during wakeups. A well designed check will execute
 * quickly and detect RAM integrity defects with a sufficient probability.
 * The areas of RAM which will be checked have to be chosen carefully. It depends
 * on the check algorithm itself and the task structure. Stack contents of the
 * task executing the RAM check e.g. very likely cannot be checked. It is good
 * practice to have the hash generation and checking in the same task and that this
 * task is not preemptible and that there is only little activity between hash
 * generation and hash check. The RAM check itself is provided by the system
 * designer. In case of applied multi core and existence of Satellite-EcuM(s):
 * this API will be called by the Master-EcuM only.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): NA
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: 0: RAM integrity test failed else: RAM integrity test passed
 */
FUNC(uint8, ECUM_CHECKRAMHASH_CODE) EcuM_CheckRamHash
(
    void
)
{
    /*todo*/
    return 1;
}
#define ECUM_STOP_SEC_CHECKRAMHASH_CODE
#include "EcuM_MemMap.h"

#define ECUM_START_SEC_DISABLEWAKEUPSOURCES_CODE
#include "EcuM_MemMap.h"
/**
 * The ECU Manager Module calls EcuM_DisableWakeupSources to set the wakeup
 * source(s) defined in the wakeupSource bitfield so that they are not able to
 * wake the ECU up.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_DISABLEWAKEUPSOURCES_CODE) EcuM_DisableWakeupSources
(
    EcuM_WakeupSourceType wakeupSource
)
{
    /*Get module which is the source for wakupSource*/
    EcuM_GetSourceInfo4WakeSource(wakeupSource);
    /*todo*/
}
#define ECUM_STOP_SEC_DISABLEWAKEUPSOURCES_CODE
#include "EcuM_MemMap.h"

#if (ECUM_DRIVER_RESTART_LIST == STD_ON)
#define ECUM_START_SEC_AL_DRIVERRESTART_CODE
#include "EcuM_MemMap.h"
/**
 * This callout shall provide driver initialization and other hardware-related
 * startup activities in the wakeup case.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): ConfigPtr, pointer to the EcuM post-build configuration which
 *                             contains pointers to all other BSW module post-build
 *                             configurations.
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_AL_DRIVERRESTART_CODE) EcuM_AL_DriverRestart
(
    P2CONST(EcuM_ConfigType, AUTOMATIC, ECUM_APPL_CONST) ConfigPtr
)
{
}
#define ECUM_STOP_SEC_AL_DRIVERRESTART_CODE
#include "EcuM_MemMap.h"
#endif /*#if (ECUM_DRIVER_RESTART_LIST == STD_ON)*/

#define ECUM_START_SEC_STARTWAKEUPSOURCES_CODE
#include "EcuM_MemMap.h"
/**
 * The callout shall start the given wakeup source(s) so that they are ready to
 * perform wakeup validation.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_STARTWAKEUPSOURCES_CODE) EcuM_StartWakeupSources
(
    EcuM_WakeupSourceType wakeupSource
)
{
    uint32 index=100u;
     

}
#define ECUM_STOP_SEC_STARTWAKEUPSOURCES_CODE
#include "EcuM_MemMap.h"

#define ECUM_START_SEC_CHECKVALIDATION_CODE
#include "EcuM_MemMap.h"
/**
 * This callout is called by the EcuM to validate a wakeup source. If a valid
 * wakeup has been detected, it shall be reported to EcuM via EcuM_ValidateWakeupEvent().
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_CHECKVALIDATION_CODE) EcuM_CheckValidation
(
    EcuM_WakeupSourceType wakeupSource
)
{
    /*todo*/
    CanIf_CheckValidation(wakeupSource);
    EcuM_EndCheckWakeup(wakeupSource);
}
#define ECUM_STOP_SEC_CHECKVALIDATION_CODE
#include "EcuM_MemMap.h"

#define ECUM_START_SEC_STOPWAKEUPSOURCES_CODE
#include "EcuM_MemMap.h"
/**
 * The callout shall stop the given wakeup source(s) after unsuccessful wakeup
 * validation.
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): wakeupSource
 * Parameters(INOUT): NA
 * Parameters(OUT):  NA
 * Return value: NA
 */
FUNC(void, ECUM_STOPWAKEUPSOURCES_CODE) EcuM_StopWakeupSources
(
    EcuM_WakeupSourceType wakeupSource
)
{ 
}
#define ECUM_STOP_SEC_STOPWAKEUPSOURCES_CODE
#include "EcuM_MemMap.h"



/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/


void Rte_EcuM_SetStateIndication(uint16 state)
{
    return;
}

/*******************************************************************************
**                            General Notes                                   **
*******************************************************************************/


