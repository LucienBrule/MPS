////----------------------------------
//// Lab 2 - Timer Interrupts - Lab02.c
//
////----------------------------------
//// Objective:
////   Build a small game that records user's reaction time.
////
//
////
////
//// -- Imports ---------------
////
//#include "init.h"
//
//
////
////
//// -- Prototypes ------------
////
//void blinkScreen();
//void Init_GPIO();
//void Init_Timer();
//void task3();
//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef * tim);
//void TIM7_IRQHandler(void);
//
//
////
////
//// -- Code Body -------------
////
//volatile uint8_t timeUpdated = 0;
//volatile uint8_t buttonPressed = 0;
//volatile uint8_t buttonReleased = 0;
//volatile uint32_t elapsed = 0;
//
//int32_t randomNumber = 0;
//uint32_t startTime = 0;
//float averageScore = 0;
//unsigned int iterations = 0;
//TIM_HandleTypeDef tim7;
//
//int main() {
//	HAL_Init();
//	__HAL_RCC_GPIOC_CLK_ENABLE();
//	Sys_Init();
//	Init_Timer();
//	Init_GPIO();
//
//
//	printf("Task 1\r\n");
//	task1();
//	printf("Task 1 Done\r\n");
//	printf("Task 3\r\n");
//	task3();
//	printf("Task 3 Done\r\n");
//
//
////
////	while(1){
////		t1();
////		printf("%u iterations\r\n", iterations);
////	}
//
//	/*
//	while (1) {
//		t1();
//		// Main loop code goes here
//		printf("\033c\033[36m\033[2J");
//		printf("Blink!\r\n");
//		HAL_Delay(1000);
//		blinkScreen(); // Alternatively: in some terminals, the BELL can be configured to produce
//					   // 			a "visual bell" ... a blink.
//		HAL_Delay(1000);
//	}*/
//}
//
//void task1(){
//	getchar();
//}
//
//
//void task3(){
//	HAL_TIM_Base_Stop_IT(&tim7);
//	iterations = 0;
//	HAL_TIM_Base_Start_IT(&tim7);
//	for(int i = 0; i <100000000 ; i++){
//		asm("nop");
//		asm("nop");
//		asm("nop");
//		asm("nop");
//	}
////	printf("Waiting for input...\r\n");
////	getchar();
//	float elapsed = iterations * .028;
//	printf("%.1f seconds elapsed\r\n", iterations);
//}
//
////
////
//// -- Utility Functions ------
////
//void blinkScreen(){
//	printf("\033[30;47m");
//	// Clear and redraw display (flash it & sound the bell).
//	printf("\a\033[s\033[2J\033[u");
//	fflush(stdout);
//	HAL_Delay(100);
//
//	printf("\033[37;40m");
//	// Clear and redraw display (flash it).
//	printf("\033[s\033[2J\033[u");
//	fflush(stdout);
//}
//
//
////
////
//// -- Init Functions ----------
////
//void Init_Timer() {
//	tim7.Instance = TIM7;
//	tim7.Init.Period = 6000;
//	tim7.Init.Prescaler = 500;
//
//
//	__HAL_RCC_TIM7_CLK_ENABLE();
//
//	HAL_NVIC_SetPriority(TIM7_IRQn,0,0);
//	HAL_NVIC_EnableIRQ(TIM7_IRQn);
//
//	HAL_TIM_Base_Init(&tim7);
//	HAL_TIM_Base_Start_IT(&tim7);
//
//}
//
//void Init_GPIO() {
//	// Enable GPIO clocks?
//	// Looks like GPIO reg updates are synced to a base clock.
//	//  for any changes to appear the clocks need to be running.
//	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
//	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOJEN;
//	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
//	__HAL_RCC_SYSCFG_CLK_ENABLE();
//
//
//	GPIO_InitTypeDef GPIO_InitStruct;
//	//PushButton2 --> PA8
//	GPIO_InitStruct.Pin = GPIO_PIN_8;
//	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
//	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
//	GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
//	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
//	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
//
//	asm ("nop");
//	asm ("nop");
//
//
//}
//
////
////
//// -- ISRs (IRQs) -------------
////
//void TIM7_IRQHandler(void) {
//	HAL_TIM_IRQHandler(&tim7);
//
//}
//
//
//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef * tim){
//	if(tim -> Instance == TIM7){
//		//printf("Overflow\r\n");
//		iterations++;
//	}
//
//}
//
//
////HAL - GPIO/EXTI Handler
//void EXTI9_5_IRQHandler(void){
//	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_8);
//}
//
//
//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
//	printf("Button Pressed\r\n");
//
//	//HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
//}
//
//void HAL_TIMEx_BreakCallback(TIM_HandleTypeDef *htim){};
//void HAL_TIMEx_CommutationCallback(TIM_HandleTypeDef *htim){};
//
//
