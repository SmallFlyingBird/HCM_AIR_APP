/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "McalLib.h"
#include "Pwm.h"
#include "MotorDrvDev_Interface.h"
#include "MotorMotion_Interface.h"
#include "AswInterfaceManager.h"

// void AFS_PWM_Notification()
// {
//     if (Get_Variant() <= CONFIG_GEN1_MAX)
//     {
//         Interface_PulseGeneratorCallBack(E_MotorTpye_Swiveling);
//     }
//     else
//     {
//         Interface_PulseGeneratorCallBack(E_MotorTpye_Leveling);
//     }
// }

// void ALS_PWM_Notification()
// {
//     if (Get_Variant() <= CONFIG_GEN1_MAX)
//     {
//         Interface_PulseGeneratorCallBack(E_MotorTpye_Leveling);
//     }
//     else
//     {
//         Interface_PulseGeneratorCallBack(E_MotorTpye_Swiveling);
//     }
// }
