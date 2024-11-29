#ifndef _SYSTEMSERVICE_INTERFACE_H_
#define _SYSTEMSERVICE_INTERFACE_H_

/****************************************************************
 *                                                              *
 *                     Include Files                            *
 *                                                              *
 ****************************************************************/
#include "HcmPlatform.h"
#include "FlsTst_Types.h"
#include "Nvm_Cfg.h"
#include "Dcm_Cfg.h"
/****************************************************************
 *                                                              *
 *                      Macro Define                            *
 *                                                              *
 ****************************************************************/
#define DRV_REINIT_NUM 3

#define BLOCK_NUM_ONCE_ERASE 1   /*一次擦除多少个block*/
#define BYTES_NUM_ONCE_WRITE 512 /*一次写多少个字节*/
#define BYTES_NUM_ONCE_READ 512  /*一次读多少个字节*/

#define BLOCK_MEMORY_SIZE 2


#if (DCM_UDS_SERVICE0X23_ENABLED == STD_ON)
#include "Rte_Dcm.h"
/*23服务存储故障信息*/
#define GNSS_SIZE 4                                                        /*Global Real Time所占字节数*/
#define FAULT_STATE_SIZE 2                                                 /*故障存储所占字节数*/
#define STATE_TOTAL_SIZE (GNSS_SIZE + FAULT_STATE_SIZE)                    /*一个状态总共需要存储的空间*/
#define FAULT_STATE_MAX_STORE_NUM ((ReadMemorySize / (STATE_TOTAL_SIZE)))  /*故障最多存储个数*/
#define LATEST_STATE_AT_FIRST 0                                            /*1：故障最新状态放在数组首位    0：故障最新状态放在数组最后*/
#define FAULT_STATE_ID 0x0001                                              /*故障存储的版本号，如果故障信息发生改变（存储长度或者位域发生改变），此版本号升级*/
#define FAULT_INFO_STORE_ADDRESS (ReadMemoryStartAddress + ReadMemorySize) /*错误信息存储位置 : 跟在存储数据的后面*/
#define COPY_SIZE 100                                                      /*一次从NVM中拷贝多少个字节到ram*/

#define READMEMORY_BLOCK_BASE_ADDRESS 0x1000000
#define READMEMORY_BLOCK_START_ADDRESS 0x18000

#define NVM_FAULT_STORE_SIZE (ReadMemorySize + 8)                           /*NVM一共要存的字节数 6：2字节FAULT_STATE_ID，2 字节FaultNumber,2字节CRC
                                                                              NVM_FAULT_STORE_SIZE一定要是EB里面配置的PageSize(16)的整数倍，否则FlsWrite会返回E_NOT_OK*/

typedef struct
{
    uint8_t FaultBufferInitState; /*存储buffer状态 ：0-> Rambuffer不可用  1->Rambuffer不可用,正在从NVM拷贝数据到Ram中  2->Rambuffer数据可用*/
    uint16_t FaultStateNum;       /*存储了多少个错误状态*/
} T_FaultStateStorageInfo;
#endif

/*Light Show Block Info*/
#define LIGHTSHOW_BLOCK_SIZE 8192
#define LIGHTSHOW_BLOCK_BASE_ADDRESS 0x1000000
#define LIGHTSHOW_BLOCK_START_ADDRESS 0x8000
#define LIGHTSHOW_BLOCK_NUM 6

/*Welcome Goodbye Block Info*/
#define WELGBY_BLOCK_SIZE 8192
#define WELGBY_BLOCK_BASE_ADDRESS 0x1000000
#define WELGBY_BLOCK_START_ADDRESS 0x14000
#define WELGBY_BLOCK_NUM 1

#define NVM_MEMORY_SIZE 1
/*Light Show ExtFlag Info*/
#define LIGHTSHOWEXTFLAG_BLOCK_ID NvMBlock_LightShowExtFlag
#define LIGHTSHOWEXTFLAG_DATA_SIZE 62

#define MEMORY_OPERATION_TIMEOUT 1000
#define MEMORY_WRITE_BUFFER_SIZE 128

#define MEMORY_FILL_ENABLE 1

#if MEMORY_FILL_ENABLE
#define MEMORY_FILL_DATA 0xCC
#define MEMORY_TEST 0
#endif

#define FLS_TST_BLOCK_NUM 2
#define FLSTST_VALIED_START_ADDRESS 0x0
#define FLSTST_VALIED_END_ADDRESS 0x1FFFFF

#define FLSTST_EXE_CRC_STORE_START_ADDRESS 0x21000
#define FLSTST_EXE_LENS_STORE_START_ADDRESS 0x21004
#define FLSTST_EXE_DATA_STORE_START_ADDRESS 0x22000

#define FLSTST_DATA_CRC_STORE_START_ADDRESS 0x1E4100
#define FLSTST_DATA_LENS_STORE_START_ADDRESS 0x1E4104
#define FLSTST_DATA_DATA_STORE_START_ADDRESS 0x1E4108

#define BYTE_BIG_ENDIAN 0
#define BYTE_LITTLE_ENDIAN 1
#define BYTE_ORDER BYTE_BIG_ENDIAN

/****************************************************************
 *                                                              *
 *                     Data Type Define                         *
 *                                                              *
 ****************************************************************/
/******************************************Memory 存储******************************************/
typedef enum
{
    E_DrvReInitID_Boost = 0,
    E_DrvReInitID_Buck = 1,
    // E_DrvReInitID_MatrixTrip = 2,
} E_DrvReInitID;

typedef enum
{
    E_MemoryType_None = 0,
    E_MemoryType_LightShow = 1,
    E_MemoryType_WelGby = 2,
    E_MemoryType_LightShowExtFlag = 3,
} E_MemoryType;

typedef enum
{
    E_MemoryJobState_Idle = 0,
    E_MemoryJobState_Busying = 1,
} E_MemoryJobState;

typedef enum
{
    E_MemoryJobResult_OK = 0,
    E_MemoryJobResult_Error = 1,
    E_MemoryJobResult_Pending = 2,
} E_MemoryJobResult;

typedef enum
{
    E_MemoryJob_None = 0,
    E_MemoryJob_Read = 1,
    E_MemoryJob_Write = 2,
    E_MemoryJob_Erase = 3,
} E_MemoryJob;

typedef struct
{
    E_MemoryType CurMemoryType;
    E_MemoryJob MemoryJob;
    E_MemoryJobState MemoryJobState;
    E_MemoryJobResult MemoryJobResult;
} S_MemoryJobCtr;

typedef struct
{
    E_MemoryType MemoryType;
    uint8_t DataBlockNum;
    uint32_t DataBlockStartAddress;
    uint32_t DataBlockSize;
} S_BlockMemoryInfo;

typedef struct
{
    E_MemoryType MemoryType;
    uint16_t NvmBlockId;
    uint16_t DataLens;
} S_NvmMemoryInfo;

typedef enum
{
    E_SpiErrorDevice_Boost = 0,
    E_SpiErrorDevice_Buck = 1,
    E_SpiErrorDevice_MotorDrv = 2,
    E_SpiErrorDevice_Sbc = 3,
} E_SpiErrorDevice;

/********************************************************Flash Tset********************************************************/
typedef enum
{
    E_FlsTstDataBlockType_EXE = 0,
    E_FlsTstDataBlockType_DATA = 1,
} E_FlsTstDataBlockType;

typedef enum
{
    E_FlsTstResult_NotTest = 0,
    E_FlsTstResult_Testing = 1,
    E_FlsTstResult_TestOK = 2,
    E_FlsTstResult_TestNotOK = 3,
} E_FlsTstResult;

typedef struct
{
    E_FlsTstDataBlockType FlsTstDataBlockType;
    FlsTst_AlgorithmType FlsTstAlgorithmType;
    uint32_t DataStoreStartAddress;
    uint32_t DataLensStoreStartAddress;
    uint32_t CrcStoreStartAddress;
} S_FlsTstDataBlockInfo;

/****************************************************************
 *                                                              *
 *                   Global Functions                           *
 *                                                              *
 ****************************************************************/

uint8_t Interface_GetDid43A8WriteFlag(void);
void Interface_SetDid43A8WriteFlag(uint8_t val);
uint8_t Interface_GetMessageRcvdPowerOnFlag(void);
Std_ReturnType Interface_SetBusOffFlag(void);
Std_ReturnType Interface_ClearBusOffFlag(void);
/*返回值为1，表示ECU处于BusOff(慢恢复)状态，
  返回值为0，表示ECU不处于BusOff状态
  */
uint8_t Interface_GetBusOffFlag(void);

/*调用此函数设置标记位，ECU将不休眠*/
Std_ReturnType Interface_SetKeepAwakeFlag(void);
/*调用此函数后，ECU将正常走休眠流程*/
Std_ReturnType Interface_ClearKeepAwakeFlag(void);
uint8_t Interface_GetKeepAwakeFlag(void);
Std_ReturnType Interface_SetSpiError(E_SpiErrorDevice SpiErrorDevice, uint8_t devid);
Std_ReturnType Interface_ClearSpiError(E_SpiErrorDevice SpiErrorDevice, uint8_t devid);
Std_ReturnType Interface_EraseMemory(E_MemoryType MemoryType);
Std_ReturnType Interface_WriteMemory(E_MemoryType MemoryType, uint32_t Lens, uint8_t *DataSrc);
Std_ReturnType Interface_ReadMemory(E_MemoryType MemoryType, uint32_t Lens, uint8_t *DataSrc);
Std_ReturnType Interface_AddReInitDrvDevice(E_DrvReInitID DrvReInitID);
E_MemoryJobResult Interface_GetMemoryJobResult(E_MemoryType MemoryType);

void SystemService_MemoryJobMainFunction(uint8_t timebase);
void SystemService_MainFunction(uint8_t timebase);
void SystemService_FlsTstMainFunction(uint8_t timebase);
Std_ReturnType SystemServiceInit(void);

#if (DCM_UDS_SERVICE0X23_ENABLED == STD_ON)
Std_ReturnType Interface_GetFaultStateRamBufferAddress(uint32_t StartAddress, uint32_t Lens, uint8_t **OutputAddress);
Std_ReturnType Interface_FaultStateStore(void);
Std_ReturnType Interface_FaultStateMainFunction(uint8_t timebase);
Std_ReturnType Interface_UpdateFaultState(uint8 *FaultState);
#endif

void Fls_AccessStartNotif(void);
void Fls_AccessFinishNotif(void);
extern FUNC(void, OS_CODE) SuspendAllInterrupts(void);
extern FUNC(void, OS_CODE) ResumeAllInterrupts(void);
#endif