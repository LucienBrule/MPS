//------------------------------------
// Lab 3 - Part 1: UART - Lab03_uart.c
//------------------------------------
//

/*
 * UART information:
 * 	textbook page 221
 * 	reference manual page 1241
 * 	USART1 and 6 setup in uart.c
 */
#include "init.h"
#include <stdlib.h>
UART_HandleTypeDef uart6;
uint8_t uart_it_recv[1] = {0x00};
void polling_receive(){
	uint8_t uart1_recv[1];
	uint8_t uart6_recv[1];
	while(1){
		uart1_recv[0] = 0;
		uart6_recv[0] = 0;
		// get char from each uart
		HAL_UART_Receive(&uart6, uart6_recv, 1, 0);
		HAL_UART_Receive(&USB_UART, uart1_recv, 1, 0);

		if(uart1_recv[0] == 27 || uart6_recv[0] == 27){
			printf("\r\nEXITING\r\n");
			uart_print(&uart6,"\r\nEXITING\r\n");
			exit(EXIT_SUCCESS);
		}

//		printf("uart6_recv: %x\r\n", uart6_recv[0]);
		if(uart1_recv[0]){
			HAL_UART_Transmit(&USB_UART,uart1_recv,1, 0);
			HAL_UART_Transmit(&uart6,uart1_recv,1, 0);
		}
		if(uart6_recv[0]){
			HAL_UART_Transmit(&USB_UART,uart6_recv,1, 0);
			HAL_UART_Transmit(&uart6, uart6_recv,1, 0);
		}
	}
}

void interrupt_init(){
	HAL_NVIC_SetPriority(USART6_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(USART6_IRQn);
	HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(USART1_IRQn);

}

// Main Execution Loop
int main(void) {
	//Initialize the system
	Sys_Init();
	//Initialize GPIO for UART
	initUart(&uart6,9600,USART6);

	// Broadcast over both UART that we are starting.
	uart_print(&uart6,"\r\n[INFO] UART6 9600\r\n");
	uart_print(&USB_UART,"\r\n[INFO] UART1 115200\r\n");
	//start the listen loop
//	TASK 2
//	polling_ receive();
//	TASK 3:
	//initialize uart interrupt
	interrupt_init();
	call_receive:
		HAL_UART_Receive_IT(&uart6,uart_it_recv,1);
		HAL_UART_Receive_IT(&USB_UART,uart_it_recv,1);
		if(uart_it_recv[0] == 27){
			printf("\r\nEXITING\r\n");
			uart_print(&uart6,"\r\nEXITING\r\n");
			return 0;
		}
		HAL_Delay(100);
	goto call_receive;

}
void USART1_IRQHandler(){
//	printf("IRQ 1 handler called\r\n");
	HAL_UART_IRQHandler(&USB_UART);
}
void USART6_IRQHandler(){
//	printf("IRQ 6 handler called\r\n");
	HAL_UART_IRQHandler(&uart6);

}
//Interrupt routine to handle received data
//void HAL_UART_RxTC
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle){
	if(UartHandle->Instance == USART6){
		HAL_UART_Transmit(&USB_UART,uart_it_recv,1, 0);
		HAL_UART_Transmit(&uart6, uart_it_recv,1, 0);
	}
	else if(UartHandle->Instance == USART1){
		HAL_UART_Transmit(&USB_UART,uart_it_recv,1, 0);
		HAL_UART_Transmit(&uart6, uart_it_recv,1, 0);
	}
}
