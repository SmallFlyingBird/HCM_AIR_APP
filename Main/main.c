

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Mcu.h"
/* #include "McalLib.h" */
#include "Port.h"
#include "Adc.h"
#include "Can.h"
#include "Dio.h"
#include "Spi.h"
#include "Uart.h"
#include "CDD_Dma.h"
#include "Gpt.h"
#include "EcuM.h"
#include "Dio_Service.h"
#include "Gpt_Service.h"
#include "RamTst.h"
#include "Os.h"
#include "Platform.h"
#include "SafetyDrv.h"

int main(void)
{
    Safety_CoreSwSelfTest();
    McalLib_Init();
    Mcu_Init(&Mcu_Config);
    Mcu_InitClock(McuConf_McuClockSettingConfig_McuClockSettingConfig_0);
    while(MCU_PLL_LOCKED != Mcu_GetPllStatus());/*only test*/

    Platform_Init(NULL_PTR);
    Safety_Htmsstest();

    RamTst_Init(&RamTstConfigRoot);
	  RamTst_ChangeNumberOfTestedCells(4096);
	  RamTst_RunFullTest();
	/* RamTst_TestResultType RamTstResult = RamTst_GetTestResult(); */

    EcuM_Init();
    while(1);
}
