* [Enlish version](./README.md)

# JFlash AddOn For CH32F103C8T6
> 由于J-Flash官方没有支持CH32F103C8T6，同时WCH也没有相应的解决办法，故除了Keil之外，Jlink没有其他工具支持烧写CH32F103C8T6，但是我们可以修改J-Flash的设备描述文件以支持烧写CH32F103C8T6。

1. 打开`J-Flash`安装目录,找到`JLinkDevices.xml`
2. 打开`JLinkDevices.xml`，在文件末尾，`</DataBase>`之前添加如下文本，然后保存关闭，如果无法保存，请先将文件拷贝至非系统目录，修改完后，拖至原目录覆盖原文件。
```
  <Device>
    <ChipInfo Vendor="WCH" Name="CH32F103C8T6" WorkRAMAddr="0x20000000" WorkRAMSize="0x005000" Core="JLINK_CORE_CORTEX_M3"  />
    <FlashBankInfo Name="Flash Bank1" BaseAddr="0x08000000" MaxSize="0x00010000" Loader="Devices/WCH/CH32FLM/CH32F1xx.FLM" LoaderType="FLASH_ALGO_TYPE_OPEN" AlwaysPresent="1" />
  </Device>
```
3. 在该目录下找到`Devices`
4. 将`WCH`目录复制到该目录下
5. 重新打开`J-Flash`，新建工程即可找到`CH32F103C8T6`
