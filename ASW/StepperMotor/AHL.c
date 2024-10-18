/********************************
 * AHL.c
 *
 *  Created on: 2024/5/6
 *      Author: tujiongjiong
 ********************************/


/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "AHL.h"
#include <stdlib.h>
#include <math.h>

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
static S_AHLConfigInfo gs_AHLConfigInfo;

static S_AHLRunInfo gs_AHLRunInfo =
{
    .AHLMode = E_AHLMode_OFF,
    .Static_AngleIncre = 0,
    .Static_PosIncre = 0,
    .Dynamic_SlopeAngleIncre = 0,
    .Dynamic_SlopePosIncre = 0,
    .Dynamic_RpAccPosIncre = 0,
    .Dynamic_RpBrkPosIncre = 0,
    .AccelerateSpeed = 0,
};

static S_AHLDidInfo gs_AHLDidInfo = { .AHLStatus = AHLStatus_Res };

/****************************************************************
 *                                                              *
 *                   Private Functions Define                   *
 *                                                              *
 ****************************************************************/

/* 读取调平电机参数配置并存放 */
static Std_ReturnType AHL_GetParameterIntoInfo(void)
{
    Std_ReturnType rtval = E_OK;

    gs_AHLConfigInfo.LvlType = (E_LvlType)Get_pVehLvLType();

    gs_AHLConfigInfo.WheelBase = Get_pVehWheelBase() * 0.001;
    gs_AHLConfigInfo.HeadlampOverhang = Get_pVehHeadlampOverhang() * 0.001;
    gs_AHLConfigInfo.HeadlampHeight = Get_pVehHeadlampHeight() * 0.001;

    return rtval;
}

/* 计算大灯所需的角度增量，单位rad，仰为正方向 */
static double AHL_CalculateNeededAngleIncre(void)
{
    uint32_t SignalValue;
    double SuspPosnVertLvlFrnt; /* 前悬架高度坐标值，向上为正方向 */
    double SuspPosnVertLvlRe;   /* 后悬架高度坐标值，向上为正方向 */
    double VehIncliAngle;       /* 车辆倾斜角，单位rad；仰为正方向 */
    double HeadlampHeightIncre; /* 大灯高度增量；向上为正方向 */
    double AngleIncre;

    Interface_GetSignal_SuspPosnVertLvlFrnt(&SignalValue);
    SuspPosnVertLvlFrnt = MotorManage_ConvertSigned_xToSigned_32(SignalValue, 15) * 0.000062;
    Interface_GetSignal_SuspPosnVertLvlRe(&SignalValue);
    SuspPosnVertLvlRe = MotorManage_ConvertSigned_xToSigned_32(SignalValue, 15) * 0.000062;

    VehIncliAngle = asin((SuspPosnVertLvlFrnt - SuspPosnVertLvlRe) / gs_AHLConfigInfo.WheelBase); /* 根据前后悬架高度差和前后轴距，用反正弦函数计算车辆倾斜角 */
    HeadlampHeightIncre = SuspPosnVertLvlFrnt + gs_AHLConfigInfo.HeadlampOverhang * tan(VehIncliAngle); /* 前悬架高度 + 大灯与前轴距离 * 车辆倾斜角正切值 */

    AngleIncre = - (HeadlampHeightIncre / sqrt(gs_AHLConfigInfo.HeadlampHeight * gs_AHLConfigInfo.HeadlampHeight + LB_DISTANCE * LB_DISTANCE) + VehIncliAngle); /* 大灯高度增量引起的角度增量 + 车辆倾斜角引起的角度增量 */

    return AngleIncre;
}

/* AHL静态调平 */
static Std_ReturnType AHL_StaticLeveling_50ms()
{
    Std_ReturnType rtval = E_OK;

    gs_AHLRunInfo.AHLMode = E_AHLMode_Static;

    /* 滤波延时 */
    static uint16_t FilterTime = STATIC_FILT_TIME;
    if(FilterTime < STATIC_FILT_TIME)
    {
        FilterTime += 50;
        return rtval;
    }
    else
    {
        FilterTime = 0;
    }

    gs_AHLRunInfo.Static_AngleIncre = AHL_CalculateNeededAngleIncre(); /* 计算需要执行的角度增量 */
    gs_AHLRunInfo.Static_PosIncre = MotorManage_LvlConvertAglIncreToPosIncre(gs_AHLRunInfo.Static_AngleIncre); /* 转换静态位置增量 */
    MotorManage_SetLevelingPosIncre(E_LvlFunction_AHL, gs_AHLRunInfo.Static_PosIncre);

    gs_AHLRunInfo.Dynamic_SlopeAngleIncre = gs_AHLRunInfo.Static_AngleIncre; /* 初始动态坡道角度值为静态角度值 */
    gs_AHLRunInfo.Dynamic_SlopePosIncre = gs_AHLRunInfo.Static_PosIncre; /* 初始化坡道电机位置增量，防止刚进入动态模式时就进入急加减速模式 */
    return rtval;
}



/* 40深度循环FIFO，差值计数 */
static uint8_t AHL_CycleFIFO_DeviationCount(double NewData, double DeviaVal)
{
    uint8_t i;
    uint8_t DeviationNum = 0;
    static double Data[41] = {0};

    /* 循环压入数据 */
    for(i = 0; i < 40; i++)
    {
        Data[i] = Data[i + 1];
    }
    Data[40] = NewData;

    /* 差值计数 */
    for(i = 0; i < 40; i++)
    {
        if(fabs(Data[i] - Data[i + 1]) > DeviaVal)
        {
            DeviationNum++;
        }
    }
    return DeviationNum;
}

/* 计算车辆加速度 */
static void AHL_CalculateAccelerateSpeed_50ms(void)
{
    static double VehSpeed[5] = {0}; /* 存放最近5次的车速值，首尾时间间隔为200ms（200ms是接收间隔40ms和读取间隔50ms的最小公倍数，保证读取的首尾时间间隔与实际接收时间间隔一致） */
    uint8_t i;

    /* 循环压入一次车速值 */
    for(i = 0; i < 4; i++)
    {
        VehSpeed[i] = VehSpeed[i + 1];
    }
    Interface_GetSignal_VehSpdLgtA(&VehSpeed[4]);

    gs_AHLRunInfo.AccelerateSpeed = (VehSpeed[4] - VehSpeed[0]) / 0.2; /* 首尾时间间隔为200ms，首尾差值计算加速度 */
}

/* AHL动态调平 */
static Std_ReturnType AHL_DynamicLeveling_50ms()
{
    Std_ReturnType rtval = E_OK;
    double CurrNeededAngleIncre = 0.0;

    CurrNeededAngleIncre = AHL_CalculateNeededAngleIncre(); /* 计算当前需要执行的角度增量 */

    /* 颠簸路面检测 */
    uint8_t DeviaCount;
    switch( gs_AHLRunInfo.AHLMode )
    {
        case E_AHLMode_OFF:
        case E_AHLMode_Static:
        case E_AHLMode_Dyna_Bumpy:
        case E_AHLMode_Dyna_Slope:
        DeviaCount = AHL_CycleFIFO_DeviationCount(CurrNeededAngleIncre, BUMPY_ANGLE_THRES * RAD_PER_DEG); /* 最近41次读取的车辆角度值，总时间2s，两两差值过大计数 */
        if(DeviaCount >= BUMPY_COUNT_ENTER)
        {
            gs_AHLRunInfo.AHLMode = E_AHLMode_Dyna_Bumpy;
        }
        else if(DeviaCount <= BUMPY_COUNT_QUIT)
        {
            gs_AHLRunInfo.AHLMode = E_AHLMode_Dyna_Slope;
        }
    }

    /* 急加减速模式转换 */
    static uint16_t RapidKeepTime = 0; /* 急加减速模式保持时间 */
    switch( gs_AHLRunInfo.AHLMode )
    {
        case E_AHLMode_Dyna_Slope:
            if(gs_AHLRunInfo.AccelerateSpeed * 3.6 > RAPID_ACCSP_THRES) /* 急加速 */
            {
                gs_AHLRunInfo.AHLMode = E_AHLMode_Dyna_RapidAccel;
            }
            else if(gs_AHLRunInfo.AccelerateSpeed * 3.6 < -RAPID_ACCSP_THRES) /* 急减速 */
            {
                gs_AHLRunInfo.AHLMode = E_AHLMode_Dyna_RapidBrake;
            }
            break;

        case E_AHLMode_Dyna_RapidAccel:
        case E_AHLMode_Dyna_RapidBrake:
            if(RapidKeepTime < RAPID_KEEP_TIME) /* 保持一定时间 */
            {
                RapidKeepTime += 50;
            }
            else /* 保持时间到，判断一次 */
            {
                if(gs_AHLRunInfo.AccelerateSpeed * 3.6 > RAPID_ACCSP_THRES) /* 急加速 */
                {
                    gs_AHLRunInfo.AHLMode = E_AHLMode_Dyna_RapidAccel;
                }
                else if(gs_AHLRunInfo.AccelerateSpeed * 3.6 < -RAPID_ACCSP_THRES) /* 急减速 */
                {
                    gs_AHLRunInfo.AHLMode = E_AHLMode_Dyna_RapidBrake;
                }
                else
                {
                    gs_AHLRunInfo.AHLMode = E_AHLMode_Dyna_Slope;
                }
                RapidKeepTime = 0;
            }
    }

    /* 计算动态调平的值 */
    static uint16_t s_SlopeConfirmTime = 0; /* 坡道确认时间 */
    switch( gs_AHLRunInfo.AHLMode )
    {
        case E_AHLMode_Dyna_Slope:
            if(fabs(CurrNeededAngleIncre - gs_AHLRunInfo.Dynamic_SlopeAngleIncre) * DEG_PER_RAD >= SLOPE_ANGLE_THRES) /* 车辆角度与静态相比，有较大角度变化 */
            {
                if(s_SlopeConfirmTime < SLOPE_CONFRM_TIME) /* 延时确认 */
                {
                    s_SlopeConfirmTime += 50;
                }
                else
                {
                    gs_AHLRunInfo.Dynamic_SlopeAngleIncre = CurrNeededAngleIncre; /* 刷新动态坡道角度值 */
                    gs_AHLRunInfo.Dynamic_SlopePosIncre = MotorManage_LvlConvertAglIncreToPosIncre(gs_AHLRunInfo.Dynamic_SlopeAngleIncre); /* 动态坡道模式位置增量，也作为急加减速的基础值 */
                    s_SlopeConfirmTime = 0;             /* 再次计时检测 */
                }
            }
            break;

        case E_AHLMode_Dyna_RapidAccel:
            gs_AHLRunInfo.Dynamic_RpAccPosIncre = gs_AHLRunInfo.Dynamic_SlopePosIncre + MotorManage_LvlConvertAglIncreToPosIncre( - (RAPID_FIXED_ANGLE * RAD_PER_DEG));
            break;

        case E_AHLMode_Dyna_RapidBrake:
            gs_AHLRunInfo.Dynamic_RpBrkPosIncre = gs_AHLRunInfo.Dynamic_SlopePosIncre + MotorManage_LvlConvertAglIncreToPosIncre(RAPID_FIXED_ANGLE * RAD_PER_DEG);
    }
    
    /* 设置电机位置增量 */
    switch( gs_AHLRunInfo.AHLMode )
    {
        case E_AHLMode_Dyna_Slope:
            MotorManage_SetLevelingPosIncre(E_LvlFunction_AHL, gs_AHLRunInfo.Dynamic_SlopePosIncre);
            break;
        case E_AHLMode_Dyna_RapidAccel:
            MotorManage_SetLevelingPosIncre(E_LvlFunction_AHL, gs_AHLRunInfo.Dynamic_RpAccPosIncre);
            break;
        case E_AHLMode_Dyna_RapidBrake:
            MotorManage_SetLevelingPosIncre(E_LvlFunction_AHL, gs_AHLRunInfo.Dynamic_RpBrkPosIncre);
    }
    return rtval;
}

/* AHL故障检测 */
static Std_ReturnType AHL_FaultDetection(uint8_t timebase)
{
    Std_ReturnType rtval = E_OK;
    U_LvlFuncErrSta LvlFuncErrSta;
    U_DisSrc_t AHLDerateSta;

    LvlFuncErrSta = MotorManage_GetLevelingFuncErrorState();
    GetLgtFuncDisSrc_AHL(& AHLDerateSta);  /* 降额状态 */

    if( LvlFuncErrSta.Bits.SigErr_AHL == 1u ||
        LvlFuncErrSta.Bits.MotErr_AHL == 1u ||
        AHLDerateSta.bits.sp_los == 1u )
    {
        gs_AHLRunInfo.AHLMode = E_AHLMode_ERROR;
    }
    else
    {
        if(gs_AHLRunInfo.AHLMode == E_AHLMode_ERROR)
        {
            gs_AHLRunInfo.AHLMode = E_AHLMode_OFF;
        }
    }
    return rtval;
}

/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
/* 设置AHL的DID数据，4368 */
Std_ReturnType AHL_SetDID_4368_AHLStatus(void)
{
    Std_ReturnType rtval = E_OK;

    /* 填充DID信息 */
    if(gs_AHLRunInfo.AHLMode == E_AHLMode_OFF)
    {
        gs_AHLDidInfo.AHLStatus = AHLStatus_Off;
    }
    else if(gs_AHLRunInfo.AHLMode == E_AHLMode_ERROR)
    {
        gs_AHLDidInfo.AHLStatus = AHLStatus_Error;
    }
    else
    {
        gs_AHLDidInfo.AHLStatus = AHLStatus_On;
    }

    rtval |= Interface_SetDidSignalData(DIDSIGNALNAME_ID_StsOfAHL, (uint32_t)gs_AHLDidInfo.AHLStatus);

    return rtval;
}


/* AHL初始化 */
void AHL_Init(void)
{
    AHL_GetParameterIntoInfo();
}


/* AHL主函数 */
/* 固定放到50ms任务中 */
void AHL_MainFunction_50ms(void)
{
    if(gs_AHLConfigInfo.LvlType == E_LvlType_AHL) /* 调平类型为自动 */
    {
        AHL_CalculateAccelerateSpeed_50ms(); /* 刷新加速度值 */

        E_LvlRefRunSts LvlRefRunSts;
        LvlRefRunSts = LevelingMotor_GetLvlRefRunSts();

        if(LvlRefRunSts == E_LvlRefRunSts_Done) /* 参考运行完成，开始调平 */
        {
            uint32_t ActvnOfAhl;
            Interface_GetSignal_ActvnOfAhl(& ActvnOfAhl);

            if(ActvnOfAhl == 1u) /* AHL激活 */
            {
                AHL_FaultDetection(50u); /* 故障检测 */
                if(gs_AHLRunInfo.AHLMode == E_AHLMode_ERROR)
                {
                    MotorManage_SetLevelingPosIncre(E_LvlFunction_AHL, 0u);
                    Interface_SetSignal_StsOfLvlg( 0x2u );
                }
                else
                {
                    double VehSpdLgtA;
                    Interface_GetSignal_VehSpdLgtA(&VehSpdLgtA);

                    if(VehSpdLgtA * 3.6 <= 4.0) /* 静态调平 */
                    {
                        AHL_StaticLeveling_50ms();
                    }
                    else if(VehSpdLgtA * 3.6 > 4.0) /* 动态调平 */
                    {
                        AHL_DynamicLeveling_50ms();
                    }
                    Interface_SetSignal_StsOfLvlg( 0x1u );
                }
            }
            else if(ActvnOfAhl == 0u) /* AHL关闭 */
            {
                MotorManage_SetLevelingPosIncre(E_LvlFunction_AHL, 0u);
                Interface_SetSignal_StsOfLvlg( 0x0u );
                gs_AHLRunInfo.AHLMode = E_AHLMode_OFF;
            }
        }
        else if(LvlRefRunSts == E_LvlRefRunSts_NoCond || LvlRefRunSts == E_LvlRefRunSts_Error)/* 电机参考运行条件不满足或有故障 */
        {
            uint32_t ActvnOfAhl;

            Interface_GetSignal_ActvnOfAhl(& ActvnOfAhl);
            if(ActvnOfAhl == 1u)
            {
                Interface_SetSignal_StsOfLvlg( 0x2u );
            }
            else if(ActvnOfAhl == 0u)
            {
                Interface_SetSignal_StsOfLvlg( 0x0u );
            }
            gs_AHLRunInfo.AHLMode = E_AHLMode_OFF;
        }
        else if(LvlRefRunSts == E_LvlRefRunSts_During) /* 电机参考运行正在执行中 */
        {
            Interface_SetSignal_StsOfLvlg( 0x0u );
            gs_AHLRunInfo.AHLMode = E_AHLMode_OFF;
        }

        switch( gs_AHLRunInfo.AHLMode )
        {
            case E_AHLMode_OFF:
                MotorManage_SetLevelingFuncActState(E_LvlFunction_AHL, 0u);
                break;
            case E_AHLMode_Static:
            case E_AHLMode_Dyna_Bumpy:
            case E_AHLMode_Dyna_Slope:
            case E_AHLMode_Dyna_RapidAccel:
            case E_AHLMode_Dyna_RapidBrake:
            case E_AHLMode_ERROR:
                MotorManage_SetLevelingFuncActState(E_LvlFunction_AHL, 1u);
        }
    }
}


