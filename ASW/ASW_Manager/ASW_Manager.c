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
#include "ASW_Manager.h"
#include "DidSignalManager.h"
#include "FrontCrossLamp.h"
#include "Fan.h"
#include <stdlib.h>
#include <math.h>
#include "LightingASW.h"
#include "DCMotor.h"
#include "Cdd_Driver_Manager.h"
#include "BuckDerate_Interface.h"
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

}

/* 10ms任务 */
//测试代码
#include "Pwm_Cfg.h"
#include "Dio.h"
#include "Pwm.h"
#include "Wdg.h"
#include "PowerSupply_Interface.h"
#include "OUVDerate_Interface.h"
#include "AdcDev_Interface.h"
#include "HighSide_Interface.h"
#include "Dio_Cfg.h"

uint8 LR_flag=0xff; //左右识别

uint8 pwmread=100;
uint16 Motorcnt=0; //电机 计数器延时
uint16_t HSDCur[10]={0};
uint16 pwmdata=0x8000;
uint8 temp1111[10]={0};
uint16 volbuf[6]={0};
sint16 tempbuf[2]={0};
extern uint8 *ExLin_ControlBuffPtr;

Std_ReturnType BD18397MainFun(uint8 id);
Std_ReturnType CddDriver_AdcDrvInit(void);
Std_ReturnType Interface_GetHighSideChannelCurrent(E_HSChannel HSChannel, uint16_t *current);
Std_ReturnType HighSide_Interface_Mainfunction(uint8_t timebase);
Std_ReturnType AswInterfaceManagerInit(void);

void CddDriver_AdcMainfunction(void);
void DCMotor_MainFunction(uint8 timebase);
void CddDriver_AdcMainfunction(void);
void PowerSupplyMainFunction(uint8_t tmiebase);
void LIN_Light(uint8 *rxbuf);
void Light_Manager(uint8 pwmper);

void ASW_Manager_MainFunction_10ms(void)
{
   //LIN 打开灯
    for (uint8 i = 0; i < 8;i++)
    {
        temp1111[i] = ExLin_ControlBuffPtr[i];
    }
    LIN_Light(&temp1111);
    Light_Manager(pwmread);
//LIN 读温度

    // ExLin_SetDTC(DTC_Highside1_Error,Over_Current);
    // ExLin_SetStatus(STATUS_BUCK_Temp,tempbuf[0]);
    // ExLin_SetStatus(STATUS_BUCK_Voltage,volbuf[0]);//传递BUCK1 CH1电压
    Channel_Interface_MainFunction(10); //BUCK诊断ID0
    Wdg_Service();
//电机
//     Motorcnt++;
//     if(Motorcnt>=20)
//     {
//         Motorcnt=0;
//         DCMotor_MainFunction(10);
// //灯开关测18398
//         // test_vol();
//     }      
//远光MOS调光
    // pwmdata=pwmdata-10;
    // if(pwmdata<=20) pwmdata=0x8000;
    // Pwm_SetDutyCycle(PwmConf_PwmChannel_H_L_Ctrl, pwmdata);//0x8000U);//100%=关闭远光
//ADC采样
    CddDriver_AdcMainfunction();
    BuckInterfaceMainFuntion(10);//BUCK 读电压读故障
    
//电源采样和计算
    PowerSupplyMainFunction(10);
// 降额
    OUVDerateMainFunction(10); //电压获取 判断是否降额 降额占空比
    pwmread=Interface_GetDerateRatioOfOUV(); //获取点灯占空比
    // BD18397_MainFunction(pwmread);
//高边获取电流
    Interface_GetHighSideChannelCurrent(0, HSDCur);//E_HSChannel_HS0
//高边诊断
    HighSide_Interface_Mainfunction(10);
    // Fan_Fan1CtrLineDtcErrDetect_10ms();
    // HSDManage_MainFunction(10);
}


/* 20ms任务 */
void ASW_Manager_MainFunction_20ms(void)
{

}


/* 50ms任务 */
void ASW_Manager_MainFunction_50ms(void)
{
    // DCMotor_MainFunction(50);
}


/* 100ms任务 */
void ASW_Manager_MainFunction_100ms(void)
{
    BuckDerateMainFunction(100);
    // Fan_MainFunction(100);
    // DidSignalManagerMainFunction(100);
}
/*测试代码*/

/* 初始化 */
void BD18397_Init_All(void);
Std_ReturnType ASW_Manager_Init(void)
{
    Std_ReturnType rtval = E_OK;
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


