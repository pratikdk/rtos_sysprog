################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../third_party/freeRTOS/org/Source/portable/GCC/ARM_CM4F/port.c 

OBJS += \
./third_party/freeRTOS/org/Source/portable/GCC/ARM_CM4F/port.o 

C_DEPS += \
./third_party/freeRTOS/org/Source/portable/GCC/ARM_CM4F/port.d 


# Each subdirectory must supply rules for building sources it contributes
third_party/freeRTOS/org/Source/portable/GCC/ARM_CM4F/%.o: ../third_party/freeRTOS/org/Source/portable/GCC/ARM_CM4F/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -DSTM32F446xx -DUSE_STDPERIPH_DRIVER -I"C:/Users/prati/Documents/rtos/003_stm32_rtos_led_button_tasks_interrupt/StdPeriph_Driver/inc" -I"C:/Users/prati/Documents/rtos/003_stm32_rtos_led_button_tasks_interrupt/third_party/freeRTOS/org/Source/include" -I"C:/Users/prati/Documents/rtos/003_stm32_rtos_led_button_tasks_interrupt/third_party/freeRTOS/org/Source/portable/GCC/ARM_CM4F" -I"C:/Users/prati/Documents/rtos/003_stm32_rtos_led_button_tasks_interrupt/third_party/freeRTOS/org" -I"C:/Users/prati/Documents/rtos/003_stm32_rtos_led_button_tasks_interrupt/config" -I"C:/Users/prati/Documents/rtos/003_stm32_rtos_led_button_tasks_interrupt/inc" -I"C:/Users/prati/Documents/rtos/003_stm32_rtos_led_button_tasks_interrupt/CMSIS/device" -I"C:/Users/prati/Documents/rtos/003_stm32_rtos_led_button_tasks_interrupt/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


