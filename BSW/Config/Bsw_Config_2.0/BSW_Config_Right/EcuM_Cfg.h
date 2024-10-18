/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2022)                                               **
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
**  Created on  : 2024/03/26 15:24:53                                         **
**  Author      :                                                             **
**  Vendor      :                                                             **
**  DESCRIPTION : Configuration constant variables for pre-compile            **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11.                     **
**                                                                            **
*******************************************************************************/
#ifndef ECUM_CFG_H
#define ECUM_CFG_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define ECUM_MAINFUNC_PERIOD                10u

#define ECWM_COMM_PNC_ENABLED                STD_OFF

#define  ECUM_USE_TIMER                    ECUM_TIMER_USE_OS

/* EcuMDevErrorDetect */
#define ECUM_DEV_ERROR_DETECT               STD_OFF

/* EcuMVersionInfoApi */
#define ECUM_VERSION_INFO_API               STD_OFF

/*Switch for whether a driver init list zero configured*/
#define ECUM_DRIVER_INIT_LIST_ZERO          STD_OFF

/*Switch for whether a driver init list one configured*/
#define ECUM_DRIVER_INIT_LIST_ONE           STD_ON

/*Switch for whether a driver restart list configured*/
#define ECUM_DRIVER_RESTART_LIST            STD_OFF

/*This flag indicates whether the optional AlarmClock feature is present*/
#define ECUM_ALARM_CLOCK_PRESENT            STD_OFF

/*To reuse software components (legacy SWCs), which are designed to work with
 * the "ECU State Manager with fixed state machine" the option
 * "ECU Mode Handling" has to be activated.*/
/*If STD_OFF, Run Request Protocol is not performed*/
#define ECUM_MODE_HANDING                   STD_ON

/*EcuMResetLoopDetection*/
#define ECUM_RESET_LOOP_DETECTION           STD_OFF

/*EcuMSetProgrammableInterrupts*/
#define ECUM_SET_PROGRAMMABLE_INTERRUPTS    STD_OFF

/*Number of sleep mode configured in this ECUM*/
#define ECUM_MAX_SLEEP_MODE_NUM            1

/*Number of reset mode configured in this ECUM*/
#define ECUM_MAX_RESET_MODE_NUM             1

#define ECUM_MAX_SHUTDOWN_CAUSE_NUM         1

/*Number of wake up sources configured in this ECUM*/
#define ECUM_MAX_WAKE_UP_SOURCE_NUM         1

/*Number of ECUM user configured*/
#define ECUM_MAX_USER_NUM                   1

/*Number of ECUM alarm clock configured*/
#define ECUM_MAX_ALARM_CLOCK_NUM             0

/*number of core, in multi-core case, it is bigger than one*/
#define ECUM_MAX_MCU_CORE_NUM                1

/*the CORE identifier on which the master ECUM running*/
#define ECUM_MASTER_CORE_ID                   0

#define ECUM_ALL_WKSOURCE                    ((uint32)(EcuMWakeupSource_ByCAN))

#define EcuMDriverInitListBswM_0                       0u

#define EcuMFlexUserConfig                       0u

#endif /* ECUM_CFG_H */
