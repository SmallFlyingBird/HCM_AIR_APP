
#include "HcmPlatform.h"
#include "TurnIndicator.h"
#include "Buck_Interface.h"
#include "Channel_Interface.h"
#include "Lighting.h"
#include "Dio_Service.h"

void TI_On(E_ChannelID id,uint16 cur,uint16 *sts)
{
   if(id==ChannelID2)
    {
        if(((sts[ChannelID2_Alt]&E_POS)!=0)||((sts[ChannelID2_Alt]&E_DRL)!=0))
        {
            // wait pos drl close
        }
        else
        {
            Port_CH2_Enable();
        }
    }
    else if(id==ChannelID2_Alt) 
    {
        if(((sts[ChannelID2]&E_POS)!=0)||((sts[ChannelID2]&E_DRL)!=0))
        {
            // wait pos drl close
        }
        else
        {
            Port_CH2Alt_Enable();
        }
    }           
    Interface_ChannelOpen(id,cur);
}

void TI_Off(E_ChannelID id)
{
    if(id==ChannelID2)
    {
        Port_CH2_Disable();
    }
    else if(id==ChannelID2_Alt) 
    {
        Port_CH2Alt_Disable();
    }
    else
    {
        Interface_ChannelClose(id);
    }
}    