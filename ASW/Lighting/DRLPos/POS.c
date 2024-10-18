


/* ASW Interface */
#include "HcmPlatform.h"
#include "GeneralFunction.h"
#include "Parameter_Interface.h"
#include "MatrixChip_Interface.h"
#include "ComSignal_Interface.h"
/* Lighting Base */
#include "Lighting.h"
#include "LampManager.h"

#include "POS.h"



typedef struct _POSCtl_
{

    uint8_t     pr_DRLPOStype;      /* 0:共用通道；1:独立通道；2:部分共用通道 */

    S_LF_Info_T pr_Posinfo;         /* POS灯光配置信息 */
    S_LF_Info_T pr_DRLinfo;         /* DRL灯光配置信息 */

    uint16_t    pr_onRamp_POS;
    uint16_t    pr_offRamp_POS;


    uint8_t     pr_percPOS;         /* POS亮度百分比 */
    uint8_t     pr_percPOSDRL;      /* POS与DRL共用时的亮度 */
    uint8_t     pr_percPOSTI;       /* ECE:共用时亮度百分比 */
    uint16_t    pr_uptimePOSTI;     /* 共用效果 延时时间 */

    uint16_t    pr_chnMask_PosDRL;  /* POS与DRL通道共用 通道标识 */
    uint16_t    pr_appaMask_POSTI;  /* POS与TI发光面共用 通道标识 */

    uint8_t     pr_LegalRequ;    /* 0:ECE, 1:SAE; 2:Reserve */

    /* N-1 */
    uint8_t         pr_N_1      :1; /* 0:能亮则亮; 1:1灭全灭 */

    uint8_t     st_bPOSTI   :1;     /* POSTI共用效果存在标识 */
    uint16_t    st_msTIOFF;         /* TI关计时 */

    uint16_t    st_POSms;   /* AOL_POS状态的时间ms，单向增加 */

    uint8_t     st_POSperc; /* POS当前占空比 */

    S_LF_Err_T  st_err;
    S_LF_Err_T  st_errDTC;

    uint8_t     st_actPOS   :1;     /* 0:act; 1:un-act */
    uint8_t     st_actTI    :1;
    uint8_t     st_stsTI    :1;
    uint8_t     st_enaPOS   :1;     /* 0:disable; 1:enable */

    uint8_t     st_turnPOS  :1;     /* 0:turn off; 1:turn on */
    uint8_t     st_POSstsTI :1;     /* POS-TI共用效果延时用，命令保持 */

    uint16_t    st_ChnOnErr;    /* POS Channel On error state */

}S_POSCtl_t;

static S_POSCtl_t posctl, *_ctl = 0;


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
    {
        percAll[i] = perc;

        /* POS/DRL共用的通道 */
        if (posctl.pr_chnMask_PosDRL & (0x0001 << i))
        { percAll[i] = posctl.pr_percPOSDRL; }
    }

    
    _ctl->st_bPOSTI = 0;    /* POSTI共用标识清零 */
    if (TIstsOn1)
    {
        mask1 = chnM & _ctl->pr_appaMask_POSTI;     /* POSTI共用发光面识别 */
        perc1 = _ctl->pr_percPOSTI;
        if ((_ctl->pr_LegalRequ == 1) && TIactOn1)
        { perc1 = 0; }    

        if (perc1 == 0)
        {
            toff = 0;   /* 当关闭时，立刻关闭 */

            _ctl->st_err.chnErr |= (_ctl->st_ChnOnErr & mask1); /* 被转向关闭的通道 保持开时的故障状态 */
        }

        if (mask1 != 0)
        {
            /* 设置共用效果标识 */
            _ctl->st_bPOSTI = 1;
            /* 记录此通道的设置值 */
            for (i=0; i<MAX_CHANNLE_NUM; i++)
            {
                if (((mask1) & (0x0001<<i)) != 0)
                { percAll[i] = perc1; }
            }
        }
    }
    else
    {
        _ctl->st_ChnOnErr = _ctl->st_err.chnErr;    /* 记录 可被转向关闭的通道 开时故障状态 */
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

static void act_on_POS(uint8_t TIstsOn1, uint8_t TIactOn1)
{
    Light_Functions func = E_PositionLight;
    uint16_t        chnM = _ctl->pr_Posinfo.chnMask;
    uint16_t        mtxM = _ctl->pr_Posinfo.mtxMask;
    uint8_t         perc = _ctl->pr_percPOS;    /* POS亮度百分比 */
    uint16_t        ton  = _ctl->pr_onRamp_POS;
    uint16_t        toff = _ctl->pr_offRamp_POS;

    _act_SetPix(func, chnM, mtxM, perc, ton, toff, TIstsOn1, TIactOn1);
}
static void act_off_POS()
{
    Light_Functions func = E_PositionLight;
    uint16_t        chnM = _ctl->pr_Posinfo.chnMask;
    uint16_t        mtxM = _ctl->pr_Posinfo.mtxMask;
    uint8_t         perc = 0;
    uint16_t        ton  = _ctl->pr_onRamp_POS;
    uint16_t        toff = _ctl->pr_offRamp_POS;

    _act_SetPix(func, chnM, mtxM, perc, ton, toff, 0, 0);
}


void POS_Init(void)
{
    uint16_t maskDRL, maskPOS;
    uint16_t u16v;

    C_Memcpy_B((uint8_t*)(&posctl), 0, sizeof(S_POSCtl_t));

    lampM_GetLampInfo(E_PositionLight, &(posctl.pr_Posinfo));
    lampM_GetLampInfo(E_DaytimeRunningLight, &(posctl.pr_DRLinfo));

#if (DEBUG_LIGHTING_POS)
    posctl.pr_onRamp_POS  = 0;
    posctl.pr_offRamp_POS = 0;
#else
    posctl.pr_onRamp_POS  = Get_pLedOnRampTi(E_PositionLight);
    posctl.pr_offRamp_POS = Get_pLedOffRampTi(E_PositionLight);
#endif

    /*  */
    posctl.pr_appaMask_POSTI = Get_POS_TI_surfaces_apparent();

#if (DEBUG_LIGHTING_POS)
    posctl.pr_percPOS = 30;
    posctl.pr_percPOSTI = 14;
    posctl.pr_uptimePOSTI = 200;
#else
    posctl.pr_percPOS = Get_pLedIntensPosLDuty();
    posctl.pr_percPOSDRL = Get_pLedIntensityPos();
    posctl.pr_percPOSTI = Get_pLedIntensityPosTi();
    posctl.pr_uptimePOSTI = Get_pLedTimeUpPosTi();
#endif

    maskDRL = posctl.pr_DRLinfo.chnMask;
    maskPOS = posctl.pr_Posinfo.chnMask;

    posctl.pr_chnMask_PosDRL = maskDRL & maskPOS;
    posctl.pr_appaMask_POSTI &= maskPOS;


    /* 0:ECE, 1:SAE; 2:Reserve */
#if (DEBUG_LIGHTING_POS)
    posctl.pr_LegalRequ = 1;
#else
    posctl.pr_LegalRequ = Get_pLegalRequirement();
#endif

    /* N-1 */
    u16v = Get_LightN_1();
    if ((u16v & 0x0020) != 0) { posctl.pr_N_1 = 1; }

    _ctl = &posctl;
}

void POS_Exit(void)
{
    _ctl = 0;
}

void POS_Run_(unsigned int ms)
{
    S_LgtFuncEna_t ena;
    S_LgtActIns_t  act;

    GetLgtFuncEna(&ena);
    GetLgtActIns (&act);
    _ctl->st_actPOS = act.ActPOS;
    _ctl->st_enaPOS = ena.EnaPOS;
    _ctl->st_actTI = act.ActTIact;
    _ctl->st_stsTI = act.ActTIsts;
    LampM_GetLampBaseErr(&(_ctl->st_err));
    LampM_GetLampBaseErr_DTC(&(_ctl->st_errDTC));

#if (DEBUG_LIGHTING_POS)
    _ctl->st_actPOS = 1;
    _ctl->st_enaPOS = 1;
    _ctl->st_stsTI = 0;
    _ctl->st_actTI = 0;
#endif

    /* TI关计时 */
    if (_ctl->st_stsTI == 1)
    { _ctl->st_msTIOFF = 0; }
    else
    { _ctl->st_msTIOFF = C_AddToMax_U16(_ctl->st_msTIOFF, ms); }

    /* POS共用效果延时 */
    _ctl->st_POSstsTI = act.ActTIsts;
    if (_ctl->st_bPOSTI)
    {
        if (_ctl->st_msTIOFF < _ctl->pr_uptimePOSTI)
        { _ctl->st_POSstsTI = ACT_ON; }
    }

    /* Turn On/Off */
    if ((_ctl->st_enaPOS) && (_ctl->st_actPOS))
    { _ctl->st_turnPOS = 1; }
    else
    { _ctl->st_turnPOS = 0; }

    /* Turn Off */
    if (_ctl->st_turnPOS == 0)
    {
        if (_ctl->pr_Posinfo.being)
        {
            act_off_POS();
        }

        SetLgtStsFb_POS(STS_OFF);

        /* CTS-6.4.4 */
        /* if (_ctl->st_actPOS)
        { SetLgtStsFb_POS(STS_ERR); } */
    }

}


void POS_Run_On(void)
{
    if (_ctl == 0) { return; }

    /* Turn On */
    if (_ctl->st_turnPOS)
    {
        if (_ctl->pr_Posinfo.being)
        {
            act_on_POS(_ctl->st_POSstsTI, _ctl->st_actTI);
        }

        if (((_ctl->st_err.chnErr & _ctl->pr_Posinfo.chnMask) == 0) &&
            ((_ctl->st_err.mtxErr & _ctl->pr_Posinfo.mtxMask) == 0))
        { SetLgtStsFb_POS(STS_ON); }
        else
        {
            if (FEEDERR_LATE) { SetLgtStsFb_POS(STS_ON);  }
            else              { SetLgtStsFb_POS(STS_ERR); }

            /* 故障 关 */
            if (((_ctl->st_errDTC.chnErr & _ctl->pr_Posinfo.chnMask) != 0) ||
                ((_ctl->st_errDTC.mtxErr & _ctl->pr_Posinfo.mtxMask) != 0))
            {
                if (FEEDERR_LATE) { SetLgtStsFb_POS(STS_ERR); } 
                if (_ctl->pr_N_1) { SetLgtOnDis_POS(); }
            }
        }

        /* NTC故障，反馈ERROR */
        if ((_ctl->st_errDTC.ntcErr & _ctl->pr_Posinfo.chnMask) != 0)
        {
            SetLgtStsFb_POS(STS_ERR);
        }

    }

}
