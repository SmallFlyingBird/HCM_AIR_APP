/*
 * AseInterfaceManager.c
 *
 *  Created on: 2024��1��15��
 *      Author: mihuiliang
 */

#ifndef ASW_INTERFACE_ASW_INTERFACE_MANAGER_ASEINTERFACEMANAGER_C_
#define ASW_INTERFACE_ASW_INTERFACE_MANAGER_ASEINTERFACEMANAGER_C_

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HcmPlatform.h"
#include "AmbiDerate_Interface.h"
#include "BuckDerate_Interface.h"
#include "LossDerate_Interface.h"
#include "NtcDerate_Interface.h"
#include "OUVDerate_Interface.h"
#include "PulseGenerator_Interface.h"
#include "Buck_Interface.h"
#include "LRDirection_Interface.h"
#include "NtcRcod_Interface.h"
#include "Channel_Interface.h"
#include "HighSide_Interface.h"
#include "PowerSupply_Interface.h"
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
void ASWInterfaceManagerMainFunc_2ms(void)
{
    // Channel_Interface_TimerMainFunction(2);
    // MotorMotionMainFunction(2);
}
void ASWInterfaceManagerMainFunc_10ms(void)
{
//     BuckInterfaceMainFuntion(10); //4MS
//     Channel_Interface_MainFunction(10);//0.25
//     ComSignalInterfaceMainFunction(10);//0.15
//     DtcInterfaceMainFunction(10);//0.60
//     SystemService_MainFunction(10);//1ms
// #if (QINGHAIGANG)
//     OUVDerateMainFunction(10);//1ms
// #endif /*QINGHAIGANG*/
}
void ASWInterfaceManagerMainFunc_20ms(void)
{
    // PowerSupplyMainFunction(20);
    // RcodInterface_Mainfunction(20);
    // HighSide_Interface_Mainfunction(20);
    // AdcDev_Interface_Mainfunction(20);
    // SystemService_MemoryJobMainFunction(20);
}

void ASWInterfaceManagerMainFunc_100ms(void)
{
//     NtcInterface_Mainfunction(100);
// #if (QINGHAIGANG)
//     NtcDerateMainFunction(100);
//     BuckDerateMainFunction(100);
//     AmbiDerateMainFunction(100);
// #else  /*QINGHAIGANG*/
//     DerateRatioManagerFuncmain(100);
// #endif /*QINGHAIGANG*/
//     Interface_RoutineCtr_MainFunction(100);
//     DID_Interface_Mainfunction(100);
}

void ASWInterfaceManagerMainFunc_1s(void)
{
    // SystemService_FlsTstMainFunction(1000);
}

Std_ReturnType AswInterfaceManagerInit(void)
{
    // Std_ReturnType rtval = E_OK;
    // uint16_t BoostMaxVlotage = 0;
    // E_ChannelID chindex = 0;
    // rtval |= Interface_HighSideInit();
    // rtval |= Interface_DIDInit();
    // rtval |= Interface_ChannelInit();
    // rtval |= Interface_BuckInit();
    // rtval |= Interface_NtcRcodInit();
    // rtval |= DirectionInterface_Init();
    // rtval |= Interface_DtcInit();
    // rtval |= Interface_PulseGeneratorInit();
    // // rtval |= MatrixChipInterfaceModuleInit();
    // return rtval;
}
#endif /* ASW_INTERFACE_ASW_INTERFACE_MANAGER_ASEINTERFACEMANAGER_C_ */
