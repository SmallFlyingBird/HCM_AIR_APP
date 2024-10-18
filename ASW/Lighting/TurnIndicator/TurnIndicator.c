/**
 * @file TurnIndicator.c
 * @author QinHaigang (qinhaigang@xyl.cn)
 * @brief 
 * @version 0.2
 * @date 2024-05-10
 * 
 * @copyright Copyright (c) 2024-  New Elec. Dept. XYL
 * 
 * @par History:
 * <table>
 * <tr><th>Data       <th>Version <th>Author     <th>Description
 * <tr><td>2024-05-06 <td>0.1     <td>QinHaigang <td>First
 * <tr><td>2024-05-10 <td>0.2     <td>QinHaigang <td>未定义流水单元做普通转向的亮灭动作
 * </table>
 */

/* Base Include */
#include "HcmPlatform.h"
#include "GeneralFunction.h"
#include "Parameter_Interface.h"
#include "MatrixChip_Interface.h"
#include "ComSignal_Interface.h"

/* Lighting Include */
#include "LampManager.h"
#include "Lighting.h"

#include "TurnIndicator.h"


typedef enum _TIS_
{
    TIS_OFF = 0,
    TIS_LEON,
    TIS_RION,
    TIS_LERION
}e_TIS_t;
typedef enum _SW_
{
    SS_ON = 0,
    SS_OFF
}e_SS_t;
typedef enum _FBS_
{
    FBS_OFF = 0,
    FBS_ON,
    FBS_ERR,
    FBS_Res
}e_FBS_T;


/* pr_:配置参数, in_:控制输入, ou_:控制输出, er_:错误输出, st_:中间数据 */

typedef struct _TICtl_
{
    uint8_t     pr_lr       :1; /* 左/右识别 */

    S_LF_Info_T pr_lfinfo;      /* TI灯光配置信息 */

    uint16_t    pr_onDelay;
    uint16_t    pr_offDelay;
    uint16_t    pr_onRamp;
    uint16_t    pr_offRamp;

    uint8_t     pr_pLedSeqTiHwl;
    uint8_t     pr_pVariantTyp;
    uint16_t    pr_pSTITime;

    /* N-1 */
    uint8_t     pr_N_1              :1; /* 0:能亮则亮; 1:1灭全灭 */

    uint8_t     st_disSeqTI         :1; /* 0:不禁止流水功能；1：禁止流水功能 */

    uint8_t     st_act  :1; /* 0:deactivation; 1:activation */
    uint16_t    st_actms;   /* act翻转计时（0->1或1->0时重新开始计时） */

    uint8_t     st_STIUnit[TI_MAX_MATRIXCHIP_NUM*MAX_MATRIXCHIP_CHANNEL_NUM];
    uint8_t     st_STIUnitIdx[13];  /* 各UNIT开头序号 */
    uint8_t     st_STIUnitNum[13];  /* 各UNIT的LED数量，暂未用先内存占位，Reserved for occupy mem */
    uint8_t     st_STInum;  /* 参与流水的UNIT个数 */
    uint8_t     st_STIcur;  /* 当前流到哪个UNIT */
    uint16_t    st_STIspa;  /* 流水间隔时间 */
    uint16_t    st_STIms;   /* 流水UNIT时间到 */

    uint8_t     st_stsTI    :1;     /*  */
    uint8_t     st_actTI    :1;     /* 0:act; 1:un-act */
    uint8_t     st_noseqTI  :1;     /* 0:seq; 1:no-seq */
    uint8_t     st_enaTI    :1;     /* 0:disable; 1:enable */
    uint8_t     st_turnTI   :1;     /* 0:turn off; 1:turn on */
    uint8_t     st_res_b8   :3;

    uint8_t     st_onErr    :1; /* 开灯故障记录，0:no; 1:yes */
    
}S_TICtl_t;

static S_TICtl_t tictl, *_ctl = 0;


/* max UNIT number, 12个有效UNIT 和 1个无效UNIT */
#define mUINT    (13)   

static void build_STIUnit(void)
{
    /* STI Unit 配置数据 */
    const uint8 *pCfg = Get_pTIPixelToLedUnitAddress();
    /* max LED number */
    const int    mLED = TI_MAX_MATRIXCHIP_NUM*MAX_MATRIXCHIP_CHANNEL_NUM;
    
    int      i, j, total;
    int         n[mUINT];  /* 各UNIT的数量 */
    uint8_t    *p[mUINT];  /* 指向STIUnit单元，用于第2次扫描 */


    /* STI信息获取 */

    for (i=0; i<mUINT; i++) {n[i] = 0; p[i] = NULL;}    /* 清零 */

    /* 第1次扫描，获取各UNIT数量 */
    for (i=0; i<mLED; i++)
    {
        switch (pCfg[i])
        {
        case  0: n[ 0]++; break;
        case  1: n[ 1]++; break;
        case  2: n[ 2]++; break;
        case  3: n[ 3]++; break;
        case  4: n[ 4]++; break;
        case  5: n[ 5]++; break;
        case  6: n[ 6]++; break;
        case  7: n[ 7]++; break;
        case  8: n[ 8]++; break;
        case  9: n[ 9]++; break;
        case 10: n[10]++; break;
        case 11: n[11]++; break;
        case 12: n[12]++; break;
        default:;
        }
    }

    /* 填充各UNIT开始的序号，及各UNIT区域开头指针 */
    for (i=0; i<mUINT; i++)
    {
        if (i==0) { tictl.st_STIUnitIdx[i] = 0; }
        else
        {
            total = 0;
            for (j=0; j<i; j++) { total += n[j]; }

            tictl.st_STIUnitIdx[i] = total;
        }
        p[i] = &(tictl.st_STIUnit[tictl.st_STIUnitIdx[i]]);
    }

    /* 统计参与流水的UNIT个数 */
    tictl.st_STInum = 0;
    for (i=1; i<mUINT; i++)
    {
        if (n[i] > 0) { (tictl.st_STInum)++; }
        else break;
    }
    if (tictl.st_STInum > 0)
    {
        tictl.st_STIspa = tictl.pr_pSTITime / tictl.st_STInum;
    }
    else
    {
        tictl.st_STIspa = tictl.pr_pSTITime;
    }
    tictl.st_STIcur = 0;

    /* 第2次扫描，填充STIUnit */
    for (i=0; i<mLED; i++)
    {
        switch (pCfg[i])
        {
        case  0: *(p[ 0]) = i; (p[ 0])++; break;
        case  1: *(p[ 1]) = i; (p[ 1])++; break;
        case  2: *(p[ 2]) = i; (p[ 2])++; break;
        case  3: *(p[ 3]) = i; (p[ 3])++; break;
        case  4: *(p[ 4]) = i; (p[ 4])++; break;
        case  5: *(p[ 5]) = i; (p[ 5])++; break;
        case  6: *(p[ 6]) = i; (p[ 6])++; break;
        case  7: *(p[ 7]) = i; (p[ 7])++; break;
        case  8: *(p[ 8]) = i; (p[ 8])++; break;
        case  9: *(p[ 9]) = i; (p[ 9])++; break;
        case 10: *(p[10]) = i; (p[10])++; break;
        case 11: *(p[11]) = i; (p[11])++; break;
        case 12: *(p[12]) = i; (p[12])++; break;
        default:;
        }
    }
}


static void _act_SetPix(Light_Functions func, 
                        uint16_t        chnM,
                        uint16_t        mtxM,
                        uint8_t         perc,
                        uint16_t        ton,
                        uint16_t        toff
                        )
{
    int i, j;
    uint16_t mask = (chnM & (~mtxM));
    uint8_t pid[MAX_MATRIXCHIP_CHANNEL_NUM];
    uint8_t id;

    /* 设置通道占空比 */
    LampM_SetLampChn(func, mask, perc, ton, toff);  /* 无矩阵通道 */
    LampM_SetLampChn(func, mtxM, 100,  0,   0);     /* 有矩阵通道控制 */
    
    /* 设置各像素占空比 */
    if (mtxM != 0)
    {
        for (i=0; i<MAX_CHANNLE_NUM; i++)
        {
            if (((mtxM) & (0x0001<<i)) != 0)
            {
                lampM_GetLampChnPixId(func, (0x0001<<i), pid);
                for (j=0; j<MAX_MATRIXCHIP_CHANNEL_NUM; j++)
                {
                    id = pid[j];
                    if (id != 0)
                    { LampM_SetLampPix(func, id, perc, ton, toff); }
                }
            }
        }
    }
}

static void all_on(void)
{
    Light_Functions func = E_TurnIndicator;
    uint16_t        chnM = tictl.pr_lfinfo.chnMask;
    uint16_t        mtxM = tictl.pr_lfinfo.mtxMask;
    uint8_t         perc = 100;
    uint16_t        ton  = tictl.pr_onRamp;
    uint16_t        toff = tictl.pr_offRamp;

    _act_SetPix(func, chnM, mtxM, perc, ton, toff);
}
static void all_off(void)
{
    Light_Functions func = E_TurnIndicator;
    uint16_t        chnM = tictl.pr_lfinfo.chnMask;
    uint16_t        mtxM = tictl.pr_lfinfo.mtxMask;
    uint8_t         perc = 0;
    uint16_t        ton  = tictl.pr_onRamp;
    uint16_t        toff = tictl.pr_offRamp;

    /*  */
    _act_SetPix(func, chnM, mtxM, perc, ton, toff);
}
static void unit_onoff0(uint8_t idx, int onoff0)
{
    int i, s, n, v, perc;

    if (idx > 12) return;

    s = tictl.st_STIUnitIdx[idx];

    if (tictl.st_STIcur < 12)
    { n = tictl.st_STIUnitIdx[tictl.st_STIcur+1]-s; }
    else
    { n = tictl.pr_lfinfo.lednum - s; }

    for (i=0; i<n; i++)
    {
        v = tictl.st_STIUnit[s+i] + 1;
        perc = (onoff0 == 0) ? 0 : 100;
        LampM_SetLampPix(E_TurnIndicator, v, perc, tictl.pr_onRamp, tictl.pr_offRamp);
    }

}


static void act_on(int ms, int noseq)
{
    int i;

    /*  */
    if (tictl.st_act == 0)
    {
        tictl.st_act = 1;
        tictl.st_actms = 0;
        tictl.st_STIcur = 0;
        tictl.st_STIms = 0;
    }

    /*  */
    if ((noseq == 0) &&
        ((tictl.pr_pLedSeqTiHwl == 2) || (tictl.pr_pLedSeqTiHwl == 8)) &&
        (tictl.pr_pVariantTyp == 0) &&
        (tictl.pr_lfinfo.lednum > 0))
    {
        if (tictl.st_actms < tictl.st_STIms) return;

        if (tictl.st_STIcur == 0)
        {
            /* 不流水UNIT全开 */
            unit_onoff0(0, 1);

            /* 流水UNIT全关 */
            for (i=1; i<=tictl.st_STInum; i++)
            { unit_onoff0(i, 0); }
        }
        else
        {
            /* 逐个UNIT点亮 */
            if (tictl.pr_lfinfo.lednum > 0)
            {
                unit_onoff0(tictl.st_STIcur, 1);
            }
        }

        tictl.st_STIcur++;
        tictl.st_STIms += tictl.st_STIspa;
    }
    else
    {
        all_on();
    }
}

static void act_off(int ms, int noseq)
{
    int i;

    /* Timer/Counter reset */
    if (tictl.st_act == 1)
    {
        tictl.st_act = 0;
        tictl.st_actms = 0;
        tictl.st_STIcur = 0;
        tictl.st_STIms = 0;
    }
    
    /*  */
    if ((noseq == 0) &&
        ((tictl.pr_pLedSeqTiHwl == 2) || (tictl.pr_pLedSeqTiHwl == 8)) &&
        (tictl.pr_pVariantTyp == 1) &&  /* 关流水 */
        (tictl.pr_lfinfo.lednum > 0))
    {
        if (tictl.st_actms < tictl.st_STIms) return;

        if (tictl.st_STIcur == 0)
        {
            /* 不流水UNIT全关 */
            unit_onoff0(0, 0);

            /* 流水UNIT全开 */
            for (i=1; i<=tictl.st_STInum; i++)
            { unit_onoff0(i, 1); }
        }
        else
        {
            /* 逐个UNIT熄灭 */
            if (tictl.pr_lfinfo.lednum > 0)
            {
                unit_onoff0(tictl.st_STIcur, 0);
            }
        }

        tictl.st_STIcur++;
        tictl.st_STIms += tictl.st_STIspa;
    }
    else
    {
        all_off();
    }
}


int TI_Init(void)
{
    uint16_t u16v;

    C_Memset_B((uint8_t*)(&tictl), 0, sizeof(S_TICtl_t));

    lampM_GetLampInfo(E_TurnIndicator, &(tictl.pr_lfinfo));

    tictl.pr_lr = LR_LE;

#if (DEBUG_LIGHTING_TI)
    tictl.pr_onDelay  = 0;
    tictl.pr_offDelay = 0;
    tictl.pr_onRamp   = 0;
    tictl.pr_offRamp  = 0;

    tictl.pr_pLedSeqTiHwl = 2;      /* 1:不流水; 2:TI; 4:HWL; 8:TI&HWL; o:无效; */
    tictl.pr_pVariantTyp  = 1;      /* 0:开流水; 1:关流水; 2:保留 */
    tictl.pr_pSTITime     = 800;    /* 流水时间ms */

    tictl.pr_N_1 = 0;
#else
    tictl.pr_onDelay  = Get_pLedONDelay(E_TurnIndicator);
    tictl.pr_offDelay = Get_pLedOFFDelay(E_TurnIndicator);
    tictl.pr_onRamp   = Get_pLedOnRampTi(E_TurnIndicator);
    tictl.pr_offRamp  = Get_pLedOffRampTi(E_TurnIndicator);

    tictl.pr_pLedSeqTiHwl = Get_pLedSeqTiHwl();
    tictl.pr_pVariantTyp  = Get_pVariantTyp();
    tictl.pr_pSTITime     = Get_pSTITime();

    /* N-1 */
    u16v = Get_LightN_1();
    if ((u16v & 0x0040) != 0) { tictl.pr_N_1 = 1; }
#endif

    build_STIUnit();

    _ctl = &tictl;

    return 0;
}

int TI_Exit(void)
{
    _ctl = 0;
    return 0;
}

int TI_Run(uint32_t ms)
{
#if (DEBUG_LIGHTING_TI)
    static int debug_ms = 0;
#endif

    S_LgtFuncEna_t ena;
    S_LgtActIns_t  act;
    S_LF_Err_T     err;
    S_LF_Err_T     errDTC;

    int noseq;

    if (_ctl == 0) { return 0; }

    GetLgtFuncEna(&ena);
    GetLgtActIns (&act);
    _ctl->st_stsTI = act.ActTIsts;
    _ctl->st_actTI = act.ActTIact;
    _ctl->st_noseqTI = act.ActTInoseq;
    _ctl->st_enaTI = ena.EnaTI;
    LampM_GetLampBaseErr(&(err));
    LampM_GetLampBaseErr_DTC(&(errDTC));

#if (DEBUG_LIGHTING_TI)

    _ctl->st_enaTI = 1;
    _ctl->st_stsTI = 1;
    _ctl->st_noseqTI = 1; /* 0:流水; 1:不流水 */

    debug_ms += ms;
    if (debug_ms >= 2000) { debug_ms = 0; }

    if (debug_ms <= 1000) { _ctl->st_actTI = 0; }
    else                  { _ctl->st_actTI = 1; }

#endif

    /* set Channel Fault Specal for TI */
    LampM_Specal_TI(_ctl->st_stsTI);

    /* Turn On/Off */
    if ((_ctl->st_stsTI == 1) &&
        (_ctl->st_actTI == 1) &&
        (_ctl->st_enaTI == 1))
    { _ctl->st_turnTI = 1; }
    else
    {
        _ctl->st_turnTI = 0;
    }

    /* disable seqTI */
    if (_ctl->st_stsTI == 0)
    { _ctl->st_disSeqTI = 0; }  /* 关时，清除禁止流水 */

    /* set noseq */
    noseq = _ctl->st_noseqTI;
    if (_ctl->st_disSeqTI)
    { noseq = _ctl->st_disSeqTI; }

    /* Turn Off */
    if (_ctl->st_turnTI == 0)
    {
        if (tictl.pr_lfinfo.being)
        {
            act_off(ms, noseq);
        }

        SetLgtStsFb_TI(STS_OFF);

        /* CTS-6.4.4 */
        /* if ((_ctl->st_stsTI == 1) && (_ctl->st_actTI == 1))
        { SetLgtStsFb_TI(STS_ERR); } */

        /* STS==1时，若上次开灯时有故障,则要反馈故障 */
        if ((_ctl->st_stsTI == 1) && (_ctl->st_onErr == 1))
        { SetLgtStsFb_TI(STS_ERR); }
    }

    /* Turn On */
    if (_ctl->st_turnTI)
    {
        if (tictl.pr_lfinfo.being)
        {
            act_on(ms, noseq);
        }

        SetLgtStsFb_TI(STS_ON); _ctl->st_onErr = 0;
    }

    /* 故障判断 及 反馈 @CTS-5.8.4 */
    if ((_ctl->st_enaTI == 1) &&
        ((_ctl->st_stsTI == 1) || (_ctl->st_actTI == 1)))
    {
        if (((err.chnErr & tictl.pr_lfinfo.chnMask) != 0) ||
            ((err.mtxErr & tictl.pr_lfinfo.mtxMask) != 0))
        {
            if (FEEDERR_LATE == 0) { SetLgtStsFb_TI(STS_ERR); _ctl->st_onErr = 1; }

            /* 故障 关 */
            if (((errDTC.chnErr & tictl.pr_lfinfo.chnMask) != 0) ||
                ((errDTC.mtxErr & tictl.pr_lfinfo.mtxMask) != 0))
            {
                if (FEEDERR_LATE) { SetLgtStsFb_TI(STS_ERR); _ctl->st_onErr = 1; } 

                if (_ctl->pr_N_1) { SetLgtOnDis_TI(); }

                /* 禁止流水功能，春建飞书20240822 */
                _ctl->st_disSeqTI = 1;  /* 故障确认后禁止流水 */
            }
        }

        /* NTC故障，反馈ERROR */
        if ((errDTC.ntcErr & tictl.pr_lfinfo.chnMask) != 0)
        {
            SetLgtStsFb_TI(STS_ERR); _ctl->st_onErr = 1;
        }

        /* dis seqTI --> ERR */
        /* if (_ctl->st_disSeqTI) { SetLgtStsFb_TI(STS_ERR); } */

    }


    /* Timer */
    if ((0xffff-tictl.st_actms) >= ms) { tictl.st_actms += ms; }

    return 0;
}

