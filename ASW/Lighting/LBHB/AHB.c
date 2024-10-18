

/* Base Include */
#include "HcmPlatform.h"
#include "GeneralFunction.h"
#include "Parameter_Interface.h"
#include "ComSignal_Interface.h"
#include "MatrixChip_Interface.h"

/* Lighting Include */
#include "LampManager.h"
#include "Lighting.h"

#include "AHB.h"


typedef struct _AHBCtl_
{
    S_LF_Info_T pr_infoHBsail;    /* HBsail灯光 灯配置信息 */
    S_LF_Info_T pr_infoHBspot;    /* HBspot灯光 灯配置信息 */

    uint8_t     pr_EnaAHB           :1;

    /* N-1 */
    uint8_t     pr_N_1              :1; /* 0:能亮则亮; 1:1灭全灭 */

    uint8_t     pr_NoOfpixels;              /* PIX数量(N.A.), "DBLLvlAHB":"pNoOfpixels" */

    uint16_t    pr_AHBCDistOfHB;            /* AHB远光距离,0.01m, "DBLLvlAHB":"pAHBCDistOfHiBeam" */
    
    S_LF_Err_T  st_err;     /* 动作故障 */
    S_LF_Err_T  st_errDTC;  /* 动作故障(已报DTC) */
    
    /* AHB On1/Off0 */
    uint8_t     st_turnOn1_AHB  :1;
    uint8_t     st_turnOn1_HB   :1;

}S_ahbctl_t;

static       S_ahbctl_t     ahbctl;     /* 初始化时使用 */
static       S_ahbctl_t    *_ctl;       /* 初始化后使用 */
static const uint8_t       *_pixHB;     /* 配置的HB各像素PWM */


static 
void _act_use_PixPerc(Light_Functions func, 
                             uint16_t        chnM,
                             uint16_t        mtxM,
                             uint8_t         perc,
                             uint16_t        ton,
                             uint16_t        toff,
                             uint8_t         onoff0,     /* not 0:On; 0:Off */
                             const uint8_t  *pixPerc)
{
    int i, j;
    uint16_t mask = (chnM & (~mtxM));
    uint8_t pid[MAX_MATRIXCHIP_CHANNEL_NUM];
    uint8_t id, idx, perc1;

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
                    {
                        perc1 = perc;

                        if (onoff0 != 0)    /* if On */
                        {
                            idx = id-1;
                            if (pixPerc[idx] > 0) { perc1 = pixPerc[idx]; }
                        }

                        LampM_SetLampPix(func, id, perc1, ton, toff);
                    }
                }
            }
        }
    }
}


static void act_on_HBsail()
{
    Light_Functions func = E_HighBeamSail;
    uint16_t        chnM = ahbctl.pr_infoHBsail.chnMask;
    uint16_t        mtxM = ahbctl.pr_infoHBsail.mtxMask;
    uint8_t         perc = 100;
    uint16_t        ton  = 0;
    uint16_t        toff = 0;

    /*  */
    _act_use_PixPerc(func, chnM, mtxM, perc, ton, toff, 1, _pixHB);
}
static void act_on_HBspot()
{
    Light_Functions func = E_HighBeamSpot;
    uint16_t        chnM = ahbctl.pr_infoHBspot.chnMask;
    uint16_t        mtxM = ahbctl.pr_infoHBspot.mtxMask;
    uint8_t         perc = 100;
    uint16_t        ton  = 0;
    uint16_t        toff = 0;

    /*  */
    _act_use_PixPerc(func, chnM, mtxM, perc, ton, toff, 1, _pixHB);
}



void AHB_Init(void)
{
    uint8_t u8v;
    uint16_t u16v;

    C_Memset_B((uint8_t*)(&ahbctl), 0, sizeof(S_ahbctl_t));

    lampM_GetLampInfo(E_HighBeamSail, &(ahbctl.pr_infoHBsail));
    lampM_GetLampInfo(E_HighBeamSpot, &(ahbctl.pr_infoHBspot));

    ahbctl.pr_EnaAHB = 1;

    /* N-1 */
    u16v = Get_LightN_1();
    if ((u16v & 0x0004) != 0) { ahbctl.pr_N_1 = 1; }

    /* 水平电机配置信息, "DBLLvlAHB":"pVehLvlType" */
    /* u8v = Get_pVehLvLType(); if (u8v != 2) { ahbctl.pr_EnaAHB = 0; } */
    /* AHB类型, "DBLLvlAHB":"pAHBCTyp" */
    u8v = Get_pAHBCType();   if (u8v != 1) { ahbctl.pr_EnaAHB = 0; }

    ahbctl.pr_AHBCDistOfHB = Get_pAHBCDistOfHiBeam();

    _pixHB = Get_pHighBeamPWMPixel_B_head();

    _ctl = &ahbctl;
}

void AHB_Exit(void)
{
    _ctl = 0;
}

void AHB_Run_On(void)
{
    S_LgtFuncEna_t  ena;
    S_LgtActIns_t   act;
    S_AHBCObj_t     obj;

    if (_ctl == 0) return;
    if (_ctl->pr_EnaAHB == 0) return;

    GetLgtFuncEna(&ena);
    GetLgtActIns (&act);
    LampM_GetLampBaseErr(&_ctl->st_err);
    LampM_GetLampBaseErr_DTC(&_ctl->st_errDTC);

    Get_AHBCObj(&obj);

    /* 辅助信号故障处理 */
    if (obj.e_Classn || obj.e_Dist)
    { ena.EnaAHBC = ENA_OFF; }

#if (DEBUG_LIGHTING_AHB)

#endif

    /* AHB Turn On? */
    if ((ena.EnaAHBC == ENA_ON) &&
        ((act.ActHB == ENA_OFF) && (act.ActAHBC == ACT_ON)) &&
        (obj.CamSts == 1) &&
        (obj.TooMany == 0) &&
        (obj.LitArea == 0))
    { _ctl->st_turnOn1_AHB = 1; }
    else
    { _ctl->st_turnOn1_AHB = 0; }

    /* HB Turn On? */
    _ctl->st_turnOn1_HB = 0;
    if      (obj.Classn == 0)                  { _ctl->st_turnOn1_HB = 1; }
    else if (obj.Dist > _ctl->pr_AHBCDistOfHB) { _ctl->st_turnOn1_HB = 1; }

    /* Turn On */
    if (_ctl->st_turnOn1_AHB)
    {
        SetLgtStsFb_AHBC(STS_ON);

        if (_ctl->st_turnOn1_HB)
        {
            if (_ctl->pr_infoHBsail.being)
            {
                act_on_HBsail();
            }
            if (_ctl->pr_infoHBspot.being)
            {
                act_on_HBspot();
            }

            SetLgtStsFb_HB(STS_ON);

            /* HB Channel Error */
            if (((_ctl->st_err.chnErr & _ctl->pr_infoHBsail.chnMask) != 0) ||
                ((_ctl->st_err.mtxErr & _ctl->pr_infoHBsail.mtxMask) != 0) ||
                ((_ctl->st_err.chnErr & _ctl->pr_infoHBspot.chnMask) != 0) ||
                ((_ctl->st_err.mtxErr & _ctl->pr_infoHBspot.mtxMask) != 0))
            {
                SetLgtStsFb_HB(STS_ERR);
                SetLgtStsFb_AHBC(STS_ERR);

                if (_ctl->pr_N_1) { ; }
            }

            /* HB NTC Error */
            if (((_ctl->st_errDTC.ntcErr & _ctl->pr_infoHBsail.chnMask) != 0) ||
                ((_ctl->st_errDTC.ntcErr & _ctl->pr_infoHBspot.chnMask) != 0))
            {
                SetLgtStsFb_HB(STS_ERR);
                SetLgtStsFb_AHBC(STS_ERR);
            }
        }
        else
        {
            SetLgtStsFb_HB(STS_OFF);
        }
    }
    else
    {
        SetLgtStsFb_AHBC(STS_OFF);

        /* 辅助信号故障，反馈ERROR */
        if (obj.e_Classn || obj.e_OnCmng || obj.e_Dist) 
        { SetLgtStsFb_AHBC(STS_ERR); }

        /* CamSts信号处理 */
        if ((ena.EnaAHBC == ENA_ON) &&
            ((act.ActHB == ENA_OFF) && (act.ActAHBC == ACT_ON)) &&
            ((obj.CamSts != 1) && (obj.CamSts != 3)))
        { SetLgtStsFb_AHBC(STS_ERR); }
    }

}

