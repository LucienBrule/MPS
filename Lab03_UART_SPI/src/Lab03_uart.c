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

void polling_receive(UART_HandleTypeDef *uart6){
	uint8_t uart1_recv[1];
	uint8_t uart6_recv[1];
	while(1){
		uart1_recv[1] = 0;
		uart6_recv[1] = 0;
		// get char from each uart
		HAL_UART_Receive(&USB_UART, &uart1_recv, 1, 100);
		HAL_UART_Receive(&USB_UART, &uart6_recv, 1, 100);

		if(uart1_recv[0]){
			HAL_UART_Transmit(&USB_UART,&uart1_recv,1, 10);
			HAL_UART_Transmit(&uart6,&uart1_recv,1, 10);
			fflush(0);
		}
		if(uart6_recv[0]){
			HAL_UART_Transmit(&uart6,&uart1_recv,1, 10);
			HAL_UART_Transmit(&uart6,&uart6_recv,1, 10);
			fflush(0);
		}

	}

}
// Main Execution Loop
int main(void) {
	//Initialize the system
	Sys_Init();
	//Initialize GPIO for UART
	UART_HandleTypeDef uart6;
	initUart(&uart6,9600,USART6);
	// Broadcast over both UART that we are starting.
	uart_print(&uart6,"\r\n[printf] UART6 9600\r\n");
	uart_print(&USB_UART,"\r\n[printf] UART1 115200\r\n");
	//start the listen loop
	polling_receive(&uart6);


}
