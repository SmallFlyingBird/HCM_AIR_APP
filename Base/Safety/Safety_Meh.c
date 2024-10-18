#include "SafetyDrv.h"
#include "Meh.h"
#include "Z20K148M.h"
#include "Mstp_Cfg.h"
#include "Mcu.h"
#include "Mcu_Types.h"

#define MEH_EIRU_SRAM_DATA 1

typedef struct
{
    uint8_t Htmss_FLAG;
    uint8_t FLS_ECC_FLAG;
    boolean injected;
    uint8_t detected;
    uint8_t detectedRes;
    Mcu_ResetType restType;
} MehFlsDebug;

static MehFlsDebug g_mehD = {
    .Htmss_FLAG = 0,
    .FLS_ECC_FLAG = 0,
    .injected = false,
    .detected = 0,
    .detectedRes = 0,
    .restType = MCU_POWER_ON_RESET,
};

void SeruParityErrorCallbackFunc(void)
{
}

void SeruChannelErrorCallbackFunc(uint32 SeruCh)
{
    // 软件通道错误
    if ((SeruCh == SERU_DRV_SW_ERR0) || (SeruCh == SERU_DRV_SW_ERR1) || (SeruCh == SERU_DRV_SW_ERR2))
    {
        Mstp_SeruRegBfPtr->SERU_SWERR_GNT.SWERR_CH0 = 0;
        Mstp_SeruRegBfPtr->SERU_SWERR_GNT.SWERR_CH1 = 0;
        Mstp_SeruRegBfPtr->SERU_SWERR_GNT.SWERR_CH2 = 0;
    }

    if (SeruCh == SERU_DRV_FLASH_ECC_ERROR)
    {
        // 发生MBE 故障， noraml reset， 可在复位后查看复位原因
        if (g_mehD.injected)
        {
            g_mehD.FLS_ECC_FLAG++;
            
        }
        else
        {
            g_mehD.Htmss_FLAG++;
        }
    }

    if (SeruCh == SERU_DRV_FLASH_UNSECURE)
    {
    }
}

void EiruErrorCallback(const Meh_SramType Sram,
                       const Meh_SramEccErrStatusType ErrorStatus,
                       Meh_SramEccErrCauseType *ErrorCausePtr)
{
    (void)Sram;
    (void)ErrorStatus;
    (void)ErrorCausePtr;
}

void Safety_MehInit(void)
{
    Meh_Init(NULL_PTR);
}

void Safety_MehSramInject(void)
{
    // 故障注入未开放API，通过调试修改寄存器的方式

    // SRAM方式
    // 配置被检SRAM 地址EIRU_EEIADDR
    // 配置ECC mask  或者  DATA mask
    // 访问SRAM 触发
    static uint32 Idx = 0U;
    Mstp_EiruRegBfPtr->EIRU_EEIADDR.EEIADDR = ((uint32_t)&Idx) >> 2;
#ifdef MEH_EIRU_SRAM_DATA
    Mstp_EiruRegBfPtr->EIRU_SRAMn_SC[1].EIRU_SRAMn_DATAMASK.DATAMASK = 1;
#elif
    Mstp_EiruRegBfPtr->EIRU_SRAMn_SC[1].EIRU_SRAMn_ECCMASK.ECCMASK = 1;
#endif
    for (Idx = 0U; Idx < 10000U; ++Idx)
    {
    }
    Meh_MainFunction();
}

void Safety_MehSeruInject(void)
{
    // SERU 注入测试 三个SW通道支持手动注入
    Mstp_SeruRegBfPtr->SERU_SWERR_GNT.SWERR_CH0 = 1;
}

// extern Reg_Flash_BfType *const Mstp_FlashRegBfPtr;
// extern Reg_Flash_WType *const  Mstp_FlashRegWPtr;
const static uint32_t ecc_tst_data = 0x88ABCDEF;
static uint32_t ecc_data_addr = 0;
static uint32_t ecc_data_read = 0;

void Safety_FlsEccInject(void)
{
    if (g_mehD.Htmss_FLAG != 0)
    {
        return; // 如果监测到注入过故障不再注入
    }

    ecc_data_addr = (uint32_t)&ecc_tst_data;

    //  1. Unlock FLASH_ECC_IN_ADDR and FLASH_ECC_IN_CTRL by writing 0x5C to FLASH_ECC_IN_CTRL[31:24]
    Mstp_FlashRegWPtr->FLASH_ECC_IN_CTRL = Mstp_FlashRegWPtr->FLASH_ECC_IN_CTRL & 0xffffff | 0x5c000000;

    // 2. Configure ECC injection address by writing FLASH_ECC_IN_ADDR[31:4]
    Mstp_FlashRegWPtr->FLASH_ECC_IN_ADDR = ecc_data_addr;

    // 3. Configure ECC injection 128-bit data on FLASH_FDATA0-FLASH_FDATA3 and 9-bit
    // ECC value on FLASH_ECC_IN_CTRL[8:0], and the 137-bit read data from flash arrays
    // will make XNOR operation with 137-bit ECC injection data before ECC check circuit.
    Mstp_FlashRegWPtr->FLASH_FDATA0 = 0;
    Mstp_FlashRegBfPtr->FLASH_ECC_IN_CTRL.ECC_9BIT = 0x1EF;

    // 4. Enable ECC injection function by writing 1 to FLASH_ECC_IN_CTRL[9]
    Mstp_FlashRegBfPtr->FLASH_ECC_IN_CTRL.ECC_IN_EN = 1;

    // 5. Check ECC event status on FLASH_MBE_STATE and FLASH_SBE_STATE, while bus
    // error and interrupt can generate with right configuration on ECC double bit error.

    g_mehD.injected = true;
    /* read */
    ecc_data_read = ecc_tst_data;
    ecc_data_read = 0;
}

void Safety_LatenSBEDetection(void)
{
    g_mehD.detected++;
    Reg_Flash_BfType *const Fls_Drv_FlsRegBfPtr = (Reg_Flash_BfType *)FLASHC_BASE_ADDR;
    if (Fls_Drv_FlsRegBfPtr->FLASH_FSTAT.DFDIF == 1)
    {
        g_mehD.detectedRes++;
        // MBE 故障处理 （除非flash本身真正发生了ecc错误， 注入的ECC故障 产生的DFDFF 标记无法保留到下次复位）
        Safety_SetTestRes(SAFETY_MEH_LATEN_SBE, SAFETY_ERROR);
    }

    Safety_SetTestRes(SAFETY_MEH_LATEN_SBE, SAFETY_NORMAL);

    g_mehD.restType = Mcu_GetResetReason();
}