/*
 * ASW_Manager.c
 *
 *  Created on: 2024.04.07
 *      Author: mihuiliang
 */

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
#include "LightingASW.h"
#include "DCMotor.h"
#include "Cdd_Driver_Manager.h"
#include "LinManager.h"
#include "Lighting.h"

#include "BuckDerate_Interface.h"
#include "AdcDev_Interface.h"
#include "PowerSupply_Interface.h"
#include "OUVDerate_Interface.h"
#include "Dio_Service.h"
#include "Pwm_Service.h"
#include "LB.h"
#include "LRDirection_Interface.h"
/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Global Variable Define                     *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
/* 5ms任务 */
void ASW_Manager_MainFunction_5ms(void)
{
// Channel_Interface_TimerMainFunction(2);
}

//10ms
void ASW_Manager_MainFunction_10ms(void)
{
//     ComSignalInterfaceMainFunction(10);//0.15
//     DtcInterfaceMainFunction(10);//0.60
//     SystemService_MainFunction(10);//1ms
    Lin_Mainfunction(10);
    Light_Manager(10);  //点灯
    Fan_MainFunction(10);
    Channel_Interface_MainFunction(10); //BUCK诊断ID0
    BuckInterfaceMainFuntion(10);//BUCK 读电压读故障
    
    OUVDerateMainFunction(10); //电压获取 判断是否降额 降额占空比
}


/* 20ms任务 */
void ASW_Manager_MainFunction_20ms(void)
{
    // RcodInterface_Mainfunction(20);
    HighSide_Interface_Mainfunction(20); //高边诊断
    HSDManage_MainFunction(20);
    // SystemService_MemoryJobMainFunction(20);
    PowerSupplyMainFunction(20);//电源采样和计算
    AdcDev_Interface_Mainfunction(20);
}


/* 50ms任务 */
void ASW_Manager_MainFunction_50ms(void)
{
    DCMotor_MainFunction(50); //直流电机 运行 故障
}


/* 100ms任务 */
void ASW_Manager_MainFunction_100ms(void)
{
    //     NtcInterface_Mainfunction(100);
//     NtcDerateMainFunction(100);
//     DerateRatioManagerFuncmain(100);
//     DID_Interface_Mainfunction(100);
 // SystemService_FlsTstMainFunction(1000);
    BuckDerateMainFunction(100);
    // Fan_MainFunction(100);
    // DidSignalManagerMainFunction(100);
}


/* 初始化 */
Std_ReturnType ASW_Manager_Init(void)
{
    Std_ReturnType rtval = E_OK;

    Port_Init_All(); //初始化IO口
    Pwm_Init_All();
 //配置表初始化
    LowBeam_Init();
    DCMotor_Init();  //直流电机  配置表数据读取
    HSDManage_Init();
    // Fan_Init();
//驱动初始化

    rtval |= CDD_Init();
    rtval |= Interface_HighSideInit();    
    // rtval |= Interface_ChannelInit();
    rtval |= Interface_BuckInit();
    // rtval |= DirectionInterface_Init();
    // rtval |= Interface_NtcRcodInit();
    // rtval |= Interface_DIDInit();
    // rtval |= Interface_DtcInit();
    // Light_Parameter_Init();//放所有初始化的后面 对前面参数表接口的调用
    return rtval;
}

