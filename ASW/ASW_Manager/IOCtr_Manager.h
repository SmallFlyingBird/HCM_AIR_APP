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
#include "DidConfig.h"
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
Std_ReturnType IOCtr_434B_Cbk(E_IOCtrType IOCtrTypeState);
/* 4358 CallBack */
Std_ReturnType IOCtr_4358_Cbk(E_IOCtrType IOCtrTypeState);
/* channel1 cbk*/
Std_ReturnType IOCtr_4359_Cbk(E_IOCtrType IOCtrType);
/* channel2 cbk*/
Std_ReturnType IOCtr_435B_Cbk(E_IOCtrType IOCtrType);
/* channel3 cbk*/
Std_ReturnType IOCtr_435C_Cbk(E_IOCtrType IOCtrType);
/* channel4 cbk*/
Std_ReturnType IOCtr_435D_Cbk(E_IOCtrType IOCtrType);
/* channel5 cbk*/
Std_ReturnType IOCtr_435E_Cbk(E_IOCtrType IOCtrType);
/* channel6 cbk*/
Std_ReturnType IOCtr_435F_Cbk(E_IOCtrType IOCtrType);
/* channel7 cbk*/
Std_ReturnType IOCtr_4360_Cbk(E_IOCtrType IOCtrType);
/* channel8 cbk*/
Std_ReturnType IOCtr_4361_Cbk(E_IOCtrType IOCtrType);
/* channel9 cbk*/
Std_ReturnType IOCtr_4362_Cbk(E_IOCtrType IOCtrType);
/* channel10 cbk*/
Std_ReturnType IOCtr_4363_Cbk(E_IOCtrType IOCtrType);
/* channel11 cbk*/
Std_ReturnType IOCtr_4364_Cbk(E_IOCtrType IOCtrType);
/* channel12 cbk*/
Std_ReturnType IOCtr_4367_Cbk(E_IOCtrType IOCtrType);
/* 4365 CallBack */
Std_ReturnType IOCtr_4365_Cbk(E_IOCtrType IOCtrTypeState);
/* 4366 CallBack */
Std_ReturnType IOCtr_4366_Cbk(E_IOCtrType IOCtrTypeState);
/* 43A9 CallBack */
Std_ReturnType IOCtr_43A9_Cbk(E_IOCtrType IOCtrTypeState);
/*远近光84像素2F控制*/
Std_ReturnType IOCtr_7022_Cbk(E_IOCtrType IOCtrType);

/*
 *  获得通道2F服务的状态
 */
E_IOCtrType GetChannelIOCtrSts(E_ChannelID id);
/*
 *  获得远近光像素点的2F服务的状态
 */
E_IOCtrType GetLBHBPixelIOCtrSts(E_ChannelID id);