
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
/*计算通道降流*/
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
//配置表ChnConfig+Derating中，5级温度1 2 3 4 5，3级降额 A B C
        if (temperature <= (((sint16)Get_pLedDerTemp1(chid)) - 40))//1.温度小于pLedDerTemp1
        {
            NtcDerateRatio[chid] = Get_pLedDerPwrA(chid);
        }
        else if (temperature <= (((sint16)Get_pLedDerTemp2(chid)) - 40))//2.温度小于pLedDerTemp2
        {
            tmplow = (sint16)Get_pLedDerTemp1(chid) - 40;
            tmphigh = (sint16)Get_pLedDerTemp2(chid) - 40;
            pwrA = Get_pLedDerPwrA(chid);
            NtcDerateRatio[chid] = (uint8)(((uint16_t)(100 - pwrA)) * ((uint16_t)(temperature - tmplow)) / ((uint16_t)(tmphigh - tmplow)) + pwrA);
        }
        else if (temperature <= ((sint16)Get_pLedDerTemp3(chid) - 40))//3.温度小于pLedDerTemp1
        {
            NtcDerateRatio[chid] = 100;
        }
        else if (temperature <= ((sint16)Get_pLedDerTemp4(chid) - 40))//4.温度小于pLedDerTemp1
        {
            tmplow = (sint16)Get_pLedDerTemp3(chid) - 40;
            tmphigh = (sint16)Get_pLedDerTemp4(chid) - 40;
            pwrB = Get_pLedDerPwrB(chid);

            NtcDerateRatio[chid] = (uint8)(((uint16_t)(100 - pwrB)) * ((uint16_t)(tmphigh - temperature)) / ((uint16_t)(tmphigh - tmplow)) + pwrB);
        }
        else if (temperature <= ((sint16)Get_pLedDerTemp5(chid) - 40))//5.温度小于pLedDerTemp1
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
//计算这个所对应的功能，并且设置这个功能所对应的其余通道的降流比率

//找到这个通道对应灯具功能的掩码
        LightFuncMask = GetLightFunctionsMaskByChNo(chid);
        for (LF = E_LowBeamKink; LF <= E_SideMarkerLamp; LF++)
        {
            if ((LightFuncMask & (1 << LF)) == 0)
                continue;
//找到这个功能对应的所有通道掩码
            chmask = GetChannelMaskByLightFunction(LF);

            if (LF == E_LowBeamKink)
            {
                if (Get_pLedDerMinCurrLoBeamFlat() > NtcDerateRatio[chid])
                {
                    /*LowBeamFlat的NTC降流比例不能小于pLedDerMinCurrLoBeamFlat这个参数*/
                    NtcDerateRatio[chid] = Get_pLedDerMinCurrLoBeamFlat();

                    if (NtcDerateRatio[chid] > Get_pLedDerMinCurrLoBeamFlat())
                    {
                        // Interface_SetSystemError(E_SystemErrorTypE_LowBeamKinkDerateError, 1);
                    }
                    else
                    {
                        // Interface_SetSystemError(E_SystemErrorTypE_LowBeamKinkDerateError, 0);
                    }
                }
            }
            else if (LF == E_TurnIndicator)
            {
                if (Get_pLedDerMinCurrDirIndcr() > NtcDerateRatio[chid])
                {
                    /*转向灯的NTC降流比例不能小于pLedDerMinCurrLoBeamFlat这个参数*/
                    NtcDerateRatio[chid] = Get_pLedDerMinCurrDirIndcr();
                    if (NtcDerateRatio[chid] > Get_pLedDerMinCurrDirIndcr())
                    {
                        // Interface_SetSystemError(E_SystemErrorType_TIDerateError, 1);
                    }
                    else
                    {
                        // Interface_SetSystemError(E_SystemErrorType_TIDerateError, 0);
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

void NtcDerateMainFunction(uint8_t timebase)
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

            if (TempHy >= 1/* Get_pLedDerTempHys() */)
            {
                gs_CurNtcTmperatureInfo[NtcRcodFunction - E_NtcRcodFunction_Ntc1].CurTemperature = temperature;
            }
            else
            {
                continue;
            }
        }
        CaculateChannelDerateRatio(ChannelMask, temperature);
    }
}


