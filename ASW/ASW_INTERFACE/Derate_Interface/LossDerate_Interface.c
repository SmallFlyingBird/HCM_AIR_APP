/**
 * @file LossDerate_Interface.c
 * @author QinHaigang (qinhaigang@xyl.cn)
 * @brief 
 * @version 0.1
 * @date 2024-05-07
 * 
 * @copyright Copyright (c) 2024-  New Elec. Dept. XYL
 * 
 * @par History:
 * <table>
 * <tr><th>Data       <th>Version <th>Author     <th>Description
 * <tr><td>2024-05-07 <td>0.1     <td>QinHaigang <td>
 * </table>
 */

#include "HcmPlatform.h"
#include "GeneralFunction.h"
#include "Parameter_Interface.h"
#include "DTC_Interface.h"
#include "ComSignal_Interface.h"

#include "LossDerate_Interface.h"

static uint8_t LossDerateRatio[MAX_CHANNLE_NUM] = {100, 100, 100, 100, 100, 100};

typedef struct _LossDerateCtl_
{
    uint8_t     pr_Geely    :1;         /* Geely CTS flag */
    uint8_t     pr_GeelyLB;             /* Geely LB derate to 55% */

    uint16_t    pr_mask[NUM_DER_LGT];   /* every lighting channel mask */
    uint16_t    pr_Rate[NUM_DER_LGT];   /* every lighting rated power (0.1W) */
    
    uint16_t    pr_1P;                  /* 1 power supply, 600 (0.1W) */
    uint16_t    pr_2P_Hi;               /* 2 power supply High, 1300 (0.1W) */
    uint16_t    pr_2P_Lo;               /* 2 power supply Low,  1200 (0.1W) */

    uint8_t     in_loss     :1;         /* 1 power supply lost flag */

    uint16_t    st_Avai;                /* Available Power (0.1W) */

}S_LossDerateCtl_t;

static S_LossDerateCtl_t    lossctl;
static S_LossDerateCtl_t   *_ctl = 0;

static 
void cal_derate(S_DerateLight_t dlgt, uint16_t avai, uint8_t *pDer)
{
  
}

uint8_t 
Interface_GetChannelDerateRatioOfLoss(E_ChannelID id)
{

}