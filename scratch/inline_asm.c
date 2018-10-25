#include <stdio.h>
#include <stdlib.h>
int main(){
	uint16_t result = 0;
	uint16_t num1 = 6;
	uint16_t num2 = 9;
    	printf("Adding %u and %u\n",num1, num2);
    	__asm__ __volatile__(
				"mov %1,%0;"
				"add %2,%0;"
				:"=r" (result)
				:"r" (num1),"r" (num2)
				:
				);
    	printf("The result is: %u\n",result);
	return 0;
}
