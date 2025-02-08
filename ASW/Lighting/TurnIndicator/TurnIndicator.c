
#include "HcmPlatform.h"
#include "TurnIndicator.h"
#include "Lighting.h"
#include "Buck_Interface.h"
#include "Channel_Interface.h"
#include "Dio_Service.h"
#include "Parameter_Interface.h"
#include "DTC_Interface.h"


static Std_ReturnType TI_On(E_ChannelID id,uint16 *sts)
{
    uint8 pwm=100,pwmramp=100;  
    uint16 cur=0; 
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
    pwm=Interface_GetSignal_ChannelPwm(id);
    pwmramp=Lighting_SetPwmRamp(E_TurnIndicator);
    pwm=pwm*pwmramp/100;
    cur=Interface_GetSignal_ChannelCurrent(id);        
    Interface_ChannelOpen(id,cur,pwm);
    return E_OK;  
}

static Std_ReturnType TI_Off(E_ChannelID id)
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

//left on ;right on ;left and right on
/* return 1: signal ok  ; return 0 :signal no use
 */
uint8 rtval1=0;
Std_ReturnType TI_LinStsActAnalysis(uint8 sts,uint8 act)
{
    
    if(((sts==act)&&(sts!=0))||((act==0)&&(sts!=0)))
    {
    #ifdef LeftAir
        sts&=0x01;  
        act&=0x01;  
    #endif
    #ifdef RightAir
        sts&=0x02; 
        act&=0x02; 
    #endif
        if(sts!=0) rtval1=1;
        else rtval1=0;
    }
    else
    {
        rtval1=0;
    }
    return rtval1;
}

/***************************************************************************************************************************************************/

//TI ON and OFF
uint16 TI_RunMainFun(E_ChannelID id,uint16 *sts)
{
    uint16 lgmask=0;
    uint8 TIsts=0,TIact=0,SwitchOn=0;
    U_ChannelErrorState err;
    lgmask=GetChannelMaskByLightFunction(E_TurnIndicator);
    if(((lgmask>>id)&0x01)!=0) 
    {
        TIsts=Lighting_GetAct(E_TurnIndicator);
        TIact=Lighting_GetAct(E_TurnIndicator_Act);
        if((TIsts==ACT_ON)&&(TIact==ACT_ON))
        {               
            sts[id] |= E_TI; //CH1 CH1_Tap is one channel  
            TI_On(id,sts);
        }
        else
        {              
            sts[id] &= (~E_TI); 
            TI_Off(id);
        }   
        if((sts[id]&E_TI)!=0) 
        {
            err=Interface_GetChannelState(id);
            if(err.Error==1) 
            {
                SetLgtStsFb_TI(STS_ERR);
            }
            else
            {
                SetLgtStsFb_TI(STS_ON);
            }
        }
        else 
        {
            SetLgtStsFb_TI(STS_OFF);
        }  
    }
    return sts[id];
}

