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
    //     BuckInterfaceMainFuntion(10); //4MS
//     Channel_Interface_MainFunction(10);//0.25
//     ComSignalInterfaceMainFunction(10);//0.15
//     DtcInterfaceMainFunction(10);//0.60
//     SystemService_MainFunction(10);//1ms
//     OUVDerateMainFunction(10);//1ms
    Lin_Mainfunction(10);
    Light_Manager(10);  //点灯
    Fan_MainFunction(10);
    Channel_Interface_MainFunction(10); //BUCK诊断ID0
    BuckInterfaceMainFuntion(10);//BUCK 读电压读故障
    
    OUVDerateMainFunction(10); //电压获取 判断是否降额 降额占空比
    HighSide_Interface_Mainfunction(10); //高边诊断
}


/* 20ms任务 */
void ASW_Manager_MainFunction_20ms(void)
{
     // PowerSupplyMainFunction(20);
    // RcodInterface_Mainfunction(20);
    // HighSide_Interface_Mainfunction(20);
    // AdcDev_Interface_Mainfunction(20);
    // SystemService_MemoryJobMainFunction(20);
    PowerSupplyMainFunction(10);//电源采样和计算
    AdcDev_Interface_Mainfunction(20);
}


/* 50ms任务 */
void ASW_Manager_MainFunction_50ms(void)
{
    DCMotor_MainFunction(50);
}


/* 100ms任务 */
void ASW_Manager_MainFunction_100ms(void)
{
    //     NtcInterface_Mainfunction(100);
//     NtcDerateMainFunction(100);
//     BuckDerateMainFunction(100);
//     DerateRatioManagerFuncmain(100);
//     DID_Interface_Mainfunction(100);
 // SystemService_FlsTstMainFunction(1000);
    BuckDerateMainFunction(100);
    // Fan_MainFunction(100);
    // DidSignalManagerMainFunction(100);
}
/*测试代码*/
#include "Pwm_Cfg.h"
#include "Dio.h"
#include "Pwm.h"
#include "PowerSupply_Interface.h"

#include "AdcDev_Interface.h"
#include "HighSide_Interface.h"
#include "Dio_Cfg.h"
/* 初始化 */
uint8 LR_flag=0xff; //左右识别 临时放置 未做处理
void BD18397_Init_All(void);
Std_ReturnType ASW_Manager_Init(void)
{
    Std_ReturnType rtval = E_OK;
        // Std_ReturnType rtval = E_OK;
    // uint16_t BoostMaxVlotage = 0;
    // E_ChannelID chindex = 0;
    // rtval |= Interface_HighSideInit();
    // rtval |= Interface_DIDInit();
    // rtval |= Interface_ChannelInit();
    // rtval |= Interface_BuckInit();
    // rtval |= Interface_NtcRcodInit();
    // rtval |= DirectionInterface_Init();
    // rtval |= Interface_DtcInit();
    // rtval |= Interface_PulseGeneratorInit();
    // // rtval |= MatrixChipInterfaceModuleInit();
    // return rtval;
    
    Pwm_SetPeriodAndDuty(PwmConf_PwmChannel_H_L_Ctrl,5000,0x08000);//0x8000=100%=关闭远光；开5000 频率400HZ 占空比0
    Dio_WriteChannel(DioConf_DioChannel_TL_Ctrl, STD_LOW); //打开TL
    Dio_WriteChannel(DioConf_DioChannel_DRL_Ctrl, STD_LOW); //打开DRL
    Dio_WriteChannel(DioConf_DioChannel_HSD_EN1, STD_HIGH);//HSE_EN=1 打开风扇
    Dio_WriteChannel(DioConf_DioChannel_HSD_EN2, STD_LOW);//关电机
    Pwm_SetDutyCycle(PwmConf_PwmChannel_DC_Ctr, 0); //拉低电机控制引脚
    LR_flag=Dio_ReadChannel(DioConf_DioChannel_L_R_Identify_To_MCU); //左接地 读出1;右悬空 读出0
    CDD_Init();
   
    // ExLin_SetDTC(DTC_Highside1_Error,Short_Circuit);
    // ExLin_SetStatus(STATUS_BUCK_Temp,0x55);
    Pwm_SetDutyCycle(PwmConf_PwmChannel_PTE8_PWM_OUT, 0x3399);//0x4899U);//0x1999 约等于20%   //0x3399空载50V

 //配置表初始化
    BD18397_Init_All();//没有配置表 临时配置电流值
    // Fan_Init();
    // DCMotor_Init();
    // HSDManage_Init();
    return rtval;
}

