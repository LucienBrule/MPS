//------------------------------------------------------------------------------------
// Hello.c
//------------------------------------------------------------------------------------
//
// Test program to demonstrate serial port I/O.  This program writes a message on
// the console using the printf() function, and reads characters using the getchar()
// function.  An ANSI escape sequence is used to clear the screen if a '2' is typed.
// A '1' repeats the message and the program responds to other input characters with
// an appropriate message.
//
// Any valid keystroke turns on the green LED on the board; invalid entries turn it off
//

//------------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------------
#include "stm32f769xx.h"
#include "hello.h"

#include<stdint.h>

//------------------------------------------------------------------------------------
// MAIN Routine
//------------------------------------------------------------------------------------
int main(void) {
	Sys_Init(); // This always goes at the top of main (defined in init.c)

	char choice;
	char in[3];
	int size = 3;

	printf("\033[2J\033[;H"); // Erase screen & move cursor to home position
	fflush(stdout); // Need to flush stdout after using printf that doesn't end in \n

	//Enable Clock for Ports A,C,D,F,F
	volatile uint32_t * RCC_AHB1_CLOCK_ENABLE = (uint32_t*) 0x40023830U; // Enable clock for peripheral bus on GPIO Port J
	*RCC_AHB1_CLOCK_ENABLE |= 0x0000022D;

	//Bitmask initalize ouputs (inputs by default)
	GPIOJ->MODER |= 0x04000400; //Bitmask for GPIO J Pin 5 initialization (set it to Output mode): 0x00000400U or 1024U in decimal
	GPIOA->MODER |= 0x01000000;
	GPIOD->MODER |= 0x00000100;

	//Set Pull-up / Pull-down Resistors for inputs
	GPIOC->PUPDR |= 0x00005000;
	GPIOJ->PUPDR |= 0x00000004;
	GPIOF->PUPDR |= 0x00001000;

	//Variable assignments for easy access of the switch and pot inputs
	uint16_t s1;
	uint16_t s2;
	uint16_t s3;
	uint16_t s4;
	uint16_t pot;

	HAL_Delay(1000); // Pause for a second

	while (1) {
		//Get input data for all switches and pot
		s1 = (GPIOC->IDR) & 0x0080;
		s2 = (GPIOC->IDR) & 0x0040;
		s3 = (GPIOJ->IDR) & 0x0002;
		s4 = (GPIOF->IDR) & 0x0040;
		pot = (GPIOJ->IDR) & 0x0001;

		//Check if the switches are enabled, then turn on corresponding LED accordingly
		if (s1 != 0x0080) {

			GPIOJ->BSRR = (uint16_t) GPIO_PIN_13;
		} else {
			GPIOJ->BSRR = (uint16_t) GPIO_PIN_13 << 16;
		}

		if (s2 != 0x0040) {

			GPIOJ->BSRR = (uint16_t) GPIO_PIN_5;
		} else {
			GPIOJ->BSRR = (uint16_t) GPIO_PIN_5 << 16;
		}

		if (s3 != 0x0002) {

			GPIOA->BSRR = (uint16_t) GPIO_PIN_12;
		} else {
			GPIOA->BSRR = (uint16_t) GPIO_PIN_12 << 16;
		}

		if (s4 != 0x0040) {
			GPIOD->BSRR = (uint16_t) GPIO_PIN_4 << 16;
		} else {
			GPIOD->BSRR = (uint16_t) GPIO_PIN_4;
		}

		//Check if pot reads a digital 1 and display info accordingly
		if (pot) {
			printf("Pot On\r\n");
		}

	}

}

