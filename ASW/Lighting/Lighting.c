#include "HcmPlatform.h"
#include "Lighting.h"
#include "LinManager.h"
#include "Ex_SleepWakeup.h"
#include "Dio_Service.h"
#include "Pwm_Service.h"
#include "Parameter_Interface.h"
#include "OUVDerate_Interface.h"
#include "Channel_Interface.h"

uint16 test[20]={0}; //测试用
S_Lin_LControl linsignal={0};
typedef enum
{
    Light_ON  = 1,
    Light_OFF = 0,
}LightSwitchState;

typedef struct
{
    uint8 perpwm[6];
}S_LightingCtrl;
S_LightingCtrl gs_lighting_ctrl;

typedef struct
{
    uint16 CH_NormalCur; /*Para table Normal Current*/
} S_ChannelCtrl_Config;
S_ChannelCtrl_Config gs_ChannelCtrlConfig[MAX_CHANNLE_NUM]=
{
    {.CH_NormalCur = 250, },
    {.CH_NormalCur = 250, },
    {.CH_NormalCur = 250, },
    {.CH_NormalCur = 250, },
    {.CH_NormalCur = 250, },
    {.CH_NormalCur = 250, },
};


typedef struct _
{
    /* Channel mask */
    uint16_t        pr_ChMask_LB   ;
    uint16_t        pr_ChMask_HB   ;
    uint16_t        pr_ChMask_TI   ;
    uint16_t        pr_ChMask_DRL  ;
    uint16_t        pr_ChMask_POS  ;
    uint16_t        pr_ChMask_CORN ;
    uint16_t        pr_ChMask_FOG  ;
    uint16_t        pr_ChMask_LOGO ;
    uint16_t        pr_ChMask_CROS ;
    uint16_t        pr_ChMask_GRIL ;
    uint16_t        pr_ChMask_ASSI ;

    /* 延时开参数 */
    uint16_t        pr_onDelay_LB   ;
    uint16_t        pr_onDelay_HB   ;
    uint16_t        pr_onDelay_TI   ;
    uint16_t        pr_onDelay_DRL  ;
    uint16_t        pr_onDelay_POS  ;
    uint16_t        pr_onDelay_CORN ;
    uint16_t        pr_onDelay_FOG  ;
    uint16_t        pr_onDelay_LOGO ;
    uint16_t        pr_onDelay_CROS ;
    uint16_t        pr_onDelay_GRIL ;

    /* 延时关参数 */
    uint16_t        pr_offDelay_LB   ;
    uint16_t        pr_offDelay_HB   ;
    uint16_t        pr_offDelay_TI   ;
    uint16_t        pr_offDelay_DRL  ;
    uint16_t        pr_offDelay_POS  ;
    uint16_t        pr_offDelay_CORN ;
    uint16_t        pr_offDelay_FOG  ;
    uint16_t        pr_offDelay_LOGO ;
    uint16_t        pr_offDelay_CROS ;
    uint16_t        pr_offDelay_GRIL ;

    S_LgtActIns_t   in_Act_cur;    /* 当前命令输入 */
    S_LgtActIns_t   in_Act_per;    /* 前次命令输入 */

    /* 记录命令状态的时间 */
    uint16_t        st_msActLB   ;
    uint16_t        st_msActHB   ;
    uint16_t        st_msActTI   ;
    uint16_t        st_msActDRL  ;
    uint16_t        st_msActPOS  ;
    uint16_t        st_msActCORN ;
    uint16_t        st_msActFOG  ;
    uint16_t        st_msActLOGO ;
    uint16_t        st_msActCROS ;
    uint16_t        st_msActGRIL ;

    /*****************************************************/

    S_LgtFuncEna_t  st_LgtEna;      /* 灯光功能使能 */
    S_LgtActIns_t   st_LgtAct;      /* 灯光动作指令 */
    S_LgtStsFb_t    st_LgtSts;      /* 灯光状态反馈 */

    S_LgtFuncEna_t  st_LgtDer;      /* 灯光降额禁止状态 */
    uint16_t        st_maskDer0;    /* 被降额到0的通道掩码 */

    S_LgtFuncEna_t  st_LgtOnDis;    /* 灯光当前开命令周期内 禁止状态 */

    /* Lighting Disable Source */
    U_DisSrc_t      st_LgtDS_LB      ;
    U_DisSrc_t      st_LgtDS_TI      ;
    U_DisSrc_t      st_LgtDS_POS     ;
    U_DisSrc_t      st_LgtDS_SML     ;
    U_DisSrc_t      st_LgtDS_HB      ;
    U_DisSrc_t      st_LgtDS_DRL     ;
    U_DisSrc_t      st_LgtDS_CORN    ;
    U_DisSrc_t      st_LgtDS_FOG     ;
    U_DisSrc_t      st_LgtDS_CROS    ;
    U_DisSrc_t      st_LgtDS_GRIL    ;
    U_DisSrc_t      st_LgtDS_LOGO    ;
    U_DisSrc_t      st_LgtDS_WELC    ;
}S_LightingCtl_t;

static S_LightingCtl_t lgtctl;

void Light_Parameter_Init(void)
{
    uint8 ch=0;
    for(ch=0;ch<MAX_CHANNLE_NUM;ch++)
    {
        gs_ChannelCtrlConfig[ch].CH_NormalCur=Interface_GetChannelParamTableNormalCurrent(ch);
    }
}

// static void _input(uint16_t ms)
// {
//     uint8  u8v;
//     uint16 u16v;
//     uint32 u32v;
//     uint16 top = 0xFFFF - ms;
// //延时开灯和延时关灯计时
//     if (lgtctl.st_msActLB   <= top) { lgtctl.st_msActLB   += ms; }
//     if (lgtctl.st_msActHB   <= top) { lgtctl.st_msActHB   += ms; }
//     if (lgtctl.st_msActTI   <= top) { lgtctl.st_msActTI   += ms; }
//     if (lgtctl.st_msActDRL  <= top) { lgtctl.st_msActDRL  += ms; }
//     if (lgtctl.st_msActPOS  <= top) { lgtctl.st_msActPOS  += ms; }
//     if (lgtctl.st_msActCORN <= top) { lgtctl.st_msActCORN += ms; }
//     if (lgtctl.st_msActFOG  <= top) { lgtctl.st_msActFOG  += ms; }
//     if (lgtctl.st_msActLOGO <= top) { lgtctl.st_msActLOGO += ms; }
//     if (lgtctl.st_msActCROS <= top) { lgtctl.st_msActCROS += ms; }
//     if (lgtctl.st_msActGRIL <= top) { lgtctl.st_msActGRIL += ms; }

// //取得网络上灯功能动作输入指令
//     linsignal=Interface_Get_LinSignal();
//     if(linsignal.Bits.LB_Ena==Light_ON)
//     { 
//         if(Light_ON != lgtctl.in_Act_cur.ActLB)
//         {
//             lgtctl.st_msActLB   = 0;
//         }
//         lgtctl.in_Act_cur.ActLB = Light_ON; 
//     }
//     else if(Light_OFF != lgtctl.in_Act_cur.ActLB)
//     {
//         lgtctl.st_msActLB   = 0;
//     }
//     if (linsignal.Bits.Pos_Ena==Light_ON) 
//     { 
//         lgtctl.in_Act_per.ActPOS = lgtctl.in_Act_cur.ActPOS;
//         lgtctl.in_Act_cur.ActPOS = Light_ON; 
//     }
//     if (linsignal.Bits.HB_Ena==Light_ON) 
//     { 
//         lgtctl.in_Act_per.ActHB = lgtctl.in_Act_cur.ActHB; 
//         lgtctl.in_Act_cur.ActHB = Light_ON; 
//     }
//     if (linsignal.Bits.Turn_Sts==Light_ON) 
//     { 
//         lgtctl.in_Act_per.ActTIsts = lgtctl.in_Act_cur.ActTIsts;
//         lgtctl.in_Act_cur.ActTIsts = Light_ON;
//     }
//     if (linsignal.Bits.Turn_Act==Light_ON)
//     { 
//         lgtctl.in_Act_per.ActTIact = lgtctl.in_Act_cur.ActTIact;
//         lgtctl.in_Act_cur.ActTIact = Light_ON; 
//     }
//     if (linsignal.Bits.Drl_Ena==Light_ON)
//     { 
//         lgtctl.in_Act_per.ActDRL = lgtctl.in_Act_cur.ActDRL;
//         lgtctl.in_Act_cur.ActDRL = Light_ON; 
//     }
//     if (linsignal.Bits.CROS_Ena==Light_ON)
//     { 
//         lgtctl.in_Act_per.ActCROS = lgtctl.in_Act_cur.ActCROS;
//         lgtctl.in_Act_cur.ActCROS = Light_ON; 
//     }

//     /* 判断灯功能动作输入指令变化 */
//     if ((lgtctl.in_Act_cur.ActLB    == ACT_ON) && (lgtctl.in_Act_per.ActLB    == ACT_OFF)) { lgtctl.in_Act_per.ActLB    = ACT_ON;   }
//     if ((lgtctl.in_Act_cur.ActHB    == ACT_ON) && (lgtctl.in_Act_per.ActHB    == ACT_OFF)) { lgtctl.in_Act_per.ActHB    = ACT_ON;  lgtctl.st_msActHB   = 0; }
//     if ((lgtctl.in_Act_cur.ActTIsts == ACT_ON) && (lgtctl.in_Act_per.ActTIsts == ACT_OFF)) { lgtctl.in_Act_per.ActTIsts = ACT_ON;  lgtctl.st_msActTI   = 0; }
//     if ((lgtctl.in_Act_cur.ActDRL   == ACT_ON) && (lgtctl.in_Act_per.ActDRL   == ACT_OFF)) { lgtctl.in_Act_per.ActDRL   = ACT_ON;  lgtctl.st_msActDRL  = 0; }
//     if ((lgtctl.in_Act_cur.ActPOS   == ACT_ON) && (lgtctl.in_Act_per.ActPOS   == ACT_OFF)) { lgtctl.in_Act_per.ActPOS   = ACT_ON;  lgtctl.st_msActPOS  = 0; }
//     if ((lgtctl.in_Act_cur.ActCROS  == ACT_ON) && (lgtctl.in_Act_per.ActCROS  == ACT_OFF)) { lgtctl.in_Act_per.ActCROS  = ACT_ON;  lgtctl.st_msActCROS = 0; }
//     if ((lgtctl.in_Act_cur.ActLB    == ACT_OFF) && (lgtctl.in_Act_per.ActLB    == ACT_ON)) { lgtctl.in_Act_per.ActLB    = ACT_OFF; lgtctl.st_msActLB   = 0; }
//     if ((lgtctl.in_Act_cur.ActHB    == ACT_OFF) && (lgtctl.in_Act_per.ActHB    == ACT_ON)) { lgtctl.in_Act_per.ActHB    = ACT_OFF; lgtctl.st_msActHB   = 0; }
//     if ((lgtctl.in_Act_cur.ActTIsts == ACT_OFF) && (lgtctl.in_Act_per.ActTIsts == ACT_ON)) { lgtctl.in_Act_per.ActTIsts = ACT_OFF; lgtctl.st_msActTI   = 0; }
//     if ((lgtctl.in_Act_cur.ActDRL   == ACT_OFF) && (lgtctl.in_Act_per.ActDRL   == ACT_ON)) { lgtctl.in_Act_per.ActDRL   = ACT_OFF; lgtctl.st_msActDRL  = 0; }
//     if ((lgtctl.in_Act_cur.ActPOS   == ACT_OFF) && (lgtctl.in_Act_per.ActPOS   == ACT_ON)) { lgtctl.in_Act_per.ActPOS   = ACT_OFF; lgtctl.st_msActPOS  = 0; }
//     if ((lgtctl.in_Act_cur.ActCROS  == ACT_OFF) && (lgtctl.in_Act_per.ActCROS  == ACT_ON)) { lgtctl.in_Act_per.ActCROS  = ACT_OFF; lgtctl.st_msActCROS = 0; }

//     /* 根据延时配置，设置灯功能动作标志 */
//     if ((lgtctl.in_Act_per.ActLB    == ACT_ON)  && (lgtctl.st_msActLB   >= lgtctl.pr_onDelay_LB  ))  { lgtctl.st_LgtAct.ActLB    = ACT_ON; }
//     if ((lgtctl.in_Act_per.ActHB    == ACT_ON)  && (lgtctl.st_msActHB   >= lgtctl.pr_onDelay_HB  ))  { lgtctl.st_LgtAct.ActHB    = ACT_ON; }
//     if ((lgtctl.in_Act_per.ActTIsts == ACT_ON)  && (lgtctl.st_msActTI   >= lgtctl.pr_onDelay_TI  ))  { lgtctl.st_LgtAct.ActTIsts = ACT_ON; }
//     if ((lgtctl.in_Act_per.ActDRL   == ACT_ON)  && (lgtctl.st_msActDRL  >= lgtctl.pr_onDelay_DRL ))  { lgtctl.st_LgtAct.ActDRL   = ACT_ON; }
//     if ((lgtctl.in_Act_per.ActPOS   == ACT_ON)  && (lgtctl.st_msActPOS  >= lgtctl.pr_onDelay_POS ))  { lgtctl.st_LgtAct.ActPOS   = ACT_ON; }
//     if ((lgtctl.in_Act_per.ActCROS  == ACT_ON)  && (lgtctl.st_msActCROS >= lgtctl.pr_onDelay_CROS))  { lgtctl.st_LgtAct.ActCROS  = ACT_ON; }
//     if ((lgtctl.in_Act_per.ActLB    == ACT_OFF) && (lgtctl.st_msActLB   >= lgtctl.pr_offDelay_LB  )) { lgtctl.st_LgtAct.ActLB    = ACT_OFF; }
//     if ((lgtctl.in_Act_per.ActHB    == ACT_OFF) && (lgtctl.st_msActHB   >= lgtctl.pr_offDelay_HB  )) { lgtctl.st_LgtAct.ActHB    = ACT_OFF; }
//     if ((lgtctl.in_Act_per.ActTIsts == ACT_OFF) && (lgtctl.st_msActTI   >= lgtctl.pr_offDelay_TI  )) { lgtctl.st_LgtAct.ActTIsts = ACT_OFF; }
//     if ((lgtctl.in_Act_per.ActDRL   == ACT_OFF) && (lgtctl.st_msActDRL  >= lgtctl.pr_offDelay_DRL )) { lgtctl.st_LgtAct.ActDRL   = ACT_OFF; }
//     if ((lgtctl.in_Act_per.ActPOS   == ACT_OFF) && (lgtctl.st_msActPOS  >= lgtctl.pr_offDelay_POS )) { lgtctl.st_LgtAct.ActPOS   = ACT_OFF; }
//     if ((lgtctl.in_Act_per.ActCROS  == ACT_OFF) && (lgtctl.st_msActCROS >= lgtctl.pr_offDelay_CROS)) { lgtctl.st_LgtAct.ActCROS  = ACT_OFF; }

//     lgtctl.st_LgtAct.ActTIact = lgtctl.in_Act_cur.ActTIact;

//     lgtctl.st_LgtAct.ActTInoseq = lgtctl.in_Act_cur.ActTInoseq;
// }


void LB_HB_RUN(uint8 pwmper)
{
    uint8 chmask=0;
    chmask=GetChannelMaskByLightFunction(E_HighBeamSail);
    if(((chmask>>1)&0x01)!=0)
    {
        if(linsignal.Bits.HB_Ena==Light_ON)//远光
        {
            Pwm_CH1Tap_Enable();
            Interface_SetChannelCurrent((E_ChannelID)ChannelID1_Tap,gs_ChannelCtrlConfig[ChannelID1_Tap].CH_NormalCur*pwmper/100); //设置通道电流
            Interface_SetChannelSwitchState((E_ChannelID)ChannelID1_Tap, CHANNEL_STATE_ON); 
        }
        else 
        {
            Pwm_CH1Tap_Disable();
            if(linsignal.Bits.LB_Ena==Light_ON)//近光
            {
                Interface_SetChannelCurrent((E_ChannelID)ChannelID1, gs_ChannelCtrlConfig[ChannelID1].CH_NormalCur*pwmper/100); //设置通道电流
                Interface_SetChannelSwitchState((E_ChannelID)ChannelID1, CHANNEL_STATE_ON); 
            }
            else 
            {
                Interface_SetChannelCurrent((E_ChannelID)ChannelID1_Tap, 0); //设置通道电流
                Interface_SetChannelSwitchState((E_ChannelID)ChannelID1_Tap, CHANNEL_STATE_OFF); 
                Interface_SetChannelCurrent((E_ChannelID)ChannelID1, 0); //设置通道电流
                Interface_SetChannelSwitchState((E_ChannelID)ChannelID1, CHANNEL_STATE_OFF); 
            }
        }
    }
    else 
    {
        if(linsignal.Bits.LB_Ena==Light_ON)//近光开
        {
            Interface_SetChannelCurrent((E_ChannelID)ChannelID1, gs_ChannelCtrlConfig[ChannelID1].CH_NormalCur*pwmper/100); //设置通道电流
            Interface_SetChannelSwitchState((E_ChannelID)ChannelID1, CHANNEL_STATE_ON); 
        }
        else 
        {
            Interface_SetChannelCurrent((E_ChannelID)ChannelID1, 0); //设置通道电流
            Interface_SetChannelSwitchState((E_ChannelID)ChannelID1, CHANNEL_STATE_OFF); 
        } 
    }
}

void PosDrlTurn_Run(uint8 pwmper)
{
    uint8 chmask=0;
    chmask=GetChannelMaskByLightFunction(E_TurnIndicator);
//通道共用 通过IO口切换
    if(((chmask>>3)&0x01)!=0)
    {
        if(linsignal.Bits.Turn_Act==Light_ON)//转向开
        {
            Port_DrlPos_Disable();
            Port_TL_Enable(); 
            Interface_SetChannelCurrent((E_ChannelID)ChannelID2_Alt,gs_ChannelCtrlConfig[ChannelID2_Alt].CH_NormalCur*pwmper/100); //设置通道电流
            Interface_SetChannelSwitchState((E_ChannelID)ChannelID2_Alt, CHANNEL_STATE_ON); 
        }
        else 
        {
            Port_TL_Disable();
            if(linsignal.Bits.Drl_Ena==Light_ON)
            {
                Port_DrlPos_Enable();
                Interface_SetChannelCurrent((E_ChannelID)ChannelID2, gs_ChannelCtrlConfig[ChannelID2].CH_NormalCur*pwmper/100); //设置通道电流
                Interface_SetChannelSwitchState((E_ChannelID)ChannelID2, CHANNEL_STATE_ON); 
            }
            else if(linsignal.Bits.Pos_Ena==Light_ON)
            {
                Port_DrlPos_Enable();
                Interface_SetChannelCurrent((E_ChannelID)ChannelID2,gs_ChannelCtrlConfig[ChannelID2].CH_NormalCur*pwmper/100); //设置通道电流
                Interface_SetChannelSwitchState((E_ChannelID)ChannelID2, CHANNEL_STATE_ON); 
            }
            else 
            {
                Port_DrlPos_Disable();
                Interface_SetChannelCurrent((E_ChannelID)ChannelID2,0); 
                Interface_SetChannelSwitchState((E_ChannelID)ChannelID2, CHANNEL_STATE_OFF); 
                Interface_SetChannelCurrent((E_ChannelID)ChannelID2_Alt,0); 
                Interface_SetChannelSwitchState((E_ChannelID)ChannelID2_Alt, CHANNEL_STATE_OFF); 
            }
        }
    }
    else 
    {
        if(linsignal.Bits.Drl_Ena==Light_ON)
        {
            Port_DrlPos_Enable();
            Interface_SetChannelCurrent((E_ChannelID)ChannelID2, gs_ChannelCtrlConfig[ChannelID2].CH_NormalCur*pwmper/100); //设置通道电流
            Interface_SetChannelSwitchState((E_ChannelID)ChannelID2, CHANNEL_STATE_ON); 
        }
        else if(linsignal.Bits.Pos_Ena==Light_ON)
        {
            Port_DrlPos_Enable();
            Interface_SetChannelCurrent((E_ChannelID)ChannelID2,gs_ChannelCtrlConfig[ChannelID2].CH_NormalCur*pwmper/100); //设置通道电流
            Interface_SetChannelSwitchState((E_ChannelID)ChannelID2, CHANNEL_STATE_ON); 
        }
        else 
        {
            Port_DrlPos_Disable();
            Interface_SetChannelCurrent((E_ChannelID)ChannelID2,0); 
            Interface_SetChannelSwitchState((E_ChannelID)ChannelID2, CHANNEL_STATE_OFF); 
        }
    }
}


//非共用通道 CH3 CH4
void Non_SharedChannel(uint8 pwmper)
{
    E_ChannelID id=0;
    uint8 chmask=0;
//确定CH3 CH4接的灯
    for(id=ChannelID3;id<CHANNEL_NUM;id++)
    {
        chmask=GetChannelMaskByLightFunction(E_HighBeamSail);
        if(((chmask>>id)&0x01)!=0) //CH3/CH4接入远光
        {
            if(linsignal.Bits.HB_Ena==Light_ON)
            {
                Interface_SetChannelCurrent(id,gs_ChannelCtrlConfig[id].CH_NormalCur*pwmper/100); //设置通道电流
                Interface_SetChannelSwitchState(id, CHANNEL_STATE_ON); 
            }
            else
            {
                Interface_SetChannelCurrent(id, 0);
                Interface_SetChannelSwitchState(id, CHANNEL_STATE_OFF); 
            }
        }
        chmask=GetChannelMaskByLightFunction(E_DaytimeRunningLight);
        if(((chmask>>id)&0x01)!=0) //CH3/CH4接入日行
        {
            if(linsignal.Bits.Drl_Ena==Light_ON)
            {
                Interface_SetChannelCurrent(id,gs_ChannelCtrlConfig[id].CH_NormalCur*pwmper/100); //设置通道电流
                Interface_SetChannelSwitchState(id, CHANNEL_STATE_ON); 
            }
            else
            {
                Interface_SetChannelCurrent(id, 0); //设置通道电流
                Interface_SetChannelSwitchState(id, CHANNEL_STATE_OFF); 
            }
        }
        chmask=GetChannelMaskByLightFunction(E_PositionLight);
        if(((chmask>>id)&0x01)!=0) //CH3/CH4接入位置
        {
            if(linsignal.Bits.Pos_Ena==Light_ON)
            {
                Interface_SetChannelCurrent(id,gs_ChannelCtrlConfig[id].CH_NormalCur*pwmper/100); //设置通道电流
                Interface_SetChannelSwitchState(id, CHANNEL_STATE_ON); 
            }
            else
            {
                Interface_SetChannelCurrent(id, 0); 
                Interface_SetChannelSwitchState(id, CHANNEL_STATE_OFF); 
            }
        }
        chmask=GetChannelMaskByLightFunction(E_TurnIndicator);
        if(((chmask>>id)&0x01)!=0) //CH3/CH4接入转向
        {
            if(linsignal.Bits.Turn_Act==Light_ON)
            {
                Interface_SetChannelCurrent(id,gs_ChannelCtrlConfig[id].CH_NormalCur*pwmper/100); //设置通道电流
                Interface_SetChannelSwitchState(id, CHANNEL_STATE_ON); 
            }
            else
            {
                Interface_SetChannelCurrent(id, 0); 
                Interface_SetChannelSwitchState(id, CHANNEL_STATE_OFF); 
            }
        }
        chmask=GetChannelMaskByLightFunction(E_FrontCrossLamp);
        if(((chmask>>id)&0x01)!=0) //CH3/CH4接入贯穿灯
        {
            if(linsignal.Bits.CROS_Ena==Light_ON)
            {
                Interface_SetChannelCurrent(id,gs_ChannelCtrlConfig[id].CH_NormalCur*pwmper/100); //设置通道电流
                Interface_SetChannelSwitchState(id, CHANNEL_STATE_ON); 
            }
            else
            {
                Interface_SetChannelCurrent(id, 0); 
                Interface_SetChannelSwitchState(id, CHANNEL_STATE_OFF); 
            }
        }
    }
}
void DCMotor_MainFunction(uint8_t timebase);
void Lighting_BasicFun(void)
{
    uint8 pwmper=100;
//1.如有点灯信号，打开BOOST（不能一直打开，考虑热量）,不进入休眠
    
    linsignal=Interface_Get_LinSignal();
    if(linsignal.Light_Status!=0)
    {
        Boost_Enable();
        ResetAWakeTime();
        Port_FAN_Enable(); 
    }
    else 
    {
        Port_DC_Disable();
        Port_FAN_Disable();
        Boost_Disable();
    }
    Port_DC_Enable();
//2.降额处理，获取最新的占空比
    pwmper=Interface_GetDerateRatioOfOUV();  
    test[0]=pwmper;//测试
//3.1 点灯功能  远近光 共用通道CH1 CH1'
    LB_HB_RUN(pwmper);
//3.2 点灯功能  转向 日行 位置 共用通道 CH2 CH2'
    PosDrlTurn_Run(pwmper);
//3.3 点灯功能 非共用通道
    Non_SharedChannel(pwmper);
}

/*灯光管理功能*/
void Light_Manager(uint8 timebase)
{  
    Lighting_BasicFun(); //基础灯光执行点亮
}




