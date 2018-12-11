//--------------------------------
// Lab 4 - Sample - Lab04_sample.c
//--------------------------------
//
//
#include <stdlib.h>
#include "init.h"
void configureADC();
void task1();
void task2();
void configureDAC();

ADC_HandleTypeDef ADCHandle;
DAC_HandleTypeDef DACHandle;

// Main Execution Loop
int main(void)
{
	//Initialize the system
	Sys_Init();
	HAL_Init();
	configureADC();
	configureDAC();
	HAL_ADC_Start(&ADCHandle);
	printf("\r\n============ Starting LAB 04 ===============\r\n");
//	task1();
	task2();
//	task2_part2();
//	task4();
//	task3();
//	task4();
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
//		HAL_Delay(1000);
//		new_value = (float) task4(&adc_buffer, previous);
		new_value = (float) task4_part2(&adc_buffer, previous);

//		printf("\t\t\t\tprevious: %f, %lu\r\n", new_value, (uint32_t) new_value);
		HAL_DAC_Start(&DACHandle,DAC1_CHANNEL_1);
		HAL_DAC_SetValue(&DACHandle,DAC1_CHANNEL_1,DAC_ALIGN_12B_R,(uint32_t) new_value);
		previous = new_value;
	}


}

void task2(){
	uint32_t output = 0;
	for(;;){
		if(output >= 4095) output = 0;
		output+=0x0F;
		HAL_DAC_Start(&DACHandle,DAC1_CHANNEL_1);
		HAL_DAC_SetValue(&DACHandle,DAC1_CHANNEL_1,DAC_ALIGN_12B_R,output);
		printf("Output: %lu\r\n", output);
//		HAL_Delay(1000);
//		HAL_DACEx_TriangleWaveGenerate(&DACHandle,DAC1_CHANNEL_1,1);

 }
}
void task2_part2(){
	int32_t output = 0;
	for(;;){
//		output+=0x0F;
		HAL_ADC_Start(&ADCHandle);
		HAL_ADC_PollForConversion(&ADCHandle,100);
		output = HAL_ADC_GetValue(&ADCHandle);
		HAL_DAC_Start(&DACHandle,DAC1_CHANNEL_1);
		HAL_DAC_SetValue(&DACHandle,DAC1_CHANNEL_1,DAC_ALIGN_12B_R,output);
//		if(! (output / 300))
		printf("Output: %ld \t\t%0*s\r\n", output,(uint32_t)(output + 50) / 350 + 1,"x");
//		HAL_Delay(10ß);
//		HAL_DACEx_TriangleWaveGenerate(&DACHandle,DAC1_CHANNEL_1,1);
	}
}
void task1(){
	int min, max,i;
	float sum;
	min = 8000;
	for(;;){
		i++;
		uint16_t value = 0x00;
		float voltage;
		HAL_ADC_Start(&ADCHandle);
		HAL_ADC_PollForConversion(&ADCHandle,100);
		value = HAL_ADC_GetValue(&ADCHandle);
		voltage =(double) (( (double) value* (double) 3300) / (double) 4095) / (double)1000;
		if (value > max) max = value;
		if (value < min) min = value;
		sum += value;
		printf("ADC: %x %u VOLTS: %f, max: %d min: %d, avg: %f\r\n",value,value,(double) voltage,max,min,sum / (float)i);
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

// GPIO init for A6
	GPIO_InitTypeDef GPIO_InitStruct_a6;
	GPIO_InitStruct_a6.Pin = GPIO_PIN_6;
	GPIO_InitStruct_a6.Mode = GPIO_MODE_ANALOG;
	GPIO_InitStruct_a6.Pull = GPIO_NOPULL;
	GPIO_InitStruct_a6.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOA,&GPIO_InitStruct_a6);



}
