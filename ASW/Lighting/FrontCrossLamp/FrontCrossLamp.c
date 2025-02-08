#include "HcmPlatform.h"
#include "Lighting.h"
#include "Buck_Interface.h"
#include "Channel_Interface.h"
#include "FrontCrossLamp.h"
#include "Parameter_Interface.h"
#include "DTC_Interface.h"

void CROS_On(E_ChannelID id)
{
    uint8 pwm=100,pwmramp=100;
    uint16 cur=0;
    pwm=Interface_GetSignal_ChannelPwm(id);
    pwmramp=Lighting_SetPwmRamp(E_FrontCrossLamp);
    pwm=pwm*pwmramp/100;
    cur=Interface_GetSignal_ChannelCurrent(id);
    Interface_ChannelOpen(id,cur,pwm);
}

void CROS_Off(E_ChannelID id)
{
    Interface_ChannelClose(id);
}

//POS ON and OFF
uint16 CROS_RunMainFun(E_ChannelID id,uint16 *sts)
{
    uint16 lgmask=0;
    uint8 pwmc=0;
    uint8 SwitchOn=0;
    U_ChannelErrorState err;

    lgmask=GetChannelMaskByLightFunction(E_FrontCrossLamp);
    if(((lgmask>>id)&0x01)!=0) 
    {
        SwitchOn=Lighting_GetAct(E_FrontCrossLamp);
        if(SwitchOn==ACT_ON)
        {
            CROS_On(id);
            sts[id] |= E_CROS; //CH1 CH1_Tap is one channel   
        }
        else
        {
            CROS_Off(id);
            sts[id] &=(~E_CROS);   
        }    
        if((sts[id]&E_CROS)!=0) 
        {
            err=Interface_GetChannelState(id);
            if(err.Error==0) 
            {
                SetLgtStsFb_CROS(STS_ON);
            }
            else
            {
                SetLgtStsFb_CROS(STS_ERR);
            }
        }
        else 
        {
            SetLgtStsFb_CROS(STS_OFF);
        }   
    }
    return sts[id];
}



