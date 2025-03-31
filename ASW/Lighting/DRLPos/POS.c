#include "HcmPlatform.h"
#include "POS.h"
#include "Buck_Interface.h"
#include "Channel_Interface.h"
#include "Dio_Service.h"
#include "Lighting.h"
#include "Parameter_Interface.h"
#include "DTC_Interface.h"
#include "NtcRcod_Interface.h"

uint16 POS_On(E_ChannelID id,uint16 *sts,uint8 pwm,uint16 cur)
{
    uint16 drl_sts=0;   
    static uint8 TI0n_PosOff=0;
    uint8 ntc_err=0,bin_err=0;
    if(id==ChannelID2)
    {
        if((sts[ChannelID2_Alt]&E_TI)!=0)//需点亮位置CH2,但转向已打开且位于CH2_Alt
        {
            Port_CH2_Disable();
            sts[id]&= (~E_POS);
            if(TI0n_PosOff==0)
            {
                TI0n_PosOff=1;               
                Interface_ChannelClose(id);
            }
        }
        else
        {
            Port_CH2_Enable(0);
            sts[id] |=E_POS; 
        }
    }
    else if(id==ChannelID2_Alt) 
    {
        if((sts[ChannelID2_Alt]&E_TI)!=0)//需点亮日行CH2,但转向已打开，且位于CH2
        {
            Port_CH2Alt_Disable();
            sts[id]&= (~E_POS);
            if(TI0n_PosOff==0)
            {
                TI0n_PosOff=1;               
                Interface_ChannelClose(id);
            }
        }
        else
        {
            Port_CH2Alt_Enable(0);
            sts[id]|=E_POS;
        }
    }
    else 
    {
        sts[id] |=E_POS; 
    }
    if((sts[id]&E_POS)!=0)
    {
        TI0n_PosOff=0;
        Interface_ChannelOpen(id,cur,pwm);
        Reset_ChannelShort2VCC(id);
        ntc_err=Interface_GetChannelNtcError(id);
        bin_err=Interface_GetChannelBinError(id);
        if((ntc_err!=0)||(bin_err!=0))
        {
            SetLgtStsFb_POS(STS_ERR);  
        }
        else if(GetLgtStsFb_POS()!=STS_ERR)
        {
            SetLgtStsFb_POS(STS_ON);
        }
    }
    else
    {
        SetLgtStsFb_POS(STS_OFF);
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
Std_ReturnType POS_RunMainFun(uint16 *sts)
{
    uint16 lgmask=0,lgmask1=0;
    uint8 SwitchOnDRL=0,SwitchOnPOS=0;
    // U_ChannelErrorState err;
    uint8 IntensityPosPerc=0,pwm=0,pwmramp=0;
    uint16 cur=0;
    E_ChannelID id=ChannelID1;
    U_E2EErrorFlag LB_E2EFlag;
    if((GetLgtStsEna_WELC()==1)||(GetLgtStsEna_GDY()==1))
    {
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
                sts[id]&= (~E_POS);  //the channel DRL on
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
                LB_E2EFlag=Rbk_U_E2EErrorFlag();
                if((LB_E2EFlag.bits.ActnOfLedLoBeamCntErr==1)||(LB_E2EFlag.bits.ActnOfLedLoBeamCrcErr==1)||(LB_E2EFlag.bits.ActnOfLedLoBeamTimeout==1))
                {
                    if(((lgmask1>>id)&0x01)==0)
                    {
                        POS_On(id,sts,pwm,cur);   
                    }
                    SetLgtStsFb_POS(STS_ON);
                }
                else
#endif
                {
/* normal mode */
                    if(SwitchOnPOS==ACT_ON)
                    {             
                        pwm=Interface_GetSignal_ChannelPwm(id);
                        #if APP_E2E_FUN
                        pwmramp=100;
                        #else
                        pwmramp=Lighting_SetPwmRamp(E_PositionLight);
                        #endif
                        IntensityPosPerc=Get_pLedIntensityPos();
                        pwm=pwm*pwmramp*IntensityPosPerc/10000;
                        cur=Interface_GetSignal_ChannelCurrent(id);    
                        POS_On(id,sts,pwm,cur);                   
                    }
                    else
                    {
                        sts[id]&= (~E_POS); 
                        POS_Off(id);
                        SetLgtStsFb_POS(STS_OFF);
                    }     
                }  
            }
        }
    }
    return E_OK;
}


