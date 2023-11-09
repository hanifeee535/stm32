#include <stdint.h>



void delay ( int volatile rep);

int main ()
{
	uint32_t volatile *pRCC_Apb2En = (uint32_t*) 0x40021018;
	uint32_t volatile *pGPIOA = (uint32_t*) 0x40010800;
	uint32_t volatile *pGPIOC = (uint32_t*) 0x40011004;
	uint32_t volatile *pODR = (uint32_t*) 0x4001100C;
	uint32_t volatile *pIDR = (uint32_t*) 0x40010808;
	
	
	//Enabling the clock for GPIO A from RCC APB2 Enable register (by setting 2nd bit high)
	*pRCC_Apb2En |= 1<<2;
	
	//Enabling the clock for GPIO C from RCC APB2 Enable register (by setting 4th bit high)
	*pRCC_Apb2En |= 1<<4;
	
	
	
	//configuring the GPIO A0 pin in input pul up/pull down 
	*pGPIOA &= (unsigned) ~ (0xF << 0);  //clearing the data
	*pGPIOA |= 0x8<<0; // setting the value
	
	// configuring the GPIO C13 pin for output push pull
	*pGPIOC &= (unsigned) ~(0xF<<20); //clearing the data
	*pGPIOC |= 0x3<< 20; //setting the value
	
	
	
	while (1)
	{
		if (*pIDR &= 0x00000001)
		{
			*pODR &= (unsigned) ~ 1<<13;
			
			delay (10);
			*pODR |= 1<<13;
			delay (10);
		}
		else { *pODR |= 1<<13;  }
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

