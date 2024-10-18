/**
 * @file LampManager.c
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
 * <tr><td>2024-05-06 <td>0.1     <td>QinHaigang <td>
 * </table>
 */

#include "HcmPlatform.h"
#include "GeneralFunction.h"
#include "Parameter_Interface.h"
#include "SystemService_Interface.h"

#include "Buck_Interface.h"
#include "MatrixChip_Interface.h"
#include "Channel_Interface.h"
#include "DerateRatioManager_Interface.h"
#include "LossDerate_Interface.h"
#include "OUVDerate_Interface.h"

#include "DTC_Interface.h"

#include "Lighting.h"
#include "LampManager.h"

#if (QINGHAIGANG) && (QHG_DMONI_orXCP)
#include "DMoni.h"
#endif  /* (QINGHAIGANG) && (QHG_DMONI_orXCP) */

#include "IOCtr_ASW.h"

/*
Channel Falut Handle means
0/other: don't intervene
1      : 3S cycle close/open
2      : disabled-close until user-close
*/
#define CHNFLT_HANDLE_MEANS     (2)

/* 电性能测试，故障不干预 */
#if (QINGHAIGANG)
#if (BUILD_PROJECT_ID == 1)
#define CHNFLT_HANDLE_MEANS     (0)
#endif  /* (BUILD_PROJECT_ID == 1) */
#endif  /* (QINGHAIGANG) */


/**
 * @brief 矩阵集 枚举
 */
typedef enum _MtxSet_
{
    MtxSet_LBHB = 0,
    MtxSet_TI,
    MtxSet_DRLPOS,
    MtxSet_GRIL,
    MtxSet_LOGO,
    MtxSet_ASSI,
    MtxSet_CROSS,
    MtxSetNum               /* 矩阵集的数量 */
} E_MtxSet_t;

/**
 * @brief 矩阵集(TPS集) 纲要结构体
 */
typedef struct _SetGen_
{
    uint16_t    chnMask;    /* 矩阵集 通道掩码 */
    uint16_t    mtxMask;    /* 矩阵集 矩阵掩码 */
    uint8_t     start;      /* 矩阵集 行/像素索引的起始位置 */
    uint8_t     num;        /* 矩阵集 行/像素索引的数量 */
    uint8_t     res_B4[2];
}S_SetGen_t;

/**
 * @brief 矩阵集 行/像素索引
 */
typedef struct _Setidx_
{
    uint8_t     set:4;      /* 1个TPS集合中的定义行序号 */
    uint8_t     idx:4;      /* 1个TPS定义行中像素序号 */
    uint8_t     res_B4[2];
} S_SetIdx_t;

/**
 * @brief 
 * 
 */
typedef struct _AimChn_
{
    uint8_t     perc;       /* 目标 工作百分比 */
    uint8_t     perc0;      /* 当前/设置 工作百分比 */

    uint16_t    ton;        /* 完整打开过程时间(ms) */
    uint16_t    toff;	    /* 完整关闭过程时间(ms) */

    uint16_t    curr;       /* 设置电流 */
    uint8_t     ppwm;       /* 实际PWM调整，作用于CHN或MTX */

    uint8_t     bFED    :1; /* 被2F或EPT强制过 */
}S_AimChn_t;

/**
 * @brief 
 * 
 */
typedef struct _AimMtx_
{
    uint8_t     addr;                               /* 矩阵芯片地址 */
    uint8_t     res[3];
    uint8_t     perc[MAX_MATRIXCHIP_CHANNEL_NUM];   /* 目标占空比 */
    uint8_t     perc0[MAX_MATRIXCHIP_CHANNEL_NUM];  /* 当前/设置占空比 */
    uint16_t    ton[MAX_MATRIXCHIP_CHANNEL_NUM];    /* 完整打开过程时间(ms) */
    uint16_t    toff[MAX_MATRIXCHIP_CHANNEL_NUM];   /* 完整关闭过程时间(ms) */                       
}S_AimMtx_t;

/**
 * @brief 
 * 
 */
typedef struct _LampCtl_
{
    /* 通道/矩阵/像素位掩码 */
    uint16_t    chnMask;
    uint16_t    mtxMask;
    uint16_t    pixMask[MAX_CHANNLE_NUM];

    /* 各矩阵集合信息条纲要及像素索引 */
    S_SetGen_t  sg[MtxSetNum];
    S_SetIdx_t  pix[MAX_CHANNLE_NUM*MAX_MATRIXCHIP_CHANNEL_NUM];

    /* 主要用于灯光逻辑调用接口的设置（矩阵芯片地址和通道电流除外）后统一刷新到芯片 */
    S_AimChn_t  aimChn[MAX_CHANNLE_NUM];
    S_AimMtx_t  aimMtx[MAX_CHANNLE_NUM];

    uint8_t     pwm[MAX_MATRIXCHIP_CHANNEL_NUM];    /* 动态读取矩阵PWM百分比值用 */

    /* 所有通道/矩阵/NTC/RBIN底层故障检测掩码 */
    S_LF_Err_T  err;        /* 实时故障 */
    S_LF_Err_T  err_DTC;    /* 已报DTC故障 */
    S_LF_Err_T  erruse;  /* 应用有效的实时故障 */
    S_LF_Err_T  erruseDTC;  /* 应用有效的延时故障 */

    uint16_t    chnOnTime[MAX_CHANNLE_NUM];   /* 通道开时长 */
    uint16_t    chnOffTime[MAX_CHANNLE_NUM];  /* 通道关时长 */

    uint16_t    disChn2Gnd;    /* 通道接地故障 判断禁用标识（带矩阵的通道，矩阵各PWM设置都小于100,可能出现误判） */
    uint16_t    chnErrDelay[MAX_CHANNLE_NUM];   /* 通道故障延时计时 */
    uint16_t    chnOffDelay[MAX_CHANNLE_NUM];   /* 通道故障关闭延时 */

    uint16_t    mtxErrDelay[MAX_CHANNLE_NUM];   /* 矩阵故障延时计时 */
    uint16_t    ntcErrDelay[MAX_CHANNLE_NUM];
    uint16_t    binErrDelay[MAX_CHANNLE_NUM];

    uint16_t    Achn2Vcc;   /* Assert channel Short to VCC flag */
    uint16_t    AchnOpen;   /* Assert ... */
    uint16_t    Achn2Gnd;   /* Assert ... */
    uint16_t    AchnUvol;   /* Assert ... */

    sint32_t    CChg;  /* 本周期耗电流变化 */
    sint32_t    maxchg; /* 最大变化电流 */
    uint8_t     maxUp;  /* 上个周期是否变更最大电流 */

    /* 通道需要特别处理 */
    uint16_t    chnMaskLB;          /* 近光通道掩码 */
    uint16_t    chnMaskLB_UV;       /* the mask of LB channel under voltage */
    uint16_t    chnMaskLB_UV_DTC;   /* the mask of LB channel under voltage DTC */
    uint8_t     b_disUV_LB  :1;     /* 近光忽略欠压故障 */

    /* TI channel Special */
    uint16_t    chnMaskTI;          /* TI channel Mask */
    uint8_t     chnTIuseing :1;     /* TI channel in TI Actn */

}S_LampCtl_t;

static S_LampCtl_t lampctl;

static S_LF_Info_T lightinfo[E_LightFunc_Num];

const uint8_t *idMtx[MAX_CHANNLE_NUM];     /* 指向配置的通道矩阵的像素ID号开头 */

typedef struct _LM_DebugInfo_
{
    uint16_t chnCur[MAX_CHANNLE_NUM];   /* 通道电流 */
    uint8_t  chnCSe[MAX_CHANNLE_NUM];   /* Which Channel Current Select, 0:Reserved / 1:BIN / 2:DID / 3:ConfigTable / other:UnKnown */
    uint8_t  chnPwm[MAX_CHANNLE_NUM];   /* 通道PWM */
    uint8_t  mtxPwm[MAX_CHANNLE_NUM][MAX_MATRIXCHIP_CHANNEL_NUM];
    double   chnVol[MAX_CHANNLE_NUM];   /* 通道电压 */
    uint16_t chnSw;                     /* 通道开关状态 */
}S_LM_DebugInfo_t;
static S_LM_DebugInfo_t lampdeg;


/**
 * @brief 设置通道电流100mA以下时，需要调整通道PWM
 * 
 * @param chn 
 */
void AimChn_ChnCurr_Adj(E_ChannelID chn)
{
    /* 若通道电流小于100mA，则需要调通道的PWM; 0mA/100mA不调整 */
    if ((lampctl.aimChn[chn].curr > 0) &&
        (lampctl.aimChn[chn].curr < 100))
    {
        lampctl.aimChn[chn].ppwm = lampctl.aimChn[chn].curr;
        lampctl.aimChn[chn].curr = 100;
    }
    else
    {
        lampctl.aimChn[chn].ppwm = 100;
    }
}


/**
 * @brief 2F DID 控制通道
 * 
 * @param chn 
 * @param curr 
 */
static void IoCtr2F_ChnCUR(E_ChannelID chn, uint16_t curr) /* 设置电流存在风险 */
{
    if ((lampctl.chnMask & (0x0001 << chn)) != 0)
    {
        lampctl.aimChn[chn].curr = curr;
        AimChn_ChnCurr_Adj(chn);
    }
}
static void IoCtr2F_ChnPWM(E_ChannelID chn, uint8_t perc)
{
    int i;

    if ((lampctl.chnMask & (0x0001 << chn)) != 0)
    {
        if (((lampctl.mtxMask & (0x0001 << chn)) == 0))
        {
            lampctl.aimChn[chn].perc  = perc;
            lampctl.aimChn[chn].perc0 = perc;
        }
        else
        {
            lampctl.aimChn[chn].perc  = 100;
            lampctl.aimChn[chn].perc0 = 100;
            for (i=0; i<MAX_MATRIXCHIP_CHANNEL_NUM; i++)
            {
                lampctl.aimMtx[chn].perc[i]  = perc;
                lampctl.aimMtx[chn].perc0[i] = perc;
            }
        }

        lampctl.aimChn[chn].bFED = 1;
    }
}
static void IoCtr2F_ChnPWM_Reset(E_ChannelID chn)
{
    int i;

    if ((lampctl.chnMask & (0x0001 << chn)) != 0)
    {
        /* 清除强制，只清除一次 */
        if (lampctl.aimChn[chn].bFED == 1)
        {
            lampctl.aimChn[chn].perc0 = lampctl.aimChn[chn].perc;
            for (i=0; i<MAX_MATRIXCHIP_CHANNEL_NUM; i++)
            {
                lampctl.aimMtx[chn].perc0[i] = lampctl.aimMtx[chn].perc[i];
            }

            lampctl.aimChn[chn].bFED = 0;
        }
    }
}
/* static void IoCtr2F_ADBPixPWM(uint8_t *mask, uint8_t *perc)
{ } */
static void IoCtr2F(void)
{
    int i;
    for (i=0; i<MAX_CHANNLE_NUM; i++)
    {
        if (diagioctr_chn[i].ctr == 3)
        {
            /* 2F 强制 */
            if ((diagioctr_chn[i].mask & 0x40) != 0) { IoCtr2F_ChnCUR(i, diagioctr_chn[i].cur); }
            if ((diagioctr_chn[i].mask & 0x80) != 0) { IoCtr2F_ChnPWM(i, diagioctr_chn[i].pwm); }
        }
        if (diagioctr_chn[i].ctr == 0)
        {
            /* 清除强制，只清除一次 */
            IoCtr2F_ChnPWM_Reset(i);
        }
    }

    /* ADB Pix Set/Release */
    /* if (diagioctr_adbpix.ctr == 3)
    { IoCtr2F_ADBPixPWM(diagioctr_adbpix.mask, diagioctr_adbpix.pix); }
    if (diagioctr_adbpix.ctr == 0)
    { ; } */
}

/**
 * @brief 构建所有矩阵集纲要
 */
static void build_MtxSetGen(void)
{
    int i, j, idx;

    int               n;              /* 矩阵集的信息条数量 */
    uint8_t         (*f)(uint8_t id); /* 获取矩阵集信息条的函数 */
    const uint8_t    *p;
    uint8_t          chn;

    S_SetGen_t *psg;    /* 矩阵集纲要 */

    E_MtxSet_t  MS;     /* 矩阵集 */

    for (MS=MtxSet_LBHB; MS<MtxSetNum; MS++)
    {
        psg = &(lampctl.sg[MS]);
        psg->mtxMask    = 0;
        psg->num        = 0;

        switch(MS)
        {
        case MtxSet_LBHB:
            psg->chnMask |= GetChannelMaskByLightFunction(E_LowBeamFlat);
            psg->chnMask |= GetChannelMaskByLightFunction(E_LowBeamKink);
            psg->chnMask |= GetChannelMaskByLightFunction(E_HighBeamSail);
            psg->chnMask |= GetChannelMaskByLightFunction(E_HighBeamSpot);
            n = LOWHIGH_MAX_MATRIXCHIP_NUM;
            f = Get_LB_HB_MatrixInfo;
            psg->start = 0;
            break;
        case MtxSet_TI:
            psg->chnMask |= GetChannelMaskByLightFunction(E_TurnIndicator);
            n = TI_MAX_MATRIXCHIP_NUM;
            f = Get_TI_MatrixInfo;
            psg->start = lampctl.sg[MS-1].start + lampctl.sg[MS-1].num;
            break;
        case MtxSet_DRLPOS:
            psg->chnMask |= GetChannelMaskByLightFunction(E_DaytimeRunningLight);
            psg->chnMask |= GetChannelMaskByLightFunction(E_PositionLight);
            n = DRLPOS_MAX_MATRIXCHIP_NUM;
            f = Get_DRL_POS_MatrixInfo;
            psg->start = lampctl.sg[MS-1].start + lampctl.sg[MS-1].num;
            break;
        case MtxSet_GRIL:
            psg->chnMask |= GetChannelMaskByLightFunction(E_GrilleLamp);
            n = GRILLE_MAX_MATRIXCHIP_NUM;
            f = Get_Grille_MatrixInfo;
            psg->start = lampctl.sg[MS-1].start + lampctl.sg[MS-1].num;
            break;
        case MtxSet_LOGO:
            psg->chnMask |= GetChannelMaskByLightFunction(E_LogoLamp);
            n = LOGO_MAX_MATRIXCHIP_NUM;
            f = Get_Logo_MatrixInfo;
            psg->start = lampctl.sg[MS-1].start + lampctl.sg[MS-1].num;
            break;
        case MtxSet_ASSI:
            psg->chnMask |= GetChannelMaskByLightFunction(E_AssistantLight);
            n = ASSISTANT_MAX_MATRIXCHIP_NUM;
            f = Get_Assistant_MatrixInfo;
            psg->start = lampctl.sg[MS-1].start + lampctl.sg[MS-1].num;
            break;
        case MtxSet_CROSS:
            psg->chnMask |= GetChannelMaskByLightFunction(E_FrontCrossLamp);
            n = FRONTCROSS_MAX_MATRIXCHIP_NUM;
            f = Get_FrontCross_MatrixInfo;
            psg->start = lampctl.sg[MS-1].start + lampctl.sg[MS-1].num;
            break;
        case E_CorneringLight:
        case E_FogLamp:
        case E_SideMarkerLamp:
            /* 未规定矩阵集类型，不参与构建 */
            break;
        default:;
        }

        for (i=0; i<n; i++)
        {
            p = f(i);

            if ((p[0] == 1) &&
                (p[2] >= 1) &&
                (p[2] <= 12)) /*  LMM available */
            {
                chn = p[2] - 1; /* LMM is assigned to which channel */

                psg->mtxMask |= (0x0001 << chn);
                lampctl.aimMtx[chn].addr = p[1];
                idMtx[chn] = &(p[8]);

                for(j=0; j<MAX_MATRIXCHIP_CHANNEL_NUM; j++)
                {
                    if (p[8+j] > 0) /*  Pixel mapping */
                    {
                        psg->num++;

                        idx = p[8+j] - 1 + psg->start;
                        lampctl.pix[idx].set = i;
                        lampctl.pix[idx].idx = j;

                        lampctl.pixMask[chn] |= 0x0001 << j;
                    }
                }
            }
        }
    }
}

/**
 * @brief 构建灯光控制信息
 */
static void build_LightInfo(void)
{
    int i;

    Light_Functions lgt;

    uint16_t chnMask, mtxMask;
    const uint8_t *p;

    E_MtxSet_t m;

    mtxMask = Get_MatrixRealisation();
    p = Get_PixelNoforchannel();

    for (lgt=E_LowBeamFlat; lgt<E_LightFunc_Num; lgt++)
    {
        chnMask = GetChannelMaskByLightFunction(lgt);

        lightinfo[lgt].being = 0;
        lightinfo[lgt].lednum = 0;
        lightinfo[lgt].ledlamp = 0;
        lightinfo[lgt].chnMask = chnMask;
        lightinfo[lgt].mtxMask = chnMask & mtxMask;

        if (chnMask != 0)
        {
            lightinfo[lgt].being = 1;

            chnMask &= mtxMask;
            if (chnMask != 0)
            {
                for (i=0; i<MAX_CHANNLE_NUM; i++)
                {
                    if ((chnMask & (0x0001<<i)) != 0)
                    {
                        lightinfo[lgt].lednum += p[i];
                    }
                }
            }
        }

        for (m=(E_MtxSet_t)0; m<MtxSetNum; m++)
        {
            if ((lampctl.sg[m].mtxMask & chnMask) != 0)
            {
                lightinfo[lgt].ledlamp = lampctl.sg[m].num;
                break;
            }
        }
    }
}

/**
 * @brief 计算本运行周期设置的占空比值
 * 
 * @param cycTime 周期运行时间
 * @param upTime  完整打开过程耗时ms
 * @param dnTime  完整关闭过程耗时ms
 * @param curPwm  当前占空比
 * @param aimPwm  目标占空比
 * @return 本运行周期设置的占空比
 * @CTS-5.1.1
 */
static uint8_t CalcPercStep(uint16_t cycTime,
                            uint16_t upTime, uint16_t dnTime, 
                            uint8_t curPwm, uint8_t aimPwm)
{
#if 1
    uint8_t setPwm = aimPwm;
    uint8_t pwm;

    if (aimPwm > curPwm)
    {
        if ((upTime > 0) && (upTime > cycTime))
        {
            pwm = (100 * cycTime) / upTime;
            if (pwm == 0) { pwm = 1; }

            if ((aimPwm - curPwm) > pwm)
            {
                setPwm = curPwm + pwm;
            }
        }
    }
    if (aimPwm < curPwm)
    {
        if ((dnTime > 0) && (dnTime > cycTime))
        {
            pwm = (100 * cycTime) / dnTime;
            if (pwm == 0) { pwm = 1; }

            if ((curPwm - aimPwm) > pwm)
            {
                setPwm = curPwm - pwm;
            }
        }
    }
    return setPwm;
#else
    /* 测试用 */
    if (curPwm < aimPwm) {return (curPwm+1);}
    if (curPwm > aimPwm) {return (curPwm-1);}
    return aimPwm;
#endif
}

static void ChnPercentSet(uint32_t ms)
{
    int i, j;

    uint8_t  chnPerc;           /* 通道目标占空比 */
    uint8_t  chnPerc0;          /* 通道当前/设置占空比 */

    uint16_t ton, toff;

    uint8_t  addr;          /* 矩阵地址 */
    uint8_t *percArr;       /* 矩阵目标占空比 */
    uint8_t *percArr0;      /* 矩阵当前/设置占空比 */

    for (i=0; i<MAX_CHANNLE_NUM; i++)
    { if ((lampctl.chnMask & (0x0001 << i)) != 0)
    {
        if (((lampctl.mtxMask & (0x0001 << i)) != 0) &&
            (lampctl.pixMask[i] != 0))
        {
            addr = lampctl.aimMtx[i].addr;

            percArr  = lampctl.aimMtx[i].perc;
            percArr0 = lampctl.aimMtx[i].perc0;
            /* Interface_GetMatrixChipChannelPwm(addr, percArr0); */

            for (j=0; j<MAX_MATRIXCHIP_CHANNEL_NUM; j++)
            {
                if ((lampctl.pixMask[i] & (0x0001 << j)) != 0)
                {
                    ton  = lampctl.aimMtx[i].ton[j];
                    toff = lampctl.aimMtx[i].toff[j];

                    percArr0[j] = CalcPercStep(ms, ton, toff, percArr0[j], percArr[j]);
                }
            }

            /* Interface_SetMatrixChipChannelPwm(addr, percArr0); */
        }

        /* update channel */
        chnPerc  = lampctl.aimChn[i].perc;
        chnPerc0 = lampctl.aimChn[i].perc0;
        ton      = lampctl.aimChn[i].ton;
        toff     = lampctl.aimChn[i].toff;

        /* chnPerc0 = Interface_GetChannelCurPWM((E_ChannelID)i); */
        chnPerc0 = CalcPercStep(ms, ton, toff, chnPerc0, chnPerc);
        lampctl.aimChn[i].perc0 = chnPerc0;

    }
    }

}

static void ChnCurrentSet(void)
{
    int i;

    uint16_t chnCurr;   /* 通道电流 */
    /* uint8_t  chnPerc; */   /* 通道占空比，>100 表示无效 */

    uint8_t  derate;    /* 降额比例 */

    /* uint32_t u32v; */

    /* 设置通道电流/占空比 */
    for (i=0; i<MAX_CHANNLE_NUM; i++)
    {
        if ((lampctl.chnMask & (0x0001 << i)) != 0)
        {
            /* 降额判断，先调电流降额，不行再调整PWM值 */
            /* 应用逻辑已设置占空比，这里表示无需降额 */
            /* chnPerc = 0xFF; */ /* PWM值不做调整 */

#if (DEBUG_LIGHTING_LAMPMANAGER)
            /* 通道电流和占空比设置，测试用 */
            chnCurr = 100;   /* 应用逻辑不设置电流，测试时通道统一使用50mA */
#else
            /* 使用正常电流，还是使用降额的电流？ */ 
            
            /* 优先级 BIN>DID>参数配置表  CTS_V1.0.4_4.1.2 */
            chnCurr = Interface_GetChannelBinCurrent((E_ChannelID)i);
            if (chnCurr == INVALIED_CURRENT)
            {
                chnCurr = Interface_GetChannelDidConfigCurrent((E_ChannelID)i);
                if (chnCurr == INVALIED_CURRENT)
                {
                    chnCurr = Interface_GetChannelParamTableNormalCurrent((E_ChannelID)i);
                    lampdeg.chnCSe[i] = 3;
                }
                else
                { lampdeg.chnCSe[i] = 2; }
            }
            else
            { lampdeg.chnCSe[i] = 1; }

            /* 获取通道的降额百分比 */
            derate = Interface_GetChannelDerateRatio((E_ChannelID)i);
            if (derate == 0) 
            { chnCurr = 0; }
            else if (derate < 100) 
            { chnCurr = ((uint32_t)chnCurr)*((uint32_t)derate) / ((uint32_t)100); }
#endif

            lampctl.aimChn[i].curr = chnCurr;
            /* Interface_SetChannelCurrent((E_ChannelID)i, lampctl.aimChn[i].curr); */

            /* 若通道电流小于100mA，则需要调通道的PWM */
            if ((lampctl.aimChn[i].curr > 0) &&
                (lampctl.aimChn[i].curr < 100))
            {
                lampctl.aimChn[i].ppwm = lampctl.aimChn[i].curr;
                lampctl.aimChn[i].curr = 100;
            }
            else
            {
                lampctl.aimChn[i].ppwm = 100;
            }
        }
    }
}

static void ChnMtxWorkingSet(uint32_t ms)
{
    int i, j;

    E_ChannelState aim;         /* 通道使能 */

    uint8_t  chnPerc0;          /* 通道当前/设置占空比 */
    uint8_t  chnPwm;

    uint8_t  addr;                                  /* 矩阵地址 */
    uint8_t  mtxPwm[MAX_MATRIXCHIP_CHANNEL_NUM];    /* 矩阵当前/设置占空比 */

    /*  U_ChannelDiagState chnDiag; */
    U_ChannelErrorState chnErr;     /* 通道故障 */
    E_ChannelState      chnSwSta;   /* 通道开关状态 */
    uint16_t            chnCurrVal; /* 通道电流状态 */
    uint8_t             mtxErr;     /* 矩阵通讯丢失故障 */

    uint32_t u32v;
    uint16_t u16v;
    uint8_t  u8v;

    /* IOCtr2F 强制通道工作 */
    IoCtr2F();

    /* */
    for (i=0; i<MAX_CHANNLE_NUM; i++)
    {
        aim = CHANNEL_STATE_OFF;

        Interface_GetChannelSwitchState(i, &chnSwSta);               /* 当前开关 */
        chnCurrVal = Interface_GetChannelCurCurrent((E_ChannelID)i); /* 当前电流 */

#if (DEBUG_LIGHTING_LM_READ)
        test_chnPerc[i] = Interface_GetChannelCurPWM((E_ChannelID)i);       /* 测试 读取通道PWM */
        test_chnCurr[i] = Interface_GetChannelCurCurrent((E_ChannelID)i);
#endif  /* DEBUG_LIGHTING_LM_READ */

#if (CHNFLT_HANDLE_MEANS == 1)
        /* 故障关计时 */
        lampctl.chnOffDelay[i] = C_SubToMin_U16(lampctl.chnOffDelay[i], ms);
#endif  /* (CHNFLT_HANDLE_MEANS == 1) */
#if (CHNFLT_HANDLE_MEANS == 2)
        if ((lampctl.chnMask & (0x0001 << i)) != 0)
        {
            int delay_clr = 0;
            if (lampctl.aimChn[i].perc == 0)    /* 若应用设置通了道工作百分比0 */
            {
                if (lampctl.chnOffDelay[i] > 0) /* 若因故障关闭 */
                {
                    if ((((lampctl.chnMaskTI & (0x0001<<i)) != 0) && (lampctl.chnTIuseing))==0) /* TI special */
                    {
                        delay_clr = 1;
                        lampctl.aimChn[i].perc0 = 0;
                    }
                }
            } 

            if ((lampctl.mtxMask & (0x0001 << i)) != 0)
            {
                u32v = 0;
                for (j=0; j<MAX_MATRIXCHIP_CHANNEL_NUM; j++)
                { u32v += lampctl.aimMtx[i].perc[j]; }
                if (u32v == 0)                      /* 若应用设置了矩阵工作百分比0 */
                {
                    if (lampctl.chnOffDelay[i] > 0) /* 若因故障关闭 */
                    {
                        if ((((lampctl.chnMaskTI & (0x0001<<i)) != 0) && (lampctl.chnTIuseing))==0) /* TI special */
                        {
                            delay_clr = 1;
                            C_Memset_B(lampctl.aimMtx[i].perc0, 0, MAX_MATRIXCHIP_CHANNEL_NUM);
                        }
                    }
                }
            }

            if ((delay_clr) && ((lampctl.Achn2Vcc & (0x0001<<i)) == 0))
            /* if ((delay_clr) && 
                ((lampctl.Achn2Vcc & (0x0001<<i)) == 0) &&
                ((lampctl.AchnOpen & (0x0001<<i)) == 0) &&
                ((lampctl.Achn2Gnd & (0x0001<<i)) == 0) &&
                ((lampctl.AchnUvol & (0x0001<<i)) == 0)) */
            {
                lampctl.chnOffDelay[i] = 0;

                /* 清除通道故障 */
                lampctl.err.chnErr &= ~(0x0001<<i);     /* 清除实时故障 */
                lampctl.chnErrDelay[i] = 0;             /* 清除故障计时 */
                lampctl.err_DTC.chnErr &= ~(0x0001<<i); /* 清除确认故障 */
                /* 清除矩阵故障 */
                lampctl.err.mtxErr &= ~(0x0001<<i);
                lampctl.mtxErrDelay[i] = 0;
                lampctl.err_DTC.mtxErr &= ~(0x0001<<i);
            }
        }
#endif  /* (CHNFLT_HANDLE_MEANS == 2) */

        if (((lampctl.chnMask & (0x0001 << i)) != 0) &&
            (lampctl.chnOffDelay[i] == 0))
        {

#if (CHNFLT_HANDLE_MEANS == 1) || (CHNFLT_HANDLE_MEANS == 2)
            /* 故障关闭通道 */
            if ((lampctl.err_DTC.chnErr & (0x0001<<i)) ||
                (lampctl.err_DTC.mtxErr & (0x0001<<i)))
            {
                lampctl.chnOffDelay[i] = 3000;  /* 通道故障关3秒 */
            }
#endif  /* (CHNFLT_HANDLE_MEANS == 1) || (CHNFLT_HANDLE_MEANS == 2) */

            /* 检测设置 */
            chnPerc0 = lampctl.aimChn[i].perc0;
            /* chnPerc0 = Interface_GetChannelCurPWM((E_ChannelID)i); */

            if ((lampctl.aimChn[i].curr > 0) &&
                (chnPerc0 > 0))
            {
                if ((lampctl.mtxMask & (0x0001 << i)) == 0)
                {
                    aim = CHANNEL_STATE_ON;

                    /* 计算实际设置值 */
                    if (lampctl.aimChn[i].ppwm < 100)
                    {
                        u16v  = lampctl.aimChn[i].ppwm;
                        u16v *= lampctl.aimChn[i].perc0;
                        u16v /= 100;
                        chnPwm = u16v;
                    }
                    else
                    {
                        chnPwm = lampctl.aimChn[i].perc0;
                    }
                    /* 设置通道PWM */
                    Interface_SetChannelPWM((E_ChannelID)i, chnPwm);
                }
                else
                {
                    u32v = 0;
                    u8v  = 0;
                    addr = lampctl.aimMtx[i].addr;

                    C_Memcpy_B(mtxPwm, lampctl.aimMtx[i].perc0, MAX_MATRIXCHIP_CHANNEL_NUM);
                    /* Interface_GetMatrixChipChannelPwm(addr, percArr0); */
#if (DEBUG_LIGHTING_LM_READ)
                    C_Memcpy_B(test_mtxPerc[i], percArr0, MAX_MATRIXCHIP_CHANNEL_NUM);
#endif  /* DEBUG_LIGHTING_LM_READ */

                    for (j=0; j<MAX_MATRIXCHIP_CHANNEL_NUM; j++)
                    {
                        /* 已配置PIX-ID的，表示存在的LED，参与计算；未配置PIX-ID的，表示不存在，不参与计算 */
                        if ((lampctl.pixMask[i] & (0x0001<<j)) != 0)
                        {
                            if (lampctl.aimChn[i].ppwm < 100)
                            {
                                u16v  = lampctl.aimChn[i].ppwm;
                                u16v *= mtxPwm[j];
                                u16v /= 100;
                                mtxPwm[j] = u16v;
                            }

                            /* 判断矩阵设置PWM值，是否全0，从而 禁止通道输出 */
                            u32v += mtxPwm[j];

                            /* 判断矩阵设置PWM值，是否有100，从而判断 禁用通道接地故障 */
                            if (u8v < mtxPwm[j]) { u8v = mtxPwm[j]; }
                        }
                    }

                    if (u32v > 0)
                    { aim = CHANNEL_STATE_ON; }

                    /* 设置矩阵PWM */
                    Interface_SetMatrixChipChannelPwm(addr, mtxPwm);

                    /* 设置通道PWM */
                    chnPwm = lampctl.aimChn[i].perc0;
                    Interface_SetChannelPWM((E_ChannelID)i, chnPwm);

                    if (u8v < 100)
                    { lampctl.disChn2Gnd |= (0x0001 << i); }    /* 禁用通道接地故障 */
                    else
                    { lampctl.disChn2Gnd &= ~(0x0001 << i); }   /* 使能通道接地故障 */
                }
            }

        }


        /* 计算周期电流变化 */
        if (aim != chnSwSta)
        {
            if (aim == CHANNEL_STATE_ON)
            { lampctl.CChg += lampctl.aimChn[i].curr; }
            else
            { lampctl.CChg -= lampctl.aimChn[i].curr; }
        }
        else
        {
            if (aim == CHANNEL_STATE_ON)
            {
                lampctl.CChg -= chnCurrVal;
                lampctl.CChg += lampctl.aimChn[i].curr;
            }
        }
        /* 跳过本周期电流设置和开关设置，并提升上限电流 */
        if (lampctl.CChg > lampctl.maxchg)
        {
            i=MAX_CHANNLE_NUM;
            if (lampctl.maxchg < 100000) { lampctl.maxchg += 500; }
            lampctl.maxUp += 1;
            continue;
        }

        /* OUV降额到0，禁止打开通道，不反馈故障 */
        if (0 == Interface_GetDerateRatioOfOUV())
        { aim = CHANNEL_STATE_OFF; }


        if (aim == CHANNEL_STATE_OFF) { Interface_SetChannelSwitchState((E_ChannelID)i, aim); }
        /* 设置通道电流 */
        Interface_SetChannelCurrent((E_ChannelID)i, lampctl.aimChn[i].curr);
        /* 设置通道开关 */
        if (aim == CHANNEL_STATE_ON)  { Interface_SetChannelSwitchState((E_ChannelID)i, aim); }

    }
}

#if (BUILD_PROJECT_ID == 1)
#if (QINGHAIGANG) && (QHG_DMONI_orXCP)
static void EPTest_ChnMtxSet(E_ChannelID chn, uint8_t onoff0)
{
    int i;
    uint8_t percG1[12] = {100,50,50,50,100,100,100,100,0,0,0,0};
    uint8_t percG2[12] = {100,50,50,50,50,50,50,100,100,100,100,100};
    uint8_t perc;

    if (Get_Variant() <= CONFIG_GEN1_MAX)
    { perc = onoff0 ? percG1[chn] : 0; }
    else
    { perc = onoff0 ? percG2[chn] : 0; }


    if ((lampctl.chnMask & (0x0001 << chn)) != 0)
    {
        if (((lampctl.mtxMask & (0x0001 << chn)) != 0))
        {
            for (i=0; i<MAX_MATRIXCHIP_CHANNEL_NUM; i++)
            {
                lampctl.aimMtx[chn].perc[i] = perc;
                lampctl.aimMtx[chn].toff[i] = 0;
                lampctl.aimMtx[chn].ton[i]  = 0;
            }
            
            lampctl.aimChn[chn].perc = 100;
        }
        else
        {
            lampctl.aimChn[chn].perc = perc;
        }
        lampctl.aimChn[chn].toff = 0;
        lampctl.aimChn[chn].ton  = 0;
        
    }
}
static void EPTest(void)
{
    int i;
    
    if ((DMONI_FUN(D_EPTEST)) && (DMONI_SUB(D_EPTEST) == 0))
    {
        uint8_t  cpm = dmoni_rx[D_EPTEST][6] & 0x03;
        if (cpm != 0) return;

        for (i=0; i<8; i++)
        {
            if((dmoni_rx[D_EPTEST][1] & (0x01<<i)) != 0) { EPTest_ChnMtxSet(i, 1); }
            else                                         { EPTest_ChnMtxSet(i, 0); }
        }
        for (i=0; i<4; i++)
        {
            if((dmoni_rx[D_EPTEST][2] & (0x01<<i)) != 0) { EPTest_ChnMtxSet(8+i, 1); }
            else                                         { EPTest_ChnMtxSet(8+i, 0); }
        }
    }
}

static void EPTest_IoCtr2F(void)
{
    int i;

    uint16_t currG1[3][12] = {
        {360,  360, 360, 360, 360, 360, 360, 360,  0,0,0,0},
        {1000, 500, 500, 500, 300, 150, 500, 1000, 0,0,0,0},
        {660,  500, 500, 500, 300, 150, 500, 500,  0,0,0,0}
    };
    uint8_t  percG1[3][12] = {
        {100,  100, 100, 100, 100, 100, 100, 100,  0,0,0,0},
        {100,   50,  50,  50, 100, 100, 100, 100,  0,0,0,0},
        {100,   50,  50,  50, 100, 100, 100, 100,  0,0,0,0}
    };

    uint16_t currG2[3][12] = {
        {320,  320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320},
        {1000, 500, 500, 500, 500, 500, 500, 500, 500, 150, 150, 1000},
        {660,  500, 500, 500, 500, 500, 500, 500, 500, 150, 150, 500}
    };
    uint8_t percG2[3][12] = {
        {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100},
        {100,  50,  50,  50,  50,  50,  50, 100, 100, 100, 100, 100},
        {100,  50,  50,  50,  50,  50,  50, 100, 100, 100, 100, 100}
    };
    
    if ((DMONI_FUN(D_EPTEST)) && (DMONI_SUB(D_EPTEST) == 0))
    {
        uint16_t *curr;
        uint8_t  *perc;

        uint8_t  cpm = dmoni_rx[D_EPTEST][6] & 0x03;


        if (cpm == 0)
        {
            /* 清除强制，只清除一次 */
            for (i=0; i<12; i++) { IoCtr2F_ChnPWM_Reset(i); }
            return;
        }
        else
        { cpm -= 1; }


        if (Get_Variant() <= CONFIG_GEN1_MAX)
        {
            curr = currG1[cpm];
            perc = percG1[cpm];
        }
        else
        {
            curr = currG2[cpm];
            perc = percG2[cpm];
        }

        for (i=0; i<8; i++)
        {
            if((dmoni_rx[D_EPTEST][1] & (0x01<<i)) != 0)
            {
                /* 强制 */
                IoCtr2F_ChnCUR(i, curr[i]);
                IoCtr2F_ChnPWM(i, perc[i]);
            }
            else
            {
                /* 清除强制，只清除一次 */
                IoCtr2F_ChnPWM_Reset(i);
            }
        }
        for (i=0; i<4; i++)
        {
            if((dmoni_rx[D_EPTEST][2] & (0x01<<i)) != 0)
            {
                /* 强制 */
                IoCtr2F_ChnCUR(8+i, curr[8+i]);
                IoCtr2F_ChnPWM(8+i, perc[8+i]);
            }
            else
            {
                /* 清除强制，只清除一次 */
                IoCtr2F_ChnPWM_Reset(8+i);
            }
        }
    }
}
#endif  /* (QINGHAIGANG) && (QHG_DMONI_orXCP) */
#endif  /* (BUILD_PROJECT_ID == 1) */

static 
U_ChannelErrorState _LM_GetChannelState(E_ChannelID index, E_ErrorType ErrorType)
{
    U_ChannelErrorState chnErr;
    chnErr = Interface_GetChannelState(index, ErrorType);
    uint16_t *p_u16v;

    if (E_ErrorType_ErrorDtcState == ErrorType)
    { p_u16v = &(lampctl.chnMaskLB_UV_DTC); }
    else
    { p_u16v = &(lampctl.chnMaskLB_UV); }

    /* 近光通道特殊情况下要求欠压故障不关通道 CTS, 7.4.1.2 */
    if (lampctl.b_disUV_LB)
    {
        if (lampctl.chnMaskLB & (0x0001 << index))
        {
            if (chnErr.bits.UnderVoltage) 
            { (*p_u16v) |=  (0x0001 << index); }
            else
            { (*p_u16v) &= ~(0x0001 << index); }

            chnErr.bits.UnderVoltage = 0;
        }
    }

    /* 调试用，用命令模拟故障 */
    /* if (index == 2)
    {
        S_LgtActIns_t aaa;  GetLgtActIns(&aaa);
        if (aaa.ActLB) {chnErr.bits.UnderVoltage = 1;}
    } */

    return chnErr;
}
static void FaultsHandle(uint32_t ms)
{
    int i;
    U_ChannelErrorState chnErr;     /* 通道故障 */
    U_ChannelErrorState chnErrDTC;     /* 通道故障 */
    E_ChannelState      chnSwSta;   /* 通道开关状态 */

    uint8_t addr;       /* 矩阵地址 */
    uint8_t mtxErr;     /* 矩阵通讯丢失故障 */

    uint8_t chnNtcBin;  /* 通道NTC或BIN的配置 */
    U_Ntc_Error ntcErr, ntcErrDTC;
    U_Bin_Error binErr, binErrDTC;
    uint8_t u8v;

    U_HSDAndFan_Error hsErr, hsErrDTC;  /* 高边故障 */
    uint16_t LMMSupplyFlag;
    uint8_t  lmmErr, lmmErrDTC;

    uint16_t ChFCDelay = 3000;    /* Channel Fault Comfirm delay time (ms) */
    uint16_t ChOpenDelayFb = 400;  /* Channel Open delay feedback error (ms) */

    ntcErr    = Interface_GetNtcErrorState(E_ErrorType_ErrorRealTimeState);
    ntcErrDTC = Interface_GetNtcErrorState(E_ErrorType_ErrorDtcState);
    binErr    = Interface_GetBinErrorState(E_ErrorType_ErrorRealTimeState);
    binErrDTC = Interface_GetBinErrorState(E_ErrorType_ErrorDtcState);

    hsErr    = Interface_GetHSDAndFanErrorState(E_ErrorType_ErrorRealTimeState);
    hsErrDTC = Interface_GetHSDAndFanErrorState(E_ErrorType_ErrorDtcState);

    /* LMM supply DTC */
    LMMSupplyFlag = GetChannelMaskByLightFunction(E_LMM_Supply);
    if ((LMMSupplyFlag & (1 << 12)) != 0)
    {
        if (hsErr.bits.HSD1_OpenOrShort2Vcc_ErrorConfirmed ||
            hsErr.bits.HSD1_OverCur_ErrorConfirmed ||
            hsErr.bits.HSD1_Shor2Gnd_ErrorConfirmed)
        { lmmErr = 1; }
        else
        { lmmErr = 0; }

        if (hsErrDTC.bits.HSD1_OpenOrShort2Vcc_ErrorConfirmed ||
            hsErrDTC.bits.HSD1_OverCur_ErrorConfirmed ||
            hsErrDTC.bits.HSD1_Shor2Gnd_ErrorConfirmed)
        { lmmErrDTC = 1; }
        else
        { lmmErrDTC = 0; }
    }
    else if ((LMMSupplyFlag & (1 << 13)) != 0)
    {
        if (hsErr.bits.HSD2_OpenOrShort2Vcc_ErrorConfirmed ||
            hsErr.bits.HSD2_OverCur_ErrorConfirmed ||
            hsErr.bits.HSD2_Shor2Gnd_ErrorConfirmed)
        { lmmErr = 1; }
        else
        { lmmErr = 0; }

        if (hsErrDTC.bits.HSD2_OpenOrShort2Vcc_ErrorConfirmed ||
            hsErrDTC.bits.HSD2_OverCur_ErrorConfirmed ||
            hsErrDTC.bits.HSD2_Shor2Gnd_ErrorConfirmed)
        { lmmErrDTC = 1; }
        else
        { lmmErrDTC = 0; }
    }
    else if ((LMMSupplyFlag & (1 << 14)) != 0)
    {
        if (hsErr.bits.HSD3_OpenOrShort2Vcc_ErrorConfirmed ||
            hsErr.bits.HSD3_OverCur_ErrorConfirmed ||
            hsErr.bits.HSD3_Shor2Gnd_ErrorConfirmed)
        { lmmErr = 1; }
        else
        { lmmErr = 0; }

        if (hsErrDTC.bits.HSD3_OpenOrShort2Vcc_ErrorConfirmed ||
            hsErrDTC.bits.HSD3_OverCur_ErrorConfirmed ||
            hsErrDTC.bits.HSD3_Shor2Gnd_ErrorConfirmed)
        { lmmErrDTC = 1; }
        else
        { lmmErrDTC = 0; }
    }
    else
    { lmmErr = lmmErrDTC = 0; }


    /* 遍历已配置通道 */
    for (i=0; i<MAX_CHANNLE_NUM; i++)
    { if ((lampctl.chnMask & (0x0001 << i)) != 0)
    {
        /* DebugInfo */
        lampdeg.chnCur[i] = Interface_GetChannelCurCurrent((E_ChannelID)i);
        lampdeg.chnPwm[i] = Interface_GetChannelCurPWM(i);
        addr = lampctl.aimMtx[i].addr;
        Interface_GetMatrixChipChannelPwm(addr, lampdeg.mtxPwm[i]);
        Interface_GetChannelVoltage(i, &(lampdeg.chnVol[i]));
        Interface_GetChannelSwitchState(i, &chnSwSta);  /* 获取当前开关状态 */
        if (chnSwSta == CHANNEL_STATE_ON) { lampdeg.chnSw |=  (0x0001 << i); }
        else                              { lampdeg.chnSw &= ~(0x0001 << i); }

        /* 通道开/关时长统计 */
        if (chnSwSta == CHANNEL_STATE_ON)
        {
            lampctl.chnOnTime[i] = C_AddToMax_U16(lampctl.chnOnTime[i], ms);
            lampctl.chnOffTime[i] = 0;
        }
        else
        {
            lampctl.chnOffTime[i] = C_AddToMax_U16(lampctl.chnOffTime[i], ms);
            lampctl.chnOnTime[i] = 0;
        }

        /* 获取通道故障 */
        chnErr    = _LM_GetChannelState(i, E_ErrorType_ErrorRealTimeState);
        chnErrDTC = _LM_GetChannelState(i, E_ErrorType_ErrorDtcState);

        /* 调整通道故障 */
        if (chnSwSta == CHANNEL_STATE_ON)
        {
            chnErr.bits.Short2VCC = 0;
            chnErrDTC.bits.Short2VCC = 0;

            /* 若是带矩阵通道，矩阵各PWM值都小于100，则忽略接地故障 */
            if ((lampctl.disChn2Gnd & (0x0001 << i)) != 0)
            { chnErr.bits.Short2GndError = 0; }

            /* assert  */
            /* if (chnErrDTC.bits.OpenError)
            { lampctl.AchnOpen |= (0x0001 << i); }
            else
            { lampctl.AchnOpen &= ~(0x0001 << i); }

            if (chnErrDTC.bits.Short2GndError)
            { lampctl.Achn2Gnd |= (0x0001 << i); }
            else
            { lampctl.Achn2Gnd &= ~(0x0001 << i); }

            if (chnErrDTC.bits.UnderVoltage)
            { lampctl.AchnUvol |= (0x0001 << i); }
            else
            { lampctl.AchnUvol &= ~(0x0001 << i); } */
        }
        else
        {
            chnErr.bits.OpenError = 0;
            chnErr.bits.Short2GndError = 0;
            chnErr.bits.UnderVoltage = 0;

            chnErrDTC.bits.OpenError = 0;
            chnErrDTC.bits.Short2GndError = 0;
            chnErrDTC.bits.UnderVoltage = 0;

            /*assert short2vcc*/
            if (chnErrDTC.bits.Short2VCC)
            { lampctl.Achn2Vcc |= (0x0001 << i); }
            else
            { lampctl.Achn2Vcc &= ~(0x0001 << i); }
        }

        /* add short2vcc flag (when closing) */
        if ((lampctl.Achn2Vcc & (0x0001 << i)) != 0)
        {
            chnErr.bits.Short2VCC = 1;
            chnErrDTC.bits.Short2VCC = 1;
        }
        else
        { 
            chnErr.bits.Short2VCC = 0;
            chnErrDTC.bits.Short2VCC = 0;
        }

        /* if ((lampctl.AchnOpen & (0x0001 << i)) != 0)
        {
            chnErr.bits.OpenError = 1;
            chnErrDTC.bits.OpenError = 1;
        }
        else
        { 
            chnErr.bits.OpenError = 0;
            chnErrDTC.bits.OpenError = 0;
        }

        if ((lampctl.Achn2Gnd & (0x0001 << i)) != 0)
        {
            chnErr.bits.Short2GndError = 1;
            chnErrDTC.bits.Short2GndError = 1;
        }
        else
        { 
            chnErr.bits.Short2GndError = 0;
            chnErrDTC.bits.Short2GndError = 0;
        }

        if ((lampctl.AchnUvol & (0x0001 << i)) != 0)
        {
            chnErr.bits.UnderVoltage = 1;
            chnErrDTC.bits.UnderVoltage = 1;
        }
        else
        { 
            chnErr.bits.UnderVoltage = 0;
            chnErrDTC.bits.UnderVoltage = 0;
        } */


        /* 处理通道故障 */
        if (chnErr.Error != 0)
        {
            lampctl.err.chnErr |=  (0x0001<<i);         /* 实时故障 */
            lampctl.chnErrDelay[i] = C_AddToMax_U16(lampctl.chnErrDelay[i], ms); /* 故障计时 */

            /*  */
            if (((lampctl.chnMaskTI & (0x0001<<i)) != 0) && (lampctl.chnTIuseing))
            { ChFCDelay = 100; }
            else
            { ChFCDelay = 3000; }

            if ((lampctl.chnErrDelay[i] > ChFCDelay) &&     /* 延时3秒 */
                (chnErrDTC.Error != 0))                    /* 已报DTC */
            {                                           /* 故障确认 */
                lampctl.err_DTC.chnErr |= (0x0001<<i);
            }
        }
        else
        {
            if (lampctl.chnOffDelay[i] == 0)
            {
                lampctl.err.chnErr &= ~(0x0001<<i);     /* 清除实时故障 */
                lampctl.chnErrDelay[i] = 0;             /* 清除故障计时 */
                lampctl.err_DTC.chnErr &= ~(0x0001<<i); /* 清除确认故障 */
            }
        }

        /* 遍历打开的通道 */
        if (chnSwSta == CHANNEL_STATE_ON)
        {
            /* 获取矩阵通讯故障 Matrix faults */
            if ((lampctl.mtxMask & (0x0001 << i)) != 0)
            {
                /* 获取矩阵实时故障 */
                addr = lampctl.aimMtx[i].addr;
                mtxErr = Interface_GetMatrixChioLostComErrorFlag(addr); /* 矩阵通讯丢失故障 */

                /* mtxErr = 0; lmmErr = 0; */
                if (mtxErr || lmmErr)   /* 矩阵供电故障,合并成矩阵故障 */
                {
                    lampctl.err.mtxErr |= (0x0001<<i);          /* 实时故障 */
                    lampctl.mtxErrDelay[i] = C_AddToMax_U16(lampctl.mtxErrDelay[i], ms); /* 故障计时 */

                    if (lmmErr == 0)    /* 矩阵供电正常 */
                    {
                        if (lampctl.mtxErrDelay[i] > 3000)          /* 延时3秒 */
                        {                                           /* 故障确认 */
                            lampctl.err_DTC.mtxErr |= (0x0001<<i);
                        }
                    }
                    else                /* 矩阵供电故障 */
                    {
                        if ((lampctl.mtxErrDelay[i] > 3000) &&      /* 延时3秒 */
                            (lmmErrDTC))                            /* 已报DTC */
                        {                                           /* 故障确认 */
                            lampctl.err_DTC.mtxErr |= (0x0001<<i);
                        }
                    }
                }
                else
                {
                    lampctl.err.mtxErr &= ~(0x0001<<i);     /* 清除实时故障 */
                    lampctl.mtxErrDelay[i] = 0;             /* 清除故障计时 */
                    lampctl.err_DTC.mtxErr &= ~(0x0001<<i); /* 清除确认故障 */
                }
            }
        }
        else
        {
            if (lampctl.chnOffDelay[i] == 0)
            {
                /* 清除矩阵故障 */
                lampctl.err.mtxErr &= ~(0x0001<<i);
                lampctl.mtxErrDelay[i] = 0;
                lampctl.err_DTC.mtxErr &= ~(0x0001<<i);
            }
        }


        /* 获取通道NTC故障 */
        u8v = 0;
        chnNtcBin = Get_pLedChToNtc(i);
        switch(chnNtcBin)
        {
        case 1:
            if (ntcErr.bits.Ntc1_OpenOrShort2Vcc_ErrorConfirmed != 0) { u8v |= 0x01; }
            if (ntcErr.bits.Ntc1_Short2Gnd_ErrorConfirmed != 0)       { u8v |= 0x02; }
            break;
        case 2:
            if (ntcErr.bits.Ntc2_OpenOrShort2Vcc_ErrorConfirmed != 0) { u8v |= 0x01; }
            if (ntcErr.bits.Ntc2_Short2Gnd_ErrorConfirmed != 0)       { u8v |= 0x02; }
            break;
        case 3:
            if (ntcErr.bits.Ntc3_OpenOrShort2Vcc_ErrorConfirmed != 0) { u8v |= 0x01; }
            if (ntcErr.bits.Ntc3_Short2Gnd_ErrorConfirmed != 0)       { u8v |= 0x02; }
            break;
        case 4:
            if (ntcErr.bits.Ntc4_OpenOrShort2Vcc_ErrorConfirmed != 0) { u8v |= 0x01; }
            if (ntcErr.bits.Ntc4_Short2Gnd_ErrorConfirmed != 0)       { u8v |= 0x02; }
            break;
        case 5:
            if (ntcErr.bits.Ntc5_OpenOrShort2Vcc_ErrorConfirmed != 0) { u8v |= 0x01; }
            if (ntcErr.bits.Ntc5_Short2Gnd_ErrorConfirmed != 0)       { u8v |= 0x02; }
            break;
        case 7:
            if (ntcErr.bits.MatrixNtc1_ErrorConfirmed != 0)           { u8v |= 0x01; }
            break;
        case 8:
            if (ntcErr.bits.MatrixNtc2_ErrorConfirmed != 0)           { u8v |= 0x01; }
            break;
        default:;
        }
        /* */
        if (u8v != 0)
        {
            lampctl.err.ntcErr |=  (0x0001<<i);         /* 实时故障 */
            lampctl.ntcErrDelay[i] = C_AddToMax_U16(lampctl.ntcErrDelay[i], ms); /* 故障计时 */

            if (lampctl.ntcErrDelay[i] > 3000)          /* 延时3秒 */
            {                                           /* 故障确认 */
                lampctl.err_DTC.ntcErr |= (0x0001<<i);
            }
        }
        else
        {
            lampctl.err.ntcErr &= ~(0x0001<<i);     /* 清除实时故障 */
            lampctl.ntcErrDelay[i] = 0;             /* 清除故障计时 */
            lampctl.err_DTC.ntcErr &= ~(0x0001<<i); /* 清除确认故障 */
        }

        /* BIN故障 */
        u8v = 0;
        chnNtcBin = Get_pBinSrcChByChannelID(i);
        switch(chnNtcBin)
        {
        case 1: if (binErr.bits.Bin1ErrorConfirm != 0)       { u8v |= 0x01; } break;
        case 2: if (binErr.bits.Bin2ErrorConfirm != 0)       { u8v |= 0x01; } break;
        case 3: if (binErr.bits.Bin3ErrorConfirm != 0)       { u8v |= 0x01; } break;
        case 4: if (binErr.bits.MatrixBin1ErrorConfirm != 0) { u8v |= 0x01; } break;
        case 5: if (binErr.bits.MatrixBin2ErrorConfirm != 0) { u8v |= 0x01; } break;
        default:;
        }
        /* */
        if (u8v != 0)
        {
            lampctl.err.binErr |=  (0x0001<<i);         /* 实时故障 */
            lampctl.binErrDelay[i] = C_AddToMax_U16(lampctl.binErrDelay[i], ms); /* 故障计时 */

            if (lampctl.binErrDelay[i] > 3000)          /* 延时3秒 */
            {                                           /* 故障确认 */
                lampctl.err_DTC.binErr |= (0x0001<<i);
            }
        }
        else
        {
            lampctl.err.binErr &= ~(0x0001<<i);     /* 清除实时故障 */
            lampctl.binErrDelay[i] = 0;             /* 清除故障计时 */
            lampctl.err_DTC.binErr &= ~(0x0001<<i); /* 清除确认故障 */
        }



        /* 转向通道特别处理 */
        if (((lampctl.chnMaskTI & (0x0001<<i)) != 0) && (lampctl.chnTIuseing))
        { ChOpenDelayFb = 100; }
        else
        { ChOpenDelayFb = 400; }
        /* 通道打开且300ms以内，认为无效 */
        if ((lampctl.chnOnTime[i] > 0) && (lampctl.chnOnTime[i] <= ChOpenDelayFb))
        {
            lampctl.erruse.chnErr    &= ~(0x0001<<i);
            lampctl.erruse.mtxErr    &= ~(0x0001<<i);

            lampctl.erruseDTC.chnErr &= ~(0x0001<<i);
            lampctl.erruseDTC.mtxErr &= ~(0x0001<<i);
        }
        else
        {
            if (lampctl.err.chnErr & (0x0001<<i)) { lampctl.erruse.chnErr |=  (0x0001<<i); }
            else                                  { lampctl.erruse.chnErr &= ~(0x0001<<i); }
            if (lampctl.err.mtxErr & (0x0001<<i)) { lampctl.erruse.mtxErr |=  (0x0001<<i); }
            else                                  { lampctl.erruse.mtxErr &= ~(0x0001<<i); }

            if (lampctl.err_DTC.chnErr & (0x0001<<i)) { lampctl.erruseDTC.chnErr |=  (0x0001<<i); }
            else                                      { lampctl.erruseDTC.chnErr &= ~(0x0001<<i); }
            if (lampctl.err_DTC.mtxErr & (0x0001<<i)) { lampctl.erruseDTC.mtxErr |=  (0x0001<<i); }
            else                                      { lampctl.erruseDTC.mtxErr &= ~(0x0001<<i); }
        }

        /* NTC/BIN故障 */
        if (lampctl.err.ntcErr & (0x0001<<i)) { lampctl.erruse.ntcErr |=  (0x0001<<i); }
        else                                  { lampctl.erruse.ntcErr &= ~(0x0001<<i); }
        if (lampctl.err.binErr & (0x0001<<i)) { lampctl.erruse.binErr |=  (0x0001<<i); }
        else                                  { lampctl.erruse.binErr &= ~(0x0001<<i); }

        if (lampctl.err_DTC.ntcErr & (0x0001<<i)) { lampctl.erruseDTC.ntcErr |=  (0x0001<<i); }
        else                                      { lampctl.erruseDTC.ntcErr &= ~(0x0001<<i); }
        if (lampctl.err_DTC.binErr & (0x0001<<i)) { lampctl.erruseDTC.binErr |=  (0x0001<<i); }
        else                                      { lampctl.erruseDTC.binErr &= ~(0x0001<<i); }

    }
    }

    /* 矩阵通讯故障持续6秒后复位矩阵 */
    #if 0   /* 可能造成灯闪 */
    u8v = 0;
    for (i=0; i<MAX_CHANNLE_NUM; i++)
    { if (lampctl.mtxErrDelay[i] > 6000) { u8v = 1; break; } }
    if (u8v) {
        Interface_AddReInitDrvDevice(E_DrvReInitID_MatrixTrip);
    }
    #endif
}



/*************************** Interface Functions ***************************** */

/**
 * @brief 模块初始化
 */
void LampM_Init(void)
{
    int i;

    /* 初始清零 */
    C_Memset_B((unsigned char*)(&lampctl), 0, sizeof(S_LampCtl_t));
    C_Memset_B((unsigned char*)(&lightinfo), 0, MAX_CHANNLE_NUM*sizeof(S_LF_Info_T));
    C_Memset_B(idMtx, 0, MAX_CHANNLE_NUM);

    /* 取得 配置通道掩码 */
    for (i=0; i<E_LightFunc_Num; i++)
    {
        lampctl.chnMask |= GetChannelMaskByLightFunction((Light_Functions)i);
    }
    /* 取得 配置通道矩阵掩码 */
    lampctl.mtxMask = Get_MatrixRealisation();

    /* 取得 各功能的 配置矩阵掩码 和 配置LED数量 */
    build_MtxSetGen();

    /* 取得 */
    build_LightInfo();

#if 1   /* 初始设置通道和矩阵芯片 */
    for (i=0; i<MAX_CHANNLE_NUM; i++)
    {
        if ((lampctl.chnMask & (0x0001<<i)) != 0)
        {
            Interface_SetChannelSwitchState((E_ChannelID)i, CHANNEL_STATE_OFF);
            Interface_SetChannelCurrent((E_ChannelID)i, 0);
            Interface_SetChannelPWM((E_ChannelID)i, 0);
            if ((lampctl.mtxMask & (0x0001<<i)) != 0)
            {
                Interface_SetMatrixChipChannelPwm(lampctl.aimMtx[i].addr,
                                                  lampctl.aimMtx[i].perc);
            }
        }
    }
#endif
#if 0   /* 测试用 */
    for (i=0; i<MAX_CHANNLE_NUM; i++)
    {
        if ((lampctl.chnMask & (0x0001<<i)) != 0)
        {
            lampctl.aimChn->perc0 = Interface_GetChannelCurPWM((E_ChannelID)i);
            if ((lampctl.mtxMask & (0x0001<<i)) != 0)
            {
                Interface_GetMatrixChipChannelPwm(lampctl.aimMtx[i].addr,
                                                  lampctl.aimMtx[i].perc0);
            }
        }
    }
#endif

    lampctl.maxchg = 500;


    /* 获取近光通道掩码 */
    lampctl.chnMaskLB = lightinfo[E_LowBeamFlat].chnMask | lightinfo[E_LowBeamKink].chnMask;

    /* initial TI channel Mask */
    lampctl.chnMaskTI = lightinfo[E_TurnIndicator].chnMask;
    lampctl.chnTIuseing = 0;
}

/**
 * @brief 模块退出
 */
void LampM_Exit(void)
{
}

#if (DEBUG_LIGHTING_LM_READ)
static E_ChannelState  test_chnSwSta[MAX_CHANNLE_NUM];  /* 当前通道开/关 */
static uint8_t test_chnPerc[MAX_CHANNLE_NUM];           /* 当前通道百分比 */
static uint16_t test_chnCurr[MAX_CHANNLE_NUM];          /* 当前通道电流 */
static uint8_t test_mtxPerc[MAX_CHANNLE_NUM][MAX_MATRIXCHIP_CHANNEL_NUM];   /* 当前通道矩阵各百分比 */
#endif  /* DEBUG_LIGHTING_LM_READ */

/**
 * @brief 灯光控制模块运行周期调用
 */
void LampM_Run(uint32_t ms)
{
    int i, j;

    uint8_t  chnPerc;           /* 通道目标占空比 */
    uint8_t  chnPerc0;          /* 通道当前/设置占空比 */

    uint16_t ton, toff;
    
    uint8_t  addr;              /* 矩阵地址 */
    uint8_t *percArr;           /* 矩阵目标占空比 */
    uint8_t *percArr0 = lampctl.pwm;    /* 矩阵当前/设置占空比 */

    E_ChannelState aim;         /* 通道使能 */

    /*  U_ChannelDiagState chnDiag; */
    U_ChannelErrorState chnErr;     /* 通道故障 */
    E_ChannelState      chnSwSta;   /* 通道开关状态 */
    uint16_t            chnCurrVal; /* 通道电流状态 */
    uint8_t             mtxErr;     /* 矩阵通讯丢失故障 */

    uint32_t u32v;
    uint16_t u16v;
    uint8_t  u8v;

    /* 故障处理 */
    FaultsHandle(ms);

#if 0   /* 测试使用的接口 */
    uint8_t chn = 4;
    uint8_t adr[12] = {0xFF,1,2,3,4,5,0,6,7,0xFF,0xFF,0xFF};
    uint8_t pwm[12] = {0,10,20,30,40,50,60,70,80,90,100,0};

    Interface_SetMatrixChipChannelPwm(adr[chn], pwm);

    /*  Interface_SetChannelPWM((E_ChannelID)chn, 100); */
    Interface_SetChannelCurrent((E_ChannelID)chn, 100);
    Interface_SetChannelPWM((E_ChannelID)chn, 100); 
    
    Interface_SetChannelSwitchState((E_ChannelID)chn, CHANNEL_STATE_ON);
    return;
#endif

#if 0   /* 测试提供的接口 */
    LampM_SetLampChn((Light_Functions)6, 0xFFFF, 100, 0, 0);
    LampM_SetLampPix((Light_Functions)6, 1, 100, 0, 0);
    /*  LampM_SetLampPix((Light_Functions)6, 24, 100, 0, 0);
    LampM_SetLampPix((Light_Functions)6, 23, 100, 0, 0);
    LampM_SetLampPix((Light_Functions)6, 29, 100, 0, 0);
    LampM_SetLampPix((Light_Functions)6, 28, 100, 0, 0);
    LampM_SetLampPix((Light_Functions)6, 27, 100, 0, 0); */
#endif

#if (BUILD_PROJECT_ID == 1)
#if (QINGHAIGANG) && (QHG_DMONI_orXCP)
    EPTest();   /* EMC测试设置 */
#endif  /* (QINGHAIGANG) && (QHG_DMONI_orXCP) */
#endif  /* (BUILD_PROJECT_ID == 1) */

    /* 本周周期变化电流清零 */
    lampctl.CChg = 0;
    /* 上限值清零 */
    if (lampctl.maxUp == 0) { lampctl.maxchg = 500; }
    /* 标志清零 */
    lampctl.maxUp = 0;

    /* 更新通道和矩阵的PWM值到芯片 */
    ChnPercentSet(ms);
    /* 通道电流设置，不作用到通道 */
    ChnCurrentSet();

#if (BUILD_PROJECT_ID == 1)
#if (QINGHAIGANG) && (QHG_DMONI_orXCP)
    EPTest_IoCtr2F();   /* EMC测试设置 */
#endif  /* (QINGHAIGANG) && (QHG_DMONI_orXCP) */
#endif  /* (BUILD_PROJECT_ID == 1) */

    /* 通道使能设置 */
    ChnMtxWorkingSet(ms);
}


int lampM_GetLampInfo(Light_Functions lgt, S_LF_Info_T * info)
{
    if ((lgt >= E_LightFunc_Num) || 
        (info == 0))
    { return -1; }

    info->being = lightinfo[lgt].being;
    info->lednum = lightinfo[lgt].lednum;
    info->chnMask = lightinfo[lgt].chnMask;
    info->mtxMask = lightinfo[lgt].mtxMask;
    info->ledlamp = lightinfo[lgt].ledlamp;

    return 0;
}


int lampM_GetLampChnPixId(Light_Functions lgt, uint16_t mask, uint8_t *id)
{
    int i, j;
    uint16_t mk;

    if ((lgt >= E_LightFunc_Num) ||
        (mask == 0) ||
        id == 0)
    { return -1; }

    if ((lightinfo[lgt].being == 1)&&
        (lightinfo[lgt].ledlamp > 0))
    {
        mk = lightinfo[lgt].mtxMask & mask;
        if (mk != 0)
        {
            for (i=0; i<MAX_CHANNLE_NUM; i++)
            {
                if ((mk & (0x0001<<i)) != 0)
                {
                    if (idMtx[i] != 0)
                    {
                        for (j=0; j<MAX_MATRIXCHIP_CHANNEL_NUM; j++)
                        { id[j] = idMtx[i][j]; }

                        break;  /* 仅找1个 */
                    }
                }
            }
        }
    }

    return 0;
}


/**
 * @brief 
 * 
 */
int LampM_SetLampChn(Light_Functions lgt, uint16_t mask, 
                     uint8_t perc, uint16_t ton, uint16_t toff)
{
    int i;
    uint16_t chnMask;

    /* */
    if ((lgt >= E_LightFunc_Num) ||
        (mask == 0x0000))
    { return -1; }

    /* */
    if (perc > 100) { perc = 100; }

    chnMask = GetChannelMaskByLightFunction(lgt);
    chnMask &= mask;
    for(i=0; i<16; i++)
    {
        if ((chnMask & (0x0001 << i)) != 0)
        {
            lampctl.aimChn[i].perc = perc;
            lampctl.aimChn[i].ton = ton;
            lampctl.aimChn[i].toff = toff;
        }
    }

    return 0;
}

int LampM_SetLampPix(Light_Functions lgt, uint8_t pixid, 
                     uint8_t perc, uint16_t ton, uint16_t toff)
{
    int set, idx;

    const uint8_t *p;
    int chn/*  , addr */;

    /* */
    if (lgt >= E_LMM_Supply)
    { return -1; }
    if (pixid < 1)
    { return -1; }
    else
    { pixid -= 1; }

    /* */
    if (perc > 100) { perc = 100; }

    if ((lightinfo[lgt].being) && 
        (lightinfo[lgt].ledlamp > 0))
    {
        switch(lgt)
        {
        case E_LowBeamFlat:
        case E_LowBeamKink:
        case E_HighBeamSail:
        case E_HighBeamSpot:
            if (pixid >= lampctl.sg[MtxSet_LBHB].num) { return -1; }
            pixid += lampctl.sg[MtxSet_LBHB].start; /* 取得像素索引 */
            set = lampctl.pix[pixid].set;   /* 取得像素索引对应的矩阵集合序号 */
            p = Get_LB_HB_MatrixInfo(set);          /* 取得矩阵集合中的行 */
            break;
        case E_TurnIndicator:
            if (pixid >= lampctl.sg[MtxSet_TI].num) { return -1; }
            pixid += lampctl.sg[MtxSet_TI].start;
            set = lampctl.pix[pixid].set;
            p = Get_TI_MatrixInfo(set);
            break;
        case E_DaytimeRunningLight:
        case E_PositionLight:
            if (pixid >= lampctl.sg[MtxSet_DRLPOS].num) { return -1; }
            pixid += lampctl.sg[MtxSet_DRLPOS].start;
            set = lampctl.pix[pixid].set;
            p = Get_DRL_POS_MatrixInfo(set);
            break;
        case E_GrilleLamp:
            if (pixid >= lampctl.sg[MtxSet_GRIL].num) { return -1; }
            pixid += lampctl.sg[MtxSet_GRIL].start;
            set = lampctl.pix[pixid].set;
            p = Get_Grille_MatrixInfo(set);
            break;
        case E_LogoLamp:
            if (pixid >= lampctl.sg[MtxSet_LOGO].num) { return -1; }
            pixid += lampctl.sg[MtxSet_LOGO].start;
            set = lampctl.pix[pixid].set;
            p = Get_Logo_MatrixInfo(set);
            break;
        case E_AssistantLight:
            if (pixid >= lampctl.sg[MtxSet_ASSI].num) { return -1; }
            pixid += lampctl.sg[MtxSet_ASSI].start;
            set = lampctl.pix[pixid].set;
            p = Get_Assistant_MatrixInfo(set);
            break;
        case E_FrontCrossLamp:
            if (pixid >= lampctl.sg[MtxSet_CROSS].num) { return -1; }
            pixid += lampctl.sg[MtxSet_CROSS].start;
            set = lampctl.pix[pixid].set;
            p = Get_FrontCross_MatrixInfo(set);
            break;
        /* case E_CorneringLight:
        case E_FogLamp:
        case E_SideMarkerLamp:
            break; */
        default:
            return -1;
        };

        idx = lampctl.pix[pixid].idx;   /* 取得像素索引对应的矩阵集合行中的像素序号 */

        chn  = p[2] - 1;    /* 矩阵对应的通道序号 */
        /* addr = p[1]; */        /* 矩阵地址 */

        if (((lightinfo[lgt].chnMask) & (0x0001 << chn)) != 0)
        {
            /* lampctl.aimMtx[chn].addr = addr; */
            lampctl.aimMtx[chn].perc[idx] = perc;
            lampctl.aimMtx[chn].ton[idx] = ton;
            lampctl.aimMtx[chn].toff[idx] = toff;
        }
    }

    return 0;
}

int LampM_GetLampBaseErr(S_LF_Err_T *err)
{
    /* input check */
    if (err == 0) { return -1; }

    C_Memcpy_B(err, &(lampctl.erruse), sizeof(S_LF_Err_T));
    err->chnErr |= lampctl.chnMaskLB_UV;

    /* 通道故障延时30ms上报 */
    {
    for (int i=0; i<MAX_CHANNLE_NUM; i++)
    {
        if (lampctl.chnErrDelay[i] <= 30)
        { err->chnErr &= ~(0x0001<<i); }
    }
    }
    

    return 0;
}

int LampM_GetLampBaseErr_DTC(S_LF_Err_T *err)
{
    /* input check */
    if (err == 0) { return -1; }

    C_Memcpy_B(err, &(lampctl.erruseDTC), sizeof(S_LF_Err_T));
    err->chnErr |= lampctl.chnMaskLB_UV_DTC;

    return 0;
}

void LampM_Specal_LB(uint8_t spe)
{
    if (spe == 0)
    { lampctl.b_disUV_LB = 0; }
    else
    { lampctl.b_disUV_LB = 1; }
}

void LampM_Specal_TI(uint8_t spe)
{
    if (spe == 0)
    { lampctl.chnTIuseing = 0; }
    else
    { lampctl.chnTIuseing = 1; }
}