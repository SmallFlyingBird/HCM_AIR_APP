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
**  FILENAME    : EcuM_Cfg.c                                                  **
**                                                                            **
**  Created on  :                                                             **
**  Author      :                                                             **
**  Vendor      :                                                             **
**  DESCRIPTION : Configuration constant variables for pre-compile            **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "EcuM.h"
#include "EcuM_Internal.h"
#include "BswM.h"

extern const BswM_ConfigType BswMPBCfg;

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
#define ECUM_START_SEC_CONST_16
#include "EcuM_MemMap.h"
/*EcuMOSResource, reference to a OS resource which is used to bring the ECU into
* sleep mode. In case of multi core each core shall have an own OsResource.*/
#if (1 >= ECUM_MAX_MCU_CORE_NUM)
CONST(ResourceType, ECUM_CONST) EcuM_OSResource = 0;
#else
CONST(ResourceType, ECUM_CONST) EcuM_OSResource[ECUM_MAX_MCU_CORE_NUM];
#endif
#define ECUM_STOP_SEC_CONST_16
#include "EcuM_MemMap.h"



#define ECUM_START_SEC_CONST_UNSPECIFIED
#include "EcuM_MemMap.h"

/*EcuM Wake up source configurations by pre-compile configure*/
CONST(EcuM_WakeupSourceCfgType, ECUM_CONST) \
EcuM_WkSourceCfgs[ECUM_MAX_WAKE_UP_SOURCE_NUM]=
{
	/*EcuMWakeupSource_Lin*/
	{
		4000,	                    /* EcuMCheckWakeupTimeout */
		4000,	                    /* EcuMValidationTimeout */
		EcuMWakeupSource_Lin_WKSID,	/* EcuMWakeupSourceId */
		FALSE,       	        /* EcuMWakeupSourcePolling */
		0xff,                      /* EcuMComMChannelRef,Maybe reference macro definition  */
		0u,                            /* reset Reason number */
		NULL_PTR, 		/* EcuMResetReasonRef */
	}
};
#define ECUM_STOP_SEC_CONST_UNSPECIFIED
#include "EcuM_MemMap.h"

#define ECUM_START_SEC_CONST_32
#include "EcuM_MemMap.h"
/*The normal MCU mode to be restored after a sleep.*/
CONST(Mcu_ModeType, ECUM_CONST) EcuM_NormalMcuMode=0;	/* EcuMNormalMcuModeRef,McuModeSettingConf->McuMode */
#define ECUM_STOP_SEC_CONST_32
#include "EcuM_MemMap.h"

#if (ECUM_MAX_PARTITION_NUM > 0)
#define ECUM_START_SEC_CONST_32
#include "EcuM_MemMap.h"
/*Partitions a ECUM run inside*/
#if (ECUM_MAX_MCU_CORE_NUM < 2)
/*single core MCU*/
CONST(ApplicationType, ECUM_CONST) EcuM_HostPartition = 1 ;	/* EcuMPartitionRef */
#else
/*Multi-core MCU, a ECUM for each core running AUTOSAR software*/
CONST(ApplicationType, ECUM_CONST) \
    EcuM_HostPartition[ECUM_MAX_MCU_CORE_NUM] = {0, 0, 0};	/* EcuMPartitionRef */
#endif
#define ECUM_STOP_SEC_CONST_32
#include "EcuM_MemMap.h"
#endif

#define ECUM_START_SEC_CONST_UNSPECIFIED
#include "EcuM_MemMap.h"
/*ECUM user configuration*/
CONST(EcuM_UserCfgType, ECUM_CONST) EcuM_UserCfgs[ECUM_MAX_USER_NUM]=
{
	/*EcuMFlexUserConfig_0*/
	{
		#if (ECUM_MAX_PARTITION_NUM > 1)
			0, 			   /*which "EcucPartition" the user of the EcuM is executed*/
		#endif
		#if (ECUM_MAX_MCU_CORE_NUM > 1)
			0xff,             /*The core id the user of ECUM is in*/
		#endif
            TRUE,          /*the user is allowed to call the EcuM_GoDown API*/
		#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
			FALSE,          /*the user is allowed to call the EcuM_SetClock API*/
		#endif
		    0              /* EcuMFlexUser */	
	}
};
#define ECUM_STOP_SEC_CONST_UNSPECIFIED
#include "EcuM_MemMap.h"




#define ECUM_START_SEC_CONST_32
#include "EcuM_MemMap.h"
/*RESET function configurations for configured RESET modes*/
CONST(EcuM_ResetFunctionType, ECUM_CONST) \
    EcuM_ResetFunctions[ECUM_MAX_RESET_MODE_NUM];
#define ECUM_STOP_SEC_CONST_32
#include "EcuM_MemMap.h"

#define ECUM_START_SEC_CONST_32
#include "EcuM_MemMap.h"
CONST(EcuM_GenBSWPbCfgType, ECUM_VAR_NO_INIT) EcuM_GenMcalConfig = 
{
    &BswMPBCfg
};
#define ECUM_STOP_SEC_CONST_32
#include "EcuM_MemMap.h"

CONST(EcuM_ConfigType, ECUM_VAR_NO_INIT) EcuM_Config =
{
    0x0ul,
    OSDEFAULTAPPMODE,
    {
        OsResource_0,
    },
    ECUM_SHUTDOWN_TARGET_OFF,
    0,
    &EcuM_GenMcalConfig
};
/*******************************************************************************
**                            General Notes                                   **
*******************************************************************************/
