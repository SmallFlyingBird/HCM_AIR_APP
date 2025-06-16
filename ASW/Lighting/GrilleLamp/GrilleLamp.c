#include "GrilleLamp.h"

void GrilleLamp_On(E_ChannelID id)
{
    uint8 pwm=100,pwmramp=100;
    uint16 cur=0;
    pwm=Interface_GetSignal_ChannelPwm(id);
    pwmramp=Lighting_SetPwmRamp(E_GrilleLamp);
    pwm=pwm*pwmramp/100;
    cur=Interface_GetSignal_ChannelCurrent(id);
    Interface_ChannelOpen(id,cur,pwm);
}

void GrilleLamp_Off(E_ChannelID id)
{
    Interface_ChannelClose(id);
}

void GrilleLamp_RunMainFun(void)
{
    uint16 lgmask=0;
    uint8 SwitchOn=0;
    U_ChannelErrorState err;

    E_ChannelID id=ChannelID1;
    lgmask=GetChannelMaskByLightFunction(E_GrilleLamp);
    for(id=ChannelID1;id<CHANNEL_NUM;id++)
    {
        if(((lgmask>>id)&0x01)!=0) 
        {
            SwitchOn=Lighting_GetAct(E_GrilleLamp);
            if(SwitchOn==ACT_ON)
            {
                GrilleLamp_On(id);
            }
            else
            {
                GrilleLamp_Off(id);
            }     
        }
    }
}



