#include "HcmPlatform.h"
#include "POS.h"
#include "Buck_Interface.h"
#include "Channel_Interface.h"
#include "Dio_Service.h"
#include "Lighting.h"
#include "Parameter_Interface.h"
#include "DTC_Interface.h"

uint16 POS_On(E_ChannelID id,uint16 *sts,uint8 pwm,uint16 cur)
{
    uint16 drl_sts=0;   
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
        Interface_ChannelOpen(id,cur,pwm);
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


//POS ON and OFF
void POS_RunMainFun(uint16 *sts)
{
    uint16 lgmask=0,lgmask1=0;
    uint8 SwitchOn=0;
    U_ChannelErrorState err;
    uint8 IntensityPosPerc=0,pwm=0,pwmramp=0;
    uint16 cur=0;

    E_ChannelID id=ChannelID1;
    lgmask=GetChannelMaskByLightFunction(E_PositionLight);
    for(id=ChannelID1;id<CHANNEL_NUM;id++)
    {
        if(((lgmask>>id)&0x01)!=0) 
        {
            lgmask1=GetChannelMaskByLightFunction(E_DaytimeRunningLight);
            SwitchOn=Lighting_GetAct(E_DaytimeRunningLight);
            if((((lgmask1>>id)&0x01)!=0)&&(SwitchOn==ACT_ON)) 
            {           
                sts[id]&= (~E_POS);  //the channel DRL on
            }
            else
            {
                SwitchOn=Lighting_GetAct(E_PositionLight);
                if(SwitchOn==ACT_ON)
                {             
                    pwm=Interface_GetSignal_ChannelPwm(id);
                    pwmramp=Lighting_SetPwmRamp(E_PositionLight);
                    IntensityPosPerc=Get_pLedIntensityPos();
                    pwm=pwm*pwmramp*IntensityPosPerc/10000;
                    cur=Interface_GetSignal_ChannelCurrent(id);    
                    sts[id]=POS_On(id,sts,pwm,cur);
                }
                else
                {
                    sts[id]&= (~E_POS); 
                    POS_Off(id);
                }       
            }
            if((sts[id]&E_POS)!=0)
            {
                err=Interface_GetChannelState(id);
                if((err.Error==0)&&(pwm==100))
                {
                    SetLgtStsFb_POS(STS_ERR);
                }
                else 
                {
                    SetLgtStsFb_POS(STS_ON);
                }
            }
            else
            {
                SetLgtStsFb_POS(STS_OFF);
            }
        }
    }
}


