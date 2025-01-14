/* ASW Interface */
#include "HcmPlatform.h"
#include "GeneralFunction.h"
#include "Parameter_Interface.h"
#include "ComSignal_Interface.h"
/* Lighting Base */
#include "Lighting.h"
#include "LampManager.h"
#include "POS.h"

typedef struct _POSCtl_
{
    uint8_t     pr_DRLPOStype;      /* 0:共用通道；1:独立通道；2:部分共用通道 */
    uint16_t    pr_onRamp_POS;
    uint16_t    pr_offRamp_POS;

    uint8_t     pr_percPOSDRL;      /* POS与DRL共用时的亮度 */
    uint8_t     pr_percPOSTI;       /* ECE:共用时亮度百分比 */
    uint16_t    pr_uptimePOSTI;     /* 共用效果 延时时间 */

    uint16_t    pr_chnMask_PosDRL;  /* POS与DRL通道共用 通道标识 */
    uint16_t    pr_appaMask_POSTI;  /* POS与TI发光面共用 通道标识 */

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


void POS_Init(void)
{
    uint16_t u16v;
    C_Memcpy_B((uint8_t*)(&posctl), 0, sizeof(S_POSCtl_t));

    posctl.pr_onRamp_POS  = Get_pLedOnRampTi(E_PositionLight);
    posctl.pr_offRamp_POS = Get_pLedOffRampTi(E_PositionLight);
    posctl.pr_appaMask_POSTI = Get_POS_TI_surfaces_apparent();
    posctl.pr_percPOSDRL = Get_pLedIntensityPos();
    posctl.pr_percPOSTI = Get_pLedIntensityPosTi();
    posctl.pr_uptimePOSTI = Get_pLedTimeUpPosTi();
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

}


void POS_Run_On(void)
{
   
}
