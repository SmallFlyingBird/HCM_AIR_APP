# 
include config.mk





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
$(TARGET_NAME).elf : paramgr $(OBJ_FILES)
	@echo "Linking $@"
	@$(LD) $(LD_OPT) -T $(LINKER_DEF) $(OBJ_DIR)/*.o -o $(BIN_DIR)/$@ -L$(LIB_PATH) -l$(LIB_NAME)

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

# Remove all output folder
.PHONY: cleanall
cleanall:
	@rm -rf $(OUT_DIR_ALL)

# ParaMgr.c
.PHONY: paramgr
paramgr:
ifeq ($(BUILD_PARAMGR), )
	@echo "don't update ParaMgr.c"
else
	@cp -f ../Base/Parameter/store/$(BUILD_PROJECT)/$(BUILD_PARAMGR).c ../Base/Parameter/0000_Default/ParaMgr.c
	@echo "ParaMgr.c Updated."
endif
