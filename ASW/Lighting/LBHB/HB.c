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
/* Lighting Base */
#include "LampManager.h"
#include "Lighting.h"

#include "HB.h"


typedef struct _HBCtl_
{
    // S_LF_Info_T     pr_infoHBsail;    /* HBsail灯光 灯配置信息 */
    // S_LF_Info_T     pr_infoHBspot;    /* HBspot灯光 灯配置信息 */

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

static void act_on_HBsail()
{

}
static void act_on_HBspot()
{

}

static void act_off_HBsail()
{

}

static void act_off_HBspot()
{

}


void HB_Init(void)
{
    uint16_t u16v;

    /*  */
    C_Memset_B((uint8_t*)(&(hbctl)), 0, sizeof(S_HBCtl_t));

    // lampM_GetLampInfo(E_HighBeamSail, &(hbctl.pr_infoHBsail));
    // lampM_GetLampInfo(E_HighBeamSpot, &(hbctl.pr_infoHBspot));

    hbctl.pr_PixMode = 1;
    hbctl.pr_SAE0_ECE1 = 0;

    /* N-1 */
    if ((u16v & 0x0004) != 0) { hbctl.pr_N_1 = 1; }


    // _pixHB = Get_pHighBeamPWMPixel_B_head();

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
        // if (hbctl.pr_infoHBsail.being)
        // {
        //     act_off_HBsail();
        // }
        // if (hbctl.pr_infoHBspot.being)
        // {
        //     act_off_HBspot();
        // }

        SetLgtStsFb_HB(STS_OFF);

        /* CTS-6.4.4 */
        /* if (_ctl->st_actHB == ACT_ON)
        { SetLgtStsFb_HB(STS_ERR); } */
    }
}

void HB_Run_On(void)
{
  
}

