/**
 * @file HB.c
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

/* ASW Interface */
#include "HcmPlatform.h"
#include "GeneralFunction.h"
#include "Parameter_Interface.h"
#include "MatrixChip_Interface.h"
/* Lighting Base */
#include "LampManager.h"
#include "Lighting.h"

#include "HB.h"


typedef struct _HBCtl_
{
    S_LF_Info_T     pr_infoHBsail;    /* HBsail灯光 灯配置信息 */
    S_LF_Info_T     pr_infoHBspot;    /* HBspot灯光 灯配置信息 */

    uint8_t         pr_PixMode          :2; /* LB/HB共用LED模式 "Light Control":"pPxlModuleType" */
    /* 法规相关 */
    uint8_t         pr_SAE0_ECE1        :1; /* 0:SAE规范; 1:ECE规范 */
    /* N-1 */
    uint8_t         pr_N_1              :1; /* 0:能亮则亮; 1:1灭全灭 */

    uint16_t        pr_onRampHBsail;
    uint16_t        pr_onRampHBspot;
    uint16_t        pr_offRampHBsail;
    uint16_t        pr_offRampHBspot;

    /*  */
    S_LF_Err_T      st_err;     /* 动作故障 */
    S_LF_Err_T      st_errDTC;  /* 动作故障(已报DTC) */

    uint8_t         st_actHB    :1;     /* 0:act; 1:un-act */
    uint8_t         st_enaHB    :1;     /* 0:disable; 1:enable */
    uint8_t         st_turnHB   :1;     /* 0:turn off; 1:turn on */
}S_HBCtl_t;

static       S_HBCtl_t      hbctl;
static       S_HBCtl_t     *_ctl = 0;
static const uint8_t       *_pixHB;     /* 配置的HB各像素PWM */


static void _act_SetPix(Light_Functions func, 
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
                        idx = id-1;
                        if (pixPerc[idx] > 0)
                        {
                            if (onoff0 != 0) { perc1 = pixPerc[idx]; }
                            else             { perc1 = 0; }
                            
                            LampM_SetLampPix(func, id, perc1, ton, toff);
                        }

                    }
                }
            }
        }
    }
}



static void act_on_HBsail()
{
    Light_Functions func = E_HighBeamSail;
    uint16_t        chnM = hbctl.pr_infoHBsail.chnMask;
    uint16_t        mtxM = hbctl.pr_infoHBsail.mtxMask;
    uint8_t         perc = 100;
    uint16_t        ton  = hbctl.pr_onRampHBsail;
    uint16_t        toff = hbctl.pr_offRampHBsail;

    /*  */
    _act_SetPix(func, chnM, mtxM, perc, ton, toff, 1, _pixHB);
}
static void act_on_HBspot()
{
    Light_Functions func = E_HighBeamSpot;
    uint16_t        chnM = hbctl.pr_infoHBspot.chnMask;
    uint16_t        mtxM = hbctl.pr_infoHBspot.mtxMask;
    uint8_t         perc = 100;
    uint16_t        ton  = hbctl.pr_onRampHBspot;
    uint16_t        toff = hbctl.pr_offRampHBspot;

    /*  */
    _act_SetPix(func, chnM, mtxM, perc, ton, toff, 1, _pixHB);
}

static void act_off_HBsail()
{
    Light_Functions func = E_HighBeamSail;
    uint16_t        chnM = hbctl.pr_infoHBsail.chnMask;
    uint16_t        mtxM = hbctl.pr_infoHBsail.mtxMask;
    uint8_t         perc = 0;
    uint16_t        ton  = hbctl.pr_onRampHBsail;
    uint16_t        toff = hbctl.pr_offRampHBsail;

    /*  */
    _act_SetPix(func, chnM, mtxM, perc, ton, toff, 0, _pixHB);
    
}

static void act_off_HBspot()
{
    Light_Functions func = E_HighBeamSpot;
    uint16_t        chnM = hbctl.pr_infoHBspot.chnMask;
    uint16_t        mtxM = hbctl.pr_infoHBspot.mtxMask;
    uint8_t         perc = 0;
    uint16_t        ton  = hbctl.pr_onRampHBspot;
    uint16_t        toff = hbctl.pr_offRampHBspot;

    /*  */
    _act_SetPix(func, chnM, mtxM, perc, ton, toff, 0, _pixHB);
}


void HB_Init(void)
{
    uint16_t u16v;

    /*  */
    C_Memset_B((uint8_t*)(&(hbctl)), 0, sizeof(S_HBCtl_t));

    lampM_GetLampInfo(E_HighBeamSail, &(hbctl.pr_infoHBsail));
    lampM_GetLampInfo(E_HighBeamSpot, &(hbctl.pr_infoHBspot));

    hbctl.pr_PixMode = 1;
    hbctl.pr_SAE0_ECE1 = 0;

    /* N-1 */
    u16v = Get_LightN_1();
    if ((u16v & 0x0004) != 0) { hbctl.pr_N_1 = 1; }

    hbctl.pr_onRampHBsail = Get_pLedOnRampTi(E_HighBeamSail);
    hbctl.pr_onRampHBspot = Get_pLedOnRampTi(E_HighBeamSpot);
    hbctl.pr_offRampHBsail = Get_pLedOffRampTi(E_HighBeamSail);
    hbctl.pr_offRampHBspot = Get_pLedOffRampTi(E_HighBeamSpot);

    _pixHB = Get_pHighBeamPWMPixel_B_head();

    _ctl = &hbctl;
}

void HB_Exit(void)
{
    _ctl = 0;
}

void HB_Run_(uint16_t ms)
{
    S_LgtFuncEna_t ena;
    S_LgtActIns_t  act;

    if (_ctl == 0) { return; }

    /* 获取 */
    GetLgtFuncEna(&ena);
    GetLgtActIns (&act);
    _ctl->st_actHB = act.ActHB;
    _ctl->st_enaHB = ena.EnaHB;
    LampM_GetLampBaseErr(&(_ctl->st_err));
    LampM_GetLampBaseErr_DTC(&(_ctl->st_errDTC));
    
#if (DEBUG_LIGHTING_HB)
    _ctl->st_actHB = ACT_ON;
#endif

    /* Turn On/Off */
    if ((_ctl->st_actHB == ACT_ON) && 
        (_ctl->st_enaHB == ENA_ON))
    { _ctl->st_turnHB = 1; }
    else
    { _ctl->st_turnHB = 0; }

    /* Turn Off */
    if (_ctl->st_turnHB == 0)
    {
        if (hbctl.pr_infoHBsail.being)
        {
            act_off_HBsail();
        }
        if (hbctl.pr_infoHBspot.being)
        {
            act_off_HBspot();
        }

        SetLgtStsFb_HB(STS_OFF);

        /* CTS-6.4.4 */
        /* if (_ctl->st_actHB == ACT_ON)
        { SetLgtStsFb_HB(STS_ERR); } */
    }
}

void HB_Run_On(void)
{
    if (_ctl == 0) return;

    /* Turn On */
    if (_ctl->st_turnHB)
    {
        if (hbctl.pr_infoHBsail.being)
        {
            act_on_HBsail();
        }
        if (hbctl.pr_infoHBspot.being)
        {
            act_on_HBspot();
        }

        if (((_ctl->st_err.chnErr & hbctl.pr_infoHBsail.chnMask) == 0) &&
            ((_ctl->st_err.mtxErr & hbctl.pr_infoHBsail.mtxMask) == 0) &&
            ((_ctl->st_err.chnErr & hbctl.pr_infoHBspot.chnMask) == 0) &&
            ((_ctl->st_err.mtxErr & hbctl.pr_infoHBspot.mtxMask) == 0))
        {
            SetLgtStsFb_HB(STS_ON);
        }
        else
        {
            if (FEEDERR_LATE) { SetLgtStsFb_HB(STS_ON);  }
            else              { SetLgtStsFb_HB(STS_ERR); }

            /* 故障 关 */
            if (((_ctl->st_errDTC.chnErr & hbctl.pr_infoHBsail.chnMask) != 0) ||
                ((_ctl->st_errDTC.mtxErr & hbctl.pr_infoHBsail.mtxMask) != 0) ||
                ((_ctl->st_errDTC.chnErr & hbctl.pr_infoHBspot.chnMask) != 0) ||
                ((_ctl->st_errDTC.mtxErr & hbctl.pr_infoHBspot.mtxMask) != 0))
            {
                if (FEEDERR_LATE) { SetLgtStsFb_HB(STS_ERR); } 
                if (_ctl->pr_N_1) { SetLgtOnDis_HB(); }
            }
        }

        /* NTC故障，反馈ERROR */
        if (((_ctl->st_errDTC.ntcErr & hbctl.pr_infoHBsail.chnMask) != 0) ||
            ((_ctl->st_errDTC.ntcErr & hbctl.pr_infoHBspot.chnMask) != 0))
        {
            SetLgtStsFb_HB(STS_ERR);
        }

    }
}

