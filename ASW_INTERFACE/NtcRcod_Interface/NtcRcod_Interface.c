/*
 * NtcRcod_Interface.c
 *
 *  Created on: 2024��2��22��
 *      Author: mihuiliang
 */

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "NtcRcod_Interface.h"
#include "Parameter_Interface.h"
#include "GeneralFunction.h"
#include "Channel_Interface.h"
#include "DTC_Interface.h"
/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Global Variable Define                     *
 *                                                              *
 ****************************************************************/
static S_NtcRcodInfo gs_NtcRcodInfo[MAX_NTCRCOD_NUM];
static uint8_t NumNtcRcodInfoUsed = 0;
/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/
static Std_ReturnType SetNtcRcodInfo_Rcod(uint8_t BinSrc, E_ChannelID chid)
{
    Std_ReturnType rtval = E_OK;
    uint8_t ntcid;
    uint8_t i = 0;
    E_NtcRcodFunction NtcRcodFunction;

    if (NumNtcRcodInfoUsed >= MAX_NTCRCOD_NUM)
        return E_NOT_OK;

    switch (BinSrc)
    {
    case 1:
        NtcRcodFunction = E_NtcRcodFunction_Rcod1;
        break;
    case 2:
        NtcRcodFunction = E_NtcRcodFunction_Rcod2;
        break;
    case 3:
        NtcRcodFunction = E_NtcRcodFunction_Rcod3;
        break;
    case 4:
        NtcRcodFunction = E_NtcRcodFunction_MatrixRcod1;
        break;
    case 5:
        NtcRcodFunction = E_NtcRcodFunction_MatrixRcod2;
        break;
    }

    for (i = 0; i < NumNtcRcodInfoUsed; i++)
    {
        if (gs_NtcRcodInfo[i].NtcRcodFunction == NtcRcodFunction)
        {
            gs_NtcRcodInfo[i].Map2ChannelMask |= (1 << chid);
            return E_OK;
        }
    }

    if (BinSrc <= 3)
    {
        /*Rcod use MCU ADC*/
        ntcid = Get_pBinRcodToNTC(BinSrc);
        gs_NtcRcodInfo[NumNtcRcodInfoUsed].NtcRcodFunction = NtcRcodFunction;
        switch (ntcid)
        {
        case 1:
            gs_NtcRcodInfo[NumNtcRcodInfoUsed].NtcRcodMapToAdcFunction = E_AdcFunction_NTC1;
            break;
        case 2:
            gs_NtcRcodInfo[NumNtcRcodInfoUsed].NtcRcodMapToAdcFunction = E_AdcFunction_NTC2;
            break;
        case 3:
            gs_NtcRcodInfo[NumNtcRcodInfoUsed].NtcRcodMapToAdcFunction = E_AdcFunction_NTC3;
            break;
        case 4:
            gs_NtcRcodInfo[NumNtcRcodInfoUsed].NtcRcodMapToAdcFunction = E_AdcFunction_NTC4;
            break;
        case 5:
            gs_NtcRcodInfo[NumNtcRcodInfoUsed].NtcRcodMapToAdcFunction = E_AdcFunction_NTC5;
            break;
        case 6:
            gs_NtcRcodInfo[NumNtcRcodInfoUsed].NtcRcodMapToAdcFunction = E_AdcFunction_NTC6;
            break;
        }
    }
    else
    {
        /*Rcod use LMM ADC*/
        switch (BinSrc)
        {
        case 4:
            gs_NtcRcodInfo[NumNtcRcodInfoUsed].NtcRcodFunction = E_NtcRcodFunction_MatrixRcod1;
            gs_NtcRcodInfo[NumNtcRcodInfoUsed].LMMAddress = Get_pLMMAddRcod1();
            gs_NtcRcodInfo[NumNtcRcodInfoUsed].LMMAdcPort = Get_pLMMAdcPortRcod1();
            break;
        case 5:
            gs_NtcRcodInfo[NumNtcRcodInfoUsed].NtcRcodFunction = E_NtcRcodFunction_MatrixRcod2;
            gs_NtcRcodInfo[NumNtcRcodInfoUsed].LMMAddress = Get_pLMMAddRcod2();
            gs_NtcRcodInfo[NumNtcRcodInfoUsed].LMMAdcPort = Get_pLMMAdcPortRcod2();
            break;
        }
    }
    gs_NtcRcodInfo[NumNtcRcodInfoUsed].Map2ChannelMask = (1 << chid);
    gs_NtcRcodInfo[NumNtcRcodInfoUsed].DefaultRcodIndrexOrFaultNtcTemp = Get_pDefaultRcodIndexChByChannelID(chid);
    gs_NtcRcodInfo[NumNtcRcodInfoUsed].bufferindex = 0;
    gs_NtcRcodInfo[NumNtcRcodInfoUsed].DataFirstCalcuComplete = 0;
    NumNtcRcodInfoUsed++;

    return rtval;
}

static Std_ReturnType SetNtcRcodInfo_NTC(uint8_t NtcId, E_ChannelID chid)
{
    Std_ReturnType rtval = E_OK;
    uint8_t i = 0;
    E_NtcRcodFunction NtcRcodFunction = E_NtcRcodFunction_NONE;

    if (NumNtcRcodInfoUsed >= MAX_NTCRCOD_NUM)
        return E_NOT_OK;

    switch (NtcId)
    {
    case 1:
        NtcRcodFunction = E_NtcRcodFunction_Ntc1;
        break;
    case 2:
        NtcRcodFunction = E_NtcRcodFunction_Ntc2;
        break;
    case 3:
        NtcRcodFunction = E_NtcRcodFunction_Ntc3;
        break;
    case 4:
        NtcRcodFunction = E_NtcRcodFunction_Ntc4;
        break;
    case 5:
        NtcRcodFunction = E_NtcRcodFunction_Ntc5;
        break;
    case 6:
        NtcRcodFunction = E_NtcRcodFunction_Ntc6;
        break;
    case 7:
        NtcRcodFunction = E_NtcRcodFunction_MatrixNtc1;
        break;
    case 8:
        NtcRcodFunction = E_NtcRcodFunction_MatrixNtc2;
        break;
    }
    for (i = 0; i < NumNtcRcodInfoUsed; i++)
    {
        if (gs_NtcRcodInfo[i].NtcRcodFunction == NtcRcodFunction)
        {
            gs_NtcRcodInfo[i].Map2ChannelMask |= (1 << chid);
            return E_OK;
        }
    }

    gs_NtcRcodInfo[NumNtcRcodInfoUsed].NtcRcodFunction = NtcRcodFunction;

    switch (NtcId)
    {
    case 1:
        gs_NtcRcodInfo[NumNtcRcodInfoUsed].NtcRcodMapToAdcFunction = E_AdcFunction_NTC1;
        break;
    case 2:
        gs_NtcRcodInfo[NumNtcRcodInfoUsed].NtcRcodMapToAdcFunction = E_AdcFunction_NTC2;
        break;
    case 3:
        gs_NtcRcodInfo[NumNtcRcodInfoUsed].NtcRcodMapToAdcFunction = E_AdcFunction_NTC3;
        break;
    case 4:
        gs_NtcRcodInfo[NumNtcRcodInfoUsed].NtcRcodMapToAdcFunction = E_AdcFunction_NTC4;
        break;
    case 5:
        gs_NtcRcodInfo[NumNtcRcodInfoUsed].NtcRcodMapToAdcFunction = E_AdcFunction_NTC5;
        break;
    case 6:
        gs_NtcRcodInfo[NumNtcRcodInfoUsed].NtcRcodMapToAdcFunction = E_AdcFunction_NTC6;
        break;
    case 7:
        gs_NtcRcodInfo[NumNtcRcodInfoUsed].LMMAddress = Get_pLMMAddNTC_Mx1();
        gs_NtcRcodInfo[NumNtcRcodInfoUsed].LMMAdcPort = Get_pLMMAdcPort_Mx1();
        break;
    case 8:
        gs_NtcRcodInfo[NumNtcRcodInfoUsed].LMMAddress = Get_pLMMAddNTC_Mx2();
        gs_NtcRcodInfo[NumNtcRcodInfoUsed].LMMAdcPort = Get_pLMMAdcPort_Mx2();
        break;
    }

    gs_NtcRcodInfo[NumNtcRcodInfoUsed].Map2ChannelMask = (1 << chid);
    gs_NtcRcodInfo[NumNtcRcodInfoUsed].DefaultRcodIndrexOrFaultNtcTemp = Get_pNtcFaultTemp(NtcId);
    gs_NtcRcodInfo[NumNtcRcodInfoUsed].bufferindex = 0;
    gs_NtcRcodInfo[NumNtcRcodInfoUsed].DataFirstCalcuComplete = 0;
    NumNtcRcodInfoUsed++;
    return rtval;
}

/*
 * return  unit:mΩ
 * Pull-up resistor = 10k
 */
static uint32_t CaculateNtcOrRcodRegister(uint32_t AdcDigitalVal, E_AdcAccuracy AdcAccuracy)
{
    uint32_t adcwitch;
    uint32_t rtval;

    adcwitch = GetAdcWidth(AdcAccuracy);

    rtval = (10000 * AdcDigitalVal) / (adcwitch - AdcDigitalVal);

    return (rtval * 1000);
}
/*
 *   if Rcod index is out of range,return E_NOT_OK;
 */
static Std_ReturnType CaculateRcodCurrent(uint32_t AdcDigitalVal, E_AdcAccuracy AdcAccuracy, uint8 RcodIndex, uint16 *current)
{
    Std_ReturnType rtval = E_OK;
    uint32_t RcodRegister = 0;
    uint16 current_tmp = 0;
    RcodRegister = CaculateNtcOrRcodRegister(AdcDigitalVal, AdcAccuracy);

    current_tmp = GetRcodCurrentByRegisterVal((RcodRegister / 1000), RcodIndex);

    if (current_tmp == 0xFFFF)
        return E_NOT_OK;
    else
        *current = current_tmp;

    return rtval;
}

static Std_ReturnType CaculateNtcTemp(uint32_t AdcDigitalVal, E_AdcAccuracy AdcAccuracy, uint8 NtcIndex, sint16 *temp)
{
    Std_ReturnType rtval = E_OK;
    uint32_t NtcRegister = 0;
    uint8_t tmp;
    uint8_t ntctype;

    NtcRegister = CaculateNtcOrRcodRegister(AdcDigitalVal, AdcAccuracy);

    ntctype = Get_pNtcType(NtcIndex);

    tmp = GetNtcTempByRegisterVal(NtcRegister, ntctype);

    if (tmp == 0)
        return E_NOT_OK;
    else
        *temp = (sint16)tmp - 50;

    return rtval;
}
/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
Std_ReturnType Interface_GetNtcRcodMap2ChannelMask(E_NtcRcodFunction NtcRcodFunction, uint16_t *channelmask)
{
    uint8_t i = 0;
    for (i = 0; i < NumNtcRcodInfoUsed; i++)
    {
        if (gs_NtcRcodInfo[i].NtcRcodFunction == NtcRcodFunction)
        {
            *channelmask = gs_NtcRcodInfo[i].Map2ChannelMask;
            return E_OK;
        }
    }

    return E_NOT_OK;
}
Std_ReturnType Interface_GetNtcTemperature(E_NtcRcodFunction NtcRcodFunction, sint16 *tmp)
{
    uint8_t i;
    for (i = 0; i < NumNtcRcodInfoUsed; i++)
    {
        if (gs_NtcRcodInfo[i].NtcRcodFunction == NtcRcodFunction)
        {
            if (gs_NtcRcodInfo[i].DataFirstCalcuComplete == 1)
            {
                *tmp = gs_NtcRcodInfo[i].NtcTemp;
                return E_OK;
            }
            else
            {
                /*Ntc has not caculate complete*/
                return E_NOT_OK;
            }
        }
    }
    /*Ntc not configed */
    return E_NOT_OK;
}

Std_ReturnType Interface_GetRcodCurrent(E_NtcRcodFunction NtcRcodFunction, uint16 *current)
{
    Std_ReturnType rtval = E_OK;

    return rtval;
}

Std_ReturnType Interface_NtcRcodInit(void)
{
    E_ChannelID chid = ChannelID1;
    uint8_t BinSrc;
    uint8_t ntcid;
    Std_ReturnType rtval = E_OK;

    for (chid = ChannelID1; chid <= ChannelID4; chid++)
    {
        /*Deal with Rcod*/
        if (Get_pRcodEnable() == 1)
        {
            BinSrc = Get_pBinSrcChByChannelID(chid);
            if ((BinSrc != 0) && (BinSrc <= 5))
            {
                rtval |= SetNtcRcodInfo_Rcod(BinSrc, chid);
            }
        }

        /*Deal with NTC*/
        ntcid = Get_pLedChToNtc(chid);
        if (ntcid != 0)
        {
            SetNtcRcodInfo_NTC(ntcid, chid);
        }
    }
    return rtval;
}
