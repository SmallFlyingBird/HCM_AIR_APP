/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <FlsTst_Cfg.h>
 *  @brief      <>
 *  
 *  <MCU:S32K14X>
 *  
 *  @author     <>
 *  @date       <2024-12-16 14:21:14>
 */
/*============================================================================*/


/*======================[R E V I S I O N   H I S T O R Y]=====================*/
/*  <VERSION>    <DATE>      <AUTHOR>         <REVISION LOG>
 *   V1.0.0     20210916     Huangyin         Initial version
 */
/*============================================================================*/
#ifndef FLSTST_CFG_H
#define FLSTST_CFG_H

/*============================[I N C L U D E S]===============================*/
#include "FlsTst_Types.h"


/*=======[F I L E  V E R S I O N   I N F O R M A T I O N]=====================*/
#define 	FLSTST_CFG_H_AR_MAJOR_VERSION     			4U
#define 	FLSTST_CFG_H_AR_MINOR_VERSION     			2U
#define 	FLSTST_CFG_H_AR_PATCH_VERSION     			2U
#define 	FLSTST_CFG_H_SW_MAJOR_VERSION     			1U
#define 	FLSTST_CFG_H_SW_MINOR_VERSION     			0U
#define 	FLSTST_CFG_H_SW_PATCH_VERSION     			0U 
/* Switches the development error detection and notification on or off */
#define FLSTST_DEV_ERROR_DETECT             STD_ON

/* Configures the Number of cells to be tested in background mode during
 * one scheduled task (FlsTst_MainFunction() call). */
#define FLSTST_TESTCELLS_NUM                0x8U

/* Configures the Number of cells to be tested in background mode without
 * checking user requests (Abort, Suspend). */
#define FLSTST_TESTCELL_LENGTH_ATOMIC       0x80U

/* Defines the end value of the Test Interval Id. */
#define FLSTST_TEST_INTERVALID_END_VALUE    0x100U

/* Switch to indicate that the notification is supported. */
#define FLSTST_COMPLETED_NOTIFY_SUPPORT     STD_ON

/* Adds / removes ECC related register initialization at FlsTst_Init */
#define FLSTST_INIT_ECC                     STD_ON

/* Time out value of Fgnd test */
#define FLSTST_FGND_TIMEOUT                 0x10000U

/*  Enable/Disable the extended safety mechanism. */
#define FLSTST_EXTEND_SAFETY_MODE           STD_ON

/* Adds / removes the service FlsTst_GetCurrentState() from the code */
#define FLSTST_GET_CURRENT_STATE_API        STD_ON

/* Adds / removes the service FlsTst_GetErrorDetails() from the code. */
#define FLSTST_GET_ERRORD_ETAILS_API        STD_ON

/* Adds / removes the service FlsTst_GetTestResultBgnd() from the code. */
#define FLSTST_GET_TEST_RESULT_BGND_API     STD_ON

/* Adds / removes the service FlsTst_GetTestResultFgnd() from the code. */
#define FLSTST_GET_TEST_RESULT_FGND_API     STD_ON

/* Adds / removes the service FlsTst_GetTestSignatureBgnd() from the code. */
#define FLSTST_GET_TEST_SIGNATURE_BGND_API  STD_ON

/* Adds / removes the service FlsTst_GetTestSignatureFgnd() from the code. */
#define FLSTST_GET_TEST_SIGNATURE_FGND_API  STD_ON

/* Adds / removes the service FlsTst_StartFgnd() from the code */
#define FLSTST_START_FGND_API               STD_ON

/* Adds / removes the services FlsTst_Suspend() and FlsTst_Resume() from the code.*/
#define FLSTST_SUSPEND_RESUME_API           STD_ON

/* Adds / removes the service FlsTst_TestEcc() from the code. */
#define FLSTST_TEST_ECC_API                 STD_ON

/* Adds / removes the service FlsTst_GetVersionInfo() from the code. */
#define FLSTST_VERSION_INFO_API             STD_ON

/* Define the totle number of Flash blocks in background test */
#define FLSTST_BGND_BLOCK_NUM               1u

/* Define the totle number of Flash blocks in foreground test */
#define FLSTST_FGND_BLOCK_NUM               1u

/* Declaration of the Configuration data. */
#define FLSTST_START_CONST_PBCFG
#include "FlsTst_MemMap.h"
extern CONST( FlsTst_ConfigType, FLSTST_CONST) FlsTst_Config;
#define FLSTST_STOP_CONST_PBCFG
#include "FlsTst_MemMap.h"


/* Declaration of the callback function. */
#define FLSTST_START_SEC_CODE
#include "FlsTst_MemMap.h"
extern void FlsTst_Notify(void);
#define FLSTST_START_SEC_CODE
#include "FlsTst_MemMap.h"

#endif

