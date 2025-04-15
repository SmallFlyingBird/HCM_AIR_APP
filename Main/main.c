

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
#include "Fls.h"
#include "Fee.h"
#include "NvM.h"
#include "Lin.h"
#include "LinTp.h"
#include "LinIf.h"
#include "Dcm.h"
#include "Os.h"
#include "Platform.h"
#include "Os_User.h"
#include "Rte_Nvm.h"

void Fls_AccessStartNotif(void)
{
}
void Fls_AccessFinishNotif(void)
{
}
void Gpt_StimCallBack_5Ms(void)
{
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
    Fls_Init(NULL_PTR);
    Fee_Init(&Fee_ConfigData);
    NvM_Init(NULL_PTR);
    NvM_ReadAll_Immediately();
    LinIf_Side_Init();
    LinTp_Side_Init();
    LinIf_Wakeup(LinConf_LinChannel_LinChannel_1);
    Dcm_Init();	
    StartOS();
}
