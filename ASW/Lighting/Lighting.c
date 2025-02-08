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
#include "FrontCrossLamp.h"
#include "TurnIndicator.h"
#include "DRL.h"
#include "POS.h"
#include "charge.h"

uint16 CH_CurStatus[6]={0}; //通道当前的状态

uint8_t Interface_GetChannelDerateRatio(E_ChannelID chid);
typedef struct
{
    uint16 Ch_NormalCur; /*Para table Normal Current*/
    uint8 Ch_Pwm;
} PR_CHANNEL_CUR;

typedef struct 
{
    uint16  pr_onDelay[E_AssistantLight]; //delay on time
    uint16  pr_offDelay[E_AssistantLight] ; //delay off time
    uint16  pr_OnRamp[E_AssistantLight]  ; // ramp on time
    uint16  pr_OffRamp[E_AssistantLight] ; //ramp off time
    S_LgtActIns_t   in_Act_cur;           //cur in act signal

    uint16  st_msAct[E_AssistantLight]   ; //记录命令状态的时间 

    S_LgtFuncEna_t  st_LgtEna;      //lighting enable
    S_LgtActIns_t   st_LgtAct;     //lighting act
    S_LgtStsFb_t    st_LgtSts;     //lighting status
    S_LgtFuncEna_t  st_LgtDer;    //灯光降额禁止状态 
    uint16        st_maskDer0;    /* 被降额到0的通道掩码 */
    uint16 chnMask;               //channel mask
    PR_CHANNEL_CUR pr_channel_cur[MAX_CHANNLE_NUM]; //注意该数组只能调用6个
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

/*get the act status*/
uint8 Lighting_GetAct(Light_Functions lf)
{
	uint16_t rtval = 0;
	switch (lf)
	{
	case E_LowBeamKink:
		rtval = lgtctl.st_LgtAct.ActLB;
		break;
	case E_HighBeamSpot:
		rtval = lgtctl.st_LgtAct.ActHB;
		break;
	case E_DaytimeRunningLight:
		rtval = lgtctl.st_LgtAct.ActDRL;
		break;
	case E_PositionLight:
		rtval = lgtctl.st_LgtAct.ActPOS;
		break;
	case E_TurnIndicator:
		rtval = lgtctl.st_LgtAct.ActTIsts | (lgtctl.st_LgtAct.ActTIact<<1);
		break;
	case E_FrontCrossLamp:
		rtval = lgtctl.st_LgtAct.ActCROS;
		break;
	}
	return rtval;
}

/*get the act status*/
static uint8 Lighting_SetAct(Light_Functions lf,E_LgtAct_t actsts)
{
	uint8 rtval = 0;
	switch (lf)
	{
	case E_LowBeamKink:
		lgtctl.st_LgtAct.ActLB=actsts;
		break;
	case E_HighBeamSpot:
		lgtctl.st_LgtAct.ActHB=actsts;
		break;
	case E_DaytimeRunningLight:
		lgtctl.st_LgtAct.ActDRL=actsts;
		break;
	case E_PositionLight:
		lgtctl.st_LgtAct.ActPOS=actsts;
		break;
	case E_TurnIndicator:
        lgtctl.st_LgtAct.ActTIsts=actsts;
		break;
	case E_FrontCrossLamp:
		lgtctl.st_LgtAct.ActCROS=actsts;
		break;
	}
	return rtval;
}

/*get the act cur status*/
static uint8 Lighting_GetActCur(Light_Functions lf)
{
	uint8 rtval = 0;
	switch (lf)
	{
	case E_LowBeamKink:
		rtval = lgtctl.in_Act_cur.ActLB;
		break;
	case E_HighBeamSpot:
		rtval = lgtctl.in_Act_cur.ActHB;
		break;
	case E_DaytimeRunningLight:
		rtval = lgtctl.in_Act_cur.ActDRL;
		break;
	case E_PositionLight:
		rtval = lgtctl.in_Act_cur.ActPOS;
		break;
	case E_TurnIndicator:
		rtval = lgtctl.in_Act_cur.ActTIsts;
		break;
	case E_FrontCrossLamp:
		rtval = lgtctl.in_Act_cur.ActCROS;
		break;
	}
	return rtval;
}

typedef struct 
{
    uint8 pwm_Ramp[E_AssistantLight];       //渐亮渐灭占空比
    uint16 st_msRampRun[E_AssistantLight] ;//渐亮渐灭执行时间
}S_Pamp_Pwm;
static S_Pamp_Pwm gs_ramp_pwm;

void Light_Parameter_Init(void)
{

}

static void ChnCurrentSet(void)
{
    int chid;
    uint16_t chnCurr;   /* 通道电流 */
    uint8_t  derate;    /* 降额比例 */
        /* 取得 配置通道掩码 */
    for (chid=0; chid<E_AssistantLight; chid++)
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

            /* 若通道电流小于100mA，则需要调通道的PWM */
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
    for(E_Light=E_LowBeamKink;E_Light<E_FrontCrossLamp;E_Light++)
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
    uint8 linrx=0,inact=0;
//delay on ;delay off time++
    Light_Functions lf= E_LowBeamKink;
    for(lf=E_LowBeamKink;lf<=E_AssistantLight;lf++)
    {
        if (lgtctl.st_msAct[lf] <= top) { lgtctl.st_msAct[lf] += ms; }
// lin rx signal not = act signal ,run time=0;
        linrx=Lighting_GetLinCtrl(lf);
        inact=Lighting_GetActCur(lf);
        if((linrx != inact))     
        { 
            lgtctl.st_msAct[lf] = 0; 
            gs_ramp_pwm.st_msRampRun[lf]=0; 
        }
    }

//in act signal = lin rx signal
    lgtctl.in_Act_cur.ActLB    = Lighting_GetLinCtrl(E_LowBeamKink);
    lgtctl.in_Act_cur.ActHB    = Lighting_GetLinCtrl(E_HighBeamSpot);
    lgtctl.in_Act_cur.ActPOS   = Lighting_GetLinCtrl(E_PositionLight);
    lgtctl.in_Act_cur.ActDRL   = Lighting_GetLinCtrl(E_DaytimeRunningLight);
    lgtctl.in_Act_cur.ActTIsts = Lighting_GetLinCtrl(E_TurnIndicator)>>2; 
    lgtctl.in_Act_cur.ActCROS  = Lighting_GetLinCtrl(E_FrontCrossLamp);
    lgtctl.in_Act_cur.ActTIact = Lighting_GetLinCtrl(E_TurnIndicator);

    //如有点灯信号，打开BOOST（不能一直打开，考虑热量）,不进入休眠
    if((lgtctl.in_Act_cur.ActLB!=0)||(lgtctl.in_Act_cur.ActHB!=0)||(lgtctl.in_Act_cur.ActPOS!=0)
    ||(lgtctl.in_Act_cur.ActDRL!=0)||(lgtctl.in_Act_cur.ActTIsts!=0)||(lgtctl.in_Act_cur.ActCROS!=0)||(lgtctl.in_Act_cur.ActTIact!=0)
    ||(Interface_GetSignal_PosnLampDyn()!=0))
    {
        Boost_Enable();
        ResetAWakeTime();
        /* Port_FAN_Enable();  */
    }
    else
    {
        /* Port_FAN_Disable(); */
        Boost_Disable();
    }
}

//渐亮渐灭功能
static void Input_RampFun(uint16 ms)
{
    uint8 In_Act_Cur=ACT_OFF;
    Light_Functions Lf=E_LowBeamKink;
/* Ramp_On calculate pwm */
    for(Lf=E_LowBeamKink;Lf<=E_FrontCrossLamp;Lf++)
    {
        In_Act_Cur=Lighting_GetActCur(Lf);
    
        if ((In_Act_Cur == ACT_ON)&& (lgtctl.st_msAct[Lf] >= lgtctl.pr_onDelay[Lf]))  //延时点亮结束 进入渐亮阶段
        {
            Lighting_SetAct(Lf,ACT_ON);
            if(gs_ramp_pwm.st_msRampRun[Lf]<lgtctl.pr_OnRamp[Lf])//渐亮
            {
                gs_ramp_pwm.st_msRampRun[Lf] += ms;
                gs_ramp_pwm.pwm_Ramp[Lf] = 100*gs_ramp_pwm.st_msRampRun[Lf]/lgtctl.pr_OnRamp[Lf];
            }
            else gs_ramp_pwm.pwm_Ramp[Lf]=100;
        }
    }
//Ramp off calculate PWM
    for(Lf=E_LowBeamKink;Lf<=E_FrontCrossLamp;Lf++)
    {
        In_Act_Cur=Lighting_GetActCur(Lf);
        if ((In_Act_Cur == ACT_OFF) && (lgtctl.st_msAct[Lf]   >= lgtctl.pr_offDelay[Lf]  )) 
        { 
            if(gs_ramp_pwm.st_msRampRun[Lf]<lgtctl.pr_OffRamp[Lf])//渐灭
            {
                gs_ramp_pwm.st_msRampRun[Lf] += ms;
                gs_ramp_pwm.pwm_Ramp[Lf] = 100-(100*gs_ramp_pwm.st_msRampRun[Lf]/lgtctl.pr_OffRamp[Lf]);
            }
            else 
            {
                Lighting_SetAct(Lf,ACT_OFF);
            }
        }
    }
    lgtctl.st_LgtAct.ActTIact = lgtctl.in_Act_cur.ActTIact;
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


uint16 Lighting_Rek_Fun(void)
{
    return lgtctl.st_LgtSts.Light_Status;
}

void Light_Run(uint8 timebase)
{
    E_ChannelID chid=ChannelID1;

    for(chid=ChannelID1;chid<CHANNEL_NUM;chid++)
    {
/*************************************LB HB**CH1 CH1_Tap****************************************************/
        CH_CurStatus[chid]=HB_RunMainFun(chid,lgtctl.st_LgtAct.ActHB,&CH_CurStatus[0]); //HB light main function
        CH_CurStatus[chid]=LB_RunMainFun(chid,lgtctl.st_LgtAct.ActLB,&CH_CurStatus[0]);

/*************************************pos drl ti******************************************************/
        CH_CurStatus[chid]=TI_RunMainFun(chid,&CH_CurStatus[0]);
        CH_CurStatus[chid]=DRL_RunMainFun(chid,&CH_CurStatus[0]);
        CH_CurStatus[chid]=POS_RunMainFun(chid,&CH_CurStatus[0]); 
        CH_CurStatus[chid]=Charge_MainFunction(chid,&CH_CurStatus[0],timebase);

        CH_CurStatus[chid]=CROS_RunMainFun(chid,&CH_CurStatus[0]);   

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




