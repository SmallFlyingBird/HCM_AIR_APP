#include "HcmPlatform.h"
#include "charge.h"
#include "Parameter_Interface.h"
#include "LinManager.h"
#include "Channel_Interface.h"
#include "Dio_Service.h"
#include "DTC_Interface.h"
#define CHARGE_TOTAL_TIME   3000     //charge total execute time  30s

pr_Charge_Group Light_Charge_To_Execute;   //
pr_Charge_Group Light_Charge_From_Parameter[10]; 


/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/
static Std_ReturnType Charge_Get_Parameter(void)
{
    const uint8 *p_Mode_LowBri_Parameter;
	const uint16 *p_OffTi_ConTi_UpBri_Parameter;
    uint16 Step=0;

    // IntensityPosPerc=Get_pLedIntensityPos();

    p_Mode_LowBri_Parameter=Get_Dynamic_Light_Function_pWelcomP1ModeLowBri_By_Group(Group3);
    p_OffTi_ConTi_UpBri_Parameter=Get_Dynamic_Light_Function_pWelcomP1OffTiConTiUpBri_By_Group(Group3);
    for(Step=step1;Step<=step10;Step++)
    {
        Light_Charge_From_Parameter[Step].pr_ChargeMode = (pr_ChargeMode_t)p_Mode_LowBri_Parameter[Step];
        if(Light_Charge_From_Parameter[Step].pr_ChargeMode == 0) //read finish
        {
            return E_OK;
        }
        Light_Charge_From_Parameter[Step].LowBriPrm = (p_Mode_LowBri_Parameter[Step + 10]);
        Light_Charge_From_Parameter[Step].OffsTiPm = (p_OffTi_ConTi_UpBri_Parameter[Step]);
        Light_Charge_From_Parameter[Step].ConTiPrm = (p_OffTi_ConTi_UpBri_Parameter[Step + 10]);
        Light_Charge_From_Parameter[Step].UpperBriPrm = (p_OffTi_ConTi_UpBri_Parameter[Step + 20]);
    }
    return E_OK;
}

//pos on
static uint16 Mode1_Gradual_On_Execute(E_ChannelID id,pr_ChargeStep_t step)
{
    uint16 cur=0;
    uint16 reval=0;
    uint8 upbriprm=0;
    if(id==ChannelID2)
    {
        Port_CH2_Enable(0);
        reval=E_POS; 
    }
    else if(id==ChannelID2_Alt) 
    {
        Port_CH2Alt_Enable(0);
        reval=E_POS; 
    }
    upbriprm=Light_Charge_From_Parameter[step].UpperBriPrm;
    cur=Interface_GetSignal_ChannelCurrent(id);
    if(upbriprm==0) upbriprm=1;
    Interface_ChannelOpen(id,cur,upbriprm);
    return reval; 
}

static uint16 Mode2_Gradual_On_Execute(E_ChannelID id,uint16 time,pr_ChargeStep_t step)
{
    uint16 reval=0;
    float slop=0;
    uint8 upbriprm=0;
    uint16 cur=0;

    slop=(Light_Charge_From_Parameter[step].UpperBriPrm-Light_Charge_From_Parameter[step].LowBriPrm)*1.0/ \
        (Light_Charge_From_Parameter[step].ConTiPrm-Light_Charge_From_Parameter[step].OffsTiPm);
    if(id==ChannelID2)
    {
        Port_CH2_Enable(0);
        reval=E_POS; 
    }
    else if(id==ChannelID2_Alt) 
    {
        Port_CH2Alt_Enable(0);
        reval=E_POS; 
    }
    upbriprm=slop*(time-Light_Charge_From_Parameter[step].OffsTiPm);
    if(upbriprm<=Light_Charge_From_Parameter[step].UpperBriPrm)
    {
        cur=Interface_GetSignal_ChannelCurrent(id); //get current
        if(upbriprm==0) upbriprm=1;
        Interface_ChannelOpen(id,cur,upbriprm);
    }
    return reval;
}

static uint16 Mode3_Gradual_On_Execute(E_ChannelID id,uint16 time,pr_ChargeStep_t step)
{
    uint16 reval=0;
    float slop=0;
    uint8 upbriprm=0;
    uint16 cur=0;
    
    slop=(Light_Charge_From_Parameter[step].UpperBriPrm-Light_Charge_From_Parameter[step].LowBriPrm)*1.0/ \
        (Light_Charge_From_Parameter[step].ConTiPrm-Light_Charge_From_Parameter[step].OffsTiPm);
    if(id==ChannelID2)
    {
        Port_CH2_Enable(0);
        reval=E_POS; 
    }
    else if(id==ChannelID2_Alt) 
    {
        Port_CH2Alt_Enable(0);
        reval=E_POS; 
    }
    upbriprm=Light_Charge_From_Parameter[step].UpperBriPrm-slop*(time-Light_Charge_From_Parameter[step].OffsTiPm);
    if(upbriprm<=Light_Charge_From_Parameter[step].UpperBriPrm)
    {
        cur=Interface_GetSignal_ChannelCurrent(id); //get current
        if(upbriprm==0) upbriprm=1;
        Interface_ChannelOpen(id,cur,upbriprm);
    }
    return reval; 
}
/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
void Charge_Init(void)
{
    Charge_Get_Parameter();
}

Std_ReturnType Charge_MainFunction(uint16 *sts,uint8 timebase)
{
    uint16 lgmask=0;    
    uint8 Pos_Dyn_Ena=0,TI_Sts=0,Drl_Ena=0,Pos_Ena=0;
    static pr_ChargeStep_t Step=step1;
    static pr_ChargeMode_t Mode=mode_none;
    static uint16 Mode_Time=0;  /* mode execute time */
    Std_ReturnType reval=E_OK;
    static uint8 ModeTime_AddFlag=0;
    static uint8 posdyn_pre=0; //the last pos dyn status,if on,close the pos
    E_ChannelID id=ChannelID1;
    static uint8 ChargeRunFirst=0;
    static uint8 posdynstart=0;
    static uint8 TICutInFlag=0;

    Pos_Dyn_Ena=Interface_GetSignal_PosnLampDyn();
    if(Pos_Dyn_Ena==0)
    {
        posdynstart=0;
        TICutInFlag=0;
    }
    if(TICutInFlag==1) 
        return reval;

    lgmask=GetChannelMaskByLightFunction(E_PositionLight);
    for(id=ChannelID1;id<CHANNEL_NUM;id++)
    {
        if(((lgmask>>id)&0x01)!=0) 
        {
    /* get lin signal */               
            TI_Sts = Lighting_GetLinCtrl(E_TurnIndicator);
            Drl_Ena = Lighting_GetLinCtrl(E_DaytimeRunningLight);
            Pos_Ena = Lighting_GetLinCtrl(E_PositionLight);
            #ifdef LeftAir
            TI_Sts&=0x01;
            #endif

            #ifdef RightAir
            TI_Sts=(TI_Sts>>1)&0x01;
            #endif
            if((TI_Sts==0)&&(Drl_Ena==0)&&(Pos_Ena==0))
            {
                Reset_ChannelErrorCnt(id);
                if(ChargeRunFirst==0)//wait TI CLOSE
                {
                    ChargeRunFirst=1;
                    reval=E_OK; 
                    return reval; 
                }
                if(Pos_Dyn_Ena!=0)
                {
                    posdynstart=1;
                    Mode=Light_Charge_From_Parameter[Step].pr_ChargeMode;
                    sts[id]|=E_POS;
                    posdyn_pre=1;
                    
                    if(Mode==0) 
                    {
                        Step=step1;
                        Mode=Light_Charge_From_Parameter[step1].pr_ChargeMode;
                    }
                    if(ModeTime_AddFlag==0) 
                    {
                        ModeTime_AddFlag=(lgmask>>id);
                        Mode_Time+=timebase;
                    }
                    else if(ModeTime_AddFlag==(lgmask>>id))
                    {
                        Mode_Time+=timebase; //every timebase only add once
                    }
                    switch (Mode)
                    {
                    case mode1:               
                        if(Mode_Time>=Light_Charge_From_Parameter[Step].OffsTiPm) //delay the off time 
                        {
                            Mode1_Gradual_On_Execute(id,Step);//mode1 run
                        }
                        if(Mode_Time>=Light_Charge_From_Parameter[Step].ConTiPrm)
                        {
                            Mode_Time=0;
                            Step++;
                        }
                    break;
                    case mode2:                
                        if(Mode_Time>=Light_Charge_From_Parameter[Step].OffsTiPm) //delay the off time 
                        {
                            Mode2_Gradual_On_Execute(id,Mode_Time,Step);//mode2 run
                        }
                        else
                        {
                            Interface_ChannelOpen(id,0,0);
                        }
                        if(Mode_Time>=Light_Charge_From_Parameter[Step].ConTiPrm)
                        {
                            Mode_Time=0;
                            Step++;
                        }
                    break;
                    case mode3:
                        if(Mode_Time>=Light_Charge_From_Parameter[Step].OffsTiPm) //delay the off time 
                        {
                            Mode3_Gradual_On_Execute(id,Mode_Time,Step);
                        }
                        if(Mode_Time>=Light_Charge_From_Parameter[Step].ConTiPrm)
                        {
                            Mode_Time=0;
                            Step++;
                        }
                    break;
                    default:
                    break;
                    }  
                    reval=E_NOT_OK; 
                }
                else
                {
                    sts[id]&=~E_POS;
                    Mode_Time=0;
                    Step=step1;
                    if(posdyn_pre==1)
                    {
                        posdyn_pre=0;
                        sts[id]&=~E_POS;
                        Port_CH2_Disable();
                        Interface_ChannelClose(id);
                        reval=E_NOT_OK; 
                    }
                }
            }
            else 
            {     
                if((posdynstart==1)&&(TI_Sts!=0)) //posdyn run ,cut in by TI,don't run again
                {
                    posdynstart=0;
                    TICutInFlag=1;
                }
                ChargeRunFirst=0;       
                Mode_Time=0;
                Step=step1;
                if(posdyn_pre==1)
                {
                    posdyn_pre=0;                   
                    sts[id]&=~E_POS;
                    Interface_ChannelClose(id);
                    Port_CH2_Disable();
                    if((id==ChannelID2)||(id==ChannelID2_Alt))
                    {
                        Reset_ChannelErrorCnt(ChannelID2);
                        Reset_ChannelErrorCnt(ChannelID2_Alt);
                    }
                    else
                    {
                        Reset_ChannelErrorCnt(id);
                    }
                    reval=E_NOT_OK;                    
                }
            }
    /* analysis the charge status */
            if((sts[id] &E_POS)!=0) 
            {
                SetLgtStsFb_POS(STS_ON);
            }
            else 
            {
                SetLgtStsFb_POS(STS_OFF);
            }
        }
    }
    return reval; 
}







