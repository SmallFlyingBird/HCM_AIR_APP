/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "ASW_Manager.h"
#include "FrontCrossLamp.h"
#include "Fan.h"
#include <stdlib.h>
#include <math.h>
#include "DCMotor.h"
#include "Cdd_Driver_Manager.h"
#include "LinManager.h"
#include "Lighting.h"
#include "AdcDev_Interface.h"
#include "PowerSupply_Interface.h"
#include "Dio_Service.h"
#include "Pwm_Service.h"
#include "LB.h"
#include "LRDirection_Interface.h"
#include "NtcDerate_Interface.h"
#include "OUVDerate_Interface.h"
#include "BuckDerate_Interface.h"
#include "DerateRatioManager_Interface.h"
#include "SystemService_Interface.h"
/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
uint32 task_mscnt[10]={0}; //test code
/* 5ms任务 */
void ASW_Manager_MainFunction_5ms(void)
{
    task_mscnt[0]++;
    Channel_Interface_TimerMainFunction(5);
    AdcDev_Interface_Mainfunction(5);
}
//10ms
void ASW_Manager_MainFunction_10ms(void)
{
    task_mscnt[1]++;
    SystemService_MainFunction(10);//BUCK reInit
    Lin_Mainfunction(10);
    Light_Manager(10);  //lighting
    BuckInterfaceMainFuntion(10);//BUCK read vol temp ;BD18397 main function
    PowerSupplyMainFunction(10);//power read adc and calculate
    AdcDev_Interface_Mainfunction(10);
    OUVDerateMainFunction(10); //get vol,derate or not ,derate pwm ; 
    Channel_Interface_MainFunction(10); //BUCK read err       
}


/* 20ms任务 */
void ASW_Manager_MainFunction_20ms(void)
{
    HighSide_Interface_Mainfunction(20); //HSD dtc
    HSDManage_MainFunction(20); //HSD RUN
    RcodInterface_Mainfunction(20); //Rcod RUN
}


/* 50ms任务 */
void ASW_Manager_MainFunction_50ms(void)
{
    DCMotor_MainFunction(50); //DC RUN and ERR
}

/* 100ms任务 */
void ASW_Manager_MainFunction_100ms(void)
{
    BuckDerateMainFunction(100); //get temp ,calculate derate pwm
    // Fan_MainFunction(100);
    NtcInterface_Mainfunction(100);
    NtcDerateMainFunction(100);
}

/* Init */
void ASW_Manager_Init(void)
{
    Port_Init_All(); 
    Pwm_Init_All();
/* parameter init */
    DCMotor_Init();  //dc parameter read
    HSDManage_Init();
    Fan_Init();
    /* device init */
    CDD_Init();
    Interface_HighSideInit();    
    Interface_ChannelInit();
    Interface_BuckInit();
    DirectionInterface_Init();
    Interface_NtcRcodInit();
    Interface_DtcInit(); //set the dtc bit0 =0
    Lighting_Init(); 
}

