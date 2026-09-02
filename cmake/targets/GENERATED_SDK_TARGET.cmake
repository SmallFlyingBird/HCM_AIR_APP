cmake_minimum_required(VERSION 3.16)



set(sources
    ${PROJ_DIR}/Mcal/Mcu/src/Mcu.c
    ${PROJ_DIR}/Mcal/Mcu/src/Mcu_Lld.c
    ${PROJ_DIR}/Mcal/Mcu/src/Mcu_Lld_Irq.c
    ${PROJ_DIR}/Mcal/Rte/src/SchM_Mcu.c
    ${PROJ_DIR}/Mcal/Rte/src/SchM_Adc.c
    ${PROJ_DIR}/Mcal/Rte/src/SchM_Dio.c
    ${PROJ_DIR}/Mcal/Rte/src/SchM_CddDma.c
    ${PROJ_DIR}/Mcal/Rte/src/SchM_Fls.c
    ${PROJ_DIR}/Mcal/Rte/src/SchM_Gpt.c
    ${PROJ_DIR}/Mcal/Rte/src/SchM_Icu.c
    ${PROJ_DIR}/Mcal/Rte/src/SchM_Lin.c
    ${PROJ_DIR}/Mcal/Rte/src/SchM_Port.c
    ${PROJ_DIR}/Mcal/Rte/src/SchM_Pwm.c
    ${PROJ_DIR}/Mcal/Rte/src/SchM_Spi.c
    ${PROJ_DIR}/Mcal/Rte/src/SchM_Platform.c
    ${PROJ_DIR}/Mcal/Adc/src/Adc.c
    ${PROJ_DIR}/Mcal/Adc/src/Adc_Irq.c
    ${PROJ_DIR}/Mcal/Adc/src/Adc_Lld.c
    ${PROJ_DIR}/Mcal/Dio/src/Dio_Lld.c
    ${PROJ_DIR}/Mcal/Dio/src/Dio.c
    ${PROJ_DIR}/Mcal/EcuM/src/EcuM.c
    ${PROJ_DIR}/Mcal/CddDma/src/CddDma.c
    ${PROJ_DIR}/Mcal/CddDma/src/CddDma_Lld.c
    ${PROJ_DIR}/Mcal/Det/src/Det.c
    ${PROJ_DIR}/Mcal/Fls/src/Fls.c
    ${PROJ_DIR}/Mcal/Fls/src/Fls_Mld.c
    ${PROJ_DIR}/Mcal/Fls/src/Fls_Lld.c
    ${PROJ_DIR}/Mcal/Gpt/src/Gpt.c
    ${PROJ_DIR}/Mcal/Gpt/src/Gpt_Mld.c
    ${PROJ_DIR}/Mcal/Gpt/src/Gpt_Lld_Lptmr.c
    ${PROJ_DIR}/Mcal/Gpt/src/Gpt_Lld_Lptmr_Irq.c
    ${PROJ_DIR}/Mcal/Gpt/src/Gpt_Lld_Ptmr.c
    ${PROJ_DIR}/Mcal/Gpt/src/Gpt_Lld_Ptmr_Irq.c
    ${PROJ_DIR}/Mcal/Gpt/src/Gpt_Lld_Tmr.c
    ${PROJ_DIR}/Mcal/Gpt/src/Gpt_Lld_Tmr_Irq.c
    ${PROJ_DIR}/Mcal/Gpt/src/Gpt_Lld_Rtc.c
    ${PROJ_DIR}/Mcal/Gpt/src/Gpt_Lld_Rtc_Irq.c
    ${PROJ_DIR}/Mcal/Icu/src/Icu_Lld_Etmr.c
    ${PROJ_DIR}/Mcal/Icu/src/Icu_Etmr_Irq.c
    ${PROJ_DIR}/Mcal/Icu/src/Icu_Lld_Port.c
    ${PROJ_DIR}/Mcal/Icu/src/Icu_Port_Irq.c
    ${PROJ_DIR}/Mcal/Icu/src/Icu_Mld.c
    ${PROJ_DIR}/Mcal/Icu/src/Icu.c
    ${PROJ_DIR}/Mcal/Lin/src/Lin.c
    ${PROJ_DIR}/Mcal/Lin/src/Lin_Mld.c
    ${PROJ_DIR}/Mcal/Lin/src/Lin_Lld.c
    ${PROJ_DIR}/Mcal/LinIf/src/LinIf.c
    ${PROJ_DIR}/Mcal/Port/src/Port.c
    ${PROJ_DIR}/Mcal/Port/src/Port_Lld.c
    ${PROJ_DIR}/Mcal/Pwm/src/Pwm.c
    ${PROJ_DIR}/Mcal/Pwm/src/Pwm_Mld.c
    ${PROJ_DIR}/Mcal/Pwm/src/Pwm_Lld_Etmr.c
    ${PROJ_DIR}/Mcal/Pwm/src/Pwm_Lld_Etmr_Irq.c
    ${PROJ_DIR}/Mcal/Spi/src/Spi.c
    ${PROJ_DIR}/Mcal/Spi/src/Spi_Lld.c
    ${PROJ_DIR}/Mcal/Platform/src/exceptions.c
    ${PROJ_DIR}/Mcal/Platform/src/IntCtrl_Lld.c
    ${PROJ_DIR}/Mcal/Platform/src/OsIf.c
    ${PROJ_DIR}/Mcal/Platform/src/Platform_Mld.c
    ${PROJ_DIR}/Mcal/Platform/src/Platform.c
    ${PROJ_DIR}/Mcal/Platform/src/System_Lld.c
    ${PROJ_DIR}/Mcal/Platform/src/Mpu_Lld_M33.c
)
set(includes
    ${PROJ_DIR}/Mcal/Mcu/inc
    ${PROJ_DIR}/Mcal/Rte/inc
    ${PROJ_DIR}/Mcal/Adc/inc
    ${PROJ_DIR}/Mcal/Dio/inc
    ${PROJ_DIR}/Mcal/EcuM/inc
    ${PROJ_DIR}/Mcal/CddDma/inc
    ${PROJ_DIR}/Mcal/Det/inc
    ${PROJ_DIR}/Mcal/Fls/inc
    ${PROJ_DIR}/Mcal/Gpt/inc
    ${PROJ_DIR}/Mcal/Icu/inc
    ${PROJ_DIR}/Mcal/Lin/inc
    ${PROJ_DIR}/Mcal/LinIf/inc
    ${PROJ_DIR}/Mcal/MemIf/inc
    ${PROJ_DIR}/Mcal/Port/inc
    ${PROJ_DIR}/Mcal/Pwm/inc
    ${PROJ_DIR}/Mcal/Spi/inc
    ${PROJ_DIR}/Mcal/Platform/inc
    ${PROJ_DIR}/Mcal/Platform/core
    ${PROJ_DIR}/Mcal/Platform/YTM32B1MD1/feature
    ${PROJ_DIR}/Mcal/Platform/YTM32B1MD1/regmap
)
set(priIncludes
)

add_library(GENERATED_SDK_TARGET STATIC ${sources})

target_include_directories(GENERATED_SDK_TARGET PUBLIC ${includes})


target_include_directories(GENERATED_SDK_TARGET PRIVATE ${priIncludes})
configcore(GENERATED_SDK_TARGET ${CMAKE_SOURCE_DIR})

target_compile_definitions(GENERATED_SDK_TARGET PUBLIC
    YTM32B1MD1
    CPU_YTM32B1MD1
)
target_compile_options(GENERATED_SDK_TARGET PUBLIC
)



target_link_libraries(GENERATED_SDK_TARGET
    GENERATED_CONFIG_TARGET
)
