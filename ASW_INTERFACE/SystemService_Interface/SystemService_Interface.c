
// /****************************************************************
//  *                                                              *
//  *                     Include Files                            *
//  *                                                              *
//  ****************************************************************/
// #include "SystemService_Interface.h"
// #include "Fls.h"
// #include "RamTst.h"
// #include "Crc.h"
// #include "Can_GeneralTypes.h"
// #include "Can_Cfg.h"
// #include "Compiler.h"
// #include "CanNm.h"
// #include "CanNm_Internal.h"
// #include "Nvm.h"
// #include "DTC_Interface.h"
// #include "BUCK_Interface.h"
// #include "GeneralFunction.h"
// #include "Channel_Interface.h"
// /****************************************************************
//  *                                                              *
//  *                  Private Variable Define                     *
//  *                                                              *
//  ****************************************************************/
// const S_BlockMemoryInfo gs_BlockMemoryInfo[BLOCK_MEMORY_SIZE] = {
//     {
//         .MemoryType = E_MemoryType_LightShow,
//         .DataBlockNum = LIGHTSHOW_BLOCK_NUM,
//         .DataBlockStartAddress = LIGHTSHOW_BLOCK_START_ADDRESS,
//         .DataBlockSize = LIGHTSHOW_BLOCK_SIZE,

//     },
//     {
//         .MemoryType = E_MemoryType_WelGby,
//         .DataBlockNum = WELGBY_BLOCK_NUM,
//         .DataBlockStartAddress = WELGBY_BLOCK_START_ADDRESS,
//         .DataBlockSize = WELGBY_BLOCK_SIZE,
//     },
// };

// const S_NvmMemoryInfo gs_NvmMemoryInfo[NVM_MEMORY_SIZE] = {
//     {.MemoryType = E_MemoryType_LightShowExtFlag,
//      .NvmBlockId = LIGHTSHOWEXTFLAG_BLOCK_ID,
//      .DataLens = LIGHTSHOWEXTFLAG_DATA_SIZE},
// };

// const S_FlsTstDataBlockInfo gs_FlsTstDataBlockInfo[FLS_TST_BLOCK_NUM] = {
//     {
//         .FlsTstDataBlockType = E_FlsTstDataBlockType_EXE,
//         .FlsTstAlgorithmType = FLSTST_32BIT_CRC,
//         .DataStoreStartAddress = FLSTST_EXE_DATA_STORE_START_ADDRESS,
//         .DataLensStoreStartAddress = FLSTST_EXE_LENS_STORE_START_ADDRESS,
//         .CrcStoreStartAddress = FLSTST_EXE_CRC_STORE_START_ADDRESS,
//     },

//     {
//         .FlsTstDataBlockType = E_FlsTstDataBlockType_DATA,
//         .FlsTstAlgorithmType = FLSTST_32BIT_CRC,
//         .DataStoreStartAddress = FLSTST_DATA_DATA_STORE_START_ADDRESS,
//         .DataLensStoreStartAddress = FLSTST_DATA_LENS_STORE_START_ADDRESS,
//         .CrcStoreStartAddress = FLSTST_DATA_CRC_STORE_START_ADDRESS,
//     },
// };

// /****************************************************************
//  *                                                              *
//  *                   Global Variable Define                     *
//  *                                                              *
//  ****************************************************************/
// static uint16_t g_DrvReInitMask = 0;
// /*
//  *保持唤醒标记位：0：ECU正常走休眠流程  1：ECU不休眠
//  */
// static uint8_t g_SysKeepAwakeFlag = 0;
// /*
//  *Bus off标记位，当ECU处于慢恢复的时候置1，总线恢复后清0
//  */
// static uint8_t g_SysInBusOffState = 0;

// /*
//  *上电是否报文
//  *0：上电还未收到报文   1：上电收到过报文
//  */
// static uint8_t g_MessageRcvdPowerOn = 0;

// static uint16_t Saved_ChannelCurrent[MAX_CHANNLE_NUM];
// static uint8_t Saved_ChannelPwm[MAX_CHANNLE_NUM];
// static E_ChannelState Saved_ChannelState[MAX_CHANNLE_NUM];
// // static uint8_t Saved_MatrixChipPwm[MAX_MATRIXCHIP_NUM][MAX_MATRIXCHIP_CHANNEL_NUM];
// // static uint8_t Saved_MatrixChipAddr[MAX_MATRIXCHIP_NUM];

// static uint8_t WriteMemoryBuffer[MEMORY_WRITE_BUFFER_SIZE];

// static E_FlsTstResult ge_FlsTstResult[FLS_TST_BLOCK_NUM] = {E_FlsTstResult_NotTest, E_FlsTstResult_NotTest};
// static uint8_t gu_BoostSpiErrorFlag = 0;
// static uint8_t gu_BuckSpiErrorFlag = 0;
// static uint8_t gu_MotorDrvSpiErrorFlag = 0;
// static uint8_t gu_SbcSpiErrorFlag = 0;
// static uint8_t gu_SysSpiErrCnt = 0;
// #if MEMORY_TEST
// static uint8_t LightShowWriteData[(1024 * 8 * 4 + 5)] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
// static uint8_t LightShowReadData[(1024 * 8 * 4 + 5)];
// static uint8_t ExtFlagReadData[62];
// static uint8_t ExtFlagWriteData[62] = {0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA};
// #endif

// static uint8_t *MemoryJob_TargetAddress = NULL;
// static uint32_t MemoryJob_Length = 0; /*读写总长度*/

// static uint32_t MemoryReadOffset = 0;       /*读取字节的偏移值*/
// static uint32_t MemoryWriteOffset = 0;      /*写字节的偏移值*/
// static uint32_t MemoryRemainBytes = 0;      /*还剩多少个字节没有读写*/
// static uint32_t MemoryEraseBolckOffset = 0; /*擦除块的偏移值*/

// static S_MemoryJobCtr gs_MemoryJobCtr = {
//     .CurMemoryType = E_MemoryType_None,
//     .MemoryJob = E_MemoryJob_None,
//     .MemoryJobState = E_MemoryJobState_Idle,
//     .MemoryJobResult = E_MemoryJobResult_OK,
// };

// #if (DCM_UDS_SERVICE0X23_ENABLED == STD_ON)
// static uint8 g_uFaultStorageBuffer[NVM_FAULT_STORE_SIZE];
// static uint8 FaultStateNeedStore = 0;
// static T_FaultStateStorageInfo gT_FaultStateStorageInfo;
// #endif

// /*43A8是否被2E服务写过（标记位）*/
// static uint8_t Did_43A8_WriteFlag = 0;

// /****************************************************************
//  *                                                              *
//  *                   Private Functions Define                   *
//  *                                                              *
//  ****************************************************************/
// static void SaveBuckStateAndCloseBuck(void)
// {
//     uint8_t i = 0;
//     for (i = 0; i < MAX_CHANNLE_NUM; i++)
//     {
//         Saved_ChannelCurrent[i] = Interface_GetChannelCurCurrent((E_ChannelID)i);
//         Saved_ChannelPwm[i] = Interface_GetChannelCurPWM((E_ChannelID)i);
//         Interface_GetChannelSwitchState((E_ChannelID)i, &Saved_ChannelState[i]);

//         Interface_SetChannelSwitchState((E_ChannelID)i, CHANNEL_STATE_OFF);
//         Interface_SetChannelPWM((E_ChannelID)i, 0);
//         Interface_SetChannelCurrent((E_ChannelID)i, 0);
//     }
// }

// static void ResumeBuckState(void)
// {
//     uint8_t i = 0;
//     for (i = 0; i < MAX_CHANNLE_NUM; i++)
//     {
//         Interface_SetChannelPWM((E_ChannelID)i, Saved_ChannelPwm[i]);
//         Interface_SetChannelCurrent((E_ChannelID)i, Saved_ChannelCurrent[i]);
//         Interface_SetChannelSwitchState((E_ChannelID)i, Saved_ChannelState[i]);
//     }
// }

// static void DrvReInit_MainFunc(uint8_t timebase)
// {
//     static uint16_t DrvReInitTimeTick = 0;
//     Std_ReturnType rtval = E_OK;
//     uint16_t BoostMaxVlotage = 0;
//     E_ChannelID chindex = 0;

//     DrvReInitTimeTick += timebase;

//     if (DrvReInitTimeTick < 100)
//         return;

//     DrvReInitTimeTick = 0;

//     if ((g_DrvReInitMask & (1 << E_DrvReInitID_Boost)) != 0)
//     {
//         /*Boost丢初始化，重新初始化boost buck*/
//         g_DrvReInitMask |= (1 << E_DrvReInitID_Buck);
//         /*1.保存buck通道输出状态并关闭通道输出*/
//         SaveBuckStateAndCloseBuck();

//         if (rtval == E_OK)
//         {
//             g_DrvReInitMask &= ~(1 << E_DrvReInitID_Boost);
//             rtval = Interface_BuckInit();
//         }

//         if (rtval == E_OK)
//         {
//             g_DrvReInitMask &= ~(1 << E_DrvReInitID_Buck);
//             ResumeBuckState();
//         }
//     }

//     if ((g_DrvReInitMask & (1 << E_DrvReInitID_Buck)) != 0)
//     {
//         /*1.保存buck通道输出状态并关闭通道输出*/
//         SaveBuckStateAndCloseBuck();
//         rtval = Interface_BuckInit();
//         if (rtval == E_OK)
//         {
//             g_DrvReInitMask &= ~(1 << E_DrvReInitID_Buck);
//             ResumeBuckState();
//         }
//     }
// }

// static Std_ReturnType RamTstMainFunc(uint8_t timebase)
// {
//     RamTst_TestResultType RamTstResult;

//     RamTstResult = RamTst_GetTestResult();

//     if (RamTstResult == RAMTST_RESULT_NOT_OK)
//         Interface_SetSystemError(E_SystemErrorType_Ram_Error, 1);
//     else
//         Interface_SetSystemError(E_SystemErrorType_Ram_Error, 0);
//     return E_OK;
// }

// static Std_ReturnType FlsTstMainFunc(uint8_t timebase)
// {
//     uint8_t i = 0;
//     for (i = 0; i < FLS_TST_BLOCK_NUM; i++)
//     {
//         if (ge_FlsTstResult[i] == E_FlsTstResult_TestOK)
//         {
//             if (gs_FlsTstDataBlockInfo[i].FlsTstDataBlockType == E_FlsTstDataBlockType_EXE)
//                 Interface_SetSystemError(E_SystemErrorType_Rom_Error, 0);
//             else if (gs_FlsTstDataBlockInfo[i].FlsTstDataBlockType == E_FlsTstDataBlockType_DATA)
//                 Interface_SetSystemError(E_SystemErrorType_ParameterTable_CrcError, 0);
//         }
//         else if (ge_FlsTstResult[i] == E_FlsTstResult_TestNotOK)
//         {
//             if (gs_FlsTstDataBlockInfo[i].FlsTstDataBlockType == E_FlsTstDataBlockType_EXE)
//                 Interface_SetSystemError(E_SystemErrorType_Rom_Error, 1);
//             else if (gs_FlsTstDataBlockInfo[i].FlsTstDataBlockType == E_FlsTstDataBlockType_DATA)
//                 Interface_SetSystemError(E_SystemErrorType_ParameterTable_CrcError, 1);
//         }
//     }
//     return E_OK;
// }
// static Std_ReturnType SpiErrMainFunc(uint8_t timebase)
// {
//     if (gu_BoostSpiErrorFlag || gu_BuckSpiErrorFlag || gu_MotorDrvSpiErrorFlag || gu_SbcSpiErrorFlag)
//     {
//         gu_SysSpiErrCnt = CNT_INC(gu_SysSpiErrCnt, STEP_1, CNT_LIMIT_10);
//     }
//     else
//     {
//         gu_SysSpiErrCnt = CNT_DEC(gu_SysSpiErrCnt, STEP_1, DEC_LIMIT_0);
//     }

//     if (gu_SysSpiErrCnt >= CNT_LIMIT_10)
//         Interface_SetSystemError(E_SystemErrorType_ECU_SpiError, 1);
//     else if (gu_SysSpiErrCnt <= DEC_LIMIT_0)
//         Interface_SetSystemError(E_SystemErrorType_ECU_SpiError, 0);

//     return E_OK;
// }

// static E_MemoryJobResult MemoryRead(void)
// {
//     E_MemoryJobResult rtval = E_MemoryJobResult_Pending;
//     uint8_t BlockIndex = 0;
//     uint8_t *DataAddress;
//     uint32_t i = 0;
//     switch (gs_MemoryJobCtr.CurMemoryType)
//     {
//     case E_MemoryType_LightShow:
//     case E_MemoryType_WelGby:
//         for (BlockIndex = 0; BlockIndex < BLOCK_MEMORY_SIZE; BlockIndex++)
//         {
//             if (gs_BlockMemoryInfo[BlockIndex].MemoryType == gs_MemoryJobCtr.CurMemoryType)
//                 break;
//         }
//         if (BlockIndex >= BLOCK_MEMORY_SIZE)
//             return E_MemoryJobResult_Error;

//         if (MemoryJob_Length > (gs_BlockMemoryInfo[BlockIndex].DataBlockSize * gs_BlockMemoryInfo[BlockIndex].DataBlockNum))
//             return E_MemoryJobResult_Error;

//         if (MemoryRemainBytes <= 0)
//             return E_MemoryJobResult_OK;

//         DataAddress = LIGHTSHOW_BLOCK_BASE_ADDRESS + gs_BlockMemoryInfo[BlockIndex].DataBlockStartAddress + MemoryReadOffset;

//         if (MemoryRemainBytes <= BYTES_NUM_ONCE_READ) /*剩余字节不超过BYTES_NUM_ONCE_READ*/
//         {
//             for (i = 0; i < MemoryRemainBytes; i++)
//             {
//                 MemoryJob_TargetAddress[i] = DataAddress[i];
//             }
//             MemoryRemainBytes = 0;
//             rtval = E_MemoryJobResult_OK;
//         }
//         else
//         {
//             for (i = 0; i < BYTES_NUM_ONCE_READ; i++)
//             {
//                 MemoryJob_TargetAddress[i] = DataAddress[i];
//             }
//             MemoryReadOffset += BYTES_NUM_ONCE_READ;
//             MemoryJob_TargetAddress += BYTES_NUM_ONCE_READ;
//             MemoryRemainBytes -= BYTES_NUM_ONCE_READ;
//             rtval = E_MemoryJobResult_Pending;
//         }
//         break;

//     case E_MemoryType_LightShowExtFlag:
//         for (BlockIndex = 0; BlockIndex < NVM_MEMORY_SIZE; BlockIndex++)
//         {
//             if (gs_NvmMemoryInfo[BlockIndex].MemoryType == gs_MemoryJobCtr.CurMemoryType)
//                 break;
//         }
//         if (BlockIndex >= NVM_MEMORY_SIZE)
//             return E_MemoryJobResult_Error;

//         if (MemoryJob_Length > gs_NvmMemoryInfo[BlockIndex].DataLens)
//             return E_MemoryJobResult_Error;

//         DataAddress = NvM_BlockDescriptor[(gs_NvmMemoryInfo[BlockIndex].NvmBlockId - 1)].NvmRamBlockDataAddress + MemoryReadOffset;

//         if (MemoryRemainBytes <= BYTES_NUM_ONCE_READ)
//         {
//             for (i = 0; i < MemoryRemainBytes; i++)
//             {
//                 MemoryJob_TargetAddress[i] = DataAddress[i];
//             }
//             MemoryRemainBytes = 0;
//             rtval = E_MemoryJobResult_OK;
//         }
//         else
//         {
//             for (i = 0; i < BYTES_NUM_ONCE_READ; i++)
//             {
//                 MemoryJob_TargetAddress[i] = DataAddress[i];
//             }
//             MemoryReadOffset += BYTES_NUM_ONCE_READ;
//             MemoryJob_TargetAddress += BYTES_NUM_ONCE_READ;
//             MemoryRemainBytes -= BYTES_NUM_ONCE_READ;
//             rtval = E_MemoryJobResult_Pending;
//         }

//         break;
//     default:
//         rtval = E_MemoryJobResult_Error;
//         break;
//     }

//     return rtval;
// }

// static MemoryWrite(void)
// {
//     E_MemoryJobResult rtval = E_MemoryJobResult_Pending;
//     uint8_t BlockIndex = 0;
//     uint32_t WriteAddress = 0;
//     uint32_t i = 0;
//     uint32_t WriteDatalengths;
//     uint16_t timeout = 0;

//     switch (gs_MemoryJobCtr.CurMemoryType)
//     {
//     case E_MemoryType_LightShow:
//     case E_MemoryType_WelGby:
//         for (BlockIndex = 0; BlockIndex < BLOCK_MEMORY_SIZE; BlockIndex++)
//         {
//             if (gs_BlockMemoryInfo[BlockIndex].MemoryType == gs_MemoryJobCtr.CurMemoryType)
//                 break;
//         }
//         if (BlockIndex >= BLOCK_MEMORY_SIZE)
//             return E_MemoryJobResult_Error;

//         if (MemoryJob_Length > (gs_BlockMemoryInfo[BlockIndex].DataBlockSize * gs_BlockMemoryInfo[BlockIndex].DataBlockNum))
//             return E_MemoryJobResult_Error;

//         /*没有字节要写，返回OK*/
//         if (MemoryRemainBytes <= 0)
//             return E_MemoryJobResult_OK;

//         if (MemoryRemainBytes >= BYTES_NUM_ONCE_WRITE)
//         {
//             /*一次主循环写入BYTES_NUM_ONCE_WRITE个字节*/
//             WriteDatalengths = BYTES_NUM_ONCE_WRITE;
//         }
//         else
//         {
//             WriteDatalengths = MemoryRemainBytes;
//         }

//         MemoryRemainBytes -= WriteDatalengths;

//         while (WriteDatalengths > 0)
//         {
//             if (WriteDatalengths >= MEMORY_WRITE_BUFFER_SIZE)
//             {
//                 for (i = 0; i < MEMORY_WRITE_BUFFER_SIZE; i++)
//                 {
//                     WriteMemoryBuffer[i] = MemoryJob_TargetAddress[MemoryWriteOffset + i];
//                 }
//                 WriteAddress = gs_BlockMemoryInfo[BlockIndex].DataBlockStartAddress + MemoryWriteOffset;
//                 MemoryWriteOffset += MEMORY_WRITE_BUFFER_SIZE;
//                 WriteDatalengths -= MEMORY_WRITE_BUFFER_SIZE;
//             }
//             else
//             {
//                 for (i = 0; i < WriteDatalengths; i++)
//                     WriteMemoryBuffer[i] = MemoryJob_TargetAddress[MemoryWriteOffset + i];
// #if MEMORY_FILL_ENABLE
//                 for (i = 0; i < (MEMORY_WRITE_BUFFER_SIZE - WriteDatalengths); i++)
//                 {
//                     /*填充*/
//                     WriteMemoryBuffer[WriteDatalengths + i] = MEMORY_FILL_DATA;
//                 }
//                 WriteAddress = gs_BlockMemoryInfo[BlockIndex].DataBlockStartAddress + MemoryWriteOffset;
//                 MemoryWriteOffset += WriteDatalengths;
//                 WriteDatalengths = 0;
// #endif
//             }

//             if (Fls_Write(WriteAddress, WriteMemoryBuffer, MEMORY_WRITE_BUFFER_SIZE) != E_OK)
//             {
//                 return E_MemoryJobResult_Error;
//             }

//             timeout = 0;
//             SuspendAllInterrupts();
//             do
//             {
//                 Fls_MainFunction();
//                 timeout++;
//             } while ((timeout <= MEMORY_OPERATION_TIMEOUT) && (MEMIF_JOB_OK != Fls_GetJobResult()));
//             ResumeAllInterrupts();

//             if (timeout > MEMORY_OPERATION_TIMEOUT)
//                 return E_MemoryJobResult_Error;
//         }

//         if (MemoryRemainBytes <= 0)
//             rtval = E_MemoryJobResult_OK;
//         else
//             rtval = E_MemoryJobResult_Pending;

//         break;

//     case E_MemoryType_LightShowExtFlag:
//         for (BlockIndex = 0; BlockIndex < NVM_MEMORY_SIZE; BlockIndex++)
//         {
//             if (gs_NvmMemoryInfo[BlockIndex].MemoryType == gs_MemoryJobCtr.CurMemoryType)
//                 break;
//         }
//         if (BlockIndex >= NVM_MEMORY_SIZE)
//             return E_MemoryJobResult_Error;

//         if (MemoryJob_Length > gs_NvmMemoryInfo[BlockIndex].DataLens)
//             return E_MemoryJobResult_Error;

//         if (MemoryRemainBytes >= BYTES_NUM_ONCE_WRITE)
//         {
//             /*一次主循环写入BYTES_NUM_ONCE_WRITE个字节*/
//             WriteDatalengths = BYTES_NUM_ONCE_WRITE;
//         }
//         else
//         {
//             WriteDatalengths = MemoryRemainBytes;
//         }

//         for (i = 0; i < WriteDatalengths; i++)
//         {
//             NvM_BlockDescriptor[(gs_NvmMemoryInfo[BlockIndex].NvmBlockId - 1)].NvmRamBlockDataAddress[MemoryWriteOffset + i] = MemoryJob_TargetAddress[MemoryWriteOffset + i];
//         }

//         MemoryWriteOffset += WriteDatalengths;
//         MemoryRemainBytes -= WriteDatalengths;

//         if (MemoryRemainBytes <= 0)
//             rtval = E_MemoryJobResult_OK;
//         else
//             rtval = E_MemoryJobResult_Pending;

//         break;
//     default:
//         rtval = E_MemoryJobResult_Error;
//         break;
//     }
//     return rtval;
// }

// static E_MemoryJobResult MemoryErase(void)
// {
//     E_MemoryJobResult rtval = E_MemoryJobResult_Pending;
//     uint8_t BlockIndex = 0;
//     uint32_t EraseAddress;
//     uint8_t eraseblocknum = 0;
//     uint8_t i = 0;
//     static uint16_t timeout = 0;

//     for (BlockIndex = 0; BlockIndex < BLOCK_MEMORY_SIZE; BlockIndex++)
//     {
//         if (gs_BlockMemoryInfo[BlockIndex].MemoryType == gs_MemoryJobCtr.CurMemoryType)
//             break;
//     }
//     if (BlockIndex >= BLOCK_MEMORY_SIZE)
//         return E_MemoryJobResult_Error;

//     if (MemoryEraseBolckOffset >= gs_BlockMemoryInfo[BlockIndex].DataBlockNum)
//         return E_MemoryJobResult_OK;

//     if ((MemoryEraseBolckOffset + BLOCK_NUM_ONCE_ERASE) <= gs_BlockMemoryInfo[BlockIndex].DataBlockNum)
//         eraseblocknum = BLOCK_NUM_ONCE_ERASE;
//     else
//         eraseblocknum = gs_BlockMemoryInfo[BlockIndex].DataBlockNum - MemoryEraseBolckOffset;

//     for (i = 0; i < eraseblocknum; i++)
//     {
//         EraseAddress = gs_BlockMemoryInfo[BlockIndex].DataBlockStartAddress + MemoryEraseBolckOffset * gs_BlockMemoryInfo[BlockIndex].DataBlockSize;
//         MemoryEraseBolckOffset++;

//         if (Fls_Erase(EraseAddress, gs_BlockMemoryInfo[BlockIndex].DataBlockSize) != E_OK)
//             return E_MemoryJobResult_Error;

//         timeout = 0;

//         SuspendAllInterrupts();
//         do
//         {
//             Fls_MainFunction();
//             timeout++;
//         } while ((timeout <= MEMORY_OPERATION_TIMEOUT) && (MEMIF_JOB_OK != Fls_GetJobResult()));
//         ResumeAllInterrupts();

//         if (timeout > MEMORY_OPERATION_TIMEOUT)
//             return E_MemoryJobResult_Error;
//     }

//     if (MemoryEraseBolckOffset >= gs_BlockMemoryInfo[BlockIndex].DataBlockNum)
//         rtval = E_MemoryJobResult_OK;
//     else
//         rtval = E_MemoryJobResult_Pending;

//     return rtval;
// }

// /****************************************************************
//  *                                                              *
//  *                   Global Functions Define                    *
//  *                                                              *
//  ****************************************************************/
// /*
//  *   Return 0:表示43A8没有被2E服务重置，或者重置了被App清除了
//  *   Return 1:表示43A8被2E服务重置
//  */
// uint8_t Interface_GetDid43A8WriteFlag(void)
// {
//     return Did_43A8_WriteFlag;
// }

// void Interface_SetDid43A8WriteFlag(uint8_t val)
// {
//     if (val)
//     {
//         Did_43A8_WriteFlag = 1;
//     }
//     else
//     {
//         Did_43A8_WriteFlag = 0;
//     }
// }

// /*获得上电是否收到报文
//  *返回0：上电还没收到报文
//  *返回1：上电收到报文
//  */
// uint8_t Interface_GetMessageRcvdPowerOnFlag(void)
// {
//     return g_MessageRcvdPowerOn;
// }

// Std_ReturnType Interface_SetBusOffFlag(void)
// {
//     g_SysInBusOffState = 1;
//     return E_OK;
// }
// Std_ReturnType Interface_ClearBusOffFlag(void)
// {
//     g_SysInBusOffState = 0;
//     return E_OK;
// }
// /*返回值为1，表示ECU处于BusOff(慢恢复)状态，
//   返回值为0，表示ECU不处于BusOff状态
//   */
// uint8_t Interface_GetBusOffFlag(void)
// {
//     return g_SysInBusOffState;
// }

// /*调用此函数后，ECU将不会休眠*/
// Std_ReturnType Interface_SetKeepAwakeFlag(void)
// {
//     g_SysKeepAwakeFlag = 1;
//     return E_OK;
// }

// /*调用此函数后，ECU将正常走休眠流程*/
// Std_ReturnType Interface_ClearKeepAwakeFlag(void)
// {
//     g_SysKeepAwakeFlag = 0;
//     return E_OK;
// }

// uint8_t Interface_GetKeepAwakeFlag(void)
// {
//     return g_SysKeepAwakeFlag;
// }

// /*设置某个设备spi故障*/
// Std_ReturnType Interface_SetSpiError(E_SpiErrorDevice SpiErrorDevice, uint8_t devid)
// {
//     switch (SpiErrorDevice)
//     {
//     case E_SpiErrorDevice_Boost:
//         gu_BoostSpiErrorFlag |= (1 << devid);
//         break;
//     case E_SpiErrorDevice_Buck:
//         gu_BuckSpiErrorFlag |= (1 << devid);
//         break;
//     case E_SpiErrorDevice_MotorDrv:
//         gu_MotorDrvSpiErrorFlag |= (1 << devid);
//         break;
//     case E_SpiErrorDevice_Sbc:
//         gu_SbcSpiErrorFlag |= (1 << devid);
//         break;
//     }
//     return E_OK;
// }

// /*清除某个设备spi故障*/
// Std_ReturnType Interface_ClearSpiError(E_SpiErrorDevice SpiErrorDevice, uint8_t devid)
// {
//     switch (SpiErrorDevice)
//     {
//     case E_SpiErrorDevice_Boost:
//         gu_BoostSpiErrorFlag &= ~(1 << devid);
//         break;
//     case E_SpiErrorDevice_Buck:
//         gu_BuckSpiErrorFlag &= ~(1 << devid);
//         break;
//     case E_SpiErrorDevice_MotorDrv:
//         gu_MotorDrvSpiErrorFlag &= ~(1 << devid);
//         break;
//     case E_SpiErrorDevice_Sbc:
//         gu_SbcSpiErrorFlag &= ~(1 << devid);
//         break;
//     }
//     return E_OK;
// }

// E_MemoryJobResult Interface_GetMemoryJobResult(E_MemoryType MemoryType)
// {
//     if (gs_MemoryJobCtr.CurMemoryType == MemoryType)
//     {
//         return gs_MemoryJobCtr.MemoryJobResult;
//     }

//     return E_MemoryJobResult_Error;
// }

// Std_ReturnType Interface_EraseMemory(E_MemoryType MemoryType)
// {
//     Std_ReturnType rtval = E_OK;
//     if (gs_MemoryJobCtr.MemoryJobState == E_MemoryJobState_Idle)
//     {
//         gs_MemoryJobCtr.MemoryJobState = E_MemoryJobState_Busying;
//         gs_MemoryJobCtr.CurMemoryType = MemoryType;
//         gs_MemoryJobCtr.MemoryJob = E_MemoryJob_Erase;
//         gs_MemoryJobCtr.MemoryJobResult = E_MemoryJobResult_Pending;
//         MemoryEraseBolckOffset = 0; /*擦除块偏移*/
//         rtval = E_OK;
//     }
//     else
//     {
//         rtval = E_NOT_OK;
//     }

//     return rtval;
// }

// Std_ReturnType Interface_WriteMemory(E_MemoryType MemoryType, uint32_t Lens, uint8_t *DataSrc)
// {
//     Std_ReturnType rtval = E_OK;
//     if (gs_MemoryJobCtr.MemoryJobState == E_MemoryJobState_Idle)
//     {
//         gs_MemoryJobCtr.MemoryJobState = E_MemoryJobState_Busying;
//         gs_MemoryJobCtr.CurMemoryType = MemoryType;
//         gs_MemoryJobCtr.MemoryJob = E_MemoryJob_Write;
//         gs_MemoryJobCtr.MemoryJobResult = E_MemoryJobResult_Pending;
//         MemoryJob_Length = Lens;           /*写入的总长度*/
//         MemoryJob_TargetAddress = DataSrc; /*写入数据的目标首地址*/
//         MemoryRemainBytes = Lens;          /*还剩多少字节没有写入*/
//         MemoryWriteOffset = 0;             /*写字节偏移值*/
//         rtval = E_OK;
//     }
//     else
//     {
//         rtval = E_NOT_OK;
//     }

//     return rtval;
// }

// Std_ReturnType Interface_ReadMemory(E_MemoryType MemoryType, uint32_t Lens, uint8_t *DataSrc)
// {
//     Std_ReturnType rtval = E_OK;
//     if (gs_MemoryJobCtr.MemoryJobState == E_MemoryJobState_Idle)
//     {
//         gs_MemoryJobCtr.MemoryJobState = E_MemoryJobState_Busying;
//         gs_MemoryJobCtr.CurMemoryType = MemoryType;
//         gs_MemoryJobCtr.MemoryJob = E_MemoryJob_Read;
//         gs_MemoryJobCtr.MemoryJobResult = E_MemoryJobResult_Pending;
//         MemoryJob_Length = Lens;           /*读取的总长度*/
//         MemoryJob_TargetAddress = DataSrc; /*读取数据的目标首地址*/
//         MemoryRemainBytes = Lens;          /*还剩多少字节没有读取*/
//         MemoryReadOffset = 0;              /*读取字节偏移值*/
//         rtval = E_OK;
//     }
//     else
//     {
//         rtval = E_NOT_OK;
//     }
//     return rtval;
// }

// Std_ReturnType Interface_AddReInitDrvDevice(E_DrvReInitID DrvReInitID)
// {
//     g_DrvReInitMask |= (1 << DrvReInitID);
//     return E_OK;
// }
// /*
//  *Can收到报文的回调函数
//  * return 1 TRUE 之后会调用 CanIf_RxIndication
//  * return 0 FALSE 之后就不会调用 CanIf_RxIndication
//  */
// boolean Interface_CanRcvMessageCallOut(uint8 Hrh, Can_IdType CanId, uint8 CanDataLegth, const uint8 *CanSduPtr)
// {
//     Nm_StateType NmState;
//     Nm_ModeType NmMode;
//     g_MessageRcvdPowerOn = 1;
// #if HCM_LEFT_SIDE
//     if (Hrh == CanConf_CanHardwareObject_CanHardwareObject_HcmrBodyExposedNMFr)
// #else
//     if (Hrh == CanConf_CanHardwareObject_CanHardwareObject_HcmrBodyExposedNMFr)
// #endif
//     {
//         /* 3.0平台CanNmAllNmMessagesKeepAwake==FALSE ,CANNM那边会过滤掉NM报文，就用不着这边在过滤一次了*/
// #if (BASE_TECH_PLATFORM == BASE_TECH_2_0)
//         CanNmResetPncTimerHander(CanSduPtr);
// #endif
//     }
// #if HCM_LEFT_SIDE
//     else if (Hrh == CanConf_CanHardwareObject_CanHardwareObject_CemToHcmlBodyCanExposedDiagReqFrame ||
//              Hrh == CanConf_CanHardwareObject_CanHardwareObject_CemToAllFuncBodyCanExposedDiagReqFrame)
// #else
//     else if (Hrh == CanConf_CanHardwareObject_CanHardwareObject_CemToHcmrBodyCanExposedDiagReqFrame ||
//              Hrh == CanConf_CanHardwareObject_CanHardwareObject_CemToAllFuncBodyCanExposedDiagReqFrame)

// #endif
//     {
//         /*诊断报文不能唤醒网络*/
//         if (CanNm_GetState(0, &NmState, &NmMode) == E_OK)
//         {
//             if (NmState == NM_STATE_UNINIT || NmState == NM_STATE_BUS_SLEEP)
//                 return FALSE;
//         }
//         else
//         {
//             return FALSE;
//         }
//     }

//     return TRUE;
// }

// #if (DCM_UDS_SERVICE0X23_ENABLED == STD_ON)
// #include "NmHistoryState.h"
// Std_ReturnType Interface_GetFaultStateRamBufferAddress(uint32_t StartAddress, uint32_t Lens, uint8_t **OutputAddress)
// {
//     if ((StartAddress < ReadMemoryStartAddress) || ((StartAddress + Lens) > (ReadMemoryStartAddress + ReadMemorySize)))
//         return E_NOT_OK;

//     *OutputAddress = &(g_uFaultStorageBuffer[(StartAddress - ReadMemoryStartAddress)]);

//     return E_OK;
// }
// Std_ReturnType Interface_FaultStateStore(void)
// {
//     uint32_t timeout;
//     uint16_t CRC_NVM;

//     if (FaultStateNeedStore == 0)
//         return E_OK;

//     /***************************************Erase***********************************************/
//     if (Fls_Erase(READMEMORY_BLOCK_START_ADDRESS, 8192) != E_OK)
//         return E_NOT_OK;

//     timeout = 0;

//     SuspendAllInterrupts();
//     do
//     {
//         Fls_MainFunction();
//         timeout++;
//     } while ((timeout <= MEMORY_OPERATION_TIMEOUT) && (MEMIF_JOB_OK != Fls_GetJobResult()));
//     ResumeAllInterrupts();

//     if (timeout > MEMORY_OPERATION_TIMEOUT)
//         return E_NOT_OK;

//     /***************************************End Erase***********************************************/

//     /***************************************Write***********************************************/
//     g_uFaultStorageBuffer[ReadMemorySize] = (uint8_t)((FAULT_STATE_ID & 0xFF00) >> 8);
//     g_uFaultStorageBuffer[(ReadMemorySize + 1)] = (uint8_t)(FAULT_STATE_ID & 0xFF);

//     g_uFaultStorageBuffer[(ReadMemorySize + 2)] = (uint8_t)((gT_FaultStateStorageInfo.FaultStateNum & 0xFF00) >> 8);
//     g_uFaultStorageBuffer[(ReadMemorySize + 3)] = (uint8_t)(gT_FaultStateStorageInfo.FaultStateNum & 0xFF);

//     CRC_NVM = FAULT_STATE_ID + gT_FaultStateStorageInfo.FaultStateNum;

//     g_uFaultStorageBuffer[(ReadMemorySize + 4)] = (uint8_t)((CRC_NVM & 0xFF00) >> 8);
//     g_uFaultStorageBuffer[(ReadMemorySize + 5)] = (uint8_t)(CRC_NVM & 0xFF);

//     if (Fls_Write(READMEMORY_BLOCK_START_ADDRESS, g_uFaultStorageBuffer, NVM_FAULT_STORE_SIZE) != E_OK)
//     {
//         return E_NOT_OK;
//     }

//     timeout = 0;
//     SuspendAllInterrupts();
//     do
//     {
//         Fls_MainFunction();
//         timeout++;
//     } while ((timeout <= MEMORY_OPERATION_TIMEOUT) && (MEMIF_JOB_OK != Fls_GetJobResult()));
//     ResumeAllInterrupts();

//     if (timeout > MEMORY_OPERATION_TIMEOUT)
//         return E_NOT_OK;
//     /***************************************End Write***********************************************/

//     return E_OK;
// }

// Std_ReturnType Interface_FaultStateMainFunction(uint8_t timebase)
// {
//     uint8_t *FaultInfoStoreAddress = FAULT_INFO_STORE_ADDRESS;
//     uint8_t *FaultBufferStoreAddress = ReadMemoryStartAddress;
//     uint16_t NVM_FaultStateId;
//     uint16_t NVM_CRC;
//     uint16_t NVM_FaultNumer;
//     uint16_t i = 0;
//     static uint32_t ReadDataOffset = 0;
//     static uint32_t RemainDataBytes = 0;

//     if (gT_FaultStateStorageInfo.FaultBufferInitState == 2)
//         return E_OK;
//     if (gT_FaultStateStorageInfo.FaultBufferInitState == 1)
//     {
//         /*从NVM中拷贝数据到Ram*/
//         if (RemainDataBytes > 0)
//         {
//             if (RemainDataBytes >= COPY_SIZE)
//             {
//                 for (i = 0; i < COPY_SIZE; i++)
//                     g_uFaultStorageBuffer[(ReadDataOffset + i)] = FaultBufferStoreAddress[(ReadDataOffset + i)];

//                 ReadDataOffset += COPY_SIZE;
//                 RemainDataBytes -= COPY_SIZE;
//             }
//             else
//             {
//                 for (i = 0; i < RemainDataBytes; i++)
//                     g_uFaultStorageBuffer[(ReadDataOffset + i)] = FaultBufferStoreAddress[(ReadDataOffset + i)];

//                 ReadDataOffset += RemainDataBytes;
//                 RemainDataBytes = 0;
//             }
//         }
//         else
//         {
//             gT_FaultStateStorageInfo.FaultBufferInitState = 2;
//         }

//         return E_OK;
//     }

//     NVM_FaultStateId = (((uint16_t)FaultInfoStoreAddress[0] & 0x00FF) << 8) + FaultInfoStoreAddress[1];

//     if (NVM_FaultStateId != FAULT_STATE_ID)
//     {
//         /*ID号不匹配，Nvm的数据不可用*/
//         gT_FaultStateStorageInfo.FaultStateNum = 0;
//         gT_FaultStateStorageInfo.FaultBufferInitState = 2;
//         return E_OK;
//     }

//     NVM_FaultNumer = (((uint16_t)FaultInfoStoreAddress[2] & 0x00FF) << 8) + FaultInfoStoreAddress[3];
//     NVM_CRC = (((uint16_t)FaultInfoStoreAddress[4] & 0x00FF) << 8) + FaultInfoStoreAddress[5];

//     if (NVM_CRC == (NVM_FaultStateId + NVM_FaultNumer))
//     {
//         gT_FaultStateStorageInfo.FaultStateNum = NVM_FaultNumer;
//         ReadDataOffset = 0;
//         RemainDataBytes = ReadMemorySize;
//         /*准备从NVM中拷贝数据到RAM中*/
//         gT_FaultStateStorageInfo.FaultBufferInitState = 1;
//     }
//     else
//     {
//         /*CRC不匹配，Nvm的数据不可用*/
//         gT_FaultStateStorageInfo.FaultStateNum = 0;
//         gT_FaultStateStorageInfo.FaultBufferInitState = 2;
//         return E_OK;
//     }
//     return E_OK;
// }
// /*更新错误状态*/
// Std_ReturnType Interface_UpdateFaultState(uint8 *FaultState)
// {
//     uint32_t gnss = 0;
//     uint16_t i = 0;
//     uint16_t j = 0;
//     uint32_t LatestFaultOffset;

//     if (gT_FaultStateStorageInfo.FaultBufferInitState != 2)
//         return E_NOT_OK;

// #if (LATEST_STATE_AT_FIRST)
// #else
//     if (gT_FaultStateStorageInfo.FaultStateNum == 0)
//     {
//         gnss = GetNmHistoryTimeStamps();

//         g_uFaultStorageBuffer[0] = (uint8_t)((gnss & 0xFF000000) >> 24);
//         g_uFaultStorageBuffer[1] = (uint8_t)((gnss & 0x00FF0000) >> 16);
//         g_uFaultStorageBuffer[2] = (uint8_t)((gnss & 0x0000FF00) >> 8);
//         g_uFaultStorageBuffer[3] = (uint8_t)(gnss & 0x000000FF);

//         for (i = 0; i < FAULT_STATE_SIZE; i++)
//         {
//             g_uFaultStorageBuffer[(4 + i)] = FaultState[i];
//         }

//         gT_FaultStateStorageInfo.FaultStateNum++;
//         FaultStateNeedStore = 1;
//     }
//     else if (gT_FaultStateStorageInfo.FaultStateNum < FAULT_STATE_MAX_STORE_NUM)
//     {
//         /*找到最新的故障状态的存储位置*/
//         LatestFaultOffset = (gT_FaultStateStorageInfo.FaultStateNum - 1) * (STATE_TOTAL_SIZE);
//         for (i = 0; i < FAULT_STATE_SIZE; i++)
//         {
//             if (FaultState[i] != g_uFaultStorageBuffer[(LatestFaultOffset + GNSS_SIZE + i)])
//             {
//                 /*状态有改变*/
//                 break;
//             }
//         }

//         if (i < FAULT_STATE_SIZE)
//         {
//             /*状态发生改变存储*/
//             gnss = GetNmHistoryTimeStamps();
//             LatestFaultOffset = gT_FaultStateStorageInfo.FaultStateNum * (STATE_TOTAL_SIZE);

//             g_uFaultStorageBuffer[LatestFaultOffset] = (uint8_t)((gnss & 0xFF000000) >> 24);
//             g_uFaultStorageBuffer[(LatestFaultOffset + 1)] = (uint8_t)((gnss & 0x00FF0000) >> 16);
//             g_uFaultStorageBuffer[(LatestFaultOffset + 2)] = (uint8_t)((gnss & 0x0000FF00) >> 8);
//             g_uFaultStorageBuffer[(LatestFaultOffset + 3)] = (uint8_t)(gnss & 0x000000FF);

//             LatestFaultOffset += GNSS_SIZE;

//             for (i = 0; i < FAULT_STATE_SIZE; i++)
//             {
//                 g_uFaultStorageBuffer[(LatestFaultOffset + i)] = FaultState[i];
//             }

//             gT_FaultStateStorageInfo.FaultStateNum++;
//             FaultStateNeedStore = 1;
//         }
//     }
//     else
//     {
//         /*找到最新的故障状态的存储位置*/
//         LatestFaultOffset = (gT_FaultStateStorageInfo.FaultStateNum - 1) * (STATE_TOTAL_SIZE);
//         for (i = 0; i < FAULT_STATE_SIZE; i++)
//         {
//             if (FaultState[i] != g_uFaultStorageBuffer[(LatestFaultOffset + GNSS_SIZE + i)])
//             {
//                 /*状态有改变*/
//                 break;
//             }
//         }

//         if (i < FAULT_STATE_SIZE)
//         {
//             /*存储空间存满，需要删除最老的那个状态 FIFO*/
//             for (i = 0; i < (gT_FaultStateStorageInfo.FaultStateNum - 1); i++)
//             {
//                 for (j = 0; j < STATE_TOTAL_SIZE; j++)
//                 {
//                     g_uFaultStorageBuffer[(i * STATE_TOTAL_SIZE + j)] = g_uFaultStorageBuffer[((i + 1) * STATE_TOTAL_SIZE + j)];
//                 }
//             }

//             gnss = GetNmHistoryTimeStamps();
//             LatestFaultOffset = (FAULT_STATE_MAX_STORE_NUM - 1) * (STATE_TOTAL_SIZE);

//             g_uFaultStorageBuffer[LatestFaultOffset] = (uint8_t)((gnss & 0xFF000000) >> 24);
//             g_uFaultStorageBuffer[(LatestFaultOffset + 1)] = (uint8_t)((gnss & 0x00FF0000) >> 16);
//             g_uFaultStorageBuffer[(LatestFaultOffset + 2)] = (uint8_t)((gnss & 0x0000FF00) >> 8);
//             g_uFaultStorageBuffer[(LatestFaultOffset + 3)] = (uint8_t)(gnss & 0x000000FF);
//             LatestFaultOffset += GNSS_SIZE;

//             for (i = 0; i < FAULT_STATE_SIZE; i++)
//             {
//                 g_uFaultStorageBuffer[(LatestFaultOffset + i)] = FaultState[i];
//             }

//             gT_FaultStateStorageInfo.FaultStateNum = FAULT_STATE_MAX_STORE_NUM;
//             FaultStateNeedStore = 1;
//         }
//     }
// #endif
//     return E_OK;
// }
// #endif

// /*
//  *内存操作主函数：
//  *主要执行擦写和读写操作
//  */
// void SystemService_MemoryJobMainFunction(uint8_t timebase)
// {
//     if (gs_MemoryJobCtr.MemoryJobState == E_MemoryJobState_Idle)
//         return;

//     switch (gs_MemoryJobCtr.MemoryJob)
//     {
//     case E_MemoryJob_Read:
//         gs_MemoryJobCtr.MemoryJobResult = MemoryRead();
//         break;
//     case E_MemoryJob_Write:
//         gs_MemoryJobCtr.MemoryJobResult = MemoryWrite();
//         break;
//     case E_MemoryJob_Erase:
//         gs_MemoryJobCtr.MemoryJobResult = MemoryErase();
//         break;
//     }
//     /*Job!=Pending 说明出错或者OK，就把JOB状态置成IDLE*/
//     if (gs_MemoryJobCtr.MemoryJobResult != E_MemoryJobResult_Pending)
//         gs_MemoryJobCtr.MemoryJobState = E_MemoryJobState_Idle;
// }

// void SystemService_MainFunction(uint8_t timebase)
// {
//     DrvReInit_MainFunc(timebase);
//     RamTstMainFunc(timebase);
//     FlsTstMainFunc(timebase);
//     SpiErrMainFunc(timebase);
// #if (DCM_UDS_SERVICE0X23_ENABLED == STD_ON)
//     Interface_FaultStateMainFunction(timebase);
// #endif
// #if MEMORY_TEST
//     uint32_t signal = 0;
//     static uint8 stepcase = 0;
//     Interface_GetSignal_ActnOfLedDaytiRunngLamp(&signal);
//     if (signal == 1)
//     {
//         switch (stepcase)
//         {
//         case 0:
//             if (Interface_EraseMemory(E_MemoryType_LightShow) == E_OK)
//             {
//                 stepcase = 1;
//             }
//             break;
//         case 1:
//             if (Interface_WriteMemory(E_MemoryType_LightShow, (1024 * 8 * 4 + 5), LightShowWriteData) == E_OK)
//                 stepcase = 2;
//             break;
//         case 2:
//             if (Interface_GetMemoryJobResult(E_MemoryType_LightShow) == E_MemoryJobResult_OK)
//                 stepcase = 3;
//             break;
//         case 3:
//             if (Interface_ReadMemory(E_MemoryType_LightShow, (1024 * 8 * 4 + 5), LightShowReadData) == E_OK)
//                 stepcase = 4;
//             break;
//         case 4:
//             if (Interface_GetMemoryJobResult(E_MemoryType_LightShow) == E_MemoryJobResult_OK)
//                 stepcase = 5;
//             break;
//         case 5:
//             stepcase = 5;
//             break;
//         }
//     }
// #endif
// }

// void SystemService_FlsTstMainFunction(uint8_t timebase)
// {
//     static uint8_t FlsTstNum = 0;
//     uint8 SignatureResult;
//     uint8 *TestAddr;
//     uint8 *DataPtr;
//     uint32_t TestLength;
//     uint32_t CalcCrc;
//     uint32_t StoreCrc;
//     Std_ReturnType result = E_OK;

//     if (FlsTstNum >= FLS_TST_BLOCK_NUM)
//         return;
//     if (FLS_TST_BLOCK_NUM == 0)
//         return;

//     if ((ge_FlsTstResult[FlsTstNum] == E_FlsTstResult_NotTest) ||
//         (ge_FlsTstResult[FlsTstNum] == E_FlsTstResult_Testing))
//     {
//         ge_FlsTstResult[FlsTstNum] = E_FlsTstResult_Testing;

//         /*判断地址是否有效*/
//         if ((gs_FlsTstDataBlockInfo[FlsTstNum].DataStoreStartAddress < FLSTST_VALIED_START_ADDRESS) ||
//             (gs_FlsTstDataBlockInfo[FlsTstNum].DataStoreStartAddress > FLSTST_VALIED_END_ADDRESS) ||
//             (gs_FlsTstDataBlockInfo[FlsTstNum].DataLensStoreStartAddress < FLSTST_VALIED_START_ADDRESS) ||
//             ((gs_FlsTstDataBlockInfo[FlsTstNum].DataLensStoreStartAddress + 3) > FLSTST_VALIED_END_ADDRESS) ||
//             (gs_FlsTstDataBlockInfo[FlsTstNum].CrcStoreStartAddress < FLSTST_VALIED_START_ADDRESS) ||
//             ((gs_FlsTstDataBlockInfo[FlsTstNum].CrcStoreStartAddress + 3) > FLSTST_VALIED_END_ADDRESS))
//         {
//             ge_FlsTstResult[FlsTstNum] = E_FlsTstResult_TestNotOK;
//             result = E_NOT_OK;
//         }

//         if (result == E_OK)
//         {
//             TestAddr = (uint8 *)gs_FlsTstDataBlockInfo[FlsTstNum].DataStoreStartAddress;
//             DataPtr = (uint8 *)gs_FlsTstDataBlockInfo[FlsTstNum].DataLensStoreStartAddress;
// #if (BYTE_ORDER == BYTE_BIG_ENDIAN)
//             TestLength = DataPtr[3] + (((uint32_t)(DataPtr[2])) << 8) + (((uint32_t)(DataPtr[1])) << 16) + (((uint32_t)(DataPtr[0])) << 24);
// #else
//             TestLength = DataPtr[0] + (((uint32_t)(DataPtr[1])) << 8) + (((uint32_t)(DataPtr[2])) << 16) + (((uint32_t)(DataPtr[3])) << 24);
// #endif
//             /*长度超出范围（Debug的时候TestLength=0xFFFFFFFF，避免这种情况）*/
//             if (TestLength > (FLSTST_VALIED_END_ADDRESS - FLSTST_VALIED_START_ADDRESS + 1))
//             {
//                 ge_FlsTstResult[FlsTstNum] = E_FlsTstResult_TestNotOK;
//                 result = E_NOT_OK;
//             }
//             else
//             {
//                 /*长度+起始地址超出范围*/
//                 if ((gs_FlsTstDataBlockInfo[FlsTstNum].DataStoreStartAddress + TestLength) > FLSTST_VALIED_END_ADDRESS)
//                 {
//                     ge_FlsTstResult[FlsTstNum] = E_FlsTstResult_TestNotOK;
//                     result = E_NOT_OK;
//                 }
//             }
//         }

//         if (result == E_OK)
//         {
//             switch (gs_FlsTstDataBlockInfo[FlsTstNum].FlsTstAlgorithmType)
//             {
//             case FLSTST_8BIT_CRC:
//                 CalcCrc = (uint32_t)Crc_CalculateCRC8((uint8 *)TestAddr, TestLength, (uint8)SignatureResult, TRUE);
//                 break;
//             case FLSTST_16BIT_CRC:
//                 CalcCrc = (uint32_t)Crc_CalculateCRC16((uint8 *)TestAddr, TestLength, (uint16)SignatureResult, TRUE);
//                 break;
//             case FLSTST_32BIT_CRC:
//                 CalcCrc = (uint32_t)Crc_CalculateCRC32((uint8 *)TestAddr, TestLength, (uint16)SignatureResult, TRUE);
//                 break;
//             }
//             DataPtr = (uint8 *)gs_FlsTstDataBlockInfo[FlsTstNum].CrcStoreStartAddress;
// #if (BYTE_ORDER == BYTE_BIG_ENDIAN)
//             StoreCrc = DataPtr[3] + (((uint32_t)(DataPtr[2])) << 8) + (((uint32_t)(DataPtr[1])) << 16) + (((uint32_t)(DataPtr[0])) << 24);
// #else
//             StoreCrc = DataPtr[0] + (((uint32_t)(DataPtr[1])) << 8) + (((uint32_t)(DataPtr[2])) << 16) + (((uint32_t)(DataPtr[3])) << 24);
// #endif
//             if (StoreCrc == CalcCrc)
//                 ge_FlsTstResult[FlsTstNum] = E_FlsTstResult_TestOK;
//             else
//                 ge_FlsTstResult[FlsTstNum] = E_FlsTstResult_TestNotOK;
//         }
//     }
//     else
//     {
//         FlsTstNum++;
//     }
// }

// Std_ReturnType SystemServiceInit(void)
// {
//     Std_ReturnType rtval = E_OK;

//     g_DrvReInitMask = 0;

//     return rtval;
// }

// #include "Os.h"
// void Fls_AccessStartNotif(void)
// {
//     SuspendAllInterrupts();
// }

// void Fls_AccessFinishNotif(void)
// {
//     ResumeAllInterrupts();
// }
