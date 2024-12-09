// /**
//  * @file AmbiDerate_Interface.c
//  * @author QinHaigang (qinhaigang@xyl.cn)
//  * @brief 
//  * @version 0.1
//  * @date 2024-04-28
//  * 
//  * @copyright Copyright (c) 2024-  New Elec. Dept. XYL
//  * 
//  * @par History:
//  * <table>
//  * <tr><th>Data       <th>Version <th>Author     <th>Description
//  * <tr><td>2024-04-28 <td>0.1     <td>QinHaigang <td>
//  * </table>
//  */

// #include "HcmPlatform.h"
// #include "GeneralFunction.h"
// #include "Parameter_Interface.h"
// #include "ComSignal_Interface.h"

// #include "AmbiDerate_Interface.h"

// typedef struct _AmbiPr_
// {
//     uint8_t     pr_tLo;     /*  90 (C) */
//     uint8_t     pr_tHi;     /* 105 (C) */

//     uint16_t    pr_dLo;     /* 5500 (%%) */
// }S_AmbiPr_t;

// static 
// const 
// S_AmbiPr_t ambipr = 
// {
//     .pr_tLo = 90,
//     .pr_tHi = 105,
//     .pr_dLo = 5500,
// };

// typedef struct _AmbientDerateCtl_
// {
//     sint32_t    in_te;      /* AmbTRawAmbTVal (C) */
//     sint32_t    st_te;      /* in_te record */

//     uint8_t     ou_perc;    /* Derated Percent (%) */

//     uint8_t     st_tHys;    /* pr_tHi - "FANsetting"."pFanAmbTempHys" (C) */

//     uint16_t    st_p1t;     /* perc (100) / te (C) */
// }S_AmbientDerateCtl_t;

// static S_AmbientDerateCtl_t ambictl;
// static int binited = 0;

// //环境温度的降额计算
// void AmbiDerateMainFunction(uint8_t timebase)
// {
//     uint8_t up; /* 0:no change; 1:up; 2:down */
//     uint8_t te;

//     if (binited == 0)
//     {
//         C_Memset_B((uint8_t*)(&ambictl), 0, sizeof(S_AmbientDerateCtl_t));

//         ambictl.st_tHys = ambipr.pr_tHi - Get_pFanAmbTempHys();

//         ambictl.st_p1t = (10000 - ambipr.pr_dLo) / (ambipr.pr_tHi - ambipr.pr_tLo);

//         Interface_GetSignal_AmbTRawAmbTVal(&(ambictl.st_te));
//     }

//     Interface_GetSignal_AmbTRawAmbTVal(&(ambictl.in_te));

//     if      (ambictl.in_te > ambictl.st_te) { up = 1; }
//     else if (ambictl.in_te < ambictl.st_te) { up = 2; }
//     else                                    { up = 0; }

//     if ((binited == 0) && (up == 0))
//     {
//         up = 1; /* 初始识别1次 */
//         binited = 1;
//     }

//     ambictl.st_te = ambictl.in_te;
//     te            = ambictl.in_te;  /* sint32 -> uint8 */

//     if (up != 0)
//     {
//         if (ambictl.in_te < ambipr.pr_tLo) { te = ambipr.pr_tLo - 1; }
//         if (ambictl.in_te > ambipr.pr_tHi) { te = ambipr.pr_tHi + 1; }

//         /*  */
//         if (((up==1) && (te > ambipr.pr_tHi)) ||
//             ((up==2) && (te > ambictl.st_tHys)))
//         {
//             ambictl.ou_perc = 0;
//             return;
//         }

//         if (te > ambipr.pr_tLo)
//         {
//             ambictl.ou_perc = (10000 - ((te - ambipr.pr_tLo) * ambictl.st_p1t)) / 100;
//             return;
//         }

//         ambictl.ou_perc = 100;
//     }
// }

// uint8_t Interface_GetDerateRatioOfAmbi(void)
// {
//     if (binited) { return ambictl.ou_perc; }
//     else         { return 100; }
// }
