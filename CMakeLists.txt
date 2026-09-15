cmake_minimum_required(VERSION 3.16)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# cmake -DCMAKE_PREFIX_PATH="C:\\ghs\\comp_202214" -DCMAKE_TOOLCHAIN_FILE="../cmake/ghs.cmake" -DARM_CPU="cortexm33" -G "Ninja" ..


project(HCM_AIR)

# USER CODE BEGIN start

set(HCM_AIR_RELEASE ON) # if Debug should set to OFF; if Release should set to ON and remmber change TO!!!!!!!!!!!!!!!!!!!!!!
# USER CODE END start

set(PROJ_DIR ${CMAKE_SOURCE_DIR})
set(SDK_VER 2_3_0)
set(SDK_DIR C:/Users/zhangyicheng/AppData/Roaming/yt_config_tool/mcal/YTM32B1MD1_2_3_0)

include(${CMAKE_SOURCE_DIR}/cmake/config.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/targets/GENERATED_CONFIG_TARGET.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/targets/GENERATED_SDK_TARGET.cmake)
include(${CMAKE_SOURCE_DIR}/HCM/cmake/HCM_AIR_MD1.cmake)
# USER CODE BEGIN include
# include(...)
# USER CODE END include

set(project_elf HCM_AIR.elf)
add_executable(${project_elf} app/main.c)
#add app as include path
target_include_directories(${project_elf} PRIVATE app)
#add all source files in app folder 
file(GLOB dir_sources "app/*.c" "app/*.cpp" "app/*.S")
if(dir_sources)
    foreach(src ${dir_sources})
        target_sources(${project_elf} PRIVATE ${src})
    endforeach()
endif()

# USER CODE BEGIN add_executable
# target_include_directories()
# target_sources(${project_elf} PRIVATE ..)
# USER CODE END add_executable
# target_sources(${project_elf} PRIVATE ..)
# 递归搜索所有头文件目录
file(GLOB_RECURSE header_dirs "BSW/*.h")
# 提取头文件所在的目录
set(unique_dirs "")
foreach(header ${header_dirs})
    get_filename_component(dir_path ${header} DIRECTORY)
    list(APPEND unique_dirs ${dir_path})
endforeach()


configcore(${project_elf} ${CMAKE_SOURCE_DIR})


# USER CODE BEGIN target_compile_definitions
# target_compile_definitions(...)
# USER CODE END target_compile_definitions

target_compile_definitions(${project_elf} PUBLIC
    "YTM32B1MD1"
    "CPU_YTM32B1MD1"
)

# USER CODE BEGIN target_compile_options
# target_compile_options(...)
# USER CODE END target_compile_options


target_link_libraries(${project_elf} "-Wl,--whole-archive" GENERATED_CONFIG_TARGET GENERATED_SDK_TARGET  "-Wl,--no-whole-archive")
target_link_libraries(${project_elf} "-Wl,--whole-archive" HCM_AIR_MD1 "-Wl,--no-whole-archive")
# USER CODE BEGIN target_link_libraries
# target_link_libraries(...)
# USER CODE END target_link_libraries


if (CORTEXM)
    compilerSpecificPlatformConfigAppForM(${project_elf} ${CMAKE_SOURCE_DIR} )
elseif(CORTEXA)
    compilerSpecificPlatformConfigAppForA(${project_elf} ${CMAKE_SOURCE_DIR} )
else()
    compilerSpecificPlatformConfigAppForR(${project_elf} ${CMAKE_SOURCE_DIR} )
endif()

target_link_libraries(${project_elf} "-e Reset_Handler;-map=HCM_AIR.map;-T ../board/yt_linker.ld;-paddr_offset=0")
find_program(CMAKE_GSREC gsrec)
if(CMAKE_GSREC)
add_custom_target(gens19
    DEPENDS ${project_elf} 
    COMMAND ${CMAKE_GSREC} ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.elf -o ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.s19
)
add_custom_target(genhex
    DEPENDS ${project_elf} 
    COMMAND ${CMAKE_GSREC} -hex386 ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.elf -o ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.hex
)
add_custom_command(
    TARGET ${project_elf} POST_BUILD
    COMMAND ${CMAKE_GSREC} -hex386 ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.elf -o ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.hex
)
endif()
find_program(CMAKE_GMEM gmemfile)
if(CMAKE_GMEM)
add_custom_target(genbin
    DEPENDS ${project_elf} 
    COMMAND ${CMAKE_GMEM} ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.elf -o ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.bin
)
endif()
find_program(CMAKE_GDUMP gdump)
if(CMAKE_GDUMP)
add_custom_target(genlist
    DEPENDS ${project_elf} 
    COMMAND ${CMAKE_GDUMP} -full ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.elf > ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.lst
)
endif()

if(${HCM_AIR_RELEASE})
# Create OutputHex directory if it doesn't exist
file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/OutputHex")
# HexView tool configuration for merging BOOT hex file
set(HEXVIEW_TOOL "E:/APP/HexView/hexview.exe")
set(BOOT_HEX_FILE "${CMAKE_SOURCE_DIR}/BOOT/HCM_AIR_FBL.hex")
set(APP_HEX_FILE "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.hex")
set(BOOT_FILLED_HEX "${CMAKE_CURRENT_BINARY_DIR}/OutputHex/boot_filled.hex")
set(APP_FILLED_HEX "${CMAKE_CURRENT_BINARY_DIR}/OutputHex/app_filled.hex")
set(APP_FINAL_HEX "${CMAKE_CURRENT_BINARY_DIR}/OutputHex/app_final.hex")
set(HCM_PT_HEX "${CMAKE_CURRENT_BINARY_DIR}/OutputHex/HCM_PT.hex")
set(HCM_APP_HEX "${CMAKE_CURRENT_BINARY_DIR}/OutputHex/HCM_APP.hex")
set(MERGED_HEX_FILE "${CMAKE_CURRENT_BINARY_DIR}/OutputHex/${CMAKE_PROJECT_NAME}_merged.hex")



# Mark hex file as generated output for dependency tracking
set_source_files_properties(${APP_HEX_FILE} PROPERTIES GENERATED TRUE)

# Add POST_BUILD commands to generate hex, pad regions, extract sub-hex files and merge with boot hex
add_custom_command(
    TARGET ${project_elf} POST_BUILD
    # 1. Generate app hex from elf
    COMMAND ${CMAKE_GSREC} -hex386 ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.elf -o ${APP_HEX_FILE}
    # 2. Fill BOOT hex up to 0x27FFF with 0xFF
    COMMAND "${HEXVIEW_TOOL}" ${BOOT_HEX_FILE} /FR:0-0x27FFF /XI:32 /FP:0xFF -s -o ${BOOT_FILLED_HEX}
    # 3. Fill app code regions 0x38000-0x5AFF0 and 0x78000-0x78FFF with 0xFF
    COMMAND "${HEXVIEW_TOOL}" ${APP_HEX_FILE} /FR:0x38000-0x5AFEF /XI:32 /FP:0xFF -s -o ${APP_HEX_FILE}
    
    COMMAND "${HEXVIEW_TOOL}" ${APP_HEX_FILE} /FR:0x5AFF0-0x5AFFF /FP:00078142000781430108FFFFFFFFFFFF /XI:32 -s -o ${APP_FILLED_HEX}
    
    COMMAND "${HEXVIEW_TOOL}" ${APP_FILLED_HEX} /FR:0x78000-0x78FFF /XI:32 /FP:0xFF -s -o ${APP_FILLED_HEX}
    # 4. Extract 0x78000-0x78FFF as HCM_PT.hex
    COMMAND "${HEXVIEW_TOOL}" ${APP_FILLED_HEX} /CR:0x38000-0x5AFFF /XI:32 -s -o ${HCM_PT_HEX}
    # 5.Fill 0x5AFF0-0x5AFFF with specific pattern  ;
    
    # 6.Extract 0x38000-0x5AFFF as HCM_APP.hex
    COMMAND "${HEXVIEW_TOOL}" ${APP_FILLED_HEX} /CR:0x78000-0x78FFF /XI:32 -s -o ${HCM_APP_HEX}
    
    
    # 7. Merge padded boot and final app hex
    COMMAND "${HEXVIEW_TOOL}" /MT:${BOOT_FILLED_HEX}+${HCM_APP_HEX}+${HCM_PT_HEX}  /XI:32 -s -o "${MERGED_HEX_FILE}"
    COMMENT "Generating HEX files with padding, extraction and merging"
)

# run VBF Tool to convert hex file to VBF file
# ---- 工具根目录 ----
set(VBF_TOOL_ROOT "${CMAKE_SOURCE_DIR}/Tools/HS11_VBF_GeneralTool")
set(LEFT_DIR      "${VBF_TOOL_ROOT}/Left")
set(RIGHT_DIR     "${VBF_TOOL_ROOT}/Right")
set(OUTPUT_VBF_DIR "${VBF_TOOL_ROOT}/OutPutVbfFiles")

# ---- 源 hex 文件 ----
set(SOURCE_FILE_APP "${CMAKE_CURRENT_BINARY_DIR}/OutputHex/HCM_APP.hex")
set(SOURCE_FILE_PAR "${CMAKE_CURRENT_BINARY_DIR}/OutputHex/HCM_PT.hex")

# ---- 目标子目录 ----
set(LEFT_APP_DEST  "${LEFT_DIR}/0APPHexfile")
set(LEFT_PAR_DEST  "${LEFT_DIR}/0DATAHexfile")
set(RIGHT_APP_DEST "${RIGHT_DIR}/0APPHexfile")
set(RIGHT_PAR_DEST "${RIGHT_DIR}/0DATAHexfile")

# ---- 输出 VBF 文件名（TO 号，客户每次更新需修改这里）----
###################################################
set(APP_LEFT_VBF  "6608602409C.vbf")###############
set(PAR_LEFT_VBF  "6608602408A.vbf")###############
set(APP_RIGHT_VBF "6608602410C.vbf")###############
set(PAR_RIGHT_VBF "6608602407A.vbf")###############
###################################################

# ---- 配置阶段创建目录（避免 bat 因目录不存在而失败）----
file(MAKE_DIRECTORY "${LEFT_APP_DEST}")
file(MAKE_DIRECTORY "${LEFT_PAR_DEST}")
file(MAKE_DIRECTORY "${RIGHT_APP_DEST}")
file(MAKE_DIRECTORY "${RIGHT_PAR_DEST}")
file(MAKE_DIRECTORY "${OUTPUT_VBF_DIR}")

# ============================================================
# 自定义目标：generate_vbf
# ============================================================
add_custom_target(generate_vbf ALL
    # --- 1. 复制 hex 到左右两侧目标目录 ---
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${SOURCE_FILE_APP}" "${LEFT_APP_DEST}/HCM_APP.hex"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${SOURCE_FILE_PAR}" "${LEFT_PAR_DEST}/HCM_PT.hex"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${SOURCE_FILE_APP}" "${RIGHT_APP_DEST}/HCM_APP.hex"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${SOURCE_FILE_PAR}" "${RIGHT_PAR_DEST}/HCM_PT.hex"

    # --- 2. 左侧：调 converterAPP.bat，生成 APP VBF ---
    COMMAND cd ${LEFT_DIR} && call converterAPP.bat
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${LEFT_DIR}/VBFfile/HCM_APP_Comp.vbf"
            "${OUTPUT_VBF_DIR}/${APP_LEFT_VBF}"

    # --- 3. 左侧：调 converterDATA.bat，生成 PAR VBF ---
    COMMAND cd ${LEFT_DIR} && call converterDATA.bat
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${LEFT_DIR}/VBFfile/HCM_PT_Comp.vbf"
            "${OUTPUT_VBF_DIR}/${PAR_LEFT_VBF}"

    # --- 4. 右侧：调 converterAPP.bat，生成 APP VBF ---
    COMMAND cd ${RIGHT_DIR} && call converterAPP.bat
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${RIGHT_DIR}/VBFfile/HCM_APP_Comp.vbf"
            "${OUTPUT_VBF_DIR}/${APP_RIGHT_VBF}"

    # --- 5. 右侧：调 converterDATA.bat，生成 PAR VBF ---
    COMMAND cd ${RIGHT_DIR} && call converterDATA.bat
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${RIGHT_DIR}/VBFfile/HCM_PT_Comp.vbf"
            "${OUTPUT_VBF_DIR}/${PAR_RIGHT_VBF}"

    # DEPENDS "${SOURCE_FILE_APP}" "${SOURCE_FILE_PAR}"
    COMMENT "Generating VBF files (left/right APP & DATA) ..."
    VERBATIM
)
add_dependencies(generate_vbf ${project_elf})
endif()


# ozone target 
if (CMAKE_HOST_WIN32)
    set(OZONE_PATHS 
        "$ENV{PROGRAMFILES}/SEGGER/Ozone"
        "$ENV{PROGRAMFILES\(X86\)}/SEGGER/Ozone"
    )
    if(EXISTS "D:/")
        # 如果D盘存在,将其添加到搜索路径中
        list(APPEND OZONE_PATHS 
            "D:/Program Files/SEGGER/Ozone"
            "D:/Program Files (x86)/SEGGER/Ozone"
        )
    endif()
    list(APPEND OZONE_PATHS ".")
endif()
find_program(OZONE_EXECUTABLE 
    NAMES Ozone
    PATHS ${OZONE_PATHS}
)
if(OZONE_EXECUTABLE)
add_custom_target(Ozone
    DEPENDS ${project_elf} 
    COMMAND ${CMAKE_SOURCE_DIR}/.scripts/ozone ${OZONE_EXECUTABLE} ${CMAKE_SOURCE_DIR}/${CMAKE_PROJECT_NAME}.jdebug
)
else()
message(WARNING "Ozone not found, additional search paths: ${OZONE_PATHS}")
endif()


# yct file as depend
file(GLOB yct_files "${CMAKE_SOURCE_DIR}/*.yct")
if(yct_files)
    list(APPEND CMAKE_CONFIGURE_DEPENDS ${yct_files})
endif()

# USER CODE BEGIN others

# USER CODE END others