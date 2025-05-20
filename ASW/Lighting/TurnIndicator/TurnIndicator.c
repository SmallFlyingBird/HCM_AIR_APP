
#include "HcmPlatform.h"
#include "TurnIndicator.h"
#include "Lighting.h"
#include "Buck_Interface.h"
#include "Channel_Interface.h"
#include "Dio_Service.h"
#include "Parameter_Interface.h"
#include "DTC_Interface.h"
#include "LinManager.h"
#include "NtcRcod_Interface.h"
#include "PduR_Callout.h"

#define TI_ERR_DELAY    20

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
            Interface_ChannelClose(ChannelID2);
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
            Interface_ChannelClose(ChannelID2_Alt);
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
Std_ReturnType TI_RunMainFun(uint16 *sts)
{
    uint16 lgmask=0;
    uint8 TIsts=0,TIact=0;
    E_ChannelID id=ChannelID1;
    U_ChannelErrorState err;
    static uint8 TI_ErrStatus=0;  //0 LB=NO ERR
    uint8 ntc_err=0,bin_err=0;
    static uint8 TiDelayCnt=0;
    if((GetLgtStsEna_WELC()==1)||(GetLgtStsEna_GDY()==1)||(GetLgtStsEna_Charge()==1))
    {
        SetLgtStsFb_TI(STS_OFF);  
        return E_OK;
    }
    lgmask=GetChannelMaskByLightFunction(E_TurnIndicator);
    for(id=ChannelID1;id<CHANNEL_NUM;id++)
    {
        if(((lgmask>>id)&0x01)!=0) 
        {
            TIsts=Lighting_GetLinCtrl(E_TurnIndicator);
            TIact=Lighting_GetLinCtrl(E_TurnIndicator_Act);
            if(AIR_437C_Direction_RIGHT == PduR_GetLightSide())
            {/* Right side */
                TIsts=(TIsts&0x02)>>1;
                TIact=(TIact&0x02)>>1;
            }
            else
            {
                TIsts=TIsts&0x01;
                TIact=TIact&0x01;
            }
            /* functionsafety mode */
#if APP_E2E_FUN
            TI_E2EFlag=Rbk_U_E2EErrorFlag();
            if((TIsts==ACT_ON)&&((TI_E2EFlag.bits.ActvnOfIndcrCntErr==1)||(TI_E2EFlag.bits.ActvnOfIndcrCrcErr==1)||(TI_E2EFlag.bits.ActvnOfIndcrTimeout==1)))
            {
                sts[id] |= E_TI;
                TI_Off(id);
                SetLgtStsFb_TI(STS_ERR);
            }
            else
#endif
            {
                if((TIsts==ACT_ON)&&(TIact==ACT_ON))
                {    
                    if(TI_ErrStatus==0)  
                    {
                        sts[id] |= E_TI; //CH1 CH1_Tap is one channel  
                        TI_On(id,sts);                           
                        /*  */
                        ntc_err=Interface_GetChannelNtcError(id);
                        bin_err=Interface_GetChannelBinError(id);
                        if((ntc_err!=0)||(bin_err!=0))
                        {
                            SetLgtStsFb_TI(STS_ERR);  
                        }
                        else if(GetLgtStsFb_TI()!=STS_ERR)
                        {
                            SetLgtStsFb_TI(STS_ON); 
                        }              
                    }   
                    else
                    {
                        SetLgtStsFb_TI(STS_ERR);
                    }
                }  
                else if((TIsts==ACT_ON)&&(TIact==ACT_OFF))
                {
                    if(TI_ErrStatus==0) 
                    {
                        sts[id] |= E_TI; //CH1 CH1_Tap is one channel 
                        TIOff_flag=1;
                        TI_Off(id);
                        /*  */
                        ntc_err=Interface_GetChannelNtcError(id);
                        bin_err=Interface_GetChannelBinError(id);
                        if((ntc_err!=0)||(bin_err!=0))
                        {
                            SetLgtStsFb_TI(STS_ERR);  
                        }
                        else if(GetLgtStsFb_TI()!=STS_ERR)
                        {
                            SetLgtStsFb_TI(STS_OFF);
                        }                         
                    }
                    else
                    {
                        SetLgtStsFb_TI(STS_ERR);
                    }               
                }
                else
                {       
                    TiDelayCnt=0;             
                    TI_ErrStatus=0;      
                    sts[id] &= (~E_TI); 
                    TI_Off(id);
                    Reset_ChannelLowVolError(id);/* when the channel off,don't check lowvoltage */
                    SetLgtStsFb_TI(STS_OFF);
                } 
                if((sts[id] &E_TI)!=0)
                {
                    err=Interface_GetChannelState(id);

                    if(err.Error!=0)
                    {
                        TiDelayCnt++;
                        if(TiDelayCnt>=10)
                        {
                            TiDelayCnt=10;
                            TIOff_flag=1;
                            TI_Off(id); 
                            TI_ErrStatus=1; 
                            SetLgtStsFb_TI(STS_ERR);
                        }
                    }
                }
            }
        }
    }
    return E_OK;
}

