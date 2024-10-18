#include"Xcp_Caldata.h"
#include "Platform_Types.h"


/* Exported data definition */

/* ConstVolatile memory section */ 
uint32 Calib_CRC  __attribute__((section(".CalData_Crc"))) = 0;
uint32 Calib_SIZE __attribute__((section(".CalData_Size"))) = 0;

/*  Calibration variable defined */
uint8 u8_Calib_1 __attribute__((section(".CalData")));
uint8 u8_Calib_2 __attribute__((section(".CalData")));
uint8 u8_Calib_3 __attribute__((section(".CalData")));
uint8 u8_Calib_4 __attribute__((section(".CalData")));
uint8 u8_Calib_5 __attribute__((section(".CalData")));
uint8 u8_Calib_6 __attribute__((section(".CalData")));
uint8 u8_Calib_7 __attribute__((section(".CalData")));
uint8 u8_Calib_8 __attribute__((section(".CalData")));
uint8 u8_Calib_9 __attribute__((section(".CalData")));
uint8 u8_Calib_10 __attribute__((section(".CalData")));
uint16 u16_Calib_1 __attribute__((section(".CalData")));
uint16 u16_Calib_2 __attribute__((section(".CalData")));
uint16 u16_Calib_3 __attribute__((section(".CalData")));
uint16 u16_Calib_4 __attribute__((section(".CalData")));
uint16 u16_Calib_5 __attribute__((section(".CalData")));
uint16 u16_Calib_6 __attribute__((section(".CalData")));
uint16 u16_Calib_7 __attribute__((section(".CalData")));
uint16 u16_Calib_8 __attribute__((section(".CalData")));
uint16 u16_Calib_9 __attribute__((section(".CalData")));
uint16 u16_Calib_10 __attribute__((section(".CalData")));
uint32 u32_Calib_1 __attribute__((section(".CalData")));
uint32 u32_Calib_2 __attribute__((section(".CalData")));
uint32 u32_Calib_3 __attribute__((section(".CalData")));
uint32 u32_Calib_4 __attribute__((section(".CalData")));
uint32 u32_Calib_5 __attribute__((section(".CalData")));
uint32 u32_Calib_6 __attribute__((section(".CalData")));
uint32 u32_Calib_7 __attribute__((section(".CalData")));
uint32 u32_Calib_8 __attribute__((section(".CalData")));
uint32 u32_Calib_9 __attribute__((section(".CalData")));
uint32 u32_Calib_10 __attribute__((section(".CalData")));





__attribute__((section(".CalData"))) uint8  DH= 20; /*ADB标定参数放大10倍变成整形存储 */
__attribute__((section(".CalData"))) uint8  L_LEFT = 15;/*ADB标定参数放大10倍变成整形存储 */
__attribute__((section(".CalData"))) uint8  L_RIGHT= 15;/*ADB标定参数放大10倍变成整形存储 */
__attribute__((section(".CalData"))) uint8  DarkSpace= 4;
__attribute__((section(".CalData"))) uint8  Carwidth= 20;/*ADB标定参数放大10倍变成整形存储 */
__attribute__((section(".CalData"))) uint8  L_DarkRepair=10;/*ADB标定参数放大10倍变成整形存储 */
__attribute__((section(".CalData"))) uint8  R_DarkRepair=10;/*ADB标定参数放大10倍变成整形存储 */

__attribute__((section(".CalData"))) uint8  Max_distPre=15;/*每周期最大变化距离*/
__attribute__((section(".CalData"))) uint8  Max_DegPre=2;/*每周期最大变化角度 */
__attribute__((section(".CalData"))) uint8  Max_DegSpeedPre=2;/*每周期最大变化加速度*/



/* Definition for custom storage class: Volatile */
uint32 Mea_A = 0;
