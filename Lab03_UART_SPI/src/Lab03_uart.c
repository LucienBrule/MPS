//------------------------------------
// Lab 3 - Part 1: UART - Lab03_uart.c
//------------------------------------
//

#include "init.h"

SPI_HandleTypeDef spi2;
// Main Execution Loop
int main(void) {
	//Initialize the system
	Sys_Init();
	HAL_Init();
	//HAL_SPI_MspInit(&spi2);



	initSPI(&spi2, SPI2);

	uint8_t kbd[1];
	uint8_t spi[1];

	printf("\r\nYour code here!\r\n");
	while(1){
		kbd[0] = 0x00;
		spi[0] = 0x00;

		kbd[0] = getchar();

		//spi_putchar(spi2,kbd[0]);
		HAL_SPI_TransmitReceive(&spi2, kbd, spi,1,100);

		HAL_Delay(10);

		//spi[0] =spi_getchar(spi2,0);

		//HAL_SPI_Receive(&spi2,spi, 1, 100);

		printf("Received from keyboard: %x \r\n----\r\n Received from SPI: %x\r\n", kbd[0],spi[0]);

		fflush(0);
	}





	// Lost? Check out uart.c!

}




