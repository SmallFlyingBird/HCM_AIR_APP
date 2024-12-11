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

// typedef enum
// {
//     E_PinMode_ICU = 0,
//     E_PinMode_GPIO = 1,
// } E_PinMode;

// typedef enum
// {
//     E_PinState_Low = 0,
//     E_PinState_High = 1,
// } E_PinState;

typedef enum
{
    E_PulseGeneratorFunction_NONE = 0,
    E_PulseGeneratorFunction_DCMotor,
} E_PulseGeneratorFunction;

typedef enum
{
    E_PulseGeneratorDataType_Init = 0,
    E_PulseGeneratorDataType_DeInit,
    E_PulseGeneratorDataType_PWM,
} E_PulseGeneratorDataType;

/*******************************************DataSrc*********************************************************/
typedef struct PwmValueDataSrc
{
    E_PulseGeneratorFunction PulseGeneratorFunction;
    uint8_t duty; /*duty=0-100  ->  0-100%*/
    uint16_t cycle;
} S_PwmValueDataSrc;

// typedef struct PulseGeneratorInitDataSrc
// {
//     E_PulseGeneratorFunction PulseGeneratorFunction;
// } S_PulseGeneratorInitDataSrc;

// typedef struct PinModeDataSrc
// {
//     E_PulseGeneratorFunction PulseGeneratorFunction;
//     E_PinMode *PinMode;
// } S_PinModeDataSrc;

// typedef struct PinStateDataSrc
// {
//     E_PulseGeneratorFunction PulseGeneratorFunction;
//     E_PinState *PinState;
// } S_PinStateDataSrc;

/*******************************************DataPackets******************************************************/
typedef struct PulseGeneratorDataPackets
{
    E_PulseGeneratorDataType PulseGeneratorDataType;
    void *datasrc;
} S_PulseGeneratorDataPackets;

typedef struct PulseGenerator_Dev
{
    E_PulseGeneratorFunction PulseGeneratorFunction; 
    // Std_ReturnType (*DeviceInit)(void *ptr);         
    // Std_ReturnType (*DeviceDeInit)(void *ptr);       
    // Std_ReturnType (*Read)(void *ptr);               
    Std_ReturnType (*Write)(void *ptr);              
    // Std_ReturnType (*MainFunction)(void *ptr);       
    struct PulseGenerator_Dev *ptNext;              
} S_PulseGenerator_Dev;

/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
Std_ReturnType Interface_EnablePulseGenerator(E_PulseGeneratorFunction PulseGeneratorFunction, uint16_t cycle, uint8_t duty);
#endif /* PULSEGENERATOR_INTERFACE_PULSEGENERATOR_INTERFACE_H_ */
