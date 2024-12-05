

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
    //Spi_ReadIB(SpiConf_SpiChannel_SpiChannel_Buck1, Ex_Spi_MasterRxDataBuffer);
    //Ex_Spi_CheckRxResult(Ex_Spi_MasterRxDataBuffer);
}




// static void Ex_Spi_InitDataBuffer(void)
// {
//     uint32 Index;
//     for (Index = 0U; Index < SPI_MAX_CFG_CHANNELS; Index++)
//     {
//         Ex_Spi_MasterTxDataBuffer[Index] = Index;
//         Ex_Spi_MasterRxDataBuffer[Index] = 0;
//         Ex_Spi_SlaveTxDataBuffer[Index] = Index;
//         Ex_Spi_SlaveRxDataBuffer[Index] = 0;
//     }
// }
// uint8 count = 0;
// static void Ex_Spi_UseCase_01(void)
// {
//     /* Connect SPI0 with SPI2.
//      SPI0: master, async transmission with DMA enabled,
//      SPI2: slave, async transmission */

//     Ex_Spi_InitDataBuffer();

//     //Spi_WriteIB(SpiConf_SpiChannel_SpiChannel_Buck1, Ex_Spi_MasterTxDataBuffer);
//     Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_Buck1, Ex_Spi_MasterTxDataBuffer, Ex_Spi_MasterRxDataBuffer, 100U);

//     Spi_AsyncTransmit(SpiConf_SpiSequence_SpiSequence_Buck1);

//     while (1)
//     {
      
//         Spi_MainFunction_Handling();
//         if (SPI_SEQ_OK == Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_Buck1) &&
//             SPI_SEQ_OK == Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_Buck1))
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
    Platform_Init(NULL_PTR);                  
    Adc_Init(NULL_PTR);
    Spi_Init(NULL_PTR);
    Pwm_Init(NULL_PTR);
    Gpt_Init(NULL_PTR);
    StartOS();
}
