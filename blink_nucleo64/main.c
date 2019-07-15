
#include<stdint.h>
#include<stdbool.h>

#include "Board_LED.h"
#include "Board_Buttons.h"

void delay (void)
{
	uint32_t i = 0;
	for( i = 0; i< 500000; i++);
}

void pointers3(void){
	void (*jump_addr) (void) = 0x00000000;
	jump_addr();
}

void pointers2(void){
	pointers3();
}

void pointers(void){
	pointers2();
}


int main(void){
	
	bool ledstatus = false;
	bool lastBtn = false;
	LED_Initialize();
	Buttons_Initialize();
	
	while(1)
	{
		pointers();
		if(Buttons_GetState() ==1){
			
			//lastBtn = true;
			if(ledstatus){
				ledstatus = false;
				delay();
			}else{
				ledstatus = true;
				delay();
			}
		}
		
		if(ledstatus){
			LED_On(0);
			
		}else{
			LED_Off(0);
		}
	}
	return 0;
}
