#include "init.h"

int main(){
	Sys_Init();
	printf("Enter something\r\n");
	HAL_Delay(1);
	char a = getchar();
	printf("%c",a);
	printf("MORE WORDS\r\n");
	/*printf("AAAA\n\r");
	printf("BBBB\n\r");
	printf("CCCC\n\r");
	printf("DDDD\n\r");
	printf("EEEE\n\r");
	printf("FFFF\n\r");
*/
	while(1);
}
