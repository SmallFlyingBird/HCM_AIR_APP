
#include "CorneringLamp.h"
void CornLamp_On(E_ChannelID id)
{
    uint8 pwm=100,pwmramp=100;
    uint16 cur=0;
    pwm=Interface_GetSignal_ChannelPwm(id);
    pwmramp=Lighting_SetPwmRamp(E_CorneringLight);
    pwm=pwm*pwmramp/100;
    cur=Interface_GetSignal_ChannelCurrent(id);
    Interface_ChannelOpen(id,cur,pwm);
}

void CornLamp_Off(E_ChannelID id)
{
    Interface_ChannelClose(id);
}

void CornLamp_RunMainFun(uint16 *sts)
{
    uint16 lgmask=0;
    uint8 SwitchOn=0;
    U_ChannelErrorState err;

    E_ChannelID id=ChannelID1;
    lgmask=GetChannelMaskByLightFunction(E_CorneringLight);
    for(id=ChannelID1;id<CHANNEL_NUM;id++)
    {
        if(((lgmask>>id)&0x01)!=0) 
        {
            SwitchOn=Lighting_GetAct(E_CorneringLight);
            if(SwitchOn==ACT_ON)
            {
                CornLamp_On(id);
                sts[id] |= E_CORN; //CH1 CH1_Tap is one channel   
            }
            else
            {
                CornLamp_Off(id);
                sts[id] &=(~E_CORN);   
            }    
            if((sts[id]&E_CORN)!=0) 
            {
                err=Interface_GetChannelState(id);
                if(err.Error==0) 
                {
                    SetLgtStsFb_CORN(STS_ON);
                }
                else
                {
                    SetLgtStsFb_CORN(STS_ERR);
                }
            }
            else 
            {
                SetLgtStsFb_CORN(STS_OFF);
            }   
        }
    }
}



