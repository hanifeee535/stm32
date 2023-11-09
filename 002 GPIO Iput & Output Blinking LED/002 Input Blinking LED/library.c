#include "library_header.h"
#include <stdint.h>

//configuration of GPIO ports
void config_gp ( uint32_t port , uint32_t pin, uint32_t mode, uint32_t config)
{
	volatile uint32_t *tempR;
	uint32_t tpin = pin;
	uint32_t offset = 0x00;
	if (pin>7) {
		tpin -= 8;
		offset = 0x01;
	}
	
	if (port == 1)
	{
		RccAPB2  = RccAPB2  |(1<<2); //Enabling the APB2 Register for GPIOA
		tempR = (volatile uint32_t*) (&GpioA+offset); 
		
	}
	
	else if (port == 2)
	{
		RccAPB2  = RccAPB2  |(1<<3);//Enabling the APB2 Register for GPIOB
		tempR = (volatile uint32_t*) (&GpioB+offset); 
		
	}
	
	else if (port == 3)
	{
		RccAPB2  = RccAPB2  |(1<<4); //Enabling the APB2 Register for GPIOC
		tempR = (volatile uint32_t*) (&GpioC+offset); 
		
	}
	else {tempR = 0;}
	
	*tempR &= (unsigned) ~ (0xF<<(tpin*4)); //Reseting the GPIO pin
	
	*tempR |= (config << (tpin*4+2));  // Setting the value
	*tempR |= (mode<<(tpin*4)); // Seting the value
}

//Write function 
void write_gp (uint32_t port, uint32_t pin, uint32_t state)
{
	volatile uint32_t* ODR;
	volatile uint32_t offset = 0x03;
	if (port == 1)
	{
		ODR = (volatile uint32_t*) (&GpioA + offset);
	}
	else if (port == 2)
	{
		ODR = (volatile uint32_t*) (&GpioB + offset);
	}
	else if (port == 3)
	{
		ODR = (volatile uint32_t*) (&GpioC + offset);
	}
	else {ODR = 0;}
	state?((*ODR |= 1<<pin)) : (*ODR &= (unsigned) ~ (1<<pin));
}


//Read function (read from input port)
uint32_t read_gp (uint32_t port, uint32_t pin)
{
	volatile uint32_t *IDR;
  volatile uint32_t offset = 0x02;
	uint32_t state;
	
	if (port == 1)
	{
		IDR = (volatile uint32_t*) (&GpioA + offset);
	}
	else if (port == 2)
	{
		IDR = (volatile uint32_t*) (&GpioB + offset);
	}
	else if (port == 3)
	{
		IDR = (volatile uint32_t*) (&GpioC + offset);
	}
	else {IDR = 0;}
	
	state = (*IDR & (1<<pin)) >> pin;
	return state;
}

