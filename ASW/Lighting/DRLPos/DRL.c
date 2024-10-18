


/* ASW Interface */
#include "HcmPlatform.h"
#include "GeneralFunction.h"
#include "Parameter_Interface.h"
#include "MatrixChip_Interface.h"
#include "ComSignal_Interface.h"
/* Lighting Base */
#include "Lighting.h"
#include "LampManager.h"

#include "DRL.h"



typedef struct _DRLCtl_
{
    uint8_t     pr_DRLPOStype;      /* 0:共用通道；1:独立通道；2:部分共用通道 */

    S_LF_Info_T pr_DRLinfo;         /* DRL灯光配置信息 */

    uint16_t    pr_onRamp_DRL;
    uint16_t    pr_offRamp_DRL;

    uint8_t     pr_percDRLTI;       /* 共用时，亮度百分比 */
    uint8_t     pr_percDRLTI40mm;   /* 40mm时，亮度百分比 */
    uint16_t    pr_uptimeDRLTI;     /* 共用效果 延时时间 */


    uint16_t    pr_chnMask_PosDRL;  /* POS与DRL通道共用 通道标识 */
    uint16_t    pr_nearMask_DRLTI;  /* DRL与TI发光面靠近 通道标识 */
    uint16_t    pr_appaMask_DRLTI;  /* DRL与TI发光面共用 通道标识 */

    uint8_t     pr_LegalRequ;    /* 0:ECE, 1:SAE; 2:Reserve */

    /* N-1 */
    uint8_t     pr_N_1          :1; /* 0:能亮则亮; 1:1灭全灭 */

    uint8_t     st_bDRLTI   :1;     /* DRLTI共用效果存在标识 */
    uint16_t    st_msTIOFF;         /* TI关计时 */
    

    uint16_t    st_DRLms;   /* AOL_DRL状态的时间ms，单向增加 */


    uint8_t     st_DRLperc; /* DRL当前占空比 */

    S_LF_Err_T  st_err;
    S_LF_Err_T  st_errDTC;

    uint8_t     st_actDRL   :1;     /* 0:act; 1:un-act */
    uint8_t     st_actTI    :1;
    uint8_t     st_stsTI    :1;
    uint8_t     st_enaDRL   :1;     /* 0:disable; 1:enable */
    uint8_t     st_turnDRL  :1;     /* 0:turn off; 1:turn on */
    uint8_t     st_DRLstsTI :1;     /* DRL-TI共用效果延时用，命令保持 */
    

}S_DRLCtl_t;

static S_DRLCtl_t drlctl, *_ctl = 0;


typedef struct _AFSDRL_Ctl_
{
    uint16_t    pr_AFSDRLPWM;           /* AFS时的DRL亮度百分比，单位：0.1% */

    uint8_t     pr_AFSLightDRL  :1;     /* 配置 AFS时 点亮DRL */

    uint8_t     st_actAFS       :1;     /*  */
    uint8_t     st_enaAFS       :1;     /*  */
    uint8_t     st_actHB        :1;
    uint8_t     st_actAHBC      :1;
}S_AFSDRLCtl_t;
static S_AFSDRLCtl_t afsdrlctl, *_ctl1 = 0;


static void _act_SetPix(Light_Functions func, 
                        uint16_t        chnM,
                        uint16_t        mtxM,
                        uint8_t         perc,
                        uint16_t        ton,
                        uint16_t        toff,
                        uint8_t         TIstsOn1,   /* 0:TIsts Off; 1:TIsts On */
                        uint8_t         TIactOn1    /* 0:TIact Off; 1:TIact On */
                        )
{
    int i, j;
    uint16_t mask = (chnM & (~mtxM));               /* 无矩阵通道 */
    uint8_t pid[MAX_MATRIXCHIP_CHANNEL_NUM];
    uint8_t id, idx, perc1;
    uint16_t mask1;
    uint8_t percAll[MAX_CHANNLE_NUM];    /* 预设全部通道的百分比 */

    /* 获取 全部通道需要设置的 工作百分比 */

    for (i=0; i<MAX_CHANNLE_NUM; i++)
    { percAll[i] = perc; }


    _ctl->st_bDRLTI = 0;    /* DRLTI共用标识清零 */
    if (TIstsOn1)
    {
        mask1 = chnM & _ctl->pr_nearMask_DRLTI;     /* 40mm与TI的掩码 */
        perc1 = _ctl->pr_percDRLTI40mm;

        if (mask1 != 0)     
        {
            /* 设置共用效果标识 */
            _ctl->st_bDRLTI = 1;
            /* 记录此通道的设置值 */
            for (i=0; i<MAX_CHANNLE_NUM; i++)
            {
                if (((mask1) & (0x0001<<i)) != 0)
                { percAll[i] = perc1; }
            }
        }

        mask1 = chnM & _ctl->pr_appaMask_DRLTI;     /* 与TI共用发光面的掩码 */
        perc1 = _ctl->pr_percDRLTI;
        if (mask1 != 0)
        {
            /* 设置共用效果标识 */
            _ctl->st_bDRLTI = 1;
            /* 记录此通道的设置值 */
            for (i=0; i<MAX_CHANNLE_NUM; i++)
            {
                if (((mask1) & (0x0001<<i)) != 0)
                { percAll[i] = perc1; }
            }
        }

        /*  */
        toff = 0;
    }

    

    /* 设置无矩阵通道 通道PWM */
    if (mask != 0)
    {
        for (i=0; i<MAX_CHANNLE_NUM; i++)
        {
            mask1 = (mask) & (0x0001<<i);
            if (mask1 != 0)
            {
                LampM_SetLampChn(func, mask1, percAll[i], ton, toff);
            }
        }
    }
    /* 设置有矩阵通道 通道和矩阵各像素的占空比 */
    if (mtxM != 0)
    {
        for (i=0; i<MAX_CHANNLE_NUM; i++)
        {
            mask1 = (mtxM) & (0x0001<<i);
            if (mask1 != 0)
            {
                /* 设置 通道PWM */
                LampM_SetLampChn(func, mask1, 100, 0, 0);

                /* 设置 矩阵各像素 */
                lampM_GetLampChnPixId(func, (0x0001<<i), pid);
                for (j=0; j<MAX_MATRIXCHIP_CHANNEL_NUM; j++)
                {
                    id = pid[j];
                    if (id != 0)
                    {
                        LampM_SetLampPix(func, id, percAll[i], ton, toff);
                    }
                }
            }
        }
    }
}

static void act_on_DRL(uint8_t TIstsOn1)
{
    Light_Functions func = E_DaytimeRunningLight;
    uint16_t        chnM = _ctl->pr_DRLinfo.chnMask;
    uint16_t        mtxM = _ctl->pr_DRLinfo.mtxMask;
    uint8_t         perc = 100;                 /* DRL亮度百分比 */
    uint16_t        ton  = _ctl->pr_onRamp_DRL;
    uint16_t        toff = _ctl->pr_offRamp_DRL;

    if (_ctl->st_actDRL)
    { perc = 100; }

    if (_ctl1->pr_AFSLightDRL && _ctl1->st_actAFS)  /* 同时点亮日行灯，按照pAFSDRLPWM亮度值，CTS-V-9.3.6.1 */
    {
        perc = _ctl1->pr_AFSDRLPWM / 10;
        if ((_ctl1->pr_AFSDRLPWM % 10) >= 5)
        { perc += 1; }
    }

    _act_SetPix(func, chnM, mtxM, perc, ton, toff, TIstsOn1, 0);
}
static void act_off_DRL()
{
    Light_Functions func = E_DaytimeRunningLight;
    uint16_t        chnM = _ctl->pr_DRLinfo.chnMask;
    uint16_t        mtxM = _ctl->pr_DRLinfo.mtxMask;
    uint8_t         perc = 0;
    uint16_t        ton  = _ctl->pr_onRamp_DRL;
    uint16_t        toff = _ctl->pr_offRamp_DRL;

    _act_SetPix(func, chnM, mtxM, perc, ton, toff, 0, 0);
}




void DRL_Init(void)
{
    uint16_t maskDRL, maskPOS;
    uint16_t u16v;

    C_Memcpy_B((uint8_t*)(&drlctl), 0, sizeof(S_DRLCtl_t));
    C_Memcpy_B((uint8_t*)(&afsdrlctl), 0, sizeof(S_AFSDRLCtl_t));

    lampM_GetLampInfo(E_DaytimeRunningLight, &(drlctl.pr_DRLinfo));

#if (DEBUG_LIGHTING_DRL)
    drlctl.pr_onRamp_DRL  = 0;
    drlctl.pr_offRamp_DRL = 0;
#else
    drlctl.pr_onRamp_DRL  = Get_pLedOnRampTi(E_DaytimeRunningLight);
    drlctl.pr_offRamp_DRL = Get_pLedOffRampTi(E_DaytimeRunningLight);
#endif

    /*  */
    drlctl.pr_nearMask_DRLTI = Get_DRL_TI_surfaces_Near();
    drlctl.pr_appaMask_DRLTI = Get_DRL_TI_surfaces_apparent();


    maskDRL = drlctl.pr_DRLinfo.chnMask;

    drlctl.pr_chnMask_PosDRL = maskDRL & maskPOS;
    drlctl.pr_nearMask_DRLTI &= maskDRL;
    drlctl.pr_appaMask_DRLTI &= maskDRL;

    /* 0:ECE, 1:SAE; 2:Reserve */
#if (DEBUG_LIGHTING_DRL)
    drlctl.pr_LegalRequ = 1;
#else
    drlctl.pr_LegalRequ = Get_pLegalRequirement();
#endif

    /* N-1 */
    u16v = Get_LightN_1();
    if ((u16v & 0x0010) != 0) { drlctl.pr_N_1 = 1; }

    /* AFS-DRL */
    afsdrlctl.pr_AFSLightDRL = Get_ParaMgr_pAFSLightDRL() ? 1 : 0;
    afsdrlctl.pr_AFSDRLPWM = Get_ParaMgr_pAFSDRLPWM();

    _ctl = &drlctl;
    _ctl1 = &afsdrlctl;
}

void DRL_Exit(void)
{
    _ctl = 0;
}

void DRL_Run_(unsigned int ms)
{
    S_LgtFuncEna_t ena;
    S_LgtActIns_t  act;

    if ((_ctl == 0) || (_ctl1 == 0)) { return; }

    GetLgtFuncEna(&ena);
    GetLgtActIns (&act);
    _ctl->st_actDRL   = act.ActDRL;
    _ctl->st_enaDRL   = ena.EnaDRL;
    _ctl->st_actTI    = act.ActTIact;
    _ctl->st_stsTI    = act.ActTIsts;
    _ctl1->st_actAFS  = act.ActAFS;
    _ctl1->st_enaAFS  = ena.EnaAFS;
    _ctl1->st_actHB   = act.ActHB;
    _ctl1->st_actAHBC = act.ActAHBC;
    LampM_GetLampBaseErr(&(_ctl->st_err));
    LampM_GetLampBaseErr_DTC(&(_ctl->st_errDTC));

#if (DEBUG_LIGHTING_DRL)
    _ctl->st_actDRL = 1;
    _ctl->st_enaDRL = 1;
    _ctl->st_stsTI = 0;
    _ctl->st_actTI = 0;
#endif

    /* TI关计时 */
    if (_ctl->st_stsTI == 1)
    { _ctl->st_msTIOFF = 0; }
    else
    { _ctl->st_msTIOFF = C_AddToMax_U16(_ctl->st_msTIOFF, ms); }

    /* DRL-TI共用效果延时 */
    _ctl->st_DRLstsTI = act.ActTIsts;
    if (_ctl->st_bDRLTI)
    {
        if (_ctl->st_msTIOFF < _ctl->pr_uptimeDRLTI)
        { _ctl->st_DRLstsTI = 1; }
    }

    /* Turn On/Off */
    if ((_ctl->st_enaDRL) && 
        ((_ctl->st_actDRL) || ((_ctl1->pr_AFSLightDRL)&&(_ctl1->st_actAFS)&&(_ctl1->st_enaAFS)&&(_ctl1->st_actHB == 0) && (_ctl1->st_actAHBC == 0))))
    { _ctl->st_turnDRL = 1; }
    else
    { _ctl->st_turnDRL = 0; }

    /* Turn Off */
    if (_ctl->st_turnDRL == 0)
    {
        if (_ctl->pr_DRLinfo.being)
        {
            act_off_DRL();
        }

        SetLgtStsFb_DRL(STS_OFF);

        /* CTS-6.4.4 */
        /* if (_ctl->st_actDRL)
        { SetLgtStsFb_DRL(STS_ERR); } */
    }
}

void DRL_Run_On(void)
{
    if ((_ctl == 0) || (_ctl1 == 0)) { return; }

    /* Turn On */
    if (_ctl->st_turnDRL)
    {
        /* 动作并反馈 */
        if (_ctl->pr_DRLinfo.being)
        {
            act_on_DRL(_ctl->st_DRLstsTI);

            if ((_ctl->st_actDRL) ||
                (_ctl1->pr_AFSLightDRL && _ctl1->st_actAFS))
            { SetLgtStsFb_DRL(STS_ON); }
        }

        /* 故障判断并反馈 */
        if (((_ctl->st_err.chnErr & (_ctl->pr_DRLinfo.chnMask)) != 0) ||
            ((_ctl->st_err.mtxErr & (_ctl->pr_DRLinfo.mtxMask)) != 0))
        {
            if (FEEDERR_LATE == 0) { SetLgtStsFb_DRL(STS_ERR); }

            /* 故障 关 */
            if (((_ctl->st_errDTC.chnErr & (_ctl->pr_DRLinfo.chnMask)) != 0) ||
                ((_ctl->st_errDTC.mtxErr & (_ctl->pr_DRLinfo.mtxMask)) != 0))
            {
                if (FEEDERR_LATE) { SetLgtStsFb_DRL(STS_ERR); } 
                if (_ctl->pr_N_1) { SetLgtOnDis_DRL(); }
            }

        }

        /* NTC故障，反馈ERROR */
        if ((_ctl->st_errDTC.ntcErr & (_ctl->pr_DRLinfo.chnMask)) != 0)
        {
            SetLgtStsFb_DRL(STS_ERR);
        }

    }
}
