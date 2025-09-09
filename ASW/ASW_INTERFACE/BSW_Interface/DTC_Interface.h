#ifndef ASW_INTERFACE_DID_DTC_INTERFACE_DTC_INTERFACE_H_
#define ASW_INTERFACE_DID_DTC_INTERFACE_DTC_INTERFACE_H_
/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HcmPlatform.h"
//#include "Rte_E2EXf.h"
#include "Rte_E2E_Callout.h"
/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/
typedef enum
{
    E_DtcState_TestPassed = 0,
    E_DtcState_TestFailed = 1,
    E_DtcState_TestNotComplete = 2,
} E_DtcTestState;



typedef enum
{
    E_NtcSsignalNo_NTC1 = 0,
    E_NtcSsignalNo_NTC2 = 1,
    E_NtcSsignalNo_NTC3 = 2,
    E_NtcSsignalNo_NTC4 = 3,
    E_NtcSsignalNo_NTC5 = 4,
} E_NtcSignalNo;

typedef enum
{
    E_BinType_Bin1 = 0,
    E_BinType_Bin2 = 1,
    E_BinType_Bin3 = 2,
} E_BinType;

typedef enum
{
    E_NtcErrorType_OpenOrShort2Vcc = 0,
    E_NtcErrorType_Short2Gnd = 1,
} E_NtcErrorType;

typedef enum
{
    E_StepMotorErrorType_OverLoad = 0,
    E_StepMotorErrorType_OpenLoad,
    E_StepMotorErrorType_OverUse,
    E_StepMotorErrorType_InterError,
    E_StepMotorErrorType_StepLoss,
} E_StepMotorErrorType;

typedef enum
{
    E_HallSensorErrorType_ElectricalFailure = 0,
    E_HallSensorErrorType_ConstantLow,
    E_HallSensorErrorType_ConstantHigh,
} E_HallSensorErrorType;

typedef enum
{
    E_SupplyVoltageErrorType_KL15_SHORT2GND_OPEN = 0,
    E_SupplyVoltageErrorType_KL56_SHORT2GND_OPEN,
    E_SupplyVoltageErrorType_SUPPLYVOTAGE_TOO_HIGH,
    E_SupplyVoltageErrorType_SUPPLYVOTAGE_TOO_LOW,
    E_SupplyVoltageErrorType_BUSSIGNAL_MISMATCH,
} E_SupplyVoltageErrorType;

typedef enum
{
    E_HSDAndFanErrorType_HSD0_OverCur = 0,
    E_HSDAndFanErrorType_HSD0_Shor2Gnd,
    E_HSDAndFanErrorType_HSD0_OpenOrShort2Vcc,
    E_HSDAndFanErrorType_HSD1_OverCur,
    E_HSDAndFanErrorType_HSD1_Shor2Gnd,
    E_HSDAndFanErrorType_HSD1_OpenOrShort2Vcc,
    // E_HSDAndFanErrorType_FAN1_Stall,
    // E_HSDAndFanErrorType_FAN1_CtrLineShort2Gnd,
    // E_HSDAndFanErrorType_FAN1_CtrLineShort2VCC,
    // E_HSDAndFanErrorType_FAN1_SupplyShort2Gnd,
    // E_HSDAndFanErrorType_FAN1_SupplyOpenOrShort2VCC,
    // E_HSDAndFanErrorType_FAN1_HSDOverCur,
} E_HSDAndFanErrorType;

typedef enum
{  
    E_E2EErrorType_ActnOfLedLoBeam_TimeoutError=0, 
    E_E2EErrorType_ActnOfLedLoBeam_CounterError,   
    E_E2EErrorType_ActnOfLedLoBeam_CrcError,       
    E_E2EErrorType_ActvnOfIndcr_TimeoutError,      
    E_E2EErrorType_ActvnOfIndcr_CounterError,      
    E_E2EErrorType_ActvnOfIndcr_CrcError,          
    E_E2EErrorType_LvlgSwtSetReq_TimeoutError,     
    E_E2EErrorType_LvlgSwtSetReq_CounterError,     
    E_E2EErrorType_LvlgSwtSetReq_ChksError,        
} E_E2EErrorType;

typedef enum
{
    E_SystemErrorType_WatchDogTimeout,
    E_SystemErrorType_LeftRightError,
    E_SystemErrorType_LeftRightMismatch,
    E_SystemErrorType_LowBeamFlatDerateError,
    E_SystemErrorType_TIDerateError,
    E_SystemErrorType_DCMotorError,
    E_SystemErrorType_CentralCfgError,
} E_SystemErrorType;

typedef union
{
    uint32 App_channel1_8_error;
    struct
    {
        uint32 CH1_OPEN_CONFIRMED : 1;
        uint32 CH1_SHORT2GND_CONFIRMED : 1;
        uint32 CH1_SHORT2VCC_CONFIRMED : 1;
        uint32 CH1_UNVOLTAGE_CONFIRMED : 1;
        uint32 CH2_OPEN_CONFIRMED : 1;
        uint32 CH2_SHORT2GND_CONFIRMED : 1;
        uint32 CH2_SHORT2VCC_CONFIRMED : 1;
        uint32 CH2_UNVOLTAGE_CONFIRMED : 1;
        uint32 CH3_OPEN_CONFIRMED : 1;
        uint32 CH3_SHORT2GND_CONFIRMED : 1;
        uint32 CH3_SHORT2VCC_CONFIRMED : 1;
        uint32 CH3_UNVOLTAGE_CONFIRMED : 1;
        uint32 CH4_OPEN_CONFIRMED : 1;
        uint32 CH4_SHORT2GND_CONFIRMED : 1;
        uint32 CH4_SHORT2VCC_CONFIRMED : 1;
        uint32 CH4_UNVOLTAGE_CONFIRMED : 1;
        uint32 CH5_OPEN_CONFIRMED : 1;
        uint32 CH5_SHORT2GND_CONFIRMED : 1;
        uint32 CH5_SHORT2VCC_CONFIRMED : 1;
        uint32 CH5_UNVOLTAGE_CONFIRMED : 1;
        uint32 CH6_OPEN_CONFIRMED : 1;
        uint32 CH6_SHORT2GND_CONFIRMED : 1;
        uint32 CH6_SHORT2VCC_CONFIRMED : 1;
        uint32 CH6_UNVOLTAGE_CONFIRMED : 1;
    } bits;
} U_App_Channel1_8_Error;


typedef union
{
    uint8 BinError;
    struct
    {
        uint8_t Bin1ErrorConfirm : 1;
        uint8_t Bin2ErrorConfirm : 1;
        uint8_t Bin3ErrorConfirm : 1;
        // uint8_t MatrixBin1ErrorConfirm : 1;
        // uint8_t MatrixBin2ErrorConfirm : 1;
    } bits;
} U_Bin_Error;

typedef enum
{
    E_ErrorType_ErrorDtcState = 0,
    E_ErrorType_ErrorRealTimeState = 1,
} E_ErrorType;

typedef union
{
    uint16 NtcError;
    struct
    {
        uint16 Ntc1_OpenOrShort2Vcc_ErrorConfirmed : 1;
        uint16 Ntc1_Short2Gnd_ErrorConfirmed : 1;
        uint16 Ntc2_OpenOrShort2Vcc_ErrorConfirmed : 1;
        uint16 Ntc2_Short2Gnd_ErrorConfirmed : 1;
        uint16 Ntc3_OpenOrShort2Vcc_ErrorConfirmed : 1;
        uint16 Ntc3_Short2Gnd_ErrorConfirmed : 1;
        uint16 Ntc4_OpenOrShort2Vcc_ErrorConfirmed : 1;
        uint16 Ntc4_Short2Gnd_ErrorConfirmed : 1;
        uint16 Ntc5_OpenOrShort2Vcc_ErrorConfirmed : 1;
        uint16 Ntc5_Short2Gnd_ErrorConfirmed : 1;
        uint16 Ntc6_OpenOrShort2Vcc_ErrorConfirmed : 1;
        uint16 Ntc6_Short2Gnd_ErrorConfirmed : 1;
        uint16 rcved : 4;
    } bits;
} U_Ntc_Error;

typedef union
{
    uint8 Boost_Buck_Error;
    struct
    {
        uint8_t Buckx_OVER_TEMP_CONFIRMED : 1;
        // uint8_t Boostx_OVER_TEMP_CONFIRMED : 1;
        uint8_t Buckx_InterError : 1;
        // uint8_t Boostx_InterError : 1;
        uint8_t rcvd : 6;
    } bits;
} U_Boost_Buck_Error;

typedef union
{
    uint8 SupplyVoltageError;
    struct
    {
        uint8_t KL15_SHORT2GND_OPEN_ErrorConfirmed : 1;
        uint8_t KL56_SHORT2GND_OPEN_ErrorConfirmed : 1;
        uint8_t SUPPLYVOTAGE_TOO_HIGH : 1;
        uint8_t SUPPLYVOTAGE_TOO_LOW : 1;
        uint8_t EcuSupply_BusSignal_Mismatch : 1;
        uint8_t rcvd : 3;
    } bits;
} U_SupplyVoltage_Error;

typedef union
{
    uint16 HsdAndFanError;
    struct
    {
        uint16 HSD0_OverCur_ErrorConfirmed : 1;
        uint16 HSD0_Shor2Gnd_ErrorConfirmed : 1;
        uint16 HSD0_OpenOrShort2Vcc_ErrorConfirmed : 1;
        uint16 HSD1_OverCur_ErrorConfirmed : 1;
        uint16 HSD1_Shor2Gnd_ErrorConfirmed : 1;
        uint16 HSD1_OpenOrShort2Vcc_ErrorConfirmed : 1;
        uint16 rcvd : 1;
    } bits;
} U_HSDAndFan_Error;

typedef union
{
    uint32 SystemError;
    struct
    {
        uint32 MatrixChip_LossCom : 1;
        uint32 ParameterTable_CrcError : 1;
        uint32 ParameterTable_VersionError : 1;
        uint32 ECU_OverTemperature : 1;
        uint32 ECU_SpiError : 1;
        uint32 Rom_Error : 1;
        uint32 Ram_Error : 1;
        uint32 ChannelCurrentConfigError : 1;
        uint32 WatchDogTimeout : 1;
        uint32 LeftRightError : 1;
        uint32 LeftRightMismatch : 1;
        uint32 LowBeamFlatDerateError : 1;
        uint32 TIDerateError : 1;
        uint32 PublicKeyNotWrited : 1;
        uint32 DcMotorError : 1;
        uint32 CentralCfgError : 1;
        uint32 rcv : 4;
    } bits;
} U_System_Error;

/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
static uint8_t GetDtcErrorVal(const uint8_t DtcIndex);
static uint8_t GetDtcErrorValRealTime(const uint8_t DtcIndex);

void Interface_SetDtcNtcError(E_NtcSignalNo ntcno, E_NtcErrorType ntcerror, uint8_t val);
U_Ntc_Error Interface_GetNtcErrorState(void);

void Interface_SetDtcBinError(E_BinType BinType, uint8_t val);
U_Bin_Error Interface_GetBinErrorState(void);

void Interface_SetDtcSupplyVotageError(E_SupplyVoltageErrorType SupplyVoltageErrorType, uint8_t val);
U_SupplyVoltage_Error Interface_GetSupplyVoltageErrorState(void);

void Interface_SetDtcHSDAndFanError(E_HSDAndFanErrorType HSDAndFanErrorType, uint8_t val);
U_HSDAndFan_Error Interface_GetHSDAndFanErrorState(void);

void Interface_SetDtcHallSensorError(E_HallSensorErrorType HallSensorErrorType, uint8_t val);

void Interface_DisableSuspPosnVertLvlOrSuspPosnVertLvlRe_QF_Detect(void);
void Interface_EnableSuspPosnVertLvlOrSuspPosnVertLvlRe_QF_Detect(void);
uint8_t Interface_GetSuspPosnVertLvlOrSuspPosnVertLvlRe_QF_Detect_Flag(void);

void Interface_SetDtcBuckOverTempError(uint8_t val);

void Interface_SetSystemError(E_SystemErrorType SystemErrorType, uint8_t val);
U_System_Error Interface_GetSystemErrorState(void);

Std_ReturnType DtcInterfaceMainFunction(uint8_t timebase);
void Interface_DtcInit(void);

void Interface_SetDtcE2EError(E_E2EErrorType E2EErrorType, uint8_t val);
S_E2EStateForFailSafe GetE2EFlagForFailSafe(void);
U_E2EErrorFlag Interface_GetDtcE2EError(void);
void Interface_ClearAllDtcError(void);
#endif /* ASW_INTERFACE_DID_DTC_INTERFACE_DTC_INTERFACE_H_ */
