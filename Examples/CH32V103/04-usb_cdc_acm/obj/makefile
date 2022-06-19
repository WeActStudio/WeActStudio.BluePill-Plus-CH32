################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include User/CherryUSB/port/ch32/subdir.mk
-include User/CherryUSB/core/subdir.mk
-include User/CherryUSB/class/cdc/subdir.mk
-include User/CherryUSB/app/subdir.mk
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
usb_cdc_acm.hex \

SECONDARY_LIST += \
usb_cdc_acm.lst \

SECONDARY_SIZE += \
usb_cdc_acm.siz \


# All Target
all: usb_cdc_acm.elf secondary-outputs

# Tool invocations
usb_cdc_acm.elf: $(OBJS) $(USER_OBJS)
	@	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized  -g -T "F:\WeActStudio1\Products\WeAct-BluePill-Plus\DataLink\WeActStudio.BluePill-Plus-CH32\Examples\CH32V103\04-usb_cdc_acm\Ld\Link.ld" -nostartfiles -Xlinker --gc-sections -Wl,-Map,"usb_cdc_acm.map" --specs=nano.specs --specs=nosys.specs -o "usb_cdc_acm.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@	@
usb_cdc_acm.hex: usb_cdc_acm.elf
	@	riscv-none-embed-objcopy -O ihex "usb_cdc_acm.elf"  "usb_cdc_acm.hex"
	@	@
usb_cdc_acm.lst: usb_cdc_acm.elf
	@	riscv-none-embed-objdump --all-headers --demangle --disassemble "usb_cdc_acm.elf" > "usb_cdc_acm.lst"
	@	@
usb_cdc_acm.siz: usb_cdc_acm.elf
	@	riscv-none-embed-size --format=berkeley "usb_cdc_acm.elf"
	@	@
# Other Targets
clean:
	-$(RM) $(ASM_UPPER_DEPS)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) usb_cdc_acm.elf
	-@
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
