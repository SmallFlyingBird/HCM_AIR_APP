#include "SafetyDrv.h"
#include "Mstp.h"
#include "Mpu.h"
#include "smpu_drv_os.h"
#include "ghs_compatible.h"

#define MpuRegionConfig_STL_Data            SMPU_MEMORY_REGION_0
#define MpuRegionConfig_PFLASH              SMPU_MEMORY_REGION_1
#define MpuRegionConfig_DFLASH              SMPU_MEMORY_REGION_2
#define MpuRegionConfig_SRAM_L              SMPU_MEMORY_REGION_3
#define MpuRegionConfig_IFR                 SMPU_MEMORY_REGION_4
#define MpuRegionConfig_SRAM_U_ex_stl       SMPU_MEMORY_REGION_5

void RamTestCompletedNotification(void)
{
    Safety_SetTestRes(SAFETY_MSTP_RAM_RW, SAFETY_NORMAL);
}


void RamTestErrorNotification(void)
{
    Safety_SetTestRes(SAFETY_MSTP_RAM_RW, SAFETY_ERROR);
}

boolean static g_mpuStarted = false;

// ram_stl_data 区域 0x20000000 ~ 0x20000040 ， 上电测试后不再使用
uint8_t value[0x40] __attribute__((section(".stl_data"))) = {0x0};

// 标记ram分区位置
const uint8_t ram_add_0 __attribute__((section(".tst0"))) = 0xFA;
const uint8_t ram_add_1 __attribute__((section(".tst1"))) = 0xFB;
const uint8_t ram_add_2 __attribute__((section(".tst2"))) = 0xFC;
const uint8_t ram_add_3 __attribute__((section(".tst3"))) = 0xFD;
static uint32_t addr[4] = {0};

void Safety_MpuReadTst(void)
{
    uint8_t readTst = value[1];

    addr[0] = (uint32_t)&ram_add_0;
    addr[1] = (uint32_t)&ram_add_1;
    addr[2] = (uint32_t)&ram_add_2;
    addr[3] = (uint32_t)&ram_add_3;
}


void Safety_MpuSettNotAllow(void)
{
    // default config not allow write
    SMPU_Disable();
    SMPU_MemoryRegionConfigDisable(MpuRegionConfig_STL_Data);
    SMPU_BusMstSvrModeAccessControl(MpuRegionConfig_STL_Data, SMPU_BUS_MASTER_0, SMPU_READ_EXE_ALLOWED); // 配置 master_core 访问 STL_Data 的权限
    SMPU_MemoryRegionConfigEnable(MpuRegionConfig_STL_Data);
    SMPU_Enable();
}

void Safety_MpuSetAllow(void)
{
    SMPU_Disable();
    SMPU_MemoryRegionConfigDisable(MpuRegionConfig_STL_Data);
    SMPU_BusMstSvrModeAccessControl(MpuRegionConfig_STL_Data, SMPU_BUS_MASTER_0, SMPU_ALL_ALLOWED);
    SMPU_MemoryRegionConfigEnable(MpuRegionConfig_STL_Data);
    SMPU_Enable();
}


void Safety_MpuWriteTstNotAllow(void)
{
    Safety_MpuSettNotAllow();
    value[0] = 0xFF;
}

void Safety_MpuWriteTstAllow(void)
{
    Safety_MpuSetAllow();
    value[0] = 0x00;
}

static void Safety_MpuEnableBusFault(void)
{
    __asm(
        "ldr  r0, =0xE000ED24 \t\n"
        "ldr  r1, [r0]\t\n"
        "ldr  r2, =0x00070000 \t\n"
        "orr  r1, r2\t\n"
        "str  r1, [r0]\t\n"
        "dsb\t\n"
        "isb\t\n"
    );
}

void Safety_Mpuinit(void)
{
    Mpu_Init(NULL_PTR); 
    Safety_MpuEnableBusFault();
    g_mpuStarted = true;
}


static Mpu_SalveErrorType mpuError;
void MpuErrorNotificationFunc(const uint8 SlavePort, const Mpu_SalveErrorType *ErrorTypePtr)
{
    (void)SlavePort;
    (void)ErrorTypePtr;
    mpuError.ErrorAddress = ErrorTypePtr->ErrorAddress;
    mpuError.MrcnIndication = ErrorTypePtr->MrcnIndication;
    mpuError.BusMasterId = ErrorTypePtr->BusMasterId;
    mpuError.AccessError = ErrorTypePtr->AccessError;
    mpuError.AccessMode = ErrorTypePtr->AccessMode;
    mpuError.IsWriteError = mpuError.IsWriteError;
}

boolean Safety_MpuStart(void)
{
    return g_mpuStarted;
}