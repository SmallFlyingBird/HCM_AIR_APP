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
#include "ADBsuanfa.h"
#include "ASW_Manager.h"
#include "DidSignalManager.h"

#if TUJIONGJIONG
#include "FrontCrossLamp.h"
#include "Fan.h"
#include <stdlib.h>
#include <math.h>
#endif

#if (QINGHAIGANG)
#include "LightingASW.h"
#endif	/*QINGHAIGANG*/

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
#if TUJIONGJIONG
    Fan_Fan1CtrLineDtcErrDetect_10ms();
    HSDManage_MainFunction(10);
#endif

#if (QINGHAIGANG)
#if (QHG_TESTIF_LED == 0)
    // Lighting_Run10ms();
#endif  /*QHG_TESTIF_LED*/
#else	/*QINGHAIGANG*/
    BasicLightingManagerMainFunction(10);
#endif	/*QINGHAIGANG*/


#if WANGSIBO
	
	/*Dynamic_Light_Function_MainFunction(10);*/
#endif
}


/* 20ms任务 */
void ASW_Manager_MainFunction_20ms(void)
{

}


/* 50ms任务 */
void ASW_Manager_MainFunction_50ms(void)
{
#if TUJIONGJIONG
    DCMotor_MainFunction(50);
#endif
}


/* 100ms任务 */
void ASW_Manager_MainFunction_100ms(void)
{
#if TUJIONGJIONG
    // Fan_MainFunction(100);
#endif
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

