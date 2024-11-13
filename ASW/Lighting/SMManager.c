

// #include "HcmPlatform.h"
// #include "GeneralFunction.h"
// #include "Parameter_Interface.h"

// #include "Lighting.h"
// #include "MotorManage.h"

// #if (QINGHAIGANG) && (QHG_DMONI_orXCP)
// #include "DMoni.h"
// #endif  /* (QINGHAIGANG) && (QHG_DMONI_orXCP) */

// typedef struct _
// {
//     uint8_t     st_bLeveling    :2; /* 0:不动; 1:到默认位置; 2:到指定位置; 3:自动伸缩运动 */
//     uint8_t     st_bSwiveling   :2; /* 0:不动; 1:到默认位置; 2:到指定位置; 3:自动伸缩运动 */

//     double      st_degLevl;
//     double      st_degSwiv;

//     double      pr_LvlBotPos;
//     double      pr_LvlTopPos;
//     double      pr_SwlLePos;
//     double      pr_SwlRiPos;

//     uint16_t    st_ms30000;     /* 30S循环 */
// }S_SMotorM_t;

// static S_SMotorM_t smotor, *_ctl = 0;

// void SMotorM_Init(void)
// {
//     if (LR_LE == Get_FlgLR())
//     {
//         smotor.pr_LvlBotPos = Get_LeLamp_pLvlBotPosdeg();
//         smotor.pr_LvlTopPos = Get_LeLamp_pLvlTopPosdeg();
//         smotor.pr_SwlLePos  = Get_LeLamp_SvlLePosdeg();
//         smotor.pr_SwlRiPos  = Get_LeLamp_SvlRiPosdeg();
//     }
//     else
//     {
//         smotor.pr_LvlBotPos = Get_RiLamp_pLvlBotPosdeg();
//         smotor.pr_LvlTopPos = Get_RiLamp_pLvlTopPosdeg();
//         smotor.pr_SwlLePos  = Get_RiLamp_SvlLePosdeg();
//         smotor.pr_SwlRiPos  = Get_RiLamp_SvlRiPosdeg();
//     }

//     smotor.st_bLeveling = 0;
//     smotor.st_bSwiveling = 0;
//     smotor.st_ms30000 = 0;

//     _ctl = &smotor;
// }

// void SMotorM_Exit(void)
// {

//     _ctl = 0;
// }

// void SMotorM_Run10ms(void)
// {
// #if (BUILD_PROJECT_ID == 1)
// #if (QINGHAIGANG) && (QHG_DMONI_orXCP)
//     uint16_t u16v;
//     sint16_t s16v;
//     double   d32v;
//     sint16_t posInc;

// extern uint8_t test_level_autorun;
// extern uint8_t test_swive_autorun;
// #endif  /* (QINGHAIGANG) && (QHG_DMONI_orXCP) */
// #endif  /* (BUILD_PROJECT_ID == 1) */

//     if (_ctl == 0) { return; }

// #if (BUILD_PROJECT_ID == 1)
// #if (QINGHAIGANG) && (QHG_DMONI_orXCP)
//     /* DMoni强制测试 */
//     if ((DMONI_FUN(D_MOTOR)) && (DMONI_SUB(D_MOTOR) == 0))
//     {
//         _ctl->st_bLeveling  = ((dmoni_rx[D_MOTOR][1] & 0xc0)>>6);
//         _ctl->st_bSwiveling = ((dmoni_rx[D_MOTOR][3] & 0xc0)>>6);

//         /* 转换值 */
//         u16v = (dmoni_rx[D_MOTOR][1] & 0x1F);
//         u16v <<= 8;
//         u16v += dmoni_rx[D_MOTOR][2];
//         if (dmoni_rx[D_MOTOR][1] & 0x20)
//         { s16v = 0 - u16v; }
//         else
//         { s16v = u16v; }
//         d32v = s16v / 100;

//         _ctl->st_degLevl = d32v;

//         /* 转换值 */
//         u16v = (dmoni_rx[D_MOTOR][3] & 0x1F);
//         u16v <<= 8;
//         u16v += dmoni_rx[D_MOTOR][4];
//         if (dmoni_rx[D_MOTOR][3] & 0x20)
//         { s16v = 0 - u16v; }
//         else
//         { s16v = u16v; }
//         d32v = s16v / 100;

//         _ctl->st_degSwiv = (double)d32v;
//     }
//     else
//     {
//         _ctl->st_bLeveling  = 0;
//         _ctl->st_bSwiveling = 0;
//     }

//     /* Leveling电机运行 */
//     switch (_ctl->st_bLeveling)
//     {
//     case 1: /* 到默认位置 */
//         posInc = 0;
//         break;
//     case 2: /* 到指定位置 */
//         posInc = MotorManage_LvlConvertAglIncreToPosIncre(_ctl->st_degLevl * RAD_PER_DEG);
//         break;
//     case 3: /* 自动运行,EMC测试用 */
//         if (_ctl->st_ms30000 < 15000)
//         { posInc = MotorManage_LvlConvertAglIncreToPosIncre(smotor.pr_LvlBotPos * RAD_PER_DEG); }
//         else
//         { posInc = MotorManage_LvlConvertAglIncreToPosIncre(smotor.pr_LvlTopPos * RAD_PER_DEG); }
//         break;
//     default:
//         posInc = 0;
//     }
//     MotorManage_SetLevelingPosIncre(E_LvlFunction_AFS, posInc);

//     /* Swiveling电机运行 */
//     switch (_ctl->st_bSwiveling)
//     {
//     case 1:
//         posInc = 0;
//         break;
//     case 2:
//         posInc = MotorManage_SvlConvertAngleIncreToPosIncre(_ctl->st_degSwiv * RAD_PER_DEG);
//         break;
//     case 3: /* 自动运行,EMC测试用 */
//         if (_ctl->st_ms30000 < 15000)
//         { posInc = MotorManage_SvlConvertAngleIncreToPosIncre(smotor.pr_SwlLePos * RAD_PER_DEG); }
//         else
//         { posInc = MotorManage_SvlConvertAngleIncreToPosIncre(smotor.pr_SwlRiPos * RAD_PER_DEG); }
//         break;
//     default:
//         posInc = 0;
//     }
//     MotorManage_SetSwivelingPosIncre(E_SvlFunction_AFS, posInc);

//     /* 设置电机测试自动运行 */
//     if (((dmoni_rx[D_EPTEST][0] & 0x7e) >> 1) == D_EPTEST)
//     {
//         if ((dmoni_rx[D_EPTEST][6] & 0x40) != 0)
//         { test_level_autorun = 1; }
//         else
//         { test_level_autorun = 0; }

//         if ((dmoni_rx[D_EPTEST][6] & 0x80) != 0)
//         { test_swive_autorun = 1; }
//         else
//         { test_swive_autorun = 0; }
//     }
//     else
//     {
//         test_level_autorun = 0;
//         test_swive_autorun = 0;
//     }

// #endif  /* (QINGHAIGANG) && (QHG_DMONI_orXCP) */
// #endif  /* (BUILD_PROJECT_ID == 1) */

//     _ctl->st_ms30000 += 10;
//     if (_ctl->st_ms30000 >= 30000) { _ctl->st_ms30000 = 0; }
// }
