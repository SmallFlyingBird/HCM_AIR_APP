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
#include "LossDerate_Interface.h"

static uint8_t LossDerateRatio[MAX_CHANNLE_NUM] = {100, 100, 100, 100, 100, 100,
                                                   100, 100, 100, 100, 100, 100};

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
    int i;
    uint16_t rated = 0;
    uint16_t sum = 0;
    uint32_t u32v;

    if ((dlgt.val == 0) ||
        (pDer == 0))
    { return; }

    /* 计算额定 */
    for (i=0; i<NUM_DER_LGT; i++)
    {
        if ((dlgt.val & (0x0001<<i)) != 0)
        {
            rated += lossctl.pr_Rate[i];
            pDer[i] = 100;
        }
    }
    if (rated <= avai) return;

    /* 计算降额 */
    for (i=0; i<NUM_DER_LGT; i++)
    {
        if ((dlgt.val & (0x0001<<i)) != 0)
        {
            if ((lossctl.pr_Geely == 1) && (i == D00_LB))
            {
                sum += (lossctl.pr_Rate[i]*lossctl.pr_GeelyLB)/100;
                pDer[i] = lossctl.pr_GeelyLB;
                continue;
            }

            sum += lossctl.pr_Rate[i];

            if (sum > avai)
            {
                u32v = sum-avai;

                if (u32v >= lossctl.pr_Rate[i])
                {
                    pDer[i] = 0;
                }
                else
                {
                    u32v = lossctl.pr_Rate[i] - u32v;
                    u32v = u32v * 100;
                    pDer[i] = u32v / lossctl.pr_Rate[i];
                }
                break;
            }
        }
    }
    i++;
    for (; i<NUM_DER_LGT; i++)
    {
        if ((dlgt.val & (0x0001<<i)) != 0) { pDer[i] = 0; }
    }

}


void LossDerateMainFunction(uint8_t timebase, S_DerateLight_t dlgt)
{
    int i, j;

    uint8_t gap;    /**/
    uint8_t der[NUM_DER_LGT];

    uint16_t mask;

    if(_ctl == 0)
    {
        C_Memset_B((uint8_t*)(&lossctl), 0, sizeof(S_LossDerateCtl_t));

#if (OEM_PLATFORM == OEM_GEELY)
        lossctl.pr_Geely = 1;
#else
        lossctl.pr_Geely = 0;
#endif
        lossctl.pr_GeelyLB = 55;

        lossctl.pr_1P    = 600;
        lossctl.pr_2P_Hi = 1300;
        lossctl.pr_2P_Lo = 1200;

        _ctl = &lossctl;
    }

    /* From DTC Error Confirmed */
    if (lossctl.in_loss)
    { lossctl.st_Avai = lossctl.pr_1P; }
    else        /* 未丢失供电，不降额 */
    {
        lossctl.st_Avai = lossctl.pr_2P_Hi;
        for (i=0; i<MAX_CHANNLE_NUM; i++) { LossDerateRatio[i] = 100; }
        return;
    }

    /* 使用DMONI调试 */
    /* {
    extern unsigned char debug_var_rx[8];
    for (i=0; i<8; i++)
    {
        if ((debug_var_rx[1] & (0x01<<i)) != 0)
        {
            switch(i)
            {
            case 0: dlgt.bit.D00_LB   = 1; break;
            case 1: dlgt.bit.D01_TI   = 1; break;
            case 2: dlgt.bit.D02_POS  = 1; break;
            case 3: dlgt.bit.D03_SML  = 1; break;
            case 4: dlgt.bit.D04_HB   = 1; break;
            case 5: dlgt.bit.D05_DRL  = 1; break;
            case 6: dlgt.bit.D06_CORN = 1; break;
            case 7: dlgt.bit.D07_FOG  = 1; break;
            }
        }
        else
        {
            switch(i)
            {
            case 0: dlgt.bit.D00_LB   = 0; break;
            case 1: dlgt.bit.D01_TI   = 0; break;
            case 2: dlgt.bit.D02_POS  = 0; break;
            case 3: dlgt.bit.D03_SML  = 0; break;
            case 4: dlgt.bit.D04_HB   = 0; break;
            case 5: dlgt.bit.D05_DRL  = 0; break;
            case 6: dlgt.bit.D06_CORN = 0; break;
            case 7: dlgt.bit.D07_FOG  = 0; break;
            }
        }
    }
    for (i=0; i<8; i++)
    {
        if ((debug_var_rx[2] & (0x01<<i)) != 0)
        {
            switch(i)
            {
            case 0: dlgt.bit.D08_CROS  = 1; break;
            case 1: dlgt.bit.D09_GRIL  = 1; break;
            case 2: dlgt.bit.D10_LOGO  = 1; break;
            case 3: dlgt.bit.D11_WELC  = 1; break;
            case 4: dlgt.bit.D12_SHOW  = 1; break;
            }
        }
        else
        {
            switch(i)
            {
            case 0: dlgt.bit.D08_CROS  = 0; break;
            case 1: dlgt.bit.D09_GRIL  = 0; break;
            case 2: dlgt.bit.D10_LOGO  = 0; break;
            case 3: dlgt.bit.D11_WELC  = 0; break;
            case 4: dlgt.bit.D12_SHOW  = 0; break;
            }
        }
    }
    } */

    /* 计算当前激活灯功能的减额值 */
    for (i=0; i<NUM_DER_LGT; i++) { der[i] = 0xFF; } 
    cal_derate(dlgt, lossctl.st_Avai, der);

    /* 根据灯功能减额比例，对应到通道 */
    for (i=(NUM_DER_LGT-1); i>=0; i--)              /* 从低优先级到高优先级进行减额 */
    {
        if ( ((dlgt.val & (0x0001<<i)) != 0) && 
             (der[(E_DerateLight_t)i]<100) )
        {
            for (j=0; j<MAX_CHANNLE_NUM; j++)       /* 遍历某灯光功能的所有通道 */
            {
                if ((lossctl.pr_mask[i] & (0x0001<<j)) != 0)
                { LossDerateRatio[j] = der[i]; }
            }
        }
    }

}

uint8_t 
Interface_GetChannelDerateRatioOfLoss(E_ChannelID id)
{
    if (_ctl != 0) { return LossDerateRatio[id]; }
    else           { return 100; }
}

uint16_t 
Interface_GetDerateLightChannelMask(E_DerateLight_t dl)
{
    if (_ctl != 0) { return lossctl.pr_mask[dl]; }
    else           { return 0x0000; }
}

int Interface_IsLoss(void)
{
    if (_ctl != 0) { return lossctl.in_loss; }
    else           { return 0; }
}
