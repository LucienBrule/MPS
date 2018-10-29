#include <stdio.h>
#include <stdlib.h>
int main(){
	uint16_t result = 0;
	uint16_t num1 = 6;
	uint16_t num2 = 9;
	printf("Adding %u and %u\n",num1, num2);
	__asm__ __volatile__(
		"movw %1,%0;"
		"add %2,%0;"
		:"=r" (result)
		:"r" (num1),"r" (num2)
		:
		);
	printf("The result is: %u\n",result);
	result = 7;
	num1 = 2;
	num2 = 3;
	// result = num1 * num2;
	printf("Multiplying two numbers\r\n");
	__asm__ __volatile__(
			"nop;\n\t"
			"movw %1,%%ax;\n\t"
			"movw %2,%%cx;\n\t"
			"mulw %%cx;\n\t"
			"movw %%ax, %0"
			:"=r" (result)
			:"r" (num1),"r" (num2)
			:
			);
	printf("The result is: %u\n",result);

	printf("Performing (2*x)/3 + 5 two numbers\r\n");
	result = 0;
	num1 = 3;
	__asm__ __volatile__(
			"nop;\n\t"
			"movw %1, %%ax\n\t"
			"movw $2, %%cx\n\t"
			"mulw %%cx\n\t"
			"movw $3, %%cx\n\t"
			"divw %%cx\n\t"
			"add $5, %%ax\n\t"
			"mov %%ax, %0"
			:"=r" (result)
			:"r" (num1)
			:
			);
	printf("The result is: %u\n",result);

	return 0;
}
