/* USER CODE BEGIN Header */
/* you can remove the copyright */

/*
 * Copyright 2020-2025 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * @file main.c
 * @brief
 *
*/

/* USER CODE END Header */
#include "Mcal.h"
/* Includes ------------------------------------------------------------------*/
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
// #define CPU_CLOCK_HZ (12000000U) /* CPU clock frequency in Hz */
#define CM33_SCB_FPSCR_DZCFLAG_MASK                               (0x0002U)
#define EB_BUFFER_LENGTH 128
#define IB_BUFFER_LENGTH 20

#define LIN_SLAVE_CHANNEL      LinConf_LinChannel_LinChannel0
#define LIN_SLAVE_RX_ID        0x10U
#define LIN_SLAVE_TX_ID        0x11U
#define LIN_SLAVE_DATA_LEN     8U

#define TEST_10KHZ 12000
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
uint32 Gpt_PtmrNotificationCnt;
Spi_DataBufferType EbSrcDataBuffers[EB_BUFFER_LENGTH] = {0};
// Spi_DataBufferType EbSrcDataBuffers[EB_BUFFER_LENGTH] = {0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9};
Spi_DataBufferType EbDecDataBuffers[EB_BUFFER_LENGTH] = {0};
Spi_DataBufferType IbSrcDataBuffers[IB_BUFFER_LENGTH] = {0};
Spi_DataBufferType IbDecDataBuffers[IB_BUFFER_LENGTH] = {0};
Adc_ValueGroupType Adc_Group0RstFIFO[AdcGroup_0_CHANNEL_NUMBER];
Adc_ValueGroupType Adc_Group1RstFIFO[AdcGroup_1_CHANNEL_NUMBER];
uint16 Adc_Group0An0PhyValue = 0;
uint16 Adc_Group0An1PhyValue = 0;

Icu_DutyCycleType Dbg_MeasureDutyCycleValue_Ch;
/* USER CODE END PV */

/* Private function declare --------------------------------------------------*/
/* USER CODE BEGIN PFDC */
uint32 Adc_Group0CompleteCnt = 0;
uint32 Adc_Group1CompleteCnt = 0;
uint32 Adc_RstReadFailCnt = 0;


volatile uint8 LinSlave_RxData[LIN_SLAVE_DATA_LEN] = {0U};
volatile uint8 LinSlave_TxData[LIN_SLAVE_DATA_LEN] =
{
    0x59U, 0x54U, 0x4DU, 0x33U,
    0x32U, 0x4CU, 0x49U, 0x4EU  /* "YTM32LIN" */
};
volatile uint32 LinSlave_RxCount = 0U;
volatile uint32 LinSlave_TxCount = 0U;
/* USER CODE END PFDC */
static void Board_Init(void);

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void Ex_Spi_MasterSequenceEndNotification(void)
{

}

void Gpt_Notification_GptChannelConfiguration_0(void)
{
    Gpt_PtmrNotificationCnt++;
    if(Gpt_PtmrNotificationCnt%10 == 0)
        {
            Dio_FlipChannel(DioConf_DioChannel_Trigger_Ctrl);
        }
        // Dio_WriteChannel(DioConf_DioChannel_Trigger_Ctrl,STD_LOW);
}

void CallBack_AdcGroup0(void)
{
    if (Adc_GetGroupStatus(AdcConf_AdcConfigSet_AdcGroup_0) == ADC_STREAM_COMPLETED)
    {
    Adc_ValueGroupType TempRst0[AdcGroup_0_CHANNEL_NUMBER];
    Adc_Group0CompleteCnt++;
    if (E_OK == Adc_ReadGroup(AdcConf_AdcConfigSet_AdcGroup_0, TempRst0))
    {
        Adc_Group0An0PhyValue = TempRst0[0] * 5000 / 4096;
        Adc_Group0An1PhyValue = TempRst0[1] * 5000 / 4096;
    }
    else
    {
        Adc_RstReadFailCnt++;
    }
    }
}

void CallBack_AdcGroup1(void)
{
    Adc_ValueGroupType TempRst1[AdcGroup_1_CHANNEL_NUMBER];
    Adc_Group1CompleteCnt++;
    if (E_OK == Adc_ReadGroup(AdcConf_AdcConfigSet_AdcGroup_1, TempRst1))
    {
        
    }
    else
    {
        Adc_RstReadFailCnt++;
    }
}


Std_ReturnType LinIf_HeaderIndication(NetworkHandleType Channel, Lin_PduType *PduPtr)
{
    uint8 frameId;
    uint8 index;

    if ((Channel != LIN_SLAVE_CHANNEL) || (PduPtr == NULL_PTR))
    {
        return E_NOT_OK;
    }

    /* Pid contains parity bits; lower 6 bits are the frame ID. */
    frameId = PduPtr->Pid & 0x3FU;

    PduPtr->Cs = LIN_ENHANCED_CS;
    PduPtr->Dl = LIN_SLAVE_DATA_LEN;

    /* Master publishes ID 0x10, slave receives 8 bytes. */
    if (frameId == LIN_SLAVE_RX_ID)
    {
        PduPtr->Drc = LIN_FRAMERESPONSE_RX;
        return E_OK;
    }

    /* Slave publishes ID 0x11. */
    if (frameId == LIN_SLAVE_TX_ID)
    {
        for (index = 0U; index < LIN_SLAVE_DATA_LEN; index++)
        {
            PduPtr->SduPtr[index] = LinSlave_TxData[index];
        }

        PduPtr->Drc = LIN_FRAMERESPONSE_TX;
        LinSlave_TxCount++;
        return E_OK;
    }

    PduPtr->Drc = LIN_FRAMERESPONSE_IGNORE;
    return E_NOT_OK;
}

void LinIf_RxIndication(NetworkHandleType Channel, uint8 *Lin_SduPtr)
{
    uint8 index;
    if ((LinConf_LinChannel_LinChannel0 == (uint8)Channel))
    {
        for (index = 0U; index < LIN_SLAVE_DATA_LEN; index++)
        {
            LinSlave_RxData[index] = Lin_SduPtr[index];

            /* Echo received data through ID 0x11. */
            LinSlave_TxData[index] = Lin_SduPtr[index];
        }

        LinSlave_RxCount++;
    }
}
/* USER CODE END 0 */


/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
    /* USER CODE BEGIN 1 */
    uint8 pin_state_read = 0;
    uint8 BufferLoop = 0;
    Mcu_Init(&Mcu_Config);
    Mcu_InitClock(McuConf_McuClockSettingConfig_McuClockSettingConfig_0);
#if (MCU_NO_PLL == STD_OFF)
    while (MCU_PLL_LOCKED != Mcu_GetPllStatus())
    {
        /* Busy wait until the System PLL is locked */
    }
    Mcu_DistributePllClock();
#endif
    /* USER CODE END 1 */ 
    Board_Init();
    /* USER CODE BEGIN 2 */
    Adc_SetupResultBuffer(AdcConf_AdcConfigSet_AdcGroup_0, Adc_Group0RstFIFO);
    Adc_SetupResultBuffer(AdcConf_AdcConfigSet_AdcGroup_1, Adc_Group1RstFIFO);
    Adc_EnableGroupNotification(AdcConf_AdcConfigSet_AdcGroup_0);
    Adc_EnableGroupNotification(AdcConf_AdcConfigSet_AdcGroup_1);

    Gpt_StartTimer(0, 40000);
    Gpt_EnableNotification(0);

    Pwm_SetDutyCycle(PwmConf_PwmChannel_PwmChannel_2, 0x6000U);
    Pwm_SetDutyCycle(PwmConf_PwmChannel_PwmChannel_1, 0x4000U);
    // Pwm_SetPeriodAndDuty(PwmConf_PwmChannel_PwmChannel_1, 12000, 0x4000);
    // Pwm_SetDutyCycle(PwmConf_PwmChannel_PwmChannel_2, 0x6000U);
    Pwm_SetDutyCycle(PwmConf_PwmChannel_PwmChannel_3, 0x3000U);

    Icu_StartSignalMeasurement(IcuConf_IcuChannel_IcuChannel_0);

    for (BufferLoop = 0; BufferLoop < EB_BUFFER_LENGTH; BufferLoop++)
    {
        EbSrcDataBuffers[BufferLoop] = BufferLoop;
    }
    for (BufferLoop = 0; BufferLoop < IB_BUFFER_LENGTH; BufferLoop++)
    {
        IbSrcDataBuffers[BufferLoop] = BufferLoop;
    }
    Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_0, &EbSrcDataBuffers[0], &EbDecDataBuffers[0], 40); /*Used by Job0*/
    
    // Lin_Wakeup(LinConf_LinChannel_LinChannel1);
    Lin_WakeupInternal(LinConf_LinChannel_LinChannel0);
    /* USER CODE END 2 */

    /* Infinite loop */
    /* USER CODE BEGIN WHILE */
    /* test the Dio channel read API */
    while (1)
    {
        /* USER CODE END WHILE */
        /* USER CODE BEGIN 3 */
        pin_state_read = Dio_ReadChannel(DioConf_DioChannel_LR_Identify);
        if (pin_state_read == STD_HIGH)
        {
            /* Do something when the pin is high */
            Dio_WriteChannel(DioConf_DioChannel_Trigger_Ctrl2,STD_HIGH);
        }
        Spi_SetAsyncMode(SPI_POLLING_MODE);
        Dio_WriteChannel(DioConf_DioChannel_SPI_BD_CS1,STD_LOW);
        Spi_AsyncTransmit(SpiConf_SpiSequence_SpiSequence_0);
        while (Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_0) != SPI_SEQ_OK)
        {
            Spi_MainFunction_Handling();
        }
        Dio_WriteChannel(DioConf_DioChannel_SPI_BD_CS1,STD_HIGH);
        Adc_StartGroupConversion(AdcConf_AdcConfigSet_AdcGroup_0);
        Adc_StartGroupConversion(AdcConf_AdcConfigSet_AdcGroup_1);
        
        if (ICU_ACTIVE == Icu_GetInputState(IcuConf_IcuChannel_IcuChannel_0))
        {
            /* Wait until ICU is active */
            Icu_GetDutyCycleValues(IcuConf_IcuChannel_IcuChannel_0, &Dbg_MeasureDutyCycleValue_Ch);
            if (Dbg_MeasureDutyCycleValue_Ch.PeriodTime <= TEST_10KHZ + 100 && Dbg_MeasureDutyCycleValue_Ch.PeriodTime >= TEST_10KHZ - 100)
            {
                Icu_StopSignalMeasurement(IcuConf_IcuChannel_IcuChannel_0);
                while (1);  /*test pass*/
            }
        }
    }

    /* USER CODE END 3 */
}

static void Board_Init(void)
{
    Port_Init(&Port_Config);
    Platform_Init(NULL_PTR);
    Spi_Init(&Spi_Config);
    Adc_Init(&Adc_Config);
    Gpt_Init(&Gpt_Config);
    Pwm_Init(&Pwm_Config);
    Lin_Init(&Lin_Config);
    Icu_Init(&Icu_Config);
}

/* USER CODE BEGIN 4 */
/* USER CODE END 4 */
