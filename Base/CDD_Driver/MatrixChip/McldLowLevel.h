/**
 *  @file McldLowLevel.h
 *  @author Infineon
 *  @date 13.03.2020
 *	@brief MCLD specific low level driver implementation from Infineon Technologies AG.
 *	@note  This file includes the definitions for the MCLD hardware access layer
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/**
 * @addtogroup MCLD_LOW_LEVEL
 * @{
 */


#ifndef MCLD_LOW_LEVEL_H_
#define MCLD_LOW_LEVEL_H_


/******************************************************************************/
/*	Includes																  */
/******************************************************************************/
#include "TLD7002.h"

//#include "IfxCpu.h"
//#include "IfxScuWdt.h"
//#include "Ifx_Types.h"
//#include "../CAN/CAN.h"


/******************************************************************************/
/*	Basic Definitions for MCLD												  */
/******************************************************************************/

/** number of elements of an array of LED groups */
#define ARRAY_SIZE(array) (sizeof(array) / sizeof(*array))

#define NUM_DEVICES							 32							/**< number of MCLD devices */
#define NUM_MCLD_CH							 16							/**< number of MCLD channels */

#define LOW_BYTE_16BIT					 0x00FF							/**< low byte of a 16 bit number */
#define HIGH_BYTE_16BIT					 0xFF00							/**< high byte of a 16 bit number */
#define HIGH_BYTE_14BIT					 0x3F00							/**< high byte of a 13 bit number */

#define CH_MIN_DC_VAL						  0							/**< minimum duty cycle for 8 bit and 14 bit duty cycle configuration */
#define CH_MAX_DC_8BIT_VAL					255							/**< maximum duty cycle for 8 bit duty cycle configuration */
#define CH_MAX_DC_14BIT_VAL				  16383							/**< maximum duty cycle for 14 bit duty cycle configuration */
#define CH_MIN_DUTY_CYCLE					  0							/**< minimum channel duty-cycle */
#define CH_MAX_DUTY_CYCLE				  10000							/**< maximum channel duty-cycle (multiplied with 100 to increase accuracy )*/
#define CH_MAX_CONTROLLED_CURRENT			 75							/**< maximum controlled current in milliampere */
#define CH_MAX_SWITCHED_CURRENT				125							/**< maximum switched current in milliampere */

#define CRC8_CALC_SEED						0xFF						/**< CRC-8 (according to CRC-8-AUTOSAR and SAEJ1850) seed */
#define CRC8_CALC_GENERATOR_POLYNOM			0x1D						/**< CRC-8 (according to CRC-8-AUTOSAR and SAEJ1850) generator polynom value */
#define CRC8_CALC_XOR_VAL					0xFF						/**< CRC-8 (according to CRC-8-AUTOSAR and SAEJ1850) xor value */
#define CRC3_CALC_SEED						0x05						/**< CRC-3 seed */
#define CRC3_CALC_GENERATOR_POLYNOM			0x00						/**< CRC-3 generator polynom value */
#define CRC3_CALC_XOR_VAL					0x00						/**< CRC-3 xor value */


/** LightFuncType_t
 *  Enum for the light function for the LED's/LED group's abstracted driver.
 */
typedef enum MCLD_CH_t {
	MCLD_CH0 = 0,									/**< MCLD channel 0 */
	MCLD_CH1 = 1,									/**< MCLD channel 1 */
	MCLD_CH2 = 2,									/**< MCLD channel 2 */
	MCLD_CH3 = 3,									/**< MCLD channel 3 */
	MCLD_CH4 = 4,									/**< MCLD channel 4 */
	MCLD_CH5 = 5,									/**< MCLD channel 5 */
	MCLD_CH6 = 6,									/**< MCLD channel 6 */
	MCLD_CH7 = 7,									/**< MCLD channel 7 */
	MCLD_CH8 = 8,									/**< MCLD channel 8 */
	MCLD_CH9 = 9,									/**< MCLD channel 9 */
	MCLD_CH10 = 10,									/**< MCLD channel 10 */
	MCLD_CH11 = 11,									/**< MCLD channel 11 */
	MCLD_CH12 = 12,									/**< MCLD channel 12 */
	MCLD_CH13 = 13,									/**< MCLD channel 13 */
	MCLD_CH14 = 14,									/**< MCLD channel 14 */
	MCLD_CH15 = 15									/**< MCLD channel 15 */
} MCLD_CH_t;


/** MCLD_VAL_t
 *  Enum for result of response frame validation.
 */
typedef enum MCLD_VAL_t {
	MCLD_VAL_NO_ERROR = 0,							/**< No error detected in response frame */
	MCLD_VAL_CRC3_ERROR = 1,						/**< CRC3 error detected in response frame */
	MCLD_VAL_RC_ERROR = 2,							/**< Rolling Counter error detected in response frame */
	MCLD_VAL_CRC8_ERROR = 4							/**< CRC8 error detected at data in response frame */
} MCLD_VAL_t;


/******************************************************************************/
/*	Global Variables 														  */
/******************************************************************************/

/** store the master and slave rolling counters
  * curr_mrc[0]	 	(FRAME_SLAVE_ADDRESS_BROADCAST)		Store master rolling counter
  * curr_mrc[1]	 	(FRAME_SLAVE_ADDRESS_1)				Store slave 1 rolling counter
  * curr_mrc[2]	 	(FRAME_SLAVE_ADDRESS_2)				Store slave 2 rolling counter
  * ...				...									...
  * curr_mrc[30] 	(FRAME_SLAVE_ADDRESS_30)			Store slave 30 rolling counter
  * curr_mrc[31] 	(FRAME_SLAVE_ADDRESS_31)			Store slave 31 rolling counter
  */
extern FRAME_RC_2BIT_t curr_mrc[NUM_DEVICES];


/******************************************************************************/
/*	Global CRC lookup tables												  */
/******************************************************************************/

/* CRC3 lookup table for 5 bit value */
extern const uint8 LOOKUP_CRC3_5BIT[32];

/* CRC3 lookup table for 8 bit value */
extern const uint8 LOOKUP_CRC3_8BIT[256];


/******************************************************************************/
/* Command preparation and validation function declarations 				  */
/******************************************************************************/

extern void mcld_brdc_dc_sync_prep(BRDC_DC_SYNC_FRAME_t* frm);
extern void mcld_brdc_dc_sync_fin(BRDC_DC_SYNC_FRAME_t* frm);
extern bool mcld_dc_update_8bit_prep(DC_UPDATE_8BIT_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add);

extern bool mcld_dc_update_8bit_dlc0_prep(DC_UPDATE_8BIT_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add);

extern void mcld_dc_update_8bit_fin(DC_UPDATE_8BIT_FRAME_t* frm);
extern MCLD_VAL_t mcld_dc_update_8bit_val_resp(DC_UPDATE_8BIT_FRAME_t* frm);
extern bool mcld_dc_update_14bit_prep(DC_UPDATE_14BIT_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add);
extern void mcld_dc_update_14bit_fin(DC_UPDATE_14BIT_FRAME_t* frm);
extern MCLD_VAL_t mcld_dc_update_14bit_val_resp(DC_UPDATE_14BIT_FRAME_t* frm);
extern bool mcld_pm_change_prep(PM_CHANGE_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add);
extern void mcld_pm_change_fin(PM_CHANGE_FRAME_t* frm);
extern MCLD_VAL_t mcld_pm_change_val_resp(PM_CHANGE_FRAME_t* frm);
extern bool mcld_read_ost_prep(READ_OST_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add);
extern void mcld_read_ost_fin(READ_OST_FRAME_t* frm);
extern MCLD_VAL_t mcld_read_ost_val_resp(READ_OST_FRAME_t* frm);
extern bool mcld_hwcr_prep(HWCR_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add);
extern void mcld_hwcr_fin(HWCR_FRAME_t* frm);
extern MCLD_VAL_t mcld_hwcr_val_resp(HWCR_FRAME_t* frm);

extern bool mcld_write_reg_dlc1_prep(WRITE_REG_DLC1_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add);
extern void mcld_write_reg_dlc1_fin(WRITE_REG_DLC1_FRAME_t* frm);
extern MCLD_VAL_t mcld_write_reg_dlc1_val_resp(WRITE_REG_DLC1_FRAME_t* frm);
extern bool mcld_write_reg_dlc2_prep(WRITE_REG_DLC2_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add);
extern void mcld_write_reg_dlc2_fin(WRITE_REG_DLC2_FRAME_t* frm);
extern MCLD_VAL_t mcld_write_reg_dlc2_val_resp(WRITE_REG_DLC2_FRAME_t* frm);
extern bool mcld_write_reg_dlc3_prep(WRITE_REG_DLC3_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add);
extern void mcld_write_reg_dlc3_fin(WRITE_REG_DLC3_FRAME_t* frm);
extern MCLD_VAL_t mcld_write_reg_dlc3_val_resp(WRITE_REG_DLC3_FRAME_t* frm);
extern bool mcld_write_reg_dlc4_prep(WRITE_REG_DLC4_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add);
extern void mcld_write_reg_dlc4_fin(WRITE_REG_DLC4_FRAME_t* frm);
extern MCLD_VAL_t mcld_write_reg_dlc4_val_resp(WRITE_REG_DLC4_FRAME_t* frm);
extern bool mcld_write_reg_dlc5_prep(WRITE_REG_DLC5_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add);
extern void mcld_write_reg_dlc5_fin(WRITE_REG_DLC5_FRAME_t* frm);
extern MCLD_VAL_t mcld_write_reg_dlc5_val_resp(WRITE_REG_DLC5_FRAME_t* frm);
extern bool mcld_write_reg_dlc6_prep(WRITE_REG_DLC6_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add);
extern void mcld_write_reg_dlc6_fin(WRITE_REG_DLC6_FRAME_t* frm);
extern MCLD_VAL_t mcld_write_reg_dlc6_val_resp(WRITE_REG_DLC6_FRAME_t* frm);
extern bool mcld_write_reg_dlc7_prep(WRITE_REG_DLC7_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add);
extern void mcld_write_reg_dlc7_fin(WRITE_REG_DLC7_FRAME_t* frm);
extern MCLD_VAL_t mcld_write_reg_dlc7_val_resp(WRITE_REG_DLC7_FRAME_t* frm);

extern bool mcld_read_reg_dlc1_prep(READ_REG_DLC1_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add);
extern void mcld_read_reg_dlc1_fin(READ_REG_DLC1_FRAME_t* frm);
extern MCLD_VAL_t mcld_read_reg_dlc1_val_resp(READ_REG_DLC1_FRAME_t* frm);
extern bool mcld_read_reg_dlc2_prep(READ_REG_DLC2_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add);
extern void mcld_read_reg_dlc2_fin(READ_REG_DLC2_FRAME_t* frm);
extern MCLD_VAL_t mcld_read_reg_dlc2_val_resp(READ_REG_DLC2_FRAME_t* frm);
extern bool mcld_read_reg_dlc3_prep(READ_REG_DLC3_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add);
extern void mcld_read_reg_dlc3_fin(READ_REG_DLC3_FRAME_t* frm);
extern MCLD_VAL_t mcld_read_reg_dlc3_val_resp(READ_REG_DLC3_FRAME_t* frm);
extern bool mcld_read_reg_dlc4_prep(READ_REG_DLC4_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add);
extern void mcld_read_reg_dlc4_fin(READ_REG_DLC4_FRAME_t* frm);
extern MCLD_VAL_t mcld_read_reg_dlc4_val_resp(READ_REG_DLC4_FRAME_t* frm);
extern bool mcld_read_reg_dlc5_prep(READ_REG_DLC5_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add);
extern void mcld_read_reg_dlc5_fin(READ_REG_DLC5_FRAME_t* frm);
extern MCLD_VAL_t mcld_read_reg_dlc5_val_resp(READ_REG_DLC5_FRAME_t* frm);
extern bool mcld_read_reg_dlc6_prep(READ_REG_DLC6_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add);
extern void mcld_read_reg_dlc6_fin(READ_REG_DLC6_FRAME_t* frm);
extern MCLD_VAL_t mcld_read_reg_dlc6_val_resp(READ_REG_DLC6_FRAME_t* frm);
extern bool mcld_read_reg_dlc7_prep(READ_REG_DLC7_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add);
extern void mcld_read_reg_dlc7_fin(READ_REG_DLC7_FRAME_t* frm);
extern MCLD_VAL_t mcld_read_reg_dlc7_val_resp(READ_REG_DLC7_FRAME_t* frm);


/******************************************************************************/
/* Auxiliary function declarations 		 									  */
/******************************************************************************/

extern void mcld_init_low_level(void);
// TODO: additional reset function required
extern FRAME_RC_2BIT_t mcld_get_next_rc_val(FRAME_RC_2BIT_t mrc);
extern void mcld_calculate_crc3_master_request(FRAME_CRC_ADDRESS_t* byte_req_s_add, FRAME_MRC_DLC_FUN_t* byte_mrc_dlc_fun);
//
//
extern bool mcld_calculate_crc3_slave_response(FRAME_OUTPUT_STATUS_BYTE_t* ost_byte, FRAME_ACK_BYTE_t* ack_byte);
extern uint8 mcld_calculate_crc8_general(uint8* data_array , uint8 data_len);
extern uint8 mcld_calculate_crc8_leadbyte(uint8* data_array , uint8 data_len, uint8 lead_byte);
//extern void setChDc8BitToFrame(DC_UPDATE_8BIT_FRAME_t* updtfram, MCLD_CH_t ch, uint8 dc_val);
//extern void setChDc14BitToFrame(DC_UPDATE_14BIT_FRAME_t* updtfram, MCLD_CH_t ch, uint16 dc_val);
//extern uint8 calcChDc8BitValue(uint16 dc_perc);
//extern uint16 calcChDc14BitValue(uint16 dc_perc);
//
//
//extern void write_data_to_FTDI_ASC1(uint8* data, uint8 data_length);
//extern void start_read_from_HSLI(uint8 data_length);
//
//extern uint8 bufferIdx,ReadLength;
//extern uint8 DMA_Buffer_HSLI_Rx[80];

#endif /* MCLD_LOW_LEVEL_H_ */

//add by LL
//const uint8 LOOKUP_CRC3_5BIT[32];
//MIRROR_MID_CRC3

/**@}*/
