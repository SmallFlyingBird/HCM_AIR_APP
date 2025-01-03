#include "Ex_Lin.h"
#include "Mcu.h"
#include "Wdg.h"
#include "Os_User.h"

//#define UART3_ADDRESS  ((volatile unsigned char*)(0x40070000U)

/* Variable */
static uint8 Frame_Zcud01_Buffer[7] = {0};
static uint8 Frame_Zcud02_Buffer[7] = {0};
static uint8 Frame_Diagnostic[8] = {0};
static uint8 Frame_Diagnostic_resp[8] = {0};
uint8 *ExLin_ControlBuffPtr = Frame_Zcud01_Buffer;

Frame_ZcudZcud_Lin2Fr01 Frame_Zcud01 = {0};
Frame_ZcudZcud_Lin2Fr02 Frame_Zcud02 = {0};
#if(HCM_DIRECTION_CONFIG == HCM_LEFT_CONFIG)
Frame_HcmlZcud_Lin2Fr01 Frame_Hcml = {0};
#else
Frame_HcmrZcud_Lin2Fr01 Frame_Hcmr = {0};
#endif

/* Function */
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

uint8 UDS_Reset_Flag = FALSE;
const uint8 Appl_extprogrequestreceived[] = {0x6E, 0x67, 0x69, 0x53, 0x67, 0x6F, 0x72, 0x50};

/* get reset request state */
uint8 UDS_ResetReq(void)
{
	uint8 index;
	uint8* Boot_Addr;
	if(UDS_Reset_Flag == TRUE)
	{
    	for(index=0;index<8;index++)
    	{
    		Boot_UninitRam[index] = Appl_extprogrequestreceived[index];
    	}
			
		Mcu_PerformReset();
	}
	
}
/* UDS service 10 02 */
void ExLin_UDS_10(void)
{
	UDS_Reset_Flag = TRUE;
#ifdef LeftAir
	Frame_Diagnostic_resp[0] = 0x2A;
#elif RightAir
	Frame_Diagnostic_resp[0] = 0x2B;
#endif
	Frame_Diagnostic_resp[1] = 0x7;
	Frame_Diagnostic_resp[2] = 0x50;
	Frame_Diagnostic_resp[3] = Frame_Diagnostic[3];
	Frame_Diagnostic_resp[4] = 0x00;
	Frame_Diagnostic_resp[5] = 0x32;
	Frame_Diagnostic_resp[6] = 0x13;
	Frame_Diagnostic_resp[7]=  0x88;
}
/* UDS service 10 02 */
void ExLin_UDS_31(void)
{
#ifdef LeftAir
	Frame_Diagnostic_resp[0] = 0x2A;
#elif RightAir
	Frame_Diagnostic_resp[0] = 0x2B;
#endif
	Frame_Diagnostic_resp[1] = 0x7;
	Frame_Diagnostic_resp[2] = 0x71;
	Frame_Diagnostic_resp[3] = Frame_Diagnostic[3];
	Frame_Diagnostic_resp[4] = Frame_Diagnostic[4];
	Frame_Diagnostic_resp[5] = Frame_Diagnostic[5];
	Frame_Diagnostic_resp[6] = 0xFF;
	Frame_Diagnostic_resp[7]=  0xFF;
}
/* UDS service 10 02 */
void ExLin_UDS_27(void)
{
#ifdef LeftAir
	Frame_Diagnostic_resp[0] = 0x2A;
#elif RightAir
	Frame_Diagnostic_resp[0] = 0x2B;
#endif
	Frame_Diagnostic_resp[1] = 0x7;
	Frame_Diagnostic_resp[2] = 0x67;
	Frame_Diagnostic_resp[3] = Frame_Diagnostic[3];
	Frame_Diagnostic_resp[4] = 0xFF;
	Frame_Diagnostic_resp[5] = 0xFF;
	Frame_Diagnostic_resp[6] = 0xFF;
	Frame_Diagnostic_resp[7]=  0xFF;
}

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
        case 3:
			// 10 02 sevice
			if((Frame_Diagnostic[0] == 0x2A)&&(Frame_Diagnostic[2] == 0x10)) 
			{	
				ExLin_UDS_10(); 
			}
			//31 service
			if((Frame_Diagnostic[0] == 0x2A)&&(Frame_Diagnostic[2] == 0x31)) 
			{	
				ExLin_UDS_31(); 
			}
			//27 Service
			if((Frame_Diagnostic[0] == 0x2A)&&(Frame_Diagnostic[2] == 0x27)) 
			{	
				ExLin_UDS_27(); 
			}
            ExLin_TxBuffer[0] = Frame_Diagnostic_resp[0];
            ExLin_TxBuffer[1] = Frame_Diagnostic_resp[1];
            ExLin_TxBuffer[2] = Frame_Diagnostic_resp[2];
            ExLin_TxBuffer[3] = Frame_Diagnostic_resp[3];
            ExLin_TxBuffer[4] = Frame_Diagnostic_resp[4];
            ExLin_TxBuffer[5] = Frame_Diagnostic_resp[5];
            ExLin_TxBuffer[6] = Frame_Diagnostic_resp[6];
            ExLin_TxBuffer[7] = Frame_Diagnostic_resp[7];
            break;
        default:
            break;
    }
    
}



void ExLin_GetBuffer(uint8* Lin_SduPtr)
{
    ExLin_ControlBuffPtr[0] = Lin_SduPtr[0];
    ExLin_ControlBuffPtr[1] = Lin_SduPtr[1];
    ExLin_ControlBuffPtr[2] = Lin_SduPtr[2];
    ExLin_ControlBuffPtr[3] = Lin_SduPtr[3];
    ExLin_ControlBuffPtr[4] = Lin_SduPtr[4];
    ExLin_ControlBuffPtr[5] = Lin_SduPtr[5];
    ExLin_ControlBuffPtr[6] = Lin_SduPtr[6];

    Frame_Zcud01.Byte0.Byte = Frame_Zcud01_Buffer[0];
    Frame_Zcud01.Byte1.Byte = Frame_Zcud01_Buffer[1];
    Frame_Zcud01.Byte2.Byte = Frame_Zcud01_Buffer[2];
    Frame_Zcud01.ActnOfLedLoBeamChks = Frame_Zcud01_Buffer[3];
    Frame_Zcud01.Byte4.Byte = Frame_Zcud01_Buffer[4];
    Frame_Zcud01.Byte5.Byte = Frame_Zcud01_Buffer[5];
    Frame_Zcud01.ActvnOfIndcrIndcrOutChks = Frame_Zcud01_Buffer[6];

    Frame_Zcud02.LvlgSwtSetReqChks = Frame_Zcud02_Buffer[0];
    Frame_Zcud02.Byte1.Byte = Frame_Zcud02_Buffer[1];
    Frame_Zcud02.Byte2.Byte = Frame_Zcud02_Buffer[2];
    Frame_Zcud02.Reserved1 = Frame_Zcud02_Buffer[3];
    Frame_Zcud02.Reserved2 = Frame_Zcud02_Buffer[4];
    Frame_Zcud02.Reserved3 = Frame_Zcud02_Buffer[5];
    Frame_Zcud02.Reserved4 = Frame_Zcud02_Buffer[6];

}

void ExLin_SetBuffer(uint8 index)
{
    //ExLin_ControlBuffPtr = (index == 1) ? Frame_Zcud01_Buffer : Frame_Zcud02_Buffer;   
    switch(index)
    {
        case 1:
            ExLin_ControlBuffPtr = Frame_Zcud01_Buffer;
            break;
        case 2:
            ExLin_ControlBuffPtr = Frame_Zcud02_Buffer;
            break;
        case 3:
            ExLin_ControlBuffPtr = Frame_Diagnostic;
            break;
        default:
            break;
    } 
}

void ExLin_Diagnostic_MainFunction_5ms(void)
{
    if(Frame_Diagnostic[2] == 0x27 && Frame_Diagnostic[3] == 0x01)
    {
        Frame_Diagnostic_resp[0] = 0x22;
        Frame_Diagnostic_resp[1] = 0x33;
    }
}
