#include "ledHeader.h"
void config_gp ( uint32_t port , uint32_t pin, uint32_t mode, uint32_t config)
{
	uint32_t *tempR;
	uint32_t tpin = pin;
	uint32_t offset = 0x00;
	if (pin>7) {
		tpin -= 8;
		offset = 0x01;
	}
	
	if (port == 1)
	{
		pRccAPB2  = pRccAPB2  |(1<<2);
		tempR = (uint32_t*) (&pGpioA+offset); 
		
	}
	
	else if (port == 2)
	{
		pRccAPB2  = pRccAPB2  |(1<<3);
		tempR = (uint32_t*) (&pGpioB+offset); 
		
	}
	
	else if (port == 3)
	{
		pRccAPB2  = pRccAPB2  |(1<<4);
		tempR = (uint32_t*) (&pGpioC+offset); 
		
	}
	else {tempR = 0;}
	
	*tempR &= (unsigned) ~ (0xF<<(tpin*4));
	
	*tempR |= (config << (tpin*4+2)); 
	*tempR |= (mode<<(tpin*4));
}


void write_gp (uint32_t port, uint32_t pin, uint32_t state)
{
	uint32_t* ODR;
	uint32_t offset = 0x03;
	if (port == 1)
	{
		ODR = (uint32_t*) (&pGpioA + offset);
	}
	else if (port == 2)
	{
		ODR = (uint32_t*) (&pGpioB + offset);
	}
	else if (port == 3)
	{
		ODR = (uint32_t*) (&pGpioC + offset);
	}
	else {ODR = 0;}
	state?((*ODR |= 1<<pin)) : (*ODR &= (unsigned) ~ (1<<pin));
}
