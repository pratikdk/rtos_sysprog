################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../third_party/freeRTOS/org/Source/croutine.c \
../third_party/freeRTOS/org/Source/event_groups.c \
../third_party/freeRTOS/org/Source/list.c \
../third_party/freeRTOS/org/Source/queue.c \
../third_party/freeRTOS/org/Source/stream_buffer.c \
../third_party/freeRTOS/org/Source/tasks.c \
../third_party/freeRTOS/org/Source/timers.c 

OBJS += \
./third_party/freeRTOS/org/Source/croutine.o \
./third_party/freeRTOS/org/Source/event_groups.o \
./third_party/freeRTOS/org/Source/list.o \
./third_party/freeRTOS/org/Source/queue.o \
./third_party/freeRTOS/org/Source/stream_buffer.o \
./third_party/freeRTOS/org/Source/tasks.o \
./third_party/freeRTOS/org/Source/timers.o 

C_DEPS += \
./third_party/freeRTOS/org/Source/croutine.d \
./third_party/freeRTOS/org/Source/event_groups.d \
./third_party/freeRTOS/org/Source/list.d \
./third_party/freeRTOS/org/Source/queue.d \
./third_party/freeRTOS/org/Source/stream_buffer.d \
./third_party/freeRTOS/org/Source/tasks.d \
./third_party/freeRTOS/org/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
third_party/freeRTOS/org/Source/%.o: ../third_party/freeRTOS/org/Source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -DSTM32F446xx -DUSE_STDPERIPH_DRIVER -I"C:/Users/prati/Documents/rtos/002_stm32_rtos_led_button_tasks/StdPeriph_Driver/inc" -I"C:/Users/prati/Documents/rtos/002_stm32_rtos_led_button_tasks/third_party/freeRTOS/org" -I"C:/Users/prati/Documents/rtos/002_stm32_rtos_led_button_tasks/config" -I"C:/Users/prati/Documents/rtos/002_stm32_rtos_led_button_tasks/third_party/freeRTOS/org/Source/include" -I"C:/Users/prati/Documents/rtos/002_stm32_rtos_led_button_tasks/third_party/freeRTOS/org/Source/portable/GCC/ARM_CM4F" -I"C:/Users/prati/Documents/rtos/002_stm32_rtos_led_button_tasks/inc" -I"C:/Users/prati/Documents/rtos/002_stm32_rtos_led_button_tasks/CMSIS/device" -I"C:/Users/prati/Documents/rtos/002_stm32_rtos_led_button_tasks/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


