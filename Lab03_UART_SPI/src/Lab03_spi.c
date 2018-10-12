//----------------------------------
// Lab 3 - Part 3: SPI - Lab03_spi.c
//----------------------------------
//

#include "init.h"

// If needed:
#include <stdio.h>
#include <stdlib.h>

/*
 * For convenience, configure the SPI handler here
 */
// See 769 Description of HAL drivers.pdf, Ch. 58.1 or stm32f7xx_hal_spi.c

SPI_HandleTypeDef spi2;
void configureSPI()
{
//	[SPIHandler here].Instance = SPI2; // Please use SPI2!
//	[SPIHandler here].Init.Mode = SPI_MODE_MASTER; // Set master mode
//	[SPIHandler here].Init.TIMode = SPI_TIMODE_DISABLE; // Use Motorola mode, not TI mode
/*
 * ... You get the idea.
 */
	spi2.Instance = SPI2;
	spi2.Init.Mode= SPI_MODE_MASTER;
	spi2.Init.TIMode= SPI_TIMODE_DISABLE;
	spi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_128;
	spi2.Init.DataSize= SPI_DATASIZE_8BIT;
	spi2.Init.Direction= SPI_DIRECTION_2LINES;


	HAL_SPI_Init(&spi2);
	//
	// Note: HAL_StatusTypeDef HAL_SPI_Init(SPI_HandleTypeDef *hspi)
	//
	// HAL_SPI_Init() will call HAL_SPI_MspInit() after reading the properities of
	// the passed SPI_HandleTypeDef. After finishing the MspInit call, it will set
	// the SPI property bits. This is how all HAL_[peripheral]_Init() functions work.
}

/*
 * This is called upon SPI initialization. It handles the configuration
 * of the GPIO pins for SPI.
 */
 // Do NOT change the name of an MspInit function; it needs to override a
 // __weak function of the same name. It does not need a prototype in the header.
void HAL_SPI_MspInit(SPI_HandleTypeDef *hspi)
{
	// SPI GPIO initialization structure here
	GPIO_InitTypeDef gpio;
	if (hspi->Instance == SPI2)
	{
		// Enable SPI GPIO port clocks, set HAL GPIO init structure's values for each
		// SPI-related port pin (SPI port pin configuration), enable SPI IRQs (if applicable), etc.
		__HAL_RCC_GPIOB_CLK_ENABLE();
		__HAL_RCC_GPIOA_CLK_ENABLE();
		printf("init\r\n");
		gpio.Pin = GPIO_PIN_15;
		gpio.Mode = GPIO_MODE_AF_PP;
		gpio.Pull = GPIO_PULLUP;
		gpio.Speed= GPIO_SPEED_MEDIUM;
		gpio.Alternate = GPIO_AF5_SPI2;

		HAL_GPIO_Init(GPIOB, &gpio);

		gpio.Pin = GPIO_PIN_14;

		//MISO
		HAL_GPIO_Init(GPIOB, &gpio);

		gpio.Pin = GPIO_PIN_12;

		//SCK
		HAL_GPIO_Init(GPIOA, &gpio);

		__SPI2_CLK_ENABLE();
		fflush(0);



	}
}

int main(void)
{
	Sys_Init();

	// For convenience
	configureSPI();

	__HAL_RCC_GPIOC_CLK_ENABLE();
	GPIO_InitTypeDef g;
	g.Pin = 6;
	g.Mode = GPIO_MODE_OUTPUT_PP;
	g.Pull = GPIO_PULLDOWN;
	g.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOC, &g);

	HAL_GPIO_TogglePin(GPIOC, 6);
	getchar();

	HAL_GPIO_WritePin(GPIOC,6,GPIO_PIN_SET);

	HAL_GPIO_WritePin(GPIOA, 12,GPIO_PIN_SET);
	HAL_Delay(100);
	HAL_GPIO_TogglePin(GPIOA, 12);
	HAL_Delay(100);

	getchar();

	printf("Your code here!\r\n");

	uint8_t kbd[1],sp[1],dummy[1];

	while(1){
		kbd[0] = 0x00;
		sp[0] = 0x00;
		dummy[0] = 0x11;

		kbd[0] = 0xcc;

		//spi_putchar(spi2,kbd[0]);

		HAL_SPI_Transmit(&spi2, kbd,1,100);



		//HAL_SPI_TransmitReceive(&spi2,dummy,sp,1,100);

		HAL_Delay(10);

		//spi[0] =spi_getchar(spi2,0);

		//HAL_SPI_Receive(&spi2,sp, 1, 100);

		printf("Received from keyboard: %x \r\n----\r\n Received from SPI: %x\r\n", kbd[0],sp[0]);

		//fflush(0);
		}

// See 769 Description of HAL drivers.pdf, Ch. 58.2.3 or stm32f7xx_hal_spi.c
//
//	HAL_StatusTypeDef HAL_SPI_TransmitReceive(SPI_HandleTypeDef *hspi, uint8_t *pTxData, uint8_t *pRxData, uint16_t Size, uint32_t Timeout)
//
}
