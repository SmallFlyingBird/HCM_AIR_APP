#include "HcmPlatform.h"
#include "DRL.h"
#include "Buck_Interface.h"
#include "Channel_Interface.h"
#include "Dio_Service.h"
#include "Lighting.h"

uint16 DRL_On(E_ChannelID id,uint16 cur,uint16 *sts)
{
    uint16 drl_sts=0;
   if(id==ChannelID2)
    {
        if((sts[ChannelID2_Alt]&E_TI)!=0)//can't open CH2,the TI is CH2_Alt
        {
            Port_CH2_Disable();
            sts[id]&= (~E_DRL);
        }
        else
        {
            Port_CH2_Enable();
            sts[id]|=E_DRL; 
        }
    }
    else if(id==ChannelID2_Alt) 
    {
        if((sts[ChannelID2]&E_TI)!=0)//需点亮日行CH2_Alt,但转向已打开，且位于CH2
        {
            Port_CH2Alt_Disable();
            sts[id]&= (~E_DRL);
        }
        else
        {
            Port_CH2Alt_Enable();
            sts[id] |=E_DRL; 
        }
    }
    else
    {
        sts[id]|=E_DRL; 
    }
    if((sts[id]&E_DRL)!=0)
    {
        Interface_SetChannelCurrent(id,cur); //设置通道电流
        Interface_SetChannelSwitchState(id, CHANNEL_STATE_ON); 
    }
    drl_sts=sts[id];
    return drl_sts;
}

//close the drl
void DRL_Off(E_ChannelID id)
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
