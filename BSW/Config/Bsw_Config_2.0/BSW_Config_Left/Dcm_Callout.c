/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Dcm_Callout.c>
 *  @brief      <>
 *  
 *  <MCU:Z20K148>
 *  
 *  @author     <>
 *  @date       <2024-03-21 10:57:33>
 */
/*============================================================================*/

#include "Dcm_Internal.h"
#include "UDS.h"
#include "DcmDsl_MsgManage.h"
#include "Dcm_CalloutBoot.h"
#include "Os.h"
#include "string.h"
#if (DCM_TM == STD_ON)
#include "Tm.h"
#endif /* (DCM_TM == STD_ON) */

/* BL_AppFlagType* BL_AppFlag = (BL_AppFlagType*) BL_APP_FLAG_ADDRESS; */
#define APPL_EXT_PROG_REQUEST_RECEIVED_LENGTH 8
const uint8 Appl_extprogrequestreceived[]={0x6E,0x67,0x69,0x53,0x67,0x6F,0x72,0x50};
#define FL_BOOT_MODE 0x2001fff8
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Std_ReturnType Dcm_SetProgConditions(
Dcm_OpStatusType OpStatus,
Dcm_ProgConditionsType * ProgConditions/* PRQA S 3334 */ /* MISRA Rule 5.3 */
)
{
    DCM_UNUSED(OpStatus);
    DCM_UNUSED(ProgConditions);
    memcpy(FL_BOOT_MODE,Appl_extprogrequestreceived,APPL_EXT_PROG_REQUEST_RECEIVED_LENGTH);
    return E_OK;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
Dcm_EcuStartModeType Dcm_GetProgConditions(/* PRQA S 3408 */ /* MISRA Rule 8.4 */
Dcm_ProgConditionsType * ProgConditions/* PRQA S 3334 */ /* MISRA Rule 5.3 */
)
{
    DCM_UNUSED(ProgConditions);
    /*TODO: check ApplUpdated*/
    /*e.g*/
    /*    if (BL_AppFlag->FlApplUpdate == (uint32)FL_APPL_UPDATED)
    {
        ProgConditions->ApplUpdated = TRUE;
        BL_AppFlag->FlApplUpdate = (uint32)0;
        return DCM_WARM_START;
    }*/
    return DCM_COLD_START;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
/* Showing TM solution as an example */
/* if not having TM, need to implement other methods for timing functionality */
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
FUNC(void, DCM_CODE) Dcm_ResetTime(P2VAR(uint32, AUTOMATIC, DCM_VAR) TimerPtr)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
#if (DCM_TM == STD_ON)
    Tm_PredefTimer100us32bitType Timer;

    Timer.ui32RefTime = 0;
    (void)Tm_ResetTimer100us32bit(&Timer);
    *TimerPtr = Timer.ui32RefTime / (uint32)10;
#else /* DCM_TM == STD_ON */
#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
	CoreIdType coreId;
    coreId = GetCoreID();
    switch (coreId)
    {
        case OS_CORE_ID_0:
        {
            (void)GetCounterValue(SystemTimer_Core0, TimerPtr);
            /*tick to ms*/

            *TimerPtr = OS_TICKS2MS_SystemTimer_Core0(*TimerPtr);
            break;
        }
        default:
            break;
    }
#endif
#endif /* DCM_TM == STD_ON */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
/* Showing TM solution as an example */
/* if not having TM, need to implement other methods for timing functionality */
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
FUNC(void, DCM_CODE) Dcm_GetTimeSpan(uint32 TimerPtr,P2VAR(uint32, AUTOMATIC, DCM_VAR) TimeSpanPtr)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
#if (DCM_TM == STD_ON)
    Tm_PredefTimer100us32bitType Timer;
    *TimeSpanPtr = 0u;

    Timer.ui32RefTime = TimerPtr * (uint32)10;
    (void)Tm_GetTimeSpan100us32bit(&Timer,TimeSpanPtr);
    *TimeSpanPtr = *TimeSpanPtr / (uint32)10;
#else /* DCM_TM == STD_ON */
#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
	CoreIdType coreId;
	coreId = GetCoreID();
    switch (coreId)
    {
        case OS_CORE_ID_0:
        {
            /*ms to tick*/
        	TimerPtr = OS_MS2TICKS_SystemTimer_Core0(TimerPtr);
            (void)GetElapsedValue(SystemTimer_Core0, &TimerPtr, TimeSpanPtr);
            *TimeSpanPtr = OS_TICKS2MS_SystemTimer_Core0(*TimeSpanPtr);
            break;
        }
        default:
            break;
    }
#endif
#endif /* DCM_TM == STD_ON */
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

