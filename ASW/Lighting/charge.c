#include "HcmPlatform.h"
#include "charge.h"
#include "Parameter_Interface.h"
#include "LinManager.h"
#include "Channel_Interface.h"
#include "Dio_Service.h"
#include "DTC_Interface.h"
#include "Pwm_Service.h"

#define CHARGE_TOTAL_TIME   3000     //charge total execute time  30s

#define STEP_MAXNUM    10
#define GROUP_MAXNUM   8

pr_Charge_Group Light_Charge_From_Parameter[GROUP_MAXNUM][STEP_MAXNUM]; 

#define DYN_OFF  0
#define DYN_ON   1
/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/
/******************************************************Get Parameter************************************************************/
static Std_ReturnType Group3_Welcome1_Get_Parameter(void)
{
    const uint8 *p_Mode_LowBri_Parameter;
	const uint16 *p_OffTi_ConTi_UpBri_Parameter;
    uint16 Step=0;

    // IntensityPosPerc=Get_pLedIntensityPos();

    p_Mode_LowBri_Parameter=Get_Dynamic_Light_Function_pWelcomP1ModeLowBri_By_Group(Group3);
    p_OffTi_ConTi_UpBri_Parameter=Get_Dynamic_Light_Function_pWelcomP1OffTiConTiUpBri_By_Group(Group3);
    for(Step=step1;Step<=step10;Step++)
    {
        Light_Charge_From_Parameter[Group3][Step].pr_ChargeMode = (pr_ChargeMode_t)p_Mode_LowBri_Parameter[Step];
        if(Light_Charge_From_Parameter[Group3][Step].pr_ChargeMode == 0) //read finish
        {
            return E_OK;
        }
        Light_Charge_From_Parameter[Group3][Step].LowBriPrm = (p_Mode_LowBri_Parameter[Step + 10]);
        Light_Charge_From_Parameter[Group3][Step].OffsTiPm = (p_OffTi_ConTi_UpBri_Parameter[Step]);
        Light_Charge_From_Parameter[Group3][Step].ConTiPrm = (p_OffTi_ConTi_UpBri_Parameter[Step + 10]);
        Light_Charge_From_Parameter[Group3][Step].UpperBriPrm = (p_OffTi_ConTi_UpBri_Parameter[Step + 20]);
    }
    return E_OK;
}


/*
* Mode0  always off
* Mode1  always on
* Mode2  slowly on
* Mode3  slowly off
*/
/* **********************************************CH2 GROUP3*********************************************************** */
static uint16 Group3_Mode0_Gradual_On_Execute(void)
{
    uint16 cur=0;
    uint16 rbval=0;
    Port_CH2_Enable(0);
    rbval=E_POS;
    Interface_ChannelClose(ChannelID2);
    return rbval; 
}

static uint16 Group3_Mode1_Gradual_On_Execute(pr_ChargeStep_t step)
{
    uint16 cur=0;
    uint16 rbval=0;
    uint8 upbriprm=0;
    Port_CH2_Enable(0);
    rbval=E_POS; 
    upbriprm=Light_Charge_From_Parameter[Group3][step].UpperBriPrm;
    cur=Interface_GetSignal_ChannelCurrent(ChannelID2);
    if(upbriprm==0) upbriprm=1;
    Interface_ChannelOpen(ChannelID2,cur,upbriprm);
    return rbval; 
}

static uint16 Group3_Mode2_Gradual_On_Execute(uint16 time,pr_ChargeStep_t step)
{
    uint16 rbval=0;
    float slop=0;
    uint8 upbriprm=0;
    uint16 cur=0;

    slop=(Light_Charge_From_Parameter[Group3][step].UpperBriPrm-Light_Charge_From_Parameter[Group3][step].LowBriPrm)*1.0/ \
        (Light_Charge_From_Parameter[Group3][step].ConTiPrm-Light_Charge_From_Parameter[Group3][step].OffsTiPm);
    Port_CH2_Enable(0);
    rbval=E_POS; 
    upbriprm=slop*(time-Light_Charge_From_Parameter[Group3][step].OffsTiPm);
    if(upbriprm<=Light_Charge_From_Parameter[Group3][step].UpperBriPrm)
    {
        cur=Interface_GetSignal_ChannelCurrent(ChannelID2); //get current
        if(upbriprm==0) upbriprm=1;
        Interface_ChannelOpen(ChannelID2,cur,upbriprm);
    }
    return rbval;
}

static uint16 Group3_Mode3_Gradual_On_Execute(uint16 time,pr_ChargeStep_t step)
{
    uint16 rbval=0;
    float slop=0;
    uint8 upbriprm=0;
    uint16 cur=0;
    
    slop=(Light_Charge_From_Parameter[Group3][step].UpperBriPrm-Light_Charge_From_Parameter[Group3][step].LowBriPrm)*1.0/ \
        (Light_Charge_From_Parameter[Group3][step].ConTiPrm-Light_Charge_From_Parameter[Group3][step].OffsTiPm);
    Port_CH2_Enable(0);
    rbval=E_POS; 
    upbriprm=Light_Charge_From_Parameter[Group3][step].UpperBriPrm-slop*(time-Light_Charge_From_Parameter[Group3][step].OffsTiPm);
    if(upbriprm<=Light_Charge_From_Parameter[Group3][step].UpperBriPrm)
    {
        cur=Interface_GetSignal_ChannelCurrent(ChannelID2); //get current
        if(upbriprm==0) upbriprm=1;
        Interface_ChannelOpen(ChannelID2,cur,upbriprm);
    }
    return rbval; 
}

/****************************************************WELCOME GOODBYE************************************************************/
static void Group3_WelcomeGoodbye(uint8 start,uint8 timebase)
{
    static pr_ChargeStep_t Step=step1;
    static pr_ChargeMode_t Mode=mode0;
    static uint16 Mode_Time=0;  /* mode execute time */
    
    if(start==DYN_OFF)
    {
        Step=step1;
        Mode=mode0;
        Mode_Time=0; 
    }
    Mode=Light_Charge_From_Parameter[Group3][Step].pr_ChargeMode;   
    Mode_Time+=timebase; //every timebase only add once
    switch (Mode)
    {
    case mode0:
        if(Mode_Time>=Light_Charge_From_Parameter[Group3][Step].OffsTiPm) //delay the off time 
        {
            Group3_Mode0_Gradual_On_Execute();//mode2 run
        }
        if(Mode_Time>=Light_Charge_From_Parameter[Group3][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode1:               
        if(Mode_Time>=Light_Charge_From_Parameter[Group3][Step].OffsTiPm) //delay the off time 
        {
            Group3_Mode1_Gradual_On_Execute(Step);//mode1 run
        }
        if(Mode_Time>=Light_Charge_From_Parameter[Group3][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode2:                
        if(Mode_Time>=Light_Charge_From_Parameter[Group3][Step].OffsTiPm) //delay the off time 
        {
            Group3_Mode2_Gradual_On_Execute(Mode_Time,Step);//mode2 run
        }
        else
        {
            Interface_ChannelOpen(ChannelID2,0,0);
        }
        if(Mode_Time>=Light_Charge_From_Parameter[Group3][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode3:
        if(Mode_Time>=Light_Charge_From_Parameter[Group3][Step].OffsTiPm) //delay the off time 
        {
            Group3_Mode3_Gradual_On_Execute(Mode_Time,Step);
        }
        if(Mode_Time>=Light_Charge_From_Parameter[Group3][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    default:
        Step=step1;
        Mode=Light_Charge_From_Parameter[Group3][step1].pr_ChargeMode;
    break;
    }  
}


/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
Std_ReturnType DynLight_MainFunction(uint8 timebase)
{
    static uint8 flag_get_parameter=0;
    uint8 id=0;
    static uint8 FirstRunOrNot=0;
    if((GetLgtStsEna_WELC()==0)&&(GetLgtStsEna_GDY()==0))
    {
        if(flag_get_parameter!=0) //need to set all channel close
        {
            Pwm_CH1Tap_Disable();
            Port_CH2_Disable();  
            Port_CH2Alt_Disable();
            for(id=0;id<6;id++)
            {
                Interface_ChannelClose(id);
                Reset_ChannelShort2VCC(id);
            } 
        }
        flag_get_parameter=0;
        return E_NOT_OK;
    }
/* the first run in,need to close all light, set the status to off, and get the parameters */
    if(((GetLgtStsEna_WELC()==1)&&(flag_get_parameter!=1))||((GetLgtStsEna_GDY()==1)&&(flag_get_parameter!=2)))
    {
        FirstRunOrNot=DYN_OFF;
        Pwm_CH1Tap_Disable();
        Port_CH2_Disable();  
        Port_CH2Alt_Disable();
        for(id=0;id<6;id++)
        {
            Interface_ChannelClose(id);
        }
        
        SetLgtStsFb_LB  (STS_OFF); 
        SetLgtStsFb_TI  (STS_OFF); 
        SetLgtStsFb_POS (STS_OFF); 
        SetLgtStsFb_HB  (STS_OFF); 
        SetLgtStsFb_DRL (STS_OFF); 
        SetLgtStsFb_CORN(STS_OFF); 
        SetLgtStsFb_CROS(STS_OFF); 
        SetLgtStsFb_WELC(STS_OFF); 
        SetLgtStsFb_Fog (STS_OFF);

        if(flag_get_parameter!=1)         // 获取欢迎group 
        {
            flag_get_parameter=1;
            Group3_Welcome1_Get_Parameter();
        }
        else if(flag_get_parameter!=2)    // 获取欢送group 
        {  
            flag_get_parameter=2; 
        }
    }
/* clean the error cnt */
    for(id=0;id<6;id++)
    {
        Reset_ChannelShort2VCC(id);
    }
/* run the every group */
    Group3_WelcomeGoodbye(FirstRunOrNot,timebase);
    FirstRunOrNot=DYN_ON;
    return E_OK;
}



