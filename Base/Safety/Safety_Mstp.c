#include "SafetyDrv.h"
#include "Mstp.h"

#define SAFETY_MSTP_REG_CHECK_NUM (27U) // EB Config 检查数

void Safety_MstpInit(void)
{
    Mstp_Init();
}

// EB的Config固定后 初始化EB配置的CRC
static uint32 Ex_SafetyLib_ExpectedCrcVal[SAFETY_MSTP_REG_CHECK_NUM] = {
    0x1F0AD8BB,
    0x45279DBA,
    0x45279DBA,
    0x45279DBA,
    0x1F0AD8BB,
    0x45279DBA,
    0x45279DBA,
    0x45279DBA,
    0x1F0AD8BB,
    0x45279DBA,
    0x45279DBA,
    0x45279DBA,
    0xC9EE8C57,
    0x45279DBA,
    0x45279DBA,
    0x45279DBA,
    0x98D0C2E8,
    0x45279DBA,
    0x45279DBA,
    0x45279DBA,
    0xE57CB7B1,
    0x45279DBA,
    0x45279DBA,
    0x45279DBA,
    0x7AD521F2,
    0x45279DBA,
    0x45279DBA,
};

void Safety_MstpRegCheck(void)
{
    boolean TestRet = FALSE;
    static uint32 ResultBuffer[SAFETY_MSTP_REG_CHECK_NUM] = {0x00U};
    uint8 Index = 0U;

    Mstp_TriggerRegCheck();

    TestRet = Mstp_GetRegCheckResult(ResultBuffer, SAFETY_MSTP_REG_CHECK_NUM);

    if (TRUE == TestRet)
    {
        for (Index = 0U; Index < SAFETY_MSTP_REG_CHECK_NUM; ++Index)
        {
            if (Ex_SafetyLib_ExpectedCrcVal[Index] != ResultBuffer[Index])
            {
                Safety_SetTestRes(SAFETY_MSTP_REG_CHECK, SAFETY_ERROR);
                TestRet = FALSE;
                return;
            }
        }
    }

    Safety_SetTestRes(SAFETY_MSTP_REG_CHECK, SAFETY_NORMAL);
}

uint32_t ret = 0;
void SafeTy_MstpReadDelayRegisterCheck(void)
{
    ret = Mstp_ReadFlashDelayReg();
    if (0xFFFFFFFF == ret)
    {
        // Invalid value indicates Flash peripheral is not enabled
    }
    // In normal read (LSMODE=0), the recommended
    // 04: CORE_CLK <= 160M
    uint32_t LSMODE = Mstp_FlashRegBfPtr->FLASH_FCTRL.LSMODE;
    if ((LSMODE == 0) && (ret != 4))
    {
        // ...
        Safety_SetTestRes(SAFETY_MSTP_READ_DELAY_REG, SAFETY_ERROR);
    }

    // In low speed read (LSMODE=1), the recommended
    // 1h: CORE_CLK <= 40M
    if ((LSMODE == 1) && (ret != 1))
    {
        // ...
        Safety_SetTestRes(SAFETY_MSTP_READ_DELAY_REG, SAFETY_ERROR);
    }

    Safety_SetTestRes(SAFETY_MSTP_READ_DELAY_REG, SAFETY_NORMAL);
}

// 当前定义测试范围 
// 0  0x20000000 ~ 0x20000008
// 1  0x20010000 ~ 0x20010008
void Safety_MstpRamTst(void)
{
    Safety_MpuSetAllow();  //  mpu中配置0x20000000 ~ 0x20004000 不可写， 测试前开启可写
    Mstp_RamTstMainFunction();
}
