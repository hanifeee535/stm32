#include <stdint.h>


void delay (int volatile rep);
int main (void)
{
	uint32_t *pClkCtrlReg = (uint32_t*) 0x40021018; 
	uint32_t *pPortCModeReg = (uint32_t*) 0x40011004; 
	uint32_t *pPortCODR = (uint32_t*) 0x4001100C; 

	
	//Enabling the GPIO_C CLock from RCC_APB2 peripheral ( by setting the 4th bit which contains gpioC)
	
	*pClkCtrlReg = *pClkCtrlReg |(1<<4);
	
	//Configuring the GPIO_C 13 pin as output by configuring 20 to 23th bit
	*pPortCModeReg &= (unsigned) ~(0xF<<20); //clearing the data
	*pPortCModeReg |= (3<<20); //Setting GPIO pin13 for general purpose output mode
	
	
	for(; ; )
	{
	//set value 1 for pin 13
		*pPortCODR |= 1<<13;
		delay (10);
	//Reset the value
		*pPortCODR  &= (unsigned) ~(1<<13);
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
