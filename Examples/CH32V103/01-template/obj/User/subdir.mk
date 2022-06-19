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
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\Example\CH32V103\01-template\Debug" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\Example\CH32V103\01-template\Core" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\Example\CH32V103\01-template\User" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\Example\CH32V103\01-template\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

