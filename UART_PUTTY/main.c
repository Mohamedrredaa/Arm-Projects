#include <stdint.h>
#include "tm4c123gh6pm.h"
char getChar(void);
void delayMs(int n);
void Uart_Init(void);
void Led_Init(void);
void SystemInit(){}
void printChar(char x);
void UART0Send(char c);
void printString(char* str);
char* getString(void);
void getChar_led(char c);
void getString_led(char* c);
char* str;int i;char* x;
void led(char* x);
	void printString(char* x);
int main(void)
{	
		Uart_Init();
		Led_Init();		
		
		while(1)
		{
			x = getString();
			led(x);
			
		}
} 

void Uart_Init(){
		SYSCTL_RCGCUART_R |= 1; 
		SYSCTL_RCGCGPIO_R |= 1; 
		SYSCTL_RCGCGPIO_R |= 0x20; 
		UART0_CTL_R = 0; 
		UART0_IBRD_R = 104; 
		UART0_FBRD_R = 11; 
		UART0_CC_R = 0;            
		UART0_LCRH_R = 0x60; 
		UART0_CTL_R = 0x301; 
		
}

void Led_Init(){
		GPIO_PORTA_DEN_R = 0x03; 
		GPIO_PORTA_AFSEL_R = 0x03; 
		GPIO_PORTA_PCTL_R = 0x11; 
		GPIO_PORTF_DIR_R = 0x0E; 
		GPIO_PORTF_DEN_R = 0x0E;
		GPIO_PORTF_DATA_R = 0;


}
char getChar(void)
{
	char c;
	while((UART0_FR_R & 0x10) != 0); /* wait until the buffer is not empty */
	c = UART0_DR_R; 								 /* read the received data */
	return c; /* and return it */
}

void printChar(char x){
	while((UART0_FR_R &0x20) !=0);
	UART0_DR_R = x;
}
char* getString(){
	char *str;int i;
	for(i=0;i<9;i++)
		{str[i] = getChar();
		printChar(str[i]); 
		if(str[i] == 13)break;
		}
	
	//for(i = 0;i<10;i++)printChar(32); // this if fpr space 
	//printChar(10);   								// this is new line
	printChar(10);
	return str;
}
void printString(char* x){
	int i = 0;
	for(;x[i] != 0;i++){printChar(x[i]);}

}
void getChar_led(char c){
			 
			if(c == 'R' || c == 'r')GPIO_PORTF_DATA_R = 2;
			else if(c == 'B' || c == 'b')GPIO_PORTF_DATA_R = 4;
			else if(c == 'G' || c == 'g')GPIO_PORTF_DATA_R = 8;
}
void getString_led(char* c){
			char x = c[3];
			switch(x)
			{
				case 'r' : 
				case 'R' : GPIO_PORTF_DATA_R = 2;break;
				case 'B' : 
				case 'b' : GPIO_PORTF_DATA_R = 4;break;
				case 'G' : 
				case 'g' : GPIO_PORTF_DATA_R = 8;break;
					
			}
}
void led(char* c){
				if((c[0] == 'O' || c[0] == 'o' )&&
					 (c[1] == 'N' || c[1] == 'n' )&&
					 (c[2] ==  32 || c[2] == 32  )&&
					 (c[3] == 'R' || c[3] == 'r' )&&
					 (c[4] == 'E' || c[4] == 'e' )&&
					 (c[5] == 'D' || c[5] == 'd' ))GPIO_PORTF_DATA_R = 2;
				
	else if ((c[0] == 'O' || c[0] == 'o' )&&
					 (c[1] == 'N' || c[1] == 'n' )&&
					 (c[2] ==  32 || c[2] == 32  )&&
					 (c[3] == 'B' || c[3] == 'b' )&&
					 (c[4] == 'L' || c[4] == 'l' )&&
					 (c[5] == 'U' || c[5] == 'u' )&&
					 (c[6] == 'E' || c[6] == 'e' ))
						GPIO_PORTF_DATA_R = 4;
			
	else if ((c[0] == 'O' || c[0] == 'o' )&&
					 (c[1] == 'N' || c[1] == 'n' )&&
					 (c[2] ==  32 || c[2] == 32  )&&
					 (c[3] == 'G' || c[3] == 'g' )&&
					 (c[4] == 'R' || c[4] == 'r' )&&
					 (c[5] == 'E' || c[5] == 'e' )&&
					 (c[6] == 'E' || c[6] == 'e' )&&
					 (c[7] == 'N' || c[7] == 'n' ))
						GPIO_PORTF_DATA_R = 8;				
			
}
