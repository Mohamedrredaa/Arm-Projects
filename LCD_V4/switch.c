#include "switch.h"
 
void initSwitch(char portIndex , char pinNumber, SW *sw)
{
	sw->s = initPin(portIndex,pinNumber,INPUT);
}

char readSwitch(SW sw)
{
	return readPin(&sw.s);
}
