#include "HcmPlatform.h"
#include "Lighting.h"
#include "HB.h"
#include "Buck_Interface.h"
#include "Channel_Interface.h"
#include "Pwm_Service.h"
#include "Parameter_Interface.h"

void HB_Init()
{

}
void HB_On(E_ChannelID id,uint16 cur)
{
    if(id==ChannelID1_Tap)
    {
        Pwm_CH1Tap_Enable();
    }
    Interface_ChannelOpen(id,cur); 
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
uint16 HB_RunMainFun(E_ChannelID id,uint16 cur,uint8 SwitchOn,uint16 *sts)
{
    uint16 lgmask=0;
    uint16 cur0=0;
    uint8 pwmc=0;
    lgmask=GetChannelMaskByLightFunction(E_HighBeamSpot);
    if(((lgmask>>id)&0x01)!=0) 
    {
        if(SwitchOn==ACT_ON)
        {
            pwmc=Lighting_SetPwmRamp(E_HighBeamSpot);
            cur0=cur*pwmc/100;
            sts[id] |= E_HB; //CH1 CH1_Tap is one channel               
            HB_On(id,cur0);
        }
        else
        {             
            sts[id] &=(~E_HB); 
            HB_Off(id);
        }
        if((sts[id]&E_HB)!=0) 
        {
            SetLgtStsFb_HB(STS_ON);
        }
        else 
        {
            SetLgtStsFb_HB(STS_OFF);
        }
    }
    return sts[id];
}

