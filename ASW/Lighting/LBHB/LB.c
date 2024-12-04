/**
 * @file LB.c
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
#include "Fan.h"
#include "LB.h"


typedef struct _LBCtl_
{
    uint8_t         pr_PixMode          :2; /* LB/HB共用LED模式 "Light Control":"pPxlModuleType" */
    /* 法规相关 */
    uint8_t         pr_SAE0_ECE1        :1; /* 0:SAE规范; 1:ECE规范 */

    uint8_t         pr_LogoLBPOS        :2; /* logo灯作为LB/POS的一部分标识 "Light Control":"pLogoLowbeamPOS" */
    uint8_t         pr_res_b8           :3; /* 保留 */
    
    uint16_t        pr_onRampLBflat;
    uint16_t        pr_onRampLBkink;
    uint16_t        pr_offRampLBflat;
    uint16_t        pr_offRampLBkink;

    /* 功能安全相关 */
    uint8_t         st_usagemode;       /* 车辆模式 */
    uint32_t        st_speed;           /* 车速 m/h */

    uint8_t         st_actLB    :1;     /* 0:act; 1:un-act */
    uint8_t         st_enaLB    :1;     /* 0:disable; 1:enable */
    uint8_t         st_turnLB   :1;     /* 0:turn off; 1:turn on */
    uint8_t         st_res_b8   :5;

    uint8_t         st_res_B4;

    /*  */
    S_LF_Err_T      st_err;     /* 动作故障(实时) */
    S_LF_Err_T      st_errDTC;  /* 动作故障(已报DTC) */

}S_LBCtl_t;

static       S_LBCtl_t  lbctl, *_ctl = 0;
static const uint8_t   *pr_pixLB;     /* 配置的LB各像素PWM */


static void act_on_LBflat()
{

}
static void act_on_LBkink()
{
   
}


static void act_off_LBflat()
{

}
static void act_off_LBkink()
{
 
}


static void lamp_check(void)
{
    
}


void LB_Init(void)
{
    /*  */
    C_Memset_B((uint8_t*)(&(lbctl)), 0, sizeof(S_LBCtl_t));
    
    // lampM_GetLampInfo(E_LowBeamFlat,  &(lbctl.pr_infoLBflat));
    // lampM_GetLampInfo(E_LowBeamKink,  &(lbctl.pr_infoLBkink));

    lbctl.pr_PixMode = 1;
    lbctl.pr_SAE0_ECE1 = 0;


    _ctl = &lbctl;
}

void LB_Exit(void)
{

}

void LB_Run_(uint16_t ms)
{

}

void LB_Run_On(void)
{

}

