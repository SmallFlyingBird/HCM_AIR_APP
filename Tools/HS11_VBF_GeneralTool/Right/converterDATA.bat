@echo off

setlocal enabledelayedexpansion

rem Configure the key file for signature
SET SIGNATURE_PRIV=Private_key_Req_1609_rev_5.xml
SET SIGNATURE_TEST=test_prod_signature_priv.xml

rem Configure PATHS
rem Directory where hexfile is located
SET HEX_PATH=.\0DATAHexfile\
rem Directory to store generated batch files
SET VBB_PATH=.\Batchfile\
rem Directory to store generated vbf files
SET VBF_PATH=.\VBFfile\
rem Directory to store signed vbf files
SET OUTPUT_PATH=.\out\

rem Configure VBF converter params
rem (Optional) What VBF Version to create, i.e. 2,0 2.1, 2.2, 2.3 or 2.4
SET VBF_Version=2.5
rem (Required) A hexadecimal value indicating the ECU node address.
SET ECUaddr=1B2B
rem (Required) A software type name
SET SwType=DATA
rem (Required for VBF2.2 or earlier, VBF2.5) A string specifying a software part number. In VBF 2.5 is an unquoted string of length 20 that contains only numbers.
SET SwPartNum=6608561506
rem (Required for VBF2.5) The SW version field indicates the vehicle manufacturer version for identification of the software component (VBF File). Unquoted string of 4 uppercase characters.
SET SwVersion=C
rem (Optional) A hexadecimal address indicating the start address to an executable function in ECU memory.
SET addrCall=
rem (Required VBF2.6) Specifies the Verification block table start address. Example: VerificationBlockStartAddr=FFFFEEEE need pad 8 Byte
SET VerificationBlockStartAddr=001E4000
rem (Optional) Start address of flash memory to erase. In hex. (example  C0000000  ). Must have a following EraseLength after each EraseStart. There can be several EraseStart / EraseLength pairs. For multiple addresses, use ; to connect them.
SET EraseStart=0078000
rem (Optional) Length of flash memory to erase. In hex (example: 00000100 ). Must have an EraseStart before each EraseLength There can be several EraseStart / EraseLength pairs. For multiple lengths, use ; to connect them.
SET EraseLength=00007FFF 

SET ifDelete=0
rem (Optional) A path to a text file containing checksum information for support of the Software Security concept.
SET CsumFile=

rem (Optional) Address of sub network  (VBF 2.2 and higher)
SET SubNetworkAddress=
rem (Optional) A hexadecimal value indicating the ECU address for a slave node.
SET ECUaddrSlave=
rem (Required for VBF2.1) Indicates if standard frame format or extended frame format shall used.
SET can_frame_format=
rem (Required for VBF2.2 or later) Indicates what frame format to use (currently support for CAN_STANDARD or CAN_EXTENDED)
SET frame_format=
rem (Required) A network name indicating the main network.
SET Network=
rem (Optional) A sub network name
SET NetworkSub=



rem (Required for VBF2.3 or later) A string specifying a WERS software part number. At least one of SwPartNumberWERS and SwPartNumberKDP must be present when VBFVersion is 2.3 or later.
SET SwPartNumberWERS=
rem (Required for VBF2.3 or later) A string specifying a KDP software part number. At least one of SwPartNumberWERS and SwPartNumberKDP must be present when VBFVersion is 2.3 or later.
SET SwPartNumberKDP=

rem (Optional) This function sorts the blocks in a VBF. The blocks are sorted after their start address in an ascending order. Example: Sort=1
SET Sort=1
rem (Optional) This function will group blocks that have adjacent data areas. Example: Group=1
SET Group=1
rem (Required VBF2.6) Specifies if the VBF file should be created with verification block table then CreateVerificationBlock(1) or not (0). Example: CreateVerificationBlock=1
SET CreateVerificationBlock=1
rem (Optional VBF2.6) Specifies if users wants to create VBF file when Verification block overlaps with other data block. CreateVerificationBlock(1) or not (0). Example: CreateVerificationOverlapBlock=1
SET CreateVerificationOverlapBlock=

rem (Optional) A free text comment string. There can be several comment parameter/value pairs. For multiple rows, use ; to connect them.
SET Comments=This is an Example of VBF generation batch.;Programed by:;HCJ;2022.7.8


rem (Optional for VBF2.3 or later) Start address of flash memory to omit. In hex. (example  C0000000  ). Must have a following OmitLength after each OmitStart. There can be several OmitStart / OmitLength pairs. For multiple addresses, use ; to connect them.
SET OmitStart=
rem (Optional) Length of flash memory to erase. In hex (example: 00000100 ). Must have an EraseStart before each EraseLength There can be several EraseStart / EraseLength pairs. For multiple lengths, use ; to connect them.
SET OmitLength=
rem (Optional) This function will align the VBF blocks before the VBF is stored on file.Example: Align=1. Must be followed by AlignBlockSize and AlignFillData.
SET Align=
rem (Optional) Size to align. In hex without any preceeding 0x or similar. Example: AlignBlockSize=11FF. 
SET AlignBlockSize=
rem (Optional) One byte of data to use for align fill. In hex without any preceeding 0x or similar. Example: AlignFillData=FF.
SET AlignFillData=


rem !!!!!!!!!!!!!!!!!!!!!!!!! DO NOT EDIT !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
SET VBFCONVERT=.\VBFConverter\VBFConvert.exe
SET SPACE=
echo CLEANING LEGACY FILES...
del /f /s /q !VBB_PATH!
del /f /s /q !VBF_PATH!
if !ifDelete!==1 (
   del /f /s /q !OUTPUT_PATH!
)
for /R %HEX_PATH% %%f in (*.hex) do (
   SET "FILENAME=%%~nxf"
   SET "FILENAME_NOEXT=%%~nf"
   SET TARGET_VBB=%VBB_PATH%!FILENAME_NOEXT!.VBB
   SET TARGET_VBB_COMPRESSED=%VBB_PATH%!FILENAME_NOEXT!_COMPRESSED.VBB
   echo FIND HEX FILE: !FILENAME!
   echo CHECKING PARAMS...
   rem PARAM CHECK
   if not defined ECUaddr (
      echo ParamERROR: ECUaddr MISSING!
      goto end
   )
   rem if not defined Network (
   rem    echo ParamERROR: Network MISSING!
   rem    goto end
   rem )
   if not defined SwType (
      echo ParamERROR: SwType MISSING!
      goto end
   )
   if defined Align (
      if not defined AlignBlockSize (
         echo ParamERROR: AlignBlockSize MISSING!
         goto end
      )
      if not defined AlignFillData (
         echo ParamERROR: AlignFillData MISSING!
         goto end
      )
   )
   if !SwType!==SBL (
      if defined EraseStart (
         echo ParamERROR: SBL but Erase configured!
         goto end
      )
      if defined EraseLength (
         echo ParamERROR: SBL but Erase configured!
         goto end
      )
   )
   if !SwType!==DATA (
      if defined addrCall (
         echo ParamERROR: DATA but Call configured!
         goto end
      )
   )
   if !SwType!==EXE (
   if defined addrCall (
      echo ParamERROR: EXE but Call configured!
      goto end
   )
   )
   rem if !VBF_Version!==2.1 (
   rem    if not defined can_frame_format (
   rem    echo ParamERROR: can_frame_format MISSING!
   rem    goto end
   rem    )
   rem )
   rem if !VBF_Version! LEQ 2.2 (
   rem    if not defined SwPartNum (
   rem       echo ParamERROR: SwPartNum MISSING!
   rem       goto end
   rem    )
   rem )
   if !VBF_Version! GEQ 2.2 (
      rem if not defined frame_format (
      rem echo ParamERROR: frame_format MISSING!
      rem goto end
      rem )
      if !VBF_Version! GEQ 2.3 (
         rem if not defined SwPartNumberKDP (
         rem    if not defined SwPartNumberWERS (
         rem    echo ParamERROR: SwPartNumberWERS or SwPartNumberKDP MISSING!
         rem    goto end
         rem    )
         rem )
         if !VBF_Version!==2.5 (
            if not defined SwVersion (
            echo ParamERROR: SwVersion MISSING!
            goto end
            )
            if not defined SwPartNum (
            echo ParamERROR: SwPartNum MISSING!
            goto end
            )
         )
         if !VBF_Version!==2.6 (
            if not defined CreateVerificationBlock (
            echo ParamERROR: CreateVerificationBlock MISSING!
            goto end
            )
            if not defined VerificationBlockStartAddr (
            echo ParamERROR: VerificationBlockStartAddr MISSING!
            goto end
            )
         )
      )
   )
   
   SET flagEraseStart=0
   SET flagEraseLength=0
   (for %%a in (%EraseStart%) do (  
      SET EraseStartAddr[!flagEraseStart!]=%%a
      SET /a "flagEraseStart+=1"
      ))
   SET /a "flagEraseStart-=1"
   (for %%a in (%EraseLength%) do (  
      SET EraseLengths[!flagEraseLength!]=%%a
      SET /a "flagEraseLength+=1"
      ))
   SET /a "flagEraseLength-=1"

   SET flagOmitStart=0
   SET flagOmitLength=0
   (for %%a in (%OmitStart%) do (  
      SET OmitStartAddr[!flagOmitStart!]=%%a
      SET /a "flagOmitStart+=1"
      ))
   SET /a "flagOmitStart-=1"
   (for %%a in (%OmitLength%) do (  
      SET OmitLengths[!flagOmitLength!]=%%a
      SET /a "flagOmitLength+=1"
      ))
   SET /a "flagOmitLength-=1"
   if not !flagEraseStart!==!flagEraseLength! (
   echo ParamERROR: EraseStart and EraseLength do not match in size!
   goto end
   )
   if not !flagOmitStart!==!flagOmitLength! (
      echo ParamERROR: OmitStart and OmitLength do not match in size!
      goto end
   )

   rem Generate Batch file
   echo GENERATING BATCHFILE: !TARGET_VBB!...
   cd.>!TARGET_VBB!
   echo ;>>!TARGET_VBB!
   echo ;!SPACE!!SPACE!!SPACE!!SPACE!VBF!SPACE!!VBF_Version!>>!TARGET_VBB!
   echo ;BATCHFILE="!TARGET_VBB!">>!TARGET_VBB!
   echo ;>>!TARGET_VBB!
   echo [VBF1]>>!TARGET_VBB!
   echo SourceFile=!HEX_PATH!!FILENAME!>>!TARGET_VBB!
   echo TargetFile=!VBF_PATH!!FILENAME_NOEXT!.vbf>>!TARGET_VBB!
   call:toVBB CsumFile,!CsumFile!
   call:toVBB VBFVersion,!VBF_Version!
   call:toVBB ECUaddr,!ECUaddr!
   call:toVBB SubNetworkAddress,!SubNetworkAddress!
   call:toVBB ECUaddrSlave,!ECUaddrSlave!
   call:toVBB can_frame_format,!can_frame_format!
   call:toVBB frame_format,!frame_format!
   call:toVBB Network,!Network!
   call:toVBB NetworkSub,!NetworkSub!
   call:toVBB SwType,!SwType!
   call:toVBB SwPartNum,!SwPartNum!
   call:toVBB SwVersion,!SwVersion!
   call:toVBB SwPartNumberWERS,!SwPartNumberWERS!
   call:toVBB SwPartNumberKDP,!SwPartNumberKDP!
   call:toVBB Sort,!Sort!
   call:toVBB Group,!Group!
   call:toVBB Align,!Align!
   call:toVBB AlignBlockSize,!AlignBlockSize!
   call:toVBB AlignFillData,!AlignFillData!
   call:toVBB Compressed,0
   call:toVBB CreateVerificationBlock,!CreateVerificationBlock!
   call:toVBB CreateVerificationOverlapBlock,!CreateVerificationOverlapBlock!
   call:toVBB VerificationBlockStartAddr,!VerificationBlockStartAddr!
   echo call=!addrCall!>>!TARGET_VBB!
   echo=>>!TARGET_VBB!

   rem Fill Comment
   if defined Comments (
      set remain=%Comments%
      :split
      for /f "tokens=1* delims=;" %%a in ("%remain%") do (
          echo Comment=%%a>>!TARGET_VBB!
          set remain=%%b
      )
      if defined remain goto :split
      echo=>>!TARGET_VBB!
   )

   rem Fill Erase Sector
   if defined EraseStart (
      (for /l %%a in (0,1,!flagEraseLength!) do (
         echo EraseStart=!EraseStartAddr[%%a]!>>!TARGET_VBB!
         echo EraseLength=!EraseLengths[%%a]!>>!TARGET_VBB!
         ))
      echo=>>!TARGET_VBB!
   )

   rem Fill Omit Sector
   if defined OmitStart (
      (for /l %%a in (0,1,!flagOmitLength!) do (
         echo OmitStart=!OmitStartAddr[%%a]!>>!TARGET_VBB!
         echo OmitLength=!OmitLengths[%%a]!>>!TARGET_VBB!
         ))
      echo=>>!TARGET_VBB!
   )      
                          
   echo=>>!TARGET_VBB!

   rem Generate Batch file (compressed)
   echo GENERATING COMPRESSED BATCHFILE: !TARGET_VBB_COMPRESSED!...
   cd.>!TARGET_VBB_COMPRESSED!
   echo ;>>!TARGET_VBB_COMPRESSED!
   echo ;!SPACE!!SPACE!!SPACE!!SPACE!VBF!SPACE!!VBF_Version!>>!TARGET_VBB_COMPRESSED!
   echo ;BATCHFILE="!TARGET_VBB_COMPRESSED!">>!TARGET_VBB_COMPRESSED!
   echo ;>>!TARGET_VBB_COMPRESSED!
   echo [VBF1]>>!TARGET_VBB_COMPRESSED!
   echo SourceFile=!HEX_PATH!!FILENAME!>>!TARGET_VBB_COMPRESSED!
   echo TargetFile=!VBF_PATH!!FILENAME_NOEXT!_Comp.vbf>>!TARGET_VBB_COMPRESSED!
   call:toVBBcomp CsumFile,!CsumFile!
   call:toVBBcomp VBFVersion,!VBF_Version!
   call:toVBBcomp ECUaddr,!ECUaddr!
   call:toVBBcomp SubNetworkAddress,!SubNetworkAddress!
   call:toVBBcomp ECUaddrSlave,!ECUaddrSlave!
   call:toVBBcomp can_frame_format,!can_frame_format!
   call:toVBBcomp frame_format,!frame_format!
   call:toVBBcomp Network,!Network!
   call:toVBBcomp NetworkSub,!NetworkSub!
   call:toVBBcomp SwType,!SwType!
   call:toVBBcomp SwPartNum,!SwPartNum!
   call:toVBBcomp SwVersion,!SwVersion!
   call:toVBBcomp SwPartNumberWERS,!SwPartNumberWERS!
   call:toVBBcomp SwPartNumberKDP,!SwPartNumberKDP!
   call:toVBBcomp Sort,!Sort!
   call:toVBBcomp Group,!Group!
   call:toVBBcomp Align,!Align!
   call:toVBBcomp AlignBlockSize,!AlignBlockSize!
   call:toVBBcomp AlignFillData,!AlignFillData!
   call:toVBBcomp Compressed,1
   call:toVBBcomp CreateVerificationBlock,!CreateVerificationBlock!
   call:toVBBcomp CreateVerificationOverlapBlock,!CreateVerificationOverlapBlock!
   call:toVBBcomp VerificationBlockStartAddr,!VerificationBlockStartAddr!
   echo call=!addrCall!>>!TARGET_VBB_COMPRESSED!
   echo=>>!TARGET_VBB_COMPRESSED!

   rem Fill Comment
   if defined Comments (
      set remain=%Comments%
      :splitComp
      for /f "tokens=1* delims=;" %%a in ("%remain%") do (
          echo Comment=%%a>>!TARGET_VBB_COMPRESSED!
          set remain=%%b
      )
      if defined remain goto :splitComp
      echo=>>!TARGET_VBB_COMPRESSED!
   )

   rem Fill Erase Sector
   if defined EraseStart (
      (for /l %%a in (0,1,!flagEraseLength!) do (
         echo EraseStart=!EraseStartAddr[%%a]!>>!TARGET_VBB_COMPRESSED!
         echo EraseLength=!EraseLengths[%%a]!>>!TARGET_VBB_COMPRESSED!
         ))
      echo=>>!TARGET_VBB_COMPRESSED!
   )

   rem Fill Omit Sector
   if defined OmitStart (
      (for /l %%a in (0,1,!flagOmitLength!) do (
         echo OmitStart=!OmitStartAddr[%%a]!>>!TARGET_VBB_COMPRESSED!
         echo OmitLength=!OmitLengths[%%a]!>>!TARGET_VBB_COMPRESSED!
         ))
      echo=>>!TARGET_VBB_COMPRESSED!
   )      
                          
   echo=>>!TARGET_VBB_COMPRESSED!
)

rem CONVERT AND SIGN VBF
if exist !TARGET_VBB! (
   echo BATCHFILE GENERATE SUCCESS
   SET TARGET_VBF=!VBF_PATH!!FILENAME_NOEXT!.vbf
   echo GENERATING VBF: !TARGET_VBF!...
   start /wait !VBFCONVERT! -BATCHFILE="!TARGET_VBB!"
   if exist !TARGET_VBF! (
      echo VBFFILE GENERATE SUCCESS
      echo SIGNING VBFFILE: !TARGET_VBF!...
      call:sign !TARGET_VBF!,!OUTPUT_PATH!!FILENAME_NOEXT!_Signed.vbf,!SIGNATURE_PRIV!
      call:signdev !OUTPUT_PATH!!FILENAME_NOEXT!_Signed.vbf,!OUTPUT_PATH!!FILENAME_NOEXT!_Signed_dev.vbf
      call:sign !TARGET_VBF!,!OUTPUT_PATH!!FILENAME_NOEXT!_Signed_Test_Private_key.vbf,!SIGNATURE_TEST!
      call:sign !OUTPUT_PATH!!FILENAME_NOEXT!_Signed_dev.vbf,!OUTPUT_PATH!!FILENAME_NOEXT!_Signed_dev_Signed_Test_Private_key.vbf,!SIGNATURE_TEST!
      rem call:signdev !OUTPUT_PATH!!FILENAME_NOEXT!_Signed_dev_Signed_Test_Private_key.vbf,!OUTPUT_PATH!!FILENAME_NOEXT!_Signed_dev_Signed_Test_Private_key_dev.vbf
      echo DELETING TEMPORARY FILE
      rem del !OUTPUT_PATH!!FILENAME_NOEXT!_Signed_dev_Signed_Test_Private_key.vbf
   ) else (
      echo GENERATE !TARGET_VBF! FAILED
      goto end
   )
) else (
   echo GENERATE !TARGET_VBB! FAILED PLEASE CHECK IF HEX FILE EXISTS.
   goto end
)

rem CONVERT AND SIGN COMPRESSED VBF
if exist !TARGET_VBB_COMPRESSED! (
   echo COMPRESSED BATCHFILE GENERATE SUCCESS
   SET TARGET_VBF_COMPRESSED=!VBF_PATH!!FILENAME_NOEXT!_Comp.vbf
   echo GENERATING COMPRESSED VBF: !TARGET_VBF_COMPRESSED!...
   start /wait !VBFCONVERT! -BATCHFILE="!TARGET_VBB_COMPRESSED!"
   if exist !TARGET_VBF_COMPRESSED! (
      echo COMPRESSED VBFFILE GENERATE SUCCESS
      echo SIGNING COMPRESSED VBFFILE: !TARGET_VBF_COMPRESSED!...
      call:sign !TARGET_VBF_COMPRESSED!,!OUTPUT_PATH!!FILENAME_NOEXT!_Comp_Signed.vbf,!SIGNATURE_PRIV!
      call:signdev !OUTPUT_PATH!!FILENAME_NOEXT!_Comp_Signed.vbf,!OUTPUT_PATH!!FILENAME_NOEXT!_Comp_Signed_dev.vbf
      call:sign !TARGET_VBF_COMPRESSED!,!OUTPUT_PATH!!FILENAME_NOEXT!_Comp_Signed_Test_Private_key.vbf,!SIGNATURE_TEST!
      call:sign !OUTPUT_PATH!!FILENAME_NOEXT!_Comp_Signed_dev.vbf,!OUTPUT_PATH!!FILENAME_NOEXT!_Comp_Signed_dev_Signed_Test_Private_key.vbf,!SIGNATURE_TEST!
      rem call:signdev !OUTPUT_PATH!!FILENAME_NOEXT!_Comp_Signed_dev_Signed_Test_Private_key.vbf,!OUTPUT_PATH!!FILENAME_NOEXT!_Comp_Signed_dev_Signed_Test_Private_key_dev.vbf
      echo DELETING TEMPORARY FILE
      rem del !OUTPUT_PATH!!FILENAME_NOEXT!_Comp_Signed_dev_Signed_Test_Private_key.vbf
   ) else (
      echo GENERATE !TARGET_VBF_COMPRESSED! FAILED
      goto end
   )
) else (
   echo GENERATE !TARGET_VBB_COMPRESSED! FAILED PLEASE CHECK IF HEX FILE EXISTS.
   goto end
)

:end
pause

:toVBB
SET name=%~1
SET value=%~2
if defined value (
   echo !name!=!value!>>!TARGET_VBB!
)
goto:eof

:toVBBcomp
SET name=%~1
SET value=%~2
if defined value (
   echo !name!=!value!>>!TARGET_VBB_COMPRESSED!
)
goto:eof

:sign
SET vbf=%~1
SET output=%~2
SET key=%~3
VbfSign.exe !vbf! !output! DontCreate !key!
echo SIGNED VBF GENERATED: !output!
goto:eof

:signdev
SET vbf=%~1
SET output=%~2
Signtosigndev.exe !vbf! !output!
echo SIGNED VBF GENERATED: !output!
goto:eof
