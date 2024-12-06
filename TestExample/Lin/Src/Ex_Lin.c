#include "Ex_Lin.h"


//#define UART3_ADDRESS  ((volatile unsigned char*)(0x40070000U)
static uint8 ExLin_DTCBuffer[8] = {0};
static uint8 ExLin_StatusBuffer[8] = {0};
static uint8 ExLin_ControlBuffer[8] = {0};
uint8 *ExLin_ControlBuffPtr = ExLin_ControlBuffer;

const ExLin_SignalType TestSignals[25] = 
{
    {
        DTC_Power_Error,        /* signal index */
        2,                      /* singal length */
        0                       /* signal startbit*/
    },
    {
        DTC_LDO_Error,
        1,
        2
    },
    {
        DTC_Communication_Error,
        1,
        8
    },
    {
        DTC_HSD1_Error,
        2,
        16
    },
    {
        DTC_HSD2_Error,
        2,
        18
    },
    {
        DTC_BUCK_Error,
        2,
        32
    },
    {
        DTC_ADC1_Error,
        2,
        40
    },
    {
        DTC_ADC2_Error,
        2,
        42
    },
     {
        DTC_ADC3_Error,
        2,
        44
    },
    {
        DTC_ADC4_Error,
        2,
        46
    },
    {
        DTC_ADC5_Error,
        2,
        48
    },
    {
        DTC_ADC6_Error,
        2,
        50
    },
    {
        DTC_BUCK0CH1_Error,
        1,
        56
    },
    {
        DTC_BUCK0CH2_Error,
        1,
        57
    },
    {
        DTC_BUCK0CH3_Error,
        1,
        58
    },
        {

        DTC_BUCK1CH1_Error,

        1,
        59
    },
    {
        DTC_BUCK1CH2_Error,
        1,
        60
    },
    {
        DTC_BUCK1CH3_Error,
        1,
        61
    },
    {
        STATUS_BUCK0_Temp,
        8,
        0
    },
    {
        STATUS_BUCK1_Temp,
        8,
        8
    },
    {
        STATUS_BUCK0CH1_Voltage,
        8,
        16
    },
    {
        STATUS_BUCK0CH2_Voltage,
        8,
        24
    },
    {
        STATUS_BUCK1CH1_Voltage,
        8,
        32
    },
    {
        STATUS_BUCK1CH2_Voltage,
        8,
        40
    },
    {
        STATUS_KL56_Voltage,
        8,
        48
    },
};

void ExLin_SetBit(uint8* Var,uint8 bitPos,uint8 bitlength,uint16 value)
{
    uint8 StartByte = bitPos / 8;
    uint8 StartBit = bitPos % 8;

    value &= ((1ULL << bitlength) - 1);

    if((bitPos + bitlength) > 64)
        return;

    for (uint8 i = 0; i < bitlength; i++)
    {
        uint8 ByteIndex = StartByte + i / 8;
        uint8 bitOffset = (StartBit + i) % 8;
        uint8 bitMask = 1 << bitOffset;

        if(value & (1ULL << i ))
        {
            Var[ByteIndex] |= bitMask;
        }
        else
        {
            Var[ByteIndex] &= ~bitMask;
        }
    }
}



void ExLin_SetDTC(ExLin_SignalIndex dtcindex,ExLin_DTCstatus status)
{
    const ExLin_SignalType *dtcptr = TestSignals;
    uint8 bitPOS = (dtcptr + dtcindex)->signalStartbit;
    uint8 bitlength = (dtcptr + dtcindex)->signalLength;

    ExLin_SetBit(ExLin_DTCBuffer,bitPOS,bitlength,status);
}


void ExLin_SetStatus(ExLin_SignalIndex statusindex,uint16 data)
{
    const ExLin_SignalType *dtcptr = TestSignals;
    uint8 bitPOS = ((dtcptr + statusindex)->signalStartbit);
    uint8 bitlength = (dtcptr + statusindex)->signalLength;
    
    ExLin_SetBit(ExLin_StatusBuffer,bitPOS,bitlength,data);
}

void ExLin_SetFrame(FrameID frameIndex,uint8* ExLin_TxBuffer)
{
    if(ExLin_Frame_HCM_DTC == frameIndex)
    {
        for (uint8 i = 0; i < 8; i++)
        {
            ExLin_TxBuffer[i] = ExLin_DTCBuffer[i];
        }
        //ExLin_TxBuffer[] = ExLin_DTCBuffer;
    }
    else
    {
        for (uint8 i = 0; i < 8; i++)
        {
            ExLin_TxBuffer[i] = ExLin_StatusBuffer[i];
        }
        //ExLin_TxBuffer = ExLin_StatusBuffer;
    }
    
}

void ExLin_GetBuffer(uint8* Lin_SduPtr)
{
    for (uint8 i = 0; i < 8; i++)
    {
        ExLin_ControlBuffer[i] = *(Lin_SduPtr++);
    }
}