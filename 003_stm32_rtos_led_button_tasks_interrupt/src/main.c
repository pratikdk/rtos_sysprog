/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"

#include "FreeRTOS.h"
#include "task.h"

#include "string.h"
#include <stdint.h>

#define TRUE 		1
#define FALSE 		0
#define PRESSED		TRUE
#define NOT_PRESSED	FALSE
			
static void prvSetupUART2(void);
static void prvSetupHardware(void);
void printMessage(char *msg);
static void prvSetupGpio(void);

void led_task_handler(void *params);
void button_handler(void *params);

uint8_t button_status_flag = NOT_PRESSED;

int main(void)
{
	// 1. reset RCC clock configuration to the default reset state
	// HSI on, PLL off, HSE off, system_clock = 16mhz, core_clock = 16mhz
	RCC_DeInit();

	// 2. update the SystemCoreClock variable
	SystemCoreClockUpdate();

	// 2.1 Send data string using uart2 to debugger of ide
	prvSetupHardware();

	xTaskCreate(led_task_handler, "LED-TASK", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

	vTaskStartScheduler();

	for(;;);
}

void led_task_handler(void *params)
{
	while (1)
	{
		if (button_status_flag == PRESSED)
		{
			GPIO_WriteBit(GPIOA, GPIO_Pin_5, Bit_SET);
		}
		else
		{
			GPIO_WriteBit(GPIOA, GPIO_Pin_5, Bit_RESET);
		}
	}
}

void button_handler(void *params)
{
	button_status_flag ^= 1;
}

static void prvSetupUART2(void)
{
	// 1. Enable the GPOIA and UART2 peripheral clock
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

	// UART2_TX -> PA2
	// UART2_RX -> PA3
	// 2. GPIO pins configuration
	GPIO_InitTypeDef gpioa_uart_pins;
	memset(&gpioa_uart_pins, 0, sizeof(gpioa_uart_pins));
	gpioa_uart_pins.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_2;
	gpioa_uart_pins.GPIO_Mode = GPIO_Mode_AF;
	gpioa_uart_pins.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOA, &gpioa_uart_pins);

	// 3. Set AF mode for pa2 and pa3
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);

	// 4. USART parameter initialization
	USART_InitTypeDef usart2_init;
	memset(&usart2_init, 0, sizeof(usart2_init));
	usart2_init.USART_BaudRate = 115200;
	usart2_init.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	usart2_init.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	usart2_init.USART_Parity = USART_Parity_No;
	usart2_init.USART_StopBits = USART_StopBits_1;
	usart2_init.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART2, &usart2_init);

	// 5. Enable the USART2 peripheral
	USART_Cmd(USART2, ENABLE);
}

static void prvSetupGpio(void)
{
	// Enable gpio port a, port c peripheral and syscfg peripheral
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

	GPIO_InitTypeDef led_init, button_init;

	// configure gpio pin used by led
	led_init.GPIO_Mode = GPIO_Mode_OUT;
	led_init.GPIO_OType = GPIO_OType_PP;
	led_init.GPIO_PuPd = GPIO_PuPd_NOPULL;
	led_init.GPIO_Speed = GPIO_Low_Speed;
	led_init.GPIO_Pin = GPIO_Pin_5;

	GPIO_Init(GPIOA, &led_init);

	// configure gpio pin used by button
	button_init.GPIO_Mode = GPIO_Mode_IN;
	button_init.GPIO_OType = GPIO_OType_PP;
	button_init.GPIO_PuPd = GPIO_PuPd_NOPULL;
	button_init.GPIO_Speed = GPIO_Low_Speed;
	button_init.GPIO_Pin = GPIO_Pin_13;

	GPIO_Init(GPIOC, &button_init);

	// interrupt configuration for the button (PC13)
	// 1. (SYSCFG setting) system configuration for EXTI line
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource13);

	// 2. EXTI configuration, line 13, falling edge, interrupt mode
	EXTI_InitTypeDef exti_init;
	exti_init.EXTI_Line = EXTI_Line13;
	exti_init.EXTI_Mode = EXTI_Mode_Interrupt;
	exti_init.EXTI_Trigger = EXTI_Trigger_Falling;
	exti_init.EXTI_LineCmd = ENABLE;
	EXTI_Init(&exti_init);

	// 3. NVIC settings (EXTI line -> IRQ -> NVIC controller)
	NVIC_SetPriority(EXTI15_10_IRQn, 5);
	NVIC_EnableIRQ(EXTI15_10_IRQn);
}

static void prvSetupHardware(void)
{
	// setup gpio pins for led and button
	prvSetupGpio();

	// setup UART2
	prvSetupUART2();
}


void printMessage(char *msg)
{
	for (uint32_t i = 0; i < strlen(msg); ++i)
	{
		while (USART_GetFlagStatus(USART2, USART_FLAG_TXE) != SET);
		USART_SendData(USART2, msg[i]);
	}
}

void EXTI15_10_IRQHandler(void)
{
	// 1. clear the interrupt pending bit of EXTI line (13)
	EXTI_ClearITPendingBit(EXTI_Line13);
	// 2. call button handler
	button_handler(NULL);
}
