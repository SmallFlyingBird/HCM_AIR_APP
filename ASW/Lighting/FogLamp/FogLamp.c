#include "HcmPlatform.h"
#include "Lighting.h"
#include "Buck_Interface.h"
#include "Channel_Interface.h"
#include "FogLamp.h"
#include "Parameter_Interface.h"
#include "DTC_Interface.h"

void FogLamp_On(E_ChannelID id)
{
    uint8 pwm=100,pwmramp=100;
    uint16 cur=0;
    pwm=Interface_GetSignal_ChannelPwm(id);
    pwmramp=Lighting_SetPwmRamp(E_FogLamp);
    pwm=pwm*pwmramp/100;
    cur=Interface_GetSignal_ChannelCurrent(id);
    Interface_ChannelOpen(id,cur,pwm);
}

void FogLamp_Off(E_ChannelID id)
{
    Interface_ChannelClose(id);
}

uint16 FogLamp_RunMainFun(E_ChannelID id,uint16 *sts)
{
    uint16 lgmask=0;
    uint8 SwitchOn=0;
    U_ChannelErrorState err;

    lgmask=GetChannelMaskByLightFunction(E_FogLamp);
    if(((lgmask>>id)&0x01)!=0) 
    {
        SwitchOn=Lighting_GetAct(E_FogLamp);
        if(SwitchOn==ACT_ON)
        {
            FogLamp_On(id);
            sts[id] |= E_FOG; //CH1 CH1_Tap is one channel   
        }
        else
        {
            FogLamp_Off(id);
            sts[id] &=(~E_FOG);   
        }    
        if((sts[id]&E_FOG)!=0) 
        {
            err=Interface_GetChannelState(id);
            if(err.Error==0) 
            {
                SetLgtStsFb_Fog(STS_ON);
            }
            else
            {
                SetLgtStsFb_Fog(STS_ERR);
            }
        }
        else 
        {
            SetLgtStsFb_Fog(STS_OFF);
        }   
    }
    return sts[id];
}



