//--------------------------------
// Lab 4 - Sample - Lab04_sample.c
//--------------------------------
//
//

#include "init.h"
void configureADC();

ADC_HandleTypeDef ADCHandle;

// Main Execution Loop
int main(void)
{
	//Initialize the system
	Sys_Init();
	configureADC();
	HAL_ADC_Start(&ADCHandle);
	printf("\r\n============ Starting LAB 04 ===============\r\n");

	for(;;){
		uint16_t value = 0x00;
		float voltage;
		HAL_ADC_Start(&ADCHandle);
		HAL_ADC_PollForConversion(&ADCHandle,100);
		value = HAL_ADC_GetValue(&ADCHandle);
		voltage =(double) (( (double) value* (double) 3300) / (double) 4095) / (double)1000;
		printf("ADC: %x %u VOLTS: %f \r\n",value,value,(double) voltage);
		HAL_Delay(1000);
	}
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
