################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/init.c \
../src/main.c \
../src/uart.c 

OBJS += \
./src/init.o \
./src/main.o \
./src/uart.o 

C_DEPS += \
./src/init.d \
./src/main.d \
./src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -DUSE_HAL_DRIVER -DSTM32F769xx -DUSE_STM32F769I_DISCO -I"C:/Users/Ryan/Documents/MPS_Labs/MPS/LAB5/inc" -I"C:/Users/Ryan/Documents/MPS_Labs/MPS/stm32lib/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/Ryan/Documents/MPS_Labs/MPS/stm32lib/Drivers/CMSIS/Include" -I"C:/Users/Ryan/Documents/MPS_Labs/MPS/stm32lib/Drivers/STM32F7xx_HAL_Driver/Inc" -Og -g3 -Wall -fmessage-length=0 -Wdouble-promotion -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


