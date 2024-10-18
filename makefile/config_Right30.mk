# User shall update these variables according to specific environments
include sourcedir_Right30.mk
# The root path of plugins, it is beneath eclipse directory.
PLUGINS_DIR = ../BSW/Mcal

# The path to generated file directory for Tresos.
TRESOS_GENERATED_DIR = ../Generated

# The target file name of executable file.
TARGET_NAME = HCM_CDE

# Set the used derivative.
DERIVATIVE = Z20K148M

# Set the modules to be compiled.
MCAL_MODULE_LIST = McalLib Mcu Rte Port Dio Det Can Platform Wdg WdgIf EcuM Spi Dma Adc Gpt Fls Pwm Icu

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
          -hex=$(HEX_DIR_AND_NAME) \
          -paddr_offset=0
