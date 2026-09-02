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
#include "LinManager.h"
#include "TurnIndicator.h"

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
    Interface_ChannelClose(id);
}


static void DRL_On(E_ChannelID id)
{
    uint8 pwmramp=0,pwmcur=0,pwmall=0;
    uint16 cur=0;
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
    static uint8 DRLerrflag1=0,DRLerrflag2=0,DRLerrflag3=0;/* DRL max channel num is 2 */
    static uint8 Error_N_1=0;

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
            SwitchOn_Drl=Lighting_GetAct(E_DaytimeRunningLight);
/* 日行 转向的共用发光面*/
            if((Get_DRL_TI_surfaces_apparent()>>id !=0)&&(ACT_OFF == Interface_Get_Channel_Surfaces_Apparent_Switch()))/* id为共通道&&转向打开 */
            {
                DRL_Off(id);
            }
            else if(SwitchOn_Drl==ACT_ON)
            {
                if(Error_N_1==0)
                {
                    if(Get_LightN_1(E_DaytimeRunningLight)&&((DRLerrflag1==id)||(DRLerrflag2==id)||(DRLerrflag3==id)))/* DRL参数表配了N-1 且其中一个通道发生故障*/
                    {
                        Error_N_1=1;
                    }
                    else if((DRLerrflag1!=id)&&(DRLerrflag2!=id)&&(DRLerrflag3!=id))/* 未发生故障 */
                    {
                        DRLOff_flag=1;
                        DRL_On(id);
                    }
                }
            }
            else
            {
                Error_N_1=0;
                DRLerrflag1=0;
                DRLerrflag2=0;
                DRLerrflag3=0;
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
 /* run the err function */           
            if(SwitchOn_Drl== ACT_ON) 
            {
                if(Error_N_1==1)
                {
                    DRL_Off(id);
                    SetLgtStsFb_Status(STS_ERR,E_DaytimeRunningLight);
                    SetDTCGroup_DRL(DTC_Error);
                }
                else
                {
                    ntc_err=Interface_GetChannelNtcError(id);
                    bin_err=Interface_GetChannelBinError(id);
                    if(((Interface_GetChannelState_Light(id)==0)&&(DRLerrflag1!=id)&&(DRLerrflag2!=id)&&(DRLerrflag3!=id)))  //channel err
                    {      
                        if(((ntc_err!=0)||(bin_err!=0)) ) //ntc err or bin err
                        {
                            SetLgtStsFb_Status(STS_ERR,E_DaytimeRunningLight);
                            SetDTCGroup_DRL(DTC_Error);
                        }
                        else 
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
                            if(DRLerrflag1==0)/* channel always used to lowbeam */
                            {
                                DRLerrflag1=id;
                            }
                            else if((DRLerrflag1!=id)&&(DRLerrflag2==0))
                            {
                                DRLerrflag2=id;
                            }
                            else if((DRLerrflag1!=id)&&(DRLerrflag2!=id)&&(DRLerrflag3==0))
                            {
                                DRLerrflag3=id;
                            }
                        }
                    }  
                    errcheckflag=1;
                }
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

