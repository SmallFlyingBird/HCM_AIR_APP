#include "HcmPlatform.h"
#include "POS.h"
#include "Buck_Interface.h"
#include "Channel_Interface.h"
#include "Dio_Service.h"
#include "Lighting.h"
#include "Parameter_Interface.h"
#include "DTC_Interface.h"
#include "NtcRcod_Interface.h"
#include "LinManager.h"
#include "TurnIndicator.h"
static uint8 errcheckflag=0;

void POS_On(E_ChannelID id,uint8 pwm,uint16 cur)
{
    Interface_ChannelOpen(id,cur,pwm);
}

//close the pos
void POS_Off(E_ChannelID id)
{
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
    // static uint8 POSOffFlag=0;
    static uint8 SwitchOn_DRL=ACT_OFF;
    static uint8 errflag1=0,errflag2=0,errflag3=0;/* POS max channel num is 2 */
    static uint8 Error_N_1=0;

    if((GetLgtStsEna_WELC()==1)||(GetLgtStsEna_GDY()==1))
    {
        errflag1=0;
        errflag2=0; 
        errflag3=0; 
        SetLgtStsFb_Status(STS_OFF,E_PositionLight);  
        return E_OK;
    }
    if(GetLgtStsEna_Charge()==1)
    { /* dyn pos */
        errflag1=0;
        errflag2=0; 
        errflag3=0; 
        return E_OK;
    }
    lgmask=GetChannelMaskByLightFunction(E_PositionLight);
    for(id=ChannelID1;id<CHANNEL_NUM;id++)
    {
        if(((lgmask>>id)&0x01)!=0) 
        {
#if APP_E2E_FUN
/* functionsafety mode */
            // if(Get_E2E_Status() == 1)
            // {
                Rbk_U_E2EErrorFlag(&LB_E2EFlag);
                if((LB_E2EFlag.bits.ActnOfLedLoBeamCntErr==1)||(LB_E2EFlag.bits.ActnOfLedLoBeamCrcErr==1)||(LB_E2EFlag.bits.ActnOfLedLoBeamTimeout==1))
                {
                    cur = Interface_GetSignal_ChannelCurrent(id);
                    /* pos 14% */
                    POS_On(id,14,cur);   
                    SetLgtStsFb_Status(STS_ON,E_PositionLight);
                    continue;
                }
            // }
#endif
            lgmask1=GetChannelMaskByLightFunction(E_DaytimeRunningLight);
            SwitchOnDRL=Lighting_GetAct(E_DaytimeRunningLight);
            SwitchOnPOS=Lighting_GetAct(E_PositionLight);
/* 日行 转向的共用发光面*/
            if((Get_POS_TI_surfaces_apparent()>>id !=0)&&(ACT_OFF == Interface_Get_Channel_Surfaces_Apparent_Switch()))/* id为共通道&&转向打开 */
            {
                POS_Off(id);
            }
            else if((((lgmask1>>id)&0x01)!=0)&&(SwitchOnDRL==ACT_ON)) 
            {      
                errflag1=0;
                errflag2=0;   
                errflag3=0;    
                if(SwitchOnPOS==ACT_ON)
                {  
                    SetLgtStsFb_Status(STS_ON,E_PositionLight);
                }
                else
                {
                    SetLgtStsFb_Status(STS_OFF,E_PositionLight);
                }
            }
            else
            {
/* normal mode */
                if(SwitchOnPOS==ACT_ON)
                {        
                    if(Error_N_1==0)
                    {
                        if(Get_LightN_1(E_PositionLight)&&((errflag1==id)||(errflag2==id)||(errflag3==id)))/* DRL参数表配了N-1 且其中一个通道发生故障*/
                        {
                            Error_N_1=1;
                        }
                        else if((errflag1!=id)&&(errflag2!=id)&&(errflag3!=id))
                        {

                            pwm=Interface_GetSignal_ChannelPwm(id);
                            pwmramp=Lighting_SetPwmRamp(E_PositionLight);
                            IntensityPosPerc=Get_pLedIntensityPos();
                            pwm=pwm*pwmramp*IntensityPosPerc/10000;
                            cur=Interface_GetSignal_ChannelCurrent(id); 
                            POS_On(id,pwm,cur);    
                        }    
                    }                
                }
                else
                {
                    Error_N_1=0;
                    errflag1=0;
                    errflag2=0;
                    errflag3=0;                        
                    SetLgtStsFb_Status(STS_OFF,E_PositionLight);
                    lgmask1=GetChannelMaskByLightFunction(E_DaytimeRunningLight);
                    SwitchOn_DRL=Lighting_GetAct(E_DaytimeRunningLight);
/* share channel : pos is on ,not close  */
                    if((((lgmask1>>id)&0x01)==0) || (SwitchOn_DRL==ACT_OFF)) 
                    {
                        POS_Off(id);
                    }  
                }     
            }
            if(SwitchOnPOS==ACT_ON)
            {
                if(Error_N_1==1)
                {
                    POS_Off(id);
                    SetLgtStsFb_Status(STS_ERR,E_PositionLight);  
                    SetDTCGroup_POS(DTC_Error);
                }
                else
                {
                    ntc_err=Interface_GetChannelNtcError(id);
                    bin_err=Interface_GetChannelBinError(id);
                    Reset_ChannelLowVolError(id);/* when the channel off,don't check lowvoltage */
                    if(((Interface_GetChannelState_Light(id)&0xe7)==0)&&(errflag1!=id)&&(errflag2!=id)&&(errflag3!=id))  //channel err
                    {      
                        if((ntc_err!=0)||(bin_err!=0))  //ntc err or bin err
                        {
                            SetLgtStsFb_Status(STS_ERR,E_PositionLight);  
                            SetDTCGroup_POS(DTC_Error);
                        }
                        else
                        {
                            SetLgtStsFb_Status(STS_ON,E_PositionLight);
                            SetDTCGroup_POS(DTC_Noerr);
                        }   
                    }
                    else
                    {
                        if(errcheckflag==1)
                        {
                            SetLgtStsFb_Status(STS_ERR,E_PositionLight); 
                            SetDTCGroup_POS(DTC_Error);
                            Interface_SetLightChannelStateSwitch(id,STS_ERR);
                            POS_Off(id);
                            if(errflag1==0)/* channel always used to lowbeam */
                            {
                                errflag1=id;
                            }
                            else if((errflag1!=id)&&(errflag2==0))
                            {
                                errflag2=id;
                            }
                            else if((errflag1!=id)&&(errflag2!=id)&&(errflag3==0))
                            {
                                errflag3=id;
                            }
                        }
                    }  
                    errcheckflag=1;
                }
            }
            else
            {
                errcheckflag=0;
                SetLgtStsFb_Status(STS_OFF,E_PositionLight);
            }
        }
    }
    return E_OK;
}


