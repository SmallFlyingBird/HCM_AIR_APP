# Project Name：Dio_Demo


---


## Function description

This project is designed to demonstrate the MCAL Dio and Platform module config and usage:
- **Dio**: 
  - test the Api of Dio read ***Port/Channel/ChannelGroup*** and write ***Masked_Port/Port/ChannelGroup***
- **Platform**:
  - FPU exception, divide by zero exception handler is implemented.
- **Testing Process**
After reset, the demo project will test the Dio read ***Port/Channel/ChannelGroup*** API, and write ***Masked_Port/Port/ChannelGroup*** API, then toggle LED5/6/7 and LED8R/G/B with 16x loops, and then LED7 will be turned OFF as FPU Divide by Zero exception trigger and handled. At the end, to demonstrate the Dio channel notification configuration, if SW2 pressed, LED5 will be toggled, and if SW3 pressed, LED6 will be toggled.

The SW2 and SW3 input states are read back to determine which user LED will be toggled periodically as below:
- **SW2** 
   + ***pressed*** : toggle **LED7** every 100ms
   + ***released***: toggle **LED8B** every 100ms
- **SW3** 
   + ***pressed*** : toggle **LED8G** every 100ms
   + ***released***: toggle **LED8R** every 100ms
---


## Setup

+ ***Step1***: Open the Dio_Demo.yct with the YCT tool, config the toolchain per your required(by default, the VS code + GCC are used)
+ ***Step2***：Generate the codes， you can change the configurations if needed(to adapt to your own HW design), if so, please ensure all the modifications are OK with no any errors exist before generating the code.
+ ***Step3***: Open the generated project with VS code/IAR/Keil IDE per your selected.
+ ***Step4***: Compile the project, power on the EVB and download it to the EVB via the available debugger, such as a J-Link debugger probe.
+ ***Step5***: At last, confirm the test results by controlling user buttons `SW2` and `SW3` and observing the on/off blinking changes of onboard LEDs..
  
---

## Hardware requirement
+ **EVB**: YTM32B1MD1-EVB-Q100-Rev.A/B
+ **Debugger**: J-Link HW v9 or later with YUNTU `YTM32B1MD1` patch(support package) installed.

**Note**: Please check the version number at the bottom of the EVB. If it is `YTM32B1MD1-EVB-Q100-Rev.A/B`, please use the example projects ending with `_RevA` for `Icu_Demo`.
---

## Software requirement

+ **Config & Code Generation Tool**
  + **MCAL**: Yuntu Config Tool(YCT) v2.7.0 or later version
+ **Compiler Toolchain**
  + **GCC**: GNU GCC v10.3 or later version
  + **Keil/MDK**: ARM Keil/MDK v5.36 or later version(`armclang v6.18.2` is recommended to be used as the compiler)
  + **IAR**: IAR v9.50 or later version
  + **VS Code**: Microsoft Visual Studio Code IDE v1.76 or later version(C/C++ support, GNU toolchain, CMake v3.25, ninja, Cortex-Debug extensions installation required)
+ **Debugger driver**
    + **J-Link**: SEGGER J-Link v7.82 or later version, YUNTU `YTM32B1MD1` patch(support package) installation required.
    + **Ozone Debugger tool**: SEGGER Ozone v3.28 or later version.

    ***Note***: **YTM32B1MD1** patch install required which can be obtained via **YCT** or contact ***YUNTU sales/FAE team***.

---