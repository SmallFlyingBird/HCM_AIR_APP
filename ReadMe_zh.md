# 项目名称：Dio_Demo

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