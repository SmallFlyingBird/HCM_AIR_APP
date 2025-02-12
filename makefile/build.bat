@echo off
Set path=%path%;D:\Install\Hexview
Set MrgedFilePath= .\output_%1\bin\P177_AIR_MergedAndFilled.hex
Set ParaTablePath= ..\CDD\Parameter\HEX\Air_Parameter.hex
make -f makefile %1 
if exist %ParaTablePath% start /b hexview %ParaTablePath% /cs14:@0x78FFE;0x78000-0x78FFD /s /XI:32 -o %FilePath%
if exist %MrgedFilePath% start /b hexview %MrgedFilePath% /cs14:@0x4BFFE;0x38000-0x78FFF /s /XI:32 -o %FilePath%


