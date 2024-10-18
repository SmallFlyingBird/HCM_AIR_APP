/*
 * PulseGenerator_Interface.h
 *
 *  Created on: 2024��1��22��
 *      Author: mihuiliang
 */

#ifndef PULSEGENERATOR_INTERFACE_PULSEGENERATOR_INTERFACE_H_
#define PULSEGENERATOR_INTERFACE_PULSEGENERATOR_INTERFACE_H_

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HcmPlatform.h"
/****************************************************************
 *                                                              *
 *                      Macro Define                            *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/

typedef enum
{
    E_PinMode_ICU = 0,
    E_PinMode_GPIO = 1,
} E_PinMode;

typedef enum
{
    E_PinState_Low = 0,
    E_PinState_High = 1,
} E_PinState;

typedef enum
{
    E_PinMode_IcuRisingEdge = 0,
    E_PinMode_IcuFallingEdge = 1,
    E_PinMode_IcuBothEdge = 2,
} E_IcuMode;

typedef enum
{
    E_PulseGeneratorFunction_NONE = 0,
    E_PulseGeneratorFunction_LevelingMotor,
    E_PulseGeneratorFunction_SwivelingMotor,
    E_PulseGeneratorFunction_FanPwmControl,
    E_PulseGeneratorFunction_FanDiag,
    E_PulseGeneratorFunction_DCMotor,
} E_PulseGeneratorFunction;

typedef enum
{
    E_PulseGeneratorDataType_Init = 0,
    E_PulseGeneratorDataType_DeInit,
    E_PulseGeneratorDataType_PWM,
    E_PulseGeneratorDataType_PinMode,           /*主要用于改变FanDiag的诊断脚的*/
    E_PulseGeneratorDataType_PinState,          /*当FanDiag是GPIO时候，主要用于获得FanDiag诊断脚的状态*/
    E_PulseGeneratorDataType_ICU_Start,         /*启动ICU*/
    E_PulseGeneratorDataType_ICU_Stop,          /*停止ICU*/
    E_PulseGeneratorDataType_ICU_RequestResult, /*启动ICU*/
} E_PulseGeneratorDataType;

/*******************************************DataSrc*********************************************************/
typedef struct PwmValueDataSrc
{
    E_PulseGeneratorFunction PulseGeneratorFunction;
    uint8_t duty; /*duty=0-100  ->  0-100%*/
    uint16_t cycle;
} S_PwmValueDataSrc;

typedef struct PulseGeneratorInitDataSrc
{
    E_PulseGeneratorFunction PulseGeneratorFunction;
} S_PulseGeneratorInitDataSrc;

typedef struct PinModeDataSrc
{
    E_PulseGeneratorFunction PulseGeneratorFunction;
    E_PinMode *PinMode;
} S_PinModeDataSrc;

typedef struct PinStateDataSrc
{
    E_PulseGeneratorFunction PulseGeneratorFunction;
    E_PinState *PinState;
} S_PinStateDataSrc;

typedef struct ICUStartDataSrc
{
    E_PulseGeneratorFunction PulseGeneratorFunction;
    E_IcuMode IcuMode;
} S_ICUStartDataSrc;

typedef struct ICURequestResultDataSrc
{
    E_PulseGeneratorFunction PulseGeneratorFunction;
    uint32_t *GetNumber;
} S_ICURequestResultDataSrc;

typedef struct ICUStopDataSrc
{
    E_PulseGeneratorFunction PulseGeneratorFunction;
} S_ICUStopDataSrc;




/*******************************************DataPackets******************************************************/
typedef struct PulseGeneratorDataPackets
{
    E_PulseGeneratorDataType PulseGeneratorDataType;
    void *datasrc;
} S_PulseGeneratorDataPackets;

typedef struct PulseGenerator_Dev
{
    E_PulseGeneratorFunction PulseGeneratorFunction; /*�豸����*/
    Std_ReturnType (*DeviceInit)(void *ptr);         /*�豸��ʼ��*/
    Std_ReturnType (*DeviceDeInit)(void *ptr);       /*�豸ȥ��ʼ��*/
    Std_ReturnType (*Read)(void *ptr);               /*������*/
    Std_ReturnType (*Write)(void *ptr);              /*д����*/
    Std_ReturnType (*MainFunction)(void *ptr);       /*buck��������������buckι��*/
    struct PulseGenerator_Dev *ptNext;               /*ָ����һ��*/
} S_PulseGenerator_Dev;

/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
Std_ReturnType Interface_SetPulseGnerator(E_PulseGeneratorFunction PulseGeneratorFunction, uint16_t cycle, uint8_t duty);
Std_ReturnType Interface_DisablePulseGenerator(E_PulseGeneratorFunction PulseGeneratorFunction, uint16_t cycle, uint8_t duty);
Std_ReturnType Interface_EnablePulseGenerator(E_PulseGeneratorFunction PulseGeneratorFunction, uint16_t cycle, uint8_t duty);
Std_ReturnType Interface_SetPinMode(E_PulseGeneratorFunction PulseGeneratorFunction, E_PinMode PinMode);
Std_ReturnType Interface_GetPinMode(E_PulseGeneratorFunction PulseGeneratorFunction, E_PinMode *PinMode);
Std_ReturnType Interface_SetPinState(E_PulseGeneratorFunction PulseGeneratorFunction, E_PinState PinState);
Std_ReturnType Interface_GetPinState(E_PulseGeneratorFunction PulseGeneratorFunction, E_PinState *PinState);
Std_ReturnType Interface_IcuStart(E_PulseGeneratorFunction PulseGeneratorFunction, E_IcuMode IcuMode);
Std_ReturnType Interface_IcuStop(E_PulseGeneratorFunction PulseGeneratorFunction);
Std_ReturnType Interface_RequestResult(E_PulseGeneratorFunction PulseGeneratorFunction, uint32_t* Number);
Std_ReturnType Interface_PulseGeneratorInit(void);
Std_ReturnType PulseGeneratorDev_Register(S_PulseGenerator_Dev *Drv_Dev);
#endif /* PULSEGENERATOR_INTERFACE_PULSEGENERATOR_INTERFACE_H_ */
