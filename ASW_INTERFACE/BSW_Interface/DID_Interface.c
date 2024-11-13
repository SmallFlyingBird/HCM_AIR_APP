/*
 * DID_Interface.c
 *
 *  Created on: 2024��1��12��
 *      Author: mihuiliang
 */

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "DIDConfig.h"
#include "DID_Interface.h"
#include "IOCtr_Manager.h"
#include "Rte_Dcm_Type.h"
#include "Dcm.h"
/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
static uint8_t DidSignal8bitRunTimebuffer[DIDSIGNALE_8BIT_SIZE];
static uint16_t DidSignal16bitRunTimebuffer[DIDSIGNALE_16BIT_SIZE];
static uint32_t DidSignal32bitRunTimebuffer[DIDSIGNALE_32BIT_SIZE];

/****************************************************************
 *                                                              *
 *                   Global Variable Define                     *
 *                                                              *
 ****************************************************************/

/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/
static uint8_t SignalDataIsChange(const S_DidSignal *ptDidSignal, uint32 value)
{
    uint16_t bufferid;

    bufferid = ptDidSignal->SignalRunTimeBufferID;

    if (ptDidSignal->DidSignalLengths <= 8)
    {
        if (bufferid >= DIDSIGNALE_8BIT_SIZE)
            return 0;
        if ((uint8_t)value == DidSignal8bitRunTimebuffer[bufferid])
            return 0;
        else
            return 1;
    }
    else if (ptDidSignal->DidSignalLengths <= 16)
    {
        if (bufferid >= DIDSIGNALE_16BIT_SIZE)
            return 0;
        if ((uint16_t)value == DidSignal16bitRunTimebuffer[bufferid])
            return 0;
        else
            return 1;
    }
    else if (ptDidSignal->DidSignalLengths <= 32)
    {
        if (bufferid >= DIDSIGNALE_32BIT_SIZE)
            return 0;
        if ((uint32_t)value == DidSignal32bitRunTimebuffer[bufferid])
            return 0;
        else
            return 1;
    }
    /*will not go to here*/
    return 0;
}

static Std_ReturnType UpdateDidSignalRunTimebuffer(const S_DidSignal *ptDidSignal, uint32 value)
{

    uint16_t bufferid;

    bufferid = ptDidSignal->SignalRunTimeBufferID;

    if (ptDidSignal->DidSignalLengths <= 8)
    {
        if (bufferid >= DIDSIGNALE_8BIT_SIZE)
            return E_NOT_OK;

        DidSignal8bitRunTimebuffer[bufferid] = (uint8_t)value;
    }
    else if (ptDidSignal->DidSignalLengths <= 16)
    {
        if (bufferid >= DIDSIGNALE_16BIT_SIZE)
            return 0;

        DidSignal16bitRunTimebuffer[bufferid] = (uint16_t)value;
    }
    else if (ptDidSignal->DidSignalLengths <= 32)
    {
        if (bufferid >= DIDSIGNALE_32BIT_SIZE)
            return 0;

        DidSignal32bitRunTimebuffer[bufferid] = (uint32_t)value;
    }

    return E_OK;
}

static Std_ReturnType SetSignalValue(const S_DidSignal *ptDidSignal, uint32 value)
{
    uint8_t SignalStartBytes;
    uint8_t bitoffsets;
    uint8_t signallength;
    uint8_t RemainSignalLength = 0;
    uint8_t *datasrc;
    uint32 value_tmp;
    Std_ReturnType rtval;
    const S_DidConfig *DidConfig = NULL;

    if (SignalDataIsChange(ptDidSignal, value) == 0)
        return E_OK;

    SignalStartBytes = (ptDidSignal->DidSignalLSBBits / 8);
    bitoffsets = (uint8_t)(ptDidSignal->DidSignalLSBBits & 0x07);
    signallength = ptDidSignal->DidSignalLengths;

    DidConfig = GetDidConfig(ptDidSignal->BelongToDidIndex);
    if (DidConfig == NULL)
        return E_NOT_OK;

    datasrc = DidConfig->DidDataSrc;

    if (SignalStartBytes >= (DidConfig->DidDataLength))
        return E_NOT_OK; /*overflow*/

    if ((bitoffsets + signallength) <= 8)
    {
        /*�ź�û�п��ֽ�*/
        datasrc[SignalStartBytes] &= (0xFF << (bitoffsets + signallength)) | (0xFF >> (8 - bitoffsets));
        datasrc[SignalStartBytes] |= ((uint8_t)value) << bitoffsets;
    }
    else
    {
        RemainSignalLength = signallength;
        value_tmp = value;

        datasrc[SignalStartBytes] &= 0xFF >> (8 - bitoffsets);
        datasrc[SignalStartBytes] |= (uint8_t)(value_tmp << bitoffsets);
        value_tmp = value_tmp >> (8 - bitoffsets);

        RemainSignalLength -= (8 - bitoffsets);

        while (RemainSignalLength > 8)
        {
            bitoffsets = 0;
            if (ptDidSignal->SignalSort == E_SignalSort_Motorola)
            {
                if (SignalStartBytes == 0)
                    return E_NOT_OK; /*the first byte ,can not --*/
                SignalStartBytes--;
            }
            else if (ptDidSignal->SignalSort == E_SignalSort_Intel)
            {
                if (SignalStartBytes >= (DidConfig->DidDataLength - 1))
                    return E_NOT_OK; /*the last byte,can not ++*/
                SignalStartBytes++;
            }

            datasrc[SignalStartBytes] = (uint8_t)(value_tmp & 0XFF);

            RemainSignalLength -= 8;
            value_tmp = value_tmp >> 8;
        }

        if (RemainSignalLength > 0)
        {
            if (ptDidSignal->SignalSort == E_SignalSort_Motorola)
            {
                if (SignalStartBytes == 0)
                    return E_NOT_OK; /*the first byte ,can not --*/
                SignalStartBytes--;
            }
            else if (ptDidSignal->SignalSort == E_SignalSort_Intel)
            {
                if (SignalStartBytes >= (DidConfig->DidDataLength - 1))
                    return E_NOT_OK; /*the last byte,can not ++*/
                SignalStartBytes++;
            }
            datasrc[SignalStartBytes] &= (0xFF << RemainSignalLength);
            datasrc[SignalStartBytes] |= (uint8_t)value_tmp;
        }
    }

    rtval = UpdateDidSignalRunTimebuffer(ptDidSignal, value);

    return rtval;
}

static Std_ReturnType GetSignalValue(const S_DidSignal *ptDidSignal, uint32 *value, E_DataType DataType)
{
    uint8_t SignalStartBytes;
    uint8_t bitoffsets,shiftbits;
    uint8_t signallength;
    uint8_t RemainSignalLength;
    uint8_t *datasrc;
    uint32 value_tmp = 0;
    Std_ReturnType rtval = E_OK;

    const S_DidConfig *DidConfig = NULL;

    SignalStartBytes = (ptDidSignal->DidSignalLSBBits / 8);
    bitoffsets = (uint8_t)(ptDidSignal->DidSignalLSBBits & 0x07);
    signallength = ptDidSignal->DidSignalLengths;

    DidConfig = GetDidConfig(ptDidSignal->BelongToDidIndex);
    if (NULL == DidConfig)
        return E_NOT_OK;

    if (DataType == E_DataType_0x22_0x2E)
    {
        datasrc = DidConfig->DidDataSrc;
    }
    else if (DataType == E_DataType_0x2F)
    {
        if (DidConfig->IoCtrInfo == NULL)
            return E_NOT_OK;

        if (DidConfig->IoCtrInfo->IoCtrlMaskSupport == E_IoCtrlMaskSupport_MaskAtStartByte)
            datasrc = &(DidConfig->IoCtrInfo->DidIOCtrlDataSrc[1]); /*The first byte is Mask*/
        else
            datasrc = &(DidConfig->IoCtrInfo->DidIOCtrlDataSrc[0]);
    }

    if (SignalStartBytes >= (DidConfig->DidDataLength))
        return E_NOT_OK; /*overflow*/

    if ((bitoffsets + signallength) <= 8)
    {
        /*�ź�û�п��ֽ�*/
        value_tmp = (uint32_t)((datasrc[SignalStartBytes] >> bitoffsets) & (0XFF >> (8 - signallength)));
    }
    else
    {
        RemainSignalLength = signallength;
        value_tmp = (uint32_t)((datasrc[SignalStartBytes] >> bitoffsets) & (0XFF >> bitoffsets));

        RemainSignalLength -= (8 - bitoffsets);

        shiftbits = (8 - bitoffsets);
        while (RemainSignalLength >= 8)
        {
            if (ptDidSignal->SignalSort == E_SignalSort_Motorola)
            {
                if (SignalStartBytes == 0)
                    return E_NOT_OK; /*the first byte ,can not --*/
                SignalStartBytes--;
            }
            else if (ptDidSignal->SignalSort == E_SignalSort_Intel)
            {
                if (SignalStartBytes >= (DidConfig->DidDataLength - 1))
                    return E_NOT_OK; /*the last byte,can not ++*/
                SignalStartBytes++;
            }

            value_tmp += ((uint32_t)datasrc[SignalStartBytes]) << (shiftbits);

            shiftbits += 8;
            RemainSignalLength -= 8;
        }

        if (RemainSignalLength > 0)
        {
            if (ptDidSignal->SignalSort == E_SignalSort_Motorola)
            {
                if (SignalStartBytes == 0)
                    return E_NOT_OK; /*the first byte ,can not --*/
                SignalStartBytes--;
            }
            else if (ptDidSignal->SignalSort == E_SignalSort_Intel)
            {
                if (SignalStartBytes >= (DidConfig->DidDataLength - 1))
                    return E_NOT_OK; /*the last byte,can not ++*/
                SignalStartBytes++;
            }

            value_tmp += ((uint32_t)datasrc[SignalStartBytes] & (0xFF >> (8 - RemainSignalLength))) << (shiftbits);
        }
    }

    *value = value_tmp;

    if (DataType == E_DataType_0x22_0x2E)
        rtval |= UpdateDidSignalRunTimebuffer(ptDidSignal, value_tmp);

    return E_OK;
}

/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
Std_ReturnType Interface_DID434B_IoCtrCallback(E_IOCtrType IOCtrTypeState)
{
    Std_ReturnType rtval = E_OK;
    rtval = IOCtr_434B_Cbk(IOCtrTypeState);
    return rtval;
}

Std_ReturnType Interface_DID4358_IoCtrCallback(E_IOCtrType IOCtrTypeState)
{
    Std_ReturnType rtval = E_OK;
    rtval = IOCtr_4358_Cbk(IOCtrTypeState);
    return rtval;
}
Std_ReturnType Interface_DID4359_IoCtrCallback(E_IOCtrType IOCtrTypeState)
{
    Std_ReturnType rtval = E_OK;
    rtval = IOCtr_4359_Cbk(IOCtrTypeState);
    return rtval;
}

Std_ReturnType Interface_DID435B_IoCtrCallback(E_IOCtrType IOCtrTypeState)
{
    Std_ReturnType rtval = E_OK;
    rtval = IOCtr_435B_Cbk(IOCtrTypeState);
    return rtval;
}
Std_ReturnType Interface_DID435C_IoCtrCallback(E_IOCtrType IOCtrTypeState)
{
    Std_ReturnType rtval = E_OK;
    rtval = IOCtr_435C_Cbk(IOCtrTypeState);
    return rtval;
}

Std_ReturnType Interface_DID435D_IoCtrCallback(E_IOCtrType IOCtrTypeState)
{
    Std_ReturnType rtval = E_OK;
    rtval = IOCtr_435D_Cbk(IOCtrTypeState);
    return rtval;
}
Std_ReturnType Interface_DID435E_IoCtrCallback(E_IOCtrType IOCtrTypeState)
{
    Std_ReturnType rtval = E_OK;
    rtval = IOCtr_435E_Cbk(IOCtrTypeState);
    return rtval;
}

Std_ReturnType Interface_DID435F_IoCtrCallback(E_IOCtrType IOCtrTypeState)
{
    Std_ReturnType rtval = E_OK;
    rtval = IOCtr_435F_Cbk(IOCtrTypeState);
    return rtval;
}
Std_ReturnType Interface_DID4360_IoCtrCallback(E_IOCtrType IOCtrTypeState)
{
    Std_ReturnType rtval = E_OK;
    rtval = IOCtr_4360_Cbk(IOCtrTypeState);
    return rtval;
}

Std_ReturnType Interface_DID4361_IoCtrCallback(E_IOCtrType IOCtrTypeState)
{
    Std_ReturnType rtval = E_OK;
    rtval = IOCtr_4361_Cbk(IOCtrTypeState);
    return rtval;
}
Std_ReturnType Interface_DID4362_IoCtrCallback(E_IOCtrType IOCtrTypeState)
{
    Std_ReturnType rtval = E_OK;
    rtval = IOCtr_4362_Cbk(IOCtrTypeState);
    return rtval;
}

Std_ReturnType Interface_DID4363_IoCtrCallback(E_IOCtrType IOCtrTypeState)
{
    Std_ReturnType rtval = E_OK;
    rtval = IOCtr_4363_Cbk(IOCtrTypeState);
    return rtval;
}
Std_ReturnType Interface_DID4364_IoCtrCallback(E_IOCtrType IOCtrTypeState)
{
    Std_ReturnType rtval = E_OK;
    rtval = IOCtr_4364_Cbk(IOCtrTypeState);
    return rtval;
}

Std_ReturnType Interface_DID4367_IoCtrCallback(E_IOCtrType IOCtrTypeState)
{
    Std_ReturnType rtval = E_OK;
    rtval = IOCtr_4367_Cbk(IOCtrTypeState);
    return rtval;
}

Std_ReturnType Interface_DID43A9_IoCtrCallback(E_IOCtrType IOCtrTypeState)
{
    Std_ReturnType rtval = E_OK;
    rtval = IOCtr_43A9_Cbk(IOCtrTypeState);
    return rtval;
}

Std_ReturnType Interface_DID7022_IoCtrCallback(E_IOCtrType IOCtrTypeState)
{
    Std_ReturnType rtval = E_OK;
    rtval = IOCtr_7022_Cbk(IOCtrTypeState);
    return rtval;
}

Std_ReturnType Interface_GetDidIoctrMask(uint8_t DidNameId, uint8_t *Mask)
{
    const S_DidConfig *DidConfig = NULL;
    DidConfig = GetDidConfig(DidNameId);

    if (DidConfig->IoCtrInfo == NULL)
        return E_NOT_OK;

    if (DidConfig->IoCtrInfo->IoCtrlMaskSupport == E_IoCtrlMaskSupport_MaskAtStartByte)
        *Mask = DidConfig->IoCtrInfo->DidIOCtrlDataSrc[0];
    else if (DidConfig->IoCtrInfo->IoCtrlMaskSupport == E_IoCtrlMaskSupport_MaskAtEndByte)
        *Mask = DidConfig->IoCtrInfo->DidIOCtrlDataSrc[(DidConfig->DidDataLength)];
    else
        return E_NOT_OK;

    return E_OK;
}

Std_ReturnType Interface_GetDidIoctrState(uint8_t DidNameId, E_IOCtrType *IoctrState)
{
    const S_DidConfig *DidConfig = NULL;

    DidConfig = GetDidConfig(DidNameId);

    if (DidConfig->IoCtrInfo == NULL)
        return E_NOT_OK;

    *IoctrState = DidConfig->IoCtrInfo->CurIoCtrState;

    return E_OK;
}

Std_ReturnType Interface_GetDidSignalIoctrData(uint16_t DidSignalID, uint32_t *val)
{
    Std_ReturnType rtval = E_OK;
    const S_DidSignal *DidSignal = NULL;

    DidSignal = GetDidSignal(DidSignalID);

    if (DidSignal == NULL)
        return E_NOT_OK;

    rtval = GetSignalValue(DidSignal, val, E_DataType_0x2F);

    return rtval;
}

Std_ReturnType Interface_GetDidSignalData(uint16_t DidSignalID, uint32_t *val)
{
    Std_ReturnType rtval = E_OK;
    const S_DidSignal *DidSignal = NULL;

    DidSignal = GetDidSignal(DidSignalID);

    if (DidSignal == NULL)
        return E_NOT_OK;

    rtval = GetSignalValue(DidSignal, val, E_DataType_0x22_0x2E);

    return rtval;
}

Std_ReturnType Interface_SetDidSignalData(uint16_t DidSignalID, uint32_t val)
{
    const S_DidSignal *DidSignal = NULL;
    Std_ReturnType rtval;
    DidSignal = GetDidSignal(DidSignalID);
    if (DidSignal == NULL)
        return E_NOT_OK;

    rtval = SetSignalValue(DidSignal, val);

    return rtval;
}

Std_ReturnType DID_Interface_Mainfunction(uint8_t timebase)
{
    static Dcm_SesCtrlType CurSesCtrlType = DCM_DEFAULT_SESSION;
    Dcm_SesCtrlType SesCtrlTypetmp;

    Dcm_GetSesCtrlType(&SesCtrlTypetmp);

    if (SesCtrlTypetmp != CurSesCtrlType)
    {
        CurSesCtrlType = SesCtrlTypetmp;

        if (SesCtrlTypetmp == DCM_DEFAULT_SESSION)
        {
            /*从别的会话模式跳转到默认会话模式*/
            ResettAllIoctrToDefault();
        }
    }

    return E_OK;
}

Std_ReturnType Interface_DIDInit(void)
{
    uint8_t i = 0;
    uint8_t para1 = 0, para2 = 0;
    Std_ReturnType rtval = E_OK;
    const S_DidConfig *DidConfig = NULL;
    for (i = 0; i < DidConfig_NUM; i++)
    {
        DidConfig = GetDidConfig(i);

        if (DidConfig->Init != NULL)
        {
            rtval |= DidConfig->Init(para1, DidConfig->DidDataSrc, &para2);
        }
    }
    return rtval;
}
