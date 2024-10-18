 
/********************************
 * ADBsuanfa.c
 *
 *  Created on: 2024/4/29
 *      Author: sbf
 ********************************/
 
/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/


#include "HcmPlatform.h"
#include "mpu_driver.h"
#include "HcmPlatform.h"


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

 

#define  Most_ObstacleNumber    8
#define  PI                     3.1415926
#define  MathMethod             0
 
 #define  Max_distPre        20 /*每周期最大变化距离*/
 #define  Max_DegPre         4 /*每周期最大变化角度 */
 #define   Max_DegSpeedPre   4 /*每周期最大变化加速度*/




typedef struct
 {
      uint16_t iCounter;
    // uint16_t id;

    uint16_t distance;
    uint8_t  ObjDir;
    uint8_t  Classn  ;
    uint8_t  TrkInfo;
    float  leftAngleMovingSpeed ; //角速度
    float  rightAngleMovingSpeed ;//角速度
    float  leftAngle;
    float  rightAngle;
    float  bottomAngle;
 } IFCValue;

 typedef struct
  {
    float LeftRad;// 
    float RightRad;// 
    float Len;// 
} VehiclePostion;

 
 typedef struct
  {
       uint16  livecounter;
	     uint16 iCounter;
        uint16 Input_d1;
        float Input_u1;
        float Input_v1;
        float Input_degsped;
        uint8 isActive;
  } IFCTarget;

  typedef struct
{
  float LED_ST_ANG ;
  float LED_END_ANG ;
} LED_ANGLE_TYPE ;


 typedef struct
  {
    uint32_t ActvnOfAhbc;
    uint32_t CameraStsforAHBC;
    uint32_t TooManyCars;
    uint32_t LitArea;
    uint32_t ActnOfLedHiBeam;
  } ADBConditionsstruct;


typedef enum
{
 ADBoffline =0,
ADBopenwindow=1,
 ADBactive=2,
 ADBUADBclosewindow=3,
};


typedef enum
{
 ADBledsetoff=0,
 ADBledseton =1,
ADBUnuse=0xff
 
};


uint32  GetLightStatus(void);
uint32 GetStatus(float minA, float maxA);
void   GetRightPostion(float d, float leftrad, float rightrad,VehiclePostion* vehiclePostion);
void GetLeftPostion (float d,float leftDeg,float rightDeg,VehiclePostion* vehiclePostion);
Std_ReturnType  GetADBLedsOnoffcmd( uint8_t*ADBLedsOnoffcmd  );
static Std_ReturnType ADBopenwindowdeal(uint8_t  Row );
static  Std_ReturnType SetAllon(uint8_t*g_adb_onoff);
static Std_ReturnType SetAlloff(uint8_t *g_adb_onoff);
static Std_ReturnType ADBclosewindowdeal(uint8_t  Row );
void ADBMainFuction(void );
uint8_t  GetADBstatus(void );
void ADBB_Init(void);
static  Std_ReturnType SetSingleLedOn( uint8_t*g_adb_onoff,uint8_t num);
static  Std_ReturnType SetSingleLedOff( uint8_t*g_adb_onoff,uint8_t num);
void ADB_OPen_and_Close_delay(void);