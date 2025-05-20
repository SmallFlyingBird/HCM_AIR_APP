#include "HcmPlatform.h"
#include "DRL.h"
#include "Buck_Interface.h"
#include "Channel_Interface.h"
#include "Dio_Service.h"
#include "Lighting.h"
#include "Parameter_Interface.h"
#include "DTC_Interface.h"
#include "LINManager.h"
#include "NtcRcod_Interface.h"
/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/

typedef struct Drl_Err_Status
{
    struct {  
    uint8 ch2err      :1;
    uint8 ch4err      :1;  
    uint8 rev         :6;        
    } bits;
    uint8 errsts;
} Drl_Err_Status;


typedef struct 
{
    Drl_Err_Status g_Drl_Status; 
    uint8 errdelaycnt;
}Drl_Status;
Drl_Status S_Drl_Status;
static uint8 DRLOff_flag=0;
/****************************************************************
 *                                                              *
 *                   Global Variable Define                     *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/

//close the drl
static void DRL_Off(E_ChannelID id)
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
    if(DRLOff_flag==1)
    {
        Interface_ChannelClose(id);
    }
}


static void DRL_On(E_ChannelID id,uint16 *sts)
{
    uint8 pwmramp=0,pwmcur=0,pwmall=0;
    uint16 cur=0;
    uint8 TI_Sts=0;
    U_ChannelErrorState err;
    static uint8 TI0n_DRLOff=0;
    uint8 ntc_err=0;//channel ntc err
    uint8 bin_err=0;
    if(id==ChannelID2)
    {      
/* can't open CH2,the TI is CH2_Alt */
        if((sts[ChannelID2_Alt]&E_TI)!=0)
        {
            Port_CH2_Disable();
            sts[id]&= (~E_DRL);
            if(TI0n_DRLOff==0)
            {
                TI0n_DRLOff=1;               
                Interface_ChannelClose(id);
            }
        }
        else
        {
            Port_CH2_Enable(S_Drl_Status.g_Drl_Status.bits.ch2err);
            sts[id]|=E_DRL; 
        }
    }
    else if(id==ChannelID2_Alt) 
    {
/* drl is CH2_ALT ON,but TI is CH2 ON */
        if((sts[ChannelID2]&E_TI)!=0)
        {
            Port_CH2Alt_Disable();
            sts[id]&= (~E_DRL);
            if(TI0n_DRLOff==0)
            {
                TI0n_DRLOff=1;
                Interface_ChannelClose(id);
            }              
        }
        else
        {
            Port_CH2Alt_Enable(S_Drl_Status.g_Drl_Status.bits.ch2err);
            sts[id] |=E_DRL; 
        }
    }
    else
    {
        sts[id]|=E_DRL; 
    }
    if((sts[id]&E_DRL)!=0)
    {
        TI0n_DRLOff=0;
        DRLOff_flag=1;
        cur=Interface_GetSignal_ChannelCurrent(id);
#if APP_E2E_FUN
        pwmramp=100;
#else
        pwmramp=Lighting_SetPwmRamp(E_DaytimeRunningLight);
#endif
        pwmcur=Interface_GetSignal_ChannelPwm(id);
        pwmall=pwmramp*pwmcur/100;
        Interface_ChannelOpen(id,cur,pwmall);
    }

    err=Interface_GetChannelState(id);
    if((err.Error!=0) &&(pwmall==100)&&(Interface_GetChannelOnTime(id)>=10))
    {
        sts[id]&= (~E_DRL);
        DRL_Off(id);
        SetLgtStsFb_DRL(STS_ERR);    
        S_Drl_Status.g_Drl_Status.errsts=1;   
    }
    if(S_Drl_Status.g_Drl_Status.errsts==0)
    {
        if((sts[id]&E_DRL)!=0)
        {
            ntc_err=Interface_GetChannelNtcError(id);
            bin_err=Interface_GetChannelBinError(id);
            if((ntc_err!=0)||(bin_err!=0))
            {
                SetLgtStsFb_DRL(STS_ERR);  
            }
            else if(GetLgtStsFb_DRL()!=STS_ERR)
            {
                SetLgtStsFb_DRL(STS_ON);
            }
        }
        else 
        {
            SetLgtStsFb_DRL(STS_OFF);
        }
    }
}


/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
//DRL ON and OFF
Std_ReturnType DRL_RunMainFun(uint16 *sts)
{
    uint16 lgmask=0,lgmask1=0,lgmaskTi=0;
    uint8 SwitchOn_Drl=0,SwitchOn_pos=0;
    uint8 stsreadback=0;
    E_ChannelID id=ChannelID1;
    U_E2EErrorFlag LB_E2EFlag;
    if((GetLgtStsEna_WELC()==1)||(GetLgtStsEna_GDY()==1)||(GetLgtStsEna_Charge()==1))
    {
        SetLgtStsFb_DRL(STS_OFF);  
        return E_OK;
    }

    lgmask=GetChannelMaskByLightFunction(E_DaytimeRunningLight);
    lgmaskTi=GetChannelMaskByLightFunction(E_TurnIndicator);
    for(id=ChannelID1;id<CHANNEL_NUM;id++)
    {
        if(((lgmask>>id)&0x01)!=0) 
        {
#if APP_E2E_FUN
/* functionsafety mode */
            LB_E2EFlag=Rbk_U_E2EErrorFlag();
            if((LB_E2EFlag.bits.ActnOfLedLoBeamCntErr==1)||(LB_E2EFlag.bits.ActnOfLedLoBeamCrcErr==1)||(LB_E2EFlag.bits.ActnOfLedLoBeamTimeout==1))
            {
                sts[id] |=E_DRL; //CH1 CH1_Tap
                DRL_On(id,sts);
                SetLgtStsFb_DRL(STS_ON);
            }
            else
#endif
            {
                SwitchOn_Drl=Lighting_GetAct(E_DaytimeRunningLight);
                if(SwitchOn_Drl==ACT_ON)
                {
                    DRL_On(id,sts);
                }
                else
                {
                    sts[id]&= (~E_DRL); 
                    S_Drl_Status.g_Drl_Status.bits.ch2err=0; 
                    S_Drl_Status.g_Drl_Status.errsts=0;  //when close the DRL,err status =0;
                    lgmask1=GetChannelMaskByLightFunction(E_PositionLight);
                    SwitchOn_pos=Lighting_GetAct(E_PositionLight);
/* share channel : pos is on ,not close  */
                    if((((lgmask1>>id)&0x01)==0) || (SwitchOn_pos==ACT_OFF)) 
                    {
                        DRL_Off(id);
                    }     
                    SetLgtStsFb_DRL(STS_OFF);       
                }    
            }            
        }
    }
    return E_OK;
}


