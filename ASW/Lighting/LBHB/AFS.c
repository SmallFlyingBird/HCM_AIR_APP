/**
 * @file AFS.c
 * @author QinHaigang (qinhaigang@xyl.cn)
 * @brief 
 * @version 0.1
 * @date 2024-09-27
 * 
 * @copyright Copyright (c) 2024-  New Elec. Dept. XYL
 * 
 * @par History:
 * <table>
 * <tr><th>Data       <th>Version <th>Author     <th>Description
 * <tr><td>2024-09-27 <td>0.1     <td>QinHaigang <td>First
 * </table>
 */

/* Base Include */
#include "HcmPlatform.h"
#include "GeneralFunction.h"
#include "Parameter_Interface.h"
#include "ComSignal_Interface.h"
#include "MatrixChip_Interface.h"

/* Lighting Include */
#include "LampManager.h"
#include "Lighting.h"

#include "AFS.h"

#include "CorneringLight.h"
#include "FogLamp.h"
#include "MotorManage.h"


#if 0   /* move to Lighting.h */
typedef enum _vcew_
{
    VCEW_U = 0, /* 无模式 */
    VCEW_V,     /* 城市模式TOW */
    VCEW_C,     /* 乡村模式CON */
    VCEW_E,     /* 高速模式MOT */
    VCEW_W      /* 天气模式AWL */
}E_VCEW_t;
#endif


typedef struct _AFSCtl_
{
    S_LF_Info_T pr_infoLBflat;          /* LBflat灯光配置信息 */
    S_LF_Info_T pr_infoLBkink;          /* LBkink灯光配置信息 */
    S_LF_Info_T pr_infoCORN;            /* CORN灯光配置信息 */
    S_LF_Info_T pr_infoFOG;             /* FOG灯光配置信息 */

    uint8_t     pr_TownLight_en     :1; /* Town light */
    uint8_t     pr_CountryLight_en  :1; /* Country light */
    uint8_t     pr_MotorwayLight_en :1; /* Motorway light */
    uint8_t     pr_AWLight_en       :1; /* Adverse Weather light */
    uint8_t     pr_PixMode          :2; /* LB-HB PxlModuleType */

    uint8_t     pr_TOWN_CORN        :1;
    uint8_t     pr_AWL_FOG          :1;

    uint16_t    pr_SpdThd1OfAfs;        /* Thd1 upper limit (0.01m/s) */
    uint16_t    pr_SpdThd1OfAfs_Lo;     /* Thd1 lower limit (0.01m/s) */
    uint16_t    pr_SpdThd2OfAfs;        /* Thd2 upper limit (0.01m/s) */
    uint16_t    pr_SpdThd2OfAfs_Lo;     /* Thd2 lower limit (0.01m/s) */
    uint16_t    pr_SpdThd3OfAfs;        /* Thd3 upper limit (0.01m/s) */
    uint16_t    pr_SpdThd3OfAfs_Lo;     /* Thd3 lower limit (0.01m/s) */

    uint8_t     pr_TOWN_LBflat; /* Town light,            LB-flat intensity */
    uint8_t     pr_TOWN_LBkink; /* Town light,            LB-kink intensity */
    uint8_t     pr_CORY_LBflat; /* Country light,         LB-flat intensity */
    uint8_t     pr_CORY_LBkink; /* Country light,         LB-kink intensity */
    uint8_t     pr_AWL_LBflat;  /* Adverse Weather light, LB-flat intensity */
    uint8_t     pr_AWL_LBkink;  /* Adverse Weather light, LB-kink intensity */
    uint8_t     pr_MOTO_LBflat; /* Motorway light,        LB-flat intensity */
    uint8_t     pr_MOTO_LBkink; /* Motorway light,        LB-kink intensity */

    uint16_t    pr_onRampLBflat;        /* LB-flat On Ramp */
    uint16_t    pr_onRampLBkink;        /* LB-kink On Ramp */
    uint16_t    pr_offRampLBflat;       /* LB-flat Off Ramp */
    uint16_t    pr_offRampLBkink;       /* LB-kink Off Ramp */

    uint8_t     pr_TOWN_CorLgt_Perc;    /* Town-Mod, CornerLight intensity */

    /* uint16_t    pr_TOWN_ramp;
    uint16_t    pr_CORY_ramp;
    uint16_t    pr_MOTO_ramp;
    uint16_t    pr_AWL_ramp;
    uint16_t    pr_TOUR_ramp;
    uint16_t    pr_LB_ramp; */

    uint16_t    pr_OvrTime_TOWN;
    uint16_t    pr_OvrTime_CORY;
    uint16_t    pr_OvrTime_MOTO;
    uint16_t    pr_OvrTime_AWL;
    uint16_t    pr_OvrTime_LB;

    double      pr_LVL_OfsDeg_TOWN;     /* TOWN, LVL motor Offset deg */
    double      pr_LVL_OfsDeg_CORY;     /* CORY, LVL motor Offset deg */
    double      pr_LVL_OfsDeg_MOTO;     /* MOTO, LVL motor Offset deg */
    double      pr_LVL_OfsDeg_AWL;      /* AWL , LVL motor Offset deg */
    double      pr_SWL_OfsDeg_TOWN;     /* TOWN, SWL motor Offset deg */
    double      pr_SWL_OfsDeg_CORY;     /* CORY, SWL motor Offset deg */
    double      pr_SWL_OfsDeg_MOTO;     /* MOTO, SWL motor Offset deg */
    double      pr_SWL_OfsDeg_AWL;      /* AWL , SWL motor Offset deg */

    /* pr_deg Lvl电机角度参数...... */
    uint8_t     st_actAFS       :1;
    uint8_t     st_actWipr      :1;
    uint8_t     ou_stsAFS       :2;

    uint8_t     st_iniVCEW      :1;     /* 初始没有判断过VCEW */

    uint16_t    st_VehiSpd;         /* vehicle speed (0.01m/s) */
    uint16_t    st_VehiSpd0;        /* pre vehicle speed (0.01m/s) */

    E_VCEW_t    st_vcew;        /* current vcew */
    E_VCEW_t    st_vcew0;       /* pre-vcew for OvrTime */
    uint16_t    st_OvrTime;     /* Current OvrTime counter */

    
    const uint8_t   *st_LBkinkPixPerc;   /* Current LBkint Pix Percent, 84 bytes */

    /*  */
    S_LgtFuncEna_t  st_ena;     /* 动作使能 */
    S_LgtActIns_t   st_act;     /* 动作命令 */
    S_LgtStsFb_t    st_sts;     /* 动作反馈 */
    S_LF_Err_T      st_err;     /* 动作故障 */
    S_LF_Err_T      st_errDTC;  /* 动作故障 */

    uint8_t     st_turnOnOff0   :1;
    uint8_t     st_OvrTimeOk    :1; /* 模式满足延时 */

    /* DMoni信息 */
    uint8_t     dm_rx8[8];
    uint8_t     dm_tx8[8];

}S_AFSCtl_t;

static       S_AFSCtl_t     afsctl;     /* 初始化时用 */
static       S_AFSCtl_t    *_ctl = 0;   /* 初始化后用 */

static const uint8_t       *pr_pixLB;     /* 配置的LB各像素PWM */
static const uint8_t       *pr_pixTOWN;   /* 配置的Town各像素PWM */
static const uint8_t       *pr_pixMOTO;   /* 配置的Motorway各像素PWM */
static const uint8_t       *pr_pixCORY;   /* 配置的Country各像素PWM */
static const uint8_t       *pr_pixAWL;    /* 配置的AdverseWeather各像素PWM */
static const uint8_t       *pr_pixTour;   /* 配置的TouristMod各像素PWM */



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

static void act_off_LBflat()
{
    Light_Functions func = E_LowBeamFlat;
    uint16_t        chnM = _ctl->pr_infoLBflat.chnMask;
    uint8_t         perc = 0;
    uint16_t        ton  = _ctl->pr_onRampLBflat;
    uint16_t        toff = _ctl->pr_offRampLBflat;

    /*  */
    LampM_SetLampChn(func, chnM, perc, ton, toff);  /* 无矩阵通道 */

}
static void act_off_LBkink()
{
    Light_Functions func = E_LowBeamKink;
    uint16_t        chnM = _ctl->pr_infoLBkink.chnMask;
    uint16_t        mtxM = _ctl->pr_infoLBkink.mtxMask;
    uint8_t         perc = 0;
    uint16_t        ton  = _ctl->pr_onRampLBkink;
    uint16_t        toff = _ctl->pr_offRampLBkink;

    _ctl->st_LBkinkPixPerc = pr_pixLB;

    /*  */
    _act_use_PixPerc(func, chnM, mtxM, perc, ton, toff, 0, pr_pixLB);
}

static void act_on_LBflat()
{
    Light_Functions func = E_LowBeamFlat;
    uint16_t        chnM = _ctl->pr_infoLBflat.chnMask;
    uint8_t         perc = 100;
    uint16_t        ton  = _ctl->pr_onRampLBflat;
    uint16_t        toff = _ctl->pr_offRampLBflat;

    switch (_ctl->st_vcew)
    {
    case VCEW_V: if (_ctl->pr_TownLight_en)     { perc = _ctl->pr_TOWN_LBflat; } break;
    case VCEW_C: if (_ctl->pr_CountryLight_en)  { perc = _ctl->pr_CORY_LBflat; } break;
    case VCEW_E: if (_ctl->pr_MotorwayLight_en) { perc = _ctl->pr_MOTO_LBflat; } break;
    case VCEW_W: if (_ctl->pr_AWLight_en)       { perc = _ctl->pr_AWL_LBflat;  } break;
    default:;
    }

    /*  */
    LampM_SetLampChn(func, chnM, perc, ton, toff);  /* 无矩阵通道 */

}
static void act_on_LBkink()
{
    Light_Functions func = E_LowBeamKink;
    uint16_t        chnM = _ctl->pr_infoLBkink.chnMask;
    uint16_t        mtxM = _ctl->pr_infoLBkink.mtxMask;
    uint8_t         perc = 100;
    uint16_t        ton  = _ctl->pr_onRampLBkink;
    uint16_t        toff = _ctl->pr_offRampLBkink;

    const uint8_t * pix = pr_pixLB;

    switch (_ctl->st_vcew)
    {
    case VCEW_V: if (_ctl->pr_TownLight_en)     { pix = pr_pixTOWN; perc = _ctl->pr_TOWN_LBkink; } break;
    case VCEW_C: if (_ctl->pr_CountryLight_en)  { pix = pr_pixCORY; perc = _ctl->pr_CORY_LBkink; } break;
    case VCEW_E: if (_ctl->pr_MotorwayLight_en) { pix = pr_pixMOTO; perc = _ctl->pr_MOTO_LBkink; } break;
    case VCEW_W: if (_ctl->pr_AWLight_en)       { pix = pr_pixAWL;  perc = _ctl->pr_AWL_LBkink;  } break;
    default:;
    }

    _ctl->st_LBkinkPixPerc = pix;

    _act_use_PixPerc(func, chnM, mtxM, perc, ton, toff, 1, pix);
}

static void vcew_switch(uint16_t ms)
{
    uint16_t spd0 = _ctl->st_VehiSpd0; /* 记录的车速 */
    uint16_t spd  = _ctl->st_VehiSpd;  /* 当前车速 */
    uint8_t  wipr = _ctl->st_actWipr;  /* 当前雨刮 */

    E_VCEW_t set = _ctl->st_vcew0;   /* 待识别的模式=上次识别的模式 */

    if ((spd > spd0) || (_ctl->st_iniVCEW == 0))
    {
                                              set = VCEW_U;
        if (spd >= _ctl->pr_SpdThd1OfAfs)   { set = VCEW_V; }
        if (spd >= _ctl->pr_SpdThd2OfAfs)   { set = VCEW_C; }
        if (spd >= _ctl->pr_SpdThd3OfAfs)   { set = VCEW_E; }

        /* re-initialize */
        if (_ctl->st_iniVCEW == 0)
        {
            _ctl->st_vcew = _ctl->st_vcew0 = VCEW_U;

            _ctl->st_OvrTime = 0;
            _ctl->st_OvrTimeOk = 0;
            
            _ctl->st_iniVCEW = 1;
        }
    }
    if (spd < spd0)
    {
                                              set = VCEW_E;
        if (spd < _ctl->pr_SpdThd3OfAfs_Lo) { set = VCEW_C; }
        if (spd < _ctl->pr_SpdThd2OfAfs_Lo) { set = VCEW_V; }
        if (spd < _ctl->pr_SpdThd1OfAfs_Lo) { set = VCEW_U; }
    }
    if ((set > VCEW_V) && (wipr == 1))      { set = VCEW_W; }

    /* 判断模式切换 并 计时 */
    if (set != _ctl->st_vcew0)
    {
        _ctl->st_vcew0 = set;
        _ctl->st_OvrTime = 0;
        _ctl->st_OvrTimeOk = 0;
    }
    else
    {
        _ctl->st_OvrTime = C_AddToMax_U16(_ctl->st_OvrTime, ms);
    }

    /* 延时 */
    switch(_ctl->st_vcew0)
    {
    case VCEW_U: if (_ctl->st_OvrTime >= _ctl->pr_OvrTime_LB)   { _ctl->st_OvrTimeOk = 1; } break;
    case VCEW_V: if (_ctl->st_OvrTime >= _ctl->pr_OvrTime_TOWN) { _ctl->st_OvrTimeOk = 1; } break;
    case VCEW_C: if (_ctl->st_OvrTime >= _ctl->pr_OvrTime_CORY) { _ctl->st_OvrTimeOk = 1; } break;
    case VCEW_E: if (_ctl->st_OvrTime >= _ctl->pr_OvrTime_MOTO) { _ctl->st_OvrTimeOk = 1; } break;
    case VCEW_W: if (_ctl->st_OvrTime >= _ctl->pr_OvrTime_AWL)  { _ctl->st_OvrTimeOk = 1; } break;
    default:;
    }

    if (_ctl->st_OvrTimeOk)
    { _ctl->st_vcew = _ctl->st_vcew0; }
}


void AFS_Init(void)
{
    uint8_t u8v;
    double  f8v;

    C_Memset_B((uint8_t*)(&afsctl), 0, sizeof(S_AFSCtl_t));

    lampM_GetLampInfo(E_LowBeamFlat,    &(afsctl.pr_infoLBflat));
    lampM_GetLampInfo(E_LowBeamKink,    &(afsctl.pr_infoLBkink));
    lampM_GetLampInfo(E_CorneringLight, &(afsctl.pr_infoCORN));
    lampM_GetLampInfo(E_FogLamp,        &(afsctl.pr_infoFOG));

    afsctl.pr_TownLight_en = Get_ParaMgr_pTownLightEn();
    afsctl.pr_CountryLight_en = Get_ParaMgr_pCountryLightEn();
    afsctl.pr_AWLight_en = Get_ParaMgr_pAWLightEn();
    afsctl.pr_MotorwayLight_en = Get_ParaMgr_pMotorwayLightEn();

    u8v = Get_ParaMgr_pTownLightCornerLight();
    afsctl.pr_TOWN_CORN = (u8v) ? 1 : 0;
    u8v = Get_ParaMgr_pAWLLightFogLight();
    afsctl.pr_AWL_FOG = (u8v) ? 1 : 0;

    afsctl.pr_SpdThd1OfAfs = Get_ParaMgr_pSpdThd1OfAfs();
    afsctl.pr_SpdThd2OfAfs = Get_ParaMgr_pSpdThd2OfAfs();
    afsctl.pr_SpdThd3OfAfs = Get_ParaMgr_pSpdThd3OfAfs();
    u8v = Get_ParaMgr_pSpdzoneOfAfsHys();
    
    afsctl.pr_SpdThd1OfAfs_Lo = C_SubToMin_U16(afsctl.pr_SpdThd1OfAfs, u8v);
    afsctl.pr_SpdThd2OfAfs_Lo = C_SubToMin_U16(afsctl.pr_SpdThd2OfAfs, u8v);
    afsctl.pr_SpdThd3OfAfs_Lo = C_SubToMin_U16(afsctl.pr_SpdThd3OfAfs, u8v);

    afsctl.pr_TOWN_LBflat = Get_ParaMgr_pTownLightLoBeamFlatInt();
    afsctl.pr_TOWN_LBkink = Get_ParaMgr_pTownLightLoBeamKinkInt();
    afsctl.pr_MOTO_LBflat = Get_ParaMgr_pMotorwayLoBeamFlatInt();
    afsctl.pr_MOTO_LBkink = Get_ParaMgr_pMotorwayLoBeamKinkInt();
    afsctl.pr_CORY_LBflat = Get_ParaMgr_pCountryLoBeamFlatInt();
    afsctl.pr_CORY_LBkink = Get_ParaMgr_pCountryLoBeamKinkInt();
    afsctl.pr_AWL_LBflat = Get_ParaMgr_pAWLLoBeamFlatInt();
    afsctl.pr_AWL_LBkink = Get_ParaMgr_pAWLLoBeamKinkInt();

    afsctl.pr_onRampLBflat = Get_pLedOnRampTi(E_LowBeamFlat);
    afsctl.pr_onRampLBkink = Get_pLedOnRampTi(E_LowBeamKink);
    afsctl.pr_offRampLBflat = Get_pLedOffRampTi(E_LowBeamFlat);
    afsctl.pr_offRampLBkink = Get_pLedOffRampTi(E_LowBeamKink);

    afsctl.pr_TOWN_CorLgt_Perc = Get_ParaMgr_pTownCornerLightPWM();

    afsctl.pr_OvrTime_TOWN = Get_ParaMgr_pTownChngOvrTime();
    afsctl.pr_OvrTime_CORY = Get_ParaMgr_pCountryChngOvrTime();
    afsctl.pr_OvrTime_MOTO = Get_ParaMgr_pMotorwayChngOvrTime();
    afsctl.pr_OvrTime_AWL  = Get_ParaMgr_pAWLChngOvrTime();
    afsctl.pr_OvrTime_LB   = Get_ParaMgr_pLoBeamChngOvrTime();

    if (LR_LE == Get_FlgLR())
    {
        afsctl.pr_LVL_OfsDeg_TOWN = (0.01 * Get_ParaMgr_pTownOffsetLeftLvl_deg()    ) - 45;
        afsctl.pr_LVL_OfsDeg_CORY = (0.01 * Get_ParaMgr_pCountryOffsetLeftLvl_deg() ) - 45;
        afsctl.pr_LVL_OfsDeg_MOTO = (0.01 * Get_ParaMgr_pMotorwayOffsetLeftLvl_deg()) - 45;
        afsctl.pr_LVL_OfsDeg_AWL  = (0.01 * Get_ParaMgr_pAWLOffsetLeftLvl_deg()     ) - 45;

        afsctl.pr_SWL_OfsDeg_TOWN = (0.01 * Get_ParaMgr_pTownOffsetLeftDBL_deg()    ) - 45;
        afsctl.pr_SWL_OfsDeg_CORY = (0.01 * Get_ParaMgr_pCountryOffsetLeftDBL_deg() ) - 45;
        afsctl.pr_SWL_OfsDeg_MOTO = (0.01 * Get_ParaMgr_pMotorwayOffsetLeftDBL_deg()) - 45;
        afsctl.pr_SWL_OfsDeg_AWL  = (0.01 * Get_ParaMgr_pAWLOffsetLeftDBL_deg()     ) - 45;
    }
    else
    {
        afsctl.pr_LVL_OfsDeg_TOWN = (0.01 * Get_ParaMgr_pTownOffsetRightLvl_deg()    ) - 45;
        afsctl.pr_LVL_OfsDeg_CORY = (0.01 * Get_ParaMgr_pCountryOffsetRightLvl_deg() ) - 45;
        afsctl.pr_LVL_OfsDeg_MOTO = (0.01 * Get_ParaMgr_pMotorwayOffsetRightLvl_deg()) - 45;
        afsctl.pr_LVL_OfsDeg_AWL  = (0.01 * Get_ParaMgr_pAWLOffsetRightLvl_deg()     ) - 45;

        afsctl.pr_SWL_OfsDeg_TOWN = (0.01 * Get_ParaMgr_pTownOffsetRightDBL_deg()    ) - 45;
        afsctl.pr_SWL_OfsDeg_CORY = (0.01 * Get_ParaMgr_pCountryOffsetRightDBL_deg() ) - 45;
        afsctl.pr_SWL_OfsDeg_MOTO = (0.01 * Get_ParaMgr_pMotorwayOffsetRightDBL_deg()) - 45;
        afsctl.pr_SWL_OfsDeg_AWL  = (0.01 * Get_ParaMgr_pAWLOffsetRightDBL_deg()     ) - 45;
    }

    Interface_GetSignal_VehSpdLgtA(&f8v);
    afsctl.st_VehiSpd0 = afsctl.st_VehiSpd = f8v * 100;
    afsctl.st_iniVCEW = 0;

    pr_pixLB = Get_pLowBeamPWMPixel_head();
    pr_pixTOWN = Get_pTownLightPWMPixel_head();
    pr_pixMOTO = Get_pMotorWayPWMPixel_head();
    pr_pixCORY = Get_pCountryLightPWMPixel_head();
    pr_pixAWL = Get_pWeatherLightPWMPixel_head();
    pr_pixTour = Get_pLHTPWMPixel_head();

    afsctl.st_LBkinkPixPerc = pr_pixLB;

    _ctl = &afsctl;
}

void AFS_Exit(void)
{
    _ctl = 0;
}

void AFS_Run_(uint16_t ms)
{
    S_LgtFuncEna_t *ena;
    S_LgtActIns_t  *act;
    S_LgtStsFb_t   *sts;
    S_LF_Err_T     *err;
    S_LF_Err_T     *errDTC;
    double          d8v;
    uint32_t        u32v;
    sint16_t        posInc;

    if (_ctl == 0) return;
    ena = &(_ctl->st_ena);
    act = &(_ctl->st_act);
    sts = &(_ctl->st_sts);
    err = &(_ctl->st_err);
    errDTC = &(_ctl->st_errDTC);

    GetLgtFuncEna(ena);
    GetLgtActIns (act);
    GetLgtStsFb  (sts);
    LampM_GetLampBaseErr(err);
    LampM_GetLampBaseErr_DTC(errDTC);
    

    _ctl->st_VehiSpd0 = _ctl->st_VehiSpd;
    _ctl->st_VehiSpd = Get_VehSpd();

    if (_ctl->pr_AWLight_en)
    {
        Interface_GetSignal_WipgInfoWiprActv(&u32v);
        _ctl->st_actWipr = u32v ? 1 : 0;
    }

    vcew_switch(ms);

#if (DEBUG_LIGHTING_AFS)

#endif

    if ((ena->EnaAFS == 1) &&
        ((act->ActAFS == 1) && (act->ActHB == 0) && (act->ActAHBC == 0)))
    {
        _ctl->st_turnOnOff0 = 1;
    }
    else
    {
        _ctl->st_turnOnOff0 = 0;
        _ctl->st_iniVCEW = 0;   /* re-initialize */
    }

    if ((_ctl->pr_TownLight_en || _ctl->pr_CountryLight_en || _ctl->pr_MotorwayLight_en || _ctl->pr_AWLight_en) &&
        ((act->ActAFS == 1) && (act->ActHB == 0) && (act->ActAHBC == 0)))
    {
        MotorManage_SetLevelingFuncActState (E_LvlFunction_AFS, 1);
        MotorManage_SetSwivelingFuncActState(E_SvlFunction_AFS, 1);
    }
    else
    {
        MotorManage_SetLevelingFuncActState (E_LvlFunction_AFS, 0);
        MotorManage_SetSwivelingFuncActState(E_SvlFunction_AFS, 0);
    }


    /* Turn Off */
    if (0 == _ctl->st_turnOnOff0)
    {
        if (afsctl.pr_infoLBflat.being)
        { act_off_LBflat(); }

        if (afsctl.pr_infoLBkink.being)
        { act_off_LBkink(); }

        /* LVL */
        posInc = MotorManage_LvlConvertAglIncreToPosIncre(0*RAD_PER_DEG);
        MotorManage_SetLevelingPosIncre(E_LvlFunction_AFS, posInc);

        /* SWL */
        posInc = MotorManage_SvlConvertAngleIncreToPosIncre(0*RAD_PER_DEG);
        MotorManage_SetSwivelingPosIncre(E_SvlFunction_AFS, posInc);

        /* 角灯 */
        if ((_ctl->st_vcew == VCEW_V) && (_ctl->pr_TOWN_CORN == 1))
        { CorneringLight_SetPwmOfAFS(0); }

        /* 雾灯 */
        if ((_ctl->st_vcew == VCEW_W) && (_ctl->pr_AWL_FOG == 1))
        { FogLamp_SetPwmOfAFS(0); }

        SetLgtStsFb_AFS(STS_OFF);
    }
}

void AFS_Run_On(void)
{
    S_LgtFuncEna_t *ena;
    S_LgtActIns_t  *act;
    S_LgtStsFb_t   *sts;
    S_LF_Err_T     *err;
    S_LF_Err_T     *errDTC;
    double          lvl;
    double          swl;
    sint16_t        posInc;
    U_LvlFuncErrSta lvlErr;
    U_SvlFuncErrSta svlErr;
    E_LvlRefRunSts  lvlSts;
    E_SvlRefRunSts  svlSts;
    E_LvlType       lvlTyp;
    E_DBLType       svlTyp;

    if (_ctl == 0) return;
    ena = &(_ctl->st_ena);
    act = &(_ctl->st_act);
    sts = &(_ctl->st_sts);
    err = &(_ctl->st_err);
    errDTC = &(_ctl->st_errDTC);

    /* Turn On */
    if (_ctl->st_turnOnOff0)
    {
        E_LgtSts_t fbAFS   = STS_ON;
        E_LgtSts_t fbLB    = STS_ON;
        E_LgtSts_t fbDRL   = STS_Res;
        E_LgtSts_t fbCORN  = STS_Res;
        E_LgtSts_t fbFOG   = STS_Res;
        E_LgtSts_t fbSMLvl = STS_Res;
        E_LgtSts_t fbSMSwl = STS_Res;

        if (afsctl.pr_infoLBflat.being) /* LBflat肯定存在 */
        {
            act_on_LBflat();
        }

        if (afsctl.pr_infoLBkink.being)
        {
            act_on_LBkink();
        }
        
        /* 设置MOTO */
        lvl = 0;
        swl = 0;
        switch(_ctl->st_vcew)
        {
        case VCEW_V:
            if (_ctl->pr_TownLight_en)
            {
                lvl = _ctl->pr_LVL_OfsDeg_TOWN;
                swl = _ctl->pr_SWL_OfsDeg_TOWN;
            }
            break;
        case VCEW_C:
            if (_ctl->pr_CountryLight_en)
            {
                lvl = _ctl->pr_LVL_OfsDeg_CORY;
                swl = _ctl->pr_SWL_OfsDeg_CORY;
            }
            break;
        case VCEW_E:
            if (_ctl->pr_MotorwayLight_en)
            {
                lvl = _ctl->pr_LVL_OfsDeg_MOTO;
                swl = _ctl->pr_SWL_OfsDeg_MOTO;
            }
            break;
        case VCEW_W:
            if (_ctl->pr_AWLight_en)
            {
                lvl = _ctl->pr_LVL_OfsDeg_AWL;
                swl = _ctl->pr_SWL_OfsDeg_AWL;
            }
            break;
        default:;
        }

        /* LVL */
        lvlTyp = (E_LvlType)Get_pVehLvLType();
        if ((lvlTyp == E_LvlType_MHL) ||
            (lvlTyp == E_LvlType_AHL))  /* 是否配置了LVL */
        {
            posInc = MotorManage_LvlConvertAglIncreToPosIncre(lvl*RAD_PER_DEG);
            MotorManage_SetLevelingPosIncre(E_LvlFunction_AFS, posInc);
            lvlErr = MotorManage_GetLevelingFuncErrorState();
            lvlSts = LevelingMotor_GetLvlRefRunSts();
            if (lvlErr.Bits.SigErr_AFS || lvlErr.Bits.MotErr_AFS || 
                ((lvlSts != E_LvlRefRunSts_Done) && (lvlSts != E_LvlRefRunSts_During)))
            { fbSMLvl = STS_ERR; }
        }

        /* SWL */
        svlTyp = (E_DBLType)Get_pVehDBLType();
        if ((svlTyp == E_DBLType_MotorWoHall) ||
            (svlTyp == E_DBLType_MotorWiHall) ||
            (svlTyp == E_DBLType_MotorWoHallWiCL) ||
            (svlTyp == E_DBLType_MotorWiHallWiCL))  /* 是否配置了SWL */
        {
            posInc = MotorManage_SvlConvertAngleIncreToPosIncre(swl*RAD_PER_DEG);
            MotorManage_SetSwivelingPosIncre(E_SvlFunction_AFS, posInc);
            svlErr = MotorManage_GetSwivelingFuncErrorState();
            svlSts = SwivelingMotor_GetSvlRefRunSts();
            if (svlErr.Bits.SigErr_AFS || svlErr.Bits.MotErr_AFS || 
                ((svlSts != E_SvlRefRunSts_Done) && (svlSts != E_SvlRefRunSts_During)))
            { fbSMSwl = STS_ERR; }
        }

        /* 角灯 */
        if ((_ctl->st_vcew == VCEW_V) && (_ctl->pr_TOWN_CORN == 1))
        { CorneringLight_SetPwmOfAFS(_ctl->pr_TOWN_CorLgt_Perc); }
        /* CL Channel Error */
        if (((err->chnErr && afsctl.pr_infoCORN.chnMask) != 0) ||
            ((err->ntcErr && afsctl.pr_infoCORN.chnMask) != 0))
        { fbCORN = STS_ERR; }
        /* CL NTC Error */
        if ((errDTC->ntcErr && afsctl.pr_infoCORN.chnMask) != 0)
        { fbCORN = STS_ERR; }

        /* 雾灯 */
        if ((_ctl->st_vcew == VCEW_W) && (_ctl->pr_AWL_FOG == 1))
        { FogLamp_SetPwmOfAFS(100); }
        /* FOG Channel Error */
        if (((err->chnErr && afsctl.pr_infoFOG.chnMask) != 0) ||
            ((err->ntcErr && afsctl.pr_infoFOG.chnMask) != 0))
        { fbFOG = STS_ERR; }
        /* FOG NTC Error */
        if ((errDTC->ntcErr && afsctl.pr_infoFOG.chnMask) != 0)
        { fbFOG = STS_ERR; }

        /* 日行灯故障, AFS不反馈故障 */
        /*  fbDRL = afsctl.st_sts.StsDRL;  */

        /* LB Channel Error */
        if (((err->chnErr & afsctl.pr_infoLBflat.chnMask) != 0) ||
            ((err->mtxErr & afsctl.pr_infoLBflat.mtxMask) != 0) ||
            ((err->chnErr & afsctl.pr_infoLBkink.chnMask) != 0) ||
            ((err->mtxErr & afsctl.pr_infoLBkink.mtxMask) != 0))
        {
            fbLB = STS_ERR;
        }
        /* LB NTC Error */
        if (((errDTC->ntcErr & afsctl.pr_infoLBflat.chnMask) != 0) ||
            ((errDTC->ntcErr & afsctl.pr_infoLBkink.chnMask) != 0))
        {
            fbLB = STS_ERR;
        }

        /* FeedBack */
        if ((fbLB   == STS_ERR) ||
            /*  (fbDRL  == STS_ERR) ||  */
            (fbCORN == STS_ERR) ||
            (fbFOG  == STS_ERR) ||
            (fbSMLvl == STS_ERR) ||
            (fbSMSwl == STS_ERR))
        {
            SetLgtStsFb_AFS(STS_ERR);
        }
        else
        {
            SetLgtStsFb_AFS(STS_ON);
        }

        if (fbLB   == STS_ERR) { SetLgtStsFb_LB  (STS_ERR); } else { SetLgtStsFb_LB(STS_ON); }
        if (fbCORN == STS_ERR) { SetLgtStsFb_CORN(STS_ERR); }
        if (fbFOG  == STS_ERR) { SetLgtStsFb_FOG (STS_ERR); }

    }
}

E_VCEW_t  AFS_Get_cvew(void)
{
    if (_ctl == 0) { return VCEW_U; }
    else           
    {
        if (_ctl->st_turnOnOff0 == 0) { return VCEW_U; }
        else                          { return _ctl->st_vcew; }
    }
}

const uint8_t * AFS_Get_PixPercHead(void)
{
    if (_ctl == 0) { return Get_pLowBeamPWMPixel_head(); }
    else           { return _ctl->st_LBkinkPixPerc; }
}
