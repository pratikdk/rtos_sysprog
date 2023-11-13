################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../third_party/SEGGER/SEGGER/SEGGER_RTT.c \
../third_party/SEGGER/SEGGER/SEGGER_SYSVIEW.c 

S_UPPER_SRCS += \
../third_party/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.S 

OBJS += \
./third_party/SEGGER/SEGGER/SEGGER_RTT.o \
./third_party/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.o \
./third_party/SEGGER/SEGGER/SEGGER_SYSVIEW.o 

S_UPPER_DEPS += \
./third_party/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.d 

C_DEPS += \
./third_party/SEGGER/SEGGER/SEGGER_RTT.d \
./third_party/SEGGER/SEGGER/SEGGER_SYSVIEW.d 


# Each subdirectory must supply rules for building sources it contributes
third_party/SEGGER/SEGGER/%.o: ../third_party/SEGGER/SEGGER/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -DSTM32F446xx -DUSE_STDPERIPH_DRIVER -I"C:/Users/prati/Documents/rtos/001_stm32_hello_world/StdPeriph_Driver/inc" -I"C:/Users/prati/Documents/rtos/001_stm32_hello_world/third_party/SEGGER/Config" -I"C:/Users/prati/Documents/rtos/001_stm32_hello_world/third_party/SEGGER/OS" -I"C:/Users/prati/Documents/rtos/001_stm32_hello_world/third_party/SEGGER/SEGGER" -I"C:/Users/prati/Documents/rtos/001_stm32_hello_world/config" -I"C:/Users/prati/Documents/rtos/001_stm32_hello_world/third_party/freeRTOS/org/Source/include" -I"C:/Users/prati/Documents/rtos/001_stm32_hello_world/third_party/freeRTOS/org/Source/portable/GCC/ARM_CM4F" -I"C:/Users/prati/Documents/rtos/001_stm32_hello_world/inc" -I"C:/Users/prati/Documents/rtos/001_stm32_hello_world/CMSIS/device" -I"C:/Users/prati/Documents/rtos/001_stm32_hello_world/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

third_party/SEGGER/SEGGER/%.o: ../third_party/SEGGER/SEGGER/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -DSTM32F446xx -DUSE_STDPERIPH_DRIVER -I"C:/Users/prati/Documents/rtos/001_stm32_hello_world/StdPeriph_Driver/inc" -I"C:/Users/prati/Documents/rtos/001_stm32_hello_world/third_party/SEGGER/Config" -I"C:/Users/prati/Documents/rtos/001_stm32_hello_world/third_party/SEGGER/OS" -I"C:/Users/prati/Documents/rtos/001_stm32_hello_world/third_party/SEGGER/SEGGER" -I"C:/Users/prati/Documents/rtos/001_stm32_hello_world/config" -I"C:/Users/prati/Documents/rtos/001_stm32_hello_world/third_party/freeRTOS/org/Source/include" -I"C:/Users/prati/Documents/rtos/001_stm32_hello_world/third_party/freeRTOS/org/Source/portable/GCC/ARM_CM4F" -I"C:/Users/prati/Documents/rtos/001_stm32_hello_world/inc" -I"C:/Users/prati/Documents/rtos/001_stm32_hello_world/CMSIS/device" -I"C:/Users/prati/Documents/rtos/001_stm32_hello_world/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


