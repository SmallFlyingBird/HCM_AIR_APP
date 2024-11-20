/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Os_UserInf.c>
 *  @brief      <>
 *  
 *  <MCU:Z20K148>
 *  
 *  @author     <>
 *  @date       <2024-05-07 13:45:59>
 */
/*============================================================================*/

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>      <DATE>     <AUTHOR>      <REVISION LOG>
 *   V1.0.0       20141111     bo.zeng      Initial version
 *   V2.0.0       20170615     shi.shu      Multicore
 *   V3.0.0       20191121     shun.li      Functional safety version
 *   V3.1.0       20200421     shun.li      Add IOC function
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/
#include "Os.h"
#include "Os_Extend.h"
#include "Os_Processor.h"
#include "Mcu.h"
/* #include "McalLib.h" */
#include "Port.h"
#include "Wdg.h"
#include "Adc.h"
#include "Can.h"
#include "Dio.h"
#include "Spi.h"
#include "Uart.h"
#include "CDD_Dma.h"
#include "Gpt.h"
#include "Can_Drv.h"
#include "Dio_Service.h"
#include "Gpt_Service.h"
#include "Spi.h"
#include "Icu.h"
#include "Pwm.h"
#include "Uart.h"

#include "CanIf.h"
#include "CanSM.h"
#include "PduR.h"
#include "Com.h"
#include "ComM.h"
#include "ComM_Gent.h"
#include "CanNm.h"
#include "BswM.h"
#include "EcuM.h"
#include "EcuM_Cbk.h"
#include "Xcp.h"
#include "Xcp_test.h"
#include "SchM_Xcp.h"
#include "SchM_EcuM.h"
#include "SchM_BswM.h"
#include "CanTp.h"
#include "Dcm.h"
#include "Dem.h"
#include "WdgIf.h"
#include "WdgM.h"
#include "Rte_E2EXf.h"

#include "Fls.h"
#include "Fee.h"
#include "NvM.h"
#include "string.h"
#include "FlsTst.h"

#include "NmHistoryState.h"

#include "Cdd_Driver_Manager.h"
#include "AswInterfaceManager.h"
#include "ASW_Manager.h"
#include "ComSignal_Interface.h"

#include "Interrupt_Drv_Cfg.h"

#include "HcmPlatform.h"
#include "Cdd_Driver_Manager.h"
#include "AswInterfaceManager.h"
#include "Channel_Interface.h"
#include "ComSignal_Interface.h"
#include "HighSide_Interface.h"
#include "SafetyDrv.h"

#include "NmHistoryState.h"
#if(BASE_TECH_PLATFORM == BASE_TECH_3_0)
/*3.0平台支持27服务，需要随机数*/ 
#include "Crypto.h"
#endif
#include "NvM.h"

/*=======[V E R S I O N   I N F O R M A T I O N]===============================*/
#define OS_USERAPP_C_AR_MAJOR_VERSION     4U
#define OS_USERAPP_C_AR_MINOR_VERSION     2U
#define OS_USERAPP_C_AR_PATCH_VERSION     2U
#define OS_USERAPP_C_SW_MAJOR_VERSION     1U
#define OS_USERAPP_C_SW_MINOR_VERSION     0U
#define OS_USERAPP_C_SW_PATCH_VERSION     0U

/*=======[V E R S I O N  C H E C K]===========================================*/
#if (OS_USERAPP_C_AR_MAJOR_VERSION != OS_CFG_H_AR_MAJOR_VERSION)
    #error "Os_Userapp.c:Mismatch in Specification Major Version"
#endif
#if (OS_USERAPP_C_AR_MINOR_VERSION != OS_CFG_H_AR_MINOR_VERSION)
    #error "Os_Userapp.c:Mismatch in Specification Minor Version"
#endif
#if (OS_USERAPP_C_AR_PATCH_VERSION != OS_CFG_H_AR_PATCH_VERSION)
    #error "Os_Userapp.c:Mismatch in Specification Patch Version"
#endif
#if (OS_USERAPP_C_SW_MAJOR_VERSION != OS_CFG_H_SW_MAJOR_VERSION)
    #error "Os_Userapp.c:Mismatch in Specification Major Version"
#endif
#if (OS_USERAPP_C_SW_MINOR_VERSION != OS_CFG_H_SW_MINOR_VERSION)
    #error "Os_Userapp.c:Mismatch in Specification Minor Version"
#endif


uint32 _1msCnt = 0;
uint32 _2msCnt = 0;
uint32 _5msCnt = 0;
uint32 _10msCnt = 0;
uint32 _20msCnt = 0;
uint32 _50msCnt = 0;
uint32 _100msCnt = 0;
uint32 _1000msCnt = 0;
uint8 ECUReset = FALSE;
uint8 NvM_MutexStatus = STD_OFF;
uint8  FlsTst_StoredInfo[20] =
{
  0x00,0x00,0x5b,0x2f,  /*Crc result of Block0 */
 0x5a,0x5a,0x5a,0x5a, /*FlashTest Flag*/
  0x00,0x00,0x00,0x01, /*FlashTest Memory Block number*/
  0x01,0x00,0x60,0x00, /*Start Address of Block0  0x1006000*/
  0x00,0x00,0x01,0x00 /*Block size of Block0   0x1000*/
};
uint8 DataMessage[8]={0x55,0x1f,0,0,0,0,0,0};
/*=======[T A S K S]==========================================*/
/*OsTask_1ms: Core0(CPU0),Type = BASIC, Priority = 9*/
TASK(OsTask_1ms)
{
    _1msCnt++;
    CanSM_MainFunction();
    CanTp_MainFunction();
    /* please insert your code here ... */
    
   
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
/*OsTask_2ms: Core0(CPU0),Type = BASIC, Priority = 8*/
TASK(OsTask_2ms)
{
    /* please insert your code here ... */
    _2msCnt++;
    ASWInterfaceManagerMainFunc_2ms(); 
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
/*OsTask_5ms: Core0(CPU0),Type = BASIC, Priority = 7*/
TASK(OsTask_5ms)
{
    _5msCnt++;
    WdgM_MainFunction();
    CanNm_MainFunction();
    ComM_MainFunction_BodyExposedCAN_HCML();
    Com_MainFunctionRx();
    Com_MainFunctionTx();
#if MIHUILIANG  
#endif
    /* please insert your code here ... */
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
/*OsTask_10ms: Core0(CPU0),Type = BASIC, Priority = 6*/
TASK(OsTask_10ms)
{
    _10msCnt++;
//  Interface_SetHighSideState(E_HSChannel_HS3, E_HSDChannelSwitchState_ON);   
#if (QINGHAIGANG) && (QHG_DMONI_orXCP)
    DMoni_Run10ms();
#else
    Xcp_MainFunction();
	Xcp_EventIndication(EventChannel_0);
#endif  /*(QINGHAIGANG) && (QHG_DMONI_orXCP)*/
    EcuM_MainFunction();
    BswM_MainFunction();
    Dcm_MainFunction();
    Dem_MainFunction();
    WdgM_CheckpointReached(WdgMSupervisedEntity_0,SE0_WdgMCheckpoint_Alive_10ms);    
     
#if MIHUILIANG
#endif
    ASWInterfaceManagerMainFunc_10ms();
    ASW_Manager_MainFunction_10ms();

    if(STD_OFF == NvM_MutexStatus)
    {
        NvM_MainFunction();
	    Fee_MainFunction();
	    Fls_MainFunction();
    }
    
    //   Interface_SetHighSideState(E_HSChannel_HS3, E_HSDChannelSwitchState_OFF);
    
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
/*OsTask_20ms: Core0(CPU0),Type = BASIC, Priority = 5*/
TASK(OsTask_20ms)
{
    _20msCnt++;

    #if (QINGHAIGANG)
    #if (BUILD_PROJECT_ID == 1)    /*EPT*/
    if (QINGHAIGANG_b_noNM)
    {   /*no MN*/
        EcuM_SetWakeupEvent(32);
        Interface_SetKeepAwakeFlag();
    }
    #endif  /*(BUILD_PROJECT_ID == 1)*/
    #endif  /*QINGHAIGANG*/

    /* please insert your code here ... */
    ASWInterfaceManagerMainFunc_20ms();
    ASW_Manager_MainFunction_20ms();
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
/*OsTask_50ms: Core0(CPU0),Type = BASIC, Priority = 4*/
TASK(OsTask_50ms)
{
    /* please insert your code here ... */
    _50msCnt++;
    ASW_Manager_MainFunction_50ms();
    // ASWInterfaceManagerMainFunc_50ms();
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
/*OsTask_100ms: Core0(CPU0),Type = BASIC, Priority = 3*/
TASK(OsTask_100ms)
{
    /* please insert your code here ... */
    ExWdg_Timer_20ms = 0;
    _100msCnt++;
    ASWInterfaceManagerMainFunc_100ms();
    ASW_Manager_MainFunction_100ms();
    
    NmHistoryState_MainFunction();

    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}
/*OsTask_1s: Core0(CPU0),Type = BASIC, Priority = 2*/
TASK(OsTask_1s)
{
    /* please insert your code here ... */
    _1000msCnt++;
    ASWInterfaceManagerMainFunc_1s();
    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}

/*OsTask_Init: Core0(CPU0),Type = BASIC, Priority = 1*/
uint32 RESET_NVM_USE_TIME = 0;
NvM_RequestResultType RequestResultPtr = NVM_REQ_NOT_OK;

TASK(OsTask_Init)
{

    Std_ReturnType FlsTstReturn;
	FlsTst_TestResultFgndType FgndBlockResult;
    initializePort();
    
    Wdg_Init(&Wdg_Config);
    Spi_Init(&Spi_Config);
    Adc_Init(&Adc_Config);
    Adc_SelfTest(AdcConf_AdcHwUnit_AdcHwUnit_0);
    Adc_SelfTest(AdcConf_AdcHwUnit_AdcHwUnit_1);
    E2EXf_Init(&E2EXf_Config);
    Dma_Init(NULL_PTR);
    Icu_Init(&Icu_Config);
    Icu_SetMode(ICU_MODE_NORMAL);
    Pwm_Init(&Pwm_Config);
    Uart0Drv_Init(0);
    Uart1Drv_Init(0);
    EcuM_StartupTwo();
#if(BASE_TECH_PLATFORM == BASE_TECH_3_0)
    Crypto_Init(NULL_PTR);
#endif
    
    ECUReset = TRUE;
    EcuM_SetWakeupEvent(EcuMWakeupSource_ByCAN);
    CanIf_SetControllerMode(CANIF_CANDRV_0_BodyExposedCAN_HCML,CANIF_CS_STARTED);
	
	/* ComM_RequestComMode(ComMUser_BodyExposedCAN_HCML,COMM_FULL_COMMUNICATION); */

    Xcp_Init(&Xcp_PBConfig); 
    Fls_Init(NULL_PTR);
    do{
        Fls_MainFunction();
    }while(MEMIF_IDLE!=Fls_GetStatus());

    #if 0
    Fls_Write(0x6200,FlsTst_StoredInfo,16);

    do{
        Fls_MainFunction();
    }while(MEMIF_IDLE!=Fls_GetStatus());
    #endif

/*     FlsTst_Init(&FlsTst_Config);
	FlsTstReturn = FlsTst_StartFgnd(0U);
	FgndBlockResult	= FlsTst_GetTestResultFgnd();
 */

    Fee_Init(&Fee_ConfigData);
    do{
        Fls_MainFunction();
        Fee_MainFunction();
    }while(MEMIF_IDLE!=Fee_GetStatus());

    NvM_Init(NULL_PTR);

    NvM_ReadAll();
    do
	{
		RESET_NVM_USE_TIME++;
		NvM_MainFunction();
		Fee_MainFunction();
		Fls_MainFunction();
		NvM_GetErrorStatus(0,&RequestResultPtr);
        if(RESET_NVM_USE_TIME == 500)
            break;
	}while (RequestResultPtr == NVM_REQ_PENDING);

    Dcm_Init(&Dcm_Cfg);
    Dem_Init(&DemPbCfg);
#ifdef GEELY20_SPECIFICATION_USED
	/*this should be called after NvM ReadAll,NmHistoryState data can be restored from NvM�� */
	NmHistoryState_PreInit();
	NmHistoryState_NvmReadyInit();
#endif

    /*10ms*/
    Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_0);
    Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_0,30000);
    /*20ms*/
    Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_1);
    Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_1,60000);

    Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_4);  // 1mhz
    Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_4,100);   // 10 10us / 100 100us ....

    Pwm_SetPeriodAndDuty(PwmConf_PwmChannel_ALS_NXT, 5000, 0);
    Pwm_SetPeriodAndDuty(PwmConf_PwmChannel_AFS_NXT, 5000, 0);
    Pwm_EnableNotification(PwmConf_PwmChannel_AFS_NXT, PWM_FALLING_EDGE);
    Pwm_EnableNotification(PwmConf_PwmChannel_ALS_NXT, PWM_FALLING_EDGE);

    WdgM_SetMode(WDGIF_SLOW_MODE);

    /* please insert your code here ... */
#if MIHUILIANG
    CDD_Init();
    AswInterfaceManagerInit();
    ASW_Manager_Init();
#endif
#if TUJIONGJIONG
    CDD_Init();
    AswInterfaceManagerInit();
    ASW_Manager_Init();

#if 0
    Interface_SetChannelCurrent(ChannelID1,  50);
    Interface_SetChannelCurrent(ChannelID2,  50);
    Interface_SetChannelCurrent(ChannelID3,  50);
    Interface_SetChannelCurrent(ChannelID4,  50);
    Interface_SetChannelCurrent(ChannelID5,  50);
    Interface_SetChannelCurrent(ChannelID6,  50);
    Interface_SetChannelCurrent(ChannelID7,  50);
    Interface_SetChannelCurrent(ChannelID8,  50);
    Interface_SetChannelCurrent(ChannelID9,  50);
    Interface_SetChannelCurrent(ChannelID10, 50);
    Interface_SetChannelCurrent(ChannelID11, 50);
    Interface_SetChannelCurrent(ChannelID12, 50);

    Interface_SetChannelPWM(ChannelID1,  100);
    Interface_SetChannelPWM(ChannelID2,  100);
    Interface_SetChannelPWM(ChannelID3,  100);
    Interface_SetChannelPWM(ChannelID4,  100);
    Interface_SetChannelPWM(ChannelID5,  100);
    Interface_SetChannelPWM(ChannelID6,  100);
    Interface_SetChannelPWM(ChannelID7,  100);
    Interface_SetChannelPWM(ChannelID8,  100);
    Interface_SetChannelPWM(ChannelID9,  100);
    Interface_SetChannelPWM(ChannelID10, 100);
    Interface_SetChannelPWM(ChannelID11, 100);
    Interface_SetChannelPWM(ChannelID12, 100);

    Interface_SetChannelSwitchState(ChannelID1,  CHANNEL_STATE_ON);
    Interface_SetChannelSwitchState(ChannelID2,  CHANNEL_STATE_ON);
    Interface_SetChannelSwitchState(ChannelID3,  CHANNEL_STATE_ON);
    Interface_SetChannelSwitchState(ChannelID4,  CHANNEL_STATE_ON);
    Interface_SetChannelSwitchState(ChannelID5,  CHANNEL_STATE_ON);
    Interface_SetChannelSwitchState(ChannelID6,  CHANNEL_STATE_ON);
    Interface_SetChannelSwitchState(ChannelID7,  CHANNEL_STATE_ON);
    Interface_SetChannelSwitchState(ChannelID8,  CHANNEL_STATE_ON);
    Interface_SetChannelSwitchState(ChannelID9,  CHANNEL_STATE_ON);
    Interface_SetChannelSwitchState(ChannelID10, CHANNEL_STATE_ON);
    Interface_SetChannelSwitchState(ChannelID11, CHANNEL_STATE_ON);
    Interface_SetChannelSwitchState(ChannelID12, CHANNEL_STATE_ON);

    Interface_SetHighSideState(E_HSChannel_HS0, E_HSDChannelSwitchState_ON);
    Interface_SetHighSideState(E_HSChannel_HS1, E_HSDChannelSwitchState_ON);
    Interface_SetHighSideState(E_HSChannel_HS2, E_HSDChannelSwitchState_ON);
    Interface_SetHighSideState(E_HSChannel_HS3, E_HSDChannelSwitchState_ON);
#endif

#endif

#if QINGHAIGANG
#if (TUJIONGJIONG == 0)
    CDD_Init();
    AswInterfaceManagerInit();
    ASW_Manager_Init();
#endif  /*(TUJIONGJIONG == 0)*/
<<<<<<< HEAD
    /* Dio_WriteChannel(DioConf_DioChannel_OUT_CON_5V, STD_HIGH); */
    // ADBB_Init();
=======
    /* Dio_WriteChannel(0x10, STD_HIGH); */
    ADBB_Init();
>>>>>>> d892f4d98da55125dfbc164c0084b55deb87a618
#if (QHG_DMONI_orXCP)
    DMoni_Init();
#endif  /*QHG_DMONI_orXCP*/
#endif  /*QINGHAIGANG*/

    SetRelAlarm(OsAlarm_1ms,1,1);
    SetRelAlarm(OsAlarm_2ms,3,2);
    SetRelAlarm(OsAlarm_5ms,5,5);
    SetRelAlarm(OsAlarm_10ms,7,10);
    SetRelAlarm(OsAlarm_20ms,9,20);
    SetRelAlarm(OsAlarm_50ms,11,50);
    SetRelAlarm(OsAlarm_100ms,13,100);
    SetRelAlarm(OsAlarm_1s,15,1000);

#if ECU_SAFETY
    SafetyStartupTest();
#endif

    if (E_OK != TerminateTask())
    {
        while (1)
        {
            /* dead loop */
        }
    }
}

void TaskNotification1ms(void){
    /**/
}

void TaskNotification20ms(void){

    SafetyTask20ms();
    ExWdg_Timer_20ms ++;
    if(ExWdg_Timer_20ms*20 <= ExWdgTimeout)
    {
        Dio_WriteChannel(DioConf_DioChannel_WD_Feed,STD_HIGH);
        ExWdgTimeout=(ExWdgTimeout-ExWdg_Timer_20ms*20);
    }
        
    Wdg_feed_flag = TRUE;

}

void TaskNotification10ms(void){
    if(TRUE == Wdg_feed_flag)
        Dio_WriteChannel(DioConf_DioChannel_WD_Feed,STD_LOW);
}

void TaskNotification50ms(void){
}

/*=======[ALARM CALL BACK]==========================================*/

/*=======[H O O K S]================================================*/
FUNC(void, OS_APPL_CODE) IdleHook_Core0(void)
{
    /* please insert your code here ... */
    while(1);
}
void ErrorHook(StatusType Error)
{
    /* please insert your code here ... */
}

void StartupHook(void)
{
    /* please insert your code here ... */
}

void ShutdownHook(StatusType Error)
{
    /* please insert your code here ... */
    EcuM_Shutdown();
}

/*=======[I S R S]================================================*/
/*
 *ISR(ADC0_IRQn: Core0(CPU0))
 */
ISR(ISR_OS_ADC0_IRQn)
{
    /* please insert your code here ... */
    Adc_Drv_0_IrqHandler();
}

/*
 *ISR(ADC1_IRQn: Core0(CPU0))
 */
ISR(ISR_OS_ADC1_IRQn)
{
    /* please insert your code here ... */
    Adc_Drv_1_IrqHandler();
}

/*
 *ISR(CAN6_BUSOFF_IRQn: Core0(CPU0))
 */
ISR(ISR_OS_CAN6_BUSOFF_IRQn)
{
    /* please insert your code here ... */
    Can_Drv_BusOffIntHandler(6U);
}

/*
 *ISR(CAN6_ECC_IRQn: Core0(CPU0))
 */
ISR(ISR_OS_CAN6_ECC_IRQn)
{
    /* please insert your code here ... */
    Can_Drv_EccIntHandler(6U);
}

/*
 *ISR(CAN6_ERROR_IRQn: Core0(CPU0))
 */
ISR(ISR_OS_CAN6_ERROR_IRQn)
{
    /* please insert your code here ... */
    Can_Drv_ErrorIntHandler(6U);
}

/*
 *ISR(CAN6_MSG_0_31_IRQn: Core0(CPU0))
 */
ISR(ISR_OS_CAN6_MSG_0_31_IRQn)
{
    /* please insert your code here ... */
    Can_Drv_IntHandler(6U, 0U, 31U);
}

/*
 *ISR(CAN6_MSG_32_63_IRQn: Core0(CPU0))
 */
ISR(ISR_OS_CAN6_MSG_32_63_IRQn)
{
    /* please insert your code here ... */
    Can_Drv_IntHandler(6U, 32U, 63U);
}

/*
 *ISR(CAN6_MSG_64_95_IRQn: Core0(CPU0))
 */
ISR(ISR_OS_CAN6_MSG_64_95_IRQn)
{
    /* please insert your code here ... */
    Can_Drv_IntHandler(6U, 64U, 95U);
}

/*
 *ISR(CAN6_MSG_96_127_IRQn: Core0(CPU0))
 */
ISR(ISR_OS_CAN6_MSG_96_127_IRQn)
{
    /* please insert your code here ... */
    Can_Drv_IntHandler(6U, 96U, 127U);
}

/*
 *ISR(CAN6_RX_WARNING_IRQn: Core0(CPU0))
 */
ISR(ISR_OS_CAN6_RX_WARNING_IRQn)
{
    /* please insert your code here ... */
    Can_Drv_RxWarnIntHandler(6U);
}

/*
 *ISR(CAN6_SELF_WKUP_IRQn: Core0(CPU0))
 */
ISR(ISR_OS_CAN6_SELF_WKUP_IRQn)
{
    /* please insert your code here ... */
    Can_Drv_WakeUpIntHandler(6U);
}

/*
 *ISR(CAN6_TX_WARNING_IRQn: Core0(CPU0))
 */
ISR(ISR_OS_CAN6_TX_WARNING_IRQn)
{
    /* please insert your code here ... */
    Can_Drv_TxWarnIntHandler(6U);
}
/*
 *ISR(CMU0_IRQn: Core0(CPU0))
 */
ISR(ISR_OS_CMU0_IRQn)
{
    /* please insert your code here ... */
    Cmu_Drv_0_IrqHandler();
}

/*
 *ISR(CMU1_IRQn: Core0(CPU0))
 */
ISR(ISR_OS_CMU1_IRQn)
{
    /* please insert your code here ... */
    Cmu_Drv_1_IrqHandler();
}

/*
 *ISR(CMU2_IRQn: Core0(CPU0))
 */
ISR(ISR_OS_CMU2_IRQn)
{
    /* please insert your code here ... */
    Cmu_Drv_2_IrqHandler();
}

/*
 *ISR(DMA_CH12_TX_COMPLETE_IRQn: Core0(CPU0))
 */
ISR(ISR_OS_DMA_CH12_TX_COMPLETE_IRQn)
{
    /* please insert your code here ... */
    Dma_Drv_Ch12IrqHandler();
}

/*
 *ISR(DMA_CH13_TX_COMPLETE_IRQn: Core0(CPU0))
 */
ISR(ISR_OS_DMA_CH13_TX_COMPLETE_IRQn)
{
    /* please insert your code here ... */
     Dma_Drv_Ch13IrqHandler();
}

/*
 *ISR(MCPWM0_CH_IRQn: Core0(CPU0))
 */
ISR(ISR_OS_MCPWM0_CH_IRQn)
{
    /* please insert your code here ... */
    Mcpwm_Drv_0_ChIrqHandler();
}

/*
 *ISR(MCPWM1_CH_IRQn: Core0(CPU0))
 */
ISR(ISR_OS_MCPWM1_CH_IRQn)
{
    /* please insert your code here ... */
    Mcpwm_Drv_1_ChIrqHandler();
}

/*
 *ISR(SERU_CHANNEL_ERR_IRQn: Core0(CPU0))
 */
ISR(ISR_OS_SERU_CHANNEL_ERR_IRQn)
{
    /* please insert your code here ... */
    Seru_Drv_ChErrIrqHandler();
}

/*
 *ISR(SERU_PARITY_ERR_IRQn: Core0(CPU0))
 */
ISR(ISR_OS_SERU_PARITY_ERR_IRQn)
{
    /* please insert your code here ... */
    Seru_Drv_ParityErrIrqHandler();
}

extern ISR(Stim_Drv_IrqHandler);
/*
 *ISR(STIM_IRQn: Core0(CPU0))
 */
ISR(ISR_OS_STIM_IRQn)
{
    /* please insert your code here ... */
    Stim_Drv_IrqHandler();
}

/*
 *ISR(TIM0_IRQn: Core0(CPU0))
 */
ISR(ISR_OS_TIM0_IRQn)
{
    /* please insert your code here ... */
    Tim_Drv_0_ChIrqHandler();
}
extern ISR(Tim_Drv_1_ChIrqHandler);
/*
 *ISR(TIM1_IRQn: Core0(CPU0))
 */
ISR(ISR_OS_TIM1_IRQn)
{
    /* please insert your code here ... */
    Tim_Drv_1_ChIrqHandler();
}

/*=======[E N D   O F   F I L E]==============================================*/

