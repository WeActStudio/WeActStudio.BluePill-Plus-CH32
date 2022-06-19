* [中文版本](./README-zh.md)

# JFlash AddOn For CH32F103C8T6
> Because j-Flash does not support CH32F103C8T6, and WCH does not have a corresponding solution, Jlink does not support CH32F103C8T6 except Keil. However, we can modify the j-Flash device description file to support writing CH32F103C8T6.

1. Open the `J-Flash` installation directory and find `jlinkdevices.xml`
2. Open `jlinkdevices.XML`, add the following text before `</DataBase>` at the end of the file, and save and close the file. If the file cannot be saved, copy it to a non-system directory first, and then drag it to the original directory to overwrite the original file.

```
  <Device>
    <ChipInfo Vendor="WCH" Name="CH32F103C8T6" WorkRAMAddr="0x20000000" WorkRAMSize="0x005000" Core="JLINK_CORE_CORTEX_M3"  />
    <FlashBankInfo Name="Flash Bank1" BaseAddr="0x08000000" MaxSize="0x00010000" Loader="Devices/WCH/CH32FLM/CH32F1xx.FLM" LoaderType="FLASH_ALGO_TYPE_OPEN" AlwaysPresent="1" />
  </Device>
```
3. Locate `Devices` in the directory
4. Copy the `WCH` directory to this directory
5. Re-open `J-Flash` and create a project to find `CH32F103C8T6`
