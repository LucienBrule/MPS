#include "init.h"
#define TEXT_ESCAPE "\033[0;33m\033[44m\n"

DMA_HandleTypeDef txSPI, rxSPI;
SPI_HandleTypeDef spi2;
int done = 0;

void task3();
void task2();
void initDMA();
void configureSPI();
int main(){
	Sys_Init();
	initDMA();
	configureSPI();
	printf("Enter something\r\n");
	task3();
	//HAL_Delay(1000);
	/*while(1){
		char a = getchar();
		printf("You entered: %c\r\n",a);
	}
	*/

}

void task1(){
#ifdef TEXT_ESCAPE
 printf(TEXT_ESCAPE);
#endif

	printf("                                               PRESS <ESC> OR <CTRL> + [ TO QUIT");
	printf(" \n \n \n \n \n \n\r");
	char key_pressed = 0;
	while(key_pressed != 0x1B){
		key_pressed = getchar();
		if(isprint(key_pressed)){
			printf("The keyboard character is %c\n\r", key_pressed);
		}
		else if(key_pressed == 0x0A){
			// Do nothing
		}else{
			printf("The keyboard character $%x is 'not printable'\a\n\r", key_pressed);
		}
	}
	printf("Exiting\r\n");
	while(1);
}



void task2(){
	uint8_t i[1], o[1], index;

	index = 0;
	while(1){
		i[0] = 0x00;
		o[0] = 0x00;

		o[0] = getchar();
		printf("Got something\r\n");
		HAL_SPI_TransmitReceive_DMA(&spi2, o,i,1);
		while(!done);

		printf("\033[2J");
//		printf("\033[1;0Kbd %c\r\n\nSPI%c", o[0],i[0]);
		printf("KBD: %c \r\n",o[0]);
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("SPI: %c \r\n",i[0]);
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");







		index++;
	}

}


void configureSPI()
{

//	[SPIHandler here].Instance = SPI2; // Please use SPI2!
//	[SPIHandler here].Init.Mode = SPI_MODE_MASTER; // Set master mode
//	[SPIHandler here].Init.TIMode = SPI_TIMODE_DISABLE; // Use Motorola mode, not TI mode


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

	__HAL_LINKDMA(&spi2,hdmatx,txSPI);
	__HAL_LINKDMA(&spi2,hdmarx,rxSPI);





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

void initSPIDMA(){
	//__DMA2_CLK_ENABLE();
		__HAL_RCC_DMA1_CLK_ENABLE();

		txSPI.Instance = DMA1_Stream4;
		txSPI.Init.Channel = DMA_CHANNEL_0;
		txSPI.Init.Direction = DMA_MEMORY_TO_PERIPH;
		txSPI.Init.PeriphInc = DMA_PINC_DISABLE;
		txSPI.Init.MemInc = DMA_MINC_ENABLE;
		txSPI.Init.PeriphDataAlignment = DMA_MDATAALIGN_BYTE;
		txSPI.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
		txSPI.Init.Mode = DMA_NORMAL;
		txSPI.Init.Priority = DMA_PRIORITY_VERY_HIGH;
		txSPI.Init.FIFOMode = DMA_FIFOMODE_DISABLE;


		rxSPI.Instance = DMA1_Stream3;
		rxSPI.Init.Channel = DMA_CHANNEL_0;
		rxSPI.Init.Direction = DMA_PERIPH_TO_MEMORY;
		rxSPI.Init.PeriphInc = DMA_PINC_DISABLE;
		rxSPI.Init.MemInc = DMA_MINC_ENABLE;
		rxSPI.Init.PeriphDataAlignment = DMA_MDATAALIGN_BYTE;
		rxSPI.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
		rxSPI.Init.Mode = DMA_NORMAL;
		rxSPI.Init.Priority = DMA_PRIORITY_VERY_HIGH;
		rxSPI.Init.FIFOMode = DMA_FIFOMODE_DISABLE;

		HAL_DMA_Init(&txSPI);
		HAL_DMA_Init(&rxSPI);

		HAL_NVIC_EnableIRQ(SPI2_IRQn);
		HAL_NVIC_SetPriority(SPI2_IRQn,0,0);
		HAL_NVIC_SetPriority(DMA1_Stream4_IRQn, 0, 0);
		HAL_NVIC_EnableIRQ(DMA1_Stream4_IRQn);
		HAL_NVIC_SetPriority(DMA1_Stream3_IRQn, 0, 0);
		HAL_NVIC_EnableIRQ(DMA1_Stream3_IRQn);
}

void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi){
	printf("Callback");
	done = 1;
}

void DMA1_Stream4_IRQHandler(){
	HAL_DMA_IRQHandler(&txSPI);
}
void DMA1_Stream3_IRQHandler(){
	HAL_DMA_IRQHandler(&rxSPI);
}

