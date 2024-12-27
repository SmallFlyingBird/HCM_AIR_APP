#ifndef EXLIN_HEADER_H
#define EXLIN_HEADER_H
#include "Lin_GeneralTypes.h"
#include "Lin_Types.h"

#define HCM_LEFT_CONFIG (0)
#define HCM_RIGHT_CONFIG (1)
#define HCM_DIRECTION_CONFIG HCM_LEFT_CONFIG


static uint8 ReceiveLinIn5s = 0;
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
    DTC_LDO_Error,
    DTC_Communication_Error,
    DTC_HSD1_Error,//DTC_Highside1_Error,
    DTC_HSD2_Error,//DTC_DCmotor_Error,
    DTC_BUCK_Error,
    DTC_ADC1_Error,
    DTC_ADC2_Error,
    DTC_ADC3_Error,
    DTC_ADC4_Error,
    DTC_ADC5_Error,
    DTC_ADC6_Error,
    DTC_BUCK0CH1_Error,
    DTC_BUCK0CH2_Error,
    DTC_BUCK0CH3_Error,
    DTC_BUCK1CH1_Error,
    DTC_BUCK1CH2_Error,
    DTC_BUCK1CH3_Error,

    /*STATUS*/
    STATUS_BUCK0_Temp,//0x12
    STATUS_BUCK1_Temp,
    STATUS_BUCK0CH1_Voltage,
    STATUS_BUCK0CH2_Voltage,
    STATUS_BUCK1CH1_Voltage,
    STATUS_BUCK1CH2_Voltage,
    STATUS_KL56_Voltage,

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
// void ExLin_SetDTC(ExLin_SignalIndex dtcindex, ExLin_DTCstatus status);
// void ExLin_SetStatus(ExLin_SignalIndex statusindex, uint16 data);
void ExLin_SetFrame(FrameID frameIndex, uint8 *ExLin_TxBuffer);
void ExLin_GetBuffer(uint8 *Lin_SduPtr);
void ExLin_SetBuffer(uint8 index);
void ExLin_Diagnostic_MainFunction_5ms(void);

#if(HCM_DIRECTION_CONFIG == HCM_LEFT_CONFIG)

typedef union
{
    uint8 Byte;
    struct 
    {
        uint8 StsOfLedCornrgLampwithLINLe : 2;
        uint8 StsOfLedDaytiRunngLampWithLINLe : 2;
        uint8 StsOfLedFrntFogLampWithLINLe : 2;
        uint8 StsOfLedFrntPosnLampWithLINLe : 2;
    }Bits;
} Byte0_Frame_HcmlZcud;

typedef union
{
    uint8 Byte;
    struct
    {
        uint8 StsOfLedFrntTurnIndcrWithLINLe : 2;
        uint8 StsOfLedHiBeamWithLINLe : 2;
        uint8 StsOfLedLoBeamWithLINLe : 2;
        uint8 StsOfWelGbyFrntWithLINLe : 1;
        uint8 Reserved : 1;
    }Bits;
}Byte1_Frame_HcmlZcud;

typedef union
{
    uint8 Byte;
    struct
    {
        uint8 Reserved : 7;
        uint8 ErrRespHCML : 1;
    } Bits;
} Byte7_Frame_HcmlZcud;
typedef struct
{
    /* Byte0 */
    Byte0_Frame_HcmlZcud Byte0;

    /* Byte1 */
    Byte1_Frame_HcmlZcud Byte1;

    /* Byte2 */
    uint8 HCML2DTCGroup1;

    /* Byte3 */
    uint8 HCML2DTCGroup2;

    /* Byte4 */
    uint8 HCML2DTCGroup3;

    /* Byte5 */
    uint8 HCML2DTCGroup4;

    /* Byte6 */
    Byte7_Frame_HcmlZcud Byte6;
} Frame_HcmlZcud_Lin2Fr01;
#else
typedef union
{
    uint8 Byte;
    struct 
    {
        uint8 StsOfLedCornrgLampwithLINRi : 2;
        uint8 StsOfLedDaytiRunngLampWithLINRi : 2;
        uint8 StsOfLedFrntFogLampWithLINRi : 2;
        uint8 StsOfLedFrntPosnLampWithLINRi : 2;
    }Bits;
} Byte0_Frame_HcmrZcud;

typedef union
{
    uint8 Byte;
    struct
    {
        uint8 StsOfLedFrntTurnIndcrWithLINRi : 2;
        uint8 StsOfLedHiBeamWithLINRi : 2;
        uint8 StsOfLedLoBeamWithLINRi : 2;
        uint8 StsOfWelGbyFrntWithLINRi : 1;
        uint8 Reserved : 1;
    }Bits;
}Byte1_Frame_HcmrZcud;

typedef union
{
    uint8 Byte;
    struct
    {
        uint8 Reserved : 7;
        uint8 ErrRespHCMR : 1;
    } Bits;
} Byte7_Frame_HcmrZcud;
typedef struct
{
    /* Byte0 */
    Byte0_Frame_HcmrZcud Byte0;

    /* Byte1 */
    Byte1_Frame_HcmrZcud Byte1;

    /* Byte2 */
    uint8 HCMR2DTCGroup1;

    /* Byte3 */
    uint8 HCMR2DTCGroup2;

    /* Byte4 */
    uint8 HCMR2DTCGroup3;

    /* Byte5 */
    uint8 HCMR2DTCGroup4;

    /* Byte6 */
    Byte7_Frame_HcmrZcud Byte6;
} Frame_HcmrZcud_Lin2Fr01;
#endif

/**************************************************/
/**************************************************/
/**************************************************/
typedef union
{
    uint8 Byte;
    struct
    {
        uint8 ActnOfLedCornrgLampLe : 1;
        uint8 ActnOfAssistantLi : 1;
        uint8 ActnOfLedCornrgLampRi : 1;
        uint8 ActnOfLedDaytiRunngLamp : 1;
        uint8 ActnOfLedFrntCrossLamp : 1;
        uint8 ActnOfLedFrntCrossLampDyn : 1;
        uint8 ActnOfLedFrntFogLamp : 1;
        uint8 ActnOfLedGrilleLamp : 1;
    } Bits;
} Byte0_Frame_Zcud01;

typedef union
{
    uint8 Byte;
    struct
    {
        uint8 ActnOfLedGrilleLampDyn : 1;
        uint8 ActnOfLedHiBeam : 1;
        uint8 ActnOfLedLeLogoLamp : 1;
        uint8 ActnOfLedLeLogoLampDyn : 1;
        uint8 ActnOfLedPosnLamp : 1;
        uint8 ActnOfLedPosnLampDyn : 1;
        uint8 ActnOfLedRiLogoLamp : 1;
        uint8 ActnOfLedRiLogoLampDyn : 1;
    } Bits;
} Byte1_Frame_Zcud01;

typedef union
{
    uint8 Byte;
    struct
    {
        uint8 ActvnOfApproach : 1;
        uint8 ActvnOfCarLoctr : 1;
        uint8 ActvnOfGoodByeLi : 1;
        uint8 ActvnOfShowModLi : 1;
        uint8 ActvnOfWaitMode : 1;
        uint8 ActvnOfWelcomeLi : 1;
        uint8 IndcrNoSeq : 1;
        uint8 ActnOfLedLoBeamActnOfLedLoBeam : 1;
    } Bits;
} Byte2_Frame_Zcud01;

typedef union
{
    uint8 Byte;
    struct
    {
        uint8 ActnOfLedLoBeamCntr : 4;
        uint8 WelcomeGoodbyeModeReq : 4;
    } Bits;
} Byte4_Frame_Zcud01;

typedef union
{
    uint8 Byte;
    struct
    {
        uint8 IndcrSts : 2;
        uint8 ActvnOfIndcrIndcrOutCntr : 4;
        uint8 ActvnOfIndcrIndcrOut : 2;
    } Bits;
} Byte5_Frame_Zcud01;
typedef struct
{
    /* Byte0 */
    Byte0_Frame_Zcud01 Byte0;

    /* Byte1 */
    Byte1_Frame_Zcud01 Byte1;


    /* Byte2 */
    Byte2_Frame_Zcud01 Byte2;

    /* Byte3 */
    uint8 ActnOfLedLoBeamChks;

    /* Byte4 */
    Byte4_Frame_Zcud01 Byte4;

    /* Byte5 */
    Byte5_Frame_Zcud01 Byte5;

    /* Byte6 */
    uint8 ActvnOfIndcrIndcrOutChks;
} Frame_ZcudZcud_Lin2Fr01;


/**************************************************/
/**************************************************/
/**************************************************/



typedef union
{
    uint8 Byte;
    struct
    {
        uint8 LvlgSwtSetReqCntr : 4;
        uint8 LvlgSwtSetReqLvlgSwtSetReq : 3;
        uint8 ClrDTCOfLINHCML2 : 1;
    } Bits;
} Byte1_Frame_Zcud02;

typedef union
{
    uint8 Byte;
    struct
    {
        uint8 ClrDTCOfLINHCMR2 : 1;
        uint8 Reserved : 7;
    } Bits;
} Byte2_Frame_Zcud02;
typedef struct
{
    /* Byte0 */
    uint8 LvlgSwtSetReqChks;

    /* Byte1 */
    Byte1_Frame_Zcud02 Byte1;

    /* Byte2 */
    Byte2_Frame_Zcud02 Byte2;

    /* Byte3-7 */
    uint8 Reserved1;
    uint8 Reserved2;
    uint8 Reserved3;
    uint8 Reserved4;
} Frame_ZcudZcud_Lin2Fr02;




#endif