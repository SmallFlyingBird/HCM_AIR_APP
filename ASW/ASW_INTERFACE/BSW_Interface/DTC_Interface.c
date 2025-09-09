#include "DTC_Interface.h"
#include "Channel_Interface.h"
#include "DtcConfig.h"
//#include "Rte_E2EXf.h"
#include "Rte_E2E_Callout.h"


#define NTC_NUM 5
#define BIN_NUM 3
#define SUPPLY_NUM 5
#define FANHSD_NUM 12
#define E2E_NUM 11
#define BOOST_BUCK_NUM 2
#define SYSTEM_NUM 28

/****************************************************************
 *                                                              *
 *                   Global Variable Define                     *
 *                                                              *
 ****************************************************************/
//ERROR in buf position
const uint8_t gMap_ChannelShort2GndError[MAX_CHANNLE_NUM] = {44, 47, 51, 55, 59, 63};
const uint8_t gMap_ChannelShort2VccError[MAX_CHANNLE_NUM] = {45, 48, 52, 56, 60, 64};
const uint8_t gMap_ChannelOpenError[MAX_CHANNLE_NUM] = {46, 49, 53, 57, 61, 65};
const uint8_t gMap_ChannelUVError[MAX_CHANNLE_NUM] = {0, 50, 54, 58, 62, 66};
const uint8_t gMap_NtcShort2GndError[NTC_NUM] = {26, 28, 30, 32, 34};
const uint8_t gMap_NtcOpenOrShort2Vcc[NTC_NUM] = {27, 29, 31,33,35};
const uint8_t gMap_BinError[BIN_NUM] = {36, 37, 38};
const uint8_t gMap_SupplyVolError[SUPPLY_NUM] = {9,10,11,12,13};
const uint8_t gMap_FanAndHsdError[FANHSD_NUM] = {22, 20, 21, 25, 23, 24, 14,15,16,17,18,19};
const uint8_t gMap_BoostBuckError[BOOST_BUCK_NUM] = {67, 69};
const uint8_t gMap_SystemError[SYSTEM_NUM] = {71,70, 68, 72, 8, 39,40, 4, 5, 73,74};
const uint8_t gMap_E2EError[E2E_NUM] = {75,76,77,78,79,80,81,82,83,84,85};

static U_Boost_Buck_Error gu_BaseLayerSetBoostBuck_Error;
/*ground lever real time error status*/
static uint8_t ErrorMapValRealTimer[DTC_VALUE_SIZE];
/*Dtc Error Status*/
static uint8_t DtcErrorMapVal[DTC_VALUE_SIZE];
/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/
static uint8_t GetDtcErrorValRealTime(const uint8_t DtcIndex)
{
    if (DtcIndex >= DTC_MAX_SIZE)
        return 0;
    if ((ErrorMapValRealTimer[(DtcIndex >> 3)] & (1 << (DtcIndex & 0x07))) == 0)
        return 0;
    else
        return 1;
}

static uint8_t GetDtcErrorVal(const uint8_t DtcIndex)
{
    if (DtcIndex >= DTC_MAX_SIZE)
        return 0;
    if ((DtcErrorMapVal[(DtcIndex >> 3)] & (1 << (DtcIndex & 0x07))) == 0)
        return 0;
    else
        return 1;
}

static Std_ReturnType SetErrorMapValRealTime(const uint8_t DtcIndex)
{
    if (DtcIndex >= DTC_MAX_SIZE)
        return E_NOT_OK;

    ErrorMapValRealTimer[(DtcIndex >> 3)] |= (1 << (DtcIndex & 0x07));
    return E_OK;
}

static Std_ReturnType ClearErrorMapValRealTime(const uint8_t DtcIndex)
{
    if (DtcIndex >= DTC_MAX_SIZE)
        return E_NOT_OK;
    ErrorMapValRealTimer[(DtcIndex >> 3)] &= ~(1 << (DtcIndex & 0x07));
    return E_OK;
}

static void clearAllErrorMapRealTime(void)
{
    for (uint8 i = 0; i < DTC_VALUE_SIZE; i++)
    {
        ErrorMapValRealTimer[i] = 0;
    }
}

/*************************************************************************************************
 *                                                                                              *
 *                                   Global Functions Define                                    *
 *                                                                                              *
 *************************************************************************************************/

/************************************************CHANNEL ERROR****************************************************/

/***************************************************************NTC ERROR***************************************************************/
void Interface_SetDtcNtcError(E_NtcSignalNo ntcno, E_NtcErrorType ntcerror, uint8_t val)
{
    uint8_t Dtcindex = 0;
    if (ntcno >= NTC_NUM)
        return;
    switch (ntcerror)
    {
    case E_NtcErrorType_OpenOrShort2Vcc:
    {
        Dtcindex = gMap_NtcOpenOrShort2Vcc[ntcno];
    }
    break;
    case E_NtcErrorType_Short2Gnd:
    {
        Dtcindex = gMap_NtcShort2GndError[ntcno];
    }
    break;
    }
    if (val)
    {
        SetErrorMapValRealTime(Dtcindex);
    }
    else
    {
        ClearErrorMapValRealTime(Dtcindex);
    }
}

U_Ntc_Error Interface_GetNtcErrorState(void)
{
    U_Ntc_Error rtval;
    uint8_t Dtcindex = 0;
    E_NtcSignalNo NtcSignalNo;
    rtval.NtcError = 0;
    for (NtcSignalNo = E_NtcSsignalNo_NTC1; NtcSignalNo <= E_NtcSsignalNo_NTC5; NtcSignalNo++)
    {
        Dtcindex = gMap_NtcOpenOrShort2Vcc[NtcSignalNo];
        if (GetDtcErrorValRealTime(Dtcindex) != 0)
        {
            rtval.NtcError |= (1 << (NtcSignalNo * 2));
        }
        Dtcindex = gMap_NtcShort2GndError[NtcSignalNo];
        if (GetDtcErrorValRealTime(Dtcindex) != 0)
        {
            rtval.NtcError |= (1 << (NtcSignalNo * 2 + 1));
        }
    }
    return rtval;
}
/***************************************************************BIN ERROR***************************************************************/
void Interface_SetDtcBinError(E_BinType BinType, uint8_t val)
{
    if (BinType <= E_BinType_Bin3)
    {
        if (val)
        {
            SetErrorMapValRealTime(gMap_BinError[BinType]);
        }     
        else
        {
            ClearErrorMapValRealTime(gMap_BinError[BinType]);
        }
    }
}

U_Bin_Error Interface_GetBinErrorState(void)
{
    U_Bin_Error rtval;
    uint8_t i = 0;
    rtval.BinError = 0;
    for (i = 0; i < BIN_NUM; i++)
    {
        if (GetDtcErrorValRealTime(gMap_BinError[i]) != 0)
        {
            rtval.BinError |= (1 << i);
        }
    }
    return rtval;
}

/***************************************************************KL56 ERROR***************************************************************/
void Interface_SetDtcSupplyVotageError(E_SupplyVoltageErrorType SupplyVoltageErrorType, uint8_t val)
{
    if (val)
    {
        SetErrorMapValRealTime(gMap_SupplyVolError[SupplyVoltageErrorType]);
    }
    else
    {
        ClearErrorMapValRealTime(gMap_SupplyVolError[SupplyVoltageErrorType]);
    }
}

U_SupplyVoltage_Error Interface_GetSupplyVoltageErrorState(void)
{
    U_SupplyVoltage_Error rtval;
    uint8_t i = 0;
    rtval.SupplyVoltageError = 0;
    for (i = 0; i < SUPPLY_NUM; i++)
    {
        if (GetDtcErrorValRealTime(gMap_SupplyVolError[i]) != 0)
        {
            rtval.SupplyVoltageError |= (1 << i);
        }
    }
    return rtval;
}

/***************************************************************FAN ERROR***************************************************************/
void Interface_SetDtcHSDAndFanError(E_HSDAndFanErrorType HSDAndFanErrorType, uint8_t val)
{
    if (val)
    {
        SetErrorMapValRealTime(gMap_FanAndHsdError[HSDAndFanErrorType]);
    }
    else
    {
        ClearErrorMapValRealTime(gMap_FanAndHsdError[HSDAndFanErrorType]);
    }
}

U_HSDAndFan_Error Interface_GetHSDAndFanErrorState(void)
{
    U_HSDAndFan_Error rtval;
    uint8_t i = 0;
    rtval.HsdAndFanError = 0;
    for (i = 0; i < FANHSD_NUM; i++)
    {
        if (GetDtcErrorValRealTime(gMap_FanAndHsdError[i]) != 0)
        {
            rtval.HsdAndFanError |= (1 << i);
        }
    }
    return rtval;
}

/***************************************************************Boost buck ERROE***************************************************************/
void Interface_SetDtcBuckOverTempError(uint8_t val)
{
    if (val)
    {
        gu_BaseLayerSetBoostBuck_Error.bits.Buckx_OVER_TEMP_CONFIRMED = 1;
        SetErrorMapValRealTime(gMap_BoostBuckError[1]);
    }
    else
    {
        gu_BaseLayerSetBoostBuck_Error.bits.Buckx_OVER_TEMP_CONFIRMED = 0;
    }
}

/***************************************************************SYSTEM ERROR***************************************************************/
void Interface_SetSystemError(E_SystemErrorType SystemErrorType, uint8_t val)
{
    if (val)
    {
        SetErrorMapValRealTime(gMap_SystemError[SystemErrorType]);
    }
    else
    {
        ClearErrorMapValRealTime(gMap_SystemError[SystemErrorType]);
    }
}

U_System_Error Interface_GetSystemErrorState(void)
{
    U_System_Error rtval;
    uint8_t i = 0;
    rtval.SystemError = 0;
    for (i = 0; i < SYSTEM_NUM; i++)
    {
        if (GetDtcErrorValRealTime(gMap_SystemError[i]) != 0)
        {
            rtval.SystemError |= (1 << i);
        }
    }

    return rtval;
}

/*10ms Task*/
Std_ReturnType DtcInterfaceMainFunction(uint8_t timebase)
{
    return E_OK;
}

void Interface_DtcInit(void)
{
    uint16_t chmask;
    chmask = Interface_GetChannelMask();
    if ((chmask >> 6) != 0)
    {
        Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 1);
    }
    else
    {
        Interface_SetSystemError(E_SystemErrorType_CentralCfgError, 0);
    }
}


/***************************************************************E2E ERROR***************************************************************/
void Interface_SetDtcE2EError(E_E2EErrorType E2EErrorType, uint8_t val)
{
    if (val)
    {
        SetErrorMapValRealTime(gMap_E2EError[E2EErrorType]);
    }
    else
    {
        ClearErrorMapValRealTime(gMap_E2EError[E2EErrorType]);
    }
}

U_E2EErrorFlag Interface_GetDtcE2EError(void)
{
    U_E2EErrorFlag rtval;
    uint8_t i = 0;
    rtval.E2EErrFlag = 0;
    for (i = 0; i < E2E_NUM; i++)
    {
        if (GetDtcErrorValRealTime(gMap_E2EError[i]) != 0)
        {
            rtval.E2EErrFlag |= (1 << i);
        }
    }
    return rtval;
}

/*获得功能安全的E2E标记位，超时，CRC错误和Counter错误*/
S_E2EStateForFailSafe GetE2EFlagForFailSafe(void)
{
#if (DTC_INF_DIS_E2E == 0)
    return gs_E2EStateForFailSafe;
#else /* (DTC_INF_DIS_E2E == 0) */
    S_E2EStateForFailSafe TestData;
    TestData.E2EErrorFlagForFailSafe.E2EErrFlag = 0u;
    return TestData;
#endif
}



void Interface_ClearAllDtcError(void)
{
    clearAllErrorMapRealTime();
}






