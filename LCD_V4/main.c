#include "LCD.h"
#include "switch.h"
SW inc,dec,reset;
void SystemInit()
{
	LCD_init_V2();
	initSwitch('a',5,&inc);
	initSwitch('a',6,&dec);
	initSwitch('a',7,&reset);
	
	//LCD_init();
}

void __main()
{
	int counter = 990;
	display_num(counter);
	while(1)
	{
		
		
		while(readSwitch(inc))//if user pressed increment counter every 0.2 seconds
		{
			counter = (counter + 1)%1000;
			//delay_milli(200);
			display_num(counter);
		}
	
		if(readSwitch(dec))
		{
			
			counter=counter-1;
			if (counter == -1) counter = 999;
			display_num(counter);
			while(readSwitch(dec));
		}
			
		if(readSwitch(reset)) 
		{	
			counter = 0;
			display_num (counter);
		}
  }
	

}
