################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include stm32lib/Drivers/STM32F7xx_HAL_Driver/Src/subdir.mk
-include stm32lib/Drivers/CMSIS/Device/ST/STM32F7xx/Source/Templates/subdir.mk
-include startup/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: MPS_Lab01.elf

# Tool invocations
MPS_Lab01.elf: $(OBJS) $(USER_OBJS) /home/Ryan/Documents/MPS/MPS/MPS_Lab01/LinkerScript.ld
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -specs=nosys.specs -specs=nano.specs -T"/home/Ryan/Documents/MPS/MPS/MPS_Lab01/LinkerScript.ld" -Wl,-Map=output.map -Wl,--gc-sections -o "MPS_Lab01.elf" @"objects.list" $(USER_OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -O binary "MPS_Lab01.elf" "MPS_Lab01.bin"
	arm-none-eabi-size "MPS_Lab01.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
