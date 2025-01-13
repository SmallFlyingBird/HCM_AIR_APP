#include <Rte_DcmDid.h>
#include "Dio_Cfg.h"
#include "Dio.h"
#define LR_DIR_IN_DID_OFFSET 0
DcmDspDataStruct ShareDcmDspDataCPY;
uint8 g_LRdirection = SIDE_DETECT_LEFT_PBL;
static const uint8 Buffer_DcmDspData_0xF122[DataLength_DcmDspData_0xF122] =
{
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
};


static const uint8 Buffer_DcmDspData_0xF124[DataLength_DcmDspData_0xF124] =
{
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
};

#if (VEHICLE_PLATFORM == VEHICLE_SMART_HS11)
static const uint8 Buffer_DcmDspData_0xF1A2_L[DataLength_DcmDspData_0xF1A2] =
{
	0x66, 0x08, 0x27, 0x61, 0x21, 0x20, 0x20, 0x41,
};

static const uint8 Buffer_DcmDspData_0xF1A2_R[DataLength_DcmDspData_0xF1A2] =
{
	0x66, 0x08, 0x27, 0x61, 0x30, 0x20, 0x20, 0x41,
};
#elif(VEHICLE_PLATFORM == VEHICLE_GEELY_G636) 
static const uint8 Buffer_DcmDspData_0xF1A2_L[DataLength_DcmDspData_0xF1A2] =
{
	0x66, 0x08, 0x27, 0x61, 0x21, 0x20, 0x20, 0x41,
};

static const uint8 Buffer_DcmDspData_0xF1A2_R[DataLength_DcmDspData_0xF1A2] =
{
	0x66, 0x08, 0x27, 0x61, 0x30, 0x20, 0x20, 0x41,
};

#endif

uint8 Rte_Dcm_0xF1F0_ReadData(uint8 *readData, uint16* readLength)
{
	/* test multiple transmission */
	uint8 index;
	
	*readLength = 0x1e;
	for(index=0;index<*readLength;index++)
	{
		readData[index]=index;
	}

	return E_OK;
}


uint8 Rte_Dcm_0xF121_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}


uint8 Rte_Dcm_0xF125_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}


uint8 Rte_Dcm_0xF12A_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}


uint8 Rte_Dcm_0xF12B_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0xF18C_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}


uint8 Rte_Dcm_0xF1A1_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}


uint8 Rte_Dcm_0xF1A5_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}


uint8 Rte_Dcm_0xF1AA_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}


uint8 Rte_Dcm_0xF1AB_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0x437C_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0xF122_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0xF124_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}

uint8 Rte_Dcm_0xF1A2_ReadData(uint8 *readData, uint16* readLength)
{
	return E_OK;
}


