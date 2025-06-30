#include "HcmPlatform.h"
#include "Lighting.h"
#include "HB.h"
#include "Buck_Interface.h"
#include "Channel_Interface.h"
#include "Pwm_Service.h"
#include "Parameter_Interface.h"
#include "DTC_Interface.h"
#include "NtcRcod_Interface.h"
#include "Channel_Interface.h"
void HB_On(E_ChannelID id)
{
    uint8 pwm=100,pwmramp=100;
    uint16 cur=0; 
    pwm=Interface_GetSignal_ChannelPwm(id);
    pwmramp=Lighting_SetPwmRamp(E_HighBeam);
    pwm=pwm*pwmramp/100;
    cur=Interface_GetSignal_ChannelCurrent(id);
    Interface_ChannelOpen(id,cur,pwm); 
}

void HB_Off(E_ChannelID id)
{
    Interface_ChannelClose(id);
}

//HB ON and OFF
void HB_RunMainFun(void)
{
    uint16 lgmask=0;
    uint8 SwitchOn;
    E_ChannelID id=ChannelID1;
    uint8 ntc_err=0,bin_err=0;
    static uint8 HB_ErrStatus=0;  //0 LB=NO ERR
    static uint8 errcheckflag=0;
    if((GetLgtStsEna_WELC()==1)||(GetLgtStsEna_GDY()==1))
    {
        SetLgtStsFb_HB(STS_OFF);
        lgmask=GetChannelMaskByLightFunction(E_HighBeam);
        for(id=ChannelID1;id<CHANNEL_NUM;id++)
        {
            if(((lgmask>>id)&0x01)!=0) 
            {
                if(Interface_GetLightChannelStateSwitch(id) ==CHANNEL_STATE_ON)
                {
                    HB_Off(id);
                }
            }
        }
    }
    else
    {
        lgmask=GetChannelMaskByLightFunction(E_HighBeam);
        for(id=ChannelID1;id<CHANNEL_NUM;id++)
        {
            if(((lgmask>>id)&0x01)!=0) 
            {
                SwitchOn=Lighting_GetAct(E_HighBeam);
                if(SwitchOn==ACT_ON)
                {
                    if(HB_ErrStatus==0)
                    {       
                        if(Interface_GetLightChannelStateSwitch(id)==CHANNEL_STATE_OFF)
                        {
                            Reset_ChannelAllError(id);
                        }      
                        HB_On(id);
                    }
                }
                else
                {             
                    HB_ErrStatus=0;
                    HB_Off(id);
                }
    /* the status of highbeam */
                if(SwitchOn==ACT_ON) 
                {
                    if(Interface_GetChannelState(id)==0) 
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
                        if(errcheckflag==1)
                        {
                            SetLgtStsFb_HB(STS_ERR);
                            Interface_SetLightChannelStateSwitch(id,STS_ERR);
                            HB_Off(id);
                            HB_ErrStatus=1;
                        }
                    }
                    errcheckflag=1;
                }
                else 
                {
                    errcheckflag=0;
                    SetLgtStsFb_HB(STS_OFF);
                }
            }
        }  
    }
}

