#ifndef RTE_DCM_CALLOUT_H_
#define RTE_DCM_CALLOUT_H_

typedef enum
{
    EOLSession_NotActive = 0,
    EOLSession_Active
} EOLSessionStatusEnum;

typedef enum
{
    EOLControl_Fan = 0,
    EOLSession_CH1B
} EOLControlObjectEnum;

unsigned char Rte_Dcm_GetEolSessionStatus(void);
void Rte_Dcm_SetEolSessionStatus(unsigned char status);

#endif