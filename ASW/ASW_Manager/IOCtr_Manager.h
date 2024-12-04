/*
 * ASW_Manager.c
 *
 *  Created on: 2024.04.15
 *      Author: mihuiliang
 */
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


/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/
/* 434B CallBack */
Std_ReturnType IOCtr_434B_Cbk(uint8 IOCtrTypeState);
/* 4358 CallBack */
Std_ReturnType IOCtr_4358_Cbk(uint8 IOCtrTypeState);
/* channel1 cbk*/
Std_ReturnType IOCtr_4359_Cbk(uint8 IOCtrType);
/* channel2 cbk*/
Std_ReturnType IOCtr_435B_Cbk(uint8 IOCtrType);
/* channel3 cbk*/
Std_ReturnType IOCtr_435C_Cbk(uint8 IOCtrType);
/* channel4 cbk*/
Std_ReturnType IOCtr_435D_Cbk(uint8 IOCtrType);
/* channel5 cbk*/
Std_ReturnType IOCtr_435E_Cbk(uint8 IOCtrType);
/* channel6 cbk*/
Std_ReturnType IOCtr_435F_Cbk(uint8 IOCtrType);
/* channel7 cbk*/
Std_ReturnType IOCtr_4360_Cbk(uint8 IOCtrType);
/* channel8 cbk*/
Std_ReturnType IOCtr_4361_Cbk(uint8 IOCtrType);
/* channel9 cbk*/
Std_ReturnType IOCtr_4362_Cbk(uint8 IOCtrType);
/* channel10 cbk*/
Std_ReturnType IOCtr_4363_Cbk(uint8 IOCtrType);
/* channel11 cbk*/
Std_ReturnType IOCtr_4364_Cbk(uint8 IOCtrType);
/* channel12 cbk*/
Std_ReturnType IOCtr_4367_Cbk(uint8 IOCtrType);
/* 4365 CallBack */
Std_ReturnType IOCtr_4365_Cbk(uint8 IOCtrTypeState);
/* 4366 CallBack */
Std_ReturnType IOCtr_4366_Cbk(uint8 IOCtrTypeState);
/* 43A9 CallBack */
Std_ReturnType IOCtr_43A9_Cbk(uint8 IOCtrTypeState);
/*远近光84像素2F控制*/
Std_ReturnType IOCtr_7022_Cbk(uint8 IOCtrType);

/*
 *  获得通道2F服务的状态
 */
uint8 GetChannelIOCtrSts(E_ChannelID id);
/*
 *  获得远近光像素点的2F服务的状态
 */
uint8 GetLBHBPixelIOCtrSts(E_ChannelID id);