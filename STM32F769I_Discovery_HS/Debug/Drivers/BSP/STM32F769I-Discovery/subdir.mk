################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Ryan/Documents/STM32CubeMx/Sample\ Projects/STM32Cube_FW_F7_V1.14.0/Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery.c \
C:/Users/Ryan/Documents/STM32CubeMx/Sample\ Projects/STM32Cube_FW_F7_V1.14.0/Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery_sd.c 

OBJS += \
./Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery.o \
./Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery_sd.o 

C_DEPS += \
./Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery.d \
./Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery_sd.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery.o: C:/Users/Ryan/Documents/STM32CubeMx/Sample\ Projects/STM32Cube_FW_F7_V1.14.0/Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -DUSE_HAL_DRIVER -DSTM32F769xx -DUSE_STM32F769I_DISCO -DUSE_USB_HS -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Projects/STM32F769I-Discovery/Applications/USB_Device/MSC_Standalone/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/BSP/STM32F769I-Discovery" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/CMSIS/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery_sd.o: C:/Users/Ryan/Documents/STM32CubeMx/Sample\ Projects/STM32Cube_FW_F7_V1.14.0/Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery_sd.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -DUSE_HAL_DRIVER -DSTM32F769xx -DUSE_STM32F769I_DISCO -DUSE_USB_HS -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Projects/STM32F769I-Discovery/Applications/USB_Device/MSC_Standalone/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/BSP/STM32F769I-Discovery" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/CMSIS/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery_sd.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


