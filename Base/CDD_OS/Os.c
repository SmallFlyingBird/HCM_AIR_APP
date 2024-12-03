#include "Platform.h"
#include "Mcu.h"
#include "Port.h"
#include "Adc.h"
#include "Lin.h"
#include "Dio.h"
#include "Spi.h"
#include "Pwm.h"
#include "SchM_Spi.h"
#include "CDD_Dma.h"
#include "Gpt.h"
#include "EcuM.h"
#include "Dio_Service.h"
#include "Gpt_Service.h"
#include "Wdg.h"
#include "Os.h"
#include "Platform.h"
#include "Ex_Lin.h"
#include "Ex_SleepWakeup.h"
#include "Os_User.h"

#define OS_NVIC_ICTR_ADDRESS      0xE000E004u              /* Interrupt Controller Type Register */
#define OS_NVIC_ISER_BASE_ADDRESS 0xE000E100u /* Interrupt Set-Enable Register0-15:0xE000E100->0xE000E13C */
#define OS_NVIC_ICER_BASE_ADDRESS 0xE000E180u /* Interrupt Clear-Enable Register0-15:0xE000E180->0xE000E1BC */
#define OS_NVIC_ISPR_BASE_ADDRESS 0xE000E200u /* Interrupt Set-Pending Register 0-15:0xE000E200->0xE000E23C */
#define OS_NVIC_ICPR_BASE_ADDRESS 0xE000E280u /* Interrupt Clear-Pending Register 0-15:0xE000E280->0xE000E2BC */
#define OS_NVIC_IABR_BASE_ADDRESS 0xE000E300u /* Active Bit Register Register 0-15:0xE000E300->0xE000E37C */
#define OS_NVIC_IPR_BASE_ADDRESS  0xE000E400u /* Interrupt Priority Register 0-123:0xE000E400->0xE000E7EC */
#define OS_NVIC_STIR_ADDRESS      0xE000EF00u /* Software Trigger Interrupt Register */
#define OS_NVIC_CPUID_ADDRESS     0xE000ED00u
#define OS_NVIC_ICSR_ADDRESS      0xE000ED04u
#define OS_NVIC_VTOR_ADDRESS      0xE000ED08u
#define OS_NVIC_AIRCR_ADDRESS     0xE000ED0Cu
#define OS_NVIC_SCR_ADDRESS       0xE000ED10u
#define OS_NVIC_SEPR_BASE_ADDRESS 0xE000ED18u

/* Core interrupts */
#define OS_INITSTACK_IRQn                   (0u)
#define OS_RESET_IRQn                       (1u)
#define OS_NonMaskableInt_IRQn              (2u)                               /**< Non Maskable Interrupt */
#define OS_HardFault_IRQn                   (3u)                               /**< Cortex-M7 SV Hard Fault Interrupt */
#define OS_MemoryManagement_IRQn            (4u)                               /**< Cortex-M7 Memory Management Interrupt */
#define OS_BusFault_IRQn                    (5u)                               /**< Cortex-M7 Bus Fault Interrupt */
#define OS_UsageFault_IRQn                  (6u)                               /**< Cortex-M7 Usage Fault Interrupt */
#define OS_SVCall_IRQn                      (11u)                              /**< Cortex-M7 SV Call Interrupt */
#define OS_DebugMonitor_IRQn                (12u)                              /**< Cortex-M7 Debug Monitor Interrupt */
#define OS_PendSV_IRQn                      (14u)                              /**< Cortex-M7 Pend SV Interrupt */
#define OS_SysTick_IRQn                     (15u)                              /**< Cortex-M7 System Tick Interrupt */

#define OS_REG32(address) (*(volatile uint32*)(address)) /* 32-bit register */
#define OS_REG16(address) (*(volatile uint16*)(address)) /* 16-bit register */
#define OS_REG8(address)  (*(volatile uint8*)(address))  /*  8-bit register */

/* SysTick Timer */
#define OS_SYSTICK_ENABLE_BIT   (1u << 0u)
#define OS_SYSTICK_INT_BIT      (1u << 1u)
#define OS_SYSTICK_CLK_BIT      (1u << 2u)

#define OS_SYSTICK_BASE_ADDRESS (0xE000E010U)
#define OS_SYSTICK_CTRL_REG     OS_REG32(OS_SYSTICK_BASE_ADDRESS)
#define OS_SYSTICK_RELOAD_REG   OS_REG32(OS_SYSTICK_BASE_ADDRESS + 0x4u)
#define OS_SYSTICK_COUNTER_REG  OS_REG32(OS_SYSTICK_BASE_ADDRESS + 0x8u)
#define OS_SYSTICK_CHECK_REG    OS_REG32(OS_SYSTICK_BASE_ADDRESS + 0xCu)

/* System timer register value define */
#define     CFG_REG_OSTIMER_VALUE_CORE             160000U

/* Set interrupt priority */
/* Interrupt priority conversion */
#define OS_NVIC_PRIO_BITS   (4u)
#define OS_NVIC_PRIO_LEVELS (1u << OS_NVIC_PRIO_BITS)
#define OS_NVIC_PRIO_SHIFT  (8u - OS_NVIC_PRIO_BITS)
#define OS_NVIC_PRIO_MIN    0x00u
#define OS_NVIC_PRIO_MAX    0xFFu
#define OS_INTERRUPT_SYS_PRIO(id)  OS_REG8(OS_NVIC_SEPR_BASE_ADDRESS + id)
#define OS_INTERRUPT_NVIC_PRIO(id) OS_REG8(OS_NVIC_IPR_BASE_ADDRESS + id)
#define OS_INTERRUPT_SET_PRIO(id, prio)                  \
    if (id >= 16)                                        \
    {                                                    \
        OS_INTERRUPT_NVIC_PRIO(id - 16) = (uint8)(prio); \
    }                                                    \
    else if (id >= 4)                                    \
    {                                                    \
        OS_INTERRUPT_SYS_PRIO(id - 4) = (uint8)(prio);   \
    }                                                    \
    else                                                 \
    {                                                    \
    }
#define OS_NVIC_CONVERT_GET_PRIO(prio) (uint8)(((prio) ^ 0xFFu) >> OS_NVIC_PRIO_SHIFT)
#define OS_NVIC_CONVERT_SET_PRIO(prio) (uint8)(((prio) ^ 0xFFu) << OS_NVIC_PRIO_SHIFT)

/* define section */
extern const uint32 __RAM_INTERRUPT_START;
extern const uint32 __STACK_TOP;

/* build interrupt vector */
static void Os_InterruptInit(void)
{
    uint32 index;
    uint32 *addr = (uint32)&__RAM_INTERRUPT_START;
    uint32 stack = (uint32)&__STACK_TOP;

    for (index = 0; index < 16; index++)
    {
        if (0u == index )                                                  /* HardFault */
        {
            addr[OS_INITSTACK_IRQn] = stack;
        }
        else if (1u == index )                                                  /* HardFault */
        {
            addr[OS_RESET_IRQn] = (uint32) (&Reset_Handler + 1);
        }
        else if (2u == index )                                                  /* HardFault */
        {
            addr[OS_NonMaskableInt_IRQn] = (uint32) &NMI_Handler;
        }
        else if (3u == index )                                                  /* HardFault */
        {
            addr[OS_HardFault_IRQn] = (uint32) &HardFault_Handler;
        }
        else if (5u == index )                                                  /* HardFault */
        {
            addr[OS_BusFault_IRQn] = (uint32) &BusFault_Handler;
        }
        else if (6u == index )                                                  /* HardFault */
        {
            addr[OS_UsageFault_IRQn] = (uint32) &UsageFault_Handler;
        }
        else if (11u == index)                                                 /* SVC */
        {
            OS_INTERRUPT_SET_PRIO(OS_SVCall_IRQn, OS_NVIC_CONVERT_SET_PRIO(OS_NVIC_PRIO_MAX));
            addr[OS_SVCall_IRQn] = (uint32) (&SVC_Handler);
        }
        else if (14u == index )                                                 /* PendSV */
        {
            OS_INTERRUPT_SET_PRIO(OS_PendSV_IRQn, OS_NVIC_CONVERT_SET_PRIO(OS_NVIC_PRIO_MIN));
            addr[OS_PendSV_IRQn] = (uint32) (&PendSV_Handler + 1);
        }
        else if (15u == index )                                                 /* SysTick */
        {
            OS_INTERRUPT_SET_PRIO(OS_SysTick_IRQn, OS_NVIC_CONVERT_SET_PRIO(OS_NVIC_PRIO_MAX));
            addr[OS_SysTick_IRQn] = (uint32) (&SysTick_Handler);
        }
        else
        {
            /* Default */
        }
    }
}

/*Init system timer for OS*/
static void Os_ArchInitSystemTimer(void)
{
    OS_SYSTICK_CTRL_REG = 0x0u;
    OS_SYSTICK_COUNTER_REG = 0x0u;
    OS_SYSTICK_RELOAD_REG = CFG_REG_OSTIMER_VALUE_CORE - 0x1u;
    OS_SYSTICK_CTRL_REG = (OS_SYSTICK_CLK_BIT | OS_SYSTICK_INT_BIT);
}

/* Initiate Systick timer */
static void Os_StartSysTimer(void)
{
    /*Start SysTick counter*/
    OS_SYSTICK_CTRL_REG |= OS_SYSTICK_ENABLE_BIT;
}
/* Run Task */
unsigned int Delay = 0;
uint8 temp = 0;
uint8 temp1[8];
extern uint8 *ExLin_ControlBuffPtr;

static void OS_Task(void)
{
    /*keep lin awake*/
    Dio_WriteChannel(DioConf_DioChannel_LIN_Wake_N, STD_LOW);
    Dio_WriteChannel(DioConf_DioChannel_LIN_SLP_N, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_CC_Boost_EN, STD_LOW);

    //Pwm_SetPeriodAndDuty(PwmConf_PwmChannel_PTE8_PWM_OUT, 50, 0x5199);

    temp = Dio_ReadChannel(DioConf_DioChannel_CC_Boost_EN);
    Ex_SleepWakupInit();
    // Ex_Spi_UseCase_01();
    ExLin_SetDTC(DTC_Highside1_Error,Short_Circuit);
    ExLin_SetStatus(STATUS_BUCK_Temp,0x60);

    Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_100MS);
    Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_100MS, 5000);
    
    while (1)
    {

        for (uint8 i = 0; i < 8;i++)
        {
            temp1[i] = ExLin_ControlBuffPtr[i];
        }
        Wdg_Service();
        Delay = 10000U;
        while (Delay--)
            ;
    };
}
/* Os Initial */
void StartOS(void)
{
	/* Initial Interrupt */
	Os_InterruptInit();
	Platform_Init(NULL_PTR);
	/*Initate Timer*/
	Os_ArchInitSystemTimer();
	Os_StartSysTimer();

	/* Run Task */
	OS_Task();
}

