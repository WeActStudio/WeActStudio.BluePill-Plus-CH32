################################################################################
# MRS Version: {"version":"1.8.4","date":"2023/02/15"}
# 自动生成的文件。不要编辑！
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include User/USBLIB/USB-Driver/src/subdir.mk
-include User/USBLIB/CONFIG/subdir.mk
-include User/subdir.mk
-include Startup/subdir.mk
-include Peripheral/src/subdir.mk
-include Debug/subdir.mk
-include Core/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
04-usb_cdc_acm.hex \

SECONDARY_LIST += \
04-usb_cdc_acm.lst \

SECONDARY_SIZE += \
04-usb_cdc_acm.siz \


# 所有目标
all: 04-usb_cdc_acm.elf secondary-outputs

# 工具调用
04-usb_cdc_acm.elf: $(OBJS) $(USER_OBJS)
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -T "F:\WeActStudio1\Products\WeAct-BluePill-Plus\Example\CH32V203\04-usb_cdc_acm\Ld\Link.ld" -nostartfiles -Xlinker --gc-sections -Wl,-Map,"04-usb_cdc_acm.map" --specs=nano.specs --specs=nosys.specs -o "04-usb_cdc_acm.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@	@
04-usb_cdc_acm.hex: 04-usb_cdc_acm.elf
	@	riscv-none-embed-objcopy -O ihex "04-usb_cdc_acm.elf"  "04-usb_cdc_acm.hex"
	@	@
04-usb_cdc_acm.lst: 04-usb_cdc_acm.elf
	@	riscv-none-embed-objdump --all-headers --demangle --disassemble -M xw "04-usb_cdc_acm.elf" > "04-usb_cdc_acm.lst"
	@	@
04-usb_cdc_acm.siz: 04-usb_cdc_acm.elf
	@	riscv-none-embed-size --format=berkeley "04-usb_cdc_acm.elf"
	@	@
# 其他目标
clean:
	-$(RM) $(ASM_UPPER_DEPS)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) 04-usb_cdc_acm.elf
	-@
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
