/********************************
 * MHL.c
 *
 *  Created on: 2024/7/20
 *      Author: tujiongjiong
 ********************************/


/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "MHL.h"

/****************************************************************
 *                                                              *
 *                  Private Variable Define                     *
 *                                                              *
 ****************************************************************/
static S_MHLConfigInfo gs_MHLConfigInfo;

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

/* 读取MHL参数配置并存放 */
static void MHL_GetParameterIntoInfo(void)
{
    gs_MHLConfigInfo.LvlType = (E_LvlType)Get_pVehLvLType();

    gs_MHLConfigInfo.StepMode = Get_pLvlStepMode();

#if HCM_LEFT_SIDE
    gs_MHLConfigInfo.DfltPos = Get_LeLamp_pLvlDfltPosLe() * (gs_MHLConfigInfo.StepMode / 2);
#elif HCM_RIGHT_SIDE
    gs_MHLConfigInfo.DfltPos = Get_RiLamp_pLvlDfltPosRi() * (gs_MHLConfigInfo.StepMode / 2);
#endif
    gs_MHLConfigInfo.MHLPos1Incre = Get_pManLvlAgPos1() * (gs_MHLConfigInfo.StepMode / 2) - gs_MHLConfigInfo.DfltPos;
    gs_MHLConfigInfo.MHLPos2Incre = Get_pManLvlAgPos2() * (gs_MHLConfigInfo.StepMode / 2) - gs_MHLConfigInfo.DfltPos;
    gs_MHLConfigInfo.MHLPos3Incre = Get_pManLvlAgPos3() * (gs_MHLConfigInfo.StepMode / 2) - gs_MHLConfigInfo.DfltPos;
    gs_MHLConfigInfo.MHLPos4Incre = Get_pManLvlAgPos4() * (gs_MHLConfigInfo.StepMode / 2) - gs_MHLConfigInfo.DfltPos;
    gs_MHLConfigInfo.MHLPos5Incre = Get_pManLvlAgPos5() * (gs_MHLConfigInfo.StepMode / 2) - gs_MHLConfigInfo.DfltPos;
}

/* AHL静态调平 */
static void MHL_Run(void)
{
    uint32_t LvlgSwtSetReq;
    Interface_GetSignal_LvlgSwtSetReqADModCtrlInhbn(& LvlgSwtSetReq);
    switch( LvlgSwtSetReq )
    {
        case 0:
            MotorManage_SetLevelingPosIncre(E_LvlFunction_MHL, 0u);
            break;
        case 1:
            MotorManage_SetLevelingPosIncre(E_LvlFunction_MHL, gs_MHLConfigInfo.MHLPos1Incre);
            break;
        case 2:
            MotorManage_SetLevelingPosIncre(E_LvlFunction_MHL, gs_MHLConfigInfo.MHLPos2Incre);
            break;
        case 3:
            MotorManage_SetLevelingPosIncre(E_LvlFunction_MHL, gs_MHLConfigInfo.MHLPos3Incre);
            break;
        case 4:
            MotorManage_SetLevelingPosIncre(E_LvlFunction_MHL, gs_MHLConfigInfo.MHLPos4Incre);
            break;
        case 5:
            MotorManage_SetLevelingPosIncre(E_LvlFunction_MHL, gs_MHLConfigInfo.MHLPos5Incre);
    }
}


/****************************************************************
 *                                                              *
 *                   Global Functions Define                    *
 *                                                              *
 ****************************************************************/


/* MHL初始化 */
void MHL_Init(void)
{
    MHL_GetParameterIntoInfo();
}

/* MHL主函数 */
void MHL_MainFunction(uint8_t timebase)
{
    if(gs_MHLConfigInfo.LvlType == E_LvlType_MHL) /* 调平类型为手动 */
    {
        E_LvlRefRunSts LvlRefRunSts;
        LvlRefRunSts = LevelingMotor_GetLvlRefRunSts();

        if(LvlRefRunSts == E_LvlRefRunSts_Done) /* 电机参考运行完成 */
        {
#if (OEM_PLATFORM == OEM_SMART)
            uint32_t StsOfLedLoBeam;
            Interface_GetSignal_StsOfLedLoBeam(& StsOfLedLoBeam);
            if(StsOfLedLoBeam == 0x1u)
            {
                uint32_t SignalValue;
                E_UsageModeSts UsageMode;
                Interface_GetSignal_VehModMngtGlbSafe1UsgModSts(& SignalValue);
                UsageMode = (E_UsageModeSts)SignalValue;
                if( UsageMode == E_UsageModeSts_Cnvinc ||
                    UsageMode == E_UsageModeSts_Actv ||
                    UsageMode == E_UsageModeSts_Drvg ) /* 参考运行完成、UsageMode状态正确，开始调平 */
                {
                    U_LvlFuncErrSta LvlFuncErrSta;
                    U_DisSrc_t MHLDerateSta;

                    LvlFuncErrSta = MotorManage_GetLevelingFuncErrorState();
                    GetLgtFuncDisSrc_MHL(& MHLDerateSta);  /* 降额状态 */

                    if( LvlFuncErrSta.Bits.SigErr_MHL == 1u ||
                        LvlFuncErrSta.Bits.MotErr_MHL == 1u ||
                        MHLDerateSta.bits.sp_los == 1u )
                    {
                        MotorManage_SetLevelingPosIncre(E_LvlFunction_MHL, 0u);
                        Interface_SetSignal_StsOfLvlg( 0x2u );
                    }
                    else
                    {
                        MHL_Run();
                        Interface_SetSignal_StsOfLvlg( 0x1u );
                    }
                    MotorManage_SetLevelingFuncActState(E_LvlFunction_MHL, 1u);
                }
                else
                {
                    Interface_SetSignal_StsOfLvlg( 0x0u );
                    MotorManage_SetLevelingFuncActState(E_LvlFunction_MHL, 0u);
                }
            }
            else
            {
                Interface_SetSignal_StsOfLvlg( 0x0u );
                MotorManage_SetLevelingFuncActState(E_LvlFunction_MHL, 0u);
            }
#elif (OEM_PLATFORM == OEM_GEELY)
            uint32_t StsOfLedLoBeam;
            Interface_GetSignal_StsOfLedLoBeam(& StsOfLedLoBeam);
            if(StsOfLedLoBeam == 0x1u)
            {
                U_LvlFuncErrSta LvlFuncErrSta;
                S_LgtFuncEna_t MHLEnaSta;

                LvlFuncErrSta = MotorManage_GetLevelingFuncErrorState();
                GetLgtFuncEna(& MHLEnaSta);  /* 降额状态 */

                if( LvlFuncErrSta.Bits.SigErr_MHL == 1u ||
                    LvlFuncErrSta.Bits.MotErr_MHL == 1u ||
                    MHLEnaSta.EnaMHL == 0u )
                {
                    MotorManage_SetLevelingPosIncre(E_LvlFunction_MHL, 0u);
                    Interface_SetSignal_StsOfLvlg( 0x2u );
                }
                else
                {
                    MHL_Run();
                    Interface_SetSignal_StsOfLvlg( 0x1u );
                }
                MotorManage_SetLevelingFuncActState(E_LvlFunction_MHL, 1u);
            }
            else
            {
                Interface_SetSignal_StsOfLvlg( 0x0u );
                MotorManage_SetLevelingFuncActState(E_LvlFunction_MHL, 0u);
            }
#endif
        }
        else if(LvlRefRunSts == E_LvlRefRunSts_NoCond || LvlRefRunSts == E_LvlRefRunSts_Error)/* 电机参考运行条件不满足或有故障 */
        {
#if (OEM_PLATFORM == OEM_SMART)
            uint32_t SignalValue;
            E_UsageModeSts UsageMode;
            uint32_t StsOfLedLoBeam;
            Interface_GetSignal_VehModMngtGlbSafe1UsgModSts(& SignalValue);
            UsageMode = (E_UsageModeSts)SignalValue;
            Interface_GetSignal_StsOfLedLoBeam(& StsOfLedLoBeam);
            if((UsageMode == E_UsageModeSts_Cnvinc ||
                UsageMode == E_UsageModeSts_Actv ||
                UsageMode == E_UsageModeSts_Drvg) &&
                StsOfLedLoBeam == 0x1u) /* 参考运行有问题，MHL开启时反馈错误 */
            {
                Interface_SetSignal_StsOfLvlg( 0x2u );
            }
            else
            {
                Interface_SetSignal_StsOfLvlg( 0x0u );
            }
#elif (OEM_PLATFORM == OEM_GEELY)
            uint32_t StsOfLedLoBeam;
            Interface_GetSignal_StsOfLedLoBeam(& StsOfLedLoBeam);
            if(StsOfLedLoBeam == 0x1u) /* 参考运行有问题，MHL开启时反馈错误 */
            {
                Interface_SetSignal_StsOfLvlg( 0x2u );
            }
            else
            {
                Interface_SetSignal_StsOfLvlg( 0x0u );
            }
#endif
            MotorManage_SetLevelingFuncActState(E_LvlFunction_MHL, 0u);
        }
        else if(LvlRefRunSts == E_LvlRefRunSts_During) /* 电机参考运行正在执行中 */
        {
            Interface_SetSignal_StsOfLvlg( 0x0u );
            MotorManage_SetLevelingFuncActState(E_LvlFunction_MHL, 0u);
        }
    }
}


