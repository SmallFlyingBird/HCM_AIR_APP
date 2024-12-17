/*============================================================================*/
/*  Copyright (C) iSOFT   (2020), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Os_Cfg.c>
 *  @brief      <>
 *  
 *  <MCU:S32K14X>
 *  
 *  @author     <>
 *  @date       <2024-12-16 14:21:13>
 */
/*============================================================================*/


/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>      <DATE>     <AUTHOR>      <REVISION LOG>
 *   V1.0.0       20141111     bo.zeng      Initial version
 *   V1.1.0       20160418     shi.shu      Add SC34
 *   V2.0.0       20191121     shun.li      Functional safety version
 *	 V2.1.0       20200421     shun.li      Add IOC function
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/
#include "Os_Cfg.h"
#include "Os_CfgData.h"
#include "Os.h"
#include "Os_Processor.h"
#include "Os_Internal.h"

/*=======[V E R S I O N   I N F O R M A T I O N]===============================*/
#define OS_CFG_C_AR_MAJOR_VERSION     4U
#define OS_CFG_C_AR_MINOR_VERSION     2U
#define OS_CFG_C_AR_PATCH_VERSION     2U
#define OS_CFG_C_SW_MAJOR_VERSION     1U
#define OS_CFG_C_SW_MINOR_VERSION     0U
#define OS_CFG_C_SW_PATCH_VERSION     0U 

/*=======[V E R S I O N  C H E C K]===========================================*/
#if (OS_CFG_C_AR_MAJOR_VERSION != OS_CFG_H_AR_MAJOR_VERSION)
    #error "Os_Cfg.c:Mismatch in Specification Major Version"
#endif 
#if (OS_CFG_C_AR_MINOR_VERSION != OS_CFG_H_AR_MINOR_VERSION)
    #error "Os_Cfg.c:Mismatch in Specification Minor Version"
#endif
#if (OS_CFG_C_AR_PATCH_VERSION != OS_CFG_H_AR_PATCH_VERSION)
    #error "Os_Cfg.c:Mismatch in Specification Patch Version"
#endif
#if (OS_CFG_C_SW_MAJOR_VERSION != OS_CFG_H_SW_MAJOR_VERSION)
    #error "Os_Cfg.c:Mismatch in Specification Major Version"
#endif
#if (OS_CFG_C_SW_MINOR_VERSION != OS_CFG_H_SW_MINOR_VERSION)
    #error "Os_Cfg.c:Mismatch in Specification Minor Version"
#endif

/*=======[M A C R O S]========================================================*/
#define  OS_STACK_TOP(stack)    ((Os_StackPtrType)((&(stack)[0]) + (sizeof(stack) / sizeof((stack)[0]))))
#define  OS_STACK_BOTTOM(stack) ((Os_StackPtrType)(stack))

/*=======[I N T E R N A L   D A T A]==========================================*/
/* Ready Queue Manager */

#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core0_0[1];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core0_1[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core0_2[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core0_3[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core0_4[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core0_5[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core0_6[2];
static VAR(Os_TaskType, OS_VAR) Os_ActivateQueue_Core0_7[5];   
VAR(Os_ReadyQueueType, OS_VAR)  Os_ReadyQueueMark_Core0[CFG_PRIORITY_MAX_CORE0];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONSTP2VAR(Os_TaskType, OS_CONST, OS_VAR) Os_ReadyQueue_Core0[CFG_PRIORITY_MAX_CORE0] = 
{
    Os_ActivateQueue_Core0_0,   
    Os_ActivateQueue_Core0_1,   
    Os_ActivateQueue_Core0_2,   
    Os_ActivateQueue_Core0_3,   
    Os_ActivateQueue_Core0_4,   
    Os_ActivateQueue_Core0_5,   
    Os_ActivateQueue_Core0_6,   
    Os_ActivateQueue_Core0_7,       
};

CONST(uint32, OS_CONST) Os_ActivateQueueSize_Core0[CFG_PRIORITY_MAX_CORE0] = 
{
    1, 
    2,      
    2,      
    2,      
    2,      
    2,      
    2,      
    5,     
};
    
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_PriorityType, OS_CONST) Os_PrioGroupCore0[CFG_PRIORITY_MAX_CORE0] = 
{
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,    
};

CONST(Os_PriorityType, OS_CONST) Os_PrioMaskCore0[CFG_PRIORITY_MAX_CORE0] = 
{
    0x0001,
    0x0002,
    0x0004,
    0x0008,
    0x0010,
    0x0020,
    0x0040,
    0x0080,    
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"


/* ------------------------stack Management---------------------- */
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_SysStack_Core0[1024];	
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_StackType, OS_CONST) Os_SystemStackCore0 =
{
    OS_STACK_TOP(Os_SysStack_Core0), OS_STACK_BOTTOM(Os_SysStack_Core0)		
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
	
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask_100ms_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"	
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask_10ms_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"	
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask_1ms_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"	
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask_2ms_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"	
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask_50ms_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"	
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask_5ms_Stack[1024];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"	
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_OsTask_Init_Stack[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_TaskStack_Idle_Core0[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_StackType, OS_CONST) Os_TaskStackCore0[CFG_TASK_MAX_CORE0] = 
{	
	{OS_STACK_TOP(Os_OsTask_100ms_Stack), OS_STACK_BOTTOM(Os_OsTask_100ms_Stack)},	
	{OS_STACK_TOP(Os_OsTask_10ms_Stack), OS_STACK_BOTTOM(Os_OsTask_10ms_Stack)},	
	{OS_STACK_TOP(Os_OsTask_1ms_Stack), OS_STACK_BOTTOM(Os_OsTask_1ms_Stack)},	
	{OS_STACK_TOP(Os_OsTask_2ms_Stack), OS_STACK_BOTTOM(Os_OsTask_2ms_Stack)},	
	{OS_STACK_TOP(Os_OsTask_50ms_Stack), OS_STACK_BOTTOM(Os_OsTask_50ms_Stack)},	
	{OS_STACK_TOP(Os_OsTask_5ms_Stack), OS_STACK_BOTTOM(Os_OsTask_5ms_Stack)},	
	{OS_STACK_TOP(Os_OsTask_Init_Stack), OS_STACK_BOTTOM(Os_OsTask_Init_Stack)},
    {OS_STACK_TOP(Os_TaskStack_Idle_Core0), OS_STACK_BOTTOM(Os_TaskStack_Idle_Core0)}
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_SysTimer_Stack_Core0[1024];/*system timer*/
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_ADC0_IRQHandler_Stack_Core0[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_ADC1_IRQHandler_Stack_Core0[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_DMA0_IRQHandler_Stack_Core0[500];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_ERM_double_fault_IRQHandler_Stack_Core0[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_ERM_single_fault_IRQHandler_Stack_Core0[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_FTFC_Fault_IRQHandler_Stack_Core0[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_LPIT0_Ch0_IRQHandler_Stack_Core0[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_LPUART1_RxTx_IRQHandler_Stack_Core0[512];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"
static VAR(Os_StackDataType, OS_VAR) Os_LVD_LVW_IRQHandler_Stack_Core0[100];
#define OS_STOP_SEC_VAR_STACK_CORE0
#include "Os_MemMap.h"


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_StackType, OS_CONST) Os_ISR2StackCore0[CFG_ISR2_MAX_CORE0] =
{
	{OS_STACK_TOP(Os_SysTimer_Stack_Core0), OS_STACK_BOTTOM(Os_SysTimer_Stack_Core0)},/*system timer*/	
	{OS_STACK_TOP(Os_ADC0_IRQHandler_Stack_Core0), OS_STACK_BOTTOM(Os_ADC0_IRQHandler_Stack_Core0)},
	{OS_STACK_TOP(Os_ADC1_IRQHandler_Stack_Core0), OS_STACK_BOTTOM(Os_ADC1_IRQHandler_Stack_Core0)},
	{OS_STACK_TOP(Os_DMA0_IRQHandler_Stack_Core0), OS_STACK_BOTTOM(Os_DMA0_IRQHandler_Stack_Core0)},
	{OS_STACK_TOP(Os_ERM_double_fault_IRQHandler_Stack_Core0), OS_STACK_BOTTOM(Os_ERM_double_fault_IRQHandler_Stack_Core0)},
	{OS_STACK_TOP(Os_ERM_single_fault_IRQHandler_Stack_Core0), OS_STACK_BOTTOM(Os_ERM_single_fault_IRQHandler_Stack_Core0)},
	{OS_STACK_TOP(Os_FTFC_Fault_IRQHandler_Stack_Core0), OS_STACK_BOTTOM(Os_FTFC_Fault_IRQHandler_Stack_Core0)},
	{OS_STACK_TOP(Os_LPIT0_Ch0_IRQHandler_Stack_Core0), OS_STACK_BOTTOM(Os_LPIT0_Ch0_IRQHandler_Stack_Core0)},
	{OS_STACK_TOP(Os_LPUART1_RxTx_IRQHandler_Stack_Core0), OS_STACK_BOTTOM(Os_LPUART1_RxTx_IRQHandler_Stack_Core0)},
	{OS_STACK_TOP(Os_LVD_LVW_IRQHandler_Stack_Core0), OS_STACK_BOTTOM(Os_LVD_LVW_IRQHandler_Stack_Core0)},
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

/* -------------------------Task Management---------------------- */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"                                                                                    
CONST(Os_TaskCfgType, OS_CONST) Os_TaskCfgCore0[CFG_TASK_MAX_CORE0] = 
{
	{
        &Os_TaskEntry_OsTask_100ms,   	/*osTaskEntry*/      
        Os_GetObjLocalId(OsTask_100ms),   /*osTaskStackId*/                                                  
        1,    							/*osTaskActivation*/                        
        1,  							/*osTaskPriority*/                       
        OS_PREEMPTIVE_FULL,				/*osTaskSchedule*/
        0U,								/*osRsv1*/
        OS_NULL_APPMODE,				/*osTaskAutoStartMode*/                      
    },
	{
        &Os_TaskEntry_OsTask_10ms,   	/*osTaskEntry*/      
        Os_GetObjLocalId(OsTask_10ms),   /*osTaskStackId*/                                                  
        1,    							/*osTaskActivation*/                        
        3,  							/*osTaskPriority*/                       
        OS_PREEMPTIVE_FULL,				/*osTaskSchedule*/
        0U,								/*osRsv1*/
        OS_NULL_APPMODE,				/*osTaskAutoStartMode*/                      
    },
	{
        &Os_TaskEntry_OsTask_1ms,   	/*osTaskEntry*/      
        Os_GetObjLocalId(OsTask_1ms),   /*osTaskStackId*/                                                  
        1,    							/*osTaskActivation*/                        
        6,  							/*osTaskPriority*/                       
        OS_PREEMPTIVE_FULL,				/*osTaskSchedule*/
        0U,								/*osRsv1*/
        OS_NULL_APPMODE,				/*osTaskAutoStartMode*/                      
    },
	{
        &Os_TaskEntry_OsTask_2ms,   	/*osTaskEntry*/      
        Os_GetObjLocalId(OsTask_2ms),   /*osTaskStackId*/                                                  
        1,    							/*osTaskActivation*/                        
        5,  							/*osTaskPriority*/                       
        OS_PREEMPTIVE_FULL,				/*osTaskSchedule*/
        0U,								/*osRsv1*/
        OS_NULL_APPMODE,				/*osTaskAutoStartMode*/                      
    },
	{
        &Os_TaskEntry_OsTask_50ms,   	/*osTaskEntry*/      
        Os_GetObjLocalId(OsTask_50ms),   /*osTaskStackId*/                                                  
        1,    							/*osTaskActivation*/                        
        2,  							/*osTaskPriority*/                       
        OS_PREEMPTIVE_FULL,				/*osTaskSchedule*/
        0U,								/*osRsv1*/
        OS_NULL_APPMODE,				/*osTaskAutoStartMode*/                      
    },
	{
        &Os_TaskEntry_OsTask_5ms,   	/*osTaskEntry*/      
        Os_GetObjLocalId(OsTask_5ms),   /*osTaskStackId*/                                                  
        1,    							/*osTaskActivation*/                        
        4,  							/*osTaskPriority*/                       
        OS_PREEMPTIVE_FULL,				/*osTaskSchedule*/
        0U,								/*osRsv1*/
        OS_NULL_APPMODE,				/*osTaskAutoStartMode*/                      
    },
	{
        &Os_TaskEntry_OsTask_Init,   	/*osTaskEntry*/      
        Os_GetObjLocalId(OsTask_Init),   /*osTaskStackId*/                                                  
        1,    							/*osTaskActivation*/                        
        7,  							/*osTaskPriority*/                       
        OS_PREEMPTIVE_FULL,				/*osTaskSchedule*/
        0U,								/*osRsv1*/
        OSDEFAULTAPPMODE,				/*osTaskAutoStartMode*/                      
    },
    {
       	&Os_TaskEntry_IdleCore0,			/*osTaskEntry*/  						
		Os_GetObjLocalId(OS_TASK_IDLE_CORE0),	/*osTaskStackId*/					
		1,										/*osTaskActivation*/   									
		0,										/*osTaskPriority*/								
		OS_PREEMPTIVE_FULL,						/*osTaskSchedule*/						
		0U,										/*osRsv1*/								
		OS_ALL_APPMODE,							/*osTaskAutoStartMode*/         
		 	
    }        
};

CONST(uint16, OS_CONST) Os_ResourceAccessMask_OsTask_100ms[1] =
{	
	
    0x5U,	
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_OsTask_10ms[1] =
{	
	
    0x5U,	
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_OsTask_1ms[1] =
{	
	
    0x5U,	
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_OsTask_2ms[1] =
{	
	
    0x1U,	
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_OsTask_50ms[1] =
{	
	
    0x1U,	
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_OsTask_5ms[1] =
{	
	
    0x1U,	
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_OsTask_Init[1] =
{	
	
    0x7U,	
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_OS_TASK_IDLE_CORE0[1] =
{
	0x0000U	
};
P2CONST(uint16, OS_VAR, OS_CONST) Os_TaskResourceAccessMaskCore0[CFG_TASK_MAX_CORE0] =
{	
    Os_ResourceAccessMask_OsTask_100ms,
    Os_ResourceAccessMask_OsTask_10ms,
    Os_ResourceAccessMask_OsTask_1ms,
    Os_ResourceAccessMask_OsTask_2ms,
    Os_ResourceAccessMask_OsTask_50ms,
    Os_ResourceAccessMask_OsTask_5ms,
    Os_ResourceAccessMask_OsTask_Init,
	Os_ResourceAccessMask_OS_TASK_IDLE_CORE0,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

/* ------------------------Counter Management--------------------- */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_CounterCfgType, OS_CONST) Os_CounterCfgCore0[CFG_COUNTER_MAX_CORE0] = 
{	{    
		65535,	/*osCounterMaxAllowedValue*/
		1,	/*osCounterMinCycle*/
		1,	/*osCounterTicksPerBase*/
		COUNTER_HARDWARE,	/*osCounterType*/
		1000,	/*osSecondsPerTick*/   
	},
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
FUNC(void, OS_CODE) Os_ArchSystemTimerCore0(void)
{
    (void)Os_IncrementHardCounter(SystemTimer_Core0);
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

/* --------------------------Alarm Management---------------------- */
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_5ms(void)
{
    (void)ActivateTask(OsTask_5ms); 
}
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_50ms(void)
{
    (void)ActivateTask(OsTask_50ms); 
}
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_2ms(void)
{
    (void)ActivateTask(OsTask_2ms); 
}
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_1ms(void)
{
    (void)ActivateTask(OsTask_1ms); 
}
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_10ms(void)
{
    (void)ActivateTask(OsTask_10ms); 
}
FUNC(void, OS_CODE) AlarmCallback_OsAlarm_100ms(void)
{
    (void)ActivateTask(OsTask_100ms); 
}
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_AlarmAutostartCfgType, OS_CONST) Os_AlarmAutostartCfgCore0[CFG_AUTO_ALARM_MAX_CORE0] = 
{
	{
		6,							/*osAlarmStartTime*/
		ALARM_AUTOSTART_RELATIVE,	/*osAlarmAutostartType*/
		100,						/*osAlarmCycleTime*/
		OSDEFAULTAPPMODE,			/*osAlarmAppMode*/	
	},

	{
		4,							/*osAlarmStartTime*/
		ALARM_AUTOSTART_RELATIVE,	/*osAlarmAutostartType*/
		10,						/*osAlarmCycleTime*/
		OSDEFAULTAPPMODE,			/*osAlarmAppMode*/	
	},

	{
		1,							/*osAlarmStartTime*/
		ALARM_AUTOSTART_RELATIVE,	/*osAlarmAutostartType*/
		1,						/*osAlarmCycleTime*/
		OSDEFAULTAPPMODE,			/*osAlarmAppMode*/	
	},

	{
		2,							/*osAlarmStartTime*/
		ALARM_AUTOSTART_RELATIVE,	/*osAlarmAutostartType*/
		2,						/*osAlarmCycleTime*/
		OSDEFAULTAPPMODE,			/*osAlarmAppMode*/	
	},

	{
		5,							/*osAlarmStartTime*/
		ALARM_AUTOSTART_RELATIVE,	/*osAlarmAutostartType*/
		50,						/*osAlarmCycleTime*/
		OSDEFAULTAPPMODE,			/*osAlarmAppMode*/	
	},

	{
		3,							/*osAlarmStartTime*/
		ALARM_AUTOSTART_RELATIVE,	/*osAlarmAutostartType*/
		5,						/*osAlarmCycleTime*/
		OSDEFAULTAPPMODE,			/*osAlarmAppMode*/	
	},

};

CONST(Os_AlarmCfgType, OS_CONST) Os_AlarmCfgCore0[CFG_ALARM_MAX_CORE0] =
{
	{
		Os_GetObjLocalId(SystemTimer_Core0),	/*osAlarmCounter*/
        &Os_AlarmAutostartCfgCore0[0],	/*osAlarmAutostartRef*/			
        &AlarmCallback_OsAlarm_100ms,	/*osAlarmCallback*/		
	},
	{
		Os_GetObjLocalId(SystemTimer_Core0),	/*osAlarmCounter*/
        &Os_AlarmAutostartCfgCore0[1],	/*osAlarmAutostartRef*/			
        &AlarmCallback_OsAlarm_10ms,	/*osAlarmCallback*/		
	},
	{
		Os_GetObjLocalId(SystemTimer_Core0),	/*osAlarmCounter*/
        &Os_AlarmAutostartCfgCore0[2],	/*osAlarmAutostartRef*/			
        &AlarmCallback_OsAlarm_1ms,	/*osAlarmCallback*/		
	},
	{
		Os_GetObjLocalId(SystemTimer_Core0),	/*osAlarmCounter*/
        &Os_AlarmAutostartCfgCore0[3],	/*osAlarmAutostartRef*/			
        &AlarmCallback_OsAlarm_2ms,	/*osAlarmCallback*/		
	},
	{
		Os_GetObjLocalId(SystemTimer_Core0),	/*osAlarmCounter*/
        &Os_AlarmAutostartCfgCore0[4],	/*osAlarmAutostartRef*/			
        &AlarmCallback_OsAlarm_50ms,	/*osAlarmCallback*/		
	},
	{
		Os_GetObjLocalId(SystemTimer_Core0),	/*osAlarmCounter*/
        &Os_AlarmAutostartCfgCore0[5],	/*osAlarmAutostartRef*/			
        &AlarmCallback_OsAlarm_5ms,	/*osAlarmCallback*/		
	},
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"

/* -------------------------Resource Management------------------ */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_ResourceCfgType, OS_CONST) Os_ResourceCfgCore0[CFG_STD_RESOURCE_MAX_CORE0] = 
{  
    {
     7U,	/*ceiling*/
     OCCUPIED_BY_TASK,	/*resourceOccupyType*/
     0U,/*rsv1*/     
     },   
    {
     7U,	/*ceiling*/
     OCCUPIED_BY_TASK,	/*resourceOccupyType*/
     0U,/*rsv1*/     
     },   
    {
     15U,	/*ceiling*/
     OCCUPIED_BY_TASK_OR_INTERRUPT,	/*resourceOccupyType*/
     0U,/*rsv1*/     
     }, 	 
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"



/* -----------------------ISR Management-------------------------- */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"
CONST(Os_IsrCfgType, OS_CONST) Os_IsrCfgCore0[CFG_ISR_MAX_CORE0] =
{    
    {
        OS_ISR_CATEGORY2,	/*OsIsrCatType*/
        TRUE,	/*OsNestedEnable*/      
    },    
   	    
    {
        OS_ISR_CATEGORY2,	/*OsIsrCatType*/ 
        TRUE,				/*OsNestedEnable*/          
    },    
    {
        OS_ISR_CATEGORY2,	/*OsIsrCatType*/ 
        TRUE,				/*OsNestedEnable*/          
    },    
    {
        OS_ISR_CATEGORY2,	/*OsIsrCatType*/ 
        TRUE,				/*OsNestedEnable*/          
    },    
    {
        OS_ISR_CATEGORY2,	/*OsIsrCatType*/ 
        TRUE,				/*OsNestedEnable*/          
    },    
    {
        OS_ISR_CATEGORY2,	/*OsIsrCatType*/ 
        TRUE,				/*OsNestedEnable*/          
    },    
    {
        OS_ISR_CATEGORY2,	/*OsIsrCatType*/ 
        TRUE,				/*OsNestedEnable*/          
    },    
    {
        OS_ISR_CATEGORY2,	/*OsIsrCatType*/ 
        TRUE,				/*OsNestedEnable*/          
    },    
    {
        OS_ISR_CATEGORY2,	/*OsIsrCatType*/ 
        FALSE,				/*OsNestedEnable*/          
    },    
    {
        OS_ISR_CATEGORY2,	/*OsIsrCatType*/ 
        TRUE,				/*OsNestedEnable*/          
    },    
    {
        OS_ISR_CATEGORY1,	/*OsIsrCatType*/  
        FALSE,				/*OsNestedEnable*/           
    },
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_SysTick_Handler[1] =
{
	0x1U    
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ADC0_IRQHandler[1] =
{	

    0x0U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ADC1_IRQHandler[1] =
{	

    0x0U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_DMA0_IRQHandler[1] =
{	

    0x0U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ERM_double_fault_IRQHandler[1] =
{	

    0x0U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_ERM_single_fault_IRQHandler[1] =
{	

    0x0U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_FTFC_Fault_IRQHandler[1] =
{	

    0x0U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_LPIT0_Ch0_IRQHandler[1] =
{	

    0x4U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_LPUART1_RxTx_IRQHandler[1] =
{	

    0x0U,
};
CONST(uint16, OS_CONST) Os_ResourceAccessMask_LVD_LVW_IRQHandler[1] =
{	

    0x0U,
};
P2CONST(uint16, OS_VAR, OS_CONST) Os_IsrResourceAccessMaskCore0[CFG_ISR2_MAX_CORE0] =
{
	Os_ResourceAccessMask_SysTick_Handler,	
    Os_ResourceAccessMask_ADC0_IRQHandler,
    Os_ResourceAccessMask_ADC1_IRQHandler,
    Os_ResourceAccessMask_DMA0_IRQHandler,
    Os_ResourceAccessMask_ERM_double_fault_IRQHandler,
    Os_ResourceAccessMask_ERM_single_fault_IRQHandler,
    Os_ResourceAccessMask_FTFC_Fault_IRQHandler,
    Os_ResourceAccessMask_LPIT0_Ch0_IRQHandler,
    Os_ResourceAccessMask_LPUART1_RxTx_IRQHandler,
    Os_ResourceAccessMask_LVD_LVW_IRQHandler,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap.h"



/* -----------------Control block definition--------------------- */
/*
 * Private data,be accessed by own core.
 */
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_TCBType volatile, OS_VAR) Os_TCBCore0[CFG_TASK_MAX_CORE0];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"








#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_CCBType volatile, OS_VAR) Os_CCBCore0[CFG_COUNTER_MAX_CORE0];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"


#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_ACBType volatile, OS_VAR) Os_ACBCore0[CFG_ALARM_MAX_CORE0];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"


#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_RCBType volatile, OS_VAR) Os_RCBCore0[CFG_STD_RESOURCE_MAX_CORE0];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"




#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_ICBType volatile,  OS_VAR) Os_ICBCore0[CFG_ISR2_MAX_CORE0];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"


/*
 * Private data, be accessed by own core.
 */
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
VAR(Os_IsrType,  OS_VAR) Os_SysIsrNestQueueCore0[CFG_ISR2_MAX_CORE0];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"


/*
 * Global data, be accessed by all core.
 */
Os_CoreCBType volatile				Os_CoreCB;

/*
 * Clone data, Each core has a copy.
 */
#define OS_START_SEC_VAR_CLONE_32
#include "Os_MemMap.h"
VAR(Os_SCBType volatile, OS_VAR)	Os_SCB;
#define OS_STOP_SEC_VAR_CLONE_32
#include "Os_MemMap.h"


/*=======[E N D   O F   F I L E]==============================================*/

