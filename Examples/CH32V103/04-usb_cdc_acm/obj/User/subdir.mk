################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/board.c \
../User/ch32v10x_it.c \
../User/main.c \
../User/system_ch32v10x.c 

OBJS += \
./User/board.o \
./User/ch32v10x_it.o \
./User/main.o \
./User/system_ch32v10x.o 

C_DEPS += \
./User/board.d \
./User/ch32v10x_it.d \
./User/main.d \
./User/system_ch32v10x.d 


# Each subdirectory must supply rules for building sources it contributes
User/%.o: ../User/%.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\DataLink\WeActStudio.BluePill-Plus-CH32\Examples\CH32V103\04-usb_cdc_acm\Debug" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\DataLink\WeActStudio.BluePill-Plus-CH32\Examples\CH32V103\04-usb_cdc_acm\Core" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\DataLink\WeActStudio.BluePill-Plus-CH32\Examples\CH32V103\04-usb_cdc_acm\User" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\DataLink\WeActStudio.BluePill-Plus-CH32\Examples\CH32V103\04-usb_cdc_acm\Peripheral\inc" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\DataLink\WeActStudio.BluePill-Plus-CH32\Examples\CH32V103\04-usb_cdc_acm\User\CherryUSB\app" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\DataLink\WeActStudio.BluePill-Plus-CH32\Examples\CH32V103\04-usb_cdc_acm\User\CherryUSB\class\cdc" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\DataLink\WeActStudio.BluePill-Plus-CH32\Examples\CH32V103\04-usb_cdc_acm\User\CherryUSB\core" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\DataLink\WeActStudio.BluePill-Plus-CH32\Examples\CH32V103\04-usb_cdc_acm\User\CherryUSB\common" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\DataLink\WeActStudio.BluePill-Plus-CH32\Examples\CH32V103\04-usb_cdc_acm\User\CherryUSB\osal" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\DataLink\WeActStudio.BluePill-Plus-CH32\Examples\CH32V103\04-usb_cdc_acm\User\CherryUSB\port\ch32" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

