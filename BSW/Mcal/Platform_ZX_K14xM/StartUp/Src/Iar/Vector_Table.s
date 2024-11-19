/*****************************************************************************************/
/* @file      : Vector_Table.s                                                           */
/* @brief     : Vector table Source File.                                                */
/*              - Platform: Z20K14xM                                                     */
/*              - Autosar Version: 4.6.0                                                 */
/* @version   : 1.2.2                                                                    */
/* @author    : Zhixin Semiconductor                                                     */
/* @note                                                                                 */
/*                                                                                       */
/* @copyright : Copyright (c) 2021-2024 Zhixin Semiconductor Ltd. All rights reserved.   */
/*****************************************************************************************/
    SECTION .intvec:DATA:ROOT(2)
    EXTERN undefined_handler
    PUBLIC __VECTOR_TABLE
    EXTERN __STACK_TOP               /* Top of Stack for Initial Stack Pointer */
    EXTERN Reset_Handler             /* Reset Handler */
    EXTERN NMI_Handler               /* NMI Handler */
    EXTERN HardFault_Handler         /* Hard Fault Handler */
    EXTERN MemManageFault_Handler    /* Reserved */
    EXTERN BusFault_Handler          /* Bus Fault Handler */
    EXTERN UsageFault_Handler        /* Usage Fault Handler */
    EXTERN SVC_Handler               /* SVCall Handler */
    EXTERN DebugMonitor_Handler      /* Debug Monitor Handler */
    EXTERN PendSV_Handler            /* PendSV Handler */
    EXTERN SysTick_Handler           /* SysTick Handler */ /* 15*/

__VECTOR_TABLE
    DCD __STACK_TOP               /* Top of Stack for Initial Stack Pointer */
    DCD Reset_Handler             /* Reset Handler */
    DCD NMI_Handler               /* NMI Handler */
    DCD HardFault_Handler         /* Hard Fault Handler */
    DCD MemManageFault_Handler    /* Reserved */
    DCD BusFault_Handler          /* Bus Fault Handler */
    DCD UsageFault_Handler        /* Usage Fault Handler */
    DCD 0                         /* Reserved */
    DCD 0                         /* Reserved */
    DCD 0                         /* Reserved */
    DCD 0                         /* Reserved */
    DCD SVC_Handler               /* SVCall Handler */
    DCD DebugMonitor_Handler      /* Debug Monitor Handler */
    DCD 0                         /* Reserved */
    DCD PendSV_Handler            /* PendSV Handler */
    DCD SysTick_Handler           /* SysTick Handler */ /* 15*/

    DCD undefined_handler /*0*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*10*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler 
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*20*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler 
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*30*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler 
    DCD undefined_handler /*40*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler 
    DCD undefined_handler
    DCD undefined_handler /*50*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*60*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler 
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*70*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*80*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*90*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler 
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*100*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*110*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*120*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*130*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*140*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*150*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*160*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*170*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*180*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*190*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*200*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*204*/


    END
