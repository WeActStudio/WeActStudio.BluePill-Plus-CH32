* [Enlish version](./README.md)
# WeActStudio.BluePill-Plus-GD32
CH32F103C8T6
> 72Mhz Max,20KB RAM,64KB ROM,Cortex-M3

CH32V103C8T6
> 72Mhz Max,20KB RAM,64KB ROM,RISC-V

CH32 官方网站 www.wch.cn(zh-CN) / www.wch-ic.com(en)

![display](Images/BluePillPlus.jpg)

## 特性
* CH32F103C8T6 ARM Cortex-M3
+ `72 MHz` 最大运行频率
+ `64 Kbytes` of Flash memory, `20 Kbytes` of SRAM
* CH32V103C8T6 RISC-V
+ `72 MHz` 最大运行频率
+ `64 Kbytes` of Flash memory, `20 Kbytes` of SRAM
* `8 MHz` 系统晶振
* `32.768 KHz` RTC晶振
* 用户按键 KEY `PA0`
* 蓝色 LED `PB2` Active high
* 红色电源 LED `PWR`
* 2x20 侧面引脚 && 1x4 SWD 引脚
* 尺寸: `52.81 mm x 20.78 mm`

* SPI Flash U3 IO位置
  * PA4  CS
  * PA6  MISO
  * PA7  MOSI
  * PA5  SCK
* USB C
  * PA11  USB_DN
  * PA12  USB_DP
* SWD Debug
  * PA13  SWDIO
  * PA14  SWCLK

|目录名称|内容|
| :--:|:--:|
|Doc| 数据手册/参考手册|
|HDK| 硬件开发资料|
|SDK|软件开发资料|
|Examples|软件例程|

## 如何下载程序
方法1
  1. 安装`Tools`目录下的`WCHISPTool_Setup.exe`
  2. CH32V103 使用USB下载，CH32F103使用串口下载

方法2
  1. CH32F103使用J-Link的J-Flash下载，见`Tools\CH32F103\JFlash_AddOn_For_CH32F103C8T6`目录
  2. CH32F103，CH32V103使用WCHLink下载，工具见`Tools\CH32x103\`目录下的WCH_xxx_MCU_ProgramTool.zip

```
/*---------------------------------------
- WeAct Studio 官方链接
- taobao: weactstudio.taobao.com
- aliexpress: weactstudio.aliexpress.com
- github: github.com/WeActTC
- gitee: gitee.com/WeAct-TC
- blog: www.weact-tc.cn
---------------------------------------*/
```