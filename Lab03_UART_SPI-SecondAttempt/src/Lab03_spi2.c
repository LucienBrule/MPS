//----------------------------------
// Lab 3 - Part 3: SPI - Lab03_spi.c
//----------------------------------
//

#include "init.h"

// If needed:
//#include <stdio.h>
//#include <stdlib.h>

/*
 * For convenience, configure the SPI handler here
 */
// See 769 Description of HAL drivers.pdf, Ch. 58.1 or stm32f7xx_hal_spi.c

SPI_HandleTypeDef spi2;

void task3(){
	uint8_t i[1], o[1];

	while(1){
		i[0] = 0x00;
		o[0] = 0x00;
		printf("Enter something\r\n");
		o[0] = getchar();
		HAL_SPI_TransmitReceive(&spi2, o,i,1,100);

		printf("Recieved %c; Transmitted %c\r\n", i[0], o[0]);
	}

}
void configureSPI()
{

//	[SPIHandler here].Instance = SPI2; // Please use SPI2!
//	[SPIHandler here].Init.Mode = SPI_MODE_MASTER; // Set master mode
//	[SPIHandler here].Init.TIMode = SPI_TIMODE_DISABLE; // Use Motorola mode, not TI mode
/*
 * ... You get the idea.
 */
	spi2.Instance = SPI2;
	spi2.Init.Mode = SPI_MODE_MASTER;
	spi2.Init.TIMode = SPI_TIMODE_DISABLE;
	spi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_128;
	spi2.Init.DataSize = SPI_DATASIZE_8BIT;
	spi2.Init.Direction = SPI_DIRECTION_2LINES;
	spi2.Init.CLKPolarity = SPI_POLARITY_LOW;
	spi2.Init.CLKPhase = SPI_PHASE_1EDGE;
	spi2.Init.NSS = SPI_NSS_SOFT;
	spi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
	spi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	spi2.Init.CRCPolynomial = 10;






	if(HAL_SPI_Init(&spi2) != HAL_OK){
		printf("Error\r\n");
	}

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
	GPIO_InitTypeDef g;
	if (hspi->Instance == SPI2)
	{
		// Enable SPI GPIO port clocks, set HAL GPIO init structure's values for each
		// SPI-related port pin (SPI port pin configuration), enable SPI IRQs (if applicable), etc.


		__HAL_RCC_GPIOC_CLK_ENABLE();
		__HAL_RCC_GPIOA_CLK_ENABLE();
		__HAL_RCC_GPIOB_CLK_ENABLE();
		__HAL_RCC_GPIOJ_CLK_ENABLE();
		__SPI2_CLK_ENABLE();
		__HAL_RCC_SPI2_CLK_ENABLE();
		g.Pin = GPIO_PIN_14;
		g.Mode = GPIO_MODE_AF_PP;
		g.Pull = GPIO_PULLUP;
		g.Speed = GPIO_SPEED_HIGH;
		g.Alternate = GPIO_AF5_SPI2;

		HAL_GPIO_Init(GPIOB,&g);

		g.Pin= GPIO_PIN_15;
		HAL_GPIO_Init(GPIOB, &g);

		g.Pin = GPIO_PIN_12;

		HAL_GPIO_Init(GPIOA,&g);





	}
}

int main(void)
{
	Sys_Init();

	// For convenience
	configureSPI();

	GPIO_InitTypeDef g;
	g.Pin = GPIO_PIN_6;
	g.Mode = GPIO_MODE_OUTPUT_PP;
	g.Pull = GPIO_PULLUP;

	HAL_GPIO_Init(GPIOC, &g);

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_SET);
	printf("Your code here!\r\n");


// See 769 Description of HAL drivers.pdf, Ch. 58.2.3 or stm32f7xx_hal_spi.c
//
//	HAL_StatusTypeDef HAL_SPI_TransmitReceive(SPI_HandleTypeDef *hspi, uint8_t *pTxData, uint8_t *pRxData, uint16_t Size, uint32_t Timeout)
//
}
