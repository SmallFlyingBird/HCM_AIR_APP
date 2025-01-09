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
} S_ChannelCtrl_Config;
S_ChannelCtrl_Config gs_ChannelCtrlConfig[MAX_CHANNLE_NUM]; //注意该数组只能调用6个
typedef struct 
{
//延时开参数
    uint16  pr_onDelay_LB   ;
    uint16  pr_onDelay_HB   ;
    uint16  pr_onDelay_TI   ;
    uint16  pr_onDelay_DRL  ;
    uint16  pr_onDelay_POS  ;
    uint16  pr_onDelay_CROS ;

//延时关参数 
    uint16  pr_offDelay_LB   ;
    uint16  pr_offDelay_HB   ;
    uint16  pr_offDelay_TI   ;
    uint16  pr_offDelay_DRL  ;
    uint16  pr_offDelay_POS  ;
    uint16  pr_offDelay_CROS ;

//渐亮时间
    uint16  pr_OnRamp_LB   ;
    uint16  pr_OnRamp_HB   ;
    uint16  pr_OnRamp_TI   ;
    uint16  pr_OnRamp_DRL  ;
    uint16  pr_OnRamp_POS  ;
    uint16  pr_OnRamp_CROS ;

//渐灭时间
    uint16  pr_OffRamp_LB   ;
    uint16  pr_OffRamp_HB   ;
    uint16  pr_OffRamp_TI   ;
    uint16  pr_OffRamp_DRL  ;
    uint16  pr_OffRamp_POS  ;
    uint16  pr_OffRamp_CROS ;

    S_LgtActIns_t   in_Act_cur;    /* 当前命令输入 */

//记录命令状态的时间 
    uint16  st_msActLB   ;
    uint16  st_msActHB   ;
    uint16  st_msActTI   ;
    uint16  st_msActDRL  ;
    uint16  st_msActPOS  ;
    uint16  st_msActCROS ;

    S_LgtFuncEna_t  st_LgtEna;      /* 灯光功能使能 */
    S_LgtActIns_t   st_LgtAct;      /* 灯光动作指令 */
    S_LgtStsFb_t    st_LgtSts;      /* 灯光状态反馈 */
    S_LgtFuncEna_t  st_LgtDer;      /* 灯光降额禁止状态 */
    uint16        st_maskDer0;    /* 被降额到0的通道掩码 */

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
//渐亮渐灭占空比
    uint8 pwm_Ramp_LB   ;
    uint8 pwm_Ramp_HB   ;
    uint8 pwm_Ramp_TI   ;
    uint8 pwm_Ramp_DRL  ;
    uint8 pwm_Ramp_POS  ;
    uint8 pwm_Ramp_CROS ;

//渐亮渐灭执行时间
    uint16 st_msRampRun_LB   ;
    uint16 st_msRampRun_HB   ;
    uint16 st_msRampRun_TI   ;
    uint16 st_msRampRun_DRL  ;
    uint16 st_msRampRun_POS  ;
    uint16 st_msRampRun_CROS ;
}S_Pamp_Pwm;
static S_Pamp_Pwm gs_ramp_pwm;

void Light_Parameter_Init(void)
{
    uint8 ch=0;
    for(ch=0;ch<MAX_CHANNLE_NUM;ch++)
    {
        gs_ChannelCtrlConfig[ch].CH_NormalCur=Get_pLedNormalCurrent(ch);   //Interface_GetChannelParamTableNormalCurrent(ch);
    }
}
static void _inou_init(void)
{
//延时点亮读参数表
    lgtctl.pr_onDelay_LB    = Get_pLedONDelay(E_LowBeamKink);
    lgtctl.pr_onDelay_HB    = Get_pLedONDelay(E_HighBeamSpot);
    lgtctl.pr_onDelay_TI    = Get_pLedONDelay(E_TurnIndicator);
    lgtctl.pr_onDelay_DRL   = Get_pLedONDelay(E_DaytimeRunningLight);
    lgtctl.pr_onDelay_POS   = Get_pLedONDelay(E_PositionLight);
    lgtctl.pr_onDelay_CROS  = Get_pLedONDelay(E_FrontCrossLamp);

    lgtctl.pr_offDelay_LB   = Get_pLedOFFDelay(E_LowBeamKink);
    lgtctl.pr_offDelay_HB   = Get_pLedOFFDelay(E_HighBeamSpot);
    lgtctl.pr_offDelay_TI   = Get_pLedOFFDelay(E_TurnIndicator);
    lgtctl.pr_offDelay_DRL  = Get_pLedOFFDelay(E_DaytimeRunningLight);
    lgtctl.pr_offDelay_POS  = Get_pLedOFFDelay(E_PositionLight);
    lgtctl.pr_offDelay_CROS = Get_pLedOFFDelay(E_FrontCrossLamp);

//渐亮渐灭读参数表
    lgtctl.pr_OnRamp_LB    = Get_pLedOnRampTi(E_LowBeamKink);
    lgtctl.pr_OnRamp_HB    = Get_pLedOnRampTi(E_HighBeamSpot);
    lgtctl.pr_OnRamp_TI    = Get_pLedOnRampTi(E_TurnIndicator);
    lgtctl.pr_OnRamp_DRL   = Get_pLedOnRampTi(E_DaytimeRunningLight);
    lgtctl.pr_OnRamp_POS   = Get_pLedOnRampTi(E_PositionLight);
    lgtctl.pr_OnRamp_CROS  = Get_pLedOnRampTi(E_FrontCrossLamp);

    lgtctl.pr_OffRamp_LB   = Get_pLedOffRampTi(E_LowBeamKink);
    lgtctl.pr_OffRamp_HB   = Get_pLedOffRampTi(E_HighBeamSpot);
    lgtctl.pr_OffRamp_TI   = Get_pLedOffRampTi(E_TurnIndicator);
    lgtctl.pr_OffRamp_DRL  = Get_pLedOffRampTi(E_DaytimeRunningLight);
    lgtctl.pr_OffRamp_POS  = Get_pLedOffRampTi(E_PositionLight);
    lgtctl.pr_OffRamp_CROS = Get_pLedOffRampTi(E_FrontCrossLamp);
}

Std_ReturnType Lighting_Init(void)
{
    _inou_init();
    Light_Parameter_Init(); //正常工作电流
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
    if (lgtctl.st_msActLB   <= top) { lgtctl.st_msActLB   += ms; }
    if (lgtctl.st_msActHB   <= top) { lgtctl.st_msActHB   += ms; }
    if (lgtctl.st_msActTI   <= top) { lgtctl.st_msActTI   += ms; }
    if (lgtctl.st_msActDRL  <= top) { lgtctl.st_msActDRL  += ms; }
    if (lgtctl.st_msActPOS  <= top) { lgtctl.st_msActPOS  += ms; }
    if (lgtctl.st_msActCROS <= top) { lgtctl.st_msActCROS += ms; }

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
        lgtctl.st_msActLB = 0; 
        gs_ramp_pwm.st_msRampRun_LB=0; 
    }
    if((linsignal.Bits.HB_Ena != lgtctl.in_Act_cur.ActHB))        
    {
        lgtctl.st_msActHB = 0;  
        gs_ramp_pwm.st_msRampRun_HB=0; 
    }
    if((linsignal.Bits.Pos_Ena != lgtctl.in_Act_cur.ActPOS))        
    {
        lgtctl.st_msActPOS = 0; 
        gs_ramp_pwm.st_msRampRun_POS=0; 
    }
    if((linsignal.Bits.Drl_Ena != lgtctl.in_Act_cur.ActDRL))        
    { 
        lgtctl.st_msActDRL = 0; 
        gs_ramp_pwm.st_msRampRun_DRL=0; 
    }
    if((linsignal.Bits.Turn_Sts != lgtctl.in_Act_cur.ActTIsts))     
    { 
        lgtctl.st_msActTI = 0;  
        gs_ramp_pwm.st_msRampRun_TI=0; 
    }
    if((linsignal.Bits.CROS_Ena != lgtctl.in_Act_cur.ActCROS))      
    { 
        lgtctl.st_msActCROS = 0;
        gs_ramp_pwm.st_msRampRun_CROS=0; 
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
    if ((lgtctl.in_Act_cur.ActLB    == ACT_ON)  && (lgtctl.st_msActLB   >= lgtctl.pr_onDelay_LB  ))  //延时点亮结束 进入渐亮阶段
    {
        lgtctl.st_LgtAct.ActLB = ACT_ON; 
        if(gs_ramp_pwm.st_msRampRun_LB<lgtctl.pr_OnRamp_LB)//渐亮
        {
            gs_ramp_pwm.st_msRampRun_LB += ms;
            gs_ramp_pwm.pwm_Ramp_LB = 100*gs_ramp_pwm.st_msRampRun_LB/lgtctl.pr_OnRamp_LB;
        }
        else gs_ramp_pwm.pwm_Ramp_LB=100;
    }
    if ((lgtctl.in_Act_cur.ActHB == ACT_ON)  && (lgtctl.st_msActHB   >= lgtctl.pr_onDelay_HB  ))  
    { 
        lgtctl.st_LgtAct.ActHB = ACT_ON; 
        if(gs_ramp_pwm.st_msRampRun_HB<lgtctl.pr_OnRamp_HB)//渐亮
        {
            gs_ramp_pwm.st_msRampRun_HB += ms;
            gs_ramp_pwm.pwm_Ramp_HB = 100*gs_ramp_pwm.st_msRampRun_HB/lgtctl.pr_OnRamp_HB;
        }
        else gs_ramp_pwm.pwm_Ramp_HB=100;
    }
    if ((lgtctl.in_Act_cur.ActTIsts == ACT_ON) && (lgtctl.st_msActTI   >= lgtctl.pr_onDelay_TI  ))  
    { 
        lgtctl.st_LgtAct.ActTIsts = ACT_ON; 
        if(gs_ramp_pwm.st_msRampRun_TI<lgtctl.pr_OnRamp_TI)//渐亮
        {
            gs_ramp_pwm.st_msRampRun_TI += ms;
            gs_ramp_pwm.pwm_Ramp_TI = 100*gs_ramp_pwm.st_msRampRun_TI/lgtctl.pr_OnRamp_TI;
        }
        else gs_ramp_pwm.pwm_Ramp_TI=100;
    }
    if ((lgtctl.in_Act_cur.ActDRL == ACT_ON) && (lgtctl.st_msActDRL  >= lgtctl.pr_onDelay_DRL ))  
    {
        lgtctl.st_LgtAct.ActDRL = ACT_ON; 
        if(gs_ramp_pwm.st_msRampRun_DRL<lgtctl.pr_OnRamp_DRL)//渐亮
        {
            gs_ramp_pwm.st_msRampRun_DRL += ms;
            gs_ramp_pwm.pwm_Ramp_DRL = 100*gs_ramp_pwm.st_msRampRun_DRL/lgtctl.pr_OnRamp_DRL;
        }
        else gs_ramp_pwm.pwm_Ramp_DRL=100;
    }
    if ((lgtctl.in_Act_cur.ActPOS == ACT_ON) && (lgtctl.st_msActPOS  >= lgtctl.pr_onDelay_POS ))  
    {
        lgtctl.st_LgtAct.ActPOS   = ACT_ON; 
        if(gs_ramp_pwm.st_msRampRun_POS<lgtctl.pr_OnRamp_POS)//渐亮
        {
            gs_ramp_pwm.st_msRampRun_POS += ms;
            gs_ramp_pwm.pwm_Ramp_POS = 100*gs_ramp_pwm.st_msRampRun_POS/lgtctl.pr_OnRamp_POS;
        }
        else gs_ramp_pwm.pwm_Ramp_POS=100;
    }
    if ((lgtctl.in_Act_cur.ActCROS == ACT_ON) && (lgtctl.st_msActCROS >= lgtctl.pr_onDelay_CROS))  
    { 
        lgtctl.st_LgtAct.ActCROS  = ACT_ON; 
        if(gs_ramp_pwm.st_msRampRun_CROS<lgtctl.pr_OnRamp_CROS)//渐亮
        {
            gs_ramp_pwm.st_msRampRun_CROS += ms;
            gs_ramp_pwm.pwm_Ramp_CROS = 100*gs_ramp_pwm.st_msRampRun_CROS/lgtctl.pr_OnRamp_CROS;
        }
        else gs_ramp_pwm.pwm_Ramp_CROS=100;
    }
//延时熄灭结束，进入渐灭阶段
    if ((lgtctl.in_Act_cur.ActLB == ACT_OFF) && (lgtctl.st_msActLB   >= lgtctl.pr_offDelay_LB  )) 
    { 
        if(gs_ramp_pwm.st_msRampRun_LB<lgtctl.pr_OffRamp_LB)//渐灭
        {
            gs_ramp_pwm.st_msRampRun_LB += ms;
            gs_ramp_pwm.pwm_Ramp_LB = 100-(100*gs_ramp_pwm.st_msRampRun_LB/lgtctl.pr_OffRamp_LB);
        }
        else lgtctl.st_LgtAct.ActLB = ACT_OFF; //渐灭时间到 关灯
    }
    if ((lgtctl.in_Act_cur.ActHB == ACT_OFF) && (lgtctl.st_msActHB   >= lgtctl.pr_offDelay_HB  )) 
    {
        if(gs_ramp_pwm.st_msRampRun_HB<lgtctl.pr_OffRamp_HB)//渐灭
        {
            gs_ramp_pwm.st_msRampRun_HB += ms;
            gs_ramp_pwm.pwm_Ramp_HB = 100-(100*gs_ramp_pwm.st_msRampRun_HB/lgtctl.pr_OffRamp_HB);
        }
        else lgtctl.st_LgtAct.ActHB = ACT_OFF; 
    }
    if ((lgtctl.in_Act_cur.ActTIsts == ACT_OFF) && (lgtctl.st_msActTI   >= lgtctl.pr_offDelay_TI  )) 
    { 
        if(gs_ramp_pwm.st_msRampRun_TI<lgtctl.pr_OffRamp_TI)//渐灭
        {
            gs_ramp_pwm.st_msRampRun_TI += ms;
            gs_ramp_pwm.pwm_Ramp_TI = 100-(100*gs_ramp_pwm.st_msRampRun_TI/lgtctl.pr_OffRamp_TI);
        }
        else lgtctl.st_LgtAct.ActTIsts = ACT_OFF; 
    }
    if ((lgtctl.in_Act_cur.ActDRL == ACT_OFF) && (lgtctl.st_msActDRL  >= lgtctl.pr_offDelay_DRL )) 
    { 
        if(gs_ramp_pwm.st_msRampRun_DRL<lgtctl.pr_OffRamp_DRL)//渐灭
        {
            gs_ramp_pwm.st_msRampRun_DRL += ms;
            gs_ramp_pwm.pwm_Ramp_DRL = 100-(100*gs_ramp_pwm.st_msRampRun_DRL/lgtctl.pr_OffRamp_DRL);
        }
        else lgtctl.st_LgtAct.ActDRL   = ACT_OFF; 
    }
    if ((lgtctl.in_Act_cur.ActPOS == ACT_OFF) && (lgtctl.st_msActPOS  >= lgtctl.pr_offDelay_POS )) 
    { 
        if(gs_ramp_pwm.st_msRampRun_HB<lgtctl.pr_OffRamp_HB)//渐灭
        {
            gs_ramp_pwm.st_msRampRun_HB += ms;
            gs_ramp_pwm.pwm_Ramp_HB = 100-(100*gs_ramp_pwm.st_msRampRun_HB/lgtctl.pr_OffRamp_HB);
        }
        else lgtctl.st_LgtAct.ActPOS   = ACT_OFF; 
    }
    if ((lgtctl.in_Act_cur.ActCROS == ACT_OFF) && (lgtctl.st_msActCROS >= lgtctl.pr_offDelay_CROS)) 
    { 
        if(gs_ramp_pwm.st_msRampRun_CROS<lgtctl.pr_OffRamp_CROS)//渐灭
        {
            gs_ramp_pwm.st_msRampRun_CROS += ms;
            gs_ramp_pwm.pwm_Ramp_CROS = 100-(100*gs_ramp_pwm.st_msRampRun_CROS/lgtctl.pr_OffRamp_CROS);
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

void Lighting_BasicFun(void)
{
    uint8 pwmper=100;
    E_ChannelID id=0;
    uint8 lgmask=0,chmask=0,lgmask1=0;
    uint16 cur=0;

    for(id=ChannelID1;id<CHANNEL_NUM;id++)
    {
/************************************* 近光 远光******************************************************/
        lgmask=GetChannelMaskByLightFunction(E_HighBeamSpot);
        if(((lgmask>>id)&0x01)!=0) 
        {
            if(lgtctl.st_LgtAct.ActHB==ACT_ON)
            {
                pwmper=Interface_GetChannelDerateRatio(id);
                cur=gs_ChannelCtrlConfig[id].CH_NormalCur*pwmper*gs_ramp_pwm.pwm_Ramp_HB/10000;
                CH_CurStatus[id] |= E_HB; //CH1 CH1_Tap is one channel
                SetLgtStsFb_HB(STS_ON);
                HB_On(id,cur);
            }
            else
            {             
                CH_CurStatus[id] &=(~E_HB); 
                SetLgtStsFb_HB(STS_OFF);
                HB_Off(id);
            }
        }
        lgmask=GetChannelMaskByLightFunction(E_LowBeamKink);
        if(((lgmask>>id)&0x01)!=0) 
        {
            if(lgtctl.st_LgtAct.ActLB==ACT_ON)
            {               
                pwmper=Interface_GetChannelDerateRatio(id);
                cur=gs_ChannelCtrlConfig[id].CH_NormalCur*pwmper*gs_ramp_pwm.pwm_Ramp_LB/10000;
                CH_CurStatus[id] |=E_LB; 
                SetLgtStsFb_LB(STS_ON);
                LB_On(id,cur);
            }
            else
            {
                CH_CurStatus[id] &=(~E_LB); //CH1 CH1_Tap会相互影响
                SetLgtStsFb_LB(STS_OFF); 
                LB_Off(id);             
            }
        }
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
                SetLgtStsFb_TI(STS_ON);
                CH_CurStatus[id] |=E_TI; //CH1 CH1_Tap
                pwmper=Interface_GetChannelDerateRatio(id);
                cur=gs_ChannelCtrlConfig[id].CH_NormalCur*pwmper*gs_ramp_pwm.pwm_Ramp_TI/10000;
                TI_On(id,cur,&CH_CurStatus);
            }
            else
            {
                SetLgtStsFb_TI(STS_OFF);
                CH_CurStatus[id] &= (~E_TI); 
                TI_Off(id);
            }       
        }
        lgmask=GetChannelMaskByLightFunction(E_DaytimeRunningLight);
        if(((lgmask>>id)&0x01)!=0) 
        {
            if(lgtctl.st_LgtAct.ActDRL==ACT_ON)
            {
                pwmper=Interface_GetChannelDerateRatio(id);
                cur=gs_ChannelCtrlConfig[id].CH_NormalCur*pwmper*gs_ramp_pwm.pwm_Ramp_DRL/10000;
                CH_CurStatus[id]=DRL_On(id,cur,&CH_CurStatus);
               
                if((CH_CurStatus[id]&E_DRL)!=0)
                {
                    SetLgtStsFb_DRL(STS_ON);
                }
                else
                {
                    SetLgtStsFb_DRL(STS_OFF);
                }
            }
            else
            {
                SetLgtStsFb_DRL(STS_OFF);
                CH_CurStatus[id]&= (~E_DRL); 
                lgmask1=GetChannelMaskByLightFunction(E_PositionLight);
                if((((lgmask1>>id)&0x01)!=0) && (lgtctl.st_LgtAct.ActPOS==ACT_ON)) //日行 位置 通道共用 && 位置灯正开启 ,不执行
                {
                    //share channel : pos is on ,not close 
                }
                else
                {
                    DRL_Off(id);
                }            
            }
        }
        lgmask=GetChannelMaskByLightFunction(E_PositionLight);
        if(((lgmask>>id)&0x01)!=0) 
        {
            lgmask1=GetChannelMaskByLightFunction(E_DaytimeRunningLight);
            if((((lgmask1>>id)&0x01)!=0)&&(lgtctl.st_LgtAct.ActDRL==ACT_ON)) 
            {
                //the channel DRL on
                SetLgtStsFb_POS(STS_OFF);
                CH_CurStatus[id]&= (~E_POS); 
            }
            else
            {
                if(lgtctl.st_LgtAct.ActPOS==ACT_ON)
                {
                    pwmper=Interface_GetChannelDerateRatio(id);
                   
                    cur=gs_ChannelCtrlConfig[id].CH_NormalCur*pwmper*gs_ramp_pwm.pwm_Ramp_POS/10000;
                    CH_CurStatus[id]=POS_On(id,cur,&CH_CurStatus);
                    if((CH_CurStatus[id]&E_POS)!=0)
                    {
                        SetLgtStsFb_POS(STS_ON);
                    }
                    else
                    {
                        SetLgtStsFb_POS(STS_OFF);
                    }
                    // if(id==ChannelID2)
                    // {
                    //     if((CH_CurStatus[ChannelID2_Alt]&E_TI)!=0)//需点亮位置CH2,但转向已打开且位于CH2_Alt
                    //     {
                    //         Port_CH2_Disable();
                    //         SetLgtStsFb_POS(STS_OFF);
                    //         CH_CurStatus[id]&= (~E_POS);
                    //     }
                    //     else
                    //     {
                    //         Port_CH2_Enable();
                    //         SetLgtStsFb_POS(STS_ON);
                    //         CH_CurStatus[id] |=E_POS; 
                    //     }
                    // }
                    // else if(id==ChannelID2_Alt) 
                    // {
                    //     if((CH_CurStatus[ChannelID2_Alt]&E_TI)!=0)//需点亮日行CH2,但转向已打开，且位于CH2
                    //     {
                    //         Port_CH2Alt_Disable();
                    //         SetLgtStsFb_POS(STS_OFF);
                    //         CH_CurStatus[id]&= (~E_POS);
                    //     }
                    //     else
                    //     {
                    //         Port_CH2Alt_Enable();
                    //         SetLgtStsFb_POS(STS_ON);
                    //         CH_CurStatus[id]|=E_POS;
                    //     }
                    // }
                    // else 
                    // {
                    //     SetLgtStsFb_POS(STS_ON);
                    //     CH_CurStatus[id] |=E_POS; 
                    // }
                    // if((CH_CurStatus[id]&E_POS)!=0)
                    // {
                    //     Interface_SetChannelCurrent(id,cur); //设置通道电流
                    //     Interface_SetChannelSwitchState(id, CHANNEL_STATE_ON); 
                    // }
                }
                else
                {
                    SetLgtStsFb_POS(STS_OFF);
                    CH_CurStatus[id]&= (~E_POS); 
                    POS_Off(id);
                }       
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
                pwmper=Interface_GetChannelDerateRatio(id);
                cur=gs_ChannelCtrlConfig[id].CH_NormalCur*pwmper*gs_ramp_pwm.pwm_Ramp_CROS/10000;
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
    Input_DelayRampFun(timebase);//delay + ramp +
    Lighting_BasicFun(); //基础灯光执行点亮 降额+点灯控制
}




