
/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "NtcDerate_Interface.h"
#include "NtcRcod_Interface.h"
#include "Parameter_Interface.h"
#include "DTC_Interface.h"
/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
static uint8_t NtcDerateRatio[MAX_CHANNLE_NUM] = {100, 100, 100, 100, 100, 100};
static S_CurNtcTmperatureInfo gs_CurNtcTmperatureInfo[MAX_NTC_NUM] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};
/****************************************************************
 *                                                              *
 *                   Global Variable Define                     *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/
/*calculate the channel derate*/
static void CaculateChannelDerateRatio(uint16_t ChannelMask, sint16 temperature)
{
    E_ChannelID chid;
    E_ChannelID i;
    sint16 tmplow, tmphigh;
    uint8 pwrA, pwrB, pwrC;
    uint8_t tmp;
    uint16_t LightFuncMask = 0;
    uint16_t chmask = 0;
    Light_Functions LF;
    for (chid = ChannelID1; chid < CHANNEL_NUM; chid++)
    {
        if ((ChannelMask & (1 << chid)) == 0)
            continue;
/* parameter in ChnConfig+Derating，5 step temp : 1 2 3 4 5，3 step derate  A B C */
        if (temperature <= (((sint16)Get_pLedDerTemp1(chid)) - 40))/* 1.temp<pLedDerTemp1 */
        {
            NtcDerateRatio[chid] = Get_pLedDerPwrA(chid);
        }
        else if (temperature <= (((sint16)Get_pLedDerTemp2(chid)) - 40))/* 2.temp < pLedDerTemp2 */
        {
            tmplow = (sint16)Get_pLedDerTemp1(chid) - 40;
            tmphigh = (sint16)Get_pLedDerTemp2(chid) - 40;
            pwrA = Get_pLedDerPwrA(chid);
            NtcDerateRatio[chid] = (uint8)(((uint16_t)(100 - pwrA)) * ((uint16_t)(temperature - tmplow)) / ((uint16_t)(tmphigh - tmplow)) + pwrA);
        }
        else if (temperature <= ((sint16)Get_pLedDerTemp3(chid) - 40))/* 3.temp<pLedDerTemp3 */
        {
            NtcDerateRatio[chid] = 100;
        }
        else if (temperature <= ((sint16)Get_pLedDerTemp4(chid) - 40))/* 4.temp<pLedDerTemp4 */
        {
            tmplow = (sint16)Get_pLedDerTemp3(chid) - 40;
            tmphigh = (sint16)Get_pLedDerTemp4(chid) - 40;
            pwrB = Get_pLedDerPwrB(chid);

            NtcDerateRatio[chid] = (uint8)(((uint16_t)(100 - pwrB)) * ((uint16_t)(tmphigh - temperature)) / ((uint16_t)(tmphigh - tmplow)) + pwrB);
        }
        else if (temperature <= ((sint16)Get_pLedDerTemp5(chid) - 40))/* 5.temp<pLedDerTemp5 */
        {
            tmplow = (sint16)Get_pLedDerTemp4(chid) - 40;
            tmphigh = (sint16)Get_pLedDerTemp5(chid) - 40;
            pwrB = Get_pLedDerPwrB(chid);
            pwrC = Get_pLedDerPwrC(chid);

            NtcDerateRatio[chid] = (uint8)(((uint16_t)(pwrB - pwrC)) * ((uint16_t)(tmphigh - temperature)) / ((uint16_t)(tmphigh - tmplow)) + pwrC);
        }
        else
        {
            NtcDerateRatio[chid] = 0;
        }
/* 计算这个所对应的功能，并且设置这个功能所对应的其余通道的降流比率 */
/* which light function for the channel  */
        LightFuncMask = GetLightFunctionsMaskByChNo(chid);
        for (LF = E_LowBeam; LF < E_TurnIndicator_Act; LF++)
        {
            if ((LightFuncMask & (1 << LF)) == 0)
                continue;
/* find all channels for the light function */
            chmask = GetChannelMaskByLightFunction(LF);

            if (LF == E_LowBeam)
            {
                if (Get_pLedDerMinCurrLoBeamFlat() > NtcDerateRatio[chid])
                {
/*LowBeamFlat NTC derate need to > pLedDerMinCurrLoBeamFlat*/
                    NtcDerateRatio[chid] = Get_pLedDerMinCurrLoBeamFlat();

                    if (NtcDerateRatio[chid] > Get_pLedDerMinCurrLoBeamFlat())
                    {
                        Interface_SetSystemError(E_SystemErrorType_LowBeamFlatDerateError, 1);
                    }
                    else
                    {
                        Interface_SetSystemError(E_SystemErrorType_LowBeamFlatDerateError, 0);
                    }
                }
            }
            else if (LF == E_TurnIndicator)
            {
                if (Get_pLedDerMinCurrDirIndcr() > NtcDerateRatio[chid])
                {
/*TI NTC derate need to > pLedDerMinCurrLoBeamFlat*/
                    NtcDerateRatio[chid] = Get_pLedDerMinCurrDirIndcr();
                    if (NtcDerateRatio[chid] > Get_pLedDerMinCurrDirIndcr())
                    {
                        Interface_SetSystemError(E_SystemErrorType_TIDerateError, 1);
                    }
                    else
                    {
                        Interface_SetSystemError(E_SystemErrorType_TIDerateError, 0);
                    }
                }
            }

            for (i = ChannelID1; i < CHANNEL_NUM; i++)
            {
                if ((chmask & (1 << i)) == 0)
                    continue;
                NtcDerateRatio[i] = NtcDerateRatio[chid];
            }
        }
    }
}
/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
uint8_t Interface_GetChannelDerateRatioOfNtc(E_ChannelID id)
{
    if (id >= CHANNEL_NUM)
        return 100;

    return NtcDerateRatio[id];
}

void Ntc_LightBoard_MainFunction(uint8_t timebase)
{
    E_NtcRcodFunction NtcRcodFunction = E_NtcRcodFunction_Ntc1;
    sint16 temperature;
    uint16_t ChannelMask;
    uint8_t TempHy;

    for (NtcRcodFunction = E_NtcRcodFunction_Ntc1; NtcRcodFunction <= E_NtcRcodFunction_Ntc6; NtcRcodFunction++)
    {
        if (Interface_GetNtcTemperature(NtcRcodFunction, &temperature) == E_NOT_OK)
            continue;

        if (Interface_GetNtcRcodMap2ChannelMask(NtcRcodFunction, &ChannelMask) == E_NOT_OK)
            continue;

        if (gs_CurNtcTmperatureInfo[NtcRcodFunction - E_NtcRcodFunction_Ntc1].TemperatureValied == 0)
        {
            gs_CurNtcTmperatureInfo[NtcRcodFunction - E_NtcRcodFunction_Ntc1].CurTemperature = temperature;
            gs_CurNtcTmperatureInfo[NtcRcodFunction - E_NtcRcodFunction_Ntc1].TemperatureValied = 1;
        }
        else
        {
            if (gs_CurNtcTmperatureInfo[NtcRcodFunction - E_NtcRcodFunction_Ntc1].CurTemperature > temperature)
                TempHy = (uint8)(gs_CurNtcTmperatureInfo[NtcRcodFunction - E_NtcRcodFunction_Ntc1].CurTemperature - temperature);
            else
                TempHy = (uint8)(temperature - gs_CurNtcTmperatureInfo[NtcRcodFunction - E_NtcRcodFunction_Ntc1].CurTemperature);

            if (TempHy >= 1)/* Get_pLedDerTempHys() */
            {
                gs_CurNtcTmperatureInfo[NtcRcodFunction - E_NtcRcodFunction_Ntc1].CurTemperature = temperature;
            }
            else
            {
                continue;
            }
        }
/* according to the channelmask and temprature to calculate the derate */
        CaculateChannelDerateRatio(ChannelMask, temperature);
    }
}
/* enviroment funtion */
/* 功能测试中，待补全 */
#define E_TEMPDERATE_START     90
#define E_TEMPDERATE_STOP      105
#define E_LOWEST_PWM           55
sint16 enviromenttemp=0;
void NTC_Enviroment_MainFunction(uint8_t timebase)
{
    enviromenttemp=NTC_Calculate_Enviroment_Temp();/*get the temp */
    /* 需要添加返回温度值的报文 代码 */
/* 高配策略  可作为参考 
   环境温度90~105℃降额输出，从100%降额至55%，环境温度>105℃则关闭通道输出。
   当环境温度＞105°，LB Flat保持55%，其他灯光关闭。
 */
    // if((enviromenttemp>=E_TEMPDERATE_START)&&(enviromenttemp<=E_TEMPDERATE_STOP))/* linear derate */
    // {
    //     derate=100-(enviromenttemp-E_TEMPDERATE_START)*(100-E_LOWEST_PWM)/(E_TEMPDERATE_STOP-E_TEMPDERATE_START);
    // }
}


void NtcDerateMainFunction(uint8_t timebase)
{
    Ntc_LightBoard_MainFunction(timebase);/* light board NTC */ 
    NTC_Enviroment_MainFunction(timebase);/* MCU NTC */
}


uint8 Interface_GetEnviroment()
{

}


