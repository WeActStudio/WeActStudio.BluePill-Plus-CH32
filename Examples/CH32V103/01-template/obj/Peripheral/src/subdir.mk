################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Peripheral/src/ch32v10x_adc.c \
../Peripheral/src/ch32v10x_bkp.c \
../Peripheral/src/ch32v10x_crc.c \
../Peripheral/src/ch32v10x_dbgmcu.c \
../Peripheral/src/ch32v10x_dma.c \
../Peripheral/src/ch32v10x_exti.c \
../Peripheral/src/ch32v10x_flash.c \
../Peripheral/src/ch32v10x_gpio.c \
../Peripheral/src/ch32v10x_i2c.c \
../Peripheral/src/ch32v10x_iwdg.c \
../Peripheral/src/ch32v10x_misc.c \
../Peripheral/src/ch32v10x_pwr.c \
../Peripheral/src/ch32v10x_rcc.c \
../Peripheral/src/ch32v10x_rtc.c \
../Peripheral/src/ch32v10x_spi.c \
../Peripheral/src/ch32v10x_tim.c \
../Peripheral/src/ch32v10x_usart.c \
../Peripheral/src/ch32v10x_usb.c \
../Peripheral/src/ch32v10x_usb_host.c \
../Peripheral/src/ch32v10x_wwdg.c 

OBJS += \
./Peripheral/src/ch32v10x_adc.o \
./Peripheral/src/ch32v10x_bkp.o \
./Peripheral/src/ch32v10x_crc.o \
./Peripheral/src/ch32v10x_dbgmcu.o \
./Peripheral/src/ch32v10x_dma.o \
./Peripheral/src/ch32v10x_exti.o \
./Peripheral/src/ch32v10x_flash.o \
./Peripheral/src/ch32v10x_gpio.o \
./Peripheral/src/ch32v10x_i2c.o \
./Peripheral/src/ch32v10x_iwdg.o \
./Peripheral/src/ch32v10x_misc.o \
./Peripheral/src/ch32v10x_pwr.o \
./Peripheral/src/ch32v10x_rcc.o \
./Peripheral/src/ch32v10x_rtc.o \
./Peripheral/src/ch32v10x_spi.o \
./Peripheral/src/ch32v10x_tim.o \
./Peripheral/src/ch32v10x_usart.o \
./Peripheral/src/ch32v10x_usb.o \
./Peripheral/src/ch32v10x_usb_host.o \
./Peripheral/src/ch32v10x_wwdg.o 

C_DEPS += \
./Peripheral/src/ch32v10x_adc.d \
./Peripheral/src/ch32v10x_bkp.d \
./Peripheral/src/ch32v10x_crc.d \
./Peripheral/src/ch32v10x_dbgmcu.d \
./Peripheral/src/ch32v10x_dma.d \
./Peripheral/src/ch32v10x_exti.d \
./Peripheral/src/ch32v10x_flash.d \
./Peripheral/src/ch32v10x_gpio.d \
./Peripheral/src/ch32v10x_i2c.d \
./Peripheral/src/ch32v10x_iwdg.d \
./Peripheral/src/ch32v10x_misc.d \
./Peripheral/src/ch32v10x_pwr.d \
./Peripheral/src/ch32v10x_rcc.d \
./Peripheral/src/ch32v10x_rtc.d \
./Peripheral/src/ch32v10x_spi.d \
./Peripheral/src/ch32v10x_tim.d \
./Peripheral/src/ch32v10x_usart.d \
./Peripheral/src/ch32v10x_usb.d \
./Peripheral/src/ch32v10x_usb_host.d \
./Peripheral/src/ch32v10x_wwdg.d 


# Each subdirectory must supply rules for building sources it contributes
Peripheral/src/%.o: ../Peripheral/src/%.c
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\Example\CH32V103\01-template\Debug" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\Example\CH32V103\01-template\Core" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\Example\CH32V103\01-template\User" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\Example\CH32V103\01-template\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

