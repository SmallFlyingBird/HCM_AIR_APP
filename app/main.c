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
#include "Fee.h"
#include "NvM.h"
#include "Lin.h"
#include "LinTp.h"
#include "LinIf.h"
#include "Dcm.h"
#include "Os.h"
#include "Os_User.h"     /* StartOS */
#include "Rte_Nvm.h"    /* NvM_ReadAll_Immediately */
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
#if 0

Spi_DataBufferType EbSrcDataBuffers[EB_BUFFER_LENGTH] = {0};
// Spi_DataBufferType EbSrcDataBuffers[EB_BUFFER_LENGTH] = {0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9};
Spi_DataBufferType EbDecDataBuffers[EB_BUFFER_LENGTH] = {0};
Spi_DataBufferType IbSrcDataBuffers[IB_BUFFER_LENGTH] = {0};
Spi_DataBufferType IbDecDataBuffers[IB_BUFFER_LENGTH] = {0};
Adc_ValueGroupType Adc_Group0RstFIFO[AdcGroup_0_CHANNEL_NUMBER];
Adc_ValueGroupType Adc_Group1RstFIFO[AdcGroup_1_CHANNEL_NUMBER];
Icu_DutyCycleType Dbg_MeasureDutyCycleValue_Ch;

#endif
uint32 Gpt_PtmrNotificationCnt;
// uint16 Adc_Group0An0PhyValue = 0;
// uint16 Adc_Group0An1PhyValue = 0;

/* USER CODE END PV */

/* Private function declare --------------------------------------------------*/
/* USER CODE BEGIN PFDC */
// uint32 Adc_Group0CompleteCnt = 0;
// uint32 Adc_Group1CompleteCnt = 0;
// uint32 Adc_Group2CompleteCnt = 0;
// uint32 Adc_RstReadFailCnt = 0;


volatile uint8 LinSlave_RxData[LIN_SLAVE_DATA_LEN] = {0U};
volatile uint8 LinSlave_TxData[LIN_SLAVE_DATA_LEN] =
{
    0x59U, 0x54U, 0x4DU, 0x33U,
    0x32U, 0x4CU, 0x49U, 0x4EU  /* "YTM32LIN" */
};
volatile uint32 LinSlave_RxCount = 0U;
volatile uint32 LinSlave_TxCount = 0U;

// uint8 Fls_WriteData[1024] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
// uint8 Fls_ReadData[8] = {0};
/* USER CODE END PFDC */
static void Board_Init(void);

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void Gpt_Notification_GptChannelConfiguration_0(void)
{

}



/* USER CODE END 0 */


/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
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

    Board_Init();



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
    //Icu_Init(&Icu_Config);
    Fls_Init(&Fls_Config);
    Fee_Init(&Fee_ConfigData);
    NvM_Init(NULL_PTR);
    NvM_ReadAll_Immediately();
    Lin_WakeupInternal(LinConf_LinChannel_LinChannel0);
    LinIf_Side_Init();
    LinTp_Side_Init();
    LinIf_Wakeup(LinConf_LinChannel_LinChannel0);
    Dcm_Init();	
    StartOS();
}

/* USER CODE BEGIN 4 */
/* USER CODE END 4 */
