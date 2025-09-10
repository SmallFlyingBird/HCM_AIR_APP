
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

void CornLamp_RunMainFun(void)
{
    uint16 lgmask=0;
    uint8 SwitchOn=0;

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
            }
            else
            {
                CornLamp_Off(id); 
            }    
            if(SwitchOn==ACT_ON)
            {
                if(Interface_GetChannelState(id)==0) 
                {
                    SetLgtStsFb_Status(STS_ON,E_CorneringLight);
                    SetDTCGroup_CORN(DTC_Noerr);
                }
                else
                {
                    SetLgtStsFb_Status(STS_ERR,E_CorneringLight);
                    SetDTCGroup_CORN(DTC_Error);
                    Interface_SetLightChannelStateSwitch(id,STS_ERR);
                }
            }
            else 
            {
                SetLgtStsFb_Status(STS_OFF,E_CorneringLight);
            }   
        }
    }
}



