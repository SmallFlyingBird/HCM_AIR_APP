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



static uint8 Buffer_DcmDspData_0xF1F0[DataLength_DcmDspData_0xF1F0] =
{
    0x0,APPL_BOOT_MODE,SW_HIGH_VERSION,SW_MIDDLE_VERSION,SW_LOW_VERSION,0x20,VEHICLE_PLATFORM
};


void Rte_Dcm_ShareDID_Iint(void)
{
	const DcmDspDataStruct *pShareDcmDspData = (const DcmDspDataStruct *)(SHARE_DID_INFO_ADDRESS);
    uint8 SampleTimes;
    uint8 tempLevel;
    uint32 DelayCounter = 800;
   

#if(APPL_BOOT_MODE == APPL_BOOT_MODE_SBL)
    g_LRdirection=pShareDcmDspData->LeftRightFlag;
#endif

    // /*����Pflash�������ݵ�ShareDcmDspDataCPY�ṹ����*/
	// if(pShareDcmDspData->Mask == 0x5A5A5A5AU)
	// {
	// 	DP_Memcpy((uint8 *)&ShareDcmDspDataCPY, (const uint8 *)pShareDcmDspData, sizeof(DcmDspDataStruct));
	// }else
	// {
	// 	DP_Memset((uint8 *)&ShareDcmDspDataCPY,0xFF,sizeof(DcmDspDataStruct));
	// }



    // uint8 * Did437CAddress=DID_437C_STORE_ADDRESS;

    // if(Did437CAddress[12] == 0x02)
        g_LRdirection = SIDE_DETECT_RIGHT_PBL;

}


void UpdateShareData(DcmDspDataStruct *datasrc)
{
	DP_Memcpy((uint8 *)(&ShareDcmDspDataCPY), (uint8 *)datasrc, sizeof(DcmDspDataStruct));
}


FL_ResultType Rte_Dcm_0xF1F0_ReadData(uint8 *readData, uint16* readLength)
{
#if (APPL_BOOT_MODE==APPL_BOOT_MODE_PBL)
    Buffer_DcmDspData_0xF1F0[LR_DIR_IN_DID_OFFSET]=g_LRdirection;
#endif
	DP_Memcpy(readData, Buffer_DcmDspData_0xF1F0, DataLength_DcmDspData_0xF1F0);
	*readLength = (uint16)DataLength_DcmDspData_0xF1F0;
	return FL_OK;
}


FL_ResultType Rte_Dcm_0xF121_ReadData(uint8 *readData, uint16* readLength)
{
    uint8 i=0;
    for(i=0;i<DataLength_DcmDspData_0xF121;i++)
    {
        readData[i]=0x00;
    }  
	*readLength = (uint16)DataLength_DcmDspData_0xF121;
	return FL_OK;
}


FL_ResultType Rte_Dcm_0xF125_ReadData(uint8 *readData, uint16* readLength)
{
    uint8 i=0;
    for(i=0;i<DataLength_DcmDspData_0xF125;i++)
    {
        readData[i]=0x00;
    }
	*readLength = (uint16)DataLength_DcmDspData_0xF125;
	return FL_OK;
}


FL_ResultType Rte_Dcm_0xF12A_ReadData(uint8 *readData, uint16* readLength)
{
    uint8 i=0;
    for(i=0;i<DataLength_DcmDspData_0xF12A;i++)
    {
        readData[i]=0x00;
    }
	*readLength = (uint16)DataLength_DcmDspData_0xF12A;
	return FL_OK;
}


FL_ResultType Rte_Dcm_0xF12B_ReadData(uint8 *readData, uint16* readLength)
{
    uint8 i=0;
    for(i=0;i<DataLength_DcmDspData_0xF12B;i++)
    {
        readData[i]=0x00;
    }
	*readLength = (uint16)DataLength_DcmDspData_0xF12B;
	return FL_OK;
}

FL_ResultType Rte_Dcm_0xF18C_ReadData(uint8 *readData, uint16* readLength)
{
	DP_Memcpy(readData, (const uint8 *)ShareDcmDspDataCPY.Buffer_DcmDspData_0xF18C, DataLength_DcmDspData_0xF18C);
	*readLength = (uint16)DataLength_DcmDspData_0xF18C;
	return FL_OK;
}


FL_ResultType Rte_Dcm_0xF1A1_ReadData(uint8 *readData, uint16* readLength)
{
    uint8 i=0;
    uint8 *DidStoreAddress;

    if(g_LRdirection == SIDE_DETECT_LEFT_PBL)
    {
        DidStoreAddress=0x0001FFF0;
        for(i=0;i<DataLength_DcmDspData_0xF1A1;i++)
        {
#if (APPL_BOOT_MODE == APPL_BOOT_MODE_PBL)
            readData[i]=Pflash_DID_F1A1_L[i];
#else
            readData[i]=DidStoreAddress[i];
#endif
        }
    }
    else
    {
        DidStoreAddress=0x0001FFF8;
        for(i=0;i<DataLength_DcmDspData_0xF1A1;i++)
        {
#if (APPL_BOOT_MODE == APPL_BOOT_MODE_PBL)
            readData[i]=Pflash_DID_F1A1_R[i];
#else
            readData[i]=DidStoreAddress[i];
#endif
        }
    }

	*readLength = (uint16)DataLength_DcmDspData_0xF1A1;
	return FL_OK;
}


FL_ResultType Rte_Dcm_0xF1A5_ReadData(uint8 *readData, uint16* readLength)
{
    uint8 i=0;
    uint8 *DidStoreAddress;

    if(g_LRdirection == SIDE_DETECT_LEFT_PBL)
    {
        DidStoreAddress=0x0001FFE0;
        for(i=0;i<DataLength_DcmDspData_0xF1A5;i++)
        {
#if (APPL_BOOT_MODE == APPL_BOOT_MODE_PBL)
            readData[i]=Pflash_DID_F1A5_L[i];
#else
            readData[i]=DidStoreAddress[i];
#endif
        }
    }
    else
    {
        DidStoreAddress=0x0001FFE8;
        for(i=0;i<DataLength_DcmDspData_0xF1A5;i++)
        {
#if (APPL_BOOT_MODE == APPL_BOOT_MODE_PBL)
            readData[i]=Pflash_DID_F1A5_R[i];
#else
            readData[i]=DidStoreAddress[i];
#endif
        }
    }

   
	*readLength = (uint16)DataLength_DcmDspData_0xF1A5;
	return FL_OK;
}


FL_ResultType Rte_Dcm_0xF1AA_ReadData(uint8 *readData, uint16* readLength)
{
	DP_Memcpy(readData, (const uint8 *)ShareDcmDspDataCPY.Buffer_DcmDspData_0xF1AA, DataLength_DcmDspData_0xF1AA);
	*readLength = (uint16)DataLength_DcmDspData_0xF1AA;
	return FL_OK;
}


FL_ResultType Rte_Dcm_0xF1AB_ReadData(uint8 *readData, uint16* readLength)
{
	DP_Memcpy(readData, (const uint8 *)ShareDcmDspDataCPY.Buffer_DcmDspData_0xF1AB, DataLength_DcmDspData_0xF1AB);
	*readLength = (uint16)DataLength_DcmDspData_0xF1AB;
	return FL_OK;
}

FL_ResultType Rte_Dcm_0x437C_ReadData(uint8 *readData, uint16* readLength)
{
	DP_Memcpy(readData, (const uint8 *)DID_437C_STORE_ADDRESS, DataLength_DcmDspData_0x437C);
	*readLength = (uint16)DataLength_DcmDspData_0x437C;
	return FL_OK;
}




FL_ResultType Rte_Dcm_0xF122_ReadData(uint8 *readData, uint16* readLength)
{
	DP_Memcpy(readData, (const uint8 *)Buffer_DcmDspData_0xF122, DataLength_DcmDspData_0xF122);
	*readLength = (uint16)DataLength_DcmDspData_0xF122;
	return FL_OK;
}


FL_ResultType Rte_Dcm_0xF124_ReadData(uint8 *readData, uint16* readLength)
{
	DP_Memcpy(readData, (const uint8 *)Buffer_DcmDspData_0xF124, DataLength_DcmDspData_0xF124);
	*readLength = (uint16)DataLength_DcmDspData_0xF124;
	return FL_OK;
}


FL_ResultType Rte_Dcm_0xF1A2_ReadData(uint8 *readData, uint16* readLength)
{
    if(g_LRdirection == SIDE_DETECT_LEFT_PBL)
    {
        DP_Memcpy(readData, (const uint8 *)Buffer_DcmDspData_0xF1A2_L, DataLength_DcmDspData_0xF1A2);
    }
    else
    {
        DP_Memcpy(readData, (const uint8 *)Buffer_DcmDspData_0xF1A2_R, DataLength_DcmDspData_0xF1A2);
    }
	
	*readLength = (uint16)DataLength_DcmDspData_0xF1A2;
	return FL_OK;
}


