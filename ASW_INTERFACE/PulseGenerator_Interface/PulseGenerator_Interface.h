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

typedef enum
{
    E_PulseGeneratorFunction_NONE = 0,
    E_PulseGeneratorFunction_DCMotor,
} E_PulseGeneratorFunction;

/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
Std_ReturnType Interface_EnablePulseGenerator(E_PulseGeneratorFunction PulseGeneratorFunction, uint16_t cycle, uint8_t duty);
#endif /* PULSEGENERATOR_INTERFACE_PULSEGENERATOR_INTERFACE_H_ */
