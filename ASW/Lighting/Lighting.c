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
#include "charge.h"
#include "FrontCrossLamp.h"
#include "FogLamp.h"
#include "GrilleLamp.h"
#include "LogoLamp.h"
#include "CorneringLamp.h"

#define LIGHT_MAX_NUM    12
uint16 CH_CurStatus[6]={0}; //通道当前的状态

uint8_t Interface_GetChannelDerateRatio(E_ChannelID chid);
typedef struct
{
    uint16 Ch_NormalCur; /*Para table Normal Current*/
    uint8 Ch_Pwm;
} PR_CHANNEL_CUR;

typedef struct 
{
    uint16  pr_onDelay[LIGHT_MAX_NUM]; //delay on time
    uint16  pr_offDelay[LIGHT_MAX_NUM] ; //delay off time
    uint16  pr_OnRamp[LIGHT_MAX_NUM]  ; // ramp on time
    uint16  pr_OffRamp[LIGHT_MAX_NUM] ; //ramp off time
    uint8   in_Act_cur[LIGHT_MAX_NUM] ;           //cur in act signal
    uint16  st_msAct[LIGHT_MAX_NUM]   ; //记录命令状态的时间 
    S_LgtFuncEna_t  st_LgtEna;      //lighting enable
    uint8   st_LgtAct[LIGHT_MAX_NUM];     //lighting act
    S_LgtStsFb_t    st_LgtSts;     //lighting status
    S_LgtFuncEna_t  st_LgtDer;    //灯光降额禁止状态 
    uint16        st_maskDer0;    /* 被降额到0的通道掩码 */
    uint16 chnMask;               //channel mask
    PR_CHANNEL_CUR pr_channel_cur[MAX_CHANNLE_NUM];  //parameter channel current
}S_LightingCtl_t;
static S_LightingCtl_t lgtctl;

void SetLgtStsFb_LB  (E_LgtSts_t sts){ lgtctl.st_LgtSts.Bits.StsLB   = sts; }
void SetLgtStsFb_TI  (E_LgtSts_t sts){ lgtctl.st_LgtSts.Bits.StsTI   = sts; }
void SetLgtStsFb_POS (E_LgtSts_t sts){ lgtctl.st_LgtSts.Bits.StsPOS  = sts; }
void SetLgtStsFb_HB  (E_LgtSts_t sts){ lgtctl.st_LgtSts.Bits.StsHB   = sts; }
void SetLgtStsFb_DRL (E_LgtSts_t sts){ lgtctl.st_LgtSts.Bits.StsDRL  = sts; }
void SetLgtStsFb_CORN(E_LgtSts_t sts){ lgtctl.st_LgtSts.Bits.StsCORN = sts; }
void SetLgtStsFb_CROS(E_LgtSts_t sts){ lgtctl.st_LgtSts.Bits.StsCROS = sts; }
void SetLgtStsFb_WELC(E_LgtSts_t sts){ lgtctl.st_LgtSts.Bits.StsWELC = sts; }
void SetLgtStsFb_Fog(E_LgtSts_t sts) { lgtctl.st_LgtSts.Bits.StsFOG  = sts; }

/*get the act status*/
uint8 Lighting_GetAct(Light_Functions lf)
{
	return lgtctl.st_LgtAct[lf];
}

typedef struct 
{
    uint8 pwm_Ramp[LIGHT_MAX_NUM];       //渐亮渐灭占空比
    uint16 st_msRampRun[LIGHT_MAX_NUM] ;//渐亮渐灭执行时间
}S_Pamp_Pwm;
static S_Pamp_Pwm gs_ramp_pwm;

static void ChnCurrentSet(void)
{
    int chid;
    uint16_t chnCurr;   /* 通道电流 */
    uint8_t  derate;    /* 降额比例 */
        /* 取得 配置通道掩码 */
    for (chid=0; chid<E_TurnIndicator_Act; chid++)
    {
        lgtctl.chnMask |= GetChannelMaskByLightFunction((Light_Functions)chid);
    }

    /* 设置通道电流/占空比 */
    for (chid=0; chid<MAX_CHANNLE_NUM; chid++)
    {
        if ((lgtctl.chnMask & (0x0001 << chid)) != 0)
        {           
            /* 优先级 BIN>DID>参数配置表  CTS_V1.0.4_4.1.2 */
            // chnCurr = Interface_GetChannelBinCurrent((E_ChannelID)chid);
            // if (chnCurr == INVALIED_CURRENT)
            // {
            //     chnCurr = Interface_GetChannelDidConfigCurrent((E_ChannelID)chid);
            //     if (chnCurr == INVALIED_CURRENT)
            //     {
                    chnCurr = Interface_GetChannelParamTableNormalCurrent((E_ChannelID)chid);
                // }
            // }

            /* 获取通道的降额百分比 */
            derate = Interface_GetChannelDerateRatio((E_ChannelID)chid);

            if (derate == 0) 
            {
                chnCurr = 0;
            }
            else if (derate < 100) 
            { 
                chnCurr = ((uint32_t)chnCurr)*((uint32_t)derate) / ((uint32_t)100); 
            }
            lgtctl.pr_channel_cur[chid].Ch_NormalCur = chnCurr;

            /* if cur<100mA，need to change PWM */
            if ((lgtctl.pr_channel_cur[chid].Ch_NormalCur > 0) &&
                (lgtctl.pr_channel_cur[chid].Ch_NormalCur < 100))
            {
                lgtctl.pr_channel_cur[chid].Ch_Pwm= lgtctl.pr_channel_cur[chid].Ch_NormalCur;
                lgtctl.pr_channel_cur[chid].Ch_NormalCur = 100;
            }
            else
            {
                lgtctl.pr_channel_cur[chid].Ch_Pwm = 100;
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
uint16 Interface_GetSignal_ChannelCurrent(uint8 chid)
{
    return lgtctl.pr_channel_cur[chid].Ch_NormalCur;
}

/* function: get the channel run pwm */
uint8 Interface_GetSignal_ChannelPwm(uint8 chid)
{
    return lgtctl.pr_channel_cur[chid].Ch_Pwm;
}

/*
parameter init 
On delay time 
Off delay time 
On ramp time 
Off ramp time 
*/
static void _inou_init(void)
{
    Light_Functions E_Light= E_LowBeamKink;
    for(E_Light=E_LowBeamKink;E_Light<=E_AssistantLight;E_Light++)
    {
        lgtctl.pr_onDelay[E_Light]  = Get_pLedONDelay(E_Light);
        lgtctl.pr_offDelay[E_Light] = Get_pLedOFFDelay(E_Light);
        lgtctl.pr_OnRamp[E_Light]   = Get_pLedOnRampTi(E_Light);
        lgtctl.pr_OffRamp[E_Light]  = Get_pLedOffRampTi(E_Light);
    }
}

Std_ReturnType Lighting_Init(void)
{
    _inou_init();  //basic light Init
    Charge_Init();// POS_DYN Init
    return E_OK;
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

//点亮信号输入 延时点亮 延时熄灭功能
static void Input_DelayFun(uint16 ms)
{
    uint16 top = 0xFFFF - ms;
    uint8 linrx=0;
    static uint8 inact_off_cnt=0;
    uint8 boostoffdelay=0;
//delay on ;delay off time++
    Light_Functions lf= E_LowBeamKink;
    for(lf=E_LowBeamKink;lf<E_TurnIndicator_Act;lf++)
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
        if(lgtctl.in_Act_cur[lf]==0)
        {
            inact_off_cnt++;
        }
        else 
        {
            inact_off_cnt=0;
        }
    }
    lgtctl.in_Act_cur[E_TurnIndicator_Act]=Lighting_GetLinCtrl(E_TurnIndicator_Act);

    if((inact_off_cnt>=E_TurnIndicator_Act)&&((Interface_GetSignal_PosnLampDyn()==0)))
    {
        inact_off_cnt=E_TurnIndicator_Act;
        if(boostoffdelay++>=2) //close buck first
        {
            Boost_Disable();
        }
    }
    else
    {
        boostoffdelay=0;
        Boost_Enable();
        ResetAWakeTime();
    }
}

//渐亮渐灭功能
static void Input_RampFun(uint16 ms)
{
    uint8 In_Act_Cur=ACT_OFF;
    Light_Functions Lf=E_LowBeamKink;
/* Ramp_On calculate pwm */
    for(Lf=E_LowBeamKink;Lf<=E_AssistantLight;Lf++)
    {
        In_Act_Cur=lgtctl.in_Act_cur[Lf];
    
        if ((In_Act_Cur != ACT_OFF)&& (lgtctl.st_msAct[Lf] >= lgtctl.pr_onDelay[Lf]))  //延时点亮结束 进入渐亮阶段
        {
            lgtctl.st_LgtAct[Lf]=ACT_ON;
            if(gs_ramp_pwm.st_msRampRun[Lf]<lgtctl.pr_OnRamp[Lf])//渐亮
            {
                gs_ramp_pwm.st_msRampRun[Lf] += ms;
                gs_ramp_pwm.pwm_Ramp[Lf] = 100*gs_ramp_pwm.st_msRampRun[Lf]/lgtctl.pr_OnRamp[Lf];
            }
            else gs_ramp_pwm.pwm_Ramp[Lf]=100;
        }
    }
//Ramp off calculate PWM
    for(Lf=E_LowBeamKink;Lf<=E_AssistantLight;Lf++)
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
/*************************************LB HB**CH1 CH1_Tap****************************************************/
    HB_RunMainFun(&CH_CurStatus[0]); //HB light main function
    LB_RunMainFun(&CH_CurStatus[0]);

/*************************************pos drl ti******************************************************/
    reval=Charge_MainFunction(&CH_CurStatus[0],timebase);
    if(reval==E_OK)
    {
        TI_RunMainFun(&CH_CurStatus[0]);
        DRL_RunMainFun(&CH_CurStatus[0]);
        POS_RunMainFun(&CH_CurStatus[0]); 
    }
    CROS_RunMainFun(&CH_CurStatus[0]);   
    FogLamp_RunMainFun(&CH_CurStatus[0]);
    GrilleLamp_RunMainFun(&CH_CurStatus[0]);
    LogoLamp_RunMainFun(&CH_CurStatus[0]);
    CornLamp_RunMainFun(&CH_CurStatus[0]);
/**********************************share channel close************************************************** */
    if((0==CH_CurStatus[ChannelID1_Tap])&&(0==CH_CurStatus[ChannelID1])) //CH1 和 CH1Tap 关通道 
    {
        Interface_ChannelClose(ChannelID1);
        Interface_ChannelClose(ChannelID1_Tap);
    }        
    if(( CH_CurStatus[ChannelID2]==0)&&(CH_CurStatus[ChannelID2_Alt]==0)) 
    {
        Interface_ChannelClose(ChannelID2);
        Interface_ChannelClose(ChannelID2_Alt);
    }
}

/*灯光管理功能*/
Std_ReturnType Light_Manager(uint8 timebase)
{  
    uint8 ouv_pwm=0;
    E_ChannelID ch=ChannelID1;
    ouv_pwm=Interface_GetDerateRatioOfOUV();
    if(ouv_pwm==0)
    {      
        for (ch = ChannelID1; ch < CHANNEL_NUM; ch++)
        {
            Interface_ChannelClose(ch);
        }
        Boost_Disable();
    }
    else
    {
        Input_DelayRampFun(timebase);//delay + ramp 
        Derate_handle(timebase);
        Light_Run(timebase);
    }
    return E_OK;
}




