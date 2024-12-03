/*
 * Buck_Interface.c
 *
 *
 *      Author: mihuiliang
 */

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "Buck_Interface.h"
#include "SystemService_Interface.h"
/****************************************************************
 *                                                              *
 *                  Global Private Variable Define              *
 *                                                              *
 ****************************************************************/
static S_BuckDrv_Dev *g_S_BuckDrv_Dev_Header = NULL;

/****************************************************************
 *                                                              *
 *                  Static Private Function Define              *
 *                                                              *
 ****************************************************************/
static S_BuckDrv_Dev *GetBuckDrvDevByBuckNO(E_BuckNo buckNo)
{
    S_BuckDrv_Dev *tmp = g_S_BuckDrv_Dev_Header;
    while (tmp != NULL)
    {
        if (tmp->Device_id == buckNo)
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
Std_ReturnType Interface_GetBuckChannelMask(E_BuckNo buckid, uint16_t *chmask)
{
    Std_ReturnType rtval = E_OK;
    S_BuckDrv_Dev *BuckDrvDev = NULL;

    BuckDrvDev = GetBuckDrvDevByBuckNO(buckid);
    if (BuckDrvDev == NULL)
        return E_NOT_OK;

    *chmask = BuckDrvDev->ChannelMappingMask;

    return rtval;
}

Std_ReturnType Interface_GetBuckTempterature(E_BuckNo buckid, int16_t *temp)
{
    Std_ReturnType rtval = E_OK;
    S_BuckDrv_Dev *BuckDrvDev = NULL;
    S_BuckDataPackets BuckDataPackets;
    S_BuckTemperatureStateDataSrc BuckTemperatureStateDataSrc;

    BuckDrvDev = GetBuckDrvDevByBuckNO(buckid);

    if (BuckDrvDev == NULL)
        return E_NOT_OK;

    BuckTemperatureStateDataSrc.BuckNo = buckid;

    BuckDataPackets.BuckDataType = E_BuckDataType_BuckTemperature;
    BuckDataPackets.datasrc = (void *)(&BuckTemperatureStateDataSrc);

    rtval |= BuckDrvDev->Read((void *)(&BuckDataPackets));

    if (rtval == E_OK)
    {
        *temp = BuckTemperatureStateDataSrc.BuckTemp;
    }

    return rtval;
}

Std_ReturnType Interface_ReInitAllBuck(void)
{
    Std_ReturnType rtval = E_OK;

    return rtval;
}

Std_ReturnType BuckInterfaceMainFuntion(uint8_t timebase)
{
#if (LIST_ALL_BUCK_AT_ONCE)
    S_BuckDrv_Dev *tmp = g_S_BuckDrv_Dev_Header;
#else
    static S_BuckDrv_Dev *tmp = NULL;
#endif
    Std_ReturnType rtval = E_OK;

    S_BuckDataPackets BuckDataPackets;
    S_BuckMainFunctionDataSrc BuckMainFunctionDataSrc;
    S_BuckDiagStateDataSrc BuckDiagStateDataSrc;
#if (LIST_ALL_BUCK_AT_ONCE)
    while (tmp)
    {
        BuckMainFunctionDataSrc.BuckNo = tmp->Device_id;
        BuckDataPackets.BuckDataType = E_BuckDataType_BuckMainFunction;
        BuckDataPackets.datasrc = (void *)(&BuckMainFunctionDataSrc);
        rtval |= tmp->MainFunction((void *)(&BuckDataPackets));

        BuckDiagStateDataSrc.BuckNo = tmp->Device_id;
        BuckDataPackets.BuckDataType = E_BuckDataType_BuckDiagState;
        BuckDataPackets.datasrc = (void *)(&BuckDiagStateDataSrc);
        rtval |= tmp->Read((void *)(&BuckDataPackets));

        tmp = tmp->ptNext;
    }
#else
    if (tmp == NULL)
    {
        tmp = g_S_BuckDrv_Dev_Header;
        if (tmp == NULL)
            return rtval;
    }
    
    BuckMainFunctionDataSrc.BuckNo = tmp->Device_id;
    BuckDataPackets.BuckDataType = E_BuckDataType_BuckMainFunction;
    BuckDataPackets.datasrc = (void *)(&BuckMainFunctionDataSrc);
    rtval |= tmp->MainFunction((void *)(&BuckDataPackets));

    BuckDiagStateDataSrc.BuckNo = tmp->Device_id;
    BuckDataPackets.BuckDataType = E_BuckDataType_BuckDiagState;
    BuckDataPackets.datasrc = (void *)(&BuckDiagStateDataSrc);
    rtval |= tmp->Read((void *)(&BuckDataPackets));

    tmp = tmp->ptNext;
#endif
    return rtval;
}

S_BuckDrv_Dev *GetBuckDrvDevByChId(E_ChannelID id)
{
    S_BuckDrv_Dev *tmp = g_S_BuckDrv_Dev_Header;
    while (tmp != NULL)
    {
        if ((tmp->ChannelMappingMask & (1 << id)) != 0)
            return tmp;
        tmp = tmp->ptNext;
    }
    return NULL;
}

Std_ReturnType Interface_BuckInit(void)
{
    Std_ReturnType rtval = E_OK;
    S_BuckDrv_Dev *tmp = g_S_BuckDrv_Dev_Header;
    S_BuckInitDataSrc BuckInitDataSrc;
    S_BuckDataPackets BuckDataPackets;
    while (tmp)
    {
        BuckInitDataSrc.BuckNo = tmp->Device_id;
        BuckDataPackets.BuckDataType = E_BuckDataType_BuckInit;
        BuckDataPackets.datasrc = (void *)(&BuckInitDataSrc);
        rtval |= tmp->DeviceInit((void *)(&BuckDataPackets));

        if (rtval != E_OK)
            return E_NOT_OK;

        tmp = tmp->ptNext;
    }

    return rtval;
}

Std_ReturnType BuckDrvDev_Register(S_BuckDrv_Dev *Drv_Dev)
{
    S_BuckDrv_Dev *tmp = g_S_BuckDrv_Dev_Header;

    if (g_S_BuckDrv_Dev_Header == NULL)
    {
        g_S_BuckDrv_Dev_Header = Drv_Dev;
        g_S_BuckDrv_Dev_Header->ptNext = NULL;
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
