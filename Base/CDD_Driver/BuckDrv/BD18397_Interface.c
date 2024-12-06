/***

***/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Platform_Types.h"
#include "BD18397.h"
#include "BD18397_interface.h"

#include "AswInterfaceManager.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define BD18397_INTERFACE_C_DRIVER_MAJOR_VERSION 0
#define BD18397_INTERFACE_C_DRIVER_MINOR_VERSION 0
#if (BD18397_INTERFACE_C_DRIVER_MAJOR_VERSION != BD18397_H_DRIVER_MAJOR_VERSION)
#error "BD18397_Interface.c and BD18397.h have different version id, please check files compatibility"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

const BD18397_ChannelMappingType buch_ch_hwch_mapping_Gen2[6] = {
    {0, 2}, /*channel1 is map to device_id:0 hw_ch:2(1st ic and SW3)*/
    {0, 0}, /*channel3 is map to device_id:0 hw_ch:0(1st Ic and SW1)*/
    {1, 0}, /*channel4 is map to device_id:1 hw_ch:0(2nd Ic and SW1)*/
    {1, 2}, /*channel5 is map to device_id:1 hw_ch:2(2nd Ic and SW3)*/
    {1, 1}, /*channel6 is map to device_id:1 hw_ch:1(2nd Ic and SW2)*/
    {0, 1}, /*channel12 is map to device_id:0 hw_ch:1(1st Ic and SW2)*/
};


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
static S_BuckDrv_Dev BD18398Device_Gen2[] = {
    {.BuckDeviceType = E_BuckDrvDev_BD18398,
     .ChannelMappingMask = 0x0031, /*CH5（CH1'）,CH4,CH1*/
     .Device_id = E_BuckNo1,
     .DeviceDeInit = BD18397DeInitFun,
     .DeviceInit = BD18397InitFun,
     .MainFunction = BD18397task,
     .ptNext = NULL_PTR,
     .Read = BD18397ReadFun,
     .Write = BD18397WriteFun},
    {.BuckDeviceType = E_BuckDrvDev_BD18398,
     .ChannelMappingMask = 0x0046, /*CH3,CH3,CH6(CH2')*/
     .Device_id = E_BuckNo2,
     .DeviceDeInit = BD18397DeInitFun,
     .DeviceInit = BD18397InitFun,
     .MainFunction = BD18397task,
     .ptNext = NULL_PTR,
     .Read = BD18397ReadFun,
     .Write = BD18397WriteFun},
};

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

static Std_ReturnType BD18397SetChannelCurrent(S_ChannelCurrentDataSrc *ptr)
{
    Std_ReturnType res = E_OK;
    uint8 device_id;
    uint8 hw_ch;

    device_id = buch_ch_hwch_mapping_Gen2[ptr->ChannelID].device_id;
    hw_ch = buch_ch_hwch_mapping_Gen2[ptr->ChannelID].hw_ch;
    /*call lower level funtion */
    res |= BD18397SetICH(device_id, hw_ch, BD18397_SNSN_R, ptr->CurrentValue);
    return res;
}

static Std_ReturnType BD18397SetPWMDutyCycle(S_ChannelPwmDataSrc *ptr)
{
    Std_ReturnType res = E_OK;
    uint8 device_id;
    uint8 hw_ch;

    device_id = buch_ch_hwch_mapping_Gen2[ptr->ChannelID].device_id;
    hw_ch = buch_ch_hwch_mapping_Gen2[ptr->ChannelID].hw_ch;
    /*call lower level funtion */
    res |= BD18397SetPWM(device_id, hw_ch, ptr->PwmValue);
    return res;
}

static Std_ReturnType BD18397SetSwitchState(S_ChannelSwitchStateDataSrc *ptr)
{
    Std_ReturnType res = E_OK;
    uint8 device_id;
    uint8 hw_ch;

    device_id = buch_ch_hwch_mapping_Gen2[ptr->ChannelID].device_id;
    hw_ch = buch_ch_hwch_mapping_Gen2[ptr->ChannelID].hw_ch;
    /*call lower level funtion */
    res |= BD18397SetHwCHCtrl(device_id, hw_ch, ptr->SwitchStateValue);
    return res;
}

static Std_ReturnType BD18397SetLimphomeState(S_BuckLimpHomeDataSrc *ptr)
{
    Std_ReturnType res = E_OK;
    if(ptr->LimpHomeState==0)
    {
        BD18397SetLHDisable(ptr->BuckNo);//close limphome
    }
    else
    {
        BD18397SetLHEnable(ptr->BuckNo);//open limphome
    }    
    return res;
}

static Std_ReturnType BD18397GetSwitchState(S_ChannelSwitchStateDataSrc *ptr)
{
    Std_ReturnType res = E_OK;
    uint8 device_id;
    uint8 hw_ch;

    device_id = buch_ch_hwch_mapping_Gen2[ptr->ChannelID].device_id;
    hw_ch = buch_ch_hwch_mapping_Gen2[ptr->ChannelID].hw_ch;
    /*call lower level funtion */
    res |= BD18397GetHwCHCtrl(device_id, hw_ch, &(ptr->SwitchStateValue));
    return res;
}

static Std_ReturnType BD18397GetChannelCurrent(S_ChannelCurrentDataSrc *ptr)
{
    Std_ReturnType res = E_OK;
    uint8 device_id;
    uint8 hw_ch;

    device_id = buch_ch_hwch_mapping_Gen2[ptr->ChannelID].device_id;
    hw_ch = buch_ch_hwch_mapping_Gen2[ptr->ChannelID].hw_ch;
    /*call lower level funtion */
    res |= BD18397GetICH(device_id, hw_ch, BD18397_SNSN_R, &(ptr->CurrentValue));
    return res;
}

static Std_ReturnType BD18397GetPWMDutyCycle(S_ChannelPwmDataSrc *ptr)
{
    Std_ReturnType res = E_OK;
    uint8 device_id;
    uint8 hw_ch;

    device_id = buch_ch_hwch_mapping_Gen2[ptr->ChannelID].device_id;
    hw_ch = buch_ch_hwch_mapping_Gen2[ptr->ChannelID].hw_ch;
    /*call lower level funtion */
    res |= BD18397GetHwCHCtrl(device_id, hw_ch, &(ptr->PwmValue));
    return res;
}

static Std_ReturnType BD18397GetTemperature(S_BuckTemperatureStateDataSrc *ptr)
{
    Std_ReturnType rtval = E_OK;
    uint16 TempBuffer = 0;
    /*Get ADC BUFFER*/
    rtval |= BD18397GetThremalBuffer(ptr->BuckNo, &TempBuffer);
    if (rtval != E_NOT_OK)
    {
        /*caculate temperature*/
        ptr->BuckTemp = (int16_t)((((double)TempBuffer) / 1.472) - 259);
    }
    return rtval;
}

static Std_ReturnType BD18397GetBuckDiagState(S_BuckDiagStateDataSrc *ptr)
{
    uint8 val = 0;
    Std_ReturnType rtval = E_OK;

    rtval |= BD18397GetLostComFlag(ptr->BuckNo, &val);
    if (val)
        ptr->BuckDiagState.LostCom = 1;
    else
        ptr->BuckDiagState.LostCom = 0;

    rtval |= BD18397GetLostConfig(ptr->BuckNo, &val);
    if (val)
        ptr->BuckDiagState.LostConfig = 1;
    else
        ptr->BuckDiagState.LostConfig = 0;

    return rtval;
}

extern uint16 buckvolbuf[6];
extern uint8 buckovervolflag;
static Std_ReturnType BD18397GetChannelVoltage(S_ChannelVoltageDataSrc *ptr)
{
    Std_ReturnType rtval = E_OK;
    uint16 VolBuffer = 0;
    uint8 device_id;
    uint8 hw_ch;
    static uint8 cnt0=0;
    device_id = buch_ch_hwch_mapping_Gen2[ptr->ChannelID].device_id;
    hw_ch = buch_ch_hwch_mapping_Gen2[ptr->ChannelID].hw_ch;
    /*Get ADC BUFFER*/
    rtval |= BD18397GetHwChVoltage(device_id, hw_ch, &VolBuffer);
    if (rtval != E_NOT_OK)
    {
        ptr->ChannelVoltageValue = ((double)(VolBuffer + 1)) * 67.5 / 1024;
        buckvolbuf[device_id*3+hw_ch]=ptr->ChannelVoltageValue;
        if(buckvolbuf[device_id*3+hw_ch]>480)
        {
            cnt0=0;
            buckovervolflag=1;
        }
        else 
        {
            cnt0++;
            if(cnt0>=10) buckovervolflag=0;
        }
    }
    return rtval;
}

static Std_ReturnType BD18397GetChannelErr(S_ChannelDiagStateDataSrc *ptr)
{
    Std_ReturnType rtval = E_OK;
    uint8 device_id;
    uint8 hw_ch;

    device_id = buch_ch_hwch_mapping_Gen2[ptr->ChannelID].device_id;
    hw_ch = buch_ch_hwch_mapping_Gen2[ptr->ChannelID].hw_ch;
    uint8 ErrStBuffer = 0;
    /*Get channel ErrStatus*/
    rtval |= BD18397GetHwChErrStatus(device_id, hw_ch, &ErrStBuffer);
    if (rtval != E_NOT_OK)
    {
        ptr->ChannelDiagState.Bits.OpenError = ((ErrStBuffer == 0x02) ? 1 : 0);
        ptr->ChannelDiagState.Bits.Short2Gnd = ((ErrStBuffer == 0x01) ? 1 : 0);
        ptr->ChannelDiagState.Bits.Pending = 0;
    }
    else
    {
        ptr->ChannelDiagState.Bits.Pending = 1;
    }
    return rtval;
}

static Std_ReturnType BD18397GetChannelOutputFrequency(S_ChannelFrequencyDataSrc *ptr)
{
    Std_ReturnType rtval = E_OK;
    uint8 device_id;
    uint8 hw_ch;

    device_id = buch_ch_hwch_mapping_Gen2[ptr->ChannelID].device_id;
    hw_ch = buch_ch_hwch_mapping_Gen2[ptr->ChannelID].hw_ch;
    uint16 OutputFrequency = 0;
    /*Get channel ErrStatus*/
    rtval |= BD18397GetOutputFrequency(device_id, hw_ch, &OutputFrequency);
    if (rtval != E_NOT_OK)
    {
        ptr->ChannelFrequency = OutputFrequency;
    }
    else
    {
        ptr->ChannelFrequency = 0;
    }
    return rtval;
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*Read interface function*/
Std_ReturnType BD18397ReadFun(void *inputPtr)
{
    Std_ReturnType res = E_OK;
    S_BuckDataPackets *ptr = inputPtr;
    switch (ptr->BuckDataType)
    {
    case E_BuckDataType_BuckInit /* constant-expression */:
        /* code */
        /*BuckInit does not support read init fun*/
        res = E_NOT_OK;
        break;
    case E_BuckDataType_BuckDeInit /* constant-expression */:
        /* code */
        /*BuckInit does not support read init fun*/
        res = E_NOT_OK;
        break;
    case E_BuckDataType_ChannelPWM:
        /* code */
        res |= BD18397GetPWMDutyCycle(ptr->datasrc);
        break;
    case E_BuckDataType_ChannelCurrent:
        /* code */
        res |= BD18397GetChannelCurrent(ptr->datasrc);
        break;
    case E_BuckDataType_ChannelSwitchState:
        /* code */
        res |= BD18397GetSwitchState(ptr->datasrc);
        break;
    case E_BuckDataType_ChannelVoltage:
        /* code */
        res |= BD18397GetChannelVoltage(ptr->datasrc);
        break;
    case E_BuckDataType_ChannelDiagState:
        /* code */
        res |= BD18397GetChannelErr(ptr->datasrc);
        break;
    case E_BuckDataType_BuckTemperature:
        /* code */
        res |= BD18397GetTemperature(ptr->datasrc);
        break;
    case E_BuckDataType_BuckDiagState:
        res |= BD18397GetBuckDiagState(ptr->datasrc);
        break;
    case E_BuckDataType_ChannelFrequency:
        res |= BD18397GetChannelOutputFrequency(ptr->datasrc);
        break;
    default:
        /*funtion go into a non-defined situation. please check file version or your up-level*/
        res = E_NOT_OK;
        break;
    }
}

Std_ReturnType BD18397WriteFun(void *inputPtr)
{
    Std_ReturnType res = E_OK;
    S_BuckDataPackets *ptr = inputPtr;
    switch (ptr->BuckDataType)
    {



    case E_BuckDataType_BuckInit /* constant-expression */:
        /* code */
        res |= BD18397InitFun(ptr);
        break;
    case E_BuckDataType_BuckDeInit /* constant-expression */:
        /* code */
        break;
    case E_BuckDataType_ChannelPWM:
        /* code */
        res |= BD18397SetPWMDutyCycle(ptr->datasrc);
        break;
    case E_BuckDataType_ChannelCurrent:
        /* code */
        res |= BD18397SetChannelCurrent(ptr->datasrc);
        break;
    case E_BuckDataType_ChannelSwitchState:
        /* code */
        res |= BD18397SetSwitchState(ptr->datasrc);
        break;
    case E_BuckDataType_ChannelVoltage:
        /* code */
        /*BUCK does not support write channel vol*/
        res = E_NOT_OK;
        break;

    case E_BuckDataType_ChannelDiagState:
        /* code */
        /*BUCK does not support write DiagState*/
        res = E_NOT_OK;
        break;

    case E_BuckDataType_BuckTemperature:
        /* code */
        /*buck does not support write temperature info*/
        res = E_NOT_OK;
        break;
    case E_BuckDataType_BuckLimpHomeSwitch:
        res |=  BD18397SetLimphomeState(ptr->datasrc);
        break;
    default:
        /*you entry a not defined function. */
        res = E_NOT_OK;
        break;
    }
    return res;
}

Std_ReturnType BD18397InitFun(void *inputPtr)
{
    Std_ReturnType res = E_OK;
    /*call lower level funtion */
    S_BuckDataPackets *ptr = inputPtr;
    S_BuckDeInitDataSrc *datasrc = ptr->datasrc;
    res |= BD18397Init(datasrc->BuckNo);
    return res;
}

Std_ReturnType BD18397DeInitFun(void *inputPtr)
{
    Std_ReturnType res = E_OK;
    /*call lower level funtion */
    S_BuckDataPackets *ptr = inputPtr;
    S_BuckDeInitDataSrc *datasrc = ptr->datasrc;
    (void)ptr;
    (void)datasrc;
    res |= BD18397DeInit(datasrc->BuckNo);
    /*
    @todo: DeinitFun
    */
    return res;
}
extern uint8 losscommunicate;
Std_ReturnType BD18397task(void *inputPtr)
{
    Std_ReturnType res = E_OK;
    /*call lower level funtion */
    S_BuckDataPackets *ptr = inputPtr;
    S_BuckMainFunctionDataSrc *datasrc = ptr->datasrc;
    res |= BD18397MainFun(datasrc->BuckNo);
    if(res == E_NOT_OK)
    {
        losscommunicate=1;
    }
    else losscommunicate=0;
    return res;
}

Std_ReturnType CddDriver_18397Init(void)
{
    Std_ReturnType rtval = E_OK;
    uint8 i = 0;
    for (i = 0; i < BD18398_MAX_DEV_NUM_GEN2; i++)
        rtval |= BuckDrvDev_Register(&BD18398Device_Gen2[i]);
    return rtval;
}
