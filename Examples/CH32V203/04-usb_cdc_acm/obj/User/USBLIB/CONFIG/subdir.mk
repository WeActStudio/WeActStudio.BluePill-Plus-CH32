################################################################################
# MRS Version: {"version":"1.8.4","date":"2023/02/15"}
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/USBLIB/CONFIG/hw_config.c \
../User/USBLIB/CONFIG/usb_desc.c \
../User/USBLIB/CONFIG/usb_endp.c \
../User/USBLIB/CONFIG/usb_istr.c \
../User/USBLIB/CONFIG/usb_prop.c \
../User/USBLIB/CONFIG/usb_pwr.c 

OBJS += \
./User/USBLIB/CONFIG/hw_config.o \
./User/USBLIB/CONFIG/usb_desc.o \
./User/USBLIB/CONFIG/usb_endp.o \
./User/USBLIB/CONFIG/usb_istr.o \
./User/USBLIB/CONFIG/usb_prop.o \
./User/USBLIB/CONFIG/usb_pwr.o 

C_DEPS += \
./User/USBLIB/CONFIG/hw_config.d \
./User/USBLIB/CONFIG/usb_desc.d \
./User/USBLIB/CONFIG/usb_endp.d \
./User/USBLIB/CONFIG/usb_istr.d \
./User/USBLIB/CONFIG/usb_prop.d \
./User/USBLIB/CONFIG/usb_pwr.d 


# Each subdirectory must supply rules for building sources it contributes
User/USBLIB/CONFIG/%.o: ../User/USBLIB/CONFIG/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\Example\CH32V203\04-usb_cdc_acm\Debug" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\Example\CH32V203\04-usb_cdc_acm\Core" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\Example\CH32V203\04-usb_cdc_acm\User" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\Example\CH32V203\04-usb_cdc_acm\Peripheral\inc" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\Example\CH32V203\04-usb_cdc_acm\User\USBLIB\CONFIG" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\Example\CH32V203\04-usb_cdc_acm\User\USBLIB\USB-Driver\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

