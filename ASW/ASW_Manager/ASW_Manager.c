/*
 * ASW_Manager.c
 *
 *  Created on: 2024.04.07
 *      Author: mihuiliang
 */

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "ASW_Manager.h"
#include "ASW_Manager.h"
#include "DidSignalManager.h"
#include "FrontCrossLamp.h"
#include "Fan.h"
#include <stdlib.h>
#include <math.h>
#include "LightingASW.h"
#include "DCMotor.h"
/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/

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

/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
/* 10ms任务 */
void ASW_Manager_MainFunction_10ms(void)
{
    Fan_Fan1CtrLineDtcErrDetect_10ms();
    HSDManage_MainFunction(10);
}


/* 20ms任务 */
void ASW_Manager_MainFunction_20ms(void)
{

}


/* 50ms任务 */
void ASW_Manager_MainFunction_50ms(void)
{
    DCMotor_MainFunction(50);
}


/* 100ms任务 */
void ASW_Manager_MainFunction_100ms(void)
{
    Fan_MainFunction(100);
    DidSignalManagerMainFunction(100);
}

/* 初始化 */
Std_ReturnType ASW_Manager_Init(void)
{
    Std_ReturnType rtval = E_OK;
    Fan_Init();
    DCMotor_Init();
    HSDManage_Init();
    return rtval;
}


