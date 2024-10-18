/*
 * DidConfig.c
 *
 *  Created on: 2024��1��15��
 *      Author: mihuiliang
 */

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "DidConfig.h"
#include "DID_Interface.h"
#include "Rte_Dcm.h"
#include "NvM_Cfg.h"
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

S_IoCtrInfo g_S_IoCtrInfo[DidIoCtr_NUM]={
		/*0*/
		{.CurIoCtrState=E_IOCtrType_ReturnControl,.IoCtrlMaskSupport=E_IoCtrlMaskSupport_MaskAtEndByte,.DidIOCtrlDataSrc=Buffer_DcmDspData_0x434B_OptionRecord,.IoCtrCallBack=Interface_DID434B_IoCtrCallback},
		/*1*/
		{.CurIoCtrState=E_IOCtrType_ReturnControl,.IoCtrlMaskSupport=E_IoCtrlMaskSupport_MaskAtEndByte,.DidIOCtrlDataSrc=Buffer_DcmDspData_0x4358_OptionRecord,.IoCtrCallBack=Interface_DID4358_IoCtrCallback},
		/*2*/
		{.CurIoCtrState=E_IOCtrType_ReturnControl,.IoCtrlMaskSupport=E_IoCtrlMaskSupport_MaskAtEndByte,.DidIOCtrlDataSrc=Buffer_DcmDspData_0x4359_OptionRecord,.IoCtrCallBack=Interface_DID4359_IoCtrCallback},
		/*3*/
		{.CurIoCtrState=E_IOCtrType_ReturnControl,.IoCtrlMaskSupport=E_IoCtrlMaskSupport_MaskAtEndByte,.DidIOCtrlDataSrc=Buffer_DcmDspData_0x435B_OptionRecord,.IoCtrCallBack=Interface_DID435B_IoCtrCallback},
		/*4*/
		{.CurIoCtrState=E_IOCtrType_ReturnControl,.IoCtrlMaskSupport=E_IoCtrlMaskSupport_MaskAtEndByte,.DidIOCtrlDataSrc=Buffer_DcmDspData_0x435C_OptionRecord,.IoCtrCallBack=Interface_DID435C_IoCtrCallback},
		/*5*/
		{.CurIoCtrState=E_IOCtrType_ReturnControl,.IoCtrlMaskSupport=E_IoCtrlMaskSupport_MaskAtEndByte,.DidIOCtrlDataSrc=Buffer_DcmDspData_0x435D_OptionRecord,.IoCtrCallBack=Interface_DID435D_IoCtrCallback},
		/*6*/
		{.CurIoCtrState=E_IOCtrType_ReturnControl,.IoCtrlMaskSupport=E_IoCtrlMaskSupport_MaskAtEndByte,.DidIOCtrlDataSrc=Buffer_DcmDspData_0x435E_OptionRecord,.IoCtrCallBack=Interface_DID435E_IoCtrCallback},
		/*7*/
		{.CurIoCtrState=E_IOCtrType_ReturnControl,.IoCtrlMaskSupport=E_IoCtrlMaskSupport_MaskAtEndByte,.DidIOCtrlDataSrc=Buffer_DcmDspData_0x435F_OptionRecord,.IoCtrCallBack=Interface_DID435F_IoCtrCallback},
		/*8*/
		{.CurIoCtrState=E_IOCtrType_ReturnControl,.IoCtrlMaskSupport=E_IoCtrlMaskSupport_MaskAtEndByte,.DidIOCtrlDataSrc=Buffer_DcmDspData_0x4360_OptionRecord,.IoCtrCallBack=Interface_DID4360_IoCtrCallback},
		/*9*/
		{.CurIoCtrState=E_IOCtrType_ReturnControl,.IoCtrlMaskSupport=E_IoCtrlMaskSupport_MaskAtEndByte,.DidIOCtrlDataSrc=Buffer_DcmDspData_0x4361_OptionRecord,.IoCtrCallBack=Interface_DID4361_IoCtrCallback},
		/*10*/
		{.CurIoCtrState=E_IOCtrType_ReturnControl,.IoCtrlMaskSupport=E_IoCtrlMaskSupport_MaskAtEndByte,.DidIOCtrlDataSrc=Buffer_DcmDspData_0x4362_OptionRecord,.IoCtrCallBack=Interface_DID4362_IoCtrCallback},
		/*11*/
		{.CurIoCtrState=E_IOCtrType_ReturnControl,.IoCtrlMaskSupport=E_IoCtrlMaskSupport_MaskAtEndByte,.DidIOCtrlDataSrc=Buffer_DcmDspData_0x4363_OptionRecord,.IoCtrCallBack=Interface_DID4363_IoCtrCallback},
		/*12*/
		{.CurIoCtrState=E_IOCtrType_ReturnControl,.IoCtrlMaskSupport=E_IoCtrlMaskSupport_MaskAtEndByte,.DidIOCtrlDataSrc=Buffer_DcmDspData_0x4364_OptionRecord,.IoCtrCallBack=Interface_DID4364_IoCtrCallback},
		/*13*/
		{.CurIoCtrState=E_IOCtrType_ReturnControl,.IoCtrlMaskSupport=E_IoCtrlMaskSupport_MaskAtEndByte,.DidIOCtrlDataSrc=Buffer_DcmDspData_0x4367_OptionRecord,.IoCtrCallBack=Interface_DID4367_IoCtrCallback},
		/*14*/
		{.CurIoCtrState=E_IOCtrType_ReturnControl,.IoCtrlMaskSupport=E_IoCtrlMaskSupport_MaskAtEndByte,.DidIOCtrlDataSrc=Buffer_DcmDspData_0x4365_OptionRecord,.IoCtrCallBack=Interface_DID4365_IoCtrCallback},
		/*15*/
		{.CurIoCtrState=E_IOCtrType_ReturnControl,.IoCtrlMaskSupport=E_IoCtrlMaskSupport_MaskAtEndByte,.DidIOCtrlDataSrc=Buffer_DcmDspData_0x4366_OptionRecord,.IoCtrCallBack=Interface_DID4366_IoCtrCallback},
		/*16*/
		{.CurIoCtrState=E_IOCtrType_ReturnControl,.IoCtrlMaskSupport=E_IoCtrlMaskSupport_MaskAtEndByte,.DidIOCtrlDataSrc=Buffer_DcmDspData_0x43A9_OptionRecord,.IoCtrCallBack=Interface_DID43A9_IoCtrCallback},
		/*17*/
		{.CurIoCtrState=E_IOCtrType_ReturnControl,.IoCtrlMaskSupport=E_IoCtrlMaskSupport_NoMask,.DidIOCtrlDataSrc=Buffer_DcmDspData_0x7022_OptionRecord,.IoCtrCallBack=Interface_DID7022_IoCtrCallback},
};
/*
 * DidPermissions
 * BIT0 0X22   1
 * BIT1 0X2E   2
 * BIT2 0X2F   4
 * */
const S_DidConfig	g_S_DidConfig[DidConfig_NUM]={
		/*0:434B*/
		{.DidDataLength=4,.DidPermissions=0x05,.DidDataSrc=Buffer_DcmDspData_0x434B,.IoCtrInfo=&g_S_IoCtrInfo[0],.Init=NULL},
		/*1:4351*/
		{.DidDataLength=1,.DidPermissions=0x01,.DidDataSrc=Buffer_DcmDspData_0x4351,.IoCtrInfo=NULL,.Init=NULL},
		/*2:4357*/
		{.DidDataLength=2,.DidPermissions=0x01,.DidDataSrc=Buffer_DcmDspData_0x4357,.IoCtrInfo=NULL,.Init=NULL},
		/*3:4358*/
		{.DidDataLength=3,.DidPermissions=0x05,.DidDataSrc=Buffer_DcmDspData_0x4358,.IoCtrInfo=&g_S_IoCtrInfo[1],.Init=NULL},
		/*4:4359*/
		{.DidDataLength=11,.DidPermissions=0x05,.DidDataSrc=Buffer_DcmDspData_0x4359,.IoCtrInfo=&g_S_IoCtrInfo[2],.Init=NULL},
		/*5:435B*/
		{.DidDataLength=11,.DidPermissions=0x05,.DidDataSrc=Buffer_DcmDspData_0x435B,.IoCtrInfo=&g_S_IoCtrInfo[3],.Init=NULL},
		/*6:435C*/
		{.DidDataLength=11,.DidPermissions=0x05,.DidDataSrc=Buffer_DcmDspData_0x435C,.IoCtrInfo=&g_S_IoCtrInfo[4],.Init=NULL},
		/*7:435D*/
		{.DidDataLength=11,.DidPermissions=0x05,.DidDataSrc=Buffer_DcmDspData_0x435D,.IoCtrInfo=&g_S_IoCtrInfo[5],.Init=NULL},
		/*8:435E*/
		{.DidDataLength=11,.DidPermissions=0x05,.DidDataSrc=Buffer_DcmDspData_0x435E,.IoCtrInfo=&g_S_IoCtrInfo[6],.Init=NULL},
		/*9:435F*/
		{.DidDataLength=11,.DidPermissions=0x05,.DidDataSrc=Buffer_DcmDspData_0x435F,.IoCtrInfo=&g_S_IoCtrInfo[7],.Init=NULL},
		/*10:4360*/
		{.DidDataLength=11,.DidPermissions=0x05,.DidDataSrc=Buffer_DcmDspData_0x4360,.IoCtrInfo=&g_S_IoCtrInfo[8],.Init=NULL},
		/*11:4361*/
		{.DidDataLength=11,.DidPermissions=0x05,.DidDataSrc=Buffer_DcmDspData_0x4361,.IoCtrInfo=&g_S_IoCtrInfo[9],.Init=NULL},
		/*12:4362*/
		{.DidDataLength=11,.DidPermissions=0x05,.DidDataSrc=Buffer_DcmDspData_0x4362,.IoCtrInfo=&g_S_IoCtrInfo[10],.Init=NULL},
		/*13:4363*/
		{.DidDataLength=11,.DidPermissions=0x05,.DidDataSrc=Buffer_DcmDspData_0x4363,.IoCtrInfo=&g_S_IoCtrInfo[11],.Init=NULL},
		/*14:4364*/
		{.DidDataLength=11,.DidPermissions=0x05,.DidDataSrc=Buffer_DcmDspData_0x4364,.IoCtrInfo=&g_S_IoCtrInfo[12],.Init=NULL},
		/*15:4367*/
		{.DidDataLength=11,.DidPermissions=0x05,.DidDataSrc=Buffer_DcmDspData_0x4367,.IoCtrInfo=&g_S_IoCtrInfo[13],.Init=NULL},
		/*16:4365*/
		{.DidDataLength=2,.DidPermissions=0x05,.DidDataSrc=Buffer_DcmDspData_0x4365,.IoCtrInfo=&g_S_IoCtrInfo[14],.Init=NULL},
		/*17:4366*/
		{.DidDataLength=2,.DidPermissions=0x05,.DidDataSrc=Buffer_DcmDspData_0x4366,.IoCtrInfo=&g_S_IoCtrInfo[15],.Init=NULL},
		/*18:4368*/
		{.DidDataLength=4,.DidPermissions=0x01,.DidDataSrc=Buffer_DcmDspData_0x4368,.IoCtrInfo=NULL,.Init=NULL},
		/*19:437C*/
		{.DidDataLength=24,.DidPermissions=0x03,.DidDataSrc=Buffer_DcmDspData_0x437C,.IoCtrInfo=NULL,.Init=Rte_Call_Dcm_CSDataServices_DcmDspData_0x437C_ReadData},
		/*20:43A8*/
		{.DidDataLength=100,.DidPermissions=0x03,.DidDataSrc=NvMBlockRamBuffer2,.IoCtrInfo=NULL,.Init=Rte_Call_Dcm_CSDataServices_DcmDspData_0x43A8_ReadData},
		/*21:43A9*/
		{.DidDataLength=3,.DidPermissions=0x05,.DidDataSrc=Buffer_DcmDspData_0x43A9,.IoCtrInfo=&g_S_IoCtrInfo[16],.Init=NULL},
		/*22:43CA*/
		{.DidDataLength=3,.DidPermissions=0x01,.DidDataSrc=Buffer_DcmDspData_0x43CA,.IoCtrInfo=NULL,.Init=NULL},
		/*23:43CE*/
		{.DidDataLength=1,.DidPermissions=0x01,.DidDataSrc=Buffer_DcmDspData_0x43CE,.IoCtrInfo=NULL,.Init=NULL},
		/*24:43CF*/
		{.DidDataLength=1,.DidPermissions=0x01,.DidDataSrc=Buffer_DcmDspData_0x43CF,.IoCtrInfo=NULL,.Init=NULL},
		/*25:43D0*/
		{.DidDataLength=1,.DidPermissions=0x01,.DidDataSrc=Buffer_DcmDspData_0x43D0,.IoCtrInfo=NULL,.Init=NULL},
		/*26:43D1*/
		{.DidDataLength=1,.DidPermissions=0x01,.DidDataSrc=Buffer_DcmDspData_0x43D1,.IoCtrInfo=NULL,.Init=NULL},
		/*27:43D2*/
		{.DidDataLength=1,.DidPermissions=0x01,.DidDataSrc=Buffer_DcmDspData_0x43D2,.IoCtrInfo=NULL,.Init=NULL},
		/*28:43D3*/
		{.DidDataLength=1,.DidPermissions=0x01,.DidDataSrc=Buffer_DcmDspData_0x43D3,.IoCtrInfo=NULL,.Init=NULL},
		/*29:43D4*/
		{.DidDataLength=1,.DidPermissions=0x01,.DidDataSrc=Buffer_DcmDspData_0x43D4,.IoCtrInfo=NULL,.Init=NULL},
		/*30:43D5*/
		{.DidDataLength=1,.DidPermissions=0x01,.DidDataSrc=Buffer_DcmDspData_0x43D5,.IoCtrInfo=NULL,.Init=NULL},
		/*31:43D7*/
		{.DidDataLength=2,.DidPermissions=0x01,.DidDataSrc=Buffer_DcmDspData_0x43D7,.IoCtrInfo=NULL,.Init=NULL},
		/*32:43D8*/
		{.DidDataLength=1,.DidPermissions=0x01,.DidDataSrc=Buffer_DcmDspData_0x43D8,.IoCtrInfo=NULL,.Init=NULL},
		/*33:43D9*/
		{.DidDataLength=1,.DidPermissions=0x01,.DidDataSrc=Buffer_DcmDspData_0x43D9,.IoCtrInfo=NULL,.Init=NULL},
		/*34:43DA*/
		{.DidDataLength=2,.DidPermissions=0x01,.DidDataSrc=Buffer_DcmDspData_0x43DA,.IoCtrInfo=NULL,.Init=NULL},
		/*35:7022*/
		{.DidDataLength=84,.DidPermissions=0x05,.DidDataSrc=Buffer_DcmDspData_0x7022,.IoCtrInfo=&g_S_IoCtrInfo[17],.Init=NULL},
		/*36:D134*/
		{.DidDataLength=1,.DidPermissions=0x01,.DidDataSrc=Buffer_DcmDspData_0xD134,.IoCtrInfo=NULL,.Init=NULL},
		/*37:DD00*/
		{.DidDataLength=4,.DidPermissions=0x01,.DidDataSrc=Buffer_DcmDspData_0xDD00,.IoCtrInfo=NULL,.Init=NULL},
		/*38:DD01*/
		{.DidDataLength=3,.DidPermissions=0x01,.DidDataSrc=Buffer_DcmDspData_0xDD01,.IoCtrInfo=NULL,.Init=NULL},
		/*39:DD02*/
		{.DidDataLength=1,.DidPermissions=0x01,.DidDataSrc=Buffer_DcmDspData_0xDD02,.IoCtrInfo=NULL,.Init=NULL},
		/*40:DD0A*/
		{.DidDataLength=1,.DidPermissions=0x01,.DidDataSrc=Buffer_DcmDspData_0xDD0A,.IoCtrInfo=NULL,.Init=NULL},
		/*41:DD0C*/
		{.DidDataLength=1,.DidPermissions=0x01,.DidDataSrc=Buffer_DcmDspData_0xDD0C,.IoCtrInfo=NULL,.Init=NULL},
		/*42:DD07*/
		{.DidDataLength=6,.DidPermissions=0x01,.DidDataSrc=Buffer_DcmDspData_0xDD07,.IoCtrInfo=NULL,.Init=NULL},
#if (VEHICLE_PLATFORM == VEHICLE_GEELY_FX11)
		/*43:DD06*/
		{.DidDataLength=2,.DidPermissions=0x01,.DidDataSrc=Buffer_DcmDspData_0xDD06,.IoCtrInfo=NULL,.Init=NULL},
#endif
};

const S_DidSignal	g_S_DidSignal[DidSignal_NUM]={
		/*************************************************434B*******************************************************************/
		/*0:DIDSIGNALNAME_ID_Fan1Diagnosis 			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=4,.SignalRunTimeBufferID=0,.DidSignalLSBBits=4,.BelongToDidIndex=0},/*uint8*/
		/*1:DIDSIGNALNAME_ID_FAN2Control				*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=4,.SignalRunTimeBufferID=1,.DidSignalLSBBits=0,.BelongToDidIndex=0},/*uint8*/
		/*2:DIDSIGNALNAME_ID_Fan1supply				*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=4,.SignalRunTimeBufferID=2,.DidSignalLSBBits=12,.BelongToDidIndex=0},/*uint8*/
		/*3:DIDSIGNALNAME_ID_Fan1OutputControl		*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=3,.DidSignalLSBBits=20,.BelongToDidIndex=0},/*uint8*/
		/*4:DIDSIGNALNAME_ID_Fan1CurrentFeedback		*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=0,.DidSignalLSBBits=24,.BelongToDidIndex=0},/*uint16*/

		/*************************************************4351*******************************************************************/
		/*5:DIDSIGNALNAME_ID_Temperature 			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=4,.DidSignalLSBBits=0,.BelongToDidIndex=1},/*uint8*/

		/*************************************************4357*******************************************************************/
		/*6:DIDSIGNALNAME_ID_IgnitionRelay			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=5,.DidSignalLSBBits=0,.BelongToDidIndex=2},/*uint8*/
		/*7:DIDSIGNALNAME_ID_ExteriorLightRelay			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=6,.DidSignalLSBBits=8,.BelongToDidIndex=2},/*uint8*/

		/*************************************************4358*******************************************************************/
		/*8:DIDSIGNALNAME_ID_SMLOutputStatus			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=7,.DidSignalLSBBits=0,.BelongToDidIndex=3},/*uint8*/
		/*9:DIDSIGNALNAME_ID_SMLCurFB			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=16,.SignalRunTimeBufferID=1,.DidSignalLSBBits=16,.BelongToDidIndex=3},/*uint16*/

		/*************************************************4359*******************************************************************/
		/*10:DIDSIGNALNAME_ID_CH1OutputLuminosity			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=8,.DidSignalLSBBits=0,.BelongToDidIndex=4},/*uint8*/
		/*11:DIDSIGNALNAME_ID_CH1Current			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=2,.DidSignalLSBBits=20,.BelongToDidIndex=4},/*uint16*/
		/*12:DIDSIGNALNAME_ID_CH1ActualVol			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=16,.SignalRunTimeBufferID=3,.DidSignalLSBBits=36,.BelongToDidIndex=4},/*uint16*/
		/*13:DIDSIGNALNAME_ID_CH1ActualFreq			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=16,.SignalRunTimeBufferID=4,.DidSignalLSBBits=52,.BelongToDidIndex=4},/*uint16*/
		/*14:DIDSIGNALNAME_ID_CH1Function			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=28,.SignalRunTimeBufferID=0,.DidSignalLSBBits=72,.BelongToDidIndex=4},/*uint32*/
		/*15:DIDSIGNALNAME_ID_CH1ThermResTemp			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=9,.DidSignalLSBBits=80,.BelongToDidIndex=4},/*uint8*/

		/*************************************************435B*******************************************************************/
		/*16:DIDSIGNALNAME_ID_CH2OutputLuminosity			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=10,.DidSignalLSBBits=0,.BelongToDidIndex=5},/*uint8*/
		/*17:DIDSIGNALNAME_ID_CH2Current			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=5,.DidSignalLSBBits=20,.BelongToDidIndex=5},/*uint16*/
		/*18:DIDSIGNALNAME_ID_CH2ActualVol			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=16,.SignalRunTimeBufferID=6,.DidSignalLSBBits=36,.BelongToDidIndex=5},/*uint16*/
		/*19:DIDSIGNALNAME_ID_CH2ActualFreq			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=16,.SignalRunTimeBufferID=7,.DidSignalLSBBits=52,.BelongToDidIndex=5},/*uint16*/
		/*20:DIDSIGNALNAME_ID_CH2Function			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=28,.SignalRunTimeBufferID=1,.DidSignalLSBBits=72,.BelongToDidIndex=5},/*uint32*/
		/*21:DIDSIGNALNAME_ID_CH2ThermResTemp			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=11,.DidSignalLSBBits=80,.BelongToDidIndex=5},/*uint8*/

		/*************************************************435C*******************************************************************/
		/*22:DIDSIGNALNAME_ID_CH3OutputLuminosity			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=12,.DidSignalLSBBits=0,.BelongToDidIndex=6},/*uint8*/
		/*23:DIDSIGNALNAME_ID_CH3Current			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=8,.DidSignalLSBBits=20,.BelongToDidIndex=6},/*uint16*/
		/*24:DIDSIGNALNAME_ID_CH3ActualVol			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=16,.SignalRunTimeBufferID=9,.DidSignalLSBBits=36,.BelongToDidIndex=6},/*uint16*/
		/*25:DIDSIGNALNAME_ID_CH3ActualFreq			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=16,.SignalRunTimeBufferID=10,.DidSignalLSBBits=52,.BelongToDidIndex=6},/*uint16*/
		/*26:DIDSIGNALNAME_ID_CH3Function			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=28,.SignalRunTimeBufferID=2,.DidSignalLSBBits=72,.BelongToDidIndex=6},/*uint32*/
		/*27:DIDSIGNALNAME_ID_CH3ThermResTemp			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=13,.DidSignalLSBBits=80,.BelongToDidIndex=6},/*uint8*/

		/*************************************************435D*******************************************************************/
		/*28:DIDSIGNALNAME_ID_CH4OutputLuminosity			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=14,.DidSignalLSBBits=0,.BelongToDidIndex=7},/*uint8*/
		/*29:DIDSIGNALNAME_ID_CH4Current			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=11,.DidSignalLSBBits=20,.BelongToDidIndex=7},/*uint16*/
		/*30:DIDSIGNALNAME_ID_CH4ActualVol			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=16,.SignalRunTimeBufferID=12,.DidSignalLSBBits=36,.BelongToDidIndex=7},/*uint16*/
		/*31:DIDSIGNALNAME_ID_CH4ActualFreq			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=16,.SignalRunTimeBufferID=13,.DidSignalLSBBits=52,.BelongToDidIndex=7},/*uint16*/
		/*32:DIDSIGNALNAME_ID_CH4Function			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=28,.SignalRunTimeBufferID=3,.DidSignalLSBBits=72,.BelongToDidIndex=7},/*uint32*/
		/*33:DIDSIGNALNAME_ID_CH4ThermResTemp			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=15,.DidSignalLSBBits=80,.BelongToDidIndex=7},/*uint8*/

		/*************************************************435E*******************************************************************/
		/*34:DIDSIGNALNAME_ID_CH5OutputLuminosity			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=16,.DidSignalLSBBits=0,.BelongToDidIndex=8},/*uint8*/
		/*35:DIDSIGNALNAME_ID_CH5Current			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=14,.DidSignalLSBBits=20,.BelongToDidIndex=8},/*uint16*/
		/*36:DIDSIGNALNAME_ID_CH5ActualVol			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=16,.SignalRunTimeBufferID=15,.DidSignalLSBBits=36,.BelongToDidIndex=8},/*uint16*/
		/*37:DIDSIGNALNAME_ID_CH5ActualFreq			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=16,.SignalRunTimeBufferID=16,.DidSignalLSBBits=52,.BelongToDidIndex=8},/*uint16*/
		/*38:DIDSIGNALNAME_ID_CH5Function			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=28,.SignalRunTimeBufferID=4,.DidSignalLSBBits=72,.BelongToDidIndex=8},/*uint32*/
		/*39:DIDSIGNALNAME_ID_CH5ThermResTemp			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=17,.DidSignalLSBBits=80,.BelongToDidIndex=8},/*uint8*/

		/*************************************************435F*******************************************************************/
		/*40:DIDSIGNALNAME_ID_CH6OutputLuminosity			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=18,.DidSignalLSBBits=0,.BelongToDidIndex=9},/*uint8*/
		/*41:DIDSIGNALNAME_ID_CH6Current			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=17,.DidSignalLSBBits=20,.BelongToDidIndex=9},/*uint16*/
		/*42:DIDSIGNALNAME_ID_CH6ActualVol			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=16,.SignalRunTimeBufferID=18,.DidSignalLSBBits=36,.BelongToDidIndex=9},/*uint16*/
		/*43:DIDSIGNALNAME_ID_CH6ActualFreq			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=16,.SignalRunTimeBufferID=19,.DidSignalLSBBits=52,.BelongToDidIndex=9},/*uint16*/
		/*44:DIDSIGNALNAME_ID_CH6Function			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=28,.SignalRunTimeBufferID=5,.DidSignalLSBBits=72,.BelongToDidIndex=9},/*uint32*/
		/*45:DIDSIGNALNAME_ID_CH6ThermResTemp			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=19,.DidSignalLSBBits=80,.BelongToDidIndex=9},/*uint8*/

		/*************************************************4360*******************************************************************/
		/*46:DIDSIGNALNAME_ID_CH7OutputLuminosity			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=20,.DidSignalLSBBits=0,.BelongToDidIndex=10},/*uint8*/
		/*47:DIDSIGNALNAME_ID_CH7Current			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=20,.DidSignalLSBBits=20,.BelongToDidIndex=10},/*uint16*/
		/*48:DIDSIGNALNAME_ID_CH7ActualVol			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=16,.SignalRunTimeBufferID=21,.DidSignalLSBBits=36,.BelongToDidIndex=10},/*uint16*/
		/*49:DIDSIGNALNAME_ID_CH7ActualFreq			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=16,.SignalRunTimeBufferID=22,.DidSignalLSBBits=52,.BelongToDidIndex=10},/*uint16*/
		/*50:DIDSIGNALNAME_ID_CH7Function			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=28,.SignalRunTimeBufferID=6,.DidSignalLSBBits=72,.BelongToDidIndex=10},/*uint32*/
		/*51:DIDSIGNALNAME_ID_CH7ThermResTemp			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=21,.DidSignalLSBBits=80,.BelongToDidIndex=10},/*uint8*/

		/*************************************************4361*******************************************************************/
		/*52:DIDSIGNALNAME_ID_CH8OutputLuminosity			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=22,.DidSignalLSBBits=0,.BelongToDidIndex=11},/*uint8*/
		/*53:DIDSIGNALNAME_ID_CH8Current			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=23,.DidSignalLSBBits=20,.BelongToDidIndex=11},/*uint16*/
		/*54:DIDSIGNALNAME_ID_CH8ActualVol			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=16,.SignalRunTimeBufferID=24,.DidSignalLSBBits=36,.BelongToDidIndex=11},/*uint16*/
		/*55:DIDSIGNALNAME_ID_CH8ActualFreq			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=16,.SignalRunTimeBufferID=25,.DidSignalLSBBits=52,.BelongToDidIndex=11},/*uint16*/
		/*56:DIDSIGNALNAME_ID_CH8Function			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=28,.SignalRunTimeBufferID=7,.DidSignalLSBBits=72,.BelongToDidIndex=11},/*uint32*/
		/*57:DIDSIGNALNAME_ID_CH8ThermResTemp			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=23,.DidSignalLSBBits=80,.BelongToDidIndex=11},/*uint8*/

		/*************************************************4362*******************************************************************/
		/*58:DIDSIGNALNAME_ID_CH9OutputLuminosity			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=24,.DidSignalLSBBits=0,.BelongToDidIndex=12},/*uint8*/
		/*59:DIDSIGNALNAME_ID_CH9Current			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=26,.DidSignalLSBBits=20,.BelongToDidIndex=12},/*uint16*/
		/*60:DIDSIGNALNAME_ID_CH9ActualVol			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=16,.SignalRunTimeBufferID=27,.DidSignalLSBBits=36,.BelongToDidIndex=12},/*uint16*/
		/*61:DIDSIGNALNAME_ID_CH9ActualFreq			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=16,.SignalRunTimeBufferID=28,.DidSignalLSBBits=52,.BelongToDidIndex=12},/*uint16*/
		/*62:DIDSIGNALNAME_ID_CH9Function			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=28,.SignalRunTimeBufferID=8,.DidSignalLSBBits=72,.BelongToDidIndex=12},/*uint32*/
		/*63:DIDSIGNALNAME_ID_CH9ThermResTemp			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=25,.DidSignalLSBBits=80,.BelongToDidIndex=12},/*uint8*/

		/*************************************************4363*******************************************************************/
		/*64:DIDSIGNALNAME_ID_CH10OutputLuminosity			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=26,.DidSignalLSBBits=0,.BelongToDidIndex=13},/*uint8*/
		/*65:DIDSIGNALNAME_ID_CH10Current			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=29,.DidSignalLSBBits=20,.BelongToDidIndex=13},/*uint16*/
		/*66:DIDSIGNALNAME_ID_CH10ActualVol			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=16,.SignalRunTimeBufferID=30,.DidSignalLSBBits=36,.BelongToDidIndex=13},/*uint16*/
		/*67:DIDSIGNALNAME_ID_CH10ActualFreq			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=16,.SignalRunTimeBufferID=31,.DidSignalLSBBits=52,.BelongToDidIndex=13},/*uint16*/
		/*68:DIDSIGNALNAME_ID_CH10Function			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=28,.SignalRunTimeBufferID=9,.DidSignalLSBBits=72,.BelongToDidIndex=13},/*uint32*/
		/*69:DIDSIGNALNAME_ID_CH10ThermResTemp			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=27,.DidSignalLSBBits=80,.BelongToDidIndex=13},/*uint8*/

		/*************************************************4364*******************************************************************/
		/*70:DIDSIGNALNAME_ID_CH11OutputLuminosity			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=28,.DidSignalLSBBits=0,.BelongToDidIndex=14},/*uint8*/
		/*71:DIDSIGNALNAME_ID_CH11Current			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=32,.DidSignalLSBBits=20,.BelongToDidIndex=14},/*uint16*/
		/*72:DIDSIGNALNAME_ID_CH11ActualVol			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=16,.SignalRunTimeBufferID=33,.DidSignalLSBBits=36,.BelongToDidIndex=14},/*uint16*/
		/*73:DIDSIGNALNAME_ID_CH11ActualFreq			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=16,.SignalRunTimeBufferID=34,.DidSignalLSBBits=52,.BelongToDidIndex=14},/*uint16*/
		/*74:DIDSIGNALNAME_ID_CH11Function			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=28,.SignalRunTimeBufferID=10,.DidSignalLSBBits=72,.BelongToDidIndex=14},/*uint32*/
		/*75:DIDSIGNALNAME_ID_CH11ThermResTemp			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=29,.DidSignalLSBBits=80,.BelongToDidIndex=14},/*uint8*/

		/*************************************************4367*******************************************************************/
		/*76:DIDSIGNALNAME_ID_CH12OutputLuminosity			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=30,.DidSignalLSBBits=0,.BelongToDidIndex=15},/*uint8*/
		/*77:DIDSIGNALNAME_ID_CH12Current			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=35,.DidSignalLSBBits=20,.BelongToDidIndex=15},/*uint16*/
		/*78:DIDSIGNALNAME_ID_CH12ActualVol			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=16,.SignalRunTimeBufferID=36,.DidSignalLSBBits=36,.BelongToDidIndex=15},/*uint16*/
		/*79:DIDSIGNALNAME_ID_CH12ActualFreq			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=16,.SignalRunTimeBufferID=37,.DidSignalLSBBits=52,.BelongToDidIndex=15},/*uint16*/
		/*80:DIDSIGNALNAME_ID_CH12Function			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=28,.SignalRunTimeBufferID=11,.DidSignalLSBBits=72,.BelongToDidIndex=15},/*uint32*/
		/*81:DIDSIGNALNAME_ID_CH12ThermResTemp			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=31,.DidSignalLSBBits=80,.BelongToDidIndex=15},/*uint8*/

		/*************************************************4365*******************************************************************/
		/*82:DIDSIGNALNAME_ID_LvlSlewingAngle			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=38,.DidSignalLSBBits=12,.BelongToDidIndex=16},/*uint16*/
		/*83:DIDSIGNALNAME_ID_LvlStsRefRun			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=4,.SignalRunTimeBufferID=32,.DidSignalLSBBits=8,.BelongToDidIndex=16},/*uint8*/

		/*************************************************4366*******************************************************************/
		/*84:DIDSIGNALNAME_ID_SwlSlewingAngle			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=39,.DidSignalLSBBits=12,.BelongToDidIndex=17},/*uint16*/
		/*85:DIDSIGNALNAME_ID_SwlStsRefRun			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=4,.SignalRunTimeBufferID=33,.DidSignalLSBBits=8,.BelongToDidIndex=17},/*uint8*/

		/*************************************************4368*******************************************************************/
		/*86:DIDSIGNALNAME_ID_StsOfHB			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=2,.SignalRunTimeBufferID=34,.DidSignalLSBBits=6,.BelongToDidIndex=18},/*uint8*/
		/*87:DIDSIGNALNAME_ID_StsOfLB			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=2,.SignalRunTimeBufferID=35,.DidSignalLSBBits=4,.BelongToDidIndex=18},/*uint8*/
		/*88:DIDSIGNALNAME_ID_StsOfTI			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=2,.SignalRunTimeBufferID=36,.DidSignalLSBBits=2,.BelongToDidIndex=18},/*uint8*/
		/*89:DIDSIGNALNAME_ID_StsOfPL			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=2,.SignalRunTimeBufferID=37,.DidSignalLSBBits=0,.BelongToDidIndex=18},/*uint8*/
		/*90:DIDSIGNALNAME_ID_StsOfDRL			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=2,.SignalRunTimeBufferID=38,.DidSignalLSBBits=14,.BelongToDidIndex=18},/*uint8*/
		/*91:DIDSIGNALNAME_ID_StsOfFog			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=2,.SignalRunTimeBufferID=39,.DidSignalLSBBits=12,.BelongToDidIndex=18},/*uint8*/
		/*92:DIDSIGNALNAME_ID_StsOfCorner			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=2,.SignalRunTimeBufferID=40,.DidSignalLSBBits=10,.BelongToDidIndex=18},/*uint8*/
		/*93:DIDSIGNALNAME_ID_StsOfSML			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=2,.SignalRunTimeBufferID=41,.DidSignalLSBBits=8,.BelongToDidIndex=18},/*uint8*/
		/*94:DIDSIGNALNAME_ID_StsOfDBL			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=2,.SignalRunTimeBufferID=42,.DidSignalLSBBits=22,.BelongToDidIndex=18},/*uint8*/
		/*95:DIDSIGNALNAME_ID_StsOfAHL			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=2,.SignalRunTimeBufferID=43,.DidSignalLSBBits=20,.BelongToDidIndex=18},/*uint8*/
		/*96:DIDSIGNALNAME_ID_StsOfAFS			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=2,.SignalRunTimeBufferID=44,.DidSignalLSBBits=18,.BelongToDidIndex=18},/*uint8*/
		/*97:DIDSIGNALNAME_ID_StsOfAHBC			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=2,.SignalRunTimeBufferID=45,.DidSignalLSBBits=16,.BelongToDidIndex=18},/*uint8*/
		/*98:DIDSIGNALNAME_ID_StsOftTourist			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=2,.SignalRunTimeBufferID=46,.DidSignalLSBBits=30,.BelongToDidIndex=18},/*uint8*/
		/*99:DIDSIGNALNAME_ID_StsOfLightShowAct			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=2,.SignalRunTimeBufferID=47,.DidSignalLSBBits=28,.BelongToDidIndex=18},/*uint8*/
		/*100:DIDSIGNALNAME_ID_StsOfLightShowDoload			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=2,.SignalRunTimeBufferID=48,.DidSignalLSBBits=26,.BelongToDidIndex=18},/*uint8*/

		/*************************************************437C*******************************************************************/
		/*101:DIDSIGNALNAME_ID_Ch1MaxCur			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=40,.DidSignalLSBBits=12,.BelongToDidIndex=19},/*uint16*/
		/*102:DIDSIGNALNAME_ID_Ch2MaxCur			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=41,.DidSignalLSBBits=16,.BelongToDidIndex=19},/*uint16*/
		/*103:DIDSIGNALNAME_ID_Ch3MaxCur			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=42,.DidSignalLSBBits=36,.BelongToDidIndex=19},/*uint16*/
		/*104:DIDSIGNALNAME_ID_Ch4MaxCur			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=43,.DidSignalLSBBits=40,.BelongToDidIndex=19},/*uint16*/
		/*105:DIDSIGNALNAME_ID_Ch5MaxCur			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=44,.DidSignalLSBBits=60,.BelongToDidIndex=19},/*uint16*/
		/*106:DIDSIGNALNAME_ID_Ch6MaxCur			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=45,.DidSignalLSBBits=64,.BelongToDidIndex=19},/*uint16*/
		/*107:DIDSIGNALNAME_ID_Ch7MaxCur			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=46,.DidSignalLSBBits=84,.BelongToDidIndex=19},/*uint16*/
		/*108:DIDSIGNALNAME_ID_Ch8MaxCur			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=47,.DidSignalLSBBits=88,.BelongToDidIndex=19},/*uint16*/
		/*109:DIDSIGNALNAME_ID_SideOfVehicle			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=49,.DidSignalLSBBits=96,.BelongToDidIndex=19},/*uint8*/
		/*110:DIDSIGNALNAME_ID_ProDateSecond			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=6,.SignalRunTimeBufferID=50,.DidSignalLSBBits=106,.BelongToDidIndex=19},/*uint8*/
		/*111:DIDSIGNALNAME_ID_ProDateMinute			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=6,.SignalRunTimeBufferID=51,.DidSignalLSBBits=116,.BelongToDidIndex=19},/*uint8*/
		/*112:DIDSIGNALNAME_ID_ProDateHour			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=5,.SignalRunTimeBufferID=52,.DidSignalLSBBits=127,.BelongToDidIndex=19},/*uint8*/
		/*113:DIDSIGNALNAME_ID_ProDateDay			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=5,.SignalRunTimeBufferID=53,.DidSignalLSBBits=122,.BelongToDidIndex=19},/*uint8*/
		/*114:DIDSIGNALNAME_ID_ProDateMonth			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=4,.SignalRunTimeBufferID=54,.DidSignalLSBBits=134,.BelongToDidIndex=19},/*uint8*/
		/*115:DIDSIGNALNAME_ID_ProDateYear			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=7,.SignalRunTimeBufferID=55,.DidSignalLSBBits=143,.BelongToDidIndex=19},/*uint8*/
		/*116:DIDSIGNALNAME_ID_ProDateReserved			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=7,.SignalRunTimeBufferID=56,.DidSignalLSBBits=136,.BelongToDidIndex=19},/*uint8*/
		/*117:DIDSIGNALNAME_ID_Ch9MaxCur			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=48,.DidSignalLSBBits=156,.BelongToDidIndex=19},/*uint16*/
		/*118:DIDSIGNALNAME_ID_Ch10MaxCur			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=49,.DidSignalLSBBits=160,.BelongToDidIndex=19},/*uint16*/
		/*119:DIDSIGNALNAME_ID_Ch11MaxCur			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=50,.DidSignalLSBBits=180,.BelongToDidIndex=19},/*uint16*/
		/*120:DIDSIGNALNAME_ID_Ch12MaxCur			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=51,.DidSignalLSBBits=184,.BelongToDidIndex=19},/*uint16*/

		/*************************************************43A8*******************************************************************/
		/*121:DIDSIGNALNAME_ID_PeakCurCh1			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=52,.DidSignalLSBBits=12,.BelongToDidIndex=20},/*uint16*/
		/*122:DIDSIGNALNAME_ID_TotalRunTimeCh1			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=32,.SignalRunTimeBufferID=12,.DidSignalLSBBits=44,.BelongToDidIndex=20},/*uint32*/
		/*123:DIDSIGNALNAME_ID_PeakCurCh2			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=53,.DidSignalLSBBits=48,.BelongToDidIndex=20},/*uint16*/
		/*124:DIDSIGNALNAME_ID_TotalRunTimeCh2			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=32,.SignalRunTimeBufferID=13,.DidSignalLSBBits=80,.BelongToDidIndex=20},/*uint32*/
		/*125:DIDSIGNALNAME_ID_PeakCurCh3			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=54,.DidSignalLSBBits=100,.BelongToDidIndex=20},/*uint16*/
		/*126:DIDSIGNALNAME_ID_TotalRunTimeCh3			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=32,.SignalRunTimeBufferID=14,.DidSignalLSBBits=132,.BelongToDidIndex=20},/*uint32*/
		/*127:DIDSIGNALNAME_ID_PeakCurCh4			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=55,.DidSignalLSBBits=136,.BelongToDidIndex=20},/*uint16*/
		/*128:DIDSIGNALNAME_ID_TotalRunTimeCh4			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=32,.SignalRunTimeBufferID=15,.DidSignalLSBBits=168,.BelongToDidIndex=20},/*uint32*/
		/*129:DIDSIGNALNAME_ID_PeakCurCh5			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=56,.DidSignalLSBBits=188,.BelongToDidIndex=20},/*uint16*/
		/*130:DIDSIGNALNAME_ID_TotalRunTimeCh5			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=32,.SignalRunTimeBufferID=16,.DidSignalLSBBits=220,.BelongToDidIndex=20},/*uint32*/
		/*131:DIDSIGNALNAME_ID_PeakCurCh6			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=57,.DidSignalLSBBits=224,.BelongToDidIndex=20},/*uint16*/
		/*132:DIDSIGNALNAME_ID_TotalRunTimeCh6			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=32,.SignalRunTimeBufferID=17,.DidSignalLSBBits=256,.BelongToDidIndex=20},/*uint32*/
		/*133:DIDSIGNALNAME_ID_PeakCurCh7			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=58,.DidSignalLSBBits=276,.BelongToDidIndex=20},/*uint16*/
		/*134:DIDSIGNALNAME_ID_TotalRunTimeCh7			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=32,.SignalRunTimeBufferID=18,.DidSignalLSBBits=308,.BelongToDidIndex=20},/*uint32*/
		/*135:DIDSIGNALNAME_ID_PeakCurCh8			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=59,.DidSignalLSBBits=312,.BelongToDidIndex=20},/*uint16*/
		/*136:DIDSIGNALNAME_ID_TotalRunTimeCh8			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=32,.SignalRunTimeBufferID=19,.DidSignalLSBBits=344,.BelongToDidIndex=20},/*uint32*/
		/*137:DIDSIGNALNAME_ID_PeakTempRes1			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=57,.DidSignalLSBBits=352,.BelongToDidIndex=20},/*uint8*/
		/*138:DIDSIGNALNAME_ID_PeakTempRes2			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=58,.DidSignalLSBBits=360,.BelongToDidIndex=20},/*uint8*/
		/*139:DIDSIGNALNAME_ID_PeakTempRes3			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=59,.DidSignalLSBBits=368,.BelongToDidIndex=20},/*uint8*/
		/*140:DIDSIGNALNAME_ID_PeakTempRes4			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=60,.DidSignalLSBBits=376,.BelongToDidIndex=20},/*uint8*/
		/*141:DIDSIGNALNAME_ID_PeakTempRes5			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=61,.DidSignalLSBBits=384,.BelongToDidIndex=20},/*uint8*/
		/*142:DIDSIGNALNAME_ID_PeakTempCtrMod			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=62,.DidSignalLSBBits=392,.BelongToDidIndex=20},/*uint8*/
		/*143:DIDSIGNALNAME_ID_TotalNumLedDera			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=32,.SignalRunTimeBufferID=20,.DidSignalLSBBits=424,.BelongToDidIndex=20},/*uint32*/
		/*144:DIDSIGNALNAME_ID_TotalNumFanStart			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=32,.SignalRunTimeBufferID=21,.DidSignalLSBBits=456,.BelongToDidIndex=20},/*uint32*/
		/*145:DIDSIGNALNAME_ID_TotalNumFanStartDeic			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=32,.SignalRunTimeBufferID=22,.DidSignalLSBBits=488,.BelongToDidIndex=20},/*uint32*/
		/*146:DIDSIGNALNAME_ID_TotalNumFanStartDefog			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=32,.SignalRunTimeBufferID=23,.DidSignalLSBBits=520,.BelongToDidIndex=20},/*uint32*/
		/*147:DIDSIGNALNAME_ID_TotalRunTimeFan			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=32,.SignalRunTimeBufferID=24,.DidSignalLSBBits=552,.BelongToDidIndex=20},/*uint32*/
		/*148:DIDSIGNALNAME_ID_TotalNumLvlStep			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=32,.SignalRunTimeBufferID=25,.DidSignalLSBBits=584,.BelongToDidIndex=20},/*uint32*/
		/*149:DIDSIGNALNAME_ID_TotalNumSwlStep			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=32,.SignalRunTimeBufferID=26,.DidSignalLSBBits=624,.BelongToDidIndex=20},/*uint32*/
		/*150:DIDSIGNALNAME_ID_PeakCurCh9			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=60,.DidSignalLSBBits=644,.BelongToDidIndex=20},/*uint16*/
		/*151:DIDSIGNALNAME_ID_TotalRunTimeCh9			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=32,.SignalRunTimeBufferID=27,.DidSignalLSBBits=676,.BelongToDidIndex=20},/*uint32*/
		/*152:DIDSIGNALNAME_ID_PeakCurCh10			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=61,.DidSignalLSBBits=680,.BelongToDidIndex=20},/*uint16*/
		/*153:DIDSIGNALNAME_ID_TotalRunTimeCh10			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=32,.SignalRunTimeBufferID=28,.DidSignalLSBBits=712,.BelongToDidIndex=20},/*uint32*/
		/*154:DIDSIGNALNAME_ID_PeakCurCh11			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=62,.DidSignalLSBBits=732,.BelongToDidIndex=20},/*uint16*/
		/*155:DIDSIGNALNAME_ID_TotalRunTimeCh11			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=32,.SignalRunTimeBufferID=29,.DidSignalLSBBits=764,.BelongToDidIndex=20},/*uint32*/
		/*156:DIDSIGNALNAME_ID_PeakCurCh12			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=12,.SignalRunTimeBufferID=63,.DidSignalLSBBits=768,.BelongToDidIndex=20},/*uint16*/
		/*157:DIDSIGNALNAME_ID_TotalRunTimeCh12			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=32,.SignalRunTimeBufferID=30,.DidSignalLSBBits=800,.BelongToDidIndex=20},/*uint32*/

		/*************************************************43A9*******************************************************************/
		/*158:DIDSIGNALNAME_ID_SeqIndcSts			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=63,.DidSignalLSBBits=0,.BelongToDidIndex=21},/*uint8*/
		/*159:DIDSIGNALNAME_ID_SeqCurFeedBack			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=16,.SignalRunTimeBufferID=64,.DidSignalLSBBits=16,.BelongToDidIndex=21},/*uint16*/

		/*************************************************43CA*******************************************************************/
		/*160:DIDSIGNALNAME_ID_SideDetShort2VCC			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=64,.DidSignalLSBBits=0,.BelongToDidIndex=22},/*uint8*/
		/*161:DIDSIGNALNAME_ID_SideDetOpen			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=65,.DidSignalLSBBits=8,.BelongToDidIndex=22},/*uint8*/
		/*162:DIDSIGNALNAME_ID_SideDetShort2GND			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=66,.DidSignalLSBBits=16,.BelongToDidIndex=22},/*uint8*/

		/*************************************************43CE*******************************************************************/
		/*163:DIDSIGNALNAME_ID_Buck4Temp			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=67,.DidSignalLSBBits=0,.BelongToDidIndex=23},/*uint8*/

		/*************************************************43CF*******************************************************************/
		/*164:DIDSIGNALNAME_ID_Buck1Temp			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=68,.DidSignalLSBBits=0,.BelongToDidIndex=24},/*uint8*/

		/*************************************************43D0*******************************************************************/
		/*165:DIDSIGNALNAME_ID_Buck2Temp			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=69,.DidSignalLSBBits=0,.BelongToDidIndex=25},/*uint8*/

		/*************************************************43D1*******************************************************************/
		/*166:DIDSIGNALNAME_ID_Buck3Temp			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=70,.DidSignalLSBBits=0,.BelongToDidIndex=26},/*uint8*/

		/*************************************************43D2*******************************************************************/
		/*167:DIDSIGNALNAME_ID_BoostTemp			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=71,.DidSignalLSBBits=0,.BelongToDidIndex=27},/*uint8*/

		/*************************************************43D3*******************************************************************/
		/*168:DIDSIGNALNAME_ID_LRVol			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=72,.DidSignalLSBBits=0,.BelongToDidIndex=28},/*uint8*/

		/*************************************************43D3*******************************************************************/
		/*169:DIDSIGNALNAME_ID_HallVol			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=73,.DidSignalLSBBits=0,.BelongToDidIndex=29},/*uint8*/

		/*************************************************43D3*******************************************************************/
		/*170:DIDSIGNALNAME_ID_FanSupplyVol			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=74,.DidSignalLSBBits=0,.BelongToDidIndex=30},/*uint8*/

		/*************************************************43D7*******************************************************************/
		/*171:DIDSIGNALNAME_ID_Ch1DrvErr			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=1,.SignalRunTimeBufferID=75,.DidSignalLSBBits=7,.BelongToDidIndex=31},/*uint8*/
		/*172:DIDSIGNALNAME_ID_Ch2DrvErr			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=1,.SignalRunTimeBufferID=76,.DidSignalLSBBits=6,.BelongToDidIndex=31},/*uint8*/
		/*173:DIDSIGNALNAME_ID_Ch3DrvErr			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=1,.SignalRunTimeBufferID=77,.DidSignalLSBBits=5,.BelongToDidIndex=31},/*uint8*/
		/*174:DIDSIGNALNAME_ID_Ch4DrvErr			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=1,.SignalRunTimeBufferID=78,.DidSignalLSBBits=4,.BelongToDidIndex=31},/*uint8*/
		/*175:DIDSIGNALNAME_ID_Ch5DrvErr			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=1,.SignalRunTimeBufferID=79,.DidSignalLSBBits=3,.BelongToDidIndex=31},/*uint8*/
		/*176:DIDSIGNALNAME_ID_Ch6DrvErr			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=1,.SignalRunTimeBufferID=80,.DidSignalLSBBits=2,.BelongToDidIndex=31},/*uint8*/
		/*177:DIDSIGNALNAME_ID_Ch7DrvErr			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=1,.SignalRunTimeBufferID=81,.DidSignalLSBBits=1,.BelongToDidIndex=31},/*uint8*/
		/*178:DIDSIGNALNAME_ID_Ch8DrvErr			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=1,.SignalRunTimeBufferID=82,.DidSignalLSBBits=0,.BelongToDidIndex=31},/*uint8*/
		/*179:DIDSIGNALNAME_ID_Ch9DrvErr			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=1,.SignalRunTimeBufferID=83,.DidSignalLSBBits=15,.BelongToDidIndex=31},/*uint8*/
		/*180:DIDSIGNALNAME_ID_Ch10DrvErr			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=1,.SignalRunTimeBufferID=84,.DidSignalLSBBits=14,.BelongToDidIndex=31},/*uint8*/
		/*181:DIDSIGNALNAME_ID_Ch11DrvErr			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=1,.SignalRunTimeBufferID=85,.DidSignalLSBBits=13,.BelongToDidIndex=31},/*uint8*/
		/*182:DIDSIGNALNAME_ID_Ch12DrvErr			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=1,.SignalRunTimeBufferID=86,.DidSignalLSBBits=12,.BelongToDidIndex=31},/*uint8*/

		/*************************************************43D8*******************************************************************/
		/*183:DIDSIGNALNAME_ID_SwlDrvComLoss			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=1,.SignalRunTimeBufferID=87,.DidSignalLSBBits=7,.BelongToDidIndex=32},/*uint8*/
		/*184:DIDSIGNALNAME_ID_SwlDrvTemWarn			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=1,.SignalRunTimeBufferID=88,.DidSignalLSBBits=6,.BelongToDidIndex=32},/*uint8*/
		/*185:DIDSIGNALNAME_ID_SwlDrvTemShutDown			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=1,.SignalRunTimeBufferID=89,.DidSignalLSBBits=5,.BelongToDidIndex=32},/*uint8*/
		/*186:DIDSIGNALNAME_ID_SwlDrvUnderVol			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=1,.SignalRunTimeBufferID=90,.DidSignalLSBBits=4,.BelongToDidIndex=32},/*uint8*/
		/*187:DIDSIGNALNAME_ID_SwlDrvRegFail			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=1,.SignalRunTimeBufferID=91,.DidSignalLSBBits=3,.BelongToDidIndex=32},/*uint8*/
		/*188:DIDSIGNALNAME_ID_SwlDrvReserved			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=3,.SignalRunTimeBufferID=92,.DidSignalLSBBits=0,.BelongToDidIndex=32},/*uint8*/

		/*************************************************43D9*******************************************************************/
		/*189:DIDSIGNALNAME_ID_LvlDrvComLoss			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=1,.SignalRunTimeBufferID=93,.DidSignalLSBBits=7,.BelongToDidIndex=33},/*uint8*/
		/*190:DIDSIGNALNAME_ID_LvlDrvTemWarn			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=1,.SignalRunTimeBufferID=94,.DidSignalLSBBits=6,.BelongToDidIndex=33},/*uint8*/
		/*191:DIDSIGNALNAME_ID_LvlDrvTemShutDown			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=1,.SignalRunTimeBufferID=95,.DidSignalLSBBits=5,.BelongToDidIndex=33},/*uint8*/
		/*192:DIDSIGNALNAME_ID_LvlDrvUnderVol			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=1,.SignalRunTimeBufferID=96,.DidSignalLSBBits=4,.BelongToDidIndex=33},/*uint8*/
		/*193:DIDSIGNALNAME_ID_LvlDrvRegFail			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=1,.SignalRunTimeBufferID=97,.DidSignalLSBBits=3,.BelongToDidIndex=33},/*uint8*/
		/*194:DIDSIGNALNAME_ID_LvlDrvReserved			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=3,.SignalRunTimeBufferID=98,.DidSignalLSBBits=0,.BelongToDidIndex=33},/*uint8*/

		/*************************************************43DA*******************************************************************/
		/*195:DIDSIGNALNAME_ID_AppSideDet			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=99,.DidSignalLSBBits=0,.BelongToDidIndex=34},/*uint8*/
		/*196:DIDSIGNALNAME_ID_BootSideDet			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=100,.DidSignalLSBBits=8,.BelongToDidIndex=34},/*uint8*/

		/*************************************************7022*******************************************************************/
		/*197:DIDSIGNALNAME_ID_Pixel1Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=101,.DidSignalLSBBits=0,.BelongToDidIndex=35},/*uint8*/
		/*198:DIDSIGNALNAME_ID_Pixel2Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=102,.DidSignalLSBBits=8,.BelongToDidIndex=35},/*uint8*/
		/*199:DIDSIGNALNAME_ID_Pixel3Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=103,.DidSignalLSBBits=16,.BelongToDidIndex=35},/*uint8*/
		/*200:DIDSIGNALNAME_ID_Pixel4Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=104,.DidSignalLSBBits=24,.BelongToDidIndex=35},/*uint8*/
		/*201:DIDSIGNALNAME_ID_Pixel5Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=105,.DidSignalLSBBits=32,.BelongToDidIndex=35},/*uint8*/
		/*202:DIDSIGNALNAME_ID_Pixel6Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=106,.DidSignalLSBBits=40,.BelongToDidIndex=35},/*uint8*/
		/*203:DIDSIGNALNAME_ID_Pixel7Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=107,.DidSignalLSBBits=48,.BelongToDidIndex=35},/*uint8*/
		/*204:DIDSIGNALNAME_ID_Pixel8Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=108,.DidSignalLSBBits=56,.BelongToDidIndex=35},/*uint8*/
		/*205:DIDSIGNALNAME_ID_Pixel9Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=109,.DidSignalLSBBits=64,.BelongToDidIndex=35},/*uint8*/
		/*206:DIDSIGNALNAME_ID_Pixel10Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=110,.DidSignalLSBBits=72,.BelongToDidIndex=35},/*uint8*/
		/*207:DIDSIGNALNAME_ID_Pixel11Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=111,.DidSignalLSBBits=80,.BelongToDidIndex=35},/*uint8*/
		/*208:DIDSIGNALNAME_ID_Pixel12Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=112,.DidSignalLSBBits=88,.BelongToDidIndex=35},/*uint8*/
		/*209:DIDSIGNALNAME_ID_Pixel13Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=113,.DidSignalLSBBits=96,.BelongToDidIndex=35},/*uint8*/
		/*210:DIDSIGNALNAME_ID_Pixel14Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=114,.DidSignalLSBBits=104,.BelongToDidIndex=35},/*uint8*/
		/*211:DIDSIGNALNAME_ID_Pixel15Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=115,.DidSignalLSBBits=112,.BelongToDidIndex=35},/*uint8*/
		/*212:DIDSIGNALNAME_ID_Pixel16Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=116,.DidSignalLSBBits=120,.BelongToDidIndex=35},/*uint8*/
		/*213:DIDSIGNALNAME_ID_Pixel17Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=117,.DidSignalLSBBits=128,.BelongToDidIndex=35},/*uint8*/
		/*214:DIDSIGNALNAME_ID_Pixel18Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=118,.DidSignalLSBBits=136,.BelongToDidIndex=35},/*uint8*/
		/*215:DIDSIGNALNAME_ID_Pixel19Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=119,.DidSignalLSBBits=144,.BelongToDidIndex=35},/*uint8*/
		/*216:DIDSIGNALNAME_ID_Pixel20Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=120,.DidSignalLSBBits=152,.BelongToDidIndex=35},/*uint8*/
		/*217:DIDSIGNALNAME_ID_Pixel21Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=121,.DidSignalLSBBits=160,.BelongToDidIndex=35},/*uint8*/
		/*218:DIDSIGNALNAME_ID_Pixel22Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=122,.DidSignalLSBBits=168,.BelongToDidIndex=35},/*uint8*/
		/*219:DIDSIGNALNAME_ID_Pixel23Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=123,.DidSignalLSBBits=176,.BelongToDidIndex=35},/*uint8*/
		/*220:DIDSIGNALNAME_ID_Pixel24Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=124,.DidSignalLSBBits=184,.BelongToDidIndex=35},/*uint8*/
		/*221:DIDSIGNALNAME_ID_Pixel25Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=125,.DidSignalLSBBits=192,.BelongToDidIndex=35},/*uint8*/
		/*222:DIDSIGNALNAME_ID_Pixel26Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=126,.DidSignalLSBBits=200,.BelongToDidIndex=35},/*uint8*/
		/*223:DIDSIGNALNAME_ID_Pixel27Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=127,.DidSignalLSBBits=208,.BelongToDidIndex=35},/*uint8*/
		/*224:DIDSIGNALNAME_ID_Pixel28Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=128,.DidSignalLSBBits=216,.BelongToDidIndex=35},/*uint8*/
		/*225:DIDSIGNALNAME_ID_Pixel29Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=129,.DidSignalLSBBits=224,.BelongToDidIndex=35},/*uint8*/
		/*226:DIDSIGNALNAME_ID_Pixel30Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=130,.DidSignalLSBBits=232,.BelongToDidIndex=35},/*uint8*/
		/*227:DIDSIGNALNAME_ID_Pixel31Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=131,.DidSignalLSBBits=240,.BelongToDidIndex=35},/*uint8*/
		/*228:DIDSIGNALNAME_ID_Pixel32Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=132,.DidSignalLSBBits=248,.BelongToDidIndex=35},/*uint8*/
		/*229:DIDSIGNALNAME_ID_Pixel33Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=133,.DidSignalLSBBits=256,.BelongToDidIndex=35},/*uint8*/
		/*230:DIDSIGNALNAME_ID_Pixel34Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=134,.DidSignalLSBBits=264,.BelongToDidIndex=35},/*uint8*/
		/*231:DIDSIGNALNAME_ID_Pixel35Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=135,.DidSignalLSBBits=272,.BelongToDidIndex=35},/*uint8*/
		/*232:DIDSIGNALNAME_ID_Pixel36Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=136,.DidSignalLSBBits=280,.BelongToDidIndex=35},/*uint8*/
		/*233:DIDSIGNALNAME_ID_Pixel37Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=137,.DidSignalLSBBits=288,.BelongToDidIndex=35},/*uint8*/
		/*234:DIDSIGNALNAME_ID_Pixel38Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=138,.DidSignalLSBBits=296,.BelongToDidIndex=35},/*uint8*/
		/*235:DIDSIGNALNAME_ID_Pixel39Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=139,.DidSignalLSBBits=304,.BelongToDidIndex=35},/*uint8*/
		/*236:DIDSIGNALNAME_ID_Pixel40Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=140,.DidSignalLSBBits=312,.BelongToDidIndex=35},/*uint8*/
		/*237:DIDSIGNALNAME_ID_Pixel41Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=141,.DidSignalLSBBits=320,.BelongToDidIndex=35},/*uint8*/
		/*238:DIDSIGNALNAME_ID_Pixel42Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=142,.DidSignalLSBBits=328,.BelongToDidIndex=35},/*uint8*/
		/*239:DIDSIGNALNAME_ID_Pixel43Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=143,.DidSignalLSBBits=336,.BelongToDidIndex=35},/*uint8*/
		/*240:DIDSIGNALNAME_ID_Pixel44Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=144,.DidSignalLSBBits=344,.BelongToDidIndex=35},/*uint8*/
		/*241:DIDSIGNALNAME_ID_Pixel45Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=145,.DidSignalLSBBits=352,.BelongToDidIndex=35},/*uint8*/
		/*242:DIDSIGNALNAME_ID_Pixel46Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=146,.DidSignalLSBBits=360,.BelongToDidIndex=35},/*uint8*/
		/*243:DIDSIGNALNAME_ID_Pixel47Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=147,.DidSignalLSBBits=368,.BelongToDidIndex=35},/*uint8*/
		/*244:DIDSIGNALNAME_ID_Pixel48Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=148,.DidSignalLSBBits=376,.BelongToDidIndex=35},/*uint8*/
		/*245:DIDSIGNALNAME_ID_Pixel49Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=149,.DidSignalLSBBits=384,.BelongToDidIndex=35},/*uint8*/
		/*246:DIDSIGNALNAME_ID_Pixel50Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=150,.DidSignalLSBBits=392,.BelongToDidIndex=35},/*uint8*/
		/*247:DIDSIGNALNAME_ID_Pixel51Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=151,.DidSignalLSBBits=400,.BelongToDidIndex=35},/*uint8*/
		/*248:DIDSIGNALNAME_ID_Pixel52Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=152,.DidSignalLSBBits=408,.BelongToDidIndex=35},/*uint8*/
		/*249:DIDSIGNALNAME_ID_Pixel53Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=153,.DidSignalLSBBits=416,.BelongToDidIndex=35},/*uint8*/
		/*250:DIDSIGNALNAME_ID_Pixel54Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=154,.DidSignalLSBBits=424,.BelongToDidIndex=35},/*uint8*/
		/*251:DIDSIGNALNAME_ID_Pixel55Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=155,.DidSignalLSBBits=432,.BelongToDidIndex=35},/*uint8*/
		/*252:DIDSIGNALNAME_ID_Pixel56Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=156,.DidSignalLSBBits=440,.BelongToDidIndex=35},/*uint8*/
		/*253:DIDSIGNALNAME_ID_Pixel57Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=157,.DidSignalLSBBits=448,.BelongToDidIndex=35},/*uint8*/
		/*254:DIDSIGNALNAME_ID_Pixel58Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=158,.DidSignalLSBBits=456,.BelongToDidIndex=35},/*uint8*/
		/*255:DIDSIGNALNAME_ID_Pixel59Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=159,.DidSignalLSBBits=464,.BelongToDidIndex=35},/*uint8*/
		/*256:DIDSIGNALNAME_ID_Pixel60Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=160,.DidSignalLSBBits=472,.BelongToDidIndex=35},/*uint8*/
		/*257:DIDSIGNALNAME_ID_Pixel61Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=161,.DidSignalLSBBits=480,.BelongToDidIndex=35},/*uint8*/
		/*258:DIDSIGNALNAME_ID_Pixel62Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=162,.DidSignalLSBBits=488,.BelongToDidIndex=35},/*uint8*/
		/*259:DIDSIGNALNAME_ID_Pixel63Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=163,.DidSignalLSBBits=496,.BelongToDidIndex=35},/*uint8*/
		/*260:DIDSIGNALNAME_ID_Pixel64Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=164,.DidSignalLSBBits=504,.BelongToDidIndex=35},/*uint8*/
		/*261:DIDSIGNALNAME_ID_Pixel65Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=165,.DidSignalLSBBits=512,.BelongToDidIndex=35},/*uint8*/
		/*262:DIDSIGNALNAME_ID_Pixel66Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=166,.DidSignalLSBBits=520,.BelongToDidIndex=35},/*uint8*/
		/*263:DIDSIGNALNAME_ID_Pixel67Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=167,.DidSignalLSBBits=528,.BelongToDidIndex=35},/*uint8*/
		/*264:DIDSIGNALNAME_ID_Pixel68Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=168,.DidSignalLSBBits=536,.BelongToDidIndex=35},/*uint8*/
		/*265:DIDSIGNALNAME_ID_Pixel69Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=169,.DidSignalLSBBits=544,.BelongToDidIndex=35},/*uint8*/
		/*266:DIDSIGNALNAME_ID_Pixel70Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=170,.DidSignalLSBBits=552,.BelongToDidIndex=35},/*uint8*/
		/*267:DIDSIGNALNAME_ID_Pixel71Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=171,.DidSignalLSBBits=560,.BelongToDidIndex=35},/*uint8*/
		/*268:DIDSIGNALNAME_ID_Pixel72Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=172,.DidSignalLSBBits=568,.BelongToDidIndex=35},/*uint8*/
		/*269:DIDSIGNALNAME_ID_Pixel73Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=173,.DidSignalLSBBits=576,.BelongToDidIndex=35},/*uint8*/
		/*270:DIDSIGNALNAME_ID_Pixel74Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=174,.DidSignalLSBBits=584,.BelongToDidIndex=35},/*uint8*/
		/*271:DIDSIGNALNAME_ID_Pixel75Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=175,.DidSignalLSBBits=592,.BelongToDidIndex=35},/*uint8*/
		/*272:DIDSIGNALNAME_ID_Pixel76Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=176,.DidSignalLSBBits=600,.BelongToDidIndex=35},/*uint8*/
		/*273:DIDSIGNALNAME_ID_Pixel77Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=177,.DidSignalLSBBits=608,.BelongToDidIndex=35},/*uint8*/
		/*274:DIDSIGNALNAME_ID_Pixel78Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=178,.DidSignalLSBBits=616,.BelongToDidIndex=35},/*uint8*/
		/*275:DIDSIGNALNAME_ID_Pixel79Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=179,.DidSignalLSBBits=624,.BelongToDidIndex=35},/*uint8*/
		/*276:DIDSIGNALNAME_ID_Pixel80Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=180,.DidSignalLSBBits=632,.BelongToDidIndex=35},/*uint8*/
		/*277:DIDSIGNALNAME_ID_Pixel81Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=181,.DidSignalLSBBits=640,.BelongToDidIndex=35},/*uint8*/
		/*278:DIDSIGNALNAME_ID_Pixel82Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=182,.DidSignalLSBBits=648,.BelongToDidIndex=35},/*uint8*/
		/*279:DIDSIGNALNAME_ID_Pixel83Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=183,.DidSignalLSBBits=656,.BelongToDidIndex=35},/*uint8*/
		/*280:DIDSIGNALNAME_ID_Pixel84Acv			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=184,.DidSignalLSBBits=664,.BelongToDidIndex=35},/*uint8*/

		/*************************************************D134*******************************************************************/
		/*281:DIDSIGNALNAME_ID_CarMode			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=185,.DidSignalLSBBits=0,.BelongToDidIndex=36},/*uint8*/

		/*************************************************DD00*******************************************************************/
		/*282:DIDSIGNALNAME_ID_GlobalRealTime			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=32,.SignalRunTimeBufferID=31,.DidSignalLSBBits=24,.BelongToDidIndex=37},/*uint32*/

		/*************************************************DD01*******************************************************************/
		/*283:DIDSIGNALNAME_ID_GlobalTotalDistance			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=24,.SignalRunTimeBufferID=32,.DidSignalLSBBits=16,.BelongToDidIndex=38},/*uint32*/

		/*************************************************DD02*******************************************************************/
		/*284:DIDSIGNALNAME_ID_VehBatteryVol			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=186,.DidSignalLSBBits=0,.BelongToDidIndex=39},/*uint8*/

		/*************************************************DD0A*******************************************************************/
		/*285:DIDSIGNALNAME_ID_UsageMode			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=187,.DidSignalLSBBits=0,.BelongToDidIndex=40},/*uint8*/

		/*************************************************DD0C*******************************************************************/
		/*286:DIDSIGNALNAME_ID_ElectricPowerLevel			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=188,.DidSignalLSBBits=0,.BelongToDidIndex=41},/*uint8*/

		/*************************************************DD07*******************************************************************/
		/*287:DIDSIGNALNAME_ID_GNSSUTCTimeYear			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=189,.DidSignalLSBBits=0,.BelongToDidIndex=42},/*uint8*/
		/*288:DIDSIGNALNAME_ID_GNSSUTCTimeMonth			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=190,.DidSignalLSBBits=8,.BelongToDidIndex=42},/*uint8*/
		/*289:DIDSIGNALNAME_ID_GNSSUTCTimeDay			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=191,.DidSignalLSBBits=16,.BelongToDidIndex=42},/*uint8*/
		/*290:DIDSIGNALNAME_ID_GNSSUTCTimeHour			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=192,.DidSignalLSBBits=24,.BelongToDidIndex=42},/*uint8*/
		/*291:DIDSIGNALNAME_ID_GNSSUTCTimeMinute			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=193,.DidSignalLSBBits=32,.BelongToDidIndex=42},/*uint8*/
		/*292:DIDSIGNALNAME_ID_GNSSUTCTimeSecond			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=8,.SignalRunTimeBufferID=194,.DidSignalLSBBits=40,.BelongToDidIndex=42},/*uint8*/

#if (VEHICLE_PLATFORM == VEHICLE_GEELY_FX11)
        /*************************************************DD07*******************************************************************/
        /*293:DIDSIGNALNAME_ID_VehicleSpeed			*/
		{.SignalSort=E_SignalSort_Motorola,.DidSignalLengths=16,.SignalRunTimeBufferID=65,.DidSignalLSBBits=0,.BelongToDidIndex=43},/*uint16*/

#endif
};

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
Std_ReturnType ResettAllIoctrToDefault(void)
{
	uint8_t i=0;

	for(i=0;i<DidIoCtr_NUM;i++)
	{
		g_S_IoCtrInfo[i].CurIoCtrState=E_IOCtrType_ReturnControl;
		g_S_IoCtrInfo[i].IoCtrCallBack(E_IOCtrType_ReturnControl);
	}
	return E_OK;
}
Std_ReturnType SetDidIoCtrState(uint8_t DidNameId,E_IOCtrType IOCtrType)
{
	if(g_S_DidConfig[DidNameId].DidPermissions.bits.Service_0x2F != 1)
		return E_NOT_OK;

	if(g_S_DidConfig[DidNameId].IoCtrInfo == NULL)
		return E_NOT_OK;

	g_S_DidConfig[DidNameId].IoCtrInfo->CurIoCtrState=IOCtrType;

	return E_OK;
}

const S_DidConfig *GetDidConfig(uint16_t index)
{
	if(index>=DidConfig_NUM)
		return NULL;

	return &g_S_DidConfig[index];
}

const S_DidSignal* GetDidSignal(uint16_t index)
{
	if (index>=DidSignal_NUM)
		return NULL;
	return &g_S_DidSignal[index];
}


