################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/core_riscv.c 

OBJS += \
./Core/core_riscv.o 

C_DEPS += \
./Core/core_riscv.d 


# Each subdirectory must supply rules for building sources it contributes
Core/%.o: ../Core/%.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\DataLink\WeActStudio.BluePill-Plus-CH32\Examples\CH32V103\04-usb_cdc_acm\Debug" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\DataLink\WeActStudio.BluePill-Plus-CH32\Examples\CH32V103\04-usb_cdc_acm\Core" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\DataLink\WeActStudio.BluePill-Plus-CH32\Examples\CH32V103\04-usb_cdc_acm\User" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\DataLink\WeActStudio.BluePill-Plus-CH32\Examples\CH32V103\04-usb_cdc_acm\Peripheral\inc" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\DataLink\WeActStudio.BluePill-Plus-CH32\Examples\CH32V103\04-usb_cdc_acm\User\CherryUSB\app" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\DataLink\WeActStudio.BluePill-Plus-CH32\Examples\CH32V103\04-usb_cdc_acm\User\CherryUSB\class\cdc" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\DataLink\WeActStudio.BluePill-Plus-CH32\Examples\CH32V103\04-usb_cdc_acm\User\CherryUSB\core" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\DataLink\WeActStudio.BluePill-Plus-CH32\Examples\CH32V103\04-usb_cdc_acm\User\CherryUSB\common" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\DataLink\WeActStudio.BluePill-Plus-CH32\Examples\CH32V103\04-usb_cdc_acm\User\CherryUSB\osal" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\DataLink\WeActStudio.BluePill-Plus-CH32\Examples\CH32V103\04-usb_cdc_acm\User\CherryUSB\port\ch32" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

