/**
 * @file LB.c
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
#include "ComSignal_Interface.h"
/* Lighting Base */
#include "LampManager.h"
#include "Lighting.h"

#include "LogoLamp.h"
#include "Fan.h"
#include "LB.h"


typedef struct _LBCtl_
{
    S_LF_Info_T     pr_infoLBflat;    /* LBflat灯光 灯配置信息 */
    S_LF_Info_T     pr_infoLBkink;    /* LBkink灯光 灯配置信息 */

    uint8_t         pr_PixMode          :2; /* LB/HB共用LED模式 "Light Control":"pPxlModuleType" */
    /* 法规相关 */
    uint8_t         pr_SAE0_ECE1        :1; /* 0:SAE规范; 1:ECE规范 */

    uint8_t         pr_LogoLBPOS        :2; /* logo灯作为LB/POS的一部分标识 "Light Control":"pLogoLowbeamPOS" */
    uint8_t         pr_res_b8           :3; /* 保留 */
    
    uint16_t        pr_onRampLBflat;
    uint16_t        pr_onRampLBkink;
    uint16_t        pr_offRampLBflat;
    uint16_t        pr_offRampLBkink;

    /* 功能安全相关 */
    uint8_t         st_usagemode;       /* 车辆模式 */
    uint32_t        st_speed;           /* 车速 m/h */

    uint8_t         st_actLB    :1;     /* 0:act; 1:un-act */
    uint8_t         st_enaLB    :1;     /* 0:disable; 1:enable */
    uint8_t         st_turnLB   :1;     /* 0:turn off; 1:turn on */
    uint8_t         st_res_b8   :5;

    uint8_t         st_res_B4;

    /*  */
    S_LF_Err_T      st_err;     /* 动作故障(实时) */
    S_LF_Err_T      st_errDTC;  /* 动作故障(已报DTC) */

}S_LBCtl_t;

static       S_LBCtl_t  lbctl, *_ctl = 0;
static const uint8_t   *pr_pixLB;     /* 配置的LB各像素PWM */


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



static void act_on_LBflat()
{
    Light_Functions func = E_LowBeamFlat;
    uint16_t        chnM = lbctl.pr_infoLBflat.chnMask;
    uint8_t         perc = 100;
    uint16_t        ton  = lbctl.pr_onRampLBflat;
    uint16_t        toff = lbctl.pr_offRampLBflat;

    /*  */
    LampM_SetLampChn(func, chnM, perc, ton, toff);  /* 无矩阵通道 */

}
static void act_on_LBkink()
{
    Light_Functions func = E_LowBeamKink;
    uint16_t        chnM = lbctl.pr_infoLBkink.chnMask;
    uint16_t        mtxM = lbctl.pr_infoLBkink.mtxMask;
    uint8_t         perc = 100;
    uint16_t        ton  = lbctl.pr_onRampLBkink;
    uint16_t        toff = lbctl.pr_offRampLBkink;

    _act_SetPix(func, chnM, mtxM, perc, ton, toff, 1, pr_pixLB);  

}


static void act_off_LBflat()
{
    Light_Functions func = E_LowBeamFlat;
    uint16_t        chnM = lbctl.pr_infoLBflat.chnMask;
    uint8_t         perc = 0;
    uint16_t        ton  = lbctl.pr_onRampLBflat;
    uint16_t        toff = lbctl.pr_offRampLBflat;

    /*  */
    LampM_SetLampChn(func, chnM, perc, ton, toff);  /* 无矩阵通道 */

}
static void act_off_LBkink()
{
    Light_Functions func = E_LowBeamKink;
    uint16_t        chnM = lbctl.pr_infoLBkink.chnMask;
    uint16_t        mtxM = lbctl.pr_infoLBkink.mtxMask;
    uint8_t         perc = 0;
    uint16_t        ton  = lbctl.pr_onRampLBkink;
    uint16_t        toff = lbctl.pr_offRampLBkink;

    /*  */
    _act_SetPix(func, chnM, mtxM, perc, ton, toff, 0, pr_pixLB);
}


static void lamp_check(void)
{
    
}


void LB_Init(void)
{
    /*  */
    C_Memset_B((uint8_t*)(&(lbctl)), 0, sizeof(S_LBCtl_t));
    
    lampM_GetLampInfo(E_LowBeamFlat,  &(lbctl.pr_infoLBflat));
    lampM_GetLampInfo(E_LowBeamKink,  &(lbctl.pr_infoLBkink));

    lbctl.pr_PixMode = 1;
    lbctl.pr_SAE0_ECE1 = 0;

    lbctl.pr_LogoLBPOS = Get_pLogoLowbeamPOS();

    lbctl.pr_onRampLBflat = Get_pLedOnRampTi(E_LowBeamFlat);
    lbctl.pr_onRampLBkink = Get_pLedOnRampTi(E_LowBeamKink);
    lbctl.pr_offRampLBflat = Get_pLedOffRampTi(E_LowBeamFlat);
    lbctl.pr_offRampLBkink = Get_pLedOffRampTi(E_LowBeamKink);

    _ctl = &lbctl;
    pr_pixLB = Get_pLowBeamPWMPixel_head();
}

void LB_Exit(void)
{
    _ctl = 0;
}

void LB_Run_(uint16_t ms)
{
    E_UseMode_t vehmode;
    uint16_t    vehspd;

    S_LgtFuncEna_t ena;
    S_LgtActIns_t  act;

    if (_ctl == 0) { return; }

    /* 获取 */
    GetLgtFuncEna(&ena);
    GetLgtActIns (&act);
    _ctl->st_actLB = act.ActLB;
    _ctl->st_enaLB = ena.EnaLB;
    LampM_GetLampBaseErr(&(_ctl->st_err));
    LampM_GetLampBaseErr_DTC(&(_ctl->st_errDTC));

    /* 获取车辆模式和车速 */
    vehmode = Get_VehMode();
    lbctl.st_usagemode = vehmode;
    vehspd  = Get_VehSpd();
    lbctl.st_speed = C_VehSpd_00m1s_m1h(vehspd);

#if (DEBUG_LIGHTING_LB)
    _ctl->st_actLB = ACT_ON;
#endif

    /* Turn On/Off */
    
    if ((_ctl->st_actLB == ACT_ON) && 
        (_ctl->st_enaLB == ENA_ON))
    { _ctl->st_turnLB = 1; }
    else
    { _ctl->st_turnLB = 0; }

    /* Turn Off */
    if (_ctl->st_turnLB == 0)
    {
        if (lbctl.pr_infoLBflat.being)
        { act_off_LBflat(); }
        
        if (lbctl.pr_infoLBkink.being)
        { act_off_LBkink(); }

        SetLgtStsFb_LB(STS_OFF);

        /* CTS-6.4.4 */
        /* if (_ctl->st_actLB == ACT_ON)
        { SetLgtStsFb_LB(STS_ERR); } */
    }
}

void LB_Run_On(void)
{
    if (_ctl == 0) { return; }

    /* Trun On */
    if (_ctl->st_turnLB)
    {
        if (lbctl.pr_infoLBflat.being)
        {
            act_on_LBflat();
        }

        if (lbctl.pr_infoLBkink.being)
        {
            act_on_LBkink();
        }

        if (((_ctl->st_err.chnErr & lbctl.pr_infoLBflat.chnMask) == 0) &&
            ((_ctl->st_err.mtxErr & lbctl.pr_infoLBflat.mtxMask) == 0) &&
            ((_ctl->st_err.chnErr & lbctl.pr_infoLBkink.chnMask) == 0) &&
            ((_ctl->st_err.mtxErr & lbctl.pr_infoLBkink.mtxMask) == 0))
        {
            SetLgtStsFb_LB(STS_ON);
        }
        else
        {
            if (FEEDERR_LATE) { SetLgtStsFb_LB(STS_ON);  }
            else              { SetLgtStsFb_LB(STS_ERR); }

            /* 故障 关 */
            if (((_ctl->st_errDTC.chnErr & lbctl.pr_infoLBflat.chnMask) != 0) ||
                ((_ctl->st_errDTC.mtxErr & lbctl.pr_infoLBflat.mtxMask) != 0) ||
                ((_ctl->st_errDTC.chnErr & lbctl.pr_infoLBkink.chnMask) != 0) ||
                ((_ctl->st_errDTC.mtxErr & lbctl.pr_infoLBkink.mtxMask) != 0))
            {
                if (FEEDERR_LATE) { SetLgtStsFb_LB(STS_ERR); }

                /* 361638v4, 269076v2 */
                if (lbctl.pr_SAE0_ECE1 == 0)
                {
                    if ((lbctl.st_usagemode < 0x08) && (lbctl.st_speed < 3000))   /* usagemode==非活动 && speed < 3km/h */
                    { SetLgtOnDis_LB(); }
                }
            }
        }

        /* NTC故障，反馈ERROR */
        if (((_ctl->st_errDTC.ntcErr & lbctl.pr_infoLBflat.chnMask) != 0) ||
            ((_ctl->st_errDTC.ntcErr & lbctl.pr_infoLBkink.chnMask) != 0))
        {
            SetLgtStsFb_LB(STS_ERR);
        }

        /* LOGO灯故障，反馈ERROR */
        if (_ctl->pr_LogoLBPOS == 1)
        {
            if (LogoLamp_GetLogoLampErrorState())
            { SetLgtStsFb_LB(STS_ERR); }
        }

        /* FAN故障，反馈ERROR */
        if (Fan_GetFanFaultSignal())
        { SetLgtStsFb_LB(STS_ERR); }
    }
}

