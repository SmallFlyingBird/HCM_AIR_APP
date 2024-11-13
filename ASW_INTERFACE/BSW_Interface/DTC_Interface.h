/*
 * DTC_Interface.h
 *
 *  Created on: 2024��1��12��
 *      Author: mihuiliang
 */

#ifndef ASW_INTERFACE_DID_DTC_INTERFACE_DTC_INTERFACE_H_
#define ASW_INTERFACE_DID_DTC_INTERFACE_DTC_INTERFACE_H_

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HcmPlatform.h"
#include "Rte_Cbk.h"
#include "MotorDrvDev_Interface.h"
/****************************************************************
 *                                                              *
 *                      Macro Define                            *
 *                                                              *
 ****************************************************************/
/*�汾�� 0.0.0*/
#define DTC_INTERFACE_VERSION_HIGH_BYTE 0
#define DTC_INTERFACE_VERSION_MIDDLE_BYTE 0
#define DTC_INTERFACE_VERSION_LOW_BYTE 0

#define RSA_PUBLIC_KEY_LENGTH 292u
#define SECM_SECCONST_LENGTH 0x05U

#define FL_PUBLICKEY_SECCONST_NVM_INFO_ADDRESS (0x0101E000U)
#define FL_OPERATE_SUCCEESSD_FLAG 0x50484B4AU

/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/
typedef enum
{
    E_HCMVariantType_Gen1RD_DC_6CH = 1,
    E_HCMVariantType_Gen1RD = 2,
    E_HCMVariantType_Gen1RD_NOMO = 3,
    E_HCMVariantType_Gen1RD_NOMO_DC = 4,
    E_HCMVariantType_Gen1RD_DC_PLUS1 = 5,
    E_HCMVariantType_Gen1RD_PLUS1 = 6,
    E_HCMVariantType_Gen1RD_PLUS2 = 7,
    E_HCMVariantType_Gen1RD_PLUS3 = 8,
    E_HCMVariantType_Gen2RDL = 9,
    E_HCMVariantType_Gen2RDL_NOMO = 10,
    E_HCMVariantType_Gen2RDH = 11,
    E_HCMVariantType_Gen2RDH_NOMO = 12,
    E_HCMVariantType_Gen2RDH_DC = 13,
    E_HCMVariantType_Gen2RD_FULL = 14,
    E_HCMVariantType_Gen2RD_MAX1 = 15,
} E_HCMVariantType;

typedef enum
{
    E_ErrorType_ErrorDtcState = 0,
    E_ErrorType_ErrorRealTimeState = 1,
} E_ErrorType;

typedef enum
{
    E_DtcState_TestPassed = 0,
    E_DtcState_TestFailed = 1,
    E_DtcState_TestNotComplete = 2,
} E_DtcTestState;

typedef enum
{
    E_CAHNNEL_OPEN = 0,
    E_CAHNNEL_SHORT2GND = 1,
    E_CAHNNEL_SHORT2VCC = 2,
    E_CAHNNEL_UNVOL = 3,
} E_ChannelErrorType;

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
    E_BinType_MatrixBin1 = 3,
    E_BinType_MatrixBin2 = 4,
} E_BinType;

typedef enum
{
    E_NtcErrorType_OpenOrShort2Vcc = 0,
    E_NtcErrorType_Short2Gnd = 1,
    E_NtcErrorType_MatrixNtc1Error = 2,
    E_NtcErrorType_MatrixNtc2Error = 3,
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
    E_HSDAndFanErrorType_HSD1_OverCur = 0,
    E_HSDAndFanErrorType_HSD1_Shor2Gnd,
    E_HSDAndFanErrorType_HSD1_OpenOrShort2Vcc,
    E_HSDAndFanErrorType_HSD2_OverCur,
    E_HSDAndFanErrorType_HSD2_Shor2Gnd,
    E_HSDAndFanErrorType_HSD2_OpenOrShort2Vcc,
    E_HSDAndFanErrorType_HSD3_OverCur,
    E_HSDAndFanErrorType_HSD3_Shor2Gnd,
    E_HSDAndFanErrorType_HSD3_OpenOrShort2Vcc,
    E_HSDAndFanErrorType_FAN1_Stall,
    E_HSDAndFanErrorType_FAN1_CtrLineShort2Gnd,
    E_HSDAndFanErrorType_FAN1_CtrLineShort2VCC,
    E_HSDAndFanErrorType_FAN1_SupplyShort2Gnd,
    E_HSDAndFanErrorType_FAN1_SupplyOpenOrShort2VCC,
    E_HSDAndFanErrorType_FAN1_HSDOverCur,
} E_HSDAndFanErrorType;

typedef enum
{
    E_E2EErrorType_LvlgSwtSetReq_ChksError = 0,
    E_E2EErrorType_SuspPosnVertLvl_QFError,
    E_E2EErrorType_SteerWhlSnsr_QFError,
    E_E2EErrorType_VehSpdLgtSafe_CounterError,
    E_E2EErrorType_VehSpdLgtSafe_CrcError,
    E_E2EErrorType_VehModMngtGlbSafe1_CounterError,
    E_E2EErrorType_VehModMngtGlbSafe1_CrcError,
    E_E2EErrorType_IndcrOutSafe_CounterError,
    E_E2EErrorType_IndcrOutSafe_CrcError,
    E_E2EErrorType_ActnOfLedLoBeam_CounterError,
    E_E2EErrorType_ActnOfLedLoBeam_CrcError,
    E_E2EErrorType_BusOff_Error,
} E_E2EErrorType;

typedef enum
{
    E_SystemErrorType_MatrixChip_LossCom = 0,
    E_SystemErrorType_ParameterTable_CrcError,
    E_SystemErrorType_ParameterTable_VersionError,
    E_SystemErrorType_ECU_OverTemperature,
    E_SystemErrorType_ECU_SpiError,
    E_SystemErrorType_Rom_Error,
    E_SystemErrorType_Ram_Error,
    E_SystemErrorType_ChannelCurrentConfigError,
    E_SystemErrorType_WatchDogTimeout,
    E_SystemErrorType_LeftRightError,
    E_SystemErrorType_LeftRightMismatch,
    E_SystemErrorType_LowBeamFlatDerateError,
    E_SystemErrorType_TIDerateError,
    E_SystemErrorType_PinCodeNotWrited,
    E_SystemErrorType_PublicKeyNotWrited,
    E_SystemErrorType_DCMotorError,
    E_SystemErrorType_CentralCfgError,
#if ((VEHICLE_PLATFORM == VEHICLE_SMART_HS11) || (VEHICLE_PLATFORM == VEHICLE_GEELY_G636))
    E_SystemErrorType_Ch2MatrixLossCom,
    E_SystemErrorType_Ch3MatrixLossCom,
    E_SystemErrorType_Ch4MatrixLossCom,
    E_SystemErrorType_Ch5MatrixLossCom,
    E_SystemErrorType_Ch6MatrixLossCom,
    E_SystemErrorType_Ch7MatrixLossCom,
    E_SystemErrorType_Ch8MatrixLossCom,
    E_SystemErrorType_Ch9MatrixLossCom,
    E_SystemErrorType_Ch10MatrixLossCom,
    E_SystemErrorType_Ch11MatrixLossCom,
    E_SystemErrorType_Ch12MatrixLossCom,
#endif
} E_SystemErrorType;

typedef union
{
    uint8_t Error;
    struct
    {
        uint8_t OpenError : 1;
        uint8_t Short2GndError : 1;
        uint8_t Short2VCC : 1;
        uint8_t UnderVoltage : 1;
    } bits;
} U_ChannelErrorState;

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
        uint32 CH7_OPEN_CONFIRMED : 1;
        uint32 CH7_SHORT2GND_CONFIRMED : 1;
        uint32 CH7_SHORT2VCC_CONFIRMED : 1;
        uint32 CH7_UNVOLTAGE_CONFIRMED : 1;
        uint32 CH8_OPEN_CONFIRMED : 1;
        uint32 CH8_SHORT2GND_CONFIRMED : 1;
        uint32 CH8_SHORT2VCC_CONFIRMED : 1;
        uint32 CH8_UNVOLTAGE_CONFIRMED : 1;
    } bits;
} U_App_Channel1_8_Error;

typedef union
{
    uint16 App_channel9_12_error;
    struct
    {
        uint16 CH9_OPEN_CONFIRMED : 1;
        uint16 CH9_SHORT2GND_CONFIRMED : 1;
        uint16 CH9_SHORT2VCC_CONFIRMED : 1;
        uint16 CH9_UNVOLTAGE_CONFIRMED : 1;
        uint16 CH10_OPEN_CONFIRMED : 1;
        uint16 CH10_SHORT2GND_CONFIRMED : 1;
        uint16 CH10_SHORT2VCC_CONFIRMED : 1;
        uint16 CH10_UNVOLTAGE_CONFIRMED : 1;
        uint16 CH11_OPEN_CONFIRMED : 1;
        uint16 CH11_SHORT2GND_CONFIRMED : 1;
        uint16 CH11_SHORT2VCC_CONFIRMED : 1;
        uint16 CH11_UNVOLTAGE_CONFIRMED : 1;
        uint16 CH12_OPEN_CONFIRMED : 1;
        uint16 CH12_SHORT2GND_CONFIRMED : 1;
        uint16 CH12_SHORT2VCC_CONFIRMED : 1;
        uint16 CH12_UNVOLTAGE_CONFIRMED : 1;
    } bits;
} U_App_Channel9_12_Error;

typedef union
{
    uint8 BinError;
    struct
    {
        uint8_t Bin1ErrorConfirm : 1;
        uint8_t Bin2ErrorConfirm : 1;
        uint8_t Bin3ErrorConfirm : 1;
        uint8_t MatrixBin1ErrorConfirm : 1;
        uint8_t MatrixBin2ErrorConfirm : 1;
    } bits;
} U_Bin_Error;

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
        uint16 MatrixNtc1_ErrorConfirmed : 1;
        uint16 MatrixNtc2_ErrorConfirmed : 1;
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
        uint8_t rcvd : 4;
    } bits;
} U_Boost_Buck_Error;

typedef union
{
    uint16 StepMotor_Error;
    struct
    {
        uint16 LevelMotor_OverLoad : 1;
        uint16 LevelMotor_OpenLoad : 1;
        uint16 LevelMotor_OverUse : 1;
        uint16 LevelMotor_InterError : 1;
        uint16 LevelMotor_StepLoss : 1;

        uint16 SwivelMotor_OverLoad : 1;
        uint16 SwivelMotor_OpenLoad : 1;
        uint16 SwivelMotor_OverUse : 1;
        uint16 SwivelMotor_InterError : 1;
        uint16 SwivelMotor_StepLoss : 1;

        uint16 Hall_ElectricalFailure : 1;
        uint16 Hall_FB_ConstantLow : 1;
        uint16 Hall_FB_ConstantHigh : 1;

        uint16 rcvd : 3;
    } bits;
} U_StepMotorAndHall_Error;

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
        uint16 HSD1_OverCur_ErrorConfirmed : 1;
        uint16 HSD1_Shor2Gnd_ErrorConfirmed : 1;
        uint16 HSD1_OpenOrShort2Vcc_ErrorConfirmed : 1;
        uint16 HSD2_OverCur_ErrorConfirmed : 1;
        uint16 HSD2_Shor2Gnd_ErrorConfirmed : 1;
        uint16 HSD2_OpenOrShort2Vcc_ErrorConfirmed : 1;
        uint16 HSD3_OverCur_ErrorConfirmed : 1;
        uint16 HSD3_Shor2Gnd_ErrorConfirmed : 1;
        uint16 HSD3_OpenOrShort2Vcc_ErrorConfirmed : 1;
        uint16 FAN1_Stall_ErrorConfirmed : 1;
        uint16 FAN1_CtrLineShort2Gnd_ErrorConfirmed : 1;
        uint16 FAN1_CtrLineShort2VCC_ErrorConfirmed : 1;
        uint16 FAN1_SupplyShort2Gnd_ErrorConfirmed : 1;
        uint16 FAN1_SupplyOpenOrShort2VCC_ErrorConfirmed : 1;
        uint16 FAN1_HSDOverCur_ErrorConfirmed : 1;
        uint16 rcvd : 1;
    } bits;
} U_HSDAndFan_Error;

typedef union
{
    uint16 E2EError;
    struct
    {
        uint16 LvlgSwtSetReq_ChksError : 1;
        uint16 SuspPosnVertLvl_QFError : 1;
        uint16 SteerWhlSnsr_QFError : 1;
        uint16 VehSpdLgtSafe_CounterError : 1;
        uint16 VehSpdLgtSafe_CrcError : 1;
        uint16 VehModMngtGlbSafe1_CounterError : 1;
        uint16 VehModMngtGlbSafe1_CrcError : 1;
        uint16 IndcrOutSafe_CounterError : 1;
        uint16 IndcrOutSafe_CrcError : 1;
        uint16 ActnOfLedLoBeam_CounterError : 1;
        uint16 ActnOfLedLoBeam_CrcError : 1;
        uint16 rcv : 5;
    } bits;
} U_E2E_Error;

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
        uint32 PinCodeNotWrited : 1;
        uint32 PublicKeyNotWrited : 1;
        uint32 DcMotorError : 1;
        uint32 CentralCfgError : 1;
#if ((VEHICLE_PLATFORM == VEHICLE_SMART_HS11) || (VEHICLE_PLATFORM == VEHICLE_GEELY_G636))
        uint32 Ch2MatrixLossCom : 1;
        uint32 Ch3MatrixLossCom : 1;
        uint32 Ch4MatrixLossCom : 1;
        uint32 Ch5MatrixLossCom : 1;
        uint32 Ch6MatrixLossCom : 1;
        uint32 Ch7MatrixLossCom : 1;
        uint32 Ch8MatrixLossCom : 1;
        uint32 Ch9MatrixLossCom : 1;
        uint32 Ch10MatrixLossCom : 1;
        uint32 Ch11MatrixLossCom : 1;
        uint32 Ch12MatrixLossCom : 1;
        uint32 rcv : 4;
#endif
    } bits;
} U_System_Error;
/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
void Interface_SetDtcChannelError(E_ChannelID index, E_ChannelErrorType errortype, uint8_t val);
U_ChannelErrorState Interface_GetChannelState(E_ChannelID index, E_ErrorType ErrorType);

void Interface_SetDtcNtcError(E_NtcSignalNo ntcno, E_NtcErrorType ntcerror, uint8_t val);
U_Ntc_Error Interface_GetNtcErrorState(E_ErrorType ErrorType);

void Interface_SetDtcBinError(E_BinType BinType, uint8_t val);
U_Bin_Error Interface_GetBinErrorState(E_ErrorType ErrorType);

void Interface_SetDtcSupplyVotageError(E_SupplyVoltageErrorType SupplyVoltageErrorType, uint8_t val);
U_SupplyVoltage_Error Interface_GetSupplyVoltageErrorState(E_ErrorType ErrorType);

void Interface_SetDtcHSDAndFanError(E_HSDAndFanErrorType HSDAndFanErrorType, uint8_t val);
U_HSDAndFan_Error Interface_GetHSDAndFanErrorState(E_ErrorType ErrorType);

// void Interface_SetDtcStepMotorError(E_MotorTpye MotorTpye, E_StepMotorErrorType StepMotorErrorType, uint8_t val);
void Interface_SetDtcHallSensorError(E_HallSensorErrorType HallSensorErrorType, uint8_t val);
U_StepMotorAndHall_Error Interface_GetStepMotorAndHallErrorState(E_ErrorType ErrorType);

void Interface_DisableSuspPosnVertLvlOrSuspPosnVertLvlRe_QF_Detect(void);
void Interface_EnableSuspPosnVertLvlOrSuspPosnVertLvlRe_QF_Detect(void);
uint8_t Interface_GetSuspPosnVertLvlOrSuspPosnVertLvlRe_QF_Detect_Flag(void);

void Interface_DisableSteerWhlSnsr_QF_Detect(void);
void Interface_EnableSteerWhlSnsr_QF_Detect(void);
uint8_t Interface_GetSteerWhlSnsr_QF_Detect_Flag(void);

void Interface_DisableLvlgSwtSetReq_CRC_Detect(void);
void Interface_EnableLvlgSwtSetReq_CRC_Detect(void);
uint8_t Interface_GetLvlgSwtSetReq_CRC_Detect_Flag(void);

void Interface_SetDtcE2EError(E_E2EErrorType E2EErrorType, uint8_t val);
U_E2E_Error Interface_GetE2EErrorState(E_ErrorType ErrorType);
S_E2EStateForFailSafe GetE2EFlagForFailSafe(void);

void Interface_SetDtcBuckOverTempError(uint8_t val);
void Interface_SetDtcBoostOverTempError(uint8_t val);
void Interface_SetDtcBuckInterError(uint8_t val);
void Interface_SetDtcBoostInterError(uint8_t val);
U_Boost_Buck_Error Interface_GetBoostBuckErrorState(E_ErrorType ErrorType);

void Interface_SetSystemError(E_SystemErrorType SystemErrorType, uint8_t val);
U_System_Error Interface_GetSystemErrorState(E_ErrorType ErrorType);

Std_ReturnType DtcInterfaceMainFunction(uint8_t timebase);
Std_ReturnType Interface_DtcInit(void);
#endif /* ASW_INTERFACE_DID_DTC_INTERFACE_DTC_INTERFACE_H_ */
