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
#include "SwivelingMotor.h"
#include "LevelingMotor.h"
#include "DidSignalManager.h"

#if WANGSIBO
#include "Dynamic_Light_Function.h"
#endif

#if TUJIONGJIONG
#include "CorneringLight.h"
#include "FogLamp.h"
#include "FrontCrossLamp.h"
#include "GrilleLamp.h"
#include "LogoLamp.h"
#include "SiderMarkerLamp.h"
#include "Fan.h"
#include "AHL.h"
#include "MHL.h"
#include "DBL.h"
#include "MotorManage.h"
#include "DCMotor.h"


#if AHL_TEST
#include <stdlib.h>
#include <math.h>
#endif

#endif


#if (QINGHAIGANG)
#include "LightingASW.h"
#endif	/*QINGHAIGANG*/
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
    // FogLamp_MainFunction(10);
    // CorneringLight_MainFunction(10);
    // FrontCrossLamp_MainFunction(10);
    // GrilleLamp_MainFunction(10);
    // LogoLamp_MainFunction(10);
    // SiderMarkerLamp_MainFunction(10);

    // Fan_Fan1CtrLineDtcErrDetect_10ms();
    // HSDManage_MainFunction(10);
    // MotorManage_MainFunction(10);

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
#if AHL_TEST

    static double TestRadian = 4.71238898;
    static uint16_t Time = 0;
    static uint8_t Flag = 0;

    double SinVal;

    Time += 20;
    if(Time >= 40)
    {
        if(Flag == 1)
            TestRadian += 0.005;
        if(TestRadian >= 10000.0)
        {
            TestRadian = 0.0;
        }

        SinVal = sin(TestRadian);

        if(SinVal < -0.98)
        {
            static DelayTime = 0;

            if(DelayTime < 800)
            {
                Flag = 0; 
                DelayTime += 40;
            }
            else
            {
                Flag = 1; 
                DelayTime = 0;
            }
        }
        Interface_SetSignal_VehSpdLgtA((uint32_t)(5000 * SinVal + 5010));

        Time = 0;
    }
    Interface_SetSignal_ActvnOfAhl(1);    
    Interface_SetSignal_SuspPosnVertLvlFrnt(rand()/50);
    Interface_SetSignal_SuspPosnVertLvlRe(rand()/50);
#endif

#if WANGSIBO
    //// Test_Interface_Dynamic_Light(20);
	// Dynamic_Light_Function_MainFunction(20);
    // Dynamic_Charging_Light_MainFunction(20);
#endif  /*WANGSIBO*/

    // LevelingMotorMainFunction(20);
    // SwivelingMotorMainFunction(20);
    // ADBMainFuction(); 
}


/* 50ms任务 */
void ASW_Manager_MainFunction_50ms(void)
{
#if TUJIONGJIONG
    // AHL_MainFunction_50ms();
    // MHL_MainFunction(50);
    // DBL_MainFunction(50);
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

#if (QINGHAIGANG)
#if (QHG_TESTIF_LED == 0)
    // Lighting_Init();
#endif  /*QHG_TESTIF_LED*/
#else
    rtval |= ASW_PixelInit();
    rtval |= BasicLightingManagerInit();
#endif	/*QINGHAIGANG*/

    // ADBB_Init();

#if TUJIONGJIONG
    // CorneringLight_Init();
    // FogLamp_Init();
    // FrontCrossLamp_Init();
    // GrilleLamp_Init();
    // LogoLamp_Init();
    // SiderMarkerLamp_Init();
    // Fan_Init();
    // AHL_Init();
    // MHL_Init();
    // DCMotor_Init();
    // DBL_Init();
    // HSDManage_Init();
    // MotorManage_Init();
#endif

    // LevelingMotorInit();
    // SwivelingMotorInit();

    return rtval;
}

