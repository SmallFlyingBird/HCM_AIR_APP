/**
 *  @file McldLowLevel.c
 *  @author Infineon
 *  @date 13.03.2020
 *	@brief MCLD specific low level driver implementation from Infineon Technologies AG.
 *	@note  This file includes the implementation for the MCLD hardware access layer.
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


/******************************************************************************/
/*	Includes																  */
/******************************************************************************/
//#include <DAVE.h>
#include "McldLowLevel.h"
//#include "LowLevelAccess.h"
//#include "ac780x.h"
/******************************************************************************/
/*	Global CRC lookup table definitions 									  */
/******************************************************************************/

/* CRC3 lookup table for 5 bit value */
/*
const uint8 LOOKUP_CRC3_5BIT[32] = {
	0, 1, 5, 4, 7, 6, 2, 3, 6, 7, 3, 2, 1, 0, 4, 5,
	3, 2, 6, 7, 4, 5, 1, 0, 5, 4, 0, 1, 2, 3, 7, 6
};
*/

const uint8 LOOKUP_CRC3_5BIT[32] = { 0, 1, 5, 4, 7, 6, 2, 3, 6, 7, 3, 2, 1, 0, 4, 5, 3, 2, 6, 7, 4, 5, 1, 0, 5, 4, 0, 1, 2, 3, 7, 6 };

/* CRC3 lookup table for 8 bit value */
/*
const uint8 LOOKUP_CRC3_8BIT[256] = {
	0, 3, 4, 7, 2, 1, 6, 5, 1, 2, 5, 6, 3, 0, 7, 4,
	5, 6, 1, 2, 7, 4, 3, 0, 4, 7, 0, 3, 6, 5, 2, 1,
	7, 4, 3, 0, 5, 6, 1, 2, 6, 5, 2, 1, 4, 7, 0, 3,
	2, 1, 6, 5, 0, 3, 4, 7,	3, 0, 7, 4, 1, 2, 5, 6,
	6, 5, 2, 1, 4, 7, 0, 3,	7, 4, 3, 0, 5, 6, 1, 2,
	3, 0, 7, 4, 1, 2, 5, 6,	2, 1, 6, 5, 0, 3, 4, 7,
	1, 2, 5, 6, 3, 0, 7, 4,	0, 3, 4, 7, 2, 1, 6, 5,
	4, 7, 0, 3, 6, 5, 2, 1,	5, 6, 1, 2, 7, 4, 3, 0,
	3, 0, 7, 4, 1, 2, 5, 6,	2, 1, 6, 5, 0, 3, 4, 7,
	6, 5, 2, 1, 4, 7, 0, 3,	7, 4, 3, 0, 5, 6, 1, 2,
	4, 7, 0, 3, 6, 5, 2, 1,	5, 6, 1, 2, 7, 4, 3, 0,
	1, 2, 5, 6, 3, 0, 7, 4,	0, 3, 4, 7, 2, 1, 6, 5,
	5, 6, 1, 2, 7, 4, 3, 0,	4, 7, 0, 3, 6, 5, 2, 1,
	0, 3, 4, 7, 2, 1, 6, 5,	1, 2, 5, 6, 3, 0, 7, 4,
	2, 1, 6, 5, 0, 3, 4, 7,	3, 0, 7, 4, 1, 2, 5, 6,
	7, 4, 3, 0, 5, 6, 1, 2,	6, 5, 2, 1, 4, 7, 0, 3,
};
*/
const uint8 LOOKUP_CRC3_8BIT[256] = { 0, 3, 4, 7, 2, 1, 6, 5, 1, 2, 5, 6, 3, 0, 7, 4, 5, 6, 1, 2, 7, 4, 3, 0, 4, 7, 0, 3, 6, 5, 2, 1, 7, 4, 3, 0, 5, 6, 1, 2, 6, 5, 2, 1, 4, 7, 0, 3, 2, 1, 6, 5, 0, 3, 4, 7, 3, 0, 7, 4, 1, 2, 5, 6, 6, 5, 2, 1, 4, 7, 0, 3, 7, 4, 3, 0, 5, 6, 1, 2, 3, 0, 7, 4, 1, 2, 5, 6, 2, 1, 6, 5, 0, 3, 4, 7, 1, 2, 5, 6, 3, 0, 7, 4, 0, 3, 4, 7, 2, 1, 6, 5, 4, 7, 0, 3, 6, 5, 2, 1, 5, 6, 1, 2, 7, 4, 3, 0, 3, 0, 7, 4, 1, 2, 5, 6, 2, 1, 6, 5, 0, 3, 4, 7, 6, 5, 2, 1, 4, 7, 0, 3, 7, 4, 3, 0, 5, 6, 1, 2, 4, 7, 0, 3, 6, 5, 2, 1, 5, 6, 1, 2, 7, 4, 3, 0, 1, 2, 5, 6, 3, 0, 7, 4, 0, 3, 4, 7, 2, 1, 6, 5, 5, 6, 1, 2, 7, 4, 3, 0, 4, 7, 0, 3, 6, 5, 2, 1, 0, 3, 4, 7, 2, 1, 6, 5, 1, 2, 5, 6, 3, 0, 7, 4, 2, 1, 6, 5, 0, 3, 4, 7, 3, 0, 7, 4, 1, 2, 5, 6, 7, 4, 3, 0, 5, 6, 1, 2, 6, 5, 2, 1, 4, 7, 0, 3 };

static uint8 MIRROR_MID_CRC3[8] = {0, 4, 2, 6, 1, 5, 3, 7};

//static uint8 HSLI_TX_Vector[75];
//static uint8 add_sent_byte, num_of_byte;

uint8 DMA_Buffer_HSLI_Rx[80], bufferIdx=0,ReadLength=0;

//static uint8 MIRROR_MID_CRC3[8] = {0, 4, 2, 6, 1, 5, 3, 7};

int TransmitData(uint8 *pdata, uint16 length);


/******************************************************************************/
/* Command preparation and validation function implementation 				  */
/******************************************************************************/

/** @brief Prepare a MCLD BRDC_DC_SYNC data frame
 * This functions prepares a frame by setting the sync message, address, FUN, DLC and MRC as well as resetting the CRC3.
 *
 * @param[in] BRDC_DC_SYNC_FRAME_t* pointer to frame where the CRC has to be calculated
 *
 * @return trigger reset of the execution timer [true: reset execution timer; false: don't reset execution timer]
 */
void mcld_brdc_dc_sync_prep(BRDC_DC_SYNC_FRAME_t* frm) {
	frm->w_brdc_dc_sync.SYNC = SYNC_MSG;
	frm->w_brdc_dc_sync.CRC_REQ_S_ADD.bit.Address = FRAME_SLAVE_ADDRESS_BROADCAST;
	frm->w_brdc_dc_sync.CRC_REQ_S_ADD.bit.TLDCRC = 0;											/*< CRC initially 0 */
	frm->w_brdc_dc_sync.MRC_DLC_FUN.bit.FUN = FRAME_FUN_BRDC_DC_SYNC;
	frm->w_brdc_dc_sync.MRC_DLC_FUN.bit.DLC = FRAME_DLC_0;
	frm->w_brdc_dc_sync.MRC_DLC_FUN.bit.MRC = curr_mrc[0];									/*< set MRC */
	curr_mrc[0] = mcld_get_next_rc_val(curr_mrc[0]);										/*< calculate next Master Rolling Counter */
}

/** @brief Finalize a MCLD BRDC_DC_SYNC data frame
 * This functions finalizes a frame by calculating the CRC3 for the MRC_DLC_FUN byte and
 * calculating the CRC8 for the data in order to store it in the SAFETY_BYTE.
 *
 * @param[in] BRDC_DC_SYNC_FRAME_t* pointer to frame where the CRC has to be calculated
 */
void mcld_brdc_dc_sync_fin(BRDC_DC_SYNC_FRAME_t* frm) {



	mcld_calculate_crc3_master_request(&(frm->w_brdc_dc_sync.CRC_REQ_S_ADD), &(frm->w_brdc_dc_sync.MRC_DLC_FUN));


}

/** @brief Prepare a MCLD DC_UPDATE (8 Bit) data frame
 * This functions prepares a frame by setting the sync message, address, FUN, DLC and MRC as well as resetting the CRC3.
 * Additionally it is checked, if the slave address is valid for that frame.
 *
 * @param[in] DC_UPDATE_8BIT_FRAME_t* pointer to frame where the CRC has to be calculated
 * @param[in] FRAME_SLAVE_ADDRESS_t address of slave where the frame has to be send [FRAME_SLAVE_ADDRESS_1 ... FRAME_SLAVE_ADDRESS_31]
 *
 * @return trigger reset of the execution timer [true: reset execution timer; false: don't reset execution timer]
 */
bool mcld_dc_update_8bit_prep(DC_UPDATE_8BIT_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add)
{
	bool ret_val = false;																	/*< initially return value false */
	if(add >= FRAME_SLAVE_ADDRESS_1 && add <= FRAME_SLAVE_ADDRESS_31) {
		ret_val = true;																		/*< address is valid */
		frm->w_pwm_dc_update.SYNC = SYNC_MSG;
		frm->w_pwm_dc_update.CRC_REQ_S_ADD.bit.Address = add;
		frm->w_pwm_dc_update.CRC_REQ_S_ADD.bit.TLDCRC = 0;										/*< CRC initially 0 */
		frm->w_pwm_dc_update.MRC_DLC_FUN.bit.FUN = FRAME_FUN_DC_UPDATE;
		frm->w_pwm_dc_update.MRC_DLC_FUN.bit.DLC = FRAME_DLC_4;
		frm->w_pwm_dc_update.MRC_DLC_FUN.bit.MRC = curr_mrc[0];								/*< set MRC */
		frm->timeout = false;																/*< reset timeout */
		curr_mrc[0] = mcld_get_next_rc_val(curr_mrc[0]);									/*< calculate next Master Rolling Counter */
		curr_mrc[add] = mcld_get_next_rc_val(curr_mrc[add]);								/*< calculate expected Rolling Counter for answer */
	}
	return ret_val;
}

/** @brief Prepare a MCLD DC_UPDATE (8 Bit) data frame with DLC 0
 * This functions prepares a frame by setting the sync message, address, FUN, DLC and MRC as well as resetting the CRC3.
 * This frame will be prepared with DLC 0, which means there is no payload in the frame.
 * Additionally it is checked, if the slave address is valid for that frame.
 *
 * @param[in] DC_UPDATE_8BIT_FRAME_t* pointer to frame where the CRC has to be calculated
 * @param[in] FRAME_SLAVE_ADDRESS_t address of slave where the frame has to be send [FRAME_SLAVE_ADDRESS_BROADCAST ... FRAME_SLAVE_ADDRESS_31]
 *
 * @return trigger reset of the execution timer [true: reset execution timer; false: don't reset execution timer]
 */


bool mcld_dc_update_8bit_dlc0_prep(DC_UPDATE_8BIT_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add) {
	bool ret_val = false;																	/*< initially return value false */
	if(add <= FRAME_SLAVE_ADDRESS_31) {
		ret_val = true;																		/*< address is valid */
		frm->w_pwm_dc_update.SYNC = SYNC_MSG;
		frm->w_pwm_dc_update.CRC_REQ_S_ADD.bit.Address = add;
		frm->w_pwm_dc_update.CRC_REQ_S_ADD.bit.TLDCRC = 0;										/*< CRC initially 0 */
		frm->w_pwm_dc_update.MRC_DLC_FUN.bit.FUN = FRAME_FUN_DC_UPDATE;
		frm->w_pwm_dc_update.MRC_DLC_FUN.bit.DLC = FRAME_DLC_0;
		frm->w_pwm_dc_update.MRC_DLC_FUN.bit.MRC = curr_mrc[0];								/*< set MRC */
		frm->timeout = false;																/*< reset timeout */
		curr_mrc[0] = mcld_get_next_rc_val(curr_mrc[0]);									/*< calculate next Master Rolling Counter */
		if(add != FRAME_SLAVE_ADDRESS_BROADCAST) {											/*< only for messages which are not broadcast messages (would lead to two times increasing MRC) */
			curr_mrc[add] = mcld_get_next_rc_val(curr_mrc[add]);							/*< calculate expected Rolling Counter for answer */
		}
	}
	return ret_val;
}

/** @brief Finalize a MCLD DC_UPDATE (8 Bit) data frame
 * This functions finalizes a frame by calculating the CRC3 for the MRC_DLC_FUN byte and
 * calculating the CRC8 for the data in order to store it in the SAFETY_BYTE.
 *
 * @param[in] DC_UPDATE_8BIT_FRAME_t* pointer to frame where the CRC has to be calculated
 */
void mcld_dc_update_8bit_fin(DC_UPDATE_8BIT_FRAME_t* frm) {
	mcld_calculate_crc3_master_request(&(frm->w_pwm_dc_update.CRC_REQ_S_ADD), &(frm->w_pwm_dc_update.MRC_DLC_FUN));

	/* Calculate CRC8 for SAFETY_BYTE from POS_DC_UPDATE_8BIT_DCOUT0 to POS_DC_UPDATE_8BIT_DCOUT15 */
	frm->w_pwm_dc_update.SAFETY_BYTE = mcld_calculate_crc8_general(&(frm->write_array[POS_DC_UPDATE_8BIT_DCOUT0]),POS_DC_UPDATE_8BIT_SAFETY_BYTE - POS_DC_UPDATE_8BIT_DCOUT0);											/*< CRC will be written in SAFETY_BYTE */
}

/** @brief Validate the slave response of a MCLD DC_UPDATE (8 Bit) data frame
 * This functions validates the slave response of a frame by checking for a CRC3 error or rolling counter error.
 *
 * @param[in] DC_UPDATE_8BIT_FRAME_t* pointer to frame where the CRC has to be calculated
 *
 * @return detected error in validation [MCLD_VAL_NO_ERROR: no error detected; MCLD_VAL_CRC3_ERROR: CRC3 error in ACK_BYTE ; MCLD_VAL_RC_ERROR: rolling counter error]
 */
MCLD_VAL_t mcld_dc_update_8bit_val_resp(DC_UPDATE_8BIT_FRAME_t* frm) {
	/* check for CRC3 error */
	if(mcld_calculate_crc3_slave_response((FRAME_OUTPUT_STATUS_BYTE_t*)&(frm->r_pwm_dc_update.OST), (FRAME_ACK_BYTE_t*)&(frm->r_pwm_dc_update.ACK))) {
		return MCLD_VAL_CRC3_ERROR;
	}
	/* check for Rolling Counter Error */
	FRAME_ACK_BYTE_t temp_ack;
	temp_ack.ACK_BYTE = frm->r_pwm_dc_update.ACK;											/*< store ACK byte temporary */
	if(temp_ack.bit.RC != curr_mrc[frm->w_pwm_dc_update.CRC_REQ_S_ADD.bit.Address]) {
		return MCLD_VAL_RC_ERROR;
	}
	/* no error detected */
	return MCLD_VAL_NO_ERROR;
}

/** @brief Prepare a MCLD DC_UPDATE (14 Bit) data frame
 * This functions prepares a frame by setting the sync message, address, FUN, DLC and MRC as well as resetting the CRC3.
 * Additionally it is checked, if the slave address is valid for that frame.
 *
 * @param[in] DC_UPDATE_14BIT_FRAME_t* pointer to frame where the CRC has to be calculated
 * @param[in] FRAME_SLAVE_ADDRESS_t address of slave where the frame has to be send [FRAME_SLAVE_ADDRESS_1 ... FRAME_SLAVE_ADDRESS_31]
 *
 * @return trigger reset of the execution timer [true: reset execution timer; false: don't reset execution timer]
 */
bool mcld_dc_update_14bit_prep(DC_UPDATE_14BIT_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add) {
	bool ret_val = false;																	/*< initially return value false */
	if(add >= FRAME_SLAVE_ADDRESS_1 && add <= FRAME_SLAVE_ADDRESS_31) {
		ret_val = true;																		/*< address is valid */
		frm->w_pwm_dc_update.SYNC = SYNC_MSG;
		frm->w_pwm_dc_update.CRC_REQ_S_ADD.bit.Address = add;
		frm->w_pwm_dc_update.CRC_REQ_S_ADD.bit.TLDCRC = 0;										/*< CRC initially 0 */
		frm->w_pwm_dc_update.MRC_DLC_FUN.bit.FUN = FRAME_FUN_DC_UPDATE;
		frm->w_pwm_dc_update.MRC_DLC_FUN.bit.DLC = FRAME_DLC_6;
		frm->w_pwm_dc_update.MRC_DLC_FUN.bit.MRC = curr_mrc[0];								/*< set MRC */
		frm->timeout = false;																/*< reset timeout */
		curr_mrc[0] = mcld_get_next_rc_val(curr_mrc[0]);									/*< calculate next Master Rolling Counter */
		curr_mrc[add] = mcld_get_next_rc_val(curr_mrc[add]);								/*< calculate expected Rolling Counter for answer */
	}
	return ret_val;
}

/** @brief Finalize a MCLD DC_UPDATE (14 Bit) data frame
 * This functions finalizes a frame by calculating the CRC3 for the MRC_DLC_FUN byte and
 * calculating the CRC8 for the data in order to store it in the SAFETY_BYTE.
 *
 * @param[in] DC_UPDATE_14BIT_FRAME_t* pointer to frame where the CRC has to be calculated
 */
void mcld_dc_update_14bit_fin(DC_UPDATE_14BIT_FRAME_t* frm) {
	mcld_calculate_crc3_master_request(&(frm->w_pwm_dc_update.CRC_REQ_S_ADD), &(frm->w_pwm_dc_update.MRC_DLC_FUN));

	/* from POS_DC_UPDATE_14BIT_DCOUT0_HB to POS_DC_UPDATE_14BIT_DCOUT15_LB */
	frm->w_pwm_dc_update.SAFETY_BYTE = mcld_calculate_crc8_general(&(frm->write_array[POS_DC_UPDATE_14BIT_DCOUT0_HB]),POS_DC_UPDATE_14BIT_SAFETY_BYTE - POS_DC_UPDATE_14BIT_DCOUT0_HB);
}

/** @brief Validate the slave response of a MCLD DC_UPDATE (14 Bit) data frame
 * This functions validates the slave response of a frame by checking for a CRC3 error or rolling counter error.
 *
 * @param[in] DC_UPDATE_14BIT_FRAME_t* pointer to frame where the CRC has to be calculated
 *
 * @return detected error in validation [MCLD_VAL_NO_ERROR: no error detected; MCLD_VAL_CRC3_ERROR: CRC3 error in ACK_BYTE ; MCLD_VAL_RC_ERROR: rolling counter error]
 */
MCLD_VAL_t mcld_dc_update_14bit_val_resp(DC_UPDATE_14BIT_FRAME_t* frm) {
	/* check for CRC3 error */
	if(mcld_calculate_crc3_slave_response( (FRAME_OUTPUT_STATUS_BYTE_t*) &(frm->r_pwm_dc_update.OST), (FRAME_ACK_BYTE_t*) &(frm->r_pwm_dc_update.ACK))) {
		return MCLD_VAL_CRC3_ERROR;
	}
	/* check for Rolling Counter Error */
	FRAME_ACK_BYTE_t temp_ack;
	temp_ack.ACK_BYTE = frm->r_pwm_dc_update.ACK;											/*< store ACK byte temporary */
	if(temp_ack.bit.RC != curr_mrc[frm->w_pwm_dc_update.CRC_REQ_S_ADD.bit.Address]) {
		return MCLD_VAL_RC_ERROR;
	}
	/* no error detected */
	return MCLD_VAL_NO_ERROR;
}

/** @brief Prepare a MCLD PM_CHANGE data frame
 * This functions prepares a frame by setting the sync message, address, FUN, DLC and MRC as well as resetting the CRC3.
 * Additionally it is checked, if the slave address is valid for that frame.
 *
 * @param[in] PM_CHANGE_FRAME_t* pointer to frame where the CRC has to be calculated
 * @param[in] FRAME_SLAVE_ADDRESS_t address of slave where the frame has to be send [FRAME_SLAVE_ADDRESS_BROADCAST ... FRAME_SLAVE_ADDRESS_31]
 *
 * @return trigger reset of the execution timer [true: reset execution timer; false: don't reset execution timer]
 */
bool mcld_pm_change_prep(PM_CHANGE_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add) {
	bool ret_val = false;																	/*< initially return value false */
	if(add <= FRAME_SLAVE_ADDRESS_31) {
		ret_val = true;																		/*< address is valid */
		frm->w_power_mode_change.SYNC = SYNC_MSG;
		frm->w_power_mode_change.CRC_REQ_S_ADD.bit.Address = add;
		frm->w_power_mode_change.CRC_REQ_S_ADD.bit.TLDCRC = 0;									/*< CRC initially 0 */
		frm->w_power_mode_change.MRC_DLC_FUN.bit.FUN = FRAME_FUN_PM_CHANGE;
		frm->w_power_mode_change.MRC_DLC_FUN.bit.DLC = FRAME_DLC_1;
		frm->w_power_mode_change.MRC_DLC_FUN.bit.MRC = curr_mrc[0];							/*< set MRC */
		frm->w_power_mode_change.RESERVED = RES_BYTE;										/*< set RESERVED to 0 */
		frm->w_power_mode_change.PM_CHANGE &= ~POWER_MODE_CHANGE_RESERVED_MSK;				/*< set RES of POWER_MODE_CHANGE byte to 0 */
		frm->timeout = false;																/*< reset timeout */
		curr_mrc[0] = mcld_get_next_rc_val(curr_mrc[0]);									/*< calculate next Master Rolling Counter */
		if(add != FRAME_SLAVE_ADDRESS_BROADCAST) {											/*< only for messages which are not broadcast messages (would lead to two times increasing MRC) */
			curr_mrc[add] = mcld_get_next_rc_val(curr_mrc[add]);							/*< calculate expected Rolling Counter for answer */
		}
	}
	return ret_val;
}

/** @brief Finalize a MCLD PM_CHANGE data frame
 * This functions finalizes a frame by calculating the CRC3 for the MRC_DLC_FUN byte and
 * calculating the CRC8 for the data in order to store it in the SAFETY_BYTE.
 *
 * @param[in] PM_CHANGE_FRAME_t* pointer to frame where the CRC has to be calculated
 */
void mcld_pm_change_fin(PM_CHANGE_FRAME_t* frm) {
	mcld_calculate_crc3_master_request(&(frm->w_power_mode_change.CRC_REQ_S_ADD), &(frm->w_power_mode_change.MRC_DLC_FUN));


	/* from POS_PM_CHANGE_POWER_MODE to POS_PM_CHANGE_RES (0x00) */
	frm->w_power_mode_change.SAFETY_BYTE = mcld_calculate_crc8_general(&(frm->write_array[POS_PM_CHANGE_POWER_MODE]),POS_PM_CHANGE_SAFETY_BYTE - POS_PM_CHANGE_POWER_MODE);
}

/** @brief Validate the slave response of a MCLD PM_CHANGE data frame
 * This functions validates the slave response of a frame by checking for a CRC3 error or rolling counter error.
 *
 * @param[in] PM_CHANGE_FRAME_t* pointer to frame where the CRC has to be calculated
 *
 * @return detected error in validation [MCLD_VAL_NO_ERROR: no error detected; MCLD_VAL_CRC3_ERROR: CRC3 error in ACK_BYTE ; MCLD_VAL_RC_ERROR: rolling counter error]
 */
MCLD_VAL_t mcld_pm_change_val_resp(PM_CHANGE_FRAME_t* frm) {
	/* check for CRC3 error */
	if(mcld_calculate_crc3_slave_response(&(frm->r_power_mode_change.OST), &(frm->r_power_mode_change.ACK))) {
		return MCLD_VAL_CRC3_ERROR;
	}
	/* check for Rolling Counter Error */
	FRAME_ACK_BYTE_t temp_ack;
	temp_ack.ACK_BYTE = frm->r_power_mode_change.ACK;										/*< store ACK byte temporary */
	if(temp_ack.bit.RC != curr_mrc[frm->w_power_mode_change.CRC_REQ_S_ADD.bit.Address]) {
		return MCLD_VAL_RC_ERROR;
	}
	/* no error detected */
	return MCLD_VAL_NO_ERROR;
}

/** @brief Prepare a MCLD READ_OST data frame
 * This functions prepares a frame by setting the sync message, address, FUN, DLC and MRC as well as resetting the CRC3.
 * Additionally it is checked, if the slave address is valid for that frame.
 *
 * @param[in] READ_OST_FRAME_t* pointer to frame where the CRC has to be calculated
 * @param[in] FRAME_SLAVE_ADDRESS_t address of slave where the frame has to be send [FRAME_SLAVE_ADDRESS_1 ... FRAME_SLAVE_ADDRESS_31]
 *
 * @return trigger reset of the execution timer [true: reset execution timer; false: don't reset execution timer]
 */
bool mcld_read_ost_prep(READ_OST_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add) {
	bool ret_val = false;																	/*< initially return value false */
	if(add >= FRAME_SLAVE_ADDRESS_1 && add <= FRAME_SLAVE_ADDRESS_31) {
		ret_val = true;																		/*< address is valid */
		frm->w_read_output_status.SYNC = SYNC_MSG;
		frm->w_read_output_status.CRC_REQ_S_ADD.bit.Address = add;
		frm->w_read_output_status.CRC_REQ_S_ADD.bit.TLDCRC = 0;								/*< CRC initially 0 */
		frm->w_read_output_status.MRC_DLC_FUN.bit.FUN = FRAME_FUN_READ_OST;
		frm->w_read_output_status.MRC_DLC_FUN.bit.DLC = FRAME_DLC_4;
		frm->w_read_output_status.MRC_DLC_FUN.bit.MRC = curr_mrc[0];						/*< set MRC */
		frm->timeout = false;																/*< reset timeout */
		curr_mrc[0] = mcld_get_next_rc_val(curr_mrc[0]);									/*< calculate next Master Rolling Counter */
		curr_mrc[add] = mcld_get_next_rc_val(curr_mrc[add]);								/*< calculate expected Rolling Counter for answer */
	}
	return ret_val;
}

/** @brief Finalize a MCLD READ_OST data frame
 * This functions finalizes a frame by calculating the CRC3 for the MRC_DLC_FUN byte and
 * calculating the CRC8 for the data in order to store it in the SAFETY_BYTE.
 *
 * @param[in] READ_OST_FRAME_t* pointer to frame where the CRC has to be calculated
 */
void mcld_read_ost_fin(READ_OST_FRAME_t* frm) {
	mcld_calculate_crc3_master_request(&(frm->w_read_output_status.CRC_REQ_S_ADD), &(frm->w_read_output_status.MRC_DLC_FUN));
}

/** @brief Validate the slave response of a READ_OST PM_CHANGE data frame
 * This functions validates the slave response of a frame by checking for a CRC3 error or rolling counter error.
 *
 * @param[in] READ_OST_FRAME_t* pointer to frame where the CRC has to be calculated
 *
 * @return detected error in validation [MCLD_VAL_NO_ERROR: no error detected; MCLD_VAL_CRC3_ERROR: CRC3 error in ACK_BYTE; MCLD_VAL_RC_ERROR: rolling counter error; MCLD_VAL_CRC8_ERROR: CRC8 error in DATA; ]
 */
MCLD_VAL_t mcld_read_ost_val_resp(READ_OST_FRAME_t* frm) {
	uint8 crc8_data_val = 0;
	/* from POS_READ_OST_OSB_OUT0 to POS_READ_OST_OSB_OUT15 */
	crc8_data_val = mcld_calculate_crc8_general(&(frm->write_array[POS_READ_OST_OSB_OUT0]),POS_READ_OST_SAFETY_BYTE - POS_READ_OST_OSB_OUT0);

	/* check for CRC3 error */
	if(mcld_calculate_crc3_slave_response(&(frm->r_read_output_status.OST), &(frm->r_read_output_status.ACK))) {
		return MCLD_VAL_CRC3_ERROR;
	}
	/* check for Rolling Counter Error */
	FRAME_ACK_BYTE_t temp_ack;
	temp_ack.ACK_BYTE = frm->r_read_output_status.ACK;										/*< store ACK byte temporary */
	if(temp_ack.bit.RC != curr_mrc[frm->w_read_output_status.CRC_REQ_S_ADD.bit.Address]) {
		return MCLD_VAL_RC_ERROR;
	}
	/* check for CRC8 error of data */
	if(crc8_data_val != frm->r_read_output_status.SAFETY_BYTE) {
		return MCLD_VAL_CRC8_ERROR;
	}
	/* no error detected */
	return MCLD_VAL_NO_ERROR;
}

/** @brief Prepare a MCLD HWCR data frame
 * This functions prepares a frame by setting the sync message, address, FUN, DLC and MRC as well as resetting the CRC3.
 * Additionally it is checked, if the slave address is valid for that frame.
 *
 * @param[in] HWCR_FRAME_t* pointer to frame where the CRC has to be calculated
 * @param[in] FRAME_SLAVE_ADDRESS_t address of slave where the frame has to be send [FRAME_SLAVE_ADDRESS_BROADCAST ... FRAME_SLAVE_ADDRESS_31]
 *
 * @return trigger reset of the execution timer [true: reset execution timer; false: don't reset execution timer]
 */
bool mcld_hwcr_prep(HWCR_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add) {
	bool ret_val = false;																	/*< initially return value false */
	if(add <= FRAME_SLAVE_ADDRESS_31) {
		ret_val = true;																		/*< address is valid */
		frm->w_hardware_control.SYNC = SYNC_MSG;
		frm->w_hardware_control.CRC_REQ_S_ADD.bit.Address = add;
		frm->w_hardware_control.CRC_REQ_S_ADD.bit.TLDCRC = 0;									/*< CRC initially 0 */
		frm->w_hardware_control.MRC_DLC_FUN.bit.FUN = FRAME_FUN_HWCR;
		frm->w_hardware_control.MRC_DLC_FUN.bit.DLC = FRAME_DLC_3;
		frm->w_hardware_control.MRC_DLC_FUN.bit.MRC = curr_mrc[0];							/*< set MRC */
		frm->timeout = false;																/*< reset timeout */
		curr_mrc[0] = mcld_get_next_rc_val(curr_mrc[0]);									/*< calculate next Master Rolling Counter */
		if(add != FRAME_SLAVE_ADDRESS_BROADCAST) {											/*< only for messages which are not broadcast messages (would lead to two times increasing MRC) */
			curr_mrc[add] = mcld_get_next_rc_val(curr_mrc[add]);							/*< calculate expected Rolling Counter for answer */
		}
	}
	return ret_val;
}

/** @brief Finalize a MCLD HWCR data frame
 * This functions finalizes a frame by calculating the CRC3 for the MRC_DLC_FUN byte and
 * calculating the CRC8 for the data in order to store it in the SAFETY_BYTE.
 *
 * @param[in] HWCR_FRAME_t* pointer to frame where the CRC has to be calculated
 */
void mcld_hwcr_fin(HWCR_FRAME_t* frm) {
	mcld_calculate_crc3_master_request(&(frm->w_hardware_control.CRC_REQ_S_ADD), &(frm->w_hardware_control.MRC_DLC_FUN));

	/* from POS_HWCR_RESET_OL_1 to POS_HWCR_RESET_STATUS */
	frm->w_hardware_control.SAFETY_BYTE = mcld_calculate_crc8_general(&(frm->write_array[POS_HWCR_RESET_OL_HB]),POS_HWCR_SAFETY_BYTE - POS_HWCR_RESET_OL_HB);
}

/** @brief Validate the slave response of a MCLD HWCR data frame
 * This functions validates the slave response of a frame by checking for a CRC3 error or rolling counter error.
 *
 * @param[in] HWCR_FRAME_t* pointer to frame where the CRC has to be calculated
 *
 * @return detected error in validation [MCLD_VAL_NO_ERROR: no error detected; MCLD_VAL_CRC3_ERROR: CRC3 error in ACK_BYTE ; MCLD_VAL_RC_ERROR: rolling counter error]
 */
MCLD_VAL_t mcld_hwcr_val_resp(HWCR_FRAME_t* frm) {
	/* check for CRC3 error */
	if(mcld_calculate_crc3_slave_response(&(frm->r_hardware_control.OST), &(frm->r_hardware_control.ACK))) {
		return MCLD_VAL_CRC3_ERROR;
	}
	/* check for Rolling Counter Error */
	FRAME_ACK_BYTE_t temp_ack;
	temp_ack.ACK_BYTE = frm->r_hardware_control.ACK;										/*< store ACK byte temporary */
	if(temp_ack.bit.RC != curr_mrc[frm->w_hardware_control.CRC_REQ_S_ADD.bit.Address]) {
		return MCLD_VAL_RC_ERROR;
	}
	/* no error detected */
	return MCLD_VAL_NO_ERROR;
}

/** @brief Prepare a MCLD WRITE_REG_DLC1 data frame
 * This functions prepares a frame by setting the sync message, address, FUN, DLC and MRC as well as resetting the CRC3.
 * Additionally it is checked, if the slave address is valid for that frame.
 *
 * @param[in] WRITE_REG_DLC1_FRAME_t* pointer to frame where the CRC has to be calculated
 * @param[in] FRAME_SLAVE_ADDRESS_t address of slave where the frame has to be send [FRAME_SLAVE_ADDRESS_BROADCAST ... FRAME_SLAVE_ADDRESS_31]
 *
 * @return trigger reset of the execution timer [true: reset execution timer; false: don't reset execution timer]
 */
bool mcld_write_reg_dlc1_prep(WRITE_REG_DLC1_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add) {
	bool ret_val = false;																	/*< initially return value false */
	if(add <= FRAME_SLAVE_ADDRESS_31) {
		ret_val = true;																		/*< address is valid */
		frm->w_write_reg.SYNC = SYNC_MSG;
		frm->w_write_reg.CRC_REQ_S_ADD.bit.Address = add;
		frm->w_write_reg.CRC_REQ_S_ADD.bit.TLDCRC = 0;											/*< CRC initially 0 */
		frm->w_write_reg.MRC_DLC_FUN.bit.FUN = FRAME_FUN_WRITE_REG;
		frm->w_write_reg.MRC_DLC_FUN.bit.DLC = FRAME_DLC_1;
		frm->w_write_reg.MRC_DLC_FUN.bit.MRC = curr_mrc[0];									/*< set MRC */
		frm->timeout = false;																/*< reset timeout */
		curr_mrc[0] = mcld_get_next_rc_val(curr_mrc[0]);									/*< calculate next Master Rolling Counter */
		if(add != FRAME_SLAVE_ADDRESS_BROADCAST) {											/*< only for messages which are not broadcast messages (would lead to two times increasing MRC) */
			curr_mrc[add] = mcld_get_next_rc_val(curr_mrc[add]);							/*< calculate expected Rolling Counter for answer */
		}
	}
	return ret_val;
}

/** @brief Finalize a MCLD WRITE_REG_DLC1 data frame
 * This functions finalizes a frame by calculating the CRC3 for the MRC_DLC_FUN byte and
 * calculating the CRC8 for the data in order to store it in the SAFETY_BYTE.
 *
 * @param[in] WRITE_REG_DLC1_FRAME_t* pointer to frame where the CRC has to be calculated
 */
void mcld_write_reg_dlc1_fin(WRITE_REG_DLC1_FRAME_t* frm) {
	mcld_calculate_crc3_master_request(&(frm->w_write_reg.CRC_REQ_S_ADD), &(frm->w_write_reg.MRC_DLC_FUN));

	/* from POS_WRITE_REG_DATA0_HB to POS_WRITE_REG_DLC1_SAFETY_BYTE-1 */
	frm->w_write_reg.SAFETY_BYTE = mcld_calculate_crc8_general(&(frm->write_array[POS_WRITE_REG_START_ADD]),POS_WRITE_REG_DLC1_SAFETY_BYTE - POS_WRITE_REG_START_ADD);
}

/** @brief Validate the slave response of a MCLD WRITE_REG_DLC1 data frame
 * This functions validates the slave response of a frame by checking for a CRC3 error or rolling counter error.
 *
 * @param[in] WRITE_REG_DLC1_FRAME_t* pointer to frame where the CRC has to be calculated
 *
 * @return detected error in validation [MCLD_VAL_NO_ERROR: no error detected; MCLD_VAL_CRC3_ERROR: CRC3 error in ACK_BYTE ; MCLD_VAL_RC_ERROR: rolling counter error]
 */
MCLD_VAL_t mcld_write_reg_dlc1_val_resp(WRITE_REG_DLC1_FRAME_t* frm) {
	/* check for CRC3 error */
	if(mcld_calculate_crc3_slave_response(&(frm->r_write_reg.OST), &(frm->r_write_reg.ACK))) {
		return MCLD_VAL_CRC3_ERROR;
	}
	/* check for Rolling Counter Error */
	FRAME_ACK_BYTE_t temp_ack;
	temp_ack.ACK_BYTE = frm->r_write_reg.ACK;												/*< store ACK byte temporary */
	if(temp_ack.bit.RC != curr_mrc[frm->w_write_reg.CRC_REQ_S_ADD.bit.Address]) {
		return MCLD_VAL_RC_ERROR;
	}
	/* no error detected */
	return MCLD_VAL_NO_ERROR;
}

/** @brief Prepare a MCLD WRITE_REG_DLC2 data frame
 * This functions prepares a frame by setting the sync message, address, FUN, DLC and MRC as well as resetting the CRC3.
 * Additionally it is checked, if the slave address is valid for that frame.
 *
 * @param[in] WRITE_REG_DLC2_FRAME_t* pointer to frame where the CRC has to be calculated
 * @param[in] FRAME_SLAVE_ADDRESS_t address of slave where the frame has to be send [FRAME_SLAVE_ADDRESS_BROADCAST ... FRAME_SLAVE_ADDRESS_31]
 *
 * @return trigger reset of the execution timer [true: reset execution timer; false: don't reset execution timer]
 */
bool mcld_write_reg_dlc2_prep(WRITE_REG_DLC2_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add) {
	bool ret_val = false;																	/*< initially return value false */
	if(add <= FRAME_SLAVE_ADDRESS_31) {
		ret_val = true;																		/*< address is valid */
		frm->w_write_reg.SYNC = SYNC_MSG;
		frm->w_write_reg.CRC_REQ_S_ADD.bit.Address = add;
		frm->w_write_reg.CRC_REQ_S_ADD.bit.TLDCRC = 0;											/*< CRC initially 0 */
		frm->w_write_reg.MRC_DLC_FUN.bit.FUN = FRAME_FUN_WRITE_REG;
		frm->w_write_reg.MRC_DLC_FUN.bit.DLC = FRAME_DLC_2;
		frm->w_write_reg.MRC_DLC_FUN.bit.MRC = curr_mrc[0];									/*< set MRC */
		frm->timeout = false;																/*< reset timeout */
		curr_mrc[0] = mcld_get_next_rc_val(curr_mrc[0]);									/*< calculate next Master Rolling Counter */
		if(add != FRAME_SLAVE_ADDRESS_BROADCAST) {											/*< only for messages which are not broadcast messages (would lead to two times increasing MRC) */
			curr_mrc[add] = mcld_get_next_rc_val(curr_mrc[add]);							/*< calculate expected Rolling Counter for answer */
		}
	}
	return ret_val;
}

/** @brief Finalize a MCLD WRITE_REG_DLC2 data frame
 * This functions finalizes a frame by calculating the CRC3 for the MRC_DLC_FUN byte and
 * calculating the CRC8 for the data in order to store it in the SAFETY_BYTE.
 *
 * @param[in] WRITE_REG_DLC2_FRAME_t* pointer to frame where the CRC has to be calculated
 */
void mcld_write_reg_dlc2_fin(WRITE_REG_DLC2_FRAME_t* frm) {
	mcld_calculate_crc3_master_request(&(frm->w_write_reg.CRC_REQ_S_ADD), &(frm->w_write_reg.MRC_DLC_FUN));

	/* from POS_WRITE_REG_DATA0_HB to POS_WRITE_REG_DLC2_SAFETY_BYTE-1 */
	frm->w_write_reg.SAFETY_BYTE = mcld_calculate_crc8_general(&(frm->write_array[POS_WRITE_REG_START_ADD]),POS_WRITE_REG_DLC2_SAFETY_BYTE - POS_WRITE_REG_START_ADD);
}

/** @brief Validate the slave response of a MCLD WRITE_REG_DLC2 data frame
 * This functions validates the slave response of a frame by checking for a CRC3 error or rolling counter error.
 *
 * @param[in] WRITE_REG_DLC2_FRAME_t* pointer to frame where the CRC has to be calculated
 *
 * @return detected error in validation [MCLD_VAL_NO_ERROR: no error detected; MCLD_VAL_CRC3_ERROR: CRC3 error in ACK_BYTE ; MCLD_VAL_RC_ERROR: rolling counter error]
 */
MCLD_VAL_t mcld_write_reg_dlc2_val_resp(WRITE_REG_DLC2_FRAME_t* frm) {
	/* check for CRC3 error */
	if(mcld_calculate_crc3_slave_response(&(frm->r_write_reg.OST), &(frm->r_write_reg.ACK))) {
		return MCLD_VAL_CRC3_ERROR;
	}
	/* check for Rolling Counter Error */
	FRAME_ACK_BYTE_t temp_ack;
	temp_ack.ACK_BYTE = frm->r_write_reg.ACK;												/*< store ACK byte temporary */
	if(temp_ack.bit.RC != curr_mrc[frm->w_write_reg.CRC_REQ_S_ADD.bit.Address]) {
		return MCLD_VAL_RC_ERROR;
	}
	/* no error detected */
	return MCLD_VAL_NO_ERROR;
}

/** @brief Prepare a MCLD WRITE_REG_DLC3 data frame
 * This functions prepares a frame by setting the sync message, address, FUN, DLC and MRC as well as resetting the CRC3.
 * Additionally it is checked, if the slave address is valid for that frame.
 *
 * @param[in] WRITE_REG_DLC3_FRAME_t* pointer to frame where the CRC has to be calculated
 * @param[in] FRAME_SLAVE_ADDRESS_t address of slave where the frame has to be send [FRAME_SLAVE_ADDRESS_BROADCAST ... FRAME_SLAVE_ADDRESS_31]
 *
 * @return trigger reset of the execution timer [true: reset execution timer; false: don't reset execution timer]
 */
bool mcld_write_reg_dlc3_prep(WRITE_REG_DLC3_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add) {
	bool ret_val = false;																	/*< initially return value false */
	if(add <= FRAME_SLAVE_ADDRESS_31) {
		ret_val = true;																		/*< address is valid */
		frm->w_write_reg.SYNC = SYNC_MSG;
		frm->w_write_reg.CRC_REQ_S_ADD.bit.Address = add;
		frm->w_write_reg.CRC_REQ_S_ADD.bit.TLDCRC = 0;											/*< CRC initially 0 */
		frm->w_write_reg.MRC_DLC_FUN.bit.FUN = FRAME_FUN_WRITE_REG;
		frm->w_write_reg.MRC_DLC_FUN.bit.DLC = FRAME_DLC_3;
		frm->w_write_reg.MRC_DLC_FUN.bit.MRC = curr_mrc[0];									/*< set MRC */
		frm->timeout = false;																/*< reset timeout */
		curr_mrc[0] = mcld_get_next_rc_val(curr_mrc[0]);									/*< calculate next Master Rolling Counter */
		if(add != FRAME_SLAVE_ADDRESS_BROADCAST) {											/*< only for messages which are not broadcast messages (would lead to two times increasing MRC) */
			curr_mrc[add] = mcld_get_next_rc_val(curr_mrc[add]);							/*< calculate expected Rolling Counter for answer */
		}
	}
	return ret_val;
}

/** @brief Finalize a MCLD WRITE_REG_DLC3 data frame
 * This functions finalizes a frame by calculating the CRC3 for the MRC_DLC_FUN byte and
 * calculating the CRC8 for the data in order to store it in the SAFETY_BYTE.
 *
 * @param[in] WRITE_REG_DLC3_FRAME_t* pointer to frame where the CRC has to be calculated
 */
void mcld_write_reg_dlc3_fin(WRITE_REG_DLC3_FRAME_t* frm) {
	mcld_calculate_crc3_master_request(&(frm->w_write_reg.CRC_REQ_S_ADD), &(frm->w_write_reg.MRC_DLC_FUN));

	/* from POS_WRITE_REG_DATA0_HB to POS_WRITE_REG_DLC3_SAFETY_BYTE-1 */
	frm->w_write_reg.SAFETY_BYTE = mcld_calculate_crc8_general(&(frm->write_array[POS_WRITE_REG_START_ADD]),POS_WRITE_REG_DLC3_SAFETY_BYTE - POS_WRITE_REG_START_ADD);
}

/** @brief Validate the slave response of a MCLD WRITE_REG_DLC3 data frame
 * This functions validates the slave response of a frame by checking for a CRC3 error or rolling counter error.
 *
 * @param[in] WRITE_REG_DLC3_FRAME_t* pointer to frame where the CRC has to be calculated
 *
 * @return detected error in validation [MCLD_VAL_NO_ERROR: no error detected; MCLD_VAL_CRC3_ERROR: CRC3 error in ACK_BYTE ; MCLD_VAL_RC_ERROR: rolling counter error]
 */
MCLD_VAL_t mcld_write_reg_dlc3_val_resp(WRITE_REG_DLC3_FRAME_t* frm) {
	/* check for CRC3 error */
	if(mcld_calculate_crc3_slave_response(&(frm->r_write_reg.OST), &(frm->r_write_reg.ACK))) {
		return MCLD_VAL_CRC3_ERROR;
	}
	/* check for Rolling Counter Error */
	FRAME_ACK_BYTE_t temp_ack;
	temp_ack.ACK_BYTE = frm->r_write_reg.ACK;												/*< store ACK byte temporary */
	if(temp_ack.bit.RC != curr_mrc[frm->w_write_reg.CRC_REQ_S_ADD.bit.Address]) {
		return MCLD_VAL_RC_ERROR;
	}
	/* no error detected */
	return MCLD_VAL_NO_ERROR;
}

/** @brief Prepare a MCLD WRITE_REG_DLC4 data frame
 * This functions prepares a frame by setting the sync message, address, FUN, DLC and MRC as well as resetting the CRC3.
 * Additionally it is checked, if the slave address is valid for that frame.
 *
 * @param[in] WRITE_REG_DLC4_FRAME_t* pointer to frame where the CRC has to be calculated
 * @param[in] FRAME_SLAVE_ADDRESS_t address of slave where the frame has to be send [FRAME_SLAVE_ADDRESS_BROADCAST ... FRAME_SLAVE_ADDRESS_31]
 *
 * @return trigger reset of the execution timer [true: reset execution timer; false: don't reset execution timer]
 */
bool mcld_write_reg_dlc4_prep(WRITE_REG_DLC4_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add) {
	bool ret_val = false;																	/*< initially return value false */
	if(add <= FRAME_SLAVE_ADDRESS_31) {
		ret_val = true;																		/*< address is valid */
		frm->w_write_reg.SYNC = SYNC_MSG;
		frm->w_write_reg.CRC_REQ_S_ADD.bit.Address = add;
		frm->w_write_reg.CRC_REQ_S_ADD.bit.TLDCRC = 0;											/*< CRC initially 0 */
		frm->w_write_reg.MRC_DLC_FUN.bit.FUN = FRAME_FUN_WRITE_REG;
		frm->w_write_reg.MRC_DLC_FUN.bit.DLC = FRAME_DLC_4;
		frm->w_write_reg.MRC_DLC_FUN.bit.MRC = curr_mrc[0];									/*< set MRC */
		frm->timeout = false;																/*< reset timeout */
		curr_mrc[0] = mcld_get_next_rc_val(curr_mrc[0]);									/*< calculate next Master Rolling Counter */
		if(add != FRAME_SLAVE_ADDRESS_BROADCAST) {											/*< only for messages which are not broadcast messages (would lead to two times increasing MRC) */
			curr_mrc[add] = mcld_get_next_rc_val(curr_mrc[add]);							/*< calculate expected Rolling Counter for answer */
		}
	}
	return ret_val;
}

/** @brief Finalize a MCLD WRITE_REG_DLC4 data frame
 * This functions finalizes a frame by calculating the CRC3 for the MRC_DLC_FUN byte and
 * calculating the CRC8 for the data in order to store it in the SAFETY_BYTE.
 *
 * @param[in] WRITE_REG_DLC4_FRAME_t* pointer to frame where the CRC has to be calculated
 */
void mcld_write_reg_dlc4_fin(WRITE_REG_DLC4_FRAME_t* frm) {
	mcld_calculate_crc3_master_request(&(frm->w_write_reg.CRC_REQ_S_ADD), &(frm->w_write_reg.MRC_DLC_FUN));

	/* from POS_WRITE_REG_DATA0_HB to POS_WRITE_REG_DLC4_SAFETY_BYTE-1 */
	frm->w_write_reg.SAFETY_BYTE = mcld_calculate_crc8_general(&(frm->write_array[POS_WRITE_REG_START_ADD]),POS_WRITE_REG_DLC4_SAFETY_BYTE - POS_WRITE_REG_START_ADD);
}

/** @brief Validate the slave response of a MCLD WRITE_REG_DLC4 data frame
 * This functions validates the slave response of a frame by checking for a CRC3 error or rolling counter error.
 *
 * @param[in] WRITE_REG_DLC4_FRAME_t* pointer to frame where the CRC has to be calculated
 *
 * @return detected error in validation [MCLD_VAL_NO_ERROR: no error detected; MCLD_VAL_CRC3_ERROR: CRC3 error in ACK_BYTE ; MCLD_VAL_RC_ERROR: rolling counter error]
 */
MCLD_VAL_t mcld_write_reg_dlc4_val_resp(WRITE_REG_DLC4_FRAME_t* frm) {
	/* check for CRC3 error */
	if(mcld_calculate_crc3_slave_response(&(frm->r_write_reg.OST), &(frm->r_write_reg.ACK))) {
		return MCLD_VAL_CRC3_ERROR;
	}
	/* check for Rolling Counter Error */
	FRAME_ACK_BYTE_t temp_ack;
	temp_ack.ACK_BYTE = frm->r_write_reg.ACK;												/*< store ACK byte temporary */
	if(temp_ack.bit.RC != curr_mrc[frm->w_write_reg.CRC_REQ_S_ADD.bit.Address]) {
		return MCLD_VAL_RC_ERROR;
	}
	/* no error detected */
	return MCLD_VAL_NO_ERROR;
}

/** @brief Prepare a MCLD WRITE_REG_DLC5 data frame
 * This functions prepares a frame by setting the sync message, address, FUN, DLC and MRC as well as resetting the CRC3.
 * Additionally it is checked, if the slave address is valid for that frame.
 *
 * @param[in] WRITE_REG_DLC5_FRAME_t* pointer to frame where the CRC has to be calculated
 * @param[in] FRAME_SLAVE_ADDRESS_t address of slave where the frame has to be send [FRAME_SLAVE_ADDRESS_BROADCAST ... FRAME_SLAVE_ADDRESS_31]
 *
 * @return trigger reset of the execution timer [true: reset execution timer; false: don't reset execution timer]
 */
bool mcld_write_reg_dlc5_prep(WRITE_REG_DLC5_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add) {
	bool ret_val = false;																	/*< initially return value false */
	if(add <= FRAME_SLAVE_ADDRESS_31) {
		ret_val = true;																		/*< address is valid */
		frm->w_write_reg.SYNC = SYNC_MSG;
		frm->w_write_reg.CRC_REQ_S_ADD.bit.Address = add;
		frm->w_write_reg.CRC_REQ_S_ADD.bit.TLDCRC = 0;											/*< CRC initially 0 */
		frm->w_write_reg.MRC_DLC_FUN.bit.FUN = FRAME_FUN_WRITE_REG;
		frm->w_write_reg.MRC_DLC_FUN.bit.DLC = FRAME_DLC_5;
		frm->w_write_reg.MRC_DLC_FUN.bit.MRC = curr_mrc[0];									/*< set MRC */
		frm->timeout = false;																/*< reset timeout */
		curr_mrc[0] = mcld_get_next_rc_val(curr_mrc[0]);									/*< calculate next Master Rolling Counter */
		if(add != FRAME_SLAVE_ADDRESS_BROADCAST) {											/*< only for messages which are not broadcast messages (would lead to two times increasing MRC) */
			curr_mrc[add] = mcld_get_next_rc_val(curr_mrc[add]);							/*< calculate expected Rolling Counter for answer */
		}
	}
	return ret_val;
}

/** @brief Finalize a MCLD WRITE_REG_DLC5 data frame
 * This functions finalizes a frame by calculating the CRC3 for the MRC_DLC_FUN byte and
 * calculating the CRC8 for the data in order to store it in the SAFETY_BYTE.
 *
 * @param[in] WRITE_REG_DLC5_FRAME_t* pointer to frame where the CRC has to be calculated
 */
void mcld_write_reg_dlc5_fin(WRITE_REG_DLC5_FRAME_t* frm) {
	mcld_calculate_crc3_master_request(&(frm->w_write_reg.CRC_REQ_S_ADD), &(frm->w_write_reg.MRC_DLC_FUN));

	/* from POS_WRITE_REG_DATA0_HB to POS_WRITE_REG_DLC5_SAFETY_BYTE-1 */
	frm->w_write_reg.SAFETY_BYTE = mcld_calculate_crc8_general(&(frm->write_array[POS_WRITE_REG_START_ADD]),POS_WRITE_REG_DLC5_SAFETY_BYTE - POS_WRITE_REG_START_ADD);
}

/** @brief Validate the slave response of a MCLD WRITE_REG_DLC5 data frame
 * This functions validates the slave response of a frame by checking for a CRC3 error or rolling counter error.
 *
 * @param[in] WRITE_REG_DLC5_FRAME_t* pointer to frame where the CRC has to be calculated
 *
 * @return detected error in validation [MCLD_VAL_NO_ERROR: no error detected; MCLD_VAL_CRC3_ERROR: CRC3 error in ACK_BYTE ; MCLD_VAL_RC_ERROR: rolling counter error]
 */
MCLD_VAL_t mcld_write_reg_dlc5_val_resp(WRITE_REG_DLC5_FRAME_t* frm) {
	/* check for CRC3 error */
	if(mcld_calculate_crc3_slave_response(&(frm->r_write_reg.OST), &(frm->r_write_reg.ACK))) {
		return MCLD_VAL_CRC3_ERROR;
	}
	/* check for Rolling Counter Error */
	FRAME_ACK_BYTE_t temp_ack;
	temp_ack.ACK_BYTE = frm->r_write_reg.ACK;												/*< store ACK byte temporary */
	if(temp_ack.bit.RC != curr_mrc[frm->w_write_reg.CRC_REQ_S_ADD.bit.Address]) {
		return MCLD_VAL_RC_ERROR;
	}
	/* no error detected */
	return MCLD_VAL_NO_ERROR;
}

/** @brief Prepare a MCLD WRITE_REG_DLC6 data frame
 * This functions prepares a frame by setting the sync message, address, FUN, DLC and MRC as well as resetting the CRC3.
 * Additionally it is checked, if the slave address is valid for that frame.
 *
 * @param[in] WRITE_REG_DLC6_FRAME_t* pointer to frame where the CRC has to be calculated
 * @param[in] FRAME_SLAVE_ADDRESS_t address of slave where the frame has to be send [FRAME_SLAVE_ADDRESS_BROADCAST ... FRAME_SLAVE_ADDRESS_31]
 *
 * @return trigger reset of the execution timer [true: reset execution timer; false: don't reset execution timer]
 */
bool mcld_write_reg_dlc6_prep(WRITE_REG_DLC6_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add) {
	bool ret_val = false;																	/*< initially return value false */
	if(add <= FRAME_SLAVE_ADDRESS_31) {
		ret_val = true;																		/*< address is valid */
		frm->w_write_reg.SYNC = SYNC_MSG;
		frm->w_write_reg.CRC_REQ_S_ADD.bit.Address = add;
		frm->w_write_reg.CRC_REQ_S_ADD.bit.TLDCRC = 0;											/*< CRC initially 0 */
		frm->w_write_reg.MRC_DLC_FUN.bit.FUN = FRAME_FUN_WRITE_REG;
		frm->w_write_reg.MRC_DLC_FUN.bit.DLC = FRAME_DLC_6;
		frm->w_write_reg.MRC_DLC_FUN.bit.MRC = curr_mrc[0];									/*< set MRC */
		frm->timeout = false;																/*< reset timeout */
		curr_mrc[0] = mcld_get_next_rc_val(curr_mrc[0]);									/*< calculate next Master Rolling Counter */
		if(add != FRAME_SLAVE_ADDRESS_BROADCAST) {											/*< only for messages which are not broadcast messages (would lead to two times increasing MRC) */
			curr_mrc[add] = mcld_get_next_rc_val(curr_mrc[add]);							/*< calculate expected Rolling Counter for answer */
		}
	}
	return ret_val;
}

/** @brief Finalize a MCLD WRITE_REG_DLC6 data frame
 * This functions finalizes a frame by calculating the CRC3 for the MRC_DLC_FUN byte and
 * calculating the CRC8 for the data in order to store it in the SAFETY_BYTE.
 *
 * @param[in] WRITE_REG_DLC6_FRAME_t* pointer to frame where the CRC has to be calculated
 */
void mcld_write_reg_dlc6_fin(WRITE_REG_DLC6_FRAME_t* frm) {
	mcld_calculate_crc3_master_request(&(frm->w_write_reg.CRC_REQ_S_ADD), &(frm->w_write_reg.MRC_DLC_FUN));

	/* from POS_WRITE_REG_DATA0_HB to POS_WRITE_REG_DLC6_SAFETY_BYTE-1 */
	frm->w_write_reg.SAFETY_BYTE = mcld_calculate_crc8_general(&(frm->write_array[POS_WRITE_REG_START_ADD]),POS_WRITE_REG_DLC6_SAFETY_BYTE - POS_WRITE_REG_START_ADD);
}

/** @brief Validate the slave response of a MCLD WRITE_REG_DLC6 data frame
 * This functions validates the slave response of a frame by checking for a CRC3 error or rolling counter error.
 *
 * @param[in] WRITE_REG_DLC6_FRAME_t* pointer to frame where the CRC has to be calculated
 *
 * @return detected error in validation [MCLD_VAL_NO_ERROR: no error detected; MCLD_VAL_CRC3_ERROR: CRC3 error in ACK_BYTE ; MCLD_VAL_RC_ERROR: rolling counter error]
 */
MCLD_VAL_t mcld_write_reg_dlc6_val_resp(WRITE_REG_DLC6_FRAME_t* frm) {
	/* check for CRC3 error */
	if(mcld_calculate_crc3_slave_response(&(frm->r_write_reg.OST), &(frm->r_write_reg.ACK))) {
		return MCLD_VAL_CRC3_ERROR;
	}
	/* check for Rolling Counter Error */
	FRAME_ACK_BYTE_t temp_ack;
	temp_ack.ACK_BYTE = frm->r_write_reg.ACK;												/*< store ACK byte temporary */
	if(temp_ack.bit.RC != curr_mrc[frm->w_write_reg.CRC_REQ_S_ADD.bit.Address]) {
		return MCLD_VAL_RC_ERROR;
	}
	/* no error detected */
	return MCLD_VAL_NO_ERROR;
}

/** @brief Prepare a MCLD WRITE_REG_DLC7 data frame
 * This functions prepares a frame by setting the sync message, address, FUN, DLC and MRC as well as resetting the CRC3.
 * Additionally it is checked, if the slave address is valid for that frame.
 *
 * @param[in] WRITE_REG_DLC7_FRAME_t* pointer to frame where the CRC has to be calculated
 * @param[in] FRAME_SLAVE_ADDRESS_t address of slave where the frame has to be send [FRAME_SLAVE_ADDRESS_BROADCAST ... FRAME_SLAVE_ADDRESS_31]
 *
 * @return trigger reset of the execution timer [true: reset execution timer; false: don't reset execution timer]
 */
bool mcld_write_reg_dlc7_prep(WRITE_REG_DLC7_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add) {
	bool ret_val = false;																	/*< initially return value false */
	if(add <= FRAME_SLAVE_ADDRESS_31) {
		ret_val = true;																		/*< address is valid */
		frm->w_write_reg.SYNC = SYNC_MSG;
		frm->w_write_reg.CRC_REQ_S_ADD.bit.Address = add;
		frm->w_write_reg.CRC_REQ_S_ADD.bit.TLDCRC = 0;											/*< CRC initially 0 */
		frm->w_write_reg.MRC_DLC_FUN.bit.FUN = FRAME_FUN_WRITE_REG;
		frm->w_write_reg.MRC_DLC_FUN.bit.DLC = FRAME_DLC_7;
		frm->w_write_reg.MRC_DLC_FUN.bit.MRC = curr_mrc[0];									/*< set MRC */
		frm->timeout = false;																/*< reset timeout */
		curr_mrc[0] = mcld_get_next_rc_val(curr_mrc[0]);									/*< calculate next Master Rolling Counter */
		if(add != FRAME_SLAVE_ADDRESS_BROADCAST) {											/*< only for messages which are not broadcast messages (would lead to two times increasing MRC) */
			curr_mrc[add] = mcld_get_next_rc_val(curr_mrc[add]);							/*< calculate expected Rolling Counter for answer */
		}
	}
	return ret_val;
}

/** @brief Finalize a MCLD WRITE_REG_DLC7 data frame
 * This functions finalizes a frame by calculating the CRC3 for the MRC_DLC_FUN byte and
 * calculating the CRC8 for the data in order to store it in the SAFETY_BYTE.
 *
 * @param[in] WRITE_REG_DLC7_FRAME_t* pointer to frame where the CRC has to be calculated
 */
void mcld_write_reg_dlc7_fin(WRITE_REG_DLC7_FRAME_t* frm) {
	mcld_calculate_crc3_master_request(&(frm->w_write_reg.CRC_REQ_S_ADD), &(frm->w_write_reg.MRC_DLC_FUN));

	/* from POS_WRITE_REG_DATA0_HB to POS_WRITE_REG_DLC7_SAFETY_BYTE-1 */
	frm->w_write_reg.SAFETY_BYTE = mcld_calculate_crc8_general(&(frm->write_array[POS_WRITE_REG_START_ADD]),POS_WRITE_REG_DLC7_SAFETY_BYTE - POS_WRITE_REG_START_ADD);
}

/** @brief Validate the slave response of a MCLD WRITE_REG_DLC7 data frame
 * This functions validates the slave response of a frame by checking for a CRC3 error or rolling counter error.
 *
 * @param[in] WRITE_REG_DLC7_FRAME_t* pointer to frame where the CRC has to be calculated
 *
 * @return detected error in validation [MCLD_VAL_NO_ERROR: no error detected; MCLD_VAL_CRC3_ERROR: CRC3 error in ACK_BYTE ; MCLD_VAL_RC_ERROR: rolling counter error]
 */
MCLD_VAL_t mcld_write_reg_dlc7_val_resp(WRITE_REG_DLC7_FRAME_t* frm) {
	/* check for CRC3 error */
	if(mcld_calculate_crc3_slave_response(&(frm->r_write_reg.OST), &(frm->r_write_reg.ACK))) {
		return MCLD_VAL_CRC3_ERROR;
	}
	/* check for Rolling Counter Error */
	FRAME_ACK_BYTE_t temp_ack;
	temp_ack.ACK_BYTE = frm->r_write_reg.ACK;												/*< store ACK byte temporary */
	if(temp_ack.bit.RC != curr_mrc[frm->w_write_reg.CRC_REQ_S_ADD.bit.Address]) {
		return MCLD_VAL_RC_ERROR;
	}
	/* no error detected */
	return MCLD_VAL_NO_ERROR;
}

/** @brief Prepare a MCLD READ_REG_DLC1 data frame
 * This functions prepares a frame by setting the sync message, address, FUN, DLC and MRC as well as resetting the CRC3.
 * Additionally it is checked, if the slave address is valid for that frame.
 *
 * @param[in] READ_REG_DLC1_FRAME_t* pointer to frame where the CRC has to be calculated
 * @param[in] FRAME_SLAVE_ADDRESS_t address of slave where the frame has to be send [FRAME_SLAVE_ADDRESS_BROADCAST ... FRAME_SLAVE_ADDRESS_31]
 *
 * @return trigger reset of the execution timer [true: reset execution timer; false: don't reset execution timer]
 */
bool mcld_read_reg_dlc1_prep(READ_REG_DLC1_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add) {
	bool ret_val = false;																	/*< initially return value false */
	if(add <= FRAME_SLAVE_ADDRESS_31) {
		ret_val = true;																		/*< address is valid */
		frm->w_read_reg.SYNC = SYNC_MSG;
		frm->w_read_reg.CRC_REQ_S_ADD.bit.Address = add;
		frm->w_read_reg.CRC_REQ_S_ADD.bit.TLDCRC = 0;											/*< CRC initially 0 */
		frm->w_read_reg.MRC_DLC_FUN.bit.FUN = FRAME_FUN_READ_REG;
		frm->w_read_reg.MRC_DLC_FUN.bit.DLC = FRAME_DLC_1;
		frm->w_read_reg.MRC_DLC_FUN.bit.MRC = curr_mrc[0];									/*< set MRC */
		frm->timeout = false;																/*< reset timeout */
		curr_mrc[0] = mcld_get_next_rc_val(curr_mrc[0]);									/*< calculate next Master Rolling Counter */
		if(add != FRAME_SLAVE_ADDRESS_BROADCAST) {											/*< only for messages which are not broadcast messages (would lead to two times increasing MRC) */
			curr_mrc[add] = mcld_get_next_rc_val(curr_mrc[add]);							/*< calculate expected Rolling Counter for answer */
		}
	}
	return ret_val;
}

/** @brief Finalize a MCLD READ_REG_DLC1 data frame
 * This functions finalizes a frame by calculating the CRC3 for the MRC_DLC_FUN byte and
 * calculating the CRC8 for the data in order to store it in the SAFETY_BYTE.
 *
 * @param[in] READ_REG_DLC1_FRAME_t* pointer to frame where the CRC has to be calculated
 */
void mcld_read_reg_dlc1_fin(READ_REG_DLC1_FRAME_t* frm) {
	mcld_calculate_crc3_master_request(&(frm->w_read_reg.CRC_REQ_S_ADD), &(frm->w_read_reg.MRC_DLC_FUN));
}

/** @brief Validate the slave response of a MCLD READ_REG_DLC1 data frame
 * This functions validates the slave response of a frame by checking for a CRC3 error or rolling counter error.
 *
 * @param[in] READ_REG_DLC1_FRAME_t* pointer to frame where the CRC has to be calculated
 *
 * @return detected error in validation [MCLD_VAL_NO_ERROR: no error detected; MCLD_VAL_CRC3_ERROR: CRC3 error in ACK_BYTE; MCLD_VAL_RC_ERROR: rolling counter error; MCLD_VAL_CRC8_ERROR: CRC8 error in DATA; ]
 */
MCLD_VAL_t mcld_read_reg_dlc1_val_resp(READ_REG_DLC1_FRAME_t* frm) {
	uint8 crc8_data_val = 0;
	/* leading slave address + data from POS_READ_REG_DATA0_HB to POS_READ_REG_DLC1_SAFETY_BYTE-1 */
	crc8_data_val = mcld_calculate_crc8_leadbyte(&(frm->write_array[POS_READ_REG_DATA0_HB]),POS_READ_REG_DLC1_SAFETY_BYTE - POS_READ_REG_DATA0_HB, frm->read_array[POS_READ_REG_START_ADD]);

	/* check for CRC3 error */
	if(mcld_calculate_crc3_slave_response(&(frm->r_read_reg.OST), &(frm->r_read_reg.ACK))) {
		return MCLD_VAL_CRC3_ERROR;
	}
	/* check for Rolling Counter Error */
	FRAME_ACK_BYTE_t temp_ack;
	temp_ack.ACK_BYTE = frm->r_read_reg.ACK;												/*< store ACK byte temporary */
	if(temp_ack.bit.RC != curr_mrc[frm->w_read_reg.CRC_REQ_S_ADD.bit.Address]) {
		return MCLD_VAL_RC_ERROR;
	}
	/* check for CRC8 error of data */
	if(crc8_data_val != frm->r_read_reg.SAFETY_BYTE) {
		return MCLD_VAL_CRC8_ERROR;
	}
	/* no error detected */
	return MCLD_VAL_NO_ERROR;
}

/** @brief Prepare a MCLD READ_REG_DLC2 data frame
 * This functions prepares a frame by setting the sync message, address, FUN, DLC and MRC as well as resetting the CRC3.
 * Additionally it is checked, if the slave address is valid for that frame.
 *
 * @param[in] READ_REG_DLC2_FRAME_t* pointer to frame where the CRC has to be calculated
 * @param[in] FRAME_SLAVE_ADDRESS_t address of slave where the frame has to be send [FRAME_SLAVE_ADDRESS_BROADCAST ... FRAME_SLAVE_ADDRESS_31]
 *
 * @return trigger reset of the execution timer [true: reset execution timer; false: don't reset execution timer]
 */
bool mcld_read_reg_dlc2_prep(READ_REG_DLC2_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add) {
	bool ret_val = false;																	/*< initially return value false */
	if(add <= FRAME_SLAVE_ADDRESS_31) {
		ret_val = true;																		/*< address is valid */
		frm->w_read_reg.SYNC = SYNC_MSG;
		frm->w_read_reg.CRC_REQ_S_ADD.bit.Address = add;
		frm->w_read_reg.CRC_REQ_S_ADD.bit.TLDCRC = 0;											/*< CRC initially 0 */
		frm->w_read_reg.MRC_DLC_FUN.bit.FUN = FRAME_FUN_READ_REG;
		frm->w_read_reg.MRC_DLC_FUN.bit.DLC = FRAME_DLC_2;
		frm->w_read_reg.MRC_DLC_FUN.bit.MRC = curr_mrc[0];									/*< set MRC */
		frm->timeout = false;																/*< reset timeout */
		curr_mrc[0] = mcld_get_next_rc_val(curr_mrc[0]);									/*< calculate next Master Rolling Counter */
		if(add != FRAME_SLAVE_ADDRESS_BROADCAST) {											/*< only for messages which are not broadcast messages (would lead to two times increasing MRC) */
			curr_mrc[add] = mcld_get_next_rc_val(curr_mrc[add]);							/*< calculate expected Rolling Counter for answer */
		}
	}
	return ret_val;
}

/** @brief Finalize a MCLD READ_REG_DLC2 data frame
 * This functions finalizes a frame by calculating the CRC3 for the MRC_DLC_FUN byte and
 * calculating the CRC8 for the data in order to store it in the SAFETY_BYTE.
 *
 * @param[in] READ_REG_DLC2_FRAME_t* pointer to frame where the CRC has to be calculated
 */
void mcld_read_reg_dlc2_fin(READ_REG_DLC2_FRAME_t* frm) {
	mcld_calculate_crc3_master_request(&(frm->w_read_reg.CRC_REQ_S_ADD), &(frm->w_read_reg.MRC_DLC_FUN));
}

/** @brief Validate the slave response of a MCLD READ_REG_DLC2 data frame
 * This functions validates the slave response of a frame by checking for a CRC3 error or rolling counter error.
 *
 * @param[in] READ_REG_DLC2_FRAME_t* pointer to frame where the CRC has to be calculated
 *
 * @return detected error in validation [MCLD_VAL_NO_ERROR: no error detected; MCLD_VAL_CRC3_ERROR: CRC3 error in ACK_BYTE; MCLD_VAL_RC_ERROR: rolling counter error; MCLD_VAL_CRC8_ERROR: CRC8 error in DATA; ]
 */
MCLD_VAL_t mcld_read_reg_dlc2_val_resp(READ_REG_DLC2_FRAME_t* frm) {
	uint8 crc8_data_val = 0;
	/* leading slave address + data from POS_READ_REG_DATA0_HB to POS_READ_REG_DLC2_SAFETY_BYTE-1 */
	crc8_data_val = mcld_calculate_crc8_leadbyte(&(frm->write_array[POS_READ_REG_DATA0_HB]),POS_READ_REG_DLC2_SAFETY_BYTE - POS_READ_REG_DATA0_HB, frm->read_array[POS_READ_REG_START_ADD]);

	/* check for CRC3 error */
	if(mcld_calculate_crc3_slave_response(&(frm->r_read_reg.OST), &(frm->r_read_reg.ACK))) {
		return MCLD_VAL_CRC3_ERROR;
	}
	/* check for Rolling Counter Error */
	FRAME_ACK_BYTE_t temp_ack;
	temp_ack.ACK_BYTE = frm->r_read_reg.ACK;												/*< store ACK byte temporary */
	if(temp_ack.bit.RC != curr_mrc[frm->w_read_reg.CRC_REQ_S_ADD.bit.Address]) {
		return MCLD_VAL_RC_ERROR;
	}
	/* check for CRC8 error of data */
	if(crc8_data_val != frm->r_read_reg.SAFETY_BYTE) {
		return MCLD_VAL_CRC8_ERROR;
	}
	/* no error detected */
	return MCLD_VAL_NO_ERROR;
}

/** @brief Prepare a MCLD READ_REG_DLC3 data frame
 * This functions prepares a frame by setting the sync message, address, FUN, DLC and MRC as well as resetting the CRC3.
 * Additionally it is checked, if the slave address is valid for that frame.
 *
 * @param[in] READ_REG_DLC3_FRAME_t* pointer to frame where the CRC has to be calculated
 * @param[in] FRAME_SLAVE_ADDRESS_t address of slave where the frame has to be send [FRAME_SLAVE_ADDRESS_BROADCAST ... FRAME_SLAVE_ADDRESS_31]
 *
 * @return trigger reset of the execution timer [true: reset execution timer; false: don't reset execution timer]
 */
bool mcld_read_reg_dlc3_prep(READ_REG_DLC3_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add) {
	bool ret_val = false;																	/*< initially return value false */
	if(add <= FRAME_SLAVE_ADDRESS_31) {
		ret_val = true;																		/*< address is valid */
		frm->w_read_reg.SYNC = SYNC_MSG;
		frm->w_read_reg.CRC_REQ_S_ADD.bit.Address = add;
		frm->w_read_reg.CRC_REQ_S_ADD.bit.TLDCRC = 0;											/*< CRC initially 0 */
		frm->w_read_reg.MRC_DLC_FUN.bit.FUN = FRAME_FUN_READ_REG;
		frm->w_read_reg.MRC_DLC_FUN.bit.DLC = FRAME_DLC_3;
		frm->w_read_reg.MRC_DLC_FUN.bit.MRC = curr_mrc[0];									/*< set MRC */
		frm->timeout = false;																/*< reset timeout */
		curr_mrc[0] = mcld_get_next_rc_val(curr_mrc[0]);									/*< calculate next Master Rolling Counter */
		if(add != FRAME_SLAVE_ADDRESS_BROADCAST) {											/*< only for messages which are not broadcast messages (would lead to two times increasing MRC) */
			curr_mrc[add] = mcld_get_next_rc_val(curr_mrc[add]);							/*< calculate expected Rolling Counter for answer */
		}
	}
	return ret_val;
}

/** @brief Finalize a MCLD READ_REG_DLC3 data frame
 * This functions finalizes a frame by calculating the CRC3 for the MRC_DLC_FUN byte and
 * calculating the CRC8 for the data in order to store it in the SAFETY_BYTE.
 *
 * @param[in] READ_REG_DLC3_FRAME_t* pointer to frame where the CRC has to be calculated
 */
void mcld_read_reg_dlc3_fin(READ_REG_DLC3_FRAME_t* frm) {
	mcld_calculate_crc3_master_request(&(frm->w_read_reg.CRC_REQ_S_ADD), &(frm->w_read_reg.MRC_DLC_FUN));
}

/** @brief Validate the slave response of a MCLD READ_REG_DLC3 data frame
 * This functions validates the slave response of a frame by checking for a CRC3 error or rolling counter error.
 *
 * @param[in] READ_REG_DLC3_FRAME_t* pointer to frame where the CRC has to be calculated
 *
 * @return detected error in validation [MCLD_VAL_NO_ERROR: no error detected; MCLD_VAL_CRC3_ERROR: CRC3 error in ACK_BYTE; MCLD_VAL_RC_ERROR: rolling counter error; MCLD_VAL_CRC8_ERROR: CRC8 error in DATA; ]
 */
MCLD_VAL_t mcld_read_reg_dlc3_val_resp(READ_REG_DLC3_FRAME_t* frm) {
	uint8 crc8_data_val = 0;
	/* leading slave address + data from POS_READ_REG_DATA0_HB to POS_READ_REG_DLC3_SAFETY_BYTE-1 */
	crc8_data_val = mcld_calculate_crc8_leadbyte(&(frm->write_array[POS_READ_REG_DATA0_HB]),POS_READ_REG_DLC3_SAFETY_BYTE - POS_READ_REG_DATA0_HB, frm->read_array[POS_READ_REG_START_ADD]);

	/* check for CRC3 error */
	if(mcld_calculate_crc3_slave_response(&(frm->r_read_reg.OST), &(frm->r_read_reg.ACK))) {
		return MCLD_VAL_CRC3_ERROR;
	}
	/* check for Rolling Counter Error */
	FRAME_ACK_BYTE_t temp_ack;
	temp_ack.ACK_BYTE = frm->r_read_reg.ACK;												/*< store ACK byte temporary */
	if(temp_ack.bit.RC != curr_mrc[frm->w_read_reg.CRC_REQ_S_ADD.bit.Address]) {
		return MCLD_VAL_RC_ERROR;
	}
	/* check for CRC8 error of data */
	if(crc8_data_val != frm->r_read_reg.SAFETY_BYTE) {
		return MCLD_VAL_CRC8_ERROR;
	}
	/* no error detected */
	return MCLD_VAL_NO_ERROR;
}

/** @brief Prepare a MCLD READ_REG_DLC4 data frame
 * This functions prepares a frame by setting the sync message, address, FUN, DLC and MRC as well as resetting the CRC3.
 * Additionally it is checked, if the slave address is valid for that frame.
 *
 * @param[in] READ_REG_DLC4_FRAME_t* pointer to frame where the CRC has to be calculated
 * @param[in] FRAME_SLAVE_ADDRESS_t address of slave where the frame has to be send [FRAME_SLAVE_ADDRESS_BROADCAST ... FRAME_SLAVE_ADDRESS_31]
 *
 * @return trigger reset of the execution timer [true: reset execution timer; false: don't reset execution timer]
 */
bool mcld_read_reg_dlc4_prep(READ_REG_DLC4_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add) {
	bool ret_val = false;																	/*< initially return value false */
	if(add <= FRAME_SLAVE_ADDRESS_31) {
		ret_val = true;																		/*< address is valid */
		frm->w_read_reg.SYNC = SYNC_MSG;
		frm->w_read_reg.CRC_REQ_S_ADD.bit.Address = add;
		frm->w_read_reg.CRC_REQ_S_ADD.bit.TLDCRC = 0;											/*< CRC initially 0 */
		frm->w_read_reg.MRC_DLC_FUN.bit.FUN = FRAME_FUN_READ_REG;
		frm->w_read_reg.MRC_DLC_FUN.bit.DLC = FRAME_DLC_4;
		frm->w_read_reg.MRC_DLC_FUN.bit.MRC = curr_mrc[0];									/*< set MRC */
		frm->timeout = false;																/*< reset timeout */
		curr_mrc[0] = mcld_get_next_rc_val(curr_mrc[0]);									/*< calculate next Master Rolling Counter */
		if(add != FRAME_SLAVE_ADDRESS_BROADCAST) {											/*< only for messages which are not broadcast messages (would lead to two times increasing MRC) */
			curr_mrc[add] = mcld_get_next_rc_val(curr_mrc[add]);							/*< calculate expected Rolling Counter for answer */
		}
	}
	return ret_val;
}

/** @brief Finalize a MCLD READ_REG_DLC4 data frame
 * This functions finalizes a frame by calculating the CRC3 for the MRC_DLC_FUN byte and
 * calculating the CRC8 for the data in order to store it in the SAFETY_BYTE.
 *
 * @param[in] READ_REG_DLC4_FRAME_t* pointer to frame where the CRC has to be calculated
 */
void mcld_read_reg_dlc4_fin(READ_REG_DLC4_FRAME_t* frm) {
	mcld_calculate_crc3_master_request(&(frm->w_read_reg.CRC_REQ_S_ADD), &(frm->w_read_reg.MRC_DLC_FUN));
}

/** @brief Validate the slave response of a MCLD READ_REG_DLC4 data frame
 * This functions validates the slave response of a frame by checking for a CRC3 error or rolling counter error.
 *
 * @param[in] READ_REG_DLC4_FRAME_t* pointer to frame where the CRC has to be calculated
 *
 * @return detected error in validation [MCLD_VAL_NO_ERROR: no error detected; MCLD_VAL_CRC3_ERROR: CRC3 error in ACK_BYTE; MCLD_VAL_RC_ERROR: rolling counter error; MCLD_VAL_CRC8_ERROR: CRC8 error in DATA; ]
 */
MCLD_VAL_t mcld_read_reg_dlc4_val_resp(READ_REG_DLC4_FRAME_t* frm) {
	uint8 crc8_data_val = 0;
	/* leading slave address + data from POS_READ_REG_DATA0_HB to POS_READ_REG_DLC4_SAFETY_BYTE-1 */
	crc8_data_val = mcld_calculate_crc8_leadbyte(&(frm->write_array[POS_READ_REG_DATA0_HB]),POS_READ_REG_DLC4_SAFETY_BYTE - POS_READ_REG_DATA0_HB, frm->read_array[POS_READ_REG_START_ADD]);

	/* check for CRC3 error */
	if(mcld_calculate_crc3_slave_response(&(frm->r_read_reg.OST), &(frm->r_read_reg.ACK))) {
		return MCLD_VAL_CRC3_ERROR;
	}
	/* check for Rolling Counter Error */
	FRAME_ACK_BYTE_t temp_ack;
	temp_ack.ACK_BYTE = frm->r_read_reg.ACK;												/*< store ACK byte temporary */
	if(temp_ack.bit.RC != curr_mrc[frm->w_read_reg.CRC_REQ_S_ADD.bit.Address]) {
		return MCLD_VAL_RC_ERROR;
	}
	/* check for CRC8 error of data */
	if(crc8_data_val != frm->r_read_reg.SAFETY_BYTE) {
		return MCLD_VAL_CRC8_ERROR;
	}
	/* no error detected */
	return MCLD_VAL_NO_ERROR;
}

/** @brief Prepare a MCLD READ_REG_DLC5 data frame
 * This functions prepares a frame by setting the sync message, address, FUN, DLC and MRC as well as resetting the CRC3.
 * Additionally it is checked, if the slave address is valid for that frame.
 *
 * @param[in] READ_REG_DLC5_FRAME_t* pointer to frame where the CRC has to be calculated
 * @param[in] FRAME_SLAVE_ADDRESS_t address of slave where the frame has to be send [FRAME_SLAVE_ADDRESS_BROADCAST ... FRAME_SLAVE_ADDRESS_31]
 *
 * @return trigger reset of the execution timer [true: reset execution timer; false: don't reset execution timer]
 */
bool mcld_read_reg_dlc5_prep(READ_REG_DLC5_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add) {
	bool ret_val = false;																	/*< initially return value false */
	if(add <= FRAME_SLAVE_ADDRESS_31) {
		ret_val = true;																		/*< address is valid */
		frm->w_read_reg.SYNC = SYNC_MSG;
		frm->w_read_reg.CRC_REQ_S_ADD.bit.Address = add;
		frm->w_read_reg.CRC_REQ_S_ADD.bit.TLDCRC = 0;											/*< CRC initially 0 */
		frm->w_read_reg.MRC_DLC_FUN.bit.FUN = FRAME_FUN_READ_REG;
		frm->w_read_reg.MRC_DLC_FUN.bit.DLC = FRAME_DLC_5;
		frm->w_read_reg.MRC_DLC_FUN.bit.MRC = curr_mrc[0];									/*< set MRC */
		frm->timeout = false;																/*< reset timeout */
		curr_mrc[0] = mcld_get_next_rc_val(curr_mrc[0]);									/*< calculate next Master Rolling Counter */
		if(add != FRAME_SLAVE_ADDRESS_BROADCAST) {											/*< only for messages which are not broadcast messages (would lead to two times increasing MRC) */
			curr_mrc[add] = mcld_get_next_rc_val(curr_mrc[add]);							/*< calculate expected Rolling Counter for answer */
		}
	}
	return ret_val;
}

/** @brief Finalize a MCLD READ_REG_DLC5 data frame
 * This functions finalizes a frame by calculating the CRC3 for the MRC_DLC_FUN byte and
 * calculating the CRC8 for the data in order to store it in the SAFETY_BYTE.
 *
 * @param[in] READ_REG_DLC5_FRAME_t* pointer to frame where the CRC has to be calculated
 */
void mcld_read_reg_dlc5_fin(READ_REG_DLC5_FRAME_t* frm) {
	mcld_calculate_crc3_master_request(&(frm->w_read_reg.CRC_REQ_S_ADD), &(frm->w_read_reg.MRC_DLC_FUN));
}

/** @brief Validate the slave response of a MCLD READ_REG_DLC5 data frame
 * This functions validates the slave response of a frame by checking for a CRC3 error or rolling counter error.
 *
 * @param[in] READ_REG_DLC1_FRAME_t* pointer to frame where the CRC has to be calculated
 *
 * @return detected error in validation [MCLD_VAL_NO_ERROR: no error detected; MCLD_VAL_CRC3_ERROR: CRC3 error in ACK_BYTE; MCLD_VAL_RC_ERROR: rolling counter error; MCLD_VAL_CRC8_ERROR: CRC8 error in DATA; ]
 */
MCLD_VAL_t mcld_read_reg_dlc5_val_resp(READ_REG_DLC5_FRAME_t* frm) {
	uint8 crc8_data_val = 0;
	/* leading slave address + data from POS_READ_REG_DATA0_HB to POS_READ_REG_DLC5_SAFETY_BYTE-1 */
	crc8_data_val = mcld_calculate_crc8_leadbyte(&(frm->write_array[POS_READ_REG_DATA0_HB]),POS_READ_REG_DLC5_SAFETY_BYTE - POS_READ_REG_DATA0_HB, frm->read_array[POS_READ_REG_START_ADD]);

	/* check for CRC3 error */
	if(mcld_calculate_crc3_slave_response(&(frm->r_read_reg.OST), &(frm->r_read_reg.ACK))) {
		return MCLD_VAL_CRC3_ERROR;
	}
	/* check for Rolling Counter Error */
	FRAME_ACK_BYTE_t temp_ack;
	temp_ack.ACK_BYTE = frm->r_read_reg.ACK;												/*< store ACK byte temporary */
	if(temp_ack.bit.RC != curr_mrc[frm->w_read_reg.CRC_REQ_S_ADD.bit.Address]) {
		return MCLD_VAL_RC_ERROR;
	}
	/* check for CRC8 error of data */
	if(crc8_data_val != frm->r_read_reg.SAFETY_BYTE) {
		return MCLD_VAL_CRC8_ERROR;
	}
	/* no error detected */
	return MCLD_VAL_NO_ERROR;
}

/** @brief Prepare a MCLD READ_REG_DLC6 data frame
 * This functions prepares a frame by setting the sync message, address, FUN, DLC and MRC as well as resetting the CRC3.
 * Additionally it is checked, if the slave address is valid for that frame.
 *
 * @param[in] READ_REG_DLC6_FRAME_t* pointer to frame where the CRC has to be calculated
 * @param[in] FRAME_SLAVE_ADDRESS_t address of slave where the frame has to be send [FRAME_SLAVE_ADDRESS_BROADCAST ... FRAME_SLAVE_ADDRESS_31]
 *
 * @return trigger reset of the execution timer [true: reset execution timer; false: don't reset execution timer]
 */
bool mcld_read_reg_dlc6_prep(READ_REG_DLC6_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add) {
	bool ret_val = false;																	/*< initially return value false */
	if(add <= FRAME_SLAVE_ADDRESS_31) {
		ret_val = true;																		/*< address is valid */
		frm->w_read_reg.SYNC = SYNC_MSG;
		frm->w_read_reg.CRC_REQ_S_ADD.bit.Address = add;
		frm->w_read_reg.CRC_REQ_S_ADD.bit.TLDCRC = 0;											/*< CRC initially 0 */
		frm->w_read_reg.CRC_REQ_S_ADD.bit.TLDCRC = 0;
		frm->w_read_reg.MRC_DLC_FUN.bit.FUN = FRAME_FUN_READ_REG;
		frm->w_read_reg.MRC_DLC_FUN.bit.DLC = FRAME_DLC_6;
		frm->w_read_reg.MRC_DLC_FUN.bit.MRC = curr_mrc[0];									/*< set MRC */
		frm->timeout = false;																/*< reset timeout */
		curr_mrc[0] = mcld_get_next_rc_val(curr_mrc[0]);									/*< calculate next Master Rolling Counter */
		if(add != FRAME_SLAVE_ADDRESS_BROADCAST) {											/*< only for messages which are not broadcast messages (would lead to two times increasing MRC) */
			curr_mrc[add] = mcld_get_next_rc_val(curr_mrc[add]);							/*< calculate expected Rolling Counter for answer */
		}
	}
	return ret_val;
}

/** @brief Finalize a MCLD READ_REG_DLC6 data frame
 * This functions finalizes a frame by calculating the CRC3 for the MRC_DLC_FUN byte and
 * calculating the CRC8 for the data in order to store it in the SAFETY_BYTE.
 *
 * @param[in] READ_REG_DLC6_FRAME_t* pointer to frame where the CRC has to be calculated
 */
void mcld_read_reg_dlc6_fin(READ_REG_DLC6_FRAME_t* frm) {
	mcld_calculate_crc3_master_request(&(frm->w_read_reg.CRC_REQ_S_ADD), &(frm->w_read_reg.MRC_DLC_FUN));
}

/** @brief Validate the slave response of a MCLD READ_REG_DLC6 data frame
 * This functions validates the slave response of a frame by checking for a CRC3 error or rolling counter error.
 *
 * @param[in] READ_REG_DLC6_FRAME_t* pointer to frame where the CRC has to be calculated
 *
 * @return detected error in validation [MCLD_VAL_NO_ERROR: no error detected; MCLD_VAL_CRC3_ERROR: CRC3 error in ACK_BYTE; MCLD_VAL_RC_ERROR: rolling counter error; MCLD_VAL_CRC8_ERROR: CRC8 error in DATA; ]
 */
MCLD_VAL_t mcld_read_reg_dlc6_val_resp(READ_REG_DLC6_FRAME_t* frm) {
	uint8 crc8_data_val = 0;
	/* leading slave address + data from POS_READ_REG_DATA0_HB to POS_READ_REG_DLC6_SAFETY_BYTE-1 */
	crc8_data_val = mcld_calculate_crc8_leadbyte(&(frm->write_array[POS_READ_REG_DATA0_HB]),POS_READ_REG_DLC6_SAFETY_BYTE - POS_READ_REG_DATA0_HB, frm->read_array[POS_READ_REG_START_ADD]);

	/* check for CRC3 error */
	if(mcld_calculate_crc3_slave_response(&(frm->r_read_reg.OST), &(frm->r_read_reg.ACK))) {
		return MCLD_VAL_CRC3_ERROR;
	}
	/* check for Rolling Counter Error */
	FRAME_ACK_BYTE_t temp_ack;
	temp_ack.ACK_BYTE = frm->r_read_reg.ACK;												/*< store ACK byte temporary */
	if(temp_ack.bit.RC != curr_mrc[frm->w_read_reg.CRC_REQ_S_ADD.bit.Address]) {
		return MCLD_VAL_RC_ERROR;
	}
	/* check for CRC8 error of data */
	if(crc8_data_val != frm->r_read_reg.SAFETY_BYTE) {
		return MCLD_VAL_CRC8_ERROR;
	}
	/* no error detected */
	return MCLD_VAL_NO_ERROR;
}

/** @brief Prepare a MCLD READ_REG_DLC7 data frame
 * This functions prepares a frame by setting the sync message, address, FUN, DLC and MRC as well as resetting the CRC3.
 * Additionally it is checked, if the slave address is valid for that frame.
 *
 * @param[in] READ_REG_DLC7_FRAME_t* pointer to frame where the CRC has to be calculated
 * @param[in] FRAME_SLAVE_ADDRESS_t address of slave where the frame has to be send [FRAME_SLAVE_ADDRESS_BROADCAST ... FRAME_SLAVE_ADDRESS_31]
 *
 * @return trigger reset of the execution timer [true: reset execution timer; false: don't reset execution timer]
 */
bool mcld_read_reg_dlc7_prep(READ_REG_DLC7_FRAME_t* frm, FRAME_SLAVE_ADDRESS_t add) {
	bool ret_val = false;																	/*< initially return value false */
	if(add <= FRAME_SLAVE_ADDRESS_31) {
		ret_val = true;																		/*< address is valid */
		frm->w_read_reg.SYNC = SYNC_MSG;
		frm->w_read_reg.CRC_REQ_S_ADD.bit.Address = add;
		frm->w_read_reg.CRC_REQ_S_ADD.bit.TLDCRC = 0;											/*< CRC initially 0 */
		frm->w_read_reg.MRC_DLC_FUN.bit.FUN = FRAME_FUN_READ_REG;
		frm->w_read_reg.MRC_DLC_FUN.bit.DLC = FRAME_DLC_7;
		frm->w_read_reg.MRC_DLC_FUN.bit.MRC = curr_mrc[0];									/*< set MRC */
		frm->timeout = false;																/*< reset timeout */
		curr_mrc[0] = mcld_get_next_rc_val(curr_mrc[0]);									/*< calculate next Master Rolling Counter */
		if(add != FRAME_SLAVE_ADDRESS_BROADCAST) {											/*< only for messages which are not broadcast messages (would lead to two times increasing MRC) */
			curr_mrc[add] = mcld_get_next_rc_val(curr_mrc[add]);							/*< calculate expected Rolling Counter for answer */
		}
	}
	return ret_val;
}

/** @brief Finalize a MCLD READ_REG_DLC7 data frame
 * This functions finalizes a frame by calculating the CRC3 for the MRC_DLC_FUN byte and
 * calculating the CRC8 for the data in order to store it in the SAFETY_BYTE.
 *
 * @param[in] READ_REG_DLC7_FRAME_t* pointer to frame where the CRC has to be calculated
 */
void mcld_read_reg_dlc7_fin(READ_REG_DLC7_FRAME_t* frm) {
	mcld_calculate_crc3_master_request(&(frm->w_read_reg.CRC_REQ_S_ADD), &(frm->w_read_reg.MRC_DLC_FUN));
}

/** @brief Validate the slave response of a MCLD READ_REG_DLC7 data frame
 * This functions validates the slave response of a frame by checking for a CRC3 error or rolling counter error.
 *
 * @param[in] READ_REG_DLC7_FRAME_t* pointer to frame where the CRC has to be calculated
 *
 * @return detected error in validation [MCLD_VAL_NO_ERROR: no error detected; MCLD_VAL_CRC3_ERROR: CRC3 error in ACK_BYTE; MCLD_VAL_RC_ERROR: rolling counter error; MCLD_VAL_CRC8_ERROR: CRC8 error in DATA; ]
 */
MCLD_VAL_t mcld_read_reg_dlc7_val_resp(READ_REG_DLC7_FRAME_t* frm) {
	uint8 crc8_data_val = 0;
	/* leading slave address + data from POS_READ_REG_DATA0_HB to POS_READ_REG_DLC7_SAFETY_BYTE-1 */
	crc8_data_val = mcld_calculate_crc8_leadbyte(&(frm->write_array[POS_READ_REG_DATA0_HB]),POS_READ_REG_DLC7_SAFETY_BYTE - POS_READ_REG_DATA0_HB, frm->read_array[POS_READ_REG_START_ADD]);

	/* check for CRC3 error */
	if(mcld_calculate_crc3_slave_response(&(frm->r_read_reg.OST), &(frm->r_read_reg.ACK))) {
		return MCLD_VAL_CRC3_ERROR;
	}
	/* check for Rolling Counter Error */
	FRAME_ACK_BYTE_t temp_ack;
	temp_ack.ACK_BYTE = frm->r_read_reg.ACK;												/*< store ACK byte temporary */
	if(temp_ack.bit.RC != curr_mrc[frm->w_read_reg.CRC_REQ_S_ADD.bit.Address]) {
		return MCLD_VAL_RC_ERROR;
	}
	/* check for CRC8 error of data */
	if(crc8_data_val != frm->r_read_reg.SAFETY_BYTE) {
		return MCLD_VAL_CRC8_ERROR;
	}
	/* no error detected */
	return MCLD_VAL_NO_ERROR;
}


/******************************************************************************/
/* Auxiliary function implementation	 									  */
/******************************************************************************/

/** @brief Initialization tasks
 *
 * This functions performs the required initialization tasks for the MCLD low level drivers and
 * has to be executed only one time.
 * Tasks:
 *  - reset curr_mrc to FRAME_RC_2BIT_0
 *
 */
void mcld_init_low_level(void){
	uint8 index;
	/* reset curr_mrc array to initial values */
	for(index = 0; index < 32; index++) {
		curr_mrc[index] = FRAME_RC_2BIT_0;
	}
}


/** @brief Generate next Rolling Counter vaue
 *
 * This functions returns the next Rolling Counter, a 2 bit counter value, which the master needs to increment in
 *  every data transmission starting from 0x00 default (start) value.
 * @param[in] FRAME_RC_2BIT_t current MRC value [FRAME_RC_2BIT_START_VALUE, FRAME_RC_2BIT_0 ... FRAME_RC_2BIT_3]
 *
 * @return FRAME_RC_2BIT_t next CR value
 */
FRAME_RC_2BIT_t mcld_get_next_rc_val(FRAME_RC_2BIT_t mrc) {
	FRAME_RC_2BIT_t nextMrc = FRAME_RC_2BIT_START_VALUE;	/*< initialize return value */

	switch(mrc) {											/*< switch current RC value */
		case FRAME_RC_2BIT_0:								/*< FRAME_RC_2BIT_0 (FRAME_RC_2BIT_START_VALUE) -> FRAME_RC_2BIT_1 */
			nextMrc = FRAME_RC_2BIT_1;
			break;
		case FRAME_RC_2BIT_1:								/*< FRAME_RC_2BIT_1 -> FRAME_RC_2BIT_2 */
			nextMrc = FRAME_RC_2BIT_2;
			break;
		case FRAME_RC_2BIT_2:								/*< FRAME_RC_2BIT_2 -> FRAME_RC_2BIT_3 */
			nextMrc = FRAME_RC_2BIT_3;
			break;
		case FRAME_RC_2BIT_3:								/*< FRAME_RC_2BIT_3 -> FRAME_RC_2BIT_0 */
			nextMrc = FRAME_RC_2BIT_0;
			break;
	}
	return nextMrc;
}


/** @brief Calculate CRC3 of the master request
 *
 * This functions calculates the CRC3 of master request over the Address, MRC, DLC and FUN.
 * @param[in] uint8* pointer to CRC_REQ_S_ADD byte of frame
 * @param[in] uint8* pointer to MRC_DLC_FUN byte of frame
 *
 */
void mcld_calculate_crc3_master_request(FRAME_CRC_ADDRESS_t* byte_req_s_add, FRAME_MRC_DLC_FUN_t* byte_mrc_dlc_fun) {

	 uint8 crc = CRC3_CALC_SEED;



	 crc = LOOKUP_CRC3_5BIT[crc ^ byte_req_s_add->CRC_ADDRESS_BYTE];			//< CRC of lower 5 bits
	 crc = MIRROR_MID_CRC3[crc];
	 crc = LOOKUP_CRC3_8BIT[crc ^ byte_mrc_dlc_fun->MRC_DLC_FUN_BYTE];
	 byte_req_s_add->bit.TLDCRC = crc;

	 /*
	 crc = LOOKUP_CRC3_5BIT[crc ^ byte_req_s_add->bit.Address];
	 crc = MIRROR_MID_CRC3[crc];
	 crc = LOOKUP_CRC3_8BIT[crc ^ (uint8)*byte_mrc_dlc_fun->MRC_DLC_FUN_BYTE];
	 byte_req_s_add->bit.CRC = crc; (uint8)*
	 */




}

void mcld_calculate_crc3_master_request__old(FRAME_CRC_ADDRESS_t* byte_req_s_add, FRAME_MRC_DLC_FUN_t* byte_mrc_dlc_fun) {

	 uint8 crc = CRC3_CALC_SEED;
	
	 crc = LOOKUP_CRC3_5BIT[crc ^ byte_req_s_add->CRC_ADDRESS_BYTE];			//< CRC of lower 5 bits
	 crc = MIRROR_MID_CRC3[crc];
	 crc = LOOKUP_CRC3_8BIT[crc ^ byte_mrc_dlc_fun->MRC_DLC_FUN_BYTE];
	 byte_req_s_add->bit.TLDCRC = crc;
	 /*
	 crc = LOOKUP_CRC3_5BIT[crc ^ byte_req_s_add->bit.Address];
	 crc = MIRROR_MID_CRC3[crc];
	 crc = LOOKUP_CRC3_8BIT[crc ^ (uint8)*byte_mrc_dlc_fun->MRC_DLC_FUN_BYTE];
	 byte_req_s_add->bit.CRC = crc; (uint8)*
	 */
}

/** @brief Check CRC3 of the slave response
 *
 * This functions calculates the CRC3 of slave response over the output status byte, MODE, RC and TER.
 * @param[in] uint8* pointer to OST of frame
 * @param[in] uint8* pointer to ACK byte of frame
 *
 * @return bool [true: crc value is correct; false: crc value is not correct]
 *
 */
bool mcld_calculate_crc3_slave_response(FRAME_OUTPUT_STATUS_BYTE_t* ost_byte, FRAME_ACK_BYTE_t* ack_byte) {
	bool crc_correct = false;				/*< initially crc is not correct */
 	uint8 crc = CRC3_CALC_SEED;
	crc = LOOKUP_CRC3_8BIT[crc ^ ost_byte->OUTPUT_STATUS_BYTE];
	crc = MIRROR_MID_CRC3[crc];
	crc = LOOKUP_CRC3_5BIT[crc ^ (ack_byte->ACK_BYTE & 0x5)];	/*< CRC of lower 5 bits */
	crc_correct = crc == ack_byte->bit.TLDCRC ? true : false;		/* Check if CRC is correct */
	return crc_correct;
}


/** @brief Calculate CRC8 in general
 *
 * This functions calculates the CRC8 based on the 8-SAE J1850 algorithm.
 * @param[in] uint8* pointer to data_array
 * @param[in] uint8 length of data array [0 ... 255]
 *
 * @return uint8 calculated CRC8 [0 ... 255]
 *
 */
uint8 mcld_calculate_crc8_general(uint8* data_array , uint8 data_len) {
	uint8 crc = 0;
	unsigned long crc_calc = CRC8_CALC_SEED;				/* CRC initial value */
	uint8 bit = 0;
	uint8 index = 0;

	/* CRC-8-SAE J1850 algorithm */
	/* all elements of the data array */
	for (index=0; index<data_len; index++) {
		/* use data bytes */
		crc_calc ^= data_array[index];

		for(bit=0; bit<8; bit++) {
			if ((crc_calc & 0x80)!=0) {
				crc_calc <<= 1;
				crc_calc ^= CRC8_CALC_GENERATOR_POLYNOM;
			}
			else {
				crc_calc <<= 1;
			}
		}
	}
	crc = (~crc_calc)&CRC8_CALC_XOR_VAL;					/* write CRC into SAFETY_BYTE */
	return crc;
}


/** @brief Calculate CRC8 with leading byte
 *
 * This functions calculates the CRC8 based on the 8-SAE J1850 algorithm adding an additional byte (leading byte) at the beginning.
 * This means the CRC is calculated for: lead_byte; data_array[0]; data_array[1]; data_array[2]; data_array[3]; ... data_array[255]
 * @param[in] uint8* pointer to data_array
 * @param[in] uint8 length of data array [0 ... 255]
 * @param[in] uint8 leading byte [0 ... 255]
 *
 * @return uint8 calculated CRC8 [0 ... 255]
 *
 */
uint8 mcld_calculate_crc8_leadbyte(uint8* data_array , uint8 data_len, uint8 lead_byte) {
	uint8 crc = 0;
	unsigned long crc_calc = CRC8_CALC_SEED;				/* CRC initial value */
	uint8 bit = 0;
	uint8 index = 0;

	/* CRC-8-SAE J1850 algorithm for first element (lead_byte) */
	crc_calc ^= lead_byte;

	for(bit=0; bit<8; bit++) {
		if ((crc_calc & 0x80)!=0) {
			crc_calc <<= 1;
			crc_calc ^= CRC8_CALC_GENERATOR_POLYNOM;
		}
		else {
			crc_calc <<= 1;
		}
	}

	/* CRC-8-SAE J1850 algorithm for data array */
	/* all elements of the data array */
	for (index=0; index<data_len; index++) {
		/* use data bytes */
		crc_calc ^= data_array[index];

		for(bit=0; bit<8; bit++) {
			if ((crc_calc & 0x80)!=0) {
				crc_calc <<= 1;
				crc_calc ^= CRC8_CALC_GENERATOR_POLYNOM;
			}
			else {
				crc_calc <<= 1;
			}
		}
	}
	crc = (~crc_calc)&CRC8_CALC_XOR_VAL;					/* write CRC into SAFETY_BYTE */
	return crc;
}


/** @brief Set a duty cycle Value of the dc_update (8 Bit) frame
 * This functions configures the duty cycle value in the parameter to a given frame.
 *
 * @param[in] DC_UPDATE_8BIT_FRAME_t* pointer to frame where the duty cycle should be stored
 * @param[in] MCLD_CH_t channel where the duty cycle should be configured
 * @param[in] uint8 duty cycle value [CH_MIN_DC_VAL ... CH_MAX_DC_8BIT_VAL]
 */
void setChDc8BitToFrame(DC_UPDATE_8BIT_FRAME_t* updtfram, MCLD_CH_t ch, uint8 dc_val) {
	switch(ch){											/*< decide between channels and set duty cycle */
	case MCLD_CH0:
		updtfram->w_pwm_dc_update.DutyCycleOUT0 = dc_val & CH_MAX_DC_8BIT_VAL;
		break;
	case MCLD_CH1:
		updtfram->w_pwm_dc_update.DutyCycleOUT1 = dc_val & CH_MAX_DC_8BIT_VAL;
		break;
	case MCLD_CH2:
		updtfram->w_pwm_dc_update.DutyCycleOUT2 = dc_val & CH_MAX_DC_8BIT_VAL;
		break;
	case MCLD_CH3:
		updtfram->w_pwm_dc_update.DutyCycleOUT3 = dc_val & CH_MAX_DC_8BIT_VAL;
		break;
	case MCLD_CH4:
		updtfram->w_pwm_dc_update.DutyCycleOUT4 = dc_val & CH_MAX_DC_8BIT_VAL;
		break;
	case MCLD_CH5:
		updtfram->w_pwm_dc_update.DutyCycleOUT5 = dc_val & CH_MAX_DC_8BIT_VAL;
		break;
	case MCLD_CH6:
		updtfram->w_pwm_dc_update.DutyCycleOUT6 = dc_val & CH_MAX_DC_8BIT_VAL;
		break;
	case MCLD_CH7:
		updtfram->w_pwm_dc_update.DutyCycleOUT7 = dc_val & CH_MAX_DC_8BIT_VAL;
		break;
	case MCLD_CH8:
		updtfram->w_pwm_dc_update.DutyCycleOUT8 = dc_val & CH_MAX_DC_8BIT_VAL;
		break;
	case MCLD_CH9:
		updtfram->w_pwm_dc_update.DutyCycleOUT9 = dc_val & CH_MAX_DC_8BIT_VAL;
		break;
	case MCLD_CH10:
		updtfram->w_pwm_dc_update.DutyCycleOUT10 = dc_val & CH_MAX_DC_8BIT_VAL;
		break;
	case MCLD_CH11:
		updtfram->w_pwm_dc_update.DutyCycleOUT11 = dc_val & CH_MAX_DC_8BIT_VAL;
		break;
	case MCLD_CH12:
		updtfram->w_pwm_dc_update.DutyCycleOUT12 = dc_val & CH_MAX_DC_8BIT_VAL;
		break;
	case MCLD_CH13:
		updtfram->w_pwm_dc_update.DutyCycleOUT13 = dc_val & CH_MAX_DC_8BIT_VAL;
		break;
	case MCLD_CH14:
		updtfram->w_pwm_dc_update.DutyCycleOUT14 = dc_val & CH_MAX_DC_8BIT_VAL;
		break;
	case MCLD_CH15:
		updtfram->w_pwm_dc_update.DutyCycleOUT15 = dc_val & CH_MAX_DC_8BIT_VAL;
		break;
	};
}


/** @brief Set a duty cycle Value of the dc_update (14 Bit) frame
 * This functions configures the duty cycle value in the parameter to a given frame.
 *
 * @param[in] DC_UPDATE_8BIT_FRAME_t* pointer to frame where the duty cycle should be stored
 * @param[in] MCLD_CH_t channel where the duty cycle should be configured
 * @param[in] uint16 duty cycle value [CH_MIN_DC_VAL ... CH_MAX_DC_14BIT_VAL]
 */
void setChDc14BitToFrame(DC_UPDATE_14BIT_FRAME_t* updtfram, MCLD_CH_t ch, uint16 dc_val) {
	switch(ch){											/*< decide between channels and set duty cycle */
	case MCLD_CH0:
		updtfram->w_pwm_dc_update.DutyCycleOUT0_LB = (dc_val & LOW_BYTE_16BIT);				/*< copy data element LSB */
		updtfram->w_pwm_dc_update.DutyCycleOUT0_HB = (dc_val & HIGH_BYTE_14BIT) >> 8;		/*< copy data element MSB */
		break;
	case MCLD_CH1:
		updtfram->w_pwm_dc_update.DutyCycleOUT1_LB = (dc_val & LOW_BYTE_16BIT);				/*< copy data element LSB */
		updtfram->w_pwm_dc_update.DutyCycleOUT1_HB = (dc_val & HIGH_BYTE_14BIT) >> 8;		/*< copy data element MSB */
		break;
	case MCLD_CH2:
		updtfram->w_pwm_dc_update.DutyCycleOUT2_LB = (dc_val & LOW_BYTE_16BIT);				/*< copy data element LSB */
		updtfram->w_pwm_dc_update.DutyCycleOUT2_HB = (dc_val & HIGH_BYTE_14BIT) >> 8;		/*< copy data element MSB */
		break;
	case MCLD_CH3:
		updtfram->w_pwm_dc_update.DutyCycleOUT3_LB = (dc_val & LOW_BYTE_16BIT);				/*< copy data element LSB */
		updtfram->w_pwm_dc_update.DutyCycleOUT3_HB = (dc_val & HIGH_BYTE_14BIT) >> 8;		/*< copy data element MSB */
		break;
	case MCLD_CH4:
		updtfram->w_pwm_dc_update.DutyCycleOUT4_LB = (dc_val & LOW_BYTE_16BIT);				/*< copy data element LSB */
		updtfram->w_pwm_dc_update.DutyCycleOUT4_HB = (dc_val & HIGH_BYTE_14BIT) >> 8;		/*< copy data element MSB */
		break;
	case MCLD_CH5:
		updtfram->w_pwm_dc_update.DutyCycleOUT5_LB = (dc_val & LOW_BYTE_16BIT);				/*< copy data element LSB */
		updtfram->w_pwm_dc_update.DutyCycleOUT5_HB = (dc_val & HIGH_BYTE_14BIT) >> 8;		/*< copy data element MSB */
		break;
	case MCLD_CH6:
		updtfram->w_pwm_dc_update.DutyCycleOUT6_LB = (dc_val & LOW_BYTE_16BIT);				/*< copy data element LSB */
		updtfram->w_pwm_dc_update.DutyCycleOUT6_HB = (dc_val & HIGH_BYTE_14BIT) >> 8;		/*< copy data element MSB */
		break;
	case MCLD_CH7:
		updtfram->w_pwm_dc_update.DutyCycleOUT7_LB = (dc_val & LOW_BYTE_16BIT);				/*< copy data element LSB */
		updtfram->w_pwm_dc_update.DutyCycleOUT7_HB = (dc_val & HIGH_BYTE_14BIT) >> 8;		/*< copy data element MSB */
		break;
	case MCLD_CH8:
		updtfram->w_pwm_dc_update.DutyCycleOUT8_LB = (dc_val & LOW_BYTE_16BIT);				/*< copy data element LSB */
		updtfram->w_pwm_dc_update.DutyCycleOUT8_HB = (dc_val & HIGH_BYTE_14BIT) >> 8;		/*< copy data element MSB */
		break;
	case MCLD_CH9:
		updtfram->w_pwm_dc_update.DutyCycleOUT9_LB = (dc_val & LOW_BYTE_16BIT);				/*< copy data element LSB */
		updtfram->w_pwm_dc_update.DutyCycleOUT9_HB = (dc_val & HIGH_BYTE_14BIT) >> 8;		/*< copy data element MSB */
		break;
	case MCLD_CH10:
		updtfram->w_pwm_dc_update.DutyCycleOUT10_LB = (dc_val & LOW_BYTE_16BIT);			/*< copy data element LSB */
		updtfram->w_pwm_dc_update.DutyCycleOUT10_HB = (dc_val & HIGH_BYTE_14BIT) >> 8;		/*< copy data element MSB */
		break;
	case MCLD_CH11:
		updtfram->w_pwm_dc_update.DutyCycleOUT11_LB = (dc_val & LOW_BYTE_16BIT);			/*< copy data element LSB */
		updtfram->w_pwm_dc_update.DutyCycleOUT11_HB = (dc_val & HIGH_BYTE_14BIT) >> 8;		/*< copy data element MSB */
		break;
	case MCLD_CH12:
		updtfram->w_pwm_dc_update.DutyCycleOUT12_LB = (dc_val & LOW_BYTE_16BIT);			/*< copy data element LSB */
		updtfram->w_pwm_dc_update.DutyCycleOUT12_HB = (dc_val & HIGH_BYTE_14BIT) >> 8;		/*< copy data element MSB */
		break;
	case MCLD_CH13:
		updtfram->w_pwm_dc_update.DutyCycleOUT13_LB = (dc_val & LOW_BYTE_16BIT);			/*< copy data element LSB */
		updtfram->w_pwm_dc_update.DutyCycleOUT13_HB = (dc_val & HIGH_BYTE_14BIT) >> 8;		/*< copy data element MSB */
		break;
	case MCLD_CH14:
		updtfram->w_pwm_dc_update.DutyCycleOUT14_LB = (dc_val & LOW_BYTE_16BIT);			/*< copy data element LSB */
		updtfram->w_pwm_dc_update.DutyCycleOUT14_HB = (dc_val & HIGH_BYTE_14BIT) >> 8;		/*< copy data element MSB */
		break;
	case MCLD_CH15:
		updtfram->w_pwm_dc_update.DutyCycleOUT15_LB = (dc_val & LOW_BYTE_16BIT);			/*< copy data element LSB */
		updtfram->w_pwm_dc_update.DutyCycleOUT15_HB = (dc_val & HIGH_BYTE_14BIT) >> 8;		/*< copy data element MSB */
		break;
	};
}


/** @brief Calculate 8 Bit duty cycle value from given duty cycle in percent
 *
 * @param[in] uint16 duty cycle [0.00 %: 0 - 100.00%: 10000]
 *
 * @return uint8 duty cycle 8 bit value
 */
uint8 calcChDc8BitValue(uint16 dc_perc) {
	uint8 ret_val = 0;								/*< variable to store the value to be returned */
	uint32 dc_val = 0;								/*< variable to store calculated DC value */
	if(dc_perc == CH_MIN_DUTY_CYCLE) { 				/*< for 0 percent duty cycle -> set to minimum value (avoid errors in rounding) */
		ret_val = CH_MIN_DC_VAL;
	}
	else if(dc_perc == CH_MAX_DUTY_CYCLE) { 		/*< for 100 percent duty cycle -> set to minimum value (avoid errors in rounding) */
		ret_val = CH_MAX_DC_8BIT_VAL;
	}
	else {										 	/*< for all other values the duty cycle is calculated */
		//dc_val = CH_MAX_DC_8BIT_VAL << SHIFT16;		/*< extend the data-width for 100 % duty cycle */
		dc_val = CH_MAX_DC_8BIT_VAL << 16;		/*< extend the data-width for 100 % duty cycle */
		dc_val /= CH_MAX_DUTY_CYCLE;				/*< divide by the maximum value for the duty cycle to get the extended value for 1 % duty cycle */
		dc_val *= dc_perc;							/*< multiply with the duty cycle value from the parameter */
		//dc_val = dc_val >> SHIFT16;					/*< shrink data with to get final data word */
		dc_val = dc_val >> 16;					/*< shrink data with to get final data word */
		ret_val = dc_val & CH_MAX_DC_8BIT_VAL;		/*< set the calculated DC value to return value */
	}
	return ret_val;
}


/** @brief Calculate 14 Bit duty cycle value from given duty cycle in percent
 *
 * @param[in] uint16 duty cycle [0.00 %: 0 - 100.00%: 10000]
 *
 * @return uint16 duty cycle 14 bit value
 */
uint16 calcChDc14BitValue(uint16 dc_perc) {
	uint16 ret_val = 0;								/*< variable to store the value to be returned */
	uint32 dc_val = 0;								/*< variable to store calculated DC value */
	if(dc_perc == CH_MIN_DUTY_CYCLE) { 				/*< for 0 percent duty cycle -> set to minimum value (avoid errors in rounding) */
		ret_val = CH_MIN_DC_VAL;
	}
	else if(dc_perc == CH_MAX_DUTY_CYCLE) { 		/*< for 100 percent duty cycle -> set to minimum value (avoid errors in rounding) */
		ret_val = CH_MAX_DC_14BIT_VAL;
	}
	else {										 	/*< for all other values the duty cycle is calculated */
		//dc_val = CH_MAX_DC_14BIT_VAL << SHIFT16;	/*< extend the data-width for 100 % duty cycle */
		dc_val = CH_MAX_DC_14BIT_VAL << 16;	/*< extend the data-width for 100 % duty cycle */
		dc_val /= CH_MAX_DUTY_CYCLE;				/*< divide by the maximum value for the duty cycle to get the extended value for 1 % duty cycle */
		dc_val *= dc_perc;							/*< multiply with the duty cycle value from the parameter */
		//dc_val = dc_val >> SHIFT16;					/*< shrink data with to get final data word */
		dc_val = dc_val >> 16;					/*< shrink data with to get final data word */
		ret_val = dc_val & CH_MAX_DC_14BIT_VAL;		/*< set the calculated DC value to return value */
	}
	return ret_val;
}

void delay1(volatile int cycles)
{
    while(cycles--);
}


//void write_data_to_FTDI_ASC1(uint8* data, uint8 data_length)
//{
//		//while(0 != TransmitData(data, data_length));
//	uint8 UartNor=0;
//	UART_SendWait(UartNor,data,data_length);
//}
//






/*void HSLI_Tx(){

	if(add_sent_byte < num_of_byte){
		UART_TransmitWord(&HSLI_UART,HSLI_TX_Vector[add_sent_byte]);
		add_sent_byte++;
	} else{
		TIMER_Stop(&HSLI_TX_Timer);
	}

}*/

void start_read_from_HSLI(uint8 data_length){

	//UART_AbortReceive(&HSLI_UART);
	//UART_Receive(&HSLI_UART, DMA_Buffer_HSLI_Rx, data_length);
	//LPUART_DRV_AbortReceivingData(INST_LPUART1);

    bufferIdx=0;
    ReadLength=data_length;
	//LPUART_DRV_ReceiveData(INST_LPUART1, DMA_Buffer_HSLI_Rx, 1U);
}

/**@}*/
