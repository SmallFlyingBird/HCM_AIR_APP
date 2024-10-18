/*
 * Drv8889.h
 *
 *  Created on: 2024��1��23��
 *      Author: mihuiliang
 */

#ifndef CDD_DRIVER_MOTORDRV_DRV8889_H_
#define CDD_DRIVER_MOTORDRV_DRV8889_H_


/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                      Macro Define                            *
 *                                                              *
 ****************************************************************/
#define PIN_LOW   0
#define PIN_HIGH  1

#define FAULT_Status_OL_MASK  		 (1<<0)
#define FAULT_Status_TF_MASK  		 (1<<1)
#define FAULT_Status_STL_MASK  		 (1<<2)
#define FAULT_Status_OCP_MASK  		 (1<<3)
#define FAULT_Status_UVLO_MASK  	 (1<<5)
#define FAULT_Status_SPI_ERROR_MASK  (1<<6)

#define FAULT_Status2_OTS_MASK		 (1<<5)
#define FAULT_Status2_OTW_MASK		 (1<<6)
#define FAULT_Status2_UTW_MASK		 (1<<7)


#define DRV8889_FAULT_STATUS	0x00
#define DRV8889_DIAG_STATUS_1 	0x01
#define DRV8889_DIAG_STATUS_2 	0x02

#define DRV8889_CTRL1	0x03
#define DRV8889_CTRL2	0x04
#define DRV8889_CTRL3	0x05
#define DRV8889_CTRL4	0x06
#define DRV8889_CTRL5	0x07
#define DRV8889_CTRL6	0x08
#define DRV8889_CTRL7	0x09
#define DRV8889_CTRL8	0x0A

#define DRV8889_SPIERROR_LIMIT 5    /*Spi错误上限次数*/

/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/

typedef struct
{
	union
	{
		uint8_t SR0_Value;
		struct
		{
			uint8_t SR0_OL:1;
			uint8_t	SR0_TF:1;
			uint8_t	SR0_STL:1;
			uint8_t	SR0_OCP:1;
			uint8_t	SR0_CPUV:1;
			uint8_t	SR0_UVLO:1;
			uint8_t	SR0_SPI_ERROR:1;
			uint8_t	SR0_Fault:1;
		}b0;
	}SR0;

	union
	{
		uint8_t SR1_Value;

		struct
		{
			uint8_t SR1_OCP_HS1_A:1;
			uint8_t	SR1_OCP_LS1_A:1;
			uint8_t	SR1_OCP_HS2_A:1;
			uint8_t	SR1_OCP_LS2_A:1;
			uint8_t	SR1_OCP_HS1_B:1;
			uint8_t	SR1_OCP_LS1_B:1;
			uint8_t	SR1_OCP_HS2_B:1;
			uint8_t	SR1_OCP_LS2_B:1;
		}b1;
	}SR1;

	union
	{
		uint8_t SR2_Value;
		struct
		{
			uint8_t SR2_OL_A:1;
			uint8_t	SR2_OL_B:1;
			uint8_t	SR2_RSVD:1;
			uint8_t	SR2_STALL:1;
			uint8_t	SR2_STL_LRN_OK:1;
			uint8_t	SR2_OTS:1;
			uint8_t	SR2_OTW:1;
			uint8_t	SR2_UTW:1;
		}b2;
	}SR2;
}SR_REG;


typedef struct
{
	union
	{
		uint8_t CR1_Value;
		struct
		{
			uint8_t CR1_SLEW_RATE:2;
			uint8_t	CR1_RSVD:2;
			uint8_t	CR1_TRQ_DAC:4;
		}b1;
	}CR1;

	union
	{
		uint8_t CR2_Value;
		struct
		{
			uint8_t CR2_DECAY:3;
			uint8_t	CR2_TOFF:2;
			uint8_t	CR2_RSVD:2;
			uint8_t	CR2_DIS_OUT:1;
		}b2;
	}CR2;

	union
	{
		uint8_t CR3_Value;
		struct
		{
			uint8_t CR3_MICROSTEP_MODE:4;
			uint8_t	CR3_SPI_STEP:1;
			uint8_t	CR3_SPI_DIR:1;
			uint8_t	CR3_STEP:1;
			uint8_t	CR3_DIR:1;
		}b3;
	}CR3;

	union
	{
		uint8_t CR4_Value;
		struct
		{
			uint8_t CR4_TW_REP:1;
			uint8_t	CR4_OTSD_MODE:1;
			uint8_t	CR4_OCP_MODE:1;
			uint8_t	CR4_EN_OL:1;
			uint8_t	CR4_LOCK:3;
			uint8_t	CR4_CLR_FLT:1;
		}b4;
	}CR4;

	union
	{
		uint8_t CR5_Value;
		struct
		{

			uint8_t CR5_RSVD2:3;
			uint8_t	CR5_STL_REP:1;
			uint8_t	CR5_EN_STL:1;
			uint8_t	CR5_STL_LRN:1;
			uint8_t	CR5_RSVD1:2;
		}b5;
	}CR5;

	union
	{
		uint8_t CR6_Value;
		struct
		{
			uint8_t CR6_STALL_TH:8;
		}b6;
	}CR6;

	union
	{
		uint8_t CR7_Value;
		struct
		{
			uint8_t CR7_TRQ_COUNT:8;
		}b7;
	}CR7;

	union
	{
		uint8_t CR8_Value;
		struct
		{
			uint8_t CR8_REV_ID:4;
			uint8_t	CR8_RSVD:4;

		}b8;
	}CR8;
}CR_REG;


typedef struct DRV8889DevManager{
	uint8_t 	  	spi_error_cnt;
	uint8_t 		OutputDisableFlag;
	SR_REG      	srreg;
	CR_REG			crreg;
}S_DRV8889DevManager;
/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
Std_ReturnType CddDriver_Drv8889Init(void);

#endif /* CDD_DRIVER_MOTORDRV_DRV8889_H_ */
