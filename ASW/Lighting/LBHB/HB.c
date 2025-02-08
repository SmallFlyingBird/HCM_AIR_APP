#include "HcmPlatform.h"
#include "Lighting.h"
#include "HB.h"
#include "Buck_Interface.h"
#include "Channel_Interface.h"
#include "Pwm_Service.h"
#include "Parameter_Interface.h"
#include "DTC_Interface.h"

void HB_On(E_ChannelID id)
{
    uint8 pwm=100,pwmramp=100;
    uint16 cur=0; 
    if(id==ChannelID1_Tap)
    {
        Pwm_CH1Tap_Enable();
    }
    pwm=Interface_GetSignal_ChannelPwm(id);
    pwmramp=Lighting_SetPwmRamp(E_HighBeamSpot);
    pwm=pwm*pwmramp/100;
    cur=Interface_GetSignal_ChannelCurrent(id);
    Interface_ChannelOpen(id,cur,pwm); 
}

void HB_Off(E_ChannelID id)
{
    if(id==ChannelID1_Tap)
    {
        Pwm_CH1Tap_Disable();       
    }
    else
    {
        Interface_ChannelClose(id);
    }
}

//HB ON and OFF
uint16 HB_RunMainFun(E_ChannelID id,uint16 *sts)
{
    uint16 lgmask=0;
    U_ChannelErrorState err;
    uint8 SwitchOn;
    lgmask=GetChannelMaskByLightFunction(E_HighBeamSpot);
    if(((lgmask>>id)&0x01)!=0) 
    {
        SwitchOn=Lighting_GetAct(E_HighBeamSpot);
        if(SwitchOn==ACT_ON)
        {
            sts[id] |= E_HB; //CH1 CH1_Tap is one channel               
            HB_On(id);
        }
        else
        {             
            sts[id] &=(~E_HB); 
            HB_Off(id);
        }
        if((sts[id]&E_HB)!=0) 
        {
            err=Interface_GetChannelState(id);
            if(err.Error==1) 
            {
                SetLgtStsFb_HB(STS_ERR);
            }
            else
            {
                SetLgtStsFb_HB(STS_ON);
            }
        }
        else 
        {
            SetLgtStsFb_HB(STS_OFF);
        }
    }
    return sts[id];
}

