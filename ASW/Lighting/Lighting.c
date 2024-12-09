/**
 * @file Lighting.c
 * @author QinHaigang (qinhaigang@xyl.cn)
 * @brief 
 * @version 0.1
 * @date 2024-05-06
 * 
 * @copyright Copyright (c) 2024-  New Elec. Dept. XYL
 * 
 * @par History:
 * <table>
 * <tr><th>Data       <th>Version <th>Author     <th>Description
 * <tr><td>2024-05-06 <td>0.1     <td>QinHaigang <td>First
 * </table>
 */

/* Base inlude */
#include "HcmPlatform.h"
#include "GeneralFunction.h"
#include "Parameter_Interface.h"
#include "ComSignal_Interface.h"
#include "LRDirection_Interface.h"
/* Derate include */
#include "LossDerate_Interface.h"
#include "DerateRatioManager_Interface.h"
/* Lighting include */
#include "LampManager.h"
#include "HSDManager.h"
// #include "SMManager.h"
#include "Lighting.h"
/* #include "LBHB.h" */
#include "LB.h"
#include "HB.h"
#include "TurnIndicator.h"
#include "DRL.h"
#include "POS.h"
#include "DTC_Interface.h"
#include "LinManager.h"

//降额百分比
#include "OUVDerate_Interface.h"

#define Light_ON   1
#define Light_OFF   0

typedef struct _
{
    uint32_t        mo_magic;

    uint8_t         pr_FlgLR    :1; /* 0:L; 1:R */
    uint8_t         pr_FlgLR_ERR:1; /* L/R识别有故障 */
    uint8_t         pr_res_b8   :6;
    uint8_t         pr_res_B4[3];

    /* Channel mask */
    uint16_t        pr_ChMask_LB   ;
    uint16_t        pr_ChMask_HB   ;
    uint16_t        pr_ChMask_TI   ;
    uint16_t        pr_ChMask_DRL  ;
    uint16_t        pr_ChMask_POS  ;
    uint16_t        pr_ChMask_CROS ;

    /* 延时开参数 */
    uint16_t        pr_onDelay_LB   ;
    uint16_t        pr_onDelay_HB   ;
    uint16_t        pr_onDelay_TI   ;
    uint16_t        pr_onDelay_DRL  ;
    uint16_t        pr_onDelay_POS  ;
    uint16_t        pr_onDelay_CROS ;

    /* 延时关参数 */
    uint16_t        pr_offDelay_LB   ;
    uint16_t        pr_offDelay_HB   ;
    uint16_t        pr_offDelay_TI   ;
    uint16_t        pr_offDelay_DRL  ;
    uint16_t        pr_offDelay_POS  ;
    uint16_t        pr_offDelay_CORN ;
    uint16_t        pr_offDelay_CROS ;

    S_LgtActIns_t   in_Act0;    /* 当前命令输入 */
    S_LgtActIns_t   in_Act1;    /* 前次命令输入 */

    uint8_t         st_disSleep :1; /* 禁止休眠 */

    /* 记录命令状态的时间 */
    uint16_t        st_msActLB   ;
    uint16_t        st_msActHB   ;
    uint16_t        st_msActTI   ;
    uint16_t        st_msActDRL  ;
    uint16_t        st_msActPOS  ;
    uint16_t        st_msActCROS ;

    /*****************************************************/

    S_LgtFuncEna_t  st_LgtEna;      /* 灯光功能使能 */
    S_LgtActIns_t   st_LgtAct;      /* 灯光动作指令 */
    S_LgtStsFb_t    st_LgtSts;      /* 灯光状态反馈 */

    S_LgtFuncEna_t  st_LgtDer;      /* 灯光降额禁止状态 */
    uint16_t        st_maskDer0;    /* 被降额到0的通道掩码 */
    E_Derate_t      st_Der0For[MAX_CHANNLE_NUM]; /* Derate to 0 Source */

    S_LgtFuncEna_t  st_LgtOnDis;    /* 灯光当前开命令周期内 禁止状态 */

    /* Lighting Disable Source */
    U_DisSrc_t      st_LgtDS_LB      ;
    U_DisSrc_t      st_LgtDS_TI      ;
    U_DisSrc_t      st_LgtDS_POS     ;
    U_DisSrc_t      st_LgtDS_HB      ;
    U_DisSrc_t      st_LgtDS_DRL     ;
    U_DisSrc_t      st_LgtDS_CROS    ;
    U_DisSrc_t      st_LgtDS_WELC    ;

    U_DisSrc_t      st_LgtDS_POS_Dyn ;
    U_DisSrc_t      st_LgtDS_CROS_Dyn;

    S_AHBCObj_t ahbcobj;

    /* Power loss 1 */
    uint8_t     st_PWRloss;
    /* BUSOFF */
    uint8_t     st_busoff;
    /* QF */
    uint8_t     st_QF_VSpd;

    /* Pincode Check */
    uint8_t     pr_PCC_cfg      :1; /* 配置标志 */
    uint8_t     st_PCC_err      :1; /* 错误标志 */
    uint8_t     st_PCC_err0     :1; /* 上次的错误标志 */
    uint8_t     st_PCC_on1      :1;
    uint8_t     st_PCC_Reserved :4;

    uint16_t    st_PCC_ms;

}S_LightingCtl_t;

S_LightingCtl_t lgtctl;


/***************************** Local Fucntions ********************************/

/**
 * @brief 
 */
static void _inou_init(void)
{

}

static void _input(uint16_t ms)
{
    uint16 top = 0xFFFF - ms;
    uint32 u32v=0;
    if (lgtctl.st_msActLB   <= top) { lgtctl.st_msActLB   += ms; }
    if (lgtctl.st_msActHB   <= top) { lgtctl.st_msActHB   += ms; }
    if (lgtctl.st_msActTI   <= top) { lgtctl.st_msActTI   += ms; }
    if (lgtctl.st_msActDRL  <= top) { lgtctl.st_msActDRL  += ms; }
    if (lgtctl.st_msActPOS  <= top) { lgtctl.st_msActPOS  += ms; }
    if (lgtctl.st_msActCROS <= top) { lgtctl.st_msActCROS += ms; }
    
    /* 有点灯要求，阻止休眠 */
    if ((lgtctl.st_LgtAct.ActLB       != 0) ||
        (lgtctl.st_LgtAct.ActTIsts    != 0) ||
        (lgtctl.st_LgtAct.ActPOS      != 0) ||
        (lgtctl.st_LgtAct.ActHB       != 0) ||
        (lgtctl.st_LgtAct.ActDRL      != 0) ||
        (lgtctl.st_LgtAct.ActCORN     != 0) ||
        (lgtctl.st_LgtAct.ActCROS     != 0) ||
        (lgtctl.st_LgtAct.ActWELC     != 0) ||
        (lgtctl.st_LgtAct.ActPOS_Dyn  != 0) ||
        (lgtctl.st_LgtAct.ActCROS_Dyn != 0))
    {
        // Interface_SetKeepAwakeFlag();
        lgtctl.st_disSleep = 1;
    }
    else
    {
        // Interface_ClearKeepAwakeFlag();
        lgtctl.st_disSleep = 0;
    }


}
static void _output(uint16_t ms)
{


}

static void Derate0_forwhat(uint16_t der0mask, uint16_t lgtmask, U_DisSrc_t *ds)
{
    uint16_t mask;
    E_Derate_t der;
    int i;

    mask = der0mask & lgtmask;
    if (mask != 0)
    {
        ds->bits.ot_chn = ds->bits.ot_led = ds->bits.ot_amb = ds->bits.sp_ouv = ds->bits.sp_los = 0;

        for (i=0; i<MAX_CHANNLE_NUM; i++)
        { if ((mask & (0x0001<<i)) != 0)
        {
            der = Interface_GetChannelDerateFor((E_ChannelID)i);
            if (der == DERA_ECU) { ds->bits.ot_chn = 1; }
            if (der == DERA_LED) { ds->bits.ot_led = 1; }
            if (der == DERA_AMB) { ds->bits.ot_amb = 1; }
            if (der == DERA_OUV) { ds->bits.sp_ouv = 1; }
            if (der == DERA_LOS) { ds->bits.sp_los = 1; }
            break;
        }
        }
    }
}

static void Derate_handle(uint16_t ms)
{
    int i;
    S_DerateLight_t dl;
    uint16_t mask;

    /* 1路丢失判断的功能状态 */
    dl.bit.D00_LB   = (lgtctl.st_LgtAct.ActLB)    ? 1 : 0;
    dl.bit.D01_TI   = (lgtctl.st_LgtAct.ActTIsts) ? 1 : 0;
    dl.bit.D02_POS  = (lgtctl.st_LgtAct.ActPOS)   ? 1 : 0;
    dl.bit.D04_HB   = (lgtctl.st_LgtAct.ActHB)    ? 1 : 0;
    dl.bit.D05_DRL  = (lgtctl.st_LgtAct.ActDRL)   ? 1 : 0;
    dl.bit.D06_CORN = (lgtctl.st_LgtAct.ActCORN)  ? 1 : 0;
    dl.bit.D08_CROS = (lgtctl.st_LgtAct.ActCROS)  ? 1 : 0;
    dl.bit.D11_WELC = (lgtctl.st_LgtAct.ActWELC)  ? 1 : 0;
    /* 1路丢失时按功能优先级降额 */
    LossDerateMainFunction(ms, dl);

    /* 综合处理降额 */
    DerateRatioManagerFuncmain(ms);


    /* 查看是否有通道降额到0，导致灯光完全关闭 */
    lgtctl.st_maskDer0 = 0;
    for (i=0; i<MAX_CHANNLE_NUM; i++)
    {
        if (Interface_GetChannelDerateRatio((E_ChannelID)i) == 0)
        { lgtctl.st_maskDer0 |= (0x0001<<i); }
    }

    /* 获取降额反馈 */
    for (i=0; i<NUM_DER_LGT; i++)
    {
        mask = Interface_GetDerateLightChannelMask((E_DerateLight_t)i);
        switch(i)
        {
        case D00_LB:   lgtctl.st_LgtDer.EnaLB   = (mask & lgtctl.st_maskDer0) ? 0 : 1; break;
        case D01_TI:   lgtctl.st_LgtDer.EnaTI   = (mask & lgtctl.st_maskDer0) ? 0 : 1; break;
        case D02_POS:  lgtctl.st_LgtDer.EnaPOS  = (mask & lgtctl.st_maskDer0) ? 0 : 1; break;
        case D04_HB:   lgtctl.st_LgtDer.EnaHB   = (mask & lgtctl.st_maskDer0) ? 0 : 1; break;
        case D05_DRL:  lgtctl.st_LgtDer.EnaDRL  = (mask & lgtctl.st_maskDer0) ? 0 : 1; break;
        case D08_CROS: lgtctl.st_LgtDer.EnaCROS = (mask & lgtctl.st_maskDer0) ? 0 : 1; break;
        case D11_WELC: lgtctl.st_LgtDer.EnaWELC = (mask & lgtctl.st_maskDer0) ? 0 : 1; break;
        default:;
        }
    }

    /* Derate to 0 for what */
    Derate0_forwhat(lgtctl.st_maskDer0, lgtctl.pr_ChMask_LB  , &(lgtctl.st_LgtDS_LB  ));
    Derate0_forwhat(lgtctl.st_maskDer0, lgtctl.pr_ChMask_TI  , &(lgtctl.st_LgtDS_TI  ));
    Derate0_forwhat(lgtctl.st_maskDer0, lgtctl.pr_ChMask_POS , &(lgtctl.st_LgtDS_POS ));
    Derate0_forwhat(lgtctl.st_maskDer0, lgtctl.pr_ChMask_HB  , &(lgtctl.st_LgtDS_HB  ));
    Derate0_forwhat(lgtctl.st_maskDer0, lgtctl.pr_ChMask_DRL , &(lgtctl.st_LgtDS_DRL ));
    Derate0_forwhat(lgtctl.st_maskDer0, lgtctl.pr_ChMask_CROS, &(lgtctl.st_LgtDS_CROS));

}

/* 综合使能处理 */
static void Enable_handle(void)
{
    /* 降额关后，需要下个命令周期开 */
    /* if (lgtctl.st_LgtDer.EnaLB   == ENA_OFF) { lgtctl.st_LgtOnDis.EnaLB   = ENA_OFF; }
    if (lgtctl.st_LgtDer.EnaTI   == ENA_OFF) { lgtctl.st_LgtOnDis.EnaTI   = ENA_OFF; }
    if (lgtctl.st_LgtDer.EnaPOS  == ENA_OFF) { lgtctl.st_LgtOnDis.EnaPOS  = ENA_OFF; }
    if (lgtctl.st_LgtDer.EnaSML  == ENA_OFF) { lgtctl.st_LgtOnDis.EnaSML  = ENA_OFF; }
    if (lgtctl.st_LgtDer.EnaHB   == ENA_OFF) { lgtctl.st_LgtOnDis.EnaHB   = ENA_OFF; }
    if (lgtctl.st_LgtDer.EnaDRL  == ENA_OFF) { lgtctl.st_LgtOnDis.EnaDRL  = ENA_OFF; }
    if (lgtctl.st_LgtDer.EnaCORN == ENA_OFF) { lgtctl.st_LgtOnDis.EnaCORN = ENA_OFF; }
    if (lgtctl.st_LgtDer.EnaFOG  == ENA_OFF) { lgtctl.st_LgtOnDis.EnaFOG  = ENA_OFF; }
    if (lgtctl.st_LgtDer.EnaCROS == ENA_OFF) { lgtctl.st_LgtOnDis.EnaCROS = ENA_OFF; }
    if (lgtctl.st_LgtDer.EnaGRIL == ENA_OFF) { lgtctl.st_LgtOnDis.EnaGRIL = ENA_OFF; }
    if (lgtctl.st_LgtDer.EnaLOGO == ENA_OFF) { lgtctl.st_LgtOnDis.EnaLOGO = ENA_OFF; }
    if (lgtctl.st_LgtDer.EnaWELC == ENA_OFF) { lgtctl.st_LgtOnDis.EnaWELC = ENA_OFF; } */

    /* 综合处理 */
    lgtctl.st_LgtEna.EnaLB   = (lgtctl.st_LgtDer.EnaLB   && lgtctl.st_LgtOnDis.EnaLB  ) ? 1 : 0;
    lgtctl.st_LgtEna.EnaTI   = (lgtctl.st_LgtDer.EnaTI   && lgtctl.st_LgtOnDis.EnaTI  ) ? 1 : 0;
    lgtctl.st_LgtEna.EnaPOS  = (lgtctl.st_LgtDer.EnaPOS  && lgtctl.st_LgtOnDis.EnaPOS ) ? 1 : 0;
    lgtctl.st_LgtEna.EnaHB   = (lgtctl.st_LgtDer.EnaHB   && lgtctl.st_LgtOnDis.EnaHB  ) ? 1 : 0;
    lgtctl.st_LgtEna.EnaDRL  = (lgtctl.st_LgtDer.EnaDRL  && lgtctl.st_LgtOnDis.EnaDRL ) ? 1 : 0;
    lgtctl.st_LgtEna.EnaCROS = (lgtctl.st_LgtDer.EnaCROS && lgtctl.st_LgtOnDis.EnaCROS) ? 1 : 0;
    lgtctl.st_LgtEna.EnaWELC = (lgtctl.st_LgtDer.EnaWELC && lgtctl.st_LgtOnDis.EnaWELC) ? 1 : 0;

    lgtctl.st_LgtEna.EnaPOS_Dyn  = 1;
    lgtctl.st_LgtEna.EnaCROS_Dyn = 1;

    /* N-1 mode Derate0 */
    lgtctl.st_LgtDS_LB  .bits.mo_N_1 = lgtctl.st_LgtOnDis.EnaLB   ? 0 : 1;
    lgtctl.st_LgtDS_TI  .bits.mo_N_1 = lgtctl.st_LgtOnDis.EnaTI   ? 0 : 1;
    lgtctl.st_LgtDS_POS .bits.mo_N_1 = lgtctl.st_LgtOnDis.EnaPOS  ? 0 : 1;
    lgtctl.st_LgtDS_HB  .bits.mo_N_1 = lgtctl.st_LgtOnDis.EnaHB   ? 0 : 1;
    lgtctl.st_LgtDS_DRL .bits.mo_N_1 = lgtctl.st_LgtOnDis.EnaDRL  ? 0 : 1;
    lgtctl.st_LgtDS_CROS.bits.mo_N_1 = lgtctl.st_LgtOnDis.EnaCROS ? 0 : 1;
    lgtctl.st_LgtDS_WELC.bits.mo_N_1 = lgtctl.st_LgtOnDis.EnaWELC ? 0 : 1;
}


/******************************** Interface ASW *******************************/

void Lighting_Init(void)
{
    /* Control Block Clear to 0 */
    C_Memset_B((uint8_t*)(&lgtctl), 0, sizeof(S_LightingCtl_t));

    /*  */
    _inou_init();

    /*  */
    HsdM_Init();
    /* Lighting Initialize */
    LampM_Init();       /* Lamp Manager */

    /* LBHB_Init(); */        /* Low Beam & High Beam */
    LB_Init();
    HB_Init();
    DRL_Init();
    POS_Init();
    TI_Init();          /* Turn Indicator */
    /*  GRIL_Init(); */        /* Grille Lamp     Demo */


}

/**
 * @brief 
 * 
 * @return int 
 */
void Lighting_Exit(void)
{
    /* LBHB_Exit(); */        /* Low Beam & High Beam */
    LB_Exit();
    HB_Exit();
    DRL_Exit();
    POS_Exit();
    TI_Exit();          /* Turn Indicator */
    /* GRIL_Exit(); */        /* Grille Lamp     Demo */
    LampM_Exit();       /* Lamp Manager */

    HsdM_Exit();
    // SMotorM_Exit();
}

/**
 * @brief Lighting Run cycle 10ms
 * 
 * @return 0:Ok; not 0:some Error
 */
void Lighting_Run10ms(void)
{
    uint16_t ms = 10;   /* 10ms */
    
    /* Input Net Signals */
    _input(ms);

    /* Derate handle */
    Derate_handle(ms);  

    /* 使能综合处理 */
    Enable_handle();    /**/

    LB_Run_(ms);
   
    HB_Run_(ms);
    POS_Run_(ms);
    DRL_Run_(ms);
    
    LB_Run_On();
    HB_Run_On();

    POS_Run_On();
    DRL_Run_On();

    TI_Run(ms);         /* Turn Indicator */

    LampM_Run(ms);      /* Lamp Manager */

    _output(ms);
}

/***************************** Interface Lighting *****************************/

/**
 * @brief Get L/R flag
 * 
 * @return L/R flag 
 */
E_FlgLR_t Get_FlgLR(void)
{
    return lgtctl.pr_FlgLR;
}

/**
 * @brief Get S_LgtFuncEna_t object
 * 
 * @param ena, point to S_LgtFuncEna_t object
 * @return int, 0:Ok; not 0:same Error
 */
int GetLgtFuncEna(S_LgtFuncEna_t *ena)
{
    if (ena == 0) { return -1; }
    C_Memcpy_B((uint8_t*)ena, (uint8_t*)(&(lgtctl.st_LgtEna)), sizeof(S_LgtFuncEna_t));
    return 0;
}

void GetLgtFuncDisSrc_LB       (U_DisSrc_t *ds) { if(ds != 0) {ds->val = lgtctl.st_LgtDS_LB.val      ;} }
void GetLgtFuncDisSrc_TI       (U_DisSrc_t *ds) { if(ds != 0) {ds->val = lgtctl.st_LgtDS_TI.val      ;} }
void GetLgtFuncDisSrc_POS      (U_DisSrc_t *ds) { if(ds != 0) {ds->val = lgtctl.st_LgtDS_POS.val     ;} }
void GetLgtFuncDisSrc_HB       (U_DisSrc_t *ds) { if(ds != 0) {ds->val = lgtctl.st_LgtDS_HB.val      ;} }
void GetLgtFuncDisSrc_DRL      (U_DisSrc_t *ds) { if(ds != 0) {ds->val = lgtctl.st_LgtDS_DRL.val     ;} }
void GetLgtFuncDisSrc_CROS     (U_DisSrc_t *ds) { if(ds != 0) {ds->val = lgtctl.st_LgtDS_CROS.val    ;} }
void GetLgtFuncDisSrc_WELC     (U_DisSrc_t *ds) { if(ds != 0) {ds->val = lgtctl.st_LgtDS_WELC.val    ;} }
void GetLgtFuncDisSrc_POS_Dyn  (U_DisSrc_t *ds) { if(ds != 0) {ds->val = lgtctl.st_LgtDS_POS_Dyn.val ;} }
void GetLgtFuncDisSrc_CROS_Dyn (U_DisSrc_t *ds) { if(ds != 0) {ds->val = lgtctl.st_LgtDS_CROS_Dyn.val;} }


/**
 * @brief Get S_LgtActIns_t object
 * 
 * @param ena, point to S_LgtFuncEna_t object
 * @return int, 0:Ok; not 0:same Error
 */
int GetLgtActIns(S_LgtActIns_t *act)
{
    if (act == 0) { return -1; }
    C_Memcpy_B((uint8_t*)act, (uint8_t*)(&(lgtctl.st_LgtAct)), sizeof(S_LgtActIns_t));
    return 0;
}

/**
 * @brief Get S_LgtStsFb_t data
 * 
 * @param sts: pointer to S_LgtStsFb_t data for Get
 * @return 0:OK; not 0:Error
 */
int GetLgtStsFb(S_LgtStsFb_t *sts)
{
    if (sts == 0) { return -1; }
    C_Memcpy_B((uint8_t*)sts, (uint8_t*)(&(lgtctl.st_LgtSts)), sizeof(S_LgtStsFb_t));
    return 0;
}

void SetLgtStsFb_LB  (E_LgtSts_t sts){ lgtctl.st_LgtSts.StsLB   = sts; }
void SetLgtStsFb_TI  (E_LgtSts_t sts){ lgtctl.st_LgtSts.StsTI   = sts; }
void SetLgtStsFb_POS (E_LgtSts_t sts){ lgtctl.st_LgtSts.StsPOS  = sts; }
void SetLgtStsFb_HB  (E_LgtSts_t sts){ lgtctl.st_LgtSts.StsHB   = sts; }
void SetLgtStsFb_DRL (E_LgtSts_t sts){ lgtctl.st_LgtSts.StsDRL  = sts; }
void SetLgtStsFb_CORN(E_LgtSts_t sts){ lgtctl.st_LgtSts.StsCORN = sts; }
void SetLgtStsFb_CROS(E_LgtSts_t sts){ lgtctl.st_LgtSts.StsCROS = sts; }
void SetLgtStsFb_WELC(E_LgtSts_t sts){ lgtctl.st_LgtSts.StsWELC = sts; }

/* 在当前开命令周期内 设置禁止 */
void SetLgtOnDis_LB  () { lgtctl.st_LgtOnDis.EnaLB   = ENA_OFF; }
void SetLgtOnDis_TI  () { lgtctl.st_LgtOnDis.EnaTI   = ENA_OFF; }
void SetLgtOnDis_POS () { lgtctl.st_LgtOnDis.EnaPOS  = ENA_OFF; }
void SetLgtOnDis_HB  () { lgtctl.st_LgtOnDis.EnaHB   = ENA_OFF; }
void SetLgtOnDis_DRL () { lgtctl.st_LgtOnDis.EnaDRL  = ENA_OFF; }
void SetLgtOnDis_CROS() { lgtctl.st_LgtOnDis.EnaCROS = ENA_OFF; }
void SetLgtOnDis_WELC() { lgtctl.st_LgtOnDis.EnaWELC = ENA_OFF; }




//测试代码
#include "Pwm_Cfg.h"
#include "Dio.h"
#include "Pwm.h"

typedef struct
{
    uint32_t    EnaLB       :1;     /* Low Beam */
    uint32_t    EnaTI       :1;     /* Trun Indicator */
    uint32_t    EnaPOS      :1;     /* POSition light */
    uint32_t    EnaHB       :1;     /* Hight Beam */
    uint32_t    EnaDRL      :1;     /* Day Running Light */
    uint32_t    EnaCROS     :1;     /* front CROSS lamp */
    uint32_t    EnaWELC     :1;     /* WELCome/goodbye light */

    uint32_t    EnaPOS_Dyn  :1;     /* POSition light   Dynamic */
    uint32_t    EnaCROS_Dyn :1;     /* front CROSS lamp Dynamic */

    uint32_t    res         :13;
}S_LgtFuncEna_t0;
S_LgtFuncEna_t0 LightEna;
Std_ReturnType BD18397SetHwCHCtrl(uint8 id, uint8 hw_ch, uint8 isON);

void LowBeam_RunOn(uint8 pwm)
{
    BD18397SetHwCHCtrl(0, 0, 1);   //CH1  近光(远光)
}
void LowBeam_RunOff(void)
{
    BD18397SetHwCHCtrl(0, 0, 0);   //CH1  近光(远光)
}
void HighBeam_RunOn(uint8 pwm)
{
    Pwm_SetPeriodAndDuty(PwmConf_PwmChannel_H_L_Ctrl,5000,0);//0x8000=100%=关闭远光；开5000 频率400HZ 占空比0
    BD18397SetHwCHCtrl(0, 0, 1);   //CH1  近光、远光
}
void HighBeam_RunOff(void)
{
    Pwm_SetPeriodAndDuty(PwmConf_PwmChannel_H_L_Ctrl,5000,0x8000);//0x8000=100%=关闭远光；开5000 频率400HZ 占空比0
}
void Front_Cross_Lamp_RunOn(uint8 pwm)
{
    BD18397SetHwCHCtrl(0, 1, 1);   //CH4  贯穿灯
}
void Front_Cross_Lamp_RunOff(void)
{
    BD18397SetHwCHCtrl(0, 1, 0);   //CH4  贯穿灯
}
void PosDrl_RunOn(uint8 pwm)
{
    static uint8 cnt=0;
    if(cnt==0)//硬件上做一个延时
    {
        cnt=1;
        Dio_WriteChannel(DioConf_DioChannel_TL_Ctrl, STD_LOW); //关闭TL
    }
    else
    {
        cnt=0;
        Dio_WriteChannel(DioConf_DioChannel_DRL_Ctrl, STD_HIGH); //打开DRL
        BD18397SetHwCHCtrl(1, 0, 1);    //CH2 位置灯1 转向灯  共用发光面
        BD18397SetHwCHCtrl(1, 1, 1);    //CH3  位置灯2
    }
}

void PosDrl_RunOff(void)
{
    Dio_WriteChannel(DioConf_DioChannel_DRL_Ctrl, STD_LOW);//关闭DRL
    BD18397SetHwCHCtrl(1, 1, 0);    //CH3  位置灯2 
}

void Turn_RunOn(uint8 pwm)
{
    static uint8 cnt=0;
    if(cnt==0)//硬件上做一个延时
    {
        cnt=1;
        Dio_WriteChannel(DioConf_DioChannel_DRL_Ctrl, STD_LOW); //关闭DRL
    }
    else
    {
        cnt=0;
        Dio_WriteChannel(DioConf_DioChannel_TL_Ctrl, STD_HIGH); //打开TL
        BD18397SetHwCHCtrl(1, 1, 0);    //CH3  位置灯2
        BD18397SetHwCHCtrl(1, 0, 1);    //CH2 位置灯1 转向灯  共用发光面
    }
}

void Turn_RunOff(void)
{
    Dio_WriteChannel(DioConf_DioChannel_TL_Ctrl, STD_LOW); //打开TL
    // BD18397SetHwCHCtrl(1, 0, 0);    //CH2 位置灯1 转向灯  共用发光面
}
//关闭POS DRL TURN
void PosDrlTurn_Alloff(void)
{
    Dio_WriteChannel(DioConf_DioChannel_DRL_Ctrl, STD_LOW);//关闭DRL
    Dio_WriteChannel(DioConf_DioChannel_TL_Ctrl, STD_LOW); //打开TL
    BD18397SetHwCHCtrl(1, 0, 0);    //CH2 位置灯1 转向灯  共用发光面
    BD18397SetHwCHCtrl(1, 1, 0);    //CH3  位置灯2 
}

/*基础点灯功能*/
uint8 data000=0;
void Lighting_BasicFun(void)
{
    GS_LIN_LCONTROL BLStatus;
    uint8 pwmper=100;
    BLStatus.Light_Status=Get_BaseLight_Signal(); //获取基础灯光状态
    data000=BLStatus.Light_Status;
    data000=BLStatus.Bits.LB_Ena;
    pwmper=Interface_GetDerateRatioOfOUV();      //获取点灯占空比
    //获取占空比
    if(BLStatus.Bits.CROS_Ena==Light_ON)//贯穿灯开
    {
        Front_Cross_Lamp_RunOn(pwmper);
    }
    else 
    {
        Front_Cross_Lamp_RunOff();
    }

    if(BLStatus.Bits.HB_Ena==Light_ON)//远光开
    {
        LowBeam_RunOn(pwmper);
        HighBeam_RunOn(pwmper);
    }
    else //远光关
    {
        HighBeam_RunOff();
    }

    if(BLStatus.Bits.LB_Ena==Light_ON)//近光 开
    {
        LowBeam_RunOn(pwmper);
    }
    else if((BLStatus.Bits.LB_Ena==Light_OFF)&&(BLStatus.Bits.HB_Ena==Light_OFF))//近光关
    {
        LowBeam_RunOff();
    } 
   
    if((BLStatus.Bits.Pos_Ena==Light_OFF)&&(BLStatus.Bits.Drl_Ena==Light_OFF)&&(BLStatus.Bits.Turn_Ena==Light_OFF))
    {
       PosDrlTurn_Alloff();//含共发光面
    }
    else
    {
        if(BLStatus.Bits.Turn_Ena==Light_ON)//转向
        {
            Turn_RunOn(100);
        }
        else//转向 打开关闭
        {
            Turn_RunOff();
        }
        if(((BLStatus.Bits.Pos_Ena==Light_ON)||(BLStatus.Bits.Drl_Ena==Light_ON))&&(BLStatus.Bits.Turn_Ena==Light_OFF))//位置 开
        {
           PosDrl_RunOn(100);
        } 
        else //位置
        {
            PosDrl_RunOff();
        } 
    }
}

/*灯光管理功能*/
void Light_Manager(uint8 timebase)
{  
    Lighting_BasicFun(); //基础灯光
}


void HS11MainFuncion(uint8 *CanReceiveData)
{
    uint16_t channelMask;
    uint8 function = 0;

    channelMask = (((uint16_t)CanReceiveData[1]) << 8) + ((uint16_t)CanReceiveData[0]);

    for (function = 0; function <= 4; function++)
    {
        switch (function)
        {
            /*LB*/
        case 0:
            // if (CanReceiveData[0] != 0)
            // {
            //     Interface_SetChannelPWM(ChannelID1, 100);
            //     Interface_SetChannelCurrent(ChannelID1, FunOpenCurrent[function]);
            //     Interface_SetChannelSwitchState(ChannelID1, CHANNEL_STATE_ON);
            // }
            // else
            // {
            //     Interface_SetChannelSwitchState(ChannelID1, CHANNEL_STATE_OFF);
            // }
            // break;
        case 1:
        case 3:
        case 4:
        
            break;
        }
    }
}






















