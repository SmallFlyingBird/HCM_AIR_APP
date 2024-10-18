/********************************
 * DBL.c
 *
 *  Created on: 2024/6/12
 *      Author: tujiongjiong
 ********************************/


/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "DBL.h"
#include <stdlib.h>
#include <math.h>

/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
static S_DBLConfigInfo gs_DBLConfigInfo;
static S_DBLRunInfo gs_DBLRunInfo =
{
    .DBLState = E_DBLState_OFF,
    .ShiftNumTop_Last = 0,
    .ShiftNumMddl_Last = 0,
    .ShiftNumBttm_Last = 0,
    .ShiftNumTop_Curr = 0,
    .ShiftNumMddl_Curr = 0,
    .ShiftNumBttm_Curr = 0,
    .BendingAngle = 0,
    .ptLBKinkPWM = NULL,
    .PxlShiftPWM = {0}
};

static S_DBLDidInfo gs_DBLDidInfo = { .DBLStatus = DBLStatus_Res };

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

/* 读取调平电机参数配置并存放 */
static Std_ReturnType DBL_GetParameterIntoInfo(void)
{
    Std_ReturnType rtval = E_OK;

    gs_DBLConfigInfo.VehDBLType = (E_DBLType)Get_pVehDBLType();

    gs_DBLConfigInfo.CntrPxlBttm   = Get_pDBCntrPxlBttmRow();
    gs_DBLConfigInfo.CntrPxlMddl   = Get_pDBCntrPxlMddlRow();
    gs_DBLConfigInfo.CntrPxlTop    = Get_pDBCntrPxlTopRow();
    gs_DBLConfigInfo.LeEdgePxlBttm = Get_pDBLeEdgePxlHLBttmRow();
    gs_DBLConfigInfo.RiEdgePxlBttm = Get_pDBRiEdgePxlHLBttmRow();
    gs_DBLConfigInfo.LeEdgePxlMddl = Get_pDBLeEdgePxlHLMddlRow();
    gs_DBLConfigInfo.RiEdgePxlMddl = Get_pDBRiEdgePxlHLMddlRow();
    gs_DBLConfigInfo.LeEdgePxlTop  = Get_pDBLeEdgePxlHLTopRow();
    gs_DBLConfigInfo.RiEdgePxlTop  = Get_pDBRiEdgePxlHLTopRow();
    gs_DBLConfigInfo.LeLimPxlBttm  = Get_pDBLeLimBttmRow();
    gs_DBLConfigInfo.RiLimPxlBttm  = Get_pDBRiLimBttmRow();
    gs_DBLConfigInfo.LeLimPxlMddl  = Get_pDBLeLimMddlRow();
    gs_DBLConfigInfo.RiLimPxlMddl  = Get_pDBRiLimMddlRow();
    gs_DBLConfigInfo.LeLimPxlTop   = Get_pDBLeLimTopRow();
    gs_DBLConfigInfo.RiLimPxlTop   = Get_pDBRiLimTopRow();
    gs_DBLConfigInfo.TrnsnTime     = Get_pDBTrnsntime();
    gs_DBLConfigInfo.ShiftDlyTime  = Get_pDBPxlShiftDlyTime();

#if HCM_LEFT_SIDE
    gs_DBLConfigInfo.ptLowBeamPWM      = Get_pLowBeamPWMPixel_P();
    gs_DBLConfigInfo.ptTownLightPWM    = Get_pTownLightPWMPixel_P();
    gs_DBLConfigInfo.ptMotorWayPWM     = Get_pMotorWayPWMPixel_P();
    gs_DBLConfigInfo.ptCountryLightPWM = Get_pCountryLightPWMPixel_P();
    gs_DBLConfigInfo.ptWeatherLightPWM = Get_pWeatherLightPWMPixel_P();
    gs_DBLConfigInfo.ptLHTPWM          = Get_pLHTPWMPixel_P();

    gs_DBLConfigInfo.ptLBPxlLeBdr = Get_pPixelLeft_LeftBdr();
    gs_DBLConfigInfo.ptLBPxlRiBdr = Get_pPixelLeft_RightBdr();
#elif HCM_RIGHT_SIDE
    gs_DBLConfigInfo.ptLowBeamPWM      = Get_pLowBeamPWMPixel_R_P();
    gs_DBLConfigInfo.ptTownLightPWM    = Get_pTownLightPWMPixel_R_P();
    gs_DBLConfigInfo.ptMotorWayPWM     = Get_pMotorWayPWMPixel_R_P();
    gs_DBLConfigInfo.ptCountryLightPWM = Get_pCountryLightPWMPixel_R_P();
    gs_DBLConfigInfo.ptWeatherLightPWM = Get_pWeatherLightPWMPixel_R_P();
    gs_DBLConfigInfo.ptLHTPWM          = Get_pLHTPWMPixel_R_P();

    gs_DBLConfigInfo.ptLBPxlLeBdr = Get_pPixelRight_LeftBdr();
    gs_DBLConfigInfo.ptLBPxlRiBdr = Get_pPixelRight_RightBdr();
#endif
    gs_DBLConfigInfo.DBLCornerLightPWM = Get_pSBLCornerLightPWM();

    gs_DBLRunInfo.ptLBKinkPWM = gs_DBLConfigInfo.ptLowBeamPWM;
    return rtval;
}

/* DBL电机调节 */
/* BendAngle：单位rad 左转为正 */
static Std_ReturnType DBL_Motor(double BendAngle)
{
    Std_ReturnType rtval = E_OK;
    static double s_HeadLampAgIncre = 0; /* 大灯角度增量，单位rad，左转为负 */

    if((fabs((- BendAngle) - s_HeadLampAgIncre) * DEG_PER_RAD) > (DEGREE_MIN_DIF / STRW_FRTW_RATE)) /* 差值需大于最小执行角度 */
    {
        s_HeadLampAgIncre = - BendAngle;
    }
    else
    {
        return rtval;
    }
    sint16_t MotorPosIncre = 0;

    MotorPosIncre = MotorManage_SvlConvertAngleIncreToPosIncre(s_HeadLampAgIncre);
    MotorManage_SetSwivelingPosIncre(E_SvlFunction_DBL, MotorPosIncre);
    return rtval;
}





/* 矩阵DBL的LBKink的PWM转换（根据AFS和旅行模式） */
static void DBL_MatrixLBKinkPwmChange(void)
{
    uint8_t TOUR_LBKinkOnSta;
    E_VCEW_t e_AFSRunMode;

    TOUR_LBKinkOnSta = TOUR_is_LBKinkOn();
    e_AFSRunMode = AFS_Get_cvew();

    if(TOUR_LBKinkOnSta == 1u)
    {
        gs_DBLRunInfo.ptLBKinkPWM = gs_DBLConfigInfo.ptLHTPWM;
    }
    else
    {
        switch( e_AFSRunMode )
        {
            case VCEW_U:
                gs_DBLRunInfo.ptLBKinkPWM = gs_DBLConfigInfo.ptLowBeamPWM;
                break;
            case VCEW_V:
                gs_DBLRunInfo.ptLBKinkPWM = gs_DBLConfigInfo.ptTownLightPWM;
                break;
            case VCEW_C:
                gs_DBLRunInfo.ptLBKinkPWM = gs_DBLConfigInfo.ptCountryLightPWM;
                break;
            case VCEW_E:
                gs_DBLRunInfo.ptLBKinkPWM = gs_DBLConfigInfo.ptMotorWayPWM;
                break;
            case VCEW_W:
                gs_DBLRunInfo.ptLBKinkPWM = gs_DBLConfigInfo.ptWeatherLightPWM;
        }
    }
}

/* DBL近光单层像素左右移 */
static void DBL_PixelShift(sint8_t ShiftNum, uint8_t LeEdgePxl, uint8_t RiEdgePxl)
{
    uint8_t PixelId;

    if(ShiftNum < 0u) /* 左移 */
    {
        ShiftNum = - ShiftNum;
        for(PixelId = LeEdgePxl; PixelId <= RiEdgePxl; PixelId++)
        {
            if(PixelId + ShiftNum <= RiEdgePxl)
            {
                gs_DBLRunInfo.PxlShiftPWM[PixelId - 1] = gs_DBLRunInfo.ptLBKinkPWM[PixelId + ShiftNum - 1];
            }
            else
            {
                gs_DBLRunInfo.PxlShiftPWM[PixelId - 1] = gs_DBLRunInfo.ptLBKinkPWM[RiEdgePxl - 1];
            }
        }
    }
    else if(ShiftNum >= 0u) /* 右移 */
    {
        for(PixelId = RiEdgePxl; PixelId >= LeEdgePxl; PixelId--)
        {
            if(PixelId - ShiftNum >= LeEdgePxl)
            {
                gs_DBLRunInfo.PxlShiftPWM[PixelId - 1] = gs_DBLRunInfo.ptLBKinkPWM[PixelId - ShiftNum - 1];
            }
            else
            {
                gs_DBLRunInfo.PxlShiftPWM[PixelId - 1] = gs_DBLRunInfo.ptLBKinkPWM[LeEdgePxl - 1];
            }
        }
    }
}

/* 刷新像素位移数量 */
/* PixelOffsetAg：单位：deg 向右为正 */
static void DBL_RefreshPixelShiftNum(double PixelOffsetAg)
{
    uint8_t PixelId;

    gs_DBLRunInfo.ShiftNumTop_Last = gs_DBLRunInfo.ShiftNumTop_Curr;
    gs_DBLRunInfo.ShiftNumMddl_Last = gs_DBLRunInfo.ShiftNumMddl_Curr;
    gs_DBLRunInfo.ShiftNumBttm_Last = gs_DBLRunInfo.ShiftNumBttm_Curr;

    if(PixelOffsetAg < 0) /* 左偏 */
    {
        if(gs_DBLConfigInfo.LeEdgePxlTop > 0 && gs_DBLConfigInfo.RiEdgePxlTop > 0) /* 顶层 */
        {
            for(PixelId = gs_DBLConfigInfo.CntrPxlTop; PixelId >= gs_DBLConfigInfo.LeLimPxlTop; PixelId--)
            {
                if( (PixelOffsetAg > gs_DBLConfigInfo.ptLBPxlLeBdr[PixelId - 1] * 0.01 - 90.0) &&
                    (PixelOffsetAg < gs_DBLConfigInfo.ptLBPxlRiBdr[PixelId - 1] * 0.01 - 90.0) )
                {
                    if(gs_DBLRunInfo.ShiftNumTop_Curr - (PixelId - gs_DBLConfigInfo.CntrPxlTop) == -1)
                    {
                        if( (PixelOffsetAg > gs_DBLConfigInfo.ptLBPxlLeBdr[PixelId - 1] * 0.01 - 90.0 + (DEGREE_PXL_HYS / STRW_FRTW_RATE)) &&
                            (PixelOffsetAg < gs_DBLConfigInfo.ptLBPxlRiBdr[PixelId - 1] * 0.01 - 90.0 - (DEGREE_PXL_HYS / STRW_FRTW_RATE)) )
                        {
                            gs_DBLRunInfo.ShiftNumTop_Curr = PixelId - gs_DBLConfigInfo.CntrPxlTop;
                        }
                    }
                    else
                    {
                        gs_DBLRunInfo.ShiftNumTop_Curr = PixelId - gs_DBLConfigInfo.CntrPxlTop;
                    }
                    break;
                }
                else if(PixelId == gs_DBLConfigInfo.LeLimPxlTop)
                {
                    gs_DBLRunInfo.ShiftNumTop_Curr = gs_DBLConfigInfo.LeLimPxlTop - gs_DBLConfigInfo.CntrPxlTop;
                }
            }
        }
        if(gs_DBLConfigInfo.LeEdgePxlMddl > 0 && gs_DBLConfigInfo.RiEdgePxlMddl > 0) /* 中间层 */
        {
            for(PixelId = gs_DBLConfigInfo.CntrPxlMddl; PixelId >= gs_DBLConfigInfo.LeLimPxlMddl; PixelId--)
            {
                if( (PixelOffsetAg > gs_DBLConfigInfo.ptLBPxlLeBdr[PixelId - 1] * 0.01 - 90.0) &&
                    (PixelOffsetAg < gs_DBLConfigInfo.ptLBPxlRiBdr[PixelId - 1] * 0.01 - 90.0) )
                {
                    if(gs_DBLRunInfo.ShiftNumMddl_Curr - (PixelId - gs_DBLConfigInfo.CntrPxlMddl) == -1)
                    {
                        if( (PixelOffsetAg > gs_DBLConfigInfo.ptLBPxlLeBdr[PixelId - 1] * 0.01 - 90.0 + (DEGREE_PXL_HYS / STRW_FRTW_RATE)) &&
                            (PixelOffsetAg < gs_DBLConfigInfo.ptLBPxlRiBdr[PixelId - 1] * 0.01 - 90.0 - (DEGREE_PXL_HYS / STRW_FRTW_RATE)) )
                        {
                            gs_DBLRunInfo.ShiftNumMddl_Curr = PixelId - gs_DBLConfigInfo.CntrPxlMddl;
                        }
                    }
                    else
                    {
                        gs_DBLRunInfo.ShiftNumMddl_Curr = PixelId - gs_DBLConfigInfo.CntrPxlMddl;
                    }
                    break;
                }
                else if(PixelId == gs_DBLConfigInfo.LeLimPxlMddl)
                {
                    gs_DBLRunInfo.ShiftNumMddl_Curr = gs_DBLConfigInfo.LeLimPxlMddl - gs_DBLConfigInfo.CntrPxlMddl;
                }
            }
        }
        if(gs_DBLConfigInfo.LeEdgePxlBttm > 0 && gs_DBLConfigInfo.RiEdgePxlBttm > 0) /* 底层 */
        {
            for(PixelId = gs_DBLConfigInfo.CntrPxlBttm; PixelId >= gs_DBLConfigInfo.LeLimPxlBttm; PixelId--)
            {
                if( (PixelOffsetAg > gs_DBLConfigInfo.ptLBPxlLeBdr[PixelId - 1] * 0.01 - 90.0) &&
                    (PixelOffsetAg < gs_DBLConfigInfo.ptLBPxlRiBdr[PixelId - 1] * 0.01 - 90.0) )
                {
                    if(gs_DBLRunInfo.ShiftNumBttm_Curr - (PixelId - gs_DBLConfigInfo.CntrPxlBttm) == -1)
                    {
                        if( (PixelOffsetAg > gs_DBLConfigInfo.ptLBPxlLeBdr[PixelId - 1] * 0.01 - 90.0 + (DEGREE_PXL_HYS / STRW_FRTW_RATE)) &&
                            (PixelOffsetAg < gs_DBLConfigInfo.ptLBPxlRiBdr[PixelId - 1] * 0.01 - 90.0 - (DEGREE_PXL_HYS / STRW_FRTW_RATE)) )
                        {
                            gs_DBLRunInfo.ShiftNumBttm_Curr = PixelId - gs_DBLConfigInfo.CntrPxlBttm;
                        }
                    }
                    else
                    {
                        gs_DBLRunInfo.ShiftNumBttm_Curr = PixelId - gs_DBLConfigInfo.CntrPxlBttm;
                    }
                    break;
                }
                else if(PixelId == gs_DBLConfigInfo.LeLimPxlBttm)
                {
                    gs_DBLRunInfo.ShiftNumBttm_Curr = gs_DBLConfigInfo.LeLimPxlBttm - gs_DBLConfigInfo.CntrPxlBttm;
                }
            }
        }
    }
    else if(PixelOffsetAg >= 0) /* 右偏 */
    {
        if(gs_DBLConfigInfo.LeEdgePxlTop > 0 && gs_DBLConfigInfo.RiEdgePxlTop > 0) /* 顶层 */
        {
            for(PixelId = gs_DBLConfigInfo.CntrPxlTop; PixelId <= gs_DBLConfigInfo.RiLimPxlTop; PixelId++)
            {
                if( (PixelOffsetAg > gs_DBLConfigInfo.ptLBPxlLeBdr[PixelId - 1] * 0.01 - 90.0) &&
                    (PixelOffsetAg < gs_DBLConfigInfo.ptLBPxlRiBdr[PixelId - 1] * 0.01 - 90.0) )
                {
                    if(gs_DBLRunInfo.ShiftNumTop_Curr - (PixelId - gs_DBLConfigInfo.CntrPxlTop) == 1)
                    {
                        if( (PixelOffsetAg > gs_DBLConfigInfo.ptLBPxlLeBdr[PixelId - 1] * 0.01 - 90.0 + (DEGREE_PXL_HYS / STRW_FRTW_RATE)) &&
                            (PixelOffsetAg < gs_DBLConfigInfo.ptLBPxlRiBdr[PixelId - 1] * 0.01 - 90.0 - (DEGREE_PXL_HYS / STRW_FRTW_RATE)) )
                        {
                            gs_DBLRunInfo.ShiftNumTop_Curr = PixelId - gs_DBLConfigInfo.CntrPxlTop;
                        }
                    }
                    else
                    {
                        gs_DBLRunInfo.ShiftNumTop_Curr = PixelId - gs_DBLConfigInfo.CntrPxlTop;
                    }
                    break;
                }
                else if(PixelId == gs_DBLConfigInfo.RiLimPxlTop)
                {
                    gs_DBLRunInfo.ShiftNumTop_Curr = gs_DBLConfigInfo.RiLimPxlTop - gs_DBLConfigInfo.CntrPxlTop;
                }
            }
        }
        if(gs_DBLConfigInfo.LeEdgePxlMddl > 0 && gs_DBLConfigInfo.RiEdgePxlMddl > 0) /* 中间层 */
        {
            for(PixelId = gs_DBLConfigInfo.CntrPxlMddl; PixelId <= gs_DBLConfigInfo.RiLimPxlMddl; PixelId++)
            {
                if( (PixelOffsetAg > gs_DBLConfigInfo.ptLBPxlLeBdr[PixelId - 1] * 0.01 - 90.0) &&
                    (PixelOffsetAg < gs_DBLConfigInfo.ptLBPxlRiBdr[PixelId - 1] * 0.01 - 90.0) )
                {
                    if(gs_DBLRunInfo.ShiftNumMddl_Curr - (PixelId - gs_DBLConfigInfo.CntrPxlMddl) == 1)
                    {
                        if( (PixelOffsetAg > gs_DBLConfigInfo.ptLBPxlLeBdr[PixelId - 1] * 0.01 - 90.0 + (DEGREE_PXL_HYS / STRW_FRTW_RATE)) &&
                            (PixelOffsetAg < gs_DBLConfigInfo.ptLBPxlRiBdr[PixelId - 1] * 0.01 - 90.0 - (DEGREE_PXL_HYS / STRW_FRTW_RATE)) )
                        {
                            gs_DBLRunInfo.ShiftNumMddl_Curr = PixelId - gs_DBLConfigInfo.CntrPxlMddl;
                        }
                    }
                    else
                    {
                        gs_DBLRunInfo.ShiftNumMddl_Curr = PixelId - gs_DBLConfigInfo.CntrPxlMddl;
                    }
                    break;
                }
                else if(PixelId == gs_DBLConfigInfo.RiLimPxlMddl)
                {
                    gs_DBLRunInfo.ShiftNumMddl_Curr = gs_DBLConfigInfo.RiLimPxlMddl - gs_DBLConfigInfo.CntrPxlMddl;
                }
            }
        }
        if(gs_DBLConfigInfo.LeEdgePxlBttm > 0 && gs_DBLConfigInfo.RiEdgePxlBttm > 0) /* 底层 */
        {
            for(PixelId = gs_DBLConfigInfo.CntrPxlBttm; PixelId <= gs_DBLConfigInfo.RiLimPxlBttm; PixelId++)
            {
                if( (PixelOffsetAg > gs_DBLConfigInfo.ptLBPxlLeBdr[PixelId - 1] * 0.01 - 90.0) &&
                    (PixelOffsetAg < gs_DBLConfigInfo.ptLBPxlRiBdr[PixelId - 1] * 0.01 - 90.0) )
                {
                    if(gs_DBLRunInfo.ShiftNumBttm_Curr - (PixelId - gs_DBLConfigInfo.CntrPxlBttm) == 1)
                    {
                        if( (PixelOffsetAg > gs_DBLConfigInfo.ptLBPxlLeBdr[PixelId - 1] * 0.01 - 90.0 + (DEGREE_PXL_HYS / STRW_FRTW_RATE)) &&
                            (PixelOffsetAg < gs_DBLConfigInfo.ptLBPxlRiBdr[PixelId - 1] * 0.01 - 90.0 - (DEGREE_PXL_HYS / STRW_FRTW_RATE)) )
                        {
                            gs_DBLRunInfo.ShiftNumBttm_Curr = PixelId - gs_DBLConfigInfo.CntrPxlBttm;
                        }
                    }
                    else
                    {
                        gs_DBLRunInfo.ShiftNumBttm_Curr = PixelId - gs_DBLConfigInfo.CntrPxlBttm;
                    }
                    break;
                }
                else if(PixelId == gs_DBLConfigInfo.RiLimPxlBttm)
                {
                    gs_DBLRunInfo.ShiftNumBttm_Curr = gs_DBLConfigInfo.RiLimPxlBttm - gs_DBLConfigInfo.CntrPxlBttm;
                }
            }
        }
    }
}

/* DBL矩阵LED调节 */
/* BendAngle：单位rad 左转为正 */
static Std_ReturnType DBL_Matrix(double BendAngle)
{
    Std_ReturnType rtval = E_OK;
    double PixelOffsetAg; /* deg */

    PixelOffsetAg = - (BendAngle * DEG_PER_RAD);
    DBL_RefreshPixelShiftNum(PixelOffsetAg);

    return rtval;
}







/* DBL角灯调节 */
/* BendAngle：单位rad 左转为正 */
static Std_ReturnType DBL_CornerLight(double BendAngle)
{
    Std_ReturnType rtval = E_OK;

#if HCM_LEFT_SIDE
    if(BendAngle > 0) /* 左转为正 */
    {
        CorneringLight_SetPwmOfDBL(gs_DBLConfigInfo.DBLCornerLightPWM);
    }
    else
    {
        CorneringLight_SetPwmOfDBL( 0 );
    }
#elif HCM_RIGHT_SIDE
    if(BendAngle < 0) /* 右转为负 */
    {
        CorneringLight_SetPwmOfDBL(gs_DBLConfigInfo.DBLCornerLightPWM);
    }
    else
    {
        CorneringLight_SetPwmOfDBL( 0 );
    }
#endif
    return rtval;
}






/* DBL设置电机近光灯像素角灯弯曲角度 */
/* BendAngle：单位rad 左转为正 */
static void DBL_SetMotorMatrixCLBendAg(double BendAngle)
{
    switch( gs_DBLConfigInfo.VehDBLType )
    {
        case E_DBLType_MotorWoHall:
        case E_DBLType_MotorWiHall:
            DBL_Motor(BendAngle);
            break;

        case E_DBLType_Matrix:
            DBL_Matrix(BendAngle);
            break;

        case E_DBLType_CornerLight:
            DBL_CornerLight(BendAngle);
            break;

        case E_DBLType_MotorWoHallWiCL:
        case E_DBLType_MotorWiHallWiCL:
            DBL_Motor(BendAngle);
            DBL_CornerLight(BendAngle);
            break;

        case E_DBLType_MatrixWiCL:
            DBL_Matrix(BendAngle);
            DBL_CornerLight(BendAngle);
    }
}

/* DBL运行 */
static void DBL_Run(void)
{
    switch( gs_DBLRunInfo.DBLState )
    {
        case E_DBLState_OFF:
        case E_DBLState_Stdby:
            DBL_SetMotorMatrixCLBendAg(0);
            break;

        case E_DBLState_Active:
            DBL_SetMotorMatrixCLBendAg(gs_DBLRunInfo.BendingAngle);
            break;

        case E_DBLState_SigErr:
        case E_DBLState_MotErr:
        case E_DBLState_LBErr:
        case E_DBLState_CLErr:
            DBL_SetMotorMatrixCLBendAg(0);
    }
}

/* DBL运行状态转换 */
static void DBL_RunStateTrans(void)
{
    uint32_t SignalValue;
    double VehSpdLgtA;     /* 车速，m/s */
    double SteerWhlSnsrAg; /* 方向盘角度，rad 左转为正 */
    static E_EnableFlag DBL_EnableFlag = E_EnableFlag_DISABLE;

    /* Interface_GetSignal_YawRateReqdByDrvr(); */
    /* Interface_GetSignal_SteerWhlSnsrAgSpd(); */

    Interface_GetSignal_VehSpdLgtA(&VehSpdLgtA);
    Interface_GetSignal_SteerWhlSnsrAg(&SignalValue);
    SteerWhlSnsrAg = MotorManage_ConvertSigned_xToSigned_32(SignalValue, 15) * 0.0009765625;

    gs_DBLRunInfo.BendingAngle = SteerWhlSnsrAg / STRW_FRTW_RATE; /* 弯曲角度为前轮角度值 */

/* 测试 */
#if DBL_TEST
    static sint16_t Cycle = 10;
    static uint8_t Flag = 1;

    if (Flag)
    {
        Cycle += 10;
    }
    else
    {
        Cycle -= 10;
    }

    if (Cycle >= 300)
    {
        Flag = 0;
    }
    else if (Cycle <= -300)
    {
        Flag = 1;
    }
    gs_DBLRunInfo.BendingAngle = (double)Cycle/10.0 * RAD_PER_DEG ;
    SteerWhlSnsrAg = gs_DBLRunInfo.BendingAngle * 15.0;
    VehSpdLgtA = 3.0;
#endif

    switch( gs_DBLRunInfo.DBLState )
    {
        case E_DBLState_OFF:
        case E_DBLState_Stdby:
        case E_DBLState_Active:
            if(VehSpdLgtA * 3.6 > SPEED_DBL_EN)
            {
                DBL_EnableFlag = E_EnableFlag_ENABLE;
            }
            else if(VehSpdLgtA * 3.6 < SPEED_DBL_DIS)
            {
                DBL_EnableFlag = E_EnableFlag_DISABLE;
            }

            if(DBL_EnableFlag == E_EnableFlag_ENABLE)
            {
                if(fabs(SteerWhlSnsrAg) > DEGREE_DBL_ON * RAD_PER_DEG)
                {
                    gs_DBLRunInfo.DBLState = E_DBLState_Active;
                }
                else if(fabs(SteerWhlSnsrAg) < DEGREE_DBL_OFF * RAD_PER_DEG)
                {
                    gs_DBLRunInfo.DBLState = E_DBLState_Stdby;
                }
            }
            else if(DBL_EnableFlag == E_EnableFlag_DISABLE)
            {
                gs_DBLRunInfo.DBLState = E_DBLState_Stdby;
            }
    }
}

/* DBL故障检测 */
static Std_ReturnType DBL_FaultDetection(void)
{
    Std_ReturnType rtval = E_OK;

    if(gs_DBLRunInfo.DBLState == E_DBLState_OFF)
    {
        return rtval;
    }

    U_SvlFuncErrSta SvlFuncErrSta;
    U_DisSrc_t DBLDerateSta;
    S_E2EStateForFailSafe SignalE2EState;
    uint32_t VehSpdLgtQf;
    uint32_t SteerWhlSnsrQf;

    switch( gs_DBLConfigInfo.VehDBLType ) /* 信号故障检测 */
    {
        case E_DBLType_MotorWoHall:
        case E_DBLType_MotorWiHall:
        case E_DBLType_MotorWoHallWiCL:
        case E_DBLType_MotorWiHallWiCL:
            SvlFuncErrSta = MotorManage_GetSwivelingFuncErrorState();
            GetLgtFuncDisSrc_DBL(& DBLDerateSta);  /* 降额状态 */
            if( SvlFuncErrSta.Bits.SigErr_DBL == 1u ||
                DBLDerateSta.bits.sp_los == 1u )
            {
                gs_DBLRunInfo.DBLState = E_DBLState_SigErr;
                return rtval;
            }
            break;

        case E_DBLType_Matrix:
        case E_DBLType_CornerLight:
        case E_DBLType_MatrixWiCL:
        SignalE2EState = GetE2EFlagForFailSafe();
        Interface_GetSignal_VehSpdLgtQf(& VehSpdLgtQf);
        Interface_GetSignal_SteerWhlSnsrQf(& SteerWhlSnsrQf);

        if( SignalE2EState.E2EErrorFlagForFailSafe.bits.VehSpdTimeout == 1 ||
            SignalE2EState.E2EErrorFlagForFailSafe.bits.VehSpdCntErr == 1  ||
            SignalE2EState.E2EErrorFlagForFailSafe.bits.VehSpdCrcErr == 1  ||
            VehSpdLgtQf < 2 ||
            SignalE2EState.E2EErrorFlagForFailSafe.bits.SteerWhlSnsrTimeout == 1 ||
            SignalE2EState.E2EErrorFlagForFailSafe.bits.SteerWhlSnsrCntErr == 1  ||
            SignalE2EState.E2EErrorFlagForFailSafe.bits.SteerWhlSnsrCrcErr == 1 ||
            SteerWhlSnsrQf == 0u ||
            Interface_GetBusOffFlag() == 1u)
            {
                gs_DBLRunInfo.DBLState = E_DBLState_SigErr;
                return rtval;
            }
    }

    switch( gs_DBLConfigInfo.VehDBLType ) /* 电机故障检测 */
    {
        case E_DBLType_MotorWoHall:
        case E_DBLType_MotorWiHall:
        case E_DBLType_MotorWoHallWiCL:
        case E_DBLType_MotorWiHallWiCL:
            if(SvlFuncErrSta.Bits.MotErr_DBL == 1u)
            {
                gs_DBLRunInfo.DBLState = E_DBLState_MotErr;
                return rtval;
            }
    }

    S_LF_Err_T DBL_RTErrMask;

    switch( gs_DBLConfigInfo.VehDBLType ) /* 近光灯故障检测 */
    {
        case E_DBLType_Matrix:
        case E_DBLType_MatrixWiCL:
            LampM_GetLampBaseErr(&DBL_RTErrMask);
            if(DBL_RTErrMask.chnErr & GetChannelMaskByLightFunction(E_LowBeamKink))
            {
                gs_DBLRunInfo.DBLState = E_DBLState_LBErr;
                return rtval;
            }
    }
    switch( gs_DBLConfigInfo.VehDBLType ) /* 角灯故障检测 */
    {
        case E_DBLType_CornerLight:
        case E_DBLType_MotorWoHallWiCL:
        case E_DBLType_MotorWiHallWiCL:
        case E_DBLType_MatrixWiCL:
            if(CorneringLight_GetCLRealTimeErrSta() == 1u)
            {
                gs_DBLRunInfo.DBLState = E_DBLState_CLErr;
                return rtval;
            }
    }

    switch( gs_DBLRunInfo.DBLState ) /* 故障恢复 */
    {
        case E_DBLState_SigErr:
        case E_DBLState_MotErr:
        case E_DBLState_LBErr:
        case E_DBLState_CLErr:
            gs_DBLRunInfo.DBLState = E_DBLState_Stdby;
    }
    return rtval;
}
/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/
/* 设置DBL的DID数据，4368 */
Std_ReturnType DBL_SetDID_4368_DBLStatus(void)
{
    Std_ReturnType rtval = E_OK;

    rtval |= Interface_SetDidSignalData(DIDSIGNALNAME_ID_StsOfDBL, (uint32_t)gs_DBLDidInfo.DBLStatus);

    return rtval;
}

/* DBL近光Kink关闭 */
void DBL_LowBeamKink_OFF(void)
{
    if(gs_DBLConfigInfo.VehDBLType == E_DBLType_Matrix || gs_DBLConfigInfo.VehDBLType == E_DBLType_MatrixWiCL)
    {
        if(gs_DBLRunInfo.DBLState == E_DBLState_OFF)
        {
            uint8_t PixelId;
            S_LF_Info_T DBL_LF_Info_T;

            lampM_GetLampInfo(E_LowBeamKink, &DBL_LF_Info_T);
            LampM_SetLampChn(E_LowBeamKink, DBL_LF_Info_T.mtxMask, 0, 0, 0);

            if(gs_DBLConfigInfo.LeEdgePxlTop > 0 && gs_DBLConfigInfo.RiEdgePxlTop > 0) /* 顶层 */
            {
                for(PixelId = gs_DBLConfigInfo.LeEdgePxlTop; PixelId <= gs_DBLConfigInfo.RiEdgePxlTop; PixelId++)
                {
                    LampM_SetLampPix(E_LowBeamKink, PixelId, 0, 0, 0);
                }
            }
            if(gs_DBLConfigInfo.LeEdgePxlMddl > 0 && gs_DBLConfigInfo.RiEdgePxlMddl > 0) /* 中间层 */
            {
                for(PixelId = gs_DBLConfigInfo.LeEdgePxlMddl; PixelId <= gs_DBLConfigInfo.RiEdgePxlMddl; PixelId++)
                {
                    LampM_SetLampPix(E_LowBeamKink, PixelId, 0, 0, 0);
                }
            }
            if(gs_DBLConfigInfo.LeEdgePxlBttm > 0 && gs_DBLConfigInfo.RiEdgePxlBttm > 0) /* 底层 */
            {
                for(PixelId = gs_DBLConfigInfo.LeEdgePxlBttm; PixelId <= gs_DBLConfigInfo.RiEdgePxlBttm; PixelId++)
                {
                    LampM_SetLampPix(E_LowBeamKink, PixelId, 0, 0, 0);
                }
            }
        }
    }
}

/* DBL近光Kink开启 */
void DBL_LowBeamKink_ON(uint8_t timebase)
{
    if(gs_DBLConfigInfo.VehDBLType == E_DBLType_Matrix || gs_DBLConfigInfo.VehDBLType == E_DBLType_MatrixWiCL)
    {
        if(gs_DBLRunInfo.DBLState != E_DBLState_OFF)
        {
            uint8_t PixelId;
            S_LF_Info_T DBL_LF_Info_T;

            lampM_GetLampInfo(E_LowBeamKink, &DBL_LF_Info_T);
            LampM_SetLampChn(E_LowBeamKink, DBL_LF_Info_T.mtxMask, 100, 0, 0);

            static uint16_t s_NextShiftDelayTime = 0u;

            if( gs_DBLRunInfo.ShiftNumTop_Last  != gs_DBLRunInfo.ShiftNumTop_Curr ||
                gs_DBLRunInfo.ShiftNumMddl_Last != gs_DBLRunInfo.ShiftNumMddl_Curr ||
                gs_DBLRunInfo.ShiftNumBttm_Last != gs_DBLRunInfo.ShiftNumBttm_Curr )
            {
                if(s_NextShiftDelayTime >= gs_DBLConfigInfo.ShiftDlyTime)
                {
                    s_NextShiftDelayTime = 0u;
                }
            }

            if(s_NextShiftDelayTime < gs_DBLConfigInfo.ShiftDlyTime)
            {
                s_NextShiftDelayTime += timebase;
            }
            else
            {
                if(gs_DBLConfigInfo.LeEdgePxlTop > 0 && gs_DBLConfigInfo.RiEdgePxlTop > 0) /* 顶层 */
                {
                    DBL_PixelShift(gs_DBLRunInfo.ShiftNumTop_Curr, gs_DBLConfigInfo.LeEdgePxlTop, gs_DBLConfigInfo.RiEdgePxlTop);
                }
                if(gs_DBLConfigInfo.LeEdgePxlMddl > 0 && gs_DBLConfigInfo.RiEdgePxlMddl > 0) /* 中间层 */
                {
                    DBL_PixelShift(gs_DBLRunInfo.ShiftNumMddl_Curr, gs_DBLConfigInfo.LeEdgePxlMddl, gs_DBLConfigInfo.RiEdgePxlMddl);
                }
                if(gs_DBLConfigInfo.LeEdgePxlBttm > 0 && gs_DBLConfigInfo.RiEdgePxlBttm > 0) /* 底层 */
                {
                    DBL_PixelShift(gs_DBLRunInfo.ShiftNumBttm_Curr, gs_DBLConfigInfo.LeEdgePxlBttm, gs_DBLConfigInfo.RiEdgePxlBttm);
                }
            }

            if(gs_DBLConfigInfo.LeEdgePxlTop > 0 && gs_DBLConfigInfo.RiEdgePxlTop > 0) /* 顶层 */
            {
                for(PixelId = gs_DBLConfigInfo.LeEdgePxlTop; PixelId <= gs_DBLConfigInfo.RiEdgePxlTop; PixelId++)
                {
                    LampM_SetLampPix(E_LowBeamKink, PixelId, gs_DBLRunInfo.PxlShiftPWM[PixelId - 1], gs_DBLConfigInfo.TrnsnTime, gs_DBLConfigInfo.TrnsnTime);
                }
            }
            if(gs_DBLConfigInfo.LeEdgePxlMddl > 0 && gs_DBLConfigInfo.RiEdgePxlMddl > 0) /* 中间层 */
            {
                for(PixelId = gs_DBLConfigInfo.LeEdgePxlMddl; PixelId <= gs_DBLConfigInfo.RiEdgePxlMddl; PixelId++)
                {
                    LampM_SetLampPix(E_LowBeamKink, PixelId, gs_DBLRunInfo.PxlShiftPWM[PixelId - 1], gs_DBLConfigInfo.TrnsnTime, gs_DBLConfigInfo.TrnsnTime);
                }
            }
            if(gs_DBLConfigInfo.LeEdgePxlBttm > 0 && gs_DBLConfigInfo.RiEdgePxlBttm > 0) /* 底层 */
            {
                for(PixelId = gs_DBLConfigInfo.LeEdgePxlBttm; PixelId <= gs_DBLConfigInfo.RiEdgePxlBttm; PixelId++)
                {
                    LampM_SetLampPix(E_LowBeamKink, PixelId, gs_DBLRunInfo.PxlShiftPWM[PixelId - 1], gs_DBLConfigInfo.TrnsnTime, gs_DBLConfigInfo.TrnsnTime);
                }
            }
        }
    }
}


/* DBL初始化 */
void DBL_Init(void)
{
    DBL_GetParameterIntoInfo();
}


/* DBL主函数 */
void DBL_MainFunction(uint8_t timebase)
{
    if(gs_DBLConfigInfo.VehDBLType == E_DBLType_NotAval)
    {
        return;
    }

    switch( gs_DBLConfigInfo.VehDBLType )
    {
        case E_DBLType_Matrix:
        case E_DBLType_MatrixWiCL:
            DBL_MatrixLBKinkPwmChange();
    }

    uint32_t ActvnOfDbl;

    Interface_GetSignal_ActvnOfDbl(& ActvnOfDbl);
    if(ActvnOfDbl)
    {
        E_SvlRefRunSts SvlRefRunSts;

        switch( gs_DBLConfigInfo.VehDBLType )
        {
            case E_DBLType_MotorWoHall:
            case E_DBLType_MotorWiHall:
            case E_DBLType_MotorWoHallWiCL:
            case E_DBLType_MotorWiHallWiCL:
                SvlRefRunSts = SwivelingMotor_GetSvlRefRunSts();
                if(SvlRefRunSts == E_SvlRefRunSts_Done)
                {
                    DBL_RunStateTrans();
                    DBL_FaultDetection();
                    MotorManage_SetSwivelingFuncActState(E_SvlFunction_DBL, 1u);
                }
                else if(SvlRefRunSts == E_SvlRefRunSts_NoCond || SvlRefRunSts == E_SvlRefRunSts_Error)
                {
                    gs_DBLRunInfo.DBLState = E_DBLState_MotErr;
                    MotorManage_SetSwivelingFuncActState(E_SvlFunction_DBL, 0u);
                }
                else if(SvlRefRunSts == E_SvlRefRunSts_Done)
                {
                    gs_DBLRunInfo.DBLState = E_DBLState_OFF;
                    MotorManage_SetSwivelingFuncActState(E_SvlFunction_DBL, 0u);
                }
                break;

            case E_DBLType_Matrix:
            case E_DBLType_CornerLight:
            case E_DBLType_MatrixWiCL:
                DBL_RunStateTrans();
                DBL_FaultDetection();
                Interface_EnableSteerWhlSnsr_QF_Detect();
        }
    }
    else
    {
        gs_DBLRunInfo.DBLState = E_DBLState_OFF;
        switch( gs_DBLConfigInfo.VehDBLType )
        {
            case E_DBLType_MotorWoHall:
            case E_DBLType_MotorWiHall:
            case E_DBLType_MotorWoHallWiCL:
            case E_DBLType_MotorWiHallWiCL:
                MotorManage_SetSwivelingFuncActState(E_SvlFunction_DBL, 0u);
                break;

            case E_DBLType_Matrix:
            case E_DBLType_CornerLight:
            case E_DBLType_MatrixWiCL:
                Interface_DisableSteerWhlSnsr_QF_Detect();
        }
    }

    DBL_Run();

    switch( gs_DBLRunInfo.DBLState )
    {
        case E_DBLState_OFF:
            Interface_SetSignal_StsOfSwvlg(0x0);
            gs_DBLDidInfo.DBLStatus = DBLStatus_Off;
            break;

        case E_DBLState_Stdby:
        case E_DBLState_Active:
            Interface_SetSignal_StsOfSwvlg(0x1);
            gs_DBLDidInfo.DBLStatus = DBLStatus_On;
            break;

        case E_DBLState_SigErr:
        case E_DBLState_MotErr:
        case E_DBLState_LBErr:
        case E_DBLState_CLErr:
            Interface_SetSignal_StsOfSwvlg(0x2);
            gs_DBLDidInfo.DBLStatus = DBLStatus_Error;
    }
}


