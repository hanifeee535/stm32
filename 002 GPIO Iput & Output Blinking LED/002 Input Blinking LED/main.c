#include <stdint.h>
#include"library_header.h"


void delay ( int volatile rep);

int main ()
{
	//configuring GPIO A0 pin as input push out-pull down
	config_gp (portA, 0, input, pp_in);
		//configuring GPIO C 13 pin as general purpuse output push-pull
	config_gp (portC, 13, output_50Mhz, gp_output);
	
	
	while (1)
	{
		//if pin GPIO A0 reading state is High(1)
		if (read_gp(portA, 0) ==1 )
		{
			//Write to GPIO C 13 as low
			write_gp (portC, 13, LOW);
			
			delay (10);
			//Write to GPIO C 13 as High
			write_gp (portC, 13, HIGH);
			delay (10);
		}
		else { write_gp (portC, 13, HIGH);  }
	}
	
	
}



void delay (int volatile rep)
{
	int volatile i;
	for (rep; rep>0; rep--)
	{
		for (i= 100000; i>0; i--)
		{
		
		}
	}
}

