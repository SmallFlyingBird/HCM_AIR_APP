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
#include "IOCtr_Manager.h"
#include "Channel_Interface.h"
#include "Fan.h"
#if (QINGHAIGANG)
#include "IOCtr_ASW.h"
#endif  /*QINGHAIGANG*/

/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
static uint8 ChannelIOCtrSts[MAX_CHANNLE_NUM];
static uint8 LBHBPixelIOCtrSts = 0;
/****************************************************************
 *                                                              *
 *                   Global Variable Define                     *
 *                                                              *
 ****************************************************************/
S_DiagIOCtr_CHN_t diagioctr_chn[MAX_CHANNLE_NUM];
S_DiagIOCtr_ADBPIX_t diagioctr_adbpix;

/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/
static Std_ReturnType ChannelIOCtrProcess(uint8 IOCtrType, E_ChannelID chid, uint8_t DidNameID, uint16_t PwmSigID, uint16_t CurSigID)
{
    Std_ReturnType rtval = E_OK;

    return rtval;
}

/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
/* 434B CallBack */
Std_ReturnType IOCtr_434B_Cbk(uint8 IOCtrTypeState)
{
    Std_ReturnType rtval = E_OK;

    Fan_IoCtrCallback(IOCtrTypeState);

    return rtval;
}

/* 4358 CallBack */
Std_ReturnType IOCtr_4358_Cbk(uint8 IOCtrTypeState)
{
    Std_ReturnType rtval = E_OK;

    // SiderMarkerLamp_IoCtrCallback(IOCtrTypeState);

    return rtval;
}

/* channel1 cbk*/
Std_ReturnType IOCtr_4359_Cbk(uint8 IOCtrType)
{
    Std_ReturnType rtval = E_OK;


    return rtval;
}
/* channel2 cbk*/
Std_ReturnType IOCtr_435B_Cbk(uint8 IOCtrType)
{
    Std_ReturnType rtval = E_OK;


    return rtval;
}
/* channel3 cbk*/
Std_ReturnType IOCtr_435C_Cbk(uint8 IOCtrType)
{
    Std_ReturnType rtval = E_OK;


    return rtval;
}
/* channel4 cbk*/
Std_ReturnType IOCtr_435D_Cbk(uint8 IOCtrType)
{
    Std_ReturnType rtval = E_OK;


    return rtval;
}
/* channel5 cbk*/
Std_ReturnType IOCtr_435E_Cbk(uint8 IOCtrType)
{
    Std_ReturnType rtval = E_OK;


    return rtval;
}
/* channel6 cbk*/
Std_ReturnType IOCtr_435F_Cbk(uint8 IOCtrType)
{
    Std_ReturnType rtval = E_OK;


    return rtval;
}
/* channel7 cbk*/
Std_ReturnType IOCtr_4360_Cbk(uint8 IOCtrType)
{
    // Std_ReturnType rtval = E_OK;

    // rtval = ChannelIOCtrProcess(IOCtrType, ChannelID7,
    //                             DIDNAME_ID_HeadlampCtrlLEDCh7,
    //                             DIDSIGNALNAME_ID_CH7OutputLuminosity,
    //                             DIDSIGNALNAME_ID_CH7Current);

    // return rtval;
}
/* channel8 cbk*/
Std_ReturnType IOCtr_4361_Cbk(uint8 IOCtrType)
{
    // Std_ReturnType rtval = E_OK;

    // rtval = ChannelIOCtrProcess(IOCtrType, ChannelID8,
    //                             DIDNAME_ID_HeadlampCtrlLEDCh8,
    //                             DIDSIGNALNAME_ID_CH8OutputLuminosity,
    //                             DIDSIGNALNAME_ID_CH8Current);

    // return rtval;
}
/* channel9 cbk*/
Std_ReturnType IOCtr_4362_Cbk(uint8 IOCtrType)
{
    // Std_ReturnType rtval = E_OK;

    // rtval = ChannelIOCtrProcess(IOCtrType, ChannelID9,
    //                             DIDNAME_ID_HeadlampCtrlLEDCh9,
    //                             DIDSIGNALNAME_ID_CH9OutputLuminosity,
    //                             DIDSIGNALNAME_ID_CH9Current);

    // return rtval;
}
/* channel10 cbk*/
Std_ReturnType IOCtr_4363_Cbk(uint8 IOCtrType)
{
    // Std_ReturnType rtval = E_OK;

    // rtval = ChannelIOCtrProcess(IOCtrType, ChannelID10,
    //                             DIDNAME_ID_HeadlampCtrlLEDCh10,
    //                             DIDSIGNALNAME_ID_CH10OutputLuminosity,
    //                             DIDSIGNALNAME_ID_CH10Current);

    // return rtval;
}
/* channel11 cbk*/
Std_ReturnType IOCtr_4364_Cbk(uint8 IOCtrType)
{
    // Std_ReturnType rtval = E_OK;

    // rtval = ChannelIOCtrProcess(IOCtrType, ChannelID11,
    //                             DIDNAME_ID_HeadlampCtrlLEDCh11,
    //                             DIDSIGNALNAME_ID_CH11OutputLuminosity,
    //                             DIDSIGNALNAME_ID_CH11Current);

    // return rtval;
}
/* channel12 cbk*/
Std_ReturnType IOCtr_4367_Cbk(uint8 IOCtrType)
{
    // Std_ReturnType rtval = E_OK;

    // rtval = ChannelIOCtrProcess(IOCtrType, ChannelID4,
    //                             DIDNAME_ID_HeadlampCtrlLEDCh12,
    //                             DIDSIGNALNAME_ID_CH12OutputLuminosity,
    //                             DIDSIGNALNAME_ID_CH12Current);

    // return rtval;
}
/* 4365 CallBack */
Std_ReturnType IOCtr_4365_Cbk(uint8 IOCtrTypeState)
{
    Std_ReturnType rtval = E_OK;
    // rtval = LevelingMotor_IoCtrCallBack(IOCtrTypeState);
    return rtval;
}

/* 4366 CallBack */
Std_ReturnType IOCtr_4366_Cbk(uint8 IOCtrTypeState)
{
    Std_ReturnType rtval = E_OK;
    // rtval = SwivelingMotor_IoCtrCallBack(IOCtrTypeState);
    return rtval;
}

/* 43A9 CallBack */
Std_ReturnType IOCtr_43A9_Cbk(uint8 IOCtrTypeState)
{
    Std_ReturnType rtval = E_OK;

    return rtval;
}

/*远近光84像素2F控制*/
Std_ReturnType IOCtr_7022_Cbk(uint8 IOCtrType)
{
    Std_ReturnType rtval = E_OK;

    uint8_t i = 0;
    uint8_t n, k;
    uint32_t iodata;

    LBHBPixelIOCtrSts = IOCtrType;
    diagioctr_adbpix.ctr = IOCtrType;


    return rtval;
}

/*
 *  获得通道2F服务的状态
 */
uint8 GetChannelIOCtrSts(E_ChannelID id)
{
    return ChannelIOCtrSts[id];
}

/*
 *  获得远近光像素点的2F服务的状态
 */
uint8 GetLBHBPixelIOCtrSts(E_ChannelID id)
{
    return LBHBPixelIOCtrSts;
}