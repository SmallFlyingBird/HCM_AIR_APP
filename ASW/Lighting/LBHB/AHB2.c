

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

#include "AHB2.h"


typedef struct _AHB2Ctl_
{
    S_LF_Info_T pr_infoLBflat;    /* LBflat灯光 灯配置信息 */
    S_LF_Info_T pr_infoLBkink;    /* LBkink灯光 灯配置信息 */
    S_LF_Info_T pr_infoHBsail;    /* HBsail灯光 灯配置信息 */
    S_LF_Info_T pr_infoHBspot;    /* HBspot灯光 灯配置信息 */

    uint8_t     pr_EnaAHB2      :1;
    uint8_t     pr_FlgLe0Ri     :1;

    uint8_t     pr_N_1          :1; /* 0:能亮则亮; 1:1灭全灭 */

    uint8_t     pr_NoOfpixels;              /* PIX数量(N.A.), "DBLLvlAHB":"pNoOfpixels" */

    uint16_t    pr_AHBCDistOfHB;            /* AHB远光距离, "DBLLvlAHB":"pAHBCDistOfHiBeam", (m) */
    uint16_t    pr_AHBCDistOfLB;            /* AHB近光距离, "DBLLvlAHB":"pAHBCDistOfLoBeam", (m) */
    uint16_t    pr_OncmngDist[9];           /* 来车距离分段, "DBLLvlAHB":"pAHB2OncmngDist1-9", (m) */
    double      pr_OncmngLvlOfs[10];        /* 来车距离分段电机角度, "DBLLvlAHB":"pLVLOffsetLe/RiAHB2OncmngDist1-9", (度) */
    uint16_t    pr_PrecedDist[9];           /* 去车距离分段, "DBLLvlAHB":"pAHB2PrecdngDist1-9", (m) */
    double      pr_PrecedLvlOfs[10];        /* 去车距离分段电机角度, "DBLLvlAHB":"pLVLOffsetLe/RiAHB2PrecdngDist1-9", (度) */
    uint16_t    pr_AHB2FrznTi;              /* ? */
    uint8_t     pr_SftyMrgnOnCmng;
    uint8_t     pr_SftyMrgnPreced;
    uint8_t     pr_AHB2LBflatInt;
    uint8_t     pr_AHB2LBkinkInt;
    uint8_t     pr_AHB2HBspotInt;
    uint8_t     pr_AHB2HBsailInt;
    uint16_t    pr_AHB2ChngOvrTime;

    /* AHB2 On1/Off0 */
    uint8_t     st_turnOn1_AHB2 :1;
    uint8_t     st_turnOn1_HB   :1;

}S_ahb2ctl_t;

static       S_ahb2ctl_t    ahb2ctl;    /* 初始化时使用 */
static       S_ahb2ctl_t   *_ctl = 0;   /* 初始化后使用 */
static const uint8_t       *_pixLB;     /* 配置的LB各像素PWM */
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

static void act_on_LBflat(uint8_t pe)
{
    Light_Functions func = E_LowBeamFlat;
    uint16_t        chnM = _ctl->pr_infoLBflat.chnMask;
    uint8_t         perc = pe;
    uint16_t        ton  = 0;
    uint16_t        toff = 0;

    /*  */
    LampM_SetLampChn(func, chnM, perc, ton, toff);  /* 无矩阵通道 */

}
static void act_on_LBkink(uint8_t pe)
{
    Light_Functions func = E_LowBeamKink;
    uint16_t        chnM = _ctl->pr_infoLBkink.chnMask;
    uint16_t        mtxM = _ctl->pr_infoLBkink.mtxMask;
    uint8_t         perc = pe;
    uint16_t        ton  = 0;
    uint16_t        toff = 0;

    _act_use_PixPerc(func, chnM, mtxM, perc, ton, toff, 1, _pixLB);
}
static void act_on_HBsail(uint8_t pe)
{
    Light_Functions func = E_HighBeamSail;
    uint16_t        chnM = _ctl->pr_infoHBsail.chnMask;
    uint16_t        mtxM = _ctl->pr_infoHBsail.mtxMask;
    uint8_t         perc = pe;
    uint16_t        ton  = 0;
    uint16_t        toff = 0;

    /*  */
    _act_use_PixPerc(func, chnM, mtxM, perc, ton, toff, 1, _pixHB);
}
static void act_on_HBspot(uint8_t pe)
{
    Light_Functions func = E_HighBeamSpot;
    uint16_t        chnM = _ctl->pr_infoHBspot.chnMask;
    uint16_t        mtxM = _ctl->pr_infoHBspot.mtxMask;
    uint8_t         perc = pe;
    uint16_t        ton  = 0;
    uint16_t        toff = 0;

    /*  */
    _act_use_PixPerc(func, chnM, mtxM, perc, ton, toff, 1, _pixHB);
}



void AHB2_Init(void)
{
    uint8_t u8v;

    C_Memset_B((uint8_t*)(&ahb2ctl), 0, sizeof(S_ahb2ctl_t));

    lampM_GetLampInfo(E_LowBeamFlat,  &(ahb2ctl.pr_infoLBflat));
    lampM_GetLampInfo(E_LowBeamKink,  &(ahb2ctl.pr_infoLBkink));
    lampM_GetLampInfo(E_HighBeamSail, &(ahb2ctl.pr_infoHBsail));
    lampM_GetLampInfo(E_HighBeamSpot, &(ahb2ctl.pr_infoHBspot));

    ahb2ctl.pr_EnaAHB2 = 1;
    /* 水平电机配置信息, "DBLLvlAHB":"pVehLvlType" */
    /* u8v = Get_pVehLvLType(); if (u8v != 2) { ahb2ctl.pr_EnaAHB2 = 0; } */
    /* AHB类型, "DBLLvlAHB":"pAHBCTyp" */
    u8v = Get_pAHBCType();   if (u8v != 2) { ahb2ctl.pr_EnaAHB2 = 0; }

    ahb2ctl.pr_FlgLe0Ri = 0;

    ahb2ctl.pr_AHBCDistOfHB = Get_pAHBCDistOfHiBeam();
    /* ahb2ctl.pr_AHBCDistOfLB = Get_pAHBCDistOfLoBeam(); */

    ahb2ctl.pr_OncmngDist[0] = Get_pAHB2OncmngDist1();
    ahb2ctl.pr_OncmngDist[1] = Get_pAHB2OncmngDist2();
    ahb2ctl.pr_OncmngDist[2] = Get_pAHB2OncmngDist3();
    ahb2ctl.pr_OncmngDist[3] = Get_pAHB2OncmngDist4();
    ahb2ctl.pr_OncmngDist[4] = Get_pAHB2OncmngDist5();
    ahb2ctl.pr_OncmngDist[5] = Get_pAHB2OncmngDist6();
    ahb2ctl.pr_OncmngDist[6] = Get_pAHB2OncmngDist7();
    ahb2ctl.pr_OncmngDist[7] = Get_pAHB2OncmngDist8();
    ahb2ctl.pr_OncmngDist[8] = Get_pAHB2OncmngDist9();

    if (ahb2ctl.pr_FlgLe0Ri == 0)
    {
    ahb2ctl.pr_OncmngLvlOfs[0] = (0.1 * Get_LeLamp_pLVLOffsetLeAHB2OncmngDist1() ) - 50;
    ahb2ctl.pr_OncmngLvlOfs[1] = (0.1 * Get_LeLamp_pLVLOffsetLeAHB2OncmngDist2() ) - 50;
    ahb2ctl.pr_OncmngLvlOfs[2] = (0.1 * Get_LeLamp_pLVLOffsetLeAHB2OncmngDist3() ) - 50;
    ahb2ctl.pr_OncmngLvlOfs[3] = (0.1 * Get_LeLamp_pLVLOffsetLeAHB2OncmngDist4() ) - 50;
    ahb2ctl.pr_OncmngLvlOfs[4] = (0.1 * Get_LeLamp_pLVLOffsetLeAHB2OncmngDist5() ) - 50;
    ahb2ctl.pr_OncmngLvlOfs[5] = (0.1 * Get_LeLamp_pLVLOffsetLeAHB2OncmngDist6() ) - 50;
    ahb2ctl.pr_OncmngLvlOfs[6] = (0.1 * Get_LeLamp_pLVLOffsetLeAHB2OncmngDist7() ) - 50;
    ahb2ctl.pr_OncmngLvlOfs[7] = (0.1 * Get_LeLamp_pLVLOffsetLeAHB2OncmngDist8() ) - 50;
    ahb2ctl.pr_OncmngLvlOfs[8] = (0.1 * Get_LeLamp_pLVLOffsetLeAHB2OncmngDist9() ) - 50;
    ahb2ctl.pr_OncmngLvlOfs[9] = (0.1 * Get_LeLamp_pLVLOffsetLeAHB2OncmngDist10()) - 50;
    }
    else
    {
    ahb2ctl.pr_OncmngLvlOfs[0] = (0.1 * Get_RiLamp_pLVLOffsetRiAHB2OncmngDist1() ) - 50;
    ahb2ctl.pr_OncmngLvlOfs[1] = (0.1 * Get_RiLamp_pLVLOffsetRiAHB2OncmngDist2() ) - 50;
    ahb2ctl.pr_OncmngLvlOfs[2] = (0.1 * Get_RiLamp_pLVLOffsetRiAHB2OncmngDist3() ) - 50;
    ahb2ctl.pr_OncmngLvlOfs[3] = (0.1 * Get_RiLamp_pLVLOffsetRiAHB2OncmngDist4() ) - 50;
    ahb2ctl.pr_OncmngLvlOfs[4] = (0.1 * Get_RiLamp_pLVLOffsetRiAHB2OncmngDist5() ) - 50;
    ahb2ctl.pr_OncmngLvlOfs[5] = (0.1 * Get_RiLamp_pLVLOffsetRiAHB2OncmngDist6() ) - 50;
    ahb2ctl.pr_OncmngLvlOfs[6] = (0.1 * Get_RiLamp_pLVLOffsetRiAHB2OncmngDist7() ) - 50;
    ahb2ctl.pr_OncmngLvlOfs[7] = (0.1 * Get_RiLamp_pLVLOffsetRiAHB2OncmngDist8() ) - 50;
    ahb2ctl.pr_OncmngLvlOfs[8] = (0.1 * Get_RiLamp_pLVLOffsetRiAHB2OncmngDist9() ) - 50;
    ahb2ctl.pr_OncmngLvlOfs[9] = (0.1 * Get_RiLamp_pLVLOffsetRiAHB2OncmngDist10()) - 50;
    }
    
    ahb2ctl.pr_PrecedDist[0] = Get_pAHB2PrecdngDist1();
    ahb2ctl.pr_PrecedDist[1] = Get_pAHB2PrecdngDist2();
    ahb2ctl.pr_PrecedDist[2] = Get_pAHB2PrecdngDist3();
    ahb2ctl.pr_PrecedDist[3] = Get_pAHB2PrecdngDist4();
    ahb2ctl.pr_PrecedDist[4] = Get_pAHB2PrecdngDist5();
    ahb2ctl.pr_PrecedDist[5] = Get_pAHB2PrecdngDist6();
    ahb2ctl.pr_PrecedDist[6] = Get_pAHB2PrecdngDist7();
    ahb2ctl.pr_PrecedDist[7] = Get_pAHB2PrecdngDist8();
    ahb2ctl.pr_PrecedDist[8] = Get_pAHB2PrecdngDist9();

    if (ahb2ctl.pr_FlgLe0Ri == 0)
    {
    ahb2ctl.pr_PrecedLvlOfs[0] = (0.1 * Get_LeLamp_pLVLOffsetLeAHB2PrecdngDist1() ) - 50;
    ahb2ctl.pr_PrecedLvlOfs[1] = (0.1 * Get_LeLamp_pLVLOffsetLeAHB2PrecdngDist2() ) - 50;
    ahb2ctl.pr_PrecedLvlOfs[2] = (0.1 * Get_LeLamp_pLVLOffsetLeAHB2PrecdngDist3() ) - 50;
    ahb2ctl.pr_PrecedLvlOfs[3] = (0.1 * Get_LeLamp_pLVLOffsetLeAHB2PrecdngDist4() ) - 50;
    ahb2ctl.pr_PrecedLvlOfs[4] = (0.1 * Get_LeLamp_pLVLOffsetLeAHB2PrecdngDist5() ) - 50;
    ahb2ctl.pr_PrecedLvlOfs[5] = (0.1 * Get_LeLamp_pLVLOffsetLeAHB2PrecdngDist6() ) - 50;
    ahb2ctl.pr_PrecedLvlOfs[6] = (0.1 * Get_LeLamp_pLVLOffsetLeAHB2PrecdngDist7() ) - 50;
    ahb2ctl.pr_PrecedLvlOfs[7] = (0.1 * Get_LeLamp_pLVLOffsetLeAHB2PrecdngDist8() ) - 50;
    ahb2ctl.pr_PrecedLvlOfs[8] = (0.1 * Get_LeLamp_pLVLOffsetLeAHB2PrecdngDist9() ) - 50;
    ahb2ctl.pr_PrecedLvlOfs[9] = (0.1 * Get_LeLamp_pLVLOffsetLeAHB2PrecdngDist10()) - 50;
    }
    else
    {
    ahb2ctl.pr_PrecedLvlOfs[0] = (0.1 * Get_RiLamp_pLVLOffsetRiAHB2PrecdngDist1() ) - 50;
    ahb2ctl.pr_PrecedLvlOfs[1] = (0.1 * Get_RiLamp_pLVLOffsetRiAHB2PrecdngDist2() ) - 50;
    ahb2ctl.pr_PrecedLvlOfs[2] = (0.1 * Get_RiLamp_pLVLOffsetRiAHB2PrecdngDist3() ) - 50;
    ahb2ctl.pr_PrecedLvlOfs[3] = (0.1 * Get_RiLamp_pLVLOffsetRiAHB2PrecdngDist4() ) - 50;
    ahb2ctl.pr_PrecedLvlOfs[4] = (0.1 * Get_RiLamp_pLVLOffsetRiAHB2PrecdngDist5() ) - 50;
    ahb2ctl.pr_PrecedLvlOfs[5] = (0.1 * Get_RiLamp_pLVLOffsetRiAHB2PrecdngDist6() ) - 50;
    ahb2ctl.pr_PrecedLvlOfs[6] = (0.1 * Get_RiLamp_pLVLOffsetRiAHB2PrecdngDist7() ) - 50;
    ahb2ctl.pr_PrecedLvlOfs[7] = (0.1 * Get_RiLamp_pLVLOffsetRiAHB2PrecdngDist8() ) - 50;
    ahb2ctl.pr_PrecedLvlOfs[8] = (0.1 * Get_RiLamp_pLVLOffsetRiAHB2PrecdngDist9() ) - 50;
    ahb2ctl.pr_PrecedLvlOfs[9] = (0.1 * Get_RiLamp_pLVLOffsetRiAHB2PrecdngDist10()) - 50;
    }

    ahb2ctl.pr_AHB2FrznTi = Get_pAHB2FrznTi();

    ahb2ctl.pr_AHB2LBflatInt = Get_pAHB2LightLoBeamFlatInt();
    ahb2ctl.pr_AHB2LBkinkInt = Get_pAHB2LightLoBeamKinkInt();
    ahb2ctl.pr_AHB2HBspotInt = Get_pAHB2LightHiBeamSpotInt();
    ahb2ctl.pr_AHB2HBsailInt = Get_pAHB2LightHiBeamSailInt();

    _pixLB = Get_pLowBeamPWMPixel_head();
    _pixHB = Get_pHighBeamPWMPixel_B_head();

    _ctl = &ahb2ctl;
}

static void vheobj_calu(S_AHBCObj_t *obj, uint8_t *prec, double *deg)
{
    *prec = 100;    /* 开灯强度 */
    *deg = 0;       /* 电机目标角度 */

    /* 根据识别到的车辆，调整电机和亮度 */
    if (obj->Classn == 1)
    {
        if((obj->Dist < _ctl->pr_AHBCDistOfHB) &&
           (obj->Dist > _ctl->pr_AHBCDistOfLB))
        {
            if (obj->OnCmng != 2)    /* 来车, 默认来车 */
            {   /* 由小到大依次判断 */
                if (obj->Dist > _ctl->pr_OncmngDist[8]) { *deg = _ctl->pr_OncmngLvlOfs[8]; }
                if (obj->Dist > _ctl->pr_OncmngDist[7]) { *deg = _ctl->pr_OncmngLvlOfs[7]; }
                if (obj->Dist > _ctl->pr_OncmngDist[6]) { *deg = _ctl->pr_OncmngLvlOfs[6]; }
                if (obj->Dist > _ctl->pr_OncmngDist[5]) { *deg = _ctl->pr_OncmngLvlOfs[5]; }
                if (obj->Dist > _ctl->pr_OncmngDist[4]) { *deg = _ctl->pr_OncmngLvlOfs[4]; }
                if (obj->Dist > _ctl->pr_OncmngDist[3]) { *deg = _ctl->pr_OncmngLvlOfs[3]; }
                if (obj->Dist > _ctl->pr_OncmngDist[2]) { *deg = _ctl->pr_OncmngLvlOfs[2]; }
                if (obj->Dist > _ctl->pr_OncmngDist[1]) { *deg = _ctl->pr_OncmngLvlOfs[1]; }
                if (obj->Dist > _ctl->pr_OncmngDist[0]) { *deg = _ctl->pr_OncmngLvlOfs[0]; }
            }
            else                            /* 去车 */
            {
                /* 由小到大依次判断 */
                if (obj->Dist > _ctl->pr_PrecedDist[8]) { *deg = _ctl->pr_PrecedLvlOfs[8]; }
                if (obj->Dist > _ctl->pr_PrecedDist[7]) { *deg = _ctl->pr_PrecedLvlOfs[7]; }
                if (obj->Dist > _ctl->pr_PrecedDist[6]) { *deg = _ctl->pr_PrecedLvlOfs[6]; }
                if (obj->Dist > _ctl->pr_PrecedDist[5]) { *deg = _ctl->pr_PrecedLvlOfs[5]; }
                if (obj->Dist > _ctl->pr_PrecedDist[4]) { *deg = _ctl->pr_PrecedLvlOfs[4]; }
                if (obj->Dist > _ctl->pr_PrecedDist[3]) { *deg = _ctl->pr_PrecedLvlOfs[3]; }
                if (obj->Dist > _ctl->pr_PrecedDist[2]) { *deg = _ctl->pr_PrecedLvlOfs[2]; }
                if (obj->Dist > _ctl->pr_PrecedDist[1]) { *deg = _ctl->pr_PrecedLvlOfs[1]; }
                if (obj->Dist > _ctl->pr_PrecedDist[0]) { *deg = _ctl->pr_PrecedLvlOfs[0]; }
            }
        }
        if (obj->Dist <= _ctl->pr_AHBCDistOfLB)
        {
            /* ...调光百分比判断... */

        }
    }
}

void AHB2_Exit(void)
{
    _ctl = 0;
}

void AHB2_Run_On(void)
{
    uint8_t perc;   /* 调光百分比 */
    double  deg;    /* LVL调节角度 */
    sint16_t posInc;

    S_LgtFuncEna_t ena;
    S_LgtActIns_t  act;
    S_LF_Err_T     err;
    S_LF_Err_T     errDTC;
    S_AHBCObj_t    obj;

    if (_ctl == 0) return;
    if (_ctl->pr_EnaAHB2 == 0) return;

    GetLgtFuncEna(&ena);
    GetLgtActIns (&act);
    LampM_GetLampBaseErr(&(err));
    LampM_GetLampBaseErr_DTC(&(errDTC));

    Get_AHBCObj(&obj);

#if (DEBUG_LIGHTING_AHB2)

#endif

    /* AHB2 Turn On? */
    if ((ena.EnaAHBC == ENA_ON) &&
        ((act.ActHB == ENA_OFF) && (act.ActAHBC == ACT_ON)) &&
        (obj.CamSts == 1) &&
        (obj.TooMany == 0) &&
        (obj.LitArea == 0))
    { _ctl->st_turnOn1_AHB2 = 1; }
    else
    { _ctl->st_turnOn1_AHB2 = 0; }

    if ((act.ActHB == ENA_OFF) && (act.ActAHBC == ACT_ON))
    { MotorManage_SetLevelingFuncActState(E_LvlFunction_AHB2, _ctl->st_turnOn1_AHB2); }
    else
    { MotorManage_SetLevelingFuncActState(E_LvlFunction_AHB2, _ctl->st_turnOn1_AHB2); }
    

    /* Trun On */
    if (_ctl->st_turnOn1_AHB2)
    {
        vheobj_calu(&obj, &perc, &deg);

        /* LVL Motor */
        posInc = MotorManage_LvlConvertAglIncreToPosIncre(deg*RAD_PER_DEG);
        MotorManage_SetLevelingPosIncre(E_LvlFunction_AHB2, posInc);

        /* LEDs */
        if (_ctl->pr_infoLBflat.being)
        {
            act_on_LBflat(_ctl->pr_AHB2LBflatInt);
        }
        if (_ctl->pr_infoLBkink.being)
        {
            act_on_LBkink(_ctl->pr_AHB2LBkinkInt);
        }
        if (_ctl->pr_infoHBsail.being)
        {
            act_on_HBsail(_ctl->pr_AHB2HBsailInt);
        }
        if (_ctl->pr_infoHBspot.being)
        {
            act_on_HBspot(_ctl->pr_AHB2HBspotInt);
        }

        SetLgtStsFb_AHBC(STS_ON);
        SetLgtStsFb_HB(STS_ON);

        /* Channel Error */
        if (((err.chnErr & _ctl->pr_infoLBflat.chnMask) != 0) ||
            ((err.mtxErr & _ctl->pr_infoLBflat.mtxMask) != 0) ||
            ((err.chnErr & _ctl->pr_infoLBkink.chnMask) != 0) ||
            ((err.mtxErr & _ctl->pr_infoLBkink.mtxMask) != 0) ||
            ((err.chnErr & _ctl->pr_infoHBsail.chnMask) != 0) ||
            ((err.mtxErr & _ctl->pr_infoHBsail.mtxMask) != 0) ||
            ((err.chnErr & _ctl->pr_infoHBspot.chnMask) != 0) ||
            ((err.mtxErr & _ctl->pr_infoHBspot.mtxMask) != 0))
        {
            SetLgtStsFb_AHBC(STS_ERR);
            SetLgtStsFb_HB(STS_ERR);

            if (_ctl->pr_N_1) { ; }
        }

        /* NTC Error */
        if (((errDTC.ntcErr & _ctl->pr_infoLBflat.chnMask) != 0) ||
            ((errDTC.ntcErr & _ctl->pr_infoLBkink.chnMask) != 0) ||
            ((errDTC.ntcErr & _ctl->pr_infoHBsail.chnMask) != 0) ||
            ((errDTC.ntcErr & _ctl->pr_infoHBspot.chnMask) != 0))
        {
            SetLgtStsFb_AHBC(STS_ERR);
            SetLgtStsFb_HB(STS_ERR);
        }
    }
    else
    {
        /* LVL */
        MotorManage_SetLevelingPosIncre(E_LvlFunction_AHB2, 0);

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

