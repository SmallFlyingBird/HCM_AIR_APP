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

const static S_OUVDeratePr_t gs_ouvderater_data = 
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
    OUV_OVER_LOW = 0,     /* Over Low  voltage supply */
    OUV_LOW,         /* Low       voltage supply */
    OUV_OK,         /* normal    voltage supply */
    OUV_HIGH,         /* High      voltage supply */
    OUV_OVER_HIGH          /* Over High voltage supply */
}E_OUVSts_t;

typedef struct _OUVDerateCtl_
{
    uint16_t    in_vol;     /* Power Supply Voltage (100mV) */
    uint8_t     derate_perc;    /* Derate to Percent (%) */  
    uint16_t    st_ms_high;    /* OUV_HIGH Timer */
    uint16_t    st_ms_overhigh;    /* OUV_OVER_HIGH Timer */
    uint16_t    slop_per_vol;     /* percent (%%) / voltage (100mV) */
    E_OUVSts_t  s_state;     /* for State Switching */
}S_OUVDerateCtl_t;

static S_OUVDerateCtl_t gs_ouvderate_ctrl;
static int inited = 0;

void OUVDerateMainFunction(uint8_t timebase)
{
    Std_ReturnType r2;
    double kl56;
    if (inited == 0)
    {
        C_Memset_B((uint8_t*)(&gs_ouvderate_ctrl), 0, sizeof(S_OUVDerateCtl_t));
        gs_ouvderate_ctrl.slop_per_vol = (10000 - gs_ouvderater_data.pr_dLoDn)/(gs_ouvderater_data.pr_vLo-gs_ouvderater_data.pr_vLoDn);
        gs_ouvderate_ctrl.in_vol = gs_ouvderater_data.pr_vLoUp; /* default OK */
        inited = 1;
    }
    r2 = Interface_GetKL56Voltage(&kl56);
    if (r2 == E_OK)
    {
        gs_ouvderate_ctrl.in_vol =(uint16_t)(kl56* 10);
    }
    /*  */
    switch(gs_ouvderate_ctrl.s_state)
    {
    case OUV_OVER_LOW:                                /* V < 6.5 */
        if (gs_ouvderate_ctrl.in_vol >= gs_ouvderater_data.pr_vLoUp) //大于开启电压
        {
            if (r2 == E_OK)
            { 
                // Interface_AddReInitDrvDevice(E_DrvReInitID_MatrixTrip); //矩阵芯片重新初始化
            }
            
            gs_ouvderate_ctrl.s_state = OUV_LOW;
        }
        else //低点亮关灯
        {
            gs_ouvderate_ctrl.derate_perc = 0;
        }
        break;
    case OUV_LOW:                                /* 6.5 <= V <= 9 */
        if (gs_ouvderate_ctrl.in_vol > gs_ouvderater_data.pr_vLo)
        { gs_ouvderate_ctrl.s_state = OUV_OK; }
        else if (gs_ouvderate_ctrl.in_vol < gs_ouvderater_data.pr_vLoDn)
        { gs_ouvderate_ctrl.s_state = OUV_OVER_LOW; }
        else
        { gs_ouvderate_ctrl.derate_perc = (10000-((gs_ouvderater_data.pr_vLo-gs_ouvderate_ctrl.in_vol)*gs_ouvderate_ctrl.slop_per_vol))/100; }
        break;
    case OUV_OK:                                /* 9 <= V <= 20.2*/
        if (gs_ouvderate_ctrl.in_vol > gs_ouvderater_data.pr_vHi)
        { gs_ouvderate_ctrl.s_state = OUV_HIGH; }
        else if (gs_ouvderate_ctrl.in_vol < gs_ouvderater_data.pr_vLo)
        { gs_ouvderate_ctrl.s_state = OUV_LOW; }
        else
        { gs_ouvderate_ctrl.derate_perc = 100; }
        break;
    case OUV_HIGH:                                /* 20.2 < V */
        gs_ouvderate_ctrl.st_ms_high = C_AddToMax_U16(gs_ouvderate_ctrl.st_ms_high, timebase);
        if (gs_ouvderate_ctrl.in_vol > gs_ouvderater_data.pr_vHiUp)
        {
            gs_ouvderate_ctrl.s_state = OUV_OVER_HIGH;
        }
        else if (gs_ouvderate_ctrl.in_vol <= gs_ouvderater_data.pr_vHiDn)
        {
            gs_ouvderate_ctrl.s_state = OUV_OK;
            gs_ouvderate_ctrl.st_ms_high = 0;
        }
        else
        {
            if (gs_ouvderate_ctrl.st_ms_high < gs_ouvderater_data.pr_tHI) //
            { gs_ouvderate_ctrl.derate_perc = 100; }
            else
            { gs_ouvderate_ctrl.derate_perc = 0; }
        }
        break;
    case OUV_OVER_HIGH:                                /* 26.5 < V */
        gs_ouvderate_ctrl.st_ms_high = C_AddToMax_U16(gs_ouvderate_ctrl.st_ms_high, timebase);
        gs_ouvderate_ctrl.st_ms_overhigh = C_AddToMax_U16(gs_ouvderate_ctrl.st_ms_overhigh, timebase);
        if (gs_ouvderate_ctrl.in_vol < gs_ouvderater_data.pr_vHiDn) //<19.2
        {
            gs_ouvderate_ctrl.s_state = OUV_OK;
            gs_ouvderate_ctrl.st_ms_high = 0;
            gs_ouvderate_ctrl.st_ms_overhigh = 0;
        }
        else if ((gs_ouvderate_ctrl.in_vol <= gs_ouvderater_data.pr_vHiUp)&&(gs_ouvderate_ctrl.derate_perc!=0))//<26.2
        {
            gs_ouvderate_ctrl.s_state = OUV_HIGH;
            gs_ouvderate_ctrl.st_ms_overhigh = 0;
        }
        else
        {
            if ((gs_ouvderate_ctrl.st_ms_high < gs_ouvderater_data.pr_tHI) &&
                (gs_ouvderate_ctrl.st_ms_overhigh < gs_ouvderater_data.pr_tOH)) 
            { gs_ouvderate_ctrl.derate_perc = 100; }
            else
            { gs_ouvderate_ctrl.derate_perc = 0; }
        }
        break;
    default:;
    }
}

uint8_t Interface_GetDerateRatioOfOUV(void)
{
    if (inited) { return gs_ouvderate_ctrl.derate_perc; }
    else        { return 100; }
}
