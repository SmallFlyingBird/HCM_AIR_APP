#include "HcmPlatform.h"
#include "Lighting.h"
#include "HB.h"
#include "Buck_Interface.h"
#include "Channel_Interface.h"
#include "Pwm_Service.h"
#include "Parameter_Interface.h"
#include "DTC_Interface.h"
#include "NtcRcod_Interface.h"

void HB_On(E_ChannelID id)
{
    uint8 pwm=100,pwmramp=100;
    uint16 cur=0; 
    pwm=Interface_GetSignal_ChannelPwm(id);
    pwmramp=Lighting_SetPwmRamp(E_HighBeamSpot);
    pwm=pwm*pwmramp/100;
    cur=Interface_GetSignal_ChannelCurrent(id);
    Interface_ChannelOpen(id,cur,pwm); 
}

void HB_Off(E_ChannelID id)
{
    Interface_ChannelClose(id);
}

//HB ON and OFF
Std_ReturnType HB_RunMainFun(uint16 *sts)
{
    uint16 lgmask=0;
    U_ChannelErrorState err;
    uint8 SwitchOn;
    E_ChannelID id=ChannelID1;
    uint8 ntc_err=0,bin_err=0;
    static uint8 HB_ErrStatus=0;  //0 LB=NO ERR
    if((GetLgtStsEna_WELC()==1)||(GetLgtStsEna_GDY()==1)||(GetLgtStsEna_Charge()==1))
    {
        return E_OK;
    }
    lgmask=GetChannelMaskByLightFunction(E_HighBeamSpot);
    for(id==ChannelID1;id<CHANNEL_NUM;id++)
    {
        if(((lgmask>>id)&0x01)!=0) 
        {
            SwitchOn=Lighting_GetAct(E_HighBeamSpot);
            if(SwitchOn==ACT_ON)
            {
                if(HB_ErrStatus==0)
                {
                    sts[id] |= E_HB; //CH1 CH1_Tap is one channel               
                    HB_On(id);
                }
            }
            else
            {             
                sts[id] &=(~E_HB);
                HB_ErrStatus=0;
                HB_Off(id);
                Reset_ChannelAllError(id);
            }
/* the status of highbeam */
            if((sts[id]&E_HB)!=0) 
            {
                err=Interface_GetChannelState(id);
                if(err.Error==0) 
                {
                    ntc_err=Interface_GetChannelNtcError(id);
                    bin_err=Interface_GetChannelBinError(id);
                    if((ntc_err!=0)||(bin_err!=0))
                    {
                        SetLgtStsFb_HB(STS_ERR);  
                    }
                    else if(GetLgtStsFb_HB()!=STS_ERR)
                    {
                        SetLgtStsFb_HB(STS_ON);
                    }                  
                }
                else
                {
                    SetLgtStsFb_HB(STS_ERR);
                    HB_Off(id);
                    HB_ErrStatus=1;
                }
            }
            else 
            {
                SetLgtStsFb_HB(STS_OFF);
            }
        }
    }  
    return E_OK;
}

