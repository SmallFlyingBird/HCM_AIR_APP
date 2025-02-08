
#include "HcmPlatform.h"
#include "LB.h"
#include "Lighting.h"
#include "Buck_Interface.h"
#include "Channel_Interface.h"
#include "Pwm_Service.h"
#include "Parameter_Interface.h"
#include "FAN.h"
static void LB_On(E_ChannelID id)
{
    uint8 pwm=0,pwmramp=0;
    uint16 cur=0;
    if(id==ChannelID1_Tap)
    {
        Pwm_CH1Tap_Enable();
    }
    pwm=Interface_GetSignal_ChannelPwm(id);
    pwmramp=Lighting_SetPwmRamp(E_LowBeamKink); //get ramp pwm
    pwm=pwm*pwmramp/100;
    cur=Interface_GetSignal_ChannelCurrent(id); 
    Interface_ChannelOpen(id,cur,pwm); 
}

static void LB_Off(E_ChannelID id)
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
uint16 LB_RunMainFun(E_ChannelID id,uint16 *sts)
{
    uint16 lgmask=0;
    uint16 lb_sts=0;
    U_ChannelErrorState err;
    uint8 SwitchOn;
    lgmask=GetChannelMaskByLightFunction(E_LowBeamKink);
    if(((lgmask>>id)&0x01)!=0) 
    {
        SwitchOn=Lighting_GetAct(E_LowBeamKink);
        if(SwitchOn==ACT_ON)
        {              
            sts[id] |=E_LB; //CH1 CH1_Tap会相互影响
            LB_On(id);
        }
        else
        {
            sts[id] &=(~E_LB); //CH1 CH1_Tap会相互影响
            LB_Off(id);             
        }
        if((sts[id]&E_LB)!=0) 
        {
            err=Interface_GetChannelState(id);
            if(err.Error==1) //channel
            {
                SetLgtStsFb_LB(STS_ERR);
            }
            else if (Fan_GetFanFaultSignal()) //fan error
            {
                SetLgtStsFb_LB(STS_ERR);
            }
            else
            {
                SetLgtStsFb_LB(STS_ON);
            }
        }
        else 
        {
            SetLgtStsFb_LB(STS_OFF);
        }
    }
    lb_sts=sts[id];
    return lb_sts;
}













