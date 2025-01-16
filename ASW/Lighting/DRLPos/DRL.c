#include "HcmPlatform.h"
#include "DRL.h"
#include "Buck_Interface.h"
#include "Channel_Interface.h"
#include "Dio_Service.h"
#include "Lighting.h"
#include "Parameter_Interface.h"

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

//DRL ON and OFF
uint16 DRL_RunMainFun(E_ChannelID id,uint16 cur,uint16 *sts)
{
    uint16 lgmask=0,lgmask1=0;
    uint16 cur0=0;
    uint8 pwmc=0;
    uint8 SwitchOn=0;

    lgmask=GetChannelMaskByLightFunction(E_DaytimeRunningLight);
    if(((lgmask>>id)&0x01)!=0) 
    {
        SwitchOn=Lighting_GetAct(E_DaytimeRunningLight);
        if(SwitchOn==ACT_ON)
        {
            pwmc=Lighting_SetPwmRamp(E_DaytimeRunningLight);
            cur0=cur*pwmc/100;
            sts[id]=DRL_On(id,cur0,sts);
        }
        else
        {
            sts[id]&= (~E_DRL); 
            lgmask1=GetChannelMaskByLightFunction(E_PositionLight);
            SwitchOn=Lighting_GetAct(E_PositionLight);
            if((((lgmask1>>id)&0x01)!=0) && (SwitchOn==ACT_ON)) //share channel : pos is on ,not close 
            {
                return sts[id];
            }
            else
            {
                DRL_Off(id);
            }            
        }                
        if((sts[id]&E_DRL)!=0)
        {
            SetLgtStsFb_DRL(STS_ON);
        }
        else
        {
            SetLgtStsFb_DRL(STS_OFF);
        }
    }
    return sts[id];
}


