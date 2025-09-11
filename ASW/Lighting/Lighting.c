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
#include "StarsLight.h"
#include "EOL_Interface.h"
#include "Rte_Dcm_Callout.h"
#include "ParaMgr.h"
#include "ADS.h"
#define LIGHT_MAX_NUM    12

uint8 BOOST_Enable_Flag=0;
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

typedef union
{
    uint8 DTC;
    struct
    {
        uint8 DTC_LB:1;
        uint8 DTC_HB:1;
        uint8 DTC_POS:1;
        uint8 DTC_DRL:1;
        uint8 DTC_IND:1;
        uint8 DTC_FOG:1;
        uint8 DTC_CROS:1;
        uint8 DTC_CORN:1;
    } bits;

} DTCErrorStatusStrut;

static S_LightingCtl_t lgtctl;
static DTCErrorStatusStrut DTCErrorStatus;


typedef struct 
{
    uint8 pwm_Ramp[LIGHT_MAX_NUM];             /*   RAMP PWM       */
    uint16 st_msRampRun[LIGHT_MAX_NUM] ;       /*   RAMP RUN TIME  */
}S_Pamp_Pwm;
static S_Pamp_Pwm gs_ramp_pwm;

void SetLgtStsFb_Status(E_LgtSts_t sts,Light_Functions lightType)
{
    switch (lightType)
    {
        case E_LowBeam://LB
            lgtctl.st_LgtSts.Bits.StsLB   = sts;
            break;
        case E_HighBeam://HB
            lgtctl.st_LgtSts.Bits.StsHB   = sts; 
            break;
        case E_DaytimeRunningLight://DRL
            lgtctl.st_LgtSts.Bits.StsDRL  = sts;
            break;
        case E_PositionLight://POS
            lgtctl.st_LgtSts.Bits.StsPOS  = sts; 
            break;
        case E_TurnIndicator://IND
            lgtctl.st_LgtSts.Bits.StsTI   = sts;
            break;
        case E_CorneringLight://corner
            lgtctl.st_LgtSts.Bits.StsCORN = sts;
            break;
        case E_FogLamp://FOG
            lgtctl.st_LgtSts.Bits.StsFOG  = sts;
            break;
        case E_FrontCrossLamp://cross
            lgtctl.st_LgtSts.Bits.StsCROS = sts; 
            break;
        case 9://welcome
            lgtctl.st_LgtSts.Bits.StsWELC = sts; 
        default:
            break;
    } 
}

void SetDTCGroup_LB(E_DTCsts sts)
{
    DTCErrorStatus.bits.DTC_LB = sts;
}
void SetDTCGroup_HB(E_DTCsts sts)
{
    DTCErrorStatus.bits.DTC_HB = sts;
}void SetDTCGroup_POS(E_DTCsts sts)
{
    DTCErrorStatus.bits.DTC_POS = sts;
}void SetDTCGroup_DRL(E_DTCsts sts)
{
    DTCErrorStatus.bits.DTC_DRL = sts;
}
void SetDTCGroup_IND(E_DTCsts sts)
{
    DTCErrorStatus.bits.DTC_IND = sts;
}
void SetDTCGroup_FOG(E_DTCsts sts)
{
    DTCErrorStatus.bits.DTC_FOG = sts;
}
void SetDTCGroup_CORN(E_DTCsts sts)
{
    DTCErrorStatus.bits.DTC_CORN = sts;
}
void SetDTCGroup_CROS(E_DTCsts sts)
{
    DTCErrorStatus.bits.DTC_CROS = sts;
}
void SetLgtStsEna_DynLight(uint8 WelEna,uint8 GdyEna,uint8 ChargeEna)
{
    lgtctl.st_LgtEna.EnaWELC = WelEna ; 
    lgtctl.st_LgtEna.EnaGoodBye = GdyEna ;
    lgtctl.st_LgtEna.EnaPOS_Dyn = ChargeEna ;
}

uint8 GetLgtStsFb(Light_Functions lightType)
{
    uint8 ret = 0;
    switch (lightType)
    {
        case E_LowBeam://LB
            ret = lgtctl.st_LgtSts.Bits.StsLB;
            break;
        case E_HighBeam://HB
            ret = lgtctl.st_LgtSts.Bits.StsHB   ; 
            break;
        case E_DaytimeRunningLight://DRL
            ret = lgtctl.st_LgtSts.Bits.StsDRL  ;
            break;
        case E_PositionLight://POS
            ret = lgtctl.st_LgtSts.Bits.StsPOS  ; 
            break;
        case E_TurnIndicator://IND
            ret = lgtctl.st_LgtSts.Bits.StsTI ;
            break;
        case E_CorneringLight://corner
            ret = lgtctl.st_LgtSts.Bits.StsCORN;
            break;
        case E_FogLamp://FOG
            ret = lgtctl.st_LgtSts.Bits.StsFOG;
            break;
        case E_FrontCrossLamp://cross
            ret = lgtctl.st_LgtSts.Bits.StsCROS; 
            break;
        case 9://welcome
            ret = lgtctl.st_LgtSts.Bits.StsWELC; 
        default:
            break;
    }
    return ret;
}


uint8 GetDTCGroup_LB(void)
{
    return DTCErrorStatus.bits.DTC_LB;
}
uint8 GetDTCGroup_HB(void)
{
    return DTCErrorStatus.bits.DTC_HB;
}
uint8 GetDTCGroup_POS(void)
{
    return DTCErrorStatus.bits.DTC_POS;
}
uint8 GetDTCGroup_DRL(void)
{
    return DTCErrorStatus.bits.DTC_DRL;
}
uint8 GetDTCGroup_FOG(void)
{
    return DTCErrorStatus.bits.DTC_FOG;
}
uint8 GetDTCGroup_IND(void)
{
    return DTCErrorStatus.bits.DTC_IND;
}
uint8 GetDTCGroup_CROS(void)
{
    return DTCErrorStatus.bits.DTC_CROS;
}
uint8 GetDTCGroup_CORN(void)
{
    return DTCErrorStatus.bits.DTC_CORN;
}
uint8 GetLgtStsEna_WELC  (void)
{
    return lgtctl.st_LgtEna.EnaWELC;   
}
uint8 GetLgtStsEna_GDY   (void)
{
    return lgtctl.st_LgtEna.EnaGoodBye;  
}
uint8 GetLgtStsEna_Charge(void)
{
    return lgtctl.st_LgtEna.EnaPOS_Dyn;   
}

void ClearDTCGroup(void)
{
    DTCErrorStatus.DTC = 0;
}

/*get the act status*/
uint8 Lighting_GetAct(Light_Functions lf)
{
	return lgtctl.st_LgtAct[lf];
}

static void ChnCurrentSet(void)
{
    E_ChannelID id=ChannelID1;
    uint16_t chnCurr = 0;   /* channel current  */
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
            
            if(ParaMgr_CfgPrm_Usage_B==HWTEST_CODE)
            {
                chnCurr = Interface_GetChannelParamTableNormalCurrent((E_ChannelID)id);
            }
            else if(ParaMgr_CfgPrm_Usage_B==NORMAL_CODE)
            {
                /*BIN > DID > parameter  CTS_V1.0.4_4.1.2 */
                chnCurr = Interface_GetChannelBinCurrent((E_ChannelID)id);
                if (chnCurr == INVALIED_CURRENT)
                {
                    chnCurr = Interface_GetChannelDidConfigCurrent((E_ChannelID)id);
                    if (chnCurr == 0xFFF)
                    {
                        chnCurr = Interface_GetChannelParamTableNormalCurrent((E_ChannelID)id);
                    }
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
            }
            lgtctl.pr_channel_cur[id].Ch_NormalCur = chnCurr;

            /* if cur<100mA，need to change PWM */
            if ((lgtctl.pr_channel_cur[id].Ch_NormalCur >= 0) &&
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
    for(E_Light=E_LowBeam;E_Light<=E_ADSLight;E_Light++)
    {
        lgtctl.pr_onDelay[E_Light]  = Get_pLedONDelay(E_Light);
        lgtctl.pr_offDelay[E_Light] = Get_pLedOFFDelay(E_Light);
        lgtctl.pr_OnRamp[E_Light]   = Get_pLedOnRampTi(E_Light);
        lgtctl.pr_OffRamp[E_Light]  = Get_pLedOffRampTi(E_Light);
    }
}

static void Set_DynSignal(void)
{
    U_E2EErrorFlag E2eError;
    if((lgtctl.in_Act_cur[E_LowBeam]==0)&&(lgtctl.in_Act_cur[E_HighBeam]==0)&&(lgtctl.in_Act_cur[E_DaytimeRunningLight]==0)&&
    (lgtctl.in_Act_cur[E_PositionLight]==0)&&(lgtctl.in_Act_cur[E_TurnIndicator]==0)&&(lgtctl.in_Act_cur[E_CorneringLight]==0)&&
    (lgtctl.in_Act_cur[E_FogLamp]==0)&&(lgtctl.in_Act_cur[E_LogoLamp]==0)&&(lgtctl.in_Act_cur[E_FrontCrossLamp]==0)&&
    (lgtctl.in_Act_cur[E_GrilleLamp]==0)&&(lgtctl.in_Act_cur[E_AssistantLight]==0)&&(lgtctl.in_Act_cur[E_TurnIndicator_Act]==0)
    &&(lgtctl.in_Act_cur[E_ADSLight]==0)
    #if APP_E2E_FUN
    && ((E2eError.bits.ActnOfLedLoBeamCntErr==0) && (E2eError.bits.ActnOfLedLoBeamCrcErr==0) && (E2eError.bits.ActnOfLedLoBeamTimeout==0)) //go to safety functional 
    && ((E2eError.bits.ActvnOfIndcrTimeout==0) && (E2eError.bits.ActvnOfIndcrCrcErr==0) && (E2eError.bits.LvlgSwtSetReqCntErr==0))
    #endif
    )
    {
        if((Interface_GetSignal_ActvnOfWelcomeLi()==1)&&(Get_pWelGbytyp_B()==1))
        {
            SetLgtStsEna_DynLight(ACT_ON,ACT_OFF,ACT_OFF);//SET WELCOME1 ON
            BOOST_Enable_Flag=1;
        }
        else if((Interface_GetSignal_ActvnOfGoodByeLi()==1)&&(Get_pWelGbytyp_B()==1))
        {
            SetLgtStsEna_DynLight(ACT_OFF,ACT_ON,ACT_OFF);//SET GOODBYE ON
            BOOST_Enable_Flag=1;
        }
        else if(Interface_GetSignal_PosnLampDyn()==1)
        {
            SetLgtStsEna_DynLight(ACT_OFF,ACT_OFF,ACT_ON);//SET CHARGE ON
            BOOST_Enable_Flag=1;
        }
        else
        {//no e2e err ;no light signal
            SetLgtStsEna_DynLight(ACT_OFF,ACT_OFF,ACT_OFF);//SET all OFF
            BOOST_Enable_Flag=0;
        }
    }
/* TI>ADS>DRL>POS>dyn pos;cornering>dyn pos; logo>dyn pos */
    else if((lgtctl.in_Act_cur[E_DaytimeRunningLight]==0)&&(lgtctl.in_Act_cur[E_PositionLight]==0)&&(lgtctl.in_Act_cur[E_TurnIndicator]==0)&&
    (lgtctl.in_Act_cur[E_TurnIndicator_Act]==0)&&(lgtctl.in_Act_cur[E_CorneringLight]==0)&&(lgtctl.in_Act_cur[E_LogoLamp]==0)&&(lgtctl.in_Act_cur[E_ADSLight]==0)
    #if APP_E2E_FUN
    && ((E2eError.bits.ActnOfLedLoBeamCntErr==0) && (E2eError.bits.ActnOfLedLoBeamCrcErr==0) && (E2eError.bits.ActnOfLedLoBeamTimeout==0)) //go to safety functional 
    && ((E2eError.bits.ActvnOfIndcrTimeout==0) && (E2eError.bits.ActvnOfIndcrCrcErr==0) && (E2eError.bits.LvlgSwtSetReqCntErr==0))
    #endif
    )
    {
        if(Interface_GetSignal_PosnLampDyn()==1)
        {
            SetLgtStsEna_DynLight(ACT_OFF,ACT_OFF,ACT_ON);//SET CHARGE ON
            BOOST_Enable_Flag=1;
        }
        else if((lgtctl.in_Act_cur[E_HighBeam]==1)||(lgtctl.in_Act_cur[E_LowBeam]==1)||(lgtctl.in_Act_cur[E_FogLamp]==1)||(lgtctl.in_Act_cur[E_FrontCrossLamp]==1)||
        (lgtctl.in_Act_cur[E_GrilleLamp]==1)||(lgtctl.in_Act_cur[E_AssistantLight]==1))
        {
            SetLgtStsEna_DynLight(ACT_OFF,ACT_OFF,ACT_OFF);//SET all OFF
            BOOST_Enable_Flag=1;
        }
        else
        {//no e2e err ;no light signal
            SetLgtStsEna_DynLight(ACT_OFF,ACT_OFF,ACT_OFF);//SET all OFF
            BOOST_Enable_Flag=0;
        }
    } 
    else 
    {
        SetLgtStsEna_DynLight(ACT_OFF,ACT_OFF,ACT_OFF);//SET all ON
        BOOST_Enable_Flag=1;
    }
    if(lgtctl.in_Act_cur[E_HighBeam]==1)
    {
        SetWelGdyForbid(1);
    }
    else if((Interface_GetSignal_ActvnOfGoodByeLi()==0)&&(Interface_GetSignal_ActvnOfWelcomeLi()==0))
    {
        SetWelGdyForbid(0);
    }
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
    lgtctl.in_Act_cur[E_ADSLight]=Lighting_GetLinCtrl(E_ADSLight);
    lgtctl.in_Act_cur[E_TurnIndicator_Act]=Lighting_GetLinCtrl(E_TurnIndicator_Act);
    Rbk_U_E2EErrorFlag(&E2eError);
}

/* ramp on off function */
static void Input_RampFun(uint16 ms)
{
    uint8 In_Act_Cur=ACT_OFF;
    Light_Functions Lf=E_LowBeam;
/* Ramp_On calculate pwm */
    for(Lf=E_LowBeam;Lf<=E_ADSLight;Lf++)
    {
        In_Act_Cur=lgtctl.in_Act_cur[Lf];
    
        if ((In_Act_Cur != ACT_OFF)&& (lgtctl.st_msAct[Lf] >= lgtctl.pr_onDelay[Lf]))  /* delay time finished,into ramp on function */
        {
            if(Lf==E_ADSLight)
            {
                lgtctl.st_LgtAct[E_ADSLight]=lgtctl.in_Act_cur[E_ADSLight];
            }
            else
            {
                lgtctl.st_LgtAct[Lf]=ACT_ON;
            }
            if(gs_ramp_pwm.st_msRampRun[Lf]<lgtctl.pr_OnRamp[Lf])/* ramp on */
            {
                gs_ramp_pwm.st_msRampRun[Lf] += ms;
                gs_ramp_pwm.pwm_Ramp[Lf] = 100*gs_ramp_pwm.st_msRampRun[Lf]/lgtctl.pr_OnRamp[Lf];
            }
            else gs_ramp_pwm.pwm_Ramp[Lf]=100;
        }
    }
/* Ramp off calculate PWM */
    for(Lf=E_LowBeam;Lf<=E_ADSLight;Lf++)
    {
        In_Act_Cur=lgtctl.in_Act_cur[Lf];
        if ((In_Act_Cur == ACT_OFF) && (lgtctl.st_msAct[Lf]   >= lgtctl.pr_offDelay[Lf]  )) 
        { 
            if(gs_ramp_pwm.st_msRampRun[Lf]<lgtctl.pr_OffRamp[Lf])/* ramp off */
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
    Set_DynSignal();
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
    HB_RunMainFun(); //HB light main function
    LB_RunMainFun();
/*************************************pos drl ti******************************************************/
    TI_RunMainFun();
    POS_RunMainFun(); 
    DRL_RunMainFun();    

    CROS_RunMainFun();   
    FogLamp_RunMainFun();
    GrilleLamp_RunMainFun();
    LogoLamp_RunMainFun();
    CornLamp_RunMainFun();
    StarsLight_RunMainFun();
    ADS_RunMainFun();
/**********************************share channel close************************************************** */
    if((GetLgtStsEna_WELC()==0)&&(GetLgtStsEna_GDY()==0)) //no welcome goodbye
    {
        if((0==Interface_GetLightChannelStateSwitch(ChannelID1_Tap))&&(0==Interface_GetLightChannelStateSwitch(ChannelID1))) /* CH1 CH1Tap Close the channel */ 
        { 
            Interface_ChannelClose(ChannelID1);
            Interface_ChannelClose(ChannelID1_Tap);
        }
/* the code for CH1 close ,short to VCC */
        if((0!=Interface_GetLightChannelStateSwitch(ChannelID1_Tap))&&(0==Interface_GetLightChannelStateSwitch(ChannelID1)))
        {
            Pwm_HLCtrl_Disable();
        }
        else
        {
            Pwm_HLCtrl_Enable();
        }
        if(GetLgtStsEna_Charge()==0)   /* no charge */
        {
            if(( Interface_GetLightChannelStateSwitch(ChannelID2)==0)&&(Interface_GetLightChannelStateSwitch(ChannelID2_Alt)==0))
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
    ouv_pwm=Interface_GetDerateRatioOfOUV(); /* get the power derate */
    if(ouv_pwm==0) /*  close the light */
    {      
        for (ch = ChannelID1; ch < CHANNEL_NUM; ch++)
        {
            Interface_ChannelClose(ch); /* close the buck */
        }
        Boost_Disable();  /* close the boost */
    }
    else
    {
        Derate_handle(timebase);
        if(ParaMgr_CfgPrm_Usage_B==HWTEST_CODE)
        {/* hardware test */
            /*for emc test*/
            EMC_Light_Main();
        }
        else 
        {
            if(BOOST_Enable_Flag==1)
            {
                Boost_Enable();
                ResetAWakeTime();
            }
            else
            {
                Boost_Disable();
            }
            if(TRUE == Rte_Dcm_GetEolSessionStatus())
            {/* EOL */
                EOL_Light_Main();
            }   
            else /* normal code */
            {
                Input_DelayRampFun(timebase); /* delay + ramp  */
                Light_Run(timebase);
            }
        }
    }
    return E_OK;
}


E_LgtSts_t g_LightChannelStatus[6]={0};
E_LgtSts_t Interface_GetLightChannelStateSwitch(E_ChannelID id)
{
    return g_LightChannelStatus[id];
}

void Interface_SetLightChannelStateSwitch(E_ChannelID id,E_LgtSts_t state)
{
    g_LightChannelStatus[id]=state;
}

void Interface_SwitchBoost(uint8 tmp)
{
    BOOST_Enable_Flag = tmp;
}