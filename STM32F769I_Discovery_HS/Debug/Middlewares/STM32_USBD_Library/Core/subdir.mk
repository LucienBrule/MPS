################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Ryan/Documents/STM32CubeMx/Sample\ Projects/STM32Cube_FW_F7_V1.14.0/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.c \
C:/Users/Ryan/Documents/STM32CubeMx/Sample\ Projects/STM32Cube_FW_F7_V1.14.0/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.c \
C:/Users/Ryan/Documents/STM32CubeMx/Sample\ Projects/STM32Cube_FW_F7_V1.14.0/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.c 

OBJS += \
./Middlewares/STM32_USBD_Library/Core/usbd_core.o \
./Middlewares/STM32_USBD_Library/Core/usbd_ctlreq.o \
./Middlewares/STM32_USBD_Library/Core/usbd_ioreq.o 

C_DEPS += \
./Middlewares/STM32_USBD_Library/Core/usbd_core.d \
./Middlewares/STM32_USBD_Library/Core/usbd_ctlreq.d \
./Middlewares/STM32_USBD_Library/Core/usbd_ioreq.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/STM32_USBD_Library/Core/usbd_core.o: C:/Users/Ryan/Documents/STM32CubeMx/Sample\ Projects/STM32Cube_FW_F7_V1.14.0/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -DUSE_HAL_DRIVER -DSTM32F769xx -DUSE_STM32F769I_DISCO -DUSE_USB_HS -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Projects/STM32F769I-Discovery/Applications/USB_Device/MSC_Standalone/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/BSP/STM32F769I-Discovery" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/CMSIS/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"Middlewares/STM32_USBD_Library/Core/usbd_core.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/STM32_USBD_Library/Core/usbd_ctlreq.o: C:/Users/Ryan/Documents/STM32CubeMx/Sample\ Projects/STM32Cube_FW_F7_V1.14.0/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -DUSE_HAL_DRIVER -DSTM32F769xx -DUSE_STM32F769I_DISCO -DUSE_USB_HS -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Projects/STM32F769I-Discovery/Applications/USB_Device/MSC_Standalone/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/BSP/STM32F769I-Discovery" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/CMSIS/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"Middlewares/STM32_USBD_Library/Core/usbd_ctlreq.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Middlewares/STM32_USBD_Library/Core/usbd_ioreq.o: C:/Users/Ryan/Documents/STM32CubeMx/Sample\ Projects/STM32Cube_FW_F7_V1.14.0/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -DUSE_HAL_DRIVER -DSTM32F769xx -DUSE_STM32F769I_DISCO -DUSE_USB_HS -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Projects/STM32F769I-Discovery/Applications/USB_Device/MSC_Standalone/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/BSP/STM32F769I-Discovery" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/Ryan/Documents/STM32CubeMx/Sample Projects/STM32Cube_FW_F7_V1.14.0/Drivers/CMSIS/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"Middlewares/STM32_USBD_Library/Core/usbd_ioreq.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


