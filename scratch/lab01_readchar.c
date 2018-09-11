#include <stdio.h>
#include <ctype.h>

#define TEXT_ESCAPE "\033[0;33m\033[44m\n"

int main(){
	#ifdef TEXT_ESCAPE
	 printf(TEXT_ESCAPE);
	#endif

	//python -c 'print((80 - len("PRESS <ESC> OR <CTRL> + [ TO QUIT")) * " ")'
	printf("                                               PRESS <ESC> OR <CTRL> + [ TO QUIT");
	printf(" \n \n \n \n \n \n");
	char key_pressed = 0;
	while(key_pressed != 0x1B){
		key_pressed = getchar();
		if(isprint(key_pressed)){
			printf("The keyboard character is %c\n", key_pressed);
		}
		else if(key_pressed == 0x0A){
			// Do nothing
		}else{
			printf("The keyboard character $%x is 'not printable'\a\n", key_pressed);
		}
	}
	printf("Exiting");
}
