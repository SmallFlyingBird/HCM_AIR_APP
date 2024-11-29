#ifndef EXLIN_HEADER_H
#define EXLIN_HEADER_H
#include "Lin_GeneralTypes.h"
#include "Lin_Types.h"



/* Frame */
typedef enum
{
    ExLin_Frame_HCM_DTC = 0x00u,
    ExLin_Frame_HCM_STATUS = 0x03,
} FrameID;

typedef struct
{
    uint8 ExLinFrameIndex;
    FrameID ExLinFrameId;
} ExLinFrameType;

/* Signal */
typedef enum
{
    /*DTC*/
    DTC_Power_Error = 0x00U,
    DTC_Communication_Error,
    DTC_Highside1_Error,
    DTC_DCmotor_Error,
    DTC_BUCK_Error,
    DTC_ADC1_Error,
    DTC_ADC2_Error,
    DTC_ADC3_Error,
    DTC_ADC4_Error,
    DTC_ADC5_Error,
    DTC_ADC6_Error,
    Response_Error,//0x0C

    /*STATUS*/
    STATUS_BUCK_Temp,//0x0D
    STATUS_BUCK_Voltage
} ExLin_SignalIndex;

typedef struct
{
    ExLin_SignalIndex signalindex;
    uint8 signalLength;
    uint8 signalStartbit;
} ExLin_SignalType;




typedef enum
{
    STATUS_OFF = 0x00,

    /*Power*/
    Over_Voltage = 0x01,   //
    Low_Voltage = 0x02,

    Missing_Commuication = 0x01,

    /*Highside,dc,buck*/
    Over_Current = 0x01,
    Broken_Circuit,
    Short_Circuit,

    /*adc*/
    ADC_Broken_Circuit = 0x01,
    ADC_Short_Circuit
} ExLin_DTCstatus;

void ExLin_Init(void);
void ExLin_SetBit(uint8 *Var, uint8 bitPos, uint8 bitlength, uint16 value);
void ExLin_SetDTC(ExLin_SignalIndex dtcindex, ExLin_DTCstatus status);
void ExLin_SetStatus(ExLin_SignalIndex statusindex, uint16 data);
void ExLin_SetFrame(FrameID frameIndex, uint8 *ExLin_TxBuffer);
void ExLin_GetBuffer(uint8 *Lin_SduPtr);

#endif