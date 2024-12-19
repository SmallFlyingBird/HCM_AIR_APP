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

typedef struct
{
    uint8 perpwm[6];
}S_LightingCtrl;
S_LightingCtrl gs_lighting_ctrl;

uint16 Cur_ChannelBuf[6]={50,50,200,50,50,50};

void LB_HB_RUN(uint8 pwmper)
{
    if(gs_lin_ctrl.Bits.HB_Ena==Light_ON)//远光
    {
        Pwm_CH1Tap_Enable();
        Interface_SetChannelCurrent((E_ChannelID)ChannelID1_Tap, Cur_ChannelBuf[3]*pwmper/100); //设置通道电流
        Interface_SetChannelSwitchState((E_ChannelID)ChannelID1_Tap, CHANNEL_STATE_ON); 
    }
    else 
    {
        Pwm_CH1Tap_Disable();
        if(gs_lin_ctrl.Bits.LB_Ena==Light_ON)//近光
        {
            Interface_SetChannelCurrent((E_ChannelID)ChannelID1, Cur_ChannelBuf[3]*pwmper/100); //设置通道电流
            Interface_SetChannelSwitchState((E_ChannelID)ChannelID1, CHANNEL_STATE_ON); 
        }
        else 
        {
            Interface_SetChannelCurrent((E_ChannelID)ChannelID1, 0); //设置通道电流
            Interface_SetChannelSwitchState((E_ChannelID)ChannelID1, CHANNEL_STATE_OFF); 
        }
    }
}

void PosDrlTurn_Run(uint8 pwmper)
{
//1.通道共用 通过IO口切换
    if(gs_lin_ctrl.Bits.Turn_Ena1==Light_ON)//转向开
    {
        Port_DrlPos_Disable();
        Port_TL_Enable(); 
        Interface_SetChannelCurrent((E_ChannelID)ChannelID2_Alt, Cur_ChannelBuf[3]*pwmper/100); //设置通道电流
        Interface_SetChannelSwitchState((E_ChannelID)ChannelID2_Alt, CHANNEL_STATE_ON); 
    }
    else 
    {
        Port_TL_Disable();
        if(gs_lin_ctrl.Bits.Drl_Ena==Light_ON)
        {
            Port_DrlPos_Enable();
            Interface_SetChannelCurrent((E_ChannelID)ChannelID2, Cur_ChannelBuf[3]*pwmper/100); //设置通道电流
            Interface_SetChannelSwitchState((E_ChannelID)ChannelID2, CHANNEL_STATE_ON); 
        }
        else if(gs_lin_ctrl.Bits.Pos_Ena==Light_ON)
        {
            Port_DrlPos_Enable();
            Interface_SetChannelCurrent((E_ChannelID)ChannelID2, Cur_ChannelBuf[3]*pwmper/100); //设置通道电流
            Interface_SetChannelSwitchState((E_ChannelID)ChannelID2, CHANNEL_STATE_ON); 
        }
        else 
        {
            Port_DrlPos_Disable();
            Interface_SetChannelCurrent((E_ChannelID)ChannelID2,0); //设置通道电流
            Interface_SetChannelSwitchState((E_ChannelID)ChannelID2, CHANNEL_STATE_OFF); 
        }
    }

//2.非共用通道
    if(gs_lin_ctrl.Bits.Pos_Ena==Light_ON)//位置
    {
        Interface_SetChannelCurrent((E_ChannelID)ChannelID3, Cur_ChannelBuf[3]*pwmper/100); //设置通道电流
        Interface_SetChannelSwitchState((E_ChannelID)ChannelID3, CHANNEL_STATE_ON); 
    }
    else 
    {
        Interface_SetChannelCurrent((E_ChannelID)ChannelID3, 0); //设置通道电流
        Interface_SetChannelSwitchState((E_ChannelID)ChannelID3, CHANNEL_STATE_OFF); 
    }
}

void Cross_Run(uint8 pwmper)
{
    if(gs_lin_ctrl.Bits.CROS_Ena==Light_ON)
    {
        Interface_SetChannelCurrent((E_ChannelID)ChannelID4, Cur_ChannelBuf[3]*pwmper/100); //设置通道电流
        Interface_SetChannelSwitchState((E_ChannelID)ChannelID4, CHANNEL_STATE_ON); 
    }
    else
    {
        Interface_SetChannelCurrent((E_ChannelID)ChannelID4, 0); //设置通道电流
        Interface_SetChannelSwitchState((E_ChannelID)ChannelID4, CHANNEL_STATE_OFF); 
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
//1.降额处理，获取最新的占空比
    pwmper=Interface_GetDerateRatioOfOUV();  
    test[0]=pwmper;//测试
//2.1 点灯功能  远近光
    LB_HB_RUN(pwmper);
//2.2 点灯功能  转向 日行 位置
    PosDrlTurn_Run(pwmper);
//2.3 点灯功能 贯穿灯
    Cross_Run(pwmper);
}

/*灯光管理功能*/
void Light_Manager(uint8 timebase)
{  
    Lighting_BasicFun(); //基础灯光执行点亮
}



   


















