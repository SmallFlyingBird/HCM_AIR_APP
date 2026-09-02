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
void CROS_RunMainFun(void)
{
    uint16 lgmask=0;
    uint8 pwmc=0;
    uint8 SwitchOn=0;
    E_ChannelID id=ChannelID1;
    lgmask=GetChannelMaskByLightFunction(E_FrontCrossLamp);
    for(id=ChannelID1;id<CHANNEL_NUM;id++)
    {
        if(((lgmask>>id)&0x01)!=0) 
        {
            SwitchOn=Lighting_GetAct(E_FrontCrossLamp);
            if(SwitchOn==ACT_ON)
            {
                CROS_On(id);  
            }
            else
            {
                CROS_Off(id);
            }    
            if(SwitchOn==ACT_ON)
            {
                if(Interface_GetChannelState_Light(id)==0) 
                {
                    SetLgtStsFb_Status(STS_ON,E_FrontCrossLamp);
                    SetDTCGroup_CROS(DTC_Noerr);
                }
                else
                {
                    SetLgtStsFb_Status(STS_ERR,E_FrontCrossLamp);
                    SetDTCGroup_CROS(DTC_Error);
                    Interface_SetLightChannelStateSwitch(id,STS_ERR);
                }
            }
            else 
            {
                SetLgtStsFb_Status(STS_OFF,E_FrontCrossLamp);
            }   
        }

    }
}



