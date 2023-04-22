################################################################################
# MRS Version: {"version":"1.8.4","date":"2023/02/15"}
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/board.c \
../User/ch32v20x_it.c \
../User/main.c \
../User/rtc.c \
../User/system_ch32v20x.c 

OBJS += \
./User/board.o \
./User/ch32v20x_it.o \
./User/main.o \
./User/rtc.o \
./User/system_ch32v20x.o 

C_DEPS += \
./User/board.d \
./User/ch32v20x_it.d \
./User/main.d \
./User/rtc.d \
./User/system_ch32v20x.d 


# Each subdirectory must supply rules for building sources it contributes
User/%.o: ../User/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\Example\CH32V203\03-rtc\Debug" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\Example\CH32V203\03-rtc\Core" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\Example\CH32V203\03-rtc\User" -I"F:\WeActStudio1\Products\WeAct-BluePill-Plus\Example\CH32V203\03-rtc\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

