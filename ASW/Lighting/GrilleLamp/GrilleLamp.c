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

uint16 GrilleLamp_RunMainFun(E_ChannelID id,uint16 *sts)
{
    uint16 lgmask=0;
    uint8 SwitchOn=0;
    U_ChannelErrorState err;

    lgmask=GetChannelMaskByLightFunction(E_GrilleLamp);
    if(((lgmask>>id)&0x01)!=0) 
    {
        SwitchOn=Lighting_GetAct(E_GrilleLamp);
        if(SwitchOn==ACT_ON)
        {
            GrilleLamp_On(id);
            sts[id] |= E_GRIL; //CH1 CH1_Tap is one channel   
        }
        else
        {
            GrilleLamp_Off(id);
            sts[id] &=(~E_GRIL);   
        }    
        // if((sts[id]&E_GRIL)!=0) 
        // {
        //     err=Interface_GetChannelState(id);
        //     if(err.Error==1) 
        //     {
        //         SetLgtStsFb_CORN(STS_ERR);
        //     }
        //     else
        //     {
        //         SetLgtStsFb_CORN(STS_ON);
        //     }
        // }
        // else 
        // {
        //     SetLgtStsFb_CORN(STS_OFF);
        // }   
    }
    return sts[id];
}



