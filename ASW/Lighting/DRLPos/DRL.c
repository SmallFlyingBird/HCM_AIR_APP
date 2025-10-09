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
static uint8 errcheckflag=0;
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
    Interface_ChannelClose(id);
}


static void DRL_On(E_ChannelID id)
{
    uint8 pwmramp=0,pwmcur=0,pwmall=0;
    uint16 cur=0;
    uint8 TI_Sts=0;
    static uint8 TI0n_DRLOff=0;
    static uint8 DRLerrflag=0;
    uint8 onflag=0;
    if(id==ChannelID2)             /* can't open CH2,the TI is CH2_Alt */
    {      
        if(Interface_GetLightChannelStateSwitch(ChannelID2_Alt) != CHANNEL_STATE_OFF) 
        {
            Port_CH2_Disable();
            if(TI0n_DRLOff==0)
            {
                TI0n_DRLOff=1;               
                Interface_ChannelClose(id);
            }
        }
        else
        {
            onflag=1;
            Port_CH2_Enable();
        }
    }
    else if(id==ChannelID2_Alt)     /* drl is CH2_ALT ON,but TI is CH2 ON */
    {
        if(Interface_GetLightChannelStateSwitch(ChannelID2) != CHANNEL_STATE_OFF) 
        {
            Port_CH2Alt_Disable();
            if(TI0n_DRLOff==0)
            {
                TI0n_DRLOff=1;
                Interface_ChannelClose(id);
            }              
        }
        else
        {
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
        onflag=0;
        TI0n_DRLOff=0;
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
}


/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
//DRL ON and OFF
Std_ReturnType DRL_RunMainFun(void)
{
    uint16 lgmask=0,lgmask1=0,lgmaskTi=0;
    uint8 SwitchOn_Drl=0;/* get from Lin */
    uint8 SwitchOn_pos=0;/* get from Lin */
    uint8 stsreadback=0;
    E_ChannelID id=ChannelID1;
    uint8 ntc_err=0;//channel ntc err
    uint8 bin_err=0;
    static uint8 DRLOff_flag=0;
    static uint8 DRLerrflag1=0,DRLerrflag2=0;/* DRL max channel num is 2 */

    if((GetLgtStsEna_WELC()==1)||(GetLgtStsEna_GDY()==1)||(GetLgtStsEna_Charge()==1))
    {
        SetLgtStsFb_Status(STS_OFF,E_DaytimeRunningLight);  
        return E_OK;
    }

    lgmask=GetChannelMaskByLightFunction(E_DaytimeRunningLight);
    lgmaskTi=GetChannelMaskByLightFunction(E_TurnIndicator);
    for(id=ChannelID1;id<CHANNEL_NUM;id++)
    {
        if(((lgmask>>id)&0x01)!=0) 
        {
            {
                SwitchOn_Drl=Lighting_GetAct(E_DaytimeRunningLight);
                if(SwitchOn_Drl==ACT_ON)
                {
                    if((DRLerrflag1!=id)&&(DRLerrflag2!=id))
                    {
                        DRLOff_flag=1;
                        if(Interface_GetLightChannelStateSwitch(id)==CHANNEL_STATE_OFF)
                        {
                            errcheckflag=0;
                            Reset_ChannelAllError(id);
                        }
                        DRL_On(id);
                    }
                }
                else
                {
                    DRLerrflag1=0;
                    DRLerrflag2=0;
                    lgmask1=GetChannelMaskByLightFunction(E_PositionLight);
                    SwitchOn_pos=Lighting_GetAct(E_PositionLight);
/* share channel : pos is on ,not close  */
                    if(((((lgmask1>>id)&0x01)==0) || (SwitchOn_pos==ACT_OFF)) &&(DRLOff_flag==1))
                    {
                        DRLOff_flag = 0;
                        DRL_Off(id);
                    }     
                    SetLgtStsFb_Status(STS_OFF,E_DaytimeRunningLight);       
                }    
            }    
 /* run the err function */           
            if(SwitchOn_Drl== ACT_ON) 
            {
                ntc_err=Interface_GetChannelNtcError(id);
                bin_err=Interface_GetChannelBinError(id);
                if((Interface_GetChannelState(id)==0)&&(DRLerrflag1!=id)&&(DRLerrflag2!=id))  //channel err
                {      
                    if(((ntc_err!=0)||(bin_err!=0)) ) //ntc err or bin err
                    {
                        SetLgtStsFb_Status(STS_ERR,E_DaytimeRunningLight);
                        SetDTCGroup_DRL(DTC_Error);
                    }
                    else if(GetLgtStsFb(E_DaytimeRunningLight)==0)    //no error
                    {
                        SetLgtStsFb_Status(STS_ON,E_DaytimeRunningLight);
                        SetDTCGroup_DRL(DTC_Noerr);
                    }   
                }
                else
                {
                    if(errcheckflag==1)
                    {
                        SetLgtStsFb_Status(STS_ERR,E_DaytimeRunningLight);
                        SetDTCGroup_DRL(DTC_Error);
                        Interface_SetLightChannelStateSwitch(id,STS_ERR); 
                        DRL_Off(id);
                        if(DRLerrflag1==0)
                        {
                            DRLerrflag1=id;
                        }
                        else if(DRLerrflag1!=id)
                        {
                            DRLerrflag2=id;
                        }
                    }
                }  
                errcheckflag=1;
            }
            else 
            {
                errcheckflag=0;
                SetLgtStsFb_Status(STS_OFF,E_DaytimeRunningLight);
            }
        }
    }
    return E_OK;
}

