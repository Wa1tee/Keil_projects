
#include<stdint.h>
#include "Board_LED.h"

void delay (void)
{
	uint32_t i = 0;
	for( i = 0; i< 500000; i++);
}


int main(void){
	
	while(1)
	{
		LED_Initialize();
		LED_On(0);
		delay();
		LED_Off(0);
		delay();
		delay();
		delay();
	}
	return 0;
}
