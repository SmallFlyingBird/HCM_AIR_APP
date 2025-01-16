
#include "HcmPlatform.h"
#include "LB.h"
#include "Lighting.h"
#include "Buck_Interface.h"
#include "Channel_Interface.h"
#include "Pwm_Service.h"
#include "Parameter_Interface.h"
#include "FAN.h"
void LB_On(E_ChannelID id,uint16 cur)
{
    if(id==ChannelID1_Tap)
    {
        Pwm_CH1Tap_Enable();
    }
    Interface_ChannelOpen(id,cur); 
}

void LB_Off(E_ChannelID id)
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

//LB运行代码
uint16 LB_RunMainFun(E_ChannelID id,uint16 cur,uint8 SwitchOn,uint16 *sts)
{
    uint16 lgmask=0;
    uint16 cur0=0;
    uint8 pwmc=0;
    uint16 lb_sts=0;
    lgmask=GetChannelMaskByLightFunction(E_LowBeamKink);
    if(((lgmask>>id)&0x01)!=0) 
    {
        if(SwitchOn==ACT_ON)
        {             
            pwmc=Lighting_SetPwmRamp(E_LowBeamKink); //get ramp pwm
            cur0=cur*pwmc/100;  
            sts[id] |=E_LB; //CH1 CH1_Tap会相互影响
            LB_On(id,cur);
        }
        else
        {
            sts[id] &=(~E_LB); //CH1 CH1_Tap会相互影响
            LB_Off(id);             
        }
        if((sts[id]&E_LB)!=0) 
        {
            SetLgtStsFb_LB(STS_ON);
        }
        else 
        {
            SetLgtStsFb_LB(STS_OFF);
        }
//fan error
        if (Fan_GetFanFaultSignal())
        {
            SetLgtStsFb_LB(STS_ERR);
        }
    }
    lb_sts=sts[id];
    return lb_sts;
}













