/*
 * PulseGenerator_Interface.c
 *
 *  Created on: 2024��1��22��
 *      Author: mihuiliang
 */

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "PulseGenerator_Interface.h"

/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
static S_PulseGenerator_Dev *g_PulseGenerator_Dev_Header = NULL;

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
static S_PulseGenerator_Dev *GetPulseGeneratorDev(E_PulseGeneratorFunction PulseGeneratorFunction)
{
    S_PulseGenerator_Dev *tmp;

    tmp = g_PulseGenerator_Dev_Header;

    while (tmp)
    {
        if (tmp->PulseGeneratorFunction == PulseGeneratorFunction)
            return tmp;

        tmp = tmp->ptNext;
    }

    return NULL;
}

/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
Std_ReturnType Interface_SetPulseGnerator(E_PulseGeneratorFunction PulseGeneratorFunction, uint16_t cycle, uint8_t duty)
{
    Std_ReturnType rtval = E_OK;
    S_PulseGenerator_Dev *PulseGenerator_Dev = NULL;
    S_PwmValueDataSrc PwmValueDataSrc;
    S_PulseGeneratorDataPackets PulseGeneratorDataPackets;
    PulseGenerator_Dev = GetPulseGeneratorDev(PulseGeneratorFunction);

    if (PulseGenerator_Dev == NULL)
        return E_NOT_OK;

    if (duty > 100)
        duty = 100;

    PwmValueDataSrc.cycle = cycle;
    PwmValueDataSrc.duty = duty;
    PwmValueDataSrc.PulseGeneratorFunction = PulseGeneratorFunction;
    PulseGeneratorDataPackets.PulseGeneratorDataType = E_PulseGeneratorDataType_PWM;
    PulseGeneratorDataPackets.datasrc = (void *)(&PwmValueDataSrc);

    rtval |= PulseGenerator_Dev->Write((void *)(&PulseGeneratorDataPackets));

    return rtval;
}
Std_ReturnType Interface_DisablePulseGenerator(E_PulseGeneratorFunction PulseGeneratorFunction, uint16_t cycle, uint8_t duty)
{
    Std_ReturnType rtval = E_OK;
    S_PulseGenerator_Dev *PulseGenerator_Dev = NULL;
    S_PwmValueDataSrc PwmValueDataSrc;
    S_PulseGeneratorDataPackets PulseGeneratorDataPackets;
    PulseGenerator_Dev = GetPulseGeneratorDev(PulseGeneratorFunction);

    if (PulseGenerator_Dev == NULL)
        return E_NOT_OK;

    PwmValueDataSrc.cycle = cycle;
    PwmValueDataSrc.duty = 0;
    PwmValueDataSrc.PulseGeneratorFunction = PulseGeneratorFunction;
    PulseGeneratorDataPackets.PulseGeneratorDataType = E_PulseGeneratorDataType_PWM;
    PulseGeneratorDataPackets.datasrc = (void *)(&PwmValueDataSrc);

    rtval |= PulseGenerator_Dev->Write((void *)(&PulseGeneratorDataPackets));

    return rtval;
}
Std_ReturnType Interface_EnablePulseGenerator(E_PulseGeneratorFunction PulseGeneratorFunction, uint16_t cycle, uint8_t duty)
{
    Std_ReturnType rtval = E_OK;
    S_PulseGenerator_Dev *PulseGenerator_Dev = NULL;
    S_PwmValueDataSrc PwmValueDataSrc;
    S_PulseGeneratorDataPackets PulseGeneratorDataPackets;
    PulseGenerator_Dev = GetPulseGeneratorDev(PulseGeneratorFunction);

    if (PulseGenerator_Dev == NULL)
        return E_NOT_OK;

    if (duty > 100)
        duty = 100;

    PwmValueDataSrc.cycle = cycle;
    PwmValueDataSrc.duty = duty;
    PwmValueDataSrc.PulseGeneratorFunction = PulseGeneratorFunction;
    PulseGeneratorDataPackets.PulseGeneratorDataType = E_PulseGeneratorDataType_PWM;
    PulseGeneratorDataPackets.datasrc = (void *)(&PwmValueDataSrc);

    rtval |= PulseGenerator_Dev->Write((void *)(&PulseGeneratorDataPackets));

    return rtval;
}
/*设置Pin的模式 */
Std_ReturnType Interface_SetPinMode(E_PulseGeneratorFunction PulseGeneratorFunction, E_PinMode PinMode)
{
    Std_ReturnType rtval = E_OK;
    S_PulseGenerator_Dev *PulseGenerator_Dev = NULL;
    S_PulseGeneratorDataPackets PulseGeneratorDataPackets;
    S_PinModeDataSrc PinModeDataSrc;
    E_PinMode SetPinMode;

    PulseGenerator_Dev = GetPulseGeneratorDev(PulseGeneratorFunction);
    if (PulseGenerator_Dev == NULL)
        return E_NOT_OK;

    SetPinMode = PinMode;
    PinModeDataSrc.PulseGeneratorFunction = PulseGeneratorFunction;
    PinModeDataSrc.PinMode = &SetPinMode;
    PulseGeneratorDataPackets.PulseGeneratorDataType = E_PulseGeneratorDataType_PinMode;
    PulseGeneratorDataPackets.datasrc = (void *)(&PinModeDataSrc);

    rtval |= PulseGenerator_Dev->Write((void *)(&PulseGeneratorDataPackets));

    return rtval;
}
/*获得Pin的模式*/
Std_ReturnType Interface_GetPinMode(E_PulseGeneratorFunction PulseGeneratorFunction, E_PinMode *PinMode)
{
    Std_ReturnType rtval = E_OK;
    S_PulseGenerator_Dev *PulseGenerator_Dev = NULL;
    S_PulseGeneratorDataPackets PulseGeneratorDataPackets;
    S_PinModeDataSrc PinModeDataSrc;

    PulseGenerator_Dev = GetPulseGeneratorDev(PulseGeneratorFunction);
    if (PulseGenerator_Dev == NULL)
        return E_NOT_OK;

    PinModeDataSrc.PulseGeneratorFunction = PulseGeneratorFunction;
    PinModeDataSrc.PinMode = PinMode;
    PulseGeneratorDataPackets.PulseGeneratorDataType = E_PulseGeneratorDataType_PinMode;
    PulseGeneratorDataPackets.datasrc = (void *)(&PinModeDataSrc);

    rtval |= PulseGenerator_Dev->Read((void *)(&PulseGeneratorDataPackets));

    return rtval;
}

Std_ReturnType Interface_SetPinState(E_PulseGeneratorFunction PulseGeneratorFunction, E_PinState PinState)
{
    Std_ReturnType rtval = E_OK;
    S_PulseGenerator_Dev *PulseGenerator_Dev = NULL;
    S_PulseGeneratorDataPackets PulseGeneratorDataPackets;
    S_PinStateDataSrc PinStateDataSrc;
    E_PinState SetPinState;

    PulseGenerator_Dev = GetPulseGeneratorDev(PulseGeneratorFunction);
    if (PulseGenerator_Dev == NULL)
        return E_NOT_OK;

    SetPinState = PinState;
    PinStateDataSrc.PulseGeneratorFunction = PulseGeneratorFunction;
    PinStateDataSrc.PinState = &SetPinState;
    PulseGeneratorDataPackets.PulseGeneratorDataType = E_PulseGeneratorDataType_PinState;
    PulseGeneratorDataPackets.datasrc = (void *)(&PinStateDataSrc);

    rtval |= PulseGenerator_Dev->Write((void *)(&PulseGeneratorDataPackets));

    return rtval;
}

Std_ReturnType Interface_GetPinState(E_PulseGeneratorFunction PulseGeneratorFunction, E_PinState *PinState)
{
    Std_ReturnType rtval = E_OK;
    S_PulseGenerator_Dev *PulseGenerator_Dev = NULL;
    S_PulseGeneratorDataPackets PulseGeneratorDataPackets;
    S_PinStateDataSrc PinStateDataSrc;

    PulseGenerator_Dev = GetPulseGeneratorDev(PulseGeneratorFunction);
    if (PulseGenerator_Dev == NULL)
        return E_NOT_OK;

    PinStateDataSrc.PulseGeneratorFunction = PulseGeneratorFunction;
    PinStateDataSrc.PinState = PinState;
    PulseGeneratorDataPackets.PulseGeneratorDataType = E_PulseGeneratorDataType_PinState;
    PulseGeneratorDataPackets.datasrc = (void *)(&PinStateDataSrc);

    rtval |= PulseGenerator_Dev->Read((void *)(&PulseGeneratorDataPackets));

    return rtval;
}

Std_ReturnType Interface_IcuStart(E_PulseGeneratorFunction PulseGeneratorFunction, E_IcuMode IcuMode)
{
    Std_ReturnType rtval = E_OK;
    S_PulseGenerator_Dev *PulseGenerator_Dev = NULL;
    S_PulseGeneratorDataPackets PulseGeneratorDataPackets;
    S_ICUStartDataSrc ICUStartDataSrc;

    PulseGenerator_Dev = GetPulseGeneratorDev(PulseGeneratorFunction);
    if (PulseGenerator_Dev == NULL)
        return E_NOT_OK;

    ICUStartDataSrc.PulseGeneratorFunction = PulseGeneratorFunction;
    ICUStartDataSrc.IcuMode = IcuMode;
    PulseGeneratorDataPackets.PulseGeneratorDataType = E_PulseGeneratorDataType_ICU_Start;
    PulseGeneratorDataPackets.datasrc = (void *)(&ICUStartDataSrc);

    rtval |= PulseGenerator_Dev->Write((void *)(&PulseGeneratorDataPackets));

    return rtval;
}


Std_ReturnType Interface_IcuStop(E_PulseGeneratorFunction PulseGeneratorFunction)
{
    Std_ReturnType rtval = E_OK;
    S_PulseGenerator_Dev *PulseGenerator_Dev = NULL;
    S_PulseGeneratorDataPackets PulseGeneratorDataPackets;
    S_ICUStopDataSrc ICUStopDataSrc;

    PulseGenerator_Dev = GetPulseGeneratorDev(PulseGeneratorFunction);
    if (PulseGenerator_Dev == NULL)
        return E_NOT_OK;

    ICUStopDataSrc.PulseGeneratorFunction = PulseGeneratorFunction;
    PulseGeneratorDataPackets.PulseGeneratorDataType = E_PulseGeneratorDataType_ICU_Stop;
    PulseGeneratorDataPackets.datasrc = (void *)(&ICUStopDataSrc);

    rtval |= PulseGenerator_Dev->Write((void *)(&PulseGeneratorDataPackets));

    return rtval;
}


Std_ReturnType Interface_RequestResult(E_PulseGeneratorFunction PulseGeneratorFunction, uint32_t* Number)
{
    Std_ReturnType rtval = E_OK;
    S_PulseGenerator_Dev *PulseGenerator_Dev = NULL;
    S_PulseGeneratorDataPackets PulseGeneratorDataPackets;
    S_ICURequestResultDataSrc ICURequestResultDataSrc;

    PulseGenerator_Dev = GetPulseGeneratorDev(PulseGeneratorFunction);
    if (PulseGenerator_Dev == NULL)
        return E_NOT_OK;

    ICURequestResultDataSrc.PulseGeneratorFunction = PulseGeneratorFunction;
    ICURequestResultDataSrc.GetNumber = Number;
    PulseGeneratorDataPackets.PulseGeneratorDataType = E_PulseGeneratorDataType_ICU_RequestResult;
    PulseGeneratorDataPackets.datasrc = (void *)(&ICURequestResultDataSrc);

    rtval |= PulseGenerator_Dev->Read((void *)(&PulseGeneratorDataPackets));

    return rtval;
}




Std_ReturnType Interface_PulseGeneratorInit(void)
{
    Std_ReturnType rtval = E_OK;
    S_PulseGenerator_Dev *tmp = g_PulseGenerator_Dev_Header;
    S_PulseGeneratorInitDataSrc PulseGeneratorInitDataSrc;
    S_PulseGeneratorDataPackets PulseGeneratorDataPackets;

    while (tmp)
    {
        PulseGeneratorInitDataSrc.PulseGeneratorFunction = tmp->PulseGeneratorFunction;
        PulseGeneratorDataPackets.PulseGeneratorDataType = E_PulseGeneratorDataType_Init;
        PulseGeneratorDataPackets.datasrc = (void *)(&PulseGeneratorInitDataSrc);
        rtval |= tmp->DeviceInit((void *)(&PulseGeneratorDataPackets));
        tmp = tmp->ptNext;
    }

    return rtval;
}

Std_ReturnType PulseGeneratorDev_Register(S_PulseGenerator_Dev *Drv_Dev)
{
    S_PulseGenerator_Dev *tmp = g_PulseGenerator_Dev_Header;

    if (g_PulseGenerator_Dev_Header == NULL)
    {
        g_PulseGenerator_Dev_Header = Drv_Dev;
        g_PulseGenerator_Dev_Header->ptNext = NULL;
    }
    else
    {
        while (tmp->ptNext != NULL)
            tmp = tmp->ptNext;
        tmp->ptNext = Drv_Dev;
        Drv_Dev->ptNext = NULL;
    }
    return E_OK;
}
