/*******************************************************************************
**                      Include                                               **
*******************************************************************************/
#include <string.h>
#include "Rte_Dcm_Callout.h"
#include "HCMPlatform.h"
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
#define DID437C_GETCURRENT(channel,buf) (buf[channel] << 8 | buf[channel+1] << 8)
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

extern uint8 eolSessionActive;


uint8 Rte_Dcm_GetEolSessionStatus(void)
{
    return (uint8)eolSessionActive;
}

void Rte_Dcm_SetEolSessionStatus(uint8 status)
{
    eolSessionActive = status;
}



uint16 Get_DidConfigCurrent(uint8 channelid)
{/* read from flash*/
    uint16 rtval = 0;
    uint8 buffer[DID437C_LEHGTH] = {0};
    /* Get 437cdata start address */
	const uint8* DID437C_Data_Addr = (const uint8*)DFLASH_DID437CData_START_ADDRESS; 

	/* Read data */
	memcpy(buffer, DID437C_Data_Addr, DID437C_LEHGTH);

	
	switch (channelid)
	{
	case ChannelID1:
		rtval = (buffer[1] & 0x0F) << 8 |  buffer[0];
		break;
	case ChannelID2:
		rtval = (buffer[2] << 8 | (buffer[1] & 0xF0)) >> 4;
		break;
	case ChannelID3:
		rtval = (buffer[4] & 0x0F) << 8 |  buffer[3];
		break;
	case ChannelID4:
		rtval = (buffer[5] << 8 | (buffer[4] & 0xF0)) >> 4;
		break;
	case ChannelID1_Tap:
		rtval = (buffer[7] & 0x0F) << 8 |  buffer[6];
		break;
	case ChannelID2_Alt:
		rtval = (buffer[8] << 8 | (buffer[7] & 0xF0)) >> 4;
		break;
	default:
		rtval = 0xFFFF;
		break;
	}
	return rtval;
	

}