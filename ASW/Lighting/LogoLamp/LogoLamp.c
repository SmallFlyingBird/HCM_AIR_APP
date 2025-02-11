#include "LogoLamp.h"

void LogoLamp_On(E_ChannelID id)
{
    uint8 pwm=100,pwmramp=100;
    uint16 cur=0;
    pwm=Interface_GetSignal_ChannelPwm(id);
    pwmramp=Lighting_SetPwmRamp(E_LogoLamp);
    pwm=pwm*pwmramp/100;
    cur=Interface_GetSignal_ChannelCurrent(id);
    Interface_ChannelOpen(id,cur,pwm);
}

void LogoLamp_Off(E_ChannelID id)
{
    Interface_ChannelClose(id);
}

uint16 LogoLamp_RunMainFun(E_ChannelID id,uint16 *sts)
{
    uint16 lgmask=0;
    uint8 SwitchOn=0;
    U_ChannelErrorState err;

    lgmask=GetChannelMaskByLightFunction(E_LogoLamp);
    if(((lgmask>>id)&0x01)!=0) 
    {
        SwitchOn=Lighting_GetAct(E_LogoLamp);
        if(SwitchOn==ACT_ON)
        {
            LogoLamp_On(id);
            sts[id] |= E_LOGO; //CH1 CH1_Tap is one channel   
        }
        else
        {
            LogoLamp_Off(id);
            sts[id] &=(~E_LOGO);   
        }    
        // if((sts[id]&E_LOGO)!=0) 
        // {
        //     err=Interface_GetChannelState(id);
        //     if(err.Error==1) 
        //     {
        //         SetLgtStsFb_Fog(STS_ERR);
        //     }
        //     else
        //     {
        //         SetLgtStsFb_Fog(STS_ON);
        //     }
        // }
        // else 
        // {
        //     SetLgtStsFb_Fog(STS_OFF);
        // }   
    }
    return sts[id];
}



