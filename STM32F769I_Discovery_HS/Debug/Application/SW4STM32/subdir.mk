################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
C:/Users/Ryan/Documents/STM32CubeMx/Sample\ Projects/STM32Cube_FW_F7_V1.14.0/Projects/STM32F769I-Discovery/Applications/USB_Device/MSC_Standalone/SW4STM32/startup_stm32f769xx.s 

OBJS += \
./Application/SW4STM32/startup_stm32f769xx.o 


# Each subdirectory must supply rules for building sources it contributes
Application/SW4STM32/startup_stm32f769xx.o: C:/Users/Ryan/Documents/STM32CubeMx/Sample\ Projects/STM32Cube_FW_F7_V1.14.0/Projects/STM32F769I-Discovery/Applications/USB_Device/MSC_Standalone/SW4STM32/startup_stm32f769xx.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-as -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


