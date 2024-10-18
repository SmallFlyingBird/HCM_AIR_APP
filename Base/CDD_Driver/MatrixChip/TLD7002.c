/*
 * Tps92662A.c
 *
 */

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "TLD7002.h"
#include "MatrixChip_Interface.h"
#include "Parameter_Interface.h"
#include "Uart.h"
#include "Dio_Cfg.h"
#include "Dio.h"
#include "Port_Types.h"
#include "Port.h"
#include "McldLowLevel.h"
extern uint8 uart0_done;
extern uint8 uart1_done;

/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
static S_MatrixChipDrv_Dev g_TLD7002ADev[MAX_MATRIXCHIP_CHANNEL_NUM];
static uint8_t TLD7002ADevNum = 0;
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
#define TLD7002_CRC8_CALC_GENERATOR_POLYNOM	  0x1D
#define TLD7002_CRC8_CALC_SEED				  0xFF
#define TLD7002_CRC8_CALC_XOR_VAL			  0xFF
#define NumberofDevice                        18
#define NumberofChannel                       192
#define MCL_Length_8bit                       16
#define TLD7002_DelayMsSystem                 1
#define OS_TICKS_PER_US (80u << 8u)

#define OS_US_TO_TICKS(us) (OS_TICKS_PER_US * (us))
#define OS_MS_TO_TICKS(ms) (OS_TICKS_PER_US * 1000u * (ms))

static uint8 MIRROR_MID_CRC3_TEST[8] = {0, 4, 2, 6, 1, 5, 3, 7};

const uint8 LOOKUP_CRC3_5BIT_TEST[32] =
{
	0, 1, 5, 4, 7, 6, 2, 3, 6, 7, 3, 2, 1, 0, 4, 5,
	3, 2, 6, 7, 4, 5, 1, 0, 5, 4, 0, 1, 2, 3, 7, 6
};

uint8 LOOKUP_CRC3_8BIT_TEST[256] =
{
	0, 3, 4, 7, 2, 1, 6, 5, 1, 2, 5, 6, 3, 0, 7, 4,
	5, 6, 1, 2, 7, 4, 3, 0, 4, 7, 0, 3, 6, 5, 2, 1,
	7, 4, 3, 0, 5, 6, 1, 2, 6, 5, 2, 1, 4, 7, 0, 3,
	2, 1, 6, 5, 0, 3, 4, 7, 3, 0, 7, 4, 1, 2, 5, 6,
	6, 5, 2, 1, 4, 7, 0, 3, 7, 4, 3, 0, 5, 6, 1, 2,
	3, 0, 7, 4, 1, 2, 5, 6, 2, 1, 6, 5, 0, 3, 4, 7,
	1, 2, 5, 6, 3, 0, 7, 4, 0, 3, 4, 7, 2, 1, 6, 5,
	4, 7, 0, 3, 6, 5, 2, 1, 5, 6, 1, 2, 7, 4, 3, 0,
	3, 0, 7, 4, 1, 2, 5, 6, 2, 1, 6, 5, 0, 3, 4, 7,
	6, 5, 2, 1, 4, 7, 0, 3, 7, 4, 3, 0, 5, 6, 1, 2,
	4, 7, 0, 3, 6, 5, 2, 1, 5, 6, 1, 2, 7, 4, 3, 0,
	1, 2, 5, 6, 3, 0, 7, 4, 0, 3, 4, 7, 2, 1, 6, 5,
	5, 6, 1, 2, 7, 4, 3, 0, 4, 7, 0, 3, 6, 5, 2, 1,
	0, 3, 4, 7, 2, 1, 6, 5, 1, 2, 5, 6, 3, 0, 7, 4,
	2, 1, 6, 5, 0, 3, 4, 7, 3, 0, 7, 4, 1, 2, 5, 6,
	7, 4, 3, 0, 5, 6, 1, 2, 6, 5, 2, 1, 4, 7, 0, 3
};

uint8 TLD7002_LOOKUP_CRC8_SAE_J1850[256] =
{
	0x00, 0x1D, 0x3A, 0x27, 0x74, 0x69, 0x4E, 0x53,
	0xE8, 0xF5, 0xD2, 0xCF, 0x9C, 0x81, 0xA6, 0xBB,
	0xCD, 0xD0, 0xF7, 0xEA, 0xB9, 0xA4, 0x83, 0x9E,
	0x25, 0x38, 0x1F, 0x02, 0x51, 0x4C, 0x6B, 0x76,
	0x87, 0x9A, 0xBD, 0xA0, 0xF3, 0xEE, 0xC9, 0xD4,
	0x6F, 0x72, 0x55, 0x48, 0x1B, 0x06, 0x21, 0x3C,
	0x4A, 0x57, 0x70, 0x6D, 0x3E, 0x23, 0x04, 0x19,
	0xA2, 0xBF, 0x98, 0x85, 0xD6, 0xCB, 0xEC, 0xF1,
	0x13, 0x0E, 0x29, 0x34, 0x67, 0x7A, 0x5D, 0x40,
	0xFB, 0xE6, 0xC1, 0xDC, 0x8F, 0x92, 0xB5, 0xA8,
	0xDE, 0xC3, 0xE4, 0xF9, 0xAA, 0xB7, 0x90, 0x8D,
	0x36, 0x2B, 0x0C, 0x11, 0x42, 0x5F, 0x78, 0x65,
	0x94, 0x89, 0xAE, 0xB3, 0xE0, 0xFD, 0xDA, 0xC7,
	0x7C, 0x61, 0x46, 0x5B, 0x08, 0x15, 0x32, 0x2F,
	0x59, 0x44, 0x63, 0x7E, 0x2D, 0x30, 0x17, 0x0A,
	0xB1, 0xAC, 0x8B, 0x96, 0xC5, 0xD8, 0xFF, 0xE2,
	0x26, 0x3B, 0x1C, 0x01, 0x52, 0x4F, 0x68, 0x75,
	0xCE, 0xD3, 0xF4, 0xE9, 0xBA, 0xA7, 0x80, 0x9D,
	0xEB, 0xF6, 0xD1, 0xCC, 0x9F, 0x82, 0xA5, 0xB8,
	0x03, 0x1E, 0x39, 0x24, 0x77, 0x6A, 0x4D, 0x50,
	0xA1, 0xBC, 0x9B, 0x86, 0xD5, 0xC8, 0xEF, 0xF2,
	0x49, 0x54, 0x73, 0x6E, 0x3D, 0x20, 0x07, 0x1A,
	0x6C, 0x71, 0x56, 0x4B, 0x18, 0x05, 0x22, 0x3F,
	0x84, 0x99, 0xBE, 0xA3, 0xF0, 0xED, 0xCA, 0xD7,
	0x35, 0x28, 0x0F, 0x12, 0x41, 0x5C, 0x7B, 0x66,
	0xDD, 0xC0, 0xE7, 0xFA, 0xA9, 0xB4, 0x93, 0x8E,
	0xF8, 0xE5, 0xC2, 0xDF, 0x8C, 0x91, 0xB6, 0xAB,
	0x10, 0x0D, 0x2A, 0x37, 0x64, 0x79, 0x5E, 0x43,
	0xB2, 0xAF, 0x88, 0x95, 0xC6, 0xDB, 0xFC, 0xE1,
	0x5A, 0x47, 0x60, 0x7D, 0x2E, 0x33, 0x14, 0x09,
	0x7F, 0x62, 0x45, 0x58, 0x0B, 0x16, 0x31, 0x2C,
	0x97, 0x8A, 0xAD, 0xB0, 0xE3, 0xFE, 0xD9, 0xC4
};

static FRAME_RC_2BIT_t  Curr_MRC[NUM_DEVICES] = {0};

uint32 Delay_TLD7002 = 0;
uint32 delay_softTLD7002 = 0;
uint8  UpdataFinish_Flag = 6;

TLD7002_LPIT_PAR TLD7002_Device_Buffer[NumberofDevice] = {0};

uint8 TLD_7002Duty_8bit[101]=
{
	0,31,43,52,59,65,71,76,81,85,
	90,94,97,101,104,108,111,114,117,120,
	123,125,128,131,133,136,138,141,143,145,
	148,150,152,154,156,158,160,162,164,166,
	168,170,172,174,176,177,179,181,183,184,
	186,188,189,191,193,194,196,198,199,201,
	202,204,205,207,208,210,211,213,214,215,
	217,218,220,221,222,224,225,226,228,229,
	230,232,233,234,236,237,238,239,241,242,
	243,244,246,247,248,249,250,251,253,254,
	255
};
TLD7002_UART_PAR g_tpsuartpar[3]=
{
	{
		.uartid=ID_UART0,
		.busstate=BUS_TLD7002_IDLE,
		.busError=0,
		.busRecOk=0,
	},
	{
		.uartid=ID_UART1,
		.busstate=BUS_TLD7002_IDLE,
		.busError=0,
		.busRecOk=0,
	},
	{
		.uartid=ID_UART2,
		.busstate=BUS_TLD7002_IDLE,
		.busError=0,
		.busRecOk=0,
	},
};

void Reset_Frame_PAR(uint8 uartid)
{
	g_tpsuartpar[uartid].busError=0;
	g_tpsuartpar[uartid].busRecOk=0;
	g_tpsuartpar[uartid].busstate=BUS_TLD7002_IDLE;
	g_tpsuartpar[uartid].RxdataCnt=0;

	for(uint8_t i=0;i<50;i++)
	{
		g_tpsuartpar[uartid].rcvdata[i]=0;
		g_tpsuartpar[uartid].Txdata[i]=0;
	}
}

TLD7002_UART_PAR *GetFramePAR(uint8 uartid)
{
	return &g_tpsuartpar[uartid];
}

void TLD7002_Delay_us(uint32 delaytime)
{
    uint32 i = delaytime;
	while(i>0)
	{
	    i--;
	}
}

uint16 calcChDc14BitValue_TEST(uint16 dc_perc)
{
	uint16 ret_val = 0;	/*< variable to store the value to be returned */
//	double tst = 0.0;/*< variable to store calculated DC value */

	if(dc_perc <= 0)
	{ /*< for 0 percent duty cycle -> set to minimum value (avoid errors in rounding) */
		ret_val = CH_MIN_DC_VAL;
	}
	else if(dc_perc >= 10000)
	{ /*< for 100 percent duty cycle -> set to minimum value (avoid errors in rounding) */
		ret_val = CH_MAX_DC_14BIT_VAL;
	}
	else
	{ /*< for all other values the duty cycle is calculated */
		ret_val=(uint16)((((double)dc_perc)/10000.0)*16383.0+0.5);
	}
	return ret_val;
}

/*函数功能：计算发送数组中的CRC位
*
*/
void mcld_calculate_crc3_master_request_test(uint8* data,uint8 *result)
{
	uint8 crc = CRC3_CALC_SEED;

	crc = LOOKUP_CRC3_5BIT_TEST[(crc ^ data[0])];
	crc = MIRROR_MID_CRC3_TEST[crc];
	crc = LOOKUP_CRC3_8BIT_TEST[(crc ^ data[1])];
	*result = crc;
}
void mcld_calculate_crc3_slave_request_test(uint8* data,uint8 *result)
{
	uint8 crc = CRC3_CALC_SEED;

	crc = LOOKUP_CRC3_8BIT_TEST[(crc ^ data[0])];
	crc = MIRROR_MID_CRC3_TEST[crc];
	crc = LOOKUP_CRC3_5BIT_TEST[(crc ^ data[1])];
	*result=crc;
}
uint8 mcld_calculate_crc8_general_test(uint8* data_array,uint8 data_len)
{
	uint8 crc = TLD7002_CRC8_CALC_SEED;	/* CRC initial value */
	uint8 index = 0;
//	uint8 bit = 0;
	#if (TLD7002_CRC8_CONF_ALGORITHM == TLD7002_CRC8_USE_LUT)
		/* CRC-8-SAE J1850 algorithm */
		/* all elements of the data array */
		for (index=0; index<data_len; index++)
		{
			/* use data bytes */
			crc = TLD7002_LOOKUP_CRC8_SAE_J1850[crc ^ data_array[index]];
		}
	#elif (TLD7002_CRC8_CONF_ALGORITHM == TLD7002_CRC8_USE_CALC)
		/* CRC-8-SAE J1850 algorithm */
		/* all elements of the data array */
		for (index=0; index<data_len; index++)
		{
			/* use data bytes */
			crc ^= data_array[index];
			for(bit=0; bit<8; bit++)
			{
				if ((crc & 0x80)!=0)
				{
					crc <<= 1;
					crc ^= TLD7002_CRC8_CALC_GENERATOR_POLYNOM;
				}
				else
				{
					crc <<= 1;
				}
			}
		}
	#endif
		crc = crc ^ TLD7002_CRC8_CALC_XOR_VAL;	/* write CRC into SAFETY_BYTE */
		return crc;
}

uint8 TLD7002_calculate_crc8_leadbyte_Test(uint8* data_array , uint8 data_len, uint8 lead_byte)
{
	uint8 crc = TLD7002_CRC8_CALC_SEED;	/* CRC initial value */
	uint8 index = 0;
//	uint8 bit = 0;
	#if (TLD7002_CRC8_CONF_ALGORITHM == TLD7002_CRC8_USE_LUT)
		/* CRC-8-SAE J1850 algorithm for first element (lead_byte) */
		crc = TLD7002_LOOKUP_CRC8_SAE_J1850[crc ^ lead_byte];

		/* CRC-8-SAE J1850 algorithm */
		/* all elements of the data array */
		for (index=0; index<data_len; index++)
		{
			/* use data bytes */
			crc = TLD7002_LOOKUP_CRC8_SAE_J1850[crc ^ data_array[index]];
		}

	#elif (TLD7002_CRC8_CONF_ALGORITHM == TLD7002_CRC8_USE_CALC)
		/* CRC-8-SAE J1850 algorithm for first element (lead_byte) */
		crc ^= lead_byte;

		for(bit=0; bit<8; bit++)
		{
			if ((crc & 0x80)!=0)
			{
				crc <<= 1;
				crc ^= TLD7002_CRC8_CALC_GENERATOR_POLYNOM;
			}
			else
			{
				crc <<= 1;
			}
		}

		/* CRC-8-SAE J1850 algorithm for data array */
		/* all elements of the data array */
		for (index=0; index<data_len; index++)
		{
			/* use data bytes */
			crc ^= data_array[index];

			for(bit=0; bit<8; bit++)
			{
				if ((crc & 0x80)!=0)
				{
					crc <<= 1;
					crc ^= TLD7002_CRC8_CALC_GENERATOR_POLYNOM;
				}
				else
				{
					crc <<= 1;
				}
			}
		}
	#endif
		crc = crc ^ TLD7002_CRC8_CALC_XOR_VAL;				/* write CRC into SAFETY_BYTE */
		return crc;

}


void TLD7002_init_low_level(void)
{
	/* reset master rolling counter to initial values */
	//TLD7002_curr_master_rc = 0;

	/* reset slave rolling counters to initial values */
	for(uint8 index = 0; index < 31; index++)
	{
		Curr_MRC[index] = 0;
	}
}
uint8 usTxUartData_PM_CHANGE[12] = {1};
/*函数功能：初始化调用 内部调用 电源模式转换  
不调用也可以初始化，AEF推荐加上，防止被篡改
* 发送信号：
* [0]=0x55;
* [1]=CRC+0x1f&Deviceaddress;
* [2]=(uint8)(((Curr_MRC[0]<<6)&0xC0) | ((0x01<<3)&0x38) | (FRAME_FUN_PM_CHANGE&0x7));  2字节
* [3]=(uint8)(mode & 0x07); 初始化=0
* [4]=0
* [5]=CRC
* 输入：UartPort：串口号
       address：发送的从机地址 
	   mode ：只用到初始化模式。OTP模式未使用
* 输出：dc_val：从机读到的buf 
*/
uint8 PM_CHANGE(uint8 UartPort,uint8 address, FRAME_PM_t mode )
{
	uint8 usTxUartCRC1[2] = {0};
	uint8 usTxUartCRC2[2] = {0};
	uint8 ret_val = 0;
	uint8 CRC_result[2] = {0};
	uint8 i = 0;
	TLD7002_UART_PAR *  RxUartData = NULL;
	for(i=0; i<12; i++)
	{
		usTxUartData_PM_CHANGE[i] = 0;
	}
	TLD7002_Delay_us(1000);

	if(address <= 0x1F)
	{
		usTxUartData_PM_CHANGE[0] = 0x55;
		usTxUartData_PM_CHANGE[1] = address & 0x1F;

		usTxUartData_PM_CHANGE[2] = (uint8)(((Curr_MRC[0]<<6)&0xC0) | ((0x01<<3)&0x38) | (FRAME_FUN_PM_CHANGE&0x7));
		Curr_MRC[0] = mcld_get_next_rc_val(Curr_MRC[0]);

		if(address != FRAME_SLAVE_ADDRESS_BROADCAST)
		{	/*< only for messages which are not broadcast messages (would lead to two times increasing MRC) */
			Curr_MRC[address] = mcld_get_next_rc_val(Curr_MRC[address]);							/*< calculate expected Rolling Counter for answer */
		}

		usTxUartData_PM_CHANGE[3] = (uint8)(mode & 0x07);
		usTxUartData_PM_CHANGE[4] = 0x00;

		usTxUartCRC1[0] = usTxUartData_PM_CHANGE[1];
		usTxUartCRC1[1] = usTxUartData_PM_CHANGE[2];
		mcld_calculate_crc3_master_request_test(usTxUartCRC1, &CRC_result[0]);
		usTxUartData_PM_CHANGE[1] = (uint8)(((CRC_result[0]<<5)&0xE0) | (usTxUartData_PM_CHANGE[1]));

		usTxUartCRC2[0] = usTxUartData_PM_CHANGE[3];
		usTxUartCRC2[1] = 0x00;
		usTxUartData_PM_CHANGE[5] = mcld_calculate_crc8_general_test(usTxUartCRC2, 2);

		Reset_Frame_PAR(UartPort);
	    RxUartData = GetFramePAR(UartPort);
	    RxUartData->mode = Wtite_mode;
	    RxUartData->busstate = BUS_TLD7002_SYNC;
		RxUartData->slaveaddr = usTxUartData_PM_CHANGE[1];
		RxUartData->MRC_DLC_FUN = usTxUartData_PM_CHANGE[2];
		RxUartData->PowerMode = usTxUartData_PM_CHANGE[3];
		RxUartData->Power_Reser = usTxUartData_PM_CHANGE[4];
		RxUartData->crc = usTxUartData_PM_CHANGE[5];
		RxUartData->rcvdatalens = PM_CHANGE_Lenth;
		RxUartData->Txdatalens = 6;
		RxUartData->RxdataCnt = 0;

		if(UartPort == ID_UART0)
		{
			Uart_AsyncSend(ID_UART0, usTxUartData_PM_CHANGE, 6);
			TLD7002_Delay_us(7000);
		}
		else if(UartPort == ID_UART1)
		{
			Uart_AsyncSend(ID_UART1, usTxUartData_PM_CHANGE, 6);
			TLD7002_Delay_us(7000);
		}
		else if(UartPort == ID_UART2)
		{
			Uart_AsyncSend(ID_UART2, usTxUartData_PM_CHANGE, 6);
			TLD7002_Delay_us(7000);
		}

	}
	else
    {
		ret_val = ADDR_ERR;
		Reset_Frame_PAR(UartPort);
	}
     return ret_val;
}

/*函数功能：来触发多个从机的同步采样事件
* 发送信号：
* [0]=0x55;
* [1]=CRC+0x1f&Deviceaddress;
* [2]= MRC ;DLC=0:0字节；FUN=0 广播
* 输入：UartPort 串口号
*/
uint8 usTxUartData_SYNC[12] = {1};
void MCLD_BRDC_DC_SYNC_FRAME_Dynamic(uint8 UartPort)
{
	uint8 usTxUartCRC1[2] = {0};
	uint8 CRC_result[2] = {0};
	TLD7002_UART_PAR *  RxUartData = NULL;

	for(uint8 i=0;i<12;i++)
	{
		usTxUartData_SYNC[i]=0;
	}

	TLD7002_Delay_us(100);

	usTxUartData_SYNC[0] = 0x55;
	usTxUartData_SYNC[1] = 0x00;

	usTxUartData_SYNC[2] = (uint8)((Curr_MRC[0]<<6) | (FRAME_DLC_0<<3) | (FRAME_FUN_BRDC_DC_SYNC&0x7));
	Curr_MRC[0] = mcld_get_next_rc_val(Curr_MRC[0]);

	usTxUartCRC1[0] = usTxUartData_SYNC[1];
	usTxUartCRC1[1] = usTxUartData_SYNC[2];
	mcld_calculate_crc3_master_request_test(usTxUartCRC1, &CRC_result[0]);
	usTxUartData_SYNC[1] = (uint8)(((CRC_result[0]<<5)&0xE0) | (usTxUartData_SYNC[1]));

	Reset_Frame_PAR(UartPort);
	RxUartData = GetFramePAR(UartPort);
	RxUartData->mode = HWWCR_mode;
	RxUartData->RxdataCnt = 0;

	if(UartPort == ID_UART0)
	{
		Uart_AsyncSend(ID_UART0, usTxUartData_SYNC, 3);
		TLD7002_Delay_us(100);
	}
	else if(UartPort ==ID_UART1)
	{
		Uart_AsyncSend(ID_UART1, usTxUartData_SYNC, 3);
		TLD7002_Delay_us(100);
	}
	else if(UartPort ==ID_UART2)
	{
		Uart_AsyncSend(ID_UART2, usTxUartData_SYNC, 3);
		TLD7002_Delay_us(100);
	}

}
uint8 usTxUartData_DC_UPDATE8BIT[50] = {1};
/*函数功能：轮询更新芯片寄存器的值 用于更新PWM 控制开关和亮度
* 发送信号：
* [0]=0x55;
* [1]=CRC+0x1f&Deviceaddress;
* [2]= MRC ;DLC=4:16字节；FUN=1 轮询更新寄存器的值
* [bit3~18] 0xFF
* bit[9] 0
* bit[10] 0xFF
* bit[11] CRC
* 输入：
* Deviceaddress：发送的从机地址 
* dc_val：
*/
uint8  MCLD_DC_UPDATE_8BIT_FRAME_TSET_Dynamic(uint8 UartPort,uint8 address,uint8* dc_val)
{

	uint8 usTxUartCRC1[2] = {0};
	uint8 ret_val = 0;
	uint8 CRC_result[2] = {0};
	TLD7002_UART_PAR *  RxUartData = NULL;
	for(uint8 i=0;i<50;i++)
	{
		usTxUartData_DC_UPDATE8BIT[i]=0;
	}
	TLD7002_Delay_us(100);
	if(address >= FRAME_SLAVE_ADDRESS_1 && address <= FRAME_SLAVE_ADDRESS_31) //地址合法
	{
		usTxUartData_DC_UPDATE8BIT[0] = 0x55;
		usTxUartData_DC_UPDATE8BIT[1] = 0x1f & address;

		usTxUartData_DC_UPDATE8BIT[2] = (uint8)((Curr_MRC[0]<<6) | (FRAME_DLC_4<<3) | (FRAME_FUN_DC_UPDATE&0x7));
		Curr_MRC[0] = mcld_get_next_rc_val(Curr_MRC[0]);
		Curr_MRC[address] = mcld_get_next_rc_val(Curr_MRC[address]);

		usTxUartCRC1[0] = usTxUartData_DC_UPDATE8BIT[1];
		usTxUartCRC1[1] = usTxUartData_DC_UPDATE8BIT[2];
		mcld_calculate_crc3_master_request_test(usTxUartCRC1, &CRC_result[0]);
		usTxUartData_DC_UPDATE8BIT[1] = (uint8)(((CRC_result[0]<<5)&0xE0) | (usTxUartData_DC_UPDATE8BIT[1]));

		for(uint8 i=0;i<MCL_Length_8bit;i++)
		{
		  usTxUartData_DC_UPDATE8BIT[i+3] = dc_val[i];
		}

		usTxUartData_DC_UPDATE8BIT[19] = mcld_calculate_crc8_general_test(&usTxUartData_DC_UPDATE8BIT[3],16);

		Reset_Frame_PAR(UartPort);
		RxUartData = GetFramePAR(UartPort);
		RxUartData->mode = Wtite_mode;
		RxUartData->busstate = BUS_TLD7002_SYNC;//BUS_TLD7002_SYNC
		RxUartData->rcvdatalens = 22;
		RxUartData->Txdatalens = 20;
		RxUartData->RxdataCnt = 0;
		if(UartPort == ID_UART0)
		{
			Uart_AsyncSend(ID_UART0, usTxUartData_DC_UPDATE8BIT, LEN_DC_UPDATE_8BIT_WRITE);
			TLD7002_Delay_us(1000);//2500//1200
		}
		else if(UartPort == ID_UART1)
		{
			Uart_AsyncSend(ID_UART1, usTxUartData_DC_UPDATE8BIT, LEN_DC_UPDATE_8BIT_WRITE);
			TLD7002_Delay_us(1000);

		}
		else if(UartPort == ID_UART2)
		{
			Uart_AsyncSend(ID_UART2, usTxUartData_DC_UPDATE8BIT, LEN_DC_UPDATE_8BIT_WRITE);
			TLD7002_Delay_us(1000);
		}
	 }
	else
	{
		ret_val = ADDR_ERR;
	}
	return ret_val;

}
static Std_ReturnType TLD7002_SetChannelPwm(uint8 addr, S_ChannelPWMDataSrc *datasrc)
{
    Std_ReturnType rtval = E_OK;
    uint8 ch=0,ADDR=0;
    uint16 RW_data[16] = {
        0x00,
    };

    ADDR = addr;
    for (ch = 0; ch < MAX_MATRIXCHIP_CHANNEL_NUM; ch++) 
    {
        if (datasrc->PwmValue[ch] >= 100)
        {
            RW_data[ch] = 1023;
        }
        else
            RW_data[ch] = ((uint16)(datasrc->PwmValue[ch])) * 1.023 * 10;
    }
		
	rtval |= MCLD_DC_UPDATE_8BIT_FRAME_TSET_Dynamic(ID_UART0, ADDR,RW_data);//功能码1：轮询更新PWM占空比
    MCLD_BRDC_DC_SYNC_FRAME_Dynamic(ID_UART0); //功能码0：触发多个从机的采样事件

    return rtval;
}

/*读取通道PWM*/
Std_ReturnType TLD7002_GetMlcAllChannelWidth(uint8 addr, uint16 *width)
{
    uint8 ch, count;
    Std_ReturnType ucStatus;
    return ucStatus;
}


Std_ReturnType TLD7002_GetSYSCFG(uint8 addr, uint8 *SYSCFG)
{
    uint8 ch, count;
    Std_ReturnType ucStatus;
    LEDDriver_Type_t sMLC;
    sMLC.addr.addr = addr;
    uint8 data[1] = {
        0x00,
    };

    // ucStatus = LEDDriver_ReadCmd(&sMLC, LEDDriver_SYSCFG, data, 1);
    // if (ucStatus == E_OK)
    //     *SYSCFG = data[0];
    return ucStatus;
}

static Std_ReturnType TLD7002ADeviceInit(void *ptr)
{
    uint8 ch=0;
    S_MatrixTripDataPackets *DataPackets;
    DataPackets = (S_MatrixTripDataPackets *)ptr;
    for (ch = 0; ch < MAX_MATRIXCHIP_CHANNEL_NUM; ch++)
    {
        PM_CHANGE(ID_UART0,DataPackets->dev_address, FRAME_PM_INIT_MODE );
    }
}

static Std_ReturnType TLD7002Write(void *ptr)
{
    Std_ReturnType rtval = E_OK;
    S_MatrixTripDataPackets *DataaPackets;
    DataaPackets = (S_MatrixTripDataPackets *)ptr;
    uint16_t delay = 0;

    switch (DataaPackets->DataType)
    {
    case E_MatrixTripDataType_PwmValue:
        rtval |= TLD7002_SetChannelPwm(DataaPackets->dev_address, (S_ChannelPWMDataSrc *)(DataaPackets->datasrc));
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
static Std_ReturnType TLD7002Read(void *ptr)
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
    // case E_MatrixTripDataType_PwmValue://怎么获取芯片内部的PWM
    //     rtval |= TPS92662_GetMlcAllChannelWidth(DataaPackets->dev_address, width);
    //     if (rtval == E_OK)
    //     {
    //         ChannelPWMDataSrc = (S_ChannelPWMDataSrc *)(DataaPackets->datasrc);
    //         for (i = 0; i < MAX_MATRIXCHIP_CHANNEL_NUM; i++)
    //         {
    //             ChannelPWMDataSrc->PwmValue[i] = (uint8)(width[i] * 0.1);
    //         }
    //     }
    //     break;
    // case E_MatrixTripDataType_AdcValue: //怎么获取ADC采样值
    //     AdcValueDataSrc = (S_AdcValueDataSrc *)(DataaPackets->datasrc);
    //     rtval |= TPS92662_GetMlcADC(DataaPackets->dev_address, AdcValueDataSrc->AdcNO, &(AdcValueDataSrc->AdcValue));
    //     if (rtval != E_OK)
    //     {
    //         if (ComtimeOutFlag == 1)
    //         {
    //             AdcValueDataSrc->LostComErr = 1;
    //         }
    //         else
    //         {
    //             AdcValueDataSrc->LostComErr = 0;
    //         }
    //     }
    //     break;
    }
    return rtval;
}

//判断芯片是否超时 是否丢失配置
static Std_ReturnType DLT7002_MainFunction(void *ptr)
{
    Std_ReturnType rtval = E_OK;
    S_MatrixTripDataPackets *MatrixTripDataPackets;
    S_MainFunctionDataSrc *MainFunctionDataSrc;
    static uint8 syscfg;

    if (g_TLD7002ADev == 0)
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

Std_ReturnType TLD7002ADevRegister(void)
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
        /*151:TLD7002*/
        if (tpspara[LMM_TYPE_INDEX] == E_TLD7002)
        {
            if (g_TLD7002ADev >= MAX_MATRIXCHIP_NUM)
                return E_NOT_OK;

            g_TLD7002ADev[TLD7002ADevNum].MatrixChipType = E_TLD7002;
            g_TLD7002ADev[TLD7002ADevNum].dev_address = tpspara[LMM_ADDRESS_INDEX];
            g_TLD7002ADev[TLD7002ADevNum].DeviceInit = TLD7002ADeviceInit;
            g_TLD7002ADev[TLD7002ADevNum].Write = TLD7002Write;
            g_TLD7002ADev[TLD7002ADevNum].Read = TLD7002Read;
            g_TLD7002ADev[TLD7002ADevNum].MainFunction = DLT7002_MainFunction;
            g_TLD7002ADev[TLD7002ADevNum].ptNext = NULL;

            rtval |= MatrixChipDrvDev_Register(&g_TLD7002ADev[TLD7002ADevNum]);
            if (rtval == E_OK)
                TLD7002ADevNum++;
        }
    }

    for (i = 0; i < TI_MAX_MATRIXCHIP_NUM; i++)
    {
        tpspara = Get_TI_MatrixInfo(i);
        if (tpspara[LMM_AVL_INDEX] == 0)
        {
            break;
        }
        /*151:TLD7002*/
        if (tpspara[LMM_TYPE_INDEX] == E_TLD7002)
        {
            if (TLD7002ADevNum >= MAX_MATRIXCHIP_NUM)
                return E_NOT_OK;

            g_TLD7002ADev[TLD7002ADevNum].MatrixChipType = E_TLD7002;
            g_TLD7002ADev[TLD7002ADevNum].dev_address = tpspara[LMM_ADDRESS_INDEX];
            g_TLD7002ADev[TLD7002ADevNum].DeviceInit = TLD7002ADeviceInit;
            g_TLD7002ADev[TLD7002ADevNum].Write = TLD7002Write;
            g_TLD7002ADev[TLD7002ADevNum].Read = TLD7002Read;
            g_TLD7002ADev[TLD7002ADevNum].MainFunction = DLT7002_MainFunction;
            g_TLD7002ADev[TLD7002ADevNum].ptNext = NULL;

            rtval |= MatrixChipDrvDev_Register(&g_TLD7002ADev[TLD7002ADevNum]);
            if (rtval == E_OK)
                TLD7002ADevNum++;
        }
    }

    for (i = 0; i < DRLPOS_MAX_MATRIXCHIP_NUM; i++)
    {
        tpspara = Get_DRL_POS_MatrixInfo(i);
        if (tpspara[LMM_AVL_INDEX] == 0)
        {
            break;
        }
        /*151:TLD7002*/
        if (tpspara[LMM_TYPE_INDEX] == E_TLD7002)
        {
            if (TLD7002ADevNum >= MAX_MATRIXCHIP_NUM)
                return E_NOT_OK;

            g_TLD7002ADev[TLD7002ADevNum].MatrixChipType = E_TLD7002;
            g_TLD7002ADev[TLD7002ADevNum].dev_address = tpspara[LMM_ADDRESS_INDEX];
            g_TLD7002ADev[TLD7002ADevNum].DeviceInit = TLD7002ADeviceInit;
            g_TLD7002ADev[TLD7002ADevNum].Write = TLD7002Write;
            g_TLD7002ADev[TLD7002ADevNum].Read = TLD7002Read;
            g_TLD7002ADev[TLD7002ADevNum].MainFunction = DLT7002_MainFunction;
            g_TLD7002ADev[TLD7002ADevNum].ptNext = NULL;

            rtval |= MatrixChipDrvDev_Register(&g_TLD7002ADev[TLD7002ADevNum]);
            if (rtval == E_OK)
                TLD7002ADevNum++;
        }
    }

    for (i = 0; i < GRILLE_MAX_MATRIXCHIP_NUM; i++)
    {
        tpspara = Get_Grille_MatrixInfo(i);
        if (tpspara[LMM_AVL_INDEX] == 0)
        {
            break;
        }
        /*151:TLD7002*/
        if (tpspara[LMM_TYPE_INDEX] == E_TLD7002)
        {
            if (TLD7002ADevNum >= MAX_MATRIXCHIP_NUM)
                return E_NOT_OK;

            g_TLD7002ADev[TLD7002ADevNum].MatrixChipType = E_TLD7002;
            g_TLD7002ADev[TLD7002ADevNum].dev_address = tpspara[LMM_ADDRESS_INDEX];
            g_TLD7002ADev[TLD7002ADevNum].DeviceInit = TLD7002ADeviceInit;
            g_TLD7002ADev[TLD7002ADevNum].Write = TLD7002Write;
            g_TLD7002ADev[TLD7002ADevNum].Read = TLD7002Read;
            g_TLD7002ADev[TLD7002ADevNum].MainFunction = DLT7002_MainFunction;
            g_TLD7002ADev[TLD7002ADevNum].ptNext = NULL;

            rtval |= MatrixChipDrvDev_Register(&g_TLD7002ADev[TLD7002ADevNum]);
            if (rtval == E_OK)
                TLD7002ADevNum++;
        }
    }

    for (i = 0; i < LOGO_MAX_MATRIXCHIP_NUM; i++)
    {
        tpspara = Get_Logo_MatrixInfo(i);
        if (tpspara[LMM_AVL_INDEX] == 0)
        {
            break;
        }
        /*151:TLD7002*/
        if (tpspara[LMM_TYPE_INDEX] == E_TLD7002)
        {
            if (TLD7002ADevNum >= MAX_MATRIXCHIP_NUM)
                return E_NOT_OK;

            g_TLD7002ADev[TLD7002ADevNum].MatrixChipType = E_TLD7002;
            g_TLD7002ADev[TLD7002ADevNum].dev_address = tpspara[LMM_ADDRESS_INDEX];
            g_TLD7002ADev[TLD7002ADevNum].DeviceInit = TLD7002ADeviceInit;
            g_TLD7002ADev[TLD7002ADevNum].Write = TLD7002Write;
            g_TLD7002ADev[TLD7002ADevNum].Read = TLD7002Read;
            g_TLD7002ADev[TLD7002ADevNum].MainFunction = DLT7002_MainFunction;
            g_TLD7002ADev[TLD7002ADevNum].ptNext = NULL;

            rtval |= MatrixChipDrvDev_Register(&g_TLD7002ADev[TLD7002ADevNum]);
            if (rtval == E_OK)
                TLD7002ADevNum++;
        }
    }

    for (i = 0; i < ASSISTANT_MAX_MATRIXCHIP_NUM; i++)
    {
        tpspara = Get_Assistant_MatrixInfo(i);
        if (tpspara[LMM_AVL_INDEX] == 0)
        {
            break;
        }
        /*151:TLD7002*/
        if (tpspara[LMM_TYPE_INDEX] == E_TLD7002)
        {
            if (TLD7002ADevNum >= MAX_MATRIXCHIP_NUM)
                return E_NOT_OK;

            g_TLD7002ADev[TLD7002ADevNum].MatrixChipType = E_TLD7002;
            g_TLD7002ADev[TLD7002ADevNum].dev_address = tpspara[LMM_ADDRESS_INDEX];
            g_TLD7002ADev[TLD7002ADevNum].DeviceInit = TLD7002ADeviceInit;
            g_TLD7002ADev[TLD7002ADevNum].Write = TLD7002Write;
            g_TLD7002ADev[TLD7002ADevNum].Read = TLD7002Read;
            g_TLD7002ADev[TLD7002ADevNum].MainFunction = DLT7002_MainFunction;
            g_TLD7002ADev[TLD7002ADevNum].ptNext = NULL;

            rtval |= MatrixChipDrvDev_Register(&g_TLD7002ADev[TLD7002ADevNum]);
            if (rtval == E_OK)
                TLD7002ADevNum++;
        }
    }

    for (i = 0; i < FRONTCROSS_MAX_MATRIXCHIP_NUM; i++)
    {
        tpspara = Get_FrontCross_MatrixInfo(i);
        if (tpspara[LMM_AVL_INDEX] == 0)
        {
            break;
        }
        /*151:TLD7002*/
        if (tpspara[LMM_TYPE_INDEX] == E_TLD7002)
        {
            if (TLD7002ADevNum >= MAX_MATRIXCHIP_NUM)
                return E_NOT_OK;

            g_TLD7002ADev[TLD7002ADevNum].MatrixChipType = E_TLD7002;
            g_TLD7002ADev[TLD7002ADevNum].dev_address = tpspara[LMM_ADDRESS_INDEX];
            g_TLD7002ADev[TLD7002ADevNum].DeviceInit = TLD7002ADeviceInit;
            g_TLD7002ADev[TLD7002ADevNum].Write = TLD7002Write;
            g_TLD7002ADev[TLD7002ADevNum].Read = TLD7002Read;
            g_TLD7002ADev[TLD7002ADevNum].MainFunction = DLT7002_MainFunction;
            g_TLD7002ADev[TLD7002ADevNum].ptNext = NULL;

            rtval |= MatrixChipDrvDev_Register(&g_TLD7002ADev[TLD7002ADevNum]);
            if (rtval == E_OK)
                TLD7002ADevNum++;
        }
    }

    return rtval;
}


uint8 usTxUartData_READ_OST_COM1[20]={1};
uint8 usRxUartData_READ_OST_COM1[20]={1};
/*函数功能：读诊断信息
* 发送信号：
* [0]=0x55;
* [1]=CRC+0x1f&Deviceaddress;
* [2]=(uint8_t)(((Curr_MRC[0]<<6)&0xC0)|((0x04<<3)&0x38)|(FRAME_FUN_READ_OST&0x7)); 16字节
* 输入：Deviceaddress：发送的从机地址 
* 输出：dc_val：从机读到的buf 
*/
uint8  TLD7002Diagnose(uint8 Deviceaddress, uint8* dc_val)
{
    uint8 usTxUartCRC1[2]={0};
	uint8 i,ret_val=0;
	uint8 CRC_result[2]={0};
	Std_ReturnType sendStatus=E_OK;
	TLD7002_UART_PAR *  RxUartData=NULL;
	uint8 usRxUartCRC[2]={0};
	uint8 RxCRC_result[2]={0};
	uint8 RX_FlagErr=0;

	uint32 T_timeout,T_bytesRemaining;
	// Uart_StatusType Uart_TransmitStatus;
	for(uint8 i=0;i<20;i++)
	{
		usTxUartData_READ_OST_COM1[i]=0;
	}

	TLD7002_Delay_us(100);

	if((Deviceaddress<=FRAME_SLAVE_ADDRESS_31)&&(Deviceaddress>=FRAME_SLAVE_ADDRESS_1))
	{
		usTxUartData_READ_OST_COM1[0]=0x55;
		usTxUartData_READ_OST_COM1[1]=0x1f&Deviceaddress;

		usTxUartData_READ_OST_COM1[2]=(uint8_t)(((Curr_MRC[0]<<6)&0xC0)|((0x04<<3)&0x38)|(FRAME_FUN_READ_OST&0x7));
		Curr_MRC[0] = mcld_get_next_rc_val(Curr_MRC[0]); //MRC+1 滚动计数器 0 1 2 3 0 1 2 3...
		if(Deviceaddress != FRAME_SLAVE_ADDRESS_BROADCAST)
		{											/*< only for messages which are not broadcast messages (would lead to two times increasing MRC) */
			Curr_MRC[Deviceaddress] = mcld_get_next_rc_val(Curr_MRC[Deviceaddress]);							/*< calculate expected Rolling Counter for answer */
		}

		usTxUartCRC1[0]=usTxUartData_READ_OST_COM1[1];
		usTxUartCRC1[1]=usTxUartData_READ_OST_COM1[2];
		mcld_calculate_crc3_master_request_test(usTxUartCRC1,&CRC_result[0]);
		usTxUartData_READ_OST_COM1[1]=(uint8_t)(((CRC_result[0]<<5)&0xE0)|(usTxUartData_READ_OST_COM1[1]));

		Reset_Frame_PAR(ID_UART0); //ID_UART0数组清零
		RxUartData=GetFramePAR(ID_UART0); //数组清零后赋值给RxUartData
		RxUartData->mode=READ_OST_mode;
		RxUartData->busstate=BUS_TLD7002_SYNC;
		RxUartData->rcvdatalens=Rxdata_ReadOTS_Lenth;
		RxUartData->Txdatalens=3;
		RxUartData->RxdataCnt=0;

        uint32 T_bytesRemaining;
        uint32 T_timeout = 0x2000;
        /*Uart_StatusType Uart_TransmitStatus = UART_STATUS_TIMEOUT;*/
        /*Uart_StatusType Uart_ReceiveStatus = UART_STATUS_TIMEOUT;*/

        GetResource(OsResource_UartMatrixChip);
        delay_softTLD7002=Uart_GetTicks();//获取当前的时间点
        sendStatus = Uart_AsyncReceive(ID_UART0,usRxUartData_READ_OST_COM1,Rxdata_ReadOTS_Lenth);
        sendStatus|=Uart_AsyncSend(ID_UART0,usTxUartData_READ_OST_COM1,LEN_READ_REG_OVHD);
        // if(sendStatus==E_NOT_OK){
        //     Uart_Abort(COM1,UART_SEND);
        //     Uart_Abort(COM1,UART_RECEIVE);
        //     return E_NOT_OK;
        // }

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
            for(i = 0; i < 16; i++)
            {
                dc_val[i] = usRxUartData_READ_OST_COM1[i+3]; //将接收到的数据存储到dc_val[]
            }
        }

        ReleaseResource(OsResource_UartMatrixChip);
        return sendStatus;
    }
}


//读温度读ADC
// MCLD_Read_Reg_DMA(1,0x02,0x36,dc_val2,1,devicemode1);
#if 0

uint8  MCLD_Read_Reg_DMA(uint8 UartPort,uint8 Deviceaddress,uint8 Startadd,uint16* dc_val,uint8 Lenth,uint8 * devicemode)
{

			    uint8 usTxUartCRC1[2]={0};
			 	uint8 ret_val=0;
			 	uint8 CRC_result[2]={0};
			 	uint8 usTxUartData_Lenth=0;
			 	uint8  lenthofdata[2]={0};


			 	TLD7002_UART_PAR *  RxUartData=NULL;
			 	uint8 usRxUartCRC[2]={0};
			 	uint8 RxCRC_result[2]={0};
			 	uint8 RX_FlagErr=0;

				uint8 usTxUartData[50]={0};

					for(uint8 i=0;i<50;i++)
					{
						usTxUartData[i]=0;
					}


			 	if((Deviceaddress<=FRAME_SLAVE_ADDRESS_31)&&(Startadd<=0x3b))
				{
						usTxUartData[0]=0x55;
						usTxUartData[1]=0x1f&Deviceaddress;

						usTxUartData_Lenth=Get_theLenthofTxdata(Lenth,lenthofdata);
						if(usTxUartData_Lenth==0)
						{

								ret_val=Senddata_lenth_ERR;
								return  ret_val;
						}


						usTxUartData[2]=(uint8)(((Curr_MRC[0]<<6)&0xC0)|((lenthofdata[1]<<3)&0x38)|(FRAME_FUN_READ_REG&0x7));
						Curr_MRC[0] = mcld_get_next_rc_val(Curr_MRC[0]);
						if(Deviceaddress != FRAME_SLAVE_ADDRESS_BROADCAST)
						{											/*< only for messages which are not broadcast messages (would lead to two times increasing MRC) */
							Curr_MRC[Deviceaddress] = mcld_get_next_rc_val(Curr_MRC[Deviceaddress]);							/*< calculate expected Rolling Counter for answer */
						}


						 usTxUartCRC1[0]=usTxUartData[1];
						 usTxUartCRC1[1]=usTxUartData[2];
						 mcld_calculate_crc3_master_request_test(usTxUartCRC1,&CRC_result[0]);
						 usTxUartData[1]=(uint8)(((CRC_result[0]<<5)&0xE0)|(usTxUartData[1]));

						 usTxUartData[3]=Startadd;


						Reset_Frame_PAR(UartPort);
						RxUartData=GetFramePAR(UartPort);
						RxUartData->mode=READ_REG_mode;
						RxUartData->busstate=BUS_TLD7002_SYNC;
						RxUartData->rcvdatalens=(4+Lenth*2+3);
						RxUartData->Txdatalens=4;
						RxUartData->RxdataCnt=0;



						 ChangeRx_DataLength_UART1_Test(4+Lenth*2+3,RxUartData->rcvdata);
						 ClearDMAchannel1_INTFlag();
						 ClearTx_Channel1(usTxUartData,4);

						//UART_SendWait(UartPort, usTxUartData, LEN_READ_REG_WRITE);


						//delay_softTLD7002=0;
						 delay_softTLD7002=Uart_GetTicks();
						//while(((DMA->INT&0x01)==0)&&(delay_softTLD7002<=TLD7002DelayTime_MS))
						 while(((DMA->INT&0x40)==0)&&((Uart_GetTicks() - delay_softTLD7002) < OS_MS_TO_TICKS(TLD7002_DelayMsSystem)))
						{
							//delay_softTLD7002++;
						}

						// if(DMA->INT==0x01)
						if((DMA->INT&0x40)==0x40)
						{

							 ClearDMAchannel1_INTFlag();
							 ChangeRx_DataLength_UART1_Test(1,RxUartData->rcvdata);
							 RxUartData->Txdatalens=4;
							for(uint8 i=0;i<(RxUartData->Txdatalens);i++)
							{
								if(RxUartData->rcvdata[i]!=usTxUartData[i])
								{
									RX_FlagErr=1;
									break;
								}
							}
							if(RX_FlagErr==0)
							{
								 RxCRC_result[0]=TLD7002_calculate_crc8_leadbyte_Test(&RxUartData->rcvdata[4],(Lenth*2),RxUartData->rcvdata[3]);
								 if(RxCRC_result[0]!=(RxUartData->rcvdata[3+Lenth*2+1]))
								 {

									 ret_val=Rec_CRC8_ERR;//CRC8 ERR
									 Reset_Frame_PAR(UartPort);
									 return ret_val;
								 }

								 usRxUartCRC[0]=RxUartData->rcvdata[3+Lenth*2+2];
								 usRxUartCRC[1]=RxUartData->rcvdata[3+Lenth*2+3]&0x1f;//4+Lenth*2+3
								 mcld_calculate_crc3_slave_request_test(usRxUartCRC,&RxCRC_result[1]);
								if(RxCRC_result[1]==((RxUartData->rcvdata[3+Lenth*2+3]&0xE0)>>5))// CRC3 ((RxUartData->rcvdata[7]&0xE0)>>5)
								{
									for(uint8 i=0;i<Lenth;i++)
									{
										dc_val[i]=(
												  ((((uint16)RxUartData->rcvdata[i*2+4])<<8)&0xff00)|
												  ((((uint16)RxUartData->rcvdata[i*2+5]))&0x00ff)
												  );
									}
									*devicemode=RxUartData->rcvdata[3+Lenth*2+3];
									ret_val=Rec_Success;
									Reset_Frame_PAR(UartPort);
									return ret_val;
								}
								else
								{
									ret_val=Rec_CRC3_ERR;//CRC3 ERR
									Reset_Frame_PAR(UartPort);
									return ret_val;
								}
						   }
							else
							{
								Reset_Frame_PAR(UartPort);
								ret_val=OverTime_ERR;
								return ret_val;
							}
						}
						else if(DMA->INT==0x0)
						{
							//ChangeRx_DataLength_UART0_Test(1);
							ChangeRx_DataLength_UART1_Test(1,RxUartData->rcvdata);
							Reset_Frame_PAR(UartPort);
							ret_val=OverTime_ERR;
							return ret_val;
						}
						else
						{
							//ChangeRx_DataLength_UART0_Test(1);
							ChangeRx_DataLength_UART1_Test(1,RxUartData->rcvdata);
							Reset_Frame_PAR(UartPort);
							ret_val=OverTime_ERR;
						    return ret_val;
						}

				}
			 	else
			 	{
			 		ret_val=ADDR_ERR;
			 		return  ret_val;

			 	}

			 	return ret_val;


}

#endif



