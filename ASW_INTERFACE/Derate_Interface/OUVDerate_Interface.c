/**
 * @file OUVDerate_Interface.c
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
#include "PowerSupply_Interface.h"
#include "OUVDerate_Interface.h"
typedef struct _OUVDeratePr_
{
    uint16_t    pr_vLoDn;   /*  65   (100mV) */
    uint16_t    pr_vLoUp;   /*  75   (100mV) */
    uint16_t    pr_vLo;     /*  90   (100mV) */
    uint16_t    pr_vHiDn;   /* 192   (100mV) */
    uint16_t    pr_vHi;     /* 202   (100mV) */
    uint16_t    pr_vHiUp;   /* 265   (100mV) */
 
    uint16_t    pr_dLoDn;   /* 5500  (%%) */
 
    uint16_t    pr_tHI;     /* 63000 (ms) */
    uint16_t    pr_tOH;     /*   400 (ms) */
}S_OUVDeratePr_t;

const
static 
S_OUVDeratePr_t ouvpr = 
{
    .pr_vLoDn   = 65,
    .pr_vLoUp   = 75,
    .pr_vLo     = 90,
    .pr_vHiDn   = 192,
    .pr_vHi     = 202,
    .pr_vHiUp   = 265,
    .pr_dLoDn   = 5500,
    .pr_tHI     = 63000,
    .pr_tOH     = 400
};

typedef enum _
{
    OUV_OL = 0,     /* Over Low  voltage supply */
    OUV_LO,         /* Low       voltage supply */
    OUV_OK,         /* normal    voltage supply */
    OUV_HI,         /* High      voltage supply */
    OUV_OH          /* Over High voltage supply */
}E_OUVSts_t;

typedef struct _OUVDerateCtl_
{
    uint16_t    in_vol;     /* Power Supply Voltage (100mV) */

    uint8_t     ou_perc;    /* Derate to Percent (%) */
    
    uint16_t    st_msHI;    /* OUV_HI Timer */
    uint16_t    st_msOH;    /* OUV_OH Timer */

    uint16_t    st_p1v;     /* percent (%%) / voltage (100mV) */
    
    E_OUVSts_t  st_ouv;     /* for State Switching */

}S_OUVDerateCtl_t;

static S_OUVDerateCtl_t ouvctl;
static int inited = 0;

void OUVDerateMainFunction(uint8_t timebase)
{
    Std_ReturnType r2;
    double kl56;
    if (inited == 0)
    {
        C_Memset_B((uint8_t*)(&ouvctl), 0, sizeof(S_OUVDerateCtl_t));

        ouvctl.st_p1v = (10000 - ouvpr.pr_dLoDn)/(ouvpr.pr_vLo-ouvpr.pr_vLoDn);

        ouvctl.in_vol = ouvpr.pr_vLoUp; /* default OK */

        inited = 1;
    }
    r2 = Interface_GetKL56Voltage(&kl56);
    if (r2 == E_OK)
    {
        ouvctl.in_vol =(uint16_t)(kl56* 10);
    }
    /*  */
    switch(ouvctl.st_ouv)
    {
    case OUV_OL:                                /* V < 6.5 */
        if (ouvctl.in_vol >= ouvpr.pr_vLoUp) //大于开启电压
        {
            if (r2 == E_OK)
            { 
                // Interface_AddReInitDrvDevice(E_DrvReInitID_MatrixTrip); //矩阵芯片重新初始化
            }
            
            ouvctl.st_ouv = OUV_LO;
        }
        else //低点亮关灯
        {
            ouvctl.ou_perc = 0;
        }
        break;
    case OUV_LO:                                /* 6.5 <= V <= 9 */
        if (ouvctl.in_vol > ouvpr.pr_vLo)
        { ouvctl.st_ouv = OUV_OK; }
        else if (ouvctl.in_vol < ouvpr.pr_vLoDn)
        { ouvctl.st_ouv = OUV_OL; }
        else
        { ouvctl.ou_perc = (10000-((ouvpr.pr_vLo-ouvctl.in_vol)*ouvctl.st_p1v))/100; }
        break;
    case OUV_OK:                                /* 9 <= V <= 20.2*/
        if (ouvctl.in_vol > ouvpr.pr_vHi)
        { ouvctl.st_ouv = OUV_HI; }
        else if (ouvctl.in_vol < ouvpr.pr_vLo)
        { ouvctl.st_ouv = OUV_LO; }
        else
        { ouvctl.ou_perc = 100; }
        break;
    case OUV_HI:                                /* 20.2 < V */
        ouvctl.st_msHI = C_AddToMax_U16(ouvctl.st_msHI, timebase);
        if (ouvctl.in_vol > ouvpr.pr_vHiUp)
        {
            ouvctl.st_ouv = OUV_OH;
        }
        else if (ouvctl.in_vol <= ouvpr.pr_vHiDn)
        {
            ouvctl.st_ouv = OUV_OK;
            ouvctl.st_msHI = 0;
        }
        else
        {
            if (ouvctl.st_msHI < ouvpr.pr_tHI) //
            { ouvctl.ou_perc = 100; }
            else
            { ouvctl.ou_perc = 0; }
        }
        break;
    case OUV_OH:                                /* 26.5 < V */
        ouvctl.st_msHI = C_AddToMax_U16(ouvctl.st_msHI, timebase);
        ouvctl.st_msOH = C_AddToMax_U16(ouvctl.st_msOH, timebase);
        if (ouvctl.in_vol < ouvpr.pr_vHiDn) //<19.2
        {
            ouvctl.st_ouv = OUV_OK;
            ouvctl.st_msHI = 0;
            ouvctl.st_msOH = 0;
        }
        else if (ouvctl.in_vol <= ouvpr.pr_vHiUp) //<26.2
        {
            ouvctl.st_ouv = OUV_HI;
            ouvctl.st_msOH = 0;
        }
        else
        {
            if ((ouvctl.st_msHI < ouvpr.pr_tHI) &&
                (ouvctl.st_msOH < ouvpr.pr_tOH)) 
            { ouvctl.ou_perc = 100; }
            else
            { ouvctl.ou_perc = 0; }
        }
        break;
    default:;
    }
}

uint8_t Interface_GetDerateRatioOfOUV(void)
{
    if (inited) { return ouvctl.ou_perc; }
    else        { return 100; }
}
