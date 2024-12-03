#ifndef OS_USER_H
#define OS_USER_H

extern void undefined_handler(void);
extern void NMI_Handler(void);
extern void HardFault_Handler(void); 
extern void MemManageFault_Handler(void) ;
extern void BusFault_Handler(void);
extern void UsageFault_Handler(void);
extern void DebugMonitor_Handler(void);
extern void PendSV_Handler(void);
extern void SysTick_Handler(void);
extern void SVC_Handler(void); 
extern void Reset_Handler(void);
extern void StartOS(void);
#endif
