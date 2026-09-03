cmake_minimum_required(VERSION 3.16)



set(sources
    # ==================== CDD ====================
    # CDD/Parameter
    ${PROJ_DIR}/HCM/CDD/Parameter/0000_Default/ParaMgr.c

    # CDD/CDD_Driver
    ${PROJ_DIR}/HCM/CDD/CDD_Driver/AdcDrv/AdcDrv.c
    ${PROJ_DIR}/HCM/CDD/CDD_Driver/BuckDrv/BD18397.c
    ${PROJ_DIR}/HCM/CDD/CDD_Driver/BuckDrv/BD18397_Interface.c
    ${PROJ_DIR}/HCM/CDD/CDD_Driver/CDD_Driver_Manager/Cdd_Driver_Manager.c
    ${PROJ_DIR}/HCM/CDD/CDD_Driver/HighSideDrv/DrvTps2HB35.c
    # ${PROJ_DIR}/HCM/CDD/CDD_Driver/Smpu_Drv/smpu_drv_os.c
    ${PROJ_DIR}/HCM/CDD/CDD_Driver/Wdg_Drv/TPL8536.c

    # CDD/CDD_OS
    ${PROJ_DIR}/HCM/CDD/CDD_OS/CpuLoad.c
    ${PROJ_DIR}/HCM/CDD/CDD_OS/Os.c
    ${PROJ_DIR}/HCM/CDD/CDD_OS/Os_User.c

    # CDD/Safety
    # ${PROJ_DIR}/HCM/CDD/Safety/Safety_Cmu.c
    # ${PROJ_DIR}/HCM/CDD/Safety/Safety_Drv.c
    # ${PROJ_DIR}/HCM/CDD/Safety/Safety_Htmss.c
    # ${PROJ_DIR}/HCM/CDD/Safety/Safety_Meh.c
    # ${PROJ_DIR}/HCM/CDD/Safety/Safety_Mpu.c
    # ${PROJ_DIR}/HCM/CDD/Safety/Safety_Mstp.c
    # ${PROJ_DIR}/HCM/CDD/Safety/Safety_Pmu.c
    # ${PROJ_DIR}/HCM/CDD/Safety/Safety_Tdg.c
    # ${PROJ_DIR}/HCM/CDD/Safety/m4_stl_exceptions.c
    # ${PROJ_DIR}/HCM/CDD/Safety/m4_stl_main.c

    # CDD/TestExample
    # ${PROJ_DIR}/HCM/CDD/TestExample/Adc/Ex_adc.c
    ${PROJ_DIR}/HCM/CDD/TestExample/SleepWakeup/Src/Ex_SleepWakeup.c

    # ==================== ASW ====================
    # ASW/ASW_INTERFACE
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/ADC_Interface/AdcDev_Interface.c
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/EOL_Interface/EOL_Interface.c
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/Base/GeneralFunction.c
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/BSW_Interface/DID_Interface.c
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/BSW_Interface/DTC_Interface.c
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/BSW_Interface/DidConfig.c
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/BSW_Interface/DtcConfig.c
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/Channel_Interface/Buck_Interface.c
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/Channel_Interface/Channel_Interface.c
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/Derate_Interface/AmbiDerate_Interface.c
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/Derate_Interface/BuckDerate_Interface.c
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/Derate_Interface/DerateRatioManager_Interface.c
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/Derate_Interface/NtcDerate_Interface.c
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/Derate_Interface/OUVDerate_Interface.c
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/HighSide_Interface/HighSide_Interface.c
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/LRDirection_Interface/LRDirection_Interface.c
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/NtcRcod_Interface/NtcRcod_Interface.c
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/Parameter_Interface/Parameter_Interface.c
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/PowerSupply_Interface/PowerSupply_Interface.c
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/PulseGenerator_Interface/PulseGenerator_Interface.c
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/SystemService_Interface/SystemService_Interface.c

    # ASW/ASW_Manager, DCMotor, Fan, HSDManage, src(服务层)
    ${PROJ_DIR}/HCM/ASW/ASW_Manager/ASW_Manager.c
    ${PROJ_DIR}/HCM/ASW/ASW_Manager/LinManager.c
    ${PROJ_DIR}/HCM/ASW/ASW_Manager/RTE_ASW.c
    ${PROJ_DIR}/HCM/ASW/DCMotor/DCMotor.c
    ${PROJ_DIR}/HCM/ASW/Fan/Fan.c
    ${PROJ_DIR}/HCM/ASW/HSDManage/HSDManage.c
    ${PROJ_DIR}/HCM/ASW/src/Adc_Service.c
    ${PROJ_DIR}/HCM/ASW/src/Dio_Service.c
    ${PROJ_DIR}/HCM/ASW/src/Dma_Service.c
    ${PROJ_DIR}/HCM/ASW/src/Pwm_Service.c
    ${PROJ_DIR}/HCM/ASW/src/Spi_Service.c

    # ASW/Lighting
    ${PROJ_DIR}/HCM/ASW/Lighting/Lighting.c
    ${PROJ_DIR}/HCM/ASW/Lighting/LampManager.c
    ${PROJ_DIR}/HCM/ASW/Lighting/WelGdy.c
    ${PROJ_DIR}/HCM/ASW/Lighting/HSDManager.c
    ${PROJ_DIR}/HCM/ASW/Lighting/ADS/ADS.c
    ${PROJ_DIR}/HCM/ASW/Lighting/CorneringLamp/CorneringLamp.c
    ${PROJ_DIR}/HCM/ASW/Lighting/DRLPos/DRL.c
    ${PROJ_DIR}/HCM/ASW/Lighting/DRLPos/POS.c
    ${PROJ_DIR}/HCM/ASW/Lighting/FogLamp/FogLamp.c
    ${PROJ_DIR}/HCM/ASW/Lighting/FrontCrossLamp/FrontCrossLamp.c
    ${PROJ_DIR}/HCM/ASW/Lighting/GrilleLamp/GrilleLamp.c
    ${PROJ_DIR}/HCM/ASW/Lighting/LBHB/LB.c
    ${PROJ_DIR}/HCM/ASW/Lighting/LBHB/HB.c
    ${PROJ_DIR}/HCM/ASW/Lighting/LogoLamp/LogoLamp.c
    ${PROJ_DIR}/HCM/ASW/Lighting/StarsLight/StarsLight.c
    ${PROJ_DIR}/HCM/ASW/Lighting/TurnIndicator/TurnIndicator.c

    # ==================== BSW ====================
    # # BSW/Config/BSW_Config (注: Mcal_Config/Src 由 GENERATED_CONFIG_TARGET 编译, 不重复包含)
    # ${PROJ_DIR}/HCM/BSW/Config/BSW_Config/Dcm_Cfg.c
    # ${PROJ_DIR}/HCM/BSW/Config/BSW_Config/LinIf_Cfg.c
    # ${PROJ_DIR}/HCM/BSW/Config/BSW_Config/PduR_Callout.c
    # ${PROJ_DIR}/HCM/BSW/Config/BSW_Config/Rte_Com.c
    # ${PROJ_DIR}/HCM/BSW/Config/BSW_Config/Rte_Dcm.c
    # ${PROJ_DIR}/HCM/BSW/Config/BSW_Config/Rte_Dcm_Callout.c
    # ${PROJ_DIR}/HCM/BSW/Config/BSW_Config/Rte_Nvm.c
    # ${PROJ_DIR}/HCM/BSW/Config/BSW_Config/E2E/Rte_E2EXf.c
    # ${PROJ_DIR}/HCM/BSW/Config/BSW_Config/E2E/Rte_E2EXf_LCfg.c
    # ${PROJ_DIR}/HCM/BSW/Config/BSW_Config/E2E/Rte_E2E_Callout.c
    # ${PROJ_DIR}/HCM/BSW/Config/BSW_Config/E2E/Rte_Xf_Cfg.c
    # ${PROJ_DIR}/HCM/BSW/Config/BSW_Config/NVM/Fee_Cfg.c
    # ${PROJ_DIR}/HCM/BSW/Config/BSW_Config/NVM/MemIf_Cfg.c
    # ${PROJ_DIR}/HCM/BSW/Config/BSW_Config/NVM/NvM_Cfg.c

    # # BSW/Diagnostic
    # ${PROJ_DIR}/HCM/BSW/Diagnostic/Dcm/Dcm.c
    # ${PROJ_DIR}/HCM/BSW/Diagnostic/Dcm/Dcm_Dsp.c
    # ${PROJ_DIR}/HCM/BSW/Diagnostic/Dem/Dem.c
    # ${PROJ_DIR}/HCM/BSW/Diagnostic/LinTp/LinTp.c
    # ${PROJ_DIR}/HCM/BSW/Diagnostic/LinTp/LinTp_Internal.c
    # ${PROJ_DIR}/HCM/BSW/Diagnostic/LinTp/LinTp_Slave.c

    # # BSW/Communication
    # ${PROJ_DIR}/HCM/BSW/Communication/LinIf/LinIf_Slave.c
    # ${PROJ_DIR}/HCM/BSW/Communication/LinSM/LinSM.c
    # ${PROJ_DIR}/HCM/BSW/Communication/Com/Com.c
    # ${PROJ_DIR}/HCM/BSW/Communication/Com/Com_Cfg.c

    # # BSW/Memory (SchM 仅含头文件, 无 .c)
    # ${PROJ_DIR}/HCM/BSW/Memory/Fee/Fee.c
    # ${PROJ_DIR}/HCM/BSW/Memory/MemIf/MemIf.c
    # ${PROJ_DIR}/HCM/BSW/Memory/NvM/NvM.c
    # ${PROJ_DIR}/HCM/BSW/Memory/NvM/NvM_Inter.c

    # # BSW/Crc 与 BSW/E2E
    # ${PROJ_DIR}/HCM/BSW/Crc/Crc.c
    # ${PROJ_DIR}/HCM/BSW/E2E/E2E.c
    # ${PROJ_DIR}/HCM/BSW/E2E/E2E_P01.c
)
set(includes
    ${PROJ_DIR}/app
    # ${PROJ_DIR}/board

    ${PROJ_DIR}/HCM/CDD/Parameter
    ${PROJ_DIR}/HCM/CDD/CDD_Driver/AdcDrv
    ${PROJ_DIR}/HCM/CDD/CDD_Driver/BuckDrv
    ${PROJ_DIR}/HCM/CDD/CDD_Driver/CDD_Driver_Manager
    ${PROJ_DIR}/HCM/CDD/CDD_Driver/HighSideDrv
    # ${PROJ_DIR}/HCM/CDD/CDD_Driver/Smpu_Drv
    ${PROJ_DIR}/HCM/CDD/CDD_Driver/Wdg_Drv
    ${PROJ_DIR}/HCM/CDD/CDD_OS
    # ${PROJ_DIR}/HCM/CDD/Safety
    # ${PROJ_DIR}/HCM/CDD/Safety/Inc
    # ${PROJ_DIR}/HCM/CDD/Safety/Cortex_M4_STL/Inc
    # ${PROJ_DIR}/HCM/CDD/Safety/Cortex_M4_STL/Inc/ARM.CMSIS.5.3.0/CMSIS/Include
    ${PROJ_DIR}/HCM/CDD/TestExample/Lin/Inc
    ${PROJ_DIR}/HCM/CDD/TestExample/SleepWakeup/Inc

    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/ADC_Interface
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/EOL_Interface
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/ASW_Interface_Manager
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/Base
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/BSW_Interface
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/Channel_Interface
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/Derate_Interface
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/HighSide_Interface
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/NtcRcod_Interface
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/Parameter_Interface
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/PowerSupply_Interface
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/PulseGenerator_Interface
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/LRDirection_Interface
    ${PROJ_DIR}/HCM/ASW/ASW_INTERFACE/SystemService_Interface

    ${PROJ_DIR}/HCM/ASW/Include
    ${PROJ_DIR}/HCM/ASW/ASW_Manager
    ${PROJ_DIR}/HCM/ASW/DCMotor
    ${PROJ_DIR}/HCM/ASW/Fan
    ${PROJ_DIR}/HCM/ASW/HSDManage
    ${PROJ_DIR}/HCM/ASW/Lighting
    ${PROJ_DIR}/HCM/ASW/Lighting/LBHB
    ${PROJ_DIR}/HCM/ASW/Lighting/TurnIndicator
    ${PROJ_DIR}/HCM/ASW/Lighting/DRLPos
    ${PROJ_DIR}/HCM/ASW/Lighting/FrontCrossLamp
    ${PROJ_DIR}/HCM/ASW/Lighting/FogLamp
    ${PROJ_DIR}/HCM/ASW/Lighting/CorneringLamp
    ${PROJ_DIR}/HCM/ASW/Lighting/ADS
    ${PROJ_DIR}/HCM/ASW/Lighting/StarsLight
    ${PROJ_DIR}/HCM/ASW/Lighting/LogoLamp
    ${PROJ_DIR}/HCM/ASW/Lighting/GrilleLamp

    # ${PROJ_DIR}/HCM/BSW/Config/Mcal_Config/Inc
    # ${PROJ_DIR}/HCM/BSW/Config/BSW_Config
    # ${PROJ_DIR}/HCM/BSW/Config/BSW_Config/NVM
    # ${PROJ_DIR}/HCM/BSW/Config/BSW_Config/E2E
    # ${PROJ_DIR}/HCM/BSW/Diagnostic/Dcm
    # ${PROJ_DIR}/HCM/BSW/Diagnostic/Dem
    # ${PROJ_DIR}/HCM/BSW/Diagnostic/LinTp
    # ${PROJ_DIR}/HCM/BSW/Communication/LinIf
    # ${PROJ_DIR}/HCM/BSW/Communication/LinSM
    # ${PROJ_DIR}/HCM/BSW/Communication/Com
    # ${PROJ_DIR}/HCM/BSW/Memory/Fee
    # ${PROJ_DIR}/HCM/BSW/Memory/MemIf
    # ${PROJ_DIR}/HCM/BSW/Memory/NvM
    # ${PROJ_DIR}/HCM/BSW/Memory/SchM
    # ${PROJ_DIR}/HCM/BSW/Crc
    # ${PROJ_DIR}/HCM/BSW/E2E
)
set(priIncludes
)

add_library(HCM_AIR_MD1 STATIC ${sources})

target_include_directories(HCM_AIR_MD1 PUBLIC ${includes})


target_include_directories(HCM_AIR_MD1 PRIVATE ${priIncludes})
configcore(HCM_AIR_MD1 ${CMAKE_SOURCE_DIR})


# target_sources(${project_elf} PRIVATE ..)
# 递归搜索所有头文件目录
file(GLOB_RECURSE header_dirs "BSW/*.h")
# 提取头文件所在的目录
set(unique_dirs "")
foreach(header ${header_dirs})
    get_filename_component(dir_path ${header} DIRECTORY)
    list(APPEND unique_dirs ${dir_path})
endforeach()
# 去重并添加为包含目录
list(REMOVE_DUPLICATES unique_dirs)
# 显示找到的头文件目录（调试用）
list(LENGTH unique_dirs dir_count)
message(STATUS "找到 ${dir_count} 个头文件目录")
foreach(include_dir ${unique_dirs})
    target_include_directories(HCM_AIR_MD1 PRIVATE ${include_dir})
    # 显示每个添加的包含目录（调试用，可选）
    # message(STATUS "添加包含目录: ${include_dir}")
endforeach()


target_compile_definitions(HCM_AIR_MD1 PUBLIC
    YTM32B1MD1
    CPU_YTM32B1MD1
)
target_compile_options(HCM_AIR_MD1 PUBLIC
    -fdiagnostics-color=always
)



target_link_libraries(HCM_AIR_MD1
    GENERATED_CONFIG_TARGET
    GENERATED_SDK_TARGET
)
