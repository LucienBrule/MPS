#include <stdio.h>

int main(){
	printf("### LAB 001 ###\n");
	char key_pressed = 0;
	while(key_pressed != 0x41){
		key_pressed = getchar();
		if(key_pressed != 0x0A)
			printf("You pressed: %x ... %c\n", key_pressed, key_pressed);
	}
}
