/**
 * @file LampManager.c
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
 * <tr><td>2024-05-06 <td>0.1     <td>QinHaigang <td>
 * </table>
 */

#include "HcmPlatform.h"
#include "GeneralFunction.h"
#include "Parameter_Interface.h"
#include "SystemService_Interface.h"

#include "Buck_Interface.h"
#include "Channel_Interface.h"
#include "DerateRatioManager_Interface.h"
#include "LossDerate_Interface.h"
#include "OUVDerate_Interface.h"

#include "DTC_Interface.h"

#include "Lighting.h"
#include "LampManager.h"

#if (QINGHAIGANG) && (QHG_DMONI_orXCP)
#include "DMoni.h"
#endif  /* (QINGHAIGANG) && (QHG_DMONI_orXCP) */

#include "IOCtr_ASW.h"

/*
Channel Falut Handle means
0/other: don't intervene
1      : 3S cycle close/open
2      : disabled-close until user-close
*/
#define CHNFLT_HANDLE_MEANS     (2)

/* 电性能测试，故障不干预 */
#if (QINGHAIGANG)
#if (BUILD_PROJECT_ID == 1)
#define CHNFLT_HANDLE_MEANS     (0)
#endif  /* (BUILD_PROJECT_ID == 1) */
#endif  /* (QINGHAIGANG) */


/**
 * @brief 矩阵集 枚举
 */
typedef enum _MtxSet_
{
    MtxSet_LBHB = 0,
    MtxSet_TI,
    MtxSet_DRLPOS,
    MtxSet_GRIL,
    MtxSet_LOGO,
    MtxSet_ASSI,
    MtxSet_CROSS,
    MtxSetNum               /* 矩阵集的数量 */
} E_MtxSet_t;


/**
 * @brief 
 * 
 */
typedef struct _AimChn_
{
    uint8_t     perc;       /* 目标 工作百分比 */
    uint8_t     perc0;      /* 当前/设置 工作百分比 */

    uint16_t    ton;        /* 完整打开过程时间(ms) */
    uint16_t    toff;	    /* 完整关闭过程时间(ms) */

    uint16_t    curr;       /* 设置电流 */
    uint8_t     ppwm;       /* 实际PWM调整，作用于CHN或MTX */

    uint8_t     bFED    :1; /* 被2F或EPT强制过 */
}S_AimChn_t;


/**
 * @brief 2F DID 控制通道
 * 
 * @param chn 
 * @param curr 
 */
static void IoCtr2F_ChnCUR(E_ChannelID chn, uint16_t curr) /* 设置电流存在风险 */
{

}
static void IoCtr2F_ChnPWM(E_ChannelID chn, uint8_t perc)
{
   
}
static void IoCtr2F_ChnPWM_Reset(E_ChannelID chn)
{
  
}
/* static void IoCtr2F_ADBPixPWM(uint8_t *mask, uint8_t *perc)
{ } */
static void IoCtr2F(void)
{
  
}


static U_ChannelErrorState _LM_GetChannelState(E_ChannelID index, E_ErrorType ErrorType)
{
 
}

/*************************** Interface Functions ***************************** */


int LampM_GetLampBaseErr_DTC(S_LF_Err_T *err)
{
   
}

void LampM_Specal_LB(uint8_t spe)
{
   
}

void LampM_Specal_TI(uint8_t spe)
{
  
}