#include "HcmPlatform.h"
#include "Lighting.h"
#include "LinManager.h"
#include "Ex_SleepWakeup.h"
#include "Dio_Service.h"
#include "Pwm_Service.h"
#include "Parameter_Interface.h"
#include "OUVDerate_Interface.h"
#include "Channel_Interface.h"
#include "HB.h"
#include "LB.h"
#include "FrontCrossLamp.h"
#include "TurnIndicator.h"
#include "DRL.h"
#include "POS.h"

uint16 CH_CurStatus[6]={0}; //通道当前的状态

uint8_t Interface_GetChannelDerateRatio(E_ChannelID id);
S_Lin_LControl linsignal={0};
typedef struct
{
    uint16 CH_NormalCur; /*Para table Normal Current*/
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
    int ch;
    uint16_t chnCurr;   /* 通道电流 */
    uint8_t  derate;    /* 降额比例 */
        /* 取得 配置通道掩码 */
    for (ch=0; ch<E_AssistantLight; ch++)
    {
        lgtctl.chnMask |= GetChannelMaskByLightFunction((Light_Functions)ch);
    }

    /* 设置通道电流/占空比 */
    for (ch=0; ch<MAX_CHANNLE_NUM; ch++)
    {
        if ((lgtctl.chnMask & (0x0001 << ch)) != 0)
        {           
            /* 优先级 BIN>DID>参数配置表  CTS_V1.0.4_4.1.2 */
            // chnCurr = Interface_GetChannelBinCurrent((E_ChannelID)ch);
            // if (chnCurr == INVALIED_CURRENT)
            // {
            //     chnCurr = Interface_GetChannelDidConfigCurrent((E_ChannelID)ch);
            //     if (chnCurr == INVALIED_CURRENT)
            //     {
                    chnCurr = Interface_GetChannelParamTableNormalCurrent((E_ChannelID)ch);
                // }
            // }

            /* 获取通道的降额百分比 */
            derate = Interface_GetChannelDerateRatio((E_ChannelID)ch);
            if (derate == 0) 
            {
                chnCurr = 0;
            }
            else if (derate < 100) 
            { 
                chnCurr = ((uint32_t)chnCurr)*((uint32_t)derate) / ((uint32_t)100); 
            }
            lgtctl.pr_channel_cur[ch].CH_NormalCur = chnCurr;

            /* 若通道电流小于100mA，则需要调通道的PWM */
            if ((lgtctl.pr_channel_cur[ch].CH_NormalCur > 0) &&
                (lgtctl.pr_channel_cur[ch].CH_NormalCur < 100))
            {
                lgtctl.pr_channel_cur[ch].Ch_Pwm= lgtctl.pr_channel_cur[ch].CH_NormalCur;
                lgtctl.pr_channel_cur[ch].CH_NormalCur = 100;
            }
            else
            {
                lgtctl.pr_channel_cur[ch].Ch_Pwm = 100;
            }
        }
    }
}

static void _inou_init(void)
{
//延时点亮读参数表
    lgtctl.pr_onDelay[E_LowBeamKink]         = Get_pLedONDelay(E_LowBeamKink);
    lgtctl.pr_onDelay[E_HighBeamSpot]        = Get_pLedONDelay(E_HighBeamSpot);
    lgtctl.pr_onDelay[E_TurnIndicator]       = Get_pLedONDelay(E_TurnIndicator);
    lgtctl.pr_onDelay[E_DaytimeRunningLight] = Get_pLedONDelay(E_DaytimeRunningLight);
    lgtctl.pr_onDelay[E_PositionLight]       = Get_pLedONDelay(E_PositionLight);
    lgtctl.pr_onDelay[E_FrontCrossLamp]      = Get_pLedONDelay(E_FrontCrossLamp);

    lgtctl.pr_offDelay[E_LowBeamKink]        = Get_pLedOFFDelay(E_LowBeamKink);
    lgtctl.pr_offDelay[E_HighBeamSpot]       = Get_pLedOFFDelay(E_HighBeamSpot);
    lgtctl.pr_offDelay[E_TurnIndicator]      = Get_pLedOFFDelay(E_TurnIndicator);
    lgtctl.pr_offDelay[E_DaytimeRunningLight]= Get_pLedOFFDelay(E_DaytimeRunningLight);
    lgtctl.pr_offDelay[E_PositionLight]      = Get_pLedOFFDelay(E_PositionLight);
    lgtctl.pr_offDelay[E_FrontCrossLamp]     = Get_pLedOFFDelay(E_FrontCrossLamp);

//渐亮渐灭读参数表
    lgtctl.pr_OnRamp[E_LowBeamKink]          = Get_pLedOnRampTi(E_LowBeamKink);
    lgtctl.pr_OnRamp[E_HighBeamSpot]         = Get_pLedOnRampTi(E_HighBeamSpot);
    lgtctl.pr_OnRamp[E_TurnIndicator]        = Get_pLedOnRampTi(E_TurnIndicator);
    lgtctl.pr_OnRamp[E_DaytimeRunningLight]  = Get_pLedOnRampTi(E_DaytimeRunningLight);
    lgtctl.pr_OnRamp[E_PositionLight]        = Get_pLedOnRampTi(E_PositionLight);
    lgtctl.pr_OnRamp[E_FrontCrossLamp]       = Get_pLedOnRampTi(E_FrontCrossLamp);

    lgtctl.pr_OffRamp[E_LowBeamKink]         = Get_pLedOffRampTi(E_LowBeamKink);
    lgtctl.pr_OffRamp[E_HighBeamSpot]        = Get_pLedOffRampTi(E_HighBeamSpot);
    lgtctl.pr_OffRamp[E_TurnIndicator]       = Get_pLedOffRampTi(E_TurnIndicator);
    lgtctl.pr_OffRamp[E_DaytimeRunningLight] = Get_pLedOffRampTi(E_DaytimeRunningLight);
    lgtctl.pr_OffRamp[E_PositionLight]       = Get_pLedOffRampTi(E_PositionLight);
    lgtctl.pr_OffRamp[E_FrontCrossLamp]      = Get_pLedOffRampTi(E_FrontCrossLamp);
}

Std_ReturnType Lighting_Init(void)
{
    _inou_init();
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
//延时开灯和延时关灯计时
    if (lgtctl.st_msAct[E_LowBeamKink]   <= top) { lgtctl.st_msAct[E_LowBeamKink]   += ms; }
    if (lgtctl.st_msAct[E_HighBeamSpot]   <= top) { lgtctl.st_msAct[E_HighBeamSpot]   += ms; }
    if (lgtctl.st_msAct[E_TurnIndicator]   <= top) { lgtctl.st_msAct[E_TurnIndicator]   += ms; }
    if (lgtctl.st_msAct[E_DaytimeRunningLight]  <= top) { lgtctl.st_msAct[E_DaytimeRunningLight]  += ms; }
    if (lgtctl.st_msAct[E_PositionLight]  <= top) { lgtctl.st_msAct[E_PositionLight]  += ms; }
    if (lgtctl.st_msAct[E_FrontCrossLamp] <= top) { lgtctl.st_msAct[E_FrontCrossLamp] += ms; }

//取得网络上灯功能动作输入指令
    linsignal=Interface_Get_LinSignal();
//如有点灯信号，打开BOOST（不能一直打开，考虑热量）,不进入休眠
    if(linsignal.Light_Status!=0)
    {
        Boost_Enable();
        ResetAWakeTime();
        Port_FAN_Enable(); 
    }
    else 
    {
        Port_FAN_Disable();
        Boost_Disable();
    }
// lin接收信号如果和执行信号不同，执行时间清零
    if((linsignal.Bits.LB_Ena != lgtctl.in_Act_cur.ActLB))     
    { 
        lgtctl.st_msAct[E_LowBeamKink] = 0; 
        gs_ramp_pwm.st_msRampRun[E_LowBeamKink]=0; 
    }
    if((linsignal.Bits.HB_Ena != lgtctl.in_Act_cur.ActHB))        
    {
        lgtctl.st_msAct[E_HighBeamSpot] = 0;  
        gs_ramp_pwm.st_msRampRun[E_HighBeamSpot]=0; 
    }
    if((linsignal.Bits.Pos_Ena != lgtctl.in_Act_cur.ActPOS))        
    {
        lgtctl.st_msAct[E_PositionLight] = 0; 
        gs_ramp_pwm.st_msRampRun[E_PositionLight]=0; 
    }
    if((linsignal.Bits.Drl_Ena != lgtctl.in_Act_cur.ActDRL))        
    { 
        lgtctl.st_msAct[E_DaytimeRunningLight] = 0; 
        gs_ramp_pwm.st_msRampRun[E_DaytimeRunningLight]=0; 
    }
    if((linsignal.Bits.Turn_Sts != lgtctl.in_Act_cur.ActTIsts))     
    { 
        lgtctl.st_msAct[E_TurnIndicator] = 0;  
        gs_ramp_pwm.st_msRampRun[E_TurnIndicator]=0; 
    }
    if((linsignal.Bits.CROS_Ena != lgtctl.in_Act_cur.ActCROS))      
    { 
        lgtctl.st_msAct[E_FrontCrossLamp] = 0;
        gs_ramp_pwm.st_msRampRun[E_FrontCrossLamp]=0; 
    }
//输入执行信号 = lin接收到的信号
    lgtctl.in_Act_cur.ActLB    = linsignal.Bits.LB_Ena; 
    lgtctl.in_Act_cur.ActHB    = linsignal.Bits.HB_Ena; 
    lgtctl.in_Act_cur.ActPOS   = linsignal.Bits.Pos_Ena; 
    lgtctl.in_Act_cur.ActDRL   = linsignal.Bits.Drl_Ena; 
    lgtctl.in_Act_cur.ActTIsts = linsignal.Bits.Turn_Sts; 
    lgtctl.in_Act_cur.ActCROS  = linsignal.Bits.CROS_Ena; 
    lgtctl.in_Act_cur.ActTIact = linsignal.Bits.Turn_Act; 
}

//渐亮渐灭功能
static void Input_RampFun(uint16 ms)
{
//渐亮：计算PWM  
    if ((lgtctl.in_Act_cur.ActLB    == ACT_ON)  && (lgtctl.st_msAct[E_LowBeamKink]   >= lgtctl.pr_onDelay[E_LowBeamKink]  ))  //延时点亮结束 进入渐亮阶段
    {
        lgtctl.st_LgtAct.ActLB = ACT_ON; 
        if(gs_ramp_pwm.st_msRampRun[E_LowBeamKink]<lgtctl.pr_OnRamp[E_LowBeamKink])//渐亮
        {
            gs_ramp_pwm.st_msRampRun[E_LowBeamKink] += ms;
            gs_ramp_pwm.pwm_Ramp[E_LowBeamKink] = 100*gs_ramp_pwm.st_msRampRun[E_LowBeamKink]/lgtctl.pr_OnRamp[E_LowBeamKink];
        }
        else gs_ramp_pwm.pwm_Ramp[E_LowBeamKink]=100;
    }
    if ((lgtctl.in_Act_cur.ActHB == ACT_ON)  && (lgtctl.st_msAct[E_HighBeamSpot]   >= lgtctl.pr_onDelay[E_HighBeamSpot]  ))  
    { 
        lgtctl.st_LgtAct.ActHB = ACT_ON; 
        if(gs_ramp_pwm.st_msRampRun[E_HighBeamSpot]<lgtctl.pr_OnRamp[E_HighBeamSpot])//渐亮
        {
            gs_ramp_pwm.st_msRampRun[E_HighBeamSpot] += ms;
            gs_ramp_pwm.pwm_Ramp[E_HighBeamSpot] = 100*gs_ramp_pwm.st_msRampRun[E_HighBeamSpot]/lgtctl.pr_OnRamp[E_HighBeamSpot];
        }
        else gs_ramp_pwm.pwm_Ramp[E_HighBeamSpot]=100;
    }
    if ((lgtctl.in_Act_cur.ActTIsts == ACT_ON) && (lgtctl.st_msAct[E_TurnIndicator]   >= lgtctl.pr_onDelay[E_TurnIndicator]  ))  
    { 
        lgtctl.st_LgtAct.ActTIsts = ACT_ON; 
        if(gs_ramp_pwm.st_msRampRun[E_TurnIndicator]<lgtctl.pr_OnRamp[E_TurnIndicator])//渐亮
        {
            gs_ramp_pwm.st_msRampRun[E_TurnIndicator] += ms;
            gs_ramp_pwm.pwm_Ramp[E_TurnIndicator] = 100*gs_ramp_pwm.st_msRampRun[E_TurnIndicator]/lgtctl.pr_OnRamp[E_TurnIndicator];
        }
        else gs_ramp_pwm.pwm_Ramp[E_TurnIndicator]=100;
    }
    if ((lgtctl.in_Act_cur.ActDRL == ACT_ON) && (lgtctl.st_msAct[E_DaytimeRunningLight]  >= lgtctl.pr_onDelay[E_DaytimeRunningLight] ))  
    {
        lgtctl.st_LgtAct.ActDRL = ACT_ON; 
        if(gs_ramp_pwm.st_msRampRun[E_DaytimeRunningLight]<lgtctl.pr_OnRamp[E_DaytimeRunningLight])//渐亮
        {
            gs_ramp_pwm.st_msRampRun[E_DaytimeRunningLight] += ms;
            gs_ramp_pwm.pwm_Ramp[E_DaytimeRunningLight] = 100*gs_ramp_pwm.st_msRampRun[E_DaytimeRunningLight]/lgtctl.pr_OnRamp[E_DaytimeRunningLight];
        }
        else gs_ramp_pwm.pwm_Ramp[E_DaytimeRunningLight]=100;
    }
    if ((lgtctl.in_Act_cur.ActPOS == ACT_ON) && (lgtctl.st_msAct[E_PositionLight]  >= lgtctl.pr_onDelay[E_PositionLight] ))  
    {
        lgtctl.st_LgtAct.ActPOS   = ACT_ON; 
        if(gs_ramp_pwm.st_msRampRun[E_PositionLight]<lgtctl.pr_OnRamp[E_PositionLight])//渐亮
        {
            gs_ramp_pwm.st_msRampRun[E_PositionLight] += ms;
            gs_ramp_pwm.pwm_Ramp[E_PositionLight] = 100*gs_ramp_pwm.st_msRampRun[E_PositionLight]/lgtctl.pr_OnRamp[E_PositionLight];
        }
        else gs_ramp_pwm.pwm_Ramp[E_PositionLight]=100;
    }
    if ((lgtctl.in_Act_cur.ActCROS == ACT_ON) && (lgtctl.st_msAct[E_FrontCrossLamp] >= lgtctl.pr_onDelay[E_FrontCrossLamp]))  
    { 
        lgtctl.st_LgtAct.ActCROS  = ACT_ON; 
        if(gs_ramp_pwm.st_msRampRun[E_FrontCrossLamp]<lgtctl.pr_OnRamp[E_FrontCrossLamp])//渐亮
        {
            gs_ramp_pwm.st_msRampRun[E_FrontCrossLamp] += ms;
            gs_ramp_pwm.pwm_Ramp[E_FrontCrossLamp] = 100*gs_ramp_pwm.st_msRampRun[E_FrontCrossLamp]/lgtctl.pr_OnRamp[E_FrontCrossLamp];
        }
        else gs_ramp_pwm.pwm_Ramp[E_FrontCrossLamp]=100;
    }
//延时熄灭结束，进入渐灭阶段
    if ((lgtctl.in_Act_cur.ActLB == ACT_OFF) && (lgtctl.st_msAct[E_LowBeamKink]   >= lgtctl.pr_offDelay[E_LowBeamKink]  )) 
    { 
        if(gs_ramp_pwm.st_msRampRun[E_LowBeamKink]<lgtctl.pr_OffRamp[E_LowBeamKink])//渐灭
        {
            gs_ramp_pwm.st_msRampRun[E_LowBeamKink] += ms;
            gs_ramp_pwm.pwm_Ramp[E_LowBeamKink] = 100-(100*gs_ramp_pwm.st_msRampRun[E_LowBeamKink]/lgtctl.pr_OffRamp[E_LowBeamKink]);
        }
        else lgtctl.st_LgtAct.ActLB = ACT_OFF; //渐灭时间到 关灯
    }
    if ((lgtctl.in_Act_cur.ActHB == ACT_OFF) && (lgtctl.st_msAct[E_HighBeamSpot]   >= lgtctl.pr_offDelay[E_HighBeamSpot]  )) 
    {
        if(gs_ramp_pwm.st_msRampRun[E_HighBeamSpot]<lgtctl.pr_OffRamp[E_HighBeamSpot])//渐灭
        {
            gs_ramp_pwm.st_msRampRun[E_HighBeamSpot] += ms;
            gs_ramp_pwm.pwm_Ramp[E_HighBeamSpot] = 100-(100*gs_ramp_pwm.st_msRampRun[E_HighBeamSpot]/lgtctl.pr_OffRamp[E_HighBeamSpot]);
        }
        else lgtctl.st_LgtAct.ActHB = ACT_OFF; 
    }
    if ((lgtctl.in_Act_cur.ActTIsts == ACT_OFF) && (lgtctl.st_msAct[E_TurnIndicator]   >= lgtctl.pr_offDelay[E_TurnIndicator]  )) 
    { 
        if(gs_ramp_pwm.st_msRampRun[E_TurnIndicator]<lgtctl.pr_OffRamp[E_TurnIndicator])//渐灭
        {
            gs_ramp_pwm.st_msRampRun[E_TurnIndicator] += ms;
            gs_ramp_pwm.pwm_Ramp[E_TurnIndicator] = 100-(100*gs_ramp_pwm.st_msRampRun[E_TurnIndicator]/lgtctl.pr_OffRamp[E_TurnIndicator]);
        }
        else lgtctl.st_LgtAct.ActTIsts = ACT_OFF; 
    }
    if ((lgtctl.in_Act_cur.ActDRL == ACT_OFF) && (lgtctl.st_msAct[E_DaytimeRunningLight]  >= lgtctl.pr_offDelay[E_DaytimeRunningLight] )) 
    { 
        if(gs_ramp_pwm.st_msRampRun[E_DaytimeRunningLight]<lgtctl.pr_OffRamp[E_DaytimeRunningLight])//渐灭
        {
            gs_ramp_pwm.st_msRampRun[E_DaytimeRunningLight] += ms;
            gs_ramp_pwm.pwm_Ramp[E_DaytimeRunningLight] = 100-(100*gs_ramp_pwm.st_msRampRun[E_DaytimeRunningLight]/lgtctl.pr_OffRamp[E_DaytimeRunningLight]);
        }
        else lgtctl.st_LgtAct.ActDRL   = ACT_OFF; 
    }
    if ((lgtctl.in_Act_cur.ActPOS == ACT_OFF) && (lgtctl.st_msAct[E_PositionLight]  >= lgtctl.pr_offDelay[E_PositionLight] )) 
    { 
        if(gs_ramp_pwm.st_msRampRun[E_HighBeamSpot]<lgtctl.pr_OffRamp[E_HighBeamSpot])//渐灭
        {
            gs_ramp_pwm.st_msRampRun[E_HighBeamSpot] += ms;
            gs_ramp_pwm.pwm_Ramp[E_HighBeamSpot] = 100-(100*gs_ramp_pwm.st_msRampRun[E_HighBeamSpot]/lgtctl.pr_OffRamp[E_HighBeamSpot]);
        }
        else lgtctl.st_LgtAct.ActPOS   = ACT_OFF; 
    }
    if ((lgtctl.in_Act_cur.ActCROS == ACT_OFF) && (lgtctl.st_msAct[E_FrontCrossLamp] >= lgtctl.pr_offDelay[E_FrontCrossLamp])) 
    { 
        if(gs_ramp_pwm.st_msRampRun[E_FrontCrossLamp]<lgtctl.pr_OffRamp[E_FrontCrossLamp])//渐灭
        {
            gs_ramp_pwm.st_msRampRun[E_FrontCrossLamp] += ms;
            gs_ramp_pwm.pwm_Ramp[E_FrontCrossLamp] = 100-(100*gs_ramp_pwm.st_msRampRun[E_FrontCrossLamp]/lgtctl.pr_OffRamp[E_FrontCrossLamp]);
        }
        else lgtctl.st_LgtAct.ActCROS  = ACT_OFF; 
    }

    lgtctl.st_LgtAct.ActTIact = lgtctl.in_Act_cur.ActTIact;
}
static void Input_DelayRampFun(uint16 ms)
{
    Input_DelayFun(ms);
    Input_RampFun(ms);
}

Std_ReturnType Lighting_SetPwmRamp(E_ChannelID id)
{
    return gs_ramp_pwm.pwm_Ramp[id];
}


void Lighting_BasicFun(void)
{
    uint8 pwmper=100;
    E_ChannelID id=0;
    uint8 lgmask=0,chmask=0,lgmask1=0;
    uint16 cur=0;

    for(id=ChannelID1;id<CHANNEL_NUM;id++)
    {
/*************************************LB HB******************************************************/
        CH_CurStatus[id]=HB_RunMainFun(id,lgtctl.pr_channel_cur[id].CH_NormalCur,lgtctl.st_LgtAct.ActHB,&CH_CurStatus); //HB light main function
        CH_CurStatus[id]=LB_RunMainFun(id,lgtctl.pr_channel_cur[id].CH_NormalCur,lgtctl.st_LgtAct.ActLB,&CH_CurStatus);
//近光可以接CH1和CH1_Tap，远光可以接CH1_Tap或其他通道
/**************************************CH1 CH1_Tap******************************************************/
        if((0==CH_CurStatus[ChannelID1_Tap])&&(0==CH_CurStatus[ChannelID1])) //CH1 和 CH1Tap 关通道 
        {
            Interface_ChannelClose(ChannelID1);
            Interface_ChannelClose(ChannelID1_Tap);
        }
/*************************************位置 日行 转向******************************************************/
        lgmask=GetChannelMaskByLightFunction(E_TurnIndicator);
        if(((lgmask>>id)&0x01)!=0) 
        {
            if((lgtctl.st_LgtAct.ActTIsts==ACT_ON)&&(lgtctl.st_LgtAct.ActTIact==ACT_ON))//转向开
            {               
                CH_CurStatus[id] |=E_TI; //CH1 CH1_Tap
                cur=lgtctl.pr_channel_cur[id].CH_NormalCur*pwmper*gs_ramp_pwm.pwm_Ramp[E_TurnIndicator]/10000;
                TI_On(id,cur,&CH_CurStatus);
            }
            else
            {              
                CH_CurStatus[id] &= (~E_TI); 
                TI_Off(id);
            }   
            if((CH_CurStatus[id]&E_LB)!=0) 
            {
                SetLgtStsFb_TI(STS_ON);
            }
            else 
            {
                SetLgtStsFb_TI(STS_OFF);
            }  
        }
        lgmask=GetChannelMaskByLightFunction(E_DaytimeRunningLight);
        if(((lgmask>>id)&0x01)!=0) 
        {
            if(lgtctl.st_LgtAct.ActDRL==ACT_ON)
            {
                cur=lgtctl.pr_channel_cur[id].CH_NormalCur*pwmper*gs_ramp_pwm.pwm_Ramp[E_DaytimeRunningLight]/10000;
                CH_CurStatus[id]=DRL_On(id,cur,&CH_CurStatus);
            }
            else
            {
                CH_CurStatus[id]&= (~E_DRL); 
                lgmask1=GetChannelMaskByLightFunction(E_PositionLight);
                if((((lgmask1>>id)&0x01)!=0) && (lgtctl.st_LgtAct.ActPOS==ACT_ON)) 
                {
                    //share channel : pos is on ,not close 
                }
                else
                {
                    DRL_Off(id);
                }            
            }                
            if((CH_CurStatus[id]&E_DRL)!=0)
            {
                SetLgtStsFb_DRL(STS_ON);
            }
            else
            {
                SetLgtStsFb_DRL(STS_OFF);
            }
        }
        lgmask=GetChannelMaskByLightFunction(E_PositionLight);
        if(((lgmask>>id)&0x01)!=0) 
        {
            lgmask1=GetChannelMaskByLightFunction(E_DaytimeRunningLight);
            if((((lgmask1>>id)&0x01)!=0)&&(lgtctl.st_LgtAct.ActDRL==ACT_ON)) 
            {
                //the channel DRL on
                CH_CurStatus[id]&= (~E_POS); 
            }
            else
            {
                if(lgtctl.st_LgtAct.ActPOS==ACT_ON)
                {                 
                    cur=lgtctl.pr_channel_cur[id].CH_NormalCur*pwmper*gs_ramp_pwm.pwm_Ramp[E_PositionLight]/10000;
                    CH_CurStatus[id]=POS_On(id,cur,&CH_CurStatus);
                }
                else
                {
                    CH_CurStatus[id]&= (~E_POS); 
                    POS_Off(id);
                }       
            }
            if((CH_CurStatus[id]&E_POS)!=0)
            {
                SetLgtStsFb_POS(STS_ON);
            }
            else
            {
                SetLgtStsFb_POS(STS_OFF);
            }
        }
        if(( CH_CurStatus[ChannelID2]==0)&&(CH_CurStatus[ChannelID2_Alt]==0)) 
        {
            Interface_ChannelClose(ChannelID2);
            Interface_ChannelClose(ChannelID2_Alt);
        }
/************************************************************************************ */
        lgmask=GetChannelMaskByLightFunction(E_FrontCrossLamp);
        if(((lgmask>>id)&0x01)!=0) 
        {
            if(lgtctl.st_LgtAct.ActCROS==ACT_ON)
            {
                SetLgtStsFb_CROS(STS_ON);
                cur=lgtctl.pr_channel_cur[id].CH_NormalCur*pwmper*gs_ramp_pwm.pwm_Ramp[E_FrontCrossLamp]/10000;
                CROS_On(id,cur);
            }
            else
            {
                SetLgtStsFb_CROS(STS_OFF);   
                CROS_Off(id);
            }       
        }
    }
}

uint16 Lighting_Rek_Fun(void)
{
    return lgtctl.st_LgtSts.Light_Status;
}

/*灯光管理功能*/
Std_ReturnType Light_Manager(uint8 timebase)
{  
    Input_DelayRampFun(timebase);//delay + ramp 
    ChnCurrentSet();      // channel current
    Lighting_BasicFun(); //基础灯光执行点亮 降额+点灯控制
}




