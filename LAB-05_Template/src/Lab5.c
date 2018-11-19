#include "init.h"
#define TEXT_ESCAPE "\033[0;33m\033[44m\n"

DMA_HandleTypeDef txSPI, rxSPI;
SPI_HandleTypeDef spi2;
int done = 0;
uint32_t task4_part2(float*,float );
void fuckingrunme();
void task2();
void initDMA();
void configureDAC();
void configureSPI();
ADC_HandleTypeDef ADCHandle;
DAC_HandleTypeDef DACHandle;
int main(){
	Sys_Init();
	initSPIDMA();
	configureSPI();
	configureADC();
	configureDAC();
	printf("Enter something\r\n");
	task2();
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


void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi){
	done = 1;
}
void DMA1_Stream4_IRQHandler(){
	HAL_DMA_IRQHandler(&txSPI);
}
void DMA1_Stream3_IRQHandler(){
	HAL_DMA_IRQHandler(&rxSPI);
}
void SPI2_IRQHandler(){
	HAL_SPI_IRQHandler(&spi2);
}
void task2(){
	uint8_t i[1], o[1], index;

	index = 0;
	while(1){
		i[0] = 0x00;
		o[0] = 0x00;

		o[0] = getchar();
		printf("Got something: %c\r\n",o[0]);
		HAL_SPI_TransmitReceive_DMA(&spi2, o,i,(uint16_t) 1);
		while(!done);
		printf("\r\nDone.");
		printf("\033[2J");
//		printf("\033[1;0Kbd %c\r\n\nSPI%c", o[0],i[0]);
		printf("KBD: %c \r\n",o[0]);
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("SPI: %c \r\n",i[0]);
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

		index++;
	}

}


void fuckingrunme(){
		float adc_buffer[3] = {0.0};
		float previous = 0.0;
		float new_value = 0.0;
		while(1){
			for(int i = 0; i < 3; i++){
				//adc read
				HAL_ADC_Start(&ADCHandle);
				HAL_ADC_PollForConversion(&ADCHandle,100);
				adc_buffer[i] = HAL_ADC_GetValue(&ADCHandle);
			}
	//		part 4 implemented with assembly and C
	//		new_value = (float) task4(&adc_buffer, previous);
			new_value = (float) task4_part2(adc_buffer, previous);
			printf("[INFO] NEW VALUE: %f\r\n",new_value);
	//Dac write
			HAL_DAC_Start(&DACHandle,DAC1_CHANNEL_1);
			HAL_DAC_SetValue(&DACHandle,DAC1_CHANNEL_1,DAC_ALIGN_12B_R,(uint32_t) new_value);
			previous = new_value;
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







	if(HAL_SPI_Init(&spi2) != HAL_OK){
		printf("Error\r\n");
	}
	__HAL_LINKDMA(&spi2,hdmatx,txSPI);
	__HAL_LINKDMA(&spi2,hdmarx,rxSPI);

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


void configureADC()
{
	// Enable the ADC Clock.
	__HAL_RCC_SYSCFG_CLK_ENABLE();
	__HAL_RCC_ADC1_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();


	//Configure ADC1
	ADCHandle.Instance = ADC1;
	ADCHandle.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
	ADCHandle.Init.Resolution = ADC_RESOLUTION12b;
	ADCHandle.Init.ContinuousConvMode = DISABLE;
	ADCHandle.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	ADCHandle.Init.NbrOfConversion = 0;
	ADCHandle.Init.NbrOfDiscConversion = 1;
	ADCHandle.Init.DiscontinuousConvMode = ENABLE;
	ADCHandle.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	HAL_ADC_Init(&ADCHandle); // Initialize the ADC


	// Configure the ADC channel
	ADC_ChannelConfTypeDef ADC_Channel_InitStruct;
	ADC_Channel_InitStruct.Channel = ADC_CHANNEL_6;
	ADC_Channel_InitStruct.Rank = 1;
	ADC_Channel_InitStruct.SamplingTime = ADC_SAMPLETIME_112CYCLES;
	HAL_ADC_ConfigChannel(&ADCHandle,&ADC_Channel_InitStruct);
}

uint32_t task4_part2(float* k,float previous_output){
	float adc1 = k[0];
	float adc2 = k[1];
	float adc3 = k[2];
	float adc4 = previous_output;
	float dac_out = 0.0;
	float scalar = 0.0;
//	SO the compiler CANT PASS FLOATS so pass as uint32_t instead.
//	this is important ^^^^^^^^^^^^^^
	return (uint32_t)( adc1 * 0.3125 + adc2 * 0.25 + adc3 * 0.3125 + adc4 * 0.296875);
}

void configureDAC(){
	// GPIO init for A6
	GPIO_InitTypeDef GPIO_InitStruct_a4;
	GPIO_InitStruct_a4.Pin = GPIO_PIN_4;
	GPIO_InitStruct_a4.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct_a4.Pull = GPIO_NOPULL;
	GPIO_InitStruct_a4.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOA,&GPIO_InitStruct_a4);
	__HAL_RCC_DAC_CLK_ENABLE();
	DACHandle.Instance = DAC1;
	HAL_DAC_Init(&DACHandle);
	DAC_ChannelConfTypeDef DAC_Channel_InitStruct;
	DAC_Channel_InitStruct.DAC_Trigger = DAC_TRIGGER_NONE;
	HAL_DAC_ConfigChannel(&DACHandle,&DAC_Channel_InitStruct,DAC1_CHANNEL_1);
}


void HAL_ADC_MspInit(ADC_HandleTypeDef *hadc)
{

// GPIO init
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Pin = GPIO_PIN_6;
	GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOA,&GPIO_InitStruct);


}




