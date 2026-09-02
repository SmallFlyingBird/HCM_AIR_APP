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
#include "DID_Interface.h"
#include "Rte_Dcm_Callout.h"
/****************************************************************
 *                                                              *
 *                  Global Private Variable Define              *
 *                                                              *
 ****************************************************************/
static S_BuckDrv_Dev *g_S_BuckDrv_Dev_Header = NULL;
typedef struct ChannelControl
{
    uint8 lostcmd;
} S_BuckControl;
S_BuckControl g_S_BuckControl[CHANNEL_NUM];
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
    BuckTemperatureStateDataSrc.BuckTemp = 0;
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
        if (BuckDiagStateDataSrc.BuckDiagState.LostCom == 1)
        {  
            g_S_BuckControl[tmp->Device_id].lostcmd=1;           
        }
        else
        {
            g_S_BuckControl[tmp->Device_id].lostcmd=0;
        }
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


uint8 Interface_GetSPI_LostCmd(void)
{
    uint8 retval=0;
    if (g_S_BuckControl[E_BuckNo1].lostcmd ==1)
    {  
        retval=1;
        Interface_SetD900Data(WDG_Safety_SPI,STATE_ERROR);
        Interface_SetD900Data(In_LED_driver,STATE_ERROR);
    }
    else 
    {
        Interface_SetD900Data(In_LED_driver,STATE_OK);
        if(g_S_BuckControl[E_BuckNo2].lostcmd ==1)
        {
            retval=1;
            Interface_SetD900Data(WDG_Safety_SPI,STATE_ERROR);
        }
        else
        {
            Interface_SetD900Data(WDG_Safety_SPI,STATE_OK);
        }
    }
    return retval;
}


/*
 * 开关所有Buck的LimpHome功能
 * LHState=0：关闭所有buck的LimpHome功能
 * LHState=1：打开所有buck的LimpHome功能（一般应用层不会用这个参数）
 */
Std_ReturnType Interface_SetAllBuckLimpHomeState(uint8_t LHState)
{
    Std_ReturnType rtval = E_OK;
    S_BuckDrv_Dev *tmp = g_S_BuckDrv_Dev_Header;
    S_BuckDataPackets BuckDataPackets;
    S_BuckLimpHomeDataSrc BuckLimpHomeDataSrc;

    /*复位标记置起来以后，BuckLimpHome功能无法被打开*/
    if (ASWInterface_GetEcuResetFlag() == 1)
    {
        if (LHState == 1)
            return E_NOT_OK;
    }

    if (LHState)
    {
        BuckLimpHomeDataSrc.LimpHomeState = 1;
    }
    else
    {
        BuckLimpHomeDataSrc.LimpHomeState = 0;
    }
    BuckDataPackets.BuckDataType = E_BuckDataType_BuckLimpHomeSwitch;
    BuckDataPackets.datasrc = (void *)(&BuckLimpHomeDataSrc);
    while (tmp)
    {
        BuckLimpHomeDataSrc.BuckNo = tmp->Device_id;
        rtval |= tmp->Write((void *)(&BuckDataPackets));
        tmp = tmp->ptNext;
    }
    return rtval;
}

