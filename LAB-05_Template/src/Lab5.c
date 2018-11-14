#include "init.h"

int main(){
	Sys_Init();
	__HAL_RCC_DMA2_CLK_ENABLE();
	printf("THESE ARE WORDS");
}
