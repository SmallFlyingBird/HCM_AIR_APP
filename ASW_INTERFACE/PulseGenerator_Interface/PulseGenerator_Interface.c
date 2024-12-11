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

    PwmValueDataSrc = (S_PwmValueDataSrc *)(PulseGeneratorDataPackets->datasrc);
    rtval |= SetPulseGeneratorDutyAndCycle(PwmValueDataSrc->PulseGeneratorFunction, PwmValueDataSrc);

    rtval |= PulseGenerator_Dev->Write((void *)(&PulseGeneratorDataPackets));

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
