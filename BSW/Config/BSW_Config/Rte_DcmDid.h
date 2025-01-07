#ifndef RTE_DCMDID_H
#define RTE_DCMDID_H

#include <Std_Types.h>

#define DataLength_DcmDspData_0xF121 7U
#define DataLength_DcmDspData_0xF125 7U
#define DataLength_DcmDspData_0xF12A 7U
#define DataLength_DcmDspData_0xF12B 7U
#define DataLength_DcmDspData_0x437C 24U
#define DataLength_DcmDspData_0xF18C 4U
#define DataLength_DcmDspData_0xF1A1 8U
#define DataLength_DcmDspData_0xF1A5 8U
#define DataLength_DcmDspData_0xF1AA 8U
#define DataLength_DcmDspData_0xF1AB 8U

#define DataLength_DcmDspData_0xF122 7U
#define DataLength_DcmDspData_0xF124 7U
#define DataLength_DcmDspData_0xF1A2 8U

#define DataLength_DcmDspData_0xF1F0 45U

#define SIDE_DETECT_LEFT_PBL    0x55
#define SIDE_DETECT_RIGHT_PBL   0xAA

#define SW_HIGH_VERSION         0x00
#define SW_MIDDLE_VERSION       0x00
#define SW_LOW_VERSION          0x04

/*车辆平台配置*/
#define VEHICLE_SMART_HS11 0
#define VEHICLE_GEELY_G636 1
#define VEHICLE_PLATFORM VEHICLE_SMART_HS11


typedef struct {
	uint32 Mask;
	uint8 Buffer_DcmDspData_0xF121[DataLength_DcmDspData_0xF121];
	uint8 Buffer_DcmDspData_0xF125[DataLength_DcmDspData_0xF125];
	uint8 Buffer_DcmDspData_0xF12A[DataLength_DcmDspData_0xF12A];
	uint8 Buffer_DcmDspData_0xF12B[DataLength_DcmDspData_0xF12B];
	uint8 Buffer_DcmDspData_0x437C[DataLength_DcmDspData_0x437C];
	uint8 Buffer_DcmDspData_0xF18C[DataLength_DcmDspData_0xF18C];
	uint8 Buffer_DcmDspData_0xF1A1[DataLength_DcmDspData_0xF1A1];
	uint8 Buffer_DcmDspData_0xF1A5[DataLength_DcmDspData_0xF1A5];
	uint8 Buffer_DcmDspData_0xF1AA[DataLength_DcmDspData_0xF1AA];
	uint8 Buffer_DcmDspData_0xF1AB[DataLength_DcmDspData_0xF1AB];
} DcmDspDataStruct;

#define DID_437C_STORE_ADDRESS  0x01016000

extern uint8 g_LRdirection ;
extern DcmDspDataStruct ShareDcmDspDataCPY;
void Rte_Dcm_ShareDID_Iint(void);
void UpdateShareData(DcmDspDataStruct *datasrc);
uint8 Rte_Dcm_0xF1F0_ReadData(uint8 *readData, uint16* readLength);
uint8 Rte_Dcm_0xF121_ReadData(uint8 *readData, uint16* readLength);
uint8 Rte_Dcm_0xF125_ReadData(uint8 *readData, uint16* readLength);
uint8 Rte_Dcm_0xF12A_ReadData(uint8 *readData, uint16* readLength);
uint8 Rte_Dcm_0xF12B_ReadData(uint8 *readData, uint16* readLength);
uint8 Rte_Dcm_0xF18C_ReadData(uint8 *readData, uint16* readLength);
uint8 Rte_Dcm_0xF1A1_ReadData(uint8 *readData, uint16* readLength);
uint8 Rte_Dcm_0xF1A5_ReadData(uint8 *readData, uint16* readLength);
uint8 Rte_Dcm_0xF1AA_ReadData(uint8 *readData, uint16* readLength);
uint8 Rte_Dcm_0xF1AB_ReadData(uint8 *readData, uint16* readLength);
uint8 Rte_Dcm_0x437C_ReadData(uint8 *readData, uint16* readLength);

uint8 Rte_Dcm_0xF122_ReadData(uint8 *readData, uint16* readLength);
uint8 Rte_Dcm_0xF124_ReadData(uint8 *readData, uint16* readLength);
uint8 Rte_Dcm_0xF1A2_ReadData(uint8 *readData, uint16* readLength);


#endif /* RTE_DCMDID_H */
