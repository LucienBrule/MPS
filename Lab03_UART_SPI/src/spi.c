#include "init.h"

void initSPI(SPI_HandleTypeDef *Shand, SPI_TypeDef *Tgt){
	Shand -> Instance = Tgt;
	Shand -> Init.Mode  = SPI_MODE_MASTER;
	Shand -> Init.Direction = SPI_DIRECTION_2LINES;
	Shand -> Init.DataSize = SPI_DATASIZE_8BIT;
	Shand -> Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_128;
	Shand -> Init.TIMode = SPI_TIMODE_DISABLE;

	HAL_SPI_Init(Shand);

}

void HAL_SPI_MspInit(SPI_HandleTypeDef *hspi){

	printf("init\r\n");
	__GPIOC_CLK_ENABLE();
	__GPIOB_CLK_ENABLE();
	__GPIOA_CLK_ENABLE();

	GPIO_InitTypeDef GPIOStruct;

	GPIOStruct.Pin = GPIO_PIN_15;
	GPIOStruct.Mode = GPIO_MODE_AF_PP;
	GPIOStruct.Pull = GPIO_PULLUP;
	GPIOStruct.Speed= GPIO_SPEED_HIGH;
	GPIOStruct.Alternate = GPIO_AF7_SPI2;

	//MOSI
	HAL_GPIO_Init(GPIOB, &GPIOStruct);

	GPIOStruct.Pin = GPIO_PIN_14;

	//MISO
	HAL_GPIO_Init(GPIOB, &GPIOStruct);

	GPIOStruct.Pin = GPIO_PIN_12;

	//SCK
	HAL_GPIO_Init(GPIOA, &GPIOStruct);

	__SPI2_CLK_ENABLE();
	fflush(0);

}



char spi_getchar(SPI_HandleTypeDef *hspi, uint8_t echo) {
	char input[1];
	HAL_SPI_Receive(hspi, (uint8_t *)input, 1, HAL_MAX_DELAY);
	if (echo) HAL_SPI_Transmit(hspi, (uint8_t*) input, 1, 1000);
	return (char)input[0];
}

// Send one character
void spi_putchar(SPI_HandleTypeDef *hspi, char * input) {
	HAL_SPI_Transmit(hspi, (uint8_t*) input, 1, 1000);
}

