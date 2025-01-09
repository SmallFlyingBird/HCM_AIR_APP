#include "HcmPlatform.h"
#include "POS.h"
#include "Buck_Interface.h"
#include "Channel_Interface.h"
#include "Dio_Service.h"
#include "Lighting.h"
#include "Parameter_Interface.h"

uint16 POS_On(E_ChannelID id,uint16 cur,uint16 *sts)
{
    uint16 drl_sts=0;
    uint8 IntensityPosPerc=0;
    uint16 cur0=0;
    IntensityPosPerc=Get_pLedIntensityPos();
    if(id==ChannelID2)
    {
        if((sts[ChannelID2_Alt]&E_TI)!=0)//需点亮位置CH2,但转向已打开且位于CH2_Alt
        {
            Port_CH2_Disable();
            sts[id]&= (~E_POS);
        }
        else
        {
            Port_CH2_Enable();
            sts[id] |=E_POS; 
        }
    }
    else if(id==ChannelID2_Alt) 
    {
        if((sts[ChannelID2_Alt]&E_TI)!=0)//需点亮日行CH2,但转向已打开，且位于CH2
        {
            Port_CH2Alt_Disable();
            sts[id]&= (~E_POS);
        }
        else
        {
            Port_CH2Alt_Enable();
            sts[id]|=E_POS;
        }
    }
    else 
    {
        sts[id] |=E_POS; 
    }
    if((sts[id]&E_POS)!=0)
    {
        Interface_SetChannelCurrent(id,cur*IntensityPosPerc); //设置通道电流
        Interface_SetChannelSwitchState(id, CHANNEL_STATE_ON); 
    }
    drl_sts=sts[id];
    return drl_sts;
}

//close the pos
void POS_Off(E_ChannelID id)
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
