
# include "MCAL.h"

typedef struct
{
	Pin s;
} SW;

void initSwitch(char portIndex , char pinNumber, SW *sw);
char readSwitch(SW sw);
char noiseReadSwitch(SW sw);
