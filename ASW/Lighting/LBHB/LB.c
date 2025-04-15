
#include "HcmPlatform.h"
#include "LB.h"
#include "Lighting.h"
#include "Buck_Interface.h"
#include "Channel_Interface.h"
#include "Pwm_Service.h"
#include "Parameter_Interface.h"
#include "FAN.h"

static void LB_On(E_ChannelID id)
{
    uint8 pwm=0,pwmramp=0;
    uint16 cur=0;
    if(id==ChannelID1)
    {
        Pwm_HLCtrl_Enable();
    }
    pwm=Interface_GetSignal_ChannelPwm(id);
#if APP_E2E_FUN
    pwmramp=100;
#else
    pwmramp=Lighting_SetPwmRamp(E_LowBeamKink); //get ramp pwm
#endif
    pwm=pwm*pwmramp/100;
    cur=Interface_GetSignal_ChannelCurrent(id); 
    Interface_ChannelOpen(id,cur,pwm);
}

static void LB_Off(E_ChannelID id)
{
    if(id==ChannelID1)
    {
        Pwm_HLCtrl_Disable();
    }
    else
    {
        Interface_ChannelClose(id);
    }
}          

//LB RUN
Std_ReturnType LB_RunMainFun(uint16 *sts)
{
    static uint8 LB_ErrStatus=0;  //0 LB=NO ERR
    uint16 lgmask=0;
    U_ChannelErrorState err;
    uint8 SwitchOn=0;
    uint8 ntc_err=0,bin_err=0;
    E_ChannelID id=ChannelID1;
    
    if((GetLgtStsEna_WELC()==1)||(GetLgtStsEna_GDY()==1)||(GetLgtStsEna_Charge()==1))
    {
        return E_OK;
    }
/* normal mode */
    lgmask=GetChannelMaskByLightFunction(E_LowBeamKink);
    for(id=ChannelID1;id<CHANNEL_NUM;id++)
    {
        if(((lgmask>>id)&0x01)!=0) 
        {
/* functionsafety mode */
#if APP_E2E_FUN
            U_E2EErrorFlag LB_E2EFlag;
            LB_E2EFlag=Rbk_U_E2EErrorFlag();
            if((LB_E2EFlag.bits.ActnOfLedLoBeamCntErr==1)||(LB_E2EFlag.bits.ActnOfLedLoBeamCrcErr==1)||(LB_E2EFlag.bits.ActnOfLedLoBeamTimeout==1))
            {
                sts[id] |=E_LB; //CH1 CH1_Tap
                LB_On(id);
                SetLgtStsFb_LB(STS_ERR);
            }
            else
#endif
            {
/* normal mode */            
                SwitchOn=Lighting_GetAct(E_LowBeamKink);
                if(SwitchOn==ACT_ON)
                {       
                    if(LB_ErrStatus==0) 
                    {
                        sts[id] |=E_LB; //CH1 CH1_Tap
                        LB_On(id);
                    }      
                }
                else
                {
                    LB_ErrStatus=0;
                    sts[id] &=(~E_LB); //CH1 CH1_Tap
                    LB_Off(id); 
                    Reset_ChannelAllError(id);            
                }
/* the status of lowbeam */
                if((sts[id]&E_LB)!=0) 
                {
                    err=Interface_GetChannelState(id);
                    ntc_err=Interface_GetChannelNtcError(id);
                    bin_err=Interface_GetChannelBinError(id);
                    if(err.Error==0)  //channel err
                    {      
                        if(Fan_GetFanFaultSignal()) //fan error
                        {
                            SetLgtStsFb_LB(STS_ERR);
                            LB_ErrStatus=1;
                            LB_Off(id);
                        }
                        else if((ntc_err!=0)||(bin_err!=0))  //ntc err or bin err
                        {
                            SetLgtStsFb_LB(STS_ERR);  
                        }
                        else if(GetLgtStsFb_LB()==0)    //no error
                        {
                            SetLgtStsFb_LB(STS_ON);
                        }   
                    }
                    else
                    {
                        SetLgtStsFb_LB(STS_ERR); 
                        LB_ErrStatus=1;
                        LB_Off(id);
                    }  
                }
                else //the channel off
                {
                    Reset_ChannelAllError(id);
                    SetLgtStsFb_LB(STS_OFF);
                }
            }
        }
    }
    return E_OK;
}













