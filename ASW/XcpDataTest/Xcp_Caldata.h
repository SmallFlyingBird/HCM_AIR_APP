#ifndef XCP_CAL_DATA_H
#define XCP_CAL_DATA_H

#include"Std_Types.h"

extern uint8 Calib_A __attribute__((section(".CalData"))) ;
extern uint8 Calib_B __attribute__((section(".CalData"))) ;


extern uint8   Carwidth ;
extern uint8   DH ;
extern uint8  L_LEFT ;
extern uint8  L_RIGHT ;
extern uint8  DarkSpace ;
extern uint8 L_DarkRepair;
extern uint8 R_DarkRepair;


 
extern uint32 Mea_A ;
 

#endif

