

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Platform.h"
#include "Mcu.h"
#include "Port.h"
#include "Adc.h"
#include "Lin.h"
#include "Dio.h"
#include "Spi.h"
#include "Pwm.h"
#include "SchM_Spi.h"
#include "CDD_Dma.h"
#include "Gpt.h"
#include "EcuM.h"
#include "Dio_Service.h"
#include "Gpt_Service.h"
#include "Wdg.h"
#include "Lin.h"
#include "LinTp.h"
#include "LinIf.h"
#include "Dcm.h"
#include "Os.h"
#include "Platform.h"
#include "Os_User.h"

// static Spi_DataBufferType Ex_Spi_MasterTxDataBuffer[32];

// static Spi_DataBufferType Ex_Spi_MasterRxDataBuffer[32];
// static Spi_DataBufferType Ex_Spi_SlaveTxDataBuffer[32];
// static Spi_DataBufferType Ex_Spi_SlaveRxDataBuffer[32];
static uint16 Gpt_5s;

void Fls_AccessStartNotif(void)
{
}
void Fls_AccessFinishNotif(void)
{
}
void Gpt_StimCallBack_5Ms(void)
{
}
void Gpt_StimCallBack_10Ms(void)
{
}
void Gpt_StimCallBack_100Ms(void)
{
    Gpt_5s++;  
}

void Ex_Spi_MasterSequenceEndNotification(void)
{
}

int main(void)
{
    McalLib_Init();
    Mcu_Init(NULL_PTR);
    Mcu_InitClock(McuConf_McuClockSettingConfig_McuClockSettingConfig_0);
    Wdg_Init(NULL_PTR);
    Lin_Init(NULL_PTR);
    Port_Init(NULL_PTR);
    Platform_Init(NULL_PTR);                  
    Adc_Init(NULL_PTR);
    Spi_Init(NULL_PTR);
    Pwm_Init(NULL_PTR);
    Gpt_Init(NULL_PTR);
	Lin_Init(NULL_PTR);
	LinIf_Init(&LinIf_PCConfig);
#ifdef LeftAir
    LinTp_Init(&LinTp_PCConfig_L);
#elif RightAir
    LinTp_Init(&LinTp_PCConfig_R);
#endif
    LinIf_Wakeup(LinConf_LinChannel_LinChannel_1);
    Dcm_Init();
    StartOS();
}
