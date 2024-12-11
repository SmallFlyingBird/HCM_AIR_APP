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
#include "DidConfig.h"
#include "DID_Interface.h"
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
static E_IOCtrType ChannelIOCtrSts[MAX_CHANNLE_NUM];
static E_IOCtrType LBHBPixelIOCtrSts = E_IOCtrType_ReturnControl;
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
static Std_ReturnType ChannelIOCtrProcess(E_IOCtrType IOCtrType, E_ChannelID chid, uint8_t DidNameID, uint16_t PwmSigID, uint16_t CurSigID)
{
    Std_ReturnType rtval = E_OK;
    uint8_t mask;
    uint8_t iodata;

    ChannelIOCtrSts[chid] = IOCtrType;

    diagioctr_chn[chid].ctr = IOCtrType;
    diagioctr_chn[chid].mask = 0;

    if (IOCtrType == E_IOCtrType_ShortTermAdjustment)
    {
        Interface_GetDidIoctrMask(DidNameID, &mask);
        diagioctr_chn[chid].mask = mask;

        /*设置通道PWM的值*/
        if ((mask & 0x80) != 0)
        {
            /*获取PWM的值*/
            Interface_GetDidSignalIoctrData(PwmSigID, &iodata);
            if (iodata > 100) { iodata = 100; }

            diagioctr_chn[chid].pwm = ((uint8_t)iodata);

            Interface_SetDidSignalData(PwmSigID, iodata);
        }
        /*设置通道电流的值*/
        if ((mask & 0x40) != 0)
        {
            /*获取电流的值*/
            Interface_GetDidSignalIoctrData(CurSigID, &iodata);
            
            if (iodata != 4095)
            { diagioctr_chn[chid].cur = ((uint16_t)iodata); }
            else
            { diagioctr_chn[chid].mask &= (~(0x40)); }

            Interface_SetDidSignalData(CurSigID, iodata);
        }
    }

    return rtval;
}

/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
/* 434B CallBack */
Std_ReturnType IOCtr_434B_Cbk(E_IOCtrType IOCtrTypeState)
{
    Std_ReturnType rtval = E_OK;

    Fan_IoCtrCallback(IOCtrTypeState);

    return rtval;
}

/* 4358 CallBack */
Std_ReturnType IOCtr_4358_Cbk(E_IOCtrType IOCtrTypeState)
{
    Std_ReturnType rtval = E_OK;

    // SiderMarkerLamp_IoCtrCallback(IOCtrTypeState);

    return rtval;
}

/* channel1 cbk*/
Std_ReturnType IOCtr_4359_Cbk(E_IOCtrType IOCtrType)
{
    Std_ReturnType rtval = E_OK;

    rtval = ChannelIOCtrProcess(IOCtrType, ChannelID1,
                                DIDNAME_ID_HeadlampCtrlLEDCh1,
                                DIDSIGNALNAME_ID_CH1OutputLuminosity,
                                DIDSIGNALNAME_ID_CH1Current);

    return rtval;
}
/* channel2 cbk*/
Std_ReturnType IOCtr_435B_Cbk(E_IOCtrType IOCtrType)
{
    Std_ReturnType rtval = E_OK;

    rtval = ChannelIOCtrProcess(IOCtrType, ChannelID2,
                                DIDNAME_ID_HeadlampCtrlLEDCh2,
                                DIDSIGNALNAME_ID_CH2OutputLuminosity,
                                DIDSIGNALNAME_ID_CH2Current);

    return rtval;
}
/* channel3 cbk*/
Std_ReturnType IOCtr_435C_Cbk(E_IOCtrType IOCtrType)
{
    Std_ReturnType rtval = E_OK;

    rtval = ChannelIOCtrProcess(IOCtrType, ChannelID3,
                                DIDNAME_ID_HeadlampCtrlLEDCh3,
                                DIDSIGNALNAME_ID_CH3OutputLuminosity,
                                DIDSIGNALNAME_ID_CH3Current);

    return rtval;
}
/* channel4 cbk*/
Std_ReturnType IOCtr_435D_Cbk(E_IOCtrType IOCtrType)
{
    Std_ReturnType rtval = E_OK;

    rtval = ChannelIOCtrProcess(IOCtrType, ChannelID4,
                                DIDNAME_ID_HeadlampCtrlLEDCh4,
                                DIDSIGNALNAME_ID_CH4OutputLuminosity,
                                DIDSIGNALNAME_ID_CH4Current);

    return rtval;
}
/* channel5 cbk*/
Std_ReturnType IOCtr_435E_Cbk(E_IOCtrType IOCtrType)
{
    Std_ReturnType rtval = E_OK;

    rtval = ChannelIOCtrProcess(IOCtrType, ChannelID5,
                                DIDNAME_ID_HeadlampCtrlLEDCh5,
                                DIDSIGNALNAME_ID_CH5OutputLuminosity,
                                DIDSIGNALNAME_ID_CH5Current);

    return rtval;
}
/* channel6 cbk*/
Std_ReturnType IOCtr_435F_Cbk(E_IOCtrType IOCtrType)
{
    Std_ReturnType rtval = E_OK;

    rtval = ChannelIOCtrProcess(IOCtrType, ChannelID6,
                                DIDNAME_ID_HeadlampCtrlLEDCh6,
                                DIDSIGNALNAME_ID_CH6OutputLuminosity,
                                DIDSIGNALNAME_ID_CH6Current);

    return rtval;
}
/* channel7 cbk*/
Std_ReturnType IOCtr_4360_Cbk(E_IOCtrType IOCtrType)
{
    // Std_ReturnType rtval = E_OK;

    // rtval = ChannelIOCtrProcess(IOCtrType, ChannelID7,
    //                             DIDNAME_ID_HeadlampCtrlLEDCh7,
    //                             DIDSIGNALNAME_ID_CH7OutputLuminosity,
    //                             DIDSIGNALNAME_ID_CH7Current);

    // return rtval;
}
/* channel8 cbk*/
Std_ReturnType IOCtr_4361_Cbk(E_IOCtrType IOCtrType)
{
    // Std_ReturnType rtval = E_OK;

    // rtval = ChannelIOCtrProcess(IOCtrType, ChannelID8,
    //                             DIDNAME_ID_HeadlampCtrlLEDCh8,
    //                             DIDSIGNALNAME_ID_CH8OutputLuminosity,
    //                             DIDSIGNALNAME_ID_CH8Current);

    // return rtval;
}
/* channel9 cbk*/
Std_ReturnType IOCtr_4362_Cbk(E_IOCtrType IOCtrType)
{
    // Std_ReturnType rtval = E_OK;

    // rtval = ChannelIOCtrProcess(IOCtrType, ChannelID9,
    //                             DIDNAME_ID_HeadlampCtrlLEDCh9,
    //                             DIDSIGNALNAME_ID_CH9OutputLuminosity,
    //                             DIDSIGNALNAME_ID_CH9Current);

    // return rtval;
}
/* channel10 cbk*/
Std_ReturnType IOCtr_4363_Cbk(E_IOCtrType IOCtrType)
{
    // Std_ReturnType rtval = E_OK;

    // rtval = ChannelIOCtrProcess(IOCtrType, ChannelID10,
    //                             DIDNAME_ID_HeadlampCtrlLEDCh10,
    //                             DIDSIGNALNAME_ID_CH10OutputLuminosity,
    //                             DIDSIGNALNAME_ID_CH10Current);

    // return rtval;
}
/* channel11 cbk*/
Std_ReturnType IOCtr_4364_Cbk(E_IOCtrType IOCtrType)
{
    // Std_ReturnType rtval = E_OK;

    // rtval = ChannelIOCtrProcess(IOCtrType, ChannelID11,
    //                             DIDNAME_ID_HeadlampCtrlLEDCh11,
    //                             DIDSIGNALNAME_ID_CH11OutputLuminosity,
    //                             DIDSIGNALNAME_ID_CH11Current);

    // return rtval;
}
/* channel12 cbk*/
Std_ReturnType IOCtr_4367_Cbk(E_IOCtrType IOCtrType)
{
    // Std_ReturnType rtval = E_OK;

    // rtval = ChannelIOCtrProcess(IOCtrType, ChannelID4,
    //                             DIDNAME_ID_HeadlampCtrlLEDCh12,
    //                             DIDSIGNALNAME_ID_CH12OutputLuminosity,
    //                             DIDSIGNALNAME_ID_CH12Current);

    // return rtval;
}
/* 4365 CallBack */
Std_ReturnType IOCtr_4365_Cbk(E_IOCtrType IOCtrTypeState)
{
    Std_ReturnType rtval = E_OK;
    // rtval = LevelingMotor_IoCtrCallBack(IOCtrTypeState);
    return rtval;
}

/* 4366 CallBack */
Std_ReturnType IOCtr_4366_Cbk(E_IOCtrType IOCtrTypeState)
{
    Std_ReturnType rtval = E_OK;
    // rtval = SwivelingMotor_IoCtrCallBack(IOCtrTypeState);
    return rtval;
}

/* 43A9 CallBack */
Std_ReturnType IOCtr_43A9_Cbk(E_IOCtrType IOCtrTypeState)
{
    Std_ReturnType rtval = E_OK;

    return rtval;
}

/*远近光84像素2F控制*/
Std_ReturnType IOCtr_7022_Cbk(E_IOCtrType IOCtrType)
{
    Std_ReturnType rtval = E_OK;

    uint8_t i = 0;
    uint8_t n, k;
    uint32_t iodata;

    LBHBPixelIOCtrSts = IOCtrType;
    diagioctr_adbpix.ctr = IOCtrType;

    if (IOCtrType == E_IOCtrType_ShortTermAdjustment)
    {
        for (i = 0; i < MAX_ADBPIXNUM; i++)
        {
            Interface_GetDidSignalIoctrData((DIDSIGNALNAME_ID_Pixel1Acv + i), &iodata);
            if (iodata <= 100)
            {
                n = i/8; k = i%8;
                diagioctr_adbpix.mask[n] |= 0x01 << k;
                diagioctr_adbpix.pix[i] = ((uint8_t)iodata);

                Interface_SetDidSignalData((DIDSIGNALNAME_ID_Pixel1Acv + i), iodata);
            }
        }
    }

    return rtval;
}

/*
 *  获得通道2F服务的状态
 */
E_IOCtrType GetChannelIOCtrSts(E_ChannelID id)
{
    return ChannelIOCtrSts[id];
}

/*
 *  获得远近光像素点的2F服务的状态
 */
E_IOCtrType GetLBHBPixelIOCtrSts(E_ChannelID id)
{
    return LBHBPixelIOCtrSts;
}