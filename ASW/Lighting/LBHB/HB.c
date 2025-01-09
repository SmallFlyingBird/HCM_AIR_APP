#include "HcmPlatform.h"
#include "Lighting.h"
#include "HB.h"
#include "Buck_Interface.h"
#include "Channel_Interface.h"
#include "Pwm_Service.h"

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


void HB_RUN()
{

}