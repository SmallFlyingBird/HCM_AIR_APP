

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Platform.h"
#include "Mcu.h"
#include "Port.h"
#include "Spi.h"
#include "CDD_Dma.h"
#include "SchM_Spi.h"
#include "Wdg.h"
#include "Mcu.h"
#include "Port.h"
#include "Adc.h"
#include "Lin.h"
#include "Dio.h"
#include "Spi.h"
#include "SchM_Spi.h"
#include "Uart.h"
#include "CDD_Dma.h"
#include "Gpt.h"
#include "EcuM.h"
#include "Dio_Service.h"
#include "Gpt_Service.h"

static Spi_DataBufferType Ex_Spi_MasterTxDataBuffer[32];
static Spi_DataBufferType Ex_Spi_MasterRxDataBuffer[32];
static Spi_DataBufferType Ex_Spi_SlaveTxDataBuffer[32];
static Spi_DataBufferType Ex_Spi_SlaveRxDataBuffer[32];

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

// static void Ex_Spi_UseCase_01(void)
// {
//     /* Connect SPI0 with SPI2.
//      SPI0: master, async transmission with DMA enabled,
//      SPI2: slave, async transmission */

//     Ex_Spi_InitDataBuffer();

//     Spi_WriteIB(SpiConf_SpiChannel_SpiChannel_0, Ex_Spi_MasterTxDataBuffer);
//     Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_1, Ex_Spi_SlaveTxDataBuffer, Ex_Spi_SlaveRxDataBuffer, 100U);

//     Spi_AsyncTransmit(SpiConf_SpiSequence_Sequence_Slave);

//     Spi_AsyncTransmit(SpiConf_SpiSequence_Sequence_Master);

//     while (1)
//     {
//         Spi_MainFunction_Handling();
//         if (SPI_SEQ_OK == Spi_GetSequenceResult(SpiConf_SpiSequence_Sequence_Slave) &&
//             SPI_SEQ_OK == Spi_GetSequenceResult(SpiConf_SpiSequence_Sequence_Master))
//         {
//             break;
//         }
//     }
// }

int main(void)
{
    McalLib_Init();

    Mcu_Init(NULL_PTR);
    Mcu_InitClock(McuConf_McuClockSettingConfig_McuClockSettingConfig_0);
    Wdg_Init(NULL_PTR);
    Lin_Init(NULL_PTR);
    Port_Init(NULL_PTR);
    Dma_Init(NULL_PTR);
    Spi_Init(NULL_PTR);
    Platform_Init(NULL_PTR);

    //Ex_Spi_UseCase_01();


    while (1)
        ;
}
