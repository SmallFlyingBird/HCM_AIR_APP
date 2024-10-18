/*
 * MatrixChip_Interface.c
 *
 *  Created on: 2024��1��10��
 *      Author: mihuiliang
 */
/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "AswInterfaceManager.h"
/****************************************************************
 *                                                              *
 *                  Global Private Variable Define              *
 *                                                              *
 ****************************************************************/
static S_MatrixChipDrv_Dev *g_S_MatrixChipDrv_Dev_Header = NULL;
static uint8_t MatrixDrvRegisterNum = 0;
static S_MatrixDrvInfo g_S_MatrixDrvInfo[MAX_MATRIXCHIP_NUM];
#if LMM_LOSCOM_AUTORESUM_ENABLE
#else
static List_t gMatrixComList;
static ListItem_t gMatrixComListItem[MAX_MATRIXCHIP_NUM];
#endif
static E_MatrixChipType g_MatrixChipType = E_None;
/****************************************************************
 *                                                              *
 *                   Global Private Functions Define            *
 *                                                              *
 ****************************************************************/

/*
 * return 0: the pwm value is same as cur pwm ,
 * return 1: the pwm value is not same as cur pwm ,
 *
 */
static uint8_t IsMatrixChipPwmChanged(uint8_t dev_address, uint8 *PWMDataSrc)
{
    uint8_t i = 0;
    uint8_t j = 0;

    for (i = 0; i < MatrixDrvRegisterNum; i++)
    {
        if (g_S_MatrixDrvInfo[i].dev_address != dev_address)
            continue;

        for (j = 0; j < MAX_MATRIXCHIP_CHANNEL_NUM; j++)
        {
            if ((g_S_MatrixDrvInfo[i].CurPwm[j] != UNUSED_PWM_VALUE) &&
                (PWMDataSrc[j] != g_S_MatrixDrvInfo[i].CurPwm[j]))
                return 1;
        }

        return 0;
    }

    return 0;
}
static Std_ReturnType SetMatrixChipCurPwm(uint8_t dev_address, uint8 *PWMDataSrc)
{

    uint8_t i = 0;
    uint8_t j = 0;

    for (i = 0; i < MatrixDrvRegisterNum; i++)
    {
        if (g_S_MatrixDrvInfo[i].dev_address != dev_address)
            continue;

        for (j = 0; j < TPS92662A_MAX_CHANNEL_NUM; j++)
        {
            if (g_S_MatrixDrvInfo[i].CurPwm[j] != UNUSED_PWM_VALUE)
                g_S_MatrixDrvInfo[i].CurPwm[j] = PWMDataSrc[j];
        }

        return E_OK;
    }

    return E_NOT_OK;
}

static S_MatrixChipDrv_Dev *GetMatrixChipDrvByDevAddress(uint8_t dev_address)
{
    S_MatrixChipDrv_Dev *tmp = g_S_MatrixChipDrv_Dev_Header;

    while (tmp != NULL)
    {
        if (tmp->dev_address == dev_address)
            return tmp;

        tmp = tmp->ptNext;
    }

    return NULL;
}

static S_MatrixDrvInfo *GetMatrixDrvInfoByDevAddress(uint8_t dev_address)
{
    S_MatrixDrvInfo *MatrixDrvInfo = NULL;
    uint8_t i = 0;
    for (i = 0; i < MatrixDrvRegisterNum; i++)
    {
        if (g_S_MatrixDrvInfo[i].dev_address == dev_address)
            return &g_S_MatrixDrvInfo[i];
    }

    return NULL;
}

static Std_ReturnType GetTps92662AInitDataByDevAddress(uint8_t dev_address, const uint8 **tpspara, const uint16 **phaseshif)
{
    uint8_t i = 0;
    uint8_t j = 0;
    const uint8 *InitData_tpspara = NULL;
    const uint16 *InitData_phaseshif = NULL;
    S_MatrixDrvInfo *MatrixDrvInfo = NULL;

    for (i = 0; i < LOWHIGH_MAX_MATRIXCHIP_NUM; i++)
    {
        InitData_tpspara = Get_LB_HB_MatrixInfo(i);
        if (InitData_tpspara[LMM_AVL_INDEX] == 0)
        {
            break;
        }

        if (InitData_tpspara[LMM_ADDRESS_INDEX] == dev_address)
        {
            /*设置通道的矩阵芯片地址映射*/
            Interface_SetChannelMatrixChipDeviceAddress((InitData_tpspara[LMM_CH_INDEX] - 1), dev_address);
            /*设置矩阵芯片的通道映射*/
            Interface_SetMatrixChipChannelMap((InitData_tpspara[LMM_CH_INDEX] - 1), dev_address);

            MatrixDrvInfo = GetMatrixDrvInfoByDevAddress(dev_address);
            for (j = 0; j < MAX_MATRIXCHIP_CHANNEL_NUM; j++)
            {
                if (InitData_tpspara[LMM_PIXNUMBERID_INDEX + j] == 0)
                    MatrixDrvInfo->CurPwm[j] = UNUSED_PWM_VALUE;
            }
            InitData_phaseshif = Get_LB_HB_PhsSft(i);
            *tpspara = InitData_tpspara;
            *phaseshif = InitData_phaseshif;
            /*find*/
            return E_OK;
        }
    }

    for (i = 0; i < TI_MAX_MATRIXCHIP_NUM; i++)
    {
        InitData_tpspara = Get_TI_MatrixInfo(i);
        if (InitData_tpspara[LMM_AVL_INDEX] == 0)
        {
            break;
        }

        if (InitData_tpspara[LMM_ADDRESS_INDEX] == dev_address)
        {
            Interface_SetChannelMatrixChipDeviceAddress((InitData_tpspara[LMM_CH_INDEX] - 1), dev_address);
            /*设置矩阵芯片的通道映射*/
            Interface_SetMatrixChipChannelMap((InitData_tpspara[LMM_CH_INDEX] - 1), dev_address);

            MatrixDrvInfo = GetMatrixDrvInfoByDevAddress(dev_address);
            for (j = 0; j < MAX_MATRIXCHIP_CHANNEL_NUM; j++)
            {
                if (InitData_tpspara[LMM_PIXNUMBERID_INDEX + j] == 0)
                    MatrixDrvInfo->CurPwm[j] = UNUSED_PWM_VALUE;
            }
            InitData_phaseshif = Get_TI_PhsSft(i);
            *tpspara = InitData_tpspara;
            *phaseshif = InitData_phaseshif;
            /*find*/
            return E_OK;
        }
    }

    for (i = 0; i < DRLPOS_MAX_MATRIXCHIP_NUM; i++)
    {
        InitData_tpspara = Get_DRL_POS_MatrixInfo(i);
        if (InitData_tpspara[LMM_AVL_INDEX] == 0)
        {
            break;
        }

        if (InitData_tpspara[LMM_ADDRESS_INDEX] == dev_address)
        {
            Interface_SetChannelMatrixChipDeviceAddress((InitData_tpspara[LMM_CH_INDEX] - 1), dev_address);
            /*设置矩阵芯片的通道映射*/
            Interface_SetMatrixChipChannelMap((InitData_tpspara[LMM_CH_INDEX] - 1), dev_address);

            MatrixDrvInfo = GetMatrixDrvInfoByDevAddress(dev_address);
            for (j = 0; j < MAX_MATRIXCHIP_CHANNEL_NUM; j++)
            {
                if (InitData_tpspara[LMM_PIXNUMBERID_INDEX + j] == 0)
                    MatrixDrvInfo->CurPwm[j] = UNUSED_PWM_VALUE;
            }
            InitData_phaseshif = Get_DRL_POS_PhsSft(i);
            *tpspara = InitData_tpspara;
            *phaseshif = InitData_phaseshif;
            /*find*/
            return E_OK;
        }
    }

    for (i = 0; i < GRILLE_MAX_MATRIXCHIP_NUM; i++)
    {
        InitData_tpspara = Get_Grille_MatrixInfo(i);
        if (InitData_tpspara[LMM_AVL_INDEX] == 0)
        {
            break;
        }

        if (InitData_tpspara[LMM_ADDRESS_INDEX] == dev_address)
        {
            Interface_SetChannelMatrixChipDeviceAddress((InitData_tpspara[LMM_CH_INDEX] - 1), dev_address);
            /*设置矩阵芯片的通道映射*/
            Interface_SetMatrixChipChannelMap((InitData_tpspara[LMM_CH_INDEX] - 1), dev_address);

            MatrixDrvInfo = GetMatrixDrvInfoByDevAddress(dev_address);
            for (j = 0; j < MAX_MATRIXCHIP_CHANNEL_NUM; j++)
            {
                if (InitData_tpspara[LMM_PIXNUMBERID_INDEX + j] == 0)
                    MatrixDrvInfo->CurPwm[j] = UNUSED_PWM_VALUE;
            }
            InitData_phaseshif = Get_Grille_PhsSft(i);
            *tpspara = InitData_tpspara;
            *phaseshif = InitData_phaseshif;
            /*find*/
            return E_OK;
        }
    }

    for (i = 0; i < LOGO_MAX_MATRIXCHIP_NUM; i++)
    {
        InitData_tpspara = Get_Logo_MatrixInfo(i);
        if (InitData_tpspara[LMM_AVL_INDEX] == 0)
        {
            break;
        }

        if (InitData_tpspara[LMM_ADDRESS_INDEX] == dev_address)
        {
            Interface_SetChannelMatrixChipDeviceAddress((InitData_tpspara[LMM_CH_INDEX] - 1), dev_address);
            /*设置矩阵芯片的通道映射*/
            Interface_SetMatrixChipChannelMap((InitData_tpspara[LMM_CH_INDEX] - 1), dev_address);

            MatrixDrvInfo = GetMatrixDrvInfoByDevAddress(dev_address);
            for (j = 0; j < MAX_MATRIXCHIP_CHANNEL_NUM; j++)
            {
                if (InitData_tpspara[LMM_PIXNUMBERID_INDEX + j] == 0)
                    MatrixDrvInfo->CurPwm[j] = UNUSED_PWM_VALUE;
            }
            InitData_phaseshif = Get_Logo_PhsSft(i);
            *tpspara = InitData_tpspara;
            *phaseshif = InitData_phaseshif;
            /*find*/
            return E_OK;
        }
    }

    for (i = 0; i < ASSISTANT_MAX_MATRIXCHIP_NUM; i++)
    {
        InitData_tpspara = Get_Assistant_MatrixInfo(i);
        if (InitData_tpspara[LMM_AVL_INDEX] == 0)
        {
            break;
        }

        if (InitData_tpspara[LMM_ADDRESS_INDEX] == dev_address)
        {
            Interface_SetChannelMatrixChipDeviceAddress((InitData_tpspara[LMM_CH_INDEX] - 1), dev_address);
            /*设置矩阵芯片的通道映射*/
            Interface_SetMatrixChipChannelMap((InitData_tpspara[LMM_CH_INDEX] - 1), dev_address);

            MatrixDrvInfo = GetMatrixDrvInfoByDevAddress(dev_address);
            for (j = 0; j < MAX_MATRIXCHIP_CHANNEL_NUM; j++)
            {
                if (InitData_tpspara[LMM_PIXNUMBERID_INDEX + j] == 0)
                    MatrixDrvInfo->CurPwm[j] = UNUSED_PWM_VALUE;
            }
            InitData_phaseshif = Get_Assistant_PhsSft(i);
            *tpspara = InitData_tpspara;
            *phaseshif = InitData_phaseshif;
            /*find*/
            return E_OK;
        }
    }

    for (i = 0; i < FRONTCROSS_MAX_MATRIXCHIP_NUM; i++)
    {
        InitData_tpspara = Get_FrontCross_MatrixInfo(i);
        if (InitData_tpspara[LMM_AVL_INDEX] == 0)
        {
            break;
        }

        if (InitData_tpspara[LMM_ADDRESS_INDEX] == dev_address)
        {
            Interface_SetChannelMatrixChipDeviceAddress((InitData_tpspara[LMM_CH_INDEX] - 1), dev_address);
            /*设置矩阵芯片的通道映射*/
            Interface_SetMatrixChipChannelMap((InitData_tpspara[LMM_CH_INDEX] - 1), dev_address);

            MatrixDrvInfo = GetMatrixDrvInfoByDevAddress(dev_address);
            for (j = 0; j < MAX_MATRIXCHIP_CHANNEL_NUM; j++)
            {
                if (InitData_tpspara[LMM_PIXNUMBERID_INDEX + j] == 0)
                    MatrixDrvInfo->CurPwm[j] = UNUSED_PWM_VALUE;
            }
            InitData_phaseshif = Get_FrontCross_PhsSft(i);
            *tpspara = InitData_tpspara;
            *phaseshif = InitData_phaseshif;
            /*find*/
            return E_OK;
        }
    }

    /*Not find*/
    return E_NOT_OK;
}

static Std_ReturnType MatrixComReset(S_MatrixChipDrv_Dev *DrvDev)
{
    Std_ReturnType rtval = E_OK;
    S_MatrixTripDataPackets MatrixTripDataPackets;

    MatrixTripDataPackets.DataType = E_MatrixTripDataType_MatrixComReset;
    MatrixTripDataPackets.dev_address = DrvDev->dev_address;
    MatrixTripDataPackets.datasrc = NULL;

    rtval |= DrvDev->Write((void *)(&MatrixTripDataPackets));

    return rtval;
}

/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
/*
 *判断矩阵芯片使用的通道是都都是0%占空比
 * return 1：所有通道占空比都为0
 * return 0：有通道的占空比不为0
 */
uint8_t Interface_IsMatrixChipIsEmtpyPwm(uint8_t dev_address)
{
    S_MatrixDrvInfo *MatrixDrvInfo = NULL;
    uint8_t i = 0;

    MatrixDrvInfo = GetMatrixDrvInfoByDevAddress(dev_address);

    if (MatrixDrvInfo == NULL)
        return 0;

    for (i = 0; i < MAX_MATRIXCHIP_CHANNEL_NUM; i++)
    {
        if ((MatrixDrvInfo->CurPwm[i] != UNUSED_PWM_VALUE) &&
            (MatrixDrvInfo->CurPwm[i] != 0))
        {
            return 0;
        }
    }

    return 1;
}
/*判断矩阵芯片使用的通道是都都是100%占空比*/
uint8_t Interface_IsMatrixChipIsFullPwm(uint8_t dev_address)
{
    S_MatrixDrvInfo *MatrixDrvInfo = NULL;
    uint8_t i = 0;

    MatrixDrvInfo = GetMatrixDrvInfoByDevAddress(dev_address);

    if (MatrixDrvInfo == NULL)
        return 0;

    for (i = 0; i < MAX_MATRIXCHIP_CHANNEL_NUM; i++)
    {
        if ((MatrixDrvInfo->CurPwm[i] != UNUSED_PWM_VALUE) &&
            (MatrixDrvInfo->CurPwm[i] != 100))
        {
            return 0;
        }
    }

    return 1;
}
/*
 *设置矩阵芯片的通道映射
 */
Std_ReturnType Interface_SetMatrixChipChannelMap(E_ChannelID channelid, uint8_t dev_address)
{
    S_MatrixDrvInfo *ptMatrixDrvInfo = NULL;

    ptMatrixDrvInfo = GetMatrixDrvInfoByDevAddress(dev_address);

    if (ptMatrixDrvInfo == NULL)
        return E_NOT_OK;

    ptMatrixDrvInfo->ChannlMap = channelid;

    return E_OK;
}

Std_ReturnType Interface_SetMatrixChipChannelPwm(uint8_t dev_address, uint8 *pwmdata)
{
    S_MatrixChipDrv_Dev *tmp = NULL;
    S_ChannelPWMDataSrc ChannelPWMDataSrc;
    S_MatrixTripDataPackets MatrixTripDataPackets;
    Std_ReturnType rtval = E_OK;
    uint8_t i = 0;

    tmp = GetMatrixChipDrvByDevAddress(dev_address);

    if (NULL == tmp)
        return E_NOT_OK;

    if (IsMatrixChipPwmChanged(dev_address, pwmdata) == 1)
    {
        for (i = 0; i < MAX_MATRIXCHIP_CHANNEL_NUM; i++)
        {
            ChannelPWMDataSrc.PwmValue[i] = pwmdata[i];
        }
        MatrixTripDataPackets.DataType = E_MatrixTripDataType_PwmValue;
        MatrixTripDataPackets.dev_address = dev_address;
        MatrixTripDataPackets.datasrc = (void *)(&ChannelPWMDataSrc);
        rtval |= tmp->Write((void *)(&MatrixTripDataPackets));

        if (rtval == E_OK)
        {
            rtval |= SetMatrixChipCurPwm(dev_address, pwmdata);
        }
    }

    return rtval;
}

Std_ReturnType Interface_GetMatrixChipChannelPwm(uint8_t dev_address, uint8 *pwmdata)
{
    Std_ReturnType rtval = E_OK;
    S_MatrixChipDrv_Dev *tmp = NULL;

    uint8_t i = 0;
    uint8_t j = 0;
    tmp = GetMatrixChipDrvByDevAddress(dev_address);

    if (NULL == tmp)
    {
        return E_NOT_OK;
    }

    for (i = 0; i < MatrixDrvRegisterNum; i++)
    {
        if (g_S_MatrixDrvInfo[i].dev_address != dev_address)
            continue;

        for (j = 0; j < TPS92662A_MAX_CHANNEL_NUM; j++)
        {
            pwmdata[j] = g_S_MatrixDrvInfo[i].CurPwm[j];
        }
    }

    return rtval;
}

Std_ReturnType Interface_GetMatrixChipAdcValue(uint8_t dev_address, S_AdcValueDataSrc *AdcValueDataSrc)
{
    S_MatrixChipDrv_Dev *tmp = NULL;
    S_MatrixDrvInfo *MatrixDrvInfo = NULL;
    S_MatrixTripDataPackets MatrixTripDataPackets;
    Std_ReturnType rtval = E_OK;

    tmp = GetMatrixChipDrvByDevAddress(dev_address);

    MatrixDrvInfo = GetMatrixDrvInfoByDevAddress(dev_address);

    if ((NULL == tmp) || (NULL == MatrixDrvInfo))
        return E_NOT_OK;

    if (MatrixDrvInfo->LostComFlag == 1)
        return E_NOT_OK;

    MatrixTripDataPackets.DataType = E_MatrixTripDataType_AdcValue;
    MatrixTripDataPackets.dev_address = dev_address;
    MatrixTripDataPackets.datasrc = (void *)AdcValueDataSrc;
    rtval |= tmp->Read((void *)(&MatrixTripDataPackets));

    if (rtval != E_OK)
    {
        if (AdcValueDataSrc->LostComErr == 1)
        {
            if (tmp->MatrixChipType == E_TPS92662A)
                MatrixComReset(tmp);
        }
    }

    return rtval;
}

Std_ReturnType Interface_GetMatrixChipPwmWidth(uint8_t dev_address, uint8 *pwmdata)
{
    S_MatrixChipDrv_Dev *tmp = NULL;
    S_MatrixTripDataPackets MatrixTripDataPackets;
    S_ChannelPWMDataSrc ChannelPWMDataSrc;
    uint8_t i = 0;
    Std_ReturnType rtval = E_OK;

    tmp = GetMatrixChipDrvByDevAddress(dev_address);
    if (NULL == tmp)
        return E_NOT_OK;

    MatrixTripDataPackets.DataType = E_MatrixTripDataType_PwmValue;
    MatrixTripDataPackets.dev_address = dev_address;
    MatrixTripDataPackets.datasrc = (void *)(&ChannelPWMDataSrc);

    rtval |= tmp->Read((void *)(&MatrixTripDataPackets));

    if (rtval == E_OK)
    {
        for (i = 0; i < MAX_MATRIXCHIP_CHANNEL_NUM; i++)
        {
            pwmdata[i] = ChannelPWMDataSrc.PwmValue[i];
        }
    }

    return rtval;
}

uint8_t Interface_GetMatrixChipRegisterNumer(void)
{
    return MatrixDrvRegisterNum;
}

uint8_t Interface_GetMatrixChipAddress(uint8_t registerid)
{
    if (registerid >= MAX_MATRIXCHIP_NUM)
        return 0xFF;
    return g_S_MatrixDrvInfo[registerid].dev_address;
}

uint8_t Interface_GetMatrixChioLostComErrorFlag(uint8_t dev_address)
{
    uint8_t i = 0;
    for (i = 0; i < MatrixDrvRegisterNum; i++)
    {
        if (g_S_MatrixDrvInfo[i].dev_address == dev_address)
            return g_S_MatrixDrvInfo[i].LostComFlag;
    }
    return 0;
}
/*
 *重置矩阵芯片通信列表：把注册的矩阵芯片再放回到通信列表中
 */
Std_ReturnType Interface_ResetMatrixChipComList(void)
{
    uint8_t i = 0;
    for (i = 0; i < MatrixDrvRegisterNum; i++)
    {
#if LMM_LOSCOM_AUTORESUM_ENABLE
        g_S_MatrixDrvInfo[i].LostComFlag = 0;
        g_S_MatrixDrvInfo[i].LostComErrCnt = 0;
#else
        if (IsListItemInList(&gMatrixComList, &(gMatrixComListItem[i])) == 0)
            ListItemInsertEnd(&gMatrixComList, &(gMatrixComListItem[i]));
        /*重置错误计数器*/
        g_S_MatrixDrvInfo[(gMatrixComListItem[i].MatrixIndex)].LostComErrCnt = 0;

#endif
    }
    return E_OK;
}

Std_ReturnType MatrixChip_Interface_Mainfunction(uint8_t timebase)
{
    static S_MatrixChipDrv_Dev *tmp = NULL;
    S_MatrixTripDataPackets MatrixTripDataPackets;
    S_MainFunctionDataSrc MainFunctionDataSrc;
    Std_ReturnType rtval = E_OK;
#if LMM_LOSCOM_AUTORESUM_ENABLE
    static uint8_t MatrixDrvInfoIndex = 0;
#else
    static ListItem_t *ListItemTmp = &(gMatrixComListItem[0]);
    ListItem_t *RemoveListItem = NULL;
#endif
    uint8_t dev_address;
    uint8_t i = 0;

    if (MatrixDrvRegisterNum == 0)
        return E_OK;

#if LMM_LOSCOM_AUTORESUM_ENABLE
    dev_address = g_S_MatrixDrvInfo[MatrixDrvInfoIndex].dev_address;
#else
    if (GetListNumberOfItems(&gMatrixComList) == 0)
        return E_OK;

    if (ListItemTmp == NULL)
        return E_OK;

    dev_address = g_S_MatrixDrvInfo[ListItemTmp->MatrixIndex].dev_address;
#endif

    tmp = GetMatrixChipDrvByDevAddress(dev_address);

    if (tmp == NULL)
        return E_NOT_OK;

    MatrixTripDataPackets.dev_address = tmp->dev_address;
    MatrixTripDataPackets.DataType = E_MatrixTripDataType_MainFunction;
    MatrixTripDataPackets.datasrc = (void *)(&MainFunctionDataSrc);

    if (tmp != NULL)
    {
        rtval |= tmp->MainFunction((void *)(&MatrixTripDataPackets));

        if (rtval == E_OK)
        {
            if (MainFunctionDataSrc.ComTimeout == 1)
            {
                if (g_MatrixChipType == E_TPS92662A)
                {
                    /*拉低TX脚,重置926626A通信*/
                    rtval |= MatrixComReset(tmp);
#if LMM_LOSCOM_AUTORESUM_ENABLE
                    g_S_MatrixDrvInfo[MatrixDrvInfoIndex].LostComErrCnt = CNT_INC(g_S_MatrixDrvInfo[MatrixDrvInfoIndex].LostComErrCnt, STEP_1, CNT_LIMIT_5);
                    if (g_S_MatrixDrvInfo[MatrixDrvInfoIndex].LostComErrCnt >= CNT_LIMIT_5)
                    {
                        g_S_MatrixDrvInfo[MatrixDrvInfoIndex].LostComFlag = 1;
#if ((VEHICLE_PLATFORM == VEHICLE_SMART_HS11) || (VEHICLE_PLATFORM == VEHICLE_GEELY_G636))
                        if ((g_S_MatrixDrvInfo[MatrixDrvInfoIndex].ChannlMap >= ChannelID2) && (g_S_MatrixDrvInfo[MatrixDrvInfoIndex].ChannlMap <= ChannelID12))
                        {
                            Interface_SetSystemError((E_SystemErrorType_Ch2MatrixLossCom + g_S_MatrixDrvInfo[MatrixDrvInfoIndex].ChannlMap - ChannelID2), 1);
                        }
#endif
                    }
#else
                    g_S_MatrixDrvInfo[ListItemTmp->MatrixIndex].LostComErrCnt = CNT_INC(g_S_MatrixDrvInfo[ListItemTmp->MatrixIndex].LostComErrCnt, STEP_1, CNT_LIMIT_5);
                    if (g_S_MatrixDrvInfo[ListItemTmp->MatrixIndex].LostComErrCnt >= CNT_LIMIT_5)
                    {
                        g_S_MatrixDrvInfo[ListItemTmp->MatrixIndex].LostComFlag = 1;
                        RemoveListItem = ListItemTmp;
                        ListItemTmp = GetNextListItem(ListItemTmp);
                        ListItemRemove(RemoveListItem);
                    }
                    else
                    {
                        ListItemTmp = GetNextListItem(ListItemTmp);
                    }
#endif
                }
            }
            else if (MainFunctionDataSrc.LostCfg == 1)
            {
#if LMM_LOSCOM_AUTORESUM_ENABLE
                g_S_MatrixDrvInfo[MatrixDrvInfoIndex].LostComErrCnt = 0;
                g_S_MatrixDrvInfo[MatrixDrvInfoIndex].LostComFlag = 0;
#if ((VEHICLE_PLATFORM == VEHICLE_SMART_HS11) || (VEHICLE_PLATFORM == VEHICLE_GEELY_G636))
                if ((g_S_MatrixDrvInfo[MatrixDrvInfoIndex].ChannlMap >= ChannelID2) && (g_S_MatrixDrvInfo[MatrixDrvInfoIndex].ChannlMap <= ChannelID12))
                {
                    Interface_SetSystemError((E_SystemErrorType_Ch2MatrixLossCom + g_S_MatrixDrvInfo[MatrixDrvInfoIndex].ChannlMap - ChannelID2), 0);
                }
#endif

#else

                g_S_MatrixDrvInfo[ListItemTmp->MatrixIndex].LostComErrCnt = 0;
                g_S_MatrixDrvInfo[ListItemTmp->MatrixIndex].LostComFlag = 0;
                ListItemTmp = GetNextListItem(ListItemTmp);
#endif
                /*丢失配置，重新初始化矩阵芯片*/
                Interface_AddReInitDrvDevice(E_DrvReInitID_MatrixTrip);
            }
            else
            {
#if LMM_LOSCOM_AUTORESUM_ENABLE
                g_S_MatrixDrvInfo[MatrixDrvInfoIndex].LostComErrCnt = 0;
                g_S_MatrixDrvInfo[MatrixDrvInfoIndex].LostComFlag = 0;
#if ((VEHICLE_PLATFORM == VEHICLE_SMART_HS11) || (VEHICLE_PLATFORM == VEHICLE_GEELY_G636))
                if ((g_S_MatrixDrvInfo[MatrixDrvInfoIndex].ChannlMap >= ChannelID2) && (g_S_MatrixDrvInfo[MatrixDrvInfoIndex].ChannlMap <= ChannelID12))
                {
                    Interface_SetSystemError((E_SystemErrorType_Ch2MatrixLossCom + g_S_MatrixDrvInfo[MatrixDrvInfoIndex].ChannlMap - ChannelID2), 0);
                }
#endif
#else
                g_S_MatrixDrvInfo[ListItemTmp->MatrixIndex].LostComErrCnt = 0;
                g_S_MatrixDrvInfo[ListItemTmp->MatrixIndex].LostComFlag = 0;
                ListItemTmp = GetNextListItem(ListItemTmp);
#endif
            }
        }
    }
#if LMM_LOSCOM_AUTORESUM_ENABLE
    /*指向下一个矩阵芯片数组*/
    MatrixDrvInfoIndex++;
    if (MatrixDrvInfoIndex >= MatrixDrvRegisterNum)
        MatrixDrvInfoIndex = 0;

#endif

#if ((VEHICLE_PLATFORM == VEHICLE_SMART_HS11) || (VEHICLE_PLATFORM == VEHICLE_GEELY_G636))
#elif (VEHICLE_PLATFORM == VEHICLE_GEELY_FX11)
    for (i = 0; i < MatrixDrvRegisterNum; i++)
    {
        if (g_S_MatrixDrvInfo[i].LostComFlag)
        {
            Interface_SetSystemError(E_SystemErrorType_MatrixChip_LossCom, 1);
            break;
        }
    }

    if (i >= MatrixDrvRegisterNum)
        Interface_SetSystemError(E_SystemErrorType_MatrixChip_LossCom, 0);
#endif

    return rtval;
}

Std_ReturnType MatrixChipDrvDev_Register(S_MatrixChipDrv_Dev *Drv_Dev)
{
    S_MatrixChipDrv_Dev *tmp = g_S_MatrixChipDrv_Dev_Header;
    uint8_t i = 0;

    if (g_S_MatrixChipDrv_Dev_Header == NULL)
    {
        if (MatrixDrvRegisterNum >= MAX_MATRIXCHIP_NUM)
            return E_NOT_OK;
#if LMM_LOSCOM_AUTORESUM_ENABLE
#else
        ListInit(&gMatrixComList);
        for (i = 0; i < MAX_MATRIXCHIP_NUM; i++)
            ListItemInit(&gMatrixComListItem[i]);
#endif
        g_S_MatrixDrvInfo[MatrixDrvRegisterNum].dev_address = Drv_Dev->dev_address;
        g_S_MatrixDrvInfo[MatrixDrvRegisterNum].LostComFlag = 0;
#if LMM_LOSCOM_AUTORESUM_ENABLE
#else
        gMatrixComListItem[MatrixDrvRegisterNum].MatrixIndex = MatrixDrvRegisterNum;
        gMatrixComListItem[MatrixDrvRegisterNum].pvDataPtr = (void *)(&g_S_MatrixDrvInfo[MatrixDrvRegisterNum].LostComFlag);
        ListItemInsertEnd(&gMatrixComList, &(gMatrixComListItem[MatrixDrvRegisterNum]));
#endif
        g_S_MatrixChipDrv_Dev_Header = Drv_Dev;
        MatrixDrvRegisterNum++;

        g_S_MatrixChipDrv_Dev_Header->ptNext = NULL;
    }
    else
    {
        while (tmp->ptNext != NULL)
            tmp = tmp->ptNext;

        if (MatrixDrvRegisterNum >= MAX_MATRIXCHIP_NUM)
            return E_NOT_OK;
        g_S_MatrixDrvInfo[MatrixDrvRegisterNum].dev_address = Drv_Dev->dev_address;
        g_S_MatrixDrvInfo[MatrixDrvRegisterNum].LostComFlag = 0;
#if LMM_LOSCOM_AUTORESUM_ENABLE
#else
        gMatrixComListItem[MatrixDrvRegisterNum].MatrixIndex = MatrixDrvRegisterNum;
        gMatrixComListItem[MatrixDrvRegisterNum].pvDataPtr = (void *)(&g_S_MatrixDrvInfo[MatrixDrvRegisterNum].LostComFlag);
        ListItemInsertEnd(&gMatrixComList, &(gMatrixComListItem[MatrixDrvRegisterNum]));
#endif
        MatrixDrvRegisterNum++;

        tmp->ptNext = Drv_Dev;
        Drv_Dev->ptNext = NULL;
    }
    return E_OK;
}

Std_ReturnType MatrixChipInterfaceModuleInit(void)
{
    Std_ReturnType rtval = E_OK;
    S_MatrixChipDrv_Dev *tmp = g_S_MatrixChipDrv_Dev_Header;
    S_MatrixTripDataPackets MatrixTripDataPackets;
    S_Tps92662A_InitDataSrc Tps92662AInitDataSrc;
    uint8_t i = 0;
    uint8_t j = 0;
    const uint8 *tpspara = NULL;
    const uint16 *phaseshif = NULL;

    while (tmp)
    {
        if (tmp->MatrixChipType == E_TPS92662A)
        {
            g_MatrixChipType = E_TPS92662A;

            Tps92662AInitDataSrc.AdcID = Get_pLMMADCID();
            Tps92662AInitDataSrc.PwmTick = Get_pLMMPWMTick();
            Tps92662AInitDataSrc.CMWEN = Get_pLMMCMWEN();
            Tps92662AInitDataSrc.CMWTAP = Get_pLMMCMWTAP();
            if (GetTps92662AInitDataByDevAddress(tmp->dev_address, &tpspara, &phaseshif) == E_OK)
            {

                Tps92662AInitDataSrc.SlewRate = tpspara[LMM_SLEWRATE_INDEX];
                Tps92662AInitDataSrc.OvLimit = tpspara[LMM_OVLIMIT_INDEX];
                for (i = 0; i < TPS92662A_MAX_CHANNEL_NUM; i++)
                {
                    Tps92662AInitDataSrc.DefaultPwm[i] = tpspara[(LMM_PWM_INDEX + i)];
                    Tps92662AInitDataSrc.PhaseShift[i] = phaseshif[i];
                }
                MatrixTripDataPackets.dev_address = tmp->dev_address;
                MatrixTripDataPackets.DataType = E_MatrixTripDataType_DevInit;
                MatrixTripDataPackets.datasrc = (void *)(&Tps92662AInitDataSrc);
                rtval |= tmp->DeviceInit((void *)(&MatrixTripDataPackets));
            }
        }
        else if (tmp->MatrixChipType == E_TLD7002)
        {
            
        }
        tmp = tmp->ptNext;
    }

    for (i = 0; i < MatrixDrvRegisterNum; i++)
    {
        for (j = 0; j < MAX_MATRIXCHIP_CHANNEL_NUM; j++)
        {
            if (g_S_MatrixDrvInfo[i].CurPwm[j] != UNUSED_PWM_VALUE)
                g_S_MatrixDrvInfo[i].CurPwm[j] = 0;
        }
    }

    return rtval;
}
