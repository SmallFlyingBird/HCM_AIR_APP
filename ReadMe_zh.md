# 项目名称：Dio_Demo

## HCM AIR 的 VS Code / CMake 构建

本工程实际使用 Green Hills 2022.1.4（`ccarm.exe` / `cxarm.exe`）和
Cortex-M33。仅安装 VS Code 的 CMake Tools 扩展并不包含 CMake、Ninja
或编译器；也不能仅通过 `c_cpp_properties.json` 的 `compilerPath` 配置构建。

当前电脑的配置位于 `.vscode/settings.json` 和 `CMakeUserPresets.json`，
这两个文件包含本机设置，不提交到 Git。便携版 CMake 3.31.8 和 Ninja 1.12.1
位于 `.tools/`，GHS 位于 `D:/Work/XY/Compiler/comp_202214`。

1. 在 VS Code 命令面板执行 `Developer: Reload Window`。
2. 执行 `CMake: Select Configure Preset`，选择 `ghs-local`
   （显示名称为 `HCM AIR - GHS 2022.1.4 (Cortex-M33)`）。
3. 执行 `CMake: Configure`，再执行 `CMake: Build`。
   若提示选择构建预设，也选择 `ghs-local`。

也可以在项目根目录的 PowerShell 中执行：

```powershell
& ./.tools/cmake-3.31.8-windows-x86_64/bin/cmake.exe --preset ghs-local
& ./.tools/cmake-3.31.8-windows-x86_64/bin/cmake.exe --build --preset ghs-local --parallel 4
```

日常构建生成 `build/HCM_AIR.elf` 和 `build/HCM_AIR.hex`。
本机预设设置 `HCM_GENERATE_RELEASE_PACKAGE=OFF`，不运行 HexView 和 VBF 转换。
需要发布包时，在本机预设的 `cacheVariables` 中将该选项改为 `ON`，并设置
`HEXVIEW_TOOL` 为实际的 `hexview.exe` 路径，然后重新配置和构建。
此选项不改变 `HCM_AIR_RELEASE` 或固件的编译参数。

迁移到其他电脑时，需要重新准备 CMake、Ninja 和 GHS，并配置同名本机预设：
生成器为 `Ninja`，构建目录为 `${sourceDir}/build`，工具链文件为
`${sourceDir}/cmake/ghs.cmake`，`ARM_CPU=cortexm33`，
`CMAKE_PREFIX_PATH` 指向 GHS 安装目录，`CMAKE_MAKE_PROGRAM` 指向 Ninja。

---

## 功能描述

本项目旨在演示MCAL Dio和Platform模块的配置和使用：

- **Dio**: 
    - 测试Dio读取***Port/Channel/ChannelGroup***和写入***Masked_Port/Port/ChannelGroup***的API

- **Platform**:
    - 实现了FPU异常，除零异常处理程序。
- **测试过程**
    - 复位后，演示项目将测试 Dio 读取 ***Port/Channel/ChannelGroup*** API 和写入 ***Masked_Port/Port/ChannelGroup*** API，然后切换 **LED5/6/7** 和 **LED8R/G/B** **10**- 次循环，之后 **LED7** 将关闭，因为触发了 FPU 除零异常并已处理。

 最后，在主循环中，用户按键**SW2**和**SW3**的输入状态被读回，以确定哪个用户LED将周期亮灭闪烁：

- **SW2** 
    + ***按下*** : 每 100ms 亮灭 **LED7**
    + ***释放***: 每 100ms 亮灭 **LED8B**
- **SW3** 
    + ***按下*** : 每 100ms 亮灭 **LED8G**
    + ***释放***: 每 100ms 亮灭 **LED8R**
---

## 步骤

+ ***步骤1***: 使用 YCT 工具打开 Dio_Demo.yct，根据您的需求配置工具链（默认使用 VS code + GCC）
+ ***步骤2***：生成代码，如果需要，可以更改配置（以适应您自己的硬件设计），如果这样做，请确保所有修改都正确无误，没有错误存在，然后再生成代码。
+ ***步骤3***: 使用您选择的 VS code/IAR/Keil IDE 打开生成的项目。
+ ***步骤4***: 编译项目，给 EVB 上电并通过可用的调试器（如 J-Link 调试器探头）下载到 EVB。
+ ***步骤5***: 最后，通过控制用户按键**SW2**和**SW3**以及观察板载LED亮灭闪烁变化确认测试结果。

---

## 硬件需求
+ **EVB**: YTM32B1MD1-EVB-Q100-Rev.A/B
+ **调试器**: J-Link HW v9 或更高版本，安装了 YUNTU `YTM32B1MD1` 补丁（支持包）。

***注意***: 请确认EVB底部的版本号，如果是***YTM32B1MD1-EVB-Q100-Rev.A***，`Icu_Demo`请使用以`_RevA`结尾的样例工程。

---

## 软件需求

+ **配置和代码生成工具**
  + **MCAL**: Yuntu Config Tool(YCT) v2.7.0 或更高版本
+ **编译器工具链**
  + **GCC**: GNU GCC v10.3 或更高版本
  + **Keil/MDK**: ARM Keil/MDK v5.36 或更高版本(编译器推荐使用`armclang v6.18.2`)
  + **IAR**: IAR v9.50 或更高版本
  + **VS Code**: Microsoft Visual Studio Code IDE v1.76 或更高版本（需要 C/C++ 支持，GNU 工具链，CMake v3.25，ninja，Cortex-Debug 扩展安装）
+ **Debugger driver**
    + **J-Link**: SEGGER J-Link v7.82 或更高版本，需要安装 YUNTU `YTM32B1MD1` 补丁（支持包）。
    + **Ozone Debugger tool**: SEGGER Ozone v3.28 或更高版本。

    ***注意***: 需要安装 **YTM32B1MD1** 补丁，补丁可通过 **YCT** 工具或联系 ***云途 销售/FAE 团队***获取.

---
