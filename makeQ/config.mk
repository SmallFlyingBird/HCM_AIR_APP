include env.mk

################################################################################
# Build Customer (auto Set)
#   0: SMART
#   1: GEELY
#
################################################################################
# Build BaseTech (auto Set)
#   0: Base Tech 2.0
#   1: Base Tech 3.0
#
################################################################################
#Build DMoni on CAN (may auto Set)
#     1:     use DMoni on CAN
# not 1: not use DMoni on CAN
#
# when BUILD_PROJECT = EPT, auto Set BUILD_DMONI_CAN = 1
#
################################################################################
ifeq      ($(BUILD_PROJECT), EPT)
BUILD_PROJECT_ID := 1
BUILD_CUSTOMER   := 0
BUILD_BASETECH   := 0
BUILD_DMONI_CAN  := 1
else ifeq ($(BUILD_PROJECT), G636)
BUILD_PROJECT_ID := 2
BUILD_CUSTOMER   := 1
BUILD_BASETECH   := 0
BUILD_DMONI_CAN  := 0
else ifeq ($(BUILD_PROJECT), HS11)
BUILD_PROJECT_ID := 3
BUILD_CUSTOMER   := 0
BUILD_BASETECH   := 0
BUILD_DMONI_CAN  := 0
else ifeq ($(BUILD_PROJECT), FX11)
BUILD_PROJECT_ID := 4
BUILD_CUSTOMER   := 1
BUILD_BASETECH   := 1
BUILD_DMONI_CAN  := 0
else
BUILD_PROJECT_ID := 0
BUILD_CUSTOMER   := 0
BUILD_BASETECH   := 0
BUILD_DMONI_CAN  := 0
endif


# Set Build Output Directory. 
# {

# Set the output project name
OUT_PRJ_NAME := $(BUILD_PROJECT)_$(BUILD_PARAMGR)

# Set CUSTOMER name
ifeq ($(BUILD_CUSTOMER), 0)
OUT_CUS_NAME := SMART
else ifeq ($(BUILD_CUSTOMER), 1)
OUT_CUS_NAME := GEELY
else
OUT_CUS_NAME := 
endif

# Set BT name
ifeq ($(BUILD_BASETECH), 0)
OUT_BT_NAME := BT20
else ifeq ($(BUILD_BASETECH), 1)
OUT_BT_NAME := BT30
else
OUT_BT_NAME := 
endif

# Set the output Left/Right name
ifeq ($(BUILD_LE0RI), 0)
OUT_LR_NAME := Le
else
OUT_LR_NAME := Ri
endif

# Set the output folder name
OUT_DIR := output_$(OUT_CUS_NAME)_$(OUT_PRJ_NAME)_$(OUT_BT_NAME)_$(OUT_LR_NAME)
OUT_DIR_ALL := output_*
# Set the directory of object files
OBJ_DIR := $(OUT_DIR)/obj
# Set the directory of executable file
BIN_DIR := $(OUT_DIR)/bin

# }

# Set Build Module
# {

# Which ParaMgr.c ?
SRC_PARAMGR_DIR = ../Base/Parameter/0000_Default

# What Base Tech 2.0/3.0
ifeq ($(BUILD_BASETECH), 0)
    BSWConfig := /BSW_Config_2.0
else ifeq ($(BUILD_BASETECH), 1)
    BSWConfig := /BSW_Config_3.0
endif

# User shall update these variables according to specific environments
ifeq ($(BUILD_LE0RI), 0)
    include sourcedir_Left.mk
    LR_NAME := Left
else
    include sourcedir_Right.mk
    LR_NAME := Right
endif

# }

# The root path of plugins, it is beneath eclipse directory.
PLUGINS_DIR = ../BSW/Mcal

# The path to generated file directory for Tresos.
TRESOS_GENERATED_DIR = ../Generated

# The target file name of executable file.
TARGET_NAME = App_$(LR_NAME)

# Set the used derivative.
DERIVATIVE = Z20K148M

# Set Lib
LIB_PATH = ../BSW/Mcal/Mstp_ZX_K14xM/Library/Ghs
LIB_NAME = Mstp.a

# Set the modules to be compiled.
MCAL_MODULE_LIST = McalLib Mcu Rte Port Dio Det Can Platform Wdg WdgIf EcuM Spi Dma Adc Gpt Fls Pwm Icu Crypto CryptoIf Csm Cmu Meh Mstp HTMSS Mpu

# Set package name of modules, the varialbe shall not be modified.
MCAL_PACKAGE_NAME = ZX_K14xM

# Set the compiler type. Since ghs is only supported compiler now, the varialbe shall not be modified.
COMIPLER_TYPE = Ghs

# Set the Compolier, Linker and Assembler.
CC := $(GHS_DIR)/ccthumb.exe
LD := $(GHS_DIR)/ccthumb.exe
AS := $(GHS_DIR)/ccthumb.exe

# Set the Compolier options.
CC_OPT := -cpu=cortexm4f \
          -G \
          -dual_debug \
          -thumb \
          -thumb_lib \
          -Wtrigraphs \
          --gnu_asm \
          --no_commons \
          -Wshadow \
          --no_exceptions \
          -Wundef \
          -Wimplicit-int \
          --prototype_errors \
          -keeptempfiles \
          --incorrect_pragma_warnings \
          -DBUILD_BASETECH=$(BUILD_BASETECH)\
          -DBUILD_CUSTOMER=$(BUILD_CUSTOMER)\
          -DBUILD_LE0RI=$(BUILD_LE0RI) \
          -DBUILD_PROJECT=$(BUILD_PROJECT) \
          -DBUILD_PROJECT_ID=$(BUILD_PROJECT_ID) \
          -DBUILD_DMONI_CAN=$(BUILD_DMONI_CAN)

# Set the Assembler options.
AS_OPT := -cpu=cortexm4f \
          -preprocess_assembly_files \
          -list

# Set the Linker options.
LD_OPT := -cpu=cortexm4f \
          -Mn \
          -ignore_debug_references \
          -map \
          -keepmap \
          -delete \
          -nostartfile \
          -e Reset_Handler \
          -locatedprogram \
          -hex=$(BIN_DIR)/$(TARGET_NAME).hex \
          -paddr_offset=0
