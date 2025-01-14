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
**  FILENAME    : EcuM_Cfg.h                                                  **
**                                                                            **
**  Created on  :                                                             **
**  Author      :                                                             **
**  Vendor      :                                                             **
**  DESCRIPTION : Configuration constant variables for pre-compile            **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
#ifndef ECUM_CFG_H
#define ECUM_CFG_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#include "EcuM_Types.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* EcuMDevErrorDetect */
#define ECUM_DEV_ERROR_DETECT               STD_OFF

/* EcuMIncludeDet */
#define ECUM_INCLUDE_DET                    STD_OFF

/* EcuMIncludeComM */
#define ECUM_INCLUDE_COMM                   STD_ON

/* EcuMVersionInfoApi */
#define ECUM_VERSION_INFO_API               STD_OFF

/*Switch for whether a driver init list zero configured*/
#define ECUM_DRIVER_INIT_LIST_ZERO  		STD_OFF		

/*Switch for whether a driver init list one configured*/
#define ECUM_DRIVER_INIT_LIST_ONE           STD_OFF

/*Switch for whether a driver restart list configured*/
#define ECUM_DRIVER_RESTART_LIST    		STD_OFF		

/*This flag indicates whether the optional AlarmClock feature is present*/
#define ECUM_ALARM_CLOCK_PRESENT            STD_OFF

/*To reuse software components (legacy SWCs), which are designed to work with
 * the "ECU State Manager with fixed state machine" the option
 * "ECU Mode Handling" has to be activated.*/
/*If STD_OFF, Run Request Protocol is not performed*/
#define ECUM_MODE_HANDING         			STD_ON

/*EcuMResetLoopDetection*/
#define ECUM_RESET_LOOP_DETECTION           STD_OFF

/*EcuMSetProgrammableInterrupts*/
#define ECUM_SET_PROGRAMMABLE_INTERRUPTS    STD_OFF

/*EcuMAlarmWakeupSource,the reference to the EcuMWakeupSource being used for the
 *EcuM AlarmClock*/
#define ECUM_ALARM_WAKEUP_SOURCE 			6

/*Number of sleep mode configured in this ECUM*/
#define ECUM_MAX_SLEEP_MODE_NUM 			0

/*Number of reset mode configured in this ECUM*/
#define ECUM_MAX_RESET_MODE_NUM 			1

/*Number of wake up sources configured in this ECUM*/
#define ECUM_MAX_WAKE_UP_SOURCE_NUM 		1

/*Number of ECUM user configured*/
#define ECUM_MAX_USER_NUM   				1	

/*Number of ECUM alarm clock configured*/
#define ECUM_MAX_ALARM_CLOCK_NUM 			0

/*extended configure and generated ECUM reset modes, start from 3*/
#define ECUM_RESET_SMU    					3

/*extended configure and generated ECUM shutdown cause, start from 4*/
#define ECUM_CAUSE_CDD1    					4

/*number of core, in multi-core case, it is bigger than one*/
#define ECUM_MAX_MCU_CORE_NUM  				1

/*number of partitions in ECU*/
#define ECUM_MAX_PARTITION_NUM 				0	 /*EcuMPartitionRef*/
/*the CORE identifier on which the master ECUM running*/
#define ECUM_MASTER_CORE_ID   				OS_CORE_ID_0

#define ECUM_CORE1_ENABLE
#define ECUM_CORE1_ID

#define ECUM_CORE2_ENABLE
#define ECUM_CORE2_ID
#define ECUM_ALL_WKSOURCE				    (EcuMWakeupSource_Lin_WKSID)

#define ECUM_COUNTER_ID					    0
/*todo: ECUM_SPINLOCK_ID should reference in OS*/
#define ECUM_SPINLOCK_ID

/*todo: reference in OS*/
#define EcuM_Core1_Task_GoDown
#define EcuM_Core2_Task_GoDown

#define EcuM_Core1_Event_GoDown
#define EcuM_Core2_Event_GoDown

#define EcuM_Core0_Resource_GoSleep
#define EcuM_Core1_Resource_GoSleep
#define EcuM_Core2_Resource_GoSleep

#define EcuMFlexUserConfig_0                0u
#define EcuMResetMode_0                     0u

#endif /* ECUM_CFG_H */

