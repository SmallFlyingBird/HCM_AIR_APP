#include "HcmPlatform.h"
#include "Lighting.h"
#include "Buck_Interface.h"
#include "Channel_Interface.h"
#include "FrontCrossLamp.h"
#include "Parameter_Interface.h"


void CROS_On(E_ChannelID id,uint16 cur)
{
    uint8 pwm=100;
    pwm=Interface_GetSignal_ChannelPwm(id);
    Interface_ChannelOpen(id,cur,pwm);
}

void CROS_Off(E_ChannelID id)
{
    Interface_ChannelClose(id);
}

//POS ON and OFF
void CROS_RunMainFun(E_ChannelID id,uint16 cur)
{
    uint16 lgmask=0;
    uint16 cur0=0;
    uint8 pwmc=0;
    uint8 SwitchOn=0;

    lgmask=GetChannelMaskByLightFunction(E_FrontCrossLamp);
    if(((lgmask>>id)&0x01)!=0) 
    {
        SwitchOn=Lighting_GetAct(E_FrontCrossLamp);
        if(SwitchOn==ACT_ON)
        {
            pwmc=Lighting_SetPwmRamp(E_FrontCrossLamp);
            cur0=cur*pwmc/100;
            CROS_On(id,cur0);
            SetLgtStsFb_CROS(STS_ON);
        }
        else
        {
            CROS_Off(id);
            SetLgtStsFb_CROS(STS_OFF);   
        }       
    }
}



