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

typedef struct
{
    uint16 CH_NormalCur; /*Para table Normal Current*/
} S_ChannelCtrl_Config;
S_ChannelCtrl_Config gs_ChannelCtrlConfig[MAX_CHANNLE_NUM]=
{
    {.CH_NormalCur = 250, },
    {.CH_NormalCur = 250, },
    {.CH_NormalCur = 250, },
    {.CH_NormalCur = 250, },
    {.CH_NormalCur = 250, },
    {.CH_NormalCur = 250, },
};

void Light_Parameter_Init(void)
{
    uint8 ch=0;
    for(ch=0;ch<MAX_CHANNLE_NUM;ch++)
    {
        gs_ChannelCtrlConfig[ch].CH_NormalCur=Interface_GetChannelParamTableNormalCurrent(ch);
    }
}

void LB_HB_RUN(uint8 pwmper)
{
    uint8 chmask=0;
    chmask=GetChannelMaskByLightFunction(E_HighBeamSail);
    if(((chmask>>1)&0x01)!=0)
    {
        if(gs_lin_ctrl.Bits.HB_Ena==Light_ON)//远光
        {
            Pwm_CH1Tap_Enable();
            Interface_SetChannelCurrent((E_ChannelID)ChannelID1_Tap,gs_ChannelCtrlConfig[ChannelID1_Tap].CH_NormalCur*pwmper/100); //设置通道电流
            Interface_SetChannelSwitchState((E_ChannelID)ChannelID1_Tap, CHANNEL_STATE_ON); 
        }
        else 
        {
            Pwm_CH1Tap_Disable();
            if(gs_lin_ctrl.Bits.LB_Ena==Light_ON)//近光
            {
                Interface_SetChannelCurrent((E_ChannelID)ChannelID1, gs_ChannelCtrlConfig[ChannelID1].CH_NormalCur*pwmper/100); //设置通道电流
                Interface_SetChannelSwitchState((E_ChannelID)ChannelID1, CHANNEL_STATE_ON); 
            }
            else 
            {
                Interface_SetChannelCurrent((E_ChannelID)ChannelID1_Tap, 0); //设置通道电流
                Interface_SetChannelSwitchState((E_ChannelID)ChannelID1_Tap, CHANNEL_STATE_OFF); 
                Interface_SetChannelCurrent((E_ChannelID)ChannelID1, 0); //设置通道电流
                Interface_SetChannelSwitchState((E_ChannelID)ChannelID1, CHANNEL_STATE_OFF); 
            }
        }
    }
    else 
    {
        if(gs_lin_ctrl.Bits.LB_Ena==Light_ON)//近光开
        {
            Interface_SetChannelCurrent((E_ChannelID)ChannelID1, gs_ChannelCtrlConfig[ChannelID1].CH_NormalCur*pwmper/100); //设置通道电流
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
    uint8 chmask=0;
    chmask=GetChannelMaskByLightFunction(E_TurnIndicator);
//通道共用 通过IO口切换
    if(((chmask>>3)&0x01)!=0)
    {
        if(gs_lin_ctrl.Bits.Turn_Ena1==Light_ON)//转向开
        {
            Port_DrlPos_Disable();
            Port_TL_Enable(); 
            Interface_SetChannelCurrent((E_ChannelID)ChannelID2_Alt,gs_ChannelCtrlConfig[ChannelID2_Alt].CH_NormalCur*pwmper/100); //设置通道电流
            Interface_SetChannelSwitchState((E_ChannelID)ChannelID2_Alt, CHANNEL_STATE_ON); 
        }
        else 
        {
            Port_TL_Disable();
            if(gs_lin_ctrl.Bits.Drl_Ena==Light_ON)
            {
                Port_DrlPos_Enable();
                Interface_SetChannelCurrent((E_ChannelID)ChannelID2, gs_ChannelCtrlConfig[ChannelID2].CH_NormalCur*pwmper/100); //设置通道电流
                Interface_SetChannelSwitchState((E_ChannelID)ChannelID2, CHANNEL_STATE_ON); 
            }
            else if(gs_lin_ctrl.Bits.Pos_Ena==Light_ON)
            {
                Port_DrlPos_Enable();
                Interface_SetChannelCurrent((E_ChannelID)ChannelID2,gs_ChannelCtrlConfig[ChannelID2].CH_NormalCur*pwmper/100); //设置通道电流
                Interface_SetChannelSwitchState((E_ChannelID)ChannelID2, CHANNEL_STATE_ON); 
            }
            else 
            {
                Port_DrlPos_Disable();
                Interface_SetChannelCurrent((E_ChannelID)ChannelID2,0); 
                Interface_SetChannelSwitchState((E_ChannelID)ChannelID2, CHANNEL_STATE_OFF); 
                Interface_SetChannelCurrent((E_ChannelID)ChannelID2_Alt,0); 
                Interface_SetChannelSwitchState((E_ChannelID)ChannelID2_Alt, CHANNEL_STATE_OFF); 
            }
        }
    }
    else 
    {
        if(gs_lin_ctrl.Bits.Drl_Ena==Light_ON)
        {
            Port_DrlPos_Enable();
            Interface_SetChannelCurrent((E_ChannelID)ChannelID2, gs_ChannelCtrlConfig[ChannelID2].CH_NormalCur*pwmper/100); //设置通道电流
            Interface_SetChannelSwitchState((E_ChannelID)ChannelID2, CHANNEL_STATE_ON); 
        }
        else if(gs_lin_ctrl.Bits.Pos_Ena==Light_ON)
        {
            Port_DrlPos_Enable();
            Interface_SetChannelCurrent((E_ChannelID)ChannelID2,gs_ChannelCtrlConfig[ChannelID2].CH_NormalCur*pwmper/100); //设置通道电流
            Interface_SetChannelSwitchState((E_ChannelID)ChannelID2, CHANNEL_STATE_ON); 
        }
        else 
        {
            Port_DrlPos_Disable();
            Interface_SetChannelCurrent((E_ChannelID)ChannelID2,0); 
            Interface_SetChannelSwitchState((E_ChannelID)ChannelID2, CHANNEL_STATE_OFF); 
        }
    }
}


//非共用通道 CH3 CH4
void Non_SharedChannel(uint8 pwmper)
{
    uint8 id=0,chmask=0;
//确定CH3 CH4接的灯
    for(id=ChannelID3;id<CHANNEL_NUM;id++)
    {
        chmask=GetChannelMaskByLightFunction(E_HighBeamSail);
        if(((chmask>>id)&0x01)!=0) //CH3/CH4接入远光
        {
            if(gs_lin_ctrl.Bits.HB_Ena==Light_ON)
            {
                Interface_SetChannelCurrent(id,gs_ChannelCtrlConfig[id].CH_NormalCur*pwmper/100); //设置通道电流
                Interface_SetChannelSwitchState(id, CHANNEL_STATE_ON); 
            }
            else
            {
                Interface_SetChannelCurrent(id, 0);
                Interface_SetChannelSwitchState(id, CHANNEL_STATE_OFF); 
            }
        }
        chmask=GetChannelMaskByLightFunction(E_DaytimeRunningLight);
        if(((chmask>>id)&0x01)!=0) //CH3/CH4接入日行
        {
            if(gs_lin_ctrl.Bits.Drl_Ena==Light_ON)
            {
                Interface_SetChannelCurrent(id,gs_ChannelCtrlConfig[id].CH_NormalCur*pwmper/100); //设置通道电流
                Interface_SetChannelSwitchState(id, CHANNEL_STATE_ON); 
            }
            else
            {
                Interface_SetChannelCurrent(id, 0); //设置通道电流
                Interface_SetChannelSwitchState(id, CHANNEL_STATE_OFF); 
            }
        }
        chmask=GetChannelMaskByLightFunction(E_PositionLight);
        if(((chmask>>id)&0x01)!=0) //CH3/CH4接入位置
        {
            if(gs_lin_ctrl.Bits.Pos_Ena==Light_ON)
            {
                Interface_SetChannelCurrent(id,gs_ChannelCtrlConfig[id].CH_NormalCur*pwmper/100); //设置通道电流
                Interface_SetChannelSwitchState(id, CHANNEL_STATE_ON); 
            }
            else
            {
                Interface_SetChannelCurrent(id, 0); 
                Interface_SetChannelSwitchState(id, CHANNEL_STATE_OFF); 
            }
        }
        chmask=GetChannelMaskByLightFunction(E_TurnIndicator);
        if(((chmask>>id)&0x01)!=0) //CH3/CH4接入转向
        {
            if(gs_lin_ctrl.Bits.Turn_Ena1==Light_ON)
            {
                Interface_SetChannelCurrent(id,gs_ChannelCtrlConfig[id].CH_NormalCur*pwmper/100); //设置通道电流
                Interface_SetChannelSwitchState(id, CHANNEL_STATE_ON); 
            }
            else
            {
                Interface_SetChannelCurrent(id, 0); 
                Interface_SetChannelSwitchState(id, CHANNEL_STATE_OFF); 
            }
        }
        chmask=GetChannelMaskByLightFunction(E_FrontCrossLamp);
        if(((chmask>>id)&0x01)!=0) //CH3/CH4接入贯穿灯
        {
            if(gs_lin_ctrl.Bits.CROS_Ena==Light_ON)
            {
                Interface_SetChannelCurrent(id,gs_ChannelCtrlConfig[id].CH_NormalCur*pwmper/100); //设置通道电流
                Interface_SetChannelSwitchState(id, CHANNEL_STATE_ON); 
            }
            else
            {
                Interface_SetChannelCurrent(id, 0); 
                Interface_SetChannelSwitchState(id, CHANNEL_STATE_OFF); 
            }
        }
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
        Port_FAN_Enable(); 
    }
    else 
    {
        Port_FAN_Disable();
        Boost_Disable();
    }
//2.降额处理，获取最新的占空比
    pwmper=Interface_GetDerateRatioOfOUV();  
    test[0]=pwmper;//测试
//3.1 点灯功能  远近光 共用通道CH1 CH1'
    LB_HB_RUN(pwmper);
//3.2 点灯功能  转向 日行 位置 共用通道 CH2 CH2'
    PosDrlTurn_Run(pwmper);
//3.3 点灯功能 非共用通道
    Non_SharedChannel(pwmper);
}

/*灯光管理功能*/
void Light_Manager(uint8 timebase)
{  
    Lighting_BasicFun(); //基础灯光执行点亮
}




