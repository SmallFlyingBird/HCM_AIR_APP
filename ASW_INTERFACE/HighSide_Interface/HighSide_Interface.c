/*
 * HighSide_Interface.c
 *
 *  Created on: 2024��2��21��
 *      Author: mihuiliang
 */

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "Dio.h"
#include "HighSide_Interface.h"
#include "DTC_Interface.h"
#include "GeneralFunction.h"
#include "Parameter_Interface.h"
/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
static S_HighSideDrv_Dev *gs_HighSideDrv_Dev_Header = NULL;
static E_HSDChannelSwitchState gE_HSDChannelSwitchState[CHANNEL_SIZE] = {E_HSDChannelSwitchState_OFF, E_HSDChannelSwitchState_OFF, E_HSDChannelSwitchState_OFF, E_HSDChannelSwitchState_OFF};
static uint8_t Output5vState = 0;
static S_HSDErrCnt gs_HSDErrCnt[CHANNEL_SIZE];
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
static S_HighSideDrv_Dev *GetHighSideDrvDev(E_HSChannel HSChannel)
{
    S_HighSideDrv_Dev *tmp = gs_HighSideDrv_Dev_Header;

    while (tmp)
    {
        if ((tmp->HsdChMappingMask & (1 << HSChannel)) != 0)
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
Std_ReturnType Interface_GetHighSideChannelCurrent(E_HSChannel HSChannel, uint16_t *current)
{
    Std_ReturnType rtval = E_OK;
    S_HighSideDrv_Dev *tmp = NULL;
    S_HighSideCurrentDataSrc HighSideCurrentDataSrc;
    S_HighSidekDataPackets HighSidekDataPackets;
    tmp = GetHighSideDrvDev(HSChannel);

    if (tmp == NULL)
        return E_NOT_OK;

    HighSideCurrentDataSrc.HSChannel = HSChannel;

    HighSidekDataPackets.HighSideDataType = E_HighSideDataType_ChannelCurrent;
    HighSidekDataPackets.datasrc = (void *)&HighSideCurrentDataSrc;

    rtval |= tmp->Read((void *)(&HighSidekDataPackets));

    if (rtval == E_OK)
    {
        *current = HighSideCurrentDataSrc.current;
    }

    return rtval;
}

Std_ReturnType Interface_GetHighSideChannelDiagInfo(E_HSChannel HSChannel, U_HSChannelDiagInfo *HSChannelDiagInfo)
{
    Std_ReturnType rtval = E_OK;
    S_HighSideDrv_Dev *tmp = NULL;
    S_HighSideDiagDataSrc HighSideDiagDataSrc;
    S_HighSidekDataPackets HighSidekDataPackets;
    tmp = GetHighSideDrvDev(HSChannel);

    if (tmp == NULL)
        return E_NOT_OK;

    HighSideDiagDataSrc.HSChannel = HSChannel;

    HighSidekDataPackets.HighSideDataType = E_HighSideDataType_ChannelDiagInfo;
    HighSidekDataPackets.datasrc = (void *)&HighSideDiagDataSrc;

    rtval |= tmp->Read((void *)(&HighSidekDataPackets));

    if (rtval == E_OK)
    {
        *HSChannelDiagInfo = HighSideDiagDataSrc.HSChannelDiagInfo;
    }

    return rtval;
}
Std_ReturnType Interface_GetHighSideState(E_HSChannel HSChannel, E_HSDChannelSwitchState *Sts)
{
    S_HighSideDrv_Dev *tmp = NULL;

    tmp = GetHighSideDrvDev(HSChannel);
    if (tmp == NULL)
        return E_NOT_OK;

    *Sts = gE_HSDChannelSwitchState[HSChannel];

    return E_OK;
}
Std_ReturnType Interface_SetHighSideState(E_HSChannel HSChannel, E_HSDChannelSwitchState Sts)
{
    Std_ReturnType rtval = E_OK;
    S_HighSideDrv_Dev *tmp = NULL;
    S_HighSideSwitchStateDataSrc HighSideSwitchStateDataSrc;
    S_HighSidekDataPackets HighSidekDataPackets;

    tmp = GetHighSideDrvDev(HSChannel);

    if (tmp == NULL)
        return E_NOT_OK;

    if (gE_HSDChannelSwitchState[HSChannel] == Sts)
        return E_OK;

    HighSideSwitchStateDataSrc.HSChannel = HSChannel;
    HighSideSwitchStateDataSrc.HsdState = Sts;

    HighSidekDataPackets.HighSideDataType = E_HighSideDataType_ChannelSwitch;
    HighSidekDataPackets.datasrc = (void *)&HighSideSwitchStateDataSrc;

    rtval |= tmp->Write((void *)(&HighSidekDataPackets));

    if (rtval == E_OK)
    {
        gE_HSDChannelSwitchState[HSChannel] = Sts;
    }

    return rtval;
}

Std_ReturnType Interface_Enable5VOut(void)
{
    /**
     * OUT_CON_5V:
     * STD_HIGH: Enable 5V OUTPUT
     * STD_LOW: DISABLE 5V OUTPUT
     * */
    Dio_WriteChannel(0x10, STD_HIGH);
    Output5vState = 1;

    return E_OK;
}

Std_ReturnType Interface_Disable5VOut(void)
{
    /**
     * OUT_CON_5V:
     * STD_HIGH: Enable 5V OUTPUT
     * STD_LOW: DISABLE 5V OUTPUT
     * */
    Dio_WriteChannel(0x10, STD_LOW);

    Output5vState = 0;

    return E_OK;
}

Std_ReturnType HighSide_Interface_Mainfunction(uint8_t timebase)
{
    Std_ReturnType rtval = E_OK;
    S_HighSideDrv_Dev *tmp = gs_HighSideDrv_Dev_Header;
    S_HighSideDevMainFuncDataSrc HighSideDevMainFuncDataSrc;
    S_HighSidekDataPackets HighSidekDataPackets;
    U_HSChannelDiagInfo HSChannelDiagInfo;
    uint8_t i = 0;

    while (tmp)
    {
        if (tmp->MainFunction != NULL)
        {
            HighSideDevMainFuncDataSrc.Device_id = tmp->Device_id;
            HighSidekDataPackets.HighSideDataType = E_HighSideDataType_DeviceMainFunction;
            HighSidekDataPackets.datasrc = (void *)(&HighSideDevMainFuncDataSrc);

            rtval |= tmp->MainFunction((void *)(&HighSidekDataPackets));
        }

        tmp = tmp->ptNext;
    }

    for (i = 0; i < CHANNEL_SIZE; i++)
    {
        if (gE_HSDChannelSwitchState[i] == E_HSDChannelSwitchState_OFF)
            continue;

        if (Interface_GetHighSideChannelDiagInfo((E_HSChannel)i, &HSChannelDiagInfo) != E_OK)
            continue;

    }
    return rtval;
}

Std_ReturnType Interface_HighSideInit(void)
{
    Std_ReturnType rtval = E_OK;
    S_HighSideDrv_Dev *tmp = gs_HighSideDrv_Dev_Header;
    S_HighSideDevInitDataSrc HighSideDevInitDataSrc;
    S_HighSidekDataPackets HighSidekDataPackets;
    uint16_t LMMSupplyFlag = 0;

    while (tmp)
    {
        HighSideDevInitDataSrc.Device_id = tmp->Device_id;
        HighSidekDataPackets.HighSideDataType = E_HighSideDataType_DeviceInit;
        HighSidekDataPackets.datasrc = (void *)(&HighSideDevInitDataSrc);

        rtval |= tmp->DeviceInit((void *)(&HighSidekDataPackets));

        tmp = tmp->ptNext;
    }

    return rtval;
}

Std_ReturnType HighSideDrvDev_Register(S_HighSideDrv_Dev *Drv_Dev)
{
    S_HighSideDrv_Dev *tmp = gs_HighSideDrv_Dev_Header;

    if (gs_HighSideDrv_Dev_Header == NULL)
    {
        gs_HighSideDrv_Dev_Header = Drv_Dev;
        gs_HighSideDrv_Dev_Header->ptNext = NULL;
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
