

# Source Path

# CanIf
ifeq ($(BUILD_DMONI_CAN), 1)
SRC_CanIf := ../makeQ/Special/BUILD_DMONI_CAN/BSW/Communication/CanIf
else
SRC_CanIf := ../BSW/Communication/CAN/CanIf
endif
