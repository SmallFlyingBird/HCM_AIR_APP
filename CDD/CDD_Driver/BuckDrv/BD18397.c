/***
Date: 2024/01/08
Auther: yinjianye
***/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Platform_Types.h"
#include "Std_Types.h"
#include "BD18397.h"
#include "Spi.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define BD18397_C_DRIVER_MAJOR_VERSION 0
#define BD18397_C_DRIVER_MINOR_VERSION 0
#if (BD18397_C_DRIVER_MAJOR_VERSION != BD18397_H_DRIVER_MAJOR_VERSION)
#error "BD18397.c and BD18397.h have different version id"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
const uint8 id_SpiNo_mapping[2] = { SpiConf_SpiChannel_SpiChannel_Buck1,
                                    SpiConf_SpiChannel_SpiChannel_Buck2,
};

const uint8 ADNode_mapping[10] = {
    A_D_Thermal, A_D_VSNSN1, A_D_VSNSN2, A_D_VSNSN3, A_D_V5VEXT};
/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
static uint8 BD18397LostConfigFlag[2] = { 0, 0};
static uint8 BD18397LostComFlag[2] = { 0, 0};

/*BD18397 ADC node buffer*/
static BD18397_ADCStoreType BD18397_ADCOrignalval[2] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};


#if BD18397_MODIFY_MHL
/*ADC开启转换标记位*/
static uint8_t BD18397_ADCStartConvertFlag[2] = {0, 0};
#endif

/*BD18397 register data buffer*/
static BD18397_RegDataType BD18397RegData[2] = {
    {/*INIT VAL*/
     /*WLOCK=ENALBE(1); WDTEN=ENALBE(1); RDMODE=8bit(0); SLEEP=NORMAL(0); SWRST=NORMAL(0)*/
     .BD18397_SYSSET_Data = 0x80,
     /*FLTRST=REQ_CLEAR(1); LEDOCPLAT=AUTO_CLEAR(0),SWOCPLAT(0)*/
     .BD18397_ERRSET1_Data = 0x40,
     /*ISETDIM=BY_ISET_REG(0); PWMDIM=203Hz(1); PHEN=NO_SHIFT(0)*/
     .BD18397_DIMSET_Data = 0x10,
     /*ISET=0*/
     .BD18397_ISET1H_Data = 0x0,
     .BD18397_ISET1L_Data = 0x00,
     .BD18397_ISET2H_Data = 0x0,
     .BD18397_ISET2L_Data = 0x00,
     .BD18397_ISET3H_Data = 0x0,
     .BD18397_ISET3L_Data = 0x00,
     /*DPWM=100%*/
     .BD18397_DPWM1H_Data = 0xFF,
     .BD18397_DPWM1L_Data = 0x03,
     .BD18397_DPWM2H_Data = 0xFF,
     .BD18397_DPWM2L_Data = 0x03,
     .BD18397_DPWM3H_Data = 0xFF,
     .BD18397_DPWM3L_Data = 0x03,
     /*GM=1200us(0); TON1=400Khz(7)*/
     .BD18397_DCDCSET1_Data = 0x07,
     /*TON2=400Khz(7)*/
     .BD18397_DCDCSET2_Data = 0x07,
     /*TON3=400Khz(7)*/
     .BD18397_DCDCSET3_Data = 0x07,
     /*VMODE=CURRENT_MODE(0); SSCG=536Hz(5)*/
     .BD18397_DCDCSET4_Data = 0x05,
     /*CHEN=DISABLE(0); PWMDIM=ENABLE(1)*/
     .BD18397_CHEN_Data = 0x70,
     /*ADMODE=AUTOMATIC(1); VMONSEL=Thermal(0)*/
     .BD18397_ADSEL_Data = 0x10,
     /**/
     .BD18397_VMONH_Data = 0x00,
     .BD18397_VMONL_Data = 0x00,
     /**/
     .BD18397_ERRSTALL_Data = 0x00,
     .BD18397_ERRST1_Data = 0x00,
     .BD18397_ERRST2_Data = 0x00,
     .BD18397_ERRST3_Data = 0x00},
    {/*INIT VAL*/
     /*WLOCK=ENALBE(1); WDTEN=ENALBE(1); RDMODE=8bit(0); SLEEP=NORMAL(0); SWRST=NORMAL(0)*/
     .BD18397_SYSSET_Data = 0x80,
     /*FLTRST=REQ_CLEAR(1); LEDOCPLAT=AUTO_CLEAR(0),SWOCPLAT(0)*/
     .BD18397_ERRSET1_Data = 0x40,
     /*ISETDIM=BY_ISET_REG(0); PWMDIM=203Hz(1); PHEN=NO_SHIFT(0)*/
     .BD18397_DIMSET_Data = 0x10,
     /*ISET=0*/
     .BD18397_ISET1H_Data = 0x0,
     .BD18397_ISET1L_Data = 0x00,
     .BD18397_ISET2H_Data = 0x0,
     .BD18397_ISET2L_Data = 0x00,
     .BD18397_ISET3H_Data = 0x0,
     .BD18397_ISET3L_Data = 0x00,
     /*DPWM=0%*/
     .BD18397_DPWM1H_Data = 0xFF,
     .BD18397_DPWM1L_Data = 0x03,
     .BD18397_DPWM2H_Data = 0xFF,
     .BD18397_DPWM2L_Data = 0x03,
     .BD18397_DPWM3H_Data = 0xFF,
     .BD18397_DPWM3L_Data = 0x03,
     /*GM=1200us(0); TON1=400Khz(7)*/
     .BD18397_DCDCSET1_Data = 0x07,
     /*TON2=400Khz(7)*/
     .BD18397_DCDCSET2_Data = 0x07,
     /*TON3=400Khz(7)*/
     .BD18397_DCDCSET3_Data = 0x07,
     /*VMODE=CURRENT_MODE(0); SSCG=536Hz(5)*/
     .BD18397_DCDCSET4_Data = 0x05,
     /*CHEN=DISABLE(0); PWMDIM=ENABLE(1)*/
     .BD18397_CHEN_Data = 0x70,
     /*ADMODE=AUTOMATIC(1); VMONSEL=Thermal(0)*/
     .BD18397_ADSEL_Data = 0x10,
     /**/
     .BD18397_VMONH_Data = 0x00,
     .BD18397_VMONL_Data = 0x00,
     /**/
     .BD18397_ERRSTALL_Data = 0x00,
     .BD18397_ERRST1_Data = 0x00,
     .BD18397_ERRST2_Data = 0x00,
     .BD18397_ERRST3_Data = 0x00},
};

/*CRC Table init flag*/
static uint8 crc_table_init_flag = 0;
/*CRC table*/
static uint8 crc_table[256];
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/**
 * Std_ReturnType BD18397Transmit()
 * this function is used for IC data transmit.
 * When isContinuous is 1, Read function will return data in next transmit function.
 * eg: if you want read ch1-3 Current data, you can do like this:
 * 		transmit(Read_Ch1_CMD,NULL,1,1);
 * 		transmit(Read_Ch2_CMD,Ch1DataBuffer,1,1);
 * 		transmit(Read_Ch3_CMD,Ch2DataBuffer,1,1);
 * 		transmit(Read_Ch3_CMD,Ch3DataBuffer,1,1);
 * if you just read one thing, you can do like this:
 * 		transmit(Read_AD_CMD,ADBuffer,0,0);
 * transmit will send twice SPI CMD .
 * WARNING:YOU CAN NOT change RDMODE when you use Continuous. if you want 10bit, you need always use 10bit untill continuous read is done.
 * if ReceiveData is NULL_PTR, function will not retrieve data.
 *
 */
static Std_ReturnType BD18397Transmit(BD18397_TransType *TransData, BD18397_ReceiveType *ReceiveData, uint8 is10bit, uint8 isContinuous);

/**
 * Std_ReturnType BD18397GetCRC(void *IC)
 * this function can only be called by BD18397Transmit().
 */
static Std_ReturnType BD18397GetCRC(void *IC);

/**
 * Std_ReturnType BD18397CaculateCRC(void *IC);
 * this function can only be called by BD18397Transmit();
 */
static Std_ReturnType BD18397CaculateCRC(void *IC);

/**
 * Std_ReturnType BD18397CRCTableInit();
 * this function can only be called by GetCRC or CaclateCRC;
 */
static Std_ReturnType BD18397CRCTableInit();

/**
 * uint8 BD18397CreateCRCTable(uint8 data);
 * this function can only be called by BD18397CRCTableInit();
 */
static uint8 BD18397CreateCRCTable(uint8 data);
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
static uint8 BD18397CreateCRCTable(uint8 data)
{
    int i = 0;
    uint8 result = data;

    for (i = 0; i < 8; i++)
    {
        /*判断8位内存中的最高位是否是1*/
        uint8 h = (result & 0x80);
        if (h == 0x80)
        {
            /*如果是1，则左移1位，并与生成式进行异或，并保存结果中*/
            result = ((result << 1) & 0xFF);
            result = (result ^ CRC_MUL);
        }
        else
        {
            /*如果是0，则左移1位，不进行异或运算，并保存在结果中*/
            result = ((result << 1) & 0xFF);
        }
    }
    return result;
}
static Std_ReturnType BD18397CRCTableInit()
{
    /*using for generate CRC table*/
    uint16 i = 0;
    for (i = 0; i < 256; i++)
    {
        crc_table[i] = BD18397CreateCRCTable(i);
    }
    return E_OK;
}

/**
 * Std_ReturnType BD18397Transmit()
 * this function is used for IC data transmit.
 * 10bitMode is not support for this version
 * WARNING:BD1839x do not support Continuous read write.
 *
 */
static Std_ReturnType BD18397Transmit(BD18397_TransType *TransData, BD18397_ReceiveType *ReceiveData, uint8 is10bit, uint8 isContinuous)
{
    Std_ReturnType res = E_OK;
    uint8 command[4] = {0x00, 0x00, 0x00};
    uint8 receive[4] = {0x00, 0x00, 0x00};
    /*if there is a read cmd*/
    if ((TransData->RWAddr & 0x80) == 0)
    {
#if 0
		BD18397SetRDMODE(TransData->ID, is10bit);
#endif
        /*RDMODE complete*/
        /*Now need transfer data*/
        BD18397GetCRC(TransData);

        command[2] = TransData->RWAddr;
        command[1] = TransData->data;
        command[0] = TransData->CRC;
#if BD18397CONFIG_OS_RESOURCE_USED
        /*if using OS resource to protected SPI*/
        // GetResource(OsResource_BD18397Spi);
#endif
        Spi_SetupEB(TransData->SpiChNo, command, receive, 4);
        res |= Spi_SyncTransmit(TransData->SpiChNo);
        if (0 == isContinuous)
        {
            /*transmit twice*/
            command[2] = 0xFF;
            command[1] = 0xFF;
            command[0] = 0xFF;
            res |= Spi_SyncTransmit(TransData->SpiChNo);
        }
#if BD18397CONFIG_OS_RESOURCE_USED
        /*if using OS resource to protected SPI*/
        // ReleaseResource(OsResource_BD18397Spi);
#endif
        if (NULL_PTR != ReceiveData)
        {
            /*need retrive data*/
            /*TODO: caculate CRC*/
            ReceiveData->data1 = receive[2];
            ReceiveData->data2 = receive[1];
            ReceiveData->CRC = receive[0];
#if 1
            if (E_NOT_OK == BD18397CaculateCRC(ReceiveData))
            {
                /*CRC not matched*/
                res = E_NOT_OK;
            };
#endif
        }
    }
    else
    {
        /* there is a write cmd*/
        res |= BD18397GetCRC(TransData);
        command[2] = TransData->RWAddr;
        command[1] = TransData->data;
        command[0] = TransData->CRC;
/*TODO: */
#if BD18397CONFIG_OS_RESOURCE_USED
        /*if using OS resource to protected SPI*/
        // GetResource(OsResource_BD18397Spi);
#endif
        Spi_SetupEB(TransData->SpiChNo, command, receive, 4);
        res |= Spi_SyncTransmit(TransData->SpiChNo);
#if BD18397CONFIG_OS_RESOURCE_USED
        /*if using OS resource to protected SPI*/
        // ReleaseResource(OsResource_BD18397Spi);
#endif
        if (ReceiveData != NULL_PTR)
        {
            ReceiveData->data1 = receive[2];
            ReceiveData->data2 = receive[1];
            ReceiveData->CRC = receive[0];
        }
    }
    return res;
}

static Std_ReturnType BD18397GetCRC(void *IC)
{
    uint8 result = 0;
    BD18397_TransType *ptr = IC;
    if (0 == crc_table_init_flag)
    {
        BD18397CRCTableInit();
        crc_table_init_flag = 1;
    }
    /*caculate */
    result = crc_table[ptr->RWAddr];
    result = crc_table[result ^ (ptr->data)];
    ptr->CRC = result;
    return E_OK;
}

static Std_ReturnType BD18397CaculateCRC(void *IC)
{
    uint8 result = 0;
    BD18397_ReceiveType *ptr = IC;
    if (0 == crc_table_init_flag)
    {
        BD18397CRCTableInit();
        crc_table_init_flag = 1;
    }
    /*caculate */
    result = crc_table[ptr->data1];
    result = crc_table[result ^ (ptr->data2)];
    if (ptr->CRC == result)
    {
        return E_OK;
    }
    else
    {
        return E_NOT_OK;
    }
}
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
 * BD18397SetRDMODE is used for change RDMODE, be caution you need know what you want to do
 * this function can not return E_NOT_OK, expecte SPI err.
 * if present RDMODE is equal to is10bit, function do nothing, and return E_OK;
 * */
Std_ReturnType BD18397SetRDMODE(uint8 id, uint8 is10bit)
{
    Std_ReturnType res = E_OK;
    uint8 RDMode = ((BD18397RegData[id].BD18397_SYSSET_Data & 0x20) >> 5);
    if (RDMode != is10bit)
    {
        /*if RDMODE!=rdmode we want*/
        /*Create changeRDMode transmit str*/
        BD18397_TransType changeRDMode = {
            .RWAddr = 0x80 | BD18397_SYSSET,
            .CRC = 0};
        if (1 == is10bit)
        {
            /* change it to 10bit mode*/
            changeRDMode.data = BD18397RegData[id].BD18397_SYSSET_Data | (0x20);
        }
        else
        {
            /*change it to 8bit mode*/
            changeRDMode.data = BD18397RegData[id].BD18397_SYSSET_Data & (~(0x20));
        }
        /*set SYSSET RDMODE*/
        res |= BD18397Transmit(&changeRDMode, NULL_PTR, 0, 0);
        BD18397RegData[id].BD18397_SYSSET_Data = changeRDMode.data;
    }
    return res;
}

/**
 * 函数功能 设置通道电流
 * 输入：
 * id：buck地址，用于有多个buck芯片时，通过地址指定哪一个芯片
 * hw_ch：buck通道：18397可选0 1，18398可选0 1 2
 * Rsnsx：SNSNx和SNSPx之间的电阻，单位mΩ，默认100
 * Current：设置电流值，单位mA
 */
Std_ReturnType BD18397SetICH(uint8 id, uint8 hw_ch, uint16 Rsnsx, uint16 Current)
{
    Std_ReturnType res = E_OK;
    /*TODO: need verify data overflow*/
    uint16 ICH90 = (uint16)(409.6 * (0.2 + (12 * (((double)Current) / 1000)) * (((double)Rsnsx) / 1000.0)));
    uint8 ICHH = (uint8)(ICH90 >> 2);
    uint8 ICHL = (uint8)(ICH90 & 0x0003);
    BD18397_TransType WriteCMD = {
        .ID = id,
        .RWAddr = 0x80 | (BD18397_ISET1H + (2 * hw_ch)),
        .data = ICHH,
        .SpiChNo = id_SpiNo_mapping[id],
    };
    res |= BD18397Transmit(&WriteCMD, NULL_PTR, 0, 0);
    WriteCMD.RWAddr = 0x80 | (BD18397_ISET1L + (2 * hw_ch));
    WriteCMD.data = ICHL;
    res |= BD18397Transmit(&WriteCMD, NULL_PTR, 0, 0);
    /*now reflesh reg data buffer*/
    switch (hw_ch)
    {
    case 0 /* hw_ch==0 */:
        /* code */
        BD18397RegData[id].BD18397_ISET1H_Data = ICHH;
        BD18397RegData[id].BD18397_ISET1L_Data = ICHL;
        break;
    case 1 /* hw_ch==1 */:
        /* code */
        BD18397RegData[id].BD18397_ISET2H_Data = ICHH;
        BD18397RegData[id].BD18397_ISET2L_Data = ICHL;
        break;

    case 2 /* hw_ch==2 */:
        /* code */
        BD18397RegData[id].BD18397_ISET3H_Data = ICHH;
        BD18397RegData[id].BD18397_ISET3L_Data = ICHL;
        break;

    default:
        break;
    }

    return res;
}

/**
 * 函数功能 设置通道电流占空比
 * 输入 ：
 * id buck地址，用于有多个buck芯片时，通过地址指定哪一个芯片
 * hw_ch：buck通道：18397可选0 1，18398可选0 1 2
 * PWM 电流输出占空比，取值1~100，取值100时按设置的电流值输出
 **/
Std_ReturnType BD18397SetPWM(uint8 id, uint8 hw_ch, uint8 PWM)
{
    Std_ReturnType res = E_OK;
    /*in case of overflow*/
    if (PWM > 100)
    {
        PWM = 100;
    }
    /*caculate PWMH and PWML*/
    /*TODO: need verify caculate value*/
    uint8 PWMH = (uint8)(((uint16)(PWM * 10.23)) >> 2);
    uint8 PWML = (uint8)(((uint16)(PWM * 10.23)) & 0x03);
    BD18397_TransType WriteCMD = {
        .ID = id,
        .RWAddr = 0x80 | (BD18397_DPWM1H + (2 * hw_ch)),
        .data = PWMH,
        .SpiChNo = id_SpiNo_mapping[id],
    };
    res |= BD18397Transmit(&WriteCMD, NULL_PTR, 0, 0);
    WriteCMD.RWAddr = 0x80 | (BD18397_DPWM1L + (2 * hw_ch));
    WriteCMD.data = PWML;
    res |= BD18397Transmit(&WriteCMD, NULL_PTR, 0, 0);
    /*now reflesh reg data buffer*/
    switch (hw_ch)
    {
    case 0 /* hw_ch==0 */:
        /* code */
        BD18397RegData[id].BD18397_DPWM1H_Data = PWMH;
        BD18397RegData[id].BD18397_DPWM1L_Data = PWML;
        break;
    case 1 /* hw_ch==1 */:
        /* code */
        BD18397RegData[id].BD18397_DPWM2H_Data = PWMH;
        BD18397RegData[id].BD18397_DPWM2L_Data = PWML;
        break;

    case 2 /* hw_ch==2 */:
        /* code */
        BD18397RegData[id].BD18397_DPWM3H_Data = PWMH;
        BD18397RegData[id].BD18397_DPWM3L_Data = PWML;
        break;

    default:
        break;
    }

    return res;
}

/**
 * 函数功能 设置通道输出开关
 * 输入 ：
 * id   ：buck地址，用于有多个buck芯片时，通过地址指定哪一个芯片
 * hw_ch：buck通道：18397可选0 1，18398可选0 1 2
 * isON ：1：通道输出  0：通道不输出
 **/
Std_ReturnType BD18397SetHwCHCtrl(uint8 id, uint8 hw_ch, uint8 isON)
{
    Std_ReturnType res = E_OK;
    BD18397_TransType WriteCMD = {
        .ID = id,
        .RWAddr = 0x80 | (BD18397_CHEN),
        .SpiChNo = id_SpiNo_mapping[id],
    };
    if (1 == isON)
    {
        WriteCMD.data = (BD18397RegData[id].BD18397_CHEN_Data) | (1 << hw_ch);
    }
    else
    {
        WriteCMD.data = (BD18397RegData[id].BD18397_CHEN_Data) & (~(1 << hw_ch));
    }
    res |= BD18397Transmit(&WriteCMD, NULL_PTR, 0, 0);
    BD18397RegData[id].BD18397_CHEN_Data = WriteCMD.data;
    return res;
}

/**
 * 函数功能 芯片初始化
 * 输入 ：
 * id   ：buck地址，用于有多个buck芯片时，通过地址指定哪一个芯片
 **/
Std_ReturnType BD18397Init(uint8 id)
{
    Std_ReturnType res = E_OK;
    /*SET SYSSET*/
    BD18397_TransType WriteCMD = {
        .ID = id,
        .SpiChNo = id_SpiNo_mapping[id],
    };
    /*SET SYSSET*/

    WriteCMD.data = BD18397RegData[id].BD18397_SYSSET_Data;
    WriteCMD.RWAddr = 0x80 | (BD18397_SYSSET);
    res |= BD18397Transmit(&WriteCMD, NULL_PTR, 0, 0);

    /*SET DCDC*/
    WriteCMD.data = BD18397RegData[id].BD18397_DCDCSET1_Data;
    WriteCMD.RWAddr = 0x80 | (BD18397_DCDCSET1);
    res |= BD18397Transmit(&WriteCMD, NULL_PTR, 0, 0);
    WriteCMD.data = BD18397RegData[id].BD18397_DCDCSET2_Data;
    WriteCMD.RWAddr = 0x80 | (BD18397_DCDCSET2);
    res |= BD18397Transmit(&WriteCMD, NULL_PTR, 0, 0);
    WriteCMD.data = BD18397RegData[id].BD18397_DCDCSET3_Data;
    WriteCMD.RWAddr = 0x80 | (BD18397_DCDCSET3);
    res |= BD18397Transmit(&WriteCMD, NULL_PTR, 0, 0);

    WriteCMD.data = BD18397RegData[id].BD18397_DCDCSET4_Data;
    WriteCMD.RWAddr = 0x80 | (BD18397_DCDCSET4);
    res |= BD18397Transmit(&WriteCMD, NULL_PTR, 0, 0);
    /*SET ISET*/
    WriteCMD.data = BD18397RegData[id].BD18397_ISET1H_Data;
    WriteCMD.RWAddr = 0x80 | (BD18397_ISET1H);
    res |= BD18397Transmit(&WriteCMD, NULL_PTR, 0, 0);
    WriteCMD.data = BD18397RegData[id].BD18397_ISET2H_Data;
    WriteCMD.RWAddr = 0x80 | (BD18397_ISET2H);
    res |= BD18397Transmit(&WriteCMD, NULL_PTR, 0, 0);
    WriteCMD.data = BD18397RegData[id].BD18397_ISET3H_Data;
    WriteCMD.RWAddr = 0x80 | (BD18397_ISET3H);
    res |= BD18397Transmit(&WriteCMD, NULL_PTR, 0, 0);
    WriteCMD.data = BD18397RegData[id].BD18397_ISET1L_Data;
    WriteCMD.RWAddr = 0x80 | (BD18397_ISET1L);
    res |= BD18397Transmit(&WriteCMD, NULL_PTR, 0, 0);
    WriteCMD.data = BD18397RegData[id].BD18397_ISET2L_Data;
    WriteCMD.RWAddr = 0x80 | (BD18397_ISET2L);
    res |= BD18397Transmit(&WriteCMD, NULL_PTR, 0, 0);
    WriteCMD.data = BD18397RegData[id].BD18397_ISET3L_Data;
    WriteCMD.RWAddr = 0x80 | (BD18397_ISET3L);
    res |= BD18397Transmit(&WriteCMD, NULL_PTR, 0, 0);

    /*SET PWM*/
    WriteCMD.data = BD18397RegData[id].BD18397_DPWM1H_Data;
    WriteCMD.RWAddr = 0x80 | (BD18397_DPWM1H);
    res |= BD18397Transmit(&WriteCMD, NULL_PTR, 0, 0);
    WriteCMD.data = BD18397RegData[id].BD18397_DPWM2H_Data;
    WriteCMD.RWAddr = 0x80 | (BD18397_DPWM2H);
    res |= BD18397Transmit(&WriteCMD, NULL_PTR, 0, 0);
    WriteCMD.data = BD18397RegData[id].BD18397_DPWM3H_Data;
    WriteCMD.RWAddr = 0x80 | (BD18397_DPWM3H);
    res |= BD18397Transmit(&WriteCMD, NULL_PTR, 0, 0);
    WriteCMD.data = BD18397RegData[id].BD18397_DPWM1L_Data;
    WriteCMD.RWAddr = 0x80 | (BD18397_DPWM1L);
    res |= BD18397Transmit(&WriteCMD, NULL_PTR, 0, 0);
    WriteCMD.data = BD18397RegData[id].BD18397_DPWM2L_Data;
    WriteCMD.RWAddr = 0x80 | (BD18397_DPWM2L);
    res |= BD18397Transmit(&WriteCMD, NULL_PTR, 0, 0);
    WriteCMD.data = BD18397RegData[id].BD18397_DPWM3L_Data;
    WriteCMD.RWAddr = 0x80 | (BD18397_DPWM3L);
    res |= BD18397Transmit(&WriteCMD, NULL_PTR, 0, 0);
    /*SET DIMSET*/
    WriteCMD.data = BD18397RegData[id].BD18397_DIMSET_Data;
    WriteCMD.RWAddr = 0x80 | (BD18397_DIMSET);
    res |= BD18397Transmit(&WriteCMD, NULL_PTR, 0, 0);

    /*SET ERRSET1*/
    WriteCMD.data = BD18397RegData[id].BD18397_ERRSET1_Data;
    WriteCMD.RWAddr = 0x80 | (BD18397_ERRSET1);
    res |= BD18397Transmit(&WriteCMD, NULL_PTR, 0, 0);
    /*ERRSET CLEAN finish, set errset to no request*/
    BD18397RegData[id].BD18397_ERRSET1_Data = BD18397RegData[id].BD18397_ERRSET1_Data & (~(0x40));

    /*SET CHEN*/
    WriteCMD.data = BD18397RegData[id].BD18397_CHEN_Data;
    WriteCMD.RWAddr = 0x80 | (BD18397_CHEN);
    res |= BD18397Transmit(&WriteCMD, NULL_PTR, 0, 0);

    BD18397SetADCNoteMode(0, ADNode_mapping[0], 0, 0);
    BD18397SetADCNoteMode(0, ADNode_mapping[1], 0, 0);
    BD18397SetADCNoteMode(0, ADNode_mapping[2], 0, 0);
    BD18397SetADCNoteMode(0, ADNode_mapping[3], 0, 0);
    BD18397SetADCNoteMode(1, ADNode_mapping[0], 0, 0);
    BD18397SetADCNoteMode(1, ADNode_mapping[1], 0, 0);
    BD18397SetADCNoteMode(1, ADNode_mapping[2], 0, 0);
    BD18397SetADCNoteMode(1, ADNode_mapping[3], 0, 0);
    return res;
}

/**
 * 函数功能 芯片去初始化
 * 输入 ：
 * id   ：buck地址，用于有多个buck芯片时，通过地址指定哪一个芯片
 **/
Std_ReturnType BD18397DeInit(uint8 id)
{
    Std_ReturnType res = E_OK;
    /*SET SYSSET*/
    BD18397_TransType WriteCMD = {
        .ID = id,
        .RWAddr = 0x80 | (BD18397_SYSSET),
        .SpiChNo = id_SpiNo_mapping[id],
        .data = 0x01};
    res |= BD18397Transmit(&WriteCMD, NULL_PTR, 0, 0);
    return res;
}

Std_ReturnType BD18397GetOutputFrequency(uint8 id, uint8 hw_ch, uint16 *OutputFrequency)
{
    Std_ReturnType res = E_OK;
    *OutputFrequency = 203;
    return res;
}

/**
 * 函数功能 读取通道电流占空比
 * 输入 ：
 * id buck地址，用于有多个buck芯片时，通过地址指定哪一个芯片
 * hw_ch：buck通道：18397可选0 1，18398可选0 1 2
 * PWMBuffer：放置当前读取的PWM值
*/
Std_ReturnType BD18397GetPWM(uint8 id, uint8 hw_ch, uint8 *PWMBuffer)
{
    Std_ReturnType res = E_OK;
    uint16 DPWMBuffer = 0;
    uint8 HighData = 0;
    uint8 LowData = 0;
    BD18397_TransType WriteCMD = {
        .ID = id,
        .RWAddr = (BD18397_DPWM1H + (2 * hw_ch)),
        .data = 0xFF,
        .SpiChNo = id_SpiNo_mapping[id],
    };
    BD18397_ReceiveType ReadCMD = {
        .ID = id,
        .data1 = 0,
        .data2 = 0,
        .CRC = 0};
    /*use 8bit mode*/
    res |= BD18397Transmit(&WriteCMD, &ReadCMD, 0, 0);
    HighData = ReadCMD.data2;
    WriteCMD.RWAddr = (BD18397_DPWM1L + (2 * hw_ch));
    res |= BD18397Transmit(&WriteCMD, &ReadCMD, 0, 0);
    LowData = ReadCMD.data2;
    switch (hw_ch)
    {
        case 0 /* hw_ch==0 */:
            /* code */
            BD18397RegData[id].BD18397_DPWM1H_Data = HighData;
            BD18397RegData[id].BD18397_DPWM1L_Data = LowData;
            break;
        case 1 /* hw_ch==1 */:
            /* code */
            BD18397RegData[id].BD18397_DPWM2H_Data = HighData;
            BD18397RegData[id].BD18397_DPWM2L_Data = LowData;
            break;
        case 2 /* hw_ch==2 */:
            /* code */
            BD18397RegData[id].BD18397_DPWM3H_Data = HighData;
            BD18397RegData[id].BD18397_DPWM3L_Data = LowData;
            break;
        default:
            break;
    }
    DPWMBuffer = (((uint16)HighData) << 2) | ((uint16)LowData & 0x0003);
    *PWMBuffer = (uint16)(((double)DPWMBuffer) * 100.0 / 1022.0);
    return res;
}

Std_ReturnType BD18397GetHwCHCtrl(uint8 id, uint8 hw_ch, E_ChannelState *isON)
{
    Std_ReturnType res = E_OK;
    uint8 isONState=0;
    BD18397_TransType WriteCMD = {
        .ID = id,
        .RWAddr = (BD18397_CHEN),
        .data = 0xFF,
        .SpiChNo = id_SpiNo_mapping[id],
    };
    BD18397_ReceiveType ReadCMD = {
        .ID = id,
        .data1 = 0,
        .data2 = 0,
        .CRC = 0};
    res |= BD18397Transmit(&WriteCMD, &ReadCMD, 0, 0);
    
    isONState = (ReadCMD.data2) & (1 << hw_ch);
    if(isONState == 1) *isON=CHANNEL_STATE_ON;
    else *isON=CHANNEL_STATE_OFF;

    BD18397RegData[id].BD18397_CHEN_Data = ReadCMD.data2;
    return res;
}

Std_ReturnType BD18397IsLostConfig(uint8 id, uint8 *isLostConfig)
{
    Std_ReturnType res = E_OK;
    BD18397_TransType WriteCMD = {
        .ID = id,
        .RWAddr = (BD18397_DIMSET),
        .data = 0xFF,
        .SpiChNo = id_SpiNo_mapping[id],
    };
    BD18397_ReceiveType ReadCMD = {
        .ID = id,
        .data1 = 0,
        .data2 = 0,
        .CRC = 0};
    res |= BD18397Transmit(&WriteCMD, &ReadCMD, 0, 0);
    if (res == E_OK)
    {
        if (ReadCMD.data2 != BD18397RegData[id].BD18397_DIMSET_Data)
        {
            /*Lost Configure*/
            *isLostConfig = 1;
        }
        else
        {
            *isLostConfig = 0;
        }
    }
    return res;
}

/**
 * 函数功能 芯片运行主功能，10ms执行一次，读取芯片通道输出电压值，判断输出是否正常
 * 输入 ：
 * id：buck地址，用于有多个buck芯片时，通过地址指定哪一个芯片 */
uint8 buftest[10]={0};
Std_ReturnType BD18397MainFun(uint8 id)
{
    Std_ReturnType res = E_OK;
    uint8 islostconfig;
    uint8 ch_en=0;
    BD18397_TransType WriteCMD = {
        .ID = id,
        .data = 0xFF,
        .SpiChNo = id_SpiNo_mapping[id],
    };
    BD18397_ReceiveType ReadCMD = {
        .ID = id,
        .data1 = 0,
        .data2 = 0,
        .CRC = 0};

    res |= BD18397IsLostConfig(id, &islostconfig);
    if (res == E_OK)
    {
        BD18397LostConfigFlag[id] = islostconfig;
    }

#if BD18397_MODIFY_MHL
    if (BD18397_ADCStartConvertFlag[id] == 1)
    {
        BD18397RegData[id].BD18397_VMONL_Data = 1;//取值范围 0 1 2 3  
        WriteCMD.RWAddr = (BD18397_VMONH);
        res |= BD18397Transmit(&WriteCMD, &ReadCMD, 0, 0);
        BD18397RegData[id].BD18397_VMONH_Data = ReadCMD.data2;
        if (res == E_OK)
        {
            BD18397_ADCOrignalval[id].data[ADNode_mapping[BD18397_ADCOrignalval[id].AdcStruct.ADSEL]] = (((uint16)(BD18397RegData[id].BD18397_VMONH_Data)) << 2) | ((uint16)(BD18397RegData[id].BD18397_VMONL_Data & 0x3));

//测试代码：
        if((id==0)&&(ADNode_mapping[BD18397_ADCOrignalval[id].AdcStruct.ADSEL]==0)&&(BD18397_ADCOrignalval[id].data[ADNode_mapping[BD18397_ADCOrignalval[id].AdcStruct.ADSEL]]<10))
        {
            buftest[0]++;
        }
        if((id==0)&&(ADNode_mapping[BD18397_ADCOrignalval[id].AdcStruct.ADSEL]==7)&&(BD18397_ADCOrignalval[id].data[ADNode_mapping[BD18397_ADCOrignalval[id].AdcStruct.ADSEL]]<10))
        {
            buftest[1]++;
        }
        if((id==0)&&(ADNode_mapping[BD18397_ADCOrignalval[id].AdcStruct.ADSEL]==8)&&(BD18397_ADCOrignalval[id].data[ADNode_mapping[BD18397_ADCOrignalval[id].AdcStruct.ADSEL]]<10))
        {
            buftest[2]++;
        }
        if((id==0)&&(ADNode_mapping[BD18397_ADCOrignalval[id].AdcStruct.ADSEL]==9)&&(BD18397_ADCOrignalval[id].data[ADNode_mapping[BD18397_ADCOrignalval[id].AdcStruct.ADSEL]]<10))
        {
            buftest[3]++;
        }
        if((id==1)&&(ADNode_mapping[BD18397_ADCOrignalval[id].AdcStruct.ADSEL]==0)&&(BD18397_ADCOrignalval[id].data[ADNode_mapping[BD18397_ADCOrignalval[id].AdcStruct.ADSEL]]<10))
        {
            buftest[4]++;
        }
        if((id==1)&&(ADNode_mapping[BD18397_ADCOrignalval[id].AdcStruct.ADSEL]==7)&&(BD18397_ADCOrignalval[id].data[ADNode_mapping[BD18397_ADCOrignalval[id].AdcStruct.ADSEL]]<10))
        {
            buftest[5]++;
        }
        if((id==1)&&(ADNode_mapping[BD18397_ADCOrignalval[id].AdcStruct.ADSEL]==8)&&(BD18397_ADCOrignalval[id].data[ADNode_mapping[BD18397_ADCOrignalval[id].AdcStruct.ADSEL]]<10))
        {
            buftest[6]++;
        }
        if((id==1)&&(ADNode_mapping[BD18397_ADCOrignalval[id].AdcStruct.ADSEL]==9)&&(BD18397_ADCOrignalval[id].data[ADNode_mapping[BD18397_ADCOrignalval[id].AdcStruct.ADSEL]]<10))
        {
            buftest[7]++;
        }
        }
    }
#endif

    if (BD18397_ADCOrignalval[id].AdcStruct.ADSEL < MAX_ADC_Node - 1)
    {
        /*when ADSEL=MAX_ADC_Node-1,ADSEL will still ++ and go into next cycle.*/
        BD18397_ADCOrignalval[id].AdcStruct.ADSEL++;
    }
    else
    {
        /*when ADSEL=MAX_ADC_Node,ADSEL will be 0 and go into next cycle.*/
        BD18397_ADCOrignalval[id].AdcStruct.ADSEL = 0;
    }

#if BD18397_MODIFY_MHL
    BD18397_ADCStartConvertFlag[id] = 1;
#endif
    // res |= BD18397SetADCNoteMode(id, ADNode_mapping[BD18397_ADCOrignalval[id].AdcStruct.ADSEL], 0, 0);
    // res |= BD18397SetADCNoteMode(id, ADNode_mapping[BD18397_ADCOrignalval[id].AdcStruct.ADSEL], 1, 0);
    /*Errstatus: send ErrStall read command, if do not have hard err, it will not read ERRST1-3*/
    WriteCMD.RWAddr = (BD18397_ERRSTALL);
    res |= BD18397Transmit(&WriteCMD, &ReadCMD, 0, 0);
    BD18397RegData[id].BD18397_ERRSTALL_Data = ReadCMD.data2;
#if BD18397CONFIG_GetChannel_ERR_In_MainFunction
    /*0x07: Hardware ERR mask*/
    if (0 != ((ReadCMD.data2) & (0x07)))
    {
        /*if ERRSTALL data have err in channel, read channel specific err*/
        ch_en=BD18397RegData[id].BD18397_CHEN_Data;
        if((ch_en&1)!=0) //CH1 ON
        {
            WriteCMD.RWAddr = (BD18397_ERRST1);
            WriteCMD.data = 0xff;
            res |= BD18397Transmit(&WriteCMD, &ReadCMD, 0, 0);
            BD18397RegData[id].BD18397_ERRST1_Data = ReadCMD.data2;
        }
        if((ch_en&2)!=0) //CH2 ON
        {
            WriteCMD.RWAddr = (BD18397_ERRST2);
            WriteCMD.data = 0xff;
            res |= BD18397Transmit(&WriteCMD, &ReadCMD, 0, 0);
            BD18397RegData[id].BD18397_ERRST2_Data = ReadCMD.data2;
        }
        if((ch_en&4)!=0) //CH3 ON
        {
            WriteCMD.RWAddr = (BD18397_ERRST3);
            WriteCMD.data = 0xff;
            res |= BD18397Transmit(&WriteCMD, &ReadCMD, 0, 0);
            BD18397RegData[id].BD18397_ERRST3_Data = ReadCMD.data2;
        }
    }
    else
    {
        BD18397RegData[id].BD18397_ERRST1_Data = 0;
        BD18397RegData[id].BD18397_ERRST2_Data = 0;
        BD18397RegData[id].BD18397_ERRST3_Data = 0;
    }
#endif

#if BD18397_MODIFY_MHL
#else
    WriteCMD.RWAddr = (BD18397_VMONL);
    res |= BD18397Transmit(&WriteCMD, &ReadCMD, 0, 0);
    BD18397RegData[id].BD18397_VMONL_Data = ReadCMD.data2;

    WriteCMD.RWAddr = (BD18397_VMONH);
    res |= BD18397Transmit(&WriteCMD, &ReadCMD, 0, 0);
    BD18397RegData[id].BD18397_VMONH_Data = ReadCMD.data2;
#endif
    WriteCMD.RWAddr = 0x80 | (BD18397_ERRSET1);
    WriteCMD.data = (BD18397RegData[id].BD18397_ERRSET1_Data | 0x04);
    res |= BD18397Transmit(&WriteCMD, &ReadCMD, 0, 0);
#if BD18397_MODIFY_MHL
#else
    BD18397_ADCOrignalval[id].data[ADNode_mapping[BD18397_ADCOrignalval[id].AdcStruct.ADSEL]] = (((uint16)(BD18397RegData[id].BD18397_VMONH_Data)) << 2) | ((uint16)(BD18397RegData[id].BD18397_VMONL_Data & 0x3));
#endif
    res |= BD18397SetADCNoteMode(id, ADNode_mapping[BD18397_ADCOrignalval[id].AdcStruct.ADSEL], 1, 0);
    // res |= BD18397SetADCNoteMode(id, ADNode_mapping[BD18397_ADCOrignalval[id].AdcStruct.ADSEL],0, 1);
    return res;
}

/**
 * 函数功能 设置电流输出频率
 * 输入 ：
 * id   ：buck地址，用于有多个buck芯片时，通过地址指定哪一个芯片
 * hw_ch：buck通道：18397可选0 1，18398可选0 1 2
 * GM ：放大增益
 *TON : 输出主频
*/
Std_ReturnType BD18397SetDCDCSetting(uint8 id, uint8 hw_ch, uint8 GM, uint8 TON)
{
    Std_ReturnType res = E_OK;
    if (GM > 3)
    {
        GM = 3;
    }
    if (TON > 63)
    {
        TON = 63;
    }
    if (hw_ch > 2)
    {
        return E_NOT_OK;
    }
    BD18397_TransType WriteCMD = {
        .ID = id,
        .RWAddr = 0x80 | (BD18397_DCDCSET1 + hw_ch),
        .data = ((GM << 6) | (TON)),
        .SpiChNo = id_SpiNo_mapping[id],
    };
    res |= BD18397Transmit(&WriteCMD, NULL_PTR, 0, 0);
    switch (hw_ch)
    {
    case 0 /* hw_ch==0 */:
        /* code */
        BD18397RegData[id].BD18397_DCDCSET1_Data = WriteCMD.data;

        break;
    case 1 /* hw_ch==1 */:
        /* code */
        BD18397RegData[id].BD18397_DCDCSET2_Data = WriteCMD.data;
        break;

    case 2 /* hw_ch==2 */:
        /* code */
        BD18397RegData[id].BD18397_DCDCSET3_Data = WriteCMD.data;
        break;

    default:
        break;
    }

    return res;
}

Std_ReturnType BD18397ReceiveRegDataBuffer(uint8 id, uint8 addr, uint8 *data)
{
    Std_ReturnType res = E_OK;
    return res;
}

/**
 * 函数功能 读取通道电流占空比
 * 输入 ：
 * id  :buck地址，用于有多个buck芯片时，通过地址指定哪一个芯片
 * mode：转换模式1：自动转换 0：手动转换 项目中用到手动转换
 * trg : mode=0，当trg=1,开始转换数据
 * ADMODE:采样的10个数据，具体列表查看寄存器0x15
*/
Std_ReturnType BD18397SetADCNoteMode(uint8 id, uint8 mode, uint8 trg, uint8 ADMODE)
{
    Std_ReturnType res = E_OK;
    BD18397_TransType WriteCMD = {
        .ID = id,
        .RWAddr = 0x80 | (BD18397_ADSEL),
        .data = 0,
        .SpiChNo = id_SpiNo_mapping[id],
    };
    WriteCMD.data = ((mode & 0x0f) | ((ADMODE & 0x1) << 4) | ((trg & 0x1) << 7));
    res |= BD18397Transmit(&WriteCMD, NULL_PTR, 0, 0);
    BD18397RegData[id].BD18397_ADSEL_Data = WriteCMD.data;
    return res;
}
/**
 * 函数功能 获取ADC值（具体的ADC类型要看前一个0x15写的是什么）
 * 输入 ：
 * id  :buck地址，用于有多个buck芯片时，通过地址指定哪一个芯片
 * VMON：存放采样的数据
**/
Std_ReturnType BD18397GetADC(uint8 id, uint16 *VMON)
{
    Std_ReturnType res = E_OK;
    BD18397_ReceiveType receiveData = {
        .data1 = 0,
        .data2 = 0,
        .CRC = 0,
        .ID = 0};
    BD18397_TransType WriteCMD = {
        .ID = id,
        .RWAddr = (BD18397_VMONH),
        .data = 0,
        .SpiChNo = id_SpiNo_mapping[id],
    };
    res |= BD18397Transmit(&WriteCMD, &receiveData, 0, 1);
    WriteCMD.RWAddr = BD18397_VMONL;
    res |= BD18397Transmit(&WriteCMD, &receiveData, 0, 1);
    BD18397RegData[id].BD18397_VMONH_Data = WriteCMD.data;
    res |= BD18397Transmit(&WriteCMD, &receiveData, 0, 1);
    BD18397RegData[id].BD18397_VMONL_Data = WriteCMD.data;
    *VMON = (((uint16)(BD18397RegData[id].BD18397_VMONH_Data)) << 2) | ((uint16)(BD18397RegData[id].BD18397_VMONL_Data) & 0x3);
    return res;
}

Std_ReturnType BD18397GetThremalBuffer(uint8 id, uint16 *buffer)
{
    if (buffer == NULL_PTR)
    return E_NOT_OK;

    *buffer = BD18397_ADCOrignalval[id].AdcStruct.Thermal;
    return E_OK;
}


Std_ReturnType BD18397GetHwChVoltage(uint8 id, uint8 hw_ch, uint16 *buffer)
{
    // static uint8 data;
    if (buffer == NULL_PTR)
    return E_NOT_OK;
    *buffer = BD18397_ADCOrignalval[id].data[7 + hw_ch]; //the ADC is efficient
    return E_OK;
}

Std_ReturnType BD18397GetHwChErrStatus(uint8 id, uint8 hw_ch, uint8 *buffer)
{
    Std_ReturnType res = E_OK;
    if (buffer != NULL_PTR)
    {

        switch (hw_ch)
        {
        case 0 /* constant-expression */:
            /* code */
            *buffer = BD18397RegData[id].BD18397_ERRST1_Data;
            break;
        case 1 /* constant-expression */:
            /* code */
            *buffer = BD18397RegData[id].BD18397_ERRST2_Data;
            break;
        case 2 /* constant-expression */:
            /* code */
            *buffer = BD18397RegData[id].BD18397_ERRST3_Data;
            break;

        default:
            res = E_NOT_OK;
            break;
        }
    }
    else
    {
        res = E_NOT_OK;
    }
    return res;
}

Std_ReturnType BD18397GetLostComFlag(uint8 id, uint8 *val)
{
    *val = BD18397LostComFlag[id];
    return E_OK;
}

Std_ReturnType BD18397GetLostConfig(uint8 id, uint8 *val)
{
    *val = BD18397LostConfigFlag[id];
    return E_OK;
}

/* 函数名称 ：Std_ReturnType BD18397SetLHEnable(uint8 id)
 * 函数功能 ：设置LH模式开启
 * 输入     ： id:1839x的对应id
 * 返回值   ：E_OK 设置成功
             E_NOT_OK 设置不成功
*/
Std_ReturnType BD18397SetLHEnable(uint8 id)
{
    Std_ReturnType res = E_OK;
    uint8 Data_Sysset = 0;
    BD18397_TransType WriteCMD = {
        .ID = id,
        .RWAddr =  0x80 | BD18397_SYSSET,
        .data = 0xFF,
        .SpiChNo = id_SpiNo_mapping[id],
    };
    BD18397_ReceiveType ReadCMD = {
        .ID = id,
        .data1 = 0,
        .data2 = 0,
        .CRC = 0};
    if((BD18397RegData[id].BD18397_SYSSET_Data&0x40) == 0) //if LH disable
    {
        WriteCMD.data = BD18397RegData[id].BD18397_SYSSET_Data| 0x40;
        res |= BD18397Transmit(&WriteCMD, NULL_PTR, 0, 0); //write wdten=1
        WriteCMD.RWAddr = BD18397_SYSSET;
        res |= BD18397Transmit(&WriteCMD, &ReadCMD, 0, 0); //check write success or not
        if(res==E_OK)
        {
            Data_Sysset = ReadCMD.data2 ;
            if((Data_Sysset&0x40) != 0) //OPEN OK
            {
                BD18397RegData[id].BD18397_SYSSET_Data = Data_Sysset;     
            }
            else res = E_NOT_OK;
        }
    }
    return res;
}

/* 函数名称 ：Std_ReturnType BD18397SetLHEnable(uint8 id)
 * 函数功能 ：设置LH模式关闭
 * 输入     ： id:1839x的对应id
 * 返回值   ：E_OK 设置成功
             E_NOT_OK 设置不成功
*/
Std_ReturnType BD18397SetLHDisable(uint8 id)
{
    Std_ReturnType res = E_OK;
    uint8 Data_Sysset = 0;
    BD18397_TransType WriteCMD = {
        .ID = id,
        .RWAddr = 0x80 | BD18397_SYSSET,
        .data = 0xFF,
        .SpiChNo = id_SpiNo_mapping[id],
    };
    BD18397_ReceiveType ReadCMD = {
        .ID = id,
        .data1 = 0,
        .data2 = 0,
        .CRC = 0};
    if((BD18397RegData[id].BD18397_SYSSET_Data&0x40) !=0)
    {
        WriteCMD.data = BD18397RegData[id].BD18397_SYSSET_Data & 0xBF;
        res |= BD18397Transmit(&WriteCMD, NULL_PTR, 0, 0); //write wdten=0
        WriteCMD.RWAddr = BD18397_SYSSET;
        res |= BD18397Transmit(&WriteCMD, &ReadCMD, 0, 0); //check write success or not
        if(res==E_OK)
        {
            Data_Sysset = ReadCMD.data2 ;
            if((Data_Sysset&0x40) ==0)//CLOSE OK
            {
                BD18397RegData[id].BD18397_SYSSET_Data = Data_Sysset;     
            }
            else res = E_NOT_OK;
        }
    }
    return res;
}

// /*占空比不为100%会吱吱响*/
void BD18397_Init_All(void)
{
    uint8 Rsnsx=100,isON=0;
    uint16 Current=0,PWM=100;
    BD18397Init(0);
    BD18397Init(1);

}
