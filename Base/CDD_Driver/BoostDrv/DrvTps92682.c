/*
 * DrvTps92682.c
 *
 *  Created on: 2024年2月20日
 *      Author: mihuiliang
 */

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HcmPlatform.h"
#include "AswInterfaceManager.h"
#include "DrvTps92682.h"
#include "Spi_Cfg.h"
#include "Spi.h"
#include "Os_Cfg.h"
#include "Os.h"
/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
static Std_ReturnType DrvTps92682_DeviceInit(void *ptr);
static Std_ReturnType DrvTps92682_DeviceDeInit(void *ptr);
static Std_ReturnType DrvTps92682_Read(void *ptr);
static Std_ReturnType DrvTps92682_Write(void *ptr);
static Std_ReturnType DrvTps92682_MainFunction(void *ptr);

static BoostDrv_Dev_OutputVoltage[MAX_BOOST_DRV_NUM][2] = {0};

static S_BoostDrv_Dev gs_BoostDrv_Dev[MAX_BOOST_DRV_NUM] = {
    {
        .BoostDrvDevType = E_BoostDrvDevType_Tps92682,
        .dev_id = E_BoostkNo1,
        .DeviceInit = DrvTps92682_DeviceInit,
        .DeviceDeInit = DrvTps92682_DeviceDeInit,
        .Read = DrvTps92682_Read,
        .Write = DrvTps92682_Write,
        .MainFunction = DrvTps92682_MainFunction,
        .ptNext = NULL,
    },
};
static uint8 Tps92682LostConfigFlag[MAX_BOOST_DRV_NUM] = {0};
static uint8 Tps92682LostComFlag[MAX_BOOST_DRV_NUM] = {0};

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
static S_BoostDrv_Dev *GetBoostDrvDev(E_BoostkNo BoostkNo)
{
    uint8_t i = 0;

    for (i = 0; i < MAX_BOOST_DRV_NUM; i++)
    {
        if (gs_BoostDrv_Dev[i].dev_id == BoostkNo)
            return &gs_BoostDrv_Dev[i];
    }
    return NULL;
}

static void Boost_DelayUs(uint32_t uiTime)
{
    uint32_t uiLoop = 0;
    for (uiLoop = 0; uiLoop < uiTime; uiLoop++)
        ;
}

static Std_ReturnType Boost_Write(uint8_t dev_id, uint8_t ucReg, uint8_t ucRegData)
{
    Std_ReturnType rtval = E_OK;
    uint8_t usTxSpiData[2] = {0};
    uint8_t usRxSpiData[2] = {0};
    if (ucReg < 0x27)
    {
        uint8_t i = 0;
        uint8_t address = ((ucReg << 1) & (~0x81)) | 0x80;
        uint8_t data = ucRegData;
        uint8_t PAR = (address >> 1) & 0x01;

        for (i = 2; i < 8; i++)
        {
            PAR = (~((address >> i) ^ PAR)) & 0X01;
        }

        for (i = 0; i < 8; i++)
        {
            PAR = (~((data >> i) ^ PAR)) & 0X01;
        }
        address += (~PAR) & 0x01;

        usTxSpiData[0] = data;
        usTxSpiData[1] = address;
        GetResource(OsResource_BoostBuckSpi);
        Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_Boost, usTxSpiData, usRxSpiData, 2);
        Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_Boost);
        ReleaseResource(OsResource_BoostBuckSpi);
#if 0
		Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_Boost,usTxSpiData,usRxSpiData,2);
		Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_Boost);
#endif

        if (((usRxSpiData[1] & 0x80) != 0x80) && ((usRxSpiData[1] & 0x40) == 0x40))
        {
            /* Spi Success*/
            rtval = E_OK;
        }
        else
        {
            rtval = E_NOT_OK;
        }
    }
    else
    {
        /* Spi Error*/
        rtval = E_NOT_OK;
    }
    return rtval;
}

static Std_ReturnType Boost_Read(uint8_t dev_id, uint8_t ucReg, uint8_t *pucRegData)
{
    Std_ReturnType rtval = E_OK;
    uint8_t usTxSpiData[2] = {0};
    uint8_t usRxSpiData[2] = {0};
    if (ucReg < 0x27)
    {
        uint8_t i = 0;
        uint8_t address = (ucReg << 1) & (~0x81);
        uint8_t data = 0x00;
        uint8_t PAR = (address >> 1) & 0x01;

        for (i = 2; i < 8; i++)
        {
            PAR = (~((address >> i) ^ PAR)) & 0X01;
        }

        for (i = 0; i < 8; i++)
        {
            PAR = (~((data >> i) ^ PAR)) & 0X01;
        }
        address += (~PAR) & 0x01;

        usTxSpiData[0] = data;
        usTxSpiData[1] = address;
        GetResource(OsResource_BoostBuckSpi);
        Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_Boost, usTxSpiData, usRxSpiData, 2);
        Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_Boost);

        Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_Boost);

        ReleaseResource(OsResource_BoostBuckSpi);
        if (((usRxSpiData[1] & 0x80) == 0) && (((usRxSpiData[1] >> 2) & 0x18) == 0x18))
        {
            /* Spi Success*/
            rtval = E_OK;
            *pucRegData = usRxSpiData[0];
        }
        else
        {
            rtval = E_NOT_OK;
            *pucRegData = (uint8_t)0x00;
        }
    }
    else
    {
        /* Spi Error*/
        rtval = E_NOT_OK;
    }

    return rtval;
}

static Std_ReturnType SetTps92682OutputVoltage(E_BoostkNo BoostkNo, uint8_t voltage)
{
    Std_ReturnType rtval = E_OK;
    S_BoostDrv_Dev *BoostDrv_Dev;
    uint8_t ucV1Volt = voltage;
    uint8_t ucV2Volt = voltage;

    uint16_t ucLoop = 0;
    uint16_t ucPreData = 0;
    uint16_t ucSetData = 0;

    BoostDrv_Dev = GetBoostDrvDev(BoostkNo);
    if (BoostDrv_Dev == NULL)
        return E_NOT_OK;

    if (ucV1Volt != BoostDrv_Dev_OutputVoltage[BoostDrv_Dev->dev_id][0])
    {
        ucPreData = (uint16_t)(BoostDrv_Dev_OutputVoltage[BoostDrv_Dev->dev_id][0] * (255.0 * BOOST_CHANNEL1_RDOWN / (BOOST_CHANNEL1_RUP + BOOST_CHANNEL1_RDOWN) / 2.4));
        ucSetData = (uint16_t)(ucV1Volt * (255.0 * BOOST_CHANNEL1_RDOWN / (BOOST_CHANNEL1_RUP + BOOST_CHANNEL1_RDOWN) / 2.4));

        if (ucSetData >= 255)
        {
            ucSetData = 255;
        }

        for (ucLoop = ucPreData; ucLoop < ucSetData; ucLoop += 15)
        {
            rtval |= Boost_Write(BoostDrv_Dev->dev_id, REG_CH1IADJ, (uint8_t)ucLoop);
            Boost_DelayUs(0xFF);
        }
        rtval |= Boost_Write(BoostDrv_Dev->dev_id, REG_CH1IADJ, (uint8_t)ucSetData);
        if (rtval == E_OK)
            BoostDrv_Dev_OutputVoltage[BoostDrv_Dev->dev_id][0] = ucV1Volt;
    }

    if (ucV2Volt != BoostDrv_Dev_OutputVoltage[BoostDrv_Dev->dev_id][1])
    {
        ucPreData = (uint16_t)(BoostDrv_Dev_OutputVoltage[BoostDrv_Dev->dev_id][1] * (255.0 * BOOST_CHANNEL2_RDOWN / (BOOST_CHANNEL2_RUP + BOOST_CHANNEL2_RDOWN) / 2.4));
        ucSetData = (uint16_t)(ucV2Volt * (255.0 * BOOST_CHANNEL2_RDOWN / (BOOST_CHANNEL2_RUP + BOOST_CHANNEL2_RDOWN) / 2.4));

        if (ucSetData >= 255)
        {
            ucSetData = 255;
        }

        for (ucLoop = ucPreData; ucLoop < ucSetData; ucLoop += 15)
        {
            rtval |= Boost_Write(BoostDrv_Dev->dev_id, REG_CH2IADJ, (uint8_t)ucLoop);
            Boost_DelayUs(0xFF);
        }
        rtval |= Boost_Write(BoostDrv_Dev->dev_id, REG_CH2IADJ, (uint8_t)ucSetData);
        if (rtval == E_OK)
            BoostDrv_Dev_OutputVoltage[BoostDrv_Dev->dev_id][1] = ucV2Volt;
    }
    return rtval;

    return rtval;
}

static Std_ReturnType DrvTps92682_DeviceInit(void *ptr)
{
    Std_ReturnType rtval = E_OK;
    S_BoostDrv_Dev *BoostDrv_Dev;
    uint8_t temp = 0;
    S_BoostDataPackets *BoostDataPackets;
    S_BoostInitDataSrc *BoostInitDataSrc;

    BoostDataPackets = (S_BoostDataPackets *)ptr;

    if (BoostDataPackets->BoostDataTypes != E_BoostDataType_BoostInit)
        return E_NOT_OK;

    BoostInitDataSrc = (S_BoostInitDataSrc *)(BoostDataPackets->datasrc);

    BoostDrv_Dev = GetBoostDrvDev(BoostInitDataSrc->BoostkNo);
    if (BoostDrv_Dev == NULL)
        return E_NOT_OK;

    Boost_Write(BoostDrv_Dev->dev_id, REG_RESET, 0xC3);
    Boost_Write(BoostDrv_Dev->dev_id, REG_SWDIV, 0x05);     /*0x05, 开关频率200k*/
    Boost_Write(BoostDrv_Dev->dev_id, REG_ISLOPE, 0x22);    /*0x22, 斜坡补偿100mV*/
    Boost_Write(BoostDrv_Dev->dev_id, REG_ILIM, 0x5A);      /*0x5A, 关断电压150mV*/
    Boost_Write(BoostDrv_Dev->dev_id, REG_OV, 0xFF);
    Boost_Write(BoostDrv_Dev->dev_id, REG_FM, 0x25);
    Boost_Write(BoostDrv_Dev->dev_id, REG_FEN1, 0x3F);
    Boost_Write(BoostDrv_Dev->dev_id, REG_FEN2, 0x3F);
    Boost_Write(BoostDrv_Dev->dev_id, REG_LHCFG, 0xA3);
    Boost_Write(BoostDrv_Dev->dev_id, REG_LHCH1IADJ, 0xFF);
    Boost_Write(BoostDrv_Dev->dev_id, REG_LHCH2IADJ, 0xFF);
    Boost_Write(BoostDrv_Dev->dev_id, REG_CFG1, REG_CFG1_VAL);  /*0xA3*/
    Boost_Write(BoostDrv_Dev->dev_id, REG_CH1IADJ, 0x0A);
    Boost_Write(BoostDrv_Dev->dev_id, REG_CH2IADJ, 0x0A);
    Boost_Read(BoostDrv_Dev->dev_id, REG_FLT1, &temp);
    Boost_Read(BoostDrv_Dev->dev_id, REG_FLT2, &temp);
    Boost_Write(BoostDrv_Dev->dev_id, REG_EN, 0xB3);            /*0xB3*/

    BoostDrv_Dev_OutputVoltage[BoostInitDataSrc->BoostkNo][0] = 0;
    BoostDrv_Dev_OutputVoltage[BoostInitDataSrc->BoostkNo][1] = 0;
    rtval |= SetTps92682OutputVoltage(BoostDrv_Dev->dev_id, BoostInitDataSrc->InitVoltage);

    Boost_Read(BoostDrv_Dev->dev_id, REG_CFG1, &temp);
    if (temp != REG_CFG1_VAL)
    {
        rtval = E_NOT_OK;
    }
    Boost_Read(BoostDrv_Dev->dev_id, REG_CH1IADJ, &temp);
    Boost_Read(BoostDrv_Dev->dev_id, REG_CH2IADJ, &temp);

    return rtval;
}
static Std_ReturnType DrvTps92682_DeviceDeInit(void *ptr)
{
    Std_ReturnType rtval = E_OK;

    return rtval;
}
static Std_ReturnType DrvTps92682_Read(void *ptr)
{
    Std_ReturnType rtval = E_OK;
    S_BoostDiagStateDataSrc *BoostDiagStateDataSrc;
    S_BoostDataPackets *BoostDataPackets;
    BoostDataPackets = (S_BoostDataPackets *)ptr;
    switch (BoostDataPackets->BoostDataTypes)
    {
    case E_BoostDataType_BoostDiagState:
        BoostDiagStateDataSrc = (S_BoostDiagStateDataSrc *)(BoostDataPackets->datasrc);
        if (Tps92682LostConfigFlag[BoostDiagStateDataSrc->BoostkNo] == 1)
            BoostDiagStateDataSrc->BoostDiagState.Bits.LostCfg = 1;
        else
            BoostDiagStateDataSrc->BoostDiagState.Bits.LostCfg = 0;

        if (Tps92682LostComFlag[BoostDiagStateDataSrc->BoostkNo] == 1)
            BoostDiagStateDataSrc->BoostDiagState.Bits.LostCom = 1;
        else
            BoostDiagStateDataSrc->BoostDiagState.Bits.LostCom = 0;
        break;
    default:
        rtval = E_NOT_OK;
        break;
    }

    return rtval;
}
static Std_ReturnType DrvTps92682_Write(void *ptr)
{
    Std_ReturnType rtval = E_OK;
    S_BoostDiagStateDataSrc *BoostDiagStateDataSrc;
    S_BoostDataPackets *BoostDataPackets;

    BoostDataPackets = (S_BoostDataPackets *)ptr;

    switch (BoostDataPackets->BoostDataTypes)
    {
    case E_BoostDataType_BoostOutputVoltage:
        rtval |= SetTps92682OutputVoltage(((S_BoostOutputVoltageDataSrc *)BoostDataPackets->datasrc)->BoostkNo, ((S_BoostOutputVoltageDataSrc *)BoostDataPackets->datasrc)->Voltage);
        break;
    case E_BoostDataType_BoostDiagState:
        BoostDiagStateDataSrc = (S_BoostDiagStateDataSrc *)(BoostDataPackets->datasrc);
        if (Tps92682LostConfigFlag[BoostDiagStateDataSrc->BoostkNo] == 1)
            BoostDiagStateDataSrc->BoostDiagState.Bits.LostCfg = 1;
        else
            BoostDiagStateDataSrc->BoostDiagState.Bits.LostCfg = 0;

        if (Tps92682LostComFlag[BoostDiagStateDataSrc->BoostkNo] == 1)
            BoostDiagStateDataSrc->BoostDiagState.Bits.LostCom = 1;
        else
            BoostDiagStateDataSrc->BoostDiagState.Bits.LostCom = 0;
        break;
    default:
        rtval = E_NOT_OK;
        break;
    }

    return rtval;
}
static Std_ReturnType DrvTps92682_MainFunction(void *ptr)
{
    Std_ReturnType rtval = E_OK;
    S_BoostDataPackets *BoostDataPackets;
    S_BoostMainFuncDataSrc *BoostMainFuncDataSrc;
    uint8_t readdata;

    BoostDataPackets = (S_BoostDataPackets *)ptr;

    if (BoostDataPackets->BoostDataTypes != E_BoostDataType_BoostMainFunction)
        return E_NOT_OK;

    BoostMainFuncDataSrc = (S_BoostMainFuncDataSrc *)(BoostDataPackets->datasrc);

    if (Boost_Read(BoostMainFuncDataSrc->BoostkNo, REG_CFG1, &readdata) == E_OK)
    {
        Tps92682LostComFlag[BoostMainFuncDataSrc->BoostkNo] = 0;
        if (readdata != REG_CFG1_VAL)
            Tps92682LostConfigFlag[BoostMainFuncDataSrc->BoostkNo] = 1;
        else
            Tps92682LostConfigFlag[BoostMainFuncDataSrc->BoostkNo] = 0;
    }
    else
    {
        Tps92682LostComFlag[BoostMainFuncDataSrc->BoostkNo] = 1;
    }

    return rtval;
}

/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
Std_ReturnType CddDriver_DrvTps92682Init(void)
{
    Std_ReturnType rtval = E_OK;
    uint8_t i = 0;

    for (i = 0; i < MAX_BOOST_DRV_NUM; i++)
    {
        rtval |= BoostDrvDev_Register(&gs_BoostDrv_Dev[i]);
    }

    return rtval;
}
