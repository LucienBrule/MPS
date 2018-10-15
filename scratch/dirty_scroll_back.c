#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#define ESCAPE_KEY 0x2b
#define ENTER_KEY 0x0a
int main(){
	printf("Enter a character:\n");
	uint64_t buffer = 0x00;
	uint8_t key = 0x0;
	while(key != ESCAPE_KEY){
		key = getchar();
		if(key != ENTER_KEY){
			printf("You pressed: %c %x\n",key,key);
			buffer =  buffer << 8 | key;
			printf("NUMBER: 0x%" PRIx64 "\n",buffer);
			printf("STRING: %.7s\n",&buffer);
		}
	}
	printf("EXITING");
	return 0;
}
	
