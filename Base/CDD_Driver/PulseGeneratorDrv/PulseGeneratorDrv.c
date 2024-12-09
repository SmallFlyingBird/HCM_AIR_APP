// /*
//  * PulseGenerateDrv.c
//  *
//  *  Created on: 2024��2��17��
//  *      Author: mihuiliang
//  */

// /****************************************************************
//  *                                                              *
//  *                     Include Files                            *
//  *                                                              *
//  ****************************************************************/
// #include "PulseGeneratorDrv.h"
// #include "Pwm.h"
// #include "Port_Types.h"
// #include "Port.h"
// #include "Icu_Types.h"
// #include "Icu_Cfg.h"
// #include "Dio_Cfg.h"
// #include "Dio.h"
// #include "Icu.h"
// /****************************************************************
//  *                                                              *
//  *                  Private Variable Define                     *
//  *                                                              *
//  ****************************************************************/
// static Std_ReturnType PulseGenerator_DeviceInit(void *ptr);
// static Std_ReturnType PulseGenerator_DeviceDeInit(void *ptr);
// static Std_ReturnType PulseGenerator_Read(void *ptr);
// static Std_ReturnType PulseGenerator_Write(void *ptr);
// static Std_ReturnType PulseGenerator_MainFunction(void *ptr);

// static uint8_t g_PwmIntFlag[MAX_PULSEGENERATOR_NUM] = {0, 0, 0, 0};

// static E_PinMode ge_FanDiagPinMode = E_PinMode_ICU;

// static S_PulseGenerator_Dev gs_PulseGenerator_Dev[MAX_PULSEGENERATOR_NUM] = {
//     {
//         .PulseGeneratorFunction = E_PulseGeneratorFunction_LevelingMotor,
//         .DeviceInit = PulseGenerator_DeviceInit,
//         .DeviceDeInit = PulseGenerator_DeviceDeInit,
//         .Read = PulseGenerator_Read,
//         .Write = PulseGenerator_Write,
//         .MainFunction = PulseGenerator_MainFunction,
//         .ptNext = NULL,
//     },
//     {
//         .PulseGeneratorFunction = E_PulseGeneratorFunction_SwivelingMotor,
//         .DeviceInit = PulseGenerator_DeviceInit,
//         .DeviceDeInit = PulseGenerator_DeviceDeInit,
//         .Read = PulseGenerator_Read,
//         .Write = PulseGenerator_Write,
//         .MainFunction = PulseGenerator_MainFunction,
//         .ptNext = NULL,
//     },
//     {
//         .PulseGeneratorFunction = E_PulseGeneratorFunction_FanPwmControl,
//         .DeviceInit = PulseGenerator_DeviceInit,
//         .DeviceDeInit = PulseGenerator_DeviceDeInit,
//         .Read = PulseGenerator_Read,
//         .Write = PulseGenerator_Write,
//         .MainFunction = PulseGenerator_MainFunction,
//         .ptNext = NULL,
//     },
//     {
//         .PulseGeneratorFunction = E_PulseGeneratorFunction_FanDiag,
//         .DeviceInit = PulseGenerator_DeviceInit,
//         .DeviceDeInit = PulseGenerator_DeviceDeInit,
//         .Read = PulseGenerator_Read,
//         .Write = PulseGenerator_Write,
//         .MainFunction = PulseGenerator_MainFunction,
//         .ptNext = NULL,
//     },
//     {
//         .PulseGeneratorFunction = E_PulseGeneratorFunction_DCMotor,
//         .DeviceInit = PulseGenerator_DeviceInit,
//         .DeviceDeInit = PulseGenerator_DeviceDeInit,
//         .Read = PulseGenerator_Read,
//         .Write = PulseGenerator_Write,
//         .MainFunction = PulseGenerator_MainFunction,
//         .ptNext = NULL,
//     },

// };

// /****************************************************************
//  *                                                              *
//  *                   Global Variable Define                     *
//  *                                                              *
//  ****************************************************************/

// /****************************************************************
//  *                                                              *
//  *                   Private Functions Define                   *
//  *                                                              *
//  ****************************************************************/
// static Std_ReturnType SetPulseGeneratorDutyAndCycle(E_PulseGeneratorFunction PulseGeneratorFunction, S_PwmValueDataSrc *PwmValueDataSrc)
// {
//     Std_ReturnType rtval = E_OK;
//     uint16 Cyclcounter = 0;
//     uint16 duty = 0;

//     Cyclcounter = (PwmValueDataSrc->cycle);
//     duty = (uint16)(((uint32)PwmValueDataSrc->duty) * 32767 / 100);
//     switch (PulseGeneratorFunction)
//     {
//         case E_PulseGeneratorFunction_DCMotor:
//             Pwm_SetPeriodAndDuty(PwmConf_PwmChannel_DC_Ctr, Cyclcounter, duty);
//         break;
//     }
//     return rtval;
// }
// static Std_ReturnType PulseGenerator_DeviceInit(void *ptr)
// {
//     Std_ReturnType rtval = E_OK;


//     return rtval;
// }

// static Std_ReturnType PulseGenerator_DeviceDeInit(void *ptr)
// {
//     Std_ReturnType rtval = E_OK;
//     return rtval;
// }
// static Std_ReturnType PulseGenerator_Read(void *ptr)
// {

//     return rtval;
// }
// static Std_ReturnType PulseGenerator_Write(void *ptr)
// {

// }
// static Std_ReturnType PulseGenerator_MainFunction(void *ptr)
// {
//     Std_ReturnType rtval = E_OK;
//     return rtval;
// }

// /****************************************************************
//  *                                                              *
//  *                   Global Functions Define                    *
//  *                                                              *
//  ****************************************************************/

// Std_ReturnType CddDriver_PulseGeneratorInit(void)
// {
//     Std_ReturnType rtval = E_OK;
//     uint8_t i = 0;

//     for (i = 0; i < MAX_PULSEGENERATOR_NUM; i++)
//     {
//         rtval |= PulseGeneratorDev_Register(&gs_PulseGenerator_Dev[i]);
//     }
//     return rtval;
// }
