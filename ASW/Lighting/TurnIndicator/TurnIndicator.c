
#include "HcmPlatform.h"
#include "TurnIndicator.h"
#include "Lighting.h"
#include "Buck_Interface.h"
#include "Channel_Interface.h"
#include "Dio_Service.h"
#include "Parameter_Interface.h"
#include "DTC_Interface.h"
#include "LinManager.h"

#define TI_ERR_DELAY    20
uint8 TiDelayCnt=0;
typedef struct Drl_Err_Status
{
    struct {  
    uint8 ch2err      :1;
    uint8 ch4err      :1;  
    uint8 rev         :6;        
    } bits;
    uint8 errsts;
} TI_Err_Status;

TI_Err_Status S_TI_Status; 
static uint8 TIOff_flag=0;
static Std_ReturnType TI_On(E_ChannelID id,uint16 *sts)
{
    uint8 pwm=100,pwmramp=100;  
    uint16 cur=0; 
    if(id==ChannelID2)
    {
        if(((sts[ChannelID2_Alt]&E_POS)!=0)||((sts[ChannelID2_Alt]&E_DRL)!=0))
        {
            Port_CH2Alt_Disable();
            Interface_ChannelClose(ChannelID2_Alt);
        }
        Port_CH2_Enable(0);
    }
    else if(id==ChannelID2_Alt) 
    {
        if(((sts[ChannelID2]&E_POS)!=0)||((sts[ChannelID2]&E_DRL)!=0))
        {
            Port_CH2_Disable();
            Interface_ChannelClose(ChannelID2);
        }// wait pos drl close
        Port_CH2Alt_Enable(0);
    }
    pwm=Interface_GetSignal_ChannelPwm(id);
    pwmramp=Lighting_SetPwmRamp(E_TurnIndicator);
    pwm=pwm*pwmramp/100;
    cur=Interface_GetSignal_ChannelCurrent(id);        
    Interface_ChannelOpen(id,cur,pwm);
    return E_OK;  
}

/*
E_ChannelID id  :channel id
uint8 flag      : 1: TI STS ON RUN;  0:TI OFF
*/
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
    if(TIOff_flag==1)
    {
        TIOff_flag=0;
        Interface_ChannelClose(id); //act on,sts off
    }

    return E_OK; 
}    


/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
void TI_RunMainFun(uint16 *sts)
{
    uint16 lgmask=0;
    uint8 TIsts=0,TIact=0;
    E_ChannelID id=ChannelID1;
    U_ChannelErrorState err;
    lgmask=GetChannelMaskByLightFunction(E_TurnIndicator);
    for(id=ChannelID1;id<CHANNEL_NUM;id++)
    {
        if(((lgmask>>id)&0x01)!=0) 
        {
            TIsts=Lighting_GetLinCtrl(E_TurnIndicator);
            TIact=Lighting_GetLinCtrl(E_TurnIndicator_Act);
            #ifdef RightAir
            TIsts=(TIsts&0x02)>>1;
            TIact=(TIact&0x02)>>1;
            #endif
            #ifdef LeftAir
            TIsts=TIsts&0x01;
            TIact=TIact&0x01;
            #endif
            if((TIsts==ACT_ON)&&(TIact==ACT_ON))
            {    
                if(S_TI_Status.errsts==0)  
                {
                    sts[id] |= E_TI; //CH1 CH1_Tap is one channel  
                    TI_On(id,sts); 
                    SetLgtStsFb_TI(STS_ON);                 
                }   
                else
                {
                    SetLgtStsFb_TI(STS_ERR);
                }
            }  
            else if((TIsts==ACT_ON)&&(TIact==ACT_OFF))
            {
                if(S_TI_Status.errsts==0) 
                {
                    TiDelayCnt=0;
                    sts[id] |= E_TI; //CH1 CH1_Tap is one channel 
                    TIOff_flag=1;
                    TI_Off(id);
                    SetLgtStsFb_TI(STS_OFF);
                }
                else
                {
                    SetLgtStsFb_TI(STS_ERR);
                }               
            }
            else
            {       
                TiDelayCnt=0;               
                S_TI_Status.errsts=0;      
                sts[id] &= (~E_TI); 
                Reset_ChannelErrorCnt(id);
                TI_Off(id);
                SetLgtStsFb_TI(STS_OFF);
            } 

            if((sts[id] &E_TI)!=0)
            {
                err=Interface_GetChannelState(id);

                if(err.Error!=0)
                {
                    TiDelayCnt++;
                    if(TiDelayCnt>=5)
                    {
                        TiDelayCnt=5;
                        TIOff_flag=1;
                        TI_Off(id); 
                        S_TI_Status.errsts=1; 
                    }        
                }  
            }
        }
    }
}

