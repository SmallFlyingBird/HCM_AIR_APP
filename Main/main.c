

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
//#include "Uart.h"
#include "CDD_Dma.h"
#include "Gpt.h"
#include "EcuM.h"
#include "Dio_Service.h"
#include "Gpt_Service.h"
#include "Wdg.h"
#include "Os.h"
#include "Platform.h"
//#include "Example_Lin.h"
//#include "BD18397.h"

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
void Spi_Drv_0_RxuIrqHandler(void)
{
}
void Ex_Spi_MasterSequenceEndNotification(void)
{
    //Spi_ReadIB(SpiConf_SpiChannel_SpiChannel_Buck1, Ex_Spi_MasterRxDataBuffer);
    //Ex_Spi_CheckRxResult(Ex_Spi_MasterRxDataBuffer);
}

// void Uart_Drv_0_IrqHandler(void)
// {
// }


static void Ex_Spi_InitDataBuffer(void)
{
    uint32 Index;
    for (Index = 0U; Index < SPI_MAX_CFG_CHANNELS; Index++)
    {
        Ex_Spi_MasterTxDataBuffer[Index] = Index;
        Ex_Spi_MasterRxDataBuffer[Index] = 0;
        Ex_Spi_SlaveTxDataBuffer[Index] = Index;
        Ex_Spi_SlaveRxDataBuffer[Index] = 0;
    }
}
uint8 count = 0;
static void Ex_Spi_UseCase_01(void)
{
    /* Connect SPI0 with SPI2.
     SPI0: master, async transmission with DMA enabled,
     SPI2: slave, async transmission */

    Ex_Spi_InitDataBuffer();

    //Spi_WriteIB(SpiConf_SpiChannel_SpiChannel_Buck1, Ex_Spi_MasterTxDataBuffer);
    Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_Buck1, Ex_Spi_MasterTxDataBuffer, Ex_Spi_MasterRxDataBuffer, 100U);

    Spi_AsyncTransmit(SpiConf_SpiSequence_SpiSequence_Buck1);

    while (1)
    {
      
        Spi_MainFunction_Handling();
        if (SPI_SEQ_OK == Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_Buck1) &&
            SPI_SEQ_OK == Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_Buck1))
        {
            break;
        }
        
    }
}
#include "Pwm_Cfg.h"
#include "Dio.h"
#include "Pwm.h"
void BD18397_MainFunction(uint16 pwm0);

//ADC采样
#include "AdcDev_Interface.h"
Std_ReturnType CddDriver_AdcDrvInit(void);
void DCMotor_MainFunction(uint8 timebase);
void CddDriver_AdcMainfunction(void);

#include "PowerSupply_Interface.h"
#include "OUVDerate_Interface.h"
void PowerSupplyMainFunction(uint8_t tmiebase);

Std_ReturnType BD18397MainFun(uint8 id);



unsigned int Delay = 0;
uint8 temp = 0;
uint8 pwmread=0;
uint16 Motorcnt=0; //电机 计数器延时
//高边
#include "HighSide_Interface.h"
Std_ReturnType Interface_GetHighSideChannelCurrent(E_HSChannel HSChannel, uint16_t *current);
Std_ReturnType HighSide_Interface_Mainfunction(uint8_t timebase);
uint16_t HSDCur[10]={0};
Std_ReturnType CddDriver_DrvTps2HB35Init(void);
uint16 pwmdata=0x8000;
int main(void)
{
    McalLib_Init();
    Mcu_Init(NULL_PTR);
    Mcu_InitClock(McuConf_McuClockSettingConfig_McuClockSettingConfig_0);
    Wdg_Init(NULL_PTR);
    Lin_Init(NULL_PTR);
    Port_Init(NULL_PTR);
    Pwm_Init(NULL_PTR);
    Spi_Init(NULL_PTR);
    Pwm_Init(NULL_PTR);
    Platform_Init(NULL_PTR);                  
    Adc_Init(NULL_PTR);
    /*keep lin awake*/
    Dio_WriteChannel(DioConf_DioChannel_LIN_Wake_N, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_LIN_SLP_N, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_CC_Boost_EN, STD_LOW);

    // Pwm_SetPeriodAndDuty(PwmConf_PwmChannel_PTE8_PWM_OUT, 50, 0x5199);
    Pwm_SetDutyCycle(PwmConf_PwmChannel_PTE8_PWM_OUT, 0x3399);//0x4899U);//0x1999 约等于20%   //0x3399空载50V
    temp = Dio_ReadChannel(DioConf_DioChannel_CC_Boost_EN);
    // Ex_Spi_UseCase_01();

    //Pwm_SetDutyCycle(PwmConf_PwmChannel_H_L_Ctrl, 0);//0x8000U);//100%=关闭远光
    Pwm_SetPeriodAndDuty(PwmConf_PwmChannel_H_L_Ctrl,5000,0x8000);//0x8000=100%=关闭远光；开5000 频率400HZ 占空比0
    Dio_WriteChannel(DioConf_DioChannel_HSD_EN1, STD_HIGH);//HSE_EN=1 打开风扇
    Dio_WriteChannel(DioConf_DioChannel_HSD_EN2, STD_HIGH);//HSE_EN=1 打开电机
    // Dio_WriteChannel(DioConf_DioChannel_TL_Ctrl, STD_HIGH); //打开TL
    Dio_WriteChannel(DioConf_DioChannel_DRL_Ctrl, STD_HIGH); //打开DRL
    CddDriver_AdcDrvInit();
    BD18397_MainFunction(0);
//高边
    CddDriver_DrvTps2HB35Init();
    while (1)
    {
        Wdg_Service();
//电机
        Motorcnt++;
        if(Motorcnt>=20)
        {
            Motorcnt=0;
            DCMotor_MainFunction(10);
        }      
//远光MOS调光
        // pwmdata=pwmdata-10;
        // if(pwmdata<=20) pwmdata=0x8000;
        // Pwm_SetDutyCycle(PwmConf_PwmChannel_H_L_Ctrl, pwmdata);//0x8000U);//100%=关闭远光
//ADC采样
        CddDriver_AdcMainfunction();
//BUCK
        BD18397MainFun(0);  
        BD18397MainFun(1);
//电源采样和计算
        PowerSupplyMainFunction(10);
// 降额
        OUVDerateMainFunction(10);
        pwmread=Interface_GetDerateRatioOfOUV(); 
        BD18397_MainFunction(pwmread);
//高边获取电流
        Interface_GetHighSideChannelCurrent(0, HSDCur);//E_HSChannel_HS0
//高边诊断
        HighSide_Interface_Mainfunction(10);
        Delay = 10000U;
        while (Delay--)
            ;
    }
        ;
}
