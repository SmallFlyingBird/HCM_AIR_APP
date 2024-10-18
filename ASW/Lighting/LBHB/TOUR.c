

/* Base Include */
#include "HcmPlatform.h"
#include "GeneralFunction.h"
#include "Parameter_Interface.h"
#include "ComSignal_Interface.h"
#include "MatrixChip_Interface.h"
#include "MotorManage.h"

/* Lighting Include */
#include "LampManager.h"
#include "Lighting.h"

#include "TOUR.h"


typedef struct _TOURCtl_
{
    S_LF_Info_T pr_infoLBkink;          /* LBkink灯光配置信息 */

    uint8_t     pr_TouristMod       :2; /* Tourist Mod */
    uint8_t     pr_PixMode          :2; /* LB-HB PxlModuleType (N.A.) */

    double      pr_DfltDegLe;           /* 左侧默认角度 */
    double      pr_DfltDegRi;           /* 右侧默认角度 */

    uint16_t    pr_onRampLBkink;        /* LB-kink On Ramp */
    uint16_t    pr_offRampLBkink;       /* LB-kink Off Ramp */

    uint16_t    pr_LB_ramp;

    const uint8_t   *st_LBkinkPixPerc;   /* Current LBkint Pix Percent, 84 bytes */
    uint8_t          st_isLBKinkOn;

    /*  */
    S_LgtFuncEna_t  st_ena;     /* 动作是能 */
    S_LgtActIns_t   st_act;     /* 动作命令 */
    S_LF_Err_T      st_err;     /* 动作故障 */
    uint8_t         st_turn;    /* 当前功能激活状态，0:TurnOff; 1:TurnOn */

}S_TOURCtl_t;

static       S_TOURCtl_t     tourctl;       /* 初始化时用 */
static       S_TOURCtl_t    *_ctl = 0;      /* 初始化后用 */

static const uint8_t        *pr_pixLB;      /* 配置的LB各像素PWM */
static const uint8_t        *_pixTour;      /* 配置的TouristMod各像素PWM */


static void _act_use_PixPerc(
    Light_Functions func, 
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

static void act_off_LBkink()
{
    Light_Functions func = E_LowBeamKink;
    uint16_t        chnM = _ctl->pr_infoLBkink.chnMask;
    uint16_t        mtxM = _ctl->pr_infoLBkink.mtxMask;
    uint8_t         perc = 0;
    uint16_t        ton  = _ctl->pr_onRampLBkink;
    uint16_t        toff = _ctl->pr_offRampLBkink;

    /*  */
    _act_use_PixPerc(func, chnM, mtxM, perc, ton, toff, 0, 0);
}

static void act_on_LBkink()
{
    Light_Functions func = E_LowBeamKink;
    uint16_t        chnM = _ctl->pr_infoLBkink.chnMask;
    uint16_t        mtxM = _ctl->pr_infoLBkink.mtxMask;
    uint8_t         perc = 100;
    uint16_t        ton  = _ctl->pr_onRampLBkink;
    uint16_t        toff = _ctl->pr_offRampLBkink;

    _ctl->st_LBkinkPixPerc = _pixTour;
 
    _act_use_PixPerc(func, chnM, mtxM, perc, ton, toff, 1, _pixTour);
}


void TOUR_Init(void)
{
    uint8_t u8v;

    C_Memset_B((uint8_t*)(&tourctl), 0, sizeof(S_TOURCtl_t));


    lampM_GetLampInfo(E_LowBeamKink,  &(tourctl.pr_infoLBkink));


    tourctl.pr_TouristMod = Get_ParaMgr_pTouristMod();

    tourctl.pr_DfltDegLe = Get_LeLamp_pLvlDfltPosLe_deg();
    tourctl.pr_DfltDegRi = Get_RiLamp_pLvlDfltPosRi_deg();

    tourctl.pr_onRampLBkink  = Get_pLedOnRampTi(E_LowBeamKink);
    tourctl.pr_offRampLBkink = Get_pLedOffRampTi(E_LowBeamKink);

    if (LR_LE == Get_FlgLR())
    { _pixTour = Get_pLHTPWMPixel_head(); }
    else
    { _pixTour = Get_pLHTPWMPixel_R_head(); }

    _ctl = &tourctl;
}

void TOUR_Exit(void)
{
    _ctl = 0;
}

void TOUR_Run_(uint16_t ms)
{
    S_LgtFuncEna_t *ena;
    S_LgtActIns_t  *act;
    S_LF_Err_T     *err;

    if (_ctl == 0) return;
    ena = &(_ctl->st_ena);
    act = &(_ctl->st_act);
    err = &(_ctl->st_err);

    GetLgtFuncEna(ena);
    GetLgtActIns (act);
    LampM_GetLampBaseErr(err);

#if (DEBUG_LIGHTING_TOUR_LB)

#endif

    /* Turn Off/On */
    if ((ena->EnaTOUR == ENA_ON) &&
        ((act->ActTOUR == ACT_ON)/*  && (act->ActLB == ACT_ON) */) &&
        ((_ctl->pr_TouristMod == 1) || (_ctl->pr_TouristMod == 2)))
    { _ctl->st_turn = 1; }
    else
    { _ctl->st_turn = 0; }

    if ((_ctl->pr_TouristMod == 2) &&
        ((act->ActTOUR == ACT_ON)/*  && (act->ActLB == ACT_ON) */))
    { MotorManage_SetLevelingFuncActState(E_LvlFunction_TrMod, 1); }
    else
    { MotorManage_SetLevelingFuncActState(E_LvlFunction_TrMod, 0); }
    

    /* Turn Off */
    /* Depend LB Trun Off */
}

void TOUR_Run_On(void)
{
    S_LgtFuncEna_t *ena;
    S_LgtActIns_t  *act;
    S_LF_Err_T     *err;

    double         degInc;
    sint16_t       posInc;

    if (_ctl == 0) return;
    ena = &(_ctl->st_ena);
    act = &(_ctl->st_act);
    err = &(_ctl->st_err);

    /* Turn On */
    /* Depend LB Turn On */
    if (_ctl->st_turn)
    {
        if (_ctl->pr_infoLBkink.being)
        {
            if (_ctl->pr_TouristMod == 1)
            { act_off_LBkink(); }

            if (_ctl->pr_TouristMod == 2)
            { act_on_LBkink(); }
        }

        /* 交换默认位置 */
        posInc = 0;
        if (_ctl->pr_TouristMod == 2)
        {
            if (Get_FlgLR() == LR_LE)
            {
                degInc = _ctl->pr_DfltDegRi - _ctl->pr_DfltDegLe;
            }
            else
            {
                degInc = _ctl->pr_DfltDegLe - _ctl->pr_DfltDegRi;
            }
            posInc = MotorManage_LvlConvertAglIncreToPosIncre(degInc * RAD_PER_DEG);
            
        }
        MotorManage_SetLevelingPosIncre(E_LvlFunction_TrMod, posInc);


        /*  */
        if (((err->chnErr & _ctl->pr_infoLBkink.chnMask) == 0) &&
            ((err->mtxErr & _ctl->pr_infoLBkink.mtxMask) == 0) &&
            ((err->ntcErr & _ctl->pr_infoLBkink.chnMask) == 0))
        {
            SetLgtStsFb_TOUR(STS_ON);
        }
        else
        {
            SetLgtStsFb_TOUR(STS_ERR);
        }
    }
    else
    {
        /* LVL */
        MotorManage_SetLevelingPosIncre(E_LvlFunction_TrMod, 0);
    }
}

uint8_t TOUR_is_LBKinkOn(void)
{
    if ((_ctl->st_turn == 1) &&
        (_ctl->pr_TouristMod == 2))
    { return 1; }
    else
    { return 0; }
}

const uint8_t * TOUR_Get_PixPercHead(void)
{
    if (_ctl == 0) { return Get_pLowBeamPWMPixel_head(); }
    else           { return _ctl->st_LBkinkPixPerc; }
}
