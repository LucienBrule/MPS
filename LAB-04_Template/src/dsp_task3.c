void task3(){
	float num1,num2,result;
	num1 = 13.37;
	num2 = 69.69;
	result = 0.0;

	printf("[TASK 4]\r\n");
	printf("Adding %f and %f\r\n",num1, num2);
	asm volatile("vadd.f32 %[out],%[in1],%[in2];\n\t"
			:[out] "+w" (result)
			:[in1] "w" (num1), [in2] "w" (num2));
	printf("num1: %f , num2: %f, result: %f\r\n",num1,num2,result);
	num1 = 13.37;
	num2 = 69.69;
	result = 0.0;
	printf("Multiplying two numbers\r\n");
	asm volatile("vmul.f32 %[out],%[in1],%[in2];\n\t"
			:[out] "+w" (result)
			:[in1] "w" (num1), [in2] "w" (num2));
	printf("num1: %f , num2: %f, result: %f\r\n",num1,num2,result);

	num1 = 13.37;
	num2 = 0.0;
	result = 0.0;
	float five = 5.0;
	float two_thirds = 2.0/3.0;
	float carry = 0.0;

	printf("Evaulating 2x + 5 two numbers\r\n");
	asm volatile(	"vmul.f32 %[in5],%[in1],%[in4];\n\t" // x * 2/3
					"vadd.f32 %[out], %[in5], %[in3];\n\t" // add 5 to carry and store in output
			:[out] "+w" (result)
			:[in1] "w" (num1), [in2] "w" (num2), [in3] "w"  (five), [in4] "w"  (two_thirds),[in5] "w"  (carry));
	printf("num1: %f , num2: %f, result: %f\r\n",num1,num2,result);
}
