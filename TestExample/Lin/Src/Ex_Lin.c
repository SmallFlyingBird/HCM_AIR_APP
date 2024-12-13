#include "Ex_Lin.h"


//#define UART3_ADDRESS  ((volatile unsigned char*)(0x40070000U)

static uint8 ExLin_ControlBuffer1[7] = {0};
static uint8 ExLin_ControlBuffer2[7] = {0};
uint8 *ExLin_ControlBuffPtr = ExLin_ControlBuffer1;
#if(HCM_DIRECTION_CONFIG == HCM_LEFT_CONFIG)
Frame_HcmlZcud_Lin2Fr01 Frame_Hcml = {0};
#else
Frame_HcmrZcud_Lin2Fr01 Frame_Hcmr = {0};
#endif


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



// void ExLin_SetDTC(ExLin_SignalIndex dtcindex,ExLin_DTCstatus status)
// {
//     const ExLin_SignalType *dtcptr = TestSignals;
//     uint8 bitPOS = (dtcptr + dtcindex)->signalStartbit;
//     uint8 bitlength = (dtcptr + dtcindex)->signalLength;

//     ExLin_SetBit(ExLin_DTCBuffer,bitPOS,bitlength,status);
// }


// void ExLin_SetStatus(ExLin_SignalIndex statusindex,uint16 data)
// {
//     const ExLin_SignalType *dtcptr = TestSignals;
//     uint8 bitPOS = ((dtcptr + statusindex)->signalStartbit);
//     uint8 bitlength = (dtcptr + statusindex)->signalLength;
    
//     ExLin_SetBit(ExLin_StatusBuffer,bitPOS,bitlength,data);
// }

void ExLin_SetFrame(FrameID frameIndex,uint8* ExLin_TxBuffer)
{
    switch(frameIndex)
    {
        case 0:
            break;
        case 1:
            // Frame_Hcml.Byte0.Bits.StsOfLedCornrgLampwithLINLe = 1;
            ExLin_TxBuffer[0] = Frame_Hcml.Byte0.Byte;
            ExLin_TxBuffer[1] = Frame_Hcml.Byte1.Byte;
            ExLin_TxBuffer[2] = Frame_Hcml.HCML2DTCGroup1;
            ExLin_TxBuffer[3] = Frame_Hcml.HCML2DTCGroup2;
            ExLin_TxBuffer[4] = Frame_Hcml.HCML2DTCGroup3;
            ExLin_TxBuffer[5] = Frame_Hcml.HCML2DTCGroup4;
            ExLin_TxBuffer[6] = Frame_Hcml.Byte6.Byte;
            break;
        case 2:
            ExLin_TxBuffer[0] = Frame_Hcml.Byte0.Byte;
            ExLin_TxBuffer[1] = Frame_Hcml.Byte1.Byte;
            ExLin_TxBuffer[2] = Frame_Hcml.HCML2DTCGroup1;
            ExLin_TxBuffer[3] = Frame_Hcml.HCML2DTCGroup2;
            ExLin_TxBuffer[4] = Frame_Hcml.HCML2DTCGroup3;
            ExLin_TxBuffer[5] = Frame_Hcml.HCML2DTCGroup4;
            ExLin_TxBuffer[6] = Frame_Hcml.Byte6.Byte;
            break;
   
        default:
    }
    
}



void ExLin_GetBuffer(uint8* Lin_SduPtr)
{
    while((*ExLin_ControlBuffPtr++ = *Lin_SduPtr++) != '\0')
    {}

}

void ExLin_SetBuffer(uint8 index)
{
    ExLin_ControlBuffPtr = (index == 1) ? ExLin_ControlBuffer1 : ExLin_ControlBuffer2;    
}