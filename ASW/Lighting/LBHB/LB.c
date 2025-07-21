
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
    pwm=Interface_GetSignal_ChannelPwm(id);
#if APP_E2E_FUN
    pwmramp=100;
#else
    pwmramp=Lighting_SetPwmRamp(E_LowBeam); //get ramp pwm
#endif
    pwm=pwm*pwmramp/100;
    cur=Interface_GetSignal_ChannelCurrent(id); 
    Interface_ChannelOpen(id,cur,pwm);
}

static void LB_Off(E_ChannelID id)
{
    Interface_ChannelClose(id);
}          

//LB RUN
Std_ReturnType LB_RunMainFun(void)
{
    static uint8 LB_ErrStatus=0;  //0 LB=NO ERR
    uint16 lgmask=0;
    uint8 SwitchOn=0;
    uint8 ntc_err=0,bin_err=0;
    static uint8 errcheckflag=0;
    if((GetLgtStsEna_WELC() == TRUE) || (GetLgtStsEna_GDY() == TRUE) )
    {
        SetLgtStsFb_LB(STS_OFF);  
        return E_OK;
    }
/* normal mode */
    lgmask=GetChannelMaskByLightFunction(E_LowBeam);

    if(((lgmask>>ChannelID1)&0x01)!=0) 
    {
/* functionsafety mode */
#if APP_E2E_FUN
        U_E2EErrorFlag LB_E2EFlag;
        LB_E2EFlag=Rbk_U_E2EErrorFlag();
        if((LB_E2EFlag.bits.ActnOfLedLoBeamCntErr==1)||(LB_E2EFlag.bits.ActnOfLedLoBeamCrcErr==1)||(LB_E2EFlag.bits.ActnOfLedLoBeamTimeout==1))
        {
            LB_On(ChannelID1);
            SetLgtStsFb_LB(STS_ON);
            Interface_SetLightChannelStateSwitch(ChannelID1,STS_ON);
        }
        else
#endif
        {
/* normal mode */            
            SwitchOn=Lighting_GetAct(E_LowBeam);
            if(SwitchOn==ACT_ON)
            {       
                if(LB_ErrStatus==0) 
                {
                    if(Interface_GetLightChannelStateSwitch(ChannelID1)==CHANNEL_STATE_OFF)
                    {
                        Reset_ChannelAllError(ChannelID1);
                    }
                    LB_On(ChannelID1);
                }      
            }
            else
            {
                LB_ErrStatus=0;
                LB_Off(ChannelID1);            
            }
/* the status of lowbeam */
            if(SwitchOn==ACT_ON)
            {
                ntc_err=Interface_GetChannelNtcError(ChannelID1);
                bin_err=Interface_GetChannelBinError(ChannelID1);
                if(Interface_GetChannelState(ChannelID1)==0)  //channel err
                {      
                    if(Fan_GetFanFaultSignal()) //fan error
                    {
                        SetLgtStsFb_LB(STS_ERR);
                        LB_ErrStatus=1;
                        LB_Off(ChannelID1);
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
                    if(errcheckflag==1)
                    {
                        SetLgtStsFb_LB(STS_ERR); 
                        Interface_SetLightChannelStateSwitch(ChannelID1,STS_ERR);
                        LB_ErrStatus=1;
                        LB_Off(ChannelID1);
                    }
                }  
                errcheckflag=1;
            }
            else //the channel off
            {
                errcheckflag=0;
                SetLgtStsFb_LB(STS_OFF);
            }
        }
    }
    return E_OK;
}













