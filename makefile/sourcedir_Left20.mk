
# Set include path
INCLUDE_DIR := 	../Main \
				../ASW/Include \
				../ASW/ASW_Manager \
				../ASW/BasicLighting \
				../ASW/BasicLighting/FrontCrossLamp \
				../ASW/DCMotor \
				../ASW/Fan \
				../ASW/HSDManage \
				../ASW/Lighting \
				../ASW/Lighting/LBHB \
				../ASW/Lighting/TurnIndicator \
				../ASW/Lighting/DRLPos \
        		../ASW/LowBeam \
				../ASW/ASW_INTERFACE/ADC_Interface \
				../ASW/ASW_INTERFACE/Base \
				../ASW/ASW_INTERFACE/BSW_Interface \
				../ASW/ASW_INTERFACE/Channel_Interface \
				../ASW/ASW_INTERFACE/Derate_Interface \
				../ASW/ASW_INTERFACE/HighSide_Interface \
				../ASW/ASW_INTERFACE/NtcRcod_Interface \
				../ASW/ASW_INTERFACE/Parameter_Interface \
				../ASW/ASW_INTERFACE/PowerSupply_Interface \
				../ASW/ASW_INTERFACE/PulseGenerator_Interface \
				../ASW/ASW_INTERFACE/LRDirection_Interface \
				../ASW/ASW_INTERFACE/SystemService_Interface \
				../BSW/Config/Mcal_Config/Inc \
				../BSW/Config/BSW_Config \
				../BSW/Diagnostic/Dcm \
				../BSW/Diagnostic/LinTp \
				../BSW/Communication/LinIf \
				../BSW/Communication/LinSM \
				../BSW/Communication/Com \
				../CDD/CDD_Driver/AdcDrv \
				../CDD/CDD_Driver/BuckDrv \
				../CDD/CDD_Driver/CDD_Driver_Manager \
				../CDD/CDD_Driver/HighSideDrv \
				../CDD/CDD_Driver/Uart_Drv \
				../CDD/CDD_Driver/Wdg_Drv \
				../CDD/CDD_Driver/Smpu_Drv \
				../CDD/CDD_OS	\
				../CDD/Parameter \
				../CDD/Safety/ \
				../CDD/Safety/Inc \
				../CDD/Safety/Cortex_M4_STL/Inc \
				../CDD/Safety/Cortex_M4_STL/Inc/ARM.CMSIS.5.3.0\CMSIS/Include \
				../CDD/TestExample/Lin/Inc \
				../CDD/TestExample/SleepWakeup/Inc
# Add Application sourcefile dir
SRC_DIRS := ../Main \
			../ASW/src	\
			../ASW/ASW_Manager \
			../ASW/BasicLighting \
			../ASW/BasicLighting/FrontCrossLamp \
			../ASW/Lighting \
			../ASW/Lighting/LBHB \
			../ASW/Lighting/TurnIndicator \
			../ASW/Lighting/DRLPos \
			../ASW/Fan \
			../ASW/DCMotor \
			../ASW/HSDManage \
			../ASW/LowBeam \
			../ASW/ASW_INTERFACE/ADC_Interface \
			../ASW/ASW_INTERFACE/ASW_Interface_Manager \
			../ASW/ASW_INTERFACE/Base \
			../ASW/ASW_INTERFACE/BSW_Interface \
			../ASW/ASW_INTERFACE/Channel_Interface \
			../ASW/ASW_INTERFACE/Derate_Interface \
			../ASW/ASW_INTERFACE/HighSide_Interface \
			../ASW/ASW_INTERFACE/NtcRcod_Interface \
			../ASW/ASW_INTERFACE/Parameter_Interface \
			../ASW/ASW_INTERFACE/PowerSupply_Interface \
			../ASW/ASW_INTERFACE/PulseGenerator_Interface \
			../ASW/ASW_INTERFACE/LRDirection_Interface \
			../ASW/ASW_INTERFACE/SystemService_Interface \
			../BSW/Config/Mcal_Config/Src \
			../BSW/Config/BSW_Config \
			../BSW/Diagnostic/Dcm \
			../BSW/Diagnostic/LinTp \
			../BSW/Communication/LinIf \
			../BSW/Communication/LinSM \
			../BSW/Communication/Com \
			../CDD/CDD_Driver/AdcDrv \
			../CDD/CDD_Driver/BuckDrv \
			../CDD/CDD_Driver/CDD_Driver_Manager \
			../CDD/CDD_Driver/HighSideDrv \
			../CDD/CDD_Driver/Uart_Drv \
			../CDD/CDD_Driver/Wdg_Drv \
			../CDD/CDD_Driver/Smpu_Drv \
			../CDD/CDD_OS	\
			../CDD/Parameter/0000_Default \
			../CDD/TestExample/Lin/Src \
			../CDD/TestExample/SleepWakeup/Src
HEX_DIR_AND_NAME = output_Left20/bin/HCM_Left.hex
# Boot HEX path
HEX_BOOT_FILE =	../Boot/Left/Geely3_Z20K144M_LIN_PBL.hex
# Merge App and BOOT with filled value '0xFF'
HEX_MERGE_DIR =	$(BIN_DIR)/P177_AIR_MergedAndFilled.hex


