include env.mk
include config_Left20.mk
include sourcedir_Left20.mk

# Set the output folder name
OUT_DIR := output_Left20
# Set the directory of object files
OBJ_DIR := $(OUT_DIR)/obj
# Set the directory of executable file
BIN_DIR := $(OUT_DIR)/bin



# Add required modules and tresos generated path to source directories
SRC_DIRS += $(foreach module,$(MCAL_MODULE_LIST),$(PLUGINS_DIR)/$(module)_$(MCAL_PACKAGE_NAME)/Src) \
            $(PLUGINS_DIR)/Platform_$(MCAL_PACKAGE_NAME)/Startup/Src \
            $(PLUGINS_DIR)/Platform_$(MCAL_PACKAGE_NAME)/Startup/Src/$(COMIPLER_TYPE) \
            $(TRESOS_GENERATED_DIR)/Src

# Add required modules and tresos generated path to include directories 
INC_DIRS := $(foreach INCDIR,$(INCLUDE_DIR),$(INCDIR)) \
            $(foreach module,$(MCAL_MODULE_LIST),$(PLUGINS_DIR)/$(module)_$(MCAL_PACKAGE_NAME)/Inc) \
            $(PLUGINS_DIR)/Base_$(MCAL_PACKAGE_NAME)/Inc \
            $(PLUGINS_DIR)/Base_$(MCAL_PACKAGE_NAME)/Inc/MemMap \
            $(PLUGINS_DIR)/McalLib_$(MCAL_PACKAGE_NAME)/Inc/Devices \
            $(PLUGINS_DIR)/Platform_$(MCAL_PACKAGE_NAME)/Startup/Inc \
            $(TRESOS_GENERATED_DIR)/Inc

# Set used linker file
LINKER_DEF := $(PLUGINS_DIR)/Platform_$(MCAL_PACKAGE_NAME)/LinkerScripts/$(COMIPLER_TYPE)/Linker_Flash_$(DERIVATIVE).ld

# Search source files from source directories, and remove directory-part
SOURCE_FILES := $(foreach DIR,$(SRC_DIRS),$(notdir $(wildcard $(DIR)/*.c))) \
                $(foreach DIR,$(SRC_DIRS),$(notdir $(wildcard $(DIR)/*.s)))

# Get object files from source files
OBJ_FILES := $(patsubst %.c,%.o,$(SOURCE_FILES))
OBJ_FILES := $(patsubst %.s,%.o,$(OBJ_FILES))

# Set compiler flag of include directores
INC_FLAG =$(addprefix -I, $(INC_DIRS))


# Build target executable file.
.PHONY: build
build: $(TARGET_NAME).elf

# Linker all the object files to executable file
$(TARGET_NAME).elf : $(OBJ_FILES)
	@echo "Linking $@"
	@$(LD) $(LD_OPT) -T $(LINKER_DEF) $(OBJ_DIR)/*.o -o $(BIN_DIR)/$@
#	@$(LD) $(LD_OPT) -T $(LINKER_DEF) $(OBJ_DIR)/*.o -o $(BIN_DIR)/$@ -L$(LIB_PATH) -l$(LIB_NAME)
	@$(HEX) $(PARAM_TABLE_HEX_FILE) /FR:0x78000-0x78FFF /XI:32 /FP:0xFF /s -o $(PARAM_TABLE_HEX_FILE)
	@$(HEX) $(HEX_BOOT_FILE) /FR:0x00000-0x27FFF /XI:32 /FP:0xFF /s -o $(HEX_BOOT_FILE)
	@$(HEX) $(HEX_DIR_AND_NAME) /FR:0x38000-0x4BFFF:0x78000-0x78FFF /FP:0xFF /XI:32 /s -o $(HEX_DIR_AND_NAME)
	@$(HEX) /MT:$(HEX_DIR_AND_NAME)+$(HEX_BOOT_FILE) /XI:32 /s -o $(HEX_MERGE_DIR)
vpath %.c $(SRC_DIRS)
vpath %.o $(OBJ_DIR)
# Compiler all the c files
%.o: %.c | create_output_dir
	@echo "Compiling $<"
	@$(CC) $(CC_OPT) -c -o $(OBJ_DIR)/$@ $< $(INC_FLAG)

vpath %.s $(SRC_DIRS)
vpath %.o $(OBJ_DIR)
# Compiler all the assembler files
%.o : %.s
	@echo "Compiling $<"
	@$(AS) $(AS_OPT) -c -o $(OBJ_DIR)/$@ $<

# Create output folder
.PHONY: create_output_dir
create_output_dir:
	-@mkdir $(OUT_DIR)

# Remove output folder
.PHONY: clean
clean:
	@rm -rf $(OUT_DIR)
