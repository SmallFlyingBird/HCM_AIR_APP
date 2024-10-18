/*
 * Tps92662A.h
 *
 *  Created on: 2024��1��10��
 *      Author: mihuiliang
 */

#ifndef BASE_CDD_DRIVER_MATRIXCHIP_TPS92662A_H_
#define BASE_CDD_DRIVER_MATRIXCHIP_TPS92662A_H_



/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "MatrixChip_Interface.h"
/****************************************************************
 *                                                              *
 *                      Macro Define                            *
 *                                                              *
 ****************************************************************/
#define  CHANNEL1_MLC       ((uint8_t)0)
#define  CHANNEL2_MLC       ((uint8_t)1)
#define  CHANNEL3_MLC       ((uint8_t)2)
#define  CHANNEL4_MLC       ((uint8_t)3)
#define  CHANNEL5_MLC       ((uint8_t)4)
#define  CHANNEL6_MLC       ((uint8_t)5)

#define  CHANNEL7_MLC       ((uint8_t)6)
#define  CHANNEL8_MLC       ((uint8_t)7)
#define  CHANNEL9_MLC       ((uint8_t)8)
#define  CHANNEL10_MLC       ((uint8_t)9)
#define  CHANNEL11_MLC       ((uint8_t)10)
#define  CHANNEL12_MLC       ((uint8_t)11)

/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/
typedef union{
	struct{
		uint8 bit0:1;
		uint8 bit1:1;
		uint8 bit2:1;
		uint8 bit3:1;
		uint8 bit4:1;
		uint8 bit5:1;
		uint8 bit6:1;
		uint8 bit7:1;
	}bit;
	uint8_t addr;
}LEDDriverAddr_t;

typedef struct
{
	uint8	mode;
	LEDDriverAddr_t	addr;
}LEDDriver_Type_t;


typedef enum{
/*LED PWM Phase-shift and width registers*/
	LEDDriver_MPHASE01L			=	0x00U,
	LEDDriver_MPHASE02L			= 	0x01U,
	LEDDriver_MPHASE03L			= 	0X02U,
	LEDDriver_MPHASE03_01H		=	0x03U,	
	LEDDriver_MPHASE04L			=	0x04U,
	LEDDriver_MPHASE05L			=	0x05U,
	LEDDriver_MPHASE06L			=	0x06U,
	LEDDriver_MPHASE06_04H		=	0x07U,
	LEDDriver_MPHASE07L			=	0x08U,
	LEDDriver_MPHASE08L			=	0x09U,
	LEDDriver_MPHASE09L			=	0x0AU,
	LEDDriver_MPHASE09_07H		=	0x0BU,
	LEDDriver_MPHASE10L			=	0x0CU,
	LEDDriver_MPHASE11L			=	0x0DU,
	LEDDriver_MPHASE12L			= 	0x0EU,
	LEDDriver_MPHASE12_10H		=	0x0FU,
	LEDDriver_MWIDTH01L			=	0x10U,
	LEDDriver_MWIDTH02L			=	0x11U,
	LEDDriver_MWIDTH03L			=	0x12U,
	LEDDriver_MWIDTH03_01H		=	0x13U,
	LEDDriver_MWIDTH04L			=	0x14U,
	LEDDriver_MWIDTH05L			=	0x15U,
	LEDDriver_MWIDTH06L			=	0x16U,
	LEDDriver_MWIDTH06_04H		=	0x17U,
	LEDDriver_MWIDTH07L			=	0x18U,
	LEDDriver_MWIDTH08L			=	0x19U,
	LEDDriver_MWIDTH09L 		=	0x1AU,
	LEDDriver_MWIDTH09_07H		=	0x1BU,
	LEDDriver_MWIDTH10L			=	0x1CU,
	LEDDriver_MWIDTH11L			=	0x1DU,
	LEDDriver_MWIDTH12L			=	0x1EU,
	LEDDriver_MWIDTH12_10H		=	0x1FU,
	LEDDriver_LPHASE01H			=	0x20U,
	LEDDriver_LPHASE02H			=	0x21U,
	LEDDriver_LPHASE03H			=	0x22U,
	LEDDriver_LPHASE04H			=	0x23U,
	LEDDriver_LPHASE05H 		=	0x24U,
	LEDDriver_LPHASE06H			=	0x25U,
	LEDDriver_LPHASE07H			=	0x26U,
	LEDDriver_LPHASE08H			=	0x27U,
	LEDDriver_LPHASE09H			=	0x28U,
	LEDDriver_LPHASE10H			=	0x29U,
	LEDDriver_LPHASE11H			=	0x2AU,
	LEDDriver_LPHASE12H			=	0x2BU,
	LEDDriver_LPHASE03_01L		=	0x2CU,
	LEDDriver_LPHASE06_04L		=	0x2DU,
	LEDDriver_LPHASE09_07L		=	0x2EU,
	LEDDriver_LPHASE12_10L		=	0x2FU,
	LEDDriver_LWIDTH01H			=	0x30U,
	LEDDriver_LWIDTH02H			=	0x31U,
	LEDDriver_LWIDTH03H			=	0x32U,
	LEDDriver_LWIDTH04H			=	0x33U,
	LEDDriver_LWIDTH05H			=	0x34U,
	LEDDriver_LWIDTH06H			=	0x35U,
	LEDDriver_LWIDTH07H			=	0x36U,
	LEDDriver_LWIDTH08H			=	0x37U,
	LEDDriver_LWIDTH09H			=	0x38U,
	LEDDriver_LWIDTH10H			=	0x39U,
	LEDDriver_LWIDTH11H			=	0x3AU,
	LEDDriver_LWIDTH12H			=	0x3BU,
	LEDDriver_LWIDTH03_01L		=	0x3CU,
	LEDDriver_LWIDTH06_04L		=	0x3DU,
	LEDDriver_LWIDTH09_07L		=	0x3EU,
	LEDDriver_LWIDTH12_10L		=	0x3FU,
	LEDDriver_DPHASE01L			=	0x40U,
	LEDDriver_DPHASE01H			=	0x41U,
	LEDDriver_DWIDTH01L			=	0x42U,
	LEDDriver_DWIDTH01H			=	0x43U,
	LEDDriver_DPHASE02L			=	0x44U,
	LEDDriver_DPHASE02H			=	0x45U,
	LEDDriver_DWIDTH02L			=	0x46U,
	LEDDriver_DWIDTH02H			=	0x47U,
	LEDDriver_DPHASE03L			=	0x48U,
	LEDDriver_DPHASE03H			=	0x49U,
	LEDDriver_DWIDTH03L			=	0x4AU,
	LEDDriver_DWIDTH03H			=	0x4BU,
	LEDDriver_DPHASE04L			=	0x4CU,
	LEDDriver_DPHASE04H			=	0x4DU,
	LEDDriver_DWIDTH04L			=	0x4EU,
	LEDDriver_DWIDTH04H			=	0x4FU,
	LEDDriver_DPHASE05L			=	0x50U,
	LEDDriver_DPHASE05H			=	0x51U,
	LEDDriver_DWIDTH05L			=	0x52U,
	LEDDriver_DWIDTH05H			=	0x53U,
	LEDDriver_DPHASE06L			=	0x54U,
	LEDDriver_DPHASE06H			=	0x55U,
	LEDDriver_DWIDTH06L			=	0x56U,
	LEDDriver_DWIDTH06H			=	0x57U,
	LEDDriver_DPHASE07L			=	0x58U,
	LEDDriver_DPHASE07H			=	0x59U,
	LEDDriver_DWIDTH07L			=	0x5AU,
	LEDDriver_DWIDTH07H			=	0x5BU,
	LEDDriver_DPHASE08L			=	0x5CU,
	LEDDriver_DPHASE08H			=	0x5DU,
	LEDDriver_DWIDTH08L			=	0x5EU,
	LEDDriver_DWIDTH08H			=	0x5FU,
	LEDDriver_DPHASE09L			=	0x60U,
	LEDDriver_DPHASE09H			=	0x61U,
	LEDDriver_DWIDTH09L			=	0x62U,
	LEDDriver_DWIDTH09H			=	0x63U,
	LEDDriver_DPHASE10L			=	0x64U,
	LEDDriver_DPHASE10H			=	0x65U,
	LEDDriver_DWIDTH10L			=	0x66U,
	LEDDriver_DWIDTH10H			=	0x67U,
	LEDDriver_DPHASE11L			=	0x68U,
	LEDDriver_DPHASE11H			=	0x69U,
	LEDDriver_DWIDTH11L			=	0x6AU,
	LEDDriver_DWIDTH11H			=	0x6BU,
	LEDDriver_DPHASE12L			=	0x6CU,
	LEDDriver_DPHASE12H			=	0x6DU,
	LEDDriver_DWIDTH12L			=	0x6EU,
	LEDDriver_DWIDTH12H			=	0x6FU,
	/*slew rate registers*/
	LEDDriver_SLEWRATE			=	0x70U,
	/*Over Voltage Limit Registers*/
	LEDDriver_OVLMT				=	0x71U,
	/*Parallel LED String Registers*/
	LEDDriver_PARLED			=	0x72U,
	/*Default pulse Width Registers*/
	LEDDriver_DEFWIDTH02_01		=	0x73U,
	LEDDriver_DEFWIDTH04_03		=	0x74U,
	LEDDriver_DEFWIDTH06_05		=	0x75U,
	LEDDriver_DEFWIDTH08_07		=	0x76U,
	LEDDriver_DEFWIDTH10_09		=	0x77U,
	LEDDriver_DEFWIDTH12_11		=	0x78U,
	/*System Configuration Register*/
	LEDDriver_SYSCFG			=	0x80U,
	/*Communication watchdog timer tap point register*/
	LEDDriver_CMWTAP			=	0x81U,
	/*PWM Tick Period Register*/
	LEDDriver_PWMTICK			=	0x82U,
	/*ADC ID Register*/
	LEDDriver_ADCID				=	0x83U,
	/*SOFTSYNC Register*/
	LEDDriver_SOFTSYNC			=	0x84U,
	/*XTAL DRIVE STRENGTH Register*/
	LEDDriver_XTALDS			=	0x85U,
	/*I2C Tick Period Register*/
	LEDDriver_I2CTICK			=	0x90U,
	/*I2C Slave Address Register*/
	LEDDriver_I2CSLA			=	0x91U,
	/*I2C Read Length Register*/
	LEDDriver_I2CRLEN			=	0x92U,
	/*I2C Byte Address Register*/
	LEDDriver_I2CADR			=	0x93U,
	/*I2C Master Control Register*/
	LEDDriver_I2CCTRL			=	0x94U,
	/*I2C Data Register*/
	LEDDriver_I2CDAT			=	0x95U,
	/*I2C Status Register*/
	LEDDriver_I2CSTAT			=	0x96U,
	/*I2C Bus Monitor Register(Read-only)*/
	LEDDriver_I2CBMON			=	0x97U,
	/*ADC Registers(Read-only)*/
	LEDDriver_ADC1				=	0xA0U,
	LEDDriver_ADC2				=	0xA1U,
	/*DSTR Register(Read-only)*/
	LEDDriver_DSTR				=	0xA2U,
	/*Fault and CRC Error Count Registers*/
	LEDDriver_FAULTL			=	0xB0U,
	LEDDriver_FAULTH			=	0xB1U,
	LEDDriver_CERRCNT			=	0xB2U,
	/*IC identification Register(Read-only)*/
	LEDDriver_ICID				=	0xFFU,	
}LEDDriver_register_t;
/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
Std_ReturnType Tps92662ADevRegister(void);
#endif /* BASE_CDD_DRIVER_MATRIXCHIP_TPS92662A_H_ */
