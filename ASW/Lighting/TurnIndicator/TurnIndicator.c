
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
static Std_ReturnType TI_On(E_ChannelID id)
{
    uint8 pwm=100,pwmramp=100;  
    uint16 cur=0; 
    if(id==ChannelID2)
    {
        if(Interface_GetLightChannelStateSwitch(ChannelID2_Alt)== CHANNEL_STATE_ON) 
        {
            Port_CH2Alt_Disable();
            Interface_ChannelClose(ChannelID2);
            Interface_ChannelClose(ChannelID2_Alt);
        }
        Port_CH2_Enable();
    }
    else if(id==ChannelID2_Alt) 
    {
        if(Interface_GetLightChannelStateSwitch(ChannelID2)== CHANNEL_STATE_ON) 
        {
            Port_CH2_Disable();
            Interface_ChannelClose(ChannelID2);
            Interface_ChannelClose(ChannelID2_Alt);
        }// wait pos drl close
        Port_CH2Alt_Enable();
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
    Interface_ChannelClose(id);
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
Std_ReturnType TI_RunMainFun(void)
{
    uint16 lgmask=0;
    uint8 TIsts=0,TIact=0;
    E_ChannelID id=ChannelID1;
    static uint8 TI_ErrStatus=0;  //0 LB=NO ERR
    uint8 ntc_err=0,bin_err=0;
    static uint8 TiDelayCnt=0;
    U_E2EErrorFlag TI_E2EFlag;
    if((GetLgtStsEna_WELC()==1)||(GetLgtStsEna_GDY()==1)||(GetLgtStsEna_Charge()==1))
    {
        SetLgtStsFb_Status(STS_OFF,E_TurnIndicator);  
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
            Rbk_U_E2EErrorFlag(&TI_E2EFlag);
            if(((TI_E2EFlag.bits.ActvnOfIndcrCntErr==1)||(TI_E2EFlag.bits.ActvnOfIndcrCrcErr==1)||(TI_E2EFlag.bits.ActvnOfIndcrTimeout==1)))
            {
                TI_Off(id);
                
                if(TIsts==ACT_ON)
                {/* when indicator on*/
                    SetLgtStsFb_Status(STS_ERR,E_TurnIndicator);
                    Interface_SetLightChannelStateSwitch(id,STS_ERR);
                }
                else
                {/* when indicator off */
                    SetLgtStsFb_Status(STS_OFF,E_TurnIndicator);
                    Interface_SetLightChannelStateSwitch(id,STS_OFF);
                }
            }
            else
#endif
            {
                if((TIsts==ACT_ON)&&(TIact==ACT_ON))
                {    
                    if(Interface_GetLightChannelStateSwitch(id)==CHANNEL_STATE_OFF)
                    {
                        Reset_ChannelAllError(id);
                    }
                    if(TI_ErrStatus==0)  
                    {
                        TI_On(id);                           
                        /*  */
                        ntc_err=Interface_GetChannelNtcError(id);
                        bin_err=Interface_GetChannelBinError(id);
                        if((ntc_err!=0)||(bin_err!=0))
                        {
                            SetLgtStsFb_Status(STS_ERR,E_TurnIndicator);  
                            SetDTCGroup_IND(DTC_Error);
                        }
                        else if(GetLgtStsFb(E_TurnIndicator)!=STS_ERR)
                        {
                            SetLgtStsFb_Status(STS_ON,E_TurnIndicator); 
                            SetDTCGroup_IND(DTC_Noerr);
                        }              
                    }   
                    else
                    {
                        SetLgtStsFb_Status(STS_ERR,E_TurnIndicator);
                        SetDTCGroup_IND(DTC_Error);
                        Interface_SetLightChannelStateSwitch(id,STS_ERR);
                    }
                }  
                else if((TIsts==ACT_ON)&&(TIact==ACT_OFF))
                {
                    if(TI_ErrStatus==0) 
                    {
                        TIOff_flag=1;
                        TI_Off(id);
                        Interface_SetLightChannelStateSwitch(id,STS_ON);
                        /*  */
                        ntc_err=Interface_GetChannelNtcError(id);
                        bin_err=Interface_GetChannelBinError(id);
                        if((ntc_err!=0)||(bin_err!=0))
                        {
                            SetLgtStsFb_Status(STS_ERR,E_TurnIndicator);  
                            SetDTCGroup_IND(DTC_Error);
                        }
                        else if(GetLgtStsFb(E_TurnIndicator)!=STS_ERR)
                        {
                            SetLgtStsFb_Status(STS_OFF,E_TurnIndicator);
                            SetDTCGroup_IND(DTC_Noerr);
                        }                         
                    }
                    else
                    {
                        SetLgtStsFb_Status(STS_ERR,E_TurnIndicator);
                        SetDTCGroup_IND(DTC_Error);
                        Interface_SetLightChannelStateSwitch(id,STS_ERR);
                    }               
                }
                else
                {       
                    TiDelayCnt=0;             
                    TI_ErrStatus=0;      
                    TI_Off(id);
                    SetLgtStsFb_Status(STS_OFF,E_TurnIndicator);
                } 
                if(TIsts==ACT_ON)
                {
                    if(Interface_GetChannelState(id)!=0)
                    {
                        TiDelayCnt++;
                        if(TiDelayCnt>=10)
                        {
                            TiDelayCnt=10;
                            TIOff_flag=1;
                            TI_Off(id); 
                            TI_ErrStatus=1; 
                            SetLgtStsFb_Status(STS_ERR,E_TurnIndicator);
                            SetDTCGroup_IND(DTC_Error);
                            Interface_SetLightChannelStateSwitch(id,STS_ERR);
                        }
                    }
                }
            }
        }
    }
    return E_OK;
}

