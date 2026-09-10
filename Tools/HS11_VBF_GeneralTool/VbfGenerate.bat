@echo off
setlocal enabledelayedexpansion
:: 设置源文件和目标路径
set "source_file_app=.\output_app\bin\Hex\HCM_APP.hex"
set "source_file_par=.\output_app\bin\Hex\HCM_PT.hex"
set "dest_dir_left_app=..\Tools\HS11_VBF_GeneralTool\Left\0APPHexfile\"
set "dest_dir_left_par=..\Tools\HS11_VBF_GeneralTool\Left\0DATAHexfile\"
set "bat_path_left=..\Tools\HS11_VBF_GeneralTool\Left\"
set "dest_dir_right_app=..\Tools\HS11_VBF_GeneralTool\Right\0APPHexfile\"
set "dest_dir_right_par=..\Tools\HS11_VBF_GeneralTool\Right\0DATAHexfile\"
set "bat_path_right=..\Right\"
set "bat_app=converterAPP.bat"
set "bat_par=converterDATA.bat"

::TO号需要根据客户每次发的修改
set "APP_LEFT_VBF=6608602409C.vbf"
set "PAR_LEFT_VBF=6608602408A.vbf"
set "APP_RIGHT_VBF=6608602410C.vbf"
set "PAR_RIGHT_VBF=6608602407A.vbf"


:: 检查源文件是否存在
if not exist "%source_file_app%" (
    echo error：no %source_file_app% exist
    pause
    exit /b 1
)
:: 创建目标目录（如果不存在）
if not exist "%dest_dir_left_app%" (
    mkdir "%dest_dir_left_app%"
    if %errorlevel% neq 0 (
        echo 错误：无法创建目标目录 %dest_dir_left_app%
        pause
        exit /b 1
    )
)
:: 复制文件到目标目录
copy /y "%source_file_app%" "%dest_dir_left_app%" >nul
copy /y "%source_file_par%" "%dest_dir_left_par%" >nul
copy /y "%source_file_app%" "%dest_dir_right_app%" >nul
copy /y "%source_file_par%" "%dest_dir_right_par%" >nul
if %errorlevel% equ 0 (
    echo file has been copied into %dest_dir_left_app%
) else (
    echo error：copy failed
    pause
    exit /b 1
)
:: 执行左侧目标批处理文件
if exist "%bat_path_left%" (
	::进入/Left
	cd /d %bat_path_left%
	
	::执行生成app脚本
    echo running %bat_app%...
    call "%bat_app%"
    echo vbf Generate Success
	
	::拷贝到out中
	copy /y ".\VBFfile\HCM_APP_Comp.vbf" "..\OutPutVbfFiles\%APP_LEFT_VBF%"
	echo copy appVbf file into OutPutVbfFiles Success
	
	
	::执行生成par脚本
    echo running %bat_par%...
    call "%bat_par%"
    echo vbf Generate Success
	
		::拷贝到out中
	copy /y ".\VBFfile\HCM_PT_Comp.vbf" "..\OutPutVbfFiles\%PAR_LEFT_VBF%"
	echo copy parVbf file into OutPutVbfFiles Success
) else (
    echo error：no %bat_path_left% exist
    pause
    exit /b 1
)
    echo %cd%
:: 执行右侧目标批处理文件
if exist "%bat_path_right%" (
	::进入/Right
	cd /d %bat_path_right%
	
	::执行生成app脚本
    echo running %bat_app%...
    call "%bat_app%"
    echo vbf Generate Success
	
	::拷贝到out中
	copy /y ".\VBFfile\HCM_APP_Comp.vbf" "..\OutPutVbfFiles\%APP_RIGHT_VBF%"
	echo copy appVbf file into OutPutVbfFiles Success
	
	
	::执行生成par脚本
    echo running %bat_par%...
    call "%bat_par%"
    echo vbf Generate Success
	
	::拷贝到out中
	copy /y ".\VBFfile\HCM_PT_Comp.vbf" "..\OutPutVbfFiles\%PAR_RIGHT_VBF%"
	echo copy parVbf file into OutPutVbfFiles Success
) else (
    echo error：no %bat_path_right% exist
    pause
    exit /b 1
)



endlocal
pause