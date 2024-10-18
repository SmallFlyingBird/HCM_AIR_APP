;  ***************************************************************************************
;  @file      : Vector_Table.s                                                                 
;  @brief     : Vector table Source File.                                                      
;               - Platform: Z20K14xM                                                      
;               - Autosar Version: 4.6.0                                                  
;  @version   : 1.2.1                                                                     
;  @author    : Zhixin Semiconductor                                                      
;  @note                                                                                  
;                                                                                         
;  @copyright : Copyright (c) 2021-2023 Zhixin Semiconductor Ltd. All rights reserved.    
; ****************************************************************************************
        
        EXPORT  __VECTOR_TABLE
        EXPORT  __VECTOR_TABLE_END
        EXPORT  __Vectors_Size

        ;IMPORT  __main
        IMPORT  Reset_Handler
        IMPORT  NMI_Handler
        IMPORT  HardFault_Handler
        IMPORT  MemManageFault_Handler
        IMPORT  BusFault_Handler
        IMPORT  UsageFault_Handler
        IMPORT  SVC_Handler
        IMPORT  DebugMonitor_Handler
        IMPORT  PendSV_Handler
        IMPORT  SysTick_Handler
        IMPORT  undefined_handler
        IMPORT  |Image$$ARM_LIB_STACK$$ZI$$Limit|
        AREA    |.intvec|, DATA, READONLY
__VECTOR_TABLE
        DCD   |Image$$ARM_LIB_STACK$$ZI$$Limit| ; Top of Stack
        DCD   Reset_Handler+1           ; POR Reset Entry
        DCD   NMI_Handler             ; Non Maskable handler
        DCD   HardFault_Handler       ; SV Hard Fault handler
        DCD   MemManageFault_Handler  ; MemManage Fault Handler
        DCD   BusFault_Handler        ; Bus Fault Handler
        DCD   UsageFault_Handler      ; Usage Fault Handler
        DCD   0
        DCD   0
        DCD   0
        DCD   0
        DCD   SVC_Handler+1              ; SV Call handler
        DCD   DebugMonitor_Handler     ; debug monitor Handler
        DCD   0
        DCD   PendSV_Handler           ; Pend SV handler
        DCD   SysTick_Handler          ; System Tick handler


        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 10
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 20
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 30
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 40
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 50
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 60
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 70
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 80
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 90
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 100
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 110
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 120
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 130
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 140
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 150
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 160
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 170
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 180
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 190
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 200
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 
        DCD   undefined_handler             ; 204
__VECTOR_TABLE_END

__Vectors_Size  EQU   __VECTOR_TABLE_END - __VECTOR_TABLE
        END