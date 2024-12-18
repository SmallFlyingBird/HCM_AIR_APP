#include "HcmPlatform.h"
#include "Lighting.h"
#include "LinManager.h"
#include "Ex_SleepWakeup.h"
#include "Dio_Service.h"
#include "Pwm_Service.h"
#include "Parameter_Interface.h"
#include "OUVDerate_Interface.h"
#include "Channel_Interface.h"

uint16 test[20]={0}; //测试用
typedef enum
{
    Light_ON  = 1,
    Light_OFF = 0,
}LightSwitchState;

extern S_Lin_LControl gs_lin_ctrl;//lin接收到的开关状态
S_Lin_LControl gs_run_ctrl;//灯光需要执行的开关状态

typedef struct
{
    uint8 perpwm[6];
}S_LightingCtrl;
S_LightingCtrl gs_lighting_ctrl;

uint16 Cur_ChannelBuf[6]={50,50,200,50,50,50};

/*配置表中6个通道的开关功能*/
void Lighting_SwitchFun(E_ChannelID channel,LightSwitchState sw,uint16 cur)
{
    switch(channel)
    {
    case ChannelID1:
        if(sw==Light_ON)
        {
            Interface_SetChannelCurrent((E_ChannelID)ChannelID1,cur); //设置通道电流
            Interface_SetChannelSwitchState((E_ChannelID)ChannelID1, CHANNEL_STATE_ON);
        }
        else 
        {
            Interface_SetChannelCurrent((E_ChannelID)ChannelID1, 0); //设置通道电流
            Interface_SetChannelSwitchState((E_ChannelID)ChannelID1, CHANNEL_STATE_OFF); 
        }
    break;
    case ChannelID1_Tap:
        if(sw==Light_ON)
        {
            Interface_SetChannelCurrent((E_ChannelID)ChannelID1_Tap, cur); //设置通道电流
            Interface_SetChannelSwitchState((E_ChannelID)ChannelID1_Tap, CHANNEL_STATE_ON); 
            Pwm_CH1Tap_Enable();
        }
        else 
        {
            Pwm_CH1Tap_Disable();
        }
    break;
    case ChannelID2:
        if(sw==Light_ON)
        {
            Interface_SetChannelCurrent((E_ChannelID)ChannelID2, cur); //设置通道电流
            Interface_SetChannelSwitchState((E_ChannelID)ChannelID2, CHANNEL_STATE_ON); 
        }
        else 
        {
            Interface_SetChannelCurrent((E_ChannelID)ChannelID2, 0); //设置通道电流
            Interface_SetChannelSwitchState((E_ChannelID)ChannelID2, CHANNEL_STATE_OFF); 
        }
    break;
    case ChannelID2_Alt:
        if(sw==Light_ON)
        {
            Interface_SetChannelCurrent((E_ChannelID)ChannelID2_Alt, cur); //设置通道电流
            Interface_SetChannelSwitchState((E_ChannelID)ChannelID2_Alt, CHANNEL_STATE_ON); 
        }
        else 
        {
            Interface_SetChannelCurrent((E_ChannelID)ChannelID2_Alt, 0); //设置通道电流
            Interface_SetChannelSwitchState((E_ChannelID)ChannelID2_Alt, CHANNEL_STATE_OFF); 
        }
    break;
    case ChannelID3:
        if(sw==Light_ON)
        {
            Interface_SetChannelCurrent((E_ChannelID)ChannelID3, cur); //设置通道电流
            Interface_SetChannelSwitchState((E_ChannelID)ChannelID3, CHANNEL_STATE_ON); 
        }
        else 
        {
            Interface_SetChannelCurrent((E_ChannelID)ChannelID3, 0); //设置通道电流
            Interface_SetChannelSwitchState((E_ChannelID)ChannelID3, CHANNEL_STATE_OFF); 
        }
    break;
    case ChannelID4:
        if(sw==Light_ON)
        {
            Interface_SetChannelCurrent((E_ChannelID)ChannelID4,cur); //设置通道电流
            Interface_SetChannelSwitchState((E_ChannelID)ChannelID4, CHANNEL_STATE_ON); 
        }
        else 
        {
            Interface_SetChannelCurrent((E_ChannelID)ChannelID4, 0); //设置通道电流
            Interface_SetChannelSwitchState((E_ChannelID)ChannelID4, CHANNEL_STATE_OFF); 
        }
    break;
    }
}



void Lighting_BasicFun(void)
{
    uint8 pwmper=100;
//1.如有点灯信号，打开BOOST（不能一直打开，考虑热量）,不进入休眠
    if(gs_lin_ctrl.Light_Status!=0)
    {
        Boost_Enable();
        ResetAWakeTime();
    }
    else Boost_Disable();
//2.对接收信号进行优先级处理

    gs_run_ctrl.Bits.CROS_Ena=gs_lin_ctrl.Bits.CROS_Ena;//贯穿灯

    if(gs_lin_ctrl.Bits.Turn_Ena1==Light_ON)//转向
    {
        gs_run_ctrl.Bits.Drl_Ena=Light_OFF;
        gs_run_ctrl.Bits.Pos_Ena=Light_OFF;
        gs_run_ctrl.Bits.Turn_Ena1=Light_ON;
    }
    else//转向 打开关闭
    {
        gs_run_ctrl.Bits.Turn_Ena1=Light_OFF;
        gs_run_ctrl.Bits.Pos_Ena=gs_lin_ctrl.Bits.Pos_Ena;
        gs_run_ctrl.Bits.Drl_Ena=gs_lin_ctrl.Bits.Drl_Ena;
    }

//1.降额处理，获取最新的占空比
    pwmper=Interface_GetDerateRatioOfOUV();  
    test[0]=pwmper;//测试
//2.点灯功能
    if(gs_lin_ctrl.Bits.HB_Ena==Light_ON)
    {
        gs_run_ctrl.Bits.HB_Ena=Light_ON; 
        gs_run_ctrl.Bits.LB_Ena=Light_ON;
    }
    else
    {
        gs_run_ctrl.Bits.HB_Ena=Light_OFF;
        if(gs_lin_ctrl.Bits.LB_Ena==Light_ON)
        {
            gs_run_ctrl.Bits.LB_Ena=Light_ON;
        }
        else gs_run_ctrl.Bits.LB_Ena=Light_OFF;
    }


    if(gs_lin_ctrl.Bits.HB_Ena==Light_ON)//远光
    {
        Lighting_SwitchFun(ChannelID1_Tap,Light_ON,Cur_ChannelBuf[0]*pwmper/100);
    }
    else 
    {
        if(gs_lin_ctrl.Bits.LB_Ena==Light_ON)//近光
        {
            Lighting_SwitchFun(ChannelID1,Light_ON,Cur_ChannelBuf[1]*pwmper/100);
        }
        else Lighting_SwitchFun(ChannelID1_Tap,Light_OFF,0);
    }

    if(gs_run_ctrl.Bits.Turn_Ena1==Light_ON)//转向
    {
        Port_TL_Enable(); 
        Lighting_SwitchFun(ChannelID2_Alt,Light_ON,Cur_ChannelBuf[3]*pwmper/100);
    }
    else 
    {
        Port_TL_Disable();
        Lighting_SwitchFun(ChannelID2_Alt,Light_OFF,0);
    }
    if(gs_run_ctrl.Bits.Drl_Ena==Light_ON)//日行
    {
        Port_DrlPos_Enable(); 
        Lighting_SwitchFun(ChannelID2,Light_ON,Cur_ChannelBuf[2]*pwmper/100);
    }
    if(gs_run_ctrl.Bits.Pos_Ena==Light_ON)//位置
    {
        Port_DrlPos_Enable(); 
//3.共发光面
        if(gs_run_ctrl.Bits.Drl_Ena!=Light_ON) Lighting_SwitchFun(ChannelID2,Light_ON,Cur_ChannelBuf[4]*pwmper/100);//日行不开 打开共用发光面
        Lighting_SwitchFun(ChannelID3,Light_ON,Cur_ChannelBuf[4]*pwmper/100);
    }
    if ((gs_run_ctrl.Bits.Drl_Ena==Light_OFF)&&(gs_run_ctrl.Bits.Pos_Ena==Light_OFF)) //日行位置都关闭时，把通道输出关闭
    {
        Port_DrlPos_Disable(); 
        Lighting_SwitchFun(ChannelID3,Light_ON,0);
        if(gs_run_ctrl.Bits.Turn_Ena1==Light_OFF) 
        {
            Lighting_SwitchFun(ChannelID2,Light_OFF,0);
        }
    }
}

/*灯光管理功能*/
void Light_Manager(uint8 timebase)
{  
    Lighting_BasicFun(); //基础灯光执行点亮
}



   


















