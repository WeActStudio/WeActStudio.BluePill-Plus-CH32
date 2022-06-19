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
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\Example\CH32V103\03-rtc\Debug" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\Example\CH32V103\03-rtc\Core" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\Example\CH32V103\03-rtc\User" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\Example\CH32V103\03-rtc\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

