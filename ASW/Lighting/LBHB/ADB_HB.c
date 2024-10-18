



/* Base Include */
#include "HcmPlatform.h"
#include "ADBsuanfa.h"
#include "GeneralFunction.h"
#include "Parameter_Interface.h"
#include "MatrixChip_Interface.h"

/* Lighting Include */
#include "LampManager.h"
#include "Lighting.h"

/* UDS Server Include */
#include "IOCtr_ASW.h"

#include "ADB_HB.h"


typedef struct _ADBCtl_
{
    S_LF_Info_T     pr_infoLBkink;    /* LBkink灯光 灯配置信息 */
    S_LF_Info_T     pr_infoHBsail;    /* HBsail灯光 灯配置信息 */
    S_LF_Info_T     pr_infoHBspot;    /* HBspot灯光 灯配置信息 */

    uint8_t         pr_EnaADB   :1;     /* AHBC类型, "DBLLvlAHB":"pAHBCTyp" */
    uint8_t         pr_N_1      :1;     /* 0:能亮则亮; 1:1灭全灭 */

    uint8_t         st_turn;            /*  */

    /*  */
    S_LF_Err_T      st_err;     /* 动作故障(实时) */
    S_LF_Err_T      st_errDTC;  /* 动作故障(已报DTC) */

    S_LgtFuncEna_t  st_ena;
    S_LgtActIns_t   st_act;

    S_AHBCObj_t     st_obj;
}S_ADBCtl_t;

static S_ADBCtl_t       adbctl;
static S_ADBCtl_t      *_ctl = 0;
static const uint8_t   *_pixHB;     /* 配置的HB各像素PWM */

uint8  ADBled[84]={0,0,0,0,0,0,0,0,0,0,0,0};  /* 0xff:无效；0：灭；1：HB亮 */


static void _act_use_ADBPix(Light_Functions func, 
                            uint16_t        mtxM,
                            uint8_t         perc,
                            uint16_t        ton,
                            uint16_t        toff)
{
    int i, j;
    uint8_t pid[MAX_MATRIXCHIP_CHANNEL_NUM];
    uint8_t id, idx, perc1;

    /* 设置矩阵通道占空比 */
    LampM_SetLampChn(func, mtxM, 100, 0, 0);
    
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

                        perc1 = perc;                                       /* 1 */

                        if (_pixHB[idx] > 0)
                        { perc1 = _pixHB[idx]; }                            /* 2 */

                        if ((ADBled[idx] != 0xFF) && (ADBled[idx] == 0))
                        { perc1 = 0; }                                      /* 3 */

                        LampM_SetLampPix(func, id, perc1, ton, toff);
                    }
                }
            }
        }
    }
}




void ADB_HB_Init(void)
{
    uint8_t u8v;
    uint16_t u16v;

    C_Memset_B((uint8_t*)(&adbctl), 0, sizeof(S_ADBCtl_t));

    lampM_GetLampInfo(E_LowBeamKink,  &(adbctl.pr_infoLBkink));
    lampM_GetLampInfo(E_HighBeamSail, &(adbctl.pr_infoHBsail));
    lampM_GetLampInfo(E_HighBeamSpot, &(adbctl.pr_infoHBspot));

    /* Enable */
    adbctl.pr_EnaADB = 1;
    u8v = Get_pAHBCType();   if (u8v != 3) { adbctl.pr_EnaADB = 0; }

    /* N-1 */
    u16v = Get_LightN_1();
    if ((u16v & 0x0004) != 0) { adbctl.pr_N_1 = 1; }


    _pixHB = Get_pHighBeamPWMPixel_B_head();

    _ctl = &adbctl;
}

void ADB_HB_Exit(void)
{
    _ctl = 0;
}

void ADB_HB_Run_(uint16_t ms)
{
    uint8_t        adbsta;

    if (_ctl == 0) { return; }
    if (_ctl->pr_EnaADB == 0) { return; }

    GetLgtFuncEna(&_ctl->st_ena);
    GetLgtActIns (&_ctl->st_act);
    LampM_GetLampBaseErr(&(_ctl->st_err));
    LampM_GetLampBaseErr_DTC(&(_ctl->st_errDTC));

    Get_AHBCObj(&_ctl->st_obj);


    /* UDS 2F Set */
    if (diagioctr_adbpix.ctr == 3)
    {
        int i, m, n;
        for (i=0; i<MAX_ADBPIXNUM; i++)
        {
            m = i/8; n = i%8;
            if ((diagioctr_adbpix.mask[m] & (0x01<<n)) != 0)
            {
                ADBled[i] = (diagioctr_adbpix.pix[i] > 0) ? 1 : 0;
            }
            else
            {
                ADBled[i] = 0xFF;
            }
        }
        
        _ctl->st_turn = 1;
    }

    /* UDS 2F Freeze */
    if (diagioctr_adbpix.ctr == 2)
    { ; }

    /* UDS 2F Release */
    if (diagioctr_adbpix.ctr == 0)
    {
        /* 获取ADB计算状态 */
        GetADBLedsOnoffcmd(ADBled);
        adbsta = GetADBstatus();

        /* ADB动作灯光 */
        if ((adbsta != 0) && 
            (_ctl->st_ena.EnaAHBC == ENA_ON) &&
            (_ctl->st_act.ActAHBC == ENA_ON))
        { _ctl->st_turn = 1; }
        else
        {
            if((_ctl->st_act.ActAHBC == ENA_OFF)&&adbsta==ADBUADBclosewindow)
            { _ctl->st_turn = 1;}

            if((_ctl->st_act.ActAHBC == ENA_OFF)&&adbsta==ADBoffline)
            {_ctl->st_turn = 0;}
        }
    }

#if (DEBUG_LIGHTING_ADB_HB)
    _ctl->st_turn = 1;
#endif
}



void ADB_HB_Run_On(void)
{ 
    uint16_t        mtxM;
    uint8_t         perc;
    uint16_t        ton;
    uint16_t        toff;

    if (_ctl == 0) { return; }
    if (_ctl->pr_EnaADB == 0) { return; }

    if (_ctl->st_turn == 0)
    {
        SetLgtStsFb_AHBC(STS_OFF);

        /* 辅助信号故障，反馈ERROR */
        if (_ctl->st_obj.e_Classn || _ctl->st_obj.e_OnCmng || _ctl->st_obj.e_Dist) 
        { SetLgtStsFb_AHBC(STS_ERR); }

        /* CamSts信号处理 */
        if ((_ctl->st_ena.EnaAHBC == ENA_ON) &&
            ((_ctl->st_act.ActHB == ENA_OFF) && (_ctl->st_act.ActAHBC == ACT_ON)) &&
            ((_ctl->st_obj.CamSts != 1) && (_ctl->st_obj.CamSts != 3)))
        { SetLgtStsFb_AHBC(STS_ERR); }

        return;
    }

    SetLgtStsFb_AHBC(STS_ON);

    if (_ctl->pr_infoLBkink.being)
    {
        mtxM = _ctl->pr_infoLBkink.mtxMask;
        perc = 100;
        ton = 0;
        toff = 0;
        _act_use_ADBPix(E_LowBeamKink, mtxM, perc, ton, toff);
    }
    if (_ctl->pr_infoHBsail.being)
    {
        mtxM = _ctl->pr_infoHBsail.mtxMask;
        perc = 100;
        ton = 0;
        toff = 0;
        _act_use_ADBPix(E_HighBeamSail, mtxM, perc, ton, toff);
    }
    if (_ctl->pr_infoHBspot.being)
    {
        mtxM = _ctl->pr_infoHBspot.mtxMask;
        perc = 100;
        ton = 0;
        toff = 0;
        _act_use_ADBPix(E_HighBeamSpot, mtxM, perc, ton, toff);
    }

    /* LB故障 */
    /* if (((_ctl->st_err.chnErr & _ctl->pr_infoLBkink.chnMask) != 0) ||
        ((_ctl->st_err.mtxErr & _ctl->pr_infoLBkink.mtxMask) != 0))
    {
        if (FEEDERR_LATE == 0) {
            SetLgtStsFb_AHBC(STS_ERR);
            SetLgtStsFb_LB(STS_ERR);
        }

        if (((_ctl->st_errDTC.chnErr & _ctl->pr_infoLBkink.chnMask) != 0) ||
            ((_ctl->st_errDTC.mtxErr & _ctl->pr_infoLBkink.mtxMask) != 0))
        {
            SetLgtStsFb_AHBC(STS_ERR);
            SetLgtStsFb_LB(STS_ERR);
        }
    } */

    /* HB故障 */
    if (((_ctl->st_err.chnErr & _ctl->pr_infoHBsail.chnMask) != 0) ||
        ((_ctl->st_err.mtxErr & _ctl->pr_infoHBsail.mtxMask) != 0) ||
        ((_ctl->st_err.chnErr & _ctl->pr_infoHBspot.chnMask) != 0) ||
        ((_ctl->st_err.mtxErr & _ctl->pr_infoHBspot.mtxMask) != 0))
    {
        if (FEEDERR_LATE == 0) {
            SetLgtStsFb_AHBC(STS_ERR);
            SetLgtStsFb_HB(STS_ERR);
        }

        if (((_ctl->st_errDTC.chnErr & _ctl->pr_infoHBsail.chnMask) != 0) ||
            ((_ctl->st_errDTC.mtxErr & _ctl->pr_infoHBsail.mtxMask) != 0) ||
            ((_ctl->st_errDTC.chnErr & _ctl->pr_infoHBspot.chnMask) != 0) ||
            ((_ctl->st_errDTC.mtxErr & _ctl->pr_infoHBspot.mtxMask) != 0))
        {
            SetLgtStsFb_AHBC(STS_ERR);
            SetLgtStsFb_HB(STS_ERR);
        }
    }


}

