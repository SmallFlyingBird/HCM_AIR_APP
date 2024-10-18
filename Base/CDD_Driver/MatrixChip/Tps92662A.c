/*
 * TLD7002.c
 *
 *  Created on: 2024��1��10��
 *      Author: mihuiliang
 */

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "Tps92662A.h"
#include "Parameter_Interface.h"
#include "Uart.h"
#include "Dio_Cfg.h"
#include "Dio.h"
#include "Port_Types.h"
#include "Port.h"

extern uint8 uart0_done;
extern uint8 uart1_done;

/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
static S_MatrixChipDrv_Dev g_Tps92662ADev[MAX_MATRIXCHIP_NUM];
static uint8_t Tps92662ADevNum = 0;
static uint8_t ComtimeOutFlag = 0;
static uint8_t ComErrorFlag = 0;
/****************************************************************
 *                                                              *
 *                   Global Variable Define                     *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/
static uint8_t GetWriteINITByte(uint8_t dataLen)
{
    uint8_t result = 0;
    switch (dataLen)
    {
    case 1:
        result = 0x87;
        break;
    case 2:
        result = 0x99;
        break;
    case 3:
        result = 0x1E;
        break;
    case 4:
        result = 0xAA;
        break;
    case 12:
        result = 0x2D;
        break;
    case 16:
        result = 0x33;
        break;
    case 32:
        result = 0xB4;
        break;
    default:
        result = 0x00;
        break;
    }
    return result;
}
static void InvertUint16(unsigned short *dBuf, unsigned short *srcBuf)
{
    int i;
    unsigned short tmp[4] = {0};

    for (i = 0; i < 16; i++)
    {
        if (srcBuf[0] & (1 << i))
            tmp[0] |= 1 << (15 - i);
    }
    dBuf[0] = tmp[0];
}

static unsigned short CRC16_IBM(unsigned char *data, unsigned int datalen)
{
    unsigned short wCRC1in = 0x0000;
    unsigned short wCPoly = 0x8005;
    int i = 0;
    InvertUint16(&wCPoly, &wCPoly);
    while (datalen--)
    {
        wCRC1in ^= *(data++);
        for (i = 0; i < 8; i++)
        {
            if (wCRC1in & 0x01)
                wCRC1in = (wCRC1in >> 1) ^ wCPoly;
            else
                wCRC1in = wCRC1in >> 1;
        }
    }
    return (wCRC1in);
}
static uint8_t GetReadINITByte(uint8_t dataLen)
{
    uint8_t result = 0;
    switch (dataLen)
    {
    case 1:
        result = 0x4B;
        break;
    case 2:
        result = 0xCC;
        break;
    case 3:
        result = 0xD2;
        break;
    case 4:
        result = 0x55;
        break;
    case 12:
        result = 0xE1;
        break;
    case 16:
        result = 0x66;
        break;
    case 32:
        result = 0x78;
        break;
    default:
        result = 0x00;
        break;
    }
    return result;
}
/*
        function descrpition:	basic read data function.
        @LEDChip:				a pointer head to TPS92662A structure. it can caculate DEVID and reflash the ADDR automaticly
        @driverReg: 			LED Driver register address, maping in 'LEDDriver_register_t'
        @readData:				a pointer pin to Data which will be received.
        @dataLen:				the length of data. it only can be enum1,2,3,4,12,16 or32)
    */

Std_ReturnType LEDDriver_ReadCmd(
    LEDDriver_Type_t *LEDChip,
    LEDDriver_register_t driverReg,
    uint8_t *readData,
    uint8_t dataLen)
{
    Std_ReturnType sendStatus = E_OK;
    static Dma_ChannelStatusType DmaStatus;
    uint8 count = 0;
    __attribute__((aligned(32))) static uint8_t command[5] = {100};
    __attribute__((aligned(32))) static uint8_t rxdata[40] = {100};

    for (count = 0; count < 5; count++)
    {
        command[count] = 0;
    }
    for (count = 0; count < 40; count++)
    {
        rxdata[count] = 0;
    }
    uint16_t CRC = 0x0;
    uint16 receiveCRC = 0x00;
    /*caculate DEVID*/
    LEDDriverAddr_t chipAddr;
    chipAddr = LEDChip->addr;
    /*if bit5 is NOT EQUALs 1, means DEVID is not caculate. when caculating done, return new DEVID to *LEDChiip*/
    if (LEDChip->addr.bit.bit5 != 1)
    {
        chipAddr.bit.bit7 = ~(chipAddr.bit.bit1 ^ chipAddr.bit.bit3 ^ chipAddr.bit.bit4 ^ 1);
        chipAddr.bit.bit6 = chipAddr.bit.bit0 ^ chipAddr.bit.bit1 ^ chipAddr.bit.bit2 ^ chipAddr.bit.bit4;
        chipAddr.bit.bit5 = 1;
        LEDChip->addr = chipAddr;
    }
    command[0] = GetReadINITByte(dataLen);
    command[1] = chipAddr.addr;
    command[2] = driverReg;
    if (dataLen != 1 && dataLen != 2 && dataLen != 3 && dataLen != 4 && dataLen != 12 && dataLen != 16 && dataLen != 32)
    {
        return E_NOT_OK;
    }
    CRC = CRC16_IBM(command, 3);
    command[3] = (uint8_t)(CRC & 0xFF);
    command[4] = (uint8_t)((CRC >> 8) & 0xFF);

    uint32 T_bytesRemaining;
    uint32 T_timeout = 0x2000;
    /*Uart_StatusType Uart_TransmitStatus = UART_STATUS_TIMEOUT;*/
    /*Uart_StatusType Uart_ReceiveStatus = UART_STATUS_TIMEOUT;*/

    GetResource(OsResource_UartMatrixChip);
    sendStatus |= Uart_AsyncReceive(0, rxdata, dataLen + 7);
    sendStatus |= Uart_AsyncSend(0, command, 5);

    /*T_timeout = 0x1FFF;*/
    ComtimeOutFlag = 0;
    ComErrorFlag = 0;
    uart0_done = 0;
    do
    {
        /*  Uart_GetStatus(0, 1, &DmaStatus);  */
        T_timeout--;

        /*when timeout is not end, and DmaStatus is not Done, go for this. Or when Timeout, Or Done, any of this is happening, while is end*/
    } while ((0 != T_timeout) && (uart0_done != 1));
    uart0_done = 0;
    if (T_timeout == 0)
    {
        Uart_Abort(0, 1);
        ComtimeOutFlag = 1;
        sendStatus = E_NOT_OK;
    }

    if (sendStatus == E_OK)
    {
        receiveCRC = CRC16_IBM(rxdata + 5, dataLen);
        if (rxdata[dataLen + 5] != (receiveCRC & 0xFF) || (rxdata[dataLen + 6] != ((receiveCRC >> 8) & 0xFF)))
        {
            ComErrorFlag = 1;
            sendStatus = E_NOT_OK;
        }
        for (count = 0; count < dataLen; count++)
        {
            readData[count] = rxdata[count + 5];
        }
    }

    ReleaseResource(OsResource_UartMatrixChip);
    return sendStatus;
}

/*
    function descrpition:   basic read data function.
    @LEDChip:				a pointer head to TPS92662A structure. it can caculate DEVID and reflash the ADDR automaticly
    @driverReg:				LED Driver register address, maping in 'LEDDriver_register_t'
    @sendData:		   		a pointer pin to Data which would transfer to TPS92662A.
    @dataLen:				the length of data. it only can be enum1,2,3,4,12,16 or32)
*/

static Std_ReturnType LEDDriver_WriteCmd(
    LEDDriver_Type_t *LEDChip,
    LEDDriver_register_t driverReg,
    uint8_t *sendData,
    uint8_t dataLen)
{
    static Dma_ChannelStatusType DmaStatus;
    static Std_ReturnType sendStatus = E_OK;
    uint8 count = 0;
    __attribute__((aligned(32))) static uint8_t command[40] = {100};
    __attribute__((aligned(32))) static uint8_t rcv_data[40] = {100};
    static uint32 T_bytesRemaining = 0;
    uint32 T_timeout = 0x2FFF;

    for (count = 0; count < 40; count++)
    {
        command[count] = 0;
    }

    uint16_t CRC = 0x0;
    uint8_t countCycle;
    /*caculate DEVID*/
    LEDDriverAddr_t chipAddr;
    chipAddr = LEDChip->addr;
    /*if bit5 is NOT EQUALs 1, means DEVID is not caculate. when caculating done, return new DEVID to *LEDChiip*/
    if (LEDChip->addr.bit.bit5 != 1)
    {
        chipAddr.bit.bit7 = ~(chipAddr.bit.bit1 ^ chipAddr.bit.bit3 ^ chipAddr.bit.bit4 ^ 1);
        chipAddr.bit.bit6 = chipAddr.bit.bit0 ^ chipAddr.bit.bit1 ^ chipAddr.bit.bit2 ^ chipAddr.bit.bit4;
        chipAddr.bit.bit5 = 1;
        LEDChip->addr = chipAddr;
    }
    command[0] = GetWriteINITByte(dataLen);
    command[1] = chipAddr.addr;
    command[2] = driverReg;
    if (dataLen != 1 && dataLen != 2 && dataLen != 3 && dataLen != 4 && dataLen != 12 && dataLen != 16 && dataLen != 32)
    {
        return E_NOT_OK;
    }
    for (countCycle = 0; countCycle < dataLen; countCycle++)
    {
        command[countCycle + 3] = sendData[countCycle];
    }
    CRC = CRC16_IBM(command, dataLen + 3);
    command[dataLen + 3] = (uint8_t)(CRC & 0xFF);        /*CRCL*/
    command[dataLen + 4] = (uint8_t)((CRC >> 8) & 0xFF); /*CRCH*/

    GetResource(OsResource_UartMatrixChip);
    /*Sending data*/
    Uart_AsyncReceive(0, rcv_data, dataLen + 5);
    sendStatus = Uart_AsyncSend(0, command, (dataLen + 5));
    uart0_done = 0;
    do
    {
        /*  Uart_GetStatus(0, 1, &DmaStatus); */
        T_timeout--;
        /*when timeout is not end, and DmaStatus is not Done, go for this. Or when Timeout, Or Done, any of this is happening, while is end*/
    } while ((0 != T_timeout) && (uart0_done != 1));
    uart0_done = 0;
    if (T_timeout == 0)
    {
        sendStatus = E_NOT_OK;
    }
    ReleaseResource(OsResource_UartMatrixChip);
    return sendStatus;
}

static Std_ReturnType Tps92662A_SetChannelPwm(uint8 addr, S_ChannelPWMDataSrc *datasrc)
{
    Std_ReturnType rtval = E_OK;

    LEDDriver_Type_t sMLC;
    sMLC.addr.addr = addr;
    uint8 round;
    uint8 ch;
    uint8 data[16] = {
        0x00,
    };
    uint16 RW_data[12] = {
        0x00,
    };
    for (ch = 0; ch < 12; ch++)
    {
        if (datasrc->PwmValue[ch] >= 100)
        {
            RW_data[ch] = 1023;
        }
        else
            RW_data[ch] = ((uint16)(datasrc->PwmValue[ch])) * 1.023 * 10;
    }
    for (round = 0; round < 4; round++)
    {
        for (ch = 0; ch < 3; ch++)
        {
            data[ch + 4 * round] = (uint8)(RW_data[ch + 3 * round] & 0xFF);
            data[3 + 4 * round] |= (uint8)((((RW_data[ch + 3 * round]) >> 8) & 0x03) << 2 * ch);
        }
    }
    rtval |= LEDDriver_WriteCmd(&sMLC, LEDDriver_MWIDTH01L, data, 16);

    return rtval;
}
Std_ReturnType TPS92662_SetADCID(uint8 ADCID)
{
    Std_ReturnType ucStatus = E_OK;
    LEDDriver_Type_t psMlc;
    uint8 data = ADCID;
    psMlc.addr.addr = 0x1F;
    ucStatus = LEDDriver_WriteCmd(&psMlc, LEDDriver_ADCID, &data, 1);
    return ucStatus;
}
Std_ReturnType TPS92662_SetMlcSlewRate(uint8 addr,
                                       uint8 SlewRate)
{
    Std_ReturnType ucStatus;
    LEDDriver_Type_t sMLC;
    sMLC.addr.addr = addr;
    uint8 data[1] = {SlewRate};
    ucStatus = LEDDriver_WriteCmd(&sMLC, LEDDriver_SLEWRATE, data, 1);
    return ucStatus;
}
Std_ReturnType TPS92662_SetMlcOVLMT(uint8 addr, uint8 ovlmt)
{
    Std_ReturnType ucStatus;
    LEDDriver_Type_t sMLC;
    sMLC.addr.addr = addr;
    uint8 data[1] = {ovlmt};
    ucStatus = LEDDriver_WriteCmd(&sMLC, LEDDriver_OVLMT, data, 1);
    return ucStatus;
}
Std_ReturnType TPS92662_SetMlcDefaultWidth(uint8 addr, uint16 *defWidth)
{
    Std_ReturnType ucStatus;
    LEDDriver_Type_t sMLC;
    sMLC.addr.addr = addr;
    uint8 count;
    uint8 data[6] = {
        0x00,
    };
    for (count = 0; count < 6; count++)
    {
        data[count] = ((uint8)(defWidth[2 * count] * 0.015)) | (((uint8)(defWidth[2 * count + 1] * 0.015)) << 4);
    }
    ucStatus = LEDDriver_WriteCmd(&sMLC, LEDDriver_DEFWIDTH02_01, data, 4);
    ucStatus = LEDDriver_WriteCmd(&sMLC, LEDDriver_DEFWIDTH10_09, data + 4, 2);
    return ucStatus;
}
Std_ReturnType TPS92662_SetMlcWdgTapPiont(uint8 addr, uint8 cmwtap)
{
    Std_ReturnType ucStatus;
    LEDDriver_Type_t sMLC;
    sMLC.addr.addr = addr;
    uint8 data[1] = {cmwtap};
    ucStatus = LEDDriver_WriteCmd(&sMLC, LEDDriver_CMWTAP, data, 1);
    return ucStatus;
}
Std_ReturnType TPS92662_SetMlcWdgEn(uint8 addr, uint8 isEnable)
{
    Std_ReturnType ucStatus;
    LEDDriver_Type_t sMLC;
    sMLC.addr.addr = addr;
    uint8 data[1] = {0x00};
    data[0] = isEnable << 3;
    ucStatus = LEDDriver_WriteCmd(&sMLC, LEDDriver_SYSCFG, data, 1);
    return ucStatus;
}

Std_ReturnType TPS92662_PMWTickPeriodChange(uint8 addr, uint8 tick)
{
    Std_ReturnType ucStatus;
    LEDDriver_Type_t sMLC;
    sMLC.addr.addr = addr;
    uint8_t data[1] = {tick};
    ucStatus = LEDDriver_WriteCmd(&sMLC, LEDDriver_PWMTICK, data, 1);
    return ucStatus;
}
Std_ReturnType TPS92662_SetChannelPhase(uint8 addr, uint8 channel, uint16 phase)
{
    Std_ReturnType ucStatus = E_OK;
    LEDDriver_Type_t psMlc;
    psMlc.addr.addr = addr;
    uint8 data[2] = {0x0, 0x0};
    /*phase=(uint16)phase*1.023;*/
    if (phase > 1023)
    {
        phase = 1023;
    }
    data[0] = phase & 0xff;
    data[1] = (phase >> 8) & 0x03;

    ucStatus = LEDDriver_WriteCmd(&psMlc, (LEDDriver_DPHASE01L + 4 * channel), data, 2);

    return ucStatus;
}
Std_ReturnType TPS92662_SetMlcAllChannelPhase(uint8 addr, uint16 *Phase)
{
    Std_ReturnType ucStatus;
    LEDDriver_Type_t sMLC;
    sMLC.addr.addr = addr;
    uint8 round;
    uint8 ch;
    uint8 data[16] = {
        0x00,
    };
    uint16 RW_data[12];
    for (ch = 0; ch < 12; ch++)
    {
        /*RW[ch]=(uint16)Phase[ch]*1.023;*/
        RW_data[ch] = (uint16)Phase[ch];
    }
    for (round = 0; round < 4; round++)
    {
        for (ch = 0; ch < 3; ch++)
        {
            data[ch + 4 * round] = (uint8)(RW_data[ch + 3 * round] & 0xFF);
            data[3 + 4 * round] |= (uint8)((((RW_data[ch + 3 * round]) >> 8) & 0x03) << 2 * ch);
        }
    }
    ucStatus = LEDDriver_WriteCmd(&sMLC, LEDDriver_MPHASE01L, data, 16);
    return ucStatus;
}

Std_ReturnType TPS92662_GetMlcAllChannelPhase(uint8 addr, uint16 *phase)
{
    uint8 ch, count;
    Std_ReturnType ucStatus;
    LEDDriver_Type_t sMLC;
    sMLC.addr.addr = addr;
    uint16 RW_data[12] = {
        0x00,
    };
    uint8 data[16] = {
        0x00,
    };
    ucStatus = LEDDriver_ReadCmd(&sMLC, LEDDriver_MPHASE01L, data, 16);
    for (count = 0; count < 4; count++)
    {
        for (ch = 0; ch < 3; ch++)
        {
            RW_data[ch + 3 * count] = (uint16)((uint16)data[ch + 4 * count] + ((uint16)((data[3 + 4 * count] >> 2 * ch) & 0x3) << 8));
        }
    }
    for (ch = 0; ch < 12; ch++)
    {
        phase[ch] = (uint16)RW_data[ch];
    }
    return ucStatus;
}
Std_ReturnType TPS92662_GetMlcAllChannelWidth(uint8 addr, uint16 *width)
{
    uint8 ch, count;
    Std_ReturnType ucStatus;
    LEDDriver_Type_t sMLC;
    sMLC.addr.addr = addr;
    uint16 RW_data[12] = {
        0x00,
    };
    uint8 data[16] = {
        0x00,
    };
    ucStatus = LEDDriver_ReadCmd(&sMLC, LEDDriver_MWIDTH01L, data, 16);
    for (count = 0; count < 4; count++)
    {
        for (ch = 0; ch < 3; ch++)
        {
            RW_data[ch + 3 * count] = (uint16)((uint16)data[ch + 4 * count] + ((uint16)((data[3 + 4 * count] >> 2 * ch) & 0x3) << 8));
        }
    }
    for (ch = 0; ch < 12; ch++)
    {
        width[ch] = (uint16)RW_data[ch] * 0.9775;
    }
    return ucStatus;
}

Std_ReturnType TPS92662_GetMlcADC(uint8 addr, uint8 ADC, uint8 *value)
{
    Std_ReturnType ucStatus = E_OK;
    LEDDriver_Type_t psMlc;
    psMlc.addr.addr = addr;
    if (ADC == 1)
    {
        ucStatus = LEDDriver_ReadCmd(&psMlc, LEDDriver_ADC1, value, 1);
    }
    else if (ADC == 2)
    {
        ucStatus = LEDDriver_ReadCmd(&psMlc, LEDDriver_ADC2, value, 1);
    }
    else
    {
        ucStatus = E_NOT_OK;
        value[0] = 0;
    }
    return ucStatus;
}

Std_ReturnType TPS92662_GetSYSCFG(uint8 addr, uint8 *SYSCFG)
{
    uint8 ch, count;
    Std_ReturnType ucStatus;
    LEDDriver_Type_t sMLC;
    sMLC.addr.addr = addr;
    uint8 data[1] = {
        0x00,
    };

    ucStatus = LEDDriver_ReadCmd(&sMLC, LEDDriver_SYSCFG, data, 1);
    if (ucStatus == E_OK)
        *SYSCFG = data[0];
    return ucStatus;
}

static Std_ReturnType Tps92662ADeviceInit(void *ptr)
{
#if 0
	Std_ReturnType ucStatus=E_OK;
	LEDDriver_Type_t sMLC;
	S_Tps92662ADataPackets *DataPackets;
	uint8 addr;

	DataPackets=(S_Tps92662ADataPackets *)ptr;

	sMLC.addr.addr=DataPackets->dev_address;
	addr=DataPackets->dev_address;
	sMLC.mode = 0;
	uint8_t  data[1]={0x00};
/*BordCast write*/
	LEDDriverAddr_t bordcastAddr;
	bordcastAddr.addr=0x1F;
	LEDDriver_Type_t BORDCAST={0,bordcastAddr};
	data[0]=0;
	LEDDriver_WriteCmd(&BORDCAST,LEDDriver_ADCID,data,1);
	LEDDriver_WriteCmd(&sMLC,LEDDriver_ADCID,data,1);
	data[0]=0x00;
	LEDDriver_WriteCmd(&sMLC,LEDDriver_SYSCFG,data,1);
	data[0]=0xAA;
	LEDDriver_WriteCmd(&sMLC,LEDDriver_OVLMT,data,1);

	TPS92662_SetChannelPhase(addr, CHANNEL1_MLC, 85 );
	TPS92662_SetChannelPhase(addr, CHANNEL2_MLC, 170 );
	TPS92662_SetChannelPhase(addr, CHANNEL3_MLC, 255 );
	TPS92662_SetChannelPhase(addr, CHANNEL4_MLC, 340);

	TPS92662_SetChannelPhase(addr, CHANNEL5_MLC, 425 );
	TPS92662_SetChannelPhase(addr, CHANNEL6_MLC, 510 );
	TPS92662_SetChannelPhase(addr, CHANNEL7_MLC, 595 );
	TPS92662_SetChannelPhase(addr, CHANNEL8_MLC, 680);

	TPS92662_SetChannelPhase(addr, CHANNEL9_MLC, 765 );
	TPS92662_SetChannelPhase(addr, CHANNEL10_MLC, 850 );
	TPS92662_SetChannelPhase(addr, CHANNEL11_MLC, 935 );
	TPS92662_SetChannelPhase(addr, CHANNEL12_MLC, 1020);
	data[0]=0x00;
	LEDDriver_WriteCmd(&sMLC,LEDDriver_SLEWRATE,data,1);
	sMLC.mode=1;
	return ucStatus;
#else
    Std_ReturnType rtval = E_OK;
    S_MatrixTripDataPackets *DataPackets;
    S_Tps92662A_InitDataSrc *InitDataSrc;
    DataPackets = (S_MatrixTripDataPackets *)ptr;
    uint16_t data[TPS92662A_MAX_CHANNEL_NUM];
    uint8_t i = 0;

    if (DataPackets->DataType != E_MatrixTripDataType_DevInit)
        return E_NOT_OK;

    InitDataSrc = (S_Tps92662A_InitDataSrc *)(DataPackets->datasrc);

    rtval |= TPS92662_SetADCID(InitDataSrc->AdcID);
    rtval |= TPS92662_PMWTickPeriodChange(DataPackets->dev_address, InitDataSrc->PwmTick);
    rtval |= TPS92662_SetMlcWdgTapPiont(DataPackets->dev_address, InitDataSrc->CMWTAP);
    rtval |= TPS92662_SetMlcWdgEn(DataPackets->dev_address, InitDataSrc->CMWEN);
    rtval |= TPS92662_SetMlcSlewRate(DataPackets->dev_address, InitDataSrc->SlewRate);
    rtval |= TPS92662_SetMlcOVLMT(DataPackets->dev_address, InitDataSrc->OvLimit);
    for (i = 0; i < TPS92662A_MAX_CHANNEL_NUM; i++)
    {
        data[i] = ((uint16_t)InitDataSrc->DefaultPwm[i]) * 10;
    }
    rtval |= TPS92662_SetMlcDefaultWidth(DataPackets->dev_address, data);
    rtval |= TPS92662_SetMlcAllChannelPhase(DataPackets->dev_address, InitDataSrc->PhaseShift);

    return rtval;
#endif
}

static Std_ReturnType Tps92662AWrite(void *ptr)
{
    Std_ReturnType rtval = E_OK;
    S_MatrixTripDataPackets *DataaPackets;
    DataaPackets = (S_MatrixTripDataPackets *)ptr;
    uint16_t delay = 0;

    switch (DataaPackets->DataType)
    {
    case E_MatrixTripDataType_PwmValue:
        rtval |= Tps92662A_SetChannelPwm(DataaPackets->dev_address, (S_ChannelPWMDataSrc *)(DataaPackets->datasrc));
        break;
    case E_MatrixTripDataType_MatrixComReset:
        GetResource(OsResource_UartMatrixChip);
        Port_SetPinDirection(PortConf_PortPin_CAN_TX_S, PORT_PIN_OUT);
        Port_SetPinMode(PortConf_PortPin_CAN_TX_S, PORT_PIN_MODE_GPIO);
        Dio_WriteChannel(DioConf_DioChannel_Uart0_TX, STD_LOW);
        delay = 0x1FFF;
        while (delay)
        {
            delay--;
        }
        Port_SetPinMode(PortConf_PortPin_CAN_TX_S, PORT_PIN_MODE_ALT5);
        ReleaseResource(OsResource_UartMatrixChip);
        break;
    default:
        rtval = E_NOT_OK;
        break;
    }
    return rtval;
}
static Std_ReturnType Tps92662ARead(void *ptr)
{
    Std_ReturnType rtval = E_OK;
    S_MatrixTripDataPackets *DataaPackets;
    DataaPackets = (S_MatrixTripDataPackets *)ptr;
    static uint16 width[MAX_MATRIXCHIP_CHANNEL_NUM];
    S_ChannelPWMDataSrc *ChannelPWMDataSrc;
    S_AdcValueDataSrc *AdcValueDataSrc;
    uint8_t i = 0;
    switch (DataaPackets->DataType)
    {
    case E_MatrixTripDataType_PwmValue:
        rtval |= TPS92662_GetMlcAllChannelWidth(DataaPackets->dev_address, width);
        if (rtval == E_OK)
        {
            ChannelPWMDataSrc = (S_ChannelPWMDataSrc *)(DataaPackets->datasrc);
            for (i = 0; i < MAX_MATRIXCHIP_CHANNEL_NUM; i++)
            {
                ChannelPWMDataSrc->PwmValue[i] = (uint8)(width[i] * 0.1);
            }
        }
        break;
    case E_MatrixTripDataType_AdcValue:
        AdcValueDataSrc = (S_AdcValueDataSrc *)(DataaPackets->datasrc);
        rtval |= TPS92662_GetMlcADC(DataaPackets->dev_address, AdcValueDataSrc->AdcNO, &(AdcValueDataSrc->AdcValue));
        if (rtval != E_OK)
        {
            if (ComtimeOutFlag == 1)
            {
                AdcValueDataSrc->LostComErr = 1;
            }
            else
            {
                AdcValueDataSrc->LostComErr = 0;
            }
        }
        break;
    }
    return rtval;
}

static Std_ReturnType Tps92662AMainFunction(void *ptr)
{
    Std_ReturnType rtval = E_OK;
    S_MatrixTripDataPackets *MatrixTripDataPackets;
    S_MainFunctionDataSrc *MainFunctionDataSrc;
    static uint8 syscfg;

    if (Tps92662ADevNum == 0)
        return E_NOT_OK;

    MatrixTripDataPackets = (S_MatrixTripDataPackets *)ptr;
    MainFunctionDataSrc = (S_MainFunctionDataSrc *)(MatrixTripDataPackets->datasrc);

    if (MatrixTripDataPackets->DataType != E_MatrixTripDataType_MainFunction)
        return E_NOT_OK;

    if (TPS92662_GetSYSCFG(MatrixTripDataPackets->dev_address, &syscfg) == E_OK)
    {
        MainFunctionDataSrc->ComTimeout = 0;
        MainFunctionDataSrc->ComError = 0;
        if ((Get_pLMMCMWEN() == 1) && ((syscfg & 0x08) == 0))
        {
            MainFunctionDataSrc->LostCfg = 1;
        }
        else
        {
            MainFunctionDataSrc->LostCfg = 0;
        }
    }
    else
    {
        if (ComtimeOutFlag == 1)
        {
            MainFunctionDataSrc->ComTimeout = 1;
        }
        if (ComErrorFlag == 1)
        {
            MainFunctionDataSrc->ComError = 1;
        }
    }

    return rtval;
}
/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/

Std_ReturnType Tps92662ADevRegister(void)
{
    uint8_t i = 0;
    const uint8 *tpspara = NULL;
    Std_ReturnType rtval = E_OK;

    for (i = 0; i < LOWHIGH_MAX_MATRIXCHIP_NUM; i++)
    {
        tpspara = Get_LB_HB_MatrixInfo(i);
        if (tpspara[LMM_AVL_INDEX] == 0)
        {
            break;
        }
        /*148:TLD7002*/
        if (tpspara[LMM_TYPE_INDEX] == E_TPS92662A)
        {
            if (Tps92662ADevNum >= MAX_MATRIXCHIP_NUM)
                return E_NOT_OK;

            g_Tps92662ADev[Tps92662ADevNum].MatrixChipType = E_TPS92662A;
            g_Tps92662ADev[Tps92662ADevNum].dev_address = tpspara[LMM_ADDRESS_INDEX];
            g_Tps92662ADev[Tps92662ADevNum].DeviceInit = Tps92662ADeviceInit;
            g_Tps92662ADev[Tps92662ADevNum].Write = Tps92662AWrite;
            g_Tps92662ADev[Tps92662ADevNum].Read = Tps92662ARead;
            g_Tps92662ADev[Tps92662ADevNum].MainFunction = Tps92662AMainFunction;
            g_Tps92662ADev[Tps92662ADevNum].ptNext = NULL;

            rtval |= MatrixChipDrvDev_Register(&g_Tps92662ADev[Tps92662ADevNum]);
            if (rtval == E_OK)
                Tps92662ADevNum++;
        }
    }

    for (i = 0; i < TI_MAX_MATRIXCHIP_NUM; i++)
    {
        tpspara = Get_TI_MatrixInfo(i);
        if (tpspara[LMM_AVL_INDEX] == 0)
        {
            break;
        }
       /*148:TPS92662A*/
        if (tpspara[LMM_TYPE_INDEX] == E_TPS92662A)
        {
            if (Tps92662ADevNum >= MAX_MATRIXCHIP_NUM)
                return E_NOT_OK;

            g_Tps92662ADev[Tps92662ADevNum].MatrixChipType = E_TPS92662A;
            g_Tps92662ADev[Tps92662ADevNum].dev_address = tpspara[LMM_ADDRESS_INDEX];
            g_Tps92662ADev[Tps92662ADevNum].DeviceInit = Tps92662ADeviceInit;
            g_Tps92662ADev[Tps92662ADevNum].Write = Tps92662AWrite;
            g_Tps92662ADev[Tps92662ADevNum].Read = Tps92662ARead;
            g_Tps92662ADev[Tps92662ADevNum].MainFunction = Tps92662AMainFunction;
            g_Tps92662ADev[Tps92662ADevNum].ptNext = NULL;

            rtval |= MatrixChipDrvDev_Register(&g_Tps92662ADev[Tps92662ADevNum]);
            if (rtval == E_OK)
                Tps92662ADevNum++;
        }
    }

    for (i = 0; i < DRLPOS_MAX_MATRIXCHIP_NUM; i++)
    {
        tpspara = Get_DRL_POS_MatrixInfo(i);
        if (tpspara[LMM_AVL_INDEX] == 0)
        {
            break;
        }
        /*148:TPS92662A*/
        if (tpspara[LMM_TYPE_INDEX] == E_TPS92662A)
        {
            if (Tps92662ADevNum >= MAX_MATRIXCHIP_NUM)
                return E_NOT_OK;

            g_Tps92662ADev[Tps92662ADevNum].MatrixChipType = E_TPS92662A;
            g_Tps92662ADev[Tps92662ADevNum].dev_address = tpspara[LMM_ADDRESS_INDEX];
            g_Tps92662ADev[Tps92662ADevNum].DeviceInit = Tps92662ADeviceInit;
            g_Tps92662ADev[Tps92662ADevNum].Write = Tps92662AWrite;
            g_Tps92662ADev[Tps92662ADevNum].Read = Tps92662ARead;
            g_Tps92662ADev[Tps92662ADevNum].MainFunction = Tps92662AMainFunction;
            g_Tps92662ADev[Tps92662ADevNum].ptNext = NULL;

            rtval |= MatrixChipDrvDev_Register(&g_Tps92662ADev[Tps92662ADevNum]);
            if (rtval == E_OK)
                Tps92662ADevNum++;
        }
    }

    for (i = 0; i < GRILLE_MAX_MATRIXCHIP_NUM; i++)
    {
        tpspara = Get_Grille_MatrixInfo(i);
        if (tpspara[LMM_AVL_INDEX] == 0)
        {
            break;
        }
        /*148:TLD7002*/
        if (tpspara[LMM_TYPE_INDEX] == E_TPS92662A)
        {
            if (Tps92662ADevNum >= MAX_MATRIXCHIP_NUM)
                return E_NOT_OK;

            g_Tps92662ADev[Tps92662ADevNum].MatrixChipType = E_TPS92662A;
            g_Tps92662ADev[Tps92662ADevNum].dev_address = tpspara[LMM_ADDRESS_INDEX];
            g_Tps92662ADev[Tps92662ADevNum].DeviceInit = Tps92662ADeviceInit;
            g_Tps92662ADev[Tps92662ADevNum].Write = Tps92662AWrite;
            g_Tps92662ADev[Tps92662ADevNum].Read = Tps92662ARead;
            g_Tps92662ADev[Tps92662ADevNum].MainFunction = Tps92662AMainFunction;
            g_Tps92662ADev[Tps92662ADevNum].ptNext = NULL;

            rtval |= MatrixChipDrvDev_Register(&g_Tps92662ADev[Tps92662ADevNum]);
            if (rtval == E_OK)
                Tps92662ADevNum++;
        }
    }

    for (i = 0; i < LOGO_MAX_MATRIXCHIP_NUM; i++)
    {
        tpspara = Get_Logo_MatrixInfo(i);
        if (tpspara[LMM_AVL_INDEX] == 0)
        {
            break;
        }
        /*148:TPS92662A*/
        if (tpspara[LMM_TYPE_INDEX] == E_TPS92662A)
        {
            if (Tps92662ADevNum >= MAX_MATRIXCHIP_NUM)
                return E_NOT_OK;

            g_Tps92662ADev[Tps92662ADevNum].MatrixChipType = E_TPS92662A;
            g_Tps92662ADev[Tps92662ADevNum].dev_address = tpspara[LMM_ADDRESS_INDEX];
            g_Tps92662ADev[Tps92662ADevNum].DeviceInit = Tps92662ADeviceInit;
            g_Tps92662ADev[Tps92662ADevNum].Write = Tps92662AWrite;
            g_Tps92662ADev[Tps92662ADevNum].Read = Tps92662ARead;
            g_Tps92662ADev[Tps92662ADevNum].MainFunction = Tps92662AMainFunction;
            g_Tps92662ADev[Tps92662ADevNum].ptNext = NULL;

            rtval |= MatrixChipDrvDev_Register(&g_Tps92662ADev[Tps92662ADevNum]);
            if (rtval == E_OK)
                Tps92662ADevNum++;
        }
    }

    for (i = 0; i < ASSISTANT_MAX_MATRIXCHIP_NUM; i++)
    {
        tpspara = Get_Assistant_MatrixInfo(i);
        if (tpspara[LMM_AVL_INDEX] == 0)
        {
            break;
        }
        /*148:TPS92662A*/
        if (tpspara[LMM_TYPE_INDEX] == E_TPS92662A)
        {
            if (Tps92662ADevNum >= MAX_MATRIXCHIP_NUM)
                return E_NOT_OK;

            g_Tps92662ADev[Tps92662ADevNum].MatrixChipType = E_TPS92662A;
            g_Tps92662ADev[Tps92662ADevNum].dev_address = tpspara[LMM_ADDRESS_INDEX];
            g_Tps92662ADev[Tps92662ADevNum].DeviceInit = Tps92662ADeviceInit;
            g_Tps92662ADev[Tps92662ADevNum].Write = Tps92662AWrite;
            g_Tps92662ADev[Tps92662ADevNum].Read = Tps92662ARead;
            g_Tps92662ADev[Tps92662ADevNum].MainFunction = Tps92662AMainFunction;
            g_Tps92662ADev[Tps92662ADevNum].ptNext = NULL;

            rtval |= MatrixChipDrvDev_Register(&g_Tps92662ADev[Tps92662ADevNum]);
            if (rtval == E_OK)
                Tps92662ADevNum++;
        }
    }

    for (i = 0; i < FRONTCROSS_MAX_MATRIXCHIP_NUM; i++)
    {
        tpspara = Get_FrontCross_MatrixInfo(i);
        if (tpspara[LMM_AVL_INDEX] == 0)
        {
            break;
        }
       /*148:TPS92662A*/
        if (tpspara[LMM_TYPE_INDEX] == E_TPS92662A)
        {
            if (Tps92662ADevNum >= MAX_MATRIXCHIP_NUM)
                return E_NOT_OK;

            g_Tps92662ADev[Tps92662ADevNum].MatrixChipType = E_TPS92662A;
            g_Tps92662ADev[Tps92662ADevNum].dev_address = tpspara[LMM_ADDRESS_INDEX];
            g_Tps92662ADev[Tps92662ADevNum].DeviceInit = Tps92662ADeviceInit;
            g_Tps92662ADev[Tps92662ADevNum].Write = Tps92662AWrite;
            g_Tps92662ADev[Tps92662ADevNum].Read = Tps92662ARead;
            g_Tps92662ADev[Tps92662ADevNum].MainFunction = Tps92662AMainFunction;
            g_Tps92662ADev[Tps92662ADevNum].ptNext = NULL;

            rtval |= MatrixChipDrvDev_Register(&g_Tps92662ADev[Tps92662ADevNum]);
            if (rtval == E_OK)
                Tps92662ADevNum++;
        }
    }

    return rtval;
}
