#include "HcmPlatform.h"
#include "DRL.h"
#include "Buck_Interface.h"
#include "Channel_Interface.h"
#include "Dio_Service.h"
#include "Lighting.h"
#include "Parameter_Interface.h"
#include "DTC_Interface.h"

uint16 DRL_On(E_ChannelID id,uint16 *sts)
{
    uint16 drl_sts=0,cur=0;
    uint8 pwmramp=0,pwmcur=0,pwmall=0;
   
    if(id==ChannelID2)
    {
/* can't open CH2,the TI is CH2_Alt */
        if((sts[ChannelID2_Alt]&E_TI)!=0)
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
/* drl is CH2_ALT ON,but TI is CH2 ON */
        if((sts[ChannelID2]&E_TI)!=0)
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
        cur=Interface_GetSignal_ChannelCurrent(id);
        pwmramp=Lighting_SetPwmRamp(E_DaytimeRunningLight);
        pwmcur=Interface_GetSignal_ChannelPwm(id);
        pwmall=pwmramp*pwmcur/100;
        Interface_ChannelOpen(id,cur,pwmall);
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
uint16 DRL_RunMainFun(E_ChannelID id,uint16 *sts)
{
    uint16 lgmask=0,lgmask1=0;
    uint8 SwitchOn=0;
    U_ChannelErrorState err;
/* channel choose */
    lgmask=GetChannelMaskByLightFunction(E_DaytimeRunningLight);
    if(((lgmask>>id)&0x01)!=0) 
    {
        SwitchOn=Lighting_GetAct(E_DaytimeRunningLight);
        if(SwitchOn==ACT_ON)
        {
            sts[id]=DRL_On(id,sts);
        }
        else
        {
            sts[id]&= (~E_DRL); 
            lgmask1=GetChannelMaskByLightFunction(E_PositionLight);
            SwitchOn=Lighting_GetAct(E_PositionLight);
/* share channel : pos is on ,not close  */
            if((((lgmask1>>id)&0x01)!=0) && (SwitchOn==ACT_ON)) 
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
            err=Interface_GetChannelState(id);
            if(err.Error==1) 
            {
                SetLgtStsFb_DRL(STS_ERR);
            }
            else
            {
                SetLgtStsFb_DRL(STS_ON);
            }
        }
        else
        {
            SetLgtStsFb_DRL(STS_OFF);
        }
    }
    return sts[id];
}


