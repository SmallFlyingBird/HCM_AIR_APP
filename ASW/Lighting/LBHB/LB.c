
#include "HcmPlatform.h"
#include "LB.h"
#include "Channel_Interface.h"
#include "Parameter_Interface.h"
#include "BD18397_Interface.h"
#include "lighting.h"

static S_LowBeamRunInfo gs_LowBeamRunInfo;

/* 近光启动初始化 */
void LowBeam_ConfigInit(void)
{

}

void LB_Run(E_ChannelID id,uint8 ledstatus)
{
    // uint8 lgmask=0,chmask=0;
    // uint16 cur=0;
    // lgmask=GetChannelMaskByLightFunction(E_LowBeamKink);
    // if(((lgmask>>id)&0x01)!=0) 
    // {
    //     if(lgtctl.st_LgtAct.ActLB==ACT_ON)
    //     {
    //         pwmper=Interface_GetChannelDerateRatio(id);
    //         cur=gs_ChannelCtrlConfig[id].CH_NormalCur*pwmper*gs_ramp_pwm.pwm_Ramp_LB/10000;
    //         if(id==ChannelID1_Tap)
    //         {
    //             Pwm_CH1Tap_Enable();
    //             ChannelEna[ChannelID1_Tap]=1; //CH1 CH1_Tap会相互影响
    //         }
    //         else if(id==ChannelID1) 
    //         {
    //             ChannelEna[ChannelID1]=1; //CH1 CH1_Tap会相互影响
    //         }
    //         Interface_SetChannelCurrent(id,cur); //设置通道电流
    //         Interface_SetChannelSwitchState(id, CHANNEL_STATE_ON); 
    //     }
    //     else
    //     {
    //         if(id==ChannelID1_Tap)
    //         {
    //             Pwm_CH1Tap_Disable();
    //             ChannelEna[ChannelID1_Tap]=0; //CH1 CH1_Tap会相互影响
    //         }
    //         else if(id==ChannelID1) 
    //         {
    //             ChannelEna[ChannelID1]=0; //CH1 CH1_Tap会相互影响
    //         }
    //         else
    //         {
    //             Interface_SetChannelCurrent(id, 0);
    //             Interface_SetChannelSwitchState(id, CHANNEL_STATE_OFF); 
    //         }
    //     }
    // }
}