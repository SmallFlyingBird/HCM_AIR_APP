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
/******************************************************Get All Group Parameter************************************************************/
static Std_ReturnType GroupWelcome1_Get_Parameter(void)
{
    const uint8 *p_Mode_LowBri_Parameter;
	const uint16 *p_OffTi_ConTi_UpBri_Parameter;
    uint16 Step=0;
    E_LED_Group_ID groupx=0;
    for(groupx=Group1;groupx<=Group8;groupx++)
    {
        p_Mode_LowBri_Parameter=Get_Dynamic_Light_Function_pWelcomP1ModeLowBri_By_Group(groupx);
        p_OffTi_ConTi_UpBri_Parameter=Get_Dynamic_Light_Function_pWelcomP1OffTiConTiUpBri_By_Group(groupx);
        for(Step=step1;Step<=step10;Step++)
        {
            Light_Charge_From_Parameter[groupx][Step].pr_ChargeMode = (pr_ChargeMode_t)p_Mode_LowBri_Parameter[Step];
            Light_Charge_From_Parameter[groupx][Step].LowBriPrm = (p_Mode_LowBri_Parameter[Step + 10]);
            Light_Charge_From_Parameter[groupx][Step].OffsTiPm = (p_OffTi_ConTi_UpBri_Parameter[Step]);
            Light_Charge_From_Parameter[groupx][Step].ConTiPrm = (p_OffTi_ConTi_UpBri_Parameter[Step + 10]);
            Light_Charge_From_Parameter[groupx][Step].UpperBriPrm = (p_OffTi_ConTi_UpBri_Parameter[Step + 20]);
        }
    }
    return E_OK;
}


/*
* Mode0  always off
* Mode1  always on
* Mode2  slowly on
* Mode3  slowly off
*/
/* **********************************************CH1 GROUP2*********************************************************** */
static void Group1_Mode0_Gradual_On_Execute(void)
{
    uint16 cur=0;
    Pwm_HLCtrl_Disable();
    Interface_ChannelClose(ChannelID1); 
}

static void Group1_Mode1_Gradual_On_Execute(pr_ChargeStep_t step)
{
    uint16 cur=0;
    uint8 upbriprm=0;
    Pwm_HLCtrl_Enable();
    upbriprm=Light_Charge_From_Parameter[Group1][step].UpperBriPrm;
    cur=Interface_GetSignal_ChannelCurrent(ChannelID1);
    if(upbriprm==0) upbriprm=1;
    Interface_ChannelOpen(ChannelID1,cur,upbriprm);
}

static void Group1_Mode2_Gradual_On_Execute(uint16 time,pr_ChargeStep_t step)
{
    float slop=0;
    uint8 upbriprm=0;
    uint16 cur=0;

    slop=(Light_Charge_From_Parameter[Group1][step].UpperBriPrm-Light_Charge_From_Parameter[Group1][step].LowBriPrm)*1.0/ \
        (Light_Charge_From_Parameter[Group1][step].ConTiPrm-Light_Charge_From_Parameter[Group1][step].OffsTiPm);
    Pwm_HLCtrl_Enable();
    upbriprm=slop*(time-Light_Charge_From_Parameter[Group1][step].OffsTiPm);
    if(upbriprm<=Light_Charge_From_Parameter[Group1][step].UpperBriPrm)
    {
        cur=Interface_GetSignal_ChannelCurrent(ChannelID1); //get current
        if(upbriprm==0) upbriprm=1;
        Interface_ChannelOpen(ChannelID1,cur,upbriprm);
    }
}

static void Group1_Mode3_Gradual_On_Execute(uint16 time,pr_ChargeStep_t step)
{
    float slop=0;
    uint8 upbriprm=0;
    uint16 cur=0;
    
    slop=(Light_Charge_From_Parameter[Group1][step].UpperBriPrm-Light_Charge_From_Parameter[Group1][step].LowBriPrm)*1.0/ \
        (Light_Charge_From_Parameter[Group1][step].ConTiPrm-Light_Charge_From_Parameter[Group1][step].OffsTiPm);
    Pwm_HLCtrl_Enable();
    upbriprm=Light_Charge_From_Parameter[Group1][step].UpperBriPrm-slop*(time-Light_Charge_From_Parameter[Group1][step].OffsTiPm);
    if(upbriprm<=Light_Charge_From_Parameter[Group1][step].UpperBriPrm)
    {
        cur=Interface_GetSignal_ChannelCurrent(ChannelID1); //get current
        if(upbriprm==0) upbriprm=1;
        Interface_ChannelOpen(ChannelID1,cur,upbriprm);
    }
}

/* **********************************************CH1' GROUP2*********************************************************** */
static void Group2_Mode0_Gradual_On_Execute(void)
{
    uint16 cur=0;
    
    Interface_ChannelClose(ChannelID1_Tap); 
}

static void Group2_Mode1_Gradual_On_Execute(pr_ChargeStep_t step)
{
    uint16 cur=0;
    uint8 upbriprm=0;
    upbriprm=Light_Charge_From_Parameter[Group2][step].UpperBriPrm;
    cur=Interface_GetSignal_ChannelCurrent(ChannelID1_Tap);
    if(upbriprm==0) upbriprm=1;
    Interface_ChannelOpen(ChannelID1_Tap,cur,upbriprm);
}

static void Group2_Mode2_Gradual_On_Execute(uint16 time,pr_ChargeStep_t step)
{
    float slop=0;
    uint8 upbriprm=0;
    uint16 cur=0;

    slop=(Light_Charge_From_Parameter[Group2][step].UpperBriPrm-Light_Charge_From_Parameter[Group2][step].LowBriPrm)*1.0/ \
        (Light_Charge_From_Parameter[Group2][step].ConTiPrm-Light_Charge_From_Parameter[Group2][step].OffsTiPm); 
    upbriprm=slop*(time-Light_Charge_From_Parameter[Group2][step].OffsTiPm);
    if(upbriprm<=Light_Charge_From_Parameter[Group2][step].UpperBriPrm)
    {
        cur=Interface_GetSignal_ChannelCurrent(ChannelID1_Tap); //get current
        if(upbriprm==0) upbriprm=1;
        Interface_ChannelOpen(ChannelID1_Tap,cur,upbriprm);
    }
}

static void Group2_Mode3_Gradual_On_Execute(uint16 time,pr_ChargeStep_t step)
{
    float slop=0;
    uint8 upbriprm=0;
    uint16 cur=0;
    
    slop=(Light_Charge_From_Parameter[Group2][step].UpperBriPrm-Light_Charge_From_Parameter[Group2][step].LowBriPrm)*1.0/ \
        (Light_Charge_From_Parameter[Group2][step].ConTiPrm-Light_Charge_From_Parameter[Group2][step].OffsTiPm);
    upbriprm=Light_Charge_From_Parameter[Group2][step].UpperBriPrm-slop*(time-Light_Charge_From_Parameter[Group2][step].OffsTiPm);
    if(upbriprm<=Light_Charge_From_Parameter[Group2][step].UpperBriPrm)
    {
        cur=Interface_GetSignal_ChannelCurrent(ChannelID1_Tap); //get current
        if(upbriprm==0) upbriprm=1;
        Interface_ChannelOpen(ChannelID1_Tap,cur,upbriprm);
    }
}
/* **********************************************CH2 GROUP3*********************************************************** */
static void Group3_Mode0_Gradual_On_Execute(void)
{
    uint16 cur=0;
    Port_CH2_Enable(0);
    Interface_ChannelClose(ChannelID2); 
}

static void Group3_Mode1_Gradual_On_Execute(pr_ChargeStep_t step)
{
    uint16 cur=0;
    uint8 upbriprm=0;
    Port_CH2_Enable(0); 
    upbriprm=Light_Charge_From_Parameter[Group3][step].UpperBriPrm;
    cur=Interface_GetSignal_ChannelCurrent(ChannelID2);
    if(upbriprm==0) upbriprm=1;
    Interface_ChannelOpen(ChannelID2,cur,upbriprm);
}

static void Group3_Mode2_Gradual_On_Execute(uint16 time,pr_ChargeStep_t step)
{
    float slop=0;
    uint8 upbriprm=0;
    uint16 cur=0;

    slop=(Light_Charge_From_Parameter[Group3][step].UpperBriPrm-Light_Charge_From_Parameter[Group3][step].LowBriPrm)*1.0/ \
        (Light_Charge_From_Parameter[Group3][step].ConTiPrm-Light_Charge_From_Parameter[Group3][step].OffsTiPm);
    Port_CH2_Enable(0); 
    upbriprm=slop*(time-Light_Charge_From_Parameter[Group3][step].OffsTiPm);
    if(upbriprm<=Light_Charge_From_Parameter[Group3][step].UpperBriPrm)
    {
        cur=Interface_GetSignal_ChannelCurrent(ChannelID2); //get current
        if(upbriprm==0) upbriprm=1;
        Interface_ChannelOpen(ChannelID2,cur,upbriprm);
    }
}

static void Group3_Mode3_Gradual_On_Execute(uint16 time,pr_ChargeStep_t step)
{
    float slop=0;
    uint8 upbriprm=0;
    uint16 cur=0;
    
    slop=(Light_Charge_From_Parameter[Group3][step].UpperBriPrm-Light_Charge_From_Parameter[Group3][step].LowBriPrm)*1.0/ \
        (Light_Charge_From_Parameter[Group3][step].ConTiPrm-Light_Charge_From_Parameter[Group3][step].OffsTiPm);
    Port_CH2_Enable(0);
    upbriprm=Light_Charge_From_Parameter[Group3][step].UpperBriPrm-slop*(time-Light_Charge_From_Parameter[Group3][step].OffsTiPm);
    if(upbriprm<=Light_Charge_From_Parameter[Group3][step].UpperBriPrm)
    {
        cur=Interface_GetSignal_ChannelCurrent(ChannelID2); //get current
        if(upbriprm==0) upbriprm=1;
        Interface_ChannelOpen(ChannelID2,cur,upbriprm);
    }
}

/* **********************************************CH2' GROUP4*********************************************************** */
static void Group4_Mode0_Gradual_On_Execute(void)
{
    uint16 cur=0;
    Port_CH2Alt_Enable(0);
    Interface_ChannelClose(ChannelID2); 
}

static void Group4_Mode1_Gradual_On_Execute(pr_ChargeStep_t step)
{
    uint16 cur=0;
    uint8 upbriprm=0;
    Port_CH2Alt_Enable(0); 
    upbriprm=Light_Charge_From_Parameter[Group4][step].UpperBriPrm;
    cur=Interface_GetSignal_ChannelCurrent(ChannelID2);
    if(upbriprm==0) upbriprm=1;
    Interface_ChannelOpen(ChannelID2,cur,upbriprm);
}

static void Group4_Mode2_Gradual_On_Execute(uint16 time,pr_ChargeStep_t step)
{
    float slop=0;
    uint8 upbriprm=0;
    uint16 cur=0;

    slop=(Light_Charge_From_Parameter[Group4][step].UpperBriPrm-Light_Charge_From_Parameter[Group4][step].LowBriPrm)*1.0/ \
        (Light_Charge_From_Parameter[Group4][step].ConTiPrm-Light_Charge_From_Parameter[Group4][step].OffsTiPm);
    Port_CH2Alt_Enable(0); 
    upbriprm=slop*(time-Light_Charge_From_Parameter[Group4][step].OffsTiPm);
    if(upbriprm<=Light_Charge_From_Parameter[Group4][step].UpperBriPrm)
    {
        cur=Interface_GetSignal_ChannelCurrent(ChannelID2); //get current
        if(upbriprm==0) upbriprm=1;
        Interface_ChannelOpen(ChannelID2,cur,upbriprm);
    }
}

static void Group4_Mode3_Gradual_On_Execute(uint16 time,pr_ChargeStep_t step)
{
    float slop=0;
    uint8 upbriprm=0;
    uint16 cur=0;
    
    slop=(Light_Charge_From_Parameter[Group4][step].UpperBriPrm-Light_Charge_From_Parameter[Group4][step].LowBriPrm)*1.0/ \
        (Light_Charge_From_Parameter[Group4][step].ConTiPrm-Light_Charge_From_Parameter[Group4][step].OffsTiPm);
    Port_CH2Alt_Enable(0);
    upbriprm=Light_Charge_From_Parameter[Group4][step].UpperBriPrm-slop*(time-Light_Charge_From_Parameter[Group4][step].OffsTiPm);
    if(upbriprm<=Light_Charge_From_Parameter[Group4][step].UpperBriPrm)
    {
        cur=Interface_GetSignal_ChannelCurrent(ChannelID2); //get current
        if(upbriprm==0) upbriprm=1;
        Interface_ChannelOpen(ChannelID2,cur,upbriprm);
    }
} 

/* **********************************************CH3 GROUP5*********************************************************** */
static void Group5_Mode0_Gradual_On_Execute(void)
{
    uint16 cur=0;
    Interface_ChannelClose(ChannelID3); 
}

static void Group5_Mode1_Gradual_On_Execute(pr_ChargeStep_t step)
{
    uint16 cur=0;
    uint8 upbriprm=0;
    upbriprm=Light_Charge_From_Parameter[Group5][step].UpperBriPrm;
    cur=Interface_GetSignal_ChannelCurrent(ChannelID3);
    if(upbriprm==0) upbriprm=1;
    Interface_ChannelOpen(ChannelID3,cur,upbriprm);
}

static void Group5_Mode2_Gradual_On_Execute(uint16 time,pr_ChargeStep_t step)
{
    float slop=0;
    uint8 upbriprm=0;
    uint16 cur=0;

    slop=(Light_Charge_From_Parameter[Group5][step].UpperBriPrm-Light_Charge_From_Parameter[Group5][step].LowBriPrm)*1.0/ \
        (Light_Charge_From_Parameter[Group5][step].ConTiPrm-Light_Charge_From_Parameter[Group5][step].OffsTiPm);
    upbriprm=slop*(time-Light_Charge_From_Parameter[Group5][step].OffsTiPm);
    if(upbriprm<=Light_Charge_From_Parameter[Group5][step].UpperBriPrm)
    {
        cur=Interface_GetSignal_ChannelCurrent(ChannelID3); //get current
        if(upbriprm==0) upbriprm=1;
        Interface_ChannelOpen(ChannelID3,cur,upbriprm);
    }
}

static void Group5_Mode3_Gradual_On_Execute(uint16 time,pr_ChargeStep_t step)
{
    float slop=0;
    uint8 upbriprm=0;
    uint16 cur=0;
    
    slop=(Light_Charge_From_Parameter[Group5][step].UpperBriPrm-Light_Charge_From_Parameter[Group5][step].LowBriPrm)*1.0/ \
        (Light_Charge_From_Parameter[Group5][step].ConTiPrm-Light_Charge_From_Parameter[Group5][step].OffsTiPm);
    upbriprm=Light_Charge_From_Parameter[Group5][step].UpperBriPrm-slop*(time-Light_Charge_From_Parameter[Group5][step].OffsTiPm);
    if(upbriprm<=Light_Charge_From_Parameter[Group5][step].UpperBriPrm)
    {
        cur=Interface_GetSignal_ChannelCurrent(ChannelID3); //get current
        if(upbriprm==0) upbriprm=1;
        Interface_ChannelOpen(ChannelID3,cur,upbriprm);
    }
} 


/* **********************************************CH4 GROUP6*********************************************************** */
static void Group6_Mode0_Gradual_On_Execute(void)
{
    uint16 cur=0;
    Interface_ChannelClose(ChannelID4); 
}

static void Group6_Mode1_Gradual_On_Execute(pr_ChargeStep_t step)
{
    uint16 cur=0;
    uint8 upbriprm=0;
    upbriprm=Light_Charge_From_Parameter[Group6][step].UpperBriPrm;
    cur=Interface_GetSignal_ChannelCurrent(ChannelID4);
    if(upbriprm==0) upbriprm=1;
    Interface_ChannelOpen(ChannelID4,cur,upbriprm);
}

static void Group6_Mode2_Gradual_On_Execute(uint16 time,pr_ChargeStep_t step)
{
    float slop=0;
    uint8 upbriprm=0;
    uint16 cur=0;

    slop=(Light_Charge_From_Parameter[Group6][step].UpperBriPrm-Light_Charge_From_Parameter[Group6][step].LowBriPrm)*1.0/ \
        (Light_Charge_From_Parameter[Group6][step].ConTiPrm-Light_Charge_From_Parameter[Group6][step].OffsTiPm);
    upbriprm=slop*(time-Light_Charge_From_Parameter[Group6][step].OffsTiPm);
    if(upbriprm<=Light_Charge_From_Parameter[Group6][step].UpperBriPrm)
    {
        cur=Interface_GetSignal_ChannelCurrent(ChannelID4); //get current
        if(upbriprm==0) upbriprm=1;
        Interface_ChannelOpen(ChannelID4,cur,upbriprm);
    }
}

static void Group6_Mode3_Gradual_On_Execute(uint16 time,pr_ChargeStep_t step)
{
    float slop=0;
    uint8 upbriprm=0;
    uint16 cur=0;
    
    slop=(Light_Charge_From_Parameter[Group6][step].UpperBriPrm-Light_Charge_From_Parameter[Group6][step].LowBriPrm)*1.0/ \
        (Light_Charge_From_Parameter[Group6][step].ConTiPrm-Light_Charge_From_Parameter[Group6][step].OffsTiPm);

    upbriprm=Light_Charge_From_Parameter[Group6][step].UpperBriPrm-slop*(time-Light_Charge_From_Parameter[Group6][step].OffsTiPm);
    if(upbriprm<=Light_Charge_From_Parameter[Group6][step].UpperBriPrm)
    {
        cur=Interface_GetSignal_ChannelCurrent(ChannelID4); //get current
        if(upbriprm==0) upbriprm=1;
        Interface_ChannelOpen(ChannelID4,cur,upbriprm);
    }
} 


/****************************************************WELCOME GOODBYE************************************************************/
static Std_ReturnType Group1_WelcomeGoodbye(uint8 start,uint8 timebase)
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
//run over
    if(Light_Charge_From_Parameter[Group1][Step].ConTiPrm==0) 
    return E_NOT_OK;

    Mode=Light_Charge_From_Parameter[Group1][Step].pr_ChargeMode;   
    Mode_Time+=timebase; //every timebase only add once

    switch (Mode)
    {
    case mode0:
        if(Mode_Time>=Light_Charge_From_Parameter[Group1][Step].OffsTiPm) //delay the off time 
        {
            Group1_Mode0_Gradual_On_Execute();//mode2 run
        }
        if(Mode_Time>=Light_Charge_From_Parameter[Group1][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode1:               
        if(Mode_Time>=Light_Charge_From_Parameter[Group1][Step].OffsTiPm) //delay the off time 
        {
            Group1_Mode1_Gradual_On_Execute(Step);//mode1 run
        }
        if(Mode_Time>=Light_Charge_From_Parameter[Group1][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode2:                
        if(Mode_Time>=Light_Charge_From_Parameter[Group1][Step].OffsTiPm) //delay the off time 
        {
            Group1_Mode2_Gradual_On_Execute(Mode_Time,Step);//mode2 run
        }
        else
        {
            Interface_ChannelOpen(ChannelID1,0,0);
        }
        if(Mode_Time>=Light_Charge_From_Parameter[Group1][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode3:
        if(Mode_Time>=Light_Charge_From_Parameter[Group1][Step].OffsTiPm) //delay the off time 
        {
            Group1_Mode3_Gradual_On_Execute(Mode_Time,Step);
        }
        if(Mode_Time>=Light_Charge_From_Parameter[Group1][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    default:
        Step=step1;
        Mode=Light_Charge_From_Parameter[Group1][step1].pr_ChargeMode;
    break;
    }  
    return E_OK;
}


static Std_ReturnType Group2_WelcomeGoodbye(uint8 start,uint8 timebase)
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
//run over
    if(Light_Charge_From_Parameter[Group2][Step].ConTiPrm==0) 
    return E_NOT_OK;

    Mode=Light_Charge_From_Parameter[Group2][Step].pr_ChargeMode;   
    Mode_Time+=timebase; //every timebase only add once

    switch (Mode)
    {
    case mode0:
        if(Mode_Time>=Light_Charge_From_Parameter[Group2][Step].OffsTiPm) //delay the off time 
        {
            Group2_Mode0_Gradual_On_Execute();//mode2 run
        }
        if(Mode_Time>=Light_Charge_From_Parameter[Group2][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode1:               
        if(Mode_Time>=Light_Charge_From_Parameter[Group2][Step].OffsTiPm) //delay the off time 
        {
            Group2_Mode1_Gradual_On_Execute(Step);//mode1 run
        }
        else
        {
            Interface_ChannelOpen(ChannelID1_Tap,0,0);
        }
        if(Mode_Time>=Light_Charge_From_Parameter[Group2][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode2:                
        if(Mode_Time>=Light_Charge_From_Parameter[Group2][Step].OffsTiPm) //delay the off time 
        {
            Group2_Mode2_Gradual_On_Execute(Mode_Time,Step);//mode2 run
        }
        if(Mode_Time>=Light_Charge_From_Parameter[Group2][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode3:
        if(Mode_Time>=Light_Charge_From_Parameter[Group2][Step].OffsTiPm) //delay the off time 
        {
            Group2_Mode3_Gradual_On_Execute(Mode_Time,Step);
        }
        if(Mode_Time>=Light_Charge_From_Parameter[Group2][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    default:
        Step=step1;
        Mode=Light_Charge_From_Parameter[Group2][step1].pr_ChargeMode;
    break;
    }  
    return E_OK;
}

static Std_ReturnType Group3_WelcomeGoodbye(uint8 start,uint8 timebase)
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
//run over
    if(Light_Charge_From_Parameter[Group3][Step].ConTiPrm==0) 
    return E_NOT_OK;

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
    return E_OK;
}

static Std_ReturnType Group4_WelcomeGoodbye(uint8 start,uint8 timebase)
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
//run over
    if(Light_Charge_From_Parameter[Group4][Step].ConTiPrm==0) 
    return E_NOT_OK;

    Mode=Light_Charge_From_Parameter[Group4][Step].pr_ChargeMode;   
    Mode_Time+=timebase; //every timebase only add once

    switch (Mode)
    {
    case mode0:
        if(Mode_Time>=Light_Charge_From_Parameter[Group4][Step].OffsTiPm) //delay the off time 
        {
            Group4_Mode0_Gradual_On_Execute();//mode2 run
        }
        if(Mode_Time>=Light_Charge_From_Parameter[Group4][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode1:               
        if(Mode_Time>=Light_Charge_From_Parameter[Group4][Step].OffsTiPm) //delay the off time 
        {
            Group4_Mode1_Gradual_On_Execute(Step);//mode1 run
        }
        if(Mode_Time>=Light_Charge_From_Parameter[Group4][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode2:                
        if(Mode_Time>=Light_Charge_From_Parameter[Group4][Step].OffsTiPm) //delay the off time 
        {
            Group4_Mode2_Gradual_On_Execute(Mode_Time,Step);//mode2 run
        }
        else
        {
            Interface_ChannelOpen(ChannelID2_Alt,0,0);
        }
        if(Mode_Time>=Light_Charge_From_Parameter[Group4][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode3:
        if(Mode_Time>=Light_Charge_From_Parameter[Group4][Step].OffsTiPm) //delay the off time 
        {
            Group4_Mode3_Gradual_On_Execute(Mode_Time,Step);
        }
        if(Mode_Time>=Light_Charge_From_Parameter[Group4][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    default:
        Step=step1;
        Mode=Light_Charge_From_Parameter[Group4][step1].pr_ChargeMode;
    break;
    }  
    return E_OK;
}

static Std_ReturnType Group5_WelcomeGoodbye(uint8 start,uint8 timebase)
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
//run over
    if(Light_Charge_From_Parameter[Group5][Step].ConTiPrm==0) 
    return E_NOT_OK;

    Mode=Light_Charge_From_Parameter[Group5][Step].pr_ChargeMode;   
    Mode_Time+=timebase; //every timebase only add once

    switch (Mode)
    {
    case mode0:
        if(Mode_Time>=Light_Charge_From_Parameter[Group5][Step].OffsTiPm) //delay the off time 
        {
            Group5_Mode0_Gradual_On_Execute();//mode2 run
        }
        if(Mode_Time>=Light_Charge_From_Parameter[Group5][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode1:               
        if(Mode_Time>=Light_Charge_From_Parameter[Group5][Step].OffsTiPm) //delay the off time 
        {
            Group5_Mode1_Gradual_On_Execute(Step);//mode1 run
        }
        if(Mode_Time>=Light_Charge_From_Parameter[Group5][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode2:                
        if(Mode_Time>=Light_Charge_From_Parameter[Group5][Step].OffsTiPm) //delay the off time 
        {
            Group5_Mode2_Gradual_On_Execute(Mode_Time,Step);//mode2 run
        }
        else
        {
            Interface_ChannelOpen(ChannelID3,0,0);
        }
        if(Mode_Time>=Light_Charge_From_Parameter[Group5][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode3:
        if(Mode_Time>=Light_Charge_From_Parameter[Group5][Step].OffsTiPm) //delay the off time 
        {
            Group5_Mode3_Gradual_On_Execute(Mode_Time,Step);
        }
        if(Mode_Time>=Light_Charge_From_Parameter[Group5][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    default:
        Step=step1;
        Mode=Light_Charge_From_Parameter[Group5][step1].pr_ChargeMode;
    break;
    }  
    return E_OK;
}

static Std_ReturnType Group6_WelcomeGoodbye(uint8 start,uint8 timebase)
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
//run over
    if(Light_Charge_From_Parameter[Group6][Step].ConTiPrm==0) 
    return E_NOT_OK;

    Mode=Light_Charge_From_Parameter[Group6][Step].pr_ChargeMode;   
    Mode_Time+=timebase; //every timebase only add once

    switch (Mode)
    {
    case mode0:
        if(Mode_Time>=Light_Charge_From_Parameter[Group6][Step].OffsTiPm) //delay the off time 
        {
            Group6_Mode0_Gradual_On_Execute();//mode2 run
        }
        if(Mode_Time>=Light_Charge_From_Parameter[Group6][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode1:               
        if(Mode_Time>=Light_Charge_From_Parameter[Group6][Step].OffsTiPm) //delay the off time 
        {
            Group6_Mode1_Gradual_On_Execute(Step);//mode1 run
        }
        if(Mode_Time>=Light_Charge_From_Parameter[Group6][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode2:                
        if(Mode_Time>=Light_Charge_From_Parameter[Group6][Step].OffsTiPm) //delay the off time 
        {
            Group6_Mode2_Gradual_On_Execute(Mode_Time,Step);//mode2 run
        }
        else
        {
            Interface_ChannelOpen(ChannelID4,0,0);
        }
        if(Mode_Time>=Light_Charge_From_Parameter[Group6][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode3:
        if(Mode_Time>=Light_Charge_From_Parameter[Group6][Step].OffsTiPm) //delay the off time 
        {
            Group6_Mode3_Gradual_On_Execute(Mode_Time,Step);
        }
        if(Mode_Time>=Light_Charge_From_Parameter[Group6][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    default:
        Step=step1;
        Mode=Light_Charge_From_Parameter[Group6][step1].pr_ChargeMode;
    break;
    }  
    return E_OK;
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
            Pwm_HLCtrl_Disable();
            Port_CH2_Disable();  
            Port_CH2Alt_Disable();
            for(id=0;id<6;id++)
            {
                Interface_ChannelClose(id);
                Reset_ChannelAllError(id);
            } 
        }
        flag_get_parameter=0;
        return E_NOT_OK;
    }
/* the first run in,need to close all light, set the status to off, and get the parameters */
    if(((GetLgtStsEna_WELC()==1)&&(flag_get_parameter!=1))||((GetLgtStsEna_GDY()==1)&&(flag_get_parameter!=2)))
    {
        FirstRunOrNot=DYN_OFF;
        Pwm_HLCtrl_Disable();
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

        if(flag_get_parameter!=1)         // get welcome group 
        {
            flag_get_parameter=1;
            GroupWelcome1_Get_Parameter();
        }
        else if(flag_get_parameter!=2)    // get goodbye group 
        {  
            flag_get_parameter=2; 
        }
    }
/* clean the error cnt */
    for(id=0;id<6;id++)
    {
        Reset_ChannelAllError(id);
    }
/* run the every group */
    Group1_WelcomeGoodbye(FirstRunOrNot,timebase);
    Group2_WelcomeGoodbye(FirstRunOrNot,timebase);
    Group3_WelcomeGoodbye(FirstRunOrNot,timebase);
    Group4_WelcomeGoodbye(FirstRunOrNot,timebase);
    Group5_WelcomeGoodbye(FirstRunOrNot,timebase);
    Group6_WelcomeGoodbye(FirstRunOrNot,timebase);
    FirstRunOrNot=DYN_ON;
    return E_OK;
}



