#ifndef RTE_DCM_CALLOUT_H_
#define RTE_DCM_CALLOUT_H_


#define DFLASH_DID437CData_START_ADDRESS (0x0101A1A4U)
#define DID437C_LEHGTH (24u)

typedef unsigned char  		uint8;
typedef unsigned short  	uint16;

typedef enum
{
    EOLSession_NotActive = 0,
    EOLSession_Active
} EOLSessionStatusEnum;

typedef enum
{
    EOLControl_Fan = 1,
    EOLSession_CH1B
} EOLControlObjectEnum;

uint16 Get_DidConfigCurrent(uint8 channelid);
uint8 Rte_Dcm_GetEolSessionStatus(void);
void Rte_Dcm_SetEolSessionStatus(uint8 status);
void RTE_DCM_TurnOffBuckBoost(void);
#endif