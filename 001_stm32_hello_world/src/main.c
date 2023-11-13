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
#include <stdio.h>
#include <string.h>

#ifdef USE_SEMIHOSTING
extern void initialise_monitor_handles();
#endif

#define TRUE				1
#define FALSE				0
#define AVAILABLE			TRUE
#define NOT_AVAILABLE		FALSE

void vTask1_handler(void *params);
void vTask2_handler(void *params);
static void prvSetupHardware(void);
static void prvSetupUART2(void);
void printMessage(char *msg);

TaskHandle_t xTaskHandle1 = NULL;
TaskHandle_t xTaskHandle2 = NULL;
char usr_msg[250];
uint8_t USART_ACCESS_KEY = AVAILABLE;

int main(void)
{
	// Enable ARM Cortex M4's Cycle Counter (stored in DWT_CYCCNT register)
	DWT->CTRL |= (1 << 0); // 0th bit of CTRL register enables cycle counter

#ifdef USE_SEMIHOSTING
	initialise_monitor_handles();
#endif

	// 1. reset RCC clock configuration to the default reset state
	// HSI on, PLL off, HSE off, system_clock = 16mhz, core_clock = 16mhz
	RCC_DeInit();

	// 2. update the SystemCoreClock variable
	SystemCoreClockUpdate();

	// 2.1 Send data string using uart2 to debugger of ide
	prvSetupHardware();
	sprintf(usr_msg, "This is hello world application starting\r\n");
	printMessage(usr_msg);

	// 2.2 start recording events for segger systemview
	SEGGER_SYSVIEW_Conf();
	SEGGER_SYSVIEW_Start();

	// 3. create 2 tasks
	xTaskCreate(vTask1_handler, "Task-1", configMINIMAL_STACK_SIZE, NULL, 2, &xTaskHandle1);
	xTaskCreate(vTask2_handler, "Task-2", configMINIMAL_STACK_SIZE, NULL, 2, &xTaskHandle2);

	// 4. start the scheduler
	vTaskStartScheduler();

	for(;;);
}

void vTask1_handler(void *params)
{
	while(1)
	{
		if (USART_ACCESS_KEY == AVAILABLE)
		{
			USART_ACCESS_KEY = NOT_AVAILABLE;
			printMessage("Hello-World: From Task-1\r\n");
			USART_ACCESS_KEY = AVAILABLE;
			taskYIELD();
		}
//		printf("Hello-World: From Task-1\n");

	}
}

void vTask2_handler(void *params)
{
	while(1)
	{
		if (USART_ACCESS_KEY == AVAILABLE)
		{
			USART_ACCESS_KEY = NOT_AVAILABLE;
			printMessage("Hello-World: From Task-2\r\n");
			USART_ACCESS_KEY = AVAILABLE;
			taskYIELD();
		}
//		printf("Hello-World: From Task-2\n");
	}
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
static void prvSetupHardware(void)
{
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
