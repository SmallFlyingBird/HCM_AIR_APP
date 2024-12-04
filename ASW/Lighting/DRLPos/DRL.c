


/* ASW Interface */
#include "HcmPlatform.h"
#include "GeneralFunction.h"
/* Lighting Base */
#include "Lighting.h"
#include "LampManager.h"

#include "DRL.h"

typedef struct _DRLCtl_
{
    uint8_t     pr_DRLPOStype;      /* 0:共用通道；1:独立通道；2:部分共用通道 */

    uint16_t    pr_onRamp_DRL;
    uint16_t    pr_offRamp_DRL;

    uint8_t     pr_percDRLTI;       /* 共用时，亮度百分比 */
    uint8_t     pr_percDRLTI40mm;   /* 40mm时，亮度百分比 */
    uint16_t    pr_uptimeDRLTI;     /* 共用效果 延时时间 */

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
static void act_on_DRL(uint8_t TIstsOn1)
{

}

void DRL_Init(void)
{

}

void DRL_Exit(void)
{

}

void DRL_Run_(unsigned int ms)
{

}

void DRL_Run_On(void)
{
 
}
