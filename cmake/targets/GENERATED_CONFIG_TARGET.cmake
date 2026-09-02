cmake_minimum_required(VERSION 3.16)



set(sources
    ${PROJ_DIR}/board/RamInit0.s
    ${PROJ_DIR}/board/RamInit1.c
    ${PROJ_DIR}/board/RamInit2.c
    ${PROJ_DIR}/board/Mcu_Cfg.c
    ${PROJ_DIR}/board/Mcu_PBcfg.c
    ${PROJ_DIR}/board/Adc_Cfg.c
    ${PROJ_DIR}/board/Adc_PBcfg.c
    ${PROJ_DIR}/board/Dio_Cfg.c
    ${PROJ_DIR}/board/CddDma_Cfg.c
    ${PROJ_DIR}/board/CddDma_PBcfg.c
    ${PROJ_DIR}/board/Fls_Cfg.c
    ${PROJ_DIR}/board/Fls_PBcfg.c
    ${PROJ_DIR}/board/Gpt_Cfg.c
    ${PROJ_DIR}/board/Gpt_PBcfg.c
    ${PROJ_DIR}/board/Icu_Cfg.c
    ${PROJ_DIR}/board/Icu_PBcfg.c
    ${PROJ_DIR}/board/Lin_Cfg.c
    ${PROJ_DIR}/board/Lin_PBcfg.c
    ${PROJ_DIR}/board/Port_Cfg.c
    ${PROJ_DIR}/board/Port_PBcfg.c
    ${PROJ_DIR}/board/Pwm_Cfg.c
    ${PROJ_DIR}/board/Pwm_PBcfg.c
    ${PROJ_DIR}/board/Pwm_Lld_Etmr_PBcfg.c
    ${PROJ_DIR}/board/Spi_Cfg.c
    ${PROJ_DIR}/board/Spi_PBcfg.c
    ${PROJ_DIR}/board/IntCtrl_Lld_Cfg.c
    ${PROJ_DIR}/board/Mpu_Lld_Cfg.c
    ${PROJ_DIR}/board/Platform_Cfg.c
    ${PROJ_DIR}/board/Platform_Mld_Cfg.c
    ${PROJ_DIR}/board/startup.S
    ${PROJ_DIR}/board/vector.S
    ${PROJ_DIR}/board/vector_table_copy.c
    ${PROJ_DIR}/board/system.c
)
set(includes
    ${PROJ_DIR}/board
)
set(priIncludes
)

add_library(GENERATED_CONFIG_TARGET STATIC ${sources})

target_include_directories(GENERATED_CONFIG_TARGET PUBLIC ${includes})


target_include_directories(GENERATED_CONFIG_TARGET PRIVATE ${priIncludes})
configcore(GENERATED_CONFIG_TARGET ${CMAKE_SOURCE_DIR})

target_compile_definitions(GENERATED_CONFIG_TARGET PUBLIC
    YTM32B1MD1
    CPU_YTM32B1MD1
)
target_compile_options(GENERATED_CONFIG_TARGET PUBLIC
)



target_link_libraries(GENERATED_CONFIG_TARGET
    GENERATED_SDK_TARGET
)
