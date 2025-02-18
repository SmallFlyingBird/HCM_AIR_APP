#include "HcmPlatform.h"
#include "DRL.h"
#include "Buck_Interface.h"
#include "Channel_Interface.h"
#include "Dio_Service.h"
#include "Lighting.h"
#include "Parameter_Interface.h"
#include "DTC_Interface.h"

static uint8 DRL_errcnt=0;          // err renew delay cnt
static uint8 ledofffflag=0;     //err:flag=1,led keep off status
static uint16 Drl_Sts=0;

static void DRL_On(E_ChannelID id,uint16 *sts,uint8 pwm,uint16 cur)
{
    uint8 i=0;
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
        Interface_ChannelOpen(id,cur,pwm);
    }
}

//close the drl
static void DRL_Off(E_ChannelID id)
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
    SetLgtStsFb_DRL(STS_OFF); 
}

static void DRL_ON_Run(E_ChannelID id,uint16 *sts)
{
    uint8 pwmramp=0,pwmcur=0,pwmall=0;
    uint16 drl_sts=0,cur=0;
    U_ChannelErrorState err;
    
    if(ledofffflag==0)
    {
        cur=Interface_GetSignal_ChannelCurrent(id);
        pwmramp=Lighting_SetPwmRamp(E_DaytimeRunningLight);
        pwmcur=Interface_GetSignal_ChannelPwm(id);
        pwmall=pwmramp*pwmcur/100;
        DRL_On(id,sts,pwmall,cur);
        err=Interface_GetChannelState(id);
        if((err.Error!=0) &&(pwmall==100))
        {
            if(DRL_errcnt++>=16)//wait err renew
            {
                DRL_errcnt=16;
                ledofffflag=1;
                DRL_Off(id);
                SetLgtStsFb_DRL(STS_ERR);
            }
        }
        else
        {
            SetLgtStsFb_DRL(STS_ON);
        }
    }
}
//DRL ON and OFF
Std_ReturnType DRL_RunMainFun(uint16 *sts)
{
    uint16 lgmask=0,lgmask1=0;
    uint8 SwitchOn_Drl=0,SwitchOn_pos=0;
    uint16 drl_sts=0;
    uint8 stsreadback=0;
    E_ChannelID id=ChannelID1;
    lgmask=GetChannelMaskByLightFunction(E_DaytimeRunningLight);
    for(id=ChannelID1;id<CHANNEL_NUM;id++)
    {
        if(((lgmask>>id)&0x01)!=0) 
        {
            SwitchOn_Drl=Lighting_GetAct(E_DaytimeRunningLight);
            if(SwitchOn_Drl==ACT_ON)
            {
                DRL_ON_Run(id,sts);
            }
            else
            {
                ledofffflag=0;
                DRL_errcnt=0;
                sts[id]&= (~E_DRL); 
                lgmask1=GetChannelMaskByLightFunction(E_PositionLight);
                SwitchOn_pos=Lighting_GetAct(E_PositionLight);
/* share channel : pos is on ,not close  */
                if((((lgmask1>>id)&0x01)==0) || (SwitchOn_pos==ACT_OFF)) 
                {
                    DRL_Off(id);
                }           
            }                
        }
    }
    return E_OK;
}


