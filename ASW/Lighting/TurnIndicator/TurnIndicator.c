/**
 * @file TurnIndicator.c
 * @author QinHaigang (qinhaigang@xyl.cn)
 * @brief 
 * @version 0.2
 * @date 2024-05-10
 * 
 * @copyright Copyright (c) 2024-  New Elec. Dept. XYL
 * 
 * @par History:
 * <table>
 * <tr><th>Data       <th>Version <th>Author     <th>Description
 * <tr><td>2024-05-06 <td>0.1     <td>QinHaigang <td>First
 * <tr><td>2024-05-10 <td>0.2     <td>QinHaigang <td>未定义流水单元做普通转向的亮灭动作
 * </table>
 */

/* Base Include */
#include "HcmPlatform.h"
#include "GeneralFunction.h"
/* Lighting Include */
#include "LampManager.h"
#include "Lighting.h"

#include "TurnIndicator.h"


typedef enum _TIS_
{
    TIS_OFF = 0,
    TIS_LEON,
    TIS_RION,
    TIS_LERION
}e_TIS_t;
typedef enum _SW_
{
    SS_ON = 0,
    SS_OFF
}e_SS_t;
typedef enum _FBS_
{
    FBS_OFF = 0,
    FBS_ON,
    FBS_ERR,
    FBS_Res
}e_FBS_T;


/* pr_:配置参数, in_:控制输入, ou_:控制输出, er_:错误输出, st_:中间数据 */

typedef struct _TICtl_
{
    uint8_t     pr_lr       :1; /* 左/右识别 */

    // S_LF_Info_T pr_lfinfo;      /* TI灯光配置信息 */

    uint16_t    pr_onDelay;
    uint16_t    pr_offDelay;
    uint16_t    pr_onRamp;
    uint16_t    pr_offRamp;

    uint8_t     pr_pLedSeqTiHwl;
    uint8_t     pr_pVariantTyp;
    uint16_t    pr_pSTITime;

    /* N-1 */
    uint8_t     pr_N_1              :1; /* 0:能亮则亮; 1:1灭全灭 */

    uint8_t     st_disSeqTI         :1; /* 0:不禁止流水功能；1：禁止流水功能 */

    uint8_t     st_act  :1; /* 0:deactivation; 1:activation */
    uint16_t    st_actms;   /* act翻转计时（0->1或1->0时重新开始计时） */

    // uint8_t     st_STIUnit[TI_MAX_MATRIXCHIP_NUM*MAX_MATRIXCHIP_CHANNEL_NUM];
    uint8_t     st_STIUnitIdx[13];  /* 各UNIT开头序号 */
    uint8_t     st_STIUnitNum[13];  /* 各UNIT的LED数量，暂未用先内存占位，Reserved for occupy mem */
    uint8_t     st_STInum;  /* 参与流水的UNIT个数 */
    uint8_t     st_STIcur;  /* 当前流到哪个UNIT */
    uint16_t    st_STIspa;  /* 流水间隔时间 */
    uint16_t    st_STIms;   /* 流水UNIT时间到 */

    uint8_t     st_stsTI    :1;     /*  */
    uint8_t     st_actTI    :1;     /* 0:act; 1:un-act */
    uint8_t     st_noseqTI  :1;     /* 0:seq; 1:no-seq */
    uint8_t     st_enaTI    :1;     /* 0:disable; 1:enable */
    uint8_t     st_turnTI   :1;     /* 0:turn off; 1:turn on */
    uint8_t     st_res_b8   :3;

    uint8_t     st_onErr    :1; /* 开灯故障记录，0:no; 1:yes */
    
}S_TICtl_t;

static S_TICtl_t tictl, *_ctl = 0;


static void all_on(void)
{
   
}
static void all_off(void)
{
}


static void act_on(int ms, int noseq)
{
   
}

static void act_off(int ms, int noseq)
{
   
}


int TI_Init(void)
{
    uint16_t u16v;

    C_Memset_B((uint8_t*)(&tictl), 0, sizeof(S_TICtl_t));

    // lampM_GetLampInfo(E_TurnIndicator, &(tictl.pr_lfinfo));

    tictl.pr_lr = LR_LE;

#if (DEBUG_LIGHTING_TI)
    tictl.pr_onDelay  = 0;
    tictl.pr_offDelay = 0;
    tictl.pr_onRamp   = 0;
    tictl.pr_offRamp  = 0;

    tictl.pr_pLedSeqTiHwl = 2;      /* 1:不流水; 2:TI; 4:HWL; 8:TI&HWL; o:无效; */
    tictl.pr_pVariantTyp  = 1;      /* 0:开流水; 1:关流水; 2:保留 */
    tictl.pr_pSTITime     = 800;    /* 流水时间ms */

    tictl.pr_N_1 = 0;
#else

    /* N-1 */
    if ((u16v & 0x0040) != 0) { tictl.pr_N_1 = 1; }
#endif

    // build_STIUnit();

    _ctl = &tictl;

    return 0;
}

int TI_Exit(void)
{
    _ctl = 0;
    return 0;
}

int TI_Run(uint32_t ms)
{

}

