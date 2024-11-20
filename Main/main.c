

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
#include "Lin.h"
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

void SuspendAllInterrupts(void)
{
}
void ResumeAllInterrupts(void)
{
}
void Fls_AccessStartNotif(void)
{
    SuspendAllInterrupts();
}
void Fls_AccessFinishNotif(void)
{
    ResumeAllInterrupts();
}
void Gpt_StimCallBack_5Ms(void)
{
}
void Gpt_StimCallBack_10Ms(void)
{
}
void Gpt_StimCallBack_100Ms(void)
{
}
void Spi_Drv_0_TxeIrqHandler(void)
{
}
void Spi_Drv_0_TxoIrqHandler(void)
{
}
void Spi_Drv_0_RxfIrqHandler(void)
{
}
void Spi_Drv_0_RxoIrqHandler(void)
{
}
void Ex_Spi_MasterSequenceEndNotification(void)
{
}
void Spi_Drv_0_RxuIrqHandler(void)
{
}

void Uart_Drv_0_IrqHandler(void)
{
}

int main(void)
{
    // Safety_CoreSwSelfTest();
    McalLib_Init();
    Mcu_Init(NULL_PTR);
    // Mcu_Init(&Mcu_Config);
    Mcu_InitClock(McuConf_McuClockSettingConfig_McuClockSettingConfig_0);
    while (MCU_PLL_LOCKED != Mcu_GetPllStatus())
        ; /*only test*/

    Platform_Init(NULL_PTR);
    // Safety_Htmsstest();

    // RamTst_Init(&RamTstConfigRoot);
    // RamTst_ChangeNumberOfTestedCells(4096);
    // RamTst_RunFullTest();
    /* RamTst_TestResultType RamTstResult = RamTst_GetTestResult(); */

    // EcuM_Init();
    while (1)
        ;
}
