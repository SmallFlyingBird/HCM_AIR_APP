#include "GeneralFunction.h"
#include "ComSignal_Interface.h"
#include "Parameter_Interface.h"
#include "ADBsuanfa.h"
#include "Lighting.h"
#include"Xcp_Caldata.h"
#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "ParaMgr.h"

static  uint8  ADBledsinterface[84]={ ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,
                                       ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,
                                       ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,
                                        ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,
                                        ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,
                                        ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,
                                        ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse,ADBUnuse
                                        };
 static uint8  ADBledChangeArr[84] ={0};        
 static uint8_t ADBopenwindowfinshined=0,ADBclosewindowfinshined=0;
 static uint8_t  Hs11ADBstatus=ADBoffline;
IFCValue cacheIFCValue[20];
uint8 HS11LEDnumber=0;
IFCTarget ifcTarget[30]={0};
IFCTarget oneLightspot={0};
 LED_ANGLE_TYPE Hcm_led_anlge[84]={0};

float  cameraH,cameraL,cameraR,CarW,L_Repair,R_Repair;//存放标定参数

//弧度转角度
static inline float radTodeg(float rad)
{
    return (float)(rad * 180 / PI);
}

//角度转弧度
static inline float DegToRad(float deg)
{
    return (float)(deg * PI / 180 ); 
}

 
 
//  void GetDarkAreaAngle (float sd,float leftDeg,float rightDeg,  float anglespeed , VehiclePostion* vehiclePostion)


// {
//       uint8 Workcase=0;
//       float  DSTH;
//       float  LevelL1,LevelL2;  //左右边界
//       float  a=0,b=0,c=0,d=0; //角度
//       //float  cameraH,cameraL,cameraR,CarW;
//       float  tempL,tempR;
//         a=DegToRad(rightDeg);
//         b=DegToRad(leftDeg);

//     if(anglespeed>0&&anglespeed<10){ tempR=R_Repair+1; tempL=L_Repair; }
//     else  if(anglespeed<0&&anglespeed>-10) { tempR=R_Repair;tempL=L_Repair+1;  }
//     else  
//     { tempR=R_Repair;tempL=L_Repair;  }



// #if  MathMethod

//       if(leftDeg>=rightDeg)     //左角度大于右边舍弃
//        { vehiclePostion->LeftRad=0;vehiclePostion->RightRad=0;return ;}     
           
//       if( leftDeg<=0&&rightDeg<=0) Workcase=1;
//       else if( leftDeg<0&&rightDeg>=0)
//       {
//           if(fabs(leftDeg)>fabs(rightDeg))Workcase=2;
//           else   if(fabs(leftDeg)==fabs(rightDeg))Workcase=3;
//           else    Workcase=4;
//       }
//       else if( leftDeg>=0&&rightDeg>=0)Workcase=5;
//       else Workcase=0;
//     if(HCM_LEFT_SIDE)       //如果为左边灯控制器
//       {
//         switch(Workcase)
//           {

//               case 1:   

//                         DSTH= CarW/fabs(tan(b)-tan(a));
//                         if(DSTH>=sd)    
//                         { vehiclePostion->LeftRad=0;vehiclePostion->RightRad=0;return ;}                       
//                         LevelL1= sqrt (pow (sd,2)-pow (DSTH,2)) -CarW/2-cameraL;
//                         c=atan( LevelL1/(DSTH-cameraH));
//                         d=atan( (LevelL1+CarW)/(DSTH-cameraH));   
//                         vehiclePostion->RightRad=(float)radTodeg(c)*-1;   
//                         vehiclePostion->LeftRad=(float)radTodeg(d)*-1;
                    

//                         break ;
//               case 2:
                  

//                         DSTH= CarW/fabs(tan(b)-tan(a));
//                         LevelL1= cameraL+DSTH*tan(a);
//                         if(LevelL1>CarW/2)     
//                         { vehiclePostion->LeftRad=0;vehiclePostion->RightRad=0;return ;}               
//                         c=atan( LevelL1/(DSTH-cameraH));
//                         d=atan( (CarW-LevelL1)/(DSTH-cameraH));   
//                         vehiclePostion->RightRad=(float)radTodeg(c);   
//                         vehiclePostion->LeftRad=(float)radTodeg(d)*-1;
                    



//                         break ;
//               case 3:
//                           DSTH=sd;
//                           LevelL1=CarW;
//                         c=atan( LevelL1/(DSTH-cameraH));                   
//                         vehiclePostion->RightRad=(float)radTodeg(c);   
//                         vehiclePostion->LeftRad=0;


//                         break ;
//               case 4:

//                         DSTH= CarW/fabs(tan(b)-tan(a));
//                         LevelL1= cameraL+DSTH*tan(a);     
//                         if(LevelL1<CarW)     
//                         { vehiclePostion->LeftRad=0;vehiclePostion->RightRad=0;return ;}    
//                         c=atan( LevelL1/(DSTH-cameraH));
//                         d=atan( ( LevelL1-CarW)/(DSTH-cameraH));   
//                         vehiclePostion->RightRad=(float)radTodeg(c);   
//                         vehiclePostion->LeftRad=(float)radTodeg(d) ;

//                         break ;
//               case 5:

//                         DSTH= CarW/fabs(tan(a)-tan(b));
//                           if(DSTH>=sd)    
//                           { vehiclePostion->LeftRad=0;vehiclePostion->RightRad=0;return ;}                       
//                         LevelL1= sqrt (pow (sd,2)-pow (DSTH,2)) +CarW/2+cameraL;
//                         c=atan( LevelL1/(DSTH-cameraH));
//                         d=atan( (LevelL1-CarW)/(DSTH-cameraH));   
//                         vehiclePostion->RightRad=(float)radTodeg(c);   
//                         vehiclePostion->LeftRad=(float)radTodeg(d);

                      
//                         break ;
//               default :  

//                           vehiclePostion->LeftRad=0;vehiclePostion->RightRad=0;return ;

//                         break ;
            
//         }
//       }
//       else  //如果为右边灯控制器
//         {
//           switch(Workcase)
//           {

//               case 1:   

//                         DSTH= CarW/fabs(tan(b)-tan(a));
//                         if(DSTH>=sd)    
//                         { vehiclePostion->LeftRad=0;vehiclePostion->RightRad=0;return ;}                       
//                         LevelL1= sqrt (pow (sd,2)-pow (DSTH,2)) -CarW/2+cameraR;
//                         c=atan( LevelL1/(DSTH-cameraH));
//                         d=atan( (LevelL1+CarW)/(DSTH-cameraH));   
//                         vehiclePostion->RightRad=(float)radTodeg(c)*-1;   
//                         vehiclePostion->LeftRad=(float)radTodeg(d)*-1;
                    

//                         break ;
//               case 2:
                  

//                         DSTH= CarW/fabs(tan(b)-tan(a));
//                         LevelL1= cameraR-DSTH*tan(a);
//                         if(LevelL1>cameraR)     
//                         { vehiclePostion->LeftRad=0;vehiclePostion->RightRad=0;return ;}               
//                         c=atan( LevelL1/(DSTH-cameraH));
//                         d=atan( (CarW+LevelL1)/(DSTH-cameraH));   
//                         vehiclePostion->RightRad=(float)radTodeg(c)*-1;   
//                         vehiclePostion->LeftRad=(float)radTodeg(d)*-1;
//                         break ;
//               case 3:
//                         DSTH=sd;
//                         d=atan( CarW/(DSTH-cameraH));                   
//                         vehiclePostion->RightRad=0;   
//                         vehiclePostion->LeftRad=(float)radTodeg(d)*-1;

//                         break ;
//               case 4:

//                         DSTH= CarW/fabs(tan(b)-tan(a));
//                         LevelL1= DSTH*tan(a)-cameraR;     
//                         if(LevelL1>CarW)     
//                         { vehiclePostion->LeftRad=0;vehiclePostion->RightRad=0;return ;}    
//                         c=atan( LevelL1/(DSTH-cameraH));
//                         d=atan( ( CarW-LevelL1)/(DSTH-cameraH));   
//                         vehiclePostion->RightRad=(float)radTodeg(c);   
//                         vehiclePostion->LeftRad=(float)radTodeg(d)*-1 ;

//                         break ;
//               case 5:

//                         DSTH= CarW/fabs(tan(a)-tan(b));
//                           if(DSTH>=sd)    
//                           { vehiclePostion->LeftRad=0;vehiclePostion->RightRad=0;return ;}                       
//                         LevelL1= sqrt (pow (sd,2)-pow (DSTH,2))+CarW/2-cameraR;
//                         c=atan( LevelL1/(DSTH-cameraH));
//                         d=atan( (LevelL1-CarW)/(DSTH-cameraH));   
//                         vehiclePostion->RightRad=(float)radTodeg(c);   
//                         vehiclePostion->LeftRad=(float)radTodeg(d);

                      
//                         break ;
//               default :  

//                           vehiclePostion->LeftRad=0;vehiclePostion->RightRad=0;return ;

//                         break ;
            
//           }
      


//       }
// #else 
//       if(leftDeg>=rightDeg)     //左角度大于右边舍弃
//        { vehiclePostion->LeftRad=0;vehiclePostion->RightRad=0;return ;}               
//       if( leftDeg<0&&rightDeg<=0) Workcase=1;
//       else if( leftDeg<0&&rightDeg>0)Workcase=2;
//       else if( leftDeg>=0&&rightDeg>0)Workcase=3;
//       else Workcase=0;



// if(HCM_LEFT_SIDE)       //如果为左边灯控制器
//       {
//         switch(Workcase)
//           {
//               case 1:   
//               case 2:                 
//               case 3:
//                         DSTH= sd;                                        
//                         LevelL1= DSTH*tan(a)+cameraL+tempR;
//                         LevelL2= DSTH*tan(b)+cameraL-tempL;
//                         c=atan( LevelL1/(DSTH-cameraH));
//                         d=atan( LevelL2/(DSTH-cameraH));   
//                         vehiclePostion->RightRad=(float)radTodeg(c);   
//                         vehiclePostion->LeftRad=(float)radTodeg(d);
//                         break ;
       
//               default :  

//                           vehiclePostion->LeftRad=0;vehiclePostion->RightRad=0;return ;
//                         break ;
            
//         }
//       }
//       else  //如果为右边灯控制器
//         {
//           switch(Workcase)
//           {

//               case 1:   
//               case 2:
//               case 3:
//                         DSTH= sd;                                        
//                         LevelL1= DSTH* tan(a)-cameraR+tempR;
//                         LevelL2=  DSTH*tan(b)-cameraR-tempL;
//                         c=atan( LevelL1/(DSTH-cameraH));
//                         d=atan( LevelL2/(DSTH-cameraH));   
//                         vehiclePostion->RightRad=(float)radTodeg(c);   
//                         vehiclePostion->LeftRad=(float)radTodeg(d);

//                         break ;
       
//               default :  

//                           vehiclePostion->LeftRad=0;vehiclePostion->RightRad=0;return ;

//                         break ;
            
//             }
//         }

//    vehiclePostion->Len=LevelL1-LevelL2;

// #endif

//  }




// uint32  GetLightStatus(void)
// {
//           uint32  status=0,minDistance=600 ;
//           uint8  i = 0,j=0, icount=0;
//           VehiclePostion vehiclePostion;
//           float  minAngle,maxAngle;
//           SetAllon(ADBledChangeArr);
//           for ( i = 0; i < Most_ObstacleNumber; i++)// 每次的临时数据  轮询放到buffer
//           {
//             if( (cacheIFCValue[i].distance>4 &&cacheIFCValue[i].distance<400)  )// 踢出2米内，600米外
//               {
//                   icount++;     
//                   if(minAngle>cacheIFCValue[i].leftAngle){minAngle=cacheIFCValue[i].leftAngle;}
//                   if(maxAngle<cacheIFCValue[i].rightAngle){maxAngle=cacheIFCValue[i].rightAngle;}
//                   if(minDistance> cacheIFCValue[i].distance){minDistance=cacheIFCValue[i].distance;}
//               }
//           }

//            if(icount>DarkSpace ) //  注册buffer 大于4个  暗区暗区融合
//            {                
                
//                  GetDarkAreaAngle((float)cacheIFCValue[i].distance, (float)cacheIFCValue[i].leftAngle, (float)cacheIFCValue[i].rightAngle, (float)cacheIFCValue[i].leftAngleMovingSpeed,  &vehiclePostion);
//                  status = GetStatus(vehiclePostion.LeftRad, vehiclePostion.RightRad);
//            }
//            else
//            {
//               for (  i = 0; i < Most_ObstacleNumber; i++)// 每次的临时数据  轮询放到buffer
//               {
//                 if( (cacheIFCValue[i].distance>4 &&cacheIFCValue[i].distance<400)  )// 踢出2米内，400米外
//                 {
//                   GetDarkAreaAngle((float)cacheIFCValue[i].distance, (float)cacheIFCValue[i].leftAngle, (float)cacheIFCValue[i].rightAngle,(float)cacheIFCValue[i].leftAngleMovingSpeed,&vehiclePostion);
//                   status = GetStatus(vehiclePostion.LeftRad, vehiclePostion.RightRad);
//                 }
//                }
//            }
        

//          ADB_OPen_and_Close_delay();
//         //C_Memcpy_B(ADBledsinterface,ADBledChangeArr,84);
//   return  status;
// }








 void GetDarkAreaAngle (float sd,float leftDeg,float rightDeg,VehiclePostion* vehiclePostion)
 {
      uint8 Workcase=0;
      float  DSTH;
      float  LevelL1,LevelL2;  //左右边界
      float  a=0,b=0,c=0,d=0; //角度
      //float  cameraH,cameraL,cameraR,CarW;
      float  tempL,tempR;
        a=DegToRad(rightDeg);
        b=DegToRad(leftDeg);
       tempR=R_Repair;tempL=L_Repair;  

#if  MathMethod

      if(leftDeg>=rightDeg)     //左角度大于右边舍弃
       { vehiclePostion->LeftRad=0;vehiclePostion->RightRad=0;return ;}     
           
      if( leftDeg<=0&&rightDeg<=0) Workcase=1;
      else if( leftDeg<0&&rightDeg>=0)
      {
          if(fabs(leftDeg)>fabs(rightDeg))Workcase=2;
          else   if(fabs(leftDeg)==fabs(rightDeg))Workcase=3;
          else    Workcase=4;
      }
      else if( leftDeg>=0&&rightDeg>=0)Workcase=5;
      else Workcase=0;
    if(HCM_LEFT_SIDE)       //如果为左边灯控制器
      {
        switch(Workcase)
          {

              case 1:   

                        DSTH= CarW/fabs(tan(b)-tan(a));
                        if(DSTH>=sd)    
                        { vehiclePostion->LeftRad=0;vehiclePostion->RightRad=0;return ;}                       
                        LevelL1= sqrt (pow (sd,2)-pow (DSTH,2)) -CarW/2-cameraL;
                        c=atan( LevelL1/(DSTH-cameraH));
                        d=atan( (LevelL1+CarW)/(DSTH-cameraH));   
                        vehiclePostion->RightRad=(float)radTodeg(c)*-1;   
                        vehiclePostion->LeftRad=(float)radTodeg(d)*-1;
                    

                        break ;
              case 2:
                  

                        DSTH= CarW/fabs(tan(b)-tan(a));
                        LevelL1= cameraL+DSTH*tan(a);
                        if(LevelL1>CarW/2)     
                        { vehiclePostion->LeftRad=0;vehiclePostion->RightRad=0;return ;}               
                        c=atan( LevelL1/(DSTH-cameraH));
                        d=atan( (CarW-LevelL1)/(DSTH-cameraH));   
                        vehiclePostion->RightRad=(float)radTodeg(c);   
                        vehiclePostion->LeftRad=(float)radTodeg(d)*-1;
                    



                        break ;
              case 3:
                          DSTH=sd;
                          LevelL1=CarW;
                        c=atan( LevelL1/(DSTH-cameraH));                   
                        vehiclePostion->RightRad=(float)radTodeg(c);   
                        vehiclePostion->LeftRad=0;


                        break ;
              case 4:

                        DSTH= CarW/fabs(tan(b)-tan(a));
                        LevelL1= cameraL+DSTH*tan(a);     
                        if(LevelL1<CarW)     
                        { vehiclePostion->LeftRad=0;vehiclePostion->RightRad=0;return ;}    
                        c=atan( LevelL1/(DSTH-cameraH));
                        d=atan( ( LevelL1-CarW)/(DSTH-cameraH));   
                        vehiclePostion->RightRad=(float)radTodeg(c);   
                        vehiclePostion->LeftRad=(float)radTodeg(d) ;

                        break ;
              case 5:

                        DSTH= CarW/fabs(tan(a)-tan(b));
                          if(DSTH>=sd)    
                          { vehiclePostion->LeftRad=0;vehiclePostion->RightRad=0;return ;}                       
                        LevelL1= sqrt (pow (sd,2)-pow (DSTH,2)) +CarW/2+cameraL;
                        c=atan( LevelL1/(DSTH-cameraH));
                        d=atan( (LevelL1-CarW)/(DSTH-cameraH));   
                        vehiclePostion->RightRad=(float)radTodeg(c);   
                        vehiclePostion->LeftRad=(float)radTodeg(d);

                      
                        break ;
              default :  

                          vehiclePostion->LeftRad=0;vehiclePostion->RightRad=0;return ;

                        break ;
            
        }
      }
      else  //如果为右边灯控制器
        {
          switch(Workcase)
          {

              case 1:   

                        DSTH= CarW/fabs(tan(b)-tan(a));
                        if(DSTH>=sd)    
                        { vehiclePostion->LeftRad=0;vehiclePostion->RightRad=0;return ;}                       
                        LevelL1= sqrt (pow (sd,2)-pow (DSTH,2)) -CarW/2+cameraR;
                        c=atan( LevelL1/(DSTH-cameraH));
                        d=atan( (LevelL1+CarW)/(DSTH-cameraH));   
                        vehiclePostion->RightRad=(float)radTodeg(c)*-1;   
                        vehiclePostion->LeftRad=(float)radTodeg(d)*-1;
                    

                        break ;
              case 2:
                  

                        DSTH= CarW/fabs(tan(b)-tan(a));
                        LevelL1= cameraR-DSTH*tan(a);
                        if(LevelL1>cameraR)     
                        { vehiclePostion->LeftRad=0;vehiclePostion->RightRad=0;return ;}               
                        c=atan( LevelL1/(DSTH-cameraH));
                        d=atan( (CarW+LevelL1)/(DSTH-cameraH));   
                        vehiclePostion->RightRad=(float)radTodeg(c)*-1;   
                        vehiclePostion->LeftRad=(float)radTodeg(d)*-1;
                        break ;
              case 3:
                        DSTH=sd;
                        d=atan( CarW/(DSTH-cameraH));                   
                        vehiclePostion->RightRad=0;   
                        vehiclePostion->LeftRad=(float)radTodeg(d)*-1;

                        break ;
              case 4:

                        DSTH= CarW/fabs(tan(b)-tan(a));
                        LevelL1= DSTH*tan(a)-cameraR;     
                        if(LevelL1>CarW)     
                        { vehiclePostion->LeftRad=0;vehiclePostion->RightRad=0;return ;}    
                        c=atan( LevelL1/(DSTH-cameraH));
                        d=atan( ( CarW-LevelL1)/(DSTH-cameraH));   
                        vehiclePostion->RightRad=(float)radTodeg(c);   
                        vehiclePostion->LeftRad=(float)radTodeg(d)*-1 ;

                        break ;
              case 5:

                        DSTH= CarW/fabs(tan(a)-tan(b));
                          if(DSTH>=sd)    
                          { vehiclePostion->LeftRad=0;vehiclePostion->RightRad=0;return ;}                       
                        LevelL1= sqrt (pow (sd,2)-pow (DSTH,2))+CarW/2-cameraR;
                        c=atan( LevelL1/(DSTH-cameraH));
                        d=atan( (LevelL1-CarW)/(DSTH-cameraH));   
                        vehiclePostion->RightRad=(float)radTodeg(c);   
                        vehiclePostion->LeftRad=(float)radTodeg(d);

                      
                        break ;
              default :  

                          vehiclePostion->LeftRad=0;vehiclePostion->RightRad=0;return ;

                        break ;
            
          }
      


      }
#else 
      if(leftDeg>=rightDeg)     //左角度大于右边舍弃
       { vehiclePostion->LeftRad=0;vehiclePostion->RightRad=0;return ;}               
      if( leftDeg<0&&rightDeg<=0) Workcase=1;
      else if( leftDeg<0&&rightDeg>0)Workcase=2;
      else if( leftDeg>=0&&rightDeg>0)Workcase=3;
      else Workcase=0;



if(HCM_LEFT_SIDE)       //如果为左边灯控制器
      {
        switch(Workcase)
          {
              case 1:   
              case 2:                 
              case 3:
                        DSTH= sd;                                        
                        LevelL1= DSTH*tan(a)+cameraL+tempR;
                        LevelL2= DSTH*tan(b)+cameraL-tempL;
                        c=atan( LevelL1/(DSTH-cameraH));
                        d=atan( LevelL2/(DSTH-cameraH));   
                        vehiclePostion->RightRad=(float)radTodeg(c);   
                        vehiclePostion->LeftRad=(float)radTodeg(d);
                        break ;
       
              default :  

                          vehiclePostion->LeftRad=0;vehiclePostion->RightRad=0;return ;
                        break ;
            
        }
      }
      else  //如果为右边灯控制器
        {
          switch(Workcase)
          {

              case 1:   
              case 2:
              case 3:
                        DSTH= sd;                                        
                        LevelL1= DSTH* tan(a)-cameraR+tempR;
                        LevelL2=  DSTH*tan(b)-cameraR-tempL;
                        c=atan( LevelL1/(DSTH-cameraH));
                        d=atan( LevelL2/(DSTH-cameraH));   
                        vehiclePostion->RightRad=(float)radTodeg(c);   
                        vehiclePostion->LeftRad=(float)radTodeg(d);

                        break ;
       
              default :  

                          vehiclePostion->LeftRad=0;vehiclePostion->RightRad=0;return ;

                        break ;
            
            }
        }

   vehiclePostion->Len=LevelL1-LevelL2;

#endif

 }

 

 

uint32 GetStatus(float minA, float maxA)
{
  uint32 status=0;
  uint8  j=0;

   if(minA>=maxA)return status;

  for (j = 0; j < HS11LEDnumber; j++)
  {
    if (minA < Hcm_led_anlge[j].LED_END_ANG && maxA > Hcm_led_anlge[j].LED_ST_ANG)//重合关灯
    {
        SetSingleLedOff(ADBledChangeArr ,j);
     }
  }
     return (~status);
}



uint8 PushIFCFrame(void )
{
	 uint8  i=0;
	static uint16 counter=0;
    static uint16 preCounter450=0xff;
    uint32_t SignaltempValue=0;

                    counter++;
                    if(counter>255)counter=0;
                    for(i=0;i<Most_ObstacleNumber;i++)cacheIFCValue[i].iCounter=counter;
                
                    Interface_GetSignal_VehObjforADB1AdbAbsDist(&SignaltempValue);
                    cacheIFCValue[0].distance= (uint16_t)SignaltempValue;             
                    Interface_GetSignal_VehObjforADB1AdbClassn(&SignaltempValue);
                    cacheIFCValue[0].Classn=  (uint16_t)SignaltempValue;                   
                     Interface_GetSignal_VehObjforADB1AdbHozlAgLe(&SignaltempValue);
                    cacheIFCValue[0].leftAngle=   (float)SignaltempValue *0.05-40  ;                  
                    Interface_GetSignal_VehObjforADB1AdbHozlAgRi(&SignaltempValue);
                    cacheIFCValue[0].rightAngle=  (float)SignaltempValue *0.05-40  ;  
                    
                    Interface_GetSignal_VehObjforADB1AdbVertAg(&SignaltempValue);
                    cacheIFCValue[0].bottomAngle= (float)SignaltempValue *0.5-3  ;     
                    Interface_GetSignal_VehObjforADB1AdbObjHozlAgSpdRi(&SignaltempValue);
                    cacheIFCValue[0].rightAngleMovingSpeed= (float)SignaltempValue *0.2-50;
                    Interface_GetSignal_VehObjforADB1AdbObjHozlAgSpdLe(&SignaltempValue);
                    cacheIFCValue[0].leftAngleMovingSpeed= (float)SignaltempValue *0.2-50; ;       
                    Interface_GetSignal_VehObjforADB1AdbTrkInfo(&SignaltempValue);
                    cacheIFCValue[0].TrkInfo= (uint8_t)SignaltempValue ;        
                    Interface_GetSignal_VehObjforADB1AdbObjDir(&SignaltempValue);
                    cacheIFCValue[0].ObjDir= (uint8_t)SignaltempValue ;


                    Interface_GetSignal_VehObjforADB2AdbAbsDist(&SignaltempValue);
                    cacheIFCValue[1].distance= (uint16_t)SignaltempValue;               
                    Interface_GetSignal_VehObjforADB2AdbClassn(&SignaltempValue);
                    cacheIFCValue[1].Classn=  (uint16_t)SignaltempValue;                   
                     Interface_GetSignal_VehObjforADB2AdbHozlAgLe(&SignaltempValue);
                    cacheIFCValue[1].leftAngle=   (float)SignaltempValue *0.05-40  ;                  
                    Interface_GetSignal_VehObjforADB2AdbHozlAgRi(&SignaltempValue);
                    cacheIFCValue[1].rightAngle=  (float)SignaltempValue *0.05-40  ;               
                    Interface_GetSignal_VehObjforADB2AdbVertAg(&SignaltempValue);
                    cacheIFCValue[1].bottomAngle= (float)SignaltempValue *0.5-3  ;     
                    Interface_GetSignal_VehObjforADB2AdbObjHozlAgSpdRi(&SignaltempValue);
                    cacheIFCValue[1].rightAngleMovingSpeed= (float)SignaltempValue *0.2-50;
                    Interface_GetSignal_VehObjforADB2AdbObjHozlAgSpdLe(&SignaltempValue);
                    cacheIFCValue[1].leftAngleMovingSpeed= (float)SignaltempValue *0.2-50; ;       
                    Interface_GetSignal_VehObjforADB2AdbTrkInfo(&SignaltempValue);
                    cacheIFCValue[1].TrkInfo= (uint8_t)SignaltempValue ;        
                    Interface_GetSignal_VehObjforADB2AdbObjDir(&SignaltempValue);
                    cacheIFCValue[1].ObjDir= (uint8_t)SignaltempValue ;


                    Interface_GetSignal_VehObjforADB3AdbAbsDist(&SignaltempValue);
                    cacheIFCValue[2].distance= (uint16_t)SignaltempValue;               
                    Interface_GetSignal_VehObjforADB3AdbClassn(&SignaltempValue);
                    cacheIFCValue[2].Classn=  (uint16_t)SignaltempValue;                   
                     Interface_GetSignal_VehObjforADB3AdbHozlAgLe(&SignaltempValue);
                    cacheIFCValue[2].leftAngle=   (float)SignaltempValue *0.05-40  ;                  
                    Interface_GetSignal_VehObjforADB3AdbHozlAgRi(&SignaltempValue);
                    cacheIFCValue[2].rightAngle=  (float)SignaltempValue *0.05-40  ;               
                    Interface_GetSignal_VehObjforADB3AdbVertAg(&SignaltempValue);
                    cacheIFCValue[2].bottomAngle= (float)SignaltempValue *0.5-3  ;     
                    Interface_GetSignal_VehObjforADB3AdbObjHozlAgSpdRi(&SignaltempValue);
                    cacheIFCValue[2].rightAngleMovingSpeed= (float)SignaltempValue *0.2-50;
                    Interface_GetSignal_VehObjforADB3AdbObjHozlAgSpdLe(&SignaltempValue);
                    cacheIFCValue[2].leftAngleMovingSpeed= (float)SignaltempValue *0.2-50; ;       
                    Interface_GetSignal_VehObjforADB3AdbTrkInfo(&SignaltempValue);
                    cacheIFCValue[2].TrkInfo= (uint8_t)SignaltempValue ;        
                    Interface_GetSignal_VehObjforADB3AdbObjDir(&SignaltempValue);
                    cacheIFCValue[2].ObjDir= (uint8_t)SignaltempValue ;


                    Interface_GetSignal_VehObjforADB4AdbAbsDist(&SignaltempValue);
                    cacheIFCValue[3].distance= (uint16_t)SignaltempValue;               
                    Interface_GetSignal_VehObjforADB4AdbClassn(&SignaltempValue);
                    cacheIFCValue[3].Classn=  (uint16_t)SignaltempValue;                   
                     Interface_GetSignal_VehObjforADB4AdbHozlAgLe(&SignaltempValue);
                    cacheIFCValue[3].leftAngle=   (float)SignaltempValue *0.05-40  ;                  
                    Interface_GetSignal_VehObjforADB4AdbHozlAgRi(&SignaltempValue);
                    cacheIFCValue[3].rightAngle=  (float)SignaltempValue *0.05-40  ;               
                    Interface_GetSignal_VehObjforADB4AdbVertAg(&SignaltempValue);
                    cacheIFCValue[3].bottomAngle= (float)SignaltempValue *0.5-3  ;     
                    Interface_GetSignal_VehObjforADB4AdbObjHozlAgSpdRi(&SignaltempValue);
                    cacheIFCValue[3].rightAngleMovingSpeed= (float)SignaltempValue *0.2-50;
                    Interface_GetSignal_VehObjforADB4AdbObjHozlAgSpdLe(&SignaltempValue);
                    cacheIFCValue[3].leftAngleMovingSpeed= (float)SignaltempValue *0.2-50; ;       
                    Interface_GetSignal_VehObjforADB4AdbTrkInfo(&SignaltempValue);
                    cacheIFCValue[3].TrkInfo= (uint8_t)SignaltempValue ;        
                    Interface_GetSignal_VehObjforADB4AdbObjDir(&SignaltempValue);
                    cacheIFCValue[3].ObjDir= (uint8_t)SignaltempValue ;


                    Interface_GetSignal_VehObjforADB5AdbAbsDist(&SignaltempValue);
                    cacheIFCValue[4].distance= (uint16_t)SignaltempValue;               
                    Interface_GetSignal_VehObjforADB5AdbClassn(&SignaltempValue);
                    cacheIFCValue[4].Classn=  (uint16_t)SignaltempValue;                   
                     Interface_GetSignal_VehObjforADB5AdbHozlAgLe(&SignaltempValue);
                    cacheIFCValue[4].leftAngle=   (float)SignaltempValue *0.05-40  ;                  
                    Interface_GetSignal_VehObjforADB5AdbHozlAgRi(&SignaltempValue);
                    cacheIFCValue[4].rightAngle=  (float)SignaltempValue *0.05-40  ;               
                    Interface_GetSignal_VehObjforADB5AdbVertAg(&SignaltempValue);
                    cacheIFCValue[4].bottomAngle= (float)SignaltempValue *0.5-3  ;     
                    Interface_GetSignal_VehObjforADB5AdbObjHozlAgSpdRi(&SignaltempValue);
                    cacheIFCValue[4].rightAngleMovingSpeed= (float)SignaltempValue *0.2-50;
                    Interface_GetSignal_VehObjforADB5AdbObjHozlAgSpdLe(&SignaltempValue);
                    cacheIFCValue[4].leftAngleMovingSpeed= (float)SignaltempValue *0.2-50; ;       
                    Interface_GetSignal_VehObjforADB5AdbTrkInfo(&SignaltempValue);
                    cacheIFCValue[4].TrkInfo= (uint8_t)SignaltempValue ;        
                    Interface_GetSignal_VehObjforADB5AdbObjDir(&SignaltempValue);
                    cacheIFCValue[4].ObjDir= (uint8_t)SignaltempValue ;

                    Interface_GetSignal_VehObjforADB6AdbAbsDist(&SignaltempValue);
                    cacheIFCValue[5].distance= (uint16_t)SignaltempValue;               
                    Interface_GetSignal_VehObjforADB6AdbClassn(&SignaltempValue);
                    cacheIFCValue[5].Classn=  (uint16_t)SignaltempValue;                   
                     Interface_GetSignal_VehObjforADB6AdbHozlAgLe(&SignaltempValue);
                    cacheIFCValue[5].leftAngle=   (float)SignaltempValue *0.05-40  ;                  
                    Interface_GetSignal_VehObjforADB6AdbHozlAgRi(&SignaltempValue);
                    cacheIFCValue[5].rightAngle=  (float)SignaltempValue *0.05-40  ;               
                    Interface_GetSignal_VehObjforADB6AdbVertAg(&SignaltempValue);
                    cacheIFCValue[5].bottomAngle= (float)SignaltempValue *0.5-3  ;     
                    Interface_GetSignal_VehObjforADB6AdbObjHozlAgSpdRi(&SignaltempValue);
                    cacheIFCValue[5].rightAngleMovingSpeed= (float)SignaltempValue *0.2-50;
                    Interface_GetSignal_VehObjforADB6AdbObjHozlAgSpdLe(&SignaltempValue);
                    cacheIFCValue[5].leftAngleMovingSpeed= (float)SignaltempValue *0.2-50; ;       
                    Interface_GetSignal_VehObjforADB6AdbTrkInfo(&SignaltempValue);
                    cacheIFCValue[5].TrkInfo= (uint8_t)SignaltempValue ;        
                    Interface_GetSignal_VehObjforADB6AdbObjDir(&SignaltempValue);
                    cacheIFCValue[5].ObjDir= (uint8_t)SignaltempValue ;



                    Interface_GetSignal_VehObjforADB7AdbAbsDist(&SignaltempValue);
                    cacheIFCValue[6].distance= (uint16_t)SignaltempValue;               
                    Interface_GetSignal_VehObjforADB7AdbClassn(&SignaltempValue);
                    cacheIFCValue[6].Classn=  (uint16_t)SignaltempValue;                   
                     Interface_GetSignal_VehObjforADB7AdbHozlAgLe(&SignaltempValue);
                    cacheIFCValue[6].leftAngle=   (float)SignaltempValue *0.05-40  ;                  
                    Interface_GetSignal_VehObjforADB7AdbHozlAgRi(&SignaltempValue);
                    cacheIFCValue[6].rightAngle=  (float)SignaltempValue *0.05-40  ;               
                    Interface_GetSignal_VehObjforADB7AdbVertAg(&SignaltempValue);
                    cacheIFCValue[6].bottomAngle= (float)SignaltempValue *0.5-3  ;     
                    Interface_GetSignal_VehObjforADB7AdbObjHozlAgSpdRi(&SignaltempValue);
                    cacheIFCValue[6].rightAngleMovingSpeed= (float)SignaltempValue *0.2-50;
                    Interface_GetSignal_VehObjforADB7AdbObjHozlAgSpdLe(&SignaltempValue);
                    cacheIFCValue[6].leftAngleMovingSpeed= (float)SignaltempValue *0.2-50; ;       
                    Interface_GetSignal_VehObjforADB7AdbTrkInfo(&SignaltempValue);
                    cacheIFCValue[6].TrkInfo= (uint8_t)SignaltempValue ;        
                    Interface_GetSignal_VehObjforADB7AdbObjDir(&SignaltempValue);
                    cacheIFCValue[6].ObjDir= (uint8_t)SignaltempValue ;



                    Interface_GetSignal_VehObjforADB8AdbAbsDist(&SignaltempValue);
                    cacheIFCValue[7].distance= (uint16_t)SignaltempValue;               
                    Interface_GetSignal_VehObjforADB8AdbClassn(&SignaltempValue);
                    cacheIFCValue[7].Classn=  (uint16_t)SignaltempValue;                   
                     Interface_GetSignal_VehObjforADB8AdbHozlAgLe(&SignaltempValue);
                    cacheIFCValue[7].leftAngle=   (float)SignaltempValue *0.05-40  ;                  
                    Interface_GetSignal_VehObjforADB8AdbHozlAgRi(&SignaltempValue);
                    cacheIFCValue[7].rightAngle=  (float)SignaltempValue *0.05-40  ;               
                    Interface_GetSignal_VehObjforADB8AdbVertAg(&SignaltempValue);
                    cacheIFCValue[7].bottomAngle= (float)SignaltempValue *0.5-3  ;     
                    Interface_GetSignal_VehObjforADB8AdbObjHozlAgSpdRi(&SignaltempValue);
                    cacheIFCValue[7].rightAngleMovingSpeed= (float)SignaltempValue *0.2-50;
                    Interface_GetSignal_VehObjforADB8AdbObjHozlAgSpdLe(&SignaltempValue);
                    cacheIFCValue[7].leftAngleMovingSpeed= (float)SignaltempValue *0.2-50; ;       
                    Interface_GetSignal_VehObjforADB8AdbTrkInfo(&SignaltempValue);
                    cacheIFCValue[7].TrkInfo= (uint8_t)SignaltempValue ;        
                    Interface_GetSignal_VehObjforADB8AdbObjDir(&SignaltempValue);
                    cacheIFCValue[7].ObjDir= (uint8_t)SignaltempValue ;

 

  return E_OK;
 
}




uint32  GetLightStatus(void)  //10ms
{
      float leftGap=0,rightGap=0,degGap=0;
      uint32 dGap=0;
	     uint32  status=0,minDistance=600 ;
	     uint8  i = 0,j=0, Darkcount=0;
      VehiclePostion vehiclePostion;
           
         //缓存最小最大需要遮挡的灯的角度
      float minAngle=40, maxAngle=-40 ;
	     int icounter=cacheIFCValue[0].iCounter;
 
     for ( i = 0; i < 30; i++) //设计30个buffer，存储当前跟踪的有效数据
      {
				 if (ifcTarget[i].isActive && ( icounter-ifcTarget[i].iCounter>50|| (icounter-ifcTarget[i].iCounter <0
                  && icounter-ifcTarget[i].iCounter+255 >50)))   //如果4次没连续的有效数据，从当前buffer注销
					{
					 ifcTarget[i].isActive =0;
					 ifcTarget[i].Input_d1=0;
					 ifcTarget[i].Input_u1=0;
					 ifcTarget[i].Input_v1=0;
          ifcTarget[i].Input_degsped=0;
					 ifcTarget[i].iCounter=0;
          ifcTarget[i].livecounter=0;
					}
       if( ifcTarget[i].isActive) 
          {
              if (minAngle>ifcTarget[i].Input_v1){minAngle=ifcTarget[i].Input_v1;}
              if (maxAngle< ifcTarget[i].Input_u1){maxAngle= ifcTarget[i].Input_u1;}
              if(minDistance> ifcTarget[i].Input_d1){minDistance=ifcTarget[i].Input_d1;}
          }

      }



          //判断是否当前已经处理的目标物
          uint8 treated[30] = {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,
                            false,false,false,false,false,false,false,false,false,false,false,false,false,false,false};

          for (  i = 0; i < Most_ObstacleNumber; i++)// 每次的临时数据  轮询放到buffer
          {
            if( (cacheIFCValue[i].distance>4 &&cacheIFCValue[i].distance<800)  )// 踢出2米内，600米外
              {

                  uint8 hasActived = false;
                  for ( j = 0; j < 30; j++)
                  {
                      if (ifcTarget[j].isActive && !treated[j]) //30个激活里面找有接近的
                      {
                              dGap= abs(ifcTarget[j].Input_d1 - cacheIFCValue[i].distance)  ;
                              rightGap=fabs(ifcTarget[j].Input_u1 - cacheIFCValue[i].rightAngle);
                              leftGap=fabs(ifcTarget[j].Input_v1 - cacheIFCValue[i].leftAngle);
                              degGap=fabs(ifcTarget[j].Input_degsped - cacheIFCValue[i].leftAngleMovingSpeed);

                              if (dGap<Max_distPre && leftGap<Max_DegPre && rightGap<Max_DegPre&&degGap<Max_DegSpeedPre)  //跟踪 
                              {
                                  treated[j]=true; 
                                  ifcTarget[j].iCounter = cacheIFCValue[i].iCounter;
                                  ifcTarget[j].Input_d1 = cacheIFCValue[i].distance;
                                  ifcTarget[j].Input_u1 = cacheIFCValue[i].rightAngle;
                                  ifcTarget[j].Input_v1 = cacheIFCValue[i].leftAngle; 
                                  ifcTarget[j].Input_degsped=cacheIFCValue[i].leftAngleMovingSpeed;
                                  hasActived = true;
                                  ifcTarget[j].livecounter++;
                                  if(ifcTarget[j].livecounter>65530)ifcTarget[j].livecounter=100;
                               break;
                           };
                      }
                      
                   }


                  if (!hasActived)//30个里面注册新的
                  {
                      
                      for ( j = 0; j < 30; j++)
                      {
                          if (!ifcTarget[j].isActive)
                          {
                              treated[j]=true;  
                              ifcTarget[j].iCounter = cacheIFCValue[i].iCounter;
                              ifcTarget[j].Input_d1 = cacheIFCValue[i].distance;
                              ifcTarget[j].Input_u1 = cacheIFCValue[i].rightAngle;
                              ifcTarget[j].Input_v1 = cacheIFCValue[i].leftAngle;     
                              ifcTarget[j].Input_degsped=cacheIFCValue[i].leftAngleMovingSpeed;              
                                ifcTarget[j].isActive = true;
                                ifcTarget[j].livecounter=0;
                              break;
                          }
                      }
                  }
              }
          }
 

           SetAllon(ADBledChangeArr);
    
         for (  i = 0; i < 30; i++){ if(ifcTarget[i].livecounter>=14) Darkcount++;  }

           if(Darkcount>DarkSpace ) //  注册buffer 大于4个  暗区暗区融合
           {
            
                  if( HCM_LEFT_SIDE)
                  {
                  GetDarkAreaAngle((float)minDistance, minAngle, maxAngle,&vehiclePostion);
                  status = GetStatus(vehiclePostion.LeftRad, vehiclePostion.RightRad);              
                  }
                  else
                  {
                  GetDarkAreaAngle((float)minDistance, minAngle, maxAngle,&vehiclePostion);
                  status = GetStatus(vehiclePostion.LeftRad, vehiclePostion.RightRad);
                  }
           }
           else   //否则 小于4个注册buffer  
           {
                for (  i = 0; i < 30; i++)
                {
                  
                  // if (ifcTarget[i].isActive)
                      if (ifcTarget[i].isActive&& ifcTarget[i].livecounter>=14)
                    {
                        if( HCM_LEFT_SIDE)
                        {
                        GetDarkAreaAngle((float)ifcTarget[i].Input_d1, (float)ifcTarget[i].Input_v1, (float)ifcTarget[i].Input_u1,&vehiclePostion);
                        status = GetStatus(vehiclePostion.LeftRad, vehiclePostion.RightRad);
                        }
                        else
                        {
                        GetDarkAreaAngle((float)ifcTarget[i].Input_d1, (float)ifcTarget[i].Input_v1, (float)ifcTarget[i].Input_u1,&vehiclePostion);
                        status = GetStatus(vehiclePostion.LeftRad, vehiclePostion.RightRad);
         
                        }
                    }
                }
           }
  for(i=0;i<HS11LEDnumber;i++)
  {
         if(ADBledChangeArr[i]==0)     break;     
  }
 if(i==HS11LEDnumber)
 {
  i=255;
 }



 //ADB_OPen_and_Close_delay();
 C_Memcpy_B(ADBledsinterface,ADBledChangeArr,HS11LEDnumber);
  return  status;// StatusStay(status);
}

void ADB_OPen_and_Close_delay(void)
{
      static  uint8 Counter_Delay[84]={0};
      uint8 i=0;
      for(i=0;i<HS11LEDnumber;i++)
      {
            if(ADBledsinterface[i]==1&&ADBledChangeArr[i]==0)
            {
             ADBledsinterface[i]=0;
            }
            else if(ADBledsinterface[i]==0&&ADBledChangeArr[i]==1)
            {
                Counter_Delay[i]++;

                if(Counter_Delay[i]>14)
                {
                   ADBledsinterface[i]=1; Counter_Delay[i]=0;
                }
            }
      }
}





void ADBB_Init(void)
{
uint8  ADBEna[84];
uint8 i=0,j=0,LEDnumber=0 ;

uint16  ADBleAngle[84];
uint16  ADBriAngle[84];

  if  (HCM_LEFT_SIDE)
  {
   Get_ParaMgr_pFanADBleEna_B(ADBEna );
   Get_ParaMgr_pFanADBlepPixel_LeftBdrl(ADBleAngle );
  Get_ParaMgr_pFanADBlepPixel_RightBdr(ADBriAngle );
  }
  else
  {
    Get_ParaMgr_pFanADBriEna_B(ADBEna);
   Get_ParaMgr_pFanADBripPixel_LeftBdrl(ADBleAngle );
   Get_ParaMgr_pFanADBripPixel_RightBdr(ADBriAngle );
   }
  
  
for(i=0;i<84;i++)
{
if(ADBEna[i]!=0){LEDnumber++; }
else  break;
}
HS11LEDnumber=LEDnumber;


  for(i=0;i<HS11LEDnumber;i++)
  {
  Hcm_led_anlge[i].LED_ST_ANG=(float)ADBleAngle[i]*0.01-90;
  Hcm_led_anlge[i].LED_END_ANG=(float)ADBriAngle[i]*0.01-90;
  ADBledsinterface[i]=ADBledsetoff;
  }

  cameraH=(float)DH/10.0;
  cameraL=(float)L_LEFT/10.0;
  cameraR=(float)L_RIGHT/10.0;
  CarW=(float)Carwidth/10.0;
  L_Repair=(float)L_DarkRepair/10.0;
  R_Repair=(float)R_DarkRepair/10.0;

}


static ADBConditionsstruct HCMADBCon;
void ADBMainFuction(void )
{
  uint32_t  SignaltempValue=0;

  SignaltempValue = Get_pAHBCType();
  if (SignaltempValue != 3) return;
  
  Interface_GetSignal_ActvnOfAhbc(&SignaltempValue);
  HCMADBCon.ActvnOfAhbc=SignaltempValue;
  Interface_GetSignal_CameraStsforAHBC(&SignaltempValue);
  HCMADBCon.CameraStsforAHBC=SignaltempValue;
  Interface_GetSignal_TooManyCars(&SignaltempValue);
  HCMADBCon.TooManyCars =SignaltempValue;
  Interface_GetSignal_LitArea(&SignaltempValue);
  HCMADBCon.LitArea= SignaltempValue;
  Interface_GetSignal_ActnOfLedHiBeam(&SignaltempValue);
  HCMADBCon.ActnOfLedHiBeam=SignaltempValue;

  



//Hs11ADBstatus=ADBactive;  
 switch ( Hs11ADBstatus)
 {
  case  ADBoffline :      
                            
                                SetAlloff(ADBledsinterface);
                                if(HCMADBCon.ActvnOfAhbc==1&&(HCMADBCon.CameraStsforAHBC==1||HCMADBCon.CameraStsforAHBC==3 )
                                 &&HCMADBCon.TooManyCars==0&&HCMADBCon.LitArea==0
                                &&HCMADBCon.ActnOfLedHiBeam==0)   
                                {
                                  Hs11ADBstatus =ADBopenwindow;
                                }                                                                                      
                               break;
  case  ADBopenwindow :             
                                                      
                          if(ParaMgr_pADBSequence_en_B) 
                            { ADBopenwindowdeal(1);    }
                          else   
                            {ADBopenwindowfinshined=1;}

                            if( HCMADBCon.ActnOfLedHiBeam==0) 
                            {
                                if( ADBopenwindowfinshined==1) 
                                {
                                  Hs11ADBstatus =ADBactive;
                                  ADBopenwindowfinshined=0;
                                }                             
                            }
                            else 
                            {
                                Hs11ADBstatus =ADBoffline;                               
                            }

                              break;
  case  ADBactive :            
                                           
                             PushIFCFrame();//10ms一次
                             GetLightStatus(); //10ms一次

                           /*点亮灯珠*/
                      
                            if( (HCMADBCon.ActvnOfAhbc==1&&(HCMADBCon.CameraStsforAHBC==1||HCMADBCon.CameraStsforAHBC==3 )
                                 &&HCMADBCon.TooManyCars==0&&HCMADBCon.LitArea==0&&HCMADBCon.ActnOfLedHiBeam==0
                                 )!=1 
                               )
                               {
                                Hs11ADBstatus =ADBUADBclosewindow;
                               }

                              if(HCMADBCon.ActnOfLedHiBeam==1){   Hs11ADBstatus =ADBoffline; }
                         

                                       break;
  case  ADBUADBclosewindow :        
                                if(HCMADBCon.ActnOfLedHiBeam==1)
                                {  Hs11ADBstatus =ADBoffline; }
                                else 
                                {                                                         
                                        if(ParaMgr_pADBSequence_en_B) 
                                          {  ADBclosewindowdeal(1);   }
                                        else   
                                          { ADBclosewindowfinshined=1;}

                                          if(ADBclosewindowfinshined==1) 
                                          {
                                            Hs11ADBstatus =ADBoffline;
                                            ADBclosewindowfinshined=0;
                                          }
                                }                                                                
                                 break;

  default :                       

                                 Hs11ADBstatus =ADBoffline;
                                break ;

 }
    
 
}


Std_ReturnType  GetADBLedsOnoffcmd( uint8_t*ADBLedsOnoffcmd  )
{
  Std_ReturnType rtval = E_OK;
  uint8_t j=0;
  for(j=0;j<HS11LEDnumber;j++) ADBLedsOnoffcmd[j]=ADBledsinterface[j];
  return rtval;
}


uint8_t  GetADBstatus(void )
{
      return  Hs11ADBstatus;
}



 static Std_ReturnType SetAlloff(uint8_t*g_adb_onoff)
 {
Std_ReturnType rtval = E_OK;
  uint8_t j=0;
 for(j=0;j<HS11LEDnumber;j++) g_adb_onoff[j]=ADBledsetoff;

  return rtval;
 }


 static  Std_ReturnType SetAllon(uint8_t*g_adb_onoff  )
 {
  Std_ReturnType rtval = E_OK;
  uint8_t j=0;
 for(j=0;j<HS11LEDnumber;j++) g_adb_onoff[j]=ADBledseton;
   return rtval;
 } 

 static  Std_ReturnType SetSingleLedOn( uint8_t*g_adb_onoff,uint8_t num)
 {
  Std_ReturnType rtval = E_OK;
  g_adb_onoff[num]=ADBledseton;
   return rtval;
 } 

 static  Std_ReturnType SetSingleLedOff( uint8_t*g_adb_onoff,uint8_t num)
 {
  Std_ReturnType rtval = E_OK;
   g_adb_onoff[num]=ADBledsetoff;
   return rtval;
 } 



 static Std_ReturnType ADBopenwindowdeal(uint8_t  Row )
 {
      Std_ReturnType rtval = E_OK;
      static  uint8_t indexopen=0;
      static  uint8_t  flowcounter=0;
      uint8_t flowflag=0;
        flowcounter++;
        if(flowcounter> ParaMgr_pADBSequenceTime_W/(10*HS11LEDnumber))
        {
        flowcounter=0;flowflag=1;
        }
        if(ADBopenwindowfinshined==0&&flowflag==1)
         {
            if(Row==1 )
            {
                      if(HS11LEDnumber%2==0) //偶数
                      {  
                        ADBledsinterface[ HS11LEDnumber/2-indexopen]=ADBledseton;
                        ADBledsinterface[HS11LEDnumber/2+indexopen-1]=ADBledseton;
                      

                        if(indexopen<=HS11LEDnumber/2&&indexopen+1>HS11LEDnumber/2)
                        {
                          ADBopenwindowfinshined=1; indexopen=0;
                        }
                          if(ADBopenwindowfinshined==0) indexopen++;

                      }
                    else //奇数
                     {

                        ADBledsinterface[ HS11LEDnumber/2-indexopen]=ADBledseton;
                        ADBledsinterface[HS11LEDnumber/2+indexopen]=ADBledseton;                
                        if(indexopen<=HS11LEDnumber/2&&indexopen+1>HS11LEDnumber/2)
                        {
                          ADBopenwindowfinshined=1; indexopen=0;
                        }

                        if(ADBopenwindowfinshined==0)indexopen++;

                    }

            }

      }
  return rtval;
 }


  static Std_ReturnType ADBclosewindowdeal(uint8_t  Row )
 {
    Std_ReturnType rtval = E_OK;
    static  uint8_t indexclose=0;

      static  uint8_t  flowcounter=0;
      uint8_t flowflag=0;
        flowcounter++;
        if(flowcounter> ParaMgr_pADBSequenceTime_W/(10*HS11LEDnumber))
        {
        flowcounter=0;flowflag=1;
        }

    if(ADBclosewindowfinshined==0&&flowflag)
    {
        if(Row==1 )
        {
      
                      ADBledsinterface[ indexclose]=ADBledsetoff;
                      ADBledsinterface[HS11LEDnumber-indexclose-1]=ADBledsetoff;
                      if(indexclose<=HS11LEDnumber/2&&indexclose+1>HS11LEDnumber/2)
                      {
                        ADBclosewindowfinshined=1; indexclose=0;
                      }

                      if(ADBclosewindowfinshined==0)indexclose++;


      }
    }
  return rtval;
  }

 