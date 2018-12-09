################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Ryan/Documents/STM32CubeMx/Sample\ Projects/STM32Cube_FW_F7_V1.14.0/Projects/STM32F769I-Discovery/Applications/USB_Device/MSC_Standalone/Src/main.c \
C:/Users/Ryan/Documents/STM32CubeMx/Sample\ Projects/STM32Cube_FW_F7_V1.14.0/Projects/STM32F769I-Discovery/Applications/USB_Device/MSC_Standalone/Src/stm32f7xx_it.c \
C:/Users/Ryan/Documents/STM32CubeMx/Sample\ Projects/STM32Cube_FW_F7_V1.14.0/Projects/STM32F769I-Discovery/Applications/USB_Device/MSC_Standalone/Src/usbd_conf.c \
C:/Users/Ryan/Documents/STM32CubeMx/Sample\ Projects/STM32Cube_FW_F7_V1.14.0/Projects/STM32F769I-Discovery/Applications/USB_Device/MSC_Standalone/Src/usbd_desc.c \
C:/Users/Ryan/Documents/STM32CubeMx/Sample\ Projects/STM32Cube_FW_F7_V1.14.0/Projects/STM32F769I-Discovery/Applications/USB_Device/MSC_Standalone/Src/usbd_storage.c 

OBJS += \
./Application/User/main.o \
./Application/User/stm32f7xx_it.o \
./Application/User/usbd_conf.o \
./Application/User/usbd_desc.o \
./Application/User/usbd_storage.o 

C_DEPS += \
./Application/User/main.d \
./Application/User/stm32f7xx_it.d \
./Application/User/usbd_conf.d \
./Application/User/usbd_desc.d \
./Application/User/usbd_storage.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/main.o: C:/Users/Ryan/Documents/STM32CubeMx/Sample\ Projects/STM32Cube_FW_F7_V1.14.0/Projects/STM32F769I-Discovery/Applications/USB_Device/MSC_Standalone/Src/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -DUSE_HAL_DRIVER -DSTM32F769xx -DUSE_STM32F769I_DISCO -DUSE_USB_HS -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Projects/STM32F769I-Discovery/Applications/USB_Device/MSC_Standalone/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/BSP/STM32F769I-Discovery" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/CMSIS/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"Application/User/main.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32f7xx_it.o: C:/Users/Ryan/Documents/STM32CubeMx/Sample\ Projects/STM32Cube_FW_F7_V1.14.0/Projects/STM32F769I-Discovery/Applications/USB_Device/MSC_Standalone/Src/stm32f7xx_it.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -DUSE_HAL_DRIVER -DSTM32F769xx -DUSE_STM32F769I_DISCO -DUSE_USB_HS -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Projects/STM32F769I-Discovery/Applications/USB_Device/MSC_Standalone/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/BSP/STM32F769I-Discovery" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/CMSIS/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"Application/User/stm32f7xx_it.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/usbd_conf.o: C:/Users/Ryan/Documents/STM32CubeMx/Sample\ Projects/STM32Cube_FW_F7_V1.14.0/Projects/STM32F769I-Discovery/Applications/USB_Device/MSC_Standalone/Src/usbd_conf.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -DUSE_HAL_DRIVER -DSTM32F769xx -DUSE_STM32F769I_DISCO -DUSE_USB_HS -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Projects/STM32F769I-Discovery/Applications/USB_Device/MSC_Standalone/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/BSP/STM32F769I-Discovery" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/CMSIS/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"Application/User/usbd_conf.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/usbd_desc.o: C:/Users/Ryan/Documents/STM32CubeMx/Sample\ Projects/STM32Cube_FW_F7_V1.14.0/Projects/STM32F769I-Discovery/Applications/USB_Device/MSC_Standalone/Src/usbd_desc.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -DUSE_HAL_DRIVER -DSTM32F769xx -DUSE_STM32F769I_DISCO -DUSE_USB_HS -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Projects/STM32F769I-Discovery/Applications/USB_Device/MSC_Standalone/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/BSP/STM32F769I-Discovery" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/CMSIS/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"Application/User/usbd_desc.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/usbd_storage.o: C:/Users/Ryan/Documents/STM32CubeMx/Sample\ Projects/STM32Cube_FW_F7_V1.14.0/Projects/STM32F769I-Discovery/Applications/USB_Device/MSC_Standalone/Src/usbd_storage.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -DUSE_HAL_DRIVER -DSTM32F769xx -DUSE_STM32F769I_DISCO -DUSE_USB_HS -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Projects/STM32F769I-Discovery/Applications/USB_Device/MSC_Standalone/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/BSP/STM32F769I-Discovery" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/CMSIS/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"Application/User/usbd_storage.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


