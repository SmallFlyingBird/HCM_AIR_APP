#include "HcmPlatform.h"
#include "WelGdy.h"
#include "Parameter_Interface.h"
#include "LinManager.h"
#include "Channel_Interface.h"
#include "Dio_Service.h"
#include "DTC_Interface.h"
#include "Pwm_Service.h"
#include "ParaMgr.h"
#include "StarsLight.h"

#define CHARGE_TOTAL_TIME   30000     //charge total execute time  30s

#define STEP_MAXNUM    10
#define GROUP_MAXNUM   8
#define Charge_MAXNUM  2

#define GROUP_HWOUT    2
#define GROUPRUNMAX    8 /* real run group */
pr_WelGdy_Group Light_WelGdy_From_Parameter[GROUP_MAXNUM][STEP_MAXNUM]; 
HWOut_WelGdy_Group HWOut_WelGdy_From_Parameter[GROUP_HWOUT][STEP_MAXNUM]; 

#define DYN_OFF  0
#define DYN_ON   1

#define NODYN       0
#define WELRUN      1
#define GDYRUN      2
#define POSDYNRUN   3

const uint8 ParaMgr_pChargeModeLowBri_B[20] = {2, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 80, 0, 0, 0, 0, 0, 0, 0, 0};
const uint8 ParaMgr_pChargeOffTiConTiUpBri_B[30] = {10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 10, 90, 0, 0, 0, 0, 0, 0, 0, 80, 80, 80, 0, 0, 0, 0, 0, 0, 0};
/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/
/******************************************************Get Charge Group Parameter************************************************************/
static Std_ReturnType GroupCharge_Get_Parameter(void)
{
    uint16 Step=0;
    uint8 lgmask=0;
    E_LED_Group_ID groupx=Group1;
    lgmask=GetChannelMaskByLightFunction(E_PositionLight);
    for(groupx=Group1;groupx<=Group6;groupx++) //DYN not use in HSD
    {
        if(((lgmask>>groupx)&0x01)!=0) //find the pos channel
        {
            for(Step=step1;Step<=StepNum;Step++)
            {
                Light_WelGdy_From_Parameter[groupx][Step].pr_ChargeMode = (pr_ChargeMode_t)ParaMgr_pChargeModeLowBri_B[Step];
                Light_WelGdy_From_Parameter[groupx][Step].LowBriPrm     = (ParaMgr_pChargeModeLowBri_B[Step + 10]);
                Light_WelGdy_From_Parameter[groupx][Step].OffsTiPm      = (ParaMgr_pChargeOffTiConTiUpBri_B[Step])*10;
                Light_WelGdy_From_Parameter[groupx][Step].ConTiPrm      = (ParaMgr_pChargeOffTiConTiUpBri_B[Step + 10])*10;
                Light_WelGdy_From_Parameter[groupx][Step].UpperBriPrm   = (ParaMgr_pChargeOffTiConTiUpBri_B[Step + 20]);
            }
        }
        else //clear the buf no use
        {
            for(Step=step1;Step<=StepNum;Step++)
            {
                Light_WelGdy_From_Parameter[groupx][Step].pr_ChargeMode = mode0;
                Light_WelGdy_From_Parameter[groupx][Step].LowBriPrm     = 0;
                Light_WelGdy_From_Parameter[groupx][Step].OffsTiPm      = 0;
                Light_WelGdy_From_Parameter[groupx][Step].ConTiPrm      = 0;
                Light_WelGdy_From_Parameter[groupx][Step].UpperBriPrm   = 0;
            }
        }
    }
    return E_OK;
}
/******************************************************Get All Group Parameter************************************************************/
static Std_ReturnType GroupWelcome1_Get_Parameter(void)
{
    const uint8 *p_Mode_LowBri_Parameter;
	const uint8 *p_OffTi_ConTi_UpBri_Parameter;
    uint8 Step=0;
    E_LED_Group_ID groupx=Group1;
    for(groupx=Group1;groupx < GroupNum;groupx++)
    {
        p_Mode_LowBri_Parameter=Get_Dynamic_Light_Function_pWelcomP1ModeLowBri_By_Group(groupx);
        p_OffTi_ConTi_UpBri_Parameter=Get_Dynamic_Light_Function_pWelcomP1OffTiConTiUpBri_By_Group(groupx);
        for(Step=step1;Step<=StepNum;Step++)
        {
            Light_WelGdy_From_Parameter[groupx][Step].pr_ChargeMode = (pr_ChargeMode_t)p_Mode_LowBri_Parameter[Step];
            Light_WelGdy_From_Parameter[groupx][Step].LowBriPrm = (p_Mode_LowBri_Parameter[Step + 10]);
            Light_WelGdy_From_Parameter[groupx][Step].OffsTiPm = (p_OffTi_ConTi_UpBri_Parameter[Step])*10;
            Light_WelGdy_From_Parameter[groupx][Step].ConTiPrm = (p_OffTi_ConTi_UpBri_Parameter[Step + 10])*10;
            Light_WelGdy_From_Parameter[groupx][Step].UpperBriPrm = (p_OffTi_ConTi_UpBri_Parameter[Step + 20]);
        }
    }
    return E_OK;
}
//goodbye
static Std_ReturnType GroupWelcome2_Get_Parameter(void)
{
    const uint8 *p_Mode_LowBri_Parameter;
	const uint8 *p_OffTi_ConTi_UpBri_Parameter;
    uint8 Step=0;
    E_LED_Group_ID groupx=Group1;
    for(groupx = Group1;groupx < GroupNum;groupx++)
    {
        p_Mode_LowBri_Parameter=Get_Dynamic_Light_Function_pWelcomP2ModeLowBri_By_Group(groupx);
        p_OffTi_ConTi_UpBri_Parameter=Get_Dynamic_Light_Function_pWelcomP2OffTiConTiUpBri_By_Group(groupx);
        for(Step=step1;Step<=StepNum;Step++)
        {
            Light_WelGdy_From_Parameter[groupx][Step].pr_ChargeMode = (pr_ChargeMode_t)p_Mode_LowBri_Parameter[Step];
            Light_WelGdy_From_Parameter[groupx][Step].LowBriPrm = (p_Mode_LowBri_Parameter[Step + 10]);
            Light_WelGdy_From_Parameter[groupx][Step].OffsTiPm = (p_OffTi_ConTi_UpBri_Parameter[Step])*10;
            Light_WelGdy_From_Parameter[groupx][Step].ConTiPrm = (p_OffTi_ConTi_UpBri_Parameter[Step + 10])*10;
            Light_WelGdy_From_Parameter[groupx][Step].UpperBriPrm = (p_OffTi_ConTi_UpBri_Parameter[Step + 20]);
        }
    }
    return E_OK;
}

/* HWOUT Welcome from parameter */
static Std_ReturnType GroupHWOutWel_Get_Parameter(void)
{
    uint8 Step=0;
    for(Step=step1;Step<=StepNum;Step++)
    {
        HWOut_WelGdy_From_Parameter[0][Step].Pwmper = ParaMgr_pWelcomHW_OUT1_PWM_B[Step];
        HWOut_WelGdy_From_Parameter[0][Step].ConTiPrm = ParaMgr_pWelcomHW_OUT1_ConTiPrm_B[Step]*10;
        HWOut_WelGdy_From_Parameter[1][Step].Pwmper = ParaMgr_pWelcomHW_OUT2_PWM_B[Step];
        HWOut_WelGdy_From_Parameter[1][Step].ConTiPrm = ParaMgr_pWelcomHW_OUT2_ConTiPrm_B[Step]*10;
    }
    return E_OK;
}

/* HWOUT Goodbye from parameter*/
static Std_ReturnType GroupHWOutGby_Get_Parameter(void)
{
    uint8 Step=0;
    for(Step=step1;Step<=StepNum;Step++)
    {
        HWOut_WelGdy_From_Parameter[0][Step].Pwmper = ParaMgr_pWelcomHW_OUT1_PWM_B[Step+10];
        HWOut_WelGdy_From_Parameter[0][Step].ConTiPrm = ParaMgr_pWelcomHW_OUT1_ConTiPrm_B[Step+10]*10;
        HWOut_WelGdy_From_Parameter[1][Step].Pwmper = ParaMgr_pWelcomHW_OUT2_PWM_B[Step+10];
        HWOut_WelGdy_From_Parameter[1][Step].ConTiPrm = ParaMgr_pWelcomHW_OUT2_PWM_B[Step+10]*10;
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
    Pwm_HLCtrl_Disable();
    Interface_ChannelClose(ChannelID1); 
}

static void Group1_Mode1_Gradual_On_Execute(pr_ChargeStep_t step)
{
    uint16 cur=0;
    uint8 upbriprm=0;
    Pwm_HLCtrl_Enable();
    upbriprm=Light_WelGdy_From_Parameter[Group1][step].UpperBriPrm;
    cur=Interface_GetSignal_ChannelCurrent(ChannelID1);
    // if(upbriprm==0) upbriprm=1;
    Interface_ChannelOpen(ChannelID1,cur,upbriprm);
}

static void Group1_Mode2_Gradual_On_Execute(uint16 time,pr_ChargeStep_t step)
{
    float slop=0;
    uint8 upbriprm=0;
    uint16 cur=0;

    slop=(Light_WelGdy_From_Parameter[Group1][step].UpperBriPrm-Light_WelGdy_From_Parameter[Group1][step].LowBriPrm)*1.0/ \
        (Light_WelGdy_From_Parameter[Group1][step].ConTiPrm-Light_WelGdy_From_Parameter[Group1][step].OffsTiPm);
    Pwm_HLCtrl_Enable();
    upbriprm=slop*(time-Light_WelGdy_From_Parameter[Group1][step].OffsTiPm)+Light_WelGdy_From_Parameter[Group1][step].LowBriPrm;
    if(upbriprm>Light_WelGdy_From_Parameter[Group1][step].UpperBriPrm)
    {
        upbriprm=Light_WelGdy_From_Parameter[Group1][step].UpperBriPrm;
    }
    cur=Interface_GetSignal_ChannelCurrent(ChannelID1); //get current
    Interface_ChannelOpen(ChannelID1,cur,upbriprm);
}

static void Group1_Mode3_Gradual_On_Execute(uint16 time,pr_ChargeStep_t step)
{
    float slop=0;
    uint8 upbriprm=0;
    uint16 cur=0;
    
    slop=(Light_WelGdy_From_Parameter[Group1][step].UpperBriPrm-Light_WelGdy_From_Parameter[Group1][step].LowBriPrm)*1.0/ \
        (Light_WelGdy_From_Parameter[Group1][step].ConTiPrm-Light_WelGdy_From_Parameter[Group1][step].OffsTiPm);
    Pwm_HLCtrl_Enable();
    upbriprm=Light_WelGdy_From_Parameter[Group1][step].UpperBriPrm-slop*(time-Light_WelGdy_From_Parameter[Group1][step].OffsTiPm);
    if(upbriprm<=Light_WelGdy_From_Parameter[Group1][step].UpperBriPrm)
    {
        cur=Interface_GetSignal_ChannelCurrent(ChannelID1); //get current
        if(upbriprm!=0)
        {
            Interface_ChannelOpen(ChannelID1,cur,upbriprm);
        }
        else
        {
            Interface_ChannelClose(ChannelID1);
        }
    }
}

/* **********************************************CH1' GROUP2*********************************************************** */
static void Group2_Mode0_Gradual_On_Execute(void)
{
    Interface_ChannelClose(ChannelID1_Tap); 
}

static void Group2_Mode1_Gradual_On_Execute(pr_ChargeStep_t step)
{
    uint16 cur=0;
    uint8 upbriprm=0;
    upbriprm=Light_WelGdy_From_Parameter[Group2][step].UpperBriPrm;
    cur=Interface_GetSignal_ChannelCurrent(ChannelID1_Tap);
    Interface_ChannelOpen(ChannelID1_Tap,cur,upbriprm);
}

static void Group2_Mode2_Gradual_On_Execute(uint16 time,pr_ChargeStep_t step)
{
    float slop=0;
    uint8 upbriprm=0;
    uint16 cur=0;

    slop=(Light_WelGdy_From_Parameter[Group2][step].UpperBriPrm-Light_WelGdy_From_Parameter[Group2][step].LowBriPrm)*1.0/ \
        (Light_WelGdy_From_Parameter[Group2][step].ConTiPrm-Light_WelGdy_From_Parameter[Group2][step].OffsTiPm); 
    upbriprm=slop*(time-Light_WelGdy_From_Parameter[Group2][step].OffsTiPm)+Light_WelGdy_From_Parameter[Group2][step].LowBriPrm;
    if(upbriprm>Light_WelGdy_From_Parameter[Group2][step].UpperBriPrm)
    {
        upbriprm=Light_WelGdy_From_Parameter[Group2][step].UpperBriPrm;
    }

    cur=Interface_GetSignal_ChannelCurrent(ChannelID1_Tap); //get current
    Interface_ChannelOpen(ChannelID1_Tap,cur,upbriprm);
}

static void Group2_Mode3_Gradual_On_Execute(uint16 time,pr_ChargeStep_t step)
{
    float slop=0;
    uint8 upbriprm=0;
    uint16 cur=0;
    
    slop=(Light_WelGdy_From_Parameter[Group2][step].UpperBriPrm-Light_WelGdy_From_Parameter[Group2][step].LowBriPrm)*1.0/ \
        (Light_WelGdy_From_Parameter[Group2][step].ConTiPrm-Light_WelGdy_From_Parameter[Group2][step].OffsTiPm);
    upbriprm=Light_WelGdy_From_Parameter[Group2][step].UpperBriPrm-slop*(time-Light_WelGdy_From_Parameter[Group2][step].OffsTiPm);
    if(upbriprm<=Light_WelGdy_From_Parameter[Group2][step].UpperBriPrm)
    {
        cur=Interface_GetSignal_ChannelCurrent(ChannelID1_Tap); //get current
        if(upbriprm!=0)
        {
            Interface_ChannelOpen(ChannelID1_Tap,cur,upbriprm);
        }
        else
        {
            Interface_ChannelClose(ChannelID1_Tap);
        }
    }
}
/* **********************************************CH2 GROUP3*********************************************************** */
static void Group3_Mode0_Gradual_On_Execute(void)
{
    Port_CH2_Disable();
    Interface_ChannelClose(ChannelID2); 
}

static void Group3_Mode1_Gradual_On_Execute(pr_ChargeStep_t step)
{
    uint16 cur=0;
    uint8 upbriprm=0;
    Port_CH2_Enable(); 
    upbriprm=Light_WelGdy_From_Parameter[Group3][step].UpperBriPrm;
    cur=Interface_GetSignal_ChannelCurrent(ChannelID2);
    Interface_ChannelOpen(ChannelID2,cur,upbriprm);
}

static void Group3_Mode2_Gradual_On_Execute(uint16 time,pr_ChargeStep_t step)
{
    float slop=0;
    uint8 upbriprm=0;
    uint16 cur=0;

    slop=(Light_WelGdy_From_Parameter[Group3][step].UpperBriPrm-Light_WelGdy_From_Parameter[Group3][step].LowBriPrm)*1.0/ \
        (Light_WelGdy_From_Parameter[Group3][step].ConTiPrm-Light_WelGdy_From_Parameter[Group3][step].OffsTiPm);
    Port_CH2_Enable(); 
    upbriprm=slop*(time-Light_WelGdy_From_Parameter[Group3][step].OffsTiPm)+Light_WelGdy_From_Parameter[Group3][step].LowBriPrm;
    if(upbriprm>Light_WelGdy_From_Parameter[Group3][step].UpperBriPrm)
    {
        upbriprm=Light_WelGdy_From_Parameter[Group3][step].UpperBriPrm;
    }
    cur=Interface_GetSignal_ChannelCurrent(ChannelID2); //get current
    Interface_ChannelOpen(ChannelID2,cur,upbriprm);
}

static void Group3_Mode3_Gradual_On_Execute(uint16 time,pr_ChargeStep_t step)
{
    float slop=0;
    uint8 upbriprm=0;
    uint16 cur=0;
    
    slop=(Light_WelGdy_From_Parameter[Group3][step].UpperBriPrm-Light_WelGdy_From_Parameter[Group3][step].LowBriPrm)*1.0/ \
        (Light_WelGdy_From_Parameter[Group3][step].ConTiPrm-Light_WelGdy_From_Parameter[Group3][step].OffsTiPm);
    Port_CH2_Enable();
    upbriprm=Light_WelGdy_From_Parameter[Group3][step].UpperBriPrm-slop*(time-Light_WelGdy_From_Parameter[Group3][step].OffsTiPm);
    if(upbriprm<=Light_WelGdy_From_Parameter[Group3][step].UpperBriPrm)
    {
        cur=Interface_GetSignal_ChannelCurrent(ChannelID2); //get current
        if(upbriprm!=0)
        {
            Interface_ChannelOpen(ChannelID2,cur,upbriprm);
        }
        else
        {
            Interface_ChannelClose(ChannelID2);
        }
    }
}

/* **********************************************CH2' GROUP4*********************************************************** */
static void Group4_Mode0_Gradual_On_Execute(void)
{
    Port_CH2Alt_Disable();
    Interface_ChannelClose(ChannelID2_Alt); 
}

static void Group4_Mode1_Gradual_On_Execute(pr_ChargeStep_t step)
{
    uint16 cur=0;
    uint8 upbriprm=0;
    Port_CH2Alt_Enable(); 
    upbriprm=Light_WelGdy_From_Parameter[Group4][step].UpperBriPrm;
    cur=Interface_GetSignal_ChannelCurrent(ChannelID2_Alt);
    // if(upbriprm==0) upbriprm=1;
    Interface_ChannelOpen(ChannelID2_Alt,cur,upbriprm);
}

static void Group4_Mode2_Gradual_On_Execute(uint16 time,pr_ChargeStep_t step)
{
    float slop=0;
    uint8 upbriprm=0;
    uint16 cur=0;

    slop=(Light_WelGdy_From_Parameter[Group4][step].UpperBriPrm-Light_WelGdy_From_Parameter[Group4][step].LowBriPrm)*1.0/ \
        (Light_WelGdy_From_Parameter[Group4][step].ConTiPrm-Light_WelGdy_From_Parameter[Group4][step].OffsTiPm);
    Port_CH2Alt_Enable(); 
    upbriprm=slop*(time-Light_WelGdy_From_Parameter[Group4][step].OffsTiPm)+Light_WelGdy_From_Parameter[Group4][step].LowBriPrm;
    if(upbriprm>Light_WelGdy_From_Parameter[Group4][step].UpperBriPrm)
    {
        upbriprm=Light_WelGdy_From_Parameter[Group4][step].UpperBriPrm;
    }
    cur=Interface_GetSignal_ChannelCurrent(ChannelID2_Alt); //get current
    Interface_ChannelOpen(ChannelID2_Alt,cur,upbriprm);
}

static void Group4_Mode3_Gradual_On_Execute(uint16 time,pr_ChargeStep_t step)
{
    float slop=0;
    uint8 upbriprm=0;
    uint16 cur=0;
    
    slop=(Light_WelGdy_From_Parameter[Group4][step].UpperBriPrm-Light_WelGdy_From_Parameter[Group4][step].LowBriPrm)*1.0/ \
        (Light_WelGdy_From_Parameter[Group4][step].ConTiPrm-Light_WelGdy_From_Parameter[Group4][step].OffsTiPm);
    Port_CH2Alt_Enable();
    upbriprm=Light_WelGdy_From_Parameter[Group4][step].UpperBriPrm-slop*(time-Light_WelGdy_From_Parameter[Group4][step].OffsTiPm);
    if(upbriprm<=Light_WelGdy_From_Parameter[Group4][step].UpperBriPrm)
    {
        cur=Interface_GetSignal_ChannelCurrent(ChannelID2_Alt); //get current
        if(upbriprm!=0)
        {
            Interface_ChannelOpen(ChannelID2_Alt,cur,upbriprm);
        }
        else
        {
            Interface_ChannelClose(ChannelID2_Alt);
        }
    }
} 

/* **********************************************CH3 GROUP5*********************************************************** */
static void Group5_Mode0_Gradual_On_Execute(void)
{
    Interface_ChannelClose(ChannelID3); 
}

static void Group5_Mode1_Gradual_On_Execute(pr_ChargeStep_t step)
{
    uint16 cur=0;
    uint8 upbriprm=0;
    upbriprm=Light_WelGdy_From_Parameter[Group5][step].UpperBriPrm;
    cur=Interface_GetSignal_ChannelCurrent(ChannelID3);
    Interface_ChannelOpen(ChannelID3,cur,upbriprm);
}

static void Group5_Mode2_Gradual_On_Execute(uint16 time,pr_ChargeStep_t step)
{
    float slop=0;
    uint8 upbriprm=0;
    uint16 cur=0;

    slop=(Light_WelGdy_From_Parameter[Group5][step].UpperBriPrm-Light_WelGdy_From_Parameter[Group5][step].LowBriPrm)*1.0/ \
        (Light_WelGdy_From_Parameter[Group5][step].ConTiPrm-Light_WelGdy_From_Parameter[Group5][step].OffsTiPm);
    upbriprm=slop*(time-Light_WelGdy_From_Parameter[Group5][step].OffsTiPm)+Light_WelGdy_From_Parameter[Group5][step].LowBriPrm;
    if(upbriprm>Light_WelGdy_From_Parameter[Group5][step].UpperBriPrm)
    {
        upbriprm=Light_WelGdy_From_Parameter[Group5][step].UpperBriPrm;
    }
    cur=Interface_GetSignal_ChannelCurrent(ChannelID3); //get current
    Interface_ChannelOpen(ChannelID3,cur,upbriprm);
}

static void Group5_Mode3_Gradual_On_Execute(uint16 time,pr_ChargeStep_t step)
{
    float slop=0;
    uint8 upbriprm=0;
    uint16 cur=0;
    slop=(Light_WelGdy_From_Parameter[Group5][step].UpperBriPrm-Light_WelGdy_From_Parameter[Group5][step].LowBriPrm)*1.0/ \
        (Light_WelGdy_From_Parameter[Group5][step].ConTiPrm-Light_WelGdy_From_Parameter[Group5][step].OffsTiPm);
    upbriprm=Light_WelGdy_From_Parameter[Group5][step].UpperBriPrm-slop*(time-Light_WelGdy_From_Parameter[Group5][step].OffsTiPm);
    if(upbriprm<=Light_WelGdy_From_Parameter[Group5][step].UpperBriPrm)
    {
        cur=Interface_GetSignal_ChannelCurrent(ChannelID3); //get current
        if(upbriprm!=0)
        {
            Interface_ChannelOpen(ChannelID3,cur,upbriprm);
        }
        else
        {
            Interface_ChannelClose(ChannelID3);
        }       
    }
} 


/* **********************************************CH4 GROUP6*********************************************************** */
static void Group6_Mode0_Gradual_On_Execute(void)
{
    Interface_ChannelClose(ChannelID4); 
}

static void Group6_Mode1_Gradual_On_Execute(pr_ChargeStep_t step)
{
    uint16 cur=0;
    uint8 upbriprm=0;
    upbriprm=Light_WelGdy_From_Parameter[Group6][step].UpperBriPrm;
    cur=Interface_GetSignal_ChannelCurrent(ChannelID4);
    Interface_ChannelOpen(ChannelID4,cur,upbriprm);
}

static void Group6_Mode2_Gradual_On_Execute(uint16 time,pr_ChargeStep_t step)
{
    float slop=0;
    uint8 upbriprm=0;
    uint16 cur=0;

    slop=(Light_WelGdy_From_Parameter[Group6][step].UpperBriPrm-Light_WelGdy_From_Parameter[Group6][step].LowBriPrm)*1.0/ \
        (Light_WelGdy_From_Parameter[Group6][step].ConTiPrm-Light_WelGdy_From_Parameter[Group6][step].OffsTiPm);
    upbriprm=slop*(time-Light_WelGdy_From_Parameter[Group6][step].OffsTiPm)+Light_WelGdy_From_Parameter[Group6][step].LowBriPrm;
    if(upbriprm>Light_WelGdy_From_Parameter[Group6][step].UpperBriPrm)
    {
        upbriprm=Light_WelGdy_From_Parameter[Group6][step].UpperBriPrm;
    }
    cur=Interface_GetSignal_ChannelCurrent(ChannelID4); //get current
    Interface_ChannelOpen(ChannelID4,cur,upbriprm);
}

static void Group6_Mode3_Gradual_On_Execute(uint16 time,pr_ChargeStep_t step)
{
    float slop=0;
    uint8 upbriprm=0;
    uint16 cur=0;
    
    slop=(Light_WelGdy_From_Parameter[Group6][step].UpperBriPrm-Light_WelGdy_From_Parameter[Group6][step].LowBriPrm)*1.0/ \
        (Light_WelGdy_From_Parameter[Group6][step].ConTiPrm-Light_WelGdy_From_Parameter[Group6][step].OffsTiPm);

    upbriprm=Light_WelGdy_From_Parameter[Group6][step].UpperBriPrm-slop*(time-Light_WelGdy_From_Parameter[Group6][step].OffsTiPm);
    if(upbriprm<=Light_WelGdy_From_Parameter[Group6][step].UpperBriPrm)
    {
        cur=Interface_GetSignal_ChannelCurrent(ChannelID4); //get current
        upbriprm=Light_WelGdy_From_Parameter[Group6][step].UpperBriPrm-slop*(time-Light_WelGdy_From_Parameter[Group6][step].OffsTiPm);
        if(upbriprm!=0)
        {
            Interface_ChannelOpen(ChannelID4,cur,upbriprm);
        }
        else
        {
            Interface_ChannelClose(ChannelID4);
        }
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
    if(Light_WelGdy_From_Parameter[Group1][Step].ConTiPrm==0) 
    {
        return E_NOT_OK;
    }

    Mode=Light_WelGdy_From_Parameter[Group1][Step].pr_ChargeMode;   
    Mode_Time+=timebase; //every timebase only add once

    switch (Mode)
    {
    case mode0:
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group1][Step].OffsTiPm) //delay the off time 
        {
            Group1_Mode0_Gradual_On_Execute();//mode2 run
        }
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group1][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode1:               
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group1][Step].OffsTiPm) //delay the off time 
        {
            Group1_Mode1_Gradual_On_Execute(Step);//mode1 run
        }
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group1][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode2:                
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group1][Step].OffsTiPm) //delay the off time 
        {
            Group1_Mode2_Gradual_On_Execute(Mode_Time,Step);//mode2 run
        }
        else
        {
            Interface_ChannelOpen(ChannelID1,0,0);
        }
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group1][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode3:
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group1][Step].OffsTiPm) //delay the off time 
        {
            Group1_Mode3_Gradual_On_Execute(Mode_Time,Step);
        }
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group1][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    default:
        Step=step1;
        Mode=Light_WelGdy_From_Parameter[Group1][step1].pr_ChargeMode;
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
    if(Light_WelGdy_From_Parameter[Group2][Step].ConTiPrm==0) 
    {
        return E_NOT_OK;
    }

    Mode=Light_WelGdy_From_Parameter[Group2][Step].pr_ChargeMode;   
    Mode_Time+=timebase; //every timebase only add once

    switch (Mode)
    {
    case mode0:
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group2][Step].OffsTiPm) //delay the off time 
        {
            Group2_Mode0_Gradual_On_Execute();//mode2 run
        }
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group2][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode1:               
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group2][Step].OffsTiPm) //delay the off time 
        {
            Group2_Mode1_Gradual_On_Execute(Step);//mode1 run
        }
        else
        {
            Interface_ChannelOpen(ChannelID1_Tap,0,0);
        }
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group2][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode2:                
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group2][Step].OffsTiPm) //delay the off time 
        {
            Group2_Mode2_Gradual_On_Execute(Mode_Time,Step);//mode2 run
        }
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group2][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode3:
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group2][Step].OffsTiPm) //delay the off time 
        {
            Group2_Mode3_Gradual_On_Execute(Mode_Time,Step);
        }
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group2][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    default:
        Step=step1;
        Mode=Light_WelGdy_From_Parameter[Group2][step1].pr_ChargeMode;
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
    if(Light_WelGdy_From_Parameter[Group3][Step].ConTiPrm==0) 
    return E_NOT_OK;

    Mode=Light_WelGdy_From_Parameter[Group3][Step].pr_ChargeMode;   
    Mode_Time+=timebase; //every timebase only add once
    switch (Mode)
    {
    case mode0:
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group3][Step].OffsTiPm) //delay the off time 
        {
            // if((group3_mode0run==0)&&(group4_mode1run==0))
            {
                // group3_mode0run=1;
                Group3_Mode0_Gradual_On_Execute();//mode2 run
            }            
        }
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group3][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode1:               
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group3][Step].OffsTiPm) //delay the off time 
        {
            // if(group3_mode1run==0)
            {
                // group3_mode1run=1;
                Group3_Mode1_Gradual_On_Execute(Step);//mode1 run
            }                      
        }
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group3][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode2:                
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group3][Step].OffsTiPm) //delay the off time 
        {
            Group3_Mode2_Gradual_On_Execute(Mode_Time,Step);//mode2 run
        }
        else
        {
            Interface_ChannelOpen(ChannelID2,0,0);
        }
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group3][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode3:
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group3][Step].OffsTiPm) //delay the off time 
        {
            Group3_Mode3_Gradual_On_Execute(Mode_Time,Step);
        }
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group3][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    default:
        Step=step1;
        Mode=Light_WelGdy_From_Parameter[Group3][step1].pr_ChargeMode;
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
    if(Light_WelGdy_From_Parameter[Group4][Step].ConTiPrm==0) 
    {
        return E_NOT_OK;
    }

    Mode=Light_WelGdy_From_Parameter[Group4][Step].pr_ChargeMode;   
    Mode_Time+=timebase; //every timebase only add once
    switch (Mode)
    {
    case mode0:
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group4][Step].OffsTiPm) //delay the off time 
        {
            Group4_Mode0_Gradual_On_Execute();//mode2 run           
        }
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group4][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode1:               
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group4][Step].OffsTiPm) //delay the off time 
        {
            // if(group4_mode1run==0)
            {
                // group4_mode1run=1;
                Group4_Mode1_Gradual_On_Execute(Step);//mode1 run
            }     
        }
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group4][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode2:                
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group4][Step].OffsTiPm) //delay the off time 
        {
            Group4_Mode2_Gradual_On_Execute(Mode_Time,Step);//mode2 run
        }
        else
        {
            Interface_ChannelOpen(ChannelID2_Alt,0,0);
        }
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group4][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode3:
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group4][Step].OffsTiPm) //delay the off time 
        {
            Group4_Mode3_Gradual_On_Execute(Mode_Time,Step);
        }
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group4][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    default:
        Step=step1;
        Mode=Light_WelGdy_From_Parameter[Group4][step1].pr_ChargeMode;
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
    if(Light_WelGdy_From_Parameter[Group5][Step].ConTiPrm==0) 
    {
        return E_NOT_OK;
    }

    Mode=Light_WelGdy_From_Parameter[Group5][Step].pr_ChargeMode;   
    Mode_Time+=timebase; //every timebase only add once

    switch (Mode)
    {
    case mode0:
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group5][Step].OffsTiPm) //delay the off time 
        {
            Group5_Mode0_Gradual_On_Execute();//mode2 run
        }
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group5][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode1:               
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group5][Step].OffsTiPm) //delay the off time 
        {
            Group5_Mode1_Gradual_On_Execute(Step);//mode1 run
        }
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group5][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode2:                
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group5][Step].OffsTiPm) //delay the off time 
        {
            Group5_Mode2_Gradual_On_Execute(Mode_Time,Step);//mode2 run
        }
        else
        {
            Interface_ChannelOpen(ChannelID3,0,0);
        }
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group5][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode3:
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group5][Step].OffsTiPm) //delay the off time 
        {
            Group5_Mode3_Gradual_On_Execute(Mode_Time,Step);
        }
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group5][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    default:
        Step=step1;
        Mode=Light_WelGdy_From_Parameter[Group5][step1].pr_ChargeMode;
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
    if(Light_WelGdy_From_Parameter[Group6][Step].ConTiPrm==0) 
    {
        return E_NOT_OK;
    }

    Mode=Light_WelGdy_From_Parameter[Group6][Step].pr_ChargeMode;   
    Mode_Time+=timebase; //every timebase only add once

    switch (Mode)
    {
    case mode0:
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group6][Step].OffsTiPm) //delay the off time 
        {
            Group6_Mode0_Gradual_On_Execute();//mode2 run
        }
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group6][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode1:               
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group6][Step].OffsTiPm) //delay the off time 
        {
            Group6_Mode1_Gradual_On_Execute(Step);//mode1 run
        }
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group6][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode2:                
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group6][Step].OffsTiPm) //delay the off time 
        {
            Group6_Mode2_Gradual_On_Execute(Mode_Time,Step);//mode2 run
        }
        else
        {
            Interface_ChannelOpen(ChannelID4,0,0);
        }
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group6][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    case mode3:
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group6][Step].OffsTiPm) //delay the off time 
        {
            Group6_Mode3_Gradual_On_Execute(Mode_Time,Step);
        }
        if(Mode_Time>=Light_WelGdy_From_Parameter[Group6][Step].ConTiPrm)
        {
            Mode_Time=0;
            Step++;
        }
    break;
    default:
        Step=step1;
        Mode=Light_WelGdy_From_Parameter[Group6][step1].pr_ChargeMode;
    break;
    }  
    return E_OK;
}

static Std_ReturnType HWOut1_WelcomeGoodbye(uint8 start,uint8 timebase)
{
    static pr_ChargeStep_t Step=step1;
    static uint16 runtime=0;
    if(start==DYN_OFF)
    {
        Step=step1;
    }
/* run over */
    if(HWOut_WelGdy_From_Parameter[HWOUT1][Step].ConTiPrm==0) 
    {
        return E_NOT_OK;
    }
    Interface_StarsLight_Ctrl(HWOUT1,HWOut_WelGdy_From_Parameter[HWOUT1][Step].Pwmper);
    runtime+=timebase;
    if(runtime>=HWOut_WelGdy_From_Parameter[HWOUT1][Step].ConTiPrm)
    {
        runtime=0;
        Step++;
    }
    return E_OK;
}

static Std_ReturnType HWOut2_WelcomeGoodbye(uint8 start,uint8 timebase)
{
    static pr_ChargeStep_t Step=step1;
    static uint16 runtime=0;
    if(start==DYN_OFF)
    {
        Step=step1;
    }
/* run over */
    if(HWOut_WelGdy_From_Parameter[HWOUT2][Step].ConTiPrm==0) 
    {
        return E_NOT_OK;
    }
    Interface_StarsLight_Ctrl(HWOUT2,HWOut_WelGdy_From_Parameter[HWOUT2][Step].Pwmper);
    runtime+=timebase;
    if(runtime>=HWOut_WelGdy_From_Parameter[HWOUT2][Step].ConTiPrm)
    {
        runtime=0;
        Step++;
    }
    return E_OK;
}

void DynLight_CloseAllBasicLightChannel(void)
{
    E_ChannelID id=ChannelID1;
    Pwm_HLCtrl_Disable();
    Port_CH2_Disable();  
    Port_CH2Alt_Disable();
    for(id=ChannelID1;id<CHANNEL_NUM;id++)
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
    SetLgtStsFb_WELC(STS_ON); //return welcome on status 
    SetLgtStsFb_Fog (STS_OFF);
}
/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/

Std_ReturnType WelGdyRunFunction(uint8 timebase)
{
    static uint8 flag_get_parameter=0;
    static uint8 FirstRunOrNot=0;
    E_ChannelID id=ChannelID1;
    uint8 SwitchHb=0;
    static uint8 NoRunWelGdy=0,WelGdyRunning=0;
    uint8 WelGdyRunOver=0;
    SwitchHb=Lighting_GetAct(E_HighBeam);
    if((SwitchHb==ACT_ON)&&(WelGdyRunning==1))
    {
        NoRunWelGdy=1;
    }
    else if((SwitchHb==ACT_OFF)&&(GetLgtStsEna_WELC()==0)&&(GetLgtStsEna_GDY()==0))
    {
        NoRunWelGdy=0;
    }
    if((GetLgtStsEna_WELC()==0)&&(GetLgtStsEna_GDY()==0))
    {
        WelGdyRunning=0;
        if(flag_get_parameter!=NODYN) //need to set all channel close
        {
            Pwm_HLCtrl_Disable();
            Port_CH2_Disable();  
            Port_CH2Alt_Disable();
            for(id=ChannelID1;id<CHANNEL_NUM;id++)
            {
                Interface_ChannelClose(id);
                Reset_ChannelAllError(id); //clear the error of dyn cause 
            } 
        }
        flag_get_parameter=NODYN;
        SetLgtStsFb_WELC(STS_OFF);
        return E_NOT_OK;
    }

    if(NoRunWelGdy==1)
    {
        return E_NOT_OK;
    }
/* the first run in,need to close all light, set the status to off, and get the parameters */
    if((GetLgtStsEna_WELC()==1)&&(flag_get_parameter!=WELRUN))
    {
        WelGdyRunning=1;
        flag_get_parameter=WELRUN;
        FirstRunOrNot=DYN_OFF;
        DynLight_CloseAllBasicLightChannel();  //close all channel and status
        GroupWelcome1_Get_Parameter();//get parameter
        GroupHWOutWel_Get_Parameter();
        SetLgtStsFb_WELC(STS_ON);
    }
    else if((GetLgtStsEna_GDY()==1)&&(flag_get_parameter!=GDYRUN))
    {
        WelGdyRunning=1;
        flag_get_parameter=GDYRUN;
        FirstRunOrNot=DYN_OFF;
        DynLight_CloseAllBasicLightChannel();
        GroupWelcome2_Get_Parameter();
        GroupHWOutGby_Get_Parameter();
        SetLgtStsFb_WELC(STS_ON);
    }

    WelGdyRunOver+=Group1_WelcomeGoodbye(FirstRunOrNot,timebase);
    WelGdyRunOver+=Group2_WelcomeGoodbye(FirstRunOrNot,timebase);
    WelGdyRunOver+=Group3_WelcomeGoodbye(FirstRunOrNot,timebase);
    WelGdyRunOver+=Group4_WelcomeGoodbye(FirstRunOrNot,timebase);
    WelGdyRunOver+=Group5_WelcomeGoodbye(FirstRunOrNot,timebase);
    WelGdyRunOver+=Group6_WelcomeGoodbye(FirstRunOrNot,timebase);
    WelGdyRunOver+=HWOut1_WelcomeGoodbye(FirstRunOrNot,timebase);
    WelGdyRunOver+=HWOut2_WelcomeGoodbye(FirstRunOrNot,timebase);
    FirstRunOrNot=DYN_ON;

    if((((GetLgtStsEna_WELC()==1)&&(flag_get_parameter==WELRUN))||((GetLgtStsEna_GDY()==1)&&(flag_get_parameter==GDYRUN)))&&(WelGdyRunOver>=6))
    {/* run over,status = OFF */
        SetLgtStsFb_WELC(STS_OFF);
    }
    return E_OK;
}
Std_ReturnType PosDynRunFunction(uint8 timebase)
{
    static uint8 flag_get_parameter=0;
    static uint8 FirstRunOrNot=0;
    E_ChannelID id=ChannelID1;
    uint8 SwitchOnPOS=0;
    uint8 WelGdyRunOver=0;
    static uint16 PosRunTime=0;
/* welcome > gby > pos dyn */
    if((GetLgtStsEna_WELC()!=0)&&(GetLgtStsEna_GDY()!=0))
    {
        return E_NOT_OK;
    }
    if(GetLgtStsEna_Charge()==0)
    {
        PosRunTime=0;
        if(flag_get_parameter!=NODYN) //need to set all channel close
        {
            Pwm_HLCtrl_Disable();
            Port_CH2_Disable();  
            Port_CH2Alt_Disable();
            for(id=ChannelID1;id<CHANNEL_NUM;id++)
            {
                Interface_ChannelClose(id);
                Reset_ChannelAllError(id); //clear the error of dyn cause 
            } 
        }
        flag_get_parameter=NODYN;
        SetLgtStsFb_WELC(STS_OFF);
        SwitchOnPOS=Lighting_GetAct(E_PositionLight);
        if(SwitchOnPOS==ACT_OFF)//no posdyn,no pos
        {
            SetLgtStsFb_POS(STS_OFF);
        }
        return E_NOT_OK;
    }

/* the first run in,need to close all light, set the status to off, and get the parameters */
    if((GetLgtStsEna_Charge()==1)&&(flag_get_parameter!=POSDYNRUN))
    {
        flag_get_parameter=POSDYNRUN;
        FirstRunOrNot=DYN_OFF;
        DynLight_CloseAllBasicLightChannel();
        GroupCharge_Get_Parameter();
        SetLgtStsFb_WELC(STS_OFF);
        SetLgtStsFb_POS(STS_ON);
    }

    WelGdyRunOver+=Group1_WelcomeGoodbye(FirstRunOrNot,timebase);
    WelGdyRunOver+=Group2_WelcomeGoodbye(FirstRunOrNot,timebase);
    WelGdyRunOver+=Group3_WelcomeGoodbye(FirstRunOrNot,timebase);
    WelGdyRunOver+=Group4_WelcomeGoodbye(FirstRunOrNot,timebase);
    WelGdyRunOver+=Group5_WelcomeGoodbye(FirstRunOrNot,timebase);
    WelGdyRunOver+=Group6_WelcomeGoodbye(FirstRunOrNot,timebase);
    // WelGdyRunOver+=HWOut1_WelcomeGoodbye(FirstRunOrNot,timebase);
    // WelGdyRunOver+=HWOut2_WelcomeGoodbye(FirstRunOrNot,timebase);
    FirstRunOrNot=DYN_ON;

    if((((GetLgtStsEna_WELC()==1)&&(flag_get_parameter==WELRUN))||((GetLgtStsEna_GDY()==1)&&(flag_get_parameter==GDYRUN)))&&(WelGdyRunOver>=6))
    {/* run over,status = OFF */
        SetLgtStsFb_WELC(STS_OFF);
    }
    if(flag_get_parameter==POSDYNRUN)
    {/* RUN time > 30s,close the posdyn */ 
        PosRunTime+=timebase;          
        if(PosRunTime<CHARGE_TOTAL_TIME)
        {
            if(WelGdyRunOver>=6)
            {
                FirstRunOrNot=DYN_OFF;
            }
        }
        else
        {
            PosRunTime=CHARGE_TOTAL_TIME;
        }
    }
    return E_OK;
}



Std_ReturnType DynLight_MainFunction(uint8 timebase)
{
    WelGdyRunFunction(timebase);
    PosDynRunFunction(timebase);
}

