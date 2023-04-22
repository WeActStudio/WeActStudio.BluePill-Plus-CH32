################################################################################
# MRS Version: {"version":"1.8.4","date":"2023/02/15"}
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/USBLIB/USB-Driver/src/usb_core.c \
../User/USBLIB/USB-Driver/src/usb_init.c \
../User/USBLIB/USB-Driver/src/usb_int.c \
../User/USBLIB/USB-Driver/src/usb_mem.c \
../User/USBLIB/USB-Driver/src/usb_regs.c \
../User/USBLIB/USB-Driver/src/usb_sil.c 

OBJS += \
./User/USBLIB/USB-Driver/src/usb_core.o \
./User/USBLIB/USB-Driver/src/usb_init.o \
./User/USBLIB/USB-Driver/src/usb_int.o \
./User/USBLIB/USB-Driver/src/usb_mem.o \
./User/USBLIB/USB-Driver/src/usb_regs.o \
./User/USBLIB/USB-Driver/src/usb_sil.o 

C_DEPS += \
./User/USBLIB/USB-Driver/src/usb_core.d \
./User/USBLIB/USB-Driver/src/usb_init.d \
./User/USBLIB/USB-Driver/src/usb_int.d \
./User/USBLIB/USB-Driver/src/usb_mem.d \
./User/USBLIB/USB-Driver/src/usb_regs.d \
./User/USBLIB/USB-Driver/src/usb_sil.d 


# Each subdirectory must supply rules for building sources it contributes
User/USBLIB/USB-Driver/src/%.o: ../User/USBLIB/USB-Driver/src/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\Example\CH32V203\04-usb_cdc_acm\Debug" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\Example\CH32V203\04-usb_cdc_acm\Core" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\Example\CH32V203\04-usb_cdc_acm\User" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\Example\CH32V203\04-usb_cdc_acm\Peripheral\inc" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\Example\CH32V203\04-usb_cdc_acm\User\USBLIB\CONFIG" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\Example\CH32V203\04-usb_cdc_acm\User\USBLIB\USB-Driver\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

