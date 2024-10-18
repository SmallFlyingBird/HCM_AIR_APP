/*
 * Drv8889.c
 *
 *  Created on: 2024��1��23��
 *      Author: mihuiliang
 */

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HcmPlatform.h"
#include "AswInterfaceManager.h"
#include "Drv8889.h"
#include "Dio_Cfg.h"
#include "Dio.h"
#include "Spi_Cfg.h"
#include "Spi.h"
#include "Os_Cfg.h"
#include "Os.h"
/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
static Std_ReturnType Drv8889_DeviceInit(void *ptr);
static Std_ReturnType Drv8889_DeviceDeInit(void *ptr);
static Std_ReturnType Drv8889_Read(void *ptr);
static Std_ReturnType Drv8889_Write(void *ptr);
static Std_ReturnType Drv8889_Mainfunction(void *ptr);

static S_MotorDrv_Dev g_S_MotorDrv_Dev_GEN2[MAX_MOTOR_NUM] = {
    {
        .DeviceType = E_MotorDrvDev_TI8889,
        .MotorType = E_MotorTpye_Swiveling,
        .Device_id = 0,
        .DeviceInit = Drv8889_DeviceInit,
        .DeviceDeInit = Drv8889_DeviceDeInit,
        .Read = Drv8889_Read,
        .Write = Drv8889_Write,
        .Mainfunction = Drv8889_Mainfunction,
        .ptNext = NULL,
    },
    {
        .DeviceType = E_MotorDrvDev_TI8889,
        .MotorType = E_MotorTpye_Leveling,
        .Device_id = 1,
        .DeviceInit = Drv8889_DeviceInit,
        .DeviceDeInit = Drv8889_DeviceDeInit,
        .Read = Drv8889_Read,
        .Write = Drv8889_Write,
        .Mainfunction = Drv8889_Mainfunction,
        .ptNext = NULL,
    },
};

static S_MotorDrv_Dev g_S_MotorDrv_Dev_GEN1[MAX_MOTOR_NUM] = {
    {
        .DeviceType = E_MotorDrvDev_TI8889,
        .MotorType = E_MotorTpye_Leveling,
        .Device_id = 0,
        .DeviceInit = Drv8889_DeviceInit,
        .DeviceDeInit = Drv8889_DeviceDeInit,
        .Read = Drv8889_Read,
        .Write = Drv8889_Write,
        .Mainfunction = Drv8889_Mainfunction,
        .ptNext = NULL,
    },
    {
        .DeviceType = E_MotorDrvDev_TI8889,
        .MotorType = E_MotorTpye_Swiveling,
        .Device_id = 1,
        .DeviceInit = Drv8889_DeviceInit,
        .DeviceDeInit = Drv8889_DeviceDeInit,
        .Read = Drv8889_Read,
        .Write = Drv8889_Write,
        .Mainfunction = Drv8889_Mainfunction,
        .ptNext = NULL,
    },
};

static S_DRV8889DevManager g_S_DRV8889DevManager[MAX_MOTOR_NUM] = {
    {
        .spi_error_cnt = 0,
    },
    {
        .spi_error_cnt = 0,
    }};

/****************************************************************
 *                                                              *
 *                   Global Variable Define                     *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/
static void DRV8889_DrvOFF(uint8_t ucPinStatus, uint8_t dev_id)
{
    if (dev_id == 0)
    {
        if (ucPinStatus == PIN_LOW)
            Dio_WriteChannel(DioConf_DioChannel_MotorOut_Con_ALS, STD_LOW);
        else
            Dio_WriteChannel(DioConf_DioChannel_MotorOut_Con_ALS, STD_HIGH);
    }
    if (dev_id == 1)
    {
        if (ucPinStatus == PIN_LOW)
            Dio_WriteChannel(DioConf_DioChannel_MotorOut_Con_AFS, STD_LOW);
        else
            Dio_WriteChannel(DioConf_DioChannel_MotorOut_Con_AFS, STD_HIGH);
    }
}

static void DisableMotorOutput(uint8_t dev_id)
{
    DRV8889_DrvOFF(PIN_HIGH, dev_id);
}

static void EnableMotorOutput(uint8_t dev_id)
{
    DRV8889_DrvOFF(PIN_LOW, dev_id);
}

static uint8_t DRV8889_SPI_WriteCmd(uint8_t dev_id, uint8_t WrAddr, uint8_t usTxData)
{
    uint8_t ucStatus = 0;
#if 1
    uint8_t Spi_TxBuffer[2] = {0}, Spi_RxBuffer[2] = {0};

    if (WrAddr < 12)
    {

        Spi_TxBuffer[1] = (WrAddr << 1) & 0X3E;
        Spi_TxBuffer[0] = usTxData;
        GetResource(OsResource_BoostBuckSpi);
        if (dev_id == 0)
        {
            Spi_SetupEB(SpiConf_SpiJob_SpiJob_Motor2, Spi_TxBuffer, Spi_RxBuffer, 2);
            Spi_SyncTransmit(SpiConf_SpiJob_SpiJob_Motor2);
        }

        else if (dev_id == 1)
        {
            Spi_SetupEB(SpiConf_SpiJob_SpiJob_Motor1, Spi_TxBuffer, Spi_RxBuffer, 2);
            Spi_SyncTransmit(SpiConf_SpiJob_SpiJob_Motor1);
        }
        ReleaseResource(OsResource_BoostBuckSpi);
        if ((Spi_RxBuffer[1] & 0xc0) == 0xc0)
        {
            /*success*/
            ucStatus = 1;
        }
    }
#endif
    return ucStatus;
}

static uint8_t DRV8889_SPI_ReadCmd(uint8_t dev_id, uint8_t WrAddr, uint8_t *usRxData)
{

    uint8_t ucStatus = 0;
#if 1
    uint8_t Spi_TxBuffer[2] = {0}, Spi_RxBuffer[2] = {0};

    if (WrAddr < 12)
    {
        Spi_TxBuffer[1] = WrAddr * 2 + 64;
        Spi_TxBuffer[0] = 0;
         GetResource(OsResource_BoostBuckSpi);
        if (dev_id == 0)
        {
            Spi_SetupEB(SpiConf_SpiJob_SpiJob_Motor2, Spi_TxBuffer, Spi_RxBuffer, 2);
            Spi_SyncTransmit(SpiConf_SpiJob_SpiJob_Motor2);
        }
        else if (dev_id == 1)
        {
            Spi_SetupEB(SpiConf_SpiJob_SpiJob_Motor1, Spi_TxBuffer, Spi_RxBuffer, 2);
            Spi_SyncTransmit(SpiConf_SpiJob_SpiJob_Motor1);
        }
        ReleaseResource(OsResource_BoostBuckSpi);

        if ((Spi_RxBuffer[1] & 0xc0) == 0xc0)
        {
            *usRxData = Spi_RxBuffer[0];
            /*success*/
            /*清除Spi故障计数器*/
            g_S_DRV8889DevManager[dev_id].spi_error_cnt = 0;
            ucStatus = 1;
        }
        else
        {
            g_S_DRV8889DevManager[dev_id].spi_error_cnt = CNT_INC(g_S_DRV8889DevManager[dev_id].spi_error_cnt, STEP_1, DRV8889_SPIERROR_LIMIT);
        }
    }
#endif
    return ucStatus;
}

static Std_ReturnType Drv8889_SetOutputCurrent(uint8_t dev_id, uint16_t current)
{
    Std_ReturnType rtval = E_OK;
    static uint16_t CurrentTable[16] = {1136, 1065, 994, 923, 852, 781, 710, 639, 568, 497, 426, 355, 284, 213, 142, 71};
    uint8_t curindex = 0;

    if (current == 0)
    {
#if 1
        DisableMotorOutput(dev_id);
        g_S_DRV8889DevManager[dev_id].OutputDisableFlag = 1;
        return E_OK;
#else
        /*Disable Drv Output*/
        g_S_DRV8889DevManager[dev_id].crreg.CR2.b2.CR2_DIS_OUT = 1;
        if (DRV8889_SPI_WriteCmd(dev_id, DRV8889_CTRL2, (g_S_DRV8889DevManager[dev_id].crreg.CR2.CR2_Value)) == 1)
        {
            g_S_DRV8889DevManager[dev_id].OutputDisableFlag = 1;
            return E_OK;
        }
        else
        {
            return E_NOT_OK;
        }
#endif
    }

    if (g_S_DRV8889DevManager[dev_id].OutputDisableFlag == 1)
    {
        /*Enable Drv Output*/
        g_S_DRV8889DevManager[dev_id].crreg.CR2.b2.CR2_DIS_OUT = 0;
#if 1
        EnableMotorOutput(dev_id);
#else
        if (DRV8889_SPI_WriteCmd(dev_id, DRV8889_CTRL2, (g_S_DRV8889DevManager[dev_id].crreg.CR2.CR2_Value)) == 1)
        {
            g_S_DRV8889DevManager[dev_id].OutputDisableFlag = 0;
        }
        else
        {
            return E_NOT_OK;
        }
#endif
    }

    for (curindex = 0; curindex < 16; curindex++)
    {
        if (current >= CurrentTable[curindex])
        {
            break;
        }
    }
    if (curindex == 16)
        curindex = 15;
    /*
     * Vref=2.5v  2.5/2.2=1.136A
     *
     * CR1_TRQ_DAC=0x00  100%		2.5/2.2*100%	=	1136mA
     * CR1_TRQ_DAC=0x01  93.75%		 2.5/2.2*93.75%	=	1065mA
     * CR1_TRQ_DAC=0x02  87.5%		2.5/2.2*87.5%	=	994mA
     * CR1_TRQ_DAC=0x03  81.25%		2.5/2.2*81.25%	=	923mA
     * CR1_TRQ_DAC=0x04  75%		2.5/2.2*75%		=	852mA
     * CR1_TRQ_DAC=0x05  68.75%		2.5/2.2*68.75%	=	781mA
     * CR1_TRQ_DAC=0x06  62.5%		2.5/2.2*62.5%	=	710mA
     * CR1_TRQ_DAC=0x07  56.25%		2.5/2.2*56.25%	=	639mA
     * CR1_TRQ_DAC=0x08  50.00%		2.5/2.2*50.25%	=	568mA
     * CR1_TRQ_DAC=0x09  43.75%		2.5/2.2*43.75%	=	497mA
     * CR1_TRQ_DAC=0x0A  37.5 %		2.5/2.2*37.50%	=	426mA
     * CR1_TRQ_DAC=0x0B  31.25%		2.5/2.2*31.25%	=	355mA
     * CR1_TRQ_DAC=0x0C  25%		2.5/2.2*25%		=	284mA
     * CR1_TRQ_DAC=0x0D  18.75%		2.5/2.2*18.75%	=	213mA
     * CR1_TRQ_DAC=0x0E  12.5%		2.5/2.2*12.5%	=	142mA
     * CR1_TRQ_DAC=0x0F  6.25%		2.5/2.2*6.25%	=	71mA
     */
    g_S_DRV8889DevManager[dev_id].crreg.CR1.b1.CR1_TRQ_DAC = curindex;
    if (DRV8889_SPI_WriteCmd(dev_id, DRV8889_CTRL1, (g_S_DRV8889DevManager[dev_id].crreg.CR1.CR1_Value)) == 1)
    {
        rtval = E_OK;
    }
    else
    {
        rtval = E_NOT_OK;
    }
    return rtval;
}

static Std_ReturnType Drv8889_SetDirectionPinState(uint8_t dev_id, E_MotorDirPinState PinState)
{

    if (dev_id == 0)
    {
        if (PinState == E_MotorDirPinState_LOW)
        {
            Dio_WriteChannel(DioConf_DioChannel_ALS_DIR, STD_LOW);
        }
        else
        {
            Dio_WriteChannel(DioConf_DioChannel_ALS_DIR, STD_HIGH);
        }
    }
    else if (dev_id == 1)
    {
        if (PinState == E_MotorDirPinState_HIGH)
        {
            Dio_WriteChannel(DioConf_DioChannel_AFS_DIR, STD_LOW);
        }
        else
        {
            Dio_WriteChannel(DioConf_DioChannel_AFS_DIR, STD_HIGH);
        }
    }

    return E_OK;
}

static Std_ReturnType Drv8889_SetStepMode(uint8_t dev_id, E_MotorMicroStepMode MotorMicroStepMode)
{
    Std_ReturnType rtval = E_OK;
    switch (MotorMicroStepMode)
    {
    case MotorMicroStepMode_1:
        /*full step*/
        g_S_DRV8889DevManager[dev_id].crreg.CR3.b3.CR3_MICROSTEP_MODE = 0;
        break;
    case MotorMicroStepMode_2:
        /*1/2*/
        g_S_DRV8889DevManager[dev_id].crreg.CR3.b3.CR3_MICROSTEP_MODE = 3;
        break;
    case MotorMicroStepMode_4:
        /*1/4*/
        g_S_DRV8889DevManager[dev_id].crreg.CR3.b3.CR3_MICROSTEP_MODE = 4;
        break;
    case MotorMicroStepMode_8:
        /*1/8*/
        g_S_DRV8889DevManager[dev_id].crreg.CR3.b3.CR3_MICROSTEP_MODE = 5;
        break;
    case MotorMicroStepMode_16:
        /*1/16*/
        g_S_DRV8889DevManager[dev_id].crreg.CR3.b3.CR3_MICROSTEP_MODE = 6;
        break;
    case MotorMicroStepMode_32:
        /*1/32*/
        g_S_DRV8889DevManager[dev_id].crreg.CR3.b3.CR3_MICROSTEP_MODE = 7;
        break;
    case MotorMicroStepMode_64:
        /*1/64*/
        g_S_DRV8889DevManager[dev_id].crreg.CR3.b3.CR3_MICROSTEP_MODE = 8;
        break;
    case MotorMicroStepMode_128:
        /*1/128*/
        g_S_DRV8889DevManager[dev_id].crreg.CR3.b3.CR3_MICROSTEP_MODE = 9;
        break;
    case MotorMicroStepMode_256:
        /*1/256*/
        g_S_DRV8889DevManager[dev_id].crreg.CR3.b3.CR3_MICROSTEP_MODE = 10;
        break;
    default:
        /*1/2*/
        g_S_DRV8889DevManager[dev_id].crreg.CR3.b3.CR3_MICROSTEP_MODE = 3;
        break;
    }
    if (DRV8889_SPI_WriteCmd(dev_id, DRV8889_CTRL3, g_S_DRV8889DevManager[dev_id].crreg.CR3.CR3_Value) == 1)
        rtval = E_OK;
    else
        rtval = E_NOT_OK;

    return rtval;
}
static Std_ReturnType Drv8889_SetStallDetSwitch(uint8_t dev_id, uint8_t val)
{
    Std_ReturnType rtval = E_OK;
    if (val)
    {
        g_S_DRV8889DevManager[dev_id].crreg.CR5.b5.CR5_EN_STL = 1;
    }
    else
    {
        g_S_DRV8889DevManager[dev_id].crreg.CR5.b5.CR5_EN_STL = 0;
    }
    if (DRV8889_SPI_WriteCmd(dev_id, DRV8889_CTRL5, g_S_DRV8889DevManager[dev_id].crreg.CR5.CR5_Value) == 1)
        rtval = E_OK;
    else
        rtval = E_NOT_OK;

    return rtval;
}

static Std_ReturnType Drv8889_SetOpenLoadDetSwitch(uint8_t dev_id, uint8_t val)
{
    Std_ReturnType rtval = E_OK;
    if (val)
    {
        g_S_DRV8889DevManager[dev_id].crreg.CR4.b4.CR4_EN_OL = 1;
    }
    else
    {
        g_S_DRV8889DevManager[dev_id].crreg.CR4.b4.CR4_EN_OL = 0;
    }

    if (DRV8889_SPI_WriteCmd(dev_id, DRV8889_CTRL5, g_S_DRV8889DevManager[dev_id].crreg.CR5.CR5_Value) == 1)
        rtval = E_OK;
    else
        rtval = E_NOT_OK;

    return rtval;
}

static Std_ReturnType Drv8889_GetTemperatureInfo(uint8_t dev_id, S_MotorTemperatureDataSrc *DataSrc)
{
    uint8_t readdata = 0;
    Std_ReturnType rtval = E_OK;
    ;

    if (DRV8889_SPI_ReadCmd(dev_id, DRV8889_DIAG_STATUS_2, &readdata) == 1)
    {
        if ((readdata & FAULT_Status2_UTW_MASK) != 0)
            DataSrc->MotorTemperatureInfo = E_MotorMotorTemp_LowTempWarning;
        else if ((readdata & FAULT_Status2_OTW_MASK) != 0)
            DataSrc->MotorTemperatureInfo = E_MotorMotorTemp_HighTempWarning;
        else if ((readdata & FAULT_Status2_OTS_MASK) != 0)
            DataSrc->MotorTemperatureInfo = E_MotorMotorTemp_HighTempShutDown;

        rtval = E_OK;
    }
    else
    {
        DataSrc->MotorTemperatureInfo = E_MotorMotorTemp_Normal;
        rtval = E_NOT_OK;
    }

    return rtval;
}

static Std_ReturnType Drv8889_GetErrorInfo(uint8_t dev_id, S_MotorDiagnoseDataSrc *DataSrc)
{
    uint8_t readdata = 0;
    Std_ReturnType rtval = E_OK;

    DataSrc->DevErrorTypt.DevError = 0;


    if (g_S_DRV8889DevManager[dev_id].spi_error_cnt >= DRV8889_SPIERROR_LIMIT)
    {
        /*通信错误达到上限，直接返回*/
        DataSrc->DevErrorTypt.bits.ComError = 1;
        return rtval;
    }

    if (DRV8889_SPI_ReadCmd(dev_id, DRV8889_FAULT_STATUS, &readdata) == 1)
    {
        DataSrc->DevErrorTypt.bits.ComError = 0;

        if ((readdata & FAULT_Status_STL_MASK) != 0)
            DataSrc->DevErrorTypt.bits.Stall = 1;
        else
            DataSrc->DevErrorTypt.bits.Stall = 0;

        if ((readdata & FAULT_Status_OL_MASK) != 0)
            DataSrc->DevErrorTypt.bits.DevOpenLoad = 1;
        else
            DataSrc->DevErrorTypt.bits.DevOpenLoad = 0;

        if ((readdata & FAULT_Status_OCP_MASK) != 0)
            DataSrc->DevErrorTypt.bits.DevShort = 1;
        else
            DataSrc->DevErrorTypt.bits.DevShort = 0;

        if ((readdata & FAULT_Status_UVLO_MASK) != 0)
            DataSrc->DevErrorTypt.bits.UV = 1;
        else
            DataSrc->DevErrorTypt.bits.UV = 0;

        if ((readdata & FAULT_Status_TF_MASK) != 0)
        {
            if (DRV8889_SPI_ReadCmd(dev_id, DRV8889_DIAG_STATUS_2, &readdata) == 1)
            {
                if ((readdata & FAULT_Status2_OTS_MASK) != 0)
                    DataSrc->DevErrorTypt.bits.ThermalShuTDown = 1;
                else
                    DataSrc->DevErrorTypt.bits.ThermalShuTDown = 0;

                if ((readdata & FAULT_Status2_OTW_MASK) != 0)
                    DataSrc->DevErrorTypt.bits.TempWarning = 1;
                else
                    DataSrc->DevErrorTypt.bits.TempWarning = 0;
            }
        }

        g_S_DRV8889DevManager[dev_id].crreg.CR4.b4.CR4_CLR_FLT = 1;
        DRV8889_SPI_WriteCmd(dev_id, DRV8889_CTRL4, g_S_DRV8889DevManager[dev_id].crreg.CR4.CR4_Value);
    }
    else
    {
        DataSrc->DevErrorTypt.bits.ComError = 1;
    }
    return rtval;
}

static Std_ReturnType Drv8889_DeviceInit(void *ptr)
{
    Std_ReturnType rtval = E_OK;
    uint8_t dev_id;
    S_MotorDrvDataPackets *ptMotorDrvDataPackets;
    S_MotorDrvInitDataSrc *MotorDrvInitDataSrc;
    ptMotorDrvDataPackets = (S_MotorDrvDataPackets *)ptr;
    uint8_t readdata = 0;

    if (ptMotorDrvDataPackets->MotorDrvDataType != E_MotorDrvDataType_DevInit)
        return E_NOT_OK;

    dev_id = ptMotorDrvDataPackets->Device_id;
    MotorDrvInitDataSrc = (S_MotorDrvInitDataSrc *)(ptMotorDrvDataPackets->datasrc);

    /*Enable motor*/
    EnableMotorOutput(dev_id);

    /*Clear Fault*/
    DRV8889_SPI_WriteCmd(dev_id, DRV8889_CTRL4, 0x80);

    /*Set Hold Current*/
    Drv8889_SetOutputCurrent(dev_id, MotorDrvInitDataSrc->outputcurrent);

    /*Set Dir pin state*/
    Drv8889_SetDirectionPinState(dev_id, MotorDrvInitDataSrc->DirPinState);

    g_S_DRV8889DevManager[dev_id].crreg.CR1.b1.CR1_SLEW_RATE = 0x03;
    DRV8889_SPI_WriteCmd(dev_id, DRV8889_CTRL1, g_S_DRV8889DevManager[dev_id].crreg.CR1.CR1_Value);

    /*
     *
     * DECAY
     * 000b = Increasing SLOW, decreasing SLOW
     * 001b = Increasing SLOW, decreasing MIXED 30%
     * 010b = Increasing SLOW, decreasing MIXED 60%
     * 011b = Increasing SLOW, decreasing FAST
     * 100b = Increasing MIXED 30%, decreasing MIXED 30%
     * 101b = Increasing MIXED 60%, decreasing MIXED 60%
     * 110b = Smart tune Dynamic Decay
     * 111b = Smart tune Ripple Control
     *
     *
     *
     */
    g_S_DRV8889DevManager[dev_id].crreg.CR2.b2.CR2_DIS_OUT = 0;
    g_S_DRV8889DevManager[dev_id].crreg.CR2.b2.CR2_TOFF = 0x01;
    g_S_DRV8889DevManager[dev_id].crreg.CR2.b2.CR2_DECAY = 7;
    DRV8889_SPI_WriteCmd(dev_id, DRV8889_CTRL2, g_S_DRV8889DevManager[dev_id].crreg.CR2.CR2_Value);

    /*
     * 	MICROSTEP_MODE=0000b = Full step (2-phase excitation) with 100% current
     *	MICROSTEP_MODE=0001b = Full step (2-phase excitation) with 71% current
     *	MICROSTEP_MODE=0010b = Non-circular 1/2 step
     *	MICROSTEP_MODE=0011b = 1/2 step
     *	MICROSTEP_MODE=0100b = 1/4 step
     *	MICROSTEP_MODE=0101b = 1/8 step
     *	MICROSTEP_MODE=0110b = 1/16 step
     *	MICROSTEP_MODE=0111b = 1/32 step
     *	MICROSTEP_MODE=1000b = 1/64 step
     *	MICROSTEP_MODE=1001b = 1/128 step
     *	MICROSTEP_MODE=1010b = 1/256 step
     *	MICROSTEP_MODE=1011b to 1111b = Reserved
     */
    g_S_DRV8889DevManager[dev_id].crreg.CR3.b3.CR3_DIR = 0;
    g_S_DRV8889DevManager[dev_id].crreg.CR3.b3.CR3_STEP = 0;
    g_S_DRV8889DevManager[dev_id].crreg.CR3.b3.CR3_SPI_DIR = 0;
    g_S_DRV8889DevManager[dev_id].crreg.CR3.b3.CR3_SPI_STEP = 0;

    Drv8889_SetStepMode(dev_id, MotorDrvInitDataSrc->MicroStepMode);
    /*
     *
     * OTSD_MODE
     * 0b = Overtemperature condition will cause latched fault
     * 1b = Overtemperature condition will cause automatic recovery fault
     *
     */
    g_S_DRV8889DevManager[dev_id].crreg.CR4.b4.CR4_CLR_FLT = 1;
    g_S_DRV8889DevManager[dev_id].crreg.CR4.b4.CR4_LOCK = 3;
    g_S_DRV8889DevManager[dev_id].crreg.CR4.b4.CR4_EN_OL = 0;
    g_S_DRV8889DevManager[dev_id].crreg.CR4.b4.CR4_OCP_MODE = 0;
    g_S_DRV8889DevManager[dev_id].crreg.CR4.b4.CR4_OTSD_MODE = 1;
    g_S_DRV8889DevManager[dev_id].crreg.CR4.b4.CR4_TW_REP = 0;
    DRV8889_SPI_WriteCmd(dev_id, DRV8889_CTRL4, g_S_DRV8889DevManager[dev_id].crreg.CR4.CR4_Value);

    g_S_DRV8889DevManager[dev_id].crreg.CR5.b5.CR5_STL_LRN = 0;
    g_S_DRV8889DevManager[dev_id].crreg.CR5.b5.CR5_EN_STL = 0; /*close stall det*/
    g_S_DRV8889DevManager[dev_id].crreg.CR5.b5.CR5_STL_REP = 0;
    DRV8889_SPI_WriteCmd(dev_id, DRV8889_CTRL5, g_S_DRV8889DevManager[dev_id].crreg.CR5.CR5_Value);

    g_S_DRV8889DevManager[dev_id].crreg.CR6.b6.CR6_STALL_TH = MotorDrvInitDataSrc->stallthreshold;
    DRV8889_SPI_WriteCmd(dev_id, DRV8889_CTRL6, g_S_DRV8889DevManager[dev_id].crreg.CR6.CR6_Value);

    if (DRV8889_SPI_ReadCmd(dev_id, DRV8889_CTRL1, &readdata))
    {
        if (readdata == (g_S_DRV8889DevManager[dev_id].crreg.CR1.CR1_Value))
        {
            rtval = E_OK;
        }
        else
        {
            /*disable motordriver to protect motro*/
            DisableMotorOutput(dev_id);
            rtval = E_NOT_OK;
        }
    }
    else
    {
        /*disable motordriver to protect motro*/
        DisableMotorOutput(dev_id);
        /*DRV8889_DrvOFF(PIN_LOW,dev_id);*/
        rtval = E_NOT_OK;
    }

    return rtval;
}
static Std_ReturnType Drv8889_DeviceDeInit(void *ptr)
{
    Std_ReturnType rtval = E_OK;

    return rtval;
}
static Std_ReturnType Drv8889_Read(void *ptr)
{
    Std_ReturnType rtval = E_OK;
    uint8_t dev_id;

    S_MotorDrvDataPackets *MotorDrvDataPackets;

    MotorDrvDataPackets = (S_MotorDrvDataPackets *)ptr;
    dev_id = MotorDrvDataPackets->Device_id;

    switch (MotorDrvDataPackets->MotorDrvDataType)
    {
    case E_MotorDrvDataType_DevInit:
        break;
    case E_MotorDrvDataType_DevDeInit:
        break;
    case E_MotorDrvDataType_DevStepMode:
        break;
    case E_MotorDrvDataType_DevStallThreshold:
        break;
    case E_MotorDrvDataType_DevStallDetectSwitchState:
        break;
    case E_MotorDrvDataType_DevDiagnose:
        rtval |= Drv8889_GetErrorInfo(dev_id, ((S_MotorDiagnoseDataSrc *)(MotorDrvDataPackets->datasrc)));
        break;
    case E_MotorDrvDataType_DevTemperature:
        rtval |= Drv8889_GetTemperatureInfo(dev_id, ((S_MotorTemperatureDataSrc *)(MotorDrvDataPackets->datasrc)));
        break;
    case E_MotorDrvDataType_DevOutputCurrent:
        break;
    case E_MotorDrvDataType_DevDirPolarity:
        break;
    }

    return rtval;
}
static Std_ReturnType Drv8889_Write(void *ptr)
{
    Std_ReturnType rtval = E_OK;
    uint8_t dev_id;

    S_MotorDrvDataPackets *MotorDrvDataPackets;

    MotorDrvDataPackets = (S_MotorDrvDataPackets *)ptr;
    dev_id = MotorDrvDataPackets->Device_id;

    switch (MotorDrvDataPackets->MotorDrvDataType)
    {
    case E_MotorDrvDataType_DevInit:
        break;
    case E_MotorDrvDataType_DevDeInit:
        break;
    case E_MotorDrvDataType_DevStepMode:
        rtval |= Drv8889_SetStepMode(dev_id, ((S_MotorDrvStepModeDataSrc *)(MotorDrvDataPackets->datasrc))->MotorMicroStepMode);
        break;
    case E_MotorDrvDataType_DevStallThreshold:

        break;
    case E_MotorDrvDataType_DevStallDetectSwitchState:
        rtval |= Drv8889_SetStallDetSwitch(dev_id, ((S_DevStallDetectSwitchStateDataSrc *)(MotorDrvDataPackets->datasrc))->StallDetectState);
        break;
    case E_MotorDrvDataType_DevDiagnose:
        break;
    case E_MotorDrvDataType_DevTemperature:
        break;
    case E_MotorDrvDataType_DevOutputCurrent:
        rtval |= Drv8889_SetOutputCurrent(dev_id, ((S_MotorDrvOutputCurrentDataSrc *)(MotorDrvDataPackets->datasrc))->MotorCurrent);
        break;
    case E_MotorDrvDataType_DevDirPolarity:
        rtval |= Drv8889_SetDirectionPinState(dev_id, ((S_MotorDrvDirPolarityDataSrc *)(MotorDrvDataPackets->datasrc))->MotorDirPinState);
        break;
    case E_MotorDrvDataType_DevOpenLoadDetectSwitchState:
        rtval |= Drv8889_SetOpenLoadDetSwitch(dev_id, ((S_DevOpenLoadDetectSwitchStateSrc *)(MotorDrvDataPackets->datasrc))->OpenLoadDetectState);
        break;
    }

    return rtval;
}
static Std_ReturnType Drv8889_Mainfunction(void *ptr)
{
    Std_ReturnType rtval = E_OK;

    return rtval;
}
/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/

Std_ReturnType CddDriver_Drv8889Init(void)
{
    Std_ReturnType rtval = E_OK;
    uint8_t i = 0;

    for (i = 0; i < MAX_MOTOR_NUM; i++)
    {
        if (Get_Variant() <= CONFIG_GEN1_MAX)
        {
            rtval |= MotorDrvDev_Register(&g_S_MotorDrv_Dev_GEN1[i]);
        }
        else
        {
            rtval |= MotorDrvDev_Register(&g_S_MotorDrv_Dev_GEN2[i]);
        }
    }
    return rtval;
}
