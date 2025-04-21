#include "HcmPlatform.h"
#include "Lighting.h"
#include "LinManager.h"
#include "Ex_SleepWakeup.h"
#include "Dio_Service.h"
#include "Pwm_Service.h"
#include "Parameter_Interface.h"
#include "OUVDerate_Interface.h"
#include "DerateRatioManager_Interface.h"
#include "Channel_Interface.h"
#include "HB.h"
#include "LB.h"
#include "TurnIndicator.h"
#include "DRL.h"
#include "POS.h"
#include "WelGdy.h"
#include "FrontCrossLamp.h"
#include "FogLamp.h"
#include "GrilleLamp.h"
#include "LogoLamp.h"
#include "CorneringLamp.h"
#include "EOL_Interface.h"
#include "Rte_Dcm_Callout.h"

#define LIGHT_MAX_NUM    12
uint16 CH_CurStatus[6]={0};              /* channel now status  */

uint8_t Interface_GetChannelDerateRatio(E_ChannelID id);
typedef struct
{
    uint16 Ch_NormalCur;                    /*Para table Normal Current*/
    uint8 Ch_Pwm;
} PR_CHANNEL_CUR;

typedef struct 
{
    uint16  pr_onDelay[LIGHT_MAX_NUM];     /* delay on time       */
    uint16  pr_offDelay[LIGHT_MAX_NUM] ;   /* delay off time      */
    uint16  pr_OnRamp[LIGHT_MAX_NUM]  ;    /*  ramp on time       */
    uint16  pr_OffRamp[LIGHT_MAX_NUM] ;    /* ramp off time       */
    uint8   in_Act_cur[LIGHT_MAX_NUM] ;    /* cur in act signal   */
    uint16  st_msAct[LIGHT_MAX_NUM]   ;    /* time of act         */
    S_LgtFuncEna_t  st_LgtEna;             /* lighting enable     */
    uint8   st_LgtAct[LIGHT_MAX_NUM];      /* lighting act        */
    S_LgtStsFb_t    st_LgtSts;             /* lighting status     */
    S_LgtFuncEna_t  st_LgtDer;             /* light forbid status */
    uint16 chnMask;                        /* channel mask        */
    PR_CHANNEL_CUR pr_channel_cur[MAX_CHANNLE_NUM];   /* parameter channel current */
}S_LightingCtl_t;
static S_LightingCtl_t lgtctl;

typedef struct 
{
    uint8 pwm_Ramp[LIGHT_MAX_NUM];             /*   RAMP PWM       */
    uint16 st_msRampRun[LIGHT_MAX_NUM] ;       /*   RAMP RUN TIME  */
}S_Pamp_Pwm;
static S_Pamp_Pwm gs_ramp_pwm;

void SetLgtStsFb_LB  (E_LgtSts_t sts){ lgtctl.st_LgtSts.Bits.StsLB   = sts; }
void SetLgtStsFb_TI  (E_LgtSts_t sts){ lgtctl.st_LgtSts.Bits.StsTI   = sts; }
void SetLgtStsFb_POS (E_LgtSts_t sts){ lgtctl.st_LgtSts.Bits.StsPOS  = sts; }
void SetLgtStsFb_HB  (E_LgtSts_t sts){ lgtctl.st_LgtSts.Bits.StsHB   = sts; }
void SetLgtStsFb_DRL (E_LgtSts_t sts){ lgtctl.st_LgtSts.Bits.StsDRL  = sts; }
void SetLgtStsFb_CORN(E_LgtSts_t sts){ lgtctl.st_LgtSts.Bits.StsCORN = sts; }
void SetLgtStsFb_CROS(E_LgtSts_t sts){ lgtctl.st_LgtSts.Bits.StsCROS = sts; }
void SetLgtStsFb_WELC(E_LgtSts_t sts){ lgtctl.st_LgtSts.Bits.StsWELC = sts; }
void SetLgtStsFb_Fog (E_LgtSts_t sts){ lgtctl.st_LgtSts.Bits.StsFOG  = sts; }

uint8 GetLgtStsFb_LB  (void){return lgtctl.st_LgtSts.Bits.StsLB   ; }
uint8 GetLgtStsFb_TI  (void){return lgtctl.st_LgtSts.Bits.StsTI   ; }
uint8 GetLgtStsFb_POS (void){return lgtctl.st_LgtSts.Bits.StsPOS  ; }
uint8 GetLgtStsFb_HB  (void){return lgtctl.st_LgtSts.Bits.StsHB   ; }
uint8 GetLgtStsFb_DRL (void){return lgtctl.st_LgtSts.Bits.StsDRL  ; }
uint8 GetLgtStsFb_CORN(void){return lgtctl.st_LgtSts.Bits.StsCORN ; }
uint8 GetLgtStsFb_CROS(void){return lgtctl.st_LgtSts.Bits.StsCROS ; }
uint8 GetLgtStsFb_WELC(void){return lgtctl.st_LgtSts.Bits.StsWELC ; }
uint8 GetLgtStsFb_Fog (void){return lgtctl.st_LgtSts.Bits.StsFOG  ; }

void SetLgtStsEna_DynLight(uint8 WelEna,uint8 GdyEna,uint8 ChargeEna)
{
    lgtctl.st_LgtEna.EnaWELC = WelEna ; 
    lgtctl.st_LgtEna.EnaGoodBye = GdyEna ;
    lgtctl.st_LgtEna.EnaPOS_Dyn = ChargeEna ;
}

uint8 GetLgtStsEna_WELC  (void){return lgtctl.st_LgtEna.EnaWELC      ;   }
uint8 GetLgtStsEna_GDY   (void){return lgtctl.st_LgtEna.EnaGoodBye   ;   }
uint8 GetLgtStsEna_Charge(void){return lgtctl.st_LgtEna.EnaPOS_Dyn   ;   }

/*get the act status*/
uint8 Lighting_GetAct(Light_Functions lf)
{
	return lgtctl.st_LgtAct[lf];
}

static void ChnCurrentSet(void)
{
    E_ChannelID id=ChannelID1;
    uint16_t chnCurr;   /* channel current  */
    uint8_t  derate;    /* channel derate % */
    for (id=ChannelID1; id<E_TurnIndicator_Act; id++)
    {
        lgtctl.chnMask |= GetChannelMaskByLightFunction((Light_Functions)id);
    }

/* set the channel current */
    for (id=ChannelID1; id<MAX_CHANNLE_NUM; id++)
    {
        if ((lgtctl.chnMask & (0x0001 << id)) != 0)
        {           
/*BIN > DID > parameter  CTS_V1.0.4_4.1.2 */
            chnCurr = Interface_GetChannelBinCurrent((E_ChannelID)id);
            if (chnCurr == INVALIED_CURRENT)
            {
                chnCurr = Interface_GetChannelDidConfigCurrent((E_ChannelID)id);
                if (chnCurr == INVALIED_CURRENT)
                {
                    chnCurr = Interface_GetChannelParamTableNormalCurrent((E_ChannelID)id);
                }
            }
/* the channel derate */
            derate = Interface_GetChannelDerateRatio((E_ChannelID)id);

            if (derate == 0) 
            {
                chnCurr = 0;
            }
            else if (derate < 100) 
            { 
                chnCurr = ((uint32_t)chnCurr)*((uint32_t)derate) / ((uint32_t)100); 
                ChannelDiagEnable(id,0);
            }
            else
            {
                ChannelDiagEnable(id,1); //diag enable
            }
            lgtctl.pr_channel_cur[id].Ch_NormalCur = chnCurr;

            /* if cur<100mA，need to change PWM */
            if ((lgtctl.pr_channel_cur[id].Ch_NormalCur > 0) &&
                (lgtctl.pr_channel_cur[id].Ch_NormalCur < 100))
            {
                lgtctl.pr_channel_cur[id].Ch_Pwm= lgtctl.pr_channel_cur[id].Ch_NormalCur;
                lgtctl.pr_channel_cur[id].Ch_NormalCur = 100;
            }
            else
            {
                lgtctl.pr_channel_cur[id].Ch_Pwm = 100;
            }
        }
    }
}

static void Derate_handle(uint8 timebase)
{
    DerateRatioManagerFuncmain(timebase); //derate calculate
    ChnCurrentSet();              //get current
}

/* function: get the channel run current */
uint16 Interface_GetSignal_ChannelCurrent(uint8 id)
{
    return lgtctl.pr_channel_cur[id].Ch_NormalCur;
}

/* function: get the channel run pwm */
uint8 Interface_GetSignal_ChannelPwm(uint8 id)
{
    return lgtctl.pr_channel_cur[id].Ch_Pwm;
}

void Lighting_Init(void)
{
    Light_Functions E_Light= E_LowBeam;
    for(E_Light=E_LowBeam;E_Light<=E_AssistantLight;E_Light++)
    {
        lgtctl.pr_onDelay[E_Light]  = Get_pLedONDelay(E_Light);
        lgtctl.pr_offDelay[E_Light] = Get_pLedOFFDelay(E_Light);
        lgtctl.pr_OnRamp[E_Light]   = Get_pLedOnRampTi(E_Light);
        lgtctl.pr_OffRamp[E_Light]  = Get_pLedOffRampTi(E_Light);
    }
}

uint8 Ramponoff_run(uint16 ms,uint16 rampon,uint8 ton,E_LgtAct_t flag)
{
    uint8 per=0;
    if(flag==ACT_ON)
    {
        if(ton<rampon) 
        {
            ton+=ms;
            per=100/(rampon)*ton;
        }
        else per=100;
    }
    else
    {
        if(ton<(rampon-ms))
        {
            ton+=ms;
            per=100-100/(rampon)*ton;
        }
        else per=0;
    }
    return per;
}

//get lin signal ,delay on time,boost enable,dyn enable
static void Input_DelayFun(uint16 ms)
{
    uint16 top = 0xFFFF - ms;
    uint8 linrx=0;
    U_E2EErrorFlag E2eError;
//delay on ;delay off time++
    Light_Functions lf= E_LowBeam;
    for(lf=E_LowBeam;lf<E_TurnIndicator_Act;lf++)
    {
        if (lgtctl.st_msAct[lf] <= top) { lgtctl.st_msAct[lf] += ms; }
// lin rx signal not = act signal ,run time=0;
        linrx=Lighting_GetLinCtrl(lf);
        if((linrx != lgtctl.in_Act_cur[lf]))     
        { 
            lgtctl.st_msAct[lf] = 0; 
            gs_ramp_pwm.st_msRampRun[lf]=0; 
        }
        lgtctl.in_Act_cur[lf]=Lighting_GetLinCtrl(lf);
    }
    lgtctl.in_Act_cur[E_TurnIndicator_Act]=Lighting_GetLinCtrl(E_TurnIndicator_Act);
    E2eError=Rbk_U_E2EErrorFlag();

    if((lgtctl.in_Act_cur[E_LowBeam]==0)&&(lgtctl.in_Act_cur[E_HighBeam]==0)&&(lgtctl.in_Act_cur[E_DaytimeRunningLight]==0)&&
    (lgtctl.in_Act_cur[E_PositionLight]==0)&&(lgtctl.in_Act_cur[E_TurnIndicator]==0)&&(lgtctl.in_Act_cur[E_CorneringLight]==0)&&
    (lgtctl.in_Act_cur[E_FogLamp]==0)&&(lgtctl.in_Act_cur[E_LogoLamp]==0)&&(lgtctl.in_Act_cur[E_FrontCrossLamp]==0)&&
    (lgtctl.in_Act_cur[E_GrilleLamp]==0)&&(lgtctl.in_Act_cur[E_AssistantLight]==0)&&(lgtctl.in_Act_cur[E_TurnIndicator_Act]==0)
    #if APP_E2E_FUN
    && ((E2eError.bits.ActnOfLedLoBeamCntErr==0) && (E2eError.bits.ActnOfLedLoBeamCrcErr==0) && (E2eError.bits.ActnOfLedLoBeamTimeout==0)) //go to safety functional 
    && ((E2eError.bits.ActvnOfIndcrTimeout==0) && (E2eError.bits.ActvnOfIndcrCrcErr==0) && (E2eError.bits.LvlgSwtSetReqCntErr==0))
    #endif
    )//
    {
        if((Interface_GetSignal_ActvnOfWelcomeLi()==1)&&(Get_pWelGbytyp_B()==1))
        {
            SetLgtStsEna_DynLight(ACT_ON,ACT_OFF,ACT_OFF);//SET WELCOME1 ON
            Boost_Enable();
            ResetAWakeTime();
        }
        else if((Interface_GetSignal_ActvnOfGoodByeLi()==1)&&(Get_pWelGbytyp_B()==1))
        {
            SetLgtStsEna_DynLight(ACT_OFF,ACT_ON,ACT_OFF);//SET GOODBYE ON
            Boost_Enable();
            ResetAWakeTime();
        }
        else if(Interface_GetSignal_PosnLampDyn()==1)
        {
            SetLgtStsEna_DynLight(ACT_OFF,ACT_OFF,ACT_ON);//SET CHARGE ON
            Boost_Enable();
            ResetAWakeTime();
        }
        else
        {//no e2e err ;no light signal
            SetLgtStsEna_DynLight(ACT_OFF,ACT_OFF,ACT_OFF);//SET all OFF
            Boost_Disable();
        }
    }
    else 
    {
        SetLgtStsEna_DynLight(ACT_OFF,ACT_OFF,ACT_OFF);//SET all ON
        Boost_Enable();
        ResetAWakeTime();
    }
}

/* ramp on off function */
static void Input_RampFun(uint16 ms)
{
    uint8 In_Act_Cur=ACT_OFF;
    Light_Functions Lf=E_LowBeam;
/* Ramp_On calculate pwm */
    for(Lf=E_LowBeam;Lf<=E_AssistantLight;Lf++)
    {
        In_Act_Cur=lgtctl.in_Act_cur[Lf];
    
        if ((In_Act_Cur != ACT_OFF)&& (lgtctl.st_msAct[Lf] >= lgtctl.pr_onDelay[Lf]))  //delay time finished,into ramp on function
        {
            lgtctl.st_LgtAct[Lf]=ACT_ON;
            if(gs_ramp_pwm.st_msRampRun[Lf]<lgtctl.pr_OnRamp[Lf])//ramp on
            {
                gs_ramp_pwm.st_msRampRun[Lf] += ms;
                gs_ramp_pwm.pwm_Ramp[Lf] = 100*gs_ramp_pwm.st_msRampRun[Lf]/lgtctl.pr_OnRamp[Lf];
            }
            else gs_ramp_pwm.pwm_Ramp[Lf]=100;
        }
    }
/* Ramp off calculate PWM */
    for(Lf=E_LowBeam;Lf<=E_AssistantLight;Lf++)
    {
        In_Act_Cur=lgtctl.in_Act_cur[Lf];
        if ((In_Act_Cur == ACT_OFF) && (lgtctl.st_msAct[Lf]   >= lgtctl.pr_offDelay[Lf]  )) 
        { 
            if(gs_ramp_pwm.st_msRampRun[Lf]<lgtctl.pr_OffRamp[Lf])//渐灭
            {
                gs_ramp_pwm.st_msRampRun[Lf] += ms;
                gs_ramp_pwm.pwm_Ramp[Lf] = 100-(100*gs_ramp_pwm.st_msRampRun[Lf]/lgtctl.pr_OffRamp[Lf]);
            }
            else 
            {
                lgtctl.st_LgtAct[Lf]=ACT_OFF;
            }
        }
    }
    lgtctl.st_LgtAct[E_TurnIndicator_Act]=lgtctl.in_Act_cur[E_TurnIndicator_Act];
}
static void Input_DelayRampFun(uint16 ms)
{
    Input_DelayFun(ms);
    Input_RampFun(ms);
}

Std_ReturnType Lighting_SetPwmRamp(Light_Functions lf)
{
    return gs_ramp_pwm.pwm_Ramp[lf];
}


uint32 Lighting_Rek_Fun(void)
{
    return lgtctl.st_LgtSts.Light_Status;
}

void Light_Run(uint8 timebase)
{
    Std_ReturnType reval=E_OK;
    DynLight_MainFunction(timebase);
/*************************************LB HB**CH1 CH1_Tap****************************************************/
    HB_RunMainFun(&CH_CurStatus[0]); //HB light main function
    LB_RunMainFun(&CH_CurStatus[0]);
/*************************************pos drl ti******************************************************/
    TI_RunMainFun(&CH_CurStatus[0]);
    POS_RunMainFun(&CH_CurStatus[0]); 
    DRL_RunMainFun(&CH_CurStatus[0]);    

    CROS_RunMainFun(&CH_CurStatus[0]);   
    FogLamp_RunMainFun(&CH_CurStatus[0]);
    GrilleLamp_RunMainFun(&CH_CurStatus[0]);
    LogoLamp_RunMainFun(&CH_CurStatus[0]);
    CornLamp_RunMainFun(&CH_CurStatus[0]);
/**********************************share channel close************************************************** */
    if((GetLgtStsEna_WELC()==0)&&(GetLgtStsEna_GDY()==0)) //no welcome goodbye
    {
        if((0==CH_CurStatus[ChannelID1_Tap])&&(0==CH_CurStatus[ChannelID1])) //CH1 CH1Tap Close the channel 
        { 
            Interface_ChannelClose(ChannelID1);
            Interface_ChannelClose(ChannelID1_Tap);
        }
/* the code for CH1 close ,short to VCC */
        if((0!=CH_CurStatus[ChannelID1_Tap])&&(0==CH_CurStatus[ChannelID1]))
        {
            Pwm_HLCtrl_Disable();
        }
        else
        {
            Pwm_HLCtrl_Enable();
        }
        if(GetLgtStsEna_Charge()==0)   //no charge
        {
            if(( CH_CurStatus[ChannelID2]==0)&&(CH_CurStatus[ChannelID2_Alt]==0))
            {
                Interface_ChannelClose(ChannelID2);
                Interface_ChannelClose(ChannelID2_Alt);
            }
        }     
    }
}

/*light all light function*/
Std_ReturnType Light_Manager(uint8 timebase)
{  
    uint8 ouv_pwm=0;
    E_ChannelID ch=ChannelID1;
    ouv_pwm=Interface_GetDerateRatioOfOUV(); //get the power derate
    if(ouv_pwm==0) //close the light
    {      
        for (ch = ChannelID1; ch < CHANNEL_NUM; ch++)
        {
            Interface_ChannelClose(ch); //close the buck
        }
        Boost_Disable(); //close the boost
    }
    else
    {
        if(TRUE == Rte_Dcm_GetEolSessionStatus) //EOL APP
        {
            Boost_Enable();
            EOL_Light_Main();
        }
        else
        {
            Input_DelayRampFun(timebase);//delay + ramp 
            Derate_handle(timebase);
            Light_Run(timebase);
        }
    }
    return E_OK;
}




