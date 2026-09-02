
#ifndef POWERSUPPLY_INTERFACE_POWERSUPPLY_INTERFACE_H_
#define POWERSUPPLY_INTERFACE_POWERSUPPLY_INTERFACE_H_

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
#define VOLTAGE_BUFFER_ARRAY_NUM 5

/*
 *   kl56开路和对地短路阈值  0.5v -> 12位AD采样精度就是410
 */
#define KL56_SHORT2GND_OPEN_THRESHOLD_12ADBIT 410

/*
 *   kl56开路和对地短路恢复阈值  1.0v -> 12位AD采样精度就是820
 */
#define KL56_SHORT2GND_OPEN_RECOVER_THRESHOLD_12ADBIT 820


#define OVER_VOLTAGE_FAIL_THRESHOLD                17.0
#define OVER_VOLTAGE_PASS_THRESHOLD                16.0

#define UNDER_VOLTAGE_FAIL_THRESHOLD                8.0
#define UNDER_VOLTAGE_PASS_THRESHOLD                9.0

/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/
typedef union{
    uint8_t SupplyVoltageState;
    struct{
        uint8_t KL15_UnderVoltage   :1;
        uint8_t KL56_OverVoltage    :1;
        uint8_t KL56_UnderVoltage   :1;  
        uint8_t rcvd                :4;
    }bits;
}U_SupplyVoltageState;
/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
void LDOSupplyMainFuntion(void);
Std_ReturnType Interface_GetKL56Voltage(double* voltage);
void PowerSupplyMainFunction(uint8_t tmiebase);
#endif /* POWERSUPPLY_INTERFACE_POWERSUPPLY_INTERFACE_H_ */
