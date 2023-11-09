#include <stdint.h>
#include"ledHeader.h"

void delay (int volatile rep);
int main (void)
{
	
	config_gp (portC, 13, output_50Mhz, gp_output);
	
	
	while (1)
	{
		write_gp (portC, 13, HIGH);
		delay (10);
		write_gp (portC, 13, LOW);
		delay (10);
	}
	
}

void delay (int volatile rep)
{
	int volatile i;
	for (rep; rep>0; rep--)
	{
		 for (i = 100000; i>0; i--)
		{
		}
	}
}
