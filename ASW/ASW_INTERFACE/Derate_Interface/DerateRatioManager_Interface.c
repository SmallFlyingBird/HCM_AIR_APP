/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "DerateRatioManager_Interface.h"
#include "BuckDerate_Interface.h"
#include "NtcDerate_Interface.h"
#include "OUVDerate_Interface.h"
#include "GeneralFunction.h"
#include "Lighting.h"
#include "AmbiDerate_Interface.h"

/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
/* 目标降额 */
static uint8 DerateRatio[MAX_CHANNLE_NUM] = {100, 100, 100, 100, 100, 100};
/* 降额原因 */
static E_Derate_t DerateFor[MAX_CHANNLE_NUM] = {DERA_UN};
/* 当前降额 */
static uint8 DerateCurr[MAX_CHANNLE_NUM] = {100, 100, 100, 100, 100, 100};

/* Derate to 0 delay timer */
static uint16_t BucksDerate0Hys[MAX_CHANNLE_NUM] = {0,0,0,0,0,0}; /* ms */
static uint16_t NtcsDerate0Hys[MAX_CHANNLE_NUM] = {0,0,0,0,0,0}; /* ms */

#define DER_STEP    (5) /*  */
#define DER_STEPB    (10) /*  */

#define FILTER_TWINKLE 50 /* Filter cnt for pos twinkle */
/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
uint8 Interface_GetChannelDerateRatio(E_ChannelID id)
{
    if ((id) >= MAX_CHANNLE_NUM)
        { return 100; }

    return DerateCurr[id];
}

E_Derate_t Interface_GetChannelDerateFor(E_ChannelID id)
{
    if ((id) >= MAX_CHANNLE_NUM)
    { return DERA_UN; }

    return DerateFor[id];
}

uint8 Interface_GetDeratePwm(void)
{
    return DerateCurr[0];
}
/*
 * 建议每隔100ms执行一次这个函数
 * 此函数会根据NTC和Buck计算出来的降流比例，计算出最终的降流比例
 */
void DerateRatioManagerFuncmain(uint8 timebase)
{
    E_ChannelID ch;
    uint8 ratio_ouv=100;
    static uint8 ratio_amb=100,ratio_ambpre=100;
    static ratio_amb_time=0;
    uint8 chratio;
    uint8 derate[MAX_CHANNLE_NUM];
    static uint16 ambito0=0;
    static uint16 ambito1=0;
    E_Derate_t derfor[MAX_CHANNLE_NUM];
    static uint8 DecCnt=0,IncCnt=0;
    struct {
    uint8 enaECU  :1;
    uint8 enaLED  :1;
    uint8 enaAMB  :1;
    uint8 enaOUV  :1;
    } 
#if (NORMAL_CODE==1)
    EnaDer = {1,1,1,1};   /* derate enable */
#elif (HARDWARE_TEST==1)
    EnaDer = {1,0,1,1};   /* derate enable */
#endif

    for (ch = ChannelID1; ch < CHANNEL_NUM; ch++)
    { 
        derate[ch] = 100; 
        derfor[ch] = DERA_UN; 
    }
/* supply derate */
    if (EnaDer.enaOUV)
    { 
        ratio_ouv = Interface_GetDerateRatioOfOUV();
    }
    else
    { 
        ratio_ouv = 100; 
    }

    if (EnaDer.enaAMB)
    { 
        ratio_ambpre = AmbiDerateMainFunction();
    }
    else
    { 
        ratio_ambpre = 100; 
    }
    if(ratio_ambpre<55)
    {
        ambito1=0;
        ambito0+=timebase;
        if(ambito0>=500)
        {
            ambito0=500;
            ratio_ambpre=0;
            ratio_amb=0;
        }
    }
    else if(ratio_ambpre<ratio_amb)
    {
        ambito1=0;
        ambito0=0;
        ratio_amb_time+=timebase;
        if(ratio_amb_time>=100)
        {
            ratio_amb_time=0;
            ratio_amb--;
        }
    }
    else
    {
        ambito0=0;
        ambito1+=timebase;
        if(ambito1>=500)
        {
            ambito1=500;
            ratio_amb_time-=timebase;
            if(ratio_amb_time<=timebase)
            {
                ratio_amb_time=0;
                ratio_amb++;
            }
        }
    }

    for (ch = ChannelID1; ch < CHANNEL_NUM; ch++)
    {
/* NTC derate */
        if (EnaDer.enaLED)
        { 
            chratio = Interface_GetChannelDerateRatioOfNtc(ch); 
        }
        else
        {
            chratio = 100; 
        }

/* ntc derate to 0%,need to wait 5s of close the light */
        if ((chratio == 0) && (NtcsDerate0Hys[ch] == 0)) 
        { 
            NtcsDerate0Hys[ch] = 5000; 
        }
        if (NtcsDerate0Hys[ch] > 0) 
        {
            chratio = 0; 
        }
        NtcsDerate0Hys[ch] = C_SubToMin_U16(NtcsDerate0Hys[ch], timebase);/* delay to zero  */

        if (chratio < derate[ch])
        {
            derate[ch] = chratio;
            derfor[ch] = DERA_LED;
        }

/* buck derate */
        if (EnaDer.enaECU)
        { 
            chratio = Interface_GetChannelDerateRatioOfBuckTemp(ch); 
        }
        else
        {
            chratio = 100; 
        }

        /* LBkink最低降到55% */
        if ((ch == ChannelID1) && (chratio < 55))
        { 
            chratio = 55; 
        }
        /* BUCK降额到0, 至少保持5S */
        if ((chratio == 0) && (BucksDerate0Hys[ch] == 0)) 
        { 
            BucksDerate0Hys[ch] = 5000; 
        }
        if (BucksDerate0Hys[ch] > 0) 
        { 
            chratio = 0; 
        }
        BucksDerate0Hys[ch] = C_SubToMin_U16(BucksDerate0Hys[ch], timebase);

        if (chratio < derate[ch])
        {
            derate[ch] = chratio;
            derfor[ch] = DERA_ECU;
        }

/* enviroment derate , LBkink最低降到55% */
        if (ratio_amb < derate[ch])
        {
            derate[ch] = ratio_amb; 
            derfor[ch] = DERA_AMB;
            if((ratio_amb < 55)&&(ch == ChannelID1))
            { 
                derate[ch] = 55; 
            }
        }
        
        /* OUV Derate */
        if (ratio_ouv < derate[ch])
        {
            derate[ch] = ratio_ouv; 
            derfor[ch] = DERA_OUV;
        }
    }

    for (ch = ChannelID1; ch < CHANNEL_NUM; ch++)
    {
        sint8_t ss;
        DerateRatio[ch] = derate[ch];
        DerateFor[ch]   = derfor[ch];

        if (DerateCurr[ch] > DerateRatio[ch])/* now derate > mu biao derate */
        {
            ss = DerateCurr[ch] - DerateRatio[ch];
            if (ss > DER_STEPB) 
            { 
                DerateCurr[ch] -= DER_STEPB; 
            }
            else if (ss > DER_STEP) 
            { 
                DerateCurr[ch] -= DER_STEP; 
            }
            else               
            {
/* Filter for pos twinkle  */
                DecCnt=0;
                if(GetLgtStsFb_POS()==1) /* the channel is pos */
                {
                    IncCnt++;
                    if(IncCnt>FILTER_TWINKLE)
                    {
                        IncCnt=0;
                        DerateCurr[ch] = DerateRatio[ch]; 
                    }
                }
                else
                {
                    DerateCurr[ch] = DerateRatio[ch]; 
                }          
            }
        }
        if (DerateCurr[ch] < DerateRatio[ch])
        {
            ss = DerateRatio[ch] - DerateCurr[ch];
            if (ss > DER_STEPB) 
            { 
                DerateCurr[ch] += DER_STEPB; 
            }
            else if (ss > DER_STEP) 
            { 
                DerateCurr[ch] += DER_STEP; 
            }
            else               
            { 
/* Filter for pos twinkle  */
                IncCnt=0;
                if(GetLgtStsFb_POS()==1) /* the channel is pos */
                {
                    DecCnt++;
                    if(DecCnt>FILTER_TWINKLE)
                    {
                        DecCnt=0;
                        DerateCurr[ch] = DerateRatio[ch]; 
                    }
                }
                else
                {
                    DerateCurr[ch] = DerateRatio[ch]; 
                }
            }
        }
    }
}













