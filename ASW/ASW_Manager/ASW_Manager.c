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
uint32 task_mscnt[10]={0};
/* 5ms任务 */
void ASW_Manager_MainFunction_5ms(void)
{
    task_mscnt[0]++;
    Channel_Interface_TimerMainFunction(5);
}
//10ms
void ASW_Manager_MainFunction_10ms(void)
{
    task_mscnt[1]++;
    SystemService_MainFunction(10);//BUCK重新初始化
    Lin_Mainfunction(10);
    Channel_Interface_MainFunction(10); //BUCK read err 
    BuckInterfaceMainFuntion(10);//BUCK read vol temp
    PowerSupplyMainFunction(10);//电源采样和计算
    AdcDev_Interface_Mainfunction(10);
    OUVDerateMainFunction(10); //电压获取 判断是否降额 降额占空比  处理降额的函数在100ms 后面看是否可以放100ms内
    Light_Manager(10);  //点灯
}


/* 20ms任务 */
void ASW_Manager_MainFunction_20ms(void)
{
    // HighSide_Interface_Mainfunction(20); //高边诊断
    // HSDManage_MainFunction(20);
    RcodInterface_Mainfunction(20);
}


/* 50ms任务 */
void ASW_Manager_MainFunction_50ms(void)
{
    DCMotor_MainFunction(50); //直流电机 运行 故障
}

/* 100ms任务 */
void ASW_Manager_MainFunction_100ms(void)
{
    NtcDerateMainFunction(100);
    BuckDerateMainFunction(100); //获取温度，求均值，求均值的降额比例 
    // Fan_MainFunction(100);
    NtcInterface_Mainfunction(100);
}

/* 初始化 */
Std_ReturnType ASW_Manager_Init(void)
{
    Std_ReturnType rtval = E_OK;

    Port_Init_All(); //初始化IO口
    Pwm_Init_All();
 //配置表初始化
    DCMotor_Init();  //直流电机  配置表数据读取
    HSDManage_Init();
    Fan_Init();
//驱动初始化

    rtval |= CDD_Init();
    rtval |= Interface_HighSideInit();    
    rtval |= Interface_ChannelInit();
    rtval |= Interface_BuckInit();
    rtval |= DirectionInterface_Init();
    rtval |= Interface_NtcRcodInit();
    // rtval |= Interface_DIDInit();
    rtval |= Interface_DtcInit();
    Lighting_Init();//放所有初始化的后面 对前面参数表接口的调用
    return rtval;
}

