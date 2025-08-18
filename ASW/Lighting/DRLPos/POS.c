#include "HcmPlatform.h"
#include "POS.h"
#include "Buck_Interface.h"
#include "Channel_Interface.h"
#include "Dio_Service.h"
#include "Lighting.h"
#include "Parameter_Interface.h"
#include "DTC_Interface.h"
#include "NtcRcod_Interface.h"

static uint8 errcheckflag=0;

void POS_On(E_ChannelID id,uint8 pwm,uint16 cur)
{
    uint16 drl_sts=0;   
    static uint8 TI0n_PosOff=0;
    uint8 onflag=0;
    if(id==ChannelID2)
    {
        if(Interface_GetLightChannelStateSwitch(ChannelID2_Alt) != CHANNEL_STATE_OFF)//需点亮位置CH2,但转向已打开且位于CH2_Alt
        {
            Port_CH2_Disable();
            if(TI0n_PosOff==0)
            {
                TI0n_PosOff=1;               
                Interface_ChannelClose(id);
            }
        }
        else
        {
            TI0n_PosOff=0;
            onflag=1;
            Port_CH2_Enable();
        }
    }
    else if(id==ChannelID2_Alt) 
    {
        if(Interface_GetLightChannelStateSwitch(ChannelID2) != CHANNEL_STATE_OFF) //需点亮日行CH2,但转向已打开，且位于CH2
        {
            Port_CH2Alt_Disable();
            if(TI0n_PosOff==0)
            {
                TI0n_PosOff=1;               
                Interface_ChannelClose(id);
            }
        }
        else
        {
            TI0n_PosOff=0;
            onflag=1;
            Port_CH2Alt_Enable();
        }
    }
    else 
    {
        onflag=1;
    }
    if(onflag==1)
    {
        if(Interface_GetLightChannelStateSwitch(id)==CHANNEL_STATE_OFF)
        {
            errcheckflag=0;
            Reset_ChannelAllError(id);
        }   
        Interface_ChannelOpen(id,cur,pwm);
    }
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
    Interface_ChannelClose(id);
}


//POS ON and OFF

Std_ReturnType POS_RunMainFun(void)
{
    uint16 lgmask=0,lgmask1=0;
    uint8 SwitchOnDRL=0,SwitchOnPOS=0;
    uint8 IntensityPosPerc=0,pwm=0,pwmramp=0;
    uint16 cur=0;
    E_ChannelID id=ChannelID1;
    U_E2EErrorFlag LB_E2EFlag;
    uint8 ntc_err=0,bin_err=0;
    static uint8 POSOffFlag=0;
    static uint8 SwitchOn_DRL=ACT_OFF;
    static uint8 errflag1=0,errflag2=0;/* POS max channel num is 2 */

    if((GetLgtStsEna_WELC()==1)||(GetLgtStsEna_GDY()==1))
    {
        errflag1=0;
        errflag2=0; 
        SetLgtStsFb_POS(STS_OFF);  
        return E_OK;
    }
    if(GetLgtStsEna_Charge()==1)
    { /* dyn pos */
        errflag1=0;
        errflag2=0; 
        return E_OK;
    }
    lgmask=GetChannelMaskByLightFunction(E_PositionLight);
    for(id=ChannelID1;id<CHANNEL_NUM;id++)
    {
        if(((lgmask>>id)&0x01)!=0) 
        {
            lgmask1=GetChannelMaskByLightFunction(E_DaytimeRunningLight);
            SwitchOnDRL=Lighting_GetAct(E_DaytimeRunningLight);
            SwitchOnPOS=Lighting_GetAct(E_PositionLight);
            if((((lgmask1>>id)&0x01)!=0)&&(SwitchOnDRL==ACT_ON)) 
            {      
                errflag1=0;
                errflag2=0;      
                if(SwitchOnPOS==ACT_ON)
                {  
                    SetLgtStsFb_POS(STS_ON);
                }
                else
                {
                    SetLgtStsFb_POS(STS_OFF);
                }
            }
            else
            {
#if APP_E2E_FUN
/* functionsafety mode */
                Rbk_U_E2EErrorFlag(&LB_E2EFlag);
                if((LB_E2EFlag.bits.ActnOfLedLoBeamCntErr==1)||(LB_E2EFlag.bits.ActnOfLedLoBeamCrcErr==1)||(LB_E2EFlag.bits.ActnOfLedLoBeamTimeout==1))
                {
                    if(((lgmask1>>id)&0x01)==0)
                    {
                        POS_On(id,pwm,cur);   
                    }
                    SetLgtStsFb_POS(STS_ON);
                }
                else
#endif
                {
/* normal mode */
                    if(SwitchOnPOS==ACT_ON)
                    {        
                        if((errflag1!=id)&&(errflag2!=id))
                        {
                            POSOffFlag=1;
                            pwm=Interface_GetSignal_ChannelPwm(id);
                            #if APP_E2E_FUN
                            pwmramp=100;
                            #else
                            pwmramp=Lighting_SetPwmRamp(E_PositionLight);
                            #endif
                            IntensityPosPerc=Get_pLedIntensityPos();
                            pwm=pwm*pwmramp*IntensityPosPerc/10000;
                            cur=Interface_GetSignal_ChannelCurrent(id); 
                            POS_On(id,pwm,cur);    
                        }                    
                    }
                    else
                    {
                        errflag1=0;
                        errflag2=0;                       
                        SetLgtStsFb_POS(STS_OFF);
                        lgmask1=GetChannelMaskByLightFunction(E_DaytimeRunningLight);
                        SwitchOn_DRL=Lighting_GetAct(E_DaytimeRunningLight);
    /* share channel : pos is on ,not close  */
                        if(((((lgmask1>>id)&0x01)==0) || (SwitchOn_DRL==ACT_OFF)) &&(POSOffFlag==1))
                        {
                            POS_Off(id);
                        }  
                    }     
                }  
            }
            if(SwitchOnPOS==ACT_ON)
            {
                ntc_err=Interface_GetChannelNtcError(id);
                bin_err=Interface_GetChannelBinError(id);
                Reset_ChannelLowVolError(id);/* when the channel off,don't check lowvoltage */
                if(((Interface_GetChannelState(id)&0xe7)==0)&&(errflag1!=id)&&(errflag2!=id))  //channel err
                {      
                    if((ntc_err!=0)||(bin_err!=0))  //ntc err or bin err
                    {
                        SetLgtStsFb_POS(STS_ERR);  
                    }
                    else if(GetLgtStsFb_POS()==0)    //no error
                    {
                        SetLgtStsFb_POS(STS_ON);
                    }   
                }
                else
                {
                    if(errcheckflag==1)
                    {
                        SetLgtStsFb_POS(STS_ERR); 
                        Interface_SetLightChannelStateSwitch(id,STS_ERR);
                        POS_Off(id);
                        if(errflag1==0)
                        {
                            errflag1=id;
                        }
                        else if(errflag1!=id)
                        {
                            errflag2=id;
                        }
                    }
                }  
                errcheckflag=1;
            }
            else
            {
                errcheckflag=0;
                SetLgtStsFb_POS(STS_OFF);
            }
        }
    }
    return E_OK;
}


