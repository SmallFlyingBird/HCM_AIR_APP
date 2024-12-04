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
typedef struct _E2Ems_
{
    uint16_t cnt;
    uint16_t crc;
    uint16_t ovr;
}S_E2Ems_t;

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
    /* 功能安全标志 */
    uint8_t     st_FS_ActLBsgl;     /* 0:正常；1:活动模式安全；2:非活动模式安全 */
    uint8_t     st_FS_ActTIsgl;     /* 0:正常；1:功能安全 */

    uint8_t     st_FS_TIcond1   :1; /* CRC/Counter 进入功能安全判断(smart方式使用的中间状态) */
    uint8_t     st_FS_TIcond2   :1; /* Timeout     进入功能安全判断(smart方式使用的中间状态) */

    uint16_t    st_FS_LBsgl_ms;

    S_E2Ems_t   st_E2Ems_UM;
    S_E2Ems_t   st_E2Ems_VSpd;
    S_E2Ems_t   st_E2Ems_LB;
    S_E2Ems_t   st_E2Ems_TI;

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
    uint32_t u32v;
    // S_LF_Info_T lgtinfo;

    /* L/R识别 */
    lgtctl.pr_FlgLR = (HCM_LEFT_SIDE) ? LR_LE : LR_RI;
    lgtctl.pr_FlgLR_ERR = 0;

    /* L/R 不匹配识别 */
#if (QINGHAIGANG) && (LGT_DIS_LRE == 0)
    if (lgtctl.pr_FlgLR == LR_LE)
    {
        if ((DIRECTION_LEFT  != Interface_GetBootLRDection()) ||
            (DIRECTION_LEFT  != Interface_GetAppLRDection()))
        { lgtctl.pr_FlgLR_ERR = 1; };
    }
    else
    {
        if ((DIRECTION_RIGHT != Interface_GetBootLRDection()) ||
            (DIRECTION_RIGHT != Interface_GetAppLRDection()))
        { lgtctl.pr_FlgLR_ERR = 1; };
    }
#endif  /* (QINGHAIGANG) && (LGT_DIS_LRE == 0) */


    // /* LB    */get_si_ActnLB   (&u32v); lgtctl.in_Act0.ActLB    = lgtctl.in_Act1.ActLB    = u32v;
    // /* HB    */get_si_ActnHB   (&u32v); lgtctl.in_Act0.ActHB    = lgtctl.in_Act1.ActHB    = u32v;
    // /* TIsts */get_si_ActnTIsts(&u32v); lgtctl.in_Act0.ActTIsts = lgtctl.in_Act1.ActTIsts = u32v;
    // /* TIact */get_si_ActnTIact(&u32v); lgtctl.in_Act0.ActTIact = lgtctl.in_Act1.ActTIact = u32v;
    // /* DRL   */get_si_ActnDRL  (&u32v); lgtctl.in_Act0.ActDRL   = lgtctl.in_Act1.ActDRL   = u32v;
    // /* POS   */get_si_ActnPOS  (&u32v); lgtctl.in_Act0.ActPOS   = lgtctl.in_Act1.ActPOS   = u32v;
    // /* CROS  */get_si_ActnCROS (&u32v); lgtctl.in_Act0.ActCROS  = lgtctl.in_Act1.ActCROS  = u32v;
    // /* CORN  */get_si_ActnCOR  (&u32v); lgtctl.in_Act0.ActCORN  = lgtctl.in_Act1.ActCORN  = u32v;

    /* 灯光当前开命令周期内 禁止标识，      以下全部设置成灯光功能使能 */
    lgtctl.st_LgtOnDis.EnaLB   = ENA_ON;
    lgtctl.st_LgtOnDis.EnaTI   = ENA_ON;
    lgtctl.st_LgtOnDis.EnaPOS  = ENA_ON;
    lgtctl.st_LgtOnDis.EnaHB   = ENA_ON;
    lgtctl.st_LgtOnDis.EnaDRL  = ENA_ON;
    lgtctl.st_LgtOnDis.EnaCROS = ENA_ON;
    lgtctl.st_LgtOnDis.EnaWELC = ENA_ON; 

    /* QF */
    lgtctl.st_busoff = 0;
    lgtctl.st_QF_VSpd = 0;
    /* E2E */

}

/* 修正转向信号 */
/* L/R Error   : 3 -> 1 */
/* L/R no Error: LEFT: 1 or 3 -> 1;  RIGHT: 2 or 3 -> 1 */
static uint32_t valLR_TI(uint32_t v)
{
    if (lgtctl.pr_FlgLR_ERR)    /* CTS-6.6.2 */
    {
        if (v == 3) { return 1; }
        else        { return 0; }
    }
    else
    {
        if (lgtctl.pr_FlgLR == LR_LE)
        { if ((v == 1) || (v == 3)) { return 1; } else { return 0; } }
        else
        { if ((v == 2) || (v == 3)) { return 1; } else { return 0; } }
    }
}

static void FS_confirm(uint16_t ms)
{
//     uint8_t  u8v;
//     uint16_t u16v;
//     uint32_t u32v;
//     S_E2EStateForFailSafe e2e;

//     /* Power loss 1 */
//     lgtctl.st_PWRloss = (Interface_IsLoss() == 0) ? 0 : 1;
//     /* BUSOFF */
//     lgtctl.st_busoff = Interface_GetBusOffFlag();
//     // /* QF状态 */
//     // Interface_GetSignal_VehSpdLgtQf(&u32v);
//     // lgtctl.st_QF_VSpd = u32v;
//     /* E2E状态 */
//     lgtctl.st_e2e = e2e = GetE2EFlagForFailSafe();

//     /*  */
//     /* VehObjforADB */


//     /* 信号故障计时 */
//     /* 模式信号 */
//     if (e2e.E2EErrorFlagForFailSafe.bits.UsgModeTimeout == 1) { lgtctl.st_E2Ems_UM.ovr = C_AddToMax_U16(lgtctl.st_E2Ems_UM.ovr, ms); } else { lgtctl.st_E2Ems_UM.ovr = 0;   }
//     if (e2e.E2EErrorFlagForFailSafe.bits.UsgModeCntErr  == 1) { lgtctl.st_E2Ems_UM.cnt = C_AddToMax_U16(lgtctl.st_E2Ems_UM.cnt, ms); } else { lgtctl.st_E2Ems_UM.cnt = 0;   }
//     if (e2e.E2EErrorFlagForFailSafe.bits.UsgModeCrcErr  == 1) { lgtctl.st_E2Ems_UM.crc = C_AddToMax_U16(lgtctl.st_E2Ems_UM.crc, ms); } else { lgtctl.st_E2Ems_UM.crc = 0;   }
//     // /* 车速信号 */
//     // if (e2e.E2EErrorFlagForFailSafe.bits.VehSpdTimeout == 1) { lgtctl.st_E2Ems_VSpd.ovr = C_AddToMax_U16(lgtctl.st_E2Ems_VSpd.ovr, ms); } else { lgtctl.st_E2Ems_VSpd.ovr = 0;   }
//     // if (e2e.E2EErrorFlagForFailSafe.bits.VehSpdCntErr  == 1) { lgtctl.st_E2Ems_VSpd.cnt = C_AddToMax_U16(lgtctl.st_E2Ems_VSpd.cnt, ms); } else { lgtctl.st_E2Ems_VSpd.cnt = 0;   }
//     // if (e2e.E2EErrorFlagForFailSafe.bits.VehSpdCrcErr  == 1) { lgtctl.st_E2Ems_VSpd.crc = C_AddToMax_U16(lgtctl.st_E2Ems_VSpd.crc, ms); } else { lgtctl.st_E2Ems_VSpd.crc = 0;   }
//     // /* LB信号 */
//     if (e2e.E2EErrorFlagForFailSafe.bits.ActnOfLedLoBeamTimeout == 1) { lgtctl.st_E2Ems_LB.ovr = C_AddToMax_U16(lgtctl.st_E2Ems_LB.ovr, ms); } else { lgtctl.st_E2Ems_LB.ovr = 0;   }
//     if (e2e.E2EErrorFlagForFailSafe.bits.ActnOfLedLoBeamCntErr  == 1) { lgtctl.st_E2Ems_LB.cnt = C_AddToMax_U16(lgtctl.st_E2Ems_LB.cnt, ms); } else { lgtctl.st_E2Ems_LB.cnt = 0;   }
//     if (e2e.E2EErrorFlagForFailSafe.bits.ActnOfLedLoBeamCrcErr  == 1) { lgtctl.st_E2Ems_LB.crc = C_AddToMax_U16(lgtctl.st_E2Ems_LB.crc, ms); } else { lgtctl.st_E2Ems_LB.crc = 0;   }
//     /* TI信号 */
//     if (e2e.E2EErrorFlagForFailSafe.bits.ActvnOfIndcrTimeout == 1) { lgtctl.st_E2Ems_TI.ovr = C_AddToMax_U16(lgtctl.st_E2Ems_TI.ovr, ms); } else { lgtctl.st_E2Ems_TI.ovr = 0;   }
//     if (e2e.E2EErrorFlagForFailSafe.bits.ActvnOfIndcrCntErr  == 1) { lgtctl.st_E2Ems_TI.cnt = C_AddToMax_U16(lgtctl.st_E2Ems_TI.cnt, ms); } else { lgtctl.st_E2Ems_TI.cnt = 0;   }
//     if (e2e.E2EErrorFlagForFailSafe.bits.ActvnOfIndcrCrcErr  == 1) { lgtctl.st_E2Ems_TI.crc = C_AddToMax_U16(lgtctl.st_E2Ems_TI.crc, ms); } else { lgtctl.st_E2Ems_TI.crc = 0;   }

//     /* lgtctl.st_FS_ActLBsgl RESET */
//     if ((lgtctl.st_E2Ems_LB.ovr == 0) &&
//         (lgtctl.st_E2Ems_LB.cnt == 0) &&
//         (lgtctl.st_E2Ems_LB.crc == 0) &&
//         (lgtctl.st_busoff == 0))
//     { lgtctl.st_FS_ActLBsgl = 0; }

//     /* TI FS */
// #if (OEM_PLATFORM == OEM_GEELY)
//     /* geely */
//     if (1)
//     {
//         /*  lgtctl.st_FS_ActTIsgl SET */
//         if ((lgtctl.st_E2Ems_TI.ovr >= 500) ||
//             (lgtctl.st_E2Ems_TI.cnt >= 250) ||
//             (lgtctl.st_E2Ems_TI.crc >= 250) ||
//             (lgtctl.st_busoff == 1))
//         { lgtctl.st_FS_ActTIsgl = 1; }
//         /*  lgtctl.st_FS_ActTIsgl RESET */
//         if ((lgtctl.st_E2Ems_TI.ovr == 0) &&
//             (lgtctl.st_E2Ems_TI.cnt == 0) &&
//             (lgtctl.st_E2Ems_TI.crc == 0) &&
//             (lgtctl.st_busoff == 0))
//         { lgtctl.st_FS_ActTIsgl = 0; }
//     }
// #endif  /* (OEM_PLATFORM == OEM_GEELY) */
// #if (OEM_PLATFORM == OEM_SMART)
//     /* smart */
//     if (1)
//     {

//         /* TIMEOUT SET */
//         if ((lgtctl.st_E2Ems_TI.ovr >= 500) ||
//             (lgtctl.st_busoff == 1))
//         { lgtctl.st_FS_TIcond2 = 1; }
//         /* TIMEOUT RESET */
//         if ((lgtctl.st_E2Ems_TI.ovr == 0) &&
//             (lgtctl.st_busoff == 0))
//         { lgtctl.st_FS_TIcond2 = 0; }

//         /**/
//         if ((lgtctl.st_FS_TIcond1 == 1) || 
//             (lgtctl.st_FS_TIcond2 == 1))
//         { lgtctl.st_FS_ActTIsgl = 1; }
//         else
//         { lgtctl.st_FS_ActTIsgl = 0; }
//     }
// #endif  /* (OEM_PLATFORM == OEM_SMART) */

}

static void PincodeCheck(uint16_t ms)
{
    uint8 err;

    /* 获取Pincode配置状态 */
    if ((lgtctl.pr_PCC_cfg == 0) || 
        (lgtctl.st_LgtAct.ActTIsts == ACT_ON) ||
        (lgtctl.st_FS_ActTIsgl == 1))   /* 与转向信号功能安全互斥 */
    {
        lgtctl.st_PCC_err = lgtctl.st_PCC_err0 = 0;
        return;
    }

    /* 获取PINCODE未写状态 */

    /* Pincode错误状态反馈 */
    if (lgtctl.st_PCC_err)
    {
        /* 设置动作标志 */
        if (lgtctl.st_PCC_err0 == 0)
        {
            lgtctl.st_PCC_on1 = 1;
            lgtctl.st_PCC_ms  = 0;
            lgtctl.st_PCC_err0 = lgtctl.st_PCC_err;
        }
        else
        {
            lgtctl.st_PCC_ms += ms;
            if (lgtctl.st_PCC_ms >= 400)
            {
                lgtctl.st_PCC_on1 = lgtctl.st_PCC_on1 ? 0 : 1;
                lgtctl.st_PCC_ms = 0;
            }
        }

        /* 强制转向灯动作 */
        lgtctl.st_LgtAct.ActTIact = lgtctl.st_PCC_on1;
        lgtctl.st_LgtAct.ActTIsts = 1;
        lgtctl.st_LgtAct.ActTInoseq = 1;
    }
    else
    { lgtctl.st_PCC_err0 = 0; }
}

static void _input(uint16_t ms)
{
    uint16 top = 0xFFFF - ms;
    uint32 u32v=0;
#if (EMC_TEST_ENABLE == 0)
    /* 功能安全确认 */
    FS_confirm(ms);
#endif  /* (EMC_TEST_ENABLE == 0) */


    if (lgtctl.st_msActLB   <= top) { lgtctl.st_msActLB   += ms; }
    if (lgtctl.st_msActHB   <= top) { lgtctl.st_msActHB   += ms; }
    if (lgtctl.st_msActTI   <= top) { lgtctl.st_msActTI   += ms; }
    if (lgtctl.st_msActDRL  <= top) { lgtctl.st_msActDRL  += ms; }
    if (lgtctl.st_msActPOS  <= top) { lgtctl.st_msActPOS  += ms; }
    if (lgtctl.st_msActCROS <= top) { lgtctl.st_msActCROS += ms; }

    /* 取得网络上灯功能动作输入指令 */
    //          /* 获取网络信号 */          /* 取值修正 */            /* 关命令周期时，清除故障禁止标识 */                       /* LB安全状态==2时，锁定 LB 动作信号 CTS-V1.0.4-7.1.1.1 */
    // /* LB    */get_si_ActnLB   (&u32v);                        if (u32v == 0) { lgtctl.st_LgtOnDis.EnaLB   = ENA_ON; } if (lgtctl.st_FS_ActLBsgl != 2) { lgtctl.in_Act0.ActLB    = u32v; }
    // /* POS   */get_si_ActnPOS  (&u32v);                        if (u32v == 0) { lgtctl.st_LgtOnDis.EnaPOS  = ENA_ON; }                                 { lgtctl.in_Act0.ActPOS   = u32v; }
    // /* HB    */get_si_ActnHB   (&u32v);                        if (u32v == 0) { lgtctl.st_LgtOnDis.EnaHB   = ENA_ON; }                                 { lgtctl.in_Act0.ActHB    = u32v; }
    // /* TIsts */get_si_ActnTIsts(&u32v); u32v = valLR_TI(u32v); if (u32v == 0) { lgtctl.st_LgtOnDis.EnaTI   = ENA_ON; }                                 { lgtctl.in_Act0.ActTIsts = u32v; }
    // /* TIact */get_si_ActnTIact(&u32v); u32v = valLR_TI(u32v);                                                                                         { lgtctl.in_Act0.ActTIact = u32v; }
    // /* DRL   */get_si_ActnDRL  (&u32v);                        if (u32v == 0) { lgtctl.st_LgtOnDis.EnaDRL  = ENA_ON; }                                 { lgtctl.in_Act0.ActDRL   = u32v; }
    // /* CROS  */get_si_ActnCROS (&u32v);                        if (u32v == 0) { lgtctl.st_LgtOnDis.EnaCROS = ENA_ON; }                                 { lgtctl.in_Act0.ActCROS  = u32v; }

    // get_si_ActnTIseq(&u32v); lgtctl.in_Act0.ActTInoseq = u32v ? 0 : 1;

    
    /* 判断灯功能动作输入指令变化 */
    if ((lgtctl.in_Act0.ActLB    == ACT_ON) && (lgtctl.in_Act1.ActLB    == ACT_OFF)) { lgtctl.in_Act1.ActLB    = ACT_ON;  lgtctl.st_msActLB   = 0; }
    if ((lgtctl.in_Act0.ActHB    == ACT_ON) && (lgtctl.in_Act1.ActHB    == ACT_OFF)) { lgtctl.in_Act1.ActHB    = ACT_ON;  lgtctl.st_msActHB   = 0; }
    if ((lgtctl.in_Act0.ActTIsts == ACT_ON) && (lgtctl.in_Act1.ActTIsts == ACT_OFF)) { lgtctl.in_Act1.ActTIsts = ACT_ON;  lgtctl.st_msActTI   = 0; }
    if ((lgtctl.in_Act0.ActDRL   == ACT_ON) && (lgtctl.in_Act1.ActDRL   == ACT_OFF)) { lgtctl.in_Act1.ActDRL   = ACT_ON;  lgtctl.st_msActDRL  = 0; }
    if ((lgtctl.in_Act0.ActPOS   == ACT_ON) && (lgtctl.in_Act1.ActPOS   == ACT_OFF)) { lgtctl.in_Act1.ActPOS   = ACT_ON;  lgtctl.st_msActPOS  = 0; }
    if ((lgtctl.in_Act0.ActCROS  == ACT_ON) && (lgtctl.in_Act1.ActCROS  == ACT_OFF)) { lgtctl.in_Act1.ActCROS  = ACT_ON;  lgtctl.st_msActCROS = 0; }
 
    if ((lgtctl.in_Act0.ActLB    == ACT_OFF) && (lgtctl.in_Act1.ActLB    == ACT_ON)) { lgtctl.in_Act1.ActLB    = ACT_OFF; lgtctl.st_msActLB   = 0; }
    if ((lgtctl.in_Act0.ActHB    == ACT_OFF) && (lgtctl.in_Act1.ActHB    == ACT_ON)) { lgtctl.in_Act1.ActHB    = ACT_OFF; lgtctl.st_msActHB   = 0; }
    if ((lgtctl.in_Act0.ActTIsts == ACT_OFF) && (lgtctl.in_Act1.ActTIsts == ACT_ON)) { lgtctl.in_Act1.ActTIsts = ACT_OFF; lgtctl.st_msActTI   = 0; }
    if ((lgtctl.in_Act0.ActDRL   == ACT_OFF) && (lgtctl.in_Act1.ActDRL   == ACT_ON)) { lgtctl.in_Act1.ActDRL   = ACT_OFF; lgtctl.st_msActDRL  = 0; }
    if ((lgtctl.in_Act0.ActPOS   == ACT_OFF) && (lgtctl.in_Act1.ActPOS   == ACT_ON)) { lgtctl.in_Act1.ActPOS   = ACT_OFF; lgtctl.st_msActPOS  = 0; }
    if ((lgtctl.in_Act0.ActCROS  == ACT_OFF) && (lgtctl.in_Act1.ActCROS  == ACT_ON)) { lgtctl.in_Act1.ActCROS  = ACT_OFF; lgtctl.st_msActCROS = 0; }

    /* 根据延时配置，设置灯功能动作标志 */
    if ((lgtctl.in_Act1.ActLB    == ACT_ON)  && (lgtctl.st_msActLB   >= lgtctl.pr_onDelay_LB  ))  { lgtctl.st_LgtAct.ActLB    = ACT_ON; }
    if ((lgtctl.in_Act1.ActHB    == ACT_ON)  && (lgtctl.st_msActHB   >= lgtctl.pr_onDelay_HB  ))  { lgtctl.st_LgtAct.ActHB    = ACT_ON; }
    if ((lgtctl.in_Act1.ActTIsts == ACT_ON)  && (lgtctl.st_msActTI   >= lgtctl.pr_onDelay_TI  ))  { lgtctl.st_LgtAct.ActTIsts = ACT_ON; }
    if ((lgtctl.in_Act1.ActDRL   == ACT_ON)  && (lgtctl.st_msActDRL  >= lgtctl.pr_onDelay_DRL ))  { lgtctl.st_LgtAct.ActDRL   = ACT_ON; }
    if ((lgtctl.in_Act1.ActPOS   == ACT_ON)  && (lgtctl.st_msActPOS  >= lgtctl.pr_onDelay_POS ))  { lgtctl.st_LgtAct.ActPOS   = ACT_ON; }
    if ((lgtctl.in_Act1.ActCROS  == ACT_ON)  && (lgtctl.st_msActCROS >= lgtctl.pr_onDelay_CROS))  { lgtctl.st_LgtAct.ActCROS  = ACT_ON; }

    if ((lgtctl.in_Act1.ActLB    == ACT_OFF) && (lgtctl.st_msActLB   >= lgtctl.pr_offDelay_LB  )) { lgtctl.st_LgtAct.ActLB    = ACT_OFF; }
    if ((lgtctl.in_Act1.ActHB    == ACT_OFF) && (lgtctl.st_msActHB   >= lgtctl.pr_offDelay_HB  )) { lgtctl.st_LgtAct.ActHB    = ACT_OFF; }
    if ((lgtctl.in_Act1.ActTIsts == ACT_OFF) && (lgtctl.st_msActTI   >= lgtctl.pr_offDelay_TI  )) { lgtctl.st_LgtAct.ActTIsts = ACT_OFF; }
    if ((lgtctl.in_Act1.ActDRL   == ACT_OFF) && (lgtctl.st_msActDRL  >= lgtctl.pr_offDelay_DRL )) { lgtctl.st_LgtAct.ActDRL   = ACT_OFF; }
    if ((lgtctl.in_Act1.ActPOS   == ACT_OFF) && (lgtctl.st_msActPOS  >= lgtctl.pr_offDelay_POS )) { lgtctl.st_LgtAct.ActPOS   = ACT_OFF; }
    if ((lgtctl.in_Act1.ActCROS  == ACT_OFF) && (lgtctl.st_msActCROS >= lgtctl.pr_offDelay_CROS)) { lgtctl.st_LgtAct.ActCROS  = ACT_OFF; }

    lgtctl.st_LgtAct.ActTIact = lgtctl.in_Act0.ActTIact;

    lgtctl.st_LgtAct.ActTInoseq = lgtctl.in_Act0.ActTInoseq;

    /* Dync */
    // get_si_ActnPOS_Dyn(&u32v);  lgtctl.st_LgtAct.ActPOS_Dyn  = u32v;
    // get_si_ActnCROS_Dyn(&u32v); lgtctl.st_LgtAct.ActCROS_Dyn = u32v;


    /* Pincode检测 */
    PincodeCheck(ms);   /* CTS-7.3.12 */

    /* 功能安全命令，_input()之后 */
    if (lgtctl.st_FS_ActLBsgl == 1)
    {
        lgtctl.st_LgtAct.ActLB  = ACT_ON;
        lgtctl.st_LgtAct.ActPOS = ACT_ON;
    }
    if (lgtctl.st_FS_ActTIsgl == 1) /* 转向灯动作优先级:功能安全>PINCODE检测 */
    {
        lgtctl.st_LgtAct.ActTIact = ACT_OFF;    /* CTS-7.1.2 */
    }

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
    uint32 u32v;

    /* Lighting Disabled, Feedback Error */
    if ((lgtctl.st_LgtAct.ActLB    == ENA_ON) && (lgtctl.st_LgtDS_LB  .bits.ot_chn || lgtctl.st_LgtDS_LB  .bits.ot_led || lgtctl.st_LgtDS_LB  .bits.ot_amb || lgtctl.st_LgtDS_LB  .bits.mo_N_1)) { lgtctl.st_LgtSts.StsLB   = STS_ERR; }
    if ((lgtctl.st_LgtAct.ActHB    == ENA_ON) && (lgtctl.st_LgtDS_HB  .bits.ot_chn || lgtctl.st_LgtDS_HB  .bits.ot_led || lgtctl.st_LgtDS_HB  .bits.ot_amb || lgtctl.st_LgtDS_HB  .bits.mo_N_1)) { lgtctl.st_LgtSts.StsHB   = STS_ERR; }
    if ((lgtctl.st_LgtAct.ActTIsts == ENA_ON) && (lgtctl.st_LgtDS_TI  .bits.ot_chn || lgtctl.st_LgtDS_TI  .bits.ot_led || lgtctl.st_LgtDS_TI  .bits.ot_amb || lgtctl.st_LgtDS_TI  .bits.mo_N_1)) { lgtctl.st_LgtSts.StsTI   = STS_ERR; }
    if ((lgtctl.st_LgtAct.ActDRL   == ENA_ON) && (lgtctl.st_LgtDS_DRL .bits.ot_chn || lgtctl.st_LgtDS_DRL .bits.ot_led || lgtctl.st_LgtDS_DRL .bits.ot_amb || lgtctl.st_LgtDS_DRL .bits.mo_N_1)) { lgtctl.st_LgtSts.StsDRL  = STS_ERR; }
    if ((lgtctl.st_LgtAct.ActPOS   == ENA_ON) && (lgtctl.st_LgtDS_POS .bits.ot_chn || lgtctl.st_LgtDS_POS .bits.ot_led || lgtctl.st_LgtDS_POS .bits.ot_amb || lgtctl.st_LgtDS_POS .bits.mo_N_1)) { lgtctl.st_LgtSts.StsPOS  = STS_ERR; }
    if ((lgtctl.st_LgtAct.ActCROS  == ENA_ON) && (lgtctl.st_LgtDS_CROS.bits.ot_chn || lgtctl.st_LgtDS_CROS.bits.ot_led || lgtctl.st_LgtDS_CROS.bits.ot_amb || lgtctl.st_LgtDS_CROS.bits.mo_N_1)) { lgtctl.st_LgtSts.StsCROS = STS_ERR; }

    /* N-1 Enable/Disable Feedback */
    /* if ((lgtctl.st_LgtAct.ActLB    == ENA_ON) && (lgtctl.st_LgtOnDis.EnaLB   == ENA_OFF)) { lgtctl.st_LgtSts.StsLB   = STS_ERR; }
    if ((lgtctl.st_LgtAct.ActHB    == ENA_ON) && (lgtctl.st_LgtOnDis.EnaHB   == ENA_OFF)) { lgtctl.st_LgtSts.StsHB   = STS_ERR; }
    if ((lgtctl.st_LgtAct.ActTIsts == ENA_ON) && (lgtctl.st_LgtOnDis.EnaTI   == ENA_OFF)) { lgtctl.st_LgtSts.StsTI   = STS_ERR; }
    if ((lgtctl.st_LgtAct.ActDRL   == ENA_ON) && (lgtctl.st_LgtOnDis.EnaDRL  == ENA_OFF)) { lgtctl.st_LgtSts.StsDRL  = STS_ERR; }
    if ((lgtctl.st_LgtAct.ActPOS   == ENA_ON) && (lgtctl.st_LgtOnDis.EnaPOS  == ENA_OFF)) { lgtctl.st_LgtSts.StsPOS  = STS_ERR; }
    if ((lgtctl.st_LgtAct.ActCORN  == ENA_ON) && (lgtctl.st_LgtOnDis.EnaCORN == ENA_OFF)) { lgtctl.st_LgtSts.StsCORN = STS_ERR; }
    if ((lgtctl.st_LgtAct.ActFOG   == ENA_ON) && (lgtctl.st_LgtOnDis.EnaFOG  == ENA_OFF)) { lgtctl.st_LgtSts.StsFOG  = STS_ERR; }
    if ((lgtctl.st_LgtAct.ActLOGO  == ENA_ON) && (lgtctl.st_LgtOnDis.EnaLOGO == ENA_OFF)) { lgtctl.st_LgtSts.StsLOGO = STS_ERR; }
    if ((lgtctl.st_LgtAct.ActCROS  == ENA_ON) && (lgtctl.st_LgtOnDis.EnaCROS == ENA_OFF)) { lgtctl.st_LgtSts.StsCROS = STS_ERR; }
    if ((lgtctl.st_LgtAct.ActGRIL  == ENA_ON) && (lgtctl.st_LgtOnDis.EnaGRIL == ENA_OFF)) { lgtctl.st_LgtSts.StsGRIL = STS_ERR; } */
    

    /* 功能安全状态， _output()之前   CTS-V1.0.4-7.1.1.1 */
    if (lgtctl.st_FS_ActLBsgl != 0)
    {
        if (lgtctl.st_LgtAct.ActLB == ACT_ON)
        { lgtctl.st_LgtSts.StsLB  = STS_ERR; }
    }


    /* TI功能安全反馈状态 CTS-7.1.2 */
    if (lgtctl.st_FS_ActTIsgl == 1)
    { lgtctl.st_LgtSts.StsTI = (lgtctl.st_LgtAct.ActTIsts == ACT_ON) ? STS_ERR : STS_OFF;}
    else
    { if (lgtctl.st_PCC_err) { lgtctl.st_LgtSts.StsTI = STS_ERR; } }    /* CTS-7.3.12 */
    /* L/R故障直接反馈ERROR，CTS-6.6.2 */
    u32v = lgtctl.st_LgtSts.StsCROS; 

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

    /* 动态灯光 */
    // Dynamic_Charging_Light_MainFunction(ms);
    
    LB_Run_On();
#if (LGT_DIS_ADB == 0)
    // ADB_HB_Run_On();
#endif  /* QHG_DIS_ADB */
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

void LIN_Light(uint8 *rxbuf)
{
    if(rxbuf[0]&0x01==1)//HS1开
    {

    }
    if(rxbuf[1]&0x01==1)//HS2开
    {

    }
    if(rxbuf[2]&0x01==1)//DC MOTER
    {

    }

    if((rxbuf[0]&0x02)!=0)//贯穿灯亮
    {
        LightEna.EnaCROS=1; 
    }
    else if((rxbuf[0]&0x02)==0)//贯穿灯亮
    {
        LightEna.EnaCROS=0;  
    }

    if((rxbuf[3]&0x01)!=0)//近光 亮
    {
        LightEna.EnaLB=1; 
    }
    else if((rxbuf[3]&0x01)==0)//近光 灭
    {
        LightEna.EnaLB=0;  //CH1  近光、远光
    }

    if((rxbuf[3]&0x02)!=0)//远光开
    {
        LightEna.EnaHB=1;
    }
    else if((rxbuf[3]&0x02)==0)//远光关
    {
        LightEna.EnaHB=0;
    }
   
    if(((rxbuf[3]&0x04)!=0)||((rxbuf[3]&0x08)!=0))//位置 开
    {
       LightEna.EnaPOS=1;
    } 
    else if(((rxbuf[3]&0x04)==0)&&((rxbuf[3]&0x08)==0))//位置
    {
        LightEna.EnaPOS=0;
    } 

    if((rxbuf[3]&0x10)!=0)//转向打开
    {
       LightEna.EnaTI=1;
    }
    else if((rxbuf[3]&0x10)==0)//转向关
    {
        LightEna.EnaTI =0;
    }
}


void Light_Manager(uint8 pwmper)
{  
     if(LightEna.EnaCROS==1)//远光开
    {
        Front_Cross_Lamp_RunOn(pwmper);
    }
    else //远光关
    {
        Front_Cross_Lamp_RunOff();
    }

    if(LightEna.EnaHB==1)//远光开
    {
        LowBeam_RunOn(pwmper);
        HighBeam_RunOn(pwmper);
        Dio_WriteChannel(DioConf_DioChannel_HSD_EN1, STD_HIGH);//HSE_EN=1 打开风扇
        Dio_WriteChannel(DioConf_DioChannel_HSD_EN2, STD_HIGH);//HSE_EN=1 打开电机
    }
    else //远光关
    {
        HighBeam_RunOff();
    }

    if(LightEna.EnaLB==1)//近光 开
    {
        LowBeam_RunOn(pwmper);
        Dio_WriteChannel(DioConf_DioChannel_HSD_EN1, STD_HIGH);//HSE_EN=1 打开风扇
        Dio_WriteChannel(DioConf_DioChannel_HSD_EN2, STD_HIGH);//HSE_EN=1 打开电机
    }
    else if((LightEna.EnaLB==0)&&(LightEna.EnaHB==0))//近光关
    {
        LowBeam_RunOff();
        Dio_WriteChannel(DioConf_DioChannel_HSD_EN1, STD_LOW);//HSE_EN=1 打开风扇
        Dio_WriteChannel(DioConf_DioChannel_HSD_EN2, STD_LOW);//HSE_EN=1 打开电机
    } 
   
    if((LightEna.EnaPOS==0)&&(LightEna.EnaDRL==0)&&(LightEna.EnaTI==0))
    {
       PosDrlTurn_Alloff();//含共发光面
    }
    else
    {
        if(LightEna.EnaTI==1)//转向
        {
            Turn_RunOn(100);
        }
        else//转向 打开关闭
        {
            Turn_RunOff();
        }
        if(((LightEna.EnaPOS==1)||(LightEna.EnaDRL==1))&&(LightEna.EnaTI==0))//位置 开
        {
           PosDrl_RunOn(100);
        } 
        else //位置
        {
            PosDrl_RunOff();
        } 
    }
}

























