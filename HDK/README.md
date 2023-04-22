# Release Version

* [中文版本](./README-zh.md)

## V1.1
1. Add a USB power input diode bypass pad
2. Adopt the gold sinking process

## V1.0
1. 1 x KEY (`PA0`)
2. 1 x `USB C`
3. Boot Key, easy to enter the ISP

## How to Enter ISP
> Press BOOT0 and NRST, release NRST, release BOOT0 after 0.5s, then enter serial port for download,serial port burning software see `Tools` folder.

* CH32V103C8T6/CH32V203C8T6 core board supports USB isp download
* CH32F103C8T6 core board does not support USB isp download

|File Name|Explain|
| :--:|:--:|
|BluePillPlus.IntLib|Altium Designer IntLib File|
|BluePillPlus_V11_SchDoc.pdf|SchDoc|

![BoardShape](/HDK/BoardShape_外形_V10.png)
