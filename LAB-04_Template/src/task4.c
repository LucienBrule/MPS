#include <stdio.h>
#include <stdlib.h>
uint32_t task4(float* k,float previous_output){
	//printf("[TASK4]\r\n");
	float adc1 = k[0];
	float adc2 = k[1];
	float adc3 = k[2];
	float adc4 = previous_output;
	float dac_out = 0.0;
	float scalar = 0.0;

	//printf("Evaulating 2x + 5 two numbers but with VMULA\r\n");
	//printf("sum/dac_out is: %f\r\n",dac_out);
	asm volatile(
					//1
					"nop;\n\t"
					"vmov.f32 %[scalar], #0.3125;\n\t"
					"vmla.f32 %[sum], %[in1],%[scalar];\n\t"

//					//2
					"vmov.f32 %[scalar], #0.25;\n\t"
					"vmla.f32 %[sum], %[in2],%[scalar];\n\t"
//					//3
					"vmov.f32 %[scalar], #0.3125;\n\t"
					"vmla.f32 %[sum], %[in3],%[scalar];\n\t"
//					//4
					"vmov.f32 %[scalar], #0.296875;\n\t"
					"vmla.f32 %[sum], %[in4],%[scalar];\n\t"
			:[sum] "+w" (dac_out), [scalar] "+w" (scalar)
			:[in1] "w" (adc1), [in2] "w" (adc2), [in3] "w"  (adc3),[in4] "w" (adc4));
//	printf("adc: %f , adc: %f, adc3: %f,adc4: %f,dac_out: %f\r\n",adc1,adc2,adc3,adc4,dac_out);
	return (uint32_t)dac_out;
}

uint32_t task4_part2(float* k,float previous_output){
	float adc1 = k[0];
	float adc2 = k[1];
	float adc3 = k[2];
	float adc4 = previous_output;
	float dac_out = 0.0;
	float scalar = 0.0;
	return (uint32_t)( adc1 * 0.3125 + adc2 * 0.25 + adc3 * 0.3125 + adc4 * 0.296875);
}
