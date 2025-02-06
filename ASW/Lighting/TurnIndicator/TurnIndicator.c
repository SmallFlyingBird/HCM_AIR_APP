
#include "HcmPlatform.h"
#include "TurnIndicator.h"
#include "Lighting.h"
#include "Buck_Interface.h"
#include "Channel_Interface.h"
#include "Dio_Service.h"
#include "Parameter_Interface.h"

Std_ReturnType TI_On(E_ChannelID id,uint16 cur,uint16 *sts)
{
    uint8 pwm=100;
    pwm=Interface_GetSignal_ChannelPwm(id);
    if(id==ChannelID2)
    {
        if(((sts[ChannelID2_Alt]&E_POS)!=0)||((sts[ChannelID2_Alt]&E_DRL)!=0))
            return E_NOT_OK;

        Port_CH2_Enable();
    }
    else if(id==ChannelID2_Alt) 
    {
        if(((sts[ChannelID2]&E_POS)!=0)||((sts[ChannelID2]&E_DRL)!=0))
            return E_NOT_OK;// wait pos drl close

        Port_CH2Alt_Enable();
    }         
    Interface_ChannelOpen(id,cur,pwm);
    return E_OK;  
}

Std_ReturnType TI_Off(E_ChannelID id)
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
    return E_OK; 
}    

//TI ON and OFF
uint16 TI_RunMainFun(E_ChannelID id,uint16 cur,uint16 *sts)
{
    uint16 lgmask=0;
    uint16 cur0=0;
    uint8 pwmc=0;
    uint8 SwitchOn=0;
    lgmask=GetChannelMaskByLightFunction(E_TurnIndicator);
    if(((lgmask>>id)&0x01)!=0) 
    {
        SwitchOn=Lighting_GetAct(E_TurnIndicator);
        if(((SwitchOn&0x01)==ACT_ON)&&(((SwitchOn>>1)&0x01)==ACT_ON))
        {               
            pwmc=Lighting_SetPwmRamp(E_TurnIndicator);
            cur0=cur*pwmc/100;
            sts[id] |= E_TI; //CH1 CH1_Tap is one channel  
            TI_On(id,cur,sts);
        }
        else
        {              
            sts[id] &= (~E_TI); 
            TI_Off(id);
        }   
        if((sts[id]&E_TI)!=0) 
        {
            SetLgtStsFb_TI(STS_ON);
        }
        else 
        {
            SetLgtStsFb_TI(STS_OFF);
        }  
    }
    return sts[id];
}

