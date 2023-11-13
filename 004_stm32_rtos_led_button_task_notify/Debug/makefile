################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include third_party/freeRTOS/org/Source/portable/MemMang/subdir.mk
-include third_party/freeRTOS/org/Source/portable/GCC/ARM_CM4F/subdir.mk
-include third_party/freeRTOS/org/Source/subdir.mk
-include startup/subdir.mk
-include src/subdir.mk
-include StdPeriph_Driver/src/subdir.mk
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
all: 004_stm32_rtos_led_button_task_notify.elf

# Tool invocations
004_stm32_rtos_led_button_task_notify.elf: $(OBJS) $(USER_OBJS) C:\Users\prati\Documents\rtos\004_stm32_rtos_led_button_task_notify/LinkerScript.ld
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -T"C:/Users/prati/Documents/rtos/004_stm32_rtos_led_button_task_notify/LinkerScript.ld" -Wl,-Map=output.map -Wl,--gc-sections -o "004_stm32_rtos_led_button_task_notify.elf" @"objects.list" $(USER_OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -O binary "004_stm32_rtos_led_button_task_notify.elf" "004_stm32_rtos_led_button_task_notify.bin"
	arm-none-eabi-size "004_stm32_rtos_led_button_task_notify.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
