
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
static S_CurNtcTmperatureInfo gs_CurNtcTmperatureInfo[MAX_NTC_NUM] = {
    {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};
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
static void CaculateChannelDerateRatio(uint16_t ChannelMask, sint16 temperature)
{
 
}
/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
uint8_t Interface_GetChannelDerateRatioOfNtc(E_ChannelID id)
{
    if (id > ChannelID4)
        return 100;

    return NtcDerateRatio[id];
}

void NtcDerateMainFunction(uint8_t timebase)
{
    E_NtcRcodFunction NtcRcodFunction = E_NtcRcodFunction_Ntc1;
    sint16 temperature;
    uint16_t ChannelMask;
    uint8_t TempHy;

    for (NtcRcodFunction = E_NtcRcodFunction_Ntc1; NtcRcodFunction <= E_NtcRcodFunction_MatrixNtc2; NtcRcodFunction++)
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