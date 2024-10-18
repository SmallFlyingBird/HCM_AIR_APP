/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <CanTp_Callout.c>
 *  @brief      <>
 *  
 *  <MCU:Z20K148>
 *  
 *  @author     <>
 *  @date       <2024-03-21 10:57:32>
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/
#include "CanTp_Internal.h"
#include "Os.h"
#if (CANTP_TM == STD_ON)
#include "Tm.h"
#endif /* CANTP_TM == STD_ON */

/*=============Module Callout Function Implementation====================*/
#define CANTP_START_SEC_CODE
#include "CanTp_MemMap.h"
/* Showing TM solution as an example */
/* if not having TM, need to implement other methods for timing functionality */
FUNC(void, CANTP_CODE)
CanTp_ResetTime(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint32, AUTOMATIC, CANTP_APPL_DATA) TimerPtr)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
#if (CANTP_TM == STD_ON)
    Tm_PredefTimer100us32bitType Timer;

    Timer.ui32RefTime = 0;
    (void)Tm_ResetTimer100us32bit(&Timer);
    *TimerPtr = Timer.ui32RefTime / (uint32)10;
#endif
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
}

/* Showing TM solution as an example */
/* if not having TM, need to implement other methods for timing functionality */
FUNC(void, CANTP_CODE)
CanTp_GetTimeSpan(
    uint32 TimerPtr,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint32, AUTOMATIC, CANTP_APPL_DATA) TimeSpanPtr)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
#if (CANTP_TM == STD_ON)
    Tm_PredefTimer100us32bitType Timer;

    Timer.ui32RefTime = TimerPtr * (uint32)10;
    (void)Tm_GetTimeSpan100us32bit(&Timer, TimeSpanPtr);
    *TimeSpanPtr = (*TimeSpanPtr) / (uint32)10;
#endif
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
}
#define CANTP_STOP_SEC_CODE
#include "CanTp_MemMap.h"

