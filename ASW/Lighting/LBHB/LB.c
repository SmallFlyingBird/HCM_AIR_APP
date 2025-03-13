
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

//LB RUN
void LB_RunMainFun(uint16 *sts)
{
    static uint8 LB_ErrStatus=0;  //0 LB=NO ERR
    uint16 lgmask=0;
    U_ChannelErrorState err;
    uint8 SwitchOn;
    E_ChannelID id=ChannelID1;
    lgmask=GetChannelMaskByLightFunction(E_LowBeamKink);
    for(id=ChannelID1;id<CHANNEL_NUM;id++)
    {
        if(((lgmask>>id)&0x01)!=0) 
        {
            SwitchOn=Lighting_GetAct(E_LowBeamKink);
            if(SwitchOn==ACT_ON)
            {       
                if(LB_ErrStatus==0) 
                {
                    sts[id] |=E_LB; //CH1 CH1_Tap会相互影响
                    LB_On(id);
                }      

            }
            else
            {
                LB_ErrStatus=0;
                sts[id] &=(~E_LB); //CH1 CH1_Tap会相互影响
                LB_Off(id); 
                Reset_ChannelErrorCnt(id);            
            }
            if((sts[id]&E_LB)!=0) 
            {
                err=Interface_GetChannelState(id);
                if(err.Error==0) //channel
                {
                    SetLgtStsFb_LB(STS_ON);
                }
                else if(Fan_GetFanFaultSignal()) //fan error
                {
                    SetLgtStsFb_LB(STS_ERR);
                    LB_ErrStatus=1;
                    LB_Off(id);
                }
                else
                {
                    SetLgtStsFb_LB(STS_ERR);
                    LB_ErrStatus=1;
                    LB_Off(id);
                }              
            }
            else 
            {
                Reset_ChannelErrorCnt(id);
                SetLgtStsFb_LB(STS_OFF);
            }
        }
    }
}













