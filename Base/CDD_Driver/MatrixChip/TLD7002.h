
#ifndef TLD7002_H_
#define TLD7002_H_
#include "Platform_Types.h"

/***********************************Define**********************************************************************************************/
//#define false  0
//#define true   1

/** FRAME_CRC_ADDRESS_t masks */
#define CRC_ADDRESS_Address_MSK						0x1F		/*!< [0..4] Address */
#define CRC_ADDRESS_CRC_MSK							0xE0		/*!< [5..7] CRC */

/** FRAME_MRC_DLC_FUN masks */
#define MRC_DLC_FUN_FUN_MSK							0x07		/*!< [0..2] Function */
#define MRC_DLC_FUN_DLC_MSK							0x38		/*!< [3..5] Data Length Code */
#define MRC_DLC_FUN_MRC_WRN_MSK						0xC0		/*!< [6..7] Rolling Counter,  master needs to increment in every data transmission*/

/** FRAME_OUTPUT_STATUS_BYTE_OUT masks */
#define OUTPUT_STATUS_BYTE_OUT_OUT_STAT_MSK			(1 << 0U)	/*!< [0] Output state flag. 0: power output channel is in OFF state; 1: power output channel is in ON state */
#define OUTPUT_STATUS_BYTE_OUT_VFWD_WRN_MSK			(1 << 1U)	/*!< [1] Forward voltage warning flag. 0: no forward voltage warning detected; 1: there was at least one forward voltage warning condition detected */
#define OUTPUT_STATUS_BYTE_OUT_CUR_WRN_MSK			(1 << 2U)	/*!< [2] Output current warning flag. 0: no output current warning detected; 1: there was at least one output current warning condition detected */
#define OUTPUT_STATUS_BYTE_OUT_DC_WRN_MSK			(1 << 3U)	/*!< [3] Duty cycle warning flag. 0: no duty cycle warning detected; 1: there was at least one duty cycle warning condition detected */
#define OUTPUT_STATUS_BYTE_OUT_OUT_SHORT_WRN_MSK	(1 << 4U)	/*!< [4] Short between adjacent output warning flag. 0: no short between adjacent output warning detected; 1: there was at least one short between an adjacent output warning detected */
#define OUTPUT_STATUS_BYTE_OUT_OVLD_MSK				(1 << 5U)	/*!< [5] OVLD flag. 0: no OVLD condition detected; 1: there was at least one OVLD condition since the last read out */
#define OUTPUT_STATUS_BYTE_OUT_SLS_MSK				(1 << 6U)	/*!< [6] Single LED Short (SLS) flag. 0: no SLS condition detected; 1: there was at least one single LED short detected */
#define OUTPUT_STATUS_BYTE_OUT_OL_MSK				(1 << 7U)	/*!< [7] Open load flag. 0: no open load condition detected; 1: there was at least one open load condition detected */

/** FRAME_DC_UPDATE_14BITDCVAL masks */
#define DC_UPDATE_14BITDCVAL_DUTY_CYCLE_MSK			0x3FFF		/*!< [0..14] Duty Cycle */
#define DC_UPDATE_14BITDCVAL_RESERVED_MSK			0xC000		/*!< [15..16] RESERVED */

/** FRAME_OUTPUT_STATUS_BYTE masks */
#define OUTPUT_STATUS_BYTE_FAULT_MSK						(1 << 0U)	/*!< [0] Internal fault flag. 0: no internal fault detected; 1: internal fault condition detected */
#define OUTPUT_STATUS_BYTE_OVLD_MSK							(1 << 1U)	/*!< [1] Over load flag. 0: no overload condition detected on OUT0 to OUT15; 1: there was at least one overload condition detected */
#define OUTPUT_STATUS_BYTE_VFWD_WRN_MSK					(1 << 2U)	/*!< [2] Forward voltage warning flag. 0: no forward voltage warning for OUT0 to OUT15 detected; 1: there was at least one forward voltage warning condition */
#define OUTPUT_STATUS_BYTE_CUR_WRN_MSK					(1 << 3U)	/*!< [3] Output current warning flag. 0: no output current warning for OUT0 to OUT15 detected; 1: there was at least one output current warning condition */
#define OUTPUT_STATUS_BYTE_DC_WRN_MSK						(1 << 4U)	/*!< [4] Duty cycle warning flag. 0: no duty cycle warning for OUT0 to OUT15 detected; 1: there was at least one duty cycle warning condition */
#define OUTPUT_STATUS_BYTE_GPINn_WRN_MSK				(1 << 5U)	/*!< [5] GPINn warning flag. 0: GPIN0 and GPIN1 are not in a fault condition; 1: there was at least one GPINn fault condition or GPINn adjacent short condition */
#define OUTPUT_STATUS_BYTE_OUT_SHRT_WRN_MSK			(1 << 6U)	/*!< [6] short between adjacent output warning. 0: no short between adjacent output warning detected; 1: there was at least one short between an adjacent output warning detected */
#define OUTPUT_STATUS_BYTE_VLED_VS_UV_MSK				(1 << 7U)	/*!< [7] VLED/VS under voltage flag. 0: if (V_LED AND V_S) is above V_DEN_threshold ; 1: there was at least one under voltage condition event detected */

/** FRAME_HWCR_RESET_OUT masks */
#define HWCR_RESET_OUT_BYTE_OUT0_MSK				(1 << 0U)	/*!< [0] RESET OUT0 */
#define HWCR_RESET_OUT_BYTE_OUT1_MSK				(1 << 1U)	/*!< [1] RESET OUT1 */
#define HWCR_RESET_OUT_BYTE_OUT2_MSK				(1 << 2U)	/*!< [2] RESET OUT2 */
#define HWCR_RESET_OUT_BYTE_OUT3_MSK				(1 << 3U)	/*!< [3] RESET OUT3 */
#define HWCR_RESET_OUT_BYTE_OUT4_MSK				(1 << 4U)	/*!< [4] RESET OUT4 */
#define HWCR_RESET_OUT_BYTE_OUT5_MSK				(1 << 5U)	/*!< [5] RESET OUT5 */
#define HWCR_RESET_OUT_BYTE_OUT6_MSK				(1 << 6U)	/*!< [6] RESET OUT6 */
#define HWCR_RESET_OUT_BYTE_OUT7_MSK				(1 << 7U)	/*!< [7] RESET OUT7 */
#define HWCR_RESET_OUT_BYTE_OUT8_MSK				(1 << 8U)	/*!< [8] RESET OUT8 */
#define HWCR_RESET_OUT_BYTE_OUT9_MSK				(1 << 9U)	/*!< [9] RESET OUT9 */
#define HWCR_RESET_OUT_BYTE_OUT10_MSK				(1 << 10U)	/*!< [10] RESET OUT10 */
#define HWCR_RESET_OUT_BYTE_OUT11_MSK				(1 << 11U)	/*!< [11] RESET OUT11 */
#define HWCR_RESET_OUT_BYTE_OUT12_MSK				(1 << 12U)	/*!< [12] RESET OUT12 */
#define HWCR_RESET_OUT_BYTE_OUT13_MSK				(1 << 13U)	/*!< [13] RESET OUT13 */
#define HWCR_RESET_OUT_BYTE_OUT14_MSK				(1 << 14U)	/*!< [14] RESET OUT14 */
#define HWCR_RESET_OUT_BYTE_OUT15_MSK				(1 << 16U)	/*!< [15] RESET OUT15 */

/** FRAME_HWCR_RESET_STATUS masks */
#define HWCR_RESET_STATUS_BIT0_MSK					(1 << 0U)	/*!< [0] BIT0. 0: LOW; 1: HIGH */
#define HWCR_RESET_STATUS_BIT1_MSK					(1 << 1U)	/*!< [1] BIT1. 0: LOW; 1: HIGH */
#define HWCR_RESET_STATUS_BIT2_MSK					(1 << 2U)	/*!< [2] BIT2. 0: LOW; 1: HIGH */
#define HWCR_RESET_STATUS_BIT3_MSK					(1 << 3U)	/*!< [3] BIT3. 0: LOW; 1: HIGH */
#define HWCR_RESET_STATUS_BIT4_MSK					(1 << 4U)	/*!< [4] BIT4. 0: LOW; 1: HIGH */
#define HWCR_RESET_STATUS_BIT5_MSK					(1 << 5U)	/*!< [5] BIT5. 0: LOW; 1: HIGH */
#define HWCR_RESET_STATUS_BIT6_MSK					(1 << 6U)	/*!< [6] BIT6. 0: LOW; 1: HIGH */
#define HWCR_RESET_STATUS_BIT7_MSK					(1 << 7U)	/*!< [7] BIT7. 0: LOW; 1: HIGH */

/** FRAME_POWER_MODE_CHANGE masks */
#define POWER_MODE_CHANGE_POWER_MODE_MSK			0x07		/*!< [0..2] Power mode  */
#define POWER_MODE_CHANGE_RESERVED_MSK				0xF8		/*!< [3..7] Reserved */

/** FRAME_ACK_BYTE masks */
#define ACK_BYTE_TER_MSK							0x01		/*!< [0] Transmission Error. 0 current frame has been successfully received; 1: the received frame resulted in a CRC8 error */
#define ACK_BYTE_RC_MSK								0x06		/*!< [1..2] rolling counter, incremented at every slave response */
#define ACK_BYTE_MODE_MSK							0x81		/*!< [3..4] mode */
#define ACK_BYTE_CRC_MSK							0x0E		/*!< [5..7] CRC3 */

/* DC_SYNC - Broadcast duty cycle */
#define POS_BRDC_DC_SYNC_SYNC						   0
#define POS_BRDC_DC_SYNC_CRC_REQ_S_ADD				   1
#define POS_BRDC_DC_SYNC_DLC_FUN					   2
#define LEN_BRDC_DC_SYNC_WRITE		 				   3

/* DC_UPDATE_8BIT - Update duty cycle and output status */
#define POS_DC_UPDATE_8BIT_SYNC						   0
#define POS_DC_UPDATE_8BIT_CRC_REQ_S_ADD			   1
#define POS_DC_UPDATE_8BIT_MRC_DLC_FUN				   2
#define POS_DC_UPDATE_8BIT_DCOUT0					   3
#define POS_DC_UPDATE_8BIT_DCOUT1					   4
#define POS_DC_UPDATE_8BIT_DCOUT2					   5
#define POS_DC_UPDATE_8BIT_DCOUT3					   6
#define POS_DC_UPDATE_8BIT_DCOUT4					   7
#define POS_DC_UPDATE_8BIT_DCOUT5					   8
#define POS_DC_UPDATE_8BIT_DCOUT6					   9
#define POS_DC_UPDATE_8BIT_DCOUT7					  10
#define POS_DC_UPDATE_8BIT_DCOUT8					  11
#define POS_DC_UPDATE_8BIT_DCOUT9					  12
#define POS_DC_UPDATE_8BIT_DCOUT10					  13
#define POS_DC_UPDATE_8BIT_DCOUT11					  14
#define POS_DC_UPDATE_8BIT_DCOUT12					  15
#define POS_DC_UPDATE_8BIT_DCOUT13					  16
#define POS_DC_UPDATE_8BIT_DCOUT14					  17
#define POS_DC_UPDATE_8BIT_DCOUT15					  18
#define POS_DC_UPDATE_8BIT_SAFETY_BYTE				  19
#define POS_DC_UPDATE_8BIT_OST						   0
#define POS_DC_UPDATE_8BIT_ACK						   1

#define LEN_DC_UPDATE_8BIT_WRITE					  20
#define LEN_DC_UPDATE_8BIT_READ						   2

/* DC_UPDATE_14BIT - Update duty cycle and output status */
#define POS_DC_UPDATE_14BIT_SYNC					   0
#define POS_DC_UPDATE_14BIT_CRC_REQ_S_ADD			   1
#define POS_DC_UPDATE_14BIT_MRC_DLC_FUN				   2
#define POS_DC_UPDATE_14BIT_DCOUT0_HB				   3
#define POS_DC_UPDATE_14BIT_DCOUT0_LB				   4
#define POS_DC_UPDATE_14BIT_DCOUT1_HB				   5
#define POS_DC_UPDATE_14BIT_DCOUT1_LB				   6
#define POS_DC_UPDATE_14BIT_DCOUT2_HB				   7
#define POS_DC_UPDATE_14BIT_DCOUT2_LB				   8
#define POS_DC_UPDATE_14BIT_DCOUT3_HB				   9
#define POS_DC_UPDATE_14BIT_DCOUT3_LB				  10
#define POS_DC_UPDATE_14BIT_DCOUT4_HB				  11
#define POS_DC_UPDATE_14BIT_DCOUT4_LB				  12
#define POS_DC_UPDATE_14BIT_DCOUT5_HB				  13
#define POS_DC_UPDATE_14BIT_DCOUT5_LB				  14
#define POS_DC_UPDATE_14BIT_DCOUT6_HB				  15
#define POS_DC_UPDATE_14BIT_DCOUT6_LB				  16
#define POS_DC_UPDATE_14BIT_DCOUT7_HB				  17
#define POS_DC_UPDATE_14BIT_DCOUT7_LB				  18
#define POS_DC_UPDATE_14BIT_DCOUT8_HB				  19
#define POS_DC_UPDATE_14BIT_DCOUT8_LB				  20
#define POS_DC_UPDATE_14BIT_DCOUT9_HB				  21
#define POS_DC_UPDATE_14BIT_DCOUT9_LB				  22
#define POS_DC_UPDATE_14BIT_DCOUT10_HB				  23
#define POS_DC_UPDATE_14BIT_DCOUT10_LB				  24
#define POS_DC_UPDATE_14BIT_DCOUT11_HB				  25
#define POS_DC_UPDATE_14BIT_DCOUT11_LB				  26
#define POS_DC_UPDATE_14BIT_DCOUT12_HB				  27
#define POS_DC_UPDATE_14BIT_DCOUT12_LB				  28
#define POS_DC_UPDATE_14BIT_DCOUT13_HB				  29
#define POS_DC_UPDATE_14BIT_DCOUT13_LB				  30
#define POS_DC_UPDATE_14BIT_DCOUT14_HB				  31
#define POS_DC_UPDATE_14BIT_DCOUT14_LB				  32
#define POS_DC_UPDATE_14BIT_DCOUT15_HB				  33
#define POS_DC_UPDATE_14BIT_DCOUT15_LB				  34
#define POS_DC_UPDATE_14BIT_SAFETY_BYTE				  35
#define POS_DC_UPDATE_14BIT_OST						   0
#define POS_DC_UPDATE_14BIT_ACK						   1

#define LEN_DC_UPDATE_14BIT_WRITE					  36
#define LEN_DC_UPDATE_14BIT_READ					   2

/* PM_CHANGE - Power mode change */
#define POS_PM_CHANGE_SYNC							   0
#define POS_PM_CHANGE_CRC_REQ_S_ADD					   1
#define POS_PM_CHANGE_MRC_DLC_FUN					   2
#define POS_PM_CHANGE_POWER_MODE					   3
#define POS_PM_CHANGE_RES							   4
#define POS_PM_CHANGE_SAFETY_BYTE					   5
#define POS_PM_CHANGE_OST							   0
#define POS_PM_CHANGE_ACK							   1

#define LEN_PM_CHANGE_WRITE							   6
#define LEN_PM_CHANGE_READ							   2

/* READ_OST - Read all output status */
#define POS_READ_OST_SYNC							   0
#define POS_READ_OST_CRC_REQ_S_ADD					   1
#define POS_READ_OST_MRC_DLC_FUN					   2
#define POS_READ_OST_OSB_OUT0						   0
#define POS_READ_OST_OSB_OUT1						   1
#define POS_READ_OST_OSB_OUT2						   2
#define POS_READ_OST_OSB_OUT3						   3
#define POS_READ_OST_OSB_OUT4						   4
#define POS_READ_OST_OSB_OUT5						   5
#define POS_READ_OST_OSB_OUT6						   6
#define POS_READ_OST_OSB_OUT7						   7
#define POS_READ_OST_OSB_OUT8						   8
#define POS_READ_OST_OSB_OUT9						   9
#define POS_READ_OST_OSB_OUT10						  10
#define POS_READ_OST_OSB_OUT11						  11
#define POS_READ_OST_OSB_OUT12						  12
#define POS_READ_OST_OSB_OUT13						  13
#define POS_READ_OST_OSB_OUT14						  14
#define POS_READ_OST_OSB_OUT15						  15
#define POS_READ_OST_SAFETY_BYTE					  16
#define POS_READ_OST_OST							  17
#define POS_READ_OST_ACK							  18

#define LEN_READ_OST_WRITE							   3
#define LEN_READ_OST_READ							  19

/* HWCR - Hardware control */
#define POS_HWCR_SYNC								   0
#define POS_HWCR_CRC_REQ_S_ADD						   1
#define POS_HWCR_MRC_DLC_FUN						   2
#define POS_HWCR_RESET_OL_HB						   3
#define POS_HWCR_RESET_OL_LB						   4
#define POS_HWCR_RESET_OP_HB						   5
#define POS_HWCR_RESET_OP_LB						   6
#define POS_HWCR_RESET_SLS_HB						   7
#define POS_HWCR_RESET_SLS_LB						   8
#define POS_HWCR_RESERVED							   9
#define POS_HWCR_RESET_STATUS						  10
#define POS_HWCR_SAFETY_BYTE						  11
#define POS_HWCR_OST								   0
#define POS_HWCR_ACK								   1

#define LEN_HWCR_WRITE								  12
#define LEN_HWCR_READ								   2

/* WRITE_REG - Write register content */
#define POS_WRITE_REG_SYNC							   0
#define POS_WRITE_REG_CRC_REQ_S_ADD					   1
#define POS_WRITE_REG_MRC_DLC_FUN					   2
#define POS_WRITE_REG_START_ADD						   3
#define POS_WRITE_REG_DATA0_HB						   4
#define POS_WRITE_REG_DATA0_LB						   5
#define POS_WRITE_REG_DATA1_HB						   6
#define POS_WRITE_REG_DATA1_LB						   7
#define POS_WRITE_REG_DATA2_HB						   8
#define POS_WRITE_REG_DATA2_LB						   9
#define POS_WRITE_REG_DATA3_HB						  10
#define POS_WRITE_REG_DATA3_LB						  11
#define POS_WRITE_REG_DATA4_HB						  12
#define POS_WRITE_REG_DATA4_LB						  13
#define POS_WRITE_REG_DATA5_HB						  14
#define POS_WRITE_REG_DATA5_LB						  15
#define POS_WRITE_REG_DATA6_HB						  16
#define POS_WRITE_REG_DATA6_LB						  17
#define POS_WRITE_REG_DATA7_HB						  18
#define POS_WRITE_REG_DATA7_LB						  19
#define POS_WRITE_REG_DATA8_HB						  20
#define POS_WRITE_REG_DATA8_LB						  21
#define POS_WRITE_REG_DATA9_HB						  22
#define POS_WRITE_REG_DATA9_LB						  23
#define POS_WRITE_REG_DATA10_HB						  24
#define POS_WRITE_REG_DATA10_LB						  25
#define POS_WRITE_REG_DATA11_HB						  26
#define POS_WRITE_REG_DATA11_LB						  27
#define POS_WRITE_REG_DATA12_HB						  28
#define POS_WRITE_REG_DATA12_LB						  29
#define POS_WRITE_REG_DATA13_HB						  30
#define POS_WRITE_REG_DATA13_LB						  31
#define POS_WRITE_REG_DATA14_HB						  32
#define POS_WRITE_REG_DATA14_LB						  33
#define POS_WRITE_REG_DATA15_HB						  34
#define POS_WRITE_REG_DATA15_LB						  35
#define POS_WRITE_REG_DATA16_HB						  36
#define POS_WRITE_REG_DATA16_LB						  37
#define POS_WRITE_REG_DATA17_HB						  38
#define POS_WRITE_REG_DATA17_LB						  39
#define POS_WRITE_REG_DATA18_HB						  40
#define POS_WRITE_REG_DATA18_LB						  41
#define POS_WRITE_REG_DATA19_HB						  42
#define POS_WRITE_REG_DATA19_LB						  43
#define POS_WRITE_REG_DATA20_HB						  44
#define POS_WRITE_REG_DATA20_LB						  45
#define POS_WRITE_REG_DATA21_HB						  46
#define POS_WRITE_REG_DATA21_LB						  47
#define POS_WRITE_REG_DATA22_HB						  48
#define POS_WRITE_REG_DATA22_LB						  49
#define POS_WRITE_REG_DATA23_HB						  50
#define POS_WRITE_REG_DATA23_LB						  51
#define POS_WRITE_REG_DATA24_HB						  52
#define POS_WRITE_REG_DATA24_LB						  53
#define POS_WRITE_REG_DATA25_HB						  54
#define POS_WRITE_REG_DATA25_LB						  55
#define POS_WRITE_REG_DATA26_HB						  56
#define POS_WRITE_REG_DATA26_LB						  57
#define POS_WRITE_REG_DATA27_HB						  58
#define POS_WRITE_REG_DATA27_LB						  59
#define POS_WRITE_REG_DATA28_HB						  60
#define POS_WRITE_REG_DATA28_LB						  61
#define POS_WRITE_REG_DATA29_HB						  62
#define POS_WRITE_REG_DATA29_LB						  63
#define POS_WRITE_REG_DATA30_HB						  64
#define POS_WRITE_REG_DATA30_LB						  65
#define POS_WRITE_REG_DATA31_HB						  66
#define POS_WRITE_REG_DATA31_LB						  67
#define POS_WRITE_REG_DLC1_SAFETY_BYTE				   6
#define POS_WRITE_REG_DLC2_SAFETY_BYTE				   8
#define POS_WRITE_REG_DLC3_SAFETY_BYTE				  12
#define POS_WRITE_REG_DLC4_SAFETY_BYTE				  20
#define POS_WRITE_REG_DLC5_SAFETY_BYTE				  28
#define POS_WRITE_REG_DLC6_SAFETY_BYTE				  36
#define POS_WRITE_REG_DLC7_SAFETY_BYTE				  68
#define POS_WRITE_REG_OST							   0
#define POS_WRITE_REG_ACK							   1

#define LEN_WRITE_REG_OVHD							   5		/*!< SYNC/CRC_REQ_S_ADD/MRC_DLC_FUN/StartADDR/SAFETY_BYTE overhead at WRITE_REG frame */
#define LEN_WRITE_REG_DLC1_WRITE					   7
#define LEN_WRITE_REG_DLC2_WRITE					   9
#define LEN_WRITE_REG_DLC3_WRITE					  13
#define LEN_WRITE_REG_DLC4_WRITE					  21
#define LEN_WRITE_REG_DLC5_WRITE					  29
#define LEN_WRITE_REG_DLC6_WRITE					  37
#define LEN_WRITE_REG_DLC7_WRITE					  69
#define LEN_WRITE_REG_READ							   2

/* READ_REG - Read register content */
#define POS_READ_REG_SYNC							   0
#define POS_READ_REG_CRC_REQ_S_ADD					   1
#define POS_READ_REG_MRC_DLC_FUN					   2
#define POS_READ_REG_START_ADD						   3
#define POS_READ_REG_DATA0_HB						   0
#define POS_READ_REG_DATA0_LB						   1
#define POS_READ_REG_DATA1_HB						   2
#define POS_READ_REG_DATA1_LB						   3
#define POS_READ_REG_DATA2_HB						   4
#define POS_READ_REG_DATA2_LB						   5
#define POS_READ_REG_DATA3_HB						   6
#define POS_READ_REG_DATA3_LB						   7
#define POS_READ_REG_DATA4_HB						   8
#define POS_READ_REG_DATA4_LB						   9
#define POS_READ_REG_DATA5_HB						  10
#define POS_READ_REG_DATA5_LB						  11
#define POS_READ_REG_DATA6_HB						  12
#define POS_READ_REG_DATA6_LB						  13
#define POS_READ_REG_DATA7_HB						  14
#define POS_READ_REG_DATA7_LB						  15
#define POS_READ_REG_DATA8_HB						  26
#define POS_READ_REG_DATA8_LB						  27
#define POS_READ_REG_DATA9_HB						  28
#define POS_READ_REG_DATA9_LB						  29
#define POS_READ_REG_DATA10_HB						  20
#define POS_READ_REG_DATA10_LB						  21
#define POS_READ_REG_DATA11_HB						  22
#define POS_READ_REG_DATA11_LB						  23
#define POS_READ_REG_DATA12_HB						  24
#define POS_READ_REG_DATA12_LB						  25
#define POS_READ_REG_DATA13_HB						  36
#define POS_READ_REG_DATA13_LB						  37
#define POS_READ_REG_DATA14_HB						  38
#define POS_READ_REG_DATA14_LB						  39
#define POS_READ_REG_DATA15_HB						  30
#define POS_READ_REG_DATA15_LB						  31
#define POS_READ_REG_DATA16_HB						  32
#define POS_READ_REG_DATA16_LB						  33
#define POS_READ_REG_DATA17_HB						  34
#define POS_READ_REG_DATA17_LB						  35
#define POS_READ_REG_DATA18_HB						  46
#define POS_READ_REG_DATA18_LB						  47
#define POS_READ_REG_DATA19_HB						  48
#define POS_READ_REG_DATA19_LB						  49
#define POS_READ_REG_DATA20_HB						  40
#define POS_READ_REG_DATA20_LB						  41
#define POS_READ_REG_DATA21_HB						  42
#define POS_READ_REG_DATA21_LB						  43
#define POS_READ_REG_DATA22_HB						  44
#define POS_READ_REG_DATA22_LB						  45
#define POS_READ_REG_DATA23_HB						  56
#define POS_READ_REG_DATA23_LB						  57
#define POS_READ_REG_DATA24_HB						  58
#define POS_READ_REG_DATA24_LB						  59
#define POS_READ_REG_DATA25_HB						  50
#define POS_READ_REG_DATA25_LB						  51
#define POS_READ_REG_DATA26_HB						  52
#define POS_READ_REG_DATA26_LB						  53
#define POS_READ_REG_DATA27_HB						  54
#define POS_READ_REG_DATA27_LB						  55
#define POS_READ_REG_DATA28_HB						  66
#define POS_READ_REG_DATA28_LB						  67
#define POS_READ_REG_DATA29_HB						  68
#define POS_READ_REG_DATA29_LB						  69
#define POS_READ_REG_DATA30_HB						  60
#define POS_READ_REG_DATA30_LB						  61
#define POS_READ_REG_DATA31_HB						  62
#define POS_READ_REG_DATA31_LB						  63
#define POS_READ_REG_DLC1_SAFETY_BYTE				   2
#define POS_READ_REG_DLC1_OST						   3
#define POS_READ_REG_DLC1_ACK						   4
#define POS_READ_REG_DLC2_SAFETY_BYTE				   4
#define POS_READ_REG_DLC2_OST						   5
#define POS_READ_REG_DLC2_ACK						   6
#define POS_READ_REG_DLC3_SAFETY_BYTE				   8
#define POS_READ_REG_DLC3_OST						   9
#define POS_READ_REG_DLC3_ACK						  10
#define POS_READ_REG_DLC4_SAFETY_BYTE				  16
#define POS_READ_REG_DLC4_OST						  17
#define POS_READ_REG_DLC4_ACK						  18
#define POS_READ_REG_DLC5_SAFETY_BYTE				  24
#define POS_READ_REG_DLC5_OST						  25
#define POS_READ_REG_DLC5_ACK						  26
#define POS_READ_REG_DLC6_SAFETY_BYTE				  32
#define POS_READ_REG_DLC6_OST						  33
#define POS_READ_REG_DLC6_ACK						  34
#define POS_READ_REG_DLC7_SAFETY_BYTE				  64
#define POS_READ_REG_DLC7_OST						  65
#define POS_READ_REG_DLC7_ACK						  66

#define LEN_READ_REG_OVHD							   3		/*!< SAFETY_BYTE/OST/ACK overhead at READ_REG frame */
#define LEN_READ_REG_WRITE							   4
#define LEN_READ_REG_DLC1_READ						   5
#define LEN_READ_REG_DLC2_READ						   7
#define LEN_READ_REG_DLC3_READ						  11
#define LEN_READ_REG_DLC4_READ						  19
#define LEN_READ_REG_DLC5_READ						  27
#define LEN_READ_REG_DLC6_READ						  35
#define LEN_READ_REG_DLC7_READ						  67

#ifndef NULL
#define NULL        ((void*)0)
#endif

//ºê¶¨Òå´®¿ÚºÅ
#define UART_0    0
#define UART_1    1
#define UART_2    2
#define   PM_CHANGE_Lenth                8
#define   DC_UPDATE_8word_Lenth          22
#define   DC_UPDATE_16word_Lenth         38
#define   PM_CHANGE_Lenth                8
#define   DC_UPDATE_8word_Lenth          22
#define   DC_UPDATE_16word_Lenth         38

#define GOOD  ((uint8_t)0)
//#define FAULT ((uint8_t)1)


#define  TLD7002_UARTPort            UART_0
#define  TLD7002_UARTPort_TL         UART_0
#define  TLD7002_UARTPort_DTP        UART_0

//set  PWM duty  of channel
#define LD_PWM_DC_CFG_01      0x00
#define LD_PWM_DC_CFG_02      0x01
#define LD_PWM_DC_CFG_03      0x02
#define LD_PWM_DC_CFG_04      0x03
#define LD_PWM_DC_CFG_05      0x04
#define LD_PWM_DC_CFG_06      0x05
#define LD_PWM_DC_CFG_07      0x06
#define LD_PWM_DC_CFG_08      0x07
#define LD_PWM_DC_CFG_09      0x08
#define LD_PWM_DC_CFG_10      0x09
#define LD_PWM_DC_CFG_11      0x0A
#define LD_PWM_DC_CFG_12      0x0B
#define LD_PWM_DC_CFG_13      0x0C
#define LD_PWM_DC_CFG_14      0x0D
#define LD_PWM_DC_CFG_15      0x0E
#define LD_PWM_DC_CFG_16      0x0F

//set Output current of channel and Output slew of channel
#define LD_PWM_DAC_CFG_01     0x10
#define LD_PWM_DAC_CFG_02     0x11
#define LD_PWM_DAC_CFG_03     0x12
#define LD_PWM_DAC_CFG_04     0x13
#define LD_PWM_DAC_CFG_05     0x14
#define LD_PWM_DAC_CFG_06     0x15
#define LD_PWM_DAC_CFG_07     0x16
#define LD_PWM_DAC_CFG_08     0x17
#define LD_PWM_DAC_CFG_09     0x18
#define LD_PWM_DAC_CFG_10     0x19
#define LD_PWM_DAC_CFG_11     0x1A
#define LD_PWM_DAC_CFG_12     0x1B
#define LD_PWM_DAC_CFG_13     0x1C
#define LD_PWM_DAC_CFG_14     0x1D
#define LD_PWM_DAC_CFG_15     0x1E
#define LD_PWM_DAC_CFG_16     0x1F

#define DIAG_SLS_CFG          0x20
#define TH_OVLD_CFG           0x21

#define LD_ADC_VFWD_01        0x22
#define LD_ADC_VFWD_02        0x23
#define LD_ADC_VFWD_03        0x24
#define LD_ADC_VFWD_04        0x25
#define LD_ADC_VFWD_05        0x26
#define LD_ADC_VFWD_06        0x27
#define LD_ADC_VFWD_07        0x28
#define LD_ADC_VFWD_08        0x29
#define LD_ADC_VFWD_09        0x2A
#define LD_ADC_VFWD_10        0x2B
#define LD_ADC_VFWD_11        0x2C
#define LD_ADC_VFWD_12        0x2D
#define LD_ADC_VFWD_13        0x2E
#define LD_ADC_VFWD_14        0x2F
#define LD_ADC_VFWD_15        0x30
#define LD_ADC_VFWD_16        0x31

#define LD_ADC_VLED           0x32
#define LD_ADC_VS             0x33
#define LD_ADC_VOUT_MIN       0x34
#define LD_ADC_VGPIN0         0x35
#define LD_ADC_VGPIN1         0x36
#define TH_OVLD_STATUS        0x37
#define DTS_STAT              0x38
#define RECON_STAT            0x39
#define PMU_DIAG              0x3A
#define HSLI_TIMING_CFG       0x3B

#define ADDR_ERR                1
#define Rec_CRC3_ERR            2
#define Rec_CRC8_ERR            2
#define Rec_TER_ERR             3
#define OverTime_ERR            4
#define Commuite_ERR            5
#define Rec_Success             6
#define Senddata_lenth_ERR      8


#define Rxdata_ReadOTS_Lenth         22

#define  TLD7002_LPITPort_UART           0
#define  TLD7002_LPIT_Writecurrent_mode         1
#define  TLD7002_LPIT_Updateduty_mode           2

#define TLD7002_Enable      1
#define TLD7002_Disable     0

#define  TLD7002_DeyTime       (uint32)60


/******************************************************************************/
/*	UART over CAN frame and field content definitions 					 	  */
/******************************************************************************/

/** FRAME_SYNC_MSG_t
 *  Enum for FRAME_SYNC_MSG_t
 */
typedef enum FRAME_SYNC_MSG_t {
	SYNC_MSG 										= 0x55		/**< sync message */
} FRAME_SYNC_MSG_t;

/** FRAME_RES_BYTE_t
 *  Enum for FRAME_RES_BYTE_t
 */
typedef enum FRAME_RES_BYTE_t {
	RES_BYTE 										= 0x0		/**< reserved byte */
} FRAME_RES_BYTE_t;


/** FRAME_SLAVE_ADDRESS_t
 *  Enum for FRAME_MASTER_ADDRESS_t
 */
typedef enum FRAME_SLAVE_ADDRESS_t {
	FRAME_SLAVE_ADDRESS_BROADCAST					=  0x0,		/**< broadcast message */
	FRAME_SLAVE_ADDRESS_1							=  0x1,		/**< slave address  1 */
	FRAME_SLAVE_ADDRESS_2							=  0x2,		/**< slave address  2 */
	FRAME_SLAVE_ADDRESS_3							=  0x3,		/**< slave address  3 */
	FRAME_SLAVE_ADDRESS_4							=  0x4,		/**< slave address  4 */
	FRAME_SLAVE_ADDRESS_5							=  0x5,		/**< slave address  5 */
	FRAME_SLAVE_ADDRESS_6							=  0x6,		/**< slave address  6 */
	FRAME_SLAVE_ADDRESS_7							=  0x7,		/**< slave address  7 */
	FRAME_SLAVE_ADDRESS_8							=  0x8,		/**< slave address  8 */
	FRAME_SLAVE_ADDRESS_9							=  0x9,		/**< slave address  9 */
	FRAME_SLAVE_ADDRESS_10							=  0xA,		/**< slave address 10 */
	FRAME_SLAVE_ADDRESS_11							=  0xB,		/**< slave address 11 */
	FRAME_SLAVE_ADDRESS_12							=  0xC,		/**< slave address 12 */
	FRAME_SLAVE_ADDRESS_13							=  0xD,		/**< slave address 13 */
	FRAME_SLAVE_ADDRESS_14							=  0xE,		/**< slave address 14 */
	FRAME_SLAVE_ADDRESS_15							=  0xF,		/**< slave address 15 */
	FRAME_SLAVE_ADDRESS_16							= 0x10,		/**< slave address 16 */
	FRAME_SLAVE_ADDRESS_17							= 0x11,		/**< slave address 17 */
	FRAME_SLAVE_ADDRESS_18							= 0x12,		/**< slave address 18 */
	FRAME_SLAVE_ADDRESS_19							= 0x13,		/**< slave address 19 */
	FRAME_SLAVE_ADDRESS_20							= 0x14,		/**< slave address 20 */
	FRAME_SLAVE_ADDRESS_21							= 0x15,		/**< slave address 21 */
	FRAME_SLAVE_ADDRESS_22							= 0x16,		/**< slave address 22 */
	FRAME_SLAVE_ADDRESS_23							= 0x17,		/**< slave address 23 */
	FRAME_SLAVE_ADDRESS_24							= 0x18,		/**< slave address 24 */
	FRAME_SLAVE_ADDRESS_25							= 0x19,		/**< slave address 25 */
	FRAME_SLAVE_ADDRESS_26							= 0x1A,		/**< slave address 26 */
	FRAME_SLAVE_ADDRESS_27							= 0x1B,		/**< slave address 27 */
	FRAME_SLAVE_ADDRESS_28							= 0x1C,		/**< slave address 28 */
	FRAME_SLAVE_ADDRESS_29							= 0x1D,		/**< slave address 29 */
	FRAME_SLAVE_ADDRESS_30							= 0x1E,		/**< slave address 30 */
	FRAME_SLAVE_ADDRESS_31							= 0x1F		/**< slave address 31 */
} FRAME_SLAVE_ADDRESS_t;


/** FRAME_SLAVE_ADDRESS_CRC_t
 *  Enum for FRAME_SLAVE_ADDRESS_CRC_t
 */
typedef enum FRAME_SLAVE_ADDRESS_CRC_t {
	FRAME_SLAVE_ADDRESS_NO_CRC						=  0x0		/**< no slave address CRC */
} FRAME_SLAVE_ADDRESS_CRC_t;


/** FRAME_CRC_ADDRESS_t
 *
 */
typedef struct {
	union {
		struct {
			FRAME_SLAVE_ADDRESS_t Address			: 5;  	/*!< [0..4] Address */
			FRAME_SLAVE_ADDRESS_CRC_t TLDCRC			: 3;		/*!< [5..7] CRC */
		} bit;
		uint8 CRC_ADDRESS_BYTE;
	};
} FRAME_CRC_ADDRESS_t;





/** FRAME_FUN_t
 *  Enum for FRAME_FUN_t. Represent the desired function request
 */
typedef enum FRAME_FUN_t {
	FRAME_FUN_BRDC_DC_SYNC						=  0x0,		/**< Broadcast duty cycle synchronization */
	FRAME_FUN_DC_UPDATE								=  0x1,		/**< Duty cycle shadow register update */
	FRAME_FUN_READ_OST								=  0x2,		/**< Request diagnostics */
	FRAME_FUN_HWCR										=  0x3,		/**< Hardware control frame */
	FRAME_FUN_WRITE_REG								=  0x4,		/**< Write register */
	FRAME_FUN_READ_REG								=  0x5,		/**< Read register */
	FRAME_FUN_PM_CHANGE								=  0x6,		/**< Power mode change */
	FRAME_FUN_RESERVED								=  0x7		/**< Reserved */
} FRAME_FUN_t;


/** FRAME_DLC_t
 *  Enum for FRAME_DLC_t. Data Length Code, 3 Bit. Represented in words - multiple of 2 bytes
 */
typedef enum FRAME_DLC_t {
	FRAME_DLC_0										=  0x0,		/**< 0 words, 0 bytes */
	FRAME_DLC_1										=  0x1,		/**< 1 word, 2 bytes */
	FRAME_DLC_2										=  0x2,		/**< 2 words, 4 bytes */
	FRAME_DLC_3										=  0x3,		/**< 4 words, 8 bytes */
	FRAME_DLC_4										=  0x4,		/**< 8 words, 16 bytes */
	FRAME_DLC_5										=  0x5,		/**< 12 words, 24 bytes */
	FRAME_DLC_6										=  0x6,		/**< 16 words, 32 bytes */
	FRAME_DLC_7										=  0x7		/**< 32 words, 64 bytes */
} FRAME_DLC_t;


/** FRAME_RC_2BIT_t
 *  Enum for Rolling Counter, a 2 bit counter value, has to be incremented in every
 *  data transmission. 0x00 default (start) value
 */
typedef enum FRAME_RC_2BIT_t {
	FRAME_RC_2BIT_START_VALUE				=  0x0,		/**< default (start) value */
	FRAME_RC_2BIT_0									=  0x0,
	FRAME_RC_2BIT_1									=  0x1,
	FRAME_RC_2BIT_2									=  0x2,
	FRAME_RC_2BIT_3									=  0x3
} FRAME_RC_2BIT_t;


/** FRAME_MRC_DLC_FUN_t
 *
 */
typedef struct {
	union {
		struct {
			FRAME_FUN_t FUN							: 3;		/*!< [0..2] Function */
			FRAME_DLC_t DLC							: 3;		/*!< [3..5] Data Length Code */
			FRAME_RC_2BIT_t MRC					: 2;		/*!< [6..7] Rolling Counter,  master needs to increment in every data transmission*/
		} bit;
		uint8 MRC_DLC_FUN_BYTE;
	};
} FRAME_MRC_DLC_FUN_t;






/** FRAME_OUTPUT_STATUS_BYTE_t
 *
 */
typedef struct {
	union {
		struct {
			bool FAULT								: 1;		/*!< [0] Internal fault flag. 0: no internal fault detected; 1: internal fault condition detected */
			bool OVLD								: 1;		/*!< [1] Over load flag. 0: no overload condition detected on OUT0 to OUT15; 1: there was at least one overload condition detected */
			bool VFWD_WRN							: 1;		/*!< [2] Forward voltage warning flag. 0: no forward voltage warning for OUT0 to OUT15 detected; 1: there was at least one forward voltage warning condition */
			bool CUR_WRN							: 1;		/*!< [3] Output current warning flag. 0: no output current warning for OUT0 to OUT15 detected; 1: there was at least one output current warning condition */
			bool DC_WRN								: 1;		/*!< [4] Duty cycle warning flag. 0: no duty cycle warning for OUT0 to OUT15 detected; 1: there was at least one duty cycle warning condition */
			bool GPINn_WRN						: 1;		/*!< [5] GPINn warning flag. 0: GPIN0 and GPIN1 are not in a fault condition; 1: there was at least one GPINn fault condition or GPINn adjacent short condition */
			bool OUT_SHRT_WRN					: 1;		/*!< [6] short between adjacent output warning. 0: no short between adjacent output warning detected; 1: there was at least one short between an adjacent output warning detected */
			bool VLED_VS_UV						: 1;		/*!< [7] VLED/VS under voltage flag. 0: if (V_LED AND V_S) is above V_DEN_threshold ; 1: there was at least one under voltage condition event detected */
		} bit;
		uint8 OUTPUT_STATUS_BYTE;
	};
} FRAME_OUTPUT_STATUS_BYTE_t;


/** FRAME_DC_UPDATE_14BITDCVAL_t
 *
 */
typedef struct {
	union {
		struct {
			uint16 duty_cycle						:14;		/*!< [0..14] Duty Cycle */
			uint8 RESERVED							: 2;		/*!< [15..16] RESERVED */
		} bit;
		uint8 DC_UPDATE_14BITDCVAL_BYTE[2];
	};
} FRAME_DC_UPDATE_14BITDCVAL_t;



/** FRAME_OUTPUT_STATUS_BYTE_OUT_t
 *
 */
typedef struct {
	union {
		struct {
			uint8 OUT_STAT							: 1;		/*!< [0] Output state flag. 0: power output channel is in OFF state; 1: power output channel is in ON state */
			uint8 VFWD_WRN							: 1;		/*!< [1] Forward voltage warning flag. 0: no forward voltage warning detected; 1: there was at least one forward voltage warning condition detected */
			uint8 CUR_WRN							: 1;		/*!< [2] Output current warning flag. 0: no output current warning detected; 1: there was at least one output current warning condition detected */
			uint8 DC_WRN							: 1;		/*!< [3] Duty cycle warning flag. 0: no duty cycle warning detected; 1: there was at least one duty cycle warning condition detected */
			uint8 OUT_SHORT_WRN						: 1;		/*!< [4] Short between adjacent output warning flag. 0: no short between adjacent output warning detected; 1: there was at least one short between an adjacent output warning detected */
			uint8 OVLD								: 1;		/*!< [5] OVLD flag. 0: no OVLD condition detected; 1: there was at least one OVLD condition since the last read out */
			uint8 SLS								: 1;		/*!< [6] Single LED Short (SLS) flag. 0: no SLS condition detected; 1: there was at least one single LED short detected */
			uint8 OL								: 1;		/*!< [7] Open load flag. 0: no open load condition detected; 1: there was at least one open load condition detected */
		} bit;
		uint8 OUTPUT_STATUS_BYTE_OUT;
	};
} FRAME_OUTPUT_STATUS_BYTE_OUT_t;


/** FRAME_HWCR_RESET_OUT_t
 *
 */
typedef struct {
	union {
		struct {
			bool RES_OUT0						: 1;		/*!< [0] RESET OUT0 */
			bool RES_OUT1						: 1;		/*!< [1] RESET OUT1 */
			bool RES_OUT2						: 1;		/*!< [2] RESET OUT2 */
			bool RES_OUT3						: 1;		/*!< [3] RESET OUT3 */
			bool RES_OUT4						: 1;		/*!< [4] RESET OUT4 */
			bool RES_OUT5						: 1;		/*!< [5] RESET OUT5 */
			bool RES_OUT6						: 1;		/*!< [6] RESET OUT6 */
			bool RES_OUT7						: 1;		/*!< [7] RESET OUT7 */
			bool RES_OUT8						: 1;		/*!< [8] RESET OUT8 */
			bool RES_OUT9						: 1;		/*!< [9] RESET OUT9 */
			bool RES_OUT10						: 1;		/*!< [10] RESET OUT10 */
			bool RES_OUT11						: 1;		/*!< [11] RESET OUT11 */
			bool RES_OUT12						: 1;		/*!< [12] RESET OUT12 */
			bool RES_OUT13						: 1;		/*!< [13] RESET OUT13 */
			bool RES_OUT14						: 1;		/*!< [14] RESET OUT14 */
			bool RES_OUT15						: 1;		/*!< [15] RESET OUT15 */
		} bit;
		struct {
			uint8 HWCR_RESET_OUT_HB;
			uint8 HWCR_RESET_OUT_LB;
		};
	};
} FRAME_HWCR_RESET_OUT_t;



/** FRAME_HWCR_RESET_STATUS_t
 *
 */
typedef struct {
	union {
		struct {
// TODO: BITFIELDS!!
			bool BIT0								: 1;		/*!< [0] BIT0. 0: LOW; 1: HIGH */
			bool BIT1								: 1;		/*!< [1] BIT1. 0: LOW; 1: HIGH */
			bool BIT2								: 1;		/*!< [2] BIT2. 0: LOW; 1: HIGH */
			bool BIT3								: 1;		/*!< [3] BIT3. 0: LOW; 1: HIGH */
			bool BIT4								: 1;		/*!< [4] BIT4. 0: LOW; 1: HIGH */
			bool BIT5								: 1;		/*!< [5] BIT5. 0: LOW; 1: HIGH */
			bool BIT6								: 1;		/*!< [6] BIT6. 0: LOW; 1: HIGH */
			bool BIT7								: 1;		/*!< [7] BIT7. 0: LOW; 1: HIGH */
		} bit;
		uint8 HWCR_RESET_STATUS_BYTE;
	};
} FRAME_HWCR_RESET_STATUS_t;




/** FRAME_POWER_MODE_t
 *  Enum for FRAME_POWER_MODE_t. Master power mode change byte comprises the commanded power mode state.
 */
typedef enum FRAME_PM_t {
	FRAME_PM_INIT_MODE								=  0x0,		/**< enter init mode */
	FRAME_PM_RES1									=  0x1,		/**< reserved */
	FRAME_PM_RES2									=  0x2,		/**< reserved */
	FRAME_PM_OTP_MODE								=  0x3		/**< enter OTP mode */
} FRAME_PM_t;


/** FRAME_POWER_MODE_CHANGE_t
 *
 */
typedef struct {
	union {
		struct {
			FRAME_PM_t POWER_MODE					: 3;		/*!< [0..2] Power mode */
			uint8 RESERVED							: 5;		/*!< [3..7] Reserved */
		} bit;
		uint8 POWER_MODE_CHANGE_BYTE;
	};
} FRAME_POWER_MODE_CHANGE_t;




/** FRAME_ACK_BYTE_MODE_t
 *  Enum for FRAME_ACK_BYTE_MODE_t. Rolling Counter, 2 bit counter value.
 */
typedef enum FRAME_ACK_BYTE_MODE_t {
	FRAME_ACK_BYTE_MODE_0							=  0x0,		/**< init mode */
	FRAME_ACK_BYTE_MODE_1							=  0x1,		/**< active mode */
	FRAME_ACK_BYTE_MODE_2							=  0x2,		/**< fail-safe mode */
	FRAME_ACK_BYTE_MODE_3							=  0x3		/**< programming or emulation mode */
} FRAME_ACK_BYTE_MODE_t;


/** FRAME_ACK_BYTE_CRC_t
 *  Enum for FRAME_ACK_BYTE_CRC_t
 */
typedef enum FRAME_ACK_BYTE_CRC_t {
	FRAME_ACK_BYTE_NO_CRC							=  0x0		/**< no ack byte CRC */
} FRAME_ACK_BYTE_CRC_t;


/** FRAME_ACK_BYTE_t
 *
 */
typedef struct {
	union {
		struct {
			bool TER											: 1;		/*!< [0] Transmission Error. 0 current frame has been successfully received; 1: the received frame resulted in a CRC8 error */
			FRAME_RC_2BIT_t RC						: 2;		/*!< [1..2] rolling counter, incremented at every slave response */
			FRAME_ACK_BYTE_MODE_t MODE		: 2;		/*!< [3..4] mode */
			FRAME_ACK_BYTE_CRC_t TLDCRC			: 3;		/*!< [5..7] CRC3 */
		} bit;
		uint8 ACK_BYTE;
	};
} FRAME_ACK_BYTE_t;


/******************************************************************************/
/*	UART over CAN frame type definitions 									  */
/******************************************************************************/



/** BRDC_DC_SYNC_FRAME_t
 */
typedef struct {
	union {
		struct {
			FRAME_SYNC_MSG_t SYNC;								/*!< sync message */
			FRAME_CRC_ADDRESS_t CRC_REQ_S_ADD;					/*!< CRC and slave address */
			FRAME_MRC_DLC_FUN_t MRC_DLC_FUN;					/*!< MRC, DLC and FUN */
		} w_brdc_dc_sync;
		uint8 write_array[LEN_BRDC_DC_SYNC_WRITE];				/*!< write frame */
	};
} BRDC_DC_SYNC_FRAME_t;


/** DC_UPDATE_8BIT_FRAME_t
 */
typedef struct {
	union {
		struct {
			FRAME_SYNC_MSG_t SYNC;								/*!< sync message */
			FRAME_CRC_ADDRESS_t CRC_REQ_S_ADD;					/*!< CRC and slave address */
			FRAME_MRC_DLC_FUN_t MRC_DLC_FUN;					/*!< MRC, DLC and FUN */
			uint8 DutyCycleOUT0;								/*!< 8 Bit duty cycle representation for OUT0 */
			uint8 DutyCycleOUT1;								/*!< 8 Bit duty cycle representation for OUT1 */
			uint8 DutyCycleOUT2;								/*!< 8 Bit duty cycle representation for OUT2 */
			uint8 DutyCycleOUT3;								/*!< 8 Bit duty cycle representation for OUT3 */
			uint8 DutyCycleOUT4;								/*!< 8 Bit duty cycle representation for OUT4 */
			uint8 DutyCycleOUT5;								/*!< 8 Bit duty cycle representation for OUT5 */
			uint8 DutyCycleOUT6;								/*!< 8 Bit duty cycle representation for OUT6 */
			uint8 DutyCycleOUT7;								/*!< 8 Bit duty cycle representation for OUT7 */
			uint8 DutyCycleOUT8;								/*!< 8 Bit duty cycle representation for OUT8 */
			uint8 DutyCycleOUT9;								/*!< 8 Bit duty cycle representation for OUT9 */
			uint8 DutyCycleOUT10;								/*!< 8 Bit duty cycle representation for OUT10 */
			uint8 DutyCycleOUT11;								/*!< 8 Bit duty cycle representation for OUT11 */
			uint8 DutyCycleOUT12;								/*!< 8 Bit duty cycle representation for OUT12 */
			uint8 DutyCycleOUT13;								/*!< 8 Bit duty cycle representation for OUT13 */
			uint8 DutyCycleOUT14;								/*!< 8 Bit duty cycle representation for OUT14 */
			uint8 DutyCycleOUT15;								/*!< 8 Bit duty cycle representation for OUT15 */
			uint8 SAFETY_BYTE;									/*!< CRC */
		} w_pwm_dc_update;
		uint8 write_array[LEN_DC_UPDATE_8BIT_WRITE];			/*!< write frame */
	};
	union {
		struct {
			uint8 OST;											/*!< Output status byte */
			uint8 ACK;											/*!< Acknowledge byte */
		} r_pwm_dc_update;
		uint8 read_array[LEN_DC_UPDATE_8BIT_READ];				/*!< read frame */
	};
	bool timeout;												/*!< receive answer timeout */
} DC_UPDATE_8BIT_FRAME_t;



/** DC_UPDATE_14BIT_FRAME_t
 */
typedef struct {
	union {
		struct {
			FRAME_SYNC_MSG_t SYNC;								/*!< sync message */
			FRAME_CRC_ADDRESS_t CRC_REQ_S_ADD;					/*!< CRC and slave address */
			FRAME_MRC_DLC_FUN_t MRC_DLC_FUN;					/*!< MRC, DLC and FUN */
			uint8 DutyCycleOUT0_HB;								/*!< 14 Bit duty cycle representation for OUT0 - HB */
			uint8 DutyCycleOUT0_LB;								/*!< 14 Bit duty cycle representation for OUT0 - LB */
			uint8 DutyCycleOUT1_HB;								/*!< 14 Bit duty cycle representation for OUT1 - HB */
			uint8 DutyCycleOUT1_LB;								/*!< 14 Bit duty cycle representation for OUT1 - LB */
			uint8 DutyCycleOUT2_HB;								/*!< 14 Bit duty cycle representation for OUT2 - HB */
			uint8 DutyCycleOUT2_LB;								/*!< 14 Bit duty cycle representation for OUT2 - LB */
			uint8 DutyCycleOUT3_HB;								/*!< 14 Bit duty cycle representation for OUT3 - HB */
			uint8 DutyCycleOUT3_LB;								/*!< 14 Bit duty cycle representation for OUT3 - LB */
			uint8 DutyCycleOUT4_HB;								/*!< 14 Bit duty cycle representation for OUT4 - HB */
			uint8 DutyCycleOUT4_LB;								/*!< 14 Bit duty cycle representation for OUT4 - LB */
			uint8 DutyCycleOUT5_HB;								/*!< 14 Bit duty cycle representation for OUT5 - HB */
			uint8 DutyCycleOUT5_LB;								/*!< 14 Bit duty cycle representation for OUT5 - LB */
			uint8 DutyCycleOUT6_HB;								/*!< 14 Bit duty cycle representation for OUT6 - HB */
			uint8 DutyCycleOUT6_LB;								/*!< 14 Bit duty cycle representation for OUT6 - LB */
			uint8 DutyCycleOUT7_HB;								/*!< 14 Bit duty cycle representation for OUT7 - HB */
			uint8 DutyCycleOUT7_LB;								/*!< 14 Bit duty cycle representation for OUT7 - LB */
			uint8 DutyCycleOUT8_HB;								/*!< 14 Bit duty cycle representation for OUT8 - HB */
			uint8 DutyCycleOUT8_LB;								/*!< 14 Bit duty cycle representation for OUT8 - LB */
			uint8 DutyCycleOUT9_HB;								/*!< 14 Bit duty cycle representation for OUT9 - HB */
			uint8 DutyCycleOUT9_LB;								/*!< 14 Bit duty cycle representation for OUT9 - LB */
			uint8 DutyCycleOUT10_HB;							/*!< 14 Bit duty cycle representation for OUT10 - HB */
			uint8 DutyCycleOUT10_LB;							/*!< 14 Bit duty cycle representation for OUT10 - LB */
			uint8 DutyCycleOUT11_HB;							/*!< 14 Bit duty cycle representation for OUT11 - HB */
			uint8 DutyCycleOUT11_LB;							/*!< 14 Bit duty cycle representation for OUT11 - LB */
			uint8 DutyCycleOUT12_HB;							/*!< 14 Bit duty cycle representation for OUT12 - HB */
			uint8 DutyCycleOUT12_LB;							/*!< 14 Bit duty cycle representation for OUT12 - LB */
			uint8 DutyCycleOUT13_HB;							/*!< 14 Bit duty cycle representation for OUT13 - HB */
			uint8 DutyCycleOUT13_LB;							/*!< 14 Bit duty cycle representation for OUT13 - LB */
			uint8 DutyCycleOUT14_HB;							/*!< 14 Bit duty cycle representation for OUT14 - HB */
			uint8 DutyCycleOUT14_LB;							/*!< 14 Bit duty cycle representation for OUT14 - LB */
			uint8 DutyCycleOUT15_HB;							/*!< 14 Bit duty cycle representation for OUT15 - HB */
			uint8 DutyCycleOUT15_LB;							/*!< 14 Bit duty cycle representation for OUT15 - LB */
			uint8 SAFETY_BYTE;									/*!< CRC */
		} w_pwm_dc_update;
		uint8 write_array[LEN_DC_UPDATE_14BIT_WRITE];			/*!< write frame */
	};
	union {
		struct {
			uint8 OST;											/*!< Output status byte */
			uint8 ACK;											/*!< Acknowledge byte */
		} r_pwm_dc_update;
		uint8 read_array[LEN_DC_UPDATE_14BIT_READ];				/*!< read frame */
	};
	bool timeout;												/*!< receive answer timeout */
} DC_UPDATE_14BIT_FRAME_t;




/** PM_CHANGE_FRAME_t
 */
typedef struct {
	union {
		struct {
			FRAME_SYNC_MSG_t SYNC;								/*!< sync message */
			FRAME_CRC_ADDRESS_t CRC_REQ_S_ADD;					/*!< CRC and slave address */
			FRAME_MRC_DLC_FUN_t MRC_DLC_FUN;					/*!< MRC, DLC and FUN */
			uint8 PM_CHANGE;									/*!< Power Mode */
			uint8 RESERVED;										/*!< Reserved */
			uint8 SAFETY_BYTE;									/*!< CRC */
		} w_power_mode_change;
		uint8 write_array[LEN_PM_CHANGE_WRITE];					/*!< write frame */
	};
	union {
		struct {
			uint8 OST;											/*!< Output status byte */
			uint8 ACK;											/*!< Acknowledge byte */
		} r_power_mode_change;
		uint8 read_array[LEN_PM_CHANGE_READ];					/*!< read frame */
	};
	bool timeout;												/*!< receive answer timeout */
} PM_CHANGE_FRAME_t;



/** READ_OST_FRAME_t
 */
typedef struct {
	union {
		struct {
			FRAME_SYNC_MSG_t SYNC;								/*!< sync message */
			FRAME_CRC_ADDRESS_t CRC_REQ_S_ADD;					/*!< CRC and slave address */
			FRAME_MRC_DLC_FUN_t MRC_DLC_FUN;					/*!< MRC, DLC and FUN */
		} w_read_output_status;
		uint8 write_array[LEN_READ_OST_WRITE];					/*!< write frame */
	};
	union {
		struct {
			uint8 OSB_OUT0;										/*!< Output Status Byte for OUT0 */
			uint8 OSB_OUT1;										/*!< Output Status Byte for OUT1 */
			uint8 OSB_OUT2;										/*!< Output Status Byte for OUT2 */
			uint8 OSB_OUT3;										/*!< Output Status Byte for OUT3 */
			uint8 OSB_OUT4;										/*!< Output Status Byte for OUT4 */
			uint8 OSB_OUT5;										/*!< Output Status Byte for OUT5 */
			uint8 OSB_OUT6;										/*!< Output Status Byte for OUT6 */
			uint8 OSB_OUT7;										/*!< Output Status Byte for OUT7 */
			uint8 OSB_OUT8;										/*!< Output Status Byte for OUT8 */
			uint8 OSB_OUT9;										/*!< Output Status Byte for OUT9 */
			uint8 OSB_OUT10;									/*!< Output Status Byte for OUT10 */
			uint8 OSB_OUT11;									/*!< Output Status Byte for OUT11 */
			uint8 OSB_OUT12;									/*!< Output Status Byte for OUT12 */
			uint8 OSB_OUT13;									/*!< Output Status Byte for OUT13 */
			uint8 OSB_OUT14;									/*!< Output Status Byte for OUT14 */
			uint8 OSB_OUT15;									/*!< Output Status Byte for OUT15 */
			uint8 SAFETY_BYTE;									/*!< CRC */
			uint8 OST;											/*!< Output status byte */
			uint8 ACK;											/*!< Acknowledge byte */
		} r_read_output_status;
		uint8 read_array[LEN_READ_OST_READ];					/*!< read frame */
	};
	bool timeout;												/*!< receive answer timeout */
} READ_OST_FRAME_t;




/** HWCR_FRAME_t
 */
typedef struct {
	union {
		struct {
			FRAME_SYNC_MSG_t SYNC;								/*!< sync message */
			FRAME_CRC_ADDRESS_t CRC_REQ_S_ADD;					/*!< CRC and slave address */
			FRAME_MRC_DLC_FUN_t MRC_DLC_FUN;					/*!< MRC, DLC and FUN */
			uint8 RESET_OVERLOAD_HB;							/*!< Reset Overload for outputs - high byte */
			uint8 RESET_OVERLOAD_LB;							/*!< Reset Overload for outputs - low byte */
			uint8 RESET_OPENLOAD_HB;							/*!< Reset Openload for outputs - high byte */
			uint8 RESET_OPENLOAD_LB;							/*!< Reset Openload for outputs - low byte */
			uint8 RESET_SLS_HB;									/*!< Reset SLS for outputs - high byte */
			uint8 RESET_SLS_LB;									/*!< Reset SLS for outputs - low byte */
			FRAME_RES_BYTE_t RESERVED;							/*!< Reserved */
			uint8 RESET_STATUS;									/*!< Reset status byte */
			uint8 SAFETY_BYTE;									/*!< CRC */
		} w_hardware_control;
		uint8 write_array[LEN_HWCR_WRITE];						/*!< write frame */
	};
	union {
		struct {
			uint8 OST;											/*!< Output status byte */
			uint8 ACK;											/*!< Acknowledge byte */
		} r_hardware_control;
		uint8 read_array[LEN_HWCR_READ];						/*!< read frame */
	};
	bool timeout;												/*!< receive answer timeout */
} HWCR_FRAME_t;




/** WRITE_REG_DLC1_FRAME_t
 */
typedef struct {
	union {
		struct {
			FRAME_SYNC_MSG_t SYNC;								/*!< sync message */
			FRAME_CRC_ADDRESS_t CRC_REQ_S_ADD;					/*!< CRC and slave address */
			FRAME_MRC_DLC_FUN_t MRC_DLC_FUN;					/*!< MRC, DLC and FUN */
			uint8 StartADDR;									/*!< Start Address byte */
			uint16 Data[(LEN_WRITE_REG_DLC1_WRITE-LEN_WRITE_REG_OVHD)/2];	/*!< Data */
			uint8 SAFETY_BYTE;									/*!< CRC */
		} w_write_reg;
		uint8 write_array[LEN_WRITE_REG_DLC1_WRITE];			/*!< write frame */
	};
	union {
		struct {
			uint8 OST;											/*!< Output status byte */
			uint8 ACK;											/*!< Acknowledge byte */
		} r_write_reg;
		uint8 read_array[LEN_WRITE_REG_READ];					/*!< read frame */
	};
	bool timeout;												/*!< receive answer timeout */
} WRITE_REG_DLC1_FRAME_t;


/** WRITE_REG_DLC2_FRAME_t
 */
typedef struct {
	union {
		struct {
			FRAME_SYNC_MSG_t SYNC;								/*!< sync message */
			FRAME_CRC_ADDRESS_t CRC_REQ_S_ADD;					/*!< CRC and slave address */
			FRAME_MRC_DLC_FUN_t MRC_DLC_FUN;					/*!< MRC, DLC and FUN */
			uint8 StartADDR;									/*!< Start Address byte */
			uint16 Data[(LEN_WRITE_REG_DLC2_WRITE-LEN_WRITE_REG_OVHD)/2];	/*!< Data */
			uint8 SAFETY_BYTE;									/*!< CRC */
		} w_write_reg;
		uint8 write_array[LEN_WRITE_REG_DLC2_WRITE];			/*!< write frame */
	};
	union {
		struct {
			uint8 OST;											/*!< Output status byte */
			uint8 ACK;											/*!< Acknowledge byte */
		} r_write_reg;
		uint8 read_array[LEN_WRITE_REG_READ];					/*!< read frame */
	};
	bool timeout;												/*!< receive answer timeout */
} WRITE_REG_DLC2_FRAME_t;


/** WRITE_REG_DLC3_FRAME_t
 */
typedef struct {
	union {
		struct {
			FRAME_SYNC_MSG_t SYNC;								/*!< sync message */
			FRAME_CRC_ADDRESS_t CRC_REQ_S_ADD;					/*!< CRC and slave address */
			FRAME_MRC_DLC_FUN_t MRC_DLC_FUN;					/*!< MRC, DLC and FUN */
			uint8 StartADDR;									/*!< Start Address byte */
			uint16 Data[(LEN_WRITE_REG_DLC3_WRITE-LEN_WRITE_REG_OVHD)/2];	/*!< Data */
			uint8 SAFETY_BYTE;									/*!< CRC */
		} w_write_reg;
		uint8 write_array[LEN_WRITE_REG_DLC3_WRITE];			/*!< write frame */
	};
	union {
		struct {
			uint8 OST;											/*!< Output status byte */
			uint8 ACK;											/*!< Acknowledge byte */
		} r_write_reg;
		uint8 read_array[LEN_WRITE_REG_READ];					/*!< read frame */
	};
	bool timeout;												/*!< receive answer timeout */
} WRITE_REG_DLC3_FRAME_t;


/** WRITE_REG_DLC4_FRAME_t
 */
typedef struct {
	union {
		struct {
			FRAME_SYNC_MSG_t SYNC;								/*!< sync message */
			FRAME_CRC_ADDRESS_t CRC_REQ_S_ADD;					/*!< CRC and slave address */
			FRAME_MRC_DLC_FUN_t MRC_DLC_FUN;					/*!< MRC, DLC and FUN */
			uint8 StartADDR;									/*!< Start Address byte */
			uint16 Data[(LEN_WRITE_REG_DLC4_WRITE-LEN_WRITE_REG_OVHD)/2];	/*!< Data */
			uint8 SAFETY_BYTE;									/*!< CRC */
		} w_write_reg;
		uint8 write_array[LEN_WRITE_REG_DLC4_WRITE];			/*!< write frame */
	};
	union {
		struct {
			uint8 OST;											/*!< Output status byte */
			uint8 ACK;											/*!< Acknowledge byte */
		} r_write_reg;
		uint8 read_array[LEN_WRITE_REG_READ];					/*!< read frame */
	};
	bool timeout;												/*!< receive answer timeout */
} WRITE_REG_DLC4_FRAME_t;


/** WRITE_REG_DLC5_FRAME_t
 */
typedef struct {
	union {
		struct {
			FRAME_SYNC_MSG_t SYNC;								/*!< sync message */
			FRAME_CRC_ADDRESS_t CRC_REQ_S_ADD;					/*!< CRC and slave address */
			FRAME_MRC_DLC_FUN_t MRC_DLC_FUN;					/*!< MRC, DLC and FUN */
			uint8 StartADDR;									/*!< Start Address byte */
			uint16 Data[(LEN_WRITE_REG_DLC5_WRITE-LEN_WRITE_REG_OVHD)/2];	/*!< Data */
			uint8 SAFETY_BYTE;									/*!< CRC */
		} w_write_reg;
		uint8 write_array[LEN_WRITE_REG_DLC5_WRITE];			/*!< write frame */
	};
	union {
		struct {
			uint8 OST;											/*!< Output status byte */
			uint8 ACK;											/*!< Acknowledge byte */
		} r_write_reg;
		uint8 read_array[LEN_WRITE_REG_READ];					/*!< read frame */
	};
	bool timeout;												/*!< receive answer timeout */
} WRITE_REG_DLC5_FRAME_t;


/** WRITE_REG_DLC6_FRAME_t
 */
typedef struct {
	union {
		struct {
			FRAME_SYNC_MSG_t SYNC;								/*!< sync message */
			FRAME_CRC_ADDRESS_t CRC_REQ_S_ADD;					/*!< CRC and slave address */
			FRAME_MRC_DLC_FUN_t MRC_DLC_FUN;					/*!< MRC, DLC and FUN */
			uint8 StartADDR;									/*!< Start Address byte */
			uint16 Data[(LEN_WRITE_REG_DLC6_WRITE-LEN_WRITE_REG_OVHD)/2];	/*!< Data */
			uint8 SAFETY_BYTE;									/*!< CRC */
		} w_write_reg;
		uint8 write_array[LEN_WRITE_REG_DLC6_WRITE];			/*!< write frame */
	};
	union {
		struct {
			uint8 OST;											/*!< Output status byte */
			uint8 ACK;											/*!< Acknowledge byte */
		} r_write_reg;
		uint8 read_array[LEN_WRITE_REG_READ];					/*!< read frame */
	};
	bool timeout;												/*!< receive answer timeout */
} WRITE_REG_DLC6_FRAME_t;


/** WRITE_REG_DLC7_FRAME_t
 */
typedef struct {
	union {
		struct {
			FRAME_SYNC_MSG_t SYNC;								/*!< sync message */
			FRAME_CRC_ADDRESS_t CRC_REQ_S_ADD;					/*!< CRC and slave address */
			FRAME_MRC_DLC_FUN_t MRC_DLC_FUN;					/*!< MRC, DLC and FUN */
			uint8 StartADDR;									/*!< Start Address byte */
			uint16 Data[(LEN_WRITE_REG_DLC7_WRITE-LEN_WRITE_REG_OVHD)/2];	/*!< Data */
			uint8 SAFETY_BYTE;									/*!< CRC */
		} w_write_reg;
		uint8 write_array[LEN_WRITE_REG_DLC7_WRITE];			/*!< write frame */
	};
	union {
		struct {
			uint8 OST;											/*!< Output status byte */
			uint8 ACK;											/*!< Acknowledge byte */
		} r_write_reg;
		uint8 read_array[LEN_WRITE_REG_READ];					/*!< read frame */
	};
	bool timeout;												/*!< receive answer timeout */
} WRITE_REG_DLC7_FRAME_t;


/** READ_REG_DLC1_FRAME_t
 */
typedef struct {
	union {
		struct {
			FRAME_SYNC_MSG_t SYNC;								/*!< sync message */
			FRAME_CRC_ADDRESS_t CRC_REQ_S_ADD;					/*!< CRC and slave address */
			FRAME_MRC_DLC_FUN_t MRC_DLC_FUN;					/*!< MRC, DLC and FUN */
			uint8 StartADDR;									/*!< Start Address byte */
		} w_read_reg;
		uint8 write_array[LEN_READ_REG_WRITE];					/*!< write frame */
	};
	union {
		struct {
			uint16 Data[(LEN_READ_REG_DLC1_READ-LEN_READ_REG_OVHD)/2];	/*!< Data */
			uint8 SAFETY_BYTE;									/*!< CRC */
			uint8 OST;											/*!< Output status byte */
			uint8 ACK;											/*!< Acknowledge byte */
		} r_read_reg;
		uint8 read_array[LEN_READ_REG_DLC1_READ];				/*!< read frame */
	};
	bool timeout;												/*!< receive answer timeout */
} READ_REG_DLC1_FRAME_t;


/** READ_REG_DLC2_FRAME_t
 */
typedef struct {
	union {
		struct {
			FRAME_SYNC_MSG_t SYNC;								/*!< sync message */
			FRAME_CRC_ADDRESS_t CRC_REQ_S_ADD;					/*!< CRC and slave address */
			FRAME_MRC_DLC_FUN_t MRC_DLC_FUN;					/*!< MRC, DLC and FUN */
			uint8 StartADDR;									/*!< Start Address byte */
		} w_read_reg;
		uint8 write_array[LEN_READ_REG_WRITE];					/*!< write frame */
	};
	union {
		struct {
			uint16 Data[(LEN_READ_REG_DLC2_READ-LEN_READ_REG_OVHD)/2];	/*!< Data */
			uint8 SAFETY_BYTE;									/*!< CRC */
			uint8 OST;											/*!< Output status byte */
			uint8 ACK;											/*!< Acknowledge byte */
		} r_read_reg;
		uint8 read_array[LEN_READ_REG_DLC2_READ];				/*!< read frame */
	};
	bool timeout;												/*!< receive answer timeout */
} READ_REG_DLC2_FRAME_t;


/** READ_REG_DLC3_FRAME_t
 */
typedef struct {
	union {
		struct {
			FRAME_SYNC_MSG_t SYNC;								/*!< sync message */
			FRAME_CRC_ADDRESS_t CRC_REQ_S_ADD;					/*!< CRC and slave address */
			FRAME_MRC_DLC_FUN_t MRC_DLC_FUN;					/*!< MRC, DLC and FUN */
			uint8 StartADDR;									/*!< Start Address byte */
		} w_read_reg;
		uint8 write_array[LEN_READ_REG_WRITE];					/*!< write frame */
	};
	union {
		struct {
			uint16 Data[(LEN_READ_REG_DLC3_READ-LEN_READ_REG_OVHD)/2];	/*!< Data */
			uint8 SAFETY_BYTE;									/*!< CRC */
			uint8 OST;											/*!< Output status byte */
			uint8 ACK;											/*!< Acknowledge byte */
		} r_read_reg;
		uint8 read_array[LEN_READ_REG_DLC3_READ];				/*!< read frame */
	};
	bool timeout;												/*!< receive answer timeout */
} READ_REG_DLC3_FRAME_t;


/** READ_REG_DLC4_FRAME_t
 */
typedef struct {
	union {
		struct {
			FRAME_SYNC_MSG_t SYNC;								/*!< sync message */
			FRAME_CRC_ADDRESS_t CRC_REQ_S_ADD;					/*!< CRC and slave address */
			FRAME_MRC_DLC_FUN_t MRC_DLC_FUN;					/*!< MRC, DLC and FUN */
			uint8 StartADDR;									/*!< Start Address byte */
		} w_read_reg;
		uint8 write_array[LEN_READ_REG_WRITE];					/*!< write frame */
	};
	union {
		struct {
			uint16 Data[(LEN_READ_REG_DLC4_READ-LEN_READ_REG_OVHD)/2];	/*!< Data */
			uint8 SAFETY_BYTE;									/*!< CRC */
			uint8 OST;											/*!< Output status byte */
			uint8 ACK;											/*!< Acknowledge byte */
		} r_read_reg;
		uint8 read_array[LEN_READ_REG_DLC4_READ];				/*!< read frame */
	};
	bool timeout;												/*!< receive answer timeout */
} READ_REG_DLC4_FRAME_t;


/** READ_REG_DLC5_FRAME_t
 */
typedef struct {
	union {
		struct {
			FRAME_SYNC_MSG_t SYNC;								/*!< sync message */
			FRAME_CRC_ADDRESS_t CRC_REQ_S_ADD;					/*!< CRC and slave address */
			FRAME_MRC_DLC_FUN_t MRC_DLC_FUN;					/*!< MRC, DLC and FUN */
			uint8 StartADDR;									/*!< Start Address byte */
		} w_read_reg;
		uint8 write_array[LEN_READ_REG_WRITE];					/*!< write frame */
	};
	union {
		struct {
			uint16 Data[(LEN_READ_REG_DLC5_READ-LEN_READ_REG_OVHD)/2];	/*!< Data */
			uint8 SAFETY_BYTE;									/*!< CRC */
			uint8 OST;											/*!< Output status byte */
			uint8 ACK;											/*!< Acknowledge byte */
		} r_read_reg;
		uint8 read_array[LEN_READ_REG_DLC5_READ];				/*!< read frame */
	};
	bool timeout;												/*!< receive answer timeout */
} READ_REG_DLC5_FRAME_t;


/** READ_REG_DLC6_FRAME_t
 */
typedef struct {
	union {
		struct {
			FRAME_SYNC_MSG_t SYNC;								/*!< sync message */
			FRAME_CRC_ADDRESS_t CRC_REQ_S_ADD;					/*!< CRC and slave address */
			FRAME_MRC_DLC_FUN_t MRC_DLC_FUN;					/*!< MRC, DLC and FUN */
			uint8 StartADDR;									/*!< Start Address byte */
		} w_read_reg;
		uint8 write_array[LEN_READ_REG_WRITE];					/*!< write frame */
	};
	union {
		struct {
			uint16 Data[(LEN_READ_REG_DLC6_READ-LEN_READ_REG_OVHD)/2];	/*!< Data */
			uint8 SAFETY_BYTE;									/*!< CRC */
			uint8 OST;											/*!< Output status byte */
			uint8 ACK;											/*!< Acknowledge byte */
		} r_read_reg;
		uint8 read_array[LEN_READ_REG_DLC6_READ];				/*!< read frame */
	};
	bool timeout;												/*!< receive answer timeout */
} READ_REG_DLC6_FRAME_t;


/** READ_REG_DLC7_FRAME_t
 */
typedef struct {
	union {
		struct {
			FRAME_SYNC_MSG_t SYNC;								/*!< sync message */
			FRAME_CRC_ADDRESS_t CRC_REQ_S_ADD;					/*!< CRC and slave address */
			FRAME_MRC_DLC_FUN_t MRC_DLC_FUN;					/*!< MRC, DLC and FUN */
			uint8 StartADDR;									/*!< Start Address byte */
		} w_read_reg;
		uint8 write_array[LEN_READ_REG_WRITE];					/*!< write frame */
	};
	union {
		struct {
			uint16 Data[(LEN_READ_REG_DLC7_READ-LEN_READ_REG_OVHD)/2];	/*!< Data */
			uint8 SAFETY_BYTE;									/*!< CRC */
			uint8 OST;											/*!< Output status byte */
			uint8 ACK;											/*!< Acknowledge byte */
		} r_read_reg;
		uint8 read_array[LEN_READ_REG_DLC7_READ];				/*!< read frame */
	};
	bool timeout;												/*!< receive answer timeout */
} READ_REG_DLC7_FRAME_t;



typedef enum{
	ID_UART0=0,
	ID_UART1=1,
	ID_UART2=2,
}UART_ID;

typedef enum{
	Wtite_mode=1,
	ReadOst_mode=2,
	ReadReg_mode=3,

	DC_UPDATE_mode=4,
	READ_OST_mode=5,
	HWWCR_mode=6,
	PM_CHANG_mode=7,
	WRITE_REG_mode=8,
	READ_REG_mode=9,

}Frame_mode;

typedef enum{
	BUS_TLD7002_IDLE=0,
	BUS_TLD7002_SYNC,
	BUS_TLD7002_Slave_ADDR,
	BUS_TLD7002_MRC_DLC_FUN,
	BUS_TLD7002_PowerMode,
	BUS_TLD7002_PowerReser,
	BUS_TLD7002_CRC,
	BUS_TLD7002_RxData,
	BUS_TLD7002_REG_CRC1,
	BUS_TLD7002_REG_DATA_RCV,
	BUS_TLD7002_REG_DATA_CRC2,
	BUS_TLD7002_TXdata,

}BUS_STATE;


typedef struct{
	Frame_mode  mode;
	UART_ID uartid;
	BUS_STATE busstate;
	uint8 busError;
  	uint8 busRecOk;
	uint8 rcvdata[50];
	uint8 Txdata[50];

	uint8 devaddr;
	uint8 slaveaddr;
	uint8 MRC_DLC_FUN;
	uint8 PowerMode;
	uint8 Power_Reser;
	uint8 crc;
	uint8 DutyCycle[16];
	uint8 StartADDR;
	uint8 rcvdatalens;
	uint8 Txdatalens;
	uint8 RxdataCnt;
}TLD7002_UART_PAR;


typedef struct{
	uint8 uartid;
	uint8 CommunicationStatus;
	uint8 WriteStatus;
	uint8 Device_address;
	uint8 Updata_flag;
	uint8 Updata_flag_8bit;

    uint16 preDuty[1];
    uint16 NowDuty[1];
	uint16 Channel_Current[1];
	uint16 Channel_Duty[1];

	uint8 ChannelUpdata_flag[16];
	uint8 Senddata[10];
	uint8 preDuty_8bit[16];
	uint8 NowDuty_8bit[16];
}TLD7002_LPIT_PAR;

/* SYNC_BREAK - Sync break reset
 * Implementation of SYNC_BREAK has to be done externally
 */
// uint8 Writedata8bit_Channel_DPL(uint8 INDEX,uint8 duty);
// void TLD7002_Parameters_Init();
// uint8 MCLD_DC_UPDATE_8BIT_FRAME_TSET_Dynamic(uint8 UartPort,uint8 address,uint8* dc_val);
// //uint8 MCLD_DC_UPDATE_14BIT_FRAME_TSET_Dynamic(uint8 UartPort,uint8 address,uint16* dc_val);
// void MCLD_BRDC_DC_SYNC_FRAME_Dynamic(uint8 UartPort);
// void TLD7002_Delay_us(uint32 delaytime);
// uint8 TLD7002_HWCR_FRAME(uint8 UartPort,uint8 Deviceaddress);
// uint8 MCLD_Read_OST_DMA(uint8 UartPort,uint8 Deviceaddress, uint8* dc_val);
Std_ReturnType TLD7002ADevRegister(void);
#endif /* TLD7002_H_ */

/**@}*/
