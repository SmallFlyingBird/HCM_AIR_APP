/*
 * PulseGenerateDrv.c
 *
 *  Created on: 2024��2��17��
 *      Author: mihuiliang
 */

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "PulseGeneratorDrv.h"
#include "AswInterfaceManager.h"
#include "Pwm.h"
#include "Port_Types.h"
#include "Port.h"
#include "Icu_Types.h"
#include "Icu_Cfg.h"
#include "Dio_Cfg.h"
#include "Dio.h"
#include "Icu.h"
/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
static Std_ReturnType PulseGenerator_DeviceInit(void *ptr);
static Std_ReturnType PulseGenerator_DeviceDeInit(void *ptr);
static Std_ReturnType PulseGenerator_Read(void *ptr);
static Std_ReturnType PulseGenerator_Write(void *ptr);
static Std_ReturnType PulseGenerator_MainFunction(void *ptr);

static uint8_t g_PwmIntFlag[MAX_PULSEGENERATOR_NUM] = {0, 0, 0, 0};

static E_PinMode ge_FanDiagPinMode = E_PinMode_ICU;

static S_PulseGenerator_Dev gs_PulseGenerator_Dev[MAX_PULSEGENERATOR_NUM] = {
    {
        .PulseGeneratorFunction = E_PulseGeneratorFunction_LevelingMotor,
        .DeviceInit = PulseGenerator_DeviceInit,
        .DeviceDeInit = PulseGenerator_DeviceDeInit,
        .Read = PulseGenerator_Read,
        .Write = PulseGenerator_Write,
        .MainFunction = PulseGenerator_MainFunction,
        .ptNext = NULL,
    },
    {
        .PulseGeneratorFunction = E_PulseGeneratorFunction_SwivelingMotor,
        .DeviceInit = PulseGenerator_DeviceInit,
        .DeviceDeInit = PulseGenerator_DeviceDeInit,
        .Read = PulseGenerator_Read,
        .Write = PulseGenerator_Write,
        .MainFunction = PulseGenerator_MainFunction,
        .ptNext = NULL,
    },
    {
        .PulseGeneratorFunction = E_PulseGeneratorFunction_FanPwmControl,
        .DeviceInit = PulseGenerator_DeviceInit,
        .DeviceDeInit = PulseGenerator_DeviceDeInit,
        .Read = PulseGenerator_Read,
        .Write = PulseGenerator_Write,
        .MainFunction = PulseGenerator_MainFunction,
        .ptNext = NULL,
    },
    {
        .PulseGeneratorFunction = E_PulseGeneratorFunction_FanDiag,
        .DeviceInit = PulseGenerator_DeviceInit,
        .DeviceDeInit = PulseGenerator_DeviceDeInit,
        .Read = PulseGenerator_Read,
        .Write = PulseGenerator_Write,
        .MainFunction = PulseGenerator_MainFunction,
        .ptNext = NULL,
    },
    {
        .PulseGeneratorFunction = E_PulseGeneratorFunction_DCMotor,
        .DeviceInit = PulseGenerator_DeviceInit,
        .DeviceDeInit = PulseGenerator_DeviceDeInit,
        .Read = PulseGenerator_Read,
        .Write = PulseGenerator_Write,
        .MainFunction = PulseGenerator_MainFunction,
        .ptNext = NULL,
    },

};

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
static Std_ReturnType SetPulseGeneratorDutyAndCycle(E_PulseGeneratorFunction PulseGeneratorFunction, S_PwmValueDataSrc *PwmValueDataSrc)
{
    Std_ReturnType rtval = E_OK;
    uint16 Cyclcounter = 0;
    uint16 duty = 0;

    Cyclcounter = (PwmValueDataSrc->cycle);
    duty = (uint16)(((uint32)PwmValueDataSrc->duty) * 32767 / 100);
    switch (PulseGeneratorFunction)
    {
        case E_PulseGeneratorFunction_DCMotor:
            Pwm_SetPeriodAndDuty(PwmConf_PwmChannel_DC_Ctr, Cyclcounter, duty);
        break;
    }
    return rtval;
}
static Std_ReturnType PulseGenerator_DeviceInit(void *ptr)
{
    Std_ReturnType rtval = E_OK;


    return rtval;
}

static Std_ReturnType PulseGenerator_DeviceDeInit(void *ptr)
{
    Std_ReturnType rtval = E_OK;
    return rtval;
}
static Std_ReturnType PulseGenerator_Read(void *ptr)
{
    Std_ReturnType rtval = E_OK;
    S_PulseGeneratorDataPackets *PulseGeneratorDataPackets = NULL;
    S_PinModeDataSrc *PinModeDataSrc;
    S_PinStateDataSrc *PinStateDataSrc;
    S_ICURequestResultDataSrc *ICURequestResultDataSrc;

    PulseGeneratorDataPackets = (S_PulseGeneratorDataPackets *)ptr;

    switch (PulseGeneratorDataPackets->PulseGeneratorDataType)
    {
    case E_PulseGeneratorDataType_PinMode:
        PinModeDataSrc = (S_PinModeDataSrc *)(PulseGeneratorDataPackets->datasrc);
        if (PinModeDataSrc->PulseGeneratorFunction != E_PulseGeneratorFunction_FanDiag)
            rtval = E_NOT_OK;
        else
            *(PinModeDataSrc->PinMode) = ge_FanDiagPinMode;
        break;
    case E_PulseGeneratorDataType_PinState:
        PinStateDataSrc = (S_PinModeDataSrc *)(PulseGeneratorDataPackets->datasrc);
        if (PinStateDataSrc->PulseGeneratorFunction != E_PulseGeneratorFunction_FanDiag)
            rtval = E_NOT_OK;
        else
            *(PinStateDataSrc->PinState) = Dio_ReadChannel(0x0070);
        break;
    case E_PulseGeneratorDataType_ICU_RequestResult:
        ICURequestResultDataSrc = (S_ICURequestResultDataSrc *)(PulseGeneratorDataPackets->datasrc);
        if (ICURequestResultDataSrc->PulseGeneratorFunction != E_PulseGeneratorFunction_FanDiag)
            rtval = E_NOT_OK;
        else
            *(ICURequestResultDataSrc->GetNumber) = Icu_GetEdgeNumbers(IcuConf_IcuChannel_IcuChannel_0);
        break;
    default:
        rtval = E_NOT_OK;
        break;
    }

    return rtval;
}
static Std_ReturnType PulseGenerator_Write(void *ptr)
{
    Std_ReturnType rtval = E_OK;
    S_PulseGeneratorDataPackets *PulseGeneratorDataPackets = NULL;
    S_PwmValueDataSrc *PwmValueDataSrc;
    S_PinModeDataSrc *PinModeDataSrc;
    S_ICUStartDataSrc *ICUStartDataSrc;
    S_ICUStopDataSrc *ICUStopDataSrc;

    PulseGeneratorDataPackets = (S_PulseGeneratorDataPackets *)ptr;

    switch (PulseGeneratorDataPackets->PulseGeneratorDataType)
    {
    case E_PulseGeneratorDataType_Init:
        break;
    case E_PulseGeneratorDataType_DeInit:
        break;
    case E_PulseGeneratorDataType_PWM:
        PwmValueDataSrc = (S_PwmValueDataSrc *)(PulseGeneratorDataPackets->datasrc);
        rtval |= SetPulseGeneratorDutyAndCycle(PwmValueDataSrc->PulseGeneratorFunction, PwmValueDataSrc);
        break;
    case E_PulseGeneratorDataType_PinMode:
        /*目前只支持FanDiag引脚的模式切换*/
        PinModeDataSrc = (S_PinModeDataSrc *)(PulseGeneratorDataPackets->datasrc);
        if (PinModeDataSrc->PulseGeneratorFunction != E_PulseGeneratorFunction_FanDiag)
            rtval = E_NOT_OK;
        else
        {
            if (((*(PinModeDataSrc->PinMode)) == E_PinMode_ICU) && (ge_FanDiagPinMode != E_PinMode_ICU))
            {
                Port_SetPinMode(PortConf_PortPin_FAN_DIAG_MCU, PORT_PIN_MODE_ALT2);
                ge_FanDiagPinMode = E_PinMode_ICU;
            }
            else if (((*(PinModeDataSrc->PinMode)) == E_PinMode_GPIO) && (ge_FanDiagPinMode != E_PinMode_GPIO))
            {
                Port_SetPinMode(PortConf_PortPin_FAN_DIAG_MCU, PORT_PIN_MODE_GPIO);
                ge_FanDiagPinMode = E_PinMode_GPIO;
            }
        }
        break;
    case E_PulseGeneratorDataType_PinState:
        /*FanDiag的Pin脚状态只支持读，不支持写*/
        rtval = E_NOT_OK;
        break;
    case E_PulseGeneratorDataType_ICU_Start:
        ICUStartDataSrc = (S_ICUStartDataSrc *)(PulseGeneratorDataPackets->datasrc);
        if (ICUStartDataSrc->PulseGeneratorFunction != E_PulseGeneratorFunction_FanDiag)
            rtval = E_NOT_OK;
        else
        {
            if (ICUStartDataSrc->IcuMode == E_PinMode_IcuRisingEdge)
                Icu_SetActivationCondition(IcuConf_IcuChannel_IcuChannel_0, ICU_RISING_EDGE);
            else if (ICUStartDataSrc->IcuMode == E_PinMode_IcuFallingEdge)
                Icu_SetActivationCondition(IcuConf_IcuChannel_IcuChannel_0, ICU_FALLING_EDGE);
            else
                Icu_SetActivationCondition(IcuConf_IcuChannel_IcuChannel_0, ICU_BOTH_EDGES);

            Icu_EnableEdgeDetection(IcuConf_IcuChannel_IcuChannel_0);
        }
        break;
    case E_PulseGeneratorDataType_ICU_Stop:
        ICUStopDataSrc = (S_ICUStopDataSrc *)(PulseGeneratorDataPackets->datasrc);
        if (ICUStopDataSrc->PulseGeneratorFunction != E_PulseGeneratorFunction_FanDiag)
            rtval = E_NOT_OK;
        else
            Icu_DisableEdgeCount(IcuConf_IcuChannel_IcuChannel_0);
        break;
    default:
        rtval = E_NOT_OK;
        break;
    }
    return rtval;
}
static Std_ReturnType PulseGenerator_MainFunction(void *ptr)
{
    Std_ReturnType rtval = E_OK;
    return rtval;
}

/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/

Std_ReturnType CddDriver_PulseGeneratorInit(void)
{
    Std_ReturnType rtval = E_OK;
    uint8_t i = 0;

    for (i = 0; i < MAX_PULSEGENERATOR_NUM; i++)
    {
        rtval |= PulseGeneratorDev_Register(&gs_PulseGenerator_Dev[i]);
    }
    return rtval;
}
